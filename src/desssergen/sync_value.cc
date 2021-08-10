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
struct v_07ada2d1213092d3daac69767fb06478 : public std::tuple<
  double,
  uint32_t,
  std::string
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, v_07ada2d1213092d3daac69767fb06478 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t)
     << '>';
  return os;
}

struct c1f1a0a3126e49b1726165cc5452d8cb {
  uint32_t skipped;
  Bytes values;
  bool operator==(c1f1a0a3126e49b1726165cc5452d8cb const &other) const {
    return skipped == other.skipped && values == other.values;
  }
};
std::ostream &operator<<(std::ostream &os, c1f1a0a3126e49b1726165cc5452d8cb const &r) {
  os << '{';
  os << "skipped:" << r.skipped << ',';
  os << "values:" << r.values;
  os << '}';
  return os;
}

struct t : public std::variant<
  v_07ada2d1213092d3daac69767fb06478,
  *worker,
  *retention,
  *time_range,
  Arr<c1f1a0a3126e49b1726165cc5452d8cb>,
  *raql_value,
  *target_config,
  *source_info,
  *runtime_stats,
  *replay,
  *replayer,
  *replay_request,
  *alert,
  *output_specs,
  *dashboard_widget,
  *alerting_contact,
  *alerting_notification,
  *alerting_delivery_status,
  *alerting_log,
  *alerting_inhibition
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
    case 8: os << std::get<8>(v); break;
    case 9: os << std::get<9>(v); break;
    case 10: os << std::get<10>(v); break;
    case 11: os << std::get<11>(v); break;
    case 12: os << std::get<12>(v); break;
    case 13: os << std::get<13>(v); break;
    case 14: os << std::get<14>(v); break;
    case 15: os << std::get<15>(v); break;
    case 16: os << std::get<16>(v); break;
    case 17: os << std::get<17>(v); break;
    case 18: os << std::get<18>(v); break;
    case 19: os << std::get<19>(v); break;
  }
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

typedef std::tuple<
  uint16_t,
  Pointer
> v_362f9d9108a6902af48b6c83d5377ea1;

typedef std::tuple<
  uint64_t,
  Pointer
> b62e103e7915a76f45f02f7c6f667c79;

typedef std::tuple<
  double,
  Pointer
> v_41a5a8cf414de9bfdc6375241fcc910a;

typedef std::tuple<
  uint32_t,
  Pointer
> ac0fbd05039f742d2f1d9ac182e392ab;

typedef std::tuple<
  Size,
  Pointer
> v_41b0681ed7f1f185fd3e6c4dcdc13110;

typedef std::tuple<
  uint8_t,
  Pointer
> v_1d5843897434feb24d158f3793db9189;

typedef std::tuple<
  Bytes,
  Pointer
> f921d1e0a170c3c04148c21704db9c45;

typedef std::tuple<
  *worker,
  Pointer
> f7624fbd7a09599953e1295791529a77;

typedef std::tuple<
  *retention,
  Pointer
> v_371090eb4646cc70f1029ba30f9305da;

typedef std::tuple<
  *time_range,
  Pointer
> v_4b60a4a70e6b1dfeee3bc23533d93277;

typedef std::tuple<
  Lst<c1f1a0a3126e49b1726165cc5452d8cb>,
  Pointer
> ca2ba47be950eca0a36de614af417907;

typedef std::tuple<
  *raql_value,
  Pointer
> ba3b596d6a5cbc29dc62e6e6a46440d5;

typedef std::tuple<
  *target_config,
  Pointer
> d9a2b3eafa7a8846e102c4c5caba99ec;

typedef std::tuple<
  *source_info,
  Pointer
> d159e6605b03eb55895de2efe6d0a8c0;

typedef std::tuple<
  *runtime_stats,
  Pointer
> c103e668680401c199cc9dd2f89f51b4;

typedef std::tuple<
  *replay,
  Pointer
> v_09f87cec186e0cb60a8fce13469f513f;

typedef std::tuple<
  *replayer,
  Pointer
> a9357042939e8b0f227486faaba4fcfb;

typedef std::tuple<
  *replay_request,
  Pointer
> cadcce10e6117fd50b402ee4d1cb38a4;

typedef std::tuple<
  *alert,
  Pointer
> feae865b6fd982b54eeb0d676df0c187;

typedef std::tuple<
  *output_specs,
  Pointer
> v_5d3df5ef82bef4373702ab960e6235b2;

typedef std::tuple<
  *dashboard_widget,
  Pointer
> v_5c6f406543b9e67fefffd08643986d36;

typedef std::tuple<
  *alerting_contact,
  Pointer
> v_132ca8e3dcf1135f5d129336ff188b57;

typedef std::tuple<
  *alerting_notification,
  Pointer
> v_85f680f1694fafb59f9004d40323f6b5;

typedef std::tuple<
  *alerting_delivery_status,
  Pointer
> v_9a0fce1a343f193cd07dec4c309db5e5;

typedef std::tuple<
  *alerting_log,
  Pointer
> v_419eac713b7b9b379f1f3222b985b0e6;

typedef std::tuple<
  *alerting_inhibition,
  Pointer
