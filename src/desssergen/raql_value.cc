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

namespace dessser::gen::raql_value {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct tb689860ac91fca7822797a026958e891 : public std::variant<
  uint32_t, // v4
  uint128_t // v6
> { using variant::variant; };

struct t81f779acbcb9180b1df9b88e2d8ce982 {
  uint32_t Cidr4_ip;
  uint8_t Cidr4_mask;
  t81f779acbcb9180b1df9b88e2d8ce982(uint32_t Cidr4_ip_, uint8_t Cidr4_mask_) : Cidr4_ip(Cidr4_ip_), Cidr4_mask(Cidr4_mask_) {}
  t81f779acbcb9180b1df9b88e2d8ce982() = default;
};
struct t8d4af754051624596ec1687a64e3bf86 {
  uint128_t ip;
  uint8_t mask;
  t8d4af754051624596ec1687a64e3bf86(uint128_t ip_, uint8_t mask_) : ip(ip_), mask(mask_) {}
  t8d4af754051624596ec1687a64e3bf86() = default;
};
struct t086a8e00718450baf3e88e60b5e42a27 : public std::variant<
  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982, // v4
  ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 // v6
> { using variant::variant; };

struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_value : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::raql_value::t> 
> {
  using tuple::tuple;
  named_value(std::tuple<std::string, std::shared_ptr<::dessser::gen::raql_value::t> > p)
    : std::tuple<std::string, std::shared_ptr<::dessser::gen::raql_value::t> >(std::get<0>(p), std::get<1>(p)) {}
};
struct t03cfda2a49b4fd636c1028863952922d : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_value::t> ,
  std::shared_ptr<::dessser::gen::raql_value::t> 
> {
  using tuple::tuple;
  t03cfda2a49b4fd636c1028863952922d(std::tuple<std::shared_ptr<::dessser::gen::raql_value::t> , std::shared_ptr<::dessser::gen::raql_value::t> > p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_value::t> , std::shared_ptr<::dessser::gen::raql_value::t> >(std::get<0>(p), std::get<1>(p)) {}
};
struct t : public std::variant<
  Void, // VNull
  Void, // VUnit
  double, // VFloat
  std::string, // VString
  bool, // VBool
  char, // VChar
  uint8_t, // VU8
  uint16_t, // VU16
  uint32_t, // VU24
  uint32_t, // VU32
  uint64_t, // VU40
  uint64_t, // VU48
  uint64_t, // VU56
  uint64_t, // VU64
  uint128_t, // VU128
  int8_t, // VI8
  int16_t, // VI16
  int32_t, // VI24
  int32_t, // VI32
  int64_t, // VI40
  int64_t, // VI48
  int64_t, // VI56
  int64_t, // VI64
  int128_t, // VI128
  uint64_t, // VEth
  uint32_t, // VIpv4
  uint128_t, // VIpv6
  ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891, // VIp
  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982, // VCidrv4
  ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86, // VCidrv6
  ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27, // VCidr
  Arr<std::shared_ptr<::dessser::gen::raql_value::t> >, // VTup
  Arr<std::shared_ptr<::dessser::gen::raql_value::t> >, // VVec
  Arr<std::shared_ptr<::dessser::gen::raql_value::t> >, // VArr
  Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> >, // VRec
  Arr<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d> // VMap
> { using variant::variant; };

struct t2192dc426e477a22ba201bc3a0e4295b : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_value::t> ,
  Pointer
> {
  using tuple::tuple;
  t2192dc426e477a22ba201bc3a0e4295b(std::tuple<std::shared_ptr<::dessser::gen::raql_value::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_value::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
extern std::function<::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b(Pointer)> of_row_binary;
struct t7609d344c1ba69d0f80fec236d4c216b : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  t7609d344c1ba69d0f80fec236d4c216b(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tf568409f41c9c0a265f7302110fc9084 : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  tf568409f41c9c0a265f7302110fc9084(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t1566bd611d8a2b90669c241f5e8d6ff1 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1566bd611d8a2b90669c241f5e8d6ff1(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t9e0ebd3dfe4817b98136c6e6b20afc92 : public std::tuple<
  uint128_t,
  Pointer
> {
  using tuple::tuple;
  t9e0ebd3dfe4817b98136c6e6b20afc92(std::tuple<uint128_t, Pointer> p)
    : std::tuple<uint128_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tbacb7b7dfcd8eb9fae24f64ef122344a : public std::tuple<
  ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891,
  Pointer
> {
  using tuple::tuple;
  tbacb7b7dfcd8eb9fae24f64ef122344a(std::tuple<::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891, Pointer> p)
    : std::tuple<::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t67fcf630ffd97c208644a466f20c16dc : public std::tuple<
  ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27,
  Pointer
> {
  using tuple::tuple;
  t67fcf630ffd97c208644a466f20c16dc(std::tuple<::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27, Pointer> p)
    : std::tuple<::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t9658b993bb9f5814bdb59e00050f3b24 : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::raql_value::t> >,
  Pointer
> {
  using tuple::tuple;
  t9658b993bb9f5814bdb59e00050f3b24(std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_value::t> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_value::t> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t5acf4e40a97d10bb414b149b4987167e : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::raql_value::named_value> >,
  Pointer
> {
  using tuple::tuple;
  t5acf4e40a97d10bb414b149b4987167e(std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_value::named_value> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_value::named_value> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t0c870624fb83311f54db2c065f542418 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_value::named_value> ,
  Pointer
> {
  using tuple::tuple;
  t0c870624fb83311f54db2c065f542418(std::tuple<std::shared_ptr<::dessser::gen::raql_value::named_value> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_value::named_value> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t6ca87232c4396e34133f69634dc3e421 : public std::tuple<
  Lst<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d>,
  Pointer
> {
  using tuple::tuple;
  t6ca87232c4396e34133f69634dc3e421(std::tuple<Lst<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<::dessser::gen::raql_value::t0c870624fb83311f54db2c065f542418(Pointer)> named_value_of_row_binary;
struct t3fd8221434e489b54b5c4356ebff5005 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t3fd8221434e489b54b5c4356ebff5005(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_value::t> )> sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_value::named_value> )> named_value_sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::named_value> ,Pointer)> named_value_to_row_binary;
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("Ptr")
      (let-pair "make_fst_529" "make_snd_530"
        (let "dsum1_83" (let-pair "du16_fst_78" "du16_snd_79" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_78") (identifier "du16_snd_79")))
          (let-pair "dsum1_fst_84" "dsum1_snd_85" (identifier "dsum1_83")
            (if (eq (u16 0) (identifier "dsum1_fst_84"))
              (make-tup
                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 0
                  (nop)) (identifier "dsum1_snd_85"))
              (if (eq (u16 1) (identifier "dsum1_fst_84"))
                (make-tup
                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 1
                    (nop)) (identifier "dsum1_snd_85"))
                (if (eq (u16 2) (identifier "dsum1_fst_84"))
                  (let-pair "dfloat_fst_517" "dfloat_snd_518" (read-u64 little-endian (identifier "dsum1_snd_85"))
                    (make-tup
                      (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 2
                        (float-of-u64 (identifier "dfloat_fst_517"))) 
                      (identifier "dfloat_snd_518")))
                  (if (eq (u16 3) (identifier "dsum1_fst_84"))
                    (let "dstring1_507"
                      (let "leb_ref_501" (make-vec (u32 0))
                        (let "shft_ref_502" (make-vec (u8 0))
                          (let "p_ref_503" (make-vec (identifier "dsum1_snd_85"))
                            (seq
                              (while
                                (let "leb128_504" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_503")))
                                  (let-pair "leb128_fst_505" "leb128_snd_506" 
                                    (identifier "leb128_504")
                                    (seq (set-vec (u8 0) (identifier "p_ref_503") (identifier "leb128_snd_506"))
                                      (set-vec (u8 0) (identifier "leb_ref_501")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_505") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_502"))) (unsafe-nth (u8 0) (identifier "leb_ref_501"))))
                                      (set-vec (u8 0) (identifier "shft_ref_502") (add (unsafe-nth (u8 0) (identifier "shft_ref_502")) (u8 7))) 
                                      (ge (identifier "leb128_fst_505") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_501"))) (unsafe-nth (u8 0) (identifier "p_ref_503")))))))
                      (let-pair "dstring1_fst_508" "dstring1_snd_509" 
                        (identifier "dstring1_507")
                        (let-pair "dstring2_fst_511" "dstring2_snd_512" 
                          (read-bytes (identifier "dstring1_snd_509") (identifier "dstring1_fst_508"))
                          (make-tup
                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 3
                              (string-of-bytes (identifier "dstring2_fst_511"))) 
                            (identifier "dstring2_snd_512")))))
                    (if (eq (u16 4) (identifier "dsum1_fst_84"))
                      (let-pair "dbool_fst_496" "dbool_snd_497" (read-u8 (identifier "dsum1_snd_85"))
                        (make-tup
                          (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 4
                            (not (eq (identifier "dbool_fst_496") (u8 0)))) 
                          (identifier "dbool_snd_497")))
                      (if (eq (u16 5) (identifier "dsum1_fst_84"))
                        (let-pair "dchar_fst_490" "dchar_snd_491" (read-u8 (identifier "dsum1_snd_85"))
                          (make-tup
                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 5
                              (char-of-u8 (identifier "dchar_fst_490"))) 
                            (identifier "dchar_snd_491")))
                        (if (eq (u16 6) (identifier "dsum1_fst_84"))
                          (let-pair "du8_fst_484" "du8_snd_485" (read-u8 (identifier "dsum1_snd_85"))
                            (make-tup
                              (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 6
                                (identifier "du8_fst_484")) (identifier "du8_snd_485")))
                          (if (eq (u16 7) (identifier "dsum1_fst_84"))
                            (let-pair "du16_fst_478" "du16_snd_479" (read-u16 little-endian (identifier "dsum1_snd_85"))
                              (make-tup
                                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 7
                                  (identifier "du16_fst_478")) (identifier "du16_snd_479")))
                            (if (eq (u16 8) (identifier "dsum1_fst_84"))
                              (let-pair "du24_fst_472" "du24_snd_473" 
                                (read-u32 little-endian (identifier "dsum1_snd_85"))
                                (make-tup
                                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 8
                                    (to-u24 (identifier "du24_fst_472"))) 
                                  (identifier "du24_snd_473")))
                              (if (eq (u16 9) (identifier "dsum1_fst_84"))
                                (let-pair "du32_fst_466" "du32_snd_467" 
                                  (read-u32 little-endian (identifier "dsum1_snd_85"))
                                  (make-tup
                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 9
                                      (identifier "du32_fst_466")) (identifier "du32_snd_467")))
                                (if (eq (u16 10) (identifier "dsum1_fst_84"))
                                  (let-pair "du40_fst_460" "du40_snd_461" 
                                    (read-u64 little-endian (identifier "dsum1_snd_85"))
                                    (make-tup
                                      (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 10
                                        (to-u40 (identifier "du40_fst_460"))) 
                                      (identifier "du40_snd_461")))
                                  (if (eq (u16 11) (identifier "dsum1_fst_84"))
                                    (let-pair "du48_fst_454" "du48_snd_455" 
                                      (read-u64 little-endian (identifier "dsum1_snd_85"))
                                      (make-tup
                                        (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 11
                                          (to-u48 (identifier "du48_fst_454"))) 
                                        (identifier "du48_snd_455")))
                                    (if (eq (u16 12) (identifier "dsum1_fst_84"))
                                      (let-pair "du56_fst_448" "du56_snd_449" 
                                        (read-u64 little-endian (identifier "dsum1_snd_85"))
                                        (make-tup
                                          (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 12
                                            (to-u56 (identifier "du56_fst_448"))) 
                                          (identifier "du56_snd_449")))
                                      (if (eq (u16 13) (identifier "dsum1_fst_84"))
                                        (let-pair "du64_fst_442" "du64_snd_443" 
                                          (read-u64 little-endian (identifier "dsum1_snd_85"))
                                          (make-tup
                                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 13
                                              (identifier "du64_fst_442")) 
                                            (identifier "du64_snd_443")))
                                        (if (eq (u16 14) (identifier "dsum1_fst_84"))
                                          (let-pair "di128_fst_436" "di128_snd_437" 
                                            (read-u128 little-endian (identifier "dsum1_snd_85"))
                                            (make-tup
                                              (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 14
                                                (identifier "di128_fst_436")) 
                                              (identifier "di128_snd_437")))
                                          (if (eq (u16 15) (identifier "dsum1_fst_84"))
                                            (let-pair "di8_fst_430" "di8_snd_431" 
                                              (read-u8 (identifier "dsum1_snd_85"))
                                              (make-tup
                                                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 15
                                                  (to-i8 (identifier "di8_fst_430"))) 
                                                (identifier "di8_snd_431")))
                                            (if (eq (u16 16) (identifier "dsum1_fst_84"))
                                              (let-pair "di16_fst_424" "di16_snd_425" 
                                                (read-u16 little-endian (identifier "dsum1_snd_85"))
                                                (make-tup
                                                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 16
                                                    (to-i16 (identifier "di16_fst_424"))) 
                                                  (identifier "di16_snd_425")))
                                              (if (eq (u16 17) (identifier "dsum1_fst_84"))
                                                (let-pair "di24_fst_418" "di24_snd_419" 
                                                  (read-u32 little-endian (identifier "dsum1_snd_85"))
                                                  (make-tup
                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 17
                                                      (to-i24 (identifier "di24_fst_418"))) 
                                                    (identifier "di24_snd_419")))
                                                (if (eq (u16 18) (identifier "dsum1_fst_84"))
                                                  (let-pair "di32_fst_412" "di32_snd_413" 
                                                    (read-u32 little-endian (identifier "dsum1_snd_85"))
                                                    (make-tup
                                                      (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 18
                                                        (to-i32 (identifier "di32_fst_412"))) 
                                                      (identifier "di32_snd_413")))
                                                  (if (eq (u16 19) (identifier "dsum1_fst_84"))
                                                    (let-pair "di40_fst_406" "di40_snd_407" 
                                                      (read-u64 little-endian (identifier "dsum1_snd_85"))
                                                      (make-tup
                                                        (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 19
                                                          (to-i40 (identifier "di40_fst_406"))) 
                                                        (identifier "di40_snd_407")))
                                                    (if (eq (u16 20) (identifier "dsum1_fst_84"))
                                                      (let-pair "di48_fst_400" "di48_snd_401" 
                                                        (read-u64 little-endian (identifier "dsum1_snd_85"))
                                                        (make-tup
                                                          (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 20
                                                            (to-i48 (identifier "di48_fst_400"))) 
                                                          (identifier "di48_snd_401")))
                                                      (if (eq (u16 21) (identifier "dsum1_fst_84"))
                                                        (let-pair "di56_fst_394" "di56_snd_395" 
                                                          (read-u64 little-endian (identifier "dsum1_snd_85"))
                                                          (make-tup
                                                            (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 21
                                                              (to-i56 (identifier "di56_fst_394"))) 
                                                            (identifier "di56_snd_395")))
                                                        (if (eq (u16 22) (identifier "dsum1_fst_84"))
                                                          (let-pair "di64_fst_388" "di64_snd_389" 
                                                            (read-u64 little-endian (identifier "dsum1_snd_85"))
                                                            (make-tup
                                                              (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 22
                                                                (to-i64 (identifier "di64_fst_388"))) 
                                                              (identifier "di64_snd_389")))
                                                          (if (eq (u16 23) (identifier "dsum1_fst_84"))
                                                            (let-pair "di128_fst_382" "di128_snd_383" 
                                                              (read-u128 little-endian (identifier "dsum1_snd_85"))
                                                              (make-tup
                                                                (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 23
                                                                  (to-i128 (identifier "di128_fst_382"))) 
                                                                (identifier "di128_snd_383")))
                                                            (if (eq (u16 24) (identifier "dsum1_fst_84"))
                                                              (let-pair "du48_fst_373" "du48_snd_374" 
                                                                (read-u64 little-endian (identifier "dsum1_snd_85"))
                                                                (make-tup
                                                                  (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 24
                                                                    (make-usr "Eth" (to-u48 (identifier "du48_fst_373")))) 
                                                                  (identifier "du48_snd_374")))
                                                              (if (eq (u16 25) (identifier "dsum1_fst_84"))
                                                                (let-pair "du32_fst_364" "du32_snd_365" 
                                                                  (read-u32 little-endian (identifier "dsum1_snd_85"))
                                                                  (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 25
                                                                    (make-usr "Ip4" (identifier "du32_fst_364"))) 
                                                                    (identifier "du32_snd_365")))
                                                                (if (eq (u16 26) (identifier "dsum1_fst_84"))
                                                                  (let-pair "di128_fst_355" "di128_snd_356" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_85"))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 26
                                                                    (make-usr "Ip6" (identifier "di128_fst_355"))) 
                                                                    (identifier "di128_snd_356")))
                                                                  (if 
                                                                    (eq (u16 27) (identifier "dsum1_fst_84"))
                                                                    (let-pair "des_usr_type_fst_349" "des_usr_type_snd_350"
                                                                    (let "dsum1_327"
                                                                    (let-pair "du16_fst_322" "du16_snd_323" (read-u16 little-endian (identifier "dsum1_snd_85")) (make-tup (identifier "du16_fst_322") (identifier "du16_snd_323")))
                                                                    (let-pair "dsum1_fst_328" "dsum1_snd_329" 
                                                                    (identifier "dsum1_327")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_328"))
                                                                    (let-pair "du32_fst_340" "du32_snd_341" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_329"))
                                                                    (make-tup (construct "[v4 Ip4 | v6 Ip6]" 0 (make-usr "Ip4" (identifier "du32_fst_340"))) (identifier "du32_snd_341")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_328") (u16 1)))
                                                                    (let-pair "di128_fst_331" "di128_snd_332" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_329"))
                                                                    (make-tup (construct "[v4 Ip4 | v6 Ip6]" 1 (make-usr "Ip6" (identifier "di128_fst_331"))) (identifier "di128_snd_332")))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 27
                                                                    (make-usr "Ip" (identifier "des_usr_type_fst_349"))) 
                                                                    (identifier "des_usr_type_snd_350")))
                                                                    (if 
                                                                    (eq (u16 28) (identifier "dsum1_fst_84"))
                                                                    (let "drec_306"
                                                                    (let-pair "du32_fst_301" "du32_snd_302" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_85")) 
                                                                    (make-tup (make-usr "Ip4" (identifier "du32_fst_301")) (identifier "du32_snd_302")))
                                                                    (let-pair "drec_fst_307" "drec_snd_308" 
                                                                    (identifier "drec_306")
                                                                    (let-pair "du8_fst_310" "du8_snd_311" 
                                                                    (read-u8 (identifier "drec_snd_308"))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 28
                                                                    (make-usr "Cidr4" (make-rec (string "mask") (identifier "du8_fst_310") (string "ip") (identifier "drec_fst_307")))) 
                                                                    (identifier "du8_snd_311")))))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "dsum1_fst_84"))
                                                                    (let "drec_285"
                                                                    (let-pair "di128_fst_280" "di128_snd_281" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_85")) 
                                                                    (make-tup (make-usr "Ip6" (identifier "di128_fst_280")) (identifier "di128_snd_281")))
                                                                    (let-pair "drec_fst_286" "drec_snd_287" 
                                                                    (identifier "drec_285")
                                                                    (let-pair "du8_fst_289" "du8_snd_290" 
                                                                    (read-u8 (identifier "drec_snd_287"))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 29
                                                                    (make-usr "Cidr6" (make-rec (string "mask") (identifier "du8_fst_289") (string "ip") (identifier "drec_fst_286")))) 
                                                                    (identifier "du8_snd_290")))))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "dsum1_fst_84"))
                                                                    (let-pair "des_usr_type_fst_274" "des_usr_type_snd_275"
                                                                    (let "dsum1_228"
                                                                    (let-pair "du16_fst_223" "du16_snd_224" (read-u16 little-endian (identifier "dsum1_snd_85")) (make-tup (identifier "du16_fst_223") (identifier "du16_snd_224")))
                                                                    (let-pair "dsum1_fst_229" "dsum1_snd_230" 
                                                                    (identifier "dsum1_228")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_229"))
                                                                    (let "drec_258"
                                                                    (let-pair "du32_fst_253" "du32_snd_254" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_230")) 
                                                                    (make-tup (make-usr "Ip4" (identifier "du32_fst_253")) (identifier "du32_snd_254")))
                                                                    (let-pair "drec_fst_259" "drec_snd_260" 
                                                                    (identifier "drec_258")
                                                                    (let-pair "du8_fst_262" "du8_snd_263" 
                                                                    (read-u8 (identifier "drec_snd_260"))
                                                                    (make-tup
                                                                    (construct "[v4 Cidr4 | v6 Cidr6]" 0 (make-usr "Cidr4" (make-rec (string "mask") (identifier "du8_fst_262") (string "ip") (identifier "drec_fst_259"))))
                                                                    (identifier "du8_snd_263")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_229") (u16 1)))
                                                                    (let "drec_237"
                                                                    (let-pair "di128_fst_232" "di128_snd_233" 
                                                                    (read-u128 little-endian (identifier "dsum1_snd_230")) 
                                                                    (make-tup (make-usr "Ip6" (identifier "di128_fst_232")) (identifier "di128_snd_233")))
                                                                    (let-pair "drec_fst_238" "drec_snd_239" 
                                                                    (identifier "drec_237")
                                                                    (let-pair "du8_fst_241" "du8_snd_242" 
                                                                    (read-u8 (identifier "drec_snd_239"))
                                                                    (make-tup
                                                                    (construct "[v4 Cidr4 | v6 Cidr6]" 1 (make-usr "Cidr6" (make-rec (string "mask") (identifier "du8_fst_241") (string "ip") (identifier "drec_fst_238"))))
                                                                    (identifier "du8_snd_242")))))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 30
                                                                    (make-usr "Cidr" (identifier "des_usr_type_fst_274"))) 
                                                                    (identifier "des_usr_type_snd_275")))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "dsum1_fst_84"))
                                                                    (let-pair "dlist4_fst_217" "dlist4_snd_218"
                                                                    (let "dlist1_205"
                                                                    (let "leb_ref_196" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_197" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_198" 
                                                                    (make-vec (identifier "dsum1_snd_85"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_199" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_198")))
                                                                    (let-pair "leb128_fst_200" "leb128_snd_201" 
                                                                    (identifier "leb128_199")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_198") (identifier "leb128_snd_201"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_196")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_200") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_197")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_196")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_197") (add (unsafe-nth (u8 0) (identifier "shft_ref_197")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_200") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_196")) (unsafe-nth (u8 0) (identifier "p_ref_198")))))))
                                                                    (let-pair "dlist1_fst_206" "dlist1_snd_207" 
                                                                    (identifier "dlist1_205")
                                                                    (let "inits_src_ref_208" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_207")))
                                                                    (seq
                                                                    (let "repeat_n_209" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_206")) (unsafe-nth (u8 0) (identifier "repeat_n_209")))
                                                                    (seq
                                                                    (let "dlist2_210" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_208"))
                                                                    (let-pair "dlist2_fst_211" "dlist2_snd_212" 
                                                                    (identifier "dlist2_210")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_208")
                                                                    (let-pair "dlist3_fst_214" "dlist3_snd_215" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_212"))
                                                                    (make-tup (cons (identifier "dlist3_fst_214") (identifier "dlist2_fst_211")) (identifier "dlist3_snd_215"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_209") (add (unsafe-nth (u8 0) (identifier "repeat_n_209")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_208"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 31
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_217"))) 
                                                                    (identifier "dlist4_snd_218")))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "dsum1_fst_84"))
                                                                    (let-pair "dlist4_fst_191" "dlist4_snd_192"
                                                                    (let "dlist1_179"
                                                                    (let "leb_ref_170" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_171" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_172" 
                                                                    (make-vec (identifier "dsum1_snd_85"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_173" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_172")))
                                                                    (let-pair "leb128_fst_174" "leb128_snd_175" 
                                                                    (identifier "leb128_173")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_172") (identifier "leb128_snd_175"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_170")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_174") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_171")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_170")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_171") (add (unsafe-nth (u8 0) (identifier "shft_ref_171")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_174") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_170")) (unsafe-nth (u8 0) (identifier "p_ref_172")))))))
                                                                    (let-pair "dlist1_fst_180" "dlist1_snd_181" 
                                                                    (identifier "dlist1_179")
                                                                    (let "inits_src_ref_182" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_181")))
                                                                    (seq
                                                                    (let "repeat_n_183" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_180")) (unsafe-nth (u8 0) (identifier "repeat_n_183")))
                                                                    (seq
                                                                    (let "dlist2_184" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_182"))
                                                                    (let-pair "dlist2_fst_185" "dlist2_snd_186" 
                                                                    (identifier "dlist2_184")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_182")
                                                                    (let-pair "dlist3_fst_188" "dlist3_snd_189" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_186"))
                                                                    (make-tup (cons (identifier "dlist3_fst_188") (identifier "dlist2_fst_185")) (identifier "dlist3_snd_189"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_183") (add (unsafe-nth (u8 0) (identifier "repeat_n_183")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_182"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 32
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_191"))) 
                                                                    (identifier "dlist4_snd_192")))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "dsum1_fst_84"))
                                                                    (let-pair "dlist4_fst_165" "dlist4_snd_166"
                                                                    (let "dlist1_153"
                                                                    (let "leb_ref_144" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_145" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_146" 
                                                                    (make-vec (identifier "dsum1_snd_85"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_147" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_146")))
                                                                    (let-pair "leb128_fst_148" "leb128_snd_149" 
                                                                    (identifier "leb128_147")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_146") (identifier "leb128_snd_149"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_144")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_148") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_145")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_144")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_145") (add (unsafe-nth (u8 0) (identifier "shft_ref_145")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_148") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_144")) (unsafe-nth (u8 0) (identifier "p_ref_146")))))))
                                                                    (let-pair "dlist1_fst_154" "dlist1_snd_155" 
                                                                    (identifier "dlist1_153")
                                                                    (let "inits_src_ref_156" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_155")))
                                                                    (seq
                                                                    (let "repeat_n_157" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_154")) (unsafe-nth (u8 0) (identifier "repeat_n_157")))
                                                                    (seq
                                                                    (let "dlist2_158" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_156"))
                                                                    (let-pair "dlist2_fst_159" "dlist2_snd_160" 
                                                                    (identifier "dlist2_158")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_156")
                                                                    (let-pair "dlist3_fst_162" "dlist3_snd_163" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_160"))
                                                                    (make-tup (cons (identifier "dlist3_fst_162") (identifier "dlist2_fst_159")) (identifier "dlist3_snd_163"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_157") (add (unsafe-nth (u8 0) (identifier "repeat_n_157")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_156"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 33
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_165"))) 
                                                                    (identifier "dlist4_snd_166")))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "dsum1_fst_84"))
                                                                    (let-pair "dlist4_fst_139" "dlist4_snd_140"
                                                                    (let "dlist1_127"
                                                                    (let "leb_ref_118" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_119" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_120" 
                                                                    (make-vec (identifier "dsum1_snd_85"))
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
                                                                    (make-vec (make-tup (end-of-list "(named_value AS (STRING; THIS))") (identifier "dlist1_snd_129")))
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
                                                                    (let-pair "dlist3_fst_136" "dlist3_snd_137" 
                                                                    (apply (identifier "named_value-of-row-binary") (identifier "dlist2_snd_134"))
                                                                    (make-tup (cons (identifier "dlist3_fst_136") (identifier "dlist2_fst_133")) (identifier "dlist3_snd_137"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_131") (add (unsafe-nth (u8 0) (identifier "repeat_n_131")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_130"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 34
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_139"))) 
                                                                    (identifier "dlist4_snd_140")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_84") (u16 35)))
                                                                    (let-pair "dlist4_fst_113" "dlist4_snd_114"
                                                                    (let "dlist1_95"
                                                                    (let "leb_ref_86" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_87" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_88" 
                                                                    (make-vec (identifier "dsum1_snd_85"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_89" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_88")))
                                                                    (let-pair "leb128_fst_90" "leb128_snd_91" 
                                                                    (identifier "leb128_89")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_88") (identifier "leb128_snd_91"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_86")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_90") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_87")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_86")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_87") (add (unsafe-nth (u8 0) (identifier "shft_ref_87")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_90") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_86")) (unsafe-nth (u8 0) (identifier "p_ref_88")))))))
                                                                    (let-pair "dlist1_fst_96" "dlist1_snd_97" 
                                                                    (identifier "dlist1_95")
                                                                    (let "inits_src_ref_98" 
                                                                    (make-vec (make-tup (end-of-list "(THIS; THIS)") (identifier "dlist1_snd_97")))
                                                                    (seq
                                                                    (let "repeat_n_99" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_96")) (unsafe-nth (u8 0) (identifier "repeat_n_99")))
                                                                    (seq
                                                                    (let "dlist2_100" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_98"))
                                                                    (let-pair "dlist2_fst_101" "dlist2_snd_102" 
                                                                    (identifier "dlist2_100")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_98")
                                                                    (let-pair "dtup_fst_104" "dtup_snd_105" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dlist2_snd_102"))
                                                                    (let-pair "dtup_fst_107" "dtup_snd_108" 
                                                                    (apply (myself "(THIS; Ptr)") (identifier "dtup_snd_105"))
                                                                    (make-tup (cons (make-tup (identifier "dtup_fst_104") (identifier "dtup_fst_107")) (identifier "dlist2_fst_101")) (identifier "dtup_snd_108")))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_99") (add (unsafe-nth (u8 0) (identifier "repeat_n_99")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_98"))))))
                                                                    (make-tup
                                                                    (construct "[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" 35
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_113"))) 
                                                                    (identifier "dlist4_snd_114"))))))))))))))))))))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_529") (identifier "make_snd_530"))))
 */
static std::function<::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b(Pointer)> fun0 { [&fun0](Pointer p_0) {
    ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b id_1 { p_0.readU16Le() };
    ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2;
    {
      auto du16_fst_78 { std::get<0>(id_1) };
      auto du16_snd_79 { std::get<1>(id_1) };
      ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b id_3 { du16_fst_78, du16_snd_79 };
      letpair_res_2 = id_3;
    }
    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b let_res_4;
    {
      ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b dsum1_83 { letpair_res_2 };
      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_5;
      {
        auto dsum1_fst_84 { std::get<0>(dsum1_83) };
        auto dsum1_snd_85 { std::get<1>(dsum1_83) };
        uint16_t id_6 { 0 };
        bool id_7 { bool(id_6 == dsum1_fst_84) };
        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_8;
        if (id_7) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::raql_value::t>  id_9 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_10 { id_9, dsum1_snd_85 };
          choose_res_8 = id_10;
        } else {
          uint16_t id_11 { 1 };
          bool id_12 { bool(id_11 == dsum1_fst_84) };
          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_13;
          if (id_12) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::raql_value::t>  id_14 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_15 { id_14, dsum1_snd_85 };
            choose_res_13 = id_15;
          } else {
            uint16_t id_16 { 2 };
            bool id_17 { bool(id_16 == dsum1_fst_84) };
            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_18;
            if (id_17) {
              ::dessser::gen::raql_value::tf568409f41c9c0a265f7302110fc9084 id_19 { dsum1_snd_85.readU64Le() };
              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_20;
              {
                auto dfloat_fst_517 { std::get<0>(id_19) };
                auto dfloat_snd_518 { std::get<1>(id_19) };
                double id_21 { float_of_qword(dfloat_fst_517) };
                std::shared_ptr<::dessser::gen::raql_value::t>  id_22 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<2>, id_21) };
                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_23 { id_22, dfloat_snd_518 };
                letpair_res_20 = id_23;
              }
              choose_res_18 = letpair_res_20;
            } else {
              uint16_t id_24 { 3 };
              bool id_25 { bool(id_24 == dsum1_fst_84) };
              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_26;
              if (id_25) {
                uint32_t id_27 { 0U };
                Vec<1, uint32_t> id_28 {  id_27  };
                ::dessser::gen::raql_value::t044960e524fd6ec1bfc06410ce526709 let_res_29;
                {
                  Vec<1, uint32_t> leb_ref_501 { id_28 };
                  uint8_t id_30 { 0 };
                  Vec<1, uint8_t> id_31 {  id_30  };
                  ::dessser::gen::raql_value::t044960e524fd6ec1bfc06410ce526709 let_res_32;
                  {
                    Vec<1, uint8_t> shft_ref_502 { id_31 };
                    Vec<1, Pointer> id_33 {  dsum1_snd_85  };
                    ::dessser::gen::raql_value::t044960e524fd6ec1bfc06410ce526709 let_res_34;
                    {
                      Vec<1, Pointer> p_ref_503 { id_33 };
                      bool while_flag_35 { true };
                      do {
                        uint8_t id_36 { 0 };
                        Pointer id_37 { p_ref_503[id_36] };
                        ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_38 { id_37.readU8() };
                        bool let_res_39;
                        {
                          ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_504 { id_38 };
                          bool letpair_res_40;
                          {
                            auto leb128_fst_505 { std::get<0>(leb128_504) };
                            auto leb128_snd_506 { std::get<1>(leb128_504) };
                            uint8_t id_41 { 0 };
                            Void id_42 { ((void)(p_ref_503[id_41] = leb128_snd_506), ::dessser::VOID) };
                            (void)id_42;
                            uint8_t id_43 { 0 };
                            uint8_t id_44 { 127 };
                            uint8_t id_45 { uint8_t(leb128_fst_505 & id_44) };
                            uint32_t id_46 { uint32_t(id_45) };
                            uint8_t id_47 { 0 };
                            uint8_t id_48 { shft_ref_502[id_47] };
                            uint32_t id_49 { uint32_t(id_46 << id_48) };
                            uint8_t id_50 { 0 };
                            uint32_t id_51 { leb_ref_501[id_50] };
                            uint32_t id_52 { uint32_t(id_49 | id_51) };
                            Void id_53 { ((void)(leb_ref_501[id_43] = id_52), ::dessser::VOID) };
                            (void)id_53;
                            uint8_t id_54 { 0 };
                            uint8_t id_55 { 0 };
                            uint8_t id_56 { shft_ref_502[id_55] };
                            uint8_t id_57 { 7 };
                            uint8_t id_58 { uint8_t(id_56 + id_57) };
                            Void id_59 { ((void)(shft_ref_502[id_54] = id_58), ::dessser::VOID) };
                            (void)id_59;
                            uint8_t id_60 { 128 };
                            bool id_61 { bool(leb128_fst_505 >= id_60) };
                            letpair_res_40 = id_61;
                          }
                          let_res_39 = letpair_res_40;
                        }
                        while_flag_35 = let_res_39;
                        if (while_flag_35) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_35);
                      (void)::dessser::VOID;
                      uint8_t id_62 { 0 };
                      uint32_t id_63 { leb_ref_501[id_62] };
                      Size id_64 { Size(id_63) };
                      uint8_t id_65 { 0 };
                      Pointer id_66 { p_ref_503[id_65] };
                      ::dessser::gen::raql_value::t044960e524fd6ec1bfc06410ce526709 id_67 { id_64, id_66 };
                      let_res_34 = id_67;
                    }
                    let_res_32 = let_res_34;
                  }
                  let_res_29 = let_res_32;
                }
                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b let_res_68;
                {
                  ::dessser::gen::raql_value::t044960e524fd6ec1bfc06410ce526709 dstring1_507 { let_res_29 };
                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_69;
                  {
                    auto dstring1_fst_508 { std::get<0>(dstring1_507) };
                    auto dstring1_snd_509 { std::get<1>(dstring1_507) };
                    ::dessser::gen::raql_value::t5887709cc43c8c8e24d28211e8c970a2 id_70 { dstring1_snd_509.readBytes(dstring1_fst_508) };
                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_71;
                    {
                      auto dstring2_fst_511 { std::get<0>(id_70) };
                      auto dstring2_snd_512 { std::get<1>(id_70) };
                      std::string id_72 { dstring2_fst_511.toString() };
                      std::shared_ptr<::dessser::gen::raql_value::t>  id_73 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<3>, id_72) };
                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_74 { id_73, dstring2_snd_512 };
                      letpair_res_71 = id_74;
                    }
                    letpair_res_69 = letpair_res_71;
                  }
                  let_res_68 = letpair_res_69;
                }
                choose_res_26 = let_res_68;
              } else {
                uint16_t id_75 { 4 };
                bool id_76 { bool(id_75 == dsum1_fst_84) };
                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_77;
                if (id_76) {
                  ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_78 { dsum1_snd_85.readU8() };
                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_79;
                  {
                    auto dbool_fst_496 { std::get<0>(id_78) };
                    auto dbool_snd_497 { std::get<1>(id_78) };
                    uint8_t id_80 { 0 };
                    bool id_81 { bool(dbool_fst_496 == id_80) };
                    bool id_82 { ! id_81 };
                    std::shared_ptr<::dessser::gen::raql_value::t>  id_83 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<4>, id_82) };
                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_84 { id_83, dbool_snd_497 };
                    letpair_res_79 = id_84;
                  }
                  choose_res_77 = letpair_res_79;
                } else {
                  uint16_t id_85 { 5 };
                  bool id_86 { bool(id_85 == dsum1_fst_84) };
                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_87;
                  if (id_86) {
                    ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_88 { dsum1_snd_85.readU8() };
                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_89;
                    {
                      auto dchar_fst_490 { std::get<0>(id_88) };
                      auto dchar_snd_491 { std::get<1>(id_88) };
                      char id_90 { char(dchar_fst_490) };
                      std::shared_ptr<::dessser::gen::raql_value::t>  id_91 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<5>, id_90) };
                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_92 { id_91, dchar_snd_491 };
                      letpair_res_89 = id_92;
                    }
                    choose_res_87 = letpair_res_89;
                  } else {
                    uint16_t id_93 { 6 };
                    bool id_94 { bool(id_93 == dsum1_fst_84) };
                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_95;
                    if (id_94) {
                      ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_96 { dsum1_snd_85.readU8() };
                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_97;
                      {
                        auto du8_fst_484 { std::get<0>(id_96) };
                        auto du8_snd_485 { std::get<1>(id_96) };
                        std::shared_ptr<::dessser::gen::raql_value::t>  id_98 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<6>, du8_fst_484) };
                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_99 { id_98, du8_snd_485 };
                        letpair_res_97 = id_99;
                      }
                      choose_res_95 = letpair_res_97;
                    } else {
                      uint16_t id_100 { 7 };
                      bool id_101 { bool(id_100 == dsum1_fst_84) };
                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_102;
                      if (id_101) {
                        ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b id_103 { dsum1_snd_85.readU16Le() };
                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_104;
                        {
                          auto du16_fst_478 { std::get<0>(id_103) };
                          auto du16_snd_479 { std::get<1>(id_103) };
                          std::shared_ptr<::dessser::gen::raql_value::t>  id_105 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<7>, du16_fst_478) };
                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_106 { id_105, du16_snd_479 };
                          letpair_res_104 = id_106;
                        }
                        choose_res_102 = letpair_res_104;
                      } else {
                        uint16_t id_107 { 8 };
                        bool id_108 { bool(id_107 == dsum1_fst_84) };
                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_109;
                        if (id_108) {
                          ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_110 { dsum1_snd_85.readU32Le() };
                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_111;
                          {
                            auto du24_fst_472 { std::get<0>(id_110) };
                            auto du24_snd_473 { std::get<1>(id_110) };
                            uint32_t id_112 { uint32_t(du24_fst_472) };
                            std::shared_ptr<::dessser::gen::raql_value::t>  id_113 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<8>, id_112) };
                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_114 { id_113, du24_snd_473 };
                            letpair_res_111 = id_114;
                          }
                          choose_res_109 = letpair_res_111;
                        } else {
                          uint16_t id_115 { 9 };
                          bool id_116 { bool(id_115 == dsum1_fst_84) };
                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_117;
                          if (id_116) {
                            ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_118 { dsum1_snd_85.readU32Le() };
                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_119;
                            {
                              auto du32_fst_466 { std::get<0>(id_118) };
                              auto du32_snd_467 { std::get<1>(id_118) };
                              std::shared_ptr<::dessser::gen::raql_value::t>  id_120 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<9>, du32_fst_466) };
                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_121 { id_120, du32_snd_467 };
                              letpair_res_119 = id_121;
                            }
                            choose_res_117 = letpair_res_119;
                          } else {
                            uint16_t id_122 { 10 };
                            bool id_123 { bool(id_122 == dsum1_fst_84) };
                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_124;
                            if (id_123) {
                              ::dessser::gen::raql_value::tf568409f41c9c0a265f7302110fc9084 id_125 { dsum1_snd_85.readU64Le() };
                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_126;
                              {
                                auto du40_fst_460 { std::get<0>(id_125) };
                                auto du40_snd_461 { std::get<1>(id_125) };
                                uint64_t id_127 { uint64_t(du40_fst_460) };
                                std::shared_ptr<::dessser::gen::raql_value::t>  id_128 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<10>, id_127) };
                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_129 { id_128, du40_snd_461 };
                                letpair_res_126 = id_129;
                              }
                              choose_res_124 = letpair_res_126;
                            } else {
                              uint16_t id_130 { 11 };
                              bool id_131 { bool(id_130 == dsum1_fst_84) };
                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_132;
                              if (id_131) {
                                ::dessser::gen::raql_value::tf568409f41c9c0a265f7302110fc9084 id_133 { dsum1_snd_85.readU64Le() };
                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_134;
                                {
                                  auto du48_fst_454 { std::get<0>(id_133) };
                                  auto du48_snd_455 { std::get<1>(id_133) };
                                  uint64_t id_135 { uint64_t(du48_fst_454) };
                                  std::shared_ptr<::dessser::gen::raql_value::t>  id_136 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<11>, id_135) };
                                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_137 { id_136, du48_snd_455 };
                                  letpair_res_134 = id_137;
                                }
                                choose_res_132 = letpair_res_134;
                              } else {
                                uint16_t id_138 { 12 };
                                bool id_139 { bool(id_138 == dsum1_fst_84) };
                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_140;
                                if (id_139) {
                                  ::dessser::gen::raql_value::tf568409f41c9c0a265f7302110fc9084 id_141 { dsum1_snd_85.readU64Le() };
                                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_142;
                                  {
                                    auto du56_fst_448 { std::get<0>(id_141) };
                                    auto du56_snd_449 { std::get<1>(id_141) };
                                    uint64_t id_143 { uint64_t(du56_fst_448) };
                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_144 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<12>, id_143) };
                                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_145 { id_144, du56_snd_449 };
                                    letpair_res_142 = id_145;
                                  }
                                  choose_res_140 = letpair_res_142;
                                } else {
                                  uint16_t id_146 { 13 };
                                  bool id_147 { bool(id_146 == dsum1_fst_84) };
                                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_148;
                                  if (id_147) {
                                    ::dessser::gen::raql_value::tf568409f41c9c0a265f7302110fc9084 id_149 { dsum1_snd_85.readU64Le() };
                                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_150;
                                    {
                                      auto du64_fst_442 { std::get<0>(id_149) };
                                      auto du64_snd_443 { std::get<1>(id_149) };
                                      std::shared_ptr<::dessser::gen::raql_value::t>  id_151 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<13>, du64_fst_442) };
                                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_152 { id_151, du64_snd_443 };
                                      letpair_res_150 = id_152;
                                    }
                                    choose_res_148 = letpair_res_150;
                                  } else {
                                    uint16_t id_153 { 14 };
                                    bool id_154 { bool(id_153 == dsum1_fst_84) };
                                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_155;
                                    if (id_154) {
                                      ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 id_156 { dsum1_snd_85.readU128Le() };
                                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_157;
                                      {
                                        auto di128_fst_436 { std::get<0>(id_156) };
                                        auto di128_snd_437 { std::get<1>(id_156) };
                                        std::shared_ptr<::dessser::gen::raql_value::t>  id_158 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<14>, di128_fst_436) };
                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_159 { id_158, di128_snd_437 };
                                        letpair_res_157 = id_159;
                                      }
                                      choose_res_155 = letpair_res_157;
                                    } else {
                                      uint16_t id_160 { 15 };
                                      bool id_161 { bool(id_160 == dsum1_fst_84) };
                                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_162;
                                      if (id_161) {
                                        ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_163 { dsum1_snd_85.readU8() };
                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_164;
                                        {
                                          auto di8_fst_430 { std::get<0>(id_163) };
                                          auto di8_snd_431 { std::get<1>(id_163) };
                                          int8_t id_165 { int8_t(di8_fst_430) };
                                          std::shared_ptr<::dessser::gen::raql_value::t>  id_166 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<15>, id_165) };
                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_167 { id_166, di8_snd_431 };
                                          letpair_res_164 = id_167;
                                        }
                                        choose_res_162 = letpair_res_164;
                                      } else {
                                        uint16_t id_168 { 16 };
                                        bool id_169 { bool(id_168 == dsum1_fst_84) };
                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_170;
                                        if (id_169) {
                                          ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b id_171 { dsum1_snd_85.readU16Le() };
                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_172;
                                          {
                                            auto di16_fst_424 { std::get<0>(id_171) };
                                            auto di16_snd_425 { std::get<1>(id_171) };
                                            int16_t id_173 { int16_t(di16_fst_424) };
                                            std::shared_ptr<::dessser::gen::raql_value::t>  id_174 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<16>, id_173) };
                                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_175 { id_174, di16_snd_425 };
                                            letpair_res_172 = id_175;
                                          }
                                          choose_res_170 = letpair_res_172;
                                        } else {
                                          uint16_t id_176 { 17 };
                                          bool id_177 { bool(id_176 == dsum1_fst_84) };
                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_178;
                                          if (id_177) {
                                            ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_179 { dsum1_snd_85.readU32Le() };
                                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_180;
                                            {
                                              auto di24_fst_418 { std::get<0>(id_179) };
                                              auto di24_snd_419 { std::get<1>(id_179) };
                                              int32_t id_181 { int32_t(di24_fst_418) };
                                              std::shared_ptr<::dessser::gen::raql_value::t>  id_182 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<17>, id_181) };
                                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_183 { id_182, di24_snd_419 };
                                              letpair_res_180 = id_183;
                                            }
                                            choose_res_178 = letpair_res_180;
                                          } else {
                                            uint16_t id_184 { 18 };
                                            bool id_185 { bool(id_184 == dsum1_fst_84) };
                                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_186;
                                            if (id_185) {
                                              ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_187 { dsum1_snd_85.readU32Le() };
                                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_188;
                                              {
                                                auto di32_fst_412 { std::get<0>(id_187) };
                                                auto di32_snd_413 { std::get<1>(id_187) };
                                                int32_t id_189 { int32_t(di32_fst_412) };
                                                std::shared_ptr<::dessser::gen::raql_value::t>  id_190 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<18>, id_189) };
                                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_191 { id_190, di32_snd_413 };
                                                letpair_res_188 = id_191;
                                              }
                                              choose_res_186 = letpair_res_188;
                                            } else {
                                              uint16_t id_192 { 19 };
                                              bool id_193 { bool(id_192 == dsum1_fst_84) };
                                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_194;
                                              if (id_193) {
                                                ::dessser::gen::raql_value::tf568409f41c9c0a265f7302110fc9084 id_195 { dsum1_snd_85.readU64Le() };
                                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_196;
                                                {
                                                  auto di40_fst_406 { std::get<0>(id_195) };
                                                  auto di40_snd_407 { std::get<1>(id_195) };
                                                  int64_t id_197 { int64_t(di40_fst_406) };
                                                  std::shared_ptr<::dessser::gen::raql_value::t>  id_198 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<19>, id_197) };
                                                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_199 { id_198, di40_snd_407 };
                                                  letpair_res_196 = id_199;
                                                }
                                                choose_res_194 = letpair_res_196;
                                              } else {
                                                uint16_t id_200 { 20 };
                                                bool id_201 { bool(id_200 == dsum1_fst_84) };
                                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_202;
                                                if (id_201) {
                                                  ::dessser::gen::raql_value::tf568409f41c9c0a265f7302110fc9084 id_203 { dsum1_snd_85.readU64Le() };
                                                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_204;
                                                  {
                                                    auto di48_fst_400 { std::get<0>(id_203) };
                                                    auto di48_snd_401 { std::get<1>(id_203) };
                                                    int64_t id_205 { int64_t(di48_fst_400) };
                                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_206 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<20>, id_205) };
                                                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_207 { id_206, di48_snd_401 };
                                                    letpair_res_204 = id_207;
                                                  }
                                                  choose_res_202 = letpair_res_204;
                                                } else {
                                                  uint16_t id_208 { 21 };
                                                  bool id_209 { bool(id_208 == dsum1_fst_84) };
                                                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_210;
                                                  if (id_209) {
                                                    ::dessser::gen::raql_value::tf568409f41c9c0a265f7302110fc9084 id_211 { dsum1_snd_85.readU64Le() };
                                                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_212;
                                                    {
                                                      auto di56_fst_394 { std::get<0>(id_211) };
                                                      auto di56_snd_395 { std::get<1>(id_211) };
                                                      int64_t id_213 { int64_t(di56_fst_394) };
                                                      std::shared_ptr<::dessser::gen::raql_value::t>  id_214 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<21>, id_213) };
                                                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_215 { id_214, di56_snd_395 };
                                                      letpair_res_212 = id_215;
                                                    }
                                                    choose_res_210 = letpair_res_212;
                                                  } else {
                                                    uint16_t id_216 { 22 };
                                                    bool id_217 { bool(id_216 == dsum1_fst_84) };
                                                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_218;
                                                    if (id_217) {
                                                      ::dessser::gen::raql_value::tf568409f41c9c0a265f7302110fc9084 id_219 { dsum1_snd_85.readU64Le() };
                                                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_220;
                                                      {
                                                        auto di64_fst_388 { std::get<0>(id_219) };
                                                        auto di64_snd_389 { std::get<1>(id_219) };
                                                        int64_t id_221 { int64_t(di64_fst_388) };
                                                        std::shared_ptr<::dessser::gen::raql_value::t>  id_222 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<22>, id_221) };
                                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_223 { id_222, di64_snd_389 };
                                                        letpair_res_220 = id_223;
                                                      }
                                                      choose_res_218 = letpair_res_220;
                                                    } else {
                                                      uint16_t id_224 { 23 };
                                                      bool id_225 { bool(id_224 == dsum1_fst_84) };
                                                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_226;
                                                      if (id_225) {
                                                        ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 id_227 { dsum1_snd_85.readU128Le() };
                                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_228;
                                                        {
                                                          auto di128_fst_382 { std::get<0>(id_227) };
                                                          auto di128_snd_383 { std::get<1>(id_227) };
                                                          int128_t id_229 { int128_t(di128_fst_382) };
                                                          std::shared_ptr<::dessser::gen::raql_value::t>  id_230 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<23>, id_229) };
                                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_231 { id_230, di128_snd_383 };
                                                          letpair_res_228 = id_231;
                                                        }
                                                        choose_res_226 = letpair_res_228;
                                                      } else {
                                                        uint16_t id_232 { 24 };
                                                        bool id_233 { bool(id_232 == dsum1_fst_84) };
                                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_234;
                                                        if (id_233) {
                                                          ::dessser::gen::raql_value::tf568409f41c9c0a265f7302110fc9084 id_235 { dsum1_snd_85.readU64Le() };
                                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_236;
                                                          {
                                                            auto du48_fst_373 { std::get<0>(id_235) };
                                                            auto du48_snd_374 { std::get<1>(id_235) };
                                                            std::function<uint64_t(uint64_t)> fun237 { [&fun237](uint64_t p_0) {
                                                              return p_0;
                                                            }
                                                             };
                                                            uint64_t id_238 { uint64_t(du48_fst_373) };
                                                            uint64_t id_239 { fun237(id_238) };
                                                            std::shared_ptr<::dessser::gen::raql_value::t>  id_240 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<24>, id_239) };
                                                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_241 { id_240, du48_snd_374 };
                                                            letpair_res_236 = id_241;
                                                          }
                                                          choose_res_234 = letpair_res_236;
                                                        } else {
                                                          uint16_t id_242 { 25 };
                                                          bool id_243 { bool(id_242 == dsum1_fst_84) };
                                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_244;
                                                          if (id_243) {
                                                            ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_245 { dsum1_snd_85.readU32Le() };
                                                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_246;
                                                            {
                                                              auto du32_fst_364 { std::get<0>(id_245) };
                                                              auto du32_snd_365 { std::get<1>(id_245) };
                                                              std::function<uint32_t(uint32_t)> fun247 { [&fun247](uint32_t p_0) {
                                                                return p_0;
                                                              }
                                                               };
                                                              uint32_t id_248 { fun247(du32_fst_364) };
                                                              std::shared_ptr<::dessser::gen::raql_value::t>  id_249 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<25>, id_248) };
                                                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_250 { id_249, du32_snd_365 };
                                                              letpair_res_246 = id_250;
                                                            }
                                                            choose_res_244 = letpair_res_246;
                                                          } else {
                                                            uint16_t id_251 { 26 };
                                                            bool id_252 { bool(id_251 == dsum1_fst_84) };
                                                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_253;
                                                            if (id_252) {
                                                              ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 id_254 { dsum1_snd_85.readU128Le() };
                                                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_255;
                                                              {
                                                                auto di128_fst_355 { std::get<0>(id_254) };
                                                                auto di128_snd_356 { std::get<1>(id_254) };
                                                                std::function<uint128_t(uint128_t)> fun256 { [&fun256](uint128_t p_0) {
                                                                  return p_0;
                                                                }
                                                                 };
                                                                uint128_t id_257 { fun256(di128_fst_355) };
                                                                std::shared_ptr<::dessser::gen::raql_value::t>  id_258 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<26>, id_257) };
                                                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_259 { id_258, di128_snd_356 };
                                                                letpair_res_255 = id_259;
                                                              }
                                                              choose_res_253 = letpair_res_255;
                                                            } else {
                                                              uint16_t id_260 { 27 };
                                                              bool id_261 { bool(id_260 == dsum1_fst_84) };
                                                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_262;
                                                              if (id_261) {
                                                                ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b id_263 { dsum1_snd_85.readU16Le() };
                                                                ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b letpair_res_264;
                                                                {
                                                                  auto du16_fst_322 { std::get<0>(id_263) };
                                                                  auto du16_snd_323 { std::get<1>(id_263) };
                                                                  ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b id_265 { du16_fst_322, du16_snd_323 };
                                                                  letpair_res_264 = id_265;
                                                                }
                                                                ::dessser::gen::raql_value::tbacb7b7dfcd8eb9fae24f64ef122344a let_res_266;
                                                                {
                                                                  ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b dsum1_327 { letpair_res_264 };
                                                                  ::dessser::gen::raql_value::tbacb7b7dfcd8eb9fae24f64ef122344a letpair_res_267;
                                                                  {
                                                                    auto dsum1_fst_328 { std::get<0>(dsum1_327) };
                                                                    auto dsum1_snd_329 { std::get<1>(dsum1_327) };
                                                                    uint16_t id_268 { 0 };
                                                                    bool id_269 { bool(id_268 == dsum1_fst_328) };
                                                                    ::dessser::gen::raql_value::tbacb7b7dfcd8eb9fae24f64ef122344a choose_res_270;
                                                                    if (id_269) {
                                                                      ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_271 { dsum1_snd_329.readU32Le() };
                                                                      ::dessser::gen::raql_value::tbacb7b7dfcd8eb9fae24f64ef122344a letpair_res_272;
                                                                      {
                                                                        auto du32_fst_340 { std::get<0>(id_271) };
                                                                        auto du32_snd_341 { std::get<1>(id_271) };
                                                                        std::function<uint32_t(uint32_t)> fun273 { [&fun273](uint32_t p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        uint32_t id_274 { fun273(du32_fst_340) };
                                                                        ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_275 { std::in_place_index<0>, id_274 };
                                                                        ::dessser::gen::raql_value::tbacb7b7dfcd8eb9fae24f64ef122344a id_276 { id_275, du32_snd_341 };
                                                                        letpair_res_272 = id_276;
                                                                      }
                                                                      choose_res_270 = letpair_res_272;
                                                                    } else {
                                                                      uint16_t id_277 { 1 };
                                                                      bool id_278 { bool(dsum1_fst_328 == id_277) };
                                                                      Void id_279 { ((void)(assert(id_278)), ::dessser::VOID) };
                                                                      (void)id_279;
                                                                      ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 id_280 { dsum1_snd_329.readU128Le() };
                                                                      ::dessser::gen::raql_value::tbacb7b7dfcd8eb9fae24f64ef122344a letpair_res_281;
                                                                      {
                                                                        auto di128_fst_331 { std::get<0>(id_280) };
                                                                        auto di128_snd_332 { std::get<1>(id_280) };
                                                                        std::function<uint128_t(uint128_t)> fun282 { [&fun282](uint128_t p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        uint128_t id_283 { fun282(di128_fst_331) };
                                                                        ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_284 { std::in_place_index<1>, id_283 };
                                                                        ::dessser::gen::raql_value::tbacb7b7dfcd8eb9fae24f64ef122344a id_285 { id_284, di128_snd_332 };
                                                                        letpair_res_281 = id_285;
                                                                      }
                                                                      choose_res_270 = letpair_res_281;
                                                                    }
                                                                    letpair_res_267 = choose_res_270;
                                                                  }
                                                                  let_res_266 = letpair_res_267;
                                                                }
                                                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_286;
                                                                {
                                                                  auto des_usr_type_fst_349 { std::get<0>(let_res_266) };
                                                                  auto des_usr_type_snd_350 { std::get<1>(let_res_266) };
                                                                  std::function<::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891(::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891)> fun287 { [&fun287](::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 p_0) {
                                                                    return p_0;
                                                                  }
                                                                   };
                                                                  ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_288 { fun287(des_usr_type_fst_349) };
                                                                  std::shared_ptr<::dessser::gen::raql_value::t>  id_289 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<27>, id_288) };
                                                                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_290 { id_289, des_usr_type_snd_350 };
                                                                  letpair_res_286 = id_290;
                                                                }
                                                                choose_res_262 = letpair_res_286;
                                                              } else {
                                                                uint16_t id_291 { 28 };
                                                                bool id_292 { bool(id_291 == dsum1_fst_84) };
                                                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_293;
                                                                if (id_292) {
                                                                  ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_294 { dsum1_snd_85.readU32Le() };
                                                                  ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_295;
                                                                  {
                                                                    auto du32_fst_301 { std::get<0>(id_294) };
                                                                    auto du32_snd_302 { std::get<1>(id_294) };
                                                                    std::function<uint32_t(uint32_t)> fun296 { [&fun296](uint32_t p_0) {
                                                                      return p_0;
                                                                    }
                                                                     };
                                                                    uint32_t id_297 { fun296(du32_fst_301) };
                                                                    ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_298 { id_297, du32_snd_302 };
                                                                    letpair_res_295 = id_298;
                                                                  }
                                                                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b let_res_299;
                                                                  {
                                                                    ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 drec_306 { letpair_res_295 };
                                                                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_300;
                                                                    {
                                                                      auto drec_fst_307 { std::get<0>(drec_306) };
                                                                      auto drec_snd_308 { std::get<1>(drec_306) };
                                                                      ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_301 { drec_snd_308.readU8() };
                                                                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_302;
                                                                      {
                                                                        auto du8_fst_310 { std::get<0>(id_301) };
                                                                        auto du8_snd_311 { std::get<1>(id_301) };
                                                                        std::function<::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982(::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982)> fun303 { [&fun303](::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_304 { drec_fst_307, du8_fst_310 };
                                                                        ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_305 { fun303(id_304) };
                                                                        std::shared_ptr<::dessser::gen::raql_value::t>  id_306 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<28>, id_305) };
                                                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_307 { id_306, du8_snd_311 };
                                                                        letpair_res_302 = id_307;
                                                                      }
                                                                      letpair_res_300 = letpair_res_302;
                                                                    }
                                                                    let_res_299 = letpair_res_300;
                                                                  }
                                                                  choose_res_293 = let_res_299;
                                                                } else {
                                                                  uint16_t id_308 { 29 };
                                                                  bool id_309 { bool(id_308 == dsum1_fst_84) };
                                                                  ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_310;
                                                                  if (id_309) {
                                                                    ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 id_311 { dsum1_snd_85.readU128Le() };
                                                                    ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 letpair_res_312;
                                                                    {
                                                                      auto di128_fst_280 { std::get<0>(id_311) };
                                                                      auto di128_snd_281 { std::get<1>(id_311) };
                                                                      std::function<uint128_t(uint128_t)> fun313 { [&fun313](uint128_t p_0) {
                                                                        return p_0;
                                                                      }
                                                                       };
                                                                      uint128_t id_314 { fun313(di128_fst_280) };
                                                                      ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 id_315 { id_314, di128_snd_281 };
                                                                      letpair_res_312 = id_315;
                                                                    }
                                                                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b let_res_316;
                                                                    {
                                                                      ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 drec_285 { letpair_res_312 };
                                                                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_317;
                                                                      {
                                                                        auto drec_fst_286 { std::get<0>(drec_285) };
                                                                        auto drec_snd_287 { std::get<1>(drec_285) };
                                                                        ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_318 { drec_snd_287.readU8() };
                                                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_319;
                                                                        {
                                                                          auto du8_fst_289 { std::get<0>(id_318) };
                                                                          auto du8_snd_290 { std::get<1>(id_318) };
                                                                          std::function<::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86(::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86)> fun320 { [&fun320](::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 p_0) {
                                                                            return p_0;
                                                                          }
                                                                           };
                                                                          ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_321 { drec_fst_286, du8_fst_289 };
                                                                          ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_322 { fun320(id_321) };
                                                                          std::shared_ptr<::dessser::gen::raql_value::t>  id_323 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<29>, id_322) };
                                                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_324 { id_323, du8_snd_290 };
                                                                          letpair_res_319 = id_324;
                                                                        }
                                                                        letpair_res_317 = letpair_res_319;
                                                                      }
                                                                      let_res_316 = letpair_res_317;
                                                                    }
                                                                    choose_res_310 = let_res_316;
                                                                  } else {
                                                                    uint16_t id_325 { 30 };
                                                                    bool id_326 { bool(id_325 == dsum1_fst_84) };
                                                                    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_327;
                                                                    if (id_326) {
                                                                      ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b id_328 { dsum1_snd_85.readU16Le() };
                                                                      ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b letpair_res_329;
                                                                      {
                                                                        auto du16_fst_223 { std::get<0>(id_328) };
                                                                        auto du16_snd_224 { std::get<1>(id_328) };
                                                                        ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b id_330 { du16_fst_223, du16_snd_224 };
                                                                        letpair_res_329 = id_330;
                                                                      }
                                                                      ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc let_res_331;
                                                                      {
                                                                        ::dessser::gen::raql_value::t7609d344c1ba69d0f80fec236d4c216b dsum1_228 { letpair_res_329 };
                                                                        ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc letpair_res_332;
                                                                        {
                                                                          auto dsum1_fst_229 { std::get<0>(dsum1_228) };
                                                                          auto dsum1_snd_230 { std::get<1>(dsum1_228) };
                                                                          uint16_t id_333 { 0 };
                                                                          bool id_334 { bool(id_333 == dsum1_fst_229) };
                                                                          ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc choose_res_335;
                                                                          if (id_334) {
                                                                            ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_336 { dsum1_snd_230.readU32Le() };
                                                                            ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_337;
                                                                            {
                                                                              auto du32_fst_253 { std::get<0>(id_336) };
                                                                              auto du32_snd_254 { std::get<1>(id_336) };
                                                                              std::function<uint32_t(uint32_t)> fun338 { [&fun338](uint32_t p_0) {
                                                                                return p_0;
                                                                              }
                                                                               };
                                                                              uint32_t id_339 { fun338(du32_fst_253) };
                                                                              ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_340 { id_339, du32_snd_254 };
                                                                              letpair_res_337 = id_340;
                                                                            }
                                                                            ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc let_res_341;
                                                                            {
                                                                              ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 drec_258 { letpair_res_337 };
                                                                              ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc letpair_res_342;
                                                                              {
                                                                                auto drec_fst_259 { std::get<0>(drec_258) };
                                                                                auto drec_snd_260 { std::get<1>(drec_258) };
                                                                                ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_343 { drec_snd_260.readU8() };
                                                                                ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc letpair_res_344;
                                                                                {
                                                                                  auto du8_fst_262 { std::get<0>(id_343) };
                                                                                  auto du8_snd_263 { std::get<1>(id_343) };
                                                                                  std::function<::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982(::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982)> fun345 { [&fun345](::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 p_0) {
                                                                                    return p_0;
                                                                                  }
                                                                                   };
                                                                                  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_346 { drec_fst_259, du8_fst_262 };
                                                                                  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_347 { fun345(id_346) };
                                                                                  ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_348 { std::in_place_index<0>, id_347 };
                                                                                  ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc id_349 { id_348, du8_snd_263 };
                                                                                  letpair_res_344 = id_349;
                                                                                }
                                                                                letpair_res_342 = letpair_res_344;
                                                                              }
                                                                              let_res_341 = letpair_res_342;
                                                                            }
                                                                            choose_res_335 = let_res_341;
                                                                          } else {
                                                                            uint16_t id_350 { 1 };
                                                                            bool id_351 { bool(dsum1_fst_229 == id_350) };
                                                                            Void id_352 { ((void)(assert(id_351)), ::dessser::VOID) };
                                                                            (void)id_352;
                                                                            ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 id_353 { dsum1_snd_230.readU128Le() };
                                                                            ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 letpair_res_354;
                                                                            {
                                                                              auto di128_fst_232 { std::get<0>(id_353) };
                                                                              auto di128_snd_233 { std::get<1>(id_353) };
                                                                              std::function<uint128_t(uint128_t)> fun355 { [&fun355](uint128_t p_0) {
                                                                                return p_0;
                                                                              }
                                                                               };
                                                                              uint128_t id_356 { fun355(di128_fst_232) };
                                                                              ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 id_357 { id_356, di128_snd_233 };
                                                                              letpair_res_354 = id_357;
                                                                            }
                                                                            ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc let_res_358;
                                                                            {
                                                                              ::dessser::gen::raql_value::t9e0ebd3dfe4817b98136c6e6b20afc92 drec_237 { letpair_res_354 };
                                                                              ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc letpair_res_359;
                                                                              {
                                                                                auto drec_fst_238 { std::get<0>(drec_237) };
                                                                                auto drec_snd_239 { std::get<1>(drec_237) };
                                                                                ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_360 { drec_snd_239.readU8() };
                                                                                ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc letpair_res_361;
                                                                                {
                                                                                  auto du8_fst_241 { std::get<0>(id_360) };
                                                                                  auto du8_snd_242 { std::get<1>(id_360) };
                                                                                  std::function<::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86(::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86)> fun362 { [&fun362](::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 p_0) {
                                                                                    return p_0;
                                                                                  }
                                                                                   };
                                                                                  ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_363 { drec_fst_238, du8_fst_241 };
                                                                                  ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_364 { fun362(id_363) };
                                                                                  ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_365 { std::in_place_index<1>, id_364 };
                                                                                  ::dessser::gen::raql_value::t67fcf630ffd97c208644a466f20c16dc id_366 { id_365, du8_snd_242 };
                                                                                  letpair_res_361 = id_366;
                                                                                }
                                                                                letpair_res_359 = letpair_res_361;
                                                                              }
                                                                              let_res_358 = letpair_res_359;
                                                                            }
                                                                            choose_res_335 = let_res_358;
                                                                          }
                                                                          letpair_res_332 = choose_res_335;
                                                                        }
                                                                        let_res_331 = letpair_res_332;
                                                                      }
                                                                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_367;
                                                                      {
                                                                        auto des_usr_type_fst_274 { std::get<0>(let_res_331) };
                                                                        auto des_usr_type_snd_275 { std::get<1>(let_res_331) };
                                                                        std::function<::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27(::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27)> fun368 { [&fun368](::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 p_0) {
                                                                          return p_0;
                                                                        }
                                                                         };
                                                                        ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_369 { fun368(des_usr_type_fst_274) };
                                                                        std::shared_ptr<::dessser::gen::raql_value::t>  id_370 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<30>, id_369) };
                                                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_371 { id_370, des_usr_type_snd_275 };
                                                                        letpair_res_367 = id_371;
                                                                      }
                                                                      choose_res_327 = letpair_res_367;
                                                                    } else {
                                                                      uint16_t id_372 { 31 };
                                                                      bool id_373 { bool(id_372 == dsum1_fst_84) };
                                                                      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_374;
                                                                      if (id_373) {
                                                                        uint32_t id_375 { 0U };
                                                                        Vec<1, uint32_t> id_376 {  id_375  };
                                                                        ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_377;
                                                                        {
                                                                          Vec<1, uint32_t> leb_ref_196 { id_376 };
                                                                          uint8_t id_378 { 0 };
                                                                          Vec<1, uint8_t> id_379 {  id_378  };
                                                                          ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_380;
                                                                          {
                                                                            Vec<1, uint8_t> shft_ref_197 { id_379 };
                                                                            Vec<1, Pointer> id_381 {  dsum1_snd_85  };
                                                                            ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_382;
                                                                            {
                                                                              Vec<1, Pointer> p_ref_198 { id_381 };
                                                                              bool while_flag_383 { true };
                                                                              do {
                                                                                uint8_t id_384 { 0 };
                                                                                Pointer id_385 { p_ref_198[id_384] };
                                                                                ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_386 { id_385.readU8() };
                                                                                bool let_res_387;
                                                                                {
                                                                                  ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_199 { id_386 };
                                                                                  bool letpair_res_388;
                                                                                  {
                                                                                    auto leb128_fst_200 { std::get<0>(leb128_199) };
                                                                                    auto leb128_snd_201 { std::get<1>(leb128_199) };
                                                                                    uint8_t id_389 { 0 };
                                                                                    Void id_390 { ((void)(p_ref_198[id_389] = leb128_snd_201), ::dessser::VOID) };
                                                                                    (void)id_390;
                                                                                    uint8_t id_391 { 0 };
                                                                                    uint8_t id_392 { 127 };
                                                                                    uint8_t id_393 { uint8_t(leb128_fst_200 & id_392) };
                                                                                    uint32_t id_394 { uint32_t(id_393) };
                                                                                    uint8_t id_395 { 0 };
                                                                                    uint8_t id_396 { shft_ref_197[id_395] };
                                                                                    uint32_t id_397 { uint32_t(id_394 << id_396) };
                                                                                    uint8_t id_398 { 0 };
                                                                                    uint32_t id_399 { leb_ref_196[id_398] };
                                                                                    uint32_t id_400 { uint32_t(id_397 | id_399) };
                                                                                    Void id_401 { ((void)(leb_ref_196[id_391] = id_400), ::dessser::VOID) };
                                                                                    (void)id_401;
                                                                                    uint8_t id_402 { 0 };
                                                                                    uint8_t id_403 { 0 };
                                                                                    uint8_t id_404 { shft_ref_197[id_403] };
                                                                                    uint8_t id_405 { 7 };
                                                                                    uint8_t id_406 { uint8_t(id_404 + id_405) };
                                                                                    Void id_407 { ((void)(shft_ref_197[id_402] = id_406), ::dessser::VOID) };
                                                                                    (void)id_407;
                                                                                    uint8_t id_408 { 128 };
                                                                                    bool id_409 { bool(leb128_fst_200 >= id_408) };
                                                                                    letpair_res_388 = id_409;
                                                                                  }
                                                                                  let_res_387 = letpair_res_388;
                                                                                }
                                                                                while_flag_383 = let_res_387;
                                                                                if (while_flag_383) {
                                                                                  (void)::dessser::VOID;
                                                                                }
                                                                              } while (while_flag_383);
                                                                              (void)::dessser::VOID;
                                                                              uint8_t id_410 { 0 };
                                                                              uint32_t id_411 { leb_ref_196[id_410] };
                                                                              uint8_t id_412 { 0 };
                                                                              Pointer id_413 { p_ref_198[id_412] };
                                                                              ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_414 { id_411, id_413 };
                                                                              let_res_382 = id_414;
                                                                            }
                                                                            let_res_380 = let_res_382;
                                                                          }
                                                                          let_res_377 = let_res_380;
                                                                        }
                                                                        ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 let_res_415;
                                                                        {
                                                                          ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 dlist1_205 { let_res_377 };
                                                                          ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 letpair_res_416;
                                                                          {
                                                                            auto dlist1_fst_206 { std::get<0>(dlist1_205) };
                                                                            auto dlist1_snd_207 { std::get<1>(dlist1_205) };
                                                                            Lst<std::shared_ptr<::dessser::gen::raql_value::t> > endoflist_417;
                                                                            ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_418 { endoflist_417, dlist1_snd_207 };
                                                                            Vec<1, ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24> id_419 {  id_418  };
                                                                            ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 let_res_420;
                                                                            {
                                                                              Vec<1, ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24> inits_src_ref_208 { id_419 };
                                                                              int32_t id_421 { 0L };
                                                                              Vec<1, int32_t> id_422 {  id_421  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_209 { id_422 };
                                                                                bool while_flag_423 { true };
                                                                                do {
                                                                                  int32_t id_424 { int32_t(dlist1_fst_206) };
                                                                                  uint8_t id_425 { 0 };
                                                                                  int32_t id_426 { repeat_n_209[id_425] };
                                                                                  bool id_427 { bool(id_424 > id_426) };
                                                                                  while_flag_423 = id_427;
                                                                                  if (while_flag_423) {
                                                                                    uint8_t id_428 { 0 };
                                                                                    ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_429 { inits_src_ref_208[id_428] };
                                                                                    {
                                                                                      ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 dlist2_210 { id_429 };
                                                                                      {
                                                                                        auto dlist2_fst_211 { std::get<0>(dlist2_210) };
                                                                                        auto dlist2_snd_212 { std::get<1>(dlist2_210) };
                                                                                        uint8_t id_430 { 0 };
                                                                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_431 { fun0(dlist2_snd_212) };
                                                                                        ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 letpair_res_432;
                                                                                        {
                                                                                          auto dlist3_fst_214 { std::get<0>(id_431) };
                                                                                          auto dlist3_snd_215 { std::get<1>(id_431) };
                                                                                          Lst<std::shared_ptr<::dessser::gen::raql_value::t> > id_433 { dlist3_fst_214, dlist2_fst_211 };
                                                                                          ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_434 { id_433, dlist3_snd_215 };
                                                                                          letpair_res_432 = id_434;
                                                                                        }
                                                                                        Void id_435 { ((void)(inits_src_ref_208[id_430] = letpair_res_432), ::dessser::VOID) };
                                                                                        (void)id_435;
                                                                                      }
                                                                                      (void)::dessser::VOID;
                                                                                    }
                                                                                    (void)::dessser::VOID;
                                                                                    uint8_t id_436 { 0 };
                                                                                    uint8_t id_437 { 0 };
                                                                                    int32_t id_438 { repeat_n_209[id_437] };
                                                                                    int32_t id_439 { 1L };
                                                                                    int32_t id_440 { int32_t(id_438 + id_439) };
                                                                                    Void id_441 { ((void)(repeat_n_209[id_436] = id_440), ::dessser::VOID) };
                                                                                    (void)id_441;
                                                                                    (void)id_441;
                                                                                  }
                                                                                } while (while_flag_423);
                                                                                (void)::dessser::VOID;
                                                                              }
                                                                              (void)::dessser::VOID;
                                                                              uint8_t id_442 { 0 };
                                                                              ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_443 { inits_src_ref_208[id_442] };
                                                                              let_res_420 = id_443;
                                                                            }
                                                                            letpair_res_416 = let_res_420;
                                                                          }
                                                                          let_res_415 = letpair_res_416;
                                                                        }
                                                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_444;
                                                                        {
                                                                          auto dlist4_fst_217 { std::get<0>(let_res_415) };
                                                                          auto dlist4_snd_218 { std::get<1>(let_res_415) };
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_445 { dlist4_fst_217.toListRev() };
                                                                          std::shared_ptr<::dessser::gen::raql_value::t>  id_446 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<31>, id_445) };
                                                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_447 { id_446, dlist4_snd_218 };
                                                                          letpair_res_444 = id_447;
                                                                        }
                                                                        choose_res_374 = letpair_res_444;
                                                                      } else {
                                                                        uint16_t id_448 { 32 };
                                                                        bool id_449 { bool(id_448 == dsum1_fst_84) };
                                                                        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_450;
                                                                        if (id_449) {
                                                                          uint32_t id_451 { 0U };
                                                                          Vec<1, uint32_t> id_452 {  id_451  };
                                                                          ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_453;
                                                                          {
                                                                            Vec<1, uint32_t> leb_ref_170 { id_452 };
                                                                            uint8_t id_454 { 0 };
                                                                            Vec<1, uint8_t> id_455 {  id_454  };
                                                                            ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_456;
                                                                            {
                                                                              Vec<1, uint8_t> shft_ref_171 { id_455 };
                                                                              Vec<1, Pointer> id_457 {  dsum1_snd_85  };
                                                                              ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_458;
                                                                              {
                                                                                Vec<1, Pointer> p_ref_172 { id_457 };
                                                                                bool while_flag_459 { true };
                                                                                do {
                                                                                  uint8_t id_460 { 0 };
                                                                                  Pointer id_461 { p_ref_172[id_460] };
                                                                                  ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_462 { id_461.readU8() };
                                                                                  bool let_res_463;
                                                                                  {
                                                                                    ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_173 { id_462 };
                                                                                    bool letpair_res_464;
                                                                                    {
                                                                                      auto leb128_fst_174 { std::get<0>(leb128_173) };
                                                                                      auto leb128_snd_175 { std::get<1>(leb128_173) };
                                                                                      uint8_t id_465 { 0 };
                                                                                      Void id_466 { ((void)(p_ref_172[id_465] = leb128_snd_175), ::dessser::VOID) };
                                                                                      (void)id_466;
                                                                                      uint8_t id_467 { 0 };
                                                                                      uint8_t id_468 { 127 };
                                                                                      uint8_t id_469 { uint8_t(leb128_fst_174 & id_468) };
                                                                                      uint32_t id_470 { uint32_t(id_469) };
                                                                                      uint8_t id_471 { 0 };
                                                                                      uint8_t id_472 { shft_ref_171[id_471] };
                                                                                      uint32_t id_473 { uint32_t(id_470 << id_472) };
                                                                                      uint8_t id_474 { 0 };
                                                                                      uint32_t id_475 { leb_ref_170[id_474] };
                                                                                      uint32_t id_476 { uint32_t(id_473 | id_475) };
                                                                                      Void id_477 { ((void)(leb_ref_170[id_467] = id_476), ::dessser::VOID) };
                                                                                      (void)id_477;
                                                                                      uint8_t id_478 { 0 };
                                                                                      uint8_t id_479 { 0 };
                                                                                      uint8_t id_480 { shft_ref_171[id_479] };
                                                                                      uint8_t id_481 { 7 };
                                                                                      uint8_t id_482 { uint8_t(id_480 + id_481) };
                                                                                      Void id_483 { ((void)(shft_ref_171[id_478] = id_482), ::dessser::VOID) };
                                                                                      (void)id_483;
                                                                                      uint8_t id_484 { 128 };
                                                                                      bool id_485 { bool(leb128_fst_174 >= id_484) };
                                                                                      letpair_res_464 = id_485;
                                                                                    }
                                                                                    let_res_463 = letpair_res_464;
                                                                                  }
                                                                                  while_flag_459 = let_res_463;
                                                                                  if (while_flag_459) {
                                                                                    (void)::dessser::VOID;
                                                                                  }
                                                                                } while (while_flag_459);
                                                                                (void)::dessser::VOID;
                                                                                uint8_t id_486 { 0 };
                                                                                uint32_t id_487 { leb_ref_170[id_486] };
                                                                                uint8_t id_488 { 0 };
                                                                                Pointer id_489 { p_ref_172[id_488] };
                                                                                ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_490 { id_487, id_489 };
                                                                                let_res_458 = id_490;
                                                                              }
                                                                              let_res_456 = let_res_458;
                                                                            }
                                                                            let_res_453 = let_res_456;
                                                                          }
                                                                          ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 let_res_491;
                                                                          {
                                                                            ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 dlist1_179 { let_res_453 };
                                                                            ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 letpair_res_492;
                                                                            {
                                                                              auto dlist1_fst_180 { std::get<0>(dlist1_179) };
                                                                              auto dlist1_snd_181 { std::get<1>(dlist1_179) };
                                                                              Lst<std::shared_ptr<::dessser::gen::raql_value::t> > endoflist_493;
                                                                              ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_494 { endoflist_493, dlist1_snd_181 };
                                                                              Vec<1, ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24> id_495 {  id_494  };
                                                                              ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 let_res_496;
                                                                              {
                                                                                Vec<1, ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24> inits_src_ref_182 { id_495 };
                                                                                int32_t id_497 { 0L };
                                                                                Vec<1, int32_t> id_498 {  id_497  };
                                                                                {
                                                                                  Vec<1, int32_t> repeat_n_183 { id_498 };
                                                                                  bool while_flag_499 { true };
                                                                                  do {
                                                                                    int32_t id_500 { int32_t(dlist1_fst_180) };
                                                                                    uint8_t id_501 { 0 };
                                                                                    int32_t id_502 { repeat_n_183[id_501] };
                                                                                    bool id_503 { bool(id_500 > id_502) };
                                                                                    while_flag_499 = id_503;
                                                                                    if (while_flag_499) {
                                                                                      uint8_t id_504 { 0 };
                                                                                      ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_505 { inits_src_ref_182[id_504] };
                                                                                      {
                                                                                        ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 dlist2_184 { id_505 };
                                                                                        {
                                                                                          auto dlist2_fst_185 { std::get<0>(dlist2_184) };
                                                                                          auto dlist2_snd_186 { std::get<1>(dlist2_184) };
                                                                                          uint8_t id_506 { 0 };
                                                                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_507 { fun0(dlist2_snd_186) };
                                                                                          ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 letpair_res_508;
                                                                                          {
                                                                                            auto dlist3_fst_188 { std::get<0>(id_507) };
                                                                                            auto dlist3_snd_189 { std::get<1>(id_507) };
                                                                                            Lst<std::shared_ptr<::dessser::gen::raql_value::t> > id_509 { dlist3_fst_188, dlist2_fst_185 };
                                                                                            ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_510 { id_509, dlist3_snd_189 };
                                                                                            letpair_res_508 = id_510;
                                                                                          }
                                                                                          Void id_511 { ((void)(inits_src_ref_182[id_506] = letpair_res_508), ::dessser::VOID) };
                                                                                          (void)id_511;
                                                                                        }
                                                                                        (void)::dessser::VOID;
                                                                                      }
                                                                                      (void)::dessser::VOID;
                                                                                      uint8_t id_512 { 0 };
                                                                                      uint8_t id_513 { 0 };
                                                                                      int32_t id_514 { repeat_n_183[id_513] };
                                                                                      int32_t id_515 { 1L };
                                                                                      int32_t id_516 { int32_t(id_514 + id_515) };
                                                                                      Void id_517 { ((void)(repeat_n_183[id_512] = id_516), ::dessser::VOID) };
                                                                                      (void)id_517;
                                                                                      (void)id_517;
                                                                                    }
                                                                                  } while (while_flag_499);
                                                                                  (void)::dessser::VOID;
                                                                                }
                                                                                (void)::dessser::VOID;
                                                                                uint8_t id_518 { 0 };
                                                                                ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_519 { inits_src_ref_182[id_518] };
                                                                                let_res_496 = id_519;
                                                                              }
                                                                              letpair_res_492 = let_res_496;
                                                                            }
                                                                            let_res_491 = letpair_res_492;
                                                                          }
                                                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_520;
                                                                          {
                                                                            auto dlist4_fst_191 { std::get<0>(let_res_491) };
                                                                            auto dlist4_snd_192 { std::get<1>(let_res_491) };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_521 { dlist4_fst_191.toListRev() };
                                                                            std::shared_ptr<::dessser::gen::raql_value::t>  id_522 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<32>, id_521) };
                                                                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_523 { id_522, dlist4_snd_192 };
                                                                            letpair_res_520 = id_523;
                                                                          }
                                                                          choose_res_450 = letpair_res_520;
                                                                        } else {
                                                                          uint16_t id_524 { 33 };
                                                                          bool id_525 { bool(id_524 == dsum1_fst_84) };
                                                                          ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_526;
                                                                          if (id_525) {
                                                                            uint32_t id_527 { 0U };
                                                                            Vec<1, uint32_t> id_528 {  id_527  };
                                                                            ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_529;
                                                                            {
                                                                              Vec<1, uint32_t> leb_ref_144 { id_528 };
                                                                              uint8_t id_530 { 0 };
                                                                              Vec<1, uint8_t> id_531 {  id_530  };
                                                                              ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_532;
                                                                              {
                                                                                Vec<1, uint8_t> shft_ref_145 { id_531 };
                                                                                Vec<1, Pointer> id_533 {  dsum1_snd_85  };
                                                                                ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_534;
                                                                                {
                                                                                  Vec<1, Pointer> p_ref_146 { id_533 };
                                                                                  bool while_flag_535 { true };
                                                                                  do {
                                                                                    uint8_t id_536 { 0 };
                                                                                    Pointer id_537 { p_ref_146[id_536] };
                                                                                    ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_538 { id_537.readU8() };
                                                                                    bool let_res_539;
                                                                                    {
                                                                                      ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_147 { id_538 };
                                                                                      bool letpair_res_540;
                                                                                      {
                                                                                        auto leb128_fst_148 { std::get<0>(leb128_147) };
                                                                                        auto leb128_snd_149 { std::get<1>(leb128_147) };
                                                                                        uint8_t id_541 { 0 };
                                                                                        Void id_542 { ((void)(p_ref_146[id_541] = leb128_snd_149), ::dessser::VOID) };
                                                                                        (void)id_542;
                                                                                        uint8_t id_543 { 0 };
                                                                                        uint8_t id_544 { 127 };
                                                                                        uint8_t id_545 { uint8_t(leb128_fst_148 & id_544) };
                                                                                        uint32_t id_546 { uint32_t(id_545) };
                                                                                        uint8_t id_547 { 0 };
                                                                                        uint8_t id_548 { shft_ref_145[id_547] };
                                                                                        uint32_t id_549 { uint32_t(id_546 << id_548) };
                                                                                        uint8_t id_550 { 0 };
                                                                                        uint32_t id_551 { leb_ref_144[id_550] };
                                                                                        uint32_t id_552 { uint32_t(id_549 | id_551) };
                                                                                        Void id_553 { ((void)(leb_ref_144[id_543] = id_552), ::dessser::VOID) };
                                                                                        (void)id_553;
                                                                                        uint8_t id_554 { 0 };
                                                                                        uint8_t id_555 { 0 };
                                                                                        uint8_t id_556 { shft_ref_145[id_555] };
                                                                                        uint8_t id_557 { 7 };
                                                                                        uint8_t id_558 { uint8_t(id_556 + id_557) };
                                                                                        Void id_559 { ((void)(shft_ref_145[id_554] = id_558), ::dessser::VOID) };
                                                                                        (void)id_559;
                                                                                        uint8_t id_560 { 128 };
                                                                                        bool id_561 { bool(leb128_fst_148 >= id_560) };
                                                                                        letpair_res_540 = id_561;
                                                                                      }
                                                                                      let_res_539 = letpair_res_540;
                                                                                    }
                                                                                    while_flag_535 = let_res_539;
                                                                                    if (while_flag_535) {
                                                                                      (void)::dessser::VOID;
                                                                                    }
                                                                                  } while (while_flag_535);
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_562 { 0 };
                                                                                  uint32_t id_563 { leb_ref_144[id_562] };
                                                                                  uint8_t id_564 { 0 };
                                                                                  Pointer id_565 { p_ref_146[id_564] };
                                                                                  ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_566 { id_563, id_565 };
                                                                                  let_res_534 = id_566;
                                                                                }
                                                                                let_res_532 = let_res_534;
                                                                              }
                                                                              let_res_529 = let_res_532;
                                                                            }
                                                                            ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 let_res_567;
                                                                            {
                                                                              ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 dlist1_153 { let_res_529 };
                                                                              ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 letpair_res_568;
                                                                              {
                                                                                auto dlist1_fst_154 { std::get<0>(dlist1_153) };
                                                                                auto dlist1_snd_155 { std::get<1>(dlist1_153) };
                                                                                Lst<std::shared_ptr<::dessser::gen::raql_value::t> > endoflist_569;
                                                                                ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_570 { endoflist_569, dlist1_snd_155 };
                                                                                Vec<1, ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24> id_571 {  id_570  };
                                                                                ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 let_res_572;
                                                                                {
                                                                                  Vec<1, ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24> inits_src_ref_156 { id_571 };
                                                                                  int32_t id_573 { 0L };
                                                                                  Vec<1, int32_t> id_574 {  id_573  };
                                                                                  {
                                                                                    Vec<1, int32_t> repeat_n_157 { id_574 };
                                                                                    bool while_flag_575 { true };
                                                                                    do {
                                                                                      int32_t id_576 { int32_t(dlist1_fst_154) };
                                                                                      uint8_t id_577 { 0 };
                                                                                      int32_t id_578 { repeat_n_157[id_577] };
                                                                                      bool id_579 { bool(id_576 > id_578) };
                                                                                      while_flag_575 = id_579;
                                                                                      if (while_flag_575) {
                                                                                        uint8_t id_580 { 0 };
                                                                                        ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_581 { inits_src_ref_156[id_580] };
                                                                                        {
                                                                                          ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 dlist2_158 { id_581 };
                                                                                          {
                                                                                            auto dlist2_fst_159 { std::get<0>(dlist2_158) };
                                                                                            auto dlist2_snd_160 { std::get<1>(dlist2_158) };
                                                                                            uint8_t id_582 { 0 };
                                                                                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_583 { fun0(dlist2_snd_160) };
                                                                                            ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 letpair_res_584;
                                                                                            {
                                                                                              auto dlist3_fst_162 { std::get<0>(id_583) };
                                                                                              auto dlist3_snd_163 { std::get<1>(id_583) };
                                                                                              Lst<std::shared_ptr<::dessser::gen::raql_value::t> > id_585 { dlist3_fst_162, dlist2_fst_159 };
                                                                                              ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_586 { id_585, dlist3_snd_163 };
                                                                                              letpair_res_584 = id_586;
                                                                                            }
                                                                                            Void id_587 { ((void)(inits_src_ref_156[id_582] = letpair_res_584), ::dessser::VOID) };
                                                                                            (void)id_587;
                                                                                          }
                                                                                          (void)::dessser::VOID;
                                                                                        }
                                                                                        (void)::dessser::VOID;
                                                                                        uint8_t id_588 { 0 };
                                                                                        uint8_t id_589 { 0 };
                                                                                        int32_t id_590 { repeat_n_157[id_589] };
                                                                                        int32_t id_591 { 1L };
                                                                                        int32_t id_592 { int32_t(id_590 + id_591) };
                                                                                        Void id_593 { ((void)(repeat_n_157[id_588] = id_592), ::dessser::VOID) };
                                                                                        (void)id_593;
                                                                                        (void)id_593;
                                                                                      }
                                                                                    } while (while_flag_575);
                                                                                    (void)::dessser::VOID;
                                                                                  }
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_594 { 0 };
                                                                                  ::dessser::gen::raql_value::t9658b993bb9f5814bdb59e00050f3b24 id_595 { inits_src_ref_156[id_594] };
                                                                                  let_res_572 = id_595;
                                                                                }
                                                                                letpair_res_568 = let_res_572;
                                                                              }
                                                                              let_res_567 = letpair_res_568;
                                                                            }
                                                                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_596;
                                                                            {
                                                                              auto dlist4_fst_165 { std::get<0>(let_res_567) };
                                                                              auto dlist4_snd_166 { std::get<1>(let_res_567) };
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_597 { dlist4_fst_165.toListRev() };
                                                                              std::shared_ptr<::dessser::gen::raql_value::t>  id_598 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<33>, id_597) };
                                                                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_599 { id_598, dlist4_snd_166 };
                                                                              letpair_res_596 = id_599;
                                                                            }
                                                                            choose_res_526 = letpair_res_596;
                                                                          } else {
                                                                            uint16_t id_600 { 34 };
                                                                            bool id_601 { bool(id_600 == dsum1_fst_84) };
                                                                            ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b choose_res_602;
                                                                            if (id_601) {
                                                                              uint32_t id_603 { 0U };
                                                                              Vec<1, uint32_t> id_604 {  id_603  };
                                                                              ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_605;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_118 { id_604 };
                                                                                uint8_t id_606 { 0 };
                                                                                Vec<1, uint8_t> id_607 {  id_606  };
                                                                                ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_608;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_119 { id_607 };
                                                                                  Vec<1, Pointer> id_609 {  dsum1_snd_85  };
                                                                                  ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_610;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_120 { id_609 };
                                                                                    bool while_flag_611 { true };
                                                                                    do {
                                                                                      uint8_t id_612 { 0 };
                                                                                      Pointer id_613 { p_ref_120[id_612] };
                                                                                      ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_614 { id_613.readU8() };
                                                                                      bool let_res_615;
                                                                                      {
                                                                                        ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_121 { id_614 };
                                                                                        bool letpair_res_616;
                                                                                        {
                                                                                          auto leb128_fst_122 { std::get<0>(leb128_121) };
                                                                                          auto leb128_snd_123 { std::get<1>(leb128_121) };
                                                                                          uint8_t id_617 { 0 };
                                                                                          Void id_618 { ((void)(p_ref_120[id_617] = leb128_snd_123), ::dessser::VOID) };
                                                                                          (void)id_618;
                                                                                          uint8_t id_619 { 0 };
                                                                                          uint8_t id_620 { 127 };
                                                                                          uint8_t id_621 { uint8_t(leb128_fst_122 & id_620) };
                                                                                          uint32_t id_622 { uint32_t(id_621) };
                                                                                          uint8_t id_623 { 0 };
                                                                                          uint8_t id_624 { shft_ref_119[id_623] };
                                                                                          uint32_t id_625 { uint32_t(id_622 << id_624) };
                                                                                          uint8_t id_626 { 0 };
                                                                                          uint32_t id_627 { leb_ref_118[id_626] };
                                                                                          uint32_t id_628 { uint32_t(id_625 | id_627) };
                                                                                          Void id_629 { ((void)(leb_ref_118[id_619] = id_628), ::dessser::VOID) };
                                                                                          (void)id_629;
                                                                                          uint8_t id_630 { 0 };
                                                                                          uint8_t id_631 { 0 };
                                                                                          uint8_t id_632 { shft_ref_119[id_631] };
                                                                                          uint8_t id_633 { 7 };
                                                                                          uint8_t id_634 { uint8_t(id_632 + id_633) };
                                                                                          Void id_635 { ((void)(shft_ref_119[id_630] = id_634), ::dessser::VOID) };
                                                                                          (void)id_635;
                                                                                          uint8_t id_636 { 128 };
                                                                                          bool id_637 { bool(leb128_fst_122 >= id_636) };
                                                                                          letpair_res_616 = id_637;
                                                                                        }
                                                                                        let_res_615 = letpair_res_616;
                                                                                      }
                                                                                      while_flag_611 = let_res_615;
                                                                                      if (while_flag_611) {
                                                                                        (void)::dessser::VOID;
                                                                                      }
                                                                                    } while (while_flag_611);
                                                                                    (void)::dessser::VOID;
                                                                                    uint8_t id_638 { 0 };
                                                                                    uint32_t id_639 { leb_ref_118[id_638] };
                                                                                    uint8_t id_640 { 0 };
                                                                                    Pointer id_641 { p_ref_120[id_640] };
                                                                                    ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_642 { id_639, id_641 };
                                                                                    let_res_610 = id_642;
                                                                                  }
                                                                                  let_res_608 = let_res_610;
                                                                                }
                                                                                let_res_605 = let_res_608;
                                                                              }
                                                                              ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e let_res_643;
                                                                              {
                                                                                ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 dlist1_127 { let_res_605 };
                                                                                ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e letpair_res_644;
                                                                                {
                                                                                  auto dlist1_fst_128 { std::get<0>(dlist1_127) };
                                                                                  auto dlist1_snd_129 { std::get<1>(dlist1_127) };
                                                                                  Lst<std::shared_ptr<::dessser::gen::raql_value::named_value> > endoflist_645;
                                                                                  ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e id_646 { endoflist_645, dlist1_snd_129 };
                                                                                  Vec<1, ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e> id_647 {  id_646  };
                                                                                  ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e let_res_648;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e> inits_src_ref_130 { id_647 };
                                                                                    int32_t id_649 { 0L };
                                                                                    Vec<1, int32_t> id_650 {  id_649  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_131 { id_650 };
                                                                                      bool while_flag_651 { true };
                                                                                      do {
                                                                                        int32_t id_652 { int32_t(dlist1_fst_128) };
                                                                                        uint8_t id_653 { 0 };
                                                                                        int32_t id_654 { repeat_n_131[id_653] };
                                                                                        bool id_655 { bool(id_652 > id_654) };
                                                                                        while_flag_651 = id_655;
                                                                                        if (while_flag_651) {
                                                                                          uint8_t id_656 { 0 };
                                                                                          ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e id_657 { inits_src_ref_130[id_656] };
                                                                                          {
                                                                                            ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e dlist2_132 { id_657 };
                                                                                            {
                                                                                              auto dlist2_fst_133 { std::get<0>(dlist2_132) };
                                                                                              auto dlist2_snd_134 { std::get<1>(dlist2_132) };
                                                                                              uint8_t id_658 { 0 };
                                                                                              ::dessser::gen::raql_value::t0c870624fb83311f54db2c065f542418 id_659 { named_value_of_row_binary(dlist2_snd_134) };
                                                                                              ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e letpair_res_660;
                                                                                              {
                                                                                                auto dlist3_fst_136 { std::get<0>(id_659) };
                                                                                                auto dlist3_snd_137 { std::get<1>(id_659) };
                                                                                                Lst<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_661 { dlist3_fst_136, dlist2_fst_133 };
                                                                                                ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e id_662 { id_661, dlist3_snd_137 };
                                                                                                letpair_res_660 = id_662;
                                                                                              }
                                                                                              Void id_663 { ((void)(inits_src_ref_130[id_658] = letpair_res_660), ::dessser::VOID) };
                                                                                              (void)id_663;
                                                                                            }
                                                                                            (void)::dessser::VOID;
                                                                                          }
                                                                                          (void)::dessser::VOID;
                                                                                          uint8_t id_664 { 0 };
                                                                                          uint8_t id_665 { 0 };
                                                                                          int32_t id_666 { repeat_n_131[id_665] };
                                                                                          int32_t id_667 { 1L };
                                                                                          int32_t id_668 { int32_t(id_666 + id_667) };
                                                                                          Void id_669 { ((void)(repeat_n_131[id_664] = id_668), ::dessser::VOID) };
                                                                                          (void)id_669;
                                                                                          (void)id_669;
                                                                                        }
                                                                                      } while (while_flag_651);
                                                                                      (void)::dessser::VOID;
                                                                                    }
                                                                                    (void)::dessser::VOID;
                                                                                    uint8_t id_670 { 0 };
                                                                                    ::dessser::gen::raql_value::t5acf4e40a97d10bb414b149b4987167e id_671 { inits_src_ref_130[id_670] };
                                                                                    let_res_648 = id_671;
                                                                                  }
                                                                                  letpair_res_644 = let_res_648;
                                                                                }
                                                                                let_res_643 = letpair_res_644;
                                                                              }
                                                                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_672;
                                                                              {
                                                                                auto dlist4_fst_139 { std::get<0>(let_res_643) };
                                                                                auto dlist4_snd_140 { std::get<1>(let_res_643) };
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_673 { dlist4_fst_139.toListRev() };
                                                                                std::shared_ptr<::dessser::gen::raql_value::t>  id_674 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<34>, id_673) };
                                                                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_675 { id_674, dlist4_snd_140 };
                                                                                letpair_res_672 = id_675;
                                                                              }
                                                                              choose_res_602 = letpair_res_672;
                                                                            } else {
                                                                              uint16_t id_676 { 35 };
                                                                              bool id_677 { bool(dsum1_fst_84 == id_676) };
                                                                              Void id_678 { ((void)(assert(id_677)), ::dessser::VOID) };
                                                                              (void)id_678;
                                                                              uint32_t id_679 { 0U };
                                                                              Vec<1, uint32_t> id_680 {  id_679  };
                                                                              ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_681;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_86 { id_680 };
                                                                                uint8_t id_682 { 0 };
                                                                                Vec<1, uint8_t> id_683 {  id_682  };
                                                                                ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_684;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_87 { id_683 };
                                                                                  Vec<1, Pointer> id_685 {  dsum1_snd_85  };
                                                                                  ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 let_res_686;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_88 { id_685 };
                                                                                    bool while_flag_687 { true };
                                                                                    do {
                                                                                      uint8_t id_688 { 0 };
                                                                                      Pointer id_689 { p_ref_88[id_688] };
                                                                                      ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_690 { id_689.readU8() };
                                                                                      bool let_res_691;
                                                                                      {
                                                                                        ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_89 { id_690 };
                                                                                        bool letpair_res_692;
                                                                                        {
                                                                                          auto leb128_fst_90 { std::get<0>(leb128_89) };
                                                                                          auto leb128_snd_91 { std::get<1>(leb128_89) };
                                                                                          uint8_t id_693 { 0 };
                                                                                          Void id_694 { ((void)(p_ref_88[id_693] = leb128_snd_91), ::dessser::VOID) };
                                                                                          (void)id_694;
                                                                                          uint8_t id_695 { 0 };
                                                                                          uint8_t id_696 { 127 };
                                                                                          uint8_t id_697 { uint8_t(leb128_fst_90 & id_696) };
                                                                                          uint32_t id_698 { uint32_t(id_697) };
                                                                                          uint8_t id_699 { 0 };
                                                                                          uint8_t id_700 { shft_ref_87[id_699] };
                                                                                          uint32_t id_701 { uint32_t(id_698 << id_700) };
                                                                                          uint8_t id_702 { 0 };
                                                                                          uint32_t id_703 { leb_ref_86[id_702] };
                                                                                          uint32_t id_704 { uint32_t(id_701 | id_703) };
                                                                                          Void id_705 { ((void)(leb_ref_86[id_695] = id_704), ::dessser::VOID) };
                                                                                          (void)id_705;
                                                                                          uint8_t id_706 { 0 };
                                                                                          uint8_t id_707 { 0 };
                                                                                          uint8_t id_708 { shft_ref_87[id_707] };
                                                                                          uint8_t id_709 { 7 };
                                                                                          uint8_t id_710 { uint8_t(id_708 + id_709) };
                                                                                          Void id_711 { ((void)(shft_ref_87[id_706] = id_710), ::dessser::VOID) };
                                                                                          (void)id_711;
                                                                                          uint8_t id_712 { 128 };
                                                                                          bool id_713 { bool(leb128_fst_90 >= id_712) };
                                                                                          letpair_res_692 = id_713;
                                                                                        }
                                                                                        let_res_691 = letpair_res_692;
                                                                                      }
                                                                                      while_flag_687 = let_res_691;
                                                                                      if (while_flag_687) {
                                                                                        (void)::dessser::VOID;
                                                                                      }
                                                                                    } while (while_flag_687);
                                                                                    (void)::dessser::VOID;
                                                                                    uint8_t id_714 { 0 };
                                                                                    uint32_t id_715 { leb_ref_86[id_714] };
                                                                                    uint8_t id_716 { 0 };
                                                                                    Pointer id_717 { p_ref_88[id_716] };
                                                                                    ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 id_718 { id_715, id_717 };
                                                                                    let_res_686 = id_718;
                                                                                  }
                                                                                  let_res_684 = let_res_686;
                                                                                }
                                                                                let_res_681 = let_res_684;
                                                                              }
                                                                              ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421 let_res_719;
                                                                              {
                                                                                ::dessser::gen::raql_value::t883c6ffea47c0d7b950fe35881e3d737 dlist1_95 { let_res_681 };
                                                                                ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421 letpair_res_720;
                                                                                {
                                                                                  auto dlist1_fst_96 { std::get<0>(dlist1_95) };
                                                                                  auto dlist1_snd_97 { std::get<1>(dlist1_95) };
                                                                                  Lst<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d> endoflist_721;
                                                                                  ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421 id_722 { endoflist_721, dlist1_snd_97 };
                                                                                  Vec<1, ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421> id_723 {  id_722  };
                                                                                  ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421 let_res_724;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421> inits_src_ref_98 { id_723 };
                                                                                    int32_t id_725 { 0L };
                                                                                    Vec<1, int32_t> id_726 {  id_725  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_99 { id_726 };
                                                                                      bool while_flag_727 { true };
                                                                                      do {
                                                                                        int32_t id_728 { int32_t(dlist1_fst_96) };
                                                                                        uint8_t id_729 { 0 };
                                                                                        int32_t id_730 { repeat_n_99[id_729] };
                                                                                        bool id_731 { bool(id_728 > id_730) };
                                                                                        while_flag_727 = id_731;
                                                                                        if (while_flag_727) {
                                                                                          uint8_t id_732 { 0 };
                                                                                          ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421 id_733 { inits_src_ref_98[id_732] };
                                                                                          {
                                                                                            ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421 dlist2_100 { id_733 };
                                                                                            {
                                                                                              auto dlist2_fst_101 { std::get<0>(dlist2_100) };
                                                                                              auto dlist2_snd_102 { std::get<1>(dlist2_100) };
                                                                                              uint8_t id_734 { 0 };
                                                                                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_735 { fun0(dlist2_snd_102) };
                                                                                              ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421 letpair_res_736;
                                                                                              {
                                                                                                auto dtup_fst_104 { std::get<0>(id_735) };
                                                                                                auto dtup_snd_105 { std::get<1>(id_735) };
                                                                                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_737 { fun0(dtup_snd_105) };
                                                                                                ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421 letpair_res_738;
                                                                                                {
                                                                                                  auto dtup_fst_107 { std::get<0>(id_737) };
                                                                                                  auto dtup_snd_108 { std::get<1>(id_737) };
                                                                                                  ::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d id_739 { dtup_fst_104, dtup_fst_107 };
                                                                                                  Lst<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d> id_740 { id_739, dlist2_fst_101 };
                                                                                                  ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421 id_741 { id_740, dtup_snd_108 };
                                                                                                  letpair_res_738 = id_741;
                                                                                                }
                                                                                                letpair_res_736 = letpair_res_738;
                                                                                              }
                                                                                              Void id_742 { ((void)(inits_src_ref_98[id_734] = letpair_res_736), ::dessser::VOID) };
                                                                                              (void)id_742;
                                                                                            }
                                                                                            (void)::dessser::VOID;
                                                                                          }
                                                                                          (void)::dessser::VOID;
                                                                                          uint8_t id_743 { 0 };
                                                                                          uint8_t id_744 { 0 };
                                                                                          int32_t id_745 { repeat_n_99[id_744] };
                                                                                          int32_t id_746 { 1L };
                                                                                          int32_t id_747 { int32_t(id_745 + id_746) };
                                                                                          Void id_748 { ((void)(repeat_n_99[id_743] = id_747), ::dessser::VOID) };
                                                                                          (void)id_748;
                                                                                          (void)id_748;
                                                                                        }
                                                                                      } while (while_flag_727);
                                                                                      (void)::dessser::VOID;
                                                                                    }
                                                                                    (void)::dessser::VOID;
                                                                                    uint8_t id_749 { 0 };
                                                                                    ::dessser::gen::raql_value::t6ca87232c4396e34133f69634dc3e421 id_750 { inits_src_ref_98[id_749] };
                                                                                    let_res_724 = id_750;
                                                                                  }
                                                                                  letpair_res_720 = let_res_724;
                                                                                }
                                                                                let_res_719 = letpair_res_720;
                                                                              }
                                                                              ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_751;
                                                                              {
                                                                                auto dlist4_fst_113 { std::get<0>(let_res_719) };
                                                                                auto dlist4_snd_114 { std::get<1>(let_res_719) };
                                                                                Arr<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d> id_752 { dlist4_fst_113.toListRev() };
                                                                                std::shared_ptr<::dessser::gen::raql_value::t>  id_753 { std::make_shared<::dessser::gen::raql_value::t>(std::in_place_index<35>, id_752) };
                                                                                ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_754 { id_753, dlist4_snd_114 };
                                                                                letpair_res_751 = id_754;
                                                                              }
                                                                              choose_res_602 = letpair_res_751;
                                                                            }
                                                                            choose_res_526 = choose_res_602;
                                                                          }
                                                                          choose_res_450 = choose_res_526;
                                                                        }
                                                                        choose_res_374 = choose_res_450;
                                                                      }
                                                                      choose_res_327 = choose_res_374;
                                                                    }
                                                                    choose_res_310 = choose_res_327;
                                                                  }
                                                                  choose_res_293 = choose_res_310;
                                                                }
                                                                choose_res_262 = choose_res_293;
                                                              }
                                                              choose_res_253 = choose_res_262;
                                                            }
                                                            choose_res_244 = choose_res_253;
                                                          }
                                                          choose_res_234 = choose_res_244;
                                                        }
                                                        choose_res_226 = choose_res_234;
                                                      }
                                                      choose_res_218 = choose_res_226;
                                                    }
                                                    choose_res_210 = choose_res_218;
                                                  }
                                                  choose_res_202 = choose_res_210;
                                                }
                                                choose_res_194 = choose_res_202;
                                              }
                                              choose_res_186 = choose_res_194;
                                            }
                                            choose_res_178 = choose_res_186;
                                          }
                                          choose_res_170 = choose_res_178;
                                        }
                                        choose_res_162 = choose_res_170;
                                      }
                                      choose_res_155 = choose_res_162;
                                    }
                                    choose_res_148 = choose_res_155;
                                  }
                                  choose_res_140 = choose_res_148;
                                }
                                choose_res_132 = choose_res_140;
                              }
                              choose_res_124 = choose_res_132;
                            }
                            choose_res_117 = choose_res_124;
                          }
                          choose_res_109 = choose_res_117;
                        }
                        choose_res_102 = choose_res_109;
                      }
                      choose_res_95 = choose_res_102;
                    }
                    choose_res_87 = choose_res_95;
                  }
                  choose_res_77 = choose_res_87;
                }
                choose_res_26 = choose_res_77;
              }
              choose_res_18 = choose_res_26;
            }
            choose_res_13 = choose_res_18;
          }
          choose_res_8 = choose_res_13;
        }
        letpair_res_5 = choose_res_8;
      }
      let_res_4 = letpair_res_5;
    }
    ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b letpair_res_755;
    {
      auto make_fst_529 { std::get<0>(let_res_4) };
      auto make_snd_530 { std::get<1>(let_res_4) };
      ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_756 { make_fst_529, make_snd_530 };
      letpair_res_755 = id_756;
    }
    return letpair_res_755;
  }
   };
  return fun0;
}
std::function<::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_68"
        (let "dstring1_62"
          (let "leb_ref_56" (make-vec (u32 0))
            (let "shft_ref_57" (make-vec (u8 0))
              (let "p_ref_58" (make-vec (param 0))
                (seq
                  (while
                    (let "leb128_59" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_58")))
                      (let-pair "leb128_fst_60" "leb128_snd_61" (identifier "leb128_59")
                        (seq (set-vec (u8 0) (identifier "p_ref_58") (identifier "leb128_snd_61"))
                          (set-vec (u8 0) (identifier "leb_ref_56")
                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_60") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_57"))) (unsafe-nth (u8 0) (identifier "leb_ref_56"))))
                          (set-vec (u8 0) (identifier "shft_ref_57") (add (unsafe-nth (u8 0) (identifier "shft_ref_57")) (u8 7))) 
                          (ge (identifier "leb128_fst_60") (u8 128))))) 
                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_56"))) (unsafe-nth (u8 0) (identifier "p_ref_58")))))))
          (let-pair "dstring1_fst_63" "dstring1_snd_64" (identifier "dstring1_62")
            (let-pair "dstring2_fst_66" "dstring2_snd_67" (read-bytes (identifier "dstring1_snd_64") (identifier "dstring1_fst_63")) (make-tup (string-of-bytes (identifier "dstring2_fst_66")) (identifier "dstring2_snd_67")))))
        (let-pair "dtup_fst_69" "dtup_snd_70" (identifier "dtup_68")
          (let-pair "dtup_fst_72" "dtup_snd_73" (apply (identifier "of-row-binary") (identifier "dtup_snd_70")) (make-tup (make-tup (identifier "dtup_fst_69") (identifier "dtup_fst_72")) (identifier "dtup_snd_73"))))))
 */
