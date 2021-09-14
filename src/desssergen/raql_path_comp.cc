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
#include "desssergen/field_name.h"


namespace dessser::gen::raql_path_comp {
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
  uint32_t, // Idx
  dessser::gen::field_name::t_ext // Name
> { using variant::variant; };

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Idx
    case 1: return ::dessser::gen::field_name::Deref(std::get<1>(a)) == ::dessser::gen::field_name::Deref(std::get<1>(b)); // Name
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t69fcb450dd02dd92e601786a5f958b40 : public std::tuple<
  ::dessser::gen::raql_path_comp::t*,
  Pointer
> {
  using tuple::tuple;
  t69fcb450dd02dd92e601786a5f958b40(std::tuple<::dessser::gen::raql_path_comp::t*, Pointer> p)
    : std::tuple<::dessser::gen::raql_path_comp::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t69fcb450dd02dd92e601786a5f958b40 const &a, t69fcb450dd02dd92e601786a5f958b40 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t69fcb450dd02dd92e601786a5f958b40 const &a, t69fcb450dd02dd92e601786a5f958b40 const &b) {
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
struct tacdfdbd490062d58073ca57b70932e6d : public std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tacdfdbd490062d58073ca57b70932e6d(std::tuple<dessser::gen::field_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::field_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tacdfdbd490062d58073ca57b70932e6d const &a, tacdfdbd490062d58073ca57b70932e6d const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tacdfdbd490062d58073ca57b70932e6d const &a, tacdfdbd490062d58073ca57b70932e6d const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Idx U32 | Name $field_name]" "Ptr")
      (let "ssum_dst_79" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (write-u32 little-endian (identifier "ssum_dst_79") (get-alt "Idx" (param 0)))
          (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (ext-identifier field_name to-row-binary) (get-alt "Name" (param 0)) (identifier "ssum_dst_79"))))))
 */
static std::function<Pointer(::dessser::gen::raql_path_comp::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_path_comp::t*,Pointer)> fun0 { [&fun0](::dessser::gen::raql_path_comp::t* p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_79 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        uint32_t id_8 { std::get<0 /* Idx */>((*p_0)) };
        Pointer id_9 { ssum_dst_79.writeU32Le(id_8) };
        choose_res_7 = id_9;
      } else {
        uint16_t id_10 { uint16_t((*p_0).index()) };
        uint16_t id_11 { 1 };
        bool id_12 { bool(id_10 == id_11) };
        Void id_13 { ((void)(assert(id_12)), VOID) };
        (void)id_13;
        auto fun14 { dessser::gen::field_name::to_row_binary };
        dessser::gen::field_name::t_ext id_15 { std::get<1 /* Name */>((*p_0)) };
        Pointer id_16 { fun14(id_15, ssum_dst_79) };
        choose_res_7 = id_16;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::raql_path_comp::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Idx U32 | Name $field_name]")
      (if (eq (u16 0) (label-of (param 0))) (size 6) (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (ext-identifier field_name sersize-of-row-binary) (get-alt "Name" (param 0)))))))
 */
static std::function<Size(::dessser::gen::raql_path_comp::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_path_comp::t*)> fun17 { [&fun17](::dessser::gen::raql_path_comp::t* p_0) {
    uint16_t id_18 { 0 };
    uint16_t id_19 { uint16_t((*p_0).index()) };
    bool id_20 { bool(id_18 == id_19) };
    Size choose_res_21;
    if (id_20) {
      Size id_22 { 6UL };
      choose_res_21 = id_22;
    } else {
      uint16_t id_23 { uint16_t((*p_0).index()) };
      uint16_t id_24 { 1 };
      bool id_25 { bool(id_23 == id_24) };
      Void id_26 { ((void)(assert(id_25)), VOID) };
      (void)id_26;
      Size id_27 { 2UL };
      auto fun28 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t_ext id_29 { std::get<1 /* Name */>((*p_0)) };
      Size id_30 { fun28(id_29) };
      Size id_31 { Size(id_27 + id_30) };
      choose_res_21 = id_31;
    }
    return choose_res_21;
  }
   };
  return fun17;
}
std::function<Size(::dessser::gen::raql_path_comp::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_75" "make_snd_76"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let-pair "du32_fst_69" "du32_snd_70" (read-u32 little-endian (identifier "dsum1_snd_64")) (make-tup (construct "[Idx U32 | Name $field_name]" 0 (identifier "du32_fst_69")) (identifier "du32_snd_70")))
              (seq (assert (eq (identifier "dsum1_fst_63") (u16 1)))
                (let-pair "dsum2_fst_66" "dsum2_snd_67" (apply (ext-identifier field_name of-row-binary) (identifier "dsum1_snd_64"))
                  (make-tup (construct "[Idx U32 | Name $field_name]" 1 (identifier "dsum2_fst_66")) (identifier "dsum2_snd_67"))))))) 
        (make-tup (identifier "make_fst_75") (identifier "make_snd_76"))))
 */
