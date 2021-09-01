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
#include "desssergen/raql_type.h"
#include "desssergen/field_name.h"


namespace dessser::gen::global_variable {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t652f68aa23f2c18d61b70156eeb125ea : public std::variant<
  Void, // Program
  Void, // Site
  Void // Global
> { using variant::variant; };

struct t {
  dessser::gen::field_name::t_ext name;
  ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea scope;
  dessser::gen::raql_type::t_ext typ;
  t(dessser::gen::field_name::t_ext name_, ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea scope_, dessser::gen::raql_type::t_ext typ_) : name(name_), scope(scope_), typ(typ_) {}
  t() = default;
  bool operator==(t const &other) const {
    return name == other.name && scope == other.scope && typ == other.typ;
  }
};
typedef std::tuple<
  ::dessser::gen::global_variable::t*,
  Pointer
> t5cd24a9f87710319310e9dd0c1e1d2fb;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea,
  Pointer
> t4fdf456b0504f8a80408f6a04eaabf88;

typedef std::tuple<
  dessser::gen::field_name::t_ext,
  Pointer
> t273a2b7978f5b466a128a51c1cc4a27b;

typedef std::tuple<
  dessser::gen::raql_type::t_ext,
  Pointer
> t2f923f73303f235bd6ab3a4150418dd9;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{scope: [Program Void | Site Void | Global Void]; name: $field_name; typ: $raql_type}" "Ptr")
      (let "srec_dst_93"
        (let "srec_dst_92"
          (let "ssum_dst_91" (write-u16 little-endian (param 1) (label-of (get-field "scope" (param 0))))
            (if (eq (u16 0) (label-of (get-field "scope" (param 0)))) 
              (identifier "ssum_dst_91") (if (eq (u16 1) (label-of (get-field "scope" (param 0)))) (identifier "ssum_dst_91") (seq (assert (eq (label-of (get-field "scope" (param 0))) (u16 2))) (identifier "ssum_dst_91")))))
          (apply (ext-identifier field_name to-row-binary) (get-field "name" (param 0)) (identifier "srec_dst_92"))) 
        (apply (ext-identifier raql_type to-row-binary) (get-field "typ" (param 0)) (identifier "srec_dst_93"))))
 */
