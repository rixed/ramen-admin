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

namespace dessser::gen::runtime_stats {
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
  double stats_time;
  double first_startup;
  double last_startup;
  std::optional<double> min_etime;
  std::optional<double> max_etime;
  std::optional<double> first_input;
  std::optional<double> last_input;
  std::optional<double> first_output;
  std::optional<double> last_output;
  uint64_t tot_in_tuples;
  uint64_t tot_sel_tuples;
  uint64_t tot_out_filtered;
  uint64_t tot_out_tuples;
  uint64_t tot_out_errs;
  uint64_t tot_full_bytes;
  uint64_t tot_full_bytes_samples;
  uint64_t cur_groups;
  uint64_t max_groups;
  uint64_t tot_in_bytes;
  uint64_t tot_out_bytes;
  double tot_wait_in;
  double tot_wait_out;
  uint64_t tot_firing_notifs;
  uint64_t tot_extinguished_notifs;
  double tot_cpu;
  uint64_t cur_ram;
  uint64_t max_ram;
  t(double stats_time_, double first_startup_, double last_startup_, std::optional<double> min_etime_, std::optional<double> max_etime_, std::optional<double> first_input_, std::optional<double> last_input_, std::optional<double> first_output_, std::optional<double> last_output_, uint64_t tot_in_tuples_, uint64_t tot_sel_tuples_, uint64_t tot_out_filtered_, uint64_t tot_out_tuples_, uint64_t tot_out_errs_, uint64_t tot_full_bytes_, uint64_t tot_full_bytes_samples_, uint64_t cur_groups_, uint64_t max_groups_, uint64_t tot_in_bytes_, uint64_t tot_out_bytes_, double tot_wait_in_, double tot_wait_out_, uint64_t tot_firing_notifs_, uint64_t tot_extinguished_notifs_, double tot_cpu_, uint64_t cur_ram_, uint64_t max_ram_) : stats_time(stats_time_), first_startup(first_startup_), last_startup(last_startup_), min_etime(min_etime_), max_etime(max_etime_), first_input(first_input_), last_input(last_input_), first_output(first_output_), last_output(last_output_), tot_in_tuples(tot_in_tuples_), tot_sel_tuples(tot_sel_tuples_), tot_out_filtered(tot_out_filtered_), tot_out_tuples(tot_out_tuples_), tot_out_errs(tot_out_errs_), tot_full_bytes(tot_full_bytes_), tot_full_bytes_samples(tot_full_bytes_samples_), cur_groups(cur_groups_), max_groups(max_groups_), tot_in_bytes(tot_in_bytes_), tot_out_bytes(tot_out_bytes_), tot_wait_in(tot_wait_in_), tot_wait_out(tot_wait_out_), tot_firing_notifs(tot_firing_notifs_), tot_extinguished_notifs(tot_extinguished_notifs_), tot_cpu(tot_cpu_), cur_ram(cur_ram_), max_ram(max_ram_) {}
  t() = default;
};
inline bool operator==(t const &a, t const &b) {
  return a.stats_time == b.stats_time && a.first_startup == b.first_startup && a.last_startup == b.last_startup && ((a.min_etime && b.min_etime && a.min_etime.value() == b.min_etime.value()) || (!a.min_etime && !b.min_etime)) && ((a.max_etime && b.max_etime && a.max_etime.value() == b.max_etime.value()) || (!a.max_etime && !b.max_etime)) && ((a.first_input && b.first_input && a.first_input.value() == b.first_input.value()) || (!a.first_input && !b.first_input)) && ((a.last_input && b.last_input && a.last_input.value() == b.last_input.value()) || (!a.last_input && !b.last_input)) && ((a.first_output && b.first_output && a.first_output.value() == b.first_output.value()) || (!a.first_output && !b.first_output)) && ((a.last_output && b.last_output && a.last_output.value() == b.last_output.value()) || (!a.last_output && !b.last_output)) && a.tot_in_tuples == b.tot_in_tuples && a.tot_sel_tuples == b.tot_sel_tuples && a.tot_out_filtered == b.tot_out_filtered && a.tot_out_tuples == b.tot_out_tuples && a.tot_out_errs == b.tot_out_errs && a.tot_full_bytes == b.tot_full_bytes && a.tot_full_bytes_samples == b.tot_full_bytes_samples && a.cur_groups == b.cur_groups && a.max_groups == b.max_groups && a.tot_in_bytes == b.tot_in_bytes && a.tot_out_bytes == b.tot_out_bytes && a.tot_wait_in == b.tot_wait_in && a.tot_wait_out == b.tot_wait_out && a.tot_firing_notifs == b.tot_firing_notifs && a.tot_extinguished_notifs == b.tot_extinguished_notifs && a.tot_cpu == b.tot_cpu && a.cur_ram == b.cur_ram && a.max_ram == b.max_ram;
}

inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
struct t499f7b290c8689eedd4afcf2712aa820 : public std::tuple<
  std::shared_ptr<::dessser::gen::runtime_stats::t> ,
  Pointer
