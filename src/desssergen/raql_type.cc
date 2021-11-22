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
struct t322be039d4e703202ccedfc1a13e4f5d : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::raql_type::t> 
> {
  using tuple::tuple;
  t322be039d4e703202ccedfc1a13e4f5d(std::tuple<std::string, std::shared_ptr<::dessser::gen::raql_type::t> > p)
    : std::tuple<std::string, std::shared_ptr<::dessser::gen::raql_type::t> >(std::get<0>(p), std::get<1>(p)) {}
};
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
  Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d>, // Rec
  Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d>, // Sum
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
struct te49cc3648a3044f2cc62b07857df3a6f : public std::tuple<
  Lst<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d>,
  Pointer
> {
  using tuple::tuple;
  te49cc3648a3044f2cc62b07857df3a6f(std::tuple<Lst<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d>, Pointer> p)
    : std::tuple<Lst<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
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
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t> )> sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Size(std::shared_ptr<::dessser::gen::raql_type::base> )> base_sersize_of_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t> ,Pointer)> to_row_binary;
struct t;
inline std::ostream &operator<<(std::ostream &, struct t const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct t> const);
inline bool operator==(struct t const &, struct t const &);
inline bool operator!=(struct t const &, struct t const &);
extern std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::base> ,Pointer)> base_to_row_binary;
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("Ptr")
      (let "drec_296" (apply (identifier "base-of-row-binary") (param 0))
        (let-pair "drec_fst_297" "drec_snd_298" (identifier "drec_296")
          (let-pair "dbool_fst_300" "dbool_snd_301" (read-u8 (identifier "drec_snd_298"))
            (make-tup (make-rec (string "nullable") (not (eq (identifier "dbool_fst_300") (u8 0))) (string "type") (identifier "drec_fst_297")) (identifier "dbool_snd_301"))))))
 */
static std::function<::dessser::gen::raql_type::tf2625240b3c32734b297669569815110(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_type::tf2625240b3c32734b297669569815110(Pointer)> fun0 { [&fun0](Pointer p_0) {
    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_1 { base_of_row_binary(p_0) };
    ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 let_res_2;
    {
      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 drec_296 { id_1 };
      ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 letpair_res_3;
      {
        auto drec_fst_297 { std::get<0>(drec_296) };
        auto drec_snd_298 { std::get<1>(drec_296) };
        ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_4 { drec_snd_298.readU8() };
        ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 letpair_res_5;
        {
          auto dbool_fst_300 { std::get<0>(id_4) };
          auto dbool_snd_301 { std::get<1>(id_4) };
          uint8_t id_6 { 0 };
          bool id_7 { bool(dbool_fst_300 == id_6) };
          bool id_8 { ! id_7 };
          std::shared_ptr<::dessser::gen::raql_type::t>  id_9 { std::make_shared<::dessser::gen::raql_type::t>(id_8, drec_fst_297) };
          ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_10 { id_9, dbool_snd_301 };
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
      (let-pair "make_fst_294" "make_snd_295"
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
                                                                    (apply (identifier "of-row-binary") (identifier "dlist2_snd_193"))
                                                                    (make-tup (cons (identifier "dlist3_fst_195") (identifier "dlist2_fst_192")) (identifier "dlist3_snd_196"))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_190") (add (unsafe-nth (u8 0) (identifier "repeat_n_190")) (i32 1))))))
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_189"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 30
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_198"))) 
                                                                    (identifier "dlist4_snd_199")))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "dsum1_fst_63"))
                                                                    (let "dtup_168"
                                                                    (let-pair "du32_fst_166" "du32_snd_167" (read-u32 little-endian (identifier "dsum1_snd_64")) (make-tup (identifier "du32_fst_166") (identifier "du32_snd_167")))
                                                                    (let-pair "dtup_fst_169" "dtup_snd_170" 
                                                                    (identifier "dtup_168")
                                                                    (let-pair "dtup_fst_172" "dtup_snd_173" 
                                                                    (apply (identifier "of-row-binary") (identifier "dtup_snd_170"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 31
                                                                    (make-tup (identifier "dtup_fst_169") (identifier "dtup_fst_172"))) 
                                                                    (identifier "dtup_snd_173")))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "dsum1_fst_63"))
                                                                    (let-pair "dsum2_fst_163" "dsum2_snd_164" 
                                                                    (apply (identifier "of-row-binary") (identifier "dsum1_snd_64"))
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
                                                                    (let "dtup_147"
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
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_145")) (identifier "dstring2_snd_146")))))
                                                                    (let-pair "dtup_fst_148" "dtup_snd_149" 
                                                                    (identifier "dtup_147")
                                                                    (let-pair "dtup_fst_151" "dtup_snd_152" 
                                                                    (apply (identifier "of-row-binary") (identifier "dtup_snd_149"))
                                                                    (make-tup (cons (make-tup (identifier "dtup_fst_148") (identifier "dtup_fst_151")) (identifier "dlist2_fst_133")) (identifier "dtup_snd_152"))))))))
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
                                                                    (let "dtup_103"
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
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_101")) (identifier "dstring2_snd_102")))))
                                                                    (let-pair "dtup_fst_104" "dtup_snd_105" 
                                                                    (identifier "dtup_103")
                                                                    (let-pair "dtup_fst_107" "dtup_snd_108" 
                                                                    (apply (identifier "of-row-binary") (identifier "dtup_snd_105"))
                                                                    (make-tup (cons (make-tup (identifier "dtup_fst_104") (identifier "dtup_fst_107")) (identifier "dlist2_fst_89")) (identifier "dtup_snd_108"))))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_87") (add (unsafe-nth (u8 0) (identifier "repeat_n_87")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "inits_src_ref_86"))))))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 34
                                                                    (arr-of-lst-rev (identifier "dlist4_fst_113"))) 
                                                                    (identifier "dlist4_snd_114")))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_63") (u16 35)))
                                                                    (let "dtup_65" 
                                                                    (apply (identifier "of-row-binary") (identifier "dsum1_snd_64"))
                                                                    (let-pair "dtup_fst_66" "dtup_snd_67" 
                                                                    (identifier "dtup_65")
                                                                    (let-pair "dtup_fst_69" "dtup_snd_70" 
                                                                    (apply (identifier "of-row-binary") (identifier "dtup_snd_67"))
                                                                    (make-tup
                                                                    (construct "[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" 35
                                                                    (make-tup (identifier "dtup_fst_66") (identifier "dtup_fst_69"))) 
                                                                    (identifier "dtup_snd_70"))))))))))))))))))))))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_294") (identifier "make_snd_295"))))
 */