static std::function<Pointer(::dessser::gen::global_variable::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::global_variable::t*,Pointer)> fun0 { [&fun0](::dessser::gen::global_variable::t* p_0, Pointer p_1) {
    ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea id_1 { p_0->scope };
    uint16_t id_2 { uint16_t(id_1.index()) };
    Pointer id_3 { p_1.writeU16Le(id_2) };
    Pointer let_res_4;
    {
      Pointer ssum_dst_91 { id_3 };
      uint16_t id_5 { 0 };
      ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea id_6 { p_0->scope };
      uint16_t id_7 { uint16_t(id_6.index()) };
      bool id_8 { bool(id_5 == id_7) };
      Pointer choose_res_9;
      if (id_8) {
        choose_res_9 = ssum_dst_91;
      } else {
        uint16_t id_10 { 1 };
        ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea id_11 { p_0->scope };
        uint16_t id_12 { uint16_t(id_11.index()) };
        bool id_13 { bool(id_10 == id_12) };
        Pointer choose_res_14;
        if (id_13) {
          choose_res_14 = ssum_dst_91;
        } else {
          ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea id_15 { p_0->scope };
          uint16_t id_16 { uint16_t(id_15.index()) };
          uint16_t id_17 { 2 };
          bool id_18 { bool(id_16 == id_17) };
          Void id_19 { ((void)(assert(id_18)), VOID) };
          (void)id_19;
          choose_res_14 = ssum_dst_91;
        }
        choose_res_9 = choose_res_14;
      }
      let_res_4 = choose_res_9;
    }
    Pointer let_res_20;
    {
      Pointer srec_dst_92 { let_res_4 };
      auto fun21 { dessser::gen::field_name::to_row_binary };
      dessser::gen::field_name::t_ext id_22 { p_0->name };
      Pointer id_23 { fun21(id_22, srec_dst_92) };
      let_res_20 = id_23;
    }
    Pointer let_res_24;
    {
      Pointer srec_dst_93 { let_res_20 };
      auto fun25 { dessser::gen::raql_type::to_row_binary };
      dessser::gen::raql_type::t_ext id_26 { p_0->typ };
      Pointer id_27 { fun25(id_26, srec_dst_93) };
      let_res_24 = id_27;
    }
    return let_res_24;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::global_variable::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{scope: [Program Void | Site Void | Global Void]; name: $field_name; typ: $raql_type}")
      (let "sz_89"
        (let "sz_88"
          (if (eq (u16 0) (label-of (get-field "scope" (param 0)))) (size 2) (if (eq (u16 1) (label-of (get-field "scope" (param 0)))) (size 2) (seq (assert (eq (label-of (get-field "scope" (param 0))) (u16 2))) (size 2))))
          (add (identifier "sz_88") (apply (ext-identifier field_name sersize-of-row-binary) (get-field "name" (param 0)))))
        (add (identifier "sz_89") (apply (ext-identifier raql_type sersize-of-row-binary) (get-field "typ" (param 0))))))
 */
static std::function<Size(::dessser::gen::global_variable::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::global_variable::t*)> fun28 { [&fun28](::dessser::gen::global_variable::t* p_0) {
    uint16_t id_29 { 0 };
    ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea id_30 { p_0->scope };
    uint16_t id_31 { uint16_t(id_30.index()) };
    bool id_32 { bool(id_29 == id_31) };
    Size choose_res_33;
    if (id_32) {
      Size id_34 { 2UL };
      choose_res_33 = id_34;
    } else {
      uint16_t id_35 { 1 };
      ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea id_36 { p_0->scope };
      uint16_t id_37 { uint16_t(id_36.index()) };
      bool id_38 { bool(id_35 == id_37) };
      Size choose_res_39;
      if (id_38) {
        Size id_40 { 2UL };
        choose_res_39 = id_40;
      } else {
        ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea id_41 { p_0->scope };
        uint16_t id_42 { uint16_t(id_41.index()) };
        uint16_t id_43 { 2 };
        bool id_44 { bool(id_42 == id_43) };
        Void id_45 { ((void)(assert(id_44)), VOID) };
        (void)id_45;
        Size id_46 { 2UL };
        choose_res_39 = id_46;
      }
      choose_res_33 = choose_res_39;
    }
    Size let_res_47;
    {
      Size sz_88 { choose_res_33 };
      auto fun48 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t_ext id_49 { p_0->name };
      Size id_50 { fun48(id_49) };
      Size id_51 { Size(sz_88 + id_50) };
      let_res_47 = id_51;
    }
    Size let_res_52;
    {
      Size sz_89 { let_res_47 };
      auto fun53 { dessser::gen::raql_type::sersize_of_row_binary };
      dessser::gen::raql_type::t_ext id_54 { p_0->typ };
      Size id_55 { fun53(id_54) };
      Size id_56 { Size(sz_89 + id_55) };
      let_res_52 = id_56;
    }
    return let_res_52;
  }
   };
  return fun28;
}
std::function<Size(::dessser::gen::global_variable::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_74"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63")) (make-tup (construct "[Program Void | Site Void | Global Void]" 0 (nop)) (identifier "dsum1_snd_64"))
              (if (eq (u16 1) (identifier "dsum1_fst_63")) (make-tup (construct "[Program Void | Site Void | Global Void]" 1 (nop)) (identifier "dsum1_snd_64"))
                (seq (assert (eq (identifier "dsum1_fst_63") (u16 2))) (make-tup (construct "[Program Void | Site Void | Global Void]" 2 (nop)) (identifier "dsum1_snd_64")))))))
        (let-pair "drec_fst_75" "drec_snd_76" (identifier "drec_74")
          (let "drec_77" (apply (ext-identifier field_name of-row-binary) (identifier "drec_snd_76"))
            (let-pair "drec_fst_78" "drec_snd_79" (identifier "drec_77")
              (let-pair "drec_fst_81" "drec_snd_82" (apply (ext-identifier raql_type of-row-binary) (identifier "drec_snd_79"))
                (make-tup (make-rec (string "typ") (identifier "drec_fst_81") (string "name") (identifier "drec_fst_78") (string "scope") (identifier "drec_fst_75")) (identifier "drec_snd_82"))))))))
 */
