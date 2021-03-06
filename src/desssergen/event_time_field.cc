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
enum t168aeaddd2d2bd1c09c4d0fcc52d226f {
  OutputField,
  Parameter,
};

constexpr size_t t168aeaddd2d2bd1c09c4d0fcc52d226f_size { 2 };
struct t : public std::tuple<
  dessser::gen::field_name::t_ext,
  ::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f,
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
struct tc1fc09471ee4464e5fc85213a52a12e7 : public std::tuple<
  ::dessser::gen::event_time_field::t,
  Pointer
> {
  using tuple::tuple;
  tc1fc09471ee4464e5fc85213a52a12e7(std::tuple<::dessser::gen::event_time_field::t, Pointer> p)
    : std::tuple<::dessser::gen::event_time_field::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc1fc09471ee4464e5fc85213a52a12e7 const &a, tc1fc09471ee4464e5fc85213a52a12e7 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc1fc09471ee4464e5fc85213a52a12e7 const &a, tc1fc09471ee4464e5fc85213a52a12e7 const &b) {
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
struct tc1bc462a6796fc3e81d942b4b687ad1f : public std::tuple<
  ::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f,
  Pointer
> {
  using tuple::tuple;
  tc1bc462a6796fc3e81d942b4b687ad1f(std::tuple<::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f, Pointer> p)
    : std::tuple<::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc1bc462a6796fc3e81d942b4b687ad1f const &a, tc1bc462a6796fc3e81d942b4b687ad1f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc1bc462a6796fc3e81d942b4b687ad1f const &a, tc1bc462a6796fc3e81d942b4b687ad1f const &b) {
  return !operator==(a, b);
}
struct td2cd337bb3c8bc04d5603393d084985b : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  td2cd337bb3c8bc04d5603393d084985b(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("($field_name; [OutputField Void | Parameter Void]; FLOAT)" "Ptr")
      (let "stup_dst_94"
        (let "stup_dst_91" (apply (ext-identifier field_name to-row-binary) (get-item 0 (param 0)) (param 1))
          (let "ssum_dst_93" (write-u16 little-endian (identifier "stup_dst_91") (label-of (get-item 1 (param 0))))
            (if (eq (u16 0) (label-of (get-item 1 (param 0)))) (identifier "ssum_dst_93") (seq (assert (eq (label-of (get-item 1 (param 0))) (u16 1))) (identifier "ssum_dst_93")))))
        (write-u64 little-endian (identifier "stup_dst_94") (u64-of-float (get-item 2 (param 0))))))
 */
static std::function<Pointer(::dessser::gen::event_time_field::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::event_time_field::t &,Pointer &)> fun0 { [&](::dessser::gen::event_time_field::t p_0, Pointer p_1) {
    auto fun1 { dessser::gen::field_name::to_row_binary };
    dessser::gen::field_name::t_ext id_2 { std::get<0>(p_0) };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer stup_dst_91 { id_3 };
      ::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f id_5 { std::get<1>(p_0) };
      uint16_t id_6 { uint16_t(id_5) };
      Pointer id_7 { stup_dst_91.writeU16Le(id_6) };
      Pointer let_res_8;
      {
        Pointer ssum_dst_93 { id_7 };
        uint16_t id_9 { 0 };
        ::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f id_10 { std::get<1>(p_0) };
        uint16_t id_11 { uint16_t(id_10) };
        bool id_12 { bool(id_9 == id_11) };
        Pointer choose_res_13;
        if (id_12) {
          choose_res_13 = ssum_dst_93;
        } else {
          ::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f id_14 { std::get<1>(p_0) };
          uint16_t id_15 { uint16_t(id_14) };
          uint16_t id_16 { 1 };
          bool id_17 { bool(id_15 == id_16) };
          Void id_18 { ((void)(assert(id_17)), ::dessser::Void()) };
          (void)id_18;
          choose_res_13 = ssum_dst_93;
        }
        let_res_8 = choose_res_13;
      }
      let_res_4 = let_res_8;
    }
    Pointer let_res_19;
    {
      Pointer stup_dst_94 { let_res_4 };
      double id_20 { std::get<2>(p_0) };
      uint64_t id_21 { qword_of_float(id_20) };
      Pointer id_22 { stup_dst_94.writeU64Le(id_21) };
      let_res_19 = id_22;
    }
    return let_res_19;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::event_time_field::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("($field_name; [OutputField Void | Parameter Void]; FLOAT)")
      (add
        (let "sz_88" (apply (ext-identifier field_name sersize-of-row-binary) (get-item 0 (param 0)))
          (if (eq (u16 0) (label-of (get-item 1 (param 0)))) (add (identifier "sz_88") (size 2)) (seq (assert (eq (label-of (get-item 1 (param 0))) (u16 1))) (add (identifier "sz_88") (size 2))))) 
        (size 8)))
 */
static std::function<Size(::dessser::gen::event_time_field::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::event_time_field::t &)> fun23 { [&](::dessser::gen::event_time_field::t p_0) {
    auto fun24 { dessser::gen::field_name::sersize_of_row_binary };
    dessser::gen::field_name::t_ext id_25 { std::get<0>(p_0) };
    Size id_26 { fun24(id_25) };
    Size let_res_27;
    {
      Size sz_88 { id_26 };
      uint16_t id_28 { 0 };
      ::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f id_29 { std::get<1>(p_0) };
      uint16_t id_30 { uint16_t(id_29) };
      bool id_31 { bool(id_28 == id_30) };
      Size choose_res_32;
      if (id_31) {
        Size id_33 { 2UL };
        Size id_34 { Size(sz_88 + id_33) };
        choose_res_32 = id_34;
      } else {
        ::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f id_35 { std::get<1>(p_0) };
        uint16_t id_36 { uint16_t(id_35) };
        uint16_t id_37 { 1 };
        bool id_38 { bool(id_36 == id_37) };
        Void id_39 { ((void)(assert(id_38)), ::dessser::Void()) };
        (void)id_39;
        Size id_40 { 2UL };
        Size id_41 { Size(sz_88 + id_40) };
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
std::function<Size(::dessser::gen::event_time_field::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_57" (apply (ext-identifier field_name of-row-binary) (param 0))
        (let-pair "dtup_fst_58" "dtup_snd_59" (identifier "dtup_57")
          (let "dtup_75"
            (let "dsum1_66" (let-pair "du16_fst_61" "du16_snd_62" (read-u16 little-endian (identifier "dtup_snd_59")) (make-tup (identifier "du16_fst_61") (identifier "du16_snd_62")))
              (let-pair "dsum1_fst_67" "dsum1_snd_68" (identifier "dsum1_66")
                (if (eq (u16 0) (identifier "dsum1_fst_67")) (make-tup (construct "[OutputField Void | Parameter Void]" 0 (nop)) (identifier "dsum1_snd_68"))
                  (seq (assert (eq (identifier "dsum1_fst_67") (u16 1))) (make-tup (construct "[OutputField Void | Parameter Void]" 1 (nop)) (identifier "dsum1_snd_68"))))))
            (let-pair "dtup_fst_76" "dtup_snd_77" (identifier "dtup_75")
              (let-pair "dfloat_fst_79" "dfloat_snd_80" (read-u64 little-endian (identifier "dtup_snd_77"))
                (make-tup (make-tup (identifier "dtup_fst_58") (identifier "dtup_fst_76") (float-of-u64 (identifier "dfloat_fst_79"))) (identifier "dfloat_snd_80"))))))))
 */
static std::function<::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7(Pointer &)> fun44 { [&](Pointer p_0) {
    auto fun45 { dessser::gen::field_name::of_row_binary };
    ::dessser::gen::event_time_field::t18cecf882d7ac80cef37dfe6b22279d4 id_46 { fun45(p_0) };
    ::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7 let_res_47;
    {
      ::dessser::gen::event_time_field::t18cecf882d7ac80cef37dfe6b22279d4 dtup_57 { id_46 };
      ::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7 letpair_res_48;
      {
        auto dtup_fst_58 { std::get<0>(dtup_57) };
        auto dtup_snd_59 { std::get<1>(dtup_57) };
        ::dessser::gen::event_time_field::ta97bb48ed75bbda6173555873826c8c6 id_49 { dtup_snd_59.readU16Le() };
        ::dessser::gen::event_time_field::ta97bb48ed75bbda6173555873826c8c6 letpair_res_50;
        {
          auto du16_fst_61 { std::get<0>(id_49) };
          auto du16_snd_62 { std::get<1>(id_49) };
          ::dessser::gen::event_time_field::ta97bb48ed75bbda6173555873826c8c6 id_51 { du16_fst_61, du16_snd_62 };
          letpair_res_50 = id_51;
        }
        ::dessser::gen::event_time_field::tc1bc462a6796fc3e81d942b4b687ad1f let_res_52;
        {
          ::dessser::gen::event_time_field::ta97bb48ed75bbda6173555873826c8c6 dsum1_66 { letpair_res_50 };
          ::dessser::gen::event_time_field::tc1bc462a6796fc3e81d942b4b687ad1f letpair_res_53;
          {
            auto dsum1_fst_67 { std::get<0>(dsum1_66) };
            auto dsum1_snd_68 { std::get<1>(dsum1_66) };
            uint16_t id_54 { 0 };
            bool id_55 { bool(id_54 == dsum1_fst_67) };
            ::dessser::gen::event_time_field::tc1bc462a6796fc3e81d942b4b687ad1f choose_res_56;
            if (id_55) {
              (void)::dessser::Void();
              ::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f id_57 { OutputField };
              ::dessser::gen::event_time_field::tc1bc462a6796fc3e81d942b4b687ad1f id_58 { id_57, dsum1_snd_68 };
              choose_res_56 = id_58;
            } else {
              uint16_t id_59 { 1 };
              bool id_60 { bool(dsum1_fst_67 == id_59) };
              Void id_61 { ((void)(assert(id_60)), ::dessser::Void()) };
              (void)id_61;
              (void)::dessser::Void();
              ::dessser::gen::event_time_field::t168aeaddd2d2bd1c09c4d0fcc52d226f id_62 { Parameter };
              ::dessser::gen::event_time_field::tc1bc462a6796fc3e81d942b4b687ad1f id_63 { id_62, dsum1_snd_68 };
              choose_res_56 = id_63;
            }
            letpair_res_53 = choose_res_56;
          }
          let_res_52 = letpair_res_53;
        }
        ::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7 let_res_64;
        {
          ::dessser::gen::event_time_field::tc1bc462a6796fc3e81d942b4b687ad1f dtup_75 { let_res_52 };
          ::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7 letpair_res_65;
          {
            auto dtup_fst_76 { std::get<0>(dtup_75) };
            auto dtup_snd_77 { std::get<1>(dtup_75) };
            ::dessser::gen::event_time_field::td2cd337bb3c8bc04d5603393d084985b id_66 { dtup_snd_77.readU64Le() };
            ::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7 letpair_res_67;
            {
              auto dfloat_fst_79 { std::get<0>(id_66) };
              auto dfloat_snd_80 { std::get<1>(id_66) };
              double id_68 { float_of_qword(dfloat_fst_79) };
              ::dessser::gen::event_time_field::t id_69 { dtup_fst_58, dtup_fst_76, id_68 };
              ::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7 id_70 { id_69, dfloat_snd_80 };
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
std::function<::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_85" "make_snd_86" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_85") (identifier "make_snd_86"))))
 */
static std::function<::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7(Pointer &)> fun71 { [&](Pointer p_0) {
    ::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7 id_72 { of_row_binary(p_0) };
    ::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7 letpair_res_73;
    {
      auto make_fst_85 { std::get<0>(id_72) };
      auto make_snd_86 { std::get<1>(id_72) };
      ::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7 id_74 { make_fst_85, make_snd_86 };
      letpair_res_73 = id_74;
    }
    return letpair_res_73;
  }
   };
  return fun71;
}
std::function<::dessser::gen::event_time_field::tc1fc09471ee4464e5fc85213a52a12e7(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("($field_name; [OutputField Void | Parameter Void]; FLOAT)" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::event_time_field::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::event_time_field::t &,Pointer &)> fun75 { [&](::dessser::gen::event_time_field::t p_0, Pointer p_1) {
    Pointer id_76 { to_row_binary(p_0, p_1) };
    return id_76;
  }
   };
  return fun75;
}
std::function<Pointer(::dessser::gen::event_time_field::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