static std::function<::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0(Pointer)> base_of_row_binary_init()
{
  std::function<::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0(Pointer)> fun11 { [&fun11](Pointer p_0) {
    ::dessser::gen::raql_type::t7609d344c1ba69d0f80fec236d4c216b id_12 { p_0.readU16Le() };
    ::dessser::gen::raql_type::t7609d344c1ba69d0f80fec236d4c216b letpair_res_13;
    {
      auto du16_fst_57 { std::get<0>(id_12) };
      auto du16_snd_58 { std::get<1>(id_12) };
      ::dessser::gen::raql_type::t7609d344c1ba69d0f80fec236d4c216b id_14 { du16_fst_57, du16_snd_58 };
      letpair_res_13 = id_14;
    }
    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 let_res_15;
    {
      ::dessser::gen::raql_type::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_13 };
      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_16;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_17 { 0 };
        bool id_18 { bool(id_17 == dsum1_fst_63) };
        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_19;
        if (id_18) {
          (void)VOID;
          std::shared_ptr<::dessser::gen::raql_type::base>  id_20 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<0>, VOID) };
          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_21 { id_20, dsum1_snd_64 };
          choose_res_19 = id_21;
        } else {
          uint16_t id_22 { 1 };
          bool id_23 { bool(id_22 == dsum1_fst_63) };
          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_24;
          if (id_23) {
            (void)VOID;
            std::shared_ptr<::dessser::gen::raql_type::base>  id_25 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<1>, VOID) };
            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_26 { id_25, dsum1_snd_64 };
            choose_res_24 = id_26;
          } else {
            uint16_t id_27 { 2 };
            bool id_28 { bool(id_27 == dsum1_fst_63) };
            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_29;
            if (id_28) {
              (void)VOID;
              std::shared_ptr<::dessser::gen::raql_type::base>  id_30 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<2>, VOID) };
              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_31 { id_30, dsum1_snd_64 };
              choose_res_29 = id_31;
            } else {
              uint16_t id_32 { 3 };
              bool id_33 { bool(id_32 == dsum1_fst_63) };
              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_34;
              if (id_33) {
                (void)VOID;
                std::shared_ptr<::dessser::gen::raql_type::base>  id_35 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<3>, VOID) };
                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_36 { id_35, dsum1_snd_64 };
                choose_res_34 = id_36;
              } else {
                uint16_t id_37 { 4 };
                bool id_38 { bool(id_37 == dsum1_fst_63) };
                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_39;
                if (id_38) {
                  (void)VOID;
                  std::shared_ptr<::dessser::gen::raql_type::base>  id_40 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<4>, VOID) };
                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_41 { id_40, dsum1_snd_64 };
                  choose_res_39 = id_41;
                } else {
                  uint16_t id_42 { 5 };
                  bool id_43 { bool(id_42 == dsum1_fst_63) };
                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_44;
                  if (id_43) {
                    (void)VOID;
                    std::shared_ptr<::dessser::gen::raql_type::base>  id_45 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<5>, VOID) };
                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_46 { id_45, dsum1_snd_64 };
                    choose_res_44 = id_46;
                  } else {
                    uint16_t id_47 { 6 };
                    bool id_48 { bool(id_47 == dsum1_fst_63) };
                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_49;
                    if (id_48) {
                      (void)VOID;
                      std::shared_ptr<::dessser::gen::raql_type::base>  id_50 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<6>, VOID) };
                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_51 { id_50, dsum1_snd_64 };
                      choose_res_49 = id_51;
                    } else {
                      uint16_t id_52 { 7 };
                      bool id_53 { bool(id_52 == dsum1_fst_63) };
                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_54;
                      if (id_53) {
                        (void)VOID;
                        std::shared_ptr<::dessser::gen::raql_type::base>  id_55 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<7>, VOID) };
                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_56 { id_55, dsum1_snd_64 };
                        choose_res_54 = id_56;
                      } else {
                        uint16_t id_57 { 8 };
                        bool id_58 { bool(id_57 == dsum1_fst_63) };
                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_59;
                        if (id_58) {
                          (void)VOID;
                          std::shared_ptr<::dessser::gen::raql_type::base>  id_60 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<8>, VOID) };
                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_61 { id_60, dsum1_snd_64 };
                          choose_res_59 = id_61;
                        } else {
                          uint16_t id_62 { 9 };
                          bool id_63 { bool(id_62 == dsum1_fst_63) };
                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_64;
                          if (id_63) {
                            (void)VOID;
                            std::shared_ptr<::dessser::gen::raql_type::base>  id_65 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<9>, VOID) };
                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_66 { id_65, dsum1_snd_64 };
                            choose_res_64 = id_66;
                          } else {
                            uint16_t id_67 { 10 };
                            bool id_68 { bool(id_67 == dsum1_fst_63) };
                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_69;
                            if (id_68) {
                              (void)VOID;
                              std::shared_ptr<::dessser::gen::raql_type::base>  id_70 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<10>, VOID) };
                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_71 { id_70, dsum1_snd_64 };
                              choose_res_69 = id_71;
                            } else {
                              uint16_t id_72 { 11 };
                              bool id_73 { bool(id_72 == dsum1_fst_63) };
                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_74;
                              if (id_73) {
                                (void)VOID;
                                std::shared_ptr<::dessser::gen::raql_type::base>  id_75 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<11>, VOID) };
                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_76 { id_75, dsum1_snd_64 };
                                choose_res_74 = id_76;
                              } else {
                                uint16_t id_77 { 12 };
                                bool id_78 { bool(id_77 == dsum1_fst_63) };
                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_79;
                                if (id_78) {
                                  (void)VOID;
                                  std::shared_ptr<::dessser::gen::raql_type::base>  id_80 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<12>, VOID) };
                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_81 { id_80, dsum1_snd_64 };
                                  choose_res_79 = id_81;
                                } else {
                                  uint16_t id_82 { 13 };
                                  bool id_83 { bool(id_82 == dsum1_fst_63) };
                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_84;
                                  if (id_83) {
                                    (void)VOID;
                                    std::shared_ptr<::dessser::gen::raql_type::base>  id_85 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<13>, VOID) };
                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_86 { id_85, dsum1_snd_64 };
                                    choose_res_84 = id_86;
                                  } else {
                                    uint16_t id_87 { 14 };
                                    bool id_88 { bool(id_87 == dsum1_fst_63) };
                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_89;
                                    if (id_88) {
                                      (void)VOID;
                                      std::shared_ptr<::dessser::gen::raql_type::base>  id_90 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<14>, VOID) };
                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_91 { id_90, dsum1_snd_64 };
                                      choose_res_89 = id_91;
                                    } else {
                                      uint16_t id_92 { 15 };
                                      bool id_93 { bool(id_92 == dsum1_fst_63) };
                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_94;
                                      if (id_93) {
                                        (void)VOID;
                                        std::shared_ptr<::dessser::gen::raql_type::base>  id_95 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<15>, VOID) };
                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_96 { id_95, dsum1_snd_64 };
                                        choose_res_94 = id_96;
                                      } else {
                                        uint16_t id_97 { 16 };
                                        bool id_98 { bool(id_97 == dsum1_fst_63) };
                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_99;
                                        if (id_98) {
                                          (void)VOID;
                                          std::shared_ptr<::dessser::gen::raql_type::base>  id_100 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<16>, VOID) };
                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_101 { id_100, dsum1_snd_64 };
                                          choose_res_99 = id_101;
                                        } else {
                                          uint16_t id_102 { 17 };
                                          bool id_103 { bool(id_102 == dsum1_fst_63) };
                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_104;
                                          if (id_103) {
                                            (void)VOID;
                                            std::shared_ptr<::dessser::gen::raql_type::base>  id_105 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<17>, VOID) };
                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_106 { id_105, dsum1_snd_64 };
                                            choose_res_104 = id_106;
                                          } else {
                                            uint16_t id_107 { 18 };
                                            bool id_108 { bool(id_107 == dsum1_fst_63) };
                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_109;
                                            if (id_108) {
                                              (void)VOID;
                                              std::shared_ptr<::dessser::gen::raql_type::base>  id_110 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<18>, VOID) };
                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_111 { id_110, dsum1_snd_64 };
                                              choose_res_109 = id_111;
                                            } else {
                                              uint16_t id_112 { 19 };
                                              bool id_113 { bool(id_112 == dsum1_fst_63) };
                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_114;
                                              if (id_113) {
                                                (void)VOID;
                                                std::shared_ptr<::dessser::gen::raql_type::base>  id_115 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<19>, VOID) };
                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_116 { id_115, dsum1_snd_64 };
                                                choose_res_114 = id_116;
                                              } else {
                                                uint16_t id_117 { 20 };
                                                bool id_118 { bool(id_117 == dsum1_fst_63) };
                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_119;
                                                if (id_118) {
                                                  (void)VOID;
                                                  std::shared_ptr<::dessser::gen::raql_type::base>  id_120 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<20>, VOID) };
                                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_121 { id_120, dsum1_snd_64 };
                                                  choose_res_119 = id_121;
                                                } else {
                                                  uint16_t id_122 { 21 };
                                                  bool id_123 { bool(id_122 == dsum1_fst_63) };
                                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_124;
                                                  if (id_123) {
                                                    (void)VOID;
                                                    std::shared_ptr<::dessser::gen::raql_type::base>  id_125 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<21>, VOID) };
                                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_126 { id_125, dsum1_snd_64 };
                                                    choose_res_124 = id_126;
                                                  } else {
                                                    uint16_t id_127 { 22 };
                                                    bool id_128 { bool(id_127 == dsum1_fst_63) };
                                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_129;
                                                    if (id_128) {
                                                      (void)VOID;
                                                      std::shared_ptr<::dessser::gen::raql_type::base>  id_130 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<22>, VOID) };
                                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_131 { id_130, dsum1_snd_64 };
                                                      choose_res_129 = id_131;
                                                    } else {
                                                      uint16_t id_132 { 23 };
                                                      bool id_133 { bool(id_132 == dsum1_fst_63) };
                                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_134;
                                                      if (id_133) {
                                                        (void)VOID;
                                                        std::shared_ptr<::dessser::gen::raql_type::base>  id_135 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<23>, VOID) };
                                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_136 { id_135, dsum1_snd_64 };
                                                        choose_res_134 = id_136;
                                                      } else {
                                                        uint16_t id_137 { 24 };
                                                        bool id_138 { bool(id_137 == dsum1_fst_63) };
                                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_139;
                                                        if (id_138) {
                                                          (void)VOID;
                                                          std::shared_ptr<::dessser::gen::raql_type::base>  id_140 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<24>, VOID) };
                                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_141 { id_140, dsum1_snd_64 };
                                                          choose_res_139 = id_141;
                                                        } else {
                                                          uint16_t id_142 { 25 };
                                                          bool id_143 { bool(id_142 == dsum1_fst_63) };
                                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_144;
                                                          if (id_143) {
                                                            (void)VOID;
                                                            std::shared_ptr<::dessser::gen::raql_type::base>  id_145 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<25>, VOID) };
                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_146 { id_145, dsum1_snd_64 };
                                                            choose_res_144 = id_146;
                                                          } else {
                                                            uint16_t id_147 { 26 };
                                                            bool id_148 { bool(id_147 == dsum1_fst_63) };
                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_149;
                                                            if (id_148) {
                                                              (void)VOID;
                                                              std::shared_ptr<::dessser::gen::raql_type::base>  id_150 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<26>, VOID) };
                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_151 { id_150, dsum1_snd_64 };
                                                              choose_res_149 = id_151;
                                                            } else {
                                                              uint16_t id_152 { 27 };
                                                              bool id_153 { bool(id_152 == dsum1_fst_63) };
                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_154;
                                                              if (id_153) {
                                                                (void)VOID;
                                                                std::shared_ptr<::dessser::gen::raql_type::base>  id_155 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<27>, VOID) };
                                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_156 { id_155, dsum1_snd_64 };
                                                                choose_res_154 = id_156;
                                                              } else {
                                                                uint16_t id_157 { 28 };
                                                                bool id_158 { bool(id_157 == dsum1_fst_63) };
                                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_159;
                                                                if (id_158) {
                                                                  (void)VOID;
                                                                  std::shared_ptr<::dessser::gen::raql_type::base>  id_160 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<28>, VOID) };
                                                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_161 { id_160, dsum1_snd_64 };
                                                                  choose_res_159 = id_161;
                                                                } else {
                                                                  uint16_t id_162 { 29 };
                                                                  bool id_163 { bool(id_162 == dsum1_fst_63) };
                                                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_164;
                                                                  if (id_163) {
                                                                    (void)VOID;
                                                                    std::shared_ptr<::dessser::gen::raql_type::base>  id_165 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<29>, VOID) };
                                                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_166 { id_165, dsum1_snd_64 };
                                                                    choose_res_164 = id_166;
                                                                  } else {
                                                                    uint16_t id_167 { 30 };
                                                                    bool id_168 { bool(id_167 == dsum1_fst_63) };
                                                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_169;
                                                                    if (id_168) {
                                                                      uint32_t id_170 { 0U };
                                                                      Vec<1, uint32_t> id_171 {  id_170  };
                                                                      ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_172;
                                                                      {
                                                                        Vec<1, uint32_t> leb_ref_177 { id_171 };
                                                                        uint8_t id_173 { 0 };
                                                                        Vec<1, uint8_t> id_174 {  id_173  };
                                                                        ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_175;
                                                                        {
                                                                          Vec<1, uint8_t> shft_ref_178 { id_174 };
                                                                          Vec<1, Pointer> id_176 {  dsum1_snd_64  };
                                                                          ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_177;
                                                                          {
                                                                            Vec<1, Pointer> p_ref_179 { id_176 };
                                                                            bool while_flag_178 { true };
                                                                            do {
                                                                              uint8_t id_179 { 0 };
                                                                              Pointer id_180 { p_ref_179[id_179] };
                                                                              ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_181 { id_180.readU8() };
                                                                              bool let_res_182;
                                                                              {
                                                                                ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_180 { id_181 };
                                                                                bool letpair_res_183;
                                                                                {
                                                                                  auto leb128_fst_181 { std::get<0>(leb128_180) };
                                                                                  auto leb128_snd_182 { std::get<1>(leb128_180) };
                                                                                  uint8_t id_184 { 0 };
                                                                                  Void id_185 { ((void)(p_ref_179[id_184] = leb128_snd_182), VOID) };
                                                                                  (void)id_185;
                                                                                  uint8_t id_186 { 0 };
                                                                                  uint8_t id_187 { 127 };
                                                                                  uint8_t id_188 { uint8_t(leb128_fst_181 & id_187) };
                                                                                  uint32_t id_189 { uint32_t(id_188) };
                                                                                  uint8_t id_190 { 0 };
                                                                                  uint8_t id_191 { shft_ref_178[id_190] };
                                                                                  uint32_t id_192 { uint32_t(id_189 << id_191) };
                                                                                  uint8_t id_193 { 0 };
                                                                                  uint32_t id_194 { leb_ref_177[id_193] };
                                                                                  uint32_t id_195 { uint32_t(id_192 | id_194) };
                                                                                  Void id_196 { ((void)(leb_ref_177[id_186] = id_195), VOID) };
                                                                                  (void)id_196;
                                                                                  uint8_t id_197 { 0 };
                                                                                  uint8_t id_198 { 0 };
                                                                                  uint8_t id_199 { shft_ref_178[id_198] };
                                                                                  uint8_t id_200 { 7 };
                                                                                  uint8_t id_201 { uint8_t(id_199 + id_200) };
                                                                                  Void id_202 { ((void)(shft_ref_178[id_197] = id_201), VOID) };
                                                                                  (void)id_202;
                                                                                  uint8_t id_203 { 128 };
                                                                                  bool id_204 { bool(leb128_fst_181 >= id_203) };
                                                                                  letpair_res_183 = id_204;
                                                                                }
                                                                                let_res_182 = letpair_res_183;
                                                                              }
                                                                              while_flag_178 = let_res_182;
                                                                              if (while_flag_178) {
                                                                                (void)VOID;
                                                                              }
                                                                            } while (while_flag_178);
                                                                            (void)VOID;
                                                                            uint8_t id_205 { 0 };
                                                                            uint32_t id_206 { leb_ref_177[id_205] };
                                                                            uint8_t id_207 { 0 };
                                                                            Pointer id_208 { p_ref_179[id_207] };
                                                                            ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 id_209 { id_206, id_208 };
                                                                            let_res_177 = id_209;
                                                                          }
                                                                          let_res_175 = let_res_177;
                                                                        }
                                                                        let_res_172 = let_res_175;
                                                                      }
                                                                      ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce let_res_210;
                                                                      {
                                                                        ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 dlist1_186 { let_res_172 };
                                                                        ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce letpair_res_211;
                                                                        {
                                                                          auto dlist1_fst_187 { std::get<0>(dlist1_186) };
                                                                          auto dlist1_snd_188 { std::get<1>(dlist1_186) };
                                                                          Lst<std::shared_ptr<::dessser::gen::raql_type::t> > endoflist_212;
                                                                          ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce id_213 { endoflist_212, dlist1_snd_188 };
                                                                          Vec<1, ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce> id_214 {  id_213  };
                                                                          ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce let_res_215;
                                                                          {
                                                                            Vec<1, ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce> inits_src_ref_189 { id_214 };
                                                                            int32_t id_216 { 0L };
                                                                            Vec<1, int32_t> id_217 {  id_216  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_190 { id_217 };
                                                                              bool while_flag_218 { true };
                                                                              do {
                                                                                int32_t id_219 { int32_t(dlist1_fst_187) };
                                                                                uint8_t id_220 { 0 };
                                                                                int32_t id_221 { repeat_n_190[id_220] };
                                                                                bool id_222 { bool(id_219 > id_221) };
                                                                                while_flag_218 = id_222;
                                                                                if (while_flag_218) {
                                                                                  uint8_t id_223 { 0 };
                                                                                  ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce id_224 { inits_src_ref_189[id_223] };
                                                                                  {
                                                                                    ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce dlist2_191 { id_224 };
                                                                                    {
                                                                                      auto dlist2_fst_192 { std::get<0>(dlist2_191) };
                                                                                      auto dlist2_snd_193 { std::get<1>(dlist2_191) };
                                                                                      uint8_t id_225 { 0 };
                                                                                      ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_226 { of_row_binary(dlist2_snd_193) };
                                                                                      ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce letpair_res_227;
                                                                                      {
                                                                                        auto dlist3_fst_195 { std::get<0>(id_226) };
                                                                                        auto dlist3_snd_196 { std::get<1>(id_226) };
                                                                                        Lst<std::shared_ptr<::dessser::gen::raql_type::t> > id_228 { dlist3_fst_195, dlist2_fst_192 };
                                                                                        ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce id_229 { id_228, dlist3_snd_196 };
                                                                                        letpair_res_227 = id_229;
                                                                                      }
                                                                                      Void id_230 { ((void)(inits_src_ref_189[id_225] = letpair_res_227), VOID) };
                                                                                      (void)id_230;
                                                                                    }
                                                                                    (void)VOID;
                                                                                  }
                                                                                  (void)VOID;
                                                                                  uint8_t id_231 { 0 };
                                                                                  uint8_t id_232 { 0 };
                                                                                  int32_t id_233 { repeat_n_190[id_232] };
                                                                                  int32_t id_234 { 1L };
                                                                                  int32_t id_235 { int32_t(id_233 + id_234) };
                                                                                  Void id_236 { ((void)(repeat_n_190[id_231] = id_235), VOID) };
                                                                                  (void)id_236;
                                                                                  (void)id_236;
                                                                                }
                                                                              } while (while_flag_218);
                                                                              (void)VOID;
                                                                            }
                                                                            (void)VOID;
                                                                            uint8_t id_237 { 0 };
                                                                            ::dessser::gen::raql_type::t392d3ad514b4ff11fcd9ec6e8aea4bce id_238 { inits_src_ref_189[id_237] };
                                                                            let_res_215 = id_238;
                                                                          }
                                                                          letpair_res_211 = let_res_215;
                                                                        }
                                                                        let_res_210 = letpair_res_211;
                                                                      }
                                                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_239;
                                                                      {
                                                                        auto dlist4_fst_198 { std::get<0>(let_res_210) };
                                                                        auto dlist4_snd_199 { std::get<1>(let_res_210) };
                                                                        Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_240 { dlist4_fst_198.toListRev() };
                                                                        std::shared_ptr<::dessser::gen::raql_type::base>  id_241 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<30>, id_240) };
                                                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_242 { id_241, dlist4_snd_199 };
                                                                        letpair_res_239 = id_242;
                                                                      }
                                                                      choose_res_169 = letpair_res_239;
                                                                    } else {
                                                                      uint16_t id_243 { 31 };
                                                                      bool id_244 { bool(id_243 == dsum1_fst_63) };
                                                                      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_245;
                                                                      if (id_244) {
                                                                        ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 id_246 { dsum1_snd_64.readU32Le() };
                                                                        ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_247;
                                                                        {
                                                                          auto du32_fst_166 { std::get<0>(id_246) };
                                                                          auto du32_snd_167 { std::get<1>(id_246) };
                                                                          ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 id_248 { du32_fst_166, du32_snd_167 };
                                                                          letpair_res_247 = id_248;
                                                                        }
                                                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 let_res_249;
                                                                        {
                                                                          ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 dtup_168 { letpair_res_247 };
                                                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_250;
                                                                          {
                                                                            auto dtup_fst_169 { std::get<0>(dtup_168) };
                                                                            auto dtup_snd_170 { std::get<1>(dtup_168) };
                                                                            ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_251 { of_row_binary(dtup_snd_170) };
                                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_252;
                                                                            {
                                                                              auto dtup_fst_172 { std::get<0>(id_251) };
                                                                              auto dtup_snd_173 { std::get<1>(id_251) };
                                                                              ::dessser::gen::raql_type::tb65a12146ab462f3a71f0a2c9184c7a4 id_253 { dtup_fst_169, dtup_fst_172 };
                                                                              std::shared_ptr<::dessser::gen::raql_type::base>  id_254 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<31>, id_253) };
                                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_255 { id_254, dtup_snd_173 };
                                                                              letpair_res_252 = id_255;
                                                                            }
                                                                            letpair_res_250 = letpair_res_252;
                                                                          }
                                                                          let_res_249 = letpair_res_250;
                                                                        }
                                                                        choose_res_245 = let_res_249;
                                                                      } else {
                                                                        uint16_t id_256 { 32 };
                                                                        bool id_257 { bool(id_256 == dsum1_fst_63) };
                                                                        ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_258;
                                                                        if (id_257) {
                                                                          ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_259 { of_row_binary(dsum1_snd_64) };
                                                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_260;
                                                                          {
                                                                            auto dsum2_fst_163 { std::get<0>(id_259) };
                                                                            auto dsum2_snd_164 { std::get<1>(id_259) };
                                                                            std::shared_ptr<::dessser::gen::raql_type::base>  id_261 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<32>, dsum2_fst_163) };
                                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_262 { id_261, dsum2_snd_164 };
                                                                            letpair_res_260 = id_262;
                                                                          }
                                                                          choose_res_258 = letpair_res_260;
                                                                        } else {
                                                                          uint16_t id_263 { 33 };
                                                                          bool id_264 { bool(id_263 == dsum1_fst_63) };
                                                                          ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_265;
                                                                          if (id_264) {
                                                                            uint32_t id_266 { 0U };
                                                                            Vec<1, uint32_t> id_267 {  id_266  };
                                                                            ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_268;
                                                                            {
                                                                              Vec<1, uint32_t> leb_ref_118 { id_267 };
                                                                              uint8_t id_269 { 0 };
                                                                              Vec<1, uint8_t> id_270 {  id_269  };
                                                                              ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_271;
                                                                              {
                                                                                Vec<1, uint8_t> shft_ref_119 { id_270 };
                                                                                Vec<1, Pointer> id_272 {  dsum1_snd_64  };
                                                                                ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_273;
                                                                                {
                                                                                  Vec<1, Pointer> p_ref_120 { id_272 };
                                                                                  bool while_flag_274 { true };
                                                                                  do {
                                                                                    uint8_t id_275 { 0 };
                                                                                    Pointer id_276 { p_ref_120[id_275] };
                                                                                    ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_277 { id_276.readU8() };
                                                                                    bool let_res_278;
                                                                                    {
                                                                                      ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_121 { id_277 };
                                                                                      bool letpair_res_279;
                                                                                      {
                                                                                        auto leb128_fst_122 { std::get<0>(leb128_121) };
                                                                                        auto leb128_snd_123 { std::get<1>(leb128_121) };
                                                                                        uint8_t id_280 { 0 };
                                                                                        Void id_281 { ((void)(p_ref_120[id_280] = leb128_snd_123), VOID) };
                                                                                        (void)id_281;
                                                                                        uint8_t id_282 { 0 };
                                                                                        uint8_t id_283 { 127 };
                                                                                        uint8_t id_284 { uint8_t(leb128_fst_122 & id_283) };
                                                                                        uint32_t id_285 { uint32_t(id_284) };
                                                                                        uint8_t id_286 { 0 };
                                                                                        uint8_t id_287 { shft_ref_119[id_286] };
                                                                                        uint32_t id_288 { uint32_t(id_285 << id_287) };
                                                                                        uint8_t id_289 { 0 };
                                                                                        uint32_t id_290 { leb_ref_118[id_289] };
                                                                                        uint32_t id_291 { uint32_t(id_288 | id_290) };
                                                                                        Void id_292 { ((void)(leb_ref_118[id_282] = id_291), VOID) };
                                                                                        (void)id_292;
                                                                                        uint8_t id_293 { 0 };
                                                                                        uint8_t id_294 { 0 };
                                                                                        uint8_t id_295 { shft_ref_119[id_294] };
                                                                                        uint8_t id_296 { 7 };
                                                                                        uint8_t id_297 { uint8_t(id_295 + id_296) };
                                                                                        Void id_298 { ((void)(shft_ref_119[id_293] = id_297), VOID) };
                                                                                        (void)id_298;
                                                                                        uint8_t id_299 { 128 };
                                                                                        bool id_300 { bool(leb128_fst_122 >= id_299) };
                                                                                        letpair_res_279 = id_300;
                                                                                      }
                                                                                      let_res_278 = letpair_res_279;
                                                                                    }
                                                                                    while_flag_274 = let_res_278;
                                                                                    if (while_flag_274) {
                                                                                      (void)VOID;
                                                                                    }
                                                                                  } while (while_flag_274);
                                                                                  (void)VOID;
                                                                                  uint8_t id_301 { 0 };
                                                                                  uint32_t id_302 { leb_ref_118[id_301] };
                                                                                  uint8_t id_303 { 0 };
                                                                                  Pointer id_304 { p_ref_120[id_303] };
                                                                                  ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 id_305 { id_302, id_304 };
                                                                                  let_res_273 = id_305;
                                                                                }
                                                                                let_res_271 = let_res_273;
                                                                              }
                                                                              let_res_268 = let_res_271;
                                                                            }
                                                                            ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f let_res_306;
                                                                            {
                                                                              ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 dlist1_127 { let_res_268 };
                                                                              ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f letpair_res_307;
                                                                              {
                                                                                auto dlist1_fst_128 { std::get<0>(dlist1_127) };
                                                                                auto dlist1_snd_129 { std::get<1>(dlist1_127) };
                                                                                Lst<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> endoflist_308;
                                                                                ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f id_309 { endoflist_308, dlist1_snd_129 };
                                                                                Vec<1, ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f> id_310 {  id_309  };
                                                                                ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f let_res_311;
                                                                                {
                                                                                  Vec<1, ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f> inits_src_ref_130 { id_310 };
                                                                                  int32_t id_312 { 0L };
                                                                                  Vec<1, int32_t> id_313 {  id_312  };
                                                                                  {
                                                                                    Vec<1, int32_t> repeat_n_131 { id_313 };
                                                                                    bool while_flag_314 { true };
                                                                                    do {
                                                                                      int32_t id_315 { int32_t(dlist1_fst_128) };
                                                                                      uint8_t id_316 { 0 };
                                                                                      int32_t id_317 { repeat_n_131[id_316] };
                                                                                      bool id_318 { bool(id_315 > id_317) };
                                                                                      while_flag_314 = id_318;
                                                                                      if (while_flag_314) {
                                                                                        uint8_t id_319 { 0 };
                                                                                        ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f id_320 { inits_src_ref_130[id_319] };
                                                                                        {
                                                                                          ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f dlist2_132 { id_320 };
                                                                                          {
                                                                                            auto dlist2_fst_133 { std::get<0>(dlist2_132) };
                                                                                            auto dlist2_snd_134 { std::get<1>(dlist2_132) };
                                                                                            uint8_t id_321 { 0 };
                                                                                            uint32_t id_322 { 0U };
                                                                                            Vec<1, uint32_t> id_323 {  id_322  };
                                                                                            ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 let_res_324;
                                                                                            {
                                                                                              Vec<1, uint32_t> leb_ref_135 { id_323 };
                                                                                              uint8_t id_325 { 0 };
                                                                                              Vec<1, uint8_t> id_326 {  id_325  };
                                                                                              ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 let_res_327;
                                                                                              {
                                                                                                Vec<1, uint8_t> shft_ref_136 { id_326 };
                                                                                                Vec<1, Pointer> id_328 {  dlist2_snd_134  };
                                                                                                ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 let_res_329;
                                                                                                {
                                                                                                  Vec<1, Pointer> p_ref_137 { id_328 };
                                                                                                  bool while_flag_330 { true };
                                                                                                  do {
                                                                                                    uint8_t id_331 { 0 };
                                                                                                    Pointer id_332 { p_ref_137[id_331] };
                                                                                                    ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_333 { id_332.readU8() };
                                                                                                    bool let_res_334;
                                                                                                    {
                                                                                                      ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_138 { id_333 };
                                                                                                      bool letpair_res_335;
                                                                                                      {
                                                                                                        auto leb128_fst_139 { std::get<0>(leb128_138) };
                                                                                                        auto leb128_snd_140 { std::get<1>(leb128_138) };
                                                                                                        uint8_t id_336 { 0 };
                                                                                                        Void id_337 { ((void)(p_ref_137[id_336] = leb128_snd_140), VOID) };
                                                                                                        (void)id_337;
                                                                                                        uint8_t id_338 { 0 };
                                                                                                        uint8_t id_339 { 127 };
                                                                                                        uint8_t id_340 { uint8_t(leb128_fst_139 & id_339) };
                                                                                                        uint32_t id_341 { uint32_t(id_340) };
                                                                                                        uint8_t id_342 { 0 };
                                                                                                        uint8_t id_343 { shft_ref_136[id_342] };
                                                                                                        uint32_t id_344 { uint32_t(id_341 << id_343) };
                                                                                                        uint8_t id_345 { 0 };
                                                                                                        uint32_t id_346 { leb_ref_135[id_345] };
                                                                                                        uint32_t id_347 { uint32_t(id_344 | id_346) };
                                                                                                        Void id_348 { ((void)(leb_ref_135[id_338] = id_347), VOID) };
                                                                                                        (void)id_348;
                                                                                                        uint8_t id_349 { 0 };
                                                                                                        uint8_t id_350 { 0 };
                                                                                                        uint8_t id_351 { shft_ref_136[id_350] };
                                                                                                        uint8_t id_352 { 7 };
                                                                                                        uint8_t id_353 { uint8_t(id_351 + id_352) };
                                                                                                        Void id_354 { ((void)(shft_ref_136[id_349] = id_353), VOID) };
                                                                                                        (void)id_354;
                                                                                                        uint8_t id_355 { 128 };
                                                                                                        bool id_356 { bool(leb128_fst_139 >= id_355) };
                                                                                                        letpair_res_335 = id_356;
                                                                                                      }
                                                                                                      let_res_334 = letpair_res_335;
                                                                                                    }
                                                                                                    while_flag_330 = let_res_334;
                                                                                                    if (while_flag_330) {
                                                                                                      (void)VOID;
                                                                                                    }
                                                                                                  } while (while_flag_330);
                                                                                                  (void)VOID;
                                                                                                  uint8_t id_357 { 0 };
                                                                                                  uint32_t id_358 { leb_ref_135[id_357] };
                                                                                                  Size id_359 { Size(id_358) };
                                                                                                  uint8_t id_360 { 0 };
                                                                                                  Pointer id_361 { p_ref_137[id_360] };
                                                                                                  ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 id_362 { id_359, id_361 };
                                                                                                  let_res_329 = id_362;
                                                                                                }
                                                                                                let_res_327 = let_res_329;
                                                                                              }
                                                                                              let_res_324 = let_res_327;
                                                                                            }
                                                                                            ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 let_res_363;
                                                                                            {
                                                                                              ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 dstring1_141 { let_res_324 };
                                                                                              ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 letpair_res_364;
                                                                                              {
                                                                                                auto dstring1_fst_142 { std::get<0>(dstring1_141) };
                                                                                                auto dstring1_snd_143 { std::get<1>(dstring1_141) };
                                                                                                ::dessser::gen::raql_type::t5887709cc43c8c8e24d28211e8c970a2 id_365 { dstring1_snd_143.readBytes(dstring1_fst_142) };
                                                                                                ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 letpair_res_366;
                                                                                                {
                                                                                                  auto dstring2_fst_145 { std::get<0>(id_365) };
                                                                                                  auto dstring2_snd_146 { std::get<1>(id_365) };
                                                                                                  std::string id_367 { dstring2_fst_145.toString() };
                                                                                                  ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 id_368 { id_367, dstring2_snd_146 };
                                                                                                  letpair_res_366 = id_368;
                                                                                                }
                                                                                                letpair_res_364 = letpair_res_366;
                                                                                              }
                                                                                              let_res_363 = letpair_res_364;
                                                                                            }
                                                                                            ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f let_res_369;
                                                                                            {
                                                                                              ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 dtup_147 { let_res_363 };
                                                                                              ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f letpair_res_370;
                                                                                              {
                                                                                                auto dtup_fst_148 { std::get<0>(dtup_147) };
                                                                                                auto dtup_snd_149 { std::get<1>(dtup_147) };
                                                                                                ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_371 { of_row_binary(dtup_snd_149) };
                                                                                                ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f letpair_res_372;
                                                                                                {
                                                                                                  auto dtup_fst_151 { std::get<0>(id_371) };
                                                                                                  auto dtup_snd_152 { std::get<1>(id_371) };
                                                                                                  ::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d id_373 { dtup_fst_148, dtup_fst_151 };
                                                                                                  Lst<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_374 { id_373, dlist2_fst_133 };
                                                                                                  ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f id_375 { id_374, dtup_snd_152 };
                                                                                                  letpair_res_372 = id_375;
                                                                                                }
                                                                                                letpair_res_370 = letpair_res_372;
                                                                                              }
                                                                                              let_res_369 = letpair_res_370;
                                                                                            }
                                                                                            Void id_376 { ((void)(inits_src_ref_130[id_321] = let_res_369), VOID) };
                                                                                            (void)id_376;
                                                                                          }
                                                                                          (void)VOID;
                                                                                        }
                                                                                        (void)VOID;
                                                                                        uint8_t id_377 { 0 };
                                                                                        uint8_t id_378 { 0 };
                                                                                        int32_t id_379 { repeat_n_131[id_378] };
                                                                                        int32_t id_380 { 1L };
                                                                                        int32_t id_381 { int32_t(id_379 + id_380) };
                                                                                        Void id_382 { ((void)(repeat_n_131[id_377] = id_381), VOID) };
                                                                                        (void)id_382;
                                                                                        (void)id_382;
                                                                                      }
                                                                                    } while (while_flag_314);
                                                                                    (void)VOID;
                                                                                  }
                                                                                  (void)VOID;
                                                                                  uint8_t id_383 { 0 };
                                                                                  ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f id_384 { inits_src_ref_130[id_383] };
                                                                                  let_res_311 = id_384;
                                                                                }
                                                                                letpair_res_307 = let_res_311;
                                                                              }
                                                                              let_res_306 = letpair_res_307;
                                                                            }
                                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_385;
                                                                            {
                                                                              auto dlist4_fst_157 { std::get<0>(let_res_306) };
                                                                              auto dlist4_snd_158 { std::get<1>(let_res_306) };
                                                                              Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_386 { dlist4_fst_157.toListRev() };
                                                                              std::shared_ptr<::dessser::gen::raql_type::base>  id_387 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<33>, id_386) };
                                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_388 { id_387, dlist4_snd_158 };
                                                                              letpair_res_385 = id_388;
                                                                            }
                                                                            choose_res_265 = letpair_res_385;
                                                                          } else {
                                                                            uint16_t id_389 { 34 };
                                                                            bool id_390 { bool(id_389 == dsum1_fst_63) };
                                                                            ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 choose_res_391;
                                                                            if (id_390) {
                                                                              uint32_t id_392 { 0U };
                                                                              Vec<1, uint32_t> id_393 {  id_392  };
                                                                              ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_394;
                                                                              {
                                                                                Vec<1, uint32_t> leb_ref_74 { id_393 };
                                                                                uint8_t id_395 { 0 };
                                                                                Vec<1, uint8_t> id_396 {  id_395  };
                                                                                ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_397;
                                                                                {
                                                                                  Vec<1, uint8_t> shft_ref_75 { id_396 };
                                                                                  Vec<1, Pointer> id_398 {  dsum1_snd_64  };
                                                                                  ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 let_res_399;
                                                                                  {
                                                                                    Vec<1, Pointer> p_ref_76 { id_398 };
                                                                                    bool while_flag_400 { true };
                                                                                    do {
                                                                                      uint8_t id_401 { 0 };
                                                                                      Pointer id_402 { p_ref_76[id_401] };
                                                                                      ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_403 { id_402.readU8() };
                                                                                      bool let_res_404;
                                                                                      {
                                                                                        ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_77 { id_403 };
                                                                                        bool letpair_res_405;
                                                                                        {
                                                                                          auto leb128_fst_78 { std::get<0>(leb128_77) };
                                                                                          auto leb128_snd_79 { std::get<1>(leb128_77) };
                                                                                          uint8_t id_406 { 0 };
                                                                                          Void id_407 { ((void)(p_ref_76[id_406] = leb128_snd_79), VOID) };
                                                                                          (void)id_407;
                                                                                          uint8_t id_408 { 0 };
                                                                                          uint8_t id_409 { 127 };
                                                                                          uint8_t id_410 { uint8_t(leb128_fst_78 & id_409) };
                                                                                          uint32_t id_411 { uint32_t(id_410) };
                                                                                          uint8_t id_412 { 0 };
                                                                                          uint8_t id_413 { shft_ref_75[id_412] };
                                                                                          uint32_t id_414 { uint32_t(id_411 << id_413) };
                                                                                          uint8_t id_415 { 0 };
                                                                                          uint32_t id_416 { leb_ref_74[id_415] };
                                                                                          uint32_t id_417 { uint32_t(id_414 | id_416) };
                                                                                          Void id_418 { ((void)(leb_ref_74[id_408] = id_417), VOID) };
                                                                                          (void)id_418;
                                                                                          uint8_t id_419 { 0 };
                                                                                          uint8_t id_420 { 0 };
                                                                                          uint8_t id_421 { shft_ref_75[id_420] };
                                                                                          uint8_t id_422 { 7 };
                                                                                          uint8_t id_423 { uint8_t(id_421 + id_422) };
                                                                                          Void id_424 { ((void)(shft_ref_75[id_419] = id_423), VOID) };
                                                                                          (void)id_424;
                                                                                          uint8_t id_425 { 128 };
                                                                                          bool id_426 { bool(leb128_fst_78 >= id_425) };
                                                                                          letpair_res_405 = id_426;
                                                                                        }
                                                                                        let_res_404 = letpair_res_405;
                                                                                      }
                                                                                      while_flag_400 = let_res_404;
                                                                                      if (while_flag_400) {
                                                                                        (void)VOID;
                                                                                      }
                                                                                    } while (while_flag_400);
                                                                                    (void)VOID;
                                                                                    uint8_t id_427 { 0 };
                                                                                    uint32_t id_428 { leb_ref_74[id_427] };
                                                                                    uint8_t id_429 { 0 };
                                                                                    Pointer id_430 { p_ref_76[id_429] };
                                                                                    ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 id_431 { id_428, id_430 };
                                                                                    let_res_399 = id_431;
                                                                                  }
                                                                                  let_res_397 = let_res_399;
                                                                                }
                                                                                let_res_394 = let_res_397;
                                                                              }
                                                                              ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f let_res_432;
                                                                              {
                                                                                ::dessser::gen::raql_type::t883c6ffea47c0d7b950fe35881e3d737 dlist1_83 { let_res_394 };
                                                                                ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f letpair_res_433;
                                                                                {
                                                                                  auto dlist1_fst_84 { std::get<0>(dlist1_83) };
                                                                                  auto dlist1_snd_85 { std::get<1>(dlist1_83) };
                                                                                  Lst<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> endoflist_434;
                                                                                  ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f id_435 { endoflist_434, dlist1_snd_85 };
                                                                                  Vec<1, ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f> id_436 {  id_435  };
                                                                                  ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f let_res_437;
                                                                                  {
                                                                                    Vec<1, ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f> inits_src_ref_86 { id_436 };
                                                                                    int32_t id_438 { 0L };
                                                                                    Vec<1, int32_t> id_439 {  id_438  };
                                                                                    {
                                                                                      Vec<1, int32_t> repeat_n_87 { id_439 };
                                                                                      bool while_flag_440 { true };
                                                                                      do {
                                                                                        int32_t id_441 { int32_t(dlist1_fst_84) };
                                                                                        uint8_t id_442 { 0 };
                                                                                        int32_t id_443 { repeat_n_87[id_442] };
                                                                                        bool id_444 { bool(id_441 > id_443) };
                                                                                        while_flag_440 = id_444;
                                                                                        if (while_flag_440) {
                                                                                          uint8_t id_445 { 0 };
                                                                                          ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f id_446 { inits_src_ref_86[id_445] };
                                                                                          {
                                                                                            ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f dlist2_88 { id_446 };
                                                                                            {
                                                                                              auto dlist2_fst_89 { std::get<0>(dlist2_88) };
                                                                                              auto dlist2_snd_90 { std::get<1>(dlist2_88) };
                                                                                              uint8_t id_447 { 0 };
                                                                                              uint32_t id_448 { 0U };
                                                                                              Vec<1, uint32_t> id_449 {  id_448  };
                                                                                              ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 let_res_450;
                                                                                              {
                                                                                                Vec<1, uint32_t> leb_ref_91 { id_449 };
                                                                                                uint8_t id_451 { 0 };
                                                                                                Vec<1, uint8_t> id_452 {  id_451  };
                                                                                                ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 let_res_453;
                                                                                                {
                                                                                                  Vec<1, uint8_t> shft_ref_92 { id_452 };
                                                                                                  Vec<1, Pointer> id_454 {  dlist2_snd_90  };
                                                                                                  ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 let_res_455;
                                                                                                  {
                                                                                                    Vec<1, Pointer> p_ref_93 { id_454 };
                                                                                                    bool while_flag_456 { true };
                                                                                                    do {
                                                                                                      uint8_t id_457 { 0 };
                                                                                                      Pointer id_458 { p_ref_93[id_457] };
                                                                                                      ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 id_459 { id_458.readU8() };
                                                                                                      bool let_res_460;
                                                                                                      {
                                                                                                        ::dessser::gen::raql_type::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_94 { id_459 };
                                                                                                        bool letpair_res_461;
                                                                                                        {
                                                                                                          auto leb128_fst_95 { std::get<0>(leb128_94) };
                                                                                                          auto leb128_snd_96 { std::get<1>(leb128_94) };
                                                                                                          uint8_t id_462 { 0 };
                                                                                                          Void id_463 { ((void)(p_ref_93[id_462] = leb128_snd_96), VOID) };
                                                                                                          (void)id_463;
                                                                                                          uint8_t id_464 { 0 };
                                                                                                          uint8_t id_465 { 127 };
                                                                                                          uint8_t id_466 { uint8_t(leb128_fst_95 & id_465) };
                                                                                                          uint32_t id_467 { uint32_t(id_466) };
                                                                                                          uint8_t id_468 { 0 };
                                                                                                          uint8_t id_469 { shft_ref_92[id_468] };
                                                                                                          uint32_t id_470 { uint32_t(id_467 << id_469) };
                                                                                                          uint8_t id_471 { 0 };
                                                                                                          uint32_t id_472 { leb_ref_91[id_471] };
                                                                                                          uint32_t id_473 { uint32_t(id_470 | id_472) };
                                                                                                          Void id_474 { ((void)(leb_ref_91[id_464] = id_473), VOID) };
                                                                                                          (void)id_474;
                                                                                                          uint8_t id_475 { 0 };
                                                                                                          uint8_t id_476 { 0 };
                                                                                                          uint8_t id_477 { shft_ref_92[id_476] };
                                                                                                          uint8_t id_478 { 7 };
                                                                                                          uint8_t id_479 { uint8_t(id_477 + id_478) };
                                                                                                          Void id_480 { ((void)(shft_ref_92[id_475] = id_479), VOID) };
                                                                                                          (void)id_480;
                                                                                                          uint8_t id_481 { 128 };
                                                                                                          bool id_482 { bool(leb128_fst_95 >= id_481) };
                                                                                                          letpair_res_461 = id_482;
                                                                                                        }
                                                                                                        let_res_460 = letpair_res_461;
                                                                                                      }
                                                                                                      while_flag_456 = let_res_460;
                                                                                                      if (while_flag_456) {
                                                                                                        (void)VOID;
                                                                                                      }
                                                                                                    } while (while_flag_456);
                                                                                                    (void)VOID;
                                                                                                    uint8_t id_483 { 0 };
                                                                                                    uint32_t id_484 { leb_ref_91[id_483] };
                                                                                                    Size id_485 { Size(id_484) };
                                                                                                    uint8_t id_486 { 0 };
                                                                                                    Pointer id_487 { p_ref_93[id_486] };
                                                                                                    ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 id_488 { id_485, id_487 };
                                                                                                    let_res_455 = id_488;
                                                                                                  }
                                                                                                  let_res_453 = let_res_455;
                                                                                                }
                                                                                                let_res_450 = let_res_453;
                                                                                              }
                                                                                              ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 let_res_489;
                                                                                              {
                                                                                                ::dessser::gen::raql_type::t044960e524fd6ec1bfc06410ce526709 dstring1_97 { let_res_450 };
                                                                                                ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 letpair_res_490;
                                                                                                {
                                                                                                  auto dstring1_fst_98 { std::get<0>(dstring1_97) };
                                                                                                  auto dstring1_snd_99 { std::get<1>(dstring1_97) };
                                                                                                  ::dessser::gen::raql_type::t5887709cc43c8c8e24d28211e8c970a2 id_491 { dstring1_snd_99.readBytes(dstring1_fst_98) };
                                                                                                  ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 letpair_res_492;
                                                                                                  {
                                                                                                    auto dstring2_fst_101 { std::get<0>(id_491) };
                                                                                                    auto dstring2_snd_102 { std::get<1>(id_491) };
                                                                                                    std::string id_493 { dstring2_fst_101.toString() };
                                                                                                    ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 id_494 { id_493, dstring2_snd_102 };
                                                                                                    letpair_res_492 = id_494;
                                                                                                  }
                                                                                                  letpair_res_490 = letpair_res_492;
                                                                                                }
                                                                                                let_res_489 = letpair_res_490;
                                                                                              }
                                                                                              ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f let_res_495;
                                                                                              {
                                                                                                ::dessser::gen::raql_type::t3fd8221434e489b54b5c4356ebff5005 dtup_103 { let_res_489 };
                                                                                                ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f letpair_res_496;
                                                                                                {
                                                                                                  auto dtup_fst_104 { std::get<0>(dtup_103) };
                                                                                                  auto dtup_snd_105 { std::get<1>(dtup_103) };
                                                                                                  ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_497 { of_row_binary(dtup_snd_105) };
                                                                                                  ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f letpair_res_498;
                                                                                                  {
                                                                                                    auto dtup_fst_107 { std::get<0>(id_497) };
                                                                                                    auto dtup_snd_108 { std::get<1>(id_497) };
                                                                                                    ::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d id_499 { dtup_fst_104, dtup_fst_107 };
                                                                                                    Lst<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_500 { id_499, dlist2_fst_89 };
                                                                                                    ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f id_501 { id_500, dtup_snd_108 };
                                                                                                    letpair_res_498 = id_501;
                                                                                                  }
                                                                                                  letpair_res_496 = letpair_res_498;
                                                                                                }
                                                                                                let_res_495 = letpair_res_496;
                                                                                              }
                                                                                              Void id_502 { ((void)(inits_src_ref_86[id_447] = let_res_495), VOID) };
                                                                                              (void)id_502;
                                                                                            }
                                                                                            (void)VOID;
                                                                                          }
                                                                                          (void)VOID;
                                                                                          uint8_t id_503 { 0 };
                                                                                          uint8_t id_504 { 0 };
                                                                                          int32_t id_505 { repeat_n_87[id_504] };
                                                                                          int32_t id_506 { 1L };
                                                                                          int32_t id_507 { int32_t(id_505 + id_506) };
                                                                                          Void id_508 { ((void)(repeat_n_87[id_503] = id_507), VOID) };
                                                                                          (void)id_508;
                                                                                          (void)id_508;
                                                                                        }
                                                                                      } while (while_flag_440);
                                                                                      (void)VOID;
                                                                                    }
                                                                                    (void)VOID;
                                                                                    uint8_t id_509 { 0 };
                                                                                    ::dessser::gen::raql_type::te49cc3648a3044f2cc62b07857df3a6f id_510 { inits_src_ref_86[id_509] };
                                                                                    let_res_437 = id_510;
                                                                                  }
                                                                                  letpair_res_433 = let_res_437;
                                                                                }
                                                                                let_res_432 = letpair_res_433;
                                                                              }
                                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_511;
                                                                              {
                                                                                auto dlist4_fst_113 { std::get<0>(let_res_432) };
                                                                                auto dlist4_snd_114 { std::get<1>(let_res_432) };
                                                                                Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_512 { dlist4_fst_113.toListRev() };
                                                                                std::shared_ptr<::dessser::gen::raql_type::base>  id_513 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<34>, id_512) };
                                                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_514 { id_513, dlist4_snd_114 };
                                                                                letpair_res_511 = id_514;
                                                                              }
                                                                              choose_res_391 = letpair_res_511;
                                                                            } else {
                                                                              uint16_t id_515 { 35 };
                                                                              bool id_516 { bool(dsum1_fst_63 == id_515) };
                                                                              Void id_517 { ((void)(assert(id_516)), VOID) };
                                                                              (void)id_517;
                                                                              ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_518 { of_row_binary(dsum1_snd_64) };
                                                                              ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 let_res_519;
                                                                              {
                                                                                ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 dtup_65 { id_518 };
                                                                                ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_520;
                                                                                {
                                                                                  auto dtup_fst_66 { std::get<0>(dtup_65) };
                                                                                  auto dtup_snd_67 { std::get<1>(dtup_65) };
                                                                                  ::dessser::gen::raql_type::tf2625240b3c32734b297669569815110 id_521 { of_row_binary(dtup_snd_67) };
                                                                                  ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_522;
                                                                                  {
                                                                                    auto dtup_fst_69 { std::get<0>(id_521) };
                                                                                    auto dtup_snd_70 { std::get<1>(id_521) };
                                                                                    ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d id_523 { dtup_fst_66, dtup_fst_69 };
                                                                                    std::shared_ptr<::dessser::gen::raql_type::base>  id_524 { std::make_shared<::dessser::gen::raql_type::base>(std::in_place_index<35>, id_523) };
                                                                                    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_525 { id_524, dtup_snd_70 };
                                                                                    letpair_res_522 = id_525;
                                                                                  }
                                                                                  letpair_res_520 = letpair_res_522;
                                                                                }
                                                                                let_res_519 = letpair_res_520;
                                                                              }
                                                                              choose_res_391 = let_res_519;
                                                                            }
                                                                            choose_res_265 = choose_res_391;
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
    ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 letpair_res_526;
    {
      auto make_fst_294 { std::get<0>(let_res_15) };
      auto make_snd_295 { std::get<1>(let_res_15) };
      ::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0 id_527 { make_fst_294, make_snd_295 };
      letpair_res_526 = id_527;
    }
    return letpair_res_526;
  }
   };
  return fun11;
}
std::function<::dessser::gen::raql_type::t45adf9446573668c9b9a6264c9e7d2b0(Pointer)> base_of_row_binary(base_of_row_binary_init());

