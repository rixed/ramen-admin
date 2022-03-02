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
  GlobalLastOut,
  LocalLastOut,
  Out,
  SortFirst,
  SortSmallest,
  SortGreatest,
  Param,
  Env,
  Record,
  GlobalVar,
};
constexpr size_t t_size { 14 };
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
    (fun ("[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" "Ptr")
      (let "label1_112" (label-of (param 0))
        (let "ssum_dst_113" (write-u16 little-endian (param 1) (identifier "label1_112"))
          (if (eq (u16 0) (identifier "label1_112")) (identifier "ssum_dst_113")
            (if (eq (u16 1) (identifier "label1_112")) (identifier "ssum_dst_113")
              (if (eq (u16 2) (identifier "label1_112")) (identifier "ssum_dst_113")
                (if (eq (u16 3) (identifier "label1_112")) (identifier "ssum_dst_113")
                  (if (eq (u16 4) (identifier "label1_112")) (identifier "ssum_dst_113")
                    (if (eq (u16 5) (identifier "label1_112")) (identifier "ssum_dst_113")
                      (if (eq (u16 6) (identifier "label1_112")) (identifier "ssum_dst_113")
                        (if (eq (u16 7) (identifier "label1_112")) (identifier "ssum_dst_113")
                          (if (eq (u16 8) (identifier "label1_112")) 
                            (identifier "ssum_dst_113")
                            (if (eq (u16 9) (identifier "label1_112")) 
                              (identifier "ssum_dst_113")
                              (if (eq (u16 10) (identifier "label1_112")) 
                                (identifier "ssum_dst_113")
                                (if (eq (u16 11) (identifier "label1_112")) 
                                  (identifier "ssum_dst_113") (if (eq (u16 12) (identifier "label1_112")) (identifier "ssum_dst_113") (seq (assert (eq (identifier "label1_112") (u16 13))) (identifier "ssum_dst_113"))))))))))))))))))
 */
