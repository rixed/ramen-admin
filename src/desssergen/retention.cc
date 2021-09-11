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
#include "desssergen/raql_expr.h"


namespace dessser::gen::retention {
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
  dessser::gen::raql_expr::t_ext duration;
  double period;
  t(dessser::gen::raql_expr::t_ext duration_, double period_) : duration(duration_), period(period_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::raql_expr::Deref(a.duration) == ::dessser::gen::raql_expr::Deref(b.duration) && a.period == b.period;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t3c1a4fa343f4d41a3f7803e33483ce83 : public std::tuple<
  ::dessser::gen::retention::t*,
  Pointer
> {
  using tuple::tuple;
  t3c1a4fa343f4d41a3f7803e33483ce83(std::tuple<::dessser::gen::retention::t*, Pointer> p)
    : std::tuple<::dessser::gen::retention::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3c1a4fa343f4d41a3f7803e33483ce83 const &a, t3c1a4fa343f4d41a3f7803e33483ce83 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3c1a4fa343f4d41a3f7803e33483ce83 const &a, t3c1a4fa343f4d41a3f7803e33483ce83 const &b) {
  return !operator==(a, b);
}
struct t4d1c3212c0e8c9a5379e25428b55556c : public std::tuple<
  dessser::gen::raql_expr::t_ext,
  Pointer
> {
  using tuple::tuple;
  t4d1c3212c0e8c9a5379e25428b55556c(std::tuple<dessser::gen::raql_expr::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_expr::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4d1c3212c0e8c9a5379e25428b55556c const &a, t4d1c3212c0e8c9a5379e25428b55556c const &b) {
  return ::dessser::gen::raql_expr::Deref(std::get<0>(a)) == ::dessser::gen::raql_expr::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4d1c3212c0e8c9a5379e25428b55556c const &a, t4d1c3212c0e8c9a5379e25428b55556c const &b) {
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
    (fun ("{duration: $raql_expr; period: FLOAT}" "Ptr")
      (let "srec_dst_70" (apply (ext-identifier raql_expr to-row-binary) (get-field "duration" (param 0)) (param 1)) (write-u64 little-endian (identifier "srec_dst_70") (u64-of-float (get-field "period" (param 0))))))
 */
static std::function<Pointer(::dessser::gen::retention::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::retention::t*,Pointer)> fun0 { [&fun0](::dessser::gen::retention::t* p_0, Pointer p_1) {
    auto fun1 { dessser::gen::raql_expr::to_row_binary };
    dessser::gen::raql_expr::t_ext id_2 { (*p_0).duration };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_70 { id_3 };
      double id_5 { (*p_0).period };
      uint64_t id_6 { qword_of_float(id_5) };
      Pointer id_7 { srec_dst_70.writeU64Le(id_6) };
      let_res_4 = id_7;
    }
    return let_res_4;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::retention::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{duration: $raql_expr; period: FLOAT}") (add (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "duration" (param 0))) (size 8)))
 */
static std::function<Size(::dessser::gen::retention::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::retention::t*)> fun8 { [&fun8](::dessser::gen::retention::t* p_0) {
    auto fun9 { dessser::gen::raql_expr::sersize_of_row_binary };
    dessser::gen::raql_expr::t_ext id_10 { (*p_0).duration };
    Size id_11 { fun9(id_10) };
    Size id_12 { 8UL };
    Size id_13 { Size(id_11 + id_12) };
    return id_13;
  }
   };
  return fun8;
}
std::function<Size(::dessser::gen::retention::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier raql_expr of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let-pair "dfloat_fst_60" "dfloat_snd_61" (read-u64 little-endian (identifier "drec_snd_58"))
            (make-tup (make-rec (string "period") (float-of-u64 (identifier "dfloat_fst_60")) (string "duration") (identifier "drec_fst_57")) (identifier "dfloat_snd_61"))))))
 */
static std::function<::dessser::gen::retention::t3c1a4fa343f4d41a3f7803e33483ce83(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::retention::t3c1a4fa343f4d41a3f7803e33483ce83(Pointer)> fun14 { [&fun14](Pointer p_0) {
    auto fun15 { dessser::gen::raql_expr::of_row_binary };
    ::dessser::gen::retention::t4d1c3212c0e8c9a5379e25428b55556c id_16 { fun15(p_0) };
    ::dessser::gen::retention::t3c1a4fa343f4d41a3f7803e33483ce83 let_res_17;
    {
      ::dessser::gen::retention::t4d1c3212c0e8c9a5379e25428b55556c drec_56 { id_16 };
      ::dessser::gen::retention::t3c1a4fa343f4d41a3f7803e33483ce83 letpair_res_18;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        ::dessser::gen::retention::tf568409f41c9c0a265f7302110fc9084 id_19 { drec_snd_58.readU64Le() };
        ::dessser::gen::retention::t3c1a4fa343f4d41a3f7803e33483ce83 letpair_res_20;
        {
          auto dfloat_fst_60 { std::get<0>(id_19) };
          auto dfloat_snd_61 { std::get<1>(id_19) };
          double id_21 { float_of_qword(dfloat_fst_60) };
          ::dessser::gen::retention::t* id_22 { new ::dessser::gen::retention::t({ .duration = drec_fst_57, .period = id_21 }) };
          ::dessser::gen::retention::t3c1a4fa343f4d41a3f7803e33483ce83 id_23 { id_22, dfloat_snd_61 };
          letpair_res_20 = id_23;
        }
        letpair_res_18 = letpair_res_20;
      }
      let_res_17 = letpair_res_18;
    }
    return let_res_17;
  }
   };
  return fun14;
}
std::function<::dessser::gen::retention::t3c1a4fa343f4d41a3f7803e33483ce83(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
