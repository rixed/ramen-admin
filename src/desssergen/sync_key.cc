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
struct per_worker_data : public std::variant<
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

struct per_worker : public std::tuple<
  dessser::gen::fq_name::t_ext,
  std::shared_ptr<::dessser::gen::sync_key::per_worker_data> 
> {
  using tuple::tuple;
  per_worker(std::tuple<dessser::gen::fq_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_worker_data> > p)
    : std::tuple<dessser::gen::fq_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_worker_data> >(std::get<0>(p), std::get<1>(p)) {}
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
struct per_site_data : public std::variant<
  Void, // IsMaster
  ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6, // PerService
  std::shared_ptr<::dessser::gen::sync_key::per_worker> , // PerWorker
  ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 // PerProgram
> { using variant::variant; };

struct per_site : public std::tuple<
  dessser::gen::site_name::t_ext,
  std::shared_ptr<::dessser::gen::sync_key::per_site_data> 
> {
  using tuple::tuple;
  per_site(std::tuple<dessser::gen::site_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_site_data> > p)
    : std::tuple<dessser::gen::site_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_site_data> >(std::get<0>(p), std::get<1>(p)) {}
};
struct t3f2a416abcbd7d33d681d9d47445767b : public std::tuple<
  dessser::gen::src_path::t_ext,
  std::string
> {
  using tuple::tuple;
  t3f2a416abcbd7d33d681d9d47445767b(std::tuple<dessser::gen::src_path::t_ext, std::string> p)
    : std::tuple<dessser::gen::src_path::t_ext, std::string>(std::get<0>(p), std::get<1>(p)) {}
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
  std::shared_ptr<::dessser::gen::sync_key::per_site> , // PerSite
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
struct t90fc3b1be159c3c586c0a94783c9137e : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,
  Pointer
> {
  using tuple::tuple;
  t90fc3b1be159c3c586c0a94783c9137e(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_worker_data> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_worker_data> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t3fd8221434e489b54b5c4356ebff5005 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t3fd8221434e489b54b5c4356ebff5005(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t0d6c591ce3b3ba893d6d35f4657ef1da : public std::tuple<
  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb,
  Pointer
> {
  using tuple::tuple;
  t0d6c591ce3b3ba893d6d35f4657ef1da(std::tuple<::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tff6c03fed00a106fb76636c5bf20ce1b : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_worker> ,
  Pointer
> {
  using tuple::tuple;
  tff6c03fed00a106fb76636c5bf20ce1b(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_worker> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_worker> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tcd6e38ac5ca8a381102d1fa6500e9b6e : public std::tuple<
  dessser::gen::fq_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tcd6e38ac5ca8a381102d1fa6500e9b6e(std::tuple<dessser::gen::fq_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t1e67a0abfbb837ff67a392b1e636c1b1 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,
  Pointer
> {
  using tuple::tuple;
  t1e67a0abfbb837ff67a392b1e636c1b1(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_site_data> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_site_data> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct t693b3c0b01440f82d6bb9ea682c4062e : public std::tuple<
  ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9,
  Pointer
> {
  using tuple::tuple;
  t693b3c0b01440f82d6bb9ea682c4062e(std::tuple<::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct teeca16372f8ab8650d4d2918b4f32e88 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_site> ,
  Pointer
> {
  using tuple::tuple;
  teeca16372f8ab8650d4d2918b4f32e88(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_site> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_site> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
struct tff906bde0664efb2415be180e5a241ea : public std::tuple<
  dessser::gen::site_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tff906bde0664efb2415be180e5a241ea(std::tuple<dessser::gen::site_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::site_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
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
      (let "ssum_dst_771" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (write-u32 little-endian (identifier "ssum_dst_771") (get-alt "Widgets" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> per_dash_key_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_771 { id_2 };
      uint16_t id_4 { uint16_t((*p_0).index()) };
      uint16_t id_5 { 0 };
      bool id_6 { bool(id_4 == id_5) };
      Void id_7 { ((void)(assert(id_6)), ::dessser::VOID) };
      (void)id_7;
      uint32_t id_8 { std::get<0 /* Widgets */>((*p_0)) };
      Pointer id_9 { ssum_dst_771.writeU32Le(id_8) };
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
      (let "ssum_dst_773" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_774" (make-vec (string-length (get-alt "Response" (param 0))))
              (let "leb128_ptr_775" (make-vec (identifier "ssum_dst_773"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_775")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_775"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_774"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_774"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_774"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_774") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_774")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_774")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_775"))))) 
            (bytes-of-string (get-alt "Response" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "per_dash_key-to-row-binary") (get-alt "Scratchpad" (param 0)) (identifier "ssum_dst_773"))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> per_client_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> fun10 { [&fun10](std::shared_ptr<::dessser::gen::sync_key::per_client>  p_0, Pointer p_1) {
    uint16_t id_11 { uint16_t((*p_0).index()) };
    Pointer id_12 { p_1.writeU16Le(id_11) };
    Pointer let_res_13;
    {
      Pointer ssum_dst_773 { id_12 };
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
          Vec<1, uint32_t> leb128_sz_774 { id_20 };
          Vec<1, Pointer> id_22 {  ssum_dst_773  };
          Pointer let_res_23;
          {
            Vec<1, Pointer> leb128_ptr_775 { id_22 };
            bool while_flag_24 { true };
            do {
              uint8_t id_25 { 0 };
              uint8_t id_26 { 0 };
              Pointer id_27 { leb128_ptr_775[id_26] };
              uint32_t id_28 { 128U };
              uint8_t id_29 { 0 };
              uint32_t id_30 { leb128_sz_774[id_29] };
              bool id_31 { bool(id_28 > id_30) };
              uint8_t choose_res_32;
              if (id_31) {
                uint8_t id_33 { 0 };
                uint32_t id_34 { leb128_sz_774[id_33] };
                uint8_t id_35 { uint8_t(id_34) };
                choose_res_32 = id_35;
              } else {
                uint8_t id_36 { 0 };
                uint32_t id_37 { leb128_sz_774[id_36] };
                uint8_t id_38 { uint8_t(id_37) };
                uint8_t id_39 { 128 };
                uint8_t id_40 { uint8_t(id_38 | id_39) };
                choose_res_32 = id_40;
              }
              Pointer id_41 { id_27.writeU8(choose_res_32) };
              Void id_42 { ((void)(leb128_ptr_775[id_25] = id_41), ::dessser::VOID) };
              (void)id_42;
              uint8_t id_43 { 0 };
              uint8_t id_44 { 0 };
              uint32_t id_45 { leb128_sz_774[id_44] };
              uint8_t id_46 { 7 };
              uint32_t id_47 { uint32_t(id_45 >> id_46) };
              Void id_48 { ((void)(leb128_sz_774[id_43] = id_47), ::dessser::VOID) };
              (void)id_48;
              uint8_t id_49 { 0 };
              uint32_t id_50 { leb128_sz_774[id_49] };
              uint32_t id_51 { 0U };
              bool id_52 { bool(id_50 > id_51) };
              while_flag_24 = id_52;
              if (while_flag_24) {
                (void)::dessser::VOID;
              }
            } while (while_flag_24);
            (void)::dessser::VOID;
            uint8_t id_53 { 0 };
            Pointer id_54 { leb128_ptr_775[id_53] };
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
        Void id_61 { ((void)(assert(id_60)), ::dessser::VOID) };
        (void)id_61;
        std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_62 { std::get<1 /* Scratchpad */>((*p_0)) };
        Pointer id_63 { per_dash_key_to_row_binary(id_62, ssum_dst_773) };
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
      (let "ssum_dst_767" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_768" (make-vec (string-length (get-alt "Subscriber" (param 0))))
              (let "leb128_ptr_769" (make-vec (identifier "ssum_dst_767"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_769")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_769"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_768"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_768"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_768"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_768") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_768")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_768")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_769"))))) 
            (bytes-of-string (get-alt "Subscriber" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (write-u32 little-endian (identifier "ssum_dst_767") (get-alt "LastTuple" (param 0)))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> per_tail_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> fun64 { [&fun64](std::shared_ptr<::dessser::gen::sync_key::per_tail>  p_0, Pointer p_1) {
    uint16_t id_65 { uint16_t((*p_0).index()) };
    Pointer id_66 { p_1.writeU16Le(id_65) };
    Pointer let_res_67;
    {
      Pointer ssum_dst_767 { id_66 };
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
          Vec<1, uint32_t> leb128_sz_768 { id_74 };
          Vec<1, Pointer> id_76 {  ssum_dst_767  };
          Pointer let_res_77;
          {
            Vec<1, Pointer> leb128_ptr_769 { id_76 };
            bool while_flag_78 { true };
            do {
              uint8_t id_79 { 0 };
              uint8_t id_80 { 0 };
              Pointer id_81 { leb128_ptr_769[id_80] };
              uint32_t id_82 { 128U };
              uint8_t id_83 { 0 };
              uint32_t id_84 { leb128_sz_768[id_83] };
              bool id_85 { bool(id_82 > id_84) };
              uint8_t choose_res_86;
              if (id_85) {
                uint8_t id_87 { 0 };
                uint32_t id_88 { leb128_sz_768[id_87] };
                uint8_t id_89 { uint8_t(id_88) };
                choose_res_86 = id_89;
              } else {
                uint8_t id_90 { 0 };
                uint32_t id_91 { leb128_sz_768[id_90] };
                uint8_t id_92 { uint8_t(id_91) };
                uint8_t id_93 { 128 };
                uint8_t id_94 { uint8_t(id_92 | id_93) };
                choose_res_86 = id_94;
              }
              Pointer id_95 { id_81.writeU8(choose_res_86) };
              Void id_96 { ((void)(leb128_ptr_769[id_79] = id_95), ::dessser::VOID) };
              (void)id_96;
              uint8_t id_97 { 0 };
              uint8_t id_98 { 0 };
              uint32_t id_99 { leb128_sz_768[id_98] };
              uint8_t id_100 { 7 };
              uint32_t id_101 { uint32_t(id_99 >> id_100) };
              Void id_102 { ((void)(leb128_sz_768[id_97] = id_101), ::dessser::VOID) };
              (void)id_102;
              uint8_t id_103 { 0 };
              uint32_t id_104 { leb128_sz_768[id_103] };
              uint32_t id_105 { 0U };
              bool id_106 { bool(id_104 > id_105) };
              while_flag_78 = id_106;
              if (while_flag_78) {
                (void)::dessser::VOID;
              }
            } while (while_flag_78);
            (void)::dessser::VOID;
            uint8_t id_107 { 0 };
            Pointer id_108 { leb128_ptr_769[id_107] };
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
        Void id_115 { ((void)(assert(id_114)), ::dessser::VOID) };
        (void)id_115;
        uint32_t id_116 { std::get<1 /* LastTuple */>((*p_0)) };
        Pointer id_117 { ssum_dst_767.writeU32Le(id_116) };
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
    (fun ("[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" "Ptr")
      (let "label1_745" (label-of (param 0))
        (let "ssum_dst_746" (write-u16 little-endian (param 1) (identifier "label1_745"))
          (if (eq (u16 0) (identifier "label1_745")) (identifier "ssum_dst_746")
            (if (eq (u16 1) (identifier "label1_745")) (identifier "ssum_dst_746")
              (if (eq (u16 2) (identifier "label1_745")) (identifier "ssum_dst_746")
                (if (eq (u16 3) (identifier "label1_745")) (identifier "ssum_dst_746")
                  (if (eq (u16 4) (identifier "label1_745")) (identifier "ssum_dst_746")
                    (if (eq (u16 5) (identifier "label1_745")) (identifier "ssum_dst_746")
                      (if (eq (u16 6) (identifier "label1_745"))
                        (let "stup_dst_749"
                          (write-bytes
                            (let "leb128_sz_747" (make-vec (string-length (get-item 0 (get-alt "PerInstance" (param 0)))))
                              (let "leb128_ptr_748" (make-vec (identifier "ssum_dst_746"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_748")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_748"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_747"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_747"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_747"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_747") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_747")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_747")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_748"))))) 
                            (bytes-of-string (get-item 0 (get-alt "PerInstance" (param 0)))))
                          (let "label1_750" (label-of (get-item 1 (get-alt "PerInstance" (param 0))))
                            (let "ssum_dst_751" (write-u16 little-endian (identifier "stup_dst_749") (identifier "label1_750"))
                              (if (eq (u16 0) (identifier "label1_750")) 
                                (identifier "ssum_dst_751")
                                (if (eq (u16 1) (identifier "label1_750")) 
                                  (identifier "ssum_dst_751")
                                  (if (eq (u16 2) (identifier "label1_750")) 
                                    (identifier "ssum_dst_751")
                                    (if (eq (u16 3) (identifier "label1_750")) 
                                      (identifier "ssum_dst_751")
                                      (if (eq (u16 4) (identifier "label1_750")) 
                                        (identifier "ssum_dst_751")
                                        (if (eq (u16 5) (identifier "label1_750")) 
                                          (identifier "ssum_dst_751") 
                                          (if (eq (u16 6) (identifier "label1_750")) (identifier "ssum_dst_751") (seq (assert (eq (identifier "label1_750") (u16 7))) (identifier "ssum_dst_751"))))))))))))
                        (if (eq (u16 7) (identifier "label1_745")) (write-u32 little-endian (identifier "ssum_dst_746") (get-alt "PerReplayer" (param 0)))
                          (seq (assert (eq (identifier "label1_745") (u16 8))) (identifier "ssum_dst_746")))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,Pointer)> per_worker_data_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,Pointer)> fun118 { [&fun118](std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  p_0, Pointer p_1) {
    uint16_t id_119 { uint16_t((*p_0).index()) };
    Pointer let_res_120;
    {
      uint16_t label1_745 { id_119 };
      Pointer id_121 { p_1.writeU16Le(label1_745) };
      Pointer let_res_122;
      {
        Pointer ssum_dst_746 { id_121 };
        uint16_t id_123 { 0 };
        bool id_124 { bool(id_123 == label1_745) };
        Pointer choose_res_125;
        if (id_124) {
          choose_res_125 = ssum_dst_746;
        } else {
          uint16_t id_126 { 1 };
          bool id_127 { bool(id_126 == label1_745) };
          Pointer choose_res_128;
          if (id_127) {
            choose_res_128 = ssum_dst_746;
          } else {
            uint16_t id_129 { 2 };
            bool id_130 { bool(id_129 == label1_745) };
            Pointer choose_res_131;
            if (id_130) {
              choose_res_131 = ssum_dst_746;
            } else {
              uint16_t id_132 { 3 };
              bool id_133 { bool(id_132 == label1_745) };
              Pointer choose_res_134;
              if (id_133) {
                choose_res_134 = ssum_dst_746;
              } else {
                uint16_t id_135 { 4 };
                bool id_136 { bool(id_135 == label1_745) };
                Pointer choose_res_137;
                if (id_136) {
                  choose_res_137 = ssum_dst_746;
                } else {
                  uint16_t id_138 { 5 };
                  bool id_139 { bool(id_138 == label1_745) };
                  Pointer choose_res_140;
                  if (id_139) {
                    choose_res_140 = ssum_dst_746;
                  } else {
                    uint16_t id_141 { 6 };
                    bool id_142 { bool(id_141 == label1_745) };
                    Pointer choose_res_143;
                    if (id_142) {
                      ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_144 { std::get<6 /* PerInstance */>((*p_0)) };
                      std::string id_145 { std::get<0>(id_144) };
                      uint32_t id_146 { (uint32_t)id_145.size() };
                      Vec<1, uint32_t> id_147 {  id_146  };
                      Pointer let_res_148;
                      {
                        Vec<1, uint32_t> leb128_sz_747 { id_147 };
                        Vec<1, Pointer> id_149 {  ssum_dst_746  };
                        Pointer let_res_150;
                        {
                          Vec<1, Pointer> leb128_ptr_748 { id_149 };
                          bool while_flag_151 { true };
                          do {
                            uint8_t id_152 { 0 };
                            uint8_t id_153 { 0 };
                            Pointer id_154 { leb128_ptr_748[id_153] };
                            uint32_t id_155 { 128U };
                            uint8_t id_156 { 0 };
                            uint32_t id_157 { leb128_sz_747[id_156] };
                            bool id_158 { bool(id_155 > id_157) };
                            uint8_t choose_res_159;
                            if (id_158) {
                              uint8_t id_160 { 0 };
                              uint32_t id_161 { leb128_sz_747[id_160] };
                              uint8_t id_162 { uint8_t(id_161) };
                              choose_res_159 = id_162;
                            } else {
                              uint8_t id_163 { 0 };
                              uint32_t id_164 { leb128_sz_747[id_163] };
                              uint8_t id_165 { uint8_t(id_164) };
                              uint8_t id_166 { 128 };
                              uint8_t id_167 { uint8_t(id_165 | id_166) };
                              choose_res_159 = id_167;
                            }
                            Pointer id_168 { id_154.writeU8(choose_res_159) };
                            Void id_169 { ((void)(leb128_ptr_748[id_152] = id_168), ::dessser::VOID) };
                            (void)id_169;
                            uint8_t id_170 { 0 };
                            uint8_t id_171 { 0 };
                            uint32_t id_172 { leb128_sz_747[id_171] };
                            uint8_t id_173 { 7 };
                            uint32_t id_174 { uint32_t(id_172 >> id_173) };
                            Void id_175 { ((void)(leb128_sz_747[id_170] = id_174), ::dessser::VOID) };
                            (void)id_175;
                            uint8_t id_176 { 0 };
                            uint32_t id_177 { leb128_sz_747[id_176] };
                            uint32_t id_178 { 0U };
                            bool id_179 { bool(id_177 > id_178) };
                            while_flag_151 = id_179;
                            if (while_flag_151) {
                              (void)::dessser::VOID;
                            }
                          } while (while_flag_151);
                          (void)::dessser::VOID;
                          uint8_t id_180 { 0 };
                          Pointer id_181 { leb128_ptr_748[id_180] };
                          let_res_150 = id_181;
                        }
                        let_res_148 = let_res_150;
                      }
                      ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_182 { std::get<6 /* PerInstance */>((*p_0)) };
                      std::string id_183 { std::get<0>(id_182) };
                      Bytes id_184 { id_183 };
                      Pointer id_185 { let_res_148.writeBytes(id_184) };
                      Pointer let_res_186;
                      {
                        Pointer stup_dst_749 { id_185 };
                        ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_187 { std::get<6 /* PerInstance */>((*p_0)) };
                        ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_188 { std::get<1>(id_187) };
                        uint16_t id_189 { uint16_t(id_188.index()) };
                        Pointer let_res_190;
                        {
                          uint16_t label1_750 { id_189 };
                          Pointer id_191 { stup_dst_749.writeU16Le(label1_750) };
                          Pointer let_res_192;
                          {
                            Pointer ssum_dst_751 { id_191 };
                            uint16_t id_193 { 0 };
                            bool id_194 { bool(id_193 == label1_750) };
                            Pointer choose_res_195;
                            if (id_194) {
                              choose_res_195 = ssum_dst_751;
                            } else {
                              uint16_t id_196 { 1 };
                              bool id_197 { bool(id_196 == label1_750) };
                              Pointer choose_res_198;
                              if (id_197) {
                                choose_res_198 = ssum_dst_751;
                              } else {
                                uint16_t id_199 { 2 };
                                bool id_200 { bool(id_199 == label1_750) };
                                Pointer choose_res_201;
                                if (id_200) {
                                  choose_res_201 = ssum_dst_751;
                                } else {
                                  uint16_t id_202 { 3 };
                                  bool id_203 { bool(id_202 == label1_750) };
                                  Pointer choose_res_204;
                                  if (id_203) {
                                    choose_res_204 = ssum_dst_751;
                                  } else {
                                    uint16_t id_205 { 4 };
                                    bool id_206 { bool(id_205 == label1_750) };
                                    Pointer choose_res_207;
                                    if (id_206) {
                                      choose_res_207 = ssum_dst_751;
                                    } else {
                                      uint16_t id_208 { 5 };
                                      bool id_209 { bool(id_208 == label1_750) };
                                      Pointer choose_res_210;
                                      if (id_209) {
                                        choose_res_210 = ssum_dst_751;
                                      } else {
                                        uint16_t id_211 { 6 };
                                        bool id_212 { bool(id_211 == label1_750) };
                                        Pointer choose_res_213;
                                        if (id_212) {
                                          choose_res_213 = ssum_dst_751;
                                        } else {
                                          uint16_t id_214 { 7 };
                                          bool id_215 { bool(label1_750 == id_214) };
                                          Void id_216 { ((void)(assert(id_215)), ::dessser::VOID) };
                                          (void)id_216;
                                          choose_res_213 = ssum_dst_751;
                                        }
                                        choose_res_210 = choose_res_213;
                                      }
                                      choose_res_207 = choose_res_210;
                                    }
                                    choose_res_204 = choose_res_207;
                                  }
                                  choose_res_201 = choose_res_204;
                                }
                                choose_res_198 = choose_res_201;
                              }
                              choose_res_195 = choose_res_198;
                            }
                            let_res_192 = choose_res_195;
                          }
                          let_res_190 = let_res_192;
                        }
                        let_res_186 = let_res_190;
                      }
                      choose_res_143 = let_res_186;
                    } else {
                      uint16_t id_217 { 7 };
                      bool id_218 { bool(id_217 == label1_745) };
                      Pointer choose_res_219;
                      if (id_218) {
                        uint32_t id_220 { std::get<7 /* PerReplayer */>((*p_0)) };
                        Pointer id_221 { ssum_dst_746.writeU32Le(id_220) };
                        choose_res_219 = id_221;
                      } else {
                        uint16_t id_222 { 8 };
                        bool id_223 { bool(label1_745 == id_222) };
                        Void id_224 { ((void)(assert(id_223)), ::dessser::VOID) };
                        (void)id_224;
                        choose_res_219 = ssum_dst_746;
                      }
                      choose_res_143 = choose_res_219;
                    }
                    choose_res_140 = choose_res_143;
                  }
                  choose_res_137 = choose_res_140;
                }
                choose_res_134 = choose_res_137;
              }
              choose_res_131 = choose_res_134;
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
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,Pointer)> per_worker_data_to_row_binary(per_worker_data_to_row_binary_init());

/* 
    (fun ("($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))" "Ptr")
      (let "stup_dst_752" (apply (ext-identifier fq_name to-row-binary) (get-item 0 (param 0)) (param 1)) (apply (identifier "per_worker_data-to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_752"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker> ,Pointer)> per_worker_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker> ,Pointer)> fun225 { [&fun225](std::shared_ptr<::dessser::gen::sync_key::per_worker>  p_0, Pointer p_1) {
    auto fun226 { dessser::gen::fq_name::to_row_binary };
    dessser::gen::fq_name::t_ext id_227 { std::get<0>((*p_0)) };
    Pointer id_228 { fun226(id_227, p_1) };
    Pointer let_res_229;
    {
      Pointer stup_dst_752 { id_228 };
      std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_230 { std::get<1>((*p_0)) };
      Pointer id_231 { per_worker_data_to_row_binary(id_230, stup_dst_752) };
      let_res_229 = id_231;
    }
    return let_res_229;
  }
   };
  return fun225;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker> ,Pointer)> per_worker_to_row_binary(per_worker_to_row_binary_init());

/* 
    (fun ("[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" "Ptr")
      (let "ssum_dst_754" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_754")
          (if (eq (u16 1) (label-of (param 0)))
            (let "stup_dst_762"
              (write-bytes
                (let "leb128_sz_760" (make-vec (string-length (get-item 0 (get-alt "PerService" (param 0)))))
                  (let "leb128_ptr_761" (make-vec (identifier "ssum_dst_754"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_761")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_761"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_760"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_760"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_760"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_760") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_760")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_760")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_761"))))) 
                (bytes-of-string (get-item 0 (get-alt "PerService" (param 0)))))
              (let "ssum_dst_764" (write-u16 little-endian (identifier "stup_dst_762") (label-of (get-item 1 (get-alt "PerService" (param 0)))))
                (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (param 0))))) 
                  (identifier "ssum_dst_764") (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (param 0)))) (u16 1))) (identifier "ssum_dst_764")))))
            (if (eq (u16 2) (label-of (param 0))) (apply (identifier "per_worker-to-row-binary") (get-alt "PerWorker" (param 0)) (identifier "ssum_dst_754"))
              (seq (assert (eq (label-of (param 0)) (u16 3)))
                (let "stup_dst_757"
                  (write-bytes
                    (let "leb128_sz_755" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (param 0)))))
                      (let "leb128_ptr_756" (make-vec (identifier "ssum_dst_754"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_756")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_756"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_755"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_755"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_755"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_755") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_755")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_755")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_756"))))) 
                    (bytes-of-string (get-item 0 (get-alt "PerProgram" (param 0)))))
                  (let "ssum_dst_759" (write-u16 little-endian (identifier "stup_dst_757") (label-of (get-item 1 (get-alt "PerProgram" (param 0)))))
                    (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (param 0)))) (u16 0))) (identifier "ssum_dst_759"))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,Pointer)> per_site_data_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,Pointer)> fun232 { [&fun232](std::shared_ptr<::dessser::gen::sync_key::per_site_data>  p_0, Pointer p_1) {
    uint16_t id_233 { uint16_t((*p_0).index()) };
    Pointer id_234 { p_1.writeU16Le(id_233) };
    Pointer let_res_235;
    {
      Pointer ssum_dst_754 { id_234 };
      uint16_t id_236 { 0 };
      uint16_t id_237 { uint16_t((*p_0).index()) };
      bool id_238 { bool(id_236 == id_237) };
      Pointer choose_res_239;
      if (id_238) {
        choose_res_239 = ssum_dst_754;
      } else {
        uint16_t id_240 { 1 };
        uint16_t id_241 { uint16_t((*p_0).index()) };
        bool id_242 { bool(id_240 == id_241) };
        Pointer choose_res_243;
        if (id_242) {
          ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_244 { std::get<1 /* PerService */>((*p_0)) };
          std::string id_245 { std::get<0>(id_244) };
          uint32_t id_246 { (uint32_t)id_245.size() };
          Vec<1, uint32_t> id_247 {  id_246  };
          Pointer let_res_248;
          {
            Vec<1, uint32_t> leb128_sz_760 { id_247 };
            Vec<1, Pointer> id_249 {  ssum_dst_754  };
            Pointer let_res_250;
            {
              Vec<1, Pointer> leb128_ptr_761 { id_249 };
              bool while_flag_251 { true };
              do {
                uint8_t id_252 { 0 };
                uint8_t id_253 { 0 };
                Pointer id_254 { leb128_ptr_761[id_253] };
                uint32_t id_255 { 128U };
                uint8_t id_256 { 0 };
                uint32_t id_257 { leb128_sz_760[id_256] };
                bool id_258 { bool(id_255 > id_257) };
                uint8_t choose_res_259;
                if (id_258) {
                  uint8_t id_260 { 0 };
                  uint32_t id_261 { leb128_sz_760[id_260] };
                  uint8_t id_262 { uint8_t(id_261) };
                  choose_res_259 = id_262;
                } else {
                  uint8_t id_263 { 0 };
                  uint32_t id_264 { leb128_sz_760[id_263] };
                  uint8_t id_265 { uint8_t(id_264) };
                  uint8_t id_266 { 128 };
                  uint8_t id_267 { uint8_t(id_265 | id_266) };
                  choose_res_259 = id_267;
                }
                Pointer id_268 { id_254.writeU8(choose_res_259) };
                Void id_269 { ((void)(leb128_ptr_761[id_252] = id_268), ::dessser::VOID) };
                (void)id_269;
                uint8_t id_270 { 0 };
                uint8_t id_271 { 0 };
                uint32_t id_272 { leb128_sz_760[id_271] };
                uint8_t id_273 { 7 };
                uint32_t id_274 { uint32_t(id_272 >> id_273) };
                Void id_275 { ((void)(leb128_sz_760[id_270] = id_274), ::dessser::VOID) };
                (void)id_275;
                uint8_t id_276 { 0 };
                uint32_t id_277 { leb128_sz_760[id_276] };
                uint32_t id_278 { 0U };
                bool id_279 { bool(id_277 > id_278) };
                while_flag_251 = id_279;
                if (while_flag_251) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_251);
              (void)::dessser::VOID;
              uint8_t id_280 { 0 };
              Pointer id_281 { leb128_ptr_761[id_280] };
              let_res_250 = id_281;
            }
            let_res_248 = let_res_250;
          }
          ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_282 { std::get<1 /* PerService */>((*p_0)) };
          std::string id_283 { std::get<0>(id_282) };
          Bytes id_284 { id_283 };
          Pointer id_285 { let_res_248.writeBytes(id_284) };
          Pointer let_res_286;
          {
            Pointer stup_dst_762 { id_285 };
            ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_287 { std::get<1 /* PerService */>((*p_0)) };
            ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_288 { std::get<1>(id_287) };
            uint16_t id_289 { uint16_t(id_288.index()) };
            Pointer id_290 { stup_dst_762.writeU16Le(id_289) };
            Pointer let_res_291;
            {
              Pointer ssum_dst_764 { id_290 };
              uint16_t id_292 { 0 };
              ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_293 { std::get<1 /* PerService */>((*p_0)) };
              ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_294 { std::get<1>(id_293) };
              uint16_t id_295 { uint16_t(id_294.index()) };
              bool id_296 { bool(id_292 == id_295) };
              Pointer choose_res_297;
              if (id_296) {
                choose_res_297 = ssum_dst_764;
              } else {
                ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_298 { std::get<1 /* PerService */>((*p_0)) };
                ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_299 { std::get<1>(id_298) };
                uint16_t id_300 { uint16_t(id_299.index()) };
                uint16_t id_301 { 1 };
                bool id_302 { bool(id_300 == id_301) };
                Void id_303 { ((void)(assert(id_302)), ::dessser::VOID) };
                (void)id_303;
                choose_res_297 = ssum_dst_764;
              }
              let_res_291 = choose_res_297;
            }
            let_res_286 = let_res_291;
          }
          choose_res_243 = let_res_286;
        } else {
          uint16_t id_304 { 2 };
          uint16_t id_305 { uint16_t((*p_0).index()) };
          bool id_306 { bool(id_304 == id_305) };
          Pointer choose_res_307;
          if (id_306) {
            std::shared_ptr<::dessser::gen::sync_key::per_worker>  id_308 { std::get<2 /* PerWorker */>((*p_0)) };
            Pointer id_309 { per_worker_to_row_binary(id_308, ssum_dst_754) };
            choose_res_307 = id_309;
          } else {
            uint16_t id_310 { uint16_t((*p_0).index()) };
            uint16_t id_311 { 3 };
            bool id_312 { bool(id_310 == id_311) };
            Void id_313 { ((void)(assert(id_312)), ::dessser::VOID) };
            (void)id_313;
            ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_314 { std::get<3 /* PerProgram */>((*p_0)) };
            std::string id_315 { std::get<0>(id_314) };
            uint32_t id_316 { (uint32_t)id_315.size() };
            Vec<1, uint32_t> id_317 {  id_316  };
            Pointer let_res_318;
            {
              Vec<1, uint32_t> leb128_sz_755 { id_317 };
              Vec<1, Pointer> id_319 {  ssum_dst_754  };
              Pointer let_res_320;
              {
                Vec<1, Pointer> leb128_ptr_756 { id_319 };
                bool while_flag_321 { true };
                do {
                  uint8_t id_322 { 0 };
                  uint8_t id_323 { 0 };
                  Pointer id_324 { leb128_ptr_756[id_323] };
                  uint32_t id_325 { 128U };
                  uint8_t id_326 { 0 };
                  uint32_t id_327 { leb128_sz_755[id_326] };
                  bool id_328 { bool(id_325 > id_327) };
                  uint8_t choose_res_329;
                  if (id_328) {
                    uint8_t id_330 { 0 };
                    uint32_t id_331 { leb128_sz_755[id_330] };
                    uint8_t id_332 { uint8_t(id_331) };
                    choose_res_329 = id_332;
                  } else {
                    uint8_t id_333 { 0 };
                    uint32_t id_334 { leb128_sz_755[id_333] };
                    uint8_t id_335 { uint8_t(id_334) };
                    uint8_t id_336 { 128 };
                    uint8_t id_337 { uint8_t(id_335 | id_336) };
                    choose_res_329 = id_337;
                  }
                  Pointer id_338 { id_324.writeU8(choose_res_329) };
                  Void id_339 { ((void)(leb128_ptr_756[id_322] = id_338), ::dessser::VOID) };
                  (void)id_339;
                  uint8_t id_340 { 0 };
                  uint8_t id_341 { 0 };
                  uint32_t id_342 { leb128_sz_755[id_341] };
                  uint8_t id_343 { 7 };
                  uint32_t id_344 { uint32_t(id_342 >> id_343) };
                  Void id_345 { ((void)(leb128_sz_755[id_340] = id_344), ::dessser::VOID) };
                  (void)id_345;
                  uint8_t id_346 { 0 };
                  uint32_t id_347 { leb128_sz_755[id_346] };
                  uint32_t id_348 { 0U };
                  bool id_349 { bool(id_347 > id_348) };
                  while_flag_321 = id_349;
                  if (while_flag_321) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_321);
                (void)::dessser::VOID;
                uint8_t id_350 { 0 };
                Pointer id_351 { leb128_ptr_756[id_350] };
                let_res_320 = id_351;
              }
              let_res_318 = let_res_320;
            }
            ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_352 { std::get<3 /* PerProgram */>((*p_0)) };
            std::string id_353 { std::get<0>(id_352) };
            Bytes id_354 { id_353 };
            Pointer id_355 { let_res_318.writeBytes(id_354) };
            Pointer let_res_356;
            {
              Pointer stup_dst_757 { id_355 };
              ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_357 { std::get<3 /* PerProgram */>((*p_0)) };
              ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_358 { std::get<1>(id_357) };
              uint16_t id_359 { uint16_t(id_358.index()) };
              Pointer id_360 { stup_dst_757.writeU16Le(id_359) };
              Pointer let_res_361;
              {
                Pointer ssum_dst_759 { id_360 };
                ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_362 { std::get<3 /* PerProgram */>((*p_0)) };
                ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_363 { std::get<1>(id_362) };
                uint16_t id_364 { uint16_t(id_363.index()) };
                uint16_t id_365 { 0 };
                bool id_366 { bool(id_364 == id_365) };
                Void id_367 { ((void)(assert(id_366)), ::dessser::VOID) };
                (void)id_367;
                let_res_361 = ssum_dst_759;
              }
              let_res_356 = let_res_361;
            }
            choose_res_307 = let_res_356;
          }
          choose_res_243 = choose_res_307;
        }
        choose_res_239 = choose_res_243;
      }
      let_res_235 = choose_res_239;
    }
    return let_res_235;
  }
   };
  return fun232;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,Pointer)> per_site_data_to_row_binary(per_site_data_to_row_binary_init());

/* 
    (fun ("($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))" "Ptr")
      (let "stup_dst_765" (apply (ext-identifier site_name to-row-binary) (get-item 0 (param 0)) (param 1)) (apply (identifier "per_site_data-to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_765"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site> ,Pointer)> per_site_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site> ,Pointer)> fun368 { [&fun368](std::shared_ptr<::dessser::gen::sync_key::per_site>  p_0, Pointer p_1) {
    auto fun369 { dessser::gen::site_name::to_row_binary };
    dessser::gen::site_name::t_ext id_370 { std::get<0>((*p_0)) };
    Pointer id_371 { fun369(id_370, p_1) };
    Pointer let_res_372;
    {
      Pointer stup_dst_765 { id_371 };
      std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_373 { std::get<1>((*p_0)) };
      Pointer id_374 { per_site_data_to_row_binary(id_373, stup_dst_765) };
      let_res_372 = id_374;
    }
    return let_res_372;
  }
   };
  return fun368;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site> ,Pointer)> per_site_to_row_binary(per_site_to_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" "Ptr")
      (let "label1_776" (label-of (param 0))
        (let "ssum_dst_777" (write-u16 little-endian (param 1) (identifier "label1_776"))
          (if (eq (u16 0) (identifier "label1_776")) (identifier "ssum_dst_777")
            (if (eq (u16 1) (identifier "label1_776")) (identifier "ssum_dst_777")
              (if (eq (u16 2) (identifier "label1_776"))
                (write-bytes
                  (let "leb128_sz_812" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "leb128_ptr_813" (make-vec (identifier "ssum_dst_777"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_813")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_813"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_812"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_812"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_812"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_812") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_812")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_812")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_813"))))) 
                  (bytes-of-string (get-alt "Versions" (param 0))))
                (if (eq (u16 3) (identifier "label1_776"))
                  (let "stup_dst_809" (apply (ext-identifier src_path to-row-binary) (get-item 0 (get-alt "Sources" (param 0))) (identifier "ssum_dst_777"))
                    (write-bytes
                      (let "leb128_sz_810" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "leb128_ptr_811" (make-vec (identifier "stup_dst_809"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_811")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_811"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_810"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_810"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_810"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_810") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_810")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_810")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_811"))))) 
                      (bytes-of-string (get-item 1 (get-alt "Sources" (param 0))))))
                  (if (eq (u16 4) (identifier "label1_776")) (identifier "ssum_dst_777")
                    (if (eq (u16 5) (identifier "label1_776")) (apply (identifier "per_site-to-row-binary") (get-alt "PerSite" (param 0)) (identifier "ssum_dst_777"))
                      (if (eq (u16 6) (identifier "label1_776"))
                        (let "ssum_dst_806" (write-u16 little-endian (identifier "ssum_dst_777") (label-of (get-alt "Storage" (param 0))))
                          (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                            (identifier "ssum_dst_806")
                            (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                              (identifier "ssum_dst_806")
                              (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                                (write-bytes
                                  (let "leb128_sz_807" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                    (let "leb128_ptr_808" (make-vec (identifier "ssum_dst_806"))
                                      (seq
                                        (while
                                          (seq
                                            (set-vec (u8 0) (identifier "leb128_ptr_808")
                                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_808"))
                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_807"))) 
                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_807"))) 
                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_807"))) (u8 128)))))
                                            (set-vec (u8 0) (identifier "leb128_sz_807") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_807")) (u8 7))) 
                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_807")) (u32 0))) 
                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_808"))))) 
                                  (bytes-of-string (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))))))
                        (if (eq (u16 7) (identifier "label1_776"))
                          (let "stup_dst_804"
                            (let "stup_dst_801"
                              (let "stup_dst_800" (apply (ext-identifier site_name to-row-binary) (get-item 0 (get-alt "Tails" (param 0))) (identifier "ssum_dst_777"))
                                (apply (ext-identifier fq_name to-row-binary) (get-item 1 (get-alt "Tails" (param 0))) (identifier "stup_dst_800")))
                              (write-bytes
                                (let "leb128_sz_802" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "leb128_ptr_803" (make-vec (identifier "stup_dst_801"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_803")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_803"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_802"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_802"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_802"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_802") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_802")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_802")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_803"))))) 
                                (bytes-of-string (get-item 2 (get-alt "Tails" (param 0)))))) 
                            (apply (identifier "per_tail-to-row-binary") (get-item 3 (get-alt "Tails" (param 0))) (identifier "stup_dst_804")))
                          (if (eq (u16 8) (identifier "label1_776")) 
                            (write-u16 little-endian (identifier "ssum_dst_777") (get-alt "Replays" (param 0)))
                            (if (eq (u16 9) (identifier "label1_776"))
                              (if (is-null (get-alt "Error" (param 0))) 
                                (write-u8 (identifier "ssum_dst_777") (u8 1)) 
                                (apply (ext-identifier sync_socket to-row-binary) (force (get-alt "Error" (param 0))) (write-u8 (identifier "ssum_dst_777") (u8 0))))
                              (if (eq (u16 10) (identifier "label1_776")) 
                                (identifier "ssum_dst_777")
                                (if (eq (u16 11) (identifier "label1_776"))
                                  (let "stup_dst_799" (apply (ext-identifier sync_socket to-row-binary) (get-item 0 (get-alt "PerClient" (param 0))) (identifier "ssum_dst_777"))
                                    (apply (identifier "per_client-to-row-binary") (get-item 1 (get-alt "PerClient" (param 0))) (identifier "stup_dst_799")))
                                  (if (eq (u16 12) (identifier "label1_776"))
                                    (let "stup_dst_798"
                                      (write-bytes
                                        (let "leb128_sz_796" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "leb128_ptr_797" (make-vec (identifier "ssum_dst_777"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_797")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_797"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_796"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_796"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_796"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_796") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_796")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_796")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_797"))))) 
                                        (bytes-of-string (get-item 0 (get-alt "Dashboards" (param 0))))) 
                                      (apply (identifier "per_dash_key-to-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))) (identifier "stup_dst_798")))
                                    (if (eq (u16 13) (identifier "label1_776")) 
                                      (identifier "ssum_dst_777")
                                      (if (eq (u16 14) (identifier "label1_776"))
                                        (let "stup_dst_789" (apply (ext-identifier team_name to-row-binary) (get-item 0 (get-alt "Teams" (param 0))) (identifier "ssum_dst_777"))
                                          (let "ssum_dst_791" (write-u16 little-endian (identifier "stup_dst_789") (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                            (if (eq (u16 0) (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                              (write-bytes
                                                (let "leb128_sz_794" 
                                                  (make-vec (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                                  (let "leb128_ptr_795" 
                                                    (make-vec (identifier "ssum_dst_791"))
                                                    (seq
                                                      (while
                                                        (seq
                                                          (set-vec (u8 0) 
                                                            (identifier "leb128_ptr_795")
                                                            (write-u8 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_795"))
                                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_794"))) 
                                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_794"))) 
                                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_794"))) (u8 128)))))
                                                          (set-vec (u8 0) (identifier "leb128_sz_794") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_794")) (u8 7)))
                                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_794")) (u32 0))) 
                                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_795"))))) 
                                                (bytes-of-string (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                              (seq (assert (eq (label-of (get-item 1 (get-alt "Teams" (param 0)))) (u16 1)))
                                                (write-bytes
                                                  (let "leb128_sz_792" 
                                                    (make-vec (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))
                                                    (let "leb128_ptr_793" 
                                                      (make-vec (identifier "ssum_dst_791"))
                                                      (seq
                                                        (while
                                                          (seq
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb128_ptr_793")
                                                              (write-u8 
                                                                (unsafe-nth (u8 0) (identifier "leb128_ptr_793"))
                                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_792"))) 
                                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_792"))) 
                                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_792"))) (u8 128)))))
                                                            (set-vec (u8 0) (identifier "leb128_sz_792") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_792")) (u8 7)))
                                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_792")) (u32 0))) 
                                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_793"))))) 
                                                  (bytes-of-string (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))))))
                                        (seq (assert (eq (identifier "label1_776") (u16 15)))
                                          (let "stup_dst_780"
                                            (write-bytes
                                              (let "leb128_sz_778" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "leb128_ptr_779" 
                                                  (make-vec (identifier "ssum_dst_777"))
                                                  (seq
                                                    (while
                                                      (seq
                                                        (set-vec (u8 0) 
                                                          (identifier "leb128_ptr_779")
                                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_779"))
                                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_778"))) 
                                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_778"))) 
                                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_778"))) (u8 128)))))
                                                        (set-vec (u8 0) (identifier "leb128_sz_778") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_778")) (u8 7)))
                                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_778")) (u32 0))) 
                                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_779"))))) 
                                              (bytes-of-string (get-item 0 (get-alt "Incidents" (param 0)))))
                                            (let "label1_781" (label-of (get-item 1 (get-alt "Incidents" (param 0))))
                                              (let "ssum_dst_782" (write-u16 little-endian (identifier "stup_dst_780") (identifier "label1_781"))
                                                (if (eq (u16 0) (identifier "label1_781")) 
                                                  (identifier "ssum_dst_782")
                                                  (if (eq (u16 1) (identifier "label1_781")) 
                                                    (identifier "ssum_dst_782")
                                                    (if (eq (u16 2) (identifier "label1_781")) 
                                                      (identifier "ssum_dst_782")
                                                      (if (eq (u16 3) (identifier "label1_781")) 
                                                        (identifier "ssum_dst_782")
                                                        (if (eq (u16 4) (identifier "label1_781")) 
                                                          (identifier "ssum_dst_782")
                                                          (if (eq (u16 5) (identifier "label1_781"))
                                                            (let "stup_dst_786"
                                                              (write-bytes
                                                                (let "leb128_sz_784" 
                                                                  (make-vec (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                  (let "leb128_ptr_785" 
                                                                    (make-vec (identifier "ssum_dst_782"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_785")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_785"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_784"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_784"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_784"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_784") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_784")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_784")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_785"))))) 
                                                                (bytes-of-string (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                              (let "label1_787" 
                                                                (label-of (get-item 1 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0))))))
                                                                (let "ssum_dst_788" 
                                                                  (write-u16 little-endian (identifier "stup_dst_786") (identifier "label1_787"))
                                                                  (if 
                                                                    (eq (u16 0) (identifier "label1_787")) 
                                                                    (identifier "ssum_dst_788")
                                                                    (if 
                                                                    (eq (u16 1) (identifier "label1_787")) 
                                                                    (identifier "ssum_dst_788")
                                                                    (if 
                                                                    (eq (u16 2) (identifier "label1_787")) 
                                                                    (identifier "ssum_dst_788")
                                                                    (if 
                                                                    (eq (u16 3) (identifier "label1_787")) 
                                                                    (identifier "ssum_dst_788")
                                                                    (if 
                                                                    (eq (u16 4) (identifier "label1_787")) 
                                                                    (identifier "ssum_dst_788")
                                                                    (if (eq (u16 5) (identifier "label1_787")) (identifier "ssum_dst_788") (seq (assert (eq (identifier "label1_787") (u16 6))) (identifier "ssum_dst_788")))))))))))
                                                            (seq (assert (eq (identifier "label1_781") (u16 6)))
                                                              (let "stup_dst_783" 
                                                                (write-u64 little-endian (identifier "ssum_dst_782") (u64-of-float (get-item 0 (get-alt "Journal" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                (write-u32 little-endian (identifier "stup_dst_783") (get-item 1 (get-alt "Journal" (get-item 1 (get-alt "Incidents" (param 0))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> fun375 { [&fun375](std::shared_ptr<::dessser::gen::sync_key::t>  p_0, Pointer p_1) {
    uint16_t id_376 { uint16_t((*p_0).index()) };
    Pointer let_res_377;
    {
      uint16_t label1_776 { id_376 };
      Pointer id_378 { p_1.writeU16Le(label1_776) };
      Pointer let_res_379;
      {
        Pointer ssum_dst_777 { id_378 };
        uint16_t id_380 { 0 };
        bool id_381 { bool(id_380 == label1_776) };
        Pointer choose_res_382;
        if (id_381) {
          choose_res_382 = ssum_dst_777;
        } else {
          uint16_t id_383 { 1 };
          bool id_384 { bool(id_383 == label1_776) };
          Pointer choose_res_385;
          if (id_384) {
            choose_res_385 = ssum_dst_777;
          } else {
            uint16_t id_386 { 2 };
            bool id_387 { bool(id_386 == label1_776) };
            Pointer choose_res_388;
            if (id_387) {
              std::string id_389 { std::get<2 /* Versions */>((*p_0)) };
              uint32_t id_390 { (uint32_t)id_389.size() };
              Vec<1, uint32_t> id_391 {  id_390  };
              Pointer let_res_392;
              {
                Vec<1, uint32_t> leb128_sz_812 { id_391 };
                Vec<1, Pointer> id_393 {  ssum_dst_777  };
                Pointer let_res_394;
                {
                  Vec<1, Pointer> leb128_ptr_813 { id_393 };
                  bool while_flag_395 { true };
                  do {
                    uint8_t id_396 { 0 };
                    uint8_t id_397 { 0 };
                    Pointer id_398 { leb128_ptr_813[id_397] };
                    uint32_t id_399 { 128U };
                    uint8_t id_400 { 0 };
                    uint32_t id_401 { leb128_sz_812[id_400] };
                    bool id_402 { bool(id_399 > id_401) };
                    uint8_t choose_res_403;
                    if (id_402) {
                      uint8_t id_404 { 0 };
                      uint32_t id_405 { leb128_sz_812[id_404] };
                      uint8_t id_406 { uint8_t(id_405) };
                      choose_res_403 = id_406;
                    } else {
                      uint8_t id_407 { 0 };
                      uint32_t id_408 { leb128_sz_812[id_407] };
                      uint8_t id_409 { uint8_t(id_408) };
                      uint8_t id_410 { 128 };
                      uint8_t id_411 { uint8_t(id_409 | id_410) };
                      choose_res_403 = id_411;
                    }
                    Pointer id_412 { id_398.writeU8(choose_res_403) };
                    Void id_413 { ((void)(leb128_ptr_813[id_396] = id_412), ::dessser::VOID) };
                    (void)id_413;
                    uint8_t id_414 { 0 };
                    uint8_t id_415 { 0 };
                    uint32_t id_416 { leb128_sz_812[id_415] };
                    uint8_t id_417 { 7 };
                    uint32_t id_418 { uint32_t(id_416 >> id_417) };
                    Void id_419 { ((void)(leb128_sz_812[id_414] = id_418), ::dessser::VOID) };
                    (void)id_419;
                    uint8_t id_420 { 0 };
                    uint32_t id_421 { leb128_sz_812[id_420] };
                    uint32_t id_422 { 0U };
                    bool id_423 { bool(id_421 > id_422) };
                    while_flag_395 = id_423;
                    if (while_flag_395) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_395);
                  (void)::dessser::VOID;
                  uint8_t id_424 { 0 };
                  Pointer id_425 { leb128_ptr_813[id_424] };
                  let_res_394 = id_425;
                }
                let_res_392 = let_res_394;
              }
              std::string id_426 { std::get<2 /* Versions */>((*p_0)) };
              Bytes id_427 { id_426 };
              Pointer id_428 { let_res_392.writeBytes(id_427) };
              choose_res_388 = id_428;
            } else {
              uint16_t id_429 { 3 };
              bool id_430 { bool(id_429 == label1_776) };
              Pointer choose_res_431;
              if (id_430) {
                auto fun432 { dessser::gen::src_path::to_row_binary };
                ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_433 { std::get<3 /* Sources */>((*p_0)) };
                dessser::gen::src_path::t_ext id_434 { std::get<0>(id_433) };
                Pointer id_435 { fun432(id_434, ssum_dst_777) };
                Pointer let_res_436;
                {
                  Pointer stup_dst_809 { id_435 };
                  ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_437 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_438 { std::get<1>(id_437) };
                  uint32_t id_439 { (uint32_t)id_438.size() };
                  Vec<1, uint32_t> id_440 {  id_439  };
                  Pointer let_res_441;
                  {
                    Vec<1, uint32_t> leb128_sz_810 { id_440 };
                    Vec<1, Pointer> id_442 {  stup_dst_809  };
                    Pointer let_res_443;
                    {
                      Vec<1, Pointer> leb128_ptr_811 { id_442 };
                      bool while_flag_444 { true };
                      do {
                        uint8_t id_445 { 0 };
                        uint8_t id_446 { 0 };
                        Pointer id_447 { leb128_ptr_811[id_446] };
                        uint32_t id_448 { 128U };
                        uint8_t id_449 { 0 };
                        uint32_t id_450 { leb128_sz_810[id_449] };
                        bool id_451 { bool(id_448 > id_450) };
                        uint8_t choose_res_452;
                        if (id_451) {
                          uint8_t id_453 { 0 };
                          uint32_t id_454 { leb128_sz_810[id_453] };
                          uint8_t id_455 { uint8_t(id_454) };
                          choose_res_452 = id_455;
                        } else {
                          uint8_t id_456 { 0 };
                          uint32_t id_457 { leb128_sz_810[id_456] };
                          uint8_t id_458 { uint8_t(id_457) };
                          uint8_t id_459 { 128 };
                          uint8_t id_460 { uint8_t(id_458 | id_459) };
                          choose_res_452 = id_460;
                        }
                        Pointer id_461 { id_447.writeU8(choose_res_452) };
                        Void id_462 { ((void)(leb128_ptr_811[id_445] = id_461), ::dessser::VOID) };
                        (void)id_462;
                        uint8_t id_463 { 0 };
                        uint8_t id_464 { 0 };
                        uint32_t id_465 { leb128_sz_810[id_464] };
                        uint8_t id_466 { 7 };
                        uint32_t id_467 { uint32_t(id_465 >> id_466) };
                        Void id_468 { ((void)(leb128_sz_810[id_463] = id_467), ::dessser::VOID) };
                        (void)id_468;
                        uint8_t id_469 { 0 };
                        uint32_t id_470 { leb128_sz_810[id_469] };
                        uint32_t id_471 { 0U };
                        bool id_472 { bool(id_470 > id_471) };
                        while_flag_444 = id_472;
                        if (while_flag_444) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_444);
                      (void)::dessser::VOID;
                      uint8_t id_473 { 0 };
                      Pointer id_474 { leb128_ptr_811[id_473] };
                      let_res_443 = id_474;
                    }
                    let_res_441 = let_res_443;
                  }
                  ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_475 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_476 { std::get<1>(id_475) };
                  Bytes id_477 { id_476 };
                  Pointer id_478 { let_res_441.writeBytes(id_477) };
                  let_res_436 = id_478;
                }
                choose_res_431 = let_res_436;
              } else {
                uint16_t id_479 { 4 };
                bool id_480 { bool(id_479 == label1_776) };
                Pointer choose_res_481;
                if (id_480) {
                  choose_res_481 = ssum_dst_777;
                } else {
                  uint16_t id_482 { 5 };
                  bool id_483 { bool(id_482 == label1_776) };
                  Pointer choose_res_484;
                  if (id_483) {
                    std::shared_ptr<::dessser::gen::sync_key::per_site>  id_485 { std::get<5 /* PerSite */>((*p_0)) };
                    Pointer id_486 { per_site_to_row_binary(id_485, ssum_dst_777) };
                    choose_res_484 = id_486;
                  } else {
                    uint16_t id_487 { 6 };
                    bool id_488 { bool(id_487 == label1_776) };
                    Pointer choose_res_489;
                    if (id_488) {
                      ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_490 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_491 { uint16_t(id_490.index()) };
                      Pointer id_492 { ssum_dst_777.writeU16Le(id_491) };
                      Pointer let_res_493;
                      {
                        Pointer ssum_dst_806 { id_492 };
                        uint16_t id_494 { 0 };
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_495 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_496 { uint16_t(id_495.index()) };
                        bool id_497 { bool(id_494 == id_496) };
                        Pointer choose_res_498;
                        if (id_497) {
                          choose_res_498 = ssum_dst_806;
                        } else {
                          uint16_t id_499 { 1 };
                          ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_500 { std::get<6 /* Storage */>((*p_0)) };
                          uint16_t id_501 { uint16_t(id_500.index()) };
                          bool id_502 { bool(id_499 == id_501) };
                          Pointer choose_res_503;
                          if (id_502) {
                            choose_res_503 = ssum_dst_806;
                          } else {
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_504 { std::get<6 /* Storage */>((*p_0)) };
                            uint16_t id_505 { uint16_t(id_504.index()) };
                            uint16_t id_506 { 2 };
                            bool id_507 { bool(id_505 == id_506) };
                            Void id_508 { ((void)(assert(id_507)), ::dessser::VOID) };
                            (void)id_508;
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_509 { std::get<6 /* Storage */>((*p_0)) };
                            std::string id_510 { std::get<2 /* RetentionsOverride */>(id_509) };
                            uint32_t id_511 { (uint32_t)id_510.size() };
                            Vec<1, uint32_t> id_512 {  id_511  };
                            Pointer let_res_513;
                            {
                              Vec<1, uint32_t> leb128_sz_807 { id_512 };
                              Vec<1, Pointer> id_514 {  ssum_dst_806  };
                              Pointer let_res_515;
                              {
                                Vec<1, Pointer> leb128_ptr_808 { id_514 };
                                bool while_flag_516 { true };
                                do {
                                  uint8_t id_517 { 0 };
                                  uint8_t id_518 { 0 };
                                  Pointer id_519 { leb128_ptr_808[id_518] };
                                  uint32_t id_520 { 128U };
                                  uint8_t id_521 { 0 };
                                  uint32_t id_522 { leb128_sz_807[id_521] };
                                  bool id_523 { bool(id_520 > id_522) };
                                  uint8_t choose_res_524;
                                  if (id_523) {
                                    uint8_t id_525 { 0 };
                                    uint32_t id_526 { leb128_sz_807[id_525] };
                                    uint8_t id_527 { uint8_t(id_526) };
                                    choose_res_524 = id_527;
                                  } else {
                                    uint8_t id_528 { 0 };
                                    uint32_t id_529 { leb128_sz_807[id_528] };
                                    uint8_t id_530 { uint8_t(id_529) };
                                    uint8_t id_531 { 128 };
                                    uint8_t id_532 { uint8_t(id_530 | id_531) };
                                    choose_res_524 = id_532;
                                  }
                                  Pointer id_533 { id_519.writeU8(choose_res_524) };
                                  Void id_534 { ((void)(leb128_ptr_808[id_517] = id_533), ::dessser::VOID) };
                                  (void)id_534;
                                  uint8_t id_535 { 0 };
                                  uint8_t id_536 { 0 };
                                  uint32_t id_537 { leb128_sz_807[id_536] };
                                  uint8_t id_538 { 7 };
                                  uint32_t id_539 { uint32_t(id_537 >> id_538) };
                                  Void id_540 { ((void)(leb128_sz_807[id_535] = id_539), ::dessser::VOID) };
                                  (void)id_540;
                                  uint8_t id_541 { 0 };
                                  uint32_t id_542 { leb128_sz_807[id_541] };
                                  uint32_t id_543 { 0U };
                                  bool id_544 { bool(id_542 > id_543) };
                                  while_flag_516 = id_544;
                                  if (while_flag_516) {
                                    (void)::dessser::VOID;
                                  }
                                } while (while_flag_516);
                                (void)::dessser::VOID;
                                uint8_t id_545 { 0 };
                                Pointer id_546 { leb128_ptr_808[id_545] };
                                let_res_515 = id_546;
                              }
                              let_res_513 = let_res_515;
                            }
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_547 { std::get<6 /* Storage */>((*p_0)) };
                            std::string id_548 { std::get<2 /* RetentionsOverride */>(id_547) };
                            Bytes id_549 { id_548 };
                            Pointer id_550 { let_res_513.writeBytes(id_549) };
                            choose_res_503 = id_550;
                          }
                          choose_res_498 = choose_res_503;
                        }
                        let_res_493 = choose_res_498;
                      }
                      choose_res_489 = let_res_493;
                    } else {
                      uint16_t id_551 { 7 };
                      bool id_552 { bool(id_551 == label1_776) };
                      Pointer choose_res_553;
                      if (id_552) {
                        auto fun554 { dessser::gen::site_name::to_row_binary };
                        ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_555 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::site_name::t_ext id_556 { std::get<0>(id_555) };
                        Pointer id_557 { fun554(id_556, ssum_dst_777) };
                        Pointer let_res_558;
                        {
                          Pointer stup_dst_800 { id_557 };
                          auto fun559 { dessser::gen::fq_name::to_row_binary };
                          ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_560 { std::get<7 /* Tails */>((*p_0)) };
                          dessser::gen::fq_name::t_ext id_561 { std::get<1>(id_560) };
                          Pointer id_562 { fun559(id_561, stup_dst_800) };
                          let_res_558 = id_562;
                        }
                        Pointer let_res_563;
                        {
                          Pointer stup_dst_801 { let_res_558 };
                          ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_564 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_565 { std::get<2>(id_564) };
                          uint32_t id_566 { (uint32_t)id_565.size() };
                          Vec<1, uint32_t> id_567 {  id_566  };
                          Pointer let_res_568;
                          {
                            Vec<1, uint32_t> leb128_sz_802 { id_567 };
                            Vec<1, Pointer> id_569 {  stup_dst_801  };
                            Pointer let_res_570;
                            {
                              Vec<1, Pointer> leb128_ptr_803 { id_569 };
                              bool while_flag_571 { true };
                              do {
                                uint8_t id_572 { 0 };
                                uint8_t id_573 { 0 };
                                Pointer id_574 { leb128_ptr_803[id_573] };
                                uint32_t id_575 { 128U };
                                uint8_t id_576 { 0 };
                                uint32_t id_577 { leb128_sz_802[id_576] };
                                bool id_578 { bool(id_575 > id_577) };
                                uint8_t choose_res_579;
                                if (id_578) {
                                  uint8_t id_580 { 0 };
                                  uint32_t id_581 { leb128_sz_802[id_580] };
                                  uint8_t id_582 { uint8_t(id_581) };
                                  choose_res_579 = id_582;
                                } else {
                                  uint8_t id_583 { 0 };
                                  uint32_t id_584 { leb128_sz_802[id_583] };
                                  uint8_t id_585 { uint8_t(id_584) };
                                  uint8_t id_586 { 128 };
                                  uint8_t id_587 { uint8_t(id_585 | id_586) };
                                  choose_res_579 = id_587;
                                }
                                Pointer id_588 { id_574.writeU8(choose_res_579) };
                                Void id_589 { ((void)(leb128_ptr_803[id_572] = id_588), ::dessser::VOID) };
                                (void)id_589;
                                uint8_t id_590 { 0 };
                                uint8_t id_591 { 0 };
                                uint32_t id_592 { leb128_sz_802[id_591] };
                                uint8_t id_593 { 7 };
                                uint32_t id_594 { uint32_t(id_592 >> id_593) };
                                Void id_595 { ((void)(leb128_sz_802[id_590] = id_594), ::dessser::VOID) };
                                (void)id_595;
                                uint8_t id_596 { 0 };
                                uint32_t id_597 { leb128_sz_802[id_596] };
                                uint32_t id_598 { 0U };
                                bool id_599 { bool(id_597 > id_598) };
                                while_flag_571 = id_599;
                                if (while_flag_571) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_571);
                              (void)::dessser::VOID;
                              uint8_t id_600 { 0 };
                              Pointer id_601 { leb128_ptr_803[id_600] };
                              let_res_570 = id_601;
                            }
                            let_res_568 = let_res_570;
                          }
                          ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_602 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_603 { std::get<2>(id_602) };
                          Bytes id_604 { id_603 };
                          Pointer id_605 { let_res_568.writeBytes(id_604) };
                          let_res_563 = id_605;
                        }
                        Pointer let_res_606;
                        {
                          Pointer stup_dst_804 { let_res_563 };
                          ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_607 { std::get<7 /* Tails */>((*p_0)) };
                          std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_608 { std::get<3>(id_607) };
                          Pointer id_609 { per_tail_to_row_binary(id_608, stup_dst_804) };
                          let_res_606 = id_609;
                        }
                        choose_res_553 = let_res_606;
                      } else {
                        uint16_t id_610 { 8 };
                        bool id_611 { bool(id_610 == label1_776) };
                        Pointer choose_res_612;
                        if (id_611) {
                          uint16_t id_613 { std::get<8 /* Replays */>((*p_0)) };
                          Pointer id_614 { ssum_dst_777.writeU16Le(id_613) };
                          choose_res_612 = id_614;
                        } else {
                          uint16_t id_615 { 9 };
                          bool id_616 { bool(id_615 == label1_776) };
                          Pointer choose_res_617;
                          if (id_616) {
                            std::optional<dessser::gen::sync_socket::t_ext> id_618 { std::get<9 /* Error */>((*p_0)) };
                            bool id_619 { !(id_618.has_value ()) };
                            Pointer choose_res_620;
                            if (id_619) {
                              uint8_t id_621 { 1 };
                              Pointer id_622 { ssum_dst_777.writeU8(id_621) };
                              choose_res_620 = id_622;
                            } else {
                              auto fun623 { dessser::gen::sync_socket::to_row_binary };
                              std::optional<dessser::gen::sync_socket::t_ext> id_624 { std::get<9 /* Error */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_625 { id_624.value() };
                              uint8_t id_626 { 0 };
                              Pointer id_627 { ssum_dst_777.writeU8(id_626) };
                              Pointer id_628 { fun623(id_625, id_627) };
                              choose_res_620 = id_628;
                            }
                            choose_res_617 = choose_res_620;
                          } else {
                            uint16_t id_629 { 10 };
                            bool id_630 { bool(id_629 == label1_776) };
                            Pointer choose_res_631;
                            if (id_630) {
                              choose_res_631 = ssum_dst_777;
                            } else {
                              uint16_t id_632 { 11 };
                              bool id_633 { bool(id_632 == label1_776) };
                              Pointer choose_res_634;
                              if (id_633) {
                                auto fun635 { dessser::gen::sync_socket::to_row_binary };
                                ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef id_636 { std::get<11 /* PerClient */>((*p_0)) };
                                dessser::gen::sync_socket::t_ext id_637 { std::get<0>(id_636) };
                                Pointer id_638 { fun635(id_637, ssum_dst_777) };
                                Pointer let_res_639;
                                {
                                  Pointer stup_dst_799 { id_638 };
                                  ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef id_640 { std::get<11 /* PerClient */>((*p_0)) };
                                  std::shared_ptr<::dessser::gen::sync_key::per_client>  id_641 { std::get<1>(id_640) };
                                  Pointer id_642 { per_client_to_row_binary(id_641, stup_dst_799) };
                                  let_res_639 = id_642;
                                }
                                choose_res_634 = let_res_639;
                              } else {
                                uint16_t id_643 { 12 };
                                bool id_644 { bool(id_643 == label1_776) };
                                Pointer choose_res_645;
                                if (id_644) {
                                  ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_646 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_647 { std::get<0>(id_646) };
                                  uint32_t id_648 { (uint32_t)id_647.size() };
                                  Vec<1, uint32_t> id_649 {  id_648  };
                                  Pointer let_res_650;
                                  {
                                    Vec<1, uint32_t> leb128_sz_796 { id_649 };
                                    Vec<1, Pointer> id_651 {  ssum_dst_777  };
                                    Pointer let_res_652;
                                    {
                                      Vec<1, Pointer> leb128_ptr_797 { id_651 };
                                      bool while_flag_653 { true };
                                      do {
                                        uint8_t id_654 { 0 };
                                        uint8_t id_655 { 0 };
                                        Pointer id_656 { leb128_ptr_797[id_655] };
                                        uint32_t id_657 { 128U };
                                        uint8_t id_658 { 0 };
                                        uint32_t id_659 { leb128_sz_796[id_658] };
                                        bool id_660 { bool(id_657 > id_659) };
                                        uint8_t choose_res_661;
                                        if (id_660) {
                                          uint8_t id_662 { 0 };
                                          uint32_t id_663 { leb128_sz_796[id_662] };
                                          uint8_t id_664 { uint8_t(id_663) };
                                          choose_res_661 = id_664;
                                        } else {
                                          uint8_t id_665 { 0 };
                                          uint32_t id_666 { leb128_sz_796[id_665] };
                                          uint8_t id_667 { uint8_t(id_666) };
                                          uint8_t id_668 { 128 };
                                          uint8_t id_669 { uint8_t(id_667 | id_668) };
                                          choose_res_661 = id_669;
                                        }
                                        Pointer id_670 { id_656.writeU8(choose_res_661) };
                                        Void id_671 { ((void)(leb128_ptr_797[id_654] = id_670), ::dessser::VOID) };
                                        (void)id_671;
                                        uint8_t id_672 { 0 };
                                        uint8_t id_673 { 0 };
                                        uint32_t id_674 { leb128_sz_796[id_673] };
                                        uint8_t id_675 { 7 };
                                        uint32_t id_676 { uint32_t(id_674 >> id_675) };
                                        Void id_677 { ((void)(leb128_sz_796[id_672] = id_676), ::dessser::VOID) };
                                        (void)id_677;
                                        uint8_t id_678 { 0 };
                                        uint32_t id_679 { leb128_sz_796[id_678] };
                                        uint32_t id_680 { 0U };
                                        bool id_681 { bool(id_679 > id_680) };
                                        while_flag_653 = id_681;
                                        if (while_flag_653) {
                                          (void)::dessser::VOID;
                                        }
                                      } while (while_flag_653);
                                      (void)::dessser::VOID;
                                      uint8_t id_682 { 0 };
                                      Pointer id_683 { leb128_ptr_797[id_682] };
                                      let_res_652 = id_683;
                                    }
                                    let_res_650 = let_res_652;
                                  }
                                  ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_684 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_685 { std::get<0>(id_684) };
                                  Bytes id_686 { id_685 };
                                  Pointer id_687 { let_res_650.writeBytes(id_686) };
                                  Pointer let_res_688;
                                  {
                                    Pointer stup_dst_798 { id_687 };
                                    ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_689 { std::get<12 /* Dashboards */>((*p_0)) };
                                    std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_690 { std::get<1>(id_689) };
                                    Pointer id_691 { per_dash_key_to_row_binary(id_690, stup_dst_798) };
                                    let_res_688 = id_691;
                                  }
                                  choose_res_645 = let_res_688;
                                } else {
                                  uint16_t id_692 { 13 };
                                  bool id_693 { bool(id_692 == label1_776) };
                                  Pointer choose_res_694;
                                  if (id_693) {
                                    choose_res_694 = ssum_dst_777;
                                  } else {
                                    uint16_t id_695 { 14 };
                                    bool id_696 { bool(id_695 == label1_776) };
                                    Pointer choose_res_697;
                                    if (id_696) {
                                      auto fun698 { dessser::gen::team_name::to_row_binary };
                                      ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_699 { std::get<14 /* Teams */>((*p_0)) };
                                      dessser::gen::team_name::t_ext id_700 { std::get<0>(id_699) };
                                      Pointer id_701 { fun698(id_700, ssum_dst_777) };
                                      Pointer let_res_702;
                                      {
                                        Pointer stup_dst_789 { id_701 };
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_703 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_704 { std::get<1>(id_703) };
                                        uint16_t id_705 { uint16_t(id_704.index()) };
                                        Pointer id_706 { stup_dst_789.writeU16Le(id_705) };
                                        Pointer let_res_707;
                                        {
                                          Pointer ssum_dst_791 { id_706 };
                                          uint16_t id_708 { 0 };
                                          ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_709 { std::get<14 /* Teams */>((*p_0)) };
                                          ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_710 { std::get<1>(id_709) };
                                          uint16_t id_711 { uint16_t(id_710.index()) };
                                          bool id_712 { bool(id_708 == id_711) };
                                          Pointer choose_res_713;
                                          if (id_712) {
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_714 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_715 { std::get<1>(id_714) };
                                            std::string id_716 { std::get<0 /* Contacts */>(id_715) };
                                            uint32_t id_717 { (uint32_t)id_716.size() };
                                            Vec<1, uint32_t> id_718 {  id_717  };
                                            Pointer let_res_719;
                                            {
                                              Vec<1, uint32_t> leb128_sz_794 { id_718 };
                                              Vec<1, Pointer> id_720 {  ssum_dst_791  };
                                              Pointer let_res_721;
                                              {
                                                Vec<1, Pointer> leb128_ptr_795 { id_720 };
                                                bool while_flag_722 { true };
                                                do {
                                                  uint8_t id_723 { 0 };
                                                  uint8_t id_724 { 0 };
                                                  Pointer id_725 { leb128_ptr_795[id_724] };
                                                  uint32_t id_726 { 128U };
                                                  uint8_t id_727 { 0 };
                                                  uint32_t id_728 { leb128_sz_794[id_727] };
                                                  bool id_729 { bool(id_726 > id_728) };
                                                  uint8_t choose_res_730;
                                                  if (id_729) {
                                                    uint8_t id_731 { 0 };
                                                    uint32_t id_732 { leb128_sz_794[id_731] };
                                                    uint8_t id_733 { uint8_t(id_732) };
                                                    choose_res_730 = id_733;
                                                  } else {
                                                    uint8_t id_734 { 0 };
                                                    uint32_t id_735 { leb128_sz_794[id_734] };
                                                    uint8_t id_736 { uint8_t(id_735) };
                                                    uint8_t id_737 { 128 };
                                                    uint8_t id_738 { uint8_t(id_736 | id_737) };
                                                    choose_res_730 = id_738;
                                                  }
                                                  Pointer id_739 { id_725.writeU8(choose_res_730) };
                                                  Void id_740 { ((void)(leb128_ptr_795[id_723] = id_739), ::dessser::VOID) };
                                                  (void)id_740;
                                                  uint8_t id_741 { 0 };
                                                  uint8_t id_742 { 0 };
                                                  uint32_t id_743 { leb128_sz_794[id_742] };
                                                  uint8_t id_744 { 7 };
                                                  uint32_t id_745 { uint32_t(id_743 >> id_744) };
                                                  Void id_746 { ((void)(leb128_sz_794[id_741] = id_745), ::dessser::VOID) };
                                                  (void)id_746;
                                                  uint8_t id_747 { 0 };
                                                  uint32_t id_748 { leb128_sz_794[id_747] };
                                                  uint32_t id_749 { 0U };
                                                  bool id_750 { bool(id_748 > id_749) };
                                                  while_flag_722 = id_750;
                                                  if (while_flag_722) {
                                                    (void)::dessser::VOID;
                                                  }
                                                } while (while_flag_722);
                                                (void)::dessser::VOID;
                                                uint8_t id_751 { 0 };
                                                Pointer id_752 { leb128_ptr_795[id_751] };
                                                let_res_721 = id_752;
                                              }
                                              let_res_719 = let_res_721;
                                            }
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_753 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_754 { std::get<1>(id_753) };
                                            std::string id_755 { std::get<0 /* Contacts */>(id_754) };
                                            Bytes id_756 { id_755 };
                                            Pointer id_757 { let_res_719.writeBytes(id_756) };
                                            choose_res_713 = id_757;
                                          } else {
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_758 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_759 { std::get<1>(id_758) };
                                            uint16_t id_760 { uint16_t(id_759.index()) };
                                            uint16_t id_761 { 1 };
                                            bool id_762 { bool(id_760 == id_761) };
                                            Void id_763 { ((void)(assert(id_762)), ::dessser::VOID) };
                                            (void)id_763;
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_764 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_765 { std::get<1>(id_764) };
                                            std::string id_766 { std::get<1 /* Inhibition */>(id_765) };
                                            uint32_t id_767 { (uint32_t)id_766.size() };
                                            Vec<1, uint32_t> id_768 {  id_767  };
                                            Pointer let_res_769;
                                            {
                                              Vec<1, uint32_t> leb128_sz_792 { id_768 };
                                              Vec<1, Pointer> id_770 {  ssum_dst_791  };
                                              Pointer let_res_771;
                                              {
                                                Vec<1, Pointer> leb128_ptr_793 { id_770 };
                                                bool while_flag_772 { true };
                                                do {
                                                  uint8_t id_773 { 0 };
                                                  uint8_t id_774 { 0 };
                                                  Pointer id_775 { leb128_ptr_793[id_774] };
                                                  uint32_t id_776 { 128U };
                                                  uint8_t id_777 { 0 };
                                                  uint32_t id_778 { leb128_sz_792[id_777] };
                                                  bool id_779 { bool(id_776 > id_778) };
                                                  uint8_t choose_res_780;
                                                  if (id_779) {
                                                    uint8_t id_781 { 0 };
                                                    uint32_t id_782 { leb128_sz_792[id_781] };
                                                    uint8_t id_783 { uint8_t(id_782) };
                                                    choose_res_780 = id_783;
                                                  } else {
                                                    uint8_t id_784 { 0 };
                                                    uint32_t id_785 { leb128_sz_792[id_784] };
                                                    uint8_t id_786 { uint8_t(id_785) };
                                                    uint8_t id_787 { 128 };
                                                    uint8_t id_788 { uint8_t(id_786 | id_787) };
                                                    choose_res_780 = id_788;
                                                  }
                                                  Pointer id_789 { id_775.writeU8(choose_res_780) };
                                                  Void id_790 { ((void)(leb128_ptr_793[id_773] = id_789), ::dessser::VOID) };
                                                  (void)id_790;
                                                  uint8_t id_791 { 0 };
                                                  uint8_t id_792 { 0 };
                                                  uint32_t id_793 { leb128_sz_792[id_792] };
                                                  uint8_t id_794 { 7 };
                                                  uint32_t id_795 { uint32_t(id_793 >> id_794) };
                                                  Void id_796 { ((void)(leb128_sz_792[id_791] = id_795), ::dessser::VOID) };
                                                  (void)id_796;
                                                  uint8_t id_797 { 0 };
                                                  uint32_t id_798 { leb128_sz_792[id_797] };
                                                  uint32_t id_799 { 0U };
                                                  bool id_800 { bool(id_798 > id_799) };
                                                  while_flag_772 = id_800;
                                                  if (while_flag_772) {
                                                    (void)::dessser::VOID;
                                                  }
                                                } while (while_flag_772);
                                                (void)::dessser::VOID;
                                                uint8_t id_801 { 0 };
                                                Pointer id_802 { leb128_ptr_793[id_801] };
                                                let_res_771 = id_802;
                                              }
                                              let_res_769 = let_res_771;
                                            }
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_803 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_804 { std::get<1>(id_803) };
                                            std::string id_805 { std::get<1 /* Inhibition */>(id_804) };
                                            Bytes id_806 { id_805 };
                                            Pointer id_807 { let_res_769.writeBytes(id_806) };
                                            choose_res_713 = id_807;
                                          }
                                          let_res_707 = choose_res_713;
                                        }
                                        let_res_702 = let_res_707;
                                      }
                                      choose_res_697 = let_res_702;
                                    } else {
                                      uint16_t id_808 { 15 };
                                      bool id_809 { bool(label1_776 == id_808) };
                                      Void id_810 { ((void)(assert(id_809)), ::dessser::VOID) };
                                      (void)id_810;
                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_811 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_812 { std::get<0>(id_811) };
                                      uint32_t id_813 { (uint32_t)id_812.size() };
                                      Vec<1, uint32_t> id_814 {  id_813  };
                                      Pointer let_res_815;
                                      {
                                        Vec<1, uint32_t> leb128_sz_778 { id_814 };
                                        Vec<1, Pointer> id_816 {  ssum_dst_777  };
                                        Pointer let_res_817;
                                        {
                                          Vec<1, Pointer> leb128_ptr_779 { id_816 };
                                          bool while_flag_818 { true };
                                          do {
                                            uint8_t id_819 { 0 };
                                            uint8_t id_820 { 0 };
                                            Pointer id_821 { leb128_ptr_779[id_820] };
                                            uint32_t id_822 { 128U };
                                            uint8_t id_823 { 0 };
                                            uint32_t id_824 { leb128_sz_778[id_823] };
                                            bool id_825 { bool(id_822 > id_824) };
                                            uint8_t choose_res_826;
                                            if (id_825) {
                                              uint8_t id_827 { 0 };
                                              uint32_t id_828 { leb128_sz_778[id_827] };
                                              uint8_t id_829 { uint8_t(id_828) };
                                              choose_res_826 = id_829;
                                            } else {
                                              uint8_t id_830 { 0 };
                                              uint32_t id_831 { leb128_sz_778[id_830] };
                                              uint8_t id_832 { uint8_t(id_831) };
                                              uint8_t id_833 { 128 };
                                              uint8_t id_834 { uint8_t(id_832 | id_833) };
                                              choose_res_826 = id_834;
                                            }
                                            Pointer id_835 { id_821.writeU8(choose_res_826) };
                                            Void id_836 { ((void)(leb128_ptr_779[id_819] = id_835), ::dessser::VOID) };
                                            (void)id_836;
                                            uint8_t id_837 { 0 };
                                            uint8_t id_838 { 0 };
                                            uint32_t id_839 { leb128_sz_778[id_838] };
                                            uint8_t id_840 { 7 };
                                            uint32_t id_841 { uint32_t(id_839 >> id_840) };
                                            Void id_842 { ((void)(leb128_sz_778[id_837] = id_841), ::dessser::VOID) };
                                            (void)id_842;
                                            uint8_t id_843 { 0 };
                                            uint32_t id_844 { leb128_sz_778[id_843] };
                                            uint32_t id_845 { 0U };
                                            bool id_846 { bool(id_844 > id_845) };
                                            while_flag_818 = id_846;
                                            if (while_flag_818) {
                                              (void)::dessser::VOID;
                                            }
                                          } while (while_flag_818);
                                          (void)::dessser::VOID;
                                          uint8_t id_847 { 0 };
                                          Pointer id_848 { leb128_ptr_779[id_847] };
                                          let_res_817 = id_848;
                                        }
                                        let_res_815 = let_res_817;
                                      }
                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_849 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_850 { std::get<0>(id_849) };
                                      Bytes id_851 { id_850 };
                                      Pointer id_852 { let_res_815.writeBytes(id_851) };
                                      Pointer let_res_853;
                                      {
                                        Pointer stup_dst_780 { id_852 };
                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_854 { std::get<15 /* Incidents */>((*p_0)) };
                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_855 { std::get<1>(id_854) };
                                        uint16_t id_856 { uint16_t(id_855.index()) };
                                        Pointer let_res_857;
                                        {
                                          uint16_t label1_781 { id_856 };
                                          Pointer id_858 { stup_dst_780.writeU16Le(label1_781) };
                                          Pointer let_res_859;
                                          {
                                            Pointer ssum_dst_782 { id_858 };
                                            uint16_t id_860 { 0 };
                                            bool id_861 { bool(id_860 == label1_781) };
                                            Pointer choose_res_862;
                                            if (id_861) {
                                              choose_res_862 = ssum_dst_782;
                                            } else {
                                              uint16_t id_863 { 1 };
                                              bool id_864 { bool(id_863 == label1_781) };
                                              Pointer choose_res_865;
                                              if (id_864) {
                                                choose_res_865 = ssum_dst_782;
                                              } else {
                                                uint16_t id_866 { 2 };
                                                bool id_867 { bool(id_866 == label1_781) };
                                                Pointer choose_res_868;
                                                if (id_867) {
                                                  choose_res_868 = ssum_dst_782;
                                                } else {
                                                  uint16_t id_869 { 3 };
                                                  bool id_870 { bool(id_869 == label1_781) };
                                                  Pointer choose_res_871;
                                                  if (id_870) {
                                                    choose_res_871 = ssum_dst_782;
                                                  } else {
                                                    uint16_t id_872 { 4 };
                                                    bool id_873 { bool(id_872 == label1_781) };
                                                    Pointer choose_res_874;
                                                    if (id_873) {
                                                      choose_res_874 = ssum_dst_782;
                                                    } else {
                                                      uint16_t id_875 { 5 };
                                                      bool id_876 { bool(id_875 == label1_781) };
                                                      Pointer choose_res_877;
                                                      if (id_876) {
                                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_878 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_879 { std::get<1>(id_878) };
                                                        ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_880 { std::get<5 /* Dialogs */>(id_879) };
                                                        std::string id_881 { std::get<0>(id_880) };
                                                        uint32_t id_882 { (uint32_t)id_881.size() };
                                                        Vec<1, uint32_t> id_883 {  id_882  };
                                                        Pointer let_res_884;
                                                        {
                                                          Vec<1, uint32_t> leb128_sz_784 { id_883 };
                                                          Vec<1, Pointer> id_885 {  ssum_dst_782  };
                                                          Pointer let_res_886;
                                                          {
                                                            Vec<1, Pointer> leb128_ptr_785 { id_885 };
                                                            bool while_flag_887 { true };
                                                            do {
                                                              uint8_t id_888 { 0 };
                                                              uint8_t id_889 { 0 };
                                                              Pointer id_890 { leb128_ptr_785[id_889] };
                                                              uint32_t id_891 { 128U };
                                                              uint8_t id_892 { 0 };
                                                              uint32_t id_893 { leb128_sz_784[id_892] };
                                                              bool id_894 { bool(id_891 > id_893) };
                                                              uint8_t choose_res_895;
                                                              if (id_894) {
                                                                uint8_t id_896 { 0 };
                                                                uint32_t id_897 { leb128_sz_784[id_896] };
                                                                uint8_t id_898 { uint8_t(id_897) };
                                                                choose_res_895 = id_898;
                                                              } else {
                                                                uint8_t id_899 { 0 };
                                                                uint32_t id_900 { leb128_sz_784[id_899] };
                                                                uint8_t id_901 { uint8_t(id_900) };
                                                                uint8_t id_902 { 128 };
                                                                uint8_t id_903 { uint8_t(id_901 | id_902) };
                                                                choose_res_895 = id_903;
                                                              }
                                                              Pointer id_904 { id_890.writeU8(choose_res_895) };
                                                              Void id_905 { ((void)(leb128_ptr_785[id_888] = id_904), ::dessser::VOID) };
                                                              (void)id_905;
                                                              uint8_t id_906 { 0 };
                                                              uint8_t id_907 { 0 };
                                                              uint32_t id_908 { leb128_sz_784[id_907] };
                                                              uint8_t id_909 { 7 };
                                                              uint32_t id_910 { uint32_t(id_908 >> id_909) };
                                                              Void id_911 { ((void)(leb128_sz_784[id_906] = id_910), ::dessser::VOID) };
                                                              (void)id_911;
                                                              uint8_t id_912 { 0 };
                                                              uint32_t id_913 { leb128_sz_784[id_912] };
                                                              uint32_t id_914 { 0U };
                                                              bool id_915 { bool(id_913 > id_914) };
                                                              while_flag_887 = id_915;
                                                              if (while_flag_887) {
                                                                (void)::dessser::VOID;
                                                              }
                                                            } while (while_flag_887);
                                                            (void)::dessser::VOID;
                                                            uint8_t id_916 { 0 };
                                                            Pointer id_917 { leb128_ptr_785[id_916] };
                                                            let_res_886 = id_917;
                                                          }
                                                          let_res_884 = let_res_886;
                                                        }
                                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_918 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_919 { std::get<1>(id_918) };
                                                        ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_920 { std::get<5 /* Dialogs */>(id_919) };
                                                        std::string id_921 { std::get<0>(id_920) };
                                                        Bytes id_922 { id_921 };
                                                        Pointer id_923 { let_res_884.writeBytes(id_922) };
                                                        Pointer let_res_924;
                                                        {
                                                          Pointer stup_dst_786 { id_923 };
                                                          ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_925 { std::get<15 /* Incidents */>((*p_0)) };
                                                          ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_926 { std::get<1>(id_925) };
                                                          ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_927 { std::get<5 /* Dialogs */>(id_926) };
                                                          ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_928 { std::get<1>(id_927) };
                                                          uint16_t id_929 { uint16_t(id_928.index()) };
                                                          Pointer let_res_930;
                                                          {
                                                            uint16_t label1_787 { id_929 };
                                                            Pointer id_931 { stup_dst_786.writeU16Le(label1_787) };
                                                            Pointer let_res_932;
                                                            {
                                                              Pointer ssum_dst_788 { id_931 };
                                                              uint16_t id_933 { 0 };
                                                              bool id_934 { bool(id_933 == label1_787) };
                                                              Pointer choose_res_935;
                                                              if (id_934) {
                                                                choose_res_935 = ssum_dst_788;
                                                              } else {
                                                                uint16_t id_936 { 1 };
                                                                bool id_937 { bool(id_936 == label1_787) };
                                                                Pointer choose_res_938;
                                                                if (id_937) {
                                                                  choose_res_938 = ssum_dst_788;
                                                                } else {
                                                                  uint16_t id_939 { 2 };
                                                                  bool id_940 { bool(id_939 == label1_787) };
                                                                  Pointer choose_res_941;
                                                                  if (id_940) {
                                                                    choose_res_941 = ssum_dst_788;
                                                                  } else {
                                                                    uint16_t id_942 { 3 };
                                                                    bool id_943 { bool(id_942 == label1_787) };
                                                                    Pointer choose_res_944;
                                                                    if (id_943) {
                                                                      choose_res_944 = ssum_dst_788;
                                                                    } else {
                                                                      uint16_t id_945 { 4 };
                                                                      bool id_946 { bool(id_945 == label1_787) };
                                                                      Pointer choose_res_947;
                                                                      if (id_946) {
                                                                        choose_res_947 = ssum_dst_788;
                                                                      } else {
                                                                        uint16_t id_948 { 5 };
                                                                        bool id_949 { bool(id_948 == label1_787) };
                                                                        Pointer choose_res_950;
                                                                        if (id_949) {
                                                                          choose_res_950 = ssum_dst_788;
                                                                        } else {
                                                                          uint16_t id_951 { 6 };
                                                                          bool id_952 { bool(label1_787 == id_951) };
                                                                          Void id_953 { ((void)(assert(id_952)), ::dessser::VOID) };
                                                                          (void)id_953;
                                                                          choose_res_950 = ssum_dst_788;
                                                                        }
                                                                        choose_res_947 = choose_res_950;
                                                                      }
                                                                      choose_res_944 = choose_res_947;
                                                                    }
                                                                    choose_res_941 = choose_res_944;
                                                                  }
                                                                  choose_res_938 = choose_res_941;
                                                                }
                                                                choose_res_935 = choose_res_938;
                                                              }
                                                              let_res_932 = choose_res_935;
                                                            }
                                                            let_res_930 = let_res_932;
                                                          }
                                                          let_res_924 = let_res_930;
                                                        }
                                                        choose_res_877 = let_res_924;
                                                      } else {
                                                        uint16_t id_954 { 6 };
                                                        bool id_955 { bool(label1_781 == id_954) };
                                                        Void id_956 { ((void)(assert(id_955)), ::dessser::VOID) };
                                                        (void)id_956;
                                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_957 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_958 { std::get<1>(id_957) };
                                                        ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 id_959 { std::get<6 /* Journal */>(id_958) };
                                                        double id_960 { std::get<0>(id_959) };
                                                        uint64_t id_961 { qword_of_float(id_960) };
                                                        Pointer id_962 { ssum_dst_782.writeU64Le(id_961) };
                                                        Pointer let_res_963;
                                                        {
                                                          Pointer stup_dst_783 { id_962 };
                                                          ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_964 { std::get<15 /* Incidents */>((*p_0)) };
                                                          ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_965 { std::get<1>(id_964) };
                                                          ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 id_966 { std::get<6 /* Journal */>(id_965) };
                                                          uint32_t id_967 { std::get<1>(id_966) };
                                                          Pointer id_968 { stup_dst_783.writeU32Le(id_967) };
                                                          let_res_963 = id_968;
                                                        }
                                                        choose_res_877 = let_res_963;
                                                      }
                                                      choose_res_874 = choose_res_877;
                                                    }
                                                    choose_res_871 = choose_res_874;
                                                  }
                                                  choose_res_868 = choose_res_871;
                                                }
                                                choose_res_865 = choose_res_868;
                                              }
                                              choose_res_862 = choose_res_865;
                                            }
                                            let_res_859 = choose_res_862;
                                          }
                                          let_res_857 = let_res_859;
                                        }
                                        let_res_853 = let_res_857;
                                      }
                                      choose_res_697 = let_res_853;
                                    }
                                    choose_res_694 = choose_res_697;
                                  }
                                  choose_res_645 = choose_res_694;
                                }
                                choose_res_634 = choose_res_645;
                              }
                              choose_res_631 = choose_res_634;
                            }
                            choose_res_617 = choose_res_631;
                          }
                          choose_res_612 = choose_res_617;
                        }
                        choose_res_553 = choose_res_612;
                      }
                      choose_res_489 = choose_res_553;
                    }
                    choose_res_484 = choose_res_489;
                  }
                  choose_res_481 = choose_res_484;
                }
                choose_res_431 = choose_res_481;
              }
              choose_res_388 = choose_res_431;
            }
            choose_res_385 = choose_res_388;
          }
          choose_res_382 = choose_res_385;
        }
        let_res_379 = choose_res_382;
      }
      let_res_377 = let_res_379;
    }
    return let_res_377;
  }
   };
  return fun375;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Widgets U32]") (seq (assert (eq (label-of (param 0)) (u16 0))) (size 6)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> per_dash_key_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> fun969 { [&fun969](std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  p_0) {
    uint16_t id_970 { uint16_t((*p_0).index()) };
    uint16_t id_971 { 0 };
    bool id_972 { bool(id_970 == id_971) };
    Void id_973 { ((void)(assert(id_972)), ::dessser::VOID) };
    (void)id_973;
    Size id_974 { 6UL };
    return id_974;
  }
   };
  return fun969;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> per_dash_key_sersize_of_row_binary(per_dash_key_sersize_of_row_binary_init());

/* 
    (fun ("[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_693" (make-vec (string-length (get-alt "Response" (param 0))))
              (let "lebsz_ref_694" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_693")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_694")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_694") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_694")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_694")))))) 
            (size-of-u32 (string-length (get-alt "Response" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "per_dash_key-sersize-of-row-binary") (get-alt "Scratchpad" (param 0)))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> per_client_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> fun975 { [&fun975](std::shared_ptr<::dessser::gen::sync_key::per_client>  p_0) {
    uint16_t id_976 { 0 };
    uint16_t id_977 { uint16_t((*p_0).index()) };
    bool id_978 { bool(id_976 == id_977) };
    Size choose_res_979;
    if (id_978) {
      Size id_980 { 2UL };
      std::string id_981 { std::get<0 /* Response */>((*p_0)) };
      uint32_t id_982 { (uint32_t)id_981.size() };
      Vec<1, uint32_t> id_983 {  id_982  };
      Size let_res_984;
      {
        Vec<1, uint32_t> n_ref_693 { id_983 };
        uint32_t id_985 { 1U };
        Vec<1, uint32_t> id_986 {  id_985  };
        Size let_res_987;
        {
          Vec<1, uint32_t> lebsz_ref_694 { id_986 };
          bool while_flag_988 { true };
          do {
            uint8_t id_989 { 0 };
            uint32_t id_990 { n_ref_693[id_989] };
            uint8_t id_991 { 0 };
            uint32_t id_992 { lebsz_ref_694[id_991] };
            uint8_t id_993 { 7 };
            uint32_t id_994 { uint32_t(id_992 << id_993) };
            bool id_995 { bool(id_990 >= id_994) };
            while_flag_988 = id_995;
            if (while_flag_988) {
              uint8_t id_996 { 0 };
              uint8_t id_997 { 0 };
              uint32_t id_998 { lebsz_ref_694[id_997] };
              uint32_t id_999 { 1U };
              uint32_t id_1000 { uint32_t(id_998 + id_999) };
              Void id_1001 { ((void)(lebsz_ref_694[id_996] = id_1000), ::dessser::VOID) };
              (void)id_1001;
            }
          } while (while_flag_988);
          (void)::dessser::VOID;
          uint8_t id_1002 { 0 };
          uint32_t id_1003 { lebsz_ref_694[id_1002] };
          Size id_1004 { Size(id_1003) };
          let_res_987 = id_1004;
        }
        let_res_984 = let_res_987;
      }
      std::string id_1005 { std::get<0 /* Response */>((*p_0)) };
      uint32_t id_1006 { (uint32_t)id_1005.size() };
      Size id_1007 { Size(id_1006) };
      Size id_1008 { Size(let_res_984 + id_1007) };
      Size id_1009 { Size(id_980 + id_1008) };
      choose_res_979 = id_1009;
    } else {
      uint16_t id_1010 { uint16_t((*p_0).index()) };
      uint16_t id_1011 { 1 };
      bool id_1012 { bool(id_1010 == id_1011) };
      Void id_1013 { ((void)(assert(id_1012)), ::dessser::VOID) };
      (void)id_1013;
      Size id_1014 { 2UL };
      std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1015 { std::get<1 /* Scratchpad */>((*p_0)) };
      Size id_1016 { per_dash_key_sersize_of_row_binary(id_1015) };
      Size id_1017 { Size(id_1014 + id_1016) };
      choose_res_979 = id_1017;
    }
    return choose_res_979;
  }
   };
  return fun975;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> per_client_sersize_of_row_binary(per_client_sersize_of_row_binary_init());

/* 
    (fun ("[Subscriber STRING | LastTuple U32]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_688" (make-vec (string-length (get-alt "Subscriber" (param 0))))
              (let "lebsz_ref_689" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_688")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_689")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_689") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_689")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_689")))))) 
            (size-of-u32 (string-length (get-alt "Subscriber" (param 0)))))) 
        (seq (assert (eq (label-of (param 0)) (u16 1))) (size 6))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> per_tail_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> fun1018 { [&fun1018](std::shared_ptr<::dessser::gen::sync_key::per_tail>  p_0) {
    uint16_t id_1019 { 0 };
    uint16_t id_1020 { uint16_t((*p_0).index()) };
    bool id_1021 { bool(id_1019 == id_1020) };
    Size choose_res_1022;
    if (id_1021) {
      Size id_1023 { 2UL };
      std::string id_1024 { std::get<0 /* Subscriber */>((*p_0)) };
      uint32_t id_1025 { (uint32_t)id_1024.size() };
      Vec<1, uint32_t> id_1026 {  id_1025  };
      Size let_res_1027;
      {
        Vec<1, uint32_t> n_ref_688 { id_1026 };
        uint32_t id_1028 { 1U };
        Vec<1, uint32_t> id_1029 {  id_1028  };
        Size let_res_1030;
        {
          Vec<1, uint32_t> lebsz_ref_689 { id_1029 };
          bool while_flag_1031 { true };
          do {
            uint8_t id_1032 { 0 };
            uint32_t id_1033 { n_ref_688[id_1032] };
            uint8_t id_1034 { 0 };
            uint32_t id_1035 { lebsz_ref_689[id_1034] };
            uint8_t id_1036 { 7 };
            uint32_t id_1037 { uint32_t(id_1035 << id_1036) };
            bool id_1038 { bool(id_1033 >= id_1037) };
            while_flag_1031 = id_1038;
            if (while_flag_1031) {
              uint8_t id_1039 { 0 };
              uint8_t id_1040 { 0 };
              uint32_t id_1041 { lebsz_ref_689[id_1040] };
              uint32_t id_1042 { 1U };
              uint32_t id_1043 { uint32_t(id_1041 + id_1042) };
              Void id_1044 { ((void)(lebsz_ref_689[id_1039] = id_1043), ::dessser::VOID) };
              (void)id_1044;
            }
          } while (while_flag_1031);
          (void)::dessser::VOID;
          uint8_t id_1045 { 0 };
          uint32_t id_1046 { lebsz_ref_689[id_1045] };
          Size id_1047 { Size(id_1046) };
          let_res_1030 = id_1047;
        }
        let_res_1027 = let_res_1030;
      }
      std::string id_1048 { std::get<0 /* Subscriber */>((*p_0)) };
      uint32_t id_1049 { (uint32_t)id_1048.size() };
      Size id_1050 { Size(id_1049) };
      Size id_1051 { Size(let_res_1027 + id_1050) };
      Size id_1052 { Size(id_1023 + id_1051) };
      choose_res_1022 = id_1052;
    } else {
      uint16_t id_1053 { uint16_t((*p_0).index()) };
      uint16_t id_1054 { 1 };
      bool id_1055 { bool(id_1053 == id_1054) };
      Void id_1056 { ((void)(assert(id_1055)), ::dessser::VOID) };
      (void)id_1056;
      Size id_1057 { 6UL };
      choose_res_1022 = id_1057;
    }
    return choose_res_1022;
  }
   };
  return fun1018;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> per_tail_sersize_of_row_binary(per_tail_sersize_of_row_binary_init());

/* 
    (fun ("[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0))) (size 2)
          (if (eq (u16 2) (label-of (param 0))) (size 2)
            (if (eq (u16 3) (label-of (param 0))) (size 2)
              (if (eq (u16 4) (label-of (param 0))) (size 2)
                (if (eq (u16 5) (label-of (param 0))) (size 2)
                  (if (eq (u16 6) (label-of (param 0)))
                    (let "sz_667"
                      (add (size 2)
                        (add
                          (let "n_ref_665" (make-vec (string-length (get-item 0 (get-alt "PerInstance" (param 0)))))
                            (let "lebsz_ref_666" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_665")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_666")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_666") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_666")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_666")))))) 
                          (size-of-u32 (string-length (get-item 0 (get-alt "PerInstance" (param 0)))))))
                      (let "label2_668" (label-of (get-item 1 (get-alt "PerInstance" (param 0))))
                        (if (eq (u16 0) (identifier "label2_668")) (add (identifier "sz_667") (size 2))
                          (if (eq (u16 1) (identifier "label2_668")) 
                            (add (identifier "sz_667") (size 2))
                            (if (eq (u16 2) (identifier "label2_668")) 
                              (add (identifier "sz_667") (size 2))
                              (if (eq (u16 3) (identifier "label2_668")) 
                                (add (identifier "sz_667") (size 2))
                                (if (eq (u16 4) (identifier "label2_668")) 
                                  (add (identifier "sz_667") (size 2))
                                  (if (eq (u16 5) (identifier "label2_668")) 
                                    (add (identifier "sz_667") (size 2))
                                    (if (eq (u16 6) (identifier "label2_668")) (add (identifier "sz_667") (size 2)) (seq (assert (eq (identifier "label2_668") (u16 7))) (add (identifier "sz_667") (size 2))))))))))))
                    (if (eq (u16 7) (label-of (param 0))) (size 6) (seq (assert (eq (label-of (param 0)) (u16 8))) (size 2)))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> )> per_worker_data_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> )> fun1058 { [&fun1058](std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  p_0) {
    uint16_t id_1059 { 0 };
    uint16_t id_1060 { uint16_t((*p_0).index()) };
    bool id_1061 { bool(id_1059 == id_1060) };
    Size choose_res_1062;
    if (id_1061) {
      Size id_1063 { 2UL };
      choose_res_1062 = id_1063;
    } else {
      uint16_t id_1064 { 1 };
      uint16_t id_1065 { uint16_t((*p_0).index()) };
      bool id_1066 { bool(id_1064 == id_1065) };
      Size choose_res_1067;
      if (id_1066) {
        Size id_1068 { 2UL };
        choose_res_1067 = id_1068;
      } else {
        uint16_t id_1069 { 2 };
        uint16_t id_1070 { uint16_t((*p_0).index()) };
        bool id_1071 { bool(id_1069 == id_1070) };
        Size choose_res_1072;
        if (id_1071) {
          Size id_1073 { 2UL };
          choose_res_1072 = id_1073;
        } else {
          uint16_t id_1074 { 3 };
          uint16_t id_1075 { uint16_t((*p_0).index()) };
          bool id_1076 { bool(id_1074 == id_1075) };
          Size choose_res_1077;
          if (id_1076) {
            Size id_1078 { 2UL };
            choose_res_1077 = id_1078;
          } else {
            uint16_t id_1079 { 4 };
            uint16_t id_1080 { uint16_t((*p_0).index()) };
            bool id_1081 { bool(id_1079 == id_1080) };
            Size choose_res_1082;
            if (id_1081) {
              Size id_1083 { 2UL };
              choose_res_1082 = id_1083;
            } else {
              uint16_t id_1084 { 5 };
              uint16_t id_1085 { uint16_t((*p_0).index()) };
              bool id_1086 { bool(id_1084 == id_1085) };
              Size choose_res_1087;
              if (id_1086) {
                Size id_1088 { 2UL };
                choose_res_1087 = id_1088;
              } else {
                uint16_t id_1089 { 6 };
                uint16_t id_1090 { uint16_t((*p_0).index()) };
                bool id_1091 { bool(id_1089 == id_1090) };
                Size choose_res_1092;
                if (id_1091) {
                  Size id_1093 { 2UL };
                  ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_1094 { std::get<6 /* PerInstance */>((*p_0)) };
                  std::string id_1095 { std::get<0>(id_1094) };
                  uint32_t id_1096 { (uint32_t)id_1095.size() };
                  Vec<1, uint32_t> id_1097 {  id_1096  };
                  Size let_res_1098;
                  {
                    Vec<1, uint32_t> n_ref_665 { id_1097 };
                    uint32_t id_1099 { 1U };
                    Vec<1, uint32_t> id_1100 {  id_1099  };
                    Size let_res_1101;
                    {
                      Vec<1, uint32_t> lebsz_ref_666 { id_1100 };
                      bool while_flag_1102 { true };
                      do {
                        uint8_t id_1103 { 0 };
                        uint32_t id_1104 { n_ref_665[id_1103] };
                        uint8_t id_1105 { 0 };
                        uint32_t id_1106 { lebsz_ref_666[id_1105] };
                        uint8_t id_1107 { 7 };
                        uint32_t id_1108 { uint32_t(id_1106 << id_1107) };
                        bool id_1109 { bool(id_1104 >= id_1108) };
                        while_flag_1102 = id_1109;
                        if (while_flag_1102) {
                          uint8_t id_1110 { 0 };
                          uint8_t id_1111 { 0 };
                          uint32_t id_1112 { lebsz_ref_666[id_1111] };
                          uint32_t id_1113 { 1U };
                          uint32_t id_1114 { uint32_t(id_1112 + id_1113) };
                          Void id_1115 { ((void)(lebsz_ref_666[id_1110] = id_1114), ::dessser::VOID) };
                          (void)id_1115;
                        }
                      } while (while_flag_1102);
                      (void)::dessser::VOID;
                      uint8_t id_1116 { 0 };
                      uint32_t id_1117 { lebsz_ref_666[id_1116] };
                      Size id_1118 { Size(id_1117) };
                      let_res_1101 = id_1118;
                    }
                    let_res_1098 = let_res_1101;
                  }
                  ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_1119 { std::get<6 /* PerInstance */>((*p_0)) };
                  std::string id_1120 { std::get<0>(id_1119) };
                  uint32_t id_1121 { (uint32_t)id_1120.size() };
                  Size id_1122 { Size(id_1121) };
                  Size id_1123 { Size(let_res_1098 + id_1122) };
                  Size id_1124 { Size(id_1093 + id_1123) };
                  Size let_res_1125;
                  {
                    Size sz_667 { id_1124 };
                    ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_1126 { std::get<6 /* PerInstance */>((*p_0)) };
                    ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_1127 { std::get<1>(id_1126) };
                    uint16_t id_1128 { uint16_t(id_1127.index()) };
                    Size let_res_1129;
                    {
                      uint16_t label2_668 { id_1128 };
                      uint16_t id_1130 { 0 };
                      bool id_1131 { bool(id_1130 == label2_668) };
                      Size choose_res_1132;
                      if (id_1131) {
                        Size id_1133 { 2UL };
                        Size id_1134 { Size(sz_667 + id_1133) };
                        choose_res_1132 = id_1134;
                      } else {
                        uint16_t id_1135 { 1 };
                        bool id_1136 { bool(id_1135 == label2_668) };
                        Size choose_res_1137;
                        if (id_1136) {
                          Size id_1138 { 2UL };
                          Size id_1139 { Size(sz_667 + id_1138) };
                          choose_res_1137 = id_1139;
                        } else {
                          uint16_t id_1140 { 2 };
                          bool id_1141 { bool(id_1140 == label2_668) };
                          Size choose_res_1142;
                          if (id_1141) {
                            Size id_1143 { 2UL };
                            Size id_1144 { Size(sz_667 + id_1143) };
                            choose_res_1142 = id_1144;
                          } else {
                            uint16_t id_1145 { 3 };
                            bool id_1146 { bool(id_1145 == label2_668) };
                            Size choose_res_1147;
                            if (id_1146) {
                              Size id_1148 { 2UL };
                              Size id_1149 { Size(sz_667 + id_1148) };
                              choose_res_1147 = id_1149;
                            } else {
                              uint16_t id_1150 { 4 };
                              bool id_1151 { bool(id_1150 == label2_668) };
                              Size choose_res_1152;
                              if (id_1151) {
                                Size id_1153 { 2UL };
                                Size id_1154 { Size(sz_667 + id_1153) };
                                choose_res_1152 = id_1154;
                              } else {
                                uint16_t id_1155 { 5 };
                                bool id_1156 { bool(id_1155 == label2_668) };
                                Size choose_res_1157;
                                if (id_1156) {
                                  Size id_1158 { 2UL };
                                  Size id_1159 { Size(sz_667 + id_1158) };
                                  choose_res_1157 = id_1159;
                                } else {
                                  uint16_t id_1160 { 6 };
                                  bool id_1161 { bool(id_1160 == label2_668) };
                                  Size choose_res_1162;
                                  if (id_1161) {
                                    Size id_1163 { 2UL };
                                    Size id_1164 { Size(sz_667 + id_1163) };
                                    choose_res_1162 = id_1164;
                                  } else {
                                    uint16_t id_1165 { 7 };
                                    bool id_1166 { bool(label2_668 == id_1165) };
                                    Void id_1167 { ((void)(assert(id_1166)), ::dessser::VOID) };
                                    (void)id_1167;
                                    Size id_1168 { 2UL };
                                    Size id_1169 { Size(sz_667 + id_1168) };
                                    choose_res_1162 = id_1169;
                                  }
                                  choose_res_1157 = choose_res_1162;
                                }
                                choose_res_1152 = choose_res_1157;
                              }
                              choose_res_1147 = choose_res_1152;
                            }
                            choose_res_1142 = choose_res_1147;
                          }
                          choose_res_1137 = choose_res_1142;
                        }
                        choose_res_1132 = choose_res_1137;
                      }
                      let_res_1129 = choose_res_1132;
                    }
                    let_res_1125 = let_res_1129;
                  }
                  choose_res_1092 = let_res_1125;
                } else {
                  uint16_t id_1170 { 7 };
                  uint16_t id_1171 { uint16_t((*p_0).index()) };
                  bool id_1172 { bool(id_1170 == id_1171) };
                  Size choose_res_1173;
                  if (id_1172) {
                    Size id_1174 { 6UL };
                    choose_res_1173 = id_1174;
                  } else {
                    uint16_t id_1175 { uint16_t((*p_0).index()) };
                    uint16_t id_1176 { 8 };
                    bool id_1177 { bool(id_1175 == id_1176) };
                    Void id_1178 { ((void)(assert(id_1177)), ::dessser::VOID) };
                    (void)id_1178;
                    Size id_1179 { 2UL };
                    choose_res_1173 = id_1179;
                  }
                  choose_res_1092 = choose_res_1173;
                }
                choose_res_1087 = choose_res_1092;
              }
              choose_res_1082 = choose_res_1087;
            }
            choose_res_1077 = choose_res_1082;
          }
          choose_res_1072 = choose_res_1077;
        }
        choose_res_1067 = choose_res_1072;
      }
      choose_res_1062 = choose_res_1067;
    }
    return choose_res_1062;
  }
   };
  return fun1058;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> )> per_worker_data_sersize_of_row_binary(per_worker_data_sersize_of_row_binary_init());

/* 
    (fun ("($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))")
      (let "sz_670" (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 0 (param 0))) (add (identifier "sz_670") (apply (identifier "per_worker_data-sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker> )> per_worker_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker> )> fun1180 { [&fun1180](std::shared_ptr<::dessser::gen::sync_key::per_worker>  p_0) {
    auto fun1181 { dessser::gen::fq_name::sersize_of_row_binary };
    dessser::gen::fq_name::t_ext id_1182 { std::get<0>((*p_0)) };
    Size id_1183 { fun1181(id_1182) };
    Size let_res_1184;
    {
      Size sz_670 { id_1183 };
      std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_1185 { std::get<1>((*p_0)) };
      Size id_1186 { per_worker_data_sersize_of_row_binary(id_1185) };
      Size id_1187 { Size(sz_670 + id_1186) };
      let_res_1184 = id_1187;
    }
    return let_res_1184;
  }
   };
  return fun1180;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker> )> per_worker_sersize_of_row_binary(per_worker_sersize_of_row_binary_init());

/* 
    (fun ("[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0)))
          (let "sz_682"
            (add (size 2)
              (add
                (let "n_ref_680" (make-vec (string-length (get-item 0 (get-alt "PerService" (param 0)))))
                  (let "lebsz_ref_681" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_680")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_681")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_681") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_681")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_681")))))) 
                (size-of-u32 (string-length (get-item 0 (get-alt "PerService" (param 0)))))))
            (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (param 0))))) 
              (add (identifier "sz_682") (size 2)) (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (param 0)))) (u16 1))) (add (identifier "sz_682") (size 2)))))
          (if (eq (u16 2) (label-of (param 0))) (add (size 2) (apply (identifier "per_worker-sersize-of-row-binary") (get-alt "PerWorker" (param 0))))
            (seq (assert (eq (label-of (param 0)) (u16 3)))
              (let "sz_676"
                (add (size 2)
                  (add
                    (let "n_ref_674" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (param 0)))))
                      (let "lebsz_ref_675" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_674")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_675")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_675") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_675")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_675")))))) 
                    (size-of-u32 (string-length (get-item 0 (get-alt "PerProgram" (param 0))))))) 
                (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (param 0)))) (u16 0))) (add (identifier "sz_676") (size 2)))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site_data> )> per_site_data_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site_data> )> fun1188 { [&fun1188](std::shared_ptr<::dessser::gen::sync_key::per_site_data>  p_0) {
    uint16_t id_1189 { 0 };
    uint16_t id_1190 { uint16_t((*p_0).index()) };
    bool id_1191 { bool(id_1189 == id_1190) };
    Size choose_res_1192;
    if (id_1191) {
      Size id_1193 { 2UL };
      choose_res_1192 = id_1193;
    } else {
      uint16_t id_1194 { 1 };
      uint16_t id_1195 { uint16_t((*p_0).index()) };
      bool id_1196 { bool(id_1194 == id_1195) };
      Size choose_res_1197;
      if (id_1196) {
        Size id_1198 { 2UL };
        ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1199 { std::get<1 /* PerService */>((*p_0)) };
        std::string id_1200 { std::get<0>(id_1199) };
        uint32_t id_1201 { (uint32_t)id_1200.size() };
        Vec<1, uint32_t> id_1202 {  id_1201  };
        Size let_res_1203;
        {
          Vec<1, uint32_t> n_ref_680 { id_1202 };
          uint32_t id_1204 { 1U };
          Vec<1, uint32_t> id_1205 {  id_1204  };
          Size let_res_1206;
          {
            Vec<1, uint32_t> lebsz_ref_681 { id_1205 };
            bool while_flag_1207 { true };
            do {
              uint8_t id_1208 { 0 };
              uint32_t id_1209 { n_ref_680[id_1208] };
              uint8_t id_1210 { 0 };
              uint32_t id_1211 { lebsz_ref_681[id_1210] };
              uint8_t id_1212 { 7 };
              uint32_t id_1213 { uint32_t(id_1211 << id_1212) };
              bool id_1214 { bool(id_1209 >= id_1213) };
              while_flag_1207 = id_1214;
              if (while_flag_1207) {
                uint8_t id_1215 { 0 };
                uint8_t id_1216 { 0 };
                uint32_t id_1217 { lebsz_ref_681[id_1216] };
                uint32_t id_1218 { 1U };
                uint32_t id_1219 { uint32_t(id_1217 + id_1218) };
                Void id_1220 { ((void)(lebsz_ref_681[id_1215] = id_1219), ::dessser::VOID) };
                (void)id_1220;
              }
            } while (while_flag_1207);
            (void)::dessser::VOID;
            uint8_t id_1221 { 0 };
            uint32_t id_1222 { lebsz_ref_681[id_1221] };
            Size id_1223 { Size(id_1222) };
            let_res_1206 = id_1223;
          }
          let_res_1203 = let_res_1206;
        }
        ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1224 { std::get<1 /* PerService */>((*p_0)) };
        std::string id_1225 { std::get<0>(id_1224) };
        uint32_t id_1226 { (uint32_t)id_1225.size() };
        Size id_1227 { Size(id_1226) };
        Size id_1228 { Size(let_res_1203 + id_1227) };
        Size id_1229 { Size(id_1198 + id_1228) };
        Size let_res_1230;
        {
          Size sz_682 { id_1229 };
          uint16_t id_1231 { 0 };
          ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1232 { std::get<1 /* PerService */>((*p_0)) };
          ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_1233 { std::get<1>(id_1232) };
          uint16_t id_1234 { uint16_t(id_1233.index()) };
          bool id_1235 { bool(id_1231 == id_1234) };
          Size choose_res_1236;
          if (id_1235) {
            Size id_1237 { 2UL };
            Size id_1238 { Size(sz_682 + id_1237) };
            choose_res_1236 = id_1238;
          } else {
            ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1239 { std::get<1 /* PerService */>((*p_0)) };
            ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_1240 { std::get<1>(id_1239) };
            uint16_t id_1241 { uint16_t(id_1240.index()) };
            uint16_t id_1242 { 1 };
            bool id_1243 { bool(id_1241 == id_1242) };
            Void id_1244 { ((void)(assert(id_1243)), ::dessser::VOID) };
            (void)id_1244;
            Size id_1245 { 2UL };
            Size id_1246 { Size(sz_682 + id_1245) };
            choose_res_1236 = id_1246;
          }
          let_res_1230 = choose_res_1236;
        }
        choose_res_1197 = let_res_1230;
      } else {
        uint16_t id_1247 { 2 };
        uint16_t id_1248 { uint16_t((*p_0).index()) };
        bool id_1249 { bool(id_1247 == id_1248) };
        Size choose_res_1250;
        if (id_1249) {
          Size id_1251 { 2UL };
          std::shared_ptr<::dessser::gen::sync_key::per_worker>  id_1252 { std::get<2 /* PerWorker */>((*p_0)) };
          Size id_1253 { per_worker_sersize_of_row_binary(id_1252) };
          Size id_1254 { Size(id_1251 + id_1253) };
          choose_res_1250 = id_1254;
        } else {
          uint16_t id_1255 { uint16_t((*p_0).index()) };
          uint16_t id_1256 { 3 };
          bool id_1257 { bool(id_1255 == id_1256) };
          Void id_1258 { ((void)(assert(id_1257)), ::dessser::VOID) };
          (void)id_1258;
          Size id_1259 { 2UL };
          ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_1260 { std::get<3 /* PerProgram */>((*p_0)) };
          std::string id_1261 { std::get<0>(id_1260) };
          uint32_t id_1262 { (uint32_t)id_1261.size() };
          Vec<1, uint32_t> id_1263 {  id_1262  };
          Size let_res_1264;
          {
            Vec<1, uint32_t> n_ref_674 { id_1263 };
            uint32_t id_1265 { 1U };
            Vec<1, uint32_t> id_1266 {  id_1265  };
            Size let_res_1267;
            {
              Vec<1, uint32_t> lebsz_ref_675 { id_1266 };
              bool while_flag_1268 { true };
              do {
                uint8_t id_1269 { 0 };
                uint32_t id_1270 { n_ref_674[id_1269] };
                uint8_t id_1271 { 0 };
                uint32_t id_1272 { lebsz_ref_675[id_1271] };
                uint8_t id_1273 { 7 };
                uint32_t id_1274 { uint32_t(id_1272 << id_1273) };
                bool id_1275 { bool(id_1270 >= id_1274) };
                while_flag_1268 = id_1275;
                if (while_flag_1268) {
                  uint8_t id_1276 { 0 };
                  uint8_t id_1277 { 0 };
                  uint32_t id_1278 { lebsz_ref_675[id_1277] };
                  uint32_t id_1279 { 1U };
                  uint32_t id_1280 { uint32_t(id_1278 + id_1279) };
                  Void id_1281 { ((void)(lebsz_ref_675[id_1276] = id_1280), ::dessser::VOID) };
                  (void)id_1281;
                }
              } while (while_flag_1268);
              (void)::dessser::VOID;
              uint8_t id_1282 { 0 };
              uint32_t id_1283 { lebsz_ref_675[id_1282] };
              Size id_1284 { Size(id_1283) };
              let_res_1267 = id_1284;
            }
            let_res_1264 = let_res_1267;
          }
          ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_1285 { std::get<3 /* PerProgram */>((*p_0)) };
          std::string id_1286 { std::get<0>(id_1285) };
          uint32_t id_1287 { (uint32_t)id_1286.size() };
          Size id_1288 { Size(id_1287) };
          Size id_1289 { Size(let_res_1264 + id_1288) };
          Size id_1290 { Size(id_1259 + id_1289) };
          Size let_res_1291;
          {
            Size sz_676 { id_1290 };
            ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_1292 { std::get<3 /* PerProgram */>((*p_0)) };
            ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_1293 { std::get<1>(id_1292) };
            uint16_t id_1294 { uint16_t(id_1293.index()) };
            uint16_t id_1295 { 0 };
            bool id_1296 { bool(id_1294 == id_1295) };
            Void id_1297 { ((void)(assert(id_1296)), ::dessser::VOID) };
            (void)id_1297;
            Size id_1298 { 2UL };
            Size id_1299 { Size(sz_676 + id_1298) };
            let_res_1291 = id_1299;
          }
          choose_res_1250 = let_res_1291;
        }
        choose_res_1197 = choose_res_1250;
      }
      choose_res_1192 = choose_res_1197;
    }
    return choose_res_1192;
  }
   };
  return fun1188;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site_data> )> per_site_data_sersize_of_row_binary(per_site_data_sersize_of_row_binary_init());

/* 
    (fun ("($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))")
      (let "sz_685" (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (param 0))) (add (identifier "sz_685") (apply (identifier "per_site_data-sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site> )> per_site_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site> )> fun1300 { [&fun1300](std::shared_ptr<::dessser::gen::sync_key::per_site>  p_0) {
    auto fun1301 { dessser::gen::site_name::sersize_of_row_binary };
    dessser::gen::site_name::t_ext id_1302 { std::get<0>((*p_0)) };
    Size id_1303 { fun1301(id_1302) };
    Size let_res_1304;
    {
      Size sz_685 { id_1303 };
      std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_1305 { std::get<1>((*p_0)) };
      Size id_1306 { per_site_data_sersize_of_row_binary(id_1305) };
      Size id_1307 { Size(sz_685 + id_1306) };
      let_res_1304 = id_1307;
    }
    return let_res_1304;
  }
   };
  return fun1300;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site> )> per_site_sersize_of_row_binary(per_site_sersize_of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]")
      (let "label2_695" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_695")) (size 2)
          (if (eq (u16 1) (identifier "label2_695")) (size 2)
            (if (eq (u16 2) (identifier "label2_695"))
              (add (size 2)
                (add
                  (let "n_ref_743" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "lebsz_ref_744" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_743")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_744")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_744") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_744")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_744")))))) 
                  (size-of-u32 (string-length (get-alt "Versions" (param 0))))))
              (if (eq (u16 3) (identifier "label2_695"))
                (let "sz_738" (add (size 2) (apply (ext-identifier src_path sersize-of-row-binary) (get-item 0 (get-alt "Sources" (param 0)))))
                  (add (identifier "sz_738")
                    (add
                      (let "n_ref_740" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "lebsz_ref_741" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_740")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_741")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_741") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_741")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_741")))))) 
                      (size-of-u32 (string-length (get-item 1 (get-alt "Sources" (param 0))))))))
                (if (eq (u16 4) (identifier "label2_695")) (size 2)
                  (if (eq (u16 5) (identifier "label2_695")) (add (size 2) (apply (identifier "per_site-sersize-of-row-binary") (get-alt "PerSite" (param 0))))
                    (if (eq (u16 6) (identifier "label2_695"))
                      (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                        (size 4)
                        (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                          (size 4)
                          (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                            (add (size 4)
                              (add
                                (let "n_ref_735" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                  (let "lebsz_ref_736" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_735")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_736")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_736") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_736")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_736")))))) 
                                (size-of-u32 (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0))))))))))
                      (if (eq (u16 7) (identifier "label2_695"))
                        (let "sz_732"
                          (let "sz_728"
                            (let "sz_727" (add (size 2) (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (get-alt "Tails" (param 0)))))
                              (add (identifier "sz_727") (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 1 (get-alt "Tails" (param 0))))))
                            (add (identifier "sz_728")
                              (add
                                (let "n_ref_730" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "lebsz_ref_731" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_730")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_731")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_731") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_731")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_731")))))) 
                                (size-of-u32 (string-length (get-item 2 (get-alt "Tails" (param 0)))))))) 
                          (add (identifier "sz_732") (apply (identifier "per_tail-sersize-of-row-binary") (get-item 3 (get-alt "Tails" (param 0))))))
                        (if (eq (u16 8) (identifier "label2_695")) (size 4)
                          (if (eq (u16 9) (identifier "label2_695"))
                            (if (is-null (get-alt "Error" (param 0))) (size 3) (add (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (force (get-alt "Error" (param 0))))) (size 1)))
                            (if (eq (u16 10) (identifier "label2_695")) 
                              (size 2)
                              (if (eq (u16 11) (identifier "label2_695"))
                                (let "sz_725" (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (get-item 0 (get-alt "PerClient" (param 0)))))
                                  (add (identifier "sz_725") (apply (identifier "per_client-sersize-of-row-binary") (get-item 1 (get-alt "PerClient" (param 0))))))
                                (if (eq (u16 12) (identifier "label2_695"))
                                  (let "sz_723"
                                    (add (size 2)
                                      (add
                                        (let "n_ref_721" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "lebsz_ref_722" (make-vec (u32 1))
                                            (seq
                                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_721")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_722")) (u8 7)))
                                                (set-vec (u8 0) (identifier "lebsz_ref_722") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_722")) (u32 1)))) 
                                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_722")))))) 
                                        (size-of-u32 (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))))
                                    (add (identifier "sz_723") (apply (identifier "per_dash_key-sersize-of-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))))))
                                  (if (eq (u16 13) (identifier "label2_695")) 
                                    (size 2)
                                    (if (eq (u16 14) (identifier "label2_695"))
                                      (let "sz_711" (add (size 2) (apply (ext-identifier team_name sersize-of-row-binary) (get-item 0 (get-alt "Teams" (param 0)))))
                                        (if (eq (u16 0) (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                          (add (add (identifier "sz_711") (size 2))
                                            (add
                                              (let "n_ref_717" (make-vec (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                                (let "lebsz_ref_718" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_717")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_718")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_718") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_718")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_718")))))) 
                                              (size-of-u32 (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))))
                                          (seq (assert (eq (label-of (get-item 1 (get-alt "Teams" (param 0)))) (u16 1)))
                                            (add (add (identifier "sz_711") (size 2))
                                              (add
                                                (let "n_ref_714" (make-vec (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))
                                                  (let "lebsz_ref_715" 
                                                    (make-vec (u32 1))
                                                    (seq
                                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_714")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_715")) (u8 7)))
                                                        (set-vec (u8 0) (identifier "lebsz_ref_715") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_715")) (u32 1)))) 
                                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_715")))))) 
                                                (size-of-u32 (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0)))))))))))
                                      (seq (assert (eq (identifier "label2_695") (u16 15)))
                                        (let "sz_700"
                                          (add (size 2)
                                            (add
                                              (let "n_ref_698" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "lebsz_ref_699" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_698")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_699")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_699") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_699")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_699")))))) 
                                              (size-of-u32 (string-length (get-item 0 (get-alt "Incidents" (param 0)))))))
                                          (let "label2_701" (label-of (get-item 1 (get-alt "Incidents" (param 0))))
                                            (if (eq (u16 0) (identifier "label2_701")) 
                                              (add (identifier "sz_700") (size 2))
                                              (if (eq (u16 1) (identifier "label2_701")) 
                                                (add (identifier "sz_700") (size 2))
                                                (if (eq (u16 2) (identifier "label2_701")) 
                                                  (add (identifier "sz_700") (size 2))
                                                  (if (eq (u16 3) (identifier "label2_701")) 
                                                    (add (identifier "sz_700") (size 2))
                                                    (if (eq (u16 4) (identifier "label2_701")) 
                                                      (add (identifier "sz_700") (size 2))
                                                      (if (eq (u16 5) (identifier "label2_701"))
                                                        (let "sz_708"
                                                          (add (add (identifier "sz_700") (size 2))
                                                            (add
                                                              (let "n_ref_706" 
                                                                (make-vec (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                (let "lebsz_ref_707" 
                                                                  (make-vec (u32 1))
                                                                  (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_706")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_707")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_707") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_707")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_707"))))))
                                                              (size-of-u32 (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))))
                                                          (let "label2_709" 
                                                            (label-of (get-item 1 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0))))))
                                                            (if (eq (u16 0) (identifier "label2_709")) 
                                                              (add (identifier "sz_708") (size 2))
                                                              (if (eq (u16 1) (identifier "label2_709")) 
                                                                (add (identifier "sz_708") (size 2))
                                                                (if (eq (u16 2) (identifier "label2_709")) 
                                                                  (add (identifier "sz_708") (size 2))
                                                                  (if 
                                                                    (eq (u16 3) (identifier "label2_709")) 
                                                                    (add (identifier "sz_708") (size 2))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "label2_709")) 
                                                                    (add (identifier "sz_708") (size 2))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "label2_709")) 
                                                                    (add (identifier "sz_708") (size 2)) 
                                                                    (seq (assert (eq (identifier "label2_709") (u16 6))) (add (identifier "sz_708") (size 2)))))))))))
                                                        (seq (assert (eq (identifier "label2_701") (u16 6))) (add (add (add (identifier "sz_700") (size 2)) (size 8)) (size 4)))))))))))))))))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> fun1308 { [&fun1308](std::shared_ptr<::dessser::gen::sync_key::t>  p_0) {
    uint16_t id_1309 { uint16_t((*p_0).index()) };
    Size let_res_1310;
    {
      uint16_t label2_695 { id_1309 };
      uint16_t id_1311 { 0 };
      bool id_1312 { bool(id_1311 == label2_695) };
      Size choose_res_1313;
      if (id_1312) {
        Size id_1314 { 2UL };
        choose_res_1313 = id_1314;
      } else {
        uint16_t id_1315 { 1 };
        bool id_1316 { bool(id_1315 == label2_695) };
        Size choose_res_1317;
        if (id_1316) {
          Size id_1318 { 2UL };
          choose_res_1317 = id_1318;
        } else {
          uint16_t id_1319 { 2 };
          bool id_1320 { bool(id_1319 == label2_695) };
          Size choose_res_1321;
          if (id_1320) {
            Size id_1322 { 2UL };
            std::string id_1323 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1324 { (uint32_t)id_1323.size() };
            Vec<1, uint32_t> id_1325 {  id_1324  };
            Size let_res_1326;
            {
              Vec<1, uint32_t> n_ref_743 { id_1325 };
              uint32_t id_1327 { 1U };
              Vec<1, uint32_t> id_1328 {  id_1327  };
              Size let_res_1329;
              {
                Vec<1, uint32_t> lebsz_ref_744 { id_1328 };
                bool while_flag_1330 { true };
                do {
                  uint8_t id_1331 { 0 };
                  uint32_t id_1332 { n_ref_743[id_1331] };
                  uint8_t id_1333 { 0 };
                  uint32_t id_1334 { lebsz_ref_744[id_1333] };
                  uint8_t id_1335 { 7 };
                  uint32_t id_1336 { uint32_t(id_1334 << id_1335) };
                  bool id_1337 { bool(id_1332 >= id_1336) };
                  while_flag_1330 = id_1337;
                  if (while_flag_1330) {
                    uint8_t id_1338 { 0 };
                    uint8_t id_1339 { 0 };
                    uint32_t id_1340 { lebsz_ref_744[id_1339] };
                    uint32_t id_1341 { 1U };
                    uint32_t id_1342 { uint32_t(id_1340 + id_1341) };
                    Void id_1343 { ((void)(lebsz_ref_744[id_1338] = id_1342), ::dessser::VOID) };
                    (void)id_1343;
                  }
                } while (while_flag_1330);
                (void)::dessser::VOID;
                uint8_t id_1344 { 0 };
                uint32_t id_1345 { lebsz_ref_744[id_1344] };
                Size id_1346 { Size(id_1345) };
                let_res_1329 = id_1346;
              }
              let_res_1326 = let_res_1329;
            }
            std::string id_1347 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1348 { (uint32_t)id_1347.size() };
            Size id_1349 { Size(id_1348) };
            Size id_1350 { Size(let_res_1326 + id_1349) };
            Size id_1351 { Size(id_1322 + id_1350) };
            choose_res_1321 = id_1351;
          } else {
            uint16_t id_1352 { 3 };
            bool id_1353 { bool(id_1352 == label2_695) };
            Size choose_res_1354;
            if (id_1353) {
              Size id_1355 { 2UL };
              auto fun1356 { dessser::gen::src_path::sersize_of_row_binary };
              ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_1357 { std::get<3 /* Sources */>((*p_0)) };
              dessser::gen::src_path::t_ext id_1358 { std::get<0>(id_1357) };
              Size id_1359 { fun1356(id_1358) };
              Size id_1360 { Size(id_1355 + id_1359) };
              Size let_res_1361;
              {
                Size sz_738 { id_1360 };
                ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_1362 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1363 { std::get<1>(id_1362) };
                uint32_t id_1364 { (uint32_t)id_1363.size() };
                Vec<1, uint32_t> id_1365 {  id_1364  };
                Size let_res_1366;
                {
                  Vec<1, uint32_t> n_ref_740 { id_1365 };
                  uint32_t id_1367 { 1U };
                  Vec<1, uint32_t> id_1368 {  id_1367  };
                  Size let_res_1369;
                  {
                    Vec<1, uint32_t> lebsz_ref_741 { id_1368 };
                    bool while_flag_1370 { true };
                    do {
                      uint8_t id_1371 { 0 };
                      uint32_t id_1372 { n_ref_740[id_1371] };
                      uint8_t id_1373 { 0 };
                      uint32_t id_1374 { lebsz_ref_741[id_1373] };
                      uint8_t id_1375 { 7 };
                      uint32_t id_1376 { uint32_t(id_1374 << id_1375) };
                      bool id_1377 { bool(id_1372 >= id_1376) };
                      while_flag_1370 = id_1377;
                      if (while_flag_1370) {
                        uint8_t id_1378 { 0 };
                        uint8_t id_1379 { 0 };
                        uint32_t id_1380 { lebsz_ref_741[id_1379] };
                        uint32_t id_1381 { 1U };
                        uint32_t id_1382 { uint32_t(id_1380 + id_1381) };
                        Void id_1383 { ((void)(lebsz_ref_741[id_1378] = id_1382), ::dessser::VOID) };
                        (void)id_1383;
                      }
                    } while (while_flag_1370);
                    (void)::dessser::VOID;
                    uint8_t id_1384 { 0 };
                    uint32_t id_1385 { lebsz_ref_741[id_1384] };
                    Size id_1386 { Size(id_1385) };
                    let_res_1369 = id_1386;
                  }
                  let_res_1366 = let_res_1369;
                }
                ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_1387 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1388 { std::get<1>(id_1387) };
                uint32_t id_1389 { (uint32_t)id_1388.size() };
                Size id_1390 { Size(id_1389) };
                Size id_1391 { Size(let_res_1366 + id_1390) };
                Size id_1392 { Size(sz_738 + id_1391) };
                let_res_1361 = id_1392;
              }
              choose_res_1354 = let_res_1361;
            } else {
              uint16_t id_1393 { 4 };
              bool id_1394 { bool(id_1393 == label2_695) };
              Size choose_res_1395;
              if (id_1394) {
                Size id_1396 { 2UL };
                choose_res_1395 = id_1396;
              } else {
                uint16_t id_1397 { 5 };
                bool id_1398 { bool(id_1397 == label2_695) };
                Size choose_res_1399;
                if (id_1398) {
                  Size id_1400 { 2UL };
                  std::shared_ptr<::dessser::gen::sync_key::per_site>  id_1401 { std::get<5 /* PerSite */>((*p_0)) };
                  Size id_1402 { per_site_sersize_of_row_binary(id_1401) };
                  Size id_1403 { Size(id_1400 + id_1402) };
                  choose_res_1399 = id_1403;
                } else {
                  uint16_t id_1404 { 6 };
                  bool id_1405 { bool(id_1404 == label2_695) };
                  Size choose_res_1406;
                  if (id_1405) {
                    uint16_t id_1407 { 0 };
                    ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1408 { std::get<6 /* Storage */>((*p_0)) };
                    uint16_t id_1409 { uint16_t(id_1408.index()) };
                    bool id_1410 { bool(id_1407 == id_1409) };
                    Size choose_res_1411;
                    if (id_1410) {
                      Size id_1412 { 4UL };
                      choose_res_1411 = id_1412;
                    } else {
                      uint16_t id_1413 { 1 };
                      ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1414 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_1415 { uint16_t(id_1414.index()) };
                      bool id_1416 { bool(id_1413 == id_1415) };
                      Size choose_res_1417;
                      if (id_1416) {
                        Size id_1418 { 4UL };
                        choose_res_1417 = id_1418;
                      } else {
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1419 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_1420 { uint16_t(id_1419.index()) };
                        uint16_t id_1421 { 2 };
                        bool id_1422 { bool(id_1420 == id_1421) };
                        Void id_1423 { ((void)(assert(id_1422)), ::dessser::VOID) };
                        (void)id_1423;
                        Size id_1424 { 4UL };
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1425 { std::get<6 /* Storage */>((*p_0)) };
                        std::string id_1426 { std::get<2 /* RetentionsOverride */>(id_1425) };
                        uint32_t id_1427 { (uint32_t)id_1426.size() };
                        Vec<1, uint32_t> id_1428 {  id_1427  };
                        Size let_res_1429;
                        {
                          Vec<1, uint32_t> n_ref_735 { id_1428 };
                          uint32_t id_1430 { 1U };
                          Vec<1, uint32_t> id_1431 {  id_1430  };
                          Size let_res_1432;
                          {
                            Vec<1, uint32_t> lebsz_ref_736 { id_1431 };
                            bool while_flag_1433 { true };
                            do {
                              uint8_t id_1434 { 0 };
                              uint32_t id_1435 { n_ref_735[id_1434] };
                              uint8_t id_1436 { 0 };
                              uint32_t id_1437 { lebsz_ref_736[id_1436] };
                              uint8_t id_1438 { 7 };
                              uint32_t id_1439 { uint32_t(id_1437 << id_1438) };
                              bool id_1440 { bool(id_1435 >= id_1439) };
                              while_flag_1433 = id_1440;
                              if (while_flag_1433) {
                                uint8_t id_1441 { 0 };
                                uint8_t id_1442 { 0 };
                                uint32_t id_1443 { lebsz_ref_736[id_1442] };
                                uint32_t id_1444 { 1U };
                                uint32_t id_1445 { uint32_t(id_1443 + id_1444) };
                                Void id_1446 { ((void)(lebsz_ref_736[id_1441] = id_1445), ::dessser::VOID) };
                                (void)id_1446;
                              }
                            } while (while_flag_1433);
                            (void)::dessser::VOID;
                            uint8_t id_1447 { 0 };
                            uint32_t id_1448 { lebsz_ref_736[id_1447] };
                            Size id_1449 { Size(id_1448) };
                            let_res_1432 = id_1449;
                          }
                          let_res_1429 = let_res_1432;
                        }
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1450 { std::get<6 /* Storage */>((*p_0)) };
                        std::string id_1451 { std::get<2 /* RetentionsOverride */>(id_1450) };
                        uint32_t id_1452 { (uint32_t)id_1451.size() };
                        Size id_1453 { Size(id_1452) };
                        Size id_1454 { Size(let_res_1429 + id_1453) };
                        Size id_1455 { Size(id_1424 + id_1454) };
                        choose_res_1417 = id_1455;
                      }
                      choose_res_1411 = choose_res_1417;
                    }
                    choose_res_1406 = choose_res_1411;
                  } else {
                    uint16_t id_1456 { 7 };
                    bool id_1457 { bool(id_1456 == label2_695) };
                    Size choose_res_1458;
                    if (id_1457) {
                      Size id_1459 { 2UL };
                      auto fun1460 { dessser::gen::site_name::sersize_of_row_binary };
                      ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_1461 { std::get<7 /* Tails */>((*p_0)) };
                      dessser::gen::site_name::t_ext id_1462 { std::get<0>(id_1461) };
                      Size id_1463 { fun1460(id_1462) };
                      Size id_1464 { Size(id_1459 + id_1463) };
                      Size let_res_1465;
                      {
                        Size sz_727 { id_1464 };
                        auto fun1466 { dessser::gen::fq_name::sersize_of_row_binary };
                        ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_1467 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::fq_name::t_ext id_1468 { std::get<1>(id_1467) };
                        Size id_1469 { fun1466(id_1468) };
                        Size id_1470 { Size(sz_727 + id_1469) };
                        let_res_1465 = id_1470;
                      }
                      Size let_res_1471;
                      {
                        Size sz_728 { let_res_1465 };
                        ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_1472 { std::get<7 /* Tails */>((*p_0)) };
                        std::string id_1473 { std::get<2>(id_1472) };
                        uint32_t id_1474 { (uint32_t)id_1473.size() };
                        Vec<1, uint32_t> id_1475 {  id_1474  };
                        Size let_res_1476;
                        {
                          Vec<1, uint32_t> n_ref_730 { id_1475 };
                          uint32_t id_1477 { 1U };
                          Vec<1, uint32_t> id_1478 {  id_1477  };
                          Size let_res_1479;
                          {
                            Vec<1, uint32_t> lebsz_ref_731 { id_1478 };
                            bool while_flag_1480 { true };
                            do {
                              uint8_t id_1481 { 0 };
                              uint32_t id_1482 { n_ref_730[id_1481] };
                              uint8_t id_1483 { 0 };
                              uint32_t id_1484 { lebsz_ref_731[id_1483] };
                              uint8_t id_1485 { 7 };
                              uint32_t id_1486 { uint32_t(id_1484 << id_1485) };
                              bool id_1487 { bool(id_1482 >= id_1486) };
                              while_flag_1480 = id_1487;
                              if (while_flag_1480) {
                                uint8_t id_1488 { 0 };
                                uint8_t id_1489 { 0 };
                                uint32_t id_1490 { lebsz_ref_731[id_1489] };
                                uint32_t id_1491 { 1U };
                                uint32_t id_1492 { uint32_t(id_1490 + id_1491) };
                                Void id_1493 { ((void)(lebsz_ref_731[id_1488] = id_1492), ::dessser::VOID) };
                                (void)id_1493;
                              }
                            } while (while_flag_1480);
                            (void)::dessser::VOID;
                            uint8_t id_1494 { 0 };
                            uint32_t id_1495 { lebsz_ref_731[id_1494] };
                            Size id_1496 { Size(id_1495) };
                            let_res_1479 = id_1496;
                          }
                          let_res_1476 = let_res_1479;
                        }
                        ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_1497 { std::get<7 /* Tails */>((*p_0)) };
                        std::string id_1498 { std::get<2>(id_1497) };
                        uint32_t id_1499 { (uint32_t)id_1498.size() };
                        Size id_1500 { Size(id_1499) };
                        Size id_1501 { Size(let_res_1476 + id_1500) };
                        Size id_1502 { Size(sz_728 + id_1501) };
                        let_res_1471 = id_1502;
                      }
                      Size let_res_1503;
                      {
                        Size sz_732 { let_res_1471 };
                        ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_1504 { std::get<7 /* Tails */>((*p_0)) };
                        std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_1505 { std::get<3>(id_1504) };
                        Size id_1506 { per_tail_sersize_of_row_binary(id_1505) };
                        Size id_1507 { Size(sz_732 + id_1506) };
                        let_res_1503 = id_1507;
                      }
                      choose_res_1458 = let_res_1503;
                    } else {
                      uint16_t id_1508 { 8 };
                      bool id_1509 { bool(id_1508 == label2_695) };
                      Size choose_res_1510;
                      if (id_1509) {
                        Size id_1511 { 4UL };
                        choose_res_1510 = id_1511;
                      } else {
                        uint16_t id_1512 { 9 };
                        bool id_1513 { bool(id_1512 == label2_695) };
                        Size choose_res_1514;
                        if (id_1513) {
                          std::optional<dessser::gen::sync_socket::t_ext> id_1515 { std::get<9 /* Error */>((*p_0)) };
                          bool id_1516 { !(id_1515.has_value ()) };
                          Size choose_res_1517;
                          if (id_1516) {
                            Size id_1518 { 3UL };
                            choose_res_1517 = id_1518;
                          } else {
                            Size id_1519 { 2UL };
                            auto fun1520 { dessser::gen::sync_socket::sersize_of_row_binary };
                            std::optional<dessser::gen::sync_socket::t_ext> id_1521 { std::get<9 /* Error */>((*p_0)) };
                            dessser::gen::sync_socket::t_ext id_1522 { id_1521.value() };
                            Size id_1523 { fun1520(id_1522) };
                            Size id_1524 { Size(id_1519 + id_1523) };
                            Size id_1525 { 1UL };
                            Size id_1526 { Size(id_1524 + id_1525) };
                            choose_res_1517 = id_1526;
                          }
                          choose_res_1514 = choose_res_1517;
                        } else {
                          uint16_t id_1527 { 10 };
                          bool id_1528 { bool(id_1527 == label2_695) };
                          Size choose_res_1529;
                          if (id_1528) {
                            Size id_1530 { 2UL };
                            choose_res_1529 = id_1530;
                          } else {
                            uint16_t id_1531 { 11 };
                            bool id_1532 { bool(id_1531 == label2_695) };
                            Size choose_res_1533;
                            if (id_1532) {
                              Size id_1534 { 2UL };
                              auto fun1535 { dessser::gen::sync_socket::sersize_of_row_binary };
                              ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef id_1536 { std::get<11 /* PerClient */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_1537 { std::get<0>(id_1536) };
                              Size id_1538 { fun1535(id_1537) };
                              Size id_1539 { Size(id_1534 + id_1538) };
                              Size let_res_1540;
                              {
                                Size sz_725 { id_1539 };
                                ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef id_1541 { std::get<11 /* PerClient */>((*p_0)) };
                                std::shared_ptr<::dessser::gen::sync_key::per_client>  id_1542 { std::get<1>(id_1541) };
                                Size id_1543 { per_client_sersize_of_row_binary(id_1542) };
                                Size id_1544 { Size(sz_725 + id_1543) };
                                let_res_1540 = id_1544;
                              }
                              choose_res_1533 = let_res_1540;
                            } else {
                              uint16_t id_1545 { 12 };
                              bool id_1546 { bool(id_1545 == label2_695) };
                              Size choose_res_1547;
                              if (id_1546) {
                                Size id_1548 { 2UL };
                                ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_1549 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1550 { std::get<0>(id_1549) };
                                uint32_t id_1551 { (uint32_t)id_1550.size() };
                                Vec<1, uint32_t> id_1552 {  id_1551  };
                                Size let_res_1553;
                                {
                                  Vec<1, uint32_t> n_ref_721 { id_1552 };
                                  uint32_t id_1554 { 1U };
                                  Vec<1, uint32_t> id_1555 {  id_1554  };
                                  Size let_res_1556;
                                  {
                                    Vec<1, uint32_t> lebsz_ref_722 { id_1555 };
                                    bool while_flag_1557 { true };
                                    do {
                                      uint8_t id_1558 { 0 };
                                      uint32_t id_1559 { n_ref_721[id_1558] };
                                      uint8_t id_1560 { 0 };
                                      uint32_t id_1561 { lebsz_ref_722[id_1560] };
                                      uint8_t id_1562 { 7 };
                                      uint32_t id_1563 { uint32_t(id_1561 << id_1562) };
                                      bool id_1564 { bool(id_1559 >= id_1563) };
                                      while_flag_1557 = id_1564;
                                      if (while_flag_1557) {
                                        uint8_t id_1565 { 0 };
                                        uint8_t id_1566 { 0 };
                                        uint32_t id_1567 { lebsz_ref_722[id_1566] };
                                        uint32_t id_1568 { 1U };
                                        uint32_t id_1569 { uint32_t(id_1567 + id_1568) };
                                        Void id_1570 { ((void)(lebsz_ref_722[id_1565] = id_1569), ::dessser::VOID) };
                                        (void)id_1570;
                                      }
                                    } while (while_flag_1557);
                                    (void)::dessser::VOID;
                                    uint8_t id_1571 { 0 };
                                    uint32_t id_1572 { lebsz_ref_722[id_1571] };
                                    Size id_1573 { Size(id_1572) };
                                    let_res_1556 = id_1573;
                                  }
                                  let_res_1553 = let_res_1556;
                                }
                                ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_1574 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1575 { std::get<0>(id_1574) };
                                uint32_t id_1576 { (uint32_t)id_1575.size() };
                                Size id_1577 { Size(id_1576) };
                                Size id_1578 { Size(let_res_1553 + id_1577) };
                                Size id_1579 { Size(id_1548 + id_1578) };
                                Size let_res_1580;
                                {
                                  Size sz_723 { id_1579 };
                                  ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_1581 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1582 { std::get<1>(id_1581) };
                                  Size id_1583 { per_dash_key_sersize_of_row_binary(id_1582) };
                                  Size id_1584 { Size(sz_723 + id_1583) };
                                  let_res_1580 = id_1584;
                                }
                                choose_res_1547 = let_res_1580;
                              } else {
                                uint16_t id_1585 { 13 };
                                bool id_1586 { bool(id_1585 == label2_695) };
                                Size choose_res_1587;
                                if (id_1586) {
                                  Size id_1588 { 2UL };
                                  choose_res_1587 = id_1588;
                                } else {
                                  uint16_t id_1589 { 14 };
                                  bool id_1590 { bool(id_1589 == label2_695) };
                                  Size choose_res_1591;
                                  if (id_1590) {
                                    Size id_1592 { 2UL };
                                    auto fun1593 { dessser::gen::team_name::sersize_of_row_binary };
                                    ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1594 { std::get<14 /* Teams */>((*p_0)) };
                                    dessser::gen::team_name::t_ext id_1595 { std::get<0>(id_1594) };
                                    Size id_1596 { fun1593(id_1595) };
                                    Size id_1597 { Size(id_1592 + id_1596) };
                                    Size let_res_1598;
                                    {
                                      Size sz_711 { id_1597 };
                                      uint16_t id_1599 { 0 };
                                      ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1600 { std::get<14 /* Teams */>((*p_0)) };
                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1601 { std::get<1>(id_1600) };
                                      uint16_t id_1602 { uint16_t(id_1601.index()) };
                                      bool id_1603 { bool(id_1599 == id_1602) };
                                      Size choose_res_1604;
                                      if (id_1603) {
                                        Size id_1605 { 2UL };
                                        Size id_1606 { Size(sz_711 + id_1605) };
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1607 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1608 { std::get<1>(id_1607) };
                                        std::string id_1609 { std::get<0 /* Contacts */>(id_1608) };
                                        uint32_t id_1610 { (uint32_t)id_1609.size() };
                                        Vec<1, uint32_t> id_1611 {  id_1610  };
                                        Size let_res_1612;
                                        {
                                          Vec<1, uint32_t> n_ref_717 { id_1611 };
                                          uint32_t id_1613 { 1U };
                                          Vec<1, uint32_t> id_1614 {  id_1613  };
                                          Size let_res_1615;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_718 { id_1614 };
                                            bool while_flag_1616 { true };
                                            do {
                                              uint8_t id_1617 { 0 };
                                              uint32_t id_1618 { n_ref_717[id_1617] };
                                              uint8_t id_1619 { 0 };
                                              uint32_t id_1620 { lebsz_ref_718[id_1619] };
                                              uint8_t id_1621 { 7 };
                                              uint32_t id_1622 { uint32_t(id_1620 << id_1621) };
                                              bool id_1623 { bool(id_1618 >= id_1622) };
                                              while_flag_1616 = id_1623;
                                              if (while_flag_1616) {
                                                uint8_t id_1624 { 0 };
                                                uint8_t id_1625 { 0 };
                                                uint32_t id_1626 { lebsz_ref_718[id_1625] };
                                                uint32_t id_1627 { 1U };
                                                uint32_t id_1628 { uint32_t(id_1626 + id_1627) };
                                                Void id_1629 { ((void)(lebsz_ref_718[id_1624] = id_1628), ::dessser::VOID) };
                                                (void)id_1629;
                                              }
                                            } while (while_flag_1616);
                                            (void)::dessser::VOID;
                                            uint8_t id_1630 { 0 };
                                            uint32_t id_1631 { lebsz_ref_718[id_1630] };
                                            Size id_1632 { Size(id_1631) };
                                            let_res_1615 = id_1632;
                                          }
                                          let_res_1612 = let_res_1615;
                                        }
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1633 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1634 { std::get<1>(id_1633) };
                                        std::string id_1635 { std::get<0 /* Contacts */>(id_1634) };
                                        uint32_t id_1636 { (uint32_t)id_1635.size() };
                                        Size id_1637 { Size(id_1636) };
                                        Size id_1638 { Size(let_res_1612 + id_1637) };
                                        Size id_1639 { Size(id_1606 + id_1638) };
                                        choose_res_1604 = id_1639;
                                      } else {
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1640 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1641 { std::get<1>(id_1640) };
                                        uint16_t id_1642 { uint16_t(id_1641.index()) };
                                        uint16_t id_1643 { 1 };
                                        bool id_1644 { bool(id_1642 == id_1643) };
                                        Void id_1645 { ((void)(assert(id_1644)), ::dessser::VOID) };
                                        (void)id_1645;
                                        Size id_1646 { 2UL };
                                        Size id_1647 { Size(sz_711 + id_1646) };
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1648 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1649 { std::get<1>(id_1648) };
                                        std::string id_1650 { std::get<1 /* Inhibition */>(id_1649) };
                                        uint32_t id_1651 { (uint32_t)id_1650.size() };
                                        Vec<1, uint32_t> id_1652 {  id_1651  };
                                        Size let_res_1653;
                                        {
                                          Vec<1, uint32_t> n_ref_714 { id_1652 };
                                          uint32_t id_1654 { 1U };
                                          Vec<1, uint32_t> id_1655 {  id_1654  };
                                          Size let_res_1656;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_715 { id_1655 };
                                            bool while_flag_1657 { true };
                                            do {
                                              uint8_t id_1658 { 0 };
                                              uint32_t id_1659 { n_ref_714[id_1658] };
                                              uint8_t id_1660 { 0 };
                                              uint32_t id_1661 { lebsz_ref_715[id_1660] };
                                              uint8_t id_1662 { 7 };
                                              uint32_t id_1663 { uint32_t(id_1661 << id_1662) };
                                              bool id_1664 { bool(id_1659 >= id_1663) };
                                              while_flag_1657 = id_1664;
                                              if (while_flag_1657) {
                                                uint8_t id_1665 { 0 };
                                                uint8_t id_1666 { 0 };
                                                uint32_t id_1667 { lebsz_ref_715[id_1666] };
                                                uint32_t id_1668 { 1U };
                                                uint32_t id_1669 { uint32_t(id_1667 + id_1668) };
                                                Void id_1670 { ((void)(lebsz_ref_715[id_1665] = id_1669), ::dessser::VOID) };
                                                (void)id_1670;
                                              }
                                            } while (while_flag_1657);
                                            (void)::dessser::VOID;
                                            uint8_t id_1671 { 0 };
                                            uint32_t id_1672 { lebsz_ref_715[id_1671] };
                                            Size id_1673 { Size(id_1672) };
                                            let_res_1656 = id_1673;
                                          }
                                          let_res_1653 = let_res_1656;
                                        }
                                        ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_1674 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1675 { std::get<1>(id_1674) };
                                        std::string id_1676 { std::get<1 /* Inhibition */>(id_1675) };
                                        uint32_t id_1677 { (uint32_t)id_1676.size() };
                                        Size id_1678 { Size(id_1677) };
                                        Size id_1679 { Size(let_res_1653 + id_1678) };
                                        Size id_1680 { Size(id_1647 + id_1679) };
                                        choose_res_1604 = id_1680;
                                      }
                                      let_res_1598 = choose_res_1604;
                                    }
                                    choose_res_1591 = let_res_1598;
                                  } else {
                                    uint16_t id_1681 { 15 };
                                    bool id_1682 { bool(label2_695 == id_1681) };
                                    Void id_1683 { ((void)(assert(id_1682)), ::dessser::VOID) };
                                    (void)id_1683;
                                    Size id_1684 { 2UL };
                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1685 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1686 { std::get<0>(id_1685) };
                                    uint32_t id_1687 { (uint32_t)id_1686.size() };
                                    Vec<1, uint32_t> id_1688 {  id_1687  };
                                    Size let_res_1689;
                                    {
                                      Vec<1, uint32_t> n_ref_698 { id_1688 };
                                      uint32_t id_1690 { 1U };
                                      Vec<1, uint32_t> id_1691 {  id_1690  };
                                      Size let_res_1692;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_699 { id_1691 };
                                        bool while_flag_1693 { true };
                                        do {
                                          uint8_t id_1694 { 0 };
                                          uint32_t id_1695 { n_ref_698[id_1694] };
                                          uint8_t id_1696 { 0 };
                                          uint32_t id_1697 { lebsz_ref_699[id_1696] };
                                          uint8_t id_1698 { 7 };
                                          uint32_t id_1699 { uint32_t(id_1697 << id_1698) };
                                          bool id_1700 { bool(id_1695 >= id_1699) };
                                          while_flag_1693 = id_1700;
                                          if (while_flag_1693) {
                                            uint8_t id_1701 { 0 };
                                            uint8_t id_1702 { 0 };
                                            uint32_t id_1703 { lebsz_ref_699[id_1702] };
                                            uint32_t id_1704 { 1U };
                                            uint32_t id_1705 { uint32_t(id_1703 + id_1704) };
                                            Void id_1706 { ((void)(lebsz_ref_699[id_1701] = id_1705), ::dessser::VOID) };
                                            (void)id_1706;
                                          }
                                        } while (while_flag_1693);
                                        (void)::dessser::VOID;
                                        uint8_t id_1707 { 0 };
                                        uint32_t id_1708 { lebsz_ref_699[id_1707] };
                                        Size id_1709 { Size(id_1708) };
                                        let_res_1692 = id_1709;
                                      }
                                      let_res_1689 = let_res_1692;
                                    }
                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1710 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1711 { std::get<0>(id_1710) };
                                    uint32_t id_1712 { (uint32_t)id_1711.size() };
                                    Size id_1713 { Size(id_1712) };
                                    Size id_1714 { Size(let_res_1689 + id_1713) };
                                    Size id_1715 { Size(id_1684 + id_1714) };
                                    Size let_res_1716;
                                    {
                                      Size sz_700 { id_1715 };
                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1717 { std::get<15 /* Incidents */>((*p_0)) };
                                      ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1718 { std::get<1>(id_1717) };
                                      uint16_t id_1719 { uint16_t(id_1718.index()) };
                                      Size let_res_1720;
                                      {
                                        uint16_t label2_701 { id_1719 };
                                        uint16_t id_1721 { 0 };
                                        bool id_1722 { bool(id_1721 == label2_701) };
                                        Size choose_res_1723;
                                        if (id_1722) {
                                          Size id_1724 { 2UL };
                                          Size id_1725 { Size(sz_700 + id_1724) };
                                          choose_res_1723 = id_1725;
                                        } else {
                                          uint16_t id_1726 { 1 };
                                          bool id_1727 { bool(id_1726 == label2_701) };
                                          Size choose_res_1728;
                                          if (id_1727) {
                                            Size id_1729 { 2UL };
                                            Size id_1730 { Size(sz_700 + id_1729) };
                                            choose_res_1728 = id_1730;
                                          } else {
                                            uint16_t id_1731 { 2 };
                                            bool id_1732 { bool(id_1731 == label2_701) };
                                            Size choose_res_1733;
                                            if (id_1732) {
                                              Size id_1734 { 2UL };
                                              Size id_1735 { Size(sz_700 + id_1734) };
                                              choose_res_1733 = id_1735;
                                            } else {
                                              uint16_t id_1736 { 3 };
                                              bool id_1737 { bool(id_1736 == label2_701) };
                                              Size choose_res_1738;
                                              if (id_1737) {
                                                Size id_1739 { 2UL };
                                                Size id_1740 { Size(sz_700 + id_1739) };
                                                choose_res_1738 = id_1740;
                                              } else {
                                                uint16_t id_1741 { 4 };
                                                bool id_1742 { bool(id_1741 == label2_701) };
                                                Size choose_res_1743;
                                                if (id_1742) {
                                                  Size id_1744 { 2UL };
                                                  Size id_1745 { Size(sz_700 + id_1744) };
                                                  choose_res_1743 = id_1745;
                                                } else {
                                                  uint16_t id_1746 { 5 };
                                                  bool id_1747 { bool(id_1746 == label2_701) };
                                                  Size choose_res_1748;
                                                  if (id_1747) {
                                                    Size id_1749 { 2UL };
                                                    Size id_1750 { Size(sz_700 + id_1749) };
                                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1751 { std::get<15 /* Incidents */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1752 { std::get<1>(id_1751) };
                                                    ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_1753 { std::get<5 /* Dialogs */>(id_1752) };
                                                    std::string id_1754 { std::get<0>(id_1753) };
                                                    uint32_t id_1755 { (uint32_t)id_1754.size() };
                                                    Vec<1, uint32_t> id_1756 {  id_1755  };
                                                    Size let_res_1757;
                                                    {
                                                      Vec<1, uint32_t> n_ref_706 { id_1756 };
                                                      uint32_t id_1758 { 1U };
                                                      Vec<1, uint32_t> id_1759 {  id_1758  };
                                                      Size let_res_1760;
                                                      {
                                                        Vec<1, uint32_t> lebsz_ref_707 { id_1759 };
                                                        bool while_flag_1761 { true };
                                                        do {
                                                          uint8_t id_1762 { 0 };
                                                          uint32_t id_1763 { n_ref_706[id_1762] };
                                                          uint8_t id_1764 { 0 };
                                                          uint32_t id_1765 { lebsz_ref_707[id_1764] };
                                                          uint8_t id_1766 { 7 };
                                                          uint32_t id_1767 { uint32_t(id_1765 << id_1766) };
                                                          bool id_1768 { bool(id_1763 >= id_1767) };
                                                          while_flag_1761 = id_1768;
                                                          if (while_flag_1761) {
                                                            uint8_t id_1769 { 0 };
                                                            uint8_t id_1770 { 0 };
                                                            uint32_t id_1771 { lebsz_ref_707[id_1770] };
                                                            uint32_t id_1772 { 1U };
                                                            uint32_t id_1773 { uint32_t(id_1771 + id_1772) };
                                                            Void id_1774 { ((void)(lebsz_ref_707[id_1769] = id_1773), ::dessser::VOID) };
                                                            (void)id_1774;
                                                          }
                                                        } while (while_flag_1761);
                                                        (void)::dessser::VOID;
                                                        uint8_t id_1775 { 0 };
                                                        uint32_t id_1776 { lebsz_ref_707[id_1775] };
                                                        Size id_1777 { Size(id_1776) };
                                                        let_res_1760 = id_1777;
                                                      }
                                                      let_res_1757 = let_res_1760;
                                                    }
                                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1778 { std::get<15 /* Incidents */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1779 { std::get<1>(id_1778) };
                                                    ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_1780 { std::get<5 /* Dialogs */>(id_1779) };
                                                    std::string id_1781 { std::get<0>(id_1780) };
                                                    uint32_t id_1782 { (uint32_t)id_1781.size() };
                                                    Size id_1783 { Size(id_1782) };
                                                    Size id_1784 { Size(let_res_1757 + id_1783) };
                                                    Size id_1785 { Size(id_1750 + id_1784) };
                                                    Size let_res_1786;
                                                    {
                                                      Size sz_708 { id_1785 };
                                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1787 { std::get<15 /* Incidents */>((*p_0)) };
                                                      ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1788 { std::get<1>(id_1787) };
                                                      ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_1789 { std::get<5 /* Dialogs */>(id_1788) };
                                                      ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_1790 { std::get<1>(id_1789) };
                                                      uint16_t id_1791 { uint16_t(id_1790.index()) };
                                                      Size let_res_1792;
                                                      {
                                                        uint16_t label2_709 { id_1791 };
                                                        uint16_t id_1793 { 0 };
                                                        bool id_1794 { bool(id_1793 == label2_709) };
                                                        Size choose_res_1795;
                                                        if (id_1794) {
                                                          Size id_1796 { 2UL };
                                                          Size id_1797 { Size(sz_708 + id_1796) };
                                                          choose_res_1795 = id_1797;
                                                        } else {
                                                          uint16_t id_1798 { 1 };
                                                          bool id_1799 { bool(id_1798 == label2_709) };
                                                          Size choose_res_1800;
                                                          if (id_1799) {
                                                            Size id_1801 { 2UL };
                                                            Size id_1802 { Size(sz_708 + id_1801) };
                                                            choose_res_1800 = id_1802;
                                                          } else {
                                                            uint16_t id_1803 { 2 };
                                                            bool id_1804 { bool(id_1803 == label2_709) };
                                                            Size choose_res_1805;
                                                            if (id_1804) {
                                                              Size id_1806 { 2UL };
                                                              Size id_1807 { Size(sz_708 + id_1806) };
                                                              choose_res_1805 = id_1807;
                                                            } else {
                                                              uint16_t id_1808 { 3 };
                                                              bool id_1809 { bool(id_1808 == label2_709) };
                                                              Size choose_res_1810;
                                                              if (id_1809) {
                                                                Size id_1811 { 2UL };
                                                                Size id_1812 { Size(sz_708 + id_1811) };
                                                                choose_res_1810 = id_1812;
                                                              } else {
                                                                uint16_t id_1813 { 4 };
                                                                bool id_1814 { bool(id_1813 == label2_709) };
                                                                Size choose_res_1815;
                                                                if (id_1814) {
                                                                  Size id_1816 { 2UL };
                                                                  Size id_1817 { Size(sz_708 + id_1816) };
                                                                  choose_res_1815 = id_1817;
                                                                } else {
                                                                  uint16_t id_1818 { 5 };
                                                                  bool id_1819 { bool(id_1818 == label2_709) };
                                                                  Size choose_res_1820;
                                                                  if (id_1819) {
                                                                    Size id_1821 { 2UL };
                                                                    Size id_1822 { Size(sz_708 + id_1821) };
                                                                    choose_res_1820 = id_1822;
                                                                  } else {
                                                                    uint16_t id_1823 { 6 };
                                                                    bool id_1824 { bool(label2_709 == id_1823) };
                                                                    Void id_1825 { ((void)(assert(id_1824)), ::dessser::VOID) };
                                                                    (void)id_1825;
                                                                    Size id_1826 { 2UL };
                                                                    Size id_1827 { Size(sz_708 + id_1826) };
                                                                    choose_res_1820 = id_1827;
                                                                  }
                                                                  choose_res_1815 = choose_res_1820;
                                                                }
                                                                choose_res_1810 = choose_res_1815;
                                                              }
                                                              choose_res_1805 = choose_res_1810;
                                                            }
                                                            choose_res_1800 = choose_res_1805;
                                                          }
                                                          choose_res_1795 = choose_res_1800;
                                                        }
                                                        let_res_1792 = choose_res_1795;
                                                      }
                                                      let_res_1786 = let_res_1792;
                                                    }
                                                    choose_res_1748 = let_res_1786;
                                                  } else {
                                                    uint16_t id_1828 { 6 };
                                                    bool id_1829 { bool(label2_701 == id_1828) };
                                                    Void id_1830 { ((void)(assert(id_1829)), ::dessser::VOID) };
                                                    (void)id_1830;
                                                    Size id_1831 { 2UL };
                                                    Size id_1832 { Size(sz_700 + id_1831) };
                                                    Size id_1833 { 8UL };
                                                    Size id_1834 { Size(id_1832 + id_1833) };
                                                    Size id_1835 { 4UL };
                                                    Size id_1836 { Size(id_1834 + id_1835) };
                                                    choose_res_1748 = id_1836;
                                                  }
                                                  choose_res_1743 = choose_res_1748;
                                                }
                                                choose_res_1738 = choose_res_1743;
                                              }
                                              choose_res_1733 = choose_res_1738;
                                            }
                                            choose_res_1728 = choose_res_1733;
                                          }
                                          choose_res_1723 = choose_res_1728;
                                        }
                                        let_res_1720 = choose_res_1723;
                                      }
                                      let_res_1716 = let_res_1720;
                                    }
                                    choose_res_1591 = let_res_1716;
                                  }
                                  choose_res_1587 = choose_res_1591;
                                }
                                choose_res_1547 = choose_res_1587;
                              }
                              choose_res_1533 = choose_res_1547;
                            }
                            choose_res_1529 = choose_res_1533;
                          }
                          choose_res_1514 = choose_res_1529;
                        }
                        choose_res_1510 = choose_res_1514;
                      }
                      choose_res_1458 = choose_res_1510;
                    }
                    choose_res_1406 = choose_res_1458;
                  }
                  choose_res_1399 = choose_res_1406;
                }
                choose_res_1395 = choose_res_1399;
              }
              choose_res_1354 = choose_res_1395;
            }
            choose_res_1321 = choose_res_1354;
          }
          choose_res_1317 = choose_res_1321;
        }
        choose_res_1313 = choose_res_1317;
      }
      let_res_1310 = choose_res_1313;
    }
    return let_res_1310;
  }
   };
  return fun1308;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_293" (let-pair "du16_fst_288" "du16_snd_289" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_288") (identifier "du16_snd_289")))
        (let-pair "dsum1_fst_294" "dsum1_snd_295" (identifier "dsum1_293")
          (seq (assert (eq (identifier "dsum1_fst_294") (u16 0)))
            (let-pair "du32_fst_297" "du32_snd_298" (read-u32 little-endian (identifier "dsum1_snd_295")) (make-tup (construct "[Widgets U32]" 0 (identifier "du32_fst_297")) (identifier "du32_snd_298")))))))
 */
static std::function<::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c(Pointer)> per_dash_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c(Pointer)> fun1837 { [&fun1837](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1838 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1839;
    {
      auto du16_fst_288 { std::get<0>(id_1838) };
      auto du16_snd_289 { std::get<1>(id_1838) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1840 { du16_fst_288, du16_snd_289 };
      letpair_res_1839 = id_1840;
    }
    ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c let_res_1841;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_293 { letpair_res_1839 };
      ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c letpair_res_1842;
      {
        auto dsum1_fst_294 { std::get<0>(dsum1_293) };
        auto dsum1_snd_295 { std::get<1>(dsum1_293) };
        uint16_t id_1843 { 0 };
        bool id_1844 { bool(dsum1_fst_294 == id_1843) };
        Void id_1845 { ((void)(assert(id_1844)), ::dessser::VOID) };
        (void)id_1845;
        ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_1846 { dsum1_snd_295.readU32Le() };
        ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c letpair_res_1847;
        {
          auto du32_fst_297 { std::get<0>(id_1846) };
          auto du32_snd_298 { std::get<1>(id_1846) };
          std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1848 { std::make_shared<::dessser::gen::sync_key::per_dash_key>(std::in_place_index<0>, du32_fst_297) };
          ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c id_1849 { id_1848, du32_snd_298 };
          letpair_res_1847 = id_1849;
        }
        letpair_res_1842 = letpair_res_1847;
      }
      let_res_1841 = letpair_res_1842;
    }
    return let_res_1841;
  }
   };
  return fun1837;
}
std::function<::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c(Pointer)> per_dash_key_of_row_binary(per_dash_key_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_333" "make_snd_334"
        (let "dsum1_311" (let-pair "du16_fst_306" "du16_snd_307" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_306") (identifier "du16_snd_307")))
          (let-pair "dsum1_fst_312" "dsum1_snd_313" (identifier "dsum1_311")
            (if (eq (u16 0) (identifier "dsum1_fst_312"))
              (let "dstring1_323"
                (let "leb_ref_317" (make-vec (u32 0))
                  (let "shft_ref_318" (make-vec (u8 0))
                    (let "p_ref_319" (make-vec (identifier "dsum1_snd_313"))
                      (seq
                        (while
                          (let "leb128_320" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_319")))
                            (let-pair "leb128_fst_321" "leb128_snd_322" 
                              (identifier "leb128_320")
                              (seq (set-vec (u8 0) (identifier "p_ref_319") (identifier "leb128_snd_322"))
                                (set-vec (u8 0) (identifier "leb_ref_317")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_321") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_318"))) (unsafe-nth (u8 0) (identifier "leb_ref_317"))))
                                (set-vec (u8 0) (identifier "shft_ref_318") (add (unsafe-nth (u8 0) (identifier "shft_ref_318")) (u8 7))) 
                                (ge (identifier "leb128_fst_321") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_317"))) (unsafe-nth (u8 0) (identifier "p_ref_319")))))))
                (let-pair "dstring1_fst_324" "dstring1_snd_325" (identifier "dstring1_323")
                  (let-pair "dstring2_fst_327" "dstring2_snd_328" (read-bytes (identifier "dstring1_snd_325") (identifier "dstring1_fst_324"))
                    (make-tup (construct "[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" 0 (string-of-bytes (identifier "dstring2_fst_327"))) (identifier "dstring2_snd_328")))))
              (seq (assert (eq (identifier "dsum1_fst_312") (u16 1)))
                (let-pair "dsum2_fst_315" "dsum2_snd_316" (apply (identifier "per_dash_key-of-row-binary") (identifier "dsum1_snd_313"))
                  (make-tup (construct "[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" 1 (identifier "dsum2_fst_315")) (identifier "dsum2_snd_316")))))))
        (make-tup (identifier "make_fst_333") (identifier "make_snd_334"))))
 */
static std::function<::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9(Pointer)> per_client_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9(Pointer)> fun1850 { [&fun1850](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1851 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1852;
    {
      auto du16_fst_306 { std::get<0>(id_1851) };
      auto du16_snd_307 { std::get<1>(id_1851) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1853 { du16_fst_306, du16_snd_307 };
      letpair_res_1852 = id_1853;
    }
    ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 let_res_1854;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_311 { letpair_res_1852 };
      ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 letpair_res_1855;
      {
        auto dsum1_fst_312 { std::get<0>(dsum1_311) };
        auto dsum1_snd_313 { std::get<1>(dsum1_311) };
        uint16_t id_1856 { 0 };
        bool id_1857 { bool(id_1856 == dsum1_fst_312) };
        ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 choose_res_1858;
        if (id_1857) {
          uint32_t id_1859 { 0U };
          Vec<1, uint32_t> id_1860 {  id_1859  };
          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_1861;
          {
            Vec<1, uint32_t> leb_ref_317 { id_1860 };
            uint8_t id_1862 { 0 };
            Vec<1, uint8_t> id_1863 {  id_1862  };
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_1864;
            {
              Vec<1, uint8_t> shft_ref_318 { id_1863 };
              Vec<1, Pointer> id_1865 {  dsum1_snd_313  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_1866;
              {
                Vec<1, Pointer> p_ref_319 { id_1865 };
                bool while_flag_1867 { true };
                do {
                  uint8_t id_1868 { 0 };
                  Pointer id_1869 { p_ref_319[id_1868] };
                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_1870 { id_1869.readU8() };
                  bool let_res_1871;
                  {
                    ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_320 { id_1870 };
                    bool letpair_res_1872;
                    {
                      auto leb128_fst_321 { std::get<0>(leb128_320) };
                      auto leb128_snd_322 { std::get<1>(leb128_320) };
                      uint8_t id_1873 { 0 };
                      Void id_1874 { ((void)(p_ref_319[id_1873] = leb128_snd_322), ::dessser::VOID) };
                      (void)id_1874;
                      uint8_t id_1875 { 0 };
                      uint8_t id_1876 { 127 };
                      uint8_t id_1877 { uint8_t(leb128_fst_321 & id_1876) };
                      uint32_t id_1878 { uint32_t(id_1877) };
                      uint8_t id_1879 { 0 };
                      uint8_t id_1880 { shft_ref_318[id_1879] };
                      uint32_t id_1881 { uint32_t(id_1878 << id_1880) };
                      uint8_t id_1882 { 0 };
                      uint32_t id_1883 { leb_ref_317[id_1882] };
                      uint32_t id_1884 { uint32_t(id_1881 | id_1883) };
                      Void id_1885 { ((void)(leb_ref_317[id_1875] = id_1884), ::dessser::VOID) };
                      (void)id_1885;
                      uint8_t id_1886 { 0 };
                      uint8_t id_1887 { 0 };
                      uint8_t id_1888 { shft_ref_318[id_1887] };
                      uint8_t id_1889 { 7 };
                      uint8_t id_1890 { uint8_t(id_1888 + id_1889) };
                      Void id_1891 { ((void)(shft_ref_318[id_1886] = id_1890), ::dessser::VOID) };
                      (void)id_1891;
                      uint8_t id_1892 { 128 };
                      bool id_1893 { bool(leb128_fst_321 >= id_1892) };
                      letpair_res_1872 = id_1893;
                    }
                    let_res_1871 = letpair_res_1872;
                  }
                  while_flag_1867 = let_res_1871;
                  if (while_flag_1867) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_1867);
                (void)::dessser::VOID;
                uint8_t id_1894 { 0 };
                uint32_t id_1895 { leb_ref_317[id_1894] };
                Size id_1896 { Size(id_1895) };
                uint8_t id_1897 { 0 };
                Pointer id_1898 { p_ref_319[id_1897] };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_1899 { id_1896, id_1898 };
                let_res_1866 = id_1899;
              }
              let_res_1864 = let_res_1866;
            }
            let_res_1861 = let_res_1864;
          }
          ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 let_res_1900;
          {
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_323 { let_res_1861 };
            ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 letpair_res_1901;
            {
              auto dstring1_fst_324 { std::get<0>(dstring1_323) };
              auto dstring1_snd_325 { std::get<1>(dstring1_323) };
              ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_1902 { dstring1_snd_325.readBytes(dstring1_fst_324) };
              ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 letpair_res_1903;
              {
                auto dstring2_fst_327 { std::get<0>(id_1902) };
                auto dstring2_snd_328 { std::get<1>(id_1902) };
                std::string id_1904 { dstring2_fst_327.toString() };
                std::shared_ptr<::dessser::gen::sync_key::per_client>  id_1905 { std::make_shared<::dessser::gen::sync_key::per_client>(std::in_place_index<0>, id_1904) };
                ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 id_1906 { id_1905, dstring2_snd_328 };
                letpair_res_1903 = id_1906;
              }
              letpair_res_1901 = letpair_res_1903;
            }
            let_res_1900 = letpair_res_1901;
          }
          choose_res_1858 = let_res_1900;
        } else {
          uint16_t id_1907 { 1 };
          bool id_1908 { bool(dsum1_fst_312 == id_1907) };
          Void id_1909 { ((void)(assert(id_1908)), ::dessser::VOID) };
          (void)id_1909;
          ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c id_1910 { per_dash_key_of_row_binary(dsum1_snd_313) };
          ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 letpair_res_1911;
          {
            auto dsum2_fst_315 { std::get<0>(id_1910) };
            auto dsum2_snd_316 { std::get<1>(id_1910) };
            std::shared_ptr<::dessser::gen::sync_key::per_client>  id_1912 { std::make_shared<::dessser::gen::sync_key::per_client>(std::in_place_index<1>, dsum2_fst_315) };
            ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 id_1913 { id_1912, dsum2_snd_316 };
            letpair_res_1911 = id_1913;
          }
          choose_res_1858 = letpair_res_1911;
        }
        letpair_res_1855 = choose_res_1858;
      }
      let_res_1854 = letpair_res_1855;
    }
    ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 letpair_res_1914;
    {
      auto make_fst_333 { std::get<0>(let_res_1854) };
      auto make_snd_334 { std::get<1>(let_res_1854) };
      ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 id_1915 { make_fst_333, make_snd_334 };
      letpair_res_1914 = id_1915;
    }
    return letpair_res_1914;
  }
   };
  return fun1850;
}
std::function<::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9(Pointer)> per_client_of_row_binary(per_client_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_285" "make_snd_286"
        (let "dsum1_260" (let-pair "du16_fst_255" "du16_snd_256" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_255") (identifier "du16_snd_256")))
          (let-pair "dsum1_fst_261" "dsum1_snd_262" (identifier "dsum1_260")
            (if (eq (u16 0) (identifier "dsum1_fst_261"))
              (let "dstring1_275"
                (let "leb_ref_269" (make-vec (u32 0))
                  (let "shft_ref_270" (make-vec (u8 0))
                    (let "p_ref_271" (make-vec (identifier "dsum1_snd_262"))
                      (seq
                        (while
                          (let "leb128_272" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_271")))
                            (let-pair "leb128_fst_273" "leb128_snd_274" 
                              (identifier "leb128_272")
                              (seq (set-vec (u8 0) (identifier "p_ref_271") (identifier "leb128_snd_274"))
                                (set-vec (u8 0) (identifier "leb_ref_269")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_273") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_270"))) (unsafe-nth (u8 0) (identifier "leb_ref_269"))))
                                (set-vec (u8 0) (identifier "shft_ref_270") (add (unsafe-nth (u8 0) (identifier "shft_ref_270")) (u8 7))) 
                                (ge (identifier "leb128_fst_273") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_269"))) (unsafe-nth (u8 0) (identifier "p_ref_271")))))))
                (let-pair "dstring1_fst_276" "dstring1_snd_277" (identifier "dstring1_275")
                  (let-pair "dstring2_fst_279" "dstring2_snd_280" (read-bytes (identifier "dstring1_snd_277") (identifier "dstring1_fst_276"))
                    (make-tup (construct "[Subscriber STRING | LastTuple U32]" 0 (string-of-bytes (identifier "dstring2_fst_279"))) (identifier "dstring2_snd_280")))))
              (seq (assert (eq (identifier "dsum1_fst_261") (u16 1)))
                (let-pair "du32_fst_264" "du32_snd_265" (read-u32 little-endian (identifier "dsum1_snd_262")) (make-tup (construct "[Subscriber STRING | LastTuple U32]" 1 (identifier "du32_fst_264")) (identifier "du32_snd_265")))))))
        (make-tup (identifier "make_fst_285") (identifier "make_snd_286"))))
 */
static std::function<::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d(Pointer)> per_tail_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d(Pointer)> fun1916 { [&fun1916](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1917 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1918;
    {
      auto du16_fst_255 { std::get<0>(id_1917) };
      auto du16_snd_256 { std::get<1>(id_1917) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1919 { du16_fst_255, du16_snd_256 };
      letpair_res_1918 = id_1919;
    }
    ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d let_res_1920;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_260 { letpair_res_1918 };
      ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d letpair_res_1921;
      {
        auto dsum1_fst_261 { std::get<0>(dsum1_260) };
        auto dsum1_snd_262 { std::get<1>(dsum1_260) };
        uint16_t id_1922 { 0 };
        bool id_1923 { bool(id_1922 == dsum1_fst_261) };
        ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d choose_res_1924;
        if (id_1923) {
          uint32_t id_1925 { 0U };
          Vec<1, uint32_t> id_1926 {  id_1925  };
          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_1927;
          {
            Vec<1, uint32_t> leb_ref_269 { id_1926 };
            uint8_t id_1928 { 0 };
            Vec<1, uint8_t> id_1929 {  id_1928  };
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_1930;
            {
              Vec<1, uint8_t> shft_ref_270 { id_1929 };
              Vec<1, Pointer> id_1931 {  dsum1_snd_262  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_1932;
              {
                Vec<1, Pointer> p_ref_271 { id_1931 };
                bool while_flag_1933 { true };
                do {
                  uint8_t id_1934 { 0 };
                  Pointer id_1935 { p_ref_271[id_1934] };
                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_1936 { id_1935.readU8() };
                  bool let_res_1937;
                  {
                    ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_272 { id_1936 };
                    bool letpair_res_1938;
                    {
                      auto leb128_fst_273 { std::get<0>(leb128_272) };
                      auto leb128_snd_274 { std::get<1>(leb128_272) };
                      uint8_t id_1939 { 0 };
                      Void id_1940 { ((void)(p_ref_271[id_1939] = leb128_snd_274), ::dessser::VOID) };
                      (void)id_1940;
                      uint8_t id_1941 { 0 };
                      uint8_t id_1942 { 127 };
                      uint8_t id_1943 { uint8_t(leb128_fst_273 & id_1942) };
                      uint32_t id_1944 { uint32_t(id_1943) };
                      uint8_t id_1945 { 0 };
                      uint8_t id_1946 { shft_ref_270[id_1945] };
                      uint32_t id_1947 { uint32_t(id_1944 << id_1946) };
                      uint8_t id_1948 { 0 };
                      uint32_t id_1949 { leb_ref_269[id_1948] };
                      uint32_t id_1950 { uint32_t(id_1947 | id_1949) };
                      Void id_1951 { ((void)(leb_ref_269[id_1941] = id_1950), ::dessser::VOID) };
                      (void)id_1951;
                      uint8_t id_1952 { 0 };
                      uint8_t id_1953 { 0 };
                      uint8_t id_1954 { shft_ref_270[id_1953] };
                      uint8_t id_1955 { 7 };
                      uint8_t id_1956 { uint8_t(id_1954 + id_1955) };
                      Void id_1957 { ((void)(shft_ref_270[id_1952] = id_1956), ::dessser::VOID) };
                      (void)id_1957;
                      uint8_t id_1958 { 128 };
                      bool id_1959 { bool(leb128_fst_273 >= id_1958) };
                      letpair_res_1938 = id_1959;
                    }
                    let_res_1937 = letpair_res_1938;
                  }
                  while_flag_1933 = let_res_1937;
                  if (while_flag_1933) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_1933);
                (void)::dessser::VOID;
                uint8_t id_1960 { 0 };
                uint32_t id_1961 { leb_ref_269[id_1960] };
                Size id_1962 { Size(id_1961) };
                uint8_t id_1963 { 0 };
                Pointer id_1964 { p_ref_271[id_1963] };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_1965 { id_1962, id_1964 };
                let_res_1932 = id_1965;
              }
              let_res_1930 = let_res_1932;
            }
            let_res_1927 = let_res_1930;
          }
          ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d let_res_1966;
          {
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_275 { let_res_1927 };
            ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d letpair_res_1967;
            {
              auto dstring1_fst_276 { std::get<0>(dstring1_275) };
              auto dstring1_snd_277 { std::get<1>(dstring1_275) };
              ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_1968 { dstring1_snd_277.readBytes(dstring1_fst_276) };
              ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d letpair_res_1969;
              {
                auto dstring2_fst_279 { std::get<0>(id_1968) };
                auto dstring2_snd_280 { std::get<1>(id_1968) };
                std::string id_1970 { dstring2_fst_279.toString() };
                std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_1971 { std::make_shared<::dessser::gen::sync_key::per_tail>(std::in_place_index<0>, id_1970) };
                ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d id_1972 { id_1971, dstring2_snd_280 };
                letpair_res_1969 = id_1972;
              }
              letpair_res_1967 = letpair_res_1969;
            }
            let_res_1966 = letpair_res_1967;
          }
          choose_res_1924 = let_res_1966;
        } else {
          uint16_t id_1973 { 1 };
          bool id_1974 { bool(dsum1_fst_261 == id_1973) };
          Void id_1975 { ((void)(assert(id_1974)), ::dessser::VOID) };
          (void)id_1975;
          ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_1976 { dsum1_snd_262.readU32Le() };
          ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d letpair_res_1977;
          {
            auto du32_fst_264 { std::get<0>(id_1976) };
            auto du32_snd_265 { std::get<1>(id_1976) };
            std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_1978 { std::make_shared<::dessser::gen::sync_key::per_tail>(std::in_place_index<1>, du32_fst_264) };
            ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d id_1979 { id_1978, du32_snd_265 };
            letpair_res_1977 = id_1979;
          }
          choose_res_1924 = letpair_res_1977;
        }
        letpair_res_1921 = choose_res_1924;
      }
      let_res_1920 = letpair_res_1921;
    }
    ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d letpair_res_1980;
    {
      auto make_fst_285 { std::get<0>(let_res_1920) };
      auto make_snd_286 { std::get<1>(let_res_1920) };
      ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d id_1981 { make_fst_285, make_snd_286 };
      letpair_res_1980 = id_1981;
    }
    return letpair_res_1980;
  }
   };
  return fun1916;
}
std::function<::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d(Pointer)> per_tail_of_row_binary(per_tail_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_147" "make_snd_148"
        (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
          (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
            (if (eq (u16 0) (identifier "dsum1_fst_63"))
              (make-tup
                (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 0
                  (nop)) (identifier "dsum1_snd_64"))
              (if (eq (u16 1) (identifier "dsum1_fst_63"))
                (make-tup
                  (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 1
                    (nop)) (identifier "dsum1_snd_64"))
                (if (eq (u16 2) (identifier "dsum1_fst_63"))
                  (make-tup
                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 2
                      (nop)) (identifier "dsum1_snd_64"))
                  (if (eq (u16 3) (identifier "dsum1_fst_63"))
                    (make-tup
                      (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 3
                        (nop)) (identifier "dsum1_snd_64"))
                    (if (eq (u16 4) (identifier "dsum1_fst_63"))
                      (make-tup
                        (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 4
                          (nop)) (identifier "dsum1_snd_64"))
                      (if (eq (u16 5) (identifier "dsum1_fst_63"))
                        (make-tup
                          (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 5
                            (nop)) (identifier "dsum1_snd_64"))
                        (if (eq (u16 6) (identifier "dsum1_fst_63"))
                          (let "dtup_86"
                            (let "dstring1_80"
                              (let "leb_ref_74" (make-vec (u32 0))
                                (let "shft_ref_75" (make-vec (u8 0))
                                  (let "p_ref_76" (make-vec (identifier "dsum1_snd_64"))
                                    (seq
                                      (while
                                        (let "leb128_77" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_76")))
                                          (let-pair "leb128_fst_78" "leb128_snd_79" 
                                            (identifier "leb128_77")
                                            (seq (set-vec (u8 0) (identifier "p_ref_76") (identifier "leb128_snd_79"))
                                              (set-vec (u8 0) (identifier "leb_ref_74")
                                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_78") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_75"))) (unsafe-nth (u8 0) (identifier "leb_ref_74"))))
                                              (set-vec (u8 0) (identifier "shft_ref_75") (add (unsafe-nth (u8 0) (identifier "shft_ref_75")) (u8 7))) 
                                              (ge (identifier "leb128_fst_78") (u8 128))))) 
                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_74"))) (unsafe-nth (u8 0) (identifier "p_ref_76")))))))
                              (let-pair "dstring1_fst_81" "dstring1_snd_82" 
                                (identifier "dstring1_80")
                                (let-pair "dstring2_fst_84" "dstring2_snd_85" 
                                  (read-bytes (identifier "dstring1_snd_82") (identifier "dstring1_fst_81")) 
                                  (make-tup (string-of-bytes (identifier "dstring2_fst_84")) (identifier "dstring2_snd_85")))))
                            (let-pair "dtup_fst_87" "dtup_snd_88" (identifier "dtup_86")
                              (let-pair "dtup_fst_123" "dtup_snd_124"
                                (let "dsum1_95" (let-pair "du16_fst_90" "du16_snd_91" (read-u16 little-endian (identifier "dtup_snd_88")) (make-tup (identifier "du16_fst_90") (identifier "du16_snd_91")))
                                  (let-pair "dsum1_fst_96" "dsum1_snd_97" 
                                    (identifier "dsum1_95")
                                    (if (eq (u16 0) (identifier "dsum1_fst_96"))
                                      (make-tup (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 0 (nop))
                                        (identifier "dsum1_snd_97"))
                                      (if (eq (u16 1) (identifier "dsum1_fst_96"))
                                        (make-tup (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 1 (nop))
                                          (identifier "dsum1_snd_97"))
                                        (if (eq (u16 2) (identifier "dsum1_fst_96"))
                                          (make-tup (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 2 (nop))
                                            (identifier "dsum1_snd_97"))
                                          (if (eq (u16 3) (identifier "dsum1_fst_96"))
                                            (make-tup (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 3 (nop))
                                              (identifier "dsum1_snd_97"))
                                            (if (eq (u16 4) (identifier "dsum1_fst_96"))
                                              (make-tup
                                                (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 4 (nop))
                                                (identifier "dsum1_snd_97"))
                                              (if (eq (u16 5) (identifier "dsum1_fst_96"))
                                                (make-tup
                                                  (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 5 (nop))
                                                  (identifier "dsum1_snd_97"))
                                                (if (eq (u16 6) (identifier "dsum1_fst_96"))
                                                  (make-tup
                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 6 (nop))
                                                    (identifier "dsum1_snd_97"))
                                                  (seq (assert (eq (identifier "dsum1_fst_96") (u16 7)))
                                                    (make-tup
                                                      (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 7 (nop))
                                                      (identifier "dsum1_snd_97"))))))))))))
                                (make-tup
                                  (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 6
                                    (make-tup (identifier "dtup_fst_87") (identifier "dtup_fst_123"))) 
                                  (identifier "dtup_snd_124")))))
                          (if (eq (u16 7) (identifier "dsum1_fst_63"))
                            (let-pair "du32_fst_69" "du32_snd_70" (read-u32 little-endian (identifier "dsum1_snd_64"))
                              (make-tup
                                (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 7
                                  (identifier "du32_fst_69")) (identifier "du32_snd_70")))
                            (seq (assert (eq (identifier "dsum1_fst_63") (u16 8)))
                              (make-tup
                                (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 8
                                  (nop)) (identifier "dsum1_snd_64"))))))))))))) 
        (make-tup (identifier "make_fst_147") (identifier "make_snd_148"))))
 */
static std::function<::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e(Pointer)> per_worker_data_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e(Pointer)> fun1982 { [&fun1982](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1983 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1984;
    {
      auto du16_fst_57 { std::get<0>(id_1983) };
      auto du16_snd_58 { std::get<1>(id_1983) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1985 { du16_fst_57, du16_snd_58 };
      letpair_res_1984 = id_1985;
    }
    ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e let_res_1986;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_1984 };
      ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e letpair_res_1987;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_1988 { 0 };
        bool id_1989 { bool(id_1988 == dsum1_fst_63) };
        ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e choose_res_1990;
        if (id_1989) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_1991 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_1992 { id_1991, dsum1_snd_64 };
          choose_res_1990 = id_1992;
        } else {
          uint16_t id_1993 { 1 };
          bool id_1994 { bool(id_1993 == dsum1_fst_63) };
          ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e choose_res_1995;
          if (id_1994) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_1996 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_1997 { id_1996, dsum1_snd_64 };
            choose_res_1995 = id_1997;
          } else {
            uint16_t id_1998 { 2 };
            bool id_1999 { bool(id_1998 == dsum1_fst_63) };
            ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e choose_res_2000;
            if (id_1999) {
              (void)::dessser::VOID;
              std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2001 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<2>, ::dessser::VOID) };
              ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_2002 { id_2001, dsum1_snd_64 };
              choose_res_2000 = id_2002;
            } else {
              uint16_t id_2003 { 3 };
              bool id_2004 { bool(id_2003 == dsum1_fst_63) };
              ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e choose_res_2005;
              if (id_2004) {
                (void)::dessser::VOID;
                std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2006 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<3>, ::dessser::VOID) };
                ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_2007 { id_2006, dsum1_snd_64 };
                choose_res_2005 = id_2007;
              } else {
                uint16_t id_2008 { 4 };
                bool id_2009 { bool(id_2008 == dsum1_fst_63) };
                ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e choose_res_2010;
                if (id_2009) {
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2011 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<4>, ::dessser::VOID) };
                  ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_2012 { id_2011, dsum1_snd_64 };
                  choose_res_2010 = id_2012;
                } else {
                  uint16_t id_2013 { 5 };
                  bool id_2014 { bool(id_2013 == dsum1_fst_63) };
                  ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e choose_res_2015;
                  if (id_2014) {
                    (void)::dessser::VOID;
                    std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2016 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<5>, ::dessser::VOID) };
                    ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_2017 { id_2016, dsum1_snd_64 };
                    choose_res_2015 = id_2017;
                  } else {
                    uint16_t id_2018 { 6 };
                    bool id_2019 { bool(id_2018 == dsum1_fst_63) };
                    ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e choose_res_2020;
                    if (id_2019) {
                      uint32_t id_2021 { 0U };
                      Vec<1, uint32_t> id_2022 {  id_2021  };
                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2023;
                      {
                        Vec<1, uint32_t> leb_ref_74 { id_2022 };
                        uint8_t id_2024 { 0 };
                        Vec<1, uint8_t> id_2025 {  id_2024  };
                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2026;
                        {
                          Vec<1, uint8_t> shft_ref_75 { id_2025 };
                          Vec<1, Pointer> id_2027 {  dsum1_snd_64  };
                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2028;
                          {
                            Vec<1, Pointer> p_ref_76 { id_2027 };
                            bool while_flag_2029 { true };
                            do {
                              uint8_t id_2030 { 0 };
                              Pointer id_2031 { p_ref_76[id_2030] };
                              ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2032 { id_2031.readU8() };
                              bool let_res_2033;
                              {
                                ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_77 { id_2032 };
                                bool letpair_res_2034;
                                {
                                  auto leb128_fst_78 { std::get<0>(leb128_77) };
                                  auto leb128_snd_79 { std::get<1>(leb128_77) };
                                  uint8_t id_2035 { 0 };
                                  Void id_2036 { ((void)(p_ref_76[id_2035] = leb128_snd_79), ::dessser::VOID) };
                                  (void)id_2036;
                                  uint8_t id_2037 { 0 };
                                  uint8_t id_2038 { 127 };
                                  uint8_t id_2039 { uint8_t(leb128_fst_78 & id_2038) };
                                  uint32_t id_2040 { uint32_t(id_2039) };
                                  uint8_t id_2041 { 0 };
                                  uint8_t id_2042 { shft_ref_75[id_2041] };
                                  uint32_t id_2043 { uint32_t(id_2040 << id_2042) };
                                  uint8_t id_2044 { 0 };
                                  uint32_t id_2045 { leb_ref_74[id_2044] };
                                  uint32_t id_2046 { uint32_t(id_2043 | id_2045) };
                                  Void id_2047 { ((void)(leb_ref_74[id_2037] = id_2046), ::dessser::VOID) };
                                  (void)id_2047;
                                  uint8_t id_2048 { 0 };
                                  uint8_t id_2049 { 0 };
                                  uint8_t id_2050 { shft_ref_75[id_2049] };
                                  uint8_t id_2051 { 7 };
                                  uint8_t id_2052 { uint8_t(id_2050 + id_2051) };
                                  Void id_2053 { ((void)(shft_ref_75[id_2048] = id_2052), ::dessser::VOID) };
                                  (void)id_2053;
                                  uint8_t id_2054 { 128 };
                                  bool id_2055 { bool(leb128_fst_78 >= id_2054) };
                                  letpair_res_2034 = id_2055;
                                }
                                let_res_2033 = letpair_res_2034;
                              }
                              while_flag_2029 = let_res_2033;
                              if (while_flag_2029) {
                                (void)::dessser::VOID;
                              }
                            } while (while_flag_2029);
                            (void)::dessser::VOID;
                            uint8_t id_2056 { 0 };
                            uint32_t id_2057 { leb_ref_74[id_2056] };
                            Size id_2058 { Size(id_2057) };
                            uint8_t id_2059 { 0 };
                            Pointer id_2060 { p_ref_76[id_2059] };
                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2061 { id_2058, id_2060 };
                            let_res_2028 = id_2061;
                          }
                          let_res_2026 = let_res_2028;
                        }
                        let_res_2023 = let_res_2026;
                      }
                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2062;
                      {
                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_80 { let_res_2023 };
                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2063;
                        {
                          auto dstring1_fst_81 { std::get<0>(dstring1_80) };
                          auto dstring1_snd_82 { std::get<1>(dstring1_80) };
                          ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2064 { dstring1_snd_82.readBytes(dstring1_fst_81) };
                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2065;
                          {
                            auto dstring2_fst_84 { std::get<0>(id_2064) };
                            auto dstring2_snd_85 { std::get<1>(id_2064) };
                            std::string id_2066 { dstring2_fst_84.toString() };
                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2067 { id_2066, dstring2_snd_85 };
                            letpair_res_2065 = id_2067;
                          }
                          letpair_res_2063 = letpair_res_2065;
                        }
                        let_res_2062 = letpair_res_2063;
                      }
                      ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e let_res_2068;
                      {
                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_86 { let_res_2062 };
                        ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e letpair_res_2069;
                        {
                          auto dtup_fst_87 { std::get<0>(dtup_86) };
                          auto dtup_snd_88 { std::get<1>(dtup_86) };
                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2070 { dtup_snd_88.readU16Le() };
                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2071;
                          {
                            auto du16_fst_90 { std::get<0>(id_2070) };
                            auto du16_snd_91 { std::get<1>(id_2070) };
                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2072 { du16_fst_90, du16_snd_91 };
                            letpair_res_2071 = id_2072;
                          }
                          ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da let_res_2073;
                          {
                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_95 { letpair_res_2071 };
                            ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da letpair_res_2074;
                            {
                              auto dsum1_fst_96 { std::get<0>(dsum1_95) };
                              auto dsum1_snd_97 { std::get<1>(dsum1_95) };
                              uint16_t id_2075 { 0 };
                              bool id_2076 { bool(id_2075 == dsum1_fst_96) };
                              ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2077;
                              if (id_2076) {
                                (void)::dessser::VOID;
                                ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2078 { std::in_place_index<0>, ::dessser::VOID };
                                ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2079 { id_2078, dsum1_snd_97 };
                                choose_res_2077 = id_2079;
                              } else {
                                uint16_t id_2080 { 1 };
                                bool id_2081 { bool(id_2080 == dsum1_fst_96) };
                                ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2082;
                                if (id_2081) {
                                  (void)::dessser::VOID;
                                  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2083 { std::in_place_index<1>, ::dessser::VOID };
                                  ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2084 { id_2083, dsum1_snd_97 };
                                  choose_res_2082 = id_2084;
                                } else {
                                  uint16_t id_2085 { 2 };
                                  bool id_2086 { bool(id_2085 == dsum1_fst_96) };
                                  ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2087;
                                  if (id_2086) {
                                    (void)::dessser::VOID;
                                    ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2088 { std::in_place_index<2>, ::dessser::VOID };
                                    ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2089 { id_2088, dsum1_snd_97 };
                                    choose_res_2087 = id_2089;
                                  } else {
                                    uint16_t id_2090 { 3 };
                                    bool id_2091 { bool(id_2090 == dsum1_fst_96) };
                                    ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2092;
                                    if (id_2091) {
                                      (void)::dessser::VOID;
                                      ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2093 { std::in_place_index<3>, ::dessser::VOID };
                                      ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2094 { id_2093, dsum1_snd_97 };
                                      choose_res_2092 = id_2094;
                                    } else {
                                      uint16_t id_2095 { 4 };
                                      bool id_2096 { bool(id_2095 == dsum1_fst_96) };
                                      ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2097;
                                      if (id_2096) {
                                        (void)::dessser::VOID;
                                        ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2098 { std::in_place_index<4>, ::dessser::VOID };
                                        ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2099 { id_2098, dsum1_snd_97 };
                                        choose_res_2097 = id_2099;
                                      } else {
                                        uint16_t id_2100 { 5 };
                                        bool id_2101 { bool(id_2100 == dsum1_fst_96) };
                                        ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2102;
                                        if (id_2101) {
                                          (void)::dessser::VOID;
                                          ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2103 { std::in_place_index<5>, ::dessser::VOID };
                                          ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2104 { id_2103, dsum1_snd_97 };
                                          choose_res_2102 = id_2104;
                                        } else {
                                          uint16_t id_2105 { 6 };
                                          bool id_2106 { bool(id_2105 == dsum1_fst_96) };
                                          ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2107;
                                          if (id_2106) {
                                            (void)::dessser::VOID;
                                            ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2108 { std::in_place_index<6>, ::dessser::VOID };
                                            ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2109 { id_2108, dsum1_snd_97 };
                                            choose_res_2107 = id_2109;
                                          } else {
                                            uint16_t id_2110 { 7 };
                                            bool id_2111 { bool(dsum1_fst_96 == id_2110) };
                                            Void id_2112 { ((void)(assert(id_2111)), ::dessser::VOID) };
                                            (void)id_2112;
                                            (void)::dessser::VOID;
                                            ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2113 { std::in_place_index<7>, ::dessser::VOID };
                                            ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2114 { id_2113, dsum1_snd_97 };
                                            choose_res_2107 = id_2114;
                                          }
                                          choose_res_2102 = choose_res_2107;
                                        }
                                        choose_res_2097 = choose_res_2102;
                                      }
                                      choose_res_2092 = choose_res_2097;
                                    }
                                    choose_res_2087 = choose_res_2092;
                                  }
                                  choose_res_2082 = choose_res_2087;
                                }
                                choose_res_2077 = choose_res_2082;
                              }
                              letpair_res_2074 = choose_res_2077;
                            }
                            let_res_2073 = letpair_res_2074;
                          }
                          ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e letpair_res_2115;
                          {
                            auto dtup_fst_123 { std::get<0>(let_res_2073) };
                            auto dtup_snd_124 { std::get<1>(let_res_2073) };
                            ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_2116 { dtup_fst_87, dtup_fst_123 };
                            std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2117 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<6>, id_2116) };
                            ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_2118 { id_2117, dtup_snd_124 };
                            letpair_res_2115 = id_2118;
                          }
                          letpair_res_2069 = letpair_res_2115;
                        }
                        let_res_2068 = letpair_res_2069;
                      }
                      choose_res_2020 = let_res_2068;
                    } else {
                      uint16_t id_2119 { 7 };
                      bool id_2120 { bool(id_2119 == dsum1_fst_63) };
                      ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e choose_res_2121;
                      if (id_2120) {
                        ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_2122 { dsum1_snd_64.readU32Le() };
                        ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e letpair_res_2123;
                        {
                          auto du32_fst_69 { std::get<0>(id_2122) };
                          auto du32_snd_70 { std::get<1>(id_2122) };
                          std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2124 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<7>, du32_fst_69) };
                          ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_2125 { id_2124, du32_snd_70 };
                          letpair_res_2123 = id_2125;
                        }
                        choose_res_2121 = letpair_res_2123;
                      } else {
                        uint16_t id_2126 { 8 };
                        bool id_2127 { bool(dsum1_fst_63 == id_2126) };
                        Void id_2128 { ((void)(assert(id_2127)), ::dessser::VOID) };
                        (void)id_2128;
                        (void)::dessser::VOID;
                        std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2129 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<8>, ::dessser::VOID) };
                        ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_2130 { id_2129, dsum1_snd_64 };
                        choose_res_2121 = id_2130;
                      }
                      choose_res_2020 = choose_res_2121;
                    }
                    choose_res_2015 = choose_res_2020;
                  }
                  choose_res_2010 = choose_res_2015;
                }
                choose_res_2005 = choose_res_2010;
              }
              choose_res_2000 = choose_res_2005;
            }
            choose_res_1995 = choose_res_2000;
          }
          choose_res_1990 = choose_res_1995;
        }
        letpair_res_1987 = choose_res_1990;
      }
      let_res_1986 = letpair_res_1987;
    }
    ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e letpair_res_2131;
    {
      auto make_fst_147 { std::get<0>(let_res_1986) };
      auto make_snd_148 { std::get<1>(let_res_1986) };
      ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_2132 { make_fst_147, make_snd_148 };
      letpair_res_2131 = id_2132;
    }
    return letpair_res_2131;
  }
   };
  return fun1982;
}
std::function<::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e(Pointer)> per_worker_data_of_row_binary(per_worker_data_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_149" (apply (ext-identifier fq_name of-row-binary) (param 0))
        (let-pair "dtup_fst_150" "dtup_snd_151" (identifier "dtup_149")
          (let-pair "dtup_fst_153" "dtup_snd_154" (apply (identifier "per_worker_data-of-row-binary") (identifier "dtup_snd_151"))
            (make-tup (make-tup (identifier "dtup_fst_150") (identifier "dtup_fst_153")) (identifier "dtup_snd_154"))))))
 */
static std::function<::dessser::gen::sync_key::tff6c03fed00a106fb76636c5bf20ce1b(Pointer)> per_worker_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tff6c03fed00a106fb76636c5bf20ce1b(Pointer)> fun2133 { [&fun2133](Pointer p_0) {
    auto fun2134 { dessser::gen::fq_name::of_row_binary };
    ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e id_2135 { fun2134(p_0) };
    ::dessser::gen::sync_key::tff6c03fed00a106fb76636c5bf20ce1b let_res_2136;
    {
      ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e dtup_149 { id_2135 };
      ::dessser::gen::sync_key::tff6c03fed00a106fb76636c5bf20ce1b letpair_res_2137;
      {
        auto dtup_fst_150 { std::get<0>(dtup_149) };
        auto dtup_snd_151 { std::get<1>(dtup_149) };
        ::dessser::gen::sync_key::t90fc3b1be159c3c586c0a94783c9137e id_2138 { per_worker_data_of_row_binary(dtup_snd_151) };
        ::dessser::gen::sync_key::tff6c03fed00a106fb76636c5bf20ce1b letpair_res_2139;
        {
          auto dtup_fst_153 { std::get<0>(id_2138) };
          auto dtup_snd_154 { std::get<1>(id_2138) };
          std::shared_ptr<::dessser::gen::sync_key::per_worker>  id_2140 { std::make_shared<::dessser::gen::sync_key::per_worker>(dtup_fst_150, dtup_fst_153) };
          ::dessser::gen::sync_key::tff6c03fed00a106fb76636c5bf20ce1b id_2141 { id_2140, dtup_snd_154 };
          letpair_res_2139 = id_2141;
        }
        letpair_res_2137 = letpair_res_2139;
      }
      let_res_2136 = letpair_res_2137;
    }
    return let_res_2136;
  }
   };
  return fun2133;
}
std::function<::dessser::gen::sync_key::tff6c03fed00a106fb76636c5bf20ce1b(Pointer)> per_worker_of_row_binary(per_worker_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_243" "make_snd_244"
        (let "dsum1_164" (let-pair "du16_fst_159" "du16_snd_160" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_159") (identifier "du16_snd_160")))
          (let-pair "dsum1_fst_165" "dsum1_snd_166" (identifier "dsum1_164")
            (if (eq (u16 0) (identifier "dsum1_fst_165"))
              (make-tup
                (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 0
                  (nop)) (identifier "dsum1_snd_166"))
              (if (eq (u16 1) (identifier "dsum1_fst_165"))
                (let "dtup_215"
                  (let "dstring1_209"
                    (let "leb_ref_203" (make-vec (u32 0))
                      (let "shft_ref_204" (make-vec (u8 0))
                        (let "p_ref_205" (make-vec (identifier "dsum1_snd_166"))
                          (seq
                            (while
                              (let "leb128_206" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_205")))
                                (let-pair "leb128_fst_207" "leb128_snd_208" 
                                  (identifier "leb128_206")
                                  (seq (set-vec (u8 0) (identifier "p_ref_205") (identifier "leb128_snd_208"))
                                    (set-vec (u8 0) (identifier "leb_ref_203")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_207") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_204"))) (unsafe-nth (u8 0) (identifier "leb_ref_203"))))
                                    (set-vec (u8 0) (identifier "shft_ref_204") (add (unsafe-nth (u8 0) (identifier "shft_ref_204")) (u8 7))) 
                                    (ge (identifier "leb128_fst_207") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_203"))) (unsafe-nth (u8 0) (identifier "p_ref_205")))))))
                    (let-pair "dstring1_fst_210" "dstring1_snd_211" (identifier "dstring1_209")
                      (let-pair "dstring2_fst_213" "dstring2_snd_214" 
                        (read-bytes (identifier "dstring1_snd_211") (identifier "dstring1_fst_210")) 
                        (make-tup (string-of-bytes (identifier "dstring2_fst_213")) (identifier "dstring2_snd_214")))))
                  (let-pair "dtup_fst_216" "dtup_snd_217" (identifier "dtup_215")
                    (let-pair "dtup_fst_234" "dtup_snd_235"
                      (let "dsum1_224" (let-pair "du16_fst_219" "du16_snd_220" (read-u16 little-endian (identifier "dtup_snd_217")) (make-tup (identifier "du16_fst_219") (identifier "du16_snd_220")))
                        (let-pair "dsum1_fst_225" "dsum1_snd_226" (identifier "dsum1_224")
                          (if (eq (u16 0) (identifier "dsum1_fst_225")) 
                            (make-tup (construct "[Host Void | Port Void]" 0 (nop)) (identifier "dsum1_snd_226"))
                            (seq (assert (eq (identifier "dsum1_fst_225") (u16 1))) (make-tup (construct "[Host Void | Port Void]" 1 (nop)) (identifier "dsum1_snd_226"))))))
                      (make-tup
                        (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 1
                          (make-tup (identifier "dtup_fst_216") (identifier "dtup_fst_234"))) 
                        (identifier "dtup_snd_235")))))
                (if (eq (u16 2) (identifier "dsum1_fst_165"))
                  (let-pair "dsum2_fst_201" "dsum2_snd_202" (apply (identifier "per_worker-of-row-binary") (identifier "dsum1_snd_166"))
                    (make-tup
                      (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 2
                        (identifier "dsum2_fst_201")) (identifier "dsum2_snd_202")))
                  (seq (assert (eq (identifier "dsum1_fst_165") (u16 3)))
                    (let "dtup_179"
                      (let "dstring1_173"
                        (let "leb_ref_167" (make-vec (u32 0))
                          (let "shft_ref_168" (make-vec (u8 0))
                            (let "p_ref_169" (make-vec (identifier "dsum1_snd_166"))
                              (seq
                                (while
                                  (let "leb128_170" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_169")))
                                    (let-pair "leb128_fst_171" "leb128_snd_172" 
                                      (identifier "leb128_170")
                                      (seq (set-vec (u8 0) (identifier "p_ref_169") (identifier "leb128_snd_172"))
                                        (set-vec (u8 0) (identifier "leb_ref_167")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_171") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_168"))) (unsafe-nth (u8 0) (identifier "leb_ref_167"))))
                                        (set-vec (u8 0) (identifier "shft_ref_168") (add (unsafe-nth (u8 0) (identifier "shft_ref_168")) (u8 7))) 
                                        (ge (identifier "leb128_fst_171") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_167"))) (unsafe-nth (u8 0) (identifier "p_ref_169")))))))
                        (let-pair "dstring1_fst_174" "dstring1_snd_175" 
                          (identifier "dstring1_173")
                          (let-pair "dstring2_fst_177" "dstring2_snd_178" 
                            (read-bytes (identifier "dstring1_snd_175") (identifier "dstring1_fst_174")) 
                            (make-tup (string-of-bytes (identifier "dstring2_fst_177")) (identifier "dstring2_snd_178")))))
                      (let-pair "dtup_fst_180" "dtup_snd_181" (identifier "dtup_179")
                        (let "dsum1_188" (let-pair "du16_fst_183" "du16_snd_184" (read-u16 little-endian (identifier "dtup_snd_181")) (make-tup (identifier "du16_fst_183") (identifier "du16_snd_184")))
                          (let-pair "dsum1_fst_189" "dsum1_snd_190" (identifier "dsum1_188")
                            (seq (assert (eq (identifier "dsum1_fst_189") (u16 0)))
                              (make-tup
                                (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 3
                                  (make-tup (identifier "dtup_fst_180") (construct "[Executable Void]" 0 (nop)))) 
                                (identifier "dsum1_snd_190"))))))))))))) 
        (make-tup (identifier "make_fst_243") (identifier "make_snd_244"))))
 */
static std::function<::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1(Pointer)> per_site_data_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1(Pointer)> fun2142 { [&fun2142](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2143 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2144;
    {
      auto du16_fst_159 { std::get<0>(id_2143) };
      auto du16_snd_160 { std::get<1>(id_2143) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2145 { du16_fst_159, du16_snd_160 };
      letpair_res_2144 = id_2145;
    }
    ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 let_res_2146;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_164 { letpair_res_2144 };
      ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 letpair_res_2147;
      {
        auto dsum1_fst_165 { std::get<0>(dsum1_164) };
        auto dsum1_snd_166 { std::get<1>(dsum1_164) };
        uint16_t id_2148 { 0 };
        bool id_2149 { bool(id_2148 == dsum1_fst_165) };
        ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 choose_res_2150;
        if (id_2149) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2151 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 id_2152 { id_2151, dsum1_snd_166 };
          choose_res_2150 = id_2152;
        } else {
          uint16_t id_2153 { 1 };
          bool id_2154 { bool(id_2153 == dsum1_fst_165) };
          ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 choose_res_2155;
          if (id_2154) {
            uint32_t id_2156 { 0U };
            Vec<1, uint32_t> id_2157 {  id_2156  };
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2158;
            {
              Vec<1, uint32_t> leb_ref_203 { id_2157 };
              uint8_t id_2159 { 0 };
              Vec<1, uint8_t> id_2160 {  id_2159  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2161;
              {
                Vec<1, uint8_t> shft_ref_204 { id_2160 };
                Vec<1, Pointer> id_2162 {  dsum1_snd_166  };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2163;
                {
                  Vec<1, Pointer> p_ref_205 { id_2162 };
                  bool while_flag_2164 { true };
                  do {
                    uint8_t id_2165 { 0 };
                    Pointer id_2166 { p_ref_205[id_2165] };
                    ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2167 { id_2166.readU8() };
                    bool let_res_2168;
                    {
                      ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_206 { id_2167 };
                      bool letpair_res_2169;
                      {
                        auto leb128_fst_207 { std::get<0>(leb128_206) };
                        auto leb128_snd_208 { std::get<1>(leb128_206) };
                        uint8_t id_2170 { 0 };
                        Void id_2171 { ((void)(p_ref_205[id_2170] = leb128_snd_208), ::dessser::VOID) };
                        (void)id_2171;
                        uint8_t id_2172 { 0 };
                        uint8_t id_2173 { 127 };
                        uint8_t id_2174 { uint8_t(leb128_fst_207 & id_2173) };
                        uint32_t id_2175 { uint32_t(id_2174) };
                        uint8_t id_2176 { 0 };
                        uint8_t id_2177 { shft_ref_204[id_2176] };
                        uint32_t id_2178 { uint32_t(id_2175 << id_2177) };
                        uint8_t id_2179 { 0 };
                        uint32_t id_2180 { leb_ref_203[id_2179] };
                        uint32_t id_2181 { uint32_t(id_2178 | id_2180) };
                        Void id_2182 { ((void)(leb_ref_203[id_2172] = id_2181), ::dessser::VOID) };
                        (void)id_2182;
                        uint8_t id_2183 { 0 };
                        uint8_t id_2184 { 0 };
                        uint8_t id_2185 { shft_ref_204[id_2184] };
                        uint8_t id_2186 { 7 };
                        uint8_t id_2187 { uint8_t(id_2185 + id_2186) };
                        Void id_2188 { ((void)(shft_ref_204[id_2183] = id_2187), ::dessser::VOID) };
                        (void)id_2188;
                        uint8_t id_2189 { 128 };
                        bool id_2190 { bool(leb128_fst_207 >= id_2189) };
                        letpair_res_2169 = id_2190;
                      }
                      let_res_2168 = letpair_res_2169;
                    }
                    while_flag_2164 = let_res_2168;
                    if (while_flag_2164) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_2164);
                  (void)::dessser::VOID;
                  uint8_t id_2191 { 0 };
                  uint32_t id_2192 { leb_ref_203[id_2191] };
                  Size id_2193 { Size(id_2192) };
                  uint8_t id_2194 { 0 };
                  Pointer id_2195 { p_ref_205[id_2194] };
                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2196 { id_2193, id_2195 };
                  let_res_2163 = id_2196;
                }
                let_res_2161 = let_res_2163;
              }
              let_res_2158 = let_res_2161;
            }
            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2197;
            {
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_209 { let_res_2158 };
              ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2198;
              {
                auto dstring1_fst_210 { std::get<0>(dstring1_209) };
                auto dstring1_snd_211 { std::get<1>(dstring1_209) };
                ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2199 { dstring1_snd_211.readBytes(dstring1_fst_210) };
                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2200;
                {
                  auto dstring2_fst_213 { std::get<0>(id_2199) };
                  auto dstring2_snd_214 { std::get<1>(id_2199) };
                  std::string id_2201 { dstring2_fst_213.toString() };
                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2202 { id_2201, dstring2_snd_214 };
                  letpair_res_2200 = id_2202;
                }
                letpair_res_2198 = letpair_res_2200;
              }
              let_res_2197 = letpair_res_2198;
            }
            ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 let_res_2203;
            {
              ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_215 { let_res_2197 };
              ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 letpair_res_2204;
              {
                auto dtup_fst_216 { std::get<0>(dtup_215) };
                auto dtup_snd_217 { std::get<1>(dtup_215) };
                ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2205 { dtup_snd_217.readU16Le() };
                ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2206;
                {
                  auto du16_fst_219 { std::get<0>(id_2205) };
                  auto du16_snd_220 { std::get<1>(id_2205) };
                  ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2207 { du16_fst_219, du16_snd_220 };
                  letpair_res_2206 = id_2207;
                }
                ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e let_res_2208;
                {
                  ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_224 { letpair_res_2206 };
                  ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e letpair_res_2209;
                  {
                    auto dsum1_fst_225 { std::get<0>(dsum1_224) };
                    auto dsum1_snd_226 { std::get<1>(dsum1_224) };
                    uint16_t id_2210 { 0 };
                    bool id_2211 { bool(id_2210 == dsum1_fst_225) };
                    ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e choose_res_2212;
                    if (id_2211) {
                      (void)::dessser::VOID;
                      ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_2213 { std::in_place_index<0>, ::dessser::VOID };
                      ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e id_2214 { id_2213, dsum1_snd_226 };
                      choose_res_2212 = id_2214;
                    } else {
                      uint16_t id_2215 { 1 };
                      bool id_2216 { bool(dsum1_fst_225 == id_2215) };
                      Void id_2217 { ((void)(assert(id_2216)), ::dessser::VOID) };
                      (void)id_2217;
                      (void)::dessser::VOID;
                      ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_2218 { std::in_place_index<1>, ::dessser::VOID };
                      ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e id_2219 { id_2218, dsum1_snd_226 };
                      choose_res_2212 = id_2219;
                    }
                    letpair_res_2209 = choose_res_2212;
                  }
                  let_res_2208 = letpair_res_2209;
                }
                ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 letpair_res_2220;
                {
                  auto dtup_fst_234 { std::get<0>(let_res_2208) };
                  auto dtup_snd_235 { std::get<1>(let_res_2208) };
                  ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_2221 { dtup_fst_216, dtup_fst_234 };
                  std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2222 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<1>, id_2221) };
                  ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 id_2223 { id_2222, dtup_snd_235 };
                  letpair_res_2220 = id_2223;
                }
                letpair_res_2204 = letpair_res_2220;
              }
              let_res_2203 = letpair_res_2204;
            }
            choose_res_2155 = let_res_2203;
          } else {
            uint16_t id_2224 { 2 };
            bool id_2225 { bool(id_2224 == dsum1_fst_165) };
            ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 choose_res_2226;
            if (id_2225) {
              ::dessser::gen::sync_key::tff6c03fed00a106fb76636c5bf20ce1b id_2227 { per_worker_of_row_binary(dsum1_snd_166) };
              ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 letpair_res_2228;
              {
                auto dsum2_fst_201 { std::get<0>(id_2227) };
                auto dsum2_snd_202 { std::get<1>(id_2227) };
                std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2229 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<2>, dsum2_fst_201) };
                ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 id_2230 { id_2229, dsum2_snd_202 };
                letpair_res_2228 = id_2230;
              }
              choose_res_2226 = letpair_res_2228;
            } else {
              uint16_t id_2231 { 3 };
              bool id_2232 { bool(dsum1_fst_165 == id_2231) };
              Void id_2233 { ((void)(assert(id_2232)), ::dessser::VOID) };
              (void)id_2233;
              uint32_t id_2234 { 0U };
              Vec<1, uint32_t> id_2235 {  id_2234  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2236;
              {
                Vec<1, uint32_t> leb_ref_167 { id_2235 };
                uint8_t id_2237 { 0 };
                Vec<1, uint8_t> id_2238 {  id_2237  };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2239;
                {
                  Vec<1, uint8_t> shft_ref_168 { id_2238 };
                  Vec<1, Pointer> id_2240 {  dsum1_snd_166  };
                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2241;
                  {
                    Vec<1, Pointer> p_ref_169 { id_2240 };
                    bool while_flag_2242 { true };
                    do {
                      uint8_t id_2243 { 0 };
                      Pointer id_2244 { p_ref_169[id_2243] };
                      ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2245 { id_2244.readU8() };
                      bool let_res_2246;
                      {
                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_170 { id_2245 };
                        bool letpair_res_2247;
                        {
                          auto leb128_fst_171 { std::get<0>(leb128_170) };
                          auto leb128_snd_172 { std::get<1>(leb128_170) };
                          uint8_t id_2248 { 0 };
                          Void id_2249 { ((void)(p_ref_169[id_2248] = leb128_snd_172), ::dessser::VOID) };
                          (void)id_2249;
                          uint8_t id_2250 { 0 };
                          uint8_t id_2251 { 127 };
                          uint8_t id_2252 { uint8_t(leb128_fst_171 & id_2251) };
                          uint32_t id_2253 { uint32_t(id_2252) };
                          uint8_t id_2254 { 0 };
                          uint8_t id_2255 { shft_ref_168[id_2254] };
                          uint32_t id_2256 { uint32_t(id_2253 << id_2255) };
                          uint8_t id_2257 { 0 };
                          uint32_t id_2258 { leb_ref_167[id_2257] };
                          uint32_t id_2259 { uint32_t(id_2256 | id_2258) };
                          Void id_2260 { ((void)(leb_ref_167[id_2250] = id_2259), ::dessser::VOID) };
                          (void)id_2260;
                          uint8_t id_2261 { 0 };
                          uint8_t id_2262 { 0 };
                          uint8_t id_2263 { shft_ref_168[id_2262] };
                          uint8_t id_2264 { 7 };
                          uint8_t id_2265 { uint8_t(id_2263 + id_2264) };
                          Void id_2266 { ((void)(shft_ref_168[id_2261] = id_2265), ::dessser::VOID) };
                          (void)id_2266;
                          uint8_t id_2267 { 128 };
                          bool id_2268 { bool(leb128_fst_171 >= id_2267) };
                          letpair_res_2247 = id_2268;
                        }
                        let_res_2246 = letpair_res_2247;
                      }
                      while_flag_2242 = let_res_2246;
                      if (while_flag_2242) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_2242);
                    (void)::dessser::VOID;
                    uint8_t id_2269 { 0 };
                    uint32_t id_2270 { leb_ref_167[id_2269] };
                    Size id_2271 { Size(id_2270) };
                    uint8_t id_2272 { 0 };
                    Pointer id_2273 { p_ref_169[id_2272] };
                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2274 { id_2271, id_2273 };
                    let_res_2241 = id_2274;
                  }
                  let_res_2239 = let_res_2241;
                }
                let_res_2236 = let_res_2239;
              }
              ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2275;
              {
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_173 { let_res_2236 };
                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2276;
                {
                  auto dstring1_fst_174 { std::get<0>(dstring1_173) };
                  auto dstring1_snd_175 { std::get<1>(dstring1_173) };
                  ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2277 { dstring1_snd_175.readBytes(dstring1_fst_174) };
                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2278;
                  {
                    auto dstring2_fst_177 { std::get<0>(id_2277) };
                    auto dstring2_snd_178 { std::get<1>(id_2277) };
                    std::string id_2279 { dstring2_fst_177.toString() };
                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2280 { id_2279, dstring2_snd_178 };
                    letpair_res_2278 = id_2280;
                  }
                  letpair_res_2276 = letpair_res_2278;
                }
                let_res_2275 = letpair_res_2276;
              }
              ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 let_res_2281;
              {
                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_179 { let_res_2275 };
                ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 letpair_res_2282;
                {
                  auto dtup_fst_180 { std::get<0>(dtup_179) };
                  auto dtup_snd_181 { std::get<1>(dtup_179) };
                  ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2283 { dtup_snd_181.readU16Le() };
                  ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2284;
                  {
                    auto du16_fst_183 { std::get<0>(id_2283) };
                    auto du16_snd_184 { std::get<1>(id_2283) };
                    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2285 { du16_fst_183, du16_snd_184 };
                    letpair_res_2284 = id_2285;
                  }
                  ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 let_res_2286;
                  {
                    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_188 { letpair_res_2284 };
                    ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 letpair_res_2287;
                    {
                      auto dsum1_fst_189 { std::get<0>(dsum1_188) };
                      auto dsum1_snd_190 { std::get<1>(dsum1_188) };
                      uint16_t id_2288 { 0 };
                      bool id_2289 { bool(dsum1_fst_189 == id_2288) };
                      Void id_2290 { ((void)(assert(id_2289)), ::dessser::VOID) };
                      (void)id_2290;
                      (void)::dessser::VOID;
                      ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_2291 { std::in_place_index<0>, ::dessser::VOID };
                      ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_2292 { dtup_fst_180, id_2291 };
                      std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2293 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<3>, id_2292) };
                      ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 id_2294 { id_2293, dsum1_snd_190 };
                      letpair_res_2287 = id_2294;
                    }
                    let_res_2286 = letpair_res_2287;
                  }
                  letpair_res_2282 = let_res_2286;
                }
                let_res_2281 = letpair_res_2282;
              }
              choose_res_2226 = let_res_2281;
            }
            choose_res_2155 = choose_res_2226;
          }
          choose_res_2150 = choose_res_2155;
        }
        letpair_res_2147 = choose_res_2150;
      }
      let_res_2146 = letpair_res_2147;
    }
    ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 letpair_res_2295;
    {
      auto make_fst_243 { std::get<0>(let_res_2146) };
      auto make_snd_244 { std::get<1>(let_res_2146) };
      ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 id_2296 { make_fst_243, make_snd_244 };
      letpair_res_2295 = id_2296;
    }
    return letpair_res_2295;
  }
   };
  return fun2142;
}
std::function<::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1(Pointer)> per_site_data_of_row_binary(per_site_data_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_245" (apply (ext-identifier site_name of-row-binary) (param 0))
        (let-pair "dtup_fst_246" "dtup_snd_247" (identifier "dtup_245")
          (let-pair "dtup_fst_249" "dtup_snd_250" (apply (identifier "per_site_data-of-row-binary") (identifier "dtup_snd_247"))
            (make-tup (make-tup (identifier "dtup_fst_246") (identifier "dtup_fst_249")) (identifier "dtup_snd_250"))))))
 */
static std::function<::dessser::gen::sync_key::teeca16372f8ab8650d4d2918b4f32e88(Pointer)> per_site_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::teeca16372f8ab8650d4d2918b4f32e88(Pointer)> fun2297 { [&fun2297](Pointer p_0) {
    auto fun2298 { dessser::gen::site_name::of_row_binary };
    ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea id_2299 { fun2298(p_0) };
    ::dessser::gen::sync_key::teeca16372f8ab8650d4d2918b4f32e88 let_res_2300;
    {
      ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea dtup_245 { id_2299 };
      ::dessser::gen::sync_key::teeca16372f8ab8650d4d2918b4f32e88 letpair_res_2301;
      {
        auto dtup_fst_246 { std::get<0>(dtup_245) };
        auto dtup_snd_247 { std::get<1>(dtup_245) };
        ::dessser::gen::sync_key::t1e67a0abfbb837ff67a392b1e636c1b1 id_2302 { per_site_data_of_row_binary(dtup_snd_247) };
        ::dessser::gen::sync_key::teeca16372f8ab8650d4d2918b4f32e88 letpair_res_2303;
        {
          auto dtup_fst_249 { std::get<0>(id_2302) };
          auto dtup_snd_250 { std::get<1>(id_2302) };
          std::shared_ptr<::dessser::gen::sync_key::per_site>  id_2304 { std::make_shared<::dessser::gen::sync_key::per_site>(dtup_fst_246, dtup_fst_249) };
          ::dessser::gen::sync_key::teeca16372f8ab8650d4d2918b4f32e88 id_2305 { id_2304, dtup_snd_250 };
          letpair_res_2303 = id_2305;
        }
        letpair_res_2301 = letpair_res_2303;
      }
      let_res_2300 = letpair_res_2301;
    }
    return let_res_2300;
  }
   };
  return fun2297;
}
std::function<::dessser::gen::sync_key::teeca16372f8ab8650d4d2918b4f32e88(Pointer)> per_site_of_row_binary(per_site_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_660" "make_snd_661"
        (let "dsum1_341" (let-pair "du16_fst_336" "du16_snd_337" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_336") (identifier "du16_snd_337")))
          (let-pair "dsum1_fst_342" "dsum1_snd_343" (identifier "dsum1_341")
            (if (eq (u16 0) (identifier "dsum1_fst_342"))
              (make-tup
                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 0
                  (nop)) (identifier "dsum1_snd_343"))
              (if (eq (u16 1) (identifier "dsum1_fst_342"))
                (make-tup
                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 1
                    (nop)) (identifier "dsum1_snd_343"))
                (if (eq (u16 2) (identifier "dsum1_fst_342"))
                  (let "dstring1_644"
                    (let "leb_ref_638" (make-vec (u32 0))
                      (let "shft_ref_639" (make-vec (u8 0))
                        (let "p_ref_640" (make-vec (identifier "dsum1_snd_343"))
                          (seq
                            (while
                              (let "leb128_641" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_640")))
                                (let-pair "leb128_fst_642" "leb128_snd_643" 
                                  (identifier "leb128_641")
                                  (seq (set-vec (u8 0) (identifier "p_ref_640") (identifier "leb128_snd_643"))
                                    (set-vec (u8 0) (identifier "leb_ref_638")
                                      (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_642") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_639"))) (unsafe-nth (u8 0) (identifier "leb_ref_638"))))
                                    (set-vec (u8 0) (identifier "shft_ref_639") (add (unsafe-nth (u8 0) (identifier "shft_ref_639")) (u8 7))) 
                                    (ge (identifier "leb128_fst_642") (u8 128))))) 
                              (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_638"))) (unsafe-nth (u8 0) (identifier "p_ref_640")))))))
                    (let-pair "dstring1_fst_645" "dstring1_snd_646" (identifier "dstring1_644")
                      (let-pair "dstring2_fst_648" "dstring2_snd_649" 
                        (read-bytes (identifier "dstring1_snd_646") (identifier "dstring1_fst_645"))
                        (make-tup
                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 2
                            (string-of-bytes (identifier "dstring2_fst_648"))) 
                          (identifier "dstring2_snd_649")))))
                  (if (eq (u16 3) (identifier "dsum1_fst_342"))
                    (let "dtup_617" (apply (ext-identifier src_path of-row-binary) (identifier "dsum1_snd_343"))
                      (let-pair "dtup_fst_618" "dtup_snd_619" (identifier "dtup_617")
                        (let "dstring1_626"
                          (let "leb_ref_620" (make-vec (u32 0))
                            (let "shft_ref_621" (make-vec (u8 0))
                              (let "p_ref_622" (make-vec (identifier "dtup_snd_619"))
                                (seq
                                  (while
                                    (let "leb128_623" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_622")))
                                      (let-pair "leb128_fst_624" "leb128_snd_625" 
                                        (identifier "leb128_623")
                                        (seq (set-vec (u8 0) (identifier "p_ref_622") (identifier "leb128_snd_625"))
                                          (set-vec (u8 0) (identifier "leb_ref_620")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_624") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_621"))) (unsafe-nth (u8 0) (identifier "leb_ref_620"))))
                                          (set-vec (u8 0) (identifier "shft_ref_621") (add (unsafe-nth (u8 0) (identifier "shft_ref_621")) (u8 7))) 
                                          (ge (identifier "leb128_fst_624") (u8 128))))) 
                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_620"))) (unsafe-nth (u8 0) (identifier "p_ref_622")))))))
                          (let-pair "dstring1_fst_627" "dstring1_snd_628" 
                            (identifier "dstring1_626")
                            (let-pair "dstring2_fst_630" "dstring2_snd_631" 
                              (read-bytes (identifier "dstring1_snd_628") (identifier "dstring1_fst_627"))
                              (make-tup
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 3
                                  (make-tup (identifier "dtup_fst_618") (string-of-bytes (identifier "dstring2_fst_630")))) 
                                (identifier "dstring2_snd_631")))))))
                    (if (eq (u16 4) (identifier "dsum1_fst_342"))
                      (make-tup
                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 4
                          (nop)) (identifier "dsum1_snd_343"))
                      (if (eq (u16 5) (identifier "dsum1_fst_342"))
                        (let-pair "dsum2_fst_612" "dsum2_snd_613" (apply (identifier "per_site-of-row-binary") (identifier "dsum1_snd_343"))
                          (make-tup
                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 5
                              (identifier "dsum2_fst_612")) (identifier "dsum2_snd_613")))
                        (if (eq (u16 6) (identifier "dsum1_fst_342"))
                          (let-pair "dsum2_fst_609" "dsum2_snd_610"
                            (let "dsum1_584" (let-pair "du16_fst_579" "du16_snd_580" (read-u16 little-endian (identifier "dsum1_snd_343")) (make-tup (identifier "du16_fst_579") (identifier "du16_snd_580")))
                              (let-pair "dsum1_fst_585" "dsum1_snd_586" 
                                (identifier "dsum1_584")
                                (if (eq (u16 0) (identifier "dsum1_fst_585")) 
                                  (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 0 (nop)) (identifier "dsum1_snd_586"))
                                  (if (eq (u16 1) (identifier "dsum1_fst_585")) 
                                    (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 1 (nop)) (identifier "dsum1_snd_586"))
                                    (seq (assert (eq (identifier "dsum1_fst_585") (u16 2)))
                                      (let "dstring1_593"
                                        (let "leb_ref_587" (make-vec (u32 0))
                                          (let "shft_ref_588" (make-vec (u8 0))
                                            (let "p_ref_589" (make-vec (identifier "dsum1_snd_586"))
                                              (seq
                                                (while
                                                  (let "leb128_590" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_589")))
                                                    (let-pair "leb128_fst_591" "leb128_snd_592" 
                                                      (identifier "leb128_590")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_589") (identifier "leb128_snd_592"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_587")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_591") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_588")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_587")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_588") (add (unsafe-nth (u8 0) (identifier "shft_ref_588")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_591") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_587"))) (unsafe-nth (u8 0) (identifier "p_ref_589")))))))
                                        (let-pair "dstring1_fst_594" "dstring1_snd_595" 
                                          (identifier "dstring1_593")
                                          (let-pair "dstring2_fst_597" "dstring2_snd_598" 
                                            (read-bytes (identifier "dstring1_snd_595") (identifier "dstring1_fst_594"))
                                            (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 2 (string-of-bytes (identifier "dstring2_fst_597"))) (identifier "dstring2_snd_598"))))))))))
                            (make-tup
                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 6
                                (identifier "dsum2_fst_609")) (identifier "dsum2_snd_610")))
                          (if (eq (u16 7) (identifier "dsum1_fst_342"))
                            (let "dtup_551" (apply (ext-identifier site_name of-row-binary) (identifier "dsum1_snd_343"))
                              (let-pair "dtup_fst_552" "dtup_snd_553" 
                                (identifier "dtup_551")
                                (let "dtup_554" (apply (ext-identifier fq_name of-row-binary) (identifier "dtup_snd_553"))
                                  (let-pair "dtup_fst_555" "dtup_snd_556" 
                                    (identifier "dtup_554")
                                    (let "dtup_569"
                                      (let "dstring1_563"
                                        (let "leb_ref_557" (make-vec (u32 0))
                                          (let "shft_ref_558" (make-vec (u8 0))
                                            (let "p_ref_559" (make-vec (identifier "dtup_snd_556"))
                                              (seq
                                                (while
                                                  (let "leb128_560" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_559")))
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
                                        (let-pair "dtup_fst_573" "dtup_snd_574" 
                                          (apply (identifier "per_tail-of-row-binary") (identifier "dtup_snd_571"))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 7
                                              (make-tup (identifier "dtup_fst_552") (identifier "dtup_fst_555") (identifier "dtup_fst_570") (identifier "dtup_fst_573"))) 
                                            (identifier "dtup_snd_574")))))))))
                            (if (eq (u16 8) (identifier "dsum1_fst_342"))
                              (let-pair "du16_fst_546" "du16_snd_547" 
                                (read-u16 little-endian (identifier "dsum1_snd_343"))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 8
                                    (identifier "du16_fst_546")) (identifier "du16_snd_547")))
                              (if (eq (u16 9) (identifier "dsum1_fst_342"))
                                (let-pair "dsum2_fst_543" "dsum2_snd_544"
                                  (if (eq (peek-u8 (identifier "dsum1_snd_343") (size 0)) (u8 1)) 
                                    (make-tup (null "$sync_socket") (ptr-add (identifier "dsum1_snd_343") (size 1)))
                                    (let-pair "make1_1_fst_540" "make1_1_snd_541" 
                                      (apply (ext-identifier sync_socket of-row-binary) (ptr-add (identifier "dsum1_snd_343") (size 1))) 
                                      (make-tup (not-null (identifier "make1_1_fst_540")) (identifier "make1_1_snd_541"))))
                                  (make-tup
                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 9
                                      (identifier "dsum2_fst_543")) (identifier "dsum2_snd_544")))
                                (if (eq (u16 10) (identifier "dsum1_fst_342"))
                                  (make-tup
                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 10
                                      (nop)) (identifier "dsum1_snd_343"))
                                  (if (eq (u16 11) (identifier "dsum1_fst_342"))
                                    (let "dtup_527" (apply (ext-identifier sync_socket of-row-binary) (identifier "dsum1_snd_343"))
                                      (let-pair "dtup_fst_528" "dtup_snd_529" 
                                        (identifier "dtup_527")
                                        (let-pair "dtup_fst_531" "dtup_snd_532" 
                                          (apply (identifier "per_client-of-row-binary") (identifier "dtup_snd_529"))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 11
                                              (make-tup (identifier "dtup_fst_528") (identifier "dtup_fst_531"))) 
                                            (identifier "dtup_snd_532")))))
                                    (if (eq (u16 12) (identifier "dsum1_fst_342"))
                                      (let "dtup_518"
                                        (let "dstring1_512"
                                          (let "leb_ref_506" (make-vec (u32 0))
                                            (let "shft_ref_507" (make-vec (u8 0))
                                              (let "p_ref_508" (make-vec (identifier "dsum1_snd_343"))
                                                (seq
                                                  (while
                                                    (let "leb128_509" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_508")))
                                                      (let-pair "leb128_fst_510" "leb128_snd_511" 
                                                        (identifier "leb128_509")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_508") (identifier "leb128_snd_511"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_506")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_510") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_507")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_506")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_507") (add (unsafe-nth (u8 0) (identifier "shft_ref_507")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_510") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_506"))) (unsafe-nth (u8 0) (identifier "p_ref_508")))))))
                                          (let-pair "dstring1_fst_513" "dstring1_snd_514" 
                                            (identifier "dstring1_512")
                                            (let-pair "dstring2_fst_516" "dstring2_snd_517" 
                                              (read-bytes (identifier "dstring1_snd_514") (identifier "dstring1_fst_513")) 
                                              (make-tup (string-of-bytes (identifier "dstring2_fst_516")) (identifier "dstring2_snd_517")))))
                                        (let-pair "dtup_fst_519" "dtup_snd_520" 
                                          (identifier "dtup_518")
                                          (let-pair "dtup_fst_522" "dtup_snd_523" 
                                            (apply (identifier "per_dash_key-of-row-binary") (identifier "dtup_snd_520"))
                                            (make-tup
                                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 12
                                                (make-tup (identifier "dtup_fst_519") (identifier "dtup_fst_522"))) 
                                              (identifier "dtup_snd_523")))))
                                      (if (eq (u16 13) (identifier "dsum1_fst_342"))
                                        (make-tup
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 13
                                            (nop)) (identifier "dsum1_snd_343"))
                                        (if (eq (u16 14) (identifier "dsum1_fst_342"))
                                          (let "dtup_455" (apply (ext-identifier team_name of-row-binary) (identifier "dsum1_snd_343"))
                                            (let-pair "dtup_fst_456" "dtup_snd_457" 
                                              (identifier "dtup_455")
                                              (let-pair "dtup_fst_498" "dtup_snd_499"
                                                (let "dsum1_464" (let-pair "du16_fst_459" "du16_snd_460" (read-u16 little-endian (identifier "dtup_snd_457")) (make-tup (identifier "du16_fst_459") (identifier "du16_snd_460")))
                                                  (let-pair "dsum1_fst_465" "dsum1_snd_466" 
                                                    (identifier "dsum1_464")
                                                    (if (eq (u16 0) (identifier "dsum1_fst_465"))
                                                      (let "dstring1_488"
                                                        (let "leb_ref_482" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_483" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_484" 
                                                              (make-vec (identifier "dsum1_snd_466"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_485" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_484")))
                                                                    (let-pair "leb128_fst_486" "leb128_snd_487" 
                                                                    (identifier "leb128_485")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_484") (identifier "leb128_snd_487"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_482")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_486") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_483")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_482")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_483") (add (unsafe-nth (u8 0) (identifier "shft_ref_483")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_486") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_482"))) (unsafe-nth (u8 0) (identifier "p_ref_484")))))))
                                                        (let-pair "dstring1_fst_489" "dstring1_snd_490" 
                                                          (identifier "dstring1_488")
                                                          (let-pair "dstring2_fst_492" "dstring2_snd_493" 
                                                            (read-bytes (identifier "dstring1_snd_490") (identifier "dstring1_fst_489"))
                                                            (make-tup (construct "[Contacts STRING | Inhibition STRING]" 0 (string-of-bytes (identifier "dstring2_fst_492"))) (identifier "dstring2_snd_493")))))
                                                      (seq (assert (eq (identifier "dsum1_fst_465") (u16 1)))
                                                        (let "dstring1_473"
                                                          (let "leb_ref_467" 
                                                            (make-vec (u32 0))
                                                            (let "shft_ref_468" 
                                                              (make-vec (u8 0))
                                                              (let "p_ref_469" 
                                                                (make-vec (identifier "dsum1_snd_466"))
                                                                (seq
                                                                  (while
                                                                    (let "leb128_470" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_469")))
                                                                    (let-pair "leb128_fst_471" "leb128_snd_472" 
                                                                    (identifier "leb128_470")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_469") (identifier "leb128_snd_472"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_467")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_471") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_468")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_467")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_468") (add (unsafe-nth (u8 0) (identifier "shft_ref_468")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_471") (u8 128))))) 
                                                                    (nop)) 
                                                                  (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_467"))) (unsafe-nth (u8 0) (identifier "p_ref_469")))))))
                                                          (let-pair "dstring1_fst_474" "dstring1_snd_475" 
                                                            (identifier "dstring1_473")
                                                            (let-pair "dstring2_fst_477" "dstring2_snd_478" 
                                                              (read-bytes (identifier "dstring1_snd_475") (identifier "dstring1_fst_474"))
                                                              (make-tup (construct "[Contacts STRING | Inhibition STRING]" 1 (string-of-bytes (identifier "dstring2_fst_477"))) (identifier "dstring2_snd_478")))))))))
                                                (make-tup
                                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 14
                                                    (make-tup (identifier "dtup_fst_456") (identifier "dtup_fst_498"))) 
                                                  (identifier "dtup_snd_499")))))
                                          (seq (assert (eq (identifier "dsum1_fst_342") (u16 15)))
                                            (let "dtup_356"
                                              (let "dstring1_350"
                                                (let "leb_ref_344" (make-vec (u32 0))
                                                  (let "shft_ref_345" 
                                                    (make-vec (u8 0))
                                                    (let "p_ref_346" 
                                                      (make-vec (identifier "dsum1_snd_343"))
                                                      (seq
                                                        (while
                                                          (let "leb128_347" 
                                                            (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_346")))
                                                            (let-pair "leb128_fst_348" "leb128_snd_349" 
                                                              (identifier "leb128_347")
                                                              (seq (set-vec (u8 0) (identifier "p_ref_346") (identifier "leb128_snd_349"))
                                                                (set-vec 
                                                                  (u8 0) 
                                                                  (identifier "leb_ref_344")
                                                                  (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_348") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_345")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_344")))) 
                                                                (set-vec (u8 0) (identifier "shft_ref_345") (add (unsafe-nth (u8 0) (identifier "shft_ref_345")) (u8 7))) 
                                                                (ge (identifier "leb128_fst_348") (u8 128))))) 
                                                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_344"))) (unsafe-nth (u8 0) (identifier "p_ref_346")))))))
                                                (let-pair "dstring1_fst_351" "dstring1_snd_352" 
                                                  (identifier "dstring1_350")
                                                  (let-pair "dstring2_fst_354" "dstring2_snd_355" 
                                                    (read-bytes (identifier "dstring1_snd_352") (identifier "dstring1_fst_351")) 
                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_354")) (identifier "dstring2_snd_355")))))
                                              (let-pair "dtup_fst_357" "dtup_snd_358" 
                                                (identifier "dtup_356")
                                                (let-pair "dtup_fst_450" "dtup_snd_451"
                                                  (let "dsum1_365" (let-pair "du16_fst_360" "du16_snd_361" (read-u16 little-endian (identifier "dtup_snd_358")) (make-tup (identifier "du16_fst_360") (identifier "du16_snd_361")))
                                                    (let-pair "dsum1_fst_366" "dsum1_snd_367" 
                                                      (identifier "dsum1_365")
                                                      (if (eq (u16 0) (identifier "dsum1_fst_366"))
                                                        (make-tup
                                                          (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 0
                                                            (nop)) (identifier "dsum1_snd_367"))
                                                        (if (eq (u16 1) (identifier "dsum1_fst_366"))
                                                          (make-tup
                                                            (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 1
                                                              (nop)) 
                                                            (identifier "dsum1_snd_367"))
                                                          (if (eq (u16 2) (identifier "dsum1_fst_366"))
                                                            (make-tup
                                                              (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 2
                                                                (nop)) 
                                                              (identifier "dsum1_snd_367"))
                                                            (if (eq (u16 3) (identifier "dsum1_fst_366"))
                                                              (make-tup
                                                                (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 3
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_367"))
                                                              (if (eq (u16 4) (identifier "dsum1_fst_366"))
                                                                (make-tup
                                                                  (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 4
                                                                    (nop)) 
                                                                  (identifier "dsum1_snd_367"))
                                                                (if (eq (u16 5) (identifier "dsum1_fst_366"))
                                                                  (let "dtup_395"
                                                                    (let "dstring1_389"
                                                                    (let "leb_ref_383" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_384" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_385" 
                                                                    (make-vec (identifier "dsum1_snd_367"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_386" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_385")))
                                                                    (let-pair "leb128_fst_387" "leb128_snd_388" 
                                                                    (identifier "leb128_386")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_385") (identifier "leb128_snd_388"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_383")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_387") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_384")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_383")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_384") (add (unsafe-nth (u8 0) (identifier "shft_ref_384")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_387") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_383"))) (unsafe-nth (u8 0) (identifier "p_ref_385")))))))
                                                                    (let-pair "dstring1_fst_390" "dstring1_snd_391" 
                                                                    (identifier "dstring1_389")
                                                                    (let-pair "dstring2_fst_393" "dstring2_snd_394" 
                                                                    (read-bytes (identifier "dstring1_snd_391") (identifier "dstring1_fst_390"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_393")) (identifier "dstring2_snd_394")))))
                                                                    (let-pair "dtup_fst_396" "dtup_snd_397" 
                                                                    (identifier "dtup_395")
                                                                    (let-pair "dtup_fst_429" "dtup_snd_430"
                                                                    (let "dsum1_404"
                                                                    (let-pair "du16_fst_399" "du16_snd_400" (read-u16 little-endian (identifier "dtup_snd_397")) (make-tup (identifier "du16_fst_399") (identifier "du16_snd_400")))
                                                                    (let-pair "dsum1_fst_405" "dsum1_snd_406" 
                                                                    (identifier "dsum1_404")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_405"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 0
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_406"))
                                                                    (if 
                                                                    (eq (u16 1) (identifier "dsum1_fst_405"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 1
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_406"))
                                                                    (if 
                                                                    (eq (u16 2) (identifier "dsum1_fst_405"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 2
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_406"))
                                                                    (if 
                                                                    (eq (u16 3) (identifier "dsum1_fst_405"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 3
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_406"))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "dsum1_fst_405"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 4
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_406"))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "dsum1_fst_405"))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 5
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_406"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_405") (u16 6)))
                                                                    (make-tup
                                                                    (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 6
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_406")))))))))))
                                                                    (make-tup
                                                                    (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 5
                                                                    (make-tup (identifier "dtup_fst_396") (identifier "dtup_fst_429"))) 
                                                                    (identifier "dtup_snd_430")))))
                                                                  (seq 
                                                                    (assert (eq (identifier "dsum1_fst_366") (u16 6)))
                                                                    (let "dtup_371"
                                                                    (let-pair "dfloat_fst_369" "dfloat_snd_370" 
                                                                    (read-u64 little-endian (identifier "dsum1_snd_367")) 
                                                                    (make-tup (float-of-u64 (identifier "dfloat_fst_369")) (identifier "dfloat_snd_370")))
                                                                    (let-pair "dtup_fst_372" "dtup_snd_373" 
                                                                    (identifier "dtup_371")
                                                                    (let-pair "du32_fst_375" "du32_snd_376" 
                                                                    (read-u32 little-endian (identifier "dtup_snd_373"))
                                                                    (make-tup
                                                                    (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)]" 6
                                                                    (make-tup (identifier "dtup_fst_372") (identifier "du32_fst_375"))) 
                                                                    (identifier "du32_snd_376"))))))))))))))
                                                  (make-tup
                                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 15
                                                      (make-tup (identifier "dtup_fst_357") (identifier "dtup_fst_450"))) 
                                                    (identifier "dtup_snd_451"))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_660") (identifier "make_snd_661"))))
 */
static std::function<::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f(Pointer)> fun2306 { [&fun2306](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2307 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2308;
    {
      auto du16_fst_336 { std::get<0>(id_2307) };
      auto du16_snd_337 { std::get<1>(id_2307) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2309 { du16_fst_336, du16_snd_337 };
      letpair_res_2308 = id_2309;
    }
    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2310;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_341 { letpair_res_2308 };
      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2311;
      {
        auto dsum1_fst_342 { std::get<0>(dsum1_341) };
        auto dsum1_snd_343 { std::get<1>(dsum1_341) };
        uint16_t id_2312 { 0 };
        bool id_2313 { bool(id_2312 == dsum1_fst_342) };
        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2314;
        if (id_2313) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::t>  id_2315 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2316 { id_2315, dsum1_snd_343 };
          choose_res_2314 = id_2316;
        } else {
          uint16_t id_2317 { 1 };
          bool id_2318 { bool(id_2317 == dsum1_fst_342) };
          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2319;
          if (id_2318) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::sync_key::t>  id_2320 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2321 { id_2320, dsum1_snd_343 };
            choose_res_2319 = id_2321;
          } else {
            uint16_t id_2322 { 2 };
            bool id_2323 { bool(id_2322 == dsum1_fst_342) };
            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2324;
            if (id_2323) {
              uint32_t id_2325 { 0U };
              Vec<1, uint32_t> id_2326 {  id_2325  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2327;
              {
                Vec<1, uint32_t> leb_ref_638 { id_2326 };
                uint8_t id_2328 { 0 };
                Vec<1, uint8_t> id_2329 {  id_2328  };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2330;
                {
                  Vec<1, uint8_t> shft_ref_639 { id_2329 };
                  Vec<1, Pointer> id_2331 {  dsum1_snd_343  };
                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2332;
                  {
                    Vec<1, Pointer> p_ref_640 { id_2331 };
                    bool while_flag_2333 { true };
                    do {
                      uint8_t id_2334 { 0 };
                      Pointer id_2335 { p_ref_640[id_2334] };
                      ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2336 { id_2335.readU8() };
                      bool let_res_2337;
                      {
                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_641 { id_2336 };
                        bool letpair_res_2338;
                        {
                          auto leb128_fst_642 { std::get<0>(leb128_641) };
                          auto leb128_snd_643 { std::get<1>(leb128_641) };
                          uint8_t id_2339 { 0 };
                          Void id_2340 { ((void)(p_ref_640[id_2339] = leb128_snd_643), ::dessser::VOID) };
                          (void)id_2340;
                          uint8_t id_2341 { 0 };
                          uint8_t id_2342 { 127 };
                          uint8_t id_2343 { uint8_t(leb128_fst_642 & id_2342) };
                          uint32_t id_2344 { uint32_t(id_2343) };
                          uint8_t id_2345 { 0 };
                          uint8_t id_2346 { shft_ref_639[id_2345] };
                          uint32_t id_2347 { uint32_t(id_2344 << id_2346) };
                          uint8_t id_2348 { 0 };
                          uint32_t id_2349 { leb_ref_638[id_2348] };
                          uint32_t id_2350 { uint32_t(id_2347 | id_2349) };
                          Void id_2351 { ((void)(leb_ref_638[id_2341] = id_2350), ::dessser::VOID) };
                          (void)id_2351;
                          uint8_t id_2352 { 0 };
                          uint8_t id_2353 { 0 };
                          uint8_t id_2354 { shft_ref_639[id_2353] };
                          uint8_t id_2355 { 7 };
                          uint8_t id_2356 { uint8_t(id_2354 + id_2355) };
                          Void id_2357 { ((void)(shft_ref_639[id_2352] = id_2356), ::dessser::VOID) };
                          (void)id_2357;
                          uint8_t id_2358 { 128 };
                          bool id_2359 { bool(leb128_fst_642 >= id_2358) };
                          letpair_res_2338 = id_2359;
                        }
                        let_res_2337 = letpair_res_2338;
                      }
                      while_flag_2333 = let_res_2337;
                      if (while_flag_2333) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_2333);
                    (void)::dessser::VOID;
                    uint8_t id_2360 { 0 };
                    uint32_t id_2361 { leb_ref_638[id_2360] };
                    Size id_2362 { Size(id_2361) };
                    uint8_t id_2363 { 0 };
                    Pointer id_2364 { p_ref_640[id_2363] };
                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2365 { id_2362, id_2364 };
                    let_res_2332 = id_2365;
                  }
                  let_res_2330 = let_res_2332;
                }
                let_res_2327 = let_res_2330;
              }
              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2366;
              {
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_644 { let_res_2327 };
                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2367;
                {
                  auto dstring1_fst_645 { std::get<0>(dstring1_644) };
                  auto dstring1_snd_646 { std::get<1>(dstring1_644) };
                  ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2368 { dstring1_snd_646.readBytes(dstring1_fst_645) };
                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2369;
                  {
                    auto dstring2_fst_648 { std::get<0>(id_2368) };
                    auto dstring2_snd_649 { std::get<1>(id_2368) };
                    std::string id_2370 { dstring2_fst_648.toString() };
                    std::shared_ptr<::dessser::gen::sync_key::t>  id_2371 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<2>, id_2370) };
                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2372 { id_2371, dstring2_snd_649 };
                    letpair_res_2369 = id_2372;
                  }
                  letpair_res_2367 = letpair_res_2369;
                }
                let_res_2366 = letpair_res_2367;
              }
              choose_res_2324 = let_res_2366;
            } else {
              uint16_t id_2373 { 3 };
              bool id_2374 { bool(id_2373 == dsum1_fst_342) };
              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2375;
              if (id_2374) {
                auto fun2376 { dessser::gen::src_path::of_row_binary };
                ::dessser::gen::sync_key::t6886b6ff042edb771f45016f12178bb0 id_2377 { fun2376(dsum1_snd_343) };
                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2378;
                {
                  ::dessser::gen::sync_key::t6886b6ff042edb771f45016f12178bb0 dtup_617 { id_2377 };
                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2379;
                  {
                    auto dtup_fst_618 { std::get<0>(dtup_617) };
                    auto dtup_snd_619 { std::get<1>(dtup_617) };
                    uint32_t id_2380 { 0U };
                    Vec<1, uint32_t> id_2381 {  id_2380  };
                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2382;
                    {
                      Vec<1, uint32_t> leb_ref_620 { id_2381 };
                      uint8_t id_2383 { 0 };
                      Vec<1, uint8_t> id_2384 {  id_2383  };
                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2385;
                      {
                        Vec<1, uint8_t> shft_ref_621 { id_2384 };
                        Vec<1, Pointer> id_2386 {  dtup_snd_619  };
                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2387;
                        {
                          Vec<1, Pointer> p_ref_622 { id_2386 };
                          bool while_flag_2388 { true };
                          do {
                            uint8_t id_2389 { 0 };
                            Pointer id_2390 { p_ref_622[id_2389] };
                            ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2391 { id_2390.readU8() };
                            bool let_res_2392;
                            {
                              ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_623 { id_2391 };
                              bool letpair_res_2393;
                              {
                                auto leb128_fst_624 { std::get<0>(leb128_623) };
                                auto leb128_snd_625 { std::get<1>(leb128_623) };
                                uint8_t id_2394 { 0 };
                                Void id_2395 { ((void)(p_ref_622[id_2394] = leb128_snd_625), ::dessser::VOID) };
                                (void)id_2395;
                                uint8_t id_2396 { 0 };
                                uint8_t id_2397 { 127 };
                                uint8_t id_2398 { uint8_t(leb128_fst_624 & id_2397) };
                                uint32_t id_2399 { uint32_t(id_2398) };
                                uint8_t id_2400 { 0 };
                                uint8_t id_2401 { shft_ref_621[id_2400] };
                                uint32_t id_2402 { uint32_t(id_2399 << id_2401) };
                                uint8_t id_2403 { 0 };
                                uint32_t id_2404 { leb_ref_620[id_2403] };
                                uint32_t id_2405 { uint32_t(id_2402 | id_2404) };
                                Void id_2406 { ((void)(leb_ref_620[id_2396] = id_2405), ::dessser::VOID) };
                                (void)id_2406;
                                uint8_t id_2407 { 0 };
                                uint8_t id_2408 { 0 };
                                uint8_t id_2409 { shft_ref_621[id_2408] };
                                uint8_t id_2410 { 7 };
                                uint8_t id_2411 { uint8_t(id_2409 + id_2410) };
                                Void id_2412 { ((void)(shft_ref_621[id_2407] = id_2411), ::dessser::VOID) };
                                (void)id_2412;
                                uint8_t id_2413 { 128 };
                                bool id_2414 { bool(leb128_fst_624 >= id_2413) };
                                letpair_res_2393 = id_2414;
                              }
                              let_res_2392 = letpair_res_2393;
                            }
                            while_flag_2388 = let_res_2392;
                            if (while_flag_2388) {
                              (void)::dessser::VOID;
                            }
                          } while (while_flag_2388);
                          (void)::dessser::VOID;
                          uint8_t id_2415 { 0 };
                          uint32_t id_2416 { leb_ref_620[id_2415] };
                          Size id_2417 { Size(id_2416) };
                          uint8_t id_2418 { 0 };
                          Pointer id_2419 { p_ref_622[id_2418] };
                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2420 { id_2417, id_2419 };
                          let_res_2387 = id_2420;
                        }
                        let_res_2385 = let_res_2387;
                      }
                      let_res_2382 = let_res_2385;
                    }
                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2421;
                    {
                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_626 { let_res_2382 };
                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2422;
                      {
                        auto dstring1_fst_627 { std::get<0>(dstring1_626) };
                        auto dstring1_snd_628 { std::get<1>(dstring1_626) };
                        ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2423 { dstring1_snd_628.readBytes(dstring1_fst_627) };
                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2424;
                        {
                          auto dstring2_fst_630 { std::get<0>(id_2423) };
                          auto dstring2_snd_631 { std::get<1>(id_2423) };
                          std::string id_2425 { dstring2_fst_630.toString() };
                          ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_2426 { dtup_fst_618, id_2425 };
                          std::shared_ptr<::dessser::gen::sync_key::t>  id_2427 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<3>, id_2426) };
                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2428 { id_2427, dstring2_snd_631 };
                          letpair_res_2424 = id_2428;
                        }
                        letpair_res_2422 = letpair_res_2424;
                      }
                      let_res_2421 = letpair_res_2422;
                    }
                    letpair_res_2379 = let_res_2421;
                  }
                  let_res_2378 = letpair_res_2379;
                }
                choose_res_2375 = let_res_2378;
              } else {
                uint16_t id_2429 { 4 };
                bool id_2430 { bool(id_2429 == dsum1_fst_342) };
                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2431;
                if (id_2430) {
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::sync_key::t>  id_2432 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<4>, ::dessser::VOID) };
                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2433 { id_2432, dsum1_snd_343 };
                  choose_res_2431 = id_2433;
                } else {
                  uint16_t id_2434 { 5 };
                  bool id_2435 { bool(id_2434 == dsum1_fst_342) };
                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2436;
                  if (id_2435) {
                    ::dessser::gen::sync_key::teeca16372f8ab8650d4d2918b4f32e88 id_2437 { per_site_of_row_binary(dsum1_snd_343) };
                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2438;
                    {
                      auto dsum2_fst_612 { std::get<0>(id_2437) };
                      auto dsum2_snd_613 { std::get<1>(id_2437) };
                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2439 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<5>, dsum2_fst_612) };
                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2440 { id_2439, dsum2_snd_613 };
                      letpair_res_2438 = id_2440;
                    }
                    choose_res_2436 = letpair_res_2438;
                  } else {
                    uint16_t id_2441 { 6 };
                    bool id_2442 { bool(id_2441 == dsum1_fst_342) };
                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2443;
                    if (id_2442) {
                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2444 { dsum1_snd_343.readU16Le() };
                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2445;
                      {
                        auto du16_fst_579 { std::get<0>(id_2444) };
                        auto du16_snd_580 { std::get<1>(id_2444) };
                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2446 { du16_fst_579, du16_snd_580 };
                        letpair_res_2445 = id_2446;
                      }
                      ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b let_res_2447;
                      {
                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_584 { letpair_res_2445 };
                        ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b letpair_res_2448;
                        {
                          auto dsum1_fst_585 { std::get<0>(dsum1_584) };
                          auto dsum1_snd_586 { std::get<1>(dsum1_584) };
                          uint16_t id_2449 { 0 };
                          bool id_2450 { bool(id_2449 == dsum1_fst_585) };
                          ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b choose_res_2451;
                          if (id_2450) {
                            (void)::dessser::VOID;
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2452 { std::in_place_index<0>, ::dessser::VOID };
                            ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b id_2453 { id_2452, dsum1_snd_586 };
                            choose_res_2451 = id_2453;
                          } else {
                            uint16_t id_2454 { 1 };
                            bool id_2455 { bool(id_2454 == dsum1_fst_585) };
                            ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b choose_res_2456;
                            if (id_2455) {
                              (void)::dessser::VOID;
                              ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2457 { std::in_place_index<1>, ::dessser::VOID };
                              ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b id_2458 { id_2457, dsum1_snd_586 };
                              choose_res_2456 = id_2458;
                            } else {
                              uint16_t id_2459 { 2 };
                              bool id_2460 { bool(dsum1_fst_585 == id_2459) };
                              Void id_2461 { ((void)(assert(id_2460)), ::dessser::VOID) };
                              (void)id_2461;
                              uint32_t id_2462 { 0U };
                              Vec<1, uint32_t> id_2463 {  id_2462  };
                              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2464;
                              {
                                Vec<1, uint32_t> leb_ref_587 { id_2463 };
                                uint8_t id_2465 { 0 };
                                Vec<1, uint8_t> id_2466 {  id_2465  };
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2467;
                                {
                                  Vec<1, uint8_t> shft_ref_588 { id_2466 };
                                  Vec<1, Pointer> id_2468 {  dsum1_snd_586  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2469;
                                  {
                                    Vec<1, Pointer> p_ref_589 { id_2468 };
                                    bool while_flag_2470 { true };
                                    do {
                                      uint8_t id_2471 { 0 };
                                      Pointer id_2472 { p_ref_589[id_2471] };
                                      ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2473 { id_2472.readU8() };
                                      bool let_res_2474;
                                      {
                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_590 { id_2473 };
                                        bool letpair_res_2475;
                                        {
                                          auto leb128_fst_591 { std::get<0>(leb128_590) };
                                          auto leb128_snd_592 { std::get<1>(leb128_590) };
                                          uint8_t id_2476 { 0 };
                                          Void id_2477 { ((void)(p_ref_589[id_2476] = leb128_snd_592), ::dessser::VOID) };
                                          (void)id_2477;
                                          uint8_t id_2478 { 0 };
                                          uint8_t id_2479 { 127 };
                                          uint8_t id_2480 { uint8_t(leb128_fst_591 & id_2479) };
                                          uint32_t id_2481 { uint32_t(id_2480) };
                                          uint8_t id_2482 { 0 };
                                          uint8_t id_2483 { shft_ref_588[id_2482] };
                                          uint32_t id_2484 { uint32_t(id_2481 << id_2483) };
                                          uint8_t id_2485 { 0 };
                                          uint32_t id_2486 { leb_ref_587[id_2485] };
                                          uint32_t id_2487 { uint32_t(id_2484 | id_2486) };
                                          Void id_2488 { ((void)(leb_ref_587[id_2478] = id_2487), ::dessser::VOID) };
                                          (void)id_2488;
                                          uint8_t id_2489 { 0 };
                                          uint8_t id_2490 { 0 };
                                          uint8_t id_2491 { shft_ref_588[id_2490] };
                                          uint8_t id_2492 { 7 };
                                          uint8_t id_2493 { uint8_t(id_2491 + id_2492) };
                                          Void id_2494 { ((void)(shft_ref_588[id_2489] = id_2493), ::dessser::VOID) };
                                          (void)id_2494;
                                          uint8_t id_2495 { 128 };
                                          bool id_2496 { bool(leb128_fst_591 >= id_2495) };
                                          letpair_res_2475 = id_2496;
                                        }
                                        let_res_2474 = letpair_res_2475;
                                      }
                                      while_flag_2470 = let_res_2474;
                                      if (while_flag_2470) {
                                        (void)::dessser::VOID;
                                      }
                                    } while (while_flag_2470);
                                    (void)::dessser::VOID;
                                    uint8_t id_2497 { 0 };
                                    uint32_t id_2498 { leb_ref_587[id_2497] };
                                    Size id_2499 { Size(id_2498) };
                                    uint8_t id_2500 { 0 };
                                    Pointer id_2501 { p_ref_589[id_2500] };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2502 { id_2499, id_2501 };
                                    let_res_2469 = id_2502;
                                  }
                                  let_res_2467 = let_res_2469;
                                }
                                let_res_2464 = let_res_2467;
                              }
                              ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b let_res_2503;
                              {
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_593 { let_res_2464 };
                                ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b letpair_res_2504;
                                {
                                  auto dstring1_fst_594 { std::get<0>(dstring1_593) };
                                  auto dstring1_snd_595 { std::get<1>(dstring1_593) };
                                  ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2505 { dstring1_snd_595.readBytes(dstring1_fst_594) };
                                  ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b letpair_res_2506;
                                  {
                                    auto dstring2_fst_597 { std::get<0>(id_2505) };
                                    auto dstring2_snd_598 { std::get<1>(id_2505) };
                                    std::string id_2507 { dstring2_fst_597.toString() };
                                    ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2508 { std::in_place_index<2>, id_2507 };
                                    ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b id_2509 { id_2508, dstring2_snd_598 };
                                    letpair_res_2506 = id_2509;
                                  }
                                  letpair_res_2504 = letpair_res_2506;
                                }
                                let_res_2503 = letpair_res_2504;
                              }
                              choose_res_2456 = let_res_2503;
                            }
                            choose_res_2451 = choose_res_2456;
                          }
                          letpair_res_2448 = choose_res_2451;
                        }
                        let_res_2447 = letpair_res_2448;
                      }
                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2510;
                      {
                        auto dsum2_fst_609 { std::get<0>(let_res_2447) };
                        auto dsum2_snd_610 { std::get<1>(let_res_2447) };
                        std::shared_ptr<::dessser::gen::sync_key::t>  id_2511 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<6>, dsum2_fst_609) };
                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2512 { id_2511, dsum2_snd_610 };
                        letpair_res_2510 = id_2512;
                      }
                      choose_res_2443 = letpair_res_2510;
                    } else {
                      uint16_t id_2513 { 7 };
                      bool id_2514 { bool(id_2513 == dsum1_fst_342) };
                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2515;
                      if (id_2514) {
                        auto fun2516 { dessser::gen::site_name::of_row_binary };
                        ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea id_2517 { fun2516(dsum1_snd_343) };
                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2518;
                        {
                          ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea dtup_551 { id_2517 };
                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2519;
                          {
                            auto dtup_fst_552 { std::get<0>(dtup_551) };
                            auto dtup_snd_553 { std::get<1>(dtup_551) };
                            auto fun2520 { dessser::gen::fq_name::of_row_binary };
                            ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e id_2521 { fun2520(dtup_snd_553) };
                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2522;
                            {
                              ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e dtup_554 { id_2521 };
                              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2523;
                              {
                                auto dtup_fst_555 { std::get<0>(dtup_554) };
                                auto dtup_snd_556 { std::get<1>(dtup_554) };
                                uint32_t id_2524 { 0U };
                                Vec<1, uint32_t> id_2525 {  id_2524  };
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2526;
                                {
                                  Vec<1, uint32_t> leb_ref_557 { id_2525 };
                                  uint8_t id_2527 { 0 };
                                  Vec<1, uint8_t> id_2528 {  id_2527  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2529;
                                  {
                                    Vec<1, uint8_t> shft_ref_558 { id_2528 };
                                    Vec<1, Pointer> id_2530 {  dtup_snd_556  };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2531;
                                    {
                                      Vec<1, Pointer> p_ref_559 { id_2530 };
                                      bool while_flag_2532 { true };
                                      do {
                                        uint8_t id_2533 { 0 };
                                        Pointer id_2534 { p_ref_559[id_2533] };
                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2535 { id_2534.readU8() };
                                        bool let_res_2536;
                                        {
                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_560 { id_2535 };
                                          bool letpair_res_2537;
                                          {
                                            auto leb128_fst_561 { std::get<0>(leb128_560) };
                                            auto leb128_snd_562 { std::get<1>(leb128_560) };
                                            uint8_t id_2538 { 0 };
                                            Void id_2539 { ((void)(p_ref_559[id_2538] = leb128_snd_562), ::dessser::VOID) };
                                            (void)id_2539;
                                            uint8_t id_2540 { 0 };
                                            uint8_t id_2541 { 127 };
                                            uint8_t id_2542 { uint8_t(leb128_fst_561 & id_2541) };
                                            uint32_t id_2543 { uint32_t(id_2542) };
                                            uint8_t id_2544 { 0 };
                                            uint8_t id_2545 { shft_ref_558[id_2544] };
                                            uint32_t id_2546 { uint32_t(id_2543 << id_2545) };
                                            uint8_t id_2547 { 0 };
                                            uint32_t id_2548 { leb_ref_557[id_2547] };
                                            uint32_t id_2549 { uint32_t(id_2546 | id_2548) };
                                            Void id_2550 { ((void)(leb_ref_557[id_2540] = id_2549), ::dessser::VOID) };
                                            (void)id_2550;
                                            uint8_t id_2551 { 0 };
                                            uint8_t id_2552 { 0 };
                                            uint8_t id_2553 { shft_ref_558[id_2552] };
                                            uint8_t id_2554 { 7 };
                                            uint8_t id_2555 { uint8_t(id_2553 + id_2554) };
                                            Void id_2556 { ((void)(shft_ref_558[id_2551] = id_2555), ::dessser::VOID) };
                                            (void)id_2556;
                                            uint8_t id_2557 { 128 };
                                            bool id_2558 { bool(leb128_fst_561 >= id_2557) };
                                            letpair_res_2537 = id_2558;
                                          }
                                          let_res_2536 = letpair_res_2537;
                                        }
                                        while_flag_2532 = let_res_2536;
                                        if (while_flag_2532) {
                                          (void)::dessser::VOID;
                                        }
                                      } while (while_flag_2532);
                                      (void)::dessser::VOID;
                                      uint8_t id_2559 { 0 };
                                      uint32_t id_2560 { leb_ref_557[id_2559] };
                                      Size id_2561 { Size(id_2560) };
                                      uint8_t id_2562 { 0 };
                                      Pointer id_2563 { p_ref_559[id_2562] };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2564 { id_2561, id_2563 };
                                      let_res_2531 = id_2564;
                                    }
                                    let_res_2529 = let_res_2531;
                                  }
                                  let_res_2526 = let_res_2529;
                                }
                                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2565;
                                {
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_563 { let_res_2526 };
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2566;
                                  {
                                    auto dstring1_fst_564 { std::get<0>(dstring1_563) };
                                    auto dstring1_snd_565 { std::get<1>(dstring1_563) };
                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2567 { dstring1_snd_565.readBytes(dstring1_fst_564) };
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2568;
                                    {
                                      auto dstring2_fst_567 { std::get<0>(id_2567) };
                                      auto dstring2_snd_568 { std::get<1>(id_2567) };
                                      std::string id_2569 { dstring2_fst_567.toString() };
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2570 { id_2569, dstring2_snd_568 };
                                      letpair_res_2568 = id_2570;
                                    }
                                    letpair_res_2566 = letpair_res_2568;
                                  }
                                  let_res_2565 = letpair_res_2566;
                                }
                                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2571;
                                {
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_569 { let_res_2565 };
                                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2572;
                                  {
                                    auto dtup_fst_570 { std::get<0>(dtup_569) };
                                    auto dtup_snd_571 { std::get<1>(dtup_569) };
                                    ::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d id_2573 { per_tail_of_row_binary(dtup_snd_571) };
                                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2574;
                                    {
                                      auto dtup_fst_573 { std::get<0>(id_2573) };
                                      auto dtup_snd_574 { std::get<1>(id_2573) };
                                      ::dessser::gen::sync_key::te552b116666bdac4ad5a96694c71efca id_2575 { dtup_fst_552, dtup_fst_555, dtup_fst_570, dtup_fst_573 };
                                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2576 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<7>, id_2575) };
                                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2577 { id_2576, dtup_snd_574 };
                                      letpair_res_2574 = id_2577;
                                    }
                                    letpair_res_2572 = letpair_res_2574;
                                  }
                                  let_res_2571 = letpair_res_2572;
                                }
                                letpair_res_2523 = let_res_2571;
                              }
                              let_res_2522 = letpair_res_2523;
                            }
                            letpair_res_2519 = let_res_2522;
                          }
                          let_res_2518 = letpair_res_2519;
                        }
                        choose_res_2515 = let_res_2518;
                      } else {
                        uint16_t id_2578 { 8 };
                        bool id_2579 { bool(id_2578 == dsum1_fst_342) };
                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2580;
                        if (id_2579) {
                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2581 { dsum1_snd_343.readU16Le() };
                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2582;
                          {
                            auto du16_fst_546 { std::get<0>(id_2581) };
                            auto du16_snd_547 { std::get<1>(id_2581) };
                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2583 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<8>, du16_fst_546) };
                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2584 { id_2583, du16_snd_547 };
                            letpair_res_2582 = id_2584;
                          }
                          choose_res_2580 = letpair_res_2582;
                        } else {
                          uint16_t id_2585 { 9 };
                          bool id_2586 { bool(id_2585 == dsum1_fst_342) };
                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2587;
                          if (id_2586) {
                            Size id_2588 { 0UL };
                            uint8_t id_2589 { dsum1_snd_343.peekU8(id_2588) };
                            uint8_t id_2590 { 1 };
                            bool id_2591 { bool(id_2589 == id_2590) };
                            ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 choose_res_2592;
                            if (id_2591) {
                              std::optional<dessser::gen::sync_socket::t_ext> id_2593 { std::nullopt };
                              Size id_2594 { 1UL };
                              Pointer id_2595 { dsum1_snd_343.skip(id_2594) };
                              ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 id_2596 { id_2593, id_2595 };
                              choose_res_2592 = id_2596;
                            } else {
                              auto fun2597 { dessser::gen::sync_socket::of_row_binary };
                              Size id_2598 { 1UL };
                              Pointer id_2599 { dsum1_snd_343.skip(id_2598) };
                              ::dessser::gen::sync_key::t8a365991c4a4591932e21c9e1eeeab20 id_2600 { fun2597(id_2599) };
                              ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 letpair_res_2601;
                              {
                                auto make1_1_fst_540 { std::get<0>(id_2600) };
                                auto make1_1_snd_541 { std::get<1>(id_2600) };
                                std::optional<dessser::gen::sync_socket::t_ext> id_2602 { make1_1_fst_540 };
                                ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 id_2603 { id_2602, make1_1_snd_541 };
                                letpair_res_2601 = id_2603;
                              }
                              choose_res_2592 = letpair_res_2601;
                            }
                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2604;
                            {
                              auto dsum2_fst_543 { std::get<0>(choose_res_2592) };
                              auto dsum2_snd_544 { std::get<1>(choose_res_2592) };
                              std::shared_ptr<::dessser::gen::sync_key::t>  id_2605 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<9>, dsum2_fst_543) };
                              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2606 { id_2605, dsum2_snd_544 };
                              letpair_res_2604 = id_2606;
                            }
                            choose_res_2587 = letpair_res_2604;
                          } else {
                            uint16_t id_2607 { 10 };
                            bool id_2608 { bool(id_2607 == dsum1_fst_342) };
                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2609;
                            if (id_2608) {
                              (void)::dessser::VOID;
                              std::shared_ptr<::dessser::gen::sync_key::t>  id_2610 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<10>, ::dessser::VOID) };
                              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2611 { id_2610, dsum1_snd_343 };
                              choose_res_2609 = id_2611;
                            } else {
                              uint16_t id_2612 { 11 };
                              bool id_2613 { bool(id_2612 == dsum1_fst_342) };
                              ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2614;
                              if (id_2613) {
                                auto fun2615 { dessser::gen::sync_socket::of_row_binary };
                                ::dessser::gen::sync_key::t8a365991c4a4591932e21c9e1eeeab20 id_2616 { fun2615(dsum1_snd_343) };
                                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2617;
                                {
                                  ::dessser::gen::sync_key::t8a365991c4a4591932e21c9e1eeeab20 dtup_527 { id_2616 };
                                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2618;
                                  {
                                    auto dtup_fst_528 { std::get<0>(dtup_527) };
                                    auto dtup_snd_529 { std::get<1>(dtup_527) };
                                    ::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9 id_2619 { per_client_of_row_binary(dtup_snd_529) };
                                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2620;
                                    {
                                      auto dtup_fst_531 { std::get<0>(id_2619) };
                                      auto dtup_snd_532 { std::get<1>(id_2619) };
                                      ::dessser::gen::sync_key::t4ce2d4679665698c8b564907b52837ef id_2621 { dtup_fst_528, dtup_fst_531 };
                                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2622 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<11>, id_2621) };
                                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2623 { id_2622, dtup_snd_532 };
                                      letpair_res_2620 = id_2623;
                                    }
                                    letpair_res_2618 = letpair_res_2620;
                                  }
                                  let_res_2617 = letpair_res_2618;
                                }
                                choose_res_2614 = let_res_2617;
                              } else {
                                uint16_t id_2624 { 12 };
                                bool id_2625 { bool(id_2624 == dsum1_fst_342) };
                                ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2626;
                                if (id_2625) {
                                  uint32_t id_2627 { 0U };
                                  Vec<1, uint32_t> id_2628 {  id_2627  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2629;
                                  {
                                    Vec<1, uint32_t> leb_ref_506 { id_2628 };
                                    uint8_t id_2630 { 0 };
                                    Vec<1, uint8_t> id_2631 {  id_2630  };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2632;
                                    {
                                      Vec<1, uint8_t> shft_ref_507 { id_2631 };
                                      Vec<1, Pointer> id_2633 {  dsum1_snd_343  };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2634;
                                      {
                                        Vec<1, Pointer> p_ref_508 { id_2633 };
                                        bool while_flag_2635 { true };
                                        do {
                                          uint8_t id_2636 { 0 };
                                          Pointer id_2637 { p_ref_508[id_2636] };
                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2638 { id_2637.readU8() };
                                          bool let_res_2639;
                                          {
                                            ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_509 { id_2638 };
                                            bool letpair_res_2640;
                                            {
                                              auto leb128_fst_510 { std::get<0>(leb128_509) };
                                              auto leb128_snd_511 { std::get<1>(leb128_509) };
                                              uint8_t id_2641 { 0 };
                                              Void id_2642 { ((void)(p_ref_508[id_2641] = leb128_snd_511), ::dessser::VOID) };
                                              (void)id_2642;
                                              uint8_t id_2643 { 0 };
                                              uint8_t id_2644 { 127 };
                                              uint8_t id_2645 { uint8_t(leb128_fst_510 & id_2644) };
                                              uint32_t id_2646 { uint32_t(id_2645) };
                                              uint8_t id_2647 { 0 };
                                              uint8_t id_2648 { shft_ref_507[id_2647] };
                                              uint32_t id_2649 { uint32_t(id_2646 << id_2648) };
                                              uint8_t id_2650 { 0 };
                                              uint32_t id_2651 { leb_ref_506[id_2650] };
                                              uint32_t id_2652 { uint32_t(id_2649 | id_2651) };
                                              Void id_2653 { ((void)(leb_ref_506[id_2643] = id_2652), ::dessser::VOID) };
                                              (void)id_2653;
                                              uint8_t id_2654 { 0 };
                                              uint8_t id_2655 { 0 };
                                              uint8_t id_2656 { shft_ref_507[id_2655] };
                                              uint8_t id_2657 { 7 };
                                              uint8_t id_2658 { uint8_t(id_2656 + id_2657) };
                                              Void id_2659 { ((void)(shft_ref_507[id_2654] = id_2658), ::dessser::VOID) };
                                              (void)id_2659;
                                              uint8_t id_2660 { 128 };
                                              bool id_2661 { bool(leb128_fst_510 >= id_2660) };
                                              letpair_res_2640 = id_2661;
                                            }
                                            let_res_2639 = letpair_res_2640;
                                          }
                                          while_flag_2635 = let_res_2639;
                                          if (while_flag_2635) {
                                            (void)::dessser::VOID;
                                          }
                                        } while (while_flag_2635);
                                        (void)::dessser::VOID;
                                        uint8_t id_2662 { 0 };
                                        uint32_t id_2663 { leb_ref_506[id_2662] };
                                        Size id_2664 { Size(id_2663) };
                                        uint8_t id_2665 { 0 };
                                        Pointer id_2666 { p_ref_508[id_2665] };
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2667 { id_2664, id_2666 };
                                        let_res_2634 = id_2667;
                                      }
                                      let_res_2632 = let_res_2634;
                                    }
                                    let_res_2629 = let_res_2632;
                                  }
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2668;
                                  {
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_512 { let_res_2629 };
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2669;
                                    {
                                      auto dstring1_fst_513 { std::get<0>(dstring1_512) };
                                      auto dstring1_snd_514 { std::get<1>(dstring1_512) };
                                      ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2670 { dstring1_snd_514.readBytes(dstring1_fst_513) };
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2671;
                                      {
                                        auto dstring2_fst_516 { std::get<0>(id_2670) };
                                        auto dstring2_snd_517 { std::get<1>(id_2670) };
                                        std::string id_2672 { dstring2_fst_516.toString() };
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2673 { id_2672, dstring2_snd_517 };
                                        letpair_res_2671 = id_2673;
                                      }
                                      letpair_res_2669 = letpair_res_2671;
                                    }
                                    let_res_2668 = letpair_res_2669;
                                  }
                                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2674;
                                  {
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_518 { let_res_2668 };
                                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2675;
                                    {
                                      auto dtup_fst_519 { std::get<0>(dtup_518) };
                                      auto dtup_snd_520 { std::get<1>(dtup_518) };
                                      ::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c id_2676 { per_dash_key_of_row_binary(dtup_snd_520) };
                                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2677;
                                      {
                                        auto dtup_fst_522 { std::get<0>(id_2676) };
                                        auto dtup_snd_523 { std::get<1>(id_2676) };
                                        ::dessser::gen::sync_key::tfac19990b99b6207810e41e57c01fbc1 id_2678 { dtup_fst_519, dtup_fst_522 };
                                        std::shared_ptr<::dessser::gen::sync_key::t>  id_2679 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<12>, id_2678) };
                                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2680 { id_2679, dtup_snd_523 };
                                        letpair_res_2677 = id_2680;
                                      }
                                      letpair_res_2675 = letpair_res_2677;
                                    }
                                    let_res_2674 = letpair_res_2675;
                                  }
                                  choose_res_2626 = let_res_2674;
                                } else {
                                  uint16_t id_2681 { 13 };
                                  bool id_2682 { bool(id_2681 == dsum1_fst_342) };
                                  ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2683;
                                  if (id_2682) {
                                    (void)::dessser::VOID;
                                    std::shared_ptr<::dessser::gen::sync_key::t>  id_2684 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<13>, ::dessser::VOID) };
                                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2685 { id_2684, dsum1_snd_343 };
                                    choose_res_2683 = id_2685;
                                  } else {
                                    uint16_t id_2686 { 14 };
                                    bool id_2687 { bool(id_2686 == dsum1_fst_342) };
                                    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f choose_res_2688;
                                    if (id_2687) {
                                      auto fun2689 { dessser::gen::team_name::of_row_binary };
                                      ::dessser::gen::sync_key::t165bfb5c86a2d73d290e190e229b1fb1 id_2690 { fun2689(dsum1_snd_343) };
                                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2691;
                                      {
                                        ::dessser::gen::sync_key::t165bfb5c86a2d73d290e190e229b1fb1 dtup_455 { id_2690 };
                                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2692;
                                        {
                                          auto dtup_fst_456 { std::get<0>(dtup_455) };
                                          auto dtup_snd_457 { std::get<1>(dtup_455) };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2693 { dtup_snd_457.readU16Le() };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2694;
                                          {
                                            auto du16_fst_459 { std::get<0>(id_2693) };
                                            auto du16_snd_460 { std::get<1>(id_2693) };
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2695 { du16_fst_459, du16_snd_460 };
                                            letpair_res_2694 = id_2695;
                                          }
                                          ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 let_res_2696;
                                          {
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_464 { letpair_res_2694 };
                                            ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2697;
                                            {
                                              auto dsum1_fst_465 { std::get<0>(dsum1_464) };
                                              auto dsum1_snd_466 { std::get<1>(dsum1_464) };
                                              uint16_t id_2698 { 0 };
                                              bool id_2699 { bool(id_2698 == dsum1_fst_465) };
                                              ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 choose_res_2700;
                                              if (id_2699) {
                                                uint32_t id_2701 { 0U };
                                                Vec<1, uint32_t> id_2702 {  id_2701  };
                                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2703;
                                                {
                                                  Vec<1, uint32_t> leb_ref_482 { id_2702 };
                                                  uint8_t id_2704 { 0 };
                                                  Vec<1, uint8_t> id_2705 {  id_2704  };
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2706;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_483 { id_2705 };
                                                    Vec<1, Pointer> id_2707 {  dsum1_snd_466  };
                                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2708;
                                                    {
                                                      Vec<1, Pointer> p_ref_484 { id_2707 };
                                                      bool while_flag_2709 { true };
                                                      do {
                                                        uint8_t id_2710 { 0 };
                                                        Pointer id_2711 { p_ref_484[id_2710] };
                                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2712 { id_2711.readU8() };
                                                        bool let_res_2713;
                                                        {
                                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_485 { id_2712 };
                                                          bool letpair_res_2714;
                                                          {
                                                            auto leb128_fst_486 { std::get<0>(leb128_485) };
                                                            auto leb128_snd_487 { std::get<1>(leb128_485) };
                                                            uint8_t id_2715 { 0 };
                                                            Void id_2716 { ((void)(p_ref_484[id_2715] = leb128_snd_487), ::dessser::VOID) };
                                                            (void)id_2716;
                                                            uint8_t id_2717 { 0 };
                                                            uint8_t id_2718 { 127 };
                                                            uint8_t id_2719 { uint8_t(leb128_fst_486 & id_2718) };
                                                            uint32_t id_2720 { uint32_t(id_2719) };
                                                            uint8_t id_2721 { 0 };
                                                            uint8_t id_2722 { shft_ref_483[id_2721] };
                                                            uint32_t id_2723 { uint32_t(id_2720 << id_2722) };
                                                            uint8_t id_2724 { 0 };
                                                            uint32_t id_2725 { leb_ref_482[id_2724] };
                                                            uint32_t id_2726 { uint32_t(id_2723 | id_2725) };
                                                            Void id_2727 { ((void)(leb_ref_482[id_2717] = id_2726), ::dessser::VOID) };
                                                            (void)id_2727;
                                                            uint8_t id_2728 { 0 };
                                                            uint8_t id_2729 { 0 };
                                                            uint8_t id_2730 { shft_ref_483[id_2729] };
                                                            uint8_t id_2731 { 7 };
                                                            uint8_t id_2732 { uint8_t(id_2730 + id_2731) };
                                                            Void id_2733 { ((void)(shft_ref_483[id_2728] = id_2732), ::dessser::VOID) };
                                                            (void)id_2733;
                                                            uint8_t id_2734 { 128 };
                                                            bool id_2735 { bool(leb128_fst_486 >= id_2734) };
                                                            letpair_res_2714 = id_2735;
                                                          }
                                                          let_res_2713 = letpair_res_2714;
                                                        }
                                                        while_flag_2709 = let_res_2713;
                                                        if (while_flag_2709) {
                                                          (void)::dessser::VOID;
                                                        }
                                                      } while (while_flag_2709);
                                                      (void)::dessser::VOID;
                                                      uint8_t id_2736 { 0 };
                                                      uint32_t id_2737 { leb_ref_482[id_2736] };
                                                      Size id_2738 { Size(id_2737) };
                                                      uint8_t id_2739 { 0 };
                                                      Pointer id_2740 { p_ref_484[id_2739] };
                                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2741 { id_2738, id_2740 };
                                                      let_res_2708 = id_2741;
                                                    }
                                                    let_res_2706 = let_res_2708;
                                                  }
                                                  let_res_2703 = let_res_2706;
                                                }
                                                ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 let_res_2742;
                                                {
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_488 { let_res_2703 };
                                                  ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2743;
                                                  {
                                                    auto dstring1_fst_489 { std::get<0>(dstring1_488) };
                                                    auto dstring1_snd_490 { std::get<1>(dstring1_488) };
                                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2744 { dstring1_snd_490.readBytes(dstring1_fst_489) };
                                                    ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2745;
                                                    {
                                                      auto dstring2_fst_492 { std::get<0>(id_2744) };
                                                      auto dstring2_snd_493 { std::get<1>(id_2744) };
                                                      std::string id_2746 { dstring2_fst_492.toString() };
                                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_2747 { std::in_place_index<0>, id_2746 };
                                                      ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 id_2748 { id_2747, dstring2_snd_493 };
                                                      letpair_res_2745 = id_2748;
                                                    }
                                                    letpair_res_2743 = letpair_res_2745;
                                                  }
                                                  let_res_2742 = letpair_res_2743;
                                                }
                                                choose_res_2700 = let_res_2742;
                                              } else {
                                                uint16_t id_2749 { 1 };
                                                bool id_2750 { bool(dsum1_fst_465 == id_2749) };
                                                Void id_2751 { ((void)(assert(id_2750)), ::dessser::VOID) };
                                                (void)id_2751;
                                                uint32_t id_2752 { 0U };
                                                Vec<1, uint32_t> id_2753 {  id_2752  };
                                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2754;
                                                {
                                                  Vec<1, uint32_t> leb_ref_467 { id_2753 };
                                                  uint8_t id_2755 { 0 };
                                                  Vec<1, uint8_t> id_2756 {  id_2755  };
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2757;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_468 { id_2756 };
                                                    Vec<1, Pointer> id_2758 {  dsum1_snd_466  };
                                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2759;
                                                    {
                                                      Vec<1, Pointer> p_ref_469 { id_2758 };
                                                      bool while_flag_2760 { true };
                                                      do {
                                                        uint8_t id_2761 { 0 };
                                                        Pointer id_2762 { p_ref_469[id_2761] };
                                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2763 { id_2762.readU8() };
                                                        bool let_res_2764;
                                                        {
                                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_470 { id_2763 };
                                                          bool letpair_res_2765;
                                                          {
                                                            auto leb128_fst_471 { std::get<0>(leb128_470) };
                                                            auto leb128_snd_472 { std::get<1>(leb128_470) };
                                                            uint8_t id_2766 { 0 };
                                                            Void id_2767 { ((void)(p_ref_469[id_2766] = leb128_snd_472), ::dessser::VOID) };
                                                            (void)id_2767;
                                                            uint8_t id_2768 { 0 };
                                                            uint8_t id_2769 { 127 };
                                                            uint8_t id_2770 { uint8_t(leb128_fst_471 & id_2769) };
                                                            uint32_t id_2771 { uint32_t(id_2770) };
                                                            uint8_t id_2772 { 0 };
                                                            uint8_t id_2773 { shft_ref_468[id_2772] };
                                                            uint32_t id_2774 { uint32_t(id_2771 << id_2773) };
                                                            uint8_t id_2775 { 0 };
                                                            uint32_t id_2776 { leb_ref_467[id_2775] };
                                                            uint32_t id_2777 { uint32_t(id_2774 | id_2776) };
                                                            Void id_2778 { ((void)(leb_ref_467[id_2768] = id_2777), ::dessser::VOID) };
                                                            (void)id_2778;
                                                            uint8_t id_2779 { 0 };
                                                            uint8_t id_2780 { 0 };
                                                            uint8_t id_2781 { shft_ref_468[id_2780] };
                                                            uint8_t id_2782 { 7 };
                                                            uint8_t id_2783 { uint8_t(id_2781 + id_2782) };
                                                            Void id_2784 { ((void)(shft_ref_468[id_2779] = id_2783), ::dessser::VOID) };
                                                            (void)id_2784;
                                                            uint8_t id_2785 { 128 };
                                                            bool id_2786 { bool(leb128_fst_471 >= id_2785) };
                                                            letpair_res_2765 = id_2786;
                                                          }
                                                          let_res_2764 = letpair_res_2765;
                                                        }
                                                        while_flag_2760 = let_res_2764;
                                                        if (while_flag_2760) {
                                                          (void)::dessser::VOID;
                                                        }
                                                      } while (while_flag_2760);
                                                      (void)::dessser::VOID;
                                                      uint8_t id_2787 { 0 };
                                                      uint32_t id_2788 { leb_ref_467[id_2787] };
                                                      Size id_2789 { Size(id_2788) };
                                                      uint8_t id_2790 { 0 };
                                                      Pointer id_2791 { p_ref_469[id_2790] };
                                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2792 { id_2789, id_2791 };
                                                      let_res_2759 = id_2792;
                                                    }
                                                    let_res_2757 = let_res_2759;
                                                  }
                                                  let_res_2754 = let_res_2757;
                                                }
                                                ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 let_res_2793;
                                                {
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_473 { let_res_2754 };
                                                  ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2794;
                                                  {
                                                    auto dstring1_fst_474 { std::get<0>(dstring1_473) };
                                                    auto dstring1_snd_475 { std::get<1>(dstring1_473) };
                                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2795 { dstring1_snd_475.readBytes(dstring1_fst_474) };
                                                    ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2796;
                                                    {
                                                      auto dstring2_fst_477 { std::get<0>(id_2795) };
                                                      auto dstring2_snd_478 { std::get<1>(id_2795) };
                                                      std::string id_2797 { dstring2_fst_477.toString() };
                                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_2798 { std::in_place_index<1>, id_2797 };
                                                      ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 id_2799 { id_2798, dstring2_snd_478 };
                                                      letpair_res_2796 = id_2799;
                                                    }
                                                    letpair_res_2794 = letpair_res_2796;
                                                  }
                                                  let_res_2793 = letpair_res_2794;
                                                }
                                                choose_res_2700 = let_res_2793;
                                              }
                                              letpair_res_2697 = choose_res_2700;
                                            }
                                            let_res_2696 = letpair_res_2697;
                                          }
                                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2800;
                                          {
                                            auto dtup_fst_498 { std::get<0>(let_res_2696) };
                                            auto dtup_snd_499 { std::get<1>(let_res_2696) };
                                            ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff id_2801 { dtup_fst_456, dtup_fst_498 };
                                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2802 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<14>, id_2801) };
                                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2803 { id_2802, dtup_snd_499 };
                                            letpair_res_2800 = id_2803;
                                          }
                                          letpair_res_2692 = letpair_res_2800;
                                        }
                                        let_res_2691 = letpair_res_2692;
                                      }
                                      choose_res_2688 = let_res_2691;
                                    } else {
                                      uint16_t id_2804 { 15 };
                                      bool id_2805 { bool(dsum1_fst_342 == id_2804) };
                                      Void id_2806 { ((void)(assert(id_2805)), ::dessser::VOID) };
                                      (void)id_2806;
                                      uint32_t id_2807 { 0U };
                                      Vec<1, uint32_t> id_2808 {  id_2807  };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2809;
                                      {
                                        Vec<1, uint32_t> leb_ref_344 { id_2808 };
                                        uint8_t id_2810 { 0 };
                                        Vec<1, uint8_t> id_2811 {  id_2810  };
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2812;
                                        {
                                          Vec<1, uint8_t> shft_ref_345 { id_2811 };
                                          Vec<1, Pointer> id_2813 {  dsum1_snd_343  };
                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2814;
                                          {
                                            Vec<1, Pointer> p_ref_346 { id_2813 };
                                            bool while_flag_2815 { true };
                                            do {
                                              uint8_t id_2816 { 0 };
                                              Pointer id_2817 { p_ref_346[id_2816] };
                                              ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2818 { id_2817.readU8() };
                                              bool let_res_2819;
                                              {
                                                ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_347 { id_2818 };
                                                bool letpair_res_2820;
                                                {
                                                  auto leb128_fst_348 { std::get<0>(leb128_347) };
                                                  auto leb128_snd_349 { std::get<1>(leb128_347) };
                                                  uint8_t id_2821 { 0 };
                                                  Void id_2822 { ((void)(p_ref_346[id_2821] = leb128_snd_349), ::dessser::VOID) };
                                                  (void)id_2822;
                                                  uint8_t id_2823 { 0 };
                                                  uint8_t id_2824 { 127 };
                                                  uint8_t id_2825 { uint8_t(leb128_fst_348 & id_2824) };
                                                  uint32_t id_2826 { uint32_t(id_2825) };
                                                  uint8_t id_2827 { 0 };
                                                  uint8_t id_2828 { shft_ref_345[id_2827] };
                                                  uint32_t id_2829 { uint32_t(id_2826 << id_2828) };
                                                  uint8_t id_2830 { 0 };
                                                  uint32_t id_2831 { leb_ref_344[id_2830] };
                                                  uint32_t id_2832 { uint32_t(id_2829 | id_2831) };
                                                  Void id_2833 { ((void)(leb_ref_344[id_2823] = id_2832), ::dessser::VOID) };
                                                  (void)id_2833;
                                                  uint8_t id_2834 { 0 };
                                                  uint8_t id_2835 { 0 };
                                                  uint8_t id_2836 { shft_ref_345[id_2835] };
                                                  uint8_t id_2837 { 7 };
                                                  uint8_t id_2838 { uint8_t(id_2836 + id_2837) };
                                                  Void id_2839 { ((void)(shft_ref_345[id_2834] = id_2838), ::dessser::VOID) };
                                                  (void)id_2839;
                                                  uint8_t id_2840 { 128 };
                                                  bool id_2841 { bool(leb128_fst_348 >= id_2840) };
                                                  letpair_res_2820 = id_2841;
                                                }
                                                let_res_2819 = letpair_res_2820;
                                              }
                                              while_flag_2815 = let_res_2819;
                                              if (while_flag_2815) {
                                                (void)::dessser::VOID;
                                              }
                                            } while (while_flag_2815);
                                            (void)::dessser::VOID;
                                            uint8_t id_2842 { 0 };
                                            uint32_t id_2843 { leb_ref_344[id_2842] };
                                            Size id_2844 { Size(id_2843) };
                                            uint8_t id_2845 { 0 };
                                            Pointer id_2846 { p_ref_346[id_2845] };
                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2847 { id_2844, id_2846 };
                                            let_res_2814 = id_2847;
                                          }
                                          let_res_2812 = let_res_2814;
                                        }
                                        let_res_2809 = let_res_2812;
                                      }
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2848;
                                      {
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_350 { let_res_2809 };
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2849;
                                        {
                                          auto dstring1_fst_351 { std::get<0>(dstring1_350) };
                                          auto dstring1_snd_352 { std::get<1>(dstring1_350) };
                                          ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2850 { dstring1_snd_352.readBytes(dstring1_fst_351) };
                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2851;
                                          {
                                            auto dstring2_fst_354 { std::get<0>(id_2850) };
                                            auto dstring2_snd_355 { std::get<1>(id_2850) };
                                            std::string id_2852 { dstring2_fst_354.toString() };
                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2853 { id_2852, dstring2_snd_355 };
                                            letpair_res_2851 = id_2853;
                                          }
                                          letpair_res_2849 = letpair_res_2851;
                                        }
                                        let_res_2848 = letpair_res_2849;
                                      }
                                      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f let_res_2854;
                                      {
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_356 { let_res_2848 };
                                        ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2855;
                                        {
                                          auto dtup_fst_357 { std::get<0>(dtup_356) };
                                          auto dtup_snd_358 { std::get<1>(dtup_356) };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2856 { dtup_snd_358.readU16Le() };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2857;
                                          {
                                            auto du16_fst_360 { std::get<0>(id_2856) };
                                            auto du16_snd_361 { std::get<1>(id_2856) };
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2858 { du16_fst_360, du16_snd_361 };
                                            letpair_res_2857 = id_2858;
                                          }
                                          ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 let_res_2859;
                                          {
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_365 { letpair_res_2857 };
                                            ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_2860;
                                            {
                                              auto dsum1_fst_366 { std::get<0>(dsum1_365) };
                                              auto dsum1_snd_367 { std::get<1>(dsum1_365) };
                                              uint16_t id_2861 { 0 };
                                              bool id_2862 { bool(id_2861 == dsum1_fst_366) };
                                              ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2863;
                                              if (id_2862) {
                                                (void)::dessser::VOID;
                                                ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2864 { std::in_place_index<0>, ::dessser::VOID };
                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2865 { id_2864, dsum1_snd_367 };
                                                choose_res_2863 = id_2865;
                                              } else {
                                                uint16_t id_2866 { 1 };
                                                bool id_2867 { bool(id_2866 == dsum1_fst_366) };
                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2868;
                                                if (id_2867) {
                                                  (void)::dessser::VOID;
                                                  ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2869 { std::in_place_index<1>, ::dessser::VOID };
                                                  ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2870 { id_2869, dsum1_snd_367 };
                                                  choose_res_2868 = id_2870;
                                                } else {
                                                  uint16_t id_2871 { 2 };
                                                  bool id_2872 { bool(id_2871 == dsum1_fst_366) };
                                                  ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2873;
                                                  if (id_2872) {
                                                    (void)::dessser::VOID;
                                                    ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2874 { std::in_place_index<2>, ::dessser::VOID };
                                                    ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2875 { id_2874, dsum1_snd_367 };
                                                    choose_res_2873 = id_2875;
                                                  } else {
                                                    uint16_t id_2876 { 3 };
                                                    bool id_2877 { bool(id_2876 == dsum1_fst_366) };
                                                    ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2878;
                                                    if (id_2877) {
                                                      (void)::dessser::VOID;
                                                      ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2879 { std::in_place_index<3>, ::dessser::VOID };
                                                      ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2880 { id_2879, dsum1_snd_367 };
                                                      choose_res_2878 = id_2880;
                                                    } else {
                                                      uint16_t id_2881 { 4 };
                                                      bool id_2882 { bool(id_2881 == dsum1_fst_366) };
                                                      ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2883;
                                                      if (id_2882) {
                                                        (void)::dessser::VOID;
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2884 { std::in_place_index<4>, ::dessser::VOID };
                                                        ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2885 { id_2884, dsum1_snd_367 };
                                                        choose_res_2883 = id_2885;
                                                      } else {
                                                        uint16_t id_2886 { 5 };
                                                        bool id_2887 { bool(id_2886 == dsum1_fst_366) };
                                                        ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_2888;
                                                        if (id_2887) {
                                                          uint32_t id_2889 { 0U };
                                                          Vec<1, uint32_t> id_2890 {  id_2889  };
                                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2891;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_383 { id_2890 };
                                                            uint8_t id_2892 { 0 };
                                                            Vec<1, uint8_t> id_2893 {  id_2892  };
                                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2894;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_384 { id_2893 };
                                                              Vec<1, Pointer> id_2895 {  dsum1_snd_367  };
                                                              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2896;
                                                              {
                                                                Vec<1, Pointer> p_ref_385 { id_2895 };
                                                                bool while_flag_2897 { true };
                                                                do {
                                                                  uint8_t id_2898 { 0 };
                                                                  Pointer id_2899 { p_ref_385[id_2898] };
                                                                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2900 { id_2899.readU8() };
                                                                  bool let_res_2901;
                                                                  {
                                                                    ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_386 { id_2900 };
                                                                    bool letpair_res_2902;
                                                                    {
                                                                      auto leb128_fst_387 { std::get<0>(leb128_386) };
                                                                      auto leb128_snd_388 { std::get<1>(leb128_386) };
                                                                      uint8_t id_2903 { 0 };
                                                                      Void id_2904 { ((void)(p_ref_385[id_2903] = leb128_snd_388), ::dessser::VOID) };
                                                                      (void)id_2904;
                                                                      uint8_t id_2905 { 0 };
                                                                      uint8_t id_2906 { 127 };
                                                                      uint8_t id_2907 { uint8_t(leb128_fst_387 & id_2906) };
                                                                      uint32_t id_2908 { uint32_t(id_2907) };
                                                                      uint8_t id_2909 { 0 };
                                                                      uint8_t id_2910 { shft_ref_384[id_2909] };
                                                                      uint32_t id_2911 { uint32_t(id_2908 << id_2910) };
                                                                      uint8_t id_2912 { 0 };
                                                                      uint32_t id_2913 { leb_ref_383[id_2912] };
                                                                      uint32_t id_2914 { uint32_t(id_2911 | id_2913) };
                                                                      Void id_2915 { ((void)(leb_ref_383[id_2905] = id_2914), ::dessser::VOID) };
                                                                      (void)id_2915;
                                                                      uint8_t id_2916 { 0 };
                                                                      uint8_t id_2917 { 0 };
                                                                      uint8_t id_2918 { shft_ref_384[id_2917] };
                                                                      uint8_t id_2919 { 7 };
                                                                      uint8_t id_2920 { uint8_t(id_2918 + id_2919) };
                                                                      Void id_2921 { ((void)(shft_ref_384[id_2916] = id_2920), ::dessser::VOID) };
                                                                      (void)id_2921;
                                                                      uint8_t id_2922 { 128 };
                                                                      bool id_2923 { bool(leb128_fst_387 >= id_2922) };
                                                                      letpair_res_2902 = id_2923;
                                                                    }
                                                                    let_res_2901 = letpair_res_2902;
                                                                  }
                                                                  while_flag_2897 = let_res_2901;
                                                                  if (while_flag_2897) {
                                                                    (void)::dessser::VOID;
                                                                  }
                                                                } while (while_flag_2897);
                                                                (void)::dessser::VOID;
                                                                uint8_t id_2924 { 0 };
                                                                uint32_t id_2925 { leb_ref_383[id_2924] };
                                                                Size id_2926 { Size(id_2925) };
                                                                uint8_t id_2927 { 0 };
                                                                Pointer id_2928 { p_ref_385[id_2927] };
                                                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2929 { id_2926, id_2928 };
                                                                let_res_2896 = id_2929;
                                                              }
                                                              let_res_2894 = let_res_2896;
                                                            }
                                                            let_res_2891 = let_res_2894;
                                                          }
                                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2930;
                                                          {
                                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_389 { let_res_2891 };
                                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2931;
                                                            {
                                                              auto dstring1_fst_390 { std::get<0>(dstring1_389) };
                                                              auto dstring1_snd_391 { std::get<1>(dstring1_389) };
                                                              ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2932 { dstring1_snd_391.readBytes(dstring1_fst_390) };
                                                              ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2933;
                                                              {
                                                                auto dstring2_fst_393 { std::get<0>(id_2932) };
                                                                auto dstring2_snd_394 { std::get<1>(id_2932) };
                                                                std::string id_2934 { dstring2_fst_393.toString() };
                                                                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2935 { id_2934, dstring2_snd_394 };
                                                                letpair_res_2933 = id_2935;
                                                              }
                                                              letpair_res_2931 = letpair_res_2933;
                                                            }
                                                            let_res_2930 = letpair_res_2931;
                                                          }
                                                          ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 let_res_2936;
                                                          {
                                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_395 { let_res_2930 };
                                                            ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_2937;
                                                            {
                                                              auto dtup_fst_396 { std::get<0>(dtup_395) };
                                                              auto dtup_snd_397 { std::get<1>(dtup_395) };
                                                              ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2938 { dtup_snd_397.readU16Le() };
                                                              ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2939;
                                                              {
                                                                auto du16_fst_399 { std::get<0>(id_2938) };
                                                                auto du16_snd_400 { std::get<1>(id_2938) };
                                                                ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2940 { du16_fst_399, du16_snd_400 };
                                                                letpair_res_2939 = id_2940;
                                                              }
                                                              ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 let_res_2941;
                                                              {
                                                                ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_404 { letpair_res_2939 };
                                                                ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 letpair_res_2942;
                                                                {
                                                                  auto dsum1_fst_405 { std::get<0>(dsum1_404) };
                                                                  auto dsum1_snd_406 { std::get<1>(dsum1_404) };
                                                                  uint16_t id_2943 { 0 };
                                                                  bool id_2944 { bool(id_2943 == dsum1_fst_405) };
                                                                  ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_2945;
                                                                  if (id_2944) {
                                                                    (void)::dessser::VOID;
                                                                    ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_2946 { std::in_place_index<0>, ::dessser::VOID };
                                                                    ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_2947 { id_2946, dsum1_snd_406 };
                                                                    choose_res_2945 = id_2947;
                                                                  } else {
                                                                    uint16_t id_2948 { 1 };
                                                                    bool id_2949 { bool(id_2948 == dsum1_fst_405) };
                                                                    ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_2950;
                                                                    if (id_2949) {
                                                                      (void)::dessser::VOID;
                                                                      ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_2951 { std::in_place_index<1>, ::dessser::VOID };
                                                                      ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_2952 { id_2951, dsum1_snd_406 };
                                                                      choose_res_2950 = id_2952;
                                                                    } else {
                                                                      uint16_t id_2953 { 2 };
                                                                      bool id_2954 { bool(id_2953 == dsum1_fst_405) };
                                                                      ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_2955;
                                                                      if (id_2954) {
                                                                        (void)::dessser::VOID;
                                                                        ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_2956 { std::in_place_index<2>, ::dessser::VOID };
                                                                        ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_2957 { id_2956, dsum1_snd_406 };
                                                                        choose_res_2955 = id_2957;
                                                                      } else {
                                                                        uint16_t id_2958 { 3 };
                                                                        bool id_2959 { bool(id_2958 == dsum1_fst_405) };
                                                                        ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_2960;
                                                                        if (id_2959) {
                                                                          (void)::dessser::VOID;
                                                                          ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_2961 { std::in_place_index<3>, ::dessser::VOID };
                                                                          ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_2962 { id_2961, dsum1_snd_406 };
                                                                          choose_res_2960 = id_2962;
                                                                        } else {
                                                                          uint16_t id_2963 { 4 };
                                                                          bool id_2964 { bool(id_2963 == dsum1_fst_405) };
                                                                          ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_2965;
                                                                          if (id_2964) {
                                                                            (void)::dessser::VOID;
                                                                            ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_2966 { std::in_place_index<4>, ::dessser::VOID };
                                                                            ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_2967 { id_2966, dsum1_snd_406 };
                                                                            choose_res_2965 = id_2967;
                                                                          } else {
                                                                            uint16_t id_2968 { 5 };
                                                                            bool id_2969 { bool(id_2968 == dsum1_fst_405) };
                                                                            ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_2970;
                                                                            if (id_2969) {
                                                                              (void)::dessser::VOID;
                                                                              ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_2971 { std::in_place_index<5>, ::dessser::VOID };
                                                                              ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_2972 { id_2971, dsum1_snd_406 };
                                                                              choose_res_2970 = id_2972;
                                                                            } else {
                                                                              uint16_t id_2973 { 6 };
                                                                              bool id_2974 { bool(dsum1_fst_405 == id_2973) };
                                                                              Void id_2975 { ((void)(assert(id_2974)), ::dessser::VOID) };
                                                                              (void)id_2975;
                                                                              (void)::dessser::VOID;
                                                                              ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_2976 { std::in_place_index<6>, ::dessser::VOID };
                                                                              ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_2977 { id_2976, dsum1_snd_406 };
                                                                              choose_res_2970 = id_2977;
                                                                            }
                                                                            choose_res_2965 = choose_res_2970;
                                                                          }
                                                                          choose_res_2960 = choose_res_2965;
                                                                        }
                                                                        choose_res_2955 = choose_res_2960;
                                                                      }
                                                                      choose_res_2950 = choose_res_2955;
                                                                    }
                                                                    choose_res_2945 = choose_res_2950;
                                                                  }
                                                                  letpair_res_2942 = choose_res_2945;
                                                                }
                                                                let_res_2941 = letpair_res_2942;
                                                              }
                                                              ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_2978;
                                                              {
                                                                auto dtup_fst_429 { std::get<0>(let_res_2941) };
                                                                auto dtup_snd_430 { std::get<1>(let_res_2941) };
                                                                ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_2979 { dtup_fst_396, dtup_fst_429 };
                                                                ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2980 { std::in_place_index<5>, id_2979 };
                                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2981 { id_2980, dtup_snd_430 };
                                                                letpair_res_2978 = id_2981;
                                                              }
                                                              letpair_res_2937 = letpair_res_2978;
                                                            }
                                                            let_res_2936 = letpair_res_2937;
                                                          }
                                                          choose_res_2888 = let_res_2936;
                                                        } else {
                                                          uint16_t id_2982 { 6 };
                                                          bool id_2983 { bool(dsum1_fst_366 == id_2982) };
                                                          Void id_2984 { ((void)(assert(id_2983)), ::dessser::VOID) };
                                                          (void)id_2984;
                                                          ::dessser::gen::sync_key::tf568409f41c9c0a265f7302110fc9084 id_2985 { dsum1_snd_367.readU64Le() };
                                                          ::dessser::gen::sync_key::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_2986;
                                                          {
                                                            auto dfloat_fst_369 { std::get<0>(id_2985) };
                                                            auto dfloat_snd_370 { std::get<1>(id_2985) };
                                                            double id_2987 { float_of_qword(dfloat_fst_369) };
                                                            ::dessser::gen::sync_key::t5375de390f9cb5ae2ee5880ea1674828 id_2988 { id_2987, dfloat_snd_370 };
                                                            letpair_res_2986 = id_2988;
                                                          }
                                                          ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 let_res_2989;
                                                          {
                                                            ::dessser::gen::sync_key::t5375de390f9cb5ae2ee5880ea1674828 dtup_371 { letpair_res_2986 };
                                                            ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_2990;
                                                            {
                                                              auto dtup_fst_372 { std::get<0>(dtup_371) };
                                                              auto dtup_snd_373 { std::get<1>(dtup_371) };
                                                              ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_2991 { dtup_snd_373.readU32Le() };
                                                              ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_2992;
                                                              {
                                                                auto du32_fst_375 { std::get<0>(id_2991) };
                                                                auto du32_snd_376 { std::get<1>(id_2991) };
                                                                ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 id_2993 { dtup_fst_372, du32_fst_375 };
                                                                ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_2994 { std::in_place_index<6>, id_2993 };
                                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_2995 { id_2994, du32_snd_376 };
                                                                letpair_res_2992 = id_2995;
                                                              }
                                                              letpair_res_2990 = letpair_res_2992;
                                                            }
                                                            let_res_2989 = letpair_res_2990;
                                                          }
                                                          choose_res_2888 = let_res_2989;
                                                        }
                                                        choose_res_2883 = choose_res_2888;
                                                      }
                                                      choose_res_2878 = choose_res_2883;
                                                    }
                                                    choose_res_2873 = choose_res_2878;
                                                  }
                                                  choose_res_2868 = choose_res_2873;
                                                }
                                                choose_res_2863 = choose_res_2868;
                                              }
                                              letpair_res_2860 = choose_res_2863;
                                            }
                                            let_res_2859 = letpair_res_2860;
                                          }
                                          ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_2996;
                                          {
                                            auto dtup_fst_450 { std::get<0>(let_res_2859) };
                                            auto dtup_snd_451 { std::get<1>(let_res_2859) };
                                            ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_2997 { dtup_fst_357, dtup_fst_450 };
                                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2998 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<15>, id_2997) };
                                            ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_2999 { id_2998, dtup_snd_451 };
                                            letpair_res_2996 = id_2999;
                                          }
                                          letpair_res_2855 = letpair_res_2996;
                                        }
                                        let_res_2854 = letpair_res_2855;
                                      }
                                      choose_res_2688 = let_res_2854;
                                    }
                                    choose_res_2683 = choose_res_2688;
                                  }
                                  choose_res_2626 = choose_res_2683;
                                }
                                choose_res_2614 = choose_res_2626;
                              }
                              choose_res_2609 = choose_res_2614;
                            }
                            choose_res_2587 = choose_res_2609;
                          }
                          choose_res_2580 = choose_res_2587;
                        }
                        choose_res_2515 = choose_res_2580;
                      }
                      choose_res_2443 = choose_res_2515;
                    }
                    choose_res_2436 = choose_res_2443;
                  }
                  choose_res_2431 = choose_res_2436;
                }
                choose_res_2375 = choose_res_2431;
              }
              choose_res_2324 = choose_res_2375;
            }
            choose_res_2319 = choose_res_2324;
          }
          choose_res_2314 = choose_res_2319;
        }
        letpair_res_2311 = choose_res_2314;
      }
      let_res_2310 = letpair_res_2311;
    }
    ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f letpair_res_3000;
    {
      auto make_fst_660 { std::get<0>(let_res_2310) };
      auto make_snd_661 { std::get<1>(let_res_2310) };
      ::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f id_3001 { make_fst_660, make_snd_661 };
      letpair_res_3000 = id_3001;
    }
    return letpair_res_3000;
  }
   };
  return fun2306;
}
std::function<::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f(Pointer)> of_row_binary(of_row_binary_init());


}
