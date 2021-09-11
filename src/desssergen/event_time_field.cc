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


namespace dessser::gen::event_time_field {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t48a2d544f23c6703dc0a88c42484f480 : public std::variant<
  Void, // OutputField
  Void // Parameter
> { using variant::variant; };

inline bool operator==(t48a2d544f23c6703dc0a88c42484f480 const &a, t48a2d544f23c6703dc0a88c42484f480 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // OutputField
    case 1: return std::get<1>(a) == std::get<1>(b); // Parameter
  };
  return false;
}
inline bool operator!=(t48a2d544f23c6703dc0a88c42484f480 const &a, t48a2d544f23c6703dc0a88c42484f480 const &b) {
  return !operator==(a, b);
}
struct t : public std::tuple<
  dessser::gen::field_name::t_ext,
  ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480,
  double
> {
  using tuple::tuple;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::field_name::Deref(std::get<0>(a)) == ::dessser::gen::field_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tb57f62e74d28e552b9450388f3904f11 : public std::tuple<
  ::dessser::gen::event_time_field::t*,
  Pointer
> {
  using tuple::tuple;
  tb57f62e74d28e552b9450388f3904f11(std::tuple<::dessser::gen::event_time_field::t*, Pointer> p)
    : std::tuple<::dessser::gen::event_time_field::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb57f62e74d28e552b9450388f3904f11 const &a, tb57f62e74d28e552b9450388f3904f11 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb57f62e74d28e552b9450388f3904f11 const &a, tb57f62e74d28e552b9450388f3904f11 const &b) {
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
struct tb4035ae59572b883d902d5f2badfd8e0 : public std::tuple<
  ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480,
  Pointer
> {
  using tuple::tuple;
  tb4035ae59572b883d902d5f2badfd8e0(std::tuple<::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480, Pointer> p)
    : std::tuple<::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb4035ae59572b883d902d5f2badfd8e0 const &a, tb4035ae59572b883d902d5f2badfd8e0 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb4035ae59572b883d902d5f2badfd8e0 const &a, tb4035ae59572b883d902d5f2badfd8e0 const &b) {
  return !operator==(a, b);
}
struct tf568409f41c9c0a265f7302110fc9084 : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  tf568409f41c9c0a265f7302110fc9084(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf568409f41c9c0a265f7302110fc9084 const &a, tf568409f41c9c0a265f7302110fc9084 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf568409f41c9c0a265f7302110fc9084 const &a, tf568409f41c9c0a265f7302110fc9084 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("($field_name; [OutputField Void | Parameter Void]; FLOAT)" "Ptr")
      (let "stup_dst_93"
        (let "stup_dst_90" (apply (ext-identifier field_name to-row-binary) (get-item 0 (param 0)) (param 1))
          (let "ssum_dst_92" (write-u16 little-endian (identifier "stup_dst_90") (label-of (get-item 1 (param 0))))
            (if (eq (u16 0) (label-of (get-item 1 (param 0)))) (identifier "ssum_dst_92") (seq (assert (eq (label-of (get-item 1 (param 0))) (u16 1))) (identifier "ssum_dst_92")))))
        (write-u64 little-endian (identifier "stup_dst_93") (u64-of-float (get-item 2 (param 0))))))
 */
static std::function<Pointer(::dessser::gen::event_time_field::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::event_time_field::t*,Pointer)> fun0 { [&fun0](::dessser::gen::event_time_field::t* p_0, Pointer p_1) {
    auto fun1 { dessser::gen::field_name::to_row_binary };
    dessser::gen::field_name::t_ext id_2 { std::get<0>((*p_0)) };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer stup_dst_90 { id_3 };
      ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480 id_5 { std::get<1>((*p_0)) };
      uint16_t id_6 { uint16_t(id_5.index()) };
      Pointer id_7 { stup_dst_90.writeU16Le(id_6) };
      Pointer let_res_8;
      {
        Pointer ssum_dst_92 { id_7 };
        uint16_t id_9 { 0 };
        ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480 id_10 { std::get<1>((*p_0)) };
        uint16_t id_11 { uint16_t(id_10.index()) };
        bool id_12 { bool(id_9 == id_11) };
        Pointer choose_res_13;
        if (id_12) {
          choose_res_13 = ssum_dst_92;
        } else {
          ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480 id_14 { std::get<1>((*p_0)) };
          uint16_t id_15 { uint16_t(id_14.index()) };
          uint16_t id_16 { 1 };
          bool id_17 { bool(id_15 == id_16) };
          Void id_18 { ((void)(assert(id_17)), VOID) };
          (void)id_18;
          choose_res_13 = ssum_dst_92;
        }
        let_res_8 = choose_res_13;
      }
      let_res_4 = let_res_8;
    }
    Pointer let_res_19;
    {
      Pointer stup_dst_93 { let_res_4 };
      double id_20 { std::get<2>((*p_0)) };
      uint64_t id_21 { qword_of_float(id_20) };
      Pointer id_22 { stup_dst_93.writeU64Le(id_21) };
      let_res_19 = id_22;
    }
    return let_res_19;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::event_time_field::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("($field_name; [OutputField Void | Parameter Void]; FLOAT)")
      (add
        (let "sz_87" (apply (ext-identifier field_name sersize-of-row-binary) (get-item 0 (param 0)))
          (if (eq (u16 0) (label-of (get-item 1 (param 0)))) (add (identifier "sz_87") (size 2)) (seq (assert (eq (label-of (get-item 1 (param 0))) (u16 1))) (add (identifier "sz_87") (size 2))))) 
        (size 8)))
 */
static std::function<Size(::dessser::gen::event_time_field::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::event_time_field::t*)> fun23 { [&fun23](::dessser::gen::event_time_field::t* p_0) {
    auto fun24 { dessser::gen::field_name::sersize_of_row_binary };
    dessser::gen::field_name::t_ext id_25 { std::get<0>((*p_0)) };
    Size id_26 { fun24(id_25) };
    Size let_res_27;
    {
      Size sz_87 { id_26 };
      uint16_t id_28 { 0 };
      ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480 id_29 { std::get<1>((*p_0)) };
      uint16_t id_30 { uint16_t(id_29.index()) };
      bool id_31 { bool(id_28 == id_30) };
      Size choose_res_32;
      if (id_31) {
        Size id_33 { 2UL };
        Size id_34 { Size(sz_87 + id_33) };
        choose_res_32 = id_34;
      } else {
        ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480 id_35 { std::get<1>((*p_0)) };
        uint16_t id_36 { uint16_t(id_35.index()) };
        uint16_t id_37 { 1 };
        bool id_38 { bool(id_36 == id_37) };
        Void id_39 { ((void)(assert(id_38)), VOID) };
        (void)id_39;
        Size id_40 { 2UL };
        Size id_41 { Size(sz_87 + id_40) };
        choose_res_32 = id_41;
      }
      let_res_27 = choose_res_32;
    }
    Size id_42 { 8UL };
    Size id_43 { Size(let_res_27 + id_42) };
    return id_43;
  }
   };
  return fun23;
}
std::function<Size(::dessser::gen::event_time_field::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_56" (apply (ext-identifier field_name of-row-binary) (param 0))
        (let-pair "dtup_fst_57" "dtup_snd_58" (identifier "dtup_56")
          (let "dtup_74"
            (let "dsum1_65" (let-pair "du16_fst_60" "du16_snd_61" (read-u16 little-endian (identifier "dtup_snd_58")) (make-tup (identifier "du16_fst_60") (identifier "du16_snd_61")))
              (let-pair "dsum1_fst_66" "dsum1_snd_67" (identifier "dsum1_65")
                (if (eq (u16 0) (identifier "dsum1_fst_66")) (make-tup (construct "[OutputField Void | Parameter Void]" 0 (nop)) (identifier "dsum1_snd_67"))
                  (seq (assert (eq (identifier "dsum1_fst_66") (u16 1))) (make-tup (construct "[OutputField Void | Parameter Void]" 1 (nop)) (identifier "dsum1_snd_67"))))))
            (let-pair "dtup_fst_75" "dtup_snd_76" (identifier "dtup_74")
              (let-pair "dfloat_fst_78" "dfloat_snd_79" (read-u64 little-endian (identifier "dtup_snd_76"))
                (make-tup (make-tup (identifier "dtup_fst_57") (identifier "dtup_fst_75") (float-of-u64 (identifier "dfloat_fst_78"))) (identifier "dfloat_snd_79"))))))))
 */