/* 
    (fun ("{type: (base AS [Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]); nullable: BOOL}")
      (add (apply (identifier "base-sersize-of-row-binary") (get-field "type" (param 0))) (size 1)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t> )> fun528 { [&fun528](std::shared_ptr<::dessser::gen::raql_type::t>  p_0) {
    std::shared_ptr<::dessser::gen::raql_type::base>  id_529 { (*p_0).type };
    Size id_530 { base_sersize_of_row_binary(id_529) };
    Size id_531 { 1UL };
    Size id_532 { Size(id_530 + id_531) };
    return id_532;
  }
   };
  return fun528;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_type::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]")
      (let "label2_308" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_308")) (size 2)
          (if (eq (u16 1) (identifier "label2_308")) (size 2)
            (if (eq (u16 2) (identifier "label2_308")) (size 2)
              (if (eq (u16 3) (identifier "label2_308")) (size 2)
                (if (eq (u16 4) (identifier "label2_308")) (size 2)
                  (if (eq (u16 5) (identifier "label2_308")) (size 2)
                    (if (eq (u16 6) (identifier "label2_308")) (size 2)
                      (if (eq (u16 7) (identifier "label2_308")) (size 2)
                        (if (eq (u16 8) (identifier "label2_308")) (size 2)
                          (if (eq (u16 9) (identifier "label2_308")) 
                            (size 2)
                            (if (eq (u16 10) (identifier "label2_308")) 
                              (size 2)
                              (if (eq (u16 11) (identifier "label2_308")) 
                                (size 2)
                                (if (eq (u16 12) (identifier "label2_308")) 
                                  (size 2)
                                  (if (eq (u16 13) (identifier "label2_308")) 
                                    (size 2)
                                    (if (eq (u16 14) (identifier "label2_308")) 
                                      (size 2)
                                      (if (eq (u16 15) (identifier "label2_308")) 
                                        (size 2)
                                        (if (eq (u16 16) (identifier "label2_308")) 
                                          (size 2)
                                          (if (eq (u16 17) (identifier "label2_308")) 
                                            (size 2)
                                            (if (eq (u16 18) (identifier "label2_308")) 
                                              (size 2)
                                              (if (eq (u16 19) (identifier "label2_308")) 
                                                (size 2)
                                                (if (eq (u16 20) (identifier "label2_308")) 
                                                  (size 2)
                                                  (if (eq (u16 21) (identifier "label2_308")) 
                                                    (size 2)
                                                    (if (eq (u16 22) (identifier "label2_308")) 
                                                      (size 2)
                                                      (if (eq (u16 23) (identifier "label2_308")) 
                                                        (size 2)
                                                        (if (eq (u16 24) (identifier "label2_308")) 
                                                          (size 2)
                                                          (if (eq (u16 25) (identifier "label2_308")) 
                                                            (size 2)
                                                            (if (eq (u16 26) (identifier "label2_308")) 
                                                              (size 2)
                                                              (if (eq (u16 27) (identifier "label2_308")) 
                                                                (size 2)
                                                                (if (eq (u16 28) (identifier "label2_308")) 
                                                                  (size 2)
                                                                  (if 
                                                                    (eq (u16 29) (identifier "label2_308")) 
                                                                    (size 2)
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label2_308"))
                                                                    (let "sz_ref_333"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_331" 
                                                                    (make-vec (cardinality (get-alt "Tup" (param 0))))
                                                                    (let "lebsz_ref_332" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_331")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_332")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_332") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_332")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_332"))))))))
                                                                    (seq
                                                                    (let "repeat_n_334" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Tup" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_334")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_333")
                                                                    (add 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_333"))
                                                                    (apply (identifier "sersize-of-row-binary") (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_334")) (get-alt "Tup" (param 0))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_334") (add (unsafe-nth (u8 0) (identifier "repeat_n_334")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_333"))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label2_308")) 
                                                                    (add (size 6) (apply (identifier "sersize-of-row-binary") (get-item 1 (get-alt "Vec" (param 0)))))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label2_308")) 
                                                                    (add (size 2) (apply (identifier "sersize-of-row-binary") (get-alt "Arr" (param 0))))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label2_308"))
                                                                    (let "sz_ref_322"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_320" 
                                                                    (make-vec (cardinality (get-alt "Rec" (param 0))))
                                                                    (let "lebsz_ref_321" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_320")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_321")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_321") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_321")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_321"))))))))
                                                                    (seq
                                                                    (let "repeat_n_323" 
                                                                    (make-vec (i32 0))
                                                                    (while 
                                                                    (gt (to-i32 (cardinality (get-alt "Rec" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_323")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_322")
                                                                    (let "sz_328"
                                                                    (let "sz_324" 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_322"))
                                                                    (add 
                                                                    (identifier "sz_324")
                                                                    (let "wlen_325" 
                                                                    (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-alt "Rec" (param 0)))))
                                                                    (add
                                                                    (let "n_ref_326" 
                                                                    (make-vec (identifier "wlen_325"))
                                                                    (let "lebsz_ref_327" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_326")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_327")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_327") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_327")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_327")))))) 
                                                                    (size-of-u32 (identifier "wlen_325"))))))
                                                                    (add 
                                                                    (identifier "sz_328")
                                                                    (apply (identifier "sersize-of-row-binary") (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_323")) (get-alt "Rec" (param 0))))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_323") (add (unsafe-nth (u8 0) (identifier "repeat_n_323")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_322"))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label2_308"))
                                                                    (let "sz_ref_313"
                                                                    (make-vec
                                                                    (add 
                                                                    (size 2)
                                                                    (let "n_ref_311" 
                                                                    (make-vec (cardinality (get-alt "Sum" (param 0))))
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
                                                                    (gt (to-i32 (cardinality (get-alt "Sum" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_314")))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "sz_ref_313")
                                                                    (let "sz_319"
                                                                    (let "sz_315" 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_313"))
                                                                    (add 
                                                                    (identifier "sz_315")
                                                                    (let "wlen_316" 
                                                                    (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_314")) (get-alt "Sum" (param 0)))))
                                                                    (add
                                                                    (let "n_ref_317" 
                                                                    (make-vec (identifier "wlen_316"))
                                                                    (let "lebsz_ref_318" 
                                                                    (make-vec (u32 1))
                                                                    (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_317")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_318")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_318") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_318")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_318")))))) 
                                                                    (size-of-u32 (identifier "wlen_316"))))))
                                                                    (add 
                                                                    (identifier "sz_319")
                                                                    (apply (identifier "sersize-of-row-binary") (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_314")) (get-alt "Sum" (param 0))))))))
                                                                    (set-vec (u8 0) (identifier "repeat_n_314") (add (unsafe-nth (u8 0) (identifier "repeat_n_314")) (i32 1)))))) 
                                                                    (unsafe-nth (u8 0) (identifier "sz_ref_313"))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label2_308") (u16 35)))
                                                                    (let "sz_310" 
                                                                    (add (size 2) (apply (identifier "sersize-of-row-binary") (get-item 0 (get-alt "Map" (param 0)))))
                                                                    (add (identifier "sz_310") (apply (identifier "sersize-of-row-binary") (get-item 1 (get-alt "Map" (param 0))))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_type::base> )> base_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_type::base> )> fun533 { [&fun533](std::shared_ptr<::dessser::gen::raql_type::base>  p_0) {
    uint16_t id_534 { uint16_t((*p_0).index()) };
    Size let_res_535;
    {
      uint16_t label2_308 { id_534 };
      uint16_t id_536 { 0 };
      bool id_537 { bool(id_536 == label2_308) };
      Size choose_res_538;
      if (id_537) {
        Size id_539 { 2UL };
        choose_res_538 = id_539;
      } else {
        uint16_t id_540 { 1 };
        bool id_541 { bool(id_540 == label2_308) };
        Size choose_res_542;
        if (id_541) {
          Size id_543 { 2UL };
          choose_res_542 = id_543;
        } else {
          uint16_t id_544 { 2 };
          bool id_545 { bool(id_544 == label2_308) };
          Size choose_res_546;
          if (id_545) {
            Size id_547 { 2UL };
            choose_res_546 = id_547;
          } else {
            uint16_t id_548 { 3 };
            bool id_549 { bool(id_548 == label2_308) };
            Size choose_res_550;
            if (id_549) {
              Size id_551 { 2UL };
              choose_res_550 = id_551;
            } else {
              uint16_t id_552 { 4 };
              bool id_553 { bool(id_552 == label2_308) };
              Size choose_res_554;
              if (id_553) {
                Size id_555 { 2UL };
                choose_res_554 = id_555;
              } else {
                uint16_t id_556 { 5 };
                bool id_557 { bool(id_556 == label2_308) };
                Size choose_res_558;
                if (id_557) {
                  Size id_559 { 2UL };
                  choose_res_558 = id_559;
                } else {
                  uint16_t id_560 { 6 };
                  bool id_561 { bool(id_560 == label2_308) };
                  Size choose_res_562;
                  if (id_561) {
                    Size id_563 { 2UL };
                    choose_res_562 = id_563;
                  } else {
                    uint16_t id_564 { 7 };
                    bool id_565 { bool(id_564 == label2_308) };
                    Size choose_res_566;
                    if (id_565) {
                      Size id_567 { 2UL };
                      choose_res_566 = id_567;
                    } else {
                      uint16_t id_568 { 8 };
                      bool id_569 { bool(id_568 == label2_308) };
                      Size choose_res_570;
                      if (id_569) {
                        Size id_571 { 2UL };
                        choose_res_570 = id_571;
                      } else {
                        uint16_t id_572 { 9 };
                        bool id_573 { bool(id_572 == label2_308) };
                        Size choose_res_574;
                        if (id_573) {
                          Size id_575 { 2UL };
                          choose_res_574 = id_575;
                        } else {
                          uint16_t id_576 { 10 };
                          bool id_577 { bool(id_576 == label2_308) };
                          Size choose_res_578;
                          if (id_577) {
                            Size id_579 { 2UL };
                            choose_res_578 = id_579;
                          } else {
                            uint16_t id_580 { 11 };
                            bool id_581 { bool(id_580 == label2_308) };
                            Size choose_res_582;
                            if (id_581) {
                              Size id_583 { 2UL };
                              choose_res_582 = id_583;
                            } else {
                              uint16_t id_584 { 12 };
                              bool id_585 { bool(id_584 == label2_308) };
                              Size choose_res_586;
                              if (id_585) {
                                Size id_587 { 2UL };
                                choose_res_586 = id_587;
                              } else {
                                uint16_t id_588 { 13 };
                                bool id_589 { bool(id_588 == label2_308) };
                                Size choose_res_590;
                                if (id_589) {
                                  Size id_591 { 2UL };
                                  choose_res_590 = id_591;
                                } else {
                                  uint16_t id_592 { 14 };
                                  bool id_593 { bool(id_592 == label2_308) };
                                  Size choose_res_594;
                                  if (id_593) {
                                    Size id_595 { 2UL };
                                    choose_res_594 = id_595;
                                  } else {
                                    uint16_t id_596 { 15 };
                                    bool id_597 { bool(id_596 == label2_308) };
                                    Size choose_res_598;
                                    if (id_597) {
                                      Size id_599 { 2UL };
                                      choose_res_598 = id_599;
                                    } else {
                                      uint16_t id_600 { 16 };
                                      bool id_601 { bool(id_600 == label2_308) };
                                      Size choose_res_602;
                                      if (id_601) {
                                        Size id_603 { 2UL };
                                        choose_res_602 = id_603;
                                      } else {
                                        uint16_t id_604 { 17 };
                                        bool id_605 { bool(id_604 == label2_308) };
                                        Size choose_res_606;
                                        if (id_605) {
                                          Size id_607 { 2UL };
                                          choose_res_606 = id_607;
                                        } else {
                                          uint16_t id_608 { 18 };
                                          bool id_609 { bool(id_608 == label2_308) };
                                          Size choose_res_610;
                                          if (id_609) {
                                            Size id_611 { 2UL };
                                            choose_res_610 = id_611;
                                          } else {
                                            uint16_t id_612 { 19 };
                                            bool id_613 { bool(id_612 == label2_308) };
                                            Size choose_res_614;
                                            if (id_613) {
                                              Size id_615 { 2UL };
                                              choose_res_614 = id_615;
                                            } else {
                                              uint16_t id_616 { 20 };
                                              bool id_617 { bool(id_616 == label2_308) };
                                              Size choose_res_618;
                                              if (id_617) {
                                                Size id_619 { 2UL };
                                                choose_res_618 = id_619;
                                              } else {
                                                uint16_t id_620 { 21 };
                                                bool id_621 { bool(id_620 == label2_308) };
                                                Size choose_res_622;
                                                if (id_621) {
                                                  Size id_623 { 2UL };
                                                  choose_res_622 = id_623;
                                                } else {
                                                  uint16_t id_624 { 22 };
                                                  bool id_625 { bool(id_624 == label2_308) };
                                                  Size choose_res_626;
                                                  if (id_625) {
                                                    Size id_627 { 2UL };
                                                    choose_res_626 = id_627;
                                                  } else {
                                                    uint16_t id_628 { 23 };
                                                    bool id_629 { bool(id_628 == label2_308) };
                                                    Size choose_res_630;
                                                    if (id_629) {
                                                      Size id_631 { 2UL };
                                                      choose_res_630 = id_631;
                                                    } else {
                                                      uint16_t id_632 { 24 };
                                                      bool id_633 { bool(id_632 == label2_308) };
                                                      Size choose_res_634;
                                                      if (id_633) {
                                                        Size id_635 { 2UL };
                                                        choose_res_634 = id_635;
                                                      } else {
                                                        uint16_t id_636 { 25 };
                                                        bool id_637 { bool(id_636 == label2_308) };
                                                        Size choose_res_638;
                                                        if (id_637) {
                                                          Size id_639 { 2UL };
                                                          choose_res_638 = id_639;
                                                        } else {
                                                          uint16_t id_640 { 26 };
                                                          bool id_641 { bool(id_640 == label2_308) };
                                                          Size choose_res_642;
                                                          if (id_641) {
                                                            Size id_643 { 2UL };
                                                            choose_res_642 = id_643;
                                                          } else {
                                                            uint16_t id_644 { 27 };
                                                            bool id_645 { bool(id_644 == label2_308) };
                                                            Size choose_res_646;
                                                            if (id_645) {
                                                              Size id_647 { 2UL };
                                                              choose_res_646 = id_647;
                                                            } else {
                                                              uint16_t id_648 { 28 };
                                                              bool id_649 { bool(id_648 == label2_308) };
                                                              Size choose_res_650;
                                                              if (id_649) {
                                                                Size id_651 { 2UL };
                                                                choose_res_650 = id_651;
                                                              } else {
                                                                uint16_t id_652 { 29 };
                                                                bool id_653 { bool(id_652 == label2_308) };
                                                                Size choose_res_654;
                                                                if (id_653) {
                                                                  Size id_655 { 2UL };
                                                                  choose_res_654 = id_655;
                                                                } else {
                                                                  uint16_t id_656 { 30 };
                                                                  bool id_657 { bool(id_656 == label2_308) };
                                                                  Size choose_res_658;
                                                                  if (id_657) {
                                                                    Size id_659 { 2UL };
                                                                    Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_660 { std::get<30 /* Tup */>((*p_0)) };
                                                                    uint32_t id_661 { id_660.size() };
                                                                    Vec<1, uint32_t> id_662 {  id_661  };
                                                                    Size let_res_663;
                                                                    {
                                                                      Vec<1, uint32_t> n_ref_331 { id_662 };
                                                                      uint32_t id_664 { 1U };
                                                                      Vec<1, uint32_t> id_665 {  id_664  };
                                                                      Size let_res_666;
                                                                      {
                                                                        Vec<1, uint32_t> lebsz_ref_332 { id_665 };
                                                                        bool while_flag_667 { true };
                                                                        do {
                                                                          uint8_t id_668 { 0 };
                                                                          uint32_t id_669 { n_ref_331[id_668] };
                                                                          uint8_t id_670 { 0 };
                                                                          uint32_t id_671 { lebsz_ref_332[id_670] };
                                                                          uint8_t id_672 { 7 };
                                                                          uint32_t id_673 { uint32_t(id_671 << id_672) };
                                                                          bool id_674 { bool(id_669 >= id_673) };
                                                                          while_flag_667 = id_674;
                                                                          if (while_flag_667) {
                                                                            uint8_t id_675 { 0 };
                                                                            uint8_t id_676 { 0 };
                                                                            uint32_t id_677 { lebsz_ref_332[id_676] };
                                                                            uint32_t id_678 { 1U };
                                                                            uint32_t id_679 { uint32_t(id_677 + id_678) };
                                                                            Void id_680 { ((void)(lebsz_ref_332[id_675] = id_679), VOID) };
                                                                            (void)id_680;
                                                                          }
                                                                        } while (while_flag_667);
                                                                        (void)VOID;
                                                                        uint8_t id_681 { 0 };
                                                                        uint32_t id_682 { lebsz_ref_332[id_681] };
                                                                        Size id_683 { Size(id_682) };
                                                                        let_res_666 = id_683;
                                                                      }
                                                                      let_res_663 = let_res_666;
                                                                    }
                                                                    Size id_684 { Size(id_659 + let_res_663) };
                                                                    Vec<1, Size> id_685 {  id_684  };
                                                                    Size let_res_686;
                                                                    {
                                                                      Vec<1, Size> sz_ref_333 { id_685 };
                                                                      int32_t id_687 { 0L };
                                                                      Vec<1, int32_t> id_688 {  id_687  };
                                                                      {
                                                                        Vec<1, int32_t> repeat_n_334 { id_688 };
                                                                        bool while_flag_689 { true };
                                                                        do {
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_690 { std::get<30 /* Tup */>((*p_0)) };
                                                                          uint32_t id_691 { id_690.size() };
                                                                          int32_t id_692 { int32_t(id_691) };
                                                                          uint8_t id_693 { 0 };
                                                                          int32_t id_694 { repeat_n_334[id_693] };
                                                                          bool id_695 { bool(id_692 > id_694) };
                                                                          while_flag_689 = id_695;
                                                                          if (while_flag_689) {
                                                                            uint8_t id_696 { 0 };
                                                                            uint8_t id_697 { 0 };
                                                                            Size id_698 { sz_ref_333[id_697] };
                                                                            uint8_t id_699 { 0 };
                                                                            int32_t id_700 { repeat_n_334[id_699] };
                                                                            Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_701 { std::get<30 /* Tup */>((*p_0)) };
                                                                            std::shared_ptr<::dessser::gen::raql_type::t>  id_702 { id_701[id_700] };
                                                                            Size id_703 { sersize_of_row_binary(id_702) };
                                                                            Size id_704 { Size(id_698 + id_703) };
                                                                            Void id_705 { ((void)(sz_ref_333[id_696] = id_704), VOID) };
                                                                            (void)id_705;
                                                                            uint8_t id_706 { 0 };
                                                                            uint8_t id_707 { 0 };
                                                                            int32_t id_708 { repeat_n_334[id_707] };
                                                                            int32_t id_709 { 1L };
                                                                            int32_t id_710 { int32_t(id_708 + id_709) };
                                                                            Void id_711 { ((void)(repeat_n_334[id_706] = id_710), VOID) };
                                                                            (void)id_711;
                                                                            (void)id_711;
                                                                          }
                                                                        } while (while_flag_689);
                                                                        (void)VOID;
                                                                      }
                                                                      (void)VOID;
                                                                      uint8_t id_712 { 0 };
                                                                      Size id_713 { sz_ref_333[id_712] };
                                                                      let_res_686 = id_713;
                                                                    }
                                                                    choose_res_658 = let_res_686;
                                                                  } else {
                                                                    uint16_t id_714 { 31 };
                                                                    bool id_715 { bool(id_714 == label2_308) };
                                                                    Size choose_res_716;
                                                                    if (id_715) {
                                                                      Size id_717 { 6UL };
                                                                      ::dessser::gen::raql_type::tb65a12146ab462f3a71f0a2c9184c7a4 id_718 { std::get<31 /* Vec */>((*p_0)) };
                                                                      std::shared_ptr<::dessser::gen::raql_type::t>  id_719 { std::get<1>(id_718) };
                                                                      Size id_720 { sersize_of_row_binary(id_719) };
                                                                      Size id_721 { Size(id_717 + id_720) };
                                                                      choose_res_716 = id_721;
                                                                    } else {
                                                                      uint16_t id_722 { 32 };
                                                                      bool id_723 { bool(id_722 == label2_308) };
                                                                      Size choose_res_724;
                                                                      if (id_723) {
                                                                        Size id_725 { 2UL };
                                                                        std::shared_ptr<::dessser::gen::raql_type::t>  id_726 { std::get<32 /* Arr */>((*p_0)) };
                                                                        Size id_727 { sersize_of_row_binary(id_726) };
                                                                        Size id_728 { Size(id_725 + id_727) };
                                                                        choose_res_724 = id_728;
                                                                      } else {
                                                                        uint16_t id_729 { 33 };
                                                                        bool id_730 { bool(id_729 == label2_308) };
                                                                        Size choose_res_731;
                                                                        if (id_730) {
                                                                          Size id_732 { 2UL };
                                                                          Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_733 { std::get<33 /* Rec */>((*p_0)) };
                                                                          uint32_t id_734 { id_733.size() };
                                                                          Vec<1, uint32_t> id_735 {  id_734  };
                                                                          Size let_res_736;
                                                                          {
                                                                            Vec<1, uint32_t> n_ref_320 { id_735 };
                                                                            uint32_t id_737 { 1U };
                                                                            Vec<1, uint32_t> id_738 {  id_737  };
                                                                            Size let_res_739;
                                                                            {
                                                                              Vec<1, uint32_t> lebsz_ref_321 { id_738 };
                                                                              bool while_flag_740 { true };
                                                                              do {
                                                                                uint8_t id_741 { 0 };
                                                                                uint32_t id_742 { n_ref_320[id_741] };
                                                                                uint8_t id_743 { 0 };
                                                                                uint32_t id_744 { lebsz_ref_321[id_743] };
                                                                                uint8_t id_745 { 7 };
                                                                                uint32_t id_746 { uint32_t(id_744 << id_745) };
                                                                                bool id_747 { bool(id_742 >= id_746) };
                                                                                while_flag_740 = id_747;
                                                                                if (while_flag_740) {
                                                                                  uint8_t id_748 { 0 };
                                                                                  uint8_t id_749 { 0 };
                                                                                  uint32_t id_750 { lebsz_ref_321[id_749] };
                                                                                  uint32_t id_751 { 1U };
                                                                                  uint32_t id_752 { uint32_t(id_750 + id_751) };
                                                                                  Void id_753 { ((void)(lebsz_ref_321[id_748] = id_752), VOID) };
                                                                                  (void)id_753;
                                                                                }
                                                                              } while (while_flag_740);
                                                                              (void)VOID;
                                                                              uint8_t id_754 { 0 };
                                                                              uint32_t id_755 { lebsz_ref_321[id_754] };
                                                                              Size id_756 { Size(id_755) };
                                                                              let_res_739 = id_756;
                                                                            }
                                                                            let_res_736 = let_res_739;
                                                                          }
                                                                          Size id_757 { Size(id_732 + let_res_736) };
                                                                          Vec<1, Size> id_758 {  id_757  };
                                                                          Size let_res_759;
                                                                          {
                                                                            Vec<1, Size> sz_ref_322 { id_758 };
                                                                            int32_t id_760 { 0L };
                                                                            Vec<1, int32_t> id_761 {  id_760  };
                                                                            {
                                                                              Vec<1, int32_t> repeat_n_323 { id_761 };
                                                                              bool while_flag_762 { true };
                                                                              do {
                                                                                Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_763 { std::get<33 /* Rec */>((*p_0)) };
                                                                                uint32_t id_764 { id_763.size() };
                                                                                int32_t id_765 { int32_t(id_764) };
                                                                                uint8_t id_766 { 0 };
                                                                                int32_t id_767 { repeat_n_323[id_766] };
                                                                                bool id_768 { bool(id_765 > id_767) };
                                                                                while_flag_762 = id_768;
                                                                                if (while_flag_762) {
                                                                                  uint8_t id_769 { 0 };
                                                                                  uint8_t id_770 { 0 };
                                                                                  Size id_771 { sz_ref_322[id_770] };
                                                                                  Size let_res_772;
                                                                                  {
                                                                                    Size sz_324 { id_771 };
                                                                                    uint8_t id_773 { 0 };
                                                                                    int32_t id_774 { repeat_n_323[id_773] };
                                                                                    Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_775 { std::get<33 /* Rec */>((*p_0)) };
                                                                                    ::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d id_776 { id_775[id_774] };
                                                                                    std::string id_777 { std::get<0>(id_776) };
                                                                                    uint32_t id_778 { (uint32_t)id_777.size() };
                                                                                    Size let_res_779;
                                                                                    {
                                                                                      uint32_t wlen_325 { id_778 };
                                                                                      Vec<1, uint32_t> id_780 {  wlen_325  };
                                                                                      Size let_res_781;
                                                                                      {
                                                                                        Vec<1, uint32_t> n_ref_326 { id_780 };
                                                                                        uint32_t id_782 { 1U };
                                                                                        Vec<1, uint32_t> id_783 {  id_782  };
                                                                                        Size let_res_784;
                                                                                        {
                                                                                          Vec<1, uint32_t> lebsz_ref_327 { id_783 };
                                                                                          bool while_flag_785 { true };
                                                                                          do {
                                                                                            uint8_t id_786 { 0 };
                                                                                            uint32_t id_787 { n_ref_326[id_786] };
                                                                                            uint8_t id_788 { 0 };
                                                                                            uint32_t id_789 { lebsz_ref_327[id_788] };
                                                                                            uint8_t id_790 { 7 };
                                                                                            uint32_t id_791 { uint32_t(id_789 << id_790) };
                                                                                            bool id_792 { bool(id_787 >= id_791) };
                                                                                            while_flag_785 = id_792;
                                                                                            if (while_flag_785) {
                                                                                              uint8_t id_793 { 0 };
                                                                                              uint8_t id_794 { 0 };
                                                                                              uint32_t id_795 { lebsz_ref_327[id_794] };
                                                                                              uint32_t id_796 { 1U };
                                                                                              uint32_t id_797 { uint32_t(id_795 + id_796) };
                                                                                              Void id_798 { ((void)(lebsz_ref_327[id_793] = id_797), VOID) };
                                                                                              (void)id_798;
                                                                                            }
                                                                                          } while (while_flag_785);
                                                                                          (void)VOID;
                                                                                          uint8_t id_799 { 0 };
                                                                                          uint32_t id_800 { lebsz_ref_327[id_799] };
                                                                                          Size id_801 { Size(id_800) };
                                                                                          let_res_784 = id_801;
                                                                                        }
                                                                                        let_res_781 = let_res_784;
                                                                                      }
                                                                                      Size id_802 { Size(wlen_325) };
                                                                                      Size id_803 { Size(let_res_781 + id_802) };
                                                                                      let_res_779 = id_803;
                                                                                    }
                                                                                    Size id_804 { Size(sz_324 + let_res_779) };
                                                                                    let_res_772 = id_804;
                                                                                  }
                                                                                  Size let_res_805;
                                                                                  {
                                                                                    Size sz_328 { let_res_772 };
                                                                                    uint8_t id_806 { 0 };
                                                                                    int32_t id_807 { repeat_n_323[id_806] };
                                                                                    Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_808 { std::get<33 /* Rec */>((*p_0)) };
                                                                                    ::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d id_809 { id_808[id_807] };
                                                                                    std::shared_ptr<::dessser::gen::raql_type::t>  id_810 { std::get<1>(id_809) };
                                                                                    Size id_811 { sersize_of_row_binary(id_810) };
                                                                                    Size id_812 { Size(sz_328 + id_811) };
                                                                                    let_res_805 = id_812;
                                                                                  }
                                                                                  Void id_813 { ((void)(sz_ref_322[id_769] = let_res_805), VOID) };
                                                                                  (void)id_813;
                                                                                  uint8_t id_814 { 0 };
                                                                                  uint8_t id_815 { 0 };
                                                                                  int32_t id_816 { repeat_n_323[id_815] };
                                                                                  int32_t id_817 { 1L };
                                                                                  int32_t id_818 { int32_t(id_816 + id_817) };
                                                                                  Void id_819 { ((void)(repeat_n_323[id_814] = id_818), VOID) };
                                                                                  (void)id_819;
                                                                                  (void)id_819;
                                                                                }
                                                                              } while (while_flag_762);
                                                                              (void)VOID;
                                                                            }
                                                                            (void)VOID;
                                                                            uint8_t id_820 { 0 };
                                                                            Size id_821 { sz_ref_322[id_820] };
                                                                            let_res_759 = id_821;
                                                                          }
                                                                          choose_res_731 = let_res_759;
                                                                        } else {
                                                                          uint16_t id_822 { 34 };
                                                                          bool id_823 { bool(id_822 == label2_308) };
                                                                          Size choose_res_824;
                                                                          if (id_823) {
                                                                            Size id_825 { 2UL };
                                                                            Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_826 { std::get<34 /* Sum */>((*p_0)) };
                                                                            uint32_t id_827 { id_826.size() };
                                                                            Vec<1, uint32_t> id_828 {  id_827  };
                                                                            Size let_res_829;
                                                                            {
                                                                              Vec<1, uint32_t> n_ref_311 { id_828 };
                                                                              uint32_t id_830 { 1U };
                                                                              Vec<1, uint32_t> id_831 {  id_830  };
                                                                              Size let_res_832;
                                                                              {
                                                                                Vec<1, uint32_t> lebsz_ref_312 { id_831 };
                                                                                bool while_flag_833 { true };
                                                                                do {
                                                                                  uint8_t id_834 { 0 };
                                                                                  uint32_t id_835 { n_ref_311[id_834] };
                                                                                  uint8_t id_836 { 0 };
                                                                                  uint32_t id_837 { lebsz_ref_312[id_836] };
                                                                                  uint8_t id_838 { 7 };
                                                                                  uint32_t id_839 { uint32_t(id_837 << id_838) };
                                                                                  bool id_840 { bool(id_835 >= id_839) };
                                                                                  while_flag_833 = id_840;
                                                                                  if (while_flag_833) {
                                                                                    uint8_t id_841 { 0 };
                                                                                    uint8_t id_842 { 0 };
                                                                                    uint32_t id_843 { lebsz_ref_312[id_842] };
                                                                                    uint32_t id_844 { 1U };
                                                                                    uint32_t id_845 { uint32_t(id_843 + id_844) };
                                                                                    Void id_846 { ((void)(lebsz_ref_312[id_841] = id_845), VOID) };
                                                                                    (void)id_846;
                                                                                  }
                                                                                } while (while_flag_833);
                                                                                (void)VOID;
                                                                                uint8_t id_847 { 0 };
                                                                                uint32_t id_848 { lebsz_ref_312[id_847] };
                                                                                Size id_849 { Size(id_848) };
                                                                                let_res_832 = id_849;
                                                                              }
                                                                              let_res_829 = let_res_832;
                                                                            }
                                                                            Size id_850 { Size(id_825 + let_res_829) };
                                                                            Vec<1, Size> id_851 {  id_850  };
                                                                            Size let_res_852;
                                                                            {
                                                                              Vec<1, Size> sz_ref_313 { id_851 };
                                                                              int32_t id_853 { 0L };
                                                                              Vec<1, int32_t> id_854 {  id_853  };
                                                                              {
                                                                                Vec<1, int32_t> repeat_n_314 { id_854 };
                                                                                bool while_flag_855 { true };
                                                                                do {
                                                                                  Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_856 { std::get<34 /* Sum */>((*p_0)) };
                                                                                  uint32_t id_857 { id_856.size() };
                                                                                  int32_t id_858 { int32_t(id_857) };
                                                                                  uint8_t id_859 { 0 };
                                                                                  int32_t id_860 { repeat_n_314[id_859] };
                                                                                  bool id_861 { bool(id_858 > id_860) };
                                                                                  while_flag_855 = id_861;
                                                                                  if (while_flag_855) {
                                                                                    uint8_t id_862 { 0 };
                                                                                    uint8_t id_863 { 0 };
                                                                                    Size id_864 { sz_ref_313[id_863] };
                                                                                    Size let_res_865;
                                                                                    {
                                                                                      Size sz_315 { id_864 };
                                                                                      uint8_t id_866 { 0 };
                                                                                      int32_t id_867 { repeat_n_314[id_866] };
                                                                                      Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_868 { std::get<34 /* Sum */>((*p_0)) };
                                                                                      ::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d id_869 { id_868[id_867] };
                                                                                      std::string id_870 { std::get<0>(id_869) };
                                                                                      uint32_t id_871 { (uint32_t)id_870.size() };
                                                                                      Size let_res_872;
                                                                                      {
                                                                                        uint32_t wlen_316 { id_871 };
                                                                                        Vec<1, uint32_t> id_873 {  wlen_316  };
                                                                                        Size let_res_874;
                                                                                        {
                                                                                          Vec<1, uint32_t> n_ref_317 { id_873 };
                                                                                          uint32_t id_875 { 1U };
                                                                                          Vec<1, uint32_t> id_876 {  id_875  };
                                                                                          Size let_res_877;
                                                                                          {
                                                                                            Vec<1, uint32_t> lebsz_ref_318 { id_876 };
                                                                                            bool while_flag_878 { true };
                                                                                            do {
                                                                                              uint8_t id_879 { 0 };
                                                                                              uint32_t id_880 { n_ref_317[id_879] };
                                                                                              uint8_t id_881 { 0 };
                                                                                              uint32_t id_882 { lebsz_ref_318[id_881] };
                                                                                              uint8_t id_883 { 7 };
                                                                                              uint32_t id_884 { uint32_t(id_882 << id_883) };
                                                                                              bool id_885 { bool(id_880 >= id_884) };
                                                                                              while_flag_878 = id_885;
                                                                                              if (while_flag_878) {
                                                                                                uint8_t id_886 { 0 };
                                                                                                uint8_t id_887 { 0 };
                                                                                                uint32_t id_888 { lebsz_ref_318[id_887] };
                                                                                                uint32_t id_889 { 1U };
                                                                                                uint32_t id_890 { uint32_t(id_888 + id_889) };
                                                                                                Void id_891 { ((void)(lebsz_ref_318[id_886] = id_890), VOID) };
                                                                                                (void)id_891;
                                                                                              }
                                                                                            } while (while_flag_878);
                                                                                            (void)VOID;
                                                                                            uint8_t id_892 { 0 };
                                                                                            uint32_t id_893 { lebsz_ref_318[id_892] };
                                                                                            Size id_894 { Size(id_893) };
                                                                                            let_res_877 = id_894;
                                                                                          }
                                                                                          let_res_874 = let_res_877;
                                                                                        }
                                                                                        Size id_895 { Size(wlen_316) };
                                                                                        Size id_896 { Size(let_res_874 + id_895) };
                                                                                        let_res_872 = id_896;
                                                                                      }
                                                                                      Size id_897 { Size(sz_315 + let_res_872) };
                                                                                      let_res_865 = id_897;
                                                                                    }
                                                                                    Size let_res_898;
                                                                                    {
                                                                                      Size sz_319 { let_res_865 };
                                                                                      uint8_t id_899 { 0 };
                                                                                      int32_t id_900 { repeat_n_314[id_899] };
                                                                                      Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_901 { std::get<34 /* Sum */>((*p_0)) };
                                                                                      ::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d id_902 { id_901[id_900] };
                                                                                      std::shared_ptr<::dessser::gen::raql_type::t>  id_903 { std::get<1>(id_902) };
                                                                                      Size id_904 { sersize_of_row_binary(id_903) };
                                                                                      Size id_905 { Size(sz_319 + id_904) };
                                                                                      let_res_898 = id_905;
                                                                                    }
                                                                                    Void id_906 { ((void)(sz_ref_313[id_862] = let_res_898), VOID) };
                                                                                    (void)id_906;
                                                                                    uint8_t id_907 { 0 };
                                                                                    uint8_t id_908 { 0 };
                                                                                    int32_t id_909 { repeat_n_314[id_908] };
                                                                                    int32_t id_910 { 1L };
                                                                                    int32_t id_911 { int32_t(id_909 + id_910) };
                                                                                    Void id_912 { ((void)(repeat_n_314[id_907] = id_911), VOID) };
                                                                                    (void)id_912;
                                                                                    (void)id_912;
                                                                                  }
                                                                                } while (while_flag_855);
                                                                                (void)VOID;
                                                                              }
                                                                              (void)VOID;
                                                                              uint8_t id_913 { 0 };
                                                                              Size id_914 { sz_ref_313[id_913] };
                                                                              let_res_852 = id_914;
                                                                            }
                                                                            choose_res_824 = let_res_852;
                                                                          } else {
                                                                            uint16_t id_915 { 35 };
                                                                            bool id_916 { bool(label2_308 == id_915) };
                                                                            Void id_917 { ((void)(assert(id_916)), VOID) };
                                                                            (void)id_917;
                                                                            Size id_918 { 2UL };
                                                                            ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d id_919 { std::get<35 /* Map */>((*p_0)) };
                                                                            std::shared_ptr<::dessser::gen::raql_type::t>  id_920 { std::get<0>(id_919) };
                                                                            Size id_921 { sersize_of_row_binary(id_920) };
                                                                            Size id_922 { Size(id_918 + id_921) };
                                                                            Size let_res_923;
                                                                            {
                                                                              Size sz_310 { id_922 };
                                                                              ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d id_924 { std::get<35 /* Map */>((*p_0)) };
                                                                              std::shared_ptr<::dessser::gen::raql_type::t>  id_925 { std::get<1>(id_924) };
                                                                              Size id_926 { sersize_of_row_binary(id_925) };
                                                                              Size id_927 { Size(sz_310 + id_926) };
                                                                              let_res_923 = id_927;
                                                                            }
                                                                            choose_res_824 = let_res_923;
                                                                          }
                                                                          choose_res_731 = choose_res_824;
                                                                        }
                                                                        choose_res_724 = choose_res_731;
                                                                      }
                                                                      choose_res_716 = choose_res_724;
                                                                    }
                                                                    choose_res_658 = choose_res_716;
                                                                  }
                                                                  choose_res_654 = choose_res_658;
                                                                }
                                                                choose_res_650 = choose_res_654;
                                                              }
                                                              choose_res_646 = choose_res_650;
                                                            }
                                                            choose_res_642 = choose_res_646;
                                                          }
                                                          choose_res_638 = choose_res_642;
                                                        }
                                                        choose_res_634 = choose_res_638;
                                                      }
                                                      choose_res_630 = choose_res_634;
                                                    }
                                                    choose_res_626 = choose_res_630;
                                                  }
                                                  choose_res_622 = choose_res_626;
                                                }
                                                choose_res_618 = choose_res_622;
                                              }
                                              choose_res_614 = choose_res_618;
                                            }
                                            choose_res_610 = choose_res_614;
                                          }
                                          choose_res_606 = choose_res_610;
                                        }
                                        choose_res_602 = choose_res_606;
                                      }
                                      choose_res_598 = choose_res_602;
                                    }
                                    choose_res_594 = choose_res_598;
                                  }
                                  choose_res_590 = choose_res_594;
                                }
                                choose_res_586 = choose_res_590;
                              }
                              choose_res_582 = choose_res_586;
                            }
                            choose_res_578 = choose_res_582;
                          }
                          choose_res_574 = choose_res_578;
                        }
                        choose_res_570 = choose_res_574;
                      }
                      choose_res_566 = choose_res_570;
                    }
                    choose_res_562 = choose_res_566;
                  }
                  choose_res_558 = choose_res_562;
                }
                choose_res_554 = choose_res_558;
              }
              choose_res_550 = choose_res_554;
            }
            choose_res_546 = choose_res_550;
          }
          choose_res_542 = choose_res_546;
        }
        choose_res_538 = choose_res_542;
      }
      let_res_535 = choose_res_538;
    }
    return let_res_535;
  }
   };
  return fun533;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_type::base> )> base_sersize_of_row_binary(base_sersize_of_row_binary_init());