> v_79b7af3dcb201c3fb0f035e41221ecaa;

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
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun0 { [&fun0](t p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0.index()) };
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
          v_07ada2d1213092d3daac69767fb06478 id_8 { std::get<0>(p_0) };
          double id_9 { std::get<0>(id_8) };
          uint64_t id_10 { qword_of_float(id_9) };
          Pointer id_11 { ssum_dst_213.writeU64Le(id_10) };
          Pointer let_res_12;
          {
            Pointer stup_dst_223 { id_11 };
            v_07ada2d1213092d3daac69767fb06478 id_13 { std::get<0>(p_0) };
            uint32_t id_14 { std::get<1>(id_13) };
            Pointer id_15 { stup_dst_223.writeU32Le(id_14) };
            let_res_12 = id_15;
          }
          Pointer let_res_16;
          {
            Pointer stup_dst_224 { let_res_12 };
            v_07ada2d1213092d3daac69767fb06478 id_17 { std::get<0>(p_0) };
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
                  uint8_t id_43 { 0 };
                  uint8_t id_44 { 0 };
                  uint32_t id_45 { leb128_sz_225[id_44] };
                  uint8_t id_46 { 7 };
                  uint32_t id_47 { uint32_t(id_45 >> id_46) };
                  Void id_48 { ((void)(leb128_sz_225[id_43] = id_47), VOID) };
                  uint8_t id_49 { 0 };
                  uint32_t id_50 { leb128_sz_225[id_49] };
                  uint32_t id_51 { 0U };
                  bool id_52 { bool(id_50 > id_51) };
                  while_flag_24 = id_52;
                  if (while_flag_24) {
                  }
                } while (while_flag_24);
                uint8_t id_53 { 0 };
                Pointer id_54 { leb128_ptr_226[id_53] };
                let_res_23 = id_54;
              }
              let_res_21 = let_res_23;
            }
            v_07ada2d1213092d3daac69767fb06478 id_55 { std::get<0>(p_0) };
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
            std::function<Pointer(*worker,Pointer)> id_62 { dessser_gen::worker.to_row_binary };
            *worker id_63 { std::get<1>(p_0) };
            Pointer id_64 { id_62(id_63, ssum_dst_213) };
            choose_res_61 = id_64;
          } else {
            uint16_t id_65 { 2 };
            bool id_66 { bool(id_65 == label1_212) };
            Pointer choose_res_67;
            if (id_66) {
              std::function<Pointer(*retention,Pointer)> id_68 { dessser_gen::retention.to_row_binary };
              *retention id_69 { std::get<2>(p_0) };
              Pointer id_70 { id_68(id_69, ssum_dst_213) };
              choose_res_67 = id_70;
            } else {
              uint16_t id_71 { 3 };
              bool id_72 { bool(id_71 == label1_212) };
              Pointer choose_res_73;
              if (id_72) {
                std::function<Pointer(*time_range,Pointer)> id_74 { dessser_gen::time_range.to_row_binary };
                *time_range id_75 { std::get<3>(p_0) };
                Pointer id_76 { id_74(id_75, ssum_dst_213) };
                choose_res_73 = id_76;
              } else {
                uint16_t id_77 { 4 };
                bool id_78 { bool(id_77 == label1_212) };
                Pointer choose_res_79;
                if (id_78) {
                  Arr<c1f1a0a3126e49b1726165cc5452d8cb> id_80 { std::get<4>(p_0) };
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
                        uint8_t id_105 { 0 };
                        uint8_t id_106 { 0 };
                        uint32_t id_107 { leb128_sz_214[id_106] };
                        uint8_t id_108 { 7 };
                        uint32_t id_109 { uint32_t(id_107 >> id_108) };
                        Void id_110 { ((void)(leb128_sz_214[id_105] = id_109), VOID) };
                        uint8_t id_111 { 0 };
                        uint32_t id_112 { leb128_sz_214[id_111] };
                        uint32_t id_113 { 0U };
                        bool id_114 { bool(id_112 > id_113) };
                        while_flag_86 = id_114;
                        if (while_flag_86) {
                        }
                      } while (while_flag_86);
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
                      Arr<c1f1a0a3126e49b1726165cc5452d8cb> id_122 { std::get<4>(p_0) };
                      for (c1f1a0a3126e49b1726165cc5452d8cb x_218 : id_122) {
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
                                uint8_t id_156 { 0 };
                                uint8_t id_157 { 0 };
                                uint32_t id_158 { leb128_sz_221[id_157] };
                                uint8_t id_159 { 7 };
                                uint32_t id_160 { uint32_t(id_158 >> id_159) };
                                Void id_161 { ((void)(leb128_sz_221[id_156] = id_160), VOID) };
                                uint8_t id_162 { 0 };
                                uint32_t id_163 { leb128_sz_221[id_162] };
                                uint32_t id_164 { 0U };
                                bool id_165 { bool(id_163 > id_164) };
                                while_flag_137 = id_165;
                                if (while_flag_137) {
                                }
                              } while (while_flag_137);
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
                        uint8_t id_171 { 0 };
                        int32_t id_172 { 1L };
                        uint8_t id_173 { 0 };
                        int32_t id_174 { n_ref_217[id_173] };
                        int32_t id_175 { int32_t(id_172 + id_174) };
                        Void id_176 { ((void)(n_ref_217[id_171] = id_175), VOID) };
                      }
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
                    std::function<Pointer(*raql_value,Pointer)> id_182 { dessser_gen::raql_value.to_row_binary };
                    *raql_value id_183 { std::get<5>(p_0) };
                    Pointer id_184 { id_182(id_183, ssum_dst_213) };
                    choose_res_181 = id_184;
                  } else {
                    uint16_t id_185 { 6 };
                    bool id_186 { bool(id_185 == label1_212) };
                    Pointer choose_res_187;
                    if (id_186) {
                      std::function<Pointer(*target_config,Pointer)> id_188 { dessser_gen::target_config.to_row_binary };
                      *target_config id_189 { std::get<6>(p_0) };
                      Pointer id_190 { id_188(id_189, ssum_dst_213) };
                      choose_res_187 = id_190;
                    } else {
                      uint16_t id_191 { 7 };
                      bool id_192 { bool(id_191 == label1_212) };
                      Pointer choose_res_193;
                      if (id_192) {
                        std::function<Pointer(*source_info,Pointer)> id_194 { dessser_gen::source_info.to_row_binary };
                        *source_info id_195 { std::get<7>(p_0) };
                        Pointer id_196 { id_194(id_195, ssum_dst_213) };
                        choose_res_193 = id_196;
                      } else {
                        uint16_t id_197 { 8 };
                        bool id_198 { bool(id_197 == label1_212) };
                        Pointer choose_res_199;
                        if (id_198) {
                          std::function<Pointer(*runtime_stats,Pointer)> id_200 { dessser_gen::runtime_stats.to_row_binary };
                          *runtime_stats id_201 { std::get<8>(p_0) };
                          Pointer id_202 { id_200(id_201, ssum_dst_213) };
                          choose_res_199 = id_202;
                        } else {
                          uint16_t id_203 { 9 };
                          bool id_204 { bool(id_203 == label1_212) };
                          Pointer choose_res_205;
                          if (id_204) {
                            std::function<Pointer(*replay,Pointer)> id_206 { dessser_gen::replay.to_row_binary };
                            *replay id_207 { std::get<9>(p_0) };
                            Pointer id_208 { id_206(id_207, ssum_dst_213) };
                            choose_res_205 = id_208;
                          } else {
                            uint16_t id_209 { 10 };
                            bool id_210 { bool(id_209 == label1_212) };
                            Pointer choose_res_211;
                            if (id_210) {
                              std::function<Pointer(*replayer,Pointer)> id_212 { dessser_gen::replayer.to_row_binary };
                              *replayer id_213 { std::get<10>(p_0) };
                              Pointer id_214 { id_212(id_213, ssum_dst_213) };
                              choose_res_211 = id_214;
                            } else {
                              uint16_t id_215 { 11 };
                              bool id_216 { bool(id_215 == label1_212) };
                              Pointer choose_res_217;
                              if (id_216) {
                                std::function<Pointer(*replay_request,Pointer)> id_218 { dessser_gen::replay_request.to_row_binary };
                                *replay_request id_219 { std::get<11>(p_0) };
                                Pointer id_220 { id_218(id_219, ssum_dst_213) };
                                choose_res_217 = id_220;
                              } else {
                                uint16_t id_221 { 12 };
                                bool id_222 { bool(id_221 == label1_212) };
                                Pointer choose_res_223;
                                if (id_222) {
                                  std::function<Pointer(*alert,Pointer)> id_224 { dessser_gen::alert.to_row_binary };
                                  *alert id_225 { std::get<12>(p_0) };
                                  Pointer id_226 { id_224(id_225, ssum_dst_213) };
                                  choose_res_223 = id_226;
                                } else {
                                  uint16_t id_227 { 13 };
                                  bool id_228 { bool(id_227 == label1_212) };
                                  Pointer choose_res_229;
                                  if (id_228) {
                                    std::function<Pointer(*output_specs,Pointer)> id_230 { dessser_gen::output_specs.to_row_binary };
                                    *output_specs id_231 { std::get<13>(p_0) };
                                    Pointer id_232 { id_230(id_231, ssum_dst_213) };
                                    choose_res_229 = id_232;
                                  } else {
                                    uint16_t id_233 { 14 };
                                    bool id_234 { bool(id_233 == label1_212) };
                                    Pointer choose_res_235;
                                    if (id_234) {
                                      std::function<Pointer(*dashboard_widget,Pointer)> id_236 { dessser_gen::dashboard_widget.to_row_binary };
                                      *dashboard_widget id_237 { std::get<14>(p_0) };
                                      Pointer id_238 { id_236(id_237, ssum_dst_213) };
                                      choose_res_235 = id_238;
                                    } else {
                                      uint16_t id_239 { 15 };
                                      bool id_240 { bool(id_239 == label1_212) };
                                      Pointer choose_res_241;
                                      if (id_240) {
                                        std::function<Pointer(*alerting_contact,Pointer)> id_242 { dessser_gen::alerting_contact.to_row_binary };
                                        *alerting_contact id_243 { std::get<15>(p_0) };
                                        Pointer id_244 { id_242(id_243, ssum_dst_213) };
                                        choose_res_241 = id_244;
                                      } else {
                                        uint16_t id_245 { 16 };
                                        bool id_246 { bool(id_245 == label1_212) };
                                        Pointer choose_res_247;
                                        if (id_246) {
                                          std::function<Pointer(*alerting_notification,Pointer)> id_248 { dessser_gen::alerting_notification.to_row_binary };
                                          *alerting_notification id_249 { std::get<16>(p_0) };
                                          Pointer id_250 { id_248(id_249, ssum_dst_213) };
                                          choose_res_247 = id_250;
                                        } else {
                                          uint16_t id_251 { 17 };
                                          bool id_252 { bool(id_251 == label1_212) };
                                          Pointer choose_res_253;
                                          if (id_252) {
                                            std::function<Pointer(*alerting_delivery_status,Pointer)> id_254 { dessser_gen::alerting_delivery_status.to_row_binary };
                                            *alerting_delivery_status id_255 { std::get<17>(p_0) };
                                            Pointer id_256 { id_254(id_255, ssum_dst_213) };
                                            choose_res_253 = id_256;
                                          } else {
                                            uint16_t id_257 { 18 };
                                            bool id_258 { bool(id_257 == label1_212) };
                                            Pointer choose_res_259;
                                            if (id_258) {
                                              std::function<Pointer(*alerting_log,Pointer)> id_260 { dessser_gen::alerting_log.to_row_binary };
                                              *alerting_log id_261 { std::get<18>(p_0) };
                                              Pointer id_262 { id_260(id_261, ssum_dst_213) };
                                              choose_res_259 = id_262;
                                            } else {
                                              uint16_t id_263 { 19 };
                                              bool id_264 { bool(label1_212 == id_263) };
                                              Void id_265 { ((void)(assert(id_264)), VOID) };
                                              std::function<Pointer(*alerting_inhibition,Pointer)> id_266 { dessser_gen::alerting_inhibition.to_row_binary };
                                              *alerting_inhibition id_267 { std::get<19>(p_0) };
                                              Pointer id_268 { id_266(id_267, ssum_dst_213) };
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
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());

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
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun269 { [&fun269](t p_0) {
    uint16_t id_270 { uint16_t(p_0.index()) };
    Size let_res_271;
    {
      uint16_t label2_196 { id_270 };
      uint16_t id_272 { 0 };
      bool id_273 { bool(id_272 == label2_196) };
      Size choose_res_274;
      if (id_273) {
        Size id_275 { 14UL };
        v_07ada2d1213092d3daac69767fb06478 id_276 { std::get<0>(p_0) };
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
              }
            } while (while_flag_284);
            uint8_t id_298 { 0 };
            uint32_t id_299 { lebsz_ref_211[id_298] };
            Size id_300 { Size(id_299) };
            let_res_283 = id_300;
          }
          let_res_280 = let_res_283;
        }
        v_07ada2d1213092d3daac69767fb06478 id_301 { std::get<0>(p_0) };
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
          std::function<Size(*worker)> id_311 { dessser_gen::worker.sersize_of_row_binary };
          *worker id_312 { std::get<1>(p_0) };
          Size id_313 { id_311(id_312) };
          Size id_314 { Size(id_310 + id_313) };
          choose_res_309 = id_314;
        } else {
          uint16_t id_315 { 2 };
          bool id_316 { bool(id_315 == label2_196) };
          Size choose_res_317;
          if (id_316) {
            Size id_318 { 2UL };
            std::function<Size(*retention)> id_319 { dessser_gen::retention.sersize_of_row_binary };
            *retention id_320 { std::get<2>(p_0) };
            Size id_321 { id_319(id_320) };
            Size id_322 { Size(id_318 + id_321) };
            choose_res_317 = id_322;
          } else {
            uint16_t id_323 { 3 };
            bool id_324 { bool(id_323 == label2_196) };
            Size choose_res_325;
            if (id_324) {
              Size id_326 { 2UL };
              std::function<Size(*time_range)> id_327 { dessser_gen::time_range.sersize_of_row_binary };
              *time_range id_328 { std::get<3>(p_0) };
              Size id_329 { id_327(id_328) };
              Size id_330 { Size(id_326 + id_329) };
              choose_res_325 = id_330;
            } else {
              uint16_t id_331 { 4 };
              bool id_332 { bool(id_331 == label2_196) };
              Size choose_res_333;
              if (id_332) {
                Size id_334 { 2UL };
                Arr<c1f1a0a3126e49b1726165cc5452d8cb> id_335 { std::get<4>(p_0) };
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
                      }
                    } while (while_flag_342);
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
                      Arr<c1f1a0a3126e49b1726165cc5452d8cb> id_365 { std::get<4>(p_0) };
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
                          Arr<c1f1a0a3126e49b1726165cc5452d8cb> id_379 { std::get<4>(p_0) };
                          c1f1a0a3126e49b1726165cc5452d8cb id_380 { id_379[id_378] };
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
                                  }
                                } while (while_flag_390);
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
                        uint8_t id_410 { 0 };
                        uint8_t id_411 { 0 };
                        int32_t id_412 { repeat_n_200[id_411] };
                        int32_t id_413 { 1L };
                        int32_t id_414 { int32_t(id_412 + id_413) };
                        Void id_415 { ((void)(repeat_n_200[id_410] = id_414), VOID) };
                      }
                    } while (while_flag_364);
                  }
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
                  std::function<Size(*raql_value)> id_422 { dessser_gen::raql_value.sersize_of_row_binary };
                  *raql_value id_423 { std::get<5>(p_0) };
                  Size id_424 { id_422(id_423) };
                  Size id_425 { Size(id_421 + id_424) };
                  choose_res_420 = id_425;
                } else {
                  uint16_t id_426 { 6 };
                  bool id_427 { bool(id_426 == label2_196) };
                  Size choose_res_428;
                  if (id_427) {
                    Size id_429 { 2UL };
                    std::function<Size(*target_config)> id_430 { dessser_gen::target_config.sersize_of_row_binary };
                    *target_config id_431 { std::get<6>(p_0) };
                    Size id_432 { id_430(id_431) };
                    Size id_433 { Size(id_429 + id_432) };
                    choose_res_428 = id_433;
                  } else {
                    uint16_t id_434 { 7 };
                    bool id_435 { bool(id_434 == label2_196) };
                    Size choose_res_436;
                    if (id_435) {
                      Size id_437 { 2UL };
                      std::function<Size(*source_info)> id_438 { dessser_gen::source_info.sersize_of_row_binary };
                      *source_info id_439 { std::get<7>(p_0) };
                      Size id_440 { id_438(id_439) };
                      Size id_441 { Size(id_437 + id_440) };
                      choose_res_436 = id_441;
                    } else {
                      uint16_t id_442 { 8 };
                      bool id_443 { bool(id_442 == label2_196) };
                      Size choose_res_444;
                      if (id_443) {
                        Size id_445 { 2UL };
                        std::function<Size(*runtime_stats)> id_446 { dessser_gen::runtime_stats.sersize_of_row_binary };
                        *runtime_stats id_447 { std::get<8>(p_0) };
                        Size id_448 { id_446(id_447) };
                        Size id_449 { Size(id_445 + id_448) };
                        choose_res_444 = id_449;
                      } else {
                        uint16_t id_450 { 9 };
                        bool id_451 { bool(id_450 == label2_196) };
                        Size choose_res_452;
                        if (id_451) {
                          Size id_453 { 2UL };
                          std::function<Size(*replay)> id_454 { dessser_gen::replay.sersize_of_row_binary };
                          *replay id_455 { std::get<9>(p_0) };
                          Size id_456 { id_454(id_455) };
                          Size id_457 { Size(id_453 + id_456) };
                          choose_res_452 = id_457;
                        } else {
                          uint16_t id_458 { 10 };
                          bool id_459 { bool(id_458 == label2_196) };
                          Size choose_res_460;
                          if (id_459) {
                            Size id_461 { 2UL };
                            std::function<Size(*replayer)> id_462 { dessser_gen::replayer.sersize_of_row_binary };
                            *replayer id_463 { std::get<10>(p_0) };
                            Size id_464 { id_462(id_463) };
                            Size id_465 { Size(id_461 + id_464) };
                            choose_res_460 = id_465;
                          } else {
                            uint16_t id_466 { 11 };
                            bool id_467 { bool(id_466 == label2_196) };
                            Size choose_res_468;
                            if (id_467) {
                              Size id_469 { 2UL };
                              std::function<Size(*replay_request)> id_470 { dessser_gen::replay_request.sersize_of_row_binary };
                              *replay_request id_471 { std::get<11>(p_0) };
                              Size id_472 { id_470(id_471) };
                              Size id_473 { Size(id_469 + id_472) };
                              choose_res_468 = id_473;
                            } else {
                              uint16_t id_474 { 12 };
                              bool id_475 { bool(id_474 == label2_196) };
                              Size choose_res_476;
                              if (id_475) {
                                Size id_477 { 2UL };
                                std::function<Size(*alert)> id_478 { dessser_gen::alert.sersize_of_row_binary };
                                *alert id_479 { std::get<12>(p_0) };
                                Size id_480 { id_478(id_479) };
                                Size id_481 { Size(id_477 + id_480) };
                                choose_res_476 = id_481;
                              } else {
                                uint16_t id_482 { 13 };
                                bool id_483 { bool(id_482 == label2_196) };
                                Size choose_res_484;
                                if (id_483) {
                                  Size id_485 { 2UL };
                                  std::function<Size(*output_specs)> id_486 { dessser_gen::output_specs.sersize_of_row_binary };
                                  *output_specs id_487 { std::get<13>(p_0) };
                                  Size id_488 { id_486(id_487) };
                                  Size id_489 { Size(id_485 + id_488) };
                                  choose_res_484 = id_489;
                                } else {
                                  uint16_t id_490 { 14 };
                                  bool id_491 { bool(id_490 == label2_196) };
                                  Size choose_res_492;
                                  if (id_491) {
                                    Size id_493 { 2UL };
                                    std::function<Size(*dashboard_widget)> id_494 { dessser_gen::dashboard_widget.sersize_of_row_binary };
                                    *dashboard_widget id_495 { std::get<14>(p_0) };
                                    Size id_496 { id_494(id_495) };
                                    Size id_497 { Size(id_493 + id_496) };
                                    choose_res_492 = id_497;
                                  } else {
                                    uint16_t id_498 { 15 };
                                    bool id_499 { bool(id_498 == label2_196) };
                                    Size choose_res_500;
                                    if (id_499) {
                                      Size id_501 { 2UL };
                                      std::function<Size(*alerting_contact)> id_502 { dessser_gen::alerting_contact.sersize_of_row_binary };
                                      *alerting_contact id_503 { std::get<15>(p_0) };
                                      Size id_504 { id_502(id_503) };
                                      Size id_505 { Size(id_501 + id_504) };
                                      choose_res_500 = id_505;
                                    } else {
                                      uint16_t id_506 { 16 };
                                      bool id_507 { bool(id_506 == label2_196) };
                                      Size choose_res_508;
                                      if (id_507) {
                                        Size id_509 { 2UL };
                                        std::function<Size(*alerting_notification)> id_510 { dessser_gen::alerting_notification.sersize_of_row_binary };
                                        *alerting_notification id_511 { std::get<16>(p_0) };
                                        Size id_512 { id_510(id_511) };
                                        Size id_513 { Size(id_509 + id_512) };
                                        choose_res_508 = id_513;
                                      } else {
                                        uint16_t id_514 { 17 };
                                        bool id_515 { bool(id_514 == label2_196) };
                                        Size choose_res_516;
                                        if (id_515) {
                                          Size id_517 { 2UL };
                                          std::function<Size(*alerting_delivery_status)> id_518 { dessser_gen::alerting_delivery_status.sersize_of_row_binary };
                                          *alerting_delivery_status id_519 { std::get<17>(p_0) };
                                          Size id_520 { id_518(id_519) };
                                          Size id_521 { Size(id_517 + id_520) };
                                          choose_res_516 = id_521;
                                        } else {
                                          uint16_t id_522 { 18 };
                                          bool id_523 { bool(id_522 == label2_196) };
                                          Size choose_res_524;
                                          if (id_523) {
                                            Size id_525 { 2UL };
                                            std::function<Size(*alerting_log)> id_526 { dessser_gen::alerting_log.sersize_of_row_binary };
                                            *alerting_log id_527 { std::get<18>(p_0) };
                                            Size id_528 { id_526(id_527) };
                                            Size id_529 { Size(id_525 + id_528) };
                                            choose_res_524 = id_529;
                                          } else {
                                            uint16_t id_530 { 19 };
                                            bool id_531 { bool(label2_196 == id_530) };
                                            Void id_532 { ((void)(assert(id_531)), VOID) };
                                            Size id_533 { 2UL };
                                            std::function<Size(*alerting_inhibition)> id_534 { dessser_gen::alerting_inhibition.sersize_of_row_binary };
                                            *alerting_inhibition id_535 { std::get<19>(p_0) };
                                            Size id_536 { id_534(id_535) };
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
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

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
                                                  (make-tup (cons (make-rec (string "skipped") (identifier "drec_fst_131") (string "values") (identifier "drec_fst_143")) (identifier "dlist2_fst_125")) (identifier "drec_snd_144"))))))))
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
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun538 { [&fun538](Pointer p_0) {
    v_362f9d9108a6902af48b6c83d5377ea1 id_539 { p_0.readU16Le() };
    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_540;
    {
      auto du16_fst_57 { std::get<0>(id_539) };
      auto du16_snd_58 { std::get<1>(id_539) };
      v_362f9d9108a6902af48b6c83d5377ea1 id_541 {  du16_fst_57, du16_snd_58  };
      letpair_res_540 = id_541;
    }
    f63f919559f0d70225bd0da5dd9bcafc let_res_542;
    {
      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_62 { letpair_res_540 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_543;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_544 { 0 };
        bool id_545 { bool(id_544 == dsum1_fst_63) };
        f63f919559f0d70225bd0da5dd9bcafc choose_res_546;
        if (id_545) {
          b62e103e7915a76f45f02f7c6f667c79 id_547 { dsum1_snd_64.readU64Le() };
          v_41a5a8cf414de9bfdc6375241fcc910a letpair_res_548;
          {
            auto dfloat_fst_164 { std::get<0>(id_547) };
            auto dfloat_snd_165 { std::get<1>(id_547) };
            double id_549 { float_of_qword(dfloat_fst_164) };
            v_41a5a8cf414de9bfdc6375241fcc910a id_550 {  id_549, dfloat_snd_165  };
            letpair_res_548 = id_550;
          }
          f63f919559f0d70225bd0da5dd9bcafc let_res_551;
          {
            v_41a5a8cf414de9bfdc6375241fcc910a dtup_166 { letpair_res_548 };
            f63f919559f0d70225bd0da5dd9bcafc letpair_res_552;
            {
              auto dtup_fst_167 { std::get<0>(dtup_166) };
              auto dtup_snd_168 { std::get<1>(dtup_166) };
              ac0fbd05039f742d2f1d9ac182e392ab id_553 { dtup_snd_168.readU32Le() };
              ac0fbd05039f742d2f1d9ac182e392ab letpair_res_554;
              {
                auto du32_fst_170 { std::get<0>(id_553) };
                auto du32_snd_171 { std::get<1>(id_553) };
                ac0fbd05039f742d2f1d9ac182e392ab id_555 {  du32_fst_170, du32_snd_171  };
                letpair_res_554 = id_555;
              }
              f63f919559f0d70225bd0da5dd9bcafc let_res_556;
              {
                ac0fbd05039f742d2f1d9ac182e392ab dtup_172 { letpair_res_554 };
                f63f919559f0d70225bd0da5dd9bcafc letpair_res_557;
                {
                  auto dtup_fst_173 { std::get<0>(dtup_172) };
                  auto dtup_snd_174 { std::get<1>(dtup_172) };
                  uint32_t id_558 { 0U };
                  Vec<1, uint32_t> id_559 {  id_558  };
                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_560;
                  {
                    Vec<1, uint32_t> leb_ref_175 { id_559 };
                    uint8_t id_561 { 0 };
                    Vec<1, uint8_t> id_562 {  id_561  };
                    v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_563;
                    {
                      Vec<1, uint8_t> shft_ref_176 { id_562 };
                      Vec<1, Pointer> id_564 {  dtup_snd_174  };
                      v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_565;
                      {
                        Vec<1, Pointer> p_ref_177 { id_564 };
                        bool while_flag_566 { true };
                        do {
                          uint8_t id_567 { 0 };
                          Pointer id_568 { p_ref_177[id_567] };
                          v_1d5843897434feb24d158f3793db9189 id_569 { id_568.readU8() };
                          bool let_res_570;
                          {
                            v_1d5843897434feb24d158f3793db9189 leb128_178 { id_569 };
                            bool letpair_res_571;
                            {
                              auto leb128_fst_179 { std::get<0>(leb128_178) };
                              auto leb128_snd_180 { std::get<1>(leb128_178) };
                              uint8_t id_572 { 0 };
                              Void id_573 { ((void)(p_ref_177[id_572] = leb128_snd_180), VOID) };
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
                              uint8_t id_585 { 0 };
                              uint8_t id_586 { 0 };
                              uint8_t id_587 { shft_ref_176[id_586] };
                              uint8_t id_588 { 7 };
                              uint8_t id_589 { uint8_t(id_587 + id_588) };
                              Void id_590 { ((void)(shft_ref_176[id_585] = id_589), VOID) };
                              uint8_t id_591 { 128 };
                              bool id_592 { bool(leb128_fst_179 >= id_591) };
                              letpair_res_571 = id_592;
                            }
                            let_res_570 = letpair_res_571;
                          }
                          while_flag_566 = let_res_570;
                          if (while_flag_566) {
                          }
                        } while (while_flag_566);
                        uint8_t id_593 { 0 };
                        uint32_t id_594 { leb_ref_175[id_593] };
                        Size id_595 { Size(id_594) };
                        uint8_t id_596 { 0 };
                        Pointer id_597 { p_ref_177[id_596] };
                        v_41b0681ed7f1f185fd3e6c4dcdc13110 id_598 {  id_595, id_597  };
                        let_res_565 = id_598;
                      }
                      let_res_563 = let_res_565;
                    }
                    let_res_560 = let_res_563;
                  }
                  f63f919559f0d70225bd0da5dd9bcafc let_res_599;
                  {
                    v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_181 { let_res_560 };
                    f63f919559f0d70225bd0da5dd9bcafc letpair_res_600;
                    {
                      auto dstring1_fst_182 { std::get<0>(dstring1_181) };
                      auto dstring1_snd_183 { std::get<1>(dstring1_181) };
                      f921d1e0a170c3c04148c21704db9c45 id_601 { dstring1_snd_183.readBytes(dstring1_fst_182) };
                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_602;
                      {
                        auto dstring2_fst_185 { std::get<0>(id_601) };
                        auto dstring2_snd_186 { std::get<1>(id_601) };
                        std::string id_603 { dstring2_fst_185.toString() };
                        v_07ada2d1213092d3daac69767fb06478 id_604 {  dtup_fst_167, dtup_fst_173, id_603  };
                        t id_605 { std::in_place_index<0>, id_604 };
                        f63f919559f0d70225bd0da5dd9bcafc id_606 {  id_605, dstring2_snd_186  };
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
          f63f919559f0d70225bd0da5dd9bcafc choose_res_609;
          if (id_608) {
            std::function<f7624fbd7a09599953e1295791529a77(Pointer)> id_610 { dessser_gen::worker.of_row_binary };
            f7624fbd7a09599953e1295791529a77 id_611 { id_610(dsum1_snd_64) };
            f63f919559f0d70225bd0da5dd9bcafc letpair_res_612;
            {
              auto dsum2_fst_161 { std::get<0>(id_611) };
              auto dsum2_snd_162 { std::get<1>(id_611) };
              t id_613 { std::in_place_index<1>, dsum2_fst_161 };
              f63f919559f0d70225bd0da5dd9bcafc id_614 {  id_613, dsum2_snd_162  };
              letpair_res_612 = id_614;
            }
            choose_res_609 = letpair_res_612;
          } else {
            uint16_t id_615 { 2 };
            bool id_616 { bool(id_615 == dsum1_fst_63) };
            f63f919559f0d70225bd0da5dd9bcafc choose_res_617;
            if (id_616) {
              std::function<v_371090eb4646cc70f1029ba30f9305da(Pointer)> id_618 { dessser_gen::retention.of_row_binary };
              v_371090eb4646cc70f1029ba30f9305da id_619 { id_618(dsum1_snd_64) };
              f63f919559f0d70225bd0da5dd9bcafc letpair_res_620;
              {
                auto dsum2_fst_158 { std::get<0>(id_619) };
                auto dsum2_snd_159 { std::get<1>(id_619) };
                t id_621 { std::in_place_index<2>, dsum2_fst_158 };
                f63f919559f0d70225bd0da5dd9bcafc id_622 {  id_621, dsum2_snd_159  };
                letpair_res_620 = id_622;
              }
              choose_res_617 = letpair_res_620;
            } else {
              uint16_t id_623 { 3 };
              bool id_624 { bool(id_623 == dsum1_fst_63) };
              f63f919559f0d70225bd0da5dd9bcafc choose_res_625;
              if (id_624) {
                std::function<v_4b60a4a70e6b1dfeee3bc23533d93277(Pointer)> id_626 { dessser_gen::time_range.of_row_binary };
                v_4b60a4a70e6b1dfeee3bc23533d93277 id_627 { id_626(dsum1_snd_64) };
                f63f919559f0d70225bd0da5dd9bcafc letpair_res_628;
                {
                  auto dsum2_fst_155 { std::get<0>(id_627) };
                  auto dsum2_snd_156 { std::get<1>(id_627) };
                  t id_629 { std::in_place_index<3>, dsum2_fst_155 };
                  f63f919559f0d70225bd0da5dd9bcafc id_630 {  id_629, dsum2_snd_156  };
                  letpair_res_628 = id_630;
                }
                choose_res_625 = letpair_res_628;
              } else {
                uint16_t id_631 { 4 };
                bool id_632 { bool(id_631 == dsum1_fst_63) };
                f63f919559f0d70225bd0da5dd9bcafc choose_res_633;
                if (id_632) {
                  uint32_t id_634 { 0U };
                  Vec<1, uint32_t> id_635 {  id_634  };
                  ac0fbd05039f742d2f1d9ac182e392ab let_res_636;
                  {
                    Vec<1, uint32_t> leb_ref_110 { id_635 };
                    uint8_t id_637 { 0 };
                    Vec<1, uint8_t> id_638 {  id_637  };
                    ac0fbd05039f742d2f1d9ac182e392ab let_res_639;
                    {
                      Vec<1, uint8_t> shft_ref_111 { id_638 };
                      Vec<1, Pointer> id_640 {  dsum1_snd_64  };
                      ac0fbd05039f742d2f1d9ac182e392ab let_res_641;
                      {
                        Vec<1, Pointer> p_ref_112 { id_640 };
                        bool while_flag_642 { true };
                        do {
                          uint8_t id_643 { 0 };
                          Pointer id_644 { p_ref_112[id_643] };
                          v_1d5843897434feb24d158f3793db9189 id_645 { id_644.readU8() };
                          bool let_res_646;
                          {
                            v_1d5843897434feb24d158f3793db9189 leb128_113 { id_645 };
                            bool letpair_res_647;
                            {
                              auto leb128_fst_114 { std::get<0>(leb128_113) };
                              auto leb128_snd_115 { std::get<1>(leb128_113) };
                              uint8_t id_648 { 0 };
                              Void id_649 { ((void)(p_ref_112[id_648] = leb128_snd_115), VOID) };
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
                              uint8_t id_661 { 0 };
                              uint8_t id_662 { 0 };
                              uint8_t id_663 { shft_ref_111[id_662] };
                              uint8_t id_664 { 7 };
                              uint8_t id_665 { uint8_t(id_663 + id_664) };
                              Void id_666 { ((void)(shft_ref_111[id_661] = id_665), VOID) };
                              uint8_t id_667 { 128 };
                              bool id_668 { bool(leb128_fst_114 >= id_667) };
                              letpair_res_647 = id_668;
                            }
                            let_res_646 = letpair_res_647;
                          }
                          while_flag_642 = let_res_646;
                          if (while_flag_642) {
                          }
                        } while (while_flag_642);
                        uint8_t id_669 { 0 };
                        uint32_t id_670 { leb_ref_110[id_669] };
                        uint8_t id_671 { 0 };
                        Pointer id_672 { p_ref_112[id_671] };
                        ac0fbd05039f742d2f1d9ac182e392ab id_673 {  id_670, id_672  };
                        let_res_641 = id_673;
                      }
                      let_res_639 = let_res_641;
                    }
                    let_res_636 = let_res_639;
                  }
                  ca2ba47be950eca0a36de614af417907 let_res_674;
                  {
                    ac0fbd05039f742d2f1d9ac182e392ab dlist1_119 { let_res_636 };
                    ca2ba47be950eca0a36de614af417907 letpair_res_675;
                    {
                      auto dlist1_fst_120 { std::get<0>(dlist1_119) };
                      auto dlist1_snd_121 { std::get<1>(dlist1_119) };
                      Lst<c1f1a0a3126e49b1726165cc5452d8cb> endoflist_676;
                      ca2ba47be950eca0a36de614af417907 id_677 {  endoflist_676, dlist1_snd_121  };
                      Vec<1, ca2ba47be950eca0a36de614af417907> id_678 {  id_677  };
                      ca2ba47be950eca0a36de614af417907 let_res_679;
                      {
                        Vec<1, ca2ba47be950eca0a36de614af417907> inits_src_ref_122 { id_678 };
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
                              ca2ba47be950eca0a36de614af417907 id_688 { inits_src_ref_122[id_687] };
                              {
                                ca2ba47be950eca0a36de614af417907 dlist2_124 { id_688 };
                                {
                                  auto dlist2_fst_125 { std::get<0>(dlist2_124) };
                                  auto dlist2_snd_126 { std::get<1>(dlist2_124) };
                                  uint8_t id_689 { 0 };
                                  ac0fbd05039f742d2f1d9ac182e392ab id_690 { dlist2_snd_126.readU32Le() };
                                  ac0fbd05039f742d2f1d9ac182e392ab letpair_res_691;
                                  {
                                    auto du32_fst_128 { std::get<0>(id_690) };
                                    auto du32_snd_129 { std::get<1>(id_690) };
                                    ac0fbd05039f742d2f1d9ac182e392ab id_692 {  du32_fst_128, du32_snd_129  };
                                    letpair_res_691 = id_692;
                                  }
                                  ca2ba47be950eca0a36de614af417907 let_res_693;
                                  {
                                    ac0fbd05039f742d2f1d9ac182e392ab drec_130 { letpair_res_691 };
                                    ca2ba47be950eca0a36de614af417907 letpair_res_694;
                                    {
                                      auto drec_fst_131 { std::get<0>(drec_130) };
                                      auto drec_snd_132 { std::get<1>(drec_130) };
                                      uint32_t id_695 { 0U };
                                      Vec<1, uint32_t> id_696 {  id_695  };
                                      v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_697;
                                      {
                                        Vec<1, uint32_t> leb_ref_133 { id_696 };
                                        uint8_t id_698 { 0 };
                                        Vec<1, uint8_t> id_699 {  id_698  };
                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_700;
                                        {
                                          Vec<1, uint8_t> shft_ref_134 { id_699 };
                                          Vec<1, Pointer> id_701 {  drec_snd_132  };
                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_702;
                                          {
                                            Vec<1, Pointer> p_ref_135 { id_701 };
                                            bool while_flag_703 { true };
                                            do {
                                              uint8_t id_704 { 0 };
                                              Pointer id_705 { p_ref_135[id_704] };
                                              v_1d5843897434feb24d158f3793db9189 id_706 { id_705.readU8() };
                                              bool let_res_707;
                                              {
                                                v_1d5843897434feb24d158f3793db9189 leb128_136 { id_706 };
                                                bool letpair_res_708;
                                                {
                                                  auto leb128_fst_137 { std::get<0>(leb128_136) };
                                                  auto leb128_snd_138 { std::get<1>(leb128_136) };
                                                  uint8_t id_709 { 0 };
                                                  Void id_710 { ((void)(p_ref_135[id_709] = leb128_snd_138), VOID) };
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
                                                  uint8_t id_722 { 0 };
                                                  uint8_t id_723 { 0 };
                                                  uint8_t id_724 { shft_ref_134[id_723] };
                                                  uint8_t id_725 { 7 };
                                                  uint8_t id_726 { uint8_t(id_724 + id_725) };
                                                  Void id_727 { ((void)(shft_ref_134[id_722] = id_726), VOID) };
                                                  uint8_t id_728 { 128 };
                                                  bool id_729 { bool(leb128_fst_137 >= id_728) };
                                                  letpair_res_708 = id_729;
                                                }
                                                let_res_707 = letpair_res_708;
                                              }
                                              while_flag_703 = let_res_707;
                                              if (while_flag_703) {
                                              }
                                            } while (while_flag_703);
                                            uint8_t id_730 { 0 };
                                            uint32_t id_731 { leb_ref_133[id_730] };
                                            Size id_732 { Size(id_731) };
                                            uint8_t id_733 { 0 };
                                            Pointer id_734 { p_ref_135[id_733] };
                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 id_735 {  id_732, id_734  };
                                            let_res_702 = id_735;
                                          }
                                          let_res_700 = let_res_702;
                                        }
                                        let_res_697 = let_res_700;
                                      }
                                      f921d1e0a170c3c04148c21704db9c45 let_res_736;
                                      {
                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 dbytes1_139 { let_res_697 };
                                        f921d1e0a170c3c04148c21704db9c45 letpair_res_737;
                                        {
                                          auto dbytes1_fst_140 { std::get<0>(dbytes1_139) };
                                          auto dbytes1_snd_141 { std::get<1>(dbytes1_139) };
                                          f921d1e0a170c3c04148c21704db9c45 id_738 { dbytes1_snd_141.readBytes(dbytes1_fst_140) };
                                          letpair_res_737 = id_738;
                                        }
                                        let_res_736 = letpair_res_737;
                                      }
                                      ca2ba47be950eca0a36de614af417907 letpair_res_739;
                                      {
                                        auto drec_fst_143 { std::get<0>(let_res_736) };
                                        auto drec_snd_144 { std::get<1>(let_res_736) };
                                        c1f1a0a3126e49b1726165cc5452d8cb id_740 {  .skipped = drec_fst_131, .values = drec_fst_143  };
                                        Lst<c1f1a0a3126e49b1726165cc5452d8cb> id_741 { id_740, dlist2_fst_125 };
                                        ca2ba47be950eca0a36de614af417907 id_742 {  id_741, drec_snd_144  };
                                        letpair_res_739 = id_742;
                                      }
                                      letpair_res_694 = letpair_res_739;
                                    }
                                    let_res_693 = letpair_res_694;
                                  }
                                  Void id_743 { ((void)(inits_src_ref_122[id_689] = let_res_693), VOID) };
                                }
                              }
                              uint8_t id_744 { 0 };
                              uint8_t id_745 { 0 };
                              int32_t id_746 { repeat_n_123[id_745] };
                              int32_t id_747 { 1L };
                              int32_t id_748 { int32_t(id_746 + id_747) };
                              Void id_749 { ((void)(repeat_n_123[id_744] = id_748), VOID) };
                            }
                          } while (while_flag_682);
                        }
                        uint8_t id_750 { 0 };
                        ca2ba47be950eca0a36de614af417907 id_751 { inits_src_ref_122[id_750] };
                        let_res_679 = id_751;
                      }
                      letpair_res_675 = let_res_679;
                    }
                    let_res_674 = letpair_res_675;
                  }
                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_752;
                  {
                    auto dlist4_fst_149 { std::get<0>(let_res_674) };
                    auto dlist4_snd_150 { std::get<1>(let_res_674) };
                    Arr<c1f1a0a3126e49b1726165cc5452d8cb> id_753 { dlist4_fst_149.toListRev() };
                    t id_754 { std::in_place_index<4>, id_753 };
                    f63f919559f0d70225bd0da5dd9bcafc id_755 {  id_754, dlist4_snd_150  };
                    letpair_res_752 = id_755;
                  }
                  choose_res_633 = letpair_res_752;
                } else {
                  uint16_t id_756 { 5 };
                  bool id_757 { bool(id_756 == dsum1_fst_63) };
                  f63f919559f0d70225bd0da5dd9bcafc choose_res_758;
                  if (id_757) {
                    std::function<ba3b596d6a5cbc29dc62e6e6a46440d5(Pointer)> id_759 { dessser_gen::raql_value.of_row_binary };
                    ba3b596d6a5cbc29dc62e6e6a46440d5 id_760 { id_759(dsum1_snd_64) };
                    f63f919559f0d70225bd0da5dd9bcafc letpair_res_761;
                    {
                      auto dsum2_fst_108 { std::get<0>(id_760) };
                      auto dsum2_snd_109 { std::get<1>(id_760) };
                      t id_762 { std::in_place_index<5>, dsum2_fst_108 };
                      f63f919559f0d70225bd0da5dd9bcafc id_763 {  id_762, dsum2_snd_109  };
                      letpair_res_761 = id_763;
                    }
                    choose_res_758 = letpair_res_761;
                  } else {
                    uint16_t id_764 { 6 };
                    bool id_765 { bool(id_764 == dsum1_fst_63) };
                    f63f919559f0d70225bd0da5dd9bcafc choose_res_766;
                    if (id_765) {
                      std::function<d9a2b3eafa7a8846e102c4c5caba99ec(Pointer)> id_767 { dessser_gen::target_config.of_row_binary };
                      d9a2b3eafa7a8846e102c4c5caba99ec id_768 { id_767(dsum1_snd_64) };
                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_769;
                      {
                        auto dsum2_fst_105 { std::get<0>(id_768) };
                        auto dsum2_snd_106 { std::get<1>(id_768) };
                        t id_770 { std::in_place_index<6>, dsum2_fst_105 };
                        f63f919559f0d70225bd0da5dd9bcafc id_771 {  id_770, dsum2_snd_106  };
                        letpair_res_769 = id_771;
                      }
                      choose_res_766 = letpair_res_769;
                    } else {
                      uint16_t id_772 { 7 };
                      bool id_773 { bool(id_772 == dsum1_fst_63) };
                      f63f919559f0d70225bd0da5dd9bcafc choose_res_774;
                      if (id_773) {
                        std::function<d159e6605b03eb55895de2efe6d0a8c0(Pointer)> id_775 { dessser_gen::source_info.of_row_binary };
                        d159e6605b03eb55895de2efe6d0a8c0 id_776 { id_775(dsum1_snd_64) };
                        f63f919559f0d70225bd0da5dd9bcafc letpair_res_777;
                        {
                          auto dsum2_fst_102 { std::get<0>(id_776) };
                          auto dsum2_snd_103 { std::get<1>(id_776) };
                          t id_778 { std::in_place_index<7>, dsum2_fst_102 };
                          f63f919559f0d70225bd0da5dd9bcafc id_779 {  id_778, dsum2_snd_103  };
                          letpair_res_777 = id_779;
                        }
                        choose_res_774 = letpair_res_777;
                      } else {
                        uint16_t id_780 { 8 };
                        bool id_781 { bool(id_780 == dsum1_fst_63) };
                        f63f919559f0d70225bd0da5dd9bcafc choose_res_782;
                        if (id_781) {
                          std::function<c103e668680401c199cc9dd2f89f51b4(Pointer)> id_783 { dessser_gen::runtime_stats.of_row_binary };
                          c103e668680401c199cc9dd2f89f51b4 id_784 { id_783(dsum1_snd_64) };
                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_785;
                          {
                            auto dsum2_fst_99 { std::get<0>(id_784) };
                            auto dsum2_snd_100 { std::get<1>(id_784) };
                            t id_786 { std::in_place_index<8>, dsum2_fst_99 };
                            f63f919559f0d70225bd0da5dd9bcafc id_787 {  id_786, dsum2_snd_100  };
                            letpair_res_785 = id_787;
                          }
                          choose_res_782 = letpair_res_785;
                        } else {
                          uint16_t id_788 { 9 };
                          bool id_789 { bool(id_788 == dsum1_fst_63) };
                          f63f919559f0d70225bd0da5dd9bcafc choose_res_790;
                          if (id_789) {
                            std::function<v_09f87cec186e0cb60a8fce13469f513f(Pointer)> id_791 { dessser_gen::replay.of_row_binary };
                            v_09f87cec186e0cb60a8fce13469f513f id_792 { id_791(dsum1_snd_64) };
                            f63f919559f0d70225bd0da5dd9bcafc letpair_res_793;
                            {
                              auto dsum2_fst_96 { std::get<0>(id_792) };
                              auto dsum2_snd_97 { std::get<1>(id_792) };
                              t id_794 { std::in_place_index<9>, dsum2_fst_96 };
                              f63f919559f0d70225bd0da5dd9bcafc id_795 {  id_794, dsum2_snd_97  };
                              letpair_res_793 = id_795;
                            }
                            choose_res_790 = letpair_res_793;
                          } else {
                            uint16_t id_796 { 10 };
                            bool id_797 { bool(id_796 == dsum1_fst_63) };
                            f63f919559f0d70225bd0da5dd9bcafc choose_res_798;
                            if (id_797) {
                              std::function<a9357042939e8b0f227486faaba4fcfb(Pointer)> id_799 { dessser_gen::replayer.of_row_binary };
                              a9357042939e8b0f227486faaba4fcfb id_800 { id_799(dsum1_snd_64) };
                              f63f919559f0d70225bd0da5dd9bcafc letpair_res_801;
                              {
                                auto dsum2_fst_93 { std::get<0>(id_800) };
                                auto dsum2_snd_94 { std::get<1>(id_800) };
                                t id_802 { std::in_place_index<10>, dsum2_fst_93 };
                                f63f919559f0d70225bd0da5dd9bcafc id_803 {  id_802, dsum2_snd_94  };
                                letpair_res_801 = id_803;
                              }
                              choose_res_798 = letpair_res_801;
                            } else {
                              uint16_t id_804 { 11 };
                              bool id_805 { bool(id_804 == dsum1_fst_63) };
                              f63f919559f0d70225bd0da5dd9bcafc choose_res_806;
                              if (id_805) {
                                std::function<cadcce10e6117fd50b402ee4d1cb38a4(Pointer)> id_807 { dessser_gen::replay_request.of_row_binary };
                                cadcce10e6117fd50b402ee4d1cb38a4 id_808 { id_807(dsum1_snd_64) };
                                f63f919559f0d70225bd0da5dd9bcafc letpair_res_809;
                                {
                                  auto dsum2_fst_90 { std::get<0>(id_808) };
                                  auto dsum2_snd_91 { std::get<1>(id_808) };
                                  t id_810 { std::in_place_index<11>, dsum2_fst_90 };
                                  f63f919559f0d70225bd0da5dd9bcafc id_811 {  id_810, dsum2_snd_91  };
                                  letpair_res_809 = id_811;
                                }
                                choose_res_806 = letpair_res_809;
                              } else {
                                uint16_t id_812 { 12 };
                                bool id_813 { bool(id_812 == dsum1_fst_63) };
                                f63f919559f0d70225bd0da5dd9bcafc choose_res_814;
                                if (id_813) {
                                  std::function<feae865b6fd982b54eeb0d676df0c187(Pointer)> id_815 { dessser_gen::alert.of_row_binary };
                                  feae865b6fd982b54eeb0d676df0c187 id_816 { id_815(dsum1_snd_64) };
                                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_817;
                                  {
                                    auto dsum2_fst_87 { std::get<0>(id_816) };
                                    auto dsum2_snd_88 { std::get<1>(id_816) };
                                    t id_818 { std::in_place_index<12>, dsum2_fst_87 };
                                    f63f919559f0d70225bd0da5dd9bcafc id_819 {  id_818, dsum2_snd_88  };
                                    letpair_res_817 = id_819;
                                  }
                                  choose_res_814 = letpair_res_817;
                                } else {
                                  uint16_t id_820 { 13 };
                                  bool id_821 { bool(id_820 == dsum1_fst_63) };
                                  f63f919559f0d70225bd0da5dd9bcafc choose_res_822;
                                  if (id_821) {
                                    std::function<v_5d3df5ef82bef4373702ab960e6235b2(Pointer)> id_823 { dessser_gen::output_specs.of_row_binary };
                                    v_5d3df5ef82bef4373702ab960e6235b2 id_824 { id_823(dsum1_snd_64) };
                                    f63f919559f0d70225bd0da5dd9bcafc letpair_res_825;
                                    {
                                      auto dsum2_fst_84 { std::get<0>(id_824) };
                                      auto dsum2_snd_85 { std::get<1>(id_824) };
                                      t id_826 { std::in_place_index<13>, dsum2_fst_84 };
                                      f63f919559f0d70225bd0da5dd9bcafc id_827 {  id_826, dsum2_snd_85  };
                                      letpair_res_825 = id_827;
                                    }
                                    choose_res_822 = letpair_res_825;
                                  } else {
                                    uint16_t id_828 { 14 };
                                    bool id_829 { bool(id_828 == dsum1_fst_63) };
                                    f63f919559f0d70225bd0da5dd9bcafc choose_res_830;
                                    if (id_829) {
                                      std::function<v_5c6f406543b9e67fefffd08643986d36(Pointer)> id_831 { dessser_gen::dashboard_widget.of_row_binary };
                                      v_5c6f406543b9e67fefffd08643986d36 id_832 { id_831(dsum1_snd_64) };
                                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_833;
                                      {
                                        auto dsum2_fst_81 { std::get<0>(id_832) };
                                        auto dsum2_snd_82 { std::get<1>(id_832) };
                                        t id_834 { std::in_place_index<14>, dsum2_fst_81 };
                                        f63f919559f0d70225bd0da5dd9bcafc id_835 {  id_834, dsum2_snd_82  };
                                        letpair_res_833 = id_835;
                                      }
                                      choose_res_830 = letpair_res_833;
                                    } else {
                                      uint16_t id_836 { 15 };
                                      bool id_837 { bool(id_836 == dsum1_fst_63) };
                                      f63f919559f0d70225bd0da5dd9bcafc choose_res_838;
                                      if (id_837) {
                                        std::function<v_132ca8e3dcf1135f5d129336ff188b57(Pointer)> id_839 { dessser_gen::alerting_contact.of_row_binary };
                                        v_132ca8e3dcf1135f5d129336ff188b57 id_840 { id_839(dsum1_snd_64) };
                                        f63f919559f0d70225bd0da5dd9bcafc letpair_res_841;
                                        {
                                          auto dsum2_fst_78 { std::get<0>(id_840) };
                                          auto dsum2_snd_79 { std::get<1>(id_840) };
                                          t id_842 { std::in_place_index<15>, dsum2_fst_78 };
                                          f63f919559f0d70225bd0da5dd9bcafc id_843 {  id_842, dsum2_snd_79  };
                                          letpair_res_841 = id_843;
                                        }
                                        choose_res_838 = letpair_res_841;
                                      } else {
                                        uint16_t id_844 { 16 };
                                        bool id_845 { bool(id_844 == dsum1_fst_63) };
                                        f63f919559f0d70225bd0da5dd9bcafc choose_res_846;
                                        if (id_845) {
                                          std::function<v_85f680f1694fafb59f9004d40323f6b5(Pointer)> id_847 { dessser_gen::alerting_notification.of_row_binary };
                                          v_85f680f1694fafb59f9004d40323f6b5 id_848 { id_847(dsum1_snd_64) };
                                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_849;
                                          {
                                            auto dsum2_fst_75 { std::get<0>(id_848) };
                                            auto dsum2_snd_76 { std::get<1>(id_848) };
                                            t id_850 { std::in_place_index<16>, dsum2_fst_75 };
                                            f63f919559f0d70225bd0da5dd9bcafc id_851 {  id_850, dsum2_snd_76  };
                                            letpair_res_849 = id_851;
                                          }
                                          choose_res_846 = letpair_res_849;
                                        } else {
                                          uint16_t id_852 { 17 };
                                          bool id_853 { bool(id_852 == dsum1_fst_63) };
                                          f63f919559f0d70225bd0da5dd9bcafc choose_res_854;
                                          if (id_853) {
                                            std::function<v_9a0fce1a343f193cd07dec4c309db5e5(Pointer)> id_855 { dessser_gen::alerting_delivery_status.of_row_binary };
                                            v_9a0fce1a343f193cd07dec4c309db5e5 id_856 { id_855(dsum1_snd_64) };
                                            f63f919559f0d70225bd0da5dd9bcafc letpair_res_857;
                                            {
                                              auto dsum2_fst_72 { std::get<0>(id_856) };
                                              auto dsum2_snd_73 { std::get<1>(id_856) };
                                              t id_858 { std::in_place_index<17>, dsum2_fst_72 };
                                              f63f919559f0d70225bd0da5dd9bcafc id_859 {  id_858, dsum2_snd_73  };
                                              letpair_res_857 = id_859;
                                            }
                                            choose_res_854 = letpair_res_857;
                                          } else {
                                            uint16_t id_860 { 18 };
                                            bool id_861 { bool(id_860 == dsum1_fst_63) };
                                            f63f919559f0d70225bd0da5dd9bcafc choose_res_862;
                                            if (id_861) {
                                              std::function<v_419eac713b7b9b379f1f3222b985b0e6(Pointer)> id_863 { dessser_gen::alerting_log.of_row_binary };
                                              v_419eac713b7b9b379f1f3222b985b0e6 id_864 { id_863(dsum1_snd_64) };
                                              f63f919559f0d70225bd0da5dd9bcafc letpair_res_865;
                                              {
                                                auto dsum2_fst_69 { std::get<0>(id_864) };
                                                auto dsum2_snd_70 { std::get<1>(id_864) };
                                                t id_866 { std::in_place_index<18>, dsum2_fst_69 };
                                                f63f919559f0d70225bd0da5dd9bcafc id_867 {  id_866, dsum2_snd_70  };
                                                letpair_res_865 = id_867;
                                              }
                                              choose_res_862 = letpair_res_865;
                                            } else {
                                              uint16_t id_868 { 19 };
                                              bool id_869 { bool(dsum1_fst_63 == id_868) };
                                              Void id_870 { ((void)(assert(id_869)), VOID) };
                                              std::function<v_79b7af3dcb201c3fb0f035e41221ecaa(Pointer)> id_871 { dessser_gen::alerting_inhibition.of_row_binary };
                                              v_79b7af3dcb201c3fb0f035e41221ecaa id_872 { id_871(dsum1_snd_64) };
                                              f63f919559f0d70225bd0da5dd9bcafc letpair_res_873;
                                              {
                                                auto dsum2_fst_66 { std::get<0>(id_872) };
                                                auto dsum2_snd_67 { std::get<1>(id_872) };
                                                t id_874 { std::in_place_index<19>, dsum2_fst_66 };
                                                f63f919559f0d70225bd0da5dd9bcafc id_875 {  id_874, dsum2_snd_67  };
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
    f63f919559f0d70225bd0da5dd9bcafc letpair_res_876;
    {
      auto make_fst_194 { std::get<0>(let_res_542) };
      auto make_snd_195 { std::get<1>(let_res_542) };
      f63f919559f0d70225bd0da5dd9bcafc id_877 {  make_fst_194, make_snd_195  };
      letpair_res_876 = id_877;
    }
    return letpair_res_876;
  }
   };
  return fun538;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());


}
