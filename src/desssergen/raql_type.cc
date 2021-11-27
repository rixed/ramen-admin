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
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct tb65a12146ab462f3a71f0a2c9184c7a4 : public std::tuple<
  uint32_t,
  std::shared_ptr<::dessser::gen::raql_type::t> 
> {
  using tuple::tuple;
  tb65a12146ab462f3a71f0a2c9184c7a4(std::tuple<uint32_t, std::shared_ptr<::dessser::gen::raql_type::t> > p)
    : std::tuple<uint32_t, std::shared_ptr<::dessser::gen::raql_type::t> >(std::get<0>(p), std::get<1>(p)) {}
};
struct named_type : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::raql_type::t> 
> {
  using tuple::tuple;
  named_type(std::tuple<std::string, std::shared_ptr<::dessser::gen::raql_type::t> > p)
    : std::tuple<std::string, std::shared_ptr<::dessser::gen::raql_type::t> >(std::get<0>(p), std::get<1>(p)) {}
};
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
struct t76c4c35a2b2b182ccf791241e9611c1d : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_type::t> ,
  std::shared_ptr<::dessser::gen::raql_type::t> 
> {
  using tuple::tuple;
  t76c4c35a2b2b182ccf791241e9611c1d(std::tuple<std::shared_ptr<::dessser::gen::raql_type::t> , std::shared_ptr<::dessser::gen::raql_type::t> > p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_type::t> , std::shared_ptr<::dessser::gen::raql_type::t> >(std::get<0>(p), std::get<1>(p)) {}
};
struct base : public std::variant<
  Void, // Void
  Void, // Bool
  Void, // Char
  Void, // Float
  Void, // String
  Void, // U8
  Void, // U16
  Void, // U24
  Void, // U32
  Void, // U40
  Void, // U48
  Void, // U56
  Void, // U64
  Void, // U128
  Void, // I8
  Void, // I16
  Void, // I24
  Void, // I32
  Void, // I40
  Void, // I48
  Void, // I56
  Void, // I64
  Void, // I128
  Void, // Eth
  Void, // Ipv4
  Void, // Ipv6
  Void, // Ip
  Void, // Cidrv4
  Void, // Cidrv6
  Void, // Cidr
  Arr<std::shared_ptr<::dessser::gen::raql_type::t> >, // Tup
  ::dessser::gen::raql_type::tb65a12146ab462f3a71f0a2c9184c7a4, // Vec
  std::shared_ptr<::dessser::gen::raql_type::t> , // Arr
  Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> >, // Rec
  Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> >, // Sum
  ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d // Map
> { using variant::variant; };

struct t {
  bool nullable;
  std::shared_ptr<::dessser::gen::raql_type::base>  type;
  t(bool nullable_, std::shared_ptr<::dessser::gen::raql_type::base>  type_) : nullable(nullable_), type(type_) {}
  t() = default;
};
struct tf2625240b3c32734b297669569815110 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_type::t> ,
  Pointer
> {
  using tuple::tuple;
  tf2625240b3c32734b297669569815110(std::tuple<std::shared_ptr<::dessser::gen::raql_type::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_type::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
extern std::function<::dessser::gen::raql_type::tf2625240b3c32734b297669569815110(Pointer)> of_row_binary;
struct t45adf9446573668c9b9a6264c9e7d2b0 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_type::base> ,
  Pointer
> {
  using tuple::tuple;
  t45adf9446573668c9b9a6264c9e7d2b0(std::tuple<std::shared_ptr<::dessser::gen::raql_type::base> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_type::base> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t1566bd611d8a2b90669c241f5e8d6ff1 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1566bd611d8a2b90669c241f5e8d6ff1(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
extern std::function<::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0(Pointer)> base_of_row_binary;
struct t7609d344c1ba69d0f80fec236d4c216b : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  t7609d344c1ba69d0f80fec236d4c216b(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t392d3ad514b4ff11fcd9ec6e8aea4bce : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::raql_type::t> >,
  Pointer
> {
  using tuple::tuple;
  t392d3ad514b4ff11fcd9ec6e8aea4bce(std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_type::t> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_type::t> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t12830831e15d5f74216c54da311f377b : public std::tuple<
  Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> >,
  Pointer
> {
  using tuple::tuple;
  t12830831e15d5f74216c54da311f377b(std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> >, Pointer> p)
    : std::tuple<Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> >, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct te9623fc9e468b565c42815c7eaf17382 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_type::named_type> ,
  Pointer
> {
  using tuple::tuple;
  te9623fc9e468b565c42815c7eaf17382(std::tuple<std::shared_ptr<::dessser::gen::raql_type::named_type> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_type::named_type> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
extern std::function<::dessser::gen::raql_type::te9623fc9e468b565c42815c7eaf17382(Pointer)> named_type_of_row_binary;
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t3fd8221434e489b54b5c4356ebff5005 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t3fd8221434e489b54b5c4356ebff5005(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t> )> sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_type::base> )> base_sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_type::named_type> )> named_type_sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t> ,Pointer)> to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
struct named_type;
inline std::ostream &operator<<(std::ostream &, struct named_type const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct named_type> const);
inline bool operator==(struct named_type const &, struct named_type const &);
inline bool operator!=(struct named_type const &, struct named_type const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::base> ,Pointer)> base_to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::named_type> ,Pointer)> named_type_to_row_binary;
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("Ptr")
      (let "drec_281" (apply (identifier "base-of-row-binary") (param 0))
        (let-pair "drec_fst_282" "drec_snd_283" (identifier "drec_281")
          (let-pair "dbool_fst_285" "dbool_snd_286" (read-u8 (identifier "drec_snd_283"))
            (make-tup (make-rec (string "nullable") (not (eq (identifier "dbool_fst_285") (u8 0))) (string "type") (identifier "drec_fst_282")) (identifier "dbool_snd_286"))))))
 */
static std::function<::dessser::gen::raql_type::tf2625240b3c32734b297669569815110(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_type::tf2625240b3c32734b297669569815110(Pointer)> fun0 { [&fun0](Pointer p_0) {
    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_1 { base_of_row_binary(p_0) };
    ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 let_res_2;
    {
      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 drec_281 { id_1 };
      ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 letpair_res_3;
      {
        auto drec_fst_282 { std::get<0>(drec_281) };
        auto drec_snd_283 { std::get<1>(drec_281) };
        ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_4 { drec_snd_283.readU8() };
        ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 letpair_res_5;
        {
          auto dbool_fst_285 { std::get<0>(id_4) };
          auto dbool_snd_286 { std::get<1>(id_4) };
          uint8_t id_6 { 0 };
          bool id_7 { bool(dbool_fst_285 == id_6) };
          bool id_8 { ! id_7 };
          std::shared_ptr<::dessser::gen::raql_type::t>  id_9 { std::make_shared<::dessser::gen::raql_type::t>(id_8, drec_fst_282) };
          ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_10 { id_9, dbool_snd_286 };
          letpair_res_5 = id_10;
        }
        letpair_res_3 = letpair_res_5;
      }
      let_res_2 = letpair_res_3;
    }
    return let_res_2;
  }
   };
  return fun0;
}
std::function<::dessser::gen::raql_type::tf2625240b3c32734b297669569815110(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_279" "make_snd_280"
        (let "dsum1_83" (let-pair "du16_fst_78" "du16_snd_79" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_78") (identifier "du16_snd_79")))
          (let-pair "dsum1_fst_84" "dsum1_snd_85" (identifier "dsum1_83")
            (if (eq (u16 0) (identifier "dsum1_fst_84"))
              (make-tup
                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 0
                  (nop)) (identifier "dsum1_snd_85"))
              (if (eq (u16 1) (identifier "dsum1_fst_84"))
                (make-tup
                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 1
                    (nop)) (identifier "dsum1_snd_85"))
                (if (eq (u16 2) (identifier "dsum1_fst_84"))
                  (make-tup
                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 2
                      (nop)) (identifier "dsum1_snd_85"))
                  (if (eq (u16 3) (identifier "dsum1_fst_84"))
                    (make-tup
                      (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 3
                        (nop)) (identifier "dsum1_snd_85"))
                    (if (eq (u16 4) (identifier "dsum1_fst_84"))
                      (make-tup
                        (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 4
                          (nop)) (identifier "dsum1_snd_85"))
                      (if (eq (u16 5) (identifier "dsum1_fst_84"))
                        (make-tup
                          (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 5
                            (nop)) (identifier "dsum1_snd_85"))
                        (if (eq (u16 6) (identifier "dsum1_fst_84"))
                          (make-tup
                            (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 6
                              (nop)) (identifier "dsum1_snd_85"))
                          (if (eq (u16 7) (identifier "dsum1_fst_84"))
                            (make-tup
                              (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 7
                                (nop)) (identifier "dsum1_snd_85"))
                            (if (eq (u16 8) (identifier "dsum1_fst_84"))
                              (make-tup
                                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 8
                                  (nop)) (identifier "dsum1_snd_85"))
                              (if (eq (u16 9) (identifier "dsum1_fst_84"))
                                (make-tup
                                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 9
                                    (nop)) (identifier "dsum1_snd_85"))
                                (if (eq (u16 10) (identifier "dsum1_fst_84"))
                                  (make-tup
                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 10
                                      (nop)) (identifier "dsum1_snd_85"))
                                  (if (eq (u16 11) (identifier "dsum1_fst_84"))
                                    (make-tup
                                      (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 11
                                        (nop)) (identifier "dsum1_snd_85"))
                                    (if (eq (u16 12) (identifier "dsum1_fst_84"))
                                      (make-tup
                                        (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 12
                                          (nop)) (identifier "dsum1_snd_85"))
                                      (if (eq (u16 13) (identifier "dsum1_fst_84"))
                                        (make-tup
                                          (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 13
                                            (nop)) (identifier "dsum1_snd_85"))
                                        (if (eq (u16 14) (identifier "dsum1_fst_84"))
                                          (make-tup
                                            (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 14
                                              (nop)) (identifier "dsum1_snd_85"))
                                          (if (eq (u16 15) (identifier "dsum1_fst_84"))
                                            (make-tup
                                              (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 15
                                                (nop)) (identifier "dsum1_snd_85"))
                                            (if (eq (u16 16) (identifier "dsum1_fst_84"))
                                              (make-tup
                                                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 16
                                                  (nop)) (identifier "dsum1_snd_85"))
                                              (if (eq (u16 17) (identifier "dsum1_fst_84"))
                                                (make-tup
                                                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 17
                                                    (nop)) (identifier "dsum1_snd_85"))
                                                (if (eq (u16 18) (identifier "dsum1_fst_84"))
                                                  (make-tup
                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 18
                                                      (nop)) (identifier "dsum1_snd_85"))
                                                  (if (eq (u16 19) (identifier "dsum1_fst_84"))
                                                    (make-tup
                                                      (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 19
                                                        (nop)) (identifier "dsum1_snd_85"))
                                                    (if (eq (u16 20) (identifier "dsum1_fst_84"))
                                                      (make-tup
                                                        (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 20
                                                          (nop)) (identifier "dsum1_snd_85"))
                                                      (if (eq (u16 21) (identifier "dsum1_fst_84"))
                                                        (make-tup
                                                          (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 21
                                                            (nop)) (identifier "dsum1_snd_85"))
                                                        (if (eq (u16 22) (identifier "dsum1_fst_84"))
                                                          (make-tup
                                                            (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 22
                                                              (nop)) 
                                                            (identifier "dsum1_snd_85"))
                                                          (if (eq (u16 23) (identifier "dsum1_fst_84"))
                                                            (make-tup
                                                              (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 23
                                                                (nop)) 
                                                              (identifier "dsum1_snd_85"))
                                                            (if (eq (u16 24) (identifier "dsum1_fst_84"))
                                                              (make-tup
                                                                (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 24
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_85"))
                                                              (if (eq (u16 25) (identifier "dsum1_fst_84"))
                                                                (make-tup
                                                                  (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 25
                                                                    (nop)) 
                                                                  (identifier "dsum1_snd_85"))
                                                                (if (eq (u16 26) (identifier "dsum1_fst_84"))
                                                                  (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 26
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_85"))
                                                                  (if 
                                                                    (eq (u16 27) (identifier "dsum1_fst_84"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 27
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_85"))
                                                                    (if 
                                                                    (eq (u16 28) (identifier "dsum1_fst_84"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 28
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_85"))
                                                                    (if 
                                                                    (eq (u16 29) (identifier "dsum1_fst_84"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 29
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_85"))
                                                                    (if 
                                                                    (eq (u16 30) (identifier "dsum1_fst_84"))
                                                                    (let-pair "dlist4_fst_183" "dlist4_snd_184"
                                                                    (let "dlist1_171"
                                                                    (let "leb_ref_162" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_163" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_164" 
                                                                    (make-vec (identifier "dsum1_snd_85"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_165" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_164")))
                                                                    (let-pair "leb128_fst_166" "leb128_snd_167" 
                                                                    (identifier "leb128_165")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_164") (identifier "leb128_snd_167"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_162")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_166") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_163")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_162")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_163") (add (unsafe-nth (u8 0) (identifier "shft_ref_163")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_166") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_162")) (unsafe-nth (u8 0) (identifier "p_ref_164")))))))
                                                                    (let-pair "dlist1_fst_172" "dlist1_snd_173" 
                                                                    (identifier "dlist1_171")
                                                                    (let "inits_src_ref_174" 
                                                                    (make-vec (make-tup (end-of-list "THIS") (identifier "dlist1_snd_173")))
                                                                    (seq
                                                                    (let "repeat_n_175" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_172")) (unsafe-nth (u8 0) (identifier "repeat_n_175")))
                                                                    (seq
                                                                    (let "dlist2_176" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_174"))
                                                                    (let-pair "dlist2_fst_177" "dlist2_snd_178" 
                                                                    (identifier "dlist2_176")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_174")
                                                                    (let-pair "dlist3_fst_180" "dlist3_snd_181" 
                                                                    (apply (identifier "of-row-binary") (identifier "dlist2_snd_178"))
                                                                    (make-tup (cons (identifier "dlist3_fst_180") (identifier "dlist2_fst_177")) (identifier "dlist3_snd_181"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_175") (add (unsafe-nth (u8 0) (identifier "repeat_n_175")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_174"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 30
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_183"))) 
                                                                    (identifier "dlist4_snd_184")))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "dsum1_fst_84"))
                                                                    (let "dtup_153"
                                                                    (let-pair "du32_fst_151" "du32_snd_152" (read-u32 little-endian (identifier "dsum1_snd_85")) (make-tup (identifier "du32_fst_151") (identifier "du32_snd_152")))
                                                                    (let-pair "dtup_fst_154" "dtup_snd_155" 
                                                                    (identifier "dtup_153")
                                                                    (let-pair "dtup_fst_157" "dtup_snd_158" 
                                                                    (apply (identifier "of-row-binary") (identifier "dtup_snd_155"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 31
                                                                    (make-tup (identifier "dtup_fst_154") (identifier "dtup_fst_157"))) 
                                                                    (identifier "dtup_snd_158")))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "dsum1_fst_84"))
                                                                    (let-pair "dsum2_fst_148" "dsum2_snd_149" 
                                                                    (apply (identifier "of-row-binary") (identifier "dsum1_snd_85"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 32
                                                                    (identifier "dsum2_fst_148")) 
                                                                    (identifier "dsum2_snd_149")))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "dsum1_fst_84"))
                                                                    (let-pair "dlist4_fst_142" "dlist4_snd_143"
                                                                    (let "dlist1_130"
                                                                    (let "leb_ref_121" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_122" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_123" 
                                                                    (make-vec (identifier "dsum1_snd_85"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_124" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_123")))
                                                                    (let-pair "leb128_fst_125" "leb128_snd_126" 
                                                                    (identifier "leb128_124")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_123") (identifier "leb128_snd_126"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_121")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_125") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_122")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_121")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_122") (add (unsafe-nth (u8 0) (identifier "shft_ref_122")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_125") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_121")) (unsafe-nth (u8 0) (identifier "p_ref_123")))))))
                                                                    (let-pair "dlist1_fst_131" "dlist1_snd_132" 
                                                                    (identifier "dlist1_130")
                                                                    (let "inits_src_ref_133" 
                                                                    (make-vec (make-tup (end-of-list "(named_type AS (STRING; THIS))") (identifier "dlist1_snd_132")))
                                                                    (seq
                                                                    (let "repeat_n_134" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_131")) (unsafe-nth (u8 0) (identifier "repeat_n_134")))
                                                                    (seq
                                                                    (let "dlist2_135" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_133"))
                                                                    (let-pair "dlist2_fst_136" "dlist2_snd_137" 
                                                                    (identifier "dlist2_135")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_133")
                                                                    (let-pair "dlist3_fst_139" "dlist3_snd_140" 
                                                                    (apply (identifier "named_type-of-row-binary") (identifier "dlist2_snd_137"))
                                                                    (make-tup (cons (identifier "dlist3_fst_139") (identifier "dlist2_fst_136")) (identifier "dlist3_snd_140"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_134") (add (unsafe-nth (u8 0) (identifier "repeat_n_134")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_133"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 33
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_142"))) 
                                                                    (identifier "dlist4_snd_143")))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "dsum1_fst_84"))
                                                                    (let-pair "dlist4_fst_116" "dlist4_snd_117"
                                                                    (let "dlist1_104"
                                                                    (let "leb_ref_95" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_96" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_97" 
                                                                    (make-vec (identifier "dsum1_snd_85"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_98" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_97")))
                                                                    (let-pair "leb128_fst_99" "leb128_snd_100" 
                                                                    (identifier "leb128_98")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_97") (identifier "leb128_snd_100"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_95")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_99") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_96")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_95")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_96") (add (unsafe-nth (u8 0) (identifier "shft_ref_96")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_99") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_95")) (unsafe-nth (u8 0) (identifier "p_ref_97")))))))
                                                                    (let-pair "dlist1_fst_105" "dlist1_snd_106" 
                                                                    (identifier "dlist1_104")
                                                                    (let "inits_src_ref_107" 
                                                                    (make-vec (make-tup (end-of-list "named_type") (identifier "dlist1_snd_106")))
                                                                    (seq
                                                                    (let "repeat_n_108" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (identifier "dlist1_fst_105")) (unsafe-nth (u8 0) (identifier "repeat_n_108")))
                                                                    (seq
                                                                    (let "dlist2_109" 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_107"))
                                                                    (let-pair "dlist2_fst_110" "dlist2_snd_111" 
                                                                    (identifier "dlist2_109")
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "inits_src_ref_107")
                                                                    (let-pair "dlist3_fst_113" "dlist3_snd_114" 
                                                                    (apply (identifier "named_type-of-row-binary") (identifier "dlist2_snd_111"))
                                                                    (make-tup (cons (identifier "dlist3_fst_113") (identifier "dlist2_fst_110")) (identifier "dlist3_snd_114"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_108") (add (unsafe-nth (u8 0) (identifier "repeat_n_108")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_107"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 34
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_116"))) 
                                                                    (identifier "dlist4_snd_117")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_84") (u16 35)))
                                                                    (let "dtup_86" 
                                                                    (apply (identifier "of-row-binary") (identifier "dsum1_snd_85"))
                                                                    (let-pair "dtup_fst_87" "dtup_snd_88" 
                                                                    (identifier "dtup_86")
                                                                    (let-pair "dtup_fst_90" "dtup_snd_91" 
                                                                    (apply (identifier "of-row-binary") (identifier "dtup_snd_88"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" 35
                                                                    (make-tup (identifier "dtup_fst_87") (identifier "dtup_fst_90"))) 
                                                                    (identifier "dtup_snd_91"))))))))))))))))))))))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_279") (identifier "make_snd_280"))))
 */
static std::function<::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0(Pointer)> base_of_row_binary_init()
{
  std::function<::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0(Pointer)> fun11 { [&fun11](Pointer p_0) {
    ::dessser::gen::raql_type::t7609d344c1ba69d0f80fec236d4c216b id_12 { p_0.readU16Le() };
    ::dessser::gen::raql_type::t7609d344c1ba69d0f80fec236d4c216b letpair_res_13;
    {
      auto du16_fst_78 { std::get<0>(id_12) };
      auto du16_snd_79 { std::get<1>(id_12) };
      ::dessser::gen::raql_type::t7609d344c1ba69d0f80fec236d4c216b id_14 { du16_fst_78, du16_snd_79 };
      letpair_res_13 = id_14;
    }
    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 let_res_15;
    {
      ::dessser::gen::raql_type::t7609d344c1ba69d0f80fec236d4c216b dsum1_83 { letpair_res_13 };
      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_16;
      {
        auto dsum1_fst_84 { std::get<0>(dsum1_83) };
        auto dsum1_snd_85 { std::get<1>(dsum1_83) };
        uint16_t id_17 { 0 };
        bool id_18 { bool(id_17 == dsum1_fst_84) };
        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_19;
        if (id_18) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::raql_type::base>  id_20 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_21 { id_20, dsum1_snd_85 };
          choose_res_19 = id_21;
        } else {
          uint16_t id_22 { 1 };
          bool id_23 { bool(id_22 == dsum1_fst_84) };
          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_24;
          if (id_23) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::raql_type::base>  id_25 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_26 { id_25, dsum1_snd_85 };
            choose_res_24 = id_26;
          } else {
            uint16_t id_27 { 2 };
            bool id_28 { bool(id_27 == dsum1_fst_84) };
            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_29;
            if (id_28) {
              (void)::dessser::VOID;
              std::shared_ptr<::dessser::gen::raql_type::base>  id_30 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<2>, ::dessser::VOID) };
              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_31 { id_30, dsum1_snd_85 };
              choose_res_29 = id_31;
            } else {
              uint16_t id_32 { 3 };
              bool id_33 { bool(id_32 == dsum1_fst_84) };
              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_34;
              if (id_33) {
                (void)::dessser::VOID;
                std::shared_ptr<::dessser::gen::raql_type::base>  id_35 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<3>, ::dessser::VOID) };
                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_36 { id_35, dsum1_snd_85 };
                choose_res_34 = id_36;
              } else {
                uint16_t id_37 { 4 };
                bool id_38 { bool(id_37 == dsum1_fst_84) };
                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_39;
                if (id_38) {
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::raql_type::base>  id_40 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<4>, ::dessser::VOID) };
                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_41 { id_40, dsum1_snd_85 };
                  choose_res_39 = id_41;
                } else {
                  uint16_t id_42 { 5 };
                  bool id_43 { bool(id_42 == dsum1_fst_84) };
                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_44;
                  if (id_43) {
                    (void)::dessser::VOID;
                    std::shared_ptr<::dessser::gen::raql_type::base>  id_45 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<5>, ::dessser::VOID) };
                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_46 { id_45, dsum1_snd_85 };
                    choose_res_44 = id_46;
                  } else {
                    uint16_t id_47 { 6 };
                    bool id_48 { bool(id_47 == dsum1_fst_84) };
                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_49;
                    if (id_48) {
                      (void)::dessser::VOID;
                      std::shared_ptr<::dessser::gen::raql_type::base>  id_50 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<6>, ::dessser::VOID) };
                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_51 { id_50, dsum1_snd_85 };
                      choose_res_49 = id_51;
                    } else {
                      uint16_t id_52 { 7 };
                      bool id_53 { bool(id_52 == dsum1_fst_84) };
                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_54;
                      if (id_53) {
                        (void)::dessser::VOID;
                        std::shared_ptr<::dessser::gen::raql_type::base>  id_55 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<7>, ::dessser::VOID) };
                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_56 { id_55, dsum1_snd_85 };
                        choose_res_54 = id_56;
                      } else {
                        uint16_t id_57 { 8 };
                        bool id_58 { bool(id_57 == dsum1_fst_84) };
                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_59;
                        if (id_58) {
                          (void)::dessser::VOID;
                          std::shared_ptr<::dessser::gen::raql_type::base>  id_60 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<8>, ::dessser::VOID) };
                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_61 { id_60, dsum1_snd_85 };
                          choose_res_59 = id_61;
                        } else {
                          uint16_t id_62 { 9 };
                          bool id_63 { bool(id_62 == dsum1_fst_84) };
                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_64;
                          if (id_63) {
                            (void)::dessser::VOID;
                            std::shared_ptr<::dessser::gen::raql_type::base>  id_65 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<9>, ::dessser::VOID) };
                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_66 { id_65, dsum1_snd_85 };
                            choose_res_64 = id_66;
                          } else {
                            uint16_t id_67 { 10 };
                            bool id_68 { bool(id_67 == dsum1_fst_84) };
                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_69;
                            if (id_68) {
                              (void)::dessser::VOID;
                              std::shared_ptr<::dessser::gen::raql_type::base>  id_70 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<10>, ::dessser::VOID) };
                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_71 { id_70, dsum1_snd_85 };
                              choose_res_69 = id_71;
                            } else {
                              uint16_t id_72 { 11 };
                              bool id_73 { bool(id_72 == dsum1_fst_84) };
                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_74;
                              if (id_73) {
                                (void)::dessser::VOID;
                                std::shared_ptr<::dessser::gen::raql_type::base>  id_75 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<11>, ::dessser::VOID) };
                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_76 { id_75, dsum1_snd_85 };
                                choose_res_74 = id_76;
                              } else {
                                uint16_t id_77 { 12 };
                                bool id_78 { bool(id_77 == dsum1_fst_84) };
                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_79;
                                if (id_78) {
                                  (void)::dessser::VOID;
                                  std::shared_ptr<::dessser::gen::raql_type::base>  id_80 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<12>, ::dessser::VOID) };
                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_81 { id_80, dsum1_snd_85 };
                                  choose_res_79 = id_81;
                                } else {
                                  uint16_t id_82 { 13 };
                                  bool id_83 { bool(id_82 == dsum1_fst_84) };
                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_84;
                                  if (id_83) {
                                    (void)::dessser::VOID;
                                    std::shared_ptr<::dessser::gen::raql_type::base>  id_85 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<13>, ::dessser::VOID) };
                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_86 { id_85, dsum1_snd_85 };
                                    choose_res_84 = id_86;
                                  } else {
                                    uint16_t id_87 { 14 };
                                    bool id_88 { bool(id_87 == dsum1_fst_84) };
                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_89;
                                    if (id_88) {
                                      (void)::dessser::VOID;
                                      std::shared_ptr<::dessser::gen::raql_type::base>  id_90 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<14>, ::dessser::VOID) };
                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_91 { id_90, dsum1_snd_85 };
                                      choose_res_89 = id_91;
                                    } else {
                                      uint16_t id_92 { 15 };
                                      bool id_93 { bool(id_92 == dsum1_fst_84) };
                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_94;
                                      if (id_93) {
                                        (void)::dessser::VOID;
                                        std::shared_ptr<::dessser::gen::raql_type::base>  id_95 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<15>, ::dessser::VOID) };
                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_96 { id_95, dsum1_snd_85 };
                                        choose_res_94 = id_96;
                                      } else {
                                        uint16_t id_97 { 16 };
                                        bool id_98 { bool(id_97 == dsum1_fst_84) };
                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_99;
                                        if (id_98) {
                                          (void)::dessser::VOID;
                                          std::shared_ptr<::dessser::gen::raql_type::base>  id_100 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<16>, ::dessser::VOID) };
                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_101 { id_100, dsum1_snd_85 };
                                          choose_res_99 = id_101;
                                        } else {
                                          uint16_t id_102 { 17 };
                                          bool id_103 { bool(id_102 == dsum1_fst_84) };
                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_104;
                                          if (id_103) {
                                            (void)::dessser::VOID;
                                            std::shared_ptr<::dessser::gen::raql_type::base>  id_105 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<17>, ::dessser::VOID) };
                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_106 { id_105, dsum1_snd_85 };
                                            choose_res_104 = id_106;
                                          } else {
                                            uint16_t id_107 { 18 };
                                            bool id_108 { bool(id_107 == dsum1_fst_84) };
                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_109;
                                            if (id_108) {
                                              (void)::dessser::VOID;
                                              std::shared_ptr<::dessser::gen::raql_type::base>  id_110 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<18>, ::dessser::VOID) };
                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_111 { id_110, dsum1_snd_85 };
                                              choose_res_109 = id_111;
                                            } else {
                                              uint16_t id_112 { 19 };
                                              bool id_113 { bool(id_112 == dsum1_fst_84) };
                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_114;
                                              if (id_113) {
                                                (void)::dessser::VOID;
                                                std::shared_ptr<::dessser::gen::raql_type::base>  id_115 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<19>, ::dessser::VOID) };
                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_116 { id_115, dsum1_snd_85 };
                                                choose_res_114 = id_116;
                                              } else {
                                                uint16_t id_117 { 20 };
                                                bool id_118 { bool(id_117 == dsum1_fst_84) };
                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_119;
                                                if (id_118) {
                                                  (void)::dessser::VOID;
                                                  std::shared_ptr<::dessser::gen::raql_type::base>  id_120 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<20>, ::dessser::VOID) };
                                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_121 { id_120, dsum1_snd_85 };
                                                  choose_res_119 = id_121;
                                                } else {
                                                  uint16_t id_122 { 21 };
                                                  bool id_123 { bool(id_122 == dsum1_fst_84) };
                                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_124;
                                                  if (id_123) {
                                                    (void)::dessser::VOID;
                                                    std::shared_ptr<::dessser::gen::raql_type::base>  id_125 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<21>, ::dessser::VOID) };
                                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_126 { id_125, dsum1_snd_85 };
                                                    choose_res_124 = id_126;
                                                  } else {
                                                    uint16_t id_127 { 22 };
                                                    bool id_128 { bool(id_127 == dsum1_fst_84) };
                                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_129;
                                                    if (id_128) {
                                                      (void)::dessser::VOID;
                                                      std::shared_ptr<::dessser::gen::raql_type::base>  id_130 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<22>, ::dessser::VOID) };
                                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_131 { id_130, dsum1_snd_85 };
                                                      choose_res_129 = id_131;
                                                    } else {
                                                      uint16_t id_132 { 23 };
                                                      bool id_133 { bool(id_132 == dsum1_fst_84) };
                                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_134;
                                                      if (id_133) {
                                                        (void)::dessser::VOID;
                                                        std::shared_ptr<::dessser::gen::raql_type::base>  id_135 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<23>, ::dessser::VOID) };
                                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_136 { id_135, dsum1_snd_85 };
                                                        choose_res_134 = id_136;
                                                      } else {
                                                        uint16_t id_137 { 24 };
                                                        bool id_138 { bool(id_137 == dsum1_fst_84) };
                                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_139;
                                                        if (id_138) {
                                                          (void)::dessser::VOID;
                                                          std::shared_ptr<::dessser::gen::raql_type::base>  id_140 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<24>, ::dessser::VOID) };
                                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_141 { id_140, dsum1_snd_85 };
                                                          choose_res_139 = id_141;
                                                        } else {
                                                          uint16_t id_142 { 25 };
                                                          bool id_143 { bool(id_142 == dsum1_fst_84) };
                                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_144;
                                                          if (id_143) {
                                                            (void)::dessser::VOID;
                                                            std::shared_ptr<::dessser::gen::raql_type::base>  id_145 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<25>, ::dessser::VOID) };
                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_146 { id_145, dsum1_snd_85 };
                                                            choose_res_144 = id_146;
                                                          } else {
                                                            uint16_t id_147 { 26 };
                                                            bool id_148 { bool(id_147 == dsum1_fst_84) };
                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_149;
                                                            if (id_148) {
                                                              (void)::dessser::VOID;
                                                              std::shared_ptr<::dessser::gen::raql_type::base>  id_150 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<26>, ::dessser::VOID) };
                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_151 { id_150, dsum1_snd_85 };
                                                              choose_res_149 = id_151;
                                                            } else {
                                                              uint16_t id_152 { 27 };
                                                              bool id_153 { bool(id_152 == dsum1_fst_84) };
                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_154;
                                                              if (id_153) {
                                                                (void)::dessser::VOID;
                                                                std::shared_ptr<::dessser::gen::raql_type::base>  id_155 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<27>, ::dessser::VOID) };
                                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_156 { id_155, dsum1_snd_85 };
                                                                choose_res_154 = id_156;
                                                              } else {
                                                                uint16_t id_157 { 28 };
                                                                bool id_158 { bool(id_157 == dsum1_fst_84) };
                                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_159;
                                                                if (id_158) {
                                                                  (void)::dessser::VOID;
                                                                  std::shared_ptr<::dessser::gen::raql_type::base>  id_160 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<28>, ::dessser::VOID) };
                                                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_161 { id_160, dsum1_snd_85 };
                                                                  choose_res_159 = id_161;
                                                                } else {
                                                                  uint16_t id_162 { 29 };
                                                                  bool id_163 { bool(id_162 == dsum1_fst_84) };
                                                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_164;
                                                                  if (id_163) {
                                                                    (void)::dessser::VOID;
                                                                    std::shared_ptr<::dessser::gen::raql_type::base>  id_165 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<29>, ::dessser::VOID) };
                                                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_166 { id_165, dsum1_snd_85 };
                                                                    choose_res_164 = id_166;
                                                                  } else {
                                                                    uint16_t id_167 { 30 };
                                                                    bool id_168 { bool(id_167 == dsum1_fst_84) };
                                                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_169;
                                                                    if (id_168) {
                                                                      uint32_t id_170 { 0U };
                                                                      Vec<1, uint32_t> id_171 {  id_170  };
                                                                      ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_172;
                                                                      {
                                                                        Vec<1, uint32_t> leb_ref_162 { id_171 };
                                                                        uint8_t id_173 { 0 };
                                                                        Vec<1, uint8_t> id_174 {  id_173  };
                                                                        ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_175;
                                                                        {
                                                                          Vec<1, uint8_t> shft_ref_163 { id_174 };
                                                                          Vec<1, Pointer> id_176 {  dsum1_snd_85  };
                                                                          ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_177;
                                                                          {
                                                                            Vec<1, Pointer> p_ref_164 { id_176 };
                                                                            bool while_flag_178 { true };
                                                                            do {
                                                                              uint8_t id_179 { 0 };
                                                                              Pointer id_180 { p_ref_164[id_179] };
                                                                              ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_181 { id_180.readU8() };
                                                                              bool let_res_182;
                                                                              {
                                                                                ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_165 { id_181 };
                                                                                bool letpair_res_183;
                                                                                {
                                                                                  auto leb128_fst_166 { std::get<0>(leb128_165) };
                                                                                  auto leb128_snd_167 { std::get<1>(leb128_165) };
                                                                                  uint8_t id_184 { 0 };
                                                                                  Void id_185 { ((void)(p_ref_164[id_184] = leb128_snd_167), ::dessser::VOID) };
                                                                                  (void)id_185;
                                                                                  uint8_t id_186 { 0 };
                                                                                  uint8_t id_187 { 127 };
                                                                                  uint8_t id_188 { uint8_t(leb128_fst_166 & id_187) };
                                                                                  uint32_t id_189 { uint32_t(id_188) };
                                                                                  uint8_t id_190 { 0 };
                                                                                  uint8_t id_191 { shft_ref_163[id_190] };
                                                                                  uint32_t id_192 { uint32_t(id_189 << id_191) };
                                                                                  uint8_t id_193 { 0 };
                                                                                  uint32_t id_194 { leb_ref_162[id_193] };
                                                                                  uint32_t id_195 { uint32_t(id_192 | id_194) };
                                                                                  Void id_196 { ((void)(leb_ref_162[id_186] = id_195), ::dessser::VOID) };
                                                                                  (void)id_196;
                                                                                  uint8_t id_197 { 0 };
                                                                                  uint8_t id_198 { 0 };
                                                                                  uint8_t id_199 { shft_ref_163[id_198] };
                                                                                  uint8_t id_200 { 7 };
                                                                                  uint8_t id_201 { uint8_t(id_199 + id_200) };
                                                                                  Void id_202 { ((void)(shft_ref_163[id_197] = id_201), ::dessser::VOID) };
                                                                                  (void)id_202;
                                                                                  uint8_t id_203 { 128 };
                                                                                  bool id_204 { bool(leb128_fst_166 >= id_203) };
                                                                                  letpair_res_183 = id_204;
                                                                                }
                                                                                let_res_182 = letpair_res_183;
                                                                              }
                                                                              while_flag_178 = let_res_182;
                                                                              if (while_flag_178) {
                                                                                (void)::dessser::VOID;
                                                                              }
                                                                            } while (while_flag_178);
                                                                            (void)::dessser::VOID;
                                                                            uint8_t id_205 { 0 };
                                                                            uint32_t id_206 { leb_ref_162[id_205] };
                                                                            uint8_t id_207 { 0 };
                                                                            Pointer id_208 { p_ref_164[id_207] };
                                                                            ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 id_209 { id_206, id_208 };
                                                                            let_res_177 = id_209;
                                                                          }
                                                                          let_res_175 = let_res_177;
                                                                        }
                                                                        let_res_172 = let_res_175;
                                                                      }
                                                                      ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce let_res_210;
                                                                      {
                                                                        ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 dlist1_171 { let_res_172 };
                                                                        ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce letpair_res_211;
                                                                        {
                                                                          auto dlist1_fst_172 { std::get<0>(dlist1_171) };
                                                                          auto dlist1_snd_173 { std::get<1>(dlist1_171) };
                                                                          Lst<std::shared_ptr<::dessser::gen::raql_type::t> > endoflist_212;
                                                                          ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce id_213 { endoflist_212, dlist1_snd_173 };
                                                                          Vec<1, ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce> id_214 {  id_213  };
                                                                          ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce let_res_215;
                                                                          {
                                                                            Vec<1, ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce> inits_src_ref_174 { id_214 };
                                                                            int32_t id_216 { 0L };
                                                                            Vec<1, int32_t> id_217 {  id_216  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_175 { id_217 };
                                                                              bool while_flag_218 { true };
                                                                              do {
                                                                                int32_t id_219 { int32_t(dlist1_fst_172) };
                                                                                uint8_t id_220 { 0 };
                                                                                int32_t id_221 { repeat_n_175[id_220] };
                                                                                bool id_222 { bool(id_219 > id_221) };
                                                                                while_flag_218 = id_222;
                                                                                if (while_flag_218) {
                                                                                  uint8_t id_223 { 0 };
                                                                                  ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce id_224 { inits_src_ref_174[id_223] };
                                                                                  {
                                                                                    ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce dlist2_176 { id_224 };
                                                                                    {
                                                                                      auto dlist2_fst_177 { std::get<0>(dlist2_176) };
                                                                                      auto dlist2_snd_178 { std::get<1>(dlist2_176) };
                                                                                      uint8_t id_225 { 0 };
                                                                                      ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_226 { of_row_binary(dlist2_snd_178) };
                                                                                      ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce letpair_res_227;
                                                                                      {
                                                                                        auto dlist3_fst_180 { std::get<0>(id_226) };
                                                                                        auto dlist3_snd_181 { std::get<1>(id_226) };
                                                                                        Lst<std::shared_ptr<::dessser::gen::raql_type::t> > id_228 { dlist3_fst_180, dlist2_fst_177 };
                                                                                        ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce id_229 { id_228, dlist3_snd_181 };
                                                                                        letpair_res_227 = id_229;
                                                                                      }
                                                                                      Void id_230 { ((void)(inits_src_ref_174[id_225] = letpair_res_227), ::dessser::VOID) };
                                                                                      (void)id_230;
                                                                                    }
                                                                                    (void)::dessser::VOID;
                                                                                  }
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_231 { 0 };
                                                                                  uint8_t id_232 { 0 };
                                                                                  int32_t id_233 { repeat_n_175[id_232] };
                                                                                  int32_t id_234 { 1L };
                                                                                  int32_t id_235 { int32_t(id_233 + id_234) };
                                                                                  Void id_236 { ((void)(repeat_n_175[id_231] = id_235), ::dessser::VOID) };
                                                                                  (void)id_236;
                                                                                  (void)id_236;
                                                                                }
                                                                              } while (while_flag_218);
                                                                              (void)::dessser::VOID;
                                                                            }
                                                                            (void)::dessser::VOID;
                                                                            uint8_t id_237 { 0 };
                                                                            ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce id_238 { inits_src_ref_174[id_237] };
                                                                            let_res_215 = id_238;
                                                                          }
                                                                          letpair_res_211 = let_res_215;
                                                                        }
                                                                        let_res_210 = letpair_res_211;
                                                                      }
                                                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_239;
                                                                      {
                                                                        auto dlist4_fst_183 { std::get<0>(let_res_210) };
                                                                        auto dlist4_snd_184 { std::get<1>(let_res_210) };
                                                                        Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_240 { dlist4_fst_183.toListRev() };
                                                                        std::shared_ptr<::dessser::gen::raql_type::base>  id_241 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<30>, id_240) };
                                                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_242 { id_241, dlist4_snd_184 };
                                                                        letpair_res_239 = id_242;
                                                                      }
                                                                      choose_res_169 = letpair_res_239;
                                                                    } else {
                                                                      uint16_t id_243 { 31 };
                                                                      bool id_244 { bool(id_243 == dsum1_fst_84) };
                                                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_245;
                                                                      if (id_244) {
                                                                        ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 id_246 { dsum1_snd_85.readU32Le() };
                                                                        ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_247;
                                                                        {
                                                                          auto du32_fst_151 { std::get<0>(id_246) };
                                                                          auto du32_snd_152 { std::get<1>(id_246) };
                                                                          ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 id_248 { du32_fst_151, du32_snd_152 };
                                                                          letpair_res_247 = id_248;
                                                                        }
                                                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 let_res_249;
                                                                        {
                                                                          ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 dtup_153 { letpair_res_247 };
                                                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_250;
                                                                          {
                                                                            auto dtup_fst_154 { std::get<0>(dtup_153) };
                                                                            auto dtup_snd_155 { std::get<1>(dtup_153) };
                                                                            ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_251 { of_row_binary(dtup_snd_155) };
                                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_252;
                                                                            {
                                                                              auto dtup_fst_157 { std::get<0>(id_251) };
                                                                              auto dtup_snd_158 { std::get<1>(id_251) };
                                                                              ::dessser::gen::raql_type::tb65a12146ab462f3a71f0a2c9184c7a4 id_253 { dtup_fst_154, dtup_fst_157 };
                                                                              std::shared_ptr<::dessser::gen::raql_type::base>  id_254 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<31>, id_253) };
                                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_255 { id_254, dtup_snd_158 };
                                                                              letpair_res_252 = id_255;
                                                                            }
                                                                            letpair_res_250 = letpair_res_252;
                                                                          }
                                                                          let_res_249 = letpair_res_250;
                                                                        }
                                                                        choose_res_245 = let_res_249;
                                                                      } else {
                                                                        uint16_t id_256 { 32 };
                                                                        bool id_257 { bool(id_256 == dsum1_fst_84) };
                                                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_258;
                                                                        if (id_257) {
                                                                          ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_259 { of_row_binary(dsum1_snd_85) };
                                                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_260;
                                                                          {
                                                                            auto dsum2_fst_148 { std::get<0>(id_259) };
                                                                            auto dsum2_snd_149 { std::get<1>(id_259) };
                                                                            std::shared_ptr<::dessser::gen::raql_type::base>  id_261 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<32>, dsum2_fst_148) };
                                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_262 { id_261, dsum2_snd_149 };
                                                                            letpair_res_260 = id_262;
                                                                          }
                                                                          choose_res_258 = letpair_res_260;
                                                                        } else {
                                                                          uint16_t id_263 { 33 };
                                                                          bool id_264 { bool(id_263 == dsum1_fst_84) };
                                                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_265;
                                                                          if (id_264) {
                                                                            uint32_t id_266 { 0U };
                                                                            Vec<1, uint32_t> id_267 {  id_266  };
                                                                            ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_268;
                                                                            {
                                                                              Vec<1, uint32_t> leb_ref_121 { id_267 };
                                                                              uint8_t id_269 { 0 };
                                                                              Vec<1, uint8_t> id_270 {  id_269  };
                                                                              ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_271;
                                                                              {
                                                                                Vec<1, uint8_t> shft_ref_122 { id_270 };
                                                                                Vec<1, Pointer> id_272 {  dsum1_snd_85  };
                                                                                ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_273;
                                                                                {
                                                                                  Vec<1, Pointer> p_ref_123 { id_272 };
                                                                                  bool while_flag_274 { true };
                                                                                  do {
                                                                                    uint8_t id_275 { 0 };
                                                                                    Pointer id_276 { p_ref_123[id_275] };
                                                                                    ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_277 { id_276.readU8() };
                                                                                    bool let_res_278;
                                                                                    {
                                                                                      ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_124 { id_277 };
                                                                                      bool letpair_res_279;
                                                                                      {
                                                                                        auto leb128_fst_125 { std::get<0>(leb128_124) };
                                                                                        auto leb128_snd_126 { std::get<1>(leb128_124) };
                                                                                        uint8_t id_280 { 0 };
                                                                                        Void id_281 { ((void)(p_ref_123[id_280] = leb128_snd_126), ::dessser::VOID) };
                                                                                        (void)id_281;
                                                                                        uint8_t id_282 { 0 };
                                                                                        uint8_t id_283 { 127 };
                                                                                        uint8_t id_284 { uint8_t(leb128_fst_125 & id_283) };
                                                                                        uint32_t id_285 { uint32_t(id_284) };
                                                                                        uint8_t id_286 { 0 };
                                                                                        uint8_t id_287 { shft_ref_122[id_286] };
                                                                                        uint32_t id_288 { uint32_t(id_285 << id_287) };
                                                                                        uint8_t id_289 { 0 };
                                                                                        uint32_t id_290 { leb_ref_121[id_289] };
                                                                                        uint32_t id_291 { uint32_t(id_288 | id_290) };
                                                                                        Void id_292 { ((void)(leb_ref_121[id_282] = id_291), ::dessser::VOID) };
                                                                                        (void)id_292;
                                                                                        uint8_t id_293 { 0 };
                                                                                        uint8_t id_294 { 0 };
                                                                                        uint8_t id_295 { shft_ref_122[id_294] };
                                                                                        uint8_t id_296 { 7 };
                                                                                        uint8_t id_297 { uint8_t(id_295 + id_296) };
                                                                                        Void id_298 { ((void)(shft_ref_122[id_293] = id_297), ::dessser::VOID) };
                                                                                        (void)id_298;
                                                                                        uint8_t id_299 { 128 };
                                                                                        bool id_300 { bool(leb128_fst_125 >= id_299) };
                                                                                        letpair_res_279 = id_300;
                                                                                      }
                                                                                      let_res_278 = letpair_res_279;
                                                                                    }
                                                                                    while_flag_274 = let_res_278;
                                                                                    if (while_flag_274) {
                                                                                      (void)::dessser::VOID;
                                                                                    }
                                                                                  } while (while_flag_274);
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_301 { 0 };
                                                                                  uint32_t id_302 { leb_ref_121[id_301] };
                                                                                  uint8_t id_303 { 0 };
                                                                                  Pointer id_304 { p_ref_123[id_303] };
                                                                                  ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 id_305 { id_302, id_304 };
                                                                                  let_res_273 = id_305;
                                                                                }
                                                                                let_res_271 = let_res_273;
                                                                              }
                                                                              let_res_268 = let_res_271;
                                                                            }
                                                                            ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b let_res_306;
                                                                            {
                                                                              ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 dlist1_130 { let_res_268 };
                                                                              ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b letpair_res_307;
                                                                              {
                                                                                auto dlist1_fst_131 { std::get<0>(dlist1_130) };
                                                                                auto dlist1_snd_132 { std::get<1>(dlist1_130) };
                                                                                Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> > endoflist_308;
                                                                                ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b id_309 { endoflist_308, dlist1_snd_132 };
                                                                                Vec<1, ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b> id_310 {  id_309  };
                                                                                ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b let_res_311;
                                                                                {
                                                                                  Vec<1, ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b> inits_src_ref_133 { id_310 };
                                                                                  int32_t id_312 { 0L };
                                                                                  Vec<1, int32_t> id_313 {  id_312  };
                                                                                  {
                                                                                    Vec<1, int32_t> repeat_n_134 { id_313 };
                                                                                    bool while_flag_314 { true };
                                                                                    do {
                                                                                      int32_t id_315 { int32_t(dlist1_fst_131) };
                                                                                      uint8_t id_316 { 0 };
                                                                                      int32_t id_317 { repeat_n_134[id_316] };
                                                                                      bool id_318 { bool(id_315 > id_317) };
                                                                                      while_flag_314 = id_318;
                                                                                      if (while_flag_314) {
                                                                                        uint8_t id_319 { 0 };
                                                                                        ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b id_320 { inits_src_ref_133[id_319] };
                                                                                        {
                                                                                          ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b dlist2_135 { id_320 };
                                                                                          {
                                                                                            auto dlist2_fst_136 { std::get<0>(dlist2_135) };
                                                                                            auto dlist2_snd_137 { std::get<1>(dlist2_135) };
                                                                                            uint8_t id_321 { 0 };
                                                                                            ::dessser::gen::raql_type::te9623fc9e468b565c42815c7eaf17382 id_322 { named_type_of_row_binary(dlist2_snd_137) };
                                                                                            ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b letpair_res_323;
                                                                                            {
                                                                                              auto dlist3_fst_139 { std::get<0>(id_322) };
                                                                                              auto dlist3_snd_140 { std::get<1>(id_322) };
                                                                                              Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_324 { dlist3_fst_139, dlist2_fst_136 };
                                                                                              ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b id_325 { id_324, dlist3_snd_140 };
                                                                                              letpair_res_323 = id_325;
                                                                                            }
                                                                                            Void id_326 { ((void)(inits_src_ref_133[id_321] = letpair_res_323), ::dessser::VOID) };
                                                                                            (void)id_326;
                                                                                          }
                                                                                          (void)::dessser::VOID;
                                                                                        }
                                                                                        (void)::dessser::VOID;
                                                                                        uint8_t id_327 { 0 };
                                                                                        uint8_t id_328 { 0 };
                                                                                        int32_t id_329 { repeat_n_134[id_328] };
                                                                                        int32_t id_330 { 1L };
                                                                                        int32_t id_331 { int32_t(id_329 + id_330) };
                                                                                        Void id_332 { ((void)(repeat_n_134[id_327] = id_331), ::dessser::VOID) };
                                                                                        (void)id_332;
                                                                                        (void)id_332;
                                                                                      }
                                                                                    } while (while_flag_314);
                                                                                    (void)::dessser::VOID;
                                                                                  }
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_333 { 0 };
                                                                                  ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b id_334 { inits_src_ref_133[id_333] };
                                                                                  let_res_311 = id_334;
                                                                                }
                                                                                letpair_res_307 = let_res_311;
                                                                              }
                                                                              let_res_306 = letpair_res_307;
                                                                            }
                                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_335;
                                                                            {
                                                                              auto dlist4_fst_142 { std::get<0>(let_res_306) };
                                                                              auto dlist4_snd_143 { std::get<1>(let_res_306) };
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_336 { dlist4_fst_142.toListRev() };
                                                                              std::shared_ptr<::dessser::gen::raql_type::base>  id_337 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<33>, id_336) };
                                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_338 { id_337, dlist4_snd_143 };
                                                                              letpair_res_335 = id_338;
                                                                            }
                                                                            choose_res_265 = letpair_res_335;
                                                                          } else {
                                                                            uint16_t id_339 { 34 };
                                                                            bool id_340 { bool(id_339 == dsum1_fst_84) };
                                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_341;
                                                                            if (id_340) {
                                                                              uint32_t id_342 { 0U };
                                                                              Vec<1, uint32_t> id_343 {  id_342  };
                                                                              ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_344;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_95 { id_343 };
                                                                                uint8_t id_345 { 0 };
                                                                                Vec<1, uint8_t> id_346 {  id_345  };
                                                                                ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_347;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_96 { id_346 };
                                                                                  Vec<1, Pointer> id_348 {  dsum1_snd_85  };
                                                                                  ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_349;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_97 { id_348 };
                                                                                    bool while_flag_350 { true };
                                                                                    do {
                                                                                      uint8_t id_351 { 0 };
                                                                                      Pointer id_352 { p_ref_97[id_351] };
                                                                                      ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_353 { id_352.readU8() };
                                                                                      bool let_res_354;
                                                                                      {
                                                                                        ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_98 { id_353 };
                                                                                        bool letpair_res_355;
                                                                                        {
                                                                                          auto leb128_fst_99 { std::get<0>(leb128_98) };
                                                                                          auto leb128_snd_100 { std::get<1>(leb128_98) };
                                                                                          uint8_t id_356 { 0 };
                                                                                          Void id_357 { ((void)(p_ref_97[id_356] = leb128_snd_100), ::dessser::VOID) };
                                                                                          (void)id_357;
                                                                                          uint8_t id_358 { 0 };
                                                                                          uint8_t id_359 { 127 };
                                                                                          uint8_t id_360 { uint8_t(leb128_fst_99 & id_359) };
                                                                                          uint32_t id_361 { uint32_t(id_360) };
                                                                                          uint8_t id_362 { 0 };
                                                                                          uint8_t id_363 { shft_ref_96[id_362] };
                                                                                          uint32_t id_364 { uint32_t(id_361 << id_363) };
                                                                                          uint8_t id_365 { 0 };
                                                                                          uint32_t id_366 { leb_ref_95[id_365] };
                                                                                          uint32_t id_367 { uint32_t(id_364 | id_366) };
                                                                                          Void id_368 { ((void)(leb_ref_95[id_358] = id_367), ::dessser::VOID) };
                                                                                          (void)id_368;
                                                                                          uint8_t id_369 { 0 };
                                                                                          uint8_t id_370 { 0 };
                                                                                          uint8_t id_371 { shft_ref_96[id_370] };
                                                                                          uint8_t id_372 { 7 };
                                                                                          uint8_t id_373 { uint8_t(id_371 + id_372) };
                                                                                          Void id_374 { ((void)(shft_ref_96[id_369] = id_373), ::dessser::VOID) };
                                                                                          (void)id_374;
                                                                                          uint8_t id_375 { 128 };
                                                                                          bool id_376 { bool(leb128_fst_99 >= id_375) };
                                                                                          letpair_res_355 = id_376;
                                                                                        }
                                                                                        let_res_354 = letpair_res_355;
                                                                                      }
                                                                                      while_flag_350 = let_res_354;
                                                                                      if (while_flag_350) {
                                                                                        (void)::dessser::VOID;
                                                                                      }
                                                                                    } while (while_flag_350);
                                                                                    (void)::dessser::VOID;
                                                                                    uint8_t id_377 { 0 };
                                                                                    uint32_t id_378 { leb_ref_95[id_377] };
                                                                                    uint8_t id_379 { 0 };
                                                                                    Pointer id_380 { p_ref_97[id_379] };
                                                                                    ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 id_381 { id_378, id_380 };
                                                                                    let_res_349 = id_381;
                                                                                  }
                                                                                  let_res_347 = let_res_349;
                                                                                }
                                                                                let_res_344 = let_res_347;
                                                                              }
                                                                              ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b let_res_382;
                                                                              {
                                                                                ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 dlist1_104 { let_res_344 };
                                                                                ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b letpair_res_383;
                                                                                {
                                                                                  auto dlist1_fst_105 { std::get<0>(dlist1_104) };
                                                                                  auto dlist1_snd_106 { std::get<1>(dlist1_104) };
                                                                                  Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> > endoflist_384;
                                                                                  ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b id_385 { endoflist_384, dlist1_snd_106 };
                                                                                  Vec<1, ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b> id_386 {  id_385  };
                                                                                  ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b let_res_387;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b> inits_src_ref_107 { id_386 };
                                                                                    int32_t id_388 { 0L };
                                                                                    Vec<1, int32_t> id_389 {  id_388  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_108 { id_389 };
                                                                                      bool while_flag_390 { true };
                                                                                      do {
                                                                                        int32_t id_391 { int32_t(dlist1_fst_105) };
                                                                                        uint8_t id_392 { 0 };
                                                                                        int32_t id_393 { repeat_n_108[id_392] };
                                                                                        bool id_394 { bool(id_391 > id_393) };
                                                                                        while_flag_390 = id_394;
                                                                                        if (while_flag_390) {
                                                                                          uint8_t id_395 { 0 };
                                                                                          ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b id_396 { inits_src_ref_107[id_395] };
                                                                                          {
                                                                                            ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b dlist2_109 { id_396 };
                                                                                            {
                                                                                              auto dlist2_fst_110 { std::get<0>(dlist2_109) };
                                                                                              auto dlist2_snd_111 { std::get<1>(dlist2_109) };
                                                                                              uint8_t id_397 { 0 };
                                                                                              ::dessser::gen::raql_type::te9623fc9e468b565c42815c7eaf17382 id_398 { named_type_of_row_binary(dlist2_snd_111) };
                                                                                              ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b letpair_res_399;
                                                                                              {
                                                                                                auto dlist3_fst_113 { std::get<0>(id_398) };
                                                                                                auto dlist3_snd_114 { std::get<1>(id_398) };
                                                                                                Lst<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_400 { dlist3_fst_113, dlist2_fst_110 };
                                                                                                ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b id_401 { id_400, dlist3_snd_114 };
                                                                                                letpair_res_399 = id_401;
                                                                                              }
                                                                                              Void id_402 { ((void)(inits_src_ref_107[id_397] = letpair_res_399), ::dessser::VOID) };
                                                                                              (void)id_402;
                                                                                            }
                                                                                            (void)::dessser::VOID;
                                                                                          }
                                                                                          (void)::dessser::VOID;
                                                                                          uint8_t id_403 { 0 };
                                                                                          uint8_t id_404 { 0 };
                                                                                          int32_t id_405 { repeat_n_108[id_404] };
                                                                                          int32_t id_406 { 1L };
                                                                                          int32_t id_407 { int32_t(id_405 + id_406) };
                                                                                          Void id_408 { ((void)(repeat_n_108[id_403] = id_407), ::dessser::VOID) };
                                                                                          (void)id_408;
                                                                                          (void)id_408;
                                                                                        }
                                                                                      } while (while_flag_390);
                                                                                      (void)::dessser::VOID;
                                                                                    }
                                                                                    (void)::dessser::VOID;
                                                                                    uint8_t id_409 { 0 };
                                                                                    ::dessser::gen::raql_type::t12830831e15d5f74216c54da311f377b id_410 { inits_src_ref_107[id_409] };
                                                                                    let_res_387 = id_410;
                                                                                  }
                                                                                  letpair_res_383 = let_res_387;
                                                                                }
                                                                                let_res_382 = letpair_res_383;
                                                                              }
                                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_411;
                                                                              {
                                                                                auto dlist4_fst_116 { std::get<0>(let_res_382) };
                                                                                auto dlist4_snd_117 { std::get<1>(let_res_382) };
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_412 { dlist4_fst_116.toListRev() };
                                                                                std::shared_ptr<::dessser::gen::raql_type::base>  id_413 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<34>, id_412) };
                                                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_414 { id_413, dlist4_snd_117 };
                                                                                letpair_res_411 = id_414;
                                                                              }
                                                                              choose_res_341 = letpair_res_411;
                                                                            } else {
                                                                              uint16_t id_415 { 35 };
                                                                              bool id_416 { bool(dsum1_fst_84 == id_415) };
                                                                              Void id_417 { ((void)(assert(id_416)), ::dessser::VOID) };
                                                                              (void)id_417;
                                                                              ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_418 { of_row_binary(dsum1_snd_85) };
                                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 let_res_419;
                                                                              {
                                                                                ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 dtup_86 { id_418 };
                                                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_420;
                                                                                {
                                                                                  auto dtup_fst_87 { std::get<0>(dtup_86) };
                                                                                  auto dtup_snd_88 { std::get<1>(dtup_86) };
                                                                                  ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_421 { of_row_binary(dtup_snd_88) };
                                                                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_422;
                                                                                  {
                                                                                    auto dtup_fst_90 { std::get<0>(id_421) };
                                                                                    auto dtup_snd_91 { std::get<1>(id_421) };
                                                                                    ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d id_423 { dtup_fst_87, dtup_fst_90 };
                                                                                    std::shared_ptr<::dessser::gen::raql_type::base>  id_424 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<35>, id_423) };
                                                                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_425 { id_424, dtup_snd_91 };
                                                                                    letpair_res_422 = id_425;
                                                                                  }
                                                                                  letpair_res_420 = letpair_res_422;
                                                                                }
                                                                                let_res_419 = letpair_res_420;
                                                                              }
                                                                              choose_res_341 = let_res_419;
                                                                            }
                                                                            choose_res_265 = choose_res_341;
                                                                          }
                                                                          choose_res_258 = choose_res_265;
                                                                        }
                                                                        choose_res_245 = choose_res_258;
                                                                      }
                                                                      choose_res_169 = choose_res_245;
                                                                    }
                                                                    choose_res_164 = choose_res_169;
                                                                  }
                                                                  choose_res_159 = choose_res_164;
                                                                }
                                                                choose_res_154 = choose_res_159;
                                                              }
                                                              choose_res_149 = choose_res_154;
                                                            }
                                                            choose_res_144 = choose_res_149;
                                                          }
                                                          choose_res_139 = choose_res_144;
                                                        }
                                                        choose_res_134 = choose_res_139;
                                                      }
                                                      choose_res_129 = choose_res_134;
                                                    }
                                                    choose_res_124 = choose_res_129;
                                                  }
                                                  choose_res_119 = choose_res_124;
                                                }
                                                choose_res_114 = choose_res_119;
                                              }
                                              choose_res_109 = choose_res_114;
                                            }
                                            choose_res_104 = choose_res_109;
                                          }
                                          choose_res_99 = choose_res_104;
                                        }
                                        choose_res_94 = choose_res_99;
                                      }
                                      choose_res_89 = choose_res_94;
                                    }
                                    choose_res_84 = choose_res_89;
                                  }
                                  choose_res_79 = choose_res_84;
                                }
                                choose_res_74 = choose_res_79;
                              }
                              choose_res_69 = choose_res_74;
                            }
                            choose_res_64 = choose_res_69;
                          }
                          choose_res_59 = choose_res_64;
                        }
                        choose_res_54 = choose_res_59;
                      }
                      choose_res_49 = choose_res_54;
                    }
                    choose_res_44 = choose_res_49;
                  }
                  choose_res_39 = choose_res_44;
                }
                choose_res_34 = choose_res_39;
              }
              choose_res_29 = choose_res_34;
            }
            choose_res_24 = choose_res_29;
          }
          choose_res_19 = choose_res_24;
        }
        letpair_res_16 = choose_res_19;
      }
      let_res_15 = letpair_res_16;
    }
    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_426;
    {
      auto make_fst_279 { std::get<0>(let_res_15) };
      auto make_snd_280 { std::get<1>(let_res_15) };
      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_427 { make_fst_279, make_snd_280 };
      letpair_res_426 = id_427;
    }
    return letpair_res_426;
  }
   };
  return fun11;
}
std::function<::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0(Pointer)> base_of_row_binary(base_of_row_binary_init());

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
static std::function<::dessser::gen::raql_type::te9623fc9e468b565c42815c7eaf17382(Pointer)> named_type_of_row_binary_init()
{
  std::function<::dessser::gen::raql_type::te9623fc9e468b565c42815c7eaf17382(Pointer)> fun428 { [&fun428](Pointer p_0) {
    uint32_t id_429 { 0U };
    Vec<1, uint32_t> id_430 {  id_429  };
    ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 let_res_431;
    {
      Vec<1, uint32_t> leb_ref_56 { id_430 };
      uint8_t id_432 { 0 };
      Vec<1, uint8_t> id_433 {  id_432  };
      ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 let_res_434;
      {
        Vec<1, uint8_t> shft_ref_57 { id_433 };
        Vec<1, Pointer> id_435 {  p_0  };
        ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 let_res_436;
        {
          Vec<1, Pointer> p_ref_58 { id_435 };
          bool while_flag_437 { true };
          do {
            uint8_t id_438 { 0 };
            Pointer id_439 { p_ref_58[id_438] };
            ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_440 { id_439.readU8() };
            bool let_res_441;
            {
              ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_59 { id_440 };
              bool letpair_res_442;
              {
                auto leb128_fst_60 { std::get<0>(leb128_59) };
                auto leb128_snd_61 { std::get<1>(leb128_59) };
                uint8_t id_443 { 0 };
                Void id_444 { ((void)(p_ref_58[id_443] = leb128_snd_61), ::dessser::VOID) };
                (void)id_444;
                uint8_t id_445 { 0 };
                uint8_t id_446 { 127 };
                uint8_t id_447 { uint8_t(leb128_fst_60 & id_446) };
                uint32_t id_448 { uint32_t(id_447) };
                uint8_t id_449 { 0 };
                uint8_t id_450 { shft_ref_57[id_449] };
                uint32_t id_451 { uint32_t(id_448 << id_450) };
                uint8_t id_452 { 0 };
                uint32_t id_453 { leb_ref_56[id_452] };
                uint32_t id_454 { uint32_t(id_451 | id_453) };
                Void id_455 { ((void)(leb_ref_56[id_445] = id_454), ::dessser::VOID) };
                (void)id_455;
                uint8_t id_456 { 0 };
                uint8_t id_457 { 0 };
                uint8_t id_458 { shft_ref_57[id_457] };
                uint8_t id_459 { 7 };
                uint8_t id_460 { uint8_t(id_458 + id_459) };
                Void id_461 { ((void)(shft_ref_57[id_456] = id_460), ::dessser::VOID) };
                (void)id_461;
                uint8_t id_462 { 128 };
                bool id_463 { bool(leb128_fst_60 >= id_462) };
                letpair_res_442 = id_463;
              }
              let_res_441 = letpair_res_442;
            }
            while_flag_437 = let_res_441;
            if (while_flag_437) {
              (void)::dessser::VOID;
            }
          } while (while_flag_437);
          (void)::dessser::VOID;
          uint8_t id_464 { 0 };
          uint32_t id_465 { leb_ref_56[id_464] };
          Size id_466 { Size(id_465) };
          uint8_t id_467 { 0 };
          Pointer id_468 { p_ref_58[id_467] };
          ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 id_469 { id_466, id_468 };
          let_res_436 = id_469;
        }
        let_res_434 = let_res_436;
      }
      let_res_431 = let_res_434;
    }
    ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 let_res_470;
    {
      ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 dstring1_62 { let_res_431 };
      ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 letpair_res_471;
      {
        auto dstring1_fst_63 { std::get<0>(dstring1_62) };
        auto dstring1_snd_64 { std::get<1>(dstring1_62) };
        ::dessser::gen::raql_type::t5887709cc43c8c8e24d28211e8c970a2 id_472 { dstring1_snd_64.readBytes(dstring1_fst_63) };
        ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 letpair_res_473;
        {
          auto dstring2_fst_66 { std::get<0>(id_472) };
          auto dstring2_snd_67 { std::get<1>(id_472) };
          std::string id_474 { dstring2_fst_66.toString() };
          ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 id_475 { id_474, dstring2_snd_67 };
          letpair_res_473 = id_475;
        }
        letpair_res_471 = letpair_res_473;
      }
      let_res_470 = letpair_res_471;
    }
    ::dessser::gen::raql_type::te9623fc9e468b565c42815c7eaf17382 let_res_476;
    {
      ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 dtup_68 { let_res_470 };
      ::dessser::gen::raql_type::te9623fc9e468b565c42815c7eaf17382 letpair_res_477;
      {
        auto dtup_fst_69 { std::get<0>(dtup_68) };
        auto dtup_snd_70 { std::get<1>(dtup_68) };
        ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_478 { of_row_binary(dtup_snd_70) };
        ::dessser::gen::raql_type::te9623fc9e468b565c42815c7eaf17382 letpair_res_479;
        {
          auto dtup_fst_72 { std::get<0>(id_478) };
          auto dtup_snd_73 { std::get<1>(id_478) };
          std::shared_ptr<::dessser::gen::raql_type::named_type>  id_480 { std::make_shared<::dessser::gen::raql_type::named_type>(dtup_fst_69, dtup_fst_72) };
          ::dessser::gen::raql_type::te9623fc9e468b565c42815c7eaf17382 id_481 { id_480, dtup_snd_73 };
          letpair_res_479 = id_481;
        }
        letpair_res_477 = letpair_res_479;
      }
      let_res_476 = letpair_res_477;
    }
    return let_res_476;
  }
   };
  return fun428;
}
std::function<::dessser::gen::raql_type::te9623fc9e468b565c42815c7eaf17382(Pointer)> named_type_of_row_binary(named_type_of_row_binary_init());