static std::function<::dessser::gen::raql_value::t0c870624fb83311f54db2c065f542418(Pointer)> named_value_of_row_binary_init()
{
  std::function<::dessser::gen::raql_value::t0c870624fb83311f54db2c065f542418(Pointer)> fun757 { [&fun757](Pointer p_0) {
    uint32_t id_758 { 0U };
    Vec<1, uint32_t> id_759 {  id_758  };
    ::dessser::gen::raql_value::t044960e524fd6ec1bfc06410ce526709 let_res_760;
    {
      Vec<1, uint32_t> leb_ref_56 { id_759 };
      uint8_t id_761 { 0 };
      Vec<1, uint8_t> id_762 {  id_761  };
      ::dessser::gen::raql_value::t044960e524fd6ec1bfc06410ce526709 let_res_763;
      {
        Vec<1, uint8_t> shft_ref_57 { id_762 };
        Vec<1, Pointer> id_764 {  p_0  };
        ::dessser::gen::raql_value::t044960e524fd6ec1bfc06410ce526709 let_res_765;
        {
          Vec<1, Pointer> p_ref_58 { id_764 };
          bool while_flag_766 { true };
          do {
            uint8_t id_767 { 0 };
            Pointer id_768 { p_ref_58[id_767] };
            ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 id_769 { id_768.readU8() };
            bool let_res_770;
            {
              ::dessser::gen::raql_value::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_59 { id_769 };
              bool letpair_res_771;
              {
                auto leb128_fst_60 { std::get<0>(leb128_59) };
                auto leb128_snd_61 { std::get<1>(leb128_59) };
                uint8_t id_772 { 0 };
                Void id_773 { ((void)(p_ref_58[id_772] = leb128_snd_61), ::dessser::VOID) };
                (void)id_773;
                uint8_t id_774 { 0 };
                uint8_t id_775 { 127 };
                uint8_t id_776 { uint8_t(leb128_fst_60 & id_775) };
                uint32_t id_777 { uint32_t(id_776) };
                uint8_t id_778 { 0 };
                uint8_t id_779 { shft_ref_57[id_778] };
                uint32_t id_780 { uint32_t(id_777 << id_779) };
                uint8_t id_781 { 0 };
                uint32_t id_782 { leb_ref_56[id_781] };
                uint32_t id_783 { uint32_t(id_780 | id_782) };
                Void id_784 { ((void)(leb_ref_56[id_774] = id_783), ::dessser::VOID) };
                (void)id_784;
                uint8_t id_785 { 0 };
                uint8_t id_786 { 0 };
                uint8_t id_787 { shft_ref_57[id_786] };
                uint8_t id_788 { 7 };
                uint8_t id_789 { uint8_t(id_787 + id_788) };
                Void id_790 { ((void)(shft_ref_57[id_785] = id_789), ::dessser::VOID) };
                (void)id_790;
                uint8_t id_791 { 128 };
                bool id_792 { bool(leb128_fst_60 >= id_791) };
                letpair_res_771 = id_792;
              }
              let_res_770 = letpair_res_771;
            }
            while_flag_766 = let_res_770;
            if (while_flag_766) {
              (void)::dessser::VOID;
            }
          } while (while_flag_766);
          (void)::dessser::VOID;
          uint8_t id_793 { 0 };
          uint32_t id_794 { leb_ref_56[id_793] };
          Size id_795 { Size(id_794) };
          uint8_t id_796 { 0 };
          Pointer id_797 { p_ref_58[id_796] };
          ::dessser::gen::raql_value::t044960e524fd6ec1bfc06410ce526709 id_798 { id_795, id_797 };
          let_res_765 = id_798;
        }
        let_res_763 = let_res_765;
      }
      let_res_760 = let_res_763;
    }
    ::dessser::gen::raql_value::t3fd8221434e489b54b5c4356ebff5005 let_res_799;
    {
      ::dessser::gen::raql_value::t044960e524fd6ec1bfc06410ce526709 dstring1_62 { let_res_760 };
      ::dessser::gen::raql_value::t3fd8221434e489b54b5c4356ebff5005 letpair_res_800;
      {
        auto dstring1_fst_63 { std::get<0>(dstring1_62) };
        auto dstring1_snd_64 { std::get<1>(dstring1_62) };
        ::dessser::gen::raql_value::t5887709cc43c8c8e24d28211e8c970a2 id_801 { dstring1_snd_64.readBytes(dstring1_fst_63) };
        ::dessser::gen::raql_value::t3fd8221434e489b54b5c4356ebff5005 letpair_res_802;
        {
          auto dstring2_fst_66 { std::get<0>(id_801) };
          auto dstring2_snd_67 { std::get<1>(id_801) };
          std::string id_803 { dstring2_fst_66.toString() };
          ::dessser::gen::raql_value::t3fd8221434e489b54b5c4356ebff5005 id_804 { id_803, dstring2_snd_67 };
          letpair_res_802 = id_804;
        }
        letpair_res_800 = letpair_res_802;
      }
      let_res_799 = letpair_res_800;
    }
    ::dessser::gen::raql_value::t0c870624fb83311f54db2c065f542418 let_res_805;
    {
      ::dessser::gen::raql_value::t3fd8221434e489b54b5c4356ebff5005 dtup_68 { let_res_799 };
      ::dessser::gen::raql_value::t0c870624fb83311f54db2c065f542418 letpair_res_806;
      {
        auto dtup_fst_69 { std::get<0>(dtup_68) };
        auto dtup_snd_70 { std::get<1>(dtup_68) };
        ::dessser::gen::raql_value::t2192dc426e477a22ba201bc3a0e4295b id_807 { of_row_binary(dtup_snd_70) };
        ::dessser::gen::raql_value::t0c870624fb83311f54db2c065f542418 letpair_res_808;
        {
          auto dtup_fst_72 { std::get<0>(id_807) };
          auto dtup_snd_73 { std::get<1>(id_807) };
          std::shared_ptr<::dessser::gen::raql_value::named_value>  id_809 { std::make_shared<::dessser::gen::raql_value::named_value>(dtup_fst_69, dtup_fst_72) };
          ::dessser::gen::raql_value::t0c870624fb83311f54db2c065f542418 id_810 { id_809, dtup_snd_73 };
          letpair_res_808 = id_810;
        }
        letpair_res_806 = letpair_res_808;
      }
      let_res_805 = letpair_res_806;
    }
    return let_res_805;
  }
   };
  return fun757;
}
std::function<::dessser::gen::raql_value::t0c870624fb83311f54db2c065f542418(Pointer)> named_value_of_row_binary(named_value_of_row_binary_init());