static std::function<::dessser::gen::event_time_field::tb57f62e74d28e552b9450388f3904f11(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::event_time_field::tb57f62e74d28e552b9450388f3904f11(Pointer)> fun44 { [&fun44](Pointer p_0) {
    auto fun45 { dessser::gen::field_name::of_row_binary };
    ::dessser::gen::event_time_field::tacdfdbd490062d58073ca57b70932e6d id_46 { fun45(p_0) };
    ::dessser::gen::event_time_field::tb57f62e74d28e552b9450388f3904f11 let_res_47;
    {
      ::dessser::gen::event_time_field::tacdfdbd490062d58073ca57b70932e6d dtup_56 { id_46 };
      ::dessser::gen::event_time_field::tb57f62e74d28e552b9450388f3904f11 letpair_res_48;
      {
        auto dtup_fst_57 { std::get<0>(dtup_56) };
        auto dtup_snd_58 { std::get<1>(dtup_56) };
        ::dessser::gen::event_time_field::t7609d344c1ba69d0f80fec236d4c216b id_49 { dtup_snd_58.readU16Le() };
        ::dessser::gen::event_time_field::t7609d344c1ba69d0f80fec236d4c216b letpair_res_50;
        {
          auto du16_fst_60 { std::get<0>(id_49) };
          auto du16_snd_61 { std::get<1>(id_49) };
          ::dessser::gen::event_time_field::t7609d344c1ba69d0f80fec236d4c216b id_51 { du16_fst_60, du16_snd_61 };
          letpair_res_50 = id_51;
        }
        ::dessser::gen::event_time_field::tb4035ae59572b883d902d5f2badfd8e0 let_res_52;
        {
          ::dessser::gen::event_time_field::t7609d344c1ba69d0f80fec236d4c216b dsum1_65 { letpair_res_50 };
          ::dessser::gen::event_time_field::tb4035ae59572b883d902d5f2badfd8e0 letpair_res_53;
          {
            auto dsum1_fst_66 { std::get<0>(dsum1_65) };
            auto dsum1_snd_67 { std::get<1>(dsum1_65) };
            uint16_t id_54 { 0 };
            bool id_55 { bool(id_54 == dsum1_fst_66) };
            ::dessser::gen::event_time_field::tb4035ae59572b883d902d5f2badfd8e0 choose_res_56;
            if (id_55) {
              (void)VOID;
              ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480 id_57 { std::in_place_index<0>, VOID };
              ::dessser::gen::event_time_field::tb4035ae59572b883d902d5f2badfd8e0 id_58 { id_57, dsum1_snd_67 };
              choose_res_56 = id_58;
            } else {
              uint16_t id_59 { 1 };
              bool id_60 { bool(dsum1_fst_66 == id_59) };
              Void id_61 { ((void)(assert(id_60)), VOID) };
              (void)id_61;
              (void)VOID;
              ::dessser::gen::event_time_field::t48a2d544f23c6703dc0a88c42484f480 id_62 { std::in_place_index<1>, VOID };
              ::dessser::gen::event_time_field::tb4035ae59572b883d902d5f2badfd8e0 id_63 { id_62, dsum1_snd_67 };
              choose_res_56 = id_63;
            }
            letpair_res_53 = choose_res_56;
          }
          let_res_52 = letpair_res_53;
        }
        ::dessser::gen::event_time_field::tb57f62e74d28e552b9450388f3904f11 let_res_64;
        {
          ::dessser::gen::event_time_field::tb4035ae59572b883d902d5f2badfd8e0 dtup_74 { let_res_52 };
          ::dessser::gen::event_time_field::tb57f62e74d28e552b9450388f3904f11 letpair_res_65;
          {
            auto dtup_fst_75 { std::get<0>(dtup_74) };
            auto dtup_snd_76 { std::get<1>(dtup_74) };
            ::dessser::gen::event_time_field::tf568409f41c9c0a265f7302110fc9084 id_66 { dtup_snd_76.readU64Le() };
            ::dessser::gen::event_time_field::tb57f62e74d28e552b9450388f3904f11 letpair_res_67;
            {
              auto dfloat_fst_78 { std::get<0>(id_66) };
              auto dfloat_snd_79 { std::get<1>(id_66) };
              double id_68 { float_of_qword(dfloat_fst_78) };
              ::dessser::gen::event_time_field::t* id_69 { new ::dessser::gen::event_time_field::t(dtup_fst_57, dtup_fst_75, id_68) };
              ::dessser::gen::event_time_field::tb57f62e74d28e552b9450388f3904f11 id_70 { id_69, dfloat_snd_79 };
              letpair_res_67 = id_70;
            }
            letpair_res_65 = letpair_res_67;
          }
          let_res_64 = letpair_res_65;
        }
        letpair_res_48 = let_res_64;
      }
      let_res_47 = letpair_res_48;
    }
    return let_res_47;
  }
   };
  return fun44;
}
std::function<::dessser::gen::event_time_field::tb57f62e74d28e552b9450388f3904f11(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
