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

namespace dessser::gen::raql_ip_protocol {
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
  Void, // UDP
  Void // TCP
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // UDP
    case 1: return std::get<1>(a) == std::get<1>(b); // TCP
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t6c8e59c4c22b0ccb6b646b9799fa9367 : public std::tuple<
  std::shared_ptr<::dessser::gen::raql_ip_protocol::t> ,
  Pointer
> {
  using tuple::tuple;
  t6c8e59c4c22b0ccb6b646b9799fa9367(std::tuple<std::shared_ptr<::dessser::gen::raql_ip_protocol::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::raql_ip_protocol::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6c8e59c4c22b0ccb6b646b9799fa9367 const &a, t6c8e59c4c22b0ccb6b646b9799fa9367 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6c8e59c4c22b0ccb6b646b9799fa9367 const &a, t6c8e59c4c22b0ccb6b646b9799fa9367 const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[UDP Void | TCP Void]" "Ptr")
      (let "ssum_dst_77" (write-u16 little-endian (param 1) (label-of (param 0))) (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_77") (seq (assert (eq (label-of (param 0)) (u16 1))) (identifier "ssum_dst_77")))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::raql_ip_protocol::t>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_77 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        choose_res_7 = ssum_dst_77;
      } else {
        uint16_t id_8 { uint16_t((*p_0).index()) };
        uint16_t id_9 { 1 };
        bool id_10 { bool(id_8 == id_9) };
        Void id_11 { ((void)(assert(id_10)), ::dessser::Void()) };
        (void)id_11;
        choose_res_7 = ssum_dst_77;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[UDP Void | TCP Void]") (if (eq (u16 0) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 1))) (size 2))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> )> fun12 { [&](std::shared_ptr<::dessser::gen::raql_ip_protocol::t>  p_0) {
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
      Void id_21 { ((void)(assert(id_20)), ::dessser::Void()) };
      (void)id_21;
      Size id_22 { 2UL };
      choose_res_16 = id_22;
    }
    return choose_res_16;
  }
   };
  return fun12;
}
std::function<Size(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64")) (make-tup (construct "[UDP Void | TCP Void]" 0 (nop)) (identifier "dsum1_snd_65"))
            (seq (assert (eq (identifier "dsum1_fst_64") (u16 1))) (make-tup (construct "[UDP Void | TCP Void]" 1 (nop)) (identifier "dsum1_snd_65")))))))
 */
static std::function<::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367(Pointer)> fun23 { [&](Pointer p_0) {
    ::dessser::gen::raql_ip_protocol::ta97bb48ed75bbda6173555873826c8c6 id_24 { p_0.readU16Le() };
    ::dessser::gen::raql_ip_protocol::ta97bb48ed75bbda6173555873826c8c6 letpair_res_25;
    {
      auto du16_fst_58 { std::get<0>(id_24) };
      auto du16_snd_59 { std::get<1>(id_24) };
      ::dessser::gen::raql_ip_protocol::ta97bb48ed75bbda6173555873826c8c6 id_26 { du16_fst_58, du16_snd_59 };
      letpair_res_25 = id_26;
    }
    ::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367 let_res_27;
    {
      ::dessser::gen::raql_ip_protocol::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_25 };
      ::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367 letpair_res_28;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_29 { 0 };
        bool id_30 { bool(id_29 == dsum1_fst_64) };
        ::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367 choose_res_31;
        if (id_30) {
          (void)::dessser::Void();
          std::shared_ptr<::dessser::gen::raql_ip_protocol::t>  id_32 { std::make_shared<::dessser::gen::raql_ip_protocol::t>(std::in_place_index<0>, ::dessser::Void()) };
          ::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367 id_33 { id_32, dsum1_snd_65 };
          choose_res_31 = id_33;
        } else {
          uint16_t id_34 { 1 };
          bool id_35 { bool(dsum1_fst_64 == id_34) };
          Void id_36 { ((void)(assert(id_35)), ::dessser::Void()) };
          (void)id_36;
          (void)::dessser::Void();
          std::shared_ptr<::dessser::gen::raql_ip_protocol::t>  id_37 { std::make_shared<::dessser::gen::raql_ip_protocol::t>(std::in_place_index<1>, ::dessser::Void()) };
          ::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367 id_38 { id_37, dsum1_snd_65 };
          choose_res_31 = id_38;
        }
        letpair_res_28 = choose_res_31;
      }
      let_res_27 = letpair_res_28;
    }
    return let_res_27;
  }
   };
  return fun23;
}
std::function<::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_73" "make_snd_74" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_73") (identifier "make_snd_74"))))
 */
static std::function<::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367(Pointer)> fun39 { [&](Pointer p_0) {
    ::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367 id_40 { of_row_binary(p_0) };
    ::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367 letpair_res_41;
    {
      auto make_fst_73 { std::get<0>(id_40) };
      auto make_snd_74 { std::get<1>(id_40) };
      ::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367 id_42 { make_fst_73, make_snd_74 };
      letpair_res_41 = id_42;
    }
    return letpair_res_41;
  }
   };
  return fun39;
}
std::function<::dessser::gen::raql_ip_protocol::t6c8e59c4c22b0ccb6b646b9799fa9367(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[UDP Void | TCP Void]" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> ,Pointer)> fun43 { [&](std::shared_ptr<::dessser::gen::raql_ip_protocol::t>  p_0, Pointer p_1) {
    Pointer id_44 { to_row_binary(p_0, p_1) };
    return id_44;
  }
   };
  return fun43;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::raql_ip_protocol::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
