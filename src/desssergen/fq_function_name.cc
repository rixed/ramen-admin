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
#include "desssergen/function_name.h"
#include "desssergen/program_name.h"
#include "desssergen/site_name.h"


namespace dessser::gen::fq_function_name {
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
  dessser::gen::function_name::t_ext function;
  dessser::gen::program_name::t_ext program;
  dessser::gen::site_name::t_ext site;
  t(dessser::gen::function_name::t_ext function_, dessser::gen::program_name::t_ext program_, dessser::gen::site_name::t_ext site_) : function(function_), program(program_), site(site_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::function_name::Deref(a.function) == ::dessser::gen::function_name::Deref(b.function) && ::dessser::gen::program_name::Deref(a.program) == ::dessser::gen::program_name::Deref(b.program) && ::dessser::gen::site_name::Deref(a.site) == ::dessser::gen::site_name::Deref(b.site);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tf533ff813b5d329c8f12bc34e9fcc752 : public std::tuple<
  ::dessser::gen::fq_function_name::t*,
  Pointer
> {
  using tuple::tuple;
  tf533ff813b5d329c8f12bc34e9fcc752(std::tuple<::dessser::gen::fq_function_name::t*, Pointer> p)
    : std::tuple<::dessser::gen::fq_function_name::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf533ff813b5d329c8f12bc34e9fcc752 const &a, tf533ff813b5d329c8f12bc34e9fcc752 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf533ff813b5d329c8f12bc34e9fcc752 const &a, tf533ff813b5d329c8f12bc34e9fcc752 const &b) {
  return !operator==(a, b);
}
struct tff906bde0664efb2415be180e5a241ea : public std::tuple<
  dessser::gen::site_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tff906bde0664efb2415be180e5a241ea(std::tuple<dessser::gen::site_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::site_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tff906bde0664efb2415be180e5a241ea const &a, tff906bde0664efb2415be180e5a241ea const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tff906bde0664efb2415be180e5a241ea const &a, tff906bde0664efb2415be180e5a241ea const &b) {
  return !operator==(a, b);
}
struct t0e093472c41732c72d22288335ad8771 : public std::tuple<
  dessser::gen::program_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t0e093472c41732c72d22288335ad8771(std::tuple<dessser::gen::program_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::program_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0e093472c41732c72d22288335ad8771 const &a, t0e093472c41732c72d22288335ad8771 const &b) {
  return ::dessser::gen::program_name::Deref(std::get<0>(a)) == ::dessser::gen::program_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0e093472c41732c72d22288335ad8771 const &a, t0e093472c41732c72d22288335ad8771 const &b) {
  return !operator==(a, b);
}
struct te3e7208bccb6f553e92629f0b2acc200 : public std::tuple<
  dessser::gen::function_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  te3e7208bccb6f553e92629f0b2acc200(std::tuple<dessser::gen::function_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::function_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te3e7208bccb6f553e92629f0b2acc200 const &a, te3e7208bccb6f553e92629f0b2acc200 const &b) {
  return ::dessser::gen::function_name::Deref(std::get<0>(a)) == ::dessser::gen::function_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te3e7208bccb6f553e92629f0b2acc200 const &a, te3e7208bccb6f553e92629f0b2acc200 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{site: $site_name; program: $program_name; function: $function_name}" "Ptr")
      (let "srec_dst_72"
        (let "srec_dst_71" (apply (ext-identifier site_name to-row-binary) (get-field "site" (param 0)) (param 1)) (apply (ext-identifier program_name to-row-binary) (get-field "program" (param 0)) (identifier "srec_dst_71")))
        (apply (ext-identifier function_name to-row-binary) (get-field "function" (param 0)) (identifier "srec_dst_72"))))
 */
static std::function<Pointer(::dessser::gen::fq_function_name::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::fq_function_name::t*,Pointer)> fun0 { [&fun0](::dessser::gen::fq_function_name::t* p_0, Pointer p_1) {
    auto fun1 { dessser::gen::site_name::to_row_binary };
    dessser::gen::site_name::t_ext id_2 { (*p_0).site };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_71 { id_3 };
      auto fun5 { dessser::gen::program_name::to_row_binary };
      dessser::gen::program_name::t_ext id_6 { (*p_0).program };
      Pointer id_7 { fun5(id_6, srec_dst_71) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_72 { let_res_4 };
      auto fun9 { dessser::gen::function_name::to_row_binary };
      dessser::gen::function_name::t_ext id_10 { (*p_0).function };
      Pointer id_11 { fun9(id_10, srec_dst_72) };
      let_res_8 = id_11;
    }
    return let_res_8;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::fq_function_name::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{site: $site_name; program: $program_name; function: $function_name}")
      (let "sz_70"
        (let "sz_69" (apply (ext-identifier site_name sersize-of-row-binary) (get-field "site" (param 0))) (add (identifier "sz_69") (apply (ext-identifier program_name sersize-of-row-binary) (get-field "program" (param 0)))))
        (add (identifier "sz_70") (apply (ext-identifier function_name sersize-of-row-binary) (get-field "function" (param 0))))))
 */
static std::function<Size(::dessser::gen::fq_function_name::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::fq_function_name::t*)> fun12 { [&fun12](::dessser::gen::fq_function_name::t* p_0) {
    auto fun13 { dessser::gen::site_name::sersize_of_row_binary };
    dessser::gen::site_name::t_ext id_14 { (*p_0).site };
    Size id_15 { fun13(id_14) };
    Size let_res_16;
    {
      Size sz_69 { id_15 };
      auto fun17 { dessser::gen::program_name::sersize_of_row_binary };
      dessser::gen::program_name::t_ext id_18 { (*p_0).program };
      Size id_19 { fun17(id_18) };
      Size id_20 { Size(sz_69 + id_19) };
      let_res_16 = id_20;
    }
    Size let_res_21;
    {
      Size sz_70 { let_res_16 };
      auto fun22 { dessser::gen::function_name::sersize_of_row_binary };
      dessser::gen::function_name::t_ext id_23 { (*p_0).function };
      Size id_24 { fun22(id_23) };
      Size id_25 { Size(sz_70 + id_24) };
      let_res_21 = id_25;
    }
    return let_res_21;
  }
   };
  return fun12;
}
std::function<Size(::dessser::gen::fq_function_name::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier site_name of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let "drec_59" (apply (ext-identifier program_name of-row-binary) (identifier "drec_snd_58"))
            (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
              (let-pair "drec_fst_63" "drec_snd_64" (apply (ext-identifier function_name of-row-binary) (identifier "drec_snd_61"))
                (make-tup (make-rec (string "function") (identifier "drec_fst_63") (string "program") (identifier "drec_fst_60") (string "site") (identifier "drec_fst_57")) (identifier "drec_snd_64"))))))))
 */