/* 
    (fun ("{type: (base AS [Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]); nullable: BOOL}" "Ptr")
      (let "srec_dst_364" (apply (identifier "base-to-row-binary") (get-field "type" (param 0)) (param 1)) (write-u8 (identifier "srec_dst_364") (u8-of-bool (get-field "nullable" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t> ,Pointer)> fun928 { [&fun928](std::shared_ptr<::dessser::gen::raql_type::t>  p_0, Pointer p_1) {
    std::shared_ptr<::dessser::gen::raql_type::base>  id_929 { (*p_0).type };
    Pointer id_930 { base_to_row_binary(id_929, p_1) };
    Pointer let_res_931;
    {
      Pointer srec_dst_364 { id_930 };
      bool id_932 { (*p_0).nullable };
      uint8_t id_933 { uint8_t(id_932) };
      Pointer id_934 { srec_dst_364.writeU8(id_933) };
      let_res_931 = id_934;
    }
    return let_res_931;
  }
   };
  return fun928;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Void Void | Bool Void | Char Void | Float Void | String Void | U8 Void | U16 Void | U24 Void | U32 Void | U40 Void | U48 Void | U56 Void | U64 Void | U128 Void | I8 Void | I16 Void | I24 Void | I32 Void | I40 Void | I48 Void | I56 Void | I64 Void | I128 Void | Eth Void | Ipv4 Void | Ipv6 Void | Ip Void | Cidrv4 Void | Cidrv6 Void | Cidr Void | Tup THIS[] | Vec (U32; THIS) | Arr THIS | Rec (STRING; THIS)[] | Sum (STRING; THIS)[] | Map (THIS; THIS)]" "Ptr")
      (let "label1_337" (label-of (param 0))
        (let "ssum_dst_338" (write-u16 little-endian (param 1) (identifier "label1_337"))
          (if (eq (u16 0) (identifier "label1_337")) (identifier "ssum_dst_338")
            (if (eq (u16 1) (identifier "label1_337")) (identifier "ssum_dst_338")
              (if (eq (u16 2) (identifier "label1_337")) (identifier "ssum_dst_338")
                (if (eq (u16 3) (identifier "label1_337")) (identifier "ssum_dst_338")
                  (if (eq (u16 4) (identifier "label1_337")) (identifier "ssum_dst_338")
                    (if (eq (u16 5) (identifier "label1_337")) (identifier "ssum_dst_338")
                      (if (eq (u16 6) (identifier "label1_337")) (identifier "ssum_dst_338")
                        (if (eq (u16 7) (identifier "label1_337")) (identifier "ssum_dst_338")
                          (if (eq (u16 8) (identifier "label1_337")) 
                            (identifier "ssum_dst_338")
                            (if (eq (u16 9) (identifier "label1_337")) 
                              (identifier "ssum_dst_338")
                              (if (eq (u16 10) (identifier "label1_337")) 
                                (identifier "ssum_dst_338")
                                (if (eq (u16 11) (identifier "label1_337")) 
                                  (identifier "ssum_dst_338")
                                  (if (eq (u16 12) (identifier "label1_337")) 
                                    (identifier "ssum_dst_338")
                                    (if (eq (u16 13) (identifier "label1_337")) 
                                      (identifier "ssum_dst_338")
                                      (if (eq (u16 14) (identifier "label1_337")) 
                                        (identifier "ssum_dst_338")
                                        (if (eq (u16 15) (identifier "label1_337")) 
                                          (identifier "ssum_dst_338")
                                          (if (eq (u16 16) (identifier "label1_337")) 
                                            (identifier "ssum_dst_338")
                                            (if (eq (u16 17) (identifier "label1_337")) 
                                              (identifier "ssum_dst_338")
                                              (if (eq (u16 18) (identifier "label1_337")) 
                                                (identifier "ssum_dst_338")
                                                (if (eq (u16 19) (identifier "label1_337")) 
                                                  (identifier "ssum_dst_338")
                                                  (if (eq (u16 20) (identifier "label1_337")) 
                                                    (identifier "ssum_dst_338")
                                                    (if (eq (u16 21) (identifier "label1_337")) 
                                                      (identifier "ssum_dst_338")
                                                      (if (eq (u16 22) (identifier "label1_337")) 
                                                        (identifier "ssum_dst_338")
                                                        (if (eq (u16 23) (identifier "label1_337")) 
                                                          (identifier "ssum_dst_338")
                                                          (if (eq (u16 24) (identifier "label1_337")) 
                                                            (identifier "ssum_dst_338")
                                                            (if (eq (u16 25) (identifier "label1_337")) 
                                                              (identifier "ssum_dst_338")
                                                              (if (eq (u16 26) (identifier "label1_337")) 
                                                                (identifier "ssum_dst_338")
                                                                (if (eq (u16 27) (identifier "label1_337")) 
                                                                  (identifier "ssum_dst_338")
                                                                  (if 
                                                                    (eq (u16 28) (identifier "label1_337")) 
                                                                    (identifier "ssum_dst_338")
                                                                    (if 
                                                                    (eq (u16 29) (identifier "label1_337")) 
                                                                    (identifier "ssum_dst_338")
                                                                    (if 
                                                                    (eq (u16 30) (identifier "label1_337"))
                                                                    (let "dst_ref_361"
                                                                    (make-vec
                                                                    (let "leb128_sz_359" 
                                                                    (make-vec (cardinality (get-alt "Tup" (param 0))))
                                                                    (let "leb128_ptr_360" 
                                                                    (make-vec (identifier "ssum_dst_338"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_360")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_360"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_359"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_359"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_359"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_359") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_359")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_359")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_360"))))))
                                                                    (let "n_ref_362" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_363" 
                                                                    (get-alt "Tup" (param 0))
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "dst_ref_361") (apply (identifier "to-row-binary") (identifier "x_363") (unsafe-nth (u8 0) (identifier "dst_ref_361"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_362") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_362")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_361")))))
                                                                    (if 
                                                                    (eq (u16 31) (identifier "label1_337"))
                                                                    (let "stup_dst_358" 
                                                                    (write-u32 little-endian (identifier "ssum_dst_338") (get-item 0 (get-alt "Vec" (param 0))))
                                                                    (apply (identifier "to-row-binary") (get-item 1 (get-alt "Vec" (param 0))) (identifier "stup_dst_358")))
                                                                    (if 
                                                                    (eq (u16 32) (identifier "label1_337")) 
                                                                    (apply (identifier "to-row-binary") (get-alt "Arr" (param 0)) (identifier "ssum_dst_338"))
                                                                    (if 
                                                                    (eq (u16 33) (identifier "label1_337"))
                                                                    (let "dst_ref_351"
                                                                    (make-vec
                                                                    (let "leb128_sz_349" 
                                                                    (make-vec (cardinality (get-alt "Rec" (param 0))))
                                                                    (let "leb128_ptr_350" 
                                                                    (make-vec (identifier "ssum_dst_338"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_350")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_350"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_349"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_349"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_349"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_349") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_349")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_349")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_350"))))))
                                                                    (let "n_ref_352" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_353" 
                                                                    (get-alt "Rec" (param 0))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "dst_ref_351")
                                                                    (let "stup_dst_357"
                                                                    (let "stup_dst_354" 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_351"))
                                                                    (write-bytes
                                                                    (let "leb128_sz_355" 
                                                                    (make-vec (string-length (get-item 0 (identifier "x_353"))))
                                                                    (let "leb128_ptr_356" 
                                                                    (make-vec (identifier "stup_dst_354"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_356")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_356"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_355"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_355"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_355"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_355") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_355")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_355")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_356"))))) 
                                                                    (bytes-of-string (get-item 0 (identifier "x_353"))))) 
                                                                    (apply (identifier "to-row-binary") (get-item 1 (identifier "x_353")) (identifier "stup_dst_357"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_352") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_352")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_351")))))
                                                                    (if 
                                                                    (eq (u16 34) (identifier "label1_337"))
                                                                    (let "dst_ref_342"
                                                                    (make-vec
                                                                    (let "leb128_sz_340" 
                                                                    (make-vec (cardinality (get-alt "Sum" (param 0))))
                                                                    (let "leb128_ptr_341" 
                                                                    (make-vec (identifier "ssum_dst_338"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_341")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_341"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_340"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_340"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_340"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_340") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_340")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_340")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_341"))))))
                                                                    (let "n_ref_343" 
                                                                    (make-vec (i32 0))
                                                                    (seq
                                                                    (for-each "x_344" 
                                                                    (get-alt "Sum" (param 0))
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "dst_ref_342")
                                                                    (let "stup_dst_348"
                                                                    (let "stup_dst_345" 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_342"))
                                                                    (write-bytes
                                                                    (let "leb128_sz_346" 
                                                                    (make-vec (string-length (get-item 0 (identifier "x_344"))))
                                                                    (let "leb128_ptr_347" 
                                                                    (make-vec (identifier "stup_dst_345"))
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
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_347"))))) 
                                                                    (bytes-of-string (get-item 0 (identifier "x_344"))))) 
                                                                    (apply (identifier "to-row-binary") (get-item 1 (identifier "x_344")) (identifier "stup_dst_348"))))
                                                                    (set-vec (u8 0) (identifier "n_ref_343") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_343")))))) 
                                                                    (unsafe-nth (u8 0) (identifier "dst_ref_342")))))
                                                                    (seq 
                                                                    (assert (eq (identifier "label1_337") (u16 35)))
                                                                    (let "stup_dst_339" 
                                                                    (apply (identifier "to-row-binary") (get-item 0 (get-alt "Map" (param 0))) (identifier "ssum_dst_338"))
                                                                    (apply (identifier "to-row-binary") (get-item 1 (get-alt "Map" (param 0))) (identifier "stup_dst_339"))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::base> ,Pointer)> base_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::base> ,Pointer)> fun935 { [&fun935](std::shared_ptr<::dessser::gen::raql_type::base>  p_0, Pointer p_1) {
    uint16_t id_936 { uint16_t((*p_0).index()) };
    Pointer let_res_937;
    {
      uint16_t label1_337 { id_936 };
      Pointer id_938 { p_1.writeU16Le(label1_337) };
      Pointer let_res_939;
      {
        Pointer ssum_dst_338 { id_938 };
        uint16_t id_940 { 0 };
        bool id_941 { bool(id_940 == label1_337) };
        Pointer choose_res_942;
        if (id_941) {
          choose_res_942 = ssum_dst_338;
        } else {
          uint16_t id_943 { 1 };
          bool id_944 { bool(id_943 == label1_337) };
          Pointer choose_res_945;
          if (id_944) {
            choose_res_945 = ssum_dst_338;
          } else {
            uint16_t id_946 { 2 };
            bool id_947 { bool(id_946 == label1_337) };
            Pointer choose_res_948;
            if (id_947) {
              choose_res_948 = ssum_dst_338;
            } else {
              uint16_t id_949 { 3 };
              bool id_950 { bool(id_949 == label1_337) };
              Pointer choose_res_951;
              if (id_950) {
                choose_res_951 = ssum_dst_338;
              } else {
                uint16_t id_952 { 4 };
                bool id_953 { bool(id_952 == label1_337) };
                Pointer choose_res_954;
                if (id_953) {
                  choose_res_954 = ssum_dst_338;
                } else {
                  uint16_t id_955 { 5 };
                  bool id_956 { bool(id_955 == label1_337) };
                  Pointer choose_res_957;
                  if (id_956) {
                    choose_res_957 = ssum_dst_338;
                  } else {
                    uint16_t id_958 { 6 };
                    bool id_959 { bool(id_958 == label1_337) };
                    Pointer choose_res_960;
                    if (id_959) {
                      choose_res_960 = ssum_dst_338;
                    } else {
                      uint16_t id_961 { 7 };
                      bool id_962 { bool(id_961 == label1_337) };
                      Pointer choose_res_963;
                      if (id_962) {
                        choose_res_963 = ssum_dst_338;
                      } else {
                        uint16_t id_964 { 8 };
                        bool id_965 { bool(id_964 == label1_337) };
                        Pointer choose_res_966;
                        if (id_965) {
                          choose_res_966 = ssum_dst_338;
                        } else {
                          uint16_t id_967 { 9 };
                          bool id_968 { bool(id_967 == label1_337) };
                          Pointer choose_res_969;
                          if (id_968) {
                            choose_res_969 = ssum_dst_338;
                          } else {
                            uint16_t id_970 { 10 };
                            bool id_971 { bool(id_970 == label1_337) };
                            Pointer choose_res_972;
                            if (id_971) {
                              choose_res_972 = ssum_dst_338;
                            } else {
                              uint16_t id_973 { 11 };
                              bool id_974 { bool(id_973 == label1_337) };
                              Pointer choose_res_975;
                              if (id_974) {
                                choose_res_975 = ssum_dst_338;
                              } else {
                                uint16_t id_976 { 12 };
                                bool id_977 { bool(id_976 == label1_337) };
                                Pointer choose_res_978;
                                if (id_977) {
                                  choose_res_978 = ssum_dst_338;
                                } else {
                                  uint16_t id_979 { 13 };
                                  bool id_980 { bool(id_979 == label1_337) };
                                  Pointer choose_res_981;
                                  if (id_980) {
                                    choose_res_981 = ssum_dst_338;
                                  } else {
                                    uint16_t id_982 { 14 };
                                    bool id_983 { bool(id_982 == label1_337) };
                                    Pointer choose_res_984;
                                    if (id_983) {
                                      choose_res_984 = ssum_dst_338;
                                    } else {
                                      uint16_t id_985 { 15 };
                                      bool id_986 { bool(id_985 == label1_337) };
                                      Pointer choose_res_987;
                                      if (id_986) {
                                        choose_res_987 = ssum_dst_338;
                                      } else {
                                        uint16_t id_988 { 16 };
                                        bool id_989 { bool(id_988 == label1_337) };
                                        Pointer choose_res_990;
                                        if (id_989) {
                                          choose_res_990 = ssum_dst_338;
                                        } else {
                                          uint16_t id_991 { 17 };
                                          bool id_992 { bool(id_991 == label1_337) };
                                          Pointer choose_res_993;
                                          if (id_992) {
                                            choose_res_993 = ssum_dst_338;
                                          } else {
                                            uint16_t id_994 { 18 };
                                            bool id_995 { bool(id_994 == label1_337) };
                                            Pointer choose_res_996;
                                            if (id_995) {
                                              choose_res_996 = ssum_dst_338;
                                            } else {
                                              uint16_t id_997 { 19 };
                                              bool id_998 { bool(id_997 == label1_337) };
                                              Pointer choose_res_999;
                                              if (id_998) {
                                                choose_res_999 = ssum_dst_338;
                                              } else {
                                                uint16_t id_1000 { 20 };
                                                bool id_1001 { bool(id_1000 == label1_337) };
                                                Pointer choose_res_1002;
                                                if (id_1001) {
                                                  choose_res_1002 = ssum_dst_338;
                                                } else {
                                                  uint16_t id_1003 { 21 };
                                                  bool id_1004 { bool(id_1003 == label1_337) };
                                                  Pointer choose_res_1005;
                                                  if (id_1004) {
                                                    choose_res_1005 = ssum_dst_338;
                                                  } else {
                                                    uint16_t id_1006 { 22 };
                                                    bool id_1007 { bool(id_1006 == label1_337) };
                                                    Pointer choose_res_1008;
                                                    if (id_1007) {
                                                      choose_res_1008 = ssum_dst_338;
                                                    } else {
                                                      uint16_t id_1009 { 23 };
                                                      bool id_1010 { bool(id_1009 == label1_337) };
                                                      Pointer choose_res_1011;
                                                      if (id_1010) {
                                                        choose_res_1011 = ssum_dst_338;
                                                      } else {
                                                        uint16_t id_1012 { 24 };
                                                        bool id_1013 { bool(id_1012 == label1_337) };
                                                        Pointer choose_res_1014;
                                                        if (id_1013) {
                                                          choose_res_1014 = ssum_dst_338;
                                                        } else {
                                                          uint16_t id_1015 { 25 };
                                                          bool id_1016 { bool(id_1015 == label1_337) };
                                                          Pointer choose_res_1017;
                                                          if (id_1016) {
                                                            choose_res_1017 = ssum_dst_338;
                                                          } else {
                                                            uint16_t id_1018 { 26 };
                                                            bool id_1019 { bool(id_1018 == label1_337) };
                                                            Pointer choose_res_1020;
                                                            if (id_1019) {
                                                              choose_res_1020 = ssum_dst_338;
                                                            } else {
                                                              uint16_t id_1021 { 27 };
                                                              bool id_1022 { bool(id_1021 == label1_337) };
                                                              Pointer choose_res_1023;
                                                              if (id_1022) {
                                                                choose_res_1023 = ssum_dst_338;
                                                              } else {
                                                                uint16_t id_1024 { 28 };
                                                                bool id_1025 { bool(id_1024 == label1_337) };
                                                                Pointer choose_res_1026;
                                                                if (id_1025) {
                                                                  choose_res_1026 = ssum_dst_338;
                                                                } else {
                                                                  uint16_t id_1027 { 29 };
                                                                  bool id_1028 { bool(id_1027 == label1_337) };
                                                                  Pointer choose_res_1029;
                                                                  if (id_1028) {
                                                                    choose_res_1029 = ssum_dst_338;
                                                                  } else {
                                                                    uint16_t id_1030 { 30 };
                                                                    bool id_1031 { bool(id_1030 == label1_337) };
                                                                    Pointer choose_res_1032;
                                                                    if (id_1031) {
                                                                      Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_1033 { std::get<30 /* Tup */>((*p_0)) };
                                                                      uint32_t id_1034 { id_1033.size() };
                                                                      Vec<1, uint32_t> id_1035 {  id_1034  };
                                                                      Pointer let_res_1036;
                                                                      {
                                                                        Vec<1, uint32_t> leb128_sz_359 { id_1035 };
                                                                        Vec<1, Pointer> id_1037 {  ssum_dst_338  };
                                                                        Pointer let_res_1038;
                                                                        {
                                                                          Vec<1, Pointer> leb128_ptr_360 { id_1037 };
                                                                          bool while_flag_1039 { true };
                                                                          do {
                                                                            uint8_t id_1040 { 0 };
                                                                            uint8_t id_1041 { 0 };
                                                                            Pointer id_1042 { leb128_ptr_360[id_1041] };
                                                                            uint32_t id_1043 { 128U };
                                                                            uint8_t id_1044 { 0 };
                                                                            uint32_t id_1045 { leb128_sz_359[id_1044] };
                                                                            bool id_1046 { bool(id_1043 > id_1045) };
                                                                            uint8_t choose_res_1047;
                                                                            if (id_1046) {
                                                                              uint8_t id_1048 { 0 };
                                                                              uint32_t id_1049 { leb128_sz_359[id_1048] };
                                                                              uint8_t id_1050 { uint8_t(id_1049) };
                                                                              choose_res_1047 = id_1050;
                                                                            } else {
                                                                              uint8_t id_1051 { 0 };
                                                                              uint32_t id_1052 { leb128_sz_359[id_1051] };
                                                                              uint8_t id_1053 { uint8_t(id_1052) };
                                                                              uint8_t id_1054 { 128 };
                                                                              uint8_t id_1055 { uint8_t(id_1053 | id_1054) };
                                                                              choose_res_1047 = id_1055;
                                                                            }
                                                                            Pointer id_1056 { id_1042.writeU8(choose_res_1047) };
                                                                            Void id_1057 { ((void)(leb128_ptr_360[id_1040] = id_1056), VOID) };
                                                                            (void)id_1057;
                                                                            uint8_t id_1058 { 0 };
                                                                            uint8_t id_1059 { 0 };
                                                                            uint32_t id_1060 { leb128_sz_359[id_1059] };
                                                                            uint8_t id_1061 { 7 };
                                                                            uint32_t id_1062 { uint32_t(id_1060 >> id_1061) };
                                                                            Void id_1063 { ((void)(leb128_sz_359[id_1058] = id_1062), VOID) };
                                                                            (void)id_1063;
                                                                            uint8_t id_1064 { 0 };
                                                                            uint32_t id_1065 { leb128_sz_359[id_1064] };
                                                                            uint32_t id_1066 { 0U };
                                                                            bool id_1067 { bool(id_1065 > id_1066) };
                                                                            while_flag_1039 = id_1067;
                                                                            if (while_flag_1039) {
                                                                              (void)VOID;
                                                                            }
                                                                          } while (while_flag_1039);
                                                                          (void)VOID;
                                                                          uint8_t id_1068 { 0 };
                                                                          Pointer id_1069 { leb128_ptr_360[id_1068] };
                                                                          let_res_1038 = id_1069;
                                                                        }
                                                                        let_res_1036 = let_res_1038;
                                                                      }
                                                                      Vec<1, Pointer> id_1070 {  let_res_1036  };
                                                                      Pointer let_res_1071;
                                                                      {
                                                                        Vec<1, Pointer> dst_ref_361 { id_1070 };
                                                                        int32_t id_1072 { 0L };
                                                                        Vec<1, int32_t> id_1073 {  id_1072  };
                                                                        Pointer let_res_1074;
                                                                        {
                                                                          Vec<1, int32_t> n_ref_362 { id_1073 };
                                                                          Arr<std::shared_ptr<::dessser::gen::raql_type::t> > id_1075 { std::get<30 /* Tup */>((*p_0)) };
                                                                          for (std::shared_ptr<::dessser::gen::raql_type::t>  x_363 : id_1075) {
                                                                            uint8_t id_1076 { 0 };
                                                                            uint8_t id_1077 { 0 };
                                                                            Pointer id_1078 { dst_ref_361[id_1077] };
                                                                            Pointer id_1079 { to_row_binary(x_363, id_1078) };
                                                                            Void id_1080 { ((void)(dst_ref_361[id_1076] = id_1079), VOID) };
                                                                            (void)id_1080;
                                                                            uint8_t id_1081 { 0 };
                                                                            int32_t id_1082 { 1L };
                                                                            uint8_t id_1083 { 0 };
                                                                            int32_t id_1084 { n_ref_362[id_1083] };
                                                                            int32_t id_1085 { int32_t(id_1082 + id_1084) };
                                                                            Void id_1086 { ((void)(n_ref_362[id_1081] = id_1085), VOID) };
                                                                            (void)id_1086;
                                                                            (void)id_1086;
                                                                          }
                                                                          (void)VOID;
                                                                          uint8_t id_1087 { 0 };
                                                                          Pointer id_1088 { dst_ref_361[id_1087] };
                                                                          let_res_1074 = id_1088;
                                                                        }
                                                                        let_res_1071 = let_res_1074;
                                                                      }
                                                                      choose_res_1032 = let_res_1071;
                                                                    } else {
                                                                      uint16_t id_1089 { 31 };
                                                                      bool id_1090 { bool(id_1089 == label1_337) };
                                                                      Pointer choose_res_1091;
                                                                      if (id_1090) {
                                                                        ::dessser::gen::raql_type::tb65a12146ab462f3a71f0a2c9184c7a4 id_1092 { std::get<31 /* Vec */>((*p_0)) };
                                                                        uint32_t id_1093 { std::get<0>(id_1092) };
                                                                        Pointer id_1094 { ssum_dst_338.writeU32Le(id_1093) };
                                                                        Pointer let_res_1095;
                                                                        {
                                                                          Pointer stup_dst_358 { id_1094 };
                                                                          ::dessser::gen::raql_type::tb65a12146ab462f3a71f0a2c9184c7a4 id_1096 { std::get<31 /* Vec */>((*p_0)) };
                                                                          std::shared_ptr<::dessser::gen::raql_type::t>  id_1097 { std::get<1>(id_1096) };
                                                                          Pointer id_1098 { to_row_binary(id_1097, stup_dst_358) };
                                                                          let_res_1095 = id_1098;
                                                                        }
                                                                        choose_res_1091 = let_res_1095;
                                                                      } else {
                                                                        uint16_t id_1099 { 32 };
                                                                        bool id_1100 { bool(id_1099 == label1_337) };
                                                                        Pointer choose_res_1101;
                                                                        if (id_1100) {
                                                                          std::shared_ptr<::dessser::gen::raql_type::t>  id_1102 { std::get<32 /* Arr */>((*p_0)) };
                                                                          Pointer id_1103 { to_row_binary(id_1102, ssum_dst_338) };
                                                                          choose_res_1101 = id_1103;
                                                                        } else {
                                                                          uint16_t id_1104 { 33 };
                                                                          bool id_1105 { bool(id_1104 == label1_337) };
                                                                          Pointer choose_res_1106;
                                                                          if (id_1105) {
                                                                            Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_1107 { std::get<33 /* Rec */>((*p_0)) };
                                                                            uint32_t id_1108 { id_1107.size() };
                                                                            Vec<1, uint32_t> id_1109 {  id_1108  };
                                                                            Pointer let_res_1110;
                                                                            {
                                                                              Vec<1, uint32_t> leb128_sz_349 { id_1109 };
                                                                              Vec<1, Pointer> id_1111 {  ssum_dst_338  };
                                                                              Pointer let_res_1112;
                                                                              {
                                                                                Vec<1, Pointer> leb128_ptr_350 { id_1111 };
                                                                                bool while_flag_1113 { true };
                                                                                do {
                                                                                  uint8_t id_1114 { 0 };
                                                                                  uint8_t id_1115 { 0 };
                                                                                  Pointer id_1116 { leb128_ptr_350[id_1115] };
                                                                                  uint32_t id_1117 { 128U };
                                                                                  uint8_t id_1118 { 0 };
                                                                                  uint32_t id_1119 { leb128_sz_349[id_1118] };
                                                                                  bool id_1120 { bool(id_1117 > id_1119) };
                                                                                  uint8_t choose_res_1121;
                                                                                  if (id_1120) {
                                                                                    uint8_t id_1122 { 0 };
                                                                                    uint32_t id_1123 { leb128_sz_349[id_1122] };
                                                                                    uint8_t id_1124 { uint8_t(id_1123) };
                                                                                    choose_res_1121 = id_1124;
                                                                                  } else {
                                                                                    uint8_t id_1125 { 0 };
                                                                                    uint32_t id_1126 { leb128_sz_349[id_1125] };
                                                                                    uint8_t id_1127 { uint8_t(id_1126) };
                                                                                    uint8_t id_1128 { 128 };
                                                                                    uint8_t id_1129 { uint8_t(id_1127 | id_1128) };
                                                                                    choose_res_1121 = id_1129;
                                                                                  }
                                                                                  Pointer id_1130 { id_1116.writeU8(choose_res_1121) };
                                                                                  Void id_1131 { ((void)(leb128_ptr_350[id_1114] = id_1130), VOID) };
                                                                                  (void)id_1131;
                                                                                  uint8_t id_1132 { 0 };
                                                                                  uint8_t id_1133 { 0 };
                                                                                  uint32_t id_1134 { leb128_sz_349[id_1133] };
                                                                                  uint8_t id_1135 { 7 };
                                                                                  uint32_t id_1136 { uint32_t(id_1134 >> id_1135) };
                                                                                  Void id_1137 { ((void)(leb128_sz_349[id_1132] = id_1136), VOID) };
                                                                                  (void)id_1137;
                                                                                  uint8_t id_1138 { 0 };
                                                                                  uint32_t id_1139 { leb128_sz_349[id_1138] };
                                                                                  uint32_t id_1140 { 0U };
                                                                                  bool id_1141 { bool(id_1139 > id_1140) };
                                                                                  while_flag_1113 = id_1141;
                                                                                  if (while_flag_1113) {
                                                                                    (void)VOID;
                                                                                  }
                                                                                } while (while_flag_1113);
                                                                                (void)VOID;
                                                                                uint8_t id_1142 { 0 };
                                                                                Pointer id_1143 { leb128_ptr_350[id_1142] };
                                                                                let_res_1112 = id_1143;
                                                                              }
                                                                              let_res_1110 = let_res_1112;
                                                                            }
                                                                            Vec<1, Pointer> id_1144 {  let_res_1110  };
                                                                            Pointer let_res_1145;
                                                                            {
                                                                              Vec<1, Pointer> dst_ref_351 { id_1144 };
                                                                              int32_t id_1146 { 0L };
                                                                              Vec<1, int32_t> id_1147 {  id_1146  };
                                                                              Pointer let_res_1148;
                                                                              {
                                                                                Vec<1, int32_t> n_ref_352 { id_1147 };
                                                                                Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_1149 { std::get<33 /* Rec */>((*p_0)) };
                                                                                for (::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d x_353 : id_1149) {
                                                                                  uint8_t id_1150 { 0 };
                                                                                  uint8_t id_1151 { 0 };
                                                                                  Pointer id_1152 { dst_ref_351[id_1151] };
                                                                                  Pointer let_res_1153;
                                                                                  {
                                                                                    Pointer stup_dst_354 { id_1152 };
                                                                                    std::string id_1154 { std::get<0>(x_353) };
                                                                                    uint32_t id_1155 { (uint32_t)id_1154.size() };
                                                                                    Vec<1, uint32_t> id_1156 {  id_1155  };
                                                                                    Pointer let_res_1157;
                                                                                    {
                                                                                      Vec<1, uint32_t> leb128_sz_355 { id_1156 };
                                                                                      Vec<1, Pointer> id_1158 {  stup_dst_354  };
                                                                                      Pointer let_res_1159;
                                                                                      {
                                                                                        Vec<1, Pointer> leb128_ptr_356 { id_1158 };
                                                                                        bool while_flag_1160 { true };
                                                                                        do {
                                                                                          uint8_t id_1161 { 0 };
                                                                                          uint8_t id_1162 { 0 };
                                                                                          Pointer id_1163 { leb128_ptr_356[id_1162] };
                                                                                          uint32_t id_1164 { 128U };
                                                                                          uint8_t id_1165 { 0 };
                                                                                          uint32_t id_1166 { leb128_sz_355[id_1165] };
                                                                                          bool id_1167 { bool(id_1164 > id_1166) };
                                                                                          uint8_t choose_res_1168;
                                                                                          if (id_1167) {
                                                                                            uint8_t id_1169 { 0 };
                                                                                            uint32_t id_1170 { leb128_sz_355[id_1169] };
                                                                                            uint8_t id_1171 { uint8_t(id_1170) };
                                                                                            choose_res_1168 = id_1171;
                                                                                          } else {
                                                                                            uint8_t id_1172 { 0 };
                                                                                            uint32_t id_1173 { leb128_sz_355[id_1172] };
                                                                                            uint8_t id_1174 { uint8_t(id_1173) };
                                                                                            uint8_t id_1175 { 128 };
                                                                                            uint8_t id_1176 { uint8_t(id_1174 | id_1175) };
                                                                                            choose_res_1168 = id_1176;
                                                                                          }
                                                                                          Pointer id_1177 { id_1163.writeU8(choose_res_1168) };
                                                                                          Void id_1178 { ((void)(leb128_ptr_356[id_1161] = id_1177), VOID) };
                                                                                          (void)id_1178;
                                                                                          uint8_t id_1179 { 0 };
                                                                                          uint8_t id_1180 { 0 };
                                                                                          uint32_t id_1181 { leb128_sz_355[id_1180] };
                                                                                          uint8_t id_1182 { 7 };
                                                                                          uint32_t id_1183 { uint32_t(id_1181 >> id_1182) };
                                                                                          Void id_1184 { ((void)(leb128_sz_355[id_1179] = id_1183), VOID) };
                                                                                          (void)id_1184;
                                                                                          uint8_t id_1185 { 0 };
                                                                                          uint32_t id_1186 { leb128_sz_355[id_1185] };
                                                                                          uint32_t id_1187 { 0U };
                                                                                          bool id_1188 { bool(id_1186 > id_1187) };
                                                                                          while_flag_1160 = id_1188;
                                                                                          if (while_flag_1160) {
                                                                                            (void)VOID;
                                                                                          }
                                                                                        } while (while_flag_1160);
                                                                                        (void)VOID;
                                                                                        uint8_t id_1189 { 0 };
                                                                                        Pointer id_1190 { leb128_ptr_356[id_1189] };
                                                                                        let_res_1159 = id_1190;
                                                                                      }
                                                                                      let_res_1157 = let_res_1159;
                                                                                    }
                                                                                    std::string id_1191 { std::get<0>(x_353) };
                                                                                    Bytes id_1192 { id_1191 };
                                                                                    Pointer id_1193 { let_res_1157.writeBytes(id_1192) };
                                                                                    let_res_1153 = id_1193;
                                                                                  }
                                                                                  Pointer let_res_1194;
                                                                                  {
                                                                                    Pointer stup_dst_357 { let_res_1153 };
                                                                                    std::shared_ptr<::dessser::gen::raql_type::t>  id_1195 { std::get<1>(x_353) };
                                                                                    Pointer id_1196 { to_row_binary(id_1195, stup_dst_357) };
                                                                                    let_res_1194 = id_1196;
                                                                                  }
                                                                                  Void id_1197 { ((void)(dst_ref_351[id_1150] = let_res_1194), VOID) };
                                                                                  (void)id_1197;
                                                                                  uint8_t id_1198 { 0 };
                                                                                  int32_t id_1199 { 1L };
                                                                                  uint8_t id_1200 { 0 };
                                                                                  int32_t id_1201 { n_ref_352[id_1200] };
                                                                                  int32_t id_1202 { int32_t(id_1199 + id_1201) };
                                                                                  Void id_1203 { ((void)(n_ref_352[id_1198] = id_1202), VOID) };
                                                                                  (void)id_1203;
                                                                                  (void)id_1203;
                                                                                }
                                                                                (void)VOID;
                                                                                uint8_t id_1204 { 0 };
                                                                                Pointer id_1205 { dst_ref_351[id_1204] };
                                                                                let_res_1148 = id_1205;
                                                                              }
                                                                              let_res_1145 = let_res_1148;
                                                                            }
                                                                            choose_res_1106 = let_res_1145;
                                                                          } else {
                                                                            uint16_t id_1206 { 34 };
                                                                            bool id_1207 { bool(id_1206 == label1_337) };
                                                                            Pointer choose_res_1208;
                                                                            if (id_1207) {
                                                                              Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_1209 { std::get<34 /* Sum */>((*p_0)) };
                                                                              uint32_t id_1210 { id_1209.size() };
                                                                              Vec<1, uint32_t> id_1211 {  id_1210  };
                                                                              Pointer let_res_1212;
                                                                              {
                                                                                Vec<1, uint32_t> leb128_sz_340 { id_1211 };
                                                                                Vec<1, Pointer> id_1213 {  ssum_dst_338  };
                                                                                Pointer let_res_1214;
                                                                                {
                                                                                  Vec<1, Pointer> leb128_ptr_341 { id_1213 };
                                                                                  bool while_flag_1215 { true };
                                                                                  do {
                                                                                    uint8_t id_1216 { 0 };
                                                                                    uint8_t id_1217 { 0 };
                                                                                    Pointer id_1218 { leb128_ptr_341[id_1217] };
                                                                                    uint32_t id_1219 { 128U };
                                                                                    uint8_t id_1220 { 0 };
                                                                                    uint32_t id_1221 { leb128_sz_340[id_1220] };
                                                                                    bool id_1222 { bool(id_1219 > id_1221) };
                                                                                    uint8_t choose_res_1223;
                                                                                    if (id_1222) {
                                                                                      uint8_t id_1224 { 0 };
                                                                                      uint32_t id_1225 { leb128_sz_340[id_1224] };
                                                                                      uint8_t id_1226 { uint8_t(id_1225) };
                                                                                      choose_res_1223 = id_1226;
                                                                                    } else {
                                                                                      uint8_t id_1227 { 0 };
                                                                                      uint32_t id_1228 { leb128_sz_340[id_1227] };
                                                                                      uint8_t id_1229 { uint8_t(id_1228) };
                                                                                      uint8_t id_1230 { 128 };
                                                                                      uint8_t id_1231 { uint8_t(id_1229 | id_1230) };
                                                                                      choose_res_1223 = id_1231;
                                                                                    }
                                                                                    Pointer id_1232 { id_1218.writeU8(choose_res_1223) };
                                                                                    Void id_1233 { ((void)(leb128_ptr_341[id_1216] = id_1232), VOID) };
                                                                                    (void)id_1233;
                                                                                    uint8_t id_1234 { 0 };
                                                                                    uint8_t id_1235 { 0 };
                                                                                    uint32_t id_1236 { leb128_sz_340[id_1235] };
                                                                                    uint8_t id_1237 { 7 };
                                                                                    uint32_t id_1238 { uint32_t(id_1236 >> id_1237) };
                                                                                    Void id_1239 { ((void)(leb128_sz_340[id_1234] = id_1238), VOID) };
                                                                                    (void)id_1239;
                                                                                    uint8_t id_1240 { 0 };
                                                                                    uint32_t id_1241 { leb128_sz_340[id_1240] };
                                                                                    uint32_t id_1242 { 0U };
                                                                                    bool id_1243 { bool(id_1241 > id_1242) };
                                                                                    while_flag_1215 = id_1243;
                                                                                    if (while_flag_1215) {
                                                                                      (void)VOID;
                                                                                    }
                                                                                  } while (while_flag_1215);
                                                                                  (void)VOID;
                                                                                  uint8_t id_1244 { 0 };
                                                                                  Pointer id_1245 { leb128_ptr_341[id_1244] };
                                                                                  let_res_1214 = id_1245;
                                                                                }
                                                                                let_res_1212 = let_res_1214;
                                                                              }
                                                                              Vec<1, Pointer> id_1246 {  let_res_1212  };
                                                                              Pointer let_res_1247;
                                                                              {
                                                                                Vec<1, Pointer> dst_ref_342 { id_1246 };
                                                                                int32_t id_1248 { 0L };
                                                                                Vec<1, int32_t> id_1249 {  id_1248  };
                                                                                Pointer let_res_1250;
                                                                                {
                                                                                  Vec<1, int32_t> n_ref_343 { id_1249 };
                                                                                  Arr<::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d> id_1251 { std::get<34 /* Sum */>((*p_0)) };
                                                                                  for (::dessser::gen::raql_type::t322be039d4e703202ccedfc1a13e4f5d x_344 : id_1251) {
                                                                                    uint8_t id_1252 { 0 };
                                                                                    uint8_t id_1253 { 0 };
                                                                                    Pointer id_1254 { dst_ref_342[id_1253] };
                                                                                    Pointer let_res_1255;
                                                                                    {
                                                                                      Pointer stup_dst_345 { id_1254 };
                                                                                      std::string id_1256 { std::get<0>(x_344) };
                                                                                      uint32_t id_1257 { (uint32_t)id_1256.size() };
                                                                                      Vec<1, uint32_t> id_1258 {  id_1257  };
                                                                                      Pointer let_res_1259;
                                                                                      {
                                                                                        Vec<1, uint32_t> leb128_sz_346 { id_1258 };
                                                                                        Vec<1, Pointer> id_1260 {  stup_dst_345  };
                                                                                        Pointer let_res_1261;
                                                                                        {
                                                                                          Vec<1, Pointer> leb128_ptr_347 { id_1260 };
                                                                                          bool while_flag_1262 { true };
                                                                                          do {
                                                                                            uint8_t id_1263 { 0 };
                                                                                            uint8_t id_1264 { 0 };
                                                                                            Pointer id_1265 { leb128_ptr_347[id_1264] };
                                                                                            uint32_t id_1266 { 128U };
                                                                                            uint8_t id_1267 { 0 };
                                                                                            uint32_t id_1268 { leb128_sz_346[id_1267] };
                                                                                            bool id_1269 { bool(id_1266 > id_1268) };
                                                                                            uint8_t choose_res_1270;
                                                                                            if (id_1269) {
                                                                                              uint8_t id_1271 { 0 };
                                                                                              uint32_t id_1272 { leb128_sz_346[id_1271] };
                                                                                              uint8_t id_1273 { uint8_t(id_1272) };
                                                                                              choose_res_1270 = id_1273;
                                                                                            } else {
                                                                                              uint8_t id_1274 { 0 };
                                                                                              uint32_t id_1275 { leb128_sz_346[id_1274] };
                                                                                              uint8_t id_1276 { uint8_t(id_1275) };
                                                                                              uint8_t id_1277 { 128 };
                                                                                              uint8_t id_1278 { uint8_t(id_1276 | id_1277) };
                                                                                              choose_res_1270 = id_1278;
                                                                                            }
                                                                                            Pointer id_1279 { id_1265.writeU8(choose_res_1270) };
                                                                                            Void id_1280 { ((void)(leb128_ptr_347[id_1263] = id_1279), VOID) };
                                                                                            (void)id_1280;
                                                                                            uint8_t id_1281 { 0 };
                                                                                            uint8_t id_1282 { 0 };
                                                                                            uint32_t id_1283 { leb128_sz_346[id_1282] };
                                                                                            uint8_t id_1284 { 7 };
                                                                                            uint32_t id_1285 { uint32_t(id_1283 >> id_1284) };
                                                                                            Void id_1286 { ((void)(leb128_sz_346[id_1281] = id_1285), VOID) };
                                                                                            (void)id_1286;
                                                                                            uint8_t id_1287 { 0 };
                                                                                            uint32_t id_1288 { leb128_sz_346[id_1287] };
                                                                                            uint32_t id_1289 { 0U };
                                                                                            bool id_1290 { bool(id_1288 > id_1289) };
                                                                                            while_flag_1262 = id_1290;
                                                                                            if (while_flag_1262) {
                                                                                              (void)VOID;
                                                                                            }
                                                                                          } while (while_flag_1262);
                                                                                          (void)VOID;
                                                                                          uint8_t id_1291 { 0 };
                                                                                          Pointer id_1292 { leb128_ptr_347[id_1291] };
                                                                                          let_res_1261 = id_1292;
                                                                                        }
                                                                                        let_res_1259 = let_res_1261;
                                                                                      }
                                                                                      std::string id_1293 { std::get<0>(x_344) };
                                                                                      Bytes id_1294 { id_1293 };
                                                                                      Pointer id_1295 { let_res_1259.writeBytes(id_1294) };
                                                                                      let_res_1255 = id_1295;
                                                                                    }
                                                                                    Pointer let_res_1296;
                                                                                    {
                                                                                      Pointer stup_dst_348 { let_res_1255 };
                                                                                      std::shared_ptr<::dessser::gen::raql_type::t>  id_1297 { std::get<1>(x_344) };
                                                                                      Pointer id_1298 { to_row_binary(id_1297, stup_dst_348) };
                                                                                      let_res_1296 = id_1298;
                                                                                    }
                                                                                    Void id_1299 { ((void)(dst_ref_342[id_1252] = let_res_1296), VOID) };
                                                                                    (void)id_1299;
                                                                                    uint8_t id_1300 { 0 };
                                                                                    int32_t id_1301 { 1L };
                                                                                    uint8_t id_1302 { 0 };
                                                                                    int32_t id_1303 { n_ref_343[id_1302] };
                                                                                    int32_t id_1304 { int32_t(id_1301 + id_1303) };
                                                                                    Void id_1305 { ((void)(n_ref_343[id_1300] = id_1304), VOID) };
                                                                                    (void)id_1305;
                                                                                    (void)id_1305;
                                                                                  }
                                                                                  (void)VOID;
                                                                                  uint8_t id_1306 { 0 };
                                                                                  Pointer id_1307 { dst_ref_342[id_1306] };
                                                                                  let_res_1250 = id_1307;
                                                                                }
                                                                                let_res_1247 = let_res_1250;
                                                                              }
                                                                              choose_res_1208 = let_res_1247;
                                                                            } else {
                                                                              uint16_t id_1308 { 35 };
                                                                              bool id_1309 { bool(label1_337 == id_1308) };
                                                                              Void id_1310 { ((void)(assert(id_1309)), VOID) };
                                                                              (void)id_1310;
                                                                              ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d id_1311 { std::get<35 /* Map */>((*p_0)) };
                                                                              std::shared_ptr<::dessser::gen::raql_type::t>  id_1312 { std::get<0>(id_1311) };
                                                                              Pointer id_1313 { to_row_binary(id_1312, ssum_dst_338) };
                                                                              Pointer let_res_1314;
                                                                              {
                                                                                Pointer stup_dst_339 { id_1313 };
                                                                                ::dessser::gen::raql_type::t76c4c35a2b2b182ccf791241e9611c1d id_1315 { std::get<35 /* Map */>((*p_0)) };
                                                                                std::shared_ptr<::dessser::gen::raql_type::t>  id_1316 { std::get<1>(id_1315) };
                                                                                Pointer id_1317 { to_row_binary(id_1316, stup_dst_339) };
                                                                                let_res_1314 = id_1317;
                                                                              }
                                                                              choose_res_1208 = let_res_1314;
                                                                            }
                                                                            choose_res_1106 = choose_res_1208;
                                                                          }
                                                                          choose_res_1101 = choose_res_1106;
                                                                        }
                                                                        choose_res_1091 = choose_res_1101;
                                                                      }
                                                                      choose_res_1032 = choose_res_1091;
                                                                    }
                                                                    choose_res_1029 = choose_res_1032;
                                                                  }
                                                                  choose_res_1026 = choose_res_1029;
                                                                }
                                                                choose_res_1023 = choose_res_1026;
                                                              }
                                                              choose_res_1020 = choose_res_1023;
                                                            }
                                                            choose_res_1017 = choose_res_1020;
                                                          }
                                                          choose_res_1014 = choose_res_1017;
                                                        }
                                                        choose_res_1011 = choose_res_1014;
                                                      }
                                                      choose_res_1008 = choose_res_1011;
                                                    }
                                                    choose_res_1005 = choose_res_1008;
                                                  }
                                                  choose_res_1002 = choose_res_1005;
                                                }
                                                choose_res_999 = choose_res_1002;
                                              }
                                              choose_res_996 = choose_res_999;
                                            }
                                            choose_res_993 = choose_res_996;
                                          }
                                          choose_res_990 = choose_res_993;
                                        }
                                        choose_res_987 = choose_res_990;
                                      }
                                      choose_res_984 = choose_res_987;
                                    }
                                    choose_res_981 = choose_res_984;
                                  }
                                  choose_res_978 = choose_res_981;
                                }
                                choose_res_975 = choose_res_978;
                              }
                              choose_res_972 = choose_res_975;
                            }
                            choose_res_969 = choose_res_972;
                          }
                          choose_res_966 = choose_res_969;
                        }
                        choose_res_963 = choose_res_966;
                      }
                      choose_res_960 = choose_res_963;
                    }
                    choose_res_957 = choose_res_960;
                  }
                  choose_res_954 = choose_res_957;
                }
                choose_res_951 = choose_res_954;
              }
              choose_res_948 = choose_res_951;
            }
            choose_res_945 = choose_res_948;
          }
          choose_res_942 = choose_res_945;
        }
        let_res_939 = choose_res_942;
      }
      let_res_937 = let_res_939;
    }
    return let_res_937;
  }
   };
  return fun935;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_type::base> ,Pointer)> base_to_row_binary(base_to_row_binary_init());


}