> {
  using tuple::tuple;
  t499f7b290c8689eedd4afcf2712aa820(std::tuple<std::shared_ptr<::dessser::gen::runtime_stats::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::runtime_stats::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t499f7b290c8689eedd4afcf2712aa820 const &a, t499f7b290c8689eedd4afcf2712aa820 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t499f7b290c8689eedd4afcf2712aa820 const &a, t499f7b290c8689eedd4afcf2712aa820 const &b) {
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
struct t55727524d16738c6d5fa67218480136d : public std::tuple<
  std::optional<double>,
  Pointer
> {
  using tuple::tuple;
  t55727524d16738c6d5fa67218480136d(std::tuple<std::optional<double>, Pointer> p)
    : std::tuple<std::optional<double>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t55727524d16738c6d5fa67218480136d const &a, t55727524d16738c6d5fa67218480136d const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && std::get<0>(a).value() == std::get<0>(b).value()) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t55727524d16738c6d5fa67218480136d const &a, t55727524d16738c6d5fa67218480136d const &b) {
  return !operator==(a, b);
}
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("{stats_time: FLOAT; first_startup: FLOAT; last_startup: FLOAT; min_etime: FLOAT?; max_etime: FLOAT?; first_input: FLOAT?; last_input: FLOAT?; first_output: FLOAT?; last_output: FLOAT?; tot_in_tuples: U64; tot_sel_tuples: U64; tot_out_filtered: U64; tot_out_tuples: U64; tot_out_errs: U64; tot_full_bytes: U64; tot_full_bytes_samples: U64; cur_groups: U64; max_groups: U64; tot_in_bytes: U64; tot_out_bytes: U64; tot_wait_in: FLOAT; tot_wait_out: FLOAT; tot_firing_notifs: U64; tot_extinguished_notifs: U64; tot_cpu: FLOAT; cur_ram: U64; max_ram: U64}" "Ptr")
      (let "srec_dst_291"
        (let "srec_dst_290"
          (let "srec_dst_289"
            (let "srec_dst_288"
              (let "srec_dst_287"
                (let "srec_dst_286"
                  (let "srec_dst_285"
                    (let "srec_dst_284"
                      (let "srec_dst_283"
                        (let "srec_dst_282"
                          (let "srec_dst_281"
                            (let "srec_dst_280"
                              (let "srec_dst_279"
                                (let "srec_dst_278"
                                  (let "srec_dst_277"
                                    (let "srec_dst_276"
                                      (let "srec_dst_275"
                                        (let "srec_dst_274"
                                          (let "srec_dst_273"
                                            (let "srec_dst_272"
                                              (let "srec_dst_271"
                                                (let "srec_dst_270"
                                                  (let "srec_dst_269"
                                                    (let "srec_dst_268"
                                                      (let "srec_dst_267"
                                                        (let "srec_dst_266" 
                                                          (write-u64 little-endian (param 1) (u64-of-float (get-field "stats_time" (param 0))))
                                                          (write-u64 little-endian (identifier "srec_dst_266") (u64-of-float (get-field "first_startup" (param 0)))))
                                                        (write-u64 little-endian (identifier "srec_dst_267") (u64-of-float (get-field "last_startup" (param 0)))))
                                                      (if (is-null (get-field "min_etime" (param 0))) 
                                                        (write-u8 (identifier "srec_dst_268") (u8 1))
                                                        (write-u64 little-endian (write-u8 (identifier "srec_dst_268") (u8 0)) (u64-of-float (force (get-field "min_etime" (param 0)))))))
                                                    (if (is-null (get-field "max_etime" (param 0))) 
                                                      (write-u8 (identifier "srec_dst_269") (u8 1)) 
                                                      (write-u64 little-endian (write-u8 (identifier "srec_dst_269") (u8 0)) (u64-of-float (force (get-field "max_etime" (param 0)))))))
                                                  (if (is-null (get-field "first_input" (param 0))) 
                                                    (write-u8 (identifier "srec_dst_270") (u8 1)) 
                                                    (write-u64 little-endian (write-u8 (identifier "srec_dst_270") (u8 0)) (u64-of-float (force (get-field "first_input" (param 0)))))))
                                                (if (is-null (get-field "last_input" (param 0))) 
                                                  (write-u8 (identifier "srec_dst_271") (u8 1)) 
                                                  (write-u64 little-endian (write-u8 (identifier "srec_dst_271") (u8 0)) (u64-of-float (force (get-field "last_input" (param 0)))))))
                                              (if (is-null (get-field "first_output" (param 0))) 
                                                (write-u8 (identifier "srec_dst_272") (u8 1)) 
                                                (write-u64 little-endian (write-u8 (identifier "srec_dst_272") (u8 0)) (u64-of-float (force (get-field "first_output" (param 0)))))))
                                            (if (is-null (get-field "last_output" (param 0))) 
                                              (write-u8 (identifier "srec_dst_273") (u8 1)) 
                                              (write-u64 little-endian (write-u8 (identifier "srec_dst_273") (u8 0)) (u64-of-float (force (get-field "last_output" (param 0)))))))
                                          (write-u64 little-endian (identifier "srec_dst_274") (get-field "tot_in_tuples" (param 0)))) 
                                        (write-u64 little-endian (identifier "srec_dst_275") (get-field "tot_sel_tuples" (param 0)))) 
                                      (write-u64 little-endian (identifier "srec_dst_276") (get-field "tot_out_filtered" (param 0)))) 
                                    (write-u64 little-endian (identifier "srec_dst_277") (get-field "tot_out_tuples" (param 0)))) 
                                  (write-u64 little-endian (identifier "srec_dst_278") (get-field "tot_out_errs" (param 0)))) 
                                (write-u64 little-endian (identifier "srec_dst_279") (get-field "tot_full_bytes" (param 0)))) 
                              (write-u64 little-endian (identifier "srec_dst_280") (get-field "tot_full_bytes_samples" (param 0)))) 
                            (write-u64 little-endian (identifier "srec_dst_281") (get-field "cur_groups" (param 0)))) 
                          (write-u64 little-endian (identifier "srec_dst_282") (get-field "max_groups" (param 0)))) 
                        (write-u64 little-endian (identifier "srec_dst_283") (get-field "tot_in_bytes" (param 0)))) 
                      (write-u64 little-endian (identifier "srec_dst_284") (get-field "tot_out_bytes" (param 0)))) 
                    (write-u64 little-endian (identifier "srec_dst_285") (u64-of-float (get-field "tot_wait_in" (param 0)))))
                  (write-u64 little-endian (identifier "srec_dst_286") (u64-of-float (get-field "tot_wait_out" (param 0))))) 
                (write-u64 little-endian (identifier "srec_dst_287") (get-field "tot_firing_notifs" (param 0)))) 
              (write-u64 little-endian (identifier "srec_dst_288") (get-field "tot_extinguished_notifs" (param 0)))) 
            (write-u64 little-endian (identifier "srec_dst_289") (u64-of-float (get-field "tot_cpu" (param 0))))) 
          (write-u64 little-endian (identifier "srec_dst_290") (get-field "cur_ram" (param 0)))) 
        (write-u64 little-endian (identifier "srec_dst_291") (get-field "max_ram" (param 0)))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::runtime_stats::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::runtime_stats::t> ,Pointer)> fun0 { [&](std::shared_ptr<::dessser::gen::runtime_stats::t>  p_0, Pointer p_1) {
    double id_1 { (*p_0).stats_time };
    uint64_t id_2 { qword_of_float(id_1) };
    Pointer id_3 { p_1.writeU64Le(id_2) };
    Pointer let_res_4;
    {
      Pointer srec_dst_266 { id_3 };
      double id_5 { (*p_0).first_startup };
      uint64_t id_6 { qword_of_float(id_5) };
      Pointer id_7 { srec_dst_266.writeU64Le(id_6) };
      let_res_4 = id_7;
    }
    Pointer let_res_8;
    {
      Pointer srec_dst_267 { let_res_4 };
      double id_9 { (*p_0).last_startup };
      uint64_t id_10 { qword_of_float(id_9) };
      Pointer id_11 { srec_dst_267.writeU64Le(id_10) };
      let_res_8 = id_11;
    }
    Pointer let_res_12;
    {
      Pointer srec_dst_268 { let_res_8 };
      std::optional<double> id_13 { (*p_0).min_etime };
      bool id_14 { !(id_13.has_value ()) };
      Pointer choose_res_15;
      if (id_14) {
        uint8_t id_16 { 1 };
        Pointer id_17 { srec_dst_268.writeU8(id_16) };
        choose_res_15 = id_17;
      } else {
        uint8_t id_18 { 0 };
        Pointer id_19 { srec_dst_268.writeU8(id_18) };
        std::optional<double> id_20 { (*p_0).min_etime };
        double id_21 { id_20.value() };
        uint64_t id_22 { qword_of_float(id_21) };
        Pointer id_23 { id_19.writeU64Le(id_22) };
        choose_res_15 = id_23;
      }
      let_res_12 = choose_res_15;
    }
    Pointer let_res_24;
    {
      Pointer srec_dst_269 { let_res_12 };
      std::optional<double> id_25 { (*p_0).max_etime };
      bool id_26 { !(id_25.has_value ()) };
      Pointer choose_res_27;
      if (id_26) {
        uint8_t id_28 { 1 };
        Pointer id_29 { srec_dst_269.writeU8(id_28) };
        choose_res_27 = id_29;
      } else {
        uint8_t id_30 { 0 };
        Pointer id_31 { srec_dst_269.writeU8(id_30) };
        std::optional<double> id_32 { (*p_0).max_etime };
        double id_33 { id_32.value() };
        uint64_t id_34 { qword_of_float(id_33) };
        Pointer id_35 { id_31.writeU64Le(id_34) };
        choose_res_27 = id_35;
      }
      let_res_24 = choose_res_27;
    }
    Pointer let_res_36;
    {
      Pointer srec_dst_270 { let_res_24 };
      std::optional<double> id_37 { (*p_0).first_input };
      bool id_38 { !(id_37.has_value ()) };
      Pointer choose_res_39;
      if (id_38) {
        uint8_t id_40 { 1 };
        Pointer id_41 { srec_dst_270.writeU8(id_40) };
        choose_res_39 = id_41;
      } else {
        uint8_t id_42 { 0 };
        Pointer id_43 { srec_dst_270.writeU8(id_42) };
        std::optional<double> id_44 { (*p_0).first_input };
        double id_45 { id_44.value() };
        uint64_t id_46 { qword_of_float(id_45) };
        Pointer id_47 { id_43.writeU64Le(id_46) };
        choose_res_39 = id_47;
      }
      let_res_36 = choose_res_39;
    }
    Pointer let_res_48;
    {
      Pointer srec_dst_271 { let_res_36 };
      std::optional<double> id_49 { (*p_0).last_input };
      bool id_50 { !(id_49.has_value ()) };
      Pointer choose_res_51;
      if (id_50) {
        uint8_t id_52 { 1 };
        Pointer id_53 { srec_dst_271.writeU8(id_52) };
        choose_res_51 = id_53;
      } else {
        uint8_t id_54 { 0 };
        Pointer id_55 { srec_dst_271.writeU8(id_54) };
        std::optional<double> id_56 { (*p_0).last_input };
        double id_57 { id_56.value() };
        uint64_t id_58 { qword_of_float(id_57) };
        Pointer id_59 { id_55.writeU64Le(id_58) };
        choose_res_51 = id_59;
      }
      let_res_48 = choose_res_51;
    }
    Pointer let_res_60;
    {
      Pointer srec_dst_272 { let_res_48 };
      std::optional<double> id_61 { (*p_0).first_output };
      bool id_62 { !(id_61.has_value ()) };
      Pointer choose_res_63;
      if (id_62) {
        uint8_t id_64 { 1 };
        Pointer id_65 { srec_dst_272.writeU8(id_64) };
        choose_res_63 = id_65;
      } else {
        uint8_t id_66 { 0 };
        Pointer id_67 { srec_dst_272.writeU8(id_66) };
        std::optional<double> id_68 { (*p_0).first_output };
        double id_69 { id_68.value() };
        uint64_t id_70 { qword_of_float(id_69) };
        Pointer id_71 { id_67.writeU64Le(id_70) };
        choose_res_63 = id_71;
      }
      let_res_60 = choose_res_63;
    }
    Pointer let_res_72;
    {
      Pointer srec_dst_273 { let_res_60 };
      std::optional<double> id_73 { (*p_0).last_output };
      bool id_74 { !(id_73.has_value ()) };
      Pointer choose_res_75;
      if (id_74) {
        uint8_t id_76 { 1 };
        Pointer id_77 { srec_dst_273.writeU8(id_76) };
        choose_res_75 = id_77;
      } else {
        uint8_t id_78 { 0 };
        Pointer id_79 { srec_dst_273.writeU8(id_78) };
        std::optional<double> id_80 { (*p_0).last_output };
        double id_81 { id_80.value() };
        uint64_t id_82 { qword_of_float(id_81) };
        Pointer id_83 { id_79.writeU64Le(id_82) };
        choose_res_75 = id_83;
      }
      let_res_72 = choose_res_75;
    }
    Pointer let_res_84;
    {
      Pointer srec_dst_274 { let_res_72 };
      uint64_t id_85 { (*p_0).tot_in_tuples };
      Pointer id_86 { srec_dst_274.writeU64Le(id_85) };
      let_res_84 = id_86;
    }
    Pointer let_res_87;
    {
      Pointer srec_dst_275 { let_res_84 };
      uint64_t id_88 { (*p_0).tot_sel_tuples };
      Pointer id_89 { srec_dst_275.writeU64Le(id_88) };
      let_res_87 = id_89;
    }
    Pointer let_res_90;
    {
      Pointer srec_dst_276 { let_res_87 };
      uint64_t id_91 { (*p_0).tot_out_filtered };
      Pointer id_92 { srec_dst_276.writeU64Le(id_91) };
      let_res_90 = id_92;
    }
    Pointer let_res_93;
    {
      Pointer srec_dst_277 { let_res_90 };
      uint64_t id_94 { (*p_0).tot_out_tuples };
      Pointer id_95 { srec_dst_277.writeU64Le(id_94) };
      let_res_93 = id_95;
    }
    Pointer let_res_96;
    {
      Pointer srec_dst_278 { let_res_93 };
      uint64_t id_97 { (*p_0).tot_out_errs };
      Pointer id_98 { srec_dst_278.writeU64Le(id_97) };
      let_res_96 = id_98;
    }
    Pointer let_res_99;
    {
      Pointer srec_dst_279 { let_res_96 };
      uint64_t id_100 { (*p_0).tot_full_bytes };
      Pointer id_101 { srec_dst_279.writeU64Le(id_100) };
      let_res_99 = id_101;
    }
    Pointer let_res_102;
    {
      Pointer srec_dst_280 { let_res_99 };
      uint64_t id_103 { (*p_0).tot_full_bytes_samples };
      Pointer id_104 { srec_dst_280.writeU64Le(id_103) };
      let_res_102 = id_104;
    }
    Pointer let_res_105;
    {
      Pointer srec_dst_281 { let_res_102 };
      uint64_t id_106 { (*p_0).cur_groups };
      Pointer id_107 { srec_dst_281.writeU64Le(id_106) };
      let_res_105 = id_107;
    }
    Pointer let_res_108;
    {
      Pointer srec_dst_282 { let_res_105 };
      uint64_t id_109 { (*p_0).max_groups };
      Pointer id_110 { srec_dst_282.writeU64Le(id_109) };
      let_res_108 = id_110;
    }
    Pointer let_res_111;
    {
      Pointer srec_dst_283 { let_res_108 };
      uint64_t id_112 { (*p_0).tot_in_bytes };
      Pointer id_113 { srec_dst_283.writeU64Le(id_112) };
      let_res_111 = id_113;
    }
    Pointer let_res_114;
    {
      Pointer srec_dst_284 { let_res_111 };
      uint64_t id_115 { (*p_0).tot_out_bytes };
      Pointer id_116 { srec_dst_284.writeU64Le(id_115) };
      let_res_114 = id_116;
    }
    Pointer let_res_117;
    {
      Pointer srec_dst_285 { let_res_114 };
      double id_118 { (*p_0).tot_wait_in };
      uint64_t id_119 { qword_of_float(id_118) };
      Pointer id_120 { srec_dst_285.writeU64Le(id_119) };
      let_res_117 = id_120;
    }
    Pointer let_res_121;
    {
      Pointer srec_dst_286 { let_res_117 };
      double id_122 { (*p_0).tot_wait_out };
      uint64_t id_123 { qword_of_float(id_122) };
      Pointer id_124 { srec_dst_286.writeU64Le(id_123) };
      let_res_121 = id_124;
    }
    Pointer let_res_125;
    {
      Pointer srec_dst_287 { let_res_121 };
      uint64_t id_126 { (*p_0).tot_firing_notifs };
      Pointer id_127 { srec_dst_287.writeU64Le(id_126) };
      let_res_125 = id_127;
    }
    Pointer let_res_128;
    {
      Pointer srec_dst_288 { let_res_125 };
      uint64_t id_129 { (*p_0).tot_extinguished_notifs };
      Pointer id_130 { srec_dst_288.writeU64Le(id_129) };
      let_res_128 = id_130;
    }
    Pointer let_res_131;
    {
      Pointer srec_dst_289 { let_res_128 };
      double id_132 { (*p_0).tot_cpu };
      uint64_t id_133 { qword_of_float(id_132) };
      Pointer id_134 { srec_dst_289.writeU64Le(id_133) };
      let_res_131 = id_134;
    }
    Pointer let_res_135;
    {
      Pointer srec_dst_290 { let_res_131 };
      uint64_t id_136 { (*p_0).cur_ram };
      Pointer id_137 { srec_dst_290.writeU64Le(id_136) };
      let_res_135 = id_137;
    }
    Pointer let_res_138;
    {
      Pointer srec_dst_291 { let_res_135 };
      uint64_t id_139 { (*p_0).max_ram };
      Pointer id_140 { srec_dst_291.writeU64Le(id_139) };
      let_res_138 = id_140;
    }
    return let_res_138;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::runtime_stats::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("{stats_time: FLOAT; first_startup: FLOAT; last_startup: FLOAT; min_etime: FLOAT?; max_etime: FLOAT?; first_input: FLOAT?; last_input: FLOAT?; first_output: FLOAT?; last_output: FLOAT?; tot_in_tuples: U64; tot_sel_tuples: U64; tot_out_filtered: U64; tot_out_tuples: U64; tot_out_errs: U64; tot_full_bytes: U64; tot_full_bytes_samples: U64; cur_groups: U64; max_groups: U64; tot_in_bytes: U64; tot_out_bytes: U64; tot_wait_in: FLOAT; tot_wait_out: FLOAT; tot_firing_notifs: U64; tot_extinguished_notifs: U64; tot_cpu: FLOAT; cur_ram: U64; max_ram: U64}")
      (add
        (add
          (add
            (add
              (add
                (add
                  (add
                    (add
                      (add
                        (add
                          (add
                            (add
                              (add
                                (add
                                  (add
                                    (add
                                      (add
                                        (add
                                          (let "sz_247"
                                            (let "sz_246"
                                              (let "sz_245"
                                                (let "sz_244"
                                                  (if (is-null (get-field "max_etime" (param 0))) 
                                                    (add (if (is-null (get-field "min_etime" (param 0))) (size 25) (size 33)) (size 1))
                                                    (add (add (if (is-null (get-field "min_etime" (param 0))) (size 25) (size 33)) (size 8)) (size 1)))
                                                  (if (is-null (get-field "first_input" (param 0))) (add (identifier "sz_244") (size 1)) (add (add (identifier "sz_244") (size 8)) (size 1))))
                                                (if (is-null (get-field "last_input" (param 0))) (add (identifier "sz_245") (size 1)) (add (add (identifier "sz_245") (size 8)) (size 1))))
                                              (if (is-null (get-field "first_output" (param 0))) (add (identifier "sz_246") (size 1)) (add (add (identifier "sz_246") (size 8)) (size 1))))
                                            (if (is-null (get-field "last_output" (param 0))) (add (identifier "sz_247") (size 1)) (add (add (identifier "sz_247") (size 8)) (size 1)))) 
                                          (size 8)) (size 8)) (size 8)) 
                                    (size 8)) (size 8)) (size 8)) (size 8)) 
                            (size 8)) (size 8)) (size 8)) (size 8)) (size 8)) 
                  (size 8)) (size 8)) (size 8)) (size 8)) (size 8)) (size 8)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::runtime_stats::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::runtime_stats::t> )> fun141 { [&](std::shared_ptr<::dessser::gen::runtime_stats::t>  p_0) {
    std::optional<double> id_142 { (*p_0).max_etime };
    bool id_143 { !(id_142.has_value ()) };
    Size choose_res_144;
    if (id_143) {
      std::optional<double> id_145 { (*p_0).min_etime };
      bool id_146 { !(id_145.has_value ()) };
      Size choose_res_147;
      if (id_146) {
        Size id_148 { 25UL };
        choose_res_147 = id_148;
      } else {
        Size id_149 { 33UL };
        choose_res_147 = id_149;
      }
      Size id_150 { 1UL };
      Size id_151 { Size(choose_res_147 + id_150) };
      choose_res_144 = id_151;
    } else {
      std::optional<double> id_152 { (*p_0).min_etime };
      bool id_153 { !(id_152.has_value ()) };
      Size choose_res_154;
      if (id_153) {
        Size id_155 { 25UL };
        choose_res_154 = id_155;
      } else {
        Size id_156 { 33UL };
        choose_res_154 = id_156;
      }
      Size id_157 { 8UL };
      Size id_158 { Size(choose_res_154 + id_157) };
      Size id_159 { 1UL };
      Size id_160 { Size(id_158 + id_159) };
      choose_res_144 = id_160;
    }
    Size let_res_161;
    {
      Size sz_244 { choose_res_144 };
      std::optional<double> id_162 { (*p_0).first_input };
      bool id_163 { !(id_162.has_value ()) };
      Size choose_res_164;
      if (id_163) {
        Size id_165 { 1UL };
        Size id_166 { Size(sz_244 + id_165) };
        choose_res_164 = id_166;
      } else {
        Size id_167 { 8UL };
        Size id_168 { Size(sz_244 + id_167) };
        Size id_169 { 1UL };
        Size id_170 { Size(id_168 + id_169) };
        choose_res_164 = id_170;
      }
      let_res_161 = choose_res_164;
    }
    Size let_res_171;
    {
      Size sz_245 { let_res_161 };
      std::optional<double> id_172 { (*p_0).last_input };
      bool id_173 { !(id_172.has_value ()) };
      Size choose_res_174;
      if (id_173) {
        Size id_175 { 1UL };
        Size id_176 { Size(sz_245 + id_175) };
        choose_res_174 = id_176;
      } else {
        Size id_177 { 8UL };
        Size id_178 { Size(sz_245 + id_177) };
        Size id_179 { 1UL };
        Size id_180 { Size(id_178 + id_179) };
        choose_res_174 = id_180;
      }
      let_res_171 = choose_res_174;
    }
    Size let_res_181;
    {
      Size sz_246 { let_res_171 };
      std::optional<double> id_182 { (*p_0).first_output };
      bool id_183 { !(id_182.has_value ()) };
      Size choose_res_184;
      if (id_183) {
        Size id_185 { 1UL };
        Size id_186 { Size(sz_246 + id_185) };
        choose_res_184 = id_186;
      } else {
        Size id_187 { 8UL };
        Size id_188 { Size(sz_246 + id_187) };
        Size id_189 { 1UL };
        Size id_190 { Size(id_188 + id_189) };
        choose_res_184 = id_190;
      }
      let_res_181 = choose_res_184;
    }
    Size let_res_191;
    {
      Size sz_247 { let_res_181 };
      std::optional<double> id_192 { (*p_0).last_output };
      bool id_193 { !(id_192.has_value ()) };
      Size choose_res_194;
      if (id_193) {
        Size id_195 { 1UL };
        Size id_196 { Size(sz_247 + id_195) };
        choose_res_194 = id_196;
      } else {
        Size id_197 { 8UL };
        Size id_198 { Size(sz_247 + id_197) };
        Size id_199 { 1UL };
        Size id_200 { Size(id_198 + id_199) };
        choose_res_194 = id_200;
      }
      let_res_191 = choose_res_194;
    }
    Size id_201 { 8UL };
    Size id_202 { Size(let_res_191 + id_201) };
    Size id_203 { 8UL };
    Size id_204 { Size(id_202 + id_203) };
    Size id_205 { 8UL };
    Size id_206 { Size(id_204 + id_205) };
    Size id_207 { 8UL };
    Size id_208 { Size(id_206 + id_207) };
    Size id_209 { 8UL };
    Size id_210 { Size(id_208 + id_209) };
    Size id_211 { 8UL };
    Size id_212 { Size(id_210 + id_211) };
    Size id_213 { 8UL };
    Size id_214 { Size(id_212 + id_213) };
    Size id_215 { 8UL };
    Size id_216 { Size(id_214 + id_215) };
    Size id_217 { 8UL };
    Size id_218 { Size(id_216 + id_217) };
    Size id_219 { 8UL };
    Size id_220 { Size(id_218 + id_219) };
    Size id_221 { 8UL };
    Size id_222 { Size(id_220 + id_221) };
    Size id_223 { 8UL };
    Size id_224 { Size(id_222 + id_223) };
    Size id_225 { 8UL };
    Size id_226 { Size(id_224 + id_225) };
    Size id_227 { 8UL };
    Size id_228 { Size(id_226 + id_227) };
    Size id_229 { 8UL };
    Size id_230 { Size(id_228 + id_229) };
    Size id_231 { 8UL };
    Size id_232 { Size(id_230 + id_231) };
    Size id_233 { 8UL };
    Size id_234 { Size(id_232 + id_233) };
    Size id_235 { 8UL };
    Size id_236 { Size(id_234 + id_235) };
    return id_236;
  }
   };
  return fun141;
}
std::function<Size(std::shared_ptr<::dessser::gen::runtime_stats::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "drec_59" (let-pair "dfloat_fst_57" "dfloat_snd_58" (read-u64 little-endian (param 0)) (make-tup (float-of-u64 (identifier "dfloat_fst_57")) (identifier "dfloat_snd_58")))
        (let-pair "drec_fst_60" "drec_snd_61" (identifier "drec_59")
          (let "drec_65" (let-pair "dfloat_fst_63" "dfloat_snd_64" (read-u64 little-endian (identifier "drec_snd_61")) (make-tup (float-of-u64 (identifier "dfloat_fst_63")) (identifier "dfloat_snd_64")))
            (let-pair "drec_fst_66" "drec_snd_67" (identifier "drec_65")
              (let "drec_71" (let-pair "dfloat_fst_69" "dfloat_snd_70" (read-u64 little-endian (identifier "drec_snd_67")) (make-tup (float-of-u64 (identifier "dfloat_fst_69")) (identifier "dfloat_snd_70")))
                (let-pair "drec_fst_72" "drec_snd_73" (identifier "drec_71")
                  (let "drec_80"
                    (if (eq (peek-u8 (identifier "drec_snd_73") (size 0)) (u8 1)) 
                      (make-tup (null "FLOAT") (ptr-add (identifier "drec_snd_73") (size 1)))
                      (let-pair "dfloat_fst_75" "dfloat_snd_76" (read-u64 little-endian (ptr-add (identifier "drec_snd_73") (size 1)))
                        (make-tup (not-null (float-of-u64 (identifier "dfloat_fst_75"))) (identifier "dfloat_snd_76"))))
                    (let-pair "drec_fst_81" "drec_snd_82" (identifier "drec_80")
                      (let "drec_89"
                        (if (eq (peek-u8 (identifier "drec_snd_82") (size 0)) (u8 1)) 
                          (make-tup (null "FLOAT") (ptr-add (identifier "drec_snd_82") (size 1)))
                          (let-pair "dfloat_fst_84" "dfloat_snd_85" (read-u64 little-endian (ptr-add (identifier "drec_snd_82") (size 1)))
                            (make-tup (not-null (float-of-u64 (identifier "dfloat_fst_84"))) (identifier "dfloat_snd_85"))))
                        (let-pair "drec_fst_90" "drec_snd_91" (identifier "drec_89")
                          (let "drec_98"
                            (if (eq (peek-u8 (identifier "drec_snd_91") (size 0)) (u8 1)) 
                              (make-tup (null "FLOAT") (ptr-add (identifier "drec_snd_91") (size 1)))
                              (let-pair "dfloat_fst_93" "dfloat_snd_94" 
                                (read-u64 little-endian (ptr-add (identifier "drec_snd_91") (size 1))) 
                                (make-tup (not-null (float-of-u64 (identifier "dfloat_fst_93"))) (identifier "dfloat_snd_94"))))
                            (let-pair "drec_fst_99" "drec_snd_100" (identifier "drec_98")
                              (let "drec_107"
                                (if (eq (peek-u8 (identifier "drec_snd_100") (size 0)) (u8 1)) 
                                  (make-tup (null "FLOAT") (ptr-add (identifier "drec_snd_100") (size 1)))
                                  (let-pair "dfloat_fst_102" "dfloat_snd_103" 
                                    (read-u64 little-endian (ptr-add (identifier "drec_snd_100") (size 1))) 
                                    (make-tup (not-null (float-of-u64 (identifier "dfloat_fst_102"))) (identifier "dfloat_snd_103"))))
                                (let-pair "drec_fst_108" "drec_snd_109" 
                                  (identifier "drec_107")
                                  (let "drec_116"
                                    (if (eq (peek-u8 (identifier "drec_snd_109") (size 0)) (u8 1)) 
                                      (make-tup (null "FLOAT") (ptr-add (identifier "drec_snd_109") (size 1)))
                                      (let-pair "dfloat_fst_111" "dfloat_snd_112" 
                                        (read-u64 little-endian (ptr-add (identifier "drec_snd_109") (size 1))) 
                                        (make-tup (not-null (float-of-u64 (identifier "dfloat_fst_111"))) (identifier "dfloat_snd_112"))))
                                    (let-pair "drec_fst_117" "drec_snd_118" 
                                      (identifier "drec_116")
                                      (let "drec_125"
                                        (if (eq (peek-u8 (identifier "drec_snd_118") (size 0)) (u8 1)) 
                                          (make-tup (null "FLOAT") (ptr-add (identifier "drec_snd_118") (size 1)))
                                          (let-pair "dfloat_fst_120" "dfloat_snd_121" 
                                            (read-u64 little-endian (ptr-add (identifier "drec_snd_118") (size 1))) 
                                            (make-tup (not-null (float-of-u64 (identifier "dfloat_fst_120"))) (identifier "dfloat_snd_121"))))
                                        (let-pair "drec_fst_126" "drec_snd_127" 
                                          (identifier "drec_125")
                                          (let "drec_131" (let-pair "du64_fst_129" "du64_snd_130" (read-u64 little-endian (identifier "drec_snd_127")) (make-tup (identifier "du64_fst_129") (identifier "du64_snd_130")))
                                            (let-pair "drec_fst_132" "drec_snd_133" 
                                              (identifier "drec_131")
                                              (let "drec_137" (let-pair "du64_fst_135" "du64_snd_136" (read-u64 little-endian (identifier "drec_snd_133")) (make-tup (identifier "du64_fst_135") (identifier "du64_snd_136")))
                                                (let-pair "drec_fst_138" "drec_snd_139" 
                                                  (identifier "drec_137")
                                                  (let "drec_143" (let-pair "du64_fst_141" "du64_snd_142" (read-u64 little-endian (identifier "drec_snd_139")) (make-tup (identifier "du64_fst_141") (identifier "du64_snd_142")))
                                                    (let-pair "drec_fst_144" "drec_snd_145" 
                                                      (identifier "drec_143")
                                                      (let "drec_149"
                                                        (let-pair "du64_fst_147" "du64_snd_148" (read-u64 little-endian (identifier "drec_snd_145")) (make-tup (identifier "du64_fst_147") (identifier "du64_snd_148")))
                                                        (let-pair "drec_fst_150" "drec_snd_151" 
                                                          (identifier "drec_149")
                                                          (let "drec_155"
                                                            (let-pair "du64_fst_153" "du64_snd_154" (read-u64 little-endian (identifier "drec_snd_151")) (make-tup (identifier "du64_fst_153") (identifier "du64_snd_154")))
                                                            (let-pair "drec_fst_156" "drec_snd_157" 
                                                              (identifier "drec_155")
                                                              (let "drec_161"
                                                                (let-pair "du64_fst_159" "du64_snd_160" (read-u64 little-endian (identifier "drec_snd_157")) (make-tup (identifier "du64_fst_159") (identifier "du64_snd_160")))
                                                                (let-pair "drec_fst_162" "drec_snd_163" 
                                                                  (identifier "drec_161")
                                                                  (let "drec_167"
                                                                    (let-pair "du64_fst_165" "du64_snd_166" (read-u64 little-endian (identifier "drec_snd_163")) (make-tup (identifier "du64_fst_165") (identifier "du64_snd_166")))
                                                                    (let-pair "drec_fst_168" "drec_snd_169" 
                                                                    (identifier "drec_167")
                                                                    (let "drec_173"
                                                                    (let-pair "du64_fst_171" "du64_snd_172" (read-u64 little-endian (identifier "drec_snd_169")) (make-tup (identifier "du64_fst_171") (identifier "du64_snd_172")))
                                                                    (let-pair "drec_fst_174" "drec_snd_175" 
                                                                    (identifier "drec_173")
                                                                    (let "drec_179"
                                                                    (let-pair "du64_fst_177" "du64_snd_178" (read-u64 little-endian (identifier "drec_snd_175")) (make-tup (identifier "du64_fst_177") (identifier "du64_snd_178")))
                                                                    (let-pair "drec_fst_180" "drec_snd_181" 
                                                                    (identifier "drec_179")
                                                                    (let "drec_185"
                                                                    (let-pair "du64_fst_183" "du64_snd_184" (read-u64 little-endian (identifier "drec_snd_181")) (make-tup (identifier "du64_fst_183") (identifier "du64_snd_184")))
                                                                    (let-pair "drec_fst_186" "drec_snd_187" 
                                                                    (identifier "drec_185")
                                                                    (let "drec_191"
                                                                    (let-pair "du64_fst_189" "du64_snd_190" (read-u64 little-endian (identifier "drec_snd_187")) (make-tup (identifier "du64_fst_189") (identifier "du64_snd_190")))
                                                                    (let-pair "drec_fst_192" "drec_snd_193" 
                                                                    (identifier "drec_191")
                                                                    (let "drec_197"
                                                                    (let-pair "dfloat_fst_195" "dfloat_snd_196" 
                                                                    (read-u64 little-endian (identifier "drec_snd_193")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_195")) (identifier "dfloat_snd_196")))
                                                                    (let-pair "drec_fst_198" "drec_snd_199" 
                                                                    (identifier "drec_197")
                                                                    (let "drec_203"
                                                                    (let-pair "dfloat_fst_201" "dfloat_snd_202" 
                                                                    (read-u64 little-endian (identifier "drec_snd_199")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_201")) (identifier "dfloat_snd_202")))
                                                                    (let-pair "drec_fst_204" "drec_snd_205" 
                                                                    (identifier "drec_203")
                                                                    (let "drec_209"
                                                                    (let-pair "du64_fst_207" "du64_snd_208" (read-u64 little-endian (identifier "drec_snd_205")) (make-tup (identifier "du64_fst_207") (identifier "du64_snd_208")))
                                                                    (let-pair "drec_fst_210" "drec_snd_211" 
                                                                    (identifier "drec_209")
                                                                    (let "drec_215"
                                                                    (let-pair "du64_fst_213" "du64_snd_214" (read-u64 little-endian (identifier "drec_snd_211")) (make-tup (identifier "du64_fst_213") (identifier "du64_snd_214")))
                                                                    (let-pair "drec_fst_216" "drec_snd_217" 
                                                                    (identifier "drec_215")
                                                                    (let "drec_221"
                                                                    (let-pair "dfloat_fst_219" "dfloat_snd_220" 
                                                                    (read-u64 little-endian (identifier "drec_snd_217")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_219")) (identifier "dfloat_snd_220")))
                                                                    (let-pair "drec_fst_222" "drec_snd_223" 
                                                                    (identifier "drec_221")
                                                                    (let "drec_227"
                                                                    (let-pair "du64_fst_225" "du64_snd_226" (read-u64 little-endian (identifier "drec_snd_223")) (make-tup (identifier "du64_fst_225") (identifier "du64_snd_226")))
                                                                    (let-pair "drec_fst_228" "drec_snd_229" 
                                                                    (identifier "drec_227")
                                                                    (let-pair "du64_fst_231" "du64_snd_232" 
                                                                    (read-u64 little-endian (identifier "drec_snd_229"))
                                                                    (make-tup
                                                                    (make-rec 
                                                                    (string "max_ram") 
                                                                    (identifier "du64_fst_231") 
                                                                    (string "cur_ram") 
                                                                    (identifier "drec_fst_228") 
                                                                    (string "tot_cpu") 
                                                                    (identifier "drec_fst_222") 
                                                                    (string "tot_extinguished_notifs") 
                                                                    (identifier "drec_fst_216") 
                                                                    (string "tot_firing_notifs") 
                                                                    (identifier "drec_fst_210") 
                                                                    (string "tot_wait_out") 
                                                                    (identifier "drec_fst_204") 
                                                                    (string "tot_wait_in") 
                                                                    (identifier "drec_fst_198") 
                                                                    (string "tot_out_bytes") 
                                                                    (identifier "drec_fst_192") 
                                                                    (string "tot_in_bytes") 
                                                                    (identifier "drec_fst_186") 
                                                                    (string "max_groups") 
                                                                    (identifier "drec_fst_180") 
                                                                    (string "cur_groups") 
                                                                    (identifier "drec_fst_174") 
                                                                    (string "tot_full_bytes_samples") 
                                                                    (identifier "drec_fst_168") 
                                                                    (string "tot_full_bytes") 
                                                                    (identifier "drec_fst_162") 
                                                                    (string "tot_out_errs") 
                                                                    (identifier "drec_fst_156") 
                                                                    (string "tot_out_tuples") 
                                                                    (identifier "drec_fst_150") 
                                                                    (string "tot_out_filtered") 
                                                                    (identifier "drec_fst_144") 
                                                                    (string "tot_sel_tuples") 
                                                                    (identifier "drec_fst_138") 
                                                                    (string "tot_in_tuples") 
                                                                    (identifier "drec_fst_132") 
                                                                    (string "last_output") 
                                                                    (identifier "drec_fst_126") 
                                                                    (string "first_output") 
                                                                    (identifier "drec_fst_117") 
                                                                    (string "last_input") 
                                                                    (identifier "drec_fst_108") 
                                                                    (string "first_input") 
                                                                    (identifier "drec_fst_99") 
                                                                    (string "max_etime") 
                                                                    (identifier "drec_fst_90") 
                                                                    (string "min_etime") 
                                                                    (identifier "drec_fst_81") 
                                                                    (string "last_startup") 
                                                                    (identifier "drec_fst_72") 
                                                                    (string "first_startup") 
                                                                    (identifier "drec_fst_66") 
                                                                    (string "stats_time") 
                                                                    (identifier "drec_fst_60")) 
                                                                    (identifier "du64_snd_232"))))))))))))))))))))))))))))))))))))))))))))))))))))))))
 */
static std::function<::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820(Pointer)> fun237 { [&](Pointer p_0) {
    ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_238 { p_0.readU64Le() };
    ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 letpair_res_239;
    {
      auto dfloat_fst_57 { std::get<0>(id_238) };
      auto dfloat_snd_58 { std::get<1>(id_238) };
      double id_240 { float_of_qword(dfloat_fst_57) };
      ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 id_241 { id_240, dfloat_snd_58 };
      letpair_res_239 = id_241;
    }
    ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_242;
    {
      ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 drec_59 { letpair_res_239 };
      ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_243;
      {
        auto drec_fst_60 { std::get<0>(drec_59) };
        auto drec_snd_61 { std::get<1>(drec_59) };
        ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_244 { drec_snd_61.readU64Le() };
        ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 letpair_res_245;
        {
          auto dfloat_fst_63 { std::get<0>(id_244) };
          auto dfloat_snd_64 { std::get<1>(id_244) };
          double id_246 { float_of_qword(dfloat_fst_63) };
          ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 id_247 { id_246, dfloat_snd_64 };
          letpair_res_245 = id_247;
        }
        ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_248;
        {
          ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 drec_65 { letpair_res_245 };
          ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_249;
          {
            auto drec_fst_66 { std::get<0>(drec_65) };
            auto drec_snd_67 { std::get<1>(drec_65) };
            ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_250 { drec_snd_67.readU64Le() };
            ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 letpair_res_251;
            {
              auto dfloat_fst_69 { std::get<0>(id_250) };
              auto dfloat_snd_70 { std::get<1>(id_250) };
              double id_252 { float_of_qword(dfloat_fst_69) };
              ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 id_253 { id_252, dfloat_snd_70 };
              letpair_res_251 = id_253;
            }
            ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_254;
            {
              ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 drec_71 { letpair_res_251 };
              ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_255;
              {
                auto drec_fst_72 { std::get<0>(drec_71) };
                auto drec_snd_73 { std::get<1>(drec_71) };
                Size id_256 { 0UL };
                uint8_t id_257 { drec_snd_73.peekU8(id_256) };
                uint8_t id_258 { 1 };
                bool id_259 { bool(id_257 == id_258) };
                ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d choose_res_260;
                if (id_259) {
                  std::optional<double> id_261 { std::nullopt };
                  Size id_262 { 1UL };
                  Pointer id_263 { drec_snd_73.skip(id_262) };
                  ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_264 { id_261, id_263 };
                  choose_res_260 = id_264;
                } else {
                  Size id_265 { 1UL };
                  Pointer id_266 { drec_snd_73.skip(id_265) };
                  ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_267 { id_266.readU64Le() };
                  ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d letpair_res_268;
                  {
                    auto dfloat_fst_75 { std::get<0>(id_267) };
                    auto dfloat_snd_76 { std::get<1>(id_267) };
                    double id_269 { float_of_qword(dfloat_fst_75) };
                    std::optional<double> id_270 { id_269 };
                    ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_271 { id_270, dfloat_snd_76 };
                    letpair_res_268 = id_271;
                  }
                  choose_res_260 = letpair_res_268;
                }
                ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_272;
                {
                  ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d drec_80 { choose_res_260 };
                  ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_273;
                  {
                    auto drec_fst_81 { std::get<0>(drec_80) };
                    auto drec_snd_82 { std::get<1>(drec_80) };
                    Size id_274 { 0UL };
                    uint8_t id_275 { drec_snd_82.peekU8(id_274) };
                    uint8_t id_276 { 1 };
                    bool id_277 { bool(id_275 == id_276) };
                    ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d choose_res_278;
                    if (id_277) {
                      std::optional<double> id_279 { std::nullopt };
                      Size id_280 { 1UL };
                      Pointer id_281 { drec_snd_82.skip(id_280) };
                      ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_282 { id_279, id_281 };
                      choose_res_278 = id_282;
                    } else {
                      Size id_283 { 1UL };
                      Pointer id_284 { drec_snd_82.skip(id_283) };
                      ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_285 { id_284.readU64Le() };
                      ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d letpair_res_286;
                      {
                        auto dfloat_fst_84 { std::get<0>(id_285) };
                        auto dfloat_snd_85 { std::get<1>(id_285) };
                        double id_287 { float_of_qword(dfloat_fst_84) };
                        std::optional<double> id_288 { id_287 };
                        ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_289 { id_288, dfloat_snd_85 };
                        letpair_res_286 = id_289;
                      }
                      choose_res_278 = letpair_res_286;
                    }
                    ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_290;
                    {
                      ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d drec_89 { choose_res_278 };
                      ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_291;
                      {
                        auto drec_fst_90 { std::get<0>(drec_89) };
                        auto drec_snd_91 { std::get<1>(drec_89) };
                        Size id_292 { 0UL };
                        uint8_t id_293 { drec_snd_91.peekU8(id_292) };
                        uint8_t id_294 { 1 };
                        bool id_295 { bool(id_293 == id_294) };
                        ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d choose_res_296;
                        if (id_295) {
                          std::optional<double> id_297 { std::nullopt };
                          Size id_298 { 1UL };
                          Pointer id_299 { drec_snd_91.skip(id_298) };
                          ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_300 { id_297, id_299 };
                          choose_res_296 = id_300;
                        } else {
                          Size id_301 { 1UL };
                          Pointer id_302 { drec_snd_91.skip(id_301) };
                          ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_303 { id_302.readU64Le() };
                          ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d letpair_res_304;
                          {
                            auto dfloat_fst_93 { std::get<0>(id_303) };
                            auto dfloat_snd_94 { std::get<1>(id_303) };
                            double id_305 { float_of_qword(dfloat_fst_93) };
                            std::optional<double> id_306 { id_305 };
                            ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_307 { id_306, dfloat_snd_94 };
                            letpair_res_304 = id_307;
                          }
                          choose_res_296 = letpair_res_304;
                        }
                        ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_308;
                        {
                          ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d drec_98 { choose_res_296 };
                          ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_309;
                          {
                            auto drec_fst_99 { std::get<0>(drec_98) };
                            auto drec_snd_100 { std::get<1>(drec_98) };
                            Size id_310 { 0UL };
                            uint8_t id_311 { drec_snd_100.peekU8(id_310) };
                            uint8_t id_312 { 1 };
                            bool id_313 { bool(id_311 == id_312) };
                            ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d choose_res_314;
                            if (id_313) {
                              std::optional<double> id_315 { std::nullopt };
                              Size id_316 { 1UL };
                              Pointer id_317 { drec_snd_100.skip(id_316) };
                              ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_318 { id_315, id_317 };
                              choose_res_314 = id_318;
                            } else {
                              Size id_319 { 1UL };
                              Pointer id_320 { drec_snd_100.skip(id_319) };
                              ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_321 { id_320.readU64Le() };
                              ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d letpair_res_322;
                              {
                                auto dfloat_fst_102 { std::get<0>(id_321) };
                                auto dfloat_snd_103 { std::get<1>(id_321) };
                                double id_323 { float_of_qword(dfloat_fst_102) };
                                std::optional<double> id_324 { id_323 };
                                ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_325 { id_324, dfloat_snd_103 };
                                letpair_res_322 = id_325;
                              }
                              choose_res_314 = letpair_res_322;
                            }
                            ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_326;
                            {
                              ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d drec_107 { choose_res_314 };
                              ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_327;
                              {
                                auto drec_fst_108 { std::get<0>(drec_107) };
                                auto drec_snd_109 { std::get<1>(drec_107) };
                                Size id_328 { 0UL };
                                uint8_t id_329 { drec_snd_109.peekU8(id_328) };
                                uint8_t id_330 { 1 };
                                bool id_331 { bool(id_329 == id_330) };
                                ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d choose_res_332;
                                if (id_331) {
                                  std::optional<double> id_333 { std::nullopt };
                                  Size id_334 { 1UL };
                                  Pointer id_335 { drec_snd_109.skip(id_334) };
                                  ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_336 { id_333, id_335 };
                                  choose_res_332 = id_336;
                                } else {
                                  Size id_337 { 1UL };
                                  Pointer id_338 { drec_snd_109.skip(id_337) };
                                  ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_339 { id_338.readU64Le() };
                                  ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d letpair_res_340;
                                  {
                                    auto dfloat_fst_111 { std::get<0>(id_339) };
                                    auto dfloat_snd_112 { std::get<1>(id_339) };
                                    double id_341 { float_of_qword(dfloat_fst_111) };
                                    std::optional<double> id_342 { id_341 };
                                    ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_343 { id_342, dfloat_snd_112 };
                                    letpair_res_340 = id_343;
                                  }
                                  choose_res_332 = letpair_res_340;
                                }
                                ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_344;
                                {
                                  ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d drec_116 { choose_res_332 };
                                  ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_345;
                                  {
                                    auto drec_fst_117 { std::get<0>(drec_116) };
                                    auto drec_snd_118 { std::get<1>(drec_116) };
                                    Size id_346 { 0UL };
                                    uint8_t id_347 { drec_snd_118.peekU8(id_346) };
                                    uint8_t id_348 { 1 };
                                    bool id_349 { bool(id_347 == id_348) };
                                    ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d choose_res_350;
                                    if (id_349) {
                                      std::optional<double> id_351 { std::nullopt };
                                      Size id_352 { 1UL };
                                      Pointer id_353 { drec_snd_118.skip(id_352) };
                                      ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_354 { id_351, id_353 };
                                      choose_res_350 = id_354;
                                    } else {
                                      Size id_355 { 1UL };
                                      Pointer id_356 { drec_snd_118.skip(id_355) };
                                      ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_357 { id_356.readU64Le() };
                                      ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d letpair_res_358;
                                      {
                                        auto dfloat_fst_120 { std::get<0>(id_357) };
                                        auto dfloat_snd_121 { std::get<1>(id_357) };
                                        double id_359 { float_of_qword(dfloat_fst_120) };
                                        std::optional<double> id_360 { id_359 };
                                        ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d id_361 { id_360, dfloat_snd_121 };
                                        letpair_res_358 = id_361;
                                      }
                                      choose_res_350 = letpair_res_358;
                                    }
                                    ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_362;
                                    {
                                      ::dessser::gen::runtime_stats::t55727524d16738c6d5fa67218480136d drec_125 { choose_res_350 };
                                      ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_363;
                                      {
                                        auto drec_fst_126 { std::get<0>(drec_125) };
                                        auto drec_snd_127 { std::get<1>(drec_125) };
                                        ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_364 { drec_snd_127.readU64Le() };
                                        ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_365;
                                        {
                                          auto du64_fst_129 { std::get<0>(id_364) };
                                          auto du64_snd_130 { std::get<1>(id_364) };
                                          ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_366 { du64_fst_129, du64_snd_130 };
                                          letpair_res_365 = id_366;
                                        }
                                        ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_367;
                                        {
                                          ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_131 { letpair_res_365 };
                                          ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_368;
                                          {
                                            auto drec_fst_132 { std::get<0>(drec_131) };
                                            auto drec_snd_133 { std::get<1>(drec_131) };
                                            ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_369 { drec_snd_133.readU64Le() };
                                            ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_370;
                                            {
                                              auto du64_fst_135 { std::get<0>(id_369) };
                                              auto du64_snd_136 { std::get<1>(id_369) };
                                              ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_371 { du64_fst_135, du64_snd_136 };
                                              letpair_res_370 = id_371;
                                            }
                                            ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_372;
                                            {
                                              ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_137 { letpair_res_370 };
                                              ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_373;
                                              {
                                                auto drec_fst_138 { std::get<0>(drec_137) };
                                                auto drec_snd_139 { std::get<1>(drec_137) };
                                                ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_374 { drec_snd_139.readU64Le() };
                                                ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_375;
                                                {
                                                  auto du64_fst_141 { std::get<0>(id_374) };
                                                  auto du64_snd_142 { std::get<1>(id_374) };
                                                  ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_376 { du64_fst_141, du64_snd_142 };
                                                  letpair_res_375 = id_376;
                                                }
                                                ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_377;
                                                {
                                                  ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_143 { letpair_res_375 };
                                                  ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_378;
                                                  {
                                                    auto drec_fst_144 { std::get<0>(drec_143) };
                                                    auto drec_snd_145 { std::get<1>(drec_143) };
                                                    ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_379 { drec_snd_145.readU64Le() };
                                                    ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_380;
                                                    {
                                                      auto du64_fst_147 { std::get<0>(id_379) };
                                                      auto du64_snd_148 { std::get<1>(id_379) };
                                                      ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_381 { du64_fst_147, du64_snd_148 };
                                                      letpair_res_380 = id_381;
                                                    }
                                                    ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_382;
                                                    {
                                                      ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_149 { letpair_res_380 };
                                                      ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_383;
                                                      {
                                                        auto drec_fst_150 { std::get<0>(drec_149) };
                                                        auto drec_snd_151 { std::get<1>(drec_149) };
                                                        ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_384 { drec_snd_151.readU64Le() };
                                                        ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_385;
                                                        {
                                                          auto du64_fst_153 { std::get<0>(id_384) };
                                                          auto du64_snd_154 { std::get<1>(id_384) };
                                                          ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_386 { du64_fst_153, du64_snd_154 };
                                                          letpair_res_385 = id_386;
                                                        }
                                                        ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_387;
                                                        {
                                                          ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_155 { letpair_res_385 };
                                                          ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_388;
                                                          {
                                                            auto drec_fst_156 { std::get<0>(drec_155) };
                                                            auto drec_snd_157 { std::get<1>(drec_155) };
                                                            ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_389 { drec_snd_157.readU64Le() };
                                                            ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_390;
                                                            {
                                                              auto du64_fst_159 { std::get<0>(id_389) };
                                                              auto du64_snd_160 { std::get<1>(id_389) };
                                                              ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_391 { du64_fst_159, du64_snd_160 };
                                                              letpair_res_390 = id_391;
                                                            }
                                                            ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_392;
                                                            {
                                                              ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_161 { letpair_res_390 };
                                                              ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_393;
                                                              {
                                                                auto drec_fst_162 { std::get<0>(drec_161) };
                                                                auto drec_snd_163 { std::get<1>(drec_161) };
                                                                ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_394 { drec_snd_163.readU64Le() };
                                                                ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_395;
                                                                {
                                                                  auto du64_fst_165 { std::get<0>(id_394) };
                                                                  auto du64_snd_166 { std::get<1>(id_394) };
                                                                  ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_396 { du64_fst_165, du64_snd_166 };
                                                                  letpair_res_395 = id_396;
                                                                }
                                                                ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_397;
                                                                {
                                                                  ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_167 { letpair_res_395 };
                                                                  ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_398;
                                                                  {
                                                                    auto drec_fst_168 { std::get<0>(drec_167) };
                                                                    auto drec_snd_169 { std::get<1>(drec_167) };
                                                                    ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_399 { drec_snd_169.readU64Le() };
                                                                    ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_400;
                                                                    {
                                                                      auto du64_fst_171 { std::get<0>(id_399) };
                                                                      auto du64_snd_172 { std::get<1>(id_399) };
                                                                      ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_401 { du64_fst_171, du64_snd_172 };
                                                                      letpair_res_400 = id_401;
                                                                    }
                                                                    ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_402;
                                                                    {
                                                                      ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_173 { letpair_res_400 };
                                                                      ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_403;
                                                                      {
                                                                        auto drec_fst_174 { std::get<0>(drec_173) };
                                                                        auto drec_snd_175 { std::get<1>(drec_173) };
                                                                        ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_404 { drec_snd_175.readU64Le() };
                                                                        ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_405;
                                                                        {
                                                                          auto du64_fst_177 { std::get<0>(id_404) };
                                                                          auto du64_snd_178 { std::get<1>(id_404) };
                                                                          ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_406 { du64_fst_177, du64_snd_178 };
                                                                          letpair_res_405 = id_406;
                                                                        }
                                                                        ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_407;
                                                                        {
                                                                          ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_179 { letpair_res_405 };
                                                                          ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_408;
                                                                          {
                                                                            auto drec_fst_180 { std::get<0>(drec_179) };
                                                                            auto drec_snd_181 { std::get<1>(drec_179) };
                                                                            ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_409 { drec_snd_181.readU64Le() };
                                                                            ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_410;
                                                                            {
                                                                              auto du64_fst_183 { std::get<0>(id_409) };
                                                                              auto du64_snd_184 { std::get<1>(id_409) };
                                                                              ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_411 { du64_fst_183, du64_snd_184 };
                                                                              letpair_res_410 = id_411;
                                                                            }
                                                                            ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_412;
                                                                            {
                                                                              ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_185 { letpair_res_410 };
                                                                              ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_413;
                                                                              {
                                                                                auto drec_fst_186 { std::get<0>(drec_185) };
                                                                                auto drec_snd_187 { std::get<1>(drec_185) };
                                                                                ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_414 { drec_snd_187.readU64Le() };
                                                                                ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_415;
                                                                                {
                                                                                  auto du64_fst_189 { std::get<0>(id_414) };
                                                                                  auto du64_snd_190 { std::get<1>(id_414) };
                                                                                  ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_416 { du64_fst_189, du64_snd_190 };
                                                                                  letpair_res_415 = id_416;
                                                                                }
                                                                                ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_417;
                                                                                {
                                                                                  ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_191 { letpair_res_415 };
                                                                                  ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_418;
                                                                                  {
                                                                                    auto drec_fst_192 { std::get<0>(drec_191) };
                                                                                    auto drec_snd_193 { std::get<1>(drec_191) };
                                                                                    ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_419 { drec_snd_193.readU64Le() };
                                                                                    ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 letpair_res_420;
                                                                                    {
                                                                                      auto dfloat_fst_195 { std::get<0>(id_419) };
                                                                                      auto dfloat_snd_196 { std::get<1>(id_419) };
                                                                                      double id_421 { float_of_qword(dfloat_fst_195) };
                                                                                      ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 id_422 { id_421, dfloat_snd_196 };
                                                                                      letpair_res_420 = id_422;
                                                                                    }
                                                                                    ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_423;
                                                                                    {
                                                                                      ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 drec_197 { letpair_res_420 };
                                                                                      ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_424;
                                                                                      {
                                                                                        auto drec_fst_198 { std::get<0>(drec_197) };
                                                                                        auto drec_snd_199 { std::get<1>(drec_197) };
                                                                                        ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_425 { drec_snd_199.readU64Le() };
                                                                                        ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 letpair_res_426;
                                                                                        {
                                                                                          auto dfloat_fst_201 { std::get<0>(id_425) };
                                                                                          auto dfloat_snd_202 { std::get<1>(id_425) };
                                                                                          double id_427 { float_of_qword(dfloat_fst_201) };
                                                                                          ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 id_428 { id_427, dfloat_snd_202 };
                                                                                          letpair_res_426 = id_428;
                                                                                        }
                                                                                        ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_429;
                                                                                        {
                                                                                          ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 drec_203 { letpair_res_426 };
                                                                                          ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_430;
                                                                                          {
                                                                                            auto drec_fst_204 { std::get<0>(drec_203) };
                                                                                            auto drec_snd_205 { std::get<1>(drec_203) };
                                                                                            ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_431 { drec_snd_205.readU64Le() };
                                                                                            ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_432;
                                                                                            {
                                                                                              auto du64_fst_207 { std::get<0>(id_431) };
                                                                                              auto du64_snd_208 { std::get<1>(id_431) };
                                                                                              ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_433 { du64_fst_207, du64_snd_208 };
                                                                                              letpair_res_432 = id_433;
                                                                                            }
                                                                                            ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_434;
                                                                                            {
                                                                                              ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_209 { letpair_res_432 };
                                                                                              ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_435;
                                                                                              {
                                                                                                auto drec_fst_210 { std::get<0>(drec_209) };
                                                                                                auto drec_snd_211 { std::get<1>(drec_209) };
                                                                                                ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_436 { drec_snd_211.readU64Le() };
                                                                                                ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_437;
                                                                                                {
                                                                                                  auto du64_fst_213 { std::get<0>(id_436) };
                                                                                                  auto du64_snd_214 { std::get<1>(id_436) };
                                                                                                  ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_438 { du64_fst_213, du64_snd_214 };
                                                                                                  letpair_res_437 = id_438;
                                                                                                }
                                                                                                ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_439;
                                                                                                {
                                                                                                  ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_215 { letpair_res_437 };
                                                                                                  ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_440;
                                                                                                  {
                                                                                                    auto drec_fst_216 { std::get<0>(drec_215) };
                                                                                                    auto drec_snd_217 { std::get<1>(drec_215) };
                                                                                                    ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_441 { drec_snd_217.readU64Le() };
                                                                                                    ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 letpair_res_442;
                                                                                                    {
                                                                                                      auto dfloat_fst_219 { std::get<0>(id_441) };
                                                                                                      auto dfloat_snd_220 { std::get<1>(id_441) };
                                                                                                      double id_443 { float_of_qword(dfloat_fst_219) };
                                                                                                      ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 id_444 { id_443, dfloat_snd_220 };
                                                                                                      letpair_res_442 = id_444;
                                                                                                    }
                                                                                                    ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_445;
                                                                                                    {
                                                                                                      ::dessser::gen::runtime_stats::t9a758baeff17224a77e1a522010b4168 drec_221 { letpair_res_442 };
                                                                                                      ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_446;
                                                                                                      {
                                                                                                        auto drec_fst_222 { std::get<0>(drec_221) };
                                                                                                        auto drec_snd_223 { std::get<1>(drec_221) };
                                                                                                        ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_447 { drec_snd_223.readU64Le() };
                                                                                                        ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b letpair_res_448;
                                                                                                        {
                                                                                                          auto du64_fst_225 { std::get<0>(id_447) };
                                                                                                          auto du64_snd_226 { std::get<1>(id_447) };
                                                                                                          ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_449 { du64_fst_225, du64_snd_226 };
                                                                                                          letpair_res_448 = id_449;
                                                                                                        }
                                                                                                        ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 let_res_450;
                                                                                                        {
                                                                                                          ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b drec_227 { letpair_res_448 };
                                                                                                          ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_451;
                                                                                                          {
                                                                                                            auto drec_fst_228 { std::get<0>(drec_227) };
                                                                                                            auto drec_snd_229 { std::get<1>(drec_227) };
                                                                                                            ::dessser::gen::runtime_stats::td2cd337bb3c8bc04d5603393d084985b id_452 { drec_snd_229.readU64Le() };
                                                                                                            ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_453;
                                                                                                            {
                                                                                                              auto du64_fst_231 { std::get<0>(id_452) };
                                                                                                              auto du64_snd_232 { std::get<1>(id_452) };
                                                                                                              std::shared_ptr<::dessser::gen::runtime_stats::t>  id_454 { std::make_shared<::dessser::gen::runtime_stats::t>(drec_fst_60, drec_fst_66, drec_fst_72, drec_fst_81, drec_fst_90, drec_fst_99, drec_fst_108, drec_fst_117, drec_fst_126, drec_fst_132, drec_fst_138, drec_fst_144, drec_fst_150, drec_fst_156, drec_fst_162, drec_fst_168, drec_fst_174, drec_fst_180, drec_fst_186, drec_fst_192, drec_fst_198, drec_fst_204, drec_fst_210, drec_fst_216, drec_fst_222, drec_fst_228, du64_fst_231) };
                                                                                                              ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 id_455 { id_454, du64_snd_232 };
                                                                                                              letpair_res_453 = id_455;
                                                                                                            }
                                                                                                            letpair_res_451 = letpair_res_453;
                                                                                                          }
                                                                                                          let_res_450 = letpair_res_451;
                                                                                                        }
                                                                                                        letpair_res_446 = let_res_450;
                                                                                                      }
                                                                                                      let_res_445 = letpair_res_446;
                                                                                                    }
                                                                                                    letpair_res_440 = let_res_445;
                                                                                                  }
                                                                                                  let_res_439 = letpair_res_440;
                                                                                                }
                                                                                                letpair_res_435 = let_res_439;
                                                                                              }
                                                                                              let_res_434 = letpair_res_435;
                                                                                            }
                                                                                            letpair_res_430 = let_res_434;
                                                                                          }
                                                                                          let_res_429 = letpair_res_430;
                                                                                        }
                                                                                        letpair_res_424 = let_res_429;
                                                                                      }
                                                                                      let_res_423 = letpair_res_424;
                                                                                    }
                                                                                    letpair_res_418 = let_res_423;
                                                                                  }
                                                                                  let_res_417 = letpair_res_418;
                                                                                }
                                                                                letpair_res_413 = let_res_417;
                                                                              }
                                                                              let_res_412 = letpair_res_413;
                                                                            }
                                                                            letpair_res_408 = let_res_412;
                                                                          }
                                                                          let_res_407 = letpair_res_408;
                                                                        }
                                                                        letpair_res_403 = let_res_407;
                                                                      }
                                                                      let_res_402 = letpair_res_403;
                                                                    }
                                                                    letpair_res_398 = let_res_402;
                                                                  }
                                                                  let_res_397 = letpair_res_398;
                                                                }
                                                                letpair_res_393 = let_res_397;
                                                              }
                                                              let_res_392 = letpair_res_393;
                                                            }
                                                            letpair_res_388 = let_res_392;
                                                          }
                                                          let_res_387 = letpair_res_388;
                                                        }
                                                        letpair_res_383 = let_res_387;
                                                      }
                                                      let_res_382 = letpair_res_383;
                                                    }
                                                    letpair_res_378 = let_res_382;
                                                  }
                                                  let_res_377 = letpair_res_378;
                                                }
                                                letpair_res_373 = let_res_377;
                                              }
                                              let_res_372 = letpair_res_373;
                                            }
                                            letpair_res_368 = let_res_372;
                                          }
                                          let_res_367 = letpair_res_368;
                                        }
                                        letpair_res_363 = let_res_367;
                                      }
                                      let_res_362 = letpair_res_363;
                                    }
                                    letpair_res_345 = let_res_362;
                                  }
                                  let_res_344 = letpair_res_345;
                                }
                                letpair_res_327 = let_res_344;
                              }
                              let_res_326 = letpair_res_327;
                            }
                            letpair_res_309 = let_res_326;
                          }
                          let_res_308 = letpair_res_309;
                        }
                        letpair_res_291 = let_res_308;
                      }
                      let_res_290 = letpair_res_291;
                    }
                    letpair_res_273 = let_res_290;
                  }
                  let_res_272 = letpair_res_273;
                }
                letpair_res_255 = let_res_272;
              }
              let_res_254 = letpair_res_255;
            }
            letpair_res_249 = let_res_254;
          }
          let_res_248 = letpair_res_249;
        }
        letpair_res_243 = let_res_248;
      }
      let_res_242 = letpair_res_243;
    }
    return let_res_242;
  }
   };
  return fun237;
}
std::function<::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_237" "make_snd_238" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_237") (identifier "make_snd_238"))))
 */
static std::function<::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820(Pointer)> fun456 { [&](Pointer p_0) {
    ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 id_457 { of_row_binary(p_0) };
    ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 letpair_res_458;
    {
      auto make_fst_237 { std::get<0>(id_457) };
      auto make_snd_238 { std::get<1>(id_457) };
      ::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820 id_459 { make_fst_237, make_snd_238 };
      letpair_res_458 = id_459;
    }
    return letpair_res_458;
  }
   };
  return fun456;
}
std::function<::dessser::gen::runtime_stats::t499f7b290c8689eedd4afcf2712aa820(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("{stats_time: FLOAT; first_startup: FLOAT; last_startup: FLOAT; min_etime: FLOAT?; max_etime: FLOAT?; first_input: FLOAT?; last_input: FLOAT?; first_output: FLOAT?; last_output: FLOAT?; tot_in_tuples: U64; tot_sel_tuples: U64; tot_out_filtered: U64; tot_out_tuples: U64; tot_out_errs: U64; tot_full_bytes: U64; tot_full_bytes_samples: U64; cur_groups: U64; max_groups: U64; tot_in_bytes: U64; tot_out_bytes: U64; tot_wait_in: FLOAT; tot_wait_out: FLOAT; tot_firing_notifs: U64; tot_extinguished_notifs: U64; tot_cpu: FLOAT; cur_ram: U64; max_ram: U64}" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::runtime_stats::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::runtime_stats::t> ,Pointer)> fun460 { [&](std::shared_ptr<::dessser::gen::runtime_stats::t>  p_0, Pointer p_1) {
    Pointer id_461 { to_row_binary(p_0, p_1) };
    return id_461;
  }
   };
  return fun460;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::runtime_stats::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
