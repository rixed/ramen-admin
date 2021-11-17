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


namespace dessser::gen::alerting_log {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct t89816cbdea496c3fdf253c2ff7eb9816 : public std::variant<
  Void, // Duplicate
  Void, // Inhibited
  Void, // STFU
  Void // StartEscalation
> { using variant::variant; };

inline bool operator==(t89816cbdea496c3fdf253c2ff7eb9816 const &a, t89816cbdea496c3fdf253c2ff7eb9816 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Duplicate
    case 1: return std::get<1>(a) == std::get<1>(b); // Inhibited
    case 2: return std::get<2>(a) == std::get<2>(b); // STFU
    case 3: return std::get<3>(a) == std::get<3>(b); // StartEscalation
  };
  return false;
}
inline bool operator!=(t89816cbdea496c3fdf253c2ff7eb9816 const &a, t89816cbdea496c3fdf253c2ff7eb9816 const &b) {
  return !operator==(a, b);
}
struct t634cf874353f100ca9a3d84e2b6c3c4b : public std::tuple<
  std::string,
  uint32_t
> {
  using tuple::tuple;
  t634cf874353f100ca9a3d84e2b6c3c4b(std::tuple<std::string, uint32_t> p)
    : std::tuple<std::string, uint32_t>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t634cf874353f100ca9a3d84e2b6c3c4b const &a, t634cf874353f100ca9a3d84e2b6c3c4b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t634cf874353f100ca9a3d84e2b6c3c4b const &a, t634cf874353f100ca9a3d84e2b6c3c4b const &b) {
  return !operator==(a, b);
}
struct tc13ab978611f6f6c6f0eb7ff36eb72f4 : public std::variant<
  Void, // Notification
  std::string, // Manual
  std::string // Timeout
> { using variant::variant; };

