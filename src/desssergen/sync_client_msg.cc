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
  uint32_t seq;
  bool confirm_success;
  bool echo;
  dessser::gen::sync_client_cmd::t_ext cmd;
  t(uint32_t seq_, bool confirm_success_, bool echo_, dessser::gen::sync_client_cmd::t_ext cmd_) : seq(seq_), confirm_success(confirm_success_), echo(echo_), cmd(cmd_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.seq == b.seq && a.confirm_success == b.confirm_success && a.echo == b.echo && ::dessser::gen::sync_client_cmd::Deref(a.cmd) == ::dessser::gen::sync_client_cmd::Deref(b.cmd);
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tfe3f0576fe9e9064fe3aa37bd76eb46a : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_client_msg::t> ,
  Pointer
> {
  using tuple::tuple;
  tfe3f0576fe9e9064fe3aa37bd76eb46a(std::tuple<std::shared_ptr<::dessser::gen::sync_client_msg::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_client_msg::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tfe3f0576fe9e9064fe3aa37bd76eb46a const &a, tfe3f0576fe9e9064fe3aa37bd76eb46a const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tfe3f0576fe9e9064fe3aa37bd76eb46a const &a, tfe3f0576fe9e9064fe3aa37bd76eb46a const &b) {
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
struct t938826a671b76f2c000eeb9bff80e50d : public std::tuple<
  dessser::gen::sync_client_cmd::t_ext,
  Pointer
> {
  using tuple::tuple;
  t938826a671b76f2c000eeb9bff80e50d(std::tuple<dessser::gen::sync_client_cmd::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_client_cmd::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t938826a671b76f2c000eeb9bff80e50d const &a, t938826a671b76f2c000eeb9bff80e50d const &b) {
  return ::dessser::gen::sync_client_cmd::Deref(std::get<0>(a)) == ::dessser::gen::sync_client_cmd::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t938826a671b76f2c000eeb9bff80e50d const &a, t938826a671b76f2c000eeb9bff80e50d const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{seq: U32; confirm_success: BOOL; echo: BOOL; cmd: $sync_client_cmd}" "Ptr")
      (let "srec_dst_87"
        (let "srec_dst_86" (let "srec_dst_85" (write-u32 little-endian (param 1) (get-field "seq" (param 0))) (write-u8 (identifier "srec_dst_85") (u8-of-bool (get-field "confirm_success" (param 0)))))
          (write-u8 (identifier "srec_dst_86") (u8-of-bool (get-field "echo" (param 0))))) 
        (apply (ext-identifier sync_client_cmd to-row-binary) (get-field "cmd" (param 0)) (identifier "srec_dst_87"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_msg::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_msg::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::sync_client_msg::t>  p_0, Pointer p_1) {
    uint32_t id_1 { (*p_0).seq };
    Pointer id_2 { p_1.writeU32Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_85 { id_2 };
      bool id_4 { (*p_0).confirm_success };
      uint8_t id_5 { uint8_t(id_4) };
      Pointer id_6 { srec_dst_85.writeU8(id_5) };
      let_res_3 = id_6;
    }
    Pointer let_res_7;
    {
      Pointer srec_dst_86 { let_res_3 };
      bool id_8 { (*p_0).echo };
      uint8_t id_9 { uint8_t(id_8) };
      Pointer id_10 { srec_dst_86.writeU8(id_9) };
      let_res_7 = id_10;
    }
    Pointer let_res_11;
    {
      Pointer srec_dst_87 { let_res_7 };
      auto fun12 { dessser::gen::sync_client_cmd::to_row_binary };
      dessser::gen::sync_client_cmd::t_ext id_13 { (*p_0).cmd };
      Pointer id_14 { fun12(id_13, srec_dst_87) };
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
  std::function<Size(std::shared_ptr<::dessser::gen::sync_client_msg::t> )> fun15 { [&](std::shared_ptr<::dessser::gen::sync_client_msg::t>  p_0) {
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
      (let "drec_60" (let-pair "du32_fst_58" "du32_snd_59" (read-u32 little-endian (param 0)) (make-tup (identifier "du32_fst_58") (identifier "du32_snd_59")))
        (let-pair "drec_fst_61" "drec_snd_62" (identifier "drec_60")
          (let "drec_66" (let-pair "dbool_fst_64" "dbool_snd_65" (read-u8 (identifier "drec_snd_62")) (make-tup (not (eq (identifier "dbool_fst_64") (u8 0))) (identifier "dbool_snd_65")))
            (let-pair "drec_fst_67" "drec_snd_68" (identifier "drec_66")
              (let "drec_72" (let-pair "dbool_fst_70" "dbool_snd_71" (read-u8 (identifier "drec_snd_68")) (make-tup (not (eq (identifier "dbool_fst_70") (u8 0))) (identifier "dbool_snd_71")))
                (let-pair "drec_fst_73" "drec_snd_74" (identifier "drec_72")
                  (let-pair "drec_fst_76" "drec_snd_77" (apply (ext-identifier sync_client_cmd of-row-binary) (identifier "drec_snd_74"))
                    (make-tup (make-rec (string "cmd") (identifier "drec_fst_76") (string "echo") (identifier "drec_fst_73") (string "confirm_success") (identifier "drec_fst_67") (string "seq") (identifier "drec_fst_61"))
                      (identifier "drec_snd_77"))))))))))
 */
static std::function<::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a(Pointer)> fun21 { [&](Pointer p_0) {
    ::dessser::gen::sync_client_msg::t491c44439106a32f896827242e8e76a1 id_22 { p_0.readU32Le() };
    ::dessser::gen::sync_client_msg::t491c44439106a32f896827242e8e76a1 letpair_res_23;
    {
      auto du32_fst_58 { std::get<0>(id_22) };
      auto du32_snd_59 { std::get<1>(id_22) };
      ::dessser::gen::sync_client_msg::t491c44439106a32f896827242e8e76a1 id_24 { du32_fst_58, du32_snd_59 };
      letpair_res_23 = id_24;
    }
    ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a let_res_25;
    {
      ::dessser::gen::sync_client_msg::t491c44439106a32f896827242e8e76a1 drec_60 { letpair_res_23 };
      ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a letpair_res_26;
      {
        auto drec_fst_61 { std::get<0>(drec_60) };
        auto drec_snd_62 { std::get<1>(drec_60) };
        ::dessser::gen::sync_client_msg::t1a5d74abf838df33f185a72a8912f5c9 id_27 { drec_snd_62.readU8() };
        ::dessser::gen::sync_client_msg::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_28;
        {
          auto dbool_fst_64 { std::get<0>(id_27) };
          auto dbool_snd_65 { std::get<1>(id_27) };
          uint8_t id_29 { 0 };
          bool id_30 { bool(dbool_fst_64 == id_29) };
          bool id_31 { ! id_30 };
          ::dessser::gen::sync_client_msg::tf9a0a3fefc87c9e10a93d3a172850c26 id_32 { id_31, dbool_snd_65 };
          letpair_res_28 = id_32;
        }
        ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a let_res_33;
        {
          ::dessser::gen::sync_client_msg::tf9a0a3fefc87c9e10a93d3a172850c26 drec_66 { letpair_res_28 };
          ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a letpair_res_34;
          {
            auto drec_fst_67 { std::get<0>(drec_66) };
            auto drec_snd_68 { std::get<1>(drec_66) };
            ::dessser::gen::sync_client_msg::t1a5d74abf838df33f185a72a8912f5c9 id_35 { drec_snd_68.readU8() };
            ::dessser::gen::sync_client_msg::tf9a0a3fefc87c9e10a93d3a172850c26 letpair_res_36;
            {
              auto dbool_fst_70 { std::get<0>(id_35) };
              auto dbool_snd_71 { std::get<1>(id_35) };
              uint8_t id_37 { 0 };
              bool id_38 { bool(dbool_fst_70 == id_37) };
              bool id_39 { ! id_38 };
              ::dessser::gen::sync_client_msg::tf9a0a3fefc87c9e10a93d3a172850c26 id_40 { id_39, dbool_snd_71 };
              letpair_res_36 = id_40;
            }
            ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a let_res_41;
            {
              ::dessser::gen::sync_client_msg::tf9a0a3fefc87c9e10a93d3a172850c26 drec_72 { letpair_res_36 };
              ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a letpair_res_42;
              {
                auto drec_fst_73 { std::get<0>(drec_72) };
                auto drec_snd_74 { std::get<1>(drec_72) };
                auto fun43 { dessser::gen::sync_client_cmd::of_row_binary };
                ::dessser::gen::sync_client_msg::t938826a671b76f2c000eeb9bff80e50d id_44 { fun43(drec_snd_74) };
                ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a letpair_res_45;
                {
                  auto drec_fst_76 { std::get<0>(id_44) };
                  auto drec_snd_77 { std::get<1>(id_44) };
                  std::shared_ptr<::dessser::gen::sync_client_msg::t>  id_46 { std::make_shared<::dessser::gen::sync_client_msg::t>(drec_fst_61, drec_fst_67, drec_fst_73, drec_fst_76) };
                  ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a id_47 { id_46, drec_snd_77 };
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
std::function<::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_79" "make_snd_80" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_79") (identifier "make_snd_80"))))
 */
static std::function<::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a(Pointer)> fun48 { [&](Pointer p_0) {
    ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a id_49 { of_row_binary(p_0) };
    ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a letpair_res_50;
    {
      auto make_fst_79 { std::get<0>(id_49) };
      auto make_snd_80 { std::get<1>(id_49) };
      ::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a id_51 { make_fst_79, make_snd_80 };
      letpair_res_50 = id_51;
    }
    return letpair_res_50;
  }
   };
  return fun48;
}
std::function<::dessser::gen::sync_client_msg::tfe3f0576fe9e9064fe3aa37bd76eb46a(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{seq: U32; confirm_success: BOOL; echo: BOOL; cmd: $sync_client_cmd}" "Ptr") (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_msg::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_msg::t> ,Pointer)> fun52 { [&](std::shared_ptr<::dessser::gen::sync_client_msg::t>  p_0, Pointer p_1) {
    Pointer id_53 { to_row_binary(p_0, p_1) };
    return id_53;
  }
   };
  return fun52;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_msg::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