/* 
    (fun ("[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]")
      (let "label2_536" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_536")) (size 2)
          (if (eq (u16 1) (identifier "label2_536")) (size 2)
            (if (eq (u16 2) (identifier "label2_536")) (size 10)
              (if (eq (u16 3) (identifier "label2_536"))
                (add (size 2)
                  (add
                    (let "n_ref_570" (make-vec (string-length (get-alt "VString" (param 0))))
                      (let "lebsz_ref_571" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_570")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_571")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_571") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_571")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_571")))))) 
                    (size-of-u32 (string-length (get-alt "VString" (param 0))))))
                (if (eq (u16 4) (identifier "label2_536")) (size 3)
                  (if (eq (u16 5) (identifier "label2_536")) (size 3)
                    (if (eq (u16 6) (identifier "label2_536")) (size 3)
                      (if (eq (u16 7) (identifier "label2_536")) (size 4)
                        (if (eq (u16 8) (identifier "label2_536")) (size 6)
                          (if (eq (u16 9) (identifier "label2_536")) 
                            (size 6)
                            (if (eq (u16 10) (identifier "label2_536")) 
                              (size 10)
                              (if (eq (u16 11) (identifier "label2_536")) 
                                (size 10)
                                (if (eq (u16 12) (identifier "label2_536")) 
                                  (size 10)
                                  (if (eq (u16 13) (identifier "label2_536")) 
                                    (size 10)
                                    (if (eq (u16 14) (identifier "label2_536")) 
                                      (size 18)
                                      (if (eq (u16 15) (identifier "label2_536")) 
                                        (size 3)
                                        (if (eq (u16 16) (identifier "label2_536")) 
                                          (size 4)
                                          (if (eq (u16 17) (identifier "label2_536")) 
                                            (size 6)
                                            (if (eq (u16 18) (identifier "label2_536")) 
                                              (size 6)
                                              (if (eq (u16 19) (identifier "label2_536")) 
                                                (size 10)
                                                (if (eq (u16 20) (identifier "label2_536")) 
                                                  (size 10)
                                                  (if (eq (u16 21) (identifier "label2_536")) 
                                                    (size 10)
                                                    (if (eq (u16 22) (identifier "label2_536")) 
                                                      (size 10)
                                                      (if (eq (u16 23) (identifier "label2_536")) 
                                                        (size 18)
                                                        (if (eq (u16 24) (identifier "label2_536")) 
                                                          (size 10)
                                                          (if (eq (u16 25) (identifier "label2_536")) 
                                                            (size 6)
                                                            (if (eq (u16 26) (identifier "label2_536")) 
                                                              (size 18)
                                                              (if (eq (u16 27) (identifier "label2_536"))
                                                                (if (eq (u16 0) (label-of (get-alt "VIp" (param 0)))) (size 8) (seq (assert (eq (label-of (get-alt "VIp" (param 0))) (u16 1))) (size 20)))
                                                                (if (eq (u16 28) (identifier "label2_536")) 
                                                                  (size 7)
                                                                  (if 
                                                                    (eq (u16 29) (identifier "label2_536")) 
                                                                    (size 19)
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label2_536"))
                                                                    (if (eq (u16 0) (label-of (get-alt "VCidr" (param 0)))) (size 9) (seq (assert (eq (label-of (get-alt "VCidr" (param 0))) (u16 1))) (size 21)))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label2_536"))
                                                                    (let "sz_ref_557"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_555" 
                                                                    (make-vec (cardinality (get-alt "VTup" (param 0))))
                                                                    (let "lebsz_ref_556" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_555")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_556")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_556") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_556")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_556"))))))))
                                                                    (seq
                                                                    (let "repeat_n_558" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VTup" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_558")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_557")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_557")) 
                                                                    (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_558")) (get-alt "VTup" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_558") (add (unsafe-nth (u8 0) (identifier "repeat_n_558")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_557"))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label2_536"))
                                                                    (let "sz_ref_553"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_551" 
                                                                    (make-vec (cardinality (get-alt "VVec" (param 0))))
                                                                    (let "lebsz_ref_552" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_551")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_552")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_552") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_552")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_552"))))))))
                                                                    (seq
                                                                    (let "repeat_n_554" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VVec" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_554")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_553")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_553")) 
                                                                    (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_554")) (get-alt "VVec" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_554") (add (unsafe-nth (u8 0) (identifier "repeat_n_554")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_553"))))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label2_536"))
                                                                    (let "sz_ref_549"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_547" 
                                                                    (make-vec (cardinality (get-alt "VArr" (param 0))))
                                                                    (let "lebsz_ref_548" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_547")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_548")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_548") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_548")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_548"))))))))
                                                                    (seq
                                                                    (let "repeat_n_550" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VArr" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_550")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_549")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_549")) 
                                                                    (apply (myself "Size") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_550")) (get-alt "VArr" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_550") (add (unsafe-nth (u8 0) (identifier "repeat_n_550")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_549"))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label2_536"))
                                                                    (let "sz_ref_545"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_543" 
                                                                    (make-vec (cardinality (get-alt "VRec" (param 0))))
                                                                    (let "lebsz_ref_544" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_543")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_544")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_544") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_544")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_544"))))))))
                                                                    (seq
                                                                    (let "repeat_n_546" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VRec" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_546")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_545")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_545"))
                                                                    (apply (identifier "named_value-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_546")) (get-alt "VRec" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_546") (add (unsafe-nth (u8 0) (identifier "repeat_n_546")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_545"))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label2_536") (u16 35)))
                                                                    (let "sz_ref_539"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_537" 
                                                                    (make-vec (cardinality (get-alt "VMap" (param 0))))
                                                                    (let "lebsz_ref_538" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_537")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_538")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_538") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_538")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_538"))))))))
                                                                    (seq
                                                                    (let "repeat_n_540" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "VMap" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_540")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_539")
                                                                    (add
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_539"))
                                                                    (apply (myself "Size") (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_540")) (get-alt "VMap" (param 0))))))
                                                                    (apply (myself "Size") (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_540")) (get-alt "VMap" (param 0)))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_540") (add (unsafe-nth (u8 0) (identifier "repeat_n_540")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_539"))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_value::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_value::t> )> fun811 { [&fun811](std::shared_ptr<::dessser::gen::raql_value::t>  p_0) {
    uint16_t id_812 { uint16_t((*p_0).index()) };
    Size let_res_813;
    {
      uint16_t label2_536 { id_812 };
      uint16_t id_814 { 0 };
      bool id_815 { bool(id_814 == label2_536) };
      Size choose_res_816;
      if (id_815) {
        Size id_817 { 2UL };
        choose_res_816 = id_817;
      } else {
        uint16_t id_818 { 1 };
        bool id_819 { bool(id_818 == label2_536) };
        Size choose_res_820;
        if (id_819) {
          Size id_821 { 2UL };
          choose_res_820 = id_821;
        } else {
          uint16_t id_822 { 2 };
          bool id_823 { bool(id_822 == label2_536) };
          Size choose_res_824;
          if (id_823) {
            Size id_825 { 10UL };
            choose_res_824 = id_825;
          } else {
            uint16_t id_826 { 3 };
            bool id_827 { bool(id_826 == label2_536) };
            Size choose_res_828;
            if (id_827) {
              Size id_829 { 2UL };
              std::string id_830 { std::get<3 /* VString */>((*p_0)) };
              uint32_t id_831 { (uint32_t)id_830.size() };
              Vec<1, uint32_t> id_832 {  id_831  };
              Size let_res_833;
              {
                Vec<1, uint32_t> n_ref_570 { id_832 };
                uint32_t id_834 { 1U };
                Vec<1, uint32_t> id_835 {  id_834  };
                Size let_res_836;
                {
                  Vec<1, uint32_t> lebsz_ref_571 { id_835 };
                  bool while_flag_837 { true };
                  do {
                    uint8_t id_838 { 0 };
                    uint32_t id_839 { n_ref_570[id_838] };
                    uint8_t id_840 { 0 };
                    uint32_t id_841 { lebsz_ref_571[id_840] };
                    uint8_t id_842 { 7 };
                    uint32_t id_843 { uint32_t(id_841 << id_842) };
                    bool id_844 { bool(id_839 >= id_843) };
                    while_flag_837 = id_844;
                    if (while_flag_837) {
                      uint8_t id_845 { 0 };
                      uint8_t id_846 { 0 };
                      uint32_t id_847 { lebsz_ref_571[id_846] };
                      uint32_t id_848 { 1U };
                      uint32_t id_849 { uint32_t(id_847 + id_848) };
                      Void id_850 { ((void)(lebsz_ref_571[id_845] = id_849), ::dessser::VOID) };
                      (void)id_850;
                    }
                  } while (while_flag_837);
                  (void)::dessser::VOID;
                  uint8_t id_851 { 0 };
                  uint32_t id_852 { lebsz_ref_571[id_851] };
                  Size id_853 { Size(id_852) };
                  let_res_836 = id_853;
                }
                let_res_833 = let_res_836;
              }
              std::string id_854 { std::get<3 /* VString */>((*p_0)) };
              uint32_t id_855 { (uint32_t)id_854.size() };
              Size id_856 { Size(id_855) };
              Size id_857 { Size(let_res_833 + id_856) };
              Size id_858 { Size(id_829 + id_857) };
              choose_res_828 = id_858;
            } else {
              uint16_t id_859 { 4 };
              bool id_860 { bool(id_859 == label2_536) };
              Size choose_res_861;
              if (id_860) {
                Size id_862 { 3UL };
                choose_res_861 = id_862;
              } else {
                uint16_t id_863 { 5 };
                bool id_864 { bool(id_863 == label2_536) };
                Size choose_res_865;
                if (id_864) {
                  Size id_866 { 3UL };
                  choose_res_865 = id_866;
                } else {
                  uint16_t id_867 { 6 };
                  bool id_868 { bool(id_867 == label2_536) };
                  Size choose_res_869;
                  if (id_868) {
                    Size id_870 { 3UL };
                    choose_res_869 = id_870;
                  } else {
                    uint16_t id_871 { 7 };
                    bool id_872 { bool(id_871 == label2_536) };
                    Size choose_res_873;
                    if (id_872) {
                      Size id_874 { 4UL };
                      choose_res_873 = id_874;
                    } else {
                      uint16_t id_875 { 8 };
                      bool id_876 { bool(id_875 == label2_536) };
                      Size choose_res_877;
                      if (id_876) {
                        Size id_878 { 6UL };
                        choose_res_877 = id_878;
                      } else {
                        uint16_t id_879 { 9 };
                        bool id_880 { bool(id_879 == label2_536) };
                        Size choose_res_881;
                        if (id_880) {
                          Size id_882 { 6UL };
                          choose_res_881 = id_882;
                        } else {
                          uint16_t id_883 { 10 };
                          bool id_884 { bool(id_883 == label2_536) };
                          Size choose_res_885;
                          if (id_884) {
                            Size id_886 { 10UL };
                            choose_res_885 = id_886;
                          } else {
                            uint16_t id_887 { 11 };
                            bool id_888 { bool(id_887 == label2_536) };
                            Size choose_res_889;
                            if (id_888) {
                              Size id_890 { 10UL };
                              choose_res_889 = id_890;
                            } else {
                              uint16_t id_891 { 12 };
                              bool id_892 { bool(id_891 == label2_536) };
                              Size choose_res_893;
                              if (id_892) {
                                Size id_894 { 10UL };
                                choose_res_893 = id_894;
                              } else {
                                uint16_t id_895 { 13 };
                                bool id_896 { bool(id_895 == label2_536) };
                                Size choose_res_897;
                                if (id_896) {
                                  Size id_898 { 10UL };
                                  choose_res_897 = id_898;
                                } else {
                                  uint16_t id_899 { 14 };
                                  bool id_900 { bool(id_899 == label2_536) };
                                  Size choose_res_901;
                                  if (id_900) {
                                    Size id_902 { 18UL };
                                    choose_res_901 = id_902;
                                  } else {
                                    uint16_t id_903 { 15 };
                                    bool id_904 { bool(id_903 == label2_536) };
                                    Size choose_res_905;
                                    if (id_904) {
                                      Size id_906 { 3UL };
                                      choose_res_905 = id_906;
                                    } else {
                                      uint16_t id_907 { 16 };
                                      bool id_908 { bool(id_907 == label2_536) };
                                      Size choose_res_909;
                                      if (id_908) {
                                        Size id_910 { 4UL };
                                        choose_res_909 = id_910;
                                      } else {
                                        uint16_t id_911 { 17 };
                                        bool id_912 { bool(id_911 == label2_536) };
                                        Size choose_res_913;
                                        if (id_912) {
                                          Size id_914 { 6UL };
                                          choose_res_913 = id_914;
                                        } else {
                                          uint16_t id_915 { 18 };
                                          bool id_916 { bool(id_915 == label2_536) };
                                          Size choose_res_917;
                                          if (id_916) {
                                            Size id_918 { 6UL };
                                            choose_res_917 = id_918;
                                          } else {
                                            uint16_t id_919 { 19 };
                                            bool id_920 { bool(id_919 == label2_536) };
                                            Size choose_res_921;
                                            if (id_920) {
                                              Size id_922 { 10UL };
                                              choose_res_921 = id_922;
                                            } else {
                                              uint16_t id_923 { 20 };
                                              bool id_924 { bool(id_923 == label2_536) };
                                              Size choose_res_925;
                                              if (id_924) {
                                                Size id_926 { 10UL };
                                                choose_res_925 = id_926;
                                              } else {
                                                uint16_t id_927 { 21 };
                                                bool id_928 { bool(id_927 == label2_536) };
                                                Size choose_res_929;
                                                if (id_928) {
                                                  Size id_930 { 10UL };
                                                  choose_res_929 = id_930;
                                                } else {
                                                  uint16_t id_931 { 22 };
                                                  bool id_932 { bool(id_931 == label2_536) };
                                                  Size choose_res_933;
                                                  if (id_932) {
                                                    Size id_934 { 10UL };
                                                    choose_res_933 = id_934;
                                                  } else {
                                                    uint16_t id_935 { 23 };
                                                    bool id_936 { bool(id_935 == label2_536) };
                                                    Size choose_res_937;
                                                    if (id_936) {
                                                      Size id_938 { 18UL };
                                                      choose_res_937 = id_938;
                                                    } else {
                                                      uint16_t id_939 { 24 };
                                                      bool id_940 { bool(id_939 == label2_536) };
                                                      Size choose_res_941;
                                                      if (id_940) {
                                                        Size id_942 { 10UL };
                                                        choose_res_941 = id_942;
                                                      } else {
                                                        uint16_t id_943 { 25 };
                                                        bool id_944 { bool(id_943 == label2_536) };
                                                        Size choose_res_945;
                                                        if (id_944) {
                                                          Size id_946 { 6UL };
                                                          choose_res_945 = id_946;
                                                        } else {
                                                          uint16_t id_947 { 26 };
                                                          bool id_948 { bool(id_947 == label2_536) };
                                                          Size choose_res_949;
                                                          if (id_948) {
                                                            Size id_950 { 18UL };
                                                            choose_res_949 = id_950;
                                                          } else {
                                                            uint16_t id_951 { 27 };
                                                            bool id_952 { bool(id_951 == label2_536) };
                                                            Size choose_res_953;
                                                            if (id_952) {
                                                              uint16_t id_954 { 0 };
                                                              ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_955 { std::get<27 /* VIp */>((*p_0)) };
                                                              uint16_t id_956 { uint16_t(id_955.index()) };
                                                              bool id_957 { bool(id_954 == id_956) };
                                                              Size choose_res_958;
                                                              if (id_957) {
                                                                Size id_959 { 8UL };
                                                                choose_res_958 = id_959;
                                                              } else {
                                                                ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_960 { std::get<27 /* VIp */>((*p_0)) };
                                                                uint16_t id_961 { uint16_t(id_960.index()) };
                                                                uint16_t id_962 { 1 };
                                                                bool id_963 { bool(id_961 == id_962) };
                                                                Void id_964 { ((void)(assert(id_963)), ::dessser::VOID) };
                                                                (void)id_964;
                                                                Size id_965 { 20UL };
                                                                choose_res_958 = id_965;
                                                              }
                                                              choose_res_953 = choose_res_958;
                                                            } else {
                                                              uint16_t id_966 { 28 };
                                                              bool id_967 { bool(id_966 == label2_536) };
                                                              Size choose_res_968;
                                                              if (id_967) {
                                                                Size id_969 { 7UL };
                                                                choose_res_968 = id_969;
                                                              } else {
                                                                uint16_t id_970 { 29 };
                                                                bool id_971 { bool(id_970 == label2_536) };
                                                                Size choose_res_972;
                                                                if (id_971) {
                                                                  Size id_973 { 19UL };
                                                                  choose_res_972 = id_973;
                                                                } else {
                                                                  uint16_t id_974 { 30 };
                                                                  bool id_975 { bool(id_974 == label2_536) };
                                                                  Size choose_res_976;
                                                                  if (id_975) {
                                                                    uint16_t id_977 { 0 };
                                                                    ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_978 { std::get<30 /* VCidr */>((*p_0)) };
                                                                    uint16_t id_979 { uint16_t(id_978.index()) };
                                                                    bool id_980 { bool(id_977 == id_979) };
                                                                    Size choose_res_981;
                                                                    if (id_980) {
                                                                      Size id_982 { 9UL };
                                                                      choose_res_981 = id_982;
                                                                    } else {
                                                                      ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_983 { std::get<30 /* VCidr */>((*p_0)) };
                                                                      uint16_t id_984 { uint16_t(id_983.index()) };
                                                                      uint16_t id_985 { 1 };
                                                                      bool id_986 { bool(id_984 == id_985) };
                                                                      Void id_987 { ((void)(assert(id_986)), ::dessser::VOID) };
                                                                      (void)id_987;
                                                                      Size id_988 { 21UL };
                                                                      choose_res_981 = id_988;
                                                                    }
                                                                    choose_res_976 = choose_res_981;
                                                                  } else {
                                                                    uint16_t id_989 { 31 };
                                                                    bool id_990 { bool(id_989 == label2_536) };
                                                                    Size choose_res_991;
                                                                    if (id_990) {
                                                                      Size id_992 { 2UL };
                                                                      Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_993 { std::get<31 /* VTup */>((*p_0)) };
                                                                      uint32_t id_994 { id_993.size() };
                                                                      Vec<1, uint32_t> id_995 {  id_994  };
                                                                      Size let_res_996;
                                                                      {
                                                                        Vec<1, uint32_t> n_ref_555 { id_995 };
                                                                        uint32_t id_997 { 1U };
                                                                        Vec<1, uint32_t> id_998 {  id_997  };
                                                                        Size let_res_999;
                                                                        {
                                                                          Vec<1, uint32_t> lebsz_ref_556 { id_998 };
                                                                          bool while_flag_1000 { true };
                                                                          do {
                                                                            uint8_t id_1001 { 0 };
                                                                            uint32_t id_1002 { n_ref_555[id_1001] };
                                                                            uint8_t id_1003 { 0 };
                                                                            uint32_t id_1004 { lebsz_ref_556[id_1003] };
                                                                            uint8_t id_1005 { 7 };
                                                                            uint32_t id_1006 { uint32_t(id_1004 << id_1005) };
                                                                            bool id_1007 { bool(id_1002 >= id_1006) };
                                                                            while_flag_1000 = id_1007;
                                                                            if (while_flag_1000) {
                                                                              uint8_t id_1008 { 0 };
                                                                              uint8_t id_1009 { 0 };
                                                                              uint32_t id_1010 { lebsz_ref_556[id_1009] };
                                                                              uint32_t id_1011 { 1U };
                                                                              uint32_t id_1012 { uint32_t(id_1010 + id_1011) };
                                                                              Void id_1013 { ((void)(lebsz_ref_556[id_1008] = id_1012), ::dessser::VOID) };
                                                                              (void)id_1013;
                                                                            }
                                                                          } while (while_flag_1000);
                                                                          (void)::dessser::VOID;
                                                                          uint8_t id_1014 { 0 };
                                                                          uint32_t id_1015 { lebsz_ref_556[id_1014] };
                                                                          Size id_1016 { Size(id_1015) };
                                                                          let_res_999 = id_1016;
                                                                        }
                                                                        let_res_996 = let_res_999;
                                                                      }
                                                                      Size id_1017 { Size(id_992 + let_res_996) };
                                                                      Vec<1, Size> id_1018 {  id_1017  };
                                                                      Size let_res_1019;
                                                                      {
                                                                        Vec<1, Size> sz_ref_557 { id_1018 };
                                                                        int32_t id_1020 { 0L };
                                                                        Vec<1, int32_t> id_1021 {  id_1020  };
                                                                        {
                                                                          Vec<1, int32_t> repeat_n_558 { id_1021 };
                                                                          bool while_flag_1022 { true };
                                                                          do {
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1023 { std::get<31 /* VTup */>((*p_0)) };
                                                                            uint32_t id_1024 { id_1023.size() };
                                                                            int32_t id_1025 { int32_t(id_1024) };
                                                                            uint8_t id_1026 { 0 };
                                                                            int32_t id_1027 { repeat_n_558[id_1026] };
                                                                            bool id_1028 { bool(id_1025 > id_1027) };
                                                                            while_flag_1022 = id_1028;
                                                                            if (while_flag_1022) {
                                                                              uint8_t id_1029 { 0 };
                                                                              uint8_t id_1030 { 0 };
                                                                              Size id_1031 { sz_ref_557[id_1030] };
                                                                              uint8_t id_1032 { 0 };
                                                                              int32_t id_1033 { repeat_n_558[id_1032] };
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1034 { std::get<31 /* VTup */>((*p_0)) };
                                                                              std::shared_ptr<::dessser::gen::raql_value::t>  id_1035 { id_1034[id_1033] };
                                                                              Size id_1036 { fun811(id_1035) };
                                                                              Size id_1037 { Size(id_1031 + id_1036) };
                                                                              Void id_1038 { ((void)(sz_ref_557[id_1029] = id_1037), ::dessser::VOID) };
                                                                              (void)id_1038;
                                                                              uint8_t id_1039 { 0 };
                                                                              uint8_t id_1040 { 0 };
                                                                              int32_t id_1041 { repeat_n_558[id_1040] };
                                                                              int32_t id_1042 { 1L };
                                                                              int32_t id_1043 { int32_t(id_1041 + id_1042) };
                                                                              Void id_1044 { ((void)(repeat_n_558[id_1039] = id_1043), ::dessser::VOID) };
                                                                              (void)id_1044;
                                                                              (void)id_1044;
                                                                            }
                                                                          } while (while_flag_1022);
                                                                          (void)::dessser::VOID;
                                                                        }
                                                                        (void)::dessser::VOID;
                                                                        uint8_t id_1045 { 0 };
                                                                        Size id_1046 { sz_ref_557[id_1045] };
                                                                        let_res_1019 = id_1046;
                                                                      }
                                                                      choose_res_991 = let_res_1019;
                                                                    } else {
                                                                      uint16_t id_1047 { 32 };
                                                                      bool id_1048 { bool(id_1047 == label2_536) };
                                                                      Size choose_res_1049;
                                                                      if (id_1048) {
                                                                        Size id_1050 { 2UL };
                                                                        Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1051 { std::get<32 /* VVec */>((*p_0)) };
                                                                        uint32_t id_1052 { id_1051.size() };
                                                                        Vec<1, uint32_t> id_1053 {  id_1052  };
                                                                        Size let_res_1054;
                                                                        {
                                                                          Vec<1, uint32_t> n_ref_551 { id_1053 };
                                                                          uint32_t id_1055 { 1U };
                                                                          Vec<1, uint32_t> id_1056 {  id_1055  };
                                                                          Size let_res_1057;
                                                                          {
                                                                            Vec<1, uint32_t> lebsz_ref_552 { id_1056 };
                                                                            bool while_flag_1058 { true };
                                                                            do {
                                                                              uint8_t id_1059 { 0 };
                                                                              uint32_t id_1060 { n_ref_551[id_1059] };
                                                                              uint8_t id_1061 { 0 };
                                                                              uint32_t id_1062 { lebsz_ref_552[id_1061] };
                                                                              uint8_t id_1063 { 7 };
                                                                              uint32_t id_1064 { uint32_t(id_1062 << id_1063) };
                                                                              bool id_1065 { bool(id_1060 >= id_1064) };
                                                                              while_flag_1058 = id_1065;
                                                                              if (while_flag_1058) {
                                                                                uint8_t id_1066 { 0 };
                                                                                uint8_t id_1067 { 0 };
                                                                                uint32_t id_1068 { lebsz_ref_552[id_1067] };
                                                                                uint32_t id_1069 { 1U };
                                                                                uint32_t id_1070 { uint32_t(id_1068 + id_1069) };
                                                                                Void id_1071 { ((void)(lebsz_ref_552[id_1066] = id_1070), ::dessser::VOID) };
                                                                                (void)id_1071;
                                                                              }
                                                                            } while (while_flag_1058);
                                                                            (void)::dessser::VOID;
                                                                            uint8_t id_1072 { 0 };
                                                                            uint32_t id_1073 { lebsz_ref_552[id_1072] };
                                                                            Size id_1074 { Size(id_1073) };
                                                                            let_res_1057 = id_1074;
                                                                          }
                                                                          let_res_1054 = let_res_1057;
                                                                        }
                                                                        Size id_1075 { Size(id_1050 + let_res_1054) };
                                                                        Vec<1, Size> id_1076 {  id_1075  };
                                                                        Size let_res_1077;
                                                                        {
                                                                          Vec<1, Size> sz_ref_553 { id_1076 };
                                                                          int32_t id_1078 { 0L };
                                                                          Vec<1, int32_t> id_1079 {  id_1078  };
                                                                          {
                                                                            Vec<1, int32_t> repeat_n_554 { id_1079 };
                                                                            bool while_flag_1080 { true };
                                                                            do {
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1081 { std::get<32 /* VVec */>((*p_0)) };
                                                                              uint32_t id_1082 { id_1081.size() };
                                                                              int32_t id_1083 { int32_t(id_1082) };
                                                                              uint8_t id_1084 { 0 };
                                                                              int32_t id_1085 { repeat_n_554[id_1084] };
                                                                              bool id_1086 { bool(id_1083 > id_1085) };
                                                                              while_flag_1080 = id_1086;
                                                                              if (while_flag_1080) {
                                                                                uint8_t id_1087 { 0 };
                                                                                uint8_t id_1088 { 0 };
                                                                                Size id_1089 { sz_ref_553[id_1088] };
                                                                                uint8_t id_1090 { 0 };
                                                                                int32_t id_1091 { repeat_n_554[id_1090] };
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1092 { std::get<32 /* VVec */>((*p_0)) };
                                                                                std::shared_ptr<::dessser::gen::raql_value::t>  id_1093 { id_1092[id_1091] };
                                                                                Size id_1094 { fun811(id_1093) };
                                                                                Size id_1095 { Size(id_1089 + id_1094) };
                                                                                Void id_1096 { ((void)(sz_ref_553[id_1087] = id_1095), ::dessser::VOID) };
                                                                                (void)id_1096;
                                                                                uint8_t id_1097 { 0 };
                                                                                uint8_t id_1098 { 0 };
                                                                                int32_t id_1099 { repeat_n_554[id_1098] };
                                                                                int32_t id_1100 { 1L };
                                                                                int32_t id_1101 { int32_t(id_1099 + id_1100) };
                                                                                Void id_1102 { ((void)(repeat_n_554[id_1097] = id_1101), ::dessser::VOID) };
                                                                                (void)id_1102;
                                                                                (void)id_1102;
                                                                              }
                                                                            } while (while_flag_1080);
                                                                            (void)::dessser::VOID;
                                                                          }
                                                                          (void)::dessser::VOID;
                                                                          uint8_t id_1103 { 0 };
                                                                          Size id_1104 { sz_ref_553[id_1103] };
                                                                          let_res_1077 = id_1104;
                                                                        }
                                                                        choose_res_1049 = let_res_1077;
                                                                      } else {
                                                                        uint16_t id_1105 { 33 };
                                                                        bool id_1106 { bool(id_1105 == label2_536) };
                                                                        Size choose_res_1107;
                                                                        if (id_1106) {
                                                                          Size id_1108 { 2UL };
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1109 { std::get<33 /* VArr */>((*p_0)) };
                                                                          uint32_t id_1110 { id_1109.size() };
                                                                          Vec<1, uint32_t> id_1111 {  id_1110  };
                                                                          Size let_res_1112;
                                                                          {
                                                                            Vec<1, uint32_t> n_ref_547 { id_1111 };
                                                                            uint32_t id_1113 { 1U };
                                                                            Vec<1, uint32_t> id_1114 {  id_1113  };
                                                                            Size let_res_1115;
                                                                            {
                                                                              Vec<1, uint32_t> lebsz_ref_548 { id_1114 };
                                                                              bool while_flag_1116 { true };
                                                                              do {
                                                                                uint8_t id_1117 { 0 };
                                                                                uint32_t id_1118 { n_ref_547[id_1117] };
                                                                                uint8_t id_1119 { 0 };
                                                                                uint32_t id_1120 { lebsz_ref_548[id_1119] };
                                                                                uint8_t id_1121 { 7 };
                                                                                uint32_t id_1122 { uint32_t(id_1120 << id_1121) };
                                                                                bool id_1123 { bool(id_1118 >= id_1122) };
                                                                                while_flag_1116 = id_1123;
                                                                                if (while_flag_1116) {
                                                                                  uint8_t id_1124 { 0 };
                                                                                  uint8_t id_1125 { 0 };
                                                                                  uint32_t id_1126 { lebsz_ref_548[id_1125] };
                                                                                  uint32_t id_1127 { 1U };
                                                                                  uint32_t id_1128 { uint32_t(id_1126 + id_1127) };
                                                                                  Void id_1129 { ((void)(lebsz_ref_548[id_1124] = id_1128), ::dessser::VOID) };
                                                                                  (void)id_1129;
                                                                                }
                                                                              } while (while_flag_1116);
                                                                              (void)::dessser::VOID;
                                                                              uint8_t id_1130 { 0 };
                                                                              uint32_t id_1131 { lebsz_ref_548[id_1130] };
                                                                              Size id_1132 { Size(id_1131) };
                                                                              let_res_1115 = id_1132;
                                                                            }
                                                                            let_res_1112 = let_res_1115;
                                                                          }
                                                                          Size id_1133 { Size(id_1108 + let_res_1112) };
                                                                          Vec<1, Size> id_1134 {  id_1133  };
                                                                          Size let_res_1135;
                                                                          {
                                                                            Vec<1, Size> sz_ref_549 { id_1134 };
                                                                            int32_t id_1136 { 0L };
                                                                            Vec<1, int32_t> id_1137 {  id_1136  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_550 { id_1137 };
                                                                              bool while_flag_1138 { true };
                                                                              do {
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1139 { std::get<33 /* VArr */>((*p_0)) };
                                                                                uint32_t id_1140 { id_1139.size() };
                                                                                int32_t id_1141 { int32_t(id_1140) };
                                                                                uint8_t id_1142 { 0 };
                                                                                int32_t id_1143 { repeat_n_550[id_1142] };
                                                                                bool id_1144 { bool(id_1141 > id_1143) };
                                                                                while_flag_1138 = id_1144;
                                                                                if (while_flag_1138) {
                                                                                  uint8_t id_1145 { 0 };
                                                                                  uint8_t id_1146 { 0 };
                                                                                  Size id_1147 { sz_ref_549[id_1146] };
                                                                                  uint8_t id_1148 { 0 };
                                                                                  int32_t id_1149 { repeat_n_550[id_1148] };
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1150 { std::get<33 /* VArr */>((*p_0)) };
                                                                                  std::shared_ptr<::dessser::gen::raql_value::t>  id_1151 { id_1150[id_1149] };
                                                                                  Size id_1152 { fun811(id_1151) };
                                                                                  Size id_1153 { Size(id_1147 + id_1152) };
                                                                                  Void id_1154 { ((void)(sz_ref_549[id_1145] = id_1153), ::dessser::VOID) };
                                                                                  (void)id_1154;
                                                                                  uint8_t id_1155 { 0 };
                                                                                  uint8_t id_1156 { 0 };
                                                                                  int32_t id_1157 { repeat_n_550[id_1156] };
                                                                                  int32_t id_1158 { 1L };
                                                                                  int32_t id_1159 { int32_t(id_1157 + id_1158) };
                                                                                  Void id_1160 { ((void)(repeat_n_550[id_1155] = id_1159), ::dessser::VOID) };
                                                                                  (void)id_1160;
                                                                                  (void)id_1160;
                                                                                }
                                                                              } while (while_flag_1138);
                                                                              (void)::dessser::VOID;
                                                                            }
                                                                            (void)::dessser::VOID;
                                                                            uint8_t id_1161 { 0 };
                                                                            Size id_1162 { sz_ref_549[id_1161] };
                                                                            let_res_1135 = id_1162;
                                                                          }
                                                                          choose_res_1107 = let_res_1135;
                                                                        } else {
                                                                          uint16_t id_1163 { 34 };
                                                                          bool id_1164 { bool(id_1163 == label2_536) };
                                                                          Size choose_res_1165;
                                                                          if (id_1164) {
                                                                            Size id_1166 { 2UL };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_1167 { std::get<34 /* VRec */>((*p_0)) };
                                                                            uint32_t id_1168 { id_1167.size() };
                                                                            Vec<1, uint32_t> id_1169 {  id_1168  };
                                                                            Size let_res_1170;
                                                                            {
                                                                              Vec<1, uint32_t> n_ref_543 { id_1169 };
                                                                              uint32_t id_1171 { 1U };
                                                                              Vec<1, uint32_t> id_1172 {  id_1171  };
                                                                              Size let_res_1173;
                                                                              {
                                                                                Vec<1, uint32_t> lebsz_ref_544 { id_1172 };
                                                                                bool while_flag_1174 { true };
                                                                                do {
                                                                                  uint8_t id_1175 { 0 };
                                                                                  uint32_t id_1176 { n_ref_543[id_1175] };
                                                                                  uint8_t id_1177 { 0 };
                                                                                  uint32_t id_1178 { lebsz_ref_544[id_1177] };
                                                                                  uint8_t id_1179 { 7 };
                                                                                  uint32_t id_1180 { uint32_t(id_1178 << id_1179) };
                                                                                  bool id_1181 { bool(id_1176 >= id_1180) };
                                                                                  while_flag_1174 = id_1181;
                                                                                  if (while_flag_1174) {
                                                                                    uint8_t id_1182 { 0 };
                                                                                    uint8_t id_1183 { 0 };
                                                                                    uint32_t id_1184 { lebsz_ref_544[id_1183] };
                                                                                    uint32_t id_1185 { 1U };
                                                                                    uint32_t id_1186 { uint32_t(id_1184 + id_1185) };
                                                                                    Void id_1187 { ((void)(lebsz_ref_544[id_1182] = id_1186), ::dessser::VOID) };
                                                                                    (void)id_1187;
                                                                                  }
                                                                                } while (while_flag_1174);
                                                                                (void)::dessser::VOID;
                                                                                uint8_t id_1188 { 0 };
                                                                                uint32_t id_1189 { lebsz_ref_544[id_1188] };
                                                                                Size id_1190 { Size(id_1189) };
                                                                                let_res_1173 = id_1190;
                                                                              }
                                                                              let_res_1170 = let_res_1173;
                                                                            }
                                                                            Size id_1191 { Size(id_1166 + let_res_1170) };
                                                                            Vec<1, Size> id_1192 {  id_1191  };
                                                                            Size let_res_1193;
                                                                            {
                                                                              Vec<1, Size> sz_ref_545 { id_1192 };
                                                                              int32_t id_1194 { 0L };
                                                                              Vec<1, int32_t> id_1195 {  id_1194  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_546 { id_1195 };
                                                                                bool while_flag_1196 { true };
                                                                                do {
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_1197 { std::get<34 /* VRec */>((*p_0)) };
                                                                                  uint32_t id_1198 { id_1197.size() };
                                                                                  int32_t id_1199 { int32_t(id_1198) };
                                                                                  uint8_t id_1200 { 0 };
                                                                                  int32_t id_1201 { repeat_n_546[id_1200] };
                                                                                  bool id_1202 { bool(id_1199 > id_1201) };
                                                                                  while_flag_1196 = id_1202;
                                                                                  if (while_flag_1196) {
                                                                                    uint8_t id_1203 { 0 };
                                                                                    uint8_t id_1204 { 0 };
                                                                                    Size id_1205 { sz_ref_545[id_1204] };
                                                                                    uint8_t id_1206 { 0 };
                                                                                    int32_t id_1207 { repeat_n_546[id_1206] };
                                                                                    Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_1208 { std::get<34 /* VRec */>((*p_0)) };
                                                                                    std::shared_ptr<::dessser::gen::raql_value::named_value>  id_1209 { id_1208[id_1207] };
                                                                                    Size id_1210 { named_value_sersize_of_row_binary(id_1209) };
                                                                                    Size id_1211 { Size(id_1205 + id_1210) };
                                                                                    Void id_1212 { ((void)(sz_ref_545[id_1203] = id_1211), ::dessser::VOID) };
                                                                                    (void)id_1212;
                                                                                    uint8_t id_1213 { 0 };
                                                                                    uint8_t id_1214 { 0 };
                                                                                    int32_t id_1215 { repeat_n_546[id_1214] };
                                                                                    int32_t id_1216 { 1L };
                                                                                    int32_t id_1217 { int32_t(id_1215 + id_1216) };
                                                                                    Void id_1218 { ((void)(repeat_n_546[id_1213] = id_1217), ::dessser::VOID) };
                                                                                    (void)id_1218;
                                                                                    (void)id_1218;
                                                                                  }
                                                                                } while (while_flag_1196);
                                                                                (void)::dessser::VOID;
                                                                              }
                                                                              (void)::dessser::VOID;
                                                                              uint8_t id_1219 { 0 };
                                                                              Size id_1220 { sz_ref_545[id_1219] };
                                                                              let_res_1193 = id_1220;
                                                                            }
                                                                            choose_res_1165 = let_res_1193;
                                                                          } else {
                                                                            uint16_t id_1221 { 35 };
                                                                            bool id_1222 { bool(label2_536 == id_1221) };
                                                                            Void id_1223 { ((void)(assert(id_1222)), ::dessser::VOID) };
                                                                            (void)id_1223;
                                                                            Size id_1224 { 2UL };
                                                                            Arr<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d> id_1225 { std::get<35 /* VMap */>((*p_0)) };
                                                                            uint32_t id_1226 { id_1225.size() };
                                                                            Vec<1, uint32_t> id_1227 {  id_1226  };
                                                                            Size let_res_1228;
                                                                            {
                                                                              Vec<1, uint32_t> n_ref_537 { id_1227 };
                                                                              uint32_t id_1229 { 1U };
                                                                              Vec<1, uint32_t> id_1230 {  id_1229  };
                                                                              Size let_res_1231;
                                                                              {
                                                                                Vec<1, uint32_t> lebsz_ref_538 { id_1230 };
                                                                                bool while_flag_1232 { true };
                                                                                do {
                                                                                  uint8_t id_1233 { 0 };
                                                                                  uint32_t id_1234 { n_ref_537[id_1233] };
                                                                                  uint8_t id_1235 { 0 };
                                                                                  uint32_t id_1236 { lebsz_ref_538[id_1235] };
                                                                                  uint8_t id_1237 { 7 };
                                                                                  uint32_t id_1238 { uint32_t(id_1236 << id_1237) };
                                                                                  bool id_1239 { bool(id_1234 >= id_1238) };
                                                                                  while_flag_1232 = id_1239;
                                                                                  if (while_flag_1232) {
                                                                                    uint8_t id_1240 { 0 };
                                                                                    uint8_t id_1241 { 0 };
                                                                                    uint32_t id_1242 { lebsz_ref_538[id_1241] };
                                                                                    uint32_t id_1243 { 1U };
                                                                                    uint32_t id_1244 { uint32_t(id_1242 + id_1243) };
                                                                                    Void id_1245 { ((void)(lebsz_ref_538[id_1240] = id_1244), ::dessser::VOID) };
                                                                                    (void)id_1245;
                                                                                  }
                                                                                } while (while_flag_1232);
                                                                                (void)::dessser::VOID;
                                                                                uint8_t id_1246 { 0 };
                                                                                uint32_t id_1247 { lebsz_ref_538[id_1246] };
                                                                                Size id_1248 { Size(id_1247) };
                                                                                let_res_1231 = id_1248;
                                                                              }
                                                                              let_res_1228 = let_res_1231;
                                                                            }
                                                                            Size id_1249 { Size(id_1224 + let_res_1228) };
                                                                            Vec<1, Size> id_1250 {  id_1249  };
                                                                            Size let_res_1251;
                                                                            {
                                                                              Vec<1, Size> sz_ref_539 { id_1250 };
                                                                              int32_t id_1252 { 0L };
                                                                              Vec<1, int32_t> id_1253 {  id_1252  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_540 { id_1253 };
                                                                                bool while_flag_1254 { true };
                                                                                do {
                                                                                  Arr<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d> id_1255 { std::get<35 /* VMap */>((*p_0)) };
                                                                                  uint32_t id_1256 { id_1255.size() };
                                                                                  int32_t id_1257 { int32_t(id_1256) };
                                                                                  uint8_t id_1258 { 0 };
                                                                                  int32_t id_1259 { repeat_n_540[id_1258] };
                                                                                  bool id_1260 { bool(id_1257 > id_1259) };
                                                                                  while_flag_1254 = id_1260;
                                                                                  if (while_flag_1254) {
                                                                                    uint8_t id_1261 { 0 };
                                                                                    uint8_t id_1262 { 0 };
                                                                                    Size id_1263 { sz_ref_539[id_1262] };
                                                                                    uint8_t id_1264 { 0 };
                                                                                    int32_t id_1265 { repeat_n_540[id_1264] };
                                                                                    Arr<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d> id_1266 { std::get<35 /* VMap */>((*p_0)) };
                                                                                    ::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d id_1267 { id_1266[id_1265] };
                                                                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_1268 { std::get<0>(id_1267) };
                                                                                    Size id_1269 { fun811(id_1268) };
                                                                                    Size id_1270 { Size(id_1263 + id_1269) };
                                                                                    uint8_t id_1271 { 0 };
                                                                                    int32_t id_1272 { repeat_n_540[id_1271] };
                                                                                    Arr<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d> id_1273 { std::get<35 /* VMap */>((*p_0)) };
                                                                                    ::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d id_1274 { id_1273[id_1272] };
                                                                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_1275 { std::get<1>(id_1274) };
                                                                                    Size id_1276 { fun811(id_1275) };
                                                                                    Size id_1277 { Size(id_1270 + id_1276) };
                                                                                    Void id_1278 { ((void)(sz_ref_539[id_1261] = id_1277), ::dessser::VOID) };
                                                                                    (void)id_1278;
                                                                                    uint8_t id_1279 { 0 };
                                                                                    uint8_t id_1280 { 0 };
                                                                                    int32_t id_1281 { repeat_n_540[id_1280] };
                                                                                    int32_t id_1282 { 1L };
                                                                                    int32_t id_1283 { int32_t(id_1281 + id_1282) };
                                                                                    Void id_1284 { ((void)(repeat_n_540[id_1279] = id_1283), ::dessser::VOID) };
                                                                                    (void)id_1284;
                                                                                    (void)id_1284;
                                                                                  }
                                                                                } while (while_flag_1254);
                                                                                (void)::dessser::VOID;
                                                                              }
                                                                              (void)::dessser::VOID;
                                                                              uint8_t id_1285 { 0 };
                                                                              Size id_1286 { sz_ref_539[id_1285] };
                                                                              let_res_1251 = id_1286;
                                                                            }
                                                                            choose_res_1165 = let_res_1251;
                                                                          }
                                                                          choose_res_1107 = choose_res_1165;
                                                                        }
                                                                        choose_res_1049 = choose_res_1107;
                                                                      }
                                                                      choose_res_991 = choose_res_1049;
                                                                    }
                                                                    choose_res_976 = choose_res_991;
                                                                  }
                                                                  choose_res_972 = choose_res_976;
                                                                }
                                                                choose_res_968 = choose_res_972;
                                                              }
                                                              choose_res_953 = choose_res_968;
                                                            }
                                                            choose_res_949 = choose_res_953;
                                                          }
                                                          choose_res_945 = choose_res_949;
                                                        }
                                                        choose_res_941 = choose_res_945;
                                                      }
                                                      choose_res_937 = choose_res_941;
                                                    }
                                                    choose_res_933 = choose_res_937;
                                                  }
                                                  choose_res_929 = choose_res_933;
                                                }
                                                choose_res_925 = choose_res_929;
                                              }
                                              choose_res_921 = choose_res_925;
                                            }
                                            choose_res_917 = choose_res_921;
                                          }
                                          choose_res_913 = choose_res_917;
                                        }
                                        choose_res_909 = choose_res_913;
                                      }
                                      choose_res_905 = choose_res_909;
                                    }
                                    choose_res_901 = choose_res_905;
                                  }
                                  choose_res_897 = choose_res_901;
                                }
                                choose_res_893 = choose_res_897;
                              }
                              choose_res_889 = choose_res_893;
                            }
                            choose_res_885 = choose_res_889;
                          }
                          choose_res_881 = choose_res_885;
                        }
                        choose_res_877 = choose_res_881;
                      }
                      choose_res_873 = choose_res_877;
                    }
                    choose_res_869 = choose_res_873;
                  }
                  choose_res_865 = choose_res_869;
                }
                choose_res_861 = choose_res_865;
              }
              choose_res_828 = choose_res_861;
            }
            choose_res_824 = choose_res_828;
          }
          choose_res_820 = choose_res_824;
        }
        choose_res_816 = choose_res_820;
      }
      let_res_813 = choose_res_816;
    }
    return let_res_813;
  }
   };
  return fun811;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_value::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("(STRING; THIS)")
      (let "sz_535"
        (add
          (let "n_ref_533" (make-vec (string-length (get-item 0 (param 0))))
            (let "lebsz_ref_534" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_533")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_534")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_534") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_534")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_534")))))) 
          (size-of-u32 (string-length (get-item 0 (param 0))))) (add (identifier "sz_535") (apply (identifier "sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_value::named_value> )> named_value_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_value::named_value> )> fun1287 { [&fun1287](std::shared_ptr<::dessser::gen::raql_value::named_value>  p_0) {
    std::string id_1288 { std::get<0>((*p_0)) };
    uint32_t id_1289 { (uint32_t)id_1288.size() };
    Vec<1, uint32_t> id_1290 {  id_1289  };
    Size let_res_1291;
    {
      Vec<1, uint32_t> n_ref_533 { id_1290 };
      uint32_t id_1292 { 1U };
      Vec<1, uint32_t> id_1293 {  id_1292  };
      Size let_res_1294;
      {
        Vec<1, uint32_t> lebsz_ref_534 { id_1293 };
        bool while_flag_1295 { true };
        do {
          uint8_t id_1296 { 0 };
          uint32_t id_1297 { n_ref_533[id_1296] };
          uint8_t id_1298 { 0 };
          uint32_t id_1299 { lebsz_ref_534[id_1298] };
          uint8_t id_1300 { 7 };
          uint32_t id_1301 { uint32_t(id_1299 << id_1300) };
          bool id_1302 { bool(id_1297 >= id_1301) };
          while_flag_1295 = id_1302;
          if (while_flag_1295) {
            uint8_t id_1303 { 0 };
            uint8_t id_1304 { 0 };
            uint32_t id_1305 { lebsz_ref_534[id_1304] };
            uint32_t id_1306 { 1U };
            uint32_t id_1307 { uint32_t(id_1305 + id_1306) };
            Void id_1308 { ((void)(lebsz_ref_534[id_1303] = id_1307), ::dessser::VOID) };
            (void)id_1308;
          }
        } while (while_flag_1295);
        (void)::dessser::VOID;
        uint8_t id_1309 { 0 };
        uint32_t id_1310 { lebsz_ref_534[id_1309] };
        Size id_1311 { Size(id_1310) };
        let_res_1294 = id_1311;
      }
      let_res_1291 = let_res_1294;
    }
    std::string id_1312 { std::get<0>((*p_0)) };
    uint32_t id_1313 { (uint32_t)id_1312.size() };
    Size id_1314 { Size(id_1313) };
    Size id_1315 { Size(let_res_1291 + id_1314) };
    Size let_res_1316;
    {
      Size sz_535 { id_1315 };
      std::shared_ptr<::dessser::gen::raql_value::t>  id_1317 { std::get<1>((*p_0)) };
      Size id_1318 { sersize_of_row_binary(id_1317) };
      Size id_1319 { Size(sz_535 + id_1318) };
      let_res_1316 = id_1319;
    }
    return let_res_1316;
  }
   };
  return fun1287;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_value::named_value> )> named_value_sersize_of_row_binary(named_value_sersize_of_row_binary_init());

/* 
    (fun ("[VNull Void | VUnit Void | VFloat FLOAT | VString STRING | VBool BOOL | VChar CHAR | VU8 U8 | VU16 U16 | VU24 U24 | VU32 U32 | VU40 U40 | VU48 U48 | VU56 U56 | VU64 U64 | VU128 U128 | VI8 I8 | VI16 I16 | VI24 I24 | VI32 I32 | VI40 I40 | VI48 I48 | VI56 I56 | VI64 I64 | VI128 I128 | VEth Eth | VIpv4 Ip4 | VIpv6 Ip6 | VIp Ip | VCidrv4 Cidr4 | VCidrv6 Cidr6 | VCidr Cidr | VTup THIS[] | VVec THIS[] | VArr THIS[] | VRec (named_value AS (STRING; THIS))[] | VMap (THIS; THIS)[]]" "Ptr")
      (let "label1_575" (label-of (param 0))
        (let "ssum_dst_576" (write-u16 little-endian (param 1) (identifier "label1_575"))
          (if (eq (u16 0) (identifier "label1_575")) (identifier "ssum_dst_576")
            (if (eq (u16 1) (identifier "label1_575")) (identifier "ssum_dst_576")
              (if (eq (u16 2) (identifier "label1_575")) (write-u64 little-endian (identifier "ssum_dst_576") (u64-of-float (get-alt "VFloat" (param 0))))
                (if (eq (u16 3) (identifier "label1_575"))
                  (write-bytes
                    (let "leb128_sz_612" (make-vec (string-length (get-alt "VString" (param 0))))
                      (let "leb128_ptr_613" (make-vec (identifier "ssum_dst_576"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_613")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_613"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_612"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_612"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_612"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_612") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_612")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_612")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_613"))))) 
                    (bytes-of-string (get-alt "VString" (param 0))))
                  (if (eq (u16 4) (identifier "label1_575")) (write-u8 (identifier "ssum_dst_576") (u8-of-bool (get-alt "VBool" (param 0))))
                    (if (eq (u16 5) (identifier "label1_575")) (write-u8 (identifier "ssum_dst_576") (u8-of-char (get-alt "VChar" (param 0))))
                      (if (eq (u16 6) (identifier "label1_575")) (write-u8 (identifier "ssum_dst_576") (get-alt "VU8" (param 0)))
                        (if (eq (u16 7) (identifier "label1_575")) (write-u16 little-endian (identifier "ssum_dst_576") (get-alt "VU16" (param 0)))
                          (if (eq (u16 8) (identifier "label1_575")) 
                            (write-u32 little-endian (identifier "ssum_dst_576") (to-u32 (get-alt "VU24" (param 0))))
                            (if (eq (u16 9) (identifier "label1_575")) 
                              (write-u32 little-endian (identifier "ssum_dst_576") (get-alt "VU32" (param 0)))
                              (if (eq (u16 10) (identifier "label1_575")) 
                                (write-u64 little-endian (identifier "ssum_dst_576") (to-u64 (get-alt "VU40" (param 0))))
                                (if (eq (u16 11) (identifier "label1_575")) 
                                  (write-u64 little-endian (identifier "ssum_dst_576") (to-u64 (get-alt "VU48" (param 0))))
                                  (if (eq (u16 12) (identifier "label1_575")) 
                                    (write-u64 little-endian (identifier "ssum_dst_576") (to-u64 (get-alt "VU56" (param 0))))
                                    (if (eq (u16 13) (identifier "label1_575")) 
                                      (write-u64 little-endian (identifier "ssum_dst_576") (get-alt "VU64" (param 0)))
                                      (if (eq (u16 14) (identifier "label1_575")) 
                                        (write-u128 little-endian (identifier "ssum_dst_576") (get-alt "VU128" (param 0)))
                                        (if (eq (u16 15) (identifier "label1_575")) 
                                          (write-u8 (identifier "ssum_dst_576") (to-u8 (get-alt "VI8" (param 0))))
                                          (if (eq (u16 16) (identifier "label1_575")) 
                                            (write-u16 little-endian (identifier "ssum_dst_576") (to-u16 (get-alt "VI16" (param 0))))
                                            (if (eq (u16 17) (identifier "label1_575")) 
                                              (write-u32 little-endian (identifier "ssum_dst_576") (to-u32 (to-i32 (get-alt "VI24" (param 0)))))
                                              (if (eq (u16 18) (identifier "label1_575")) 
                                                (write-u32 little-endian (identifier "ssum_dst_576") (to-u32 (get-alt "VI32" (param 0))))
                                                (if (eq (u16 19) (identifier "label1_575")) 
                                                  (write-u64 little-endian (identifier "ssum_dst_576") (to-u64 (to-i64 (get-alt "VI40" (param 0)))))
                                                  (if (eq (u16 20) (identifier "label1_575")) 
                                                    (write-u64 little-endian (identifier "ssum_dst_576") (to-u64 (to-i64 (get-alt "VI48" (param 0)))))
                                                    (if (eq (u16 21) (identifier "label1_575")) 
                                                      (write-u64 little-endian (identifier "ssum_dst_576") (to-u64 (to-i64 (get-alt "VI56" (param 0)))))
                                                      (if (eq (u16 22) (identifier "label1_575")) 
                                                        (write-u64 little-endian (identifier "ssum_dst_576") (to-u64 (get-alt "VI64" (param 0))))
                                                        (if (eq (u16 23) (identifier "label1_575")) 
                                                          (write-u128 little-endian (identifier "ssum_dst_576") (to-u128 (get-alt "VI128" (param 0))))
                                                          (if (eq (u16 24) (identifier "label1_575")) 
                                                            (write-u64 little-endian (identifier "ssum_dst_576") (to-u64 (get-alt "VEth" (param 0))))
                                                            (if (eq (u16 25) (identifier "label1_575")) 
                                                              (write-u32 little-endian (identifier "ssum_dst_576") (get-alt "VIpv4" (param 0)))
                                                              (if (eq (u16 26) (identifier "label1_575")) 
                                                                (write-u128 little-endian (identifier "ssum_dst_576") (get-alt "VIpv6" (param 0)))
                                                                (if (eq (u16 27) (identifier "label1_575"))
                                                                  (let "ssum_dst_611" 
                                                                    (write-u16 little-endian (identifier "ssum_dst_576") (label-of (get-alt "VIp" (param 0))))
                                                                    (if 
                                                                    (eq (u16 0) (label-of (get-alt "VIp" (param 0)))) 
                                                                    (write-u32 little-endian (identifier "ssum_dst_611") (get-alt "v4" (get-alt "VIp" (param 0))))
                                                                    (seq (assert (eq (label-of (get-alt "VIp" (param 0))) (u16 1))) (write-u128 little-endian (identifier "ssum_dst_611") (get-alt "v6" (get-alt "VIp" (param 0)))))))
                                                                  (if 
                                                                    (eq (u16 28) (identifier "label1_575"))
                                                                    (let "srec_dst_609" 
                                                                    (write-u32 little-endian (identifier "ssum_dst_576") (get-field "ip" (get-alt "VCidrv4" (param 0))))
                                                                    (write-u8 (identifier "srec_dst_609") (get-field "mask" (get-alt "VCidrv4" (param 0)))))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "label1_575"))
                                                                    (let "srec_dst_608" 
                                                                    (write-u128 little-endian (identifier "ssum_dst_576") (get-field "ip" (get-alt "VCidrv6" (param 0))))
                                                                    (write-u8 (identifier "srec_dst_608") (get-field "mask" (get-alt "VCidrv6" (param 0)))))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label1_575"))
                                                                    (let "ssum_dst_605" 
                                                                    (write-u16 little-endian (identifier "ssum_dst_576") (label-of (get-alt "VCidr" (param 0))))
                                                                    (if 
                                                                    (eq (u16 0) (label-of (get-alt "VCidr" (param 0))))
                                                                    (let "srec_dst_607" 
                                                                    (write-u32 little-endian (identifier "ssum_dst_605") (get-field "ip" (get-alt "v4" (get-alt "VCidr" (param 0)))))
                                                                    (write-u8 (identifier "srec_dst_607") (get-field "mask" (get-alt "v4" (get-alt "VCidr" (param 0))))))
                                                                    (seq 
                                                                    (assert (eq (label-of (get-alt "VCidr" (param 0))) (u16 1)))
                                                                    (let "srec_dst_606" 
                                                                    (write-u128 little-endian (identifier "ssum_dst_605") (get-field "ip" (get-alt "v6" (get-alt "VCidr" (param 0)))))
                                                                    (write-u8 (identifier "srec_dst_606") (get-field "mask" (get-alt "v6" (get-alt "VCidr" (param 0)))))))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label1_575"))
                                                                    (let "dst_ref_601"
                                                                    (make-vec
                                                                    (let "leb128_sz_599" 
                                                                    (make-vec (cardinality (get-alt "VTup" (param 0))))
                                                                    (let "leb128_ptr_600" 
                                                                    (make-vec (identifier "ssum_dst_576"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_600")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_600"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_599"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_599"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_599"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_599") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_599")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_599")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_600"))))))
                                                                    (let "n_ref_602" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_603" 
                                                                    (get-alt "VTup" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_601") (apply (myself "Ptr") (identifier "x_603") (unsafe-nth (u8 0) (identifier "dst_ref_601"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_602") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_602")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_601")))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label1_575"))
                                                                    (let "dst_ref_596"
                                                                    (make-vec
                                                                    (let "leb128_sz_594" 
                                                                    (make-vec (cardinality (get-alt "VVec" (param 0))))
                                                                    (let "leb128_ptr_595" 
                                                                    (make-vec (identifier "ssum_dst_576"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_595")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_595"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_594"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_594"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_594"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_594") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_594")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_594")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_595"))))))
                                                                    (let "n_ref_597" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_598" 
                                                                    (get-alt "VVec" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_596") (apply (myself "Ptr") (identifier "x_598") (unsafe-nth (u8 0) (identifier "dst_ref_596"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_597") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_597")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_596")))))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label1_575"))
                                                                    (let "dst_ref_591"
                                                                    (make-vec
                                                                    (let "leb128_sz_589" 
                                                                    (make-vec (cardinality (get-alt "VArr" (param 0))))
                                                                    (let "leb128_ptr_590" 
                                                                    (make-vec (identifier "ssum_dst_576"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_590")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_590"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_589"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_589"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_589"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_589") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_589")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_589")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_590"))))))
                                                                    (let "n_ref_592" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_593" 
                                                                    (get-alt "VArr" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_591") (apply (myself "Ptr") (identifier "x_593") (unsafe-nth (u8 0) (identifier "dst_ref_591"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_592") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_592")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_591")))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label1_575"))
                                                                    (let "dst_ref_586"
                                                                    (make-vec
                                                                    (let "leb128_sz_584" 
                                                                    (make-vec (cardinality (get-alt "VRec" (param 0))))
                                                                    (let "leb128_ptr_585" 
                                                                    (make-vec (identifier "ssum_dst_576"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_585")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_585"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_584"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_584"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_584"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_584") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_584")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_584")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_585"))))))
                                                                    (let "n_ref_587" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_588" 
                                                                    (get-alt "VRec" (param 0))
                                                                    (seq
                                                                    (set-vec (u8 0) (identifier "dst_ref_586") (apply (identifier "named_value-to-row-binary") (identifier "x_588") (unsafe-nth (u8 0) (identifier "dst_ref_586"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_587") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_587")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_586")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label1_575") (u16 35)))
                                                                    (let "dst_ref_579"
                                                                    (make-vec
                                                                    (let "leb128_sz_577" 
                                                                    (make-vec (cardinality (get-alt "VMap" (param 0))))
                                                                    (let "leb128_ptr_578" 
                                                                    (make-vec (identifier "ssum_dst_576"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_578")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_578"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_577"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_577"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_577"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_577") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_577")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_577")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_578"))))))
                                                                    (let "n_ref_580" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_581" 
                                                                    (get-alt "VMap" (param 0))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "dst_ref_579")
                                                                    (apply (myself "Ptr") (get-item 1 (identifier "x_581")) (apply (myself "Ptr") (get-item 0 (identifier "x_581")) (unsafe-nth (u8 0) (identifier "dst_ref_579")))))
                                                                    (set-vec (u8 0) (identifier "n_ref_580") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_580")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_579"))))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> fun1320 { [&fun1320](std::shared_ptr<::dessser::gen::raql_value::t>  p_0, Pointer p_1) {
    uint16_t id_1321 { uint16_t((*p_0).index()) };
    Pointer let_res_1322;
    {
      uint16_t label1_575 { id_1321 };
      Pointer id_1323 { p_1.writeU16Le(label1_575) };
      Pointer let_res_1324;
      {
        Pointer ssum_dst_576 { id_1323 };
        uint16_t id_1325 { 0 };
        bool id_1326 { bool(id_1325 == label1_575) };
        Pointer choose_res_1327;
        if (id_1326) {
          choose_res_1327 = ssum_dst_576;
        } else {
          uint16_t id_1328 { 1 };
          bool id_1329 { bool(id_1328 == label1_575) };
          Pointer choose_res_1330;
          if (id_1329) {
            choose_res_1330 = ssum_dst_576;
          } else {
            uint16_t id_1331 { 2 };
            bool id_1332 { bool(id_1331 == label1_575) };
            Pointer choose_res_1333;
            if (id_1332) {
              double id_1334 { std::get<2 /* VFloat */>((*p_0)) };
              uint64_t id_1335 { qword_of_float(id_1334) };
              Pointer id_1336 { ssum_dst_576.writeU64Le(id_1335) };
              choose_res_1333 = id_1336;
            } else {
              uint16_t id_1337 { 3 };
              bool id_1338 { bool(id_1337 == label1_575) };
              Pointer choose_res_1339;
              if (id_1338) {
                std::string id_1340 { std::get<3 /* VString */>((*p_0)) };
                uint32_t id_1341 { (uint32_t)id_1340.size() };
                Vec<1, uint32_t> id_1342 {  id_1341  };
                Pointer let_res_1343;
                {
                  Vec<1, uint32_t> leb128_sz_612 { id_1342 };
                  Vec<1, Pointer> id_1344 {  ssum_dst_576  };
                  Pointer let_res_1345;
                  {
                    Vec<1, Pointer> leb128_ptr_613 { id_1344 };
                    bool while_flag_1346 { true };
                    do {
                      uint8_t id_1347 { 0 };
                      uint8_t id_1348 { 0 };
                      Pointer id_1349 { leb128_ptr_613[id_1348] };
                      uint32_t id_1350 { 128U };
                      uint8_t id_1351 { 0 };
                      uint32_t id_1352 { leb128_sz_612[id_1351] };
                      bool id_1353 { bool(id_1350 > id_1352) };
                      uint8_t choose_res_1354;
                      if (id_1353) {
                        uint8_t id_1355 { 0 };
                        uint32_t id_1356 { leb128_sz_612[id_1355] };
                        uint8_t id_1357 { uint8_t(id_1356) };
                        choose_res_1354 = id_1357;
                      } else {
                        uint8_t id_1358 { 0 };
                        uint32_t id_1359 { leb128_sz_612[id_1358] };
                        uint8_t id_1360 { uint8_t(id_1359) };
                        uint8_t id_1361 { 128 };
                        uint8_t id_1362 { uint8_t(id_1360 | id_1361) };
                        choose_res_1354 = id_1362;
                      }
                      Pointer id_1363 { id_1349.writeU8(choose_res_1354) };
                      Void id_1364 { ((void)(leb128_ptr_613[id_1347] = id_1363), ::dessser::VOID) };
                      (void)id_1364;
                      uint8_t id_1365 { 0 };
                      uint8_t id_1366 { 0 };
                      uint32_t id_1367 { leb128_sz_612[id_1366] };
                      uint8_t id_1368 { 7 };
                      uint32_t id_1369 { uint32_t(id_1367 >> id_1368) };
                      Void id_1370 { ((void)(leb128_sz_612[id_1365] = id_1369), ::dessser::VOID) };
                      (void)id_1370;
                      uint8_t id_1371 { 0 };
                      uint32_t id_1372 { leb128_sz_612[id_1371] };
                      uint32_t id_1373 { 0U };
                      bool id_1374 { bool(id_1372 > id_1373) };
                      while_flag_1346 = id_1374;
                      if (while_flag_1346) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_1346);
                    (void)::dessser::VOID;
                    uint8_t id_1375 { 0 };
                    Pointer id_1376 { leb128_ptr_613[id_1375] };
                    let_res_1345 = id_1376;
                  }
                  let_res_1343 = let_res_1345;
                }
                std::string id_1377 { std::get<3 /* VString */>((*p_0)) };
                Bytes id_1378 { id_1377 };
                Pointer id_1379 { let_res_1343.writeBytes(id_1378) };
                choose_res_1339 = id_1379;
              } else {
                uint16_t id_1380 { 4 };
                bool id_1381 { bool(id_1380 == label1_575) };
                Pointer choose_res_1382;
                if (id_1381) {
                  bool id_1383 { std::get<4 /* VBool */>((*p_0)) };
                  uint8_t id_1384 { uint8_t(id_1383) };
                  Pointer id_1385 { ssum_dst_576.writeU8(id_1384) };
                  choose_res_1382 = id_1385;
                } else {
                  uint16_t id_1386 { 5 };
                  bool id_1387 { bool(id_1386 == label1_575) };
                  Pointer choose_res_1388;
                  if (id_1387) {
                    char id_1389 { std::get<5 /* VChar */>((*p_0)) };
                    uint8_t id_1390 { uint8_t(id_1389) };
                    Pointer id_1391 { ssum_dst_576.writeU8(id_1390) };
                    choose_res_1388 = id_1391;
                  } else {
                    uint16_t id_1392 { 6 };
                    bool id_1393 { bool(id_1392 == label1_575) };
                    Pointer choose_res_1394;
                    if (id_1393) {
                      uint8_t id_1395 { std::get<6 /* VU8 */>((*p_0)) };
                      Pointer id_1396 { ssum_dst_576.writeU8(id_1395) };
                      choose_res_1394 = id_1396;
                    } else {
                      uint16_t id_1397 { 7 };
                      bool id_1398 { bool(id_1397 == label1_575) };
                      Pointer choose_res_1399;
                      if (id_1398) {
                        uint16_t id_1400 { std::get<7 /* VU16 */>((*p_0)) };
                        Pointer id_1401 { ssum_dst_576.writeU16Le(id_1400) };
                        choose_res_1399 = id_1401;
                      } else {
                        uint16_t id_1402 { 8 };
                        bool id_1403 { bool(id_1402 == label1_575) };
                        Pointer choose_res_1404;
                        if (id_1403) {
                          uint32_t id_1405 { std::get<8 /* VU24 */>((*p_0)) };
                          uint32_t id_1406 { uint32_t(id_1405) };
                          Pointer id_1407 { ssum_dst_576.writeU32Le(id_1406) };
                          choose_res_1404 = id_1407;
                        } else {
                          uint16_t id_1408 { 9 };
                          bool id_1409 { bool(id_1408 == label1_575) };
                          Pointer choose_res_1410;
                          if (id_1409) {
                            uint32_t id_1411 { std::get<9 /* VU32 */>((*p_0)) };
                            Pointer id_1412 { ssum_dst_576.writeU32Le(id_1411) };
                            choose_res_1410 = id_1412;
                          } else {
                            uint16_t id_1413 { 10 };
                            bool id_1414 { bool(id_1413 == label1_575) };
                            Pointer choose_res_1415;
                            if (id_1414) {
                              uint64_t id_1416 { std::get<10 /* VU40 */>((*p_0)) };
                              uint64_t id_1417 { uint64_t(id_1416) };
                              Pointer id_1418 { ssum_dst_576.writeU64Le(id_1417) };
                              choose_res_1415 = id_1418;
                            } else {
                              uint16_t id_1419 { 11 };
                              bool id_1420 { bool(id_1419 == label1_575) };
                              Pointer choose_res_1421;
                              if (id_1420) {
                                uint64_t id_1422 { std::get<11 /* VU48 */>((*p_0)) };
                                uint64_t id_1423 { uint64_t(id_1422) };
                                Pointer id_1424 { ssum_dst_576.writeU64Le(id_1423) };
                                choose_res_1421 = id_1424;
                              } else {
                                uint16_t id_1425 { 12 };
                                bool id_1426 { bool(id_1425 == label1_575) };
                                Pointer choose_res_1427;
                                if (id_1426) {
                                  uint64_t id_1428 { std::get<12 /* VU56 */>((*p_0)) };
                                  uint64_t id_1429 { uint64_t(id_1428) };
                                  Pointer id_1430 { ssum_dst_576.writeU64Le(id_1429) };
                                  choose_res_1427 = id_1430;
                                } else {
                                  uint16_t id_1431 { 13 };
                                  bool id_1432 { bool(id_1431 == label1_575) };
                                  Pointer choose_res_1433;
                                  if (id_1432) {
                                    uint64_t id_1434 { std::get<13 /* VU64 */>((*p_0)) };
                                    Pointer id_1435 { ssum_dst_576.writeU64Le(id_1434) };
                                    choose_res_1433 = id_1435;
                                  } else {
                                    uint16_t id_1436 { 14 };
                                    bool id_1437 { bool(id_1436 == label1_575) };
                                    Pointer choose_res_1438;
                                    if (id_1437) {
                                      uint128_t id_1439 { std::get<14 /* VU128 */>((*p_0)) };
                                      Pointer id_1440 { ssum_dst_576.writeU128Le(id_1439) };
                                      choose_res_1438 = id_1440;
                                    } else {
                                      uint16_t id_1441 { 15 };
                                      bool id_1442 { bool(id_1441 == label1_575) };
                                      Pointer choose_res_1443;
                                      if (id_1442) {
                                        int8_t id_1444 { std::get<15 /* VI8 */>((*p_0)) };
                                        uint8_t id_1445 { uint8_t(id_1444) };
                                        Pointer id_1446 { ssum_dst_576.writeU8(id_1445) };
                                        choose_res_1443 = id_1446;
                                      } else {
                                        uint16_t id_1447 { 16 };
                                        bool id_1448 { bool(id_1447 == label1_575) };
                                        Pointer choose_res_1449;
                                        if (id_1448) {
                                          int16_t id_1450 { std::get<16 /* VI16 */>((*p_0)) };
                                          uint16_t id_1451 { uint16_t(id_1450) };
                                          Pointer id_1452 { ssum_dst_576.writeU16Le(id_1451) };
                                          choose_res_1449 = id_1452;
                                        } else {
                                          uint16_t id_1453 { 17 };
                                          bool id_1454 { bool(id_1453 == label1_575) };
                                          Pointer choose_res_1455;
                                          if (id_1454) {
                                            int32_t id_1456 { std::get<17 /* VI24 */>((*p_0)) };
                                            int32_t id_1457 { int32_t(id_1456) };
                                            uint32_t id_1458 { uint32_t(id_1457) };
                                            Pointer id_1459 { ssum_dst_576.writeU32Le(id_1458) };
                                            choose_res_1455 = id_1459;
                                          } else {
                                            uint16_t id_1460 { 18 };
                                            bool id_1461 { bool(id_1460 == label1_575) };
                                            Pointer choose_res_1462;
                                            if (id_1461) {
                                              int32_t id_1463 { std::get<18 /* VI32 */>((*p_0)) };
                                              uint32_t id_1464 { uint32_t(id_1463) };
                                              Pointer id_1465 { ssum_dst_576.writeU32Le(id_1464) };
                                              choose_res_1462 = id_1465;
                                            } else {
                                              uint16_t id_1466 { 19 };
                                              bool id_1467 { bool(id_1466 == label1_575) };
                                              Pointer choose_res_1468;
                                              if (id_1467) {
                                                int64_t id_1469 { std::get<19 /* VI40 */>((*p_0)) };
                                                int64_t id_1470 { int64_t(id_1469) };
                                                uint64_t id_1471 { uint64_t(id_1470) };
                                                Pointer id_1472 { ssum_dst_576.writeU64Le(id_1471) };
                                                choose_res_1468 = id_1472;
                                              } else {
                                                uint16_t id_1473 { 20 };
                                                bool id_1474 { bool(id_1473 == label1_575) };
                                                Pointer choose_res_1475;
                                                if (id_1474) {
                                                  int64_t id_1476 { std::get<20 /* VI48 */>((*p_0)) };
                                                  int64_t id_1477 { int64_t(id_1476) };
                                                  uint64_t id_1478 { uint64_t(id_1477) };
                                                  Pointer id_1479 { ssum_dst_576.writeU64Le(id_1478) };
                                                  choose_res_1475 = id_1479;
                                                } else {
                                                  uint16_t id_1480 { 21 };
                                                  bool id_1481 { bool(id_1480 == label1_575) };
                                                  Pointer choose_res_1482;
                                                  if (id_1481) {
                                                    int64_t id_1483 { std::get<21 /* VI56 */>((*p_0)) };
                                                    int64_t id_1484 { int64_t(id_1483) };
                                                    uint64_t id_1485 { uint64_t(id_1484) };
                                                    Pointer id_1486 { ssum_dst_576.writeU64Le(id_1485) };
                                                    choose_res_1482 = id_1486;
                                                  } else {
                                                    uint16_t id_1487 { 22 };
                                                    bool id_1488 { bool(id_1487 == label1_575) };
                                                    Pointer choose_res_1489;
                                                    if (id_1488) {
                                                      int64_t id_1490 { std::get<22 /* VI64 */>((*p_0)) };
                                                      uint64_t id_1491 { uint64_t(id_1490) };
                                                      Pointer id_1492 { ssum_dst_576.writeU64Le(id_1491) };
                                                      choose_res_1489 = id_1492;
                                                    } else {
                                                      uint16_t id_1493 { 23 };
                                                      bool id_1494 { bool(id_1493 == label1_575) };
                                                      Pointer choose_res_1495;
                                                      if (id_1494) {
                                                        int128_t id_1496 { std::get<23 /* VI128 */>((*p_0)) };
                                                        uint128_t id_1497 { uint128_t(id_1496) };
                                                        Pointer id_1498 { ssum_dst_576.writeU128Le(id_1497) };
                                                        choose_res_1495 = id_1498;
                                                      } else {
                                                        uint16_t id_1499 { 24 };
                                                        bool id_1500 { bool(id_1499 == label1_575) };
                                                        Pointer choose_res_1501;
                                                        if (id_1500) {
                                                          uint64_t id_1502 { std::get<24 /* VEth */>((*p_0)) };
                                                          uint64_t id_1503 { uint64_t(id_1502) };
                                                          Pointer id_1504 { ssum_dst_576.writeU64Le(id_1503) };
                                                          choose_res_1501 = id_1504;
                                                        } else {
                                                          uint16_t id_1505 { 25 };
                                                          bool id_1506 { bool(id_1505 == label1_575) };
                                                          Pointer choose_res_1507;
                                                          if (id_1506) {
                                                            uint32_t id_1508 { std::get<25 /* VIpv4 */>((*p_0)) };
                                                            Pointer id_1509 { ssum_dst_576.writeU32Le(id_1508) };
                                                            choose_res_1507 = id_1509;
                                                          } else {
                                                            uint16_t id_1510 { 26 };
                                                            bool id_1511 { bool(id_1510 == label1_575) };
                                                            Pointer choose_res_1512;
                                                            if (id_1511) {
                                                              uint128_t id_1513 { std::get<26 /* VIpv6 */>((*p_0)) };
                                                              Pointer id_1514 { ssum_dst_576.writeU128Le(id_1513) };
                                                              choose_res_1512 = id_1514;
                                                            } else {
                                                              uint16_t id_1515 { 27 };
                                                              bool id_1516 { bool(id_1515 == label1_575) };
                                                              Pointer choose_res_1517;
                                                              if (id_1516) {
                                                                ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_1518 { std::get<27 /* VIp */>((*p_0)) };
                                                                uint16_t id_1519 { uint16_t(id_1518.index()) };
                                                                Pointer id_1520 { ssum_dst_576.writeU16Le(id_1519) };
                                                                Pointer let_res_1521;
                                                                {
                                                                  Pointer ssum_dst_611 { id_1520 };
                                                                  uint16_t id_1522 { 0 };
                                                                  ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_1523 { std::get<27 /* VIp */>((*p_0)) };
                                                                  uint16_t id_1524 { uint16_t(id_1523.index()) };
                                                                  bool id_1525 { bool(id_1522 == id_1524) };
                                                                  Pointer choose_res_1526;
                                                                  if (id_1525) {
                                                                    ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_1527 { std::get<27 /* VIp */>((*p_0)) };
                                                                    uint32_t id_1528 { std::get<0 /* v4 */>(id_1527) };
                                                                    Pointer id_1529 { ssum_dst_611.writeU32Le(id_1528) };
                                                                    choose_res_1526 = id_1529;
                                                                  } else {
                                                                    ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_1530 { std::get<27 /* VIp */>((*p_0)) };
                                                                    uint16_t id_1531 { uint16_t(id_1530.index()) };
                                                                    uint16_t id_1532 { 1 };
                                                                    bool id_1533 { bool(id_1531 == id_1532) };
                                                                    Void id_1534 { ((void)(assert(id_1533)), ::dessser::VOID) };
                                                                    (void)id_1534;
                                                                    ::dessser::gen::raql_value::tb689860ac91fca7822797a026958e891 id_1535 { std::get<27 /* VIp */>((*p_0)) };
                                                                    uint128_t id_1536 { std::get<1 /* v6 */>(id_1535) };
                                                                    Pointer id_1537 { ssum_dst_611.writeU128Le(id_1536) };
                                                                    choose_res_1526 = id_1537;
                                                                  }
                                                                  let_res_1521 = choose_res_1526;
                                                                }
                                                                choose_res_1517 = let_res_1521;
                                                              } else {
                                                                uint16_t id_1538 { 28 };
                                                                bool id_1539 { bool(id_1538 == label1_575) };
                                                                Pointer choose_res_1540;
                                                                if (id_1539) {
                                                                  ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_1541 { std::get<28 /* VCidrv4 */>((*p_0)) };
                                                                  uint32_t id_1542 { id_1541.Cidr4_ip };
                                                                  Pointer id_1543 { ssum_dst_576.writeU32Le(id_1542) };
                                                                  Pointer let_res_1544;
                                                                  {
                                                                    Pointer srec_dst_609 { id_1543 };
                                                                    ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_1545 { std::get<28 /* VCidrv4 */>((*p_0)) };
                                                                    uint8_t id_1546 { id_1545.Cidr4_mask };
                                                                    Pointer id_1547 { srec_dst_609.writeU8(id_1546) };
                                                                    let_res_1544 = id_1547;
                                                                  }
                                                                  choose_res_1540 = let_res_1544;
                                                                } else {
                                                                  uint16_t id_1548 { 29 };
                                                                  bool id_1549 { bool(id_1548 == label1_575) };
                                                                  Pointer choose_res_1550;
                                                                  if (id_1549) {
                                                                    ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_1551 { std::get<29 /* VCidrv6 */>((*p_0)) };
                                                                    uint128_t id_1552 { id_1551.ip };
                                                                    Pointer id_1553 { ssum_dst_576.writeU128Le(id_1552) };
                                                                    Pointer let_res_1554;
                                                                    {
                                                                      Pointer srec_dst_608 { id_1553 };
                                                                      ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_1555 { std::get<29 /* VCidrv6 */>((*p_0)) };
                                                                      uint8_t id_1556 { id_1555.mask };
                                                                      Pointer id_1557 { srec_dst_608.writeU8(id_1556) };
                                                                      let_res_1554 = id_1557;
                                                                    }
                                                                    choose_res_1550 = let_res_1554;
                                                                  } else {
                                                                    uint16_t id_1558 { 30 };
                                                                    bool id_1559 { bool(id_1558 == label1_575) };
                                                                    Pointer choose_res_1560;
                                                                    if (id_1559) {
                                                                      ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_1561 { std::get<30 /* VCidr */>((*p_0)) };
                                                                      uint16_t id_1562 { uint16_t(id_1561.index()) };
                                                                      Pointer id_1563 { ssum_dst_576.writeU16Le(id_1562) };
                                                                      Pointer let_res_1564;
                                                                      {
                                                                        Pointer ssum_dst_605 { id_1563 };
                                                                        uint16_t id_1565 { 0 };
                                                                        ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_1566 { std::get<30 /* VCidr */>((*p_0)) };
                                                                        uint16_t id_1567 { uint16_t(id_1566.index()) };
                                                                        bool id_1568 { bool(id_1565 == id_1567) };
                                                                        Pointer choose_res_1569;
                                                                        if (id_1568) {
                                                                          ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_1570 { std::get<30 /* VCidr */>((*p_0)) };
                                                                          ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_1571 { std::get<0 /* v4 */>(id_1570) };
                                                                          uint32_t id_1572 { id_1571.Cidr4_ip };
                                                                          Pointer id_1573 { ssum_dst_605.writeU32Le(id_1572) };
                                                                          Pointer let_res_1574;
                                                                          {
                                                                            Pointer srec_dst_607 { id_1573 };
                                                                            ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_1575 { std::get<30 /* VCidr */>((*p_0)) };
                                                                            ::dessser::gen::raql_value::t81f779acbcb9180b1df9b88e2d8ce982 id_1576 { std::get<0 /* v4 */>(id_1575) };
                                                                            uint8_t id_1577 { id_1576.Cidr4_mask };
                                                                            Pointer id_1578 { srec_dst_607.writeU8(id_1577) };
                                                                            let_res_1574 = id_1578;
                                                                          }
                                                                          choose_res_1569 = let_res_1574;
                                                                        } else {
                                                                          ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_1579 { std::get<30 /* VCidr */>((*p_0)) };
                                                                          uint16_t id_1580 { uint16_t(id_1579.index()) };
                                                                          uint16_t id_1581 { 1 };
                                                                          bool id_1582 { bool(id_1580 == id_1581) };
                                                                          Void id_1583 { ((void)(assert(id_1582)), ::dessser::VOID) };
                                                                          (void)id_1583;
                                                                          ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_1584 { std::get<30 /* VCidr */>((*p_0)) };
                                                                          ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_1585 { std::get<1 /* v6 */>(id_1584) };
                                                                          uint128_t id_1586 { id_1585.ip };
                                                                          Pointer id_1587 { ssum_dst_605.writeU128Le(id_1586) };
                                                                          Pointer let_res_1588;
                                                                          {
                                                                            Pointer srec_dst_606 { id_1587 };
                                                                            ::dessser::gen::raql_value::t086a8e00718450baf3e88e60b5e42a27 id_1589 { std::get<30 /* VCidr */>((*p_0)) };
                                                                            ::dessser::gen::raql_value::t8d4af754051624596ec1687a64e3bf86 id_1590 { std::get<1 /* v6 */>(id_1589) };
                                                                            uint8_t id_1591 { id_1590.mask };
                                                                            Pointer id_1592 { srec_dst_606.writeU8(id_1591) };
                                                                            let_res_1588 = id_1592;
                                                                          }
                                                                          choose_res_1569 = let_res_1588;
                                                                        }
                                                                        let_res_1564 = choose_res_1569;
                                                                      }
                                                                      choose_res_1560 = let_res_1564;
                                                                    } else {
                                                                      uint16_t id_1593 { 31 };
                                                                      bool id_1594 { bool(id_1593 == label1_575) };
                                                                      Pointer choose_res_1595;
                                                                      if (id_1594) {
                                                                        Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1596 { std::get<31 /* VTup */>((*p_0)) };
                                                                        uint32_t id_1597 { id_1596.size() };
                                                                        Vec<1, uint32_t> id_1598 {  id_1597  };
                                                                        Pointer let_res_1599;
                                                                        {
                                                                          Vec<1, uint32_t> leb128_sz_599 { id_1598 };
                                                                          Vec<1, Pointer> id_1600 {  ssum_dst_576  };
                                                                          Pointer let_res_1601;
                                                                          {
                                                                            Vec<1, Pointer> leb128_ptr_600 { id_1600 };
                                                                            bool while_flag_1602 { true };
                                                                            do {
                                                                              uint8_t id_1603 { 0 };
                                                                              uint8_t id_1604 { 0 };
                                                                              Pointer id_1605 { leb128_ptr_600[id_1604] };
                                                                              uint32_t id_1606 { 128U };
                                                                              uint8_t id_1607 { 0 };
                                                                              uint32_t id_1608 { leb128_sz_599[id_1607] };
                                                                              bool id_1609 { bool(id_1606 > id_1608) };
                                                                              uint8_t choose_res_1610;
                                                                              if (id_1609) {
                                                                                uint8_t id_1611 { 0 };
                                                                                uint32_t id_1612 { leb128_sz_599[id_1611] };
                                                                                uint8_t id_1613 { uint8_t(id_1612) };
                                                                                choose_res_1610 = id_1613;
                                                                              } else {
                                                                                uint8_t id_1614 { 0 };
                                                                                uint32_t id_1615 { leb128_sz_599[id_1614] };
                                                                                uint8_t id_1616 { uint8_t(id_1615) };
                                                                                uint8_t id_1617 { 128 };
                                                                                uint8_t id_1618 { uint8_t(id_1616 | id_1617) };
                                                                                choose_res_1610 = id_1618;
                                                                              }
                                                                              Pointer id_1619 { id_1605.writeU8(choose_res_1610) };
                                                                              Void id_1620 { ((void)(leb128_ptr_600[id_1603] = id_1619), ::dessser::VOID) };
                                                                              (void)id_1620;
                                                                              uint8_t id_1621 { 0 };
                                                                              uint8_t id_1622 { 0 };
                                                                              uint32_t id_1623 { leb128_sz_599[id_1622] };
                                                                              uint8_t id_1624 { 7 };
                                                                              uint32_t id_1625 { uint32_t(id_1623 >> id_1624) };
                                                                              Void id_1626 { ((void)(leb128_sz_599[id_1621] = id_1625), ::dessser::VOID) };
                                                                              (void)id_1626;
                                                                              uint8_t id_1627 { 0 };
                                                                              uint32_t id_1628 { leb128_sz_599[id_1627] };
                                                                              uint32_t id_1629 { 0U };
                                                                              bool id_1630 { bool(id_1628 > id_1629) };
                                                                              while_flag_1602 = id_1630;
                                                                              if (while_flag_1602) {
                                                                                (void)::dessser::VOID;
                                                                              }
                                                                            } while (while_flag_1602);
                                                                            (void)::dessser::VOID;
                                                                            uint8_t id_1631 { 0 };
                                                                            Pointer id_1632 { leb128_ptr_600[id_1631] };
                                                                            let_res_1601 = id_1632;
                                                                          }
                                                                          let_res_1599 = let_res_1601;
                                                                        }
                                                                        Vec<1, Pointer> id_1633 {  let_res_1599  };
                                                                        Pointer let_res_1634;
                                                                        {
                                                                          Vec<1, Pointer> dst_ref_601 { id_1633 };
                                                                          int32_t id_1635 { 0L };
                                                                          Vec<1, int32_t> id_1636 {  id_1635  };
                                                                          Pointer let_res_1637;
                                                                          {
                                                                            Vec<1, int32_t> n_ref_602 { id_1636 };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1638 { std::get<31 /* VTup */>((*p_0)) };
                                                                            for (std::shared_ptr<::dessser::gen::raql_value::t>  x_603 : id_1638) {
                                                                              uint8_t id_1639 { 0 };
                                                                              uint8_t id_1640 { 0 };
                                                                              Pointer id_1641 { dst_ref_601[id_1640] };
                                                                              Pointer id_1642 { fun1320(x_603, id_1641) };
                                                                              Void id_1643 { ((void)(dst_ref_601[id_1639] = id_1642), ::dessser::VOID) };
                                                                              (void)id_1643;
                                                                              uint8_t id_1644 { 0 };
                                                                              int32_t id_1645 { 1L };
                                                                              uint8_t id_1646 { 0 };
                                                                              int32_t id_1647 { n_ref_602[id_1646] };
                                                                              int32_t id_1648 { int32_t(id_1645 + id_1647) };
                                                                              Void id_1649 { ((void)(n_ref_602[id_1644] = id_1648), ::dessser::VOID) };
                                                                              (void)id_1649;
                                                                              (void)id_1649;
                                                                            }
                                                                            (void)::dessser::VOID;
                                                                            uint8_t id_1650 { 0 };
                                                                            Pointer id_1651 { dst_ref_601[id_1650] };
                                                                            let_res_1637 = id_1651;
                                                                          }
                                                                          let_res_1634 = let_res_1637;
                                                                        }
                                                                        choose_res_1595 = let_res_1634;
                                                                      } else {
                                                                        uint16_t id_1652 { 32 };
                                                                        bool id_1653 { bool(id_1652 == label1_575) };
                                                                        Pointer choose_res_1654;
                                                                        if (id_1653) {
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1655 { std::get<32 /* VVec */>((*p_0)) };
                                                                          uint32_t id_1656 { id_1655.size() };
                                                                          Vec<1, uint32_t> id_1657 {  id_1656  };
                                                                          Pointer let_res_1658;
                                                                          {
                                                                            Vec<1, uint32_t> leb128_sz_594 { id_1657 };
                                                                            Vec<1, Pointer> id_1659 {  ssum_dst_576  };
                                                                            Pointer let_res_1660;
                                                                            {
                                                                              Vec<1, Pointer> leb128_ptr_595 { id_1659 };
                                                                              bool while_flag_1661 { true };
                                                                              do {
                                                                                uint8_t id_1662 { 0 };
                                                                                uint8_t id_1663 { 0 };
                                                                                Pointer id_1664 { leb128_ptr_595[id_1663] };
                                                                                uint32_t id_1665 { 128U };
                                                                                uint8_t id_1666 { 0 };
                                                                                uint32_t id_1667 { leb128_sz_594[id_1666] };
                                                                                bool id_1668 { bool(id_1665 > id_1667) };
                                                                                uint8_t choose_res_1669;
                                                                                if (id_1668) {
                                                                                  uint8_t id_1670 { 0 };
                                                                                  uint32_t id_1671 { leb128_sz_594[id_1670] };
                                                                                  uint8_t id_1672 { uint8_t(id_1671) };
                                                                                  choose_res_1669 = id_1672;
                                                                                } else {
                                                                                  uint8_t id_1673 { 0 };
                                                                                  uint32_t id_1674 { leb128_sz_594[id_1673] };
                                                                                  uint8_t id_1675 { uint8_t(id_1674) };
                                                                                  uint8_t id_1676 { 128 };
                                                                                  uint8_t id_1677 { uint8_t(id_1675 | id_1676) };
                                                                                  choose_res_1669 = id_1677;
                                                                                }
                                                                                Pointer id_1678 { id_1664.writeU8(choose_res_1669) };
                                                                                Void id_1679 { ((void)(leb128_ptr_595[id_1662] = id_1678), ::dessser::VOID) };
                                                                                (void)id_1679;
                                                                                uint8_t id_1680 { 0 };
                                                                                uint8_t id_1681 { 0 };
                                                                                uint32_t id_1682 { leb128_sz_594[id_1681] };
                                                                                uint8_t id_1683 { 7 };
                                                                                uint32_t id_1684 { uint32_t(id_1682 >> id_1683) };
                                                                                Void id_1685 { ((void)(leb128_sz_594[id_1680] = id_1684), ::dessser::VOID) };
                                                                                (void)id_1685;
                                                                                uint8_t id_1686 { 0 };
                                                                                uint32_t id_1687 { leb128_sz_594[id_1686] };
                                                                                uint32_t id_1688 { 0U };
                                                                                bool id_1689 { bool(id_1687 > id_1688) };
                                                                                while_flag_1661 = id_1689;
                                                                                if (while_flag_1661) {
                                                                                  (void)::dessser::VOID;
                                                                                }
                                                                              } while (while_flag_1661);
                                                                              (void)::dessser::VOID;
                                                                              uint8_t id_1690 { 0 };
                                                                              Pointer id_1691 { leb128_ptr_595[id_1690] };
                                                                              let_res_1660 = id_1691;
                                                                            }
                                                                            let_res_1658 = let_res_1660;
                                                                          }
                                                                          Vec<1, Pointer> id_1692 {  let_res_1658  };
                                                                          Pointer let_res_1693;
                                                                          {
                                                                            Vec<1, Pointer> dst_ref_596 { id_1692 };
                                                                            int32_t id_1694 { 0L };
                                                                            Vec<1, int32_t> id_1695 {  id_1694  };
                                                                            Pointer let_res_1696;
                                                                            {
                                                                              Vec<1, int32_t> n_ref_597 { id_1695 };
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1697 { std::get<32 /* VVec */>((*p_0)) };
                                                                              for (std::shared_ptr<::dessser::gen::raql_value::t>  x_598 : id_1697) {
                                                                                uint8_t id_1698 { 0 };
                                                                                uint8_t id_1699 { 0 };
                                                                                Pointer id_1700 { dst_ref_596[id_1699] };
                                                                                Pointer id_1701 { fun1320(x_598, id_1700) };
                                                                                Void id_1702 { ((void)(dst_ref_596[id_1698] = id_1701), ::dessser::VOID) };
                                                                                (void)id_1702;
                                                                                uint8_t id_1703 { 0 };
                                                                                int32_t id_1704 { 1L };
                                                                                uint8_t id_1705 { 0 };
                                                                                int32_t id_1706 { n_ref_597[id_1705] };
                                                                                int32_t id_1707 { int32_t(id_1704 + id_1706) };
                                                                                Void id_1708 { ((void)(n_ref_597[id_1703] = id_1707), ::dessser::VOID) };
                                                                                (void)id_1708;
                                                                                (void)id_1708;
                                                                              }
                                                                              (void)::dessser::VOID;
                                                                              uint8_t id_1709 { 0 };
                                                                              Pointer id_1710 { dst_ref_596[id_1709] };
                                                                              let_res_1696 = id_1710;
                                                                            }
                                                                            let_res_1693 = let_res_1696;
                                                                          }
                                                                          choose_res_1654 = let_res_1693;
                                                                        } else {
                                                                          uint16_t id_1711 { 33 };
                                                                          bool id_1712 { bool(id_1711 == label1_575) };
                                                                          Pointer choose_res_1713;
                                                                          if (id_1712) {
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1714 { std::get<33 /* VArr */>((*p_0)) };
                                                                            uint32_t id_1715 { id_1714.size() };
                                                                            Vec<1, uint32_t> id_1716 {  id_1715  };
                                                                            Pointer let_res_1717;
                                                                            {
                                                                              Vec<1, uint32_t> leb128_sz_589 { id_1716 };
                                                                              Vec<1, Pointer> id_1718 {  ssum_dst_576  };
                                                                              Pointer let_res_1719;
                                                                              {
                                                                                Vec<1, Pointer> leb128_ptr_590 { id_1718 };
                                                                                bool while_flag_1720 { true };
                                                                                do {
                                                                                  uint8_t id_1721 { 0 };
                                                                                  uint8_t id_1722 { 0 };
                                                                                  Pointer id_1723 { leb128_ptr_590[id_1722] };
                                                                                  uint32_t id_1724 { 128U };
                                                                                  uint8_t id_1725 { 0 };
                                                                                  uint32_t id_1726 { leb128_sz_589[id_1725] };
                                                                                  bool id_1727 { bool(id_1724 > id_1726) };
                                                                                  uint8_t choose_res_1728;
                                                                                  if (id_1727) {
                                                                                    uint8_t id_1729 { 0 };
                                                                                    uint32_t id_1730 { leb128_sz_589[id_1729] };
                                                                                    uint8_t id_1731 { uint8_t(id_1730) };
                                                                                    choose_res_1728 = id_1731;
                                                                                  } else {
                                                                                    uint8_t id_1732 { 0 };
                                                                                    uint32_t id_1733 { leb128_sz_589[id_1732] };
                                                                                    uint8_t id_1734 { uint8_t(id_1733) };
                                                                                    uint8_t id_1735 { 128 };
                                                                                    uint8_t id_1736 { uint8_t(id_1734 | id_1735) };
                                                                                    choose_res_1728 = id_1736;
                                                                                  }
                                                                                  Pointer id_1737 { id_1723.writeU8(choose_res_1728) };
                                                                                  Void id_1738 { ((void)(leb128_ptr_590[id_1721] = id_1737), ::dessser::VOID) };
                                                                                  (void)id_1738;
                                                                                  uint8_t id_1739 { 0 };
                                                                                  uint8_t id_1740 { 0 };
                                                                                  uint32_t id_1741 { leb128_sz_589[id_1740] };
                                                                                  uint8_t id_1742 { 7 };
                                                                                  uint32_t id_1743 { uint32_t(id_1741 >> id_1742) };
                                                                                  Void id_1744 { ((void)(leb128_sz_589[id_1739] = id_1743), ::dessser::VOID) };
                                                                                  (void)id_1744;
                                                                                  uint8_t id_1745 { 0 };
                                                                                  uint32_t id_1746 { leb128_sz_589[id_1745] };
                                                                                  uint32_t id_1747 { 0U };
                                                                                  bool id_1748 { bool(id_1746 > id_1747) };
                                                                                  while_flag_1720 = id_1748;
                                                                                  if (while_flag_1720) {
                                                                                    (void)::dessser::VOID;
                                                                                  }
                                                                                } while (while_flag_1720);
                                                                                (void)::dessser::VOID;
                                                                                uint8_t id_1749 { 0 };
                                                                                Pointer id_1750 { leb128_ptr_590[id_1749] };
                                                                                let_res_1719 = id_1750;
                                                                              }
                                                                              let_res_1717 = let_res_1719;
                                                                            }
                                                                            Vec<1, Pointer> id_1751 {  let_res_1717  };
                                                                            Pointer let_res_1752;
                                                                            {
                                                                              Vec<1, Pointer> dst_ref_591 { id_1751 };
                                                                              int32_t id_1753 { 0L };
                                                                              Vec<1, int32_t> id_1754 {  id_1753  };
                                                                              Pointer let_res_1755;
                                                                              {
                                                                                Vec<1, int32_t> n_ref_592 { id_1754 };
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_value::t> > id_1756 { std::get<33 /* VArr */>((*p_0)) };
                                                                                for (std::shared_ptr<::dessser::gen::raql_value::t>  x_593 : id_1756) {
                                                                                  uint8_t id_1757 { 0 };
                                                                                  uint8_t id_1758 { 0 };
                                                                                  Pointer id_1759 { dst_ref_591[id_1758] };
                                                                                  Pointer id_1760 { fun1320(x_593, id_1759) };
                                                                                  Void id_1761 { ((void)(dst_ref_591[id_1757] = id_1760), ::dessser::VOID) };
                                                                                  (void)id_1761;
                                                                                  uint8_t id_1762 { 0 };
                                                                                  int32_t id_1763 { 1L };
                                                                                  uint8_t id_1764 { 0 };
                                                                                  int32_t id_1765 { n_ref_592[id_1764] };
                                                                                  int32_t id_1766 { int32_t(id_1763 + id_1765) };
                                                                                  Void id_1767 { ((void)(n_ref_592[id_1762] = id_1766), ::dessser::VOID) };
                                                                                  (void)id_1767;
                                                                                  (void)id_1767;
                                                                                }
                                                                                (void)::dessser::VOID;
                                                                                uint8_t id_1768 { 0 };
                                                                                Pointer id_1769 { dst_ref_591[id_1768] };
                                                                                let_res_1755 = id_1769;
                                                                              }
                                                                              let_res_1752 = let_res_1755;
                                                                            }
                                                                            choose_res_1713 = let_res_1752;
                                                                          } else {
                                                                            uint16_t id_1770 { 34 };
                                                                            bool id_1771 { bool(id_1770 == label1_575) };
                                                                            Pointer choose_res_1772;
                                                                            if (id_1771) {
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_1773 { std::get<34 /* VRec */>((*p_0)) };
                                                                              uint32_t id_1774 { id_1773.size() };
                                                                              Vec<1, uint32_t> id_1775 {  id_1774  };
                                                                              Pointer let_res_1776;
                                                                              {
                                                                                Vec<1, uint32_t> leb128_sz_584 { id_1775 };
                                                                                Vec<1, Pointer> id_1777 {  ssum_dst_576  };
                                                                                Pointer let_res_1778;
                                                                                {
                                                                                  Vec<1, Pointer> leb128_ptr_585 { id_1777 };
                                                                                  bool while_flag_1779 { true };
                                                                                  do {
                                                                                    uint8_t id_1780 { 0 };
                                                                                    uint8_t id_1781 { 0 };
                                                                                    Pointer id_1782 { leb128_ptr_585[id_1781] };
                                                                                    uint32_t id_1783 { 128U };
                                                                                    uint8_t id_1784 { 0 };
                                                                                    uint32_t id_1785 { leb128_sz_584[id_1784] };
                                                                                    bool id_1786 { bool(id_1783 > id_1785) };
                                                                                    uint8_t choose_res_1787;
                                                                                    if (id_1786) {
                                                                                      uint8_t id_1788 { 0 };
                                                                                      uint32_t id_1789 { leb128_sz_584[id_1788] };
                                                                                      uint8_t id_1790 { uint8_t(id_1789) };
                                                                                      choose_res_1787 = id_1790;
                                                                                    } else {
                                                                                      uint8_t id_1791 { 0 };
                                                                                      uint32_t id_1792 { leb128_sz_584[id_1791] };
                                                                                      uint8_t id_1793 { uint8_t(id_1792) };
                                                                                      uint8_t id_1794 { 128 };
                                                                                      uint8_t id_1795 { uint8_t(id_1793 | id_1794) };
                                                                                      choose_res_1787 = id_1795;
                                                                                    }
                                                                                    Pointer id_1796 { id_1782.writeU8(choose_res_1787) };
                                                                                    Void id_1797 { ((void)(leb128_ptr_585[id_1780] = id_1796), ::dessser::VOID) };
                                                                                    (void)id_1797;
                                                                                    uint8_t id_1798 { 0 };
                                                                                    uint8_t id_1799 { 0 };
                                                                                    uint32_t id_1800 { leb128_sz_584[id_1799] };
                                                                                    uint8_t id_1801 { 7 };
                                                                                    uint32_t id_1802 { uint32_t(id_1800 >> id_1801) };
                                                                                    Void id_1803 { ((void)(leb128_sz_584[id_1798] = id_1802), ::dessser::VOID) };
                                                                                    (void)id_1803;
                                                                                    uint8_t id_1804 { 0 };
                                                                                    uint32_t id_1805 { leb128_sz_584[id_1804] };
                                                                                    uint32_t id_1806 { 0U };
                                                                                    bool id_1807 { bool(id_1805 > id_1806) };
                                                                                    while_flag_1779 = id_1807;
                                                                                    if (while_flag_1779) {
                                                                                      (void)::dessser::VOID;
                                                                                    }
                                                                                  } while (while_flag_1779);
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_1808 { 0 };
                                                                                  Pointer id_1809 { leb128_ptr_585[id_1808] };
                                                                                  let_res_1778 = id_1809;
                                                                                }
                                                                                let_res_1776 = let_res_1778;
                                                                              }
                                                                              Vec<1, Pointer> id_1810 {  let_res_1776  };
                                                                              Pointer let_res_1811;
                                                                              {
                                                                                Vec<1, Pointer> dst_ref_586 { id_1810 };
                                                                                int32_t id_1812 { 0L };
                                                                                Vec<1, int32_t> id_1813 {  id_1812  };
                                                                                Pointer let_res_1814;
                                                                                {
                                                                                  Vec<1, int32_t> n_ref_587 { id_1813 };
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_value::named_value> > id_1815 { std::get<34 /* VRec */>((*p_0)) };
                                                                                  for (std::shared_ptr<::dessser::gen::raql_value::named_value>  x_588 : id_1815) {
                                                                                    uint8_t id_1816 { 0 };
                                                                                    uint8_t id_1817 { 0 };
                                                                                    Pointer id_1818 { dst_ref_586[id_1817] };
                                                                                    Pointer id_1819 { named_value_to_row_binary(x_588, id_1818) };
                                                                                    Void id_1820 { ((void)(dst_ref_586[id_1816] = id_1819), ::dessser::VOID) };
                                                                                    (void)id_1820;
                                                                                    uint8_t id_1821 { 0 };
                                                                                    int32_t id_1822 { 1L };
                                                                                    uint8_t id_1823 { 0 };
                                                                                    int32_t id_1824 { n_ref_587[id_1823] };
                                                                                    int32_t id_1825 { int32_t(id_1822 + id_1824) };
                                                                                    Void id_1826 { ((void)(n_ref_587[id_1821] = id_1825), ::dessser::VOID) };
                                                                                    (void)id_1826;
                                                                                    (void)id_1826;
                                                                                  }
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_1827 { 0 };
                                                                                  Pointer id_1828 { dst_ref_586[id_1827] };
                                                                                  let_res_1814 = id_1828;
                                                                                }
                                                                                let_res_1811 = let_res_1814;
                                                                              }
                                                                              choose_res_1772 = let_res_1811;
                                                                            } else {
                                                                              uint16_t id_1829 { 35 };
                                                                              bool id_1830 { bool(label1_575 == id_1829) };
                                                                              Void id_1831 { ((void)(assert(id_1830)), ::dessser::VOID) };
                                                                              (void)id_1831;
                                                                              Arr<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d> id_1832 { std::get<35 /* VMap */>((*p_0)) };
                                                                              uint32_t id_1833 { id_1832.size() };
                                                                              Vec<1, uint32_t> id_1834 {  id_1833  };
                                                                              Pointer let_res_1835;
                                                                              {
                                                                                Vec<1, uint32_t> leb128_sz_577 { id_1834 };
                                                                                Vec<1, Pointer> id_1836 {  ssum_dst_576  };
                                                                                Pointer let_res_1837;
                                                                                {
                                                                                  Vec<1, Pointer> leb128_ptr_578 { id_1836 };
                                                                                  bool while_flag_1838 { true };
                                                                                  do {
                                                                                    uint8_t id_1839 { 0 };
                                                                                    uint8_t id_1840 { 0 };
                                                                                    Pointer id_1841 { leb128_ptr_578[id_1840] };
                                                                                    uint32_t id_1842 { 128U };
                                                                                    uint8_t id_1843 { 0 };
                                                                                    uint32_t id_1844 { leb128_sz_577[id_1843] };
                                                                                    bool id_1845 { bool(id_1842 > id_1844) };
                                                                                    uint8_t choose_res_1846;
                                                                                    if (id_1845) {
                                                                                      uint8_t id_1847 { 0 };
                                                                                      uint32_t id_1848 { leb128_sz_577[id_1847] };
                                                                                      uint8_t id_1849 { uint8_t(id_1848) };
                                                                                      choose_res_1846 = id_1849;
                                                                                    } else {
                                                                                      uint8_t id_1850 { 0 };
                                                                                      uint32_t id_1851 { leb128_sz_577[id_1850] };
                                                                                      uint8_t id_1852 { uint8_t(id_1851) };
                                                                                      uint8_t id_1853 { 128 };
                                                                                      uint8_t id_1854 { uint8_t(id_1852 | id_1853) };
                                                                                      choose_res_1846 = id_1854;
                                                                                    }
                                                                                    Pointer id_1855 { id_1841.writeU8(choose_res_1846) };
                                                                                    Void id_1856 { ((void)(leb128_ptr_578[id_1839] = id_1855), ::dessser::VOID) };
                                                                                    (void)id_1856;
                                                                                    uint8_t id_1857 { 0 };
                                                                                    uint8_t id_1858 { 0 };
                                                                                    uint32_t id_1859 { leb128_sz_577[id_1858] };
                                                                                    uint8_t id_1860 { 7 };
                                                                                    uint32_t id_1861 { uint32_t(id_1859 >> id_1860) };
                                                                                    Void id_1862 { ((void)(leb128_sz_577[id_1857] = id_1861), ::dessser::VOID) };
                                                                                    (void)id_1862;
                                                                                    uint8_t id_1863 { 0 };
                                                                                    uint32_t id_1864 { leb128_sz_577[id_1863] };
                                                                                    uint32_t id_1865 { 0U };
                                                                                    bool id_1866 { bool(id_1864 > id_1865) };
                                                                                    while_flag_1838 = id_1866;
                                                                                    if (while_flag_1838) {
                                                                                      (void)::dessser::VOID;
                                                                                    }
                                                                                  } while (while_flag_1838);
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_1867 { 0 };
                                                                                  Pointer id_1868 { leb128_ptr_578[id_1867] };
                                                                                  let_res_1837 = id_1868;
                                                                                }
                                                                                let_res_1835 = let_res_1837;
                                                                              }
                                                                              Vec<1, Pointer> id_1869 {  let_res_1835  };
                                                                              Pointer let_res_1870;
                                                                              {
                                                                                Vec<1, Pointer> dst_ref_579 { id_1869 };
                                                                                int32_t id_1871 { 0L };
                                                                                Vec<1, int32_t> id_1872 {  id_1871  };
                                                                                Pointer let_res_1873;
                                                                                {
                                                                                  Vec<1, int32_t> n_ref_580 { id_1872 };
                                                                                  Arr<::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d> id_1874 { std::get<35 /* VMap */>((*p_0)) };
                                                                                  for (::dessser::gen::raql_value::t03cfda2a49b4fd636c1028863952922d x_581 : id_1874) {
                                                                                    uint8_t id_1875 { 0 };
                                                                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_1876 { std::get<1>(x_581) };
                                                                                    std::shared_ptr<::dessser::gen::raql_value::t>  id_1877 { std::get<0>(x_581) };
                                                                                    uint8_t id_1878 { 0 };
                                                                                    Pointer id_1879 { dst_ref_579[id_1878] };
                                                                                    Pointer id_1880 { fun1320(id_1877, id_1879) };
                                                                                    Pointer id_1881 { fun1320(id_1876, id_1880) };
                                                                                    Void id_1882 { ((void)(dst_ref_579[id_1875] = id_1881), ::dessser::VOID) };
                                                                                    (void)id_1882;
                                                                                    uint8_t id_1883 { 0 };
                                                                                    int32_t id_1884 { 1L };
                                                                                    uint8_t id_1885 { 0 };
                                                                                    int32_t id_1886 { n_ref_580[id_1885] };
                                                                                    int32_t id_1887 { int32_t(id_1884 + id_1886) };
                                                                                    Void id_1888 { ((void)(n_ref_580[id_1883] = id_1887), ::dessser::VOID) };
                                                                                    (void)id_1888;
                                                                                    (void)id_1888;
                                                                                  }
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_1889 { 0 };
                                                                                  Pointer id_1890 { dst_ref_579[id_1889] };
                                                                                  let_res_1873 = id_1890;
                                                                                }
                                                                                let_res_1870 = let_res_1873;
                                                                              }
                                                                              choose_res_1772 = let_res_1870;
                                                                            }
                                                                            choose_res_1713 = choose_res_1772;
                                                                          }
                                                                          choose_res_1654 = choose_res_1713;
                                                                        }
                                                                        choose_res_1595 = choose_res_1654;
                                                                      }
                                                                      choose_res_1560 = choose_res_1595;
                                                                    }
                                                                    choose_res_1550 = choose_res_1560;
                                                                  }
                                                                  choose_res_1540 = choose_res_1550;
                                                                }
                                                                choose_res_1517 = choose_res_1540;
                                                              }
                                                              choose_res_1512 = choose_res_1517;
                                                            }
                                                            choose_res_1507 = choose_res_1512;
                                                          }
                                                          choose_res_1501 = choose_res_1507;
                                                        }
                                                        choose_res_1495 = choose_res_1501;
                                                      }
                                                      choose_res_1489 = choose_res_1495;
                                                    }
                                                    choose_res_1482 = choose_res_1489;
                                                  }
                                                  choose_res_1475 = choose_res_1482;
                                                }
                                                choose_res_1468 = choose_res_1475;
                                              }
                                              choose_res_1462 = choose_res_1468;
                                            }
                                            choose_res_1455 = choose_res_1462;
                                          }
                                          choose_res_1449 = choose_res_1455;
                                        }
                                        choose_res_1443 = choose_res_1449;
                                      }
                                      choose_res_1438 = choose_res_1443;
                                    }
                                    choose_res_1433 = choose_res_1438;
                                  }
                                  choose_res_1427 = choose_res_1433;
                                }
                                choose_res_1421 = choose_res_1427;
                              }
                              choose_res_1415 = choose_res_1421;
                            }
                            choose_res_1410 = choose_res_1415;
                          }
                          choose_res_1404 = choose_res_1410;
                        }
                        choose_res_1399 = choose_res_1404;
                      }
                      choose_res_1394 = choose_res_1399;
                    }
                    choose_res_1388 = choose_res_1394;
                  }
                  choose_res_1382 = choose_res_1388;
                }
                choose_res_1339 = choose_res_1382;
              }
              choose_res_1333 = choose_res_1339;
            }
            choose_res_1330 = choose_res_1333;
          }
          choose_res_1327 = choose_res_1330;
        }
        let_res_1324 = choose_res_1327;
      }
      let_res_1322 = let_res_1324;
    }
    return let_res_1322;
  }
   };
  return fun1320;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("(STRING; THIS)" "Ptr")
      (let "stup_dst_574"
        (write-bytes
          (let "leb128_sz_572" (make-vec (string-length (get-item 0 (param 0))))
            (let "leb128_ptr_573" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_573")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_573"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_572"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_572"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_572"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_572") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_572")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_572")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_573"))))) 
          (bytes-of-string (get-item 0 (param 0)))) (apply (identifier "to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_574"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::named_value> ,Pointer)> named_value_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::named_value> ,Pointer)> fun1891 { [&fun1891](std::shared_ptr<::dessser::gen::raql_value::named_value>  p_0, Pointer p_1) {
    std::string id_1892 { std::get<0>((*p_0)) };
    uint32_t id_1893 { (uint32_t)id_1892.size() };
    Vec<1, uint32_t> id_1894 {  id_1893  };
    Pointer let_res_1895;
    {
      Vec<1, uint32_t> leb128_sz_572 { id_1894 };
      Vec<1, Pointer> id_1896 {  p_1  };
      Pointer let_res_1897;
      {
        Vec<1, Pointer> leb128_ptr_573 { id_1896 };
        bool while_flag_1898 { true };
        do {
          uint8_t id_1899 { 0 };
          uint8_t id_1900 { 0 };
          Pointer id_1901 { leb128_ptr_573[id_1900] };
          uint32_t id_1902 { 128U };
          uint8_t id_1903 { 0 };
          uint32_t id_1904 { leb128_sz_572[id_1903] };
          bool id_1905 { bool(id_1902 > id_1904) };
          uint8_t choose_res_1906;
          if (id_1905) {
            uint8_t id_1907 { 0 };
            uint32_t id_1908 { leb128_sz_572[id_1907] };
            uint8_t id_1909 { uint8_t(id_1908) };
            choose_res_1906 = id_1909;
          } else {
            uint8_t id_1910 { 0 };
            uint32_t id_1911 { leb128_sz_572[id_1910] };
            uint8_t id_1912 { uint8_t(id_1911) };
            uint8_t id_1913 { 128 };
            uint8_t id_1914 { uint8_t(id_1912 | id_1913) };
            choose_res_1906 = id_1914;
          }
          Pointer id_1915 { id_1901.writeU8(choose_res_1906) };
          Void id_1916 { ((void)(leb128_ptr_573[id_1899] = id_1915), ::dessser::VOID) };
          (void)id_1916;
          uint8_t id_1917 { 0 };
          uint8_t id_1918 { 0 };
          uint32_t id_1919 { leb128_sz_572[id_1918] };
          uint8_t id_1920 { 7 };
          uint32_t id_1921 { uint32_t(id_1919 >> id_1920) };
          Void id_1922 { ((void)(leb128_sz_572[id_1917] = id_1921), ::dessser::VOID) };
          (void)id_1922;
          uint8_t id_1923 { 0 };
          uint32_t id_1924 { leb128_sz_572[id_1923] };
          uint32_t id_1925 { 0U };
          bool id_1926 { bool(id_1924 > id_1925) };
          while_flag_1898 = id_1926;
          if (while_flag_1898) {
            (void)::dessser::VOID;
          }
        } while (while_flag_1898);
        (void)::dessser::VOID;
        uint8_t id_1927 { 0 };
        Pointer id_1928 { leb128_ptr_573[id_1927] };
        let_res_1897 = id_1928;
      }
      let_res_1895 = let_res_1897;
    }
    std::string id_1929 { std::get<0>((*p_0)) };
    Bytes id_1930 { id_1929 };
    Pointer id_1931 { let_res_1895.writeBytes(id_1930) };
    Pointer let_res_1932;
    {
      Pointer stup_dst_574 { id_1931 };
      std::shared_ptr<::dessser::gen::raql_value::t>  id_1933 { std::get<1>((*p_0)) };
      Pointer id_1934 { to_row_binary(id_1933, stup_dst_574) };
      let_res_1932 = id_1934;
    }
    return let_res_1932;
  }
   };
  return fun1891;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_value::named_value> ,Pointer)> named_value_to_row_binary(named_value_to_row_binary_init());


}
