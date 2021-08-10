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
struct t {
  uint32_t seq;
  bool confirm_success;
  bool echo;
  *sync_client_cmd cmd;
  bool operator==(t const &other) const {
    return seq == other.seq && confirm_success == other.confirm_success && echo == other.echo && cmd == other.cmd;
  }
};
std::ostream &operator<<(std::ostream &os, t const &r) {
  os << '{';
  os << "seq:" << r.seq << ',';
  os << "confirm_success:" << r.confirm_success << ',';
  os << "echo:" << r.echo << ',';
  os << "cmd:" << r.cmd;
  os << '}';
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  uint32_t,
  Pointer
> ac0fbd05039f742d2f1d9ac182e392ab;

typedef std::tuple<
  uint8_t,
  Pointer
> v_1d5843897434feb24d158f3793db9189;

typedef std::tuple<
  bool,
  Pointer
> f2a48a42f9c827f487e53ee52a4e9e2f;

typedef std::tuple<
  *sync_client_cmd,
  Pointer
> v_902a7f39de6379bcb4d58e786fb18fc9;

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
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    uint32_t id_1 { p_0.seq };
    Pointer id_2 { p_1.writeU32Le(id_1) };
    Pointer let_res_3;
    {
      Pointer srec_dst_84 { id_2 };
      bool id_4 { p_0.confirm_success };
      uint8_t id_5 { uint8_t(id_4) };
      Pointer id_6 { srec_dst_84.writeU8(id_5) };
      let_res_3 = id_6;
    }
    Pointer let_res_7;
    {
      Pointer srec_dst_85 { let_res_3 };
      bool id_8 { p_0.echo };
      uint8_t id_9 { uint8_t(id_8) };
      Pointer id_10 { srec_dst_85.writeU8(id_9) };
      let_res_7 = id_10;
    }
    Pointer let_res_11;
    {
      Pointer srec_dst_86 { let_res_7 };
      std::function<Pointer(*sync_client_cmd,Pointer)> id_12 { dessser_gen::sync_client_cmd.to_row_binary };
      *sync_client_cmd id_13 { p_0.cmd };
      Pointer id_14 { id_12(id_13, srec_dst_86) };
      let_res_11 = id_14;
    }
    return let_res_11;
  }
   };
  return fun0;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{seq: U32; confirm_success: BOOL; echo: BOOL; cmd: $sync_client_cmd}") (add (size 6) (apply (ext-identifier sync_client_cmd sersize-of-row-binary) (get-field "cmd" (param 0)))))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun15 { [&fun15](t p_0) {
    Size id_16 { 6UL };
    std::function<Size(*sync_client_cmd)> id_17 { dessser_gen::sync_client_cmd.sersize_of_row_binary };
    *sync_client_cmd id_18 { p_0.cmd };
    Size id_19 { id_17(id_18) };
    Size id_20 { Size(id_16 + id_19) };
    return id_20;
  }
   };
  return fun15;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_59" (let-pair "du32_fst_57" "du32_snd_58" (read-u32 little-endian (param 0)) (make-tup (identifier "du32_fst_57") (identifier "du32_snd_58")))
        (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
          (let "drec_65" (let-pair "dbool_fst_63" "dbool_snd_64" (read-u8 (identifier "drec_snd_61")) (make-tup (not (eq (identifier "dbool_fst_63") (u8 0))) (identifier "dbool_snd_64")))
            (let-pair "drec_fst_66" "drec_snd_67" (identifier "drec_65")
              (let "drec_71" (let-pair "dbool_fst_69" "dbool_snd_70" (read-u8 (identifier "drec_snd_67")) (make-tup (not (eq (identifier "dbool_fst_69") (u8 0))) (identifier "dbool_snd_70")))
                (let-pair "drec_fst_72" "drec_snd_73" (identifier "drec_71")
                  (let-pair "drec_fst_75" "drec_snd_76" (apply (ext-identifier sync_client_cmd of-row-binary) (identifier "drec_snd_73"))
                    (make-tup (make-rec (string "seq") (identifier "drec_fst_60") (string "confirm_success") (identifier "drec_fst_66") (string "echo") (identifier "drec_fst_72") (string "cmd") (identifier "drec_fst_75"))
                      (identifier "drec_snd_76"))))))))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun21 { [&fun21](Pointer p_0) {
    ac0fbd05039f742d2f1d9ac182e392ab id_22 { p_0.readU32Le() };
    ac0fbd05039f742d2f1d9ac182e392ab letpair_res_23;
    {
      auto du32_fst_57 { std::get<0>(id_22) };
      auto du32_snd_58 { std::get<1>(id_22) };
      ac0fbd05039f742d2f1d9ac182e392ab id_24 {  du32_fst_57, du32_snd_58  };
      letpair_res_23 = id_24;
    }
    f63f919559f0d70225bd0da5dd9bcafc let_res_25;
    {
      ac0fbd05039f742d2f1d9ac182e392ab drec_59 { letpair_res_23 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_26;
      {
        auto drec_fst_60 { std::get<0>(drec_59) };
        auto drec_snd_61 { std::get<1>(drec_59) };
        v_1d5843897434feb24d158f3793db9189 id_27 { drec_snd_61.readU8() };
        f2a48a42f9c827f487e53ee52a4e9e2f letpair_res_28;
        {
          auto dbool_fst_63 { std::get<0>(id_27) };
          auto dbool_snd_64 { std::get<1>(id_27) };
          uint8_t id_29 { 0 };
          bool id_30 { bool(dbool_fst_63 == id_29) };
          bool id_31 { ! id_30 };
          f2a48a42f9c827f487e53ee52a4e9e2f id_32 {  id_31, dbool_snd_64  };
          letpair_res_28 = id_32;
        }
        f63f919559f0d70225bd0da5dd9bcafc let_res_33;
        {
          f2a48a42f9c827f487e53ee52a4e9e2f drec_65 { letpair_res_28 };
          f63f919559f0d70225bd0da5dd9bcafc letpair_res_34;
          {
            auto drec_fst_66 { std::get<0>(drec_65) };
            auto drec_snd_67 { std::get<1>(drec_65) };
            v_1d5843897434feb24d158f3793db9189 id_35 { drec_snd_67.readU8() };
            f2a48a42f9c827f487e53ee52a4e9e2f letpair_res_36;
            {
              auto dbool_fst_69 { std::get<0>(id_35) };
              auto dbool_snd_70 { std::get<1>(id_35) };
              uint8_t id_37 { 0 };
              bool id_38 { bool(dbool_fst_69 == id_37) };
              bool id_39 { ! id_38 };
              f2a48a42f9c827f487e53ee52a4e9e2f id_40 {  id_39, dbool_snd_70  };
              letpair_res_36 = id_40;
            }
            f63f919559f0d70225bd0da5dd9bcafc let_res_41;
            {
              f2a48a42f9c827f487e53ee52a4e9e2f drec_71 { letpair_res_36 };
              f63f919559f0d70225bd0da5dd9bcafc letpair_res_42;
              {
                auto drec_fst_72 { std::get<0>(drec_71) };
                auto drec_snd_73 { std::get<1>(drec_71) };
                std::function<v_902a7f39de6379bcb4d58e786fb18fc9(Pointer)> id_43 { dessser_gen::sync_client_cmd.of_row_binary };
                v_902a7f39de6379bcb4d58e786fb18fc9 id_44 { id_43(drec_snd_73) };
                f63f919559f0d70225bd0da5dd9bcafc letpair_res_45;
                {
                  auto drec_fst_75 { std::get<0>(id_44) };
                  auto drec_snd_76 { std::get<1>(id_44) };
                  t id_46 {  .seq = drec_fst_60, .confirm_success = drec_fst_66, .echo = drec_fst_72, .cmd = drec_fst_75  };
                  f63f919559f0d70225bd0da5dd9bcafc id_47 {  id_46, drec_snd_76  };
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
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
