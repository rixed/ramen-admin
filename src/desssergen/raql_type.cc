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


namespace dessser::gen::raql_type {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t;
struct t;
struct t;
typedef std::tuple<
  uint32_t,
  t*
> t9327d6336842c469509b67056a719df9;

struct t;
struct t;
struct t;
typedef std::tuple<
  std::string,
  t*
> t100b7e5cf4b9a621db7a39d7f1d01e5c;

struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  t*,
  t*
> t7411897bdb6c9b6e00a01b4eb6506ccf;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t90c8a0d2bbcf528f6fcdb9d24234c023 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Arr<t*>,
  ::dessser::gen::raql_type::t9327d6336842c469509b67056a719df9,
  t*,
  Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c>,
  Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c>,
  ::dessser::gen::raql_type::t7411897bdb6c9b6e00a01b4eb6506ccf
> { using variant::variant; };
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t {
  bool nullable;
  ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 type;
  bool operator==(t const &other) const {
    return nullable == other.nullable && type == other.type;
  }
};
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  ::dessser::gen::raql_type::t*,
  Pointer
> tfafddb6af18e2fa33b782eb359ee7c77;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023,
  Pointer
> tb59ed3c1bba347d5259eaaf5d37e798a;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

struct t;
struct t;
typedef std::tuple<
  Lst<t*>,
  Pointer
> tff7ae6104a72ec7dfd0a80e3a42a8548;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  t*,
  Pointer
> t45217dce3db5a9a49037839afd0048e8;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  Lst<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c>,
  Pointer
> t5c3d2277237e7b88993f70440ba84ff4;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

struct t;
struct t;
typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
struct t;
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{type: [Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]; nullable: BOOL}" "Ptr")
      (let "srec_dst_361"
        (let "label1_334" (label-of (get-field "type" (param 0)))
          (let "ssum_dst_335" (write-u16 little-endian (param 1) (identifier "label1_334"))
            (if (eq (u16 0) (identifier "label1_334")) (identifier "ssum_dst_335")
              (if (eq (u16 1) (identifier "label1_334")) (identifier "ssum_dst_335")
                (if (eq (u16 2) (identifier "label1_334")) (identifier "ssum_dst_335")
                  (if (eq (u16 3) (identifier "label1_334")) (identifier "ssum_dst_335")
                    (if (eq (u16 4) (identifier "label1_334")) (identifier "ssum_dst_335")
                      (if (eq (u16 5) (identifier "label1_334")) (identifier "ssum_dst_335")
                        (if (eq (u16 6) (identifier "label1_334")) (identifier "ssum_dst_335")
                          (if (eq (u16 7) (identifier "label1_334")) 
                            (identifier "ssum_dst_335")
                            (if (eq (u16 8) (identifier "label1_334")) 
                              (identifier "ssum_dst_335")
                              (if (eq (u16 9) (identifier "label1_334")) 
                                (identifier "ssum_dst_335")
                                (if (eq (u16 10) (identifier "label1_334")) 
                                  (identifier "ssum_dst_335")
                                  (if (eq (u16 11) (identifier "label1_334")) 
                                    (identifier "ssum_dst_335")
                                    (if (eq (u16 12) (identifier "label1_334")) 
                                      (identifier "ssum_dst_335")
                                      (if (eq (u16 13) (identifier "label1_334")) 
                                        (identifier "ssum_dst_335")
                                        (if (eq (u16 14) (identifier "label1_334")) 
                                          (identifier "ssum_dst_335")
                                          (if (eq (u16 15) (identifier "label1_334")) 
                                            (identifier "ssum_dst_335")
                                            (if (eq (u16 16) (identifier "label1_334")) 
                                              (identifier "ssum_dst_335")
                                              (if (eq (u16 17) (identifier "label1_334")) 
                                                (identifier "ssum_dst_335")
                                                (if (eq (u16 18) (identifier "label1_334")) 
                                                  (identifier "ssum_dst_335")
                                                  (if (eq (u16 19) (identifier "label1_334")) 
                                                    (identifier "ssum_dst_335")
                                                    (if (eq (u16 20) (identifier "label1_334")) 
                                                      (identifier "ssum_dst_335")
                                                      (if (eq (u16 21) (identifier "label1_334")) 
                                                        (identifier "ssum_dst_335")
                                                        (if (eq (u16 22) (identifier "label1_334")) 
                                                          (identifier "ssum_dst_335")
                                                          (if (eq (u16 23) (identifier "label1_334")) 
                                                            (identifier "ssum_dst_335")
                                                            (if (eq (u16 24) (identifier "label1_334")) 
                                                              (identifier "ssum_dst_335")
                                                              (if (eq (u16 25) (identifier "label1_334")) 
                                                                (identifier "ssum_dst_335")
                                                                (if (eq (u16 26) (identifier "label1_334")) 
                                                                  (identifier "ssum_dst_335")
                                                                  (if 
                                                                    (eq (u16 27) (identifier "label1_334")) 
                                                                    (identifier "ssum_dst_335")
                                                                    (if 
                                                                    (eq (u16 28) (identifier "label1_334")) 
                                                                    (identifier "ssum_dst_335")
                                                                    (if 
                                                                    (eq (u16 29) (identifier "label1_334")) 
                                                                    (identifier "ssum_dst_335")
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label1_334"))
                                                                    (let "dst_ref_358"
                                                                    (make-vec
                                                                    (let "leb128_sz_356" 
                                                                    (make-vec (cardinality (get-alt "Tup" (get-field "type" (param 0)))))
                                                                    (let "leb128_ptr_357" 
                                                                    (make-vec (identifier "ssum_dst_335"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_357")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_357"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_356"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_356"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_356"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_356") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_356")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_356")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_357"))))))
                                                                    (let "n_ref_359" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_360" 
                                                                    (get-alt "Tup" (get-field "type" (param 0)))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_358") (apply (myself "Ptr") (identifier "x_360") (unsafe-nth (u8 0) (identifier "dst_ref_358"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_359") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_359")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_358")))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label1_334"))
                                                                    (apply 
                                                                    (myself "Ptr") 
                                                                    (get-item 1 (get-alt "Vec" (get-field "type" (param 0))))
                                                                    (write-u32 little-endian (identifier "ssum_dst_335") (get-item 0 (get-alt "Vec" (get-field "type" (param 0))))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label1_334")) 
                                                                    (apply (myself "Ptr") (get-alt "Arr" (get-field "type" (param 0))) (identifier "ssum_dst_335"))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label1_334"))
                                                                    (let "dst_ref_348"
                                                                    (make-vec
                                                                    (let "leb128_sz_346" 
                                                                    (make-vec (cardinality (get-alt "Rec" (get-field "type" (param 0)))))
                                                                    (let "leb128_ptr_347" 
                                                                    (make-vec (identifier "ssum_dst_335"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_347")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_347"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_346"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_346"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_346"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_346") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_346")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_346")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_347"))))))
                                                                    (let "n_ref_349" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_350" 
                                                                    (get-alt "Rec" (get-field "type" (param 0)))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "dst_ref_348")
                                                                    (apply 
                                                                    (myself "Ptr") 
                                                                    (get-item 1 (identifier "x_350"))
                                                                    (let "stup_dst_351" 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_348"))
                                                                    (write-bytes
                                                                    (let "leb128_sz_352" 
                                                                    (make-vec (string-length (get-item 0 (identifier "x_350"))))
                                                                    (let "leb128_ptr_353" 
                                                                    (make-vec (identifier "stup_dst_351"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_353")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_353"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_352"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_352"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_352"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_352") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_352")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_352")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_353"))))) 
                                                                    (bytes-of-string (get-item 0 (identifier "x_350"))))))) 
                                                                    (set-vec (u8 0) (identifier "n_ref_349") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_349")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_348")))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label1_334"))
                                                                    (let "dst_ref_339"
                                                                    (make-vec
                                                                    (let "leb128_sz_337" 
                                                                    (make-vec (cardinality (get-alt "Sum" (get-field "type" (param 0)))))
                                                                    (let "leb128_ptr_338" 
                                                                    (make-vec (identifier "ssum_dst_335"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_338")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_338"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_337"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_337"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_337"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_337") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_337")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_337")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_338"))))))
                                                                    (let "n_ref_340" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_341" 
                                                                    (get-alt "Sum" (get-field "type" (param 0)))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "dst_ref_339")
                                                                    (apply 
                                                                    (myself "Ptr") 
                                                                    (get-item 1 (identifier "x_341"))
                                                                    (let "stup_dst_342" 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_339"))
                                                                    (write-bytes
                                                                    (let "leb128_sz_343" 
                                                                    (make-vec (string-length (get-item 0 (identifier "x_341"))))
                                                                    (let "leb128_ptr_344" 
                                                                    (make-vec (identifier "stup_dst_342"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_344")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_344"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_343"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_343"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_343"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_343") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_343")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_343")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_344"))))) 
                                                                    (bytes-of-string (get-item 0 (identifier "x_341"))))))) 
                                                                    (set-vec (u8 0) (identifier "n_ref_340") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_340")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_339")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label1_334") (u16 35)))
                                                                    (apply 
                                                                    (myself "Ptr") 
                                                                    (get-item 1 (get-alt "Map" (get-field "type" (param 0))))
                                                                    (apply (myself "Ptr") (get-item 0 (get-alt "Map" (get-field "type" (param 0)))) (identifier "ssum_dst_335")))))))))))))))))))))))))))))))))))))))))
        (write-u8 (identifier "srec_dst_361") (u8-of-bool (get-field "nullable" (param 0))))))
 */
static std::function<Pointer(::dessser::gen::raql_type::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_type::t*,Pointer)> fun0 { [&fun0](::dessser::gen::raql_type::t* p_0, Pointer p_1) {
    ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_1 { p_0->type };
    uint16_t id_2 { uint16_t(id_1.index()) };
    Pointer let_res_3;
    {
      uint16_t label1_334 { id_2 };
      Pointer id_4 { p_1.writeU16Le(label1_334) };
      Pointer let_res_5;
      {
        Pointer ssum_dst_335 { id_4 };
        uint16_t id_6 { 0 };
        bool id_7 { bool(id_6 == label1_334) };
        Pointer choose_res_8;
        if (id_7) {
          choose_res_8 = ssum_dst_335;
        } else {
          uint16_t id_9 { 1 };
          bool id_10 { bool(id_9 == label1_334) };
          Pointer choose_res_11;
          if (id_10) {
            choose_res_11 = ssum_dst_335;
          } else {
            uint16_t id_12 { 2 };
            bool id_13 { bool(id_12 == label1_334) };
            Pointer choose_res_14;
            if (id_13) {
              choose_res_14 = ssum_dst_335;
            } else {
              uint16_t id_15 { 3 };
              bool id_16 { bool(id_15 == label1_334) };
              Pointer choose_res_17;
              if (id_16) {
                choose_res_17 = ssum_dst_335;
              } else {
                uint16_t id_18 { 4 };
                bool id_19 { bool(id_18 == label1_334) };
                Pointer choose_res_20;
                if (id_19) {
                  choose_res_20 = ssum_dst_335;
                } else {
                  uint16_t id_21 { 5 };
                  bool id_22 { bool(id_21 == label1_334) };
                  Pointer choose_res_23;
                  if (id_22) {
                    choose_res_23 = ssum_dst_335;
                  } else {
                    uint16_t id_24 { 6 };
                    bool id_25 { bool(id_24 == label1_334) };
                    Pointer choose_res_26;
                    if (id_25) {
                      choose_res_26 = ssum_dst_335;
                    } else {
                      uint16_t id_27 { 7 };
                      bool id_28 { bool(id_27 == label1_334) };
                      Pointer choose_res_29;
                      if (id_28) {
                        choose_res_29 = ssum_dst_335;
                      } else {
                        uint16_t id_30 { 8 };
                        bool id_31 { bool(id_30 == label1_334) };
                        Pointer choose_res_32;
                        if (id_31) {
                          choose_res_32 = ssum_dst_335;
                        } else {
                          uint16_t id_33 { 9 };
                          bool id_34 { bool(id_33 == label1_334) };
                          Pointer choose_res_35;
                          if (id_34) {
                            choose_res_35 = ssum_dst_335;
                          } else {
                            uint16_t id_36 { 10 };
                            bool id_37 { bool(id_36 == label1_334) };
                            Pointer choose_res_38;
                            if (id_37) {
                              choose_res_38 = ssum_dst_335;
                            } else {
                              uint16_t id_39 { 11 };
                              bool id_40 { bool(id_39 == label1_334) };
                              Pointer choose_res_41;
                              if (id_40) {
                                choose_res_41 = ssum_dst_335;
                              } else {
                                uint16_t id_42 { 12 };
                                bool id_43 { bool(id_42 == label1_334) };
                                Pointer choose_res_44;
                                if (id_43) {
                                  choose_res_44 = ssum_dst_335;
                                } else {
                                  uint16_t id_45 { 13 };
                                  bool id_46 { bool(id_45 == label1_334) };
                                  Pointer choose_res_47;
                                  if (id_46) {
                                    choose_res_47 = ssum_dst_335;
                                  } else {
                                    uint16_t id_48 { 14 };
                                    bool id_49 { bool(id_48 == label1_334) };
                                    Pointer choose_res_50;
                                    if (id_49) {
                                      choose_res_50 = ssum_dst_335;
                                    } else {
                                      uint16_t id_51 { 15 };
                                      bool id_52 { bool(id_51 == label1_334) };
                                      Pointer choose_res_53;
                                      if (id_52) {
                                        choose_res_53 = ssum_dst_335;
                                      } else {
                                        uint16_t id_54 { 16 };
                                        bool id_55 { bool(id_54 == label1_334) };
                                        Pointer choose_res_56;
                                        if (id_55) {
                                          choose_res_56 = ssum_dst_335;
                                        } else {
                                          uint16_t id_57 { 17 };
                                          bool id_58 { bool(id_57 == label1_334) };
                                          Pointer choose_res_59;
                                          if (id_58) {
                                            choose_res_59 = ssum_dst_335;
                                          } else {
                                            uint16_t id_60 { 18 };
                                            bool id_61 { bool(id_60 == label1_334) };
                                            Pointer choose_res_62;
                                            if (id_61) {
                                              choose_res_62 = ssum_dst_335;
                                            } else {
                                              uint16_t id_63 { 19 };
                                              bool id_64 { bool(id_63 == label1_334) };
                                              Pointer choose_res_65;
                                              if (id_64) {
                                                choose_res_65 = ssum_dst_335;
                                              } else {
                                                uint16_t id_66 { 20 };
                                                bool id_67 { bool(id_66 == label1_334) };
                                                Pointer choose_res_68;
                                                if (id_67) {
                                                  choose_res_68 = ssum_dst_335;
                                                } else {
                                                  uint16_t id_69 { 21 };
                                                  bool id_70 { bool(id_69 == label1_334) };
                                                  Pointer choose_res_71;
                                                  if (id_70) {
                                                    choose_res_71 = ssum_dst_335;
                                                  } else {
                                                    uint16_t id_72 { 22 };
                                                    bool id_73 { bool(id_72 == label1_334) };
                                                    Pointer choose_res_74;
                                                    if (id_73) {
                                                      choose_res_74 = ssum_dst_335;
                                                    } else {
                                                      uint16_t id_75 { 23 };
                                                      bool id_76 { bool(id_75 == label1_334) };
                                                      Pointer choose_res_77;
                                                      if (id_76) {
                                                        choose_res_77 = ssum_dst_335;
                                                      } else {
                                                        uint16_t id_78 { 24 };
                                                        bool id_79 { bool(id_78 == label1_334) };
                                                        Pointer choose_res_80;
                                                        if (id_79) {
                                                          choose_res_80 = ssum_dst_335;
                                                        } else {
                                                          uint16_t id_81 { 25 };
                                                          bool id_82 { bool(id_81 == label1_334) };
                                                          Pointer choose_res_83;
                                                          if (id_82) {
                                                            choose_res_83 = ssum_dst_335;
                                                          } else {
                                                            uint16_t id_84 { 26 };
                                                            bool id_85 { bool(id_84 == label1_334) };
                                                            Pointer choose_res_86;
                                                            if (id_85) {
                                                              choose_res_86 = ssum_dst_335;
                                                            } else {
                                                              uint16_t id_87 { 27 };
                                                              bool id_88 { bool(id_87 == label1_334) };
                                                              Pointer choose_res_89;
                                                              if (id_88) {
                                                                choose_res_89 = ssum_dst_335;
                                                              } else {
                                                                uint16_t id_90 { 28 };
                                                                bool id_91 { bool(id_90 == label1_334) };
                                                                Pointer choose_res_92;
                                                                if (id_91) {
                                                                  choose_res_92 = ssum_dst_335;
                                                                } else {
                                                                  uint16_t id_93 { 29 };
                                                                  bool id_94 { bool(id_93 == label1_334) };
                                                                  Pointer choose_res_95;
                                                                  if (id_94) {
                                                                    choose_res_95 = ssum_dst_335;
                                                                  } else {
                                                                    uint16_t id_96 { 30 };
                                                                    bool id_97 { bool(id_96 == label1_334) };
                                                                    Pointer choose_res_98;
                                                                    if (id_97) {
                                                                      ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_99 { p_0->type };
                                                                      Arr<t*> id_100 { std::get<30>(id_99) };
                                                                      uint32_t id_101 { id_100.size() };
                                                                      Vec<1, uint32_t> id_102 {  id_101  };
                                                                      Pointer let_res_103;
                                                                      {
                                                                        Vec<1, uint32_t> leb128_sz_356 { id_102 };
                                                                        Vec<1, Pointer> id_104 {  ssum_dst_335  };
                                                                        Pointer let_res_105;
                                                                        {
                                                                          Vec<1, Pointer> leb128_ptr_357 { id_104 };
                                                                          bool while_flag_106 { true };
                                                                          do {
                                                                            uint8_t id_107 { 0 };
                                                                            uint8_t id_108 { 0 };
                                                                            Pointer id_109 { leb128_ptr_357[id_108] };
                                                                            uint32_t id_110 { 128U };
                                                                            uint8_t id_111 { 0 };
                                                                            uint32_t id_112 { leb128_sz_356[id_111] };
                                                                            bool id_113 { bool(id_110 > id_112) };
                                                                            uint8_t choose_res_114;
                                                                            if (id_113) {
                                                                              uint8_t id_115 { 0 };
                                                                              uint32_t id_116 { leb128_sz_356[id_115] };
                                                                              uint8_t id_117 { uint8_t(id_116) };
                                                                              choose_res_114 = id_117;
                                                                            } else {
                                                                              uint8_t id_118 { 0 };
                                                                              uint32_t id_119 { leb128_sz_356[id_118] };
                                                                              uint8_t id_120 { uint8_t(id_119) };
                                                                              uint8_t id_121 { 128 };
                                                                              uint8_t id_122 { uint8_t(id_120 | id_121) };
                                                                              choose_res_114 = id_122;
                                                                            }
                                                                            Pointer id_123 { id_109.writeU8(choose_res_114) };
                                                                            Void id_124 { ((void)(leb128_ptr_357[id_107] = id_123), VOID) };
                                                                            (void)id_124;
                                                                            uint8_t id_125 { 0 };
                                                                            uint8_t id_126 { 0 };
                                                                            uint32_t id_127 { leb128_sz_356[id_126] };
                                                                            uint8_t id_128 { 7 };
                                                                            uint32_t id_129 { uint32_t(id_127 >> id_128) };
                                                                            Void id_130 { ((void)(leb128_sz_356[id_125] = id_129), VOID) };
                                                                            (void)id_130;
                                                                            uint8_t id_131 { 0 };
                                                                            uint32_t id_132 { leb128_sz_356[id_131] };
                                                                            uint32_t id_133 { 0U };
                                                                            bool id_134 { bool(id_132 > id_133) };
                                                                            while_flag_106 = id_134;
                                                                            if (while_flag_106) {
                                                                              (void)VOID;
                                                                            }
                                                                          } while (while_flag_106);
                                                                          (void)VOID;
                                                                          uint8_t id_135 { 0 };
                                                                          Pointer id_136 { leb128_ptr_357[id_135] };
                                                                          let_res_105 = id_136;
                                                                        }
                                                                        let_res_103 = let_res_105;
                                                                      }
                                                                      Vec<1, Pointer> id_137 {  let_res_103  };
                                                                      Pointer let_res_138;
                                                                      {
                                                                        Vec<1, Pointer> dst_ref_358 { id_137 };
                                                                        int32_t id_139 { 0L };
                                                                        Vec<1, int32_t> id_140 {  id_139  };
                                                                        Pointer let_res_141;
                                                                        {
                                                                          Vec<1, int32_t> n_ref_359 { id_140 };
                                                                          ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_142 { p_0->type };
                                                                          Arr<t*> id_143 { std::get<30>(id_142) };
                                                                          for (t* x_360 : id_143) {
                                                                            uint8_t id_144 { 0 };
                                                                            uint8_t id_145 { 0 };
                                                                            Pointer id_146 { dst_ref_358[id_145] };
                                                                            Pointer id_147 { fun0(x_360, id_146) };
                                                                            Void id_148 { ((void)(dst_ref_358[id_144] = id_147), VOID) };
                                                                            (void)id_148;
                                                                            uint8_t id_149 { 0 };
                                                                            int32_t id_150 { 1L };
                                                                            uint8_t id_151 { 0 };
                                                                            int32_t id_152 { n_ref_359[id_151] };
                                                                            int32_t id_153 { int32_t(id_150 + id_152) };
                                                                            Void id_154 { ((void)(n_ref_359[id_149] = id_153), VOID) };
                                                                            (void)id_154;
                                                                            (void)id_154;
                                                                          }
                                                                          (void)VOID;
                                                                          uint8_t id_155 { 0 };
                                                                          Pointer id_156 { dst_ref_358[id_155] };
                                                                          let_res_141 = id_156;
                                                                        }
                                                                        let_res_138 = let_res_141;
                                                                      }
                                                                      choose_res_98 = let_res_138;
                                                                    } else {
                                                                      uint16_t id_157 { 31 };
                                                                      bool id_158 { bool(id_157 == label1_334) };
                                                                      Pointer choose_res_159;
                                                                      if (id_158) {
                                                                        ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_160 { p_0->type };
                                                                        ::dessser::gen::raql_type::t9327d6336842c469509b67056a719df9 id_161 { std::get<31>(id_160) };
                                                                        t* id_162 { std::get<1>(id_161) };
                                                                        ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_163 { p_0->type };
                                                                        ::dessser::gen::raql_type::t9327d6336842c469509b67056a719df9 id_164 { std::get<31>(id_163) };
                                                                        uint32_t id_165 { std::get<0>(id_164) };
                                                                        Pointer id_166 { ssum_dst_335.writeU32Le(id_165) };
                                                                        Pointer id_167 { fun0(id_162, id_166) };
                                                                        choose_res_159 = id_167;
                                                                      } else {
                                                                        uint16_t id_168 { 32 };
                                                                        bool id_169 { bool(id_168 == label1_334) };
                                                                        Pointer choose_res_170;
                                                                        if (id_169) {
                                                                          ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_171 { p_0->type };
                                                                          t* id_172 { std::get<32>(id_171) };
                                                                          Pointer id_173 { fun0(id_172, ssum_dst_335) };
                                                                          choose_res_170 = id_173;
                                                                        } else {
                                                                          uint16_t id_174 { 33 };
                                                                          bool id_175 { bool(id_174 == label1_334) };
                                                                          Pointer choose_res_176;
                                                                          if (id_175) {
                                                                            ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_177 { p_0->type };
                                                                            Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_178 { std::get<33>(id_177) };
                                                                            uint32_t id_179 { id_178.size() };
                                                                            Vec<1, uint32_t> id_180 {  id_179  };
                                                                            Pointer let_res_181;
                                                                            {
                                                                              Vec<1, uint32_t> leb128_sz_346 { id_180 };
                                                                              Vec<1, Pointer> id_182 {  ssum_dst_335  };
                                                                              Pointer let_res_183;
                                                                              {
                                                                                Vec<1, Pointer> leb128_ptr_347 { id_182 };
                                                                                bool while_flag_184 { true };
                                                                                do {
                                                                                  uint8_t id_185 { 0 };
                                                                                  uint8_t id_186 { 0 };
                                                                                  Pointer id_187 { leb128_ptr_347[id_186] };
                                                                                  uint32_t id_188 { 128U };
                                                                                  uint8_t id_189 { 0 };
                                                                                  uint32_t id_190 { leb128_sz_346[id_189] };
                                                                                  bool id_191 { bool(id_188 > id_190) };
                                                                                  uint8_t choose_res_192;
                                                                                  if (id_191) {
                                                                                    uint8_t id_193 { 0 };
                                                                                    uint32_t id_194 { leb128_sz_346[id_193] };
                                                                                    uint8_t id_195 { uint8_t(id_194) };
                                                                                    choose_res_192 = id_195;
                                                                                  } else {
                                                                                    uint8_t id_196 { 0 };
                                                                                    uint32_t id_197 { leb128_sz_346[id_196] };
                                                                                    uint8_t id_198 { uint8_t(id_197) };
                                                                                    uint8_t id_199 { 128 };
                                                                                    uint8_t id_200 { uint8_t(id_198 | id_199) };
                                                                                    choose_res_192 = id_200;
                                                                                  }
                                                                                  Pointer id_201 { id_187.writeU8(choose_res_192) };
                                                                                  Void id_202 { ((void)(leb128_ptr_347[id_185] = id_201), VOID) };
                                                                                  (void)id_202;
                                                                                  uint8_t id_203 { 0 };
                                                                                  uint8_t id_204 { 0 };
                                                                                  uint32_t id_205 { leb128_sz_346[id_204] };
                                                                                  uint8_t id_206 { 7 };
                                                                                  uint32_t id_207 { uint32_t(id_205 >> id_206) };
                                                                                  Void id_208 { ((void)(leb128_sz_346[id_203] = id_207), VOID) };
                                                                                  (void)id_208;
                                                                                  uint8_t id_209 { 0 };
                                                                                  uint32_t id_210 { leb128_sz_346[id_209] };
                                                                                  uint32_t id_211 { 0U };
                                                                                  bool id_212 { bool(id_210 > id_211) };
                                                                                  while_flag_184 = id_212;
                                                                                  if (while_flag_184) {
                                                                                    (void)VOID;
                                                                                  }
                                                                                } while (while_flag_184);
                                                                                (void)VOID;
                                                                                uint8_t id_213 { 0 };
                                                                                Pointer id_214 { leb128_ptr_347[id_213] };
                                                                                let_res_183 = id_214;
                                                                              }
                                                                              let_res_181 = let_res_183;
                                                                            }
                                                                            Vec<1, Pointer> id_215 {  let_res_181  };
                                                                            Pointer let_res_216;
                                                                            {
                                                                              Vec<1, Pointer> dst_ref_348 { id_215 };
                                                                              int32_t id_217 { 0L };
                                                                              Vec<1, int32_t> id_218 {  id_217  };
                                                                              Pointer let_res_219;
                                                                              {
                                                                                Vec<1, int32_t> n_ref_349 { id_218 };
                                                                                ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_220 { p_0->type };
                                                                                Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_221 { std::get<33>(id_220) };
                                                                                for (::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c x_350 : id_221) {
                                                                                  uint8_t id_222 { 0 };
                                                                                  t* id_223 { std::get<1>(x_350) };
                                                                                  uint8_t id_224 { 0 };
                                                                                  Pointer id_225 { dst_ref_348[id_224] };
                                                                                  Pointer let_res_226;
                                                                                  {
                                                                                    Pointer stup_dst_351 { id_225 };
                                                                                    std::string id_227 { std::get<0>(x_350) };
                                                                                    uint32_t id_228 { (uint32_t)id_227.size() };
                                                                                    Vec<1, uint32_t> id_229 {  id_228  };
                                                                                    Pointer let_res_230;
                                                                                    {
                                                                                      Vec<1, uint32_t> leb128_sz_352 { id_229 };
                                                                                      Vec<1, Pointer> id_231 {  stup_dst_351  };
                                                                                      Pointer let_res_232;
                                                                                      {
                                                                                        Vec<1, Pointer> leb128_ptr_353 { id_231 };
                                                                                        bool while_flag_233 { true };
                                                                                        do {
                                                                                          uint8_t id_234 { 0 };
                                                                                          uint8_t id_235 { 0 };
                                                                                          Pointer id_236 { leb128_ptr_353[id_235] };
                                                                                          uint32_t id_237 { 128U };
                                                                                          uint8_t id_238 { 0 };
                                                                                          uint32_t id_239 { leb128_sz_352[id_238] };
                                                                                          bool id_240 { bool(id_237 > id_239) };
                                                                                          uint8_t choose_res_241;
                                                                                          if (id_240) {
                                                                                            uint8_t id_242 { 0 };
                                                                                            uint32_t id_243 { leb128_sz_352[id_242] };
                                                                                            uint8_t id_244 { uint8_t(id_243) };
                                                                                            choose_res_241 = id_244;
                                                                                          } else {
                                                                                            uint8_t id_245 { 0 };
                                                                                            uint32_t id_246 { leb128_sz_352[id_245] };
                                                                                            uint8_t id_247 { uint8_t(id_246) };
                                                                                            uint8_t id_248 { 128 };
                                                                                            uint8_t id_249 { uint8_t(id_247 | id_248) };
                                                                                            choose_res_241 = id_249;
                                                                                          }
                                                                                          Pointer id_250 { id_236.writeU8(choose_res_241) };
                                                                                          Void id_251 { ((void)(leb128_ptr_353[id_234] = id_250), VOID) };
                                                                                          (void)id_251;
                                                                                          uint8_t id_252 { 0 };
                                                                                          uint8_t id_253 { 0 };
                                                                                          uint32_t id_254 { leb128_sz_352[id_253] };
                                                                                          uint8_t id_255 { 7 };
                                                                                          uint32_t id_256 { uint32_t(id_254 >> id_255) };
                                                                                          Void id_257 { ((void)(leb128_sz_352[id_252] = id_256), VOID) };
                                                                                          (void)id_257;
                                                                                          uint8_t id_258 { 0 };
                                                                                          uint32_t id_259 { leb128_sz_352[id_258] };
                                                                                          uint32_t id_260 { 0U };
                                                                                          bool id_261 { bool(id_259 > id_260) };
                                                                                          while_flag_233 = id_261;
                                                                                          if (while_flag_233) {
                                                                                            (void)VOID;
                                                                                          }
                                                                                        } while (while_flag_233);
                                                                                        (void)VOID;
                                                                                        uint8_t id_262 { 0 };
                                                                                        Pointer id_263 { leb128_ptr_353[id_262] };
                                                                                        let_res_232 = id_263;
                                                                                      }
                                                                                      let_res_230 = let_res_232;
                                                                                    }
                                                                                    std::string id_264 { std::get<0>(x_350) };
                                                                                    Bytes id_265 { id_264 };
                                                                                    Pointer id_266 { let_res_230.writeBytes(id_265) };
                                                                                    let_res_226 = id_266;
                                                                                  }
                                                                                  Pointer id_267 { fun0(id_223, let_res_226) };
                                                                                  Void id_268 { ((void)(dst_ref_348[id_222] = id_267), VOID) };
                                                                                  (void)id_268;
                                                                                  uint8_t id_269 { 0 };
                                                                                  int32_t id_270 { 1L };
                                                                                  uint8_t id_271 { 0 };
                                                                                  int32_t id_272 { n_ref_349[id_271] };
                                                                                  int32_t id_273 { int32_t(id_270 + id_272) };
                                                                                  Void id_274 { ((void)(n_ref_349[id_269] = id_273), VOID) };
                                                                                  (void)id_274;
                                                                                  (void)id_274;
                                                                                }
                                                                                (void)VOID;
                                                                                uint8_t id_275 { 0 };
                                                                                Pointer id_276 { dst_ref_348[id_275] };
                                                                                let_res_219 = id_276;
                                                                              }
                                                                              let_res_216 = let_res_219;
                                                                            }
                                                                            choose_res_176 = let_res_216;
                                                                          } else {
                                                                            uint16_t id_277 { 34 };
                                                                            bool id_278 { bool(id_277 == label1_334) };
                                                                            Pointer choose_res_279;
                                                                            if (id_278) {
                                                                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_280 { p_0->type };
                                                                              Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_281 { std::get<34>(id_280) };
                                                                              uint32_t id_282 { id_281.size() };
                                                                              Vec<1, uint32_t> id_283 {  id_282  };
                                                                              Pointer let_res_284;
                                                                              {
                                                                                Vec<1, uint32_t> leb128_sz_337 { id_283 };
                                                                                Vec<1, Pointer> id_285 {  ssum_dst_335  };
                                                                                Pointer let_res_286;
                                                                                {
                                                                                  Vec<1, Pointer> leb128_ptr_338 { id_285 };
                                                                                  bool while_flag_287 { true };
                                                                                  do {
                                                                                    uint8_t id_288 { 0 };
                                                                                    uint8_t id_289 { 0 };
                                                                                    Pointer id_290 { leb128_ptr_338[id_289] };
                                                                                    uint32_t id_291 { 128U };
                                                                                    uint8_t id_292 { 0 };
                                                                                    uint32_t id_293 { leb128_sz_337[id_292] };
                                                                                    bool id_294 { bool(id_291 > id_293) };
                                                                                    uint8_t choose_res_295;
                                                                                    if (id_294) {
                                                                                      uint8_t id_296 { 0 };
                                                                                      uint32_t id_297 { leb128_sz_337[id_296] };
                                                                                      uint8_t id_298 { uint8_t(id_297) };
                                                                                      choose_res_295 = id_298;
                                                                                    } else {
                                                                                      uint8_t id_299 { 0 };
                                                                                      uint32_t id_300 { leb128_sz_337[id_299] };
                                                                                      uint8_t id_301 { uint8_t(id_300) };
                                                                                      uint8_t id_302 { 128 };
                                                                                      uint8_t id_303 { uint8_t(id_301 | id_302) };
                                                                                      choose_res_295 = id_303;
                                                                                    }
                                                                                    Pointer id_304 { id_290.writeU8(choose_res_295) };
                                                                                    Void id_305 { ((void)(leb128_ptr_338[id_288] = id_304), VOID) };
                                                                                    (void)id_305;
                                                                                    uint8_t id_306 { 0 };
                                                                                    uint8_t id_307 { 0 };
                                                                                    uint32_t id_308 { leb128_sz_337[id_307] };
                                                                                    uint8_t id_309 { 7 };
                                                                                    uint32_t id_310 { uint32_t(id_308 >> id_309) };
                                                                                    Void id_311 { ((void)(leb128_sz_337[id_306] = id_310), VOID) };
                                                                                    (void)id_311;
                                                                                    uint8_t id_312 { 0 };
                                                                                    uint32_t id_313 { leb128_sz_337[id_312] };
                                                                                    uint32_t id_314 { 0U };
                                                                                    bool id_315 { bool(id_313 > id_314) };
                                                                                    while_flag_287 = id_315;
                                                                                    if (while_flag_287) {
                                                                                      (void)VOID;
                                                                                    }
                                                                                  } while (while_flag_287);
                                                                                  (void)VOID;
                                                                                  uint8_t id_316 { 0 };
                                                                                  Pointer id_317 { leb128_ptr_338[id_316] };
                                                                                  let_res_286 = id_317;
                                                                                }
                                                                                let_res_284 = let_res_286;
                                                                              }
                                                                              Vec<1, Pointer> id_318 {  let_res_284  };
                                                                              Pointer let_res_319;
                                                                              {
                                                                                Vec<1, Pointer> dst_ref_339 { id_318 };
                                                                                int32_t id_320 { 0L };
                                                                                Vec<1, int32_t> id_321 {  id_320  };
                                                                                Pointer let_res_322;
                                                                                {
                                                                                  Vec<1, int32_t> n_ref_340 { id_321 };
                                                                                  ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_323 { p_0->type };
                                                                                  Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_324 { std::get<34>(id_323) };
                                                                                  for (::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c x_341 : id_324) {
                                                                                    uint8_t id_325 { 0 };
                                                                                    t* id_326 { std::get<1>(x_341) };
                                                                                    uint8_t id_327 { 0 };
                                                                                    Pointer id_328 { dst_ref_339[id_327] };
                                                                                    Pointer let_res_329;
                                                                                    {
                                                                                      Pointer stup_dst_342 { id_328 };
                                                                                      std::string id_330 { std::get<0>(x_341) };
                                                                                      uint32_t id_331 { (uint32_t)id_330.size() };
                                                                                      Vec<1, uint32_t> id_332 {  id_331  };
                                                                                      Pointer let_res_333;
                                                                                      {
                                                                                        Vec<1, uint32_t> leb128_sz_343 { id_332 };
                                                                                        Vec<1, Pointer> id_334 {  stup_dst_342  };
                                                                                        Pointer let_res_335;
                                                                                        {
                                                                                          Vec<1, Pointer> leb128_ptr_344 { id_334 };
                                                                                          bool while_flag_336 { true };
                                                                                          do {
                                                                                            uint8_t id_337 { 0 };
                                                                                            uint8_t id_338 { 0 };
                                                                                            Pointer id_339 { leb128_ptr_344[id_338] };
                                                                                            uint32_t id_340 { 128U };
                                                                                            uint8_t id_341 { 0 };
                                                                                            uint32_t id_342 { leb128_sz_343[id_341] };
                                                                                            bool id_343 { bool(id_340 > id_342) };
                                                                                            uint8_t choose_res_344;
                                                                                            if (id_343) {
                                                                                              uint8_t id_345 { 0 };
                                                                                              uint32_t id_346 { leb128_sz_343[id_345] };
                                                                                              uint8_t id_347 { uint8_t(id_346) };
                                                                                              choose_res_344 = id_347;
                                                                                            } else {
                                                                                              uint8_t id_348 { 0 };
                                                                                              uint32_t id_349 { leb128_sz_343[id_348] };
                                                                                              uint8_t id_350 { uint8_t(id_349) };
                                                                                              uint8_t id_351 { 128 };
                                                                                              uint8_t id_352 { uint8_t(id_350 | id_351) };
                                                                                              choose_res_344 = id_352;
                                                                                            }
                                                                                            Pointer id_353 { id_339.writeU8(choose_res_344) };
                                                                                            Void id_354 { ((void)(leb128_ptr_344[id_337] = id_353), VOID) };
                                                                                            (void)id_354;
                                                                                            uint8_t id_355 { 0 };
                                                                                            uint8_t id_356 { 0 };
                                                                                            uint32_t id_357 { leb128_sz_343[id_356] };
                                                                                            uint8_t id_358 { 7 };
                                                                                            uint32_t id_359 { uint32_t(id_357 >> id_358) };
                                                                                            Void id_360 { ((void)(leb128_sz_343[id_355] = id_359), VOID) };
                                                                                            (void)id_360;
                                                                                            uint8_t id_361 { 0 };
                                                                                            uint32_t id_362 { leb128_sz_343[id_361] };
                                                                                            uint32_t id_363 { 0U };
                                                                                            bool id_364 { bool(id_362 > id_363) };
                                                                                            while_flag_336 = id_364;
                                                                                            if (while_flag_336) {
                                                                                              (void)VOID;
                                                                                            }
                                                                                          } while (while_flag_336);
                                                                                          (void)VOID;
                                                                                          uint8_t id_365 { 0 };
                                                                                          Pointer id_366 { leb128_ptr_344[id_365] };
                                                                                          let_res_335 = id_366;
                                                                                        }
                                                                                        let_res_333 = let_res_335;
                                                                                      }
                                                                                      std::string id_367 { std::get<0>(x_341) };
                                                                                      Bytes id_368 { id_367 };
                                                                                      Pointer id_369 { let_res_333.writeBytes(id_368) };
                                                                                      let_res_329 = id_369;
                                                                                    }
                                                                                    Pointer id_370 { fun0(id_326, let_res_329) };
                                                                                    Void id_371 { ((void)(dst_ref_339[id_325] = id_370), VOID) };
                                                                                    (void)id_371;
                                                                                    uint8_t id_372 { 0 };
                                                                                    int32_t id_373 { 1L };
                                                                                    uint8_t id_374 { 0 };
                                                                                    int32_t id_375 { n_ref_340[id_374] };
                                                                                    int32_t id_376 { int32_t(id_373 + id_375) };
                                                                                    Void id_377 { ((void)(n_ref_340[id_372] = id_376), VOID) };
                                                                                    (void)id_377;
                                                                                    (void)id_377;
                                                                                  }
                                                                                  (void)VOID;
                                                                                  uint8_t id_378 { 0 };
                                                                                  Pointer id_379 { dst_ref_339[id_378] };
                                                                                  let_res_322 = id_379;
                                                                                }
                                                                                let_res_319 = let_res_322;
                                                                              }
                                                                              choose_res_279 = let_res_319;
                                                                            } else {
                                                                              uint16_t id_380 { 35 };
                                                                              bool id_381 { bool(label1_334 == id_380) };
                                                                              Void id_382 { ((void)(assert(id_381)), VOID) };
                                                                              (void)id_382;
                                                                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_383 { p_0->type };
                                                                              ::dessser::gen::raql_type::t7411897bdb6c9b6e00a01b4eb6506ccf id_384 { std::get<35>(id_383) };
                                                                              t* id_385 { std::get<1>(id_384) };
                                                                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_386 { p_0->type };
                                                                              ::dessser::gen::raql_type::t7411897bdb6c9b6e00a01b4eb6506ccf id_387 { std::get<35>(id_386) };
                                                                              t* id_388 { std::get<0>(id_387) };
                                                                              Pointer id_389 { fun0(id_388, ssum_dst_335) };
                                                                              Pointer id_390 { fun0(id_385, id_389) };
                                                                              choose_res_279 = id_390;
                                                                            }
                                                                            choose_res_176 = choose_res_279;
                                                                          }
                                                                          choose_res_170 = choose_res_176;
                                                                        }
                                                                        choose_res_159 = choose_res_170;
                                                                      }
                                                                      choose_res_98 = choose_res_159;
                                                                    }
                                                                    choose_res_95 = choose_res_98;
                                                                  }
                                                                  choose_res_92 = choose_res_95;
                                                                }
                                                                choose_res_89 = choose_res_92;
                                                              }
                                                              choose_res_86 = choose_res_89;
                                                            }
                                                            choose_res_83 = choose_res_86;
                                                          }
                                                          choose_res_80 = choose_res_83;
                                                        }
                                                        choose_res_77 = choose_res_80;
                                                      }
                                                      choose_res_74 = choose_res_77;
                                                    }
                                                    choose_res_71 = choose_res_74;
                                                  }
                                                  choose_res_68 = choose_res_71;
                                                }
                                                choose_res_65 = choose_res_68;
                                              }
                                              choose_res_62 = choose_res_65;
                                            }
                                            choose_res_59 = choose_res_62;
                                          }
                                          choose_res_56 = choose_res_59;
                                        }
                                        choose_res_53 = choose_res_56;
                                      }
                                      choose_res_50 = choose_res_53;
                                    }
                                    choose_res_47 = choose_res_50;
                                  }
                                  choose_res_44 = choose_res_47;
                                }
                                choose_res_41 = choose_res_44;
                              }
                              choose_res_38 = choose_res_41;
                            }
                            choose_res_35 = choose_res_38;
                          }
                          choose_res_32 = choose_res_35;
                        }
                        choose_res_29 = choose_res_32;
                      }
                      choose_res_26 = choose_res_29;
                    }
                    choose_res_23 = choose_res_26;
                  }
                  choose_res_20 = choose_res_23;
                }
                choose_res_17 = choose_res_20;
              }
              choose_res_14 = choose_res_17;
            }
            choose_res_11 = choose_res_14;
          }
          choose_res_8 = choose_res_11;
        }
        let_res_5 = choose_res_8;
      }
      let_res_3 = let_res_5;
    }
    Pointer let_res_391;
    {
      Pointer srec_dst_361 { let_res_3 };
      bool id_392 { p_0->nullable };
      uint8_t id_393 { uint8_t(id_392) };
      Pointer id_394 { srec_dst_361.writeU8(id_393) };
      let_res_391 = id_394;
    }
    return let_res_391;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::raql_type::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{type: [Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]; nullable: BOOL}")
      (add
        (let "sz_305" (size 0)
          (let "label2_306" (label-of (get-field "type" (param 0)))
            (if (eq (u16 0) (identifier "label2_306")) (add (identifier "sz_305") (size 2))
              (if (eq (u16 1) (identifier "label2_306")) (add (identifier "sz_305") (size 2))
                (if (eq (u16 2) (identifier "label2_306")) (add (identifier "sz_305") (size 2))
                  (if (eq (u16 3) (identifier "label2_306")) (add (identifier "sz_305") (size 2))
                    (if (eq (u16 4) (identifier "label2_306")) (add (identifier "sz_305") (size 2))
                      (if (eq (u16 5) (identifier "label2_306")) (add (identifier "sz_305") (size 2))
                        (if (eq (u16 6) (identifier "label2_306")) (add (identifier "sz_305") (size 2))
                          (if (eq (u16 7) (identifier "label2_306")) 
                            (add (identifier "sz_305") (size 2))
                            (if (eq (u16 8) (identifier "label2_306")) 
                              (add (identifier "sz_305") (size 2))
                              (if (eq (u16 9) (identifier "label2_306")) 
                                (add (identifier "sz_305") (size 2))
                                (if (eq (u16 10) (identifier "label2_306")) 
                                  (add (identifier "sz_305") (size 2))
                                  (if (eq (u16 11) (identifier "label2_306")) 
                                    (add (identifier "sz_305") (size 2))
                                    (if (eq (u16 12) (identifier "label2_306")) 
                                      (add (identifier "sz_305") (size 2))
                                      (if (eq (u16 13) (identifier "label2_306")) 
                                        (add (identifier "sz_305") (size 2))
                                        (if (eq (u16 14) (identifier "label2_306")) 
                                          (add (identifier "sz_305") (size 2))
                                          (if (eq (u16 15) (identifier "label2_306")) 
                                            (add (identifier "sz_305") (size 2))
                                            (if (eq (u16 16) (identifier "label2_306")) 
                                              (add (identifier "sz_305") (size 2))
                                              (if (eq (u16 17) (identifier "label2_306")) 
                                                (add (identifier "sz_305") (size 2))
                                                (if (eq (u16 18) (identifier "label2_306")) 
                                                  (add (identifier "sz_305") (size 2))
                                                  (if (eq (u16 19) (identifier "label2_306")) 
                                                    (add (identifier "sz_305") (size 2))
                                                    (if (eq (u16 20) (identifier "label2_306")) 
                                                      (add (identifier "sz_305") (size 2))
                                                      (if (eq (u16 21) (identifier "label2_306")) 
                                                        (add (identifier "sz_305") (size 2))
                                                        (if (eq (u16 22) (identifier "label2_306")) 
                                                          (add (identifier "sz_305") (size 2))
                                                          (if (eq (u16 23) (identifier "label2_306")) 
                                                            (add (identifier "sz_305") (size 2))
                                                            (if (eq (u16 24) (identifier "label2_306")) 
                                                              (add (identifier "sz_305") (size 2))
                                                              (if (eq (u16 25) (identifier "label2_306")) 
                                                                (add (identifier "sz_305") (size 2))
                                                                (if (eq (u16 26) (identifier "label2_306")) 
                                                                  (add (identifier "sz_305") (size 2))
                                                                  (if 
                                                                    (eq (u16 27) (identifier "label2_306")) 
                                                                    (add (identifier "sz_305") (size 2))
                                                                    (if 
                                                                    (eq (u16 28) (identifier "label2_306")) 
                                                                    (add (identifier "sz_305") (size 2))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "label2_306")) 
                                                                    (add (identifier "sz_305") (size 2))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label2_306"))
                                                                    (let "sz_ref_331"
                                                                    (make-vec
                                                                    (add 
                                                                    (add (identifier "sz_305") (size 2))
                                                                    (let "n_ref_329" 
                                                                    (make-vec (cardinality (get-alt "Tup" (get-field "type" (param 0)))))
                                                                    (let "lebsz_ref_330" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_329")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_330")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_330") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_330")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_330"))))))))
                                                                    (seq
                                                                    (let "repeat_n_332" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Tup" (get-field "type" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_332")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_331")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_331"))
                                                                    (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_332")) (get-alt "Tup" (get-field "type" (param 0)))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_332") (add (unsafe-nth (u8 0) (identifier "repeat_n_332")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_331"))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label2_306"))
                                                                    (add (add (add (identifier "sz_305") (size 2)) (size 4)) (apply (myself "Size") (get-item 1 (get-alt "Vec" (get-field "type" (param 0))))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label2_306")) 
                                                                    (add (add (identifier "sz_305") (size 2)) (apply (myself "Size") (get-alt "Arr" (get-field "type" (param 0)))))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label2_306"))
                                                                    (let "sz_ref_320"
                                                                    (make-vec
                                                                    (add 
                                                                    (add (identifier "sz_305") (size 2))
                                                                    (let "n_ref_318" 
                                                                    (make-vec (cardinality (get-alt "Rec" (get-field "type" (param 0)))))
                                                                    (let "lebsz_ref_319" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_318")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_319")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_319") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_319")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_319"))))))))
                                                                    (seq
                                                                    (let "repeat_n_321" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Rec" (get-field "type" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_321")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_320")
                                                                    (let "sz_326"
                                                                    (let "sz_322" 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_320"))
                                                                    (add 
                                                                    (identifier "sz_322")
                                                                    (let "wlen_323" 
                                                                    (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_321")) (get-alt "Rec" (get-field "type" (param 0))))))
                                                                    (add
                                                                    (let "n_ref_324" 
                                                                    (make-vec (identifier "wlen_323"))
                                                                    (let "lebsz_ref_325" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_324")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_325")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_325") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_325")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_325")))))) 
                                                                    (size-of-u32 (identifier "wlen_323"))))))
                                                                    (add 
                                                                    (identifier "sz_326")
                                                                    (apply (myself "Size") (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_321")) (get-alt "Rec" (get-field "type" (param 0)))))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_321") (add (unsafe-nth (u8 0) (identifier "repeat_n_321")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_320"))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label2_306"))
                                                                    (let "sz_ref_311"
                                                                    (make-vec
                                                                    (add 
                                                                    (add (identifier "sz_305") (size 2))
                                                                    (let "n_ref_309" 
                                                                    (make-vec (cardinality (get-alt "Sum" (get-field "type" (param 0)))))
                                                                    (let "lebsz_ref_310" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_309")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_310")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_310") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_310")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_310"))))))))
                                                                    (seq
                                                                    (let "repeat_n_312" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Sum" (get-field "type" (param 0))))) (unsafe-nth (u8 0) (identifier "repeat_n_312")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_311")
                                                                    (let "sz_317"
                                                                    (let "sz_313" 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_311"))
                                                                    (add 
                                                                    (identifier "sz_313")
                                                                    (let "wlen_314" 
                                                                    (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_312")) (get-alt "Sum" (get-field "type" (param 0))))))
                                                                    (add
                                                                    (let "n_ref_315" 
                                                                    (make-vec (identifier "wlen_314"))
                                                                    (let "lebsz_ref_316" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_315")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_316")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_316") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_316")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_316")))))) 
                                                                    (size-of-u32 (identifier "wlen_314"))))))
                                                                    (add 
                                                                    (identifier "sz_317")
                                                                    (apply (myself "Size") (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_312")) (get-alt "Sum" (get-field "type" (param 0)))))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_312") (add (unsafe-nth (u8 0) (identifier "repeat_n_312")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_311"))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label2_306") (u16 35)))
                                                                    (add 
                                                                    (add (add (identifier "sz_305") (size 2)) (apply (myself "Size") (get-item 0 (get-alt "Map" (get-field "type" (param 0))))))
                                                                    (apply (myself "Size") (get-item 1 (get-alt "Map" (get-field "type" (param 0)))))))))))))))))))))))))))))))))))))))))))) 
        (size 1)))
 */
static std::function<Size(::dessser::gen::raql_type::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_type::t*)> fun395 { [&fun395](::dessser::gen::raql_type::t* p_0) {
    Size id_396 { 0UL };
    Size let_res_397;
    {
      Size sz_305 { id_396 };
      ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_398 { p_0->type };
      uint16_t id_399 { uint16_t(id_398.index()) };
      Size let_res_400;
      {
        uint16_t label2_306 { id_399 };
        uint16_t id_401 { 0 };
        bool id_402 { bool(id_401 == label2_306) };
        Size choose_res_403;
        if (id_402) {
          Size id_404 { 2UL };
          Size id_405 { Size(sz_305 + id_404) };
          choose_res_403 = id_405;
        } else {
          uint16_t id_406 { 1 };
          bool id_407 { bool(id_406 == label2_306) };
          Size choose_res_408;
          if (id_407) {
            Size id_409 { 2UL };
            Size id_410 { Size(sz_305 + id_409) };
            choose_res_408 = id_410;
          } else {
            uint16_t id_411 { 2 };
            bool id_412 { bool(id_411 == label2_306) };
            Size choose_res_413;
            if (id_412) {
              Size id_414 { 2UL };
              Size id_415 { Size(sz_305 + id_414) };
              choose_res_413 = id_415;
            } else {
              uint16_t id_416 { 3 };
              bool id_417 { bool(id_416 == label2_306) };
              Size choose_res_418;
              if (id_417) {
                Size id_419 { 2UL };
                Size id_420 { Size(sz_305 + id_419) };
                choose_res_418 = id_420;
              } else {
                uint16_t id_421 { 4 };
                bool id_422 { bool(id_421 == label2_306) };
                Size choose_res_423;
                if (id_422) {
                  Size id_424 { 2UL };
                  Size id_425 { Size(sz_305 + id_424) };
                  choose_res_423 = id_425;
                } else {
                  uint16_t id_426 { 5 };
                  bool id_427 { bool(id_426 == label2_306) };
                  Size choose_res_428;
                  if (id_427) {
                    Size id_429 { 2UL };
                    Size id_430 { Size(sz_305 + id_429) };
                    choose_res_428 = id_430;
                  } else {
                    uint16_t id_431 { 6 };
                    bool id_432 { bool(id_431 == label2_306) };
                    Size choose_res_433;
                    if (id_432) {
                      Size id_434 { 2UL };
                      Size id_435 { Size(sz_305 + id_434) };
                      choose_res_433 = id_435;
                    } else {
                      uint16_t id_436 { 7 };
                      bool id_437 { bool(id_436 == label2_306) };
                      Size choose_res_438;
                      if (id_437) {
                        Size id_439 { 2UL };
                        Size id_440 { Size(sz_305 + id_439) };
                        choose_res_438 = id_440;
                      } else {
                        uint16_t id_441 { 8 };
                        bool id_442 { bool(id_441 == label2_306) };
                        Size choose_res_443;
                        if (id_442) {
                          Size id_444 { 2UL };
                          Size id_445 { Size(sz_305 + id_444) };
                          choose_res_443 = id_445;
                        } else {
                          uint16_t id_446 { 9 };
                          bool id_447 { bool(id_446 == label2_306) };
                          Size choose_res_448;
                          if (id_447) {
                            Size id_449 { 2UL };
                            Size id_450 { Size(sz_305 + id_449) };
                            choose_res_448 = id_450;
                          } else {
                            uint16_t id_451 { 10 };
                            bool id_452 { bool(id_451 == label2_306) };
                            Size choose_res_453;
                            if (id_452) {
                              Size id_454 { 2UL };
                              Size id_455 { Size(sz_305 + id_454) };
                              choose_res_453 = id_455;
                            } else {
                              uint16_t id_456 { 11 };
                              bool id_457 { bool(id_456 == label2_306) };
                              Size choose_res_458;
                              if (id_457) {
                                Size id_459 { 2UL };
                                Size id_460 { Size(sz_305 + id_459) };
                                choose_res_458 = id_460;
                              } else {
                                uint16_t id_461 { 12 };
                                bool id_462 { bool(id_461 == label2_306) };
                                Size choose_res_463;
                                if (id_462) {
                                  Size id_464 { 2UL };
                                  Size id_465 { Size(sz_305 + id_464) };
                                  choose_res_463 = id_465;
                                } else {
                                  uint16_t id_466 { 13 };
                                  bool id_467 { bool(id_466 == label2_306) };
                                  Size choose_res_468;
                                  if (id_467) {
                                    Size id_469 { 2UL };
                                    Size id_470 { Size(sz_305 + id_469) };
                                    choose_res_468 = id_470;
                                  } else {
                                    uint16_t id_471 { 14 };
                                    bool id_472 { bool(id_471 == label2_306) };
                                    Size choose_res_473;
                                    if (id_472) {
                                      Size id_474 { 2UL };
                                      Size id_475 { Size(sz_305 + id_474) };
                                      choose_res_473 = id_475;
                                    } else {
                                      uint16_t id_476 { 15 };
                                      bool id_477 { bool(id_476 == label2_306) };
                                      Size choose_res_478;
                                      if (id_477) {
                                        Size id_479 { 2UL };
                                        Size id_480 { Size(sz_305 + id_479) };
                                        choose_res_478 = id_480;
                                      } else {
                                        uint16_t id_481 { 16 };
                                        bool id_482 { bool(id_481 == label2_306) };
                                        Size choose_res_483;
                                        if (id_482) {
                                          Size id_484 { 2UL };
                                          Size id_485 { Size(sz_305 + id_484) };
                                          choose_res_483 = id_485;
                                        } else {
                                          uint16_t id_486 { 17 };
                                          bool id_487 { bool(id_486 == label2_306) };
                                          Size choose_res_488;
                                          if (id_487) {
                                            Size id_489 { 2UL };
                                            Size id_490 { Size(sz_305 + id_489) };
                                            choose_res_488 = id_490;
                                          } else {
                                            uint16_t id_491 { 18 };
                                            bool id_492 { bool(id_491 == label2_306) };
                                            Size choose_res_493;
                                            if (id_492) {
                                              Size id_494 { 2UL };
                                              Size id_495 { Size(sz_305 + id_494) };
                                              choose_res_493 = id_495;
                                            } else {
                                              uint16_t id_496 { 19 };
                                              bool id_497 { bool(id_496 == label2_306) };
                                              Size choose_res_498;
                                              if (id_497) {
                                                Size id_499 { 2UL };
                                                Size id_500 { Size(sz_305 + id_499) };
                                                choose_res_498 = id_500;
                                              } else {
                                                uint16_t id_501 { 20 };
                                                bool id_502 { bool(id_501 == label2_306) };
                                                Size choose_res_503;
                                                if (id_502) {
                                                  Size id_504 { 2UL };
                                                  Size id_505 { Size(sz_305 + id_504) };
                                                  choose_res_503 = id_505;
                                                } else {
                                                  uint16_t id_506 { 21 };
                                                  bool id_507 { bool(id_506 == label2_306) };
                                                  Size choose_res_508;
                                                  if (id_507) {
                                                    Size id_509 { 2UL };
                                                    Size id_510 { Size(sz_305 + id_509) };
                                                    choose_res_508 = id_510;
                                                  } else {
                                                    uint16_t id_511 { 22 };
                                                    bool id_512 { bool(id_511 == label2_306) };
                                                    Size choose_res_513;
                                                    if (id_512) {
                                                      Size id_514 { 2UL };
                                                      Size id_515 { Size(sz_305 + id_514) };
                                                      choose_res_513 = id_515;
                                                    } else {
                                                      uint16_t id_516 { 23 };
                                                      bool id_517 { bool(id_516 == label2_306) };
                                                      Size choose_res_518;
                                                      if (id_517) {
                                                        Size id_519 { 2UL };
                                                        Size id_520 { Size(sz_305 + id_519) };
                                                        choose_res_518 = id_520;
                                                      } else {
                                                        uint16_t id_521 { 24 };
                                                        bool id_522 { bool(id_521 == label2_306) };
                                                        Size choose_res_523;
                                                        if (id_522) {
                                                          Size id_524 { 2UL };
                                                          Size id_525 { Size(sz_305 + id_524) };
                                                          choose_res_523 = id_525;
                                                        } else {
                                                          uint16_t id_526 { 25 };
                                                          bool id_527 { bool(id_526 == label2_306) };
                                                          Size choose_res_528;
                                                          if (id_527) {
                                                            Size id_529 { 2UL };
                                                            Size id_530 { Size(sz_305 + id_529) };
                                                            choose_res_528 = id_530;
                                                          } else {
                                                            uint16_t id_531 { 26 };
                                                            bool id_532 { bool(id_531 == label2_306) };
                                                            Size choose_res_533;
                                                            if (id_532) {
                                                              Size id_534 { 2UL };
                                                              Size id_535 { Size(sz_305 + id_534) };
                                                              choose_res_533 = id_535;
                                                            } else {
                                                              uint16_t id_536 { 27 };
                                                              bool id_537 { bool(id_536 == label2_306) };
                                                              Size choose_res_538;
                                                              if (id_537) {
                                                                Size id_539 { 2UL };
                                                                Size id_540 { Size(sz_305 + id_539) };
                                                                choose_res_538 = id_540;
                                                              } else {
                                                                uint16_t id_541 { 28 };
                                                                bool id_542 { bool(id_541 == label2_306) };
                                                                Size choose_res_543;
                                                                if (id_542) {
                                                                  Size id_544 { 2UL };
                                                                  Size id_545 { Size(sz_305 + id_544) };
                                                                  choose_res_543 = id_545;
                                                                } else {
                                                                  uint16_t id_546 { 29 };
                                                                  bool id_547 { bool(id_546 == label2_306) };
                                                                  Size choose_res_548;
                                                                  if (id_547) {
                                                                    Size id_549 { 2UL };
                                                                    Size id_550 { Size(sz_305 + id_549) };
                                                                    choose_res_548 = id_550;
                                                                  } else {
                                                                    uint16_t id_551 { 30 };
                                                                    bool id_552 { bool(id_551 == label2_306) };
                                                                    Size choose_res_553;
                                                                    if (id_552) {
                                                                      Size id_554 { 2UL };
                                                                      Size id_555 { Size(sz_305 + id_554) };
                                                                      ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_556 { p_0->type };
                                                                      Arr<t*> id_557 { std::get<30>(id_556) };
                                                                      uint32_t id_558 { id_557.size() };
                                                                      Vec<1, uint32_t> id_559 {  id_558  };
                                                                      Size let_res_560;
                                                                      {
                                                                        Vec<1, uint32_t> n_ref_329 { id_559 };
                                                                        uint32_t id_561 { 1U };
                                                                        Vec<1, uint32_t> id_562 {  id_561  };
                                                                        Size let_res_563;
                                                                        {
                                                                          Vec<1, uint32_t> lebsz_ref_330 { id_562 };
                                                                          bool while_flag_564 { true };
                                                                          do {
                                                                            uint8_t id_565 { 0 };
                                                                            uint32_t id_566 { n_ref_329[id_565] };
                                                                            uint8_t id_567 { 0 };
                                                                            uint32_t id_568 { lebsz_ref_330[id_567] };
                                                                            uint8_t id_569 { 7 };
                                                                            uint32_t id_570 { uint32_t(id_568 << id_569) };
                                                                            bool id_571 { bool(id_566 >= id_570) };
                                                                            while_flag_564 = id_571;
                                                                            if (while_flag_564) {
                                                                              uint8_t id_572 { 0 };
                                                                              uint8_t id_573 { 0 };
                                                                              uint32_t id_574 { lebsz_ref_330[id_573] };
                                                                              uint32_t id_575 { 1U };
                                                                              uint32_t id_576 { uint32_t(id_574 + id_575) };
                                                                              Void id_577 { ((void)(lebsz_ref_330[id_572] = id_576), VOID) };
                                                                              (void)id_577;
                                                                            }
                                                                          } while (while_flag_564);
                                                                          (void)VOID;
                                                                          uint8_t id_578 { 0 };
                                                                          uint32_t id_579 { lebsz_ref_330[id_578] };
                                                                          Size id_580 { Size(id_579) };
                                                                          let_res_563 = id_580;
                                                                        }
                                                                        let_res_560 = let_res_563;
                                                                      }
                                                                      Size id_581 { Size(id_555 + let_res_560) };
                                                                      Vec<1, Size> id_582 {  id_581  };
                                                                      Size let_res_583;
                                                                      {
                                                                        Vec<1, Size> sz_ref_331 { id_582 };
                                                                        int32_t id_584 { 0L };
                                                                        Vec<1, int32_t> id_585 {  id_584  };
                                                                        {
                                                                          Vec<1, int32_t> repeat_n_332 { id_585 };
                                                                          bool while_flag_586 { true };
                                                                          do {
                                                                            ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_587 { p_0->type };
                                                                            Arr<t*> id_588 { std::get<30>(id_587) };
                                                                            uint32_t id_589 { id_588.size() };
                                                                            int32_t id_590 { int32_t(id_589) };
                                                                            uint8_t id_591 { 0 };
                                                                            int32_t id_592 { repeat_n_332[id_591] };
                                                                            bool id_593 { bool(id_590 > id_592) };
                                                                            while_flag_586 = id_593;
                                                                            if (while_flag_586) {
                                                                              uint8_t id_594 { 0 };
                                                                              uint8_t id_595 { 0 };
                                                                              Size id_596 { sz_ref_331[id_595] };
                                                                              uint8_t id_597 { 0 };
                                                                              int32_t id_598 { repeat_n_332[id_597] };
                                                                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_599 { p_0->type };
                                                                              Arr<t*> id_600 { std::get<30>(id_599) };
                                                                              t* id_601 { id_600[id_598] };
                                                                              Size id_602 { fun395(id_601) };
                                                                              Size id_603 { Size(id_596 + id_602) };
                                                                              Void id_604 { ((void)(sz_ref_331[id_594] = id_603), VOID) };
                                                                              (void)id_604;
                                                                              uint8_t id_605 { 0 };
                                                                              uint8_t id_606 { 0 };
                                                                              int32_t id_607 { repeat_n_332[id_606] };
                                                                              int32_t id_608 { 1L };
                                                                              int32_t id_609 { int32_t(id_607 + id_608) };
                                                                              Void id_610 { ((void)(repeat_n_332[id_605] = id_609), VOID) };
                                                                              (void)id_610;
                                                                              (void)id_610;
                                                                            }
                                                                          } while (while_flag_586);
                                                                          (void)VOID;
                                                                        }
                                                                        (void)VOID;
                                                                        uint8_t id_611 { 0 };
                                                                        Size id_612 { sz_ref_331[id_611] };
                                                                        let_res_583 = id_612;
                                                                      }
                                                                      choose_res_553 = let_res_583;
                                                                    } else {
                                                                      uint16_t id_613 { 31 };
                                                                      bool id_614 { bool(id_613 == label2_306) };
                                                                      Size choose_res_615;
                                                                      if (id_614) {
                                                                        Size id_616 { 2UL };
                                                                        Size id_617 { Size(sz_305 + id_616) };
                                                                        Size id_618 { 4UL };
                                                                        Size id_619 { Size(id_617 + id_618) };
                                                                        ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_620 { p_0->type };
                                                                        ::dessser::gen::raql_type::t9327d6336842c469509b67056a719df9 id_621 { std::get<31>(id_620) };
                                                                        t* id_622 { std::get<1>(id_621) };
                                                                        Size id_623 { fun395(id_622) };
                                                                        Size id_624 { Size(id_619 + id_623) };
                                                                        choose_res_615 = id_624;
                                                                      } else {
                                                                        uint16_t id_625 { 32 };
                                                                        bool id_626 { bool(id_625 == label2_306) };
                                                                        Size choose_res_627;
                                                                        if (id_626) {
                                                                          Size id_628 { 2UL };
                                                                          Size id_629 { Size(sz_305 + id_628) };
                                                                          ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_630 { p_0->type };
                                                                          t* id_631 { std::get<32>(id_630) };
                                                                          Size id_632 { fun395(id_631) };
                                                                          Size id_633 { Size(id_629 + id_632) };
                                                                          choose_res_627 = id_633;
                                                                        } else {
                                                                          uint16_t id_634 { 33 };
                                                                          bool id_635 { bool(id_634 == label2_306) };
                                                                          Size choose_res_636;
                                                                          if (id_635) {
                                                                            Size id_637 { 2UL };
                                                                            Size id_638 { Size(sz_305 + id_637) };
                                                                            ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_639 { p_0->type };
                                                                            Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_640 { std::get<33>(id_639) };
                                                                            uint32_t id_641 { id_640.size() };
                                                                            Vec<1, uint32_t> id_642 {  id_641  };
                                                                            Size let_res_643;
                                                                            {
                                                                              Vec<1, uint32_t> n_ref_318 { id_642 };
                                                                              uint32_t id_644 { 1U };
                                                                              Vec<1, uint32_t> id_645 {  id_644  };
                                                                              Size let_res_646;
                                                                              {
                                                                                Vec<1, uint32_t> lebsz_ref_319 { id_645 };
                                                                                bool while_flag_647 { true };
                                                                                do {
                                                                                  uint8_t id_648 { 0 };
                                                                                  uint32_t id_649 { n_ref_318[id_648] };
                                                                                  uint8_t id_650 { 0 };
                                                                                  uint32_t id_651 { lebsz_ref_319[id_650] };
                                                                                  uint8_t id_652 { 7 };
                                                                                  uint32_t id_653 { uint32_t(id_651 << id_652) };
                                                                                  bool id_654 { bool(id_649 >= id_653) };
                                                                                  while_flag_647 = id_654;
                                                                                  if (while_flag_647) {
                                                                                    uint8_t id_655 { 0 };
                                                                                    uint8_t id_656 { 0 };
                                                                                    uint32_t id_657 { lebsz_ref_319[id_656] };
                                                                                    uint32_t id_658 { 1U };
                                                                                    uint32_t id_659 { uint32_t(id_657 + id_658) };
                                                                                    Void id_660 { ((void)(lebsz_ref_319[id_655] = id_659), VOID) };
                                                                                    (void)id_660;
                                                                                  }
                                                                                } while (while_flag_647);
                                                                                (void)VOID;
                                                                                uint8_t id_661 { 0 };
                                                                                uint32_t id_662 { lebsz_ref_319[id_661] };
                                                                                Size id_663 { Size(id_662) };
                                                                                let_res_646 = id_663;
                                                                              }
                                                                              let_res_643 = let_res_646;
                                                                            }
                                                                            Size id_664 { Size(id_638 + let_res_643) };
                                                                            Vec<1, Size> id_665 {  id_664  };
                                                                            Size let_res_666;
                                                                            {
                                                                              Vec<1, Size> sz_ref_320 { id_665 };
                                                                              int32_t id_667 { 0L };
                                                                              Vec<1, int32_t> id_668 {  id_667  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_321 { id_668 };
                                                                                bool while_flag_669 { true };
                                                                                do {
                                                                                  ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_670 { p_0->type };
                                                                                  Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_671 { std::get<33>(id_670) };
                                                                                  uint32_t id_672 { id_671.size() };
                                                                                  int32_t id_673 { int32_t(id_672) };
                                                                                  uint8_t id_674 { 0 };
                                                                                  int32_t id_675 { repeat_n_321[id_674] };
                                                                                  bool id_676 { bool(id_673 > id_675) };
                                                                                  while_flag_669 = id_676;
                                                                                  if (while_flag_669) {
                                                                                    uint8_t id_677 { 0 };
                                                                                    uint8_t id_678 { 0 };
                                                                                    Size id_679 { sz_ref_320[id_678] };
                                                                                    Size let_res_680;
                                                                                    {
                                                                                      Size sz_322 { id_679 };
                                                                                      uint8_t id_681 { 0 };
                                                                                      int32_t id_682 { repeat_n_321[id_681] };
                                                                                      ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_683 { p_0->type };
                                                                                      Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_684 { std::get<33>(id_683) };
                                                                                      ::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c id_685 { id_684[id_682] };
                                                                                      std::string id_686 { std::get<0>(id_685) };
                                                                                      uint32_t id_687 { (uint32_t)id_686.size() };
                                                                                      Size let_res_688;
                                                                                      {
                                                                                        uint32_t wlen_323 { id_687 };
                                                                                        Vec<1, uint32_t> id_689 {  wlen_323  };
                                                                                        Size let_res_690;
                                                                                        {
                                                                                          Vec<1, uint32_t> n_ref_324 { id_689 };
                                                                                          uint32_t id_691 { 1U };
                                                                                          Vec<1, uint32_t> id_692 {  id_691  };
                                                                                          Size let_res_693;
                                                                                          {
                                                                                            Vec<1, uint32_t> lebsz_ref_325 { id_692 };
                                                                                            bool while_flag_694 { true };
                                                                                            do {
                                                                                              uint8_t id_695 { 0 };
                                                                                              uint32_t id_696 { n_ref_324[id_695] };
                                                                                              uint8_t id_697 { 0 };
                                                                                              uint32_t id_698 { lebsz_ref_325[id_697] };
                                                                                              uint8_t id_699 { 7 };
                                                                                              uint32_t id_700 { uint32_t(id_698 << id_699) };
                                                                                              bool id_701 { bool(id_696 >= id_700) };
                                                                                              while_flag_694 = id_701;
                                                                                              if (while_flag_694) {
                                                                                                uint8_t id_702 { 0 };
                                                                                                uint8_t id_703 { 0 };
                                                                                                uint32_t id_704 { lebsz_ref_325[id_703] };
                                                                                                uint32_t id_705 { 1U };
                                                                                                uint32_t id_706 { uint32_t(id_704 + id_705) };
                                                                                                Void id_707 { ((void)(lebsz_ref_325[id_702] = id_706), VOID) };
                                                                                                (void)id_707;
                                                                                              }
                                                                                            } while (while_flag_694);
                                                                                            (void)VOID;
                                                                                            uint8_t id_708 { 0 };
                                                                                            uint32_t id_709 { lebsz_ref_325[id_708] };
                                                                                            Size id_710 { Size(id_709) };
                                                                                            let_res_693 = id_710;
                                                                                          }
                                                                                          let_res_690 = let_res_693;
                                                                                        }
                                                                                        Size id_711 { Size(wlen_323) };
                                                                                        Size id_712 { Size(let_res_690 + id_711) };
                                                                                        let_res_688 = id_712;
                                                                                      }
                                                                                      Size id_713 { Size(sz_322 + let_res_688) };
                                                                                      let_res_680 = id_713;
                                                                                    }
                                                                                    Size let_res_714;
                                                                                    {
                                                                                      Size sz_326 { let_res_680 };
                                                                                      uint8_t id_715 { 0 };
                                                                                      int32_t id_716 { repeat_n_321[id_715] };
                                                                                      ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_717 { p_0->type };
                                                                                      Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_718 { std::get<33>(id_717) };
                                                                                      ::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c id_719 { id_718[id_716] };
                                                                                      t* id_720 { std::get<1>(id_719) };
                                                                                      Size id_721 { fun395(id_720) };
                                                                                      Size id_722 { Size(sz_326 + id_721) };
                                                                                      let_res_714 = id_722;
                                                                                    }
                                                                                    Void id_723 { ((void)(sz_ref_320[id_677] = let_res_714), VOID) };
                                                                                    (void)id_723;
                                                                                    uint8_t id_724 { 0 };
                                                                                    uint8_t id_725 { 0 };
                                                                                    int32_t id_726 { repeat_n_321[id_725] };
                                                                                    int32_t id_727 { 1L };
                                                                                    int32_t id_728 { int32_t(id_726 + id_727) };
                                                                                    Void id_729 { ((void)(repeat_n_321[id_724] = id_728), VOID) };
                                                                                    (void)id_729;
                                                                                    (void)id_729;
                                                                                  }
                                                                                } while (while_flag_669);
                                                                                (void)VOID;
                                                                              }
                                                                              (void)VOID;
                                                                              uint8_t id_730 { 0 };
                                                                              Size id_731 { sz_ref_320[id_730] };
                                                                              let_res_666 = id_731;
                                                                            }
                                                                            choose_res_636 = let_res_666;
                                                                          } else {
                                                                            uint16_t id_732 { 34 };
                                                                            bool id_733 { bool(id_732 == label2_306) };
                                                                            Size choose_res_734;
                                                                            if (id_733) {
                                                                              Size id_735 { 2UL };
                                                                              Size id_736 { Size(sz_305 + id_735) };
                                                                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_737 { p_0->type };
                                                                              Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_738 { std::get<34>(id_737) };
                                                                              uint32_t id_739 { id_738.size() };
                                                                              Vec<1, uint32_t> id_740 {  id_739  };
                                                                              Size let_res_741;
                                                                              {
                                                                                Vec<1, uint32_t> n_ref_309 { id_740 };
                                                                                uint32_t id_742 { 1U };
                                                                                Vec<1, uint32_t> id_743 {  id_742  };
                                                                                Size let_res_744;
                                                                                {
                                                                                  Vec<1, uint32_t> lebsz_ref_310 { id_743 };
                                                                                  bool while_flag_745 { true };
                                                                                  do {
                                                                                    uint8_t id_746 { 0 };
                                                                                    uint32_t id_747 { n_ref_309[id_746] };
                                                                                    uint8_t id_748 { 0 };
                                                                                    uint32_t id_749 { lebsz_ref_310[id_748] };
                                                                                    uint8_t id_750 { 7 };
                                                                                    uint32_t id_751 { uint32_t(id_749 << id_750) };
                                                                                    bool id_752 { bool(id_747 >= id_751) };
                                                                                    while_flag_745 = id_752;
                                                                                    if (while_flag_745) {
                                                                                      uint8_t id_753 { 0 };
                                                                                      uint8_t id_754 { 0 };
                                                                                      uint32_t id_755 { lebsz_ref_310[id_754] };
                                                                                      uint32_t id_756 { 1U };
                                                                                      uint32_t id_757 { uint32_t(id_755 + id_756) };
                                                                                      Void id_758 { ((void)(lebsz_ref_310[id_753] = id_757), VOID) };
                                                                                      (void)id_758;
                                                                                    }
                                                                                  } while (while_flag_745);
                                                                                  (void)VOID;
                                                                                  uint8_t id_759 { 0 };
                                                                                  uint32_t id_760 { lebsz_ref_310[id_759] };
                                                                                  Size id_761 { Size(id_760) };
                                                                                  let_res_744 = id_761;
                                                                                }
                                                                                let_res_741 = let_res_744;
                                                                              }
                                                                              Size id_762 { Size(id_736 + let_res_741) };
                                                                              Vec<1, Size> id_763 {  id_762  };
                                                                              Size let_res_764;
                                                                              {
                                                                                Vec<1, Size> sz_ref_311 { id_763 };
                                                                                int32_t id_765 { 0L };
                                                                                Vec<1, int32_t> id_766 {  id_765  };
                                                                                {
                                                                                  Vec<1, int32_t> repeat_n_312 { id_766 };
                                                                                  bool while_flag_767 { true };
                                                                                  do {
                                                                                    ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_768 { p_0->type };
                                                                                    Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_769 { std::get<34>(id_768) };
                                                                                    uint32_t id_770 { id_769.size() };
                                                                                    int32_t id_771 { int32_t(id_770) };
                                                                                    uint8_t id_772 { 0 };
                                                                                    int32_t id_773 { repeat_n_312[id_772] };
                                                                                    bool id_774 { bool(id_771 > id_773) };
                                                                                    while_flag_767 = id_774;
                                                                                    if (while_flag_767) {
                                                                                      uint8_t id_775 { 0 };
                                                                                      uint8_t id_776 { 0 };
                                                                                      Size id_777 { sz_ref_311[id_776] };
                                                                                      Size let_res_778;
                                                                                      {
                                                                                        Size sz_313 { id_777 };
                                                                                        uint8_t id_779 { 0 };
                                                                                        int32_t id_780 { repeat_n_312[id_779] };
                                                                                        ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_781 { p_0->type };
                                                                                        Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_782 { std::get<34>(id_781) };
                                                                                        ::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c id_783 { id_782[id_780] };
                                                                                        std::string id_784 { std::get<0>(id_783) };
                                                                                        uint32_t id_785 { (uint32_t)id_784.size() };
                                                                                        Size let_res_786;
                                                                                        {
                                                                                          uint32_t wlen_314 { id_785 };
                                                                                          Vec<1, uint32_t> id_787 {  wlen_314  };
                                                                                          Size let_res_788;
                                                                                          {
                                                                                            Vec<1, uint32_t> n_ref_315 { id_787 };
                                                                                            uint32_t id_789 { 1U };
                                                                                            Vec<1, uint32_t> id_790 {  id_789  };
                                                                                            Size let_res_791;
                                                                                            {
                                                                                              Vec<1, uint32_t> lebsz_ref_316 { id_790 };
                                                                                              bool while_flag_792 { true };
                                                                                              do {
                                                                                                uint8_t id_793 { 0 };
                                                                                                uint32_t id_794 { n_ref_315[id_793] };
                                                                                                uint8_t id_795 { 0 };
                                                                                                uint32_t id_796 { lebsz_ref_316[id_795] };
                                                                                                uint8_t id_797 { 7 };
                                                                                                uint32_t id_798 { uint32_t(id_796 << id_797) };
                                                                                                bool id_799 { bool(id_794 >= id_798) };
                                                                                                while_flag_792 = id_799;
                                                                                                if (while_flag_792) {
                                                                                                  uint8_t id_800 { 0 };
                                                                                                  uint8_t id_801 { 0 };
                                                                                                  uint32_t id_802 { lebsz_ref_316[id_801] };
                                                                                                  uint32_t id_803 { 1U };
                                                                                                  uint32_t id_804 { uint32_t(id_802 + id_803) };
                                                                                                  Void id_805 { ((void)(lebsz_ref_316[id_800] = id_804), VOID) };
                                                                                                  (void)id_805;
                                                                                                }
                                                                                              } while (while_flag_792);
                                                                                              (void)VOID;
                                                                                              uint8_t id_806 { 0 };
                                                                                              uint32_t id_807 { lebsz_ref_316[id_806] };
                                                                                              Size id_808 { Size(id_807) };
                                                                                              let_res_791 = id_808;
                                                                                            }
                                                                                            let_res_788 = let_res_791;
                                                                                          }
                                                                                          Size id_809 { Size(wlen_314) };
                                                                                          Size id_810 { Size(let_res_788 + id_809) };
                                                                                          let_res_786 = id_810;
                                                                                        }
                                                                                        Size id_811 { Size(sz_313 + let_res_786) };
                                                                                        let_res_778 = id_811;
                                                                                      }
                                                                                      Size let_res_812;
                                                                                      {
                                                                                        Size sz_317 { let_res_778 };
                                                                                        uint8_t id_813 { 0 };
                                                                                        int32_t id_814 { repeat_n_312[id_813] };
                                                                                        ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_815 { p_0->type };
                                                                                        Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_816 { std::get<34>(id_815) };
                                                                                        ::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c id_817 { id_816[id_814] };
                                                                                        t* id_818 { std::get<1>(id_817) };
                                                                                        Size id_819 { fun395(id_818) };
                                                                                        Size id_820 { Size(sz_317 + id_819) };
                                                                                        let_res_812 = id_820;
                                                                                      }
                                                                                      Void id_821 { ((void)(sz_ref_311[id_775] = let_res_812), VOID) };
                                                                                      (void)id_821;
                                                                                      uint8_t id_822 { 0 };
                                                                                      uint8_t id_823 { 0 };
                                                                                      int32_t id_824 { repeat_n_312[id_823] };
                                                                                      int32_t id_825 { 1L };
                                                                                      int32_t id_826 { int32_t(id_824 + id_825) };
                                                                                      Void id_827 { ((void)(repeat_n_312[id_822] = id_826), VOID) };
                                                                                      (void)id_827;
                                                                                      (void)id_827;
                                                                                    }
                                                                                  } while (while_flag_767);
                                                                                  (void)VOID;
                                                                                }
                                                                                (void)VOID;
                                                                                uint8_t id_828 { 0 };
                                                                                Size id_829 { sz_ref_311[id_828] };
                                                                                let_res_764 = id_829;
                                                                              }
                                                                              choose_res_734 = let_res_764;
                                                                            } else {
                                                                              uint16_t id_830 { 35 };
                                                                              bool id_831 { bool(label2_306 == id_830) };
                                                                              Void id_832 { ((void)(assert(id_831)), VOID) };
                                                                              (void)id_832;
                                                                              Size id_833 { 2UL };
                                                                              Size id_834 { Size(sz_305 + id_833) };
                                                                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_835 { p_0->type };
                                                                              ::dessser::gen::raql_type::t7411897bdb6c9b6e00a01b4eb6506ccf id_836 { std::get<35>(id_835) };
                                                                              t* id_837 { std::get<0>(id_836) };
                                                                              Size id_838 { fun395(id_837) };
                                                                              Size id_839 { Size(id_834 + id_838) };
                                                                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_840 { p_0->type };
                                                                              ::dessser::gen::raql_type::t7411897bdb6c9b6e00a01b4eb6506ccf id_841 { std::get<35>(id_840) };
                                                                              t* id_842 { std::get<1>(id_841) };
                                                                              Size id_843 { fun395(id_842) };
                                                                              Size id_844 { Size(id_839 + id_843) };
                                                                              choose_res_734 = id_844;
                                                                            }
                                                                            choose_res_636 = choose_res_734;
                                                                          }
                                                                          choose_res_627 = choose_res_636;
                                                                        }
                                                                        choose_res_615 = choose_res_627;
                                                                      }
                                                                      choose_res_553 = choose_res_615;
                                                                    }
                                                                    choose_res_548 = choose_res_553;
                                                                  }
                                                                  choose_res_543 = choose_res_548;
                                                                }
                                                                choose_res_538 = choose_res_543;
                                                              }
                                                              choose_res_533 = choose_res_538;
                                                            }
                                                            choose_res_528 = choose_res_533;
                                                          }
                                                          choose_res_523 = choose_res_528;
                                                        }
                                                        choose_res_518 = choose_res_523;
                                                      }
                                                      choose_res_513 = choose_res_518;
                                                    }
                                                    choose_res_508 = choose_res_513;
                                                  }
                                                  choose_res_503 = choose_res_508;
                                                }
                                                choose_res_498 = choose_res_503;
                                              }
                                              choose_res_493 = choose_res_498;
                                            }
                                            choose_res_488 = choose_res_493;
                                          }
                                          choose_res_483 = choose_res_488;
                                        }
                                        choose_res_478 = choose_res_483;
                                      }
                                      choose_res_473 = choose_res_478;
                                    }
                                    choose_res_468 = choose_res_473;
                                  }
                                  choose_res_463 = choose_res_468;
                                }
                                choose_res_458 = choose_res_463;
                              }
                              choose_res_453 = choose_res_458;
                            }
                            choose_res_448 = choose_res_453;
                          }
                          choose_res_443 = choose_res_448;
                        }
                        choose_res_438 = choose_res_443;
                      }
                      choose_res_433 = choose_res_438;
                    }
                    choose_res_428 = choose_res_433;
                  }
                  choose_res_423 = choose_res_428;
                }
                choose_res_418 = choose_res_423;
              }
              choose_res_413 = choose_res_418;
            }
            choose_res_408 = choose_res_413;
          }
          choose_res_403 = choose_res_408;
        }
        let_res_400 = choose_res_403;
      }
      let_res_397 = let_res_400;
    }
    Size id_845 { 1UL };
    Size id_846 { Size(let_res_397 + id_845) };
    return id_846;
  }
   };
  return fun395;
}
std::function<Size(::dessser::gen::raql_type::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_293"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (make-tup
                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 0
                  (nop)) (identifier "dsum1_snd_64"))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (make-tup
                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 1
                    (nop)) (identifier "dsum1_snd_64"))
                (if (eq (u16 2) (identifier "dsum1_fst_63"))
                  (make-tup
                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 2
                      (nop)) (identifier "dsum1_snd_64"))
                  (if (eq (u16 3) (identifier "dsum1_fst_63"))
                    (make-tup
                      (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 3
                        (nop)) (identifier "dsum1_snd_64"))
                    (if (eq (u16 4) (identifier "dsum1_fst_63"))
                      (make-tup
                        (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 4
                          (nop)) (identifier "dsum1_snd_64"))
                      (if (eq (u16 5) (identifier "dsum1_fst_63"))
                        (make-tup
                          (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 5
                            (nop)) (identifier "dsum1_snd_64"))
                        (if (eq (u16 6) (identifier "dsum1_fst_63"))
                          (make-tup
                            (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 6
                              (nop)) (identifier "dsum1_snd_64"))
                          (if (eq (u16 7) (identifier "dsum1_fst_63"))
                            (make-tup
                              (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 7
                                (nop)) (identifier "dsum1_snd_64"))
                            (if (eq (u16 8) (identifier "dsum1_fst_63"))
                              (make-tup
                                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 8
                                  (nop)) (identifier "dsum1_snd_64"))
                              (if (eq (u16 9) (identifier "dsum1_fst_63"))
                                (make-tup
                                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 9
                                    (nop)) (identifier "dsum1_snd_64"))
                                (if (eq (u16 10) (identifier "dsum1_fst_63"))
                                  (make-tup
                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 10
                                      (nop)) (identifier "dsum1_snd_64"))
                                  (if (eq (u16 11) (identifier "dsum1_fst_63"))
                                    (make-tup
                                      (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 11
                                        (nop)) (identifier "dsum1_snd_64"))
                                    (if (eq (u16 12) (identifier "dsum1_fst_63"))
                                      (make-tup
                                        (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 12
                                          (nop)) (identifier "dsum1_snd_64"))
                                      (if (eq (u16 13) (identifier "dsum1_fst_63"))
                                        (make-tup
                                          (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 13
                                            (nop)) (identifier "dsum1_snd_64"))
                                        (if (eq (u16 14) (identifier "dsum1_fst_63"))
                                          (make-tup
                                            (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 14
                                              (nop)) (identifier "dsum1_snd_64"))
                                          (if (eq (u16 15) (identifier "dsum1_fst_63"))
                                            (make-tup
                                              (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 15
                                                (nop)) (identifier "dsum1_snd_64"))
                                            (if (eq (u16 16) (identifier "dsum1_fst_63"))
                                              (make-tup
                                                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 16
                                                  (nop)) (identifier "dsum1_snd_64"))
                                              (if (eq (u16 17) (identifier "dsum1_fst_63"))
                                                (make-tup
                                                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 17
                                                    (nop)) (identifier "dsum1_snd_64"))
                                                (if (eq (u16 18) (identifier "dsum1_fst_63"))
                                                  (make-tup
                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 18
                                                      (nop)) (identifier "dsum1_snd_64"))
                                                  (if (eq (u16 19) (identifier "dsum1_fst_63"))
                                                    (make-tup
                                                      (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 19
                                                        (nop)) (identifier "dsum1_snd_64"))
                                                    (if (eq (u16 20) (identifier "dsum1_fst_63"))
                                                      (make-tup
                                                        (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 20
                                                          (nop)) (identifier "dsum1_snd_64"))
                                                      (if (eq (u16 21) (identifier "dsum1_fst_63"))
                                                        (make-tup
                                                          (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 21
                                                            (nop)) (identifier "dsum1_snd_64"))
                                                        (if (eq (u16 22) (identifier "dsum1_fst_63"))
                                                          (make-tup
                                                            (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 22
                                                              (nop)) 
                                                            (identifier "dsum1_snd_64"))
                                                          (if (eq (u16 23) (identifier "dsum1_fst_63"))
                                                            (make-tup
                                                              (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 23
                                                                (nop)) 
                                                              (identifier "dsum1_snd_64"))
                                                            (if (eq (u16 24) (identifier "dsum1_fst_63"))
                                                              (make-tup
                                                                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 24
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_64"))
                                                              (if (eq (u16 25) (identifier "dsum1_fst_63"))
                                                                (make-tup
                                                                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 25
                                                                    (nop)) 
                                                                  (identifier "dsum1_snd_64"))
                                                                (if (eq (u16 26) (identifier "dsum1_fst_63"))
                                                                  (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 26
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_64"))
                                                                  (if 
                                                                    (eq (u16 27) (identifier "dsum1_fst_63"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 27
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_64"))
                                                                    (if 
                                                                    (eq (u16 28) (identifier "dsum1_fst_63"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 28
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_64"))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "dsum1_fst_63"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 29
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_64"))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "dsum1_fst_63"))
                                                                    (let-pair "dlist4_fst_198" "dlist4_snd_199"
                                                                    (let "dlist1_186"
                                                                    (let "leb_ref_177" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_178" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_179" 
                                                                    (make-vec (identifier "dsum1_snd_64"))
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
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_188")))
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
                                                                    (let-pair "dlist3_fst_195" "dlist3_snd_196" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_193"))
                                                                    (make-tup (cons (identifier "dlist3_fst_195") (identifier "dlist2_fst_192")) (identifier "dlist3_snd_196"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_190") (add (unsafe-nth (u8 0) (identifier "repeat_n_190")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_189"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 30
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_198"))) 
                                                                    (identifier "dlist4_snd_199")))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "dsum1_fst_63"))
                                                                    (let-pair "du32_fst_166" "du32_snd_167" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_64"))
                                                                    (let-pair "dtup_fst_172" "dtup_snd_173" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "du32_snd_167"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 31
                                                                    (make-tup (identifier "du32_fst_166") (identifier "dtup_fst_172"))) 
                                                                    (identifier "dtup_snd_173"))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "dsum1_fst_63"))
                                                                    (let-pair "dsum2_fst_163" "dsum2_snd_164" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dsum1_snd_64"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 32
                                                                    (identifier "dsum2_fst_163")) 
                                                                    (identifier "dsum2_snd_164")))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "dsum1_fst_63"))
                                                                    (let-pair "dlist4_fst_157" "dlist4_snd_158"
                                                                    (let "dlist1_127"
                                                                    (let "leb_ref_118" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_119" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_120" 
                                                                    (make-vec (identifier "dsum1_snd_64"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_121" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_120")))
                                                                    (let-pair "leb128_fst_122" "leb128_snd_123" 
                                                                    (identifier "leb128_121")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_120") (identifier "leb128_snd_123"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_118")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_122") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_119")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_118")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_119") (add (unsafe-nth (u8 0) (identifier "shft_ref_119")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_122") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_118")) (unsafe-nth (u8 0) (identifier "p_ref_120")))))))
                                                                    (let-pair "dlist1_fst_128" "dlist1_snd_129" 
                                                                    (identifier "dlist1_127")
                                                                    (let "inits_src_ref_130" 
                                                                    (make-vec (make-tup (end-of-list "(STRING; THIS)") (identifier "dlist1_snd_129")))
                                                                    (seq
                                                                    (let "repeat_n_131" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_128")) (unsafe-nth (u8 0) (identifier "repeat_n_131")))
                                                                    (seq
                                                                    (let "dlist2_132" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_130"))
                                                                    (let-pair "dlist2_fst_133" "dlist2_snd_134" 
                                                                    (identifier "dlist2_132")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_130")
                                                                    (let "dstring1_141"
                                                                    (let "leb_ref_135" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_136" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_137" 
                                                                    (make-vec (identifier "dlist2_snd_134"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_138" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_137")))
                                                                    (let-pair "leb128_fst_139" "leb128_snd_140" 
                                                                    (identifier "leb128_138")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_137") (identifier "leb128_snd_140"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_135")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_139") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_136")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_135")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_136") (add (unsafe-nth (u8 0) (identifier "shft_ref_136")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_139") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_135"))) (unsafe-nth (u8 0) (identifier "p_ref_137")))))))
                                                                    (let-pair "dstring1_fst_142" "dstring1_snd_143" 
                                                                    (identifier "dstring1_141")
                                                                    (let-pair "dstring2_fst_145" "dstring2_snd_146" 
                                                                    (read-bytes (identifier "dstring1_snd_143") (identifier "dstring1_fst_142"))
                                                                    (let-pair "dtup_fst_151" "dtup_snd_152" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dstring2_snd_146"))
                                                                    (make-tup 
                                                                    (cons (make-tup (string-of-bytes (identifier "dstring2_fst_145")) (identifier "dtup_fst_151")) (identifier "dlist2_fst_133")) 
                                                                    (identifier "dtup_snd_152"))))))))) 
                                                                    (set-vec (u8 0) (identifier "repeat_n_131") (add (unsafe-nth (u8 0) (identifier "repeat_n_131")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_130"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 33
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_157"))) 
                                                                    (identifier "dlist4_snd_158")))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "dsum1_fst_63"))
                                                                    (let-pair "dlist4_fst_113" "dlist4_snd_114"
                                                                    (let "dlist1_83"
                                                                    (let "leb_ref_74" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_75" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_76" 
                                                                    (make-vec (identifier "dsum1_snd_64"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_77" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_76")))
                                                                    (let-pair "leb128_fst_78" "leb128_snd_79" 
                                                                    (identifier "leb128_77")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_76") (identifier "leb128_snd_79"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_74")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_78") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_75")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_74")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_75") (add (unsafe-nth (u8 0) (identifier "shft_ref_75")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_78") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_74")) (unsafe-nth (u8 0) (identifier "p_ref_76")))))))
                                                                    (let-pair "dlist1_fst_84" "dlist1_snd_85" 
                                                                    (identifier "dlist1_83")
                                                                    (let "inits_src_ref_86" 
                                                                    (make-vec (make-tup (end-of-list "(STRING; THIS)") (identifier "dlist1_snd_85")))
                                                                    (seq
                                                                    (let "repeat_n_87" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_84")) (unsafe-nth (u8 0) (identifier "repeat_n_87")))
                                                                    (seq
                                                                    (let "dlist2_88" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_86"))
                                                                    (let-pair "dlist2_fst_89" "dlist2_snd_90" 
                                                                    (identifier "dlist2_88")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_86")
                                                                    (let "dstring1_97"
                                                                    (let "leb_ref_91" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_92" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_93" 
                                                                    (make-vec (identifier "dlist2_snd_90"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_94" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_93")))
                                                                    (let-pair "leb128_fst_95" "leb128_snd_96" 
                                                                    (identifier "leb128_94")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_93") (identifier "leb128_snd_96"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_91")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_95") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_92")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_91")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_92") (add (unsafe-nth (u8 0) (identifier "shft_ref_92")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_95") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_91"))) (unsafe-nth (u8 0) (identifier "p_ref_93")))))))
                                                                    (let-pair "dstring1_fst_98" "dstring1_snd_99" 
                                                                    (identifier "dstring1_97")
                                                                    (let-pair "dstring2_fst_101" "dstring2_snd_102" 
                                                                    (read-bytes (identifier "dstring1_snd_99") (identifier "dstring1_fst_98"))
                                                                    (let-pair "dtup_fst_107" "dtup_snd_108" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dstring2_snd_102"))
                                                                    (make-tup 
                                                                    (cons (make-tup (string-of-bytes (identifier "dstring2_fst_101")) (identifier "dtup_fst_107")) (identifier "dlist2_fst_89")) 
                                                                    (identifier "dtup_snd_108"))))))))) 
                                                                    (set-vec (u8 0) (identifier "repeat_n_87") (add (unsafe-nth (u8 0) (identifier "repeat_n_87")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_86"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 34
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_113"))) 
                                                                    (identifier "dlist4_snd_114")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_63") (u16 35)))
                                                                    (let-pair "dtup_fst_66" "dtup_snd_67" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dsum1_snd_64"))
                                                                    (let-pair "dtup_fst_69" "dtup_snd_70" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_67"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 35
                                                                    (make-tup (identifier "dtup_fst_66") (identifier "dtup_fst_69"))) 
                                                                    (identifier "dtup_snd_70"))))))))))))))))))))))))))))))))))))))))))
        (let-pair "drec_fst_294" "drec_snd_295" (identifier "drec_293")
          (let-pair "dbool_fst_297" "dbool_snd_298" (read-u8 (identifier "drec_snd_295"))
            (make-tup (make-rec (string "nullable") (not (eq (identifier "dbool_fst_297") (u8 0))) (string "type") (identifier "drec_fst_294")) (identifier "dbool_snd_298"))))))
 */