/* 
    (fun ("{type: (base AS [Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]); nullable: BOOL}")
      (add (apply (identifier "base-sersize-of-row-binary") (get-field "type" (param 0))) (size 1)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t> )> fun482 { [&fun482](std::shared_ptr<::dessser::gen::raql_type::t>  p_0) {
    std::shared_ptr<::dessser::gen::raql_type::base>  id_483 { (*p_0).type };
    Size id_484 { base_sersize_of_row_binary(id_483) };
    Size id_485 { 1UL };
    Size id_486 { Size(id_484 + id_485) };
    return id_486;
  }
   };
  return fun482;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]")
      (let "label2_298" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_298")) (size 2)
          (if (eq (u16 1) (identifier "label2_298")) (size 2)
            (if (eq (u16 2) (identifier "label2_298")) (size 2)
              (if (eq (u16 3) (identifier "label2_298")) (size 2)
                (if (eq (u16 4) (identifier "label2_298")) (size 2)
                  (if (eq (u16 5) (identifier "label2_298")) (size 2)
                    (if (eq (u16 6) (identifier "label2_298")) (size 2)
                      (if (eq (u16 7) (identifier "label2_298")) (size 2)
                        (if (eq (u16 8) (identifier "label2_298")) (size 2)
                          (if (eq (u16 9) (identifier "label2_298")) 
                            (size 2)
                            (if (eq (u16 10) (identifier "label2_298")) 
                              (size 2)
                              (if (eq (u16 11) (identifier "label2_298")) 
                                (size 2)
                                (if (eq (u16 12) (identifier "label2_298")) 
                                  (size 2)
                                  (if (eq (u16 13) (identifier "label2_298")) 
                                    (size 2)
                                    (if (eq (u16 14) (identifier "label2_298")) 
                                      (size 2)
                                      (if (eq (u16 15) (identifier "label2_298")) 
                                        (size 2)
                                        (if (eq (u16 16) (identifier "label2_298")) 
                                          (size 2)
                                          (if (eq (u16 17) (identifier "label2_298")) 
                                            (size 2)
                                            (if (eq (u16 18) (identifier "label2_298")) 
                                              (size 2)
                                              (if (eq (u16 19) (identifier "label2_298")) 
                                                (size 2)
                                                (if (eq (u16 20) (identifier "label2_298")) 
                                                  (size 2)
                                                  (if (eq (u16 21) (identifier "label2_298")) 
                                                    (size 2)
                                                    (if (eq (u16 22) (identifier "label2_298")) 
                                                      (size 2)
                                                      (if (eq (u16 23) (identifier "label2_298")) 
                                                        (size 2)
                                                        (if (eq (u16 24) (identifier "label2_298")) 
                                                          (size 2)
                                                          (if (eq (u16 25) (identifier "label2_298")) 
                                                            (size 2)
                                                            (if (eq (u16 26) (identifier "label2_298")) 
                                                              (size 2)
                                                              (if (eq (u16 27) (identifier "label2_298")) 
                                                                (size 2)
                                                                (if (eq (u16 28) (identifier "label2_298")) 
                                                                  (size 2)
                                                                  (if 
                                                                    (eq (u16 29) (identifier "label2_298")) 
                                                                    (size 2)
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label2_298"))
                                                                    (let "sz_ref_313"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_311" 
                                                                    (make-vec (cardinality (get-alt "Tup" (param 0))))
                                                                    (let "lebsz_ref_312" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_311")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_312")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_312") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_312")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_312"))))))))
                                                                    (seq
                                                                    (let "repeat_n_314" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Tup" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_314")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_313")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_313"))
                                                                    (apply (identifier "sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_314")) (get-alt "Tup" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_314") (add (unsafe-nth (u8 0) (identifier "repeat_n_314")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_313"))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label2_298")) 
                                                                    (add (size 6) (apply (identifier "sersize-of-row-binary") (get-item 1 (get-alt "Vec" (param 0)))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label2_298")) 
                                                                    (add (size 2) (apply (identifier "sersize-of-row-binary") (get-alt "Arr" (param 0))))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label2_298"))
                                                                    (let "sz_ref_307"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_305" 
                                                                    (make-vec (cardinality (get-alt "Rec" (param 0))))
                                                                    (let "lebsz_ref_306" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_305")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_306")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_306") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_306")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_306"))))))))
                                                                    (seq
                                                                    (let "repeat_n_308" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Rec" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_308")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_307")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_307"))
                                                                    (apply (identifier "named_type-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_308")) (get-alt "Rec" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_308") (add (unsafe-nth (u8 0) (identifier "repeat_n_308")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_307"))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label2_298"))
                                                                    (let "sz_ref_303"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_301" 
                                                                    (make-vec (cardinality (get-alt "Sum" (param 0))))
                                                                    (let "lebsz_ref_302" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_301")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_302")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_302") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_302")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_302"))))))))
                                                                    (seq
                                                                    (let "repeat_n_304" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Sum" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_304")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_303")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_303"))
                                                                    (apply (identifier "named_type-sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_304")) (get-alt "Sum" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_304") (add (unsafe-nth (u8 0) (identifier "repeat_n_304")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_303"))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label2_298") (u16 35)))
                                                                    (let "sz_300" 
                                                                    (add (size 2) (apply (identifier "sersize-of-row-binary") (get-item 0 (get-alt "Map" (param 0)))))
                                                                    (add (identifier "sz_300") (apply (identifier "sersize-of-row-binary") (get-item 1 (get-alt "Map" (param 0))))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_type::base> )> base_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_type::base> )> fun487 { [&fun487](std::shared_ptr<::dessser::gen::raql_type::base>  p_0) {
    uint16_t id_488 { uint16_t((*p_0).index()) };
    Size let_res_489;
    {
      uint16_t label2_298 { id_488 };
      uint16_t id_490 { 0 };
      bool id_491 { bool(id_490 == label2_298) };
      Size choose_res_492;
      if (id_491) {
        Size id_493 { 2UL };
        choose_res_492 = id_493;
      } else {
        uint16_t id_494 { 1 };
        bool id_495 { bool(id_494 == label2_298) };
        Size choose_res_496;
        if (id_495) {
          Size id_497 { 2UL };
          choose_res_496 = id_497;
        } else {
          uint16_t id_498 { 2 };
          bool id_499 { bool(id_498 == label2_298) };
          Size choose_res_500;
          if (id_499) {
            Size id_501 { 2UL };
            choose_res_500 = id_501;
          } else {
            uint16_t id_502 { 3 };
            bool id_503 { bool(id_502 == label2_298) };
            Size choose_res_504;
            if (id_503) {
              Size id_505 { 2UL };
              choose_res_504 = id_505;
            } else {
              uint16_t id_506 { 4 };
              bool id_507 { bool(id_506 == label2_298) };
              Size choose_res_508;
              if (id_507) {
                Size id_509 { 2UL };
                choose_res_508 = id_509;
              } else {
                uint16_t id_510 { 5 };
                bool id_511 { bool(id_510 == label2_298) };
                Size choose_res_512;
                if (id_511) {
                  Size id_513 { 2UL };
                  choose_res_512 = id_513;
                } else {
                  uint16_t id_514 { 6 };
                  bool id_515 { bool(id_514 == label2_298) };
                  Size choose_res_516;
                  if (id_515) {
                    Size id_517 { 2UL };
                    choose_res_516 = id_517;
                  } else {
                    uint16_t id_518 { 7 };
                    bool id_519 { bool(id_518 == label2_298) };
                    Size choose_res_520;
                    if (id_519) {
                      Size id_521 { 2UL };
                      choose_res_520 = id_521;
                    } else {
                      uint16_t id_522 { 8 };
                      bool id_523 { bool(id_522 == label2_298) };
                      Size choose_res_524;
                      if (id_523) {
                        Size id_525 { 2UL };
                        choose_res_524 = id_525;
                      } else {
                        uint16_t id_526 { 9 };
                        bool id_527 { bool(id_526 == label2_298) };
                        Size choose_res_528;
                        if (id_527) {
                          Size id_529 { 2UL };
                          choose_res_528 = id_529;
                        } else {
                          uint16_t id_530 { 10 };
                          bool id_531 { bool(id_530 == label2_298) };
                          Size choose_res_532;
                          if (id_531) {
                            Size id_533 { 2UL };
                            choose_res_532 = id_533;
                          } else {
                            uint16_t id_534 { 11 };
                            bool id_535 { bool(id_534 == label2_298) };
                            Size choose_res_536;
                            if (id_535) {
                              Size id_537 { 2UL };
                              choose_res_536 = id_537;
                            } else {
                              uint16_t id_538 { 12 };
                              bool id_539 { bool(id_538 == label2_298) };
                              Size choose_res_540;
                              if (id_539) {
                                Size id_541 { 2UL };
                                choose_res_540 = id_541;
                              } else {
                                uint16_t id_542 { 13 };
                                bool id_543 { bool(id_542 == label2_298) };
                                Size choose_res_544;
                                if (id_543) {
                                  Size id_545 { 2UL };
                                  choose_res_544 = id_545;
                                } else {
                                  uint16_t id_546 { 14 };
                                  bool id_547 { bool(id_546 == label2_298) };
                                  Size choose_res_548;
                                  if (id_547) {
                                    Size id_549 { 2UL };
                                    choose_res_548 = id_549;
                                  } else {
                                    uint16_t id_550 { 15 };
                                    bool id_551 { bool(id_550 == label2_298) };
                                    Size choose_res_552;
                                    if (id_551) {
                                      Size id_553 { 2UL };
                                      choose_res_552 = id_553;
                                    } else {
                                      uint16_t id_554 { 16 };
                                      bool id_555 { bool(id_554 == label2_298) };
                                      Size choose_res_556;
                                      if (id_555) {
                                        Size id_557 { 2UL };
                                        choose_res_556 = id_557;
                                      } else {
                                        uint16_t id_558 { 17 };
                                        bool id_559 { bool(id_558 == label2_298) };
                                        Size choose_res_560;
                                        if (id_559) {
                                          Size id_561 { 2UL };
                                          choose_res_560 = id_561;
                                        } else {
                                          uint16_t id_562 { 18 };
                                          bool id_563 { bool(id_562 == label2_298) };
                                          Size choose_res_564;
                                          if (id_563) {
                                            Size id_565 { 2UL };
                                            choose_res_564 = id_565;
                                          } else {
                                            uint16_t id_566 { 19 };
                                            bool id_567 { bool(id_566 == label2_298) };
                                            Size choose_res_568;
                                            if (id_567) {
                                              Size id_569 { 2UL };
                                              choose_res_568 = id_569;
                                            } else {
                                              uint16_t id_570 { 20 };
                                              bool id_571 { bool(id_570 == label2_298) };
                                              Size choose_res_572;
                                              if (id_571) {
                                                Size id_573 { 2UL };
                                                choose_res_572 = id_573;
                                              } else {
                                                uint16_t id_574 { 21 };
                                                bool id_575 { bool(id_574 == label2_298) };
                                                Size choose_res_576;
                                                if (id_575) {
                                                  Size id_577 { 2UL };
                                                  choose_res_576 = id_577;
                                                } else {
                                                  uint16_t id_578 { 22 };
                                                  bool id_579 { bool(id_578 == label2_298) };
                                                  Size choose_res_580;
                                                  if (id_579) {
                                                    Size id_581 { 2UL };
                                                    choose_res_580 = id_581;
                                                  } else {
                                                    uint16_t id_582 { 23 };
                                                    bool id_583 { bool(id_582 == label2_298) };
                                                    Size choose_res_584;
                                                    if (id_583) {
                                                      Size id_585 { 2UL };
                                                      choose_res_584 = id_585;
                                                    } else {
                                                      uint16_t id_586 { 24 };
                                                      bool id_587 { bool(id_586 == label2_298) };
                                                      Size choose_res_588;
                                                      if (id_587) {
                                                        Size id_589 { 2UL };
                                                        choose_res_588 = id_589;
                                                      } else {
                                                        uint16_t id_590 { 25 };
                                                        bool id_591 { bool(id_590 == label2_298) };
                                                        Size choose_res_592;
                                                        if (id_591) {
                                                          Size id_593 { 2UL };
                                                          choose_res_592 = id_593;
                                                        } else {
                                                          uint16_t id_594 { 26 };
                                                          bool id_595 { bool(id_594 == label2_298) };
                                                          Size choose_res_596;
                                                          if (id_595) {
                                                            Size id_597 { 2UL };
                                                            choose_res_596 = id_597;
                                                          } else {
                                                            uint16_t id_598 { 27 };
                                                            bool id_599 { bool(id_598 == label2_298) };
                                                            Size choose_res_600;
                                                            if (id_599) {
                                                              Size id_601 { 2UL };
                                                              choose_res_600 = id_601;
                                                            } else {
                                                              uint16_t id_602 { 28 };
                                                              bool id_603 { bool(id_602 == label2_298) };
                                                              Size choose_res_604;
                                                              if (id_603) {
                                                                Size id_605 { 2UL };
                                                                choose_res_604 = id_605;
                                                              } else {
                                                                uint16_t id_606 { 29 };
                                                                bool id_607 { bool(id_606 == label2_298) };
                                                                Size choose_res_608;
                                                                if (id_607) {
                                                                  Size id_609 { 2UL };
                                                                  choose_res_608 = id_609;
                                                                } else {
                                                                  uint16_t id_610 { 30 };
                                                                  bool id_611 { bool(id_610 == label2_298) };
                                                                  Size choose_res_612;
                                                                  if (id_611) {
                                                                    Size id_613 { 2UL };
                                                                    Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_614 { std::get<30 /* Tup */>((*p_0)) };
                                                                    uint32_t id_615 { id_614.size() };
                                                                    Vec<1, uint32_t> id_616 {  id_615  };
                                                                    Size let_res_617;
                                                                    {
                                                                      Vec<1, uint32_t> n_ref_311 { id_616 };
                                                                      uint32_t id_618 { 1U };
                                                                      Vec<1, uint32_t> id_619 {  id_618  };
                                                                      Size let_res_620;
                                                                      {
                                                                        Vec<1, uint32_t> lebsz_ref_312 { id_619 };
                                                                        bool while_flag_621 { true };
                                                                        do {
                                                                          uint8_t id_622 { 0 };
                                                                          uint32_t id_623 { n_ref_311[id_622] };
                                                                          uint8_t id_624 { 0 };
                                                                          uint32_t id_625 { lebsz_ref_312[id_624] };
                                                                          uint8_t id_626 { 7 };
                                                                          uint32_t id_627 { uint32_t(id_625 << id_626) };
                                                                          bool id_628 { bool(id_623 >= id_627) };
                                                                          while_flag_621 = id_628;
                                                                          if (while_flag_621) {
                                                                            uint8_t id_629 { 0 };
                                                                            uint8_t id_630 { 0 };
                                                                            uint32_t id_631 { lebsz_ref_312[id_630] };
                                                                            uint32_t id_632 { 1U };
                                                                            uint32_t id_633 { uint32_t(id_631 + id_632) };
                                                                            Void id_634 { ((void)(lebsz_ref_312[id_629] = id_633), ::dessser::VOID) };
                                                                            (void)id_634;
                                                                          }
                                                                        } while (while_flag_621);
                                                                        (void)::dessser::VOID;
                                                                        uint8_t id_635 { 0 };
                                                                        uint32_t id_636 { lebsz_ref_312[id_635] };
                                                                        Size id_637 { Size(id_636) };
                                                                        let_res_620 = id_637;
                                                                      }
                                                                      let_res_617 = let_res_620;
                                                                    }
                                                                    Size id_638 { Size(id_613 + let_res_617) };
                                                                    Vec<1, Size> id_639 {  id_638  };
                                                                    Size let_res_640;
                                                                    {
                                                                      Vec<1, Size> sz_ref_313 { id_639 };
                                                                      int32_t id_641 { 0L };
                                                                      Vec<1, int32_t> id_642 {  id_641  };
                                                                      {
                                                                        Vec<1, int32_t> repeat_n_314 { id_642 };
                                                                        bool while_flag_643 { true };
                                                                        do {
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_644 { std::get<30 /* Tup */>((*p_0)) };
                                                                          uint32_t id_645 { id_644.size() };
                                                                          int32_t id_646 { int32_t(id_645) };
                                                                          uint8_t id_647 { 0 };
                                                                          int32_t id_648 { repeat_n_314[id_647] };
                                                                          bool id_649 { bool(id_646 > id_648) };
                                                                          while_flag_643 = id_649;
                                                                          if (while_flag_643) {
                                                                            uint8_t id_650 { 0 };
                                                                            uint8_t id_651 { 0 };
                                                                            Size id_652 { sz_ref_313[id_651] };
                                                                            uint8_t id_653 { 0 };
                                                                            int32_t id_654 { repeat_n_314[id_653] };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_655 { std::get<30 /* Tup */>((*p_0)) };
                                                                            std::shared_ptr<::dessser::gen::raql_type::t>  id_656 { id_655[id_654] };
                                                                            Size id_657 { sersize_of_row_binary(id_656) };
                                                                            Size id_658 { Size(id_652 + id_657) };
                                                                            Void id_659 { ((void)(sz_ref_313[id_650] = id_658), ::dessser::VOID) };
                                                                            (void)id_659;
                                                                            uint8_t id_660 { 0 };
                                                                            uint8_t id_661 { 0 };
                                                                            int32_t id_662 { repeat_n_314[id_661] };
                                                                            int32_t id_663 { 1L };
                                                                            int32_t id_664 { int32_t(id_662 + id_663) };
                                                                            Void id_665 { ((void)(repeat_n_314[id_660] = id_664), ::dessser::VOID) };
                                                                            (void)id_665;
                                                                            (void)id_665;
                                                                          }
                                                                        } while (while_flag_643);
                                                                        (void)::dessser::VOID;
                                                                      }
                                                                      (void)::dessser::VOID;
                                                                      uint8_t id_666 { 0 };
                                                                      Size id_667 { sz_ref_313[id_666] };
                                                                      let_res_640 = id_667;
                                                                    }
                                                                    choose_res_612 = let_res_640;
                                                                  } else {
                                                                    uint16_t id_668 { 31 };
                                                                    bool id_669 { bool(id_668 == label2_298) };
                                                                    Size choose_res_670;
                                                                    if (id_669) {
                                                                      Size id_671 { 6UL };
                                                                      ::dessser::gen::raql_type::tb65a12146ab462f3a71f0a2c9184c7a4 id_672 { std::get<31 /* Vec */>((*p_0)) };
                                                                      std::shared_ptr<::dessser::gen::raql_type::t>  id_673 { std::get<1>(id_672) };
                                                                      Size id_674 { sersize_of_row_binary(id_673) };
                                                                      Size id_675 { Size(id_671 + id_674) };
                                                                      choose_res_670 = id_675;
                                                                    } else {
                                                                      uint16_t id_676 { 32 };
                                                                      bool id_677 { bool(id_676 == label2_298) };
                                                                      Size choose_res_678;
                                                                      if (id_677) {
                                                                        Size id_679 { 2UL };
                                                                        std::shared_ptr<::dessser::gen::raql_type::t>  id_680 { std::get<32 /* Arr */>((*p_0)) };
                                                                        Size id_681 { sersize_of_row_binary(id_680) };
                                                                        Size id_682 { Size(id_679 + id_681) };
                                                                        choose_res_678 = id_682;
                                                                      } else {
                                                                        uint16_t id_683 { 33 };
                                                                        bool id_684 { bool(id_683 == label2_298) };
                                                                        Size choose_res_685;
                                                                        if (id_684) {
                                                                          Size id_686 { 2UL };
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_687 { std::get<33 /* Rec */>((*p_0)) };
                                                                          uint32_t id_688 { id_687.size() };
                                                                          Vec<1, uint32_t> id_689 {  id_688  };
                                                                          Size let_res_690;
                                                                          {
                                                                            Vec<1, uint32_t> n_ref_305 { id_689 };
                                                                            uint32_t id_691 { 1U };
                                                                            Vec<1, uint32_t> id_692 {  id_691  };
                                                                            Size let_res_693;
                                                                            {
                                                                              Vec<1, uint32_t> lebsz_ref_306 { id_692 };
                                                                              bool while_flag_694 { true };
                                                                              do {
                                                                                uint8_t id_695 { 0 };
                                                                                uint32_t id_696 { n_ref_305[id_695] };
                                                                                uint8_t id_697 { 0 };
                                                                                uint32_t id_698 { lebsz_ref_306[id_697] };
                                                                                uint8_t id_699 { 7 };
                                                                                uint32_t id_700 { uint32_t(id_698 << id_699) };
                                                                                bool id_701 { bool(id_696 >= id_700) };
                                                                                while_flag_694 = id_701;
                                                                                if (while_flag_694) {
                                                                                  uint8_t id_702 { 0 };
                                                                                  uint8_t id_703 { 0 };
                                                                                  uint32_t id_704 { lebsz_ref_306[id_703] };
                                                                                  uint32_t id_705 { 1U };
                                                                                  uint32_t id_706 { uint32_t(id_704 + id_705) };
                                                                                  Void id_707 { ((void)(lebsz_ref_306[id_702] = id_706), ::dessser::VOID) };
                                                                                  (void)id_707;
                                                                                }
                                                                              } while (while_flag_694);
                                                                              (void)::dessser::VOID;
                                                                              uint8_t id_708 { 0 };
                                                                              uint32_t id_709 { lebsz_ref_306[id_708] };
                                                                              Size id_710 { Size(id_709) };
                                                                              let_res_693 = id_710;
                                                                            }
                                                                            let_res_690 = let_res_693;
                                                                          }
                                                                          Size id_711 { Size(id_686 + let_res_690) };
                                                                          Vec<1, Size> id_712 {  id_711  };
                                                                          Size let_res_713;
                                                                          {
                                                                            Vec<1, Size> sz_ref_307 { id_712 };
                                                                            int32_t id_714 { 0L };
                                                                            Vec<1, int32_t> id_715 {  id_714  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_308 { id_715 };
                                                                              bool while_flag_716 { true };
                                                                              do {
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_717 { std::get<33 /* Rec */>((*p_0)) };
                                                                                uint32_t id_718 { id_717.size() };
                                                                                int32_t id_719 { int32_t(id_718) };
                                                                                uint8_t id_720 { 0 };
                                                                                int32_t id_721 { repeat_n_308[id_720] };
                                                                                bool id_722 { bool(id_719 > id_721) };
                                                                                while_flag_716 = id_722;
                                                                                if (while_flag_716) {
                                                                                  uint8_t id_723 { 0 };
                                                                                  uint8_t id_724 { 0 };
                                                                                  Size id_725 { sz_ref_307[id_724] };
                                                                                  uint8_t id_726 { 0 };
                                                                                  int32_t id_727 { repeat_n_308[id_726] };
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_728 { std::get<33 /* Rec */>((*p_0)) };
                                                                                  std::shared_ptr<::dessser::gen::raql_type::named_type>  id_729 { id_728[id_727] };
                                                                                  Size id_730 { named_type_sersize_of_row_binary(id_729) };
                                                                                  Size id_731 { Size(id_725 + id_730) };
                                                                                  Void id_732 { ((void)(sz_ref_307[id_723] = id_731), ::dessser::VOID) };
                                                                                  (void)id_732;
                                                                                  uint8_t id_733 { 0 };
                                                                                  uint8_t id_734 { 0 };
                                                                                  int32_t id_735 { repeat_n_308[id_734] };
                                                                                  int32_t id_736 { 1L };
                                                                                  int32_t id_737 { int32_t(id_735 + id_736) };
                                                                                  Void id_738 { ((void)(repeat_n_308[id_733] = id_737), ::dessser::VOID) };
                                                                                  (void)id_738;
                                                                                  (void)id_738;
                                                                                }
                                                                              } while (while_flag_716);
                                                                              (void)::dessser::VOID;
                                                                            }
                                                                            (void)::dessser::VOID;
                                                                            uint8_t id_739 { 0 };
                                                                            Size id_740 { sz_ref_307[id_739] };
                                                                            let_res_713 = id_740;
                                                                          }
                                                                          choose_res_685 = let_res_713;
                                                                        } else {
                                                                          uint16_t id_741 { 34 };
                                                                          bool id_742 { bool(id_741 == label2_298) };
                                                                          Size choose_res_743;
                                                                          if (id_742) {
                                                                            Size id_744 { 2UL };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_745 { std::get<34 /* Sum */>((*p_0)) };
                                                                            uint32_t id_746 { id_745.size() };
                                                                            Vec<1, uint32_t> id_747 {  id_746  };
                                                                            Size let_res_748;
                                                                            {
                                                                              Vec<1, uint32_t> n_ref_301 { id_747 };
                                                                              uint32_t id_749 { 1U };
                                                                              Vec<1, uint32_t> id_750 {  id_749  };
                                                                              Size let_res_751;
                                                                              {
                                                                                Vec<1, uint32_t> lebsz_ref_302 { id_750 };
                                                                                bool while_flag_752 { true };
                                                                                do {
                                                                                  uint8_t id_753 { 0 };
                                                                                  uint32_t id_754 { n_ref_301[id_753] };
                                                                                  uint8_t id_755 { 0 };
                                                                                  uint32_t id_756 { lebsz_ref_302[id_755] };
                                                                                  uint8_t id_757 { 7 };
                                                                                  uint32_t id_758 { uint32_t(id_756 << id_757) };
                                                                                  bool id_759 { bool(id_754 >= id_758) };
                                                                                  while_flag_752 = id_759;
                                                                                  if (while_flag_752) {
                                                                                    uint8_t id_760 { 0 };
                                                                                    uint8_t id_761 { 0 };
                                                                                    uint32_t id_762 { lebsz_ref_302[id_761] };
                                                                                    uint32_t id_763 { 1U };
                                                                                    uint32_t id_764 { uint32_t(id_762 + id_763) };
                                                                                    Void id_765 { ((void)(lebsz_ref_302[id_760] = id_764), ::dessser::VOID) };
                                                                                    (void)id_765;
                                                                                  }
                                                                                } while (while_flag_752);
                                                                                (void)::dessser::VOID;
                                                                                uint8_t id_766 { 0 };
                                                                                uint32_t id_767 { lebsz_ref_302[id_766] };
                                                                                Size id_768 { Size(id_767) };
                                                                                let_res_751 = id_768;
                                                                              }
                                                                              let_res_748 = let_res_751;
                                                                            }
                                                                            Size id_769 { Size(id_744 + let_res_748) };
                                                                            Vec<1, Size> id_770 {  id_769  };
                                                                            Size let_res_771;
                                                                            {
                                                                              Vec<1, Size> sz_ref_303 { id_770 };
                                                                              int32_t id_772 { 0L };
                                                                              Vec<1, int32_t> id_773 {  id_772  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_304 { id_773 };
                                                                                bool while_flag_774 { true };
                                                                                do {
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_775 { std::get<34 /* Sum */>((*p_0)) };
                                                                                  uint32_t id_776 { id_775.size() };
                                                                                  int32_t id_777 { int32_t(id_776) };
                                                                                  uint8_t id_778 { 0 };
                                                                                  int32_t id_779 { repeat_n_304[id_778] };
                                                                                  bool id_780 { bool(id_777 > id_779) };
                                                                                  while_flag_774 = id_780;
                                                                                  if (while_flag_774) {
                                                                                    uint8_t id_781 { 0 };
                                                                                    uint8_t id_782 { 0 };
                                                                                    Size id_783 { sz_ref_303[id_782] };
                                                                                    uint8_t id_784 { 0 };
                                                                                    int32_t id_785 { repeat_n_304[id_784] };
                                                                                    Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_786 { std::get<34 /* Sum */>((*p_0)) };
                                                                                    std::shared_ptr<::dessser::gen::raql_type::named_type>  id_787 { id_786[id_785] };
                                                                                    Size id_788 { named_type_sersize_of_row_binary(id_787) };
                                                                                    Size id_789 { Size(id_783 + id_788) };
                                                                                    Void id_790 { ((void)(sz_ref_303[id_781] = id_789), ::dessser::VOID) };
                                                                                    (void)id_790;
                                                                                    uint8_t id_791 { 0 };
                                                                                    uint8_t id_792 { 0 };
                                                                                    int32_t id_793 { repeat_n_304[id_792] };
                                                                                    int32_t id_794 { 1L };
                                                                                    int32_t id_795 { int32_t(id_793 + id_794) };
                                                                                    Void id_796 { ((void)(repeat_n_304[id_791] = id_795), ::dessser::VOID) };
                                                                                    (void)id_796;
                                                                                    (void)id_796;
                                                                                  }
                                                                                } while (while_flag_774);
                                                                                (void)::dessser::VOID;
                                                                              }
                                                                              (void)::dessser::VOID;
                                                                              uint8_t id_797 { 0 };
                                                                              Size id_798 { sz_ref_303[id_797] };
                                                                              let_res_771 = id_798;
                                                                            }
                                                                            choose_res_743 = let_res_771;
                                                                          } else {
                                                                            uint16_t id_799 { 35 };
                                                                            bool id_800 { bool(label2_298 == id_799) };
                                                                            Void id_801 { ((void)(assert(id_800)), ::dessser::VOID) };
                                                                            (void)id_801;
                                                                            Size id_802 { 2UL };
                                                                            ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d id_803 { std::get<35 /* Map */>((*p_0)) };
                                                                            std::shared_ptr<::dessser::gen::raql_type::t>  id_804 { std::get<0>(id_803) };
                                                                            Size id_805 { sersize_of_row_binary(id_804) };
                                                                            Size id_806 { Size(id_802 + id_805) };
                                                                            Size let_res_807;
                                                                            {
                                                                              Size sz_300 { id_806 };
                                                                              ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d id_808 { std::get<35 /* Map */>((*p_0)) };
                                                                              std::shared_ptr<::dessser::gen::raql_type::t>  id_809 { std::get<1>(id_808) };
                                                                              Size id_810 { sersize_of_row_binary(id_809) };
                                                                              Size id_811 { Size(sz_300 + id_810) };
                                                                              let_res_807 = id_811;
                                                                            }
                                                                            choose_res_743 = let_res_807;
                                                                          }
                                                                          choose_res_685 = choose_res_743;
                                                                        }
                                                                        choose_res_678 = choose_res_685;
                                                                      }
                                                                      choose_res_670 = choose_res_678;
                                                                    }
                                                                    choose_res_612 = choose_res_670;
                                                                  }
                                                                  choose_res_608 = choose_res_612;
                                                                }
                                                                choose_res_604 = choose_res_608;
                                                              }
                                                              choose_res_600 = choose_res_604;
                                                            }
                                                            choose_res_596 = choose_res_600;
                                                          }
                                                          choose_res_592 = choose_res_596;
                                                        }
                                                        choose_res_588 = choose_res_592;
                                                      }
                                                      choose_res_584 = choose_res_588;
                                                    }
                                                    choose_res_580 = choose_res_584;
                                                  }
                                                  choose_res_576 = choose_res_580;
                                                }
                                                choose_res_572 = choose_res_576;
                                              }
                                              choose_res_568 = choose_res_572;
                                            }
                                            choose_res_564 = choose_res_568;
                                          }
                                          choose_res_560 = choose_res_564;
                                        }
                                        choose_res_556 = choose_res_560;
                                      }
                                      choose_res_552 = choose_res_556;
                                    }
                                    choose_res_548 = choose_res_552;
                                  }
                                  choose_res_544 = choose_res_548;
                                }
                                choose_res_540 = choose_res_544;
                              }
                              choose_res_536 = choose_res_540;
                            }
                            choose_res_532 = choose_res_536;
                          }
                          choose_res_528 = choose_res_532;
                        }
                        choose_res_524 = choose_res_528;
                      }
                      choose_res_520 = choose_res_524;
                    }
                    choose_res_516 = choose_res_520;
                  }
                  choose_res_512 = choose_res_516;
                }
                choose_res_508 = choose_res_512;
              }
              choose_res_504 = choose_res_508;
            }
            choose_res_500 = choose_res_504;
          }
          choose_res_496 = choose_res_500;
        }
        choose_res_492 = choose_res_496;
      }
      let_res_489 = choose_res_492;
    }
    return let_res_489;
  }
   };
  return fun487;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_type::base> )> base_sersize_of_row_binary(base_sersize_of_row_binary_init());

