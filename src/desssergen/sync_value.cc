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
#include "desssergen/alerting_inhibition.h"
#include "desssergen/alerting_log.h"
#include "desssergen/alerting_delivery_status.h"
#include "desssergen/alerting_notification.h"
#include "desssergen/alerting_contact.h"
#include "desssergen/dashboard_widget.h"
#include "desssergen/output_specs.h"
#include "desssergen/alert.h"
#include "desssergen/replay_request.h"
#include "desssergen/replayer.h"
#include "desssergen/replay.h"
#include "desssergen/runtime_stats.h"
#include "desssergen/source_info.h"
#include "desssergen/target_config.h"
#include "desssergen/raql_value.h"
#include "desssergen/time_range.h"
#include "desssergen/retention.h"
#include "desssergen/worker.h"


namespace dessser::gen::sync_value {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct tde68d14dd253c0005e157424dd8fc48d : public std::tuple<
  double,
  uint32_t,
  std::string
> { using tuple::tuple; };
struct te83fa7fcadeeebdddedfae1b0cf34bd2 {
  uint32_t skipped;
  Bytes values;
  te83fa7fcadeeebdddedfae1b0cf34bd2(uint32_t skipped_, Bytes values_) : skipped(skipped_), values(values_) {}
  te83fa7fcadeeebdddedfae1b0cf34bd2() = default;
};
struct t : public std::variant<
  ::dessser::gen::sync_value::tde68d14dd253c0005e157424dd8fc48d, // Error
  dessser::gen::worker::t_ext, // Worker
  dessser::gen::retention::t_ext, // Retention
  dessser::gen::time_range::t_ext, // TimeRange
  Arr<::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2>, // Tuples
  dessser::gen::raql_value::t_ext, // RamenValue
  dessser::gen::target_config::t_ext, // TargetConfig
  dessser::gen::source_info::t_ext, // SourceInfo
  dessser::gen::runtime_stats::t_ext, // RuntimeStats
  dessser::gen::replay::t_ext, // Replay
  dessser::gen::replayer::t_ext, // Replayer
  dessser::gen::replay_request::t_ext, // ReplayRequest
  dessser::gen::alert::t_ext, // Alert
  dessser::gen::output_specs::t_ext, // OutputSpecs
  dessser::gen::dashboard_widget::t_ext, // DashboardWidget
  dessser::gen::alerting_contact::t_ext, // AlertingContact
  dessser::gen::alerting_notification::t_ext, // Notification
  dessser::gen::alerting_delivery_status::t_ext, // DeliveryStatus
  dessser::gen::alerting_log::t_ext, // IncidentLog
  dessser::gen::alerting_inhibition::t_ext // Inhibition
> { using variant::variant; };

typedef std::tuple<
  ::dessser::gen::sync_value::t*,
  Pointer
> t5a4f9375f61f65c3413a01c7d782b657;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

typedef std::tuple<
  double,
  Pointer
> taebed00ad7fdb3f7ced11d3cfd58aade;

typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

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
  dessser::gen::worker::t_ext,
  Pointer
> t134551dd3247bb0c2e40279e9eddb2ac;

typedef std::tuple<
  dessser::gen::retention::t_ext,
  Pointer
> t7c83e84e0162e9442953bc16c018e153;

typedef std::tuple<
  dessser::gen::time_range::t_ext,
  Pointer
> t2cd1b6aab4060eb2dceb682cd53d34da;

typedef std::tuple<
  Lst<::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2>,
  Pointer
> ta587c787d7b029489695fe00a437996b;

typedef std::tuple<
  dessser::gen::raql_value::t_ext,
  Pointer
> t9cfa78b25ddcb5afc14daf6a802a6f88;

typedef std::tuple<
  dessser::gen::target_config::t_ext,
  Pointer
> te08e45bff93070c7c714161c85d8bac1;

typedef std::tuple<
  dessser::gen::source_info::t_ext,
  Pointer
> tf0808eb091f71d5e62637e5a96e20fd5;

typedef std::tuple<
  dessser::gen::runtime_stats::t_ext,
  Pointer
> t5e0d448e4b20dd2a65aeb5cea700d072;

typedef std::tuple<
  dessser::gen::replay::t_ext,
  Pointer
> tb33470da5f25cd7882672954c47d23c1;

typedef std::tuple<
  dessser::gen::replayer::t_ext,
  Pointer
> t489f46e36aeafd83f541b9ae05cdef2c;

typedef std::tuple<
  dessser::gen::replay_request::t_ext,
  Pointer
> t1b05239ef21a25a1347706de021d5841;

typedef std::tuple<
  dessser::gen::alert::t_ext,
  Pointer
> t9cd9e34ddfecb0b26fe0f772eb18bd85;

typedef std::tuple<
  dessser::gen::output_specs::t_ext,
  Pointer
> t135a9b267c9c18ff8a4c6aa0d72eaff7;

typedef std::tuple<
  dessser::gen::dashboard_widget::t_ext,
  Pointer
> td5d43892c681e8c8e0ae933735d580a4;

typedef std::tuple<
  dessser::gen::alerting_contact::t_ext,
  Pointer
> t24e29d052a88c9ba931ba3dd969f042b;

typedef std::tuple<
  dessser::gen::alerting_notification::t_ext,
  Pointer
> t4a3c6489e69a673e7d2022cfc40cf24c;

typedef std::tuple<
  dessser::gen::alerting_delivery_status::t_ext,
  Pointer
> tfe00ca7e5541a3abc1bf1027b3a0de04;

typedef std::tuple<
  dessser::gen::alerting_log::t_ext,
  Pointer
> td4b7bd975d92d8092bd289b9dcb515a5;

typedef std::tuple<
  dessser::gen::alerting_inhibition::t_ext,
  Pointer
> t94dc6b599eeaaffec96b6d6b251ed196;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" "Ptr")
      (let "label1_212" (label-of (param 0))
        (let "ssum_dst_213" (write-u16 little-endian (param 1) (identifier "label1_212"))
          (if (eq (u16 0) (identifier "label1_212"))
            (let "stup_dst_224"
              (let "stup_dst_223" (write-u64 little-endian (identifier "ssum_dst_213") (u64-of-float (get-item 0 (get-alt "Error" (param 0)))))
                (write-u32 little-endian (identifier "stup_dst_223") (get-item 1 (get-alt "Error" (param 0)))))
              (write-bytes
                (let "leb128_sz_225" (make-vec (string-length (get-item 2 (get-alt "Error" (param 0)))))
                  (let "leb128_ptr_226" (make-vec (identifier "stup_dst_224"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_226")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_226"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_225"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_225"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_225"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_225") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_225")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_225")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_226"))))) 
                (bytes-of-string (get-item 2 (get-alt "Error" (param 0))))))
            (if (eq (u16 1) (identifier "label1_212")) (apply (ext-identifier worker to-row-binary) (get-alt "Worker" (param 0)) (identifier "ssum_dst_213"))
              (if (eq (u16 2) (identifier "label1_212")) (apply (ext-identifier retention to-row-binary) (get-alt "Retention" (param 0)) (identifier "ssum_dst_213"))
                (if (eq (u16 3) (identifier "label1_212")) (apply (ext-identifier time_range to-row-binary) (get-alt "TimeRange" (param 0)) (identifier "ssum_dst_213"))
                  (if (eq (u16 4) (identifier "label1_212"))
                    (let "dst_ref_216"
                      (make-vec
                        (let "leb128_sz_214" (make-vec (cardinality (get-alt "Tuples" (param 0))))
                          (let "leb128_ptr_215" (make-vec (identifier "ssum_dst_213"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_215")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_215"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_214"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_214"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_214"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_214") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_214")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_214")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_215"))))))
                      (let "n_ref_217" (make-vec (i32 0))
                        (seq
                          (for-each "x_218" (get-alt "Tuples" (param 0))
                            (seq
                              (set-vec (u8 0) (identifier "dst_ref_216")
                                (let "srec_dst_220" (let "srec_dst_219" (unsafe-nth (u8 0) (identifier "dst_ref_216")) (write-u32 little-endian (identifier "srec_dst_219") (get-field "skipped" (identifier "x_218"))))
                                  (write-bytes
                                    (let "leb128_sz_221" (make-vec (u32-of-size (bytes-length (get-field "values" (identifier "x_218")))))
                                      (let "leb128_ptr_222" (make-vec (identifier "srec_dst_220"))
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
                                    (get-field "values" (identifier "x_218"))))) 
                              (set-vec (u8 0) (identifier "n_ref_217") (add (i32 1) (unsafe-nth (u8 0) (identifier "n_ref_217")))))) 
                          (unsafe-nth (u8 0) (identifier "dst_ref_216")))))
                    (if (eq (u16 5) (identifier "label1_212")) (apply (ext-identifier raql_value to-row-binary) (get-alt "RamenValue" (param 0)) (identifier "ssum_dst_213"))
                      (if (eq (u16 6) (identifier "label1_212")) (apply (ext-identifier target_config to-row-binary) (get-alt "TargetConfig" (param 0)) (identifier "ssum_dst_213"))
                        (if (eq (u16 7) (identifier "label1_212")) (apply (ext-identifier source_info to-row-binary) (get-alt "SourceInfo" (param 0)) (identifier "ssum_dst_213"))
                          (if (eq (u16 8) (identifier "label1_212")) 
                            (apply (ext-identifier runtime_stats to-row-binary) (get-alt "RuntimeStats" (param 0)) (identifier "ssum_dst_213"))
                            (if (eq (u16 9) (identifier "label1_212")) 
                              (apply (ext-identifier replay to-row-binary) (get-alt "Replay" (param 0)) (identifier "ssum_dst_213"))
                              (if (eq (u16 10) (identifier "label1_212")) 
                                (apply (ext-identifier replayer to-row-binary) (get-alt "Replayer" (param 0)) (identifier "ssum_dst_213"))
                                (if (eq (u16 11) (identifier "label1_212")) 
                                  (apply (ext-identifier replay_request to-row-binary) (get-alt "ReplayRequest" (param 0)) (identifier "ssum_dst_213"))
                                  (if (eq (u16 12) (identifier "label1_212")) 
                                    (apply (ext-identifier alert to-row-binary) (get-alt "Alert" (param 0)) (identifier "ssum_dst_213"))
                                    (if (eq (u16 13) (identifier "label1_212")) 
                                      (apply (ext-identifier output_specs to-row-binary) (get-alt "OutputSpecs" (param 0)) (identifier "ssum_dst_213"))
                                      (if (eq (u16 14) (identifier "label1_212")) 
                                        (apply (ext-identifier dashboard_widget to-row-binary) (get-alt "DashboardWidget" (param 0)) (identifier "ssum_dst_213"))
                                        (if (eq (u16 15) (identifier "label1_212")) 
                                          (apply (ext-identifier alerting_contact to-row-binary) (get-alt "AlertingContact" (param 0)) (identifier "ssum_dst_213"))
                                          (if (eq (u16 16) (identifier "label1_212")) 
                                            (apply (ext-identifier alerting_notification to-row-binary) (get-alt "Notification" (param 0)) (identifier "ssum_dst_213"))
                                            (if (eq (u16 17) (identifier "label1_212")) 
                                              (apply (ext-identifier alerting_delivery_status to-row-binary) (get-alt "DeliveryStatus" (param 0)) (identifier "ssum_dst_213"))
                                              (if (eq (u16 18) (identifier "label1_212")) 
                                                (apply (ext-identifier alerting_log to-row-binary) (get-alt "IncidentLog" (param 0)) (identifier "ssum_dst_213"))
                                                (seq (assert (eq (identifier "label1_212") (u16 19))) (apply (ext-identifier alerting_inhibition to-row-binary) (get-alt "Inhibition" (param 0)) (identifier "ssum_dst_213")))))))))))))))))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_value::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_value::t*,Pointer)> fun0 { [&fun0](::dessser::gen::sync_value::t* p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer let_res_2;
    {
      uint16_t label1_212 { id_1 };
      Pointer id_3 { p_1.writeU16Le(label1_212) };
      Pointer let_res_4;
      {
        Pointer ssum_dst_213 { id_3 };
        uint16_t id_5 { 0 };
        bool id_6 { bool(id_5 == label1_212) };
        Pointer choose_res_7;
        if (id_6) {
          ::dessser::gen::sync_value::tde68d14dd253c0005e157424dd8fc48d id_8 { std::get<0 /* Error */>((*p_0)) };
          double id_9 { std::get<0>(id_8) };
          uint64_t id_10 { qword_of_float(id_9) };
          Pointer id_11 { ssum_dst_213.writeU64Le(id_10) };
          Pointer let_res_12;
          {
            Pointer stup_dst_223 { id_11 };
            ::dessser::gen::sync_value::tde68d14dd253c0005e157424dd8fc48d id_13 { std::get<0 /* Error */>((*p_0)) };
            uint32_t id_14 { std::get<1>(id_13) };
            Pointer id_15 { stup_dst_223.writeU32Le(id_14) };
            let_res_12 = id_15;
          }
          Pointer let_res_16;
          {
            Pointer stup_dst_224 { let_res_12 };
            ::dessser::gen::sync_value::tde68d14dd253c0005e157424dd8fc48d id_17 { std::get<0 /* Error */>((*p_0)) };
            std::string id_18 { std::get<2>(id_17) };
            uint32_t id_19 { (uint32_t)id_18.size() };
            Vec<1, uint32_t> id_20 {  id_19  };
            Pointer let_res_21;
            {
              Vec<1, uint32_t> leb128_sz_225 { id_20 };
              Vec<1, Pointer> id_22 {  stup_dst_224  };
              Pointer let_res_23;
              {
                Vec<1, Pointer> leb128_ptr_226 { id_22 };
                bool while_flag_24 { true };
                do {
                  uint8_t id_25 { 0 };
                  uint8_t id_26 { 0 };
                  Pointer id_27 { leb128_ptr_226[id_26] };
                  uint32_t id_28 { 128U };
                  uint8_t id_29 { 0 };
                  uint32_t id_30 { leb128_sz_225[id_29] };
                  bool id_31 { bool(id_28 > id_30) };
                  uint8_t choose_res_32;
                  if (id_31) {
                    uint8_t id_33 { 0 };
                    uint32_t id_34 { leb128_sz_225[id_33] };
                    uint8_t id_35 { uint8_t(id_34) };
                    choose_res_32 = id_35;
                  } else {
                    uint8_t id_36 { 0 };
                    uint32_t id_37 { leb128_sz_225[id_36] };
                    uint8_t id_38 { uint8_t(id_37) };
                    uint8_t id_39 { 128 };
                    uint8_t id_40 { uint8_t(id_38 | id_39) };
                    choose_res_32 = id_40;
                  }
                  Pointer id_41 { id_27.writeU8(choose_res_32) };
                  Void id_42 { ((void)(leb128_ptr_226[id_25] = id_41), VOID) };
                  (void)id_42;
                  uint8_t id_43 { 0 };
                  uint8_t id_44 { 0 };
                  uint32_t id_45 { leb128_sz_225[id_44] };
                  uint8_t id_46 { 7 };
                  uint32_t id_47 { uint32_t(id_45 >> id_46) };
                  Void id_48 { ((void)(leb128_sz_225[id_43] = id_47), VOID) };
                  (void)id_48;
                  uint8_t id_49 { 0 };
                  uint32_t id_50 { leb128_sz_225[id_49] };
                  uint32_t id_51 { 0U };
                  bool id_52 { bool(id_50 > id_51) };
                  while_flag_24 = id_52;
                  if (while_flag_24) {
                    (void)VOID;
                  }
                } while (while_flag_24);
                (void)VOID;
                uint8_t id_53 { 0 };
                Pointer id_54 { leb128_ptr_226[id_53] };
                let_res_23 = id_54;
              }
              let_res_21 = let_res_23;
            }
            ::dessser::gen::sync_value::tde68d14dd253c0005e157424dd8fc48d id_55 { std::get<0 /* Error */>((*p_0)) };
            std::string id_56 { std::get<2>(id_55) };
            Bytes id_57 { id_56 };
            Pointer id_58 { let_res_21.writeBytes(id_57) };
            let_res_16 = id_58;
          }
          choose_res_7 = let_res_16;
        } else {
          uint16_t id_59 { 1 };
          bool id_60 { bool(id_59 == label1_212) };
          Pointer choose_res_61;
          if (id_60) {
            auto fun62 { dessser::gen::worker::to_row_binary };
            dessser::gen::worker::t_ext id_63 { std::get<1 /* Worker */>((*p_0)) };
            Pointer id_64 { fun62(id_63, ssum_dst_213) };
            choose_res_61 = id_64;
          } else {
            uint16_t id_65 { 2 };
            bool id_66 { bool(id_65 == label1_212) };
            Pointer choose_res_67;
            if (id_66) {
              auto fun68 { dessser::gen::retention::to_row_binary };
              dessser::gen::retention::t_ext id_69 { std::get<2 /* Retention */>((*p_0)) };
              Pointer id_70 { fun68(id_69, ssum_dst_213) };
              choose_res_67 = id_70;
            } else {
              uint16_t id_71 { 3 };
              bool id_72 { bool(id_71 == label1_212) };
              Pointer choose_res_73;
              if (id_72) {
                auto fun74 { dessser::gen::time_range::to_row_binary };
                dessser::gen::time_range::t_ext id_75 { std::get<3 /* TimeRange */>((*p_0)) };
                Pointer id_76 { fun74(id_75, ssum_dst_213) };
                choose_res_73 = id_76;
              } else {
                uint16_t id_77 { 4 };
                bool id_78 { bool(id_77 == label1_212) };
                Pointer choose_res_79;
                if (id_78) {
                  Arr<::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2> id_80 { std::get<4 /* Tuples */>((*p_0)) };
                  uint32_t id_81 { id_80.size() };
                  Vec<1, uint32_t> id_82 {  id_81  };
                  Pointer let_res_83;
                  {
                    Vec<1, uint32_t> leb128_sz_214 { id_82 };
                    Vec<1, Pointer> id_84 {  ssum_dst_213  };
                    Pointer let_res_85;
                    {
                      Vec<1, Pointer> leb128_ptr_215 { id_84 };
                      bool while_flag_86 { true };
                      do {
                        uint8_t id_87 { 0 };
                        uint8_t id_88 { 0 };
                        Pointer id_89 { leb128_ptr_215[id_88] };
                        uint32_t id_90 { 128U };
                        uint8_t id_91 { 0 };
                        uint32_t id_92 { leb128_sz_214[id_91] };
                        bool id_93 { bool(id_90 > id_92) };
                        uint8_t choose_res_94;
                        if (id_93) {
                          uint8_t id_95 { 0 };
                          uint32_t id_96 { leb128_sz_214[id_95] };
                          uint8_t id_97 { uint8_t(id_96) };
                          choose_res_94 = id_97;
                        } else {
                          uint8_t id_98 { 0 };
                          uint32_t id_99 { leb128_sz_214[id_98] };
                          uint8_t id_100 { uint8_t(id_99) };
                          uint8_t id_101 { 128 };
                          uint8_t id_102 { uint8_t(id_100 | id_101) };
                          choose_res_94 = id_102;
                        }
                        Pointer id_103 { id_89.writeU8(choose_res_94) };
                        Void id_104 { ((void)(leb128_ptr_215[id_87] = id_103), VOID) };
                        (void)id_104;
                        uint8_t id_105 { 0 };
                        uint8_t id_106 { 0 };
                        uint32_t id_107 { leb128_sz_214[id_106] };
                        uint8_t id_108 { 7 };
                        uint32_t id_109 { uint32_t(id_107 >> id_108) };
                        Void id_110 { ((void)(leb128_sz_214[id_105] = id_109), VOID) };
                        (void)id_110;
                        uint8_t id_111 { 0 };
                        uint32_t id_112 { leb128_sz_214[id_111] };
                        uint32_t id_113 { 0U };
                        bool id_114 { bool(id_112 > id_113) };
                        while_flag_86 = id_114;
                        if (while_flag_86) {
                          (void)VOID;
                        }
                      } while (while_flag_86);
                      (void)VOID;
                      uint8_t id_115 { 0 };
                      Pointer id_116 { leb128_ptr_215[id_115] };
                      let_res_85 = id_116;
                    }
                    let_res_83 = let_res_85;
                  }
                  Vec<1, Pointer> id_117 {  let_res_83  };
                  Pointer let_res_118;
                  {
                    Vec<1, Pointer> dst_ref_216 { id_117 };
                    int32_t id_119 { 0L };
                    Vec<1, int32_t> id_120 {  id_119  };
                    Pointer let_res_121;
                    {
                      Vec<1, int32_t> n_ref_217 { id_120 };
                      Arr<::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2> id_122 { std::get<4 /* Tuples */>((*p_0)) };
                      for (::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2 x_218 : id_122) {
                        uint8_t id_123 { 0 };
                        uint8_t id_124 { 0 };
                        Pointer id_125 { dst_ref_216[id_124] };
                        Pointer let_res_126;
                        {
                          Pointer srec_dst_219 { id_125 };
                          uint32_t id_127 { x_218.skipped };
                          Pointer id_128 { srec_dst_219.writeU32Le(id_127) };
                          let_res_126 = id_128;
                        }
                        Pointer let_res_129;
                        {
                          Pointer srec_dst_220 { let_res_126 };
                          Bytes id_130 { x_218.values };
                          Size id_131 { id_130.length() };
                          uint32_t id_132 { uint32_t(id_131) };
                          Vec<1, uint32_t> id_133 {  id_132  };
                          Pointer let_res_134;
                          {
                            Vec<1, uint32_t> leb128_sz_221 { id_133 };
                            Vec<1, Pointer> id_135 {  srec_dst_220  };
                            Pointer let_res_136;
                            {
                              Vec<1, Pointer> leb128_ptr_222 { id_135 };
                              bool while_flag_137 { true };
                              do {
                                uint8_t id_138 { 0 };
                                uint8_t id_139 { 0 };
                                Pointer id_140 { leb128_ptr_222[id_139] };
                                uint32_t id_141 { 128U };
                                uint8_t id_142 { 0 };
                                uint32_t id_143 { leb128_sz_221[id_142] };
                                bool id_144 { bool(id_141 > id_143) };
                                uint8_t choose_res_145;
                                if (id_144) {
                                  uint8_t id_146 { 0 };
                                  uint32_t id_147 { leb128_sz_221[id_146] };
                                  uint8_t id_148 { uint8_t(id_147) };
                                  choose_res_145 = id_148;
                                } else {
                                  uint8_t id_149 { 0 };
                                  uint32_t id_150 { leb128_sz_221[id_149] };
                                  uint8_t id_151 { uint8_t(id_150) };
                                  uint8_t id_152 { 128 };
                                  uint8_t id_153 { uint8_t(id_151 | id_152) };
                                  choose_res_145 = id_153;
                                }
                                Pointer id_154 { id_140.writeU8(choose_res_145) };
                                Void id_155 { ((void)(leb128_ptr_222[id_138] = id_154), VOID) };
                                (void)id_155;
                                uint8_t id_156 { 0 };
                                uint8_t id_157 { 0 };
                                uint32_t id_158 { leb128_sz_221[id_157] };
                                uint8_t id_159 { 7 };
                                uint32_t id_160 { uint32_t(id_158 >> id_159) };
                                Void id_161 { ((void)(leb128_sz_221[id_156] = id_160), VOID) };
                                (void)id_161;
                                uint8_t id_162 { 0 };
                                uint32_t id_163 { leb128_sz_221[id_162] };
                                uint32_t id_164 { 0U };
                                bool id_165 { bool(id_163 > id_164) };
                                while_flag_137 = id_165;
                                if (while_flag_137) {
                                  (void)VOID;
                                }
                              } while (while_flag_137);
                              (void)VOID;
                              uint8_t id_166 { 0 };
                              Pointer id_167 { leb128_ptr_222[id_166] };
                              let_res_136 = id_167;
                            }
                            let_res_134 = let_res_136;
                          }
                          Bytes id_168 { x_218.values };
                          Pointer id_169 { let_res_134.writeBytes(id_168) };
                          let_res_129 = id_169;
                        }
                        Void id_170 { ((void)(dst_ref_216[id_123] = let_res_129), VOID) };
                        (void)id_170;
                        uint8_t id_171 { 0 };
                        int32_t id_172 { 1L };
                        uint8_t id_173 { 0 };
                        int32_t id_174 { n_ref_217[id_173] };
                        int32_t id_175 { int32_t(id_172 + id_174) };
                        Void id_176 { ((void)(n_ref_217[id_171] = id_175), VOID) };
                        (void)id_176;
                        (void)id_176;
                      }
                      (void)VOID;
                      uint8_t id_177 { 0 };
                      Pointer id_178 { dst_ref_216[id_177] };
                      let_res_121 = id_178;
                    }
                    let_res_118 = let_res_121;
                  }
                  choose_res_79 = let_res_118;
                } else {
                  uint16_t id_179 { 5 };
                  bool id_180 { bool(id_179 == label1_212) };
                  Pointer choose_res_181;
                  if (id_180) {
                    auto fun182 { dessser::gen::raql_value::to_row_binary };
                    dessser::gen::raql_value::t_ext id_183 { std::get<5 /* RamenValue */>((*p_0)) };
                    Pointer id_184 { fun182(id_183, ssum_dst_213) };
                    choose_res_181 = id_184;
                  } else {
                    uint16_t id_185 { 6 };
                    bool id_186 { bool(id_185 == label1_212) };
                    Pointer choose_res_187;
                    if (id_186) {
                      auto fun188 { dessser::gen::target_config::to_row_binary };
                      dessser::gen::target_config::t_ext id_189 { std::get<6 /* TargetConfig */>((*p_0)) };
                      Pointer id_190 { fun188(id_189, ssum_dst_213) };
                      choose_res_187 = id_190;
                    } else {
                      uint16_t id_191 { 7 };
                      bool id_192 { bool(id_191 == label1_212) };
                      Pointer choose_res_193;
                      if (id_192) {
                        auto fun194 { dessser::gen::source_info::to_row_binary };
                        dessser::gen::source_info::t_ext id_195 { std::get<7 /* SourceInfo */>((*p_0)) };
                        Pointer id_196 { fun194(id_195, ssum_dst_213) };
                        choose_res_193 = id_196;
                      } else {
                        uint16_t id_197 { 8 };
                        bool id_198 { bool(id_197 == label1_212) };
                        Pointer choose_res_199;
                        if (id_198) {
                          auto fun200 { dessser::gen::runtime_stats::to_row_binary };
                          dessser::gen::runtime_stats::t_ext id_201 { std::get<8 /* RuntimeStats */>((*p_0)) };
                          Pointer id_202 { fun200(id_201, ssum_dst_213) };
                          choose_res_199 = id_202;
                        } else {
                          uint16_t id_203 { 9 };
                          bool id_204 { bool(id_203 == label1_212) };
                          Pointer choose_res_205;
                          if (id_204) {
                            auto fun206 { dessser::gen::replay::to_row_binary };
                            dessser::gen::replay::t_ext id_207 { std::get<9 /* Replay */>((*p_0)) };
                            Pointer id_208 { fun206(id_207, ssum_dst_213) };
                            choose_res_205 = id_208;
                          } else {
                            uint16_t id_209 { 10 };
                            bool id_210 { bool(id_209 == label1_212) };
                            Pointer choose_res_211;
                            if (id_210) {
                              auto fun212 { dessser::gen::replayer::to_row_binary };
                              dessser::gen::replayer::t_ext id_213 { std::get<10 /* Replayer */>((*p_0)) };
                              Pointer id_214 { fun212(id_213, ssum_dst_213) };
                              choose_res_211 = id_214;
                            } else {
                              uint16_t id_215 { 11 };
                              bool id_216 { bool(id_215 == label1_212) };
                              Pointer choose_res_217;
                              if (id_216) {
                                auto fun218 { dessser::gen::replay_request::to_row_binary };
                                dessser::gen::replay_request::t_ext id_219 { std::get<11 /* ReplayRequest */>((*p_0)) };
                                Pointer id_220 { fun218(id_219, ssum_dst_213) };
                                choose_res_217 = id_220;
                              } else {
                                uint16_t id_221 { 12 };
                                bool id_222 { bool(id_221 == label1_212) };
                                Pointer choose_res_223;
                                if (id_222) {
                                  auto fun224 { dessser::gen::alert::to_row_binary };
                                  dessser::gen::alert::t_ext id_225 { std::get<12 /* Alert */>((*p_0)) };
                                  Pointer id_226 { fun224(id_225, ssum_dst_213) };
                                  choose_res_223 = id_226;
                                } else {
                                  uint16_t id_227 { 13 };
                                  bool id_228 { bool(id_227 == label1_212) };
                                  Pointer choose_res_229;
                                  if (id_228) {
                                    auto fun230 { dessser::gen::output_specs::to_row_binary };
                                    dessser::gen::output_specs::t_ext id_231 { std::get<13 /* OutputSpecs */>((*p_0)) };
                                    Pointer id_232 { fun230(id_231, ssum_dst_213) };
                                    choose_res_229 = id_232;
                                  } else {
                                    uint16_t id_233 { 14 };
                                    bool id_234 { bool(id_233 == label1_212) };
                                    Pointer choose_res_235;
                                    if (id_234) {
                                      auto fun236 { dessser::gen::dashboard_widget::to_row_binary };
                                      dessser::gen::dashboard_widget::t_ext id_237 { std::get<14 /* DashboardWidget */>((*p_0)) };
                                      Pointer id_238 { fun236(id_237, ssum_dst_213) };
                                      choose_res_235 = id_238;
                                    } else {
                                      uint16_t id_239 { 15 };
                                      bool id_240 { bool(id_239 == label1_212) };
                                      Pointer choose_res_241;
                                      if (id_240) {
                                        auto fun242 { dessser::gen::alerting_contact::to_row_binary };
                                        dessser::gen::alerting_contact::t_ext id_243 { std::get<15 /* AlertingContact */>((*p_0)) };
                                        Pointer id_244 { fun242(id_243, ssum_dst_213) };
                                        choose_res_241 = id_244;
                                      } else {
                                        uint16_t id_245 { 16 };
                                        bool id_246 { bool(id_245 == label1_212) };
                                        Pointer choose_res_247;
                                        if (id_246) {
                                          auto fun248 { dessser::gen::alerting_notification::to_row_binary };
                                          dessser::gen::alerting_notification::t_ext id_249 { std::get<16 /* Notification */>((*p_0)) };
                                          Pointer id_250 { fun248(id_249, ssum_dst_213) };
                                          choose_res_247 = id_250;
                                        } else {
                                          uint16_t id_251 { 17 };
                                          bool id_252 { bool(id_251 == label1_212) };
                                          Pointer choose_res_253;
                                          if (id_252) {
                                            auto fun254 { dessser::gen::alerting_delivery_status::to_row_binary };
                                            dessser::gen::alerting_delivery_status::t_ext id_255 { std::get<17 /* DeliveryStatus */>((*p_0)) };
                                            Pointer id_256 { fun254(id_255, ssum_dst_213) };
                                            choose_res_253 = id_256;
                                          } else {
                                            uint16_t id_257 { 18 };
                                            bool id_258 { bool(id_257 == label1_212) };
                                            Pointer choose_res_259;
                                            if (id_258) {
                                              auto fun260 { dessser::gen::alerting_log::to_row_binary };
                                              dessser::gen::alerting_log::t_ext id_261 { std::get<18 /* IncidentLog */>((*p_0)) };
                                              Pointer id_262 { fun260(id_261, ssum_dst_213) };
                                              choose_res_259 = id_262;
                                            } else {
                                              uint16_t id_263 { 19 };
                                              bool id_264 { bool(label1_212 == id_263) };
                                              Void id_265 { ((void)(assert(id_264)), VOID) };
                                              (void)id_265;
                                              auto fun266 { dessser::gen::alerting_inhibition::to_row_binary };
                                              dessser::gen::alerting_inhibition::t_ext id_267 { std::get<19 /* Inhibition */>((*p_0)) };
                                              Pointer id_268 { fun266(id_267, ssum_dst_213) };
                                              choose_res_259 = id_268;
                                            }
                                            choose_res_253 = choose_res_259;
                                          }
                                          choose_res_247 = choose_res_253;
                                        }
                                        choose_res_241 = choose_res_247;
                                      }
                                      choose_res_235 = choose_res_241;
                                    }
                                    choose_res_229 = choose_res_235;
                                  }
                                  choose_res_223 = choose_res_229;
                                }
                                choose_res_217 = choose_res_223;
                              }
                              choose_res_211 = choose_res_217;
                            }
                            choose_res_205 = choose_res_211;
                          }
                          choose_res_199 = choose_res_205;
                        }
                        choose_res_193 = choose_res_199;
                      }
                      choose_res_187 = choose_res_193;
                    }
                    choose_res_181 = choose_res_187;
                  }
                  choose_res_79 = choose_res_181;
                }
                choose_res_73 = choose_res_79;
              }
              choose_res_67 = choose_res_73;
            }
            choose_res_61 = choose_res_67;
          }
          choose_res_7 = choose_res_61;
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
std::function<Pointer(::dessser::gen::sync_value::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]")
      (let "label2_196" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_196"))
          (add (size 14)
            (add
              (let "n_ref_210" (make-vec (string-length (get-item 2 (get-alt "Error" (param 0)))))
                (let "lebsz_ref_211" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_210")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_211")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_211") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_211")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_211")))))) 
              (size-of-u32 (string-length (get-item 2 (get-alt "Error" (param 0)))))))
          (if (eq (u16 1) (identifier "label2_196")) (add (size 2) (apply (ext-identifier worker sersize-of-row-binary) (get-alt "Worker" (param 0))))
            (if (eq (u16 2) (identifier "label2_196")) (add (size 2) (apply (ext-identifier retention sersize-of-row-binary) (get-alt "Retention" (param 0))))
              (if (eq (u16 3) (identifier "label2_196")) (add (size 2) (apply (ext-identifier time_range sersize-of-row-binary) (get-alt "TimeRange" (param 0))))
                (if (eq (u16 4) (identifier "label2_196"))
                  (let "sz_ref_199"
                    (make-vec
                      (add (size 2)
                        (let "n_ref_197" (make-vec (cardinality (get-alt "Tuples" (param 0))))
                          (let "lebsz_ref_198" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_197")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_198")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_198") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_198")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_198"))))))))
                    (seq
                      (let "repeat_n_200" (make-vec (i32 0))
                        (while (gt (to-i32 (cardinality (get-alt "Tuples" (param 0)))) (unsafe-nth (u8 0) (identifier "repeat_n_200")))
                          (seq
                            (set-vec (u8 0) (identifier "sz_ref_199")
                              (let "sz_202" (add (unsafe-nth (u8 0) (identifier "sz_ref_199")) (size 4))
                                (add (identifier "sz_202")
                                  (let "wlen_203" (bytes-length (get-field "values" (unsafe-nth (unsafe-nth (u8 0) (identifier "repeat_n_200")) (get-alt "Tuples" (param 0)))))
                                    (add
                                      (let "n_ref_204" (make-vec (u32-of-size (identifier "wlen_203")))
                                        (let "lebsz_ref_205" (make-vec (u32 1))
                                          (seq
                                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_204")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_205")) (u8 7)))
                                              (set-vec (u8 0) (identifier "lebsz_ref_205") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_205")) (u32 1)))) 
                                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_205")))))) 
                                      (identifier "wlen_203")))))) (set-vec (u8 0) (identifier "repeat_n_200") (add (unsafe-nth (u8 0) (identifier "repeat_n_200")) (i32 1)))))) 
                      (unsafe-nth (u8 0) (identifier "sz_ref_199"))))
                  (if (eq (u16 5) (identifier "label2_196")) (add (size 2) (apply (ext-identifier raql_value sersize-of-row-binary) (get-alt "RamenValue" (param 0))))
                    (if (eq (u16 6) (identifier "label2_196")) (add (size 2) (apply (ext-identifier target_config sersize-of-row-binary) (get-alt "TargetConfig" (param 0))))
                      (if (eq (u16 7) (identifier "label2_196")) (add (size 2) (apply (ext-identifier source_info sersize-of-row-binary) (get-alt "SourceInfo" (param 0))))
                        (if (eq (u16 8) (identifier "label2_196")) (add (size 2) (apply (ext-identifier runtime_stats sersize-of-row-binary) (get-alt "RuntimeStats" (param 0))))
                          (if (eq (u16 9) (identifier "label2_196")) 
                            (add (size 2) (apply (ext-identifier replay sersize-of-row-binary) (get-alt "Replay" (param 0))))
                            (if (eq (u16 10) (identifier "label2_196")) 
                              (add (size 2) (apply (ext-identifier replayer sersize-of-row-binary) (get-alt "Replayer" (param 0))))
                              (if (eq (u16 11) (identifier "label2_196")) 
                                (add (size 2) (apply (ext-identifier replay_request sersize-of-row-binary) (get-alt "ReplayRequest" (param 0))))
                                (if (eq (u16 12) (identifier "label2_196")) 
                                  (add (size 2) (apply (ext-identifier alert sersize-of-row-binary) (get-alt "Alert" (param 0))))
                                  (if (eq (u16 13) (identifier "label2_196")) 
                                    (add (size 2) (apply (ext-identifier output_specs sersize-of-row-binary) (get-alt "OutputSpecs" (param 0))))
                                    (if (eq (u16 14) (identifier "label2_196")) 
                                      (add (size 2) (apply (ext-identifier dashboard_widget sersize-of-row-binary) (get-alt "DashboardWidget" (param 0))))
                                      (if (eq (u16 15) (identifier "label2_196")) 
                                        (add (size 2) (apply (ext-identifier alerting_contact sersize-of-row-binary) (get-alt "AlertingContact" (param 0))))
                                        (if (eq (u16 16) (identifier "label2_196")) 
                                          (add (size 2) (apply (ext-identifier alerting_notification sersize-of-row-binary) (get-alt "Notification" (param 0))))
                                          (if (eq (u16 17) (identifier "label2_196")) 
                                            (add (size 2) (apply (ext-identifier alerting_delivery_status sersize-of-row-binary) (get-alt "DeliveryStatus" (param 0))))
                                            (if (eq (u16 18) (identifier "label2_196")) 
                                              (add (size 2) (apply (ext-identifier alerting_log sersize-of-row-binary) (get-alt "IncidentLog" (param 0))))
                                              (seq (assert (eq (identifier "label2_196") (u16 19))) (add (size 2) (apply (ext-identifier alerting_inhibition sersize-of-row-binary) (get-alt "Inhibition" (param 0))))))))))))))))))))))))))
 */
static std::function<Size(::dessser::gen::sync_value::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_value::t*)> fun269 { [&fun269](::dessser::gen::sync_value::t* p_0) {
    uint16_t id_270 { uint16_t((*p_0).index()) };
    Size let_res_271;
    {
      uint16_t label2_196 { id_270 };
      uint16_t id_272 { 0 };
      bool id_273 { bool(id_272 == label2_196) };
      Size choose_res_274;
      if (id_273) {
        Size id_275 { 14UL };
        ::dessser::gen::sync_value::tde68d14dd253c0005e157424dd8fc48d id_276 { std::get<0 /* Error */>((*p_0)) };
        std::string id_277 { std::get<2>(id_276) };
        uint32_t id_278 { (uint32_t)id_277.size() };
        Vec<1, uint32_t> id_279 {  id_278  };
        Size let_res_280;
        {
          Vec<1, uint32_t> n_ref_210 { id_279 };
          uint32_t id_281 { 1U };
          Vec<1, uint32_t> id_282 {  id_281  };
          Size let_res_283;
          {
            Vec<1, uint32_t> lebsz_ref_211 { id_282 };
            bool while_flag_284 { true };
            do {
              uint8_t id_285 { 0 };
              uint32_t id_286 { n_ref_210[id_285] };
              uint8_t id_287 { 0 };
              uint32_t id_288 { lebsz_ref_211[id_287] };
              uint8_t id_289 { 7 };
              uint32_t id_290 { uint32_t(id_288 << id_289) };
              bool id_291 { bool(id_286 >= id_290) };
              while_flag_284 = id_291;
              if (while_flag_284) {
                uint8_t id_292 { 0 };
                uint8_t id_293 { 0 };
                uint32_t id_294 { lebsz_ref_211[id_293] };
                uint32_t id_295 { 1U };
                uint32_t id_296 { uint32_t(id_294 + id_295) };
                Void id_297 { ((void)(lebsz_ref_211[id_292] = id_296), VOID) };
                (void)id_297;
              }
            } while (while_flag_284);
            (void)VOID;
            uint8_t id_298 { 0 };
            uint32_t id_299 { lebsz_ref_211[id_298] };
            Size id_300 { Size(id_299) };
            let_res_283 = id_300;
          }
          let_res_280 = let_res_283;
        }
        ::dessser::gen::sync_value::tde68d14dd253c0005e157424dd8fc48d id_301 { std::get<0 /* Error */>((*p_0)) };
        std::string id_302 { std::get<2>(id_301) };
        uint32_t id_303 { (uint32_t)id_302.size() };
        Size id_304 { Size(id_303) };
        Size id_305 { Size(let_res_280 + id_304) };
        Size id_306 { Size(id_275 + id_305) };
        choose_res_274 = id_306;
      } else {
        uint16_t id_307 { 1 };
        bool id_308 { bool(id_307 == label2_196) };
        Size choose_res_309;
        if (id_308) {
          Size id_310 { 2UL };
          auto fun311 { dessser::gen::worker::sersize_of_row_binary };
          dessser::gen::worker::t_ext id_312 { std::get<1 /* Worker */>((*p_0)) };
          Size id_313 { fun311(id_312) };
          Size id_314 { Size(id_310 + id_313) };
          choose_res_309 = id_314;
        } else {
          uint16_t id_315 { 2 };
          bool id_316 { bool(id_315 == label2_196) };
          Size choose_res_317;
          if (id_316) {
            Size id_318 { 2UL };
            auto fun319 { dessser::gen::retention::sersize_of_row_binary };
            dessser::gen::retention::t_ext id_320 { std::get<2 /* Retention */>((*p_0)) };
            Size id_321 { fun319(id_320) };
            Size id_322 { Size(id_318 + id_321) };
            choose_res_317 = id_322;
          } else {
            uint16_t id_323 { 3 };
            bool id_324 { bool(id_323 == label2_196) };
            Size choose_res_325;
            if (id_324) {
              Size id_326 { 2UL };
              auto fun327 { dessser::gen::time_range::sersize_of_row_binary };
              dessser::gen::time_range::t_ext id_328 { std::get<3 /* TimeRange */>((*p_0)) };
              Size id_329 { fun327(id_328) };
              Size id_330 { Size(id_326 + id_329) };
              choose_res_325 = id_330;
            } else {
              uint16_t id_331 { 4 };
              bool id_332 { bool(id_331 == label2_196) };
              Size choose_res_333;
              if (id_332) {
                Size id_334 { 2UL };
                Arr<::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2> id_335 { std::get<4 /* Tuples */>((*p_0)) };
                uint32_t id_336 { id_335.size() };
                Vec<1, uint32_t> id_337 {  id_336  };
                Size let_res_338;
                {
                  Vec<1, uint32_t> n_ref_197 { id_337 };
                  uint32_t id_339 { 1U };
                  Vec<1, uint32_t> id_340 {  id_339  };
                  Size let_res_341;
                  {
                    Vec<1, uint32_t> lebsz_ref_198 { id_340 };
                    bool while_flag_342 { true };
                    do {
                      uint8_t id_343 { 0 };
                      uint32_t id_344 { n_ref_197[id_343] };
                      uint8_t id_345 { 0 };
                      uint32_t id_346 { lebsz_ref_198[id_345] };
                      uint8_t id_347 { 7 };
                      uint32_t id_348 { uint32_t(id_346 << id_347) };
                      bool id_349 { bool(id_344 >= id_348) };
                      while_flag_342 = id_349;
                      if (while_flag_342) {
                        uint8_t id_350 { 0 };
                        uint8_t id_351 { 0 };
                        uint32_t id_352 { lebsz_ref_198[id_351] };
                        uint32_t id_353 { 1U };
                        uint32_t id_354 { uint32_t(id_352 + id_353) };
                        Void id_355 { ((void)(lebsz_ref_198[id_350] = id_354), VOID) };
                        (void)id_355;
                      }
                    } while (while_flag_342);
                    (void)VOID;
                    uint8_t id_356 { 0 };
                    uint32_t id_357 { lebsz_ref_198[id_356] };
                    Size id_358 { Size(id_357) };
                    let_res_341 = id_358;
                  }
                  let_res_338 = let_res_341;
                }
                Size id_359 { Size(id_334 + let_res_338) };
                Vec<1, Size> id_360 {  id_359  };
                Size let_res_361;
                {
                  Vec<1, Size> sz_ref_199 { id_360 };
                  int32_t id_362 { 0L };
                  Vec<1, int32_t> id_363 {  id_362  };
                  {
                    Vec<1, int32_t> repeat_n_200 { id_363 };
                    bool while_flag_364 { true };
                    do {
                      Arr<::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2> id_365 { std::get<4 /* Tuples */>((*p_0)) };
                      uint32_t id_366 { id_365.size() };
                      int32_t id_367 { int32_t(id_366) };
                      uint8_t id_368 { 0 };
                      int32_t id_369 { repeat_n_200[id_368] };
                      bool id_370 { bool(id_367 > id_369) };
                      while_flag_364 = id_370;
                      if (while_flag_364) {
                        uint8_t id_371 { 0 };
                        uint8_t id_372 { 0 };
                        Size id_373 { sz_ref_199[id_372] };
                        Size id_374 { 4UL };
                        Size id_375 { Size(id_373 + id_374) };
                        Size let_res_376;
                        {
                          Size sz_202 { id_375 };
                          uint8_t id_377 { 0 };
                          int32_t id_378 { repeat_n_200[id_377] };
                          Arr<::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2> id_379 { std::get<4 /* Tuples */>((*p_0)) };
                          ::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2 id_380 { id_379[id_378] };
                          Bytes id_381 { id_380.values };
                          Size id_382 { id_381.length() };
                          Size let_res_383;
                          {
                            Size wlen_203 { id_382 };
                            uint32_t id_384 { uint32_t(wlen_203) };
                            Vec<1, uint32_t> id_385 {  id_384  };
                            Size let_res_386;
                            {
                              Vec<1, uint32_t> n_ref_204 { id_385 };
                              uint32_t id_387 { 1U };
                              Vec<1, uint32_t> id_388 {  id_387  };
                              Size let_res_389;
                              {
                                Vec<1, uint32_t> lebsz_ref_205 { id_388 };
                                bool while_flag_390 { true };
                                do {
                                  uint8_t id_391 { 0 };
                                  uint32_t id_392 { n_ref_204[id_391] };
                                  uint8_t id_393 { 0 };
                                  uint32_t id_394 { lebsz_ref_205[id_393] };
                                  uint8_t id_395 { 7 };
                                  uint32_t id_396 { uint32_t(id_394 << id_395) };
                                  bool id_397 { bool(id_392 >= id_396) };
                                  while_flag_390 = id_397;
                                  if (while_flag_390) {
                                    uint8_t id_398 { 0 };
                                    uint8_t id_399 { 0 };
                                    uint32_t id_400 { lebsz_ref_205[id_399] };
                                    uint32_t id_401 { 1U };
                                    uint32_t id_402 { uint32_t(id_400 + id_401) };
                                    Void id_403 { ((void)(lebsz_ref_205[id_398] = id_402), VOID) };
                                    (void)id_403;
                                  }
                                } while (while_flag_390);
                                (void)VOID;
                                uint8_t id_404 { 0 };
                                uint32_t id_405 { lebsz_ref_205[id_404] };
                                Size id_406 { Size(id_405) };
                                let_res_389 = id_406;
                              }
                              let_res_386 = let_res_389;
                            }
                            Size id_407 { Size(let_res_386 + wlen_203) };
                            let_res_383 = id_407;
                          }
                          Size id_408 { Size(sz_202 + let_res_383) };
                          let_res_376 = id_408;
                        }
                        Void id_409 { ((void)(sz_ref_199[id_371] = let_res_376), VOID) };
                        (void)id_409;
                        uint8_t id_410 { 0 };
                        uint8_t id_411 { 0 };
                        int32_t id_412 { repeat_n_200[id_411] };
                        int32_t id_413 { 1L };
                        int32_t id_414 { int32_t(id_412 + id_413) };
                        Void id_415 { ((void)(repeat_n_200[id_410] = id_414), VOID) };
                        (void)id_415;
                        (void)id_415;
                      }
                    } while (while_flag_364);
                    (void)VOID;
                  }
                  (void)VOID;
                  uint8_t id_416 { 0 };
                  Size id_417 { sz_ref_199[id_416] };
                  let_res_361 = id_417;
                }
                choose_res_333 = let_res_361;
              } else {
                uint16_t id_418 { 5 };
                bool id_419 { bool(id_418 == label2_196) };
                Size choose_res_420;
                if (id_419) {
                  Size id_421 { 2UL };
                  auto fun422 { dessser::gen::raql_value::sersize_of_row_binary };
                  dessser::gen::raql_value::t_ext id_423 { std::get<5 /* RamenValue */>((*p_0)) };
                  Size id_424 { fun422(id_423) };
                  Size id_425 { Size(id_421 + id_424) };
                  choose_res_420 = id_425;
                } else {
                  uint16_t id_426 { 6 };
                  bool id_427 { bool(id_426 == label2_196) };
                  Size choose_res_428;
                  if (id_427) {
                    Size id_429 { 2UL };
                    auto fun430 { dessser::gen::target_config::sersize_of_row_binary };
                    dessser::gen::target_config::t_ext id_431 { std::get<6 /* TargetConfig */>((*p_0)) };
                    Size id_432 { fun430(id_431) };
                    Size id_433 { Size(id_429 + id_432) };
                    choose_res_428 = id_433;
                  } else {
                    uint16_t id_434 { 7 };
                    bool id_435 { bool(id_434 == label2_196) };
                    Size choose_res_436;
                    if (id_435) {
                      Size id_437 { 2UL };
                      auto fun438 { dessser::gen::source_info::sersize_of_row_binary };
                      dessser::gen::source_info::t_ext id_439 { std::get<7 /* SourceInfo */>((*p_0)) };
                      Size id_440 { fun438(id_439) };
                      Size id_441 { Size(id_437 + id_440) };
                      choose_res_436 = id_441;
                    } else {
                      uint16_t id_442 { 8 };
                      bool id_443 { bool(id_442 == label2_196) };
                      Size choose_res_444;
                      if (id_443) {
                        Size id_445 { 2UL };
                        auto fun446 { dessser::gen::runtime_stats::sersize_of_row_binary };
                        dessser::gen::runtime_stats::t_ext id_447 { std::get<8 /* RuntimeStats */>((*p_0)) };
                        Size id_448 { fun446(id_447) };
                        Size id_449 { Size(id_445 + id_448) };
                        choose_res_444 = id_449;
                      } else {
                        uint16_t id_450 { 9 };
                        bool id_451 { bool(id_450 == label2_196) };
                        Size choose_res_452;
                        if (id_451) {
                          Size id_453 { 2UL };
                          auto fun454 { dessser::gen::replay::sersize_of_row_binary };
                          dessser::gen::replay::t_ext id_455 { std::get<9 /* Replay */>((*p_0)) };
                          Size id_456 { fun454(id_455) };
                          Size id_457 { Size(id_453 + id_456) };
                          choose_res_452 = id_457;
                        } else {
                          uint16_t id_458 { 10 };
                          bool id_459 { bool(id_458 == label2_196) };
                          Size choose_res_460;
                          if (id_459) {
                            Size id_461 { 2UL };
                            auto fun462 { dessser::gen::replayer::sersize_of_row_binary };
                            dessser::gen::replayer::t_ext id_463 { std::get<10 /* Replayer */>((*p_0)) };
                            Size id_464 { fun462(id_463) };
                            Size id_465 { Size(id_461 + id_464) };
                            choose_res_460 = id_465;
                          } else {
                            uint16_t id_466 { 11 };
                            bool id_467 { bool(id_466 == label2_196) };
                            Size choose_res_468;
                            if (id_467) {
                              Size id_469 { 2UL };
                              auto fun470 { dessser::gen::replay_request::sersize_of_row_binary };
                              dessser::gen::replay_request::t_ext id_471 { std::get<11 /* ReplayRequest */>((*p_0)) };
                              Size id_472 { fun470(id_471) };
                              Size id_473 { Size(id_469 + id_472) };
                              choose_res_468 = id_473;
                            } else {
                              uint16_t id_474 { 12 };
                              bool id_475 { bool(id_474 == label2_196) };
                              Size choose_res_476;
                              if (id_475) {
                                Size id_477 { 2UL };
                                auto fun478 { dessser::gen::alert::sersize_of_row_binary };
                                dessser::gen::alert::t_ext id_479 { std::get<12 /* Alert */>((*p_0)) };
                                Size id_480 { fun478(id_479) };
                                Size id_481 { Size(id_477 + id_480) };
                                choose_res_476 = id_481;
                              } else {
                                uint16_t id_482 { 13 };
                                bool id_483 { bool(id_482 == label2_196) };
                                Size choose_res_484;
                                if (id_483) {
                                  Size id_485 { 2UL };
                                  auto fun486 { dessser::gen::output_specs::sersize_of_row_binary };
                                  dessser::gen::output_specs::t_ext id_487 { std::get<13 /* OutputSpecs */>((*p_0)) };
                                  Size id_488 { fun486(id_487) };
                                  Size id_489 { Size(id_485 + id_488) };
                                  choose_res_484 = id_489;
                                } else {
                                  uint16_t id_490 { 14 };
                                  bool id_491 { bool(id_490 == label2_196) };
                                  Size choose_res_492;
                                  if (id_491) {
                                    Size id_493 { 2UL };
                                    auto fun494 { dessser::gen::dashboard_widget::sersize_of_row_binary };
                                    dessser::gen::dashboard_widget::t_ext id_495 { std::get<14 /* DashboardWidget */>((*p_0)) };
                                    Size id_496 { fun494(id_495) };
                                    Size id_497 { Size(id_493 + id_496) };
                                    choose_res_492 = id_497;
                                  } else {
                                    uint16_t id_498 { 15 };
                                    bool id_499 { bool(id_498 == label2_196) };
                                    Size choose_res_500;
                                    if (id_499) {
                                      Size id_501 { 2UL };
                                      auto fun502 { dessser::gen::alerting_contact::sersize_of_row_binary };
                                      dessser::gen::alerting_contact::t_ext id_503 { std::get<15 /* AlertingContact */>((*p_0)) };
                                      Size id_504 { fun502(id_503) };
                                      Size id_505 { Size(id_501 + id_504) };
                                      choose_res_500 = id_505;
                                    } else {
                                      uint16_t id_506 { 16 };
                                      bool id_507 { bool(id_506 == label2_196) };
                                      Size choose_res_508;
                                      if (id_507) {
                                        Size id_509 { 2UL };
                                        auto fun510 { dessser::gen::alerting_notification::sersize_of_row_binary };
                                        dessser::gen::alerting_notification::t_ext id_511 { std::get<16 /* Notification */>((*p_0)) };
                                        Size id_512 { fun510(id_511) };
                                        Size id_513 { Size(id_509 + id_512) };
                                        choose_res_508 = id_513;
                                      } else {
                                        uint16_t id_514 { 17 };
                                        bool id_515 { bool(id_514 == label2_196) };
                                        Size choose_res_516;
                                        if (id_515) {
                                          Size id_517 { 2UL };
                                          auto fun518 { dessser::gen::alerting_delivery_status::sersize_of_row_binary };
                                          dessser::gen::alerting_delivery_status::t_ext id_519 { std::get<17 /* DeliveryStatus */>((*p_0)) };
                                          Size id_520 { fun518(id_519) };
                                          Size id_521 { Size(id_517 + id_520) };
                                          choose_res_516 = id_521;
                                        } else {
                                          uint16_t id_522 { 18 };
                                          bool id_523 { bool(id_522 == label2_196) };
                                          Size choose_res_524;
                                          if (id_523) {
                                            Size id_525 { 2UL };
                                            auto fun526 { dessser::gen::alerting_log::sersize_of_row_binary };
                                            dessser::gen::alerting_log::t_ext id_527 { std::get<18 /* IncidentLog */>((*p_0)) };
                                            Size id_528 { fun526(id_527) };
                                            Size id_529 { Size(id_525 + id_528) };
                                            choose_res_524 = id_529;
                                          } else {
                                            uint16_t id_530 { 19 };
                                            bool id_531 { bool(label2_196 == id_530) };
                                            Void id_532 { ((void)(assert(id_531)), VOID) };
                                            (void)id_532;
                                            Size id_533 { 2UL };
                                            auto fun534 { dessser::gen::alerting_inhibition::sersize_of_row_binary };
                                            dessser::gen::alerting_inhibition::t_ext id_535 { std::get<19 /* Inhibition */>((*p_0)) };
                                            Size id_536 { fun534(id_535) };
                                            Size id_537 { Size(id_533 + id_536) };
                                            choose_res_524 = id_537;
                                          }
                                          choose_res_516 = choose_res_524;
                                        }
                                        choose_res_508 = choose_res_516;
                                      }
                                      choose_res_500 = choose_res_508;
                                    }
                                    choose_res_492 = choose_res_500;
                                  }
                                  choose_res_484 = choose_res_492;
                                }
                                choose_res_476 = choose_res_484;
                              }
                              choose_res_468 = choose_res_476;
                            }
                            choose_res_460 = choose_res_468;
                          }
                          choose_res_452 = choose_res_460;
                        }
                        choose_res_444 = choose_res_452;
                      }
                      choose_res_436 = choose_res_444;
                    }
                    choose_res_428 = choose_res_436;
                  }
                  choose_res_420 = choose_res_428;
                }
                choose_res_333 = choose_res_420;
              }
              choose_res_325 = choose_res_333;
            }
            choose_res_317 = choose_res_325;
          }
          choose_res_309 = choose_res_317;
        }
        choose_res_274 = choose_res_309;
      }
      let_res_271 = choose_res_274;
    }
    return let_res_271;
  }
   };
  return fun269;
}
std::function<Size(::dessser::gen::sync_value::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_194" "make_snd_195"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let "dtup_166" (let-pair "dfloat_fst_164" "dfloat_snd_165" (read-u64 little-endian (identifier "dsum1_snd_64")) (make-tup (float-of-u64 (identifier "dfloat_fst_164")) (identifier "dfloat_snd_165")))
                (let-pair "dtup_fst_167" "dtup_snd_168" (identifier "dtup_166")
                  (let "dtup_172" (let-pair "du32_fst_170" "du32_snd_171" (read-u32 little-endian (identifier "dtup_snd_168")) (make-tup (identifier "du32_fst_170") (identifier "du32_snd_171")))
                    (let-pair "dtup_fst_173" "dtup_snd_174" (identifier "dtup_172")
                      (let "dstring1_181"
                        (let "leb_ref_175" (make-vec (u32 0))
                          (let "shft_ref_176" (make-vec (u8 0))
                            (let "p_ref_177" (make-vec (identifier "dtup_snd_174"))
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
                            (make-tup
                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 0
                                (make-tup (identifier "dtup_fst_167") (identifier "dtup_fst_173") (string-of-bytes (identifier "dstring2_fst_185")))) 
                              (identifier "dstring2_snd_186")))))))))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (let-pair "dsum2_fst_161" "dsum2_snd_162" (apply (ext-identifier worker of-row-binary) (identifier "dsum1_snd_64"))
                  (make-tup
                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 1
                      (identifier "dsum2_fst_161")) (identifier "dsum2_snd_162")))
                (if (eq (u16 2) (identifier "dsum1_fst_63"))
                  (let-pair "dsum2_fst_158" "dsum2_snd_159" (apply (ext-identifier retention of-row-binary) (identifier "dsum1_snd_64"))
                    (make-tup
                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 2
                        (identifier "dsum2_fst_158")) (identifier "dsum2_snd_159")))
                  (if (eq (u16 3) (identifier "dsum1_fst_63"))
                    (let-pair "dsum2_fst_155" "dsum2_snd_156" (apply (ext-identifier time_range of-row-binary) (identifier "dsum1_snd_64"))
                      (make-tup
                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 3
                          (identifier "dsum2_fst_155")) (identifier "dsum2_snd_156")))
                    (if (eq (u16 4) (identifier "dsum1_fst_63"))
                      (let-pair "dlist4_fst_149" "dlist4_snd_150"
                        (let "dlist1_119"
                          (let "leb_ref_110" (make-vec (u32 0))
                            (let "shft_ref_111" (make-vec (u8 0))
                              (let "p_ref_112" (make-vec (identifier "dsum1_snd_64"))
                                (seq
                                  (while
                                    (let "leb128_113" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_112")))
                                      (let-pair "leb128_fst_114" "leb128_snd_115" 
                                        (identifier "leb128_113")
                                        (seq (set-vec (u8 0) (identifier "p_ref_112") (identifier "leb128_snd_115"))
                                          (set-vec (u8 0) (identifier "leb_ref_110")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_114") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_111"))) (unsafe-nth (u8 0) (identifier "leb_ref_110"))))
                                          (set-vec (u8 0) (identifier "shft_ref_111") (add (unsafe-nth (u8 0) (identifier "shft_ref_111")) (u8 7))) 
                                          (ge (identifier "leb128_fst_114") (u8 128))))) 
                                    (nop)) (make-tup (unsafe-nth (u8 0) (identifier "leb_ref_110")) (unsafe-nth (u8 0) (identifier "p_ref_112")))))))
                          (let-pair "dlist1_fst_120" "dlist1_snd_121" 
                            (identifier "dlist1_119")
                            (let "inits_src_ref_122" (make-vec (make-tup (end-of-list "{skipped: U32; values: Bytes}") (identifier "dlist1_snd_121")))
                              (seq
                                (let "repeat_n_123" (make-vec (i32 0))
                                  (while (gt (to-i32 (identifier "dlist1_fst_120")) (unsafe-nth (u8 0) (identifier "repeat_n_123")))
                                    (seq
                                      (let "dlist2_124" (unsafe-nth (u8 0) (identifier "inits_src_ref_122"))
                                        (let-pair "dlist2_fst_125" "dlist2_snd_126" 
                                          (identifier "dlist2_124")
                                          (set-vec (u8 0) (identifier "inits_src_ref_122")
                                            (let "drec_130" (let-pair "du32_fst_128" "du32_snd_129" (read-u32 little-endian (identifier "dlist2_snd_126")) (make-tup (identifier "du32_fst_128") (identifier "du32_snd_129")))
                                              (let-pair "drec_fst_131" "drec_snd_132" 
                                                (identifier "drec_130")
                                                (let-pair "drec_fst_143" "drec_snd_144"
                                                  (let "dbytes1_139"
                                                    (let "leb_ref_133" 
                                                      (make-vec (u32 0))
                                                      (let "shft_ref_134" 
                                                        (make-vec (u8 0))
                                                        (let "p_ref_135" 
                                                          (make-vec (identifier "drec_snd_132"))
                                                          (seq
                                                            (while
                                                              (let "leb128_136" 
                                                                (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_135")))
                                                                (let-pair "leb128_fst_137" "leb128_snd_138" 
                                                                  (identifier "leb128_136")
                                                                  (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_135") (identifier "leb128_snd_138"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_133")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_137") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_134")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_133")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_134") (add (unsafe-nth (u8 0) (identifier "shft_ref_134")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_137") (u8 128))))) 
                                                              (nop)) 
                                                            (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_133"))) (unsafe-nth (u8 0) (identifier "p_ref_135")))))))
                                                    (let-pair "dbytes1_fst_140" "dbytes1_snd_141" (identifier "dbytes1_139") (read-bytes (identifier "dbytes1_snd_141") (identifier "dbytes1_fst_140"))))
                                                  (make-tup (cons (make-rec (string "values") (identifier "drec_fst_143") (string "skipped") (identifier "drec_fst_131")) (identifier "dlist2_fst_125")) (identifier "drec_snd_144"))))))))
                                      (set-vec (u8 0) (identifier "repeat_n_123") (add (unsafe-nth (u8 0) (identifier "repeat_n_123")) (i32 1)))))) 
                                (unsafe-nth (u8 0) (identifier "inits_src_ref_122"))))))
                        (make-tup
                          (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 4
                            (arr-of-lst-rev (identifier "dlist4_fst_149"))) 
                          (identifier "dlist4_snd_150")))
                      (if (eq (u16 5) (identifier "dsum1_fst_63"))
                        (let-pair "dsum2_fst_108" "dsum2_snd_109" (apply (ext-identifier raql_value of-row-binary) (identifier "dsum1_snd_64"))
                          (make-tup
                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 5
                              (identifier "dsum2_fst_108")) (identifier "dsum2_snd_109")))
                        (if (eq (u16 6) (identifier "dsum1_fst_63"))
                          (let-pair "dsum2_fst_105" "dsum2_snd_106" (apply (ext-identifier target_config of-row-binary) (identifier "dsum1_snd_64"))
                            (make-tup
                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 6
                                (identifier "dsum2_fst_105")) (identifier "dsum2_snd_106")))
                          (if (eq (u16 7) (identifier "dsum1_fst_63"))
                            (let-pair "dsum2_fst_102" "dsum2_snd_103" 
                              (apply (ext-identifier source_info of-row-binary) (identifier "dsum1_snd_64"))
                              (make-tup
                                (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 7
                                  (identifier "dsum2_fst_102")) (identifier "dsum2_snd_103")))
                            (if (eq (u16 8) (identifier "dsum1_fst_63"))
                              (let-pair "dsum2_fst_99" "dsum2_snd_100" 
                                (apply (ext-identifier runtime_stats of-row-binary) (identifier "dsum1_snd_64"))
                                (make-tup
                                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 8
                                    (identifier "dsum2_fst_99")) (identifier "dsum2_snd_100")))
                              (if (eq (u16 9) (identifier "dsum1_fst_63"))
                                (let-pair "dsum2_fst_96" "dsum2_snd_97" 
                                  (apply (ext-identifier replay of-row-binary) (identifier "dsum1_snd_64"))
                                  (make-tup
                                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 9
                                      (identifier "dsum2_fst_96")) (identifier "dsum2_snd_97")))
                                (if (eq (u16 10) (identifier "dsum1_fst_63"))
                                  (let-pair "dsum2_fst_93" "dsum2_snd_94" 
                                    (apply (ext-identifier replayer of-row-binary) (identifier "dsum1_snd_64"))
                                    (make-tup
                                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 10
                                        (identifier "dsum2_fst_93")) 
                                      (identifier "dsum2_snd_94")))
                                  (if (eq (u16 11) (identifier "dsum1_fst_63"))
                                    (let-pair "dsum2_fst_90" "dsum2_snd_91" 
                                      (apply (ext-identifier replay_request of-row-binary) (identifier "dsum1_snd_64"))
                                      (make-tup
                                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 11
                                          (identifier "dsum2_fst_90")) 
                                        (identifier "dsum2_snd_91")))
                                    (if (eq (u16 12) (identifier "dsum1_fst_63"))
                                      (let-pair "dsum2_fst_87" "dsum2_snd_88" 
                                        (apply (ext-identifier alert of-row-binary) (identifier "dsum1_snd_64"))
                                        (make-tup
                                          (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 12
                                            (identifier "dsum2_fst_87")) 
                                          (identifier "dsum2_snd_88")))
                                      (if (eq (u16 13) (identifier "dsum1_fst_63"))
                                        (let-pair "dsum2_fst_84" "dsum2_snd_85" 
                                          (apply (ext-identifier output_specs of-row-binary) (identifier "dsum1_snd_64"))
                                          (make-tup
                                            (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 13
                                              (identifier "dsum2_fst_84")) 
                                            (identifier "dsum2_snd_85")))
                                        (if (eq (u16 14) (identifier "dsum1_fst_63"))
                                          (let-pair "dsum2_fst_81" "dsum2_snd_82" 
                                            (apply (ext-identifier dashboard_widget of-row-binary) (identifier "dsum1_snd_64"))
                                            (make-tup
                                              (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 14
                                                (identifier "dsum2_fst_81")) 
                                              (identifier "dsum2_snd_82")))
                                          (if (eq (u16 15) (identifier "dsum1_fst_63"))
                                            (let-pair "dsum2_fst_78" "dsum2_snd_79" 
                                              (apply (ext-identifier alerting_contact of-row-binary) (identifier "dsum1_snd_64"))
                                              (make-tup
                                                (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 15
                                                  (identifier "dsum2_fst_78")) 
                                                (identifier "dsum2_snd_79")))
                                            (if (eq (u16 16) (identifier "dsum1_fst_63"))
                                              (let-pair "dsum2_fst_75" "dsum2_snd_76" 
                                                (apply (ext-identifier alerting_notification of-row-binary) (identifier "dsum1_snd_64"))
                                                (make-tup
                                                  (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 16
                                                    (identifier "dsum2_fst_75")) 
                                                  (identifier "dsum2_snd_76")))
                                              (if (eq (u16 17) (identifier "dsum1_fst_63"))
                                                (let-pair "dsum2_fst_72" "dsum2_snd_73" 
                                                  (apply (ext-identifier alerting_delivery_status of-row-binary) (identifier "dsum1_snd_64"))
                                                  (make-tup
                                                    (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 17
                                                      (identifier "dsum2_fst_72")) 
                                                    (identifier "dsum2_snd_73")))
                                                (if (eq (u16 18) (identifier "dsum1_fst_63"))
                                                  (let-pair "dsum2_fst_69" "dsum2_snd_70" 
                                                    (apply (ext-identifier alerting_log of-row-binary) (identifier "dsum1_snd_64"))
                                                    (make-tup
                                                      (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 18
                                                        (identifier "dsum2_fst_69")) 
                                                      (identifier "dsum2_snd_70")))
                                                  (seq (assert (eq (identifier "dsum1_fst_63") (u16 19)))
                                                    (let-pair "dsum2_fst_66" "dsum2_snd_67" 
                                                      (apply (ext-identifier alerting_inhibition of-row-binary) (identifier "dsum1_snd_64"))
                                                      (make-tup
                                                        (construct "[Error (FLOAT; U32; STRING) | Worker $worker | Retention $retention | TimeRange $time_range | Tuples {skipped: U32; values: Bytes}[] | RamenValue $raql_value | TargetConfig $target_config | SourceInfo $source_info | RuntimeStats $runtime_stats | Replay $replay | Replayer $replayer | ReplayRequest $replay_request | Alert $alert | OutputSpecs $output_specs | DashboardWidget $dashboard_widget | AlertingContact $alerting_contact | Notification $alerting_notification | DeliveryStatus $alerting_delivery_status | IncidentLog $alerting_log | Inhibition $alerting_inhibition]" 19
                                                          (identifier "dsum2_fst_66")) 
                                                        (identifier "dsum2_snd_67"))))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_194") (identifier "make_snd_195"))))
 */
static std::function<::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657(Pointer)> fun538 { [&fun538](Pointer p_0) {
    ::dessser::gen::sync_value::t22a32080ad88ab548b80077a17b7dd46 id_539 { p_0.readU16Le() };
    ::dessser::gen::sync_value::t22a32080ad88ab548b80077a17b7dd46 letpair_res_540;
    {
      auto du16_fst_57 { std::get<0>(id_539) };
      auto du16_snd_58 { std::get<1>(id_539) };
      ::dessser::gen::sync_value::t22a32080ad88ab548b80077a17b7dd46 id_541 { du16_fst_57, du16_snd_58 };
      letpair_res_540 = id_541;
    }
    ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 let_res_542;
    {
      ::dessser::gen::sync_value::t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_540 };
      ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_543;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_544 { 0 };
        bool id_545 { bool(id_544 == dsum1_fst_63) };
        ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_546;
        if (id_545) {
          ::dessser::gen::sync_value::t7a47220550fc5126a7b79f1e0c10c645 id_547 { dsum1_snd_64.readU64Le() };
          ::dessser::gen::sync_value::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_548;
          {
            auto dfloat_fst_164 { std::get<0>(id_547) };
            auto dfloat_snd_165 { std::get<1>(id_547) };
            double id_549 { float_of_qword(dfloat_fst_164) };
            ::dessser::gen::sync_value::taebed00ad7fdb3f7ced11d3cfd58aade id_550 { id_549, dfloat_snd_165 };
            letpair_res_548 = id_550;
          }
          ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 let_res_551;
          {
            ::dessser::gen::sync_value::taebed00ad7fdb3f7ced11d3cfd58aade dtup_166 { letpair_res_548 };
            ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_552;
            {
              auto dtup_fst_167 { std::get<0>(dtup_166) };
              auto dtup_snd_168 { std::get<1>(dtup_166) };
              ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 id_553 { dtup_snd_168.readU32Le() };
              ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 letpair_res_554;
              {
                auto du32_fst_170 { std::get<0>(id_553) };
                auto du32_snd_171 { std::get<1>(id_553) };
                ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 id_555 { du32_fst_170, du32_snd_171 };
                letpair_res_554 = id_555;
              }
              ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 let_res_556;
              {
                ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 dtup_172 { letpair_res_554 };
                ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_557;
                {
                  auto dtup_fst_173 { std::get<0>(dtup_172) };
                  auto dtup_snd_174 { std::get<1>(dtup_172) };
                  uint32_t id_558 { 0U };
                  Vec<1, uint32_t> id_559 {  id_558  };
                  ::dessser::gen::sync_value::t8beb80162423aee37bd383e9b6834c9c let_res_560;
                  {
                    Vec<1, uint32_t> leb_ref_175 { id_559 };
                    uint8_t id_561 { 0 };
                    Vec<1, uint8_t> id_562 {  id_561  };
                    ::dessser::gen::sync_value::t8beb80162423aee37bd383e9b6834c9c let_res_563;
                    {
                      Vec<1, uint8_t> shft_ref_176 { id_562 };
                      Vec<1, Pointer> id_564 {  dtup_snd_174  };
                      ::dessser::gen::sync_value::t8beb80162423aee37bd383e9b6834c9c let_res_565;
                      {
                        Vec<1, Pointer> p_ref_177 { id_564 };
                        bool while_flag_566 { true };
                        do {
                          uint8_t id_567 { 0 };
                          Pointer id_568 { p_ref_177[id_567] };
                          ::dessser::gen::sync_value::tb3f98ea670610d40658a618de3ec7b90 id_569 { id_568.readU8() };
                          bool let_res_570;
                          {
                            ::dessser::gen::sync_value::tb3f98ea670610d40658a618de3ec7b90 leb128_178 { id_569 };
                            bool letpair_res_571;
                            {
                              auto leb128_fst_179 { std::get<0>(leb128_178) };
                              auto leb128_snd_180 { std::get<1>(leb128_178) };
                              uint8_t id_572 { 0 };
                              Void id_573 { ((void)(p_ref_177[id_572] = leb128_snd_180), VOID) };
                              (void)id_573;
                              uint8_t id_574 { 0 };
                              uint8_t id_575 { 127 };
                              uint8_t id_576 { uint8_t(leb128_fst_179 & id_575) };
                              uint32_t id_577 { uint32_t(id_576) };
                              uint8_t id_578 { 0 };
                              uint8_t id_579 { shft_ref_176[id_578] };
                              uint32_t id_580 { uint32_t(id_577 << id_579) };
                              uint8_t id_581 { 0 };
                              uint32_t id_582 { leb_ref_175[id_581] };
                              uint32_t id_583 { uint32_t(id_580 | id_582) };
                              Void id_584 { ((void)(leb_ref_175[id_574] = id_583), VOID) };
                              (void)id_584;
                              uint8_t id_585 { 0 };
                              uint8_t id_586 { 0 };
                              uint8_t id_587 { shft_ref_176[id_586] };
                              uint8_t id_588 { 7 };
                              uint8_t id_589 { uint8_t(id_587 + id_588) };
                              Void id_590 { ((void)(shft_ref_176[id_585] = id_589), VOID) };
                              (void)id_590;
                              uint8_t id_591 { 128 };
                              bool id_592 { bool(leb128_fst_179 >= id_591) };
                              letpair_res_571 = id_592;
                            }
                            let_res_570 = letpair_res_571;
                          }
                          while_flag_566 = let_res_570;
                          if (while_flag_566) {
                            (void)VOID;
                          }
                        } while (while_flag_566);
                        (void)VOID;
                        uint8_t id_593 { 0 };
                        uint32_t id_594 { leb_ref_175[id_593] };
                        Size id_595 { Size(id_594) };
                        uint8_t id_596 { 0 };
                        Pointer id_597 { p_ref_177[id_596] };
                        ::dessser::gen::sync_value::t8beb80162423aee37bd383e9b6834c9c id_598 { id_595, id_597 };
                        let_res_565 = id_598;
                      }
                      let_res_563 = let_res_565;
                    }
                    let_res_560 = let_res_563;
                  }
                  ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 let_res_599;
                  {
                    ::dessser::gen::sync_value::t8beb80162423aee37bd383e9b6834c9c dstring1_181 { let_res_560 };
                    ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_600;
                    {
                      auto dstring1_fst_182 { std::get<0>(dstring1_181) };
                      auto dstring1_snd_183 { std::get<1>(dstring1_181) };
                      ::dessser::gen::sync_value::t188345aa49abd0cb47ff73fedc219f08 id_601 { dstring1_snd_183.readBytes(dstring1_fst_182) };
                      ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_602;
                      {
                        auto dstring2_fst_185 { std::get<0>(id_601) };
                        auto dstring2_snd_186 { std::get<1>(id_601) };
                        std::string id_603 { dstring2_fst_185.toString() };
                        ::dessser::gen::sync_value::tde68d14dd253c0005e157424dd8fc48d id_604 { dtup_fst_167, dtup_fst_173, id_603 };
                        ::dessser::gen::sync_value::t* id_605 { new ::dessser::gen::sync_value::t(std::in_place_index<0>, id_604) };
                        ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_606 { id_605, dstring2_snd_186 };
                        letpair_res_602 = id_606;
                      }
                      letpair_res_600 = letpair_res_602;
                    }
                    let_res_599 = letpair_res_600;
                  }
                  letpair_res_557 = let_res_599;
                }
                let_res_556 = letpair_res_557;
              }
              letpair_res_552 = let_res_556;
            }
            let_res_551 = letpair_res_552;
          }
          choose_res_546 = let_res_551;
        } else {
          uint16_t id_607 { 1 };
          bool id_608 { bool(id_607 == dsum1_fst_63) };
          ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_609;
          if (id_608) {
            auto fun610 { dessser::gen::worker::of_row_binary };
            ::dessser::gen::sync_value::t134551dd3247bb0c2e40279e9eddb2ac id_611 { fun610(dsum1_snd_64) };
            ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_612;
            {
              auto dsum2_fst_161 { std::get<0>(id_611) };
              auto dsum2_snd_162 { std::get<1>(id_611) };
              ::dessser::gen::sync_value::t* id_613 { new ::dessser::gen::sync_value::t(std::in_place_index<1>, dsum2_fst_161) };
              ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_614 { id_613, dsum2_snd_162 };
              letpair_res_612 = id_614;
            }
            choose_res_609 = letpair_res_612;
          } else {
            uint16_t id_615 { 2 };
            bool id_616 { bool(id_615 == dsum1_fst_63) };
            ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_617;
            if (id_616) {
              auto fun618 { dessser::gen::retention::of_row_binary };
              ::dessser::gen::sync_value::t7c83e84e0162e9442953bc16c018e153 id_619 { fun618(dsum1_snd_64) };
              ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_620;
              {
                auto dsum2_fst_158 { std::get<0>(id_619) };
                auto dsum2_snd_159 { std::get<1>(id_619) };
                ::dessser::gen::sync_value::t* id_621 { new ::dessser::gen::sync_value::t(std::in_place_index<2>, dsum2_fst_158) };
                ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_622 { id_621, dsum2_snd_159 };
                letpair_res_620 = id_622;
              }
              choose_res_617 = letpair_res_620;
            } else {
              uint16_t id_623 { 3 };
              bool id_624 { bool(id_623 == dsum1_fst_63) };
              ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_625;
              if (id_624) {
                auto fun626 { dessser::gen::time_range::of_row_binary };
                ::dessser::gen::sync_value::t2cd1b6aab4060eb2dceb682cd53d34da id_627 { fun626(dsum1_snd_64) };
                ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_628;
                {
                  auto dsum2_fst_155 { std::get<0>(id_627) };
                  auto dsum2_snd_156 { std::get<1>(id_627) };
                  ::dessser::gen::sync_value::t* id_629 { new ::dessser::gen::sync_value::t(std::in_place_index<3>, dsum2_fst_155) };
                  ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_630 { id_629, dsum2_snd_156 };
                  letpair_res_628 = id_630;
                }
                choose_res_625 = letpair_res_628;
              } else {
                uint16_t id_631 { 4 };
                bool id_632 { bool(id_631 == dsum1_fst_63) };
                ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_633;
                if (id_632) {
                  uint32_t id_634 { 0U };
                  Vec<1, uint32_t> id_635 {  id_634  };
                  ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 let_res_636;
                  {
                    Vec<1, uint32_t> leb_ref_110 { id_635 };
                    uint8_t id_637 { 0 };
                    Vec<1, uint8_t> id_638 {  id_637  };
                    ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 let_res_639;
                    {
                      Vec<1, uint8_t> shft_ref_111 { id_638 };
                      Vec<1, Pointer> id_640 {  dsum1_snd_64  };
                      ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 let_res_641;
                      {
                        Vec<1, Pointer> p_ref_112 { id_640 };
                        bool while_flag_642 { true };
                        do {
                          uint8_t id_643 { 0 };
                          Pointer id_644 { p_ref_112[id_643] };
                          ::dessser::gen::sync_value::tb3f98ea670610d40658a618de3ec7b90 id_645 { id_644.readU8() };
                          bool let_res_646;
                          {
                            ::dessser::gen::sync_value::tb3f98ea670610d40658a618de3ec7b90 leb128_113 { id_645 };
                            bool letpair_res_647;
                            {
                              auto leb128_fst_114 { std::get<0>(leb128_113) };
                              auto leb128_snd_115 { std::get<1>(leb128_113) };
                              uint8_t id_648 { 0 };
                              Void id_649 { ((void)(p_ref_112[id_648] = leb128_snd_115), VOID) };
                              (void)id_649;
                              uint8_t id_650 { 0 };
                              uint8_t id_651 { 127 };
                              uint8_t id_652 { uint8_t(leb128_fst_114 & id_651) };
                              uint32_t id_653 { uint32_t(id_652) };
                              uint8_t id_654 { 0 };
                              uint8_t id_655 { shft_ref_111[id_654] };
                              uint32_t id_656 { uint32_t(id_653 << id_655) };
                              uint8_t id_657 { 0 };
                              uint32_t id_658 { leb_ref_110[id_657] };
                              uint32_t id_659 { uint32_t(id_656 | id_658) };
                              Void id_660 { ((void)(leb_ref_110[id_650] = id_659), VOID) };
                              (void)id_660;
                              uint8_t id_661 { 0 };
                              uint8_t id_662 { 0 };
                              uint8_t id_663 { shft_ref_111[id_662] };
                              uint8_t id_664 { 7 };
                              uint8_t id_665 { uint8_t(id_663 + id_664) };
                              Void id_666 { ((void)(shft_ref_111[id_661] = id_665), VOID) };
                              (void)id_666;
                              uint8_t id_667 { 128 };
                              bool id_668 { bool(leb128_fst_114 >= id_667) };
                              letpair_res_647 = id_668;
                            }
                            let_res_646 = letpair_res_647;
                          }
                          while_flag_642 = let_res_646;
                          if (while_flag_642) {
                            (void)VOID;
                          }
                        } while (while_flag_642);
                        (void)VOID;
                        uint8_t id_669 { 0 };
                        uint32_t id_670 { leb_ref_110[id_669] };
                        uint8_t id_671 { 0 };
                        Pointer id_672 { p_ref_112[id_671] };
                        ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 id_673 { id_670, id_672 };
                        let_res_641 = id_673;
                      }
                      let_res_639 = let_res_641;
                    }
                    let_res_636 = let_res_639;
                  }
                  ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b let_res_674;
                  {
                    ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 dlist1_119 { let_res_636 };
                    ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b letpair_res_675;
                    {
                      auto dlist1_fst_120 { std::get<0>(dlist1_119) };
                      auto dlist1_snd_121 { std::get<1>(dlist1_119) };
                      Lst<::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2> endoflist_676;
                      ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b id_677 { endoflist_676, dlist1_snd_121 };
                      Vec<1, ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b> id_678 {  id_677  };
                      ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b let_res_679;
                      {
                        Vec<1, ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b> inits_src_ref_122 { id_678 };
                        int32_t id_680 { 0L };
                        Vec<1, int32_t> id_681 {  id_680  };
                        {
                          Vec<1, int32_t> repeat_n_123 { id_681 };
                          bool while_flag_682 { true };
                          do {
                            int32_t id_683 { int32_t(dlist1_fst_120) };
                            uint8_t id_684 { 0 };
                            int32_t id_685 { repeat_n_123[id_684] };
                            bool id_686 { bool(id_683 > id_685) };
                            while_flag_682 = id_686;
                            if (while_flag_682) {
                              uint8_t id_687 { 0 };
                              ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b id_688 { inits_src_ref_122[id_687] };
                              {
                                ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b dlist2_124 { id_688 };
                                {
                                  auto dlist2_fst_125 { std::get<0>(dlist2_124) };
                                  auto dlist2_snd_126 { std::get<1>(dlist2_124) };
                                  uint8_t id_689 { 0 };
                                  ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 id_690 { dlist2_snd_126.readU32Le() };
                                  ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 letpair_res_691;
                                  {
                                    auto du32_fst_128 { std::get<0>(id_690) };
                                    auto du32_snd_129 { std::get<1>(id_690) };
                                    ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 id_692 { du32_fst_128, du32_snd_129 };
                                    letpair_res_691 = id_692;
                                  }
                                  ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b let_res_693;
                                  {
                                    ::dessser::gen::sync_value::t405eb186408556fed8f2c41523c07d13 drec_130 { letpair_res_691 };
                                    ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b letpair_res_694;
                                    {
                                      auto drec_fst_131 { std::get<0>(drec_130) };
                                      auto drec_snd_132 { std::get<1>(drec_130) };
                                      uint32_t id_695 { 0U };
                                      Vec<1, uint32_t> id_696 {  id_695  };
                                      ::dessser::gen::sync_value::t8beb80162423aee37bd383e9b6834c9c let_res_697;
                                      {
                                        Vec<1, uint32_t> leb_ref_133 { id_696 };
                                        uint8_t id_698 { 0 };
                                        Vec<1, uint8_t> id_699 {  id_698  };
                                        ::dessser::gen::sync_value::t8beb80162423aee37bd383e9b6834c9c let_res_700;
                                        {
                                          Vec<1, uint8_t> shft_ref_134 { id_699 };
                                          Vec<1, Pointer> id_701 {  drec_snd_132  };
                                          ::dessser::gen::sync_value::t8beb80162423aee37bd383e9b6834c9c let_res_702;
                                          {
                                            Vec<1, Pointer> p_ref_135 { id_701 };
                                            bool while_flag_703 { true };
                                            do {
                                              uint8_t id_704 { 0 };
                                              Pointer id_705 { p_ref_135[id_704] };
                                              ::dessser::gen::sync_value::tb3f98ea670610d40658a618de3ec7b90 id_706 { id_705.readU8() };
                                              bool let_res_707;
                                              {
                                                ::dessser::gen::sync_value::tb3f98ea670610d40658a618de3ec7b90 leb128_136 { id_706 };
                                                bool letpair_res_708;
                                                {
                                                  auto leb128_fst_137 { std::get<0>(leb128_136) };
                                                  auto leb128_snd_138 { std::get<1>(leb128_136) };
                                                  uint8_t id_709 { 0 };
                                                  Void id_710 { ((void)(p_ref_135[id_709] = leb128_snd_138), VOID) };
                                                  (void)id_710;
                                                  uint8_t id_711 { 0 };
                                                  uint8_t id_712 { 127 };
                                                  uint8_t id_713 { uint8_t(leb128_fst_137 & id_712) };
                                                  uint32_t id_714 { uint32_t(id_713) };
                                                  uint8_t id_715 { 0 };
                                                  uint8_t id_716 { shft_ref_134[id_715] };
                                                  uint32_t id_717 { uint32_t(id_714 << id_716) };
                                                  uint8_t id_718 { 0 };
                                                  uint32_t id_719 { leb_ref_133[id_718] };
                                                  uint32_t id_720 { uint32_t(id_717 | id_719) };
                                                  Void id_721 { ((void)(leb_ref_133[id_711] = id_720), VOID) };
                                                  (void)id_721;
                                                  uint8_t id_722 { 0 };
                                                  uint8_t id_723 { 0 };
                                                  uint8_t id_724 { shft_ref_134[id_723] };
                                                  uint8_t id_725 { 7 };
                                                  uint8_t id_726 { uint8_t(id_724 + id_725) };
                                                  Void id_727 { ((void)(shft_ref_134[id_722] = id_726), VOID) };
                                                  (void)id_727;
                                                  uint8_t id_728 { 128 };
                                                  bool id_729 { bool(leb128_fst_137 >= id_728) };
                                                  letpair_res_708 = id_729;
                                                }
                                                let_res_707 = letpair_res_708;
                                              }
                                              while_flag_703 = let_res_707;
                                              if (while_flag_703) {
                                                (void)VOID;
                                              }
                                            } while (while_flag_703);
                                            (void)VOID;
                                            uint8_t id_730 { 0 };
                                            uint32_t id_731 { leb_ref_133[id_730] };
                                            Size id_732 { Size(id_731) };
                                            uint8_t id_733 { 0 };
                                            Pointer id_734 { p_ref_135[id_733] };
                                            ::dessser::gen::sync_value::t8beb80162423aee37bd383e9b6834c9c id_735 { id_732, id_734 };
                                            let_res_702 = id_735;
                                          }
                                          let_res_700 = let_res_702;
                                        }
                                        let_res_697 = let_res_700;
                                      }
                                      ::dessser::gen::sync_value::t188345aa49abd0cb47ff73fedc219f08 let_res_736;
                                      {
                                        ::dessser::gen::sync_value::t8beb80162423aee37bd383e9b6834c9c dbytes1_139 { let_res_697 };
                                        ::dessser::gen::sync_value::t188345aa49abd0cb47ff73fedc219f08 letpair_res_737;
                                        {
                                          auto dbytes1_fst_140 { std::get<0>(dbytes1_139) };
                                          auto dbytes1_snd_141 { std::get<1>(dbytes1_139) };
                                          ::dessser::gen::sync_value::t188345aa49abd0cb47ff73fedc219f08 id_738 { dbytes1_snd_141.readBytes(dbytes1_fst_140) };
                                          letpair_res_737 = id_738;
                                        }
                                        let_res_736 = letpair_res_737;
                                      }
                                      ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b letpair_res_739;
                                      {
                                        auto drec_fst_143 { std::get<0>(let_res_736) };
                                        auto drec_snd_144 { std::get<1>(let_res_736) };
                                        ::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2 id_740 { .skipped = drec_fst_131, .values = drec_fst_143 };
                                        Lst<::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2> id_741 { id_740, dlist2_fst_125 };
                                        ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b id_742 { id_741, drec_snd_144 };
                                        letpair_res_739 = id_742;
                                      }
                                      letpair_res_694 = letpair_res_739;
                                    }
                                    let_res_693 = letpair_res_694;
                                  }
                                  Void id_743 { ((void)(inits_src_ref_122[id_689] = let_res_693), VOID) };
                                  (void)id_743;
                                }
                                (void)VOID;
                              }
                              (void)VOID;
                              uint8_t id_744 { 0 };
                              uint8_t id_745 { 0 };
                              int32_t id_746 { repeat_n_123[id_745] };
                              int32_t id_747 { 1L };
                              int32_t id_748 { int32_t(id_746 + id_747) };
                              Void id_749 { ((void)(repeat_n_123[id_744] = id_748), VOID) };
                              (void)id_749;
                              (void)id_749;
                            }
                          } while (while_flag_682);
                          (void)VOID;
                        }
                        (void)VOID;
                        uint8_t id_750 { 0 };
                        ::dessser::gen::sync_value::ta587c787d7b029489695fe00a437996b id_751 { inits_src_ref_122[id_750] };
                        let_res_679 = id_751;
                      }
                      letpair_res_675 = let_res_679;
                    }
                    let_res_674 = letpair_res_675;
                  }
                  ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_752;
                  {
                    auto dlist4_fst_149 { std::get<0>(let_res_674) };
                    auto dlist4_snd_150 { std::get<1>(let_res_674) };
                    Arr<::dessser::gen::sync_value::te83fa7fcadeeebdddedfae1b0cf34bd2> id_753 { dlist4_fst_149.toListRev() };
                    ::dessser::gen::sync_value::t* id_754 { new ::dessser::gen::sync_value::t(std::in_place_index<4>, id_753) };
                    ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_755 { id_754, dlist4_snd_150 };
                    letpair_res_752 = id_755;
                  }
                  choose_res_633 = letpair_res_752;
                } else {
                  uint16_t id_756 { 5 };
                  bool id_757 { bool(id_756 == dsum1_fst_63) };
                  ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_758;
                  if (id_757) {
                    auto fun759 { dessser::gen::raql_value::of_row_binary };
                    ::dessser::gen::sync_value::t9cfa78b25ddcb5afc14daf6a802a6f88 id_760 { fun759(dsum1_snd_64) };
                    ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_761;
                    {
                      auto dsum2_fst_108 { std::get<0>(id_760) };
                      auto dsum2_snd_109 { std::get<1>(id_760) };
                      ::dessser::gen::sync_value::t* id_762 { new ::dessser::gen::sync_value::t(std::in_place_index<5>, dsum2_fst_108) };
                      ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_763 { id_762, dsum2_snd_109 };
                      letpair_res_761 = id_763;
                    }
                    choose_res_758 = letpair_res_761;
                  } else {
                    uint16_t id_764 { 6 };
                    bool id_765 { bool(id_764 == dsum1_fst_63) };
                    ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_766;
                    if (id_765) {
                      auto fun767 { dessser::gen::target_config::of_row_binary };
                      ::dessser::gen::sync_value::te08e45bff93070c7c714161c85d8bac1 id_768 { fun767(dsum1_snd_64) };
                      ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_769;
                      {
                        auto dsum2_fst_105 { std::get<0>(id_768) };
                        auto dsum2_snd_106 { std::get<1>(id_768) };
                        ::dessser::gen::sync_value::t* id_770 { new ::dessser::gen::sync_value::t(std::in_place_index<6>, dsum2_fst_105) };
                        ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_771 { id_770, dsum2_snd_106 };
                        letpair_res_769 = id_771;
                      }
                      choose_res_766 = letpair_res_769;
                    } else {
                      uint16_t id_772 { 7 };
                      bool id_773 { bool(id_772 == dsum1_fst_63) };
                      ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_774;
                      if (id_773) {
                        auto fun775 { dessser::gen::source_info::of_row_binary };
                        ::dessser::gen::sync_value::tf0808eb091f71d5e62637e5a96e20fd5 id_776 { fun775(dsum1_snd_64) };
                        ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_777;
                        {
                          auto dsum2_fst_102 { std::get<0>(id_776) };
                          auto dsum2_snd_103 { std::get<1>(id_776) };
                          ::dessser::gen::sync_value::t* id_778 { new ::dessser::gen::sync_value::t(std::in_place_index<7>, dsum2_fst_102) };
                          ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_779 { id_778, dsum2_snd_103 };
                          letpair_res_777 = id_779;
                        }
                        choose_res_774 = letpair_res_777;
                      } else {
                        uint16_t id_780 { 8 };
                        bool id_781 { bool(id_780 == dsum1_fst_63) };
                        ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_782;
                        if (id_781) {
                          auto fun783 { dessser::gen::runtime_stats::of_row_binary };
                          ::dessser::gen::sync_value::t5e0d448e4b20dd2a65aeb5cea700d072 id_784 { fun783(dsum1_snd_64) };
                          ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_785;
                          {
                            auto dsum2_fst_99 { std::get<0>(id_784) };
                            auto dsum2_snd_100 { std::get<1>(id_784) };
                            ::dessser::gen::sync_value::t* id_786 { new ::dessser::gen::sync_value::t(std::in_place_index<8>, dsum2_fst_99) };
                            ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_787 { id_786, dsum2_snd_100 };
                            letpair_res_785 = id_787;
                          }
                          choose_res_782 = letpair_res_785;
                        } else {
                          uint16_t id_788 { 9 };
                          bool id_789 { bool(id_788 == dsum1_fst_63) };
                          ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_790;
                          if (id_789) {
                            auto fun791 { dessser::gen::replay::of_row_binary };
                            ::dessser::gen::sync_value::tb33470da5f25cd7882672954c47d23c1 id_792 { fun791(dsum1_snd_64) };
                            ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_793;
                            {
                              auto dsum2_fst_96 { std::get<0>(id_792) };
                              auto dsum2_snd_97 { std::get<1>(id_792) };
                              ::dessser::gen::sync_value::t* id_794 { new ::dessser::gen::sync_value::t(std::in_place_index<9>, dsum2_fst_96) };
                              ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_795 { id_794, dsum2_snd_97 };
                              letpair_res_793 = id_795;
                            }
                            choose_res_790 = letpair_res_793;
                          } else {
                            uint16_t id_796 { 10 };
                            bool id_797 { bool(id_796 == dsum1_fst_63) };
                            ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_798;
                            if (id_797) {
                              auto fun799 { dessser::gen::replayer::of_row_binary };
                              ::dessser::gen::sync_value::t489f46e36aeafd83f541b9ae05cdef2c id_800 { fun799(dsum1_snd_64) };
                              ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_801;
                              {
                                auto dsum2_fst_93 { std::get<0>(id_800) };
                                auto dsum2_snd_94 { std::get<1>(id_800) };
                                ::dessser::gen::sync_value::t* id_802 { new ::dessser::gen::sync_value::t(std::in_place_index<10>, dsum2_fst_93) };
                                ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_803 { id_802, dsum2_snd_94 };
                                letpair_res_801 = id_803;
                              }
                              choose_res_798 = letpair_res_801;
                            } else {
                              uint16_t id_804 { 11 };
                              bool id_805 { bool(id_804 == dsum1_fst_63) };
                              ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_806;
                              if (id_805) {
                                auto fun807 { dessser::gen::replay_request::of_row_binary };
                                ::dessser::gen::sync_value::t1b05239ef21a25a1347706de021d5841 id_808 { fun807(dsum1_snd_64) };
                                ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_809;
                                {
                                  auto dsum2_fst_90 { std::get<0>(id_808) };
                                  auto dsum2_snd_91 { std::get<1>(id_808) };
                                  ::dessser::gen::sync_value::t* id_810 { new ::dessser::gen::sync_value::t(std::in_place_index<11>, dsum2_fst_90) };
                                  ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_811 { id_810, dsum2_snd_91 };
                                  letpair_res_809 = id_811;
                                }
                                choose_res_806 = letpair_res_809;
                              } else {
                                uint16_t id_812 { 12 };
                                bool id_813 { bool(id_812 == dsum1_fst_63) };
                                ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_814;
                                if (id_813) {
                                  auto fun815 { dessser::gen::alert::of_row_binary };
                                  ::dessser::gen::sync_value::t9cd9e34ddfecb0b26fe0f772eb18bd85 id_816 { fun815(dsum1_snd_64) };
                                  ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_817;
                                  {
                                    auto dsum2_fst_87 { std::get<0>(id_816) };
                                    auto dsum2_snd_88 { std::get<1>(id_816) };
                                    ::dessser::gen::sync_value::t* id_818 { new ::dessser::gen::sync_value::t(std::in_place_index<12>, dsum2_fst_87) };
                                    ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_819 { id_818, dsum2_snd_88 };
                                    letpair_res_817 = id_819;
                                  }
                                  choose_res_814 = letpair_res_817;
                                } else {
                                  uint16_t id_820 { 13 };
                                  bool id_821 { bool(id_820 == dsum1_fst_63) };
                                  ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_822;
                                  if (id_821) {
                                    auto fun823 { dessser::gen::output_specs::of_row_binary };
                                    ::dessser::gen::sync_value::t135a9b267c9c18ff8a4c6aa0d72eaff7 id_824 { fun823(dsum1_snd_64) };
                                    ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_825;
                                    {
                                      auto dsum2_fst_84 { std::get<0>(id_824) };
                                      auto dsum2_snd_85 { std::get<1>(id_824) };
                                      ::dessser::gen::sync_value::t* id_826 { new ::dessser::gen::sync_value::t(std::in_place_index<13>, dsum2_fst_84) };
                                      ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_827 { id_826, dsum2_snd_85 };
                                      letpair_res_825 = id_827;
                                    }
                                    choose_res_822 = letpair_res_825;
                                  } else {
                                    uint16_t id_828 { 14 };
                                    bool id_829 { bool(id_828 == dsum1_fst_63) };
                                    ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_830;
                                    if (id_829) {
                                      auto fun831 { dessser::gen::dashboard_widget::of_row_binary };
                                      ::dessser::gen::sync_value::td5d43892c681e8c8e0ae933735d580a4 id_832 { fun831(dsum1_snd_64) };
                                      ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_833;
                                      {
                                        auto dsum2_fst_81 { std::get<0>(id_832) };
                                        auto dsum2_snd_82 { std::get<1>(id_832) };
                                        ::dessser::gen::sync_value::t* id_834 { new ::dessser::gen::sync_value::t(std::in_place_index<14>, dsum2_fst_81) };
                                        ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_835 { id_834, dsum2_snd_82 };
                                        letpair_res_833 = id_835;
                                      }
                                      choose_res_830 = letpair_res_833;
                                    } else {
                                      uint16_t id_836 { 15 };
                                      bool id_837 { bool(id_836 == dsum1_fst_63) };
                                      ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_838;
                                      if (id_837) {
                                        auto fun839 { dessser::gen::alerting_contact::of_row_binary };
                                        ::dessser::gen::sync_value::t24e29d052a88c9ba931ba3dd969f042b id_840 { fun839(dsum1_snd_64) };
                                        ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_841;
                                        {
                                          auto dsum2_fst_78 { std::get<0>(id_840) };
                                          auto dsum2_snd_79 { std::get<1>(id_840) };
                                          ::dessser::gen::sync_value::t* id_842 { new ::dessser::gen::sync_value::t(std::in_place_index<15>, dsum2_fst_78) };
                                          ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_843 { id_842, dsum2_snd_79 };
                                          letpair_res_841 = id_843;
                                        }
                                        choose_res_838 = letpair_res_841;
                                      } else {
                                        uint16_t id_844 { 16 };
                                        bool id_845 { bool(id_844 == dsum1_fst_63) };
                                        ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_846;
                                        if (id_845) {
                                          auto fun847 { dessser::gen::alerting_notification::of_row_binary };
                                          ::dessser::gen::sync_value::t4a3c6489e69a673e7d2022cfc40cf24c id_848 { fun847(dsum1_snd_64) };
                                          ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_849;
                                          {
                                            auto dsum2_fst_75 { std::get<0>(id_848) };
                                            auto dsum2_snd_76 { std::get<1>(id_848) };
                                            ::dessser::gen::sync_value::t* id_850 { new ::dessser::gen::sync_value::t(std::in_place_index<16>, dsum2_fst_75) };
                                            ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_851 { id_850, dsum2_snd_76 };
                                            letpair_res_849 = id_851;
                                          }
                                          choose_res_846 = letpair_res_849;
                                        } else {
                                          uint16_t id_852 { 17 };
                                          bool id_853 { bool(id_852 == dsum1_fst_63) };
                                          ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_854;
                                          if (id_853) {
                                            auto fun855 { dessser::gen::alerting_delivery_status::of_row_binary };
                                            ::dessser::gen::sync_value::tfe00ca7e5541a3abc1bf1027b3a0de04 id_856 { fun855(dsum1_snd_64) };
                                            ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_857;
                                            {
                                              auto dsum2_fst_72 { std::get<0>(id_856) };
                                              auto dsum2_snd_73 { std::get<1>(id_856) };
                                              ::dessser::gen::sync_value::t* id_858 { new ::dessser::gen::sync_value::t(std::in_place_index<17>, dsum2_fst_72) };
                                              ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_859 { id_858, dsum2_snd_73 };
                                              letpair_res_857 = id_859;
                                            }
                                            choose_res_854 = letpair_res_857;
                                          } else {
                                            uint16_t id_860 { 18 };
                                            bool id_861 { bool(id_860 == dsum1_fst_63) };
                                            ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 choose_res_862;
                                            if (id_861) {
                                              auto fun863 { dessser::gen::alerting_log::of_row_binary };
                                              ::dessser::gen::sync_value::td4b7bd975d92d8092bd289b9dcb515a5 id_864 { fun863(dsum1_snd_64) };
                                              ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_865;
                                              {
                                                auto dsum2_fst_69 { std::get<0>(id_864) };
                                                auto dsum2_snd_70 { std::get<1>(id_864) };
                                                ::dessser::gen::sync_value::t* id_866 { new ::dessser::gen::sync_value::t(std::in_place_index<18>, dsum2_fst_69) };
                                                ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_867 { id_866, dsum2_snd_70 };
                                                letpair_res_865 = id_867;
                                              }
                                              choose_res_862 = letpair_res_865;
                                            } else {
                                              uint16_t id_868 { 19 };
                                              bool id_869 { bool(dsum1_fst_63 == id_868) };
                                              Void id_870 { ((void)(assert(id_869)), VOID) };
                                              (void)id_870;
                                              auto fun871 { dessser::gen::alerting_inhibition::of_row_binary };
                                              ::dessser::gen::sync_value::t94dc6b599eeaaffec96b6d6b251ed196 id_872 { fun871(dsum1_snd_64) };
                                              ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_873;
                                              {
                                                auto dsum2_fst_66 { std::get<0>(id_872) };
                                                auto dsum2_snd_67 { std::get<1>(id_872) };
                                                ::dessser::gen::sync_value::t* id_874 { new ::dessser::gen::sync_value::t(std::in_place_index<19>, dsum2_fst_66) };
                                                ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_875 { id_874, dsum2_snd_67 };
                                                letpair_res_873 = id_875;
                                              }
                                              choose_res_862 = letpair_res_873;
                                            }
                                            choose_res_854 = choose_res_862;
                                          }
                                          choose_res_846 = choose_res_854;
                                        }
                                        choose_res_838 = choose_res_846;
                                      }
                                      choose_res_830 = choose_res_838;
                                    }
                                    choose_res_822 = choose_res_830;
                                  }
                                  choose_res_814 = choose_res_822;
                                }
                                choose_res_806 = choose_res_814;
                              }
                              choose_res_798 = choose_res_806;
                            }
                            choose_res_790 = choose_res_798;
                          }
                          choose_res_782 = choose_res_790;
                        }
                        choose_res_774 = choose_res_782;
                      }
                      choose_res_766 = choose_res_774;
                    }
                    choose_res_758 = choose_res_766;
                  }
                  choose_res_633 = choose_res_758;
                }
                choose_res_625 = choose_res_633;
              }
              choose_res_617 = choose_res_625;
            }
            choose_res_609 = choose_res_617;
          }
          choose_res_546 = choose_res_609;
        }
        letpair_res_543 = choose_res_546;
      }
      let_res_542 = letpair_res_543;
    }
    ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 letpair_res_876;
    {
      auto make_fst_194 { std::get<0>(let_res_542) };
      auto make_snd_195 { std::get<1>(let_res_542) };
      ::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657 id_877 { make_fst_194, make_snd_195 };
      letpair_res_876 = id_877;
    }
    return letpair_res_876;
  }
   };
  return fun538;
}
std::function<::dessser::gen::sync_value::t5a4f9375f61f65c3413a01c7d782b657(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