static std::function<::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40(Pointer)> fun32 { [&fun32](Pointer p_0) {
    ::dessser::gen::raql_path_comp::t7609d344c1ba69d0f80fec236d4c216b id_33 { p_0.readU16Le() };
    ::dessser::gen::raql_path_comp::t7609d344c1ba69d0f80fec236d4c216b letpair_res_34;
    {
      auto du16_fst_57 { std::get<0>(id_33) };
      auto du16_snd_58 { std::get<1>(id_33) };
      ::dessser::gen::raql_path_comp::t7609d344c1ba69d0f80fec236d4c216b id_35 { du16_fst_57, du16_snd_58 };
      letpair_res_34 = id_35;
    }
    ::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40 let_res_36;
    {
      ::dessser::gen::raql_path_comp::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_34 };
      ::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40 letpair_res_37;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_38 { 0 };
        bool id_39 { bool(id_38 == dsum1_fst_63) };
        ::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40 choose_res_40;
        if (id_39) {
          ::dessser::gen::raql_path_comp::t883c6ffea47c0d7b950fe35881e3d737 id_41 { dsum1_snd_64.readU32Le() };
          ::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40 letpair_res_42;
          {
            auto du32_fst_69 { std::get<0>(id_41) };
            auto du32_snd_70 { std::get<1>(id_41) };
            ::dessser::gen::raql_path_comp::t* id_43 { new ::dessser::gen::raql_path_comp::t(std::in_place_index<0>, du32_fst_69) };
            ::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40 id_44 { id_43, du32_snd_70 };
            letpair_res_42 = id_44;
          }
          choose_res_40 = letpair_res_42;
        } else {
          uint16_t id_45 { 1 };
          bool id_46 { bool(dsum1_fst_63 == id_45) };
          Void id_47 { ((void)(assert(id_46)), VOID) };
          (void)id_47;
          auto fun48 { dessser::gen::field_name::of_row_binary };
          ::dessser::gen::raql_path_comp::tacdfdbd490062d58073ca57b70932e6d id_49 { fun48(dsum1_snd_64) };
          ::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40 letpair_res_50;
          {
            auto dsum2_fst_66 { std::get<0>(id_49) };
            auto dsum2_snd_67 { std::get<1>(id_49) };
            ::dessser::gen::raql_path_comp::t* id_51 { new ::dessser::gen::raql_path_comp::t(std::in_place_index<1>, dsum2_fst_66) };
            ::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40 id_52 { id_51, dsum2_snd_67 };
            letpair_res_50 = id_52;
          }
          choose_res_40 = letpair_res_50;
        }
        letpair_res_37 = choose_res_40;
      }
      let_res_36 = letpair_res_37;
    }
    ::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40 letpair_res_53;
    {
      auto make_fst_75 { std::get<0>(let_res_36) };
      auto make_snd_76 { std::get<1>(let_res_36) };
      ::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40 id_54 { make_fst_75, make_snd_76 };
      letpair_res_53 = id_54;
    }
    return letpair_res_53;
  }
   };
  return fun32;
}
std::function<::dessser::gen::raql_path_comp::t69fcb450dd02dd92e601786a5f958b40(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}