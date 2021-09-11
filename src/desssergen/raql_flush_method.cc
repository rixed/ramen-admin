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


namespace dessser::gen::raql_flush_method {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t : public std::variant<
  Void, // reset
  Void // never
> { using variant::variant; };

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // reset
    case 1: return std::get<1>(a) == std::get<1>(b); // never
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tb3a89096758ec6cf20bf4ee069398ed5 : public std::tuple<
  ::dessser::gen::raql_flush_method::t*,
  Pointer
> {
  using tuple::tuple;
  tb3a89096758ec6cf20bf4ee069398ed5(std::tuple<::dessser::gen::raql_flush_method::t*, Pointer> p)
    : std::tuple<::dessser::gen::raql_flush_method::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb3a89096758ec6cf20bf4ee069398ed5 const &a, tb3a89096758ec6cf20bf4ee069398ed5 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb3a89096758ec6cf20bf4ee069398ed5 const &a, tb3a89096758ec6cf20bf4ee069398ed5 const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[reset Void | never Void]" "Ptr")
      (let "ssum_dst_76" (write-u16 little-endian (param 1) (label-of (param 0))) (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_76") (seq (assert (eq (label-of (param 0)) (u16 1))) (identifier "ssum_dst_76")))))
 */
static std::function<Pointer(::dessser::gen::raql_flush_method::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_flush_method::t*,Pointer)> fun0 { [&fun0](::dessser::gen::raql_flush_method::t* p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_76 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        choose_res_7 = ssum_dst_76;
      } else {
        uint16_t id_8 { uint16_t((*p_0).index()) };
        uint16_t id_9 { 1 };
        bool id_10 { bool(id_8 == id_9) };
        Void id_11 { ((void)(assert(id_10)), VOID) };
        (void)id_11;
        choose_res_7 = ssum_dst_76;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::raql_flush_method::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[reset Void | never Void]") (if (eq (u16 0) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 1))) (size 2))))
 */
static std::function<Size(::dessser::gen::raql_flush_method::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_flush_method::t*)> fun12 { [&fun12](::dessser::gen::raql_flush_method::t* p_0) {
    uint16_t id_13 { 0 };
    uint16_t id_14 { uint16_t((*p_0).index()) };
    bool id_15 { bool(id_13 == id_14) };
    Size choose_res_16;
    if (id_15) {
      Size id_17 { 2UL };
      choose_res_16 = id_17;
    } else {
      uint16_t id_18 { uint16_t((*p_0).index()) };
      uint16_t id_19 { 1 };
      bool id_20 { bool(id_18 == id_19) };
      Void id_21 { ((void)(assert(id_20)), VOID) };
      (void)id_21;
      Size id_22 { 2UL };
      choose_res_16 = id_22;
    }
    return choose_res_16;
  }
   };
  return fun12;
}
std::function<Size(::dessser::gen::raql_flush_method::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_72" "make_snd_73"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63")) (make-tup (construct "[reset Void | never Void]" 0 (nop)) (identifier "dsum1_snd_64"))
              (seq (assert (eq (identifier "dsum1_fst_63") (u16 1))) (make-tup (construct "[reset Void | never Void]" 1 (nop)) (identifier "dsum1_snd_64")))))) 
        (make-tup (identifier "make_fst_72") (identifier "make_snd_73"))))
 */
static std::function<::dessser::gen::raql_flush_method::tb3a89096758ec6cf20bf4ee069398ed5(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_flush_method::tb3a89096758ec6cf20bf4ee069398ed5(Pointer)> fun23 { [&fun23](Pointer p_0) {
    ::dessser::gen::raql_flush_method::t7609d344c1ba69d0f80fec236d4c216b id_24 { p_0.readU16Le() };
    ::dessser::gen::raql_flush_method::t7609d344c1ba69d0f80fec236d4c216b letpair_res_25;
    {
      auto du16_fst_57 { std::get<0>(id_24) };
      auto du16_snd_58 { std::get<1>(id_24) };
      ::dessser::gen::raql_flush_method::t7609d344c1ba69d0f80fec236d4c216b id_26 { du16_fst_57, du16_snd_58 };
      letpair_res_25 = id_26;
    }
    ::dessser::gen::raql_flush_method::tb3a89096758ec6cf20bf4ee069398ed5 let_res_27;
    {
      ::dessser::gen::raql_flush_method::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_25 };
      ::dessser::gen::raql_flush_method::tb3a89096758ec6cf20bf4ee069398ed5 letpair_res_28;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_29 { 0 };
        bool id_30 { bool(id_29 == dsum1_fst_63) };
        ::dessser::gen::raql_flush_method::tb3a89096758ec6cf20bf4ee069398ed5 choose_res_31;
        if (id_30) {
          (void)VOID;
          ::dessser::gen::raql_flush_method::t* id_32 { new ::dessser::gen::raql_flush_method::t(std::in_place_index<0>, VOID) };
          ::dessser::gen::raql_flush_method::tb3a89096758ec6cf20bf4ee069398ed5 id_33 { id_32, dsum1_snd_64 };
          choose_res_31 = id_33;
        } else {
          uint16_t id_34 { 1 };
          bool id_35 { bool(dsum1_fst_63 == id_34) };
          Void id_36 { ((void)(assert(id_35)), VOID) };
          (void)id_36;
          (void)VOID;
          ::dessser::gen::raql_flush_method::t* id_37 { new ::dessser::gen::raql_flush_method::t(std::in_place_index<1>, VOID) };
          ::dessser::gen::raql_flush_method::tb3a89096758ec6cf20bf4ee069398ed5 id_38 { id_37, dsum1_snd_64 };
          choose_res_31 = id_38;
        }
        letpair_res_28 = choose_res_31;
      }
      let_res_27 = letpair_res_28;
    }
    ::dessser::gen::raql_flush_method::tb3a89096758ec6cf20bf4ee069398ed5 letpair_res_39;
    {
      auto make_fst_72 { std::get<0>(let_res_27) };
      auto make_snd_73 { std::get<1>(let_res_27) };
      ::dessser::gen::raql_flush_method::tb3a89096758ec6cf20bf4ee069398ed5 id_40 { make_fst_72, make_snd_73 };
      letpair_res_39 = id_40;
    }
    return letpair_res_39;
  }
   };
  return fun23;
}
std::function<::dessser::gen::raql_flush_method::tb3a89096758ec6cf20bf4ee069398ed5(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