static std::function<::dessser::gen::raql_type::tfafddb6af18e2fa33b782eb359ee7c77(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_type::tfafddb6af18e2fa33b782eb359ee7c77(Pointer)> fun847 { [&fun847](Pointer p_0) {
    ::dessser::gen::raql_type::t22a32080ad88ab548b80077a17b7dd46 id_848 { p_0.readU16Le() };
    ::dessser::gen::raql_type::t22a32080ad88ab548b80077a17b7dd46 letpair_res_849;
    {
      auto du16_fst_57 { std::get<0>(id_848) };
      auto du16_snd_58 { std::get<1>(id_848) };
      ::dessser::gen::raql_type::t22a32080ad88ab548b80077a17b7dd46 id_850 { du16_fst_57, du16_snd_58 };
      letpair_res_849 = id_850;
    }
    ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a let_res_851;
    {
      ::dessser::gen::raql_type::t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_849 };
      ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a letpair_res_852;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_853 { 0 };
        bool id_854 { bool(id_853 == dsum1_fst_63) };
        ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_855;
        if (id_854) {
          (void)VOID;
          ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_856 { std::in_place_index<0>, VOID };
          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_857 { id_856, dsum1_snd_64 };
          choose_res_855 = id_857;
        } else {
          uint16_t id_858 { 1 };
          bool id_859 { bool(id_858 == dsum1_fst_63) };
          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_860;
          if (id_859) {
            (void)VOID;
            ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_861 { std::in_place_index<1>, VOID };
            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_862 { id_861, dsum1_snd_64 };
            choose_res_860 = id_862;
          } else {
            uint16_t id_863 { 2 };
            bool id_864 { bool(id_863 == dsum1_fst_63) };
            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_865;
            if (id_864) {
              (void)VOID;
              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_866 { std::in_place_index<2>, VOID };
              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_867 { id_866, dsum1_snd_64 };
              choose_res_865 = id_867;
            } else {
              uint16_t id_868 { 3 };
              bool id_869 { bool(id_868 == dsum1_fst_63) };
              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_870;
              if (id_869) {
                (void)VOID;
                ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_871 { std::in_place_index<3>, VOID };
                ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_872 { id_871, dsum1_snd_64 };
                choose_res_870 = id_872;
              } else {
                uint16_t id_873 { 4 };
                bool id_874 { bool(id_873 == dsum1_fst_63) };
                ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_875;
                if (id_874) {
                  (void)VOID;
                  ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_876 { std::in_place_index<4>, VOID };
                  ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_877 { id_876, dsum1_snd_64 };
                  choose_res_875 = id_877;
                } else {
                  uint16_t id_878 { 5 };
                  bool id_879 { bool(id_878 == dsum1_fst_63) };
                  ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_880;
                  if (id_879) {
                    (void)VOID;
                    ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_881 { std::in_place_index<5>, VOID };
                    ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_882 { id_881, dsum1_snd_64 };
                    choose_res_880 = id_882;
                  } else {
                    uint16_t id_883 { 6 };
                    bool id_884 { bool(id_883 == dsum1_fst_63) };
                    ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_885;
                    if (id_884) {
                      (void)VOID;
                      ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_886 { std::in_place_index<6>, VOID };
                      ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_887 { id_886, dsum1_snd_64 };
                      choose_res_885 = id_887;
                    } else {
                      uint16_t id_888 { 7 };
                      bool id_889 { bool(id_888 == dsum1_fst_63) };
                      ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_890;
                      if (id_889) {
                        (void)VOID;
                        ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_891 { std::in_place_index<7>, VOID };
                        ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_892 { id_891, dsum1_snd_64 };
                        choose_res_890 = id_892;
                      } else {
                        uint16_t id_893 { 8 };
                        bool id_894 { bool(id_893 == dsum1_fst_63) };
                        ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_895;
                        if (id_894) {
                          (void)VOID;
                          ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_896 { std::in_place_index<8>, VOID };
                          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_897 { id_896, dsum1_snd_64 };
                          choose_res_895 = id_897;
                        } else {
                          uint16_t id_898 { 9 };
                          bool id_899 { bool(id_898 == dsum1_fst_63) };
                          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_900;
                          if (id_899) {
                            (void)VOID;
                            ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_901 { std::in_place_index<9>, VOID };
                            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_902 { id_901, dsum1_snd_64 };
                            choose_res_900 = id_902;
                          } else {
                            uint16_t id_903 { 10 };
                            bool id_904 { bool(id_903 == dsum1_fst_63) };
                            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_905;
                            if (id_904) {
                              (void)VOID;
                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_906 { std::in_place_index<10>, VOID };
                              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_907 { id_906, dsum1_snd_64 };
                              choose_res_905 = id_907;
                            } else {
                              uint16_t id_908 { 11 };
                              bool id_909 { bool(id_908 == dsum1_fst_63) };
                              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_910;
                              if (id_909) {
                                (void)VOID;
                                ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_911 { std::in_place_index<11>, VOID };
                                ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_912 { id_911, dsum1_snd_64 };
                                choose_res_910 = id_912;
                              } else {
                                uint16_t id_913 { 12 };
                                bool id_914 { bool(id_913 == dsum1_fst_63) };
                                ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_915;
                                if (id_914) {
                                  (void)VOID;
                                  ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_916 { std::in_place_index<12>, VOID };
                                  ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_917 { id_916, dsum1_snd_64 };
                                  choose_res_915 = id_917;
                                } else {
                                  uint16_t id_918 { 13 };
                                  bool id_919 { bool(id_918 == dsum1_fst_63) };
                                  ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_920;
                                  if (id_919) {
                                    (void)VOID;
                                    ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_921 { std::in_place_index<13>, VOID };
                                    ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_922 { id_921, dsum1_snd_64 };
                                    choose_res_920 = id_922;
                                  } else {
                                    uint16_t id_923 { 14 };
                                    bool id_924 { bool(id_923 == dsum1_fst_63) };
                                    ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_925;
                                    if (id_924) {
                                      (void)VOID;
                                      ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_926 { std::in_place_index<14>, VOID };
                                      ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_927 { id_926, dsum1_snd_64 };
                                      choose_res_925 = id_927;
                                    } else {
                                      uint16_t id_928 { 15 };
                                      bool id_929 { bool(id_928 == dsum1_fst_63) };
                                      ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_930;
                                      if (id_929) {
                                        (void)VOID;
                                        ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_931 { std::in_place_index<15>, VOID };
                                        ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_932 { id_931, dsum1_snd_64 };
                                        choose_res_930 = id_932;
                                      } else {
                                        uint16_t id_933 { 16 };
                                        bool id_934 { bool(id_933 == dsum1_fst_63) };
                                        ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_935;
                                        if (id_934) {
                                          (void)VOID;
                                          ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_936 { std::in_place_index<16>, VOID };
                                          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_937 { id_936, dsum1_snd_64 };
                                          choose_res_935 = id_937;
                                        } else {
                                          uint16_t id_938 { 17 };
                                          bool id_939 { bool(id_938 == dsum1_fst_63) };
                                          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_940;
                                          if (id_939) {
                                            (void)VOID;
                                            ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_941 { std::in_place_index<17>, VOID };
                                            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_942 { id_941, dsum1_snd_64 };
                                            choose_res_940 = id_942;
                                          } else {
                                            uint16_t id_943 { 18 };
                                            bool id_944 { bool(id_943 == dsum1_fst_63) };
                                            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_945;
                                            if (id_944) {
                                              (void)VOID;
                                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_946 { std::in_place_index<18>, VOID };
                                              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_947 { id_946, dsum1_snd_64 };
                                              choose_res_945 = id_947;
                                            } else {
                                              uint16_t id_948 { 19 };
                                              bool id_949 { bool(id_948 == dsum1_fst_63) };
                                              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_950;
                                              if (id_949) {
                                                (void)VOID;
                                                ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_951 { std::in_place_index<19>, VOID };
                                                ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_952 { id_951, dsum1_snd_64 };
                                                choose_res_950 = id_952;
                                              } else {
                                                uint16_t id_953 { 20 };
                                                bool id_954 { bool(id_953 == dsum1_fst_63) };
                                                ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_955;
                                                if (id_954) {
                                                  (void)VOID;
                                                  ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_956 { std::in_place_index<20>, VOID };
                                                  ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_957 { id_956, dsum1_snd_64 };
                                                  choose_res_955 = id_957;
                                                } else {
                                                  uint16_t id_958 { 21 };
                                                  bool id_959 { bool(id_958 == dsum1_fst_63) };
                                                  ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_960;
                                                  if (id_959) {
                                                    (void)VOID;
                                                    ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_961 { std::in_place_index<21>, VOID };
                                                    ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_962 { id_961, dsum1_snd_64 };
                                                    choose_res_960 = id_962;
                                                  } else {
                                                    uint16_t id_963 { 22 };
                                                    bool id_964 { bool(id_963 == dsum1_fst_63) };
                                                    ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_965;
                                                    if (id_964) {
                                                      (void)VOID;
                                                      ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_966 { std::in_place_index<22>, VOID };
                                                      ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_967 { id_966, dsum1_snd_64 };
                                                      choose_res_965 = id_967;
                                                    } else {
                                                      uint16_t id_968 { 23 };
                                                      bool id_969 { bool(id_968 == dsum1_fst_63) };
                                                      ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_970;
                                                      if (id_969) {
                                                        (void)VOID;
                                                        ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_971 { std::in_place_index<23>, VOID };
                                                        ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_972 { id_971, dsum1_snd_64 };
                                                        choose_res_970 = id_972;
                                                      } else {
                                                        uint16_t id_973 { 24 };
                                                        bool id_974 { bool(id_973 == dsum1_fst_63) };
                                                        ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_975;
                                                        if (id_974) {
                                                          (void)VOID;
                                                          ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_976 { std::in_place_index<24>, VOID };
                                                          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_977 { id_976, dsum1_snd_64 };
                                                          choose_res_975 = id_977;
                                                        } else {
                                                          uint16_t id_978 { 25 };
                                                          bool id_979 { bool(id_978 == dsum1_fst_63) };
                                                          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_980;
                                                          if (id_979) {
                                                            (void)VOID;
                                                            ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_981 { std::in_place_index<25>, VOID };
                                                            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_982 { id_981, dsum1_snd_64 };
                                                            choose_res_980 = id_982;
                                                          } else {
                                                            uint16_t id_983 { 26 };
                                                            bool id_984 { bool(id_983 == dsum1_fst_63) };
                                                            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_985;
                                                            if (id_984) {
                                                              (void)VOID;
                                                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_986 { std::in_place_index<26>, VOID };
                                                              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_987 { id_986, dsum1_snd_64 };
                                                              choose_res_985 = id_987;
                                                            } else {
                                                              uint16_t id_988 { 27 };
                                                              bool id_989 { bool(id_988 == dsum1_fst_63) };
                                                              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_990;
                                                              if (id_989) {
                                                                (void)VOID;
                                                                ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_991 { std::in_place_index<27>, VOID };
                                                                ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_992 { id_991, dsum1_snd_64 };
                                                                choose_res_990 = id_992;
                                                              } else {
                                                                uint16_t id_993 { 28 };
                                                                bool id_994 { bool(id_993 == dsum1_fst_63) };
                                                                ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_995;
                                                                if (id_994) {
                                                                  (void)VOID;
                                                                  ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_996 { std::in_place_index<28>, VOID };
                                                                  ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_997 { id_996, dsum1_snd_64 };
                                                                  choose_res_995 = id_997;
                                                                } else {
                                                                  uint16_t id_998 { 29 };
                                                                  bool id_999 { bool(id_998 == dsum1_fst_63) };
                                                                  ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_1000;
                                                                  if (id_999) {
                                                                    (void)VOID;
                                                                    ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_1001 { std::in_place_index<29>, VOID };
                                                                    ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_1002 { id_1001, dsum1_snd_64 };
                                                                    choose_res_1000 = id_1002;
                                                                  } else {
                                                                    uint16_t id_1003 { 30 };
                                                                    bool id_1004 { bool(id_1003 == dsum1_fst_63) };
                                                                    ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_1005;
                                                                    if (id_1004) {
                                                                      uint32_t id_1006 { 0U };
                                                                      Vec<1, uint32_t> id_1007 {  id_1006  };
                                                                      ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 let_res_1008;
                                                                      {
                                                                        Vec<1, uint32_t> leb_ref_177 { id_1007 };
                                                                        uint8_t id_1009 { 0 };
                                                                        Vec<1, uint8_t> id_1010 {  id_1009  };
                                                                        ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 let_res_1011;
                                                                        {
                                                                          Vec<1, uint8_t> shft_ref_178 { id_1010 };
                                                                          Vec<1, Pointer> id_1012 {  dsum1_snd_64  };
                                                                          ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 let_res_1013;
                                                                          {
                                                                            Vec<1, Pointer> p_ref_179 { id_1012 };
                                                                            bool while_flag_1014 { true };
                                                                            do {
                                                                              uint8_t id_1015 { 0 };
                                                                              Pointer id_1016 { p_ref_179[id_1015] };
                                                                              ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 id_1017 { id_1016.readU8() };
                                                                              bool let_res_1018;
                                                                              {
                                                                                ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 leb128_180 { id_1017 };
                                                                                bool letpair_res_1019;
                                                                                {
                                                                                  auto leb128_fst_181 { std::get<0>(leb128_180) };
                                                                                  auto leb128_snd_182 { std::get<1>(leb128_180) };
                                                                                  uint8_t id_1020 { 0 };
                                                                                  Void id_1021 { ((void)(p_ref_179[id_1020] = leb128_snd_182), VOID) };
                                                                                  (void)id_1021;
                                                                                  uint8_t id_1022 { 0 };
                                                                                  uint8_t id_1023 { 127 };
                                                                                  uint8_t id_1024 { uint8_t(leb128_fst_181 & id_1023) };
                                                                                  uint32_t id_1025 { uint32_t(id_1024) };
                                                                                  uint8_t id_1026 { 0 };
                                                                                  uint8_t id_1027 { shft_ref_178[id_1026] };
                                                                                  uint32_t id_1028 { uint32_t(id_1025 << id_1027) };
                                                                                  uint8_t id_1029 { 0 };
                                                                                  uint32_t id_1030 { leb_ref_177[id_1029] };
                                                                                  uint32_t id_1031 { uint32_t(id_1028 | id_1030) };
                                                                                  Void id_1032 { ((void)(leb_ref_177[id_1022] = id_1031), VOID) };
                                                                                  (void)id_1032;
                                                                                  uint8_t id_1033 { 0 };
                                                                                  uint8_t id_1034 { 0 };
                                                                                  uint8_t id_1035 { shft_ref_178[id_1034] };
                                                                                  uint8_t id_1036 { 7 };
                                                                                  uint8_t id_1037 { uint8_t(id_1035 + id_1036) };
                                                                                  Void id_1038 { ((void)(shft_ref_178[id_1033] = id_1037), VOID) };
                                                                                  (void)id_1038;
                                                                                  uint8_t id_1039 { 128 };
                                                                                  bool id_1040 { bool(leb128_fst_181 >= id_1039) };
                                                                                  letpair_res_1019 = id_1040;
                                                                                }
                                                                                let_res_1018 = letpair_res_1019;
                                                                              }
                                                                              while_flag_1014 = let_res_1018;
                                                                              if (while_flag_1014) {
                                                                                (void)VOID;
                                                                              }
                                                                            } while (while_flag_1014);
                                                                            (void)VOID;
                                                                            uint8_t id_1041 { 0 };
                                                                            uint32_t id_1042 { leb_ref_177[id_1041] };
                                                                            uint8_t id_1043 { 0 };
                                                                            Pointer id_1044 { p_ref_179[id_1043] };
                                                                            ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 id_1045 { id_1042, id_1044 };
                                                                            let_res_1013 = id_1045;
                                                                          }
                                                                          let_res_1011 = let_res_1013;
                                                                        }
                                                                        let_res_1008 = let_res_1011;
                                                                      }
                                                                      ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548 let_res_1046;
                                                                      {
                                                                        ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 dlist1_186 { let_res_1008 };
                                                                        ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548 letpair_res_1047;
                                                                        {
                                                                          auto dlist1_fst_187 { std::get<0>(dlist1_186) };
                                                                          auto dlist1_snd_188 { std::get<1>(dlist1_186) };
                                                                          Lst<t*> endoflist_1048;
                                                                          ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1049 { endoflist_1048, dlist1_snd_188 };
                                                                          Vec<1, ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548> id_1050 {  id_1049  };
                                                                          ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548 let_res_1051;
                                                                          {
                                                                            Vec<1, ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548> inits_src_ref_189 { id_1050 };
                                                                            int32_t id_1052 { 0L };
                                                                            Vec<1, int32_t> id_1053 {  id_1052  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_190 { id_1053 };
                                                                              bool while_flag_1054 { true };
                                                                              do {
                                                                                int32_t id_1055 { int32_t(dlist1_fst_187) };
                                                                                uint8_t id_1056 { 0 };
                                                                                int32_t id_1057 { repeat_n_190[id_1056] };
                                                                                bool id_1058 { bool(id_1055 > id_1057) };
                                                                                while_flag_1054 = id_1058;
                                                                                if (while_flag_1054) {
                                                                                  uint8_t id_1059 { 0 };
                                                                                  ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1060 { inits_src_ref_189[id_1059] };
                                                                                  {
                                                                                    ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548 dlist2_191 { id_1060 };
                                                                                    {
                                                                                      auto dlist2_fst_192 { std::get<0>(dlist2_191) };
                                                                                      auto dlist2_snd_193 { std::get<1>(dlist2_191) };
                                                                                      uint8_t id_1061 { 0 };
                                                                                      ::dessser::gen::raql_type::t45217dce3db5a9a49037839afd0048e8 id_1062 { fun847(dlist2_snd_193) };
                                                                                      ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548 letpair_res_1063;
                                                                                      {
                                                                                        auto dlist3_fst_195 { std::get<0>(id_1062) };
                                                                                        auto dlist3_snd_196 { std::get<1>(id_1062) };
                                                                                        Lst<t*> id_1064 { dlist3_fst_195, dlist2_fst_192 };
                                                                                        ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1065 { id_1064, dlist3_snd_196 };
                                                                                        letpair_res_1063 = id_1065;
                                                                                      }
                                                                                      Void id_1066 { ((void)(inits_src_ref_189[id_1061] = letpair_res_1063), VOID) };
                                                                                      (void)id_1066;
                                                                                    }
                                                                                    (void)VOID;
                                                                                  }
                                                                                  (void)VOID;
                                                                                  uint8_t id_1067 { 0 };
                                                                                  uint8_t id_1068 { 0 };
                                                                                  int32_t id_1069 { repeat_n_190[id_1068] };
                                                                                  int32_t id_1070 { 1L };
                                                                                  int32_t id_1071 { int32_t(id_1069 + id_1070) };
                                                                                  Void id_1072 { ((void)(repeat_n_190[id_1067] = id_1071), VOID) };
                                                                                  (void)id_1072;
                                                                                  (void)id_1072;
                                                                                }
                                                                              } while (while_flag_1054);
                                                                              (void)VOID;
                                                                            }
                                                                            (void)VOID;
                                                                            uint8_t id_1073 { 0 };
                                                                            ::dessser::gen::raql_type::tff7ae6104a72ec7dfd0a80e3a42a8548 id_1074 { inits_src_ref_189[id_1073] };
                                                                            let_res_1051 = id_1074;
                                                                          }
                                                                          letpair_res_1047 = let_res_1051;
                                                                        }
                                                                        let_res_1046 = letpair_res_1047;
                                                                      }
                                                                      ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a letpair_res_1075;
                                                                      {
                                                                        auto dlist4_fst_198 { std::get<0>(let_res_1046) };
                                                                        auto dlist4_snd_199 { std::get<1>(let_res_1046) };
                                                                        Arr<t*> id_1076 { dlist4_fst_198.toListRev() };
                                                                        ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_1077 { std::in_place_index<30>, id_1076 };
                                                                        ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_1078 { id_1077, dlist4_snd_199 };
                                                                        letpair_res_1075 = id_1078;
                                                                      }
                                                                      choose_res_1005 = letpair_res_1075;
                                                                    } else {
                                                                      uint16_t id_1079 { 31 };
                                                                      bool id_1080 { bool(id_1079 == dsum1_fst_63) };
                                                                      ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_1081;
                                                                      if (id_1080) {
                                                                        ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 id_1082 { dsum1_snd_64.readU32Le() };
                                                                        ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a letpair_res_1083;
                                                                        {
                                                                          auto du32_fst_166 { std::get<0>(id_1082) };
                                                                          auto du32_snd_167 { std::get<1>(id_1082) };
                                                                          ::dessser::gen::raql_type::t45217dce3db5a9a49037839afd0048e8 id_1084 { fun847(du32_snd_167) };
                                                                          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a letpair_res_1085;
                                                                          {
                                                                            auto dtup_fst_172 { std::get<0>(id_1084) };
                                                                            auto dtup_snd_173 { std::get<1>(id_1084) };
                                                                            ::dessser::gen::raql_type::t9327d6336842c469509b67056a719df9 id_1086 { du32_fst_166, dtup_fst_172 };
                                                                            ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_1087 { std::in_place_index<31>, id_1086 };
                                                                            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_1088 { id_1087, dtup_snd_173 };
                                                                            letpair_res_1085 = id_1088;
                                                                          }
                                                                          letpair_res_1083 = letpair_res_1085;
                                                                        }
                                                                        choose_res_1081 = letpair_res_1083;
                                                                      } else {
                                                                        uint16_t id_1089 { 32 };
                                                                        bool id_1090 { bool(id_1089 == dsum1_fst_63) };
                                                                        ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_1091;
                                                                        if (id_1090) {
                                                                          ::dessser::gen::raql_type::t45217dce3db5a9a49037839afd0048e8 id_1092 { fun847(dsum1_snd_64) };
                                                                          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a letpair_res_1093;
                                                                          {
                                                                            auto dsum2_fst_163 { std::get<0>(id_1092) };
                                                                            auto dsum2_snd_164 { std::get<1>(id_1092) };
                                                                            ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_1094 { std::in_place_index<32>, dsum2_fst_163 };
                                                                            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_1095 { id_1094, dsum2_snd_164 };
                                                                            letpair_res_1093 = id_1095;
                                                                          }
                                                                          choose_res_1091 = letpair_res_1093;
                                                                        } else {
                                                                          uint16_t id_1096 { 33 };
                                                                          bool id_1097 { bool(id_1096 == dsum1_fst_63) };
                                                                          ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_1098;
                                                                          if (id_1097) {
                                                                            uint32_t id_1099 { 0U };
                                                                            Vec<1, uint32_t> id_1100 {  id_1099  };
                                                                            ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 let_res_1101;
                                                                            {
                                                                              Vec<1, uint32_t> leb_ref_118 { id_1100 };
                                                                              uint8_t id_1102 { 0 };
                                                                              Vec<1, uint8_t> id_1103 {  id_1102  };
                                                                              ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 let_res_1104;
                                                                              {
                                                                                Vec<1, uint8_t> shft_ref_119 { id_1103 };
                                                                                Vec<1, Pointer> id_1105 {  dsum1_snd_64  };
                                                                                ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 let_res_1106;
                                                                                {
                                                                                  Vec<1, Pointer> p_ref_120 { id_1105 };
                                                                                  bool while_flag_1107 { true };
                                                                                  do {
                                                                                    uint8_t id_1108 { 0 };
                                                                                    Pointer id_1109 { p_ref_120[id_1108] };
                                                                                    ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 id_1110 { id_1109.readU8() };
                                                                                    bool let_res_1111;
                                                                                    {
                                                                                      ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 leb128_121 { id_1110 };
                                                                                      bool letpair_res_1112;
                                                                                      {
                                                                                        auto leb128_fst_122 { std::get<0>(leb128_121) };
                                                                                        auto leb128_snd_123 { std::get<1>(leb128_121) };
                                                                                        uint8_t id_1113 { 0 };
                                                                                        Void id_1114 { ((void)(p_ref_120[id_1113] = leb128_snd_123), VOID) };
                                                                                        (void)id_1114;
                                                                                        uint8_t id_1115 { 0 };
                                                                                        uint8_t id_1116 { 127 };
                                                                                        uint8_t id_1117 { uint8_t(leb128_fst_122 & id_1116) };
                                                                                        uint32_t id_1118 { uint32_t(id_1117) };
                                                                                        uint8_t id_1119 { 0 };
                                                                                        uint8_t id_1120 { shft_ref_119[id_1119] };
                                                                                        uint32_t id_1121 { uint32_t(id_1118 << id_1120) };
                                                                                        uint8_t id_1122 { 0 };
                                                                                        uint32_t id_1123 { leb_ref_118[id_1122] };
                                                                                        uint32_t id_1124 { uint32_t(id_1121 | id_1123) };
                                                                                        Void id_1125 { ((void)(leb_ref_118[id_1115] = id_1124), VOID) };
                                                                                        (void)id_1125;
                                                                                        uint8_t id_1126 { 0 };
                                                                                        uint8_t id_1127 { 0 };
                                                                                        uint8_t id_1128 { shft_ref_119[id_1127] };
                                                                                        uint8_t id_1129 { 7 };
                                                                                        uint8_t id_1130 { uint8_t(id_1128 + id_1129) };
                                                                                        Void id_1131 { ((void)(shft_ref_119[id_1126] = id_1130), VOID) };
                                                                                        (void)id_1131;
                                                                                        uint8_t id_1132 { 128 };
                                                                                        bool id_1133 { bool(leb128_fst_122 >= id_1132) };
                                                                                        letpair_res_1112 = id_1133;
                                                                                      }
                                                                                      let_res_1111 = letpair_res_1112;
                                                                                    }
                                                                                    while_flag_1107 = let_res_1111;
                                                                                    if (while_flag_1107) {
                                                                                      (void)VOID;
                                                                                    }
                                                                                  } while (while_flag_1107);
                                                                                  (void)VOID;
                                                                                  uint8_t id_1134 { 0 };
                                                                                  uint32_t id_1135 { leb_ref_118[id_1134] };
                                                                                  uint8_t id_1136 { 0 };
                                                                                  Pointer id_1137 { p_ref_120[id_1136] };
                                                                                  ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 id_1138 { id_1135, id_1137 };
                                                                                  let_res_1106 = id_1138;
                                                                                }
                                                                                let_res_1104 = let_res_1106;
                                                                              }
                                                                              let_res_1101 = let_res_1104;
                                                                            }
                                                                            ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 let_res_1139;
                                                                            {
                                                                              ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 dlist1_127 { let_res_1101 };
                                                                              ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 letpair_res_1140;
                                                                              {
                                                                                auto dlist1_fst_128 { std::get<0>(dlist1_127) };
                                                                                auto dlist1_snd_129 { std::get<1>(dlist1_127) };
                                                                                Lst<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> endoflist_1141;
                                                                                ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 id_1142 { endoflist_1141, dlist1_snd_129 };
                                                                                Vec<1, ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4> id_1143 {  id_1142  };
                                                                                ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 let_res_1144;
                                                                                {
                                                                                  Vec<1, ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4> inits_src_ref_130 { id_1143 };
                                                                                  int32_t id_1145 { 0L };
                                                                                  Vec<1, int32_t> id_1146 {  id_1145  };
                                                                                  {
                                                                                    Vec<1, int32_t> repeat_n_131 { id_1146 };
                                                                                    bool while_flag_1147 { true };
                                                                                    do {
                                                                                      int32_t id_1148 { int32_t(dlist1_fst_128) };
                                                                                      uint8_t id_1149 { 0 };
                                                                                      int32_t id_1150 { repeat_n_131[id_1149] };
                                                                                      bool id_1151 { bool(id_1148 > id_1150) };
                                                                                      while_flag_1147 = id_1151;
                                                                                      if (while_flag_1147) {
                                                                                        uint8_t id_1152 { 0 };
                                                                                        ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 id_1153 { inits_src_ref_130[id_1152] };
                                                                                        {
                                                                                          ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 dlist2_132 { id_1153 };
                                                                                          {
                                                                                            auto dlist2_fst_133 { std::get<0>(dlist2_132) };
                                                                                            auto dlist2_snd_134 { std::get<1>(dlist2_132) };
                                                                                            uint8_t id_1154 { 0 };
                                                                                            uint32_t id_1155 { 0U };
                                                                                            Vec<1, uint32_t> id_1156 {  id_1155  };
                                                                                            ::dessser::gen::raql_type::t8beb80162423aee37bd383e9b6834c9c let_res_1157;
                                                                                            {
                                                                                              Vec<1, uint32_t> leb_ref_135 { id_1156 };
                                                                                              uint8_t id_1158 { 0 };
                                                                                              Vec<1, uint8_t> id_1159 {  id_1158  };
                                                                                              ::dessser::gen::raql_type::t8beb80162423aee37bd383e9b6834c9c let_res_1160;
                                                                                              {
                                                                                                Vec<1, uint8_t> shft_ref_136 { id_1159 };
                                                                                                Vec<1, Pointer> id_1161 {  dlist2_snd_134  };
                                                                                                ::dessser::gen::raql_type::t8beb80162423aee37bd383e9b6834c9c let_res_1162;
                                                                                                {
                                                                                                  Vec<1, Pointer> p_ref_137 { id_1161 };
                                                                                                  bool while_flag_1163 { true };
                                                                                                  do {
                                                                                                    uint8_t id_1164 { 0 };
                                                                                                    Pointer id_1165 { p_ref_137[id_1164] };
                                                                                                    ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 id_1166 { id_1165.readU8() };
                                                                                                    bool let_res_1167;
                                                                                                    {
                                                                                                      ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 leb128_138 { id_1166 };
                                                                                                      bool letpair_res_1168;
                                                                                                      {
                                                                                                        auto leb128_fst_139 { std::get<0>(leb128_138) };
                                                                                                        auto leb128_snd_140 { std::get<1>(leb128_138) };
                                                                                                        uint8_t id_1169 { 0 };
                                                                                                        Void id_1170 { ((void)(p_ref_137[id_1169] = leb128_snd_140), VOID) };
                                                                                                        (void)id_1170;
                                                                                                        uint8_t id_1171 { 0 };
                                                                                                        uint8_t id_1172 { 127 };
                                                                                                        uint8_t id_1173 { uint8_t(leb128_fst_139 & id_1172) };
                                                                                                        uint32_t id_1174 { uint32_t(id_1173) };
                                                                                                        uint8_t id_1175 { 0 };
                                                                                                        uint8_t id_1176 { shft_ref_136[id_1175] };
                                                                                                        uint32_t id_1177 { uint32_t(id_1174 << id_1176) };
                                                                                                        uint8_t id_1178 { 0 };
                                                                                                        uint32_t id_1179 { leb_ref_135[id_1178] };
                                                                                                        uint32_t id_1180 { uint32_t(id_1177 | id_1179) };
                                                                                                        Void id_1181 { ((void)(leb_ref_135[id_1171] = id_1180), VOID) };
                                                                                                        (void)id_1181;
                                                                                                        uint8_t id_1182 { 0 };
                                                                                                        uint8_t id_1183 { 0 };
                                                                                                        uint8_t id_1184 { shft_ref_136[id_1183] };
                                                                                                        uint8_t id_1185 { 7 };
                                                                                                        uint8_t id_1186 { uint8_t(id_1184 + id_1185) };
                                                                                                        Void id_1187 { ((void)(shft_ref_136[id_1182] = id_1186), VOID) };
                                                                                                        (void)id_1187;
                                                                                                        uint8_t id_1188 { 128 };
                                                                                                        bool id_1189 { bool(leb128_fst_139 >= id_1188) };
                                                                                                        letpair_res_1168 = id_1189;
                                                                                                      }
                                                                                                      let_res_1167 = letpair_res_1168;
                                                                                                    }
                                                                                                    while_flag_1163 = let_res_1167;
                                                                                                    if (while_flag_1163) {
                                                                                                      (void)VOID;
                                                                                                    }
                                                                                                  } while (while_flag_1163);
                                                                                                  (void)VOID;
                                                                                                  uint8_t id_1190 { 0 };
                                                                                                  uint32_t id_1191 { leb_ref_135[id_1190] };
                                                                                                  Size id_1192 { Size(id_1191) };
                                                                                                  uint8_t id_1193 { 0 };
                                                                                                  Pointer id_1194 { p_ref_137[id_1193] };
                                                                                                  ::dessser::gen::raql_type::t8beb80162423aee37bd383e9b6834c9c id_1195 { id_1192, id_1194 };
                                                                                                  let_res_1162 = id_1195;
                                                                                                }
                                                                                                let_res_1160 = let_res_1162;
                                                                                              }
                                                                                              let_res_1157 = let_res_1160;
                                                                                            }
                                                                                            ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 let_res_1196;
                                                                                            {
                                                                                              ::dessser::gen::raql_type::t8beb80162423aee37bd383e9b6834c9c dstring1_141 { let_res_1157 };
                                                                                              ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 letpair_res_1197;
                                                                                              {
                                                                                                auto dstring1_fst_142 { std::get<0>(dstring1_141) };
                                                                                                auto dstring1_snd_143 { std::get<1>(dstring1_141) };
                                                                                                ::dessser::gen::raql_type::t188345aa49abd0cb47ff73fedc219f08 id_1198 { dstring1_snd_143.readBytes(dstring1_fst_142) };
                                                                                                ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 letpair_res_1199;
                                                                                                {
                                                                                                  auto dstring2_fst_145 { std::get<0>(id_1198) };
                                                                                                  auto dstring2_snd_146 { std::get<1>(id_1198) };
                                                                                                  ::dessser::gen::raql_type::t45217dce3db5a9a49037839afd0048e8 id_1200 { fun847(dstring2_snd_146) };
                                                                                                  ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 letpair_res_1201;
                                                                                                  {
                                                                                                    auto dtup_fst_151 { std::get<0>(id_1200) };
                                                                                                    auto dtup_snd_152 { std::get<1>(id_1200) };
                                                                                                    std::string id_1202 { dstring2_fst_145.toString() };
                                                                                                    ::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c id_1203 { id_1202, dtup_fst_151 };
                                                                                                    Lst<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_1204 { id_1203, dlist2_fst_133 };
                                                                                                    ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 id_1205 { id_1204, dtup_snd_152 };
                                                                                                    letpair_res_1201 = id_1205;
                                                                                                  }
                                                                                                  letpair_res_1199 = letpair_res_1201;
                                                                                                }
                                                                                                letpair_res_1197 = letpair_res_1199;
                                                                                              }
                                                                                              let_res_1196 = letpair_res_1197;
                                                                                            }
                                                                                            Void id_1206 { ((void)(inits_src_ref_130[id_1154] = let_res_1196), VOID) };
                                                                                            (void)id_1206;
                                                                                          }
                                                                                          (void)VOID;
                                                                                        }
                                                                                        (void)VOID;
                                                                                        uint8_t id_1207 { 0 };
                                                                                        uint8_t id_1208 { 0 };
                                                                                        int32_t id_1209 { repeat_n_131[id_1208] };
                                                                                        int32_t id_1210 { 1L };
                                                                                        int32_t id_1211 { int32_t(id_1209 + id_1210) };
                                                                                        Void id_1212 { ((void)(repeat_n_131[id_1207] = id_1211), VOID) };
                                                                                        (void)id_1212;
                                                                                        (void)id_1212;
                                                                                      }
                                                                                    } while (while_flag_1147);
                                                                                    (void)VOID;
                                                                                  }
                                                                                  (void)VOID;
                                                                                  uint8_t id_1213 { 0 };
                                                                                  ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 id_1214 { inits_src_ref_130[id_1213] };
                                                                                  let_res_1144 = id_1214;
                                                                                }
                                                                                letpair_res_1140 = let_res_1144;
                                                                              }
                                                                              let_res_1139 = letpair_res_1140;
                                                                            }
                                                                            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a letpair_res_1215;
                                                                            {
                                                                              auto dlist4_fst_157 { std::get<0>(let_res_1139) };
                                                                              auto dlist4_snd_158 { std::get<1>(let_res_1139) };
                                                                              Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_1216 { dlist4_fst_157.toListRev() };
                                                                              ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_1217 { std::in_place_index<33>, id_1216 };
                                                                              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_1218 { id_1217, dlist4_snd_158 };
                                                                              letpair_res_1215 = id_1218;
                                                                            }
                                                                            choose_res_1098 = letpair_res_1215;
                                                                          } else {
                                                                            uint16_t id_1219 { 34 };
                                                                            bool id_1220 { bool(id_1219 == dsum1_fst_63) };
                                                                            ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a choose_res_1221;
                                                                            if (id_1220) {
                                                                              uint32_t id_1222 { 0U };
                                                                              Vec<1, uint32_t> id_1223 {  id_1222  };
                                                                              ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 let_res_1224;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_74 { id_1223 };
                                                                                uint8_t id_1225 { 0 };
                                                                                Vec<1, uint8_t> id_1226 {  id_1225  };
                                                                                ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 let_res_1227;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_75 { id_1226 };
                                                                                  Vec<1, Pointer> id_1228 {  dsum1_snd_64  };
                                                                                  ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 let_res_1229;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_76 { id_1228 };
                                                                                    bool while_flag_1230 { true };
                                                                                    do {
                                                                                      uint8_t id_1231 { 0 };
                                                                                      Pointer id_1232 { p_ref_76[id_1231] };
                                                                                      ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 id_1233 { id_1232.readU8() };
                                                                                      bool let_res_1234;
                                                                                      {
                                                                                        ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 leb128_77 { id_1233 };
                                                                                        bool letpair_res_1235;
                                                                                        {
                                                                                          auto leb128_fst_78 { std::get<0>(leb128_77) };
                                                                                          auto leb128_snd_79 { std::get<1>(leb128_77) };
                                                                                          uint8_t id_1236 { 0 };
                                                                                          Void id_1237 { ((void)(p_ref_76[id_1236] = leb128_snd_79), VOID) };
                                                                                          (void)id_1237;
                                                                                          uint8_t id_1238 { 0 };
                                                                                          uint8_t id_1239 { 127 };
                                                                                          uint8_t id_1240 { uint8_t(leb128_fst_78 & id_1239) };
                                                                                          uint32_t id_1241 { uint32_t(id_1240) };
                                                                                          uint8_t id_1242 { 0 };
                                                                                          uint8_t id_1243 { shft_ref_75[id_1242] };
                                                                                          uint32_t id_1244 { uint32_t(id_1241 << id_1243) };
                                                                                          uint8_t id_1245 { 0 };
                                                                                          uint32_t id_1246 { leb_ref_74[id_1245] };
                                                                                          uint32_t id_1247 { uint32_t(id_1244 | id_1246) };
                                                                                          Void id_1248 { ((void)(leb_ref_74[id_1238] = id_1247), VOID) };
                                                                                          (void)id_1248;
                                                                                          uint8_t id_1249 { 0 };
                                                                                          uint8_t id_1250 { 0 };
                                                                                          uint8_t id_1251 { shft_ref_75[id_1250] };
                                                                                          uint8_t id_1252 { 7 };
                                                                                          uint8_t id_1253 { uint8_t(id_1251 + id_1252) };
                                                                                          Void id_1254 { ((void)(shft_ref_75[id_1249] = id_1253), VOID) };
                                                                                          (void)id_1254;
                                                                                          uint8_t id_1255 { 128 };
                                                                                          bool id_1256 { bool(leb128_fst_78 >= id_1255) };
                                                                                          letpair_res_1235 = id_1256;
                                                                                        }
                                                                                        let_res_1234 = letpair_res_1235;
                                                                                      }
                                                                                      while_flag_1230 = let_res_1234;
                                                                                      if (while_flag_1230) {
                                                                                        (void)VOID;
                                                                                      }
                                                                                    } while (while_flag_1230);
                                                                                    (void)VOID;
                                                                                    uint8_t id_1257 { 0 };
                                                                                    uint32_t id_1258 { leb_ref_74[id_1257] };
                                                                                    uint8_t id_1259 { 0 };
                                                                                    Pointer id_1260 { p_ref_76[id_1259] };
                                                                                    ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 id_1261 { id_1258, id_1260 };
                                                                                    let_res_1229 = id_1261;
                                                                                  }
                                                                                  let_res_1227 = let_res_1229;
                                                                                }
                                                                                let_res_1224 = let_res_1227;
                                                                              }
                                                                              ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 let_res_1262;
                                                                              {
                                                                                ::dessser::gen::raql_type::t405eb186408556fed8f2c41523c07d13 dlist1_83 { let_res_1224 };
                                                                                ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 letpair_res_1263;
                                                                                {
                                                                                  auto dlist1_fst_84 { std::get<0>(dlist1_83) };
                                                                                  auto dlist1_snd_85 { std::get<1>(dlist1_83) };
                                                                                  Lst<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> endoflist_1264;
                                                                                  ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 id_1265 { endoflist_1264, dlist1_snd_85 };
                                                                                  Vec<1, ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4> id_1266 {  id_1265  };
                                                                                  ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 let_res_1267;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4> inits_src_ref_86 { id_1266 };
                                                                                    int32_t id_1268 { 0L };
                                                                                    Vec<1, int32_t> id_1269 {  id_1268  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_87 { id_1269 };
                                                                                      bool while_flag_1270 { true };
                                                                                      do {
                                                                                        int32_t id_1271 { int32_t(dlist1_fst_84) };
                                                                                        uint8_t id_1272 { 0 };
                                                                                        int32_t id_1273 { repeat_n_87[id_1272] };
                                                                                        bool id_1274 { bool(id_1271 > id_1273) };
                                                                                        while_flag_1270 = id_1274;
                                                                                        if (while_flag_1270) {
                                                                                          uint8_t id_1275 { 0 };
                                                                                          ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 id_1276 { inits_src_ref_86[id_1275] };
                                                                                          {
                                                                                            ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 dlist2_88 { id_1276 };
                                                                                            {
                                                                                              auto dlist2_fst_89 { std::get<0>(dlist2_88) };
                                                                                              auto dlist2_snd_90 { std::get<1>(dlist2_88) };
                                                                                              uint8_t id_1277 { 0 };
                                                                                              uint32_t id_1278 { 0U };
                                                                                              Vec<1, uint32_t> id_1279 {  id_1278  };
                                                                                              ::dessser::gen::raql_type::t8beb80162423aee37bd383e9b6834c9c let_res_1280;
                                                                                              {
                                                                                                Vec<1, uint32_t> leb_ref_91 { id_1279 };
                                                                                                uint8_t id_1281 { 0 };
                                                                                                Vec<1, uint8_t> id_1282 {  id_1281  };
                                                                                                ::dessser::gen::raql_type::t8beb80162423aee37bd383e9b6834c9c let_res_1283;
                                                                                                {
                                                                                                  Vec<1, uint8_t> shft_ref_92 { id_1282 };
                                                                                                  Vec<1, Pointer> id_1284 {  dlist2_snd_90  };
                                                                                                  ::dessser::gen::raql_type::t8beb80162423aee37bd383e9b6834c9c let_res_1285;
                                                                                                  {
                                                                                                    Vec<1, Pointer> p_ref_93 { id_1284 };
                                                                                                    bool while_flag_1286 { true };
                                                                                                    do {
                                                                                                      uint8_t id_1287 { 0 };
                                                                                                      Pointer id_1288 { p_ref_93[id_1287] };
                                                                                                      ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 id_1289 { id_1288.readU8() };
                                                                                                      bool let_res_1290;
                                                                                                      {
                                                                                                        ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 leb128_94 { id_1289 };
                                                                                                        bool letpair_res_1291;
                                                                                                        {
                                                                                                          auto leb128_fst_95 { std::get<0>(leb128_94) };
                                                                                                          auto leb128_snd_96 { std::get<1>(leb128_94) };
                                                                                                          uint8_t id_1292 { 0 };
                                                                                                          Void id_1293 { ((void)(p_ref_93[id_1292] = leb128_snd_96), VOID) };
                                                                                                          (void)id_1293;
                                                                                                          uint8_t id_1294 { 0 };
                                                                                                          uint8_t id_1295 { 127 };
                                                                                                          uint8_t id_1296 { uint8_t(leb128_fst_95 & id_1295) };
                                                                                                          uint32_t id_1297 { uint32_t(id_1296) };
                                                                                                          uint8_t id_1298 { 0 };
                                                                                                          uint8_t id_1299 { shft_ref_92[id_1298] };
                                                                                                          uint32_t id_1300 { uint32_t(id_1297 << id_1299) };
                                                                                                          uint8_t id_1301 { 0 };
                                                                                                          uint32_t id_1302 { leb_ref_91[id_1301] };
                                                                                                          uint32_t id_1303 { uint32_t(id_1300 | id_1302) };
                                                                                                          Void id_1304 { ((void)(leb_ref_91[id_1294] = id_1303), VOID) };
                                                                                                          (void)id_1304;
                                                                                                          uint8_t id_1305 { 0 };
                                                                                                          uint8_t id_1306 { 0 };
                                                                                                          uint8_t id_1307 { shft_ref_92[id_1306] };
                                                                                                          uint8_t id_1308 { 7 };
                                                                                                          uint8_t id_1309 { uint8_t(id_1307 + id_1308) };
                                                                                                          Void id_1310 { ((void)(shft_ref_92[id_1305] = id_1309), VOID) };
                                                                                                          (void)id_1310;
                                                                                                          uint8_t id_1311 { 128 };
                                                                                                          bool id_1312 { bool(leb128_fst_95 >= id_1311) };
                                                                                                          letpair_res_1291 = id_1312;
                                                                                                        }
                                                                                                        let_res_1290 = letpair_res_1291;
                                                                                                      }
                                                                                                      while_flag_1286 = let_res_1290;
                                                                                                      if (while_flag_1286) {
                                                                                                        (void)VOID;
                                                                                                      }
                                                                                                    } while (while_flag_1286);
                                                                                                    (void)VOID;
                                                                                                    uint8_t id_1313 { 0 };
                                                                                                    uint32_t id_1314 { leb_ref_91[id_1313] };
                                                                                                    Size id_1315 { Size(id_1314) };
                                                                                                    uint8_t id_1316 { 0 };
                                                                                                    Pointer id_1317 { p_ref_93[id_1316] };
                                                                                                    ::dessser::gen::raql_type::t8beb80162423aee37bd383e9b6834c9c id_1318 { id_1315, id_1317 };
                                                                                                    let_res_1285 = id_1318;
                                                                                                  }
                                                                                                  let_res_1283 = let_res_1285;
                                                                                                }
                                                                                                let_res_1280 = let_res_1283;
                                                                                              }
                                                                                              ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 let_res_1319;
                                                                                              {
                                                                                                ::dessser::gen::raql_type::t8beb80162423aee37bd383e9b6834c9c dstring1_97 { let_res_1280 };
                                                                                                ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 letpair_res_1320;
                                                                                                {
                                                                                                  auto dstring1_fst_98 { std::get<0>(dstring1_97) };
                                                                                                  auto dstring1_snd_99 { std::get<1>(dstring1_97) };
                                                                                                  ::dessser::gen::raql_type::t188345aa49abd0cb47ff73fedc219f08 id_1321 { dstring1_snd_99.readBytes(dstring1_fst_98) };
                                                                                                  ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 letpair_res_1322;
                                                                                                  {
                                                                                                    auto dstring2_fst_101 { std::get<0>(id_1321) };
                                                                                                    auto dstring2_snd_102 { std::get<1>(id_1321) };
                                                                                                    ::dessser::gen::raql_type::t45217dce3db5a9a49037839afd0048e8 id_1323 { fun847(dstring2_snd_102) };
                                                                                                    ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 letpair_res_1324;
                                                                                                    {
                                                                                                      auto dtup_fst_107 { std::get<0>(id_1323) };
                                                                                                      auto dtup_snd_108 { std::get<1>(id_1323) };
                                                                                                      std::string id_1325 { dstring2_fst_101.toString() };
                                                                                                      ::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c id_1326 { id_1325, dtup_fst_107 };
                                                                                                      Lst<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_1327 { id_1326, dlist2_fst_89 };
                                                                                                      ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 id_1328 { id_1327, dtup_snd_108 };
                                                                                                      letpair_res_1324 = id_1328;
                                                                                                    }
                                                                                                    letpair_res_1322 = letpair_res_1324;
                                                                                                  }
                                                                                                  letpair_res_1320 = letpair_res_1322;
                                                                                                }
                                                                                                let_res_1319 = letpair_res_1320;
                                                                                              }
                                                                                              Void id_1329 { ((void)(inits_src_ref_86[id_1277] = let_res_1319), VOID) };
                                                                                              (void)id_1329;
                                                                                            }
                                                                                            (void)VOID;
                                                                                          }
                                                                                          (void)VOID;
                                                                                          uint8_t id_1330 { 0 };
                                                                                          uint8_t id_1331 { 0 };
                                                                                          int32_t id_1332 { repeat_n_87[id_1331] };
                                                                                          int32_t id_1333 { 1L };
                                                                                          int32_t id_1334 { int32_t(id_1332 + id_1333) };
                                                                                          Void id_1335 { ((void)(repeat_n_87[id_1330] = id_1334), VOID) };
                                                                                          (void)id_1335;
                                                                                          (void)id_1335;
                                                                                        }
                                                                                      } while (while_flag_1270);
                                                                                      (void)VOID;
                                                                                    }
                                                                                    (void)VOID;
                                                                                    uint8_t id_1336 { 0 };
                                                                                    ::dessser::gen::raql_type::t5c3d2277237e7b88993f70440ba84ff4 id_1337 { inits_src_ref_86[id_1336] };
                                                                                    let_res_1267 = id_1337;
                                                                                  }
                                                                                  letpair_res_1263 = let_res_1267;
                                                                                }
                                                                                let_res_1262 = letpair_res_1263;
                                                                              }
                                                                              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a letpair_res_1338;
                                                                              {
                                                                                auto dlist4_fst_113 { std::get<0>(let_res_1262) };
                                                                                auto dlist4_snd_114 { std::get<1>(let_res_1262) };
                                                                                Arr<::dessser::gen::raql_type::t100b7e5cf4b9a621db7a39d7f1d01e5c> id_1339 { dlist4_fst_113.toListRev() };
                                                                                ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_1340 { std::in_place_index<34>, id_1339 };
                                                                                ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_1341 { id_1340, dlist4_snd_114 };
                                                                                letpair_res_1338 = id_1341;
                                                                              }
                                                                              choose_res_1221 = letpair_res_1338;
                                                                            } else {
                                                                              uint16_t id_1342 { 35 };
                                                                              bool id_1343 { bool(dsum1_fst_63 == id_1342) };
                                                                              Void id_1344 { ((void)(assert(id_1343)), VOID) };
                                                                              (void)id_1344;
                                                                              ::dessser::gen::raql_type::t45217dce3db5a9a49037839afd0048e8 id_1345 { fun847(dsum1_snd_64) };
                                                                              ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a letpair_res_1346;
                                                                              {
                                                                                auto dtup_fst_66 { std::get<0>(id_1345) };
                                                                                auto dtup_snd_67 { std::get<1>(id_1345) };
                                                                                ::dessser::gen::raql_type::t45217dce3db5a9a49037839afd0048e8 id_1347 { fun847(dtup_snd_67) };
                                                                                ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a letpair_res_1348;
                                                                                {
                                                                                  auto dtup_fst_69 { std::get<0>(id_1347) };
                                                                                  auto dtup_snd_70 { std::get<1>(id_1347) };
                                                                                  ::dessser::gen::raql_type::t7411897bdb6c9b6e00a01b4eb6506ccf id_1349 { dtup_fst_66, dtup_fst_69 };
                                                                                  ::dessser::gen::raql_type::t90c8a0d2bbcf528f6fcdb9d24234c023 id_1350 { std::in_place_index<35>, id_1349 };
                                                                                  ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a id_1351 { id_1350, dtup_snd_70 };
                                                                                  letpair_res_1348 = id_1351;
                                                                                }
                                                                                letpair_res_1346 = letpair_res_1348;
                                                                              }
                                                                              choose_res_1221 = letpair_res_1346;
                                                                            }
                                                                            choose_res_1098 = choose_res_1221;
                                                                          }
                                                                          choose_res_1091 = choose_res_1098;
                                                                        }
                                                                        choose_res_1081 = choose_res_1091;
                                                                      }
                                                                      choose_res_1005 = choose_res_1081;
                                                                    }
                                                                    choose_res_1000 = choose_res_1005;
                                                                  }
                                                                  choose_res_995 = choose_res_1000;
                                                                }
                                                                choose_res_990 = choose_res_995;
                                                              }
                                                              choose_res_985 = choose_res_990;
                                                            }
                                                            choose_res_980 = choose_res_985;
                                                          }
                                                          choose_res_975 = choose_res_980;
                                                        }
                                                        choose_res_970 = choose_res_975;
                                                      }
                                                      choose_res_965 = choose_res_970;
                                                    }
                                                    choose_res_960 = choose_res_965;
                                                  }
                                                  choose_res_955 = choose_res_960;
                                                }
                                                choose_res_950 = choose_res_955;
                                              }
                                              choose_res_945 = choose_res_950;
                                            }
                                            choose_res_940 = choose_res_945;
                                          }
                                          choose_res_935 = choose_res_940;
                                        }
                                        choose_res_930 = choose_res_935;
                                      }
                                      choose_res_925 = choose_res_930;
                                    }
                                    choose_res_920 = choose_res_925;
                                  }
                                  choose_res_915 = choose_res_920;
                                }
                                choose_res_910 = choose_res_915;
                              }
                              choose_res_905 = choose_res_910;
                            }
                            choose_res_900 = choose_res_905;
                          }
                          choose_res_895 = choose_res_900;
                        }
                        choose_res_890 = choose_res_895;
                      }
                      choose_res_885 = choose_res_890;
                    }
                    choose_res_880 = choose_res_885;
                  }
                  choose_res_875 = choose_res_880;
                }
                choose_res_870 = choose_res_875;
              }
              choose_res_865 = choose_res_870;
            }
            choose_res_860 = choose_res_865;
          }
          choose_res_855 = choose_res_860;
        }
        letpair_res_852 = choose_res_855;
      }
      let_res_851 = letpair_res_852;
    }
    ::dessser::gen::raql_type::tfafddb6af18e2fa33b782eb359ee7c77 let_res_1352;
    {
      ::dessser::gen::raql_type::tb59ed3c1bba347d5259eaaf5d37e798a drec_293 { let_res_851 };
      ::dessser::gen::raql_type::tfafddb6af18e2fa33b782eb359ee7c77 letpair_res_1353;
      {
        auto drec_fst_294 { std::get<0>(drec_293) };
        auto drec_snd_295 { std::get<1>(drec_293) };
        ::dessser::gen::raql_type::tb3f98ea670610d40658a618de3ec7b90 id_1354 { drec_snd_295.readU8() };
        ::dessser::gen::raql_type::tfafddb6af18e2fa33b782eb359ee7c77 letpair_res_1355;
        {
          auto dbool_fst_297 { std::get<0>(id_1354) };
          auto dbool_snd_298 { std::get<1>(id_1354) };
          uint8_t id_1356 { 0 };
          bool id_1357 { bool(dbool_fst_297 == id_1356) };
          bool id_1358 { ! id_1357 };
          ::dessser::gen::raql_type::t* id_1359 { new ::dessser::gen::raql_type::t({ .nullable = id_1358, .type = drec_fst_294 }) };
          ::dessser::gen::raql_type::tfafddb6af18e2fa33b782eb359ee7c77 id_1360 { id_1359, dbool_snd_298 };
          letpair_res_1355 = id_1360;
        }
        letpair_res_1353 = letpair_res_1355;
      }
      let_res_1352 = letpair_res_1353;
    }
    return let_res_1352;
  }
   };
  return fun847;
}
std::function<::dessser::gen::raql_type::tfafddb6af18e2fa33b782eb359ee7c77(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;

}