/* 
    (fun ("(STRING; THIS)")
      (let "sz_297"
        (add
          (let "n_ref_295" (make-vec (string-length (get-item 0 (param 0))))
            (let "lebsz_ref_296" (make-vec (u32 1))
              (seq
                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_295")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_296")) (u8 7)))
                  (set-vec (u8 0) (identifier "lebsz_ref_296") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_296")) (u32 1)))) 
                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_296")))))) 
          (size-of-u32 (string-length (get-item 0 (param 0))))) (add (identifier "sz_297") (apply (identifier "sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_type::named_type> )> named_type_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_type::named_type> )> fun812 { [&fun812](std::shared_ptr<::dessser::gen::raql_type::named_type>  p_0) {
    std::string id_813 { std::get<0>((*p_0)) };
    uint32_t id_814 { (uint32_t)id_813.size() };
    Vec<1, uint32_t> id_815 {  id_814  };
    Size let_res_816;
    {
      Vec<1, uint32_t> n_ref_295 { id_815 };
      uint32_t id_817 { 1U };
      Vec<1, uint32_t> id_818 {  id_817  };
      Size let_res_819;
      {
        Vec<1, uint32_t> lebsz_ref_296 { id_818 };
        bool while_flag_820 { true };
        do {
          uint8_t id_821 { 0 };
          uint32_t id_822 { n_ref_295[id_821] };
          uint8_t id_823 { 0 };
          uint32_t id_824 { lebsz_ref_296[id_823] };
          uint8_t id_825 { 7 };
          uint32_t id_826 { uint32_t(id_824 << id_825) };
          bool id_827 { bool(id_822 >= id_826) };
          while_flag_820 = id_827;
          if (while_flag_820) {
            uint8_t id_828 { 0 };
            uint8_t id_829 { 0 };
            uint32_t id_830 { lebsz_ref_296[id_829] };
            uint32_t id_831 { 1U };
            uint32_t id_832 { uint32_t(id_830 + id_831) };
            Void id_833 { ((void)(lebsz_ref_296[id_828] = id_832), ::dessser::VOID) };
            (void)id_833;
          }
        } while (while_flag_820);
        (void)::dessser::VOID;
        uint8_t id_834 { 0 };
        uint32_t id_835 { lebsz_ref_296[id_834] };
        Size id_836 { Size(id_835) };
        let_res_819 = id_836;
      }
      let_res_816 = let_res_819;
    }
    std::string id_837 { std::get<0>((*p_0)) };
    uint32_t id_838 { (uint32_t)id_837.size() };
    Size id_839 { Size(id_838) };
    Size id_840 { Size(let_res_816 + id_839) };
    Size let_res_841;
    {
      Size sz_297 { id_840 };
      std::shared_ptr<::dessser::gen::raql_type::t>  id_842 { std::get<1>((*p_0)) };
      Size id_843 { sersize_of_row_binary(id_842) };
      Size id_844 { Size(sz_297 + id_843) };
      let_res_841 = id_844;
    }
    return let_res_841;
  }
   };
  return fun812;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_type::named_type> )> named_type_sersize_of_row_binary(named_type_sersize_of_row_binary_init());

/* 
    (fun ("{type: (base AS [Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]); nullable: BOOL}" "Ptr")
      (let "srec_dst_339" (apply (identifier "base-to-row-binary") (get-field "type" (param 0)) (param 1)) (write-u8 (identifier "srec_dst_339") (u8-of-bool (get-field "nullable" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t> ,Pointer)> fun845 { [&fun845](std::shared_ptr<::dessser::gen::raql_type::t>  p_0, Pointer p_1) {
    std::shared_ptr<::dessser::gen::raql_type::base>  id_846 { (*p_0).type };
    Pointer id_847 { base_to_row_binary(id_846, p_1) };
    Pointer let_res_848;
    {
      Pointer srec_dst_339 { id_847 };
      bool id_849 { (*p_0).nullable };
      uint8_t id_850 { uint8_t(id_849) };
      Pointer id_851 { srec_dst_339.writeU8(id_850) };
      let_res_848 = id_851;
    }
    return let_res_848;
  }
   };
  return fun845;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (named_type AS (STRING; THIS))[] | Sum named_type[] | Map (THIS; THIS)]" "Ptr")
      (let "label1_320" (label-of (param 0))
        (let "ssum_dst_321" (write-u16 little-endian (param 1) (identifier "label1_320"))
          (if (eq (u16 0) (identifier "label1_320")) (identifier "ssum_dst_321")
            (if (eq (u16 1) (identifier "label1_320")) (identifier "ssum_dst_321")
              (if (eq (u16 2) (identifier "label1_320")) (identifier "ssum_dst_321")
                (if (eq (u16 3) (identifier "label1_320")) (identifier "ssum_dst_321")
                  (if (eq (u16 4) (identifier "label1_320")) (identifier "ssum_dst_321")
                    (if (eq (u16 5) (identifier "label1_320")) (identifier "ssum_dst_321")
                      (if (eq (u16 6) (identifier "label1_320")) (identifier "ssum_dst_321")
                        (if (eq (u16 7) (identifier "label1_320")) (identifier "ssum_dst_321")
                          (if (eq (u16 8) (identifier "label1_320")) 
                            (identifier "ssum_dst_321")
                            (if (eq (u16 9) (identifier "label1_320")) 
                              (identifier "ssum_dst_321")
                              (if (eq (u16 10) (identifier "label1_320")) 
                                (identifier "ssum_dst_321")
                                (if (eq (u16 11) (identifier "label1_320")) 
                                  (identifier "ssum_dst_321")
                                  (if (eq (u16 12) (identifier "label1_320")) 
                                    (identifier "ssum_dst_321")
                                    (if (eq (u16 13) (identifier "label1_320")) 
                                      (identifier "ssum_dst_321")
                                      (if (eq (u16 14) (identifier "label1_320")) 
                                        (identifier "ssum_dst_321")
                                        (if (eq (u16 15) (identifier "label1_320")) 
                                          (identifier "ssum_dst_321")
                                          (if (eq (u16 16) (identifier "label1_320")) 
                                            (identifier "ssum_dst_321")
                                            (if (eq (u16 17) (identifier "label1_320")) 
                                              (identifier "ssum_dst_321")
                                              (if (eq (u16 18) (identifier "label1_320")) 
                                                (identifier "ssum_dst_321")
                                                (if (eq (u16 19) (identifier "label1_320")) 
                                                  (identifier "ssum_dst_321")
                                                  (if (eq (u16 20) (identifier "label1_320")) 
                                                    (identifier "ssum_dst_321")
                                                    (if (eq (u16 21) (identifier "label1_320")) 
                                                      (identifier "ssum_dst_321")
                                                      (if (eq (u16 22) (identifier "label1_320")) 
                                                        (identifier "ssum_dst_321")
                                                        (if (eq (u16 23) (identifier "label1_320")) 
                                                          (identifier "ssum_dst_321")
                                                          (if (eq (u16 24) (identifier "label1_320")) 
                                                            (identifier "ssum_dst_321")
                                                            (if (eq (u16 25) (identifier "label1_320")) 
                                                              (identifier "ssum_dst_321")
                                                              (if (eq (u16 26) (identifier "label1_320")) 
                                                                (identifier "ssum_dst_321")
                                                                (if (eq (u16 27) (identifier "label1_320")) 
                                                                  (identifier "ssum_dst_321")
                                                                  (if 
                                                                    (eq (u16 28) (identifier "label1_320")) 
                                                                    (identifier "ssum_dst_321")
                                                                    (if 
                                                                    (eq (u16 29) (identifier "label1_320")) 
                                                                    (identifier "ssum_dst_321")
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label1_320"))
                                                                    (let "dst_ref_336"
                                                                    (make-vec
                                                                    (let "leb128_sz_334" 
                                                                    (make-vec (cardinality (get-alt "Tup" (param 0))))
                                                                    (let "leb128_ptr_335" 
                                                                    (make-vec (identifier "ssum_dst_321"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_335")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_335"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_334"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_334"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_334"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_334") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_334")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_334")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_335"))))))
                                                                    (let "n_ref_337" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_338" 
                                                                    (get-alt "Tup" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_336") (apply (identifier "to-row-binary") (identifier "x_338") (unsafe-nth (u8 0) (identifier "dst_ref_336"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_337") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_337")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_336")))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label1_320"))
                                                                    (let "stup_dst_333" 
                                                                    (write-u32 little-endian (identifier "ssum_dst_321") (get-item 0 (get-alt "Vec" (param 0))))
                                                                    (apply (identifier "to-row-binary") (get-item 1 (get-alt "Vec" (param 0))) (identifier "stup_dst_333")))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label1_320")) 
                                                                    (apply (identifier "to-row-binary") (get-alt "Arr" (param 0)) (identifier "ssum_dst_321"))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label1_320"))
                                                                    (let "dst_ref_330"
                                                                    (make-vec
                                                                    (let "leb128_sz_328" 
                                                                    (make-vec (cardinality (get-alt "Rec" (param 0))))
                                                                    (let "leb128_ptr_329" 
                                                                    (make-vec (identifier "ssum_dst_321"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_329")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_329"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_328"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_328"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_328"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_328") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_328")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_328")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_329"))))))
                                                                    (let "n_ref_331" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_332" 
                                                                    (get-alt "Rec" (param 0))
                                                                    (seq
                                                                    (set-vec (u8 0) (identifier "dst_ref_330") (apply (identifier "named_type-to-row-binary") (identifier "x_332") (unsafe-nth (u8 0) (identifier "dst_ref_330"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_331") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_331")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_330")))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label1_320"))
                                                                    (let "dst_ref_325"
                                                                    (make-vec
                                                                    (let "leb128_sz_323" 
                                                                    (make-vec (cardinality (get-alt "Sum" (param 0))))
                                                                    (let "leb128_ptr_324" 
                                                                    (make-vec (identifier "ssum_dst_321"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_324")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_324"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_323"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_323"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_323"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_323") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_323")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_323")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_324"))))))
                                                                    (let "n_ref_326" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_327" 
                                                                    (get-alt "Sum" (param 0))
                                                                    (seq
                                                                    (set-vec (u8 0) (identifier "dst_ref_325") (apply (identifier "named_type-to-row-binary") (identifier "x_327") (unsafe-nth (u8 0) (identifier "dst_ref_325"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_326") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_326")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_325")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label1_320") (u16 35)))
                                                                    (let "stup_dst_322" 
                                                                    (apply (identifier "to-row-binary") (get-item 0 (get-alt "Map" (param 0))) (identifier "ssum_dst_321"))
                                                                    (apply (identifier "to-row-binary") (get-item 1 (get-alt "Map" (param 0))) (identifier "stup_dst_322"))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::base> ,Pointer)> base_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::base> ,Pointer)> fun852 { [&fun852](std::shared_ptr<::dessser::gen::raql_type::base>  p_0, Pointer p_1) {
    uint16_t id_853 { uint16_t((*p_0).index()) };
    Pointer let_res_854;
    {
      uint16_t label1_320 { id_853 };
      Pointer id_855 { p_1.writeU16Le(label1_320) };
      Pointer let_res_856;
      {
        Pointer ssum_dst_321 { id_855 };
        uint16_t id_857 { 0 };
        bool id_858 { bool(id_857 == label1_320) };
        Pointer choose_res_859;
        if (id_858) {
          choose_res_859 = ssum_dst_321;
        } else {
          uint16_t id_860 { 1 };
          bool id_861 { bool(id_860 == label1_320) };
          Pointer choose_res_862;
          if (id_861) {
            choose_res_862 = ssum_dst_321;
          } else {
            uint16_t id_863 { 2 };
            bool id_864 { bool(id_863 == label1_320) };
            Pointer choose_res_865;
            if (id_864) {
              choose_res_865 = ssum_dst_321;
            } else {
              uint16_t id_866 { 3 };
              bool id_867 { bool(id_866 == label1_320) };
              Pointer choose_res_868;
              if (id_867) {
                choose_res_868 = ssum_dst_321;
              } else {
                uint16_t id_869 { 4 };
                bool id_870 { bool(id_869 == label1_320) };
                Pointer choose_res_871;
                if (id_870) {
                  choose_res_871 = ssum_dst_321;
                } else {
                  uint16_t id_872 { 5 };
                  bool id_873 { bool(id_872 == label1_320) };
                  Pointer choose_res_874;
                  if (id_873) {
                    choose_res_874 = ssum_dst_321;
                  } else {
                    uint16_t id_875 { 6 };
                    bool id_876 { bool(id_875 == label1_320) };
                    Pointer choose_res_877;
                    if (id_876) {
                      choose_res_877 = ssum_dst_321;
                    } else {
                      uint16_t id_878 { 7 };
                      bool id_879 { bool(id_878 == label1_320) };
                      Pointer choose_res_880;
                      if (id_879) {
                        choose_res_880 = ssum_dst_321;
                      } else {
                        uint16_t id_881 { 8 };
                        bool id_882 { bool(id_881 == label1_320) };
                        Pointer choose_res_883;
                        if (id_882) {
                          choose_res_883 = ssum_dst_321;
                        } else {
                          uint16_t id_884 { 9 };
                          bool id_885 { bool(id_884 == label1_320) };
                          Pointer choose_res_886;
                          if (id_885) {
                            choose_res_886 = ssum_dst_321;
                          } else {
                            uint16_t id_887 { 10 };
                            bool id_888 { bool(id_887 == label1_320) };
                            Pointer choose_res_889;
                            if (id_888) {
                              choose_res_889 = ssum_dst_321;
                            } else {
                              uint16_t id_890 { 11 };
                              bool id_891 { bool(id_890 == label1_320) };
                              Pointer choose_res_892;
                              if (id_891) {
                                choose_res_892 = ssum_dst_321;
                              } else {
                                uint16_t id_893 { 12 };
                                bool id_894 { bool(id_893 == label1_320) };
                                Pointer choose_res_895;
                                if (id_894) {
                                  choose_res_895 = ssum_dst_321;
                                } else {
                                  uint16_t id_896 { 13 };
                                  bool id_897 { bool(id_896 == label1_320) };
                                  Pointer choose_res_898;
                                  if (id_897) {
                                    choose_res_898 = ssum_dst_321;
                                  } else {
                                    uint16_t id_899 { 14 };
                                    bool id_900 { bool(id_899 == label1_320) };
                                    Pointer choose_res_901;
                                    if (id_900) {
                                      choose_res_901 = ssum_dst_321;
                                    } else {
                                      uint16_t id_902 { 15 };
                                      bool id_903 { bool(id_902 == label1_320) };
                                      Pointer choose_res_904;
                                      if (id_903) {
                                        choose_res_904 = ssum_dst_321;
                                      } else {
                                        uint16_t id_905 { 16 };
                                        bool id_906 { bool(id_905 == label1_320) };
                                        Pointer choose_res_907;
                                        if (id_906) {
                                          choose_res_907 = ssum_dst_321;
                                        } else {
                                          uint16_t id_908 { 17 };
                                          bool id_909 { bool(id_908 == label1_320) };
                                          Pointer choose_res_910;
                                          if (id_909) {
                                            choose_res_910 = ssum_dst_321;
                                          } else {
                                            uint16_t id_911 { 18 };
                                            bool id_912 { bool(id_911 == label1_320) };
                                            Pointer choose_res_913;
                                            if (id_912) {
                                              choose_res_913 = ssum_dst_321;
                                            } else {
                                              uint16_t id_914 { 19 };
                                              bool id_915 { bool(id_914 == label1_320) };
                                              Pointer choose_res_916;
                                              if (id_915) {
                                                choose_res_916 = ssum_dst_321;
                                              } else {
                                                uint16_t id_917 { 20 };
                                                bool id_918 { bool(id_917 == label1_320) };
                                                Pointer choose_res_919;
                                                if (id_918) {
                                                  choose_res_919 = ssum_dst_321;
                                                } else {
                                                  uint16_t id_920 { 21 };
                                                  bool id_921 { bool(id_920 == label1_320) };
                                                  Pointer choose_res_922;
                                                  if (id_921) {
                                                    choose_res_922 = ssum_dst_321;
                                                  } else {
                                                    uint16_t id_923 { 22 };
                                                    bool id_924 { bool(id_923 == label1_320) };
                                                    Pointer choose_res_925;
                                                    if (id_924) {
                                                      choose_res_925 = ssum_dst_321;
                                                    } else {
                                                      uint16_t id_926 { 23 };
                                                      bool id_927 { bool(id_926 == label1_320) };
                                                      Pointer choose_res_928;
                                                      if (id_927) {
                                                        choose_res_928 = ssum_dst_321;
                                                      } else {
                                                        uint16_t id_929 { 24 };
                                                        bool id_930 { bool(id_929 == label1_320) };
                                                        Pointer choose_res_931;
                                                        if (id_930) {
                                                          choose_res_931 = ssum_dst_321;
                                                        } else {
                                                          uint16_t id_932 { 25 };
                                                          bool id_933 { bool(id_932 == label1_320) };
                                                          Pointer choose_res_934;
                                                          if (id_933) {
                                                            choose_res_934 = ssum_dst_321;
                                                          } else {
                                                            uint16_t id_935 { 26 };
                                                            bool id_936 { bool(id_935 == label1_320) };
                                                            Pointer choose_res_937;
                                                            if (id_936) {
                                                              choose_res_937 = ssum_dst_321;
                                                            } else {
                                                              uint16_t id_938 { 27 };
                                                              bool id_939 { bool(id_938 == label1_320) };
                                                              Pointer choose_res_940;
                                                              if (id_939) {
                                                                choose_res_940 = ssum_dst_321;
                                                              } else {
                                                                uint16_t id_941 { 28 };
                                                                bool id_942 { bool(id_941 == label1_320) };
                                                                Pointer choose_res_943;
                                                                if (id_942) {
                                                                  choose_res_943 = ssum_dst_321;
                                                                } else {
                                                                  uint16_t id_944 { 29 };
                                                                  bool id_945 { bool(id_944 == label1_320) };
                                                                  Pointer choose_res_946;
                                                                  if (id_945) {
                                                                    choose_res_946 = ssum_dst_321;
                                                                  } else {
                                                                    uint16_t id_947 { 30 };
                                                                    bool id_948 { bool(id_947 == label1_320) };
                                                                    Pointer choose_res_949;
                                                                    if (id_948) {
                                                                      Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_950 { std::get<30 /* Tup */>((*p_0)) };
                                                                      uint32_t id_951 { id_950.size() };
                                                                      Vec<1, uint32_t> id_952 {  id_951  };
                                                                      Pointer let_res_953;
                                                                      {
                                                                        Vec<1, uint32_t> leb128_sz_334 { id_952 };
                                                                        Vec<1, Pointer> id_954 {  ssum_dst_321  };
                                                                        Pointer let_res_955;
                                                                        {
                                                                          Vec<1, Pointer> leb128_ptr_335 { id_954 };
                                                                          bool while_flag_956 { true };
                                                                          do {
                                                                            uint8_t id_957 { 0 };
                                                                            uint8_t id_958 { 0 };
                                                                            Pointer id_959 { leb128_ptr_335[id_958] };
                                                                            uint32_t id_960 { 128U };
                                                                            uint8_t id_961 { 0 };
                                                                            uint32_t id_962 { leb128_sz_334[id_961] };
                                                                            bool id_963 { bool(id_960 > id_962) };
                                                                            uint8_t choose_res_964;
                                                                            if (id_963) {
                                                                              uint8_t id_965 { 0 };
                                                                              uint32_t id_966 { leb128_sz_334[id_965] };
                                                                              uint8_t id_967 { uint8_t(id_966) };
                                                                              choose_res_964 = id_967;
                                                                            } else {
                                                                              uint8_t id_968 { 0 };
                                                                              uint32_t id_969 { leb128_sz_334[id_968] };
                                                                              uint8_t id_970 { uint8_t(id_969) };
                                                                              uint8_t id_971 { 128 };
                                                                              uint8_t id_972 { uint8_t(id_970 | id_971) };
                                                                              choose_res_964 = id_972;
                                                                            }
                                                                            Pointer id_973 { id_959.writeU8(choose_res_964) };
                                                                            Void id_974 { ((void)(leb128_ptr_335[id_957] = id_973), ::dessser::VOID) };
                                                                            (void)id_974;
                                                                            uint8_t id_975 { 0 };
                                                                            uint8_t id_976 { 0 };
                                                                            uint32_t id_977 { leb128_sz_334[id_976] };
                                                                            uint8_t id_978 { 7 };
                                                                            uint32_t id_979 { uint32_t(id_977 >> id_978) };
                                                                            Void id_980 { ((void)(leb128_sz_334[id_975] = id_979), ::dessser::VOID) };
                                                                            (void)id_980;
                                                                            uint8_t id_981 { 0 };
                                                                            uint32_t id_982 { leb128_sz_334[id_981] };
                                                                            uint32_t id_983 { 0U };
                                                                            bool id_984 { bool(id_982 > id_983) };
                                                                            while_flag_956 = id_984;
                                                                            if (while_flag_956) {
                                                                              (void)::dessser::VOID;
                                                                            }
                                                                          } while (while_flag_956);
                                                                          (void)::dessser::VOID;
                                                                          uint8_t id_985 { 0 };
                                                                          Pointer id_986 { leb128_ptr_335[id_985] };
                                                                          let_res_955 = id_986;
                                                                        }
                                                                        let_res_953 = let_res_955;
                                                                      }
                                                                      Vec<1, Pointer> id_987 {  let_res_953  };
                                                                      Pointer let_res_988;
                                                                      {
                                                                        Vec<1, Pointer> dst_ref_336 { id_987 };
                                                                        int32_t id_989 { 0L };
                                                                        Vec<1, int32_t> id_990 {  id_989  };
                                                                        Pointer let_res_991;
                                                                        {
                                                                          Vec<1, int32_t> n_ref_337 { id_990 };
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_992 { std::get<30 /* Tup */>((*p_0)) };
                                                                          for (std::shared_ptr<::dessser::gen::raql_type::t>  x_338 : id_992) {
                                                                            uint8_t id_993 { 0 };
                                                                            uint8_t id_994 { 0 };
                                                                            Pointer id_995 { dst_ref_336[id_994] };
                                                                            Pointer id_996 { to_row_binary(x_338, id_995) };
                                                                            Void id_997 { ((void)(dst_ref_336[id_993] = id_996), ::dessser::VOID) };
                                                                            (void)id_997;
                                                                            uint8_t id_998 { 0 };
                                                                            int32_t id_999 { 1L };
                                                                            uint8_t id_1000 { 0 };
                                                                            int32_t id_1001 { n_ref_337[id_1000] };
                                                                            int32_t id_1002 { int32_t(id_999 + id_1001) };
                                                                            Void id_1003 { ((void)(n_ref_337[id_998] = id_1002), ::dessser::VOID) };
                                                                            (void)id_1003;
                                                                            (void)id_1003;
                                                                          }
                                                                          (void)::dessser::VOID;
                                                                          uint8_t id_1004 { 0 };
                                                                          Pointer id_1005 { dst_ref_336[id_1004] };
                                                                          let_res_991 = id_1005;
                                                                        }
                                                                        let_res_988 = let_res_991;
                                                                      }
                                                                      choose_res_949 = let_res_988;
                                                                    } else {
                                                                      uint16_t id_1006 { 31 };
                                                                      bool id_1007 { bool(id_1006 == label1_320) };
                                                                      Pointer choose_res_1008;
                                                                      if (id_1007) {
                                                                        ::dessser::gen::raql_type::tb65a12146ab462f3a71f0a2c9184c7a4 id_1009 { std::get<31 /* Vec */>((*p_0)) };
                                                                        uint32_t id_1010 { std::get<0>(id_1009) };
                                                                        Pointer id_1011 { ssum_dst_321.writeU32Le(id_1010) };
                                                                        Pointer let_res_1012;
                                                                        {
                                                                          Pointer stup_dst_333 { id_1011 };
                                                                          ::dessser::gen::raql_type::tb65a12146ab462f3a71f0a2c9184c7a4 id_1013 { std::get<31 /* Vec */>((*p_0)) };
                                                                          std::shared_ptr<::dessser::gen::raql_type::t>  id_1014 { std::get<1>(id_1013) };
                                                                          Pointer id_1015 { to_row_binary(id_1014, stup_dst_333) };
                                                                          let_res_1012 = id_1015;
                                                                        }
                                                                        choose_res_1008 = let_res_1012;
                                                                      } else {
                                                                        uint16_t id_1016 { 32 };
                                                                        bool id_1017 { bool(id_1016 == label1_320) };
                                                                        Pointer choose_res_1018;
                                                                        if (id_1017) {
                                                                          std::shared_ptr<::dessser::gen::raql_type::t>  id_1019 { std::get<32 /* Arr */>((*p_0)) };
                                                                          Pointer id_1020 { to_row_binary(id_1019, ssum_dst_321) };
                                                                          choose_res_1018 = id_1020;
                                                                        } else {
                                                                          uint16_t id_1021 { 33 };
                                                                          bool id_1022 { bool(id_1021 == label1_320) };
                                                                          Pointer choose_res_1023;
                                                                          if (id_1022) {
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_1024 { std::get<33 /* Rec */>((*p_0)) };
                                                                            uint32_t id_1025 { id_1024.size() };
                                                                            Vec<1, uint32_t> id_1026 {  id_1025  };
                                                                            Pointer let_res_1027;
                                                                            {
                                                                              Vec<1, uint32_t> leb128_sz_328 { id_1026 };
                                                                              Vec<1, Pointer> id_1028 {  ssum_dst_321  };
                                                                              Pointer let_res_1029;
                                                                              {
                                                                                Vec<1, Pointer> leb128_ptr_329 { id_1028 };
                                                                                bool while_flag_1030 { true };
                                                                                do {
                                                                                  uint8_t id_1031 { 0 };
                                                                                  uint8_t id_1032 { 0 };
                                                                                  Pointer id_1033 { leb128_ptr_329[id_1032] };
                                                                                  uint32_t id_1034 { 128U };
                                                                                  uint8_t id_1035 { 0 };
                                                                                  uint32_t id_1036 { leb128_sz_328[id_1035] };
                                                                                  bool id_1037 { bool(id_1034 > id_1036) };
                                                                                  uint8_t choose_res_1038;
                                                                                  if (id_1037) {
                                                                                    uint8_t id_1039 { 0 };
                                                                                    uint32_t id_1040 { leb128_sz_328[id_1039] };
                                                                                    uint8_t id_1041 { uint8_t(id_1040) };
                                                                                    choose_res_1038 = id_1041;
                                                                                  } else {
                                                                                    uint8_t id_1042 { 0 };
                                                                                    uint32_t id_1043 { leb128_sz_328[id_1042] };
                                                                                    uint8_t id_1044 { uint8_t(id_1043) };
                                                                                    uint8_t id_1045 { 128 };
                                                                                    uint8_t id_1046 { uint8_t(id_1044 | id_1045) };
                                                                                    choose_res_1038 = id_1046;
                                                                                  }
                                                                                  Pointer id_1047 { id_1033.writeU8(choose_res_1038) };
                                                                                  Void id_1048 { ((void)(leb128_ptr_329[id_1031] = id_1047), ::dessser::VOID) };
                                                                                  (void)id_1048;
                                                                                  uint8_t id_1049 { 0 };
                                                                                  uint8_t id_1050 { 0 };
                                                                                  uint32_t id_1051 { leb128_sz_328[id_1050] };
                                                                                  uint8_t id_1052 { 7 };
                                                                                  uint32_t id_1053 { uint32_t(id_1051 >> id_1052) };
                                                                                  Void id_1054 { ((void)(leb128_sz_328[id_1049] = id_1053), ::dessser::VOID) };
                                                                                  (void)id_1054;
                                                                                  uint8_t id_1055 { 0 };
                                                                                  uint32_t id_1056 { leb128_sz_328[id_1055] };
                                                                                  uint32_t id_1057 { 0U };
                                                                                  bool id_1058 { bool(id_1056 > id_1057) };
                                                                                  while_flag_1030 = id_1058;
                                                                                  if (while_flag_1030) {
                                                                                    (void)::dessser::VOID;
                                                                                  }
                                                                                } while (while_flag_1030);
                                                                                (void)::dessser::VOID;
                                                                                uint8_t id_1059 { 0 };
                                                                                Pointer id_1060 { leb128_ptr_329[id_1059] };
                                                                                let_res_1029 = id_1060;
                                                                              }
                                                                              let_res_1027 = let_res_1029;
                                                                            }
                                                                            Vec<1, Pointer> id_1061 {  let_res_1027  };
                                                                            Pointer let_res_1062;
                                                                            {
                                                                              Vec<1, Pointer> dst_ref_330 { id_1061 };
                                                                              int32_t id_1063 { 0L };
                                                                              Vec<1, int32_t> id_1064 {  id_1063  };
                                                                              Pointer let_res_1065;
                                                                              {
                                                                                Vec<1, int32_t> n_ref_331 { id_1064 };
                                                                                Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_1066 { std::get<33 /* Rec */>((*p_0)) };
                                                                                for (std::shared_ptr<::dessser::gen::raql_type::named_type>  x_332 : id_1066) {
                                                                                  uint8_t id_1067 { 0 };
                                                                                  uint8_t id_1068 { 0 };
                                                                                  Pointer id_1069 { dst_ref_330[id_1068] };
                                                                                  Pointer id_1070 { named_type_to_row_binary(x_332, id_1069) };
                                                                                  Void id_1071 { ((void)(dst_ref_330[id_1067] = id_1070), ::dessser::VOID) };
                                                                                  (void)id_1071;
                                                                                  uint8_t id_1072 { 0 };
                                                                                  int32_t id_1073 { 1L };
                                                                                  uint8_t id_1074 { 0 };
                                                                                  int32_t id_1075 { n_ref_331[id_1074] };
                                                                                  int32_t id_1076 { int32_t(id_1073 + id_1075) };
                                                                                  Void id_1077 { ((void)(n_ref_331[id_1072] = id_1076), ::dessser::VOID) };
                                                                                  (void)id_1077;
                                                                                  (void)id_1077;
                                                                                }
                                                                                (void)::dessser::VOID;
                                                                                uint8_t id_1078 { 0 };
                                                                                Pointer id_1079 { dst_ref_330[id_1078] };
                                                                                let_res_1065 = id_1079;
                                                                              }
                                                                              let_res_1062 = let_res_1065;
                                                                            }
                                                                            choose_res_1023 = let_res_1062;
                                                                          } else {
                                                                            uint16_t id_1080 { 34 };
                                                                            bool id_1081 { bool(id_1080 == label1_320) };
                                                                            Pointer choose_res_1082;
                                                                            if (id_1081) {
                                                                              Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_1083 { std::get<34 /* Sum */>((*p_0)) };
                                                                              uint32_t id_1084 { id_1083.size() };
                                                                              Vec<1, uint32_t> id_1085 {  id_1084  };
                                                                              Pointer let_res_1086;
                                                                              {
                                                                                Vec<1, uint32_t> leb128_sz_323 { id_1085 };
                                                                                Vec<1, Pointer> id_1087 {  ssum_dst_321  };
                                                                                Pointer let_res_1088;
                                                                                {
                                                                                  Vec<1, Pointer> leb128_ptr_324 { id_1087 };
                                                                                  bool while_flag_1089 { true };
                                                                                  do {
                                                                                    uint8_t id_1090 { 0 };
                                                                                    uint8_t id_1091 { 0 };
                                                                                    Pointer id_1092 { leb128_ptr_324[id_1091] };
                                                                                    uint32_t id_1093 { 128U };
                                                                                    uint8_t id_1094 { 0 };
                                                                                    uint32_t id_1095 { leb128_sz_323[id_1094] };
                                                                                    bool id_1096 { bool(id_1093 > id_1095) };
                                                                                    uint8_t choose_res_1097;
                                                                                    if (id_1096) {
                                                                                      uint8_t id_1098 { 0 };
                                                                                      uint32_t id_1099 { leb128_sz_323[id_1098] };
                                                                                      uint8_t id_1100 { uint8_t(id_1099) };
                                                                                      choose_res_1097 = id_1100;
                                                                                    } else {
                                                                                      uint8_t id_1101 { 0 };
                                                                                      uint32_t id_1102 { leb128_sz_323[id_1101] };
                                                                                      uint8_t id_1103 { uint8_t(id_1102) };
                                                                                      uint8_t id_1104 { 128 };
                                                                                      uint8_t id_1105 { uint8_t(id_1103 | id_1104) };
                                                                                      choose_res_1097 = id_1105;
                                                                                    }
                                                                                    Pointer id_1106 { id_1092.writeU8(choose_res_1097) };
                                                                                    Void id_1107 { ((void)(leb128_ptr_324[id_1090] = id_1106), ::dessser::VOID) };
                                                                                    (void)id_1107;
                                                                                    uint8_t id_1108 { 0 };
                                                                                    uint8_t id_1109 { 0 };
                                                                                    uint32_t id_1110 { leb128_sz_323[id_1109] };
                                                                                    uint8_t id_1111 { 7 };
                                                                                    uint32_t id_1112 { uint32_t(id_1110 >> id_1111) };
                                                                                    Void id_1113 { ((void)(leb128_sz_323[id_1108] = id_1112), ::dessser::VOID) };
                                                                                    (void)id_1113;
                                                                                    uint8_t id_1114 { 0 };
                                                                                    uint32_t id_1115 { leb128_sz_323[id_1114] };
                                                                                    uint32_t id_1116 { 0U };
                                                                                    bool id_1117 { bool(id_1115 > id_1116) };
                                                                                    while_flag_1089 = id_1117;
                                                                                    if (while_flag_1089) {
                                                                                      (void)::dessser::VOID;
                                                                                    }
                                                                                  } while (while_flag_1089);
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_1118 { 0 };
                                                                                  Pointer id_1119 { leb128_ptr_324[id_1118] };
                                                                                  let_res_1088 = id_1119;
                                                                                }
                                                                                let_res_1086 = let_res_1088;
                                                                              }
                                                                              Vec<1, Pointer> id_1120 {  let_res_1086  };
                                                                              Pointer let_res_1121;
                                                                              {
                                                                                Vec<1, Pointer> dst_ref_325 { id_1120 };
                                                                                int32_t id_1122 { 0L };
                                                                                Vec<1, int32_t> id_1123 {  id_1122  };
                                                                                Pointer let_res_1124;
                                                                                {
                                                                                  Vec<1, int32_t> n_ref_326 { id_1123 };
                                                                                  Arr<std::shared_ptr<::dessser::gen::raql_type::named_type> > id_1125 { std::get<34 /* Sum */>((*p_0)) };
                                                                                  for (std::shared_ptr<::dessser::gen::raql_type::named_type>  x_327 : id_1125) {
                                                                                    uint8_t id_1126 { 0 };
                                                                                    uint8_t id_1127 { 0 };
                                                                                    Pointer id_1128 { dst_ref_325[id_1127] };
                                                                                    Pointer id_1129 { named_type_to_row_binary(x_327, id_1128) };
                                                                                    Void id_1130 { ((void)(dst_ref_325[id_1126] = id_1129), ::dessser::VOID) };
                                                                                    (void)id_1130;
                                                                                    uint8_t id_1131 { 0 };
                                                                                    int32_t id_1132 { 1L };
                                                                                    uint8_t id_1133 { 0 };
                                                                                    int32_t id_1134 { n_ref_326[id_1133] };
                                                                                    int32_t id_1135 { int32_t(id_1132 + id_1134) };
                                                                                    Void id_1136 { ((void)(n_ref_326[id_1131] = id_1135), ::dessser::VOID) };
                                                                                    (void)id_1136;
                                                                                    (void)id_1136;
                                                                                  }
                                                                                  (void)::dessser::VOID;
                                                                                  uint8_t id_1137 { 0 };
                                                                                  Pointer id_1138 { dst_ref_325[id_1137] };
                                                                                  let_res_1124 = id_1138;
                                                                                }
                                                                                let_res_1121 = let_res_1124;
                                                                              }
                                                                              choose_res_1082 = let_res_1121;
                                                                            } else {
                                                                              uint16_t id_1139 { 35 };
                                                                              bool id_1140 { bool(label1_320 == id_1139) };
                                                                              Void id_1141 { ((void)(assert(id_1140)), ::dessser::VOID) };
                                                                              (void)id_1141;
                                                                              ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d id_1142 { std::get<35 /* Map */>((*p_0)) };
                                                                              std::shared_ptr<::dessser::gen::raql_type::t>  id_1143 { std::get<0>(id_1142) };
                                                                              Pointer id_1144 { to_row_binary(id_1143, ssum_dst_321) };
                                                                              Pointer let_res_1145;
                                                                              {
                                                                                Pointer stup_dst_322 { id_1144 };
                                                                                ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d id_1146 { std::get<35 /* Map */>((*p_0)) };
                                                                                std::shared_ptr<::dessser::gen::raql_type::t>  id_1147 { std::get<1>(id_1146) };
                                                                                Pointer id_1148 { to_row_binary(id_1147, stup_dst_322) };
                                                                                let_res_1145 = id_1148;
                                                                              }
                                                                              choose_res_1082 = let_res_1145;
                                                                            }
                                                                            choose_res_1023 = choose_res_1082;
                                                                          }
                                                                          choose_res_1018 = choose_res_1023;
                                                                        }
                                                                        choose_res_1008 = choose_res_1018;
                                                                      }
                                                                      choose_res_949 = choose_res_1008;
                                                                    }
                                                                    choose_res_946 = choose_res_949;
                                                                  }
                                                                  choose_res_943 = choose_res_946;
                                                                }
                                                                choose_res_940 = choose_res_943;
                                                              }
                                                              choose_res_937 = choose_res_940;
                                                            }
                                                            choose_res_934 = choose_res_937;
                                                          }
                                                          choose_res_931 = choose_res_934;
                                                        }
                                                        choose_res_928 = choose_res_931;
                                                      }
                                                      choose_res_925 = choose_res_928;
                                                    }
                                                    choose_res_922 = choose_res_925;
                                                  }
                                                  choose_res_919 = choose_res_922;
                                                }
                                                choose_res_916 = choose_res_919;
                                              }
                                              choose_res_913 = choose_res_916;
                                            }
                                            choose_res_910 = choose_res_913;
                                          }
                                          choose_res_907 = choose_res_910;
                                        }
                                        choose_res_904 = choose_res_907;
                                      }
                                      choose_res_901 = choose_res_904;
                                    }
                                    choose_res_898 = choose_res_901;
                                  }
                                  choose_res_895 = choose_res_898;
                                }
                                choose_res_892 = choose_res_895;
                              }
                              choose_res_889 = choose_res_892;
                            }
                            choose_res_886 = choose_res_889;
                          }
                          choose_res_883 = choose_res_886;
                        }
                        choose_res_880 = choose_res_883;
                      }
                      choose_res_877 = choose_res_880;
                    }
                    choose_res_874 = choose_res_877;
                  }
                  choose_res_871 = choose_res_874;
                }
                choose_res_868 = choose_res_871;
              }
              choose_res_865 = choose_res_868;
            }
            choose_res_862 = choose_res_865;
          }
          choose_res_859 = choose_res_862;
        }
        let_res_856 = choose_res_859;
      }
      let_res_854 = let_res_856;
    }
    return let_res_854;
  }
   };
  return fun852;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::base> ,Pointer)> base_to_row_binary(base_to_row_binary_init());

