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

namespace dessser::gen::sync_socket {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t690438e8d106ddec68c668ab00e5188a : public std::variant<
  uint32_t, // v4
  uint128_t // v6
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t690438e8d106ddec68c668ab00e5188a const &a, t690438e8d106ddec68c668ab00e5188a const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // v4
    case 1: return std::get<1>(a) == std::get<1>(b); // v6
  };
  return false;
}
inline bool operator!=(t690438e8d106ddec68c668ab00e5188a const &a, t690438e8d106ddec68c668ab00e5188a const &b) {
  return !operator==(a, b);
}
struct t {
  ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a ip;
  uint16_t port;
  t(::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a ip_, uint16_t port_) : ip(ip_), port(port_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.ip == b.ip && a.port == b.port;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tc5e6846e85f79c9786f90afd8b73dfb1 : public std::tuple<
  ::dessser::gen::sync_socket::t,
  Pointer
> {
  using tuple::tuple;
  tc5e6846e85f79c9786f90afd8b73dfb1(std::tuple<::dessser::gen::sync_socket::t, Pointer> p)
    : std::tuple<::dessser::gen::sync_socket::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc5e6846e85f79c9786f90afd8b73dfb1 const &a, tc5e6846e85f79c9786f90afd8b73dfb1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc5e6846e85f79c9786f90afd8b73dfb1 const &a, tc5e6846e85f79c9786f90afd8b73dfb1 const &b) {
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
struct t1f9e0c0c8d7eb3b4c2d57ec0ad21851a : public std::tuple<
  ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a,
  Pointer
> {
  using tuple::tuple;
  t1f9e0c0c8d7eb3b4c2d57ec0ad21851a(std::tuple<::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a, Pointer> p)
    : std::tuple<::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1f9e0c0c8d7eb3b4c2d57ec0ad21851a const &a, t1f9e0c0c8d7eb3b4c2d57ec0ad21851a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1f9e0c0c8d7eb3b4c2d57ec0ad21851a const &a, t1f9e0c0c8d7eb3b4c2d57ec0ad21851a const &b) {
  return !operator==(a, b);
}
struct t491c44439106a32f896827242e8e76a1 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t491c44439106a32f896827242e8e76a1(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return !operator==(a, b);
}
struct t859e6a4cc938643a1d59426a3bf7b15a : public std::tuple<
  uint128_t,
  Pointer
> {
  using tuple::tuple;
  t859e6a4cc938643a1d59426a3bf7b15a(std::tuple<uint128_t, Pointer> p)
    : std::tuple<uint128_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t859e6a4cc938643a1d59426a3bf7b15a const &a, t859e6a4cc938643a1d59426a3bf7b15a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t859e6a4cc938643a1d59426a3bf7b15a const &a, t859e6a4cc938643a1d59426a3bf7b15a const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{ip: Ip; port: U16}" "Ptr")
      (let "srec_dst_104"
        (let "ssum_dst_103" (write-u16 little-endian (param 1) (label-of (get-field "ip" (param 0))))
          (if (eq (u16 0) (label-of (get-field "ip" (param 0)))) (write-u32 little-endian (identifier "ssum_dst_103") (get-alt "v4" (get-field "ip" (param 0))))
            (seq (assert (eq (label-of (get-field "ip" (param 0))) (u16 1))) (write-u128 little-endian (identifier "ssum_dst_103") (get-alt "v6" (get-field "ip" (param 0)))))))
        (write-u16 little-endian (identifier "srec_dst_104") (get-field "port" (param 0)))))
 */
static std::function<Pointer(::dessser::gen::sync_socket::t const &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_socket::t const &,Pointer &)> fun0 { [&](::dessser::gen::sync_socket::t p_0, Pointer p_1) {
    ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a id_1 { p_0.ip };
    uint16_t id_2 { uint16_t(id_1.index()) };
    Pointer id_3 { p_1.writeU16Le(id_2) };
    Pointer let_res_4;
    {
      Pointer ssum_dst_103 { id_3 };
      uint16_t id_5 { 0 };
      ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a id_6 { p_0.ip };
      uint16_t id_7 { uint16_t(id_6.index()) };
      bool id_8 { bool(id_5 == id_7) };
      Pointer choose_res_9;
      if (id_8) {
        ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a id_10 { p_0.ip };
        uint32_t id_11 { std::get<0 /* v4 */>(id_10) };
        Pointer id_12 { ssum_dst_103.writeU32Le(id_11) };
        choose_res_9 = id_12;
      } else {
        ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a id_13 { p_0.ip };
        uint16_t id_14 { uint16_t(id_13.index()) };
        uint16_t id_15 { 1 };
        bool id_16 { bool(id_14 == id_15) };
        Void id_17 { ((void)(assert(id_16)), ::dessser::Void()) };
        (void)id_17;
        ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a id_18 { p_0.ip };
        uint128_t id_19 { std::get<1 /* v6 */>(id_18) };
        Pointer id_20 { ssum_dst_103.writeU128Le(id_19) };
        choose_res_9 = id_20;
      }
      let_res_4 = choose_res_9;
    }
    Pointer let_res_21;
    {
      Pointer srec_dst_104 { let_res_4 };
      uint16_t id_22 { p_0.port };
      Pointer id_23 { srec_dst_104.writeU16Le(id_22) };
      let_res_21 = id_23;
    }
    return let_res_21;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::sync_socket::t const &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{ip: Ip; port: U16}") (add (if (eq (u16 0) (label-of (get-field "ip" (param 0)))) (size 6) (seq (assert (eq (label-of (get-field "ip" (param 0))) (u16 1))) (size 18))) (size 2)))
 */
static std::function<Size(::dessser::gen::sync_socket::t const &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_socket::t const &)> fun24 { [&](::dessser::gen::sync_socket::t p_0) {
    uint16_t id_25 { 0 };
    ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a id_26 { p_0.ip };
    uint16_t id_27 { uint16_t(id_26.index()) };
    bool id_28 { bool(id_25 == id_27) };
    Size choose_res_29;
    if (id_28) {
      Size id_30 { 6UL };
      choose_res_29 = id_30;
    } else {
      ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a id_31 { p_0.ip };
      uint16_t id_32 { uint16_t(id_31.index()) };
      uint16_t id_33 { 1 };
      bool id_34 { bool(id_32 == id_33) };
      Void id_35 { ((void)(assert(id_34)), ::dessser::Void()) };
      (void)id_35;
      Size id_36 { 18UL };
      choose_res_29 = id_36;
    }
    Size id_37 { 2UL };
    Size id_38 { Size(choose_res_29 + id_37) };
    return id_38;
  }
   };
  return fun24;
}
std::function<Size(::dessser::gen::sync_socket::t const &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_87"
        (let-pair "des_usr_type_fst_85" "des_usr_type_snd_86"
          (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
            (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
              (if (eq (u16 0) (identifier "dsum1_fst_64"))
                (let-pair "du32_fst_76" "du32_snd_77" (read-u32 little-endian (identifier "dsum1_snd_65")) (make-tup (construct "[v4 Ip4 | v6 Ip6]" 0 (make-usr "Ip4" (identifier "du32_fst_76"))) (identifier "du32_snd_77")))
                (seq (assert (eq (identifier "dsum1_fst_64") (u16 1)))
                  (let-pair "di128_fst_67" "di128_snd_68" (read-u128 little-endian (identifier "dsum1_snd_65"))
                    (make-tup (construct "[v4 Ip4 | v6 Ip6]" 1 (make-usr "Ip6" (identifier "di128_fst_67"))) (identifier "di128_snd_68")))))))
          (make-tup (make-usr "Ip" (identifier "des_usr_type_fst_85")) (identifier "des_usr_type_snd_86")))
        (let-pair "drec_fst_88" "drec_snd_89" (identifier "drec_87")
          (let-pair "du16_fst_91" "du16_snd_92" (read-u16 little-endian (identifier "drec_snd_89"))
            (make-tup (make-rec (string "port") (identifier "du16_fst_91") (string "ip") (identifier "drec_fst_88")) (identifier "du16_snd_92"))))))
 */
static std::function<::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1(Pointer &)> fun39 { [&](Pointer p_0) {
    ::dessser::gen::sync_socket::ta97bb48ed75bbda6173555873826c8c6 id_40 { p_0.readU16Le() };
    ::dessser::gen::sync_socket::ta97bb48ed75bbda6173555873826c8c6 letpair_res_41;
    {
      auto du16_fst_58 { std::get<0>(id_40) };
      auto du16_snd_59 { std::get<1>(id_40) };
      ::dessser::gen::sync_socket::ta97bb48ed75bbda6173555873826c8c6 id_42 { du16_fst_58, du16_snd_59 };
      letpair_res_41 = id_42;
    }
    ::dessser::gen::sync_socket::t1f9e0c0c8d7eb3b4c2d57ec0ad21851a let_res_43;
    {
      ::dessser::gen::sync_socket::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_41 };
      ::dessser::gen::sync_socket::t1f9e0c0c8d7eb3b4c2d57ec0ad21851a letpair_res_44;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_45 { 0 };
        bool id_46 { bool(id_45 == dsum1_fst_64) };
        ::dessser::gen::sync_socket::t1f9e0c0c8d7eb3b4c2d57ec0ad21851a choose_res_47;
        if (id_46) {
          ::dessser::gen::sync_socket::t491c44439106a32f896827242e8e76a1 id_48 { dsum1_snd_65.readU32Le() };
          ::dessser::gen::sync_socket::t1f9e0c0c8d7eb3b4c2d57ec0ad21851a letpair_res_49;
          {
            auto du32_fst_76 { std::get<0>(id_48) };
            auto du32_snd_77 { std::get<1>(id_48) };
            std::function<uint32_t(uint32_t const )> fun50 { [&](uint32_t p_0) {
              return p_0;
            }
             };
            uint32_t id_51 { fun50(du32_fst_76) };
            ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a id_52 { std::in_place_index<0>, id_51 };
            ::dessser::gen::sync_socket::t1f9e0c0c8d7eb3b4c2d57ec0ad21851a id_53 { id_52, du32_snd_77 };
            letpair_res_49 = id_53;
          }
          choose_res_47 = letpair_res_49;
        } else {
          uint16_t id_54 { 1 };
          bool id_55 { bool(dsum1_fst_64 == id_54) };
          Void id_56 { ((void)(assert(id_55)), ::dessser::Void()) };
          (void)id_56;
          ::dessser::gen::sync_socket::t859e6a4cc938643a1d59426a3bf7b15a id_57 { dsum1_snd_65.readU128Le() };
          ::dessser::gen::sync_socket::t1f9e0c0c8d7eb3b4c2d57ec0ad21851a letpair_res_58;
          {
            auto di128_fst_67 { std::get<0>(id_57) };
            auto di128_snd_68 { std::get<1>(id_57) };
            std::function<uint128_t(uint128_t const )> fun59 { [&](uint128_t p_0) {
              return p_0;
            }
             };
            uint128_t id_60 { fun59(di128_fst_67) };
            ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a id_61 { std::in_place_index<1>, id_60 };
            ::dessser::gen::sync_socket::t1f9e0c0c8d7eb3b4c2d57ec0ad21851a id_62 { id_61, di128_snd_68 };
            letpair_res_58 = id_62;
          }
          choose_res_47 = letpair_res_58;
        }
        letpair_res_44 = choose_res_47;
      }
      let_res_43 = letpair_res_44;
    }
    ::dessser::gen::sync_socket::t1f9e0c0c8d7eb3b4c2d57ec0ad21851a letpair_res_63;
    {
      auto des_usr_type_fst_85 { std::get<0>(let_res_43) };
      auto des_usr_type_snd_86 { std::get<1>(let_res_43) };
      std::function<::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a(::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a const &)> fun64 { [&](::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a p_0) {
        return p_0;
      }
       };
      ::dessser::gen::sync_socket::t690438e8d106ddec68c668ab00e5188a id_65 { fun64(des_usr_type_fst_85) };
      ::dessser::gen::sync_socket::t1f9e0c0c8d7eb3b4c2d57ec0ad21851a id_66 { id_65, des_usr_type_snd_86 };
      letpair_res_63 = id_66;
    }
    ::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1 let_res_67;
    {
      ::dessser::gen::sync_socket::t1f9e0c0c8d7eb3b4c2d57ec0ad21851a drec_87 { letpair_res_63 };
      ::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1 letpair_res_68;
      {
        auto drec_fst_88 { std::get<0>(drec_87) };
        auto drec_snd_89 { std::get<1>(drec_87) };
        ::dessser::gen::sync_socket::ta97bb48ed75bbda6173555873826c8c6 id_69 { drec_snd_89.readU16Le() };
        ::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1 letpair_res_70;
        {
          auto du16_fst_91 { std::get<0>(id_69) };
          auto du16_snd_92 { std::get<1>(id_69) };
          ::dessser::gen::sync_socket::t id_71 { drec_fst_88, du16_fst_91 };
          ::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1 id_72 { id_71, du16_snd_92 };
          letpair_res_70 = id_72;
        }
        letpair_res_68 = letpair_res_70;
      }
      let_res_67 = letpair_res_68;
    }
    return let_res_67;
  }
   };
  return fun39;
}
std::function<::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_97" "make_snd_98" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_97") (identifier "make_snd_98"))))
 */
static std::function<::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1(Pointer &)> fun73 { [&](Pointer p_0) {
    ::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1 id_74 { of_row_binary(p_0) };
    ::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1 letpair_res_75;
    {
      auto make_fst_97 { std::get<0>(id_74) };
      auto make_snd_98 { std::get<1>(id_74) };
      ::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1 id_76 { make_fst_97, make_snd_98 };
      letpair_res_75 = id_76;
    }
    return letpair_res_75;
  }
   };
  return fun73;
}
std::function<::dessser::gen::sync_socket::tc5e6846e85f79c9786f90afd8b73dfb1(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{ip: Ip; port: U16}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::sync_socket::t const &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_socket::t const &,Pointer &)> fun77 { [&](::dessser::gen::sync_socket::t p_0, Pointer p_1) {
    Pointer id_78 { to_row_binary(p_0, p_1) };
    return id_78;
  }
   };
  return fun77;
}
std::function<Pointer(::dessser::gen::sync_socket::t const &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
