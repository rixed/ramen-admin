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
#include "desssergen/sync_client_cmd.h"


namespace dessser::gen::sync_client_msg {
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
  dessser::gen::sync_client_cmd::t_ext cmd;
  bool confirm_success;
  bool echo;
  uint32_t seq;
  t(dessser::gen::sync_client_cmd::t_ext cmd_, bool confirm_success_, bool echo_, uint32_t seq_) : cmd(cmd_), confirm_success(confirm_success_), echo(echo_), seq(seq_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return ::dessser::gen::sync_client_cmd::Deref(a.cmd) == ::dessser::gen::sync_client_cmd::Deref(b.cmd) && a.confirm_success == b.confirm_success && a.echo == b.echo && a.seq == b.seq;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tb7a2a03f105ea4d2c1ce1ff32010c20f : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_client_msg::t> ,
  Pointer
> {
  using tuple::tuple;
  tb7a2a03f105ea4d2c1ce1ff32010c20f(std::tuple<std::shared_ptr<::dessser::gen::sync_client_msg::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_client_msg::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb7a2a03f105ea4d2c1ce1ff32010c20f const &a, tb7a2a03f105ea4d2c1ce1ff32010c20f const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb7a2a03f105ea4d2c1ce1ff32010c20f const &a, tb7a2a03f105ea4d2c1ce1ff32010c20f const &b) {
  return !operator==(a, b);
}
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t883c6ffea47c0d7b950fe35881e3d737 const &a, t883c6ffea47c0d7b950fe35881e3d737 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t883c6ffea47c0d7b950fe35881e3d737 const &a, t883c6ffea47c0d7b950fe35881e3d737 const &b) {
  return !operator==(a, b);
}
struct t1566bd611d8a2b90669c241f5e8d6ff1 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1566bd611d8a2b90669c241f5e8d6ff1(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1566bd611d8a2b90669c241f5e8d6ff1 const &a, t1566bd611d8a2b90669c241f5e8d6ff1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1566bd611d8a2b90669c241f5e8d6ff1 const &a, t1566bd611d8a2b90669c241f5e8d6ff1 const &b) {
  return !operator==(a, b);
}
struct t8f6cce063b0da10e7eea29b507eded2e : public std::tuple<
  bool,
  Pointer
> {
  using tuple::tuple;
  t8f6cce063b0da10e7eea29b507eded2e(std::tuple<bool, Pointer> p)
    : std::tuple<bool, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8f6cce063b0da10e7eea29b507eded2e const &a, t8f6cce063b0da10e7eea29b507eded2e const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8f6cce063b0da10e7eea29b507eded2e const &a, t8f6cce063b0da10e7eea29b507eded2e const &b) {
  return !operator==(a, b);
}
struct t0ef78464875c1ff94b2ae01448b1998c : public std::tuple<
  dessser::gen::sync_client_cmd::t_ext,
  Pointer
> {
  using tuple::tuple;
  t0ef78464875c1ff94b2ae01448b1998c(std::tuple<dessser::gen::sync_client_cmd::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_client_cmd::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0ef78464875c1ff94b2ae01448b1998c const &a, t0ef78464875c1ff94b2ae01448b1998c const &b) {
  return ::dessser::gen::sync_client_cmd::Deref(std::get<0>(a)) == ::dessser::gen::sync_client_cmd::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0ef78464875c1ff94b2ae01448b1998c const &a, t0ef78464875c1ff94b2ae01448b1998c const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{seq: U32; confirm_success: BOOL; echo: BOOL; cmd: $sync_client_cmd}" "Ptr")
      (let "srec_dst_86"
        (let "srec_dst_85" (let "srec_dst_84" (write-u32 little-endian (param 1) (get-field "seq" (param 0))) (write-u8 (identifier "srec_dst_84") (u8-of-bool (get-field "confirm_success" (param 0)))))
          (write-u8 (identifier "srec_dst_85") (u8-of-bool (get-field "echo" (param 0))))) 
        (apply (ext-identifier sync_client_cmd to-row-binary) (get-field "cmd" (param 0)) (identifier "srec_dst_86"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_msg::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_msg::t> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::sync_client_msg::t>  p_0, Pointer p_1) {
    uint32_t id_1 { (*p_0).seq };
    Pointer id_2 { p_1.writeU32Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_84 { id_2 };
      bool id_4 { (*p_0).confirm_success };
      uint8_t id_5 { uint8_t(id_4) };
      Pointer id_6 { srec_dst_84.writeU8(id_5) };
      let_res_3 = id_6;
    }
    Pointer let_res_7;
    {
      Pointer srec_dst_85 { let_res_3 };
      bool id_8 { (*p_0).echo };
      uint8_t id_9 { uint8_t(id_8) };
      Pointer id_10 { srec_dst_85.writeU8(id_9) };
      let_res_7 = id_10;
    }
    Pointer let_res_11;
    {
      Pointer srec_dst_86 { let_res_7 };
      auto fun12 { dessser::gen::sync_client_cmd::to_row_binary };
      dessser::gen::sync_client_cmd::t_ext id_13 { (*p_0).cmd };
      Pointer id_14 { fun12(id_13, srec_dst_86) };
      let_res_11 = id_14;
    }
    return let_res_11;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_msg::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{seq: U32; confirm_success: BOOL; echo: BOOL; cmd: $sync_client_cmd}") (add (size 6) (apply (ext-identifier sync_client_cmd sersize-of-row-binary) (get-field "cmd" (param 0)))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_client_msg::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_client_msg::t> )> fun15 { [&fun15](std::shared_ptr<::dessser::gen::sync_client_msg::t>  p_0) {
    Size id_16 { 6UL };
    auto fun17 { dessser::gen::sync_client_cmd::sersize_of_row_binary };
    dessser::gen::sync_client_cmd::t_ext id_18 { (*p_0).cmd };
    Size id_19 { fun17(id_18) };
    Size id_20 { Size(id_16 + id_19) };
    return id_20;
  }
   };
  return fun15;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_client_msg::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_59" (let-pair "du32_fst_57" "du32_snd_58" (read-u32 little-endian (param 0)) (make-tup (identifier "du32_fst_57") (identifier "du32_snd_58")))
        (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
          (let "drec_65" (let-pair "dbool_fst_63" "dbool_snd_64" (read-u8 (identifier "drec_snd_61")) (make-tup (not (eq (identifier "dbool_fst_63") (u8 0))) (identifier "dbool_snd_64")))
            (let-pair "drec_fst_66" "drec_snd_67" (identifier "drec_65")
              (let "drec_71" (let-pair "dbool_fst_69" "dbool_snd_70" (read-u8 (identifier "drec_snd_67")) (make-tup (not (eq (identifier "dbool_fst_69") (u8 0))) (identifier "dbool_snd_70")))
                (let-pair "drec_fst_72" "drec_snd_73" (identifier "drec_71")
                  (let-pair "drec_fst_75" "drec_snd_76" (apply (ext-identifier sync_client_cmd of-row-binary) (identifier "drec_snd_73"))
                    (make-tup (make-rec (string "cmd") (identifier "drec_fst_75") (string "echo") (identifier "drec_fst_72") (string "confirm_success") (identifier "drec_fst_66") (string "seq") (identifier "drec_fst_60"))
                      (identifier "drec_snd_76"))))))))))
 */
static std::function<::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f(Pointer)> fun21 { [&fun21](Pointer p_0) {
    ::dessser::gen::sync_client_msg::t883c6ffea47c0d7b950fe35881e3d737 id_22 { p_0.readU32Le() };
    ::dessser::gen::sync_client_msg::t883c6ffea47c0d7b950fe35881e3d737 letpair_res_23;
    {
      auto du32_fst_57 { std::get<0>(id_22) };
      auto du32_snd_58 { std::get<1>(id_22) };
      ::dessser::gen::sync_client_msg::t883c6ffea47c0d7b950fe35881e3d737 id_24 { du32_fst_57, du32_snd_58 };
      letpair_res_23 = id_24;
    }
    ::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f let_res_25;
    {
      ::dessser::gen::sync_client_msg::t883c6ffea47c0d7b950fe35881e3d737 drec_59 { letpair_res_23 };
      ::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f letpair_res_26;
      {
        auto drec_fst_60 { std::get<0>(drec_59) };
        auto drec_snd_61 { std::get<1>(drec_59) };
        ::dessser::gen::sync_client_msg::t1566bd611d8a2b90669c241f5e8d6ff1 id_27 { drec_snd_61.readU8() };
        ::dessser::gen::sync_client_msg::t8f6cce063b0da10e7eea29b507eded2e letpair_res_28;
        {
          auto dbool_fst_63 { std::get<0>(id_27) };
          auto dbool_snd_64 { std::get<1>(id_27) };
          uint8_t id_29 { 0 };
          bool id_30 { bool(dbool_fst_63 == id_29) };
          bool id_31 { ! id_30 };
          ::dessser::gen::sync_client_msg::t8f6cce063b0da10e7eea29b507eded2e id_32 { id_31, dbool_snd_64 };
          letpair_res_28 = id_32;
        }
        ::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f let_res_33;
        {
          ::dessser::gen::sync_client_msg::t8f6cce063b0da10e7eea29b507eded2e drec_65 { letpair_res_28 };
          ::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f letpair_res_34;
          {
            auto drec_fst_66 { std::get<0>(drec_65) };
            auto drec_snd_67 { std::get<1>(drec_65) };
            ::dessser::gen::sync_client_msg::t1566bd611d8a2b90669c241f5e8d6ff1 id_35 { drec_snd_67.readU8() };
            ::dessser::gen::sync_client_msg::t8f6cce063b0da10e7eea29b507eded2e letpair_res_36;
            {
              auto dbool_fst_69 { std::get<0>(id_35) };
              auto dbool_snd_70 { std::get<1>(id_35) };
              uint8_t id_37 { 0 };
              bool id_38 { bool(dbool_fst_69 == id_37) };
              bool id_39 { ! id_38 };
              ::dessser::gen::sync_client_msg::t8f6cce063b0da10e7eea29b507eded2e id_40 { id_39, dbool_snd_70 };
              letpair_res_36 = id_40;
            }
            ::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f let_res_41;
            {
              ::dessser::gen::sync_client_msg::t8f6cce063b0da10e7eea29b507eded2e drec_71 { letpair_res_36 };
              ::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f letpair_res_42;
              {
                auto drec_fst_72 { std::get<0>(drec_71) };
                auto drec_snd_73 { std::get<1>(drec_71) };
                auto fun43 { dessser::gen::sync_client_cmd::of_row_binary };
                ::dessser::gen::sync_client_msg::t0ef78464875c1ff94b2ae01448b1998c id_44 { fun43(drec_snd_73) };
                ::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f letpair_res_45;
                {
                  auto drec_fst_75 { std::get<0>(id_44) };
                  auto drec_snd_76 { std::get<1>(id_44) };
                  std::shared_ptr<::dessser::gen::sync_client_msg::t>  id_46 { std::make_shared<::dessser::gen::sync_client_msg::t>(drec_fst_75, drec_fst_66, drec_fst_72, drec_fst_60) };
                  ::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f id_47 { id_46, drec_snd_76 };
                  letpair_res_45 = id_47;
                }
                letpair_res_42 = letpair_res_45;
              }
              let_res_41 = letpair_res_42;
            }
            letpair_res_34 = let_res_41;
          }
          let_res_33 = letpair_res_34;
        }
        letpair_res_26 = let_res_33;
      }
      let_res_25 = letpair_res_26;
    }
    return let_res_25;
  }
   };
  return fun21;
}
std::function<::dessser::gen::sync_client_msg::tb7a2a03f105ea4d2c1ce1ff32010c20f(Pointer)> of_row_binary(of_row_binary_init());


}
