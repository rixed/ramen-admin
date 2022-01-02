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
#include "desssergen/sync_key.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_value.h"
#include "desssergen/sync_key.h"
#include "desssergen/sync_selector.h"
#include "desssergen/sync_user_id.h"

namespace dessser::gen::sync_client_cmd {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t805abd272f99387513a75eaf2be5b195 : public std::tuple<
  dessser::gen::sync_user_id::t_ext,
  double
> {
  using tuple::tuple;
};
inline bool operator==(t805abd272f99387513a75eaf2be5b195 const &a, t805abd272f99387513a75eaf2be5b195 const &b) {
  return ::dessser::gen::sync_user_id::Deref(std::get<0>(a)) == ::dessser::gen::sync_user_id::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t805abd272f99387513a75eaf2be5b195 const &a, t805abd272f99387513a75eaf2be5b195 const &b) {
  return !operator==(a, b);
}
struct ta760ad950ac6e9d5bb8cad673985521b : public std::tuple<
  dessser::gen::sync_key::t_ext,
  dessser::gen::sync_value::t_ext
> {
  using tuple::tuple;
};
inline bool operator==(ta760ad950ac6e9d5bb8cad673985521b const &a, ta760ad950ac6e9d5bb8cad673985521b const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && ::dessser::gen::sync_value::Deref(std::get<1>(a)) == ::dessser::gen::sync_value::Deref(std::get<1>(b));
}
inline bool operator!=(ta760ad950ac6e9d5bb8cad673985521b const &a, ta760ad950ac6e9d5bb8cad673985521b const &b) {
  return !operator==(a, b);
}
struct tb16878f6e292208107ef8273775c68d0 : public std::tuple<
  dessser::gen::sync_key::t_ext,
  dessser::gen::sync_value::t_ext,
  double,
  bool
> {
  using tuple::tuple;
};
inline bool operator==(tb16878f6e292208107ef8273775c68d0 const &a, tb16878f6e292208107ef8273775c68d0 const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && ::dessser::gen::sync_value::Deref(std::get<1>(a)) == ::dessser::gen::sync_value::Deref(std::get<1>(b)) && std::get<2>(a) == std::get<2>(b) && std::get<3>(a) == std::get<3>(b);
}
inline bool operator!=(tb16878f6e292208107ef8273775c68d0 const &a, tb16878f6e292208107ef8273775c68d0 const &b) {
  return !operator==(a, b);
}
struct t828d44a85b9c48d5ccb39d9b1a51ef22 : public std::tuple<
  dessser::gen::sync_key::t_ext,
  double,
  bool
> {
  using tuple::tuple;
};
inline bool operator==(t828d44a85b9c48d5ccb39d9b1a51ef22 const &a, t828d44a85b9c48d5ccb39d9b1a51ef22 const &b) {
  return ::dessser::gen::sync_key::Deref(std::get<0>(a)) == ::dessser::gen::sync_key::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b) && std::get<2>(a) == std::get<2>(b);
}
inline bool operator!=(t828d44a85b9c48d5ccb39d9b1a51ef22 const &a, t828d44a85b9c48d5ccb39d9b1a51ef22 const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  ::dessser::gen::sync_client_cmd::t805abd272f99387513a75eaf2be5b195, // Auth
  dessser::gen::sync_selector::t_ext, // StartSync
  ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b, // SetKey
  ::dessser::gen::sync_client_cmd::tb16878f6e292208107ef8273775c68d0, // NewKey
  ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b, // UpdKey
  dessser::gen::sync_key::t_ext, // DelKey
  ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22, // LockKey
  ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22, // LockOrCreateKey
  dessser::gen::sync_key::t_ext, // UnlockKey
  Void // Bye
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 10 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Auth
    case 1: return ::dessser::gen::sync_selector::Deref(std::get<1>(a)) == ::dessser::gen::sync_selector::Deref(std::get<1>(b)); // StartSync
    case 2: return std::get<2>(a) == std::get<2>(b); // SetKey
    case 3: return std::get<3>(a) == std::get<3>(b); // NewKey
    case 4: return std::get<4>(a) == std::get<4>(b); // UpdKey
    case 5: return ::dessser::gen::sync_key::Deref(std::get<5>(a)) == ::dessser::gen::sync_key::Deref(std::get<5>(b)); // DelKey
    case 6: return std::get<6>(a) == std::get<6>(b); // LockKey
    case 7: return std::get<7>(a) == std::get<7>(b); // LockOrCreateKey
    case 8: return ::dessser::gen::sync_key::Deref(std::get<8>(a)) == ::dessser::gen::sync_key::Deref(std::get<8>(b)); // UnlockKey
    case 9: return std::get<9>(a) == std::get<9>(b); // Bye
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct tad950dfaea2a70b4ad0338105e6948fe : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,
  Pointer
> {
  using tuple::tuple;
  tad950dfaea2a70b4ad0338105e6948fe(std::tuple<std::shared_ptr<::dessser::gen::sync_client_cmd::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_client_cmd::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tad950dfaea2a70b4ad0338105e6948fe const &a, tad950dfaea2a70b4ad0338105e6948fe const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tad950dfaea2a70b4ad0338105e6948fe const &a, tad950dfaea2a70b4ad0338105e6948fe const &b) {
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
struct t0adb45945e60d54900ff933305862f48 : public std::tuple<
  dessser::gen::sync_user_id::t_ext,
  Pointer
> {
  using tuple::tuple;
  t0adb45945e60d54900ff933305862f48(std::tuple<dessser::gen::sync_user_id::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_user_id::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0adb45945e60d54900ff933305862f48 const &a, t0adb45945e60d54900ff933305862f48 const &b) {
  return ::dessser::gen::sync_user_id::Deref(std::get<0>(a)) == ::dessser::gen::sync_user_id::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0adb45945e60d54900ff933305862f48 const &a, t0adb45945e60d54900ff933305862f48 const &b) {
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
struct t1b71a579731d4ad10d04b95c8da79c3b : public std::tuple<
  dessser::gen::sync_selector::t_ext,
  Pointer
> {
  using tuple::tuple;
  t1b71a579731d4ad10d04b95c8da79c3b(std::tuple<dessser::gen::sync_selector::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_selector::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1b71a579731d4ad10d04b95c8da79c3b const &a, t1b71a579731d4ad10d04b95c8da79c3b const &b) {
  return ::dessser::gen::sync_selector::Deref(std::get<0>(a)) == ::dessser::gen::sync_selector::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1b71a579731d4ad10d04b95c8da79c3b const &a, t1b71a579731d4ad10d04b95c8da79c3b const &b) {
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
struct td4515cd8d0eb18a7a966d81bd2888d81 : public std::tuple<
  dessser::gen::sync_value::t_ext,
  Pointer
> {
  using tuple::tuple;
  td4515cd8d0eb18a7a966d81bd2888d81(std::tuple<dessser::gen::sync_value::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_value::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td4515cd8d0eb18a7a966d81bd2888d81 const &a, td4515cd8d0eb18a7a966d81bd2888d81 const &b) {
  return ::dessser::gen::sync_value::Deref(std::get<0>(a)) == ::dessser::gen::sync_value::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td4515cd8d0eb18a7a966d81bd2888d81 const &a, td4515cd8d0eb18a7a966d81bd2888d81 const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" "Ptr")
      (let "label1_185" (label-of (param 0))
        (let "ssum_dst_186" (write-u16 little-endian (param 1) (identifier "label1_185"))
          (if (eq (u16 0) (identifier "label1_185"))
            (let "stup_dst_196" (apply (ext-identifier sync_user_id to-row-binary) (get-item 0 (get-alt "Auth" (param 0))) (identifier "ssum_dst_186"))
              (write-u64 little-endian (identifier "stup_dst_196") (u64-of-float (get-item 1 (get-alt "Auth" (param 0))))))
            (if (eq (u16 1) (identifier "label1_185")) (apply (ext-identifier sync_selector to-row-binary) (get-alt "StartSync" (param 0)) (identifier "ssum_dst_186"))
              (if (eq (u16 2) (identifier "label1_185"))
                (let "stup_dst_195" (apply (ext-identifier sync_key to-row-binary) (get-item 0 (get-alt "SetKey" (param 0))) (identifier "ssum_dst_186"))
                  (apply (ext-identifier sync_value to-row-binary) (get-item 1 (get-alt "SetKey" (param 0))) (identifier "stup_dst_195")))
                (if (eq (u16 3) (identifier "label1_185"))
                  (let "stup_dst_194"
                    (let "stup_dst_193"
                      (let "stup_dst_192" (apply (ext-identifier sync_key to-row-binary) (get-item 0 (get-alt "NewKey" (param 0))) (identifier "ssum_dst_186"))
                        (apply (ext-identifier sync_value to-row-binary) (get-item 1 (get-alt "NewKey" (param 0))) (identifier "stup_dst_192")))
                      (write-u64 little-endian (identifier "stup_dst_193") (u64-of-float (get-item 2 (get-alt "NewKey" (param 0)))))) 
                    (write-u8 (identifier "stup_dst_194") (u8-of-bool (get-item 3 (get-alt "NewKey" (param 0))))))
                  (if (eq (u16 4) (identifier "label1_185"))
                    (let "stup_dst_191" (apply (ext-identifier sync_key to-row-binary) (get-item 0 (get-alt "UpdKey" (param 0))) (identifier "ssum_dst_186"))
                      (apply (ext-identifier sync_value to-row-binary) (get-item 1 (get-alt "UpdKey" (param 0))) (identifier "stup_dst_191")))
                    (if (eq (u16 5) (identifier "label1_185")) (apply (ext-identifier sync_key to-row-binary) (get-alt "DelKey" (param 0)) (identifier "ssum_dst_186"))
                      (if (eq (u16 6) (identifier "label1_185"))
                        (let "stup_dst_190"
                          (let "stup_dst_189" (apply (ext-identifier sync_key to-row-binary) (get-item 0 (get-alt "LockKey" (param 0))) (identifier "ssum_dst_186"))
                            (write-u64 little-endian (identifier "stup_dst_189") (u64-of-float (get-item 1 (get-alt "LockKey" (param 0))))))
                          (write-u8 (identifier "stup_dst_190") (u8-of-bool (get-item 2 (get-alt "LockKey" (param 0))))))
                        (if (eq (u16 7) (identifier "label1_185"))
                          (let "stup_dst_188"
                            (let "stup_dst_187" (apply (ext-identifier sync_key to-row-binary) (get-item 0 (get-alt "LockOrCreateKey" (param 0))) (identifier "ssum_dst_186"))
                              (write-u64 little-endian (identifier "stup_dst_187") (u64-of-float (get-item 1 (get-alt "LockOrCreateKey" (param 0))))))
                            (write-u8 (identifier "stup_dst_188") (u8-of-bool (get-item 2 (get-alt "LockOrCreateKey" (param 0))))))
                          (if (eq (u16 8) (identifier "label1_185")) 
                            (apply (ext-identifier sync_key to-row-binary) (get-alt "UnlockKey" (param 0)) (identifier "ssum_dst_186")) 
                            (seq (assert (eq (identifier "label1_185") (u16 9))) (identifier "ssum_dst_186"))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::sync_client_cmd::t>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer let_res_2;
    {
      uint16_t label1_185 { id_1 };
      Pointer id_3 { p_1.writeU16Le(label1_185) };
      Pointer let_res_4;
      {
        Pointer ssum_dst_186 { id_3 };
        uint16_t id_5 { 0 };
        bool id_6 { bool(id_5 == label1_185) };
        Pointer choose_res_7;
        if (id_6) {
          auto fun8 { dessser::gen::sync_user_id::to_row_binary };
          ::dessser::gen::sync_client_cmd::t805abd272f99387513a75eaf2be5b195 id_9 { std::get<0 /* Auth */>((*p_0)) };
          dessser::gen::sync_user_id::t_ext id_10 { std::get<0>(id_9) };
          Pointer id_11 { fun8(id_10, ssum_dst_186) };
          Pointer let_res_12;
          {
            Pointer stup_dst_196 { id_11 };
            ::dessser::gen::sync_client_cmd::t805abd272f99387513a75eaf2be5b195 id_13 { std::get<0 /* Auth */>((*p_0)) };
            double id_14 { std::get<1>(id_13) };
            uint64_t id_15 { qword_of_float(id_14) };
            Pointer id_16 { stup_dst_196.writeU64Le(id_15) };
            let_res_12 = id_16;
          }
          choose_res_7 = let_res_12;
        } else {
          uint16_t id_17 { 1 };
          bool id_18 { bool(id_17 == label1_185) };
          Pointer choose_res_19;
          if (id_18) {
            auto fun20 { dessser::gen::sync_selector::to_row_binary };
            dessser::gen::sync_selector::t_ext id_21 { std::get<1 /* StartSync */>((*p_0)) };
            Pointer id_22 { fun20(id_21, ssum_dst_186) };
            choose_res_19 = id_22;
          } else {
            uint16_t id_23 { 2 };
            bool id_24 { bool(id_23 == label1_185) };
            Pointer choose_res_25;
            if (id_24) {
              auto fun26 { dessser::gen::sync_key::to_row_binary };
              ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b id_27 { std::get<2 /* SetKey */>((*p_0)) };
              dessser::gen::sync_key::t_ext id_28 { std::get<0>(id_27) };
              Pointer id_29 { fun26(id_28, ssum_dst_186) };
              Pointer let_res_30;
              {
                Pointer stup_dst_195 { id_29 };
                auto fun31 { dessser::gen::sync_value::to_row_binary };
                ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b id_32 { std::get<2 /* SetKey */>((*p_0)) };
                dessser::gen::sync_value::t_ext id_33 { std::get<1>(id_32) };
                Pointer id_34 { fun31(id_33, stup_dst_195) };
                let_res_30 = id_34;
              }
              choose_res_25 = let_res_30;
            } else {
              uint16_t id_35 { 3 };
              bool id_36 { bool(id_35 == label1_185) };
              Pointer choose_res_37;
              if (id_36) {
                auto fun38 { dessser::gen::sync_key::to_row_binary };
                ::dessser::gen::sync_client_cmd::tb16878f6e292208107ef8273775c68d0 id_39 { std::get<3 /* NewKey */>((*p_0)) };
                dessser::gen::sync_key::t_ext id_40 { std::get<0>(id_39) };
                Pointer id_41 { fun38(id_40, ssum_dst_186) };
                Pointer let_res_42;
                {
                  Pointer stup_dst_192 { id_41 };
                  auto fun43 { dessser::gen::sync_value::to_row_binary };
                  ::dessser::gen::sync_client_cmd::tb16878f6e292208107ef8273775c68d0 id_44 { std::get<3 /* NewKey */>((*p_0)) };
                  dessser::gen::sync_value::t_ext id_45 { std::get<1>(id_44) };
                  Pointer id_46 { fun43(id_45, stup_dst_192) };
                  let_res_42 = id_46;
                }
                Pointer let_res_47;
                {
                  Pointer stup_dst_193 { let_res_42 };
                  ::dessser::gen::sync_client_cmd::tb16878f6e292208107ef8273775c68d0 id_48 { std::get<3 /* NewKey */>((*p_0)) };
                  double id_49 { std::get<2>(id_48) };
                  uint64_t id_50 { qword_of_float(id_49) };
                  Pointer id_51 { stup_dst_193.writeU64Le(id_50) };
                  let_res_47 = id_51;
                }
                Pointer let_res_52;
                {
                  Pointer stup_dst_194 { let_res_47 };
                  ::dessser::gen::sync_client_cmd::tb16878f6e292208107ef8273775c68d0 id_53 { std::get<3 /* NewKey */>((*p_0)) };
                  bool id_54 { std::get<3>(id_53) };
                  uint8_t id_55 { uint8_t(id_54) };
                  Pointer id_56 { stup_dst_194.writeU8(id_55) };
                  let_res_52 = id_56;
                }
                choose_res_37 = let_res_52;
              } else {
                uint16_t id_57 { 4 };
                bool id_58 { bool(id_57 == label1_185) };
                Pointer choose_res_59;
                if (id_58) {
                  auto fun60 { dessser::gen::sync_key::to_row_binary };
                  ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b id_61 { std::get<4 /* UpdKey */>((*p_0)) };
                  dessser::gen::sync_key::t_ext id_62 { std::get<0>(id_61) };
                  Pointer id_63 { fun60(id_62, ssum_dst_186) };
                  Pointer let_res_64;
                  {
                    Pointer stup_dst_191 { id_63 };
                    auto fun65 { dessser::gen::sync_value::to_row_binary };
                    ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b id_66 { std::get<4 /* UpdKey */>((*p_0)) };
                    dessser::gen::sync_value::t_ext id_67 { std::get<1>(id_66) };
                    Pointer id_68 { fun65(id_67, stup_dst_191) };
                    let_res_64 = id_68;
                  }
                  choose_res_59 = let_res_64;
                } else {
                  uint16_t id_69 { 5 };
                  bool id_70 { bool(id_69 == label1_185) };
                  Pointer choose_res_71;
                  if (id_70) {
                    auto fun72 { dessser::gen::sync_key::to_row_binary };
                    dessser::gen::sync_key::t_ext id_73 { std::get<5 /* DelKey */>((*p_0)) };
                    Pointer id_74 { fun72(id_73, ssum_dst_186) };
                    choose_res_71 = id_74;
                  } else {
                    uint16_t id_75 { 6 };
                    bool id_76 { bool(id_75 == label1_185) };
                    Pointer choose_res_77;
                    if (id_76) {
                      auto fun78 { dessser::gen::sync_key::to_row_binary };
                      ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22 id_79 { std::get<6 /* LockKey */>((*p_0)) };
                      dessser::gen::sync_key::t_ext id_80 { std::get<0>(id_79) };
                      Pointer id_81 { fun78(id_80, ssum_dst_186) };
                      Pointer let_res_82;
                      {
                        Pointer stup_dst_189 { id_81 };
                        ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22 id_83 { std::get<6 /* LockKey */>((*p_0)) };
                        double id_84 { std::get<1>(id_83) };
                        uint64_t id_85 { qword_of_float(id_84) };
                        Pointer id_86 { stup_dst_189.writeU64Le(id_85) };
                        let_res_82 = id_86;
                      }
                      Pointer let_res_87;
                      {
                        Pointer stup_dst_190 { let_res_82 };
                        ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22 id_88 { std::get<6 /* LockKey */>((*p_0)) };
                        bool id_89 { std::get<2>(id_88) };
                        uint8_t id_90 { uint8_t(id_89) };
                        Pointer id_91 { stup_dst_190.writeU8(id_90) };
                        let_res_87 = id_91;
                      }
                      choose_res_77 = let_res_87;
                    } else {
                      uint16_t id_92 { 7 };
                      bool id_93 { bool(id_92 == label1_185) };
                      Pointer choose_res_94;
                      if (id_93) {
                        auto fun95 { dessser::gen::sync_key::to_row_binary };
                        ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22 id_96 { std::get<7 /* LockOrCreateKey */>((*p_0)) };
                        dessser::gen::sync_key::t_ext id_97 { std::get<0>(id_96) };
                        Pointer id_98 { fun95(id_97, ssum_dst_186) };
                        Pointer let_res_99;
                        {
                          Pointer stup_dst_187 { id_98 };
                          ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22 id_100 { std::get<7 /* LockOrCreateKey */>((*p_0)) };
                          double id_101 { std::get<1>(id_100) };
                          uint64_t id_102 { qword_of_float(id_101) };
                          Pointer id_103 { stup_dst_187.writeU64Le(id_102) };
                          let_res_99 = id_103;
                        }
                        Pointer let_res_104;
                        {
                          Pointer stup_dst_188 { let_res_99 };
                          ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22 id_105 { std::get<7 /* LockOrCreateKey */>((*p_0)) };
                          bool id_106 { std::get<2>(id_105) };
                          uint8_t id_107 { uint8_t(id_106) };
                          Pointer id_108 { stup_dst_188.writeU8(id_107) };
                          let_res_104 = id_108;
                        }
                        choose_res_94 = let_res_104;
                      } else {
                        uint16_t id_109 { 8 };
                        bool id_110 { bool(id_109 == label1_185) };
                        Pointer choose_res_111;
                        if (id_110) {
                          auto fun112 { dessser::gen::sync_key::to_row_binary };
                          dessser::gen::sync_key::t_ext id_113 { std::get<8 /* UnlockKey */>((*p_0)) };
                          Pointer id_114 { fun112(id_113, ssum_dst_186) };
                          choose_res_111 = id_114;
                        } else {
                          uint16_t id_115 { 9 };
                          bool id_116 { bool(label1_185 == id_115) };
                          Void id_117 { ((void)(assert(id_116)), ::dessser::Void()) };
                          (void)id_117;
                          choose_res_111 = ssum_dst_186;
                        }
                        choose_res_94 = choose_res_111;
                      }
                      choose_res_77 = choose_res_94;
                    }
                    choose_res_71 = choose_res_77;
                  }
                  choose_res_59 = choose_res_71;
                }
                choose_res_37 = choose_res_59;
              }
              choose_res_25 = choose_res_37;
            }
            choose_res_19 = choose_res_25;
          }
          choose_res_7 = choose_res_19;
        }
        let_res_4 = choose_res_7;
      }
      let_res_2 = let_res_4;
    }
    return let_res_2;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]")
      (let "label2_168" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_168")) (add (add (size 2) (apply (ext-identifier sync_user_id sersize-of-row-binary) (get-item 0 (get-alt "Auth" (param 0))))) (size 8))
          (if (eq (u16 1) (identifier "label2_168")) (add (size 2) (apply (ext-identifier sync_selector sersize-of-row-binary) (get-alt "StartSync" (param 0))))
            (if (eq (u16 2) (identifier "label2_168"))
              (let "sz_182" (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-item 0 (get-alt "SetKey" (param 0)))))
                (add (identifier "sz_182") (apply (ext-identifier sync_value sersize-of-row-binary) (get-item 1 (get-alt "SetKey" (param 0))))))
              (if (eq (u16 3) (identifier "label2_168"))
                (add
                  (add
                    (let "sz_178" (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-item 0 (get-alt "NewKey" (param 0)))))
                      (add (identifier "sz_178") (apply (ext-identifier sync_value sersize-of-row-binary) (get-item 1 (get-alt "NewKey" (param 0)))))) 
                    (size 8)) (size 1))
                (if (eq (u16 4) (identifier "label2_168"))
                  (let "sz_176" (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-item 0 (get-alt "UpdKey" (param 0)))))
                    (add (identifier "sz_176") (apply (ext-identifier sync_value sersize-of-row-binary) (get-item 1 (get-alt "UpdKey" (param 0))))))
                  (if (eq (u16 5) (identifier "label2_168")) (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-alt "DelKey" (param 0))))
                    (if (eq (u16 6) (identifier "label2_168")) (add (add (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-item 0 (get-alt "LockKey" (param 0))))) (size 8)) (size 1))
                      (if (eq (u16 7) (identifier "label2_168")) (add (add (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-item 0 (get-alt "LockOrCreateKey" (param 0))))) (size 8)) (size 1))
                        (if (eq (u16 8) (identifier "label2_168")) (add (size 2) (apply (ext-identifier sync_key sersize-of-row-binary) (get-alt "UnlockKey" (param 0))))
                          (seq (assert (eq (identifier "label2_168") (u16 9))) (size 2)))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_client_cmd::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_client_cmd::t> )> fun118 { [&](std::shared_ptr<::dessser::gen::sync_client_cmd::t>  p_0) {
    uint16_t id_119 { uint16_t((*p_0).index()) };
    Size let_res_120;
    {
      uint16_t label2_168 { id_119 };
      uint16_t id_121 { 0 };
      bool id_122 { bool(id_121 == label2_168) };
      Size choose_res_123;
      if (id_122) {
        Size id_124 { 2UL };
        auto fun125 { dessser::gen::sync_user_id::sersize_of_row_binary };
        ::dessser::gen::sync_client_cmd::t805abd272f99387513a75eaf2be5b195 id_126 { std::get<0 /* Auth */>((*p_0)) };
        dessser::gen::sync_user_id::t_ext id_127 { std::get<0>(id_126) };
        Size id_128 { fun125(id_127) };
        Size id_129 { Size(id_124 + id_128) };
        Size id_130 { 8UL };
        Size id_131 { Size(id_129 + id_130) };
        choose_res_123 = id_131;
      } else {
        uint16_t id_132 { 1 };
        bool id_133 { bool(id_132 == label2_168) };
        Size choose_res_134;
        if (id_133) {
          Size id_135 { 2UL };
          auto fun136 { dessser::gen::sync_selector::sersize_of_row_binary };
          dessser::gen::sync_selector::t_ext id_137 { std::get<1 /* StartSync */>((*p_0)) };
          Size id_138 { fun136(id_137) };
          Size id_139 { Size(id_135 + id_138) };
          choose_res_134 = id_139;
        } else {
          uint16_t id_140 { 2 };
          bool id_141 { bool(id_140 == label2_168) };
          Size choose_res_142;
          if (id_141) {
            Size id_143 { 2UL };
            auto fun144 { dessser::gen::sync_key::sersize_of_row_binary };
            ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b id_145 { std::get<2 /* SetKey */>((*p_0)) };
            dessser::gen::sync_key::t_ext id_146 { std::get<0>(id_145) };
            Size id_147 { fun144(id_146) };
            Size id_148 { Size(id_143 + id_147) };
            Size let_res_149;
            {
              Size sz_182 { id_148 };
              auto fun150 { dessser::gen::sync_value::sersize_of_row_binary };
              ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b id_151 { std::get<2 /* SetKey */>((*p_0)) };
              dessser::gen::sync_value::t_ext id_152 { std::get<1>(id_151) };
              Size id_153 { fun150(id_152) };
              Size id_154 { Size(sz_182 + id_153) };
              let_res_149 = id_154;
            }
            choose_res_142 = let_res_149;
          } else {
            uint16_t id_155 { 3 };
            bool id_156 { bool(id_155 == label2_168) };
            Size choose_res_157;
            if (id_156) {
              Size id_158 { 2UL };
              auto fun159 { dessser::gen::sync_key::sersize_of_row_binary };
              ::dessser::gen::sync_client_cmd::tb16878f6e292208107ef8273775c68d0 id_160 { std::get<3 /* NewKey */>((*p_0)) };
              dessser::gen::sync_key::t_ext id_161 { std::get<0>(id_160) };
              Size id_162 { fun159(id_161) };
              Size id_163 { Size(id_158 + id_162) };
              Size let_res_164;
              {
                Size sz_178 { id_163 };
                auto fun165 { dessser::gen::sync_value::sersize_of_row_binary };
                ::dessser::gen::sync_client_cmd::tb16878f6e292208107ef8273775c68d0 id_166 { std::get<3 /* NewKey */>((*p_0)) };
                dessser::gen::sync_value::t_ext id_167 { std::get<1>(id_166) };
                Size id_168 { fun165(id_167) };
                Size id_169 { Size(sz_178 + id_168) };
                let_res_164 = id_169;
              }
              Size id_170 { 8UL };
              Size id_171 { Size(let_res_164 + id_170) };
              Size id_172 { 1UL };
              Size id_173 { Size(id_171 + id_172) };
              choose_res_157 = id_173;
            } else {
              uint16_t id_174 { 4 };
              bool id_175 { bool(id_174 == label2_168) };
              Size choose_res_176;
              if (id_175) {
                Size id_177 { 2UL };
                auto fun178 { dessser::gen::sync_key::sersize_of_row_binary };
                ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b id_179 { std::get<4 /* UpdKey */>((*p_0)) };
                dessser::gen::sync_key::t_ext id_180 { std::get<0>(id_179) };
                Size id_181 { fun178(id_180) };
                Size id_182 { Size(id_177 + id_181) };
                Size let_res_183;
                {
                  Size sz_176 { id_182 };
                  auto fun184 { dessser::gen::sync_value::sersize_of_row_binary };
                  ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b id_185 { std::get<4 /* UpdKey */>((*p_0)) };
                  dessser::gen::sync_value::t_ext id_186 { std::get<1>(id_185) };
                  Size id_187 { fun184(id_186) };
                  Size id_188 { Size(sz_176 + id_187) };
                  let_res_183 = id_188;
                }
                choose_res_176 = let_res_183;
              } else {
                uint16_t id_189 { 5 };
                bool id_190 { bool(id_189 == label2_168) };
                Size choose_res_191;
                if (id_190) {
                  Size id_192 { 2UL };
                  auto fun193 { dessser::gen::sync_key::sersize_of_row_binary };
                  dessser::gen::sync_key::t_ext id_194 { std::get<5 /* DelKey */>((*p_0)) };
                  Size id_195 { fun193(id_194) };
                  Size id_196 { Size(id_192 + id_195) };
                  choose_res_191 = id_196;
                } else {
                  uint16_t id_197 { 6 };
                  bool id_198 { bool(id_197 == label2_168) };
                  Size choose_res_199;
                  if (id_198) {
                    Size id_200 { 2UL };
                    auto fun201 { dessser::gen::sync_key::sersize_of_row_binary };
                    ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22 id_202 { std::get<6 /* LockKey */>((*p_0)) };
                    dessser::gen::sync_key::t_ext id_203 { std::get<0>(id_202) };
                    Size id_204 { fun201(id_203) };
                    Size id_205 { Size(id_200 + id_204) };
                    Size id_206 { 8UL };
                    Size id_207 { Size(id_205 + id_206) };
                    Size id_208 { 1UL };
                    Size id_209 { Size(id_207 + id_208) };
                    choose_res_199 = id_209;
                  } else {
                    uint16_t id_210 { 7 };
                    bool id_211 { bool(id_210 == label2_168) };
                    Size choose_res_212;
                    if (id_211) {
                      Size id_213 { 2UL };
                      auto fun214 { dessser::gen::sync_key::sersize_of_row_binary };
                      ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22 id_215 { std::get<7 /* LockOrCreateKey */>((*p_0)) };
                      dessser::gen::sync_key::t_ext id_216 { std::get<0>(id_215) };
                      Size id_217 { fun214(id_216) };
                      Size id_218 { Size(id_213 + id_217) };
                      Size id_219 { 8UL };
                      Size id_220 { Size(id_218 + id_219) };
                      Size id_221 { 1UL };
                      Size id_222 { Size(id_220 + id_221) };
                      choose_res_212 = id_222;
                    } else {
                      uint16_t id_223 { 8 };
                      bool id_224 { bool(id_223 == label2_168) };
                      Size choose_res_225;
                      if (id_224) {
                        Size id_226 { 2UL };
                        auto fun227 { dessser::gen::sync_key::sersize_of_row_binary };
                        dessser::gen::sync_key::t_ext id_228 { std::get<8 /* UnlockKey */>((*p_0)) };
                        Size id_229 { fun227(id_228) };
                        Size id_230 { Size(id_226 + id_229) };
                        choose_res_225 = id_230;
                      } else {
                        uint16_t id_231 { 9 };
                        bool id_232 { bool(label2_168 == id_231) };
                        Void id_233 { ((void)(assert(id_232)), ::dessser::Void()) };
                        (void)id_233;
                        Size id_234 { 2UL };
                        choose_res_225 = id_234;
                      }
                      choose_res_212 = choose_res_225;
                    }
                    choose_res_199 = choose_res_212;
                  }
                  choose_res_191 = choose_res_199;
                }
                choose_res_176 = choose_res_191;
              }
              choose_res_157 = choose_res_176;
            }
            choose_res_142 = choose_res_157;
          }
          choose_res_134 = choose_res_142;
        }
        choose_res_123 = choose_res_134;
      }
      let_res_120 = choose_res_123;
    }
    return let_res_120;
  }
   };
  return fun118;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_client_cmd::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (let "dtup_153" (apply (ext-identifier sync_user_id of-row-binary) (identifier "dsum1_snd_65"))
              (let-pair "dtup_fst_154" "dtup_snd_155" (identifier "dtup_153")
                (let-pair "dfloat_fst_157" "dfloat_snd_158" (read-u64 little-endian (identifier "dtup_snd_155"))
                  (make-tup
                    (construct "[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" 0
                      (make-tup (identifier "dtup_fst_154") (float-of-u64 (identifier "dfloat_fst_157")))) 
                    (identifier "dfloat_snd_158")))))
            (if (eq (u16 1) (identifier "dsum1_fst_64"))
              (let-pair "dsum2_fst_151" "dsum2_snd_152" (apply (ext-identifier sync_selector of-row-binary) (identifier "dsum1_snd_65"))
                (make-tup
                  (construct "[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" 1
                    (identifier "dsum2_fst_151")) (identifier "dsum2_snd_152")))
              (if (eq (u16 2) (identifier "dsum1_fst_64"))
                (let "dtup_141" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_65"))
                  (let-pair "dtup_fst_142" "dtup_snd_143" (identifier "dtup_141")
                    (let-pair "dtup_fst_145" "dtup_snd_146" (apply (ext-identifier sync_value of-row-binary) (identifier "dtup_snd_143"))
                      (make-tup
                        (construct "[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" 2
                          (make-tup (identifier "dtup_fst_142") (identifier "dtup_fst_145"))) 
                        (identifier "dtup_snd_146")))))
                (if (eq (u16 3) (identifier "dsum1_fst_64"))
                  (let "dtup_120" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_65"))
                    (let-pair "dtup_fst_121" "dtup_snd_122" (identifier "dtup_120")
                      (let "dtup_123" (apply (ext-identifier sync_value of-row-binary) (identifier "dtup_snd_122"))
                        (let-pair "dtup_fst_124" "dtup_snd_125" (identifier "dtup_123")
                          (let "dtup_129" (let-pair "dfloat_fst_127" "dfloat_snd_128" (read-u64 little-endian (identifier "dtup_snd_125")) (make-tup (float-of-u64 (identifier "dfloat_fst_127")) (identifier "dfloat_snd_128")))
                            (let-pair "dtup_fst_130" "dtup_snd_131" (identifier "dtup_129")
                              (let-pair "dbool_fst_133" "dbool_snd_134" 
                                (read-u8 (identifier "dtup_snd_131"))
                                (make-tup
                                  (construct "[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" 3
                                    (make-tup (identifier "dtup_fst_121") (identifier "dtup_fst_124") (identifier "dtup_fst_130") (not (eq (identifier "dbool_fst_133") (u8 0))))) 
                                  (identifier "dbool_snd_134")))))))))
                  (if (eq (u16 4) (identifier "dsum1_fst_64"))
                    (let "dtup_111" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_65"))
                      (let-pair "dtup_fst_112" "dtup_snd_113" (identifier "dtup_111")
                        (let-pair "dtup_fst_115" "dtup_snd_116" (apply (ext-identifier sync_value of-row-binary) (identifier "dtup_snd_113"))
                          (make-tup
                            (construct "[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" 4
                              (make-tup (identifier "dtup_fst_112") (identifier "dtup_fst_115"))) 
                            (identifier "dtup_snd_116")))))
                    (if (eq (u16 5) (identifier "dsum1_fst_64"))
                      (let-pair "dsum2_fst_109" "dsum2_snd_110" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_65"))
                        (make-tup
                          (construct "[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" 5
                            (identifier "dsum2_fst_109")) (identifier "dsum2_snd_110")))
                      (if (eq (u16 6) (identifier "dsum1_fst_64"))
                        (let "dtup_90" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_65"))
                          (let-pair "dtup_fst_91" "dtup_snd_92" (identifier "dtup_90")
                            (let "dtup_96" (let-pair "dfloat_fst_94" "dfloat_snd_95" (read-u64 little-endian (identifier "dtup_snd_92")) (make-tup (float-of-u64 (identifier "dfloat_fst_94")) (identifier "dfloat_snd_95")))
                              (let-pair "dtup_fst_97" "dtup_snd_98" (identifier "dtup_96")
                                (let-pair "dbool_fst_100" "dbool_snd_101" 
                                  (read-u8 (identifier "dtup_snd_98"))
                                  (make-tup
                                    (construct "[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" 6
                                      (make-tup (identifier "dtup_fst_91") (identifier "dtup_fst_97") (not (eq (identifier "dbool_fst_100") (u8 0))))) 
                                    (identifier "dbool_snd_101")))))))
                        (if (eq (u16 7) (identifier "dsum1_fst_64"))
                          (let "dtup_72" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_65"))
                            (let-pair "dtup_fst_73" "dtup_snd_74" (identifier "dtup_72")
                              (let "dtup_78" (let-pair "dfloat_fst_76" "dfloat_snd_77" (read-u64 little-endian (identifier "dtup_snd_74")) (make-tup (float-of-u64 (identifier "dfloat_fst_76")) (identifier "dfloat_snd_77")))
                                (let-pair "dtup_fst_79" "dtup_snd_80" 
                                  (identifier "dtup_78")
                                  (let-pair "dbool_fst_82" "dbool_snd_83" 
                                    (read-u8 (identifier "dtup_snd_80"))
                                    (make-tup
                                      (construct "[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" 7
                                        (make-tup (identifier "dtup_fst_73") (identifier "dtup_fst_79") (not (eq (identifier "dbool_fst_82") (u8 0))))) 
                                      (identifier "dbool_snd_83")))))))
                          (if (eq (u16 8) (identifier "dsum1_fst_64"))
                            (let-pair "dsum2_fst_70" "dsum2_snd_71" (apply (ext-identifier sync_key of-row-binary) (identifier "dsum1_snd_65"))
                              (make-tup
                                (construct "[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" 8
                                  (identifier "dsum2_fst_70")) (identifier "dsum2_snd_71")))
                            (seq (assert (eq (identifier "dsum1_fst_64") (u16 9)))
                              (make-tup
                                (construct "[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" 9
                                  (nop)) (identifier "dsum1_snd_65")))))))))))))))
 */
static std::function<::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe(Pointer)> fun235 { [&](Pointer p_0) {
    ::dessser::gen::sync_client_cmd::ta97bb48ed75bbda6173555873826c8c6 id_236 { p_0.readU16Le() };
    ::dessser::gen::sync_client_cmd::ta97bb48ed75bbda6173555873826c8c6 letpair_res_237;
    {
      auto du16_fst_58 { std::get<0>(id_236) };
      auto du16_snd_59 { std::get<1>(id_236) };
      ::dessser::gen::sync_client_cmd::ta97bb48ed75bbda6173555873826c8c6 id_238 { du16_fst_58, du16_snd_59 };
      letpair_res_237 = id_238;
    }
    ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_239;
    {
      ::dessser::gen::sync_client_cmd::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_237 };
      ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_240;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_241 { 0 };
        bool id_242 { bool(id_241 == dsum1_fst_64) };
        ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe choose_res_243;
        if (id_242) {
          auto fun244 { dessser::gen::sync_user_id::of_row_binary };
          ::dessser::gen::sync_client_cmd::t0adb45945e60d54900ff933305862f48 id_245 { fun244(dsum1_snd_65) };
          ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_246;
          {
            ::dessser::gen::sync_client_cmd::t0adb45945e60d54900ff933305862f48 dtup_153 { id_245 };
            ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_247;
            {
              auto dtup_fst_154 { std::get<0>(dtup_153) };
              auto dtup_snd_155 { std::get<1>(dtup_153) };
              ::dessser::gen::sync_client_cmd::td2cd337bb3c8bc04d5603393d084985b id_248 { dtup_snd_155.readU64Le() };
              ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_249;
              {
                auto dfloat_fst_157 { std::get<0>(id_248) };
                auto dfloat_snd_158 { std::get<1>(id_248) };
                double id_250 { float_of_qword(dfloat_fst_157) };
                ::dessser::gen::sync_client_cmd::t805abd272f99387513a75eaf2be5b195 id_251 { dtup_fst_154, id_250 };
                std::shared_ptr<::dessser::gen::sync_client_cmd::t>  id_252 { std::make_shared<::dessser::gen::sync_client_cmd::t>(std::in_place_index<0>, id_251) };
                ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_253 { id_252, dfloat_snd_158 };
                letpair_res_249 = id_253;
              }
              letpair_res_247 = letpair_res_249;
            }
            let_res_246 = letpair_res_247;
          }
          choose_res_243 = let_res_246;
        } else {
          uint16_t id_254 { 1 };
          bool id_255 { bool(id_254 == dsum1_fst_64) };
          ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe choose_res_256;
          if (id_255) {
            auto fun257 { dessser::gen::sync_selector::of_row_binary };
            ::dessser::gen::sync_client_cmd::t1b71a579731d4ad10d04b95c8da79c3b id_258 { fun257(dsum1_snd_65) };
            ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_259;
            {
              auto dsum2_fst_151 { std::get<0>(id_258) };
              auto dsum2_snd_152 { std::get<1>(id_258) };
              std::shared_ptr<::dessser::gen::sync_client_cmd::t>  id_260 { std::make_shared<::dessser::gen::sync_client_cmd::t>(std::in_place_index<1>, dsum2_fst_151) };
              ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_261 { id_260, dsum2_snd_152 };
              letpair_res_259 = id_261;
            }
            choose_res_256 = letpair_res_259;
          } else {
            uint16_t id_262 { 2 };
            bool id_263 { bool(id_262 == dsum1_fst_64) };
            ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe choose_res_264;
            if (id_263) {
              auto fun265 { dessser::gen::sync_key::of_row_binary };
              ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec id_266 { fun265(dsum1_snd_65) };
              ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_267;
              {
                ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec dtup_141 { id_266 };
                ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_268;
                {
                  auto dtup_fst_142 { std::get<0>(dtup_141) };
                  auto dtup_snd_143 { std::get<1>(dtup_141) };
                  auto fun269 { dessser::gen::sync_value::of_row_binary };
                  ::dessser::gen::sync_client_cmd::td4515cd8d0eb18a7a966d81bd2888d81 id_270 { fun269(dtup_snd_143) };
                  ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_271;
                  {
                    auto dtup_fst_145 { std::get<0>(id_270) };
                    auto dtup_snd_146 { std::get<1>(id_270) };
                    ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b id_272 { dtup_fst_142, dtup_fst_145 };
                    std::shared_ptr<::dessser::gen::sync_client_cmd::t>  id_273 { std::make_shared<::dessser::gen::sync_client_cmd::t>(std::in_place_index<2>, id_272) };
                    ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_274 { id_273, dtup_snd_146 };
                    letpair_res_271 = id_274;
                  }
                  letpair_res_268 = letpair_res_271;
                }
                let_res_267 = letpair_res_268;
              }
              choose_res_264 = let_res_267;
            } else {
              uint16_t id_275 { 3 };
              bool id_276 { bool(id_275 == dsum1_fst_64) };
              ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe choose_res_277;
              if (id_276) {
                auto fun278 { dessser::gen::sync_key::of_row_binary };
                ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec id_279 { fun278(dsum1_snd_65) };
                ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_280;
                {
                  ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec dtup_120 { id_279 };
                  ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_281;
                  {
                    auto dtup_fst_121 { std::get<0>(dtup_120) };
                    auto dtup_snd_122 { std::get<1>(dtup_120) };
                    auto fun282 { dessser::gen::sync_value::of_row_binary };
                    ::dessser::gen::sync_client_cmd::td4515cd8d0eb18a7a966d81bd2888d81 id_283 { fun282(dtup_snd_122) };
                    ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_284;
                    {
                      ::dessser::gen::sync_client_cmd::td4515cd8d0eb18a7a966d81bd2888d81 dtup_123 { id_283 };
                      ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_285;
                      {
                        auto dtup_fst_124 { std::get<0>(dtup_123) };
                        auto dtup_snd_125 { std::get<1>(dtup_123) };
                        ::dessser::gen::sync_client_cmd::td2cd337bb3c8bc04d5603393d084985b id_286 { dtup_snd_125.readU64Le() };
                        ::dessser::gen::sync_client_cmd::t9a758baeff17224a77e1a522010b4168 letpair_res_287;
                        {
                          auto dfloat_fst_127 { std::get<0>(id_286) };
                          auto dfloat_snd_128 { std::get<1>(id_286) };
                          double id_288 { float_of_qword(dfloat_fst_127) };
                          ::dessser::gen::sync_client_cmd::t9a758baeff17224a77e1a522010b4168 id_289 { id_288, dfloat_snd_128 };
                          letpair_res_287 = id_289;
                        }
                        ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_290;
                        {
                          ::dessser::gen::sync_client_cmd::t9a758baeff17224a77e1a522010b4168 dtup_129 { letpair_res_287 };
                          ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_291;
                          {
                            auto dtup_fst_130 { std::get<0>(dtup_129) };
                            auto dtup_snd_131 { std::get<1>(dtup_129) };
                            ::dessser::gen::sync_client_cmd::t1a5d74abf838df33f185a72a8912f5c9 id_292 { dtup_snd_131.readU8() };
                            ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_293;
                            {
                              auto dbool_fst_133 { std::get<0>(id_292) };
                              auto dbool_snd_134 { std::get<1>(id_292) };
                              uint8_t id_294 { 0 };
                              bool id_295 { bool(dbool_fst_133 == id_294) };
                              bool id_296 { ! id_295 };
                              ::dessser::gen::sync_client_cmd::tb16878f6e292208107ef8273775c68d0 id_297 { dtup_fst_121, dtup_fst_124, dtup_fst_130, id_296 };
                              std::shared_ptr<::dessser::gen::sync_client_cmd::t>  id_298 { std::make_shared<::dessser::gen::sync_client_cmd::t>(std::in_place_index<3>, id_297) };
                              ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_299 { id_298, dbool_snd_134 };
                              letpair_res_293 = id_299;
                            }
                            letpair_res_291 = letpair_res_293;
                          }
                          let_res_290 = letpair_res_291;
                        }
                        letpair_res_285 = let_res_290;
                      }
                      let_res_284 = letpair_res_285;
                    }
                    letpair_res_281 = let_res_284;
                  }
                  let_res_280 = letpair_res_281;
                }
                choose_res_277 = let_res_280;
              } else {
                uint16_t id_300 { 4 };
                bool id_301 { bool(id_300 == dsum1_fst_64) };
                ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe choose_res_302;
                if (id_301) {
                  auto fun303 { dessser::gen::sync_key::of_row_binary };
                  ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec id_304 { fun303(dsum1_snd_65) };
                  ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_305;
                  {
                    ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec dtup_111 { id_304 };
                    ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_306;
                    {
                      auto dtup_fst_112 { std::get<0>(dtup_111) };
                      auto dtup_snd_113 { std::get<1>(dtup_111) };
                      auto fun307 { dessser::gen::sync_value::of_row_binary };
                      ::dessser::gen::sync_client_cmd::td4515cd8d0eb18a7a966d81bd2888d81 id_308 { fun307(dtup_snd_113) };
                      ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_309;
                      {
                        auto dtup_fst_115 { std::get<0>(id_308) };
                        auto dtup_snd_116 { std::get<1>(id_308) };
                        ::dessser::gen::sync_client_cmd::ta760ad950ac6e9d5bb8cad673985521b id_310 { dtup_fst_112, dtup_fst_115 };
                        std::shared_ptr<::dessser::gen::sync_client_cmd::t>  id_311 { std::make_shared<::dessser::gen::sync_client_cmd::t>(std::in_place_index<4>, id_310) };
                        ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_312 { id_311, dtup_snd_116 };
                        letpair_res_309 = id_312;
                      }
                      letpair_res_306 = letpair_res_309;
                    }
                    let_res_305 = letpair_res_306;
                  }
                  choose_res_302 = let_res_305;
                } else {
                  uint16_t id_313 { 5 };
                  bool id_314 { bool(id_313 == dsum1_fst_64) };
                  ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe choose_res_315;
                  if (id_314) {
                    auto fun316 { dessser::gen::sync_key::of_row_binary };
                    ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec id_317 { fun316(dsum1_snd_65) };
                    ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_318;
                    {
                      auto dsum2_fst_109 { std::get<0>(id_317) };
                      auto dsum2_snd_110 { std::get<1>(id_317) };
                      std::shared_ptr<::dessser::gen::sync_client_cmd::t>  id_319 { std::make_shared<::dessser::gen::sync_client_cmd::t>(std::in_place_index<5>, dsum2_fst_109) };
                      ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_320 { id_319, dsum2_snd_110 };
                      letpair_res_318 = id_320;
                    }
                    choose_res_315 = letpair_res_318;
                  } else {
                    uint16_t id_321 { 6 };
                    bool id_322 { bool(id_321 == dsum1_fst_64) };
                    ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe choose_res_323;
                    if (id_322) {
                      auto fun324 { dessser::gen::sync_key::of_row_binary };
                      ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec id_325 { fun324(dsum1_snd_65) };
                      ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_326;
                      {
                        ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec dtup_90 { id_325 };
                        ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_327;
                        {
                          auto dtup_fst_91 { std::get<0>(dtup_90) };
                          auto dtup_snd_92 { std::get<1>(dtup_90) };
                          ::dessser::gen::sync_client_cmd::td2cd337bb3c8bc04d5603393d084985b id_328 { dtup_snd_92.readU64Le() };
                          ::dessser::gen::sync_client_cmd::t9a758baeff17224a77e1a522010b4168 letpair_res_329;
                          {
                            auto dfloat_fst_94 { std::get<0>(id_328) };
                            auto dfloat_snd_95 { std::get<1>(id_328) };
                            double id_330 { float_of_qword(dfloat_fst_94) };
                            ::dessser::gen::sync_client_cmd::t9a758baeff17224a77e1a522010b4168 id_331 { id_330, dfloat_snd_95 };
                            letpair_res_329 = id_331;
                          }
                          ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_332;
                          {
                            ::dessser::gen::sync_client_cmd::t9a758baeff17224a77e1a522010b4168 dtup_96 { letpair_res_329 };
                            ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_333;
                            {
                              auto dtup_fst_97 { std::get<0>(dtup_96) };
                              auto dtup_snd_98 { std::get<1>(dtup_96) };
                              ::dessser::gen::sync_client_cmd::t1a5d74abf838df33f185a72a8912f5c9 id_334 { dtup_snd_98.readU8() };
                              ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_335;
                              {
                                auto dbool_fst_100 { std::get<0>(id_334) };
                                auto dbool_snd_101 { std::get<1>(id_334) };
                                uint8_t id_336 { 0 };
                                bool id_337 { bool(dbool_fst_100 == id_336) };
                                bool id_338 { ! id_337 };
                                ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22 id_339 { dtup_fst_91, dtup_fst_97, id_338 };
                                std::shared_ptr<::dessser::gen::sync_client_cmd::t>  id_340 { std::make_shared<::dessser::gen::sync_client_cmd::t>(std::in_place_index<6>, id_339) };
                                ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_341 { id_340, dbool_snd_101 };
                                letpair_res_335 = id_341;
                              }
                              letpair_res_333 = letpair_res_335;
                            }
                            let_res_332 = letpair_res_333;
                          }
                          letpair_res_327 = let_res_332;
                        }
                        let_res_326 = letpair_res_327;
                      }
                      choose_res_323 = let_res_326;
                    } else {
                      uint16_t id_342 { 7 };
                      bool id_343 { bool(id_342 == dsum1_fst_64) };
                      ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe choose_res_344;
                      if (id_343) {
                        auto fun345 { dessser::gen::sync_key::of_row_binary };
                        ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec id_346 { fun345(dsum1_snd_65) };
                        ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_347;
                        {
                          ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec dtup_72 { id_346 };
                          ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_348;
                          {
                            auto dtup_fst_73 { std::get<0>(dtup_72) };
                            auto dtup_snd_74 { std::get<1>(dtup_72) };
                            ::dessser::gen::sync_client_cmd::td2cd337bb3c8bc04d5603393d084985b id_349 { dtup_snd_74.readU64Le() };
                            ::dessser::gen::sync_client_cmd::t9a758baeff17224a77e1a522010b4168 letpair_res_350;
                            {
                              auto dfloat_fst_76 { std::get<0>(id_349) };
                              auto dfloat_snd_77 { std::get<1>(id_349) };
                              double id_351 { float_of_qword(dfloat_fst_76) };
                              ::dessser::gen::sync_client_cmd::t9a758baeff17224a77e1a522010b4168 id_352 { id_351, dfloat_snd_77 };
                              letpair_res_350 = id_352;
                            }
                            ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe let_res_353;
                            {
                              ::dessser::gen::sync_client_cmd::t9a758baeff17224a77e1a522010b4168 dtup_78 { letpair_res_350 };
                              ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_354;
                              {
                                auto dtup_fst_79 { std::get<0>(dtup_78) };
                                auto dtup_snd_80 { std::get<1>(dtup_78) };
                                ::dessser::gen::sync_client_cmd::t1a5d74abf838df33f185a72a8912f5c9 id_355 { dtup_snd_80.readU8() };
                                ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_356;
                                {
                                  auto dbool_fst_82 { std::get<0>(id_355) };
                                  auto dbool_snd_83 { std::get<1>(id_355) };
                                  uint8_t id_357 { 0 };
                                  bool id_358 { bool(dbool_fst_82 == id_357) };
                                  bool id_359 { ! id_358 };
                                  ::dessser::gen::sync_client_cmd::t828d44a85b9c48d5ccb39d9b1a51ef22 id_360 { dtup_fst_73, dtup_fst_79, id_359 };
                                  std::shared_ptr<::dessser::gen::sync_client_cmd::t>  id_361 { std::make_shared<::dessser::gen::sync_client_cmd::t>(std::in_place_index<7>, id_360) };
                                  ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_362 { id_361, dbool_snd_83 };
                                  letpair_res_356 = id_362;
                                }
                                letpair_res_354 = letpair_res_356;
                              }
                              let_res_353 = letpair_res_354;
                            }
                            letpair_res_348 = let_res_353;
                          }
                          let_res_347 = letpair_res_348;
                        }
                        choose_res_344 = let_res_347;
                      } else {
                        uint16_t id_363 { 8 };
                        bool id_364 { bool(id_363 == dsum1_fst_64) };
                        ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe choose_res_365;
                        if (id_364) {
                          auto fun366 { dessser::gen::sync_key::of_row_binary };
                          ::dessser::gen::sync_client_cmd::t0e7f6ba9e1ceef343afe44456f9067ec id_367 { fun366(dsum1_snd_65) };
                          ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_368;
                          {
                            auto dsum2_fst_70 { std::get<0>(id_367) };
                            auto dsum2_snd_71 { std::get<1>(id_367) };
                            std::shared_ptr<::dessser::gen::sync_client_cmd::t>  id_369 { std::make_shared<::dessser::gen::sync_client_cmd::t>(std::in_place_index<8>, dsum2_fst_70) };
                            ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_370 { id_369, dsum2_snd_71 };
                            letpair_res_368 = id_370;
                          }
                          choose_res_365 = letpair_res_368;
                        } else {
                          uint16_t id_371 { 9 };
                          bool id_372 { bool(dsum1_fst_64 == id_371) };
                          Void id_373 { ((void)(assert(id_372)), ::dessser::Void()) };
                          (void)id_373;
                          (void)::dessser::Void();
                          std::shared_ptr<::dessser::gen::sync_client_cmd::t>  id_374 { std::make_shared<::dessser::gen::sync_client_cmd::t>(std::in_place_index<9>, ::dessser::Void()) };
                          ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_375 { id_374, dsum1_snd_65 };
                          choose_res_365 = id_375;
                        }
                        choose_res_344 = choose_res_365;
                      }
                      choose_res_323 = choose_res_344;
                    }
                    choose_res_315 = choose_res_323;
                  }
                  choose_res_302 = choose_res_315;
                }
                choose_res_277 = choose_res_302;
              }
              choose_res_264 = choose_res_277;
            }
            choose_res_256 = choose_res_264;
          }
          choose_res_243 = choose_res_256;
        }
        letpair_res_240 = choose_res_243;
      }
      let_res_239 = letpair_res_240;
    }
    return let_res_239;
  }
   };
  return fun235;
}
std::function<::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_166" "make_snd_167" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_166") (identifier "make_snd_167"))))
 */
static std::function<::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe(Pointer)> fun376 { [&](Pointer p_0) {
    ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_377 { of_row_binary(p_0) };
    ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe letpair_res_378;
    {
      auto make_fst_166 { std::get<0>(id_377) };
      auto make_snd_167 { std::get<1>(id_377) };
      ::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe id_379 { make_fst_166, make_snd_167 };
      letpair_res_378 = id_379;
    }
    return letpair_res_378;
  }
   };
  return fun376;
}
std::function<::dessser::gen::sync_client_cmd::tad950dfaea2a70b4ad0338105e6948fe(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[Auth ($sync_user_id; FLOAT) | StartSync $sync_selector | SetKey ($sync_key; $sync_value) | NewKey ($sync_key; $sync_value; FLOAT; BOOL) | UpdKey ($sync_key; $sync_value) | DelKey $sync_key | LockKey ($sync_key; FLOAT; BOOL) | LockOrCreateKey ($sync_key; FLOAT; BOOL) | UnlockKey $sync_key | Bye Void]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,Pointer)> fun380 { [&](std::shared_ptr<::dessser::gen::sync_client_cmd::t>  p_0, Pointer p_1) {
    Pointer id_381 { to_row_binary(p_0, p_1) };
    return id_381;
  }
   };
  return fun380;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_client_cmd::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