static std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> fun0 { [&](::dessser::gen::raql_variable::t p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0) };
    Pointer let_res_2;
    {
      uint16_t label1_112 { id_1 };
      Pointer id_3 { p_1.writeU16Le(label1_112) };
      Pointer let_res_4;
      {
        Pointer ssum_dst_113 { id_3 };
        uint16_t id_5 { 0 };
        bool id_6 { bool(id_5 == label1_112) };
        Pointer choose_res_7;
        if (id_6) {
          choose_res_7 = ssum_dst_113;
        } else {
          uint16_t id_8 { 1 };
          bool id_9 { bool(id_8 == label1_112) };
          Pointer choose_res_10;
          if (id_9) {
            choose_res_10 = ssum_dst_113;
          } else {
            uint16_t id_11 { 2 };
            bool id_12 { bool(id_11 == label1_112) };
            Pointer choose_res_13;
            if (id_12) {
              choose_res_13 = ssum_dst_113;
            } else {
              uint16_t id_14 { 3 };
              bool id_15 { bool(id_14 == label1_112) };
              Pointer choose_res_16;
              if (id_15) {
                choose_res_16 = ssum_dst_113;
              } else {
                uint16_t id_17 { 4 };
                bool id_18 { bool(id_17 == label1_112) };
                Pointer choose_res_19;
                if (id_18) {
                  choose_res_19 = ssum_dst_113;
                } else {
                  uint16_t id_20 { 5 };
                  bool id_21 { bool(id_20 == label1_112) };
                  Pointer choose_res_22;
                  if (id_21) {
                    choose_res_22 = ssum_dst_113;
                  } else {
                    uint16_t id_23 { 6 };
                    bool id_24 { bool(id_23 == label1_112) };
                    Pointer choose_res_25;
                    if (id_24) {
                      choose_res_25 = ssum_dst_113;
                    } else {
                      uint16_t id_26 { 7 };
                      bool id_27 { bool(id_26 == label1_112) };
                      Pointer choose_res_28;
                      if (id_27) {
                        choose_res_28 = ssum_dst_113;
                      } else {
                        uint16_t id_29 { 8 };
                        bool id_30 { bool(id_29 == label1_112) };
                        Pointer choose_res_31;
                        if (id_30) {
                          choose_res_31 = ssum_dst_113;
                        } else {
                          uint16_t id_32 { 9 };
                          bool id_33 { bool(id_32 == label1_112) };
                          Pointer choose_res_34;
                          if (id_33) {
                            choose_res_34 = ssum_dst_113;
                          } else {
                            uint16_t id_35 { 10 };
                            bool id_36 { bool(id_35 == label1_112) };
                            Pointer choose_res_37;
                            if (id_36) {
                              choose_res_37 = ssum_dst_113;
                            } else {
                              uint16_t id_38 { 11 };
                              bool id_39 { bool(id_38 == label1_112) };
                              Pointer choose_res_40;
                              if (id_39) {
                                choose_res_40 = ssum_dst_113;
                              } else {
                                uint16_t id_41 { 12 };
                                bool id_42 { bool(id_41 == label1_112) };
                                Pointer choose_res_43;
                                if (id_42) {
                                  choose_res_43 = ssum_dst_113;
                                } else {
                                  uint16_t id_44 { 13 };
                                  bool id_45 { bool(label1_112 == id_44) };
                                  Void id_46 { ((void)(assert(id_45)), ::dessser::Void()) };
                                  (void)id_46;
                                  choose_res_43 = ssum_dst_113;
                                }
                                choose_res_40 = choose_res_43;
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
    (fun ("[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]")
      (let "label2_111" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_111")) (size 2)
          (if (eq (u16 1) (identifier "label2_111")) (size 2)
            (if (eq (u16 2) (identifier "label2_111")) (size 2)
              (if (eq (u16 3) (identifier "label2_111")) (size 2)
                (if (eq (u16 4) (identifier "label2_111")) (size 2)
                  (if (eq (u16 5) (identifier "label2_111")) (size 2)
                    (if (eq (u16 6) (identifier "label2_111")) (size 2)
                      (if (eq (u16 7) (identifier "label2_111")) (size 2)
                        (if (eq (u16 8) (identifier "label2_111")) (size 2)
                          (if (eq (u16 9) (identifier "label2_111")) 
                            (size 2)
                            (if (eq (u16 10) (identifier "label2_111")) 
                              (size 2) (if (eq (u16 11) (identifier "label2_111")) (size 2) (if (eq (u16 12) (identifier "label2_111")) (size 2) (seq (assert (eq (identifier "label2_111") (u16 13))) (size 2)))))))))))))))))
 */
static std::function<Size(::dessser::gen::raql_variable::t const &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::raql_variable::t const &)> fun47 { [&](::dessser::gen::raql_variable::t p_0) {
    uint16_t id_48 { uint16_t(p_0) };
    Size let_res_49;
    {
      uint16_t label2_111 { id_48 };
      uint16_t id_50 { 0 };
      bool id_51 { bool(id_50 == label2_111) };
      Size choose_res_52;
      if (id_51) {
        Size id_53 { 2UL };
        choose_res_52 = id_53;
      } else {
        uint16_t id_54 { 1 };
        bool id_55 { bool(id_54 == label2_111) };
        Size choose_res_56;
        if (id_55) {
          Size id_57 { 2UL };
          choose_res_56 = id_57;
        } else {
          uint16_t id_58 { 2 };
          bool id_59 { bool(id_58 == label2_111) };
          Size choose_res_60;
          if (id_59) {
            Size id_61 { 2UL };
            choose_res_60 = id_61;
          } else {
            uint16_t id_62 { 3 };
            bool id_63 { bool(id_62 == label2_111) };
            Size choose_res_64;
            if (id_63) {
              Size id_65 { 2UL };
              choose_res_64 = id_65;
            } else {
              uint16_t id_66 { 4 };
              bool id_67 { bool(id_66 == label2_111) };
              Size choose_res_68;
              if (id_67) {
                Size id_69 { 2UL };
                choose_res_68 = id_69;
              } else {
                uint16_t id_70 { 5 };
                bool id_71 { bool(id_70 == label2_111) };
                Size choose_res_72;
                if (id_71) {
                  Size id_73 { 2UL };
                  choose_res_72 = id_73;
                } else {
                  uint16_t id_74 { 6 };
                  bool id_75 { bool(id_74 == label2_111) };
                  Size choose_res_76;
                  if (id_75) {
                    Size id_77 { 2UL };
                    choose_res_76 = id_77;
                  } else {
                    uint16_t id_78 { 7 };
                    bool id_79 { bool(id_78 == label2_111) };
                    Size choose_res_80;
                    if (id_79) {
                      Size id_81 { 2UL };
                      choose_res_80 = id_81;
                    } else {
                      uint16_t id_82 { 8 };
                      bool id_83 { bool(id_82 == label2_111) };
                      Size choose_res_84;
                      if (id_83) {
                        Size id_85 { 2UL };
                        choose_res_84 = id_85;
                      } else {
                        uint16_t id_86 { 9 };
                        bool id_87 { bool(id_86 == label2_111) };
                        Size choose_res_88;
                        if (id_87) {
                          Size id_89 { 2UL };
                          choose_res_88 = id_89;
                        } else {
                          uint16_t id_90 { 10 };
                          bool id_91 { bool(id_90 == label2_111) };
                          Size choose_res_92;
                          if (id_91) {
                            Size id_93 { 2UL };
                            choose_res_92 = id_93;
                          } else {
                            uint16_t id_94 { 11 };
                            bool id_95 { bool(id_94 == label2_111) };
                            Size choose_res_96;
                            if (id_95) {
                              Size id_97 { 2UL };
                              choose_res_96 = id_97;
                            } else {
                              uint16_t id_98 { 12 };
                              bool id_99 { bool(id_98 == label2_111) };
                              Size choose_res_100;
                              if (id_99) {
                                Size id_101 { 2UL };
                                choose_res_100 = id_101;
                              } else {
                                uint16_t id_102 { 13 };
                                bool id_103 { bool(label2_111 == id_102) };
                                Void id_104 { ((void)(assert(id_103)), ::dessser::Void()) };
                                (void)id_104;
                                Size id_105 { 2UL };
                                choose_res_100 = id_105;
                              }
                              choose_res_96 = choose_res_100;
                            }
                            choose_res_92 = choose_res_96;
                          }
                          choose_res_88 = choose_res_92;
                        }
                        choose_res_84 = choose_res_88;
                      }
                      choose_res_80 = choose_res_84;
                    }
                    choose_res_76 = choose_res_80;
                  }
                  choose_res_72 = choose_res_76;
                }
                choose_res_68 = choose_res_72;
              }
              choose_res_64 = choose_res_68;
            }
            choose_res_60 = choose_res_64;
          }
          choose_res_56 = choose_res_60;
        }
        choose_res_52 = choose_res_56;
      }
      let_res_49 = choose_res_52;
    }
    return let_res_49;
  }
   };
  return fun47;
}
std::function<Size(::dessser::gen::raql_variable::t const &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (make-tup
              (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 0
                (nop)) (identifier "dsum1_snd_65"))
            (if (eq (u16 1) (identifier "dsum1_fst_64"))
              (make-tup
                (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 1
                  (nop)) (identifier "dsum1_snd_65"))
              (if (eq (u16 2) (identifier "dsum1_fst_64"))
                (make-tup
                  (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 2
                    (nop)) (identifier "dsum1_snd_65"))
                (if (eq (u16 3) (identifier "dsum1_fst_64"))
                  (make-tup
                    (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 3
                      (nop)) (identifier "dsum1_snd_65"))
                  (if (eq (u16 4) (identifier "dsum1_fst_64"))
                    (make-tup
                      (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 4
                        (nop)) (identifier "dsum1_snd_65"))
                    (if (eq (u16 5) (identifier "dsum1_fst_64"))
                      (make-tup
                        (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 5
                          (nop)) (identifier "dsum1_snd_65"))
                      (if (eq (u16 6) (identifier "dsum1_fst_64"))
                        (make-tup
                          (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 6
                            (nop)) (identifier "dsum1_snd_65"))
                        (if (eq (u16 7) (identifier "dsum1_fst_64"))
                          (make-tup
                            (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 7
                              (nop)) (identifier "dsum1_snd_65"))
                          (if (eq (u16 8) (identifier "dsum1_fst_64"))
                            (make-tup
                              (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 8
                                (nop)) (identifier "dsum1_snd_65"))
                            (if (eq (u16 9) (identifier "dsum1_fst_64"))
                              (make-tup
                                (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 9
                                  (nop)) (identifier "dsum1_snd_65"))
                              (if (eq (u16 10) (identifier "dsum1_fst_64"))
                                (make-tup
                                  (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 10
                                    (nop)) (identifier "dsum1_snd_65"))
                                (if (eq (u16 11) (identifier "dsum1_fst_64"))
                                  (make-tup
                                    (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 11
                                      (nop)) (identifier "dsum1_snd_65"))
                                  (if (eq (u16 12) (identifier "dsum1_fst_64"))
                                    (make-tup
                                      (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 12
                                        (nop)) (identifier "dsum1_snd_65"))
                                    (seq (assert (eq (identifier "dsum1_fst_64") (u16 13)))
                                      (make-tup
                                        (construct "[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" 13
                                          (nop)) (identifier "dsum1_snd_65")))))))))))))))))))
 */
static std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> fun106 { [&](Pointer p_0) {
    ::dessser::gen::raql_variable::ta97bb48ed75bbda6173555873826c8c6 id_107 { p_0.readU16Le() };
    ::dessser::gen::raql_variable::ta97bb48ed75bbda6173555873826c8c6 letpair_res_108;
    {
      auto du16_fst_58 { std::get<0>(id_107) };
      auto du16_snd_59 { std::get<1>(id_107) };
      ::dessser::gen::raql_variable::ta97bb48ed75bbda6173555873826c8c6 id_109 { du16_fst_58, du16_snd_59 };
      letpair_res_108 = id_109;
    }
    ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 let_res_110;
    {
      ::dessser::gen::raql_variable::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_108 };
      ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 letpair_res_111;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_112 { 0 };
        bool id_113 { bool(id_112 == dsum1_fst_64) };
        ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_114;
        if (id_113) {
          (void)::dessser::Void();
          ::dessser::gen::raql_variable::t id_115 { Unknown };
          ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_116 { id_115, dsum1_snd_65 };
          choose_res_114 = id_116;
        } else {
          uint16_t id_117 { 1 };
          bool id_118 { bool(id_117 == dsum1_fst_64) };
          ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_119;
          if (id_118) {
            (void)::dessser::Void();
            ::dessser::gen::raql_variable::t id_120 { In };
            ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_121 { id_120, dsum1_snd_65 };
            choose_res_119 = id_121;
          } else {
            uint16_t id_122 { 2 };
            bool id_123 { bool(id_122 == dsum1_fst_64) };
            ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_124;
            if (id_123) {
              (void)::dessser::Void();
              ::dessser::gen::raql_variable::t id_125 { GroupState };
              ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_126 { id_125, dsum1_snd_65 };
              choose_res_124 = id_126;
            } else {
              uint16_t id_127 { 3 };
              bool id_128 { bool(id_127 == dsum1_fst_64) };
              ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_129;
              if (id_128) {
                (void)::dessser::Void();
                ::dessser::gen::raql_variable::t id_130 { GlobalState };
                ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_131 { id_130, dsum1_snd_65 };
                choose_res_129 = id_131;
              } else {
                uint16_t id_132 { 4 };
                bool id_133 { bool(id_132 == dsum1_fst_64) };
                ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_134;
                if (id_133) {
                  (void)::dessser::Void();
                  ::dessser::gen::raql_variable::t id_135 { GlobalLastOut };
                  ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_136 { id_135, dsum1_snd_65 };
                  choose_res_134 = id_136;
                } else {
                  uint16_t id_137 { 5 };
                  bool id_138 { bool(id_137 == dsum1_fst_64) };
                  ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_139;
                  if (id_138) {
                    (void)::dessser::Void();
                    ::dessser::gen::raql_variable::t id_140 { LocalLastOut };
                    ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_141 { id_140, dsum1_snd_65 };
                    choose_res_139 = id_141;
                  } else {
                    uint16_t id_142 { 6 };
                    bool id_143 { bool(id_142 == dsum1_fst_64) };
                    ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_144;
                    if (id_143) {
                      (void)::dessser::Void();
                      ::dessser::gen::raql_variable::t id_145 { Out };
                      ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_146 { id_145, dsum1_snd_65 };
                      choose_res_144 = id_146;
                    } else {
                      uint16_t id_147 { 7 };
                      bool id_148 { bool(id_147 == dsum1_fst_64) };
                      ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_149;
                      if (id_148) {
                        (void)::dessser::Void();
                        ::dessser::gen::raql_variable::t id_150 { SortFirst };
                        ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_151 { id_150, dsum1_snd_65 };
                        choose_res_149 = id_151;
                      } else {
                        uint16_t id_152 { 8 };
                        bool id_153 { bool(id_152 == dsum1_fst_64) };
                        ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_154;
                        if (id_153) {
                          (void)::dessser::Void();
                          ::dessser::gen::raql_variable::t id_155 { SortSmallest };
                          ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_156 { id_155, dsum1_snd_65 };
                          choose_res_154 = id_156;
                        } else {
                          uint16_t id_157 { 9 };
                          bool id_158 { bool(id_157 == dsum1_fst_64) };
                          ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_159;
                          if (id_158) {
                            (void)::dessser::Void();
                            ::dessser::gen::raql_variable::t id_160 { SortGreatest };
                            ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_161 { id_160, dsum1_snd_65 };
                            choose_res_159 = id_161;
                          } else {
                            uint16_t id_162 { 10 };
                            bool id_163 { bool(id_162 == dsum1_fst_64) };
                            ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_164;
                            if (id_163) {
                              (void)::dessser::Void();
                              ::dessser::gen::raql_variable::t id_165 { Param };
                              ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_166 { id_165, dsum1_snd_65 };
                              choose_res_164 = id_166;
                            } else {
                              uint16_t id_167 { 11 };
                              bool id_168 { bool(id_167 == dsum1_fst_64) };
                              ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_169;
                              if (id_168) {
                                (void)::dessser::Void();
                                ::dessser::gen::raql_variable::t id_170 { Env };
                                ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_171 { id_170, dsum1_snd_65 };
                                choose_res_169 = id_171;
                              } else {
                                uint16_t id_172 { 12 };
                                bool id_173 { bool(id_172 == dsum1_fst_64) };
                                ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 choose_res_174;
                                if (id_173) {
                                  (void)::dessser::Void();
                                  ::dessser::gen::raql_variable::t id_175 { Record };
                                  ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_176 { id_175, dsum1_snd_65 };
                                  choose_res_174 = id_176;
                                } else {
                                  uint16_t id_177 { 13 };
                                  bool id_178 { bool(dsum1_fst_64 == id_177) };
                                  Void id_179 { ((void)(assert(id_178)), ::dessser::Void()) };
                                  (void)id_179;
                                  (void)::dessser::Void();
                                  ::dessser::gen::raql_variable::t id_180 { GlobalVar };
                                  ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_181 { id_180, dsum1_snd_65 };
                                  choose_res_174 = id_181;
                                }
                                choose_res_169 = choose_res_174;
                              }
                              choose_res_164 = choose_res_169;
                            }
                            choose_res_159 = choose_res_164;
                          }
                          choose_res_154 = choose_res_159;
                        }
                        choose_res_149 = choose_res_154;
                      }
                      choose_res_144 = choose_res_149;
                    }
                    choose_res_139 = choose_res_144;
                  }
                  choose_res_134 = choose_res_139;
                }
                choose_res_129 = choose_res_134;
              }
              choose_res_124 = choose_res_129;
            }
            choose_res_119 = choose_res_124;
          }
          choose_res_114 = choose_res_119;
        }
        letpair_res_111 = choose_res_114;
      }
      let_res_110 = letpair_res_111;
    }
    return let_res_110;
  }
   };
  return fun106;
}
std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_109" "make_snd_110" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_109") (identifier "make_snd_110"))))
 */
static std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> fun182 { [&](Pointer p_0) {
    ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_183 { of_row_binary(p_0) };
    ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 letpair_res_184;
    {
      auto make_fst_109 { std::get<0>(id_183) };
      auto make_snd_110 { std::get<1>(id_183) };
      ::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79 id_185 { make_fst_109, make_snd_110 };
      letpair_res_184 = id_185;
    }
    return letpair_res_184;
  }
   };
  return fun182;
}
std::function<::dessser::gen::raql_variable::t40df163e80e2c56cfae759a1807c4d79(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[Unknown Void | In Void | GroupState Void | GlobalState Void | GlobalLastOut Void | LocalLastOut Void | Out Void | SortFirst Void | SortSmallest Void | SortGreatest Void | Param Void | Env Void | Record Void | GlobalVar Void]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> fun186 { [&](::dessser::gen::raql_variable::t p_0, Pointer p_1) {
    Pointer id_187 { to_row_binary(p_0, p_1) };
    return id_187;
  }
   };
  return fun186;
}
std::function<Pointer(::dessser::gen::raql_variable::t const &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
