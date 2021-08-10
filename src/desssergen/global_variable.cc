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

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

namespace dessser_gen {

/* ------------ */
/* Declarations */
/* ------------ */
struct c1cc8a2c9779db1c5df618b834848368 : public std::variant<
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, c1cc8a2c9779db1c5df618b834848368 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct t {
  c1cc8a2c9779db1c5df618b834848368 scope;
  *field_name name;
  *raql_type typ;
  bool operator==(t const &other) const {
    return scope == other.scope && name == other.name && typ == other.typ;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "scope:" << r.scope << ',';
  os << "name:" << r.name << ',';
  os << "typ:" << r.typ;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  uint16_t,
  Pointer
> v_362f9d9108a6902af48b6c83d5377ea1;

typedef std::tuple<
  c1cc8a2c9779db1c5df618b834848368,
  Pointer
> v_80e111c7e729759766c90bdf35a21d01;

typedef std::tuple<
  *field_name,
  Pointer
> c50aa083fa818c6eeca389b0025dda98;

typedef std::tuple<
  *raql_type,
  Pointer
> v_1afe9f73328d6d7bdf808b1d2eb2af22;

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
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    c1cc8a2c9779db1c5df618b834848368 id_1 { p_0.scope };
    uint16_t id_2 { uint16_t(id_1.index()) };
    Pointer id_3 { p_1.writeU16Le(id_2) };
    Pointer let_res_4;
    {
      Pointer ssum_dst_91 { id_3 };
      uint16_t id_5 { 0 };
      c1cc8a2c9779db1c5df618b834848368 id_6 { p_0.scope };
      uint16_t id_7 { uint16_t(id_6.index()) };
      bool id_8 { bool(id_5 == id_7) };
      Pointer choose_res_9;
      if (id_8) {
        choose_res_9 = ssum_dst_91;
      } else {
        uint16_t id_10 { 1 };
        c1cc8a2c9779db1c5df618b834848368 id_11 { p_0.scope };
        uint16_t id_12 { uint16_t(id_11.index()) };
        bool id_13 { bool(id_10 == id_12) };
        Pointer choose_res_14;
        if (id_13) {
          choose_res_14 = ssum_dst_91;
        } else {
          c1cc8a2c9779db1c5df618b834848368 id_15 { p_0.scope };
          uint16_t id_16 { uint16_t(id_15.index()) };
          uint16_t id_17 { 2 };
          bool id_18 { bool(id_16 == id_17) };
          Void id_19 { ((void)(assert(id_18)), VOID) };
          choose_res_14 = ssum_dst_91;
        }
        choose_res_9 = choose_res_14;
      }
      let_res_4 = choose_res_9;
    }
    Pointer let_res_20;
    {
      Pointer srec_dst_92 { let_res_4 };
      std::function<Pointer(*field_name,Pointer)> id_21 { dessser_gen::field_name.to_row_binary };
      *field_name id_22 { p_0.name };
      Pointer id_23 { id_21(id_22, srec_dst_92) };
      let_res_20 = id_23;
    }
    Pointer let_res_24;
    {
      Pointer srec_dst_93 { let_res_20 };
      std::function<Pointer(*raql_type,Pointer)> id_25 { dessser_gen::raql_type.to_row_binary };
      *raql_type id_26 { p_0.typ };
      Pointer id_27 { id_25(id_26, srec_dst_93) };
      let_res_24 = id_27;
    }
    return let_res_24;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{scope: [Program Void | Site Void | Global Void]; name: $field_name; typ: $raql_type}")
      (let "sz_89"
        (let "sz_88"
          (if (eq (u16 0) (label-of (get-field "scope" (param 0)))) (size 2) (if (eq (u16 1) (label-of (get-field "scope" (param 0)))) (size 2) (seq (assert (eq (label-of (get-field "scope" (param 0))) (u16 2))) (size 2))))
          (add (identifier "sz_88") (apply (ext-identifier field_name sersize-of-row-binary) (get-field "name" (param 0)))))
        (add (identifier "sz_89") (apply (ext-identifier raql_type sersize-of-row-binary) (get-field "typ" (param 0))))))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun28 { [&fun28](t p_0) {
    uint16_t id_29 { 0 };
    c1cc8a2c9779db1c5df618b834848368 id_30 { p_0.scope };
    uint16_t id_31 { uint16_t(id_30.index()) };
    bool id_32 { bool(id_29 == id_31) };
    Size choose_res_33;
    if (id_32) {
      Size id_34 { 2UL };
      choose_res_33 = id_34;
    } else {
      uint16_t id_35 { 1 };
      c1cc8a2c9779db1c5df618b834848368 id_36 { p_0.scope };
      uint16_t id_37 { uint16_t(id_36.index()) };
      bool id_38 { bool(id_35 == id_37) };
      Size choose_res_39;
      if (id_38) {
        Size id_40 { 2UL };
        choose_res_39 = id_40;
      } else {
        c1cc8a2c9779db1c5df618b834848368 id_41 { p_0.scope };
        uint16_t id_42 { uint16_t(id_41.index()) };
        uint16_t id_43 { 2 };
        bool id_44 { bool(id_42 == id_43) };
        Void id_45 { ((void)(assert(id_44)), VOID) };
        Size id_46 { 2UL };
        choose_res_39 = id_46;
      }
      choose_res_33 = choose_res_39;
    }
    Size let_res_47;
    {
      Size sz_88 { choose_res_33 };
      std::function<Size(*field_name)> id_48 { dessser_gen::field_name.sersize_of_row_binary };
      *field_name id_49 { p_0.name };
      Size id_50 { id_48(id_49) };
      Size id_51 { Size(sz_88 + id_50) };
      let_res_47 = id_51;
    }
    Size let_res_52;
    {
      Size sz_89 { let_res_47 };
      std::function<Size(*raql_type)> id_53 { dessser_gen::raql_type.sersize_of_row_binary };
      *raql_type id_54 { p_0.typ };
      Size id_55 { id_53(id_54) };
      Size id_56 { Size(sz_89 + id_55) };
      let_res_52 = id_56;
    }
    return let_res_52;
  }
   };
  return fun28;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

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
                (make-tup (make-rec (string "scope") (identifier "drec_fst_75") (string "name") (identifier "drec_fst_78") (string "typ") (identifier "drec_fst_81")) (identifier "drec_snd_82"))))))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun57 { [&fun57](Pointer p_0) {
    v_362f9d9108a6902af48b6c83d5377ea1 id_58 { p_0.readU16Le() };
    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_59;
    {
      auto du16_fst_57 { std::get<0>(id_58) };
      auto du16_snd_58 { std::get<1>(id_58) };
      v_362f9d9108a6902af48b6c83d5377ea1 id_60 {  du16_fst_57, du16_snd_58  };
      letpair_res_59 = id_60;
    }
    v_80e111c7e729759766c90bdf35a21d01 let_res_61;
    {
      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_62 { letpair_res_59 };
      v_80e111c7e729759766c90bdf35a21d01 letpair_res_62;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_63 { 0 };
        bool id_64 { bool(id_63 == dsum1_fst_63) };
        v_80e111c7e729759766c90bdf35a21d01 choose_res_65;
        if (id_64) {
          c1cc8a2c9779db1c5df618b834848368 id_66 { std::in_place_index<0>, VOID };
          v_80e111c7e729759766c90bdf35a21d01 id_67 {  id_66, dsum1_snd_64  };
          choose_res_65 = id_67;
        } else {
          uint16_t id_68 { 1 };
          bool id_69 { bool(id_68 == dsum1_fst_63) };
          v_80e111c7e729759766c90bdf35a21d01 choose_res_70;
          if (id_69) {
            c1cc8a2c9779db1c5df618b834848368 id_71 { std::in_place_index<1>, VOID };
            v_80e111c7e729759766c90bdf35a21d01 id_72 {  id_71, dsum1_snd_64  };
            choose_res_70 = id_72;
          } else {
            uint16_t id_73 { 2 };
            bool id_74 { bool(dsum1_fst_63 == id_73) };
            Void id_75 { ((void)(assert(id_74)), VOID) };
            c1cc8a2c9779db1c5df618b834848368 id_76 { std::in_place_index<2>, VOID };
            v_80e111c7e729759766c90bdf35a21d01 id_77 {  id_76, dsum1_snd_64  };
            choose_res_70 = id_77;
          }
          choose_res_65 = choose_res_70;
        }
        letpair_res_62 = choose_res_65;
      }
      let_res_61 = letpair_res_62;
    }
    f63f919559f0d70225bd0da5dd9bcafc let_res_78;
    {
      v_80e111c7e729759766c90bdf35a21d01 drec_74 { let_res_61 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_79;
      {
        auto drec_fst_75 { std::get<0>(drec_74) };
        auto drec_snd_76 { std::get<1>(drec_74) };
        std::function<c50aa083fa818c6eeca389b0025dda98(Pointer)> id_80 { dessser_gen::field_name.of_row_binary };
        c50aa083fa818c6eeca389b0025dda98 id_81 { id_80(drec_snd_76) };
        f63f919559f0d70225bd0da5dd9bcafc let_res_82;
        {
          c50aa083fa818c6eeca389b0025dda98 drec_77 { id_81 };
          f63f919559f0d70225bd0da5dd9bcafc letpair_res_83;
          {
            auto drec_fst_78 { std::get<0>(drec_77) };
            auto drec_snd_79 { std::get<1>(drec_77) };
            std::function<v_1afe9f73328d6d7bdf808b1d2eb2af22(Pointer)> id_84 { dessser_gen::raql_type.of_row_binary };
            v_1afe9f73328d6d7bdf808b1d2eb2af22 id_85 { id_84(drec_snd_79) };
            f63f919559f0d70225bd0da5dd9bcafc letpair_res_86;
            {
              auto drec_fst_81 { std::get<0>(id_85) };
              auto drec_snd_82 { std::get<1>(id_85) };
              t id_87 {  .scope = drec_fst_75, .name = drec_fst_78, .typ = drec_fst_81  };
              f63f919559f0d70225bd0da5dd9bcafc id_88 {  id_87, drec_snd_82  };
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
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
