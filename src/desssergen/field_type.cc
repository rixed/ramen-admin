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
#include "desssergen/units.h"
#include "desssergen/raql_type.h"
#include "desssergen/field_name.h"

namespace dessser::gen::field_type {
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
  std::optional<std::string> aggr;
  t(dessser::gen::field_name::t_ext name_, dessser::gen::raql_type::t_ext typ_, std::optional<dessser::gen::units::t_ext> units_, std::string doc_, std::optional<std::string> aggr_) : name(name_), typ(typ_), units(units_), doc(doc_), aggr(aggr_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ) && ((a.units && b.units && ::dessser::gen::units::Deref(a.units.value()) == ::dessser::gen::units::Deref(b.units.value())) || (!a.units && !b.units)) && a.doc == b.doc && ((a.aggr && b.aggr && a.aggr.value() == b.aggr.value()) || (!a.aggr && !b.aggr));
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t17783e9e04d504e04563e9d950fd4c39 : public std::tuple<
  std::shared_ptr<::dessser::gen::field_type::t> ,
  Pointer
> {
  using tuple::tuple;
  t17783e9e04d504e04563e9d950fd4c39(std::tuple<std::shared_ptr<::dessser::gen::field_type::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::field_type::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t17783e9e04d504e04563e9d950fd4c39 const &a, t17783e9e04d504e04563e9d950fd4c39 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t17783e9e04d504e04563e9d950fd4c39 const &a, t17783e9e04d504e04563e9d950fd4c39 const &b) {
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
struct ta18b971ad5bf537b68fb1bbf5fd2b926 : public std::tuple<
  std::optional<std::string>,
  Pointer
> {
  using tuple::tuple;
  ta18b971ad5bf537b68fb1bbf5fd2b926(std::tuple<std::optional<std::string>, Pointer> p)
    : std::tuple<std::optional<std::string>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta18b971ad5bf537b68fb1bbf5fd2b926 const &a, ta18b971ad5bf537b68fb1bbf5fd2b926 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta18b971ad5bf537b68fb1bbf5fd2b926 const &a, ta18b971ad5bf537b68fb1bbf5fd2b926 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{name: $field_name; typ: $raql_type; units: $units?; doc: STRING; aggr: STRING?}" "Ptr")
      (let "srec_dst_121"
        (let "srec_dst_118"
          (let "srec_dst_117"
            (let "srec_dst_116" (apply (ext-identifier field_name to-row-binary) (get-field "name" (param 0)) (param 1)) (apply (ext-identifier raql_type to-row-binary) (get-field "typ" (param 0)) (identifier "srec_dst_116")))
            (if (is-null (get-field "units" (param 0))) (write-u8 (identifier "srec_dst_117") (u8 1))
              (apply (ext-identifier units to-row-binary) (force (get-field "units" (param 0))) (write-u8 (identifier "srec_dst_117") (u8 0)))))
          (write-bytes
            (let "leb128_sz_119" (make-vec (string-length (get-field "doc" (param 0))))
              (let "leb128_ptr_120" (make-vec (identifier "srec_dst_118"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_120")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_120"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_119"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_119"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_119"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_119") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_119")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_119")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_120"))))) 
            (bytes-of-string (get-field "doc" (param 0)))))
        (if (is-null (get-field "aggr" (param 0))) (write-u8 (identifier "srec_dst_121") (u8 1))
          (write-bytes
            (let "leb128_sz_122" (make-vec (string-length (force (get-field "aggr" (param 0)))))
              (let "leb128_ptr_123" (make-vec (write-u8 (identifier "srec_dst_121") (u8 0)))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_123")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_123"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_122"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_122"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_122"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_122") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_122")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_122")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_123"))))) 
            (bytes-of-string (force (get-field "aggr" (param 0))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::field_type::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::field_type::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::field_type::t>  p_0, Pointer p_1) {
    auto fun1 { dessser::gen::field_name::to_row_binary };
    dessser::gen::field_name::t_ext id_2 { (*p_0).name };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_116 { id_3 };
      auto fun5 { dessser::gen::raql_type::to_row_binary };
      dessser::gen::raql_type::t_ext id_6 { (*p_0).typ };
      Pointer id_7 { fun5(id_6, srec_dst_116) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_117 { let_res_4 };
      std::optional<dessser::gen::units::t_ext> id_9 { (*p_0).units };
      bool id_10 { !(id_9.has_value ()) };
      Pointer choose_res_11;
      if (id_10) {
        uint8_t id_12 { 1 };
        Pointer id_13 { srec_dst_117.writeU8(id_12) };
        choose_res_11 = id_13;
      } else {
        auto fun14 { dessser::gen::units::to_row_binary };
        std::optional<dessser::gen::units::t_ext> id_15 { (*p_0).units };
        dessser::gen::units::t_ext id_16 { id_15.value() };
        uint8_t id_17 { 0 };
        Pointer id_18 { srec_dst_117.writeU8(id_17) };
        Pointer id_19 { fun14(id_16, id_18) };
        choose_res_11 = id_19;
      }
      let_res_8 = choose_res_11;
    }
    Pointer let_res_20;
    {
      Pointer srec_dst_118 { let_res_8 };
      std::string id_21 { (*p_0).doc };
      uint32_t id_22 { (uint32_t)id_21.size() };
      Vec<1, uint32_t> id_23 {  id_22  };
      Pointer let_res_24;
      {
        Vec<1, uint32_t> leb128_sz_119 { id_23 };
        Vec<1, Pointer> id_25 {  srec_dst_118  };
        Pointer let_res_26;
        {
          Vec<1, Pointer> leb128_ptr_120 { id_25 };
          bool while_flag_27 { true };
          do {
            uint8_t id_28 { 0 };
            uint8_t id_29 { 0 };
            Pointer id_30 { leb128_ptr_120[id_29] };
            uint32_t id_31 { 128U };
            uint8_t id_32 { 0 };
            uint32_t id_33 { leb128_sz_119[id_32] };
            bool id_34 { bool(id_31 > id_33) };
            uint8_t choose_res_35;
            if (id_34) {
              uint8_t id_36 { 0 };
              uint32_t id_37 { leb128_sz_119[id_36] };
              uint8_t id_38 { uint8_t(id_37) };
              choose_res_35 = id_38;
            } else {
              uint8_t id_39 { 0 };
              uint32_t id_40 { leb128_sz_119[id_39] };
              uint8_t id_41 { uint8_t(id_40) };
              uint8_t id_42 { 128 };
              uint8_t id_43 { uint8_t(id_41 | id_42) };
              choose_res_35 = id_43;
            }
            Pointer id_44 { id_30.writeU8(choose_res_35) };
            Void id_45 { ((void)(leb128_ptr_120[id_28] = id_44), ::dessser::VOID) };
            (void)id_45;
            uint8_t id_46 { 0 };
            uint8_t id_47 { 0 };
            uint32_t id_48 { leb128_sz_119[id_47] };
            uint8_t id_49 { 7 };
            uint32_t id_50 { uint32_t(id_48 >> id_49) };
            Void id_51 { ((void)(leb128_sz_119[id_46] = id_50), ::dessser::VOID) };
            (void)id_51;
            uint8_t id_52 { 0 };
            uint32_t id_53 { leb128_sz_119[id_52] };
            uint32_t id_54 { 0U };
            bool id_55 { bool(id_53 > id_54) };
            while_flag_27 = id_55;
            if (while_flag_27) {
              (void)::dessser::VOID;
            }
          } while (while_flag_27);
          (void)::dessser::VOID;
          uint8_t id_56 { 0 };
          Pointer id_57 { leb128_ptr_120[id_56] };
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
      Pointer srec_dst_121 { let_res_20 };
      std::optional<std::string> id_62 { (*p_0).aggr };
      bool id_63 { !(id_62.has_value ()) };
      Pointer choose_res_64;
      if (id_63) {
        uint8_t id_65 { 1 };
        Pointer id_66 { srec_dst_121.writeU8(id_65) };
        choose_res_64 = id_66;
      } else {
        std::optional<std::string> id_67 { (*p_0).aggr };
        std::string id_68 { id_67.value() };
        uint32_t id_69 { (uint32_t)id_68.size() };
        Vec<1, uint32_t> id_70 {  id_69  };
        Pointer let_res_71;
        {
          Vec<1, uint32_t> leb128_sz_122 { id_70 };
          uint8_t id_72 { 0 };
          Pointer id_73 { srec_dst_121.writeU8(id_72) };
          Vec<1, Pointer> id_74 {  id_73  };
          Pointer let_res_75;
          {
            Vec<1, Pointer> leb128_ptr_123 { id_74 };
            bool while_flag_76 { true };
            do {
              uint8_t id_77 { 0 };
              uint8_t id_78 { 0 };
              Pointer id_79 { leb128_ptr_123[id_78] };
              uint32_t id_80 { 128U };
              uint8_t id_81 { 0 };
              uint32_t id_82 { leb128_sz_122[id_81] };
              bool id_83 { bool(id_80 > id_82) };
              uint8_t choose_res_84;
              if (id_83) {
                uint8_t id_85 { 0 };
                uint32_t id_86 { leb128_sz_122[id_85] };
                uint8_t id_87 { uint8_t(id_86) };
                choose_res_84 = id_87;
              } else {
                uint8_t id_88 { 0 };
                uint32_t id_89 { leb128_sz_122[id_88] };
                uint8_t id_90 { uint8_t(id_89) };
                uint8_t id_91 { 128 };
                uint8_t id_92 { uint8_t(id_90 | id_91) };
                choose_res_84 = id_92;
              }
              Pointer id_93 { id_79.writeU8(choose_res_84) };
              Void id_94 { ((void)(leb128_ptr_123[id_77] = id_93), ::dessser::VOID) };
              (void)id_94;
              uint8_t id_95 { 0 };
              uint8_t id_96 { 0 };
              uint32_t id_97 { leb128_sz_122[id_96] };
              uint8_t id_98 { 7 };
              uint32_t id_99 { uint32_t(id_97 >> id_98) };
              Void id_100 { ((void)(leb128_sz_122[id_95] = id_99), ::dessser::VOID) };
              (void)id_100;
              uint8_t id_101 { 0 };
              uint32_t id_102 { leb128_sz_122[id_101] };
              uint32_t id_103 { 0U };
              bool id_104 { bool(id_102 > id_103) };
              while_flag_76 = id_104;
              if (while_flag_76) {
                (void)::dessser::VOID;
              }
            } while (while_flag_76);
            (void)::dessser::VOID;
            uint8_t id_105 { 0 };
            Pointer id_106 { leb128_ptr_123[id_105] };
            let_res_75 = id_106;
          }
          let_res_71 = let_res_75;
        }
        std::optional<std::string> id_107 { (*p_0).aggr };
        std::string id_108 { id_107.value() };
        Bytes id_109 { id_108 };
        Pointer id_110 { let_res_71.writeBytes(id_109) };
        choose_res_64 = id_110;
      }
      let_res_61 = choose_res_64;
    }
    return let_res_61;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::field_type::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{name: $field_name; typ: $raql_type; units: $units?; doc: STRING; aggr: STRING?}")
      (let "sz_112"
        (let "sz_108"
          (let "sz_107"
            (let "sz_106" (apply (ext-identifier field_name sersize-of-row-binary) (get-field "name" (param 0))) (add (identifier "sz_106") (apply (ext-identifier raql_type sersize-of-row-binary) (get-field "typ" (param 0)))))
            (if (is-null (get-field "units" (param 0))) (add (identifier "sz_107") (size 1)) (add (add (identifier "sz_107") (apply (ext-identifier units sersize-of-row-binary) (force (get-field "units" (param 0))))) (size 1))))
          (add (identifier "sz_108")
            (add
              (let "n_ref_110" (make-vec (string-length (get-field "doc" (param 0))))
                (let "lebsz_ref_111" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_110")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_111")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_111") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_111")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_111")))))) 
              (size-of-u32 (string-length (get-field "doc" (param 0)))))))
        (if (is-null (get-field "aggr" (param 0))) (add (identifier "sz_112") (size 1))
          (add
            (add (identifier "sz_112")
              (add
                (let "n_ref_114" (make-vec (string-length (force (get-field "aggr" (param 0)))))
                  (let "lebsz_ref_115" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_114")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_115")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_115") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_115")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_115")))))) 
                (size-of-u32 (string-length (force (get-field "aggr" (param 0))))))) 
            (size 1)))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::field_type::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::field_type::t> )> fun111 { [&](std::shared_ptr<::dessser::gen::field_type::t>  p_0) {
    auto fun112 { dessser::gen::field_name::sersize_of_row_binary };
    dessser::gen::field_name::t_ext id_113 { (*p_0).name };
    Size id_114 { fun112(id_113) };
    Size let_res_115;
    {
      Size sz_106 { id_114 };
      auto fun116 { dessser::gen::raql_type::sersize_of_row_binary };
      dessser::gen::raql_type::t_ext id_117 { (*p_0).typ };
      Size id_118 { fun116(id_117) };
      Size id_119 { Size(sz_106 + id_118) };
      let_res_115 = id_119;
    }
    Size let_res_120;
    {
      Size sz_107 { let_res_115 };
      std::optional<dessser::gen::units::t_ext> id_121 { (*p_0).units };
      bool id_122 { !(id_121.has_value ()) };
      Size choose_res_123;
      if (id_122) {
        Size id_124 { 1UL };
        Size id_125 { Size(sz_107 + id_124) };
        choose_res_123 = id_125;
      } else {
        auto fun126 { dessser::gen::units::sersize_of_row_binary };
        std::optional<dessser::gen::units::t_ext> id_127 { (*p_0).units };
        dessser::gen::units::t_ext id_128 { id_127.value() };
        Size id_129 { fun126(id_128) };
        Size id_130 { Size(sz_107 + id_129) };
        Size id_131 { 1UL };
        Size id_132 { Size(id_130 + id_131) };
        choose_res_123 = id_132;
      }
      let_res_120 = choose_res_123;
    }
    Size let_res_133;
    {
      Size sz_108 { let_res_120 };
      std::string id_134 { (*p_0).doc };
      uint32_t id_135 { (uint32_t)id_134.size() };
      Vec<1, uint32_t> id_136 {  id_135  };
      Size let_res_137;
      {
        Vec<1, uint32_t> n_ref_110 { id_136 };
        uint32_t id_138 { 1U };
        Vec<1, uint32_t> id_139 {  id_138  };
        Size let_res_140;
        {
          Vec<1, uint32_t> lebsz_ref_111 { id_139 };
          bool while_flag_141 { true };
          do {
            uint8_t id_142 { 0 };
            uint32_t id_143 { n_ref_110[id_142] };
            uint8_t id_144 { 0 };
            uint32_t id_145 { lebsz_ref_111[id_144] };
            uint8_t id_146 { 7 };
            uint32_t id_147 { uint32_t(id_145 << id_146) };
            bool id_148 { bool(id_143 >= id_147) };
            while_flag_141 = id_148;
            if (while_flag_141) {
              uint8_t id_149 { 0 };
              uint8_t id_150 { 0 };
              uint32_t id_151 { lebsz_ref_111[id_150] };
              uint32_t id_152 { 1U };
              uint32_t id_153 { uint32_t(id_151 + id_152) };
              Void id_154 { ((void)(lebsz_ref_111[id_149] = id_153), ::dessser::VOID) };
              (void)id_154;
            }
          } while (while_flag_141);
          (void)::dessser::VOID;
          uint8_t id_155 { 0 };
          uint32_t id_156 { lebsz_ref_111[id_155] };
          Size id_157 { Size(id_156) };
          let_res_140 = id_157;
        }
        let_res_137 = let_res_140;
      }
      std::string id_158 { (*p_0).doc };
      uint32_t id_159 { (uint32_t)id_158.size() };
      Size id_160 { Size(id_159) };
      Size id_161 { Size(let_res_137 + id_160) };
      Size id_162 { Size(sz_108 + id_161) };
      let_res_133 = id_162;
    }
    Size let_res_163;
    {
      Size sz_112 { let_res_133 };
      std::optional<std::string> id_164 { (*p_0).aggr };
      bool id_165 { !(id_164.has_value ()) };
      Size choose_res_166;
      if (id_165) {
        Size id_167 { 1UL };
        Size id_168 { Size(sz_112 + id_167) };
        choose_res_166 = id_168;
      } else {
        std::optional<std::string> id_169 { (*p_0).aggr };
        std::string id_170 { id_169.value() };
        uint32_t id_171 { (uint32_t)id_170.size() };
        Vec<1, uint32_t> id_172 {  id_171  };
        Size let_res_173;
        {
          Vec<1, uint32_t> n_ref_114 { id_172 };
          uint32_t id_174 { 1U };
          Vec<1, uint32_t> id_175 {  id_174  };
          Size let_res_176;
          {
            Vec<1, uint32_t> lebsz_ref_115 { id_175 };
            bool while_flag_177 { true };
            do {
              uint8_t id_178 { 0 };
              uint32_t id_179 { n_ref_114[id_178] };
              uint8_t id_180 { 0 };
              uint32_t id_181 { lebsz_ref_115[id_180] };
              uint8_t id_182 { 7 };
              uint32_t id_183 { uint32_t(id_181 << id_182) };
              bool id_184 { bool(id_179 >= id_183) };
              while_flag_177 = id_184;
              if (while_flag_177) {
                uint8_t id_185 { 0 };
                uint8_t id_186 { 0 };
                uint32_t id_187 { lebsz_ref_115[id_186] };
                uint32_t id_188 { 1U };
                uint32_t id_189 { uint32_t(id_187 + id_188) };
                Void id_190 { ((void)(lebsz_ref_115[id_185] = id_189), ::dessser::VOID) };
                (void)id_190;
              }
            } while (while_flag_177);
            (void)::dessser::VOID;
            uint8_t id_191 { 0 };
            uint32_t id_192 { lebsz_ref_115[id_191] };
            Size id_193 { Size(id_192) };
            let_res_176 = id_193;
          }
          let_res_173 = let_res_176;
        }
        std::optional<std::string> id_194 { (*p_0).aggr };
        std::string id_195 { id_194.value() };
        uint32_t id_196 { (uint32_t)id_195.size() };
        Size id_197 { Size(id_196) };
        Size id_198 { Size(let_res_173 + id_197) };
        Size id_199 { Size(sz_112 + id_198) };
        Size id_200 { 1UL };
        Size id_201 { Size(id_199 + id_200) };
        choose_res_166 = id_201;
      }
      let_res_163 = choose_res_166;
    }
    return let_res_163;
  }
   };
  return fun111;
}
std::function<Size(std::shared_ptr<::dessser::gen::field_type::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_57" (apply (ext-identifier field_name of-row-binary) (param 0))
        (let-pair "drec_fst_58" "drec_snd_59" (identifier "drec_57")
          (let "drec_60" (apply (ext-identifier raql_type of-row-binary) (identifier "drec_snd_59"))
            (let-pair "drec_fst_61" "drec_snd_62" (identifier "drec_60")
              (let "drec_66"
                (if (eq (peek-u8 (identifier "drec_snd_62") (size 0)) (u8 1)) 
                  (make-tup (null "$units") (ptr-add (identifier "drec_snd_62") (size 1)))
                  (let-pair "make1_1_fst_64" "make1_1_snd_65" (apply (ext-identifier units of-row-binary) (ptr-add (identifier "drec_snd_62") (size 1)))
                    (make-tup (not-null (identifier "make1_1_fst_64")) (identifier "make1_1_snd_65"))))
                (let-pair "drec_fst_67" "drec_snd_68" (identifier "drec_66")
                  (let "drec_81"
                    (let "dstring1_75"
                      (let "leb_ref_69" (make-vec (u32 0))
                        (let "shft_ref_70" (make-vec (u8 0))
                          (let "p_ref_71" (make-vec (identifier "drec_snd_68"))
                            (seq
                              (while
                                (let "leb128_72" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_71")))
                                  (let-pair "leb128_fst_73" "leb128_snd_74" 
                                    (identifier "leb128_72")
                                    (seq (set-vec (u8 0) (identifier "p_ref_71") (identifier "leb128_snd_74"))
                                      (set-vec (u8 0) (identifier "leb_ref_69")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_73") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_70"))) (unsafe-nth (u8 0) (identifier "leb_ref_69"))))
                                      (set-vec (u8 0) (identifier "shft_ref_70") (add (unsafe-nth (u8 0) (identifier "shft_ref_70")) (u8 7))) 
                                      (ge (identifier "leb128_fst_73") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_69"))) (unsafe-nth (u8 0) (identifier "p_ref_71")))))))
                      (let-pair "dstring1_fst_76" "dstring1_snd_77" (identifier "dstring1_75")
                        (let-pair "dstring2_fst_79" "dstring2_snd_80" 
                          (read-bytes (identifier "dstring1_snd_77") (identifier "dstring1_fst_76")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_79")) (identifier "dstring2_snd_80")))))
                    (let-pair "drec_fst_82" "drec_snd_83" (identifier "drec_81")
                      (let-pair "drec_fst_100" "drec_snd_101"
                        (if (eq (peek-u8 (identifier "drec_snd_83") (size 0)) (u8 1)) 
                          (make-tup (null "STRING") (ptr-add (identifier "drec_snd_83") (size 1)))
                          (let "dstring1_90"
                            (let "leb_ref_84" (make-vec (u32 0))
                              (let "shft_ref_85" (make-vec (u8 0))
                                (let "p_ref_86" (make-vec (ptr-add (identifier "drec_snd_83") (size 1)))
                                  (seq
                                    (while
                                      (let "leb128_87" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_86")))
                                        (let-pair "leb128_fst_88" "leb128_snd_89" 
                                          (identifier "leb128_87")
                                          (seq (set-vec (u8 0) (identifier "p_ref_86") (identifier "leb128_snd_89"))
                                            (set-vec (u8 0) (identifier "leb_ref_84")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_88") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_85"))) (unsafe-nth (u8 0) (identifier "leb_ref_84"))))
                                            (set-vec (u8 0) (identifier "shft_ref_85") (add (unsafe-nth (u8 0) (identifier "shft_ref_85")) (u8 7))) 
                                            (ge (identifier "leb128_fst_88") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_84"))) (unsafe-nth (u8 0) (identifier "p_ref_86")))))))
                            (let-pair "dstring1_fst_91" "dstring1_snd_92" 
                              (identifier "dstring1_90")
                              (let-pair "dstring2_fst_94" "dstring2_snd_95" 
                                (read-bytes (identifier "dstring1_snd_92") (identifier "dstring1_fst_91")) 
                                (make-tup (not-null (string-of-bytes (identifier "dstring2_fst_94"))) (identifier "dstring2_snd_95"))))))
                        (make-tup
                          (make-rec (string "aggr") (identifier "drec_fst_100") 
                            (string "doc") (identifier "drec_fst_82") 
                            (string "units") (identifier "drec_fst_67") 
                            (string "typ") (identifier "drec_fst_61") 
                            (string "name") (identifier "drec_fst_58")) 
                          (identifier "drec_snd_101"))))))))))))
 */
static std::function<::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39(Pointer)> fun202 { [&](Pointer p_0) {
    auto fun203 { dessser::gen::field_name::of_row_binary };
    ::dessser::gen::field_type::t18cecf882d7ac80cef37dfe6b22279d4 id_204 { fun203(p_0) };
    ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 let_res_205;
    {
      ::dessser::gen::field_type::t18cecf882d7ac80cef37dfe6b22279d4 drec_57 { id_204 };
      ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 letpair_res_206;
      {
        auto drec_fst_58 { std::get<0>(drec_57) };
        auto drec_snd_59 { std::get<1>(drec_57) };
        auto fun207 { dessser::gen::raql_type::of_row_binary };
        ::dessser::gen::field_type::t101502ffd7fb38beafe4b49259f92ba1 id_208 { fun207(drec_snd_59) };
        ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 let_res_209;
        {
          ::dessser::gen::field_type::t101502ffd7fb38beafe4b49259f92ba1 drec_60 { id_208 };
          ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 letpair_res_210;
          {
            auto drec_fst_61 { std::get<0>(drec_60) };
            auto drec_snd_62 { std::get<1>(drec_60) };
            Size id_211 { 0UL };
            uint8_t id_212 { drec_snd_62.peekU8(id_211) };
            uint8_t id_213 { 1 };
            bool id_214 { bool(id_212 == id_213) };
            ::dessser::gen::field_type::t096d6a0956a2df6dec7d0945ab177a4b choose_res_215;
            if (id_214) {
              std::optional<dessser::gen::units::t_ext> id_216 { std::nullopt };
              Size id_217 { 1UL };
              Pointer id_218 { drec_snd_62.skip(id_217) };
              ::dessser::gen::field_type::t096d6a0956a2df6dec7d0945ab177a4b id_219 { id_216, id_218 };
              choose_res_215 = id_219;
            } else {
              auto fun220 { dessser::gen::units::of_row_binary };
              Size id_221 { 1UL };
              Pointer id_222 { drec_snd_62.skip(id_221) };
              ::dessser::gen::field_type::tdcd8238b20249643ff5b5f9a7648e226 id_223 { fun220(id_222) };
              ::dessser::gen::field_type::t096d6a0956a2df6dec7d0945ab177a4b letpair_res_224;
              {
                auto make1_1_fst_64 { std::get<0>(id_223) };
                auto make1_1_snd_65 { std::get<1>(id_223) };
                std::optional<dessser::gen::units::t_ext> id_225 { make1_1_fst_64 };
                ::dessser::gen::field_type::t096d6a0956a2df6dec7d0945ab177a4b id_226 { id_225, make1_1_snd_65 };
                letpair_res_224 = id_226;
              }
              choose_res_215 = letpair_res_224;
            }
            ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 let_res_227;
            {
              ::dessser::gen::field_type::t096d6a0956a2df6dec7d0945ab177a4b drec_66 { choose_res_215 };
              ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 letpair_res_228;
              {
                auto drec_fst_67 { std::get<0>(drec_66) };
                auto drec_snd_68 { std::get<1>(drec_66) };
                uint32_t id_229 { 0U };
                Vec<1, uint32_t> id_230 {  id_229  };
                ::dessser::gen::field_type::t12fb9c475959b52bf7b17b155a955ffa let_res_231;
                {
                  Vec<1, uint32_t> leb_ref_69 { id_230 };
                  uint8_t id_232 { 0 };
                  Vec<1, uint8_t> id_233 {  id_232  };
                  ::dessser::gen::field_type::t12fb9c475959b52bf7b17b155a955ffa let_res_234;
                  {
                    Vec<1, uint8_t> shft_ref_70 { id_233 };
                    Vec<1, Pointer> id_235 {  drec_snd_68  };
                    ::dessser::gen::field_type::t12fb9c475959b52bf7b17b155a955ffa let_res_236;
                    {
                      Vec<1, Pointer> p_ref_71 { id_235 };
                      bool while_flag_237 { true };
                      do {
                        uint8_t id_238 { 0 };
                        Pointer id_239 { p_ref_71[id_238] };
                        ::dessser::gen::field_type::t1a5d74abf838df33f185a72a8912f5c9 id_240 { id_239.readU8() };
                        bool let_res_241;
                        {
                          ::dessser::gen::field_type::t1a5d74abf838df33f185a72a8912f5c9 leb128_72 { id_240 };
                          bool letpair_res_242;
                          {
                            auto leb128_fst_73 { std::get<0>(leb128_72) };
                            auto leb128_snd_74 { std::get<1>(leb128_72) };
                            uint8_t id_243 { 0 };
                            Void id_244 { ((void)(p_ref_71[id_243] = leb128_snd_74), ::dessser::VOID) };
                            (void)id_244;
                            uint8_t id_245 { 0 };
                            uint8_t id_246 { 127 };
                            uint8_t id_247 { uint8_t(leb128_fst_73 & id_246) };
                            uint32_t id_248 { uint32_t(id_247) };
                            uint8_t id_249 { 0 };
                            uint8_t id_250 { shft_ref_70[id_249] };
                            uint32_t id_251 { uint32_t(id_248 << id_250) };
                            uint8_t id_252 { 0 };
                            uint32_t id_253 { leb_ref_69[id_252] };
                            uint32_t id_254 { uint32_t(id_251 | id_253) };
                            Void id_255 { ((void)(leb_ref_69[id_245] = id_254), ::dessser::VOID) };
                            (void)id_255;
                            uint8_t id_256 { 0 };
                            uint8_t id_257 { 0 };
                            uint8_t id_258 { shft_ref_70[id_257] };
                            uint8_t id_259 { 7 };
                            uint8_t id_260 { uint8_t(id_258 + id_259) };
                            Void id_261 { ((void)(shft_ref_70[id_256] = id_260), ::dessser::VOID) };
                            (void)id_261;
                            uint8_t id_262 { 128 };
                            bool id_263 { bool(leb128_fst_73 >= id_262) };
                            letpair_res_242 = id_263;
                          }
                          let_res_241 = letpair_res_242;
                        }
                        while_flag_237 = let_res_241;
                        if (while_flag_237) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_237);
                      (void)::dessser::VOID;
                      uint8_t id_264 { 0 };
                      uint32_t id_265 { leb_ref_69[id_264] };
                      Size id_266 { Size(id_265) };
                      uint8_t id_267 { 0 };
                      Pointer id_268 { p_ref_71[id_267] };
                      ::dessser::gen::field_type::t12fb9c475959b52bf7b17b155a955ffa id_269 { id_266, id_268 };
                      let_res_236 = id_269;
                    }
                    let_res_234 = let_res_236;
                  }
                  let_res_231 = let_res_234;
                }
                ::dessser::gen::field_type::t13a07ee37ab40962540da8534858dc07 let_res_270;
                {
                  ::dessser::gen::field_type::t12fb9c475959b52bf7b17b155a955ffa dstring1_75 { let_res_231 };
                  ::dessser::gen::field_type::t13a07ee37ab40962540da8534858dc07 letpair_res_271;
                  {
                    auto dstring1_fst_76 { std::get<0>(dstring1_75) };
                    auto dstring1_snd_77 { std::get<1>(dstring1_75) };
                    ::dessser::gen::field_type::t9ef6882174ae71a34a3c5ef6b29242fb id_272 { dstring1_snd_77.readBytes(dstring1_fst_76) };
                    ::dessser::gen::field_type::t13a07ee37ab40962540da8534858dc07 letpair_res_273;
                    {
                      auto dstring2_fst_79 { std::get<0>(id_272) };
                      auto dstring2_snd_80 { std::get<1>(id_272) };
                      std::string id_274 { dstring2_fst_79.toString() };
                      ::dessser::gen::field_type::t13a07ee37ab40962540da8534858dc07 id_275 { id_274, dstring2_snd_80 };
                      letpair_res_273 = id_275;
                    }
                    letpair_res_271 = letpair_res_273;
                  }
                  let_res_270 = letpair_res_271;
                }
                ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 let_res_276;
                {
                  ::dessser::gen::field_type::t13a07ee37ab40962540da8534858dc07 drec_81 { let_res_270 };
                  ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 letpair_res_277;
                  {
                    auto drec_fst_82 { std::get<0>(drec_81) };
                    auto drec_snd_83 { std::get<1>(drec_81) };
                    Size id_278 { 0UL };
                    uint8_t id_279 { drec_snd_83.peekU8(id_278) };
                    uint8_t id_280 { 1 };
                    bool id_281 { bool(id_279 == id_280) };
                    ::dessser::gen::field_type::ta18b971ad5bf537b68fb1bbf5fd2b926 choose_res_282;
                    if (id_281) {
                      std::optional<std::string> id_283 { std::nullopt };
                      Size id_284 { 1UL };
                      Pointer id_285 { drec_snd_83.skip(id_284) };
                      ::dessser::gen::field_type::ta18b971ad5bf537b68fb1bbf5fd2b926 id_286 { id_283, id_285 };
                      choose_res_282 = id_286;
                    } else {
                      uint32_t id_287 { 0U };
                      Vec<1, uint32_t> id_288 {  id_287  };
                      ::dessser::gen::field_type::t12fb9c475959b52bf7b17b155a955ffa let_res_289;
                      {
                        Vec<1, uint32_t> leb_ref_84 { id_288 };
                        uint8_t id_290 { 0 };
                        Vec<1, uint8_t> id_291 {  id_290  };
                        ::dessser::gen::field_type::t12fb9c475959b52bf7b17b155a955ffa let_res_292;
                        {
                          Vec<1, uint8_t> shft_ref_85 { id_291 };
                          Size id_293 { 1UL };
                          Pointer id_294 { drec_snd_83.skip(id_293) };
                          Vec<1, Pointer> id_295 {  id_294  };
                          ::dessser::gen::field_type::t12fb9c475959b52bf7b17b155a955ffa let_res_296;
                          {
                            Vec<1, Pointer> p_ref_86 { id_295 };
                            bool while_flag_297 { true };
                            do {
                              uint8_t id_298 { 0 };
                              Pointer id_299 { p_ref_86[id_298] };
                              ::dessser::gen::field_type::t1a5d74abf838df33f185a72a8912f5c9 id_300 { id_299.readU8() };
                              bool let_res_301;
                              {
                                ::dessser::gen::field_type::t1a5d74abf838df33f185a72a8912f5c9 leb128_87 { id_300 };
                                bool letpair_res_302;
                                {
                                  auto leb128_fst_88 { std::get<0>(leb128_87) };
                                  auto leb128_snd_89 { std::get<1>(leb128_87) };
                                  uint8_t id_303 { 0 };
                                  Void id_304 { ((void)(p_ref_86[id_303] = leb128_snd_89), ::dessser::VOID) };
                                  (void)id_304;
                                  uint8_t id_305 { 0 };
                                  uint8_t id_306 { 127 };
                                  uint8_t id_307 { uint8_t(leb128_fst_88 & id_306) };
                                  uint32_t id_308 { uint32_t(id_307) };
                                  uint8_t id_309 { 0 };
                                  uint8_t id_310 { shft_ref_85[id_309] };
                                  uint32_t id_311 { uint32_t(id_308 << id_310) };
                                  uint8_t id_312 { 0 };
                                  uint32_t id_313 { leb_ref_84[id_312] };
                                  uint32_t id_314 { uint32_t(id_311 | id_313) };
                                  Void id_315 { ((void)(leb_ref_84[id_305] = id_314), ::dessser::VOID) };
                                  (void)id_315;
                                  uint8_t id_316 { 0 };
                                  uint8_t id_317 { 0 };
                                  uint8_t id_318 { shft_ref_85[id_317] };
                                  uint8_t id_319 { 7 };
                                  uint8_t id_320 { uint8_t(id_318 + id_319) };
                                  Void id_321 { ((void)(shft_ref_85[id_316] = id_320), ::dessser::VOID) };
                                  (void)id_321;
                                  uint8_t id_322 { 128 };
                                  bool id_323 { bool(leb128_fst_88 >= id_322) };
                                  letpair_res_302 = id_323;
                                }
                                let_res_301 = letpair_res_302;
                              }
                              while_flag_297 = let_res_301;
                              if (while_flag_297) {
                                (void)::dessser::VOID;
                              }
                            } while (while_flag_297);
                            (void)::dessser::VOID;
                            uint8_t id_324 { 0 };
                            uint32_t id_325 { leb_ref_84[id_324] };
                            Size id_326 { Size(id_325) };
                            uint8_t id_327 { 0 };
                            Pointer id_328 { p_ref_86[id_327] };
                            ::dessser::gen::field_type::t12fb9c475959b52bf7b17b155a955ffa id_329 { id_326, id_328 };
                            let_res_296 = id_329;
                          }
                          let_res_292 = let_res_296;
                        }
                        let_res_289 = let_res_292;
                      }
                      ::dessser::gen::field_type::ta18b971ad5bf537b68fb1bbf5fd2b926 let_res_330;
                      {
                        ::dessser::gen::field_type::t12fb9c475959b52bf7b17b155a955ffa dstring1_90 { let_res_289 };
                        ::dessser::gen::field_type::ta18b971ad5bf537b68fb1bbf5fd2b926 letpair_res_331;
                        {
                          auto dstring1_fst_91 { std::get<0>(dstring1_90) };
                          auto dstring1_snd_92 { std::get<1>(dstring1_90) };
                          ::dessser::gen::field_type::t9ef6882174ae71a34a3c5ef6b29242fb id_332 { dstring1_snd_92.readBytes(dstring1_fst_91) };
                          ::dessser::gen::field_type::ta18b971ad5bf537b68fb1bbf5fd2b926 letpair_res_333;
                          {
                            auto dstring2_fst_94 { std::get<0>(id_332) };
                            auto dstring2_snd_95 { std::get<1>(id_332) };
                            std::string id_334 { dstring2_fst_94.toString() };
                            std::optional<std::string> id_335 { id_334 };
                            ::dessser::gen::field_type::ta18b971ad5bf537b68fb1bbf5fd2b926 id_336 { id_335, dstring2_snd_95 };
                            letpair_res_333 = id_336;
                          }
                          letpair_res_331 = letpair_res_333;
                        }
                        let_res_330 = letpair_res_331;
                      }
                      choose_res_282 = let_res_330;
                    }
                    ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 letpair_res_337;
                    {
                      auto drec_fst_100 { std::get<0>(choose_res_282) };
                      auto drec_snd_101 { std::get<1>(choose_res_282) };
                      std::shared_ptr<::dessser::gen::field_type::t>  id_338 { std::make_shared<::dessser::gen::field_type::t>(drec_fst_58, drec_fst_61, drec_fst_67, drec_fst_82, drec_fst_100) };
                      ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 id_339 { id_338, drec_snd_101 };
                      letpair_res_337 = id_339;
                    }
                    letpair_res_277 = letpair_res_337;
                  }
                  let_res_276 = letpair_res_277;
                }
                letpair_res_228 = let_res_276;
              }
              let_res_227 = letpair_res_228;
            }
            letpair_res_210 = let_res_227;
          }
          let_res_209 = letpair_res_210;
        }
        letpair_res_206 = let_res_209;
      }
      let_res_205 = letpair_res_206;
    }
    return let_res_205;
  }
   };
  return fun202;
}
std::function<::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_103" "make_snd_104" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_103") (identifier "make_snd_104"))))
 */
static std::function<::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39(Pointer)> fun340 { [&](Pointer p_0) {
    ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 id_341 { of_row_binary(p_0) };
    ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 letpair_res_342;
    {
      auto make_fst_103 { std::get<0>(id_341) };
      auto make_snd_104 { std::get<1>(id_341) };
      ::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39 id_343 { make_fst_103, make_snd_104 };
      letpair_res_342 = id_343;
    }
    return letpair_res_342;
  }
   };
  return fun340;
}
std::function<::dessser::gen::field_type::t17783e9e04d504e04563e9d950fd4c39(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{name: $field_name; typ: $raql_type; units: $units?; doc: STRING; aggr: STRING?}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::field_type::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::field_type::t> ,Pointer)> fun344 { [&](std::shared_ptr<::dessser::gen::field_type::t>  p_0, Pointer p_1) {
    Pointer id_345 { to_row_binary(p_0, p_1) };
    return id_345;
  }
   };
  return fun344;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::field_type::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
