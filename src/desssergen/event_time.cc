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
#include "desssergen/event_time_field.h"
#include "desssergen/event_time_field.h"
#include "desssergen/event_time_field.h"


namespace dessser::gen::event_time {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct tb22291137390f6968b7c7852ed4b8408 : public std::variant<
  double, // DurationConst
  dessser::gen::event_time_field::t_ext, // DurationField
  dessser::gen::event_time_field::t_ext // StopField
> { using variant::variant; };

typedef std::tuple<
  dessser::gen::event_time_field::t_ext,
  ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408
> t;

typedef std::tuple<
  ::dessser::gen::event_time::t*,
  Pointer
> tdaa6372439c84e43d057c41d9a934bcd;

typedef std::tuple<
  dessser::gen::event_time_field::t_ext,
  Pointer
> t4cb1bd2216b69b0142d01965d521ed73;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408,
  Pointer
> tef05027cf9608827fc4c70e50490238a;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("($event_time_field; [DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field])" "Ptr")
      (let "stup_dst_89" (apply (ext-identifier event_time_field to-row-binary) (get-item 0 (param 0)) (param 1))
        (let "ssum_dst_91" (write-u16 little-endian (identifier "stup_dst_89") (label-of (get-item 1 (param 0))))
          (if (eq (u16 0) (label-of (get-item 1 (param 0)))) (write-u64 little-endian (identifier "ssum_dst_91") (u64-of-float (get-alt "DurationConst" (get-item 1 (param 0)))))
            (if (eq (u16 1) (label-of (get-item 1 (param 0)))) (apply (ext-identifier event_time_field to-row-binary) (get-alt "DurationField" (get-item 1 (param 0))) (identifier "ssum_dst_91"))
              (seq (assert (eq (label-of (get-item 1 (param 0))) (u16 2))) (apply (ext-identifier event_time_field to-row-binary) (get-alt "StopField" (get-item 1 (param 0))) (identifier "ssum_dst_91"))))))))
 */