static std::function<::dessser::gen::fq_function_name::tf533ff813b5d329c8f12bc34e9fcc752(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::fq_function_name::tf533ff813b5d329c8f12bc34e9fcc752(Pointer)> fun26 { [&fun26](Pointer p_0) {
    auto fun27 { dessser::gen::site_name::of_row_binary };
    ::dessser::gen::fq_function_name::tff906bde0664efb2415be180e5a241ea id_28 { fun27(p_0) };
    ::dessser::gen::fq_function_name::tf533ff813b5d329c8f12bc34e9fcc752 let_res_29;
    {
      ::dessser::gen::fq_function_name::tff906bde0664efb2415be180e5a241ea drec_56 { id_28 };
      ::dessser::gen::fq_function_name::tf533ff813b5d329c8f12bc34e9fcc752 letpair_res_30;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        auto fun31 { dessser::gen::program_name::of_row_binary };
        ::dessser::gen::fq_function_name::t0e093472c41732c72d22288335ad8771 id_32 { fun31(drec_snd_58) };
        ::dessser::gen::fq_function_name::tf533ff813b5d329c8f12bc34e9fcc752 let_res_33;
        {
          ::dessser::gen::fq_function_name::t0e093472c41732c72d22288335ad8771 drec_59 { id_32 };
          ::dessser::gen::fq_function_name::tf533ff813b5d329c8f12bc34e9fcc752 letpair_res_34;
          {
            auto drec_fst_60 { std::get<0>(drec_59) };
            auto drec_snd_61 { std::get<1>(drec_59) };
            auto fun35 { dessser::gen::function_name::of_row_binary };
            ::dessser::gen::fq_function_name::te3e7208bccb6f553e92629f0b2acc200 id_36 { fun35(drec_snd_61) };
            ::dessser::gen::fq_function_name::tf533ff813b5d329c8f12bc34e9fcc752 letpair_res_37;
            {
              auto drec_fst_63 { std::get<0>(id_36) };
              auto drec_snd_64 { std::get<1>(id_36) };
              ::dessser::gen::fq_function_name::t* id_38 { new ::dessser::gen::fq_function_name::t({ .function = drec_fst_63, .program = drec_fst_60, .site = drec_fst_57 }) };
              ::dessser::gen::fq_function_name::tf533ff813b5d329c8f12bc34e9fcc752 id_39 { id_38, drec_snd_64 };
              letpair_res_37 = id_39;
            }
            letpair_res_34 = letpair_res_37;
          }
          let_res_33 = letpair_res_34;
        }
        letpair_res_30 = let_res_33;
      }
      let_res_29 = letpair_res_30;
    }
    return let_res_29;
  }
   };
  return fun26;
}
std::function<::dessser::gen::fq_function_name::tf533ff813b5d329c8f12bc34e9fcc752(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}