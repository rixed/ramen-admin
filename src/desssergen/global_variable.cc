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
enum t54b6b844175be8bcdfc38eae0dd1a139 {
  Program,
  Site,
  Global,
};

constexpr size_t t54b6b844175be8bcdfc38eae0dd1a139_size { 3 };
struct t {
  ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 scope;
  dessser::gen::field_name::t_ext name;
  dessser::gen::raql_type::t_ext typ;
  t(::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 scope_, dessser::gen::field_name::t_ext name_, dessser::gen::raql_type::t_ext typ_) : scope(scope_), name(name_), typ(typ_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.scope == b.scope && ::dessser::gen::field_name::Deref(a.name) == ::dessser::gen::field_name::Deref(b.name) && ::dessser::gen::raql_type::Deref(a.typ) == ::dessser::gen::raql_type::Deref(b.typ);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tc84f2fcbb1d2467c59aba5c8fcedbcc6 : public std::tuple<
  ::dessser::gen::global_variable::t,
  Pointer
> {
  using tuple::tuple;
  tc84f2fcbb1d2467c59aba5c8fcedbcc6(std::tuple<::dessser::gen::global_variable::t, Pointer> p)
    : std::tuple<::dessser::gen::global_variable::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc84f2fcbb1d2467c59aba5c8fcedbcc6 const &a, tc84f2fcbb1d2467c59aba5c8fcedbcc6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc84f2fcbb1d2467c59aba5c8fcedbcc6 const &a, tc84f2fcbb1d2467c59aba5c8fcedbcc6 const &b) {
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
struct tcb5a2028a026de335727b68454048f2c : public std::tuple<
  ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139,
  Pointer
> {
  using tuple::tuple;
  tcb5a2028a026de335727b68454048f2c(std::tuple<::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139, Pointer> p)
    : std::tuple<::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcb5a2028a026de335727b68454048f2c const &a, tcb5a2028a026de335727b68454048f2c const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcb5a2028a026de335727b68454048f2c const &a, tcb5a2028a026de335727b68454048f2c const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{scope: [Program Void | Site Void | Global Void]; name: $field_name; typ: $raql_type}" "Ptr")
      (let "srec_dst_94"
        (let "srec_dst_93"
          (let "ssum_dst_92" (write-u16 little-endian (param 1) (label-of (get-field "scope" (param 0))))
            (if (eq (u16 0) (label-of (get-field "scope" (param 0)))) 
              (identifier "ssum_dst_92") (if (eq (u16 1) (label-of (get-field "scope" (param 0)))) (identifier "ssum_dst_92") (seq (assert (eq (label-of (get-field "scope" (param 0))) (u16 2))) (identifier "ssum_dst_92")))))
          (apply (ext-identifier field_name to-row-binary) (get-field "name" (param 0)) (identifier "srec_dst_93"))) 
        (apply (ext-identifier raql_type to-row-binary) (get-field "typ" (param 0)) (identifier "srec_dst_94"))))
 */
static std::function<Pointer(::dessser::gen::global_variable::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::global_variable::t &,Pointer &)> fun0 { [&](::dessser::gen::global_variable::t p_0, Pointer p_1) {
    ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 id_1 { p_0.scope };
    uint16_t id_2 { uint16_t(id_1) };
    Pointer id_3 { p_1.writeU16Le(id_2) };
    Pointer let_res_4;
    {
      Pointer ssum_dst_92 { id_3 };
      uint16_t id_5 { 0 };
      ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 id_6 { p_0.scope };
      uint16_t id_7 { uint16_t(id_6) };
      bool id_8 { bool(id_5 == id_7) };
      Pointer choose_res_9;
      if (id_8) {
        choose_res_9 = ssum_dst_92;
      } else {
        uint16_t id_10 { 1 };
        ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 id_11 { p_0.scope };
        uint16_t id_12 { uint16_t(id_11) };
        bool id_13 { bool(id_10 == id_12) };
        Pointer choose_res_14;
        if (id_13) {
          choose_res_14 = ssum_dst_92;
        } else {
          ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 id_15 { p_0.scope };
          uint16_t id_16 { uint16_t(id_15) };
          uint16_t id_17 { 2 };
          bool id_18 { bool(id_16 == id_17) };
          Void id_19 { ((void)(assert(id_18)), ::dessser::Void()) };
          (void)id_19;
          choose_res_14 = ssum_dst_92;
        }
        choose_res_9 = choose_res_14;
      }
      let_res_4 = choose_res_9;
    }
    Pointer let_res_20;
    {
      Pointer srec_dst_93 { let_res_4 };
      auto fun21 { dessser::gen::field_name::to_row_binary };
      dessser::gen::field_name::t_ext id_22 { p_0.name };
      Pointer id_23 { fun21(id_22, srec_dst_93) };
      let_res_20 = id_23;
    }
    Pointer let_res_24;
    {
      Pointer srec_dst_94 { let_res_20 };
      auto fun25 { dessser::gen::raql_type::to_row_binary };
      dessser::gen::raql_type::t_ext id_26 { p_0.typ };
      Pointer id_27 { fun25(id_26, srec_dst_94) };
      let_res_24 = id_27;
    }
    return let_res_24;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::global_variable::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{scope: [Program Void | Site Void | Global Void]; name: $field_name; typ: $raql_type}")
      (let "sz_90"
        (let "sz_89"
          (if (eq (u16 0) (label-of (get-field "scope" (param 0)))) (size 2) (if (eq (u16 1) (label-of (get-field "scope" (param 0)))) (size 2) (seq (assert (eq (label-of (get-field "scope" (param 0))) (u16 2))) (size 2))))
          (add (identifier "sz_89") (apply (ext-identifier field_name sersize-of-row-binary) (get-field "name" (param 0)))))
        (add (identifier "sz_90") (apply (ext-identifier raql_type sersize-of-row-binary) (get-field "typ" (param 0))))))
 */
static std::function<Size(::dessser::gen::global_variable::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::global_variable::t &)> fun28 { [&](::dessser::gen::global_variable::t p_0) {
    uint16_t id_29 { 0 };
    ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 id_30 { p_0.scope };
    uint16_t id_31 { uint16_t(id_30) };
    bool id_32 { bool(id_29 == id_31) };
    Size choose_res_33;
    if (id_32) {
      Size id_34 { 2UL };
      choose_res_33 = id_34;
    } else {
      uint16_t id_35 { 1 };
      ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 id_36 { p_0.scope };
      uint16_t id_37 { uint16_t(id_36) };
      bool id_38 { bool(id_35 == id_37) };
      Size choose_res_39;
      if (id_38) {
        Size id_40 { 2UL };
        choose_res_39 = id_40;
      } else {
        ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 id_41 { p_0.scope };
        uint16_t id_42 { uint16_t(id_41) };
        uint16_t id_43 { 2 };
        bool id_44 { bool(id_42 == id_43) };
        Void id_45 { ((void)(assert(id_44)), ::dessser::Void()) };
        (void)id_45;
        Size id_46 { 2UL };
        choose_res_39 = id_46;
      }
      choose_res_33 = choose_res_39;
    }
    Size let_res_47;
    {
      Size sz_89 { choose_res_33 };
      auto fun48 { dessser::gen::field_name::sersize_of_row_binary };
      dessser::gen::field_name::t_ext id_49 { p_0.name };
      Size id_50 { fun48(id_49) };
      Size id_51 { Size(sz_89 + id_50) };
      let_res_47 = id_51;
    }
    Size let_res_52;
    {
      Size sz_90 { let_res_47 };
      auto fun53 { dessser::gen::raql_type::sersize_of_row_binary };
      dessser::gen::raql_type::t_ext id_54 { p_0.typ };
      Size id_55 { fun53(id_54) };
      Size id_56 { Size(sz_90 + id_55) };
      let_res_52 = id_56;
    }
    return let_res_52;
  }
   };
  return fun28;
}
std::function<Size(::dessser::gen::global_variable::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_75"
        (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
          (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
            (if (eq (u16 0) (identifier "dsum1_fst_64")) (make-tup (construct "[Program Void | Site Void | Global Void]" 0 (nop)) (identifier "dsum1_snd_65"))
              (if (eq (u16 1) (identifier "dsum1_fst_64")) (make-tup (construct "[Program Void | Site Void | Global Void]" 1 (nop)) (identifier "dsum1_snd_65"))
                (seq (assert (eq (identifier "dsum1_fst_64") (u16 2))) (make-tup (construct "[Program Void | Site Void | Global Void]" 2 (nop)) (identifier "dsum1_snd_65")))))))
        (let-pair "drec_fst_76" "drec_snd_77" (identifier "drec_75")
          (let "drec_78" (apply (ext-identifier field_name of-row-binary) (identifier "drec_snd_77"))
            (let-pair "drec_fst_79" "drec_snd_80" (identifier "drec_78")
              (let-pair "drec_fst_82" "drec_snd_83" (apply (ext-identifier raql_type of-row-binary) (identifier "drec_snd_80"))
                (make-tup (make-rec (string "typ") (identifier "drec_fst_82") (string "name") (identifier "drec_fst_79") (string "scope") (identifier "drec_fst_76")) (identifier "drec_snd_83"))))))))
 */
static std::function<::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6(Pointer &)> fun57 { [&](Pointer p_0) {
    ::dessser::gen::global_variable::ta97bb48ed75bbda6173555873826c8c6 id_58 { p_0.readU16Le() };
    ::dessser::gen::global_variable::ta97bb48ed75bbda6173555873826c8c6 letpair_res_59;
    {
      auto du16_fst_58 { std::get<0>(id_58) };
      auto du16_snd_59 { std::get<1>(id_58) };
      ::dessser::gen::global_variable::ta97bb48ed75bbda6173555873826c8c6 id_60 { du16_fst_58, du16_snd_59 };
      letpair_res_59 = id_60;
    }
    ::dessser::gen::global_variable::tcb5a2028a026de335727b68454048f2c let_res_61;
    {
      ::dessser::gen::global_variable::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_59 };
      ::dessser::gen::global_variable::tcb5a2028a026de335727b68454048f2c letpair_res_62;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_63 { 0 };
        bool id_64 { bool(id_63 == dsum1_fst_64) };
        ::dessser::gen::global_variable::tcb5a2028a026de335727b68454048f2c choose_res_65;
        if (id_64) {
          (void)::dessser::Void();
          ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 id_66 { Program };
          ::dessser::gen::global_variable::tcb5a2028a026de335727b68454048f2c id_67 { id_66, dsum1_snd_65 };
          choose_res_65 = id_67;
        } else {
          uint16_t id_68 { 1 };
          bool id_69 { bool(id_68 == dsum1_fst_64) };
          ::dessser::gen::global_variable::tcb5a2028a026de335727b68454048f2c choose_res_70;
          if (id_69) {
            (void)::dessser::Void();
            ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 id_71 { Site };
            ::dessser::gen::global_variable::tcb5a2028a026de335727b68454048f2c id_72 { id_71, dsum1_snd_65 };
            choose_res_70 = id_72;
          } else {
            uint16_t id_73 { 2 };
            bool id_74 { bool(dsum1_fst_64 == id_73) };
            Void id_75 { ((void)(assert(id_74)), ::dessser::Void()) };
            (void)id_75;
            (void)::dessser::Void();
            ::dessser::gen::global_variable::t54b6b844175be8bcdfc38eae0dd1a139 id_76 { Global };
            ::dessser::gen::global_variable::tcb5a2028a026de335727b68454048f2c id_77 { id_76, dsum1_snd_65 };
            choose_res_70 = id_77;
          }
          choose_res_65 = choose_res_70;
        }
        letpair_res_62 = choose_res_65;
      }
      let_res_61 = letpair_res_62;
    }
    ::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6 let_res_78;
    {
      ::dessser::gen::global_variable::tcb5a2028a026de335727b68454048f2c drec_75 { let_res_61 };
      ::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6 letpair_res_79;
      {
        auto drec_fst_76 { std::get<0>(drec_75) };
        auto drec_snd_77 { std::get<1>(drec_75) };
        auto fun80 { dessser::gen::field_name::of_row_binary };
        ::dessser::gen::global_variable::t18cecf882d7ac80cef37dfe6b22279d4 id_81 { fun80(drec_snd_77) };
        ::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6 let_res_82;
        {
          ::dessser::gen::global_variable::t18cecf882d7ac80cef37dfe6b22279d4 drec_78 { id_81 };
          ::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6 letpair_res_83;
          {
            auto drec_fst_79 { std::get<0>(drec_78) };
            auto drec_snd_80 { std::get<1>(drec_78) };
            auto fun84 { dessser::gen::raql_type::of_row_binary };
            ::dessser::gen::global_variable::t101502ffd7fb38beafe4b49259f92ba1 id_85 { fun84(drec_snd_80) };
            ::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6 letpair_res_86;
            {
              auto drec_fst_82 { std::get<0>(id_85) };
              auto drec_snd_83 { std::get<1>(id_85) };
              ::dessser::gen::global_variable::t id_87 { drec_fst_76, drec_fst_79, drec_fst_82 };
              ::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6 id_88 { id_87, drec_snd_83 };
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
std::function<::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_85" "make_snd_86" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_85") (identifier "make_snd_86"))))
 */
static std::function<::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6(Pointer &)> fun89 { [&](Pointer p_0) {
    ::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6 id_90 { of_row_binary(p_0) };
    ::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6 letpair_res_91;
    {
      auto make_fst_85 { std::get<0>(id_90) };
      auto make_snd_86 { std::get<1>(id_90) };
      ::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6 id_92 { make_fst_85, make_snd_86 };
      letpair_res_91 = id_92;
    }
    return letpair_res_91;
  }
   };
  return fun89;
}
std::function<::dessser::gen::global_variable::tc84f2fcbb1d2467c59aba5c8fcedbcc6(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{scope: [Program Void | Site Void | Global Void]; name: $field_name; typ: $raql_type}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::global_variable::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::global_variable::t &,Pointer &)> fun93 { [&](::dessser::gen::global_variable::t p_0, Pointer p_1) {
    Pointer id_94 { to_row_binary(p_0, p_1) };
    return id_94;
  }
   };
  return fun93;
}
std::function<Pointer(::dessser::gen::global_variable::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
