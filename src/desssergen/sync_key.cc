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
struct v_808252496816a9c094ed1ddb199861d1 : public std::variant<
  uint32_t
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_808252496816a9c094ed1ddb199861d1 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

typedef std::tuple<
  v_808252496816a9c094ed1ddb199861d1,
  Pointer
> bb7a1af56c56ee3850e41d7e7bbfd8d3;

typedef std::tuple<
  uint16_t,
  Pointer
> v_362f9d9108a6902af48b6c83d5377ea1;

typedef std::tuple<
  uint32_t,
  Pointer
> ac0fbd05039f742d2f1d9ac182e392ab;

typedef std::tuple<
  *src_path,
  std::string
> c404d7e7dfb3057f4a4f6b6766eeb900;

struct v_1e81caa74ae611e9cb191b8ee50bee25 : public std::variant<
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_1e81caa74ae611e9cb191b8ee50bee25 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  v_1e81caa74ae611e9cb191b8ee50bee25
> c8d851022c838ee90bc952d525c2d3aa;

struct v_8e097ae30bed5641a60541fcf38314dd : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_8e097ae30bed5641a60541fcf38314dd const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
    case 7: os << std::get<7>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  v_8e097ae30bed5641a60541fcf38314dd
> a9a5fa86cfaa17c85b3606d1a4582bcd;

struct v_8c6c9edc5b1d709b5094571801c00912 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  a9a5fa86cfaa17c85b3606d1a4582bcd,
  uint32_t,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_8c6c9edc5b1d709b5094571801c00912 const &v) {
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
  }
  return os;
}

typedef std::tuple<
  *fq_name,
  v_8c6c9edc5b1d709b5094571801c00912
> v_0fab8a04cd41fd489e58d011ef6f08ad;

struct v_5c73eec19356406029ebc971f8fc93ef : public std::variant<
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_5c73eec19356406029ebc971f8fc93ef const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  v_5c73eec19356406029ebc971f8fc93ef
> v_9a47b091ef9a7a446e50646760330664;

struct v_320dee9bcc93c7ed0c75cc7db8b85d9b : public std::variant<
  Void,
  c8d851022c838ee90bc952d525c2d3aa,
  v_0fab8a04cd41fd489e58d011ef6f08ad,
  v_9a47b091ef9a7a446e50646760330664
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_320dee9bcc93c7ed0c75cc7db8b85d9b const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
  }
  return os;
}

typedef std::tuple<
  *site_name,
  v_320dee9bcc93c7ed0c75cc7db8b85d9b
> v_26540a608fe059393cc3cd282be43df3;

struct v_60ff76b761c62e00eb6df04e7d00fbc8 : public std::variant<
  Void,
  Void,
  std::string
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_60ff76b761c62e00eb6df04e7d00fbc8 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
  }
  return os;
}

struct v_6c1c7418355e363a303990cad40945dd : public std::variant<
  std::string,
  uint32_t
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_6c1c7418355e363a303990cad40945dd const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

struct v_3a6e990115d17bf3eefa1b91b13ca80b : public std::tuple<
  *site_name,
  *fq_name,
  std::string,
  v_6c1c7418355e363a303990cad40945dd
> { using tuple::tuple; };
std::ostream &operator<<(std::ostream &os, v_3a6e990115d17bf3eefa1b91b13ca80b const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct v_90e4213e12fd850ebf8d15b08342b17e : public std::variant<
  std::string,
  v_808252496816a9c094ed1ddb199861d1
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_90e4213e12fd850ebf8d15b08342b17e const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  *sync_socket,
  v_90e4213e12fd850ebf8d15b08342b17e
> v_287d43b770d826e060b1e65a4d07e0b0;

typedef std::tuple<
  std::string,
  v_808252496816a9c094ed1ddb199861d1*
> ea82132cbdaf05c9cc56869f7b4529c3;

struct v_04c2264c7cb6c602ff22f97c6ae3e620 : public std::variant<
  std::string,
  std::string
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, v_04c2264c7cb6c602ff22f97c6ae3e620 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  v_04c2264c7cb6c602ff22f97c6ae3e620
> v_3891539b8b788ad5d369dde272200753;

struct f27b577e1bb6a9c447e7eec975daa7e7 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  Void,
  Void
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, f27b577e1bb6a9c447e7eec975daa7e7 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  f27b577e1bb6a9c447e7eec975daa7e7
> v_22ca22dbe40628ddd4edb314b5205ff3;

typedef std::tuple<
  double,
  uint32_t
> a87b3e8210a10a34a7c2070f37f91a0a;

struct e6f820d94c0e3bb8eb0c04383ff72e06 : public std::variant<
  Void,
  Void,
  Void,
  Void,
  Void,
  v_22ca22dbe40628ddd4edb314b5205ff3,
  a87b3e8210a10a34a7c2070f37f91a0a
> { using variant::variant; };
std::ostream &operator<<(std::ostream &os, e6f820d94c0e3bb8eb0c04383ff72e06 const &v) {
  switch (v.index()) {
    case 0: os << std::get<0>(v); break;
    case 1: os << std::get<1>(v); break;
    case 2: os << std::get<2>(v); break;
    case 3: os << std::get<3>(v); break;
    case 4: os << std::get<4>(v); break;
    case 5: os << std::get<5>(v); break;
    case 6: os << std::get<6>(v); break;
  }
  return os;
}

typedef std::tuple<
  std::string,
  e6f820d94c0e3bb8eb0c04383ff72e06
> ec4a56989018adc62b22d5f6798b0bc1;

struct t : public std::variant<
  Void,
  Void,
  std::string,
  c404d7e7dfb3057f4a4f6b6766eeb900,
  Void,
  v_26540a608fe059393cc3cd282be43df3,
  v_60ff76b761c62e00eb6df04e7d00fbc8,
  v_3a6e990115d17bf3eefa1b91b13ca80b,
  uint16_t,
  std::optional<*sync_socket>,
  Void,
  v_287d43b770d826e060b1e65a4d07e0b0,
  ea82132cbdaf05c9cc56869f7b4529c3,
  Void,
  v_3891539b8b788ad5d369dde272200753,
  ec4a56989018adc62b22d5f6798b0bc1
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
  }
  return os;
}

typedef std::tuple<
  t,
  Pointer
> f63f919559f0d70225bd0da5dd9bcafc;

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
  *src_path,
  Pointer
> v_630c8a213597275b9f8880113825c98a;

typedef std::tuple<
  *site_name,
  Pointer
> ddf7cb48181332ead2f60a5f4bb1a8de;

typedef std::tuple<
  v_320dee9bcc93c7ed0c75cc7db8b85d9b,
  Pointer
> e8a9e5263837de1dc85029fd46dec174;

typedef std::tuple<
  std::string,
  Pointer
> v_46a5e81c2410b000ff0adea6dc198147;

typedef std::tuple<
  v_1e81caa74ae611e9cb191b8ee50bee25,
  Pointer
> v_767414c116ccecff2dddf58db4b75b83;

typedef std::tuple<
  *fq_name,
  Pointer
> v_41ac8303016d6ac19fef26d484dd5164;

typedef std::tuple<
  v_8c6c9edc5b1d709b5094571801c00912,
  Pointer
> v_607ee10f4a91de96ce2d10309c38196b;

typedef std::tuple<
  v_8e097ae30bed5641a60541fcf38314dd,
  Pointer
> bd3c7167a3ed96b2802d09e3178bc3c5;

typedef std::tuple<
  v_60ff76b761c62e00eb6df04e7d00fbc8,
  Pointer
> f2650694962130b5d0ae4e3741f48a7a;

typedef std::tuple<
  v_6c1c7418355e363a303990cad40945dd,
  Pointer
> ac0dff677d9c1c0e84201364a0cada0d;

typedef std::tuple<
  std::optional<*sync_socket>,
  Pointer
> v_13905691a95334749d572078b5658ba9;

typedef std::tuple<
  *sync_socket,
  Pointer
> v_7036a8b0fbd8a7ca699aed2c44f6fdba;

typedef std::tuple<
  v_90e4213e12fd850ebf8d15b08342b17e,
  Pointer
> a04ac0febaa7b7d9805cb5bfd0d5cb07;

typedef std::tuple<
  v_04c2264c7cb6c602ff22f97c6ae3e620,
  Pointer
> v_07fe007441eaa3b71ce8622eb1df9609;

typedef std::tuple<
  e6f820d94c0e3bb8eb0c04383ff72e06,
  Pointer
> e3493b0d3f2be64f6703f6d7da12486c;

typedef std::tuple<
  f27b577e1bb6a9c447e7eec975daa7e7,
  Pointer
> v_1e776a020219fd0db636bac0cf181115;

typedef std::tuple<
  uint64_t,
  Pointer
> b62e103e7915a76f45f02f7c6f667c79;

typedef std::tuple<
  double,
  Pointer
> v_41a5a8cf414de9bfdc6375241fcc910a;

/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Widgets U32]" "Ptr")
      (let "ssum_dst_743" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (write-u32 little-endian (identifier "ssum_dst_743") (get-alt "Widgets" (param 0))))))
 */
static std::function<Pointer(v_808252496816a9c094ed1ddb199861d1,Pointer)> per_dash_key_to_row_binary_init()
{
  std::function<Pointer(v_808252496816a9c094ed1ddb199861d1,Pointer)> fun0 { [&fun0](v_808252496816a9c094ed1ddb199861d1 p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0.index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_743 { id_2 };
      uint16_t id_4 { uint16_t(p_0.index()) };
      uint16_t id_5 { 0 };
      bool id_6 { bool(id_4 == id_5) };
      Void id_7 { ((void)(assert(id_6)), VOID) };
      uint32_t id_8 { std::get<0>(p_0) };
      Pointer id_9 { ssum_dst_743.writeU32Le(id_8) };
      let_res_3 = id_9;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(v_808252496816a9c094ed1ddb199861d1,Pointer)> per_dash_key_to_row_binary(per_dash_key_to_row_binary_init());

/* 
    (fun ("[Widgets U32]") (seq (assert (eq (label-of (param 0)) (u16 0))) (size 6)))
 */
static std::function<Size(v_808252496816a9c094ed1ddb199861d1)> per_dash_key_sersize_of_row_binary_init()
{
  std::function<Size(v_808252496816a9c094ed1ddb199861d1)> fun10 { [&fun10](v_808252496816a9c094ed1ddb199861d1 p_0) {
    uint16_t id_11 { uint16_t(p_0.index()) };
    uint16_t id_12 { 0 };
    bool id_13 { bool(id_11 == id_12) };
    Void id_14 { ((void)(assert(id_13)), VOID) };
    Size id_15 { 6UL };
    return id_15;
  }
   };
  return fun10;
}
std::function<Size(v_808252496816a9c094ed1ddb199861d1)> per_dash_key_sersize_of_row_binary(per_dash_key_sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
        (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
          (seq (assert (eq (identifier "dsum1_fst_63") (u16 0)))
            (let-pair "du32_fst_66" "du32_snd_67" (read-u32 little-endian (identifier "dsum1_snd_64")) (make-tup (construct "[Widgets U32]" 0 (identifier "du32_fst_66")) (identifier "du32_snd_67")))))))
 */
static std::function<bb7a1af56c56ee3850e41d7e7bbfd8d3(Pointer)> per_dash_key_of_row_binary_init()
{
  std::function<bb7a1af56c56ee3850e41d7e7bbfd8d3(Pointer)> fun16 { [&fun16](Pointer p_0) {
    v_362f9d9108a6902af48b6c83d5377ea1 id_17 { p_0.readU16Le() };
    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_18;
    {
      auto du16_fst_57 { std::get<0>(id_17) };
      auto du16_snd_58 { std::get<1>(id_17) };
      v_362f9d9108a6902af48b6c83d5377ea1 id_19 {  du16_fst_57, du16_snd_58  };
      letpair_res_18 = id_19;
    }
    bb7a1af56c56ee3850e41d7e7bbfd8d3 let_res_20;
    {
      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_62 { letpair_res_18 };
      bb7a1af56c56ee3850e41d7e7bbfd8d3 letpair_res_21;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_22 { 0 };
        bool id_23 { bool(dsum1_fst_63 == id_22) };
        Void id_24 { ((void)(assert(id_23)), VOID) };
        ac0fbd05039f742d2f1d9ac182e392ab id_25 { dsum1_snd_64.readU32Le() };
        bb7a1af56c56ee3850e41d7e7bbfd8d3 letpair_res_26;
        {
          auto du32_fst_66 { std::get<0>(id_25) };
          auto du32_snd_67 { std::get<1>(id_25) };
          v_808252496816a9c094ed1ddb199861d1 id_27 { std::in_place_index<0>, du32_fst_66 };
          bb7a1af56c56ee3850e41d7e7bbfd8d3 id_28 {  id_27, du32_snd_67  };
          letpair_res_26 = id_28;
        }
        letpair_res_21 = letpair_res_26;
      }
      let_res_20 = letpair_res_21;
    }
    return let_res_20;
  }
   };
  return fun16;
}
std::function<bb7a1af56c56ee3850e41d7e7bbfd8d3(Pointer)> per_dash_key_of_row_binary(per_dash_key_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_654" "make_snd_655"
        (let "dsum1_80" (let-pair "du16_fst_75" "du16_snd_76" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_75") (identifier "du16_snd_76")))
          (let-pair "dsum1_fst_81" "dsum1_snd_82" (identifier "dsum1_80")
            (if (eq (u16 0) (identifier "dsum1_fst_81"))
              (make-tup
                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 0
                  (nop)) (identifier "dsum1_snd_82"))
              (if (eq (u16 1) (identifier "dsum1_fst_81"))
                (make-tup
                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 1
                    (nop)) (identifier "dsum1_snd_82"))
                (if (eq (u16 2) (identifier "dsum1_fst_81"))
                  (let "dstring1_638"
                    (let "leb_ref_632" (make-vec (u32 0))
                      (let "shft_ref_633" (make-vec (u8 0))
                        (let "p_ref_634" (make-vec (identifier "dsum1_snd_82"))
                          (seq
                            (while
                              (let "leb128_635" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_634")))
                                (let-pair "leb128_fst_636" "leb128_snd_637" 
                                  (identifier "leb128_635")
                                  (seq (set-vec (u8 0) (identifier "p_ref_634") (identifier "leb128_snd_637"))
                                    (set-vec (u8 0) (identifier "leb_ref_632")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_636") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_633"))) (unsafe-nth (u8 0) (identifier "leb_ref_632"))))
                                    (set-vec (u8 0) (identifier "shft_ref_633") (add (unsafe-nth (u8 0) (identifier "shft_ref_633")) (u8 7))) 
                                    (ge (identifier "leb128_fst_636") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_632"))) (unsafe-nth (u8 0) (identifier "p_ref_634")))))))
                    (let-pair "dstring1_fst_639" "dstring1_snd_640" (identifier "dstring1_638")
                      (let-pair "dstring2_fst_642" "dstring2_snd_643" 
                        (read-bytes (identifier "dstring1_snd_640") (identifier "dstring1_fst_639"))
                        (make-tup
                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 2
                            (string-of-bytes (identifier "dstring2_fst_642"))) 
                          (identifier "dstring2_snd_643")))))
                  (if (eq (u16 3) (identifier "dsum1_fst_81"))
                    (let "dtup_611" (apply (ext-identifier src_path of-row-binary) (identifier "dsum1_snd_82"))
                      (let-pair "dtup_fst_612" "dtup_snd_613" (identifier "dtup_611")
                        (let "dstring1_620"
                          (let "leb_ref_614" (make-vec (u32 0))
                            (let "shft_ref_615" (make-vec (u8 0))
                              (let "p_ref_616" (make-vec (identifier "dtup_snd_613"))
                                (seq
                                  (while
                                    (let "leb128_617" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_616")))
                                      (let-pair "leb128_fst_618" "leb128_snd_619" 
                                        (identifier "leb128_617")
                                        (seq (set-vec (u8 0) (identifier "p_ref_616") (identifier "leb128_snd_619"))
                                          (set-vec (u8 0) (identifier "leb_ref_614")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_618") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_615"))) (unsafe-nth (u8 0) (identifier "leb_ref_614"))))
                                          (set-vec (u8 0) (identifier "shft_ref_615") (add (unsafe-nth (u8 0) (identifier "shft_ref_615")) (u8 7))) 
                                          (ge (identifier "leb128_fst_618") (u8 128))))) 
                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_614"))) (unsafe-nth (u8 0) (identifier "p_ref_616")))))))
                          (let-pair "dstring1_fst_621" "dstring1_snd_622" 
                            (identifier "dstring1_620")
                            (let-pair "dstring2_fst_624" "dstring2_snd_625" 
                              (read-bytes (identifier "dstring1_snd_622") (identifier "dstring1_fst_621"))
                              (make-tup
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 3
                                  (make-tup (identifier "dtup_fst_612") (string-of-bytes (identifier "dstring2_fst_624")))) 
                                (identifier "dstring2_snd_625")))))))
                    (if (eq (u16 4) (identifier "dsum1_fst_81"))
                      (make-tup
                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 4
                          (nop)) (identifier "dsum1_snd_82"))
                      (if (eq (u16 5) (identifier "dsum1_fst_81"))
                        (let "dtup_419" (apply (ext-identifier site_name of-row-binary) (identifier "dsum1_snd_82"))
                          (let-pair "dtup_fst_420" "dtup_snd_421" (identifier "dtup_419")
                            (let-pair "dtup_fst_603" "dtup_snd_604"
                              (let "dsum1_428" (let-pair "du16_fst_423" "du16_snd_424" (read-u16 little-endian (identifier "dtup_snd_421")) (make-tup (identifier "du16_fst_423") (identifier "du16_snd_424")))
                                (let-pair "dsum1_fst_429" "dsum1_snd_430" 
                                  (identifier "dsum1_428")
                                  (if (eq (u16 0) (identifier "dsum1_fst_429"))
                                    (make-tup
                                      (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 0
                                        (nop)) (identifier "dsum1_snd_430"))
                                    (if (eq (u16 1) (identifier "dsum1_fst_429"))
                                      (let "dtup_575"
                                        (let "dstring1_569"
                                          (let "leb_ref_563" (make-vec (u32 0))
                                            (let "shft_ref_564" (make-vec (u8 0))
                                              (let "p_ref_565" (make-vec (identifier "dsum1_snd_430"))
                                                (seq
                                                  (while
                                                    (let "leb128_566" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_565")))
                                                      (let-pair "leb128_fst_567" "leb128_snd_568" 
                                                        (identifier "leb128_566")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_565") (identifier "leb128_snd_568"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_563")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_567") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_564")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_563")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_564") (add (unsafe-nth (u8 0) (identifier "shft_ref_564")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_567") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_563"))) (unsafe-nth (u8 0) (identifier "p_ref_565")))))))
                                          (let-pair "dstring1_fst_570" "dstring1_snd_571" 
                                            (identifier "dstring1_569")
                                            (let-pair "dstring2_fst_573" "dstring2_snd_574" 
                                              (read-bytes (identifier "dstring1_snd_571") (identifier "dstring1_fst_570")) 
                                              (make-tup (string-of-bytes (identifier "dstring2_fst_573")) (identifier "dstring2_snd_574")))))
                                        (let-pair "dtup_fst_576" "dtup_snd_577" 
                                          (identifier "dtup_575")
                                          (let-pair "dtup_fst_594" "dtup_snd_595"
                                            (let "dsum1_584" (let-pair "du16_fst_579" "du16_snd_580" (read-u16 little-endian (identifier "dtup_snd_577")) (make-tup (identifier "du16_fst_579") (identifier "du16_snd_580")))
                                              (let-pair "dsum1_fst_585" "dsum1_snd_586" 
                                                (identifier "dsum1_584")
                                                (if (eq (u16 0) (identifier "dsum1_fst_585")) 
                                                  (make-tup (construct "[Host Void | Port Void]" 0 (nop)) (identifier "dsum1_snd_586"))
                                                  (seq (assert (eq (identifier "dsum1_fst_585") (u16 1))) (make-tup (construct "[Host Void | Port Void]" 1 (nop)) (identifier "dsum1_snd_586"))))))
                                            (make-tup
                                              (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 1
                                                (make-tup (identifier "dtup_fst_576") (identifier "dtup_fst_594"))) 
                                              (identifier "dtup_snd_595")))))
                                      (if (eq (u16 2) (identifier "dsum1_fst_429"))
                                        (let "dtup_464" (apply (ext-identifier fq_name of-row-binary) (identifier "dsum1_snd_430"))
                                          (let-pair "dtup_fst_465" "dtup_snd_466" 
                                            (identifier "dtup_464")
                                            (let-pair "dtup_fst_558" "dtup_snd_559"
                                              (let "dsum1_473" (let-pair "du16_fst_468" "du16_snd_469" (read-u16 little-endian (identifier "dtup_snd_466")) (make-tup (identifier "du16_fst_468") (identifier "du16_snd_469")))
                                                (let-pair "dsum1_fst_474" "dsum1_snd_475" 
                                                  (identifier "dsum1_473")
                                                  (if (eq (u16 0) (identifier "dsum1_fst_474"))
                                                    (make-tup
                                                      (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 0
                                                        (nop)) (identifier "dsum1_snd_475"))
                                                    (if (eq (u16 1) (identifier "dsum1_fst_474"))
                                                      (make-tup
                                                        (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 1
                                                          (nop)) (identifier "dsum1_snd_475"))
                                                      (if (eq (u16 2) (identifier "dsum1_fst_474"))
                                                        (make-tup
                                                          (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 2
                                                            (nop)) (identifier "dsum1_snd_475"))
                                                        (if (eq (u16 3) (identifier "dsum1_fst_474"))
                                                          (make-tup
                                                            (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 3
                                                              (nop)) 
                                                            (identifier "dsum1_snd_475"))
                                                          (if (eq (u16 4) (identifier "dsum1_fst_474"))
                                                            (make-tup
                                                              (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 4
                                                                (nop)) 
                                                              (identifier "dsum1_snd_475"))
                                                            (if (eq (u16 5) (identifier "dsum1_fst_474"))
                                                              (make-tup
                                                                (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 5
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_475"))
                                                              (if (eq (u16 6) (identifier "dsum1_fst_474"))
                                                                (let "dtup_497"
                                                                  (let "dstring1_491"
                                                                    (let "leb_ref_485" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_486" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_487" 
                                                                    (make-vec (identifier "dsum1_snd_475"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_488" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_487")))
                                                                    (let-pair "leb128_fst_489" "leb128_snd_490" 
                                                                    (identifier "leb128_488")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_487") (identifier "leb128_snd_490"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_485")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_489") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_486")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_485")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_486") (add (unsafe-nth (u8 0) (identifier "shft_ref_486")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_489") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_485"))) (unsafe-nth (u8 0) (identifier "p_ref_487")))))))
                                                                    (let-pair "dstring1_fst_492" "dstring1_snd_493" 
                                                                    (identifier "dstring1_491")
                                                                    (let-pair "dstring2_fst_495" "dstring2_snd_496" 
                                                                    (read-bytes (identifier "dstring1_snd_493") (identifier "dstring1_fst_492"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_495")) (identifier "dstring2_snd_496")))))
                                                                  (let-pair "dtup_fst_498" "dtup_snd_499" 
                                                                    (identifier "dtup_497")
                                                                    (let-pair "dtup_fst_534" "dtup_snd_535"
                                                                    (let "dsum1_506"
                                                                    (let-pair "du16_fst_501" "du16_snd_502" (read-u16 little-endian (identifier "dtup_snd_499")) (make-tup (identifier "du16_fst_501") (identifier "du16_snd_502")))
                                                                    (let-pair "dsum1_fst_507" "dsum1_snd_508" 
                                                                    (identifier "dsum1_506")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_507"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 0
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_508"))
                                                                    (if 
                                                                    (eq (u16 1) (identifier "dsum1_fst_507"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 1
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_508"))
                                                                    (if 
                                                                    (eq (u16 2) (identifier "dsum1_fst_507"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 2
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_508"))
                                                                    (if 
                                                                    (eq (u16 3) (identifier "dsum1_fst_507"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 3
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_508"))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "dsum1_fst_507"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 4
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_508"))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "dsum1_fst_507"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 5
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_508"))
                                                                    (if 
                                                                    (eq (u16 6) (identifier "dsum1_fst_507"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 6
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_508"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_507") (u16 7)))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 7
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_508"))))))))))))
                                                                    (make-tup
                                                                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 6
                                                                    (make-tup (identifier "dtup_fst_498") (identifier "dtup_fst_534"))) 
                                                                    (identifier "dtup_snd_535")))))
                                                                (if (eq (u16 7) (identifier "dsum1_fst_474"))
                                                                  (let-pair "du32_fst_480" "du32_snd_481" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_475"))
                                                                    (make-tup
                                                                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 7
                                                                    (identifier "du32_fst_480")) 
                                                                    (identifier "du32_snd_481")))
                                                                  (seq 
                                                                    (assert (eq (identifier "dsum1_fst_474") (u16 8)))
                                                                    (make-tup
                                                                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 8
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_475")))))))))))))
                                              (make-tup
                                                (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 2
                                                  (make-tup (identifier "dtup_fst_465") (identifier "dtup_fst_558"))) 
                                                (identifier "dtup_snd_559")))))
                                        (seq (assert (eq (identifier "dsum1_fst_429") (u16 3)))
                                          (let "dtup_443"
                                            (let "dstring1_437"
                                              (let "leb_ref_431" (make-vec (u32 0))
                                                (let "shft_ref_432" (make-vec (u8 0))
                                                  (let "p_ref_433" (make-vec (identifier "dsum1_snd_430"))
                                                    (seq
                                                      (while
                                                        (let "leb128_434" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_433")))
                                                          (let-pair "leb128_fst_435" "leb128_snd_436" 
                                                            (identifier "leb128_434")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_433") (identifier "leb128_snd_436"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_431")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_435") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_432")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_431")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_432") (add (unsafe-nth (u8 0) (identifier "shft_ref_432")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_435") (u8 128))))) 
                                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_431"))) (unsafe-nth (u8 0) (identifier "p_ref_433")))))))
                                              (let-pair "dstring1_fst_438" "dstring1_snd_439" 
                                                (identifier "dstring1_437")
                                                (let-pair "dstring2_fst_441" "dstring2_snd_442" 
                                                  (read-bytes (identifier "dstring1_snd_439") (identifier "dstring1_fst_438")) 
                                                  (make-tup (string-of-bytes (identifier "dstring2_fst_441")) (identifier "dstring2_snd_442")))))
                                            (let-pair "dtup_fst_444" "dtup_snd_445" 
                                              (identifier "dtup_443")
                                              (let "dsum1_452" (let-pair "du16_fst_447" "du16_snd_448" (read-u16 little-endian (identifier "dtup_snd_445")) (make-tup (identifier "du16_fst_447") (identifier "du16_snd_448")))
                                                (let-pair "dsum1_fst_453" "dsum1_snd_454" 
                                                  (identifier "dsum1_452")
                                                  (seq (assert (eq (identifier "dsum1_fst_453") (u16 0)))
                                                    (make-tup
                                                      (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 3
                                                        (make-tup (identifier "dtup_fst_444") (construct "[Executable Void]" 0 (nop)))) 
                                                      (identifier "dsum1_snd_454")))))))))))))
                              (make-tup
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 5
                                  (make-tup (identifier "dtup_fst_420") (identifier "dtup_fst_603"))) 
                                (identifier "dtup_snd_604")))))
                        (if (eq (u16 6) (identifier "dsum1_fst_81"))
                          (let-pair "dsum2_fst_417" "dsum2_snd_418"
                            (let "dsum1_392" (let-pair "du16_fst_387" "du16_snd_388" (read-u16 little-endian (identifier "dsum1_snd_82")) (make-tup (identifier "du16_fst_387") (identifier "du16_snd_388")))
                              (let-pair "dsum1_fst_393" "dsum1_snd_394" 
                                (identifier "dsum1_392")
                                (if (eq (u16 0) (identifier "dsum1_fst_393")) 
                                  (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 0 (nop)) (identifier "dsum1_snd_394"))
                                  (if (eq (u16 1) (identifier "dsum1_fst_393")) 
                                    (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 1 (nop)) (identifier "dsum1_snd_394"))
                                    (seq (assert (eq (identifier "dsum1_fst_393") (u16 2)))
                                      (let "dstring1_401"
                                        (let "leb_ref_395" (make-vec (u32 0))
                                          (let "shft_ref_396" (make-vec (u8 0))
                                            (let "p_ref_397" (make-vec (identifier "dsum1_snd_394"))
                                              (seq
                                                (while
                                                  (let "leb128_398" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_397")))
                                                    (let-pair "leb128_fst_399" "leb128_snd_400" 
                                                      (identifier "leb128_398")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_397") (identifier "leb128_snd_400"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_395")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_399") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_396")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_395")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_396") (add (unsafe-nth (u8 0) (identifier "shft_ref_396")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_399") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_395"))) (unsafe-nth (u8 0) (identifier "p_ref_397")))))))
                                        (let-pair "dstring1_fst_402" "dstring1_snd_403" 
                                          (identifier "dstring1_401")
                                          (let-pair "dstring2_fst_405" "dstring2_snd_406" 
                                            (read-bytes (identifier "dstring1_snd_403") (identifier "dstring1_fst_402"))
                                            (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 2 (string-of-bytes (identifier "dstring2_fst_405"))) (identifier "dstring2_snd_406"))))))))))
                            (make-tup
                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 6
                                (identifier "dsum2_fst_417")) (identifier "dsum2_snd_418")))
                          (if (eq (u16 7) (identifier "dsum1_fst_81"))
                            (let "dtup_329" (apply (ext-identifier site_name of-row-binary) (identifier "dsum1_snd_82"))
                              (let-pair "dtup_fst_330" "dtup_snd_331" 
                                (identifier "dtup_329")
                                (let "dtup_332" (apply (ext-identifier fq_name of-row-binary) (identifier "dtup_snd_331"))
                                  (let-pair "dtup_fst_333" "dtup_snd_334" 
                                    (identifier "dtup_332")
                                    (let "dtup_347"
                                      (let "dstring1_341"
                                        (let "leb_ref_335" (make-vec (u32 0))
                                          (let "shft_ref_336" (make-vec (u8 0))
                                            (let "p_ref_337" (make-vec (identifier "dtup_snd_334"))
                                              (seq
                                                (while
                                                  (let "leb128_338" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_337")))
                                                    (let-pair "leb128_fst_339" "leb128_snd_340" 
                                                      (identifier "leb128_338")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_337") (identifier "leb128_snd_340"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_335")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_339") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_336")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_335")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_336") (add (unsafe-nth (u8 0) (identifier "shft_ref_336")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_339") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_335"))) (unsafe-nth (u8 0) (identifier "p_ref_337")))))))
                                        (let-pair "dstring1_fst_342" "dstring1_snd_343" 
                                          (identifier "dstring1_341")
                                          (let-pair "dstring2_fst_345" "dstring2_snd_346" 
                                            (read-bytes (identifier "dstring1_snd_343") (identifier "dstring1_fst_342")) 
                                            (make-tup (string-of-bytes (identifier "dstring2_fst_345")) (identifier "dstring2_snd_346")))))
                                      (let-pair "dtup_fst_348" "dtup_snd_349" 
                                        (identifier "dtup_347")
                                        (let-pair "dtup_fst_381" "dtup_snd_382"
                                          (let "dsum1_356" (let-pair "du16_fst_351" "du16_snd_352" (read-u16 little-endian (identifier "dtup_snd_349")) (make-tup (identifier "du16_fst_351") (identifier "du16_snd_352")))
                                            (let-pair "dsum1_fst_357" "dsum1_snd_358" 
                                              (identifier "dsum1_356")
                                              (if (eq (u16 0) (identifier "dsum1_fst_357"))
                                                (let "dstring1_371"
                                                  (let "leb_ref_365" 
                                                    (make-vec (u32 0))
                                                    (let "shft_ref_366" 
                                                      (make-vec (u8 0))
                                                      (let "p_ref_367" 
                                                        (make-vec (identifier "dsum1_snd_358"))
                                                        (seq
                                                          (while
                                                            (let "leb128_368" 
                                                              (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_367")))
                                                              (let-pair "leb128_fst_369" "leb128_snd_370" 
                                                                (identifier "leb128_368")
                                                                (seq 
                                                                  (set-vec (u8 0) (identifier "p_ref_367") (identifier "leb128_snd_370"))
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_365")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_369") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_366")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_365")))) 
                                                                  (set-vec (u8 0) (identifier "shft_ref_366") (add (unsafe-nth (u8 0) (identifier "shft_ref_366")) (u8 7))) 
                                                                  (ge (identifier "leb128_fst_369") (u8 128))))) 
                                                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_365"))) (unsafe-nth (u8 0) (identifier "p_ref_367")))))))
                                                  (let-pair "dstring1_fst_372" "dstring1_snd_373" 
                                                    (identifier "dstring1_371")
                                                    (let-pair "dstring2_fst_375" "dstring2_snd_376" 
                                                      (read-bytes (identifier "dstring1_snd_373") (identifier "dstring1_fst_372"))
                                                      (make-tup (construct "[Subscriber STRING | LastTuple U32]" 0 (string-of-bytes (identifier "dstring2_fst_375"))) (identifier "dstring2_snd_376")))))
                                                (seq (assert (eq (identifier "dsum1_fst_357") (u16 1)))
                                                  (let-pair "du32_fst_360" "du32_snd_361" 
                                                    (read-u32 little-endian (identifier "dsum1_snd_358")) 
                                                    (make-tup (construct "[Subscriber STRING | LastTuple U32]" 1 (identifier "du32_fst_360")) (identifier "du32_snd_361")))))))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 7
                                              (make-tup (identifier "dtup_fst_330") (identifier "dtup_fst_333") (identifier "dtup_fst_348") (identifier "dtup_fst_381"))) 
                                            (identifier "dtup_snd_382")))))))))
                            (if (eq (u16 8) (identifier "dsum1_fst_81"))
                              (let-pair "du16_fst_324" "du16_snd_325" 
                                (read-u16 little-endian (identifier "dsum1_snd_82"))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 8
                                    (identifier "du16_fst_324")) (identifier "du16_snd_325")))
                              (if (eq (u16 9) (identifier "dsum1_fst_81"))
                                (let-pair "dsum2_fst_321" "dsum2_snd_322"
                                  (if (eq (peek-u8 (identifier "dsum1_snd_82") (size 0)) (u8 1)) 
                                    (make-tup (null "$sync_socket") (ptr-add (identifier "dsum1_snd_82") (size 1)))
                                    (let-pair "make1_1_fst_318" "make1_1_snd_319" 
                                      (apply (ext-identifier sync_socket of-row-binary) (ptr-add (identifier "dsum1_snd_82") (size 1))) 
                                      (make-tup (not-null (identifier "make1_1_fst_318")) (identifier "make1_1_snd_319"))))
                                  (make-tup
                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 9
                                      (identifier "dsum2_fst_321")) (identifier "dsum2_snd_322")))
                                (if (eq (u16 10) (identifier "dsum1_fst_81"))
                                  (make-tup
                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 10
                                      (nop)) (identifier "dsum1_snd_82"))
                                  (if (eq (u16 11) (identifier "dsum1_fst_81"))
                                    (let "dtup_278" (apply (ext-identifier sync_socket of-row-binary) (identifier "dsum1_snd_82"))
                                      (let-pair "dtup_fst_279" "dtup_snd_280" 
                                        (identifier "dtup_278")
                                        (let-pair "dtup_fst_309" "dtup_snd_310"
                                          (let "dsum1_287" (let-pair "du16_fst_282" "du16_snd_283" (read-u16 little-endian (identifier "dtup_snd_280")) (make-tup (identifier "du16_fst_282") (identifier "du16_snd_283")))
                                            (let-pair "dsum1_fst_288" "dsum1_snd_289" 
                                              (identifier "dsum1_287")
                                              (if (eq (u16 0) (identifier "dsum1_fst_288"))
                                                (let "dstring1_299"
                                                  (let "leb_ref_293" 
                                                    (make-vec (u32 0))
                                                    (let "shft_ref_294" 
                                                      (make-vec (u8 0))
                                                      (let "p_ref_295" 
                                                        (make-vec (identifier "dsum1_snd_289"))
                                                        (seq
                                                          (while
                                                            (let "leb128_296" 
                                                              (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_295")))
                                                              (let-pair "leb128_fst_297" "leb128_snd_298" 
                                                                (identifier "leb128_296")
                                                                (seq 
                                                                  (set-vec (u8 0) (identifier "p_ref_295") (identifier "leb128_snd_298"))
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_293")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_297") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_294")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_293")))) 
                                                                  (set-vec (u8 0) (identifier "shft_ref_294") (add (unsafe-nth (u8 0) (identifier "shft_ref_294")) (u8 7))) 
                                                                  (ge (identifier "leb128_fst_297") (u8 128))))) 
                                                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_293"))) (unsafe-nth (u8 0) (identifier "p_ref_295")))))))
                                                  (let-pair "dstring1_fst_300" "dstring1_snd_301" 
                                                    (identifier "dstring1_299")
                                                    (let-pair "dstring2_fst_303" "dstring2_snd_304" 
                                                      (read-bytes (identifier "dstring1_snd_301") (identifier "dstring1_fst_300"))
                                                      (make-tup (construct "[Response STRING | Scratchpad per_dash_key AS [Widgets U32]]" 0 (string-of-bytes (identifier "dstring2_fst_303"))) (identifier "dstring2_snd_304")))))
                                                (seq (assert (eq (identifier "dsum1_fst_288") (u16 1)))
                                                  (let-pair "dsum2_fst_291" "dsum2_snd_292" 
                                                    (apply (identifier "per_dash_key-of-row-binary") (identifier "dsum1_snd_289"))
                                                    (make-tup (construct "[Response STRING | Scratchpad per_dash_key AS [Widgets U32]]" 1 (identifier "dsum2_fst_291")) (identifier "dsum2_snd_292")))))))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 11
                                              (make-tup (identifier "dtup_fst_279") (identifier "dtup_fst_309"))) 
                                            (identifier "dtup_snd_310")))))
                                    (if (eq (u16 12) (identifier "dsum1_fst_81"))
                                      (let "dtup_269"
                                        (let "dstring1_263"
                                          (let "leb_ref_257" (make-vec (u32 0))
                                            (let "shft_ref_258" (make-vec (u8 0))
                                              (let "p_ref_259" (make-vec (identifier "dsum1_snd_82"))
                                                (seq
                                                  (while
                                                    (let "leb128_260" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_259")))
                                                      (let-pair "leb128_fst_261" "leb128_snd_262" 
                                                        (identifier "leb128_260")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_259") (identifier "leb128_snd_262"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_257")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_261") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_258")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_257")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_258") (add (unsafe-nth (u8 0) (identifier "shft_ref_258")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_261") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_257"))) (unsafe-nth (u8 0) (identifier "p_ref_259")))))))
                                          (let-pair "dstring1_fst_264" "dstring1_snd_265" 
                                            (identifier "dstring1_263")
                                            (let-pair "dstring2_fst_267" "dstring2_snd_268" 
                                              (read-bytes (identifier "dstring1_snd_265") (identifier "dstring1_fst_264")) 
                                              (make-tup (string-of-bytes (identifier "dstring2_fst_267")) (identifier "dstring2_snd_268")))))
                                        (let-pair "dtup_fst_270" "dtup_snd_271" 
                                          (identifier "dtup_269")
                                          (let-pair "dtup_fst_273" "dtup_snd_274" 
                                            (apply (identifier "per_dash_key-of-row-binary") (identifier "dtup_snd_271"))
                                            (make-tup
                                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 12
                                                (make-tup (identifier "dtup_fst_270") (identifier "dtup_fst_273"))) 
                                              (identifier "dtup_snd_274")))))
                                      (if (eq (u16 13) (identifier "dsum1_fst_81"))
                                        (make-tup
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 13
                                            (nop)) (identifier "dsum1_snd_82"))
                                        (if (eq (u16 14) (identifier "dsum1_fst_81"))
                                          (let "dtup_206"
                                            (let "dstring1_200"
                                              (let "leb_ref_194" (make-vec (u32 0))
                                                (let "shft_ref_195" (make-vec (u8 0))
                                                  (let "p_ref_196" (make-vec (identifier "dsum1_snd_82"))
                                                    (seq
                                                      (while
                                                        (let "leb128_197" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_196")))
                                                          (let-pair "leb128_fst_198" "leb128_snd_199" 
                                                            (identifier "leb128_197")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_196") (identifier "leb128_snd_199"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_194")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_198") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_195")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_194")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_195") (add (unsafe-nth (u8 0) (identifier "shft_ref_195")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_198") (u8 128))))) 
                                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_194"))) (unsafe-nth (u8 0) (identifier "p_ref_196")))))))
                                              (let-pair "dstring1_fst_201" "dstring1_snd_202" 
                                                (identifier "dstring1_200")
                                                (let-pair "dstring2_fst_204" "dstring2_snd_205" 
                                                  (read-bytes (identifier "dstring1_snd_202") (identifier "dstring1_fst_201")) 
                                                  (make-tup (string-of-bytes (identifier "dstring2_fst_204")) (identifier "dstring2_snd_205")))))
                                            (let-pair "dtup_fst_207" "dtup_snd_208" 
                                              (identifier "dtup_206")
                                              (let-pair "dtup_fst_249" "dtup_snd_250"
                                                (let "dsum1_215" (let-pair "du16_fst_210" "du16_snd_211" (read-u16 little-endian (identifier "dtup_snd_208")) (make-tup (identifier "du16_fst_210") (identifier "du16_snd_211")))
                                                  (let-pair "dsum1_fst_216" "dsum1_snd_217" 
                                                    (identifier "dsum1_215")
                                                    (if (eq (u16 0) (identifier "dsum1_fst_216"))
                                                      (let "dstring1_239"
                                                        (let "leb_ref_233" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_234" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_235" 
                                                              (make-vec (identifier "dsum1_snd_217"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_236" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_235")))
                                                                    (let-pair "leb128_fst_237" "leb128_snd_238" 
                                                                    (identifier "leb128_236")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_235") (identifier "leb128_snd_238"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_233")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_237") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_234")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_233")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_234") (add (unsafe-nth (u8 0) (identifier "shft_ref_234")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_237") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_233"))) (unsafe-nth (u8 0) (identifier "p_ref_235")))))))
                                                        (let-pair "dstring1_fst_240" "dstring1_snd_241" 
                                                          (identifier "dstring1_239")
                                                          (let-pair "dstring2_fst_243" "dstring2_snd_244" 
                                                            (read-bytes (identifier "dstring1_snd_241") (identifier "dstring1_fst_240"))
                                                            (make-tup (construct "[Contacts STRING | Inhibition STRING]" 0 (string-of-bytes (identifier "dstring2_fst_243"))) (identifier "dstring2_snd_244")))))
                                                      (seq (assert (eq (identifier "dsum1_fst_216") (u16 1)))
                                                        (let "dstring1_224"
                                                          (let "leb_ref_218" 
                                                            (make-vec (u32 0))
                                                            (let "shft_ref_219" 
                                                              (make-vec (u8 0))
                                                              (let "p_ref_220" 
                                                                (make-vec (identifier "dsum1_snd_217"))
                                                                (seq
                                                                  (while
                                                                    (let "leb128_221" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_220")))
                                                                    (let-pair "leb128_fst_222" "leb128_snd_223" 
                                                                    (identifier "leb128_221")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_220") (identifier "leb128_snd_223"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_218")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_222") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_219")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_218")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_219") (add (unsafe-nth (u8 0) (identifier "shft_ref_219")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_222") (u8 128))))) 
                                                                    (nop)) 
                                                                  (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_218"))) (unsafe-nth (u8 0) (identifier "p_ref_220")))))))
                                                          (let-pair "dstring1_fst_225" "dstring1_snd_226" 
                                                            (identifier "dstring1_224")
                                                            (let-pair "dstring2_fst_228" "dstring2_snd_229" 
                                                              (read-bytes (identifier "dstring1_snd_226") (identifier "dstring1_fst_225"))
                                                              (make-tup (construct "[Contacts STRING | Inhibition STRING]" 1 (string-of-bytes (identifier "dstring2_fst_228"))) (identifier "dstring2_snd_229")))))))))
                                                (make-tup
                                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 14
                                                    (make-tup (identifier "dtup_fst_207") (identifier "dtup_fst_249"))) 
                                                  (identifier "dtup_snd_250")))))
                                          (seq (assert (eq (identifier "dsum1_fst_81") (u16 15)))
                                            (let "dtup_95"
                                              (let "dstring1_89"
                                                (let "leb_ref_83" (make-vec (u32 0))
                                                  (let "shft_ref_84" 
                                                    (make-vec (u8 0))
                                                    (let "p_ref_85" (make-vec (identifier "dsum1_snd_82"))
                                                      (seq
                                                        (while
                                                          (let "leb128_86" 
                                                            (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_85")))
                                                            (let-pair "leb128_fst_87" "leb128_snd_88" 
                                                              (identifier "leb128_86")
                                                              (seq (set-vec (u8 0) (identifier "p_ref_85") (identifier "leb128_snd_88"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_83")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_87") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_84")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_83")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_84") (add (unsafe-nth (u8 0) (identifier "shft_ref_84")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_87") (u8 128))))) 
                                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_83"))) (unsafe-nth (u8 0) (identifier "p_ref_85")))))))
                                                (let-pair "dstring1_fst_90" "dstring1_snd_91" 
                                                  (identifier "dstring1_89")
                                                  (let-pair "dstring2_fst_93" "dstring2_snd_94" 
                                                    (read-bytes (identifier "dstring1_snd_91") (identifier "dstring1_fst_90")) 
                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_93")) (identifier "dstring2_snd_94")))))
                                              (let-pair "dtup_fst_96" "dtup_snd_97" 
                                                (identifier "dtup_95")
                                                (let-pair "dtup_fst_189" "dtup_snd_190"
                                                  (let "dsum1_104" (let-pair "du16_fst_99" "du16_snd_100" (read-u16 little-endian (identifier "dtup_snd_97")) (make-tup (identifier "du16_fst_99") (identifier "du16_snd_100")))
                                                    (let-pair "dsum1_fst_105" "dsum1_snd_106" 
                                                      (identifier "dsum1_104")
                                                      (if (eq (u16 0) (identifier "dsum1_fst_105"))
                                                        (make-tup
                                                          (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 0
                                                            (nop)) (identifier "dsum1_snd_106"))
                                                        (if (eq (u16 1) (identifier "dsum1_fst_105"))
                                                          (make-tup
                                                            (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 1
                                                              (nop)) 
                                                            (identifier "dsum1_snd_106"))
                                                          (if (eq (u16 2) (identifier "dsum1_fst_105"))
                                                            (make-tup
                                                              (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 2
                                                                (nop)) 
                                                              (identifier "dsum1_snd_106"))
                                                            (if (eq (u16 3) (identifier "dsum1_fst_105"))
                                                              (make-tup
                                                                (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 3
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_106"))
                                                              (if (eq (u16 4) (identifier "dsum1_fst_105"))
                                                                (make-tup
                                                                  (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 4
                                                                    (nop)) 
                                                                  (identifier "dsum1_snd_106"))
                                                                (if (eq (u16 5) (identifier "dsum1_fst_105"))
                                                                  (let "dtup_134"
                                                                    (let "dstring1_128"
                                                                    (let "leb_ref_122" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_123" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_124" 
                                                                    (make-vec (identifier "dsum1_snd_106"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_125" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_124")))
                                                                    (let-pair "leb128_fst_126" "leb128_snd_127" 
                                                                    (identifier "leb128_125")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_124") (identifier "leb128_snd_127"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_122")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_126") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_123")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_122")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_123") (add (unsafe-nth (u8 0) (identifier "shft_ref_123")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_126") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_122"))) (unsafe-nth (u8 0) (identifier "p_ref_124")))))))
                                                                    (let-pair "dstring1_fst_129" "dstring1_snd_130" 
                                                                    (identifier "dstring1_128")
                                                                    (let-pair "dstring2_fst_132" "dstring2_snd_133" 
                                                                    (read-bytes (identifier "dstring1_snd_130") (identifier "dstring1_fst_129"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_132")) (identifier "dstring2_snd_133")))))
                                                                    (let-pair "dtup_fst_135" "dtup_snd_136" 
                                                                    (identifier "dtup_134")
                                                                    (let-pair "dtup_fst_168" "dtup_snd_169"
                                                                    (let "dsum1_143"
                                                                    (let-pair "du16_fst_138" "du16_snd_139" (read-u16 little-endian (identifier "dtup_snd_136")) (make-tup (identifier "du16_fst_138") (identifier "du16_snd_139")))
                                                                    (let-pair "dsum1_fst_144" "dsum1_snd_145" 
                                                                    (identifier "dsum1_143")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_144"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 0
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_145"))
                                                                    (if 
                                                                    (eq (u16 1) (identifier "dsum1_fst_144"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 1
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_145"))
                                                                    (if 
                                                                    (eq (u16 2) (identifier "dsum1_fst_144"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 2
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_145"))
                                                                    (if 
                                                                    (eq (u16 3) (identifier "dsum1_fst_144"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 3
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_145"))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "dsum1_fst_144"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 4
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_145"))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "dsum1_fst_144"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 5
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_145"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_144") (u16 6)))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 6
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_145")))))))))))
                                                                    (make-tup
                                                                    (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 5
                                                                    (make-tup (identifier "dtup_fst_135") (identifier "dtup_fst_168"))) 
                                                                    (identifier "dtup_snd_169")))))
                                                                  (seq 
                                                                    (assert (eq (identifier "dsum1_fst_105") (u16 6)))
                                                                    (let "dtup_110"
                                                                    (let-pair "dfloat_fst_108" "dfloat_snd_109" 
                                                                    (read-u64 little-endian (identifier "dsum1_snd_106")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_108")) (identifier "dfloat_snd_109")))
                                                                    (let-pair "dtup_fst_111" "dtup_snd_112" 
                                                                    (identifier "dtup_110")
                                                                    (let-pair "du32_fst_114" "du32_snd_115" 
                                                                    (read-u32 little-endian (identifier "dtup_snd_112"))
                                                                    (make-tup
                                                                    (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 6
                                                                    (make-tup (identifier "dtup_fst_111") (identifier "du32_fst_114"))) 
                                                                    (identifier "du32_snd_115"))))))))))))))
                                                  (make-tup
                                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 15
                                                      (make-tup (identifier "dtup_fst_96") (identifier "dtup_fst_189"))) 
                                                    (identifier "dtup_snd_190"))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_654") (identifier "make_snd_655"))))
 */
static std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary_init()
{
  std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> fun29 { [&fun29](Pointer p_0) {
    v_362f9d9108a6902af48b6c83d5377ea1 id_30 { p_0.readU16Le() };
    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_31;
    {
      auto du16_fst_75 { std::get<0>(id_30) };
      auto du16_snd_76 { std::get<1>(id_30) };
      v_362f9d9108a6902af48b6c83d5377ea1 id_32 {  du16_fst_75, du16_snd_76  };
      letpair_res_31 = id_32;
    }
    f63f919559f0d70225bd0da5dd9bcafc let_res_33;
    {
      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_80 { letpair_res_31 };
      f63f919559f0d70225bd0da5dd9bcafc letpair_res_34;
      {
        auto dsum1_fst_81 { std::get<0>(dsum1_80) };
        auto dsum1_snd_82 { std::get<1>(dsum1_80) };
        uint16_t id_35 { 0 };
        bool id_36 { bool(id_35 == dsum1_fst_81) };
        f63f919559f0d70225bd0da5dd9bcafc choose_res_37;
        if (id_36) {
          t id_38 { std::in_place_index<0>, VOID };
          f63f919559f0d70225bd0da5dd9bcafc id_39 {  id_38, dsum1_snd_82  };
          choose_res_37 = id_39;
        } else {
          uint16_t id_40 { 1 };
          bool id_41 { bool(id_40 == dsum1_fst_81) };
          f63f919559f0d70225bd0da5dd9bcafc choose_res_42;
          if (id_41) {
            t id_43 { std::in_place_index<1>, VOID };
            f63f919559f0d70225bd0da5dd9bcafc id_44 {  id_43, dsum1_snd_82  };
            choose_res_42 = id_44;
          } else {
            uint16_t id_45 { 2 };
            bool id_46 { bool(id_45 == dsum1_fst_81) };
            f63f919559f0d70225bd0da5dd9bcafc choose_res_47;
            if (id_46) {
              uint32_t id_48 { 0U };
              Vec<1, uint32_t> id_49 {  id_48  };
              v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_50;
              {
                Vec<1, uint32_t> leb_ref_632 { id_49 };
                uint8_t id_51 { 0 };
                Vec<1, uint8_t> id_52 {  id_51  };
                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_53;
                {
                  Vec<1, uint8_t> shft_ref_633 { id_52 };
                  Vec<1, Pointer> id_54 {  dsum1_snd_82  };
                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_55;
                  {
                    Vec<1, Pointer> p_ref_634 { id_54 };
                    bool while_flag_56 { true };
                    do {
                      uint8_t id_57 { 0 };
                      Pointer id_58 { p_ref_634[id_57] };
                      v_1d5843897434feb24d158f3793db9189 id_59 { id_58.readU8() };
                      bool let_res_60;
                      {
                        v_1d5843897434feb24d158f3793db9189 leb128_635 { id_59 };
                        bool letpair_res_61;
                        {
                          auto leb128_fst_636 { std::get<0>(leb128_635) };
                          auto leb128_snd_637 { std::get<1>(leb128_635) };
                          uint8_t id_62 { 0 };
                          Void id_63 { ((void)(p_ref_634[id_62] = leb128_snd_637), VOID) };
                          uint8_t id_64 { 0 };
                          uint8_t id_65 { 127 };
                          uint8_t id_66 { uint8_t(leb128_fst_636 & id_65) };
                          uint32_t id_67 { uint32_t(id_66) };
                          uint8_t id_68 { 0 };
                          uint8_t id_69 { shft_ref_633[id_68] };
                          uint32_t id_70 { uint32_t(id_67 << id_69) };
                          uint8_t id_71 { 0 };
                          uint32_t id_72 { leb_ref_632[id_71] };
                          uint32_t id_73 { uint32_t(id_70 | id_72) };
                          Void id_74 { ((void)(leb_ref_632[id_64] = id_73), VOID) };
                          uint8_t id_75 { 0 };
                          uint8_t id_76 { 0 };
                          uint8_t id_77 { shft_ref_633[id_76] };
                          uint8_t id_78 { 7 };
                          uint8_t id_79 { uint8_t(id_77 + id_78) };
                          Void id_80 { ((void)(shft_ref_633[id_75] = id_79), VOID) };
                          uint8_t id_81 { 128 };
                          bool id_82 { bool(leb128_fst_636 >= id_81) };
                          letpair_res_61 = id_82;
                        }
                        let_res_60 = letpair_res_61;
                      }
                      while_flag_56 = let_res_60;
                      if (while_flag_56) {
                      }
                    } while (while_flag_56);
                    uint8_t id_83 { 0 };
                    uint32_t id_84 { leb_ref_632[id_83] };
                    Size id_85 { Size(id_84) };
                    uint8_t id_86 { 0 };
                    Pointer id_87 { p_ref_634[id_86] };
                    v_41b0681ed7f1f185fd3e6c4dcdc13110 id_88 {  id_85, id_87  };
                    let_res_55 = id_88;
                  }
                  let_res_53 = let_res_55;
                }
                let_res_50 = let_res_53;
              }
              f63f919559f0d70225bd0da5dd9bcafc let_res_89;
              {
                v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_638 { let_res_50 };
                f63f919559f0d70225bd0da5dd9bcafc letpair_res_90;
                {
                  auto dstring1_fst_639 { std::get<0>(dstring1_638) };
                  auto dstring1_snd_640 { std::get<1>(dstring1_638) };
                  f921d1e0a170c3c04148c21704db9c45 id_91 { dstring1_snd_640.readBytes(dstring1_fst_639) };
                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_92;
                  {
                    auto dstring2_fst_642 { std::get<0>(id_91) };
                    auto dstring2_snd_643 { std::get<1>(id_91) };
                    std::string id_93 { dstring2_fst_642.toString() };
                    t id_94 { std::in_place_index<2>, id_93 };
                    f63f919559f0d70225bd0da5dd9bcafc id_95 {  id_94, dstring2_snd_643  };
                    letpair_res_92 = id_95;
                  }
                  letpair_res_90 = letpair_res_92;
                }
                let_res_89 = letpair_res_90;
              }
              choose_res_47 = let_res_89;
            } else {
              uint16_t id_96 { 3 };
              bool id_97 { bool(id_96 == dsum1_fst_81) };
              f63f919559f0d70225bd0da5dd9bcafc choose_res_98;
              if (id_97) {
                std::function<v_630c8a213597275b9f8880113825c98a(Pointer)> id_99 { dessser_gen::src_path.of_row_binary };
                v_630c8a213597275b9f8880113825c98a id_100 { id_99(dsum1_snd_82) };
                f63f919559f0d70225bd0da5dd9bcafc let_res_101;
                {
                  v_630c8a213597275b9f8880113825c98a dtup_611 { id_100 };
                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_102;
                  {
                    auto dtup_fst_612 { std::get<0>(dtup_611) };
                    auto dtup_snd_613 { std::get<1>(dtup_611) };
                    uint32_t id_103 { 0U };
                    Vec<1, uint32_t> id_104 {  id_103  };
                    v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_105;
                    {
                      Vec<1, uint32_t> leb_ref_614 { id_104 };
                      uint8_t id_106 { 0 };
                      Vec<1, uint8_t> id_107 {  id_106  };
                      v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_108;
                      {
                        Vec<1, uint8_t> shft_ref_615 { id_107 };
                        Vec<1, Pointer> id_109 {  dtup_snd_613  };
                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_110;
                        {
                          Vec<1, Pointer> p_ref_616 { id_109 };
                          bool while_flag_111 { true };
                          do {
                            uint8_t id_112 { 0 };
                            Pointer id_113 { p_ref_616[id_112] };
                            v_1d5843897434feb24d158f3793db9189 id_114 { id_113.readU8() };
                            bool let_res_115;
                            {
                              v_1d5843897434feb24d158f3793db9189 leb128_617 { id_114 };
                              bool letpair_res_116;
                              {
                                auto leb128_fst_618 { std::get<0>(leb128_617) };
                                auto leb128_snd_619 { std::get<1>(leb128_617) };
                                uint8_t id_117 { 0 };
                                Void id_118 { ((void)(p_ref_616[id_117] = leb128_snd_619), VOID) };
                                uint8_t id_119 { 0 };
                                uint8_t id_120 { 127 };
                                uint8_t id_121 { uint8_t(leb128_fst_618 & id_120) };
                                uint32_t id_122 { uint32_t(id_121) };
                                uint8_t id_123 { 0 };
                                uint8_t id_124 { shft_ref_615[id_123] };
                                uint32_t id_125 { uint32_t(id_122 << id_124) };
                                uint8_t id_126 { 0 };
                                uint32_t id_127 { leb_ref_614[id_126] };
                                uint32_t id_128 { uint32_t(id_125 | id_127) };
                                Void id_129 { ((void)(leb_ref_614[id_119] = id_128), VOID) };
                                uint8_t id_130 { 0 };
                                uint8_t id_131 { 0 };
                                uint8_t id_132 { shft_ref_615[id_131] };
                                uint8_t id_133 { 7 };
                                uint8_t id_134 { uint8_t(id_132 + id_133) };
                                Void id_135 { ((void)(shft_ref_615[id_130] = id_134), VOID) };
                                uint8_t id_136 { 128 };
                                bool id_137 { bool(leb128_fst_618 >= id_136) };
                                letpair_res_116 = id_137;
                              }
                              let_res_115 = letpair_res_116;
                            }
                            while_flag_111 = let_res_115;
                            if (while_flag_111) {
                            }
                          } while (while_flag_111);
                          uint8_t id_138 { 0 };
                          uint32_t id_139 { leb_ref_614[id_138] };
                          Size id_140 { Size(id_139) };
                          uint8_t id_141 { 0 };
                          Pointer id_142 { p_ref_616[id_141] };
                          v_41b0681ed7f1f185fd3e6c4dcdc13110 id_143 {  id_140, id_142  };
                          let_res_110 = id_143;
                        }
                        let_res_108 = let_res_110;
                      }
                      let_res_105 = let_res_108;
                    }
                    f63f919559f0d70225bd0da5dd9bcafc let_res_144;
                    {
                      v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_620 { let_res_105 };
                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_145;
                      {
                        auto dstring1_fst_621 { std::get<0>(dstring1_620) };
                        auto dstring1_snd_622 { std::get<1>(dstring1_620) };
                        f921d1e0a170c3c04148c21704db9c45 id_146 { dstring1_snd_622.readBytes(dstring1_fst_621) };
                        f63f919559f0d70225bd0da5dd9bcafc letpair_res_147;
                        {
                          auto dstring2_fst_624 { std::get<0>(id_146) };
                          auto dstring2_snd_625 { std::get<1>(id_146) };
                          std::string id_148 { dstring2_fst_624.toString() };
                          c404d7e7dfb3057f4a4f6b6766eeb900 id_149 {  dtup_fst_612, id_148  };
                          t id_150 { std::in_place_index<3>, id_149 };
                          f63f919559f0d70225bd0da5dd9bcafc id_151 {  id_150, dstring2_snd_625  };
                          letpair_res_147 = id_151;
                        }
                        letpair_res_145 = letpair_res_147;
                      }
                      let_res_144 = letpair_res_145;
                    }
                    letpair_res_102 = let_res_144;
                  }
                  let_res_101 = letpair_res_102;
                }
                choose_res_98 = let_res_101;
              } else {
                uint16_t id_152 { 4 };
                bool id_153 { bool(id_152 == dsum1_fst_81) };
                f63f919559f0d70225bd0da5dd9bcafc choose_res_154;
                if (id_153) {
                  t id_155 { std::in_place_index<4>, VOID };
                  f63f919559f0d70225bd0da5dd9bcafc id_156 {  id_155, dsum1_snd_82  };
                  choose_res_154 = id_156;
                } else {
                  uint16_t id_157 { 5 };
                  bool id_158 { bool(id_157 == dsum1_fst_81) };
                  f63f919559f0d70225bd0da5dd9bcafc choose_res_159;
                  if (id_158) {
                    std::function<ddf7cb48181332ead2f60a5f4bb1a8de(Pointer)> id_160 { dessser_gen::site_name.of_row_binary };
                    ddf7cb48181332ead2f60a5f4bb1a8de id_161 { id_160(dsum1_snd_82) };
                    f63f919559f0d70225bd0da5dd9bcafc let_res_162;
                    {
                      ddf7cb48181332ead2f60a5f4bb1a8de dtup_419 { id_161 };
                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_163;
                      {
                        auto dtup_fst_420 { std::get<0>(dtup_419) };
                        auto dtup_snd_421 { std::get<1>(dtup_419) };
                        v_362f9d9108a6902af48b6c83d5377ea1 id_164 { dtup_snd_421.readU16Le() };
                        v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_165;
                        {
                          auto du16_fst_423 { std::get<0>(id_164) };
                          auto du16_snd_424 { std::get<1>(id_164) };
                          v_362f9d9108a6902af48b6c83d5377ea1 id_166 {  du16_fst_423, du16_snd_424  };
                          letpair_res_165 = id_166;
                        }
                        e8a9e5263837de1dc85029fd46dec174 let_res_167;
                        {
                          v_362f9d9108a6902af48b6c83d5377ea1 dsum1_428 { letpair_res_165 };
                          e8a9e5263837de1dc85029fd46dec174 letpair_res_168;
                          {
                            auto dsum1_fst_429 { std::get<0>(dsum1_428) };
                            auto dsum1_snd_430 { std::get<1>(dsum1_428) };
                            uint16_t id_169 { 0 };
                            bool id_170 { bool(id_169 == dsum1_fst_429) };
                            e8a9e5263837de1dc85029fd46dec174 choose_res_171;
                            if (id_170) {
                              v_320dee9bcc93c7ed0c75cc7db8b85d9b id_172 { std::in_place_index<0>, VOID };
                              e8a9e5263837de1dc85029fd46dec174 id_173 {  id_172, dsum1_snd_430  };
                              choose_res_171 = id_173;
                            } else {
                              uint16_t id_174 { 1 };
                              bool id_175 { bool(id_174 == dsum1_fst_429) };
                              e8a9e5263837de1dc85029fd46dec174 choose_res_176;
                              if (id_175) {
                                uint32_t id_177 { 0U };
                                Vec<1, uint32_t> id_178 {  id_177  };
                                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_179;
                                {
                                  Vec<1, uint32_t> leb_ref_563 { id_178 };
                                  uint8_t id_180 { 0 };
                                  Vec<1, uint8_t> id_181 {  id_180  };
                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_182;
                                  {
                                    Vec<1, uint8_t> shft_ref_564 { id_181 };
                                    Vec<1, Pointer> id_183 {  dsum1_snd_430  };
                                    v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_184;
                                    {
                                      Vec<1, Pointer> p_ref_565 { id_183 };
                                      bool while_flag_185 { true };
                                      do {
                                        uint8_t id_186 { 0 };
                                        Pointer id_187 { p_ref_565[id_186] };
                                        v_1d5843897434feb24d158f3793db9189 id_188 { id_187.readU8() };
                                        bool let_res_189;
                                        {
                                          v_1d5843897434feb24d158f3793db9189 leb128_566 { id_188 };
                                          bool letpair_res_190;
                                          {
                                            auto leb128_fst_567 { std::get<0>(leb128_566) };
                                            auto leb128_snd_568 { std::get<1>(leb128_566) };
                                            uint8_t id_191 { 0 };
                                            Void id_192 { ((void)(p_ref_565[id_191] = leb128_snd_568), VOID) };
                                            uint8_t id_193 { 0 };
                                            uint8_t id_194 { 127 };
                                            uint8_t id_195 { uint8_t(leb128_fst_567 & id_194) };
                                            uint32_t id_196 { uint32_t(id_195) };
                                            uint8_t id_197 { 0 };
                                            uint8_t id_198 { shft_ref_564[id_197] };
                                            uint32_t id_199 { uint32_t(id_196 << id_198) };
                                            uint8_t id_200 { 0 };
                                            uint32_t id_201 { leb_ref_563[id_200] };
                                            uint32_t id_202 { uint32_t(id_199 | id_201) };
                                            Void id_203 { ((void)(leb_ref_563[id_193] = id_202), VOID) };
                                            uint8_t id_204 { 0 };
                                            uint8_t id_205 { 0 };
                                            uint8_t id_206 { shft_ref_564[id_205] };
                                            uint8_t id_207 { 7 };
                                            uint8_t id_208 { uint8_t(id_206 + id_207) };
                                            Void id_209 { ((void)(shft_ref_564[id_204] = id_208), VOID) };
                                            uint8_t id_210 { 128 };
                                            bool id_211 { bool(leb128_fst_567 >= id_210) };
                                            letpair_res_190 = id_211;
                                          }
                                          let_res_189 = letpair_res_190;
                                        }
                                        while_flag_185 = let_res_189;
                                        if (while_flag_185) {
                                        }
                                      } while (while_flag_185);
                                      uint8_t id_212 { 0 };
                                      uint32_t id_213 { leb_ref_563[id_212] };
                                      Size id_214 { Size(id_213) };
                                      uint8_t id_215 { 0 };
                                      Pointer id_216 { p_ref_565[id_215] };
                                      v_41b0681ed7f1f185fd3e6c4dcdc13110 id_217 {  id_214, id_216  };
                                      let_res_184 = id_217;
                                    }
                                    let_res_182 = let_res_184;
                                  }
                                  let_res_179 = let_res_182;
                                }
                                v_46a5e81c2410b000ff0adea6dc198147 let_res_218;
                                {
                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_569 { let_res_179 };
                                  v_46a5e81c2410b000ff0adea6dc198147 letpair_res_219;
                                  {
                                    auto dstring1_fst_570 { std::get<0>(dstring1_569) };
                                    auto dstring1_snd_571 { std::get<1>(dstring1_569) };
                                    f921d1e0a170c3c04148c21704db9c45 id_220 { dstring1_snd_571.readBytes(dstring1_fst_570) };
                                    v_46a5e81c2410b000ff0adea6dc198147 letpair_res_221;
                                    {
                                      auto dstring2_fst_573 { std::get<0>(id_220) };
                                      auto dstring2_snd_574 { std::get<1>(id_220) };
                                      std::string id_222 { dstring2_fst_573.toString() };
                                      v_46a5e81c2410b000ff0adea6dc198147 id_223 {  id_222, dstring2_snd_574  };
                                      letpair_res_221 = id_223;
                                    }
                                    letpair_res_219 = letpair_res_221;
                                  }
                                  let_res_218 = letpair_res_219;
                                }
                                e8a9e5263837de1dc85029fd46dec174 let_res_224;
                                {
                                  v_46a5e81c2410b000ff0adea6dc198147 dtup_575 { let_res_218 };
                                  e8a9e5263837de1dc85029fd46dec174 letpair_res_225;
                                  {
                                    auto dtup_fst_576 { std::get<0>(dtup_575) };
                                    auto dtup_snd_577 { std::get<1>(dtup_575) };
                                    v_362f9d9108a6902af48b6c83d5377ea1 id_226 { dtup_snd_577.readU16Le() };
                                    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_227;
                                    {
                                      auto du16_fst_579 { std::get<0>(id_226) };
                                      auto du16_snd_580 { std::get<1>(id_226) };
                                      v_362f9d9108a6902af48b6c83d5377ea1 id_228 {  du16_fst_579, du16_snd_580  };
                                      letpair_res_227 = id_228;
                                    }
                                    v_767414c116ccecff2dddf58db4b75b83 let_res_229;
                                    {
                                      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_584 { letpair_res_227 };
                                      v_767414c116ccecff2dddf58db4b75b83 letpair_res_230;
                                      {
                                        auto dsum1_fst_585 { std::get<0>(dsum1_584) };
                                        auto dsum1_snd_586 { std::get<1>(dsum1_584) };
                                        uint16_t id_231 { 0 };
                                        bool id_232 { bool(id_231 == dsum1_fst_585) };
                                        v_767414c116ccecff2dddf58db4b75b83 choose_res_233;
                                        if (id_232) {
                                          v_1e81caa74ae611e9cb191b8ee50bee25 id_234 { std::in_place_index<0>, VOID };
                                          v_767414c116ccecff2dddf58db4b75b83 id_235 {  id_234, dsum1_snd_586  };
                                          choose_res_233 = id_235;
                                        } else {
                                          uint16_t id_236 { 1 };
                                          bool id_237 { bool(dsum1_fst_585 == id_236) };
                                          Void id_238 { ((void)(assert(id_237)), VOID) };
                                          v_1e81caa74ae611e9cb191b8ee50bee25 id_239 { std::in_place_index<1>, VOID };
                                          v_767414c116ccecff2dddf58db4b75b83 id_240 {  id_239, dsum1_snd_586  };
                                          choose_res_233 = id_240;
                                        }
                                        letpair_res_230 = choose_res_233;
                                      }
                                      let_res_229 = letpair_res_230;
                                    }
                                    e8a9e5263837de1dc85029fd46dec174 letpair_res_241;
                                    {
                                      auto dtup_fst_594 { std::get<0>(let_res_229) };
                                      auto dtup_snd_595 { std::get<1>(let_res_229) };
                                      c8d851022c838ee90bc952d525c2d3aa id_242 {  dtup_fst_576, dtup_fst_594  };
                                      v_320dee9bcc93c7ed0c75cc7db8b85d9b id_243 { std::in_place_index<1>, id_242 };
                                      e8a9e5263837de1dc85029fd46dec174 id_244 {  id_243, dtup_snd_595  };
                                      letpair_res_241 = id_244;
                                    }
                                    letpair_res_225 = letpair_res_241;
                                  }
                                  let_res_224 = letpair_res_225;
                                }
                                choose_res_176 = let_res_224;
                              } else {
                                uint16_t id_245 { 2 };
                                bool id_246 { bool(id_245 == dsum1_fst_429) };
                                e8a9e5263837de1dc85029fd46dec174 choose_res_247;
                                if (id_246) {
                                  std::function<v_41ac8303016d6ac19fef26d484dd5164(Pointer)> id_248 { dessser_gen::fq_name.of_row_binary };
                                  v_41ac8303016d6ac19fef26d484dd5164 id_249 { id_248(dsum1_snd_430) };
                                  e8a9e5263837de1dc85029fd46dec174 let_res_250;
                                  {
                                    v_41ac8303016d6ac19fef26d484dd5164 dtup_464 { id_249 };
                                    e8a9e5263837de1dc85029fd46dec174 letpair_res_251;
                                    {
                                      auto dtup_fst_465 { std::get<0>(dtup_464) };
                                      auto dtup_snd_466 { std::get<1>(dtup_464) };
                                      v_362f9d9108a6902af48b6c83d5377ea1 id_252 { dtup_snd_466.readU16Le() };
                                      v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_253;
                                      {
                                        auto du16_fst_468 { std::get<0>(id_252) };
                                        auto du16_snd_469 { std::get<1>(id_252) };
                                        v_362f9d9108a6902af48b6c83d5377ea1 id_254 {  du16_fst_468, du16_snd_469  };
                                        letpair_res_253 = id_254;
                                      }
                                      v_607ee10f4a91de96ce2d10309c38196b let_res_255;
                                      {
                                        v_362f9d9108a6902af48b6c83d5377ea1 dsum1_473 { letpair_res_253 };
                                        v_607ee10f4a91de96ce2d10309c38196b letpair_res_256;
                                        {
                                          auto dsum1_fst_474 { std::get<0>(dsum1_473) };
                                          auto dsum1_snd_475 { std::get<1>(dsum1_473) };
                                          uint16_t id_257 { 0 };
                                          bool id_258 { bool(id_257 == dsum1_fst_474) };
                                          v_607ee10f4a91de96ce2d10309c38196b choose_res_259;
                                          if (id_258) {
                                            v_8c6c9edc5b1d709b5094571801c00912 id_260 { std::in_place_index<0>, VOID };
                                            v_607ee10f4a91de96ce2d10309c38196b id_261 {  id_260, dsum1_snd_475  };
                                            choose_res_259 = id_261;
                                          } else {
                                            uint16_t id_262 { 1 };
                                            bool id_263 { bool(id_262 == dsum1_fst_474) };
                                            v_607ee10f4a91de96ce2d10309c38196b choose_res_264;
                                            if (id_263) {
                                              v_8c6c9edc5b1d709b5094571801c00912 id_265 { std::in_place_index<1>, VOID };
                                              v_607ee10f4a91de96ce2d10309c38196b id_266 {  id_265, dsum1_snd_475  };
                                              choose_res_264 = id_266;
                                            } else {
                                              uint16_t id_267 { 2 };
                                              bool id_268 { bool(id_267 == dsum1_fst_474) };
                                              v_607ee10f4a91de96ce2d10309c38196b choose_res_269;
                                              if (id_268) {
                                                v_8c6c9edc5b1d709b5094571801c00912 id_270 { std::in_place_index<2>, VOID };
                                                v_607ee10f4a91de96ce2d10309c38196b id_271 {  id_270, dsum1_snd_475  };
                                                choose_res_269 = id_271;
                                              } else {
                                                uint16_t id_272 { 3 };
                                                bool id_273 { bool(id_272 == dsum1_fst_474) };
                                                v_607ee10f4a91de96ce2d10309c38196b choose_res_274;
                                                if (id_273) {
                                                  v_8c6c9edc5b1d709b5094571801c00912 id_275 { std::in_place_index<3>, VOID };
                                                  v_607ee10f4a91de96ce2d10309c38196b id_276 {  id_275, dsum1_snd_475  };
                                                  choose_res_274 = id_276;
                                                } else {
                                                  uint16_t id_277 { 4 };
                                                  bool id_278 { bool(id_277 == dsum1_fst_474) };
                                                  v_607ee10f4a91de96ce2d10309c38196b choose_res_279;
                                                  if (id_278) {
                                                    v_8c6c9edc5b1d709b5094571801c00912 id_280 { std::in_place_index<4>, VOID };
                                                    v_607ee10f4a91de96ce2d10309c38196b id_281 {  id_280, dsum1_snd_475  };
                                                    choose_res_279 = id_281;
                                                  } else {
                                                    uint16_t id_282 { 5 };
                                                    bool id_283 { bool(id_282 == dsum1_fst_474) };
                                                    v_607ee10f4a91de96ce2d10309c38196b choose_res_284;
                                                    if (id_283) {
                                                      v_8c6c9edc5b1d709b5094571801c00912 id_285 { std::in_place_index<5>, VOID };
                                                      v_607ee10f4a91de96ce2d10309c38196b id_286 {  id_285, dsum1_snd_475  };
                                                      choose_res_284 = id_286;
                                                    } else {
                                                      uint16_t id_287 { 6 };
                                                      bool id_288 { bool(id_287 == dsum1_fst_474) };
                                                      v_607ee10f4a91de96ce2d10309c38196b choose_res_289;
                                                      if (id_288) {
                                                        uint32_t id_290 { 0U };
                                                        Vec<1, uint32_t> id_291 {  id_290  };
                                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_292;
                                                        {
                                                          Vec<1, uint32_t> leb_ref_485 { id_291 };
                                                          uint8_t id_293 { 0 };
                                                          Vec<1, uint8_t> id_294 {  id_293  };
                                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_295;
                                                          {
                                                            Vec<1, uint8_t> shft_ref_486 { id_294 };
                                                            Vec<1, Pointer> id_296 {  dsum1_snd_475  };
                                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_297;
                                                            {
                                                              Vec<1, Pointer> p_ref_487 { id_296 };
                                                              bool while_flag_298 { true };
                                                              do {
                                                                uint8_t id_299 { 0 };
                                                                Pointer id_300 { p_ref_487[id_299] };
                                                                v_1d5843897434feb24d158f3793db9189 id_301 { id_300.readU8() };
                                                                bool let_res_302;
                                                                {
                                                                  v_1d5843897434feb24d158f3793db9189 leb128_488 { id_301 };
                                                                  bool letpair_res_303;
                                                                  {
                                                                    auto leb128_fst_489 { std::get<0>(leb128_488) };
                                                                    auto leb128_snd_490 { std::get<1>(leb128_488) };
                                                                    uint8_t id_304 { 0 };
                                                                    Void id_305 { ((void)(p_ref_487[id_304] = leb128_snd_490), VOID) };
                                                                    uint8_t id_306 { 0 };
                                                                    uint8_t id_307 { 127 };
                                                                    uint8_t id_308 { uint8_t(leb128_fst_489 & id_307) };
                                                                    uint32_t id_309 { uint32_t(id_308) };
                                                                    uint8_t id_310 { 0 };
                                                                    uint8_t id_311 { shft_ref_486[id_310] };
                                                                    uint32_t id_312 { uint32_t(id_309 << id_311) };
                                                                    uint8_t id_313 { 0 };
                                                                    uint32_t id_314 { leb_ref_485[id_313] };
                                                                    uint32_t id_315 { uint32_t(id_312 | id_314) };
                                                                    Void id_316 { ((void)(leb_ref_485[id_306] = id_315), VOID) };
                                                                    uint8_t id_317 { 0 };
                                                                    uint8_t id_318 { 0 };
                                                                    uint8_t id_319 { shft_ref_486[id_318] };
                                                                    uint8_t id_320 { 7 };
                                                                    uint8_t id_321 { uint8_t(id_319 + id_320) };
                                                                    Void id_322 { ((void)(shft_ref_486[id_317] = id_321), VOID) };
                                                                    uint8_t id_323 { 128 };
                                                                    bool id_324 { bool(leb128_fst_489 >= id_323) };
                                                                    letpair_res_303 = id_324;
                                                                  }
                                                                  let_res_302 = letpair_res_303;
                                                                }
                                                                while_flag_298 = let_res_302;
                                                                if (while_flag_298) {
                                                                }
                                                              } while (while_flag_298);
                                                              uint8_t id_325 { 0 };
                                                              uint32_t id_326 { leb_ref_485[id_325] };
                                                              Size id_327 { Size(id_326) };
                                                              uint8_t id_328 { 0 };
                                                              Pointer id_329 { p_ref_487[id_328] };
                                                              v_41b0681ed7f1f185fd3e6c4dcdc13110 id_330 {  id_327, id_329  };
                                                              let_res_297 = id_330;
                                                            }
                                                            let_res_295 = let_res_297;
                                                          }
                                                          let_res_292 = let_res_295;
                                                        }
                                                        v_46a5e81c2410b000ff0adea6dc198147 let_res_331;
                                                        {
                                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_491 { let_res_292 };
                                                          v_46a5e81c2410b000ff0adea6dc198147 letpair_res_332;
                                                          {
                                                            auto dstring1_fst_492 { std::get<0>(dstring1_491) };
                                                            auto dstring1_snd_493 { std::get<1>(dstring1_491) };
                                                            f921d1e0a170c3c04148c21704db9c45 id_333 { dstring1_snd_493.readBytes(dstring1_fst_492) };
                                                            v_46a5e81c2410b000ff0adea6dc198147 letpair_res_334;
                                                            {
                                                              auto dstring2_fst_495 { std::get<0>(id_333) };
                                                              auto dstring2_snd_496 { std::get<1>(id_333) };
                                                              std::string id_335 { dstring2_fst_495.toString() };
                                                              v_46a5e81c2410b000ff0adea6dc198147 id_336 {  id_335, dstring2_snd_496  };
                                                              letpair_res_334 = id_336;
                                                            }
                                                            letpair_res_332 = letpair_res_334;
                                                          }
                                                          let_res_331 = letpair_res_332;
                                                        }
                                                        v_607ee10f4a91de96ce2d10309c38196b let_res_337;
                                                        {
                                                          v_46a5e81c2410b000ff0adea6dc198147 dtup_497 { let_res_331 };
                                                          v_607ee10f4a91de96ce2d10309c38196b letpair_res_338;
                                                          {
                                                            auto dtup_fst_498 { std::get<0>(dtup_497) };
                                                            auto dtup_snd_499 { std::get<1>(dtup_497) };
                                                            v_362f9d9108a6902af48b6c83d5377ea1 id_339 { dtup_snd_499.readU16Le() };
                                                            v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_340;
                                                            {
                                                              auto du16_fst_501 { std::get<0>(id_339) };
                                                              auto du16_snd_502 { std::get<1>(id_339) };
                                                              v_362f9d9108a6902af48b6c83d5377ea1 id_341 {  du16_fst_501, du16_snd_502  };
                                                              letpair_res_340 = id_341;
                                                            }
                                                            bd3c7167a3ed96b2802d09e3178bc3c5 let_res_342;
                                                            {
                                                              v_362f9d9108a6902af48b6c83d5377ea1 dsum1_506 { letpair_res_340 };
                                                              bd3c7167a3ed96b2802d09e3178bc3c5 letpair_res_343;
                                                              {
                                                                auto dsum1_fst_507 { std::get<0>(dsum1_506) };
                                                                auto dsum1_snd_508 { std::get<1>(dsum1_506) };
                                                                uint16_t id_344 { 0 };
                                                                bool id_345 { bool(id_344 == dsum1_fst_507) };
                                                                bd3c7167a3ed96b2802d09e3178bc3c5 choose_res_346;
                                                                if (id_345) {
                                                                  v_8e097ae30bed5641a60541fcf38314dd id_347 { std::in_place_index<0>, VOID };
                                                                  bd3c7167a3ed96b2802d09e3178bc3c5 id_348 {  id_347, dsum1_snd_508  };
                                                                  choose_res_346 = id_348;
                                                                } else {
                                                                  uint16_t id_349 { 1 };
                                                                  bool id_350 { bool(id_349 == dsum1_fst_507) };
                                                                  bd3c7167a3ed96b2802d09e3178bc3c5 choose_res_351;
                                                                  if (id_350) {
                                                                    v_8e097ae30bed5641a60541fcf38314dd id_352 { std::in_place_index<1>, VOID };
                                                                    bd3c7167a3ed96b2802d09e3178bc3c5 id_353 {  id_352, dsum1_snd_508  };
                                                                    choose_res_351 = id_353;
                                                                  } else {
                                                                    uint16_t id_354 { 2 };
                                                                    bool id_355 { bool(id_354 == dsum1_fst_507) };
                                                                    bd3c7167a3ed96b2802d09e3178bc3c5 choose_res_356;
                                                                    if (id_355) {
                                                                      v_8e097ae30bed5641a60541fcf38314dd id_357 { std::in_place_index<2>, VOID };
                                                                      bd3c7167a3ed96b2802d09e3178bc3c5 id_358 {  id_357, dsum1_snd_508  };
                                                                      choose_res_356 = id_358;
                                                                    } else {
                                                                      uint16_t id_359 { 3 };
                                                                      bool id_360 { bool(id_359 == dsum1_fst_507) };
                                                                      bd3c7167a3ed96b2802d09e3178bc3c5 choose_res_361;
                                                                      if (id_360) {
                                                                        v_8e097ae30bed5641a60541fcf38314dd id_362 { std::in_place_index<3>, VOID };
                                                                        bd3c7167a3ed96b2802d09e3178bc3c5 id_363 {  id_362, dsum1_snd_508  };
                                                                        choose_res_361 = id_363;
                                                                      } else {
                                                                        uint16_t id_364 { 4 };
                                                                        bool id_365 { bool(id_364 == dsum1_fst_507) };
                                                                        bd3c7167a3ed96b2802d09e3178bc3c5 choose_res_366;
                                                                        if (id_365) {
                                                                          v_8e097ae30bed5641a60541fcf38314dd id_367 { std::in_place_index<4>, VOID };
                                                                          bd3c7167a3ed96b2802d09e3178bc3c5 id_368 {  id_367, dsum1_snd_508  };
                                                                          choose_res_366 = id_368;
                                                                        } else {
                                                                          uint16_t id_369 { 5 };
                                                                          bool id_370 { bool(id_369 == dsum1_fst_507) };
                                                                          bd3c7167a3ed96b2802d09e3178bc3c5 choose_res_371;
                                                                          if (id_370) {
                                                                            v_8e097ae30bed5641a60541fcf38314dd id_372 { std::in_place_index<5>, VOID };
                                                                            bd3c7167a3ed96b2802d09e3178bc3c5 id_373 {  id_372, dsum1_snd_508  };
                                                                            choose_res_371 = id_373;
                                                                          } else {
                                                                            uint16_t id_374 { 6 };
                                                                            bool id_375 { bool(id_374 == dsum1_fst_507) };
                                                                            bd3c7167a3ed96b2802d09e3178bc3c5 choose_res_376;
                                                                            if (id_375) {
                                                                              v_8e097ae30bed5641a60541fcf38314dd id_377 { std::in_place_index<6>, VOID };
                                                                              bd3c7167a3ed96b2802d09e3178bc3c5 id_378 {  id_377, dsum1_snd_508  };
                                                                              choose_res_376 = id_378;
                                                                            } else {
                                                                              uint16_t id_379 { 7 };
                                                                              bool id_380 { bool(dsum1_fst_507 == id_379) };
                                                                              Void id_381 { ((void)(assert(id_380)), VOID) };
                                                                              v_8e097ae30bed5641a60541fcf38314dd id_382 { std::in_place_index<7>, VOID };
                                                                              bd3c7167a3ed96b2802d09e3178bc3c5 id_383 {  id_382, dsum1_snd_508  };
                                                                              choose_res_376 = id_383;
                                                                            }
                                                                            choose_res_371 = choose_res_376;
                                                                          }
                                                                          choose_res_366 = choose_res_371;
                                                                        }
                                                                        choose_res_361 = choose_res_366;
                                                                      }
                                                                      choose_res_356 = choose_res_361;
                                                                    }
                                                                    choose_res_351 = choose_res_356;
                                                                  }
                                                                  choose_res_346 = choose_res_351;
                                                                }
                                                                letpair_res_343 = choose_res_346;
                                                              }
                                                              let_res_342 = letpair_res_343;
                                                            }
                                                            v_607ee10f4a91de96ce2d10309c38196b letpair_res_384;
                                                            {
                                                              auto dtup_fst_534 { std::get<0>(let_res_342) };
                                                              auto dtup_snd_535 { std::get<1>(let_res_342) };
                                                              a9a5fa86cfaa17c85b3606d1a4582bcd id_385 {  dtup_fst_498, dtup_fst_534  };
                                                              v_8c6c9edc5b1d709b5094571801c00912 id_386 { std::in_place_index<6>, id_385 };
                                                              v_607ee10f4a91de96ce2d10309c38196b id_387 {  id_386, dtup_snd_535  };
                                                              letpair_res_384 = id_387;
                                                            }
                                                            letpair_res_338 = letpair_res_384;
                                                          }
                                                          let_res_337 = letpair_res_338;
                                                        }
                                                        choose_res_289 = let_res_337;
                                                      } else {
                                                        uint16_t id_388 { 7 };
                                                        bool id_389 { bool(id_388 == dsum1_fst_474) };
                                                        v_607ee10f4a91de96ce2d10309c38196b choose_res_390;
                                                        if (id_389) {
                                                          ac0fbd05039f742d2f1d9ac182e392ab id_391 { dsum1_snd_475.readU32Le() };
                                                          v_607ee10f4a91de96ce2d10309c38196b letpair_res_392;
                                                          {
                                                            auto du32_fst_480 { std::get<0>(id_391) };
                                                            auto du32_snd_481 { std::get<1>(id_391) };
                                                            v_8c6c9edc5b1d709b5094571801c00912 id_393 { std::in_place_index<7>, du32_fst_480 };
                                                            v_607ee10f4a91de96ce2d10309c38196b id_394 {  id_393, du32_snd_481  };
                                                            letpair_res_392 = id_394;
                                                          }
                                                          choose_res_390 = letpair_res_392;
                                                        } else {
                                                          uint16_t id_395 { 8 };
                                                          bool id_396 { bool(dsum1_fst_474 == id_395) };
                                                          Void id_397 { ((void)(assert(id_396)), VOID) };
                                                          v_8c6c9edc5b1d709b5094571801c00912 id_398 { std::in_place_index<8>, VOID };
                                                          v_607ee10f4a91de96ce2d10309c38196b id_399 {  id_398, dsum1_snd_475  };
                                                          choose_res_390 = id_399;
                                                        }
                                                        choose_res_289 = choose_res_390;
                                                      }
                                                      choose_res_284 = choose_res_289;
                                                    }
                                                    choose_res_279 = choose_res_284;
                                                  }
                                                  choose_res_274 = choose_res_279;
                                                }
                                                choose_res_269 = choose_res_274;
                                              }
                                              choose_res_264 = choose_res_269;
                                            }
                                            choose_res_259 = choose_res_264;
                                          }
                                          letpair_res_256 = choose_res_259;
                                        }
                                        let_res_255 = letpair_res_256;
                                      }
                                      e8a9e5263837de1dc85029fd46dec174 letpair_res_400;
                                      {
                                        auto dtup_fst_558 { std::get<0>(let_res_255) };
                                        auto dtup_snd_559 { std::get<1>(let_res_255) };
                                        v_0fab8a04cd41fd489e58d011ef6f08ad id_401 {  dtup_fst_465, dtup_fst_558  };
                                        v_320dee9bcc93c7ed0c75cc7db8b85d9b id_402 { std::in_place_index<2>, id_401 };
                                        e8a9e5263837de1dc85029fd46dec174 id_403 {  id_402, dtup_snd_559  };
                                        letpair_res_400 = id_403;
                                      }
                                      letpair_res_251 = letpair_res_400;
                                    }
                                    let_res_250 = letpair_res_251;
                                  }
                                  choose_res_247 = let_res_250;
                                } else {
                                  uint16_t id_404 { 3 };
                                  bool id_405 { bool(dsum1_fst_429 == id_404) };
                                  Void id_406 { ((void)(assert(id_405)), VOID) };
                                  uint32_t id_407 { 0U };
                                  Vec<1, uint32_t> id_408 {  id_407  };
                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_409;
                                  {
                                    Vec<1, uint32_t> leb_ref_431 { id_408 };
                                    uint8_t id_410 { 0 };
                                    Vec<1, uint8_t> id_411 {  id_410  };
                                    v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_412;
                                    {
                                      Vec<1, uint8_t> shft_ref_432 { id_411 };
                                      Vec<1, Pointer> id_413 {  dsum1_snd_430  };
                                      v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_414;
                                      {
                                        Vec<1, Pointer> p_ref_433 { id_413 };
                                        bool while_flag_415 { true };
                                        do {
                                          uint8_t id_416 { 0 };
                                          Pointer id_417 { p_ref_433[id_416] };
                                          v_1d5843897434feb24d158f3793db9189 id_418 { id_417.readU8() };
                                          bool let_res_419;
                                          {
                                            v_1d5843897434feb24d158f3793db9189 leb128_434 { id_418 };
                                            bool letpair_res_420;
                                            {
                                              auto leb128_fst_435 { std::get<0>(leb128_434) };
                                              auto leb128_snd_436 { std::get<1>(leb128_434) };
                                              uint8_t id_421 { 0 };
                                              Void id_422 { ((void)(p_ref_433[id_421] = leb128_snd_436), VOID) };
                                              uint8_t id_423 { 0 };
                                              uint8_t id_424 { 127 };
                                              uint8_t id_425 { uint8_t(leb128_fst_435 & id_424) };
                                              uint32_t id_426 { uint32_t(id_425) };
                                              uint8_t id_427 { 0 };
                                              uint8_t id_428 { shft_ref_432[id_427] };
                                              uint32_t id_429 { uint32_t(id_426 << id_428) };
                                              uint8_t id_430 { 0 };
                                              uint32_t id_431 { leb_ref_431[id_430] };
                                              uint32_t id_432 { uint32_t(id_429 | id_431) };
                                              Void id_433 { ((void)(leb_ref_431[id_423] = id_432), VOID) };
                                              uint8_t id_434 { 0 };
                                              uint8_t id_435 { 0 };
                                              uint8_t id_436 { shft_ref_432[id_435] };
                                              uint8_t id_437 { 7 };
                                              uint8_t id_438 { uint8_t(id_436 + id_437) };
                                              Void id_439 { ((void)(shft_ref_432[id_434] = id_438), VOID) };
                                              uint8_t id_440 { 128 };
                                              bool id_441 { bool(leb128_fst_435 >= id_440) };
                                              letpair_res_420 = id_441;
                                            }
                                            let_res_419 = letpair_res_420;
                                          }
                                          while_flag_415 = let_res_419;
                                          if (while_flag_415) {
                                          }
                                        } while (while_flag_415);
                                        uint8_t id_442 { 0 };
                                        uint32_t id_443 { leb_ref_431[id_442] };
                                        Size id_444 { Size(id_443) };
                                        uint8_t id_445 { 0 };
                                        Pointer id_446 { p_ref_433[id_445] };
                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 id_447 {  id_444, id_446  };
                                        let_res_414 = id_447;
                                      }
                                      let_res_412 = let_res_414;
                                    }
                                    let_res_409 = let_res_412;
                                  }
                                  v_46a5e81c2410b000ff0adea6dc198147 let_res_448;
                                  {
                                    v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_437 { let_res_409 };
                                    v_46a5e81c2410b000ff0adea6dc198147 letpair_res_449;
                                    {
                                      auto dstring1_fst_438 { std::get<0>(dstring1_437) };
                                      auto dstring1_snd_439 { std::get<1>(dstring1_437) };
                                      f921d1e0a170c3c04148c21704db9c45 id_450 { dstring1_snd_439.readBytes(dstring1_fst_438) };
                                      v_46a5e81c2410b000ff0adea6dc198147 letpair_res_451;
                                      {
                                        auto dstring2_fst_441 { std::get<0>(id_450) };
                                        auto dstring2_snd_442 { std::get<1>(id_450) };
                                        std::string id_452 { dstring2_fst_441.toString() };
                                        v_46a5e81c2410b000ff0adea6dc198147 id_453 {  id_452, dstring2_snd_442  };
                                        letpair_res_451 = id_453;
                                      }
                                      letpair_res_449 = letpair_res_451;
                                    }
                                    let_res_448 = letpair_res_449;
                                  }
                                  e8a9e5263837de1dc85029fd46dec174 let_res_454;
                                  {
                                    v_46a5e81c2410b000ff0adea6dc198147 dtup_443 { let_res_448 };
                                    e8a9e5263837de1dc85029fd46dec174 letpair_res_455;
                                    {
                                      auto dtup_fst_444 { std::get<0>(dtup_443) };
                                      auto dtup_snd_445 { std::get<1>(dtup_443) };
                                      v_362f9d9108a6902af48b6c83d5377ea1 id_456 { dtup_snd_445.readU16Le() };
                                      v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_457;
                                      {
                                        auto du16_fst_447 { std::get<0>(id_456) };
                                        auto du16_snd_448 { std::get<1>(id_456) };
                                        v_362f9d9108a6902af48b6c83d5377ea1 id_458 {  du16_fst_447, du16_snd_448  };
                                        letpair_res_457 = id_458;
                                      }
                                      e8a9e5263837de1dc85029fd46dec174 let_res_459;
                                      {
                                        v_362f9d9108a6902af48b6c83d5377ea1 dsum1_452 { letpair_res_457 };
                                        e8a9e5263837de1dc85029fd46dec174 letpair_res_460;
                                        {
                                          auto dsum1_fst_453 { std::get<0>(dsum1_452) };
                                          auto dsum1_snd_454 { std::get<1>(dsum1_452) };
                                          uint16_t id_461 { 0 };
                                          bool id_462 { bool(dsum1_fst_453 == id_461) };
                                          Void id_463 { ((void)(assert(id_462)), VOID) };
                                          v_5c73eec19356406029ebc971f8fc93ef id_464 { std::in_place_index<0>, VOID };
                                          v_9a47b091ef9a7a446e50646760330664 id_465 {  dtup_fst_444, id_464  };
                                          v_320dee9bcc93c7ed0c75cc7db8b85d9b id_466 { std::in_place_index<3>, id_465 };
                                          e8a9e5263837de1dc85029fd46dec174 id_467 {  id_466, dsum1_snd_454  };
                                          letpair_res_460 = id_467;
                                        }
                                        let_res_459 = letpair_res_460;
                                      }
                                      letpair_res_455 = let_res_459;
                                    }
                                    let_res_454 = letpair_res_455;
                                  }
                                  choose_res_247 = let_res_454;
                                }
                                choose_res_176 = choose_res_247;
                              }
                              choose_res_171 = choose_res_176;
                            }
                            letpair_res_168 = choose_res_171;
                          }
                          let_res_167 = letpair_res_168;
                        }
                        f63f919559f0d70225bd0da5dd9bcafc letpair_res_468;
                        {
                          auto dtup_fst_603 { std::get<0>(let_res_167) };
                          auto dtup_snd_604 { std::get<1>(let_res_167) };
                          v_26540a608fe059393cc3cd282be43df3 id_469 {  dtup_fst_420, dtup_fst_603  };
                          t id_470 { std::in_place_index<5>, id_469 };
                          f63f919559f0d70225bd0da5dd9bcafc id_471 {  id_470, dtup_snd_604  };
                          letpair_res_468 = id_471;
                        }
                        letpair_res_163 = letpair_res_468;
                      }
                      let_res_162 = letpair_res_163;
                    }
                    choose_res_159 = let_res_162;
                  } else {
                    uint16_t id_472 { 6 };
                    bool id_473 { bool(id_472 == dsum1_fst_81) };
                    f63f919559f0d70225bd0da5dd9bcafc choose_res_474;
                    if (id_473) {
                      v_362f9d9108a6902af48b6c83d5377ea1 id_475 { dsum1_snd_82.readU16Le() };
                      v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_476;
                      {
                        auto du16_fst_387 { std::get<0>(id_475) };
                        auto du16_snd_388 { std::get<1>(id_475) };
                        v_362f9d9108a6902af48b6c83d5377ea1 id_477 {  du16_fst_387, du16_snd_388  };
                        letpair_res_476 = id_477;
                      }
                      f2650694962130b5d0ae4e3741f48a7a let_res_478;
                      {
                        v_362f9d9108a6902af48b6c83d5377ea1 dsum1_392 { letpair_res_476 };
                        f2650694962130b5d0ae4e3741f48a7a letpair_res_479;
                        {
                          auto dsum1_fst_393 { std::get<0>(dsum1_392) };
                          auto dsum1_snd_394 { std::get<1>(dsum1_392) };
                          uint16_t id_480 { 0 };
                          bool id_481 { bool(id_480 == dsum1_fst_393) };
                          f2650694962130b5d0ae4e3741f48a7a choose_res_482;
                          if (id_481) {
                            v_60ff76b761c62e00eb6df04e7d00fbc8 id_483 { std::in_place_index<0>, VOID };
                            f2650694962130b5d0ae4e3741f48a7a id_484 {  id_483, dsum1_snd_394  };
                            choose_res_482 = id_484;
                          } else {
                            uint16_t id_485 { 1 };
                            bool id_486 { bool(id_485 == dsum1_fst_393) };
                            f2650694962130b5d0ae4e3741f48a7a choose_res_487;
                            if (id_486) {
                              v_60ff76b761c62e00eb6df04e7d00fbc8 id_488 { std::in_place_index<1>, VOID };
                              f2650694962130b5d0ae4e3741f48a7a id_489 {  id_488, dsum1_snd_394  };
                              choose_res_487 = id_489;
                            } else {
                              uint16_t id_490 { 2 };
                              bool id_491 { bool(dsum1_fst_393 == id_490) };
                              Void id_492 { ((void)(assert(id_491)), VOID) };
                              uint32_t id_493 { 0U };
                              Vec<1, uint32_t> id_494 {  id_493  };
                              v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_495;
                              {
                                Vec<1, uint32_t> leb_ref_395 { id_494 };
                                uint8_t id_496 { 0 };
                                Vec<1, uint8_t> id_497 {  id_496  };
                                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_498;
                                {
                                  Vec<1, uint8_t> shft_ref_396 { id_497 };
                                  Vec<1, Pointer> id_499 {  dsum1_snd_394  };
                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_500;
                                  {
                                    Vec<1, Pointer> p_ref_397 { id_499 };
                                    bool while_flag_501 { true };
                                    do {
                                      uint8_t id_502 { 0 };
                                      Pointer id_503 { p_ref_397[id_502] };
                                      v_1d5843897434feb24d158f3793db9189 id_504 { id_503.readU8() };
                                      bool let_res_505;
                                      {
                                        v_1d5843897434feb24d158f3793db9189 leb128_398 { id_504 };
                                        bool letpair_res_506;
                                        {
                                          auto leb128_fst_399 { std::get<0>(leb128_398) };
                                          auto leb128_snd_400 { std::get<1>(leb128_398) };
                                          uint8_t id_507 { 0 };
                                          Void id_508 { ((void)(p_ref_397[id_507] = leb128_snd_400), VOID) };
                                          uint8_t id_509 { 0 };
                                          uint8_t id_510 { 127 };
                                          uint8_t id_511 { uint8_t(leb128_fst_399 & id_510) };
                                          uint32_t id_512 { uint32_t(id_511) };
                                          uint8_t id_513 { 0 };
                                          uint8_t id_514 { shft_ref_396[id_513] };
                                          uint32_t id_515 { uint32_t(id_512 << id_514) };
                                          uint8_t id_516 { 0 };
                                          uint32_t id_517 { leb_ref_395[id_516] };
                                          uint32_t id_518 { uint32_t(id_515 | id_517) };
                                          Void id_519 { ((void)(leb_ref_395[id_509] = id_518), VOID) };
                                          uint8_t id_520 { 0 };
                                          uint8_t id_521 { 0 };
                                          uint8_t id_522 { shft_ref_396[id_521] };
                                          uint8_t id_523 { 7 };
                                          uint8_t id_524 { uint8_t(id_522 + id_523) };
                                          Void id_525 { ((void)(shft_ref_396[id_520] = id_524), VOID) };
                                          uint8_t id_526 { 128 };
                                          bool id_527 { bool(leb128_fst_399 >= id_526) };
                                          letpair_res_506 = id_527;
                                        }
                                        let_res_505 = letpair_res_506;
                                      }
                                      while_flag_501 = let_res_505;
                                      if (while_flag_501) {
                                      }
                                    } while (while_flag_501);
                                    uint8_t id_528 { 0 };
                                    uint32_t id_529 { leb_ref_395[id_528] };
                                    Size id_530 { Size(id_529) };
                                    uint8_t id_531 { 0 };
                                    Pointer id_532 { p_ref_397[id_531] };
                                    v_41b0681ed7f1f185fd3e6c4dcdc13110 id_533 {  id_530, id_532  };
                                    let_res_500 = id_533;
                                  }
                                  let_res_498 = let_res_500;
                                }
                                let_res_495 = let_res_498;
                              }
                              f2650694962130b5d0ae4e3741f48a7a let_res_534;
                              {
                                v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_401 { let_res_495 };
                                f2650694962130b5d0ae4e3741f48a7a letpair_res_535;
                                {
                                  auto dstring1_fst_402 { std::get<0>(dstring1_401) };
                                  auto dstring1_snd_403 { std::get<1>(dstring1_401) };
                                  f921d1e0a170c3c04148c21704db9c45 id_536 { dstring1_snd_403.readBytes(dstring1_fst_402) };
                                  f2650694962130b5d0ae4e3741f48a7a letpair_res_537;
                                  {
                                    auto dstring2_fst_405 { std::get<0>(id_536) };
                                    auto dstring2_snd_406 { std::get<1>(id_536) };
                                    std::string id_538 { dstring2_fst_405.toString() };
                                    v_60ff76b761c62e00eb6df04e7d00fbc8 id_539 { std::in_place_index<2>, id_538 };
                                    f2650694962130b5d0ae4e3741f48a7a id_540 {  id_539, dstring2_snd_406  };
                                    letpair_res_537 = id_540;
                                  }
                                  letpair_res_535 = letpair_res_537;
                                }
                                let_res_534 = letpair_res_535;
                              }
                              choose_res_487 = let_res_534;
                            }
                            choose_res_482 = choose_res_487;
                          }
                          letpair_res_479 = choose_res_482;
                        }
                        let_res_478 = letpair_res_479;
                      }
                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_541;
                      {
                        auto dsum2_fst_417 { std::get<0>(let_res_478) };
                        auto dsum2_snd_418 { std::get<1>(let_res_478) };
                        t id_542 { std::in_place_index<6>, dsum2_fst_417 };
                        f63f919559f0d70225bd0da5dd9bcafc id_543 {  id_542, dsum2_snd_418  };
                        letpair_res_541 = id_543;
                      }
                      choose_res_474 = letpair_res_541;
                    } else {
                      uint16_t id_544 { 7 };
                      bool id_545 { bool(id_544 == dsum1_fst_81) };
                      f63f919559f0d70225bd0da5dd9bcafc choose_res_546;
                      if (id_545) {
                        std::function<ddf7cb48181332ead2f60a5f4bb1a8de(Pointer)> id_547 { dessser_gen::site_name.of_row_binary };
                        ddf7cb48181332ead2f60a5f4bb1a8de id_548 { id_547(dsum1_snd_82) };
                        f63f919559f0d70225bd0da5dd9bcafc let_res_549;
                        {
                          ddf7cb48181332ead2f60a5f4bb1a8de dtup_329 { id_548 };
                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_550;
                          {
                            auto dtup_fst_330 { std::get<0>(dtup_329) };
                            auto dtup_snd_331 { std::get<1>(dtup_329) };
                            std::function<v_41ac8303016d6ac19fef26d484dd5164(Pointer)> id_551 { dessser_gen::fq_name.of_row_binary };
                            v_41ac8303016d6ac19fef26d484dd5164 id_552 { id_551(dtup_snd_331) };
                            f63f919559f0d70225bd0da5dd9bcafc let_res_553;
                            {
                              v_41ac8303016d6ac19fef26d484dd5164 dtup_332 { id_552 };
                              f63f919559f0d70225bd0da5dd9bcafc letpair_res_554;
                              {
                                auto dtup_fst_333 { std::get<0>(dtup_332) };
                                auto dtup_snd_334 { std::get<1>(dtup_332) };
                                uint32_t id_555 { 0U };
                                Vec<1, uint32_t> id_556 {  id_555  };
                                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_557;
                                {
                                  Vec<1, uint32_t> leb_ref_335 { id_556 };
                                  uint8_t id_558 { 0 };
                                  Vec<1, uint8_t> id_559 {  id_558  };
                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_560;
                                  {
                                    Vec<1, uint8_t> shft_ref_336 { id_559 };
                                    Vec<1, Pointer> id_561 {  dtup_snd_334  };
                                    v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_562;
                                    {
                                      Vec<1, Pointer> p_ref_337 { id_561 };
                                      bool while_flag_563 { true };
                                      do {
                                        uint8_t id_564 { 0 };
                                        Pointer id_565 { p_ref_337[id_564] };
                                        v_1d5843897434feb24d158f3793db9189 id_566 { id_565.readU8() };
                                        bool let_res_567;
                                        {
                                          v_1d5843897434feb24d158f3793db9189 leb128_338 { id_566 };
                                          bool letpair_res_568;
                                          {
                                            auto leb128_fst_339 { std::get<0>(leb128_338) };
                                            auto leb128_snd_340 { std::get<1>(leb128_338) };
                                            uint8_t id_569 { 0 };
                                            Void id_570 { ((void)(p_ref_337[id_569] = leb128_snd_340), VOID) };
                                            uint8_t id_571 { 0 };
                                            uint8_t id_572 { 127 };
                                            uint8_t id_573 { uint8_t(leb128_fst_339 & id_572) };
                                            uint32_t id_574 { uint32_t(id_573) };
                                            uint8_t id_575 { 0 };
                                            uint8_t id_576 { shft_ref_336[id_575] };
                                            uint32_t id_577 { uint32_t(id_574 << id_576) };
                                            uint8_t id_578 { 0 };
                                            uint32_t id_579 { leb_ref_335[id_578] };
                                            uint32_t id_580 { uint32_t(id_577 | id_579) };
                                            Void id_581 { ((void)(leb_ref_335[id_571] = id_580), VOID) };
                                            uint8_t id_582 { 0 };
                                            uint8_t id_583 { 0 };
                                            uint8_t id_584 { shft_ref_336[id_583] };
                                            uint8_t id_585 { 7 };
                                            uint8_t id_586 { uint8_t(id_584 + id_585) };
                                            Void id_587 { ((void)(shft_ref_336[id_582] = id_586), VOID) };
                                            uint8_t id_588 { 128 };
                                            bool id_589 { bool(leb128_fst_339 >= id_588) };
                                            letpair_res_568 = id_589;
                                          }
                                          let_res_567 = letpair_res_568;
                                        }
                                        while_flag_563 = let_res_567;
                                        if (while_flag_563) {
                                        }
                                      } while (while_flag_563);
                                      uint8_t id_590 { 0 };
                                      uint32_t id_591 { leb_ref_335[id_590] };
                                      Size id_592 { Size(id_591) };
                                      uint8_t id_593 { 0 };
                                      Pointer id_594 { p_ref_337[id_593] };
                                      v_41b0681ed7f1f185fd3e6c4dcdc13110 id_595 {  id_592, id_594  };
                                      let_res_562 = id_595;
                                    }
                                    let_res_560 = let_res_562;
                                  }
                                  let_res_557 = let_res_560;
                                }
                                v_46a5e81c2410b000ff0adea6dc198147 let_res_596;
                                {
                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_341 { let_res_557 };
                                  v_46a5e81c2410b000ff0adea6dc198147 letpair_res_597;
                                  {
                                    auto dstring1_fst_342 { std::get<0>(dstring1_341) };
                                    auto dstring1_snd_343 { std::get<1>(dstring1_341) };
                                    f921d1e0a170c3c04148c21704db9c45 id_598 { dstring1_snd_343.readBytes(dstring1_fst_342) };
                                    v_46a5e81c2410b000ff0adea6dc198147 letpair_res_599;
                                    {
                                      auto dstring2_fst_345 { std::get<0>(id_598) };
                                      auto dstring2_snd_346 { std::get<1>(id_598) };
                                      std::string id_600 { dstring2_fst_345.toString() };
                                      v_46a5e81c2410b000ff0adea6dc198147 id_601 {  id_600, dstring2_snd_346  };
                                      letpair_res_599 = id_601;
                                    }
                                    letpair_res_597 = letpair_res_599;
                                  }
                                  let_res_596 = letpair_res_597;
                                }
                                f63f919559f0d70225bd0da5dd9bcafc let_res_602;
                                {
                                  v_46a5e81c2410b000ff0adea6dc198147 dtup_347 { let_res_596 };
                                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_603;
                                  {
                                    auto dtup_fst_348 { std::get<0>(dtup_347) };
                                    auto dtup_snd_349 { std::get<1>(dtup_347) };
                                    v_362f9d9108a6902af48b6c83d5377ea1 id_604 { dtup_snd_349.readU16Le() };
                                    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_605;
                                    {
                                      auto du16_fst_351 { std::get<0>(id_604) };
                                      auto du16_snd_352 { std::get<1>(id_604) };
                                      v_362f9d9108a6902af48b6c83d5377ea1 id_606 {  du16_fst_351, du16_snd_352  };
                                      letpair_res_605 = id_606;
                                    }
                                    ac0dff677d9c1c0e84201364a0cada0d let_res_607;
                                    {
                                      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_356 { letpair_res_605 };
                                      ac0dff677d9c1c0e84201364a0cada0d letpair_res_608;
                                      {
                                        auto dsum1_fst_357 { std::get<0>(dsum1_356) };
                                        auto dsum1_snd_358 { std::get<1>(dsum1_356) };
                                        uint16_t id_609 { 0 };
                                        bool id_610 { bool(id_609 == dsum1_fst_357) };
                                        ac0dff677d9c1c0e84201364a0cada0d choose_res_611;
                                        if (id_610) {
                                          uint32_t id_612 { 0U };
                                          Vec<1, uint32_t> id_613 {  id_612  };
                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_614;
                                          {
                                            Vec<1, uint32_t> leb_ref_365 { id_613 };
                                            uint8_t id_615 { 0 };
                                            Vec<1, uint8_t> id_616 {  id_615  };
                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_617;
                                            {
                                              Vec<1, uint8_t> shft_ref_366 { id_616 };
                                              Vec<1, Pointer> id_618 {  dsum1_snd_358  };
                                              v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_619;
                                              {
                                                Vec<1, Pointer> p_ref_367 { id_618 };
                                                bool while_flag_620 { true };
                                                do {
                                                  uint8_t id_621 { 0 };
                                                  Pointer id_622 { p_ref_367[id_621] };
                                                  v_1d5843897434feb24d158f3793db9189 id_623 { id_622.readU8() };
                                                  bool let_res_624;
                                                  {
                                                    v_1d5843897434feb24d158f3793db9189 leb128_368 { id_623 };
                                                    bool letpair_res_625;
                                                    {
                                                      auto leb128_fst_369 { std::get<0>(leb128_368) };
                                                      auto leb128_snd_370 { std::get<1>(leb128_368) };
                                                      uint8_t id_626 { 0 };
                                                      Void id_627 { ((void)(p_ref_367[id_626] = leb128_snd_370), VOID) };
                                                      uint8_t id_628 { 0 };
                                                      uint8_t id_629 { 127 };
                                                      uint8_t id_630 { uint8_t(leb128_fst_369 & id_629) };
                                                      uint32_t id_631 { uint32_t(id_630) };
                                                      uint8_t id_632 { 0 };
                                                      uint8_t id_633 { shft_ref_366[id_632] };
                                                      uint32_t id_634 { uint32_t(id_631 << id_633) };
                                                      uint8_t id_635 { 0 };
                                                      uint32_t id_636 { leb_ref_365[id_635] };
                                                      uint32_t id_637 { uint32_t(id_634 | id_636) };
                                                      Void id_638 { ((void)(leb_ref_365[id_628] = id_637), VOID) };
                                                      uint8_t id_639 { 0 };
                                                      uint8_t id_640 { 0 };
                                                      uint8_t id_641 { shft_ref_366[id_640] };
                                                      uint8_t id_642 { 7 };
                                                      uint8_t id_643 { uint8_t(id_641 + id_642) };
                                                      Void id_644 { ((void)(shft_ref_366[id_639] = id_643), VOID) };
                                                      uint8_t id_645 { 128 };
                                                      bool id_646 { bool(leb128_fst_369 >= id_645) };
                                                      letpair_res_625 = id_646;
                                                    }
                                                    let_res_624 = letpair_res_625;
                                                  }
                                                  while_flag_620 = let_res_624;
                                                  if (while_flag_620) {
                                                  }
                                                } while (while_flag_620);
                                                uint8_t id_647 { 0 };
                                                uint32_t id_648 { leb_ref_365[id_647] };
                                                Size id_649 { Size(id_648) };
                                                uint8_t id_650 { 0 };
                                                Pointer id_651 { p_ref_367[id_650] };
                                                v_41b0681ed7f1f185fd3e6c4dcdc13110 id_652 {  id_649, id_651  };
                                                let_res_619 = id_652;
                                              }
                                              let_res_617 = let_res_619;
                                            }
                                            let_res_614 = let_res_617;
                                          }
                                          ac0dff677d9c1c0e84201364a0cada0d let_res_653;
                                          {
                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_371 { let_res_614 };
                                            ac0dff677d9c1c0e84201364a0cada0d letpair_res_654;
                                            {
                                              auto dstring1_fst_372 { std::get<0>(dstring1_371) };
                                              auto dstring1_snd_373 { std::get<1>(dstring1_371) };
                                              f921d1e0a170c3c04148c21704db9c45 id_655 { dstring1_snd_373.readBytes(dstring1_fst_372) };
                                              ac0dff677d9c1c0e84201364a0cada0d letpair_res_656;
                                              {
                                                auto dstring2_fst_375 { std::get<0>(id_655) };
                                                auto dstring2_snd_376 { std::get<1>(id_655) };
                                                std::string id_657 { dstring2_fst_375.toString() };
                                                v_6c1c7418355e363a303990cad40945dd id_658 { std::in_place_index<0>, id_657 };
                                                ac0dff677d9c1c0e84201364a0cada0d id_659 {  id_658, dstring2_snd_376  };
                                                letpair_res_656 = id_659;
                                              }
                                              letpair_res_654 = letpair_res_656;
                                            }
                                            let_res_653 = letpair_res_654;
                                          }
                                          choose_res_611 = let_res_653;
                                        } else {
                                          uint16_t id_660 { 1 };
                                          bool id_661 { bool(dsum1_fst_357 == id_660) };
                                          Void id_662 { ((void)(assert(id_661)), VOID) };
                                          ac0fbd05039f742d2f1d9ac182e392ab id_663 { dsum1_snd_358.readU32Le() };
                                          ac0dff677d9c1c0e84201364a0cada0d letpair_res_664;
                                          {
                                            auto du32_fst_360 { std::get<0>(id_663) };
                                            auto du32_snd_361 { std::get<1>(id_663) };
                                            v_6c1c7418355e363a303990cad40945dd id_665 { std::in_place_index<1>, du32_fst_360 };
                                            ac0dff677d9c1c0e84201364a0cada0d id_666 {  id_665, du32_snd_361  };
                                            letpair_res_664 = id_666;
                                          }
                                          choose_res_611 = letpair_res_664;
                                        }
                                        letpair_res_608 = choose_res_611;
                                      }
                                      let_res_607 = letpair_res_608;
                                    }
                                    f63f919559f0d70225bd0da5dd9bcafc letpair_res_667;
                                    {
                                      auto dtup_fst_381 { std::get<0>(let_res_607) };
                                      auto dtup_snd_382 { std::get<1>(let_res_607) };
                                      v_3a6e990115d17bf3eefa1b91b13ca80b id_668 {  dtup_fst_330, dtup_fst_333, dtup_fst_348, dtup_fst_381  };
                                      t id_669 { std::in_place_index<7>, id_668 };
                                      f63f919559f0d70225bd0da5dd9bcafc id_670 {  id_669, dtup_snd_382  };
                                      letpair_res_667 = id_670;
                                    }
                                    letpair_res_603 = letpair_res_667;
                                  }
                                  let_res_602 = letpair_res_603;
                                }
                                letpair_res_554 = let_res_602;
                              }
                              let_res_553 = letpair_res_554;
                            }
                            letpair_res_550 = let_res_553;
                          }
                          let_res_549 = letpair_res_550;
                        }
                        choose_res_546 = let_res_549;
                      } else {
                        uint16_t id_671 { 8 };
                        bool id_672 { bool(id_671 == dsum1_fst_81) };
                        f63f919559f0d70225bd0da5dd9bcafc choose_res_673;
                        if (id_672) {
                          v_362f9d9108a6902af48b6c83d5377ea1 id_674 { dsum1_snd_82.readU16Le() };
                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_675;
                          {
                            auto du16_fst_324 { std::get<0>(id_674) };
                            auto du16_snd_325 { std::get<1>(id_674) };
                            t id_676 { std::in_place_index<8>, du16_fst_324 };
                            f63f919559f0d70225bd0da5dd9bcafc id_677 {  id_676, du16_snd_325  };
                            letpair_res_675 = id_677;
                          }
                          choose_res_673 = letpair_res_675;
                        } else {
                          uint16_t id_678 { 9 };
                          bool id_679 { bool(id_678 == dsum1_fst_81) };
                          f63f919559f0d70225bd0da5dd9bcafc choose_res_680;
                          if (id_679) {
                            Size id_681 { 0UL };
                            uint8_t id_682 { dsum1_snd_82.peekU8(id_681) };
                            uint8_t id_683 { 1 };
                            bool id_684 { bool(id_682 == id_683) };
                            v_13905691a95334749d572078b5658ba9 choose_res_685;
                            if (id_684) {
                              std::optional<*sync_socket> id_686 { std::nullopt };
                              Size id_687 { 1UL };
                              Pointer id_688 { dsum1_snd_82.skip(id_687) };
                              v_13905691a95334749d572078b5658ba9 id_689 {  id_686, id_688  };
                              choose_res_685 = id_689;
                            } else {
                              std::function<v_7036a8b0fbd8a7ca699aed2c44f6fdba(Pointer)> id_690 { dessser_gen::sync_socket.of_row_binary };
                              Size id_691 { 1UL };
                              Pointer id_692 { dsum1_snd_82.skip(id_691) };
                              v_7036a8b0fbd8a7ca699aed2c44f6fdba id_693 { id_690(id_692) };
                              v_13905691a95334749d572078b5658ba9 letpair_res_694;
                              {
                                auto make1_1_fst_318 { std::get<0>(id_693) };
                                auto make1_1_snd_319 { std::get<1>(id_693) };
                                std::optional<*sync_socket> id_695 { make1_1_fst_318 };
                                v_13905691a95334749d572078b5658ba9 id_696 {  id_695, make1_1_snd_319  };
                                letpair_res_694 = id_696;
                              }
                              choose_res_685 = letpair_res_694;
                            }
                            f63f919559f0d70225bd0da5dd9bcafc letpair_res_697;
                            {
                              auto dsum2_fst_321 { std::get<0>(choose_res_685) };
                              auto dsum2_snd_322 { std::get<1>(choose_res_685) };
                              t id_698 { std::in_place_index<9>, dsum2_fst_321 };
                              f63f919559f0d70225bd0da5dd9bcafc id_699 {  id_698, dsum2_snd_322  };
                              letpair_res_697 = id_699;
                            }
                            choose_res_680 = letpair_res_697;
                          } else {
                            uint16_t id_700 { 10 };
                            bool id_701 { bool(id_700 == dsum1_fst_81) };
                            f63f919559f0d70225bd0da5dd9bcafc choose_res_702;
                            if (id_701) {
                              t id_703 { std::in_place_index<10>, VOID };
                              f63f919559f0d70225bd0da5dd9bcafc id_704 {  id_703, dsum1_snd_82  };
                              choose_res_702 = id_704;
                            } else {
                              uint16_t id_705 { 11 };
                              bool id_706 { bool(id_705 == dsum1_fst_81) };
                              f63f919559f0d70225bd0da5dd9bcafc choose_res_707;
                              if (id_706) {
                                std::function<v_7036a8b0fbd8a7ca699aed2c44f6fdba(Pointer)> id_708 { dessser_gen::sync_socket.of_row_binary };
                                v_7036a8b0fbd8a7ca699aed2c44f6fdba id_709 { id_708(dsum1_snd_82) };
                                f63f919559f0d70225bd0da5dd9bcafc let_res_710;
                                {
                                  v_7036a8b0fbd8a7ca699aed2c44f6fdba dtup_278 { id_709 };
                                  f63f919559f0d70225bd0da5dd9bcafc letpair_res_711;
                                  {
                                    auto dtup_fst_279 { std::get<0>(dtup_278) };
                                    auto dtup_snd_280 { std::get<1>(dtup_278) };
                                    v_362f9d9108a6902af48b6c83d5377ea1 id_712 { dtup_snd_280.readU16Le() };
                                    v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_713;
                                    {
                                      auto du16_fst_282 { std::get<0>(id_712) };
                                      auto du16_snd_283 { std::get<1>(id_712) };
                                      v_362f9d9108a6902af48b6c83d5377ea1 id_714 {  du16_fst_282, du16_snd_283  };
                                      letpair_res_713 = id_714;
                                    }
                                    a04ac0febaa7b7d9805cb5bfd0d5cb07 let_res_715;
                                    {
                                      v_362f9d9108a6902af48b6c83d5377ea1 dsum1_287 { letpair_res_713 };
                                      a04ac0febaa7b7d9805cb5bfd0d5cb07 letpair_res_716;
                                      {
                                        auto dsum1_fst_288 { std::get<0>(dsum1_287) };
                                        auto dsum1_snd_289 { std::get<1>(dsum1_287) };
                                        uint16_t id_717 { 0 };
                                        bool id_718 { bool(id_717 == dsum1_fst_288) };
                                        a04ac0febaa7b7d9805cb5bfd0d5cb07 choose_res_719;
                                        if (id_718) {
                                          uint32_t id_720 { 0U };
                                          Vec<1, uint32_t> id_721 {  id_720  };
                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_722;
                                          {
                                            Vec<1, uint32_t> leb_ref_293 { id_721 };
                                            uint8_t id_723 { 0 };
                                            Vec<1, uint8_t> id_724 {  id_723  };
                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_725;
                                            {
                                              Vec<1, uint8_t> shft_ref_294 { id_724 };
                                              Vec<1, Pointer> id_726 {  dsum1_snd_289  };
                                              v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_727;
                                              {
                                                Vec<1, Pointer> p_ref_295 { id_726 };
                                                bool while_flag_728 { true };
                                                do {
                                                  uint8_t id_729 { 0 };
                                                  Pointer id_730 { p_ref_295[id_729] };
                                                  v_1d5843897434feb24d158f3793db9189 id_731 { id_730.readU8() };
                                                  bool let_res_732;
                                                  {
                                                    v_1d5843897434feb24d158f3793db9189 leb128_296 { id_731 };
                                                    bool letpair_res_733;
                                                    {
                                                      auto leb128_fst_297 { std::get<0>(leb128_296) };
                                                      auto leb128_snd_298 { std::get<1>(leb128_296) };
                                                      uint8_t id_734 { 0 };
                                                      Void id_735 { ((void)(p_ref_295[id_734] = leb128_snd_298), VOID) };
                                                      uint8_t id_736 { 0 };
                                                      uint8_t id_737 { 127 };
                                                      uint8_t id_738 { uint8_t(leb128_fst_297 & id_737) };
                                                      uint32_t id_739 { uint32_t(id_738) };
                                                      uint8_t id_740 { 0 };
                                                      uint8_t id_741 { shft_ref_294[id_740] };
                                                      uint32_t id_742 { uint32_t(id_739 << id_741) };
                                                      uint8_t id_743 { 0 };
                                                      uint32_t id_744 { leb_ref_293[id_743] };
                                                      uint32_t id_745 { uint32_t(id_742 | id_744) };
                                                      Void id_746 { ((void)(leb_ref_293[id_736] = id_745), VOID) };
                                                      uint8_t id_747 { 0 };
                                                      uint8_t id_748 { 0 };
                                                      uint8_t id_749 { shft_ref_294[id_748] };
                                                      uint8_t id_750 { 7 };
                                                      uint8_t id_751 { uint8_t(id_749 + id_750) };
                                                      Void id_752 { ((void)(shft_ref_294[id_747] = id_751), VOID) };
                                                      uint8_t id_753 { 128 };
                                                      bool id_754 { bool(leb128_fst_297 >= id_753) };
                                                      letpair_res_733 = id_754;
                                                    }
                                                    let_res_732 = letpair_res_733;
                                                  }
                                                  while_flag_728 = let_res_732;
                                                  if (while_flag_728) {
                                                  }
                                                } while (while_flag_728);
                                                uint8_t id_755 { 0 };
                                                uint32_t id_756 { leb_ref_293[id_755] };
                                                Size id_757 { Size(id_756) };
                                                uint8_t id_758 { 0 };
                                                Pointer id_759 { p_ref_295[id_758] };
                                                v_41b0681ed7f1f185fd3e6c4dcdc13110 id_760 {  id_757, id_759  };
                                                let_res_727 = id_760;
                                              }
                                              let_res_725 = let_res_727;
                                            }
                                            let_res_722 = let_res_725;
                                          }
                                          a04ac0febaa7b7d9805cb5bfd0d5cb07 let_res_761;
                                          {
                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_299 { let_res_722 };
                                            a04ac0febaa7b7d9805cb5bfd0d5cb07 letpair_res_762;
                                            {
                                              auto dstring1_fst_300 { std::get<0>(dstring1_299) };
                                              auto dstring1_snd_301 { std::get<1>(dstring1_299) };
                                              f921d1e0a170c3c04148c21704db9c45 id_763 { dstring1_snd_301.readBytes(dstring1_fst_300) };
                                              a04ac0febaa7b7d9805cb5bfd0d5cb07 letpair_res_764;
                                              {
                                                auto dstring2_fst_303 { std::get<0>(id_763) };
                                                auto dstring2_snd_304 { std::get<1>(id_763) };
                                                std::string id_765 { dstring2_fst_303.toString() };
                                                v_90e4213e12fd850ebf8d15b08342b17e id_766 { std::in_place_index<0>, id_765 };
                                                a04ac0febaa7b7d9805cb5bfd0d5cb07 id_767 {  id_766, dstring2_snd_304  };
                                                letpair_res_764 = id_767;
                                              }
                                              letpair_res_762 = letpair_res_764;
                                            }
                                            let_res_761 = letpair_res_762;
                                          }
                                          choose_res_719 = let_res_761;
                                        } else {
                                          uint16_t id_768 { 1 };
                                          bool id_769 { bool(dsum1_fst_288 == id_768) };
                                          Void id_770 { ((void)(assert(id_769)), VOID) };
                                          bb7a1af56c56ee3850e41d7e7bbfd8d3 id_771 { per_dash_key_of_row_binary(dsum1_snd_289) };
                                          a04ac0febaa7b7d9805cb5bfd0d5cb07 letpair_res_772;
                                          {
                                            auto dsum2_fst_291 { std::get<0>(id_771) };
                                            auto dsum2_snd_292 { std::get<1>(id_771) };
                                            v_90e4213e12fd850ebf8d15b08342b17e id_773 { std::in_place_index<1>, dsum2_fst_291 };
                                            a04ac0febaa7b7d9805cb5bfd0d5cb07 id_774 {  id_773, dsum2_snd_292  };
                                            letpair_res_772 = id_774;
                                          }
                                          choose_res_719 = letpair_res_772;
                                        }
                                        letpair_res_716 = choose_res_719;
                                      }
                                      let_res_715 = letpair_res_716;
                                    }
                                    f63f919559f0d70225bd0da5dd9bcafc letpair_res_775;
                                    {
                                      auto dtup_fst_309 { std::get<0>(let_res_715) };
                                      auto dtup_snd_310 { std::get<1>(let_res_715) };
                                      v_287d43b770d826e060b1e65a4d07e0b0 id_776 {  dtup_fst_279, dtup_fst_309  };
                                      t id_777 { std::in_place_index<11>, id_776 };
                                      f63f919559f0d70225bd0da5dd9bcafc id_778 {  id_777, dtup_snd_310  };
                                      letpair_res_775 = id_778;
                                    }
                                    letpair_res_711 = letpair_res_775;
                                  }
                                  let_res_710 = letpair_res_711;
                                }
                                choose_res_707 = let_res_710;
                              } else {
                                uint16_t id_779 { 12 };
                                bool id_780 { bool(id_779 == dsum1_fst_81) };
                                f63f919559f0d70225bd0da5dd9bcafc choose_res_781;
                                if (id_780) {
                                  uint32_t id_782 { 0U };
                                  Vec<1, uint32_t> id_783 {  id_782  };
                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_784;
                                  {
                                    Vec<1, uint32_t> leb_ref_257 { id_783 };
                                    uint8_t id_785 { 0 };
                                    Vec<1, uint8_t> id_786 {  id_785  };
                                    v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_787;
                                    {
                                      Vec<1, uint8_t> shft_ref_258 { id_786 };
                                      Vec<1, Pointer> id_788 {  dsum1_snd_82  };
                                      v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_789;
                                      {
                                        Vec<1, Pointer> p_ref_259 { id_788 };
                                        bool while_flag_790 { true };
                                        do {
                                          uint8_t id_791 { 0 };
                                          Pointer id_792 { p_ref_259[id_791] };
                                          v_1d5843897434feb24d158f3793db9189 id_793 { id_792.readU8() };
                                          bool let_res_794;
                                          {
                                            v_1d5843897434feb24d158f3793db9189 leb128_260 { id_793 };
                                            bool letpair_res_795;
                                            {
                                              auto leb128_fst_261 { std::get<0>(leb128_260) };
                                              auto leb128_snd_262 { std::get<1>(leb128_260) };
                                              uint8_t id_796 { 0 };
                                              Void id_797 { ((void)(p_ref_259[id_796] = leb128_snd_262), VOID) };
                                              uint8_t id_798 { 0 };
                                              uint8_t id_799 { 127 };
                                              uint8_t id_800 { uint8_t(leb128_fst_261 & id_799) };
                                              uint32_t id_801 { uint32_t(id_800) };
                                              uint8_t id_802 { 0 };
                                              uint8_t id_803 { shft_ref_258[id_802] };
                                              uint32_t id_804 { uint32_t(id_801 << id_803) };
                                              uint8_t id_805 { 0 };
                                              uint32_t id_806 { leb_ref_257[id_805] };
                                              uint32_t id_807 { uint32_t(id_804 | id_806) };
                                              Void id_808 { ((void)(leb_ref_257[id_798] = id_807), VOID) };
                                              uint8_t id_809 { 0 };
                                              uint8_t id_810 { 0 };
                                              uint8_t id_811 { shft_ref_258[id_810] };
                                              uint8_t id_812 { 7 };
                                              uint8_t id_813 { uint8_t(id_811 + id_812) };
                                              Void id_814 { ((void)(shft_ref_258[id_809] = id_813), VOID) };
                                              uint8_t id_815 { 128 };
                                              bool id_816 { bool(leb128_fst_261 >= id_815) };
                                              letpair_res_795 = id_816;
                                            }
                                            let_res_794 = letpair_res_795;
                                          }
                                          while_flag_790 = let_res_794;
                                          if (while_flag_790) {
                                          }
                                        } while (while_flag_790);
                                        uint8_t id_817 { 0 };
                                        uint32_t id_818 { leb_ref_257[id_817] };
                                        Size id_819 { Size(id_818) };
                                        uint8_t id_820 { 0 };
                                        Pointer id_821 { p_ref_259[id_820] };
                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 id_822 {  id_819, id_821  };
                                        let_res_789 = id_822;
                                      }
                                      let_res_787 = let_res_789;
                                    }
                                    let_res_784 = let_res_787;
                                  }
                                  v_46a5e81c2410b000ff0adea6dc198147 let_res_823;
                                  {
                                    v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_263 { let_res_784 };
                                    v_46a5e81c2410b000ff0adea6dc198147 letpair_res_824;
                                    {
                                      auto dstring1_fst_264 { std::get<0>(dstring1_263) };
                                      auto dstring1_snd_265 { std::get<1>(dstring1_263) };
                                      f921d1e0a170c3c04148c21704db9c45 id_825 { dstring1_snd_265.readBytes(dstring1_fst_264) };
                                      v_46a5e81c2410b000ff0adea6dc198147 letpair_res_826;
                                      {
                                        auto dstring2_fst_267 { std::get<0>(id_825) };
                                        auto dstring2_snd_268 { std::get<1>(id_825) };
                                        std::string id_827 { dstring2_fst_267.toString() };
                                        v_46a5e81c2410b000ff0adea6dc198147 id_828 {  id_827, dstring2_snd_268  };
                                        letpair_res_826 = id_828;
                                      }
                                      letpair_res_824 = letpair_res_826;
                                    }
                                    let_res_823 = letpair_res_824;
                                  }
                                  f63f919559f0d70225bd0da5dd9bcafc let_res_829;
                                  {
                                    v_46a5e81c2410b000ff0adea6dc198147 dtup_269 { let_res_823 };
                                    f63f919559f0d70225bd0da5dd9bcafc letpair_res_830;
                                    {
                                      auto dtup_fst_270 { std::get<0>(dtup_269) };
                                      auto dtup_snd_271 { std::get<1>(dtup_269) };
                                      bb7a1af56c56ee3850e41d7e7bbfd8d3 id_831 { per_dash_key_of_row_binary(dtup_snd_271) };
                                      f63f919559f0d70225bd0da5dd9bcafc letpair_res_832;
                                      {
                                        auto dtup_fst_273 { std::get<0>(id_831) };
                                        auto dtup_snd_274 { std::get<1>(id_831) };
                                        ea82132cbdaf05c9cc56869f7b4529c3 id_833 {  dtup_fst_270, dtup_fst_273  };
                                        t id_834 { std::in_place_index<12>, id_833 };
                                        f63f919559f0d70225bd0da5dd9bcafc id_835 {  id_834, dtup_snd_274  };
                                        letpair_res_832 = id_835;
                                      }
                                      letpair_res_830 = letpair_res_832;
                                    }
                                    let_res_829 = letpair_res_830;
                                  }
                                  choose_res_781 = let_res_829;
                                } else {
                                  uint16_t id_836 { 13 };
                                  bool id_837 { bool(id_836 == dsum1_fst_81) };
                                  f63f919559f0d70225bd0da5dd9bcafc choose_res_838;
                                  if (id_837) {
                                    t id_839 { std::in_place_index<13>, VOID };
                                    f63f919559f0d70225bd0da5dd9bcafc id_840 {  id_839, dsum1_snd_82  };
                                    choose_res_838 = id_840;
                                  } else {
                                    uint16_t id_841 { 14 };
                                    bool id_842 { bool(id_841 == dsum1_fst_81) };
                                    f63f919559f0d70225bd0da5dd9bcafc choose_res_843;
                                    if (id_842) {
                                      uint32_t id_844 { 0U };
                                      Vec<1, uint32_t> id_845 {  id_844  };
                                      v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_846;
                                      {
                                        Vec<1, uint32_t> leb_ref_194 { id_845 };
                                        uint8_t id_847 { 0 };
                                        Vec<1, uint8_t> id_848 {  id_847  };
                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_849;
                                        {
                                          Vec<1, uint8_t> shft_ref_195 { id_848 };
                                          Vec<1, Pointer> id_850 {  dsum1_snd_82  };
                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_851;
                                          {
                                            Vec<1, Pointer> p_ref_196 { id_850 };
                                            bool while_flag_852 { true };
                                            do {
                                              uint8_t id_853 { 0 };
                                              Pointer id_854 { p_ref_196[id_853] };
                                              v_1d5843897434feb24d158f3793db9189 id_855 { id_854.readU8() };
                                              bool let_res_856;
                                              {
                                                v_1d5843897434feb24d158f3793db9189 leb128_197 { id_855 };
                                                bool letpair_res_857;
                                                {
                                                  auto leb128_fst_198 { std::get<0>(leb128_197) };
                                                  auto leb128_snd_199 { std::get<1>(leb128_197) };
                                                  uint8_t id_858 { 0 };
                                                  Void id_859 { ((void)(p_ref_196[id_858] = leb128_snd_199), VOID) };
                                                  uint8_t id_860 { 0 };
                                                  uint8_t id_861 { 127 };
                                                  uint8_t id_862 { uint8_t(leb128_fst_198 & id_861) };
                                                  uint32_t id_863 { uint32_t(id_862) };
                                                  uint8_t id_864 { 0 };
                                                  uint8_t id_865 { shft_ref_195[id_864] };
                                                  uint32_t id_866 { uint32_t(id_863 << id_865) };
                                                  uint8_t id_867 { 0 };
                                                  uint32_t id_868 { leb_ref_194[id_867] };
                                                  uint32_t id_869 { uint32_t(id_866 | id_868) };
                                                  Void id_870 { ((void)(leb_ref_194[id_860] = id_869), VOID) };
                                                  uint8_t id_871 { 0 };
                                                  uint8_t id_872 { 0 };
                                                  uint8_t id_873 { shft_ref_195[id_872] };
                                                  uint8_t id_874 { 7 };
                                                  uint8_t id_875 { uint8_t(id_873 + id_874) };
                                                  Void id_876 { ((void)(shft_ref_195[id_871] = id_875), VOID) };
                                                  uint8_t id_877 { 128 };
                                                  bool id_878 { bool(leb128_fst_198 >= id_877) };
                                                  letpair_res_857 = id_878;
                                                }
                                                let_res_856 = letpair_res_857;
                                              }
                                              while_flag_852 = let_res_856;
                                              if (while_flag_852) {
                                              }
                                            } while (while_flag_852);
                                            uint8_t id_879 { 0 };
                                            uint32_t id_880 { leb_ref_194[id_879] };
                                            Size id_881 { Size(id_880) };
                                            uint8_t id_882 { 0 };
                                            Pointer id_883 { p_ref_196[id_882] };
                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 id_884 {  id_881, id_883  };
                                            let_res_851 = id_884;
                                          }
                                          let_res_849 = let_res_851;
                                        }
                                        let_res_846 = let_res_849;
                                      }
                                      v_46a5e81c2410b000ff0adea6dc198147 let_res_885;
                                      {
                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_200 { let_res_846 };
                                        v_46a5e81c2410b000ff0adea6dc198147 letpair_res_886;
                                        {
                                          auto dstring1_fst_201 { std::get<0>(dstring1_200) };
                                          auto dstring1_snd_202 { std::get<1>(dstring1_200) };
                                          f921d1e0a170c3c04148c21704db9c45 id_887 { dstring1_snd_202.readBytes(dstring1_fst_201) };
                                          v_46a5e81c2410b000ff0adea6dc198147 letpair_res_888;
                                          {
                                            auto dstring2_fst_204 { std::get<0>(id_887) };
                                            auto dstring2_snd_205 { std::get<1>(id_887) };
                                            std::string id_889 { dstring2_fst_204.toString() };
                                            v_46a5e81c2410b000ff0adea6dc198147 id_890 {  id_889, dstring2_snd_205  };
                                            letpair_res_888 = id_890;
                                          }
                                          letpair_res_886 = letpair_res_888;
                                        }
                                        let_res_885 = letpair_res_886;
                                      }
                                      f63f919559f0d70225bd0da5dd9bcafc let_res_891;
                                      {
                                        v_46a5e81c2410b000ff0adea6dc198147 dtup_206 { let_res_885 };
                                        f63f919559f0d70225bd0da5dd9bcafc letpair_res_892;
                                        {
                                          auto dtup_fst_207 { std::get<0>(dtup_206) };
                                          auto dtup_snd_208 { std::get<1>(dtup_206) };
                                          v_362f9d9108a6902af48b6c83d5377ea1 id_893 { dtup_snd_208.readU16Le() };
                                          v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_894;
                                          {
                                            auto du16_fst_210 { std::get<0>(id_893) };
                                            auto du16_snd_211 { std::get<1>(id_893) };
                                            v_362f9d9108a6902af48b6c83d5377ea1 id_895 {  du16_fst_210, du16_snd_211  };
                                            letpair_res_894 = id_895;
                                          }
                                          v_07fe007441eaa3b71ce8622eb1df9609 let_res_896;
                                          {
                                            v_362f9d9108a6902af48b6c83d5377ea1 dsum1_215 { letpair_res_894 };
                                            v_07fe007441eaa3b71ce8622eb1df9609 letpair_res_897;
                                            {
                                              auto dsum1_fst_216 { std::get<0>(dsum1_215) };
                                              auto dsum1_snd_217 { std::get<1>(dsum1_215) };
                                              uint16_t id_898 { 0 };
                                              bool id_899 { bool(id_898 == dsum1_fst_216) };
                                              v_07fe007441eaa3b71ce8622eb1df9609 choose_res_900;
                                              if (id_899) {
                                                uint32_t id_901 { 0U };
                                                Vec<1, uint32_t> id_902 {  id_901  };
                                                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_903;
                                                {
                                                  Vec<1, uint32_t> leb_ref_233 { id_902 };
                                                  uint8_t id_904 { 0 };
                                                  Vec<1, uint8_t> id_905 {  id_904  };
                                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_906;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_234 { id_905 };
                                                    Vec<1, Pointer> id_907 {  dsum1_snd_217  };
                                                    v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_908;
                                                    {
                                                      Vec<1, Pointer> p_ref_235 { id_907 };
                                                      bool while_flag_909 { true };
                                                      do {
                                                        uint8_t id_910 { 0 };
                                                        Pointer id_911 { p_ref_235[id_910] };
                                                        v_1d5843897434feb24d158f3793db9189 id_912 { id_911.readU8() };
                                                        bool let_res_913;
                                                        {
                                                          v_1d5843897434feb24d158f3793db9189 leb128_236 { id_912 };
                                                          bool letpair_res_914;
                                                          {
                                                            auto leb128_fst_237 { std::get<0>(leb128_236) };
                                                            auto leb128_snd_238 { std::get<1>(leb128_236) };
                                                            uint8_t id_915 { 0 };
                                                            Void id_916 { ((void)(p_ref_235[id_915] = leb128_snd_238), VOID) };
                                                            uint8_t id_917 { 0 };
                                                            uint8_t id_918 { 127 };
                                                            uint8_t id_919 { uint8_t(leb128_fst_237 & id_918) };
                                                            uint32_t id_920 { uint32_t(id_919) };
                                                            uint8_t id_921 { 0 };
                                                            uint8_t id_922 { shft_ref_234[id_921] };
                                                            uint32_t id_923 { uint32_t(id_920 << id_922) };
                                                            uint8_t id_924 { 0 };
                                                            uint32_t id_925 { leb_ref_233[id_924] };
                                                            uint32_t id_926 { uint32_t(id_923 | id_925) };
                                                            Void id_927 { ((void)(leb_ref_233[id_917] = id_926), VOID) };
                                                            uint8_t id_928 { 0 };
                                                            uint8_t id_929 { 0 };
                                                            uint8_t id_930 { shft_ref_234[id_929] };
                                                            uint8_t id_931 { 7 };
                                                            uint8_t id_932 { uint8_t(id_930 + id_931) };
                                                            Void id_933 { ((void)(shft_ref_234[id_928] = id_932), VOID) };
                                                            uint8_t id_934 { 128 };
                                                            bool id_935 { bool(leb128_fst_237 >= id_934) };
                                                            letpair_res_914 = id_935;
                                                          }
                                                          let_res_913 = letpair_res_914;
                                                        }
                                                        while_flag_909 = let_res_913;
                                                        if (while_flag_909) {
                                                        }
                                                      } while (while_flag_909);
                                                      uint8_t id_936 { 0 };
                                                      uint32_t id_937 { leb_ref_233[id_936] };
                                                      Size id_938 { Size(id_937) };
                                                      uint8_t id_939 { 0 };
                                                      Pointer id_940 { p_ref_235[id_939] };
                                                      v_41b0681ed7f1f185fd3e6c4dcdc13110 id_941 {  id_938, id_940  };
                                                      let_res_908 = id_941;
                                                    }
                                                    let_res_906 = let_res_908;
                                                  }
                                                  let_res_903 = let_res_906;
                                                }
                                                v_07fe007441eaa3b71ce8622eb1df9609 let_res_942;
                                                {
                                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_239 { let_res_903 };
                                                  v_07fe007441eaa3b71ce8622eb1df9609 letpair_res_943;
                                                  {
                                                    auto dstring1_fst_240 { std::get<0>(dstring1_239) };
                                                    auto dstring1_snd_241 { std::get<1>(dstring1_239) };
                                                    f921d1e0a170c3c04148c21704db9c45 id_944 { dstring1_snd_241.readBytes(dstring1_fst_240) };
                                                    v_07fe007441eaa3b71ce8622eb1df9609 letpair_res_945;
                                                    {
                                                      auto dstring2_fst_243 { std::get<0>(id_944) };
                                                      auto dstring2_snd_244 { std::get<1>(id_944) };
                                                      std::string id_946 { dstring2_fst_243.toString() };
                                                      v_04c2264c7cb6c602ff22f97c6ae3e620 id_947 { std::in_place_index<0>, id_946 };
                                                      v_07fe007441eaa3b71ce8622eb1df9609 id_948 {  id_947, dstring2_snd_244  };
                                                      letpair_res_945 = id_948;
                                                    }
                                                    letpair_res_943 = letpair_res_945;
                                                  }
                                                  let_res_942 = letpair_res_943;
                                                }
                                                choose_res_900 = let_res_942;
                                              } else {
                                                uint16_t id_949 { 1 };
                                                bool id_950 { bool(dsum1_fst_216 == id_949) };
                                                Void id_951 { ((void)(assert(id_950)), VOID) };
                                                uint32_t id_952 { 0U };
                                                Vec<1, uint32_t> id_953 {  id_952  };
                                                v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_954;
                                                {
                                                  Vec<1, uint32_t> leb_ref_218 { id_953 };
                                                  uint8_t id_955 { 0 };
                                                  Vec<1, uint8_t> id_956 {  id_955  };
                                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_957;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_219 { id_956 };
                                                    Vec<1, Pointer> id_958 {  dsum1_snd_217  };
                                                    v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_959;
                                                    {
                                                      Vec<1, Pointer> p_ref_220 { id_958 };
                                                      bool while_flag_960 { true };
                                                      do {
                                                        uint8_t id_961 { 0 };
                                                        Pointer id_962 { p_ref_220[id_961] };
                                                        v_1d5843897434feb24d158f3793db9189 id_963 { id_962.readU8() };
                                                        bool let_res_964;
                                                        {
                                                          v_1d5843897434feb24d158f3793db9189 leb128_221 { id_963 };
                                                          bool letpair_res_965;
                                                          {
                                                            auto leb128_fst_222 { std::get<0>(leb128_221) };
                                                            auto leb128_snd_223 { std::get<1>(leb128_221) };
                                                            uint8_t id_966 { 0 };
                                                            Void id_967 { ((void)(p_ref_220[id_966] = leb128_snd_223), VOID) };
                                                            uint8_t id_968 { 0 };
                                                            uint8_t id_969 { 127 };
                                                            uint8_t id_970 { uint8_t(leb128_fst_222 & id_969) };
                                                            uint32_t id_971 { uint32_t(id_970) };
                                                            uint8_t id_972 { 0 };
                                                            uint8_t id_973 { shft_ref_219[id_972] };
                                                            uint32_t id_974 { uint32_t(id_971 << id_973) };
                                                            uint8_t id_975 { 0 };
                                                            uint32_t id_976 { leb_ref_218[id_975] };
                                                            uint32_t id_977 { uint32_t(id_974 | id_976) };
                                                            Void id_978 { ((void)(leb_ref_218[id_968] = id_977), VOID) };
                                                            uint8_t id_979 { 0 };
                                                            uint8_t id_980 { 0 };
                                                            uint8_t id_981 { shft_ref_219[id_980] };
                                                            uint8_t id_982 { 7 };
                                                            uint8_t id_983 { uint8_t(id_981 + id_982) };
                                                            Void id_984 { ((void)(shft_ref_219[id_979] = id_983), VOID) };
                                                            uint8_t id_985 { 128 };
                                                            bool id_986 { bool(leb128_fst_222 >= id_985) };
                                                            letpair_res_965 = id_986;
                                                          }
                                                          let_res_964 = letpair_res_965;
                                                        }
                                                        while_flag_960 = let_res_964;
                                                        if (while_flag_960) {
                                                        }
                                                      } while (while_flag_960);
                                                      uint8_t id_987 { 0 };
                                                      uint32_t id_988 { leb_ref_218[id_987] };
                                                      Size id_989 { Size(id_988) };
                                                      uint8_t id_990 { 0 };
                                                      Pointer id_991 { p_ref_220[id_990] };
                                                      v_41b0681ed7f1f185fd3e6c4dcdc13110 id_992 {  id_989, id_991  };
                                                      let_res_959 = id_992;
                                                    }
                                                    let_res_957 = let_res_959;
                                                  }
                                                  let_res_954 = let_res_957;
                                                }
                                                v_07fe007441eaa3b71ce8622eb1df9609 let_res_993;
                                                {
                                                  v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_224 { let_res_954 };
                                                  v_07fe007441eaa3b71ce8622eb1df9609 letpair_res_994;
                                                  {
                                                    auto dstring1_fst_225 { std::get<0>(dstring1_224) };
                                                    auto dstring1_snd_226 { std::get<1>(dstring1_224) };
                                                    f921d1e0a170c3c04148c21704db9c45 id_995 { dstring1_snd_226.readBytes(dstring1_fst_225) };
                                                    v_07fe007441eaa3b71ce8622eb1df9609 letpair_res_996;
                                                    {
                                                      auto dstring2_fst_228 { std::get<0>(id_995) };
                                                      auto dstring2_snd_229 { std::get<1>(id_995) };
                                                      std::string id_997 { dstring2_fst_228.toString() };
                                                      v_04c2264c7cb6c602ff22f97c6ae3e620 id_998 { std::in_place_index<1>, id_997 };
                                                      v_07fe007441eaa3b71ce8622eb1df9609 id_999 {  id_998, dstring2_snd_229  };
                                                      letpair_res_996 = id_999;
                                                    }
                                                    letpair_res_994 = letpair_res_996;
                                                  }
                                                  let_res_993 = letpair_res_994;
                                                }
                                                choose_res_900 = let_res_993;
                                              }
                                              letpair_res_897 = choose_res_900;
                                            }
                                            let_res_896 = letpair_res_897;
                                          }
                                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_1000;
                                          {
                                            auto dtup_fst_249 { std::get<0>(let_res_896) };
                                            auto dtup_snd_250 { std::get<1>(let_res_896) };
                                            v_3891539b8b788ad5d369dde272200753 id_1001 {  dtup_fst_207, dtup_fst_249  };
                                            t id_1002 { std::in_place_index<14>, id_1001 };
                                            f63f919559f0d70225bd0da5dd9bcafc id_1003 {  id_1002, dtup_snd_250  };
                                            letpair_res_1000 = id_1003;
                                          }
                                          letpair_res_892 = letpair_res_1000;
                                        }
                                        let_res_891 = letpair_res_892;
                                      }
                                      choose_res_843 = let_res_891;
                                    } else {
                                      uint16_t id_1004 { 15 };
                                      bool id_1005 { bool(dsum1_fst_81 == id_1004) };
                                      Void id_1006 { ((void)(assert(id_1005)), VOID) };
                                      uint32_t id_1007 { 0U };
                                      Vec<1, uint32_t> id_1008 {  id_1007  };
                                      v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_1009;
                                      {
                                        Vec<1, uint32_t> leb_ref_83 { id_1008 };
                                        uint8_t id_1010 { 0 };
                                        Vec<1, uint8_t> id_1011 {  id_1010  };
                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_1012;
                                        {
                                          Vec<1, uint8_t> shft_ref_84 { id_1011 };
                                          Vec<1, Pointer> id_1013 {  dsum1_snd_82  };
                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_1014;
                                          {
                                            Vec<1, Pointer> p_ref_85 { id_1013 };
                                            bool while_flag_1015 { true };
                                            do {
                                              uint8_t id_1016 { 0 };
                                              Pointer id_1017 { p_ref_85[id_1016] };
                                              v_1d5843897434feb24d158f3793db9189 id_1018 { id_1017.readU8() };
                                              bool let_res_1019;
                                              {
                                                v_1d5843897434feb24d158f3793db9189 leb128_86 { id_1018 };
                                                bool letpair_res_1020;
                                                {
                                                  auto leb128_fst_87 { std::get<0>(leb128_86) };
                                                  auto leb128_snd_88 { std::get<1>(leb128_86) };
                                                  uint8_t id_1021 { 0 };
                                                  Void id_1022 { ((void)(p_ref_85[id_1021] = leb128_snd_88), VOID) };
                                                  uint8_t id_1023 { 0 };
                                                  uint8_t id_1024 { 127 };
                                                  uint8_t id_1025 { uint8_t(leb128_fst_87 & id_1024) };
                                                  uint32_t id_1026 { uint32_t(id_1025) };
                                                  uint8_t id_1027 { 0 };
                                                  uint8_t id_1028 { shft_ref_84[id_1027] };
                                                  uint32_t id_1029 { uint32_t(id_1026 << id_1028) };
                                                  uint8_t id_1030 { 0 };
                                                  uint32_t id_1031 { leb_ref_83[id_1030] };
                                                  uint32_t id_1032 { uint32_t(id_1029 | id_1031) };
                                                  Void id_1033 { ((void)(leb_ref_83[id_1023] = id_1032), VOID) };
                                                  uint8_t id_1034 { 0 };
                                                  uint8_t id_1035 { 0 };
                                                  uint8_t id_1036 { shft_ref_84[id_1035] };
                                                  uint8_t id_1037 { 7 };
                                                  uint8_t id_1038 { uint8_t(id_1036 + id_1037) };
                                                  Void id_1039 { ((void)(shft_ref_84[id_1034] = id_1038), VOID) };
                                                  uint8_t id_1040 { 128 };
                                                  bool id_1041 { bool(leb128_fst_87 >= id_1040) };
                                                  letpair_res_1020 = id_1041;
                                                }
                                                let_res_1019 = letpair_res_1020;
                                              }
                                              while_flag_1015 = let_res_1019;
                                              if (while_flag_1015) {
                                              }
                                            } while (while_flag_1015);
                                            uint8_t id_1042 { 0 };
                                            uint32_t id_1043 { leb_ref_83[id_1042] };
                                            Size id_1044 { Size(id_1043) };
                                            uint8_t id_1045 { 0 };
                                            Pointer id_1046 { p_ref_85[id_1045] };
                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 id_1047 {  id_1044, id_1046  };
                                            let_res_1014 = id_1047;
                                          }
                                          let_res_1012 = let_res_1014;
                                        }
                                        let_res_1009 = let_res_1012;
                                      }
                                      v_46a5e81c2410b000ff0adea6dc198147 let_res_1048;
                                      {
                                        v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_89 { let_res_1009 };
                                        v_46a5e81c2410b000ff0adea6dc198147 letpair_res_1049;
                                        {
                                          auto dstring1_fst_90 { std::get<0>(dstring1_89) };
                                          auto dstring1_snd_91 { std::get<1>(dstring1_89) };
                                          f921d1e0a170c3c04148c21704db9c45 id_1050 { dstring1_snd_91.readBytes(dstring1_fst_90) };
                                          v_46a5e81c2410b000ff0adea6dc198147 letpair_res_1051;
                                          {
                                            auto dstring2_fst_93 { std::get<0>(id_1050) };
                                            auto dstring2_snd_94 { std::get<1>(id_1050) };
                                            std::string id_1052 { dstring2_fst_93.toString() };
                                            v_46a5e81c2410b000ff0adea6dc198147 id_1053 {  id_1052, dstring2_snd_94  };
                                            letpair_res_1051 = id_1053;
                                          }
                                          letpair_res_1049 = letpair_res_1051;
                                        }
                                        let_res_1048 = letpair_res_1049;
                                      }
                                      f63f919559f0d70225bd0da5dd9bcafc let_res_1054;
                                      {
                                        v_46a5e81c2410b000ff0adea6dc198147 dtup_95 { let_res_1048 };
                                        f63f919559f0d70225bd0da5dd9bcafc letpair_res_1055;
                                        {
                                          auto dtup_fst_96 { std::get<0>(dtup_95) };
                                          auto dtup_snd_97 { std::get<1>(dtup_95) };
                                          v_362f9d9108a6902af48b6c83d5377ea1 id_1056 { dtup_snd_97.readU16Le() };
                                          v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_1057;
                                          {
                                            auto du16_fst_99 { std::get<0>(id_1056) };
                                            auto du16_snd_100 { std::get<1>(id_1056) };
                                            v_362f9d9108a6902af48b6c83d5377ea1 id_1058 {  du16_fst_99, du16_snd_100  };
                                            letpair_res_1057 = id_1058;
                                          }
                                          e3493b0d3f2be64f6703f6d7da12486c let_res_1059;
                                          {
                                            v_362f9d9108a6902af48b6c83d5377ea1 dsum1_104 { letpair_res_1057 };
                                            e3493b0d3f2be64f6703f6d7da12486c letpair_res_1060;
                                            {
                                              auto dsum1_fst_105 { std::get<0>(dsum1_104) };
                                              auto dsum1_snd_106 { std::get<1>(dsum1_104) };
                                              uint16_t id_1061 { 0 };
                                              bool id_1062 { bool(id_1061 == dsum1_fst_105) };
                                              e3493b0d3f2be64f6703f6d7da12486c choose_res_1063;
                                              if (id_1062) {
                                                e6f820d94c0e3bb8eb0c04383ff72e06 id_1064 { std::in_place_index<0>, VOID };
                                                e3493b0d3f2be64f6703f6d7da12486c id_1065 {  id_1064, dsum1_snd_106  };
                                                choose_res_1063 = id_1065;
                                              } else {
                                                uint16_t id_1066 { 1 };
                                                bool id_1067 { bool(id_1066 == dsum1_fst_105) };
                                                e3493b0d3f2be64f6703f6d7da12486c choose_res_1068;
                                                if (id_1067) {
                                                  e6f820d94c0e3bb8eb0c04383ff72e06 id_1069 { std::in_place_index<1>, VOID };
                                                  e3493b0d3f2be64f6703f6d7da12486c id_1070 {  id_1069, dsum1_snd_106  };
                                                  choose_res_1068 = id_1070;
                                                } else {
                                                  uint16_t id_1071 { 2 };
                                                  bool id_1072 { bool(id_1071 == dsum1_fst_105) };
                                                  e3493b0d3f2be64f6703f6d7da12486c choose_res_1073;
                                                  if (id_1072) {
                                                    e6f820d94c0e3bb8eb0c04383ff72e06 id_1074 { std::in_place_index<2>, VOID };
                                                    e3493b0d3f2be64f6703f6d7da12486c id_1075 {  id_1074, dsum1_snd_106  };
                                                    choose_res_1073 = id_1075;
                                                  } else {
                                                    uint16_t id_1076 { 3 };
                                                    bool id_1077 { bool(id_1076 == dsum1_fst_105) };
                                                    e3493b0d3f2be64f6703f6d7da12486c choose_res_1078;
                                                    if (id_1077) {
                                                      e6f820d94c0e3bb8eb0c04383ff72e06 id_1079 { std::in_place_index<3>, VOID };
                                                      e3493b0d3f2be64f6703f6d7da12486c id_1080 {  id_1079, dsum1_snd_106  };
                                                      choose_res_1078 = id_1080;
                                                    } else {
                                                      uint16_t id_1081 { 4 };
                                                      bool id_1082 { bool(id_1081 == dsum1_fst_105) };
                                                      e3493b0d3f2be64f6703f6d7da12486c choose_res_1083;
                                                      if (id_1082) {
                                                        e6f820d94c0e3bb8eb0c04383ff72e06 id_1084 { std::in_place_index<4>, VOID };
                                                        e3493b0d3f2be64f6703f6d7da12486c id_1085 {  id_1084, dsum1_snd_106  };
                                                        choose_res_1083 = id_1085;
                                                      } else {
                                                        uint16_t id_1086 { 5 };
                                                        bool id_1087 { bool(id_1086 == dsum1_fst_105) };
                                                        e3493b0d3f2be64f6703f6d7da12486c choose_res_1088;
                                                        if (id_1087) {
                                                          uint32_t id_1089 { 0U };
                                                          Vec<1, uint32_t> id_1090 {  id_1089  };
                                                          v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_1091;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_122 { id_1090 };
                                                            uint8_t id_1092 { 0 };
                                                            Vec<1, uint8_t> id_1093 {  id_1092  };
                                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_1094;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_123 { id_1093 };
                                                              Vec<1, Pointer> id_1095 {  dsum1_snd_106  };
                                                              v_41b0681ed7f1f185fd3e6c4dcdc13110 let_res_1096;
                                                              {
                                                                Vec<1, Pointer> p_ref_124 { id_1095 };
                                                                bool while_flag_1097 { true };
                                                                do {
                                                                  uint8_t id_1098 { 0 };
                                                                  Pointer id_1099 { p_ref_124[id_1098] };
                                                                  v_1d5843897434feb24d158f3793db9189 id_1100 { id_1099.readU8() };
                                                                  bool let_res_1101;
                                                                  {
                                                                    v_1d5843897434feb24d158f3793db9189 leb128_125 { id_1100 };
                                                                    bool letpair_res_1102;
                                                                    {
                                                                      auto leb128_fst_126 { std::get<0>(leb128_125) };
                                                                      auto leb128_snd_127 { std::get<1>(leb128_125) };
                                                                      uint8_t id_1103 { 0 };
                                                                      Void id_1104 { ((void)(p_ref_124[id_1103] = leb128_snd_127), VOID) };
                                                                      uint8_t id_1105 { 0 };
                                                                      uint8_t id_1106 { 127 };
                                                                      uint8_t id_1107 { uint8_t(leb128_fst_126 & id_1106) };
                                                                      uint32_t id_1108 { uint32_t(id_1107) };
                                                                      uint8_t id_1109 { 0 };
                                                                      uint8_t id_1110 { shft_ref_123[id_1109] };
                                                                      uint32_t id_1111 { uint32_t(id_1108 << id_1110) };
                                                                      uint8_t id_1112 { 0 };
                                                                      uint32_t id_1113 { leb_ref_122[id_1112] };
                                                                      uint32_t id_1114 { uint32_t(id_1111 | id_1113) };
                                                                      Void id_1115 { ((void)(leb_ref_122[id_1105] = id_1114), VOID) };
                                                                      uint8_t id_1116 { 0 };
                                                                      uint8_t id_1117 { 0 };
                                                                      uint8_t id_1118 { shft_ref_123[id_1117] };
                                                                      uint8_t id_1119 { 7 };
                                                                      uint8_t id_1120 { uint8_t(id_1118 + id_1119) };
                                                                      Void id_1121 { ((void)(shft_ref_123[id_1116] = id_1120), VOID) };
                                                                      uint8_t id_1122 { 128 };
                                                                      bool id_1123 { bool(leb128_fst_126 >= id_1122) };
                                                                      letpair_res_1102 = id_1123;
                                                                    }
                                                                    let_res_1101 = letpair_res_1102;
                                                                  }
                                                                  while_flag_1097 = let_res_1101;
                                                                  if (while_flag_1097) {
                                                                  }
                                                                } while (while_flag_1097);
                                                                uint8_t id_1124 { 0 };
                                                                uint32_t id_1125 { leb_ref_122[id_1124] };
                                                                Size id_1126 { Size(id_1125) };
                                                                uint8_t id_1127 { 0 };
                                                                Pointer id_1128 { p_ref_124[id_1127] };
                                                                v_41b0681ed7f1f185fd3e6c4dcdc13110 id_1129 {  id_1126, id_1128  };
                                                                let_res_1096 = id_1129;
                                                              }
                                                              let_res_1094 = let_res_1096;
                                                            }
                                                            let_res_1091 = let_res_1094;
                                                          }
                                                          v_46a5e81c2410b000ff0adea6dc198147 let_res_1130;
                                                          {
                                                            v_41b0681ed7f1f185fd3e6c4dcdc13110 dstring1_128 { let_res_1091 };
                                                            v_46a5e81c2410b000ff0adea6dc198147 letpair_res_1131;
                                                            {
                                                              auto dstring1_fst_129 { std::get<0>(dstring1_128) };
                                                              auto dstring1_snd_130 { std::get<1>(dstring1_128) };
                                                              f921d1e0a170c3c04148c21704db9c45 id_1132 { dstring1_snd_130.readBytes(dstring1_fst_129) };
                                                              v_46a5e81c2410b000ff0adea6dc198147 letpair_res_1133;
                                                              {
                                                                auto dstring2_fst_132 { std::get<0>(id_1132) };
                                                                auto dstring2_snd_133 { std::get<1>(id_1132) };
                                                                std::string id_1134 { dstring2_fst_132.toString() };
                                                                v_46a5e81c2410b000ff0adea6dc198147 id_1135 {  id_1134, dstring2_snd_133  };
                                                                letpair_res_1133 = id_1135;
                                                              }
                                                              letpair_res_1131 = letpair_res_1133;
                                                            }
                                                            let_res_1130 = letpair_res_1131;
                                                          }
                                                          e3493b0d3f2be64f6703f6d7da12486c let_res_1136;
                                                          {
                                                            v_46a5e81c2410b000ff0adea6dc198147 dtup_134 { let_res_1130 };
                                                            e3493b0d3f2be64f6703f6d7da12486c letpair_res_1137;
                                                            {
                                                              auto dtup_fst_135 { std::get<0>(dtup_134) };
                                                              auto dtup_snd_136 { std::get<1>(dtup_134) };
                                                              v_362f9d9108a6902af48b6c83d5377ea1 id_1138 { dtup_snd_136.readU16Le() };
                                                              v_362f9d9108a6902af48b6c83d5377ea1 letpair_res_1139;
                                                              {
                                                                auto du16_fst_138 { std::get<0>(id_1138) };
                                                                auto du16_snd_139 { std::get<1>(id_1138) };
                                                                v_362f9d9108a6902af48b6c83d5377ea1 id_1140 {  du16_fst_138, du16_snd_139  };
                                                                letpair_res_1139 = id_1140;
                                                              }
                                                              v_1e776a020219fd0db636bac0cf181115 let_res_1141;
                                                              {
                                                                v_362f9d9108a6902af48b6c83d5377ea1 dsum1_143 { letpair_res_1139 };
                                                                v_1e776a020219fd0db636bac0cf181115 letpair_res_1142;
                                                                {
                                                                  auto dsum1_fst_144 { std::get<0>(dsum1_143) };
                                                                  auto dsum1_snd_145 { std::get<1>(dsum1_143) };
                                                                  uint16_t id_1143 { 0 };
                                                                  bool id_1144 { bool(id_1143 == dsum1_fst_144) };
                                                                  v_1e776a020219fd0db636bac0cf181115 choose_res_1145;
                                                                  if (id_1144) {
                                                                    f27b577e1bb6a9c447e7eec975daa7e7 id_1146 { std::in_place_index<0>, VOID };
                                                                    v_1e776a020219fd0db636bac0cf181115 id_1147 {  id_1146, dsum1_snd_145  };
                                                                    choose_res_1145 = id_1147;
                                                                  } else {
                                                                    uint16_t id_1148 { 1 };
                                                                    bool id_1149 { bool(id_1148 == dsum1_fst_144) };
                                                                    v_1e776a020219fd0db636bac0cf181115 choose_res_1150;
                                                                    if (id_1149) {
                                                                      f27b577e1bb6a9c447e7eec975daa7e7 id_1151 { std::in_place_index<1>, VOID };
                                                                      v_1e776a020219fd0db636bac0cf181115 id_1152 {  id_1151, dsum1_snd_145  };
                                                                      choose_res_1150 = id_1152;
                                                                    } else {
                                                                      uint16_t id_1153 { 2 };
                                                                      bool id_1154 { bool(id_1153 == dsum1_fst_144) };
                                                                      v_1e776a020219fd0db636bac0cf181115 choose_res_1155;
                                                                      if (id_1154) {
                                                                        f27b577e1bb6a9c447e7eec975daa7e7 id_1156 { std::in_place_index<2>, VOID };
                                                                        v_1e776a020219fd0db636bac0cf181115 id_1157 {  id_1156, dsum1_snd_145  };
                                                                        choose_res_1155 = id_1157;
                                                                      } else {
                                                                        uint16_t id_1158 { 3 };
                                                                        bool id_1159 { bool(id_1158 == dsum1_fst_144) };
                                                                        v_1e776a020219fd0db636bac0cf181115 choose_res_1160;
                                                                        if (id_1159) {
                                                                          f27b577e1bb6a9c447e7eec975daa7e7 id_1161 { std::in_place_index<3>, VOID };
                                                                          v_1e776a020219fd0db636bac0cf181115 id_1162 {  id_1161, dsum1_snd_145  };
                                                                          choose_res_1160 = id_1162;
                                                                        } else {
                                                                          uint16_t id_1163 { 4 };
                                                                          bool id_1164 { bool(id_1163 == dsum1_fst_144) };
                                                                          v_1e776a020219fd0db636bac0cf181115 choose_res_1165;
                                                                          if (id_1164) {
                                                                            f27b577e1bb6a9c447e7eec975daa7e7 id_1166 { std::in_place_index<4>, VOID };
                                                                            v_1e776a020219fd0db636bac0cf181115 id_1167 {  id_1166, dsum1_snd_145  };
                                                                            choose_res_1165 = id_1167;
                                                                          } else {
                                                                            uint16_t id_1168 { 5 };
                                                                            bool id_1169 { bool(id_1168 == dsum1_fst_144) };
                                                                            v_1e776a020219fd0db636bac0cf181115 choose_res_1170;
                                                                            if (id_1169) {
                                                                              f27b577e1bb6a9c447e7eec975daa7e7 id_1171 { std::in_place_index<5>, VOID };
                                                                              v_1e776a020219fd0db636bac0cf181115 id_1172 {  id_1171, dsum1_snd_145  };
                                                                              choose_res_1170 = id_1172;
                                                                            } else {
                                                                              uint16_t id_1173 { 6 };
                                                                              bool id_1174 { bool(dsum1_fst_144 == id_1173) };
                                                                              Void id_1175 { ((void)(assert(id_1174)), VOID) };
                                                                              f27b577e1bb6a9c447e7eec975daa7e7 id_1176 { std::in_place_index<6>, VOID };
                                                                              v_1e776a020219fd0db636bac0cf181115 id_1177 {  id_1176, dsum1_snd_145  };
                                                                              choose_res_1170 = id_1177;
                                                                            }
                                                                            choose_res_1165 = choose_res_1170;
                                                                          }
                                                                          choose_res_1160 = choose_res_1165;
                                                                        }
                                                                        choose_res_1155 = choose_res_1160;
                                                                      }
                                                                      choose_res_1150 = choose_res_1155;
                                                                    }
                                                                    choose_res_1145 = choose_res_1150;
                                                                  }
                                                                  letpair_res_1142 = choose_res_1145;
                                                                }
                                                                let_res_1141 = letpair_res_1142;
                                                              }
                                                              e3493b0d3f2be64f6703f6d7da12486c letpair_res_1178;
                                                              {
                                                                auto dtup_fst_168 { std::get<0>(let_res_1141) };
                                                                auto dtup_snd_169 { std::get<1>(let_res_1141) };
                                                                v_22ca22dbe40628ddd4edb314b5205ff3 id_1179 {  dtup_fst_135, dtup_fst_168  };
                                                                e6f820d94c0e3bb8eb0c04383ff72e06 id_1180 { std::in_place_index<5>, id_1179 };
                                                                e3493b0d3f2be64f6703f6d7da12486c id_1181 {  id_1180, dtup_snd_169  };
                                                                letpair_res_1178 = id_1181;
                                                              }
                                                              letpair_res_1137 = letpair_res_1178;
                                                            }
                                                            let_res_1136 = letpair_res_1137;
                                                          }
                                                          choose_res_1088 = let_res_1136;
                                                        } else {
                                                          uint16_t id_1182 { 6 };
                                                          bool id_1183 { bool(dsum1_fst_105 == id_1182) };
                                                          Void id_1184 { ((void)(assert(id_1183)), VOID) };
                                                          b62e103e7915a76f45f02f7c6f667c79 id_1185 { dsum1_snd_106.readU64Le() };
                                                          v_41a5a8cf414de9bfdc6375241fcc910a letpair_res_1186;
                                                          {
                                                            auto dfloat_fst_108 { std::get<0>(id_1185) };
                                                            auto dfloat_snd_109 { std::get<1>(id_1185) };
                                                            double id_1187 { float_of_qword(dfloat_fst_108) };
                                                            v_41a5a8cf414de9bfdc6375241fcc910a id_1188 {  id_1187, dfloat_snd_109  };
                                                            letpair_res_1186 = id_1188;
                                                          }
                                                          e3493b0d3f2be64f6703f6d7da12486c let_res_1189;
                                                          {
                                                            v_41a5a8cf414de9bfdc6375241fcc910a dtup_110 { letpair_res_1186 };
                                                            e3493b0d3f2be64f6703f6d7da12486c letpair_res_1190;
                                                            {
                                                              auto dtup_fst_111 { std::get<0>(dtup_110) };
                                                              auto dtup_snd_112 { std::get<1>(dtup_110) };
                                                              ac0fbd05039f742d2f1d9ac182e392ab id_1191 { dtup_snd_112.readU32Le() };
                                                              e3493b0d3f2be64f6703f6d7da12486c letpair_res_1192;
                                                              {
                                                                auto du32_fst_114 { std::get<0>(id_1191) };
                                                                auto du32_snd_115 { std::get<1>(id_1191) };
                                                                a87b3e8210a10a34a7c2070f37f91a0a id_1193 {  dtup_fst_111, du32_fst_114  };
                                                                e6f820d94c0e3bb8eb0c04383ff72e06 id_1194 { std::in_place_index<6>, id_1193 };
                                                                e3493b0d3f2be64f6703f6d7da12486c id_1195 {  id_1194, du32_snd_115  };
                                                                letpair_res_1192 = id_1195;
                                                              }
                                                              letpair_res_1190 = letpair_res_1192;
                                                            }
                                                            let_res_1189 = letpair_res_1190;
                                                          }
                                                          choose_res_1088 = let_res_1189;
                                                        }
                                                        choose_res_1083 = choose_res_1088;
                                                      }
                                                      choose_res_1078 = choose_res_1083;
                                                    }
                                                    choose_res_1073 = choose_res_1078;
                                                  }
                                                  choose_res_1068 = choose_res_1073;
                                                }
                                                choose_res_1063 = choose_res_1068;
                                              }
                                              letpair_res_1060 = choose_res_1063;
                                            }
                                            let_res_1059 = letpair_res_1060;
                                          }
                                          f63f919559f0d70225bd0da5dd9bcafc letpair_res_1196;
                                          {
                                            auto dtup_fst_189 { std::get<0>(let_res_1059) };
                                            auto dtup_snd_190 { std::get<1>(let_res_1059) };
                                            ec4a56989018adc62b22d5f6798b0bc1 id_1197 {  dtup_fst_96, dtup_fst_189  };
                                            t id_1198 { std::in_place_index<15>, id_1197 };
                                            f63f919559f0d70225bd0da5dd9bcafc id_1199 {  id_1198, dtup_snd_190  };
                                            letpair_res_1196 = id_1199;
                                          }
                                          letpair_res_1055 = letpair_res_1196;
                                        }
                                        let_res_1054 = letpair_res_1055;
                                      }
                                      choose_res_843 = let_res_1054;
                                    }
                                    choose_res_838 = choose_res_843;
                                  }
                                  choose_res_781 = choose_res_838;
                                }
                                choose_res_707 = choose_res_781;
                              }
                              choose_res_702 = choose_res_707;
                            }
                            choose_res_680 = choose_res_702;
                          }
                          choose_res_673 = choose_res_680;
                        }
                        choose_res_546 = choose_res_673;
                      }
                      choose_res_474 = choose_res_546;
                    }
                    choose_res_159 = choose_res_474;
                  }
                  choose_res_154 = choose_res_159;
                }
                choose_res_98 = choose_res_154;
              }
              choose_res_47 = choose_res_98;
            }
            choose_res_42 = choose_res_47;
          }
          choose_res_37 = choose_res_42;
        }
        letpair_res_34 = choose_res_37;
      }
      let_res_33 = letpair_res_34;
    }
    f63f919559f0d70225bd0da5dd9bcafc letpair_res_1200;
    {
      auto make_fst_654 { std::get<0>(let_res_33) };
      auto make_snd_655 { std::get<1>(let_res_33) };
      f63f919559f0d70225bd0da5dd9bcafc id_1201 {  make_fst_654, make_snd_655  };
      letpair_res_1200 = id_1201;
    }
    return letpair_res_1200;
  }
   };
  return fun29;
}
std::function<f63f919559f0d70225bd0da5dd9bcafc(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]")
      (let "label2_657" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_657")) (size 2)
          (if (eq (u16 1) (identifier "label2_657")) (size 2)
            (if (eq (u16 2) (identifier "label2_657"))
              (add (size 2)
                (add
                  (let "n_ref_740" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "lebsz_ref_741" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_740")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_741")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_741") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_741")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_741")))))) 
                  (size-of-u32 (string-length (get-alt "Versions" (param 0))))))
              (if (eq (u16 3) (identifier "label2_657"))
                (let "sz_735" (add (size 2) (apply (ext-identifier src_path sersize-of-row-binary) (get-item 0 (get-alt "Sources" (param 0)))))
                  (add (identifier "sz_735")
                    (add
                      (let "n_ref_737" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "lebsz_ref_738" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_737")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_738")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_738") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_738")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_738")))))) 
                      (size-of-u32 (string-length (get-item 1 (get-alt "Sources" (param 0))))))))
                (if (eq (u16 4) (identifier "label2_657")) (size 2)
                  (if (eq (u16 5) (identifier "label2_657"))
                    (let "sz_711" (add (size 2) (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (get-alt "PerSite" (param 0)))))
                      (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerSite" (param 0))))) 
                        (add (identifier "sz_711") (size 2))
                        (if (eq (u16 1) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                          (let "sz_732"
                            (add (add (identifier "sz_711") (size 2))
                              (add
                                (let "n_ref_730" (make-vec (string-length (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                  (let "lebsz_ref_731" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_730")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_731")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_731") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_731")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_731")))))) 
                                (size-of-u32 (string-length (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                            (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0))))))) 
                              (add (identifier "sz_732") (size 2)) (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 1))) (add (identifier "sz_732") (size 2)))))
                          (if (eq (u16 2) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                            (let "sz_720" (add (add (identifier "sz_711") (size 2)) (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 0 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))
                              (let "label2_721" (label-of (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))
                                (if (eq (u16 0) (identifier "label2_721")) 
                                  (add (identifier "sz_720") (size 2))
                                  (if (eq (u16 1) (identifier "label2_721")) 
                                    (add (identifier "sz_720") (size 2))
                                    (if (eq (u16 2) (identifier "label2_721")) 
                                      (add (identifier "sz_720") (size 2))
                                      (if (eq (u16 3) (identifier "label2_721")) 
                                        (add (identifier "sz_720") (size 2))
                                        (if (eq (u16 4) (identifier "label2_721")) 
                                          (add (identifier "sz_720") (size 2))
                                          (if (eq (u16 5) (identifier "label2_721")) 
                                            (add (identifier "sz_720") (size 2))
                                            (if (eq (u16 6) (identifier "label2_721"))
                                              (let "sz_726"
                                                (add (add (identifier "sz_720") (size 2))
                                                  (add
                                                    (let "n_ref_724" 
                                                      (make-vec (string-length (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                                      (let "lebsz_ref_725" 
                                                        (make-vec (u32 1))
                                                        (seq
                                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_724")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_725")) (u8 7)))
                                                            (set-vec (u8 0) (identifier "lebsz_ref_725") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_725")) (u32 1))))
                                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_725"))))))
                                                    (size-of-u32 (string-length (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))))
                                                (let "label2_727" (label-of (get-item 1 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))))
                                                  (if (eq (u16 0) (identifier "label2_727")) 
                                                    (add (identifier "sz_726") (size 2))
                                                    (if (eq (u16 1) (identifier "label2_727")) 
                                                      (add (identifier "sz_726") (size 2))
                                                      (if (eq (u16 2) (identifier "label2_727")) 
                                                        (add (identifier "sz_726") (size 2))
                                                        (if (eq (u16 3) (identifier "label2_727")) 
                                                          (add (identifier "sz_726") (size 2))
                                                          (if (eq (u16 4) (identifier "label2_727")) 
                                                            (add (identifier "sz_726") (size 2))
                                                            (if (eq (u16 5) (identifier "label2_727")) 
                                                              (add (identifier "sz_726") (size 2))
                                                              (if (eq (u16 6) (identifier "label2_727")) 
                                                                (add (identifier "sz_726") (size 2)) 
                                                                (seq (assert (eq (identifier "label2_727") (u16 7))) (add (identifier "sz_726") (size 2))))))))))))
                                              (if (eq (u16 7) (identifier "label2_721")) 
                                                (add (add (identifier "sz_720") (size 2)) (size 4)) 
                                                (seq (assert (eq (identifier "label2_721") (u16 8))) (add (identifier "sz_720") (size 2)))))))))))))
                            (seq (assert (eq (label-of (get-item 1 (get-alt "PerSite" (param 0)))) (u16 3)))
                              (let "sz_717"
                                (add (add (identifier "sz_711") (size 2))
                                  (add
                                    (let "n_ref_715" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                      (let "lebsz_ref_716" (make-vec (u32 1))
                                        (seq
                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_715")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_716")) (u8 7)))
                                            (set-vec (u8 0) (identifier "lebsz_ref_716") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_716")) (u32 1)))) 
                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_716")))))) 
                                    (size-of-u32 (string-length (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 0))) (add (identifier "sz_717") (size 2)))))))))
                    (if (eq (u16 6) (identifier "label2_657"))
                      (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                        (size 4)
                        (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                          (size 4)
                          (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                            (add (size 4)
                              (add
                                (let "n_ref_708" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                  (let "lebsz_ref_709" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_708")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_709")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_709") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_709")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_709")))))) 
                                (size-of-u32 (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0))))))))))
                      (if (eq (u16 7) (identifier "label2_657"))
                        (let "sz_701"
                          (let "sz_697"
                            (let "sz_696" (add (size 2) (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (get-alt "Tails" (param 0)))))
                              (add (identifier "sz_696") (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 1 (get-alt "Tails" (param 0))))))
                            (add (identifier "sz_697")
                              (add
                                (let "n_ref_699" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "lebsz_ref_700" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_699")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_700")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_700") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_700")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_700")))))) 
                                (size-of-u32 (string-length (get-item 2 (get-alt "Tails" (param 0))))))))
                          (if (eq (u16 0) (label-of (get-item 3 (get-alt "Tails" (param 0)))))
                            (add (add (identifier "sz_701") (size 2))
                              (add
                                (let "n_ref_704" (make-vec (string-length (get-alt "Subscriber" (get-item 3 (get-alt "Tails" (param 0))))))
                                  (let "lebsz_ref_705" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_704")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_705")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_705") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_705")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_705")))))) 
                                (size-of-u32 (string-length (get-alt "Subscriber" (get-item 3 (get-alt "Tails" (param 0))))))))
                            (seq (assert (eq (label-of (get-item 3 (get-alt "Tails" (param 0)))) (u16 1))) (add (add (identifier "sz_701") (size 2)) (size 4)))))
                        (if (eq (u16 8) (identifier "label2_657")) (size 4)
                          (if (eq (u16 9) (identifier "label2_657"))
                            (if (is-null (get-alt "Error" (param 0))) (size 3) (add (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (force (get-alt "Error" (param 0))))) (size 1)))
                            (if (eq (u16 10) (identifier "label2_657")) 
                              (size 2)
                              (if (eq (u16 11) (identifier "label2_657"))
                                (let "sz_690" (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (get-item 0 (get-alt "PerClient" (param 0)))))
                                  (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerClient" (param 0)))))
                                    (add (add (identifier "sz_690") (size 2))
                                      (add
                                        (let "n_ref_693" (make-vec (string-length (get-alt "Response" (get-item 1 (get-alt "PerClient" (param 0))))))
                                          (let "lebsz_ref_694" (make-vec (u32 1))
                                            (seq
                                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_693")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_694")) (u8 7)))
                                                (set-vec (u8 0) (identifier "lebsz_ref_694") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_694")) (u32 1)))) 
                                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_694")))))) 
                                        (size-of-u32 (string-length (get-alt "Response" (get-item 1 (get-alt "PerClient" (param 0))))))))
                                    (seq (assert (eq (label-of (get-item 1 (get-alt "PerClient" (param 0)))) (u16 1)))
                                      (add (add (identifier "sz_690") (size 2)) (apply (identifier "per_dash_key-sersize-of-row-binary") (get-alt "Scratchpad" (get-item 1 (get-alt "PerClient" (param 0)))))))))
                                (if (eq (u16 12) (identifier "label2_657"))
                                  (let "sz_688"
                                    (add (size 2)
                                      (add
                                        (let "n_ref_686" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "lebsz_ref_687" (make-vec (u32 1))
                                            (seq
                                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_686")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_687")) (u8 7)))
                                                (set-vec (u8 0) (identifier "lebsz_ref_687") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_687")) (u32 1)))) 
                                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_687")))))) 
                                        (size-of-u32 (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))))
                                    (add (identifier "sz_688") (apply (identifier "per_dash_key-sersize-of-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))))))
                                  (if (eq (u16 13) (identifier "label2_657")) 
                                    (size 2)
                                    (if (eq (u16 14) (identifier "label2_657"))
                                      (let "sz_676"
                                        (add (size 2)
                                          (add
                                            (let "n_ref_674" (make-vec (string-length (get-item 0 (get-alt "Teams" (param 0)))))
                                              (let "lebsz_ref_675" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_674")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_675")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_675") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_675")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_675")))))) 
                                            (size-of-u32 (string-length (get-item 0 (get-alt "Teams" (param 0)))))))
                                        (if (eq (u16 0) (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                          (add (add (identifier "sz_676") (size 2))
                                            (add
                                              (let "n_ref_682" (make-vec (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                                (let "lebsz_ref_683" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_682")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_683")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_683") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_683")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_683")))))) 
                                              (size-of-u32 (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))))
                                          (seq (assert (eq (label-of (get-item 1 (get-alt "Teams" (param 0)))) (u16 1)))
                                            (add (add (identifier "sz_676") (size 2))
                                              (add
                                                (let "n_ref_679" (make-vec (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))
                                                  (let "lebsz_ref_680" 
                                                    (make-vec (u32 1))
                                                    (seq
                                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_679")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_680")) (u8 7)))
                                                        (set-vec (u8 0) (identifier "lebsz_ref_680") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_680")) (u32 1)))) 
                                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_680")))))) 
                                                (size-of-u32 (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0)))))))))))
                                      (seq (assert (eq (identifier "label2_657") (u16 15)))
                                        (let "sz_662"
                                          (add (size 2)
                                            (add
                                              (let "n_ref_660" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "lebsz_ref_661" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_660")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_661")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_661") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_661")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_661")))))) 
                                              (size-of-u32 (string-length (get-item 0 (get-alt "Incidents" (param 0)))))))
                                          (let "label2_663" (label-of (get-item 1 (get-alt "Incidents" (param 0))))
                                            (if (eq (u16 0) (identifier "label2_663")) 
                                              (add (identifier "sz_662") (size 2))
                                              (if (eq (u16 1) (identifier "label2_663")) 
                                                (add (identifier "sz_662") (size 2))
                                                (if (eq (u16 2) (identifier "label2_663")) 
                                                  (add (identifier "sz_662") (size 2))
                                                  (if (eq (u16 3) (identifier "label2_663")) 
                                                    (add (identifier "sz_662") (size 2))
                                                    (if (eq (u16 4) (identifier "label2_663")) 
                                                      (add (identifier "sz_662") (size 2))
                                                      (if (eq (u16 5) (identifier "label2_663"))
                                                        (let "sz_670"
                                                          (add (add (identifier "sz_662") (size 2))
                                                            (add
                                                              (let "n_ref_668" 
                                                                (make-vec (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                (let "lebsz_ref_669" 
                                                                  (make-vec (u32 1))
                                                                  (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_668")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_669")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_669") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_669")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_669"))))))
                                                              (size-of-u32 (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))))
                                                          (let "label2_671" 
                                                            (label-of (get-item 1 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0))))))
                                                            (if (eq (u16 0) (identifier "label2_671")) 
                                                              (add (identifier "sz_670") (size 2))
                                                              (if (eq (u16 1) (identifier "label2_671")) 
                                                                (add (identifier "sz_670") (size 2))
                                                                (if (eq (u16 2) (identifier "label2_671")) 
                                                                  (add (identifier "sz_670") (size 2))
                                                                  (if 
                                                                    (eq (u16 3) (identifier "label2_671")) 
                                                                    (add (identifier "sz_670") (size 2))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "label2_671")) 
                                                                    (add (identifier "sz_670") (size 2))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "label2_671")) 
                                                                    (add (identifier "sz_670") (size 2)) 
                                                                    (seq (assert (eq (identifier "label2_671") (u16 6))) (add (identifier "sz_670") (size 2)))))))))))
                                                        (seq (assert (eq (identifier "label2_663") (u16 6))) (add (add (add (identifier "sz_662") (size 2)) (size 8)) (size 4)))))))))))))))))))))))))))))
 */
static std::function<Size(t)> sersize_of_row_binary_init()
{
  std::function<Size(t)> fun1202 { [&fun1202](t p_0) {
    uint16_t id_1203 { uint16_t(p_0.index()) };
    Size let_res_1204;
    {
      uint16_t label2_657 { id_1203 };
      uint16_t id_1205 { 0 };
      bool id_1206 { bool(id_1205 == label2_657) };
      Size choose_res_1207;
      if (id_1206) {
        Size id_1208 { 2UL };
        choose_res_1207 = id_1208;
      } else {
        uint16_t id_1209 { 1 };
        bool id_1210 { bool(id_1209 == label2_657) };
        Size choose_res_1211;
        if (id_1210) {
          Size id_1212 { 2UL };
          choose_res_1211 = id_1212;
        } else {
          uint16_t id_1213 { 2 };
          bool id_1214 { bool(id_1213 == label2_657) };
          Size choose_res_1215;
          if (id_1214) {
            Size id_1216 { 2UL };
            std::string id_1217 { std::get<2>(p_0) };
            uint32_t id_1218 { (uint32_t)id_1217.size() };
            Vec<1, uint32_t> id_1219 {  id_1218  };
            Size let_res_1220;
            {
              Vec<1, uint32_t> n_ref_740 { id_1219 };
              uint32_t id_1221 { 1U };
              Vec<1, uint32_t> id_1222 {  id_1221  };
              Size let_res_1223;
              {
                Vec<1, uint32_t> lebsz_ref_741 { id_1222 };
                bool while_flag_1224 { true };
                do {
                  uint8_t id_1225 { 0 };
                  uint32_t id_1226 { n_ref_740[id_1225] };
                  uint8_t id_1227 { 0 };
                  uint32_t id_1228 { lebsz_ref_741[id_1227] };
                  uint8_t id_1229 { 7 };
                  uint32_t id_1230 { uint32_t(id_1228 << id_1229) };
                  bool id_1231 { bool(id_1226 >= id_1230) };
                  while_flag_1224 = id_1231;
                  if (while_flag_1224) {
                    uint8_t id_1232 { 0 };
                    uint8_t id_1233 { 0 };
                    uint32_t id_1234 { lebsz_ref_741[id_1233] };
                    uint32_t id_1235 { 1U };
                    uint32_t id_1236 { uint32_t(id_1234 + id_1235) };
                    Void id_1237 { ((void)(lebsz_ref_741[id_1232] = id_1236), VOID) };
                  }
                } while (while_flag_1224);
                uint8_t id_1238 { 0 };
                uint32_t id_1239 { lebsz_ref_741[id_1238] };
                Size id_1240 { Size(id_1239) };
                let_res_1223 = id_1240;
              }
              let_res_1220 = let_res_1223;
            }
            std::string id_1241 { std::get<2>(p_0) };
            uint32_t id_1242 { (uint32_t)id_1241.size() };
            Size id_1243 { Size(id_1242) };
            Size id_1244 { Size(let_res_1220 + id_1243) };
            Size id_1245 { Size(id_1216 + id_1244) };
            choose_res_1215 = id_1245;
          } else {
            uint16_t id_1246 { 3 };
            bool id_1247 { bool(id_1246 == label2_657) };
            Size choose_res_1248;
            if (id_1247) {
              Size id_1249 { 2UL };
              std::function<Size(*src_path)> id_1250 { dessser_gen::src_path.sersize_of_row_binary };
              c404d7e7dfb3057f4a4f6b6766eeb900 id_1251 { std::get<3>(p_0) };
              *src_path id_1252 { std::get<0>(id_1251) };
              Size id_1253 { id_1250(id_1252) };
              Size id_1254 { Size(id_1249 + id_1253) };
              Size let_res_1255;
              {
                Size sz_735 { id_1254 };
                c404d7e7dfb3057f4a4f6b6766eeb900 id_1256 { std::get<3>(p_0) };
                std::string id_1257 { std::get<1>(id_1256) };
                uint32_t id_1258 { (uint32_t)id_1257.size() };
                Vec<1, uint32_t> id_1259 {  id_1258  };
                Size let_res_1260;
                {
                  Vec<1, uint32_t> n_ref_737 { id_1259 };
                  uint32_t id_1261 { 1U };
                  Vec<1, uint32_t> id_1262 {  id_1261  };
                  Size let_res_1263;
                  {
                    Vec<1, uint32_t> lebsz_ref_738 { id_1262 };
                    bool while_flag_1264 { true };
                    do {
                      uint8_t id_1265 { 0 };
                      uint32_t id_1266 { n_ref_737[id_1265] };
                      uint8_t id_1267 { 0 };
                      uint32_t id_1268 { lebsz_ref_738[id_1267] };
                      uint8_t id_1269 { 7 };
                      uint32_t id_1270 { uint32_t(id_1268 << id_1269) };
                      bool id_1271 { bool(id_1266 >= id_1270) };
                      while_flag_1264 = id_1271;
                      if (while_flag_1264) {
                        uint8_t id_1272 { 0 };
                        uint8_t id_1273 { 0 };
                        uint32_t id_1274 { lebsz_ref_738[id_1273] };
                        uint32_t id_1275 { 1U };
                        uint32_t id_1276 { uint32_t(id_1274 + id_1275) };
                        Void id_1277 { ((void)(lebsz_ref_738[id_1272] = id_1276), VOID) };
                      }
                    } while (while_flag_1264);
                    uint8_t id_1278 { 0 };
                    uint32_t id_1279 { lebsz_ref_738[id_1278] };
                    Size id_1280 { Size(id_1279) };
                    let_res_1263 = id_1280;
                  }
                  let_res_1260 = let_res_1263;
                }
                c404d7e7dfb3057f4a4f6b6766eeb900 id_1281 { std::get<3>(p_0) };
                std::string id_1282 { std::get<1>(id_1281) };
                uint32_t id_1283 { (uint32_t)id_1282.size() };
                Size id_1284 { Size(id_1283) };
                Size id_1285 { Size(let_res_1260 + id_1284) };
                Size id_1286 { Size(sz_735 + id_1285) };
                let_res_1255 = id_1286;
              }
              choose_res_1248 = let_res_1255;
            } else {
              uint16_t id_1287 { 4 };
              bool id_1288 { bool(id_1287 == label2_657) };
              Size choose_res_1289;
              if (id_1288) {
                Size id_1290 { 2UL };
                choose_res_1289 = id_1290;
              } else {
                uint16_t id_1291 { 5 };
                bool id_1292 { bool(id_1291 == label2_657) };
                Size choose_res_1293;
                if (id_1292) {
                  Size id_1294 { 2UL };
                  std::function<Size(*site_name)> id_1295 { dessser_gen::site_name.sersize_of_row_binary };
                  v_26540a608fe059393cc3cd282be43df3 id_1296 { std::get<5>(p_0) };
                  *site_name id_1297 { std::get<0>(id_1296) };
                  Size id_1298 { id_1295(id_1297) };
                  Size id_1299 { Size(id_1294 + id_1298) };
                  Size let_res_1300;
                  {
                    Size sz_711 { id_1299 };
                    uint16_t id_1301 { 0 };
                    v_26540a608fe059393cc3cd282be43df3 id_1302 { std::get<5>(p_0) };
                    v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1303 { std::get<1>(id_1302) };
                    uint16_t id_1304 { uint16_t(id_1303.index()) };
                    bool id_1305 { bool(id_1301 == id_1304) };
                    Size choose_res_1306;
                    if (id_1305) {
                      Size id_1307 { 2UL };
                      Size id_1308 { Size(sz_711 + id_1307) };
                      choose_res_1306 = id_1308;
                    } else {
                      uint16_t id_1309 { 1 };
                      v_26540a608fe059393cc3cd282be43df3 id_1310 { std::get<5>(p_0) };
                      v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1311 { std::get<1>(id_1310) };
                      uint16_t id_1312 { uint16_t(id_1311.index()) };
                      bool id_1313 { bool(id_1309 == id_1312) };
                      Size choose_res_1314;
                      if (id_1313) {
                        Size id_1315 { 2UL };
                        Size id_1316 { Size(sz_711 + id_1315) };
                        v_26540a608fe059393cc3cd282be43df3 id_1317 { std::get<5>(p_0) };
                        v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1318 { std::get<1>(id_1317) };
                        c8d851022c838ee90bc952d525c2d3aa id_1319 { std::get<1>(id_1318) };
                        std::string id_1320 { std::get<0>(id_1319) };
                        uint32_t id_1321 { (uint32_t)id_1320.size() };
                        Vec<1, uint32_t> id_1322 {  id_1321  };
                        Size let_res_1323;
                        {
                          Vec<1, uint32_t> n_ref_730 { id_1322 };
                          uint32_t id_1324 { 1U };
                          Vec<1, uint32_t> id_1325 {  id_1324  };
                          Size let_res_1326;
                          {
                            Vec<1, uint32_t> lebsz_ref_731 { id_1325 };
                            bool while_flag_1327 { true };
                            do {
                              uint8_t id_1328 { 0 };
                              uint32_t id_1329 { n_ref_730[id_1328] };
                              uint8_t id_1330 { 0 };
                              uint32_t id_1331 { lebsz_ref_731[id_1330] };
                              uint8_t id_1332 { 7 };
                              uint32_t id_1333 { uint32_t(id_1331 << id_1332) };
                              bool id_1334 { bool(id_1329 >= id_1333) };
                              while_flag_1327 = id_1334;
                              if (while_flag_1327) {
                                uint8_t id_1335 { 0 };
                                uint8_t id_1336 { 0 };
                                uint32_t id_1337 { lebsz_ref_731[id_1336] };
                                uint32_t id_1338 { 1U };
                                uint32_t id_1339 { uint32_t(id_1337 + id_1338) };
                                Void id_1340 { ((void)(lebsz_ref_731[id_1335] = id_1339), VOID) };
                              }
                            } while (while_flag_1327);
                            uint8_t id_1341 { 0 };
                            uint32_t id_1342 { lebsz_ref_731[id_1341] };
                            Size id_1343 { Size(id_1342) };
                            let_res_1326 = id_1343;
                          }
                          let_res_1323 = let_res_1326;
                        }
                        v_26540a608fe059393cc3cd282be43df3 id_1344 { std::get<5>(p_0) };
                        v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1345 { std::get<1>(id_1344) };
                        c8d851022c838ee90bc952d525c2d3aa id_1346 { std::get<1>(id_1345) };
                        std::string id_1347 { std::get<0>(id_1346) };
                        uint32_t id_1348 { (uint32_t)id_1347.size() };
                        Size id_1349 { Size(id_1348) };
                        Size id_1350 { Size(let_res_1323 + id_1349) };
                        Size id_1351 { Size(id_1316 + id_1350) };
                        Size let_res_1352;
                        {
                          Size sz_732 { id_1351 };
                          uint16_t id_1353 { 0 };
                          v_26540a608fe059393cc3cd282be43df3 id_1354 { std::get<5>(p_0) };
                          v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1355 { std::get<1>(id_1354) };
                          c8d851022c838ee90bc952d525c2d3aa id_1356 { std::get<1>(id_1355) };
                          v_1e81caa74ae611e9cb191b8ee50bee25 id_1357 { std::get<1>(id_1356) };
                          uint16_t id_1358 { uint16_t(id_1357.index()) };
                          bool id_1359 { bool(id_1353 == id_1358) };
                          Size choose_res_1360;
                          if (id_1359) {
                            Size id_1361 { 2UL };
                            Size id_1362 { Size(sz_732 + id_1361) };
                            choose_res_1360 = id_1362;
                          } else {
                            v_26540a608fe059393cc3cd282be43df3 id_1363 { std::get<5>(p_0) };
                            v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1364 { std::get<1>(id_1363) };
                            c8d851022c838ee90bc952d525c2d3aa id_1365 { std::get<1>(id_1364) };
                            v_1e81caa74ae611e9cb191b8ee50bee25 id_1366 { std::get<1>(id_1365) };
                            uint16_t id_1367 { uint16_t(id_1366.index()) };
                            uint16_t id_1368 { 1 };
                            bool id_1369 { bool(id_1367 == id_1368) };
                            Void id_1370 { ((void)(assert(id_1369)), VOID) };
                            Size id_1371 { 2UL };
                            Size id_1372 { Size(sz_732 + id_1371) };
                            choose_res_1360 = id_1372;
                          }
                          let_res_1352 = choose_res_1360;
                        }
                        choose_res_1314 = let_res_1352;
                      } else {
                        uint16_t id_1373 { 2 };
                        v_26540a608fe059393cc3cd282be43df3 id_1374 { std::get<5>(p_0) };
                        v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1375 { std::get<1>(id_1374) };
                        uint16_t id_1376 { uint16_t(id_1375.index()) };
                        bool id_1377 { bool(id_1373 == id_1376) };
                        Size choose_res_1378;
                        if (id_1377) {
                          Size id_1379 { 2UL };
                          Size id_1380 { Size(sz_711 + id_1379) };
                          std::function<Size(*fq_name)> id_1381 { dessser_gen::fq_name.sersize_of_row_binary };
                          v_26540a608fe059393cc3cd282be43df3 id_1382 { std::get<5>(p_0) };
                          v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1383 { std::get<1>(id_1382) };
                          v_0fab8a04cd41fd489e58d011ef6f08ad id_1384 { std::get<2>(id_1383) };
                          *fq_name id_1385 { std::get<0>(id_1384) };
                          Size id_1386 { id_1381(id_1385) };
                          Size id_1387 { Size(id_1380 + id_1386) };
                          Size let_res_1388;
                          {
                            Size sz_720 { id_1387 };
                            v_26540a608fe059393cc3cd282be43df3 id_1389 { std::get<5>(p_0) };
                            v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1390 { std::get<1>(id_1389) };
                            v_0fab8a04cd41fd489e58d011ef6f08ad id_1391 { std::get<2>(id_1390) };
                            v_8c6c9edc5b1d709b5094571801c00912 id_1392 { std::get<1>(id_1391) };
                            uint16_t id_1393 { uint16_t(id_1392.index()) };
                            Size let_res_1394;
                            {
                              uint16_t label2_721 { id_1393 };
                              uint16_t id_1395 { 0 };
                              bool id_1396 { bool(id_1395 == label2_721) };
                              Size choose_res_1397;
                              if (id_1396) {
                                Size id_1398 { 2UL };
                                Size id_1399 { Size(sz_720 + id_1398) };
                                choose_res_1397 = id_1399;
                              } else {
                                uint16_t id_1400 { 1 };
                                bool id_1401 { bool(id_1400 == label2_721) };
                                Size choose_res_1402;
                                if (id_1401) {
                                  Size id_1403 { 2UL };
                                  Size id_1404 { Size(sz_720 + id_1403) };
                                  choose_res_1402 = id_1404;
                                } else {
                                  uint16_t id_1405 { 2 };
                                  bool id_1406 { bool(id_1405 == label2_721) };
                                  Size choose_res_1407;
                                  if (id_1406) {
                                    Size id_1408 { 2UL };
                                    Size id_1409 { Size(sz_720 + id_1408) };
                                    choose_res_1407 = id_1409;
                                  } else {
                                    uint16_t id_1410 { 3 };
                                    bool id_1411 { bool(id_1410 == label2_721) };
                                    Size choose_res_1412;
                                    if (id_1411) {
                                      Size id_1413 { 2UL };
                                      Size id_1414 { Size(sz_720 + id_1413) };
                                      choose_res_1412 = id_1414;
                                    } else {
                                      uint16_t id_1415 { 4 };
                                      bool id_1416 { bool(id_1415 == label2_721) };
                                      Size choose_res_1417;
                                      if (id_1416) {
                                        Size id_1418 { 2UL };
                                        Size id_1419 { Size(sz_720 + id_1418) };
                                        choose_res_1417 = id_1419;
                                      } else {
                                        uint16_t id_1420 { 5 };
                                        bool id_1421 { bool(id_1420 == label2_721) };
                                        Size choose_res_1422;
                                        if (id_1421) {
                                          Size id_1423 { 2UL };
                                          Size id_1424 { Size(sz_720 + id_1423) };
                                          choose_res_1422 = id_1424;
                                        } else {
                                          uint16_t id_1425 { 6 };
                                          bool id_1426 { bool(id_1425 == label2_721) };
                                          Size choose_res_1427;
                                          if (id_1426) {
                                            Size id_1428 { 2UL };
                                            Size id_1429 { Size(sz_720 + id_1428) };
                                            v_26540a608fe059393cc3cd282be43df3 id_1430 { std::get<5>(p_0) };
                                            v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1431 { std::get<1>(id_1430) };
                                            v_0fab8a04cd41fd489e58d011ef6f08ad id_1432 { std::get<2>(id_1431) };
                                            v_8c6c9edc5b1d709b5094571801c00912 id_1433 { std::get<1>(id_1432) };
                                            a9a5fa86cfaa17c85b3606d1a4582bcd id_1434 { std::get<6>(id_1433) };
                                            std::string id_1435 { std::get<0>(id_1434) };
                                            uint32_t id_1436 { (uint32_t)id_1435.size() };
                                            Vec<1, uint32_t> id_1437 {  id_1436  };
                                            Size let_res_1438;
                                            {
                                              Vec<1, uint32_t> n_ref_724 { id_1437 };
                                              uint32_t id_1439 { 1U };
                                              Vec<1, uint32_t> id_1440 {  id_1439  };
                                              Size let_res_1441;
                                              {
                                                Vec<1, uint32_t> lebsz_ref_725 { id_1440 };
                                                bool while_flag_1442 { true };
                                                do {
                                                  uint8_t id_1443 { 0 };
                                                  uint32_t id_1444 { n_ref_724[id_1443] };
                                                  uint8_t id_1445 { 0 };
                                                  uint32_t id_1446 { lebsz_ref_725[id_1445] };
                                                  uint8_t id_1447 { 7 };
                                                  uint32_t id_1448 { uint32_t(id_1446 << id_1447) };
                                                  bool id_1449 { bool(id_1444 >= id_1448) };
                                                  while_flag_1442 = id_1449;
                                                  if (while_flag_1442) {
                                                    uint8_t id_1450 { 0 };
                                                    uint8_t id_1451 { 0 };
                                                    uint32_t id_1452 { lebsz_ref_725[id_1451] };
                                                    uint32_t id_1453 { 1U };
                                                    uint32_t id_1454 { uint32_t(id_1452 + id_1453) };
                                                    Void id_1455 { ((void)(lebsz_ref_725[id_1450] = id_1454), VOID) };
                                                  }
                                                } while (while_flag_1442);
                                                uint8_t id_1456 { 0 };
                                                uint32_t id_1457 { lebsz_ref_725[id_1456] };
                                                Size id_1458 { Size(id_1457) };
                                                let_res_1441 = id_1458;
                                              }
                                              let_res_1438 = let_res_1441;
                                            }
                                            v_26540a608fe059393cc3cd282be43df3 id_1459 { std::get<5>(p_0) };
                                            v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1460 { std::get<1>(id_1459) };
                                            v_0fab8a04cd41fd489e58d011ef6f08ad id_1461 { std::get<2>(id_1460) };
                                            v_8c6c9edc5b1d709b5094571801c00912 id_1462 { std::get<1>(id_1461) };
                                            a9a5fa86cfaa17c85b3606d1a4582bcd id_1463 { std::get<6>(id_1462) };
                                            std::string id_1464 { std::get<0>(id_1463) };
                                            uint32_t id_1465 { (uint32_t)id_1464.size() };
                                            Size id_1466 { Size(id_1465) };
                                            Size id_1467 { Size(let_res_1438 + id_1466) };
                                            Size id_1468 { Size(id_1429 + id_1467) };
                                            Size let_res_1469;
                                            {
                                              Size sz_726 { id_1468 };
                                              v_26540a608fe059393cc3cd282be43df3 id_1470 { std::get<5>(p_0) };
                                              v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1471 { std::get<1>(id_1470) };
                                              v_0fab8a04cd41fd489e58d011ef6f08ad id_1472 { std::get<2>(id_1471) };
                                              v_8c6c9edc5b1d709b5094571801c00912 id_1473 { std::get<1>(id_1472) };
                                              a9a5fa86cfaa17c85b3606d1a4582bcd id_1474 { std::get<6>(id_1473) };
                                              v_8e097ae30bed5641a60541fcf38314dd id_1475 { std::get<1>(id_1474) };
                                              uint16_t id_1476 { uint16_t(id_1475.index()) };
                                              Size let_res_1477;
                                              {
                                                uint16_t label2_727 { id_1476 };
                                                uint16_t id_1478 { 0 };
                                                bool id_1479 { bool(id_1478 == label2_727) };
                                                Size choose_res_1480;
                                                if (id_1479) {
                                                  Size id_1481 { 2UL };
                                                  Size id_1482 { Size(sz_726 + id_1481) };
                                                  choose_res_1480 = id_1482;
                                                } else {
                                                  uint16_t id_1483 { 1 };
                                                  bool id_1484 { bool(id_1483 == label2_727) };
                                                  Size choose_res_1485;
                                                  if (id_1484) {
                                                    Size id_1486 { 2UL };
                                                    Size id_1487 { Size(sz_726 + id_1486) };
                                                    choose_res_1485 = id_1487;
                                                  } else {
                                                    uint16_t id_1488 { 2 };
                                                    bool id_1489 { bool(id_1488 == label2_727) };
                                                    Size choose_res_1490;
                                                    if (id_1489) {
                                                      Size id_1491 { 2UL };
                                                      Size id_1492 { Size(sz_726 + id_1491) };
                                                      choose_res_1490 = id_1492;
                                                    } else {
                                                      uint16_t id_1493 { 3 };
                                                      bool id_1494 { bool(id_1493 == label2_727) };
                                                      Size choose_res_1495;
                                                      if (id_1494) {
                                                        Size id_1496 { 2UL };
                                                        Size id_1497 { Size(sz_726 + id_1496) };
                                                        choose_res_1495 = id_1497;
                                                      } else {
                                                        uint16_t id_1498 { 4 };
                                                        bool id_1499 { bool(id_1498 == label2_727) };
                                                        Size choose_res_1500;
                                                        if (id_1499) {
                                                          Size id_1501 { 2UL };
                                                          Size id_1502 { Size(sz_726 + id_1501) };
                                                          choose_res_1500 = id_1502;
                                                        } else {
                                                          uint16_t id_1503 { 5 };
                                                          bool id_1504 { bool(id_1503 == label2_727) };
                                                          Size choose_res_1505;
                                                          if (id_1504) {
                                                            Size id_1506 { 2UL };
                                                            Size id_1507 { Size(sz_726 + id_1506) };
                                                            choose_res_1505 = id_1507;
                                                          } else {
                                                            uint16_t id_1508 { 6 };
                                                            bool id_1509 { bool(id_1508 == label2_727) };
                                                            Size choose_res_1510;
                                                            if (id_1509) {
                                                              Size id_1511 { 2UL };
                                                              Size id_1512 { Size(sz_726 + id_1511) };
                                                              choose_res_1510 = id_1512;
                                                            } else {
                                                              uint16_t id_1513 { 7 };
                                                              bool id_1514 { bool(label2_727 == id_1513) };
                                                              Void id_1515 { ((void)(assert(id_1514)), VOID) };
                                                              Size id_1516 { 2UL };
                                                              Size id_1517 { Size(sz_726 + id_1516) };
                                                              choose_res_1510 = id_1517;
                                                            }
                                                            choose_res_1505 = choose_res_1510;
                                                          }
                                                          choose_res_1500 = choose_res_1505;
                                                        }
                                                        choose_res_1495 = choose_res_1500;
                                                      }
                                                      choose_res_1490 = choose_res_1495;
                                                    }
                                                    choose_res_1485 = choose_res_1490;
                                                  }
                                                  choose_res_1480 = choose_res_1485;
                                                }
                                                let_res_1477 = choose_res_1480;
                                              }
                                              let_res_1469 = let_res_1477;
                                            }
                                            choose_res_1427 = let_res_1469;
                                          } else {
                                            uint16_t id_1518 { 7 };
                                            bool id_1519 { bool(id_1518 == label2_721) };
                                            Size choose_res_1520;
                                            if (id_1519) {
                                              Size id_1521 { 2UL };
                                              Size id_1522 { Size(sz_720 + id_1521) };
                                              Size id_1523 { 4UL };
                                              Size id_1524 { Size(id_1522 + id_1523) };
                                              choose_res_1520 = id_1524;
                                            } else {
                                              uint16_t id_1525 { 8 };
                                              bool id_1526 { bool(label2_721 == id_1525) };
                                              Void id_1527 { ((void)(assert(id_1526)), VOID) };
                                              Size id_1528 { 2UL };
                                              Size id_1529 { Size(sz_720 + id_1528) };
                                              choose_res_1520 = id_1529;
                                            }
                                            choose_res_1427 = choose_res_1520;
                                          }
                                          choose_res_1422 = choose_res_1427;
                                        }
                                        choose_res_1417 = choose_res_1422;
                                      }
                                      choose_res_1412 = choose_res_1417;
                                    }
                                    choose_res_1407 = choose_res_1412;
                                  }
                                  choose_res_1402 = choose_res_1407;
                                }
                                choose_res_1397 = choose_res_1402;
                              }
                              let_res_1394 = choose_res_1397;
                            }
                            let_res_1388 = let_res_1394;
                          }
                          choose_res_1378 = let_res_1388;
                        } else {
                          v_26540a608fe059393cc3cd282be43df3 id_1530 { std::get<5>(p_0) };
                          v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1531 { std::get<1>(id_1530) };
                          uint16_t id_1532 { uint16_t(id_1531.index()) };
                          uint16_t id_1533 { 3 };
                          bool id_1534 { bool(id_1532 == id_1533) };
                          Void id_1535 { ((void)(assert(id_1534)), VOID) };
                          Size id_1536 { 2UL };
                          Size id_1537 { Size(sz_711 + id_1536) };
                          v_26540a608fe059393cc3cd282be43df3 id_1538 { std::get<5>(p_0) };
                          v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1539 { std::get<1>(id_1538) };
                          v_9a47b091ef9a7a446e50646760330664 id_1540 { std::get<3>(id_1539) };
                          std::string id_1541 { std::get<0>(id_1540) };
                          uint32_t id_1542 { (uint32_t)id_1541.size() };
                          Vec<1, uint32_t> id_1543 {  id_1542  };
                          Size let_res_1544;
                          {
                            Vec<1, uint32_t> n_ref_715 { id_1543 };
                            uint32_t id_1545 { 1U };
                            Vec<1, uint32_t> id_1546 {  id_1545  };
                            Size let_res_1547;
                            {
                              Vec<1, uint32_t> lebsz_ref_716 { id_1546 };
                              bool while_flag_1548 { true };
                              do {
                                uint8_t id_1549 { 0 };
                                uint32_t id_1550 { n_ref_715[id_1549] };
                                uint8_t id_1551 { 0 };
                                uint32_t id_1552 { lebsz_ref_716[id_1551] };
                                uint8_t id_1553 { 7 };
                                uint32_t id_1554 { uint32_t(id_1552 << id_1553) };
                                bool id_1555 { bool(id_1550 >= id_1554) };
                                while_flag_1548 = id_1555;
                                if (while_flag_1548) {
                                  uint8_t id_1556 { 0 };
                                  uint8_t id_1557 { 0 };
                                  uint32_t id_1558 { lebsz_ref_716[id_1557] };
                                  uint32_t id_1559 { 1U };
                                  uint32_t id_1560 { uint32_t(id_1558 + id_1559) };
                                  Void id_1561 { ((void)(lebsz_ref_716[id_1556] = id_1560), VOID) };
                                }
                              } while (while_flag_1548);
                              uint8_t id_1562 { 0 };
                              uint32_t id_1563 { lebsz_ref_716[id_1562] };
                              Size id_1564 { Size(id_1563) };
                              let_res_1547 = id_1564;
                            }
                            let_res_1544 = let_res_1547;
                          }
                          v_26540a608fe059393cc3cd282be43df3 id_1565 { std::get<5>(p_0) };
                          v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1566 { std::get<1>(id_1565) };
                          v_9a47b091ef9a7a446e50646760330664 id_1567 { std::get<3>(id_1566) };
                          std::string id_1568 { std::get<0>(id_1567) };
                          uint32_t id_1569 { (uint32_t)id_1568.size() };
                          Size id_1570 { Size(id_1569) };
                          Size id_1571 { Size(let_res_1544 + id_1570) };
                          Size id_1572 { Size(id_1537 + id_1571) };
                          Size let_res_1573;
                          {
                            Size sz_717 { id_1572 };
                            v_26540a608fe059393cc3cd282be43df3 id_1574 { std::get<5>(p_0) };
                            v_320dee9bcc93c7ed0c75cc7db8b85d9b id_1575 { std::get<1>(id_1574) };
                            v_9a47b091ef9a7a446e50646760330664 id_1576 { std::get<3>(id_1575) };
                            v_5c73eec19356406029ebc971f8fc93ef id_1577 { std::get<1>(id_1576) };
                            uint16_t id_1578 { uint16_t(id_1577.index()) };
                            uint16_t id_1579 { 0 };
                            bool id_1580 { bool(id_1578 == id_1579) };
                            Void id_1581 { ((void)(assert(id_1580)), VOID) };
                            Size id_1582 { 2UL };
                            Size id_1583 { Size(sz_717 + id_1582) };
                            let_res_1573 = id_1583;
                          }
                          choose_res_1378 = let_res_1573;
                        }
                        choose_res_1314 = choose_res_1378;
                      }
                      choose_res_1306 = choose_res_1314;
                    }
                    let_res_1300 = choose_res_1306;
                  }
                  choose_res_1293 = let_res_1300;
                } else {
                  uint16_t id_1584 { 6 };
                  bool id_1585 { bool(id_1584 == label2_657) };
                  Size choose_res_1586;
                  if (id_1585) {
                    uint16_t id_1587 { 0 };
                    v_60ff76b761c62e00eb6df04e7d00fbc8 id_1588 { std::get<6>(p_0) };
                    uint16_t id_1589 { uint16_t(id_1588.index()) };
                    bool id_1590 { bool(id_1587 == id_1589) };
                    Size choose_res_1591;
                    if (id_1590) {
                      Size id_1592 { 4UL };
                      choose_res_1591 = id_1592;
                    } else {
                      uint16_t id_1593 { 1 };
                      v_60ff76b761c62e00eb6df04e7d00fbc8 id_1594 { std::get<6>(p_0) };
                      uint16_t id_1595 { uint16_t(id_1594.index()) };
                      bool id_1596 { bool(id_1593 == id_1595) };
                      Size choose_res_1597;
                      if (id_1596) {
                        Size id_1598 { 4UL };
                        choose_res_1597 = id_1598;
                      } else {
                        v_60ff76b761c62e00eb6df04e7d00fbc8 id_1599 { std::get<6>(p_0) };
                        uint16_t id_1600 { uint16_t(id_1599.index()) };
                        uint16_t id_1601 { 2 };
                        bool id_1602 { bool(id_1600 == id_1601) };
                        Void id_1603 { ((void)(assert(id_1602)), VOID) };
                        Size id_1604 { 4UL };
                        v_60ff76b761c62e00eb6df04e7d00fbc8 id_1605 { std::get<6>(p_0) };
                        std::string id_1606 { std::get<2>(id_1605) };
                        uint32_t id_1607 { (uint32_t)id_1606.size() };
                        Vec<1, uint32_t> id_1608 {  id_1607  };
                        Size let_res_1609;
                        {
                          Vec<1, uint32_t> n_ref_708 { id_1608 };
                          uint32_t id_1610 { 1U };
                          Vec<1, uint32_t> id_1611 {  id_1610  };
                          Size let_res_1612;
                          {
                            Vec<1, uint32_t> lebsz_ref_709 { id_1611 };
                            bool while_flag_1613 { true };
                            do {
                              uint8_t id_1614 { 0 };
                              uint32_t id_1615 { n_ref_708[id_1614] };
                              uint8_t id_1616 { 0 };
                              uint32_t id_1617 { lebsz_ref_709[id_1616] };
                              uint8_t id_1618 { 7 };
                              uint32_t id_1619 { uint32_t(id_1617 << id_1618) };
                              bool id_1620 { bool(id_1615 >= id_1619) };
                              while_flag_1613 = id_1620;
                              if (while_flag_1613) {
                                uint8_t id_1621 { 0 };
                                uint8_t id_1622 { 0 };
                                uint32_t id_1623 { lebsz_ref_709[id_1622] };
                                uint32_t id_1624 { 1U };
                                uint32_t id_1625 { uint32_t(id_1623 + id_1624) };
                                Void id_1626 { ((void)(lebsz_ref_709[id_1621] = id_1625), VOID) };
                              }
                            } while (while_flag_1613);
                            uint8_t id_1627 { 0 };
                            uint32_t id_1628 { lebsz_ref_709[id_1627] };
                            Size id_1629 { Size(id_1628) };
                            let_res_1612 = id_1629;
                          }
                          let_res_1609 = let_res_1612;
                        }
                        v_60ff76b761c62e00eb6df04e7d00fbc8 id_1630 { std::get<6>(p_0) };
                        std::string id_1631 { std::get<2>(id_1630) };
                        uint32_t id_1632 { (uint32_t)id_1631.size() };
                        Size id_1633 { Size(id_1632) };
                        Size id_1634 { Size(let_res_1609 + id_1633) };
                        Size id_1635 { Size(id_1604 + id_1634) };
                        choose_res_1597 = id_1635;
                      }
                      choose_res_1591 = choose_res_1597;
                    }
                    choose_res_1586 = choose_res_1591;
                  } else {
                    uint16_t id_1636 { 7 };
                    bool id_1637 { bool(id_1636 == label2_657) };
                    Size choose_res_1638;
                    if (id_1637) {
                      Size id_1639 { 2UL };
                      std::function<Size(*site_name)> id_1640 { dessser_gen::site_name.sersize_of_row_binary };
                      v_3a6e990115d17bf3eefa1b91b13ca80b id_1641 { std::get<7>(p_0) };
                      *site_name id_1642 { std::get<0>(id_1641) };
                      Size id_1643 { id_1640(id_1642) };
                      Size id_1644 { Size(id_1639 + id_1643) };
                      Size let_res_1645;
                      {
                        Size sz_696 { id_1644 };
                        std::function<Size(*fq_name)> id_1646 { dessser_gen::fq_name.sersize_of_row_binary };
                        v_3a6e990115d17bf3eefa1b91b13ca80b id_1647 { std::get<7>(p_0) };
                        *fq_name id_1648 { std::get<1>(id_1647) };
                        Size id_1649 { id_1646(id_1648) };
                        Size id_1650 { Size(sz_696 + id_1649) };
                        let_res_1645 = id_1650;
                      }
                      Size let_res_1651;
                      {
                        Size sz_697 { let_res_1645 };
                        v_3a6e990115d17bf3eefa1b91b13ca80b id_1652 { std::get<7>(p_0) };
                        std::string id_1653 { std::get<2>(id_1652) };
                        uint32_t id_1654 { (uint32_t)id_1653.size() };
                        Vec<1, uint32_t> id_1655 {  id_1654  };
                        Size let_res_1656;
                        {
                          Vec<1, uint32_t> n_ref_699 { id_1655 };
                          uint32_t id_1657 { 1U };
                          Vec<1, uint32_t> id_1658 {  id_1657  };
                          Size let_res_1659;
                          {
                            Vec<1, uint32_t> lebsz_ref_700 { id_1658 };
                            bool while_flag_1660 { true };
                            do {
                              uint8_t id_1661 { 0 };
                              uint32_t id_1662 { n_ref_699[id_1661] };
                              uint8_t id_1663 { 0 };
                              uint32_t id_1664 { lebsz_ref_700[id_1663] };
                              uint8_t id_1665 { 7 };
                              uint32_t id_1666 { uint32_t(id_1664 << id_1665) };
                              bool id_1667 { bool(id_1662 >= id_1666) };
                              while_flag_1660 = id_1667;
                              if (while_flag_1660) {
                                uint8_t id_1668 { 0 };
                                uint8_t id_1669 { 0 };
                                uint32_t id_1670 { lebsz_ref_700[id_1669] };
                                uint32_t id_1671 { 1U };
                                uint32_t id_1672 { uint32_t(id_1670 + id_1671) };
                                Void id_1673 { ((void)(lebsz_ref_700[id_1668] = id_1672), VOID) };
                              }
                            } while (while_flag_1660);
                            uint8_t id_1674 { 0 };
                            uint32_t id_1675 { lebsz_ref_700[id_1674] };
                            Size id_1676 { Size(id_1675) };
                            let_res_1659 = id_1676;
                          }
                          let_res_1656 = let_res_1659;
                        }
                        v_3a6e990115d17bf3eefa1b91b13ca80b id_1677 { std::get<7>(p_0) };
                        std::string id_1678 { std::get<2>(id_1677) };
                        uint32_t id_1679 { (uint32_t)id_1678.size() };
                        Size id_1680 { Size(id_1679) };
                        Size id_1681 { Size(let_res_1656 + id_1680) };
                        Size id_1682 { Size(sz_697 + id_1681) };
                        let_res_1651 = id_1682;
                      }
                      Size let_res_1683;
                      {
                        Size sz_701 { let_res_1651 };
                        uint16_t id_1684 { 0 };
                        v_3a6e990115d17bf3eefa1b91b13ca80b id_1685 { std::get<7>(p_0) };
                        v_6c1c7418355e363a303990cad40945dd id_1686 { std::get<3>(id_1685) };
                        uint16_t id_1687 { uint16_t(id_1686.index()) };
                        bool id_1688 { bool(id_1684 == id_1687) };
                        Size choose_res_1689;
                        if (id_1688) {
                          Size id_1690 { 2UL };
                          Size id_1691 { Size(sz_701 + id_1690) };
                          v_3a6e990115d17bf3eefa1b91b13ca80b id_1692 { std::get<7>(p_0) };
                          v_6c1c7418355e363a303990cad40945dd id_1693 { std::get<3>(id_1692) };
                          std::string id_1694 { std::get<0>(id_1693) };
                          uint32_t id_1695 { (uint32_t)id_1694.size() };
                          Vec<1, uint32_t> id_1696 {  id_1695  };
                          Size let_res_1697;
                          {
                            Vec<1, uint32_t> n_ref_704 { id_1696 };
                            uint32_t id_1698 { 1U };
                            Vec<1, uint32_t> id_1699 {  id_1698  };
                            Size let_res_1700;
                            {
                              Vec<1, uint32_t> lebsz_ref_705 { id_1699 };
                              bool while_flag_1701 { true };
                              do {
                                uint8_t id_1702 { 0 };
                                uint32_t id_1703 { n_ref_704[id_1702] };
                                uint8_t id_1704 { 0 };
                                uint32_t id_1705 { lebsz_ref_705[id_1704] };
                                uint8_t id_1706 { 7 };
                                uint32_t id_1707 { uint32_t(id_1705 << id_1706) };
                                bool id_1708 { bool(id_1703 >= id_1707) };
                                while_flag_1701 = id_1708;
                                if (while_flag_1701) {
                                  uint8_t id_1709 { 0 };
                                  uint8_t id_1710 { 0 };
                                  uint32_t id_1711 { lebsz_ref_705[id_1710] };
                                  uint32_t id_1712 { 1U };
                                  uint32_t id_1713 { uint32_t(id_1711 + id_1712) };
                                  Void id_1714 { ((void)(lebsz_ref_705[id_1709] = id_1713), VOID) };
                                }
                              } while (while_flag_1701);
                              uint8_t id_1715 { 0 };
                              uint32_t id_1716 { lebsz_ref_705[id_1715] };
                              Size id_1717 { Size(id_1716) };
                              let_res_1700 = id_1717;
                            }
                            let_res_1697 = let_res_1700;
                          }
                          v_3a6e990115d17bf3eefa1b91b13ca80b id_1718 { std::get<7>(p_0) };
                          v_6c1c7418355e363a303990cad40945dd id_1719 { std::get<3>(id_1718) };
                          std::string id_1720 { std::get<0>(id_1719) };
                          uint32_t id_1721 { (uint32_t)id_1720.size() };
                          Size id_1722 { Size(id_1721) };
                          Size id_1723 { Size(let_res_1697 + id_1722) };
                          Size id_1724 { Size(id_1691 + id_1723) };
                          choose_res_1689 = id_1724;
                        } else {
                          v_3a6e990115d17bf3eefa1b91b13ca80b id_1725 { std::get<7>(p_0) };
                          v_6c1c7418355e363a303990cad40945dd id_1726 { std::get<3>(id_1725) };
                          uint16_t id_1727 { uint16_t(id_1726.index()) };
                          uint16_t id_1728 { 1 };
                          bool id_1729 { bool(id_1727 == id_1728) };
                          Void id_1730 { ((void)(assert(id_1729)), VOID) };
                          Size id_1731 { 2UL };
                          Size id_1732 { Size(sz_701 + id_1731) };
                          Size id_1733 { 4UL };
                          Size id_1734 { Size(id_1732 + id_1733) };
                          choose_res_1689 = id_1734;
                        }
                        let_res_1683 = choose_res_1689;
                      }
                      choose_res_1638 = let_res_1683;
                    } else {
                      uint16_t id_1735 { 8 };
                      bool id_1736 { bool(id_1735 == label2_657) };
                      Size choose_res_1737;
                      if (id_1736) {
                        Size id_1738 { 4UL };
                        choose_res_1737 = id_1738;
                      } else {
                        uint16_t id_1739 { 9 };
                        bool id_1740 { bool(id_1739 == label2_657) };
                        Size choose_res_1741;
                        if (id_1740) {
                          std::optional<*sync_socket> id_1742 { std::get<9>(p_0) };
                          bool id_1743 { !(id_1742.has_value ()) };
                          Size choose_res_1744;
                          if (id_1743) {
                            Size id_1745 { 3UL };
                            choose_res_1744 = id_1745;
                          } else {
                            Size id_1746 { 2UL };
                            std::function<Size(*sync_socket)> id_1747 { dessser_gen::sync_socket.sersize_of_row_binary };
                            std::optional<*sync_socket> id_1748 { std::get<9>(p_0) };
                            *sync_socket id_1749 { id_1748.value() };
                            Size id_1750 { id_1747(id_1749) };
                            Size id_1751 { Size(id_1746 + id_1750) };
                            Size id_1752 { 1UL };
                            Size id_1753 { Size(id_1751 + id_1752) };
                            choose_res_1744 = id_1753;
                          }
                          choose_res_1741 = choose_res_1744;
                        } else {
                          uint16_t id_1754 { 10 };
                          bool id_1755 { bool(id_1754 == label2_657) };
                          Size choose_res_1756;
                          if (id_1755) {
                            Size id_1757 { 2UL };
                            choose_res_1756 = id_1757;
                          } else {
                            uint16_t id_1758 { 11 };
                            bool id_1759 { bool(id_1758 == label2_657) };
                            Size choose_res_1760;
                            if (id_1759) {
                              Size id_1761 { 2UL };
                              std::function<Size(*sync_socket)> id_1762 { dessser_gen::sync_socket.sersize_of_row_binary };
                              v_287d43b770d826e060b1e65a4d07e0b0 id_1763 { std::get<11>(p_0) };
                              *sync_socket id_1764 { std::get<0>(id_1763) };
                              Size id_1765 { id_1762(id_1764) };
                              Size id_1766 { Size(id_1761 + id_1765) };
                              Size let_res_1767;
                              {
                                Size sz_690 { id_1766 };
                                uint16_t id_1768 { 0 };
                                v_287d43b770d826e060b1e65a4d07e0b0 id_1769 { std::get<11>(p_0) };
                                v_90e4213e12fd850ebf8d15b08342b17e id_1770 { std::get<1>(id_1769) };
                                uint16_t id_1771 { uint16_t(id_1770.index()) };
                                bool id_1772 { bool(id_1768 == id_1771) };
                                Size choose_res_1773;
                                if (id_1772) {
                                  Size id_1774 { 2UL };
                                  Size id_1775 { Size(sz_690 + id_1774) };
                                  v_287d43b770d826e060b1e65a4d07e0b0 id_1776 { std::get<11>(p_0) };
                                  v_90e4213e12fd850ebf8d15b08342b17e id_1777 { std::get<1>(id_1776) };
                                  std::string id_1778 { std::get<0>(id_1777) };
                                  uint32_t id_1779 { (uint32_t)id_1778.size() };
                                  Vec<1, uint32_t> id_1780 {  id_1779  };
                                  Size let_res_1781;
                                  {
                                    Vec<1, uint32_t> n_ref_693 { id_1780 };
                                    uint32_t id_1782 { 1U };
                                    Vec<1, uint32_t> id_1783 {  id_1782  };
                                    Size let_res_1784;
                                    {
                                      Vec<1, uint32_t> lebsz_ref_694 { id_1783 };
                                      bool while_flag_1785 { true };
                                      do {
                                        uint8_t id_1786 { 0 };
                                        uint32_t id_1787 { n_ref_693[id_1786] };
                                        uint8_t id_1788 { 0 };
                                        uint32_t id_1789 { lebsz_ref_694[id_1788] };
                                        uint8_t id_1790 { 7 };
                                        uint32_t id_1791 { uint32_t(id_1789 << id_1790) };
                                        bool id_1792 { bool(id_1787 >= id_1791) };
                                        while_flag_1785 = id_1792;
                                        if (while_flag_1785) {
                                          uint8_t id_1793 { 0 };
                                          uint8_t id_1794 { 0 };
                                          uint32_t id_1795 { lebsz_ref_694[id_1794] };
                                          uint32_t id_1796 { 1U };
                                          uint32_t id_1797 { uint32_t(id_1795 + id_1796) };
                                          Void id_1798 { ((void)(lebsz_ref_694[id_1793] = id_1797), VOID) };
                                        }
                                      } while (while_flag_1785);
                                      uint8_t id_1799 { 0 };
                                      uint32_t id_1800 { lebsz_ref_694[id_1799] };
                                      Size id_1801 { Size(id_1800) };
                                      let_res_1784 = id_1801;
                                    }
                                    let_res_1781 = let_res_1784;
                                  }
                                  v_287d43b770d826e060b1e65a4d07e0b0 id_1802 { std::get<11>(p_0) };
                                  v_90e4213e12fd850ebf8d15b08342b17e id_1803 { std::get<1>(id_1802) };
                                  std::string id_1804 { std::get<0>(id_1803) };
                                  uint32_t id_1805 { (uint32_t)id_1804.size() };
                                  Size id_1806 { Size(id_1805) };
                                  Size id_1807 { Size(let_res_1781 + id_1806) };
                                  Size id_1808 { Size(id_1775 + id_1807) };
                                  choose_res_1773 = id_1808;
                                } else {
                                  v_287d43b770d826e060b1e65a4d07e0b0 id_1809 { std::get<11>(p_0) };
                                  v_90e4213e12fd850ebf8d15b08342b17e id_1810 { std::get<1>(id_1809) };
                                  uint16_t id_1811 { uint16_t(id_1810.index()) };
                                  uint16_t id_1812 { 1 };
                                  bool id_1813 { bool(id_1811 == id_1812) };
                                  Void id_1814 { ((void)(assert(id_1813)), VOID) };
                                  Size id_1815 { 2UL };
                                  Size id_1816 { Size(sz_690 + id_1815) };
                                  v_287d43b770d826e060b1e65a4d07e0b0 id_1817 { std::get<11>(p_0) };
                                  v_90e4213e12fd850ebf8d15b08342b17e id_1818 { std::get<1>(id_1817) };
                                  v_808252496816a9c094ed1ddb199861d1 id_1819 { std::get<1>(id_1818) };
                                  Size id_1820 { per_dash_key_sersize_of_row_binary(id_1819) };
                                  Size id_1821 { Size(id_1816 + id_1820) };
                                  choose_res_1773 = id_1821;
                                }
                                let_res_1767 = choose_res_1773;
                              }
                              choose_res_1760 = let_res_1767;
                            } else {
                              uint16_t id_1822 { 12 };
                              bool id_1823 { bool(id_1822 == label2_657) };
                              Size choose_res_1824;
                              if (id_1823) {
                                Size id_1825 { 2UL };
                                ea82132cbdaf05c9cc56869f7b4529c3 id_1826 { std::get<12>(p_0) };
                                std::string id_1827 { std::get<0>(id_1826) };
                                uint32_t id_1828 { (uint32_t)id_1827.size() };
                                Vec<1, uint32_t> id_1829 {  id_1828  };
                                Size let_res_1830;
                                {
                                  Vec<1, uint32_t> n_ref_686 { id_1829 };
                                  uint32_t id_1831 { 1U };
                                  Vec<1, uint32_t> id_1832 {  id_1831  };
                                  Size let_res_1833;
                                  {
                                    Vec<1, uint32_t> lebsz_ref_687 { id_1832 };
                                    bool while_flag_1834 { true };
                                    do {
                                      uint8_t id_1835 { 0 };
                                      uint32_t id_1836 { n_ref_686[id_1835] };
                                      uint8_t id_1837 { 0 };
                                      uint32_t id_1838 { lebsz_ref_687[id_1837] };
                                      uint8_t id_1839 { 7 };
                                      uint32_t id_1840 { uint32_t(id_1838 << id_1839) };
                                      bool id_1841 { bool(id_1836 >= id_1840) };
                                      while_flag_1834 = id_1841;
                                      if (while_flag_1834) {
                                        uint8_t id_1842 { 0 };
                                        uint8_t id_1843 { 0 };
                                        uint32_t id_1844 { lebsz_ref_687[id_1843] };
                                        uint32_t id_1845 { 1U };
                                        uint32_t id_1846 { uint32_t(id_1844 + id_1845) };
                                        Void id_1847 { ((void)(lebsz_ref_687[id_1842] = id_1846), VOID) };
                                      }
                                    } while (while_flag_1834);
                                    uint8_t id_1848 { 0 };
                                    uint32_t id_1849 { lebsz_ref_687[id_1848] };
                                    Size id_1850 { Size(id_1849) };
                                    let_res_1833 = id_1850;
                                  }
                                  let_res_1830 = let_res_1833;
                                }
                                ea82132cbdaf05c9cc56869f7b4529c3 id_1851 { std::get<12>(p_0) };
                                std::string id_1852 { std::get<0>(id_1851) };
                                uint32_t id_1853 { (uint32_t)id_1852.size() };
                                Size id_1854 { Size(id_1853) };
                                Size id_1855 { Size(let_res_1830 + id_1854) };
                                Size id_1856 { Size(id_1825 + id_1855) };
                                Size let_res_1857;
                                {
                                  Size sz_688 { id_1856 };
                                  ea82132cbdaf05c9cc56869f7b4529c3 id_1858 { std::get<12>(p_0) };
                                  v_808252496816a9c094ed1ddb199861d1* id_1859 { std::get<1>(id_1858) };
                                  Size id_1860 { per_dash_key_sersize_of_row_binary(id_1859) };
                                  Size id_1861 { Size(sz_688 + id_1860) };
                                  let_res_1857 = id_1861;
                                }
                                choose_res_1824 = let_res_1857;
                              } else {
                                uint16_t id_1862 { 13 };
                                bool id_1863 { bool(id_1862 == label2_657) };
                                Size choose_res_1864;
                                if (id_1863) {
                                  Size id_1865 { 2UL };
                                  choose_res_1864 = id_1865;
                                } else {
                                  uint16_t id_1866 { 14 };
                                  bool id_1867 { bool(id_1866 == label2_657) };
                                  Size choose_res_1868;
                                  if (id_1867) {
                                    Size id_1869 { 2UL };
                                    v_3891539b8b788ad5d369dde272200753 id_1870 { std::get<14>(p_0) };
                                    std::string id_1871 { std::get<0>(id_1870) };
                                    uint32_t id_1872 { (uint32_t)id_1871.size() };
                                    Vec<1, uint32_t> id_1873 {  id_1872  };
                                    Size let_res_1874;
                                    {
                                      Vec<1, uint32_t> n_ref_674 { id_1873 };
                                      uint32_t id_1875 { 1U };
                                      Vec<1, uint32_t> id_1876 {  id_1875  };
                                      Size let_res_1877;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_675 { id_1876 };
                                        bool while_flag_1878 { true };
                                        do {
                                          uint8_t id_1879 { 0 };
                                          uint32_t id_1880 { n_ref_674[id_1879] };
                                          uint8_t id_1881 { 0 };
                                          uint32_t id_1882 { lebsz_ref_675[id_1881] };
                                          uint8_t id_1883 { 7 };
                                          uint32_t id_1884 { uint32_t(id_1882 << id_1883) };
                                          bool id_1885 { bool(id_1880 >= id_1884) };
                                          while_flag_1878 = id_1885;
                                          if (while_flag_1878) {
                                            uint8_t id_1886 { 0 };
                                            uint8_t id_1887 { 0 };
                                            uint32_t id_1888 { lebsz_ref_675[id_1887] };
                                            uint32_t id_1889 { 1U };
                                            uint32_t id_1890 { uint32_t(id_1888 + id_1889) };
                                            Void id_1891 { ((void)(lebsz_ref_675[id_1886] = id_1890), VOID) };
                                          }
                                        } while (while_flag_1878);
                                        uint8_t id_1892 { 0 };
                                        uint32_t id_1893 { lebsz_ref_675[id_1892] };
                                        Size id_1894 { Size(id_1893) };
                                        let_res_1877 = id_1894;
                                      }
                                      let_res_1874 = let_res_1877;
                                    }
                                    v_3891539b8b788ad5d369dde272200753 id_1895 { std::get<14>(p_0) };
                                    std::string id_1896 { std::get<0>(id_1895) };
                                    uint32_t id_1897 { (uint32_t)id_1896.size() };
                                    Size id_1898 { Size(id_1897) };
                                    Size id_1899 { Size(let_res_1874 + id_1898) };
                                    Size id_1900 { Size(id_1869 + id_1899) };
                                    Size let_res_1901;
                                    {
                                      Size sz_676 { id_1900 };
                                      uint16_t id_1902 { 0 };
                                      v_3891539b8b788ad5d369dde272200753 id_1903 { std::get<14>(p_0) };
                                      v_04c2264c7cb6c602ff22f97c6ae3e620 id_1904 { std::get<1>(id_1903) };
                                      uint16_t id_1905 { uint16_t(id_1904.index()) };
                                      bool id_1906 { bool(id_1902 == id_1905) };
                                      Size choose_res_1907;
                                      if (id_1906) {
                                        Size id_1908 { 2UL };
                                        Size id_1909 { Size(sz_676 + id_1908) };
                                        v_3891539b8b788ad5d369dde272200753 id_1910 { std::get<14>(p_0) };
                                        v_04c2264c7cb6c602ff22f97c6ae3e620 id_1911 { std::get<1>(id_1910) };
                                        std::string id_1912 { std::get<0>(id_1911) };
                                        uint32_t id_1913 { (uint32_t)id_1912.size() };
                                        Vec<1, uint32_t> id_1914 {  id_1913  };
                                        Size let_res_1915;
                                        {
                                          Vec<1, uint32_t> n_ref_682 { id_1914 };
                                          uint32_t id_1916 { 1U };
                                          Vec<1, uint32_t> id_1917 {  id_1916  };
                                          Size let_res_1918;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_683 { id_1917 };
                                            bool while_flag_1919 { true };
                                            do {
                                              uint8_t id_1920 { 0 };
                                              uint32_t id_1921 { n_ref_682[id_1920] };
                                              uint8_t id_1922 { 0 };
                                              uint32_t id_1923 { lebsz_ref_683[id_1922] };
                                              uint8_t id_1924 { 7 };
                                              uint32_t id_1925 { uint32_t(id_1923 << id_1924) };
                                              bool id_1926 { bool(id_1921 >= id_1925) };
                                              while_flag_1919 = id_1926;
                                              if (while_flag_1919) {
                                                uint8_t id_1927 { 0 };
                                                uint8_t id_1928 { 0 };
                                                uint32_t id_1929 { lebsz_ref_683[id_1928] };
                                                uint32_t id_1930 { 1U };
                                                uint32_t id_1931 { uint32_t(id_1929 + id_1930) };
                                                Void id_1932 { ((void)(lebsz_ref_683[id_1927] = id_1931), VOID) };
                                              }
                                            } while (while_flag_1919);
                                            uint8_t id_1933 { 0 };
                                            uint32_t id_1934 { lebsz_ref_683[id_1933] };
                                            Size id_1935 { Size(id_1934) };
                                            let_res_1918 = id_1935;
                                          }
                                          let_res_1915 = let_res_1918;
                                        }
                                        v_3891539b8b788ad5d369dde272200753 id_1936 { std::get<14>(p_0) };
                                        v_04c2264c7cb6c602ff22f97c6ae3e620 id_1937 { std::get<1>(id_1936) };
                                        std::string id_1938 { std::get<0>(id_1937) };
                                        uint32_t id_1939 { (uint32_t)id_1938.size() };
                                        Size id_1940 { Size(id_1939) };
                                        Size id_1941 { Size(let_res_1915 + id_1940) };
                                        Size id_1942 { Size(id_1909 + id_1941) };
                                        choose_res_1907 = id_1942;
                                      } else {
                                        v_3891539b8b788ad5d369dde272200753 id_1943 { std::get<14>(p_0) };
                                        v_04c2264c7cb6c602ff22f97c6ae3e620 id_1944 { std::get<1>(id_1943) };
                                        uint16_t id_1945 { uint16_t(id_1944.index()) };
                                        uint16_t id_1946 { 1 };
                                        bool id_1947 { bool(id_1945 == id_1946) };
                                        Void id_1948 { ((void)(assert(id_1947)), VOID) };
                                        Size id_1949 { 2UL };
                                        Size id_1950 { Size(sz_676 + id_1949) };
                                        v_3891539b8b788ad5d369dde272200753 id_1951 { std::get<14>(p_0) };
                                        v_04c2264c7cb6c602ff22f97c6ae3e620 id_1952 { std::get<1>(id_1951) };
                                        std::string id_1953 { std::get<1>(id_1952) };
                                        uint32_t id_1954 { (uint32_t)id_1953.size() };
                                        Vec<1, uint32_t> id_1955 {  id_1954  };
                                        Size let_res_1956;
                                        {
                                          Vec<1, uint32_t> n_ref_679 { id_1955 };
                                          uint32_t id_1957 { 1U };
                                          Vec<1, uint32_t> id_1958 {  id_1957  };
                                          Size let_res_1959;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_680 { id_1958 };
                                            bool while_flag_1960 { true };
                                            do {
                                              uint8_t id_1961 { 0 };
                                              uint32_t id_1962 { n_ref_679[id_1961] };
                                              uint8_t id_1963 { 0 };
                                              uint32_t id_1964 { lebsz_ref_680[id_1963] };
                                              uint8_t id_1965 { 7 };
                                              uint32_t id_1966 { uint32_t(id_1964 << id_1965) };
                                              bool id_1967 { bool(id_1962 >= id_1966) };
                                              while_flag_1960 = id_1967;
                                              if (while_flag_1960) {
                                                uint8_t id_1968 { 0 };
                                                uint8_t id_1969 { 0 };
                                                uint32_t id_1970 { lebsz_ref_680[id_1969] };
                                                uint32_t id_1971 { 1U };
                                                uint32_t id_1972 { uint32_t(id_1970 + id_1971) };
                                                Void id_1973 { ((void)(lebsz_ref_680[id_1968] = id_1972), VOID) };
                                              }
                                            } while (while_flag_1960);
                                            uint8_t id_1974 { 0 };
                                            uint32_t id_1975 { lebsz_ref_680[id_1974] };
                                            Size id_1976 { Size(id_1975) };
                                            let_res_1959 = id_1976;
                                          }
                                          let_res_1956 = let_res_1959;
                                        }
                                        v_3891539b8b788ad5d369dde272200753 id_1977 { std::get<14>(p_0) };
                                        v_04c2264c7cb6c602ff22f97c6ae3e620 id_1978 { std::get<1>(id_1977) };
                                        std::string id_1979 { std::get<1>(id_1978) };
                                        uint32_t id_1980 { (uint32_t)id_1979.size() };
                                        Size id_1981 { Size(id_1980) };
                                        Size id_1982 { Size(let_res_1956 + id_1981) };
                                        Size id_1983 { Size(id_1950 + id_1982) };
                                        choose_res_1907 = id_1983;
                                      }
                                      let_res_1901 = choose_res_1907;
                                    }
                                    choose_res_1868 = let_res_1901;
                                  } else {
                                    uint16_t id_1984 { 15 };
                                    bool id_1985 { bool(label2_657 == id_1984) };
                                    Void id_1986 { ((void)(assert(id_1985)), VOID) };
                                    Size id_1987 { 2UL };
                                    ec4a56989018adc62b22d5f6798b0bc1 id_1988 { std::get<15>(p_0) };
                                    std::string id_1989 { std::get<0>(id_1988) };
                                    uint32_t id_1990 { (uint32_t)id_1989.size() };
                                    Vec<1, uint32_t> id_1991 {  id_1990  };
                                    Size let_res_1992;
                                    {
                                      Vec<1, uint32_t> n_ref_660 { id_1991 };
                                      uint32_t id_1993 { 1U };
                                      Vec<1, uint32_t> id_1994 {  id_1993  };
                                      Size let_res_1995;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_661 { id_1994 };
                                        bool while_flag_1996 { true };
                                        do {
                                          uint8_t id_1997 { 0 };
                                          uint32_t id_1998 { n_ref_660[id_1997] };
                                          uint8_t id_1999 { 0 };
                                          uint32_t id_2000 { lebsz_ref_661[id_1999] };
                                          uint8_t id_2001 { 7 };
                                          uint32_t id_2002 { uint32_t(id_2000 << id_2001) };
                                          bool id_2003 { bool(id_1998 >= id_2002) };
                                          while_flag_1996 = id_2003;
                                          if (while_flag_1996) {
                                            uint8_t id_2004 { 0 };
                                            uint8_t id_2005 { 0 };
                                            uint32_t id_2006 { lebsz_ref_661[id_2005] };
                                            uint32_t id_2007 { 1U };
                                            uint32_t id_2008 { uint32_t(id_2006 + id_2007) };
                                            Void id_2009 { ((void)(lebsz_ref_661[id_2004] = id_2008), VOID) };
                                          }
                                        } while (while_flag_1996);
                                        uint8_t id_2010 { 0 };
                                        uint32_t id_2011 { lebsz_ref_661[id_2010] };
                                        Size id_2012 { Size(id_2011) };
                                        let_res_1995 = id_2012;
                                      }
                                      let_res_1992 = let_res_1995;
                                    }
                                    ec4a56989018adc62b22d5f6798b0bc1 id_2013 { std::get<15>(p_0) };
                                    std::string id_2014 { std::get<0>(id_2013) };
                                    uint32_t id_2015 { (uint32_t)id_2014.size() };
                                    Size id_2016 { Size(id_2015) };
                                    Size id_2017 { Size(let_res_1992 + id_2016) };
                                    Size id_2018 { Size(id_1987 + id_2017) };
                                    Size let_res_2019;
                                    {
                                      Size sz_662 { id_2018 };
                                      ec4a56989018adc62b22d5f6798b0bc1 id_2020 { std::get<15>(p_0) };
                                      e6f820d94c0e3bb8eb0c04383ff72e06 id_2021 { std::get<1>(id_2020) };
                                      uint16_t id_2022 { uint16_t(id_2021.index()) };
                                      Size let_res_2023;
                                      {
                                        uint16_t label2_663 { id_2022 };
                                        uint16_t id_2024 { 0 };
                                        bool id_2025 { bool(id_2024 == label2_663) };
                                        Size choose_res_2026;
                                        if (id_2025) {
                                          Size id_2027 { 2UL };
                                          Size id_2028 { Size(sz_662 + id_2027) };
                                          choose_res_2026 = id_2028;
                                        } else {
                                          uint16_t id_2029 { 1 };
                                          bool id_2030 { bool(id_2029 == label2_663) };
                                          Size choose_res_2031;
                                          if (id_2030) {
                                            Size id_2032 { 2UL };
                                            Size id_2033 { Size(sz_662 + id_2032) };
                                            choose_res_2031 = id_2033;
                                          } else {
                                            uint16_t id_2034 { 2 };
                                            bool id_2035 { bool(id_2034 == label2_663) };
                                            Size choose_res_2036;
                                            if (id_2035) {
                                              Size id_2037 { 2UL };
                                              Size id_2038 { Size(sz_662 + id_2037) };
                                              choose_res_2036 = id_2038;
                                            } else {
                                              uint16_t id_2039 { 3 };
                                              bool id_2040 { bool(id_2039 == label2_663) };
                                              Size choose_res_2041;
                                              if (id_2040) {
                                                Size id_2042 { 2UL };
                                                Size id_2043 { Size(sz_662 + id_2042) };
                                                choose_res_2041 = id_2043;
                                              } else {
                                                uint16_t id_2044 { 4 };
                                                bool id_2045 { bool(id_2044 == label2_663) };
                                                Size choose_res_2046;
                                                if (id_2045) {
                                                  Size id_2047 { 2UL };
                                                  Size id_2048 { Size(sz_662 + id_2047) };
                                                  choose_res_2046 = id_2048;
                                                } else {
                                                  uint16_t id_2049 { 5 };
                                                  bool id_2050 { bool(id_2049 == label2_663) };
                                                  Size choose_res_2051;
                                                  if (id_2050) {
                                                    Size id_2052 { 2UL };
                                                    Size id_2053 { Size(sz_662 + id_2052) };
                                                    ec4a56989018adc62b22d5f6798b0bc1 id_2054 { std::get<15>(p_0) };
                                                    e6f820d94c0e3bb8eb0c04383ff72e06 id_2055 { std::get<1>(id_2054) };
                                                    v_22ca22dbe40628ddd4edb314b5205ff3 id_2056 { std::get<5>(id_2055) };
                                                    std::string id_2057 { std::get<0>(id_2056) };
                                                    uint32_t id_2058 { (uint32_t)id_2057.size() };
                                                    Vec<1, uint32_t> id_2059 {  id_2058  };
                                                    Size let_res_2060;
                                                    {
                                                      Vec<1, uint32_t> n_ref_668 { id_2059 };
                                                      uint32_t id_2061 { 1U };
                                                      Vec<1, uint32_t> id_2062 {  id_2061  };
                                                      Size let_res_2063;
                                                      {
                                                        Vec<1, uint32_t> lebsz_ref_669 { id_2062 };
                                                        bool while_flag_2064 { true };
                                                        do {
                                                          uint8_t id_2065 { 0 };
                                                          uint32_t id_2066 { n_ref_668[id_2065] };
                                                          uint8_t id_2067 { 0 };
                                                          uint32_t id_2068 { lebsz_ref_669[id_2067] };
                                                          uint8_t id_2069 { 7 };
                                                          uint32_t id_2070 { uint32_t(id_2068 << id_2069) };
                                                          bool id_2071 { bool(id_2066 >= id_2070) };
                                                          while_flag_2064 = id_2071;
                                                          if (while_flag_2064) {
                                                            uint8_t id_2072 { 0 };
                                                            uint8_t id_2073 { 0 };
                                                            uint32_t id_2074 { lebsz_ref_669[id_2073] };
                                                            uint32_t id_2075 { 1U };
                                                            uint32_t id_2076 { uint32_t(id_2074 + id_2075) };
                                                            Void id_2077 { ((void)(lebsz_ref_669[id_2072] = id_2076), VOID) };
                                                          }
                                                        } while (while_flag_2064);
                                                        uint8_t id_2078 { 0 };
                                                        uint32_t id_2079 { lebsz_ref_669[id_2078] };
                                                        Size id_2080 { Size(id_2079) };
                                                        let_res_2063 = id_2080;
                                                      }
                                                      let_res_2060 = let_res_2063;
                                                    }
                                                    ec4a56989018adc62b22d5f6798b0bc1 id_2081 { std::get<15>(p_0) };
                                                    e6f820d94c0e3bb8eb0c04383ff72e06 id_2082 { std::get<1>(id_2081) };
                                                    v_22ca22dbe40628ddd4edb314b5205ff3 id_2083 { std::get<5>(id_2082) };
                                                    std::string id_2084 { std::get<0>(id_2083) };
                                                    uint32_t id_2085 { (uint32_t)id_2084.size() };
                                                    Size id_2086 { Size(id_2085) };
                                                    Size id_2087 { Size(let_res_2060 + id_2086) };
                                                    Size id_2088 { Size(id_2053 + id_2087) };
                                                    Size let_res_2089;
                                                    {
                                                      Size sz_670 { id_2088 };
                                                      ec4a56989018adc62b22d5f6798b0bc1 id_2090 { std::get<15>(p_0) };
                                                      e6f820d94c0e3bb8eb0c04383ff72e06 id_2091 { std::get<1>(id_2090) };
                                                      v_22ca22dbe40628ddd4edb314b5205ff3 id_2092 { std::get<5>(id_2091) };
                                                      f27b577e1bb6a9c447e7eec975daa7e7 id_2093 { std::get<1>(id_2092) };
                                                      uint16_t id_2094 { uint16_t(id_2093.index()) };
                                                      Size let_res_2095;
                                                      {
                                                        uint16_t label2_671 { id_2094 };
                                                        uint16_t id_2096 { 0 };
                                                        bool id_2097 { bool(id_2096 == label2_671) };
                                                        Size choose_res_2098;
                                                        if (id_2097) {
                                                          Size id_2099 { 2UL };
                                                          Size id_2100 { Size(sz_670 + id_2099) };
                                                          choose_res_2098 = id_2100;
                                                        } else {
                                                          uint16_t id_2101 { 1 };
                                                          bool id_2102 { bool(id_2101 == label2_671) };
                                                          Size choose_res_2103;
                                                          if (id_2102) {
                                                            Size id_2104 { 2UL };
                                                            Size id_2105 { Size(sz_670 + id_2104) };
                                                            choose_res_2103 = id_2105;
                                                          } else {
                                                            uint16_t id_2106 { 2 };
                                                            bool id_2107 { bool(id_2106 == label2_671) };
                                                            Size choose_res_2108;
                                                            if (id_2107) {
                                                              Size id_2109 { 2UL };
                                                              Size id_2110 { Size(sz_670 + id_2109) };
                                                              choose_res_2108 = id_2110;
                                                            } else {
                                                              uint16_t id_2111 { 3 };
                                                              bool id_2112 { bool(id_2111 == label2_671) };
                                                              Size choose_res_2113;
                                                              if (id_2112) {
                                                                Size id_2114 { 2UL };
                                                                Size id_2115 { Size(sz_670 + id_2114) };
                                                                choose_res_2113 = id_2115;
                                                              } else {
                                                                uint16_t id_2116 { 4 };
                                                                bool id_2117 { bool(id_2116 == label2_671) };
                                                                Size choose_res_2118;
                                                                if (id_2117) {
                                                                  Size id_2119 { 2UL };
                                                                  Size id_2120 { Size(sz_670 + id_2119) };
                                                                  choose_res_2118 = id_2120;
                                                                } else {
                                                                  uint16_t id_2121 { 5 };
                                                                  bool id_2122 { bool(id_2121 == label2_671) };
                                                                  Size choose_res_2123;
                                                                  if (id_2122) {
                                                                    Size id_2124 { 2UL };
                                                                    Size id_2125 { Size(sz_670 + id_2124) };
                                                                    choose_res_2123 = id_2125;
                                                                  } else {
                                                                    uint16_t id_2126 { 6 };
                                                                    bool id_2127 { bool(label2_671 == id_2126) };
                                                                    Void id_2128 { ((void)(assert(id_2127)), VOID) };
                                                                    Size id_2129 { 2UL };
                                                                    Size id_2130 { Size(sz_670 + id_2129) };
                                                                    choose_res_2123 = id_2130;
                                                                  }
                                                                  choose_res_2118 = choose_res_2123;
                                                                }
                                                                choose_res_2113 = choose_res_2118;
                                                              }
                                                              choose_res_2108 = choose_res_2113;
                                                            }
                                                            choose_res_2103 = choose_res_2108;
                                                          }
                                                          choose_res_2098 = choose_res_2103;
                                                        }
                                                        let_res_2095 = choose_res_2098;
                                                      }
                                                      let_res_2089 = let_res_2095;
                                                    }
                                                    choose_res_2051 = let_res_2089;
                                                  } else {
                                                    uint16_t id_2131 { 6 };
                                                    bool id_2132 { bool(label2_663 == id_2131) };
                                                    Void id_2133 { ((void)(assert(id_2132)), VOID) };
                                                    Size id_2134 { 2UL };
                                                    Size id_2135 { Size(sz_662 + id_2134) };
                                                    Size id_2136 { 8UL };
                                                    Size id_2137 { Size(id_2135 + id_2136) };
                                                    Size id_2138 { 4UL };
                                                    Size id_2139 { Size(id_2137 + id_2138) };
                                                    choose_res_2051 = id_2139;
                                                  }
                                                  choose_res_2046 = choose_res_2051;
                                                }
                                                choose_res_2041 = choose_res_2046;
                                              }
                                              choose_res_2036 = choose_res_2041;
                                            }
                                            choose_res_2031 = choose_res_2036;
                                          }
                                          choose_res_2026 = choose_res_2031;
                                        }
                                        let_res_2023 = choose_res_2026;
                                      }
                                      let_res_2019 = let_res_2023;
                                    }
                                    choose_res_1868 = let_res_2019;
                                  }
                                  choose_res_1864 = choose_res_1868;
                                }
                                choose_res_1824 = choose_res_1864;
                              }
                              choose_res_1760 = choose_res_1824;
                            }
                            choose_res_1756 = choose_res_1760;
                          }
                          choose_res_1741 = choose_res_1756;
                        }
                        choose_res_1737 = choose_res_1741;
                      }
                      choose_res_1638 = choose_res_1737;
                    }
                    choose_res_1586 = choose_res_1638;
                  }
                  choose_res_1293 = choose_res_1586;
                }
                choose_res_1289 = choose_res_1293;
              }
              choose_res_1248 = choose_res_1289;
            }
            choose_res_1215 = choose_res_1248;
          }
          choose_res_1211 = choose_res_1215;
        }
        choose_res_1207 = choose_res_1211;
      }
      let_res_1204 = choose_res_1207;
    }
    return let_res_1204;
  }
   };
  return fun1202;
}
std::function<Size(t)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad per_dash_key AS [Widgets U32]]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" "Ptr")
      (let "label1_744" (label-of (param 0))
        (let "ssum_dst_745" (write-u16 little-endian (param 1) (identifier "label1_744"))
          (if (eq (u16 0) (identifier "label1_744")) (identifier "ssum_dst_745")
            (if (eq (u16 1) (identifier "label1_744")) (identifier "ssum_dst_745")
              (if (eq (u16 2) (identifier "label1_744"))
                (write-bytes
                  (let "leb128_sz_811" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "leb128_ptr_812" (make-vec (identifier "ssum_dst_745"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_812")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_812"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_811"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_811"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_811"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_811") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_811")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_811")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_812"))))) 
                  (bytes-of-string (get-alt "Versions" (param 0))))
                (if (eq (u16 3) (identifier "label1_744"))
                  (let "stup_dst_808" (apply (ext-identifier src_path to-row-binary) (get-item 0 (get-alt "Sources" (param 0))) (identifier "ssum_dst_745"))
                    (write-bytes
                      (let "leb128_sz_809" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "leb128_ptr_810" (make-vec (identifier "stup_dst_808"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_810")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_810"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_809"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_809"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_809"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_809") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_809")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_809")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_810"))))) 
                      (bytes-of-string (get-item 1 (get-alt "Sources" (param 0))))))
                  (if (eq (u16 4) (identifier "label1_744")) (identifier "ssum_dst_745")
                    (if (eq (u16 5) (identifier "label1_744"))
                      (let "stup_dst_787" (apply (ext-identifier site_name to-row-binary) (get-item 0 (get-alt "PerSite" (param 0))) (identifier "ssum_dst_745"))
                        (let "ssum_dst_789" (write-u16 little-endian (identifier "stup_dst_787") (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                          (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerSite" (param 0))))) 
                            (identifier "ssum_dst_789")
                            (if (eq (u16 1) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                              (let "stup_dst_805"
                                (write-bytes
                                  (let "leb128_sz_803" (make-vec (string-length (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                    (let "leb128_ptr_804" (make-vec (identifier "ssum_dst_789"))
                                      (seq
                                        (while
                                          (seq
                                            (set-vec (u8 0) (identifier "leb128_ptr_804")
                                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_804"))
                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_803"))) 
                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_803"))) 
                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_803"))) (u8 128)))))
                                            (set-vec (u8 0) (identifier "leb128_sz_803") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_803")) (u8 7))) 
                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_803")) (u32 0))) 
                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_804"))))) 
                                  (bytes-of-string (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                (let "ssum_dst_807" (write-u16 little-endian (identifier "stup_dst_805") (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                  (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0))))))) 
                                    (identifier "ssum_dst_807") (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 1))) (identifier "ssum_dst_807")))))
                              (if (eq (u16 2) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                                (let "stup_dst_795" (apply (ext-identifier fq_name to-row-binary) (get-item 0 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))) (identifier "ssum_dst_789"))
                                  (let "label1_796" (label-of (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))
                                    (let "ssum_dst_797" (write-u16 little-endian (identifier "stup_dst_795") (identifier "label1_796"))
                                      (if (eq (u16 0) (identifier "label1_796")) 
                                        (identifier "ssum_dst_797")
                                        (if (eq (u16 1) (identifier "label1_796")) 
                                          (identifier "ssum_dst_797")
                                          (if (eq (u16 2) (identifier "label1_796")) 
                                            (identifier "ssum_dst_797")
                                            (if (eq (u16 3) (identifier "label1_796")) 
                                              (identifier "ssum_dst_797")
                                              (if (eq (u16 4) (identifier "label1_796")) 
                                                (identifier "ssum_dst_797")
                                                (if (eq (u16 5) (identifier "label1_796")) 
                                                  (identifier "ssum_dst_797")
                                                  (if (eq (u16 6) (identifier "label1_796"))
                                                    (let "stup_dst_800"
                                                      (write-bytes
                                                        (let "leb128_sz_798" 
                                                          (make-vec (string-length (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                                          (let "leb128_ptr_799" 
                                                            (make-vec (identifier "ssum_dst_797"))
                                                            (seq
                                                              (while
                                                                (seq
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_799")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_799"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_798"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_798"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_798"))) (u8 128)))))
                                                                  (set-vec (u8 0) (identifier "leb128_sz_798") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_798")) (u8 7)))
                                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_798")) (u32 0))) 
                                                                (nop)) 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_799")))))
                                                        (bytes-of-string (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                                      (let "label1_801" 
                                                        (label-of (get-item 1 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))))
                                                        (let "ssum_dst_802" 
                                                          (write-u16 little-endian (identifier "stup_dst_800") (identifier "label1_801"))
                                                          (if (eq (u16 0) (identifier "label1_801")) 
                                                            (identifier "ssum_dst_802")
                                                            (if (eq (u16 1) (identifier "label1_801")) 
                                                              (identifier "ssum_dst_802")
                                                              (if (eq (u16 2) (identifier "label1_801")) 
                                                                (identifier "ssum_dst_802")
                                                                (if (eq (u16 3) (identifier "label1_801")) 
                                                                  (identifier "ssum_dst_802")
                                                                  (if 
                                                                    (eq (u16 4) (identifier "label1_801")) 
                                                                    (identifier "ssum_dst_802")
                                                                    (if 
                                                                    (eq (u16 5) (identifier "label1_801")) 
                                                                    (identifier "ssum_dst_802")
                                                                    (if (eq (u16 6) (identifier "label1_801")) (identifier "ssum_dst_802") (seq (assert (eq (identifier "label1_801") (u16 7))) (identifier "ssum_dst_802"))))))))))))
                                                    (if (eq (u16 7) (identifier "label1_796"))
                                                      (write-u32 little-endian (identifier "ssum_dst_797") (get-alt "PerReplayer" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                                      (seq (assert (eq (identifier "label1_796") (u16 8))) (identifier "ssum_dst_797")))))))))))))
                                (seq (assert (eq (label-of (get-item 1 (get-alt "PerSite" (param 0)))) (u16 3)))
                                  (let "stup_dst_792"
                                    (write-bytes
                                      (let "leb128_sz_790" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                        (let "leb128_ptr_791" (make-vec (identifier "ssum_dst_789"))
                                          (seq
                                            (while
                                              (seq
                                                (set-vec (u8 0) (identifier "leb128_ptr_791")
                                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_791"))
                                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_790"))) 
                                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_790"))) 
                                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_790"))) (u8 128)))))
                                                (set-vec (u8 0) (identifier "leb128_sz_790") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_790")) (u8 7))) 
                                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_790")) (u32 0))) 
                                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_791"))))) 
                                      (bytes-of-string (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                    (let "ssum_dst_794" (write-u16 little-endian (identifier "stup_dst_792") (label-of (get-item 1 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                      (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 0))) (identifier "ssum_dst_794"))))))))))
                      (if (eq (u16 6) (identifier "label1_744"))
                        (let "ssum_dst_784" (write-u16 little-endian (identifier "ssum_dst_745") (label-of (get-alt "Storage" (param 0))))
                          (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                            (identifier "ssum_dst_784")
                            (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                              (identifier "ssum_dst_784")
                              (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                                (write-bytes
                                  (let "leb128_sz_785" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                    (let "leb128_ptr_786" (make-vec (identifier "ssum_dst_784"))
                                      (seq
                                        (while
                                          (seq
                                            (set-vec (u8 0) (identifier "leb128_ptr_786")
                                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_786"))
                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_785"))) 
                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_785"))) 
                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_785"))) (u8 128)))))
                                            (set-vec (u8 0) (identifier "leb128_sz_785") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_785")) (u8 7))) 
                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_785")) (u32 0))) 
                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_786"))))) 
                                  (bytes-of-string (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))))))
                        (if (eq (u16 7) (identifier "label1_744"))
                          (let "stup_dst_778"
                            (let "stup_dst_775"
                              (let "stup_dst_774" (apply (ext-identifier site_name to-row-binary) (get-item 0 (get-alt "Tails" (param 0))) (identifier "ssum_dst_745"))
                                (apply (ext-identifier fq_name to-row-binary) (get-item 1 (get-alt "Tails" (param 0))) (identifier "stup_dst_774")))
                              (write-bytes
                                (let "leb128_sz_776" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "leb128_ptr_777" (make-vec (identifier "stup_dst_775"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_777")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_777"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_776"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_776"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_776"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_776") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_776")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_776")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_777"))))) 
                                (bytes-of-string (get-item 2 (get-alt "Tails" (param 0))))))
                            (let "ssum_dst_780" (write-u16 little-endian (identifier "stup_dst_778") (label-of (get-item 3 (get-alt "Tails" (param 0)))))
                              (if (eq (u16 0) (label-of (get-item 3 (get-alt "Tails" (param 0)))))
                                (write-bytes
                                  (let "leb128_sz_781" (make-vec (string-length (get-alt "Subscriber" (get-item 3 (get-alt "Tails" (param 0))))))
                                    (let "leb128_ptr_782" (make-vec (identifier "ssum_dst_780"))
                                      (seq
                                        (while
                                          (seq
                                            (set-vec (u8 0) (identifier "leb128_ptr_782")
                                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_782"))
                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_781"))) 
                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_781"))) 
                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_781"))) (u8 128)))))
                                            (set-vec (u8 0) (identifier "leb128_sz_781") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_781")) (u8 7))) 
                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_781")) (u32 0))) 
                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_782"))))) 
                                  (bytes-of-string (get-alt "Subscriber" (get-item 3 (get-alt "Tails" (param 0))))))
                                (seq (assert (eq (label-of (get-item 3 (get-alt "Tails" (param 0)))) (u16 1))) (write-u32 little-endian (identifier "ssum_dst_780") (get-alt "LastTuple" (get-item 3 (get-alt "Tails" (param 0)))))))))
                          (if (eq (u16 8) (identifier "label1_744")) 
                            (write-u16 little-endian (identifier "ssum_dst_745") (get-alt "Replays" (param 0)))
                            (if (eq (u16 9) (identifier "label1_744"))
                              (if (is-null (get-alt "Error" (param 0))) 
                                (write-u8 (identifier "ssum_dst_745") (u8 1)) 
                                (apply (ext-identifier sync_socket to-row-binary) (force (get-alt "Error" (param 0))) (write-u8 (identifier "ssum_dst_745") (u8 0))))
                              (if (eq (u16 10) (identifier "label1_744")) 
                                (identifier "ssum_dst_745")
                                (if (eq (u16 11) (identifier "label1_744"))
                                  (let "stup_dst_769" (apply (ext-identifier sync_socket to-row-binary) (get-item 0 (get-alt "PerClient" (param 0))) (identifier "ssum_dst_745"))
                                    (let "ssum_dst_771" (write-u16 little-endian (identifier "stup_dst_769") (label-of (get-item 1 (get-alt "PerClient" (param 0)))))
                                      (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerClient" (param 0)))))
                                        (write-bytes
                                          (let "leb128_sz_772" (make-vec (string-length (get-alt "Response" (get-item 1 (get-alt "PerClient" (param 0))))))
                                            (let "leb128_ptr_773" (make-vec (identifier "ssum_dst_771"))
                                              (seq
                                                (while
                                                  (seq
                                                    (set-vec (u8 0) (identifier "leb128_ptr_773")
                                                      (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_773"))
                                                        (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_772"))) 
                                                          (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_772"))) 
                                                          (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_772"))) (u8 128)))))
                                                    (set-vec (u8 0) (identifier "leb128_sz_772") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_772")) (u8 7)))
                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_772")) (u32 0))) 
                                                  (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_773"))))) 
                                          (bytes-of-string (get-alt "Response" (get-item 1 (get-alt "PerClient" (param 0))))))
                                        (seq (assert (eq (label-of (get-item 1 (get-alt "PerClient" (param 0)))) (u16 1)))
                                          (apply (identifier "per_dash_key-to-row-binary") (get-alt "Scratchpad" (get-item 1 (get-alt "PerClient" (param 0)))) (identifier "ssum_dst_771"))))))
                                  (if (eq (u16 12) (identifier "label1_744"))
                                    (let "stup_dst_768"
                                      (write-bytes
                                        (let "leb128_sz_766" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "leb128_ptr_767" (make-vec (identifier "ssum_dst_745"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_767")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_767"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_766"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_766"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_766"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_766") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_766")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_766")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_767"))))) 
                                        (bytes-of-string (get-item 0 (get-alt "Dashboards" (param 0))))) 
                                      (apply (identifier "per_dash_key-to-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))) (identifier "stup_dst_768")))
                                    (if (eq (u16 13) (identifier "label1_744")) 
                                      (identifier "ssum_dst_745")
                                      (if (eq (u16 14) (identifier "label1_744"))
                                        (let "stup_dst_759"
                                          (write-bytes
                                            (let "leb128_sz_757" (make-vec (string-length (get-item 0 (get-alt "Teams" (param 0)))))
                                              (let "leb128_ptr_758" (make-vec (identifier "ssum_dst_745"))
                                                (seq
                                                  (while
                                                    (seq
                                                      (set-vec (u8 0) 
                                                        (identifier "leb128_ptr_758")
                                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_758"))
                                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_757"))) 
                                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_757"))) 
                                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_757"))) (u8 128)))))
                                                      (set-vec (u8 0) (identifier "leb128_sz_757") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_757")) (u8 7)))
                                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_757")) (u32 0))) 
                                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_758"))))) 
                                            (bytes-of-string (get-item 0 (get-alt "Teams" (param 0)))))
                                          (let "ssum_dst_761" (write-u16 little-endian (identifier "stup_dst_759") (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                            (if (eq (u16 0) (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                              (write-bytes
                                                (let "leb128_sz_764" 
                                                  (make-vec (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                                  (let "leb128_ptr_765" 
                                                    (make-vec (identifier "ssum_dst_761"))
                                                    (seq
                                                      (while
                                                        (seq
                                                          (set-vec (u8 0) 
                                                            (identifier "leb128_ptr_765")
                                                            (write-u8 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_765"))
                                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_764"))) 
                                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_764"))) 
                                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_764"))) (u8 128)))))
                                                          (set-vec (u8 0) (identifier "leb128_sz_764") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_764")) (u8 7)))
                                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_764")) (u32 0))) 
                                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_765"))))) 
                                                (bytes-of-string (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                              (seq (assert (eq (label-of (get-item 1 (get-alt "Teams" (param 0)))) (u16 1)))
                                                (write-bytes
                                                  (let "leb128_sz_762" 
                                                    (make-vec (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))
                                                    (let "leb128_ptr_763" 
                                                      (make-vec (identifier "ssum_dst_761"))
                                                      (seq
                                                        (while
                                                          (seq
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb128_ptr_763")
                                                              (write-u8 
                                                                (unsafe-nth (u8 0) (identifier "leb128_ptr_763"))
                                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_762"))) 
                                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_762"))) 
                                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_762"))) (u8 128)))))
                                                            (set-vec (u8 0) (identifier "leb128_sz_762") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_762")) (u8 7)))
                                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_762")) (u32 0))) 
                                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_763"))))) 
                                                  (bytes-of-string (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))))))
                                        (seq (assert (eq (identifier "label1_744") (u16 15)))
                                          (let "stup_dst_748"
                                            (write-bytes
                                              (let "leb128_sz_746" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "leb128_ptr_747" 
                                                  (make-vec (identifier "ssum_dst_745"))
                                                  (seq
                                                    (while
                                                      (seq
                                                        (set-vec (u8 0) 
                                                          (identifier "leb128_ptr_747")
                                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_747"))
                                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_746"))) 
                                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_746"))) 
                                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_746"))) (u8 128)))))
                                                        (set-vec (u8 0) (identifier "leb128_sz_746") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_746")) (u8 7)))
                                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_746")) (u32 0))) 
                                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_747"))))) 
                                              (bytes-of-string (get-item 0 (get-alt "Incidents" (param 0)))))
                                            (let "label1_749" (label-of (get-item 1 (get-alt "Incidents" (param 0))))
                                              (let "ssum_dst_750" (write-u16 little-endian (identifier "stup_dst_748") (identifier "label1_749"))
                                                (if (eq (u16 0) (identifier "label1_749")) 
                                                  (identifier "ssum_dst_750")
                                                  (if (eq (u16 1) (identifier "label1_749")) 
                                                    (identifier "ssum_dst_750")
                                                    (if (eq (u16 2) (identifier "label1_749")) 
                                                      (identifier "ssum_dst_750")
                                                      (if (eq (u16 3) (identifier "label1_749")) 
                                                        (identifier "ssum_dst_750")
                                                        (if (eq (u16 4) (identifier "label1_749")) 
                                                          (identifier "ssum_dst_750")
                                                          (if (eq (u16 5) (identifier "label1_749"))
                                                            (let "stup_dst_754"
                                                              (write-bytes
                                                                (let "leb128_sz_752" 
                                                                  (make-vec (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                  (let "leb128_ptr_753" 
                                                                    (make-vec (identifier "ssum_dst_750"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_753")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_753"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_752"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_752"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_752"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_752") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_752")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_752")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_753"))))) 
                                                                (bytes-of-string (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                              (let "label1_755" 
                                                                (label-of (get-item 1 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0))))))
                                                                (let "ssum_dst_756" 
                                                                  (write-u16 little-endian (identifier "stup_dst_754") (identifier "label1_755"))
                                                                  (if 
                                                                    (eq (u16 0) (identifier "label1_755")) 
                                                                    (identifier "ssum_dst_756")
                                                                    (if 
                                                                    (eq (u16 1) (identifier "label1_755")) 
                                                                    (identifier "ssum_dst_756")
                                                                    (if 
                                                                    (eq (u16 2) (identifier "label1_755")) 
                                                                    (identifier "ssum_dst_756")
                                                                    (if 
                                                                    (eq (u16 3) (identifier "label1_755")) 
                                                                    (identifier "ssum_dst_756")
                                                                    (if 
                                                                    (eq (u16 4) (identifier "label1_755")) 
                                                                    (identifier "ssum_dst_756")
                                                                    (if (eq (u16 5) (identifier "label1_755")) (identifier "ssum_dst_756") (seq (assert (eq (identifier "label1_755") (u16 6))) (identifier "ssum_dst_756")))))))))))
                                                            (seq (assert (eq (identifier "label1_749") (u16 6)))
                                                              (let "stup_dst_751" 
                                                                (write-u64 little-endian (identifier "ssum_dst_750") (u64-of-float (get-item 0 (get-alt "Journal" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                (write-u32 little-endian (identifier "stup_dst_751") (get-item 1 (get-alt "Journal" (get-item 1 (get-alt "Incidents" (param 0))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(t,Pointer)> to_row_binary_init()
{
  std::function<Pointer(t,Pointer)> fun2140 { [&fun2140](t p_0, Pointer p_1) {
    uint16_t id_2141 { uint16_t(p_0.index()) };
    Pointer let_res_2142;
    {
      uint16_t label1_744 { id_2141 };
      Pointer id_2143 { p_1.writeU16Le(label1_744) };
      Pointer let_res_2144;
      {
        Pointer ssum_dst_745 { id_2143 };
        uint16_t id_2145 { 0 };
        bool id_2146 { bool(id_2145 == label1_744) };
        Pointer choose_res_2147;
        if (id_2146) {
          choose_res_2147 = ssum_dst_745;
        } else {
          uint16_t id_2148 { 1 };
          bool id_2149 { bool(id_2148 == label1_744) };
          Pointer choose_res_2150;
          if (id_2149) {
            choose_res_2150 = ssum_dst_745;
          } else {
            uint16_t id_2151 { 2 };
            bool id_2152 { bool(id_2151 == label1_744) };
            Pointer choose_res_2153;
            if (id_2152) {
              std::string id_2154 { std::get<2>(p_0) };
              uint32_t id_2155 { (uint32_t)id_2154.size() };
              Vec<1, uint32_t> id_2156 {  id_2155  };
              Pointer let_res_2157;
              {
                Vec<1, uint32_t> leb128_sz_811 { id_2156 };
                Vec<1, Pointer> id_2158 {  ssum_dst_745  };
                Pointer let_res_2159;
                {
                  Vec<1, Pointer> leb128_ptr_812 { id_2158 };
                  bool while_flag_2160 { true };
                  do {
                    uint8_t id_2161 { 0 };
                    uint8_t id_2162 { 0 };
                    Pointer id_2163 { leb128_ptr_812[id_2162] };
                    uint32_t id_2164 { 128U };
                    uint8_t id_2165 { 0 };
                    uint32_t id_2166 { leb128_sz_811[id_2165] };
                    bool id_2167 { bool(id_2164 > id_2166) };
                    uint8_t choose_res_2168;
                    if (id_2167) {
                      uint8_t id_2169 { 0 };
                      uint32_t id_2170 { leb128_sz_811[id_2169] };
                      uint8_t id_2171 { uint8_t(id_2170) };
                      choose_res_2168 = id_2171;
                    } else {
                      uint8_t id_2172 { 0 };
                      uint32_t id_2173 { leb128_sz_811[id_2172] };
                      uint8_t id_2174 { uint8_t(id_2173) };
                      uint8_t id_2175 { 128 };
                      uint8_t id_2176 { uint8_t(id_2174 | id_2175) };
                      choose_res_2168 = id_2176;
                    }
                    Pointer id_2177 { id_2163.writeU8(choose_res_2168) };
                    Void id_2178 { ((void)(leb128_ptr_812[id_2161] = id_2177), VOID) };
                    uint8_t id_2179 { 0 };
                    uint8_t id_2180 { 0 };
                    uint32_t id_2181 { leb128_sz_811[id_2180] };
                    uint8_t id_2182 { 7 };
                    uint32_t id_2183 { uint32_t(id_2181 >> id_2182) };
                    Void id_2184 { ((void)(leb128_sz_811[id_2179] = id_2183), VOID) };
                    uint8_t id_2185 { 0 };
                    uint32_t id_2186 { leb128_sz_811[id_2185] };
                    uint32_t id_2187 { 0U };
                    bool id_2188 { bool(id_2186 > id_2187) };
                    while_flag_2160 = id_2188;
                    if (while_flag_2160) {
                    }
                  } while (while_flag_2160);
                  uint8_t id_2189 { 0 };
                  Pointer id_2190 { leb128_ptr_812[id_2189] };
                  let_res_2159 = id_2190;
                }
                let_res_2157 = let_res_2159;
              }
              std::string id_2191 { std::get<2>(p_0) };
              Bytes id_2192 { id_2191 };
              Pointer id_2193 { let_res_2157.writeBytes(id_2192) };
              choose_res_2153 = id_2193;
            } else {
              uint16_t id_2194 { 3 };
              bool id_2195 { bool(id_2194 == label1_744) };
              Pointer choose_res_2196;
              if (id_2195) {
                std::function<Pointer(*src_path,Pointer)> id_2197 { dessser_gen::src_path.to_row_binary };
                c404d7e7dfb3057f4a4f6b6766eeb900 id_2198 { std::get<3>(p_0) };
                *src_path id_2199 { std::get<0>(id_2198) };
                Pointer id_2200 { id_2197(id_2199, ssum_dst_745) };
                Pointer let_res_2201;
                {
                  Pointer stup_dst_808 { id_2200 };
                  c404d7e7dfb3057f4a4f6b6766eeb900 id_2202 { std::get<3>(p_0) };
                  std::string id_2203 { std::get<1>(id_2202) };
                  uint32_t id_2204 { (uint32_t)id_2203.size() };
                  Vec<1, uint32_t> id_2205 {  id_2204  };
                  Pointer let_res_2206;
                  {
                    Vec<1, uint32_t> leb128_sz_809 { id_2205 };
                    Vec<1, Pointer> id_2207 {  stup_dst_808  };
                    Pointer let_res_2208;
                    {
                      Vec<1, Pointer> leb128_ptr_810 { id_2207 };
                      bool while_flag_2209 { true };
                      do {
                        uint8_t id_2210 { 0 };
                        uint8_t id_2211 { 0 };
                        Pointer id_2212 { leb128_ptr_810[id_2211] };
                        uint32_t id_2213 { 128U };
                        uint8_t id_2214 { 0 };
                        uint32_t id_2215 { leb128_sz_809[id_2214] };
                        bool id_2216 { bool(id_2213 > id_2215) };
                        uint8_t choose_res_2217;
                        if (id_2216) {
                          uint8_t id_2218 { 0 };
                          uint32_t id_2219 { leb128_sz_809[id_2218] };
                          uint8_t id_2220 { uint8_t(id_2219) };
                          choose_res_2217 = id_2220;
                        } else {
                          uint8_t id_2221 { 0 };
                          uint32_t id_2222 { leb128_sz_809[id_2221] };
                          uint8_t id_2223 { uint8_t(id_2222) };
                          uint8_t id_2224 { 128 };
                          uint8_t id_2225 { uint8_t(id_2223 | id_2224) };
                          choose_res_2217 = id_2225;
                        }
                        Pointer id_2226 { id_2212.writeU8(choose_res_2217) };
                        Void id_2227 { ((void)(leb128_ptr_810[id_2210] = id_2226), VOID) };
                        uint8_t id_2228 { 0 };
                        uint8_t id_2229 { 0 };
                        uint32_t id_2230 { leb128_sz_809[id_2229] };
                        uint8_t id_2231 { 7 };
                        uint32_t id_2232 { uint32_t(id_2230 >> id_2231) };
                        Void id_2233 { ((void)(leb128_sz_809[id_2228] = id_2232), VOID) };
                        uint8_t id_2234 { 0 };
                        uint32_t id_2235 { leb128_sz_809[id_2234] };
                        uint32_t id_2236 { 0U };
                        bool id_2237 { bool(id_2235 > id_2236) };
                        while_flag_2209 = id_2237;
                        if (while_flag_2209) {
                        }
                      } while (while_flag_2209);
                      uint8_t id_2238 { 0 };
                      Pointer id_2239 { leb128_ptr_810[id_2238] };
                      let_res_2208 = id_2239;
                    }
                    let_res_2206 = let_res_2208;
                  }
                  c404d7e7dfb3057f4a4f6b6766eeb900 id_2240 { std::get<3>(p_0) };
                  std::string id_2241 { std::get<1>(id_2240) };
                  Bytes id_2242 { id_2241 };
                  Pointer id_2243 { let_res_2206.writeBytes(id_2242) };
                  let_res_2201 = id_2243;
                }
                choose_res_2196 = let_res_2201;
              } else {
                uint16_t id_2244 { 4 };
                bool id_2245 { bool(id_2244 == label1_744) };
                Pointer choose_res_2246;
                if (id_2245) {
                  choose_res_2246 = ssum_dst_745;
                } else {
                  uint16_t id_2247 { 5 };
                  bool id_2248 { bool(id_2247 == label1_744) };
                  Pointer choose_res_2249;
                  if (id_2248) {
                    std::function<Pointer(*site_name,Pointer)> id_2250 { dessser_gen::site_name.to_row_binary };
                    v_26540a608fe059393cc3cd282be43df3 id_2251 { std::get<5>(p_0) };
                    *site_name id_2252 { std::get<0>(id_2251) };
                    Pointer id_2253 { id_2250(id_2252, ssum_dst_745) };
                    Pointer let_res_2254;
                    {
                      Pointer stup_dst_787 { id_2253 };
                      v_26540a608fe059393cc3cd282be43df3 id_2255 { std::get<5>(p_0) };
                      v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2256 { std::get<1>(id_2255) };
                      uint16_t id_2257 { uint16_t(id_2256.index()) };
                      Pointer id_2258 { stup_dst_787.writeU16Le(id_2257) };
                      Pointer let_res_2259;
                      {
                        Pointer ssum_dst_789 { id_2258 };
                        uint16_t id_2260 { 0 };
                        v_26540a608fe059393cc3cd282be43df3 id_2261 { std::get<5>(p_0) };
                        v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2262 { std::get<1>(id_2261) };
                        uint16_t id_2263 { uint16_t(id_2262.index()) };
                        bool id_2264 { bool(id_2260 == id_2263) };
                        Pointer choose_res_2265;
                        if (id_2264) {
                          choose_res_2265 = ssum_dst_789;
                        } else {
                          uint16_t id_2266 { 1 };
                          v_26540a608fe059393cc3cd282be43df3 id_2267 { std::get<5>(p_0) };
                          v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2268 { std::get<1>(id_2267) };
                          uint16_t id_2269 { uint16_t(id_2268.index()) };
                          bool id_2270 { bool(id_2266 == id_2269) };
                          Pointer choose_res_2271;
                          if (id_2270) {
                            v_26540a608fe059393cc3cd282be43df3 id_2272 { std::get<5>(p_0) };
                            v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2273 { std::get<1>(id_2272) };
                            c8d851022c838ee90bc952d525c2d3aa id_2274 { std::get<1>(id_2273) };
                            std::string id_2275 { std::get<0>(id_2274) };
                            uint32_t id_2276 { (uint32_t)id_2275.size() };
                            Vec<1, uint32_t> id_2277 {  id_2276  };
                            Pointer let_res_2278;
                            {
                              Vec<1, uint32_t> leb128_sz_803 { id_2277 };
                              Vec<1, Pointer> id_2279 {  ssum_dst_789  };
                              Pointer let_res_2280;
                              {
                                Vec<1, Pointer> leb128_ptr_804 { id_2279 };
                                bool while_flag_2281 { true };
                                do {
                                  uint8_t id_2282 { 0 };
                                  uint8_t id_2283 { 0 };
                                  Pointer id_2284 { leb128_ptr_804[id_2283] };
                                  uint32_t id_2285 { 128U };
                                  uint8_t id_2286 { 0 };
                                  uint32_t id_2287 { leb128_sz_803[id_2286] };
                                  bool id_2288 { bool(id_2285 > id_2287) };
                                  uint8_t choose_res_2289;
                                  if (id_2288) {
                                    uint8_t id_2290 { 0 };
                                    uint32_t id_2291 { leb128_sz_803[id_2290] };
                                    uint8_t id_2292 { uint8_t(id_2291) };
                                    choose_res_2289 = id_2292;
                                  } else {
                                    uint8_t id_2293 { 0 };
                                    uint32_t id_2294 { leb128_sz_803[id_2293] };
                                    uint8_t id_2295 { uint8_t(id_2294) };
                                    uint8_t id_2296 { 128 };
                                    uint8_t id_2297 { uint8_t(id_2295 | id_2296) };
                                    choose_res_2289 = id_2297;
                                  }
                                  Pointer id_2298 { id_2284.writeU8(choose_res_2289) };
                                  Void id_2299 { ((void)(leb128_ptr_804[id_2282] = id_2298), VOID) };
                                  uint8_t id_2300 { 0 };
                                  uint8_t id_2301 { 0 };
                                  uint32_t id_2302 { leb128_sz_803[id_2301] };
                                  uint8_t id_2303 { 7 };
                                  uint32_t id_2304 { uint32_t(id_2302 >> id_2303) };
                                  Void id_2305 { ((void)(leb128_sz_803[id_2300] = id_2304), VOID) };
                                  uint8_t id_2306 { 0 };
                                  uint32_t id_2307 { leb128_sz_803[id_2306] };
                                  uint32_t id_2308 { 0U };
                                  bool id_2309 { bool(id_2307 > id_2308) };
                                  while_flag_2281 = id_2309;
                                  if (while_flag_2281) {
                                  }
                                } while (while_flag_2281);
                                uint8_t id_2310 { 0 };
                                Pointer id_2311 { leb128_ptr_804[id_2310] };
                                let_res_2280 = id_2311;
                              }
                              let_res_2278 = let_res_2280;
                            }
                            v_26540a608fe059393cc3cd282be43df3 id_2312 { std::get<5>(p_0) };
                            v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2313 { std::get<1>(id_2312) };
                            c8d851022c838ee90bc952d525c2d3aa id_2314 { std::get<1>(id_2313) };
                            std::string id_2315 { std::get<0>(id_2314) };
                            Bytes id_2316 { id_2315 };
                            Pointer id_2317 { let_res_2278.writeBytes(id_2316) };
                            Pointer let_res_2318;
                            {
                              Pointer stup_dst_805 { id_2317 };
                              v_26540a608fe059393cc3cd282be43df3 id_2319 { std::get<5>(p_0) };
                              v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2320 { std::get<1>(id_2319) };
                              c8d851022c838ee90bc952d525c2d3aa id_2321 { std::get<1>(id_2320) };
                              v_1e81caa74ae611e9cb191b8ee50bee25 id_2322 { std::get<1>(id_2321) };
                              uint16_t id_2323 { uint16_t(id_2322.index()) };
                              Pointer id_2324 { stup_dst_805.writeU16Le(id_2323) };
                              Pointer let_res_2325;
                              {
                                Pointer ssum_dst_807 { id_2324 };
                                uint16_t id_2326 { 0 };
                                v_26540a608fe059393cc3cd282be43df3 id_2327 { std::get<5>(p_0) };
                                v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2328 { std::get<1>(id_2327) };
                                c8d851022c838ee90bc952d525c2d3aa id_2329 { std::get<1>(id_2328) };
                                v_1e81caa74ae611e9cb191b8ee50bee25 id_2330 { std::get<1>(id_2329) };
                                uint16_t id_2331 { uint16_t(id_2330.index()) };
                                bool id_2332 { bool(id_2326 == id_2331) };
                                Pointer choose_res_2333;
                                if (id_2332) {
                                  choose_res_2333 = ssum_dst_807;
                                } else {
                                  v_26540a608fe059393cc3cd282be43df3 id_2334 { std::get<5>(p_0) };
                                  v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2335 { std::get<1>(id_2334) };
                                  c8d851022c838ee90bc952d525c2d3aa id_2336 { std::get<1>(id_2335) };
                                  v_1e81caa74ae611e9cb191b8ee50bee25 id_2337 { std::get<1>(id_2336) };
                                  uint16_t id_2338 { uint16_t(id_2337.index()) };
                                  uint16_t id_2339 { 1 };
                                  bool id_2340 { bool(id_2338 == id_2339) };
                                  Void id_2341 { ((void)(assert(id_2340)), VOID) };
                                  choose_res_2333 = ssum_dst_807;
                                }
                                let_res_2325 = choose_res_2333;
                              }
                              let_res_2318 = let_res_2325;
                            }
                            choose_res_2271 = let_res_2318;
                          } else {
                            uint16_t id_2342 { 2 };
                            v_26540a608fe059393cc3cd282be43df3 id_2343 { std::get<5>(p_0) };
                            v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2344 { std::get<1>(id_2343) };
                            uint16_t id_2345 { uint16_t(id_2344.index()) };
                            bool id_2346 { bool(id_2342 == id_2345) };
                            Pointer choose_res_2347;
                            if (id_2346) {
                              std::function<Pointer(*fq_name,Pointer)> id_2348 { dessser_gen::fq_name.to_row_binary };
                              v_26540a608fe059393cc3cd282be43df3 id_2349 { std::get<5>(p_0) };
                              v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2350 { std::get<1>(id_2349) };
                              v_0fab8a04cd41fd489e58d011ef6f08ad id_2351 { std::get<2>(id_2350) };
                              *fq_name id_2352 { std::get<0>(id_2351) };
                              Pointer id_2353 { id_2348(id_2352, ssum_dst_789) };
                              Pointer let_res_2354;
                              {
                                Pointer stup_dst_795 { id_2353 };
                                v_26540a608fe059393cc3cd282be43df3 id_2355 { std::get<5>(p_0) };
                                v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2356 { std::get<1>(id_2355) };
                                v_0fab8a04cd41fd489e58d011ef6f08ad id_2357 { std::get<2>(id_2356) };
                                v_8c6c9edc5b1d709b5094571801c00912 id_2358 { std::get<1>(id_2357) };
                                uint16_t id_2359 { uint16_t(id_2358.index()) };
                                Pointer let_res_2360;
                                {
                                  uint16_t label1_796 { id_2359 };
                                  Pointer id_2361 { stup_dst_795.writeU16Le(label1_796) };
                                  Pointer let_res_2362;
                                  {
                                    Pointer ssum_dst_797 { id_2361 };
                                    uint16_t id_2363 { 0 };
                                    bool id_2364 { bool(id_2363 == label1_796) };
                                    Pointer choose_res_2365;
                                    if (id_2364) {
                                      choose_res_2365 = ssum_dst_797;
                                    } else {
                                      uint16_t id_2366 { 1 };
                                      bool id_2367 { bool(id_2366 == label1_796) };
                                      Pointer choose_res_2368;
                                      if (id_2367) {
                                        choose_res_2368 = ssum_dst_797;
                                      } else {
                                        uint16_t id_2369 { 2 };
                                        bool id_2370 { bool(id_2369 == label1_796) };
                                        Pointer choose_res_2371;
                                        if (id_2370) {
                                          choose_res_2371 = ssum_dst_797;
                                        } else {
                                          uint16_t id_2372 { 3 };
                                          bool id_2373 { bool(id_2372 == label1_796) };
                                          Pointer choose_res_2374;
                                          if (id_2373) {
                                            choose_res_2374 = ssum_dst_797;
                                          } else {
                                            uint16_t id_2375 { 4 };
                                            bool id_2376 { bool(id_2375 == label1_796) };
                                            Pointer choose_res_2377;
                                            if (id_2376) {
                                              choose_res_2377 = ssum_dst_797;
                                            } else {
                                              uint16_t id_2378 { 5 };
                                              bool id_2379 { bool(id_2378 == label1_796) };
                                              Pointer choose_res_2380;
                                              if (id_2379) {
                                                choose_res_2380 = ssum_dst_797;
                                              } else {
                                                uint16_t id_2381 { 6 };
                                                bool id_2382 { bool(id_2381 == label1_796) };
                                                Pointer choose_res_2383;
                                                if (id_2382) {
                                                  v_26540a608fe059393cc3cd282be43df3 id_2384 { std::get<5>(p_0) };
                                                  v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2385 { std::get<1>(id_2384) };
                                                  v_0fab8a04cd41fd489e58d011ef6f08ad id_2386 { std::get<2>(id_2385) };
                                                  v_8c6c9edc5b1d709b5094571801c00912 id_2387 { std::get<1>(id_2386) };
                                                  a9a5fa86cfaa17c85b3606d1a4582bcd id_2388 { std::get<6>(id_2387) };
                                                  std::string id_2389 { std::get<0>(id_2388) };
                                                  uint32_t id_2390 { (uint32_t)id_2389.size() };
                                                  Vec<1, uint32_t> id_2391 {  id_2390  };
                                                  Pointer let_res_2392;
                                                  {
                                                    Vec<1, uint32_t> leb128_sz_798 { id_2391 };
                                                    Vec<1, Pointer> id_2393 {  ssum_dst_797  };
                                                    Pointer let_res_2394;
                                                    {
                                                      Vec<1, Pointer> leb128_ptr_799 { id_2393 };
                                                      bool while_flag_2395 { true };
                                                      do {
                                                        uint8_t id_2396 { 0 };
                                                        uint8_t id_2397 { 0 };
                                                        Pointer id_2398 { leb128_ptr_799[id_2397] };
                                                        uint32_t id_2399 { 128U };
                                                        uint8_t id_2400 { 0 };
                                                        uint32_t id_2401 { leb128_sz_798[id_2400] };
                                                        bool id_2402 { bool(id_2399 > id_2401) };
                                                        uint8_t choose_res_2403;
                                                        if (id_2402) {
                                                          uint8_t id_2404 { 0 };
                                                          uint32_t id_2405 { leb128_sz_798[id_2404] };
                                                          uint8_t id_2406 { uint8_t(id_2405) };
                                                          choose_res_2403 = id_2406;
                                                        } else {
                                                          uint8_t id_2407 { 0 };
                                                          uint32_t id_2408 { leb128_sz_798[id_2407] };
                                                          uint8_t id_2409 { uint8_t(id_2408) };
                                                          uint8_t id_2410 { 128 };
                                                          uint8_t id_2411 { uint8_t(id_2409 | id_2410) };
                                                          choose_res_2403 = id_2411;
                                                        }
                                                        Pointer id_2412 { id_2398.writeU8(choose_res_2403) };
                                                        Void id_2413 { ((void)(leb128_ptr_799[id_2396] = id_2412), VOID) };
                                                        uint8_t id_2414 { 0 };
                                                        uint8_t id_2415 { 0 };
                                                        uint32_t id_2416 { leb128_sz_798[id_2415] };
                                                        uint8_t id_2417 { 7 };
                                                        uint32_t id_2418 { uint32_t(id_2416 >> id_2417) };
                                                        Void id_2419 { ((void)(leb128_sz_798[id_2414] = id_2418), VOID) };
                                                        uint8_t id_2420 { 0 };
                                                        uint32_t id_2421 { leb128_sz_798[id_2420] };
                                                        uint32_t id_2422 { 0U };
                                                        bool id_2423 { bool(id_2421 > id_2422) };
                                                        while_flag_2395 = id_2423;
                                                        if (while_flag_2395) {
                                                        }
                                                      } while (while_flag_2395);
                                                      uint8_t id_2424 { 0 };
                                                      Pointer id_2425 { leb128_ptr_799[id_2424] };
                                                      let_res_2394 = id_2425;
                                                    }
                                                    let_res_2392 = let_res_2394;
                                                  }
                                                  v_26540a608fe059393cc3cd282be43df3 id_2426 { std::get<5>(p_0) };
                                                  v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2427 { std::get<1>(id_2426) };
                                                  v_0fab8a04cd41fd489e58d011ef6f08ad id_2428 { std::get<2>(id_2427) };
                                                  v_8c6c9edc5b1d709b5094571801c00912 id_2429 { std::get<1>(id_2428) };
                                                  a9a5fa86cfaa17c85b3606d1a4582bcd id_2430 { std::get<6>(id_2429) };
                                                  std::string id_2431 { std::get<0>(id_2430) };
                                                  Bytes id_2432 { id_2431 };
                                                  Pointer id_2433 { let_res_2392.writeBytes(id_2432) };
                                                  Pointer let_res_2434;
                                                  {
                                                    Pointer stup_dst_800 { id_2433 };
                                                    v_26540a608fe059393cc3cd282be43df3 id_2435 { std::get<5>(p_0) };
                                                    v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2436 { std::get<1>(id_2435) };
                                                    v_0fab8a04cd41fd489e58d011ef6f08ad id_2437 { std::get<2>(id_2436) };
                                                    v_8c6c9edc5b1d709b5094571801c00912 id_2438 { std::get<1>(id_2437) };
                                                    a9a5fa86cfaa17c85b3606d1a4582bcd id_2439 { std::get<6>(id_2438) };
                                                    v_8e097ae30bed5641a60541fcf38314dd id_2440 { std::get<1>(id_2439) };
                                                    uint16_t id_2441 { uint16_t(id_2440.index()) };
                                                    Pointer let_res_2442;
                                                    {
                                                      uint16_t label1_801 { id_2441 };
                                                      Pointer id_2443 { stup_dst_800.writeU16Le(label1_801) };
                                                      Pointer let_res_2444;
                                                      {
                                                        Pointer ssum_dst_802 { id_2443 };
                                                        uint16_t id_2445 { 0 };
                                                        bool id_2446 { bool(id_2445 == label1_801) };
                                                        Pointer choose_res_2447;
                                                        if (id_2446) {
                                                          choose_res_2447 = ssum_dst_802;
                                                        } else {
                                                          uint16_t id_2448 { 1 };
                                                          bool id_2449 { bool(id_2448 == label1_801) };
                                                          Pointer choose_res_2450;
                                                          if (id_2449) {
                                                            choose_res_2450 = ssum_dst_802;
                                                          } else {
                                                            uint16_t id_2451 { 2 };
                                                            bool id_2452 { bool(id_2451 == label1_801) };
                                                            Pointer choose_res_2453;
                                                            if (id_2452) {
                                                              choose_res_2453 = ssum_dst_802;
                                                            } else {
                                                              uint16_t id_2454 { 3 };
                                                              bool id_2455 { bool(id_2454 == label1_801) };
                                                              Pointer choose_res_2456;
                                                              if (id_2455) {
                                                                choose_res_2456 = ssum_dst_802;
                                                              } else {
                                                                uint16_t id_2457 { 4 };
                                                                bool id_2458 { bool(id_2457 == label1_801) };
                                                                Pointer choose_res_2459;
                                                                if (id_2458) {
                                                                  choose_res_2459 = ssum_dst_802;
                                                                } else {
                                                                  uint16_t id_2460 { 5 };
                                                                  bool id_2461 { bool(id_2460 == label1_801) };
                                                                  Pointer choose_res_2462;
                                                                  if (id_2461) {
                                                                    choose_res_2462 = ssum_dst_802;
                                                                  } else {
                                                                    uint16_t id_2463 { 6 };
                                                                    bool id_2464 { bool(id_2463 == label1_801) };
                                                                    Pointer choose_res_2465;
                                                                    if (id_2464) {
                                                                      choose_res_2465 = ssum_dst_802;
                                                                    } else {
                                                                      uint16_t id_2466 { 7 };
                                                                      bool id_2467 { bool(label1_801 == id_2466) };
                                                                      Void id_2468 { ((void)(assert(id_2467)), VOID) };
                                                                      choose_res_2465 = ssum_dst_802;
                                                                    }
                                                                    choose_res_2462 = choose_res_2465;
                                                                  }
                                                                  choose_res_2459 = choose_res_2462;
                                                                }
                                                                choose_res_2456 = choose_res_2459;
                                                              }
                                                              choose_res_2453 = choose_res_2456;
                                                            }
                                                            choose_res_2450 = choose_res_2453;
                                                          }
                                                          choose_res_2447 = choose_res_2450;
                                                        }
                                                        let_res_2444 = choose_res_2447;
                                                      }
                                                      let_res_2442 = let_res_2444;
                                                    }
                                                    let_res_2434 = let_res_2442;
                                                  }
                                                  choose_res_2383 = let_res_2434;
                                                } else {
                                                  uint16_t id_2469 { 7 };
                                                  bool id_2470 { bool(id_2469 == label1_796) };
                                                  Pointer choose_res_2471;
                                                  if (id_2470) {
                                                    v_26540a608fe059393cc3cd282be43df3 id_2472 { std::get<5>(p_0) };
                                                    v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2473 { std::get<1>(id_2472) };
                                                    v_0fab8a04cd41fd489e58d011ef6f08ad id_2474 { std::get<2>(id_2473) };
                                                    v_8c6c9edc5b1d709b5094571801c00912 id_2475 { std::get<1>(id_2474) };
                                                    uint32_t id_2476 { std::get<7>(id_2475) };
                                                    Pointer id_2477 { ssum_dst_797.writeU32Le(id_2476) };
                                                    choose_res_2471 = id_2477;
                                                  } else {
                                                    uint16_t id_2478 { 8 };
                                                    bool id_2479 { bool(label1_796 == id_2478) };
                                                    Void id_2480 { ((void)(assert(id_2479)), VOID) };
                                                    choose_res_2471 = ssum_dst_797;
                                                  }
                                                  choose_res_2383 = choose_res_2471;
                                                }
                                                choose_res_2380 = choose_res_2383;
                                              }
                                              choose_res_2377 = choose_res_2380;
                                            }
                                            choose_res_2374 = choose_res_2377;
                                          }
                                          choose_res_2371 = choose_res_2374;
                                        }
                                        choose_res_2368 = choose_res_2371;
                                      }
                                      choose_res_2365 = choose_res_2368;
                                    }
                                    let_res_2362 = choose_res_2365;
                                  }
                                  let_res_2360 = let_res_2362;
                                }
                                let_res_2354 = let_res_2360;
                              }
                              choose_res_2347 = let_res_2354;
                            } else {
                              v_26540a608fe059393cc3cd282be43df3 id_2481 { std::get<5>(p_0) };
                              v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2482 { std::get<1>(id_2481) };
                              uint16_t id_2483 { uint16_t(id_2482.index()) };
                              uint16_t id_2484 { 3 };
                              bool id_2485 { bool(id_2483 == id_2484) };
                              Void id_2486 { ((void)(assert(id_2485)), VOID) };
                              v_26540a608fe059393cc3cd282be43df3 id_2487 { std::get<5>(p_0) };
                              v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2488 { std::get<1>(id_2487) };
                              v_9a47b091ef9a7a446e50646760330664 id_2489 { std::get<3>(id_2488) };
                              std::string id_2490 { std::get<0>(id_2489) };
                              uint32_t id_2491 { (uint32_t)id_2490.size() };
                              Vec<1, uint32_t> id_2492 {  id_2491  };
                              Pointer let_res_2493;
                              {
                                Vec<1, uint32_t> leb128_sz_790 { id_2492 };
                                Vec<1, Pointer> id_2494 {  ssum_dst_789  };
                                Pointer let_res_2495;
                                {
                                  Vec<1, Pointer> leb128_ptr_791 { id_2494 };
                                  bool while_flag_2496 { true };
                                  do {
                                    uint8_t id_2497 { 0 };
                                    uint8_t id_2498 { 0 };
                                    Pointer id_2499 { leb128_ptr_791[id_2498] };
                                    uint32_t id_2500 { 128U };
                                    uint8_t id_2501 { 0 };
                                    uint32_t id_2502 { leb128_sz_790[id_2501] };
                                    bool id_2503 { bool(id_2500 > id_2502) };
                                    uint8_t choose_res_2504;
                                    if (id_2503) {
                                      uint8_t id_2505 { 0 };
                                      uint32_t id_2506 { leb128_sz_790[id_2505] };
                                      uint8_t id_2507 { uint8_t(id_2506) };
                                      choose_res_2504 = id_2507;
                                    } else {
                                      uint8_t id_2508 { 0 };
                                      uint32_t id_2509 { leb128_sz_790[id_2508] };
                                      uint8_t id_2510 { uint8_t(id_2509) };
                                      uint8_t id_2511 { 128 };
                                      uint8_t id_2512 { uint8_t(id_2510 | id_2511) };
                                      choose_res_2504 = id_2512;
                                    }
                                    Pointer id_2513 { id_2499.writeU8(choose_res_2504) };
                                    Void id_2514 { ((void)(leb128_ptr_791[id_2497] = id_2513), VOID) };
                                    uint8_t id_2515 { 0 };
                                    uint8_t id_2516 { 0 };
                                    uint32_t id_2517 { leb128_sz_790[id_2516] };
                                    uint8_t id_2518 { 7 };
                                    uint32_t id_2519 { uint32_t(id_2517 >> id_2518) };
                                    Void id_2520 { ((void)(leb128_sz_790[id_2515] = id_2519), VOID) };
                                    uint8_t id_2521 { 0 };
                                    uint32_t id_2522 { leb128_sz_790[id_2521] };
                                    uint32_t id_2523 { 0U };
                                    bool id_2524 { bool(id_2522 > id_2523) };
                                    while_flag_2496 = id_2524;
                                    if (while_flag_2496) {
                                    }
                                  } while (while_flag_2496);
                                  uint8_t id_2525 { 0 };
                                  Pointer id_2526 { leb128_ptr_791[id_2525] };
                                  let_res_2495 = id_2526;
                                }
                                let_res_2493 = let_res_2495;
                              }
                              v_26540a608fe059393cc3cd282be43df3 id_2527 { std::get<5>(p_0) };
                              v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2528 { std::get<1>(id_2527) };
                              v_9a47b091ef9a7a446e50646760330664 id_2529 { std::get<3>(id_2528) };
                              std::string id_2530 { std::get<0>(id_2529) };
                              Bytes id_2531 { id_2530 };
                              Pointer id_2532 { let_res_2493.writeBytes(id_2531) };
                              Pointer let_res_2533;
                              {
                                Pointer stup_dst_792 { id_2532 };
                                v_26540a608fe059393cc3cd282be43df3 id_2534 { std::get<5>(p_0) };
                                v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2535 { std::get<1>(id_2534) };
                                v_9a47b091ef9a7a446e50646760330664 id_2536 { std::get<3>(id_2535) };
                                v_5c73eec19356406029ebc971f8fc93ef id_2537 { std::get<1>(id_2536) };
                                uint16_t id_2538 { uint16_t(id_2537.index()) };
                                Pointer id_2539 { stup_dst_792.writeU16Le(id_2538) };
                                Pointer let_res_2540;
                                {
                                  Pointer ssum_dst_794 { id_2539 };
                                  v_26540a608fe059393cc3cd282be43df3 id_2541 { std::get<5>(p_0) };
                                  v_320dee9bcc93c7ed0c75cc7db8b85d9b id_2542 { std::get<1>(id_2541) };
                                  v_9a47b091ef9a7a446e50646760330664 id_2543 { std::get<3>(id_2542) };
                                  v_5c73eec19356406029ebc971f8fc93ef id_2544 { std::get<1>(id_2543) };
                                  uint16_t id_2545 { uint16_t(id_2544.index()) };
                                  uint16_t id_2546 { 0 };
                                  bool id_2547 { bool(id_2545 == id_2546) };
                                  Void id_2548 { ((void)(assert(id_2547)), VOID) };
                                  let_res_2540 = ssum_dst_794;
                                }
                                let_res_2533 = let_res_2540;
                              }
                              choose_res_2347 = let_res_2533;
                            }
                            choose_res_2271 = choose_res_2347;
                          }
                          choose_res_2265 = choose_res_2271;
                        }
                        let_res_2259 = choose_res_2265;
                      }
                      let_res_2254 = let_res_2259;
                    }
                    choose_res_2249 = let_res_2254;
                  } else {
                    uint16_t id_2549 { 6 };
                    bool id_2550 { bool(id_2549 == label1_744) };
                    Pointer choose_res_2551;
                    if (id_2550) {
                      v_60ff76b761c62e00eb6df04e7d00fbc8 id_2552 { std::get<6>(p_0) };
                      uint16_t id_2553 { uint16_t(id_2552.index()) };
                      Pointer id_2554 { ssum_dst_745.writeU16Le(id_2553) };
                      Pointer let_res_2555;
                      {
                        Pointer ssum_dst_784 { id_2554 };
                        uint16_t id_2556 { 0 };
                        v_60ff76b761c62e00eb6df04e7d00fbc8 id_2557 { std::get<6>(p_0) };
                        uint16_t id_2558 { uint16_t(id_2557.index()) };
                        bool id_2559 { bool(id_2556 == id_2558) };
                        Pointer choose_res_2560;
                        if (id_2559) {
                          choose_res_2560 = ssum_dst_784;
                        } else {
                          uint16_t id_2561 { 1 };
                          v_60ff76b761c62e00eb6df04e7d00fbc8 id_2562 { std::get<6>(p_0) };
                          uint16_t id_2563 { uint16_t(id_2562.index()) };
                          bool id_2564 { bool(id_2561 == id_2563) };
                          Pointer choose_res_2565;
                          if (id_2564) {
                            choose_res_2565 = ssum_dst_784;
                          } else {
                            v_60ff76b761c62e00eb6df04e7d00fbc8 id_2566 { std::get<6>(p_0) };
                            uint16_t id_2567 { uint16_t(id_2566.index()) };
                            uint16_t id_2568 { 2 };
                            bool id_2569 { bool(id_2567 == id_2568) };
                            Void id_2570 { ((void)(assert(id_2569)), VOID) };
                            v_60ff76b761c62e00eb6df04e7d00fbc8 id_2571 { std::get<6>(p_0) };
                            std::string id_2572 { std::get<2>(id_2571) };
                            uint32_t id_2573 { (uint32_t)id_2572.size() };
                            Vec<1, uint32_t> id_2574 {  id_2573  };
                            Pointer let_res_2575;
                            {
                              Vec<1, uint32_t> leb128_sz_785 { id_2574 };
                              Vec<1, Pointer> id_2576 {  ssum_dst_784  };
                              Pointer let_res_2577;
                              {
                                Vec<1, Pointer> leb128_ptr_786 { id_2576 };
                                bool while_flag_2578 { true };
                                do {
                                  uint8_t id_2579 { 0 };
                                  uint8_t id_2580 { 0 };
                                  Pointer id_2581 { leb128_ptr_786[id_2580] };
                                  uint32_t id_2582 { 128U };
                                  uint8_t id_2583 { 0 };
                                  uint32_t id_2584 { leb128_sz_785[id_2583] };
                                  bool id_2585 { bool(id_2582 > id_2584) };
                                  uint8_t choose_res_2586;
                                  if (id_2585) {
                                    uint8_t id_2587 { 0 };
                                    uint32_t id_2588 { leb128_sz_785[id_2587] };
                                    uint8_t id_2589 { uint8_t(id_2588) };
                                    choose_res_2586 = id_2589;
                                  } else {
                                    uint8_t id_2590 { 0 };
                                    uint32_t id_2591 { leb128_sz_785[id_2590] };
                                    uint8_t id_2592 { uint8_t(id_2591) };
                                    uint8_t id_2593 { 128 };
                                    uint8_t id_2594 { uint8_t(id_2592 | id_2593) };
                                    choose_res_2586 = id_2594;
                                  }
                                  Pointer id_2595 { id_2581.writeU8(choose_res_2586) };
                                  Void id_2596 { ((void)(leb128_ptr_786[id_2579] = id_2595), VOID) };
                                  uint8_t id_2597 { 0 };
                                  uint8_t id_2598 { 0 };
                                  uint32_t id_2599 { leb128_sz_785[id_2598] };
                                  uint8_t id_2600 { 7 };
                                  uint32_t id_2601 { uint32_t(id_2599 >> id_2600) };
                                  Void id_2602 { ((void)(leb128_sz_785[id_2597] = id_2601), VOID) };
                                  uint8_t id_2603 { 0 };
                                  uint32_t id_2604 { leb128_sz_785[id_2603] };
                                  uint32_t id_2605 { 0U };
                                  bool id_2606 { bool(id_2604 > id_2605) };
                                  while_flag_2578 = id_2606;
                                  if (while_flag_2578) {
                                  }
                                } while (while_flag_2578);
                                uint8_t id_2607 { 0 };
                                Pointer id_2608 { leb128_ptr_786[id_2607] };
                                let_res_2577 = id_2608;
                              }
                              let_res_2575 = let_res_2577;
                            }
                            v_60ff76b761c62e00eb6df04e7d00fbc8 id_2609 { std::get<6>(p_0) };
                            std::string id_2610 { std::get<2>(id_2609) };
                            Bytes id_2611 { id_2610 };
                            Pointer id_2612 { let_res_2575.writeBytes(id_2611) };
                            choose_res_2565 = id_2612;
                          }
                          choose_res_2560 = choose_res_2565;
                        }
                        let_res_2555 = choose_res_2560;
                      }
                      choose_res_2551 = let_res_2555;
                    } else {
                      uint16_t id_2613 { 7 };
                      bool id_2614 { bool(id_2613 == label1_744) };
                      Pointer choose_res_2615;
                      if (id_2614) {
                        std::function<Pointer(*site_name,Pointer)> id_2616 { dessser_gen::site_name.to_row_binary };
                        v_3a6e990115d17bf3eefa1b91b13ca80b id_2617 { std::get<7>(p_0) };
                        *site_name id_2618 { std::get<0>(id_2617) };
                        Pointer id_2619 { id_2616(id_2618, ssum_dst_745) };
                        Pointer let_res_2620;
                        {
                          Pointer stup_dst_774 { id_2619 };
                          std::function<Pointer(*fq_name,Pointer)> id_2621 { dessser_gen::fq_name.to_row_binary };
                          v_3a6e990115d17bf3eefa1b91b13ca80b id_2622 { std::get<7>(p_0) };
                          *fq_name id_2623 { std::get<1>(id_2622) };
                          Pointer id_2624 { id_2621(id_2623, stup_dst_774) };
                          let_res_2620 = id_2624;
                        }
                        Pointer let_res_2625;
                        {
                          Pointer stup_dst_775 { let_res_2620 };
                          v_3a6e990115d17bf3eefa1b91b13ca80b id_2626 { std::get<7>(p_0) };
                          std::string id_2627 { std::get<2>(id_2626) };
                          uint32_t id_2628 { (uint32_t)id_2627.size() };
                          Vec<1, uint32_t> id_2629 {  id_2628  };
                          Pointer let_res_2630;
                          {
                            Vec<1, uint32_t> leb128_sz_776 { id_2629 };
                            Vec<1, Pointer> id_2631 {  stup_dst_775  };
                            Pointer let_res_2632;
                            {
                              Vec<1, Pointer> leb128_ptr_777 { id_2631 };
                              bool while_flag_2633 { true };
                              do {
                                uint8_t id_2634 { 0 };
                                uint8_t id_2635 { 0 };
                                Pointer id_2636 { leb128_ptr_777[id_2635] };
                                uint32_t id_2637 { 128U };
                                uint8_t id_2638 { 0 };
                                uint32_t id_2639 { leb128_sz_776[id_2638] };
                                bool id_2640 { bool(id_2637 > id_2639) };
                                uint8_t choose_res_2641;
                                if (id_2640) {
                                  uint8_t id_2642 { 0 };
                                  uint32_t id_2643 { leb128_sz_776[id_2642] };
                                  uint8_t id_2644 { uint8_t(id_2643) };
                                  choose_res_2641 = id_2644;
                                } else {
                                  uint8_t id_2645 { 0 };
                                  uint32_t id_2646 { leb128_sz_776[id_2645] };
                                  uint8_t id_2647 { uint8_t(id_2646) };
                                  uint8_t id_2648 { 128 };
                                  uint8_t id_2649 { uint8_t(id_2647 | id_2648) };
                                  choose_res_2641 = id_2649;
                                }
                                Pointer id_2650 { id_2636.writeU8(choose_res_2641) };
                                Void id_2651 { ((void)(leb128_ptr_777[id_2634] = id_2650), VOID) };
                                uint8_t id_2652 { 0 };
                                uint8_t id_2653 { 0 };
                                uint32_t id_2654 { leb128_sz_776[id_2653] };
                                uint8_t id_2655 { 7 };
                                uint32_t id_2656 { uint32_t(id_2654 >> id_2655) };
                                Void id_2657 { ((void)(leb128_sz_776[id_2652] = id_2656), VOID) };
                                uint8_t id_2658 { 0 };
                                uint32_t id_2659 { leb128_sz_776[id_2658] };
                                uint32_t id_2660 { 0U };
                                bool id_2661 { bool(id_2659 > id_2660) };
                                while_flag_2633 = id_2661;
                                if (while_flag_2633) {
                                }
                              } while (while_flag_2633);
                              uint8_t id_2662 { 0 };
                              Pointer id_2663 { leb128_ptr_777[id_2662] };
                              let_res_2632 = id_2663;
                            }
                            let_res_2630 = let_res_2632;
                          }
                          v_3a6e990115d17bf3eefa1b91b13ca80b id_2664 { std::get<7>(p_0) };
                          std::string id_2665 { std::get<2>(id_2664) };
                          Bytes id_2666 { id_2665 };
                          Pointer id_2667 { let_res_2630.writeBytes(id_2666) };
                          let_res_2625 = id_2667;
                        }
                        Pointer let_res_2668;
                        {
                          Pointer stup_dst_778 { let_res_2625 };
                          v_3a6e990115d17bf3eefa1b91b13ca80b id_2669 { std::get<7>(p_0) };
                          v_6c1c7418355e363a303990cad40945dd id_2670 { std::get<3>(id_2669) };
                          uint16_t id_2671 { uint16_t(id_2670.index()) };
                          Pointer id_2672 { stup_dst_778.writeU16Le(id_2671) };
                          Pointer let_res_2673;
                          {
                            Pointer ssum_dst_780 { id_2672 };
                            uint16_t id_2674 { 0 };
                            v_3a6e990115d17bf3eefa1b91b13ca80b id_2675 { std::get<7>(p_0) };
                            v_6c1c7418355e363a303990cad40945dd id_2676 { std::get<3>(id_2675) };
                            uint16_t id_2677 { uint16_t(id_2676.index()) };
                            bool id_2678 { bool(id_2674 == id_2677) };
                            Pointer choose_res_2679;
                            if (id_2678) {
                              v_3a6e990115d17bf3eefa1b91b13ca80b id_2680 { std::get<7>(p_0) };
                              v_6c1c7418355e363a303990cad40945dd id_2681 { std::get<3>(id_2680) };
                              std::string id_2682 { std::get<0>(id_2681) };
                              uint32_t id_2683 { (uint32_t)id_2682.size() };
                              Vec<1, uint32_t> id_2684 {  id_2683  };
                              Pointer let_res_2685;
                              {
                                Vec<1, uint32_t> leb128_sz_781 { id_2684 };
                                Vec<1, Pointer> id_2686 {  ssum_dst_780  };
                                Pointer let_res_2687;
                                {
                                  Vec<1, Pointer> leb128_ptr_782 { id_2686 };
                                  bool while_flag_2688 { true };
                                  do {
                                    uint8_t id_2689 { 0 };
                                    uint8_t id_2690 { 0 };
                                    Pointer id_2691 { leb128_ptr_782[id_2690] };
                                    uint32_t id_2692 { 128U };
                                    uint8_t id_2693 { 0 };
                                    uint32_t id_2694 { leb128_sz_781[id_2693] };
                                    bool id_2695 { bool(id_2692 > id_2694) };
                                    uint8_t choose_res_2696;
                                    if (id_2695) {
                                      uint8_t id_2697 { 0 };
                                      uint32_t id_2698 { leb128_sz_781[id_2697] };
                                      uint8_t id_2699 { uint8_t(id_2698) };
                                      choose_res_2696 = id_2699;
                                    } else {
                                      uint8_t id_2700 { 0 };
                                      uint32_t id_2701 { leb128_sz_781[id_2700] };
                                      uint8_t id_2702 { uint8_t(id_2701) };
                                      uint8_t id_2703 { 128 };
                                      uint8_t id_2704 { uint8_t(id_2702 | id_2703) };
                                      choose_res_2696 = id_2704;
                                    }
                                    Pointer id_2705 { id_2691.writeU8(choose_res_2696) };
                                    Void id_2706 { ((void)(leb128_ptr_782[id_2689] = id_2705), VOID) };
                                    uint8_t id_2707 { 0 };
                                    uint8_t id_2708 { 0 };
                                    uint32_t id_2709 { leb128_sz_781[id_2708] };
                                    uint8_t id_2710 { 7 };
                                    uint32_t id_2711 { uint32_t(id_2709 >> id_2710) };
                                    Void id_2712 { ((void)(leb128_sz_781[id_2707] = id_2711), VOID) };
                                    uint8_t id_2713 { 0 };
                                    uint32_t id_2714 { leb128_sz_781[id_2713] };
                                    uint32_t id_2715 { 0U };
                                    bool id_2716 { bool(id_2714 > id_2715) };
                                    while_flag_2688 = id_2716;
                                    if (while_flag_2688) {
                                    }
                                  } while (while_flag_2688);
                                  uint8_t id_2717 { 0 };
                                  Pointer id_2718 { leb128_ptr_782[id_2717] };
                                  let_res_2687 = id_2718;
                                }
                                let_res_2685 = let_res_2687;
                              }
                              v_3a6e990115d17bf3eefa1b91b13ca80b id_2719 { std::get<7>(p_0) };
                              v_6c1c7418355e363a303990cad40945dd id_2720 { std::get<3>(id_2719) };
                              std::string id_2721 { std::get<0>(id_2720) };
                              Bytes id_2722 { id_2721 };
                              Pointer id_2723 { let_res_2685.writeBytes(id_2722) };
                              choose_res_2679 = id_2723;
                            } else {
                              v_3a6e990115d17bf3eefa1b91b13ca80b id_2724 { std::get<7>(p_0) };
                              v_6c1c7418355e363a303990cad40945dd id_2725 { std::get<3>(id_2724) };
                              uint16_t id_2726 { uint16_t(id_2725.index()) };
                              uint16_t id_2727 { 1 };
                              bool id_2728 { bool(id_2726 == id_2727) };
                              Void id_2729 { ((void)(assert(id_2728)), VOID) };
                              v_3a6e990115d17bf3eefa1b91b13ca80b id_2730 { std::get<7>(p_0) };
                              v_6c1c7418355e363a303990cad40945dd id_2731 { std::get<3>(id_2730) };
                              uint32_t id_2732 { std::get<1>(id_2731) };
                              Pointer id_2733 { ssum_dst_780.writeU32Le(id_2732) };
                              choose_res_2679 = id_2733;
                            }
                            let_res_2673 = choose_res_2679;
                          }
                          let_res_2668 = let_res_2673;
                        }
                        choose_res_2615 = let_res_2668;
                      } else {
                        uint16_t id_2734 { 8 };
                        bool id_2735 { bool(id_2734 == label1_744) };
                        Pointer choose_res_2736;
                        if (id_2735) {
                          uint16_t id_2737 { std::get<8>(p_0) };
                          Pointer id_2738 { ssum_dst_745.writeU16Le(id_2737) };
                          choose_res_2736 = id_2738;
                        } else {
                          uint16_t id_2739 { 9 };
                          bool id_2740 { bool(id_2739 == label1_744) };
                          Pointer choose_res_2741;
                          if (id_2740) {
                            std::optional<*sync_socket> id_2742 { std::get<9>(p_0) };
                            bool id_2743 { !(id_2742.has_value ()) };
                            Pointer choose_res_2744;
                            if (id_2743) {
                              uint8_t id_2745 { 1 };
                              Pointer id_2746 { ssum_dst_745.writeU8(id_2745) };
                              choose_res_2744 = id_2746;
                            } else {
                              std::function<Pointer(*sync_socket,Pointer)> id_2747 { dessser_gen::sync_socket.to_row_binary };
                              std::optional<*sync_socket> id_2748 { std::get<9>(p_0) };
                              *sync_socket id_2749 { id_2748.value() };
                              uint8_t id_2750 { 0 };
                              Pointer id_2751 { ssum_dst_745.writeU8(id_2750) };
                              Pointer id_2752 { id_2747(id_2749, id_2751) };
                              choose_res_2744 = id_2752;
                            }
                            choose_res_2741 = choose_res_2744;
                          } else {
                            uint16_t id_2753 { 10 };
                            bool id_2754 { bool(id_2753 == label1_744) };
                            Pointer choose_res_2755;
                            if (id_2754) {
                              choose_res_2755 = ssum_dst_745;
                            } else {
                              uint16_t id_2756 { 11 };
                              bool id_2757 { bool(id_2756 == label1_744) };
                              Pointer choose_res_2758;
                              if (id_2757) {
                                std::function<Pointer(*sync_socket,Pointer)> id_2759 { dessser_gen::sync_socket.to_row_binary };
                                v_287d43b770d826e060b1e65a4d07e0b0 id_2760 { std::get<11>(p_0) };
                                *sync_socket id_2761 { std::get<0>(id_2760) };
                                Pointer id_2762 { id_2759(id_2761, ssum_dst_745) };
                                Pointer let_res_2763;
                                {
                                  Pointer stup_dst_769 { id_2762 };
                                  v_287d43b770d826e060b1e65a4d07e0b0 id_2764 { std::get<11>(p_0) };
                                  v_90e4213e12fd850ebf8d15b08342b17e id_2765 { std::get<1>(id_2764) };
                                  uint16_t id_2766 { uint16_t(id_2765.index()) };
                                  Pointer id_2767 { stup_dst_769.writeU16Le(id_2766) };
                                  Pointer let_res_2768;
                                  {
                                    Pointer ssum_dst_771 { id_2767 };
                                    uint16_t id_2769 { 0 };
                                    v_287d43b770d826e060b1e65a4d07e0b0 id_2770 { std::get<11>(p_0) };
                                    v_90e4213e12fd850ebf8d15b08342b17e id_2771 { std::get<1>(id_2770) };
                                    uint16_t id_2772 { uint16_t(id_2771.index()) };
                                    bool id_2773 { bool(id_2769 == id_2772) };
                                    Pointer choose_res_2774;
                                    if (id_2773) {
                                      v_287d43b770d826e060b1e65a4d07e0b0 id_2775 { std::get<11>(p_0) };
                                      v_90e4213e12fd850ebf8d15b08342b17e id_2776 { std::get<1>(id_2775) };
                                      std::string id_2777 { std::get<0>(id_2776) };
                                      uint32_t id_2778 { (uint32_t)id_2777.size() };
                                      Vec<1, uint32_t> id_2779 {  id_2778  };
                                      Pointer let_res_2780;
                                      {
                                        Vec<1, uint32_t> leb128_sz_772 { id_2779 };
                                        Vec<1, Pointer> id_2781 {  ssum_dst_771  };
                                        Pointer let_res_2782;
                                        {
                                          Vec<1, Pointer> leb128_ptr_773 { id_2781 };
                                          bool while_flag_2783 { true };
                                          do {
                                            uint8_t id_2784 { 0 };
                                            uint8_t id_2785 { 0 };
                                            Pointer id_2786 { leb128_ptr_773[id_2785] };
                                            uint32_t id_2787 { 128U };
                                            uint8_t id_2788 { 0 };
                                            uint32_t id_2789 { leb128_sz_772[id_2788] };
                                            bool id_2790 { bool(id_2787 > id_2789) };
                                            uint8_t choose_res_2791;
                                            if (id_2790) {
                                              uint8_t id_2792 { 0 };
                                              uint32_t id_2793 { leb128_sz_772[id_2792] };
                                              uint8_t id_2794 { uint8_t(id_2793) };
                                              choose_res_2791 = id_2794;
                                            } else {
                                              uint8_t id_2795 { 0 };
                                              uint32_t id_2796 { leb128_sz_772[id_2795] };
                                              uint8_t id_2797 { uint8_t(id_2796) };
                                              uint8_t id_2798 { 128 };
                                              uint8_t id_2799 { uint8_t(id_2797 | id_2798) };
                                              choose_res_2791 = id_2799;
                                            }
                                            Pointer id_2800 { id_2786.writeU8(choose_res_2791) };
                                            Void id_2801 { ((void)(leb128_ptr_773[id_2784] = id_2800), VOID) };
                                            uint8_t id_2802 { 0 };
                                            uint8_t id_2803 { 0 };
                                            uint32_t id_2804 { leb128_sz_772[id_2803] };
                                            uint8_t id_2805 { 7 };
                                            uint32_t id_2806 { uint32_t(id_2804 >> id_2805) };
                                            Void id_2807 { ((void)(leb128_sz_772[id_2802] = id_2806), VOID) };
                                            uint8_t id_2808 { 0 };
                                            uint32_t id_2809 { leb128_sz_772[id_2808] };
                                            uint32_t id_2810 { 0U };
                                            bool id_2811 { bool(id_2809 > id_2810) };
                                            while_flag_2783 = id_2811;
                                            if (while_flag_2783) {
                                            }
                                          } while (while_flag_2783);
                                          uint8_t id_2812 { 0 };
                                          Pointer id_2813 { leb128_ptr_773[id_2812] };
                                          let_res_2782 = id_2813;
                                        }
                                        let_res_2780 = let_res_2782;
                                      }
                                      v_287d43b770d826e060b1e65a4d07e0b0 id_2814 { std::get<11>(p_0) };
                                      v_90e4213e12fd850ebf8d15b08342b17e id_2815 { std::get<1>(id_2814) };
                                      std::string id_2816 { std::get<0>(id_2815) };
                                      Bytes id_2817 { id_2816 };
                                      Pointer id_2818 { let_res_2780.writeBytes(id_2817) };
                                      choose_res_2774 = id_2818;
                                    } else {
                                      v_287d43b770d826e060b1e65a4d07e0b0 id_2819 { std::get<11>(p_0) };
                                      v_90e4213e12fd850ebf8d15b08342b17e id_2820 { std::get<1>(id_2819) };
                                      uint16_t id_2821 { uint16_t(id_2820.index()) };
                                      uint16_t id_2822 { 1 };
                                      bool id_2823 { bool(id_2821 == id_2822) };
                                      Void id_2824 { ((void)(assert(id_2823)), VOID) };
                                      v_287d43b770d826e060b1e65a4d07e0b0 id_2825 { std::get<11>(p_0) };
                                      v_90e4213e12fd850ebf8d15b08342b17e id_2826 { std::get<1>(id_2825) };
                                      v_808252496816a9c094ed1ddb199861d1 id_2827 { std::get<1>(id_2826) };
                                      Pointer id_2828 { per_dash_key_to_row_binary(id_2827, ssum_dst_771) };
                                      choose_res_2774 = id_2828;
                                    }
                                    let_res_2768 = choose_res_2774;
                                  }
                                  let_res_2763 = let_res_2768;
                                }
                                choose_res_2758 = let_res_2763;
                              } else {
                                uint16_t id_2829 { 12 };
                                bool id_2830 { bool(id_2829 == label1_744) };
                                Pointer choose_res_2831;
                                if (id_2830) {
                                  ea82132cbdaf05c9cc56869f7b4529c3 id_2832 { std::get<12>(p_0) };
                                  std::string id_2833 { std::get<0>(id_2832) };
                                  uint32_t id_2834 { (uint32_t)id_2833.size() };
                                  Vec<1, uint32_t> id_2835 {  id_2834  };
                                  Pointer let_res_2836;
                                  {
                                    Vec<1, uint32_t> leb128_sz_766 { id_2835 };
                                    Vec<1, Pointer> id_2837 {  ssum_dst_745  };
                                    Pointer let_res_2838;
                                    {
                                      Vec<1, Pointer> leb128_ptr_767 { id_2837 };
                                      bool while_flag_2839 { true };
                                      do {
                                        uint8_t id_2840 { 0 };
                                        uint8_t id_2841 { 0 };
                                        Pointer id_2842 { leb128_ptr_767[id_2841] };
                                        uint32_t id_2843 { 128U };
                                        uint8_t id_2844 { 0 };
                                        uint32_t id_2845 { leb128_sz_766[id_2844] };
                                        bool id_2846 { bool(id_2843 > id_2845) };
                                        uint8_t choose_res_2847;
                                        if (id_2846) {
                                          uint8_t id_2848 { 0 };
                                          uint32_t id_2849 { leb128_sz_766[id_2848] };
                                          uint8_t id_2850 { uint8_t(id_2849) };
                                          choose_res_2847 = id_2850;
                                        } else {
                                          uint8_t id_2851 { 0 };
                                          uint32_t id_2852 { leb128_sz_766[id_2851] };
                                          uint8_t id_2853 { uint8_t(id_2852) };
                                          uint8_t id_2854 { 128 };
                                          uint8_t id_2855 { uint8_t(id_2853 | id_2854) };
                                          choose_res_2847 = id_2855;
                                        }
                                        Pointer id_2856 { id_2842.writeU8(choose_res_2847) };
                                        Void id_2857 { ((void)(leb128_ptr_767[id_2840] = id_2856), VOID) };
                                        uint8_t id_2858 { 0 };
                                        uint8_t id_2859 { 0 };
                                        uint32_t id_2860 { leb128_sz_766[id_2859] };
                                        uint8_t id_2861 { 7 };
                                        uint32_t id_2862 { uint32_t(id_2860 >> id_2861) };
                                        Void id_2863 { ((void)(leb128_sz_766[id_2858] = id_2862), VOID) };
                                        uint8_t id_2864 { 0 };
                                        uint32_t id_2865 { leb128_sz_766[id_2864] };
                                        uint32_t id_2866 { 0U };
                                        bool id_2867 { bool(id_2865 > id_2866) };
                                        while_flag_2839 = id_2867;
                                        if (while_flag_2839) {
                                        }
                                      } while (while_flag_2839);
                                      uint8_t id_2868 { 0 };
                                      Pointer id_2869 { leb128_ptr_767[id_2868] };
                                      let_res_2838 = id_2869;
                                    }
                                    let_res_2836 = let_res_2838;
                                  }
                                  ea82132cbdaf05c9cc56869f7b4529c3 id_2870 { std::get<12>(p_0) };
                                  std::string id_2871 { std::get<0>(id_2870) };
                                  Bytes id_2872 { id_2871 };
                                  Pointer id_2873 { let_res_2836.writeBytes(id_2872) };
                                  Pointer let_res_2874;
                                  {
                                    Pointer stup_dst_768 { id_2873 };
                                    ea82132cbdaf05c9cc56869f7b4529c3 id_2875 { std::get<12>(p_0) };
                                    v_808252496816a9c094ed1ddb199861d1* id_2876 { std::get<1>(id_2875) };
                                    Pointer id_2877 { per_dash_key_to_row_binary(id_2876, stup_dst_768) };
                                    let_res_2874 = id_2877;
                                  }
                                  choose_res_2831 = let_res_2874;
                                } else {
                                  uint16_t id_2878 { 13 };
                                  bool id_2879 { bool(id_2878 == label1_744) };
                                  Pointer choose_res_2880;
                                  if (id_2879) {
                                    choose_res_2880 = ssum_dst_745;
                                  } else {
                                    uint16_t id_2881 { 14 };
                                    bool id_2882 { bool(id_2881 == label1_744) };
                                    Pointer choose_res_2883;
                                    if (id_2882) {
                                      v_3891539b8b788ad5d369dde272200753 id_2884 { std::get<14>(p_0) };
                                      std::string id_2885 { std::get<0>(id_2884) };
                                      uint32_t id_2886 { (uint32_t)id_2885.size() };
                                      Vec<1, uint32_t> id_2887 {  id_2886  };
                                      Pointer let_res_2888;
                                      {
                                        Vec<1, uint32_t> leb128_sz_757 { id_2887 };
                                        Vec<1, Pointer> id_2889 {  ssum_dst_745  };
                                        Pointer let_res_2890;
                                        {
                                          Vec<1, Pointer> leb128_ptr_758 { id_2889 };
                                          bool while_flag_2891 { true };
                                          do {
                                            uint8_t id_2892 { 0 };
                                            uint8_t id_2893 { 0 };
                                            Pointer id_2894 { leb128_ptr_758[id_2893] };
                                            uint32_t id_2895 { 128U };
                                            uint8_t id_2896 { 0 };
                                            uint32_t id_2897 { leb128_sz_757[id_2896] };
                                            bool id_2898 { bool(id_2895 > id_2897) };
                                            uint8_t choose_res_2899;
                                            if (id_2898) {
                                              uint8_t id_2900 { 0 };
                                              uint32_t id_2901 { leb128_sz_757[id_2900] };
                                              uint8_t id_2902 { uint8_t(id_2901) };
                                              choose_res_2899 = id_2902;
                                            } else {
                                              uint8_t id_2903 { 0 };
                                              uint32_t id_2904 { leb128_sz_757[id_2903] };
                                              uint8_t id_2905 { uint8_t(id_2904) };
                                              uint8_t id_2906 { 128 };
                                              uint8_t id_2907 { uint8_t(id_2905 | id_2906) };
                                              choose_res_2899 = id_2907;
                                            }
                                            Pointer id_2908 { id_2894.writeU8(choose_res_2899) };
                                            Void id_2909 { ((void)(leb128_ptr_758[id_2892] = id_2908), VOID) };
                                            uint8_t id_2910 { 0 };
                                            uint8_t id_2911 { 0 };
                                            uint32_t id_2912 { leb128_sz_757[id_2911] };
                                            uint8_t id_2913 { 7 };
                                            uint32_t id_2914 { uint32_t(id_2912 >> id_2913) };
                                            Void id_2915 { ((void)(leb128_sz_757[id_2910] = id_2914), VOID) };
                                            uint8_t id_2916 { 0 };
                                            uint32_t id_2917 { leb128_sz_757[id_2916] };
                                            uint32_t id_2918 { 0U };
                                            bool id_2919 { bool(id_2917 > id_2918) };
                                            while_flag_2891 = id_2919;
                                            if (while_flag_2891) {
                                            }
                                          } while (while_flag_2891);
                                          uint8_t id_2920 { 0 };
                                          Pointer id_2921 { leb128_ptr_758[id_2920] };
                                          let_res_2890 = id_2921;
                                        }
                                        let_res_2888 = let_res_2890;
                                      }
                                      v_3891539b8b788ad5d369dde272200753 id_2922 { std::get<14>(p_0) };
                                      std::string id_2923 { std::get<0>(id_2922) };
                                      Bytes id_2924 { id_2923 };
                                      Pointer id_2925 { let_res_2888.writeBytes(id_2924) };
                                      Pointer let_res_2926;
                                      {
                                        Pointer stup_dst_759 { id_2925 };
                                        v_3891539b8b788ad5d369dde272200753 id_2927 { std::get<14>(p_0) };
                                        v_04c2264c7cb6c602ff22f97c6ae3e620 id_2928 { std::get<1>(id_2927) };
                                        uint16_t id_2929 { uint16_t(id_2928.index()) };
                                        Pointer id_2930 { stup_dst_759.writeU16Le(id_2929) };
                                        Pointer let_res_2931;
                                        {
                                          Pointer ssum_dst_761 { id_2930 };
                                          uint16_t id_2932 { 0 };
                                          v_3891539b8b788ad5d369dde272200753 id_2933 { std::get<14>(p_0) };
                                          v_04c2264c7cb6c602ff22f97c6ae3e620 id_2934 { std::get<1>(id_2933) };
                                          uint16_t id_2935 { uint16_t(id_2934.index()) };
                                          bool id_2936 { bool(id_2932 == id_2935) };
                                          Pointer choose_res_2937;
                                          if (id_2936) {
                                            v_3891539b8b788ad5d369dde272200753 id_2938 { std::get<14>(p_0) };
                                            v_04c2264c7cb6c602ff22f97c6ae3e620 id_2939 { std::get<1>(id_2938) };
                                            std::string id_2940 { std::get<0>(id_2939) };
                                            uint32_t id_2941 { (uint32_t)id_2940.size() };
                                            Vec<1, uint32_t> id_2942 {  id_2941  };
                                            Pointer let_res_2943;
                                            {
                                              Vec<1, uint32_t> leb128_sz_764 { id_2942 };
                                              Vec<1, Pointer> id_2944 {  ssum_dst_761  };
                                              Pointer let_res_2945;
                                              {
                                                Vec<1, Pointer> leb128_ptr_765 { id_2944 };
                                                bool while_flag_2946 { true };
                                                do {
                                                  uint8_t id_2947 { 0 };
                                                  uint8_t id_2948 { 0 };
                                                  Pointer id_2949 { leb128_ptr_765[id_2948] };
                                                  uint32_t id_2950 { 128U };
                                                  uint8_t id_2951 { 0 };
                                                  uint32_t id_2952 { leb128_sz_764[id_2951] };
                                                  bool id_2953 { bool(id_2950 > id_2952) };
                                                  uint8_t choose_res_2954;
                                                  if (id_2953) {
                                                    uint8_t id_2955 { 0 };
                                                    uint32_t id_2956 { leb128_sz_764[id_2955] };
                                                    uint8_t id_2957 { uint8_t(id_2956) };
                                                    choose_res_2954 = id_2957;
                                                  } else {
                                                    uint8_t id_2958 { 0 };
                                                    uint32_t id_2959 { leb128_sz_764[id_2958] };
                                                    uint8_t id_2960 { uint8_t(id_2959) };
                                                    uint8_t id_2961 { 128 };
                                                    uint8_t id_2962 { uint8_t(id_2960 | id_2961) };
                                                    choose_res_2954 = id_2962;
                                                  }
                                                  Pointer id_2963 { id_2949.writeU8(choose_res_2954) };
                                                  Void id_2964 { ((void)(leb128_ptr_765[id_2947] = id_2963), VOID) };
                                                  uint8_t id_2965 { 0 };
                                                  uint8_t id_2966 { 0 };
                                                  uint32_t id_2967 { leb128_sz_764[id_2966] };
                                                  uint8_t id_2968 { 7 };
                                                  uint32_t id_2969 { uint32_t(id_2967 >> id_2968) };
                                                  Void id_2970 { ((void)(leb128_sz_764[id_2965] = id_2969), VOID) };
                                                  uint8_t id_2971 { 0 };
                                                  uint32_t id_2972 { leb128_sz_764[id_2971] };
                                                  uint32_t id_2973 { 0U };
                                                  bool id_2974 { bool(id_2972 > id_2973) };
                                                  while_flag_2946 = id_2974;
                                                  if (while_flag_2946) {
                                                  }
                                                } while (while_flag_2946);
                                                uint8_t id_2975 { 0 };
                                                Pointer id_2976 { leb128_ptr_765[id_2975] };
                                                let_res_2945 = id_2976;
                                              }
                                              let_res_2943 = let_res_2945;
                                            }
                                            v_3891539b8b788ad5d369dde272200753 id_2977 { std::get<14>(p_0) };
                                            v_04c2264c7cb6c602ff22f97c6ae3e620 id_2978 { std::get<1>(id_2977) };
                                            std::string id_2979 { std::get<0>(id_2978) };
                                            Bytes id_2980 { id_2979 };
                                            Pointer id_2981 { let_res_2943.writeBytes(id_2980) };
                                            choose_res_2937 = id_2981;
                                          } else {
                                            v_3891539b8b788ad5d369dde272200753 id_2982 { std::get<14>(p_0) };
                                            v_04c2264c7cb6c602ff22f97c6ae3e620 id_2983 { std::get<1>(id_2982) };
                                            uint16_t id_2984 { uint16_t(id_2983.index()) };
                                            uint16_t id_2985 { 1 };
                                            bool id_2986 { bool(id_2984 == id_2985) };
                                            Void id_2987 { ((void)(assert(id_2986)), VOID) };
                                            v_3891539b8b788ad5d369dde272200753 id_2988 { std::get<14>(p_0) };
                                            v_04c2264c7cb6c602ff22f97c6ae3e620 id_2989 { std::get<1>(id_2988) };
                                            std::string id_2990 { std::get<1>(id_2989) };
                                            uint32_t id_2991 { (uint32_t)id_2990.size() };
                                            Vec<1, uint32_t> id_2992 {  id_2991  };
                                            Pointer let_res_2993;
                                            {
                                              Vec<1, uint32_t> leb128_sz_762 { id_2992 };
                                              Vec<1, Pointer> id_2994 {  ssum_dst_761  };
                                              Pointer let_res_2995;
                                              {
                                                Vec<1, Pointer> leb128_ptr_763 { id_2994 };
                                                bool while_flag_2996 { true };
                                                do {
                                                  uint8_t id_2997 { 0 };
                                                  uint8_t id_2998 { 0 };
                                                  Pointer id_2999 { leb128_ptr_763[id_2998] };
                                                  uint32_t id_3000 { 128U };
                                                  uint8_t id_3001 { 0 };
                                                  uint32_t id_3002 { leb128_sz_762[id_3001] };
                                                  bool id_3003 { bool(id_3000 > id_3002) };
                                                  uint8_t choose_res_3004;
                                                  if (id_3003) {
                                                    uint8_t id_3005 { 0 };
                                                    uint32_t id_3006 { leb128_sz_762[id_3005] };
                                                    uint8_t id_3007 { uint8_t(id_3006) };
                                                    choose_res_3004 = id_3007;
                                                  } else {
                                                    uint8_t id_3008 { 0 };
                                                    uint32_t id_3009 { leb128_sz_762[id_3008] };
                                                    uint8_t id_3010 { uint8_t(id_3009) };
                                                    uint8_t id_3011 { 128 };
                                                    uint8_t id_3012 { uint8_t(id_3010 | id_3011) };
                                                    choose_res_3004 = id_3012;
                                                  }
                                                  Pointer id_3013 { id_2999.writeU8(choose_res_3004) };
                                                  Void id_3014 { ((void)(leb128_ptr_763[id_2997] = id_3013), VOID) };
                                                  uint8_t id_3015 { 0 };
                                                  uint8_t id_3016 { 0 };
                                                  uint32_t id_3017 { leb128_sz_762[id_3016] };
                                                  uint8_t id_3018 { 7 };
                                                  uint32_t id_3019 { uint32_t(id_3017 >> id_3018) };
                                                  Void id_3020 { ((void)(leb128_sz_762[id_3015] = id_3019), VOID) };
                                                  uint8_t id_3021 { 0 };
                                                  uint32_t id_3022 { leb128_sz_762[id_3021] };
                                                  uint32_t id_3023 { 0U };
                                                  bool id_3024 { bool(id_3022 > id_3023) };
                                                  while_flag_2996 = id_3024;
                                                  if (while_flag_2996) {
                                                  }
                                                } while (while_flag_2996);
                                                uint8_t id_3025 { 0 };
                                                Pointer id_3026 { leb128_ptr_763[id_3025] };
                                                let_res_2995 = id_3026;
                                              }
                                              let_res_2993 = let_res_2995;
                                            }
                                            v_3891539b8b788ad5d369dde272200753 id_3027 { std::get<14>(p_0) };
                                            v_04c2264c7cb6c602ff22f97c6ae3e620 id_3028 { std::get<1>(id_3027) };
                                            std::string id_3029 { std::get<1>(id_3028) };
                                            Bytes id_3030 { id_3029 };
                                            Pointer id_3031 { let_res_2993.writeBytes(id_3030) };
                                            choose_res_2937 = id_3031;
                                          }
                                          let_res_2931 = choose_res_2937;
                                        }
                                        let_res_2926 = let_res_2931;
                                      }
                                      choose_res_2883 = let_res_2926;
                                    } else {
                                      uint16_t id_3032 { 15 };
                                      bool id_3033 { bool(label1_744 == id_3032) };
                                      Void id_3034 { ((void)(assert(id_3033)), VOID) };
                                      ec4a56989018adc62b22d5f6798b0bc1 id_3035 { std::get<15>(p_0) };
                                      std::string id_3036 { std::get<0>(id_3035) };
                                      uint32_t id_3037 { (uint32_t)id_3036.size() };
                                      Vec<1, uint32_t> id_3038 {  id_3037  };
                                      Pointer let_res_3039;
                                      {
                                        Vec<1, uint32_t> leb128_sz_746 { id_3038 };
                                        Vec<1, Pointer> id_3040 {  ssum_dst_745  };
                                        Pointer let_res_3041;
                                        {
                                          Vec<1, Pointer> leb128_ptr_747 { id_3040 };
                                          bool while_flag_3042 { true };
                                          do {
                                            uint8_t id_3043 { 0 };
                                            uint8_t id_3044 { 0 };
                                            Pointer id_3045 { leb128_ptr_747[id_3044] };
                                            uint32_t id_3046 { 128U };
                                            uint8_t id_3047 { 0 };
                                            uint32_t id_3048 { leb128_sz_746[id_3047] };
                                            bool id_3049 { bool(id_3046 > id_3048) };
                                            uint8_t choose_res_3050;
                                            if (id_3049) {
                                              uint8_t id_3051 { 0 };
                                              uint32_t id_3052 { leb128_sz_746[id_3051] };
                                              uint8_t id_3053 { uint8_t(id_3052) };
                                              choose_res_3050 = id_3053;
                                            } else {
                                              uint8_t id_3054 { 0 };
                                              uint32_t id_3055 { leb128_sz_746[id_3054] };
                                              uint8_t id_3056 { uint8_t(id_3055) };
                                              uint8_t id_3057 { 128 };
                                              uint8_t id_3058 { uint8_t(id_3056 | id_3057) };
                                              choose_res_3050 = id_3058;
                                            }
                                            Pointer id_3059 { id_3045.writeU8(choose_res_3050) };
                                            Void id_3060 { ((void)(leb128_ptr_747[id_3043] = id_3059), VOID) };
                                            uint8_t id_3061 { 0 };
                                            uint8_t id_3062 { 0 };
                                            uint32_t id_3063 { leb128_sz_746[id_3062] };
                                            uint8_t id_3064 { 7 };
                                            uint32_t id_3065 { uint32_t(id_3063 >> id_3064) };
                                            Void id_3066 { ((void)(leb128_sz_746[id_3061] = id_3065), VOID) };
                                            uint8_t id_3067 { 0 };
                                            uint32_t id_3068 { leb128_sz_746[id_3067] };
                                            uint32_t id_3069 { 0U };
                                            bool id_3070 { bool(id_3068 > id_3069) };
                                            while_flag_3042 = id_3070;
                                            if (while_flag_3042) {
                                            }
                                          } while (while_flag_3042);
                                          uint8_t id_3071 { 0 };
                                          Pointer id_3072 { leb128_ptr_747[id_3071] };
                                          let_res_3041 = id_3072;
                                        }
                                        let_res_3039 = let_res_3041;
                                      }
                                      ec4a56989018adc62b22d5f6798b0bc1 id_3073 { std::get<15>(p_0) };
                                      std::string id_3074 { std::get<0>(id_3073) };
                                      Bytes id_3075 { id_3074 };
                                      Pointer id_3076 { let_res_3039.writeBytes(id_3075) };
                                      Pointer let_res_3077;
                                      {
                                        Pointer stup_dst_748 { id_3076 };
                                        ec4a56989018adc62b22d5f6798b0bc1 id_3078 { std::get<15>(p_0) };
                                        e6f820d94c0e3bb8eb0c04383ff72e06 id_3079 { std::get<1>(id_3078) };
                                        uint16_t id_3080 { uint16_t(id_3079.index()) };
                                        Pointer let_res_3081;
                                        {
                                          uint16_t label1_749 { id_3080 };
                                          Pointer id_3082 { stup_dst_748.writeU16Le(label1_749) };
                                          Pointer let_res_3083;
                                          {
                                            Pointer ssum_dst_750 { id_3082 };
                                            uint16_t id_3084 { 0 };
                                            bool id_3085 { bool(id_3084 == label1_749) };
                                            Pointer choose_res_3086;
                                            if (id_3085) {
                                              choose_res_3086 = ssum_dst_750;
                                            } else {
                                              uint16_t id_3087 { 1 };
                                              bool id_3088 { bool(id_3087 == label1_749) };
                                              Pointer choose_res_3089;
                                              if (id_3088) {
                                                choose_res_3089 = ssum_dst_750;
                                              } else {
                                                uint16_t id_3090 { 2 };
                                                bool id_3091 { bool(id_3090 == label1_749) };
                                                Pointer choose_res_3092;
                                                if (id_3091) {
                                                  choose_res_3092 = ssum_dst_750;
                                                } else {
                                                  uint16_t id_3093 { 3 };
                                                  bool id_3094 { bool(id_3093 == label1_749) };
                                                  Pointer choose_res_3095;
                                                  if (id_3094) {
                                                    choose_res_3095 = ssum_dst_750;
                                                  } else {
                                                    uint16_t id_3096 { 4 };
                                                    bool id_3097 { bool(id_3096 == label1_749) };
                                                    Pointer choose_res_3098;
                                                    if (id_3097) {
                                                      choose_res_3098 = ssum_dst_750;
                                                    } else {
                                                      uint16_t id_3099 { 5 };
                                                      bool id_3100 { bool(id_3099 == label1_749) };
                                                      Pointer choose_res_3101;
                                                      if (id_3100) {
                                                        ec4a56989018adc62b22d5f6798b0bc1 id_3102 { std::get<15>(p_0) };
                                                        e6f820d94c0e3bb8eb0c04383ff72e06 id_3103 { std::get<1>(id_3102) };
                                                        v_22ca22dbe40628ddd4edb314b5205ff3 id_3104 { std::get<5>(id_3103) };
                                                        std::string id_3105 { std::get<0>(id_3104) };
                                                        uint32_t id_3106 { (uint32_t)id_3105.size() };
                                                        Vec<1, uint32_t> id_3107 {  id_3106  };
                                                        Pointer let_res_3108;
                                                        {
                                                          Vec<1, uint32_t> leb128_sz_752 { id_3107 };
                                                          Vec<1, Pointer> id_3109 {  ssum_dst_750  };
                                                          Pointer let_res_3110;
                                                          {
                                                            Vec<1, Pointer> leb128_ptr_753 { id_3109 };
                                                            bool while_flag_3111 { true };
                                                            do {
                                                              uint8_t id_3112 { 0 };
                                                              uint8_t id_3113 { 0 };
                                                              Pointer id_3114 { leb128_ptr_753[id_3113] };
                                                              uint32_t id_3115 { 128U };
                                                              uint8_t id_3116 { 0 };
                                                              uint32_t id_3117 { leb128_sz_752[id_3116] };
                                                              bool id_3118 { bool(id_3115 > id_3117) };
                                                              uint8_t choose_res_3119;
                                                              if (id_3118) {
                                                                uint8_t id_3120 { 0 };
                                                                uint32_t id_3121 { leb128_sz_752[id_3120] };
                                                                uint8_t id_3122 { uint8_t(id_3121) };
                                                                choose_res_3119 = id_3122;
                                                              } else {
                                                                uint8_t id_3123 { 0 };
                                                                uint32_t id_3124 { leb128_sz_752[id_3123] };
                                                                uint8_t id_3125 { uint8_t(id_3124) };
                                                                uint8_t id_3126 { 128 };
                                                                uint8_t id_3127 { uint8_t(id_3125 | id_3126) };
                                                                choose_res_3119 = id_3127;
                                                              }
                                                              Pointer id_3128 { id_3114.writeU8(choose_res_3119) };
                                                              Void id_3129 { ((void)(leb128_ptr_753[id_3112] = id_3128), VOID) };
                                                              uint8_t id_3130 { 0 };
                                                              uint8_t id_3131 { 0 };
                                                              uint32_t id_3132 { leb128_sz_752[id_3131] };
                                                              uint8_t id_3133 { 7 };
                                                              uint32_t id_3134 { uint32_t(id_3132 >> id_3133) };
                                                              Void id_3135 { ((void)(leb128_sz_752[id_3130] = id_3134), VOID) };
                                                              uint8_t id_3136 { 0 };
                                                              uint32_t id_3137 { leb128_sz_752[id_3136] };
                                                              uint32_t id_3138 { 0U };
                                                              bool id_3139 { bool(id_3137 > id_3138) };
                                                              while_flag_3111 = id_3139;
                                                              if (while_flag_3111) {
                                                              }
                                                            } while (while_flag_3111);
                                                            uint8_t id_3140 { 0 };
                                                            Pointer id_3141 { leb128_ptr_753[id_3140] };
                                                            let_res_3110 = id_3141;
                                                          }
                                                          let_res_3108 = let_res_3110;
                                                        }
                                                        ec4a56989018adc62b22d5f6798b0bc1 id_3142 { std::get<15>(p_0) };
                                                        e6f820d94c0e3bb8eb0c04383ff72e06 id_3143 { std::get<1>(id_3142) };
                                                        v_22ca22dbe40628ddd4edb314b5205ff3 id_3144 { std::get<5>(id_3143) };
                                                        std::string id_3145 { std::get<0>(id_3144) };
                                                        Bytes id_3146 { id_3145 };
                                                        Pointer id_3147 { let_res_3108.writeBytes(id_3146) };
                                                        Pointer let_res_3148;
                                                        {
                                                          Pointer stup_dst_754 { id_3147 };
                                                          ec4a56989018adc62b22d5f6798b0bc1 id_3149 { std::get<15>(p_0) };
                                                          e6f820d94c0e3bb8eb0c04383ff72e06 id_3150 { std::get<1>(id_3149) };
                                                          v_22ca22dbe40628ddd4edb314b5205ff3 id_3151 { std::get<5>(id_3150) };
                                                          f27b577e1bb6a9c447e7eec975daa7e7 id_3152 { std::get<1>(id_3151) };
                                                          uint16_t id_3153 { uint16_t(id_3152.index()) };
                                                          Pointer let_res_3154;
                                                          {
                                                            uint16_t label1_755 { id_3153 };
                                                            Pointer id_3155 { stup_dst_754.writeU16Le(label1_755) };
                                                            Pointer let_res_3156;
                                                            {
                                                              Pointer ssum_dst_756 { id_3155 };
                                                              uint16_t id_3157 { 0 };
                                                              bool id_3158 { bool(id_3157 == label1_755) };
                                                              Pointer choose_res_3159;
                                                              if (id_3158) {
                                                                choose_res_3159 = ssum_dst_756;
                                                              } else {
                                                                uint16_t id_3160 { 1 };
                                                                bool id_3161 { bool(id_3160 == label1_755) };
                                                                Pointer choose_res_3162;
                                                                if (id_3161) {
                                                                  choose_res_3162 = ssum_dst_756;
                                                                } else {
                                                                  uint16_t id_3163 { 2 };
                                                                  bool id_3164 { bool(id_3163 == label1_755) };
                                                                  Pointer choose_res_3165;
                                                                  if (id_3164) {
                                                                    choose_res_3165 = ssum_dst_756;
                                                                  } else {
                                                                    uint16_t id_3166 { 3 };
                                                                    bool id_3167 { bool(id_3166 == label1_755) };
                                                                    Pointer choose_res_3168;
                                                                    if (id_3167) {
                                                                      choose_res_3168 = ssum_dst_756;
                                                                    } else {
                                                                      uint16_t id_3169 { 4 };
                                                                      bool id_3170 { bool(id_3169 == label1_755) };
                                                                      Pointer choose_res_3171;
                                                                      if (id_3170) {
                                                                        choose_res_3171 = ssum_dst_756;
                                                                      } else {
                                                                        uint16_t id_3172 { 5 };
                                                                        bool id_3173 { bool(id_3172 == label1_755) };
                                                                        Pointer choose_res_3174;
                                                                        if (id_3173) {
                                                                          choose_res_3174 = ssum_dst_756;
                                                                        } else {
                                                                          uint16_t id_3175 { 6 };
                                                                          bool id_3176 { bool(label1_755 == id_3175) };
                                                                          Void id_3177 { ((void)(assert(id_3176)), VOID) };
                                                                          choose_res_3174 = ssum_dst_756;
                                                                        }
                                                                        choose_res_3171 = choose_res_3174;
                                                                      }
                                                                      choose_res_3168 = choose_res_3171;
                                                                    }
                                                                    choose_res_3165 = choose_res_3168;
                                                                  }
                                                                  choose_res_3162 = choose_res_3165;
                                                                }
                                                                choose_res_3159 = choose_res_3162;
                                                              }
                                                              let_res_3156 = choose_res_3159;
                                                            }
                                                            let_res_3154 = let_res_3156;
                                                          }
                                                          let_res_3148 = let_res_3154;
                                                        }
                                                        choose_res_3101 = let_res_3148;
                                                      } else {
                                                        uint16_t id_3178 { 6 };
                                                        bool id_3179 { bool(label1_749 == id_3178) };
                                                        Void id_3180 { ((void)(assert(id_3179)), VOID) };
                                                        ec4a56989018adc62b22d5f6798b0bc1 id_3181 { std::get<15>(p_0) };
                                                        e6f820d94c0e3bb8eb0c04383ff72e06 id_3182 { std::get<1>(id_3181) };
                                                        a87b3e8210a10a34a7c2070f37f91a0a id_3183 { std::get<6>(id_3182) };
                                                        double id_3184 { std::get<0>(id_3183) };
                                                        uint64_t id_3185 { qword_of_float(id_3184) };
                                                        Pointer id_3186 { ssum_dst_750.writeU64Le(id_3185) };
                                                        Pointer let_res_3187;
                                                        {
                                                          Pointer stup_dst_751 { id_3186 };
                                                          ec4a56989018adc62b22d5f6798b0bc1 id_3188 { std::get<15>(p_0) };
                                                          e6f820d94c0e3bb8eb0c04383ff72e06 id_3189 { std::get<1>(id_3188) };
                                                          a87b3e8210a10a34a7c2070f37f91a0a id_3190 { std::get<6>(id_3189) };
                                                          uint32_t id_3191 { std::get<1>(id_3190) };
                                                          Pointer id_3192 { stup_dst_751.writeU32Le(id_3191) };
                                                          let_res_3187 = id_3192;
                                                        }
                                                        choose_res_3101 = let_res_3187;
                                                      }
                                                      choose_res_3098 = choose_res_3101;
                                                    }
                                                    choose_res_3095 = choose_res_3098;
                                                  }
                                                  choose_res_3092 = choose_res_3095;
                                                }
                                                choose_res_3089 = choose_res_3092;
                                              }
                                              choose_res_3086 = choose_res_3089;
                                            }
                                            let_res_3083 = choose_res_3086;
                                          }
                                          let_res_3081 = let_res_3083;
                                        }
                                        let_res_3077 = let_res_3081;
                                      }
                                      choose_res_2883 = let_res_3077;
                                    }
                                    choose_res_2880 = choose_res_2883;
                                  }
                                  choose_res_2831 = choose_res_2880;
                                }
                                choose_res_2758 = choose_res_2831;
                              }
                              choose_res_2755 = choose_res_2758;
                            }
                            choose_res_2741 = choose_res_2755;
                          }
                          choose_res_2736 = choose_res_2741;
                        }
                        choose_res_2615 = choose_res_2736;
                      }
                      choose_res_2551 = choose_res_2615;
                    }
                    choose_res_2249 = choose_res_2551;
                  }
                  choose_res_2246 = choose_res_2249;
                }
                choose_res_2196 = choose_res_2246;
              }
              choose_res_2153 = choose_res_2196;
            }
            choose_res_2150 = choose_res_2153;
          }
          choose_res_2147 = choose_res_2150;
        }
        let_res_2144 = choose_res_2147;
      }
      let_res_2142 = let_res_2144;
    }
    return let_res_2142;
  }
   };
  return fun2140;
}
std::function<Pointer(t,Pointer)> to_row_binary(to_row_binary_init());


}
