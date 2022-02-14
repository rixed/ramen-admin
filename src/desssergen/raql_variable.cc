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

namespace dessser::gen::raql_variable {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
enum t {
  Unknown,
  In,
  GroupState,
  GlobalState,
  OutPrevious,
  Out,
  SortFirst,
  SortSmallest,
  SortGreatest,
  Param,
  Env,
  Record,
  GlobalVar,
};

constexpr size_t t_size { 13 };
struct t40df163e80e2c56cfae759a1807c4d79 : public std::tuple<
  ::dessser::gen::raql_variable::t,
  Pointer
> {
  using tuple::tuple;
  t40df163e80e2c56cfae759a1807c4d79(std::tuple<::dessser::gen::raql_variable::t, Pointer> p)
    : std::tuple<::dessser::gen::raql_variable::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t40df163e80e2c56cfae759a1807c4d79 const &a, t40df163e80e2c56cfae759a1807c4d79 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t40df163e80e2c56cfae759a1807c4d79 const &a, t40df163e80e2c56cfae759a1807c4d79 const &b) {
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" "Ptr")
      (let "label1_109" (label-of (param 0))
        (let "ssum_dst_110" (write-u16 little-endian (param 1) (identifier "label1_109"))
          (if (eq (u16 0) (identifier "label1_109")) (identifier "ssum_dst_110")
            (if (eq (u16 1) (identifier "label1_109")) (identifier "ssum_dst_110")
              (if (eq (u16 2) (identifier "label1_109")) (identifier "ssum_dst_110")
                (if (eq (u16 3) (identifier "label1_109")) (identifier "ssum_dst_110")
                  (if (eq (u16 4) (identifier "label1_109")) (identifier "ssum_dst_110")
                    (if (eq (u16 5) (identifier "label1_109")) (identifier "ssum_dst_110")
                      (if (eq (u16 6) (identifier "label1_109")) (identifier "ssum_dst_110")
                        (if (eq (u16 7) (identifier "label1_109")) (identifier "ssum_dst_110")
                          (if (eq (u16 8) (identifier "label1_109")) 
                            (identifier "ssum_dst_110")
                            (if (eq (u16 9) (identifier "label1_109")) 
                              (identifier "ssum_dst_110")
                              (if (eq (u16 10) (identifier "label1_109")) 
                                (identifier "ssum_dst_110") (if (eq (u16 11) (identifier "label1_109")) (identifier "ssum_dst_110") (seq (assert (eq (identifier "label1_109") (u16 12))) (identifier "ssum_dst_110")))))))))))))))))
 */
static std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> fun0 { [&](::dessser::gen::raql_variable::t p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0) };
    Pointer let_res_2;
    {
      uint16_t label1_109 { id_1 };
      Pointer id_3 { p_1.writeU16Le(label1_109) };
      Pointer let_res_4;
      {
        Pointer ssum_dst_110 { id_3 };
        uint16_t id_5 { 0 };
        bool id_6 { bool(id_5 == label1_109) };
        Pointer choose_res_7;
        if (id_6) {
          choose_res_7 = ssum_dst_110;
        } else {
          uint16_t id_8 { 1 };
          bool id_9 { bool(id_8 == label1_109) };
          Pointer choose_res_10;
          if (id_9) {
            choose_res_10 = ssum_dst_110;
          } else {
            uint16_t id_11 { 2 };
            bool id_12 { bool(id_11 == label1_109) };
            Pointer choose_res_13;
            if (id_12) {
              choose_res_13 = ssum_dst_110;
            } else {
              uint16_t id_14 { 3 };
              bool id_15 { bool(id_14 == label1_109) };
              Pointer choose_res_16;
              if (id_15) {
                choose_res_16 = ssum_dst_110;
              } else {
                uint16_t id_17 { 4 };
                bool id_18 { bool(id_17 == label1_109) };
                Pointer choose_res_19;
                if (id_18) {
                  choose_res_19 = ssum_dst_110;
                } else {
                  uint16_t id_20 { 5 };
                  bool id_21 { bool(id_20 == label1_109) };
                  Pointer choose_res_22;
                  if (id_21) {
                    choose_res_22 = ssum_dst_110;
                  } else {
                    uint16_t id_23 { 6 };
                    bool id_24 { bool(id_23 == label1_109) };
                    Pointer choose_res_25;
                    if (id_24) {
                      choose_res_25 = ssum_dst_110;
                    } else {
                      uint16_t id_26 { 7 };
                      bool id_27 { bool(id_26 == label1_109) };
                      Pointer choose_res_28;
                      if (id_27) {
                        choose_res_28 = ssum_dst_110;
                      } else {
                        uint16_t id_29 { 8 };
                        bool id_30 { bool(id_29 == label1_109) };
                        Pointer choose_res_31;
                        if (id_30) {
                          choose_res_31 = ssum_dst_110;
                        } else {
                          uint16_t id_32 { 9 };
                          bool id_33 { bool(id_32 == label1_109) };
                          Pointer choose_res_34;
                          if (id_33) {
                            choose_res_34 = ssum_dst_110;
                          } else {
                            uint16_t id_35 { 10 };
                            bool id_36 { bool(id_35 == label1_109) };
                            Pointer choose_res_37;
                            if (id_36) {
                              choose_res_37 = ssum_dst_110;
                            } else {
                              uint16_t id_38 { 11 };
                              bool id_39 { bool(id_38 == label1_109) };
                              Pointer choose_res_40;
                              if (id_39) {
                                choose_res_40 = ssum_dst_110;
                              } else {
                                uint16_t id_41 { 12 };
                                bool id_42 { bool(label1_109 == id_41) };
                                Void id_43 { ((void)(assert(id_42)), ::dessser::Void()) };
                                (void)id_43;
                                choose_res_40 = ssum_dst_110;
                              }
                              choose_res_37 = choose_res_40;
                            }
                            choose_res_34 = choose_res_37;
                          }
                          choose_res_31 = choose_res_34;
                        }
                        choose_res_28 = choose_res_31;
                      }
                      choose_res_25 = choose_res_28;
                    }
                    choose_res_22 = choose_res_25;
                  }
                  choose_res_19 = choose_res_22;
                }
                choose_res_16 = choose_res_19;
              }
              choose_res_13 = choose_res_16;
            }
            choose_res_10 = choose_res_13;
          }
          choose_res_7 = choose_res_10;
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
std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]")
      (let "label2_108" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_108")) (size 2)
          (if (eq (u16 1) (identifier "label2_108")) (size 2)
            (if (eq (u16 2) (identifier "label2_108")) (size 2)
              (if (eq (u16 3) (identifier "label2_108")) (size 2)
                (if (eq (u16 4) (identifier "label2_108")) (size 2)
                  (if (eq (u16 5) (identifier "label2_108")) (size 2)
                    (if (eq (u16 6) (identifier "label2_108")) (size 2)
                      (if (eq (u16 7) (identifier "label2_108")) (size 2)
                        (if (eq (u16 8) (identifier "label2_108")) (size 2)
                          (if (eq (u16 9) (identifier "label2_108")) 
                            (size 2) (if (eq (u16 10) (identifier "label2_108")) (size 2) (if (eq (u16 11) (identifier "label2_108")) (size 2) (seq (assert (eq (identifier "label2_108") (u16 12))) (size 2))))))))))))))))
 */
static std::function<Size(::dessser::gen::raql_variable::t const &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_variable::t const &)> fun44 { [&](::dessser::gen::raql_variable::t p_0) {
    uint16_t id_45 { uint16_t(p_0) };
    Size let_res_46;
    {
      uint16_t label2_108 { id_45 };
      uint16_t id_47 { 0 };
      bool id_48 { bool(id_47 == label2_108) };
      Size choose_res_49;
      if (id_48) {
        Size id_50 { 2UL };
        choose_res_49 = id_50;
      } else {
        uint16_t id_51 { 1 };
        bool id_52 { bool(id_51 == label2_108) };
        Size choose_res_53;
        if (id_52) {
          Size id_54 { 2UL };
          choose_res_53 = id_54;
        } else {
          uint16_t id_55 { 2 };
          bool id_56 { bool(id_55 == label2_108) };
          Size choose_res_57;
          if (id_56) {
            Size id_58 { 2UL };
            choose_res_57 = id_58;
          } else {
            uint16_t id_59 { 3 };
            bool id_60 { bool(id_59 == label2_108) };
            Size choose_res_61;
            if (id_60) {
              Size id_62 { 2UL };
              choose_res_61 = id_62;
            } else {
              uint16_t id_63 { 4 };
              bool id_64 { bool(id_63 == label2_108) };
              Size choose_res_65;
              if (id_64) {
                Size id_66 { 2UL };
                choose_res_65 = id_66;
              } else {
                uint16_t id_67 { 5 };
                bool id_68 { bool(id_67 == label2_108) };
                Size choose_res_69;
                if (id_68) {
                  Size id_70 { 2UL };
                  choose_res_69 = id_70;
                } else {
                  uint16_t id_71 { 6 };
                  bool id_72 { bool(id_71 == label2_108) };
                  Size choose_res_73;
                  if (id_72) {
                    Size id_74 { 2UL };
                    choose_res_73 = id_74;
                  } else {
                    uint16_t id_75 { 7 };
                    bool id_76 { bool(id_75 == label2_108) };
                    Size choose_res_77;
                    if (id_76) {
                      Size id_78 { 2UL };
                      choose_res_77 = id_78;
                    } else {
                      uint16_t id_79 { 8 };
                      bool id_80 { bool(id_79 == label2_108) };
                      Size choose_res_81;
                      if (id_80) {
                        Size id_82 { 2UL };
                        choose_res_81 = id_82;
                      } else {
                        uint16_t id_83 { 9 };
                        bool id_84 { bool(id_83 == label2_108) };
                        Size choose_res_85;
                        if (id_84) {
                          Size id_86 { 2UL };
                          choose_res_85 = id_86;
                        } else {
                          uint16_t id_87 { 10 };
                          bool id_88 { bool(id_87 == label2_108) };
                          Size choose_res_89;
                          if (id_88) {
                            Size id_90 { 2UL };
                            choose_res_89 = id_90;
                          } else {
                            uint16_t id_91 { 11 };
                            bool id_92 { bool(id_91 == label2_108) };
                            Size choose_res_93;
                            if (id_92) {
                              Size id_94 { 2UL };
                              choose_res_93 = id_94;
                            } else {
                              uint16_t id_95 { 12 };
                              bool id_96 { bool(label2_108 == id_95) };
                              Void id_97 { ((void)(assert(id_96)), ::dessser::Void()) };
                              (void)id_97;
                              Size id_98 { 2UL };
                              choose_res_93 = id_98;
                            }
                            choose_res_89 = choose_res_93;
                          }
                          choose_res_85 = choose_res_89;
                        }
                        choose_res_81 = choose_res_85;
                      }
                      choose_res_77 = choose_res_81;
                    }
                    choose_res_73 = choose_res_77;
                  }
                  choose_res_69 = choose_res_73;
                }
                choose_res_65 = choose_res_69;
              }
              choose_res_61 = choose_res_65;
            }
            choose_res_57 = choose_res_61;
          }
          choose_res_53 = choose_res_57;
        }
        choose_res_49 = choose_res_53;
      }
      let_res_46 = choose_res_49;
    }
    return let_res_46;
  }
   };
  return fun44;
}
std::function<Size(::dessser::gen::raql_variable::t const &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (make-tup
              (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 0
                (nop)) (identifier "dsum1_snd_65"))
            (if (eq (u16 1) (identifier "dsum1_fst_64"))
              (make-tup
                (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 1
                  (nop)) (identifier "dsum1_snd_65"))
              (if (eq (u16 2) (identifier "dsum1_fst_64"))
                (make-tup
                  (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 2
                    (nop)) (identifier "dsum1_snd_65"))
                (if (eq (u16 3) (identifier "dsum1_fst_64"))
                  (make-tup
                    (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 3
                      (nop)) (identifier "dsum1_snd_65"))
                  (if (eq (u16 4) (identifier "dsum1_fst_64"))
                    (make-tup
                      (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 4
                        (nop)) (identifier "dsum1_snd_65"))
                    (if (eq (u16 5) (identifier "dsum1_fst_64"))
                      (make-tup
                        (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 5
                          (nop)) (identifier "dsum1_snd_65"))
                      (if (eq (u16 6) (identifier "dsum1_fst_64"))
                        (make-tup
                          (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 6
                            (nop)) (identifier "dsum1_snd_65"))
                        (if (eq (u16 7) (identifier "dsum1_fst_64"))
                          (make-tup
                            (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 7
                              (nop)) (identifier "dsum1_snd_65"))
                          (if (eq (u16 8) (identifier "dsum1_fst_64"))
                            (make-tup
                              (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 8
                                (nop)) (identifier "dsum1_snd_65"))
                            (if (eq (u16 9) (identifier "dsum1_fst_64"))
                              (make-tup
                                (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 9
                                  (nop)) (identifier "dsum1_snd_65"))
                              (if (eq (u16 10) (identifier "dsum1_fst_64"))
                                (make-tup
                                  (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 10
                                    (nop)) (identifier "dsum1_snd_65"))
                                (if (eq (u16 11) (identifier "dsum1_fst_64"))
                                  (make-tup
                                    (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 11
                                      (nop)) (identifier "dsum1_snd_65"))
                                  (seq (assert (eq (identifier "dsum1_fst_64") (u16 12)))
                                    (make-tup
                                      (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 12
                                        (nop)) (identifier "dsum1_snd_65"))))))))))))))))))
 */
