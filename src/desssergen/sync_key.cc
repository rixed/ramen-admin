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
#include "desssergen/team_name.h"
#include "desssergen/sync_socket.h"
#include "desssergen/sync_socket.h"
#include "desssergen/fq_name.h"
#include "desssergen/site_name.h"
#include "desssergen/fq_name.h"
#include "desssergen/site_name.h"
#include "desssergen/src_path.h"

namespace dessser::gen::sync_key {
using dessser::operator<<;

std::uniform_real_distribution<double> _random_float_(0, 1);
std::uniform_int_distribution<uint8_t> _random_u8_(0);
std::uniform_int_distribution<uint32_t> _random_u32_(0);
std::uniform_int_distribution<uint64_t> _random_u64_(0);
std::default_random_engine _random_engine_;

/* ------------ */
/* Declarations */
/* ------------ */
struct per_dash_key : public std::variant<
  uint32_t // Widgets
> { using variant::variant; };

struct per_client : public std::variant<
  std::string, // Response
  std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  // Scratchpad
> { using variant::variant; };

struct per_tail : public std::variant<
  std::string, // Subscriber
  uint32_t // LastTuple
> { using variant::variant; };

struct t3f2a416abcbd7d33d681d9d47445767b : public std::tuple<
  dessser::gen::src_path::t_ext,
  std::string
> {
  using tuple::tuple;
  t3f2a416abcbd7d33d681d9d47445767b(std::tuple<dessser::gen::src_path::t_ext, std::string> p)
    : std::tuple<dessser::gen::src_path::t_ext, std::string>(std::get<0>(p), std::get<1>(p)) {}
};
struct t32def300158106bfcc2bfd2015d1a3a9 : public std::variant<
  Void, // Host
  Void // Port
> { using variant::variant; };

struct t917a1ec3837bac9e10c931466c2b1db6 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9
> {
  using tuple::tuple;
  t917a1ec3837bac9e10c931466c2b1db6(std::tuple<std::string, ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9>(std::get<0>(p), std::get<1>(p)) {}
};
struct t082c1c733e68c2b9334f218f8c5aeccb : public std::variant<
  Void, // StateFile
  Void, // InputRingFile
  Void, // Pid
  Void, // LastKilled
  Void, // LastExit
  Void, // LastExitStatus
  Void, // SuccessiveFailures
  Void // QuarantineUntil
> { using variant::variant; };

struct t87de6a51e16e395e537230ef32d18a96 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb
> {
  using tuple::tuple;
  t87de6a51e16e395e537230ef32d18a96(std::tuple<std::string, ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb>(std::get<0>(p), std::get<1>(p)) {}
};
struct t4f653cc5cecafb6924f3d52da0caa392 : public std::variant<
  Void, // RuntimeStats
  Void, // ArchivedTimes
  Void, // NumArcFiles
  Void, // NumArcBytes
  Void, // AllocedArcBytes
  Void, // Worker
  ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96, // PerInstance
  uint32_t, // PerReplayer
  Void // OutputSpecs
> { using variant::variant; };

struct tb2139bc0252a099cc9e179b592108d12 : public std::tuple<
  dessser::gen::fq_name::t_ext,
  ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392
> {
  using tuple::tuple;
  tb2139bc0252a099cc9e179b592108d12(std::tuple<dessser::gen::fq_name::t_ext, ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392> p)
    : std::tuple<dessser::gen::fq_name::t_ext, ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392>(std::get<0>(p), std::get<1>(p)) {}
};
struct t73ec97d1f82a1880f5d2693e3a0558b1 : public std::variant<
  Void // Executable
> { using variant::variant; };

struct t1a2ea3d90b4ec20b73da76f490de4625 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1
> {
  using tuple::tuple;
  t1a2ea3d90b4ec20b73da76f490de4625(std::tuple<std::string, ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1>(std::get<0>(p), std::get<1>(p)) {}
};
struct t9030dc10bd527c50c2f835375dc4eb9d : public std::variant<
  Void, // IsMaster
  ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6, // PerService
  ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12, // PerWorker
  ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 // PerProgram
> { using variant::variant; };

struct t64d8d40f333c531e9d48c05b8ceb4cfa : public std::tuple<
  dessser::gen::site_name::t_ext,
  ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d
> {
  using tuple::tuple;
  t64d8d40f333c531e9d48c05b8ceb4cfa(std::tuple<dessser::gen::site_name::t_ext, ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d> p)
    : std::tuple<dessser::gen::site_name::t_ext, ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d>(std::get<0>(p), std::get<1>(p)) {}
};
struct t1fb80ba5a0eef0b970838ab3e8e6bce4 : public std::variant<
  Void, // TotalSize
  Void, // RecallCost
  std::string // RetentionsOverride
> { using variant::variant; };

struct te552b116666bdac4ad5a96694c71efca : public std::tuple<
  dessser::gen::site_name::t_ext,
  dessser::gen::fq_name::t_ext,
  std::string,
  std::shared_ptr<::dessser::gen::sync_key::per_tail> 
> {
  using tuple::tuple;
};
struct t4ce2d4679665698c8b564907b52837ef : public std::tuple<
  dessser::gen::sync_socket::t_ext,
  std::shared_ptr<::dessser::gen::sync_key::per_client> 
> {
  using tuple::tuple;
  t4ce2d4679665698c8b564907b52837ef(std::tuple<dessser::gen::sync_socket::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_client> > p)
    : std::tuple<dessser::gen::sync_socket::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_client> >(std::get<0>(p), std::get<1>(p)) {}
};
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct per_dash_key> const);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct tfac19990b99b6207810e41e57c01fbc1 : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::sync_key::per_dash_key> 
> {
  using tuple::tuple;
  tfac19990b99b6207810e41e57c01fbc1(std::tuple<std::string, std::shared_ptr<::dessser::gen::sync_key::per_dash_key> > p)
    : std::tuple<std::string, std::shared_ptr<::dessser::gen::sync_key::per_dash_key> >(std::get<0>(p), std::get<1>(p)) {}
};
struct t8bc7bba8a815a55f85ed48e95de5ac1f : public std::variant<
  std::string, // Contacts
  std::string // Inhibition
> { using variant::variant; };

struct t2ca7e384e93254d786048eef2705adff : public std::tuple<
  dessser::gen::team_name::t_ext,
  ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f
> {
  using tuple::tuple;
  t2ca7e384e93254d786048eef2705adff(std::tuple<dessser::gen::team_name::t_ext, ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f> p)
    : std::tuple<dessser::gen::team_name::t_ext, ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f>(std::get<0>(p), std::get<1>(p)) {}
};
struct t7cca840d7e40b13b976d995ba9f9fd5b : public std::variant<
  Void, // NumDeliveryAttempts
  Void, // FirstDeliveryAttempt
  Void, // LastDeliveryAttempt
  Void, // NextScheduled
  Void, // NextSend
  Void, // DeliveryStatus
  Void // Ack
> { using variant::variant; };

struct t5f10ae89970b1e8c27fc9f8df94fd836 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b
> {
  using tuple::tuple;
  t5f10ae89970b1e8c27fc9f8df94fd836(std::tuple<std::string, ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b>(std::get<0>(p), std::get<1>(p)) {}
};
struct t5f29f78957e3b1e9ec4688f50d1b6080 : public std::tuple<
  double,
  uint32_t
> {
  using tuple::tuple;
  t5f29f78957e3b1e9ec4688f50d1b6080(std::tuple<double, uint32_t> p)
    : std::tuple<double, uint32_t>(std::get<0>(p), std::get<1>(p)) {}
};
struct t0c4a58933d47075f04ed70f827130a86 : public std::variant<
  Void, // FirstStartNotif
  Void, // LastStartNotif
  Void, // LastStopNotif
  Void, // LastStateChangeNotif
  Void, // Team
  ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836, // Dialogs
  ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 // Journal
> { using variant::variant; };

struct t9ec4790c9e9e464ee01331cfcf67af68 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86
> {
  using tuple::tuple;
  t9ec4790c9e9e464ee01331cfcf67af68(std::tuple<std::string, ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86>(std::get<0>(p), std::get<1>(p)) {}
};
struct t : public std::variant<
  Void, // DevNull
  Void, // Time
  std::string, // Versions
  ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b, // Sources
  Void, // TargetConfig
  ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa, // PerSite
  ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4, // Storage
  ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca, // Tails
  uint16_t, // Replays
  std::optional<dessser::gen::sync_socket::t_ext>, // Error
  Void, // ReplayRequests
  ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef, // PerClient
  ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1, // Dashboards
  Void, // Notifications
  ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff, // Teams
  ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 // Incidents
> { using variant::variant; };

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct per_dash_key> const);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct t35aec9ecfaa6df3f20c35d464145bd4c : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,
  Pointer
> {
  using tuple::tuple;
  t35aec9ecfaa6df3f20c35d464145bd4c(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_dash_key> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_dash_key> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t7609d344c1ba69d0f80fec236d4c216b : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  t7609d344c1ba69d0f80fec236d4c216b(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t046563c971c0fcc6bcd022e88904aea9 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_client> ,
  Pointer
> {
  using tuple::tuple;
  t046563c971c0fcc6bcd022e88904aea9(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_client> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_client> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t1566bd611d8a2b90669c241f5e8d6ff1 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1566bd611d8a2b90669c241f5e8d6ff1(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t4521c7ac16d3ba391c05353ff307ec6d : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_tail> ,
  Pointer
> {
  using tuple::tuple;
  t4521c7ac16d3ba391c05353ff307ec6d(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_tail> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_tail> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct per_dash_key> const);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct t88648ce03c3e83f4daca25557f77454f : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::t> ,
  Pointer
> {
  using tuple::tuple;
  t88648ce03c3e83f4daca25557f77454f(std::tuple<std::shared_ptr<::dessser::gen::sync_key::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t6886b6ff042edb771f45016f12178bb0 : public std::tuple<
  dessser::gen::src_path::t_ext,
  Pointer
> {
  using tuple::tuple;
  t6886b6ff042edb771f45016f12178bb0(std::tuple<dessser::gen::src_path::t_ext, Pointer> p)
    : std::tuple<dessser::gen::src_path::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tff906bde0664efb2415be180e5a241ea : public std::tuple<
  dessser::gen::site_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tff906bde0664efb2415be180e5a241ea(std::tuple<dessser::gen::site_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::site_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t712586ec75786967434a0be4152a1e08 : public std::tuple<
  ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d,
  Pointer
> {
  using tuple::tuple;
  t712586ec75786967434a0be4152a1e08(std::tuple<::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t3fd8221434e489b54b5c4356ebff5005 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t3fd8221434e489b54b5c4356ebff5005(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t693b3c0b01440f82d6bb9ea682c4062e : public std::tuple<
  ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9,
  Pointer
> {
  using tuple::tuple;
  t693b3c0b01440f82d6bb9ea682c4062e(std::tuple<::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tcd6e38ac5ca8a381102d1fa6500e9b6e : public std::tuple<
  dessser::gen::fq_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tcd6e38ac5ca8a381102d1fa6500e9b6e(std::tuple<dessser::gen::fq_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tfad316798fa8ee621795cab2ef1d09e1 : public std::tuple<
  ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392,
  Pointer
> {
  using tuple::tuple;
  tfad316798fa8ee621795cab2ef1d09e1(std::tuple<::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t0d6c591ce3b3ba893d6d35f4657ef1da : public std::tuple<
  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb,
  Pointer
> {
  using tuple::tuple;
  t0d6c591ce3b3ba893d6d35f4657ef1da(std::tuple<::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t0e79e03631acd607acafe442d826717b : public std::tuple<
  ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4,
  Pointer
> {
  using tuple::tuple;
  t0e79e03631acd607acafe442d826717b(std::tuple<::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tdcc52da48df168277d8c161116b319a7 : public std::tuple<
  std::optional<dessser::gen::sync_socket::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tdcc52da48df168277d8c161116b319a7(std::tuple<std::optional<dessser::gen::sync_socket::t_ext>, Pointer> p)
    : std::tuple<std::optional<dessser::gen::sync_socket::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t8a365991c4a4591932e21c9e1eeeab20 : public std::tuple<
  dessser::gen::sync_socket::t_ext,
  Pointer
> {
  using tuple::tuple;
  t8a365991c4a4591932e21c9e1eeeab20(std::tuple<dessser::gen::sync_socket::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_socket::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t165bfb5c86a2d73d290e190e229b1fb1 : public std::tuple<
  dessser::gen::team_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t165bfb5c86a2d73d290e190e229b1fb1(std::tuple<dessser::gen::team_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::team_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t3a8843ea98675a135ad450a23aa2b2c8 : public std::tuple<
  ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f,
  Pointer
> {
  using tuple::tuple;
  t3a8843ea98675a135ad450a23aa2b2c8(std::tuple<::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t873cf1aed4c62babb18fe01068a9e2b0 : public std::tuple<
  ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86,
  Pointer
> {
  using tuple::tuple;
  t873cf1aed4c62babb18fe01068a9e2b0(std::tuple<::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct teb1e6c681b5c443ec217619fc46b4be9 : public std::tuple<
  ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b,
  Pointer
> {
  using tuple::tuple;
  teb1e6c681b5c443ec217619fc46b4be9(std::tuple<::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tf568409f41c9c0a265f7302110fc9084 : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  tf568409f41c9c0a265f7302110fc9084(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t5375de390f9cb5ae2ee5880ea1674828 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t5375de390f9cb5ae2ee5880ea1674828(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Widgets U32]" "Ptr")
      (let "ssum_dst_738" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (write-u32 little-endian (identifier "ssum_dst_738") (get-alt "Widgets" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> per_dash_key_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_738 { id_2 };
      uint16_t id_4 { uint16_t((*p_0).index()) };
      uint16_t id_5 { 0 };
      bool id_6 { bool(id_4 == id_5) };
      Void id_7 { ((void)(assert(id_6)), VOID) };
      (void)id_7;
      uint32_t id_8 { std::get<0 /* Widgets */>((*p_0)) };
      Pointer id_9 { ssum_dst_738.writeU32Le(id_8) };
      let_res_3 = id_9;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> per_dash_key_to_row_binary(per_dash_key_to_row_binary_init());

/* 
    (fun ("[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" "Ptr")
      (let "ssum_dst_740" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_741" (make-vec (string-length (get-alt "Response" (param 0))))
              (let "leb128_ptr_742" (make-vec (identifier "ssum_dst_740"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_742")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_742"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_741"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_741"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_741"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_741") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_741")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_741")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_742"))))) 
            (bytes-of-string (get-alt "Response" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "per_dash_key-to-row-binary") (get-alt "Scratchpad" (param 0)) (identifier "ssum_dst_740"))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> per_client_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> fun10 { [&fun10](std::shared_ptr<::dessser::gen::sync_key::per_client>  p_0, Pointer p_1) {
    uint16_t id_11 { uint16_t((*p_0).index()) };
    Pointer id_12 { p_1.writeU16Le(id_11) };
    Pointer let_res_13;
    {
      Pointer ssum_dst_740 { id_12 };
      uint16_t id_14 { 0 };
      uint16_t id_15 { uint16_t((*p_0).index()) };
      bool id_16 { bool(id_14 == id_15) };
      Pointer choose_res_17;
      if (id_16) {
        std::string id_18 { std::get<0 /* Response */>((*p_0)) };
        uint32_t id_19 { (uint32_t)id_18.size() };
        Vec<1, uint32_t> id_20 {  id_19  };
        Pointer let_res_21;
        {
          Vec<1, uint32_t> leb128_sz_741 { id_20 };
          Vec<1, Pointer> id_22 {  ssum_dst_740  };
          Pointer let_res_23;
          {
            Vec<1, Pointer> leb128_ptr_742 { id_22 };
            bool while_flag_24 { true };
            do {
              uint8_t id_25 { 0 };
              uint8_t id_26 { 0 };
              Pointer id_27 { leb128_ptr_742[id_26] };
              uint32_t id_28 { 128U };
              uint8_t id_29 { 0 };
              uint32_t id_30 { leb128_sz_741[id_29] };
              bool id_31 { bool(id_28 > id_30) };
              uint8_t choose_res_32;
              if (id_31) {
                uint8_t id_33 { 0 };
                uint32_t id_34 { leb128_sz_741[id_33] };
                uint8_t id_35 { uint8_t(id_34) };
                choose_res_32 = id_35;
              } else {
                uint8_t id_36 { 0 };
                uint32_t id_37 { leb128_sz_741[id_36] };
                uint8_t id_38 { uint8_t(id_37) };
                uint8_t id_39 { 128 };
                uint8_t id_40 { uint8_t(id_38 | id_39) };
                choose_res_32 = id_40;
              }
              Pointer id_41 { id_27.writeU8(choose_res_32) };
              Void id_42 { ((void)(leb128_ptr_742[id_25] = id_41), VOID) };
              (void)id_42;
              uint8_t id_43 { 0 };
              uint8_t id_44 { 0 };
              uint32_t id_45 { leb128_sz_741[id_44] };
              uint8_t id_46 { 7 };
              uint32_t id_47 { uint32_t(id_45 >> id_46) };
              Void id_48 { ((void)(leb128_sz_741[id_43] = id_47), VOID) };
              (void)id_48;
              uint8_t id_49 { 0 };
              uint32_t id_50 { leb128_sz_741[id_49] };
              uint32_t id_51 { 0U };
              bool id_52 { bool(id_50 > id_51) };
              while_flag_24 = id_52;
              if (while_flag_24) {
                (void)VOID;
              }
            } while (while_flag_24);
            (void)VOID;
            uint8_t id_53 { 0 };
            Pointer id_54 { leb128_ptr_742[id_53] };
            let_res_23 = id_54;
          }
          let_res_21 = let_res_23;
        }
        std::string id_55 { std::get<0 /* Response */>((*p_0)) };
        Bytes id_56 { id_55 };
        Pointer id_57 { let_res_21.writeBytes(id_56) };
        choose_res_17 = id_57;
      } else {
        uint16_t id_58 { uint16_t((*p_0).index()) };
        uint16_t id_59 { 1 };
        bool id_60 { bool(id_58 == id_59) };
        Void id_61 { ((void)(assert(id_60)), VOID) };
        (void)id_61;
        std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_62 { std::get<1 /* Scratchpad */>((*p_0)) };
        Pointer id_63 { per_dash_key_to_row_binary(id_62, ssum_dst_740) };
        choose_res_17 = id_63;
      }
      let_res_13 = choose_res_17;
    }
    return let_res_13;
  }
   };
  return fun10;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> per_client_to_row_binary(per_client_to_row_binary_init());

/* 
    (fun ("[Subscriber STRING | LastTuple U32]" "Ptr")
      (let "ssum_dst_734" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_735" (make-vec (string-length (get-alt "Subscriber" (param 0))))
              (let "leb128_ptr_736" (make-vec (identifier "ssum_dst_734"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_736")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_736"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_735"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_735"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_735"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_735") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_735")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_735")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_736"))))) 
            (bytes-of-string (get-alt "Subscriber" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (write-u32 little-endian (identifier "ssum_dst_734") (get-alt "LastTuple" (param 0)))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> per_tail_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> fun64 { [&fun64](std::shared_ptr<::dessser::gen::sync_key::per_tail>  p_0, Pointer p_1) {
    uint16_t id_65 { uint16_t((*p_0).index()) };
    Pointer id_66 { p_1.writeU16Le(id_65) };
    Pointer let_res_67;
    {
      Pointer ssum_dst_734 { id_66 };
      uint16_t id_68 { 0 };
      uint16_t id_69 { uint16_t((*p_0).index()) };
      bool id_70 { bool(id_68 == id_69) };
      Pointer choose_res_71;
      if (id_70) {
        std::string id_72 { std::get<0 /* Subscriber */>((*p_0)) };
        uint32_t id_73 { (uint32_t)id_72.size() };
        Vec<1, uint32_t> id_74 {  id_73  };
        Pointer let_res_75;
        {
          Vec<1, uint32_t> leb128_sz_735 { id_74 };
          Vec<1, Pointer> id_76 {  ssum_dst_734  };
          Pointer let_res_77;
          {
            Vec<1, Pointer> leb128_ptr_736 { id_76 };
            bool while_flag_78 { true };
            do {
              uint8_t id_79 { 0 };
              uint8_t id_80 { 0 };
              Pointer id_81 { leb128_ptr_736[id_80] };
              uint32_t id_82 { 128U };
              uint8_t id_83 { 0 };
              uint32_t id_84 { leb128_sz_735[id_83] };
              bool id_85 { bool(id_82 > id_84) };
              uint8_t choose_res_86;
              if (id_85) {
                uint8_t id_87 { 0 };
                uint32_t id_88 { leb128_sz_735[id_87] };
                uint8_t id_89 { uint8_t(id_88) };
                choose_res_86 = id_89;
              } else {
                uint8_t id_90 { 0 };
                uint32_t id_91 { leb128_sz_735[id_90] };
                uint8_t id_92 { uint8_t(id_91) };
                uint8_t id_93 { 128 };
                uint8_t id_94 { uint8_t(id_92 | id_93) };
                choose_res_86 = id_94;
              }
              Pointer id_95 { id_81.writeU8(choose_res_86) };
              Void id_96 { ((void)(leb128_ptr_736[id_79] = id_95), VOID) };
              (void)id_96;
              uint8_t id_97 { 0 };
              uint8_t id_98 { 0 };
              uint32_t id_99 { leb128_sz_735[id_98] };
              uint8_t id_100 { 7 };
              uint32_t id_101 { uint32_t(id_99 >> id_100) };
              Void id_102 { ((void)(leb128_sz_735[id_97] = id_101), VOID) };
              (void)id_102;
              uint8_t id_103 { 0 };
              uint32_t id_104 { leb128_sz_735[id_103] };
              uint32_t id_105 { 0U };
              bool id_106 { bool(id_104 > id_105) };
              while_flag_78 = id_106;
              if (while_flag_78) {
                (void)VOID;
              }
            } while (while_flag_78);
            (void)VOID;
            uint8_t id_107 { 0 };
            Pointer id_108 { leb128_ptr_736[id_107] };
            let_res_77 = id_108;
          }
          let_res_75 = let_res_77;
        }
        std::string id_109 { std::get<0 /* Subscriber */>((*p_0)) };
        Bytes id_110 { id_109 };
        Pointer id_111 { let_res_75.writeBytes(id_110) };
        choose_res_71 = id_111;
      } else {
        uint16_t id_112 { uint16_t((*p_0).index()) };
        uint16_t id_113 { 1 };
        bool id_114 { bool(id_112 == id_113) };
        Void id_115 { ((void)(assert(id_114)), VOID) };
        (void)id_115;
        uint32_t id_116 { std::get<1 /* LastTuple */>((*p_0)) };
        Pointer id_117 { ssum_dst_734.writeU32Le(id_116) };
        choose_res_71 = id_117;
      }
      let_res_67 = choose_res_71;
    }
    return let_res_67;
  }
   };
  return fun64;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> per_tail_to_row_binary(per_tail_to_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" "Ptr")
      (let "label1_743" (label-of (param 0))
        (let "ssum_dst_744" (write-u16 little-endian (param 1) (identifier "label1_743"))
          (if (eq (u16 0) (identifier "label1_743")) (identifier "ssum_dst_744")
            (if (eq (u16 1) (identifier "label1_743")) (identifier "ssum_dst_744")
              (if (eq (u16 2) (identifier "label1_743"))
                (write-bytes
                  (let "leb128_sz_800" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "leb128_ptr_801" (make-vec (identifier "ssum_dst_744"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_801")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_801"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_800"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_800"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_800"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_800") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_800")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_800")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_801"))))) 
                  (bytes-of-string (get-alt "Versions" (param 0))))
                (if (eq (u16 3) (identifier "label1_743"))
                  (let "stup_dst_797" (apply (ext-identifier src_path to-row-binary) (get-item 0 (get-alt "Sources" (param 0))) (identifier "ssum_dst_744"))
                    (write-bytes
                      (let "leb128_sz_798" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "leb128_ptr_799" (make-vec (identifier "stup_dst_797"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_799")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_799"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_798"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_798"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_798"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_798") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_798")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_798")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_799"))))) 
                      (bytes-of-string (get-item 1 (get-alt "Sources" (param 0))))))
                  (if (eq (u16 4) (identifier "label1_743")) (identifier "ssum_dst_744")
                    (if (eq (u16 5) (identifier "label1_743"))
                      (let "stup_dst_776" (apply (ext-identifier site_name to-row-binary) (get-item 0 (get-alt "PerSite" (param 0))) (identifier "ssum_dst_744"))
                        (let "ssum_dst_778" (write-u16 little-endian (identifier "stup_dst_776") (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                          (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerSite" (param 0))))) 
                            (identifier "ssum_dst_778")
                            (if (eq (u16 1) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                              (let "stup_dst_794"
                                (write-bytes
                                  (let "leb128_sz_792" (make-vec (string-length (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                    (let "leb128_ptr_793" (make-vec (identifier "ssum_dst_778"))
                                      (seq
                                        (while
                                          (seq
                                            (set-vec (u8 0) (identifier "leb128_ptr_793")
                                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_793"))
                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_792"))) 
                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_792"))) 
                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_792"))) (u8 128)))))
                                            (set-vec (u8 0) (identifier "leb128_sz_792") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_792")) (u8 7))) 
                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_792")) (u32 0))) 
                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_793"))))) 
                                  (bytes-of-string (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                (let "ssum_dst_796" (write-u16 little-endian (identifier "stup_dst_794") (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                  (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0))))))) 
                                    (identifier "ssum_dst_796") (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 1))) (identifier "ssum_dst_796")))))
                              (if (eq (u16 2) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                                (let "stup_dst_784" (apply (ext-identifier fq_name to-row-binary) (get-item 0 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))) (identifier "ssum_dst_778"))
                                  (let "label1_785" (label-of (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))
                                    (let "ssum_dst_786" (write-u16 little-endian (identifier "stup_dst_784") (identifier "label1_785"))
                                      (if (eq (u16 0) (identifier "label1_785")) 
                                        (identifier "ssum_dst_786")
                                        (if (eq (u16 1) (identifier "label1_785")) 
                                          (identifier "ssum_dst_786")
                                          (if (eq (u16 2) (identifier "label1_785")) 
                                            (identifier "ssum_dst_786")
                                            (if (eq (u16 3) (identifier "label1_785")) 
                                              (identifier "ssum_dst_786")
                                              (if (eq (u16 4) (identifier "label1_785")) 
                                                (identifier "ssum_dst_786")
                                                (if (eq (u16 5) (identifier "label1_785")) 
                                                  (identifier "ssum_dst_786")
                                                  (if (eq (u16 6) (identifier "label1_785"))
                                                    (let "stup_dst_789"
                                                      (write-bytes
                                                        (let "leb128_sz_787" 
                                                          (make-vec (string-length (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                                          (let "leb128_ptr_788" 
                                                            (make-vec (identifier "ssum_dst_786"))
                                                            (seq
                                                              (while
                                                                (seq
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_788")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_788"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_787"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_787"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_787"))) (u8 128)))))
                                                                  (set-vec (u8 0) (identifier "leb128_sz_787") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_787")) (u8 7)))
                                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_787")) (u32 0))) 
                                                                (nop)) 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_788")))))
                                                        (bytes-of-string (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                                      (let "label1_790" 
                                                        (label-of (get-item 1 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))))
                                                        (let "ssum_dst_791" 
                                                          (write-u16 little-endian (identifier "stup_dst_789") (identifier "label1_790"))
                                                          (if (eq (u16 0) (identifier "label1_790")) 
                                                            (identifier "ssum_dst_791")
                                                            (if (eq (u16 1) (identifier "label1_790")) 
                                                              (identifier "ssum_dst_791")
                                                              (if (eq (u16 2) (identifier "label1_790")) 
                                                                (identifier "ssum_dst_791")
                                                                (if (eq (u16 3) (identifier "label1_790")) 
                                                                  (identifier "ssum_dst_791")
                                                                  (if 
                                                                    (eq (u16 4) (identifier "label1_790")) 
                                                                    (identifier "ssum_dst_791")
                                                                    (if 
                                                                    (eq (u16 5) (identifier "label1_790")) 
                                                                    (identifier "ssum_dst_791")
                                                                    (if (eq (u16 6) (identifier "label1_790")) (identifier "ssum_dst_791") (seq (assert (eq (identifier "label1_790") (u16 7))) (identifier "ssum_dst_791"))))))))))))
                                                    (if (eq (u16 7) (identifier "label1_785"))
                                                      (write-u32 little-endian (identifier "ssum_dst_786") (get-alt "PerReplayer" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                                      (seq (assert (eq (identifier "label1_785") (u16 8))) (identifier "ssum_dst_786")))))))))))))
                                (seq (assert (eq (label-of (get-item 1 (get-alt "PerSite" (param 0)))) (u16 3)))
                                  (let "stup_dst_781"
                                    (write-bytes
                                      (let "leb128_sz_779" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                        (let "leb128_ptr_780" (make-vec (identifier "ssum_dst_778"))
                                          (seq
                                            (while
                                              (seq
                                                (set-vec (u8 0) (identifier "leb128_ptr_780")
                                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_780"))
                                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_779"))) 
                                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_779"))) 
                                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_779"))) (u8 128)))))
                                                (set-vec (u8 0) (identifier "leb128_sz_779") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_779")) (u8 7))) 
                                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_779")) (u32 0))) 
                                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_780"))))) 
                                      (bytes-of-string (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                    (let "ssum_dst_783" (write-u16 little-endian (identifier "stup_dst_781") (label-of (get-item 1 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                      (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 0))) (identifier "ssum_dst_783"))))))))))
                      (if (eq (u16 6) (identifier "label1_743"))
                        (let "ssum_dst_773" (write-u16 little-endian (identifier "ssum_dst_744") (label-of (get-alt "Storage" (param 0))))
                          (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                            (identifier "ssum_dst_773")
                            (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                              (identifier "ssum_dst_773")
                              (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                                (write-bytes
                                  (let "leb128_sz_774" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                    (let "leb128_ptr_775" (make-vec (identifier "ssum_dst_773"))
                                      (seq
                                        (while
                                          (seq
                                            (set-vec (u8 0) (identifier "leb128_ptr_775")
                                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_775"))
                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_774"))) 
                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_774"))) 
                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_774"))) (u8 128)))))
                                            (set-vec (u8 0) (identifier "leb128_sz_774") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_774")) (u8 7))) 
                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_774")) (u32 0))) 
                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_775"))))) 
                                  (bytes-of-string (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))))))
                        (if (eq (u16 7) (identifier "label1_743"))
                          (let "stup_dst_771"
                            (let "stup_dst_768"
                              (let "stup_dst_767" (apply (ext-identifier site_name to-row-binary) (get-item 0 (get-alt "Tails" (param 0))) (identifier "ssum_dst_744"))
                                (apply (ext-identifier fq_name to-row-binary) (get-item 1 (get-alt "Tails" (param 0))) (identifier "stup_dst_767")))
                              (write-bytes
                                (let "leb128_sz_769" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "leb128_ptr_770" (make-vec (identifier "stup_dst_768"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_770")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_770"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_769"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_769"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_769"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_769") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_769")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_769")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_770"))))) 
                                (bytes-of-string (get-item 2 (get-alt "Tails" (param 0)))))) 
                            (apply (identifier "per_tail-to-row-binary") (get-item 3 (get-alt "Tails" (param 0))) (identifier "stup_dst_771")))
                          (if (eq (u16 8) (identifier "label1_743")) 
                            (write-u16 little-endian (identifier "ssum_dst_744") (get-alt "Replays" (param 0)))
                            (if (eq (u16 9) (identifier "label1_743"))
                              (if (is-null (get-alt "Error" (param 0))) 
                                (write-u8 (identifier "ssum_dst_744") (u8 1)) 
                                (apply (ext-identifier sync_socket to-row-binary) (force (get-alt "Error" (param 0))) (write-u8 (identifier "ssum_dst_744") (u8 0))))
                              (if (eq (u16 10) (identifier "label1_743")) 
                                (identifier "ssum_dst_744")
                                (if (eq (u16 11) (identifier "label1_743"))
                                  (let "stup_dst_766" (apply (ext-identifier sync_socket to-row-binary) (get-item 0 (get-alt "PerClient" (param 0))) (identifier "ssum_dst_744"))
                                    (apply (identifier "per_client-to-row-binary") (get-item 1 (get-alt "PerClient" (param 0))) (identifier "stup_dst_766")))
                                  (if (eq (u16 12) (identifier "label1_743"))
                                    (let "stup_dst_765"
                                      (write-bytes
                                        (let "leb128_sz_763" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "leb128_ptr_764" (make-vec (identifier "ssum_dst_744"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_764")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_764"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_763"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_763"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_763"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_763") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_763")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_763")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_764"))))) 
                                        (bytes-of-string (get-item 0 (get-alt "Dashboards" (param 0))))) 
                                      (apply (identifier "per_dash_key-to-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))) (identifier "stup_dst_765")))
                                    (if (eq (u16 13) (identifier "label1_743")) 
                                      (identifier "ssum_dst_744")
                                      (if (eq (u16 14) (identifier "label1_743"))
                                        (let "stup_dst_756" (apply (ext-identifier team_name to-row-binary) (get-item 0 (get-alt "Teams" (param 0))) (identifier "ssum_dst_744"))
                                          (let "ssum_dst_758" (write-u16 little-endian (identifier "stup_dst_756") (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                            (if (eq (u16 0) (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                              (write-bytes
                                                (let "leb128_sz_761" 
                                                  (make-vec (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                                  (let "leb128_ptr_762" 
                                                    (make-vec (identifier "ssum_dst_758"))
                                                    (seq
                                                      (while
                                                        (seq
                                                          (set-vec (u8 0) 
                                                            (identifier "leb128_ptr_762")
                                                            (write-u8 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_762"))
                                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_761"))) 
                                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_761"))) 
                                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_761"))) (u8 128)))))
                                                          (set-vec (u8 0) (identifier "leb128_sz_761") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_761")) (u8 7)))
                                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_761")) (u32 0))) 
                                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_762"))))) 
                                                (bytes-of-string (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                              (seq (assert (eq (label-of (get-item 1 (get-alt "Teams" (param 0)))) (u16 1)))
                                                (write-bytes
                                                  (let "leb128_sz_759" 
                                                    (make-vec (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))
                                                    (let "leb128_ptr_760" 
                                                      (make-vec (identifier "ssum_dst_758"))
                                                      (seq
                                                        (while
                                                          (seq
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb128_ptr_760")
                                                              (write-u8 
                                                                (unsafe-nth (u8 0) (identifier "leb128_ptr_760"))
                                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_759"))) 
                                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_759"))) 
                                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_759"))) (u8 128)))))
                                                            (set-vec (u8 0) (identifier "leb128_sz_759") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_759")) (u8 7)))
                                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_759")) (u32 0))) 
                                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_760"))))) 
                                                  (bytes-of-string (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))))))
                                        (seq (assert (eq (identifier "label1_743") (u16 15)))
                                          (let "stup_dst_747"
                                            (write-bytes
                                              (let "leb128_sz_745" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "leb128_ptr_746" 
                                                  (make-vec (identifier "ssum_dst_744"))
                                                  (seq
                                                    (while
                                                      (seq
                                                        (set-vec (u8 0) 
                                                          (identifier "leb128_ptr_746")
                                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_746"))
                                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_745"))) 
                                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_745"))) 
                                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_745"))) (u8 128)))))
                                                        (set-vec (u8 0) (identifier "leb128_sz_745") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_745")) (u8 7)))
                                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_745")) (u32 0))) 
                                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_746"))))) 
                                              (bytes-of-string (get-item 0 (get-alt "Incidents" (param 0)))))
                                            (let "label1_748" (label-of (get-item 1 (get-alt "Incidents" (param 0))))
                                              (let "ssum_dst_749" (write-u16 little-endian (identifier "stup_dst_747") (identifier "label1_748"))
                                                (if (eq (u16 0) (identifier "label1_748")) 
                                                  (identifier "ssum_dst_749")
                                                  (if (eq (u16 1) (identifier "label1_748")) 
                                                    (identifier "ssum_dst_749")
                                                    (if (eq (u16 2) (identifier "label1_748")) 
                                                      (identifier "ssum_dst_749")
                                                      (if (eq (u16 3) (identifier "label1_748")) 
                                                        (identifier "ssum_dst_749")
                                                        (if (eq (u16 4) (identifier "label1_748")) 
                                                          (identifier "ssum_dst_749")
                                                          (if (eq (u16 5) (identifier "label1_748"))
                                                            (let "stup_dst_753"
                                                              (write-bytes
                                                                (let "leb128_sz_751" 
                                                                  (make-vec (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                  (let "leb128_ptr_752" 
                                                                    (make-vec (identifier "ssum_dst_749"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_752")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_752"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_751"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_751"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_751"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_751") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_751")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_751")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_752"))))) 
                                                                (bytes-of-string (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                              (let "label1_754" 
                                                                (label-of (get-item 1 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0))))))
                                                                (let "ssum_dst_755" 
                                                                  (write-u16 little-endian (identifier "stup_dst_753") (identifier "label1_754"))
                                                                  (if 
                                                                    (eq (u16 0) (identifier "label1_754")) 
                                                                    (identifier "ssum_dst_755")
                                                                    (if 
                                                                    (eq (u16 1) (identifier "label1_754")) 
                                                                    (identifier "ssum_dst_755")
                                                                    (if 
                                                                    (eq (u16 2) (identifier "label1_754")) 
                                                                    (identifier "ssum_dst_755")
                                                                    (if 
                                                                    (eq (u16 3) (identifier "label1_754")) 
                                                                    (identifier "ssum_dst_755")
                                                                    (if 
                                                                    (eq (u16 4) (identifier "label1_754")) 
                                                                    (identifier "ssum_dst_755")
                                                                    (if (eq (u16 5) (identifier "label1_754")) (identifier "ssum_dst_755") (seq (assert (eq (identifier "label1_754") (u16 6))) (identifier "ssum_dst_755")))))))))))
                                                            (seq (assert (eq (identifier "label1_748") (u16 6)))
                                                              (let "stup_dst_750" 
                                                                (write-u64 little-endian (identifier "ssum_dst_749") (u64-of-float (get-item 0 (get-alt "Journal" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                (write-u32 little-endian (identifier "stup_dst_750") (get-item 1 (get-alt "Journal" (get-item 1 (get-alt "Incidents" (param 0))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> fun118 { [&fun118](std::shared_ptr<::dessser::gen::sync_key::t>  p_0, Pointer p_1) {
    uint16_t id_119 { uint16_t((*p_0).index()) };
    Pointer let_res_120;
    {
      uint16_t label1_743 { id_119 };
      Pointer id_121 { p_1.writeU16Le(label1_743) };
      Pointer let_res_122;
      {
        Pointer ssum_dst_744 { id_121 };
        uint16_t id_123 { 0 };
        bool id_124 { bool(id_123 == label1_743) };
        Pointer choose_res_125;
        if (id_124) {
          choose_res_125 = ssum_dst_744;
        } else {
          uint16_t id_126 { 1 };
          bool id_127 { bool(id_126 == label1_743) };
          Pointer choose_res_128;
          if (id_127) {
            choose_res_128 = ssum_dst_744;
          } else {
            uint16_t id_129 { 2 };
            bool id_130 { bool(id_129 == label1_743) };
            Pointer choose_res_131;
            if (id_130) {
              std::string id_132 { std::get<2 /* Versions */>((*p_0)) };
              uint32_t id_133 { (uint32_t)id_132.size() };
              Vec<1, uint32_t> id_134 {  id_133  };
              Pointer let_res_135;
              {
                Vec<1, uint32_t> leb128_sz_800 { id_134 };
                Vec<1, Pointer> id_136 {  ssum_dst_744  };
                Pointer let_res_137;
                {
                  Vec<1, Pointer> leb128_ptr_801 { id_136 };
                  bool while_flag_138 { true };
                  do {
                    uint8_t id_139 { 0 };
                    uint8_t id_140 { 0 };
                    Pointer id_141 { leb128_ptr_801[id_140] };
                    uint32_t id_142 { 128U };
                    uint8_t id_143 { 0 };
                    uint32_t id_144 { leb128_sz_800[id_143] };
                    bool id_145 { bool(id_142 > id_144) };
                    uint8_t choose_res_146;
                    if (id_145) {
                      uint8_t id_147 { 0 };
                      uint32_t id_148 { leb128_sz_800[id_147] };
                      uint8_t id_149 { uint8_t(id_148) };
                      choose_res_146 = id_149;
                    } else {
                      uint8_t id_150 { 0 };
                      uint32_t id_151 { leb128_sz_800[id_150] };
                      uint8_t id_152 { uint8_t(id_151) };
                      uint8_t id_153 { 128 };
                      uint8_t id_154 { uint8_t(id_152 | id_153) };
                      choose_res_146 = id_154;
                    }
                    Pointer id_155 { id_141.writeU8(choose_res_146) };
                    Void id_156 { ((void)(leb128_ptr_801[id_139] = id_155), VOID) };
                    (void)id_156;
                    uint8_t id_157 { 0 };
                    uint8_t id_158 { 0 };
                    uint32_t id_159 { leb128_sz_800[id_158] };
                    uint8_t id_160 { 7 };
                    uint32_t id_161 { uint32_t(id_159 >> id_160) };
                    Void id_162 { ((void)(leb128_sz_800[id_157] = id_161), VOID) };
                    (void)id_162;
                    uint8_t id_163 { 0 };
                    uint32_t id_164 { leb128_sz_800[id_163] };
                    uint32_t id_165 { 0U };
                    bool id_166 { bool(id_164 > id_165) };
                    while_flag_138 = id_166;
                    if (while_flag_138) {
                      (void)VOID;
                    }
                  } while (while_flag_138);
                  (void)VOID;
                  uint8_t id_167 { 0 };
                  Pointer id_168 { leb128_ptr_801[id_167] };
                  let_res_137 = id_168;
                }
                let_res_135 = let_res_137;
              }
              std::string id_169 { std::get<2 /* Versions */>((*p_0)) };
              Bytes id_170 { id_169 };
              Pointer id_171 { let_res_135.writeBytes(id_170) };
              choose_res_131 = id_171;
            } else {
              uint16_t id_172 { 3 };
              bool id_173 { bool(id_172 == label1_743) };
              Pointer choose_res_174;
              if (id_173) {
                auto fun175 { dessser::gen::src_path::to_row_binary };
                ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_176 { std::get<3 /* Sources */>((*p_0)) };
                dessser::gen::src_path::t_ext id_177 { std::get<0>(id_176) };
                Pointer id_178 { fun175(id_177, ssum_dst_744) };
                Pointer let_res_179;
                {
                  Pointer stup_dst_797 { id_178 };
                  ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_180 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_181 { std::get<1>(id_180) };
                  uint32_t id_182 { (uint32_t)id_181.size() };
                  Vec<1, uint32_t> id_183 {  id_182  };
                  Pointer let_res_184;
                  {
                    Vec<1, uint32_t> leb128_sz_798 { id_183 };
                    Vec<1, Pointer> id_185 {  stup_dst_797  };
                    Pointer let_res_186;
                    {
                      Vec<1, Pointer> leb128_ptr_799 { id_185 };
                      bool while_flag_187 { true };
                      do {
                        uint8_t id_188 { 0 };
                        uint8_t id_189 { 0 };
                        Pointer id_190 { leb128_ptr_799[id_189] };
                        uint32_t id_191 { 128U };
                        uint8_t id_192 { 0 };
                        uint32_t id_193 { leb128_sz_798[id_192] };
                        bool id_194 { bool(id_191 > id_193) };
                        uint8_t choose_res_195;
                        if (id_194) {
                          uint8_t id_196 { 0 };
                          uint32_t id_197 { leb128_sz_798[id_196] };
                          uint8_t id_198 { uint8_t(id_197) };
                          choose_res_195 = id_198;
                        } else {
                          uint8_t id_199 { 0 };
                          uint32_t id_200 { leb128_sz_798[id_199] };
                          uint8_t id_201 { uint8_t(id_200) };
                          uint8_t id_202 { 128 };
                          uint8_t id_203 { uint8_t(id_201 | id_202) };
                          choose_res_195 = id_203;
                        }
                        Pointer id_204 { id_190.writeU8(choose_res_195) };
                        Void id_205 { ((void)(leb128_ptr_799[id_188] = id_204), VOID) };
                        (void)id_205;
                        uint8_t id_206 { 0 };
                        uint8_t id_207 { 0 };
                        uint32_t id_208 { leb128_sz_798[id_207] };
                        uint8_t id_209 { 7 };
                        uint32_t id_210 { uint32_t(id_208 >> id_209) };
                        Void id_211 { ((void)(leb128_sz_798[id_206] = id_210), VOID) };
                        (void)id_211;
                        uint8_t id_212 { 0 };
                        uint32_t id_213 { leb128_sz_798[id_212] };
                        uint32_t id_214 { 0U };
                        bool id_215 { bool(id_213 > id_214) };
                        while_flag_187 = id_215;
                        if (while_flag_187) {
                          (void)VOID;
                        }
                      } while (while_flag_187);
                      (void)VOID;
                      uint8_t id_216 { 0 };
                      Pointer id_217 { leb128_ptr_799[id_216] };
                      let_res_186 = id_217;
                    }
                    let_res_184 = let_res_186;
                  }
                  ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_218 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_219 { std::get<1>(id_218) };
                  Bytes id_220 { id_219 };
                  Pointer id_221 { let_res_184.writeBytes(id_220) };
                  let_res_179 = id_221;
                }
                choose_res_174 = let_res_179;
              } else {
                uint16_t id_222 { 4 };
                bool id_223 { bool(id_222 == label1_743) };
                Pointer choose_res_224;
                if (id_223) {
                  choose_res_224 = ssum_dst_744;
                } else {
                  uint16_t id_225 { 5 };
                  bool id_226 { bool(id_225 == label1_743) };
                  Pointer choose_res_227;
                  if (id_226) {
                    auto fun228 { dessser::gen::site_name::to_row_binary };
                    ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_229 { std::get<5 /* PerSite */>((*p_0)) };
                    dessser::gen::site_name::t_ext id_230 { std::get<0>(id_229) };
                    Pointer id_231 { fun228(id_230, ssum_dst_744) };
                    Pointer let_res_232;
                    {
                      Pointer stup_dst_776 { id_231 };
                      ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_233 { std::get<5 /* PerSite */>((*p_0)) };
                      ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_234 { std::get<1>(id_233) };
                      uint16_t id_235 { uint16_t(id_234.index()) };
                      Pointer id_236 { stup_dst_776.writeU16Le(id_235) };
                      Pointer let_res_237;
                      {
                        Pointer ssum_dst_778 { id_236 };
                        uint16_t id_238 { 0 };
                        ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_239 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_240 { std::get<1>(id_239) };
                        uint16_t id_241 { uint16_t(id_240.index()) };
                        bool id_242 { bool(id_238 == id_241) };
                        Pointer choose_res_243;
                        if (id_242) {
                          choose_res_243 = ssum_dst_778;
                        } else {
                          uint16_t id_244 { 1 };
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_245 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_246 { std::get<1>(id_245) };
                          uint16_t id_247 { uint16_t(id_246.index()) };
                          bool id_248 { bool(id_244 == id_247) };
                          Pointer choose_res_249;
                          if (id_248) {
                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_250 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_251 { std::get<1>(id_250) };
                            ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_252 { std::get<1 /* PerService */>(id_251) };
                            std::string id_253 { std::get<0>(id_252) };
                            uint32_t id_254 { (uint32_t)id_253.size() };
                            Vec<1, uint32_t> id_255 {  id_254  };
                            Pointer let_res_256;
                            {
                              Vec<1, uint32_t> leb128_sz_792 { id_255 };
                              Vec<1, Pointer> id_257 {  ssum_dst_778  };
                              Pointer let_res_258;
                              {
                                Vec<1, Pointer> leb128_ptr_793 { id_257 };
                                bool while_flag_259 { true };
                                do {
                                  uint8_t id_260 { 0 };
                                  uint8_t id_261 { 0 };
                                  Pointer id_262 { leb128_ptr_793[id_261] };
                                  uint32_t id_263 { 128U };
                                  uint8_t id_264 { 0 };
                                  uint32_t id_265 { leb128_sz_792[id_264] };
                                  bool id_266 { bool(id_263 > id_265) };
                                  uint8_t choose_res_267;
                                  if (id_266) {
                                    uint8_t id_268 { 0 };
                                    uint32_t id_269 { leb128_sz_792[id_268] };
                                    uint8_t id_270 { uint8_t(id_269) };
                                    choose_res_267 = id_270;
                                  } else {
                                    uint8_t id_271 { 0 };
                                    uint32_t id_272 { leb128_sz_792[id_271] };
                                    uint8_t id_273 { uint8_t(id_272) };
                                    uint8_t id_274 { 128 };
                                    uint8_t id_275 { uint8_t(id_273 | id_274) };
                                    choose_res_267 = id_275;
                                  }
                                  Pointer id_276 { id_262.writeU8(choose_res_267) };
                                  Void id_277 { ((void)(leb128_ptr_793[id_260] = id_276), VOID) };
                                  (void)id_277;
                                  uint8_t id_278 { 0 };
                                  uint8_t id_279 { 0 };
                                  uint32_t id_280 { leb128_sz_792[id_279] };
                                  uint8_t id_281 { 7 };
                                  uint32_t id_282 { uint32_t(id_280 >> id_281) };
                                  Void id_283 { ((void)(leb128_sz_792[id_278] = id_282), VOID) };
                                  (void)id_283;
                                  uint8_t id_284 { 0 };
                                  uint32_t id_285 { leb128_sz_792[id_284] };
                                  uint32_t id_286 { 0U };
                                  bool id_287 { bool(id_285 > id_286) };
                                  while_flag_259 = id_287;
                                  if (while_flag_259) {
                                    (void)VOID;
                                  }
                                } while (while_flag_259);
                                (void)VOID;
                                uint8_t id_288 { 0 };
                                Pointer id_289 { leb128_ptr_793[id_288] };
                                let_res_258 = id_289;
                              }
                              let_res_256 = let_res_258;
                            }
                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_290 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_291 { std::get<1>(id_290) };
                            ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_292 { std::get<1 /* PerService */>(id_291) };
                            std::string id_293 { std::get<0>(id_292) };
                            Bytes id_294 { id_293 };
                            Pointer id_295 { let_res_256.writeBytes(id_294) };
                            Pointer let_res_296;
                            {
                              Pointer stup_dst_794 { id_295 };
                              ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_297 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_298 { std::get<1>(id_297) };
                              ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_299 { std::get<1 /* PerService */>(id_298) };
                              ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_300 { std::get<1>(id_299) };
                              uint16_t id_301 { uint16_t(id_300.index()) };
                              Pointer id_302 { stup_dst_794.writeU16Le(id_301) };
                              Pointer let_res_303;
                              {
                                Pointer ssum_dst_796 { id_302 };
                                uint16_t id_304 { 0 };
                                ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_305 { std::get<5 /* PerSite */>((*p_0)) };
                                ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_306 { std::get<1>(id_305) };
                                ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_307 { std::get<1 /* PerService */>(id_306) };
                                ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_308 { std::get<1>(id_307) };
                                uint16_t id_309 { uint16_t(id_308.index()) };
                                bool id_310 { bool(id_304 == id_309) };
                                Pointer choose_res_311;
                                if (id_310) {
                                  choose_res_311 = ssum_dst_796;
                                } else {
                                  ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_312 { std::get<5 /* PerSite */>((*p_0)) };
                                  ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_313 { std::get<1>(id_312) };
                                  ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_314 { std::get<1 /* PerService */>(id_313) };
                                  ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_315 { std::get<1>(id_314) };
                                  uint16_t id_316 { uint16_t(id_315.index()) };
                                  uint16_t id_317 { 1 };
                                  bool id_318 { bool(id_316 == id_317) };
                                  Void id_319 { ((void)(assert(id_318)), VOID) };
                                  (void)id_319;
                                  choose_res_311 = ssum_dst_796;
                                }
                                let_res_303 = choose_res_311;
                              }
                              let_res_296 = let_res_303;
                            }
                            choose_res_249 = let_res_296;
                          } else {
                            uint16_t id_320 { 2 };
                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_321 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_322 { std::get<1>(id_321) };
                            uint16_t id_323 { uint16_t(id_322.index()) };
                            bool id_324 { bool(id_320 == id_323) };
                            Pointer choose_res_325;
                            if (id_324) {
                              auto fun326 { dessser::gen::fq_name::to_row_binary };
                              ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_327 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_328 { std::get<1>(id_327) };
                              ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_329 { std::get<2 /* PerWorker */>(id_328) };
                              dessser::gen::fq_name::t_ext id_330 { std::get<0>(id_329) };
                              Pointer id_331 { fun326(id_330, ssum_dst_778) };
                              Pointer let_res_332;
                              {
                                Pointer stup_dst_784 { id_331 };
                                ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_333 { std::get<5 /* PerSite */>((*p_0)) };
                                ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_334 { std::get<1>(id_333) };
                                ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_335 { std::get<2 /* PerWorker */>(id_334) };
                                ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_336 { std::get<1>(id_335) };
                                uint16_t id_337 { uint16_t(id_336.index()) };
                                Pointer let_res_338;
                                {
                                  uint16_t label1_785 { id_337 };
                                  Pointer id_339 { stup_dst_784.writeU16Le(label1_785) };
                                  Pointer let_res_340;
                                  {
                                    Pointer ssum_dst_786 { id_339 };
                                    uint16_t id_341 { 0 };
                                    bool id_342 { bool(id_341 == label1_785) };
                                    Pointer choose_res_343;
                                    if (id_342) {
                                      choose_res_343 = ssum_dst_786;
                                    } else {
                                      uint16_t id_344 { 1 };
                                      bool id_345 { bool(id_344 == label1_785) };
                                      Pointer choose_res_346;
                                      if (id_345) {
                                        choose_res_346 = ssum_dst_786;
                                      } else {
                                        uint16_t id_347 { 2 };
                                        bool id_348 { bool(id_347 == label1_785) };
                                        Pointer choose_res_349;
                                        if (id_348) {
                                          choose_res_349 = ssum_dst_786;
                                        } else {
                                          uint16_t id_350 { 3 };
                                          bool id_351 { bool(id_350 == label1_785) };
                                          Pointer choose_res_352;
                                          if (id_351) {
                                            choose_res_352 = ssum_dst_786;
                                          } else {
                                            uint16_t id_353 { 4 };
                                            bool id_354 { bool(id_353 == label1_785) };
                                            Pointer choose_res_355;
                                            if (id_354) {
                                              choose_res_355 = ssum_dst_786;
                                            } else {
                                              uint16_t id_356 { 5 };
                                              bool id_357 { bool(id_356 == label1_785) };
                                              Pointer choose_res_358;
                                              if (id_357) {
                                                choose_res_358 = ssum_dst_786;
                                              } else {
                                                uint16_t id_359 { 6 };
                                                bool id_360 { bool(id_359 == label1_785) };
                                                Pointer choose_res_361;
                                                if (id_360) {
                                                  ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_362 { std::get<5 /* PerSite */>((*p_0)) };
                                                  ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_363 { std::get<1>(id_362) };
                                                  ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_364 { std::get<2 /* PerWorker */>(id_363) };
                                                  ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_365 { std::get<1>(id_364) };
                                                  ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_366 { std::get<6 /* PerInstance */>(id_365) };
                                                  std::string id_367 { std::get<0>(id_366) };
                                                  uint32_t id_368 { (uint32_t)id_367.size() };
                                                  Vec<1, uint32_t> id_369 {  id_368  };
                                                  Pointer let_res_370;
                                                  {
                                                    Vec<1, uint32_t> leb128_sz_787 { id_369 };
                                                    Vec<1, Pointer> id_371 {  ssum_dst_786  };
                                                    Pointer let_res_372;
                                                    {
                                                      Vec<1, Pointer> leb128_ptr_788 { id_371 };
                                                      bool while_flag_373 { true };
                                                      do {
                                                        uint8_t id_374 { 0 };
                                                        uint8_t id_375 { 0 };
                                                        Pointer id_376 { leb128_ptr_788[id_375] };
                                                        uint32_t id_377 { 128U };
                                                        uint8_t id_378 { 0 };
                                                        uint32_t id_379 { leb128_sz_787[id_378] };
                                                        bool id_380 { bool(id_377 > id_379) };
                                                        uint8_t choose_res_381;
                                                        if (id_380) {
                                                          uint8_t id_382 { 0 };
                                                          uint32_t id_383 { leb128_sz_787[id_382] };
                                                          uint8_t id_384 { uint8_t(id_383) };
                                                          choose_res_381 = id_384;
                                                        } else {
                                                          uint8_t id_385 { 0 };
                                                          uint32_t id_386 { leb128_sz_787[id_385] };
                                                          uint8_t id_387 { uint8_t(id_386) };
                                                          uint8_t id_388 { 128 };
                                                          uint8_t id_389 { uint8_t(id_387 | id_388) };
                                                          choose_res_381 = id_389;
                                                        }
                                                        Pointer id_390 { id_376.writeU8(choose_res_381) };
                                                        Void id_391 { ((void)(leb128_ptr_788[id_374] = id_390), VOID) };
                                                        (void)id_391;
                                                        uint8_t id_392 { 0 };
                                                        uint8_t id_393 { 0 };
                                                        uint32_t id_394 { leb128_sz_787[id_393] };
                                                        uint8_t id_395 { 7 };
                                                        uint32_t id_396 { uint32_t(id_394 >> id_395) };
                                                        Void id_397 { ((void)(leb128_sz_787[id_392] = id_396), VOID) };
                                                        (void)id_397;
                                                        uint8_t id_398 { 0 };
                                                        uint32_t id_399 { leb128_sz_787[id_398] };
                                                        uint32_t id_400 { 0U };
                                                        bool id_401 { bool(id_399 > id_400) };
                                                        while_flag_373 = id_401;
                                                        if (while_flag_373) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_373);
                                                      (void)VOID;
                                                      uint8_t id_402 { 0 };
                                                      Pointer id_403 { leb128_ptr_788[id_402] };
                                                      let_res_372 = id_403;
                                                    }
                                                    let_res_370 = let_res_372;
                                                  }
                                                  ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_404 { std::get<5 /* PerSite */>((*p_0)) };
                                                  ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_405 { std::get<1>(id_404) };
                                                  ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_406 { std::get<2 /* PerWorker */>(id_405) };
                                                  ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_407 { std::get<1>(id_406) };
                                                  ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_408 { std::get<6 /* PerInstance */>(id_407) };
                                                  std::string id_409 { std::get<0>(id_408) };
                                                  Bytes id_410 { id_409 };
                                                  Pointer id_411 { let_res_370.writeBytes(id_410) };
                                                  Pointer let_res_412;
                                                  {
                                                    Pointer stup_dst_789 { id_411 };
                                                    ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_413 { std::get<5 /* PerSite */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_414 { std::get<1>(id_413) };
                                                    ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_415 { std::get<2 /* PerWorker */>(id_414) };
                                                    ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_416 { std::get<1>(id_415) };
                                                    ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_417 { std::get<6 /* PerInstance */>(id_416) };
                                                    ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_418 { std::get<1>(id_417) };
                                                    uint16_t id_419 { uint16_t(id_418.index()) };
                                                    Pointer let_res_420;
                                                    {
                                                      uint16_t label1_790 { id_419 };
                                                      Pointer id_421 { stup_dst_789.writeU16Le(label1_790) };
                                                      Pointer let_res_422;
                                                      {
                                                        Pointer ssum_dst_791 { id_421 };
                                                        uint16_t id_423 { 0 };
                                                        bool id_424 { bool(id_423 == label1_790) };
                                                        Pointer choose_res_425;
                                                        if (id_424) {
                                                          choose_res_425 = ssum_dst_791;
                                                        } else {
                                                          uint16_t id_426 { 1 };
                                                          bool id_427 { bool(id_426 == label1_790) };
                                                          Pointer choose_res_428;
                                                          if (id_427) {
                                                            choose_res_428 = ssum_dst_791;
                                                          } else {
                                                            uint16_t id_429 { 2 };
                                                            bool id_430 { bool(id_429 == label1_790) };
                                                            Pointer choose_res_431;
                                                            if (id_430) {
                                                              choose_res_431 = ssum_dst_791;
                                                            } else {
                                                              uint16_t id_432 { 3 };
                                                              bool id_433 { bool(id_432 == label1_790) };
                                                              Pointer choose_res_434;
                                                              if (id_433) {
                                                                choose_res_434 = ssum_dst_791;
                                                              } else {
                                                                uint16_t id_435 { 4 };
                                                                bool id_436 { bool(id_435 == label1_790) };
                                                                Pointer choose_res_437;
                                                                if (id_436) {
                                                                  choose_res_437 = ssum_dst_791;
                                                                } else {
                                                                  uint16_t id_438 { 5 };
                                                                  bool id_439 { bool(id_438 == label1_790) };
                                                                  Pointer choose_res_440;
                                                                  if (id_439) {
                                                                    choose_res_440 = ssum_dst_791;
                                                                  } else {
                                                                    uint16_t id_441 { 6 };
                                                                    bool id_442 { bool(id_441 == label1_790) };
                                                                    Pointer choose_res_443;
                                                                    if (id_442) {
                                                                      choose_res_443 = ssum_dst_791;
                                                                    } else {
                                                                      uint16_t id_444 { 7 };
                                                                      bool id_445 { bool(label1_790 == id_444) };
                                                                      Void id_446 { ((void)(assert(id_445)), VOID) };
                                                                      (void)id_446;
                                                                      choose_res_443 = ssum_dst_791;
                                                                    }
                                                                    choose_res_440 = choose_res_443;
                                                                  }
                                                                  choose_res_437 = choose_res_440;
                                                                }
                                                                choose_res_434 = choose_res_437;
                                                              }
                                                              choose_res_431 = choose_res_434;
                                                            }
                                                            choose_res_428 = choose_res_431;
                                                          }
                                                          choose_res_425 = choose_res_428;
                                                        }
                                                        let_res_422 = choose_res_425;
                                                      }
                                                      let_res_420 = let_res_422;
                                                    }
                                                    let_res_412 = let_res_420;
                                                  }
                                                  choose_res_361 = let_res_412;
                                                } else {
                                                  uint16_t id_447 { 7 };
                                                  bool id_448 { bool(id_447 == label1_785) };
                                                  Pointer choose_res_449;
                                                  if (id_448) {
                                                    ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_450 { std::get<5 /* PerSite */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_451 { std::get<1>(id_450) };
                                                    ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_452 { std::get<2 /* PerWorker */>(id_451) };
                                                    ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_453 { std::get<1>(id_452) };
                                                    uint32_t id_454 { std::get<7 /* PerReplayer */>(id_453) };
                                                    Pointer id_455 { ssum_dst_786.writeU32Le(id_454) };
                                                    choose_res_449 = id_455;
                                                  } else {
                                                    uint16_t id_456 { 8 };
                                                    bool id_457 { bool(label1_785 == id_456) };
                                                    Void id_458 { ((void)(assert(id_457)), VOID) };
                                                    (void)id_458;
                                                    choose_res_449 = ssum_dst_786;
                                                  }
                                                  choose_res_361 = choose_res_449;
                                                }
                                                choose_res_358 = choose_res_361;
                                              }
                                              choose_res_355 = choose_res_358;
                                            }
                                            choose_res_352 = choose_res_355;
                                          }
                                          choose_res_349 = choose_res_352;
                                        }
                                        choose_res_346 = choose_res_349;
                                      }
                                      choose_res_343 = choose_res_346;
                                    }
                                    let_res_340 = choose_res_343;
                                  }
                                  let_res_338 = let_res_340;
                                }
                                let_res_332 = let_res_338;
                              }
                              choose_res_325 = let_res_332;
                            } else {
                              ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_459 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_460 { std::get<1>(id_459) };
                              uint16_t id_461 { uint16_t(id_460.index()) };
                              uint16_t id_462 { 3 };
                              bool id_463 { bool(id_461 == id_462) };
                              Void id_464 { ((void)(assert(id_463)), VOID) };
                              (void)id_464;
                              ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_465 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_466 { std::get<1>(id_465) };
                              ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_467 { std::get<3 /* PerProgram */>(id_466) };
                              std::string id_468 { std::get<0>(id_467) };
                              uint32_t id_469 { (uint32_t)id_468.size() };
                              Vec<1, uint32_t> id_470 {  id_469  };
                              Pointer let_res_471;
                              {
                                Vec<1, uint32_t> leb128_sz_779 { id_470 };
                                Vec<1, Pointer> id_472 {  ssum_dst_778  };
                                Pointer let_res_473;
                                {
                                  Vec<1, Pointer> leb128_ptr_780 { id_472 };
                                  bool while_flag_474 { true };
                                  do {
                                    uint8_t id_475 { 0 };
                                    uint8_t id_476 { 0 };
                                    Pointer id_477 { leb128_ptr_780[id_476] };
                                    uint32_t id_478 { 128U };
                                    uint8_t id_479 { 0 };
                                    uint32_t id_480 { leb128_sz_779[id_479] };
                                    bool id_481 { bool(id_478 > id_480) };
                                    uint8_t choose_res_482;
                                    if (id_481) {
                                      uint8_t id_483 { 0 };
                                      uint32_t id_484 { leb128_sz_779[id_483] };
                                      uint8_t id_485 { uint8_t(id_484) };
                                      choose_res_482 = id_485;
                                    } else {
                                      uint8_t id_486 { 0 };
                                      uint32_t id_487 { leb128_sz_779[id_486] };
                                      uint8_t id_488 { uint8_t(id_487) };
                                      uint8_t id_489 { 128 };
                                      uint8_t id_490 { uint8_t(id_488 | id_489) };
                                      choose_res_482 = id_490;
                                    }
                                    Pointer id_491 { id_477.writeU8(choose_res_482) };
                                    Void id_492 { ((void)(leb128_ptr_780[id_475] = id_491), VOID) };
                                    (void)id_492;
                                    uint8_t id_493 { 0 };
                                    uint8_t id_494 { 0 };
                                    uint32_t id_495 { leb128_sz_779[id_494] };
                                    uint8_t id_496 { 7 };
                                    uint32_t id_497 { uint32_t(id_495 >> id_496) };
                                    Void id_498 { ((void)(leb128_sz_779[id_493] = id_497), VOID) };
                                    (void)id_498;
                                    uint8_t id_499 { 0 };
                                    uint32_t id_500 { leb128_sz_779[id_499] };
                                    uint32_t id_501 { 0U };
                                    bool id_502 { bool(id_500 > id_501) };
                                    while_flag_474 = id_502;
                                    if (while_flag_474) {
                                      (void)VOID;
                                    }
                                  } while (while_flag_474);
                                  (void)VOID;
                                  uint8_t id_503 { 0 };
                                  Pointer id_504 { leb128_ptr_780[id_503] };
                                  let_res_473 = id_504;
                                }
                                let_res_471 = let_res_473;
                              }
                              ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_505 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_506 { std::get<1>(id_505) };
                              ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_507 { std::get<3 /* PerProgram */>(id_506) };
                              std::string id_508 { std::get<0>(id_507) };
                              Bytes id_509 { id_508 };
                              Pointer id_510 { let_res_471.writeBytes(id_509) };
                              Pointer let_res_511;
                              {
                                Pointer stup_dst_781 { id_510 };
                                ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_512 { std::get<5 /* PerSite */>((*p_0)) };
                                ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_513 { std::get<1>(id_512) };
                                ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_514 { std::get<3 /* PerProgram */>(id_513) };
                                ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_515 { std::get<1>(id_514) };
                                uint16_t id_516 { uint16_t(id_515.index()) };
                                Pointer id_517 { stup_dst_781.writeU16Le(id_516) };
                                Pointer let_res_518;
                                {
                                  Pointer ssum_dst_783 { id_517 };
                                  ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_519 { std::get<5 /* PerSite */>((*p_0)) };
                                  ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_520 { std::get<1>(id_519) };
                                  ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_521 { std::get<3 /* PerProgram */>(id_520) };
                                  ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_522 { std::get<1>(id_521) };
                                  uint16_t id_523 { uint16_t(id_522.index()) };
                                  uint16_t id_524 { 0 };
                                  bool id_525 { bool(id_523 == id_524) };
                                  Void id_526 { ((void)(assert(id_525)), VOID) };
                                  (void)id_526;
                                  let_res_518 = ssum_dst_783;
                                }
                                let_res_511 = let_res_518;
                              }
                              choose_res_325 = let_res_511;
                            }
                            choose_res_249 = choose_res_325;
                          }
                          choose_res_243 = choose_res_249;
                        }
                        let_res_237 = choose_res_243;
                      }
                      let_res_232 = let_res_237;
                    }
                    choose_res_227 = let_res_232;
                  } else {
                    uint16_t id_527 { 6 };
                    bool id_528 { bool(id_527 == label1_743) };
                    Pointer choose_res_529;
                    if (id_528) {
                      ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_530 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_531 { uint16_t(id_530.index()) };
                      Pointer id_532 { ssum_dst_744.writeU16Le(id_531) };
                      Pointer let_res_533;
                      {
                        Pointer ssum_dst_773 { id_532 };
                        uint16_t id_534 { 0 };
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_535 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_536 { uint16_t(id_535.index()) };
                        bool id_537 { bool(id_534 == id_536) };
                        Pointer choose_res_538;
                        if (id_537) {
                          choose_res_538 = ssum_dst_773;
                        } else {
                          uint16_t id_539 { 1 };
                          ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_540 { std::get<6 /* Storage */>((*p_0)) };
                          uint16_t id_541 { uint16_t(id_540.index()) };
                          bool id_542 { bool(id_539 == id_541) };
                          Pointer choose_res_543;
                          if (id_542) {
                            choose_res_543 = ssum_dst_773;
                          } else {
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_544 { std::get<6 /* Storage */>((*p_0)) };
                            uint16_t id_545 { uint16_t(id_544.index()) };
                            uint16_t id_546 { 2 };
                            bool id_547 { bool(id_545 == id_546) };
                            Void id_548 { ((void)(assert(id_547)), VOID) };
                            (void)id_548;
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_549 { std::get<6 /* Storage */>((*p_0)) };
                            std::string id_550 { std::get<2 /* RetentionsOverride */>(id_549) };
                            uint32_t id_551 { (uint32_t)id_550.size() };
                            Vec<1, uint32_t> id_552 {  id_551  };
                            Pointer let_res_553;
                            {
                              Vec<1, uint32_t> leb128_sz_774 { id_552 };
                              Vec<1, Pointer> id_554 {  ssum_dst_773  };
                              Pointer let_res_555;
                              {
                                Vec<1, Pointer> leb128_ptr_775 { id_554 };
                                bool while_flag_556 { true };
                                do {
                                  uint8_t id_557 { 0 };
                                  uint8_t id_558 { 0 };
                                  Pointer id_559 { leb128_ptr_775[id_558] };
                                  uint32_t id_560 { 128U };
                                  uint8_t id_561 { 0 };
                                  uint32_t id_562 { leb128_sz_774[id_561] };
                                  bool id_563 { bool(id_560 > id_562) };
                                  uint8_t choose_res_564;
                                  if (id_563) {
                                    uint8_t id_565 { 0 };
                                    uint32_t id_566 { leb128_sz_774[id_565] };
                                    uint8_t id_567 { uint8_t(id_566) };
                                    choose_res_564 = id_567;
                                  } else {
                                    uint8_t id_568 { 0 };
                                    uint32_t id_569 { leb128_sz_774[id_568] };
                                    uint8_t id_570 { uint8_t(id_569) };
                                    uint8_t id_571 { 128 };
                                    uint8_t id_572 { uint8_t(id_570 | id_571) };
                                    choose_res_564 = id_572;
                                  }
                                  Pointer id_573 { id_559.writeU8(choose_res_564) };
                                  Void id_574 { ((void)(leb128_ptr_775[id_557] = id_573), VOID) };
                                  (void)id_574;
                                  uint8_t id_575 { 0 };
                                  uint8_t id_576 { 0 };
                                  uint32_t id_577 { leb128_sz_774[id_576] };
                                  uint8_t id_578 { 7 };
                                  uint32_t id_579 { uint32_t(id_577 >> id_578) };
                                  Void id_580 { ((void)(leb128_sz_774[id_575] = id_579), VOID) };
                                  (void)id_580;
                                  uint8_t id_581 { 0 };
                                  uint32_t id_582 { leb128_sz_774[id_581] };
                                  uint32_t id_583 { 0U };
                                  bool id_584 { bool(id_582 > id_583) };
                                  while_flag_556 = id_584;
                                  if (while_flag_556) {
                                    (void)VOID;
                                  }
                                } while (while_flag_556);
                                (void)VOID;
                                uint8_t id_585 { 0 };
                                Pointer id_586 { leb128_ptr_775[id_585] };
                                let_res_555 = id_586;
                              }
                              let_res_553 = let_res_555;
                            }
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_587 { std::get<6 /* Storage */>((*p_0)) };
                            std::string id_588 { std::get<2 /* RetentionsOverride */>(id_587) };
                            Bytes id_589 { id_588 };
                            Pointer id_590 { let_res_553.writeBytes(id_589) };
                            choose_res_543 = id_590;
                          }
                          choose_res_538 = choose_res_543;
                        }
                        let_res_533 = choose_res_538;
                      }
                      choose_res_529 = let_res_533;
                    } else {
                      uint16_t id_591 { 7 };
                      bool id_592 { bool(id_591 == label1_743) };
                      Pointer choose_res_593;
                      if (id_592) {
                        auto fun594 { dessser::gen::site_name::to_row_binary };
                        ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_595 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::site_name::t_ext id_596 { std::get<0>(id_595) };
                        Pointer id_597 { fun594(id_596, ssum_dst_744) };
                        Pointer let_res_598;
                        {
                          Pointer stup_dst_767 { id_597 };
                          auto fun599 { dessser::gen::fq_name::to_row_binary };
                          ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_600 { std::get<7 /* Tails */>((*p_0)) };
                          dessser::gen::fq_name::t_ext id_601 { std::get<1>(id_600) };
                          Pointer id_602 { fun599(id_601, stup_dst_767) };
                          let_res_598 = id_602;
                        }
                        Pointer let_res_603;
                        {
                          Pointer stup_dst_768 { let_res_598 };
                          ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_604 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_605 { std::get<2>(id_604) };
                          uint32_t id_606 { (uint32_t)id_605.size() };
                          Vec<1, uint32_t> id_607 {  id_606  };
                          Pointer let_res_608;
                          {
                            Vec<1, uint32_t> leb128_sz_769 { id_607 };
                            Vec<1, Pointer> id_609 {  stup_dst_768  };
                            Pointer let_res_610;
                            {
                              Vec<1, Pointer> leb128_ptr_770 { id_609 };
                              bool while_flag_611 { true };
                              do {
                                uint8_t id_612 { 0 };
                                uint8_t id_613 { 0 };
                                Pointer id_614 { leb128_ptr_770[id_613] };
                                uint32_t id_615 { 128U };
                                uint8_t id_616 { 0 };
                                uint32_t id_617 { leb128_sz_769[id_616] };
                                bool id_618 { bool(id_615 > id_617) };
                                uint8_t choose_res_619;
                                if (id_618) {
                                  uint8_t id_620 { 0 };
                                  uint32_t id_621 { leb128_sz_769[id_620] };
                                  uint8_t id_622 { uint8_t(id_621) };
                                  choose_res_619 = id_622;
                                } else {
                                  uint8_t id_623 { 0 };
                                  uint32_t id_624 { leb128_sz_769[id_623] };
                                  uint8_t id_625 { uint8_t(id_624) };
                                  uint8_t id_626 { 128 };
                                  uint8_t id_627 { uint8_t(id_625 | id_626) };
                                  choose_res_619 = id_627;
                                }
                                Pointer id_628 { id_614.writeU8(choose_res_619) };
                                Void id_629 { ((void)(leb128_ptr_770[id_612] = id_628), VOID) };
                                (void)id_629;
                                uint8_t id_630 { 0 };
                                uint8_t id_631 { 0 };
                                uint32_t id_632 { leb128_sz_769[id_631] };
                                uint8_t id_633 { 7 };
                                uint32_t id_634 { uint32_t(id_632 >> id_633) };
                                Void id_635 { ((void)(leb128_sz_769[id_630] = id_634), VOID) };
                                (void)id_635;
                                uint8_t id_636 { 0 };
                                uint32_t id_637 { leb128_sz_769[id_636] };
                                uint32_t id_638 { 0U };
                                bool id_639 { bool(id_637 > id_638) };
                                while_flag_611 = id_639;
                                if (while_flag_611) {
                                  (void)VOID;
                                }
                              } while (while_flag_611);
                              (void)VOID;
                              uint8_t id_640 { 0 };
                              Pointer id_641 { leb128_ptr_770[id_640] };
                              let_res_610 = id_641;
                            }
                            let_res_608 = let_res_610;
                          }
                          ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_642 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_643 { std::get<2>(id_642) };
                          Bytes id_644 { id_643 };
                          Pointer id_645 { let_res_608.writeBytes(id_644) };
                          let_res_603 = id_645;
                        }
                        Pointer let_res_646;
                        {
                          Pointer stup_dst_771 { let_res_603 };
                          ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_647 { std::get<7 /* Tails */>((*p_0)) };
                          std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_648 { std::get<3>(id_647) };
                          Pointer id_649 { per_tail_to_row_binary(id_648, stup_dst_771) };
                          let_res_646 = id_649;
                        }
                        choose_res_593 = let_res_646;
                      } else {
                        uint16_t id_650 { 8 };
                        bool id_651 { bool(id_650 == label1_743) };
                        Pointer choose_res_652;
                        if (id_651) {
                          uint16_t id_653 { std::get<8 /* Replays */>((*p_0)) };
                          Pointer id_654 { ssum_dst_744.writeU16Le(id_653) };
                          choose_res_652 = id_654;
                        } else {
                          uint16_t id_655 { 9 };
                          bool id_656 { bool(id_655 == label1_743) };
                          Pointer choose_res_657;
                          if (id_656) {
                            std::optional<dessser::gen::sync_socket::t_ext> id_658 { std::get<9 /* Error */>((*p_0)) };
                            bool id_659 { !(id_658.has_value ()) };
                            Pointer choose_res_660;
                            if (id_659) {
                              uint8_t id_661 { 1 };
                              Pointer id_662 { ssum_dst_744.writeU8(id_661) };
                              choose_res_660 = id_662;
                            } else {
                              auto fun663 { dessser::gen::sync_socket::to_row_binary };
                              std::optional<dessser::gen::sync_socket::t_ext> id_664 { std::get<9 /* Error */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_665 { id_664.value() };
                              uint8_t id_666 { 0 };
                              Pointer id_667 { ssum_dst_744.writeU8(id_666) };
                              Pointer id_668 { fun663(id_665, id_667) };
                              choose_res_660 = id_668;
                            }
                            choose_res_657 = choose_res_660;
                          } else {
                            uint16_t id_669 { 10 };
                            bool id_670 { bool(id_669 == label1_743) };
                            Pointer choose_res_671;
                            if (id_670) {
                              choose_res_671 = ssum_dst_744;
                            } else {
                              uint16_t id_672 { 11 };
                              bool id_673 { bool(id_672 == label1_743) };
                              Pointer choose_res_674;
                              if (id_673) {
                                auto fun675 { dessser::gen::sync_socket::to_row_binary };
                                ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef id_676 { std::get<11 /* PerClient */>((*p_0)) };
                                dessser::gen::sync_socket::t_ext id_677 { std::get<0>(id_676) };
                                Pointer id_678 { fun675(id_677, ssum_dst_744) };
                                Pointer let_res_679;
                                {
                                  Pointer stup_dst_766 { id_678 };
                                  ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef id_680 { std::get<11 /* PerClient */>((*p_0)) };
                                  std::shared_ptr<::dessser::gen::sync_key::per_client>  id_681 { std::get<1>(id_680) };
                                  Pointer id_682 { per_client_to_row_binary(id_681, stup_dst_766) };
                                  let_res_679 = id_682;
                                }
                                choose_res_674 = let_res_679;
                              } else {
                                uint16_t id_683 { 12 };
                                bool id_684 { bool(id_683 == label1_743) };
                                Pointer choose_res_685;
                                if (id_684) {
                                  ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_686 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_687 { std::get<0>(id_686) };
                                  uint32_t id_688 { (uint32_t)id_687.size() };
                                  Vec<1, uint32_t> id_689 {  id_688  };
                                  Pointer let_res_690;
                                  {
                                    Vec<1, uint32_t> leb128_sz_763 { id_689 };
                                    Vec<1, Pointer> id_691 {  ssum_dst_744  };
                                    Pointer let_res_692;
                                    {
                                      Vec<1, Pointer> leb128_ptr_764 { id_691 };
                                      bool while_flag_693 { true };
                                      do {
                                        uint8_t id_694 { 0 };
                                        uint8_t id_695 { 0 };
                                        Pointer id_696 { leb128_ptr_764[id_695] };
                                        uint32_t id_697 { 128U };
                                        uint8_t id_698 { 0 };
                                        uint32_t id_699 { leb128_sz_763[id_698] };
                                        bool id_700 { bool(id_697 > id_699) };
                                        uint8_t choose_res_701;
                                        if (id_700) {
                                          uint8_t id_702 { 0 };
                                          uint32_t id_703 { leb128_sz_763[id_702] };
                                          uint8_t id_704 { uint8_t(id_703) };
                                          choose_res_701 = id_704;
                                        } else {
                                          uint8_t id_705 { 0 };
                                          uint32_t id_706 { leb128_sz_763[id_705] };
                                          uint8_t id_707 { uint8_t(id_706) };
                                          uint8_t id_708 { 128 };
                                          uint8_t id_709 { uint8_t(id_707 | id_708) };
                                          choose_res_701 = id_709;
                                        }
                                        Pointer id_710 { id_696.writeU8(choose_res_701) };
                                        Void id_711 { ((void)(leb128_ptr_764[id_694] = id_710), VOID) };
                                        (void)id_711;
                                        uint8_t id_712 { 0 };
                                        uint8_t id_713 { 0 };
                                        uint32_t id_714 { leb128_sz_763[id_713] };
                                        uint8_t id_715 { 7 };
                                        uint32_t id_716 { uint32_t(id_714 >> id_715) };
                                        Void id_717 { ((void)(leb128_sz_763[id_712] = id_716), VOID) };
                                        (void)id_717;
                                        uint8_t id_718 { 0 };
                                        uint32_t id_719 { leb128_sz_763[id_718] };
                                        uint32_t id_720 { 0U };
                                        bool id_721 { bool(id_719 > id_720) };
                                        while_flag_693 = id_721;
                                        if (while_flag_693) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_693);
                                      (void)VOID;
                                      uint8_t id_722 { 0 };
                                      Pointer id_723 { leb128_ptr_764[id_722] };
                                      let_res_692 = id_723;
                                    }
                                    let_res_690 = let_res_692;
                                  }
                                  ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_724 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_725 { std::get<0>(id_724) };
                                  Bytes id_726 { id_725 };
                                  Pointer id_727 { let_res_690.writeBytes(id_726) };
                                  Pointer let_res_728;
                                  {
                                    Pointer stup_dst_765 { id_727 };
                                    ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_729 { std::get<12 /* Dashboards */>((*p_0)) };
                                    std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_730 { std::get<1>(id_729) };
                                    Pointer id_731 { per_dash_key_to_row_binary(id_730, stup_dst_765) };
                                    let_res_728 = id_731;
                                  }
                                  choose_res_685 = let_res_728;
                                } else {
                                  uint16_t id_732 { 13 };
                                  bool id_733 { bool(id_732 == label1_743) };
                                  Pointer choose_res_734;
                                  if (id_733) {
                                    choose_res_734 = ssum_dst_744;
                                  } else {
                                    uint16_t id_735 { 14 };
                                    bool id_736 { bool(id_735 == label1_743) };
                                    Pointer choose_res_737;
                                    if (id_736) {
                                      auto fun738 { dessser::gen::team_name::to_row_binary };
                                      ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_739 { std::get<14 /* Teams */>((*p_0)) };
                                      dessser::gen::team_name::t_ext id_740 { std::get<0>(id_739) };
                                      Pointer id_741 { fun738(id_740, ssum_dst_744) };
                                      Pointer let_res_742;
                                      {
                                        Pointer stup_dst_756 { id_741 };
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_743 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_744 { std::get<1>(id_743) };
                                        uint16_t id_745 { uint16_t(id_744.index()) };
                                        Pointer id_746 { stup_dst_756.writeU16Le(id_745) };
                                        Pointer let_res_747;
                                        {
                                          Pointer ssum_dst_758 { id_746 };
                                          uint16_t id_748 { 0 };
                                          ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_749 { std::get<14 /* Teams */>((*p_0)) };
                                          ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_750 { std::get<1>(id_749) };
                                          uint16_t id_751 { uint16_t(id_750.index()) };
                                          bool id_752 { bool(id_748 == id_751) };
                                          Pointer choose_res_753;
                                          if (id_752) {
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_754 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_755 { std::get<1>(id_754) };
                                            std::string id_756 { std::get<0 /* Contacts */>(id_755) };
                                            uint32_t id_757 { (uint32_t)id_756.size() };
                                            Vec<1, uint32_t> id_758 {  id_757  };
                                            Pointer let_res_759;
                                            {
                                              Vec<1, uint32_t> leb128_sz_761 { id_758 };
                                              Vec<1, Pointer> id_760 {  ssum_dst_758  };
                                              Pointer let_res_761;
                                              {
                                                Vec<1, Pointer> leb128_ptr_762 { id_760 };
                                                bool while_flag_762 { true };
                                                do {
                                                  uint8_t id_763 { 0 };
                                                  uint8_t id_764 { 0 };
                                                  Pointer id_765 { leb128_ptr_762[id_764] };
                                                  uint32_t id_766 { 128U };
                                                  uint8_t id_767 { 0 };
                                                  uint32_t id_768 { leb128_sz_761[id_767] };
                                                  bool id_769 { bool(id_766 > id_768) };
                                                  uint8_t choose_res_770;
                                                  if (id_769) {
                                                    uint8_t id_771 { 0 };
                                                    uint32_t id_772 { leb128_sz_761[id_771] };
                                                    uint8_t id_773 { uint8_t(id_772) };
                                                    choose_res_770 = id_773;
                                                  } else {
                                                    uint8_t id_774 { 0 };
                                                    uint32_t id_775 { leb128_sz_761[id_774] };
                                                    uint8_t id_776 { uint8_t(id_775) };
                                                    uint8_t id_777 { 128 };
                                                    uint8_t id_778 { uint8_t(id_776 | id_777) };
                                                    choose_res_770 = id_778;
                                                  }
                                                  Pointer id_779 { id_765.writeU8(choose_res_770) };
                                                  Void id_780 { ((void)(leb128_ptr_762[id_763] = id_779), VOID) };
                                                  (void)id_780;
                                                  uint8_t id_781 { 0 };
                                                  uint8_t id_782 { 0 };
                                                  uint32_t id_783 { leb128_sz_761[id_782] };
                                                  uint8_t id_784 { 7 };
                                                  uint32_t id_785 { uint32_t(id_783 >> id_784) };
                                                  Void id_786 { ((void)(leb128_sz_761[id_781] = id_785), VOID) };
                                                  (void)id_786;
                                                  uint8_t id_787 { 0 };
                                                  uint32_t id_788 { leb128_sz_761[id_787] };
                                                  uint32_t id_789 { 0U };
                                                  bool id_790 { bool(id_788 > id_789) };
                                                  while_flag_762 = id_790;
                                                  if (while_flag_762) {
                                                    (void)VOID;
                                                  }
                                                } while (while_flag_762);
                                                (void)VOID;
                                                uint8_t id_791 { 0 };
                                                Pointer id_792 { leb128_ptr_762[id_791] };
                                                let_res_761 = id_792;
                                              }
                                              let_res_759 = let_res_761;
                                            }
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_793 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_794 { std::get<1>(id_793) };
                                            std::string id_795 { std::get<0 /* Contacts */>(id_794) };
                                            Bytes id_796 { id_795 };
                                            Pointer id_797 { let_res_759.writeBytes(id_796) };
                                            choose_res_753 = id_797;
                                          } else {
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_798 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_799 { std::get<1>(id_798) };
                                            uint16_t id_800 { uint16_t(id_799.index()) };
                                            uint16_t id_801 { 1 };
                                            bool id_802 { bool(id_800 == id_801) };
                                            Void id_803 { ((void)(assert(id_802)), VOID) };
                                            (void)id_803;
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_804 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_805 { std::get<1>(id_804) };
                                            std::string id_806 { std::get<1 /* Inhibition */>(id_805) };
                                            uint32_t id_807 { (uint32_t)id_806.size() };
                                            Vec<1, uint32_t> id_808 {  id_807  };
                                            Pointer let_res_809;
                                            {
                                              Vec<1, uint32_t> leb128_sz_759 { id_808 };
                                              Vec<1, Pointer> id_810 {  ssum_dst_758  };
                                              Pointer let_res_811;
                                              {
                                                Vec<1, Pointer> leb128_ptr_760 { id_810 };
                                                bool while_flag_812 { true };
                                                do {
                                                  uint8_t id_813 { 0 };
                                                  uint8_t id_814 { 0 };
                                                  Pointer id_815 { leb128_ptr_760[id_814] };
                                                  uint32_t id_816 { 128U };
                                                  uint8_t id_817 { 0 };
                                                  uint32_t id_818 { leb128_sz_759[id_817] };
                                                  bool id_819 { bool(id_816 > id_818) };
                                                  uint8_t choose_res_820;
                                                  if (id_819) {
                                                    uint8_t id_821 { 0 };
                                                    uint32_t id_822 { leb128_sz_759[id_821] };
                                                    uint8_t id_823 { uint8_t(id_822) };
                                                    choose_res_820 = id_823;
                                                  } else {
                                                    uint8_t id_824 { 0 };
                                                    uint32_t id_825 { leb128_sz_759[id_824] };
                                                    uint8_t id_826 { uint8_t(id_825) };
                                                    uint8_t id_827 { 128 };
                                                    uint8_t id_828 { uint8_t(id_826 | id_827) };
                                                    choose_res_820 = id_828;
                                                  }
                                                  Pointer id_829 { id_815.writeU8(choose_res_820) };
                                                  Void id_830 { ((void)(leb128_ptr_760[id_813] = id_829), VOID) };
                                                  (void)id_830;
                                                  uint8_t id_831 { 0 };
                                                  uint8_t id_832 { 0 };
                                                  uint32_t id_833 { leb128_sz_759[id_832] };
                                                  uint8_t id_834 { 7 };
                                                  uint32_t id_835 { uint32_t(id_833 >> id_834) };
                                                  Void id_836 { ((void)(leb128_sz_759[id_831] = id_835), VOID) };
                                                  (void)id_836;
                                                  uint8_t id_837 { 0 };
                                                  uint32_t id_838 { leb128_sz_759[id_837] };
                                                  uint32_t id_839 { 0U };
                                                  bool id_840 { bool(id_838 > id_839) };
                                                  while_flag_812 = id_840;
                                                  if (while_flag_812) {
                                                    (void)VOID;
                                                  }
                                                } while (while_flag_812);
                                                (void)VOID;
                                                uint8_t id_841 { 0 };
                                                Pointer id_842 { leb128_ptr_760[id_841] };
                                                let_res_811 = id_842;
                                              }
                                              let_res_809 = let_res_811;
                                            }
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_843 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_844 { std::get<1>(id_843) };
                                            std::string id_845 { std::get<1 /* Inhibition */>(id_844) };
                                            Bytes id_846 { id_845 };
                                            Pointer id_847 { let_res_809.writeBytes(id_846) };
                                            choose_res_753 = id_847;
                                          }
                                          let_res_747 = choose_res_753;
                                        }
                                        let_res_742 = let_res_747;
                                      }
                                      choose_res_737 = let_res_742;
                                    } else {
                                      uint16_t id_848 { 15 };
                                      bool id_849 { bool(label1_743 == id_848) };
                                      Void id_850 { ((void)(assert(id_849)), VOID) };
                                      (void)id_850;
                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_851 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_852 { std::get<0>(id_851) };
                                      uint32_t id_853 { (uint32_t)id_852.size() };
                                      Vec<1, uint32_t> id_854 {  id_853  };
                                      Pointer let_res_855;
                                      {
                                        Vec<1, uint32_t> leb128_sz_745 { id_854 };
                                        Vec<1, Pointer> id_856 {  ssum_dst_744  };
                                        Pointer let_res_857;
                                        {
                                          Vec<1, Pointer> leb128_ptr_746 { id_856 };
                                          bool while_flag_858 { true };
                                          do {
                                            uint8_t id_859 { 0 };
                                            uint8_t id_860 { 0 };
                                            Pointer id_861 { leb128_ptr_746[id_860] };
                                            uint32_t id_862 { 128U };
                                            uint8_t id_863 { 0 };
                                            uint32_t id_864 { leb128_sz_745[id_863] };
                                            bool id_865 { bool(id_862 > id_864) };
                                            uint8_t choose_res_866;
                                            if (id_865) {
                                              uint8_t id_867 { 0 };
                                              uint32_t id_868 { leb128_sz_745[id_867] };
                                              uint8_t id_869 { uint8_t(id_868) };
                                              choose_res_866 = id_869;
                                            } else {
                                              uint8_t id_870 { 0 };
                                              uint32_t id_871 { leb128_sz_745[id_870] };
                                              uint8_t id_872 { uint8_t(id_871) };
                                              uint8_t id_873 { 128 };
                                              uint8_t id_874 { uint8_t(id_872 | id_873) };
                                              choose_res_866 = id_874;
                                            }
                                            Pointer id_875 { id_861.writeU8(choose_res_866) };
                                            Void id_876 { ((void)(leb128_ptr_746[id_859] = id_875), VOID) };
                                            (void)id_876;
                                            uint8_t id_877 { 0 };
                                            uint8_t id_878 { 0 };
                                            uint32_t id_879 { leb128_sz_745[id_878] };
                                            uint8_t id_880 { 7 };
                                            uint32_t id_881 { uint32_t(id_879 >> id_880) };
                                            Void id_882 { ((void)(leb128_sz_745[id_877] = id_881), VOID) };
                                            (void)id_882;
                                            uint8_t id_883 { 0 };
                                            uint32_t id_884 { leb128_sz_745[id_883] };
                                            uint32_t id_885 { 0U };
                                            bool id_886 { bool(id_884 > id_885) };
                                            while_flag_858 = id_886;
                                            if (while_flag_858) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_858);
                                          (void)VOID;
                                          uint8_t id_887 { 0 };
                                          Pointer id_888 { leb128_ptr_746[id_887] };
                                          let_res_857 = id_888;
                                        }
                                        let_res_855 = let_res_857;
                                      }
                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_889 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_890 { std::get<0>(id_889) };
                                      Bytes id_891 { id_890 };
                                      Pointer id_892 { let_res_855.writeBytes(id_891) };
                                      Pointer let_res_893;
                                      {
                                        Pointer stup_dst_747 { id_892 };
                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_894 { std::get<15 /* Incidents */>((*p_0)) };
                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_895 { std::get<1>(id_894) };
                                        uint16_t id_896 { uint16_t(id_895.index()) };
                                        Pointer let_res_897;
                                        {
                                          uint16_t label1_748 { id_896 };
                                          Pointer id_898 { stup_dst_747.writeU16Le(label1_748) };
                                          Pointer let_res_899;
                                          {
                                            Pointer ssum_dst_749 { id_898 };
                                            uint16_t id_900 { 0 };
                                            bool id_901 { bool(id_900 == label1_748) };
                                            Pointer choose_res_902;
                                            if (id_901) {
                                              choose_res_902 = ssum_dst_749;
                                            } else {
                                              uint16_t id_903 { 1 };
                                              bool id_904 { bool(id_903 == label1_748) };
                                              Pointer choose_res_905;
                                              if (id_904) {
                                                choose_res_905 = ssum_dst_749;
                                              } else {
                                                uint16_t id_906 { 2 };
                                                bool id_907 { bool(id_906 == label1_748) };
                                                Pointer choose_res_908;
                                                if (id_907) {
                                                  choose_res_908 = ssum_dst_749;
                                                } else {
                                                  uint16_t id_909 { 3 };
                                                  bool id_910 { bool(id_909 == label1_748) };
                                                  Pointer choose_res_911;
                                                  if (id_910) {
                                                    choose_res_911 = ssum_dst_749;
                                                  } else {
                                                    uint16_t id_912 { 4 };
                                                    bool id_913 { bool(id_912 == label1_748) };
                                                    Pointer choose_res_914;
                                                    if (id_913) {
                                                      choose_res_914 = ssum_dst_749;
                                                    } else {
                                                      uint16_t id_915 { 5 };
                                                      bool id_916 { bool(id_915 == label1_748) };
                                                      Pointer choose_res_917;
                                                      if (id_916) {
                                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_918 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_919 { std::get<1>(id_918) };
                                                        ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_920 { std::get<5 /* Dialogs */>(id_919) };
                                                        std::string id_921 { std::get<0>(id_920) };
                                                        uint32_t id_922 { (uint32_t)id_921.size() };
                                                        Vec<1, uint32_t> id_923 {  id_922  };
                                                        Pointer let_res_924;
                                                        {
                                                          Vec<1, uint32_t> leb128_sz_751 { id_923 };
                                                          Vec<1, Pointer> id_925 {  ssum_dst_749  };
                                                          Pointer let_res_926;
                                                          {
                                                            Vec<1, Pointer> leb128_ptr_752 { id_925 };
                                                            bool while_flag_927 { true };
                                                            do {
                                                              uint8_t id_928 { 0 };
                                                              uint8_t id_929 { 0 };
                                                              Pointer id_930 { leb128_ptr_752[id_929] };
                                                              uint32_t id_931 { 128U };
                                                              uint8_t id_932 { 0 };
                                                              uint32_t id_933 { leb128_sz_751[id_932] };
                                                              bool id_934 { bool(id_931 > id_933) };
                                                              uint8_t choose_res_935;
                                                              if (id_934) {
                                                                uint8_t id_936 { 0 };
                                                                uint32_t id_937 { leb128_sz_751[id_936] };
                                                                uint8_t id_938 { uint8_t(id_937) };
                                                                choose_res_935 = id_938;
                                                              } else {
                                                                uint8_t id_939 { 0 };
                                                                uint32_t id_940 { leb128_sz_751[id_939] };
                                                                uint8_t id_941 { uint8_t(id_940) };
                                                                uint8_t id_942 { 128 };
                                                                uint8_t id_943 { uint8_t(id_941 | id_942) };
                                                                choose_res_935 = id_943;
                                                              }
                                                              Pointer id_944 { id_930.writeU8(choose_res_935) };
                                                              Void id_945 { ((void)(leb128_ptr_752[id_928] = id_944), VOID) };
                                                              (void)id_945;
                                                              uint8_t id_946 { 0 };
                                                              uint8_t id_947 { 0 };
                                                              uint32_t id_948 { leb128_sz_751[id_947] };
                                                              uint8_t id_949 { 7 };
                                                              uint32_t id_950 { uint32_t(id_948 >> id_949) };
                                                              Void id_951 { ((void)(leb128_sz_751[id_946] = id_950), VOID) };
                                                              (void)id_951;
                                                              uint8_t id_952 { 0 };
                                                              uint32_t id_953 { leb128_sz_751[id_952] };
                                                              uint32_t id_954 { 0U };
                                                              bool id_955 { bool(id_953 > id_954) };
                                                              while_flag_927 = id_955;
                                                              if (while_flag_927) {
                                                                (void)VOID;
                                                              }
                                                            } while (while_flag_927);
                                                            (void)VOID;
                                                            uint8_t id_956 { 0 };
                                                            Pointer id_957 { leb128_ptr_752[id_956] };
                                                            let_res_926 = id_957;
                                                          }
                                                          let_res_924 = let_res_926;
                                                        }
                                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_958 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_959 { std::get<1>(id_958) };
                                                        ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_960 { std::get<5 /* Dialogs */>(id_959) };
                                                        std::string id_961 { std::get<0>(id_960) };
                                                        Bytes id_962 { id_961 };
                                                        Pointer id_963 { let_res_924.writeBytes(id_962) };
                                                        Pointer let_res_964;
                                                        {
                                                          Pointer stup_dst_753 { id_963 };
                                                          ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_965 { std::get<15 /* Incidents */>((*p_0)) };
                                                          ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_966 { std::get<1>(id_965) };
                                                          ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_967 { std::get<5 /* Dialogs */>(id_966) };
                                                          ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_968 { std::get<1>(id_967) };
                                                          uint16_t id_969 { uint16_t(id_968.index()) };
                                                          Pointer let_res_970;
                                                          {
                                                            uint16_t label1_754 { id_969 };
                                                            Pointer id_971 { stup_dst_753.writeU16Le(label1_754) };
                                                            Pointer let_res_972;
                                                            {
                                                              Pointer ssum_dst_755 { id_971 };
                                                              uint16_t id_973 { 0 };
                                                              bool id_974 { bool(id_973 == label1_754) };
                                                              Pointer choose_res_975;
                                                              if (id_974) {
                                                                choose_res_975 = ssum_dst_755;
                                                              } else {
                                                                uint16_t id_976 { 1 };
                                                                bool id_977 { bool(id_976 == label1_754) };
                                                                Pointer choose_res_978;
                                                                if (id_977) {
                                                                  choose_res_978 = ssum_dst_755;
                                                                } else {
                                                                  uint16_t id_979 { 2 };
                                                                  bool id_980 { bool(id_979 == label1_754) };
                                                                  Pointer choose_res_981;
                                                                  if (id_980) {
                                                                    choose_res_981 = ssum_dst_755;
                                                                  } else {
                                                                    uint16_t id_982 { 3 };
                                                                    bool id_983 { bool(id_982 == label1_754) };
                                                                    Pointer choose_res_984;
                                                                    if (id_983) {
                                                                      choose_res_984 = ssum_dst_755;
                                                                    } else {
                                                                      uint16_t id_985 { 4 };
                                                                      bool id_986 { bool(id_985 == label1_754) };
                                                                      Pointer choose_res_987;
                                                                      if (id_986) {
                                                                        choose_res_987 = ssum_dst_755;
                                                                      } else {
                                                                        uint16_t id_988 { 5 };
                                                                        bool id_989 { bool(id_988 == label1_754) };
                                                                        Pointer choose_res_990;
                                                                        if (id_989) {
                                                                          choose_res_990 = ssum_dst_755;
                                                                        } else {
                                                                          uint16_t id_991 { 6 };
                                                                          bool id_992 { bool(label1_754 == id_991) };
                                                                          Void id_993 { ((void)(assert(id_992)), VOID) };
                                                                          (void)id_993;
                                                                          choose_res_990 = ssum_dst_755;
                                                                        }
                                                                        choose_res_987 = choose_res_990;
                                                                      }
                                                                      choose_res_984 = choose_res_987;
                                                                    }
                                                                    choose_res_981 = choose_res_984;
                                                                  }
                                                                  choose_res_978 = choose_res_981;
                                                                }
                                                                choose_res_975 = choose_res_978;
                                                              }
                                                              let_res_972 = choose_res_975;
                                                            }
                                                            let_res_970 = let_res_972;
                                                          }
                                                          let_res_964 = let_res_970;
                                                        }
                                                        choose_res_917 = let_res_964;
                                                      } else {
                                                        uint16_t id_994 { 6 };
                                                        bool id_995 { bool(label1_748 == id_994) };
                                                        Void id_996 { ((void)(assert(id_995)), VOID) };
                                                        (void)id_996;
                                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_997 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_998 { std::get<1>(id_997) };
                                                        ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 id_999 { std::get<6 /* Journal */>(id_998) };
                                                        double id_1000 { std::get<0>(id_999) };
                                                        uint64_t id_1001 { qword_of_float(id_1000) };
                                                        Pointer id_1002 { ssum_dst_749.writeU64Le(id_1001) };
                                                        Pointer let_res_1003;
                                                        {
                                                          Pointer stup_dst_750 { id_1002 };
                                                          ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1004 { std::get<15 /* Incidents */>((*p_0)) };
                                                          ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1005 { std::get<1>(id_1004) };
                                                          ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 id_1006 { std::get<6 /* Journal */>(id_1005) };
                                                          uint32_t id_1007 { std::get<1>(id_1006) };
                                                          Pointer id_1008 { stup_dst_750.writeU32Le(id_1007) };
                                                          let_res_1003 = id_1008;
                                                        }
                                                        choose_res_917 = let_res_1003;
                                                      }
                                                      choose_res_914 = choose_res_917;
                                                    }
                                                    choose_res_911 = choose_res_914;
                                                  }
                                                  choose_res_908 = choose_res_911;
                                                }
                                                choose_res_905 = choose_res_908;
                                              }
                                              choose_res_902 = choose_res_905;
                                            }
                                            let_res_899 = choose_res_902;
                                          }
                                          let_res_897 = let_res_899;
                                        }
                                        let_res_893 = let_res_897;
                                      }
                                      choose_res_737 = let_res_893;
                                    }
                                    choose_res_734 = choose_res_737;
                                  }
                                  choose_res_685 = choose_res_734;
                                }
                                choose_res_674 = choose_res_685;
                              }
                              choose_res_671 = choose_res_674;
                            }
                            choose_res_657 = choose_res_671;
                          }
                          choose_res_652 = choose_res_657;
                        }
                        choose_res_593 = choose_res_652;
                      }
                      choose_res_529 = choose_res_593;
                    }
                    choose_res_227 = choose_res_529;
                  }
                  choose_res_224 = choose_res_227;
                }
                choose_res_174 = choose_res_224;
              }
              choose_res_131 = choose_res_174;
            }
            choose_res_128 = choose_res_131;
          }
          choose_res_125 = choose_res_128;
        }
        let_res_122 = choose_res_125;
      }
      let_res_120 = let_res_122;
    }
    return let_res_120;
  }
   };
  return fun118;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Widgets U32]") (seq (assert (eq (label-of (param 0)) (u16 0))) (size 6)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> per_dash_key_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> fun1009 { [&fun1009](std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  p_0) {
    uint16_t id_1010 { uint16_t((*p_0).index()) };
    uint16_t id_1011 { 0 };
    bool id_1012 { bool(id_1010 == id_1011) };
    Void id_1013 { ((void)(assert(id_1012)), VOID) };
    (void)id_1013;
    Size id_1014 { 6UL };
    return id_1014;
  }
   };
  return fun1009;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> per_dash_key_sersize_of_row_binary(per_dash_key_sersize_of_row_binary_init());

/* 
    (fun ("[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_657" (make-vec (string-length (get-alt "Response" (param 0))))
              (let "lebsz_ref_658" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_657")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_658")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_658") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_658")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_658")))))) 
            (size-of-u32 (string-length (get-alt "Response" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "per_dash_key-sersize-of-row-binary") (get-alt "Scratchpad" (param 0)))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> per_client_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> fun1015 { [&fun1015](std::shared_ptr<::dessser::gen::sync_key::per_client>  p_0) {
    uint16_t id_1016 { 0 };
    uint16_t id_1017 { uint16_t((*p_0).index()) };
    bool id_1018 { bool(id_1016 == id_1017) };
    Size choose_res_1019;
    if (id_1018) {
      Size id_1020 { 2UL };
      std::string id_1021 { std::get<0 /* Response */>((*p_0)) };
      uint32_t id_1022 { (uint32_t)id_1021.size() };
      Vec<1, uint32_t> id_1023 {  id_1022  };
      Size let_res_1024;
      {
        Vec<1, uint32_t> n_ref_657 { id_1023 };
        uint32_t id_1025 { 1U };
        Vec<1, uint32_t> id_1026 {  id_1025  };
        Size let_res_1027;
        {
          Vec<1, uint32_t> lebsz_ref_658 { id_1026 };
          bool while_flag_1028 { true };
          do {
            uint8_t id_1029 { 0 };
            uint32_t id_1030 { n_ref_657[id_1029] };
            uint8_t id_1031 { 0 };
            uint32_t id_1032 { lebsz_ref_658[id_1031] };
            uint8_t id_1033 { 7 };
            uint32_t id_1034 { uint32_t(id_1032 << id_1033) };
            bool id_1035 { bool(id_1030 >= id_1034) };
            while_flag_1028 = id_1035;
            if (while_flag_1028) {
              uint8_t id_1036 { 0 };
              uint8_t id_1037 { 0 };
              uint32_t id_1038 { lebsz_ref_658[id_1037] };
              uint32_t id_1039 { 1U };
              uint32_t id_1040 { uint32_t(id_1038 + id_1039) };
              Void id_1041 { ((void)(lebsz_ref_658[id_1036] = id_1040), VOID) };
              (void)id_1041;
            }
          } while (while_flag_1028);
          (void)VOID;
          uint8_t id_1042 { 0 };
          uint32_t id_1043 { lebsz_ref_658[id_1042] };
          Size id_1044 { Size(id_1043) };
          let_res_1027 = id_1044;
        }
        let_res_1024 = let_res_1027;
      }
      std::string id_1045 { std::get<0 /* Response */>((*p_0)) };
      uint32_t id_1046 { (uint32_t)id_1045.size() };
      Size id_1047 { Size(id_1046) };
      Size id_1048 { Size(let_res_1024 + id_1047) };
      Size id_1049 { Size(id_1020 + id_1048) };
      choose_res_1019 = id_1049;
    } else {
      uint16_t id_1050 { uint16_t((*p_0).index()) };
      uint16_t id_1051 { 1 };
      bool id_1052 { bool(id_1050 == id_1051) };
      Void id_1053 { ((void)(assert(id_1052)), VOID) };
      (void)id_1053;
      Size id_1054 { 2UL };
      std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1055 { std::get<1 /* Scratchpad */>((*p_0)) };
      Size id_1056 { per_dash_key_sersize_of_row_binary(id_1055) };
      Size id_1057 { Size(id_1054 + id_1056) };
      choose_res_1019 = id_1057;
    }
    return choose_res_1019;
  }
   };
  return fun1015;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> per_client_sersize_of_row_binary(per_client_sersize_of_row_binary_init());

/* 
    (fun ("[Subscriber STRING | LastTuple U32]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_652" (make-vec (string-length (get-alt "Subscriber" (param 0))))
              (let "lebsz_ref_653" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_652")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_653")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_653") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_653")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_653")))))) 
            (size-of-u32 (string-length (get-alt "Subscriber" (param 0)))))) 
        (seq (assert (eq (label-of (param 0)) (u16 1))) (size 6))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> per_tail_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> fun1058 { [&fun1058](std::shared_ptr<::dessser::gen::sync_key::per_tail>  p_0) {
    uint16_t id_1059 { 0 };
    uint16_t id_1060 { uint16_t((*p_0).index()) };
    bool id_1061 { bool(id_1059 == id_1060) };
    Size choose_res_1062;
    if (id_1061) {
      Size id_1063 { 2UL };
      std::string id_1064 { std::get<0 /* Subscriber */>((*p_0)) };
      uint32_t id_1065 { (uint32_t)id_1064.size() };
      Vec<1, uint32_t> id_1066 {  id_1065  };
      Size let_res_1067;
      {
        Vec<1, uint32_t> n_ref_652 { id_1066 };
        uint32_t id_1068 { 1U };
        Vec<1, uint32_t> id_1069 {  id_1068  };
        Size let_res_1070;
        {
          Vec<1, uint32_t> lebsz_ref_653 { id_1069 };
          bool while_flag_1071 { true };
          do {
            uint8_t id_1072 { 0 };
            uint32_t id_1073 { n_ref_652[id_1072] };
            uint8_t id_1074 { 0 };
            uint32_t id_1075 { lebsz_ref_653[id_1074] };
            uint8_t id_1076 { 7 };
            uint32_t id_1077 { uint32_t(id_1075 << id_1076) };
            bool id_1078 { bool(id_1073 >= id_1077) };
            while_flag_1071 = id_1078;
            if (while_flag_1071) {
              uint8_t id_1079 { 0 };
              uint8_t id_1080 { 0 };
              uint32_t id_1081 { lebsz_ref_653[id_1080] };
              uint32_t id_1082 { 1U };
              uint32_t id_1083 { uint32_t(id_1081 + id_1082) };
              Void id_1084 { ((void)(lebsz_ref_653[id_1079] = id_1083), VOID) };
              (void)id_1084;
            }
          } while (while_flag_1071);
          (void)VOID;
          uint8_t id_1085 { 0 };
          uint32_t id_1086 { lebsz_ref_653[id_1085] };
          Size id_1087 { Size(id_1086) };
          let_res_1070 = id_1087;
        }
        let_res_1067 = let_res_1070;
      }
      std::string id_1088 { std::get<0 /* Subscriber */>((*p_0)) };
      uint32_t id_1089 { (uint32_t)id_1088.size() };
      Size id_1090 { Size(id_1089) };
      Size id_1091 { Size(let_res_1067 + id_1090) };
      Size id_1092 { Size(id_1063 + id_1091) };
      choose_res_1062 = id_1092;
    } else {
      uint16_t id_1093 { uint16_t((*p_0).index()) };
      uint16_t id_1094 { 1 };
      bool id_1095 { bool(id_1093 == id_1094) };
      Void id_1096 { ((void)(assert(id_1095)), VOID) };
      (void)id_1096;
      Size id_1097 { 6UL };
      choose_res_1062 = id_1097;
    }
    return choose_res_1062;
  }
   };
  return fun1058;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> per_tail_sersize_of_row_binary(per_tail_sersize_of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]")
      (let "label2_659" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_659")) (size 2)
          (if (eq (u16 1) (identifier "label2_659")) (size 2)
            (if (eq (u16 2) (identifier "label2_659"))
              (add (size 2)
                (add
                  (let "n_ref_731" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "lebsz_ref_732" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_731")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_732")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_732") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_732")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_732")))))) 
                  (size-of-u32 (string-length (get-alt "Versions" (param 0))))))
              (if (eq (u16 3) (identifier "label2_659"))
                (let "sz_726" (add (size 2) (apply (ext-identifier src_path sersize-of-row-binary) (get-item 0 (get-alt "Sources" (param 0)))))
                  (add (identifier "sz_726")
                    (add
                      (let "n_ref_728" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "lebsz_ref_729" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_728")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_729")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_729") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_729")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_729")))))) 
                      (size-of-u32 (string-length (get-item 1 (get-alt "Sources" (param 0))))))))
                (if (eq (u16 4) (identifier "label2_659")) (size 2)
                  (if (eq (u16 5) (identifier "label2_659"))
                    (let "sz_702" (add (size 2) (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (get-alt "PerSite" (param 0)))))
                      (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerSite" (param 0))))) 
                        (add (identifier "sz_702") (size 2))
                        (if (eq (u16 1) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                          (let "sz_723"
                            (add (add (identifier "sz_702") (size 2))
                              (add
                                (let "n_ref_721" (make-vec (string-length (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                  (let "lebsz_ref_722" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_721")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_722")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_722") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_722")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_722")))))) 
                                (size-of-u32 (string-length (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                            (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0))))))) 
                              (add (identifier "sz_723") (size 2)) (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 1))) (add (identifier "sz_723") (size 2)))))
                          (if (eq (u16 2) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                            (let "sz_711" (add (add (identifier "sz_702") (size 2)) (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 0 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))
                              (let "label2_712" (label-of (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))
                                (if (eq (u16 0) (identifier "label2_712")) 
                                  (add (identifier "sz_711") (size 2))
                                  (if (eq (u16 1) (identifier "label2_712")) 
                                    (add (identifier "sz_711") (size 2))
                                    (if (eq (u16 2) (identifier "label2_712")) 
                                      (add (identifier "sz_711") (size 2))
                                      (if (eq (u16 3) (identifier "label2_712")) 
                                        (add (identifier "sz_711") (size 2))
                                        (if (eq (u16 4) (identifier "label2_712")) 
                                          (add (identifier "sz_711") (size 2))
                                          (if (eq (u16 5) (identifier "label2_712")) 
                                            (add (identifier "sz_711") (size 2))
                                            (if (eq (u16 6) (identifier "label2_712"))
                                              (let "sz_717"
                                                (add (add (identifier "sz_711") (size 2))
                                                  (add
                                                    (let "n_ref_715" 
                                                      (make-vec (string-length (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                                      (let "lebsz_ref_716" 
                                                        (make-vec (u32 1))
                                                        (seq
                                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_715")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_716")) (u8 7)))
                                                            (set-vec (u8 0) (identifier "lebsz_ref_716") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_716")) (u32 1))))
                                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_716"))))))
                                                    (size-of-u32 (string-length (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))))
                                                (let "label2_718" (label-of (get-item 1 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))))
                                                  (if (eq (u16 0) (identifier "label2_718")) 
                                                    (add (identifier "sz_717") (size 2))
                                                    (if (eq (u16 1) (identifier "label2_718")) 
                                                      (add (identifier "sz_717") (size 2))
                                                      (if (eq (u16 2) (identifier "label2_718")) 
                                                        (add (identifier "sz_717") (size 2))
                                                        (if (eq (u16 3) (identifier "label2_718")) 
                                                          (add (identifier "sz_717") (size 2))
                                                          (if (eq (u16 4) (identifier "label2_718")) 
                                                            (add (identifier "sz_717") (size 2))
                                                            (if (eq (u16 5) (identifier "label2_718")) 
                                                              (add (identifier "sz_717") (size 2))
                                                              (if (eq (u16 6) (identifier "label2_718")) 
                                                                (add (identifier "sz_717") (size 2)) 
                                                                (seq (assert (eq (identifier "label2_718") (u16 7))) (add (identifier "sz_717") (size 2))))))))))))
                                              (if (eq (u16 7) (identifier "label2_712")) 
                                                (add (add (identifier "sz_711") (size 2)) (size 4)) 
                                                (seq (assert (eq (identifier "label2_712") (u16 8))) (add (identifier "sz_711") (size 2)))))))))))))
                            (seq (assert (eq (label-of (get-item 1 (get-alt "PerSite" (param 0)))) (u16 3)))
                              (let "sz_708"
                                (add (add (identifier "sz_702") (size 2))
                                  (add
                                    (let "n_ref_706" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                      (let "lebsz_ref_707" (make-vec (u32 1))
                                        (seq
                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_706")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_707")) (u8 7)))
                                            (set-vec (u8 0) (identifier "lebsz_ref_707") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_707")) (u32 1)))) 
                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_707")))))) 
                                    (size-of-u32 (string-length (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 0))) (add (identifier "sz_708") (size 2)))))))))
                    (if (eq (u16 6) (identifier "label2_659"))
                      (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                        (size 4)
                        (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                          (size 4)
                          (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                            (add (size 4)
                              (add
                                (let "n_ref_699" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                  (let "lebsz_ref_700" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_699")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_700")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_700") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_700")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_700")))))) 
                                (size-of-u32 (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0))))))))))
                      (if (eq (u16 7) (identifier "label2_659"))
                        (let "sz_696"
                          (let "sz_692"
                            (let "sz_691" (add (size 2) (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (get-alt "Tails" (param 0)))))
                              (add (identifier "sz_691") (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 1 (get-alt "Tails" (param 0))))))
                            (add (identifier "sz_692")
                              (add
                                (let "n_ref_694" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "lebsz_ref_695" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_694")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_695")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_695") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_695")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_695")))))) 
                                (size-of-u32 (string-length (get-item 2 (get-alt "Tails" (param 0)))))))) 
                          (add (identifier "sz_696") (apply (identifier "per_tail-sersize-of-row-binary") (get-item 3 (get-alt "Tails" (param 0))))))
                        (if (eq (u16 8) (identifier "label2_659")) (size 4)
                          (if (eq (u16 9) (identifier "label2_659"))
                            (if (is-null (get-alt "Error" (param 0))) (size 3) (add (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (force (get-alt "Error" (param 0))))) (size 1)))
                            (if (eq (u16 10) (identifier "label2_659")) 
                              (size 2)
                              (if (eq (u16 11) (identifier "label2_659"))
                                (let "sz_689" (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (get-item 0 (get-alt "PerClient" (param 0)))))
                                  (add (identifier "sz_689") (apply (identifier "per_client-sersize-of-row-binary") (get-item 1 (get-alt "PerClient" (param 0))))))
                                (if (eq (u16 12) (identifier "label2_659"))
                                  (let "sz_687"
                                    (add (size 2)
                                      (add
                                        (let "n_ref_685" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "lebsz_ref_686" (make-vec (u32 1))
                                            (seq
                                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_685")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_686")) (u8 7)))
                                                (set-vec (u8 0) (identifier "lebsz_ref_686") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_686")) (u32 1)))) 
                                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_686")))))) 
                                        (size-of-u32 (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))))
                                    (add (identifier "sz_687") (apply (identifier "per_dash_key-sersize-of-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))))))
                                  (if (eq (u16 13) (identifier "label2_659")) 
                                    (size 2)
                                    (if (eq (u16 14) (identifier "label2_659"))
                                      (let "sz_675" (add (size 2) (apply (ext-identifier team_name sersize-of-row-binary) (get-item 0 (get-alt "Teams" (param 0)))))
                                        (if (eq (u16 0) (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                          (add (add (identifier "sz_675") (size 2))
                                            (add
                                              (let "n_ref_681" (make-vec (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                                (let "lebsz_ref_682" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_681")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_682")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_682") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_682")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_682")))))) 
                                              (size-of-u32 (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))))
                                          (seq (assert (eq (label-of (get-item 1 (get-alt "Teams" (param 0)))) (u16 1)))
                                            (add (add (identifier "sz_675") (size 2))
                                              (add
                                                (let "n_ref_678" (make-vec (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))
                                                  (let "lebsz_ref_679" 
                                                    (make-vec (u32 1))
                                                    (seq
                                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_678")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_679")) (u8 7)))
                                                        (set-vec (u8 0) (identifier "lebsz_ref_679") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_679")) (u32 1)))) 
                                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_679")))))) 
                                                (size-of-u32 (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0)))))))))))
                                      (seq (assert (eq (identifier "label2_659") (u16 15)))
                                        (let "sz_664"
                                          (add (size 2)
                                            (add
                                              (let "n_ref_662" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "lebsz_ref_663" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_662")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_663")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_663") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_663")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_663")))))) 
                                              (size-of-u32 (string-length (get-item 0 (get-alt "Incidents" (param 0)))))))
                                          (let "label2_665" (label-of (get-item 1 (get-alt "Incidents" (param 0))))
                                            (if (eq (u16 0) (identifier "label2_665")) 
                                              (add (identifier "sz_664") (size 2))
                                              (if (eq (u16 1) (identifier "label2_665")) 
                                                (add (identifier "sz_664") (size 2))
                                                (if (eq (u16 2) (identifier "label2_665")) 
                                                  (add (identifier "sz_664") (size 2))
                                                  (if (eq (u16 3) (identifier "label2_665")) 
                                                    (add (identifier "sz_664") (size 2))
                                                    (if (eq (u16 4) (identifier "label2_665")) 
                                                      (add (identifier "sz_664") (size 2))
                                                      (if (eq (u16 5) (identifier "label2_665"))
                                                        (let "sz_672"
                                                          (add (add (identifier "sz_664") (size 2))
                                                            (add
                                                              (let "n_ref_670" 
                                                                (make-vec (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                (let "lebsz_ref_671" 
                                                                  (make-vec (u32 1))
                                                                  (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_670")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_671")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_671") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_671")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_671"))))))
                                                              (size-of-u32 (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))))
                                                          (let "label2_673" 
                                                            (label-of (get-item 1 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0))))))
                                                            (if (eq (u16 0) (identifier "label2_673")) 
                                                              (add (identifier "sz_672") (size 2))
                                                              (if (eq (u16 1) (identifier "label2_673")) 
                                                                (add (identifier "sz_672") (size 2))
                                                                (if (eq (u16 2) (identifier "label2_673")) 
                                                                  (add (identifier "sz_672") (size 2))
                                                                  (if 
                                                                    (eq (u16 3) (identifier "label2_673")) 
                                                                    (add (identifier "sz_672") (size 2))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "label2_673")) 
                                                                    (add (identifier "sz_672") (size 2))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "label2_673")) 
                                                                    (add (identifier "sz_672") (size 2)) 
                                                                    (seq (assert (eq (identifier "label2_673") (u16 6))) (add (identifier "sz_672") (size 2)))))))))))
                                                        (seq (assert (eq (identifier "label2_665") (u16 6))) (add (add (add (identifier "sz_664") (size 2)) (size 8)) (size 4)))))))))))))))))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> fun1098 { [&fun1098](std::shared_ptr<::dessser::gen::sync_key::t>  p_0) {
    uint16_t id_1099 { uint16_t((*p_0).index()) };
    Size let_res_1100;
    {
      uint16_t label2_659 { id_1099 };
      uint16_t id_1101 { 0 };
      bool id_1102 { bool(id_1101 == label2_659) };
      Size choose_res_1103;
      if (id_1102) {
        Size id_1104 { 2UL };
        choose_res_1103 = id_1104;
      } else {
        uint16_t id_1105 { 1 };
        bool id_1106 { bool(id_1105 == label2_659) };
        Size choose_res_1107;
        if (id_1106) {
          Size id_1108 { 2UL };
          choose_res_1107 = id_1108;
        } else {
          uint16_t id_1109 { 2 };
          bool id_1110 { bool(id_1109 == label2_659) };
          Size choose_res_1111;
          if (id_1110) {
            Size id_1112 { 2UL };
            std::string id_1113 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1114 { (uint32_t)id_1113.size() };
            Vec<1, uint32_t> id_1115 {  id_1114  };
            Size let_res_1116;
            {
              Vec<1, uint32_t> n_ref_731 { id_1115 };
              uint32_t id_1117 { 1U };
              Vec<1, uint32_t> id_1118 {  id_1117  };
              Size let_res_1119;
              {
                Vec<1, uint32_t> lebsz_ref_732 { id_1118 };
                bool while_flag_1120 { true };
                do {
                  uint8_t id_1121 { 0 };
                  uint32_t id_1122 { n_ref_731[id_1121] };
                  uint8_t id_1123 { 0 };
                  uint32_t id_1124 { lebsz_ref_732[id_1123] };
                  uint8_t id_1125 { 7 };
                  uint32_t id_1126 { uint32_t(id_1124 << id_1125) };
                  bool id_1127 { bool(id_1122 >= id_1126) };
                  while_flag_1120 = id_1127;
                  if (while_flag_1120) {
                    uint8_t id_1128 { 0 };
                    uint8_t id_1129 { 0 };
                    uint32_t id_1130 { lebsz_ref_732[id_1129] };
                    uint32_t id_1131 { 1U };
                    uint32_t id_1132 { uint32_t(id_1130 + id_1131) };
                    Void id_1133 { ((void)(lebsz_ref_732[id_1128] = id_1132), VOID) };
                    (void)id_1133;
                  }
                } while (while_flag_1120);
                (void)VOID;
                uint8_t id_1134 { 0 };
                uint32_t id_1135 { lebsz_ref_732[id_1134] };
                Size id_1136 { Size(id_1135) };
                let_res_1119 = id_1136;
              }
              let_res_1116 = let_res_1119;
            }
            std::string id_1137 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1138 { (uint32_t)id_1137.size() };
            Size id_1139 { Size(id_1138) };
            Size id_1140 { Size(let_res_1116 + id_1139) };
            Size id_1141 { Size(id_1112 + id_1140) };
            choose_res_1111 = id_1141;
          } else {
            uint16_t id_1142 { 3 };
            bool id_1143 { bool(id_1142 == label2_659) };
            Size choose_res_1144;
            if (id_1143) {
              Size id_1145 { 2UL };
              auto fun1146 { dessser::gen::src_path::sersize_of_row_binary };
              ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_1147 { std::get<3 /* Sources */>((*p_0)) };
              dessser::gen::src_path::t_ext id_1148 { std::get<0>(id_1147) };
              Size id_1149 { fun1146(id_1148) };
              Size id_1150 { Size(id_1145 + id_1149) };
              Size let_res_1151;
              {
                Size sz_726 { id_1150 };
                ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_1152 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1153 { std::get<1>(id_1152) };
                uint32_t id_1154 { (uint32_t)id_1153.size() };
                Vec<1, uint32_t> id_1155 {  id_1154  };
                Size let_res_1156;
                {
                  Vec<1, uint32_t> n_ref_728 { id_1155 };
                  uint32_t id_1157 { 1U };
                  Vec<1, uint32_t> id_1158 {  id_1157  };
                  Size let_res_1159;
                  {
                    Vec<1, uint32_t> lebsz_ref_729 { id_1158 };
                    bool while_flag_1160 { true };
                    do {
                      uint8_t id_1161 { 0 };
                      uint32_t id_1162 { n_ref_728[id_1161] };
                      uint8_t id_1163 { 0 };
                      uint32_t id_1164 { lebsz_ref_729[id_1163] };
                      uint8_t id_1165 { 7 };
                      uint32_t id_1166 { uint32_t(id_1164 << id_1165) };
                      bool id_1167 { bool(id_1162 >= id_1166) };
                      while_flag_1160 = id_1167;
                      if (while_flag_1160) {
                        uint8_t id_1168 { 0 };
                        uint8_t id_1169 { 0 };
                        uint32_t id_1170 { lebsz_ref_729[id_1169] };
                        uint32_t id_1171 { 1U };
                        uint32_t id_1172 { uint32_t(id_1170 + id_1171) };
                        Void id_1173 { ((void)(lebsz_ref_729[id_1168] = id_1172), VOID) };
                        (void)id_1173;
                      }
                    } while (while_flag_1160);
                    (void)VOID;
                    uint8_t id_1174 { 0 };
                    uint32_t id_1175 { lebsz_ref_729[id_1174] };
                    Size id_1176 { Size(id_1175) };
                    let_res_1159 = id_1176;
                  }
                  let_res_1156 = let_res_1159;
                }
                ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_1177 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1178 { std::get<1>(id_1177) };
                uint32_t id_1179 { (uint32_t)id_1178.size() };
                Size id_1180 { Size(id_1179) };
                Size id_1181 { Size(let_res_1156 + id_1180) };
                Size id_1182 { Size(sz_726 + id_1181) };
                let_res_1151 = id_1182;
              }
              choose_res_1144 = let_res_1151;
            } else {
              uint16_t id_1183 { 4 };
              bool id_1184 { bool(id_1183 == label2_659) };
              Size choose_res_1185;
              if (id_1184) {
                Size id_1186 { 2UL };
                choose_res_1185 = id_1186;
              } else {
                uint16_t id_1187 { 5 };
                bool id_1188 { bool(id_1187 == label2_659) };
                Size choose_res_1189;
                if (id_1188) {
                  Size id_1190 { 2UL };
                  auto fun1191 { dessser::gen::site_name::sersize_of_row_binary };
                  ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1192 { std::get<5 /* PerSite */>((*p_0)) };
                  dessser::gen::site_name::t_ext id_1193 { std::get<0>(id_1192) };
                  Size id_1194 { fun1191(id_1193) };
                  Size id_1195 { Size(id_1190 + id_1194) };
                  Size let_res_1196;
                  {
                    Size sz_702 { id_1195 };
                    uint16_t id_1197 { 0 };
                    ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1198 { std::get<5 /* PerSite */>((*p_0)) };
                    ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1199 { std::get<1>(id_1198) };
                    uint16_t id_1200 { uint16_t(id_1199.index()) };
                    bool id_1201 { bool(id_1197 == id_1200) };
                    Size choose_res_1202;
                    if (id_1201) {
                      Size id_1203 { 2UL };
                      Size id_1204 { Size(sz_702 + id_1203) };
                      choose_res_1202 = id_1204;
                    } else {
                      uint16_t id_1205 { 1 };
                      ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1206 { std::get<5 /* PerSite */>((*p_0)) };
                      ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1207 { std::get<1>(id_1206) };
                      uint16_t id_1208 { uint16_t(id_1207.index()) };
                      bool id_1209 { bool(id_1205 == id_1208) };
                      Size choose_res_1210;
                      if (id_1209) {
                        Size id_1211 { 2UL };
                        Size id_1212 { Size(sz_702 + id_1211) };
                        ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1213 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1214 { std::get<1>(id_1213) };
                        ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1215 { std::get<1 /* PerService */>(id_1214) };
                        std::string id_1216 { std::get<0>(id_1215) };
                        uint32_t id_1217 { (uint32_t)id_1216.size() };
                        Vec<1, uint32_t> id_1218 {  id_1217  };
                        Size let_res_1219;
                        {
                          Vec<1, uint32_t> n_ref_721 { id_1218 };
                          uint32_t id_1220 { 1U };
                          Vec<1, uint32_t> id_1221 {  id_1220  };
                          Size let_res_1222;
                          {
                            Vec<1, uint32_t> lebsz_ref_722 { id_1221 };
                            bool while_flag_1223 { true };
                            do {
                              uint8_t id_1224 { 0 };
                              uint32_t id_1225 { n_ref_721[id_1224] };
                              uint8_t id_1226 { 0 };
                              uint32_t id_1227 { lebsz_ref_722[id_1226] };
                              uint8_t id_1228 { 7 };
                              uint32_t id_1229 { uint32_t(id_1227 << id_1228) };
                              bool id_1230 { bool(id_1225 >= id_1229) };
                              while_flag_1223 = id_1230;
                              if (while_flag_1223) {
                                uint8_t id_1231 { 0 };
                                uint8_t id_1232 { 0 };
                                uint32_t id_1233 { lebsz_ref_722[id_1232] };
                                uint32_t id_1234 { 1U };
                                uint32_t id_1235 { uint32_t(id_1233 + id_1234) };
                                Void id_1236 { ((void)(lebsz_ref_722[id_1231] = id_1235), VOID) };
                                (void)id_1236;
                              }
                            } while (while_flag_1223);
                            (void)VOID;
                            uint8_t id_1237 { 0 };
                            uint32_t id_1238 { lebsz_ref_722[id_1237] };
                            Size id_1239 { Size(id_1238) };
                            let_res_1222 = id_1239;
                          }
                          let_res_1219 = let_res_1222;
                        }
                        ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1240 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1241 { std::get<1>(id_1240) };
                        ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1242 { std::get<1 /* PerService */>(id_1241) };
                        std::string id_1243 { std::get<0>(id_1242) };
                        uint32_t id_1244 { (uint32_t)id_1243.size() };
                        Size id_1245 { Size(id_1244) };
                        Size id_1246 { Size(let_res_1219 + id_1245) };
                        Size id_1247 { Size(id_1212 + id_1246) };
                        Size let_res_1248;
                        {
                          Size sz_723 { id_1247 };
                          uint16_t id_1249 { 0 };
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1250 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1251 { std::get<1>(id_1250) };
                          ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1252 { std::get<1 /* PerService */>(id_1251) };
                          ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_1253 { std::get<1>(id_1252) };
                          uint16_t id_1254 { uint16_t(id_1253.index()) };
                          bool id_1255 { bool(id_1249 == id_1254) };
                          Size choose_res_1256;
                          if (id_1255) {
                            Size id_1257 { 2UL };
                            Size id_1258 { Size(sz_723 + id_1257) };
                            choose_res_1256 = id_1258;
                          } else {
                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1259 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1260 { std::get<1>(id_1259) };
                            ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1261 { std::get<1 /* PerService */>(id_1260) };
                            ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_1262 { std::get<1>(id_1261) };
                            uint16_t id_1263 { uint16_t(id_1262.index()) };
                            uint16_t id_1264 { 1 };
                            bool id_1265 { bool(id_1263 == id_1264) };
                            Void id_1266 { ((void)(assert(id_1265)), VOID) };
                            (void)id_1266;
                            Size id_1267 { 2UL };
                            Size id_1268 { Size(sz_723 + id_1267) };
                            choose_res_1256 = id_1268;
                          }
                          let_res_1248 = choose_res_1256;
                        }
                        choose_res_1210 = let_res_1248;
                      } else {
                        uint16_t id_1269 { 2 };
                        ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1270 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1271 { std::get<1>(id_1270) };
                        uint16_t id_1272 { uint16_t(id_1271.index()) };
                        bool id_1273 { bool(id_1269 == id_1272) };
                        Size choose_res_1274;
                        if (id_1273) {
                          Size id_1275 { 2UL };
                          Size id_1276 { Size(sz_702 + id_1275) };
                          auto fun1277 { dessser::gen::fq_name::sersize_of_row_binary };
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1278 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1279 { std::get<1>(id_1278) };
                          ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_1280 { std::get<2 /* PerWorker */>(id_1279) };
                          dessser::gen::fq_name::t_ext id_1281 { std::get<0>(id_1280) };
                          Size id_1282 { fun1277(id_1281) };
                          Size id_1283 { Size(id_1276 + id_1282) };
                          Size let_res_1284;
                          {
                            Size sz_711 { id_1283 };
                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1285 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1286 { std::get<1>(id_1285) };
                            ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_1287 { std::get<2 /* PerWorker */>(id_1286) };
                            ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_1288 { std::get<1>(id_1287) };
                            uint16_t id_1289 { uint16_t(id_1288.index()) };
                            Size let_res_1290;
                            {
                              uint16_t label2_712 { id_1289 };
                              uint16_t id_1291 { 0 };
                              bool id_1292 { bool(id_1291 == label2_712) };
                              Size choose_res_1293;
                              if (id_1292) {
                                Size id_1294 { 2UL };
                                Size id_1295 { Size(sz_711 + id_1294) };
                                choose_res_1293 = id_1295;
                              } else {
                                uint16_t id_1296 { 1 };
                                bool id_1297 { bool(id_1296 == label2_712) };
                                Size choose_res_1298;
                                if (id_1297) {
                                  Size id_1299 { 2UL };
                                  Size id_1300 { Size(sz_711 + id_1299) };
                                  choose_res_1298 = id_1300;
                                } else {
                                  uint16_t id_1301 { 2 };
                                  bool id_1302 { bool(id_1301 == label2_712) };
                                  Size choose_res_1303;
                                  if (id_1302) {
                                    Size id_1304 { 2UL };
                                    Size id_1305 { Size(sz_711 + id_1304) };
                                    choose_res_1303 = id_1305;
                                  } else {
                                    uint16_t id_1306 { 3 };
                                    bool id_1307 { bool(id_1306 == label2_712) };
                                    Size choose_res_1308;
                                    if (id_1307) {
                                      Size id_1309 { 2UL };
                                      Size id_1310 { Size(sz_711 + id_1309) };
                                      choose_res_1308 = id_1310;
                                    } else {
                                      uint16_t id_1311 { 4 };
                                      bool id_1312 { bool(id_1311 == label2_712) };
                                      Size choose_res_1313;
                                      if (id_1312) {
                                        Size id_1314 { 2UL };
                                        Size id_1315 { Size(sz_711 + id_1314) };
                                        choose_res_1313 = id_1315;
                                      } else {
                                        uint16_t id_1316 { 5 };
                                        bool id_1317 { bool(id_1316 == label2_712) };
                                        Size choose_res_1318;
                                        if (id_1317) {
                                          Size id_1319 { 2UL };
                                          Size id_1320 { Size(sz_711 + id_1319) };
                                          choose_res_1318 = id_1320;
                                        } else {
                                          uint16_t id_1321 { 6 };
                                          bool id_1322 { bool(id_1321 == label2_712) };
                                          Size choose_res_1323;
                                          if (id_1322) {
                                            Size id_1324 { 2UL };
                                            Size id_1325 { Size(sz_711 + id_1324) };
                                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1326 { std::get<5 /* PerSite */>((*p_0)) };
                                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1327 { std::get<1>(id_1326) };
                                            ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_1328 { std::get<2 /* PerWorker */>(id_1327) };
                                            ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_1329 { std::get<1>(id_1328) };
                                            ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_1330 { std::get<6 /* PerInstance */>(id_1329) };
                                            std::string id_1331 { std::get<0>(id_1330) };
                                            uint32_t id_1332 { (uint32_t)id_1331.size() };
                                            Vec<1, uint32_t> id_1333 {  id_1332  };
                                            Size let_res_1334;
                                            {
                                              Vec<1, uint32_t> n_ref_715 { id_1333 };
                                              uint32_t id_1335 { 1U };
                                              Vec<1, uint32_t> id_1336 {  id_1335  };
                                              Size let_res_1337;
                                              {
                                                Vec<1, uint32_t> lebsz_ref_716 { id_1336 };
                                                bool while_flag_1338 { true };
                                                do {
                                                  uint8_t id_1339 { 0 };
                                                  uint32_t id_1340 { n_ref_715[id_1339] };
                                                  uint8_t id_1341 { 0 };
                                                  uint32_t id_1342 { lebsz_ref_716[id_1341] };
                                                  uint8_t id_1343 { 7 };
                                                  uint32_t id_1344 { uint32_t(id_1342 << id_1343) };
                                                  bool id_1345 { bool(id_1340 >= id_1344) };
                                                  while_flag_1338 = id_1345;
                                                  if (while_flag_1338) {
                                                    uint8_t id_1346 { 0 };
                                                    uint8_t id_1347 { 0 };
                                                    uint32_t id_1348 { lebsz_ref_716[id_1347] };
                                                    uint32_t id_1349 { 1U };
                                                    uint32_t id_1350 { uint32_t(id_1348 + id_1349) };
                                                    Void id_1351 { ((void)(lebsz_ref_716[id_1346] = id_1350), VOID) };
                                                    (void)id_1351;
                                                  }
                                                } while (while_flag_1338);
                                                (void)VOID;
                                                uint8_t id_1352 { 0 };
                                                uint32_t id_1353 { lebsz_ref_716[id_1352] };
                                                Size id_1354 { Size(id_1353) };
                                                let_res_1337 = id_1354;
                                              }
                                              let_res_1334 = let_res_1337;
                                            }
                                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1355 { std::get<5 /* PerSite */>((*p_0)) };
                                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1356 { std::get<1>(id_1355) };
                                            ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_1357 { std::get<2 /* PerWorker */>(id_1356) };
                                            ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_1358 { std::get<1>(id_1357) };
                                            ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_1359 { std::get<6 /* PerInstance */>(id_1358) };
                                            std::string id_1360 { std::get<0>(id_1359) };
                                            uint32_t id_1361 { (uint32_t)id_1360.size() };
                                            Size id_1362 { Size(id_1361) };
                                            Size id_1363 { Size(let_res_1334 + id_1362) };
                                            Size id_1364 { Size(id_1325 + id_1363) };
                                            Size let_res_1365;
                                            {
                                              Size sz_717 { id_1364 };
                                              ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1366 { std::get<5 /* PerSite */>((*p_0)) };
                                              ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1367 { std::get<1>(id_1366) };
                                              ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_1368 { std::get<2 /* PerWorker */>(id_1367) };
                                              ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_1369 { std::get<1>(id_1368) };
                                              ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_1370 { std::get<6 /* PerInstance */>(id_1369) };
                                              ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_1371 { std::get<1>(id_1370) };
                                              uint16_t id_1372 { uint16_t(id_1371.index()) };
                                              Size let_res_1373;
                                              {
                                                uint16_t label2_718 { id_1372 };
                                                uint16_t id_1374 { 0 };
                                                bool id_1375 { bool(id_1374 == label2_718) };
                                                Size choose_res_1376;
                                                if (id_1375) {
                                                  Size id_1377 { 2UL };
                                                  Size id_1378 { Size(sz_717 + id_1377) };
                                                  choose_res_1376 = id_1378;
                                                } else {
                                                  uint16_t id_1379 { 1 };
                                                  bool id_1380 { bool(id_1379 == label2_718) };
                                                  Size choose_res_1381;
                                                  if (id_1380) {
                                                    Size id_1382 { 2UL };
                                                    Size id_1383 { Size(sz_717 + id_1382) };
                                                    choose_res_1381 = id_1383;
                                                  } else {
                                                    uint16_t id_1384 { 2 };
                                                    bool id_1385 { bool(id_1384 == label2_718) };
                                                    Size choose_res_1386;
                                                    if (id_1385) {
                                                      Size id_1387 { 2UL };
                                                      Size id_1388 { Size(sz_717 + id_1387) };
                                                      choose_res_1386 = id_1388;
                                                    } else {
                                                      uint16_t id_1389 { 3 };
                                                      bool id_1390 { bool(id_1389 == label2_718) };
                                                      Size choose_res_1391;
                                                      if (id_1390) {
                                                        Size id_1392 { 2UL };
                                                        Size id_1393 { Size(sz_717 + id_1392) };
                                                        choose_res_1391 = id_1393;
                                                      } else {
                                                        uint16_t id_1394 { 4 };
                                                        bool id_1395 { bool(id_1394 == label2_718) };
                                                        Size choose_res_1396;
                                                        if (id_1395) {
                                                          Size id_1397 { 2UL };
                                                          Size id_1398 { Size(sz_717 + id_1397) };
                                                          choose_res_1396 = id_1398;
                                                        } else {
                                                          uint16_t id_1399 { 5 };
                                                          bool id_1400 { bool(id_1399 == label2_718) };
                                                          Size choose_res_1401;
                                                          if (id_1400) {
                                                            Size id_1402 { 2UL };
                                                            Size id_1403 { Size(sz_717 + id_1402) };
                                                            choose_res_1401 = id_1403;
                                                          } else {
                                                            uint16_t id_1404 { 6 };
                                                            bool id_1405 { bool(id_1404 == label2_718) };
                                                            Size choose_res_1406;
                                                            if (id_1405) {
                                                              Size id_1407 { 2UL };
                                                              Size id_1408 { Size(sz_717 + id_1407) };
                                                              choose_res_1406 = id_1408;
                                                            } else {
                                                              uint16_t id_1409 { 7 };
                                                              bool id_1410 { bool(label2_718 == id_1409) };
                                                              Void id_1411 { ((void)(assert(id_1410)), VOID) };
                                                              (void)id_1411;
                                                              Size id_1412 { 2UL };
                                                              Size id_1413 { Size(sz_717 + id_1412) };
                                                              choose_res_1406 = id_1413;
                                                            }
                                                            choose_res_1401 = choose_res_1406;
                                                          }
                                                          choose_res_1396 = choose_res_1401;
                                                        }
                                                        choose_res_1391 = choose_res_1396;
                                                      }
                                                      choose_res_1386 = choose_res_1391;
                                                    }
                                                    choose_res_1381 = choose_res_1386;
                                                  }
                                                  choose_res_1376 = choose_res_1381;
                                                }
                                                let_res_1373 = choose_res_1376;
                                              }
                                              let_res_1365 = let_res_1373;
                                            }
                                            choose_res_1323 = let_res_1365;
                                          } else {
                                            uint16_t id_1414 { 7 };
                                            bool id_1415 { bool(id_1414 == label2_712) };
                                            Size choose_res_1416;
                                            if (id_1415) {
                                              Size id_1417 { 2UL };
                                              Size id_1418 { Size(sz_711 + id_1417) };
                                              Size id_1419 { 4UL };
                                              Size id_1420 { Size(id_1418 + id_1419) };
                                              choose_res_1416 = id_1420;
                                            } else {
                                              uint16_t id_1421 { 8 };
                                              bool id_1422 { bool(label2_712 == id_1421) };
                                              Void id_1423 { ((void)(assert(id_1422)), VOID) };
                                              (void)id_1423;
                                              Size id_1424 { 2UL };
                                              Size id_1425 { Size(sz_711 + id_1424) };
                                              choose_res_1416 = id_1425;
                                            }
                                            choose_res_1323 = choose_res_1416;
                                          }
                                          choose_res_1318 = choose_res_1323;
                                        }
                                        choose_res_1313 = choose_res_1318;
                                      }
                                      choose_res_1308 = choose_res_1313;
                                    }
                                    choose_res_1303 = choose_res_1308;
                                  }
                                  choose_res_1298 = choose_res_1303;
                                }
                                choose_res_1293 = choose_res_1298;
                              }
                              let_res_1290 = choose_res_1293;
                            }
                            let_res_1284 = let_res_1290;
                          }
                          choose_res_1274 = let_res_1284;
                        } else {
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1426 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1427 { std::get<1>(id_1426) };
                          uint16_t id_1428 { uint16_t(id_1427.index()) };
                          uint16_t id_1429 { 3 };
                          bool id_1430 { bool(id_1428 == id_1429) };
                          Void id_1431 { ((void)(assert(id_1430)), VOID) };
                          (void)id_1431;
                          Size id_1432 { 2UL };
                          Size id_1433 { Size(sz_702 + id_1432) };
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1434 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1435 { std::get<1>(id_1434) };
                          ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_1436 { std::get<3 /* PerProgram */>(id_1435) };
                          std::string id_1437 { std::get<0>(id_1436) };
                          uint32_t id_1438 { (uint32_t)id_1437.size() };
                          Vec<1, uint32_t> id_1439 {  id_1438  };
                          Size let_res_1440;
                          {
                            Vec<1, uint32_t> n_ref_706 { id_1439 };
                            uint32_t id_1441 { 1U };
                            Vec<1, uint32_t> id_1442 {  id_1441  };
                            Size let_res_1443;
                            {
                              Vec<1, uint32_t> lebsz_ref_707 { id_1442 };
                              bool while_flag_1444 { true };
                              do {
                                uint8_t id_1445 { 0 };
                                uint32_t id_1446 { n_ref_706[id_1445] };
                                uint8_t id_1447 { 0 };
                                uint32_t id_1448 { lebsz_ref_707[id_1447] };
                                uint8_t id_1449 { 7 };
                                uint32_t id_1450 { uint32_t(id_1448 << id_1449) };
                                bool id_1451 { bool(id_1446 >= id_1450) };
                                while_flag_1444 = id_1451;
                                if (while_flag_1444) {
                                  uint8_t id_1452 { 0 };
                                  uint8_t id_1453 { 0 };
                                  uint32_t id_1454 { lebsz_ref_707[id_1453] };
                                  uint32_t id_1455 { 1U };
                                  uint32_t id_1456 { uint32_t(id_1454 + id_1455) };
                                  Void id_1457 { ((void)(lebsz_ref_707[id_1452] = id_1456), VOID) };
                                  (void)id_1457;
                                }
                              } while (while_flag_1444);
                              (void)VOID;
                              uint8_t id_1458 { 0 };
                              uint32_t id_1459 { lebsz_ref_707[id_1458] };
                              Size id_1460 { Size(id_1459) };
                              let_res_1443 = id_1460;
                            }
                            let_res_1440 = let_res_1443;
                          }
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1461 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1462 { std::get<1>(id_1461) };
                          ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_1463 { std::get<3 /* PerProgram */>(id_1462) };
                          std::string id_1464 { std::get<0>(id_1463) };
                          uint32_t id_1465 { (uint32_t)id_1464.size() };
                          Size id_1466 { Size(id_1465) };
                          Size id_1467 { Size(let_res_1440 + id_1466) };
                          Size id_1468 { Size(id_1433 + id_1467) };
                          Size let_res_1469;
                          {
                            Size sz_708 { id_1468 };
                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1470 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1471 { std::get<1>(id_1470) };
                            ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_1472 { std::get<3 /* PerProgram */>(id_1471) };
                            ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_1473 { std::get<1>(id_1472) };
                            uint16_t id_1474 { uint16_t(id_1473.index()) };
                            uint16_t id_1475 { 0 };
                            bool id_1476 { bool(id_1474 == id_1475) };
                            Void id_1477 { ((void)(assert(id_1476)), VOID) };
                            (void)id_1477;
                            Size id_1478 { 2UL };
                            Size id_1479 { Size(sz_708 + id_1478) };
                            let_res_1469 = id_1479;
                          }
                          choose_res_1274 = let_res_1469;
                        }
                        choose_res_1210 = choose_res_1274;
                      }
                      choose_res_1202 = choose_res_1210;
                    }
                    let_res_1196 = choose_res_1202;
                  }
                  choose_res_1189 = let_res_1196;
                } else {
                  uint16_t id_1480 { 6 };
                  bool id_1481 { bool(id_1480 == label2_659) };
                  Size choose_res_1482;
                  if (id_1481) {
                    uint16_t id_1483 { 0 };
                    ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1484 { std::get<6 /* Storage */>((*p_0)) };
                    uint16_t id_1485 { uint16_t(id_1484.index()) };
                    bool id_1486 { bool(id_1483 == id_1485) };
                    Size choose_res_1487;
                    if (id_1486) {
                      Size id_1488 { 4UL };
                      choose_res_1487 = id_1488;
                    } else {
                      uint16_t id_1489 { 1 };
                      ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1490 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_1491 { uint16_t(id_1490.index()) };
                      bool id_1492 { bool(id_1489 == id_1491) };
                      Size choose_res_1493;
                      if (id_1492) {
                        Size id_1494 { 4UL };
                        choose_res_1493 = id_1494;
                      } else {
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1495 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_1496 { uint16_t(id_1495.index()) };
                        uint16_t id_1497 { 2 };
                        bool id_1498 { bool(id_1496 == id_1497) };
                        Void id_1499 { ((void)(assert(id_1498)), VOID) };
                        (void)id_1499;
                        Size id_1500 { 4UL };
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1501 { std::get<6 /* Storage */>((*p_0)) };
                        std::string id_1502 { std::get<2 /* RetentionsOverride */>(id_1501) };
                        uint32_t id_1503 { (uint32_t)id_1502.size() };
                        Vec<1, uint32_t> id_1504 {  id_1503  };
                        Size let_res_1505;
                        {
                          Vec<1, uint32_t> n_ref_699 { id_1504 };
                          uint32_t id_1506 { 1U };
                          Vec<1, uint32_t> id_1507 {  id_1506  };
                          Size let_res_1508;
                          {
                            Vec<1, uint32_t> lebsz_ref_700 { id_1507 };
                            bool while_flag_1509 { true };
                            do {
                              uint8_t id_1510 { 0 };
                              uint32_t id_1511 { n_ref_699[id_1510] };
                              uint8_t id_1512 { 0 };
                              uint32_t id_1513 { lebsz_ref_700[id_1512] };
                              uint8_t id_1514 { 7 };
                              uint32_t id_1515 { uint32_t(id_1513 << id_1514) };
                              bool id_1516 { bool(id_1511 >= id_1515) };
                              while_flag_1509 = id_1516;
                              if (while_flag_1509) {
                                uint8_t id_1517 { 0 };
                                uint8_t id_1518 { 0 };
                                uint32_t id_1519 { lebsz_ref_700[id_1518] };
                                uint32_t id_1520 { 1U };
                                uint32_t id_1521 { uint32_t(id_1519 + id_1520) };
                                Void id_1522 { ((void)(lebsz_ref_700[id_1517] = id_1521), VOID) };
                                (void)id_1522;
                              }
                            } while (while_flag_1509);
                            (void)VOID;
                            uint8_t id_1523 { 0 };
                            uint32_t id_1524 { lebsz_ref_700[id_1523] };
                            Size id_1525 { Size(id_1524) };
                            let_res_1508 = id_1525;
                          }
                          let_res_1505 = let_res_1508;
                        }
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1526 { std::get<6 /* Storage */>((*p_0)) };
                        std::string id_1527 { std::get<2 /* RetentionsOverride */>(id_1526) };
                        uint32_t id_1528 { (uint32_t)id_1527.size() };
                        Size id_1529 { Size(id_1528) };
                        Size id_1530 { Size(let_res_1505 + id_1529) };
                        Size id_1531 { Size(id_1500 + id_1530) };
                        choose_res_1493 = id_1531;
                      }
                      choose_res_1487 = choose_res_1493;
                    }
                    choose_res_1482 = choose_res_1487;
                  } else {
                    uint16_t id_1532 { 7 };
                    bool id_1533 { bool(id_1532 == label2_659) };
                    Size choose_res_1534;
                    if (id_1533) {
                      Size id_1535 { 2UL };
                      auto fun1536 { dessser::gen::site_name::sersize_of_row_binary };
                      ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_1537 { std::get<7 /* Tails */>((*p_0)) };
                      dessser::gen::site_name::t_ext id_1538 { std::get<0>(id_1537) };
                      Size id_1539 { fun1536(id_1538) };
                      Size id_1540 { Size(id_1535 + id_1539) };
                      Size let_res_1541;
                      {
                        Size sz_691 { id_1540 };
                        auto fun1542 { dessser::gen::fq_name::sersize_of_row_binary };
                        ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_1543 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::fq_name::t_ext id_1544 { std::get<1>(id_1543) };
                        Size id_1545 { fun1542(id_1544) };
                        Size id_1546 { Size(sz_691 + id_1545) };
                        let_res_1541 = id_1546;
                      }
                      Size let_res_1547;
                      {
                        Size sz_692 { let_res_1541 };
                        ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_1548 { std::get<7 /* Tails */>((*p_0)) };
                        std::string id_1549 { std::get<2>(id_1548) };
                        uint32_t id_1550 { (uint32_t)id_1549.size() };
                        Vec<1, uint32_t> id_1551 {  id_1550  };
                        Size let_res_1552;
                        {
                          Vec<1, uint32_t> n_ref_694 { id_1551 };
                          uint32_t id_1553 { 1U };
                          Vec<1, uint32_t> id_1554 {  id_1553  };
                          Size let_res_1555;
                          {
                            Vec<1, uint32_t> lebsz_ref_695 { id_1554 };
                            bool while_flag_1556 { true };
                            do {
                              uint8_t id_1557 { 0 };
                              uint32_t id_1558 { n_ref_694[id_1557] };
                              uint8_t id_1559 { 0 };
                              uint32_t id_1560 { lebsz_ref_695[id_1559] };
                              uint8_t id_1561 { 7 };
                              uint32_t id_1562 { uint32_t(id_1560 << id_1561) };
                              bool id_1563 { bool(id_1558 >= id_1562) };
                              while_flag_1556 = id_1563;
                              if (while_flag_1556) {
                                uint8_t id_1564 { 0 };
                                uint8_t id_1565 { 0 };
                                uint32_t id_1566 { lebsz_ref_695[id_1565] };
                                uint32_t id_1567 { 1U };
                                uint32_t id_1568 { uint32_t(id_1566 + id_1567) };
                                Void id_1569 { ((void)(lebsz_ref_695[id_1564] = id_1568), VOID) };
                                (void)id_1569;
                              }
                            } while (while_flag_1556);
                            (void)VOID;
                            uint8_t id_1570 { 0 };
                            uint32_t id_1571 { lebsz_ref_695[id_1570] };
                            Size id_1572 { Size(id_1571) };
                            let_res_1555 = id_1572;
                          }
                          let_res_1552 = let_res_1555;
                        }
                        ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_1573 { std::get<7 /* Tails */>((*p_0)) };
                        std::string id_1574 { std::get<2>(id_1573) };
                        uint32_t id_1575 { (uint32_t)id_1574.size() };
                        Size id_1576 { Size(id_1575) };
                        Size id_1577 { Size(let_res_1552 + id_1576) };
                        Size id_1578 { Size(sz_692 + id_1577) };
                        let_res_1547 = id_1578;
                      }
                      Size let_res_1579;
                      {
                        Size sz_696 { let_res_1547 };
                        ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_1580 { std::get<7 /* Tails */>((*p_0)) };
                        std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_1581 { std::get<3>(id_1580) };
                        Size id_1582 { per_tail_sersize_of_row_binary(id_1581) };
                        Size id_1583 { Size(sz_696 + id_1582) };
                        let_res_1579 = id_1583;
                      }
                      choose_res_1534 = let_res_1579;
                    } else {
                      uint16_t id_1584 { 8 };
                      bool id_1585 { bool(id_1584 == label2_659) };
                      Size choose_res_1586;
                      if (id_1585) {
                        Size id_1587 { 4UL };
                        choose_res_1586 = id_1587;
                      } else {
                        uint16_t id_1588 { 9 };
                        bool id_1589 { bool(id_1588 == label2_659) };
                        Size choose_res_1590;
                        if (id_1589) {
                          std::optional<dessser::gen::sync_socket::t_ext> id_1591 { std::get<9 /* Error */>((*p_0)) };
                          bool id_1592 { !(id_1591.has_value ()) };
                          Size choose_res_1593;
                          if (id_1592) {
                            Size id_1594 { 3UL };
                            choose_res_1593 = id_1594;
                          } else {
                            Size id_1595 { 2UL };
                            auto fun1596 { dessser::gen::sync_socket::sersize_of_row_binary };
                            std::optional<dessser::gen::sync_socket::t_ext> id_1597 { std::get<9 /* Error */>((*p_0)) };
                            dessser::gen::sync_socket::t_ext id_1598 { id_1597.value() };
                            Size id_1599 { fun1596(id_1598) };
                            Size id_1600 { Size(id_1595 + id_1599) };
                            Size id_1601 { 1UL };
                            Size id_1602 { Size(id_1600 + id_1601) };
                            choose_res_1593 = id_1602;
                          }
                          choose_res_1590 = choose_res_1593;
                        } else {
                          uint16_t id_1603 { 10 };
                          bool id_1604 { bool(id_1603 == label2_659) };
                          Size choose_res_1605;
                          if (id_1604) {
                            Size id_1606 { 2UL };
                            choose_res_1605 = id_1606;
                          } else {
                            uint16_t id_1607 { 11 };
                            bool id_1608 { bool(id_1607 == label2_659) };
                            Size choose_res_1609;
                            if (id_1608) {
                              Size id_1610 { 2UL };
                              auto fun1611 { dessser::gen::sync_socket::sersize_of_row_binary };
                              ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef id_1612 { std::get<11 /* PerClient */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_1613 { std::get<0>(id_1612) };
                              Size id_1614 { fun1611(id_1613) };
                              Size id_1615 { Size(id_1610 + id_1614) };
                              Size let_res_1616;
                              {
                                Size sz_689 { id_1615 };
                                ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef id_1617 { std::get<11 /* PerClient */>((*p_0)) };
                                std::shared_ptr<::dessser::gen::sync_key::per_client>  id_1618 { std::get<1>(id_1617) };
                                Size id_1619 { per_client_sersize_of_row_binary(id_1618) };
                                Size id_1620 { Size(sz_689 + id_1619) };
                                let_res_1616 = id_1620;
                              }
                              choose_res_1609 = let_res_1616;
                            } else {
                              uint16_t id_1621 { 12 };
                              bool id_1622 { bool(id_1621 == label2_659) };
                              Size choose_res_1623;
                              if (id_1622) {
                                Size id_1624 { 2UL };
                                ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_1625 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1626 { std::get<0>(id_1625) };
                                uint32_t id_1627 { (uint32_t)id_1626.size() };
                                Vec<1, uint32_t> id_1628 {  id_1627  };
                                Size let_res_1629;
                                {
                                  Vec<1, uint32_t> n_ref_685 { id_1628 };
                                  uint32_t id_1630 { 1U };
                                  Vec<1, uint32_t> id_1631 {  id_1630  };
                                  Size let_res_1632;
                                  {
                                    Vec<1, uint32_t> lebsz_ref_686 { id_1631 };
                                    bool while_flag_1633 { true };
                                    do {
                                      uint8_t id_1634 { 0 };
                                      uint32_t id_1635 { n_ref_685[id_1634] };
                                      uint8_t id_1636 { 0 };
                                      uint32_t id_1637 { lebsz_ref_686[id_1636] };
                                      uint8_t id_1638 { 7 };
                                      uint32_t id_1639 { uint32_t(id_1637 << id_1638) };
                                      bool id_1640 { bool(id_1635 >= id_1639) };
                                      while_flag_1633 = id_1640;
                                      if (while_flag_1633) {
                                        uint8_t id_1641 { 0 };
                                        uint8_t id_1642 { 0 };
                                        uint32_t id_1643 { lebsz_ref_686[id_1642] };
                                        uint32_t id_1644 { 1U };
                                        uint32_t id_1645 { uint32_t(id_1643 + id_1644) };
                                        Void id_1646 { ((void)(lebsz_ref_686[id_1641] = id_1645), VOID) };
                                        (void)id_1646;
                                      }
                                    } while (while_flag_1633);
                                    (void)VOID;
                                    uint8_t id_1647 { 0 };
                                    uint32_t id_1648 { lebsz_ref_686[id_1647] };
                                    Size id_1649 { Size(id_1648) };
                                    let_res_1632 = id_1649;
                                  }
                                  let_res_1629 = let_res_1632;
                                }
                                ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_1650 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1651 { std::get<0>(id_1650) };
                                uint32_t id_1652 { (uint32_t)id_1651.size() };
                                Size id_1653 { Size(id_1652) };
                                Size id_1654 { Size(let_res_1629 + id_1653) };
                                Size id_1655 { Size(id_1624 + id_1654) };
                                Size let_res_1656;
                                {
                                  Size sz_687 { id_1655 };
                                  ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_1657 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1658 { std::get<1>(id_1657) };
                                  Size id_1659 { per_dash_key_sersize_of_row_binary(id_1658) };
                                  Size id_1660 { Size(sz_687 + id_1659) };
                                  let_res_1656 = id_1660;
                                }
                                choose_res_1623 = let_res_1656;
                              } else {
                                uint16_t id_1661 { 13 };
                                bool id_1662 { bool(id_1661 == label2_659) };
                                Size choose_res_1663;
                                if (id_1662) {
                                  Size id_1664 { 2UL };
                                  choose_res_1663 = id_1664;
                                } else {
                                  uint16_t id_1665 { 14 };
                                  bool id_1666 { bool(id_1665 == label2_659) };
                                  Size choose_res_1667;
                                  if (id_1666) {
                                    Size id_1668 { 2UL };
                                    auto fun1669 { dessser::gen::team_name::sersize_of_row_binary };
                                    ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1670 { std::get<14 /* Teams */>((*p_0)) };
                                    dessser::gen::team_name::t_ext id_1671 { std::get<0>(id_1670) };
                                    Size id_1672 { fun1669(id_1671) };
                                    Size id_1673 { Size(id_1668 + id_1672) };
                                    Size let_res_1674;
                                    {
                                      Size sz_675 { id_1673 };
                                      uint16_t id_1675 { 0 };
                                      ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1676 { std::get<14 /* Teams */>((*p_0)) };
                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1677 { std::get<1>(id_1676) };
                                      uint16_t id_1678 { uint16_t(id_1677.index()) };
                                      bool id_1679 { bool(id_1675 == id_1678) };
                                      Size choose_res_1680;
                                      if (id_1679) {
                                        Size id_1681 { 2UL };
                                        Size id_1682 { Size(sz_675 + id_1681) };
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1683 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1684 { std::get<1>(id_1683) };
                                        std::string id_1685 { std::get<0 /* Contacts */>(id_1684) };
                                        uint32_t id_1686 { (uint32_t)id_1685.size() };
                                        Vec<1, uint32_t> id_1687 {  id_1686  };
                                        Size let_res_1688;
                                        {
                                          Vec<1, uint32_t> n_ref_681 { id_1687 };
                                          uint32_t id_1689 { 1U };
                                          Vec<1, uint32_t> id_1690 {  id_1689  };
                                          Size let_res_1691;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_682 { id_1690 };
                                            bool while_flag_1692 { true };
                                            do {
                                              uint8_t id_1693 { 0 };
                                              uint32_t id_1694 { n_ref_681[id_1693] };
                                              uint8_t id_1695 { 0 };
                                              uint32_t id_1696 { lebsz_ref_682[id_1695] };
                                              uint8_t id_1697 { 7 };
                                              uint32_t id_1698 { uint32_t(id_1696 << id_1697) };
                                              bool id_1699 { bool(id_1694 >= id_1698) };
                                              while_flag_1692 = id_1699;
                                              if (while_flag_1692) {
                                                uint8_t id_1700 { 0 };
                                                uint8_t id_1701 { 0 };
                                                uint32_t id_1702 { lebsz_ref_682[id_1701] };
                                                uint32_t id_1703 { 1U };
                                                uint32_t id_1704 { uint32_t(id_1702 + id_1703) };
                                                Void id_1705 { ((void)(lebsz_ref_682[id_1700] = id_1704), VOID) };
                                                (void)id_1705;
                                              }
                                            } while (while_flag_1692);
                                            (void)VOID;
                                            uint8_t id_1706 { 0 };
                                            uint32_t id_1707 { lebsz_ref_682[id_1706] };
                                            Size id_1708 { Size(id_1707) };
                                            let_res_1691 = id_1708;
                                          }
                                          let_res_1688 = let_res_1691;
                                        }
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1709 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1710 { std::get<1>(id_1709) };
                                        std::string id_1711 { std::get<0 /* Contacts */>(id_1710) };
                                        uint32_t id_1712 { (uint32_t)id_1711.size() };
                                        Size id_1713 { Size(id_1712) };
                                        Size id_1714 { Size(let_res_1688 + id_1713) };
                                        Size id_1715 { Size(id_1682 + id_1714) };
                                        choose_res_1680 = id_1715;
                                      } else {
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1716 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1717 { std::get<1>(id_1716) };
                                        uint16_t id_1718 { uint16_t(id_1717.index()) };
                                        uint16_t id_1719 { 1 };
                                        bool id_1720 { bool(id_1718 == id_1719) };
                                        Void id_1721 { ((void)(assert(id_1720)), VOID) };
                                        (void)id_1721;
                                        Size id_1722 { 2UL };
                                        Size id_1723 { Size(sz_675 + id_1722) };
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1724 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1725 { std::get<1>(id_1724) };
                                        std::string id_1726 { std::get<1 /* Inhibition */>(id_1725) };
                                        uint32_t id_1727 { (uint32_t)id_1726.size() };
                                        Vec<1, uint32_t> id_1728 {  id_1727  };
                                        Size let_res_1729;
                                        {
                                          Vec<1, uint32_t> n_ref_678 { id_1728 };
                                          uint32_t id_1730 { 1U };
                                          Vec<1, uint32_t> id_1731 {  id_1730  };
                                          Size let_res_1732;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_679 { id_1731 };
                                            bool while_flag_1733 { true };
                                            do {
                                              uint8_t id_1734 { 0 };
                                              uint32_t id_1735 { n_ref_678[id_1734] };
                                              uint8_t id_1736 { 0 };
                                              uint32_t id_1737 { lebsz_ref_679[id_1736] };
                                              uint8_t id_1738 { 7 };
                                              uint32_t id_1739 { uint32_t(id_1737 << id_1738) };
                                              bool id_1740 { bool(id_1735 >= id_1739) };
                                              while_flag_1733 = id_1740;
                                              if (while_flag_1733) {
                                                uint8_t id_1741 { 0 };
                                                uint8_t id_1742 { 0 };
                                                uint32_t id_1743 { lebsz_ref_679[id_1742] };
                                                uint32_t id_1744 { 1U };
                                                uint32_t id_1745 { uint32_t(id_1743 + id_1744) };
                                                Void id_1746 { ((void)(lebsz_ref_679[id_1741] = id_1745), VOID) };
                                                (void)id_1746;
                                              }
                                            } while (while_flag_1733);
                                            (void)VOID;
                                            uint8_t id_1747 { 0 };
                                            uint32_t id_1748 { lebsz_ref_679[id_1747] };
                                            Size id_1749 { Size(id_1748) };
                                            let_res_1732 = id_1749;
                                          }
                                          let_res_1729 = let_res_1732;
                                        }
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1750 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1751 { std::get<1>(id_1750) };
                                        std::string id_1752 { std::get<1 /* Inhibition */>(id_1751) };
                                        uint32_t id_1753 { (uint32_t)id_1752.size() };
                                        Size id_1754 { Size(id_1753) };
                                        Size id_1755 { Size(let_res_1729 + id_1754) };
                                        Size id_1756 { Size(id_1723 + id_1755) };
                                        choose_res_1680 = id_1756;
                                      }
                                      let_res_1674 = choose_res_1680;
                                    }
                                    choose_res_1667 = let_res_1674;
                                  } else {
                                    uint16_t id_1757 { 15 };
                                    bool id_1758 { bool(label2_659 == id_1757) };
                                    Void id_1759 { ((void)(assert(id_1758)), VOID) };
                                    (void)id_1759;
                                    Size id_1760 { 2UL };
                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1761 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1762 { std::get<0>(id_1761) };
                                    uint32_t id_1763 { (uint32_t)id_1762.size() };
                                    Vec<1, uint32_t> id_1764 {  id_1763  };
                                    Size let_res_1765;
                                    {
                                      Vec<1, uint32_t> n_ref_662 { id_1764 };
                                      uint32_t id_1766 { 1U };
                                      Vec<1, uint32_t> id_1767 {  id_1766  };
                                      Size let_res_1768;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_663 { id_1767 };
                                        bool while_flag_1769 { true };
                                        do {
                                          uint8_t id_1770 { 0 };
                                          uint32_t id_1771 { n_ref_662[id_1770] };
                                          uint8_t id_1772 { 0 };
                                          uint32_t id_1773 { lebsz_ref_663[id_1772] };
                                          uint8_t id_1774 { 7 };
                                          uint32_t id_1775 { uint32_t(id_1773 << id_1774) };
                                          bool id_1776 { bool(id_1771 >= id_1775) };
                                          while_flag_1769 = id_1776;
                                          if (while_flag_1769) {
                                            uint8_t id_1777 { 0 };
                                            uint8_t id_1778 { 0 };
                                            uint32_t id_1779 { lebsz_ref_663[id_1778] };
                                            uint32_t id_1780 { 1U };
                                            uint32_t id_1781 { uint32_t(id_1779 + id_1780) };
                                            Void id_1782 { ((void)(lebsz_ref_663[id_1777] = id_1781), VOID) };
                                            (void)id_1782;
                                          }
                                        } while (while_flag_1769);
                                        (void)VOID;
                                        uint8_t id_1783 { 0 };
                                        uint32_t id_1784 { lebsz_ref_663[id_1783] };
                                        Size id_1785 { Size(id_1784) };
                                        let_res_1768 = id_1785;
                                      }
                                      let_res_1765 = let_res_1768;
                                    }
                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1786 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1787 { std::get<0>(id_1786) };
                                    uint32_t id_1788 { (uint32_t)id_1787.size() };
                                    Size id_1789 { Size(id_1788) };
                                    Size id_1790 { Size(let_res_1765 + id_1789) };
                                    Size id_1791 { Size(id_1760 + id_1790) };
                                    Size let_res_1792;
                                    {
                                      Size sz_664 { id_1791 };
                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1793 { std::get<15 /* Incidents */>((*p_0)) };
                                      ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1794 { std::get<1>(id_1793) };
                                      uint16_t id_1795 { uint16_t(id_1794.index()) };
                                      Size let_res_1796;
                                      {
                                        uint16_t label2_665 { id_1795 };
                                        uint16_t id_1797 { 0 };
                                        bool id_1798 { bool(id_1797 == label2_665) };
                                        Size choose_res_1799;
                                        if (id_1798) {
                                          Size id_1800 { 2UL };
                                          Size id_1801 { Size(sz_664 + id_1800) };
                                          choose_res_1799 = id_1801;
                                        } else {
                                          uint16_t id_1802 { 1 };
                                          bool id_1803 { bool(id_1802 == label2_665) };
                                          Size choose_res_1804;
                                          if (id_1803) {
                                            Size id_1805 { 2UL };
                                            Size id_1806 { Size(sz_664 + id_1805) };
                                            choose_res_1804 = id_1806;
                                          } else {
                                            uint16_t id_1807 { 2 };
                                            bool id_1808 { bool(id_1807 == label2_665) };
                                            Size choose_res_1809;
                                            if (id_1808) {
                                              Size id_1810 { 2UL };
                                              Size id_1811 { Size(sz_664 + id_1810) };
                                              choose_res_1809 = id_1811;
                                            } else {
                                              uint16_t id_1812 { 3 };
                                              bool id_1813 { bool(id_1812 == label2_665) };
                                              Size choose_res_1814;
                                              if (id_1813) {
                                                Size id_1815 { 2UL };
                                                Size id_1816 { Size(sz_664 + id_1815) };
                                                choose_res_1814 = id_1816;
                                              } else {
                                                uint16_t id_1817 { 4 };
                                                bool id_1818 { bool(id_1817 == label2_665) };
                                                Size choose_res_1819;
                                                if (id_1818) {
                                                  Size id_1820 { 2UL };
                                                  Size id_1821 { Size(sz_664 + id_1820) };
                                                  choose_res_1819 = id_1821;
                                                } else {
                                                  uint16_t id_1822 { 5 };
                                                  bool id_1823 { bool(id_1822 == label2_665) };
                                                  Size choose_res_1824;
                                                  if (id_1823) {
                                                    Size id_1825 { 2UL };
                                                    Size id_1826 { Size(sz_664 + id_1825) };
                                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1827 { std::get<15 /* Incidents */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1828 { std::get<1>(id_1827) };
                                                    ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_1829 { std::get<5 /* Dialogs */>(id_1828) };
                                                    std::string id_1830 { std::get<0>(id_1829) };
                                                    uint32_t id_1831 { (uint32_t)id_1830.size() };
                                                    Vec<1, uint32_t> id_1832 {  id_1831  };
                                                    Size let_res_1833;
                                                    {
                                                      Vec<1, uint32_t> n_ref_670 { id_1832 };
                                                      uint32_t id_1834 { 1U };
                                                      Vec<1, uint32_t> id_1835 {  id_1834  };
                                                      Size let_res_1836;
                                                      {
                                                        Vec<1, uint32_t> lebsz_ref_671 { id_1835 };
                                                        bool while_flag_1837 { true };
                                                        do {
                                                          uint8_t id_1838 { 0 };
                                                          uint32_t id_1839 { n_ref_670[id_1838] };
                                                          uint8_t id_1840 { 0 };
                                                          uint32_t id_1841 { lebsz_ref_671[id_1840] };
                                                          uint8_t id_1842 { 7 };
                                                          uint32_t id_1843 { uint32_t(id_1841 << id_1842) };
                                                          bool id_1844 { bool(id_1839 >= id_1843) };
                                                          while_flag_1837 = id_1844;
                                                          if (while_flag_1837) {
                                                            uint8_t id_1845 { 0 };
                                                            uint8_t id_1846 { 0 };
                                                            uint32_t id_1847 { lebsz_ref_671[id_1846] };
                                                            uint32_t id_1848 { 1U };
                                                            uint32_t id_1849 { uint32_t(id_1847 + id_1848) };
                                                            Void id_1850 { ((void)(lebsz_ref_671[id_1845] = id_1849), VOID) };
                                                            (void)id_1850;
                                                          }
                                                        } while (while_flag_1837);
                                                        (void)VOID;
                                                        uint8_t id_1851 { 0 };
                                                        uint32_t id_1852 { lebsz_ref_671[id_1851] };
                                                        Size id_1853 { Size(id_1852) };
                                                        let_res_1836 = id_1853;
                                                      }
                                                      let_res_1833 = let_res_1836;
                                                    }
                                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1854 { std::get<15 /* Incidents */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1855 { std::get<1>(id_1854) };
                                                    ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_1856 { std::get<5 /* Dialogs */>(id_1855) };
                                                    std::string id_1857 { std::get<0>(id_1856) };
                                                    uint32_t id_1858 { (uint32_t)id_1857.size() };
                                                    Size id_1859 { Size(id_1858) };
                                                    Size id_1860 { Size(let_res_1833 + id_1859) };
                                                    Size id_1861 { Size(id_1826 + id_1860) };
                                                    Size let_res_1862;
                                                    {
                                                      Size sz_672 { id_1861 };
                                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1863 { std::get<15 /* Incidents */>((*p_0)) };
                                                      ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1864 { std::get<1>(id_1863) };
                                                      ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_1865 { std::get<5 /* Dialogs */>(id_1864) };
                                                      ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_1866 { std::get<1>(id_1865) };
                                                      uint16_t id_1867 { uint16_t(id_1866.index()) };
                                                      Size let_res_1868;
                                                      {
                                                        uint16_t label2_673 { id_1867 };
                                                        uint16_t id_1869 { 0 };
                                                        bool id_1870 { bool(id_1869 == label2_673) };
                                                        Size choose_res_1871;
                                                        if (id_1870) {
                                                          Size id_1872 { 2UL };
                                                          Size id_1873 { Size(sz_672 + id_1872) };
                                                          choose_res_1871 = id_1873;
                                                        } else {
                                                          uint16_t id_1874 { 1 };
                                                          bool id_1875 { bool(id_1874 == label2_673) };
                                                          Size choose_res_1876;
                                                          if (id_1875) {
                                                            Size id_1877 { 2UL };
                                                            Size id_1878 { Size(sz_672 + id_1877) };
                                                            choose_res_1876 = id_1878;
                                                          } else {
                                                            uint16_t id_1879 { 2 };
                                                            bool id_1880 { bool(id_1879 == label2_673) };
                                                            Size choose_res_1881;
                                                            if (id_1880) {
                                                              Size id_1882 { 2UL };
                                                              Size id_1883 { Size(sz_672 + id_1882) };
                                                              choose_res_1881 = id_1883;
                                                            } else {
                                                              uint16_t id_1884 { 3 };
                                                              bool id_1885 { bool(id_1884 == label2_673) };
                                                              Size choose_res_1886;
                                                              if (id_1885) {
                                                                Size id_1887 { 2UL };
                                                                Size id_1888 { Size(sz_672 + id_1887) };
                                                                choose_res_1886 = id_1888;
                                                              } else {
                                                                uint16_t id_1889 { 4 };
                                                                bool id_1890 { bool(id_1889 == label2_673) };
                                                                Size choose_res_1891;
                                                                if (id_1890) {
                                                                  Size id_1892 { 2UL };
                                                                  Size id_1893 { Size(sz_672 + id_1892) };
                                                                  choose_res_1891 = id_1893;
                                                                } else {
                                                                  uint16_t id_1894 { 5 };
                                                                  bool id_1895 { bool(id_1894 == label2_673) };
                                                                  Size choose_res_1896;
                                                                  if (id_1895) {
                                                                    Size id_1897 { 2UL };
                                                                    Size id_1898 { Size(sz_672 + id_1897) };
                                                                    choose_res_1896 = id_1898;
                                                                  } else {
                                                                    uint16_t id_1899 { 6 };
                                                                    bool id_1900 { bool(label2_673 == id_1899) };
                                                                    Void id_1901 { ((void)(assert(id_1900)), VOID) };
                                                                    (void)id_1901;
                                                                    Size id_1902 { 2UL };
                                                                    Size id_1903 { Size(sz_672 + id_1902) };
                                                                    choose_res_1896 = id_1903;
                                                                  }
                                                                  choose_res_1891 = choose_res_1896;
                                                                }
                                                                choose_res_1886 = choose_res_1891;
                                                              }
                                                              choose_res_1881 = choose_res_1886;
                                                            }
                                                            choose_res_1876 = choose_res_1881;
                                                          }
                                                          choose_res_1871 = choose_res_1876;
                                                        }
                                                        let_res_1868 = choose_res_1871;
                                                      }
                                                      let_res_1862 = let_res_1868;
                                                    }
                                                    choose_res_1824 = let_res_1862;
                                                  } else {
                                                    uint16_t id_1904 { 6 };
                                                    bool id_1905 { bool(label2_665 == id_1904) };
                                                    Void id_1906 { ((void)(assert(id_1905)), VOID) };
                                                    (void)id_1906;
                                                    Size id_1907 { 2UL };
                                                    Size id_1908 { Size(sz_664 + id_1907) };
                                                    Size id_1909 { 8UL };
                                                    Size id_1910 { Size(id_1908 + id_1909) };
                                                    Size id_1911 { 4UL };
                                                    Size id_1912 { Size(id_1910 + id_1911) };
                                                    choose_res_1824 = id_1912;
                                                  }
                                                  choose_res_1819 = choose_res_1824;
                                                }
                                                choose_res_1814 = choose_res_1819;
                                              }
                                              choose_res_1809 = choose_res_1814;
                                            }
                                            choose_res_1804 = choose_res_1809;
                                          }
                                          choose_res_1799 = choose_res_1804;
                                        }
                                        let_res_1796 = choose_res_1799;
                                      }
                                      let_res_1792 = let_res_1796;
                                    }
                                    choose_res_1667 = let_res_1792;
                                  }
                                  choose_res_1663 = choose_res_1667;
                                }
                                choose_res_1623 = choose_res_1663;
                              }
                              choose_res_1609 = choose_res_1623;
                            }
                            choose_res_1605 = choose_res_1609;
                          }
                          choose_res_1590 = choose_res_1605;
                        }
                        choose_res_1586 = choose_res_1590;
                      }
                      choose_res_1534 = choose_res_1586;
                    }
                    choose_res_1482 = choose_res_1534;
                  }
                  choose_res_1189 = choose_res_1482;
                }
                choose_res_1185 = choose_res_1189;
              }
              choose_res_1144 = choose_res_1185;
            }
            choose_res_1111 = choose_res_1144;
          }
          choose_res_1107 = choose_res_1111;
        }
        choose_res_1103 = choose_res_1107;
      }
      let_res_1100 = choose_res_1103;
    }
    return let_res_1100;
  }
   };
  return fun1098;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_95" (let-pair "du16_fst_90" "du16_snd_91" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_90") (identifier "du16_snd_91")))
        (let-pair "dsum1_fst_96" "dsum1_snd_97" (identifier "dsum1_95")
          (seq (assert (eq (identifier "dsum1_fst_96") (u16 0)))
            (let-pair "du32_fst_99" "du32_snd_100" (read-u32 little-endian (identifier "dsum1_snd_97")) (make-tup (construct "[Widgets U32]" 0 (identifier "du32_fst_99")) (identifier "du32_snd_100")))))))
 */
static std::function<::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c(Pointer)> per_dash_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c(Pointer)> fun1913 { [&fun1913](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1914 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1915;
    {
      auto du16_fst_90 { std::get<0>(id_1914) };
      auto du16_snd_91 { std::get<1>(id_1914) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1916 { du16_fst_90, du16_snd_91 };
      letpair_res_1915 = id_1916;
    }
    ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c let_res_1917;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_95 { letpair_res_1915 };
      ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c letpair_res_1918;
      {
        auto dsum1_fst_96 { std::get<0>(dsum1_95) };
        auto dsum1_snd_97 { std::get<1>(dsum1_95) };
        uint16_t id_1919 { 0 };
        bool id_1920 { bool(dsum1_fst_96 == id_1919) };
        Void id_1921 { ((void)(assert(id_1920)), VOID) };
        (void)id_1921;
        ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_1922 { dsum1_snd_97.readU32Le() };
        ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c letpair_res_1923;
        {
          auto du32_fst_99 { std::get<0>(id_1922) };
          auto du32_snd_100 { std::get<1>(id_1922) };
          std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1924 { std::make_shared<::dessser::gen::sync_key::per_dash_key>(std::in_place_index<0>, du32_fst_99) };
          ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c id_1925 { id_1924, du32_snd_100 };
          letpair_res_1923 = id_1925;
        }
        letpair_res_1918 = letpair_res_1923;
      }
      let_res_1917 = letpair_res_1918;
    }
    return let_res_1917;
  }
   };
  return fun1913;
}
std::function<::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c(Pointer)> per_dash_key_of_row_binary(per_dash_key_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_135" "make_snd_136"
        (let "dsum1_113" (let-pair "du16_fst_108" "du16_snd_109" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_108") (identifier "du16_snd_109")))
          (let-pair "dsum1_fst_114" "dsum1_snd_115" (identifier "dsum1_113")
            (if (eq (u16 0) (identifier "dsum1_fst_114"))
              (let "dstring1_125"
                (let "leb_ref_119" (make-vec (u32 0))
                  (let "shft_ref_120" (make-vec (u8 0))
                    (let "p_ref_121" (make-vec (identifier "dsum1_snd_115"))
                      (seq
                        (while
                          (let "leb128_122" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_121")))
                            (let-pair "leb128_fst_123" "leb128_snd_124" 
                              (identifier "leb128_122")
                              (seq (set-vec (u8 0) (identifier "p_ref_121") (identifier "leb128_snd_124"))
                                (set-vec (u8 0) (identifier "leb_ref_119")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_123") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_120"))) (unsafe-nth (u8 0) (identifier "leb_ref_119"))))
                                (set-vec (u8 0) (identifier "shft_ref_120") (add (unsafe-nth (u8 0) (identifier "shft_ref_120")) (u8 7))) 
                                (ge (identifier "leb128_fst_123") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_119"))) (unsafe-nth (u8 0) (identifier "p_ref_121")))))))
                (let-pair "dstring1_fst_126" "dstring1_snd_127" (identifier "dstring1_125")
                  (let-pair "dstring2_fst_129" "dstring2_snd_130" (read-bytes (identifier "dstring1_snd_127") (identifier "dstring1_fst_126"))
                    (make-tup (construct "[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" 0 (string-of-bytes (identifier "dstring2_fst_129"))) (identifier "dstring2_snd_130")))))
              (seq (assert (eq (identifier "dsum1_fst_114") (u16 1)))
                (let-pair "dsum2_fst_117" "dsum2_snd_118" (apply (identifier "per_dash_key-of-row-binary") (identifier "dsum1_snd_115"))
                  (make-tup (construct "[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" 1 (identifier "dsum2_fst_117")) (identifier "dsum2_snd_118")))))))
        (make-tup (identifier "make_fst_135") (identifier "make_snd_136"))))
 */
static std::function<::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9(Pointer)> per_client_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9(Pointer)> fun1926 { [&fun1926](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1927 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1928;
    {
      auto du16_fst_108 { std::get<0>(id_1927) };
      auto du16_snd_109 { std::get<1>(id_1927) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1929 { du16_fst_108, du16_snd_109 };
      letpair_res_1928 = id_1929;
    }
    ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 let_res_1930;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_113 { letpair_res_1928 };
      ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 letpair_res_1931;
      {
        auto dsum1_fst_114 { std::get<0>(dsum1_113) };
        auto dsum1_snd_115 { std::get<1>(dsum1_113) };
        uint16_t id_1932 { 0 };
        bool id_1933 { bool(id_1932 == dsum1_fst_114) };
        ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 choose_res_1934;
        if (id_1933) {
          uint32_t id_1935 { 0U };
          Vec<1, uint32_t> id_1936 {  id_1935  };
          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_1937;
          {
            Vec<1, uint32_t> leb_ref_119 { id_1936 };
            uint8_t id_1938 { 0 };
            Vec<1, uint8_t> id_1939 {  id_1938  };
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_1940;
            {
              Vec<1, uint8_t> shft_ref_120 { id_1939 };
              Vec<1, Pointer> id_1941 {  dsum1_snd_115  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_1942;
              {
                Vec<1, Pointer> p_ref_121 { id_1941 };
                bool while_flag_1943 { true };
                do {
                  uint8_t id_1944 { 0 };
                  Pointer id_1945 { p_ref_121[id_1944] };
                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_1946 { id_1945.readU8() };
                  bool let_res_1947;
                  {
                    ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_122 { id_1946 };
                    bool letpair_res_1948;
                    {
                      auto leb128_fst_123 { std::get<0>(leb128_122) };
                      auto leb128_snd_124 { std::get<1>(leb128_122) };
                      uint8_t id_1949 { 0 };
                      Void id_1950 { ((void)(p_ref_121[id_1949] = leb128_snd_124), VOID) };
                      (void)id_1950;
                      uint8_t id_1951 { 0 };
                      uint8_t id_1952 { 127 };
                      uint8_t id_1953 { uint8_t(leb128_fst_123 & id_1952) };
                      uint32_t id_1954 { uint32_t(id_1953) };
                      uint8_t id_1955 { 0 };
                      uint8_t id_1956 { shft_ref_120[id_1955] };
                      uint32_t id_1957 { uint32_t(id_1954 << id_1956) };
                      uint8_t id_1958 { 0 };
                      uint32_t id_1959 { leb_ref_119[id_1958] };
                      uint32_t id_1960 { uint32_t(id_1957 | id_1959) };
                      Void id_1961 { ((void)(leb_ref_119[id_1951] = id_1960), VOID) };
                      (void)id_1961;
                      uint8_t id_1962 { 0 };
                      uint8_t id_1963 { 0 };
                      uint8_t id_1964 { shft_ref_120[id_1963] };
                      uint8_t id_1965 { 7 };
                      uint8_t id_1966 { uint8_t(id_1964 + id_1965) };
                      Void id_1967 { ((void)(shft_ref_120[id_1962] = id_1966), VOID) };
                      (void)id_1967;
                      uint8_t id_1968 { 128 };
                      bool id_1969 { bool(leb128_fst_123 >= id_1968) };
                      letpair_res_1948 = id_1969;
                    }
                    let_res_1947 = letpair_res_1948;
                  }
                  while_flag_1943 = let_res_1947;
                  if (while_flag_1943) {
                    (void)VOID;
                  }
                } while (while_flag_1943);
                (void)VOID;
                uint8_t id_1970 { 0 };
                uint32_t id_1971 { leb_ref_119[id_1970] };
                Size id_1972 { Size(id_1971) };
                uint8_t id_1973 { 0 };
                Pointer id_1974 { p_ref_121[id_1973] };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_1975 { id_1972, id_1974 };
                let_res_1942 = id_1975;
              }
              let_res_1940 = let_res_1942;
            }
            let_res_1937 = let_res_1940;
          }
          ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 let_res_1976;
          {
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_125 { let_res_1937 };
            ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 letpair_res_1977;
            {
              auto dstring1_fst_126 { std::get<0>(dstring1_125) };
              auto dstring1_snd_127 { std::get<1>(dstring1_125) };
              ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_1978 { dstring1_snd_127.readBytes(dstring1_fst_126) };
              ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 letpair_res_1979;
              {
                auto dstring2_fst_129 { std::get<0>(id_1978) };
                auto dstring2_snd_130 { std::get<1>(id_1978) };
                std::string id_1980 { dstring2_fst_129.toString() };
                std::shared_ptr<::dessser::gen::sync_key::per_client>  id_1981 { std::make_shared<::dessser::gen::sync_key::per_client>(std::in_place_index<0>, id_1980) };
                ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 id_1982 { id_1981, dstring2_snd_130 };
                letpair_res_1979 = id_1982;
              }
              letpair_res_1977 = letpair_res_1979;
            }
            let_res_1976 = letpair_res_1977;
          }
          choose_res_1934 = let_res_1976;
        } else {
          uint16_t id_1983 { 1 };
          bool id_1984 { bool(dsum1_fst_114 == id_1983) };
          Void id_1985 { ((void)(assert(id_1984)), VOID) };
          (void)id_1985;
          ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c id_1986 { per_dash_key_of_row_binary(dsum1_snd_115) };
          ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 letpair_res_1987;
          {
            auto dsum2_fst_117 { std::get<0>(id_1986) };
            auto dsum2_snd_118 { std::get<1>(id_1986) };
            std::shared_ptr<::dessser::gen::sync_key::per_client>  id_1988 { std::make_shared<::dessser::gen::sync_key::per_client>(std::in_place_index<1>, dsum2_fst_117) };
            ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 id_1989 { id_1988, dsum2_snd_118 };
            letpair_res_1987 = id_1989;
          }
          choose_res_1934 = letpair_res_1987;
        }
        letpair_res_1931 = choose_res_1934;
      }
      let_res_1930 = letpair_res_1931;
    }
    ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 letpair_res_1990;
    {
      auto make_fst_135 { std::get<0>(let_res_1930) };
      auto make_snd_136 { std::get<1>(let_res_1930) };
      ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 id_1991 { make_fst_135, make_snd_136 };
      letpair_res_1990 = id_1991;
    }
    return letpair_res_1990;
  }
   };
  return fun1926;
}
std::function<::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9(Pointer)> per_client_of_row_binary(per_client_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_87" "make_snd_88"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (let "dstring1_77"
                (let "leb_ref_71" (make-vec (u32 0))
                  (let "shft_ref_72" (make-vec (u8 0))
                    (let "p_ref_73" (make-vec (identifier "dsum1_snd_64"))
                      (seq
                        (while
                          (let "leb128_74" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_73")))
                            (let-pair "leb128_fst_75" "leb128_snd_76" 
                              (identifier "leb128_74")
                              (seq (set-vec (u8 0) (identifier "p_ref_73") (identifier "leb128_snd_76"))
                                (set-vec (u8 0) (identifier "leb_ref_71")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_75") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_72"))) (unsafe-nth (u8 0) (identifier "leb_ref_71"))))
                                (set-vec (u8 0) (identifier "shft_ref_72") (add (unsafe-nth (u8 0) (identifier "shft_ref_72")) (u8 7))) 
                                (ge (identifier "leb128_fst_75") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_71"))) (unsafe-nth (u8 0) (identifier "p_ref_73")))))))
                (let-pair "dstring1_fst_78" "dstring1_snd_79" (identifier "dstring1_77")
                  (let-pair "dstring2_fst_81" "dstring2_snd_82" (read-bytes (identifier "dstring1_snd_79") (identifier "dstring1_fst_78"))
                    (make-tup (construct "[Subscriber STRING | LastTuple U32]" 0 (string-of-bytes (identifier "dstring2_fst_81"))) (identifier "dstring2_snd_82")))))
              (seq (assert (eq (identifier "dsum1_fst_63") (u16 1)))
                (let-pair "du32_fst_66" "du32_snd_67" (read-u32 little-endian (identifier "dsum1_snd_64")) (make-tup (construct "[Subscriber STRING | LastTuple U32]" 1 (identifier "du32_fst_66")) (identifier "du32_snd_67")))))))
        (make-tup (identifier "make_fst_87") (identifier "make_snd_88"))))
 */
static std::function<::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d(Pointer)> per_tail_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d(Pointer)> fun1992 { [&fun1992](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1993 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1994;
    {
      auto du16_fst_57 { std::get<0>(id_1993) };
      auto du16_snd_58 { std::get<1>(id_1993) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1995 { du16_fst_57, du16_snd_58 };
      letpair_res_1994 = id_1995;
    }
    ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d let_res_1996;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_1994 };
      ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d letpair_res_1997;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_1998 { 0 };
        bool id_1999 { bool(id_1998 == dsum1_fst_63) };
        ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d choose_res_2000;
        if (id_1999) {
          uint32_t id_2001 { 0U };
          Vec<1, uint32_t> id_2002 {  id_2001  };
          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2003;
          {
            Vec<1, uint32_t> leb_ref_71 { id_2002 };
            uint8_t id_2004 { 0 };
            Vec<1, uint8_t> id_2005 {  id_2004  };
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2006;
            {
              Vec<1, uint8_t> shft_ref_72 { id_2005 };
              Vec<1, Pointer> id_2007 {  dsum1_snd_64  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2008;
              {
                Vec<1, Pointer> p_ref_73 { id_2007 };
                bool while_flag_2009 { true };
                do {
                  uint8_t id_2010 { 0 };
                  Pointer id_2011 { p_ref_73[id_2010] };
                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2012 { id_2011.readU8() };
                  bool let_res_2013;
                  {
                    ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_74 { id_2012 };
                    bool letpair_res_2014;
                    {
                      auto leb128_fst_75 { std::get<0>(leb128_74) };
                      auto leb128_snd_76 { std::get<1>(leb128_74) };
                      uint8_t id_2015 { 0 };
                      Void id_2016 { ((void)(p_ref_73[id_2015] = leb128_snd_76), VOID) };
                      (void)id_2016;
                      uint8_t id_2017 { 0 };
                      uint8_t id_2018 { 127 };
                      uint8_t id_2019 { uint8_t(leb128_fst_75 & id_2018) };
                      uint32_t id_2020 { uint32_t(id_2019) };
                      uint8_t id_2021 { 0 };
                      uint8_t id_2022 { shft_ref_72[id_2021] };
                      uint32_t id_2023 { uint32_t(id_2020 << id_2022) };
                      uint8_t id_2024 { 0 };
                      uint32_t id_2025 { leb_ref_71[id_2024] };
                      uint32_t id_2026 { uint32_t(id_2023 | id_2025) };
                      Void id_2027 { ((void)(leb_ref_71[id_2017] = id_2026), VOID) };
                      (void)id_2027;
                      uint8_t id_2028 { 0 };
                      uint8_t id_2029 { 0 };
                      uint8_t id_2030 { shft_ref_72[id_2029] };
                      uint8_t id_2031 { 7 };
                      uint8_t id_2032 { uint8_t(id_2030 + id_2031) };
                      Void id_2033 { ((void)(shft_ref_72[id_2028] = id_2032), VOID) };
                      (void)id_2033;
                      uint8_t id_2034 { 128 };
                      bool id_2035 { bool(leb128_fst_75 >= id_2034) };
                      letpair_res_2014 = id_2035;
                    }
                    let_res_2013 = letpair_res_2014;
                  }
                  while_flag_2009 = let_res_2013;
                  if (while_flag_2009) {
                    (void)VOID;
                  }
                } while (while_flag_2009);
                (void)VOID;
                uint8_t id_2036 { 0 };
                uint32_t id_2037 { leb_ref_71[id_2036] };
                Size id_2038 { Size(id_2037) };
                uint8_t id_2039 { 0 };
                Pointer id_2040 { p_ref_73[id_2039] };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2041 { id_2038, id_2040 };
                let_res_2008 = id_2041;
              }
              let_res_2006 = let_res_2008;
            }
            let_res_2003 = let_res_2006;
          }
          ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d let_res_2042;
          {
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_77 { let_res_2003 };
            ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d letpair_res_2043;
            {
              auto dstring1_fst_78 { std::get<0>(dstring1_77) };
              auto dstring1_snd_79 { std::get<1>(dstring1_77) };
              ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2044 { dstring1_snd_79.readBytes(dstring1_fst_78) };
              ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d letpair_res_2045;
              {
                auto dstring2_fst_81 { std::get<0>(id_2044) };
                auto dstring2_snd_82 { std::get<1>(id_2044) };
                std::string id_2046 { dstring2_fst_81.toString() };
                std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_2047 { std::make_shared<::dessser::gen::sync_key::per_tail>(std::in_place_index<0>, id_2046) };
                ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d id_2048 { id_2047, dstring2_snd_82 };
                letpair_res_2045 = id_2048;
              }
              letpair_res_2043 = letpair_res_2045;
            }
            let_res_2042 = letpair_res_2043;
          }
          choose_res_2000 = let_res_2042;
        } else {
          uint16_t id_2049 { 1 };
          bool id_2050 { bool(dsum1_fst_63 == id_2049) };
          Void id_2051 { ((void)(assert(id_2050)), VOID) };
          (void)id_2051;
          ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_2052 { dsum1_snd_64.readU32Le() };
          ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d letpair_res_2053;
          {
            auto du32_fst_66 { std::get<0>(id_2052) };
            auto du32_snd_67 { std::get<1>(id_2052) };
            std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_2054 { std::make_shared<::dessser::gen::sync_key::per_tail>(std::in_place_index<1>, du32_fst_66) };
            ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d id_2055 { id_2054, du32_snd_67 };
            letpair_res_2053 = id_2055;
          }
          choose_res_2000 = letpair_res_2053;
        }
        letpair_res_1997 = choose_res_2000;
      }
      let_res_1996 = letpair_res_1997;
    }
    ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d letpair_res_2056;
    {
      auto make_fst_87 { std::get<0>(let_res_1996) };
      auto make_snd_88 { std::get<1>(let_res_1996) };
      ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d id_2057 { make_fst_87, make_snd_88 };
      letpair_res_2056 = id_2057;
    }
    return letpair_res_2056;
  }
   };
  return fun1992;
}
std::function<::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d(Pointer)> per_tail_of_row_binary(per_tail_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_648" "make_snd_649"
        (let "dsum1_143" (let-pair "du16_fst_138" "du16_snd_139" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_138") (identifier "du16_snd_139")))
          (let-pair "dsum1_fst_144" "dsum1_snd_145" (identifier "dsum1_143")
            (if (eq (u16 0) (identifier "dsum1_fst_144"))
              (make-tup
                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 0
                  (nop)) (identifier "dsum1_snd_145"))
              (if (eq (u16 1) (identifier "dsum1_fst_144"))
                (make-tup
                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 1
                    (nop)) (identifier "dsum1_snd_145"))
                (if (eq (u16 2) (identifier "dsum1_fst_144"))
                  (let "dstring1_632"
                    (let "leb_ref_626" (make-vec (u32 0))
                      (let "shft_ref_627" (make-vec (u8 0))
                        (let "p_ref_628" (make-vec (identifier "dsum1_snd_145"))
                          (seq
                            (while
                              (let "leb128_629" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_628")))
                                (let-pair "leb128_fst_630" "leb128_snd_631" 
                                  (identifier "leb128_629")
                                  (seq (set-vec (u8 0) (identifier "p_ref_628") (identifier "leb128_snd_631"))
                                    (set-vec (u8 0) (identifier "leb_ref_626")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_630") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_627"))) (unsafe-nth (u8 0) (identifier "leb_ref_626"))))
                                    (set-vec (u8 0) (identifier "shft_ref_627") (add (unsafe-nth (u8 0) (identifier "shft_ref_627")) (u8 7))) 
                                    (ge (identifier "leb128_fst_630") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_626"))) (unsafe-nth (u8 0) (identifier "p_ref_628")))))))
                    (let-pair "dstring1_fst_633" "dstring1_snd_634" (identifier "dstring1_632")
                      (let-pair "dstring2_fst_636" "dstring2_snd_637" 
                        (read-bytes (identifier "dstring1_snd_634") (identifier "dstring1_fst_633"))
                        (make-tup
                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 2
                            (string-of-bytes (identifier "dstring2_fst_636"))) 
                          (identifier "dstring2_snd_637")))))
                  (if (eq (u16 3) (identifier "dsum1_fst_144"))
                    (let "dtup_605" (apply (ext-identifier src_path of-row-binary) (identifier "dsum1_snd_145"))
                      (let-pair "dtup_fst_606" "dtup_snd_607" (identifier "dtup_605")
                        (let "dstring1_614"
                          (let "leb_ref_608" (make-vec (u32 0))
                            (let "shft_ref_609" (make-vec (u8 0))
                              (let "p_ref_610" (make-vec (identifier "dtup_snd_607"))
                                (seq
                                  (while
                                    (let "leb128_611" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_610")))
                                      (let-pair "leb128_fst_612" "leb128_snd_613" 
                                        (identifier "leb128_611")
                                        (seq (set-vec (u8 0) (identifier "p_ref_610") (identifier "leb128_snd_613"))
                                          (set-vec (u8 0) (identifier "leb_ref_608")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_612") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_609"))) (unsafe-nth (u8 0) (identifier "leb_ref_608"))))
                                          (set-vec (u8 0) (identifier "shft_ref_609") (add (unsafe-nth (u8 0) (identifier "shft_ref_609")) (u8 7))) 
                                          (ge (identifier "leb128_fst_612") (u8 128))))) 
                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_608"))) (unsafe-nth (u8 0) (identifier "p_ref_610")))))))
                          (let-pair "dstring1_fst_615" "dstring1_snd_616" 
                            (identifier "dstring1_614")
                            (let-pair "dstring2_fst_618" "dstring2_snd_619" 
                              (read-bytes (identifier "dstring1_snd_616") (identifier "dstring1_fst_615"))
                              (make-tup
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 3
                                  (make-tup (identifier "dtup_fst_606") (string-of-bytes (identifier "dstring2_fst_618")))) 
                                (identifier "dstring2_snd_619")))))))
                    (if (eq (u16 4) (identifier "dsum1_fst_144"))
                      (make-tup
                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 4
                          (nop)) (identifier "dsum1_snd_145"))
                      (if (eq (u16 5) (identifier "dsum1_fst_144"))
                        (let "dtup_413" (apply (ext-identifier site_name of-row-binary) (identifier "dsum1_snd_145"))
                          (let-pair "dtup_fst_414" "dtup_snd_415" (identifier "dtup_413")
                            (let-pair "dtup_fst_597" "dtup_snd_598"
                              (let "dsum1_422" (let-pair "du16_fst_417" "du16_snd_418" (read-u16 little-endian (identifier "dtup_snd_415")) (make-tup (identifier "du16_fst_417") (identifier "du16_snd_418")))
                                (let-pair "dsum1_fst_423" "dsum1_snd_424" 
                                  (identifier "dsum1_422")
                                  (if (eq (u16 0) (identifier "dsum1_fst_423"))
                                    (make-tup
                                      (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 0
                                        (nop)) (identifier "dsum1_snd_424"))
                                    (if (eq (u16 1) (identifier "dsum1_fst_423"))
                                      (let "dtup_569"
                                        (let "dstring1_563"
                                          (let "leb_ref_557" (make-vec (u32 0))
                                            (let "shft_ref_558" (make-vec (u8 0))
                                              (let "p_ref_559" (make-vec (identifier "dsum1_snd_424"))
                                                (seq
                                                  (while
                                                    (let "leb128_560" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_559")))
                                                      (let-pair "leb128_fst_561" "leb128_snd_562" 
                                                        (identifier "leb128_560")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_559") (identifier "leb128_snd_562"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_557")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_561") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_558")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_557")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_558") (add (unsafe-nth (u8 0) (identifier "shft_ref_558")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_561") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_557"))) (unsafe-nth (u8 0) (identifier "p_ref_559")))))))
                                          (let-pair "dstring1_fst_564" "dstring1_snd_565" 
                                            (identifier "dstring1_563")
                                            (let-pair "dstring2_fst_567" "dstring2_snd_568" 
                                              (read-bytes (identifier "dstring1_snd_565") (identifier "dstring1_fst_564")) 
                                              (make-tup (string-of-bytes (identifier "dstring2_fst_567")) (identifier "dstring2_snd_568")))))
                                        (let-pair "dtup_fst_570" "dtup_snd_571" 
                                          (identifier "dtup_569")
                                          (let-pair "dtup_fst_588" "dtup_snd_589"
                                            (let "dsum1_578" (let-pair "du16_fst_573" "du16_snd_574" (read-u16 little-endian (identifier "dtup_snd_571")) (make-tup (identifier "du16_fst_573") (identifier "du16_snd_574")))
                                              (let-pair "dsum1_fst_579" "dsum1_snd_580" 
                                                (identifier "dsum1_578")
                                                (if (eq (u16 0) (identifier "dsum1_fst_579")) 
                                                  (make-tup (construct "[Host Void | Port Void]" 0 (nop)) (identifier "dsum1_snd_580"))
                                                  (seq (assert (eq (identifier "dsum1_fst_579") (u16 1))) (make-tup (construct "[Host Void | Port Void]" 1 (nop)) (identifier "dsum1_snd_580"))))))
                                            (make-tup
                                              (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 1
                                                (make-tup (identifier "dtup_fst_570") (identifier "dtup_fst_588"))) 
                                              (identifier "dtup_snd_589")))))
                                      (if (eq (u16 2) (identifier "dsum1_fst_423"))
                                        (let "dtup_458" (apply (ext-identifier fq_name of-row-binary) (identifier "dsum1_snd_424"))
                                          (let-pair "dtup_fst_459" "dtup_snd_460" 
                                            (identifier "dtup_458")
                                            (let-pair "dtup_fst_552" "dtup_snd_553"
                                              (let "dsum1_467" (let-pair "du16_fst_462" "du16_snd_463" (read-u16 little-endian (identifier "dtup_snd_460")) (make-tup (identifier "du16_fst_462") (identifier "du16_snd_463")))
                                                (let-pair "dsum1_fst_468" "dsum1_snd_469" 
                                                  (identifier "dsum1_467")
                                                  (if (eq (u16 0) (identifier "dsum1_fst_468"))
                                                    (make-tup
                                                      (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 0
                                                        (nop)) (identifier "dsum1_snd_469"))
                                                    (if (eq (u16 1) (identifier "dsum1_fst_468"))
                                                      (make-tup
                                                        (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 1
                                                          (nop)) (identifier "dsum1_snd_469"))
                                                      (if (eq (u16 2) (identifier "dsum1_fst_468"))
                                                        (make-tup
                                                          (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 2
                                                            (nop)) (identifier "dsum1_snd_469"))
                                                        (if (eq (u16 3) (identifier "dsum1_fst_468"))
                                                          (make-tup
                                                            (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 3
                                                              (nop)) 
                                                            (identifier "dsum1_snd_469"))
                                                          (if (eq (u16 4) (identifier "dsum1_fst_468"))
                                                            (make-tup
                                                              (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 4
                                                                (nop)) 
                                                              (identifier "dsum1_snd_469"))
                                                            (if (eq (u16 5) (identifier "dsum1_fst_468"))
                                                              (make-tup
                                                                (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 5
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_469"))
                                                              (if (eq (u16 6) (identifier "dsum1_fst_468"))
                                                                (let "dtup_491"
                                                                  (let "dstring1_485"
                                                                    (let "leb_ref_479" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_480" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_481" 
                                                                    (make-vec (identifier "dsum1_snd_469"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_482" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_481")))
                                                                    (let-pair "leb128_fst_483" "leb128_snd_484" 
                                                                    (identifier "leb128_482")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_481") (identifier "leb128_snd_484"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_479")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_483") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_480")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_479")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_480") (add (unsafe-nth (u8 0) (identifier "shft_ref_480")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_483") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_479"))) (unsafe-nth (u8 0) (identifier "p_ref_481")))))))
                                                                    (let-pair "dstring1_fst_486" "dstring1_snd_487" 
                                                                    (identifier "dstring1_485")
                                                                    (let-pair "dstring2_fst_489" "dstring2_snd_490" 
                                                                    (read-bytes (identifier "dstring1_snd_487") (identifier "dstring1_fst_486"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_489")) (identifier "dstring2_snd_490")))))
                                                                  (let-pair "dtup_fst_492" "dtup_snd_493" 
                                                                    (identifier "dtup_491")
                                                                    (let-pair "dtup_fst_528" "dtup_snd_529"
                                                                    (let "dsum1_500"
                                                                    (let-pair "du16_fst_495" "du16_snd_496" (read-u16 little-endian (identifier "dtup_snd_493")) (make-tup (identifier "du16_fst_495") (identifier "du16_snd_496")))
                                                                    (let-pair "dsum1_fst_501" "dsum1_snd_502" 
                                                                    (identifier "dsum1_500")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_501"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 0
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_502"))
                                                                    (if 
                                                                    (eq (u16 1) (identifier "dsum1_fst_501"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 1
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_502"))
                                                                    (if 
                                                                    (eq (u16 2) (identifier "dsum1_fst_501"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 2
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_502"))
                                                                    (if 
                                                                    (eq (u16 3) (identifier "dsum1_fst_501"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 3
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_502"))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "dsum1_fst_501"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 4
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_502"))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "dsum1_fst_501"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 5
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_502"))
                                                                    (if 
                                                                    (eq (u16 6) (identifier "dsum1_fst_501"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 6
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_502"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_501") (u16 7)))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 7
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_502"))))))))))))
                                                                    (make-tup
                                                                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 6
                                                                    (make-tup (identifier "dtup_fst_492") (identifier "dtup_fst_528"))) 
                                                                    (identifier "dtup_snd_529")))))
                                                                (if (eq (u16 7) (identifier "dsum1_fst_468"))
                                                                  (let-pair "du32_fst_474" "du32_snd_475" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_469"))
                                                                    (make-tup
                                                                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 7
                                                                    (identifier "du32_fst_474")) 
                                                                    (identifier "du32_snd_475")))
                                                                  (seq 
                                                                    (assert (eq (identifier "dsum1_fst_468") (u16 8)))
                                                                    (make-tup
                                                                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 8
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_469")))))))))))))
                                              (make-tup
                                                (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 2
                                                  (make-tup (identifier "dtup_fst_459") (identifier "dtup_fst_552"))) 
                                                (identifier "dtup_snd_553")))))
                                        (seq (assert (eq (identifier "dsum1_fst_423") (u16 3)))
                                          (let "dtup_437"
                                            (let "dstring1_431"
                                              (let "leb_ref_425" (make-vec (u32 0))
                                                (let "shft_ref_426" (make-vec (u8 0))
                                                  (let "p_ref_427" (make-vec (identifier "dsum1_snd_424"))
                                                    (seq
                                                      (while
                                                        (let "leb128_428" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_427")))
                                                          (let-pair "leb128_fst_429" "leb128_snd_430" 
                                                            (identifier "leb128_428")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_427") (identifier "leb128_snd_430"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_425")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_429") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_426")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_425")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_426") (add (unsafe-nth (u8 0) (identifier "shft_ref_426")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_429") (u8 128))))) 
                                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_425"))) (unsafe-nth (u8 0) (identifier "p_ref_427")))))))
                                              (let-pair "dstring1_fst_432" "dstring1_snd_433" 
                                                (identifier "dstring1_431")
                                                (let-pair "dstring2_fst_435" "dstring2_snd_436" 
                                                  (read-bytes (identifier "dstring1_snd_433") (identifier "dstring1_fst_432")) 
                                                  (make-tup (string-of-bytes (identifier "dstring2_fst_435")) (identifier "dstring2_snd_436")))))
                                            (let-pair "dtup_fst_438" "dtup_snd_439" 
                                              (identifier "dtup_437")
                                              (let "dsum1_446" (let-pair "du16_fst_441" "du16_snd_442" (read-u16 little-endian (identifier "dtup_snd_439")) (make-tup (identifier "du16_fst_441") (identifier "du16_snd_442")))
                                                (let-pair "dsum1_fst_447" "dsum1_snd_448" 
                                                  (identifier "dsum1_446")
                                                  (seq (assert (eq (identifier "dsum1_fst_447") (u16 0)))
                                                    (make-tup
                                                      (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 3
                                                        (make-tup (identifier "dtup_fst_438") (construct "[Executable Void]" 0 (nop)))) 
                                                      (identifier "dsum1_snd_448")))))))))))))
                              (make-tup
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 5
                                  (make-tup (identifier "dtup_fst_414") (identifier "dtup_fst_597"))) 
                                (identifier "dtup_snd_598")))))
                        (if (eq (u16 6) (identifier "dsum1_fst_144"))
                          (let-pair "dsum2_fst_411" "dsum2_snd_412"
                            (let "dsum1_386" (let-pair "du16_fst_381" "du16_snd_382" (read-u16 little-endian (identifier "dsum1_snd_145")) (make-tup (identifier "du16_fst_381") (identifier "du16_snd_382")))
                              (let-pair "dsum1_fst_387" "dsum1_snd_388" 
                                (identifier "dsum1_386")
                                (if (eq (u16 0) (identifier "dsum1_fst_387")) 
                                  (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 0 (nop)) (identifier "dsum1_snd_388"))
                                  (if (eq (u16 1) (identifier "dsum1_fst_387")) 
                                    (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 1 (nop)) (identifier "dsum1_snd_388"))
                                    (seq (assert (eq (identifier "dsum1_fst_387") (u16 2)))
                                      (let "dstring1_395"
                                        (let "leb_ref_389" (make-vec (u32 0))
                                          (let "shft_ref_390" (make-vec (u8 0))
                                            (let "p_ref_391" (make-vec (identifier "dsum1_snd_388"))
                                              (seq
                                                (while
                                                  (let "leb128_392" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_391")))
                                                    (let-pair "leb128_fst_393" "leb128_snd_394" 
                                                      (identifier "leb128_392")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_391") (identifier "leb128_snd_394"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_389")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_393") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_390")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_389")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_390") (add (unsafe-nth (u8 0) (identifier "shft_ref_390")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_393") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_389"))) (unsafe-nth (u8 0) (identifier "p_ref_391")))))))
                                        (let-pair "dstring1_fst_396" "dstring1_snd_397" 
                                          (identifier "dstring1_395")
                                          (let-pair "dstring2_fst_399" "dstring2_snd_400" 
                                            (read-bytes (identifier "dstring1_snd_397") (identifier "dstring1_fst_396"))
                                            (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 2 (string-of-bytes (identifier "dstring2_fst_399"))) (identifier "dstring2_snd_400"))))))))))
                            (make-tup
                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 6
                                (identifier "dsum2_fst_411")) (identifier "dsum2_snd_412")))
                          (if (eq (u16 7) (identifier "dsum1_fst_144"))
                            (let "dtup_353" (apply (ext-identifier site_name of-row-binary) (identifier "dsum1_snd_145"))
                              (let-pair "dtup_fst_354" "dtup_snd_355" 
                                (identifier "dtup_353")
                                (let "dtup_356" (apply (ext-identifier fq_name of-row-binary) (identifier "dtup_snd_355"))
                                  (let-pair "dtup_fst_357" "dtup_snd_358" 
                                    (identifier "dtup_356")
                                    (let "dtup_371"
                                      (let "dstring1_365"
                                        (let "leb_ref_359" (make-vec (u32 0))
                                          (let "shft_ref_360" (make-vec (u8 0))
                                            (let "p_ref_361" (make-vec (identifier "dtup_snd_358"))
                                              (seq
                                                (while
                                                  (let "leb128_362" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_361")))
                                                    (let-pair "leb128_fst_363" "leb128_snd_364" 
                                                      (identifier "leb128_362")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_361") (identifier "leb128_snd_364"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_359")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_363") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_360")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_359")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_360") (add (unsafe-nth (u8 0) (identifier "shft_ref_360")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_363") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_359"))) (unsafe-nth (u8 0) (identifier "p_ref_361")))))))
                                        (let-pair "dstring1_fst_366" "dstring1_snd_367" 
                                          (identifier "dstring1_365")
                                          (let-pair "dstring2_fst_369" "dstring2_snd_370" 
                                            (read-bytes (identifier "dstring1_snd_367") (identifier "dstring1_fst_366")) 
                                            (make-tup (string-of-bytes (identifier "dstring2_fst_369")) (identifier "dstring2_snd_370")))))
                                      (let-pair "dtup_fst_372" "dtup_snd_373" 
                                        (identifier "dtup_371")
                                        (let-pair "dtup_fst_375" "dtup_snd_376" 
                                          (apply (identifier "per_tail-of-row-binary") (identifier "dtup_snd_373"))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 7
                                              (make-tup (identifier "dtup_fst_354") (identifier "dtup_fst_357") (identifier "dtup_fst_372") (identifier "dtup_fst_375"))) 
                                            (identifier "dtup_snd_376")))))))))
                            (if (eq (u16 8) (identifier "dsum1_fst_144"))
                              (let-pair "du16_fst_348" "du16_snd_349" 
                                (read-u16 little-endian (identifier "dsum1_snd_145"))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 8
                                    (identifier "du16_fst_348")) (identifier "du16_snd_349")))
                              (if (eq (u16 9) (identifier "dsum1_fst_144"))
                                (let-pair "dsum2_fst_345" "dsum2_snd_346"
                                  (if (eq (peek-u8 (identifier "dsum1_snd_145") (size 0)) (u8 1)) 
                                    (make-tup (null "$sync_socket") (ptr-add (identifier "dsum1_snd_145") (size 1)))
                                    (let-pair "make1_1_fst_342" "make1_1_snd_343" 
                                      (apply (ext-identifier sync_socket of-row-binary) (ptr-add (identifier "dsum1_snd_145") (size 1))) 
                                      (make-tup (not-null (identifier "make1_1_fst_342")) (identifier "make1_1_snd_343"))))
                                  (make-tup
                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 9
                                      (identifier "dsum2_fst_345")) (identifier "dsum2_snd_346")))
                                (if (eq (u16 10) (identifier "dsum1_fst_144"))
                                  (make-tup
                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 10
                                      (nop)) (identifier "dsum1_snd_145"))
                                  (if (eq (u16 11) (identifier "dsum1_fst_144"))
                                    (let "dtup_329" (apply (ext-identifier sync_socket of-row-binary) (identifier "dsum1_snd_145"))
                                      (let-pair "dtup_fst_330" "dtup_snd_331" 
                                        (identifier "dtup_329")
                                        (let-pair "dtup_fst_333" "dtup_snd_334" 
                                          (apply (identifier "per_client-of-row-binary") (identifier "dtup_snd_331"))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 11
                                              (make-tup (identifier "dtup_fst_330") (identifier "dtup_fst_333"))) 
                                            (identifier "dtup_snd_334")))))
                                    (if (eq (u16 12) (identifier "dsum1_fst_144"))
                                      (let "dtup_320"
                                        (let "dstring1_314"
                                          (let "leb_ref_308" (make-vec (u32 0))
                                            (let "shft_ref_309" (make-vec (u8 0))
                                              (let "p_ref_310" (make-vec (identifier "dsum1_snd_145"))
                                                (seq
                                                  (while
                                                    (let "leb128_311" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_310")))
                                                      (let-pair "leb128_fst_312" "leb128_snd_313" 
                                                        (identifier "leb128_311")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_310") (identifier "leb128_snd_313"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_308")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_312") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_309")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_308")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_309") (add (unsafe-nth (u8 0) (identifier "shft_ref_309")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_312") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_308"))) (unsafe-nth (u8 0) (identifier "p_ref_310")))))))
                                          (let-pair "dstring1_fst_315" "dstring1_snd_316" 
                                            (identifier "dstring1_314")
                                            (let-pair "dstring2_fst_318" "dstring2_snd_319" 
                                              (read-bytes (identifier "dstring1_snd_316") (identifier "dstring1_fst_315")) 
                                              (make-tup (string-of-bytes (identifier "dstring2_fst_318")) (identifier "dstring2_snd_319")))))
                                        (let-pair "dtup_fst_321" "dtup_snd_322" 
                                          (identifier "dtup_320")
                                          (let-pair "dtup_fst_324" "dtup_snd_325" 
                                            (apply (identifier "per_dash_key-of-row-binary") (identifier "dtup_snd_322"))
                                            (make-tup
                                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 12
                                                (make-tup (identifier "dtup_fst_321") (identifier "dtup_fst_324"))) 
                                              (identifier "dtup_snd_325")))))
                                      (if (eq (u16 13) (identifier "dsum1_fst_144"))
                                        (make-tup
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 13
                                            (nop)) (identifier "dsum1_snd_145"))
                                        (if (eq (u16 14) (identifier "dsum1_fst_144"))
                                          (let "dtup_257" (apply (ext-identifier team_name of-row-binary) (identifier "dsum1_snd_145"))
                                            (let-pair "dtup_fst_258" "dtup_snd_259" 
                                              (identifier "dtup_257")
                                              (let-pair "dtup_fst_300" "dtup_snd_301"
                                                (let "dsum1_266" (let-pair "du16_fst_261" "du16_snd_262" (read-u16 little-endian (identifier "dtup_snd_259")) (make-tup (identifier "du16_fst_261") (identifier "du16_snd_262")))
                                                  (let-pair "dsum1_fst_267" "dsum1_snd_268" 
                                                    (identifier "dsum1_266")
                                                    (if (eq (u16 0) (identifier "dsum1_fst_267"))
                                                      (let "dstring1_290"
                                                        (let "leb_ref_284" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_285" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_286" 
                                                              (make-vec (identifier "dsum1_snd_268"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_287" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_286")))
                                                                    (let-pair "leb128_fst_288" "leb128_snd_289" 
                                                                    (identifier "leb128_287")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_286") (identifier "leb128_snd_289"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_284")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_288") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_285")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_284")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_285") (add (unsafe-nth (u8 0) (identifier "shft_ref_285")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_288") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_284"))) (unsafe-nth (u8 0) (identifier "p_ref_286")))))))
                                                        (let-pair "dstring1_fst_291" "dstring1_snd_292" 
                                                          (identifier "dstring1_290")
                                                          (let-pair "dstring2_fst_294" "dstring2_snd_295" 
                                                            (read-bytes (identifier "dstring1_snd_292") (identifier "dstring1_fst_291"))
                                                            (make-tup (construct "[Contacts STRING | Inhibition STRING]" 0 (string-of-bytes (identifier "dstring2_fst_294"))) (identifier "dstring2_snd_295")))))
                                                      (seq (assert (eq (identifier "dsum1_fst_267") (u16 1)))
                                                        (let "dstring1_275"
                                                          (let "leb_ref_269" 
                                                            (make-vec (u32 0))
                                                            (let "shft_ref_270" 
                                                              (make-vec (u8 0))
                                                              (let "p_ref_271" 
                                                                (make-vec (identifier "dsum1_snd_268"))
                                                                (seq
                                                                  (while
                                                                    (let "leb128_272" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_271")))
                                                                    (let-pair "leb128_fst_273" "leb128_snd_274" 
                                                                    (identifier "leb128_272")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_271") (identifier "leb128_snd_274"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_269")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_273") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_270")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_269")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_270") (add (unsafe-nth (u8 0) (identifier "shft_ref_270")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_273") (u8 128))))) 
                                                                    (nop)) 
                                                                  (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_269"))) (unsafe-nth (u8 0) (identifier "p_ref_271")))))))
                                                          (let-pair "dstring1_fst_276" "dstring1_snd_277" 
                                                            (identifier "dstring1_275")
                                                            (let-pair "dstring2_fst_279" "dstring2_snd_280" 
                                                              (read-bytes (identifier "dstring1_snd_277") (identifier "dstring1_fst_276"))
                                                              (make-tup (construct "[Contacts STRING | Inhibition STRING]" 1 (string-of-bytes (identifier "dstring2_fst_279"))) (identifier "dstring2_snd_280")))))))))
                                                (make-tup
                                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 14
                                                    (make-tup (identifier "dtup_fst_258") (identifier "dtup_fst_300"))) 
                                                  (identifier "dtup_snd_301")))))
                                          (seq (assert (eq (identifier "dsum1_fst_144") (u16 15)))
                                            (let "dtup_158"
                                              (let "dstring1_152"
                                                (let "leb_ref_146" (make-vec (u32 0))
                                                  (let "shft_ref_147" 
                                                    (make-vec (u8 0))
                                                    (let "p_ref_148" 
                                                      (make-vec (identifier "dsum1_snd_145"))
                                                      (seq
                                                        (while
                                                          (let "leb128_149" 
                                                            (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_148")))
                                                            (let-pair "leb128_fst_150" "leb128_snd_151" 
                                                              (identifier "leb128_149")
                                                              (seq (set-vec (u8 0) (identifier "p_ref_148") (identifier "leb128_snd_151"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_146")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_150") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_147")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_146")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_147") (add (unsafe-nth (u8 0) (identifier "shft_ref_147")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_150") (u8 128))))) 
                                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_146"))) (unsafe-nth (u8 0) (identifier "p_ref_148")))))))
                                                (let-pair "dstring1_fst_153" "dstring1_snd_154" 
                                                  (identifier "dstring1_152")
                                                  (let-pair "dstring2_fst_156" "dstring2_snd_157" 
                                                    (read-bytes (identifier "dstring1_snd_154") (identifier "dstring1_fst_153")) 
                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_156")) (identifier "dstring2_snd_157")))))
                                              (let-pair "dtup_fst_159" "dtup_snd_160" 
                                                (identifier "dtup_158")
                                                (let-pair "dtup_fst_252" "dtup_snd_253"
                                                  (let "dsum1_167" (let-pair "du16_fst_162" "du16_snd_163" (read-u16 little-endian (identifier "dtup_snd_160")) (make-tup (identifier "du16_fst_162") (identifier "du16_snd_163")))
                                                    (let-pair "dsum1_fst_168" "dsum1_snd_169" 
                                                      (identifier "dsum1_167")
                                                      (if (eq (u16 0) (identifier "dsum1_fst_168"))
                                                        (make-tup
                                                          (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 0
                                                            (nop)) (identifier "dsum1_snd_169"))
                                                        (if (eq (u16 1) (identifier "dsum1_fst_168"))
                                                          (make-tup
                                                            (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 1
                                                              (nop)) 
                                                            (identifier "dsum1_snd_169"))
                                                          (if (eq (u16 2) (identifier "dsum1_fst_168"))
                                                            (make-tup
                                                              (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 2
                                                                (nop)) 
                                                              (identifier "dsum1_snd_169"))
                                                            (if (eq (u16 3) (identifier "dsum1_fst_168"))
                                                              (make-tup
                                                                (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 3
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_169"))
                                                              (if (eq (u16 4) (identifier "dsum1_fst_168"))
                                                                (make-tup
                                                                  (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 4
                                                                    (nop)) 
                                                                  (identifier "dsum1_snd_169"))
                                                                (if (eq (u16 5) (identifier "dsum1_fst_168"))
                                                                  (let "dtup_197"
                                                                    (let "dstring1_191"
                                                                    (let "leb_ref_185" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_186" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_187" 
                                                                    (make-vec (identifier "dsum1_snd_169"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_188" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_187")))
                                                                    (let-pair "leb128_fst_189" "leb128_snd_190" 
                                                                    (identifier "leb128_188")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_187") (identifier "leb128_snd_190"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_185")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_189") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_186")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_185")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_186") (add (unsafe-nth (u8 0) (identifier "shft_ref_186")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_189") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_185"))) (unsafe-nth (u8 0) (identifier "p_ref_187")))))))
                                                                    (let-pair "dstring1_fst_192" "dstring1_snd_193" 
                                                                    (identifier "dstring1_191")
                                                                    (let-pair "dstring2_fst_195" "dstring2_snd_196" 
                                                                    (read-bytes (identifier "dstring1_snd_193") (identifier "dstring1_fst_192"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_195")) (identifier "dstring2_snd_196")))))
                                                                    (let-pair "dtup_fst_198" "dtup_snd_199" 
                                                                    (identifier "dtup_197")
                                                                    (let-pair "dtup_fst_231" "dtup_snd_232"
                                                                    (let "dsum1_206"
                                                                    (let-pair "du16_fst_201" "du16_snd_202" (read-u16 little-endian (identifier "dtup_snd_199")) (make-tup (identifier "du16_fst_201") (identifier "du16_snd_202")))
                                                                    (let-pair "dsum1_fst_207" "dsum1_snd_208" 
                                                                    (identifier "dsum1_206")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_207"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 0
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_208"))
                                                                    (if 
                                                                    (eq (u16 1) (identifier "dsum1_fst_207"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 1
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_208"))
                                                                    (if 
                                                                    (eq (u16 2) (identifier "dsum1_fst_207"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 2
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_208"))
                                                                    (if 
                                                                    (eq (u16 3) (identifier "dsum1_fst_207"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 3
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_208"))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "dsum1_fst_207"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 4
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_208"))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "dsum1_fst_207"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 5
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_208"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_207") (u16 6)))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 6
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_208")))))))))))
                                                                    (make-tup
                                                                    (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 5
                                                                    (make-tup (identifier "dtup_fst_198") (identifier "dtup_fst_231"))) 
                                                                    (identifier "dtup_snd_232")))))
                                                                  (seq 
                                                                    (assert (eq (identifier "dsum1_fst_168") (u16 6)))
                                                                    (let "dtup_173"
                                                                    (let-pair "dfloat_fst_171" "dfloat_snd_172" 
                                                                    (read-u64 little-endian (identifier "dsum1_snd_169")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_171")) (identifier "dfloat_snd_172")))
                                                                    (let-pair "dtup_fst_174" "dtup_snd_175" 
                                                                    (identifier "dtup_173")
                                                                    (let-pair "du32_fst_177" "du32_snd_178" 
                                                                    (read-u32 little-endian (identifier "dtup_snd_175"))
                                                                    (make-tup
                                                                    (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 6
                                                                    (make-tup (identifier "dtup_fst_174") (identifier "du32_fst_177"))) 
                                                                    (identifier "du32_snd_178"))))))))))))))
                                                  (make-tup
                                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 15
                                                      (make-tup (identifier "dtup_fst_159") (identifier "dtup_fst_252"))) 
                                                    (identifier "dtup_snd_253"))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_648") (identifier "make_snd_649"))))
 */
static std::function<::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f(Pointer)> fun2058 { [&fun2058](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2059 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2060;
    {
      auto du16_fst_138 { std::get<0>(id_2059) };
      auto du16_snd_139 { std::get<1>(id_2059) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2061 { du16_fst_138, du16_snd_139 };
      letpair_res_2060 = id_2061;
    }
    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2062;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_143 { letpair_res_2060 };
      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2063;
      {
        auto dsum1_fst_144 { std::get<0>(dsum1_143) };
        auto dsum1_snd_145 { std::get<1>(dsum1_143) };
        uint16_t id_2064 { 0 };
        bool id_2065 { bool(id_2064 == dsum1_fst_144) };
        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2066;
        if (id_2065) {
          (void)VOID;
          std::shared_ptr<::dessser::gen::sync_key::t>  id_2067 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<0>, VOID) };
          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2068 { id_2067, dsum1_snd_145 };
          choose_res_2066 = id_2068;
        } else {
          uint16_t id_2069 { 1 };
          bool id_2070 { bool(id_2069 == dsum1_fst_144) };
          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2071;
          if (id_2070) {
            (void)VOID;
            std::shared_ptr<::dessser::gen::sync_key::t>  id_2072 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<1>, VOID) };
            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2073 { id_2072, dsum1_snd_145 };
            choose_res_2071 = id_2073;
          } else {
            uint16_t id_2074 { 2 };
            bool id_2075 { bool(id_2074 == dsum1_fst_144) };
            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2076;
            if (id_2075) {
              uint32_t id_2077 { 0U };
              Vec<1, uint32_t> id_2078 {  id_2077  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2079;
              {
                Vec<1, uint32_t> leb_ref_626 { id_2078 };
                uint8_t id_2080 { 0 };
                Vec<1, uint8_t> id_2081 {  id_2080  };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2082;
                {
                  Vec<1, uint8_t> shft_ref_627 { id_2081 };
                  Vec<1, Pointer> id_2083 {  dsum1_snd_145  };
                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2084;
                  {
                    Vec<1, Pointer> p_ref_628 { id_2083 };
                    bool while_flag_2085 { true };
                    do {
                      uint8_t id_2086 { 0 };
                      Pointer id_2087 { p_ref_628[id_2086] };
                      ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2088 { id_2087.readU8() };
                      bool let_res_2089;
                      {
                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_629 { id_2088 };
                        bool letpair_res_2090;
                        {
                          auto leb128_fst_630 { std::get<0>(leb128_629) };
                          auto leb128_snd_631 { std::get<1>(leb128_629) };
                          uint8_t id_2091 { 0 };
                          Void id_2092 { ((void)(p_ref_628[id_2091] = leb128_snd_631), VOID) };
                          (void)id_2092;
                          uint8_t id_2093 { 0 };
                          uint8_t id_2094 { 127 };
                          uint8_t id_2095 { uint8_t(leb128_fst_630 & id_2094) };
                          uint32_t id_2096 { uint32_t(id_2095) };
                          uint8_t id_2097 { 0 };
                          uint8_t id_2098 { shft_ref_627[id_2097] };
                          uint32_t id_2099 { uint32_t(id_2096 << id_2098) };
                          uint8_t id_2100 { 0 };
                          uint32_t id_2101 { leb_ref_626[id_2100] };
                          uint32_t id_2102 { uint32_t(id_2099 | id_2101) };
                          Void id_2103 { ((void)(leb_ref_626[id_2093] = id_2102), VOID) };
                          (void)id_2103;
                          uint8_t id_2104 { 0 };
                          uint8_t id_2105 { 0 };
                          uint8_t id_2106 { shft_ref_627[id_2105] };
                          uint8_t id_2107 { 7 };
                          uint8_t id_2108 { uint8_t(id_2106 + id_2107) };
                          Void id_2109 { ((void)(shft_ref_627[id_2104] = id_2108), VOID) };
                          (void)id_2109;
                          uint8_t id_2110 { 128 };
                          bool id_2111 { bool(leb128_fst_630 >= id_2110) };
                          letpair_res_2090 = id_2111;
                        }
                        let_res_2089 = letpair_res_2090;
                      }
                      while_flag_2085 = let_res_2089;
                      if (while_flag_2085) {
                        (void)VOID;
                      }
                    } while (while_flag_2085);
                    (void)VOID;
                    uint8_t id_2112 { 0 };
                    uint32_t id_2113 { leb_ref_626[id_2112] };
                    Size id_2114 { Size(id_2113) };
                    uint8_t id_2115 { 0 };
                    Pointer id_2116 { p_ref_628[id_2115] };
                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2117 { id_2114, id_2116 };
                    let_res_2084 = id_2117;
                  }
                  let_res_2082 = let_res_2084;
                }
                let_res_2079 = let_res_2082;
              }
              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2118;
              {
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_632 { let_res_2079 };
                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2119;
                {
                  auto dstring1_fst_633 { std::get<0>(dstring1_632) };
                  auto dstring1_snd_634 { std::get<1>(dstring1_632) };
                  ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2120 { dstring1_snd_634.readBytes(dstring1_fst_633) };
                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2121;
                  {
                    auto dstring2_fst_636 { std::get<0>(id_2120) };
                    auto dstring2_snd_637 { std::get<1>(id_2120) };
                    std::string id_2122 { dstring2_fst_636.toString() };
                    std::shared_ptr<::dessser::gen::sync_key::t>  id_2123 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<2>, id_2122) };
                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2124 { id_2123, dstring2_snd_637 };
                    letpair_res_2121 = id_2124;
                  }
                  letpair_res_2119 = letpair_res_2121;
                }
                let_res_2118 = letpair_res_2119;
              }
              choose_res_2076 = let_res_2118;
            } else {
              uint16_t id_2125 { 3 };
              bool id_2126 { bool(id_2125 == dsum1_fst_144) };
              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2127;
              if (id_2126) {
                auto fun2128 { dessser::gen::src_path::of_row_binary };
                ::dessser::gen::sync_key::t6886b6ff042edb771f45016f12178bb0 id_2129 { fun2128(dsum1_snd_145) };
                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2130;
                {
                  ::dessser::gen::sync_key::t6886b6ff042edb771f45016f12178bb0 dtup_605 { id_2129 };
                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2131;
                  {
                    auto dtup_fst_606 { std::get<0>(dtup_605) };
                    auto dtup_snd_607 { std::get<1>(dtup_605) };
                    uint32_t id_2132 { 0U };
                    Vec<1, uint32_t> id_2133 {  id_2132  };
                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2134;
                    {
                      Vec<1, uint32_t> leb_ref_608 { id_2133 };
                      uint8_t id_2135 { 0 };
                      Vec<1, uint8_t> id_2136 {  id_2135  };
                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2137;
                      {
                        Vec<1, uint8_t> shft_ref_609 { id_2136 };
                        Vec<1, Pointer> id_2138 {  dtup_snd_607  };
                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2139;
                        {
                          Vec<1, Pointer> p_ref_610 { id_2138 };
                          bool while_flag_2140 { true };
                          do {
                            uint8_t id_2141 { 0 };
                            Pointer id_2142 { p_ref_610[id_2141] };
                            ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2143 { id_2142.readU8() };
                            bool let_res_2144;
                            {
                              ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_611 { id_2143 };
                              bool letpair_res_2145;
                              {
                                auto leb128_fst_612 { std::get<0>(leb128_611) };
                                auto leb128_snd_613 { std::get<1>(leb128_611) };
                                uint8_t id_2146 { 0 };
                                Void id_2147 { ((void)(p_ref_610[id_2146] = leb128_snd_613), VOID) };
                                (void)id_2147;
                                uint8_t id_2148 { 0 };
                                uint8_t id_2149 { 127 };
                                uint8_t id_2150 { uint8_t(leb128_fst_612 & id_2149) };
                                uint32_t id_2151 { uint32_t(id_2150) };
                                uint8_t id_2152 { 0 };
                                uint8_t id_2153 { shft_ref_609[id_2152] };
                                uint32_t id_2154 { uint32_t(id_2151 << id_2153) };
                                uint8_t id_2155 { 0 };
                                uint32_t id_2156 { leb_ref_608[id_2155] };
                                uint32_t id_2157 { uint32_t(id_2154 | id_2156) };
                                Void id_2158 { ((void)(leb_ref_608[id_2148] = id_2157), VOID) };
                                (void)id_2158;
                                uint8_t id_2159 { 0 };
                                uint8_t id_2160 { 0 };
                                uint8_t id_2161 { shft_ref_609[id_2160] };
                                uint8_t id_2162 { 7 };
                                uint8_t id_2163 { uint8_t(id_2161 + id_2162) };
                                Void id_2164 { ((void)(shft_ref_609[id_2159] = id_2163), VOID) };
                                (void)id_2164;
                                uint8_t id_2165 { 128 };
                                bool id_2166 { bool(leb128_fst_612 >= id_2165) };
                                letpair_res_2145 = id_2166;
                              }
                              let_res_2144 = letpair_res_2145;
                            }
                            while_flag_2140 = let_res_2144;
                            if (while_flag_2140) {
                              (void)VOID;
                            }
                          } while (while_flag_2140);
                          (void)VOID;
                          uint8_t id_2167 { 0 };
                          uint32_t id_2168 { leb_ref_608[id_2167] };
                          Size id_2169 { Size(id_2168) };
                          uint8_t id_2170 { 0 };
                          Pointer id_2171 { p_ref_610[id_2170] };
                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2172 { id_2169, id_2171 };
                          let_res_2139 = id_2172;
                        }
                        let_res_2137 = let_res_2139;
                      }
                      let_res_2134 = let_res_2137;
                    }
                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2173;
                    {
                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_614 { let_res_2134 };
                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2174;
                      {
                        auto dstring1_fst_615 { std::get<0>(dstring1_614) };
                        auto dstring1_snd_616 { std::get<1>(dstring1_614) };
                        ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2175 { dstring1_snd_616.readBytes(dstring1_fst_615) };
                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2176;
                        {
                          auto dstring2_fst_618 { std::get<0>(id_2175) };
                          auto dstring2_snd_619 { std::get<1>(id_2175) };
                          std::string id_2177 { dstring2_fst_618.toString() };
                          ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_2178 { dtup_fst_606, id_2177 };
                          std::shared_ptr<::dessser::gen::sync_key::t>  id_2179 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<3>, id_2178) };
                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2180 { id_2179, dstring2_snd_619 };
                          letpair_res_2176 = id_2180;
                        }
                        letpair_res_2174 = letpair_res_2176;
                      }
                      let_res_2173 = letpair_res_2174;
                    }
                    letpair_res_2131 = let_res_2173;
                  }
                  let_res_2130 = letpair_res_2131;
                }
                choose_res_2127 = let_res_2130;
              } else {
                uint16_t id_2181 { 4 };
                bool id_2182 { bool(id_2181 == dsum1_fst_144) };
                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2183;
                if (id_2182) {
                  (void)VOID;
                  std::shared_ptr<::dessser::gen::sync_key::t>  id_2184 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<4>, VOID) };
                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2185 { id_2184, dsum1_snd_145 };
                  choose_res_2183 = id_2185;
                } else {
                  uint16_t id_2186 { 5 };
                  bool id_2187 { bool(id_2186 == dsum1_fst_144) };
                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2188;
                  if (id_2187) {
                    auto fun2189 { dessser::gen::site_name::of_row_binary };
                    ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea id_2190 { fun2189(dsum1_snd_145) };
                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2191;
                    {
                      ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea dtup_413 { id_2190 };
                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2192;
                      {
                        auto dtup_fst_414 { std::get<0>(dtup_413) };
                        auto dtup_snd_415 { std::get<1>(dtup_413) };
                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2193 { dtup_snd_415.readU16Le() };
                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2194;
                        {
                          auto du16_fst_417 { std::get<0>(id_2193) };
                          auto du16_snd_418 { std::get<1>(id_2193) };
                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2195 { du16_fst_417, du16_snd_418 };
                          letpair_res_2194 = id_2195;
                        }
                        ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 let_res_2196;
                        {
                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_422 { letpair_res_2194 };
                          ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2197;
                          {
                            auto dsum1_fst_423 { std::get<0>(dsum1_422) };
                            auto dsum1_snd_424 { std::get<1>(dsum1_422) };
                            uint16_t id_2198 { 0 };
                            bool id_2199 { bool(id_2198 == dsum1_fst_423) };
                            ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 choose_res_2200;
                            if (id_2199) {
                              (void)VOID;
                              ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_2201 { std::in_place_index<0>, VOID };
                              ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 id_2202 { id_2201, dsum1_snd_424 };
                              choose_res_2200 = id_2202;
                            } else {
                              uint16_t id_2203 { 1 };
                              bool id_2204 { bool(id_2203 == dsum1_fst_423) };
                              ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 choose_res_2205;
                              if (id_2204) {
                                uint32_t id_2206 { 0U };
                                Vec<1, uint32_t> id_2207 {  id_2206  };
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2208;
                                {
                                  Vec<1, uint32_t> leb_ref_557 { id_2207 };
                                  uint8_t id_2209 { 0 };
                                  Vec<1, uint8_t> id_2210 {  id_2209  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2211;
                                  {
                                    Vec<1, uint8_t> shft_ref_558 { id_2210 };
                                    Vec<1, Pointer> id_2212 {  dsum1_snd_424  };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2213;
                                    {
                                      Vec<1, Pointer> p_ref_559 { id_2212 };
                                      bool while_flag_2214 { true };
                                      do {
                                        uint8_t id_2215 { 0 };
                                        Pointer id_2216 { p_ref_559[id_2215] };
                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2217 { id_2216.readU8() };
                                        bool let_res_2218;
                                        {
                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_560 { id_2217 };
                                          bool letpair_res_2219;
                                          {
                                            auto leb128_fst_561 { std::get<0>(leb128_560) };
                                            auto leb128_snd_562 { std::get<1>(leb128_560) };
                                            uint8_t id_2220 { 0 };
                                            Void id_2221 { ((void)(p_ref_559[id_2220] = leb128_snd_562), VOID) };
                                            (void)id_2221;
                                            uint8_t id_2222 { 0 };
                                            uint8_t id_2223 { 127 };
                                            uint8_t id_2224 { uint8_t(leb128_fst_561 & id_2223) };
                                            uint32_t id_2225 { uint32_t(id_2224) };
                                            uint8_t id_2226 { 0 };
                                            uint8_t id_2227 { shft_ref_558[id_2226] };
                                            uint32_t id_2228 { uint32_t(id_2225 << id_2227) };
                                            uint8_t id_2229 { 0 };
                                            uint32_t id_2230 { leb_ref_557[id_2229] };
                                            uint32_t id_2231 { uint32_t(id_2228 | id_2230) };
                                            Void id_2232 { ((void)(leb_ref_557[id_2222] = id_2231), VOID) };
                                            (void)id_2232;
                                            uint8_t id_2233 { 0 };
                                            uint8_t id_2234 { 0 };
                                            uint8_t id_2235 { shft_ref_558[id_2234] };
                                            uint8_t id_2236 { 7 };
                                            uint8_t id_2237 { uint8_t(id_2235 + id_2236) };
                                            Void id_2238 { ((void)(shft_ref_558[id_2233] = id_2237), VOID) };
                                            (void)id_2238;
                                            uint8_t id_2239 { 128 };
                                            bool id_2240 { bool(leb128_fst_561 >= id_2239) };
                                            letpair_res_2219 = id_2240;
                                          }
                                          let_res_2218 = letpair_res_2219;
                                        }
                                        while_flag_2214 = let_res_2218;
                                        if (while_flag_2214) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_2214);
                                      (void)VOID;
                                      uint8_t id_2241 { 0 };
                                      uint32_t id_2242 { leb_ref_557[id_2241] };
                                      Size id_2243 { Size(id_2242) };
                                      uint8_t id_2244 { 0 };
                                      Pointer id_2245 { p_ref_559[id_2244] };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2246 { id_2243, id_2245 };
                                      let_res_2213 = id_2246;
                                    }
                                    let_res_2211 = let_res_2213;
                                  }
                                  let_res_2208 = let_res_2211;
                                }
                                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2247;
                                {
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_563 { let_res_2208 };
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2248;
                                  {
                                    auto dstring1_fst_564 { std::get<0>(dstring1_563) };
                                    auto dstring1_snd_565 { std::get<1>(dstring1_563) };
                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2249 { dstring1_snd_565.readBytes(dstring1_fst_564) };
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2250;
                                    {
                                      auto dstring2_fst_567 { std::get<0>(id_2249) };
                                      auto dstring2_snd_568 { std::get<1>(id_2249) };
                                      std::string id_2251 { dstring2_fst_567.toString() };
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2252 { id_2251, dstring2_snd_568 };
                                      letpair_res_2250 = id_2252;
                                    }
                                    letpair_res_2248 = letpair_res_2250;
                                  }
                                  let_res_2247 = letpair_res_2248;
                                }
                                ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 let_res_2253;
                                {
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_569 { let_res_2247 };
                                  ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2254;
                                  {
                                    auto dtup_fst_570 { std::get<0>(dtup_569) };
                                    auto dtup_snd_571 { std::get<1>(dtup_569) };
                                    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2255 { dtup_snd_571.readU16Le() };
                                    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2256;
                                    {
                                      auto du16_fst_573 { std::get<0>(id_2255) };
                                      auto du16_snd_574 { std::get<1>(id_2255) };
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2257 { du16_fst_573, du16_snd_574 };
                                      letpair_res_2256 = id_2257;
                                    }
                                    ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e let_res_2258;
                                    {
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_578 { letpair_res_2256 };
                                      ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e letpair_res_2259;
                                      {
                                        auto dsum1_fst_579 { std::get<0>(dsum1_578) };
                                        auto dsum1_snd_580 { std::get<1>(dsum1_578) };
                                        uint16_t id_2260 { 0 };
                                        bool id_2261 { bool(id_2260 == dsum1_fst_579) };
                                        ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e choose_res_2262;
                                        if (id_2261) {
                                          (void)VOID;
                                          ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_2263 { std::in_place_index<0>, VOID };
                                          ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e id_2264 { id_2263, dsum1_snd_580 };
                                          choose_res_2262 = id_2264;
                                        } else {
                                          uint16_t id_2265 { 1 };
                                          bool id_2266 { bool(dsum1_fst_579 == id_2265) };
                                          Void id_2267 { ((void)(assert(id_2266)), VOID) };
                                          (void)id_2267;
                                          (void)VOID;
                                          ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_2268 { std::in_place_index<1>, VOID };
                                          ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e id_2269 { id_2268, dsum1_snd_580 };
                                          choose_res_2262 = id_2269;
                                        }
                                        letpair_res_2259 = choose_res_2262;
                                      }
                                      let_res_2258 = letpair_res_2259;
                                    }
                                    ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2270;
                                    {
                                      auto dtup_fst_588 { std::get<0>(let_res_2258) };
                                      auto dtup_snd_589 { std::get<1>(let_res_2258) };
                                      ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_2271 { dtup_fst_570, dtup_fst_588 };
                                      ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_2272 { std::in_place_index<1>, id_2271 };
                                      ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 id_2273 { id_2272, dtup_snd_589 };
                                      letpair_res_2270 = id_2273;
                                    }
                                    letpair_res_2254 = letpair_res_2270;
                                  }
                                  let_res_2253 = letpair_res_2254;
                                }
                                choose_res_2205 = let_res_2253;
                              } else {
                                uint16_t id_2274 { 2 };
                                bool id_2275 { bool(id_2274 == dsum1_fst_423) };
                                ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 choose_res_2276;
                                if (id_2275) {
                                  auto fun2277 { dessser::gen::fq_name::of_row_binary };
                                  ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e id_2278 { fun2277(dsum1_snd_424) };
                                  ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 let_res_2279;
                                  {
                                    ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e dtup_458 { id_2278 };
                                    ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2280;
                                    {
                                      auto dtup_fst_459 { std::get<0>(dtup_458) };
                                      auto dtup_snd_460 { std::get<1>(dtup_458) };
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2281 { dtup_snd_460.readU16Le() };
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2282;
                                      {
                                        auto du16_fst_462 { std::get<0>(id_2281) };
                                        auto du16_snd_463 { std::get<1>(id_2281) };
                                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2283 { du16_fst_462, du16_snd_463 };
                                        letpair_res_2282 = id_2283;
                                      }
                                      ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 let_res_2284;
                                      {
                                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_467 { letpair_res_2282 };
                                        ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 letpair_res_2285;
                                        {
                                          auto dsum1_fst_468 { std::get<0>(dsum1_467) };
                                          auto dsum1_snd_469 { std::get<1>(dsum1_467) };
                                          uint16_t id_2286 { 0 };
                                          bool id_2287 { bool(id_2286 == dsum1_fst_468) };
                                          ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2288;
                                          if (id_2287) {
                                            (void)VOID;
                                            ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2289 { std::in_place_index<0>, VOID };
                                            ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2290 { id_2289, dsum1_snd_469 };
                                            choose_res_2288 = id_2290;
                                          } else {
                                            uint16_t id_2291 { 1 };
                                            bool id_2292 { bool(id_2291 == dsum1_fst_468) };
                                            ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2293;
                                            if (id_2292) {
                                              (void)VOID;
                                              ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2294 { std::in_place_index<1>, VOID };
                                              ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2295 { id_2294, dsum1_snd_469 };
                                              choose_res_2293 = id_2295;
                                            } else {
                                              uint16_t id_2296 { 2 };
                                              bool id_2297 { bool(id_2296 == dsum1_fst_468) };
                                              ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2298;
                                              if (id_2297) {
                                                (void)VOID;
                                                ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2299 { std::in_place_index<2>, VOID };
                                                ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2300 { id_2299, dsum1_snd_469 };
                                                choose_res_2298 = id_2300;
                                              } else {
                                                uint16_t id_2301 { 3 };
                                                bool id_2302 { bool(id_2301 == dsum1_fst_468) };
                                                ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2303;
                                                if (id_2302) {
                                                  (void)VOID;
                                                  ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2304 { std::in_place_index<3>, VOID };
                                                  ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2305 { id_2304, dsum1_snd_469 };
                                                  choose_res_2303 = id_2305;
                                                } else {
                                                  uint16_t id_2306 { 4 };
                                                  bool id_2307 { bool(id_2306 == dsum1_fst_468) };
                                                  ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2308;
                                                  if (id_2307) {
                                                    (void)VOID;
                                                    ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2309 { std::in_place_index<4>, VOID };
                                                    ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2310 { id_2309, dsum1_snd_469 };
                                                    choose_res_2308 = id_2310;
                                                  } else {
                                                    uint16_t id_2311 { 5 };
                                                    bool id_2312 { bool(id_2311 == dsum1_fst_468) };
                                                    ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2313;
                                                    if (id_2312) {
                                                      (void)VOID;
                                                      ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2314 { std::in_place_index<5>, VOID };
                                                      ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2315 { id_2314, dsum1_snd_469 };
                                                      choose_res_2313 = id_2315;
                                                    } else {
                                                      uint16_t id_2316 { 6 };
                                                      bool id_2317 { bool(id_2316 == dsum1_fst_468) };
                                                      ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2318;
                                                      if (id_2317) {
                                                        uint32_t id_2319 { 0U };
                                                        Vec<1, uint32_t> id_2320 {  id_2319  };
                                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2321;
                                                        {
                                                          Vec<1, uint32_t> leb_ref_479 { id_2320 };
                                                          uint8_t id_2322 { 0 };
                                                          Vec<1, uint8_t> id_2323 {  id_2322  };
                                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2324;
                                                          {
                                                            Vec<1, uint8_t> shft_ref_480 { id_2323 };
                                                            Vec<1, Pointer> id_2325 {  dsum1_snd_469  };
                                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2326;
                                                            {
                                                              Vec<1, Pointer> p_ref_481 { id_2325 };
                                                              bool while_flag_2327 { true };
                                                              do {
                                                                uint8_t id_2328 { 0 };
                                                                Pointer id_2329 { p_ref_481[id_2328] };
                                                                ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2330 { id_2329.readU8() };
                                                                bool let_res_2331;
                                                                {
                                                                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_482 { id_2330 };
                                                                  bool letpair_res_2332;
                                                                  {
                                                                    auto leb128_fst_483 { std::get<0>(leb128_482) };
                                                                    auto leb128_snd_484 { std::get<1>(leb128_482) };
                                                                    uint8_t id_2333 { 0 };
                                                                    Void id_2334 { ((void)(p_ref_481[id_2333] = leb128_snd_484), VOID) };
                                                                    (void)id_2334;
                                                                    uint8_t id_2335 { 0 };
                                                                    uint8_t id_2336 { 127 };
                                                                    uint8_t id_2337 { uint8_t(leb128_fst_483 & id_2336) };
                                                                    uint32_t id_2338 { uint32_t(id_2337) };
                                                                    uint8_t id_2339 { 0 };
                                                                    uint8_t id_2340 { shft_ref_480[id_2339] };
                                                                    uint32_t id_2341 { uint32_t(id_2338 << id_2340) };
                                                                    uint8_t id_2342 { 0 };
                                                                    uint32_t id_2343 { leb_ref_479[id_2342] };
                                                                    uint32_t id_2344 { uint32_t(id_2341 | id_2343) };
                                                                    Void id_2345 { ((void)(leb_ref_479[id_2335] = id_2344), VOID) };
                                                                    (void)id_2345;
                                                                    uint8_t id_2346 { 0 };
                                                                    uint8_t id_2347 { 0 };
                                                                    uint8_t id_2348 { shft_ref_480[id_2347] };
                                                                    uint8_t id_2349 { 7 };
                                                                    uint8_t id_2350 { uint8_t(id_2348 + id_2349) };
                                                                    Void id_2351 { ((void)(shft_ref_480[id_2346] = id_2350), VOID) };
                                                                    (void)id_2351;
                                                                    uint8_t id_2352 { 128 };
                                                                    bool id_2353 { bool(leb128_fst_483 >= id_2352) };
                                                                    letpair_res_2332 = id_2353;
                                                                  }
                                                                  let_res_2331 = letpair_res_2332;
                                                                }
                                                                while_flag_2327 = let_res_2331;
                                                                if (while_flag_2327) {
                                                                  (void)VOID;
                                                                }
                                                              } while (while_flag_2327);
                                                              (void)VOID;
                                                              uint8_t id_2354 { 0 };
                                                              uint32_t id_2355 { leb_ref_479[id_2354] };
                                                              Size id_2356 { Size(id_2355) };
                                                              uint8_t id_2357 { 0 };
                                                              Pointer id_2358 { p_ref_481[id_2357] };
                                                              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2359 { id_2356, id_2358 };
                                                              let_res_2326 = id_2359;
                                                            }
                                                            let_res_2324 = let_res_2326;
                                                          }
                                                          let_res_2321 = let_res_2324;
                                                        }
                                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2360;
                                                        {
                                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_485 { let_res_2321 };
                                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2361;
                                                          {
                                                            auto dstring1_fst_486 { std::get<0>(dstring1_485) };
                                                            auto dstring1_snd_487 { std::get<1>(dstring1_485) };
                                                            ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2362 { dstring1_snd_487.readBytes(dstring1_fst_486) };
                                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2363;
                                                            {
                                                              auto dstring2_fst_489 { std::get<0>(id_2362) };
                                                              auto dstring2_snd_490 { std::get<1>(id_2362) };
                                                              std::string id_2364 { dstring2_fst_489.toString() };
                                                              ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2365 { id_2364, dstring2_snd_490 };
                                                              letpair_res_2363 = id_2365;
                                                            }
                                                            letpair_res_2361 = letpair_res_2363;
                                                          }
                                                          let_res_2360 = letpair_res_2361;
                                                        }
                                                        ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 let_res_2366;
                                                        {
                                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_491 { let_res_2360 };
                                                          ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 letpair_res_2367;
                                                          {
                                                            auto dtup_fst_492 { std::get<0>(dtup_491) };
                                                            auto dtup_snd_493 { std::get<1>(dtup_491) };
                                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2368 { dtup_snd_493.readU16Le() };
                                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2369;
                                                            {
                                                              auto du16_fst_495 { std::get<0>(id_2368) };
                                                              auto du16_snd_496 { std::get<1>(id_2368) };
                                                              ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2370 { du16_fst_495, du16_snd_496 };
                                                              letpair_res_2369 = id_2370;
                                                            }
                                                            ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da let_res_2371;
                                                            {
                                                              ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_500 { letpair_res_2369 };
                                                              ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da letpair_res_2372;
                                                              {
                                                                auto dsum1_fst_501 { std::get<0>(dsum1_500) };
                                                                auto dsum1_snd_502 { std::get<1>(dsum1_500) };
                                                                uint16_t id_2373 { 0 };
                                                                bool id_2374 { bool(id_2373 == dsum1_fst_501) };
                                                                ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2375;
                                                                if (id_2374) {
                                                                  (void)VOID;
                                                                  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2376 { std::in_place_index<0>, VOID };
                                                                  ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2377 { id_2376, dsum1_snd_502 };
                                                                  choose_res_2375 = id_2377;
                                                                } else {
                                                                  uint16_t id_2378 { 1 };
                                                                  bool id_2379 { bool(id_2378 == dsum1_fst_501) };
                                                                  ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2380;
                                                                  if (id_2379) {
                                                                    (void)VOID;
                                                                    ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2381 { std::in_place_index<1>, VOID };
                                                                    ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2382 { id_2381, dsum1_snd_502 };
                                                                    choose_res_2380 = id_2382;
                                                                  } else {
                                                                    uint16_t id_2383 { 2 };
                                                                    bool id_2384 { bool(id_2383 == dsum1_fst_501) };
                                                                    ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2385;
                                                                    if (id_2384) {
                                                                      (void)VOID;
                                                                      ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2386 { std::in_place_index<2>, VOID };
                                                                      ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2387 { id_2386, dsum1_snd_502 };
                                                                      choose_res_2385 = id_2387;
                                                                    } else {
                                                                      uint16_t id_2388 { 3 };
                                                                      bool id_2389 { bool(id_2388 == dsum1_fst_501) };
                                                                      ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2390;
                                                                      if (id_2389) {
                                                                        (void)VOID;
                                                                        ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2391 { std::in_place_index<3>, VOID };
                                                                        ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2392 { id_2391, dsum1_snd_502 };
                                                                        choose_res_2390 = id_2392;
                                                                      } else {
                                                                        uint16_t id_2393 { 4 };
                                                                        bool id_2394 { bool(id_2393 == dsum1_fst_501) };
                                                                        ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2395;
                                                                        if (id_2394) {
                                                                          (void)VOID;
                                                                          ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2396 { std::in_place_index<4>, VOID };
                                                                          ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2397 { id_2396, dsum1_snd_502 };
                                                                          choose_res_2395 = id_2397;
                                                                        } else {
                                                                          uint16_t id_2398 { 5 };
                                                                          bool id_2399 { bool(id_2398 == dsum1_fst_501) };
                                                                          ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2400;
                                                                          if (id_2399) {
                                                                            (void)VOID;
                                                                            ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2401 { std::in_place_index<5>, VOID };
                                                                            ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2402 { id_2401, dsum1_snd_502 };
                                                                            choose_res_2400 = id_2402;
                                                                          } else {
                                                                            uint16_t id_2403 { 6 };
                                                                            bool id_2404 { bool(id_2403 == dsum1_fst_501) };
                                                                            ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2405;
                                                                            if (id_2404) {
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2406 { std::in_place_index<6>, VOID };
                                                                              ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2407 { id_2406, dsum1_snd_502 };
                                                                              choose_res_2405 = id_2407;
                                                                            } else {
                                                                              uint16_t id_2408 { 7 };
                                                                              bool id_2409 { bool(dsum1_fst_501 == id_2408) };
                                                                              Void id_2410 { ((void)(assert(id_2409)), VOID) };
                                                                              (void)id_2410;
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2411 { std::in_place_index<7>, VOID };
                                                                              ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2412 { id_2411, dsum1_snd_502 };
                                                                              choose_res_2405 = id_2412;
                                                                            }
                                                                            choose_res_2400 = choose_res_2405;
                                                                          }
                                                                          choose_res_2395 = choose_res_2400;
                                                                        }
                                                                        choose_res_2390 = choose_res_2395;
                                                                      }
                                                                      choose_res_2385 = choose_res_2390;
                                                                    }
                                                                    choose_res_2380 = choose_res_2385;
                                                                  }
                                                                  choose_res_2375 = choose_res_2380;
                                                                }
                                                                letpair_res_2372 = choose_res_2375;
                                                              }
                                                              let_res_2371 = letpair_res_2372;
                                                            }
                                                            ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 letpair_res_2413;
                                                            {
                                                              auto dtup_fst_528 { std::get<0>(let_res_2371) };
                                                              auto dtup_snd_529 { std::get<1>(let_res_2371) };
                                                              ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_2414 { dtup_fst_492, dtup_fst_528 };
                                                              ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2415 { std::in_place_index<6>, id_2414 };
                                                              ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2416 { id_2415, dtup_snd_529 };
                                                              letpair_res_2413 = id_2416;
                                                            }
                                                            letpair_res_2367 = letpair_res_2413;
                                                          }
                                                          let_res_2366 = letpair_res_2367;
                                                        }
                                                        choose_res_2318 = let_res_2366;
                                                      } else {
                                                        uint16_t id_2417 { 7 };
                                                        bool id_2418 { bool(id_2417 == dsum1_fst_468) };
                                                        ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2419;
                                                        if (id_2418) {
                                                          ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_2420 { dsum1_snd_469.readU32Le() };
                                                          ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 letpair_res_2421;
                                                          {
                                                            auto du32_fst_474 { std::get<0>(id_2420) };
                                                            auto du32_snd_475 { std::get<1>(id_2420) };
                                                            ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2422 { std::in_place_index<7>, du32_fst_474 };
                                                            ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2423 { id_2422, du32_snd_475 };
                                                            letpair_res_2421 = id_2423;
                                                          }
                                                          choose_res_2419 = letpair_res_2421;
                                                        } else {
                                                          uint16_t id_2424 { 8 };
                                                          bool id_2425 { bool(dsum1_fst_468 == id_2424) };
                                                          Void id_2426 { ((void)(assert(id_2425)), VOID) };
                                                          (void)id_2426;
                                                          (void)VOID;
                                                          ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2427 { std::in_place_index<8>, VOID };
                                                          ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2428 { id_2427, dsum1_snd_469 };
                                                          choose_res_2419 = id_2428;
                                                        }
                                                        choose_res_2318 = choose_res_2419;
                                                      }
                                                      choose_res_2313 = choose_res_2318;
                                                    }
                                                    choose_res_2308 = choose_res_2313;
                                                  }
                                                  choose_res_2303 = choose_res_2308;
                                                }
                                                choose_res_2298 = choose_res_2303;
                                              }
                                              choose_res_2293 = choose_res_2298;
                                            }
                                            choose_res_2288 = choose_res_2293;
                                          }
                                          letpair_res_2285 = choose_res_2288;
                                        }
                                        let_res_2284 = letpair_res_2285;
                                      }
                                      ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2429;
                                      {
                                        auto dtup_fst_552 { std::get<0>(let_res_2284) };
                                        auto dtup_snd_553 { std::get<1>(let_res_2284) };
                                        ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_2430 { dtup_fst_459, dtup_fst_552 };
                                        ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_2431 { std::in_place_index<2>, id_2430 };
                                        ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 id_2432 { id_2431, dtup_snd_553 };
                                        letpair_res_2429 = id_2432;
                                      }
                                      letpair_res_2280 = letpair_res_2429;
                                    }
                                    let_res_2279 = letpair_res_2280;
                                  }
                                  choose_res_2276 = let_res_2279;
                                } else {
                                  uint16_t id_2433 { 3 };
                                  bool id_2434 { bool(dsum1_fst_423 == id_2433) };
                                  Void id_2435 { ((void)(assert(id_2434)), VOID) };
                                  (void)id_2435;
                                  uint32_t id_2436 { 0U };
                                  Vec<1, uint32_t> id_2437 {  id_2436  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2438;
                                  {
                                    Vec<1, uint32_t> leb_ref_425 { id_2437 };
                                    uint8_t id_2439 { 0 };
                                    Vec<1, uint8_t> id_2440 {  id_2439  };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2441;
                                    {
                                      Vec<1, uint8_t> shft_ref_426 { id_2440 };
                                      Vec<1, Pointer> id_2442 {  dsum1_snd_424  };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2443;
                                      {
                                        Vec<1, Pointer> p_ref_427 { id_2442 };
                                        bool while_flag_2444 { true };
                                        do {
                                          uint8_t id_2445 { 0 };
                                          Pointer id_2446 { p_ref_427[id_2445] };
                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2447 { id_2446.readU8() };
                                          bool let_res_2448;
                                          {
                                            ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_428 { id_2447 };
                                            bool letpair_res_2449;
                                            {
                                              auto leb128_fst_429 { std::get<0>(leb128_428) };
                                              auto leb128_snd_430 { std::get<1>(leb128_428) };
                                              uint8_t id_2450 { 0 };
                                              Void id_2451 { ((void)(p_ref_427[id_2450] = leb128_snd_430), VOID) };
                                              (void)id_2451;
                                              uint8_t id_2452 { 0 };
                                              uint8_t id_2453 { 127 };
                                              uint8_t id_2454 { uint8_t(leb128_fst_429 & id_2453) };
                                              uint32_t id_2455 { uint32_t(id_2454) };
                                              uint8_t id_2456 { 0 };
                                              uint8_t id_2457 { shft_ref_426[id_2456] };
                                              uint32_t id_2458 { uint32_t(id_2455 << id_2457) };
                                              uint8_t id_2459 { 0 };
                                              uint32_t id_2460 { leb_ref_425[id_2459] };
                                              uint32_t id_2461 { uint32_t(id_2458 | id_2460) };
                                              Void id_2462 { ((void)(leb_ref_425[id_2452] = id_2461), VOID) };
                                              (void)id_2462;
                                              uint8_t id_2463 { 0 };
                                              uint8_t id_2464 { 0 };
                                              uint8_t id_2465 { shft_ref_426[id_2464] };
                                              uint8_t id_2466 { 7 };
                                              uint8_t id_2467 { uint8_t(id_2465 + id_2466) };
                                              Void id_2468 { ((void)(shft_ref_426[id_2463] = id_2467), VOID) };
                                              (void)id_2468;
                                              uint8_t id_2469 { 128 };
                                              bool id_2470 { bool(leb128_fst_429 >= id_2469) };
                                              letpair_res_2449 = id_2470;
                                            }
                                            let_res_2448 = letpair_res_2449;
                                          }
                                          while_flag_2444 = let_res_2448;
                                          if (while_flag_2444) {
                                            (void)VOID;
                                          }
                                        } while (while_flag_2444);
                                        (void)VOID;
                                        uint8_t id_2471 { 0 };
                                        uint32_t id_2472 { leb_ref_425[id_2471] };
                                        Size id_2473 { Size(id_2472) };
                                        uint8_t id_2474 { 0 };
                                        Pointer id_2475 { p_ref_427[id_2474] };
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2476 { id_2473, id_2475 };
                                        let_res_2443 = id_2476;
                                      }
                                      let_res_2441 = let_res_2443;
                                    }
                                    let_res_2438 = let_res_2441;
                                  }
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2477;
                                  {
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_431 { let_res_2438 };
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2478;
                                    {
                                      auto dstring1_fst_432 { std::get<0>(dstring1_431) };
                                      auto dstring1_snd_433 { std::get<1>(dstring1_431) };
                                      ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2479 { dstring1_snd_433.readBytes(dstring1_fst_432) };
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2480;
                                      {
                                        auto dstring2_fst_435 { std::get<0>(id_2479) };
                                        auto dstring2_snd_436 { std::get<1>(id_2479) };
                                        std::string id_2481 { dstring2_fst_435.toString() };
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2482 { id_2481, dstring2_snd_436 };
                                        letpair_res_2480 = id_2482;
                                      }
                                      letpair_res_2478 = letpair_res_2480;
                                    }
                                    let_res_2477 = letpair_res_2478;
                                  }
                                  ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 let_res_2483;
                                  {
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_437 { let_res_2477 };
                                    ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2484;
                                    {
                                      auto dtup_fst_438 { std::get<0>(dtup_437) };
                                      auto dtup_snd_439 { std::get<1>(dtup_437) };
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2485 { dtup_snd_439.readU16Le() };
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2486;
                                      {
                                        auto du16_fst_441 { std::get<0>(id_2485) };
                                        auto du16_snd_442 { std::get<1>(id_2485) };
                                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2487 { du16_fst_441, du16_snd_442 };
                                        letpair_res_2486 = id_2487;
                                      }
                                      ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 let_res_2488;
                                      {
                                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_446 { letpair_res_2486 };
                                        ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2489;
                                        {
                                          auto dsum1_fst_447 { std::get<0>(dsum1_446) };
                                          auto dsum1_snd_448 { std::get<1>(dsum1_446) };
                                          uint16_t id_2490 { 0 };
                                          bool id_2491 { bool(dsum1_fst_447 == id_2490) };
                                          Void id_2492 { ((void)(assert(id_2491)), VOID) };
                                          (void)id_2492;
                                          (void)VOID;
                                          ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_2493 { std::in_place_index<0>, VOID };
                                          ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_2494 { dtup_fst_438, id_2493 };
                                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_2495 { std::in_place_index<3>, id_2494 };
                                          ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 id_2496 { id_2495, dsum1_snd_448 };
                                          letpair_res_2489 = id_2496;
                                        }
                                        let_res_2488 = letpair_res_2489;
                                      }
                                      letpair_res_2484 = let_res_2488;
                                    }
                                    let_res_2483 = letpair_res_2484;
                                  }
                                  choose_res_2276 = let_res_2483;
                                }
                                choose_res_2205 = choose_res_2276;
                              }
                              choose_res_2200 = choose_res_2205;
                            }
                            letpair_res_2197 = choose_res_2200;
                          }
                          let_res_2196 = letpair_res_2197;
                        }
                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2497;
                        {
                          auto dtup_fst_597 { std::get<0>(let_res_2196) };
                          auto dtup_snd_598 { std::get<1>(let_res_2196) };
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_2498 { dtup_fst_414, dtup_fst_597 };
                          std::shared_ptr<::dessser::gen::sync_key::t>  id_2499 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<5>, id_2498) };
                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2500 { id_2499, dtup_snd_598 };
                          letpair_res_2497 = id_2500;
                        }
                        letpair_res_2192 = letpair_res_2497;
                      }
                      let_res_2191 = letpair_res_2192;
                    }
                    choose_res_2188 = let_res_2191;
                  } else {
                    uint16_t id_2501 { 6 };
                    bool id_2502 { bool(id_2501 == dsum1_fst_144) };
                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2503;
                    if (id_2502) {
                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2504 { dsum1_snd_145.readU16Le() };
                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2505;
                      {
                        auto du16_fst_381 { std::get<0>(id_2504) };
                        auto du16_snd_382 { std::get<1>(id_2504) };
                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2506 { du16_fst_381, du16_snd_382 };
                        letpair_res_2505 = id_2506;
                      }
                      ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b let_res_2507;
                      {
                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_386 { letpair_res_2505 };
                        ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b letpair_res_2508;
                        {
                          auto dsum1_fst_387 { std::get<0>(dsum1_386) };
                          auto dsum1_snd_388 { std::get<1>(dsum1_386) };
                          uint16_t id_2509 { 0 };
                          bool id_2510 { bool(id_2509 == dsum1_fst_387) };
                          ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b choose_res_2511;
                          if (id_2510) {
                            (void)VOID;
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2512 { std::in_place_index<0>, VOID };
                            ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b id_2513 { id_2512, dsum1_snd_388 };
                            choose_res_2511 = id_2513;
                          } else {
                            uint16_t id_2514 { 1 };
                            bool id_2515 { bool(id_2514 == dsum1_fst_387) };
                            ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b choose_res_2516;
                            if (id_2515) {
                              (void)VOID;
                              ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2517 { std::in_place_index<1>, VOID };
                              ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b id_2518 { id_2517, dsum1_snd_388 };
                              choose_res_2516 = id_2518;
                            } else {
                              uint16_t id_2519 { 2 };
                              bool id_2520 { bool(dsum1_fst_387 == id_2519) };
                              Void id_2521 { ((void)(assert(id_2520)), VOID) };
                              (void)id_2521;
                              uint32_t id_2522 { 0U };
                              Vec<1, uint32_t> id_2523 {  id_2522  };
                              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2524;
                              {
                                Vec<1, uint32_t> leb_ref_389 { id_2523 };
                                uint8_t id_2525 { 0 };
                                Vec<1, uint8_t> id_2526 {  id_2525  };
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2527;
                                {
                                  Vec<1, uint8_t> shft_ref_390 { id_2526 };
                                  Vec<1, Pointer> id_2528 {  dsum1_snd_388  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2529;
                                  {
                                    Vec<1, Pointer> p_ref_391 { id_2528 };
                                    bool while_flag_2530 { true };
                                    do {
                                      uint8_t id_2531 { 0 };
                                      Pointer id_2532 { p_ref_391[id_2531] };
                                      ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2533 { id_2532.readU8() };
                                      bool let_res_2534;
                                      {
                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_392 { id_2533 };
                                        bool letpair_res_2535;
                                        {
                                          auto leb128_fst_393 { std::get<0>(leb128_392) };
                                          auto leb128_snd_394 { std::get<1>(leb128_392) };
                                          uint8_t id_2536 { 0 };
                                          Void id_2537 { ((void)(p_ref_391[id_2536] = leb128_snd_394), VOID) };
                                          (void)id_2537;
                                          uint8_t id_2538 { 0 };
                                          uint8_t id_2539 { 127 };
                                          uint8_t id_2540 { uint8_t(leb128_fst_393 & id_2539) };
                                          uint32_t id_2541 { uint32_t(id_2540) };
                                          uint8_t id_2542 { 0 };
                                          uint8_t id_2543 { shft_ref_390[id_2542] };
                                          uint32_t id_2544 { uint32_t(id_2541 << id_2543) };
                                          uint8_t id_2545 { 0 };
                                          uint32_t id_2546 { leb_ref_389[id_2545] };
                                          uint32_t id_2547 { uint32_t(id_2544 | id_2546) };
                                          Void id_2548 { ((void)(leb_ref_389[id_2538] = id_2547), VOID) };
                                          (void)id_2548;
                                          uint8_t id_2549 { 0 };
                                          uint8_t id_2550 { 0 };
                                          uint8_t id_2551 { shft_ref_390[id_2550] };
                                          uint8_t id_2552 { 7 };
                                          uint8_t id_2553 { uint8_t(id_2551 + id_2552) };
                                          Void id_2554 { ((void)(shft_ref_390[id_2549] = id_2553), VOID) };
                                          (void)id_2554;
                                          uint8_t id_2555 { 128 };
                                          bool id_2556 { bool(leb128_fst_393 >= id_2555) };
                                          letpair_res_2535 = id_2556;
                                        }
                                        let_res_2534 = letpair_res_2535;
                                      }
                                      while_flag_2530 = let_res_2534;
                                      if (while_flag_2530) {
                                        (void)VOID;
                                      }
                                    } while (while_flag_2530);
                                    (void)VOID;
                                    uint8_t id_2557 { 0 };
                                    uint32_t id_2558 { leb_ref_389[id_2557] };
                                    Size id_2559 { Size(id_2558) };
                                    uint8_t id_2560 { 0 };
                                    Pointer id_2561 { p_ref_391[id_2560] };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2562 { id_2559, id_2561 };
                                    let_res_2529 = id_2562;
                                  }
                                  let_res_2527 = let_res_2529;
                                }
                                let_res_2524 = let_res_2527;
                              }
                              ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b let_res_2563;
                              {
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_395 { let_res_2524 };
                                ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b letpair_res_2564;
                                {
                                  auto dstring1_fst_396 { std::get<0>(dstring1_395) };
                                  auto dstring1_snd_397 { std::get<1>(dstring1_395) };
                                  ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2565 { dstring1_snd_397.readBytes(dstring1_fst_396) };
                                  ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b letpair_res_2566;
                                  {
                                    auto dstring2_fst_399 { std::get<0>(id_2565) };
                                    auto dstring2_snd_400 { std::get<1>(id_2565) };
                                    std::string id_2567 { dstring2_fst_399.toString() };
                                    ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2568 { std::in_place_index<2>, id_2567 };
                                    ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b id_2569 { id_2568, dstring2_snd_400 };
                                    letpair_res_2566 = id_2569;
                                  }
                                  letpair_res_2564 = letpair_res_2566;
                                }
                                let_res_2563 = letpair_res_2564;
                              }
                              choose_res_2516 = let_res_2563;
                            }
                            choose_res_2511 = choose_res_2516;
                          }
                          letpair_res_2508 = choose_res_2511;
                        }
                        let_res_2507 = letpair_res_2508;
                      }
                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2570;
                      {
                        auto dsum2_fst_411 { std::get<0>(let_res_2507) };
                        auto dsum2_snd_412 { std::get<1>(let_res_2507) };
                        std::shared_ptr<::dessser::gen::sync_key::t>  id_2571 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<6>, dsum2_fst_411) };
                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2572 { id_2571, dsum2_snd_412 };
                        letpair_res_2570 = id_2572;
                      }
                      choose_res_2503 = letpair_res_2570;
                    } else {
                      uint16_t id_2573 { 7 };
                      bool id_2574 { bool(id_2573 == dsum1_fst_144) };
                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2575;
                      if (id_2574) {
                        auto fun2576 { dessser::gen::site_name::of_row_binary };
                        ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea id_2577 { fun2576(dsum1_snd_145) };
                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2578;
                        {
                          ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea dtup_353 { id_2577 };
                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2579;
                          {
                            auto dtup_fst_354 { std::get<0>(dtup_353) };
                            auto dtup_snd_355 { std::get<1>(dtup_353) };
                            auto fun2580 { dessser::gen::fq_name::of_row_binary };
                            ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e id_2581 { fun2580(dtup_snd_355) };
                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2582;
                            {
                              ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e dtup_356 { id_2581 };
                              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2583;
                              {
                                auto dtup_fst_357 { std::get<0>(dtup_356) };
                                auto dtup_snd_358 { std::get<1>(dtup_356) };
                                uint32_t id_2584 { 0U };
                                Vec<1, uint32_t> id_2585 {  id_2584  };
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2586;
                                {
                                  Vec<1, uint32_t> leb_ref_359 { id_2585 };
                                  uint8_t id_2587 { 0 };
                                  Vec<1, uint8_t> id_2588 {  id_2587  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2589;
                                  {
                                    Vec<1, uint8_t> shft_ref_360 { id_2588 };
                                    Vec<1, Pointer> id_2590 {  dtup_snd_358  };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2591;
                                    {
                                      Vec<1, Pointer> p_ref_361 { id_2590 };
                                      bool while_flag_2592 { true };
                                      do {
                                        uint8_t id_2593 { 0 };
                                        Pointer id_2594 { p_ref_361[id_2593] };
                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2595 { id_2594.readU8() };
                                        bool let_res_2596;
                                        {
                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_362 { id_2595 };
                                          bool letpair_res_2597;
                                          {
                                            auto leb128_fst_363 { std::get<0>(leb128_362) };
                                            auto leb128_snd_364 { std::get<1>(leb128_362) };
                                            uint8_t id_2598 { 0 };
                                            Void id_2599 { ((void)(p_ref_361[id_2598] = leb128_snd_364), VOID) };
                                            (void)id_2599;
                                            uint8_t id_2600 { 0 };
                                            uint8_t id_2601 { 127 };
                                            uint8_t id_2602 { uint8_t(leb128_fst_363 & id_2601) };
                                            uint32_t id_2603 { uint32_t(id_2602) };
                                            uint8_t id_2604 { 0 };
                                            uint8_t id_2605 { shft_ref_360[id_2604] };
                                            uint32_t id_2606 { uint32_t(id_2603 << id_2605) };
                                            uint8_t id_2607 { 0 };
                                            uint32_t id_2608 { leb_ref_359[id_2607] };
                                            uint32_t id_2609 { uint32_t(id_2606 | id_2608) };
                                            Void id_2610 { ((void)(leb_ref_359[id_2600] = id_2609), VOID) };
                                            (void)id_2610;
                                            uint8_t id_2611 { 0 };
                                            uint8_t id_2612 { 0 };
                                            uint8_t id_2613 { shft_ref_360[id_2612] };
                                            uint8_t id_2614 { 7 };
                                            uint8_t id_2615 { uint8_t(id_2613 + id_2614) };
                                            Void id_2616 { ((void)(shft_ref_360[id_2611] = id_2615), VOID) };
                                            (void)id_2616;
                                            uint8_t id_2617 { 128 };
                                            bool id_2618 { bool(leb128_fst_363 >= id_2617) };
                                            letpair_res_2597 = id_2618;
                                          }
                                          let_res_2596 = letpair_res_2597;
                                        }
                                        while_flag_2592 = let_res_2596;
                                        if (while_flag_2592) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_2592);
                                      (void)VOID;
                                      uint8_t id_2619 { 0 };
                                      uint32_t id_2620 { leb_ref_359[id_2619] };
                                      Size id_2621 { Size(id_2620) };
                                      uint8_t id_2622 { 0 };
                                      Pointer id_2623 { p_ref_361[id_2622] };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2624 { id_2621, id_2623 };
                                      let_res_2591 = id_2624;
                                    }
                                    let_res_2589 = let_res_2591;
                                  }
                                  let_res_2586 = let_res_2589;
                                }
                                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2625;
                                {
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_365 { let_res_2586 };
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2626;
                                  {
                                    auto dstring1_fst_366 { std::get<0>(dstring1_365) };
                                    auto dstring1_snd_367 { std::get<1>(dstring1_365) };
                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2627 { dstring1_snd_367.readBytes(dstring1_fst_366) };
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2628;
                                    {
                                      auto dstring2_fst_369 { std::get<0>(id_2627) };
                                      auto dstring2_snd_370 { std::get<1>(id_2627) };
                                      std::string id_2629 { dstring2_fst_369.toString() };
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2630 { id_2629, dstring2_snd_370 };
                                      letpair_res_2628 = id_2630;
                                    }
                                    letpair_res_2626 = letpair_res_2628;
                                  }
                                  let_res_2625 = letpair_res_2626;
                                }
                                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2631;
                                {
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_371 { let_res_2625 };
                                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2632;
                                  {
                                    auto dtup_fst_372 { std::get<0>(dtup_371) };
                                    auto dtup_snd_373 { std::get<1>(dtup_371) };
                                    ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d id_2633 { per_tail_of_row_binary(dtup_snd_373) };
                                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2634;
                                    {
                                      auto dtup_fst_375 { std::get<0>(id_2633) };
                                      auto dtup_snd_376 { std::get<1>(id_2633) };
                                      ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_2635 { dtup_fst_354, dtup_fst_357, dtup_fst_372, dtup_fst_375 };
                                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2636 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<7>, id_2635) };
                                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2637 { id_2636, dtup_snd_376 };
                                      letpair_res_2634 = id_2637;
                                    }
                                    letpair_res_2632 = letpair_res_2634;
                                  }
                                  let_res_2631 = letpair_res_2632;
                                }
                                letpair_res_2583 = let_res_2631;
                              }
                              let_res_2582 = letpair_res_2583;
                            }
                            letpair_res_2579 = let_res_2582;
                          }
                          let_res_2578 = letpair_res_2579;
                        }
                        choose_res_2575 = let_res_2578;
                      } else {
                        uint16_t id_2638 { 8 };
                        bool id_2639 { bool(id_2638 == dsum1_fst_144) };
                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2640;
                        if (id_2639) {
                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2641 { dsum1_snd_145.readU16Le() };
                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2642;
                          {
                            auto du16_fst_348 { std::get<0>(id_2641) };
                            auto du16_snd_349 { std::get<1>(id_2641) };
                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2643 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<8>, du16_fst_348) };
                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2644 { id_2643, du16_snd_349 };
                            letpair_res_2642 = id_2644;
                          }
                          choose_res_2640 = letpair_res_2642;
                        } else {
                          uint16_t id_2645 { 9 };
                          bool id_2646 { bool(id_2645 == dsum1_fst_144) };
                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2647;
                          if (id_2646) {
                            Size id_2648 { 0UL };
                            uint8_t id_2649 { dsum1_snd_145.peekU8(id_2648) };
                            uint8_t id_2650 { 1 };
                            bool id_2651 { bool(id_2649 == id_2650) };
                            ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 choose_res_2652;
                            if (id_2651) {
                              std::optional<dessser::gen::sync_socket::t_ext> id_2653 { std::nullopt };
                              Size id_2654 { 1UL };
                              Pointer id_2655 { dsum1_snd_145.skip(id_2654) };
                              ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 id_2656 { id_2653, id_2655 };
                              choose_res_2652 = id_2656;
                            } else {
                              auto fun2657 { dessser::gen::sync_socket::of_row_binary };
                              Size id_2658 { 1UL };
                              Pointer id_2659 { dsum1_snd_145.skip(id_2658) };
                              ::dessser::gen::sync_key::t8a365991c4a4591932e21c9e1eeeab20 id_2660 { fun2657(id_2659) };
                              ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 letpair_res_2661;
                              {
                                auto make1_1_fst_342 { std::get<0>(id_2660) };
                                auto make1_1_snd_343 { std::get<1>(id_2660) };
                                std::optional<dessser::gen::sync_socket::t_ext> id_2662 { make1_1_fst_342 };
                                ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 id_2663 { id_2662, make1_1_snd_343 };
                                letpair_res_2661 = id_2663;
                              }
                              choose_res_2652 = letpair_res_2661;
                            }
                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2664;
                            {
                              auto dsum2_fst_345 { std::get<0>(choose_res_2652) };
                              auto dsum2_snd_346 { std::get<1>(choose_res_2652) };
                              std::shared_ptr<::dessser::gen::sync_key::t>  id_2665 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<9>, dsum2_fst_345) };
                              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2666 { id_2665, dsum2_snd_346 };
                              letpair_res_2664 = id_2666;
                            }
                            choose_res_2647 = letpair_res_2664;
                          } else {
                            uint16_t id_2667 { 10 };
                            bool id_2668 { bool(id_2667 == dsum1_fst_144) };
                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2669;
                            if (id_2668) {
                              (void)VOID;
                              std::shared_ptr<::dessser::gen::sync_key::t>  id_2670 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<10>, VOID) };
                              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2671 { id_2670, dsum1_snd_145 };
                              choose_res_2669 = id_2671;
                            } else {
                              uint16_t id_2672 { 11 };
                              bool id_2673 { bool(id_2672 == dsum1_fst_144) };
                              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2674;
                              if (id_2673) {
                                auto fun2675 { dessser::gen::sync_socket::of_row_binary };
                                ::dessser::gen::sync_key::t8a365991c4a4591932e21c9e1eeeab20 id_2676 { fun2675(dsum1_snd_145) };
                                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2677;
                                {
                                  ::dessser::gen::sync_key::t8a365991c4a4591932e21c9e1eeeab20 dtup_329 { id_2676 };
                                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2678;
                                  {
                                    auto dtup_fst_330 { std::get<0>(dtup_329) };
                                    auto dtup_snd_331 { std::get<1>(dtup_329) };
                                    ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 id_2679 { per_client_of_row_binary(dtup_snd_331) };
                                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2680;
                                    {
                                      auto dtup_fst_333 { std::get<0>(id_2679) };
                                      auto dtup_snd_334 { std::get<1>(id_2679) };
                                      ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef id_2681 { dtup_fst_330, dtup_fst_333 };
                                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2682 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<11>, id_2681) };
                                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2683 { id_2682, dtup_snd_334 };
                                      letpair_res_2680 = id_2683;
                                    }
                                    letpair_res_2678 = letpair_res_2680;
                                  }
                                  let_res_2677 = letpair_res_2678;
                                }
                                choose_res_2674 = let_res_2677;
                              } else {
                                uint16_t id_2684 { 12 };
                                bool id_2685 { bool(id_2684 == dsum1_fst_144) };
                                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2686;
                                if (id_2685) {
                                  uint32_t id_2687 { 0U };
                                  Vec<1, uint32_t> id_2688 {  id_2687  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2689;
                                  {
                                    Vec<1, uint32_t> leb_ref_308 { id_2688 };
                                    uint8_t id_2690 { 0 };
                                    Vec<1, uint8_t> id_2691 {  id_2690  };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2692;
                                    {
                                      Vec<1, uint8_t> shft_ref_309 { id_2691 };
                                      Vec<1, Pointer> id_2693 {  dsum1_snd_145  };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2694;
                                      {
                                        Vec<1, Pointer> p_ref_310 { id_2693 };
                                        bool while_flag_2695 { true };
                                        do {
                                          uint8_t id_2696 { 0 };
                                          Pointer id_2697 { p_ref_310[id_2696] };
                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2698 { id_2697.readU8() };
                                          bool let_res_2699;
                                          {
                                            ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_311 { id_2698 };
                                            bool letpair_res_2700;
                                            {
                                              auto leb128_fst_312 { std::get<0>(leb128_311) };
                                              auto leb128_snd_313 { std::get<1>(leb128_311) };
                                              uint8_t id_2701 { 0 };
                                              Void id_2702 { ((void)(p_ref_310[id_2701] = leb128_snd_313), VOID) };
                                              (void)id_2702;
                                              uint8_t id_2703 { 0 };
                                              uint8_t id_2704 { 127 };
                                              uint8_t id_2705 { uint8_t(leb128_fst_312 & id_2704) };
                                              uint32_t id_2706 { uint32_t(id_2705) };
                                              uint8_t id_2707 { 0 };
                                              uint8_t id_2708 { shft_ref_309[id_2707] };
                                              uint32_t id_2709 { uint32_t(id_2706 << id_2708) };
                                              uint8_t id_2710 { 0 };
                                              uint32_t id_2711 { leb_ref_308[id_2710] };
                                              uint32_t id_2712 { uint32_t(id_2709 | id_2711) };
                                              Void id_2713 { ((void)(leb_ref_308[id_2703] = id_2712), VOID) };
                                              (void)id_2713;
                                              uint8_t id_2714 { 0 };
                                              uint8_t id_2715 { 0 };
                                              uint8_t id_2716 { shft_ref_309[id_2715] };
                                              uint8_t id_2717 { 7 };
                                              uint8_t id_2718 { uint8_t(id_2716 + id_2717) };
                                              Void id_2719 { ((void)(shft_ref_309[id_2714] = id_2718), VOID) };
                                              (void)id_2719;
                                              uint8_t id_2720 { 128 };
                                              bool id_2721 { bool(leb128_fst_312 >= id_2720) };
                                              letpair_res_2700 = id_2721;
                                            }
                                            let_res_2699 = letpair_res_2700;
                                          }
                                          while_flag_2695 = let_res_2699;
                                          if (while_flag_2695) {
                                            (void)VOID;
                                          }
                                        } while (while_flag_2695);
                                        (void)VOID;
                                        uint8_t id_2722 { 0 };
                                        uint32_t id_2723 { leb_ref_308[id_2722] };
                                        Size id_2724 { Size(id_2723) };
                                        uint8_t id_2725 { 0 };
                                        Pointer id_2726 { p_ref_310[id_2725] };
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2727 { id_2724, id_2726 };
                                        let_res_2694 = id_2727;
                                      }
                                      let_res_2692 = let_res_2694;
                                    }
                                    let_res_2689 = let_res_2692;
                                  }
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2728;
                                  {
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_314 { let_res_2689 };
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2729;
                                    {
                                      auto dstring1_fst_315 { std::get<0>(dstring1_314) };
                                      auto dstring1_snd_316 { std::get<1>(dstring1_314) };
                                      ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2730 { dstring1_snd_316.readBytes(dstring1_fst_315) };
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2731;
                                      {
                                        auto dstring2_fst_318 { std::get<0>(id_2730) };
                                        auto dstring2_snd_319 { std::get<1>(id_2730) };
                                        std::string id_2732 { dstring2_fst_318.toString() };
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2733 { id_2732, dstring2_snd_319 };
                                        letpair_res_2731 = id_2733;
                                      }
                                      letpair_res_2729 = letpair_res_2731;
                                    }
                                    let_res_2728 = letpair_res_2729;
                                  }
                                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2734;
                                  {
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_320 { let_res_2728 };
                                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2735;
                                    {
                                      auto dtup_fst_321 { std::get<0>(dtup_320) };
                                      auto dtup_snd_322 { std::get<1>(dtup_320) };
                                      ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c id_2736 { per_dash_key_of_row_binary(dtup_snd_322) };
                                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2737;
                                      {
                                        auto dtup_fst_324 { std::get<0>(id_2736) };
                                        auto dtup_snd_325 { std::get<1>(id_2736) };
                                        ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_2738 { dtup_fst_321, dtup_fst_324 };
                                        std::shared_ptr<::dessser::gen::sync_key::t>  id_2739 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<12>, id_2738) };
                                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2740 { id_2739, dtup_snd_325 };
                                        letpair_res_2737 = id_2740;
                                      }
                                      letpair_res_2735 = letpair_res_2737;
                                    }
                                    let_res_2734 = letpair_res_2735;
                                  }
                                  choose_res_2686 = let_res_2734;
                                } else {
                                  uint16_t id_2741 { 13 };
                                  bool id_2742 { bool(id_2741 == dsum1_fst_144) };
                                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2743;
                                  if (id_2742) {
                                    (void)VOID;
                                    std::shared_ptr<::dessser::gen::sync_key::t>  id_2744 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<13>, VOID) };
                                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2745 { id_2744, dsum1_snd_145 };
                                    choose_res_2743 = id_2745;
                                  } else {
                                    uint16_t id_2746 { 14 };
                                    bool id_2747 { bool(id_2746 == dsum1_fst_144) };
                                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2748;
                                    if (id_2747) {
                                      auto fun2749 { dessser::gen::team_name::of_row_binary };
                                      ::dessser::gen::sync_key::t165bfb5c86a2d73d290e190e229b1fb1 id_2750 { fun2749(dsum1_snd_145) };
                                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2751;
                                      {
                                        ::dessser::gen::sync_key::t165bfb5c86a2d73d290e190e229b1fb1 dtup_257 { id_2750 };
                                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2752;
                                        {
                                          auto dtup_fst_258 { std::get<0>(dtup_257) };
                                          auto dtup_snd_259 { std::get<1>(dtup_257) };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2753 { dtup_snd_259.readU16Le() };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2754;
                                          {
                                            auto du16_fst_261 { std::get<0>(id_2753) };
                                            auto du16_snd_262 { std::get<1>(id_2753) };
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2755 { du16_fst_261, du16_snd_262 };
                                            letpair_res_2754 = id_2755;
                                          }
                                          ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 let_res_2756;
                                          {
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_266 { letpair_res_2754 };
                                            ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2757;
                                            {
                                              auto dsum1_fst_267 { std::get<0>(dsum1_266) };
                                              auto dsum1_snd_268 { std::get<1>(dsum1_266) };
                                              uint16_t id_2758 { 0 };
                                              bool id_2759 { bool(id_2758 == dsum1_fst_267) };
                                              ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 choose_res_2760;
                                              if (id_2759) {
                                                uint32_t id_2761 { 0U };
                                                Vec<1, uint32_t> id_2762 {  id_2761  };
                                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2763;
                                                {
                                                  Vec<1, uint32_t> leb_ref_284 { id_2762 };
                                                  uint8_t id_2764 { 0 };
                                                  Vec<1, uint8_t> id_2765 {  id_2764  };
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2766;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_285 { id_2765 };
                                                    Vec<1, Pointer> id_2767 {  dsum1_snd_268  };
                                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2768;
                                                    {
                                                      Vec<1, Pointer> p_ref_286 { id_2767 };
                                                      bool while_flag_2769 { true };
                                                      do {
                                                        uint8_t id_2770 { 0 };
                                                        Pointer id_2771 { p_ref_286[id_2770] };
                                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2772 { id_2771.readU8() };
                                                        bool let_res_2773;
                                                        {
                                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_287 { id_2772 };
                                                          bool letpair_res_2774;
                                                          {
                                                            auto leb128_fst_288 { std::get<0>(leb128_287) };
                                                            auto leb128_snd_289 { std::get<1>(leb128_287) };
                                                            uint8_t id_2775 { 0 };
                                                            Void id_2776 { ((void)(p_ref_286[id_2775] = leb128_snd_289), VOID) };
                                                            (void)id_2776;
                                                            uint8_t id_2777 { 0 };
                                                            uint8_t id_2778 { 127 };
                                                            uint8_t id_2779 { uint8_t(leb128_fst_288 & id_2778) };
                                                            uint32_t id_2780 { uint32_t(id_2779) };
                                                            uint8_t id_2781 { 0 };
                                                            uint8_t id_2782 { shft_ref_285[id_2781] };
                                                            uint32_t id_2783 { uint32_t(id_2780 << id_2782) };
                                                            uint8_t id_2784 { 0 };
                                                            uint32_t id_2785 { leb_ref_284[id_2784] };
                                                            uint32_t id_2786 { uint32_t(id_2783 | id_2785) };
                                                            Void id_2787 { ((void)(leb_ref_284[id_2777] = id_2786), VOID) };
                                                            (void)id_2787;
                                                            uint8_t id_2788 { 0 };
                                                            uint8_t id_2789 { 0 };
                                                            uint8_t id_2790 { shft_ref_285[id_2789] };
                                                            uint8_t id_2791 { 7 };
                                                            uint8_t id_2792 { uint8_t(id_2790 + id_2791) };
                                                            Void id_2793 { ((void)(shft_ref_285[id_2788] = id_2792), VOID) };
                                                            (void)id_2793;
                                                            uint8_t id_2794 { 128 };
                                                            bool id_2795 { bool(leb128_fst_288 >= id_2794) };
                                                            letpair_res_2774 = id_2795;
                                                          }
                                                          let_res_2773 = letpair_res_2774;
                                                        }
                                                        while_flag_2769 = let_res_2773;
                                                        if (while_flag_2769) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_2769);
                                                      (void)VOID;
                                                      uint8_t id_2796 { 0 };
                                                      uint32_t id_2797 { leb_ref_284[id_2796] };
                                                      Size id_2798 { Size(id_2797) };
                                                      uint8_t id_2799 { 0 };
                                                      Pointer id_2800 { p_ref_286[id_2799] };
                                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2801 { id_2798, id_2800 };
                                                      let_res_2768 = id_2801;
                                                    }
                                                    let_res_2766 = let_res_2768;
                                                  }
                                                  let_res_2763 = let_res_2766;
                                                }
                                                ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 let_res_2802;
                                                {
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_290 { let_res_2763 };
                                                  ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2803;
                                                  {
                                                    auto dstring1_fst_291 { std::get<0>(dstring1_290) };
                                                    auto dstring1_snd_292 { std::get<1>(dstring1_290) };
                                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2804 { dstring1_snd_292.readBytes(dstring1_fst_291) };
                                                    ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2805;
                                                    {
                                                      auto dstring2_fst_294 { std::get<0>(id_2804) };
                                                      auto dstring2_snd_295 { std::get<1>(id_2804) };
                                                      std::string id_2806 { dstring2_fst_294.toString() };
                                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_2807 { std::in_place_index<0>, id_2806 };
                                                      ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 id_2808 { id_2807, dstring2_snd_295 };
                                                      letpair_res_2805 = id_2808;
                                                    }
                                                    letpair_res_2803 = letpair_res_2805;
                                                  }
                                                  let_res_2802 = letpair_res_2803;
                                                }
                                                choose_res_2760 = let_res_2802;
                                              } else {
                                                uint16_t id_2809 { 1 };
                                                bool id_2810 { bool(dsum1_fst_267 == id_2809) };
                                                Void id_2811 { ((void)(assert(id_2810)), VOID) };
                                                (void)id_2811;
                                                uint32_t id_2812 { 0U };
                                                Vec<1, uint32_t> id_2813 {  id_2812  };
                                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2814;
                                                {
                                                  Vec<1, uint32_t> leb_ref_269 { id_2813 };
                                                  uint8_t id_2815 { 0 };
                                                  Vec<1, uint8_t> id_2816 {  id_2815  };
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2817;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_270 { id_2816 };
                                                    Vec<1, Pointer> id_2818 {  dsum1_snd_268  };
                                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2819;
                                                    {
                                                      Vec<1, Pointer> p_ref_271 { id_2818 };
                                                      bool while_flag_2820 { true };
                                                      do {
                                                        uint8_t id_2821 { 0 };
                                                        Pointer id_2822 { p_ref_271[id_2821] };
                                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2823 { id_2822.readU8() };
                                                        bool let_res_2824;
                                                        {
                                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_272 { id_2823 };
                                                          bool letpair_res_2825;
                                                          {
                                                            auto leb128_fst_273 { std::get<0>(leb128_272) };
                                                            auto leb128_snd_274 { std::get<1>(leb128_272) };
                                                            uint8_t id_2826 { 0 };
                                                            Void id_2827 { ((void)(p_ref_271[id_2826] = leb128_snd_274), VOID) };
                                                            (void)id_2827;
                                                            uint8_t id_2828 { 0 };
                                                            uint8_t id_2829 { 127 };
                                                            uint8_t id_2830 { uint8_t(leb128_fst_273 & id_2829) };
                                                            uint32_t id_2831 { uint32_t(id_2830) };
                                                            uint8_t id_2832 { 0 };
                                                            uint8_t id_2833 { shft_ref_270[id_2832] };
                                                            uint32_t id_2834 { uint32_t(id_2831 << id_2833) };
                                                            uint8_t id_2835 { 0 };
                                                            uint32_t id_2836 { leb_ref_269[id_2835] };
                                                            uint32_t id_2837 { uint32_t(id_2834 | id_2836) };
                                                            Void id_2838 { ((void)(leb_ref_269[id_2828] = id_2837), VOID) };
                                                            (void)id_2838;
                                                            uint8_t id_2839 { 0 };
                                                            uint8_t id_2840 { 0 };
                                                            uint8_t id_2841 { shft_ref_270[id_2840] };
                                                            uint8_t id_2842 { 7 };
                                                            uint8_t id_2843 { uint8_t(id_2841 + id_2842) };
                                                            Void id_2844 { ((void)(shft_ref_270[id_2839] = id_2843), VOID) };
                                                            (void)id_2844;
                                                            uint8_t id_2845 { 128 };
                                                            bool id_2846 { bool(leb128_fst_273 >= id_2845) };
                                                            letpair_res_2825 = id_2846;
                                                          }
                                                          let_res_2824 = letpair_res_2825;
                                                        }
                                                        while_flag_2820 = let_res_2824;
                                                        if (while_flag_2820) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_2820);
                                                      (void)VOID;
                                                      uint8_t id_2847 { 0 };
                                                      uint32_t id_2848 { leb_ref_269[id_2847] };
                                                      Size id_2849 { Size(id_2848) };
                                                      uint8_t id_2850 { 0 };
                                                      Pointer id_2851 { p_ref_271[id_2850] };
                                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2852 { id_2849, id_2851 };
                                                      let_res_2819 = id_2852;
                                                    }
                                                    let_res_2817 = let_res_2819;
                                                  }
                                                  let_res_2814 = let_res_2817;
                                                }
                                                ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 let_res_2853;
                                                {
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_275 { let_res_2814 };
                                                  ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2854;
                                                  {
                                                    auto dstring1_fst_276 { std::get<0>(dstring1_275) };
                                                    auto dstring1_snd_277 { std::get<1>(dstring1_275) };
                                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2855 { dstring1_snd_277.readBytes(dstring1_fst_276) };
                                                    ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2856;
                                                    {
                                                      auto dstring2_fst_279 { std::get<0>(id_2855) };
                                                      auto dstring2_snd_280 { std::get<1>(id_2855) };
                                                      std::string id_2857 { dstring2_fst_279.toString() };
                                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_2858 { std::in_place_index<1>, id_2857 };
                                                      ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 id_2859 { id_2858, dstring2_snd_280 };
                                                      letpair_res_2856 = id_2859;
                                                    }
                                                    letpair_res_2854 = letpair_res_2856;
                                                  }
                                                  let_res_2853 = letpair_res_2854;
                                                }
                                                choose_res_2760 = let_res_2853;
                                              }
                                              letpair_res_2757 = choose_res_2760;
                                            }
                                            let_res_2756 = letpair_res_2757;
                                          }
                                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2860;
                                          {
                                            auto dtup_fst_300 { std::get<0>(let_res_2756) };
                                            auto dtup_snd_301 { std::get<1>(let_res_2756) };
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_2861 { dtup_fst_258, dtup_fst_300 };
                                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2862 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<14>, id_2861) };
                                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2863 { id_2862, dtup_snd_301 };
                                            letpair_res_2860 = id_2863;
                                          }
                                          letpair_res_2752 = letpair_res_2860;
                                        }
                                        let_res_2751 = letpair_res_2752;
                                      }
                                      choose_res_2748 = let_res_2751;
                                    } else {
                                      uint16_t id_2864 { 15 };
                                      bool id_2865 { bool(dsum1_fst_144 == id_2864) };
                                      Void id_2866 { ((void)(assert(id_2865)), VOID) };
                                      (void)id_2866;
                                      uint32_t id_2867 { 0U };
                                      Vec<1, uint32_t> id_2868 {  id_2867  };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2869;
                                      {
                                        Vec<1, uint32_t> leb_ref_146 { id_2868 };
                                        uint8_t id_2870 { 0 };
                                        Vec<1, uint8_t> id_2871 {  id_2870  };
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2872;
                                        {
                                          Vec<1, uint8_t> shft_ref_147 { id_2871 };
                                          Vec<1, Pointer> id_2873 {  dsum1_snd_145  };
                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2874;
                                          {
                                            Vec<1, Pointer> p_ref_148 { id_2873 };
                                            bool while_flag_2875 { true };
                                            do {
                                              uint8_t id_2876 { 0 };
                                              Pointer id_2877 { p_ref_148[id_2876] };
                                              ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2878 { id_2877.readU8() };
                                              bool let_res_2879;
                                              {
                                                ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_149 { id_2878 };
                                                bool letpair_res_2880;
                                                {
                                                  auto leb128_fst_150 { std::get<0>(leb128_149) };
                                                  auto leb128_snd_151 { std::get<1>(leb128_149) };
                                                  uint8_t id_2881 { 0 };
                                                  Void id_2882 { ((void)(p_ref_148[id_2881] = leb128_snd_151), VOID) };
                                                  (void)id_2882;
                                                  uint8_t id_2883 { 0 };
                                                  uint8_t id_2884 { 127 };
                                                  uint8_t id_2885 { uint8_t(leb128_fst_150 & id_2884) };
                                                  uint32_t id_2886 { uint32_t(id_2885) };
                                                  uint8_t id_2887 { 0 };
                                                  uint8_t id_2888 { shft_ref_147[id_2887] };
                                                  uint32_t id_2889 { uint32_t(id_2886 << id_2888) };
                                                  uint8_t id_2890 { 0 };
                                                  uint32_t id_2891 { leb_ref_146[id_2890] };
                                                  uint32_t id_2892 { uint32_t(id_2889 | id_2891) };
                                                  Void id_2893 { ((void)(leb_ref_146[id_2883] = id_2892), VOID) };
                                                  (void)id_2893;
                                                  uint8_t id_2894 { 0 };
                                                  uint8_t id_2895 { 0 };
                                                  uint8_t id_2896 { shft_ref_147[id_2895] };
                                                  uint8_t id_2897 { 7 };
                                                  uint8_t id_2898 { uint8_t(id_2896 + id_2897) };
                                                  Void id_2899 { ((void)(shft_ref_147[id_2894] = id_2898), VOID) };
                                                  (void)id_2899;
                                                  uint8_t id_2900 { 128 };
                                                  bool id_2901 { bool(leb128_fst_150 >= id_2900) };
                                                  letpair_res_2880 = id_2901;
                                                }
                                                let_res_2879 = letpair_res_2880;
                                              }
                                              while_flag_2875 = let_res_2879;
                                              if (while_flag_2875) {
                                                (void)VOID;
                                              }
                                            } while (while_flag_2875);
                                            (void)VOID;
                                            uint8_t id_2902 { 0 };
                                            uint32_t id_2903 { leb_ref_146[id_2902] };
                                            Size id_2904 { Size(id_2903) };
                                            uint8_t id_2905 { 0 };
                                            Pointer id_2906 { p_ref_148[id_2905] };
                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2907 { id_2904, id_2906 };
                                            let_res_2874 = id_2907;
                                          }
                                          let_res_2872 = let_res_2874;
                                        }
                                        let_res_2869 = let_res_2872;
                                      }
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2908;
                                      {
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_152 { let_res_2869 };
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2909;
                                        {
                                          auto dstring1_fst_153 { std::get<0>(dstring1_152) };
                                          auto dstring1_snd_154 { std::get<1>(dstring1_152) };
                                          ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2910 { dstring1_snd_154.readBytes(dstring1_fst_153) };
                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2911;
                                          {
                                            auto dstring2_fst_156 { std::get<0>(id_2910) };
                                            auto dstring2_snd_157 { std::get<1>(id_2910) };
                                            std::string id_2912 { dstring2_fst_156.toString() };
                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2913 { id_2912, dstring2_snd_157 };
                                            letpair_res_2911 = id_2913;
                                          }
                                          letpair_res_2909 = letpair_res_2911;
                                        }
                                        let_res_2908 = letpair_res_2909;
                                      }
                                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2914;
                                      {
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_158 { let_res_2908 };
                                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2915;
                                        {
                                          auto dtup_fst_159 { std::get<0>(dtup_158) };
                                          auto dtup_snd_160 { std::get<1>(dtup_158) };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2916 { dtup_snd_160.readU16Le() };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2917;
                                          {
                                            auto du16_fst_162 { std::get<0>(id_2916) };
                                            auto du16_snd_163 { std::get<1>(id_2916) };
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2918 { du16_fst_162, du16_snd_163 };
                                            letpair_res_2917 = id_2918;
                                          }
                                          ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 let_res_2919;
                                          {
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_167 { letpair_res_2917 };
                                            ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_2920;
                                            {
                                              auto dsum1_fst_168 { std::get<0>(dsum1_167) };
                                              auto dsum1_snd_169 { std::get<1>(dsum1_167) };
                                              uint16_t id_2921 { 0 };
                                              bool id_2922 { bool(id_2921 == dsum1_fst_168) };
                                              ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2923;
                                              if (id_2922) {
                                                (void)VOID;
                                                ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2924 { std::in_place_index<0>, VOID };
                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2925 { id_2924, dsum1_snd_169 };
                                                choose_res_2923 = id_2925;
                                              } else {
                                                uint16_t id_2926 { 1 };
                                                bool id_2927 { bool(id_2926 == dsum1_fst_168) };
                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2928;
                                                if (id_2927) {
                                                  (void)VOID;
                                                  ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2929 { std::in_place_index<1>, VOID };
                                                  ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2930 { id_2929, dsum1_snd_169 };
                                                  choose_res_2928 = id_2930;
                                                } else {
                                                  uint16_t id_2931 { 2 };
                                                  bool id_2932 { bool(id_2931 == dsum1_fst_168) };
                                                  ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2933;
                                                  if (id_2932) {
                                                    (void)VOID;
                                                    ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2934 { std::in_place_index<2>, VOID };
                                                    ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2935 { id_2934, dsum1_snd_169 };
                                                    choose_res_2933 = id_2935;
                                                  } else {
                                                    uint16_t id_2936 { 3 };
                                                    bool id_2937 { bool(id_2936 == dsum1_fst_168) };
                                                    ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2938;
                                                    if (id_2937) {
                                                      (void)VOID;
                                                      ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2939 { std::in_place_index<3>, VOID };
                                                      ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2940 { id_2939, dsum1_snd_169 };
                                                      choose_res_2938 = id_2940;
                                                    } else {
                                                      uint16_t id_2941 { 4 };
                                                      bool id_2942 { bool(id_2941 == dsum1_fst_168) };
                                                      ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2943;
                                                      if (id_2942) {
                                                        (void)VOID;
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2944 { std::in_place_index<4>, VOID };
                                                        ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2945 { id_2944, dsum1_snd_169 };
                                                        choose_res_2943 = id_2945;
                                                      } else {
                                                        uint16_t id_2946 { 5 };
                                                        bool id_2947 { bool(id_2946 == dsum1_fst_168) };
                                                        ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2948;
                                                        if (id_2947) {
                                                          uint32_t id_2949 { 0U };
                                                          Vec<1, uint32_t> id_2950 {  id_2949  };
                                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2951;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_185 { id_2950 };
                                                            uint8_t id_2952 { 0 };
                                                            Vec<1, uint8_t> id_2953 {  id_2952  };
                                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2954;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_186 { id_2953 };
                                                              Vec<1, Pointer> id_2955 {  dsum1_snd_169  };
                                                              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2956;
                                                              {
                                                                Vec<1, Pointer> p_ref_187 { id_2955 };
                                                                bool while_flag_2957 { true };
                                                                do {
                                                                  uint8_t id_2958 { 0 };
                                                                  Pointer id_2959 { p_ref_187[id_2958] };
                                                                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2960 { id_2959.readU8() };
                                                                  bool let_res_2961;
                                                                  {
                                                                    ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_188 { id_2960 };
                                                                    bool letpair_res_2962;
                                                                    {
                                                                      auto leb128_fst_189 { std::get<0>(leb128_188) };
                                                                      auto leb128_snd_190 { std::get<1>(leb128_188) };
                                                                      uint8_t id_2963 { 0 };
                                                                      Void id_2964 { ((void)(p_ref_187[id_2963] = leb128_snd_190), VOID) };
                                                                      (void)id_2964;
                                                                      uint8_t id_2965 { 0 };
                                                                      uint8_t id_2966 { 127 };
                                                                      uint8_t id_2967 { uint8_t(leb128_fst_189 & id_2966) };
                                                                      uint32_t id_2968 { uint32_t(id_2967) };
                                                                      uint8_t id_2969 { 0 };
                                                                      uint8_t id_2970 { shft_ref_186[id_2969] };
                                                                      uint32_t id_2971 { uint32_t(id_2968 << id_2970) };
                                                                      uint8_t id_2972 { 0 };
                                                                      uint32_t id_2973 { leb_ref_185[id_2972] };
                                                                      uint32_t id_2974 { uint32_t(id_2971 | id_2973) };
                                                                      Void id_2975 { ((void)(leb_ref_185[id_2965] = id_2974), VOID) };
                                                                      (void)id_2975;
                                                                      uint8_t id_2976 { 0 };
                                                                      uint8_t id_2977 { 0 };
                                                                      uint8_t id_2978 { shft_ref_186[id_2977] };
                                                                      uint8_t id_2979 { 7 };
                                                                      uint8_t id_2980 { uint8_t(id_2978 + id_2979) };
                                                                      Void id_2981 { ((void)(shft_ref_186[id_2976] = id_2980), VOID) };
                                                                      (void)id_2981;
                                                                      uint8_t id_2982 { 128 };
                                                                      bool id_2983 { bool(leb128_fst_189 >= id_2982) };
                                                                      letpair_res_2962 = id_2983;
                                                                    }
                                                                    let_res_2961 = letpair_res_2962;
                                                                  }
                                                                  while_flag_2957 = let_res_2961;
                                                                  if (while_flag_2957) {
                                                                    (void)VOID;
                                                                  }
                                                                } while (while_flag_2957);
                                                                (void)VOID;
                                                                uint8_t id_2984 { 0 };
                                                                uint32_t id_2985 { leb_ref_185[id_2984] };
                                                                Size id_2986 { Size(id_2985) };
                                                                uint8_t id_2987 { 0 };
                                                                Pointer id_2988 { p_ref_187[id_2987] };
                                                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2989 { id_2986, id_2988 };
                                                                let_res_2956 = id_2989;
                                                              }
                                                              let_res_2954 = let_res_2956;
                                                            }
                                                            let_res_2951 = let_res_2954;
                                                          }
                                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2990;
                                                          {
                                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_191 { let_res_2951 };
                                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2991;
                                                            {
                                                              auto dstring1_fst_192 { std::get<0>(dstring1_191) };
                                                              auto dstring1_snd_193 { std::get<1>(dstring1_191) };
                                                              ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2992 { dstring1_snd_193.readBytes(dstring1_fst_192) };
                                                              ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2993;
                                                              {
                                                                auto dstring2_fst_195 { std::get<0>(id_2992) };
                                                                auto dstring2_snd_196 { std::get<1>(id_2992) };
                                                                std::string id_2994 { dstring2_fst_195.toString() };
                                                                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2995 { id_2994, dstring2_snd_196 };
                                                                letpair_res_2993 = id_2995;
                                                              }
                                                              letpair_res_2991 = letpair_res_2993;
                                                            }
                                                            let_res_2990 = letpair_res_2991;
                                                          }
                                                          ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 let_res_2996;
                                                          {
                                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_197 { let_res_2990 };
                                                            ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_2997;
                                                            {
                                                              auto dtup_fst_198 { std::get<0>(dtup_197) };
                                                              auto dtup_snd_199 { std::get<1>(dtup_197) };
                                                              ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2998 { dtup_snd_199.readU16Le() };
                                                              ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2999;
                                                              {
                                                                auto du16_fst_201 { std::get<0>(id_2998) };
                                                                auto du16_snd_202 { std::get<1>(id_2998) };
                                                                ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_3000 { du16_fst_201, du16_snd_202 };
                                                                letpair_res_2999 = id_3000;
                                                              }
                                                              ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 let_res_3001;
                                                              {
                                                                ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_206 { letpair_res_2999 };
                                                                ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 letpair_res_3002;
                                                                {
                                                                  auto dsum1_fst_207 { std::get<0>(dsum1_206) };
                                                                  auto dsum1_snd_208 { std::get<1>(dsum1_206) };
                                                                  uint16_t id_3003 { 0 };
                                                                  bool id_3004 { bool(id_3003 == dsum1_fst_207) };
                                                                  ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3005;
                                                                  if (id_3004) {
                                                                    (void)VOID;
                                                                    ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3006 { std::in_place_index<0>, VOID };
                                                                    ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3007 { id_3006, dsum1_snd_208 };
                                                                    choose_res_3005 = id_3007;
                                                                  } else {
                                                                    uint16_t id_3008 { 1 };
                                                                    bool id_3009 { bool(id_3008 == dsum1_fst_207) };
                                                                    ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3010;
                                                                    if (id_3009) {
                                                                      (void)VOID;
                                                                      ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3011 { std::in_place_index<1>, VOID };
                                                                      ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3012 { id_3011, dsum1_snd_208 };
                                                                      choose_res_3010 = id_3012;
                                                                    } else {
                                                                      uint16_t id_3013 { 2 };
                                                                      bool id_3014 { bool(id_3013 == dsum1_fst_207) };
                                                                      ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3015;
                                                                      if (id_3014) {
                                                                        (void)VOID;
                                                                        ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3016 { std::in_place_index<2>, VOID };
                                                                        ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3017 { id_3016, dsum1_snd_208 };
                                                                        choose_res_3015 = id_3017;
                                                                      } else {
                                                                        uint16_t id_3018 { 3 };
                                                                        bool id_3019 { bool(id_3018 == dsum1_fst_207) };
                                                                        ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3020;
                                                                        if (id_3019) {
                                                                          (void)VOID;
                                                                          ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3021 { std::in_place_index<3>, VOID };
                                                                          ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3022 { id_3021, dsum1_snd_208 };
                                                                          choose_res_3020 = id_3022;
                                                                        } else {
                                                                          uint16_t id_3023 { 4 };
                                                                          bool id_3024 { bool(id_3023 == dsum1_fst_207) };
                                                                          ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3025;
                                                                          if (id_3024) {
                                                                            (void)VOID;
                                                                            ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3026 { std::in_place_index<4>, VOID };
                                                                            ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3027 { id_3026, dsum1_snd_208 };
                                                                            choose_res_3025 = id_3027;
                                                                          } else {
                                                                            uint16_t id_3028 { 5 };
                                                                            bool id_3029 { bool(id_3028 == dsum1_fst_207) };
                                                                            ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3030;
                                                                            if (id_3029) {
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3031 { std::in_place_index<5>, VOID };
                                                                              ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3032 { id_3031, dsum1_snd_208 };
                                                                              choose_res_3030 = id_3032;
                                                                            } else {
                                                                              uint16_t id_3033 { 6 };
                                                                              bool id_3034 { bool(dsum1_fst_207 == id_3033) };
                                                                              Void id_3035 { ((void)(assert(id_3034)), VOID) };
                                                                              (void)id_3035;
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3036 { std::in_place_index<6>, VOID };
                                                                              ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3037 { id_3036, dsum1_snd_208 };
                                                                              choose_res_3030 = id_3037;
                                                                            }
                                                                            choose_res_3025 = choose_res_3030;
                                                                          }
                                                                          choose_res_3020 = choose_res_3025;
                                                                        }
                                                                        choose_res_3015 = choose_res_3020;
                                                                      }
                                                                      choose_res_3010 = choose_res_3015;
                                                                    }
                                                                    choose_res_3005 = choose_res_3010;
                                                                  }
                                                                  letpair_res_3002 = choose_res_3005;
                                                                }
                                                                let_res_3001 = letpair_res_3002;
                                                              }
                                                              ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_3038;
                                                              {
                                                                auto dtup_fst_231 { std::get<0>(let_res_3001) };
                                                                auto dtup_snd_232 { std::get<1>(let_res_3001) };
                                                                ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_3039 { dtup_fst_198, dtup_fst_231 };
                                                                ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_3040 { std::in_place_index<5>, id_3039 };
                                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_3041 { id_3040, dtup_snd_232 };
                                                                letpair_res_3038 = id_3041;
                                                              }
                                                              letpair_res_2997 = letpair_res_3038;
                                                            }
                                                            let_res_2996 = letpair_res_2997;
                                                          }
                                                          choose_res_2948 = let_res_2996;
                                                        } else {
                                                          uint16_t id_3042 { 6 };
                                                          bool id_3043 { bool(dsum1_fst_168 == id_3042) };
                                                          Void id_3044 { ((void)(assert(id_3043)), VOID) };
                                                          (void)id_3044;
                                                          ::dessser::gen::sync_key::tf568409f41c9c0a265f7302110fc9084 id_3045 { dsum1_snd_169.readU64Le() };
                                                          ::dessser::gen::sync_key::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_3046;
                                                          {
                                                            auto dfloat_fst_171 { std::get<0>(id_3045) };
                                                            auto dfloat_snd_172 { std::get<1>(id_3045) };
                                                            double id_3047 { float_of_qword(dfloat_fst_171) };
                                                            ::dessser::gen::sync_key::t5375de390f9cb5ae2ee5880ea1674828 id_3048 { id_3047, dfloat_snd_172 };
                                                            letpair_res_3046 = id_3048;
                                                          }
                                                          ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 let_res_3049;
                                                          {
                                                            ::dessser::gen::sync_key::t5375de390f9cb5ae2ee5880ea1674828 dtup_173 { letpair_res_3046 };
                                                            ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_3050;
                                                            {
                                                              auto dtup_fst_174 { std::get<0>(dtup_173) };
                                                              auto dtup_snd_175 { std::get<1>(dtup_173) };
                                                              ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_3051 { dtup_snd_175.readU32Le() };
                                                              ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_3052;
                                                              {
                                                                auto du32_fst_177 { std::get<0>(id_3051) };
                                                                auto du32_snd_178 { std::get<1>(id_3051) };
                                                                ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 id_3053 { dtup_fst_174, du32_fst_177 };
                                                                ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_3054 { std::in_place_index<6>, id_3053 };
                                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_3055 { id_3054, du32_snd_178 };
                                                                letpair_res_3052 = id_3055;
                                                              }
                                                              letpair_res_3050 = letpair_res_3052;
                                                            }
                                                            let_res_3049 = letpair_res_3050;
                                                          }
                                                          choose_res_2948 = let_res_3049;
                                                        }
                                                        choose_res_2943 = choose_res_2948;
                                                      }
                                                      choose_res_2938 = choose_res_2943;
                                                    }
                                                    choose_res_2933 = choose_res_2938;
                                                  }
                                                  choose_res_2928 = choose_res_2933;
                                                }
                                                choose_res_2923 = choose_res_2928;
                                              }
                                              letpair_res_2920 = choose_res_2923;
                                            }
                                            let_res_2919 = letpair_res_2920;
                                          }
                                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_3056;
                                          {
                                            auto dtup_fst_252 { std::get<0>(let_res_2919) };
                                            auto dtup_snd_253 { std::get<1>(let_res_2919) };
                                            ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_3057 { dtup_fst_159, dtup_fst_252 };
                                            std::shared_ptr<::dessser::gen::sync_key::t>  id_3058 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<15>, id_3057) };
                                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_3059 { id_3058, dtup_snd_253 };
                                            letpair_res_3056 = id_3059;
                                          }
                                          letpair_res_2915 = letpair_res_3056;
                                        }
                                        let_res_2914 = letpair_res_2915;
                                      }
                                      choose_res_2748 = let_res_2914;
                                    }
                                    choose_res_2743 = choose_res_2748;
                                  }
                                  choose_res_2686 = choose_res_2743;
                                }
                                choose_res_2674 = choose_res_2686;
                              }
                              choose_res_2669 = choose_res_2674;
                            }
                            choose_res_2647 = choose_res_2669;
                          }
                          choose_res_2640 = choose_res_2647;
                        }
                        choose_res_2575 = choose_res_2640;
                      }
                      choose_res_2503 = choose_res_2575;
                    }
                    choose_res_2188 = choose_res_2503;
                  }
                  choose_res_2183 = choose_res_2188;
                }
                choose_res_2127 = choose_res_2183;
              }
              choose_res_2076 = choose_res_2127;
            }
            choose_res_2071 = choose_res_2076;
          }
          choose_res_2066 = choose_res_2071;
        }
        letpair_res_2063 = choose_res_2066;
      }
      let_res_2062 = letpair_res_2063;
    }
    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_3060;
    {
      auto make_fst_648 { std::get<0>(let_res_2062) };
      auto make_snd_649 { std::get<1>(let_res_2062) };
      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_3061 { make_fst_648, make_snd_649 };
      letpair_res_3060 = id_3061;
    }
    return letpair_res_3060;
  }
   };
  return fun2058;
}
std::function<::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f(Pointer)> of_row_binary(of_row_binary_init());


}
