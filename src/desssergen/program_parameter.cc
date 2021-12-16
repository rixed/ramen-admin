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
#include "desssergen/raql_value.h"
#include "desssergen/units.h"
#include "desssergen/raql_type.h"
#include "desssergen/field_name.h"

namespace dessser::gen::program_parameter {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t {
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_type::t_ext typ;
  std::optional<dessser::gen::units::t_ext> units;
  std::string doc;
  dessser::gen::raql_value::t_ext value;
  t(dessser::gen::field_name::t_ext name_, dessser::gen::raql_type::t_ext typ_, std::optional<dessser::gen::units::t_ext> units_, std::string doc_, dessser::gen::raql_value::t_ext value_) : name(name_), typ(typ_), units(units_), doc(doc_), value(value_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ) && ((a.units && b.units && ::dessser::gen::units::Deref(a.units.value()) == ::dessser::gen::units::Deref(b.units.value())) || (!a.units && !b.units)) && a.doc == b.doc && ::dessser::gen::raql_value::Deref(a.value) == ::dessser::gen::raql_value::Deref(b.value);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tb6711e674917c07d8a108a1cb42aa8d4 : public std::tuple<
  std::shared_ptr<::dessser::gen::program_parameter::t> ,
  Pointer
> {
  using tuple::tuple;
  tb6711e674917c07d8a108a1cb42aa8d4(std::tuple<std::shared_ptr<::dessser::gen::program_parameter::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::program_parameter::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb6711e674917c07d8a108a1cb42aa8d4 const &a, tb6711e674917c07d8a108a1cb42aa8d4 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb6711e674917c07d8a108a1cb42aa8d4 const &a, tb6711e674917c07d8a108a1cb42aa8d4 const &b) {
  return !operator==(a, b);
}
struct t18cecf882d7ac80cef37dfe6b22279d4 : public std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t18cecf882d7ac80cef37dfe6b22279d4(std::tuple<dessser::gen::field_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::field_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t18cecf882d7ac80cef37dfe6b22279d4 const &a, t18cecf882d7ac80cef37dfe6b22279d4 const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t18cecf882d7ac80cef37dfe6b22279d4 const &a, t18cecf882d7ac80cef37dfe6b22279d4 const &b) {
  return !operator==(a, b);
}
struct t101502ffd7fb38beafe4b49259f92ba1 : public std::tuple<
  dessser::gen::raql_type::t_ext,
  Pointer
> {
  using tuple::tuple;
  t101502ffd7fb38beafe4b49259f92ba1(std::tuple<dessser::gen::raql_type::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_type::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t101502ffd7fb38beafe4b49259f92ba1 const &a, t101502ffd7fb38beafe4b49259f92ba1 const &b) {
  return ::dessser::gen::raql_type::Deref(std::get<0>(a)) == ::dessser::gen::raql_type::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t101502ffd7fb38beafe4b49259f92ba1 const &a, t101502ffd7fb38beafe4b49259f92ba1 const &b) {
  return !operator==(a, b);
}
struct t096d6a0956a2df6dec7d0945ab177a4b : public std::tuple<
  std::optional<dessser::gen::units::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t096d6a0956a2df6dec7d0945ab177a4b(std::tuple<std::optional<dessser::gen::units::t_ext>, Pointer> p)
    : std::tuple<std::optional<dessser::gen::units::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t096d6a0956a2df6dec7d0945ab177a4b const &a, t096d6a0956a2df6dec7d0945ab177a4b const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && ::dessser::gen::units::Deref(std::get<0>(a).value()) == ::dessser::gen::units::Deref(std::get<0>(b).value())) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t096d6a0956a2df6dec7d0945ab177a4b const &a, t096d6a0956a2df6dec7d0945ab177a4b const &b) {
  return !operator==(a, b);
}
struct tdcd8238b20249643ff5b5f9a7648e226 : public std::tuple<
  dessser::gen::units::t_ext,
  Pointer
> {
  using tuple::tuple;
  tdcd8238b20249643ff5b5f9a7648e226(std::tuple<dessser::gen::units::t_ext, Pointer> p)
    : std::tuple<dessser::gen::units::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tdcd8238b20249643ff5b5f9a7648e226 const &a, tdcd8238b20249643ff5b5f9a7648e226 const &b) {
  return ::dessser::gen::units::Deref(std::get<0>(a)) == ::dessser::gen::units::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tdcd8238b20249643ff5b5f9a7648e226 const &a, tdcd8238b20249643ff5b5f9a7648e226 const &b) {
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
struct tf3063cfb73e0f06d3ea99ebd15a86d50 : public std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> {
  using tuple::tuple;
  tf3063cfb73e0f06d3ea99ebd15a86d50(std::tuple<dessser::gen::raql_value::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_value::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf3063cfb73e0f06d3ea99ebd15a86d50 const &a, tf3063cfb73e0f06d3ea99ebd15a86d50 const &b) {
  return ::dessser::gen::raql_value::Deref(std::get<0>(a)) == ::dessser::gen::raql_value::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf3063cfb73e0f06d3ea99ebd15a86d50 const &a, tf3063cfb73e0f06d3ea99ebd15a86d50 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{name: $field_name; typ: $raql_type; units: $units?; doc: STRING; value: $raql_value}" "Ptr")
      (let "srec_dst_102"
        (let "srec_dst_99"
          (let "srec_dst_98"
            (let "srec_dst_97" (apply (ext-identifier field_name to-row-binary) (get-field "name" (param 0)) (param 1)) (apply (ext-identifier raql_type to-row-binary) (get-field "typ" (param 0)) (identifier "srec_dst_97")))
            (if (is-null (get-field "units" (param 0))) (write-u8 (identifier "srec_dst_98") (u8 1)) (apply (ext-identifier units to-row-binary) (force (get-field "units" (param 0))) (write-u8 (identifier "srec_dst_98") (u8 0)))))
          (write-bytes
            (let "leb128_sz_100" (make-vec (string-length (get-field "doc" (param 0))))
              (let "leb128_ptr_101" (make-vec (identifier "srec_dst_99"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_101")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_101"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_100"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_100"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_100"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_100") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_100")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_100")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_101"))))) 
            (bytes-of-string (get-field "doc" (param 0))))) (apply (ext-identifier raql_value to-row-binary) (get-field "value" (param 0)) (identifier "srec_dst_102"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::program_parameter::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::program_parameter::t> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::program_parameter::t>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::field_name::to_row_binary };
    dessser::gen::field_name::t_ext id_2 { (*p_0).name };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_97 { id_3 };
      auto fun5 { dessser::gen::raql_type::to_row_binary };
      dessser::gen::raql_type::t_ext id_6 { (*p_0).typ };
      Pointer id_7 { fun5(id_6, srec_dst_97) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_98 { let_res_4 };
      std::optional<dessser::gen::units::t_ext> id_9 { (*p_0).units };
      bool id_10 { !(id_9.has_value ()) };
      Pointer choose_res_11;
      if (id_10) {
        uint8_t id_12 { 1 };
        Pointer id_13 { srec_dst_98.writeU8(id_12) };
        choose_res_11 = id_13;
      } else {
        auto fun14 { dessser::gen::units::to_row_binary };
        std::optional<dessser::gen::units::t_ext> id_15 { (*p_0).units };
        dessser::gen::units::t_ext id_16 { id_15.value() };
        uint8_t id_17 { 0 };
        Pointer id_18 { srec_dst_98.writeU8(id_17) };
        Pointer id_19 { fun14(id_16, id_18) };
        choose_res_11 = id_19;
      }
      let_res_8 = choose_res_11;
    }
    Pointer let_res_20;
    {
      Pointer srec_dst_99 { let_res_8 };
      std::string id_21 { (*p_0).doc };
      uint32_t id_22 { (uint32_t)id_21.size() };
      Vec<1, uint32_t> id_23 {  id_22  };
      Pointer let_res_24;
      {
        Vec<1, uint32_t> leb128_sz_100 { id_23 };
        Vec<1, Pointer> id_25 {  srec_dst_99  };
        Pointer let_res_26;
        {
          Vec<1, Pointer> leb128_ptr_101 { id_25 };
          bool while_flag_27 { true };
          do {
            uint8_t id_28 { 0 };
            uint8_t id_29 { 0 };
            Pointer id_30 { leb128_ptr_101[id_29] };
            uint32_t id_31 { 128U };
            uint8_t id_32 { 0 };
            uint32_t id_33 { leb128_sz_100[id_32] };
            bool id_34 { bool(id_31 > id_33) };
            uint8_t choose_res_35;
            if (id_34) {
              uint8_t id_36 { 0 };
              uint32_t id_37 { leb128_sz_100[id_36] };
              uint8_t id_38 { uint8_t(id_37) };
              choose_res_35 = id_38;
            } else {
              uint8_t id_39 { 0 };
              uint32_t id_40 { leb128_sz_100[id_39] };
              uint8_t id_41 { uint8_t(id_40) };
              uint8_t id_42 { 128 };
              uint8_t id_43 { uint8_t(id_41 | id_42) };
              choose_res_35 = id_43;
            }
            Pointer id_44 { id_30.writeU8(choose_res_35) };
            Void id_45 { ((void)(leb128_ptr_101[id_28] = id_44), ::dessser::VOID) };
            (void)id_45;
            uint8_t id_46 { 0 };
            uint8_t id_47 { 0 };
            uint32_t id_48 { leb128_sz_100[id_47] };
            uint8_t id_49 { 7 };
            uint32_t id_50 { uint32_t(id_48 >> id_49) };
            Void id_51 { ((void)(leb128_sz_100[id_46] = id_50), ::dessser::VOID) };
            (void)id_51;
            uint8_t id_52 { 0 };
            uint32_t id_53 { leb128_sz_100[id_52] };
            uint32_t id_54 { 0U };
            bool id_55 { bool(id_53 > id_54) };
            while_flag_27 = id_55;
            if (while_flag_27) {
              (void)::dessser::VOID;
            }
          } while (while_flag_27);
          (void)::dessser::VOID;
          uint8_t id_56 { 0 };
          Pointer id_57 { leb128_ptr_101[id_56] };
          let_res_26 = id_57;
        }
        let_res_24 = let_res_26;
      }
      std::string id_58 { (*p_0).doc };
      Bytes id_59 { id_58 };
      Pointer id_60 { let_res_24.writeBytes(id_59) };
      let_res_20 = id_60;
    }
    Pointer let_res_61;
    {
      Pointer srec_dst_102 { let_res_20 };
      auto fun62 { dessser::gen::raql_value::to_row_binary };
      dessser::gen::raql_value::t_ext id_63 { (*p_0).value };
      Pointer id_64 { fun62(id_63, srec_dst_102) };
      let_res_61 = id_64;
    }
    return let_res_61;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::program_parameter::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{name: $field_name; typ: $raql_type; units: $units?; doc: STRING; value: $raql_value}")
      (let "sz_96"
        (let "sz_92"
          (let "sz_91"
            (let "sz_90" (apply (ext-identifier field_name sersize-of-row-binary) (get-field "name" (param 0))) (add (identifier "sz_90") (apply (ext-identifier raql_type sersize-of-row-binary) (get-field "typ" (param 0)))))
            (if (is-null (get-field "units" (param 0))) (add (identifier "sz_91") (size 1)) (add (add (identifier "sz_91") (apply (ext-identifier units sersize-of-row-binary) (force (get-field "units" (param 0))))) (size 1))))
          (add (identifier "sz_92")
            (add
              (let "n_ref_94" (make-vec (string-length (get-field "doc" (param 0))))
                (let "lebsz_ref_95" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_94")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_95")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_95") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_95")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_95")))))) 
              (size-of-u32 (string-length (get-field "doc" (param 0))))))) 
        (add (identifier "sz_96") (apply (ext-identifier raql_value sersize-of-row-binary) (get-field "value" (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::program_parameter::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::program_parameter::t> )> fun65 { [&fun65](std::shared_ptr<::dessser::gen::program_parameter::t>  p_0) {
    auto fun66 { dessser::gen::field_name::sersize_of_row_binary };
    dessser::gen::field_name::t_ext id_67 { (*p_0).name };
    Size id_68 { fun66(id_67) };
    Size let_res_69;
    {
      Size sz_90 { id_68 };
      auto fun70 { dessser::gen::raql_type::sersize_of_row_binary };
      dessser::gen::raql_type::t_ext id_71 { (*p_0).typ };
      Size id_72 { fun70(id_71) };
      Size id_73 { Size(sz_90 + id_72) };
      let_res_69 = id_73;
    }
    Size let_res_74;
    {
      Size sz_91 { let_res_69 };
      std::optional<dessser::gen::units::t_ext> id_75 { (*p_0).units };
      bool id_76 { !(id_75.has_value ()) };
      Size choose_res_77;
      if (id_76) {
        Size id_78 { 1UL };
        Size id_79 { Size(sz_91 + id_78) };
        choose_res_77 = id_79;
      } else {
        auto fun80 { dessser::gen::units::sersize_of_row_binary };
        std::optional<dessser::gen::units::t_ext> id_81 { (*p_0).units };
        dessser::gen::units::t_ext id_82 { id_81.value() };
        Size id_83 { fun80(id_82) };
        Size id_84 { Size(sz_91 + id_83) };
        Size id_85 { 1UL };
        Size id_86 { Size(id_84 + id_85) };
        choose_res_77 = id_86;
      }
      let_res_74 = choose_res_77;
    }
    Size let_res_87;
    {
      Size sz_92 { let_res_74 };
      std::string id_88 { (*p_0).doc };
      uint32_t id_89 { (uint32_t)id_88.size() };
      Vec<1, uint32_t> id_90 {  id_89  };
      Size let_res_91;
      {
        Vec<1, uint32_t> n_ref_94 { id_90 };
        uint32_t id_92 { 1U };
        Vec<1, uint32_t> id_93 {  id_92  };
        Size let_res_94;
        {
          Vec<1, uint32_t> lebsz_ref_95 { id_93 };
          bool while_flag_95 { true };
          do {
            uint8_t id_96 { 0 };
            uint32_t id_97 { n_ref_94[id_96] };
            uint8_t id_98 { 0 };
            uint32_t id_99 { lebsz_ref_95[id_98] };
            uint8_t id_100 { 7 };
            uint32_t id_101 { uint32_t(id_99 << id_100) };
            bool id_102 { bool(id_97 >= id_101) };
            while_flag_95 = id_102;
            if (while_flag_95) {
              uint8_t id_103 { 0 };
              uint8_t id_104 { 0 };
              uint32_t id_105 { lebsz_ref_95[id_104] };
              uint32_t id_106 { 1U };
              uint32_t id_107 { uint32_t(id_105 + id_106) };
              Void id_108 { ((void)(lebsz_ref_95[id_103] = id_107), ::dessser::VOID) };
              (void)id_108;
            }
          } while (while_flag_95);
          (void)::dessser::VOID;
          uint8_t id_109 { 0 };
          uint32_t id_110 { lebsz_ref_95[id_109] };
          Size id_111 { Size(id_110) };
          let_res_94 = id_111;
        }
        let_res_91 = let_res_94;
      }
      std::string id_112 { (*p_0).doc };
      uint32_t id_113 { (uint32_t)id_112.size() };
      Size id_114 { Size(id_113) };
      Size id_115 { Size(let_res_91 + id_114) };
      Size id_116 { Size(sz_92 + id_115) };
      let_res_87 = id_116;
    }
    Size let_res_117;
    {
      Size sz_96 { let_res_87 };
      auto fun118 { dessser::gen::raql_value::sersize_of_row_binary };
      dessser::gen::raql_value::t_ext id_119 { (*p_0).value };
      Size id_120 { fun118(id_119) };
      Size id_121 { Size(sz_96 + id_120) };
      let_res_117 = id_121;
    }
    return let_res_117;
  }
   };
  return fun65;
}
std::function<Size(std::shared_ptr<::dessser::gen::program_parameter::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier field_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_59" (apply (ext-identifier raql_type of-row-binary) (identifier "drec_snd_58"))
            (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
              (let "drec_65"
                (if (eq (peek-u8 (identifier "drec_snd_61") (size 0)) (u8 1)) 
                  (make-tup (null "$units") (ptr-add (identifier "drec_snd_61") (size 1)))
                  (let-pair "make1_1_fst_63" "make1_1_snd_64" (apply (ext-identifier units of-row-binary) (ptr-add (identifier "drec_snd_61") (size 1)))
                    (make-tup (not-null (identifier "make1_1_fst_63")) (identifier "make1_1_snd_64"))))
                (let-pair "drec_fst_66" "drec_snd_67" (identifier "drec_65")
                  (let "drec_80"
                    (let "dstring1_74"
                      (let "leb_ref_68" (make-vec (u32 0))
                        (let "shft_ref_69" (make-vec (u8 0))
                          (let "p_ref_70" (make-vec (identifier "drec_snd_67"))
                            (seq
                              (while
                                (let "leb128_71" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_70")))
                                  (let-pair "leb128_fst_72" "leb128_snd_73" 
                                    (identifier "leb128_71")
                                    (seq (set-vec (u8 0) (identifier "p_ref_70") (identifier "leb128_snd_73"))
                                      (set-vec (u8 0) (identifier "leb_ref_68")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_72") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_69"))) (unsafe-nth (u8 0) (identifier "leb_ref_68"))))
                                      (set-vec (u8 0) (identifier "shft_ref_69") (add (unsafe-nth (u8 0) (identifier "shft_ref_69")) (u8 7))) 
                                      (ge (identifier "leb128_fst_72") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_68"))) (unsafe-nth (u8 0) (identifier "p_ref_70")))))))
                      (let-pair "dstring1_fst_75" "dstring1_snd_76" (identifier "dstring1_74")
                        (let-pair "dstring2_fst_78" "dstring2_snd_79" 
                          (read-bytes (identifier "dstring1_snd_76") (identifier "dstring1_fst_75")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_78")) (identifier "dstring2_snd_79")))))
                    (let-pair "drec_fst_81" "drec_snd_82" (identifier "drec_80")
                      (let-pair "drec_fst_84" "drec_snd_85" (apply (ext-identifier raql_value of-row-binary) (identifier "drec_snd_82"))
                        (make-tup
                          (make-rec (string "value") (identifier "drec_fst_84") 
                            (string "doc") (identifier "drec_fst_81") 
                            (string "units") (identifier "drec_fst_66") 
                            (string "typ") (identifier "drec_fst_60") 
                            (string "name") (identifier "drec_fst_57")) 
                          (identifier "drec_snd_85"))))))))))))
 */
static std::function<::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4(Pointer)> fun122 { [&fun122](Pointer p_0) {
    auto fun123 { dessser::gen::field_name::of_row_binary };
    ::dessser::gen::program_parameter::t18cecf882d7ac80cef37dfe6b22279d4 id_124 { fun123(p_0) };
    ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 let_res_125;
    {
      ::dessser::gen::program_parameter::t18cecf882d7ac80cef37dfe6b22279d4 drec_56 { id_124 };
      ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 letpair_res_126;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        auto fun127 { dessser::gen::raql_type::of_row_binary };
        ::dessser::gen::program_parameter::t101502ffd7fb38beafe4b49259f92ba1 id_128 { fun127(drec_snd_58) };
        ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 let_res_129;
        {
          ::dessser::gen::program_parameter::t101502ffd7fb38beafe4b49259f92ba1 drec_59 { id_128 };
          ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 letpair_res_130;
          {
            auto drec_fst_60 { std::get<0>(drec_59) };
            auto drec_snd_61 { std::get<1>(drec_59) };
            Size id_131 { 0UL };
            uint8_t id_132 { drec_snd_61.peekU8(id_131) };
            uint8_t id_133 { 1 };
            bool id_134 { bool(id_132 == id_133) };
            ::dessser::gen::program_parameter::t096d6a0956a2df6dec7d0945ab177a4b choose_res_135;
            if (id_134) {
              std::optional<dessser::gen::units::t_ext> id_136 { std::nullopt };
              Size id_137 { 1UL };
              Pointer id_138 { drec_snd_61.skip(id_137) };
              ::dessser::gen::program_parameter::t096d6a0956a2df6dec7d0945ab177a4b id_139 { id_136, id_138 };
              choose_res_135 = id_139;
            } else {
              auto fun140 { dessser::gen::units::of_row_binary };
              Size id_141 { 1UL };
              Pointer id_142 { drec_snd_61.skip(id_141) };
              ::dessser::gen::program_parameter::tdcd8238b20249643ff5b5f9a7648e226 id_143 { fun140(id_142) };
              ::dessser::gen::program_parameter::t096d6a0956a2df6dec7d0945ab177a4b letpair_res_144;
              {
                auto make1_1_fst_63 { std::get<0>(id_143) };
                auto make1_1_snd_64 { std::get<1>(id_143) };
                std::optional<dessser::gen::units::t_ext> id_145 { make1_1_fst_63 };
                ::dessser::gen::program_parameter::t096d6a0956a2df6dec7d0945ab177a4b id_146 { id_145, make1_1_snd_64 };
                letpair_res_144 = id_146;
              }
              choose_res_135 = letpair_res_144;
            }
            ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 let_res_147;
            {
              ::dessser::gen::program_parameter::t096d6a0956a2df6dec7d0945ab177a4b drec_65 { choose_res_135 };
              ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 letpair_res_148;
              {
                auto drec_fst_66 { std::get<0>(drec_65) };
                auto drec_snd_67 { std::get<1>(drec_65) };
                uint32_t id_149 { 0U };
                Vec<1, uint32_t> id_150 {  id_149  };
                ::dessser::gen::program_parameter::t12fb9c475959b52bf7b17b155a955ffa let_res_151;
                {
                  Vec<1, uint32_t> leb_ref_68 { id_150 };
                  uint8_t id_152 { 0 };
                  Vec<1, uint8_t> id_153 {  id_152  };
                  ::dessser::gen::program_parameter::t12fb9c475959b52bf7b17b155a955ffa let_res_154;
                  {
                    Vec<1, uint8_t> shft_ref_69 { id_153 };
                    Vec<1, Pointer> id_155 {  drec_snd_67  };
                    ::dessser::gen::program_parameter::t12fb9c475959b52bf7b17b155a955ffa let_res_156;
                    {
                      Vec<1, Pointer> p_ref_70 { id_155 };
                      bool while_flag_157 { true };
                      do {
                        uint8_t id_158 { 0 };
                        Pointer id_159 { p_ref_70[id_158] };
                        ::dessser::gen::program_parameter::t1a5d74abf838df33f185a72a8912f5c9 id_160 { id_159.readU8() };
                        bool let_res_161;
                        {
                          ::dessser::gen::program_parameter::t1a5d74abf838df33f185a72a8912f5c9 leb128_71 { id_160 };
                          bool letpair_res_162;
                          {
                            auto leb128_fst_72 { std::get<0>(leb128_71) };
                            auto leb128_snd_73 { std::get<1>(leb128_71) };
                            uint8_t id_163 { 0 };
                            Void id_164 { ((void)(p_ref_70[id_163] = leb128_snd_73), ::dessser::VOID) };
                            (void)id_164;
                            uint8_t id_165 { 0 };
                            uint8_t id_166 { 127 };
                            uint8_t id_167 { uint8_t(leb128_fst_72 & id_166) };
                            uint32_t id_168 { uint32_t(id_167) };
                            uint8_t id_169 { 0 };
                            uint8_t id_170 { shft_ref_69[id_169] };
                            uint32_t id_171 { uint32_t(id_168 << id_170) };
                            uint8_t id_172 { 0 };
                            uint32_t id_173 { leb_ref_68[id_172] };
                            uint32_t id_174 { uint32_t(id_171 | id_173) };
                            Void id_175 { ((void)(leb_ref_68[id_165] = id_174), ::dessser::VOID) };
                            (void)id_175;
                            uint8_t id_176 { 0 };
                            uint8_t id_177 { 0 };
                            uint8_t id_178 { shft_ref_69[id_177] };
                            uint8_t id_179 { 7 };
                            uint8_t id_180 { uint8_t(id_178 + id_179) };
                            Void id_181 { ((void)(shft_ref_69[id_176] = id_180), ::dessser::VOID) };
                            (void)id_181;
                            uint8_t id_182 { 128 };
                            bool id_183 { bool(leb128_fst_72 >= id_182) };
                            letpair_res_162 = id_183;
                          }
                          let_res_161 = letpair_res_162;
                        }
                        while_flag_157 = let_res_161;
                        if (while_flag_157) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_157);
                      (void)::dessser::VOID;
                      uint8_t id_184 { 0 };
                      uint32_t id_185 { leb_ref_68[id_184] };
                      Size id_186 { Size(id_185) };
                      uint8_t id_187 { 0 };
                      Pointer id_188 { p_ref_70[id_187] };
                      ::dessser::gen::program_parameter::t12fb9c475959b52bf7b17b155a955ffa id_189 { id_186, id_188 };
                      let_res_156 = id_189;
                    }
                    let_res_154 = let_res_156;
                  }
                  let_res_151 = let_res_154;
                }
                ::dessser::gen::program_parameter::t13a07ee37ab40962540da8534858dc07 let_res_190;
                {
                  ::dessser::gen::program_parameter::t12fb9c475959b52bf7b17b155a955ffa dstring1_74 { let_res_151 };
                  ::dessser::gen::program_parameter::t13a07ee37ab40962540da8534858dc07 letpair_res_191;
                  {
                    auto dstring1_fst_75 { std::get<0>(dstring1_74) };
                    auto dstring1_snd_76 { std::get<1>(dstring1_74) };
                    ::dessser::gen::program_parameter::t9ef6882174ae71a34a3c5ef6b29242fb id_192 { dstring1_snd_76.readBytes(dstring1_fst_75) };
                    ::dessser::gen::program_parameter::t13a07ee37ab40962540da8534858dc07 letpair_res_193;
                    {
                      auto dstring2_fst_78 { std::get<0>(id_192) };
                      auto dstring2_snd_79 { std::get<1>(id_192) };
                      std::string id_194 { dstring2_fst_78.toString() };
                      ::dessser::gen::program_parameter::t13a07ee37ab40962540da8534858dc07 id_195 { id_194, dstring2_snd_79 };
                      letpair_res_193 = id_195;
                    }
                    letpair_res_191 = letpair_res_193;
                  }
                  let_res_190 = letpair_res_191;
                }
                ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 let_res_196;
                {
                  ::dessser::gen::program_parameter::t13a07ee37ab40962540da8534858dc07 drec_80 { let_res_190 };
                  ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 letpair_res_197;
                  {
                    auto drec_fst_81 { std::get<0>(drec_80) };
                    auto drec_snd_82 { std::get<1>(drec_80) };
                    auto fun198 { dessser::gen::raql_value::of_row_binary };
                    ::dessser::gen::program_parameter::tf3063cfb73e0f06d3ea99ebd15a86d50 id_199 { fun198(drec_snd_82) };
                    ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 letpair_res_200;
                    {
                      auto drec_fst_84 { std::get<0>(id_199) };
                      auto drec_snd_85 { std::get<1>(id_199) };
                      std::shared_ptr<::dessser::gen::program_parameter::t>  id_201 { std::make_shared<::dessser::gen::program_parameter::t>(drec_fst_57, drec_fst_60, drec_fst_66, drec_fst_81, drec_fst_84) };
                      ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 id_202 { id_201, drec_snd_85 };
                      letpair_res_200 = id_202;
                    }
                    letpair_res_197 = letpair_res_200;
                  }
                  let_res_196 = letpair_res_197;
                }
                letpair_res_148 = let_res_196;
              }
              let_res_147 = letpair_res_148;
            }
            letpair_res_130 = let_res_147;
          }
          let_res_129 = letpair_res_130;
        }
        letpair_res_126 = let_res_129;
      }
      let_res_125 = letpair_res_126;
    }
    return let_res_125;
  }
   };
  return fun122;
}
std::function<::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_87" "make_snd_88" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_87") (identifier "make_snd_88"))))
 */
static std::function<::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4(Pointer)> fun203 { [&fun203](Pointer p_0) {
    ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 id_204 { of_row_binary(p_0) };
    ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 letpair_res_205;
    {
      auto make_fst_87 { std::get<0>(id_204) };
      auto make_snd_88 { std::get<1>(id_204) };
      ::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4 id_206 { make_fst_87, make_snd_88 };
      letpair_res_205 = id_206;
    }
    return letpair_res_205;
  }
   };
  return fun203;
}
std::function<::dessser::gen::program_parameter::tb6711e674917c07d8a108a1cb42aa8d4(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{name: $field_name; typ: $raql_type; units: $units?; doc: STRING; value: $raql_value}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::program_parameter::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::program_parameter::t> ,Pointer)> fun207 { [&fun207](std::shared_ptr<::dessser::gen::program_parameter::t>  p_0, Pointer p_1) {
    Pointer id_208 { to_row_binary(p_0, p_1) };
    return id_208;
  }
   };
  return fun207;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::program_parameter::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