static std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> fun99 { [&](Pointer p_0) {
    ::dessser::gen::raql_variable::ta97bb48ed75bbda6173555873826c8c6 id_100 { p_0.readU16Le() };
    ::dessser::gen::raql_variable::ta97bb48ed75bbda6173555873826c8c6 letpair_res_101;
    {
      auto du16_fst_58 { std::get<0>(id_100) };
      auto du16_snd_59 { std::get<1>(id_100) };
      ::dessser::gen::raql_variable::ta97bb48ed75bbda6173555873826c8c6 id_102 { du16_fst_58, du16_snd_59 };
      letpair_res_101 = id_102;
    }
    ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 let_res_103;
    {
      ::dessser::gen::raql_variable::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_101 };
      ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 letpair_res_104;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_105 { 0 };
        bool id_106 { bool(id_105 == dsum1_fst_64) };
        ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_107;
        if (id_106) {
          (void)::dessser::Void();
          ::dessser::gen::raql_variable::t id_108 { Unknown };
          ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_109 { id_108, dsum1_snd_65 };
          choose_res_107 = id_109;
        } else {
          uint16_t id_110 { 1 };
          bool id_111 { bool(id_110 == dsum1_fst_64) };
          ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_112;
          if (id_111) {
            (void)::dessser::Void();
            ::dessser::gen::raql_variable::t id_113 { In };
            ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_114 { id_113, dsum1_snd_65 };
            choose_res_112 = id_114;
          } else {
            uint16_t id_115 { 2 };
            bool id_116 { bool(id_115 == dsum1_fst_64) };
            ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_117;
            if (id_116) {
              (void)::dessser::Void();
              ::dessser::gen::raql_variable::t id_118 { GroupState };
              ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_119 { id_118, dsum1_snd_65 };
              choose_res_117 = id_119;
            } else {
              uint16_t id_120 { 3 };
              bool id_121 { bool(id_120 == dsum1_fst_64) };
              ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_122;
              if (id_121) {
                (void)::dessser::Void();
                ::dessser::gen::raql_variable::t id_123 { GlobalState };
                ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_124 { id_123, dsum1_snd_65 };
                choose_res_122 = id_124;
              } else {
                uint16_t id_125 { 4 };
                bool id_126 { bool(id_125 == dsum1_fst_64) };
                ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_127;
                if (id_126) {
                  (void)::dessser::Void();
                  ::dessser::gen::raql_variable::t id_128 { OutPrevious };
                  ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_129 { id_128, dsum1_snd_65 };
                  choose_res_127 = id_129;
                } else {
                  uint16_t id_130 { 5 };
                  bool id_131 { bool(id_130 == dsum1_fst_64) };
                  ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_132;
                  if (id_131) {
                    (void)::dessser::Void();
                    ::dessser::gen::raql_variable::t id_133 { Out };
                    ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_134 { id_133, dsum1_snd_65 };
                    choose_res_132 = id_134;
                  } else {
                    uint16_t id_135 { 6 };
                    bool id_136 { bool(id_135 == dsum1_fst_64) };
                    ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_137;
                    if (id_136) {
                      (void)::dessser::Void();
                      ::dessser::gen::raql_variable::t id_138 { SortFirst };
                      ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_139 { id_138, dsum1_snd_65 };
                      choose_res_137 = id_139;
                    } else {
                      uint16_t id_140 { 7 };
                      bool id_141 { bool(id_140 == dsum1_fst_64) };
                      ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_142;
                      if (id_141) {
                        (void)::dessser::Void();
                        ::dessser::gen::raql_variable::t id_143 { SortSmallest };
                        ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_144 { id_143, dsum1_snd_65 };
                        choose_res_142 = id_144;
                      } else {
                        uint16_t id_145 { 8 };
                        bool id_146 { bool(id_145 == dsum1_fst_64) };
                        ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_147;
                        if (id_146) {
                          (void)::dessser::Void();
                          ::dessser::gen::raql_variable::t id_148 { SortGreatest };
                          ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_149 { id_148, dsum1_snd_65 };
                          choose_res_147 = id_149;
                        } else {
                          uint16_t id_150 { 9 };
                          bool id_151 { bool(id_150 == dsum1_fst_64) };
                          ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_152;
                          if (id_151) {
                            (void)::dessser::Void();
                            ::dessser::gen::raql_variable::t id_153 { Param };
                            ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_154 { id_153, dsum1_snd_65 };
                            choose_res_152 = id_154;
                          } else {
                            uint16_t id_155 { 10 };
                            bool id_156 { bool(id_155 == dsum1_fst_64) };
                            ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_157;
                            if (id_156) {
                              (void)::dessser::Void();
                              ::dessser::gen::raql_variable::t id_158 { Env };
                              ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_159 { id_158, dsum1_snd_65 };
                              choose_res_157 = id_159;
                            } else {
                              uint16_t id_160 { 11 };
                              bool id_161 { bool(id_160 == dsum1_fst_64) };
                              ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_162;
                              if (id_161) {
                                (void)::dessser::Void();
                                ::dessser::gen::raql_variable::t id_163 { Record };
                                ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_164 { id_163, dsum1_snd_65 };
                                choose_res_162 = id_164;
                              } else {
                                uint16_t id_165 { 12 };
                                bool id_166 { bool(dsum1_fst_64 == id_165) };
                                Void id_167 { ((void)(assert(id_166)), ::dessser::Void()) };
                                (void)id_167;
                                (void)::dessser::Void();
                                ::dessser::gen::raql_variable::t id_168 { GlobalVar };
                                ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_169 { id_168, dsum1_snd_65 };
                                choose_res_162 = id_169;
                              }
                              choose_res_157 = choose_res_162;
                            }
                            choose_res_152 = choose_res_157;
                          }
                          choose_res_147 = choose_res_152;
                        }
                        choose_res_142 = choose_res_147;
                      }
                      choose_res_137 = choose_res_142;
                    }
                    choose_res_132 = choose_res_137;
                  }
                  choose_res_127 = choose_res_132;
                }
                choose_res_122 = choose_res_127;
              }
              choose_res_117 = choose_res_122;
            }
            choose_res_112 = choose_res_117;
          }
          choose_res_107 = choose_res_112;
        }
        letpair_res_104 = choose_res_107;
      }
      let_res_103 = letpair_res_104;
    }
    return let_res_103;
  }
   };
  return fun99;
}
std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_106" "make_snd_107" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_106") (identifier "make_snd_107"))))
 */
static std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> fun170 { [&](Pointer p_0) {
    ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_171 { of_row_binary(p_0) };
    ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 letpair_res_172;
    {
      auto make_fst_106 { std::get<0>(id_171) };
      auto make_snd_107 { std::get<1>(id_171) };
      ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_173 { make_fst_106, make_snd_107 };
      letpair_res_172 = id_173;
    }
    return letpair_res_172;
  }
   };
  return fun170;
}
std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[Unknown Void | In Void | GroupState Void | GlobalState Void | OutPrevious Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> fun174 { [&](::dessser::gen::raql_variable::t p_0, Pointer p_1) {
    Pointer id_175 { to_row_binary(p_0, p_1) };
    return id_175;
  }
   };
  return fun174;
}
std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
