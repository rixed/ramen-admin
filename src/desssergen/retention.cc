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
struct tc95d60afdce8d3b7a30d0873966b0116 : public std::tuple<
  std::shared_ptr<::dessser::gen::retention::t> ,
  Pointer
> {
  using tuple::tuple;
  tc95d60afdce8d3b7a30d0873966b0116(std::tuple<std::shared_ptr<::dessser::gen::retention::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::retention::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc95d60afdce8d3b7a30d0873966b0116 const &a, tc95d60afdce8d3b7a30d0873966b0116 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc95d60afdce8d3b7a30d0873966b0116 const &a, tc95d60afdce8d3b7a30d0873966b0116 const &b) {
  return !operator==(a, b);
}
struct tc473a3a3b5068e57b15e934d0afcc038 : public std::tuple<
  dessser::gen::raql_expr::t_ext,
  Pointer
> {
  using tuple::tuple;
  tc473a3a3b5068e57b15e934d0afcc038(std::tuple<dessser::gen::raql_expr::t_ext, Pointer> p)
    : std::tuple<dessser::gen::raql_expr::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc473a3a3b5068e57b15e934d0afcc038 const &a, tc473a3a3b5068e57b15e934d0afcc038 const &b) {
  return ::dessser::gen::raql_expr::Deref(std::get<0>(a)) == ::dessser::gen::raql_expr::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc473a3a3b5068e57b15e934d0afcc038 const &a, tc473a3a3b5068e57b15e934d0afcc038 const &b) {
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
    (fun ("{duration: $raql_expr; period: FLOAT}" "Ptr")
      (let "srec_dst_70" (apply (ext-identifier raql_expr to-row-binary) (get-field "duration" (param 0)) (param 1)) (write-u64 little-endian (identifier "srec_dst_70") (u64-of-float (get-field "period" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::retention::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::retention::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::retention::t>  p_0, Pointer p_1) {
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
std::function<Pointer(std::shared_ptr<::dessser::gen::retention::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{duration: $raql_expr; period: FLOAT}") (add (apply (ext-identifier raql_expr sersize-of-row-binary) (get-field "duration" (param 0))) (size 8)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::retention::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::retention::t> )> fun8 { [&](std::shared_ptr<::dessser::gen::retention::t>  p_0) {
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
std::function<Size(std::shared_ptr<::dessser::gen::retention::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_56" (apply (ext-identifier raql_expr of-row-binary) (param 0))
        (let-pair "drec_fst_57" "drec_snd_58" (identifier "drec_56")
          (let-pair "dfloat_fst_60" "dfloat_snd_61" (read-u64 little-endian (identifier "drec_snd_58"))
            (make-tup (make-rec (string "period") (float-of-u64 (identifier "dfloat_fst_60")) (string "duration") (identifier "drec_fst_57")) (identifier "dfloat_snd_61"))))))
 */
static std::function<::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116(Pointer)> fun14 { [&](Pointer p_0) {
    auto fun15 { dessser::gen::raql_expr::of_row_binary };
    ::dessser::gen::retention::tc473a3a3b5068e57b15e934d0afcc038 id_16 { fun15(p_0) };
    ::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116 let_res_17;
    {
      ::dessser::gen::retention::tc473a3a3b5068e57b15e934d0afcc038 drec_56 { id_16 };
      ::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116 letpair_res_18;
      {
        auto drec_fst_57 { std::get<0>(drec_56) };
        auto drec_snd_58 { std::get<1>(drec_56) };
        ::dessser::gen::retention::td2cd337bb3c8bc04d5603393d084985b id_19 { drec_snd_58.readU64Le() };
        ::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116 letpair_res_20;
        {
          auto dfloat_fst_60 { std::get<0>(id_19) };
          auto dfloat_snd_61 { std::get<1>(id_19) };
          double id_21 { float_of_qword(dfloat_fst_60) };
          std::shared_ptr<::dessser::gen::retention::t>  id_22 { std::make_shared<::dessser::gen::retention::t>(drec_fst_57, id_21) };
          ::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116 id_23 { id_22, dfloat_snd_61 };
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
std::function<::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_66" "make_snd_67" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_66") (identifier "make_snd_67"))))
 */
static std::function<::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116(Pointer)> fun24 { [&](Pointer p_0) {
    ::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116 id_25 { of_row_binary(p_0) };
    ::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116 letpair_res_26;
    {
      auto make_fst_66 { std::get<0>(id_25) };
      auto make_snd_67 { std::get<1>(id_25) };
      ::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116 id_27 { make_fst_66, make_snd_67 };
      letpair_res_26 = id_27;
    }
    return letpair_res_26;
  }
   };
  return fun24;
}
std::function<::dessser::gen::retention::tc95d60afdce8d3b7a30d0873966b0116(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{duration: $raql_expr; period: FLOAT}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::retention::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::retention::t> ,Pointer)> fun28 { [&](std::shared_ptr<::dessser::gen::retention::t>  p_0, Pointer p_1) {
    Pointer id_29 { to_row_binary(p_0, p_1) };
    return id_29;
  }
   };
  return fun28;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::retention::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
