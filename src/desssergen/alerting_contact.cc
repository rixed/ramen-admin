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


namespace dessser::gen::alerting_contact {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct tbe8824b6bd92590dbb49ce7f29575869 {
  std::string create;
  std::string file;
  std::string insert;
  tbe8824b6bd92590dbb49ce7f29575869(std::string create_, std::string file_, std::string insert_) : create(create_), file(file_), insert(insert_) {}
  tbe8824b6bd92590dbb49ce7f29575869() = default;
};
typedef std::tuple<
  std::string,
  std::string
> t8961925d22ebc35140986110e41bc2a4;

struct t34ef5cb3b50881faab30fa24cda711db {
  Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> options;
  uint16_t partition;
  std::string text;
  std::string topic;
  t34ef5cb3b50881faab30fa24cda711db(Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> options_, uint16_t partition_, std::string text_, std::string topic_) : options(options_), partition(partition_), text(text_), topic(topic_) {}
  t34ef5cb3b50881faab30fa24cda711db() = default;
};
struct tf87a9e0f02ad9bcade189d770d3129cc : public std::variant<
  Void, // Ignore
  std::string, // Exec
  std::string, // SysLog
  ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869, // Sqlite
  ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db // Kafka
> { using variant::variant; };

struct t {
  double timeout;
  ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc via;
  t(double timeout_, ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc via_) : timeout(timeout_), via(via_) {}
  t() = default;
};
typedef std::tuple<
  ::dessser::gen::alerting_contact::t*,
  Pointer
> t6895345151933b08a9380e7a927036c0;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc,
  Pointer
> tbcf02c42d3bdd7dbddc6fe2b9f8f77e0;

typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

typedef std::tuple<
  std::string,
  Pointer
> tef94b55d8809251f13165d9a05bd9d0e;

typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

typedef std::tuple<
  Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4>,
  Pointer
> t07df82f20f511d57322ca4fc039f6078;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{via: [Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]; timeout: FLOAT}" "Ptr")
      (let "srec_dst_328"
        (let "ssum_dst_297" (write-u16 little-endian (param 1) (label-of (get-field "via" (param 0))))
          (if (eq (u16 0) (label-of (get-field "via" (param 0)))) (identifier "ssum_dst_297")
            (if (eq (u16 1) (label-of (get-field "via" (param 0))))
              (write-bytes
                (let "leb128_sz_326" (make-vec (string-length (get-alt "Exec" (get-field "via" (param 0)))))
                  (let "leb128_ptr_327" (make-vec (identifier "ssum_dst_297"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_327")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_327"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_326"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_326"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_326"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_326") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_326")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_326")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_327"))))) 
                (bytes-of-string (get-alt "Exec" (get-field "via" (param 0)))))
              (if (eq (u16 2) (label-of (get-field "via" (param 0))))
                (write-bytes
                  (let "leb128_sz_324" (make-vec (string-length (get-alt "SysLog" (get-field "via" (param 0)))))
                    (let "leb128_ptr_325" (make-vec (identifier "ssum_dst_297"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_325")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_325"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_324"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_324"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_324"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_324") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_324")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_324")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_325"))))) 
                  (bytes-of-string (get-alt "SysLog" (get-field "via" (param 0)))))
                (if (eq (u16 3) (label-of (get-field "via" (param 0))))
                  (let "srec_dst_321"
                    (let "srec_dst_318"
                      (write-bytes
                        (let "leb128_sz_316" (make-vec (string-length (get-field "file" (get-alt "Sqlite" (get-field "via" (param 0))))))
                          (let "leb128_ptr_317" (make-vec (identifier "ssum_dst_297"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_317")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_317"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_316"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_316"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_316"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_316") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_316")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_316")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_317"))))) 
                        (bytes-of-string (get-field "file" (get-alt "Sqlite" (get-field "via" (param 0))))))
                      (write-bytes
                        (let "leb128_sz_319" (make-vec (string-length (get-field "insert" (get-alt "Sqlite" (get-field "via" (param 0))))))
                          (let "leb128_ptr_320" (make-vec (identifier "srec_dst_318"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_320")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_320"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_319"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_319"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_319"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_319") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_319")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_319")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_320"))))) 
                        (bytes-of-string (get-field "insert" (get-alt "Sqlite" (get-field "via" (param 0)))))))
                    (write-bytes
                      (let "leb128_sz_322" (make-vec (string-length (get-field "create" (get-alt "Sqlite" (get-field "via" (param 0))))))
                        (let "leb128_ptr_323" (make-vec (identifier "srec_dst_321"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_323")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_323"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_322"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_322"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_322"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_322") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_322")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_322")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_323"))))) 
                      (bytes-of-string (get-field "create" (get-alt "Sqlite" (get-field "via" (param 0)))))))
                  (seq (assert (eq (label-of (get-field "via" (param 0))) (u16 4)))
                    (let "srec_dst_313"
                      (let "srec_dst_312"
                        (let "srec_dst_309"
                          (let "dst_ref_300"
                            (make-vec
                              (let "leb128_sz_298" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (get-field "via" (param 0))))))
                                (let "leb128_ptr_299" (make-vec (identifier "ssum_dst_297"))
                                  (seq
                                    (while
                                      (seq
                                        (set-vec (u8 0) (identifier "leb128_ptr_299")
                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_299"))
                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_298"))) 
                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_298"))) 
                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_298"))) (u8 128)))))
                                        (set-vec (u8 0) (identifier "leb128_sz_298") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_298")) (u8 7))) 
                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_298")) (u32 0))) 
                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_299"))))))
                            (let "n_ref_301" (make-vec (i32 0))
                              (seq
                                (for-each "x_302" (get-field "options" (get-alt "Kafka" (get-field "via" (param 0))))
                                  (seq
                                    (set-vec (u8 0) (identifier "dst_ref_300")
                                      (let "stup_dst_306"
                                        (let "stup_dst_303" (unsafe-nth (u8 0) (identifier "dst_ref_300"))
                                          (write-bytes
                                            (let "leb128_sz_304" (make-vec (string-length (get-item 0 (identifier "x_302"))))
                                              (let "leb128_ptr_305" (make-vec (identifier "stup_dst_303"))
                                                (seq
                                                  (while
                                                    (seq
                                                      (set-vec (u8 0) 
                                                        (identifier "leb128_ptr_305")
                                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_305"))
                                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_304"))) 
                                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_304"))) 
                                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_304"))) (u8 128)))))
                                                      (set-vec (u8 0) (identifier "leb128_sz_304") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_304")) (u8 7)))
                                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_304")) (u32 0))) 
                                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_305"))))) 
                                            (bytes-of-string (get-item 0 (identifier "x_302")))))
                                        (write-bytes
                                          (let "leb128_sz_307" (make-vec (string-length (get-item 1 (identifier "x_302"))))
                                            (let "leb128_ptr_308" (make-vec (identifier "stup_dst_306"))
                                              (seq
                                                (while
                                                  (seq
                                                    (set-vec (u8 0) (identifier "leb128_ptr_308")
                                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_308"))
                                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_307"))) 
                                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_307"))) 
                                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_307"))) (u8 128)))))
                                                    (set-vec (u8 0) (identifier "leb128_sz_307") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_307")) (u8 7)))
                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_307")) (u32 0))) 
                                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_308"))))) 
                                          (bytes-of-string (get-item 1 (identifier "x_302")))))) 
                                    (set-vec (u8 0) (identifier "n_ref_301") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_301")))))) 
                                (unsafe-nth (u8 0) (identifier "dst_ref_300")))))
                          (write-bytes
                            (let "leb128_sz_310" (make-vec (string-length (get-field "topic" (get-alt "Kafka" (get-field "via" (param 0))))))
                              (let "leb128_ptr_311" (make-vec (identifier "srec_dst_309"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_311")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_311"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_310"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_310"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_310"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_310") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_310")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_310")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_311"))))) 
                            (bytes-of-string (get-field "topic" (get-alt "Kafka" (get-field "via" (param 0)))))))
                        (write-u16 little-endian (identifier "srec_dst_312") (get-field "partition" (get-alt "Kafka" (get-field "via" (param 0))))))
                      (write-bytes
                        (let "leb128_sz_314" (make-vec (string-length (get-field "text" (get-alt "Kafka" (get-field "via" (param 0))))))
                          (let "leb128_ptr_315" (make-vec (identifier "srec_dst_313"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_315")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_315"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_314"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_314"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_314"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_314") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_314")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_314")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_315"))))) 
                        (bytes-of-string (get-field "text" (get-alt "Kafka" (get-field "via" (param 0))))))))))))) 
        (write-u64 little-endian (identifier "srec_dst_328") (u64-of-float (get-field "timeout" (param 0))))))
 */
static std::function<Pointer(::dessser::gen::alerting_contact::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::alerting_contact::t*,Pointer)> fun0 { [&fun0](::dessser::gen::alerting_contact::t* p_0, Pointer p_1) {
    ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_1 { (*p_0).via };
    uint16_t id_2 { uint16_t(id_1.index()) };
    Pointer id_3 { p_1.writeU16Le(id_2) };
    Pointer let_res_4;
    {
      Pointer ssum_dst_297 { id_3 };
      uint16_t id_5 { 0 };
      ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_6 { (*p_0).via };
      uint16_t id_7 { uint16_t(id_6.index()) };
      bool id_8 { bool(id_5 == id_7) };
      Pointer choose_res_9;
      if (id_8) {
        choose_res_9 = ssum_dst_297;
      } else {
        uint16_t id_10 { 1 };
        ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_11 { (*p_0).via };
        uint16_t id_12 { uint16_t(id_11.index()) };
        bool id_13 { bool(id_10 == id_12) };
        Pointer choose_res_14;
        if (id_13) {
          ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_15 { (*p_0).via };
          std::string id_16 { std::get<1 /* Exec */>(id_15) };
          uint32_t id_17 { (uint32_t)id_16.size() };
          Vec<1, uint32_t> id_18 {  id_17  };
          Pointer let_res_19;
          {
            Vec<1, uint32_t> leb128_sz_326 { id_18 };
            Vec<1, Pointer> id_20 {  ssum_dst_297  };
            Pointer let_res_21;
            {
              Vec<1, Pointer> leb128_ptr_327 { id_20 };
              bool while_flag_22 { true };
              do {
                uint8_t id_23 { 0 };
                uint8_t id_24 { 0 };
                Pointer id_25 { leb128_ptr_327[id_24] };
                uint32_t id_26 { 128U };
                uint8_t id_27 { 0 };
                uint32_t id_28 { leb128_sz_326[id_27] };
                bool id_29 { bool(id_26 > id_28) };
                uint8_t choose_res_30;
                if (id_29) {
                  uint8_t id_31 { 0 };
                  uint32_t id_32 { leb128_sz_326[id_31] };
                  uint8_t id_33 { uint8_t(id_32) };
                  choose_res_30 = id_33;
                } else {
                  uint8_t id_34 { 0 };
                  uint32_t id_35 { leb128_sz_326[id_34] };
                  uint8_t id_36 { uint8_t(id_35) };
                  uint8_t id_37 { 128 };
                  uint8_t id_38 { uint8_t(id_36 | id_37) };
                  choose_res_30 = id_38;
                }
                Pointer id_39 { id_25.writeU8(choose_res_30) };
                Void id_40 { ((void)(leb128_ptr_327[id_23] = id_39), VOID) };
                (void)id_40;
                uint8_t id_41 { 0 };
                uint8_t id_42 { 0 };
                uint32_t id_43 { leb128_sz_326[id_42] };
                uint8_t id_44 { 7 };
                uint32_t id_45 { uint32_t(id_43 >> id_44) };
                Void id_46 { ((void)(leb128_sz_326[id_41] = id_45), VOID) };
                (void)id_46;
                uint8_t id_47 { 0 };
                uint32_t id_48 { leb128_sz_326[id_47] };
                uint32_t id_49 { 0U };
                bool id_50 { bool(id_48 > id_49) };
                while_flag_22 = id_50;
                if (while_flag_22) {
                  (void)VOID;
                }
              } while (while_flag_22);
              (void)VOID;
              uint8_t id_51 { 0 };
              Pointer id_52 { leb128_ptr_327[id_51] };
              let_res_21 = id_52;
            }
            let_res_19 = let_res_21;
          }
          ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_53 { (*p_0).via };
          std::string id_54 { std::get<1 /* Exec */>(id_53) };
          Bytes id_55 { id_54 };
          Pointer id_56 { let_res_19.writeBytes(id_55) };
          choose_res_14 = id_56;
        } else {
          uint16_t id_57 { 2 };
          ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_58 { (*p_0).via };
          uint16_t id_59 { uint16_t(id_58.index()) };
          bool id_60 { bool(id_57 == id_59) };
          Pointer choose_res_61;
          if (id_60) {
            ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_62 { (*p_0).via };
            std::string id_63 { std::get<2 /* SysLog */>(id_62) };
            uint32_t id_64 { (uint32_t)id_63.size() };
            Vec<1, uint32_t> id_65 {  id_64  };
            Pointer let_res_66;
            {
              Vec<1, uint32_t> leb128_sz_324 { id_65 };
              Vec<1, Pointer> id_67 {  ssum_dst_297  };
              Pointer let_res_68;
              {
                Vec<1, Pointer> leb128_ptr_325 { id_67 };
                bool while_flag_69 { true };
                do {
                  uint8_t id_70 { 0 };
                  uint8_t id_71 { 0 };
                  Pointer id_72 { leb128_ptr_325[id_71] };
                  uint32_t id_73 { 128U };
                  uint8_t id_74 { 0 };
                  uint32_t id_75 { leb128_sz_324[id_74] };
                  bool id_76 { bool(id_73 > id_75) };
                  uint8_t choose_res_77;
                  if (id_76) {
                    uint8_t id_78 { 0 };
                    uint32_t id_79 { leb128_sz_324[id_78] };
                    uint8_t id_80 { uint8_t(id_79) };
                    choose_res_77 = id_80;
                  } else {
                    uint8_t id_81 { 0 };
                    uint32_t id_82 { leb128_sz_324[id_81] };
                    uint8_t id_83 { uint8_t(id_82) };
                    uint8_t id_84 { 128 };
                    uint8_t id_85 { uint8_t(id_83 | id_84) };
                    choose_res_77 = id_85;
                  }
                  Pointer id_86 { id_72.writeU8(choose_res_77) };
                  Void id_87 { ((void)(leb128_ptr_325[id_70] = id_86), VOID) };
                  (void)id_87;
                  uint8_t id_88 { 0 };
                  uint8_t id_89 { 0 };
                  uint32_t id_90 { leb128_sz_324[id_89] };
                  uint8_t id_91 { 7 };
                  uint32_t id_92 { uint32_t(id_90 >> id_91) };
                  Void id_93 { ((void)(leb128_sz_324[id_88] = id_92), VOID) };
                  (void)id_93;
                  uint8_t id_94 { 0 };
                  uint32_t id_95 { leb128_sz_324[id_94] };
                  uint32_t id_96 { 0U };
                  bool id_97 { bool(id_95 > id_96) };
                  while_flag_69 = id_97;
                  if (while_flag_69) {
                    (void)VOID;
                  }
                } while (while_flag_69);
                (void)VOID;
                uint8_t id_98 { 0 };
                Pointer id_99 { leb128_ptr_325[id_98] };
                let_res_68 = id_99;
              }
              let_res_66 = let_res_68;
            }
            ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_100 { (*p_0).via };
            std::string id_101 { std::get<2 /* SysLog */>(id_100) };
            Bytes id_102 { id_101 };
            Pointer id_103 { let_res_66.writeBytes(id_102) };
            choose_res_61 = id_103;
          } else {
            uint16_t id_104 { 3 };
            ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_105 { (*p_0).via };
            uint16_t id_106 { uint16_t(id_105.index()) };
            bool id_107 { bool(id_104 == id_106) };
            Pointer choose_res_108;
            if (id_107) {
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_109 { (*p_0).via };
              ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_110 { std::get<3 /* Sqlite */>(id_109) };
              std::string id_111 { id_110.file };
              uint32_t id_112 { (uint32_t)id_111.size() };
              Vec<1, uint32_t> id_113 {  id_112  };
              Pointer let_res_114;
              {
                Vec<1, uint32_t> leb128_sz_316 { id_113 };
                Vec<1, Pointer> id_115 {  ssum_dst_297  };
                Pointer let_res_116;
                {
                  Vec<1, Pointer> leb128_ptr_317 { id_115 };
                  bool while_flag_117 { true };
                  do {
                    uint8_t id_118 { 0 };
                    uint8_t id_119 { 0 };
                    Pointer id_120 { leb128_ptr_317[id_119] };
                    uint32_t id_121 { 128U };
                    uint8_t id_122 { 0 };
                    uint32_t id_123 { leb128_sz_316[id_122] };
                    bool id_124 { bool(id_121 > id_123) };
                    uint8_t choose_res_125;
                    if (id_124) {
                      uint8_t id_126 { 0 };
                      uint32_t id_127 { leb128_sz_316[id_126] };
                      uint8_t id_128 { uint8_t(id_127) };
                      choose_res_125 = id_128;
                    } else {
                      uint8_t id_129 { 0 };
                      uint32_t id_130 { leb128_sz_316[id_129] };
                      uint8_t id_131 { uint8_t(id_130) };
                      uint8_t id_132 { 128 };
                      uint8_t id_133 { uint8_t(id_131 | id_132) };
                      choose_res_125 = id_133;
                    }
                    Pointer id_134 { id_120.writeU8(choose_res_125) };
                    Void id_135 { ((void)(leb128_ptr_317[id_118] = id_134), VOID) };
                    (void)id_135;
                    uint8_t id_136 { 0 };
                    uint8_t id_137 { 0 };
                    uint32_t id_138 { leb128_sz_316[id_137] };
                    uint8_t id_139 { 7 };
                    uint32_t id_140 { uint32_t(id_138 >> id_139) };
                    Void id_141 { ((void)(leb128_sz_316[id_136] = id_140), VOID) };
                    (void)id_141;
                    uint8_t id_142 { 0 };
                    uint32_t id_143 { leb128_sz_316[id_142] };
                    uint32_t id_144 { 0U };
                    bool id_145 { bool(id_143 > id_144) };
                    while_flag_117 = id_145;
                    if (while_flag_117) {
                      (void)VOID;
                    }
                  } while (while_flag_117);
                  (void)VOID;
                  uint8_t id_146 { 0 };
                  Pointer id_147 { leb128_ptr_317[id_146] };
                  let_res_116 = id_147;
                }
                let_res_114 = let_res_116;
              }
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_148 { (*p_0).via };
              ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_149 { std::get<3 /* Sqlite */>(id_148) };
              std::string id_150 { id_149.file };
              Bytes id_151 { id_150 };
              Pointer id_152 { let_res_114.writeBytes(id_151) };
              Pointer let_res_153;
              {
                Pointer srec_dst_318 { id_152 };
                ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_154 { (*p_0).via };
                ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_155 { std::get<3 /* Sqlite */>(id_154) };
                std::string id_156 { id_155.insert };
                uint32_t id_157 { (uint32_t)id_156.size() };
                Vec<1, uint32_t> id_158 {  id_157  };
                Pointer let_res_159;
                {
                  Vec<1, uint32_t> leb128_sz_319 { id_158 };
                  Vec<1, Pointer> id_160 {  srec_dst_318  };
                  Pointer let_res_161;
                  {
                    Vec<1, Pointer> leb128_ptr_320 { id_160 };
                    bool while_flag_162 { true };
                    do {
                      uint8_t id_163 { 0 };
                      uint8_t id_164 { 0 };
                      Pointer id_165 { leb128_ptr_320[id_164] };
                      uint32_t id_166 { 128U };
                      uint8_t id_167 { 0 };
                      uint32_t id_168 { leb128_sz_319[id_167] };
                      bool id_169 { bool(id_166 > id_168) };
                      uint8_t choose_res_170;
                      if (id_169) {
                        uint8_t id_171 { 0 };
                        uint32_t id_172 { leb128_sz_319[id_171] };
                        uint8_t id_173 { uint8_t(id_172) };
                        choose_res_170 = id_173;
                      } else {
                        uint8_t id_174 { 0 };
                        uint32_t id_175 { leb128_sz_319[id_174] };
                        uint8_t id_176 { uint8_t(id_175) };
                        uint8_t id_177 { 128 };
                        uint8_t id_178 { uint8_t(id_176 | id_177) };
                        choose_res_170 = id_178;
                      }
                      Pointer id_179 { id_165.writeU8(choose_res_170) };
                      Void id_180 { ((void)(leb128_ptr_320[id_163] = id_179), VOID) };
                      (void)id_180;
                      uint8_t id_181 { 0 };
                      uint8_t id_182 { 0 };
                      uint32_t id_183 { leb128_sz_319[id_182] };
                      uint8_t id_184 { 7 };
                      uint32_t id_185 { uint32_t(id_183 >> id_184) };
                      Void id_186 { ((void)(leb128_sz_319[id_181] = id_185), VOID) };
                      (void)id_186;
                      uint8_t id_187 { 0 };
                      uint32_t id_188 { leb128_sz_319[id_187] };
                      uint32_t id_189 { 0U };
                      bool id_190 { bool(id_188 > id_189) };
                      while_flag_162 = id_190;
                      if (while_flag_162) {
                        (void)VOID;
                      }
                    } while (while_flag_162);
                    (void)VOID;
                    uint8_t id_191 { 0 };
                    Pointer id_192 { leb128_ptr_320[id_191] };
                    let_res_161 = id_192;
                  }
                  let_res_159 = let_res_161;
                }
                ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_193 { (*p_0).via };
                ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_194 { std::get<3 /* Sqlite */>(id_193) };
                std::string id_195 { id_194.insert };
                Bytes id_196 { id_195 };
                Pointer id_197 { let_res_159.writeBytes(id_196) };
                let_res_153 = id_197;
              }
              Pointer let_res_198;
              {
                Pointer srec_dst_321 { let_res_153 };
                ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_199 { (*p_0).via };
                ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_200 { std::get<3 /* Sqlite */>(id_199) };
                std::string id_201 { id_200.create };
                uint32_t id_202 { (uint32_t)id_201.size() };
                Vec<1, uint32_t> id_203 {  id_202  };
                Pointer let_res_204;
                {
                  Vec<1, uint32_t> leb128_sz_322 { id_203 };
                  Vec<1, Pointer> id_205 {  srec_dst_321  };
                  Pointer let_res_206;
                  {
                    Vec<1, Pointer> leb128_ptr_323 { id_205 };
                    bool while_flag_207 { true };
                    do {
                      uint8_t id_208 { 0 };
                      uint8_t id_209 { 0 };
                      Pointer id_210 { leb128_ptr_323[id_209] };
                      uint32_t id_211 { 128U };
                      uint8_t id_212 { 0 };
                      uint32_t id_213 { leb128_sz_322[id_212] };
                      bool id_214 { bool(id_211 > id_213) };
                      uint8_t choose_res_215;
                      if (id_214) {
                        uint8_t id_216 { 0 };
                        uint32_t id_217 { leb128_sz_322[id_216] };
                        uint8_t id_218 { uint8_t(id_217) };
                        choose_res_215 = id_218;
                      } else {
                        uint8_t id_219 { 0 };
                        uint32_t id_220 { leb128_sz_322[id_219] };
                        uint8_t id_221 { uint8_t(id_220) };
                        uint8_t id_222 { 128 };
                        uint8_t id_223 { uint8_t(id_221 | id_222) };
                        choose_res_215 = id_223;
                      }
                      Pointer id_224 { id_210.writeU8(choose_res_215) };
                      Void id_225 { ((void)(leb128_ptr_323[id_208] = id_224), VOID) };
                      (void)id_225;
                      uint8_t id_226 { 0 };
                      uint8_t id_227 { 0 };
                      uint32_t id_228 { leb128_sz_322[id_227] };
                      uint8_t id_229 { 7 };
                      uint32_t id_230 { uint32_t(id_228 >> id_229) };
                      Void id_231 { ((void)(leb128_sz_322[id_226] = id_230), VOID) };
                      (void)id_231;
                      uint8_t id_232 { 0 };
                      uint32_t id_233 { leb128_sz_322[id_232] };
                      uint32_t id_234 { 0U };
                      bool id_235 { bool(id_233 > id_234) };
                      while_flag_207 = id_235;
                      if (while_flag_207) {
                        (void)VOID;
                      }
                    } while (while_flag_207);
                    (void)VOID;
                    uint8_t id_236 { 0 };
                    Pointer id_237 { leb128_ptr_323[id_236] };
                    let_res_206 = id_237;
                  }
                  let_res_204 = let_res_206;
                }
                ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_238 { (*p_0).via };
                ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_239 { std::get<3 /* Sqlite */>(id_238) };
                std::string id_240 { id_239.create };
                Bytes id_241 { id_240 };
                Pointer id_242 { let_res_204.writeBytes(id_241) };
                let_res_198 = id_242;
              }
              choose_res_108 = let_res_198;
            } else {
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_243 { (*p_0).via };
              uint16_t id_244 { uint16_t(id_243.index()) };
              uint16_t id_245 { 4 };
              bool id_246 { bool(id_244 == id_245) };
              Void id_247 { ((void)(assert(id_246)), VOID) };
              (void)id_247;
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_248 { (*p_0).via };
              ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_249 { std::get<4 /* Kafka */>(id_248) };
              Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> id_250 { id_249.options };
              uint32_t id_251 { id_250.size() };
              Vec<1, uint32_t> id_252 {  id_251  };
              Pointer let_res_253;
              {
                Vec<1, uint32_t> leb128_sz_298 { id_252 };
                Vec<1, Pointer> id_254 {  ssum_dst_297  };
                Pointer let_res_255;
                {
                  Vec<1, Pointer> leb128_ptr_299 { id_254 };
                  bool while_flag_256 { true };
                  do {
                    uint8_t id_257 { 0 };
                    uint8_t id_258 { 0 };
                    Pointer id_259 { leb128_ptr_299[id_258] };
                    uint32_t id_260 { 128U };
                    uint8_t id_261 { 0 };
                    uint32_t id_262 { leb128_sz_298[id_261] };
                    bool id_263 { bool(id_260 > id_262) };
                    uint8_t choose_res_264;
                    if (id_263) {
                      uint8_t id_265 { 0 };
                      uint32_t id_266 { leb128_sz_298[id_265] };
                      uint8_t id_267 { uint8_t(id_266) };
                      choose_res_264 = id_267;
                    } else {
                      uint8_t id_268 { 0 };
                      uint32_t id_269 { leb128_sz_298[id_268] };
                      uint8_t id_270 { uint8_t(id_269) };
                      uint8_t id_271 { 128 };
                      uint8_t id_272 { uint8_t(id_270 | id_271) };
                      choose_res_264 = id_272;
                    }
                    Pointer id_273 { id_259.writeU8(choose_res_264) };
                    Void id_274 { ((void)(leb128_ptr_299[id_257] = id_273), VOID) };
                    (void)id_274;
                    uint8_t id_275 { 0 };
                    uint8_t id_276 { 0 };
                    uint32_t id_277 { leb128_sz_298[id_276] };
                    uint8_t id_278 { 7 };
                    uint32_t id_279 { uint32_t(id_277 >> id_278) };
                    Void id_280 { ((void)(leb128_sz_298[id_275] = id_279), VOID) };
                    (void)id_280;
                    uint8_t id_281 { 0 };
                    uint32_t id_282 { leb128_sz_298[id_281] };
                    uint32_t id_283 { 0U };
                    bool id_284 { bool(id_282 > id_283) };
                    while_flag_256 = id_284;
                    if (while_flag_256) {
                      (void)VOID;
                    }
                  } while (while_flag_256);
                  (void)VOID;
                  uint8_t id_285 { 0 };
                  Pointer id_286 { leb128_ptr_299[id_285] };
                  let_res_255 = id_286;
                }
                let_res_253 = let_res_255;
              }
              Vec<1, Pointer> id_287 {  let_res_253  };
              Pointer let_res_288;
              {
                Vec<1, Pointer> dst_ref_300 { id_287 };
                int32_t id_289 { 0L };
                Vec<1, int32_t> id_290 {  id_289  };
                Pointer let_res_291;
                {
                  Vec<1, int32_t> n_ref_301 { id_290 };
                  ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_292 { (*p_0).via };
                  ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_293 { std::get<4 /* Kafka */>(id_292) };
                  Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> id_294 { id_293.options };
                  for (::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4 x_302 : id_294) {
                    uint8_t id_295 { 0 };
                    uint8_t id_296 { 0 };
                    Pointer id_297 { dst_ref_300[id_296] };
                    Pointer let_res_298;
                    {
                      Pointer stup_dst_303 { id_297 };
                      std::string id_299 { std::get<0>(x_302) };
                      uint32_t id_300 { (uint32_t)id_299.size() };
                      Vec<1, uint32_t> id_301 {  id_300  };
                      Pointer let_res_302;
                      {
                        Vec<1, uint32_t> leb128_sz_304 { id_301 };
                        Vec<1, Pointer> id_303 {  stup_dst_303  };
                        Pointer let_res_304;
                        {
                          Vec<1, Pointer> leb128_ptr_305 { id_303 };
                          bool while_flag_305 { true };
                          do {
                            uint8_t id_306 { 0 };
                            uint8_t id_307 { 0 };
                            Pointer id_308 { leb128_ptr_305[id_307] };
                            uint32_t id_309 { 128U };
                            uint8_t id_310 { 0 };
                            uint32_t id_311 { leb128_sz_304[id_310] };
                            bool id_312 { bool(id_309 > id_311) };
                            uint8_t choose_res_313;
                            if (id_312) {
                              uint8_t id_314 { 0 };
                              uint32_t id_315 { leb128_sz_304[id_314] };
                              uint8_t id_316 { uint8_t(id_315) };
                              choose_res_313 = id_316;
                            } else {
                              uint8_t id_317 { 0 };
                              uint32_t id_318 { leb128_sz_304[id_317] };
                              uint8_t id_319 { uint8_t(id_318) };
                              uint8_t id_320 { 128 };
                              uint8_t id_321 { uint8_t(id_319 | id_320) };
                              choose_res_313 = id_321;
                            }
                            Pointer id_322 { id_308.writeU8(choose_res_313) };
                            Void id_323 { ((void)(leb128_ptr_305[id_306] = id_322), VOID) };
                            (void)id_323;
                            uint8_t id_324 { 0 };
                            uint8_t id_325 { 0 };
                            uint32_t id_326 { leb128_sz_304[id_325] };
                            uint8_t id_327 { 7 };
                            uint32_t id_328 { uint32_t(id_326 >> id_327) };
                            Void id_329 { ((void)(leb128_sz_304[id_324] = id_328), VOID) };
                            (void)id_329;
                            uint8_t id_330 { 0 };
                            uint32_t id_331 { leb128_sz_304[id_330] };
                            uint32_t id_332 { 0U };
                            bool id_333 { bool(id_331 > id_332) };
                            while_flag_305 = id_333;
                            if (while_flag_305) {
                              (void)VOID;
                            }
                          } while (while_flag_305);
                          (void)VOID;
                          uint8_t id_334 { 0 };
                          Pointer id_335 { leb128_ptr_305[id_334] };
                          let_res_304 = id_335;
                        }
                        let_res_302 = let_res_304;
                      }
                      std::string id_336 { std::get<0>(x_302) };
                      Bytes id_337 { id_336 };
                      Pointer id_338 { let_res_302.writeBytes(id_337) };
                      let_res_298 = id_338;
                    }
                    Pointer let_res_339;
                    {
                      Pointer stup_dst_306 { let_res_298 };
                      std::string id_340 { std::get<1>(x_302) };
                      uint32_t id_341 { (uint32_t)id_340.size() };
                      Vec<1, uint32_t> id_342 {  id_341  };
                      Pointer let_res_343;
                      {
                        Vec<1, uint32_t> leb128_sz_307 { id_342 };
                        Vec<1, Pointer> id_344 {  stup_dst_306  };
                        Pointer let_res_345;
                        {
                          Vec<1, Pointer> leb128_ptr_308 { id_344 };
                          bool while_flag_346 { true };
                          do {
                            uint8_t id_347 { 0 };
                            uint8_t id_348 { 0 };
                            Pointer id_349 { leb128_ptr_308[id_348] };
                            uint32_t id_350 { 128U };
                            uint8_t id_351 { 0 };
                            uint32_t id_352 { leb128_sz_307[id_351] };
                            bool id_353 { bool(id_350 > id_352) };
                            uint8_t choose_res_354;
                            if (id_353) {
                              uint8_t id_355 { 0 };
                              uint32_t id_356 { leb128_sz_307[id_355] };
                              uint8_t id_357 { uint8_t(id_356) };
                              choose_res_354 = id_357;
                            } else {
                              uint8_t id_358 { 0 };
                              uint32_t id_359 { leb128_sz_307[id_358] };
                              uint8_t id_360 { uint8_t(id_359) };
                              uint8_t id_361 { 128 };
                              uint8_t id_362 { uint8_t(id_360 | id_361) };
                              choose_res_354 = id_362;
                            }
                            Pointer id_363 { id_349.writeU8(choose_res_354) };
                            Void id_364 { ((void)(leb128_ptr_308[id_347] = id_363), VOID) };
                            (void)id_364;
                            uint8_t id_365 { 0 };
                            uint8_t id_366 { 0 };
                            uint32_t id_367 { leb128_sz_307[id_366] };
                            uint8_t id_368 { 7 };
                            uint32_t id_369 { uint32_t(id_367 >> id_368) };
                            Void id_370 { ((void)(leb128_sz_307[id_365] = id_369), VOID) };
                            (void)id_370;
                            uint8_t id_371 { 0 };
                            uint32_t id_372 { leb128_sz_307[id_371] };
                            uint32_t id_373 { 0U };
                            bool id_374 { bool(id_372 > id_373) };
                            while_flag_346 = id_374;
                            if (while_flag_346) {
                              (void)VOID;
                            }
                          } while (while_flag_346);
                          (void)VOID;
                          uint8_t id_375 { 0 };
                          Pointer id_376 { leb128_ptr_308[id_375] };
                          let_res_345 = id_376;
                        }
                        let_res_343 = let_res_345;
                      }
                      std::string id_377 { std::get<1>(x_302) };
                      Bytes id_378 { id_377 };
                      Pointer id_379 { let_res_343.writeBytes(id_378) };
                      let_res_339 = id_379;
                    }
                    Void id_380 { ((void)(dst_ref_300[id_295] = let_res_339), VOID) };
                    (void)id_380;
                    uint8_t id_381 { 0 };
                    int32_t id_382 { 1L };
                    uint8_t id_383 { 0 };
                    int32_t id_384 { n_ref_301[id_383] };
                    int32_t id_385 { int32_t(id_382 + id_384) };
                    Void id_386 { ((void)(n_ref_301[id_381] = id_385), VOID) };
                    (void)id_386;
                    (void)id_386;
                  }
                  (void)VOID;
                  uint8_t id_387 { 0 };
                  Pointer id_388 { dst_ref_300[id_387] };
                  let_res_291 = id_388;
                }
                let_res_288 = let_res_291;
              }
              Pointer let_res_389;
              {
                Pointer srec_dst_309 { let_res_288 };
                ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_390 { (*p_0).via };
                ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_391 { std::get<4 /* Kafka */>(id_390) };
                std::string id_392 { id_391.topic };
                uint32_t id_393 { (uint32_t)id_392.size() };
                Vec<1, uint32_t> id_394 {  id_393  };
                Pointer let_res_395;
                {
                  Vec<1, uint32_t> leb128_sz_310 { id_394 };
                  Vec<1, Pointer> id_396 {  srec_dst_309  };
                  Pointer let_res_397;
                  {
                    Vec<1, Pointer> leb128_ptr_311 { id_396 };
                    bool while_flag_398 { true };
                    do {
                      uint8_t id_399 { 0 };
                      uint8_t id_400 { 0 };
                      Pointer id_401 { leb128_ptr_311[id_400] };
                      uint32_t id_402 { 128U };
                      uint8_t id_403 { 0 };
                      uint32_t id_404 { leb128_sz_310[id_403] };
                      bool id_405 { bool(id_402 > id_404) };
                      uint8_t choose_res_406;
                      if (id_405) {
                        uint8_t id_407 { 0 };
                        uint32_t id_408 { leb128_sz_310[id_407] };
                        uint8_t id_409 { uint8_t(id_408) };
                        choose_res_406 = id_409;
                      } else {
                        uint8_t id_410 { 0 };
                        uint32_t id_411 { leb128_sz_310[id_410] };
                        uint8_t id_412 { uint8_t(id_411) };
                        uint8_t id_413 { 128 };
                        uint8_t id_414 { uint8_t(id_412 | id_413) };
                        choose_res_406 = id_414;
                      }
                      Pointer id_415 { id_401.writeU8(choose_res_406) };
                      Void id_416 { ((void)(leb128_ptr_311[id_399] = id_415), VOID) };
                      (void)id_416;
                      uint8_t id_417 { 0 };
                      uint8_t id_418 { 0 };
                      uint32_t id_419 { leb128_sz_310[id_418] };
                      uint8_t id_420 { 7 };
                      uint32_t id_421 { uint32_t(id_419 >> id_420) };
                      Void id_422 { ((void)(leb128_sz_310[id_417] = id_421), VOID) };
                      (void)id_422;
                      uint8_t id_423 { 0 };
                      uint32_t id_424 { leb128_sz_310[id_423] };
                      uint32_t id_425 { 0U };
                      bool id_426 { bool(id_424 > id_425) };
                      while_flag_398 = id_426;
                      if (while_flag_398) {
                        (void)VOID;
                      }
                    } while (while_flag_398);
                    (void)VOID;
                    uint8_t id_427 { 0 };
                    Pointer id_428 { leb128_ptr_311[id_427] };
                    let_res_397 = id_428;
                  }
                  let_res_395 = let_res_397;
                }
                ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_429 { (*p_0).via };
                ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_430 { std::get<4 /* Kafka */>(id_429) };
                std::string id_431 { id_430.topic };
                Bytes id_432 { id_431 };
                Pointer id_433 { let_res_395.writeBytes(id_432) };
                let_res_389 = id_433;
              }
              Pointer let_res_434;
              {
                Pointer srec_dst_312 { let_res_389 };
                ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_435 { (*p_0).via };
                ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_436 { std::get<4 /* Kafka */>(id_435) };
                uint16_t id_437 { id_436.partition };
                Pointer id_438 { srec_dst_312.writeU16Le(id_437) };
                let_res_434 = id_438;
              }
              Pointer let_res_439;
              {
                Pointer srec_dst_313 { let_res_434 };
                ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_440 { (*p_0).via };
                ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_441 { std::get<4 /* Kafka */>(id_440) };
                std::string id_442 { id_441.text };
                uint32_t id_443 { (uint32_t)id_442.size() };
                Vec<1, uint32_t> id_444 {  id_443  };
                Pointer let_res_445;
                {
                  Vec<1, uint32_t> leb128_sz_314 { id_444 };
                  Vec<1, Pointer> id_446 {  srec_dst_313  };
                  Pointer let_res_447;
                  {
                    Vec<1, Pointer> leb128_ptr_315 { id_446 };
                    bool while_flag_448 { true };
                    do {
                      uint8_t id_449 { 0 };
                      uint8_t id_450 { 0 };
                      Pointer id_451 { leb128_ptr_315[id_450] };
                      uint32_t id_452 { 128U };
                      uint8_t id_453 { 0 };
                      uint32_t id_454 { leb128_sz_314[id_453] };
                      bool id_455 { bool(id_452 > id_454) };
                      uint8_t choose_res_456;
                      if (id_455) {
                        uint8_t id_457 { 0 };
                        uint32_t id_458 { leb128_sz_314[id_457] };
                        uint8_t id_459 { uint8_t(id_458) };
                        choose_res_456 = id_459;
                      } else {
                        uint8_t id_460 { 0 };
                        uint32_t id_461 { leb128_sz_314[id_460] };
                        uint8_t id_462 { uint8_t(id_461) };
                        uint8_t id_463 { 128 };
                        uint8_t id_464 { uint8_t(id_462 | id_463) };
                        choose_res_456 = id_464;
                      }
                      Pointer id_465 { id_451.writeU8(choose_res_456) };
                      Void id_466 { ((void)(leb128_ptr_315[id_449] = id_465), VOID) };
                      (void)id_466;
                      uint8_t id_467 { 0 };
                      uint8_t id_468 { 0 };
                      uint32_t id_469 { leb128_sz_314[id_468] };
                      uint8_t id_470 { 7 };
                      uint32_t id_471 { uint32_t(id_469 >> id_470) };
                      Void id_472 { ((void)(leb128_sz_314[id_467] = id_471), VOID) };
                      (void)id_472;
                      uint8_t id_473 { 0 };
                      uint32_t id_474 { leb128_sz_314[id_473] };
                      uint32_t id_475 { 0U };
                      bool id_476 { bool(id_474 > id_475) };
                      while_flag_448 = id_476;
                      if (while_flag_448) {
                        (void)VOID;
                      }
                    } while (while_flag_448);
                    (void)VOID;
                    uint8_t id_477 { 0 };
                    Pointer id_478 { leb128_ptr_315[id_477] };
                    let_res_447 = id_478;
                  }
                  let_res_445 = let_res_447;
                }
                ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_479 { (*p_0).via };
                ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_480 { std::get<4 /* Kafka */>(id_479) };
                std::string id_481 { id_480.text };
                Bytes id_482 { id_481 };
                Pointer id_483 { let_res_445.writeBytes(id_482) };
                let_res_439 = id_483;
              }
              choose_res_108 = let_res_439;
            }
            choose_res_61 = choose_res_108;
          }
          choose_res_14 = choose_res_61;
        }
        choose_res_9 = choose_res_14;
      }
      let_res_4 = choose_res_9;
    }
    Pointer let_res_484;
    {
      Pointer srec_dst_328 { let_res_4 };
      double id_485 { (*p_0).timeout };
      uint64_t id_486 { qword_of_float(id_485) };
      Pointer id_487 { srec_dst_328.writeU64Le(id_486) };
      let_res_484 = id_487;
    }
    return let_res_484;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::alerting_contact::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{via: [Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]; timeout: FLOAT}")
      (add
        (if (eq (u16 0) (label-of (get-field "via" (param 0)))) (size 2)
          (if (eq (u16 1) (label-of (get-field "via" (param 0))))
            (add (size 2)
              (add
                (let "n_ref_293" (make-vec (string-length (get-alt "Exec" (get-field "via" (param 0)))))
                  (let "lebsz_ref_294" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_293")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_294")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_294") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_294")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_294")))))) 
                (size-of-u32 (string-length (get-alt "Exec" (get-field "via" (param 0)))))))
            (if (eq (u16 2) (label-of (get-field "via" (param 0))))
              (add (size 2)
                (add
                  (let "n_ref_290" (make-vec (string-length (get-alt "SysLog" (get-field "via" (param 0)))))
                    (let "lebsz_ref_291" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_290")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_291")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_291") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_291")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_291")))))) 
                  (size-of-u32 (string-length (get-alt "SysLog" (get-field "via" (param 0)))))))
              (if (eq (u16 3) (label-of (get-field "via" (param 0))))
                (let "sz_285"
                  (let "sz_281"
                    (add (size 2)
                      (add
                        (let "n_ref_279" (make-vec (string-length (get-field "file" (get-alt "Sqlite" (get-field "via" (param 0))))))
                          (let "lebsz_ref_280" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_279")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_280")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_280") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_280")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_280")))))) 
                        (size-of-u32 (string-length (get-field "file" (get-alt "Sqlite" (get-field "via" (param 0))))))))
                    (add (identifier "sz_281")
                      (add
                        (let "n_ref_283" (make-vec (string-length (get-field "insert" (get-alt "Sqlite" (get-field "via" (param 0))))))
                          (let "lebsz_ref_284" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_283")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_284")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_284") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_284")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_284")))))) 
                        (size-of-u32 (string-length (get-field "insert" (get-alt "Sqlite" (get-field "via" (param 0)))))))))
                  (add (identifier "sz_285")
                    (add
                      (let "n_ref_287" (make-vec (string-length (get-field "create" (get-alt "Sqlite" (get-field "via" (param 0))))))
                        (let "lebsz_ref_288" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_287")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_288")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_288") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_288")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_288")))))) 
                      (size-of-u32 (string-length (get-field "create" (get-alt "Sqlite" (get-field "via" (param 0)))))))))
                (seq (assert (eq (label-of (get-field "via" (param 0))) (u16 4)))
                  (let "sz_273"
                    (add
                      (let "sz_268"
                        (let "sz_ref_258"
                          (make-vec
                            (add (size 2)
                              (let "n_ref_256" (make-vec (cardinality (get-field "options" (get-alt "Kafka" (get-field "via" (param 0))))))
                                (let "lebsz_ref_257" (make-vec (u32 1))
                                  (seq
                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_256")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_257")) (u8 7)))
                                      (set-vec (u8 0) (identifier "lebsz_ref_257") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_257")) (u32 1)))) 
                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_257"))))))))
                          (seq
                            (let "repeat_n_259" (make-vec (i32 0))
                              (while (gt (to-i32 (cardinality (get-field "options" (get-alt "Kafka" (get-field "via" (param 0)))))) (unsafe-nth (u8 0) (identifier "repeat_n_259")))
                                (seq
                                  (set-vec (u8 0) (identifier "sz_ref_258")
                                    (let "sz_264"
                                      (let "sz_260" (unsafe-nth (u8 0) (identifier "sz_ref_258"))
                                        (add (identifier "sz_260")
                                          (let "wlen_261" (string-length (get-item 0 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_259")) (get-field "options" (get-alt "Kafka" (get-field "via" (param 0)))))))
                                            (add
                                              (let "n_ref_262" (make-vec (identifier "wlen_261"))
                                                (let "lebsz_ref_263" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_262")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_263")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_263") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_263")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_263")))))) 
                                              (size-of-u32 (identifier "wlen_261"))))))
                                      (add (identifier "sz_264")
                                        (let "wlen_265" (string-length (get-item 1 (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_259")) (get-field "options" (get-alt "Kafka" (get-field "via" (param 0)))))))
                                          (add
                                            (let "n_ref_266" (make-vec (identifier "wlen_265"))
                                              (let "lebsz_ref_267" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_266")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_267")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_267") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_267")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_267")))))) 
                                            (size-of-u32 (identifier "wlen_265"))))))) 
                                  (set-vec (u8 0) (identifier "repeat_n_259") (add (unsafe-nth (u8 0) (identifier "repeat_n_259")) (i32 1)))))) 
                            (unsafe-nth (u8 0) (identifier "sz_ref_258"))))
                        (add (identifier "sz_268")
                          (add
                            (let "n_ref_270" (make-vec (string-length (get-field "topic" (get-alt "Kafka" (get-field "via" (param 0))))))
                              (let "lebsz_ref_271" (make-vec (u32 1))
                                (seq
                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_270")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_271")) (u8 7)))
                                    (set-vec (u8 0) (identifier "lebsz_ref_271") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_271")) (u32 1)))) 
                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_271")))))) 
                            (size-of-u32 (string-length (get-field "topic" (get-alt "Kafka" (get-field "via" (param 0))))))))) 
                      (size 2))
                    (add (identifier "sz_273")
                      (add
                        (let "n_ref_275" (make-vec (string-length (get-field "text" (get-alt "Kafka" (get-field "via" (param 0))))))
                          (let "lebsz_ref_276" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_275")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_276")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_276") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_276")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_276")))))) 
                        (size-of-u32 (string-length (get-field "text" (get-alt "Kafka" (get-field "via" (param 0)))))))))))))) 
        (size 8)))
 */
static std::function<Size(::dessser::gen::alerting_contact::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::alerting_contact::t*)> fun488 { [&fun488](::dessser::gen::alerting_contact::t* p_0) {
    uint16_t id_489 { 0 };
    ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_490 { (*p_0).via };
    uint16_t id_491 { uint16_t(id_490.index()) };
    bool id_492 { bool(id_489 == id_491) };
    Size choose_res_493;
    if (id_492) {
      Size id_494 { 2UL };
      choose_res_493 = id_494;
    } else {
      uint16_t id_495 { 1 };
      ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_496 { (*p_0).via };
      uint16_t id_497 { uint16_t(id_496.index()) };
      bool id_498 { bool(id_495 == id_497) };
      Size choose_res_499;
      if (id_498) {
        Size id_500 { 2UL };
        ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_501 { (*p_0).via };
        std::string id_502 { std::get<1 /* Exec */>(id_501) };
        uint32_t id_503 { (uint32_t)id_502.size() };
        Vec<1, uint32_t> id_504 {  id_503  };
        Size let_res_505;
        {
          Vec<1, uint32_t> n_ref_293 { id_504 };
          uint32_t id_506 { 1U };
          Vec<1, uint32_t> id_507 {  id_506  };
          Size let_res_508;
          {
            Vec<1, uint32_t> lebsz_ref_294 { id_507 };
            bool while_flag_509 { true };
            do {
              uint8_t id_510 { 0 };
              uint32_t id_511 { n_ref_293[id_510] };
              uint8_t id_512 { 0 };
              uint32_t id_513 { lebsz_ref_294[id_512] };
              uint8_t id_514 { 7 };
              uint32_t id_515 { uint32_t(id_513 << id_514) };
              bool id_516 { bool(id_511 >= id_515) };
              while_flag_509 = id_516;
              if (while_flag_509) {
                uint8_t id_517 { 0 };
                uint8_t id_518 { 0 };
                uint32_t id_519 { lebsz_ref_294[id_518] };
                uint32_t id_520 { 1U };
                uint32_t id_521 { uint32_t(id_519 + id_520) };
                Void id_522 { ((void)(lebsz_ref_294[id_517] = id_521), VOID) };
                (void)id_522;
              }
            } while (while_flag_509);
            (void)VOID;
            uint8_t id_523 { 0 };
            uint32_t id_524 { lebsz_ref_294[id_523] };
            Size id_525 { Size(id_524) };
            let_res_508 = id_525;
          }
          let_res_505 = let_res_508;
        }
        ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_526 { (*p_0).via };
        std::string id_527 { std::get<1 /* Exec */>(id_526) };
        uint32_t id_528 { (uint32_t)id_527.size() };
        Size id_529 { Size(id_528) };
        Size id_530 { Size(let_res_505 + id_529) };
        Size id_531 { Size(id_500 + id_530) };
        choose_res_499 = id_531;
      } else {
        uint16_t id_532 { 2 };
        ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_533 { (*p_0).via };
        uint16_t id_534 { uint16_t(id_533.index()) };
        bool id_535 { bool(id_532 == id_534) };
        Size choose_res_536;
        if (id_535) {
          Size id_537 { 2UL };
          ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_538 { (*p_0).via };
          std::string id_539 { std::get<2 /* SysLog */>(id_538) };
          uint32_t id_540 { (uint32_t)id_539.size() };
          Vec<1, uint32_t> id_541 {  id_540  };
          Size let_res_542;
          {
            Vec<1, uint32_t> n_ref_290 { id_541 };
            uint32_t id_543 { 1U };
            Vec<1, uint32_t> id_544 {  id_543  };
            Size let_res_545;
            {
              Vec<1, uint32_t> lebsz_ref_291 { id_544 };
              bool while_flag_546 { true };
              do {
                uint8_t id_547 { 0 };
                uint32_t id_548 { n_ref_290[id_547] };
                uint8_t id_549 { 0 };
                uint32_t id_550 { lebsz_ref_291[id_549] };
                uint8_t id_551 { 7 };
                uint32_t id_552 { uint32_t(id_550 << id_551) };
                bool id_553 { bool(id_548 >= id_552) };
                while_flag_546 = id_553;
                if (while_flag_546) {
                  uint8_t id_554 { 0 };
                  uint8_t id_555 { 0 };
                  uint32_t id_556 { lebsz_ref_291[id_555] };
                  uint32_t id_557 { 1U };
                  uint32_t id_558 { uint32_t(id_556 + id_557) };
                  Void id_559 { ((void)(lebsz_ref_291[id_554] = id_558), VOID) };
                  (void)id_559;
                }
              } while (while_flag_546);
              (void)VOID;
              uint8_t id_560 { 0 };
              uint32_t id_561 { lebsz_ref_291[id_560] };
              Size id_562 { Size(id_561) };
              let_res_545 = id_562;
            }
            let_res_542 = let_res_545;
          }
          ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_563 { (*p_0).via };
          std::string id_564 { std::get<2 /* SysLog */>(id_563) };
          uint32_t id_565 { (uint32_t)id_564.size() };
          Size id_566 { Size(id_565) };
          Size id_567 { Size(let_res_542 + id_566) };
          Size id_568 { Size(id_537 + id_567) };
          choose_res_536 = id_568;
        } else {
          uint16_t id_569 { 3 };
          ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_570 { (*p_0).via };
          uint16_t id_571 { uint16_t(id_570.index()) };
          bool id_572 { bool(id_569 == id_571) };
          Size choose_res_573;
          if (id_572) {
            Size id_574 { 2UL };
            ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_575 { (*p_0).via };
            ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_576 { std::get<3 /* Sqlite */>(id_575) };
            std::string id_577 { id_576.file };
            uint32_t id_578 { (uint32_t)id_577.size() };
            Vec<1, uint32_t> id_579 {  id_578  };
            Size let_res_580;
            {
              Vec<1, uint32_t> n_ref_279 { id_579 };
              uint32_t id_581 { 1U };
              Vec<1, uint32_t> id_582 {  id_581  };
              Size let_res_583;
              {
                Vec<1, uint32_t> lebsz_ref_280 { id_582 };
                bool while_flag_584 { true };
                do {
                  uint8_t id_585 { 0 };
                  uint32_t id_586 { n_ref_279[id_585] };
                  uint8_t id_587 { 0 };
                  uint32_t id_588 { lebsz_ref_280[id_587] };
                  uint8_t id_589 { 7 };
                  uint32_t id_590 { uint32_t(id_588 << id_589) };
                  bool id_591 { bool(id_586 >= id_590) };
                  while_flag_584 = id_591;
                  if (while_flag_584) {
                    uint8_t id_592 { 0 };
                    uint8_t id_593 { 0 };
                    uint32_t id_594 { lebsz_ref_280[id_593] };
                    uint32_t id_595 { 1U };
                    uint32_t id_596 { uint32_t(id_594 + id_595) };
                    Void id_597 { ((void)(lebsz_ref_280[id_592] = id_596), VOID) };
                    (void)id_597;
                  }
                } while (while_flag_584);
                (void)VOID;
                uint8_t id_598 { 0 };
                uint32_t id_599 { lebsz_ref_280[id_598] };
                Size id_600 { Size(id_599) };
                let_res_583 = id_600;
              }
              let_res_580 = let_res_583;
            }
            ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_601 { (*p_0).via };
            ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_602 { std::get<3 /* Sqlite */>(id_601) };
            std::string id_603 { id_602.file };
            uint32_t id_604 { (uint32_t)id_603.size() };
            Size id_605 { Size(id_604) };
            Size id_606 { Size(let_res_580 + id_605) };
            Size id_607 { Size(id_574 + id_606) };
            Size let_res_608;
            {
              Size sz_281 { id_607 };
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_609 { (*p_0).via };
              ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_610 { std::get<3 /* Sqlite */>(id_609) };
              std::string id_611 { id_610.insert };
              uint32_t id_612 { (uint32_t)id_611.size() };
              Vec<1, uint32_t> id_613 {  id_612  };
              Size let_res_614;
              {
                Vec<1, uint32_t> n_ref_283 { id_613 };
                uint32_t id_615 { 1U };
                Vec<1, uint32_t> id_616 {  id_615  };
                Size let_res_617;
                {
                  Vec<1, uint32_t> lebsz_ref_284 { id_616 };
                  bool while_flag_618 { true };
                  do {
                    uint8_t id_619 { 0 };
                    uint32_t id_620 { n_ref_283[id_619] };
                    uint8_t id_621 { 0 };
                    uint32_t id_622 { lebsz_ref_284[id_621] };
                    uint8_t id_623 { 7 };
                    uint32_t id_624 { uint32_t(id_622 << id_623) };
                    bool id_625 { bool(id_620 >= id_624) };
                    while_flag_618 = id_625;
                    if (while_flag_618) {
                      uint8_t id_626 { 0 };
                      uint8_t id_627 { 0 };
                      uint32_t id_628 { lebsz_ref_284[id_627] };
                      uint32_t id_629 { 1U };
                      uint32_t id_630 { uint32_t(id_628 + id_629) };
                      Void id_631 { ((void)(lebsz_ref_284[id_626] = id_630), VOID) };
                      (void)id_631;
                    }
                  } while (while_flag_618);
                  (void)VOID;
                  uint8_t id_632 { 0 };
                  uint32_t id_633 { lebsz_ref_284[id_632] };
                  Size id_634 { Size(id_633) };
                  let_res_617 = id_634;
                }
                let_res_614 = let_res_617;
              }
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_635 { (*p_0).via };
              ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_636 { std::get<3 /* Sqlite */>(id_635) };
              std::string id_637 { id_636.insert };
              uint32_t id_638 { (uint32_t)id_637.size() };
              Size id_639 { Size(id_638) };
              Size id_640 { Size(let_res_614 + id_639) };
              Size id_641 { Size(sz_281 + id_640) };
              let_res_608 = id_641;
            }
            Size let_res_642;
            {
              Size sz_285 { let_res_608 };
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_643 { (*p_0).via };
              ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_644 { std::get<3 /* Sqlite */>(id_643) };
              std::string id_645 { id_644.create };
              uint32_t id_646 { (uint32_t)id_645.size() };
              Vec<1, uint32_t> id_647 {  id_646  };
              Size let_res_648;
              {
                Vec<1, uint32_t> n_ref_287 { id_647 };
                uint32_t id_649 { 1U };
                Vec<1, uint32_t> id_650 {  id_649  };
                Size let_res_651;
                {
                  Vec<1, uint32_t> lebsz_ref_288 { id_650 };
                  bool while_flag_652 { true };
                  do {
                    uint8_t id_653 { 0 };
                    uint32_t id_654 { n_ref_287[id_653] };
                    uint8_t id_655 { 0 };
                    uint32_t id_656 { lebsz_ref_288[id_655] };
                    uint8_t id_657 { 7 };
                    uint32_t id_658 { uint32_t(id_656 << id_657) };
                    bool id_659 { bool(id_654 >= id_658) };
                    while_flag_652 = id_659;
                    if (while_flag_652) {
                      uint8_t id_660 { 0 };
                      uint8_t id_661 { 0 };
                      uint32_t id_662 { lebsz_ref_288[id_661] };
                      uint32_t id_663 { 1U };
                      uint32_t id_664 { uint32_t(id_662 + id_663) };
                      Void id_665 { ((void)(lebsz_ref_288[id_660] = id_664), VOID) };
                      (void)id_665;
                    }
                  } while (while_flag_652);
                  (void)VOID;
                  uint8_t id_666 { 0 };
                  uint32_t id_667 { lebsz_ref_288[id_666] };
                  Size id_668 { Size(id_667) };
                  let_res_651 = id_668;
                }
                let_res_648 = let_res_651;
              }
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_669 { (*p_0).via };
              ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_670 { std::get<3 /* Sqlite */>(id_669) };
              std::string id_671 { id_670.create };
              uint32_t id_672 { (uint32_t)id_671.size() };
              Size id_673 { Size(id_672) };
              Size id_674 { Size(let_res_648 + id_673) };
              Size id_675 { Size(sz_285 + id_674) };
              let_res_642 = id_675;
            }
            choose_res_573 = let_res_642;
          } else {
            ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_676 { (*p_0).via };
            uint16_t id_677 { uint16_t(id_676.index()) };
            uint16_t id_678 { 4 };
            bool id_679 { bool(id_677 == id_678) };
            Void id_680 { ((void)(assert(id_679)), VOID) };
            (void)id_680;
            Size id_681 { 2UL };
            ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_682 { (*p_0).via };
            ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_683 { std::get<4 /* Kafka */>(id_682) };
            Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> id_684 { id_683.options };
            uint32_t id_685 { id_684.size() };
            Vec<1, uint32_t> id_686 {  id_685  };
            Size let_res_687;
            {
              Vec<1, uint32_t> n_ref_256 { id_686 };
              uint32_t id_688 { 1U };
              Vec<1, uint32_t> id_689 {  id_688  };
              Size let_res_690;
              {
                Vec<1, uint32_t> lebsz_ref_257 { id_689 };
                bool while_flag_691 { true };
                do {
                  uint8_t id_692 { 0 };
                  uint32_t id_693 { n_ref_256[id_692] };
                  uint8_t id_694 { 0 };
                  uint32_t id_695 { lebsz_ref_257[id_694] };
                  uint8_t id_696 { 7 };
                  uint32_t id_697 { uint32_t(id_695 << id_696) };
                  bool id_698 { bool(id_693 >= id_697) };
                  while_flag_691 = id_698;
                  if (while_flag_691) {
                    uint8_t id_699 { 0 };
                    uint8_t id_700 { 0 };
                    uint32_t id_701 { lebsz_ref_257[id_700] };
                    uint32_t id_702 { 1U };
                    uint32_t id_703 { uint32_t(id_701 + id_702) };
                    Void id_704 { ((void)(lebsz_ref_257[id_699] = id_703), VOID) };
                    (void)id_704;
                  }
                } while (while_flag_691);
                (void)VOID;
                uint8_t id_705 { 0 };
                uint32_t id_706 { lebsz_ref_257[id_705] };
                Size id_707 { Size(id_706) };
                let_res_690 = id_707;
              }
              let_res_687 = let_res_690;
            }
            Size id_708 { Size(id_681 + let_res_687) };
            Vec<1, Size> id_709 {  id_708  };
            Size let_res_710;
            {
              Vec<1, Size> sz_ref_258 { id_709 };
              int32_t id_711 { 0L };
              Vec<1, int32_t> id_712 {  id_711  };
              {
                Vec<1, int32_t> repeat_n_259 { id_712 };
                bool while_flag_713 { true };
                do {
                  ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_714 { (*p_0).via };
                  ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_715 { std::get<4 /* Kafka */>(id_714) };
                  Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> id_716 { id_715.options };
                  uint32_t id_717 { id_716.size() };
                  int32_t id_718 { int32_t(id_717) };
                  uint8_t id_719 { 0 };
                  int32_t id_720 { repeat_n_259[id_719] };
                  bool id_721 { bool(id_718 > id_720) };
                  while_flag_713 = id_721;
                  if (while_flag_713) {
                    uint8_t id_722 { 0 };
                    uint8_t id_723 { 0 };
                    Size id_724 { sz_ref_258[id_723] };
                    Size let_res_725;
                    {
                      Size sz_260 { id_724 };
                      uint8_t id_726 { 0 };
                      int32_t id_727 { repeat_n_259[id_726] };
                      ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_728 { (*p_0).via };
                      ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_729 { std::get<4 /* Kafka */>(id_728) };
                      Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> id_730 { id_729.options };
                      ::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4 id_731 { id_730[id_727] };
                      std::string id_732 { std::get<0>(id_731) };
                      uint32_t id_733 { (uint32_t)id_732.size() };
                      Size let_res_734;
                      {
                        uint32_t wlen_261 { id_733 };
                        Vec<1, uint32_t> id_735 {  wlen_261  };
                        Size let_res_736;
                        {
                          Vec<1, uint32_t> n_ref_262 { id_735 };
                          uint32_t id_737 { 1U };
                          Vec<1, uint32_t> id_738 {  id_737  };
                          Size let_res_739;
                          {
                            Vec<1, uint32_t> lebsz_ref_263 { id_738 };
                            bool while_flag_740 { true };
                            do {
                              uint8_t id_741 { 0 };
                              uint32_t id_742 { n_ref_262[id_741] };
                              uint8_t id_743 { 0 };
                              uint32_t id_744 { lebsz_ref_263[id_743] };
                              uint8_t id_745 { 7 };
                              uint32_t id_746 { uint32_t(id_744 << id_745) };
                              bool id_747 { bool(id_742 >= id_746) };
                              while_flag_740 = id_747;
                              if (while_flag_740) {
                                uint8_t id_748 { 0 };
                                uint8_t id_749 { 0 };
                                uint32_t id_750 { lebsz_ref_263[id_749] };
                                uint32_t id_751 { 1U };
                                uint32_t id_752 { uint32_t(id_750 + id_751) };
                                Void id_753 { ((void)(lebsz_ref_263[id_748] = id_752), VOID) };
                                (void)id_753;
                              }
                            } while (while_flag_740);
                            (void)VOID;
                            uint8_t id_754 { 0 };
                            uint32_t id_755 { lebsz_ref_263[id_754] };
                            Size id_756 { Size(id_755) };
                            let_res_739 = id_756;
                          }
                          let_res_736 = let_res_739;
                        }
                        Size id_757 { Size(wlen_261) };
                        Size id_758 { Size(let_res_736 + id_757) };
                        let_res_734 = id_758;
                      }
                      Size id_759 { Size(sz_260 + let_res_734) };
                      let_res_725 = id_759;
                    }
                    Size let_res_760;
                    {
                      Size sz_264 { let_res_725 };
                      uint8_t id_761 { 0 };
                      int32_t id_762 { repeat_n_259[id_761] };
                      ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_763 { (*p_0).via };
                      ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_764 { std::get<4 /* Kafka */>(id_763) };
                      Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> id_765 { id_764.options };
                      ::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4 id_766 { id_765[id_762] };
                      std::string id_767 { std::get<1>(id_766) };
                      uint32_t id_768 { (uint32_t)id_767.size() };
                      Size let_res_769;
                      {
                        uint32_t wlen_265 { id_768 };
                        Vec<1, uint32_t> id_770 {  wlen_265  };
                        Size let_res_771;
                        {
                          Vec<1, uint32_t> n_ref_266 { id_770 };
                          uint32_t id_772 { 1U };
                          Vec<1, uint32_t> id_773 {  id_772  };
                          Size let_res_774;
                          {
                            Vec<1, uint32_t> lebsz_ref_267 { id_773 };
                            bool while_flag_775 { true };
                            do {
                              uint8_t id_776 { 0 };
                              uint32_t id_777 { n_ref_266[id_776] };
                              uint8_t id_778 { 0 };
                              uint32_t id_779 { lebsz_ref_267[id_778] };
                              uint8_t id_780 { 7 };
                              uint32_t id_781 { uint32_t(id_779 << id_780) };
                              bool id_782 { bool(id_777 >= id_781) };
                              while_flag_775 = id_782;
                              if (while_flag_775) {
                                uint8_t id_783 { 0 };
                                uint8_t id_784 { 0 };
                                uint32_t id_785 { lebsz_ref_267[id_784] };
                                uint32_t id_786 { 1U };
                                uint32_t id_787 { uint32_t(id_785 + id_786) };
                                Void id_788 { ((void)(lebsz_ref_267[id_783] = id_787), VOID) };
                                (void)id_788;
                              }
                            } while (while_flag_775);
                            (void)VOID;
                            uint8_t id_789 { 0 };
                            uint32_t id_790 { lebsz_ref_267[id_789] };
                            Size id_791 { Size(id_790) };
                            let_res_774 = id_791;
                          }
                          let_res_771 = let_res_774;
                        }
                        Size id_792 { Size(wlen_265) };
                        Size id_793 { Size(let_res_771 + id_792) };
                        let_res_769 = id_793;
                      }
                      Size id_794 { Size(sz_264 + let_res_769) };
                      let_res_760 = id_794;
                    }
                    Void id_795 { ((void)(sz_ref_258[id_722] = let_res_760), VOID) };
                    (void)id_795;
                    uint8_t id_796 { 0 };
                    uint8_t id_797 { 0 };
                    int32_t id_798 { repeat_n_259[id_797] };
                    int32_t id_799 { 1L };
                    int32_t id_800 { int32_t(id_798 + id_799) };
                    Void id_801 { ((void)(repeat_n_259[id_796] = id_800), VOID) };
                    (void)id_801;
                    (void)id_801;
                  }
                } while (while_flag_713);
                (void)VOID;
              }
              (void)VOID;
              uint8_t id_802 { 0 };
              Size id_803 { sz_ref_258[id_802] };
              let_res_710 = id_803;
            }
            Size let_res_804;
            {
              Size sz_268 { let_res_710 };
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_805 { (*p_0).via };
              ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_806 { std::get<4 /* Kafka */>(id_805) };
              std::string id_807 { id_806.topic };
              uint32_t id_808 { (uint32_t)id_807.size() };
              Vec<1, uint32_t> id_809 {  id_808  };
              Size let_res_810;
              {
                Vec<1, uint32_t> n_ref_270 { id_809 };
                uint32_t id_811 { 1U };
                Vec<1, uint32_t> id_812 {  id_811  };
                Size let_res_813;
                {
                  Vec<1, uint32_t> lebsz_ref_271 { id_812 };
                  bool while_flag_814 { true };
                  do {
                    uint8_t id_815 { 0 };
                    uint32_t id_816 { n_ref_270[id_815] };
                    uint8_t id_817 { 0 };
                    uint32_t id_818 { lebsz_ref_271[id_817] };
                    uint8_t id_819 { 7 };
                    uint32_t id_820 { uint32_t(id_818 << id_819) };
                    bool id_821 { bool(id_816 >= id_820) };
                    while_flag_814 = id_821;
                    if (while_flag_814) {
                      uint8_t id_822 { 0 };
                      uint8_t id_823 { 0 };
                      uint32_t id_824 { lebsz_ref_271[id_823] };
                      uint32_t id_825 { 1U };
                      uint32_t id_826 { uint32_t(id_824 + id_825) };
                      Void id_827 { ((void)(lebsz_ref_271[id_822] = id_826), VOID) };
                      (void)id_827;
                    }
                  } while (while_flag_814);
                  (void)VOID;
                  uint8_t id_828 { 0 };
                  uint32_t id_829 { lebsz_ref_271[id_828] };
                  Size id_830 { Size(id_829) };
                  let_res_813 = id_830;
                }
                let_res_810 = let_res_813;
              }
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_831 { (*p_0).via };
              ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_832 { std::get<4 /* Kafka */>(id_831) };
              std::string id_833 { id_832.topic };
              uint32_t id_834 { (uint32_t)id_833.size() };
              Size id_835 { Size(id_834) };
              Size id_836 { Size(let_res_810 + id_835) };
              Size id_837 { Size(sz_268 + id_836) };
              let_res_804 = id_837;
            }
            Size id_838 { 2UL };
            Size id_839 { Size(let_res_804 + id_838) };
            Size let_res_840;
            {
              Size sz_273 { id_839 };
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_841 { (*p_0).via };
              ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_842 { std::get<4 /* Kafka */>(id_841) };
              std::string id_843 { id_842.text };
              uint32_t id_844 { (uint32_t)id_843.size() };
              Vec<1, uint32_t> id_845 {  id_844  };
              Size let_res_846;
              {
                Vec<1, uint32_t> n_ref_275 { id_845 };
                uint32_t id_847 { 1U };
                Vec<1, uint32_t> id_848 {  id_847  };
                Size let_res_849;
                {
                  Vec<1, uint32_t> lebsz_ref_276 { id_848 };
                  bool while_flag_850 { true };
                  do {
                    uint8_t id_851 { 0 };
                    uint32_t id_852 { n_ref_275[id_851] };
                    uint8_t id_853 { 0 };
                    uint32_t id_854 { lebsz_ref_276[id_853] };
                    uint8_t id_855 { 7 };
                    uint32_t id_856 { uint32_t(id_854 << id_855) };
                    bool id_857 { bool(id_852 >= id_856) };
                    while_flag_850 = id_857;
                    if (while_flag_850) {
                      uint8_t id_858 { 0 };
                      uint8_t id_859 { 0 };
                      uint32_t id_860 { lebsz_ref_276[id_859] };
                      uint32_t id_861 { 1U };
                      uint32_t id_862 { uint32_t(id_860 + id_861) };
                      Void id_863 { ((void)(lebsz_ref_276[id_858] = id_862), VOID) };
                      (void)id_863;
                    }
                  } while (while_flag_850);
                  (void)VOID;
                  uint8_t id_864 { 0 };
                  uint32_t id_865 { lebsz_ref_276[id_864] };
                  Size id_866 { Size(id_865) };
                  let_res_849 = id_866;
                }
                let_res_846 = let_res_849;
              }
              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_867 { (*p_0).via };
              ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_868 { std::get<4 /* Kafka */>(id_867) };
              std::string id_869 { id_868.text };
              uint32_t id_870 { (uint32_t)id_869.size() };
              Size id_871 { Size(id_870) };
              Size id_872 { Size(let_res_846 + id_871) };
              Size id_873 { Size(sz_273 + id_872) };
              let_res_840 = id_873;
            }
            choose_res_573 = let_res_840;
          }
          choose_res_536 = choose_res_573;
        }
        choose_res_499 = choose_res_536;
      }
      choose_res_493 = choose_res_499;
    }
    Size id_874 { 8UL };
    Size id_875 { Size(choose_res_493 + id_874) };
    return id_875;
  }
   };
  return fun488;
}
std::function<Size(::dessser::gen::alerting_contact::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_241"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (make-tup
                (construct "[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" 0 (nop))
                (identifier "dsum1_snd_64"))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (let "dstring1_229"
                  (let "leb_ref_223" (make-vec (u32 0))
                    (let "shft_ref_224" (make-vec (u8 0))
                      (let "p_ref_225" (make-vec (identifier "dsum1_snd_64"))
                        (seq
                          (while
                            (let "leb128_226" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_225")))
                              (let-pair "leb128_fst_227" "leb128_snd_228" 
                                (identifier "leb128_226")
                                (seq (set-vec (u8 0) (identifier "p_ref_225") (identifier "leb128_snd_228"))
                                  (set-vec (u8 0) (identifier "leb_ref_223")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_227") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_224"))) (unsafe-nth (u8 0) (identifier "leb_ref_223"))))
                                  (set-vec (u8 0) (identifier "shft_ref_224") (add (unsafe-nth (u8 0) (identifier "shft_ref_224")) (u8 7))) 
                                  (ge (identifier "leb128_fst_227") (u8 128))))) 
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_223"))) (unsafe-nth (u8 0) (identifier "p_ref_225")))))))
                  (let-pair "dstring1_fst_230" "dstring1_snd_231" (identifier "dstring1_229")
                    (let-pair "dstring2_fst_233" "dstring2_snd_234" (read-bytes (identifier "dstring1_snd_231") (identifier "dstring1_fst_230"))
                      (make-tup
                        (construct "[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" 1
                          (string-of-bytes (identifier "dstring2_fst_233"))) 
                        (identifier "dstring2_snd_234")))))
                (if (eq (u16 2) (identifier "dsum1_fst_63"))
                  (let "dstring1_214"
                    (let "leb_ref_208" (make-vec (u32 0))
                      (let "shft_ref_209" (make-vec (u8 0))
                        (let "p_ref_210" (make-vec (identifier "dsum1_snd_64"))
                          (seq
                            (while
                              (let "leb128_211" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_210")))
                                (let-pair "leb128_fst_212" "leb128_snd_213" 
                                  (identifier "leb128_211")
                                  (seq (set-vec (u8 0) (identifier "p_ref_210") (identifier "leb128_snd_213"))
                                    (set-vec (u8 0) (identifier "leb_ref_208")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_212") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_209"))) (unsafe-nth (u8 0) (identifier "leb_ref_208"))))
                                    (set-vec (u8 0) (identifier "shft_ref_209") (add (unsafe-nth (u8 0) (identifier "shft_ref_209")) (u8 7))) 
                                    (ge (identifier "leb128_fst_212") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_208"))) (unsafe-nth (u8 0) (identifier "p_ref_210")))))))
                    (let-pair "dstring1_fst_215" "dstring1_snd_216" (identifier "dstring1_214")
                      (let-pair "dstring2_fst_218" "dstring2_snd_219" 
                        (read-bytes (identifier "dstring1_snd_216") (identifier "dstring1_fst_215"))
                        (make-tup
                          (construct "[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" 2
                            (string-of-bytes (identifier "dstring2_fst_218"))) 
                          (identifier "dstring2_snd_219")))))
                  (if (eq (u16 3) (identifier "dsum1_fst_63"))
                    (let "drec_172"
                      (let "dstring1_166"
                        (let "leb_ref_160" (make-vec (u32 0))
                          (let "shft_ref_161" (make-vec (u8 0))
                            (let "p_ref_162" (make-vec (identifier "dsum1_snd_64"))
                              (seq
                                (while
                                  (let "leb128_163" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_162")))
                                    (let-pair "leb128_fst_164" "leb128_snd_165" 
                                      (identifier "leb128_163")
                                      (seq (set-vec (u8 0) (identifier "p_ref_162") (identifier "leb128_snd_165"))
                                        (set-vec (u8 0) (identifier "leb_ref_160")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_164") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_161"))) (unsafe-nth (u8 0) (identifier "leb_ref_160"))))
                                        (set-vec (u8 0) (identifier "shft_ref_161") (add (unsafe-nth (u8 0) (identifier "shft_ref_161")) (u8 7))) 
                                        (ge (identifier "leb128_fst_164") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_160"))) (unsafe-nth (u8 0) (identifier "p_ref_162")))))))
                        (let-pair "dstring1_fst_167" "dstring1_snd_168" 
                          (identifier "dstring1_166")
                          (let-pair "dstring2_fst_170" "dstring2_snd_171" 
                            (read-bytes (identifier "dstring1_snd_168") (identifier "dstring1_fst_167")) 
                            (make-tup (string-of-bytes (identifier "dstring2_fst_170")) (identifier "dstring2_snd_171")))))
                      (let-pair "drec_fst_173" "drec_snd_174" (identifier "drec_172")
                        (let "drec_187"
                          (let "dstring1_181"
                            (let "leb_ref_175" (make-vec (u32 0))
                              (let "shft_ref_176" (make-vec (u8 0))
                                (let "p_ref_177" (make-vec (identifier "drec_snd_174"))
                                  (seq
                                    (while
                                      (let "leb128_178" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_177")))
                                        (let-pair "leb128_fst_179" "leb128_snd_180" 
                                          (identifier "leb128_178")
                                          (seq (set-vec (u8 0) (identifier "p_ref_177") (identifier "leb128_snd_180"))
                                            (set-vec (u8 0) (identifier "leb_ref_175")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_179") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_176"))) (unsafe-nth (u8 0) (identifier "leb_ref_175"))))
                                            (set-vec (u8 0) (identifier "shft_ref_176") (add (unsafe-nth (u8 0) (identifier "shft_ref_176")) (u8 7))) 
                                            (ge (identifier "leb128_fst_179") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_175"))) (unsafe-nth (u8 0) (identifier "p_ref_177")))))))
                            (let-pair "dstring1_fst_182" "dstring1_snd_183" 
                              (identifier "dstring1_181")
                              (let-pair "dstring2_fst_185" "dstring2_snd_186" 
                                (read-bytes (identifier "dstring1_snd_183") (identifier "dstring1_fst_182")) 
                                (make-tup (string-of-bytes (identifier "dstring2_fst_185")) (identifier "dstring2_snd_186")))))
                          (let-pair "drec_fst_188" "drec_snd_189" (identifier "drec_187")
                            (let "dstring1_196"
                              (let "leb_ref_190" (make-vec (u32 0))
                                (let "shft_ref_191" (make-vec (u8 0))
                                  (let "p_ref_192" (make-vec (identifier "drec_snd_189"))
                                    (seq
                                      (while
                                        (let "leb128_193" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_192")))
                                          (let-pair "leb128_fst_194" "leb128_snd_195" 
                                            (identifier "leb128_193")
                                            (seq (set-vec (u8 0) (identifier "p_ref_192") (identifier "leb128_snd_195"))
                                              (set-vec (u8 0) (identifier "leb_ref_190")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_194") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_191"))) (unsafe-nth (u8 0) (identifier "leb_ref_190"))))
                                              (set-vec (u8 0) (identifier "shft_ref_191") (add (unsafe-nth (u8 0) (identifier "shft_ref_191")) (u8 7))) 
                                              (ge (identifier "leb128_fst_194") (u8 128))))) 
                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_190"))) (unsafe-nth (u8 0) (identifier "p_ref_192")))))))
                              (let-pair "dstring1_fst_197" "dstring1_snd_198" 
                                (identifier "dstring1_196")
                                (let-pair "dstring2_fst_200" "dstring2_snd_201" 
                                  (read-bytes (identifier "dstring1_snd_198") (identifier "dstring1_fst_197"))
                                  (make-tup
                                    (construct "[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" 3
                                      (make-rec (string "create") (string-of-bytes (identifier "dstring2_fst_200")) (string "insert") (identifier "drec_fst_188") (string "file") (identifier "drec_fst_173")))
                                    (identifier "dstring2_snd_201")))))))))
                    (seq (assert (eq (identifier "dsum1_fst_63") (u16 4)))
                      (let "drec_118"
                        (let-pair "dlist4_fst_116" "dlist4_snd_117"
                          (let "dlist1_74"
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
                                      (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_65")) (unsafe-nth (u8 0) (identifier "p_ref_67")))))))
                            (let-pair "dlist1_fst_75" "dlist1_snd_76" 
                              (identifier "dlist1_74")
                              (let "inits_src_ref_77" (make-vec (make-tup (end-of-list "(STRING; STRING)") (identifier "dlist1_snd_76")))
                                (seq
                                  (let "repeat_n_78" (make-vec (i32 0))
                                    (while (gt (to-i32 (identifier "dlist1_fst_75")) (unsafe-nth (u8 0) (identifier "repeat_n_78")))
                                      (seq
                                        (let "dlist2_79" (unsafe-nth (u8 0) (identifier "inits_src_ref_77"))
                                          (let-pair "dlist2_fst_80" "dlist2_snd_81" 
                                            (identifier "dlist2_79")
                                            (set-vec (u8 0) (identifier "inits_src_ref_77")
                                              (let "dtup_94"
                                                (let "dstring1_88"
                                                  (let "leb_ref_82" (make-vec (u32 0))
                                                    (let "shft_ref_83" 
                                                      (make-vec (u8 0))
                                                      (let "p_ref_84" 
                                                        (make-vec (identifier "dlist2_snd_81"))
                                                        (seq
                                                          (while
                                                            (let "leb128_85" 
                                                              (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_84")))
                                                              (let-pair "leb128_fst_86" "leb128_snd_87" 
                                                                (identifier "leb128_85")
                                                                (seq 
                                                                  (set-vec (u8 0) (identifier "p_ref_84") (identifier "leb128_snd_87"))
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_82")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_86") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_83")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_82")))) 
                                                                  (set-vec (u8 0) (identifier "shft_ref_83") (add (unsafe-nth (u8 0) (identifier "shft_ref_83")) (u8 7))) 
                                                                  (ge (identifier "leb128_fst_86") (u8 128))))) 
                                                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_82"))) (unsafe-nth (u8 0) (identifier "p_ref_84")))))))
                                                  (let-pair "dstring1_fst_89" "dstring1_snd_90" 
                                                    (identifier "dstring1_88")
                                                    (let-pair "dstring2_fst_92" "dstring2_snd_93" 
                                                      (read-bytes (identifier "dstring1_snd_90") (identifier "dstring1_fst_89")) 
                                                      (make-tup (string-of-bytes (identifier "dstring2_fst_92")) (identifier "dstring2_snd_93")))))
                                                (let-pair "dtup_fst_95" "dtup_snd_96" 
                                                  (identifier "dtup_94")
                                                  (let "dstring1_103"
                                                    (let "leb_ref_97" 
                                                      (make-vec (u32 0))
                                                      (let "shft_ref_98" 
                                                        (make-vec (u8 0))
                                                        (let "p_ref_99" 
                                                          (make-vec (identifier "dtup_snd_96"))
                                                          (seq
                                                            (while
                                                              (let "leb128_100" 
                                                                (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_99")))
                                                                (let-pair "leb128_fst_101" "leb128_snd_102" 
                                                                  (identifier "leb128_100")
                                                                  (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_99") (identifier "leb128_snd_102"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_97")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_101") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_98")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_97")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_98") (add (unsafe-nth (u8 0) (identifier "shft_ref_98")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_101") (u8 128))))) 
                                                              (nop)) 
                                                            (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_97"))) (unsafe-nth (u8 0) (identifier "p_ref_99")))))))
                                                    (let-pair "dstring1_fst_104" "dstring1_snd_105" 
                                                      (identifier "dstring1_103")
                                                      (let-pair "dstring2_fst_107" "dstring2_snd_108" 
                                                        (read-bytes (identifier "dstring1_snd_105") (identifier "dstring1_fst_104"))
                                                        (make-tup (cons (make-tup (identifier "dtup_fst_95") (string-of-bytes (identifier "dstring2_fst_107"))) (identifier "dlist2_fst_80")) (identifier "dstring2_snd_108"))))))))))
                                        (set-vec (u8 0) (identifier "repeat_n_78") (add (unsafe-nth (u8 0) (identifier "repeat_n_78")) (i32 1)))))) 
                                  (unsafe-nth (u8 0) (identifier "inits_src_ref_77")))))) 
                          (make-tup (identity (identifier "dlist4_fst_116")) (identifier "dlist4_snd_117")))
                        (let-pair "drec_fst_119" "drec_snd_120" (identifier "drec_118")
                          (let "drec_133"
                            (let "dstring1_127"
                              (let "leb_ref_121" (make-vec (u32 0))
                                (let "shft_ref_122" (make-vec (u8 0))
                                  (let "p_ref_123" (make-vec (identifier "drec_snd_120"))
                                    (seq
                                      (while
                                        (let "leb128_124" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_123")))
                                          (let-pair "leb128_fst_125" "leb128_snd_126" 
                                            (identifier "leb128_124")
                                            (seq (set-vec (u8 0) (identifier "p_ref_123") (identifier "leb128_snd_126"))
                                              (set-vec (u8 0) (identifier "leb_ref_121")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_125") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_122"))) (unsafe-nth (u8 0) (identifier "leb_ref_121"))))
                                              (set-vec (u8 0) (identifier "shft_ref_122") (add (unsafe-nth (u8 0) (identifier "shft_ref_122")) (u8 7))) 
                                              (ge (identifier "leb128_fst_125") (u8 128))))) 
                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_121"))) (unsafe-nth (u8 0) (identifier "p_ref_123")))))))
                              (let-pair "dstring1_fst_128" "dstring1_snd_129" 
                                (identifier "dstring1_127")
                                (let-pair "dstring2_fst_131" "dstring2_snd_132" 
                                  (read-bytes (identifier "dstring1_snd_129") (identifier "dstring1_fst_128")) 
                                  (make-tup (string-of-bytes (identifier "dstring2_fst_131")) (identifier "dstring2_snd_132")))))
                            (let-pair "drec_fst_134" "drec_snd_135" (identifier "drec_133")
                              (let "drec_139" (let-pair "du16_fst_137" "du16_snd_138" (read-u16 little-endian (identifier "drec_snd_135")) (make-tup (identifier "du16_fst_137") (identifier "du16_snd_138")))
                                (let-pair "drec_fst_140" "drec_snd_141" 
                                  (identifier "drec_139")
                                  (let "dstring1_148"
                                    (let "leb_ref_142" (make-vec (u32 0))
                                      (let "shft_ref_143" (make-vec (u8 0))
                                        (let "p_ref_144" (make-vec (identifier "drec_snd_141"))
                                          (seq
                                            (while
                                              (let "leb128_145" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_144")))
                                                (let-pair "leb128_fst_146" "leb128_snd_147" 
                                                  (identifier "leb128_145")
                                                  (seq (set-vec (u8 0) (identifier "p_ref_144") (identifier "leb128_snd_147"))
                                                    (set-vec (u8 0) (identifier "leb_ref_142")
                                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_146") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_143"))) (unsafe-nth (u8 0) (identifier "leb_ref_142"))))
                                                    (set-vec (u8 0) (identifier "shft_ref_143") (add (unsafe-nth (u8 0) (identifier "shft_ref_143")) (u8 7))) 
                                                    (ge (identifier "leb128_fst_146") (u8 128))))) 
                                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_142"))) (unsafe-nth (u8 0) (identifier "p_ref_144")))))))
                                    (let-pair "dstring1_fst_149" "dstring1_snd_150" 
                                      (identifier "dstring1_148")
                                      (let-pair "dstring2_fst_152" "dstring2_snd_153" 
                                        (read-bytes (identifier "dstring1_snd_150") (identifier "dstring1_fst_149"))
                                        (make-tup
                                          (construct "[Ignore Void | Exec STRING | SysLog STRING | Sqlite {file: STRING; insert: STRING; create: STRING} | Kafka {options: (STRING; STRING)[[]]; topic: STRING; partition: U16; text: STRING}]" 4
                                            (make-rec (string "text") 
                                              (string-of-bytes (identifier "dstring2_fst_152")) 
                                              (string "partition") (identifier "drec_fst_140") 
                                              (string "topic") (identifier "drec_fst_134") 
                                              (string "options") (identifier "drec_fst_119"))) 
                                          (identifier "dstring2_snd_153"))))))))))))))))))
        (let-pair "drec_fst_242" "drec_snd_243" (identifier "drec_241")
          (let-pair "dfloat_fst_245" "dfloat_snd_246" (read-u64 little-endian (identifier "drec_snd_243"))
            (make-tup (make-rec (string "timeout") (float-of-u64 (identifier "dfloat_fst_245")) (string "via") (identifier "drec_fst_242")) (identifier "dfloat_snd_246"))))))
 */
static std::function<::dessser::gen::alerting_contact::t6895345151933b08a9380e7a927036c0(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::alerting_contact::t6895345151933b08a9380e7a927036c0(Pointer)> fun876 { [&fun876](Pointer p_0) {
    ::dessser::gen::alerting_contact::t22a32080ad88ab548b80077a17b7dd46 id_877 { p_0.readU16Le() };
    ::dessser::gen::alerting_contact::t22a32080ad88ab548b80077a17b7dd46 letpair_res_878;
    {
      auto du16_fst_57 { std::get<0>(id_877) };
      auto du16_snd_58 { std::get<1>(id_877) };
      ::dessser::gen::alerting_contact::t22a32080ad88ab548b80077a17b7dd46 id_879 { du16_fst_57, du16_snd_58 };
      letpair_res_878 = id_879;
    }
    ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 let_res_880;
    {
      ::dessser::gen::alerting_contact::t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_878 };
      ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_881;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_882 { 0 };
        bool id_883 { bool(id_882 == dsum1_fst_63) };
        ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 choose_res_884;
        if (id_883) {
          (void)VOID;
          ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_885 { std::in_place_index<0>, VOID };
          ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 id_886 { id_885, dsum1_snd_64 };
          choose_res_884 = id_886;
        } else {
          uint16_t id_887 { 1 };
          bool id_888 { bool(id_887 == dsum1_fst_63) };
          ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 choose_res_889;
          if (id_888) {
            uint32_t id_890 { 0U };
            Vec<1, uint32_t> id_891 {  id_890  };
            ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_892;
            {
              Vec<1, uint32_t> leb_ref_223 { id_891 };
              uint8_t id_893 { 0 };
              Vec<1, uint8_t> id_894 {  id_893  };
              ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_895;
              {
                Vec<1, uint8_t> shft_ref_224 { id_894 };
                Vec<1, Pointer> id_896 {  dsum1_snd_64  };
                ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_897;
                {
                  Vec<1, Pointer> p_ref_225 { id_896 };
                  bool while_flag_898 { true };
                  do {
                    uint8_t id_899 { 0 };
                    Pointer id_900 { p_ref_225[id_899] };
                    ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 id_901 { id_900.readU8() };
                    bool let_res_902;
                    {
                      ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 leb128_226 { id_901 };
                      bool letpair_res_903;
                      {
                        auto leb128_fst_227 { std::get<0>(leb128_226) };
                        auto leb128_snd_228 { std::get<1>(leb128_226) };
                        uint8_t id_904 { 0 };
                        Void id_905 { ((void)(p_ref_225[id_904] = leb128_snd_228), VOID) };
                        (void)id_905;
                        uint8_t id_906 { 0 };
                        uint8_t id_907 { 127 };
                        uint8_t id_908 { uint8_t(leb128_fst_227 & id_907) };
                        uint32_t id_909 { uint32_t(id_908) };
                        uint8_t id_910 { 0 };
                        uint8_t id_911 { shft_ref_224[id_910] };
                        uint32_t id_912 { uint32_t(id_909 << id_911) };
                        uint8_t id_913 { 0 };
                        uint32_t id_914 { leb_ref_223[id_913] };
                        uint32_t id_915 { uint32_t(id_912 | id_914) };
                        Void id_916 { ((void)(leb_ref_223[id_906] = id_915), VOID) };
                        (void)id_916;
                        uint8_t id_917 { 0 };
                        uint8_t id_918 { 0 };
                        uint8_t id_919 { shft_ref_224[id_918] };
                        uint8_t id_920 { 7 };
                        uint8_t id_921 { uint8_t(id_919 + id_920) };
                        Void id_922 { ((void)(shft_ref_224[id_917] = id_921), VOID) };
                        (void)id_922;
                        uint8_t id_923 { 128 };
                        bool id_924 { bool(leb128_fst_227 >= id_923) };
                        letpair_res_903 = id_924;
                      }
                      let_res_902 = letpair_res_903;
                    }
                    while_flag_898 = let_res_902;
                    if (while_flag_898) {
                      (void)VOID;
                    }
                  } while (while_flag_898);
                  (void)VOID;
                  uint8_t id_925 { 0 };
                  uint32_t id_926 { leb_ref_223[id_925] };
                  Size id_927 { Size(id_926) };
                  uint8_t id_928 { 0 };
                  Pointer id_929 { p_ref_225[id_928] };
                  ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c id_930 { id_927, id_929 };
                  let_res_897 = id_930;
                }
                let_res_895 = let_res_897;
              }
              let_res_892 = let_res_895;
            }
            ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 let_res_931;
            {
              ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c dstring1_229 { let_res_892 };
              ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_932;
              {
                auto dstring1_fst_230 { std::get<0>(dstring1_229) };
                auto dstring1_snd_231 { std::get<1>(dstring1_229) };
                ::dessser::gen::alerting_contact::t188345aa49abd0cb47ff73fedc219f08 id_933 { dstring1_snd_231.readBytes(dstring1_fst_230) };
                ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_934;
                {
                  auto dstring2_fst_233 { std::get<0>(id_933) };
                  auto dstring2_snd_234 { std::get<1>(id_933) };
                  std::string id_935 { dstring2_fst_233.toString() };
                  ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_936 { std::in_place_index<1>, id_935 };
                  ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 id_937 { id_936, dstring2_snd_234 };
                  letpair_res_934 = id_937;
                }
                letpair_res_932 = letpair_res_934;
              }
              let_res_931 = letpair_res_932;
            }
            choose_res_889 = let_res_931;
          } else {
            uint16_t id_938 { 2 };
            bool id_939 { bool(id_938 == dsum1_fst_63) };
            ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 choose_res_940;
            if (id_939) {
              uint32_t id_941 { 0U };
              Vec<1, uint32_t> id_942 {  id_941  };
              ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_943;
              {
                Vec<1, uint32_t> leb_ref_208 { id_942 };
                uint8_t id_944 { 0 };
                Vec<1, uint8_t> id_945 {  id_944  };
                ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_946;
                {
                  Vec<1, uint8_t> shft_ref_209 { id_945 };
                  Vec<1, Pointer> id_947 {  dsum1_snd_64  };
                  ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_948;
                  {
                    Vec<1, Pointer> p_ref_210 { id_947 };
                    bool while_flag_949 { true };
                    do {
                      uint8_t id_950 { 0 };
                      Pointer id_951 { p_ref_210[id_950] };
                      ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 id_952 { id_951.readU8() };
                      bool let_res_953;
                      {
                        ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 leb128_211 { id_952 };
                        bool letpair_res_954;
                        {
                          auto leb128_fst_212 { std::get<0>(leb128_211) };
                          auto leb128_snd_213 { std::get<1>(leb128_211) };
                          uint8_t id_955 { 0 };
                          Void id_956 { ((void)(p_ref_210[id_955] = leb128_snd_213), VOID) };
                          (void)id_956;
                          uint8_t id_957 { 0 };
                          uint8_t id_958 { 127 };
                          uint8_t id_959 { uint8_t(leb128_fst_212 & id_958) };
                          uint32_t id_960 { uint32_t(id_959) };
                          uint8_t id_961 { 0 };
                          uint8_t id_962 { shft_ref_209[id_961] };
                          uint32_t id_963 { uint32_t(id_960 << id_962) };
                          uint8_t id_964 { 0 };
                          uint32_t id_965 { leb_ref_208[id_964] };
                          uint32_t id_966 { uint32_t(id_963 | id_965) };
                          Void id_967 { ((void)(leb_ref_208[id_957] = id_966), VOID) };
                          (void)id_967;
                          uint8_t id_968 { 0 };
                          uint8_t id_969 { 0 };
                          uint8_t id_970 { shft_ref_209[id_969] };
                          uint8_t id_971 { 7 };
                          uint8_t id_972 { uint8_t(id_970 + id_971) };
                          Void id_973 { ((void)(shft_ref_209[id_968] = id_972), VOID) };
                          (void)id_973;
                          uint8_t id_974 { 128 };
                          bool id_975 { bool(leb128_fst_212 >= id_974) };
                          letpair_res_954 = id_975;
                        }
                        let_res_953 = letpair_res_954;
                      }
                      while_flag_949 = let_res_953;
                      if (while_flag_949) {
                        (void)VOID;
                      }
                    } while (while_flag_949);
                    (void)VOID;
                    uint8_t id_976 { 0 };
                    uint32_t id_977 { leb_ref_208[id_976] };
                    Size id_978 { Size(id_977) };
                    uint8_t id_979 { 0 };
                    Pointer id_980 { p_ref_210[id_979] };
                    ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c id_981 { id_978, id_980 };
                    let_res_948 = id_981;
                  }
                  let_res_946 = let_res_948;
                }
                let_res_943 = let_res_946;
              }
              ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 let_res_982;
              {
                ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c dstring1_214 { let_res_943 };
                ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_983;
                {
                  auto dstring1_fst_215 { std::get<0>(dstring1_214) };
                  auto dstring1_snd_216 { std::get<1>(dstring1_214) };
                  ::dessser::gen::alerting_contact::t188345aa49abd0cb47ff73fedc219f08 id_984 { dstring1_snd_216.readBytes(dstring1_fst_215) };
                  ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_985;
                  {
                    auto dstring2_fst_218 { std::get<0>(id_984) };
                    auto dstring2_snd_219 { std::get<1>(id_984) };
                    std::string id_986 { dstring2_fst_218.toString() };
                    ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_987 { std::in_place_index<2>, id_986 };
                    ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 id_988 { id_987, dstring2_snd_219 };
                    letpair_res_985 = id_988;
                  }
                  letpair_res_983 = letpair_res_985;
                }
                let_res_982 = letpair_res_983;
              }
              choose_res_940 = let_res_982;
            } else {
              uint16_t id_989 { 3 };
              bool id_990 { bool(id_989 == dsum1_fst_63) };
              ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 choose_res_991;
              if (id_990) {
                uint32_t id_992 { 0U };
                Vec<1, uint32_t> id_993 {  id_992  };
                ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_994;
                {
                  Vec<1, uint32_t> leb_ref_160 { id_993 };
                  uint8_t id_995 { 0 };
                  Vec<1, uint8_t> id_996 {  id_995  };
                  ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_997;
                  {
                    Vec<1, uint8_t> shft_ref_161 { id_996 };
                    Vec<1, Pointer> id_998 {  dsum1_snd_64  };
                    ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_999;
                    {
                      Vec<1, Pointer> p_ref_162 { id_998 };
                      bool while_flag_1000 { true };
                      do {
                        uint8_t id_1001 { 0 };
                        Pointer id_1002 { p_ref_162[id_1001] };
                        ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 id_1003 { id_1002.readU8() };
                        bool let_res_1004;
                        {
                          ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 leb128_163 { id_1003 };
                          bool letpair_res_1005;
                          {
                            auto leb128_fst_164 { std::get<0>(leb128_163) };
                            auto leb128_snd_165 { std::get<1>(leb128_163) };
                            uint8_t id_1006 { 0 };
                            Void id_1007 { ((void)(p_ref_162[id_1006] = leb128_snd_165), VOID) };
                            (void)id_1007;
                            uint8_t id_1008 { 0 };
                            uint8_t id_1009 { 127 };
                            uint8_t id_1010 { uint8_t(leb128_fst_164 & id_1009) };
                            uint32_t id_1011 { uint32_t(id_1010) };
                            uint8_t id_1012 { 0 };
                            uint8_t id_1013 { shft_ref_161[id_1012] };
                            uint32_t id_1014 { uint32_t(id_1011 << id_1013) };
                            uint8_t id_1015 { 0 };
                            uint32_t id_1016 { leb_ref_160[id_1015] };
                            uint32_t id_1017 { uint32_t(id_1014 | id_1016) };
                            Void id_1018 { ((void)(leb_ref_160[id_1008] = id_1017), VOID) };
                            (void)id_1018;
                            uint8_t id_1019 { 0 };
                            uint8_t id_1020 { 0 };
                            uint8_t id_1021 { shft_ref_161[id_1020] };
                            uint8_t id_1022 { 7 };
                            uint8_t id_1023 { uint8_t(id_1021 + id_1022) };
                            Void id_1024 { ((void)(shft_ref_161[id_1019] = id_1023), VOID) };
                            (void)id_1024;
                            uint8_t id_1025 { 128 };
                            bool id_1026 { bool(leb128_fst_164 >= id_1025) };
                            letpair_res_1005 = id_1026;
                          }
                          let_res_1004 = letpair_res_1005;
                        }
                        while_flag_1000 = let_res_1004;
                        if (while_flag_1000) {
                          (void)VOID;
                        }
                      } while (while_flag_1000);
                      (void)VOID;
                      uint8_t id_1027 { 0 };
                      uint32_t id_1028 { leb_ref_160[id_1027] };
                      Size id_1029 { Size(id_1028) };
                      uint8_t id_1030 { 0 };
                      Pointer id_1031 { p_ref_162[id_1030] };
                      ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c id_1032 { id_1029, id_1031 };
                      let_res_999 = id_1032;
                    }
                    let_res_997 = let_res_999;
                  }
                  let_res_994 = let_res_997;
                }
                ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e let_res_1033;
                {
                  ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c dstring1_166 { let_res_994 };
                  ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1034;
                  {
                    auto dstring1_fst_167 { std::get<0>(dstring1_166) };
                    auto dstring1_snd_168 { std::get<1>(dstring1_166) };
                    ::dessser::gen::alerting_contact::t188345aa49abd0cb47ff73fedc219f08 id_1035 { dstring1_snd_168.readBytes(dstring1_fst_167) };
                    ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1036;
                    {
                      auto dstring2_fst_170 { std::get<0>(id_1035) };
                      auto dstring2_snd_171 { std::get<1>(id_1035) };
                      std::string id_1037 { dstring2_fst_170.toString() };
                      ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e id_1038 { id_1037, dstring2_snd_171 };
                      letpair_res_1036 = id_1038;
                    }
                    letpair_res_1034 = letpair_res_1036;
                  }
                  let_res_1033 = letpair_res_1034;
                }
                ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 let_res_1039;
                {
                  ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e drec_172 { let_res_1033 };
                  ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_1040;
                  {
                    auto drec_fst_173 { std::get<0>(drec_172) };
                    auto drec_snd_174 { std::get<1>(drec_172) };
                    uint32_t id_1041 { 0U };
                    Vec<1, uint32_t> id_1042 {  id_1041  };
                    ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1043;
                    {
                      Vec<1, uint32_t> leb_ref_175 { id_1042 };
                      uint8_t id_1044 { 0 };
                      Vec<1, uint8_t> id_1045 {  id_1044  };
                      ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1046;
                      {
                        Vec<1, uint8_t> shft_ref_176 { id_1045 };
                        Vec<1, Pointer> id_1047 {  drec_snd_174  };
                        ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1048;
                        {
                          Vec<1, Pointer> p_ref_177 { id_1047 };
                          bool while_flag_1049 { true };
                          do {
                            uint8_t id_1050 { 0 };
                            Pointer id_1051 { p_ref_177[id_1050] };
                            ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 id_1052 { id_1051.readU8() };
                            bool let_res_1053;
                            {
                              ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 leb128_178 { id_1052 };
                              bool letpair_res_1054;
                              {
                                auto leb128_fst_179 { std::get<0>(leb128_178) };
                                auto leb128_snd_180 { std::get<1>(leb128_178) };
                                uint8_t id_1055 { 0 };
                                Void id_1056 { ((void)(p_ref_177[id_1055] = leb128_snd_180), VOID) };
                                (void)id_1056;
                                uint8_t id_1057 { 0 };
                                uint8_t id_1058 { 127 };
                                uint8_t id_1059 { uint8_t(leb128_fst_179 & id_1058) };
                                uint32_t id_1060 { uint32_t(id_1059) };
                                uint8_t id_1061 { 0 };
                                uint8_t id_1062 { shft_ref_176[id_1061] };
                                uint32_t id_1063 { uint32_t(id_1060 << id_1062) };
                                uint8_t id_1064 { 0 };
                                uint32_t id_1065 { leb_ref_175[id_1064] };
                                uint32_t id_1066 { uint32_t(id_1063 | id_1065) };
                                Void id_1067 { ((void)(leb_ref_175[id_1057] = id_1066), VOID) };
                                (void)id_1067;
                                uint8_t id_1068 { 0 };
                                uint8_t id_1069 { 0 };
                                uint8_t id_1070 { shft_ref_176[id_1069] };
                                uint8_t id_1071 { 7 };
                                uint8_t id_1072 { uint8_t(id_1070 + id_1071) };
                                Void id_1073 { ((void)(shft_ref_176[id_1068] = id_1072), VOID) };
                                (void)id_1073;
                                uint8_t id_1074 { 128 };
                                bool id_1075 { bool(leb128_fst_179 >= id_1074) };
                                letpair_res_1054 = id_1075;
                              }
                              let_res_1053 = letpair_res_1054;
                            }
                            while_flag_1049 = let_res_1053;
                            if (while_flag_1049) {
                              (void)VOID;
                            }
                          } while (while_flag_1049);
                          (void)VOID;
                          uint8_t id_1076 { 0 };
                          uint32_t id_1077 { leb_ref_175[id_1076] };
                          Size id_1078 { Size(id_1077) };
                          uint8_t id_1079 { 0 };
                          Pointer id_1080 { p_ref_177[id_1079] };
                          ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c id_1081 { id_1078, id_1080 };
                          let_res_1048 = id_1081;
                        }
                        let_res_1046 = let_res_1048;
                      }
                      let_res_1043 = let_res_1046;
                    }
                    ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e let_res_1082;
                    {
                      ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c dstring1_181 { let_res_1043 };
                      ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1083;
                      {
                        auto dstring1_fst_182 { std::get<0>(dstring1_181) };
                        auto dstring1_snd_183 { std::get<1>(dstring1_181) };
                        ::dessser::gen::alerting_contact::t188345aa49abd0cb47ff73fedc219f08 id_1084 { dstring1_snd_183.readBytes(dstring1_fst_182) };
                        ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1085;
                        {
                          auto dstring2_fst_185 { std::get<0>(id_1084) };
                          auto dstring2_snd_186 { std::get<1>(id_1084) };
                          std::string id_1086 { dstring2_fst_185.toString() };
                          ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e id_1087 { id_1086, dstring2_snd_186 };
                          letpair_res_1085 = id_1087;
                        }
                        letpair_res_1083 = letpair_res_1085;
                      }
                      let_res_1082 = letpair_res_1083;
                    }
                    ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 let_res_1088;
                    {
                      ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e drec_187 { let_res_1082 };
                      ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_1089;
                      {
                        auto drec_fst_188 { std::get<0>(drec_187) };
                        auto drec_snd_189 { std::get<1>(drec_187) };
                        uint32_t id_1090 { 0U };
                        Vec<1, uint32_t> id_1091 {  id_1090  };
                        ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1092;
                        {
                          Vec<1, uint32_t> leb_ref_190 { id_1091 };
                          uint8_t id_1093 { 0 };
                          Vec<1, uint8_t> id_1094 {  id_1093  };
                          ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1095;
                          {
                            Vec<1, uint8_t> shft_ref_191 { id_1094 };
                            Vec<1, Pointer> id_1096 {  drec_snd_189  };
                            ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1097;
                            {
                              Vec<1, Pointer> p_ref_192 { id_1096 };
                              bool while_flag_1098 { true };
                              do {
                                uint8_t id_1099 { 0 };
                                Pointer id_1100 { p_ref_192[id_1099] };
                                ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 id_1101 { id_1100.readU8() };
                                bool let_res_1102;
                                {
                                  ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 leb128_193 { id_1101 };
                                  bool letpair_res_1103;
                                  {
                                    auto leb128_fst_194 { std::get<0>(leb128_193) };
                                    auto leb128_snd_195 { std::get<1>(leb128_193) };
                                    uint8_t id_1104 { 0 };
                                    Void id_1105 { ((void)(p_ref_192[id_1104] = leb128_snd_195), VOID) };
                                    (void)id_1105;
                                    uint8_t id_1106 { 0 };
                                    uint8_t id_1107 { 127 };
                                    uint8_t id_1108 { uint8_t(leb128_fst_194 & id_1107) };
                                    uint32_t id_1109 { uint32_t(id_1108) };
                                    uint8_t id_1110 { 0 };
                                    uint8_t id_1111 { shft_ref_191[id_1110] };
                                    uint32_t id_1112 { uint32_t(id_1109 << id_1111) };
                                    uint8_t id_1113 { 0 };
                                    uint32_t id_1114 { leb_ref_190[id_1113] };
                                    uint32_t id_1115 { uint32_t(id_1112 | id_1114) };
                                    Void id_1116 { ((void)(leb_ref_190[id_1106] = id_1115), VOID) };
                                    (void)id_1116;
                                    uint8_t id_1117 { 0 };
                                    uint8_t id_1118 { 0 };
                                    uint8_t id_1119 { shft_ref_191[id_1118] };
                                    uint8_t id_1120 { 7 };
                                    uint8_t id_1121 { uint8_t(id_1119 + id_1120) };
                                    Void id_1122 { ((void)(shft_ref_191[id_1117] = id_1121), VOID) };
                                    (void)id_1122;
                                    uint8_t id_1123 { 128 };
                                    bool id_1124 { bool(leb128_fst_194 >= id_1123) };
                                    letpair_res_1103 = id_1124;
                                  }
                                  let_res_1102 = letpair_res_1103;
                                }
                                while_flag_1098 = let_res_1102;
                                if (while_flag_1098) {
                                  (void)VOID;
                                }
                              } while (while_flag_1098);
                              (void)VOID;
                              uint8_t id_1125 { 0 };
                              uint32_t id_1126 { leb_ref_190[id_1125] };
                              Size id_1127 { Size(id_1126) };
                              uint8_t id_1128 { 0 };
                              Pointer id_1129 { p_ref_192[id_1128] };
                              ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c id_1130 { id_1127, id_1129 };
                              let_res_1097 = id_1130;
                            }
                            let_res_1095 = let_res_1097;
                          }
                          let_res_1092 = let_res_1095;
                        }
                        ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 let_res_1131;
                        {
                          ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c dstring1_196 { let_res_1092 };
                          ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_1132;
                          {
                            auto dstring1_fst_197 { std::get<0>(dstring1_196) };
                            auto dstring1_snd_198 { std::get<1>(dstring1_196) };
                            ::dessser::gen::alerting_contact::t188345aa49abd0cb47ff73fedc219f08 id_1133 { dstring1_snd_198.readBytes(dstring1_fst_197) };
                            ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_1134;
                            {
                              auto dstring2_fst_200 { std::get<0>(id_1133) };
                              auto dstring2_snd_201 { std::get<1>(id_1133) };
                              std::string id_1135 { dstring2_fst_200.toString() };
                              ::dessser::gen::alerting_contact::tbe8824b6bd92590dbb49ce7f29575869 id_1136 { .create = id_1135, .file = drec_fst_173, .insert = drec_fst_188 };
                              ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_1137 { std::in_place_index<3>, id_1136 };
                              ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 id_1138 { id_1137, dstring2_snd_201 };
                              letpair_res_1134 = id_1138;
                            }
                            letpair_res_1132 = letpair_res_1134;
                          }
                          let_res_1131 = letpair_res_1132;
                        }
                        letpair_res_1089 = let_res_1131;
                      }
                      let_res_1088 = letpair_res_1089;
                    }
                    letpair_res_1040 = let_res_1088;
                  }
                  let_res_1039 = letpair_res_1040;
                }
                choose_res_991 = let_res_1039;
              } else {
                uint16_t id_1139 { 4 };
                bool id_1140 { bool(dsum1_fst_63 == id_1139) };
                Void id_1141 { ((void)(assert(id_1140)), VOID) };
                (void)id_1141;
                uint32_t id_1142 { 0U };
                Vec<1, uint32_t> id_1143 {  id_1142  };
                ::dessser::gen::alerting_contact::t405eb186408556fed8f2c41523c07d13 let_res_1144;
                {
                  Vec<1, uint32_t> leb_ref_65 { id_1143 };
                  uint8_t id_1145 { 0 };
                  Vec<1, uint8_t> id_1146 {  id_1145  };
                  ::dessser::gen::alerting_contact::t405eb186408556fed8f2c41523c07d13 let_res_1147;
                  {
                    Vec<1, uint8_t> shft_ref_66 { id_1146 };
                    Vec<1, Pointer> id_1148 {  dsum1_snd_64  };
                    ::dessser::gen::alerting_contact::t405eb186408556fed8f2c41523c07d13 let_res_1149;
                    {
                      Vec<1, Pointer> p_ref_67 { id_1148 };
                      bool while_flag_1150 { true };
                      do {
                        uint8_t id_1151 { 0 };
                        Pointer id_1152 { p_ref_67[id_1151] };
                        ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 id_1153 { id_1152.readU8() };
                        bool let_res_1154;
                        {
                          ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 leb128_68 { id_1153 };
                          bool letpair_res_1155;
                          {
                            auto leb128_fst_69 { std::get<0>(leb128_68) };
                            auto leb128_snd_70 { std::get<1>(leb128_68) };
                            uint8_t id_1156 { 0 };
                            Void id_1157 { ((void)(p_ref_67[id_1156] = leb128_snd_70), VOID) };
                            (void)id_1157;
                            uint8_t id_1158 { 0 };
                            uint8_t id_1159 { 127 };
                            uint8_t id_1160 { uint8_t(leb128_fst_69 & id_1159) };
                            uint32_t id_1161 { uint32_t(id_1160) };
                            uint8_t id_1162 { 0 };
                            uint8_t id_1163 { shft_ref_66[id_1162] };
                            uint32_t id_1164 { uint32_t(id_1161 << id_1163) };
                            uint8_t id_1165 { 0 };
                            uint32_t id_1166 { leb_ref_65[id_1165] };
                            uint32_t id_1167 { uint32_t(id_1164 | id_1166) };
                            Void id_1168 { ((void)(leb_ref_65[id_1158] = id_1167), VOID) };
                            (void)id_1168;
                            uint8_t id_1169 { 0 };
                            uint8_t id_1170 { 0 };
                            uint8_t id_1171 { shft_ref_66[id_1170] };
                            uint8_t id_1172 { 7 };
                            uint8_t id_1173 { uint8_t(id_1171 + id_1172) };
                            Void id_1174 { ((void)(shft_ref_66[id_1169] = id_1173), VOID) };
                            (void)id_1174;
                            uint8_t id_1175 { 128 };
                            bool id_1176 { bool(leb128_fst_69 >= id_1175) };
                            letpair_res_1155 = id_1176;
                          }
                          let_res_1154 = letpair_res_1155;
                        }
                        while_flag_1150 = let_res_1154;
                        if (while_flag_1150) {
                          (void)VOID;
                        }
                      } while (while_flag_1150);
                      (void)VOID;
                      uint8_t id_1177 { 0 };
                      uint32_t id_1178 { leb_ref_65[id_1177] };
                      uint8_t id_1179 { 0 };
                      Pointer id_1180 { p_ref_67[id_1179] };
                      ::dessser::gen::alerting_contact::t405eb186408556fed8f2c41523c07d13 id_1181 { id_1178, id_1180 };
                      let_res_1149 = id_1181;
                    }
                    let_res_1147 = let_res_1149;
                  }
                  let_res_1144 = let_res_1147;
                }
                ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 let_res_1182;
                {
                  ::dessser::gen::alerting_contact::t405eb186408556fed8f2c41523c07d13 dlist1_74 { let_res_1144 };
                  ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 letpair_res_1183;
                  {
                    auto dlist1_fst_75 { std::get<0>(dlist1_74) };
                    auto dlist1_snd_76 { std::get<1>(dlist1_74) };
                    Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> endoflist_1184;
                    ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 id_1185 { endoflist_1184, dlist1_snd_76 };
                    Vec<1, ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078> id_1186 {  id_1185  };
                    ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 let_res_1187;
                    {
                      Vec<1, ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078> inits_src_ref_77 { id_1186 };
                      int32_t id_1188 { 0L };
                      Vec<1, int32_t> id_1189 {  id_1188  };
                      {
                        Vec<1, int32_t> repeat_n_78 { id_1189 };
                        bool while_flag_1190 { true };
                        do {
                          int32_t id_1191 { int32_t(dlist1_fst_75) };
                          uint8_t id_1192 { 0 };
                          int32_t id_1193 { repeat_n_78[id_1192] };
                          bool id_1194 { bool(id_1191 > id_1193) };
                          while_flag_1190 = id_1194;
                          if (while_flag_1190) {
                            uint8_t id_1195 { 0 };
                            ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 id_1196 { inits_src_ref_77[id_1195] };
                            {
                              ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 dlist2_79 { id_1196 };
                              {
                                auto dlist2_fst_80 { std::get<0>(dlist2_79) };
                                auto dlist2_snd_81 { std::get<1>(dlist2_79) };
                                uint8_t id_1197 { 0 };
                                uint32_t id_1198 { 0U };
                                Vec<1, uint32_t> id_1199 {  id_1198  };
                                ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1200;
                                {
                                  Vec<1, uint32_t> leb_ref_82 { id_1199 };
                                  uint8_t id_1201 { 0 };
                                  Vec<1, uint8_t> id_1202 {  id_1201  };
                                  ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1203;
                                  {
                                    Vec<1, uint8_t> shft_ref_83 { id_1202 };
                                    Vec<1, Pointer> id_1204 {  dlist2_snd_81  };
                                    ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1205;
                                    {
                                      Vec<1, Pointer> p_ref_84 { id_1204 };
                                      bool while_flag_1206 { true };
                                      do {
                                        uint8_t id_1207 { 0 };
                                        Pointer id_1208 { p_ref_84[id_1207] };
                                        ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 id_1209 { id_1208.readU8() };
                                        bool let_res_1210;
                                        {
                                          ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 leb128_85 { id_1209 };
                                          bool letpair_res_1211;
                                          {
                                            auto leb128_fst_86 { std::get<0>(leb128_85) };
                                            auto leb128_snd_87 { std::get<1>(leb128_85) };
                                            uint8_t id_1212 { 0 };
                                            Void id_1213 { ((void)(p_ref_84[id_1212] = leb128_snd_87), VOID) };
                                            (void)id_1213;
                                            uint8_t id_1214 { 0 };
                                            uint8_t id_1215 { 127 };
                                            uint8_t id_1216 { uint8_t(leb128_fst_86 & id_1215) };
                                            uint32_t id_1217 { uint32_t(id_1216) };
                                            uint8_t id_1218 { 0 };
                                            uint8_t id_1219 { shft_ref_83[id_1218] };
                                            uint32_t id_1220 { uint32_t(id_1217 << id_1219) };
                                            uint8_t id_1221 { 0 };
                                            uint32_t id_1222 { leb_ref_82[id_1221] };
                                            uint32_t id_1223 { uint32_t(id_1220 | id_1222) };
                                            Void id_1224 { ((void)(leb_ref_82[id_1214] = id_1223), VOID) };
                                            (void)id_1224;
                                            uint8_t id_1225 { 0 };
                                            uint8_t id_1226 { 0 };
                                            uint8_t id_1227 { shft_ref_83[id_1226] };
                                            uint8_t id_1228 { 7 };
                                            uint8_t id_1229 { uint8_t(id_1227 + id_1228) };
                                            Void id_1230 { ((void)(shft_ref_83[id_1225] = id_1229), VOID) };
                                            (void)id_1230;
                                            uint8_t id_1231 { 128 };
                                            bool id_1232 { bool(leb128_fst_86 >= id_1231) };
                                            letpair_res_1211 = id_1232;
                                          }
                                          let_res_1210 = letpair_res_1211;
                                        }
                                        while_flag_1206 = let_res_1210;
                                        if (while_flag_1206) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_1206);
                                      (void)VOID;
                                      uint8_t id_1233 { 0 };
                                      uint32_t id_1234 { leb_ref_82[id_1233] };
                                      Size id_1235 { Size(id_1234) };
                                      uint8_t id_1236 { 0 };
                                      Pointer id_1237 { p_ref_84[id_1236] };
                                      ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c id_1238 { id_1235, id_1237 };
                                      let_res_1205 = id_1238;
                                    }
                                    let_res_1203 = let_res_1205;
                                  }
                                  let_res_1200 = let_res_1203;
                                }
                                ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e let_res_1239;
                                {
                                  ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c dstring1_88 { let_res_1200 };
                                  ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1240;
                                  {
                                    auto dstring1_fst_89 { std::get<0>(dstring1_88) };
                                    auto dstring1_snd_90 { std::get<1>(dstring1_88) };
                                    ::dessser::gen::alerting_contact::t188345aa49abd0cb47ff73fedc219f08 id_1241 { dstring1_snd_90.readBytes(dstring1_fst_89) };
                                    ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1242;
                                    {
                                      auto dstring2_fst_92 { std::get<0>(id_1241) };
                                      auto dstring2_snd_93 { std::get<1>(id_1241) };
                                      std::string id_1243 { dstring2_fst_92.toString() };
                                      ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e id_1244 { id_1243, dstring2_snd_93 };
                                      letpair_res_1242 = id_1244;
                                    }
                                    letpair_res_1240 = letpair_res_1242;
                                  }
                                  let_res_1239 = letpair_res_1240;
                                }
                                ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 let_res_1245;
                                {
                                  ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e dtup_94 { let_res_1239 };
                                  ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 letpair_res_1246;
                                  {
                                    auto dtup_fst_95 { std::get<0>(dtup_94) };
                                    auto dtup_snd_96 { std::get<1>(dtup_94) };
                                    uint32_t id_1247 { 0U };
                                    Vec<1, uint32_t> id_1248 {  id_1247  };
                                    ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1249;
                                    {
                                      Vec<1, uint32_t> leb_ref_97 { id_1248 };
                                      uint8_t id_1250 { 0 };
                                      Vec<1, uint8_t> id_1251 {  id_1250  };
                                      ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1252;
                                      {
                                        Vec<1, uint8_t> shft_ref_98 { id_1251 };
                                        Vec<1, Pointer> id_1253 {  dtup_snd_96  };
                                        ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1254;
                                        {
                                          Vec<1, Pointer> p_ref_99 { id_1253 };
                                          bool while_flag_1255 { true };
                                          do {
                                            uint8_t id_1256 { 0 };
                                            Pointer id_1257 { p_ref_99[id_1256] };
                                            ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 id_1258 { id_1257.readU8() };
                                            bool let_res_1259;
                                            {
                                              ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 leb128_100 { id_1258 };
                                              bool letpair_res_1260;
                                              {
                                                auto leb128_fst_101 { std::get<0>(leb128_100) };
                                                auto leb128_snd_102 { std::get<1>(leb128_100) };
                                                uint8_t id_1261 { 0 };
                                                Void id_1262 { ((void)(p_ref_99[id_1261] = leb128_snd_102), VOID) };
                                                (void)id_1262;
                                                uint8_t id_1263 { 0 };
                                                uint8_t id_1264 { 127 };
                                                uint8_t id_1265 { uint8_t(leb128_fst_101 & id_1264) };
                                                uint32_t id_1266 { uint32_t(id_1265) };
                                                uint8_t id_1267 { 0 };
                                                uint8_t id_1268 { shft_ref_98[id_1267] };
                                                uint32_t id_1269 { uint32_t(id_1266 << id_1268) };
                                                uint8_t id_1270 { 0 };
                                                uint32_t id_1271 { leb_ref_97[id_1270] };
                                                uint32_t id_1272 { uint32_t(id_1269 | id_1271) };
                                                Void id_1273 { ((void)(leb_ref_97[id_1263] = id_1272), VOID) };
                                                (void)id_1273;
                                                uint8_t id_1274 { 0 };
                                                uint8_t id_1275 { 0 };
                                                uint8_t id_1276 { shft_ref_98[id_1275] };
                                                uint8_t id_1277 { 7 };
                                                uint8_t id_1278 { uint8_t(id_1276 + id_1277) };
                                                Void id_1279 { ((void)(shft_ref_98[id_1274] = id_1278), VOID) };
                                                (void)id_1279;
                                                uint8_t id_1280 { 128 };
                                                bool id_1281 { bool(leb128_fst_101 >= id_1280) };
                                                letpair_res_1260 = id_1281;
                                              }
                                              let_res_1259 = letpair_res_1260;
                                            }
                                            while_flag_1255 = let_res_1259;
                                            if (while_flag_1255) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_1255);
                                          (void)VOID;
                                          uint8_t id_1282 { 0 };
                                          uint32_t id_1283 { leb_ref_97[id_1282] };
                                          Size id_1284 { Size(id_1283) };
                                          uint8_t id_1285 { 0 };
                                          Pointer id_1286 { p_ref_99[id_1285] };
                                          ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c id_1287 { id_1284, id_1286 };
                                          let_res_1254 = id_1287;
                                        }
                                        let_res_1252 = let_res_1254;
                                      }
                                      let_res_1249 = let_res_1252;
                                    }
                                    ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 let_res_1288;
                                    {
                                      ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c dstring1_103 { let_res_1249 };
                                      ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 letpair_res_1289;
                                      {
                                        auto dstring1_fst_104 { std::get<0>(dstring1_103) };
                                        auto dstring1_snd_105 { std::get<1>(dstring1_103) };
                                        ::dessser::gen::alerting_contact::t188345aa49abd0cb47ff73fedc219f08 id_1290 { dstring1_snd_105.readBytes(dstring1_fst_104) };
                                        ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 letpair_res_1291;
                                        {
                                          auto dstring2_fst_107 { std::get<0>(id_1290) };
                                          auto dstring2_snd_108 { std::get<1>(id_1290) };
                                          std::string id_1292 { dstring2_fst_107.toString() };
                                          ::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4 id_1293 { dtup_fst_95, id_1292 };
                                          Lst<::dessser::gen::alerting_contact::t8961925d22ebc35140986110e41bc2a4> id_1294 { id_1293, dlist2_fst_80 };
                                          ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 id_1295 { id_1294, dstring2_snd_108 };
                                          letpair_res_1291 = id_1295;
                                        }
                                        letpair_res_1289 = letpair_res_1291;
                                      }
                                      let_res_1288 = letpair_res_1289;
                                    }
                                    letpair_res_1246 = let_res_1288;
                                  }
                                  let_res_1245 = letpair_res_1246;
                                }
                                Void id_1296 { ((void)(inits_src_ref_77[id_1197] = let_res_1245), VOID) };
                                (void)id_1296;
                              }
                              (void)VOID;
                            }
                            (void)VOID;
                            uint8_t id_1297 { 0 };
                            uint8_t id_1298 { 0 };
                            int32_t id_1299 { repeat_n_78[id_1298] };
                            int32_t id_1300 { 1L };
                            int32_t id_1301 { int32_t(id_1299 + id_1300) };
                            Void id_1302 { ((void)(repeat_n_78[id_1297] = id_1301), VOID) };
                            (void)id_1302;
                            (void)id_1302;
                          }
                        } while (while_flag_1190);
                        (void)VOID;
                      }
                      (void)VOID;
                      uint8_t id_1303 { 0 };
                      ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 id_1304 { inits_src_ref_77[id_1303] };
                      let_res_1187 = id_1304;
                    }
                    letpair_res_1183 = let_res_1187;
                  }
                  let_res_1182 = letpair_res_1183;
                }
                ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 letpair_res_1305;
                {
                  auto dlist4_fst_116 { std::get<0>(let_res_1182) };
                  auto dlist4_snd_117 { std::get<1>(let_res_1182) };
                  ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 id_1306 { dlist4_fst_116, dlist4_snd_117 };
                  letpair_res_1305 = id_1306;
                }
                ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 let_res_1307;
                {
                  ::dessser::gen::alerting_contact::t07df82f20f511d57322ca4fc039f6078 drec_118 { letpair_res_1305 };
                  ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_1308;
                  {
                    auto drec_fst_119 { std::get<0>(drec_118) };
                    auto drec_snd_120 { std::get<1>(drec_118) };
                    uint32_t id_1309 { 0U };
                    Vec<1, uint32_t> id_1310 {  id_1309  };
                    ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1311;
                    {
                      Vec<1, uint32_t> leb_ref_121 { id_1310 };
                      uint8_t id_1312 { 0 };
                      Vec<1, uint8_t> id_1313 {  id_1312  };
                      ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1314;
                      {
                        Vec<1, uint8_t> shft_ref_122 { id_1313 };
                        Vec<1, Pointer> id_1315 {  drec_snd_120  };
                        ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1316;
                        {
                          Vec<1, Pointer> p_ref_123 { id_1315 };
                          bool while_flag_1317 { true };
                          do {
                            uint8_t id_1318 { 0 };
                            Pointer id_1319 { p_ref_123[id_1318] };
                            ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 id_1320 { id_1319.readU8() };
                            bool let_res_1321;
                            {
                              ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 leb128_124 { id_1320 };
                              bool letpair_res_1322;
                              {
                                auto leb128_fst_125 { std::get<0>(leb128_124) };
                                auto leb128_snd_126 { std::get<1>(leb128_124) };
                                uint8_t id_1323 { 0 };
                                Void id_1324 { ((void)(p_ref_123[id_1323] = leb128_snd_126), VOID) };
                                (void)id_1324;
                                uint8_t id_1325 { 0 };
                                uint8_t id_1326 { 127 };
                                uint8_t id_1327 { uint8_t(leb128_fst_125 & id_1326) };
                                uint32_t id_1328 { uint32_t(id_1327) };
                                uint8_t id_1329 { 0 };
                                uint8_t id_1330 { shft_ref_122[id_1329] };
                                uint32_t id_1331 { uint32_t(id_1328 << id_1330) };
                                uint8_t id_1332 { 0 };
                                uint32_t id_1333 { leb_ref_121[id_1332] };
                                uint32_t id_1334 { uint32_t(id_1331 | id_1333) };
                                Void id_1335 { ((void)(leb_ref_121[id_1325] = id_1334), VOID) };
                                (void)id_1335;
                                uint8_t id_1336 { 0 };
                                uint8_t id_1337 { 0 };
                                uint8_t id_1338 { shft_ref_122[id_1337] };
                                uint8_t id_1339 { 7 };
                                uint8_t id_1340 { uint8_t(id_1338 + id_1339) };
                                Void id_1341 { ((void)(shft_ref_122[id_1336] = id_1340), VOID) };
                                (void)id_1341;
                                uint8_t id_1342 { 128 };
                                bool id_1343 { bool(leb128_fst_125 >= id_1342) };
                                letpair_res_1322 = id_1343;
                              }
                              let_res_1321 = letpair_res_1322;
                            }
                            while_flag_1317 = let_res_1321;
                            if (while_flag_1317) {
                              (void)VOID;
                            }
                          } while (while_flag_1317);
                          (void)VOID;
                          uint8_t id_1344 { 0 };
                          uint32_t id_1345 { leb_ref_121[id_1344] };
                          Size id_1346 { Size(id_1345) };
                          uint8_t id_1347 { 0 };
                          Pointer id_1348 { p_ref_123[id_1347] };
                          ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c id_1349 { id_1346, id_1348 };
                          let_res_1316 = id_1349;
                        }
                        let_res_1314 = let_res_1316;
                      }
                      let_res_1311 = let_res_1314;
                    }
                    ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e let_res_1350;
                    {
                      ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c dstring1_127 { let_res_1311 };
                      ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1351;
                      {
                        auto dstring1_fst_128 { std::get<0>(dstring1_127) };
                        auto dstring1_snd_129 { std::get<1>(dstring1_127) };
                        ::dessser::gen::alerting_contact::t188345aa49abd0cb47ff73fedc219f08 id_1352 { dstring1_snd_129.readBytes(dstring1_fst_128) };
                        ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e letpair_res_1353;
                        {
                          auto dstring2_fst_131 { std::get<0>(id_1352) };
                          auto dstring2_snd_132 { std::get<1>(id_1352) };
                          std::string id_1354 { dstring2_fst_131.toString() };
                          ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e id_1355 { id_1354, dstring2_snd_132 };
                          letpair_res_1353 = id_1355;
                        }
                        letpair_res_1351 = letpair_res_1353;
                      }
                      let_res_1350 = letpair_res_1351;
                    }
                    ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 let_res_1356;
                    {
                      ::dessser::gen::alerting_contact::tef94b55d8809251f13165d9a05bd9d0e drec_133 { let_res_1350 };
                      ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_1357;
                      {
                        auto drec_fst_134 { std::get<0>(drec_133) };
                        auto drec_snd_135 { std::get<1>(drec_133) };
                        ::dessser::gen::alerting_contact::t22a32080ad88ab548b80077a17b7dd46 id_1358 { drec_snd_135.readU16Le() };
                        ::dessser::gen::alerting_contact::t22a32080ad88ab548b80077a17b7dd46 letpair_res_1359;
                        {
                          auto du16_fst_137 { std::get<0>(id_1358) };
                          auto du16_snd_138 { std::get<1>(id_1358) };
                          ::dessser::gen::alerting_contact::t22a32080ad88ab548b80077a17b7dd46 id_1360 { du16_fst_137, du16_snd_138 };
                          letpair_res_1359 = id_1360;
                        }
                        ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 let_res_1361;
                        {
                          ::dessser::gen::alerting_contact::t22a32080ad88ab548b80077a17b7dd46 drec_139 { letpair_res_1359 };
                          ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_1362;
                          {
                            auto drec_fst_140 { std::get<0>(drec_139) };
                            auto drec_snd_141 { std::get<1>(drec_139) };
                            uint32_t id_1363 { 0U };
                            Vec<1, uint32_t> id_1364 {  id_1363  };
                            ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1365;
                            {
                              Vec<1, uint32_t> leb_ref_142 { id_1364 };
                              uint8_t id_1366 { 0 };
                              Vec<1, uint8_t> id_1367 {  id_1366  };
                              ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1368;
                              {
                                Vec<1, uint8_t> shft_ref_143 { id_1367 };
                                Vec<1, Pointer> id_1369 {  drec_snd_141  };
                                ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c let_res_1370;
                                {
                                  Vec<1, Pointer> p_ref_144 { id_1369 };
                                  bool while_flag_1371 { true };
                                  do {
                                    uint8_t id_1372 { 0 };
                                    Pointer id_1373 { p_ref_144[id_1372] };
                                    ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 id_1374 { id_1373.readU8() };
                                    bool let_res_1375;
                                    {
                                      ::dessser::gen::alerting_contact::tb3f98ea670610d40658a618de3ec7b90 leb128_145 { id_1374 };
                                      bool letpair_res_1376;
                                      {
                                        auto leb128_fst_146 { std::get<0>(leb128_145) };
                                        auto leb128_snd_147 { std::get<1>(leb128_145) };
                                        uint8_t id_1377 { 0 };
                                        Void id_1378 { ((void)(p_ref_144[id_1377] = leb128_snd_147), VOID) };
                                        (void)id_1378;
                                        uint8_t id_1379 { 0 };
                                        uint8_t id_1380 { 127 };
                                        uint8_t id_1381 { uint8_t(leb128_fst_146 & id_1380) };
                                        uint32_t id_1382 { uint32_t(id_1381) };
                                        uint8_t id_1383 { 0 };
                                        uint8_t id_1384 { shft_ref_143[id_1383] };
                                        uint32_t id_1385 { uint32_t(id_1382 << id_1384) };
                                        uint8_t id_1386 { 0 };
                                        uint32_t id_1387 { leb_ref_142[id_1386] };
                                        uint32_t id_1388 { uint32_t(id_1385 | id_1387) };
                                        Void id_1389 { ((void)(leb_ref_142[id_1379] = id_1388), VOID) };
                                        (void)id_1389;
                                        uint8_t id_1390 { 0 };
                                        uint8_t id_1391 { 0 };
                                        uint8_t id_1392 { shft_ref_143[id_1391] };
                                        uint8_t id_1393 { 7 };
                                        uint8_t id_1394 { uint8_t(id_1392 + id_1393) };
                                        Void id_1395 { ((void)(shft_ref_143[id_1390] = id_1394), VOID) };
                                        (void)id_1395;
                                        uint8_t id_1396 { 128 };
                                        bool id_1397 { bool(leb128_fst_146 >= id_1396) };
                                        letpair_res_1376 = id_1397;
                                      }
                                      let_res_1375 = letpair_res_1376;
                                    }
                                    while_flag_1371 = let_res_1375;
                                    if (while_flag_1371) {
                                      (void)VOID;
                                    }
                                  } while (while_flag_1371);
                                  (void)VOID;
                                  uint8_t id_1398 { 0 };
                                  uint32_t id_1399 { leb_ref_142[id_1398] };
                                  Size id_1400 { Size(id_1399) };
                                  uint8_t id_1401 { 0 };
                                  Pointer id_1402 { p_ref_144[id_1401] };
                                  ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c id_1403 { id_1400, id_1402 };
                                  let_res_1370 = id_1403;
                                }
                                let_res_1368 = let_res_1370;
                              }
                              let_res_1365 = let_res_1368;
                            }
                            ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 let_res_1404;
                            {
                              ::dessser::gen::alerting_contact::t8beb80162423aee37bd383e9b6834c9c dstring1_148 { let_res_1365 };
                              ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_1405;
                              {
                                auto dstring1_fst_149 { std::get<0>(dstring1_148) };
                                auto dstring1_snd_150 { std::get<1>(dstring1_148) };
                                ::dessser::gen::alerting_contact::t188345aa49abd0cb47ff73fedc219f08 id_1406 { dstring1_snd_150.readBytes(dstring1_fst_149) };
                                ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 letpair_res_1407;
                                {
                                  auto dstring2_fst_152 { std::get<0>(id_1406) };
                                  auto dstring2_snd_153 { std::get<1>(id_1406) };
                                  std::string id_1408 { dstring2_fst_152.toString() };
                                  ::dessser::gen::alerting_contact::t34ef5cb3b50881faab30fa24cda711db id_1409 { .options = drec_fst_119, .partition = drec_fst_140, .text = id_1408, .topic = drec_fst_134 };
                                  ::dessser::gen::alerting_contact::tf87a9e0f02ad9bcade189d770d3129cc id_1410 { std::in_place_index<4>, id_1409 };
                                  ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 id_1411 { id_1410, dstring2_snd_153 };
                                  letpair_res_1407 = id_1411;
                                }
                                letpair_res_1405 = letpair_res_1407;
                              }
                              let_res_1404 = letpair_res_1405;
                            }
                            letpair_res_1362 = let_res_1404;
                          }
                          let_res_1361 = letpair_res_1362;
                        }
                        letpair_res_1357 = let_res_1361;
                      }
                      let_res_1356 = letpair_res_1357;
                    }
                    letpair_res_1308 = let_res_1356;
                  }
                  let_res_1307 = letpair_res_1308;
                }
                choose_res_991 = let_res_1307;
              }
              choose_res_940 = choose_res_991;
            }
            choose_res_889 = choose_res_940;
          }
          choose_res_884 = choose_res_889;
        }
        letpair_res_881 = choose_res_884;
      }
      let_res_880 = letpair_res_881;
    }
    ::dessser::gen::alerting_contact::t6895345151933b08a9380e7a927036c0 let_res_1412;
    {
      ::dessser::gen::alerting_contact::tbcf02c42d3bdd7dbddc6fe2b9f8f77e0 drec_241 { let_res_880 };
      ::dessser::gen::alerting_contact::t6895345151933b08a9380e7a927036c0 letpair_res_1413;
      {
        auto drec_fst_242 { std::get<0>(drec_241) };
        auto drec_snd_243 { std::get<1>(drec_241) };
        ::dessser::gen::alerting_contact::t7a47220550fc5126a7b79f1e0c10c645 id_1414 { drec_snd_243.readU64Le() };
        ::dessser::gen::alerting_contact::t6895345151933b08a9380e7a927036c0 letpair_res_1415;
        {
          auto dfloat_fst_245 { std::get<0>(id_1414) };
          auto dfloat_snd_246 { std::get<1>(id_1414) };
          double id_1416 { float_of_qword(dfloat_fst_245) };
          ::dessser::gen::alerting_contact::t* id_1417 { new ::dessser::gen::alerting_contact::t({ .timeout = id_1416, .via = drec_fst_242 }) };
          ::dessser::gen::alerting_contact::t6895345151933b08a9380e7a927036c0 id_1418 { id_1417, dfloat_snd_246 };
          letpair_res_1415 = id_1418;
        }
        letpair_res_1413 = letpair_res_1415;
      }
      let_res_1412 = letpair_res_1413;
    }
    return let_res_1412;
  }
   };
  return fun876;
}
std::function<::dessser::gen::alerting_contact::t6895345151933b08a9380e7a927036c0(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
