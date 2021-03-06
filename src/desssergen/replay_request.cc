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
#include "desssergen/sync_key.h"
#include "desssergen/fq_function_name.h"

namespace dessser::gen::replay_request {
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
  dessser::gen::fq_function_name::t_ext target;
  double since;
  double until;
  bool explain;
  dessser::gen::sync_key::t_ext resp_key;
  t(dessser::gen::fq_function_name::t_ext target_, double since_, double until_, bool explain_, dessser::gen::sync_key::t_ext resp_key_) : target(target_), since(since_), until(until_), explain(explain_), resp_key(resp_key_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::fq_function_name::Deref(a.target) == ::dessser::gen::fq_function_name::Deref(b.target) && a.since == b.since && a.until == b.until && a.explain == b.explain && ::dessser::gen::sync_key::Deref(a.resp_key) == ::dessser::gen::sync_key::Deref(b.resp_key);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tcfdae0eebc6d2c4c070de31c29d5d722 : public std::tuple<
  ::dessser::gen::replay_request::t,
  Pointer
> {
  using tuple::tuple;
  tcfdae0eebc6d2c4c070de31c29d5d722(std::tuple<::dessser::gen::replay_request::t, Pointer> p)
    : std::tuple<::dessser::gen::replay_request::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcfdae0eebc6d2c4c070de31c29d5d722 const &a, tcfdae0eebc6d2c4c070de31c29d5d722 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcfdae0eebc6d2c4c070de31c29d5d722 const &a, tcfdae0eebc6d2c4c070de31c29d5d722 const &b) {
  return !operator==(a, b);
}
struct tafdf48d85e3efdf5b24e3fa2741562be : public std::tuple<
  dessser::gen::fq_function_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tafdf48d85e3efdf5b24e3fa2741562be(std::tuple<dessser::gen::fq_function_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_function_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tafdf48d85e3efdf5b24e3fa2741562be const &a, tafdf48d85e3efdf5b24e3fa2741562be const &b) {
  return ::dessser::gen::fq_function_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_function_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tafdf48d85e3efdf5b24e3fa2741562be const &a, tafdf48d85e3efdf5b24e3fa2741562be const &b) {
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
struct t9a758baeff17224a77e1a522010b4168 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t9a758baeff17224a77e1a522010b4168(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
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
struct tf9a0a3fefc87c9e10a93d3a172850c26 : public std::tuple<
  bool,
  Pointer
> {
  using tuple::tuple;
  tf9a0a3fefc87c9e10a93d3a172850c26(std::tuple<bool, Pointer> p)
    : std::tuple<bool, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf9a0a3fefc87c9e10a93d3a172850c26 const &a, tf9a0a3fefc87c9e10a93d3a172850c26 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf9a0a3fefc87c9e10a93d3a172850c26 const &a, tf9a0a3fefc87c9e10a93d3a172850c26 const &b) {
  return !operator==(a, b);
}
struct t0e7f6ba9e1ceef343afe44456f9067ec : public std::tuple<
  dessser::gen::sync_key::t_ext,
  Pointer
> {
  using tuple::tuple;
  t0e7f6ba9e1ceef343afe44456f9067ec(std::tuple<dessser::gen::sync_key::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_key::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0e7f6ba9e1ceef343afe44456f9067ec const &a, t0e7f6ba9e1ceef343afe44456f9067ec const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0e7f6ba9e1ceef343afe44456f9067ec const &a, t0e7f6ba9e1ceef343afe44456f9067ec const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{target: $fq_function_name; since: FLOAT; until: FLOAT; explain: BOOL; resp_key: $sync_key}" "Ptr")
      (let "srec_dst_92"
        (let "srec_dst_91"
          (let "srec_dst_90"
            (let "srec_dst_89" (apply (ext-identifier fq_function_name to-row-binary) (get-field "target" (param 0)) (param 1)) (write-u64 little-endian (identifier "srec_dst_89") (u64-of-float (get-field "since" (param 0)))))
            (write-u64 little-endian (identifier "srec_dst_90") (u64-of-float (get-field "until" (param 0))))) 
          (write-u8 (identifier "srec_dst_91") (u8-of-bool (get-field "explain" (param 0))))) 
        (apply (ext-identifier sync_key to-row-binary) (get-field "resp_key" (param 0)) (identifier "srec_dst_92"))))
 */
static std::function<Pointer(::dessser::gen::replay_request::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::replay_request::t &,Pointer &)> fun0 { [&](::dessser::gen::replay_request::t p_0, Pointer p_1) {
    auto fun1 { dessser::gen::fq_function_name::to_row_binary };
    dessser::gen::fq_function_name::t_ext id_2 { p_0.target };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer srec_dst_89 { id_3 };
      double id_5 { p_0.since };
      uint64_t id_6 { qword_of_float(id_5) };
      Pointer id_7 { srec_dst_89.writeU64Le(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_90 { let_res_4 };
      double id_9 { p_0.until };
      uint64_t id_10 { qword_of_float(id_9) };
      Pointer id_11 { srec_dst_90.writeU64Le(id_10) };
      let_res_8 = id_11;
    }
    Pointer let_res_12;
    {
      Pointer srec_dst_91 { let_res_8 };
      bool id_13 { p_0.explain };
      uint8_t id_14 { uint8_t(id_13) };
      Pointer id_15 { srec_dst_91.writeU8(id_14) };
      let_res_12 = id_15;
    }
    Pointer let_res_16;
    {
      Pointer srec_dst_92 { let_res_12 };
      auto fun17 { dessser::gen::sync_key::to_row_binary };
      dessser::gen::sync_key::t_ext id_18 { p_0.resp_key };
      Pointer id_19 { fun17(id_18, srec_dst_92) };
      let_res_16 = id_19;
    }
    return let_res_16;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::replay_request::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{target: $fq_function_name; since: FLOAT; until: FLOAT; explain: BOOL; resp_key: $sync_key}")
      (let "sz_88" (add (add (add (apply (ext-identifier fq_function_name sersize-of-row-binary) (get-field "target" (param 0))) (size 8)) (size 8)) (size 1))
        (add (identifier "sz_88") (apply (ext-identifier sync_key sersize-of-row-binary) (get-field "resp_key" (param 0))))))
 */
static std::function<Size(::dessser::gen::replay_request::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::replay_request::t &)> fun20 { [&](::dessser::gen::replay_request::t p_0) {
    auto fun21 { dessser::gen::fq_function_name::sersize_of_row_binary };
    dessser::gen::fq_function_name::t_ext id_22 { p_0.target };
    Size id_23 { fun21(id_22) };
    Size id_24 { 8UL };
    Size id_25 { Size(id_23 + id_24) };
    Size id_26 { 8UL };
    Size id_27 { Size(id_25 + id_26) };
    Size id_28 { 1UL };
    Size id_29 { Size(id_27 + id_28) };
    Size let_res_30;
    {
      Size sz_88 { id_29 };
      auto fun31 { dessser::gen::sync_key::sersize_of_row_binary };
      dessser::gen::sync_key::t_ext id_32 { p_0.resp_key };
      Size id_33 { fun31(id_32) };
      Size id_34 { Size(sz_88 + id_33) };
      let_res_30 = id_34;
    }
    return let_res_30;
  }
   };
  return fun20;
}
std::function<Size(::dessser::gen::replay_request::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_57" (apply (ext-identifier fq_function_name of-row-binary) (param 0))
        (let-pair "drec_fst_58" "drec_snd_59" (identifier "drec_57")
          (let "drec_63" (let-pair "dfloat_fst_61" "dfloat_snd_62" (read-u64 little-endian (identifier "drec_snd_59")) (make-tup (float-of-u64 (identifier "dfloat_fst_61")) (identifier "dfloat_snd_62")))
            (let-pair "drec_fst_64" "drec_snd_65" (identifier "drec_63")
              (let "drec_69" (let-pair "dfloat_fst_67" "dfloat_snd_68" (read-u64 little-endian (identifier "drec_snd_65")) (make-tup (float-of-u64 (identifier "dfloat_fst_67")) (identifier "dfloat_snd_68")))
                (let-pair "drec_fst_70" "drec_snd_71" (identifier "drec_69")
                  (let "drec_75" (let-pair "dbool_fst_73" "dbool_snd_74" (read-u8 (identifier "drec_snd_71")) (make-tup (not (eq (identifier "dbool_fst_73") (u8 0))) (identifier "dbool_snd_74")))
                    (let-pair "drec_fst_76" "drec_snd_77" (identifier "drec_75")
                      (let-pair "drec_fst_79" "drec_snd_80" (apply (ext-identifier sync_key of-row-binary) (identifier "drec_snd_77"))
                        (make-tup
                          (make-rec (string "resp_key") (identifier "drec_fst_79") 
                            (string "explain") (identifier "drec_fst_76") 
                            (string "until") (identifier "drec_fst_70") 
                            (string "since") (identifier "drec_fst_64") 
                            (string "target") (identifier "drec_fst_58")) 
                          (identifier "drec_snd_80"))))))))))))
 */
static std::function<::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722(Pointer &)> fun35 { [&](Pointer p_0) {
    auto fun36 { dessser::gen::fq_function_name::of_row_binary };
    ::dessser::gen::replay_request::tafdf48d85e3efdf5b24e3fa2741562be id_37 { fun36(p_0) };
    ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 let_res_38;
    {
      ::dessser::gen::replay_request::tafdf48d85e3efdf5b24e3fa2741562be drec_57 { id_37 };
      ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 letpair_res_39;
      {
        auto drec_fst_58 { std::get<0>(drec_57) };
        auto drec_snd_59 { std::get<1>(drec_57) };
        ::dessser::gen::replay_request::td2cd337bb3c8bc04d5603393d084985b id_40 { drec_snd_59.readU64Le() };
        ::dessser::gen::replay_request::t9a758baeff17224a77e1a522010b4168 letpair_res_41;
        {
          auto dfloat_fst_61 { std::get<0>(id_40) };
          auto dfloat_snd_62 { std::get<1>(id_40) };
          double id_42 { float_of_qword(dfloat_fst_61) };
          ::dessser::gen::replay_request::t9a758baeff17224a77e1a522010b4168 id_43 { id_42, dfloat_snd_62 };
          letpair_res_41 = id_43;
        }
        ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 let_res_44;
        {
          ::dessser::gen::replay_request::t9a758baeff17224a77e1a522010b4168 drec_63 { letpair_res_41 };
          ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 letpair_res_45;
          {
            auto drec_fst_64 { std::get<0>(drec_63) };
            auto drec_snd_65 { std::get<1>(drec_63) };
            ::dessser::gen::replay_request::td2cd337bb3c8bc04d5603393d084985b id_46 { drec_snd_65.readU64Le() };
            ::dessser::gen::replay_request::t9a758baeff17224a77e1a522010b4168 letpair_res_47;
            {
              auto dfloat_fst_67 { std::get<0>(id_46) };
              auto dfloat_snd_68 { std::get<1>(id_46) };
              double id_48 { float_of_qword(dfloat_fst_67) };
              ::dessser::gen::replay_request::t9a758baeff17224a77e1a522010b4168 id_49 { id_48, dfloat_snd_68 };
              letpair_res_47 = id_49;
            }
            ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 let_res_50;
            {
              ::dessser::gen::replay_request::t9a758baeff17224a77e1a522010b4168 drec_69 { letpair_res_47 };
              ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 letpair_res_51;
              {
                auto drec_fst_70 { std::get<0>(drec_69) };
                auto drec_snd_71 { std::get<1>(drec_69) };
                ::dessser::gen::replay_request::t1a5d74abf838df33f185a72a8912f5c9 id_52 { drec_snd_71.readU8() };
                ::dessser::gen::replay_request::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_53;
                {
                  auto dbool_fst_73 { std::get<0>(id_52) };
                  auto dbool_snd_74 { std::get<1>(id_52) };
                  uint8_t id_54 { 0 };
                  bool id_55 { bool(dbool_fst_73 == id_54) };
                  bool id_56 { ! id_55 };
                  ::dessser::gen::replay_request::tf9a0a3fefc87c9e10a93d3a172850c26 id_57 { id_56, dbool_snd_74 };
                  letpair_res_53 = id_57;
                }
                ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 let_res_58;
                {
                  ::dessser::gen::replay_request::tf9a0a3fefc87c9e10a93d3a172850c26 drec_75 { letpair_res_53 };
                  ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 letpair_res_59;
                  {
                    auto drec_fst_76 { std::get<0>(drec_75) };
                    auto drec_snd_77 { std::get<1>(drec_75) };
                    auto fun60 { dessser::gen::sync_key::of_row_binary };
                    ::dessser::gen::replay_request::t0e7f6ba9e1ceef343afe44456f9067ec id_61 { fun60(drec_snd_77) };
                    ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 letpair_res_62;
                    {
                      auto drec_fst_79 { std::get<0>(id_61) };
                      auto drec_snd_80 { std::get<1>(id_61) };
                      ::dessser::gen::replay_request::t id_63 { drec_fst_58, drec_fst_64, drec_fst_70, drec_fst_76, drec_fst_79 };
                      ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 id_64 { id_63, drec_snd_80 };
                      letpair_res_62 = id_64;
                    }
                    letpair_res_59 = letpair_res_62;
                  }
                  let_res_58 = letpair_res_59;
                }
                letpair_res_51 = let_res_58;
              }
              let_res_50 = letpair_res_51;
            }
            letpair_res_45 = let_res_50;
          }
          let_res_44 = letpair_res_45;
        }
        letpair_res_39 = let_res_44;
      }
      let_res_38 = letpair_res_39;
    }
    return let_res_38;
  }
   };
  return fun35;
}
std::function<::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_82" "make_snd_83" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_82") (identifier "make_snd_83"))))
 */
static std::function<::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722(Pointer &)> fun65 { [&](Pointer p_0) {
    ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 id_66 { of_row_binary(p_0) };
    ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 letpair_res_67;
    {
      auto make_fst_82 { std::get<0>(id_66) };
      auto make_snd_83 { std::get<1>(id_66) };
      ::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722 id_68 { make_fst_82, make_snd_83 };
      letpair_res_67 = id_68;
    }
    return letpair_res_67;
  }
   };
  return fun65;
}
std::function<::dessser::gen::replay_request::tcfdae0eebc6d2c4c070de31c29d5d722(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{target: $fq_function_name; since: FLOAT; until: FLOAT; explain: BOOL; resp_key: $sync_key}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::replay_request::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::replay_request::t &,Pointer &)> fun69 { [&](::dessser::gen::replay_request::t p_0, Pointer p_1) {
    Pointer id_70 { to_row_binary(p_0, p_1) };
    return id_70;
  }
   };
  return fun69;
}
std::function<Pointer(::dessser::gen::replay_request::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