/* 
    (fun ("(STRING; THIS)" "Ptr")
      (let "stup_dst_319"
        (write-bytes
          (let "leb128_sz_317" (make-vec (string-length (get-item 0 (param 0))))
            (let "leb128_ptr_318" (make-vec (param 1))
              (seq
                (while
                  (seq
                    (set-vec (u8 0) (identifier "leb128_ptr_318")
                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_318"))
                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_317"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_317"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_317"))) (u8 128)))))
                    (set-vec (u8 0) (identifier "leb128_sz_317") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_317")) (u8 7))) 
                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_317")) (u32 0))) 
                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_318"))))) 
          (bytes-of-string (get-item 0 (param 0)))) (apply (identifier "to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_319"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::named_type> ,Pointer)> named_type_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::named_type> ,Pointer)> fun1149 { [&fun1149](std::shared_ptr<::dessser::gen::raql_type::named_type>  p_0, Pointer p_1) {
    std::string id_1150 { std::get<0>((*p_0)) };
    uint32_t id_1151 { (uint32_t)id_1150.size() };
    Vec<1, uint32_t> id_1152 {  id_1151  };
    Pointer let_res_1153;
    {
      Vec<1, uint32_t> leb128_sz_317 { id_1152 };
      Vec<1, Pointer> id_1154 {  p_1  };
      Pointer let_res_1155;
      {
        Vec<1, Pointer> leb128_ptr_318 { id_1154 };
        bool while_flag_1156 { true };
        do {
          uint8_t id_1157 { 0 };
          uint8_t id_1158 { 0 };
          Pointer id_1159 { leb128_ptr_318[id_1158] };
          uint32_t id_1160 { 128U };
          uint8_t id_1161 { 0 };
          uint32_t id_1162 { leb128_sz_317[id_1161] };
          bool id_1163 { bool(id_1160 > id_1162) };
          uint8_t choose_res_1164;
          if (id_1163) {
            uint8_t id_1165 { 0 };
            uint32_t id_1166 { leb128_sz_317[id_1165] };
            uint8_t id_1167 { uint8_t(id_1166) };
            choose_res_1164 = id_1167;
          } else {
            uint8_t id_1168 { 0 };
            uint32_t id_1169 { leb128_sz_317[id_1168] };
            uint8_t id_1170 { uint8_t(id_1169) };
            uint8_t id_1171 { 128 };
            uint8_t id_1172 { uint8_t(id_1170 | id_1171) };
            choose_res_1164 = id_1172;
          }
          Pointer id_1173 { id_1159.writeU8(choose_res_1164) };
          Void id_1174 { ((void)(leb128_ptr_318[id_1157] = id_1173), ::dessser::VOID) };
          (void)id_1174;
          uint8_t id_1175 { 0 };
          uint8_t id_1176 { 0 };
          uint32_t id_1177 { leb128_sz_317[id_1176] };
          uint8_t id_1178 { 7 };
          uint32_t id_1179 { uint32_t(id_1177 >> id_1178) };
          Void id_1180 { ((void)(leb128_sz_317[id_1175] = id_1179), ::dessser::VOID) };
          (void)id_1180;
          uint8_t id_1181 { 0 };
          uint32_t id_1182 { leb128_sz_317[id_1181] };
          uint32_t id_1183 { 0U };
          bool id_1184 { bool(id_1182 > id_1183) };
          while_flag_1156 = id_1184;
          if (while_flag_1156) {
            (void)::dessser::VOID;
          }
        } while (while_flag_1156);
        (void)::dessser::VOID;
        uint8_t id_1185 { 0 };
        Pointer id_1186 { leb128_ptr_318[id_1185] };
        let_res_1155 = id_1186;
      }
      let_res_1153 = let_res_1155;
    }
    std::string id_1187 { std::get<0>((*p_0)) };
    Bytes id_1188 { id_1187 };
    Pointer id_1189 { let_res_1153.writeBytes(id_1188) };
    Pointer let_res_1190;
    {
      Pointer stup_dst_319 { id_1189 };
      std::shared_ptr<::dessser::gen::raql_type::t>  id_1191 { std::get<1>((*p_0)) };
      Pointer id_1192 { to_row_binary(id_1191, stup_dst_319) };
      let_res_1190 = id_1192;
    }
    return let_res_1190;
  }
   };
  return fun1149;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::named_type> ,Pointer)> named_type_to_row_binary(named_type_to_row_binary_init());


}