inline bool operator==(tc13ab978611f6f6c6f0eb7ff36eb72f4 const &a, tc13ab978611f6f6c6f0eb7ff36eb72f4 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Notification
    case 1: return std::get<1>(a) == std::get<1>(b); // Manual
    case 2: return std::get<2>(a) == std::get<2>(b); // Timeout
  };
  return false;
}
inline bool operator!=(tc13ab978611f6f6c6f0eb7ff36eb72f4 const &a, tc13ab978611f6f6c6f0eb7ff36eb72f4 const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816, // NewNotification
  ::dessser::gen::alerting_log::t634cf874353f100ca9a3d84e2b6c3c4b, // Outcry
  std::string, // Ack
  ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4, // Stop
  std::string // Cancel
> { using variant::variant; };

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // NewNotification
    case 1: return std::get<1>(a) == std::get<1>(b); // Outcry
    case 2: return std::get<2>(a) == std::get<2>(b); // Ack
    case 3: return std::get<3>(a) == std::get<3>(b); // Stop
    case 4: return std::get<4>(a) == std::get<4>(b); // Cancel
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t6b074172af0a13530a735ecaa0f9d4fe : public std::tuple<
  std::shared_ptr<::dessser::gen::alerting_log::t> ,
  Pointer
> {
  using tuple::tuple;
  t6b074172af0a13530a735ecaa0f9d4fe(std::tuple<std::shared_ptr<::dessser::gen::alerting_log::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::alerting_log::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6b074172af0a13530a735ecaa0f9d4fe const &a, t6b074172af0a13530a735ecaa0f9d4fe const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6b074172af0a13530a735ecaa0f9d4fe const &a, t6b074172af0a13530a735ecaa0f9d4fe const &b) {
  return !operator==(a, b);
}
struct t7609d344c1ba69d0f80fec236d4c216b : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  t7609d344c1ba69d0f80fec236d4c216b(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7609d344c1ba69d0f80fec236d4c216b const &a, t7609d344c1ba69d0f80fec236d4c216b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7609d344c1ba69d0f80fec236d4c216b const &a, t7609d344c1ba69d0f80fec236d4c216b const &b) {
  return !operator==(a, b);
}
struct t48e6907c7f46c8193257869ca01037f6 : public std::tuple<
  ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816,
  Pointer
> {
  using tuple::tuple;
  t48e6907c7f46c8193257869ca01037f6(std::tuple<::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816, Pointer> p)
    : std::tuple<::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t48e6907c7f46c8193257869ca01037f6 const &a, t48e6907c7f46c8193257869ca01037f6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t48e6907c7f46c8193257869ca01037f6 const &a, t48e6907c7f46c8193257869ca01037f6 const &b) {
  return !operator==(a, b);
}
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t044960e524fd6ec1bfc06410ce526709 const &a, t044960e524fd6ec1bfc06410ce526709 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t044960e524fd6ec1bfc06410ce526709 const &a, t044960e524fd6ec1bfc06410ce526709 const &b) {
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
struct t3fd8221434e489b54b5c4356ebff5005 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t3fd8221434e489b54b5c4356ebff5005(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3fd8221434e489b54b5c4356ebff5005 const &a, t3fd8221434e489b54b5c4356ebff5005 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3fd8221434e489b54b5c4356ebff5005 const &a, t3fd8221434e489b54b5c4356ebff5005 const &b) {
  return !operator==(a, b);
}
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5887709cc43c8c8e24d28211e8c970a2 const &a, t5887709cc43c8c8e24d28211e8c970a2 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5887709cc43c8c8e24d28211e8c970a2 const &a, t5887709cc43c8c8e24d28211e8c970a2 const &b) {
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
struct t0aabe0750109c9aec473d52493a4b4a8 : public std::tuple<
  ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4,
  Pointer
> {
  using tuple::tuple;
  t0aabe0750109c9aec473d52493a4b4a8(std::tuple<::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4, Pointer> p)
    : std::tuple<::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0aabe0750109c9aec473d52493a4b4a8 const &a, t0aabe0750109c9aec473d52493a4b4a8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0aabe0750109c9aec473d52493a4b4a8 const &a, t0aabe0750109c9aec473d52493a4b4a8 const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[NewNotification [Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void] | Outcry (STRING; U32) | Ack STRING | Stop [Notification Void | Manual STRING | Timeout STRING] | Cancel STRING]" "Ptr")
      (let "ssum_dst_212" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (let "ssum_dst_227" (write-u16 little-endian (identifier "ssum_dst_212") (label-of (get-alt "NewNotification" (param 0))))
            (if (eq (u16 0) (label-of (get-alt "NewNotification" (param 0)))) 
              (identifier "ssum_dst_227")
              (if (eq (u16 1) (label-of (get-alt "NewNotification" (param 0)))) 
                (identifier "ssum_dst_227")
                (if (eq (u16 2) (label-of (get-alt "NewNotification" (param 0)))) (identifier "ssum_dst_227") (seq (assert (eq (label-of (get-alt "NewNotification" (param 0))) (u16 3))) (identifier "ssum_dst_227"))))))
          (if (eq (u16 1) (label-of (param 0)))
            (let "stup_dst_225"
              (write-bytes
                (let "leb128_sz_223" (make-vec (string-length (get-item 0 (get-alt "Outcry" (param 0)))))
                  (let "leb128_ptr_224" (make-vec (identifier "ssum_dst_212"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_224")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_224"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_223"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_223"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_223"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_223") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_223")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_223")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_224"))))) 
                (bytes-of-string (get-item 0 (get-alt "Outcry" (param 0))))) 
              (write-u32 little-endian (identifier "stup_dst_225") (get-item 1 (get-alt "Outcry" (param 0)))))
            (if (eq (u16 2) (label-of (param 0)))
              (write-bytes
                (let "leb128_sz_221" (make-vec (string-length (get-alt "Ack" (param 0))))
                  (let "leb128_ptr_222" (make-vec (identifier "ssum_dst_212"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_222")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_222"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_221"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_221"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_221"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_221") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_221")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_221")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_222"))))) 
                (bytes-of-string (get-alt "Ack" (param 0))))
              (if (eq (u16 3) (label-of (param 0)))
                (let "ssum_dst_216" (write-u16 little-endian (identifier "ssum_dst_212") (label-of (get-alt "Stop" (param 0))))
                  (if (eq (u16 0) (label-of (get-alt "Stop" (param 0)))) 
                    (identifier "ssum_dst_216")
                    (if (eq (u16 1) (label-of (get-alt "Stop" (param 0))))
                      (write-bytes
                        (let "leb128_sz_219" (make-vec (string-length (get-alt "Manual" (get-alt "Stop" (param 0)))))
                          (let "leb128_ptr_220" (make-vec (identifier "ssum_dst_216"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_220")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_220"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_219"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_219"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_219"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_219") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_219")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_219")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_220"))))) 
                        (bytes-of-string (get-alt "Manual" (get-alt "Stop" (param 0)))))
                      (seq (assert (eq (label-of (get-alt "Stop" (param 0))) (u16 2)))
                        (write-bytes
                          (let "leb128_sz_217" (make-vec (string-length (get-alt "Timeout" (get-alt "Stop" (param 0)))))
                            (let "leb128_ptr_218" (make-vec (identifier "ssum_dst_216"))
                              (seq
                                (while
                                  (seq
                                    (set-vec (u8 0) (identifier "leb128_ptr_218")
                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_218"))
                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_217"))) 
                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_217"))) 
                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_217"))) (u8 128)))))
                                    (set-vec (u8 0) (identifier "leb128_sz_217") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_217")) (u8 7))) 
                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_217")) (u32 0))) 
                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_218"))))) 
                          (bytes-of-string (get-alt "Timeout" (get-alt "Stop" (param 0)))))))))
                (seq (assert (eq (label-of (param 0)) (u16 4)))
                  (write-bytes
                    (let "leb128_sz_213" (make-vec (string-length (get-alt "Cancel" (param 0))))
                      (let "leb128_ptr_214" (make-vec (identifier "ssum_dst_212"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_214")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_214"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_213"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_213"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_213"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_213") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_213")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_213")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_214"))))) 
                    (bytes-of-string (get-alt "Cancel" (param 0)))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_log::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_log::t> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::alerting_log::t>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_212 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_8 { std::get<0 /* NewNotification */>((*p_0)) };
        uint16_t id_9 { uint16_t(id_8.index()) };
        Pointer id_10 { ssum_dst_212.writeU16Le(id_9) };
        Pointer let_res_11;
        {
          Pointer ssum_dst_227 { id_10 };
          uint16_t id_12 { 0 };
          ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_13 { std::get<0 /* NewNotification */>((*p_0)) };
          uint16_t id_14 { uint16_t(id_13.index()) };
          bool id_15 { bool(id_12 == id_14) };
          Pointer choose_res_16;
          if (id_15) {
            choose_res_16 = ssum_dst_227;
          } else {
            uint16_t id_17 { 1 };
            ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_18 { std::get<0 /* NewNotification */>((*p_0)) };
            uint16_t id_19 { uint16_t(id_18.index()) };
            bool id_20 { bool(id_17 == id_19) };
            Pointer choose_res_21;
            if (id_20) {
              choose_res_21 = ssum_dst_227;
            } else {
              uint16_t id_22 { 2 };
              ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_23 { std::get<0 /* NewNotification */>((*p_0)) };
              uint16_t id_24 { uint16_t(id_23.index()) };
              bool id_25 { bool(id_22 == id_24) };
              Pointer choose_res_26;
              if (id_25) {
                choose_res_26 = ssum_dst_227;
              } else {
                ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_27 { std::get<0 /* NewNotification */>((*p_0)) };
                uint16_t id_28 { uint16_t(id_27.index()) };
                uint16_t id_29 { 3 };
                bool id_30 { bool(id_28 == id_29) };
                Void id_31 { ((void)(assert(id_30)), VOID) };
                (void)id_31;
                choose_res_26 = ssum_dst_227;
              }
              choose_res_21 = choose_res_26;
            }
            choose_res_16 = choose_res_21;
          }
          let_res_11 = choose_res_16;
        }
        choose_res_7 = let_res_11;
      } else {
        uint16_t id_32 { 1 };
        uint16_t id_33 { uint16_t((*p_0).index()) };
        bool id_34 { bool(id_32 == id_33) };
        Pointer choose_res_35;
        if (id_34) {
          ::dessser::gen::alerting_log::t634cf874353f100ca9a3d84e2b6c3c4b id_36 { std::get<1 /* Outcry */>((*p_0)) };
          std::string id_37 { std::get<0>(id_36) };
          uint32_t id_38 { (uint32_t)id_37.size() };
          Vec<1, uint32_t> id_39 {  id_38  };
          Pointer let_res_40;
          {
            Vec<1, uint32_t> leb128_sz_223 { id_39 };
            Vec<1, Pointer> id_41 {  ssum_dst_212  };
            Pointer let_res_42;
            {
              Vec<1, Pointer> leb128_ptr_224 { id_41 };
              bool while_flag_43 { true };
              do {
                uint8_t id_44 { 0 };
                uint8_t id_45 { 0 };
                Pointer id_46 { leb128_ptr_224[id_45] };
                uint32_t id_47 { 128U };
                uint8_t id_48 { 0 };
                uint32_t id_49 { leb128_sz_223[id_48] };
                bool id_50 { bool(id_47 > id_49) };
                uint8_t choose_res_51;
                if (id_50) {
                  uint8_t id_52 { 0 };
                  uint32_t id_53 { leb128_sz_223[id_52] };
                  uint8_t id_54 { uint8_t(id_53) };
                  choose_res_51 = id_54;
                } else {
                  uint8_t id_55 { 0 };
                  uint32_t id_56 { leb128_sz_223[id_55] };
                  uint8_t id_57 { uint8_t(id_56) };
                  uint8_t id_58 { 128 };
                  uint8_t id_59 { uint8_t(id_57 | id_58) };
                  choose_res_51 = id_59;
                }
                Pointer id_60 { id_46.writeU8(choose_res_51) };
                Void id_61 { ((void)(leb128_ptr_224[id_44] = id_60), VOID) };
                (void)id_61;
                uint8_t id_62 { 0 };
                uint8_t id_63 { 0 };
                uint32_t id_64 { leb128_sz_223[id_63] };
                uint8_t id_65 { 7 };
                uint32_t id_66 { uint32_t(id_64 >> id_65) };
                Void id_67 { ((void)(leb128_sz_223[id_62] = id_66), VOID) };
                (void)id_67;
                uint8_t id_68 { 0 };
                uint32_t id_69 { leb128_sz_223[id_68] };
                uint32_t id_70 { 0U };
                bool id_71 { bool(id_69 > id_70) };
                while_flag_43 = id_71;
                if (while_flag_43) {
                  (void)VOID;
                }
              } while (while_flag_43);
              (void)VOID;
              uint8_t id_72 { 0 };
              Pointer id_73 { leb128_ptr_224[id_72] };
              let_res_42 = id_73;
            }
            let_res_40 = let_res_42;
          }
          ::dessser::gen::alerting_log::t634cf874353f100ca9a3d84e2b6c3c4b id_74 { std::get<1 /* Outcry */>((*p_0)) };
          std::string id_75 { std::get<0>(id_74) };
          Bytes id_76 { id_75 };
          Pointer id_77 { let_res_40.writeBytes(id_76) };
          Pointer let_res_78;
          {
            Pointer stup_dst_225 { id_77 };
            ::dessser::gen::alerting_log::t634cf874353f100ca9a3d84e2b6c3c4b id_79 { std::get<1 /* Outcry */>((*p_0)) };
            uint32_t id_80 { std::get<1>(id_79) };
            Pointer id_81 { stup_dst_225.writeU32Le(id_80) };
            let_res_78 = id_81;
          }
          choose_res_35 = let_res_78;
        } else {
          uint16_t id_82 { 2 };
          uint16_t id_83 { uint16_t((*p_0).index()) };
          bool id_84 { bool(id_82 == id_83) };
          Pointer choose_res_85;
          if (id_84) {
            std::string id_86 { std::get<2 /* Ack */>((*p_0)) };
            uint32_t id_87 { (uint32_t)id_86.size() };
            Vec<1, uint32_t> id_88 {  id_87  };
            Pointer let_res_89;
            {
              Vec<1, uint32_t> leb128_sz_221 { id_88 };
              Vec<1, Pointer> id_90 {  ssum_dst_212  };
              Pointer let_res_91;
              {
                Vec<1, Pointer> leb128_ptr_222 { id_90 };
                bool while_flag_92 { true };
                do {
                  uint8_t id_93 { 0 };
                  uint8_t id_94 { 0 };
                  Pointer id_95 { leb128_ptr_222[id_94] };
                  uint32_t id_96 { 128U };
                  uint8_t id_97 { 0 };
                  uint32_t id_98 { leb128_sz_221[id_97] };
                  bool id_99 { bool(id_96 > id_98) };
                  uint8_t choose_res_100;
                  if (id_99) {
                    uint8_t id_101 { 0 };
                    uint32_t id_102 { leb128_sz_221[id_101] };
                    uint8_t id_103 { uint8_t(id_102) };
                    choose_res_100 = id_103;
                  } else {
                    uint8_t id_104 { 0 };
                    uint32_t id_105 { leb128_sz_221[id_104] };
                    uint8_t id_106 { uint8_t(id_105) };
                    uint8_t id_107 { 128 };
                    uint8_t id_108 { uint8_t(id_106 | id_107) };
                    choose_res_100 = id_108;
                  }
                  Pointer id_109 { id_95.writeU8(choose_res_100) };
                  Void id_110 { ((void)(leb128_ptr_222[id_93] = id_109), VOID) };
                  (void)id_110;
                  uint8_t id_111 { 0 };
                  uint8_t id_112 { 0 };
                  uint32_t id_113 { leb128_sz_221[id_112] };
                  uint8_t id_114 { 7 };
                  uint32_t id_115 { uint32_t(id_113 >> id_114) };
                  Void id_116 { ((void)(leb128_sz_221[id_111] = id_115), VOID) };
                  (void)id_116;
                  uint8_t id_117 { 0 };
                  uint32_t id_118 { leb128_sz_221[id_117] };
                  uint32_t id_119 { 0U };
                  bool id_120 { bool(id_118 > id_119) };
                  while_flag_92 = id_120;
                  if (while_flag_92) {
                    (void)VOID;
                  }
                } while (while_flag_92);
                (void)VOID;
                uint8_t id_121 { 0 };
                Pointer id_122 { leb128_ptr_222[id_121] };
                let_res_91 = id_122;
              }
              let_res_89 = let_res_91;
            }
            std::string id_123 { std::get<2 /* Ack */>((*p_0)) };
            Bytes id_124 { id_123 };
            Pointer id_125 { let_res_89.writeBytes(id_124) };
            choose_res_85 = id_125;
          } else {
            uint16_t id_126 { 3 };
            uint16_t id_127 { uint16_t((*p_0).index()) };
            bool id_128 { bool(id_126 == id_127) };
            Pointer choose_res_129;
            if (id_128) {
              ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_130 { std::get<3 /* Stop */>((*p_0)) };
              uint16_t id_131 { uint16_t(id_130.index()) };
              Pointer id_132 { ssum_dst_212.writeU16Le(id_131) };
              Pointer let_res_133;
              {
                Pointer ssum_dst_216 { id_132 };
                uint16_t id_134 { 0 };
                ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_135 { std::get<3 /* Stop */>((*p_0)) };
                uint16_t id_136 { uint16_t(id_135.index()) };
                bool id_137 { bool(id_134 == id_136) };
                Pointer choose_res_138;
                if (id_137) {
                  choose_res_138 = ssum_dst_216;
                } else {
                  uint16_t id_139 { 1 };
                  ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_140 { std::get<3 /* Stop */>((*p_0)) };
                  uint16_t id_141 { uint16_t(id_140.index()) };
                  bool id_142 { bool(id_139 == id_141) };
                  Pointer choose_res_143;
                  if (id_142) {
                    ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_144 { std::get<3 /* Stop */>((*p_0)) };
                    std::string id_145 { std::get<1 /* Manual */>(id_144) };
                    uint32_t id_146 { (uint32_t)id_145.size() };
                    Vec<1, uint32_t> id_147 {  id_146  };
                    Pointer let_res_148;
                    {
                      Vec<1, uint32_t> leb128_sz_219 { id_147 };
                      Vec<1, Pointer> id_149 {  ssum_dst_216  };
                      Pointer let_res_150;
                      {
                        Vec<1, Pointer> leb128_ptr_220 { id_149 };
                        bool while_flag_151 { true };
                        do {
                          uint8_t id_152 { 0 };
                          uint8_t id_153 { 0 };
                          Pointer id_154 { leb128_ptr_220[id_153] };
                          uint32_t id_155 { 128U };
                          uint8_t id_156 { 0 };
                          uint32_t id_157 { leb128_sz_219[id_156] };
                          bool id_158 { bool(id_155 > id_157) };
                          uint8_t choose_res_159;
                          if (id_158) {
                            uint8_t id_160 { 0 };
                            uint32_t id_161 { leb128_sz_219[id_160] };
                            uint8_t id_162 { uint8_t(id_161) };
                            choose_res_159 = id_162;
                          } else {
                            uint8_t id_163 { 0 };
                            uint32_t id_164 { leb128_sz_219[id_163] };
                            uint8_t id_165 { uint8_t(id_164) };
                            uint8_t id_166 { 128 };
                            uint8_t id_167 { uint8_t(id_165 | id_166) };
                            choose_res_159 = id_167;
                          }
                          Pointer id_168 { id_154.writeU8(choose_res_159) };
                          Void id_169 { ((void)(leb128_ptr_220[id_152] = id_168), VOID) };
                          (void)id_169;
                          uint8_t id_170 { 0 };
                          uint8_t id_171 { 0 };
                          uint32_t id_172 { leb128_sz_219[id_171] };
                          uint8_t id_173 { 7 };
                          uint32_t id_174 { uint32_t(id_172 >> id_173) };
                          Void id_175 { ((void)(leb128_sz_219[id_170] = id_174), VOID) };
                          (void)id_175;
                          uint8_t id_176 { 0 };
                          uint32_t id_177 { leb128_sz_219[id_176] };
                          uint32_t id_178 { 0U };
                          bool id_179 { bool(id_177 > id_178) };
                          while_flag_151 = id_179;
                          if (while_flag_151) {
                            (void)VOID;
                          }
                        } while (while_flag_151);
                        (void)VOID;
                        uint8_t id_180 { 0 };
                        Pointer id_181 { leb128_ptr_220[id_180] };
                        let_res_150 = id_181;
                      }
                      let_res_148 = let_res_150;
                    }
                    ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_182 { std::get<3 /* Stop */>((*p_0)) };
                    std::string id_183 { std::get<1 /* Manual */>(id_182) };
                    Bytes id_184 { id_183 };
                    Pointer id_185 { let_res_148.writeBytes(id_184) };
                    choose_res_143 = id_185;
                  } else {
                    ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_186 { std::get<3 /* Stop */>((*p_0)) };
                    uint16_t id_187 { uint16_t(id_186.index()) };
                    uint16_t id_188 { 2 };
                    bool id_189 { bool(id_187 == id_188) };
                    Void id_190 { ((void)(assert(id_189)), VOID) };
                    (void)id_190;
                    ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_191 { std::get<3 /* Stop */>((*p_0)) };
                    std::string id_192 { std::get<2 /* Timeout */>(id_191) };
                    uint32_t id_193 { (uint32_t)id_192.size() };
                    Vec<1, uint32_t> id_194 {  id_193  };
                    Pointer let_res_195;
                    {
                      Vec<1, uint32_t> leb128_sz_217 { id_194 };
                      Vec<1, Pointer> id_196 {  ssum_dst_216  };
                      Pointer let_res_197;
                      {
                        Vec<1, Pointer> leb128_ptr_218 { id_196 };
                        bool while_flag_198 { true };
                        do {
                          uint8_t id_199 { 0 };
                          uint8_t id_200 { 0 };
                          Pointer id_201 { leb128_ptr_218[id_200] };
                          uint32_t id_202 { 128U };
                          uint8_t id_203 { 0 };
                          uint32_t id_204 { leb128_sz_217[id_203] };
                          bool id_205 { bool(id_202 > id_204) };
                          uint8_t choose_res_206;
                          if (id_205) {
                            uint8_t id_207 { 0 };
                            uint32_t id_208 { leb128_sz_217[id_207] };
                            uint8_t id_209 { uint8_t(id_208) };
                            choose_res_206 = id_209;
                          } else {
                            uint8_t id_210 { 0 };
                            uint32_t id_211 { leb128_sz_217[id_210] };
                            uint8_t id_212 { uint8_t(id_211) };
                            uint8_t id_213 { 128 };
                            uint8_t id_214 { uint8_t(id_212 | id_213) };
                            choose_res_206 = id_214;
                          }
                          Pointer id_215 { id_201.writeU8(choose_res_206) };
                          Void id_216 { ((void)(leb128_ptr_218[id_199] = id_215), VOID) };
                          (void)id_216;
                          uint8_t id_217 { 0 };
                          uint8_t id_218 { 0 };
                          uint32_t id_219 { leb128_sz_217[id_218] };
                          uint8_t id_220 { 7 };
                          uint32_t id_221 { uint32_t(id_219 >> id_220) };
                          Void id_222 { ((void)(leb128_sz_217[id_217] = id_221), VOID) };
                          (void)id_222;
                          uint8_t id_223 { 0 };
                          uint32_t id_224 { leb128_sz_217[id_223] };
                          uint32_t id_225 { 0U };
                          bool id_226 { bool(id_224 > id_225) };
                          while_flag_198 = id_226;
                          if (while_flag_198) {
                            (void)VOID;
                          }
                        } while (while_flag_198);
                        (void)VOID;
                        uint8_t id_227 { 0 };
                        Pointer id_228 { leb128_ptr_218[id_227] };
                        let_res_197 = id_228;
                      }
                      let_res_195 = let_res_197;
                    }
                    ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_229 { std::get<3 /* Stop */>((*p_0)) };
                    std::string id_230 { std::get<2 /* Timeout */>(id_229) };
                    Bytes id_231 { id_230 };
                    Pointer id_232 { let_res_195.writeBytes(id_231) };
                    choose_res_143 = id_232;
                  }
                  choose_res_138 = choose_res_143;
                }
                let_res_133 = choose_res_138;
              }
              choose_res_129 = let_res_133;
            } else {
              uint16_t id_233 { uint16_t((*p_0).index()) };
              uint16_t id_234 { 4 };
              bool id_235 { bool(id_233 == id_234) };
              Void id_236 { ((void)(assert(id_235)), VOID) };
              (void)id_236;
              std::string id_237 { std::get<4 /* Cancel */>((*p_0)) };
              uint32_t id_238 { (uint32_t)id_237.size() };
              Vec<1, uint32_t> id_239 {  id_238  };
              Pointer let_res_240;
              {
                Vec<1, uint32_t> leb128_sz_213 { id_239 };
                Vec<1, Pointer> id_241 {  ssum_dst_212  };
                Pointer let_res_242;
                {
                  Vec<1, Pointer> leb128_ptr_214 { id_241 };
                  bool while_flag_243 { true };
                  do {
                    uint8_t id_244 { 0 };
                    uint8_t id_245 { 0 };
                    Pointer id_246 { leb128_ptr_214[id_245] };
                    uint32_t id_247 { 128U };
                    uint8_t id_248 { 0 };
                    uint32_t id_249 { leb128_sz_213[id_248] };
                    bool id_250 { bool(id_247 > id_249) };
                    uint8_t choose_res_251;
                    if (id_250) {
                      uint8_t id_252 { 0 };
                      uint32_t id_253 { leb128_sz_213[id_252] };
                      uint8_t id_254 { uint8_t(id_253) };
                      choose_res_251 = id_254;
                    } else {
                      uint8_t id_255 { 0 };
                      uint32_t id_256 { leb128_sz_213[id_255] };
                      uint8_t id_257 { uint8_t(id_256) };
                      uint8_t id_258 { 128 };
                      uint8_t id_259 { uint8_t(id_257 | id_258) };
                      choose_res_251 = id_259;
                    }
                    Pointer id_260 { id_246.writeU8(choose_res_251) };
                    Void id_261 { ((void)(leb128_ptr_214[id_244] = id_260), VOID) };
                    (void)id_261;
                    uint8_t id_262 { 0 };
                    uint8_t id_263 { 0 };
                    uint32_t id_264 { leb128_sz_213[id_263] };
                    uint8_t id_265 { 7 };
                    uint32_t id_266 { uint32_t(id_264 >> id_265) };
                    Void id_267 { ((void)(leb128_sz_213[id_262] = id_266), VOID) };
                    (void)id_267;
                    uint8_t id_268 { 0 };
                    uint32_t id_269 { leb128_sz_213[id_268] };
                    uint32_t id_270 { 0U };
                    bool id_271 { bool(id_269 > id_270) };
                    while_flag_243 = id_271;
                    if (while_flag_243) {
                      (void)VOID;
                    }
                  } while (while_flag_243);
                  (void)VOID;
                  uint8_t id_272 { 0 };
                  Pointer id_273 { leb128_ptr_214[id_272] };
                  let_res_242 = id_273;
                }
                let_res_240 = let_res_242;
              }
              std::string id_274 { std::get<4 /* Cancel */>((*p_0)) };
              Bytes id_275 { id_274 };
              Pointer id_276 { let_res_240.writeBytes(id_275) };
              choose_res_129 = id_276;
            }
            choose_res_85 = choose_res_129;
          }
          choose_res_35 = choose_res_85;
        }
        choose_res_7 = choose_res_35;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::alerting_log::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[NewNotification [Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void] | Outcry (STRING; U32) | Ack STRING | Stop [Notification Void | Manual STRING | Timeout STRING] | Cancel STRING]")
      (if (eq (u16 0) (label-of (param 0)))
        (if (eq (u16 0) (label-of (get-alt "NewNotification" (param 0)))) 
          (size 4)
          (if (eq (u16 1) (label-of (get-alt "NewNotification" (param 0)))) 
            (size 4) (if (eq (u16 2) (label-of (get-alt "NewNotification" (param 0)))) (size 4) (seq (assert (eq (label-of (get-alt "NewNotification" (param 0))) (u16 3))) (size 4)))))
        (if (eq (u16 1) (label-of (param 0)))
          (add
            (add (size 2)
              (add
                (let "n_ref_207" (make-vec (string-length (get-item 0 (get-alt "Outcry" (param 0)))))
                  (let "lebsz_ref_208" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_207")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_208")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_208") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_208")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_208")))))) 
                (size-of-u32 (string-length (get-item 0 (get-alt "Outcry" (param 0))))))) 
            (size 4))
          (if (eq (u16 2) (label-of (param 0)))
            (add (size 2)
              (add
                (let "n_ref_203" (make-vec (string-length (get-alt "Ack" (param 0))))
                  (let "lebsz_ref_204" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_203")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_204")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_204") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_204")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_204")))))) 
                (size-of-u32 (string-length (get-alt "Ack" (param 0))))))
            (if (eq (u16 3) (label-of (param 0)))
              (if (eq (u16 0) (label-of (get-alt "Stop" (param 0)))) 
                (size 4)
                (if (eq (u16 1) (label-of (get-alt "Stop" (param 0))))
                  (add (size 4)
                    (add
                      (let "n_ref_200" (make-vec (string-length (get-alt "Manual" (get-alt "Stop" (param 0)))))
                        (let "lebsz_ref_201" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_200")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_201")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_201") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_201")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_201")))))) 
                      (size-of-u32 (string-length (get-alt "Manual" (get-alt "Stop" (param 0)))))))
                  (seq (assert (eq (label-of (get-alt "Stop" (param 0))) (u16 2)))
                    (add (size 4)
                      (add
                        (let "n_ref_197" (make-vec (string-length (get-alt "Timeout" (get-alt "Stop" (param 0)))))
                          (let "lebsz_ref_198" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_197")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_198")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_198") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_198")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_198")))))) 
                        (size-of-u32 (string-length (get-alt "Timeout" (get-alt "Stop" (param 0))))))))))
              (seq (assert (eq (label-of (param 0)) (u16 4)))
                (add (size 2)
                  (add
                    (let "n_ref_193" (make-vec (string-length (get-alt "Cancel" (param 0))))
                      (let "lebsz_ref_194" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_193")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_194")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_194") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_194")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_194")))))) 
                    (size-of-u32 (string-length (get-alt "Cancel" (param 0))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::alerting_log::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::alerting_log::t> )> fun277 { [&fun277](std::shared_ptr<::dessser::gen::alerting_log::t>  p_0) {
    uint16_t id_278 { 0 };
    uint16_t id_279 { uint16_t((*p_0).index()) };
    bool id_280 { bool(id_278 == id_279) };
    Size choose_res_281;
    if (id_280) {
      uint16_t id_282 { 0 };
      ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_283 { std::get<0 /* NewNotification */>((*p_0)) };
      uint16_t id_284 { uint16_t(id_283.index()) };
      bool id_285 { bool(id_282 == id_284) };
      Size choose_res_286;
      if (id_285) {
        Size id_287 { 4UL };
        choose_res_286 = id_287;
      } else {
        uint16_t id_288 { 1 };
        ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_289 { std::get<0 /* NewNotification */>((*p_0)) };
        uint16_t id_290 { uint16_t(id_289.index()) };
        bool id_291 { bool(id_288 == id_290) };
        Size choose_res_292;
        if (id_291) {
          Size id_293 { 4UL };
          choose_res_292 = id_293;
        } else {
          uint16_t id_294 { 2 };
          ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_295 { std::get<0 /* NewNotification */>((*p_0)) };
          uint16_t id_296 { uint16_t(id_295.index()) };
          bool id_297 { bool(id_294 == id_296) };
          Size choose_res_298;
          if (id_297) {
            Size id_299 { 4UL };
            choose_res_298 = id_299;
          } else {
            ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_300 { std::get<0 /* NewNotification */>((*p_0)) };
            uint16_t id_301 { uint16_t(id_300.index()) };
            uint16_t id_302 { 3 };
            bool id_303 { bool(id_301 == id_302) };
            Void id_304 { ((void)(assert(id_303)), VOID) };
            (void)id_304;
            Size id_305 { 4UL };
            choose_res_298 = id_305;
          }
          choose_res_292 = choose_res_298;
        }
        choose_res_286 = choose_res_292;
      }
      choose_res_281 = choose_res_286;
    } else {
      uint16_t id_306 { 1 };
      uint16_t id_307 { uint16_t((*p_0).index()) };
      bool id_308 { bool(id_306 == id_307) };
      Size choose_res_309;
      if (id_308) {
        Size id_310 { 2UL };
        ::dessser::gen::alerting_log::t634cf874353f100ca9a3d84e2b6c3c4b id_311 { std::get<1 /* Outcry */>((*p_0)) };
        std::string id_312 { std::get<0>(id_311) };
        uint32_t id_313 { (uint32_t)id_312.size() };
        Vec<1, uint32_t> id_314 {  id_313  };
        Size let_res_315;
        {
          Vec<1, uint32_t> n_ref_207 { id_314 };
          uint32_t id_316 { 1U };
          Vec<1, uint32_t> id_317 {  id_316  };
          Size let_res_318;
          {
            Vec<1, uint32_t> lebsz_ref_208 { id_317 };
            bool while_flag_319 { true };
            do {
              uint8_t id_320 { 0 };
              uint32_t id_321 { n_ref_207[id_320] };
              uint8_t id_322 { 0 };
              uint32_t id_323 { lebsz_ref_208[id_322] };
              uint8_t id_324 { 7 };
              uint32_t id_325 { uint32_t(id_323 << id_324) };
              bool id_326 { bool(id_321 >= id_325) };
              while_flag_319 = id_326;
              if (while_flag_319) {
                uint8_t id_327 { 0 };
                uint8_t id_328 { 0 };
                uint32_t id_329 { lebsz_ref_208[id_328] };
                uint32_t id_330 { 1U };
                uint32_t id_331 { uint32_t(id_329 + id_330) };
                Void id_332 { ((void)(lebsz_ref_208[id_327] = id_331), VOID) };
                (void)id_332;
              }
            } while (while_flag_319);
            (void)VOID;
            uint8_t id_333 { 0 };
            uint32_t id_334 { lebsz_ref_208[id_333] };
            Size id_335 { Size(id_334) };
            let_res_318 = id_335;
          }
          let_res_315 = let_res_318;
        }
        ::dessser::gen::alerting_log::t634cf874353f100ca9a3d84e2b6c3c4b id_336 { std::get<1 /* Outcry */>((*p_0)) };
        std::string id_337 { std::get<0>(id_336) };
        uint32_t id_338 { (uint32_t)id_337.size() };
        Size id_339 { Size(id_338) };
        Size id_340 { Size(let_res_315 + id_339) };
        Size id_341 { Size(id_310 + id_340) };
        Size id_342 { 4UL };
        Size id_343 { Size(id_341 + id_342) };
        choose_res_309 = id_343;
      } else {
        uint16_t id_344 { 2 };
        uint16_t id_345 { uint16_t((*p_0).index()) };
        bool id_346 { bool(id_344 == id_345) };
        Size choose_res_347;
        if (id_346) {
          Size id_348 { 2UL };
          std::string id_349 { std::get<2 /* Ack */>((*p_0)) };
          uint32_t id_350 { (uint32_t)id_349.size() };
          Vec<1, uint32_t> id_351 {  id_350  };
          Size let_res_352;
          {
            Vec<1, uint32_t> n_ref_203 { id_351 };
            uint32_t id_353 { 1U };
            Vec<1, uint32_t> id_354 {  id_353  };
            Size let_res_355;
            {
              Vec<1, uint32_t> lebsz_ref_204 { id_354 };
              bool while_flag_356 { true };
              do {
                uint8_t id_357 { 0 };
                uint32_t id_358 { n_ref_203[id_357] };
                uint8_t id_359 { 0 };
                uint32_t id_360 { lebsz_ref_204[id_359] };
                uint8_t id_361 { 7 };
                uint32_t id_362 { uint32_t(id_360 << id_361) };
                bool id_363 { bool(id_358 >= id_362) };
                while_flag_356 = id_363;
                if (while_flag_356) {
                  uint8_t id_364 { 0 };
                  uint8_t id_365 { 0 };
                  uint32_t id_366 { lebsz_ref_204[id_365] };
                  uint32_t id_367 { 1U };
                  uint32_t id_368 { uint32_t(id_366 + id_367) };
                  Void id_369 { ((void)(lebsz_ref_204[id_364] = id_368), VOID) };
                  (void)id_369;
                }
              } while (while_flag_356);
              (void)VOID;
              uint8_t id_370 { 0 };
              uint32_t id_371 { lebsz_ref_204[id_370] };
              Size id_372 { Size(id_371) };
              let_res_355 = id_372;
            }
            let_res_352 = let_res_355;
          }
          std::string id_373 { std::get<2 /* Ack */>((*p_0)) };
          uint32_t id_374 { (uint32_t)id_373.size() };
          Size id_375 { Size(id_374) };
          Size id_376 { Size(let_res_352 + id_375) };
          Size id_377 { Size(id_348 + id_376) };
          choose_res_347 = id_377;
        } else {
          uint16_t id_378 { 3 };
          uint16_t id_379 { uint16_t((*p_0).index()) };
          bool id_380 { bool(id_378 == id_379) };
          Size choose_res_381;
          if (id_380) {
            uint16_t id_382 { 0 };
            ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_383 { std::get<3 /* Stop */>((*p_0)) };
            uint16_t id_384 { uint16_t(id_383.index()) };
            bool id_385 { bool(id_382 == id_384) };
            Size choose_res_386;
            if (id_385) {
              Size id_387 { 4UL };
              choose_res_386 = id_387;
            } else {
              uint16_t id_388 { 1 };
              ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_389 { std::get<3 /* Stop */>((*p_0)) };
              uint16_t id_390 { uint16_t(id_389.index()) };
              bool id_391 { bool(id_388 == id_390) };
              Size choose_res_392;
              if (id_391) {
                Size id_393 { 4UL };
                ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_394 { std::get<3 /* Stop */>((*p_0)) };
                std::string id_395 { std::get<1 /* Manual */>(id_394) };
                uint32_t id_396 { (uint32_t)id_395.size() };
                Vec<1, uint32_t> id_397 {  id_396  };
                Size let_res_398;
                {
                  Vec<1, uint32_t> n_ref_200 { id_397 };
                  uint32_t id_399 { 1U };
                  Vec<1, uint32_t> id_400 {  id_399  };
                  Size let_res_401;
                  {
                    Vec<1, uint32_t> lebsz_ref_201 { id_400 };
                    bool while_flag_402 { true };
                    do {
                      uint8_t id_403 { 0 };
                      uint32_t id_404 { n_ref_200[id_403] };
                      uint8_t id_405 { 0 };
                      uint32_t id_406 { lebsz_ref_201[id_405] };
                      uint8_t id_407 { 7 };
                      uint32_t id_408 { uint32_t(id_406 << id_407) };
                      bool id_409 { bool(id_404 >= id_408) };
                      while_flag_402 = id_409;
                      if (while_flag_402) {
                        uint8_t id_410 { 0 };
                        uint8_t id_411 { 0 };
                        uint32_t id_412 { lebsz_ref_201[id_411] };
                        uint32_t id_413 { 1U };
                        uint32_t id_414 { uint32_t(id_412 + id_413) };
                        Void id_415 { ((void)(lebsz_ref_201[id_410] = id_414), VOID) };
                        (void)id_415;
                      }
                    } while (while_flag_402);
                    (void)VOID;
                    uint8_t id_416 { 0 };
                    uint32_t id_417 { lebsz_ref_201[id_416] };
                    Size id_418 { Size(id_417) };
                    let_res_401 = id_418;
                  }
                  let_res_398 = let_res_401;
                }
                ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_419 { std::get<3 /* Stop */>((*p_0)) };
                std::string id_420 { std::get<1 /* Manual */>(id_419) };
                uint32_t id_421 { (uint32_t)id_420.size() };
                Size id_422 { Size(id_421) };
                Size id_423 { Size(let_res_398 + id_422) };
                Size id_424 { Size(id_393 + id_423) };
                choose_res_392 = id_424;
              } else {
                ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_425 { std::get<3 /* Stop */>((*p_0)) };
                uint16_t id_426 { uint16_t(id_425.index()) };
                uint16_t id_427 { 2 };
                bool id_428 { bool(id_426 == id_427) };
                Void id_429 { ((void)(assert(id_428)), VOID) };
                (void)id_429;
                Size id_430 { 4UL };
                ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_431 { std::get<3 /* Stop */>((*p_0)) };
                std::string id_432 { std::get<2 /* Timeout */>(id_431) };
                uint32_t id_433 { (uint32_t)id_432.size() };
                Vec<1, uint32_t> id_434 {  id_433  };
                Size let_res_435;
                {
                  Vec<1, uint32_t> n_ref_197 { id_434 };
                  uint32_t id_436 { 1U };
                  Vec<1, uint32_t> id_437 {  id_436  };
                  Size let_res_438;
                  {
                    Vec<1, uint32_t> lebsz_ref_198 { id_437 };
                    bool while_flag_439 { true };
                    do {
                      uint8_t id_440 { 0 };
                      uint32_t id_441 { n_ref_197[id_440] };
                      uint8_t id_442 { 0 };
                      uint32_t id_443 { lebsz_ref_198[id_442] };
                      uint8_t id_444 { 7 };
                      uint32_t id_445 { uint32_t(id_443 << id_444) };
                      bool id_446 { bool(id_441 >= id_445) };
                      while_flag_439 = id_446;
                      if (while_flag_439) {
                        uint8_t id_447 { 0 };
                        uint8_t id_448 { 0 };
                        uint32_t id_449 { lebsz_ref_198[id_448] };
                        uint32_t id_450 { 1U };
                        uint32_t id_451 { uint32_t(id_449 + id_450) };
                        Void id_452 { ((void)(lebsz_ref_198[id_447] = id_451), VOID) };
                        (void)id_452;
                      }
                    } while (while_flag_439);
                    (void)VOID;
                    uint8_t id_453 { 0 };
                    uint32_t id_454 { lebsz_ref_198[id_453] };
                    Size id_455 { Size(id_454) };
                    let_res_438 = id_455;
                  }
                  let_res_435 = let_res_438;
                }
                ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_456 { std::get<3 /* Stop */>((*p_0)) };
                std::string id_457 { std::get<2 /* Timeout */>(id_456) };
                uint32_t id_458 { (uint32_t)id_457.size() };
                Size id_459 { Size(id_458) };
                Size id_460 { Size(let_res_435 + id_459) };
                Size id_461 { Size(id_430 + id_460) };
                choose_res_392 = id_461;
              }
              choose_res_386 = choose_res_392;
            }
            choose_res_381 = choose_res_386;
          } else {
            uint16_t id_462 { uint16_t((*p_0).index()) };
            uint16_t id_463 { 4 };
            bool id_464 { bool(id_462 == id_463) };
            Void id_465 { ((void)(assert(id_464)), VOID) };
            (void)id_465;
            Size id_466 { 2UL };
            std::string id_467 { std::get<4 /* Cancel */>((*p_0)) };
            uint32_t id_468 { (uint32_t)id_467.size() };
            Vec<1, uint32_t> id_469 {  id_468  };
            Size let_res_470;
            {
              Vec<1, uint32_t> n_ref_193 { id_469 };
              uint32_t id_471 { 1U };
              Vec<1, uint32_t> id_472 {  id_471  };
              Size let_res_473;
              {
                Vec<1, uint32_t> lebsz_ref_194 { id_472 };
                bool while_flag_474 { true };
                do {
                  uint8_t id_475 { 0 };
                  uint32_t id_476 { n_ref_193[id_475] };
                  uint8_t id_477 { 0 };
                  uint32_t id_478 { lebsz_ref_194[id_477] };
                  uint8_t id_479 { 7 };
                  uint32_t id_480 { uint32_t(id_478 << id_479) };
                  bool id_481 { bool(id_476 >= id_480) };
                  while_flag_474 = id_481;
                  if (while_flag_474) {
                    uint8_t id_482 { 0 };
                    uint8_t id_483 { 0 };
                    uint32_t id_484 { lebsz_ref_194[id_483] };
                    uint32_t id_485 { 1U };
                    uint32_t id_486 { uint32_t(id_484 + id_485) };
                    Void id_487 { ((void)(lebsz_ref_194[id_482] = id_486), VOID) };
                    (void)id_487;
                  }
                } while (while_flag_474);
                (void)VOID;
                uint8_t id_488 { 0 };
                uint32_t id_489 { lebsz_ref_194[id_488] };
                Size id_490 { Size(id_489) };
                let_res_473 = id_490;
              }
              let_res_470 = let_res_473;
            }
            std::string id_491 { std::get<4 /* Cancel */>((*p_0)) };
            uint32_t id_492 { (uint32_t)id_491.size() };
            Size id_493 { Size(id_492) };
            Size id_494 { Size(let_res_470 + id_493) };
            Size id_495 { Size(id_466 + id_494) };
            choose_res_381 = id_495;
          }
          choose_res_347 = choose_res_381;
        }
        choose_res_309 = choose_res_347;
      }
      choose_res_281 = choose_res_309;
    }
    return choose_res_281;
  }
   };
  return fun277;
}
std::function<Size(std::shared_ptr<::dessser::gen::alerting_log::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_189" "make_snd_190"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let-pair "dsum2_fst_186" "dsum2_snd_187"
                (let "dsum1_170" (let-pair "du16_fst_165" "du16_snd_166" (read-u16 little-endian (identifier "dsum1_snd_64")) (make-tup (identifier "du16_fst_165") (identifier "du16_snd_166")))
                  (let-pair "dsum1_fst_171" "dsum1_snd_172" (identifier "dsum1_170")
                    (if (eq (u16 0) (identifier "dsum1_fst_171")) (make-tup (construct "[Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void]" 0 (nop)) (identifier "dsum1_snd_172"))
                      (if (eq (u16 1) (identifier "dsum1_fst_171")) (make-tup (construct "[Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void]" 1 (nop)) (identifier "dsum1_snd_172"))
                        (if (eq (u16 2) (identifier "dsum1_fst_171")) 
                          (make-tup (construct "[Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void]" 2 (nop)) (identifier "dsum1_snd_172"))
                          (seq (assert (eq (identifier "dsum1_fst_171") (u16 3))) (make-tup (construct "[Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void]" 3 (nop)) (identifier "dsum1_snd_172"))))))))
                (make-tup
                  (construct "[NewNotification [Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void] | Outcry (STRING; U32) | Ack STRING | Stop [Notification Void | Manual STRING | Timeout STRING] | Cancel STRING]" 0
                    (identifier "dsum2_fst_186")) (identifier "dsum2_snd_187")))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (let "dtup_152"
                  (let "dstring1_146"
                    (let "leb_ref_140" (make-vec (u32 0))
                      (let "shft_ref_141" (make-vec (u8 0))
                        (let "p_ref_142" (make-vec (identifier "dsum1_snd_64"))
                          (seq
                            (while
                              (let "leb128_143" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_142")))
                                (let-pair "leb128_fst_144" "leb128_snd_145" 
                                  (identifier "leb128_143")
                                  (seq (set-vec (u8 0) (identifier "p_ref_142") (identifier "leb128_snd_145"))
                                    (set-vec (u8 0) (identifier "leb_ref_140")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_144") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_141"))) (unsafe-nth (u8 0) (identifier "leb_ref_140"))))
                                    (set-vec (u8 0) (identifier "shft_ref_141") (add (unsafe-nth (u8 0) (identifier "shft_ref_141")) (u8 7))) 
                                    (ge (identifier "leb128_fst_144") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_140"))) (unsafe-nth (u8 0) (identifier "p_ref_142")))))))
                    (let-pair "dstring1_fst_147" "dstring1_snd_148" (identifier "dstring1_146")
                      (let-pair "dstring2_fst_150" "dstring2_snd_151" 
                        (read-bytes (identifier "dstring1_snd_148") (identifier "dstring1_fst_147")) 
                        (make-tup (string-of-bytes (identifier "dstring2_fst_150")) (identifier "dstring2_snd_151")))))
                  (let-pair "dtup_fst_153" "dtup_snd_154" (identifier "dtup_152")
                    (let-pair "du32_fst_156" "du32_snd_157" (read-u32 little-endian (identifier "dtup_snd_154"))
                      (make-tup
                        (construct "[NewNotification [Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void] | Outcry (STRING; U32) | Ack STRING | Stop [Notification Void | Manual STRING | Timeout STRING] | Cancel STRING]" 1
                          (make-tup (identifier "dtup_fst_153") (identifier "du32_fst_156"))) 
                        (identifier "du32_snd_157")))))
                (if (eq (u16 2) (identifier "dsum1_fst_63"))
                  (let "dstring1_131"
                    (let "leb_ref_125" (make-vec (u32 0))
                      (let "shft_ref_126" (make-vec (u8 0))
                        (let "p_ref_127" (make-vec (identifier "dsum1_snd_64"))
                          (seq
                            (while
                              (let "leb128_128" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_127")))
                                (let-pair "leb128_fst_129" "leb128_snd_130" 
                                  (identifier "leb128_128")
                                  (seq (set-vec (u8 0) (identifier "p_ref_127") (identifier "leb128_snd_130"))
                                    (set-vec (u8 0) (identifier "leb_ref_125")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_129") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_126"))) (unsafe-nth (u8 0) (identifier "leb_ref_125"))))
                                    (set-vec (u8 0) (identifier "shft_ref_126") (add (unsafe-nth (u8 0) (identifier "shft_ref_126")) (u8 7))) 
                                    (ge (identifier "leb128_fst_129") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_125"))) (unsafe-nth (u8 0) (identifier "p_ref_127")))))))
                    (let-pair "dstring1_fst_132" "dstring1_snd_133" (identifier "dstring1_131")
                      (let-pair "dstring2_fst_135" "dstring2_snd_136" 
                        (read-bytes (identifier "dstring1_snd_133") (identifier "dstring1_fst_132"))
                        (make-tup
                          (construct "[NewNotification [Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void] | Outcry (STRING; U32) | Ack STRING | Stop [Notification Void | Manual STRING | Timeout STRING] | Cancel STRING]" 2
                            (string-of-bytes (identifier "dstring2_fst_135"))) 
                          (identifier "dstring2_snd_136")))))
                  (if (eq (u16 3) (identifier "dsum1_fst_63"))
                    (let-pair "dsum2_fst_123" "dsum2_snd_124"
                      (let "dsum1_86" (let-pair "du16_fst_81" "du16_snd_82" (read-u16 little-endian (identifier "dsum1_snd_64")) (make-tup (identifier "du16_fst_81") (identifier "du16_snd_82")))
                        (let-pair "dsum1_fst_87" "dsum1_snd_88" (identifier "dsum1_86")
                          (if (eq (u16 0) (identifier "dsum1_fst_87")) 
                            (make-tup (construct "[Notification Void | Manual STRING | Timeout STRING]" 0 (nop)) (identifier "dsum1_snd_88"))
                            (if (eq (u16 1) (identifier "dsum1_fst_87"))
                              (let "dstring1_110"
                                (let "leb_ref_104" (make-vec (u32 0))
                                  (let "shft_ref_105" (make-vec (u8 0))
                                    (let "p_ref_106" (make-vec (identifier "dsum1_snd_88"))
                                      (seq
                                        (while
                                          (let "leb128_107" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_106")))
                                            (let-pair "leb128_fst_108" "leb128_snd_109" 
                                              (identifier "leb128_107")
                                              (seq (set-vec (u8 0) (identifier "p_ref_106") (identifier "leb128_snd_109"))
                                                (set-vec (u8 0) (identifier "leb_ref_104")
                                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_108") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_105"))) (unsafe-nth (u8 0) (identifier "leb_ref_104"))))
                                                (set-vec (u8 0) (identifier "shft_ref_105") (add (unsafe-nth (u8 0) (identifier "shft_ref_105")) (u8 7))) 
                                                (ge (identifier "leb128_fst_108") (u8 128))))) 
                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_104"))) (unsafe-nth (u8 0) (identifier "p_ref_106")))))))
                                (let-pair "dstring1_fst_111" "dstring1_snd_112" 
                                  (identifier "dstring1_110")
                                  (let-pair "dstring2_fst_114" "dstring2_snd_115" 
                                    (read-bytes (identifier "dstring1_snd_112") (identifier "dstring1_fst_111"))
                                    (make-tup (construct "[Notification Void | Manual STRING | Timeout STRING]" 1 (string-of-bytes (identifier "dstring2_fst_114"))) (identifier "dstring2_snd_115")))))
                              (seq (assert (eq (identifier "dsum1_fst_87") (u16 2)))
                                (let "dstring1_95"
                                  (let "leb_ref_89" (make-vec (u32 0))
                                    (let "shft_ref_90" (make-vec (u8 0))
                                      (let "p_ref_91" (make-vec (identifier "dsum1_snd_88"))
                                        (seq
                                          (while
                                            (let "leb128_92" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_91")))
                                              (let-pair "leb128_fst_93" "leb128_snd_94" 
                                                (identifier "leb128_92")
                                                (seq (set-vec (u8 0) (identifier "p_ref_91") (identifier "leb128_snd_94"))
                                                  (set-vec (u8 0) (identifier "leb_ref_89")
                                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_93") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_90"))) (unsafe-nth (u8 0) (identifier "leb_ref_89"))))
                                                  (set-vec (u8 0) (identifier "shft_ref_90") (add (unsafe-nth (u8 0) (identifier "shft_ref_90")) (u8 7))) 
                                                  (ge (identifier "leb128_fst_93") (u8 128))))) 
                                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_89"))) (unsafe-nth (u8 0) (identifier "p_ref_91")))))))
                                  (let-pair "dstring1_fst_96" "dstring1_snd_97" 
                                    (identifier "dstring1_95")
                                    (let-pair "dstring2_fst_99" "dstring2_snd_100" 
                                      (read-bytes (identifier "dstring1_snd_97") (identifier "dstring1_fst_96"))
                                      (make-tup (construct "[Notification Void | Manual STRING | Timeout STRING]" 2 (string-of-bytes (identifier "dstring2_fst_99"))) (identifier "dstring2_snd_100"))))))))))
                      (make-tup
                        (construct "[NewNotification [Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void] | Outcry (STRING; U32) | Ack STRING | Stop [Notification Void | Manual STRING | Timeout STRING] | Cancel STRING]" 3
                          (identifier "dsum2_fst_123")) (identifier "dsum2_snd_124")))
                    (seq (assert (eq (identifier "dsum1_fst_63") (u16 4)))
                      (let "dstring1_71"
                        (let "leb_ref_65" (make-vec (u32 0))
                          (let "shft_ref_66" (make-vec (u8 0))
                            (let "p_ref_67" (make-vec (identifier "dsum1_snd_64"))
                              (seq
                                (while
                                  (let "leb128_68" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_67")))
                                    (let-pair "leb128_fst_69" "leb128_snd_70" 
                                      (identifier "leb128_68")
                                      (seq (set-vec (u8 0) (identifier "p_ref_67") (identifier "leb128_snd_70"))
                                        (set-vec (u8 0) (identifier "leb_ref_65")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_69") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_66"))) (unsafe-nth (u8 0) (identifier "leb_ref_65"))))
                                        (set-vec (u8 0) (identifier "shft_ref_66") (add (unsafe-nth (u8 0) (identifier "shft_ref_66")) (u8 7))) 
                                        (ge (identifier "leb128_fst_69") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_65"))) (unsafe-nth (u8 0) (identifier "p_ref_67")))))))
                        (let-pair "dstring1_fst_72" "dstring1_snd_73" 
                          (identifier "dstring1_71")
                          (let-pair "dstring2_fst_75" "dstring2_snd_76" 
                            (read-bytes (identifier "dstring1_snd_73") (identifier "dstring1_fst_72"))
                            (make-tup
                              (construct "[NewNotification [Duplicate Void | Inhibited Void | STFU Void | StartEscalation Void] | Outcry (STRING; U32) | Ack STRING | Stop [Notification Void | Manual STRING | Timeout STRING] | Cancel STRING]" 4
                                (string-of-bytes (identifier "dstring2_fst_75"))) 
                              (identifier "dstring2_snd_76")))))))))))) 
        (make-tup (identifier "make_fst_189") (identifier "make_snd_190"))))
 */
static std::function<::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe(Pointer)> fun496 { [&fun496](Pointer p_0) {
    ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b id_497 { p_0.readU16Le() };
    ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b letpair_res_498;
    {
      auto du16_fst_57 { std::get<0>(id_497) };
      auto du16_snd_58 { std::get<1>(id_497) };
      ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b id_499 { du16_fst_57, du16_snd_58 };
      letpair_res_498 = id_499;
    }
    ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe let_res_500;
    {
      ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_498 };
      ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe letpair_res_501;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_502 { 0 };
        bool id_503 { bool(id_502 == dsum1_fst_63) };
        ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe choose_res_504;
        if (id_503) {
          ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b id_505 { dsum1_snd_64.readU16Le() };
          ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b letpair_res_506;
          {
            auto du16_fst_165 { std::get<0>(id_505) };
            auto du16_snd_166 { std::get<1>(id_505) };
            ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b id_507 { du16_fst_165, du16_snd_166 };
            letpair_res_506 = id_507;
          }
          ::dessser::gen::alerting_log::t48e6907c7f46c8193257869ca01037f6 let_res_508;
          {
            ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b dsum1_170 { letpair_res_506 };
            ::dessser::gen::alerting_log::t48e6907c7f46c8193257869ca01037f6 letpair_res_509;
            {
              auto dsum1_fst_171 { std::get<0>(dsum1_170) };
              auto dsum1_snd_172 { std::get<1>(dsum1_170) };
              uint16_t id_510 { 0 };
              bool id_511 { bool(id_510 == dsum1_fst_171) };
              ::dessser::gen::alerting_log::t48e6907c7f46c8193257869ca01037f6 choose_res_512;
              if (id_511) {
                (void)VOID;
                ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_513 { std::in_place_index<0>, VOID };
                ::dessser::gen::alerting_log::t48e6907c7f46c8193257869ca01037f6 id_514 { id_513, dsum1_snd_172 };
                choose_res_512 = id_514;
              } else {
                uint16_t id_515 { 1 };
                bool id_516 { bool(id_515 == dsum1_fst_171) };
                ::dessser::gen::alerting_log::t48e6907c7f46c8193257869ca01037f6 choose_res_517;
                if (id_516) {
                  (void)VOID;
                  ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_518 { std::in_place_index<1>, VOID };
                  ::dessser::gen::alerting_log::t48e6907c7f46c8193257869ca01037f6 id_519 { id_518, dsum1_snd_172 };
                  choose_res_517 = id_519;
                } else {
                  uint16_t id_520 { 2 };
                  bool id_521 { bool(id_520 == dsum1_fst_171) };
                  ::dessser::gen::alerting_log::t48e6907c7f46c8193257869ca01037f6 choose_res_522;
                  if (id_521) {
                    (void)VOID;
                    ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_523 { std::in_place_index<2>, VOID };
                    ::dessser::gen::alerting_log::t48e6907c7f46c8193257869ca01037f6 id_524 { id_523, dsum1_snd_172 };
                    choose_res_522 = id_524;
                  } else {
                    uint16_t id_525 { 3 };
                    bool id_526 { bool(dsum1_fst_171 == id_525) };
                    Void id_527 { ((void)(assert(id_526)), VOID) };
                    (void)id_527;
                    (void)VOID;
                    ::dessser::gen::alerting_log::t89816cbdea496c3fdf253c2ff7eb9816 id_528 { std::in_place_index<3>, VOID };
                    ::dessser::gen::alerting_log::t48e6907c7f46c8193257869ca01037f6 id_529 { id_528, dsum1_snd_172 };
                    choose_res_522 = id_529;
                  }
                  choose_res_517 = choose_res_522;
                }
                choose_res_512 = choose_res_517;
              }
              letpair_res_509 = choose_res_512;
            }
            let_res_508 = letpair_res_509;
          }
          ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe letpair_res_530;
          {
            auto dsum2_fst_186 { std::get<0>(let_res_508) };
            auto dsum2_snd_187 { std::get<1>(let_res_508) };
            std::shared_ptr<::dessser::gen::alerting_log::t>  id_531 { std::make_shared<::dessser::gen::alerting_log::t>(std::in_place_index<0>, dsum2_fst_186) };
            ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe id_532 { id_531, dsum2_snd_187 };
            letpair_res_530 = id_532;
          }
          choose_res_504 = letpair_res_530;
        } else {
          uint16_t id_533 { 1 };
          bool id_534 { bool(id_533 == dsum1_fst_63) };
          ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe choose_res_535;
          if (id_534) {
            uint32_t id_536 { 0U };
            Vec<1, uint32_t> id_537 {  id_536  };
            ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_538;
            {
              Vec<1, uint32_t> leb_ref_140 { id_537 };
              uint8_t id_539 { 0 };
              Vec<1, uint8_t> id_540 {  id_539  };
              ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_541;
              {
                Vec<1, uint8_t> shft_ref_141 { id_540 };
                Vec<1, Pointer> id_542 {  dsum1_snd_64  };
                ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_543;
                {
                  Vec<1, Pointer> p_ref_142 { id_542 };
                  bool while_flag_544 { true };
                  do {
                    uint8_t id_545 { 0 };
                    Pointer id_546 { p_ref_142[id_545] };
                    ::dessser::gen::alerting_log::t1566bd611d8a2b90669c241f5e8d6ff1 id_547 { id_546.readU8() };
                    bool let_res_548;
                    {
                      ::dessser::gen::alerting_log::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_143 { id_547 };
                      bool letpair_res_549;
                      {
                        auto leb128_fst_144 { std::get<0>(leb128_143) };
                        auto leb128_snd_145 { std::get<1>(leb128_143) };
                        uint8_t id_550 { 0 };
                        Void id_551 { ((void)(p_ref_142[id_550] = leb128_snd_145), VOID) };
                        (void)id_551;
                        uint8_t id_552 { 0 };
                        uint8_t id_553 { 127 };
                        uint8_t id_554 { uint8_t(leb128_fst_144 & id_553) };
                        uint32_t id_555 { uint32_t(id_554) };
                        uint8_t id_556 { 0 };
                        uint8_t id_557 { shft_ref_141[id_556] };
                        uint32_t id_558 { uint32_t(id_555 << id_557) };
                        uint8_t id_559 { 0 };
                        uint32_t id_560 { leb_ref_140[id_559] };
                        uint32_t id_561 { uint32_t(id_558 | id_560) };
                        Void id_562 { ((void)(leb_ref_140[id_552] = id_561), VOID) };
                        (void)id_562;
                        uint8_t id_563 { 0 };
                        uint8_t id_564 { 0 };
                        uint8_t id_565 { shft_ref_141[id_564] };
                        uint8_t id_566 { 7 };
                        uint8_t id_567 { uint8_t(id_565 + id_566) };
                        Void id_568 { ((void)(shft_ref_141[id_563] = id_567), VOID) };
                        (void)id_568;
                        uint8_t id_569 { 128 };
                        bool id_570 { bool(leb128_fst_144 >= id_569) };
                        letpair_res_549 = id_570;
                      }
                      let_res_548 = letpair_res_549;
                    }
                    while_flag_544 = let_res_548;
                    if (while_flag_544) {
                      (void)VOID;
                    }
                  } while (while_flag_544);
                  (void)VOID;
                  uint8_t id_571 { 0 };
                  uint32_t id_572 { leb_ref_140[id_571] };
                  Size id_573 { Size(id_572) };
                  uint8_t id_574 { 0 };
                  Pointer id_575 { p_ref_142[id_574] };
                  ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 id_576 { id_573, id_575 };
                  let_res_543 = id_576;
                }
                let_res_541 = let_res_543;
              }
              let_res_538 = let_res_541;
            }
            ::dessser::gen::alerting_log::t3fd8221434e489b54b5c4356ebff5005 let_res_577;
            {
              ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 dstring1_146 { let_res_538 };
              ::dessser::gen::alerting_log::t3fd8221434e489b54b5c4356ebff5005 letpair_res_578;
              {
                auto dstring1_fst_147 { std::get<0>(dstring1_146) };
                auto dstring1_snd_148 { std::get<1>(dstring1_146) };
                ::dessser::gen::alerting_log::t5887709cc43c8c8e24d28211e8c970a2 id_579 { dstring1_snd_148.readBytes(dstring1_fst_147) };
                ::dessser::gen::alerting_log::t3fd8221434e489b54b5c4356ebff5005 letpair_res_580;
                {
                  auto dstring2_fst_150 { std::get<0>(id_579) };
                  auto dstring2_snd_151 { std::get<1>(id_579) };
                  std::string id_581 { dstring2_fst_150.toString() };
                  ::dessser::gen::alerting_log::t3fd8221434e489b54b5c4356ebff5005 id_582 { id_581, dstring2_snd_151 };
                  letpair_res_580 = id_582;
                }
                letpair_res_578 = letpair_res_580;
              }
              let_res_577 = letpair_res_578;
            }
            ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe let_res_583;
            {
              ::dessser::gen::alerting_log::t3fd8221434e489b54b5c4356ebff5005 dtup_152 { let_res_577 };
              ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe letpair_res_584;
              {
                auto dtup_fst_153 { std::get<0>(dtup_152) };
                auto dtup_snd_154 { std::get<1>(dtup_152) };
                ::dessser::gen::alerting_log::t883c6ffea47c0d7b950fe35881e3d737 id_585 { dtup_snd_154.readU32Le() };
                ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe letpair_res_586;
                {
                  auto du32_fst_156 { std::get<0>(id_585) };
                  auto du32_snd_157 { std::get<1>(id_585) };
                  ::dessser::gen::alerting_log::t634cf874353f100ca9a3d84e2b6c3c4b id_587 { dtup_fst_153, du32_fst_156 };
                  std::shared_ptr<::dessser::gen::alerting_log::t>  id_588 { std::make_shared<::dessser::gen::alerting_log::t>(std::in_place_index<1>, id_587) };
                  ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe id_589 { id_588, du32_snd_157 };
                  letpair_res_586 = id_589;
                }
                letpair_res_584 = letpair_res_586;
              }
              let_res_583 = letpair_res_584;
            }
            choose_res_535 = let_res_583;
          } else {
            uint16_t id_590 { 2 };
            bool id_591 { bool(id_590 == dsum1_fst_63) };
            ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe choose_res_592;
            if (id_591) {
              uint32_t id_593 { 0U };
              Vec<1, uint32_t> id_594 {  id_593  };
              ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_595;
              {
                Vec<1, uint32_t> leb_ref_125 { id_594 };
                uint8_t id_596 { 0 };
                Vec<1, uint8_t> id_597 {  id_596  };
                ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_598;
                {
                  Vec<1, uint8_t> shft_ref_126 { id_597 };
                  Vec<1, Pointer> id_599 {  dsum1_snd_64  };
                  ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_600;
                  {
                    Vec<1, Pointer> p_ref_127 { id_599 };
                    bool while_flag_601 { true };
                    do {
                      uint8_t id_602 { 0 };
                      Pointer id_603 { p_ref_127[id_602] };
                      ::dessser::gen::alerting_log::t1566bd611d8a2b90669c241f5e8d6ff1 id_604 { id_603.readU8() };
                      bool let_res_605;
                      {
                        ::dessser::gen::alerting_log::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_128 { id_604 };
                        bool letpair_res_606;
                        {
                          auto leb128_fst_129 { std::get<0>(leb128_128) };
                          auto leb128_snd_130 { std::get<1>(leb128_128) };
                          uint8_t id_607 { 0 };
                          Void id_608 { ((void)(p_ref_127[id_607] = leb128_snd_130), VOID) };
                          (void)id_608;
                          uint8_t id_609 { 0 };
                          uint8_t id_610 { 127 };
                          uint8_t id_611 { uint8_t(leb128_fst_129 & id_610) };
                          uint32_t id_612 { uint32_t(id_611) };
                          uint8_t id_613 { 0 };
                          uint8_t id_614 { shft_ref_126[id_613] };
                          uint32_t id_615 { uint32_t(id_612 << id_614) };
                          uint8_t id_616 { 0 };
                          uint32_t id_617 { leb_ref_125[id_616] };
                          uint32_t id_618 { uint32_t(id_615 | id_617) };
                          Void id_619 { ((void)(leb_ref_125[id_609] = id_618), VOID) };
                          (void)id_619;
                          uint8_t id_620 { 0 };
                          uint8_t id_621 { 0 };
                          uint8_t id_622 { shft_ref_126[id_621] };
                          uint8_t id_623 { 7 };
                          uint8_t id_624 { uint8_t(id_622 + id_623) };
                          Void id_625 { ((void)(shft_ref_126[id_620] = id_624), VOID) };
                          (void)id_625;
                          uint8_t id_626 { 128 };
                          bool id_627 { bool(leb128_fst_129 >= id_626) };
                          letpair_res_606 = id_627;
                        }
                        let_res_605 = letpair_res_606;
                      }
                      while_flag_601 = let_res_605;
                      if (while_flag_601) {
                        (void)VOID;
                      }
                    } while (while_flag_601);
                    (void)VOID;
                    uint8_t id_628 { 0 };
                    uint32_t id_629 { leb_ref_125[id_628] };
                    Size id_630 { Size(id_629) };
                    uint8_t id_631 { 0 };
                    Pointer id_632 { p_ref_127[id_631] };
                    ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 id_633 { id_630, id_632 };
                    let_res_600 = id_633;
                  }
                  let_res_598 = let_res_600;
                }
                let_res_595 = let_res_598;
              }
              ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe let_res_634;
              {
                ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 dstring1_131 { let_res_595 };
                ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe letpair_res_635;
                {
                  auto dstring1_fst_132 { std::get<0>(dstring1_131) };
                  auto dstring1_snd_133 { std::get<1>(dstring1_131) };
                  ::dessser::gen::alerting_log::t5887709cc43c8c8e24d28211e8c970a2 id_636 { dstring1_snd_133.readBytes(dstring1_fst_132) };
                  ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe letpair_res_637;
                  {
                    auto dstring2_fst_135 { std::get<0>(id_636) };
                    auto dstring2_snd_136 { std::get<1>(id_636) };
                    std::string id_638 { dstring2_fst_135.toString() };
                    std::shared_ptr<::dessser::gen::alerting_log::t>  id_639 { std::make_shared<::dessser::gen::alerting_log::t>(std::in_place_index<2>, id_638) };
                    ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe id_640 { id_639, dstring2_snd_136 };
                    letpair_res_637 = id_640;
                  }
                  letpair_res_635 = letpair_res_637;
                }
                let_res_634 = letpair_res_635;
              }
              choose_res_592 = let_res_634;
            } else {
              uint16_t id_641 { 3 };
              bool id_642 { bool(id_641 == dsum1_fst_63) };
              ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe choose_res_643;
              if (id_642) {
                ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b id_644 { dsum1_snd_64.readU16Le() };
                ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b letpair_res_645;
                {
                  auto du16_fst_81 { std::get<0>(id_644) };
                  auto du16_snd_82 { std::get<1>(id_644) };
                  ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b id_646 { du16_fst_81, du16_snd_82 };
                  letpair_res_645 = id_646;
                }
                ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 let_res_647;
                {
                  ::dessser::gen::alerting_log::t7609d344c1ba69d0f80fec236d4c216b dsum1_86 { letpair_res_645 };
                  ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 letpair_res_648;
                  {
                    auto dsum1_fst_87 { std::get<0>(dsum1_86) };
                    auto dsum1_snd_88 { std::get<1>(dsum1_86) };
                    uint16_t id_649 { 0 };
                    bool id_650 { bool(id_649 == dsum1_fst_87) };
                    ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 choose_res_651;
                    if (id_650) {
                      (void)VOID;
                      ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_652 { std::in_place_index<0>, VOID };
                      ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 id_653 { id_652, dsum1_snd_88 };
                      choose_res_651 = id_653;
                    } else {
                      uint16_t id_654 { 1 };
                      bool id_655 { bool(id_654 == dsum1_fst_87) };
                      ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 choose_res_656;
                      if (id_655) {
                        uint32_t id_657 { 0U };
                        Vec<1, uint32_t> id_658 {  id_657  };
                        ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_659;
                        {
                          Vec<1, uint32_t> leb_ref_104 { id_658 };
                          uint8_t id_660 { 0 };
                          Vec<1, uint8_t> id_661 {  id_660  };
                          ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_662;
                          {
                            Vec<1, uint8_t> shft_ref_105 { id_661 };
                            Vec<1, Pointer> id_663 {  dsum1_snd_88  };
                            ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_664;
                            {
                              Vec<1, Pointer> p_ref_106 { id_663 };
                              bool while_flag_665 { true };
                              do {
                                uint8_t id_666 { 0 };
                                Pointer id_667 { p_ref_106[id_666] };
                                ::dessser::gen::alerting_log::t1566bd611d8a2b90669c241f5e8d6ff1 id_668 { id_667.readU8() };
                                bool let_res_669;
                                {
                                  ::dessser::gen::alerting_log::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_107 { id_668 };
                                  bool letpair_res_670;
                                  {
                                    auto leb128_fst_108 { std::get<0>(leb128_107) };
                                    auto leb128_snd_109 { std::get<1>(leb128_107) };
                                    uint8_t id_671 { 0 };
                                    Void id_672 { ((void)(p_ref_106[id_671] = leb128_snd_109), VOID) };
                                    (void)id_672;
                                    uint8_t id_673 { 0 };
                                    uint8_t id_674 { 127 };
                                    uint8_t id_675 { uint8_t(leb128_fst_108 & id_674) };
                                    uint32_t id_676 { uint32_t(id_675) };
                                    uint8_t id_677 { 0 };
                                    uint8_t id_678 { shft_ref_105[id_677] };
                                    uint32_t id_679 { uint32_t(id_676 << id_678) };
                                    uint8_t id_680 { 0 };
                                    uint32_t id_681 { leb_ref_104[id_680] };
                                    uint32_t id_682 { uint32_t(id_679 | id_681) };
                                    Void id_683 { ((void)(leb_ref_104[id_673] = id_682), VOID) };
                                    (void)id_683;
                                    uint8_t id_684 { 0 };
                                    uint8_t id_685 { 0 };
                                    uint8_t id_686 { shft_ref_105[id_685] };
                                    uint8_t id_687 { 7 };
                                    uint8_t id_688 { uint8_t(id_686 + id_687) };
                                    Void id_689 { ((void)(shft_ref_105[id_684] = id_688), VOID) };
                                    (void)id_689;
                                    uint8_t id_690 { 128 };
                                    bool id_691 { bool(leb128_fst_108 >= id_690) };
                                    letpair_res_670 = id_691;
                                  }
                                  let_res_669 = letpair_res_670;
                                }
                                while_flag_665 = let_res_669;
                                if (while_flag_665) {
                                  (void)VOID;
                                }
                              } while (while_flag_665);
                              (void)VOID;
                              uint8_t id_692 { 0 };
                              uint32_t id_693 { leb_ref_104[id_692] };
                              Size id_694 { Size(id_693) };
                              uint8_t id_695 { 0 };
                              Pointer id_696 { p_ref_106[id_695] };
                              ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 id_697 { id_694, id_696 };
                              let_res_664 = id_697;
                            }
                            let_res_662 = let_res_664;
                          }
                          let_res_659 = let_res_662;
                        }
                        ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 let_res_698;
                        {
                          ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 dstring1_110 { let_res_659 };
                          ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 letpair_res_699;
                          {
                            auto dstring1_fst_111 { std::get<0>(dstring1_110) };
                            auto dstring1_snd_112 { std::get<1>(dstring1_110) };
                            ::dessser::gen::alerting_log::t5887709cc43c8c8e24d28211e8c970a2 id_700 { dstring1_snd_112.readBytes(dstring1_fst_111) };
                            ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 letpair_res_701;
                            {
                              auto dstring2_fst_114 { std::get<0>(id_700) };
                              auto dstring2_snd_115 { std::get<1>(id_700) };
                              std::string id_702 { dstring2_fst_114.toString() };
                              ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_703 { std::in_place_index<1>, id_702 };
                              ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 id_704 { id_703, dstring2_snd_115 };
                              letpair_res_701 = id_704;
                            }
                            letpair_res_699 = letpair_res_701;
                          }
                          let_res_698 = letpair_res_699;
                        }
                        choose_res_656 = let_res_698;
                      } else {
                        uint16_t id_705 { 2 };
                        bool id_706 { bool(dsum1_fst_87 == id_705) };
                        Void id_707 { ((void)(assert(id_706)), VOID) };
                        (void)id_707;
                        uint32_t id_708 { 0U };
                        Vec<1, uint32_t> id_709 {  id_708  };
                        ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_710;
                        {
                          Vec<1, uint32_t> leb_ref_89 { id_709 };
                          uint8_t id_711 { 0 };
                          Vec<1, uint8_t> id_712 {  id_711  };
                          ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_713;
                          {
                            Vec<1, uint8_t> shft_ref_90 { id_712 };
                            Vec<1, Pointer> id_714 {  dsum1_snd_88  };
                            ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_715;
                            {
                              Vec<1, Pointer> p_ref_91 { id_714 };
                              bool while_flag_716 { true };
                              do {
                                uint8_t id_717 { 0 };
                                Pointer id_718 { p_ref_91[id_717] };
                                ::dessser::gen::alerting_log::t1566bd611d8a2b90669c241f5e8d6ff1 id_719 { id_718.readU8() };
                                bool let_res_720;
                                {
                                  ::dessser::gen::alerting_log::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_92 { id_719 };
                                  bool letpair_res_721;
                                  {
                                    auto leb128_fst_93 { std::get<0>(leb128_92) };
                                    auto leb128_snd_94 { std::get<1>(leb128_92) };
                                    uint8_t id_722 { 0 };
                                    Void id_723 { ((void)(p_ref_91[id_722] = leb128_snd_94), VOID) };
                                    (void)id_723;
                                    uint8_t id_724 { 0 };
                                    uint8_t id_725 { 127 };
                                    uint8_t id_726 { uint8_t(leb128_fst_93 & id_725) };
                                    uint32_t id_727 { uint32_t(id_726) };
                                    uint8_t id_728 { 0 };
                                    uint8_t id_729 { shft_ref_90[id_728] };
                                    uint32_t id_730 { uint32_t(id_727 << id_729) };
                                    uint8_t id_731 { 0 };
                                    uint32_t id_732 { leb_ref_89[id_731] };
                                    uint32_t id_733 { uint32_t(id_730 | id_732) };
                                    Void id_734 { ((void)(leb_ref_89[id_724] = id_733), VOID) };
                                    (void)id_734;
                                    uint8_t id_735 { 0 };
                                    uint8_t id_736 { 0 };
                                    uint8_t id_737 { shft_ref_90[id_736] };
                                    uint8_t id_738 { 7 };
                                    uint8_t id_739 { uint8_t(id_737 + id_738) };
                                    Void id_740 { ((void)(shft_ref_90[id_735] = id_739), VOID) };
                                    (void)id_740;
                                    uint8_t id_741 { 128 };
                                    bool id_742 { bool(leb128_fst_93 >= id_741) };
                                    letpair_res_721 = id_742;
                                  }
                                  let_res_720 = letpair_res_721;
                                }
                                while_flag_716 = let_res_720;
                                if (while_flag_716) {
                                  (void)VOID;
                                }
                              } while (while_flag_716);
                              (void)VOID;
                              uint8_t id_743 { 0 };
                              uint32_t id_744 { leb_ref_89[id_743] };
                              Size id_745 { Size(id_744) };
                              uint8_t id_746 { 0 };
                              Pointer id_747 { p_ref_91[id_746] };
                              ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 id_748 { id_745, id_747 };
                              let_res_715 = id_748;
                            }
                            let_res_713 = let_res_715;
                          }
                          let_res_710 = let_res_713;
                        }
                        ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 let_res_749;
                        {
                          ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 dstring1_95 { let_res_710 };
                          ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 letpair_res_750;
                          {
                            auto dstring1_fst_96 { std::get<0>(dstring1_95) };
                            auto dstring1_snd_97 { std::get<1>(dstring1_95) };
                            ::dessser::gen::alerting_log::t5887709cc43c8c8e24d28211e8c970a2 id_751 { dstring1_snd_97.readBytes(dstring1_fst_96) };
                            ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 letpair_res_752;
                            {
                              auto dstring2_fst_99 { std::get<0>(id_751) };
                              auto dstring2_snd_100 { std::get<1>(id_751) };
                              std::string id_753 { dstring2_fst_99.toString() };
                              ::dessser::gen::alerting_log::tc13ab978611f6f6c6f0eb7ff36eb72f4 id_754 { std::in_place_index<2>, id_753 };
                              ::dessser::gen::alerting_log::t0aabe0750109c9aec473d52493a4b4a8 id_755 { id_754, dstring2_snd_100 };
                              letpair_res_752 = id_755;
                            }
                            letpair_res_750 = letpair_res_752;
                          }
                          let_res_749 = letpair_res_750;
                        }
                        choose_res_656 = let_res_749;
                      }
                      choose_res_651 = choose_res_656;
                    }
                    letpair_res_648 = choose_res_651;
                  }
                  let_res_647 = letpair_res_648;
                }
                ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe letpair_res_756;
                {
                  auto dsum2_fst_123 { std::get<0>(let_res_647) };
                  auto dsum2_snd_124 { std::get<1>(let_res_647) };
                  std::shared_ptr<::dessser::gen::alerting_log::t>  id_757 { std::make_shared<::dessser::gen::alerting_log::t>(std::in_place_index<3>, dsum2_fst_123) };
                  ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe id_758 { id_757, dsum2_snd_124 };
                  letpair_res_756 = id_758;
                }
                choose_res_643 = letpair_res_756;
              } else {
                uint16_t id_759 { 4 };
                bool id_760 { bool(dsum1_fst_63 == id_759) };
                Void id_761 { ((void)(assert(id_760)), VOID) };
                (void)id_761;
                uint32_t id_762 { 0U };
                Vec<1, uint32_t> id_763 {  id_762  };
                ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_764;
                {
                  Vec<1, uint32_t> leb_ref_65 { id_763 };
                  uint8_t id_765 { 0 };
                  Vec<1, uint8_t> id_766 {  id_765  };
                  ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_767;
                  {
                    Vec<1, uint8_t> shft_ref_66 { id_766 };
                    Vec<1, Pointer> id_768 {  dsum1_snd_64  };
                    ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 let_res_769;
                    {
                      Vec<1, Pointer> p_ref_67 { id_768 };
                      bool while_flag_770 { true };
                      do {
                        uint8_t id_771 { 0 };
                        Pointer id_772 { p_ref_67[id_771] };
                        ::dessser::gen::alerting_log::t1566bd611d8a2b90669c241f5e8d6ff1 id_773 { id_772.readU8() };
                        bool let_res_774;
                        {
                          ::dessser::gen::alerting_log::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_68 { id_773 };
                          bool letpair_res_775;
                          {
                            auto leb128_fst_69 { std::get<0>(leb128_68) };
                            auto leb128_snd_70 { std::get<1>(leb128_68) };
                            uint8_t id_776 { 0 };
                            Void id_777 { ((void)(p_ref_67[id_776] = leb128_snd_70), VOID) };
                            (void)id_777;
                            uint8_t id_778 { 0 };
                            uint8_t id_779 { 127 };
                            uint8_t id_780 { uint8_t(leb128_fst_69 & id_779) };
                            uint32_t id_781 { uint32_t(id_780) };
                            uint8_t id_782 { 0 };
                            uint8_t id_783 { shft_ref_66[id_782] };
                            uint32_t id_784 { uint32_t(id_781 << id_783) };
                            uint8_t id_785 { 0 };
                            uint32_t id_786 { leb_ref_65[id_785] };
                            uint32_t id_787 { uint32_t(id_784 | id_786) };
                            Void id_788 { ((void)(leb_ref_65[id_778] = id_787), VOID) };
                            (void)id_788;
                            uint8_t id_789 { 0 };
                            uint8_t id_790 { 0 };
                            uint8_t id_791 { shft_ref_66[id_790] };
                            uint8_t id_792 { 7 };
                            uint8_t id_793 { uint8_t(id_791 + id_792) };
                            Void id_794 { ((void)(shft_ref_66[id_789] = id_793), VOID) };
                            (void)id_794;
                            uint8_t id_795 { 128 };
                            bool id_796 { bool(leb128_fst_69 >= id_795) };
                            letpair_res_775 = id_796;
                          }
                          let_res_774 = letpair_res_775;
                        }
                        while_flag_770 = let_res_774;
                        if (while_flag_770) {
                          (void)VOID;
                        }
                      } while (while_flag_770);
                      (void)VOID;
                      uint8_t id_797 { 0 };
                      uint32_t id_798 { leb_ref_65[id_797] };
                      Size id_799 { Size(id_798) };
                      uint8_t id_800 { 0 };
                      Pointer id_801 { p_ref_67[id_800] };
                      ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 id_802 { id_799, id_801 };
                      let_res_769 = id_802;
                    }
                    let_res_767 = let_res_769;
                  }
                  let_res_764 = let_res_767;
                }
                ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe let_res_803;
                {
                  ::dessser::gen::alerting_log::t044960e524fd6ec1bfc06410ce526709 dstring1_71 { let_res_764 };
                  ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe letpair_res_804;
                  {
                    auto dstring1_fst_72 { std::get<0>(dstring1_71) };
                    auto dstring1_snd_73 { std::get<1>(dstring1_71) };
                    ::dessser::gen::alerting_log::t5887709cc43c8c8e24d28211e8c970a2 id_805 { dstring1_snd_73.readBytes(dstring1_fst_72) };
                    ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe letpair_res_806;
                    {
                      auto dstring2_fst_75 { std::get<0>(id_805) };
                      auto dstring2_snd_76 { std::get<1>(id_805) };
                      std::string id_807 { dstring2_fst_75.toString() };
                      std::shared_ptr<::dessser::gen::alerting_log::t>  id_808 { std::make_shared<::dessser::gen::alerting_log::t>(std::in_place_index<4>, id_807) };
                      ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe id_809 { id_808, dstring2_snd_76 };
                      letpair_res_806 = id_809;
                    }
                    letpair_res_804 = letpair_res_806;
                  }
                  let_res_803 = letpair_res_804;
                }
                choose_res_643 = let_res_803;
              }
              choose_res_592 = choose_res_643;
            }
            choose_res_535 = choose_res_592;
          }
          choose_res_504 = choose_res_535;
        }
        letpair_res_501 = choose_res_504;
      }
      let_res_500 = letpair_res_501;
    }
    ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe letpair_res_810;
    {
      auto make_fst_189 { std::get<0>(let_res_500) };
      auto make_snd_190 { std::get<1>(let_res_500) };
      ::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe id_811 { make_fst_189, make_snd_190 };
      letpair_res_810 = id_811;
    }
    return letpair_res_810;
  }
   };
  return fun496;
}
std::function<::dessser::gen::alerting_log::t6b074172af0a13530a735ecaa0f9d4fe(Pointer)> of_row_binary(of_row_binary_init());

typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