static std::function<::dessser::gen::global_variable::t5cd24a9f87710319310e9dd0c1e1d2fb(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::global_variable::t5cd24a9f87710319310e9dd0c1e1d2fb(Pointer)> fun57 { [&fun57](Pointer p_0) {
    ::dessser::gen::global_variable::t22a32080ad88ab548b80077a17b7dd46 id_58 { p_0.readU16Le() };
    ::dessser::gen::global_variable::t22a32080ad88ab548b80077a17b7dd46 letpair_res_59;
    {
      auto du16_fst_57 { std::get<0>(id_58) };
      auto du16_snd_58 { std::get<1>(id_58) };
      ::dessser::gen::global_variable::t22a32080ad88ab548b80077a17b7dd46 id_60 { du16_fst_57, du16_snd_58 };
      letpair_res_59 = id_60;
    }
    ::dessser::gen::global_variable::t4fdf456b0504f8a80408f6a04eaabf88 let_res_61;
    {
      ::dessser::gen::global_variable::t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_59 };
      ::dessser::gen::global_variable::t4fdf456b0504f8a80408f6a04eaabf88 letpair_res_62;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_63 { 0 };
        bool id_64 { bool(id_63 == dsum1_fst_63) };
        ::dessser::gen::global_variable::t4fdf456b0504f8a80408f6a04eaabf88 choose_res_65;
        if (id_64) {
          (void)VOID;
          ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea id_66 { std::in_place_index<0>, VOID };
          ::dessser::gen::global_variable::t4fdf456b0504f8a80408f6a04eaabf88 id_67 { id_66, dsum1_snd_64 };
          choose_res_65 = id_67;
        } else {
          uint16_t id_68 { 1 };
          bool id_69 { bool(id_68 == dsum1_fst_63) };
          ::dessser::gen::global_variable::t4fdf456b0504f8a80408f6a04eaabf88 choose_res_70;
          if (id_69) {
            (void)VOID;
            ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea id_71 { std::in_place_index<1>, VOID };
            ::dessser::gen::global_variable::t4fdf456b0504f8a80408f6a04eaabf88 id_72 { id_71, dsum1_snd_64 };
            choose_res_70 = id_72;
          } else {
            uint16_t id_73 { 2 };
            bool id_74 { bool(dsum1_fst_63 == id_73) };
            Void id_75 { ((void)(assert(id_74)), VOID) };
            (void)id_75;
            (void)VOID;
            ::dessser::gen::global_variable::t652f68aa23f2c18d61b70156eeb125ea id_76 { std::in_place_index<2>, VOID };
            ::dessser::gen::global_variable::t4fdf456b0504f8a80408f6a04eaabf88 id_77 { id_76, dsum1_snd_64 };
            choose_res_70 = id_77;
          }
          choose_res_65 = choose_res_70;
        }
        letpair_res_62 = choose_res_65;
      }
      let_res_61 = letpair_res_62;
    }
    ::dessser::gen::global_variable::t5cd24a9f87710319310e9dd0c1e1d2fb let_res_78;
    {
      ::dessser::gen::global_variable::t4fdf456b0504f8a80408f6a04eaabf88 drec_74 { let_res_61 };
      ::dessser::gen::global_variable::t5cd24a9f87710319310e9dd0c1e1d2fb letpair_res_79;
      {
        auto drec_fst_75 { std::get<0>(drec_74) };
        auto drec_snd_76 { std::get<1>(drec_74) };
        auto fun80 { dessser::gen::field_name::of_row_binary };
        ::dessser::gen::global_variable::t273a2b7978f5b466a128a51c1cc4a27b id_81 { fun80(drec_snd_76) };
        ::dessser::gen::global_variable::t5cd24a9f87710319310e9dd0c1e1d2fb let_res_82;
        {
          ::dessser::gen::global_variable::t273a2b7978f5b466a128a51c1cc4a27b drec_77 { id_81 };
          ::dessser::gen::global_variable::t5cd24a9f87710319310e9dd0c1e1d2fb letpair_res_83;
          {
            auto drec_fst_78 { std::get<0>(drec_77) };
            auto drec_snd_79 { std::get<1>(drec_77) };
            auto fun84 { dessser::gen::raql_type::of_row_binary };
            ::dessser::gen::global_variable::t2f923f73303f235bd6ab3a4150418dd9 id_85 { fun84(drec_snd_79) };
            ::dessser::gen::global_variable::t5cd24a9f87710319310e9dd0c1e1d2fb letpair_res_86;
            {
              auto drec_fst_81 { std::get<0>(id_85) };
              auto drec_snd_82 { std::get<1>(id_85) };
              ::dessser::gen::global_variable::t* id_87 { new ::dessser::gen::global_variable::t({ .name = drec_fst_78, .scope = drec_fst_75, .typ = drec_fst_81 }) };
              ::dessser::gen::global_variable::t5cd24a9f87710319310e9dd0c1e1d2fb id_88 { id_87, drec_snd_82 };
              letpair_res_86 = id_88;
            }
            letpair_res_83 = letpair_res_86;
          }
          let_res_82 = letpair_res_83;
        }
        letpair_res_79 = let_res_82;
      }
      let_res_78 = letpair_res_79;
    }
    return let_res_78;
  }
   };
  return fun57;
}
std::function<::dessser::gen::global_variable::t5cd24a9f87710319310e9dd0c1e1d2fb(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;

}