static std::function<Pointer(::dessser::gen::event_time::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::event_time::t*,Pointer)> fun0 { [&fun0](::dessser::gen::event_time::t* p_0, Pointer p_1) {
    auto fun1 { dessser::gen::event_time_field::to_row_binary };
    dessser::gen::event_time_field::t_ext id_2 { std::get<0>(*p_0) };
    Pointer id_3 { fun1(id_2, p_1) };
    Pointer let_res_4;
    {
      Pointer stup_dst_89 { id_3 };
      ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_5 { std::get<1>(*p_0) };
      uint16_t id_6 { uint16_t(id_5.index()) };
      Pointer id_7 { stup_dst_89.writeU16Le(id_6) };
      Pointer let_res_8;
      {
        Pointer ssum_dst_91 { id_7 };
        uint16_t id_9 { 0 };
        ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_10 { std::get<1>(*p_0) };
        uint16_t id_11 { uint16_t(id_10.index()) };
        bool id_12 { bool(id_9 == id_11) };
        Pointer choose_res_13;
        if (id_12) {
          ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_14 { std::get<1>(*p_0) };
          double id_15 { std::get<0 /* DurationConst */>(id_14) };
          uint64_t id_16 { qword_of_float(id_15) };
          Pointer id_17 { ssum_dst_91.writeU64Le(id_16) };
          choose_res_13 = id_17;
        } else {
          uint16_t id_18 { 1 };
          ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_19 { std::get<1>(*p_0) };
          uint16_t id_20 { uint16_t(id_19.index()) };
          bool id_21 { bool(id_18 == id_20) };
          Pointer choose_res_22;
          if (id_21) {
            auto fun23 { dessser::gen::event_time_field::to_row_binary };
            ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_24 { std::get<1>(*p_0) };
            dessser::gen::event_time_field::t_ext id_25 { std::get<1 /* DurationField */>(id_24) };
            Pointer id_26 { fun23(id_25, ssum_dst_91) };
            choose_res_22 = id_26;
          } else {
            ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_27 { std::get<1>(*p_0) };
            uint16_t id_28 { uint16_t(id_27.index()) };
            uint16_t id_29 { 2 };
            bool id_30 { bool(id_28 == id_29) };
            Void id_31 { ((void)(assert(id_30)), VOID) };
            (void)id_31;
            auto fun32 { dessser::gen::event_time_field::to_row_binary };
            ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_33 { std::get<1>(*p_0) };
            dessser::gen::event_time_field::t_ext id_34 { std::get<2 /* StopField */>(id_33) };
            Pointer id_35 { fun32(id_34, ssum_dst_91) };
            choose_res_22 = id_35;
          }
          choose_res_13 = choose_res_22;
        }
        let_res_8 = choose_res_13;
      }
      let_res_4 = let_res_8;
    }
    return let_res_4;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::event_time::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("($event_time_field; [DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field])")
      (let "sz_87" (apply (ext-identifier event_time_field sersize-of-row-binary) (get-item 0 (param 0)))
        (if (eq (u16 0) (label-of (get-item 1 (param 0)))) (add (add (identifier "sz_87") (size 2)) (size 8))
          (if (eq (u16 1) (label-of (get-item 1 (param 0)))) (add (add (identifier "sz_87") (size 2)) (apply (ext-identifier event_time_field sersize-of-row-binary) (get-alt "DurationField" (get-item 1 (param 0)))))
            (seq (assert (eq (label-of (get-item 1 (param 0))) (u16 2))) (add (add (identifier "sz_87") (size 2)) (apply (ext-identifier event_time_field sersize-of-row-binary) (get-alt "StopField" (get-item 1 (param 0))))))))))
 */
static std::function<Size(::dessser::gen::event_time::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::event_time::t*)> fun36 { [&fun36](::dessser::gen::event_time::t* p_0) {
    auto fun37 { dessser::gen::event_time_field::sersize_of_row_binary };
    dessser::gen::event_time_field::t_ext id_38 { std::get<0>(*p_0) };
    Size id_39 { fun37(id_38) };
    Size let_res_40;
    {
      Size sz_87 { id_39 };
      uint16_t id_41 { 0 };
      ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_42 { std::get<1>(*p_0) };
      uint16_t id_43 { uint16_t(id_42.index()) };
      bool id_44 { bool(id_41 == id_43) };
      Size choose_res_45;
      if (id_44) {
        Size id_46 { 2UL };
        Size id_47 { Size(sz_87 + id_46) };
        Size id_48 { 8UL };
        Size id_49 { Size(id_47 + id_48) };
        choose_res_45 = id_49;
      } else {
        uint16_t id_50 { 1 };
        ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_51 { std::get<1>(*p_0) };
        uint16_t id_52 { uint16_t(id_51.index()) };
        bool id_53 { bool(id_50 == id_52) };
        Size choose_res_54;
        if (id_53) {
          Size id_55 { 2UL };
          Size id_56 { Size(sz_87 + id_55) };
          auto fun57 { dessser::gen::event_time_field::sersize_of_row_binary };
          ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_58 { std::get<1>(*p_0) };
          dessser::gen::event_time_field::t_ext id_59 { std::get<1 /* DurationField */>(id_58) };
          Size id_60 { fun57(id_59) };
          Size id_61 { Size(id_56 + id_60) };
          choose_res_54 = id_61;
        } else {
          ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_62 { std::get<1>(*p_0) };
          uint16_t id_63 { uint16_t(id_62.index()) };
          uint16_t id_64 { 2 };
          bool id_65 { bool(id_63 == id_64) };
          Void id_66 { ((void)(assert(id_65)), VOID) };
          (void)id_66;
          Size id_67 { 2UL };
          Size id_68 { Size(sz_87 + id_67) };
          auto fun69 { dessser::gen::event_time_field::sersize_of_row_binary };
          ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_70 { std::get<1>(*p_0) };
          dessser::gen::event_time_field::t_ext id_71 { std::get<2 /* StopField */>(id_70) };
          Size id_72 { fun69(id_71) };
          Size id_73 { Size(id_68 + id_72) };
          choose_res_54 = id_73;
        }
        choose_res_45 = choose_res_54;
      }
      let_res_40 = choose_res_45;
    }
    return let_res_40;
  }
   };
  return fun36;
}
std::function<Size(::dessser::gen::event_time::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_56" (apply (ext-identifier event_time_field of-row-binary) (param 0))
        (let-pair "dtup_fst_57" "dtup_snd_58" (identifier "dtup_56")
          (let-pair "dtup_fst_81" "dtup_snd_82"
            (let "dsum1_65" (let-pair "du16_fst_60" "du16_snd_61" (read-u16 little-endian (identifier "dtup_snd_58")) (make-tup (identifier "du16_fst_60") (identifier "du16_snd_61")))
              (let-pair "dsum1_fst_66" "dsum1_snd_67" (identifier "dsum1_65")
                (if (eq (u16 0) (identifier "dsum1_fst_66"))
                  (let-pair "dfloat_fst_75" "dfloat_snd_76" (read-u64 little-endian (identifier "dsum1_snd_67"))
                    (make-tup (construct "[DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field]" 0 (float-of-u64 (identifier "dfloat_fst_75"))) (identifier "dfloat_snd_76")))
                  (if (eq (u16 1) (identifier "dsum1_fst_66"))
                    (let-pair "dsum2_fst_72" "dsum2_snd_73" (apply (ext-identifier event_time_field of-row-binary) (identifier "dsum1_snd_67"))
                      (make-tup (construct "[DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field]" 1 (identifier "dsum2_fst_72")) (identifier "dsum2_snd_73")))
                    (seq (assert (eq (identifier "dsum1_fst_66") (u16 2)))
                      (let-pair "dsum2_fst_69" "dsum2_snd_70" (apply (ext-identifier event_time_field of-row-binary) (identifier "dsum1_snd_67"))
                        (make-tup (construct "[DurationConst FLOAT | DurationField $event_time_field | StopField $event_time_field]" 2 (identifier "dsum2_fst_69")) (identifier "dsum2_snd_70"))))))))
            (make-tup (make-tup (identifier "dtup_fst_57") (identifier "dtup_fst_81")) (identifier "dtup_snd_82"))))))
 */
static std::function<::dessser::gen::event_time::tdaa6372439c84e43d057c41d9a934bcd(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::event_time::tdaa6372439c84e43d057c41d9a934bcd(Pointer)> fun74 { [&fun74](Pointer p_0) {
    auto fun75 { dessser::gen::event_time_field::of_row_binary };
    ::dessser::gen::event_time::t4cb1bd2216b69b0142d01965d521ed73 id_76 { fun75(p_0) };
    ::dessser::gen::event_time::tdaa6372439c84e43d057c41d9a934bcd let_res_77;
    {
      ::dessser::gen::event_time::t4cb1bd2216b69b0142d01965d521ed73 dtup_56 { id_76 };
      ::dessser::gen::event_time::tdaa6372439c84e43d057c41d9a934bcd letpair_res_78;
      {
        auto dtup_fst_57 { std::get<0>(dtup_56) };
        auto dtup_snd_58 { std::get<1>(dtup_56) };
        ::dessser::gen::event_time::t22a32080ad88ab548b80077a17b7dd46 id_79 { dtup_snd_58.readU16Le() };
        ::dessser::gen::event_time::t22a32080ad88ab548b80077a17b7dd46 letpair_res_80;
        {
          auto du16_fst_60 { std::get<0>(id_79) };
          auto du16_snd_61 { std::get<1>(id_79) };
          ::dessser::gen::event_time::t22a32080ad88ab548b80077a17b7dd46 id_81 { du16_fst_60, du16_snd_61 };
          letpair_res_80 = id_81;
        }
        ::dessser::gen::event_time::tef05027cf9608827fc4c70e50490238a let_res_82;
        {
          ::dessser::gen::event_time::t22a32080ad88ab548b80077a17b7dd46 dsum1_65 { letpair_res_80 };
          ::dessser::gen::event_time::tef05027cf9608827fc4c70e50490238a letpair_res_83;
          {
            auto dsum1_fst_66 { std::get<0>(dsum1_65) };
            auto dsum1_snd_67 { std::get<1>(dsum1_65) };
            uint16_t id_84 { 0 };
            bool id_85 { bool(id_84 == dsum1_fst_66) };
            ::dessser::gen::event_time::tef05027cf9608827fc4c70e50490238a choose_res_86;
            if (id_85) {
              ::dessser::gen::event_time::t7a47220550fc5126a7b79f1e0c10c645 id_87 { dsum1_snd_67.readU64Le() };
              ::dessser::gen::event_time::tef05027cf9608827fc4c70e50490238a letpair_res_88;
              {
                auto dfloat_fst_75 { std::get<0>(id_87) };
                auto dfloat_snd_76 { std::get<1>(id_87) };
                double id_89 { float_of_qword(dfloat_fst_75) };
                ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_90 { std::in_place_index<0>, id_89 };
                ::dessser::gen::event_time::tef05027cf9608827fc4c70e50490238a id_91 { id_90, dfloat_snd_76 };
                letpair_res_88 = id_91;
              }
              choose_res_86 = letpair_res_88;
            } else {
              uint16_t id_92 { 1 };
              bool id_93 { bool(id_92 == dsum1_fst_66) };
              ::dessser::gen::event_time::tef05027cf9608827fc4c70e50490238a choose_res_94;
              if (id_93) {
                auto fun95 { dessser::gen::event_time_field::of_row_binary };
                ::dessser::gen::event_time::t4cb1bd2216b69b0142d01965d521ed73 id_96 { fun95(dsum1_snd_67) };
                ::dessser::gen::event_time::tef05027cf9608827fc4c70e50490238a letpair_res_97;
                {
                  auto dsum2_fst_72 { std::get<0>(id_96) };
                  auto dsum2_snd_73 { std::get<1>(id_96) };
                  ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_98 { std::in_place_index<1>, dsum2_fst_72 };
                  ::dessser::gen::event_time::tef05027cf9608827fc4c70e50490238a id_99 { id_98, dsum2_snd_73 };
                  letpair_res_97 = id_99;
                }
                choose_res_94 = letpair_res_97;
              } else {
                uint16_t id_100 { 2 };
                bool id_101 { bool(dsum1_fst_66 == id_100) };
                Void id_102 { ((void)(assert(id_101)), VOID) };
                (void)id_102;
                auto fun103 { dessser::gen::event_time_field::of_row_binary };
                ::dessser::gen::event_time::t4cb1bd2216b69b0142d01965d521ed73 id_104 { fun103(dsum1_snd_67) };
                ::dessser::gen::event_time::tef05027cf9608827fc4c70e50490238a letpair_res_105;
                {
                  auto dsum2_fst_69 { std::get<0>(id_104) };
                  auto dsum2_snd_70 { std::get<1>(id_104) };
                  ::dessser::gen::event_time::tb22291137390f6968b7c7852ed4b8408 id_106 { std::in_place_index<2>, dsum2_fst_69 };
                  ::dessser::gen::event_time::tef05027cf9608827fc4c70e50490238a id_107 { id_106, dsum2_snd_70 };
                  letpair_res_105 = id_107;
                }
                choose_res_94 = letpair_res_105;
              }
              choose_res_86 = choose_res_94;
            }
            letpair_res_83 = choose_res_86;
          }
          let_res_82 = letpair_res_83;
        }
        ::dessser::gen::event_time::tdaa6372439c84e43d057c41d9a934bcd letpair_res_108;
        {
          auto dtup_fst_81 { std::get<0>(let_res_82) };
          auto dtup_snd_82 { std::get<1>(let_res_82) };
          ::dessser::gen::event_time::t* id_109 { new ::dessser::gen::event_time::t({ dtup_fst_57, dtup_fst_81 }) };
          ::dessser::gen::event_time::tdaa6372439c84e43d057c41d9a934bcd id_110 { id_109, dtup_snd_82 };
          letpair_res_108 = id_110;
        }
        letpair_res_78 = letpair_res_108;
      }
      let_res_77 = letpair_res_78;
    }
    return let_res_77;
  }
   };
  return fun74;
}
std::function<::dessser::gen::event_time::tdaa6372439c84e43d057c41d9a934bcd(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;

}
