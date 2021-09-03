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

typedef std::tuple<
  dessser::gen::src_path::t_ext,
  std::string
> t274013922fc0b2cd45c289bf2ba4463d;

struct t32def300158106bfcc2bfd2015d1a3a9 : public std::variant<
  Void, // Host
  Void // Port
> { using variant::variant; };

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9
> t1aff348714b8a3b47c6403c353655995;

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

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb
> t1ad3e248018f4f9e0c3083920c2150a2;

struct t794aebb012043f26d004aebd5966b350 : public std::variant<
  Void, // RuntimeStats
  Void, // ArchivedTimes
  Void, // NumArcFiles
  Void, // NumArcBytes
  Void, // AllocedArcBytes
  Void, // Worker
  ::dessser::gen::sync_key::t1ad3e248018f4f9e0c3083920c2150a2, // PerInstance
  uint32_t, // PerReplayer
  Void // OutputSpecs
> { using variant::variant; };

typedef std::tuple<
  dessser::gen::fq_name::t_ext,
  ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350
> t4ead4b84ceaa6e65cf560142db29b99b;

struct t73ec97d1f82a1880f5d2693e3a0558b1 : public std::variant<
  Void // Executable
> { using variant::variant; };

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1
> tb761ebb9c7c72cccd366042890abdac8;

struct td886436745a4631e1e780c597e2e1fe9 : public std::variant<
  Void, // IsMaster
  ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995, // PerService
  ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b, // PerWorker
  ::dessser::gen::sync_key::tb761ebb9c7c72cccd366042890abdac8 // PerProgram
> { using variant::variant; };

typedef std::tuple<
  dessser::gen::site_name::t_ext,
  ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9
> td1b9e7ba6416a29dd2501cb424913fb2;

struct t1fb80ba5a0eef0b970838ab3e8e6bce4 : public std::variant<
  Void, // TotalSize
  Void, // RecallCost
  std::string // RetentionsOverride
> { using variant::variant; };

struct tc93e19385f89f334cffc47ceb4a894b8 : public std::variant<
  std::string, // Subscriber
  uint32_t // LastTuple
> { using variant::variant; };

struct t9d781e6e3c7478a3c57f805b8c82ba57 : public std::tuple<
  dessser::gen::site_name::t_ext,
  dessser::gen::fq_name::t_ext,
  std::string,
  ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8
> { using tuple::tuple; };
struct t34440d69278f78fc117a9719151dac05 : public std::variant<
  std::string, // Response
  ::dessser::gen::sync_key::per_dash_key* // Scratchpad
> { using variant::variant; };

typedef std::tuple<
  dessser::gen::sync_socket::t_ext,
  ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05
> te92b7cdb8c8cb9bcb9417c7d44e820f0;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  std::string,
  per_dash_key*
> tdf6d0a87bf373d7d4ea33113dc8a8b30;

struct t8bc7bba8a815a55f85ed48e95de5ac1f : public std::variant<
  std::string, // Contacts
  std::string // Inhibition
> { using variant::variant; };

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f
> tf683ff0a6f84b622c9bd63a1e4d4c2e8;

struct t7cca840d7e40b13b976d995ba9f9fd5b : public std::variant<
  Void, // NumDeliveryAttempts
  Void, // FirstDeliveryAttempt
  Void, // LastDeliveryAttempt
  Void, // NextScheduled
  Void, // NextSend
  Void, // DeliveryStatus
  Void // Ack
> { using variant::variant; };

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b
> t51130975cc895752ed58d8b9dd6b2622;

typedef std::tuple<
  double,
  uint32_t
> t66e64aa59a640b5ac04dd276fa3e8463;

struct t14a5e3eba11a1198d8e17aba65f08825 : public std::variant<
  Void, // FirstStartNotif
  Void, // LastStartNotif
  Void, // LastStopNotif
  Void, // LastStateChangeNotif
  Void, // Team
  ::dessser::gen::sync_key::t51130975cc895752ed58d8b9dd6b2622, // Dialogs
  ::dessser::gen::sync_key::t66e64aa59a640b5ac04dd276fa3e8463 // Journal
> { using variant::variant; };

typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825
> t0d1b1fab40d65ee9bac191ed6e0b37a6;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct t : public std::variant<
  Void, // DevNull
  Void, // Time
  std::string, // Versions
  ::dessser::gen::sync_key::t274013922fc0b2cd45c289bf2ba4463d, // Sources
  Void, // TargetConfig
  ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2, // PerSite
  ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4, // Storage
  ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57, // Tails
  uint16_t, // Replays
  std::optional<dessser::gen::sync_socket::t_ext>, // Error
  Void, // ReplayRequests
  ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0, // PerClient
  ::dessser::gen::sync_key::tdf6d0a87bf373d7d4ea33113dc8a8b30, // Dashboards
  Void, // Notifications
  ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8, // Teams
  ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 // Incidents
> { using variant::variant; };

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  ::dessser::gen::sync_key::per_dash_key*,
  Pointer
> t74d8a287d0a13dbe7e14118a085f0fb9;

typedef std::tuple<
  uint16_t,
  Pointer
> t22a32080ad88ab548b80077a17b7dd46;

typedef std::tuple<
  uint32_t,
  Pointer
> t405eb186408556fed8f2c41523c07d13;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  ::dessser::gen::sync_key::t*,
  Pointer
> t3161399693367e6234a99fd179dbbb5d;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  Size,
  Pointer
> t8beb80162423aee37bd383e9b6834c9c;

typedef std::tuple<
  uint8_t,
  Pointer
> tb3f98ea670610d40658a618de3ec7b90;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  Bytes,
  Pointer
> t188345aa49abd0cb47ff73fedc219f08;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  dessser::gen::src_path::t_ext,
  Pointer
> t3aef8ea133ee816827fd8db245b58487;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  dessser::gen::site_name::t_ext,
  Pointer
> tb31a43e42345099d489759a9c141b1b9;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9,
  Pointer
> tf093c02358b6fb2e811baa5e54812a8e;

typedef std::tuple<
  std::string,
  Pointer
> tef94b55d8809251f13165d9a05bd9d0e;

typedef std::tuple<
  ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9,
  Pointer
> t266fb47650ef8cb696e440bff783f8e3;

typedef std::tuple<
  dessser::gen::fq_name::t_ext,
  Pointer
> td8eaddfacf232bd15ab91a5778e12a3b;

typedef std::tuple<
  ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350,
  Pointer
> t41af8d053a5950cc10ed03d1b4f40e29;

typedef std::tuple<
  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb,
  Pointer
> t37be669ae311fab16260f09e977da9b5;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4,
  Pointer
> te62cbea9c501cbe12525ca38267c2513;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8,
  Pointer
> t25f8accbaed2398ac12a9768d2538e0b;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  std::optional<dessser::gen::sync_socket::t_ext>,
  Pointer
> tc830800ab3d022d92257593f4e7f18f4;

typedef std::tuple<
  dessser::gen::sync_socket::t_ext,
  Pointer
> t60a438e45a4b170b9ebd75067d553051;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05,
  Pointer
> t12bd4a5520fba716109e506b78c12b14;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  std::string,
  ::dessser::gen::sync_key::per_dash_key*
> taedf2e3441a6137271066ee57c3c4d25;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f,
  Pointer
> t652d47eaa6c827db9e62e1b0b0edf231;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825,
  Pointer
> tf53c8dceba8a84883083484790fbf024;

typedef std::tuple<
  ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b,
  Pointer
> te6642ee05317b332274a933388d6d540;

typedef std::tuple<
  uint64_t,
  Pointer
> t7a47220550fc5126a7b79f1e0c10c645;

typedef std::tuple<
  double,
  Pointer
> taebed00ad7fdb3f7ced11d3cfd58aade;

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Widgets U32]" "Ptr")
      (let "ssum_dst_743" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (write-u32 little-endian (identifier "ssum_dst_743") (get-alt "Widgets" (param 0))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::per_dash_key*,Pointer)> per_dash_key_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::per_dash_key*,Pointer)> fun0 { [&fun0](::dessser::gen::sync_key::per_dash_key* p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_743 { id_2 };
      uint16_t id_4 { uint16_t((*p_0).index()) };
      uint16_t id_5 { 0 };
      bool id_6 { bool(id_4 == id_5) };
      Void id_7 { ((void)(assert(id_6)), VOID) };
      (void)id_7;
      uint32_t id_8 { std::get<0 /* Widgets */>((*p_0)) };
      Pointer id_9 { ssum_dst_743.writeU32Le(id_8) };
      let_res_3 = id_9;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::sync_key::per_dash_key*,Pointer)> per_dash_key_to_row_binary(per_dash_key_to_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" "Ptr")
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
static std::function<Pointer(::dessser::gen::sync_key::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::t*,Pointer)> fun10 { [&fun10](::dessser::gen::sync_key::t* p_0, Pointer p_1) {
    uint16_t id_11 { uint16_t((*p_0).index()) };
    Pointer let_res_12;
    {
      uint16_t label1_744 { id_11 };
      Pointer id_13 { p_1.writeU16Le(label1_744) };
      Pointer let_res_14;
      {
        Pointer ssum_dst_745 { id_13 };
        uint16_t id_15 { 0 };
        bool id_16 { bool(id_15 == label1_744) };
        Pointer choose_res_17;
        if (id_16) {
          choose_res_17 = ssum_dst_745;
        } else {
          uint16_t id_18 { 1 };
          bool id_19 { bool(id_18 == label1_744) };
          Pointer choose_res_20;
          if (id_19) {
            choose_res_20 = ssum_dst_745;
          } else {
            uint16_t id_21 { 2 };
            bool id_22 { bool(id_21 == label1_744) };
            Pointer choose_res_23;
            if (id_22) {
              std::string id_24 { std::get<2 /* Versions */>((*p_0)) };
              uint32_t id_25 { (uint32_t)id_24.size() };
              Vec<1, uint32_t> id_26 {  id_25  };
              Pointer let_res_27;
              {
                Vec<1, uint32_t> leb128_sz_811 { id_26 };
                Vec<1, Pointer> id_28 {  ssum_dst_745  };
                Pointer let_res_29;
                {
                  Vec<1, Pointer> leb128_ptr_812 { id_28 };
                  bool while_flag_30 { true };
                  do {
                    uint8_t id_31 { 0 };
                    uint8_t id_32 { 0 };
                    Pointer id_33 { leb128_ptr_812[id_32] };
                    uint32_t id_34 { 128U };
                    uint8_t id_35 { 0 };
                    uint32_t id_36 { leb128_sz_811[id_35] };
                    bool id_37 { bool(id_34 > id_36) };
                    uint8_t choose_res_38;
                    if (id_37) {
                      uint8_t id_39 { 0 };
                      uint32_t id_40 { leb128_sz_811[id_39] };
                      uint8_t id_41 { uint8_t(id_40) };
                      choose_res_38 = id_41;
                    } else {
                      uint8_t id_42 { 0 };
                      uint32_t id_43 { leb128_sz_811[id_42] };
                      uint8_t id_44 { uint8_t(id_43) };
                      uint8_t id_45 { 128 };
                      uint8_t id_46 { uint8_t(id_44 | id_45) };
                      choose_res_38 = id_46;
                    }
                    Pointer id_47 { id_33.writeU8(choose_res_38) };
                    Void id_48 { ((void)(leb128_ptr_812[id_31] = id_47), VOID) };
                    (void)id_48;
                    uint8_t id_49 { 0 };
                    uint8_t id_50 { 0 };
                    uint32_t id_51 { leb128_sz_811[id_50] };
                    uint8_t id_52 { 7 };
                    uint32_t id_53 { uint32_t(id_51 >> id_52) };
                    Void id_54 { ((void)(leb128_sz_811[id_49] = id_53), VOID) };
                    (void)id_54;
                    uint8_t id_55 { 0 };
                    uint32_t id_56 { leb128_sz_811[id_55] };
                    uint32_t id_57 { 0U };
                    bool id_58 { bool(id_56 > id_57) };
                    while_flag_30 = id_58;
                    if (while_flag_30) {
                      (void)VOID;
                    }
                  } while (while_flag_30);
                  (void)VOID;
                  uint8_t id_59 { 0 };
                  Pointer id_60 { leb128_ptr_812[id_59] };
                  let_res_29 = id_60;
                }
                let_res_27 = let_res_29;
              }
              std::string id_61 { std::get<2 /* Versions */>((*p_0)) };
              Bytes id_62 { id_61 };
              Pointer id_63 { let_res_27.writeBytes(id_62) };
              choose_res_23 = id_63;
            } else {
              uint16_t id_64 { 3 };
              bool id_65 { bool(id_64 == label1_744) };
              Pointer choose_res_66;
              if (id_65) {
                auto fun67 { dessser::gen::src_path::to_row_binary };
                ::dessser::gen::sync_key::t274013922fc0b2cd45c289bf2ba4463d id_68 { std::get<3 /* Sources */>((*p_0)) };
                dessser::gen::src_path::t_ext id_69 { std::get<0>(id_68) };
                Pointer id_70 { fun67(id_69, ssum_dst_745) };
                Pointer let_res_71;
                {
                  Pointer stup_dst_808 { id_70 };
                  ::dessser::gen::sync_key::t274013922fc0b2cd45c289bf2ba4463d id_72 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_73 { std::get<1>(id_72) };
                  uint32_t id_74 { (uint32_t)id_73.size() };
                  Vec<1, uint32_t> id_75 {  id_74  };
                  Pointer let_res_76;
                  {
                    Vec<1, uint32_t> leb128_sz_809 { id_75 };
                    Vec<1, Pointer> id_77 {  stup_dst_808  };
                    Pointer let_res_78;
                    {
                      Vec<1, Pointer> leb128_ptr_810 { id_77 };
                      bool while_flag_79 { true };
                      do {
                        uint8_t id_80 { 0 };
                        uint8_t id_81 { 0 };
                        Pointer id_82 { leb128_ptr_810[id_81] };
                        uint32_t id_83 { 128U };
                        uint8_t id_84 { 0 };
                        uint32_t id_85 { leb128_sz_809[id_84] };
                        bool id_86 { bool(id_83 > id_85) };
                        uint8_t choose_res_87;
                        if (id_86) {
                          uint8_t id_88 { 0 };
                          uint32_t id_89 { leb128_sz_809[id_88] };
                          uint8_t id_90 { uint8_t(id_89) };
                          choose_res_87 = id_90;
                        } else {
                          uint8_t id_91 { 0 };
                          uint32_t id_92 { leb128_sz_809[id_91] };
                          uint8_t id_93 { uint8_t(id_92) };
                          uint8_t id_94 { 128 };
                          uint8_t id_95 { uint8_t(id_93 | id_94) };
                          choose_res_87 = id_95;
                        }
                        Pointer id_96 { id_82.writeU8(choose_res_87) };
                        Void id_97 { ((void)(leb128_ptr_810[id_80] = id_96), VOID) };
                        (void)id_97;
                        uint8_t id_98 { 0 };
                        uint8_t id_99 { 0 };
                        uint32_t id_100 { leb128_sz_809[id_99] };
                        uint8_t id_101 { 7 };
                        uint32_t id_102 { uint32_t(id_100 >> id_101) };
                        Void id_103 { ((void)(leb128_sz_809[id_98] = id_102), VOID) };
                        (void)id_103;
                        uint8_t id_104 { 0 };
                        uint32_t id_105 { leb128_sz_809[id_104] };
                        uint32_t id_106 { 0U };
                        bool id_107 { bool(id_105 > id_106) };
                        while_flag_79 = id_107;
                        if (while_flag_79) {
                          (void)VOID;
                        }
                      } while (while_flag_79);
                      (void)VOID;
                      uint8_t id_108 { 0 };
                      Pointer id_109 { leb128_ptr_810[id_108] };
                      let_res_78 = id_109;
                    }
                    let_res_76 = let_res_78;
                  }
                  ::dessser::gen::sync_key::t274013922fc0b2cd45c289bf2ba4463d id_110 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_111 { std::get<1>(id_110) };
                  Bytes id_112 { id_111 };
                  Pointer id_113 { let_res_76.writeBytes(id_112) };
                  let_res_71 = id_113;
                }
                choose_res_66 = let_res_71;
              } else {
                uint16_t id_114 { 4 };
                bool id_115 { bool(id_114 == label1_744) };
                Pointer choose_res_116;
                if (id_115) {
                  choose_res_116 = ssum_dst_745;
                } else {
                  uint16_t id_117 { 5 };
                  bool id_118 { bool(id_117 == label1_744) };
                  Pointer choose_res_119;
                  if (id_118) {
                    auto fun120 { dessser::gen::site_name::to_row_binary };
                    ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_121 { std::get<5 /* PerSite */>((*p_0)) };
                    dessser::gen::site_name::t_ext id_122 { std::get<0>(id_121) };
                    Pointer id_123 { fun120(id_122, ssum_dst_745) };
                    Pointer let_res_124;
                    {
                      Pointer stup_dst_787 { id_123 };
                      ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_125 { std::get<5 /* PerSite */>((*p_0)) };
                      ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_126 { std::get<1>(id_125) };
                      uint16_t id_127 { uint16_t(id_126.index()) };
                      Pointer id_128 { stup_dst_787.writeU16Le(id_127) };
                      Pointer let_res_129;
                      {
                        Pointer ssum_dst_789 { id_128 };
                        uint16_t id_130 { 0 };
                        ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_131 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_132 { std::get<1>(id_131) };
                        uint16_t id_133 { uint16_t(id_132.index()) };
                        bool id_134 { bool(id_130 == id_133) };
                        Pointer choose_res_135;
                        if (id_134) {
                          choose_res_135 = ssum_dst_789;
                        } else {
                          uint16_t id_136 { 1 };
                          ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_137 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_138 { std::get<1>(id_137) };
                          uint16_t id_139 { uint16_t(id_138.index()) };
                          bool id_140 { bool(id_136 == id_139) };
                          Pointer choose_res_141;
                          if (id_140) {
                            ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_142 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_143 { std::get<1>(id_142) };
                            ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995 id_144 { std::get<1 /* PerService */>(id_143) };
                            std::string id_145 { std::get<0>(id_144) };
                            uint32_t id_146 { (uint32_t)id_145.size() };
                            Vec<1, uint32_t> id_147 {  id_146  };
                            Pointer let_res_148;
                            {
                              Vec<1, uint32_t> leb128_sz_803 { id_147 };
                              Vec<1, Pointer> id_149 {  ssum_dst_789  };
                              Pointer let_res_150;
                              {
                                Vec<1, Pointer> leb128_ptr_804 { id_149 };
                                bool while_flag_151 { true };
                                do {
                                  uint8_t id_152 { 0 };
                                  uint8_t id_153 { 0 };
                                  Pointer id_154 { leb128_ptr_804[id_153] };
                                  uint32_t id_155 { 128U };
                                  uint8_t id_156 { 0 };
                                  uint32_t id_157 { leb128_sz_803[id_156] };
                                  bool id_158 { bool(id_155 > id_157) };
                                  uint8_t choose_res_159;
                                  if (id_158) {
                                    uint8_t id_160 { 0 };
                                    uint32_t id_161 { leb128_sz_803[id_160] };
                                    uint8_t id_162 { uint8_t(id_161) };
                                    choose_res_159 = id_162;
                                  } else {
                                    uint8_t id_163 { 0 };
                                    uint32_t id_164 { leb128_sz_803[id_163] };
                                    uint8_t id_165 { uint8_t(id_164) };
                                    uint8_t id_166 { 128 };
                                    uint8_t id_167 { uint8_t(id_165 | id_166) };
                                    choose_res_159 = id_167;
                                  }
                                  Pointer id_168 { id_154.writeU8(choose_res_159) };
                                  Void id_169 { ((void)(leb128_ptr_804[id_152] = id_168), VOID) };
                                  (void)id_169;
                                  uint8_t id_170 { 0 };
                                  uint8_t id_171 { 0 };
                                  uint32_t id_172 { leb128_sz_803[id_171] };
                                  uint8_t id_173 { 7 };
                                  uint32_t id_174 { uint32_t(id_172 >> id_173) };
                                  Void id_175 { ((void)(leb128_sz_803[id_170] = id_174), VOID) };
                                  (void)id_175;
                                  uint8_t id_176 { 0 };
                                  uint32_t id_177 { leb128_sz_803[id_176] };
                                  uint32_t id_178 { 0U };
                                  bool id_179 { bool(id_177 > id_178) };
                                  while_flag_151 = id_179;
                                  if (while_flag_151) {
                                    (void)VOID;
                                  }
                                } while (while_flag_151);
                                (void)VOID;
                                uint8_t id_180 { 0 };
                                Pointer id_181 { leb128_ptr_804[id_180] };
                                let_res_150 = id_181;
                              }
                              let_res_148 = let_res_150;
                            }
                            ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_182 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_183 { std::get<1>(id_182) };
                            ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995 id_184 { std::get<1 /* PerService */>(id_183) };
                            std::string id_185 { std::get<0>(id_184) };
                            Bytes id_186 { id_185 };
                            Pointer id_187 { let_res_148.writeBytes(id_186) };
                            Pointer let_res_188;
                            {
                              Pointer stup_dst_805 { id_187 };
                              ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_189 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_190 { std::get<1>(id_189) };
                              ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995 id_191 { std::get<1 /* PerService */>(id_190) };
                              ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_192 { std::get<1>(id_191) };
                              uint16_t id_193 { uint16_t(id_192.index()) };
                              Pointer id_194 { stup_dst_805.writeU16Le(id_193) };
                              Pointer let_res_195;
                              {
                                Pointer ssum_dst_807 { id_194 };
                                uint16_t id_196 { 0 };
                                ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_197 { std::get<5 /* PerSite */>((*p_0)) };
                                ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_198 { std::get<1>(id_197) };
                                ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995 id_199 { std::get<1 /* PerService */>(id_198) };
                                ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_200 { std::get<1>(id_199) };
                                uint16_t id_201 { uint16_t(id_200.index()) };
                                bool id_202 { bool(id_196 == id_201) };
                                Pointer choose_res_203;
                                if (id_202) {
                                  choose_res_203 = ssum_dst_807;
                                } else {
                                  ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_204 { std::get<5 /* PerSite */>((*p_0)) };
                                  ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_205 { std::get<1>(id_204) };
                                  ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995 id_206 { std::get<1 /* PerService */>(id_205) };
                                  ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_207 { std::get<1>(id_206) };
                                  uint16_t id_208 { uint16_t(id_207.index()) };
                                  uint16_t id_209 { 1 };
                                  bool id_210 { bool(id_208 == id_209) };
                                  Void id_211 { ((void)(assert(id_210)), VOID) };
                                  (void)id_211;
                                  choose_res_203 = ssum_dst_807;
                                }
                                let_res_195 = choose_res_203;
                              }
                              let_res_188 = let_res_195;
                            }
                            choose_res_141 = let_res_188;
                          } else {
                            uint16_t id_212 { 2 };
                            ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_213 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_214 { std::get<1>(id_213) };
                            uint16_t id_215 { uint16_t(id_214.index()) };
                            bool id_216 { bool(id_212 == id_215) };
                            Pointer choose_res_217;
                            if (id_216) {
                              auto fun218 { dessser::gen::fq_name::to_row_binary };
                              ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_219 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_220 { std::get<1>(id_219) };
                              ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_221 { std::get<2 /* PerWorker */>(id_220) };
                              dessser::gen::fq_name::t_ext id_222 { std::get<0>(id_221) };
                              Pointer id_223 { fun218(id_222, ssum_dst_789) };
                              Pointer let_res_224;
                              {
                                Pointer stup_dst_795 { id_223 };
                                ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_225 { std::get<5 /* PerSite */>((*p_0)) };
                                ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_226 { std::get<1>(id_225) };
                                ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_227 { std::get<2 /* PerWorker */>(id_226) };
                                ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_228 { std::get<1>(id_227) };
                                uint16_t id_229 { uint16_t(id_228.index()) };
                                Pointer let_res_230;
                                {
                                  uint16_t label1_796 { id_229 };
                                  Pointer id_231 { stup_dst_795.writeU16Le(label1_796) };
                                  Pointer let_res_232;
                                  {
                                    Pointer ssum_dst_797 { id_231 };
                                    uint16_t id_233 { 0 };
                                    bool id_234 { bool(id_233 == label1_796) };
                                    Pointer choose_res_235;
                                    if (id_234) {
                                      choose_res_235 = ssum_dst_797;
                                    } else {
                                      uint16_t id_236 { 1 };
                                      bool id_237 { bool(id_236 == label1_796) };
                                      Pointer choose_res_238;
                                      if (id_237) {
                                        choose_res_238 = ssum_dst_797;
                                      } else {
                                        uint16_t id_239 { 2 };
                                        bool id_240 { bool(id_239 == label1_796) };
                                        Pointer choose_res_241;
                                        if (id_240) {
                                          choose_res_241 = ssum_dst_797;
                                        } else {
                                          uint16_t id_242 { 3 };
                                          bool id_243 { bool(id_242 == label1_796) };
                                          Pointer choose_res_244;
                                          if (id_243) {
                                            choose_res_244 = ssum_dst_797;
                                          } else {
                                            uint16_t id_245 { 4 };
                                            bool id_246 { bool(id_245 == label1_796) };
                                            Pointer choose_res_247;
                                            if (id_246) {
                                              choose_res_247 = ssum_dst_797;
                                            } else {
                                              uint16_t id_248 { 5 };
                                              bool id_249 { bool(id_248 == label1_796) };
                                              Pointer choose_res_250;
                                              if (id_249) {
                                                choose_res_250 = ssum_dst_797;
                                              } else {
                                                uint16_t id_251 { 6 };
                                                bool id_252 { bool(id_251 == label1_796) };
                                                Pointer choose_res_253;
                                                if (id_252) {
                                                  ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_254 { std::get<5 /* PerSite */>((*p_0)) };
                                                  ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_255 { std::get<1>(id_254) };
                                                  ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_256 { std::get<2 /* PerWorker */>(id_255) };
                                                  ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_257 { std::get<1>(id_256) };
                                                  ::dessser::gen::sync_key::t1ad3e248018f4f9e0c3083920c2150a2 id_258 { std::get<6 /* PerInstance */>(id_257) };
                                                  std::string id_259 { std::get<0>(id_258) };
                                                  uint32_t id_260 { (uint32_t)id_259.size() };
                                                  Vec<1, uint32_t> id_261 {  id_260  };
                                                  Pointer let_res_262;
                                                  {
                                                    Vec<1, uint32_t> leb128_sz_798 { id_261 };
                                                    Vec<1, Pointer> id_263 {  ssum_dst_797  };
                                                    Pointer let_res_264;
                                                    {
                                                      Vec<1, Pointer> leb128_ptr_799 { id_263 };
                                                      bool while_flag_265 { true };
                                                      do {
                                                        uint8_t id_266 { 0 };
                                                        uint8_t id_267 { 0 };
                                                        Pointer id_268 { leb128_ptr_799[id_267] };
                                                        uint32_t id_269 { 128U };
                                                        uint8_t id_270 { 0 };
                                                        uint32_t id_271 { leb128_sz_798[id_270] };
                                                        bool id_272 { bool(id_269 > id_271) };
                                                        uint8_t choose_res_273;
                                                        if (id_272) {
                                                          uint8_t id_274 { 0 };
                                                          uint32_t id_275 { leb128_sz_798[id_274] };
                                                          uint8_t id_276 { uint8_t(id_275) };
                                                          choose_res_273 = id_276;
                                                        } else {
                                                          uint8_t id_277 { 0 };
                                                          uint32_t id_278 { leb128_sz_798[id_277] };
                                                          uint8_t id_279 { uint8_t(id_278) };
                                                          uint8_t id_280 { 128 };
                                                          uint8_t id_281 { uint8_t(id_279 | id_280) };
                                                          choose_res_273 = id_281;
                                                        }
                                                        Pointer id_282 { id_268.writeU8(choose_res_273) };
                                                        Void id_283 { ((void)(leb128_ptr_799[id_266] = id_282), VOID) };
                                                        (void)id_283;
                                                        uint8_t id_284 { 0 };
                                                        uint8_t id_285 { 0 };
                                                        uint32_t id_286 { leb128_sz_798[id_285] };
                                                        uint8_t id_287 { 7 };
                                                        uint32_t id_288 { uint32_t(id_286 >> id_287) };
                                                        Void id_289 { ((void)(leb128_sz_798[id_284] = id_288), VOID) };
                                                        (void)id_289;
                                                        uint8_t id_290 { 0 };
                                                        uint32_t id_291 { leb128_sz_798[id_290] };
                                                        uint32_t id_292 { 0U };
                                                        bool id_293 { bool(id_291 > id_292) };
                                                        while_flag_265 = id_293;
                                                        if (while_flag_265) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_265);
                                                      (void)VOID;
                                                      uint8_t id_294 { 0 };
                                                      Pointer id_295 { leb128_ptr_799[id_294] };
                                                      let_res_264 = id_295;
                                                    }
                                                    let_res_262 = let_res_264;
                                                  }
                                                  ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_296 { std::get<5 /* PerSite */>((*p_0)) };
                                                  ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_297 { std::get<1>(id_296) };
                                                  ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_298 { std::get<2 /* PerWorker */>(id_297) };
                                                  ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_299 { std::get<1>(id_298) };
                                                  ::dessser::gen::sync_key::t1ad3e248018f4f9e0c3083920c2150a2 id_300 { std::get<6 /* PerInstance */>(id_299) };
                                                  std::string id_301 { std::get<0>(id_300) };
                                                  Bytes id_302 { id_301 };
                                                  Pointer id_303 { let_res_262.writeBytes(id_302) };
                                                  Pointer let_res_304;
                                                  {
                                                    Pointer stup_dst_800 { id_303 };
                                                    ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_305 { std::get<5 /* PerSite */>((*p_0)) };
                                                    ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_306 { std::get<1>(id_305) };
                                                    ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_307 { std::get<2 /* PerWorker */>(id_306) };
                                                    ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_308 { std::get<1>(id_307) };
                                                    ::dessser::gen::sync_key::t1ad3e248018f4f9e0c3083920c2150a2 id_309 { std::get<6 /* PerInstance */>(id_308) };
                                                    ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_310 { std::get<1>(id_309) };
                                                    uint16_t id_311 { uint16_t(id_310.index()) };
                                                    Pointer let_res_312;
                                                    {
                                                      uint16_t label1_801 { id_311 };
                                                      Pointer id_313 { stup_dst_800.writeU16Le(label1_801) };
                                                      Pointer let_res_314;
                                                      {
                                                        Pointer ssum_dst_802 { id_313 };
                                                        uint16_t id_315 { 0 };
                                                        bool id_316 { bool(id_315 == label1_801) };
                                                        Pointer choose_res_317;
                                                        if (id_316) {
                                                          choose_res_317 = ssum_dst_802;
                                                        } else {
                                                          uint16_t id_318 { 1 };
                                                          bool id_319 { bool(id_318 == label1_801) };
                                                          Pointer choose_res_320;
                                                          if (id_319) {
                                                            choose_res_320 = ssum_dst_802;
                                                          } else {
                                                            uint16_t id_321 { 2 };
                                                            bool id_322 { bool(id_321 == label1_801) };
                                                            Pointer choose_res_323;
                                                            if (id_322) {
                                                              choose_res_323 = ssum_dst_802;
                                                            } else {
                                                              uint16_t id_324 { 3 };
                                                              bool id_325 { bool(id_324 == label1_801) };
                                                              Pointer choose_res_326;
                                                              if (id_325) {
                                                                choose_res_326 = ssum_dst_802;
                                                              } else {
                                                                uint16_t id_327 { 4 };
                                                                bool id_328 { bool(id_327 == label1_801) };
                                                                Pointer choose_res_329;
                                                                if (id_328) {
                                                                  choose_res_329 = ssum_dst_802;
                                                                } else {
                                                                  uint16_t id_330 { 5 };
                                                                  bool id_331 { bool(id_330 == label1_801) };
                                                                  Pointer choose_res_332;
                                                                  if (id_331) {
                                                                    choose_res_332 = ssum_dst_802;
                                                                  } else {
                                                                    uint16_t id_333 { 6 };
                                                                    bool id_334 { bool(id_333 == label1_801) };
                                                                    Pointer choose_res_335;
                                                                    if (id_334) {
                                                                      choose_res_335 = ssum_dst_802;
                                                                    } else {
                                                                      uint16_t id_336 { 7 };
                                                                      bool id_337 { bool(label1_801 == id_336) };
                                                                      Void id_338 { ((void)(assert(id_337)), VOID) };
                                                                      (void)id_338;
                                                                      choose_res_335 = ssum_dst_802;
                                                                    }
                                                                    choose_res_332 = choose_res_335;
                                                                  }
                                                                  choose_res_329 = choose_res_332;
                                                                }
                                                                choose_res_326 = choose_res_329;
                                                              }
                                                              choose_res_323 = choose_res_326;
                                                            }
                                                            choose_res_320 = choose_res_323;
                                                          }
                                                          choose_res_317 = choose_res_320;
                                                        }
                                                        let_res_314 = choose_res_317;
                                                      }
                                                      let_res_312 = let_res_314;
                                                    }
                                                    let_res_304 = let_res_312;
                                                  }
                                                  choose_res_253 = let_res_304;
                                                } else {
                                                  uint16_t id_339 { 7 };
                                                  bool id_340 { bool(id_339 == label1_796) };
                                                  Pointer choose_res_341;
                                                  if (id_340) {
                                                    ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_342 { std::get<5 /* PerSite */>((*p_0)) };
                                                    ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_343 { std::get<1>(id_342) };
                                                    ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_344 { std::get<2 /* PerWorker */>(id_343) };
                                                    ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_345 { std::get<1>(id_344) };
                                                    uint32_t id_346 { std::get<7 /* PerReplayer */>(id_345) };
                                                    Pointer id_347 { ssum_dst_797.writeU32Le(id_346) };
                                                    choose_res_341 = id_347;
                                                  } else {
                                                    uint16_t id_348 { 8 };
                                                    bool id_349 { bool(label1_796 == id_348) };
                                                    Void id_350 { ((void)(assert(id_349)), VOID) };
                                                    (void)id_350;
                                                    choose_res_341 = ssum_dst_797;
                                                  }
                                                  choose_res_253 = choose_res_341;
                                                }
                                                choose_res_250 = choose_res_253;
                                              }
                                              choose_res_247 = choose_res_250;
                                            }
                                            choose_res_244 = choose_res_247;
                                          }
                                          choose_res_241 = choose_res_244;
                                        }
                                        choose_res_238 = choose_res_241;
                                      }
                                      choose_res_235 = choose_res_238;
                                    }
                                    let_res_232 = choose_res_235;
                                  }
                                  let_res_230 = let_res_232;
                                }
                                let_res_224 = let_res_230;
                              }
                              choose_res_217 = let_res_224;
                            } else {
                              ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_351 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_352 { std::get<1>(id_351) };
                              uint16_t id_353 { uint16_t(id_352.index()) };
                              uint16_t id_354 { 3 };
                              bool id_355 { bool(id_353 == id_354) };
                              Void id_356 { ((void)(assert(id_355)), VOID) };
                              (void)id_356;
                              ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_357 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_358 { std::get<1>(id_357) };
                              ::dessser::gen::sync_key::tb761ebb9c7c72cccd366042890abdac8 id_359 { std::get<3 /* PerProgram */>(id_358) };
                              std::string id_360 { std::get<0>(id_359) };
                              uint32_t id_361 { (uint32_t)id_360.size() };
                              Vec<1, uint32_t> id_362 {  id_361  };
                              Pointer let_res_363;
                              {
                                Vec<1, uint32_t> leb128_sz_790 { id_362 };
                                Vec<1, Pointer> id_364 {  ssum_dst_789  };
                                Pointer let_res_365;
                                {
                                  Vec<1, Pointer> leb128_ptr_791 { id_364 };
                                  bool while_flag_366 { true };
                                  do {
                                    uint8_t id_367 { 0 };
                                    uint8_t id_368 { 0 };
                                    Pointer id_369 { leb128_ptr_791[id_368] };
                                    uint32_t id_370 { 128U };
                                    uint8_t id_371 { 0 };
                                    uint32_t id_372 { leb128_sz_790[id_371] };
                                    bool id_373 { bool(id_370 > id_372) };
                                    uint8_t choose_res_374;
                                    if (id_373) {
                                      uint8_t id_375 { 0 };
                                      uint32_t id_376 { leb128_sz_790[id_375] };
                                      uint8_t id_377 { uint8_t(id_376) };
                                      choose_res_374 = id_377;
                                    } else {
                                      uint8_t id_378 { 0 };
                                      uint32_t id_379 { leb128_sz_790[id_378] };
                                      uint8_t id_380 { uint8_t(id_379) };
                                      uint8_t id_381 { 128 };
                                      uint8_t id_382 { uint8_t(id_380 | id_381) };
                                      choose_res_374 = id_382;
                                    }
                                    Pointer id_383 { id_369.writeU8(choose_res_374) };
                                    Void id_384 { ((void)(leb128_ptr_791[id_367] = id_383), VOID) };
                                    (void)id_384;
                                    uint8_t id_385 { 0 };
                                    uint8_t id_386 { 0 };
                                    uint32_t id_387 { leb128_sz_790[id_386] };
                                    uint8_t id_388 { 7 };
                                    uint32_t id_389 { uint32_t(id_387 >> id_388) };
                                    Void id_390 { ((void)(leb128_sz_790[id_385] = id_389), VOID) };
                                    (void)id_390;
                                    uint8_t id_391 { 0 };
                                    uint32_t id_392 { leb128_sz_790[id_391] };
                                    uint32_t id_393 { 0U };
                                    bool id_394 { bool(id_392 > id_393) };
                                    while_flag_366 = id_394;
                                    if (while_flag_366) {
                                      (void)VOID;
                                    }
                                  } while (while_flag_366);
                                  (void)VOID;
                                  uint8_t id_395 { 0 };
                                  Pointer id_396 { leb128_ptr_791[id_395] };
                                  let_res_365 = id_396;
                                }
                                let_res_363 = let_res_365;
                              }
                              ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_397 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_398 { std::get<1>(id_397) };
                              ::dessser::gen::sync_key::tb761ebb9c7c72cccd366042890abdac8 id_399 { std::get<3 /* PerProgram */>(id_398) };
                              std::string id_400 { std::get<0>(id_399) };
                              Bytes id_401 { id_400 };
                              Pointer id_402 { let_res_363.writeBytes(id_401) };
                              Pointer let_res_403;
                              {
                                Pointer stup_dst_792 { id_402 };
                                ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_404 { std::get<5 /* PerSite */>((*p_0)) };
                                ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_405 { std::get<1>(id_404) };
                                ::dessser::gen::sync_key::tb761ebb9c7c72cccd366042890abdac8 id_406 { std::get<3 /* PerProgram */>(id_405) };
                                ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_407 { std::get<1>(id_406) };
                                uint16_t id_408 { uint16_t(id_407.index()) };
                                Pointer id_409 { stup_dst_792.writeU16Le(id_408) };
                                Pointer let_res_410;
                                {
                                  Pointer ssum_dst_794 { id_409 };
                                  ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_411 { std::get<5 /* PerSite */>((*p_0)) };
                                  ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_412 { std::get<1>(id_411) };
                                  ::dessser::gen::sync_key::tb761ebb9c7c72cccd366042890abdac8 id_413 { std::get<3 /* PerProgram */>(id_412) };
                                  ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_414 { std::get<1>(id_413) };
                                  uint16_t id_415 { uint16_t(id_414.index()) };
                                  uint16_t id_416 { 0 };
                                  bool id_417 { bool(id_415 == id_416) };
                                  Void id_418 { ((void)(assert(id_417)), VOID) };
                                  (void)id_418;
                                  let_res_410 = ssum_dst_794;
                                }
                                let_res_403 = let_res_410;
                              }
                              choose_res_217 = let_res_403;
                            }
                            choose_res_141 = choose_res_217;
                          }
                          choose_res_135 = choose_res_141;
                        }
                        let_res_129 = choose_res_135;
                      }
                      let_res_124 = let_res_129;
                    }
                    choose_res_119 = let_res_124;
                  } else {
                    uint16_t id_419 { 6 };
                    bool id_420 { bool(id_419 == label1_744) };
                    Pointer choose_res_421;
                    if (id_420) {
                      ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_422 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_423 { uint16_t(id_422.index()) };
                      Pointer id_424 { ssum_dst_745.writeU16Le(id_423) };
                      Pointer let_res_425;
                      {
                        Pointer ssum_dst_784 { id_424 };
                        uint16_t id_426 { 0 };
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_427 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_428 { uint16_t(id_427.index()) };
                        bool id_429 { bool(id_426 == id_428) };
                        Pointer choose_res_430;
                        if (id_429) {
                          choose_res_430 = ssum_dst_784;
                        } else {
                          uint16_t id_431 { 1 };
                          ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_432 { std::get<6 /* Storage */>((*p_0)) };
                          uint16_t id_433 { uint16_t(id_432.index()) };
                          bool id_434 { bool(id_431 == id_433) };
                          Pointer choose_res_435;
                          if (id_434) {
                            choose_res_435 = ssum_dst_784;
                          } else {
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_436 { std::get<6 /* Storage */>((*p_0)) };
                            uint16_t id_437 { uint16_t(id_436.index()) };
                            uint16_t id_438 { 2 };
                            bool id_439 { bool(id_437 == id_438) };
                            Void id_440 { ((void)(assert(id_439)), VOID) };
                            (void)id_440;
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_441 { std::get<6 /* Storage */>((*p_0)) };
                            std::string id_442 { std::get<2 /* RetentionsOverride */>(id_441) };
                            uint32_t id_443 { (uint32_t)id_442.size() };
                            Vec<1, uint32_t> id_444 {  id_443  };
                            Pointer let_res_445;
                            {
                              Vec<1, uint32_t> leb128_sz_785 { id_444 };
                              Vec<1, Pointer> id_446 {  ssum_dst_784  };
                              Pointer let_res_447;
                              {
                                Vec<1, Pointer> leb128_ptr_786 { id_446 };
                                bool while_flag_448 { true };
                                do {
                                  uint8_t id_449 { 0 };
                                  uint8_t id_450 { 0 };
                                  Pointer id_451 { leb128_ptr_786[id_450] };
                                  uint32_t id_452 { 128U };
                                  uint8_t id_453 { 0 };
                                  uint32_t id_454 { leb128_sz_785[id_453] };
                                  bool id_455 { bool(id_452 > id_454) };
                                  uint8_t choose_res_456;
                                  if (id_455) {
                                    uint8_t id_457 { 0 };
                                    uint32_t id_458 { leb128_sz_785[id_457] };
                                    uint8_t id_459 { uint8_t(id_458) };
                                    choose_res_456 = id_459;
                                  } else {
                                    uint8_t id_460 { 0 };
                                    uint32_t id_461 { leb128_sz_785[id_460] };
                                    uint8_t id_462 { uint8_t(id_461) };
                                    uint8_t id_463 { 128 };
                                    uint8_t id_464 { uint8_t(id_462 | id_463) };
                                    choose_res_456 = id_464;
                                  }
                                  Pointer id_465 { id_451.writeU8(choose_res_456) };
                                  Void id_466 { ((void)(leb128_ptr_786[id_449] = id_465), VOID) };
                                  (void)id_466;
                                  uint8_t id_467 { 0 };
                                  uint8_t id_468 { 0 };
                                  uint32_t id_469 { leb128_sz_785[id_468] };
                                  uint8_t id_470 { 7 };
                                  uint32_t id_471 { uint32_t(id_469 >> id_470) };
                                  Void id_472 { ((void)(leb128_sz_785[id_467] = id_471), VOID) };
                                  (void)id_472;
                                  uint8_t id_473 { 0 };
                                  uint32_t id_474 { leb128_sz_785[id_473] };
                                  uint32_t id_475 { 0U };
                                  bool id_476 { bool(id_474 > id_475) };
                                  while_flag_448 = id_476;
                                  if (while_flag_448) {
                                    (void)VOID;
                                  }
                                } while (while_flag_448);
                                (void)VOID;
                                uint8_t id_477 { 0 };
                                Pointer id_478 { leb128_ptr_786[id_477] };
                                let_res_447 = id_478;
                              }
                              let_res_445 = let_res_447;
                            }
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_479 { std::get<6 /* Storage */>((*p_0)) };
                            std::string id_480 { std::get<2 /* RetentionsOverride */>(id_479) };
                            Bytes id_481 { id_480 };
                            Pointer id_482 { let_res_445.writeBytes(id_481) };
                            choose_res_435 = id_482;
                          }
                          choose_res_430 = choose_res_435;
                        }
                        let_res_425 = choose_res_430;
                      }
                      choose_res_421 = let_res_425;
                    } else {
                      uint16_t id_483 { 7 };
                      bool id_484 { bool(id_483 == label1_744) };
                      Pointer choose_res_485;
                      if (id_484) {
                        auto fun486 { dessser::gen::site_name::to_row_binary };
                        ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_487 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::site_name::t_ext id_488 { std::get<0>(id_487) };
                        Pointer id_489 { fun486(id_488, ssum_dst_745) };
                        Pointer let_res_490;
                        {
                          Pointer stup_dst_774 { id_489 };
                          auto fun491 { dessser::gen::fq_name::to_row_binary };
                          ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_492 { std::get<7 /* Tails */>((*p_0)) };
                          dessser::gen::fq_name::t_ext id_493 { std::get<1>(id_492) };
                          Pointer id_494 { fun491(id_493, stup_dst_774) };
                          let_res_490 = id_494;
                        }
                        Pointer let_res_495;
                        {
                          Pointer stup_dst_775 { let_res_490 };
                          ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_496 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_497 { std::get<2>(id_496) };
                          uint32_t id_498 { (uint32_t)id_497.size() };
                          Vec<1, uint32_t> id_499 {  id_498  };
                          Pointer let_res_500;
                          {
                            Vec<1, uint32_t> leb128_sz_776 { id_499 };
                            Vec<1, Pointer> id_501 {  stup_dst_775  };
                            Pointer let_res_502;
                            {
                              Vec<1, Pointer> leb128_ptr_777 { id_501 };
                              bool while_flag_503 { true };
                              do {
                                uint8_t id_504 { 0 };
                                uint8_t id_505 { 0 };
                                Pointer id_506 { leb128_ptr_777[id_505] };
                                uint32_t id_507 { 128U };
                                uint8_t id_508 { 0 };
                                uint32_t id_509 { leb128_sz_776[id_508] };
                                bool id_510 { bool(id_507 > id_509) };
                                uint8_t choose_res_511;
                                if (id_510) {
                                  uint8_t id_512 { 0 };
                                  uint32_t id_513 { leb128_sz_776[id_512] };
                                  uint8_t id_514 { uint8_t(id_513) };
                                  choose_res_511 = id_514;
                                } else {
                                  uint8_t id_515 { 0 };
                                  uint32_t id_516 { leb128_sz_776[id_515] };
                                  uint8_t id_517 { uint8_t(id_516) };
                                  uint8_t id_518 { 128 };
                                  uint8_t id_519 { uint8_t(id_517 | id_518) };
                                  choose_res_511 = id_519;
                                }
                                Pointer id_520 { id_506.writeU8(choose_res_511) };
                                Void id_521 { ((void)(leb128_ptr_777[id_504] = id_520), VOID) };
                                (void)id_521;
                                uint8_t id_522 { 0 };
                                uint8_t id_523 { 0 };
                                uint32_t id_524 { leb128_sz_776[id_523] };
                                uint8_t id_525 { 7 };
                                uint32_t id_526 { uint32_t(id_524 >> id_525) };
                                Void id_527 { ((void)(leb128_sz_776[id_522] = id_526), VOID) };
                                (void)id_527;
                                uint8_t id_528 { 0 };
                                uint32_t id_529 { leb128_sz_776[id_528] };
                                uint32_t id_530 { 0U };
                                bool id_531 { bool(id_529 > id_530) };
                                while_flag_503 = id_531;
                                if (while_flag_503) {
                                  (void)VOID;
                                }
                              } while (while_flag_503);
                              (void)VOID;
                              uint8_t id_532 { 0 };
                              Pointer id_533 { leb128_ptr_777[id_532] };
                              let_res_502 = id_533;
                            }
                            let_res_500 = let_res_502;
                          }
                          ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_534 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_535 { std::get<2>(id_534) };
                          Bytes id_536 { id_535 };
                          Pointer id_537 { let_res_500.writeBytes(id_536) };
                          let_res_495 = id_537;
                        }
                        Pointer let_res_538;
                        {
                          Pointer stup_dst_778 { let_res_495 };
                          ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_539 { std::get<7 /* Tails */>((*p_0)) };
                          ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_540 { std::get<3>(id_539) };
                          uint16_t id_541 { uint16_t(id_540.index()) };
                          Pointer id_542 { stup_dst_778.writeU16Le(id_541) };
                          Pointer let_res_543;
                          {
                            Pointer ssum_dst_780 { id_542 };
                            uint16_t id_544 { 0 };
                            ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_545 { std::get<7 /* Tails */>((*p_0)) };
                            ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_546 { std::get<3>(id_545) };
                            uint16_t id_547 { uint16_t(id_546.index()) };
                            bool id_548 { bool(id_544 == id_547) };
                            Pointer choose_res_549;
                            if (id_548) {
                              ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_550 { std::get<7 /* Tails */>((*p_0)) };
                              ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_551 { std::get<3>(id_550) };
                              std::string id_552 { std::get<0 /* Subscriber */>(id_551) };
                              uint32_t id_553 { (uint32_t)id_552.size() };
                              Vec<1, uint32_t> id_554 {  id_553  };
                              Pointer let_res_555;
                              {
                                Vec<1, uint32_t> leb128_sz_781 { id_554 };
                                Vec<1, Pointer> id_556 {  ssum_dst_780  };
                                Pointer let_res_557;
                                {
                                  Vec<1, Pointer> leb128_ptr_782 { id_556 };
                                  bool while_flag_558 { true };
                                  do {
                                    uint8_t id_559 { 0 };
                                    uint8_t id_560 { 0 };
                                    Pointer id_561 { leb128_ptr_782[id_560] };
                                    uint32_t id_562 { 128U };
                                    uint8_t id_563 { 0 };
                                    uint32_t id_564 { leb128_sz_781[id_563] };
                                    bool id_565 { bool(id_562 > id_564) };
                                    uint8_t choose_res_566;
                                    if (id_565) {
                                      uint8_t id_567 { 0 };
                                      uint32_t id_568 { leb128_sz_781[id_567] };
                                      uint8_t id_569 { uint8_t(id_568) };
                                      choose_res_566 = id_569;
                                    } else {
                                      uint8_t id_570 { 0 };
                                      uint32_t id_571 { leb128_sz_781[id_570] };
                                      uint8_t id_572 { uint8_t(id_571) };
                                      uint8_t id_573 { 128 };
                                      uint8_t id_574 { uint8_t(id_572 | id_573) };
                                      choose_res_566 = id_574;
                                    }
                                    Pointer id_575 { id_561.writeU8(choose_res_566) };
                                    Void id_576 { ((void)(leb128_ptr_782[id_559] = id_575), VOID) };
                                    (void)id_576;
                                    uint8_t id_577 { 0 };
                                    uint8_t id_578 { 0 };
                                    uint32_t id_579 { leb128_sz_781[id_578] };
                                    uint8_t id_580 { 7 };
                                    uint32_t id_581 { uint32_t(id_579 >> id_580) };
                                    Void id_582 { ((void)(leb128_sz_781[id_577] = id_581), VOID) };
                                    (void)id_582;
                                    uint8_t id_583 { 0 };
                                    uint32_t id_584 { leb128_sz_781[id_583] };
                                    uint32_t id_585 { 0U };
                                    bool id_586 { bool(id_584 > id_585) };
                                    while_flag_558 = id_586;
                                    if (while_flag_558) {
                                      (void)VOID;
                                    }
                                  } while (while_flag_558);
                                  (void)VOID;
                                  uint8_t id_587 { 0 };
                                  Pointer id_588 { leb128_ptr_782[id_587] };
                                  let_res_557 = id_588;
                                }
                                let_res_555 = let_res_557;
                              }
                              ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_589 { std::get<7 /* Tails */>((*p_0)) };
                              ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_590 { std::get<3>(id_589) };
                              std::string id_591 { std::get<0 /* Subscriber */>(id_590) };
                              Bytes id_592 { id_591 };
                              Pointer id_593 { let_res_555.writeBytes(id_592) };
                              choose_res_549 = id_593;
                            } else {
                              ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_594 { std::get<7 /* Tails */>((*p_0)) };
                              ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_595 { std::get<3>(id_594) };
                              uint16_t id_596 { uint16_t(id_595.index()) };
                              uint16_t id_597 { 1 };
                              bool id_598 { bool(id_596 == id_597) };
                              Void id_599 { ((void)(assert(id_598)), VOID) };
                              (void)id_599;
                              ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_600 { std::get<7 /* Tails */>((*p_0)) };
                              ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_601 { std::get<3>(id_600) };
                              uint32_t id_602 { std::get<1 /* LastTuple */>(id_601) };
                              Pointer id_603 { ssum_dst_780.writeU32Le(id_602) };
                              choose_res_549 = id_603;
                            }
                            let_res_543 = choose_res_549;
                          }
                          let_res_538 = let_res_543;
                        }
                        choose_res_485 = let_res_538;
                      } else {
                        uint16_t id_604 { 8 };
                        bool id_605 { bool(id_604 == label1_744) };
                        Pointer choose_res_606;
                        if (id_605) {
                          uint16_t id_607 { std::get<8 /* Replays */>((*p_0)) };
                          Pointer id_608 { ssum_dst_745.writeU16Le(id_607) };
                          choose_res_606 = id_608;
                        } else {
                          uint16_t id_609 { 9 };
                          bool id_610 { bool(id_609 == label1_744) };
                          Pointer choose_res_611;
                          if (id_610) {
                            std::optional<dessser::gen::sync_socket::t_ext> id_612 { std::get<9 /* Error */>((*p_0)) };
                            bool id_613 { !(id_612.has_value ()) };
                            Pointer choose_res_614;
                            if (id_613) {
                              uint8_t id_615 { 1 };
                              Pointer id_616 { ssum_dst_745.writeU8(id_615) };
                              choose_res_614 = id_616;
                            } else {
                              auto fun617 { dessser::gen::sync_socket::to_row_binary };
                              std::optional<dessser::gen::sync_socket::t_ext> id_618 { std::get<9 /* Error */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_619 { id_618.value() };
                              uint8_t id_620 { 0 };
                              Pointer id_621 { ssum_dst_745.writeU8(id_620) };
                              Pointer id_622 { fun617(id_619, id_621) };
                              choose_res_614 = id_622;
                            }
                            choose_res_611 = choose_res_614;
                          } else {
                            uint16_t id_623 { 10 };
                            bool id_624 { bool(id_623 == label1_744) };
                            Pointer choose_res_625;
                            if (id_624) {
                              choose_res_625 = ssum_dst_745;
                            } else {
                              uint16_t id_626 { 11 };
                              bool id_627 { bool(id_626 == label1_744) };
                              Pointer choose_res_628;
                              if (id_627) {
                                auto fun629 { dessser::gen::sync_socket::to_row_binary };
                                ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_630 { std::get<11 /* PerClient */>((*p_0)) };
                                dessser::gen::sync_socket::t_ext id_631 { std::get<0>(id_630) };
                                Pointer id_632 { fun629(id_631, ssum_dst_745) };
                                Pointer let_res_633;
                                {
                                  Pointer stup_dst_769 { id_632 };
                                  ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_634 { std::get<11 /* PerClient */>((*p_0)) };
                                  ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_635 { std::get<1>(id_634) };
                                  uint16_t id_636 { uint16_t(id_635.index()) };
                                  Pointer id_637 { stup_dst_769.writeU16Le(id_636) };
                                  Pointer let_res_638;
                                  {
                                    Pointer ssum_dst_771 { id_637 };
                                    uint16_t id_639 { 0 };
                                    ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_640 { std::get<11 /* PerClient */>((*p_0)) };
                                    ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_641 { std::get<1>(id_640) };
                                    uint16_t id_642 { uint16_t(id_641.index()) };
                                    bool id_643 { bool(id_639 == id_642) };
                                    Pointer choose_res_644;
                                    if (id_643) {
                                      ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_645 { std::get<11 /* PerClient */>((*p_0)) };
                                      ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_646 { std::get<1>(id_645) };
                                      std::string id_647 { std::get<0 /* Response */>(id_646) };
                                      uint32_t id_648 { (uint32_t)id_647.size() };
                                      Vec<1, uint32_t> id_649 {  id_648  };
                                      Pointer let_res_650;
                                      {
                                        Vec<1, uint32_t> leb128_sz_772 { id_649 };
                                        Vec<1, Pointer> id_651 {  ssum_dst_771  };
                                        Pointer let_res_652;
                                        {
                                          Vec<1, Pointer> leb128_ptr_773 { id_651 };
                                          bool while_flag_653 { true };
                                          do {
                                            uint8_t id_654 { 0 };
                                            uint8_t id_655 { 0 };
                                            Pointer id_656 { leb128_ptr_773[id_655] };
                                            uint32_t id_657 { 128U };
                                            uint8_t id_658 { 0 };
                                            uint32_t id_659 { leb128_sz_772[id_658] };
                                            bool id_660 { bool(id_657 > id_659) };
                                            uint8_t choose_res_661;
                                            if (id_660) {
                                              uint8_t id_662 { 0 };
                                              uint32_t id_663 { leb128_sz_772[id_662] };
                                              uint8_t id_664 { uint8_t(id_663) };
                                              choose_res_661 = id_664;
                                            } else {
                                              uint8_t id_665 { 0 };
                                              uint32_t id_666 { leb128_sz_772[id_665] };
                                              uint8_t id_667 { uint8_t(id_666) };
                                              uint8_t id_668 { 128 };
                                              uint8_t id_669 { uint8_t(id_667 | id_668) };
                                              choose_res_661 = id_669;
                                            }
                                            Pointer id_670 { id_656.writeU8(choose_res_661) };
                                            Void id_671 { ((void)(leb128_ptr_773[id_654] = id_670), VOID) };
                                            (void)id_671;
                                            uint8_t id_672 { 0 };
                                            uint8_t id_673 { 0 };
                                            uint32_t id_674 { leb128_sz_772[id_673] };
                                            uint8_t id_675 { 7 };
                                            uint32_t id_676 { uint32_t(id_674 >> id_675) };
                                            Void id_677 { ((void)(leb128_sz_772[id_672] = id_676), VOID) };
                                            (void)id_677;
                                            uint8_t id_678 { 0 };
                                            uint32_t id_679 { leb128_sz_772[id_678] };
                                            uint32_t id_680 { 0U };
                                            bool id_681 { bool(id_679 > id_680) };
                                            while_flag_653 = id_681;
                                            if (while_flag_653) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_653);
                                          (void)VOID;
                                          uint8_t id_682 { 0 };
                                          Pointer id_683 { leb128_ptr_773[id_682] };
                                          let_res_652 = id_683;
                                        }
                                        let_res_650 = let_res_652;
                                      }
                                      ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_684 { std::get<11 /* PerClient */>((*p_0)) };
                                      ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_685 { std::get<1>(id_684) };
                                      std::string id_686 { std::get<0 /* Response */>(id_685) };
                                      Bytes id_687 { id_686 };
                                      Pointer id_688 { let_res_650.writeBytes(id_687) };
                                      choose_res_644 = id_688;
                                    } else {
                                      ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_689 { std::get<11 /* PerClient */>((*p_0)) };
                                      ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_690 { std::get<1>(id_689) };
                                      uint16_t id_691 { uint16_t(id_690.index()) };
                                      uint16_t id_692 { 1 };
                                      bool id_693 { bool(id_691 == id_692) };
                                      Void id_694 { ((void)(assert(id_693)), VOID) };
                                      (void)id_694;
                                      ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_695 { std::get<11 /* PerClient */>((*p_0)) };
                                      ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_696 { std::get<1>(id_695) };
                                      ::dessser::gen::sync_key::per_dash_key* id_697 { std::get<1 /* Scratchpad */>(id_696) };
                                      Pointer id_698 { per_dash_key_to_row_binary(id_697, ssum_dst_771) };
                                      choose_res_644 = id_698;
                                    }
                                    let_res_638 = choose_res_644;
                                  }
                                  let_res_633 = let_res_638;
                                }
                                choose_res_628 = let_res_633;
                              } else {
                                uint16_t id_699 { 12 };
                                bool id_700 { bool(id_699 == label1_744) };
                                Pointer choose_res_701;
                                if (id_700) {
                                  ::dessser::gen::sync_key::tdf6d0a87bf373d7d4ea33113dc8a8b30 id_702 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_703 { std::get<0>(id_702) };
                                  uint32_t id_704 { (uint32_t)id_703.size() };
                                  Vec<1, uint32_t> id_705 {  id_704  };
                                  Pointer let_res_706;
                                  {
                                    Vec<1, uint32_t> leb128_sz_766 { id_705 };
                                    Vec<1, Pointer> id_707 {  ssum_dst_745  };
                                    Pointer let_res_708;
                                    {
                                      Vec<1, Pointer> leb128_ptr_767 { id_707 };
                                      bool while_flag_709 { true };
                                      do {
                                        uint8_t id_710 { 0 };
                                        uint8_t id_711 { 0 };
                                        Pointer id_712 { leb128_ptr_767[id_711] };
                                        uint32_t id_713 { 128U };
                                        uint8_t id_714 { 0 };
                                        uint32_t id_715 { leb128_sz_766[id_714] };
                                        bool id_716 { bool(id_713 > id_715) };
                                        uint8_t choose_res_717;
                                        if (id_716) {
                                          uint8_t id_718 { 0 };
                                          uint32_t id_719 { leb128_sz_766[id_718] };
                                          uint8_t id_720 { uint8_t(id_719) };
                                          choose_res_717 = id_720;
                                        } else {
                                          uint8_t id_721 { 0 };
                                          uint32_t id_722 { leb128_sz_766[id_721] };
                                          uint8_t id_723 { uint8_t(id_722) };
                                          uint8_t id_724 { 128 };
                                          uint8_t id_725 { uint8_t(id_723 | id_724) };
                                          choose_res_717 = id_725;
                                        }
                                        Pointer id_726 { id_712.writeU8(choose_res_717) };
                                        Void id_727 { ((void)(leb128_ptr_767[id_710] = id_726), VOID) };
                                        (void)id_727;
                                        uint8_t id_728 { 0 };
                                        uint8_t id_729 { 0 };
                                        uint32_t id_730 { leb128_sz_766[id_729] };
                                        uint8_t id_731 { 7 };
                                        uint32_t id_732 { uint32_t(id_730 >> id_731) };
                                        Void id_733 { ((void)(leb128_sz_766[id_728] = id_732), VOID) };
                                        (void)id_733;
                                        uint8_t id_734 { 0 };
                                        uint32_t id_735 { leb128_sz_766[id_734] };
                                        uint32_t id_736 { 0U };
                                        bool id_737 { bool(id_735 > id_736) };
                                        while_flag_709 = id_737;
                                        if (while_flag_709) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_709);
                                      (void)VOID;
                                      uint8_t id_738 { 0 };
                                      Pointer id_739 { leb128_ptr_767[id_738] };
                                      let_res_708 = id_739;
                                    }
                                    let_res_706 = let_res_708;
                                  }
                                  ::dessser::gen::sync_key::tdf6d0a87bf373d7d4ea33113dc8a8b30 id_740 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_741 { std::get<0>(id_740) };
                                  Bytes id_742 { id_741 };
                                  Pointer id_743 { let_res_706.writeBytes(id_742) };
                                  Pointer let_res_744;
                                  {
                                    Pointer stup_dst_768 { id_743 };
                                    ::dessser::gen::sync_key::tdf6d0a87bf373d7d4ea33113dc8a8b30 id_745 { std::get<12 /* Dashboards */>((*p_0)) };
                                    per_dash_key* id_746 { std::get<1>(id_745) };
                                    Pointer id_747 { per_dash_key_to_row_binary(id_746, stup_dst_768) };
                                    let_res_744 = id_747;
                                  }
                                  choose_res_701 = let_res_744;
                                } else {
                                  uint16_t id_748 { 13 };
                                  bool id_749 { bool(id_748 == label1_744) };
                                  Pointer choose_res_750;
                                  if (id_749) {
                                    choose_res_750 = ssum_dst_745;
                                  } else {
                                    uint16_t id_751 { 14 };
                                    bool id_752 { bool(id_751 == label1_744) };
                                    Pointer choose_res_753;
                                    if (id_752) {
                                      ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_754 { std::get<14 /* Teams */>((*p_0)) };
                                      std::string id_755 { std::get<0>(id_754) };
                                      uint32_t id_756 { (uint32_t)id_755.size() };
                                      Vec<1, uint32_t> id_757 {  id_756  };
                                      Pointer let_res_758;
                                      {
                                        Vec<1, uint32_t> leb128_sz_757 { id_757 };
                                        Vec<1, Pointer> id_759 {  ssum_dst_745  };
                                        Pointer let_res_760;
                                        {
                                          Vec<1, Pointer> leb128_ptr_758 { id_759 };
                                          bool while_flag_761 { true };
                                          do {
                                            uint8_t id_762 { 0 };
                                            uint8_t id_763 { 0 };
                                            Pointer id_764 { leb128_ptr_758[id_763] };
                                            uint32_t id_765 { 128U };
                                            uint8_t id_766 { 0 };
                                            uint32_t id_767 { leb128_sz_757[id_766] };
                                            bool id_768 { bool(id_765 > id_767) };
                                            uint8_t choose_res_769;
                                            if (id_768) {
                                              uint8_t id_770 { 0 };
                                              uint32_t id_771 { leb128_sz_757[id_770] };
                                              uint8_t id_772 { uint8_t(id_771) };
                                              choose_res_769 = id_772;
                                            } else {
                                              uint8_t id_773 { 0 };
                                              uint32_t id_774 { leb128_sz_757[id_773] };
                                              uint8_t id_775 { uint8_t(id_774) };
                                              uint8_t id_776 { 128 };
                                              uint8_t id_777 { uint8_t(id_775 | id_776) };
                                              choose_res_769 = id_777;
                                            }
                                            Pointer id_778 { id_764.writeU8(choose_res_769) };
                                            Void id_779 { ((void)(leb128_ptr_758[id_762] = id_778), VOID) };
                                            (void)id_779;
                                            uint8_t id_780 { 0 };
                                            uint8_t id_781 { 0 };
                                            uint32_t id_782 { leb128_sz_757[id_781] };
                                            uint8_t id_783 { 7 };
                                            uint32_t id_784 { uint32_t(id_782 >> id_783) };
                                            Void id_785 { ((void)(leb128_sz_757[id_780] = id_784), VOID) };
                                            (void)id_785;
                                            uint8_t id_786 { 0 };
                                            uint32_t id_787 { leb128_sz_757[id_786] };
                                            uint32_t id_788 { 0U };
                                            bool id_789 { bool(id_787 > id_788) };
                                            while_flag_761 = id_789;
                                            if (while_flag_761) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_761);
                                          (void)VOID;
                                          uint8_t id_790 { 0 };
                                          Pointer id_791 { leb128_ptr_758[id_790] };
                                          let_res_760 = id_791;
                                        }
                                        let_res_758 = let_res_760;
                                      }
                                      ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_792 { std::get<14 /* Teams */>((*p_0)) };
                                      std::string id_793 { std::get<0>(id_792) };
                                      Bytes id_794 { id_793 };
                                      Pointer id_795 { let_res_758.writeBytes(id_794) };
                                      Pointer let_res_796;
                                      {
                                        Pointer stup_dst_759 { id_795 };
                                        ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_797 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_798 { std::get<1>(id_797) };
                                        uint16_t id_799 { uint16_t(id_798.index()) };
                                        Pointer id_800 { stup_dst_759.writeU16Le(id_799) };
                                        Pointer let_res_801;
                                        {
                                          Pointer ssum_dst_761 { id_800 };
                                          uint16_t id_802 { 0 };
                                          ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_803 { std::get<14 /* Teams */>((*p_0)) };
                                          ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_804 { std::get<1>(id_803) };
                                          uint16_t id_805 { uint16_t(id_804.index()) };
                                          bool id_806 { bool(id_802 == id_805) };
                                          Pointer choose_res_807;
                                          if (id_806) {
                                            ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_808 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_809 { std::get<1>(id_808) };
                                            std::string id_810 { std::get<0 /* Contacts */>(id_809) };
                                            uint32_t id_811 { (uint32_t)id_810.size() };
                                            Vec<1, uint32_t> id_812 {  id_811  };
                                            Pointer let_res_813;
                                            {
                                              Vec<1, uint32_t> leb128_sz_764 { id_812 };
                                              Vec<1, Pointer> id_814 {  ssum_dst_761  };
                                              Pointer let_res_815;
                                              {
                                                Vec<1, Pointer> leb128_ptr_765 { id_814 };
                                                bool while_flag_816 { true };
                                                do {
                                                  uint8_t id_817 { 0 };
                                                  uint8_t id_818 { 0 };
                                                  Pointer id_819 { leb128_ptr_765[id_818] };
                                                  uint32_t id_820 { 128U };
                                                  uint8_t id_821 { 0 };
                                                  uint32_t id_822 { leb128_sz_764[id_821] };
                                                  bool id_823 { bool(id_820 > id_822) };
                                                  uint8_t choose_res_824;
                                                  if (id_823) {
                                                    uint8_t id_825 { 0 };
                                                    uint32_t id_826 { leb128_sz_764[id_825] };
                                                    uint8_t id_827 { uint8_t(id_826) };
                                                    choose_res_824 = id_827;
                                                  } else {
                                                    uint8_t id_828 { 0 };
                                                    uint32_t id_829 { leb128_sz_764[id_828] };
                                                    uint8_t id_830 { uint8_t(id_829) };
                                                    uint8_t id_831 { 128 };
                                                    uint8_t id_832 { uint8_t(id_830 | id_831) };
                                                    choose_res_824 = id_832;
                                                  }
                                                  Pointer id_833 { id_819.writeU8(choose_res_824) };
                                                  Void id_834 { ((void)(leb128_ptr_765[id_817] = id_833), VOID) };
                                                  (void)id_834;
                                                  uint8_t id_835 { 0 };
                                                  uint8_t id_836 { 0 };
                                                  uint32_t id_837 { leb128_sz_764[id_836] };
                                                  uint8_t id_838 { 7 };
                                                  uint32_t id_839 { uint32_t(id_837 >> id_838) };
                                                  Void id_840 { ((void)(leb128_sz_764[id_835] = id_839), VOID) };
                                                  (void)id_840;
                                                  uint8_t id_841 { 0 };
                                                  uint32_t id_842 { leb128_sz_764[id_841] };
                                                  uint32_t id_843 { 0U };
                                                  bool id_844 { bool(id_842 > id_843) };
                                                  while_flag_816 = id_844;
                                                  if (while_flag_816) {
                                                    (void)VOID;
                                                  }
                                                } while (while_flag_816);
                                                (void)VOID;
                                                uint8_t id_845 { 0 };
                                                Pointer id_846 { leb128_ptr_765[id_845] };
                                                let_res_815 = id_846;
                                              }
                                              let_res_813 = let_res_815;
                                            }
                                            ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_847 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_848 { std::get<1>(id_847) };
                                            std::string id_849 { std::get<0 /* Contacts */>(id_848) };
                                            Bytes id_850 { id_849 };
                                            Pointer id_851 { let_res_813.writeBytes(id_850) };
                                            choose_res_807 = id_851;
                                          } else {
                                            ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_852 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_853 { std::get<1>(id_852) };
                                            uint16_t id_854 { uint16_t(id_853.index()) };
                                            uint16_t id_855 { 1 };
                                            bool id_856 { bool(id_854 == id_855) };
                                            Void id_857 { ((void)(assert(id_856)), VOID) };
                                            (void)id_857;
                                            ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_858 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_859 { std::get<1>(id_858) };
                                            std::string id_860 { std::get<1 /* Inhibition */>(id_859) };
                                            uint32_t id_861 { (uint32_t)id_860.size() };
                                            Vec<1, uint32_t> id_862 {  id_861  };
                                            Pointer let_res_863;
                                            {
                                              Vec<1, uint32_t> leb128_sz_762 { id_862 };
                                              Vec<1, Pointer> id_864 {  ssum_dst_761  };
                                              Pointer let_res_865;
                                              {
                                                Vec<1, Pointer> leb128_ptr_763 { id_864 };
                                                bool while_flag_866 { true };
                                                do {
                                                  uint8_t id_867 { 0 };
                                                  uint8_t id_868 { 0 };
                                                  Pointer id_869 { leb128_ptr_763[id_868] };
                                                  uint32_t id_870 { 128U };
                                                  uint8_t id_871 { 0 };
                                                  uint32_t id_872 { leb128_sz_762[id_871] };
                                                  bool id_873 { bool(id_870 > id_872) };
                                                  uint8_t choose_res_874;
                                                  if (id_873) {
                                                    uint8_t id_875 { 0 };
                                                    uint32_t id_876 { leb128_sz_762[id_875] };
                                                    uint8_t id_877 { uint8_t(id_876) };
                                                    choose_res_874 = id_877;
                                                  } else {
                                                    uint8_t id_878 { 0 };
                                                    uint32_t id_879 { leb128_sz_762[id_878] };
                                                    uint8_t id_880 { uint8_t(id_879) };
                                                    uint8_t id_881 { 128 };
                                                    uint8_t id_882 { uint8_t(id_880 | id_881) };
                                                    choose_res_874 = id_882;
                                                  }
                                                  Pointer id_883 { id_869.writeU8(choose_res_874) };
                                                  Void id_884 { ((void)(leb128_ptr_763[id_867] = id_883), VOID) };
                                                  (void)id_884;
                                                  uint8_t id_885 { 0 };
                                                  uint8_t id_886 { 0 };
                                                  uint32_t id_887 { leb128_sz_762[id_886] };
                                                  uint8_t id_888 { 7 };
                                                  uint32_t id_889 { uint32_t(id_887 >> id_888) };
                                                  Void id_890 { ((void)(leb128_sz_762[id_885] = id_889), VOID) };
                                                  (void)id_890;
                                                  uint8_t id_891 { 0 };
                                                  uint32_t id_892 { leb128_sz_762[id_891] };
                                                  uint32_t id_893 { 0U };
                                                  bool id_894 { bool(id_892 > id_893) };
                                                  while_flag_866 = id_894;
                                                  if (while_flag_866) {
                                                    (void)VOID;
                                                  }
                                                } while (while_flag_866);
                                                (void)VOID;
                                                uint8_t id_895 { 0 };
                                                Pointer id_896 { leb128_ptr_763[id_895] };
                                                let_res_865 = id_896;
                                              }
                                              let_res_863 = let_res_865;
                                            }
                                            ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_897 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_898 { std::get<1>(id_897) };
                                            std::string id_899 { std::get<1 /* Inhibition */>(id_898) };
                                            Bytes id_900 { id_899 };
                                            Pointer id_901 { let_res_863.writeBytes(id_900) };
                                            choose_res_807 = id_901;
                                          }
                                          let_res_801 = choose_res_807;
                                        }
                                        let_res_796 = let_res_801;
                                      }
                                      choose_res_753 = let_res_796;
                                    } else {
                                      uint16_t id_902 { 15 };
                                      bool id_903 { bool(label1_744 == id_902) };
                                      Void id_904 { ((void)(assert(id_903)), VOID) };
                                      (void)id_904;
                                      ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_905 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_906 { std::get<0>(id_905) };
                                      uint32_t id_907 { (uint32_t)id_906.size() };
                                      Vec<1, uint32_t> id_908 {  id_907  };
                                      Pointer let_res_909;
                                      {
                                        Vec<1, uint32_t> leb128_sz_746 { id_908 };
                                        Vec<1, Pointer> id_910 {  ssum_dst_745  };
                                        Pointer let_res_911;
                                        {
                                          Vec<1, Pointer> leb128_ptr_747 { id_910 };
                                          bool while_flag_912 { true };
                                          do {
                                            uint8_t id_913 { 0 };
                                            uint8_t id_914 { 0 };
                                            Pointer id_915 { leb128_ptr_747[id_914] };
                                            uint32_t id_916 { 128U };
                                            uint8_t id_917 { 0 };
                                            uint32_t id_918 { leb128_sz_746[id_917] };
                                            bool id_919 { bool(id_916 > id_918) };
                                            uint8_t choose_res_920;
                                            if (id_919) {
                                              uint8_t id_921 { 0 };
                                              uint32_t id_922 { leb128_sz_746[id_921] };
                                              uint8_t id_923 { uint8_t(id_922) };
                                              choose_res_920 = id_923;
                                            } else {
                                              uint8_t id_924 { 0 };
                                              uint32_t id_925 { leb128_sz_746[id_924] };
                                              uint8_t id_926 { uint8_t(id_925) };
                                              uint8_t id_927 { 128 };
                                              uint8_t id_928 { uint8_t(id_926 | id_927) };
                                              choose_res_920 = id_928;
                                            }
                                            Pointer id_929 { id_915.writeU8(choose_res_920) };
                                            Void id_930 { ((void)(leb128_ptr_747[id_913] = id_929), VOID) };
                                            (void)id_930;
                                            uint8_t id_931 { 0 };
                                            uint8_t id_932 { 0 };
                                            uint32_t id_933 { leb128_sz_746[id_932] };
                                            uint8_t id_934 { 7 };
                                            uint32_t id_935 { uint32_t(id_933 >> id_934) };
                                            Void id_936 { ((void)(leb128_sz_746[id_931] = id_935), VOID) };
                                            (void)id_936;
                                            uint8_t id_937 { 0 };
                                            uint32_t id_938 { leb128_sz_746[id_937] };
                                            uint32_t id_939 { 0U };
                                            bool id_940 { bool(id_938 > id_939) };
                                            while_flag_912 = id_940;
                                            if (while_flag_912) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_912);
                                          (void)VOID;
                                          uint8_t id_941 { 0 };
                                          Pointer id_942 { leb128_ptr_747[id_941] };
                                          let_res_911 = id_942;
                                        }
                                        let_res_909 = let_res_911;
                                      }
                                      ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_943 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_944 { std::get<0>(id_943) };
                                      Bytes id_945 { id_944 };
                                      Pointer id_946 { let_res_909.writeBytes(id_945) };
                                      Pointer let_res_947;
                                      {
                                        Pointer stup_dst_748 { id_946 };
                                        ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_948 { std::get<15 /* Incidents */>((*p_0)) };
                                        ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_949 { std::get<1>(id_948) };
                                        uint16_t id_950 { uint16_t(id_949.index()) };
                                        Pointer let_res_951;
                                        {
                                          uint16_t label1_749 { id_950 };
                                          Pointer id_952 { stup_dst_748.writeU16Le(label1_749) };
                                          Pointer let_res_953;
                                          {
                                            Pointer ssum_dst_750 { id_952 };
                                            uint16_t id_954 { 0 };
                                            bool id_955 { bool(id_954 == label1_749) };
                                            Pointer choose_res_956;
                                            if (id_955) {
                                              choose_res_956 = ssum_dst_750;
                                            } else {
                                              uint16_t id_957 { 1 };
                                              bool id_958 { bool(id_957 == label1_749) };
                                              Pointer choose_res_959;
                                              if (id_958) {
                                                choose_res_959 = ssum_dst_750;
                                              } else {
                                                uint16_t id_960 { 2 };
                                                bool id_961 { bool(id_960 == label1_749) };
                                                Pointer choose_res_962;
                                                if (id_961) {
                                                  choose_res_962 = ssum_dst_750;
                                                } else {
                                                  uint16_t id_963 { 3 };
                                                  bool id_964 { bool(id_963 == label1_749) };
                                                  Pointer choose_res_965;
                                                  if (id_964) {
                                                    choose_res_965 = ssum_dst_750;
                                                  } else {
                                                    uint16_t id_966 { 4 };
                                                    bool id_967 { bool(id_966 == label1_749) };
                                                    Pointer choose_res_968;
                                                    if (id_967) {
                                                      choose_res_968 = ssum_dst_750;
                                                    } else {
                                                      uint16_t id_969 { 5 };
                                                      bool id_970 { bool(id_969 == label1_749) };
                                                      Pointer choose_res_971;
                                                      if (id_970) {
                                                        ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_972 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_973 { std::get<1>(id_972) };
                                                        ::dessser::gen::sync_key::t51130975cc895752ed58d8b9dd6b2622 id_974 { std::get<5 /* Dialogs */>(id_973) };
                                                        std::string id_975 { std::get<0>(id_974) };
                                                        uint32_t id_976 { (uint32_t)id_975.size() };
                                                        Vec<1, uint32_t> id_977 {  id_976  };
                                                        Pointer let_res_978;
                                                        {
                                                          Vec<1, uint32_t> leb128_sz_752 { id_977 };
                                                          Vec<1, Pointer> id_979 {  ssum_dst_750  };
                                                          Pointer let_res_980;
                                                          {
                                                            Vec<1, Pointer> leb128_ptr_753 { id_979 };
                                                            bool while_flag_981 { true };
                                                            do {
                                                              uint8_t id_982 { 0 };
                                                              uint8_t id_983 { 0 };
                                                              Pointer id_984 { leb128_ptr_753[id_983] };
                                                              uint32_t id_985 { 128U };
                                                              uint8_t id_986 { 0 };
                                                              uint32_t id_987 { leb128_sz_752[id_986] };
                                                              bool id_988 { bool(id_985 > id_987) };
                                                              uint8_t choose_res_989;
                                                              if (id_988) {
                                                                uint8_t id_990 { 0 };
                                                                uint32_t id_991 { leb128_sz_752[id_990] };
                                                                uint8_t id_992 { uint8_t(id_991) };
                                                                choose_res_989 = id_992;
                                                              } else {
                                                                uint8_t id_993 { 0 };
                                                                uint32_t id_994 { leb128_sz_752[id_993] };
                                                                uint8_t id_995 { uint8_t(id_994) };
                                                                uint8_t id_996 { 128 };
                                                                uint8_t id_997 { uint8_t(id_995 | id_996) };
                                                                choose_res_989 = id_997;
                                                              }
                                                              Pointer id_998 { id_984.writeU8(choose_res_989) };
                                                              Void id_999 { ((void)(leb128_ptr_753[id_982] = id_998), VOID) };
                                                              (void)id_999;
                                                              uint8_t id_1000 { 0 };
                                                              uint8_t id_1001 { 0 };
                                                              uint32_t id_1002 { leb128_sz_752[id_1001] };
                                                              uint8_t id_1003 { 7 };
                                                              uint32_t id_1004 { uint32_t(id_1002 >> id_1003) };
                                                              Void id_1005 { ((void)(leb128_sz_752[id_1000] = id_1004), VOID) };
                                                              (void)id_1005;
                                                              uint8_t id_1006 { 0 };
                                                              uint32_t id_1007 { leb128_sz_752[id_1006] };
                                                              uint32_t id_1008 { 0U };
                                                              bool id_1009 { bool(id_1007 > id_1008) };
                                                              while_flag_981 = id_1009;
                                                              if (while_flag_981) {
                                                                (void)VOID;
                                                              }
                                                            } while (while_flag_981);
                                                            (void)VOID;
                                                            uint8_t id_1010 { 0 };
                                                            Pointer id_1011 { leb128_ptr_753[id_1010] };
                                                            let_res_980 = id_1011;
                                                          }
                                                          let_res_978 = let_res_980;
                                                        }
                                                        ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_1012 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_1013 { std::get<1>(id_1012) };
                                                        ::dessser::gen::sync_key::t51130975cc895752ed58d8b9dd6b2622 id_1014 { std::get<5 /* Dialogs */>(id_1013) };
                                                        std::string id_1015 { std::get<0>(id_1014) };
                                                        Bytes id_1016 { id_1015 };
                                                        Pointer id_1017 { let_res_978.writeBytes(id_1016) };
                                                        Pointer let_res_1018;
                                                        {
                                                          Pointer stup_dst_754 { id_1017 };
                                                          ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_1019 { std::get<15 /* Incidents */>((*p_0)) };
                                                          ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_1020 { std::get<1>(id_1019) };
                                                          ::dessser::gen::sync_key::t51130975cc895752ed58d8b9dd6b2622 id_1021 { std::get<5 /* Dialogs */>(id_1020) };
                                                          ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_1022 { std::get<1>(id_1021) };
                                                          uint16_t id_1023 { uint16_t(id_1022.index()) };
                                                          Pointer let_res_1024;
                                                          {
                                                            uint16_t label1_755 { id_1023 };
                                                            Pointer id_1025 { stup_dst_754.writeU16Le(label1_755) };
                                                            Pointer let_res_1026;
                                                            {
                                                              Pointer ssum_dst_756 { id_1025 };
                                                              uint16_t id_1027 { 0 };
                                                              bool id_1028 { bool(id_1027 == label1_755) };
                                                              Pointer choose_res_1029;
                                                              if (id_1028) {
                                                                choose_res_1029 = ssum_dst_756;
                                                              } else {
                                                                uint16_t id_1030 { 1 };
                                                                bool id_1031 { bool(id_1030 == label1_755) };
                                                                Pointer choose_res_1032;
                                                                if (id_1031) {
                                                                  choose_res_1032 = ssum_dst_756;
                                                                } else {
                                                                  uint16_t id_1033 { 2 };
                                                                  bool id_1034 { bool(id_1033 == label1_755) };
                                                                  Pointer choose_res_1035;
                                                                  if (id_1034) {
                                                                    choose_res_1035 = ssum_dst_756;
                                                                  } else {
                                                                    uint16_t id_1036 { 3 };
                                                                    bool id_1037 { bool(id_1036 == label1_755) };
                                                                    Pointer choose_res_1038;
                                                                    if (id_1037) {
                                                                      choose_res_1038 = ssum_dst_756;
                                                                    } else {
                                                                      uint16_t id_1039 { 4 };
                                                                      bool id_1040 { bool(id_1039 == label1_755) };
                                                                      Pointer choose_res_1041;
                                                                      if (id_1040) {
                                                                        choose_res_1041 = ssum_dst_756;
                                                                      } else {
                                                                        uint16_t id_1042 { 5 };
                                                                        bool id_1043 { bool(id_1042 == label1_755) };
                                                                        Pointer choose_res_1044;
                                                                        if (id_1043) {
                                                                          choose_res_1044 = ssum_dst_756;
                                                                        } else {
                                                                          uint16_t id_1045 { 6 };
                                                                          bool id_1046 { bool(label1_755 == id_1045) };
                                                                          Void id_1047 { ((void)(assert(id_1046)), VOID) };
                                                                          (void)id_1047;
                                                                          choose_res_1044 = ssum_dst_756;
                                                                        }
                                                                        choose_res_1041 = choose_res_1044;
                                                                      }
                                                                      choose_res_1038 = choose_res_1041;
                                                                    }
                                                                    choose_res_1035 = choose_res_1038;
                                                                  }
                                                                  choose_res_1032 = choose_res_1035;
                                                                }
                                                                choose_res_1029 = choose_res_1032;
                                                              }
                                                              let_res_1026 = choose_res_1029;
                                                            }
                                                            let_res_1024 = let_res_1026;
                                                          }
                                                          let_res_1018 = let_res_1024;
                                                        }
                                                        choose_res_971 = let_res_1018;
                                                      } else {
                                                        uint16_t id_1048 { 6 };
                                                        bool id_1049 { bool(label1_749 == id_1048) };
                                                        Void id_1050 { ((void)(assert(id_1049)), VOID) };
                                                        (void)id_1050;
                                                        ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_1051 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_1052 { std::get<1>(id_1051) };
                                                        ::dessser::gen::sync_key::t66e64aa59a640b5ac04dd276fa3e8463 id_1053 { std::get<6 /* Journal */>(id_1052) };
                                                        double id_1054 { std::get<0>(id_1053) };
                                                        uint64_t id_1055 { qword_of_float(id_1054) };
                                                        Pointer id_1056 { ssum_dst_750.writeU64Le(id_1055) };
                                                        Pointer let_res_1057;
                                                        {
                                                          Pointer stup_dst_751 { id_1056 };
                                                          ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_1058 { std::get<15 /* Incidents */>((*p_0)) };
                                                          ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_1059 { std::get<1>(id_1058) };
                                                          ::dessser::gen::sync_key::t66e64aa59a640b5ac04dd276fa3e8463 id_1060 { std::get<6 /* Journal */>(id_1059) };
                                                          uint32_t id_1061 { std::get<1>(id_1060) };
                                                          Pointer id_1062 { stup_dst_751.writeU32Le(id_1061) };
                                                          let_res_1057 = id_1062;
                                                        }
                                                        choose_res_971 = let_res_1057;
                                                      }
                                                      choose_res_968 = choose_res_971;
                                                    }
                                                    choose_res_965 = choose_res_968;
                                                  }
                                                  choose_res_962 = choose_res_965;
                                                }
                                                choose_res_959 = choose_res_962;
                                              }
                                              choose_res_956 = choose_res_959;
                                            }
                                            let_res_953 = choose_res_956;
                                          }
                                          let_res_951 = let_res_953;
                                        }
                                        let_res_947 = let_res_951;
                                      }
                                      choose_res_753 = let_res_947;
                                    }
                                    choose_res_750 = choose_res_753;
                                  }
                                  choose_res_701 = choose_res_750;
                                }
                                choose_res_628 = choose_res_701;
                              }
                              choose_res_625 = choose_res_628;
                            }
                            choose_res_611 = choose_res_625;
                          }
                          choose_res_606 = choose_res_611;
                        }
                        choose_res_485 = choose_res_606;
                      }
                      choose_res_421 = choose_res_485;
                    }
                    choose_res_119 = choose_res_421;
                  }
                  choose_res_116 = choose_res_119;
                }
                choose_res_66 = choose_res_116;
              }
              choose_res_23 = choose_res_66;
            }
            choose_res_20 = choose_res_23;
          }
          choose_res_17 = choose_res_20;
        }
        let_res_14 = choose_res_17;
      }
      let_res_12 = let_res_14;
    }
    return let_res_12;
  }
   };
  return fun10;
}
std::function<Pointer(::dessser::gen::sync_key::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Widgets U32]") (seq (assert (eq (label-of (param 0)) (u16 0))) (size 6)))
 */
static std::function<Size(::dessser::gen::sync_key::per_dash_key*)> per_dash_key_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::per_dash_key*)> fun1063 { [&fun1063](::dessser::gen::sync_key::per_dash_key* p_0) {
    uint16_t id_1064 { uint16_t((*p_0).index()) };
    uint16_t id_1065 { 0 };
    bool id_1066 { bool(id_1064 == id_1065) };
    Void id_1067 { ((void)(assert(id_1066)), VOID) };
    (void)id_1067;
    Size id_1068 { 6UL };
    return id_1068;
  }
   };
  return fun1063;
}
std::function<Size(::dessser::gen::sync_key::per_dash_key*)> per_dash_key_sersize_of_row_binary(per_dash_key_sersize_of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]")
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
static std::function<Size(::dessser::gen::sync_key::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::t*)> fun1069 { [&fun1069](::dessser::gen::sync_key::t* p_0) {
    uint16_t id_1070 { uint16_t((*p_0).index()) };
    Size let_res_1071;
    {
      uint16_t label2_657 { id_1070 };
      uint16_t id_1072 { 0 };
      bool id_1073 { bool(id_1072 == label2_657) };
      Size choose_res_1074;
      if (id_1073) {
        Size id_1075 { 2UL };
        choose_res_1074 = id_1075;
      } else {
        uint16_t id_1076 { 1 };
        bool id_1077 { bool(id_1076 == label2_657) };
        Size choose_res_1078;
        if (id_1077) {
          Size id_1079 { 2UL };
          choose_res_1078 = id_1079;
        } else {
          uint16_t id_1080 { 2 };
          bool id_1081 { bool(id_1080 == label2_657) };
          Size choose_res_1082;
          if (id_1081) {
            Size id_1083 { 2UL };
            std::string id_1084 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1085 { (uint32_t)id_1084.size() };
            Vec<1, uint32_t> id_1086 {  id_1085  };
            Size let_res_1087;
            {
              Vec<1, uint32_t> n_ref_740 { id_1086 };
              uint32_t id_1088 { 1U };
              Vec<1, uint32_t> id_1089 {  id_1088  };
              Size let_res_1090;
              {
                Vec<1, uint32_t> lebsz_ref_741 { id_1089 };
                bool while_flag_1091 { true };
                do {
                  uint8_t id_1092 { 0 };
                  uint32_t id_1093 { n_ref_740[id_1092] };
                  uint8_t id_1094 { 0 };
                  uint32_t id_1095 { lebsz_ref_741[id_1094] };
                  uint8_t id_1096 { 7 };
                  uint32_t id_1097 { uint32_t(id_1095 << id_1096) };
                  bool id_1098 { bool(id_1093 >= id_1097) };
                  while_flag_1091 = id_1098;
                  if (while_flag_1091) {
                    uint8_t id_1099 { 0 };
                    uint8_t id_1100 { 0 };
                    uint32_t id_1101 { lebsz_ref_741[id_1100] };
                    uint32_t id_1102 { 1U };
                    uint32_t id_1103 { uint32_t(id_1101 + id_1102) };
                    Void id_1104 { ((void)(lebsz_ref_741[id_1099] = id_1103), VOID) };
                    (void)id_1104;
                  }
                } while (while_flag_1091);
                (void)VOID;
                uint8_t id_1105 { 0 };
                uint32_t id_1106 { lebsz_ref_741[id_1105] };
                Size id_1107 { Size(id_1106) };
                let_res_1090 = id_1107;
              }
              let_res_1087 = let_res_1090;
            }
            std::string id_1108 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1109 { (uint32_t)id_1108.size() };
            Size id_1110 { Size(id_1109) };
            Size id_1111 { Size(let_res_1087 + id_1110) };
            Size id_1112 { Size(id_1083 + id_1111) };
            choose_res_1082 = id_1112;
          } else {
            uint16_t id_1113 { 3 };
            bool id_1114 { bool(id_1113 == label2_657) };
            Size choose_res_1115;
            if (id_1114) {
              Size id_1116 { 2UL };
              auto fun1117 { dessser::gen::src_path::sersize_of_row_binary };
              ::dessser::gen::sync_key::t274013922fc0b2cd45c289bf2ba4463d id_1118 { std::get<3 /* Sources */>((*p_0)) };
              dessser::gen::src_path::t_ext id_1119 { std::get<0>(id_1118) };
              Size id_1120 { fun1117(id_1119) };
              Size id_1121 { Size(id_1116 + id_1120) };
              Size let_res_1122;
              {
                Size sz_735 { id_1121 };
                ::dessser::gen::sync_key::t274013922fc0b2cd45c289bf2ba4463d id_1123 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1124 { std::get<1>(id_1123) };
                uint32_t id_1125 { (uint32_t)id_1124.size() };
                Vec<1, uint32_t> id_1126 {  id_1125  };
                Size let_res_1127;
                {
                  Vec<1, uint32_t> n_ref_737 { id_1126 };
                  uint32_t id_1128 { 1U };
                  Vec<1, uint32_t> id_1129 {  id_1128  };
                  Size let_res_1130;
                  {
                    Vec<1, uint32_t> lebsz_ref_738 { id_1129 };
                    bool while_flag_1131 { true };
                    do {
                      uint8_t id_1132 { 0 };
                      uint32_t id_1133 { n_ref_737[id_1132] };
                      uint8_t id_1134 { 0 };
                      uint32_t id_1135 { lebsz_ref_738[id_1134] };
                      uint8_t id_1136 { 7 };
                      uint32_t id_1137 { uint32_t(id_1135 << id_1136) };
                      bool id_1138 { bool(id_1133 >= id_1137) };
                      while_flag_1131 = id_1138;
                      if (while_flag_1131) {
                        uint8_t id_1139 { 0 };
                        uint8_t id_1140 { 0 };
                        uint32_t id_1141 { lebsz_ref_738[id_1140] };
                        uint32_t id_1142 { 1U };
                        uint32_t id_1143 { uint32_t(id_1141 + id_1142) };
                        Void id_1144 { ((void)(lebsz_ref_738[id_1139] = id_1143), VOID) };
                        (void)id_1144;
                      }
                    } while (while_flag_1131);
                    (void)VOID;
                    uint8_t id_1145 { 0 };
                    uint32_t id_1146 { lebsz_ref_738[id_1145] };
                    Size id_1147 { Size(id_1146) };
                    let_res_1130 = id_1147;
                  }
                  let_res_1127 = let_res_1130;
                }
                ::dessser::gen::sync_key::t274013922fc0b2cd45c289bf2ba4463d id_1148 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1149 { std::get<1>(id_1148) };
                uint32_t id_1150 { (uint32_t)id_1149.size() };
                Size id_1151 { Size(id_1150) };
                Size id_1152 { Size(let_res_1127 + id_1151) };
                Size id_1153 { Size(sz_735 + id_1152) };
                let_res_1122 = id_1153;
              }
              choose_res_1115 = let_res_1122;
            } else {
              uint16_t id_1154 { 4 };
              bool id_1155 { bool(id_1154 == label2_657) };
              Size choose_res_1156;
              if (id_1155) {
                Size id_1157 { 2UL };
                choose_res_1156 = id_1157;
              } else {
                uint16_t id_1158 { 5 };
                bool id_1159 { bool(id_1158 == label2_657) };
                Size choose_res_1160;
                if (id_1159) {
                  Size id_1161 { 2UL };
                  auto fun1162 { dessser::gen::site_name::sersize_of_row_binary };
                  ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1163 { std::get<5 /* PerSite */>((*p_0)) };
                  dessser::gen::site_name::t_ext id_1164 { std::get<0>(id_1163) };
                  Size id_1165 { fun1162(id_1164) };
                  Size id_1166 { Size(id_1161 + id_1165) };
                  Size let_res_1167;
                  {
                    Size sz_711 { id_1166 };
                    uint16_t id_1168 { 0 };
                    ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1169 { std::get<5 /* PerSite */>((*p_0)) };
                    ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1170 { std::get<1>(id_1169) };
                    uint16_t id_1171 { uint16_t(id_1170.index()) };
                    bool id_1172 { bool(id_1168 == id_1171) };
                    Size choose_res_1173;
                    if (id_1172) {
                      Size id_1174 { 2UL };
                      Size id_1175 { Size(sz_711 + id_1174) };
                      choose_res_1173 = id_1175;
                    } else {
                      uint16_t id_1176 { 1 };
                      ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1177 { std::get<5 /* PerSite */>((*p_0)) };
                      ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1178 { std::get<1>(id_1177) };
                      uint16_t id_1179 { uint16_t(id_1178.index()) };
                      bool id_1180 { bool(id_1176 == id_1179) };
                      Size choose_res_1181;
                      if (id_1180) {
                        Size id_1182 { 2UL };
                        Size id_1183 { Size(sz_711 + id_1182) };
                        ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1184 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1185 { std::get<1>(id_1184) };
                        ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995 id_1186 { std::get<1 /* PerService */>(id_1185) };
                        std::string id_1187 { std::get<0>(id_1186) };
                        uint32_t id_1188 { (uint32_t)id_1187.size() };
                        Vec<1, uint32_t> id_1189 {  id_1188  };
                        Size let_res_1190;
                        {
                          Vec<1, uint32_t> n_ref_730 { id_1189 };
                          uint32_t id_1191 { 1U };
                          Vec<1, uint32_t> id_1192 {  id_1191  };
                          Size let_res_1193;
                          {
                            Vec<1, uint32_t> lebsz_ref_731 { id_1192 };
                            bool while_flag_1194 { true };
                            do {
                              uint8_t id_1195 { 0 };
                              uint32_t id_1196 { n_ref_730[id_1195] };
                              uint8_t id_1197 { 0 };
                              uint32_t id_1198 { lebsz_ref_731[id_1197] };
                              uint8_t id_1199 { 7 };
                              uint32_t id_1200 { uint32_t(id_1198 << id_1199) };
                              bool id_1201 { bool(id_1196 >= id_1200) };
                              while_flag_1194 = id_1201;
                              if (while_flag_1194) {
                                uint8_t id_1202 { 0 };
                                uint8_t id_1203 { 0 };
                                uint32_t id_1204 { lebsz_ref_731[id_1203] };
                                uint32_t id_1205 { 1U };
                                uint32_t id_1206 { uint32_t(id_1204 + id_1205) };
                                Void id_1207 { ((void)(lebsz_ref_731[id_1202] = id_1206), VOID) };
                                (void)id_1207;
                              }
                            } while (while_flag_1194);
                            (void)VOID;
                            uint8_t id_1208 { 0 };
                            uint32_t id_1209 { lebsz_ref_731[id_1208] };
                            Size id_1210 { Size(id_1209) };
                            let_res_1193 = id_1210;
                          }
                          let_res_1190 = let_res_1193;
                        }
                        ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1211 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1212 { std::get<1>(id_1211) };
                        ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995 id_1213 { std::get<1 /* PerService */>(id_1212) };
                        std::string id_1214 { std::get<0>(id_1213) };
                        uint32_t id_1215 { (uint32_t)id_1214.size() };
                        Size id_1216 { Size(id_1215) };
                        Size id_1217 { Size(let_res_1190 + id_1216) };
                        Size id_1218 { Size(id_1183 + id_1217) };
                        Size let_res_1219;
                        {
                          Size sz_732 { id_1218 };
                          uint16_t id_1220 { 0 };
                          ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1221 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1222 { std::get<1>(id_1221) };
                          ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995 id_1223 { std::get<1 /* PerService */>(id_1222) };
                          ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_1224 { std::get<1>(id_1223) };
                          uint16_t id_1225 { uint16_t(id_1224.index()) };
                          bool id_1226 { bool(id_1220 == id_1225) };
                          Size choose_res_1227;
                          if (id_1226) {
                            Size id_1228 { 2UL };
                            Size id_1229 { Size(sz_732 + id_1228) };
                            choose_res_1227 = id_1229;
                          } else {
                            ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1230 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1231 { std::get<1>(id_1230) };
                            ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995 id_1232 { std::get<1 /* PerService */>(id_1231) };
                            ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_1233 { std::get<1>(id_1232) };
                            uint16_t id_1234 { uint16_t(id_1233.index()) };
                            uint16_t id_1235 { 1 };
                            bool id_1236 { bool(id_1234 == id_1235) };
                            Void id_1237 { ((void)(assert(id_1236)), VOID) };
                            (void)id_1237;
                            Size id_1238 { 2UL };
                            Size id_1239 { Size(sz_732 + id_1238) };
                            choose_res_1227 = id_1239;
                          }
                          let_res_1219 = choose_res_1227;
                        }
                        choose_res_1181 = let_res_1219;
                      } else {
                        uint16_t id_1240 { 2 };
                        ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1241 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1242 { std::get<1>(id_1241) };
                        uint16_t id_1243 { uint16_t(id_1242.index()) };
                        bool id_1244 { bool(id_1240 == id_1243) };
                        Size choose_res_1245;
                        if (id_1244) {
                          Size id_1246 { 2UL };
                          Size id_1247 { Size(sz_711 + id_1246) };
                          auto fun1248 { dessser::gen::fq_name::sersize_of_row_binary };
                          ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1249 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1250 { std::get<1>(id_1249) };
                          ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_1251 { std::get<2 /* PerWorker */>(id_1250) };
                          dessser::gen::fq_name::t_ext id_1252 { std::get<0>(id_1251) };
                          Size id_1253 { fun1248(id_1252) };
                          Size id_1254 { Size(id_1247 + id_1253) };
                          Size let_res_1255;
                          {
                            Size sz_720 { id_1254 };
                            ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1256 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1257 { std::get<1>(id_1256) };
                            ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_1258 { std::get<2 /* PerWorker */>(id_1257) };
                            ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_1259 { std::get<1>(id_1258) };
                            uint16_t id_1260 { uint16_t(id_1259.index()) };
                            Size let_res_1261;
                            {
                              uint16_t label2_721 { id_1260 };
                              uint16_t id_1262 { 0 };
                              bool id_1263 { bool(id_1262 == label2_721) };
                              Size choose_res_1264;
                              if (id_1263) {
                                Size id_1265 { 2UL };
                                Size id_1266 { Size(sz_720 + id_1265) };
                                choose_res_1264 = id_1266;
                              } else {
                                uint16_t id_1267 { 1 };
                                bool id_1268 { bool(id_1267 == label2_721) };
                                Size choose_res_1269;
                                if (id_1268) {
                                  Size id_1270 { 2UL };
                                  Size id_1271 { Size(sz_720 + id_1270) };
                                  choose_res_1269 = id_1271;
                                } else {
                                  uint16_t id_1272 { 2 };
                                  bool id_1273 { bool(id_1272 == label2_721) };
                                  Size choose_res_1274;
                                  if (id_1273) {
                                    Size id_1275 { 2UL };
                                    Size id_1276 { Size(sz_720 + id_1275) };
                                    choose_res_1274 = id_1276;
                                  } else {
                                    uint16_t id_1277 { 3 };
                                    bool id_1278 { bool(id_1277 == label2_721) };
                                    Size choose_res_1279;
                                    if (id_1278) {
                                      Size id_1280 { 2UL };
                                      Size id_1281 { Size(sz_720 + id_1280) };
                                      choose_res_1279 = id_1281;
                                    } else {
                                      uint16_t id_1282 { 4 };
                                      bool id_1283 { bool(id_1282 == label2_721) };
                                      Size choose_res_1284;
                                      if (id_1283) {
                                        Size id_1285 { 2UL };
                                        Size id_1286 { Size(sz_720 + id_1285) };
                                        choose_res_1284 = id_1286;
                                      } else {
                                        uint16_t id_1287 { 5 };
                                        bool id_1288 { bool(id_1287 == label2_721) };
                                        Size choose_res_1289;
                                        if (id_1288) {
                                          Size id_1290 { 2UL };
                                          Size id_1291 { Size(sz_720 + id_1290) };
                                          choose_res_1289 = id_1291;
                                        } else {
                                          uint16_t id_1292 { 6 };
                                          bool id_1293 { bool(id_1292 == label2_721) };
                                          Size choose_res_1294;
                                          if (id_1293) {
                                            Size id_1295 { 2UL };
                                            Size id_1296 { Size(sz_720 + id_1295) };
                                            ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1297 { std::get<5 /* PerSite */>((*p_0)) };
                                            ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1298 { std::get<1>(id_1297) };
                                            ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_1299 { std::get<2 /* PerWorker */>(id_1298) };
                                            ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_1300 { std::get<1>(id_1299) };
                                            ::dessser::gen::sync_key::t1ad3e248018f4f9e0c3083920c2150a2 id_1301 { std::get<6 /* PerInstance */>(id_1300) };
                                            std::string id_1302 { std::get<0>(id_1301) };
                                            uint32_t id_1303 { (uint32_t)id_1302.size() };
                                            Vec<1, uint32_t> id_1304 {  id_1303  };
                                            Size let_res_1305;
                                            {
                                              Vec<1, uint32_t> n_ref_724 { id_1304 };
                                              uint32_t id_1306 { 1U };
                                              Vec<1, uint32_t> id_1307 {  id_1306  };
                                              Size let_res_1308;
                                              {
                                                Vec<1, uint32_t> lebsz_ref_725 { id_1307 };
                                                bool while_flag_1309 { true };
                                                do {
                                                  uint8_t id_1310 { 0 };
                                                  uint32_t id_1311 { n_ref_724[id_1310] };
                                                  uint8_t id_1312 { 0 };
                                                  uint32_t id_1313 { lebsz_ref_725[id_1312] };
                                                  uint8_t id_1314 { 7 };
                                                  uint32_t id_1315 { uint32_t(id_1313 << id_1314) };
                                                  bool id_1316 { bool(id_1311 >= id_1315) };
                                                  while_flag_1309 = id_1316;
                                                  if (while_flag_1309) {
                                                    uint8_t id_1317 { 0 };
                                                    uint8_t id_1318 { 0 };
                                                    uint32_t id_1319 { lebsz_ref_725[id_1318] };
                                                    uint32_t id_1320 { 1U };
                                                    uint32_t id_1321 { uint32_t(id_1319 + id_1320) };
                                                    Void id_1322 { ((void)(lebsz_ref_725[id_1317] = id_1321), VOID) };
                                                    (void)id_1322;
                                                  }
                                                } while (while_flag_1309);
                                                (void)VOID;
                                                uint8_t id_1323 { 0 };
                                                uint32_t id_1324 { lebsz_ref_725[id_1323] };
                                                Size id_1325 { Size(id_1324) };
                                                let_res_1308 = id_1325;
                                              }
                                              let_res_1305 = let_res_1308;
                                            }
                                            ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1326 { std::get<5 /* PerSite */>((*p_0)) };
                                            ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1327 { std::get<1>(id_1326) };
                                            ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_1328 { std::get<2 /* PerWorker */>(id_1327) };
                                            ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_1329 { std::get<1>(id_1328) };
                                            ::dessser::gen::sync_key::t1ad3e248018f4f9e0c3083920c2150a2 id_1330 { std::get<6 /* PerInstance */>(id_1329) };
                                            std::string id_1331 { std::get<0>(id_1330) };
                                            uint32_t id_1332 { (uint32_t)id_1331.size() };
                                            Size id_1333 { Size(id_1332) };
                                            Size id_1334 { Size(let_res_1305 + id_1333) };
                                            Size id_1335 { Size(id_1296 + id_1334) };
                                            Size let_res_1336;
                                            {
                                              Size sz_726 { id_1335 };
                                              ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1337 { std::get<5 /* PerSite */>((*p_0)) };
                                              ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1338 { std::get<1>(id_1337) };
                                              ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_1339 { std::get<2 /* PerWorker */>(id_1338) };
                                              ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_1340 { std::get<1>(id_1339) };
                                              ::dessser::gen::sync_key::t1ad3e248018f4f9e0c3083920c2150a2 id_1341 { std::get<6 /* PerInstance */>(id_1340) };
                                              ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_1342 { std::get<1>(id_1341) };
                                              uint16_t id_1343 { uint16_t(id_1342.index()) };
                                              Size let_res_1344;
                                              {
                                                uint16_t label2_727 { id_1343 };
                                                uint16_t id_1345 { 0 };
                                                bool id_1346 { bool(id_1345 == label2_727) };
                                                Size choose_res_1347;
                                                if (id_1346) {
                                                  Size id_1348 { 2UL };
                                                  Size id_1349 { Size(sz_726 + id_1348) };
                                                  choose_res_1347 = id_1349;
                                                } else {
                                                  uint16_t id_1350 { 1 };
                                                  bool id_1351 { bool(id_1350 == label2_727) };
                                                  Size choose_res_1352;
                                                  if (id_1351) {
                                                    Size id_1353 { 2UL };
                                                    Size id_1354 { Size(sz_726 + id_1353) };
                                                    choose_res_1352 = id_1354;
                                                  } else {
                                                    uint16_t id_1355 { 2 };
                                                    bool id_1356 { bool(id_1355 == label2_727) };
                                                    Size choose_res_1357;
                                                    if (id_1356) {
                                                      Size id_1358 { 2UL };
                                                      Size id_1359 { Size(sz_726 + id_1358) };
                                                      choose_res_1357 = id_1359;
                                                    } else {
                                                      uint16_t id_1360 { 3 };
                                                      bool id_1361 { bool(id_1360 == label2_727) };
                                                      Size choose_res_1362;
                                                      if (id_1361) {
                                                        Size id_1363 { 2UL };
                                                        Size id_1364 { Size(sz_726 + id_1363) };
                                                        choose_res_1362 = id_1364;
                                                      } else {
                                                        uint16_t id_1365 { 4 };
                                                        bool id_1366 { bool(id_1365 == label2_727) };
                                                        Size choose_res_1367;
                                                        if (id_1366) {
                                                          Size id_1368 { 2UL };
                                                          Size id_1369 { Size(sz_726 + id_1368) };
                                                          choose_res_1367 = id_1369;
                                                        } else {
                                                          uint16_t id_1370 { 5 };
                                                          bool id_1371 { bool(id_1370 == label2_727) };
                                                          Size choose_res_1372;
                                                          if (id_1371) {
                                                            Size id_1373 { 2UL };
                                                            Size id_1374 { Size(sz_726 + id_1373) };
                                                            choose_res_1372 = id_1374;
                                                          } else {
                                                            uint16_t id_1375 { 6 };
                                                            bool id_1376 { bool(id_1375 == label2_727) };
                                                            Size choose_res_1377;
                                                            if (id_1376) {
                                                              Size id_1378 { 2UL };
                                                              Size id_1379 { Size(sz_726 + id_1378) };
                                                              choose_res_1377 = id_1379;
                                                            } else {
                                                              uint16_t id_1380 { 7 };
                                                              bool id_1381 { bool(label2_727 == id_1380) };
                                                              Void id_1382 { ((void)(assert(id_1381)), VOID) };
                                                              (void)id_1382;
                                                              Size id_1383 { 2UL };
                                                              Size id_1384 { Size(sz_726 + id_1383) };
                                                              choose_res_1377 = id_1384;
                                                            }
                                                            choose_res_1372 = choose_res_1377;
                                                          }
                                                          choose_res_1367 = choose_res_1372;
                                                        }
                                                        choose_res_1362 = choose_res_1367;
                                                      }
                                                      choose_res_1357 = choose_res_1362;
                                                    }
                                                    choose_res_1352 = choose_res_1357;
                                                  }
                                                  choose_res_1347 = choose_res_1352;
                                                }
                                                let_res_1344 = choose_res_1347;
                                              }
                                              let_res_1336 = let_res_1344;
                                            }
                                            choose_res_1294 = let_res_1336;
                                          } else {
                                            uint16_t id_1385 { 7 };
                                            bool id_1386 { bool(id_1385 == label2_721) };
                                            Size choose_res_1387;
                                            if (id_1386) {
                                              Size id_1388 { 2UL };
                                              Size id_1389 { Size(sz_720 + id_1388) };
                                              Size id_1390 { 4UL };
                                              Size id_1391 { Size(id_1389 + id_1390) };
                                              choose_res_1387 = id_1391;
                                            } else {
                                              uint16_t id_1392 { 8 };
                                              bool id_1393 { bool(label2_721 == id_1392) };
                                              Void id_1394 { ((void)(assert(id_1393)), VOID) };
                                              (void)id_1394;
                                              Size id_1395 { 2UL };
                                              Size id_1396 { Size(sz_720 + id_1395) };
                                              choose_res_1387 = id_1396;
                                            }
                                            choose_res_1294 = choose_res_1387;
                                          }
                                          choose_res_1289 = choose_res_1294;
                                        }
                                        choose_res_1284 = choose_res_1289;
                                      }
                                      choose_res_1279 = choose_res_1284;
                                    }
                                    choose_res_1274 = choose_res_1279;
                                  }
                                  choose_res_1269 = choose_res_1274;
                                }
                                choose_res_1264 = choose_res_1269;
                              }
                              let_res_1261 = choose_res_1264;
                            }
                            let_res_1255 = let_res_1261;
                          }
                          choose_res_1245 = let_res_1255;
                        } else {
                          ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1397 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1398 { std::get<1>(id_1397) };
                          uint16_t id_1399 { uint16_t(id_1398.index()) };
                          uint16_t id_1400 { 3 };
                          bool id_1401 { bool(id_1399 == id_1400) };
                          Void id_1402 { ((void)(assert(id_1401)), VOID) };
                          (void)id_1402;
                          Size id_1403 { 2UL };
                          Size id_1404 { Size(sz_711 + id_1403) };
                          ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1405 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1406 { std::get<1>(id_1405) };
                          ::dessser::gen::sync_key::tb761ebb9c7c72cccd366042890abdac8 id_1407 { std::get<3 /* PerProgram */>(id_1406) };
                          std::string id_1408 { std::get<0>(id_1407) };
                          uint32_t id_1409 { (uint32_t)id_1408.size() };
                          Vec<1, uint32_t> id_1410 {  id_1409  };
                          Size let_res_1411;
                          {
                            Vec<1, uint32_t> n_ref_715 { id_1410 };
                            uint32_t id_1412 { 1U };
                            Vec<1, uint32_t> id_1413 {  id_1412  };
                            Size let_res_1414;
                            {
                              Vec<1, uint32_t> lebsz_ref_716 { id_1413 };
                              bool while_flag_1415 { true };
                              do {
                                uint8_t id_1416 { 0 };
                                uint32_t id_1417 { n_ref_715[id_1416] };
                                uint8_t id_1418 { 0 };
                                uint32_t id_1419 { lebsz_ref_716[id_1418] };
                                uint8_t id_1420 { 7 };
                                uint32_t id_1421 { uint32_t(id_1419 << id_1420) };
                                bool id_1422 { bool(id_1417 >= id_1421) };
                                while_flag_1415 = id_1422;
                                if (while_flag_1415) {
                                  uint8_t id_1423 { 0 };
                                  uint8_t id_1424 { 0 };
                                  uint32_t id_1425 { lebsz_ref_716[id_1424] };
                                  uint32_t id_1426 { 1U };
                                  uint32_t id_1427 { uint32_t(id_1425 + id_1426) };
                                  Void id_1428 { ((void)(lebsz_ref_716[id_1423] = id_1427), VOID) };
                                  (void)id_1428;
                                }
                              } while (while_flag_1415);
                              (void)VOID;
                              uint8_t id_1429 { 0 };
                              uint32_t id_1430 { lebsz_ref_716[id_1429] };
                              Size id_1431 { Size(id_1430) };
                              let_res_1414 = id_1431;
                            }
                            let_res_1411 = let_res_1414;
                          }
                          ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1432 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1433 { std::get<1>(id_1432) };
                          ::dessser::gen::sync_key::tb761ebb9c7c72cccd366042890abdac8 id_1434 { std::get<3 /* PerProgram */>(id_1433) };
                          std::string id_1435 { std::get<0>(id_1434) };
                          uint32_t id_1436 { (uint32_t)id_1435.size() };
                          Size id_1437 { Size(id_1436) };
                          Size id_1438 { Size(let_res_1411 + id_1437) };
                          Size id_1439 { Size(id_1404 + id_1438) };
                          Size let_res_1440;
                          {
                            Size sz_717 { id_1439 };
                            ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_1441 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_1442 { std::get<1>(id_1441) };
                            ::dessser::gen::sync_key::tb761ebb9c7c72cccd366042890abdac8 id_1443 { std::get<3 /* PerProgram */>(id_1442) };
                            ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_1444 { std::get<1>(id_1443) };
                            uint16_t id_1445 { uint16_t(id_1444.index()) };
                            uint16_t id_1446 { 0 };
                            bool id_1447 { bool(id_1445 == id_1446) };
                            Void id_1448 { ((void)(assert(id_1447)), VOID) };
                            (void)id_1448;
                            Size id_1449 { 2UL };
                            Size id_1450 { Size(sz_717 + id_1449) };
                            let_res_1440 = id_1450;
                          }
                          choose_res_1245 = let_res_1440;
                        }
                        choose_res_1181 = choose_res_1245;
                      }
                      choose_res_1173 = choose_res_1181;
                    }
                    let_res_1167 = choose_res_1173;
                  }
                  choose_res_1160 = let_res_1167;
                } else {
                  uint16_t id_1451 { 6 };
                  bool id_1452 { bool(id_1451 == label2_657) };
                  Size choose_res_1453;
                  if (id_1452) {
                    uint16_t id_1454 { 0 };
                    ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1455 { std::get<6 /* Storage */>((*p_0)) };
                    uint16_t id_1456 { uint16_t(id_1455.index()) };
                    bool id_1457 { bool(id_1454 == id_1456) };
                    Size choose_res_1458;
                    if (id_1457) {
                      Size id_1459 { 4UL };
                      choose_res_1458 = id_1459;
                    } else {
                      uint16_t id_1460 { 1 };
                      ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1461 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_1462 { uint16_t(id_1461.index()) };
                      bool id_1463 { bool(id_1460 == id_1462) };
                      Size choose_res_1464;
                      if (id_1463) {
                        Size id_1465 { 4UL };
                        choose_res_1464 = id_1465;
                      } else {
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1466 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_1467 { uint16_t(id_1466.index()) };
                        uint16_t id_1468 { 2 };
                        bool id_1469 { bool(id_1467 == id_1468) };
                        Void id_1470 { ((void)(assert(id_1469)), VOID) };
                        (void)id_1470;
                        Size id_1471 { 4UL };
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1472 { std::get<6 /* Storage */>((*p_0)) };
                        std::string id_1473 { std::get<2 /* RetentionsOverride */>(id_1472) };
                        uint32_t id_1474 { (uint32_t)id_1473.size() };
                        Vec<1, uint32_t> id_1475 {  id_1474  };
                        Size let_res_1476;
                        {
                          Vec<1, uint32_t> n_ref_708 { id_1475 };
                          uint32_t id_1477 { 1U };
                          Vec<1, uint32_t> id_1478 {  id_1477  };
                          Size let_res_1479;
                          {
                            Vec<1, uint32_t> lebsz_ref_709 { id_1478 };
                            bool while_flag_1480 { true };
                            do {
                              uint8_t id_1481 { 0 };
                              uint32_t id_1482 { n_ref_708[id_1481] };
                              uint8_t id_1483 { 0 };
                              uint32_t id_1484 { lebsz_ref_709[id_1483] };
                              uint8_t id_1485 { 7 };
                              uint32_t id_1486 { uint32_t(id_1484 << id_1485) };
                              bool id_1487 { bool(id_1482 >= id_1486) };
                              while_flag_1480 = id_1487;
                              if (while_flag_1480) {
                                uint8_t id_1488 { 0 };
                                uint8_t id_1489 { 0 };
                                uint32_t id_1490 { lebsz_ref_709[id_1489] };
                                uint32_t id_1491 { 1U };
                                uint32_t id_1492 { uint32_t(id_1490 + id_1491) };
                                Void id_1493 { ((void)(lebsz_ref_709[id_1488] = id_1492), VOID) };
                                (void)id_1493;
                              }
                            } while (while_flag_1480);
                            (void)VOID;
                            uint8_t id_1494 { 0 };
                            uint32_t id_1495 { lebsz_ref_709[id_1494] };
                            Size id_1496 { Size(id_1495) };
                            let_res_1479 = id_1496;
                          }
                          let_res_1476 = let_res_1479;
                        }
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1497 { std::get<6 /* Storage */>((*p_0)) };
                        std::string id_1498 { std::get<2 /* RetentionsOverride */>(id_1497) };
                        uint32_t id_1499 { (uint32_t)id_1498.size() };
                        Size id_1500 { Size(id_1499) };
                        Size id_1501 { Size(let_res_1476 + id_1500) };
                        Size id_1502 { Size(id_1471 + id_1501) };
                        choose_res_1464 = id_1502;
                      }
                      choose_res_1458 = choose_res_1464;
                    }
                    choose_res_1453 = choose_res_1458;
                  } else {
                    uint16_t id_1503 { 7 };
                    bool id_1504 { bool(id_1503 == label2_657) };
                    Size choose_res_1505;
                    if (id_1504) {
                      Size id_1506 { 2UL };
                      auto fun1507 { dessser::gen::site_name::sersize_of_row_binary };
                      ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_1508 { std::get<7 /* Tails */>((*p_0)) };
                      dessser::gen::site_name::t_ext id_1509 { std::get<0>(id_1508) };
                      Size id_1510 { fun1507(id_1509) };
                      Size id_1511 { Size(id_1506 + id_1510) };
                      Size let_res_1512;
                      {
                        Size sz_696 { id_1511 };
                        auto fun1513 { dessser::gen::fq_name::sersize_of_row_binary };
                        ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_1514 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::fq_name::t_ext id_1515 { std::get<1>(id_1514) };
                        Size id_1516 { fun1513(id_1515) };
                        Size id_1517 { Size(sz_696 + id_1516) };
                        let_res_1512 = id_1517;
                      }
                      Size let_res_1518;
                      {
                        Size sz_697 { let_res_1512 };
                        ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_1519 { std::get<7 /* Tails */>((*p_0)) };
                        std::string id_1520 { std::get<2>(id_1519) };
                        uint32_t id_1521 { (uint32_t)id_1520.size() };
                        Vec<1, uint32_t> id_1522 {  id_1521  };
                        Size let_res_1523;
                        {
                          Vec<1, uint32_t> n_ref_699 { id_1522 };
                          uint32_t id_1524 { 1U };
                          Vec<1, uint32_t> id_1525 {  id_1524  };
                          Size let_res_1526;
                          {
                            Vec<1, uint32_t> lebsz_ref_700 { id_1525 };
                            bool while_flag_1527 { true };
                            do {
                              uint8_t id_1528 { 0 };
                              uint32_t id_1529 { n_ref_699[id_1528] };
                              uint8_t id_1530 { 0 };
                              uint32_t id_1531 { lebsz_ref_700[id_1530] };
                              uint8_t id_1532 { 7 };
                              uint32_t id_1533 { uint32_t(id_1531 << id_1532) };
                              bool id_1534 { bool(id_1529 >= id_1533) };
                              while_flag_1527 = id_1534;
                              if (while_flag_1527) {
                                uint8_t id_1535 { 0 };
                                uint8_t id_1536 { 0 };
                                uint32_t id_1537 { lebsz_ref_700[id_1536] };
                                uint32_t id_1538 { 1U };
                                uint32_t id_1539 { uint32_t(id_1537 + id_1538) };
                                Void id_1540 { ((void)(lebsz_ref_700[id_1535] = id_1539), VOID) };
                                (void)id_1540;
                              }
                            } while (while_flag_1527);
                            (void)VOID;
                            uint8_t id_1541 { 0 };
                            uint32_t id_1542 { lebsz_ref_700[id_1541] };
                            Size id_1543 { Size(id_1542) };
                            let_res_1526 = id_1543;
                          }
                          let_res_1523 = let_res_1526;
                        }
                        ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_1544 { std::get<7 /* Tails */>((*p_0)) };
                        std::string id_1545 { std::get<2>(id_1544) };
                        uint32_t id_1546 { (uint32_t)id_1545.size() };
                        Size id_1547 { Size(id_1546) };
                        Size id_1548 { Size(let_res_1523 + id_1547) };
                        Size id_1549 { Size(sz_697 + id_1548) };
                        let_res_1518 = id_1549;
                      }
                      Size let_res_1550;
                      {
                        Size sz_701 { let_res_1518 };
                        uint16_t id_1551 { 0 };
                        ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_1552 { std::get<7 /* Tails */>((*p_0)) };
                        ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_1553 { std::get<3>(id_1552) };
                        uint16_t id_1554 { uint16_t(id_1553.index()) };
                        bool id_1555 { bool(id_1551 == id_1554) };
                        Size choose_res_1556;
                        if (id_1555) {
                          Size id_1557 { 2UL };
                          Size id_1558 { Size(sz_701 + id_1557) };
                          ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_1559 { std::get<7 /* Tails */>((*p_0)) };
                          ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_1560 { std::get<3>(id_1559) };
                          std::string id_1561 { std::get<0 /* Subscriber */>(id_1560) };
                          uint32_t id_1562 { (uint32_t)id_1561.size() };
                          Vec<1, uint32_t> id_1563 {  id_1562  };
                          Size let_res_1564;
                          {
                            Vec<1, uint32_t> n_ref_704 { id_1563 };
                            uint32_t id_1565 { 1U };
                            Vec<1, uint32_t> id_1566 {  id_1565  };
                            Size let_res_1567;
                            {
                              Vec<1, uint32_t> lebsz_ref_705 { id_1566 };
                              bool while_flag_1568 { true };
                              do {
                                uint8_t id_1569 { 0 };
                                uint32_t id_1570 { n_ref_704[id_1569] };
                                uint8_t id_1571 { 0 };
                                uint32_t id_1572 { lebsz_ref_705[id_1571] };
                                uint8_t id_1573 { 7 };
                                uint32_t id_1574 { uint32_t(id_1572 << id_1573) };
                                bool id_1575 { bool(id_1570 >= id_1574) };
                                while_flag_1568 = id_1575;
                                if (while_flag_1568) {
                                  uint8_t id_1576 { 0 };
                                  uint8_t id_1577 { 0 };
                                  uint32_t id_1578 { lebsz_ref_705[id_1577] };
                                  uint32_t id_1579 { 1U };
                                  uint32_t id_1580 { uint32_t(id_1578 + id_1579) };
                                  Void id_1581 { ((void)(lebsz_ref_705[id_1576] = id_1580), VOID) };
                                  (void)id_1581;
                                }
                              } while (while_flag_1568);
                              (void)VOID;
                              uint8_t id_1582 { 0 };
                              uint32_t id_1583 { lebsz_ref_705[id_1582] };
                              Size id_1584 { Size(id_1583) };
                              let_res_1567 = id_1584;
                            }
                            let_res_1564 = let_res_1567;
                          }
                          ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_1585 { std::get<7 /* Tails */>((*p_0)) };
                          ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_1586 { std::get<3>(id_1585) };
                          std::string id_1587 { std::get<0 /* Subscriber */>(id_1586) };
                          uint32_t id_1588 { (uint32_t)id_1587.size() };
                          Size id_1589 { Size(id_1588) };
                          Size id_1590 { Size(let_res_1564 + id_1589) };
                          Size id_1591 { Size(id_1558 + id_1590) };
                          choose_res_1556 = id_1591;
                        } else {
                          ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_1592 { std::get<7 /* Tails */>((*p_0)) };
                          ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_1593 { std::get<3>(id_1592) };
                          uint16_t id_1594 { uint16_t(id_1593.index()) };
                          uint16_t id_1595 { 1 };
                          bool id_1596 { bool(id_1594 == id_1595) };
                          Void id_1597 { ((void)(assert(id_1596)), VOID) };
                          (void)id_1597;
                          Size id_1598 { 2UL };
                          Size id_1599 { Size(sz_701 + id_1598) };
                          Size id_1600 { 4UL };
                          Size id_1601 { Size(id_1599 + id_1600) };
                          choose_res_1556 = id_1601;
                        }
                        let_res_1550 = choose_res_1556;
                      }
                      choose_res_1505 = let_res_1550;
                    } else {
                      uint16_t id_1602 { 8 };
                      bool id_1603 { bool(id_1602 == label2_657) };
                      Size choose_res_1604;
                      if (id_1603) {
                        Size id_1605 { 4UL };
                        choose_res_1604 = id_1605;
                      } else {
                        uint16_t id_1606 { 9 };
                        bool id_1607 { bool(id_1606 == label2_657) };
                        Size choose_res_1608;
                        if (id_1607) {
                          std::optional<dessser::gen::sync_socket::t_ext> id_1609 { std::get<9 /* Error */>((*p_0)) };
                          bool id_1610 { !(id_1609.has_value ()) };
                          Size choose_res_1611;
                          if (id_1610) {
                            Size id_1612 { 3UL };
                            choose_res_1611 = id_1612;
                          } else {
                            Size id_1613 { 2UL };
                            auto fun1614 { dessser::gen::sync_socket::sersize_of_row_binary };
                            std::optional<dessser::gen::sync_socket::t_ext> id_1615 { std::get<9 /* Error */>((*p_0)) };
                            dessser::gen::sync_socket::t_ext id_1616 { id_1615.value() };
                            Size id_1617 { fun1614(id_1616) };
                            Size id_1618 { Size(id_1613 + id_1617) };
                            Size id_1619 { 1UL };
                            Size id_1620 { Size(id_1618 + id_1619) };
                            choose_res_1611 = id_1620;
                          }
                          choose_res_1608 = choose_res_1611;
                        } else {
                          uint16_t id_1621 { 10 };
                          bool id_1622 { bool(id_1621 == label2_657) };
                          Size choose_res_1623;
                          if (id_1622) {
                            Size id_1624 { 2UL };
                            choose_res_1623 = id_1624;
                          } else {
                            uint16_t id_1625 { 11 };
                            bool id_1626 { bool(id_1625 == label2_657) };
                            Size choose_res_1627;
                            if (id_1626) {
                              Size id_1628 { 2UL };
                              auto fun1629 { dessser::gen::sync_socket::sersize_of_row_binary };
                              ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_1630 { std::get<11 /* PerClient */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_1631 { std::get<0>(id_1630) };
                              Size id_1632 { fun1629(id_1631) };
                              Size id_1633 { Size(id_1628 + id_1632) };
                              Size let_res_1634;
                              {
                                Size sz_690 { id_1633 };
                                uint16_t id_1635 { 0 };
                                ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_1636 { std::get<11 /* PerClient */>((*p_0)) };
                                ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_1637 { std::get<1>(id_1636) };
                                uint16_t id_1638 { uint16_t(id_1637.index()) };
                                bool id_1639 { bool(id_1635 == id_1638) };
                                Size choose_res_1640;
                                if (id_1639) {
                                  Size id_1641 { 2UL };
                                  Size id_1642 { Size(sz_690 + id_1641) };
                                  ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_1643 { std::get<11 /* PerClient */>((*p_0)) };
                                  ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_1644 { std::get<1>(id_1643) };
                                  std::string id_1645 { std::get<0 /* Response */>(id_1644) };
                                  uint32_t id_1646 { (uint32_t)id_1645.size() };
                                  Vec<1, uint32_t> id_1647 {  id_1646  };
                                  Size let_res_1648;
                                  {
                                    Vec<1, uint32_t> n_ref_693 { id_1647 };
                                    uint32_t id_1649 { 1U };
                                    Vec<1, uint32_t> id_1650 {  id_1649  };
                                    Size let_res_1651;
                                    {
                                      Vec<1, uint32_t> lebsz_ref_694 { id_1650 };
                                      bool while_flag_1652 { true };
                                      do {
                                        uint8_t id_1653 { 0 };
                                        uint32_t id_1654 { n_ref_693[id_1653] };
                                        uint8_t id_1655 { 0 };
                                        uint32_t id_1656 { lebsz_ref_694[id_1655] };
                                        uint8_t id_1657 { 7 };
                                        uint32_t id_1658 { uint32_t(id_1656 << id_1657) };
                                        bool id_1659 { bool(id_1654 >= id_1658) };
                                        while_flag_1652 = id_1659;
                                        if (while_flag_1652) {
                                          uint8_t id_1660 { 0 };
                                          uint8_t id_1661 { 0 };
                                          uint32_t id_1662 { lebsz_ref_694[id_1661] };
                                          uint32_t id_1663 { 1U };
                                          uint32_t id_1664 { uint32_t(id_1662 + id_1663) };
                                          Void id_1665 { ((void)(lebsz_ref_694[id_1660] = id_1664), VOID) };
                                          (void)id_1665;
                                        }
                                      } while (while_flag_1652);
                                      (void)VOID;
                                      uint8_t id_1666 { 0 };
                                      uint32_t id_1667 { lebsz_ref_694[id_1666] };
                                      Size id_1668 { Size(id_1667) };
                                      let_res_1651 = id_1668;
                                    }
                                    let_res_1648 = let_res_1651;
                                  }
                                  ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_1669 { std::get<11 /* PerClient */>((*p_0)) };
                                  ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_1670 { std::get<1>(id_1669) };
                                  std::string id_1671 { std::get<0 /* Response */>(id_1670) };
                                  uint32_t id_1672 { (uint32_t)id_1671.size() };
                                  Size id_1673 { Size(id_1672) };
                                  Size id_1674 { Size(let_res_1648 + id_1673) };
                                  Size id_1675 { Size(id_1642 + id_1674) };
                                  choose_res_1640 = id_1675;
                                } else {
                                  ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_1676 { std::get<11 /* PerClient */>((*p_0)) };
                                  ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_1677 { std::get<1>(id_1676) };
                                  uint16_t id_1678 { uint16_t(id_1677.index()) };
                                  uint16_t id_1679 { 1 };
                                  bool id_1680 { bool(id_1678 == id_1679) };
                                  Void id_1681 { ((void)(assert(id_1680)), VOID) };
                                  (void)id_1681;
                                  Size id_1682 { 2UL };
                                  Size id_1683 { Size(sz_690 + id_1682) };
                                  ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_1684 { std::get<11 /* PerClient */>((*p_0)) };
                                  ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_1685 { std::get<1>(id_1684) };
                                  ::dessser::gen::sync_key::per_dash_key* id_1686 { std::get<1 /* Scratchpad */>(id_1685) };
                                  Size id_1687 { per_dash_key_sersize_of_row_binary(id_1686) };
                                  Size id_1688 { Size(id_1683 + id_1687) };
                                  choose_res_1640 = id_1688;
                                }
                                let_res_1634 = choose_res_1640;
                              }
                              choose_res_1627 = let_res_1634;
                            } else {
                              uint16_t id_1689 { 12 };
                              bool id_1690 { bool(id_1689 == label2_657) };
                              Size choose_res_1691;
                              if (id_1690) {
                                Size id_1692 { 2UL };
                                ::dessser::gen::sync_key::tdf6d0a87bf373d7d4ea33113dc8a8b30 id_1693 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1694 { std::get<0>(id_1693) };
                                uint32_t id_1695 { (uint32_t)id_1694.size() };
                                Vec<1, uint32_t> id_1696 {  id_1695  };
                                Size let_res_1697;
                                {
                                  Vec<1, uint32_t> n_ref_686 { id_1696 };
                                  uint32_t id_1698 { 1U };
                                  Vec<1, uint32_t> id_1699 {  id_1698  };
                                  Size let_res_1700;
                                  {
                                    Vec<1, uint32_t> lebsz_ref_687 { id_1699 };
                                    bool while_flag_1701 { true };
                                    do {
                                      uint8_t id_1702 { 0 };
                                      uint32_t id_1703 { n_ref_686[id_1702] };
                                      uint8_t id_1704 { 0 };
                                      uint32_t id_1705 { lebsz_ref_687[id_1704] };
                                      uint8_t id_1706 { 7 };
                                      uint32_t id_1707 { uint32_t(id_1705 << id_1706) };
                                      bool id_1708 { bool(id_1703 >= id_1707) };
                                      while_flag_1701 = id_1708;
                                      if (while_flag_1701) {
                                        uint8_t id_1709 { 0 };
                                        uint8_t id_1710 { 0 };
                                        uint32_t id_1711 { lebsz_ref_687[id_1710] };
                                        uint32_t id_1712 { 1U };
                                        uint32_t id_1713 { uint32_t(id_1711 + id_1712) };
                                        Void id_1714 { ((void)(lebsz_ref_687[id_1709] = id_1713), VOID) };
                                        (void)id_1714;
                                      }
                                    } while (while_flag_1701);
                                    (void)VOID;
                                    uint8_t id_1715 { 0 };
                                    uint32_t id_1716 { lebsz_ref_687[id_1715] };
                                    Size id_1717 { Size(id_1716) };
                                    let_res_1700 = id_1717;
                                  }
                                  let_res_1697 = let_res_1700;
                                }
                                ::dessser::gen::sync_key::tdf6d0a87bf373d7d4ea33113dc8a8b30 id_1718 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1719 { std::get<0>(id_1718) };
                                uint32_t id_1720 { (uint32_t)id_1719.size() };
                                Size id_1721 { Size(id_1720) };
                                Size id_1722 { Size(let_res_1697 + id_1721) };
                                Size id_1723 { Size(id_1692 + id_1722) };
                                Size let_res_1724;
                                {
                                  Size sz_688 { id_1723 };
                                  ::dessser::gen::sync_key::tdf6d0a87bf373d7d4ea33113dc8a8b30 id_1725 { std::get<12 /* Dashboards */>((*p_0)) };
                                  per_dash_key* id_1726 { std::get<1>(id_1725) };
                                  Size id_1727 { per_dash_key_sersize_of_row_binary(id_1726) };
                                  Size id_1728 { Size(sz_688 + id_1727) };
                                  let_res_1724 = id_1728;
                                }
                                choose_res_1691 = let_res_1724;
                              } else {
                                uint16_t id_1729 { 13 };
                                bool id_1730 { bool(id_1729 == label2_657) };
                                Size choose_res_1731;
                                if (id_1730) {
                                  Size id_1732 { 2UL };
                                  choose_res_1731 = id_1732;
                                } else {
                                  uint16_t id_1733 { 14 };
                                  bool id_1734 { bool(id_1733 == label2_657) };
                                  Size choose_res_1735;
                                  if (id_1734) {
                                    Size id_1736 { 2UL };
                                    ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_1737 { std::get<14 /* Teams */>((*p_0)) };
                                    std::string id_1738 { std::get<0>(id_1737) };
                                    uint32_t id_1739 { (uint32_t)id_1738.size() };
                                    Vec<1, uint32_t> id_1740 {  id_1739  };
                                    Size let_res_1741;
                                    {
                                      Vec<1, uint32_t> n_ref_674 { id_1740 };
                                      uint32_t id_1742 { 1U };
                                      Vec<1, uint32_t> id_1743 {  id_1742  };
                                      Size let_res_1744;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_675 { id_1743 };
                                        bool while_flag_1745 { true };
                                        do {
                                          uint8_t id_1746 { 0 };
                                          uint32_t id_1747 { n_ref_674[id_1746] };
                                          uint8_t id_1748 { 0 };
                                          uint32_t id_1749 { lebsz_ref_675[id_1748] };
                                          uint8_t id_1750 { 7 };
                                          uint32_t id_1751 { uint32_t(id_1749 << id_1750) };
                                          bool id_1752 { bool(id_1747 >= id_1751) };
                                          while_flag_1745 = id_1752;
                                          if (while_flag_1745) {
                                            uint8_t id_1753 { 0 };
                                            uint8_t id_1754 { 0 };
                                            uint32_t id_1755 { lebsz_ref_675[id_1754] };
                                            uint32_t id_1756 { 1U };
                                            uint32_t id_1757 { uint32_t(id_1755 + id_1756) };
                                            Void id_1758 { ((void)(lebsz_ref_675[id_1753] = id_1757), VOID) };
                                            (void)id_1758;
                                          }
                                        } while (while_flag_1745);
                                        (void)VOID;
                                        uint8_t id_1759 { 0 };
                                        uint32_t id_1760 { lebsz_ref_675[id_1759] };
                                        Size id_1761 { Size(id_1760) };
                                        let_res_1744 = id_1761;
                                      }
                                      let_res_1741 = let_res_1744;
                                    }
                                    ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_1762 { std::get<14 /* Teams */>((*p_0)) };
                                    std::string id_1763 { std::get<0>(id_1762) };
                                    uint32_t id_1764 { (uint32_t)id_1763.size() };
                                    Size id_1765 { Size(id_1764) };
                                    Size id_1766 { Size(let_res_1741 + id_1765) };
                                    Size id_1767 { Size(id_1736 + id_1766) };
                                    Size let_res_1768;
                                    {
                                      Size sz_676 { id_1767 };
                                      uint16_t id_1769 { 0 };
                                      ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_1770 { std::get<14 /* Teams */>((*p_0)) };
                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1771 { std::get<1>(id_1770) };
                                      uint16_t id_1772 { uint16_t(id_1771.index()) };
                                      bool id_1773 { bool(id_1769 == id_1772) };
                                      Size choose_res_1774;
                                      if (id_1773) {
                                        Size id_1775 { 2UL };
                                        Size id_1776 { Size(sz_676 + id_1775) };
                                        ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_1777 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1778 { std::get<1>(id_1777) };
                                        std::string id_1779 { std::get<0 /* Contacts */>(id_1778) };
                                        uint32_t id_1780 { (uint32_t)id_1779.size() };
                                        Vec<1, uint32_t> id_1781 {  id_1780  };
                                        Size let_res_1782;
                                        {
                                          Vec<1, uint32_t> n_ref_682 { id_1781 };
                                          uint32_t id_1783 { 1U };
                                          Vec<1, uint32_t> id_1784 {  id_1783  };
                                          Size let_res_1785;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_683 { id_1784 };
                                            bool while_flag_1786 { true };
                                            do {
                                              uint8_t id_1787 { 0 };
                                              uint32_t id_1788 { n_ref_682[id_1787] };
                                              uint8_t id_1789 { 0 };
                                              uint32_t id_1790 { lebsz_ref_683[id_1789] };
                                              uint8_t id_1791 { 7 };
                                              uint32_t id_1792 { uint32_t(id_1790 << id_1791) };
                                              bool id_1793 { bool(id_1788 >= id_1792) };
                                              while_flag_1786 = id_1793;
                                              if (while_flag_1786) {
                                                uint8_t id_1794 { 0 };
                                                uint8_t id_1795 { 0 };
                                                uint32_t id_1796 { lebsz_ref_683[id_1795] };
                                                uint32_t id_1797 { 1U };
                                                uint32_t id_1798 { uint32_t(id_1796 + id_1797) };
                                                Void id_1799 { ((void)(lebsz_ref_683[id_1794] = id_1798), VOID) };
                                                (void)id_1799;
                                              }
                                            } while (while_flag_1786);
                                            (void)VOID;
                                            uint8_t id_1800 { 0 };
                                            uint32_t id_1801 { lebsz_ref_683[id_1800] };
                                            Size id_1802 { Size(id_1801) };
                                            let_res_1785 = id_1802;
                                          }
                                          let_res_1782 = let_res_1785;
                                        }
                                        ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_1803 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1804 { std::get<1>(id_1803) };
                                        std::string id_1805 { std::get<0 /* Contacts */>(id_1804) };
                                        uint32_t id_1806 { (uint32_t)id_1805.size() };
                                        Size id_1807 { Size(id_1806) };
                                        Size id_1808 { Size(let_res_1782 + id_1807) };
                                        Size id_1809 { Size(id_1776 + id_1808) };
                                        choose_res_1774 = id_1809;
                                      } else {
                                        ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_1810 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1811 { std::get<1>(id_1810) };
                                        uint16_t id_1812 { uint16_t(id_1811.index()) };
                                        uint16_t id_1813 { 1 };
                                        bool id_1814 { bool(id_1812 == id_1813) };
                                        Void id_1815 { ((void)(assert(id_1814)), VOID) };
                                        (void)id_1815;
                                        Size id_1816 { 2UL };
                                        Size id_1817 { Size(sz_676 + id_1816) };
                                        ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_1818 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1819 { std::get<1>(id_1818) };
                                        std::string id_1820 { std::get<1 /* Inhibition */>(id_1819) };
                                        uint32_t id_1821 { (uint32_t)id_1820.size() };
                                        Vec<1, uint32_t> id_1822 {  id_1821  };
                                        Size let_res_1823;
                                        {
                                          Vec<1, uint32_t> n_ref_679 { id_1822 };
                                          uint32_t id_1824 { 1U };
                                          Vec<1, uint32_t> id_1825 {  id_1824  };
                                          Size let_res_1826;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_680 { id_1825 };
                                            bool while_flag_1827 { true };
                                            do {
                                              uint8_t id_1828 { 0 };
                                              uint32_t id_1829 { n_ref_679[id_1828] };
                                              uint8_t id_1830 { 0 };
                                              uint32_t id_1831 { lebsz_ref_680[id_1830] };
                                              uint8_t id_1832 { 7 };
                                              uint32_t id_1833 { uint32_t(id_1831 << id_1832) };
                                              bool id_1834 { bool(id_1829 >= id_1833) };
                                              while_flag_1827 = id_1834;
                                              if (while_flag_1827) {
                                                uint8_t id_1835 { 0 };
                                                uint8_t id_1836 { 0 };
                                                uint32_t id_1837 { lebsz_ref_680[id_1836] };
                                                uint32_t id_1838 { 1U };
                                                uint32_t id_1839 { uint32_t(id_1837 + id_1838) };
                                                Void id_1840 { ((void)(lebsz_ref_680[id_1835] = id_1839), VOID) };
                                                (void)id_1840;
                                              }
                                            } while (while_flag_1827);
                                            (void)VOID;
                                            uint8_t id_1841 { 0 };
                                            uint32_t id_1842 { lebsz_ref_680[id_1841] };
                                            Size id_1843 { Size(id_1842) };
                                            let_res_1826 = id_1843;
                                          }
                                          let_res_1823 = let_res_1826;
                                        }
                                        ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_1844 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1845 { std::get<1>(id_1844) };
                                        std::string id_1846 { std::get<1 /* Inhibition */>(id_1845) };
                                        uint32_t id_1847 { (uint32_t)id_1846.size() };
                                        Size id_1848 { Size(id_1847) };
                                        Size id_1849 { Size(let_res_1823 + id_1848) };
                                        Size id_1850 { Size(id_1817 + id_1849) };
                                        choose_res_1774 = id_1850;
                                      }
                                      let_res_1768 = choose_res_1774;
                                    }
                                    choose_res_1735 = let_res_1768;
                                  } else {
                                    uint16_t id_1851 { 15 };
                                    bool id_1852 { bool(label2_657 == id_1851) };
                                    Void id_1853 { ((void)(assert(id_1852)), VOID) };
                                    (void)id_1853;
                                    Size id_1854 { 2UL };
                                    ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_1855 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1856 { std::get<0>(id_1855) };
                                    uint32_t id_1857 { (uint32_t)id_1856.size() };
                                    Vec<1, uint32_t> id_1858 {  id_1857  };
                                    Size let_res_1859;
                                    {
                                      Vec<1, uint32_t> n_ref_660 { id_1858 };
                                      uint32_t id_1860 { 1U };
                                      Vec<1, uint32_t> id_1861 {  id_1860  };
                                      Size let_res_1862;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_661 { id_1861 };
                                        bool while_flag_1863 { true };
                                        do {
                                          uint8_t id_1864 { 0 };
                                          uint32_t id_1865 { n_ref_660[id_1864] };
                                          uint8_t id_1866 { 0 };
                                          uint32_t id_1867 { lebsz_ref_661[id_1866] };
                                          uint8_t id_1868 { 7 };
                                          uint32_t id_1869 { uint32_t(id_1867 << id_1868) };
                                          bool id_1870 { bool(id_1865 >= id_1869) };
                                          while_flag_1863 = id_1870;
                                          if (while_flag_1863) {
                                            uint8_t id_1871 { 0 };
                                            uint8_t id_1872 { 0 };
                                            uint32_t id_1873 { lebsz_ref_661[id_1872] };
                                            uint32_t id_1874 { 1U };
                                            uint32_t id_1875 { uint32_t(id_1873 + id_1874) };
                                            Void id_1876 { ((void)(lebsz_ref_661[id_1871] = id_1875), VOID) };
                                            (void)id_1876;
                                          }
                                        } while (while_flag_1863);
                                        (void)VOID;
                                        uint8_t id_1877 { 0 };
                                        uint32_t id_1878 { lebsz_ref_661[id_1877] };
                                        Size id_1879 { Size(id_1878) };
                                        let_res_1862 = id_1879;
                                      }
                                      let_res_1859 = let_res_1862;
                                    }
                                    ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_1880 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1881 { std::get<0>(id_1880) };
                                    uint32_t id_1882 { (uint32_t)id_1881.size() };
                                    Size id_1883 { Size(id_1882) };
                                    Size id_1884 { Size(let_res_1859 + id_1883) };
                                    Size id_1885 { Size(id_1854 + id_1884) };
                                    Size let_res_1886;
                                    {
                                      Size sz_662 { id_1885 };
                                      ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_1887 { std::get<15 /* Incidents */>((*p_0)) };
                                      ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_1888 { std::get<1>(id_1887) };
                                      uint16_t id_1889 { uint16_t(id_1888.index()) };
                                      Size let_res_1890;
                                      {
                                        uint16_t label2_663 { id_1889 };
                                        uint16_t id_1891 { 0 };
                                        bool id_1892 { bool(id_1891 == label2_663) };
                                        Size choose_res_1893;
                                        if (id_1892) {
                                          Size id_1894 { 2UL };
                                          Size id_1895 { Size(sz_662 + id_1894) };
                                          choose_res_1893 = id_1895;
                                        } else {
                                          uint16_t id_1896 { 1 };
                                          bool id_1897 { bool(id_1896 == label2_663) };
                                          Size choose_res_1898;
                                          if (id_1897) {
                                            Size id_1899 { 2UL };
                                            Size id_1900 { Size(sz_662 + id_1899) };
                                            choose_res_1898 = id_1900;
                                          } else {
                                            uint16_t id_1901 { 2 };
                                            bool id_1902 { bool(id_1901 == label2_663) };
                                            Size choose_res_1903;
                                            if (id_1902) {
                                              Size id_1904 { 2UL };
                                              Size id_1905 { Size(sz_662 + id_1904) };
                                              choose_res_1903 = id_1905;
                                            } else {
                                              uint16_t id_1906 { 3 };
                                              bool id_1907 { bool(id_1906 == label2_663) };
                                              Size choose_res_1908;
                                              if (id_1907) {
                                                Size id_1909 { 2UL };
                                                Size id_1910 { Size(sz_662 + id_1909) };
                                                choose_res_1908 = id_1910;
                                              } else {
                                                uint16_t id_1911 { 4 };
                                                bool id_1912 { bool(id_1911 == label2_663) };
                                                Size choose_res_1913;
                                                if (id_1912) {
                                                  Size id_1914 { 2UL };
                                                  Size id_1915 { Size(sz_662 + id_1914) };
                                                  choose_res_1913 = id_1915;
                                                } else {
                                                  uint16_t id_1916 { 5 };
                                                  bool id_1917 { bool(id_1916 == label2_663) };
                                                  Size choose_res_1918;
                                                  if (id_1917) {
                                                    Size id_1919 { 2UL };
                                                    Size id_1920 { Size(sz_662 + id_1919) };
                                                    ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_1921 { std::get<15 /* Incidents */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_1922 { std::get<1>(id_1921) };
                                                    ::dessser::gen::sync_key::t51130975cc895752ed58d8b9dd6b2622 id_1923 { std::get<5 /* Dialogs */>(id_1922) };
                                                    std::string id_1924 { std::get<0>(id_1923) };
                                                    uint32_t id_1925 { (uint32_t)id_1924.size() };
                                                    Vec<1, uint32_t> id_1926 {  id_1925  };
                                                    Size let_res_1927;
                                                    {
                                                      Vec<1, uint32_t> n_ref_668 { id_1926 };
                                                      uint32_t id_1928 { 1U };
                                                      Vec<1, uint32_t> id_1929 {  id_1928  };
                                                      Size let_res_1930;
                                                      {
                                                        Vec<1, uint32_t> lebsz_ref_669 { id_1929 };
                                                        bool while_flag_1931 { true };
                                                        do {
                                                          uint8_t id_1932 { 0 };
                                                          uint32_t id_1933 { n_ref_668[id_1932] };
                                                          uint8_t id_1934 { 0 };
                                                          uint32_t id_1935 { lebsz_ref_669[id_1934] };
                                                          uint8_t id_1936 { 7 };
                                                          uint32_t id_1937 { uint32_t(id_1935 << id_1936) };
                                                          bool id_1938 { bool(id_1933 >= id_1937) };
                                                          while_flag_1931 = id_1938;
                                                          if (while_flag_1931) {
                                                            uint8_t id_1939 { 0 };
                                                            uint8_t id_1940 { 0 };
                                                            uint32_t id_1941 { lebsz_ref_669[id_1940] };
                                                            uint32_t id_1942 { 1U };
                                                            uint32_t id_1943 { uint32_t(id_1941 + id_1942) };
                                                            Void id_1944 { ((void)(lebsz_ref_669[id_1939] = id_1943), VOID) };
                                                            (void)id_1944;
                                                          }
                                                        } while (while_flag_1931);
                                                        (void)VOID;
                                                        uint8_t id_1945 { 0 };
                                                        uint32_t id_1946 { lebsz_ref_669[id_1945] };
                                                        Size id_1947 { Size(id_1946) };
                                                        let_res_1930 = id_1947;
                                                      }
                                                      let_res_1927 = let_res_1930;
                                                    }
                                                    ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_1948 { std::get<15 /* Incidents */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_1949 { std::get<1>(id_1948) };
                                                    ::dessser::gen::sync_key::t51130975cc895752ed58d8b9dd6b2622 id_1950 { std::get<5 /* Dialogs */>(id_1949) };
                                                    std::string id_1951 { std::get<0>(id_1950) };
                                                    uint32_t id_1952 { (uint32_t)id_1951.size() };
                                                    Size id_1953 { Size(id_1952) };
                                                    Size id_1954 { Size(let_res_1927 + id_1953) };
                                                    Size id_1955 { Size(id_1920 + id_1954) };
                                                    Size let_res_1956;
                                                    {
                                                      Size sz_670 { id_1955 };
                                                      ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_1957 { std::get<15 /* Incidents */>((*p_0)) };
                                                      ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_1958 { std::get<1>(id_1957) };
                                                      ::dessser::gen::sync_key::t51130975cc895752ed58d8b9dd6b2622 id_1959 { std::get<5 /* Dialogs */>(id_1958) };
                                                      ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_1960 { std::get<1>(id_1959) };
                                                      uint16_t id_1961 { uint16_t(id_1960.index()) };
                                                      Size let_res_1962;
                                                      {
                                                        uint16_t label2_671 { id_1961 };
                                                        uint16_t id_1963 { 0 };
                                                        bool id_1964 { bool(id_1963 == label2_671) };
                                                        Size choose_res_1965;
                                                        if (id_1964) {
                                                          Size id_1966 { 2UL };
                                                          Size id_1967 { Size(sz_670 + id_1966) };
                                                          choose_res_1965 = id_1967;
                                                        } else {
                                                          uint16_t id_1968 { 1 };
                                                          bool id_1969 { bool(id_1968 == label2_671) };
                                                          Size choose_res_1970;
                                                          if (id_1969) {
                                                            Size id_1971 { 2UL };
                                                            Size id_1972 { Size(sz_670 + id_1971) };
                                                            choose_res_1970 = id_1972;
                                                          } else {
                                                            uint16_t id_1973 { 2 };
                                                            bool id_1974 { bool(id_1973 == label2_671) };
                                                            Size choose_res_1975;
                                                            if (id_1974) {
                                                              Size id_1976 { 2UL };
                                                              Size id_1977 { Size(sz_670 + id_1976) };
                                                              choose_res_1975 = id_1977;
                                                            } else {
                                                              uint16_t id_1978 { 3 };
                                                              bool id_1979 { bool(id_1978 == label2_671) };
                                                              Size choose_res_1980;
                                                              if (id_1979) {
                                                                Size id_1981 { 2UL };
                                                                Size id_1982 { Size(sz_670 + id_1981) };
                                                                choose_res_1980 = id_1982;
                                                              } else {
                                                                uint16_t id_1983 { 4 };
                                                                bool id_1984 { bool(id_1983 == label2_671) };
                                                                Size choose_res_1985;
                                                                if (id_1984) {
                                                                  Size id_1986 { 2UL };
                                                                  Size id_1987 { Size(sz_670 + id_1986) };
                                                                  choose_res_1985 = id_1987;
                                                                } else {
                                                                  uint16_t id_1988 { 5 };
                                                                  bool id_1989 { bool(id_1988 == label2_671) };
                                                                  Size choose_res_1990;
                                                                  if (id_1989) {
                                                                    Size id_1991 { 2UL };
                                                                    Size id_1992 { Size(sz_670 + id_1991) };
                                                                    choose_res_1990 = id_1992;
                                                                  } else {
                                                                    uint16_t id_1993 { 6 };
                                                                    bool id_1994 { bool(label2_671 == id_1993) };
                                                                    Void id_1995 { ((void)(assert(id_1994)), VOID) };
                                                                    (void)id_1995;
                                                                    Size id_1996 { 2UL };
                                                                    Size id_1997 { Size(sz_670 + id_1996) };
                                                                    choose_res_1990 = id_1997;
                                                                  }
                                                                  choose_res_1985 = choose_res_1990;
                                                                }
                                                                choose_res_1980 = choose_res_1985;
                                                              }
                                                              choose_res_1975 = choose_res_1980;
                                                            }
                                                            choose_res_1970 = choose_res_1975;
                                                          }
                                                          choose_res_1965 = choose_res_1970;
                                                        }
                                                        let_res_1962 = choose_res_1965;
                                                      }
                                                      let_res_1956 = let_res_1962;
                                                    }
                                                    choose_res_1918 = let_res_1956;
                                                  } else {
                                                    uint16_t id_1998 { 6 };
                                                    bool id_1999 { bool(label2_663 == id_1998) };
                                                    Void id_2000 { ((void)(assert(id_1999)), VOID) };
                                                    (void)id_2000;
                                                    Size id_2001 { 2UL };
                                                    Size id_2002 { Size(sz_662 + id_2001) };
                                                    Size id_2003 { 8UL };
                                                    Size id_2004 { Size(id_2002 + id_2003) };
                                                    Size id_2005 { 4UL };
                                                    Size id_2006 { Size(id_2004 + id_2005) };
                                                    choose_res_1918 = id_2006;
                                                  }
                                                  choose_res_1913 = choose_res_1918;
                                                }
                                                choose_res_1908 = choose_res_1913;
                                              }
                                              choose_res_1903 = choose_res_1908;
                                            }
                                            choose_res_1898 = choose_res_1903;
                                          }
                                          choose_res_1893 = choose_res_1898;
                                        }
                                        let_res_1890 = choose_res_1893;
                                      }
                                      let_res_1886 = let_res_1890;
                                    }
                                    choose_res_1735 = let_res_1886;
                                  }
                                  choose_res_1731 = choose_res_1735;
                                }
                                choose_res_1691 = choose_res_1731;
                              }
                              choose_res_1627 = choose_res_1691;
                            }
                            choose_res_1623 = choose_res_1627;
                          }
                          choose_res_1608 = choose_res_1623;
                        }
                        choose_res_1604 = choose_res_1608;
                      }
                      choose_res_1505 = choose_res_1604;
                    }
                    choose_res_1453 = choose_res_1505;
                  }
                  choose_res_1160 = choose_res_1453;
                }
                choose_res_1156 = choose_res_1160;
              }
              choose_res_1115 = choose_res_1156;
            }
            choose_res_1082 = choose_res_1115;
          }
          choose_res_1078 = choose_res_1082;
        }
        choose_res_1074 = choose_res_1078;
      }
      let_res_1071 = choose_res_1074;
    }
    return let_res_1071;
  }
   };
  return fun1069;
}
std::function<Size(::dessser::gen::sync_key::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_62" (let-pair "du16_fst_57" "du16_snd_58" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_57") (identifier "du16_snd_58")))
        (let-pair "dsum1_fst_63" "dsum1_snd_64" (identifier "dsum1_62")
          (seq (assert (eq (identifier "dsum1_fst_63") (u16 0)))
            (let-pair "du32_fst_66" "du32_snd_67" (read-u32 little-endian (identifier "dsum1_snd_64")) (make-tup (construct "[Widgets U32]" 0 (identifier "du32_fst_66")) (identifier "du32_snd_67")))))))
 */
static std::function<::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9(Pointer)> per_dash_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9(Pointer)> fun2007 { [&fun2007](Pointer p_0) {
    ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2008 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2009;
    {
      auto du16_fst_57 { std::get<0>(id_2008) };
      auto du16_snd_58 { std::get<1>(id_2008) };
      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2010 { du16_fst_57, du16_snd_58 };
      letpair_res_2009 = id_2010;
    }
    ::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9 let_res_2011;
    {
      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_62 { letpair_res_2009 };
      ::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9 letpair_res_2012;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_2013 { 0 };
        bool id_2014 { bool(dsum1_fst_63 == id_2013) };
        Void id_2015 { ((void)(assert(id_2014)), VOID) };
        (void)id_2015;
        ::dessser::gen::sync_key::t405eb186408556fed8f2c41523c07d13 id_2016 { dsum1_snd_64.readU32Le() };
        ::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9 letpair_res_2017;
        {
          auto du32_fst_66 { std::get<0>(id_2016) };
          auto du32_snd_67 { std::get<1>(id_2016) };
          ::dessser::gen::sync_key::per_dash_key* id_2018 { new ::dessser::gen::sync_key::per_dash_key(std::in_place_index<0>, du32_fst_66) };
          ::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9 id_2019 { id_2018, du32_snd_67 };
          letpair_res_2017 = id_2019;
        }
        letpair_res_2012 = letpair_res_2017;
      }
      let_res_2011 = letpair_res_2012;
    }
    return let_res_2011;
  }
   };
  return fun2007;
}
std::function<::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9(Pointer)> per_dash_key_of_row_binary(per_dash_key_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_654" "make_snd_655"
        (let "dsum1_80" (let-pair "du16_fst_75" "du16_snd_76" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_75") (identifier "du16_snd_76")))
          (let-pair "dsum1_fst_81" "dsum1_snd_82" (identifier "dsum1_80")
            (if (eq (u16 0) (identifier "dsum1_fst_81"))
              (make-tup
                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 0
                  (nop)) (identifier "dsum1_snd_82"))
              (if (eq (u16 1) (identifier "dsum1_fst_81"))
                (make-tup
                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 1
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
                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 2
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
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 3
                                  (make-tup (identifier "dtup_fst_612") (string-of-bytes (identifier "dstring2_fst_624")))) 
                                (identifier "dstring2_snd_625")))))))
                    (if (eq (u16 4) (identifier "dsum1_fst_81"))
                      (make-tup
                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 4
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
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 5
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
                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 6
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
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 7
                                              (make-tup (identifier "dtup_fst_330") (identifier "dtup_fst_333") (identifier "dtup_fst_348") (identifier "dtup_fst_381"))) 
                                            (identifier "dtup_snd_382")))))))))
                            (if (eq (u16 8) (identifier "dsum1_fst_81"))
                              (let-pair "du16_fst_324" "du16_snd_325" 
                                (read-u16 little-endian (identifier "dsum1_snd_82"))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 8
                                    (identifier "du16_fst_324")) (identifier "du16_snd_325")))
                              (if (eq (u16 9) (identifier "dsum1_fst_81"))
                                (let-pair "dsum2_fst_321" "dsum2_snd_322"
                                  (if (eq (peek-u8 (identifier "dsum1_snd_82") (size 0)) (u8 1)) 
                                    (make-tup (null "$sync_socket") (ptr-add (identifier "dsum1_snd_82") (size 1)))
                                    (let-pair "make1_1_fst_318" "make1_1_snd_319" 
                                      (apply (ext-identifier sync_socket of-row-binary) (ptr-add (identifier "dsum1_snd_82") (size 1))) 
                                      (make-tup (not-null (identifier "make1_1_fst_318")) (identifier "make1_1_snd_319"))))
                                  (make-tup
                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 9
                                      (identifier "dsum2_fst_321")) (identifier "dsum2_snd_322")))
                                (if (eq (u16 10) (identifier "dsum1_fst_81"))
                                  (make-tup
                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 10
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
                                                      (make-tup (construct "[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" 0 (string-of-bytes (identifier "dstring2_fst_303"))) (identifier "dstring2_snd_304")))))
                                                (seq (assert (eq (identifier "dsum1_fst_288") (u16 1)))
                                                  (let-pair "dsum2_fst_291" "dsum2_snd_292" 
                                                    (apply (identifier "per_dash_key-of-row-binary") (identifier "dsum1_snd_289"))
                                                    (make-tup (construct "[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" 1 (identifier "dsum2_fst_291")) (identifier "dsum2_snd_292")))))))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 11
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
                                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 12
                                                (make-tup (identifier "dtup_fst_270") (identifier "dtup_fst_273"))) 
                                              (identifier "dtup_snd_274")))))
                                      (if (eq (u16 13) (identifier "dsum1_fst_81"))
                                        (make-tup
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 13
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
                                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 14
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
                                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; [Subscriber STRING | LastTuple U32]) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 15
                                                      (make-tup (identifier "dtup_fst_96") (identifier "dtup_fst_189"))) 
                                                    (identifier "dtup_snd_190"))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_654") (identifier "make_snd_655"))))
 */
static std::function<::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d(Pointer)> fun2020 { [&fun2020](Pointer p_0) {
    ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2021 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2022;
    {
      auto du16_fst_75 { std::get<0>(id_2021) };
      auto du16_snd_76 { std::get<1>(id_2021) };
      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2023 { du16_fst_75, du16_snd_76 };
      letpair_res_2022 = id_2023;
    }
    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2024;
    {
      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_80 { letpair_res_2022 };
      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2025;
      {
        auto dsum1_fst_81 { std::get<0>(dsum1_80) };
        auto dsum1_snd_82 { std::get<1>(dsum1_80) };
        uint16_t id_2026 { 0 };
        bool id_2027 { bool(id_2026 == dsum1_fst_81) };
        ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2028;
        if (id_2027) {
          (void)VOID;
          ::dessser::gen::sync_key::t* id_2029 { new ::dessser::gen::sync_key::t(std::in_place_index<0>, VOID) };
          ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2030 { id_2029, dsum1_snd_82 };
          choose_res_2028 = id_2030;
        } else {
          uint16_t id_2031 { 1 };
          bool id_2032 { bool(id_2031 == dsum1_fst_81) };
          ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2033;
          if (id_2032) {
            (void)VOID;
            ::dessser::gen::sync_key::t* id_2034 { new ::dessser::gen::sync_key::t(std::in_place_index<1>, VOID) };
            ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2035 { id_2034, dsum1_snd_82 };
            choose_res_2033 = id_2035;
          } else {
            uint16_t id_2036 { 2 };
            bool id_2037 { bool(id_2036 == dsum1_fst_81) };
            ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2038;
            if (id_2037) {
              uint32_t id_2039 { 0U };
              Vec<1, uint32_t> id_2040 {  id_2039  };
              ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2041;
              {
                Vec<1, uint32_t> leb_ref_632 { id_2040 };
                uint8_t id_2042 { 0 };
                Vec<1, uint8_t> id_2043 {  id_2042  };
                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2044;
                {
                  Vec<1, uint8_t> shft_ref_633 { id_2043 };
                  Vec<1, Pointer> id_2045 {  dsum1_snd_82  };
                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2046;
                  {
                    Vec<1, Pointer> p_ref_634 { id_2045 };
                    bool while_flag_2047 { true };
                    do {
                      uint8_t id_2048 { 0 };
                      Pointer id_2049 { p_ref_634[id_2048] };
                      ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2050 { id_2049.readU8() };
                      bool let_res_2051;
                      {
                        ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_635 { id_2050 };
                        bool letpair_res_2052;
                        {
                          auto leb128_fst_636 { std::get<0>(leb128_635) };
                          auto leb128_snd_637 { std::get<1>(leb128_635) };
                          uint8_t id_2053 { 0 };
                          Void id_2054 { ((void)(p_ref_634[id_2053] = leb128_snd_637), VOID) };
                          (void)id_2054;
                          uint8_t id_2055 { 0 };
                          uint8_t id_2056 { 127 };
                          uint8_t id_2057 { uint8_t(leb128_fst_636 & id_2056) };
                          uint32_t id_2058 { uint32_t(id_2057) };
                          uint8_t id_2059 { 0 };
                          uint8_t id_2060 { shft_ref_633[id_2059] };
                          uint32_t id_2061 { uint32_t(id_2058 << id_2060) };
                          uint8_t id_2062 { 0 };
                          uint32_t id_2063 { leb_ref_632[id_2062] };
                          uint32_t id_2064 { uint32_t(id_2061 | id_2063) };
                          Void id_2065 { ((void)(leb_ref_632[id_2055] = id_2064), VOID) };
                          (void)id_2065;
                          uint8_t id_2066 { 0 };
                          uint8_t id_2067 { 0 };
                          uint8_t id_2068 { shft_ref_633[id_2067] };
                          uint8_t id_2069 { 7 };
                          uint8_t id_2070 { uint8_t(id_2068 + id_2069) };
                          Void id_2071 { ((void)(shft_ref_633[id_2066] = id_2070), VOID) };
                          (void)id_2071;
                          uint8_t id_2072 { 128 };
                          bool id_2073 { bool(leb128_fst_636 >= id_2072) };
                          letpair_res_2052 = id_2073;
                        }
                        let_res_2051 = letpair_res_2052;
                      }
                      while_flag_2047 = let_res_2051;
                      if (while_flag_2047) {
                        (void)VOID;
                      }
                    } while (while_flag_2047);
                    (void)VOID;
                    uint8_t id_2074 { 0 };
                    uint32_t id_2075 { leb_ref_632[id_2074] };
                    Size id_2076 { Size(id_2075) };
                    uint8_t id_2077 { 0 };
                    Pointer id_2078 { p_ref_634[id_2077] };
                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2079 { id_2076, id_2078 };
                    let_res_2046 = id_2079;
                  }
                  let_res_2044 = let_res_2046;
                }
                let_res_2041 = let_res_2044;
              }
              ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2080;
              {
                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_638 { let_res_2041 };
                ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2081;
                {
                  auto dstring1_fst_639 { std::get<0>(dstring1_638) };
                  auto dstring1_snd_640 { std::get<1>(dstring1_638) };
                  ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2082 { dstring1_snd_640.readBytes(dstring1_fst_639) };
                  ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2083;
                  {
                    auto dstring2_fst_642 { std::get<0>(id_2082) };
                    auto dstring2_snd_643 { std::get<1>(id_2082) };
                    std::string id_2084 { dstring2_fst_642.toString() };
                    ::dessser::gen::sync_key::t* id_2085 { new ::dessser::gen::sync_key::t(std::in_place_index<2>, id_2084) };
                    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2086 { id_2085, dstring2_snd_643 };
                    letpair_res_2083 = id_2086;
                  }
                  letpair_res_2081 = letpair_res_2083;
                }
                let_res_2080 = letpair_res_2081;
              }
              choose_res_2038 = let_res_2080;
            } else {
              uint16_t id_2087 { 3 };
              bool id_2088 { bool(id_2087 == dsum1_fst_81) };
              ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2089;
              if (id_2088) {
                auto fun2090 { dessser::gen::src_path::of_row_binary };
                ::dessser::gen::sync_key::t3aef8ea133ee816827fd8db245b58487 id_2091 { fun2090(dsum1_snd_82) };
                ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2092;
                {
                  ::dessser::gen::sync_key::t3aef8ea133ee816827fd8db245b58487 dtup_611 { id_2091 };
                  ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2093;
                  {
                    auto dtup_fst_612 { std::get<0>(dtup_611) };
                    auto dtup_snd_613 { std::get<1>(dtup_611) };
                    uint32_t id_2094 { 0U };
                    Vec<1, uint32_t> id_2095 {  id_2094  };
                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2096;
                    {
                      Vec<1, uint32_t> leb_ref_614 { id_2095 };
                      uint8_t id_2097 { 0 };
                      Vec<1, uint8_t> id_2098 {  id_2097  };
                      ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2099;
                      {
                        Vec<1, uint8_t> shft_ref_615 { id_2098 };
                        Vec<1, Pointer> id_2100 {  dtup_snd_613  };
                        ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2101;
                        {
                          Vec<1, Pointer> p_ref_616 { id_2100 };
                          bool while_flag_2102 { true };
                          do {
                            uint8_t id_2103 { 0 };
                            Pointer id_2104 { p_ref_616[id_2103] };
                            ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2105 { id_2104.readU8() };
                            bool let_res_2106;
                            {
                              ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_617 { id_2105 };
                              bool letpair_res_2107;
                              {
                                auto leb128_fst_618 { std::get<0>(leb128_617) };
                                auto leb128_snd_619 { std::get<1>(leb128_617) };
                                uint8_t id_2108 { 0 };
                                Void id_2109 { ((void)(p_ref_616[id_2108] = leb128_snd_619), VOID) };
                                (void)id_2109;
                                uint8_t id_2110 { 0 };
                                uint8_t id_2111 { 127 };
                                uint8_t id_2112 { uint8_t(leb128_fst_618 & id_2111) };
                                uint32_t id_2113 { uint32_t(id_2112) };
                                uint8_t id_2114 { 0 };
                                uint8_t id_2115 { shft_ref_615[id_2114] };
                                uint32_t id_2116 { uint32_t(id_2113 << id_2115) };
                                uint8_t id_2117 { 0 };
                                uint32_t id_2118 { leb_ref_614[id_2117] };
                                uint32_t id_2119 { uint32_t(id_2116 | id_2118) };
                                Void id_2120 { ((void)(leb_ref_614[id_2110] = id_2119), VOID) };
                                (void)id_2120;
                                uint8_t id_2121 { 0 };
                                uint8_t id_2122 { 0 };
                                uint8_t id_2123 { shft_ref_615[id_2122] };
                                uint8_t id_2124 { 7 };
                                uint8_t id_2125 { uint8_t(id_2123 + id_2124) };
                                Void id_2126 { ((void)(shft_ref_615[id_2121] = id_2125), VOID) };
                                (void)id_2126;
                                uint8_t id_2127 { 128 };
                                bool id_2128 { bool(leb128_fst_618 >= id_2127) };
                                letpair_res_2107 = id_2128;
                              }
                              let_res_2106 = letpair_res_2107;
                            }
                            while_flag_2102 = let_res_2106;
                            if (while_flag_2102) {
                              (void)VOID;
                            }
                          } while (while_flag_2102);
                          (void)VOID;
                          uint8_t id_2129 { 0 };
                          uint32_t id_2130 { leb_ref_614[id_2129] };
                          Size id_2131 { Size(id_2130) };
                          uint8_t id_2132 { 0 };
                          Pointer id_2133 { p_ref_616[id_2132] };
                          ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2134 { id_2131, id_2133 };
                          let_res_2101 = id_2134;
                        }
                        let_res_2099 = let_res_2101;
                      }
                      let_res_2096 = let_res_2099;
                    }
                    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2135;
                    {
                      ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_620 { let_res_2096 };
                      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2136;
                      {
                        auto dstring1_fst_621 { std::get<0>(dstring1_620) };
                        auto dstring1_snd_622 { std::get<1>(dstring1_620) };
                        ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2137 { dstring1_snd_622.readBytes(dstring1_fst_621) };
                        ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2138;
                        {
                          auto dstring2_fst_624 { std::get<0>(id_2137) };
                          auto dstring2_snd_625 { std::get<1>(id_2137) };
                          std::string id_2139 { dstring2_fst_624.toString() };
                          ::dessser::gen::sync_key::t274013922fc0b2cd45c289bf2ba4463d id_2140 { dtup_fst_612, id_2139 };
                          ::dessser::gen::sync_key::t* id_2141 { new ::dessser::gen::sync_key::t(std::in_place_index<3>, id_2140) };
                          ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2142 { id_2141, dstring2_snd_625 };
                          letpair_res_2138 = id_2142;
                        }
                        letpair_res_2136 = letpair_res_2138;
                      }
                      let_res_2135 = letpair_res_2136;
                    }
                    letpair_res_2093 = let_res_2135;
                  }
                  let_res_2092 = letpair_res_2093;
                }
                choose_res_2089 = let_res_2092;
              } else {
                uint16_t id_2143 { 4 };
                bool id_2144 { bool(id_2143 == dsum1_fst_81) };
                ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2145;
                if (id_2144) {
                  (void)VOID;
                  ::dessser::gen::sync_key::t* id_2146 { new ::dessser::gen::sync_key::t(std::in_place_index<4>, VOID) };
                  ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2147 { id_2146, dsum1_snd_82 };
                  choose_res_2145 = id_2147;
                } else {
                  uint16_t id_2148 { 5 };
                  bool id_2149 { bool(id_2148 == dsum1_fst_81) };
                  ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2150;
                  if (id_2149) {
                    auto fun2151 { dessser::gen::site_name::of_row_binary };
                    ::dessser::gen::sync_key::tb31a43e42345099d489759a9c141b1b9 id_2152 { fun2151(dsum1_snd_82) };
                    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2153;
                    {
                      ::dessser::gen::sync_key::tb31a43e42345099d489759a9c141b1b9 dtup_419 { id_2152 };
                      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2154;
                      {
                        auto dtup_fst_420 { std::get<0>(dtup_419) };
                        auto dtup_snd_421 { std::get<1>(dtup_419) };
                        ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2155 { dtup_snd_421.readU16Le() };
                        ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2156;
                        {
                          auto du16_fst_423 { std::get<0>(id_2155) };
                          auto du16_snd_424 { std::get<1>(id_2155) };
                          ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2157 { du16_fst_423, du16_snd_424 };
                          letpair_res_2156 = id_2157;
                        }
                        ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e let_res_2158;
                        {
                          ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_428 { letpair_res_2156 };
                          ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e letpair_res_2159;
                          {
                            auto dsum1_fst_429 { std::get<0>(dsum1_428) };
                            auto dsum1_snd_430 { std::get<1>(dsum1_428) };
                            uint16_t id_2160 { 0 };
                            bool id_2161 { bool(id_2160 == dsum1_fst_429) };
                            ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e choose_res_2162;
                            if (id_2161) {
                              (void)VOID;
                              ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_2163 { std::in_place_index<0>, VOID };
                              ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e id_2164 { id_2163, dsum1_snd_430 };
                              choose_res_2162 = id_2164;
                            } else {
                              uint16_t id_2165 { 1 };
                              bool id_2166 { bool(id_2165 == dsum1_fst_429) };
                              ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e choose_res_2167;
                              if (id_2166) {
                                uint32_t id_2168 { 0U };
                                Vec<1, uint32_t> id_2169 {  id_2168  };
                                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2170;
                                {
                                  Vec<1, uint32_t> leb_ref_563 { id_2169 };
                                  uint8_t id_2171 { 0 };
                                  Vec<1, uint8_t> id_2172 {  id_2171  };
                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2173;
                                  {
                                    Vec<1, uint8_t> shft_ref_564 { id_2172 };
                                    Vec<1, Pointer> id_2174 {  dsum1_snd_430  };
                                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2175;
                                    {
                                      Vec<1, Pointer> p_ref_565 { id_2174 };
                                      bool while_flag_2176 { true };
                                      do {
                                        uint8_t id_2177 { 0 };
                                        Pointer id_2178 { p_ref_565[id_2177] };
                                        ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2179 { id_2178.readU8() };
                                        bool let_res_2180;
                                        {
                                          ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_566 { id_2179 };
                                          bool letpair_res_2181;
                                          {
                                            auto leb128_fst_567 { std::get<0>(leb128_566) };
                                            auto leb128_snd_568 { std::get<1>(leb128_566) };
                                            uint8_t id_2182 { 0 };
                                            Void id_2183 { ((void)(p_ref_565[id_2182] = leb128_snd_568), VOID) };
                                            (void)id_2183;
                                            uint8_t id_2184 { 0 };
                                            uint8_t id_2185 { 127 };
                                            uint8_t id_2186 { uint8_t(leb128_fst_567 & id_2185) };
                                            uint32_t id_2187 { uint32_t(id_2186) };
                                            uint8_t id_2188 { 0 };
                                            uint8_t id_2189 { shft_ref_564[id_2188] };
                                            uint32_t id_2190 { uint32_t(id_2187 << id_2189) };
                                            uint8_t id_2191 { 0 };
                                            uint32_t id_2192 { leb_ref_563[id_2191] };
                                            uint32_t id_2193 { uint32_t(id_2190 | id_2192) };
                                            Void id_2194 { ((void)(leb_ref_563[id_2184] = id_2193), VOID) };
                                            (void)id_2194;
                                            uint8_t id_2195 { 0 };
                                            uint8_t id_2196 { 0 };
                                            uint8_t id_2197 { shft_ref_564[id_2196] };
                                            uint8_t id_2198 { 7 };
                                            uint8_t id_2199 { uint8_t(id_2197 + id_2198) };
                                            Void id_2200 { ((void)(shft_ref_564[id_2195] = id_2199), VOID) };
                                            (void)id_2200;
                                            uint8_t id_2201 { 128 };
                                            bool id_2202 { bool(leb128_fst_567 >= id_2201) };
                                            letpair_res_2181 = id_2202;
                                          }
                                          let_res_2180 = letpair_res_2181;
                                        }
                                        while_flag_2176 = let_res_2180;
                                        if (while_flag_2176) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_2176);
                                      (void)VOID;
                                      uint8_t id_2203 { 0 };
                                      uint32_t id_2204 { leb_ref_563[id_2203] };
                                      Size id_2205 { Size(id_2204) };
                                      uint8_t id_2206 { 0 };
                                      Pointer id_2207 { p_ref_565[id_2206] };
                                      ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2208 { id_2205, id_2207 };
                                      let_res_2175 = id_2208;
                                    }
                                    let_res_2173 = let_res_2175;
                                  }
                                  let_res_2170 = let_res_2173;
                                }
                                ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e let_res_2209;
                                {
                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_569 { let_res_2170 };
                                  ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2210;
                                  {
                                    auto dstring1_fst_570 { std::get<0>(dstring1_569) };
                                    auto dstring1_snd_571 { std::get<1>(dstring1_569) };
                                    ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2211 { dstring1_snd_571.readBytes(dstring1_fst_570) };
                                    ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2212;
                                    {
                                      auto dstring2_fst_573 { std::get<0>(id_2211) };
                                      auto dstring2_snd_574 { std::get<1>(id_2211) };
                                      std::string id_2213 { dstring2_fst_573.toString() };
                                      ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e id_2214 { id_2213, dstring2_snd_574 };
                                      letpair_res_2212 = id_2214;
                                    }
                                    letpair_res_2210 = letpair_res_2212;
                                  }
                                  let_res_2209 = letpair_res_2210;
                                }
                                ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e let_res_2215;
                                {
                                  ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e dtup_575 { let_res_2209 };
                                  ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e letpair_res_2216;
                                  {
                                    auto dtup_fst_576 { std::get<0>(dtup_575) };
                                    auto dtup_snd_577 { std::get<1>(dtup_575) };
                                    ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2217 { dtup_snd_577.readU16Le() };
                                    ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2218;
                                    {
                                      auto du16_fst_579 { std::get<0>(id_2217) };
                                      auto du16_snd_580 { std::get<1>(id_2217) };
                                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2219 { du16_fst_579, du16_snd_580 };
                                      letpair_res_2218 = id_2219;
                                    }
                                    ::dessser::gen::sync_key::t266fb47650ef8cb696e440bff783f8e3 let_res_2220;
                                    {
                                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_584 { letpair_res_2218 };
                                      ::dessser::gen::sync_key::t266fb47650ef8cb696e440bff783f8e3 letpair_res_2221;
                                      {
                                        auto dsum1_fst_585 { std::get<0>(dsum1_584) };
                                        auto dsum1_snd_586 { std::get<1>(dsum1_584) };
                                        uint16_t id_2222 { 0 };
                                        bool id_2223 { bool(id_2222 == dsum1_fst_585) };
                                        ::dessser::gen::sync_key::t266fb47650ef8cb696e440bff783f8e3 choose_res_2224;
                                        if (id_2223) {
                                          (void)VOID;
                                          ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_2225 { std::in_place_index<0>, VOID };
                                          ::dessser::gen::sync_key::t266fb47650ef8cb696e440bff783f8e3 id_2226 { id_2225, dsum1_snd_586 };
                                          choose_res_2224 = id_2226;
                                        } else {
                                          uint16_t id_2227 { 1 };
                                          bool id_2228 { bool(dsum1_fst_585 == id_2227) };
                                          Void id_2229 { ((void)(assert(id_2228)), VOID) };
                                          (void)id_2229;
                                          (void)VOID;
                                          ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_2230 { std::in_place_index<1>, VOID };
                                          ::dessser::gen::sync_key::t266fb47650ef8cb696e440bff783f8e3 id_2231 { id_2230, dsum1_snd_586 };
                                          choose_res_2224 = id_2231;
                                        }
                                        letpair_res_2221 = choose_res_2224;
                                      }
                                      let_res_2220 = letpair_res_2221;
                                    }
                                    ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e letpair_res_2232;
                                    {
                                      auto dtup_fst_594 { std::get<0>(let_res_2220) };
                                      auto dtup_snd_595 { std::get<1>(let_res_2220) };
                                      ::dessser::gen::sync_key::t1aff348714b8a3b47c6403c353655995 id_2233 { dtup_fst_576, dtup_fst_594 };
                                      ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_2234 { std::in_place_index<1>, id_2233 };
                                      ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e id_2235 { id_2234, dtup_snd_595 };
                                      letpair_res_2232 = id_2235;
                                    }
                                    letpair_res_2216 = letpair_res_2232;
                                  }
                                  let_res_2215 = letpair_res_2216;
                                }
                                choose_res_2167 = let_res_2215;
                              } else {
                                uint16_t id_2236 { 2 };
                                bool id_2237 { bool(id_2236 == dsum1_fst_429) };
                                ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e choose_res_2238;
                                if (id_2237) {
                                  auto fun2239 { dessser::gen::fq_name::of_row_binary };
                                  ::dessser::gen::sync_key::td8eaddfacf232bd15ab91a5778e12a3b id_2240 { fun2239(dsum1_snd_430) };
                                  ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e let_res_2241;
                                  {
                                    ::dessser::gen::sync_key::td8eaddfacf232bd15ab91a5778e12a3b dtup_464 { id_2240 };
                                    ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e letpair_res_2242;
                                    {
                                      auto dtup_fst_465 { std::get<0>(dtup_464) };
                                      auto dtup_snd_466 { std::get<1>(dtup_464) };
                                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2243 { dtup_snd_466.readU16Le() };
                                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2244;
                                      {
                                        auto du16_fst_468 { std::get<0>(id_2243) };
                                        auto du16_snd_469 { std::get<1>(id_2243) };
                                        ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2245 { du16_fst_468, du16_snd_469 };
                                        letpair_res_2244 = id_2245;
                                      }
                                      ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 let_res_2246;
                                      {
                                        ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_473 { letpair_res_2244 };
                                        ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 letpair_res_2247;
                                        {
                                          auto dsum1_fst_474 { std::get<0>(dsum1_473) };
                                          auto dsum1_snd_475 { std::get<1>(dsum1_473) };
                                          uint16_t id_2248 { 0 };
                                          bool id_2249 { bool(id_2248 == dsum1_fst_474) };
                                          ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 choose_res_2250;
                                          if (id_2249) {
                                            (void)VOID;
                                            ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_2251 { std::in_place_index<0>, VOID };
                                            ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 id_2252 { id_2251, dsum1_snd_475 };
                                            choose_res_2250 = id_2252;
                                          } else {
                                            uint16_t id_2253 { 1 };
                                            bool id_2254 { bool(id_2253 == dsum1_fst_474) };
                                            ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 choose_res_2255;
                                            if (id_2254) {
                                              (void)VOID;
                                              ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_2256 { std::in_place_index<1>, VOID };
                                              ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 id_2257 { id_2256, dsum1_snd_475 };
                                              choose_res_2255 = id_2257;
                                            } else {
                                              uint16_t id_2258 { 2 };
                                              bool id_2259 { bool(id_2258 == dsum1_fst_474) };
                                              ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 choose_res_2260;
                                              if (id_2259) {
                                                (void)VOID;
                                                ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_2261 { std::in_place_index<2>, VOID };
                                                ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 id_2262 { id_2261, dsum1_snd_475 };
                                                choose_res_2260 = id_2262;
                                              } else {
                                                uint16_t id_2263 { 3 };
                                                bool id_2264 { bool(id_2263 == dsum1_fst_474) };
                                                ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 choose_res_2265;
                                                if (id_2264) {
                                                  (void)VOID;
                                                  ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_2266 { std::in_place_index<3>, VOID };
                                                  ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 id_2267 { id_2266, dsum1_snd_475 };
                                                  choose_res_2265 = id_2267;
                                                } else {
                                                  uint16_t id_2268 { 4 };
                                                  bool id_2269 { bool(id_2268 == dsum1_fst_474) };
                                                  ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 choose_res_2270;
                                                  if (id_2269) {
                                                    (void)VOID;
                                                    ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_2271 { std::in_place_index<4>, VOID };
                                                    ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 id_2272 { id_2271, dsum1_snd_475 };
                                                    choose_res_2270 = id_2272;
                                                  } else {
                                                    uint16_t id_2273 { 5 };
                                                    bool id_2274 { bool(id_2273 == dsum1_fst_474) };
                                                    ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 choose_res_2275;
                                                    if (id_2274) {
                                                      (void)VOID;
                                                      ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_2276 { std::in_place_index<5>, VOID };
                                                      ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 id_2277 { id_2276, dsum1_snd_475 };
                                                      choose_res_2275 = id_2277;
                                                    } else {
                                                      uint16_t id_2278 { 6 };
                                                      bool id_2279 { bool(id_2278 == dsum1_fst_474) };
                                                      ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 choose_res_2280;
                                                      if (id_2279) {
                                                        uint32_t id_2281 { 0U };
                                                        Vec<1, uint32_t> id_2282 {  id_2281  };
                                                        ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2283;
                                                        {
                                                          Vec<1, uint32_t> leb_ref_485 { id_2282 };
                                                          uint8_t id_2284 { 0 };
                                                          Vec<1, uint8_t> id_2285 {  id_2284  };
                                                          ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2286;
                                                          {
                                                            Vec<1, uint8_t> shft_ref_486 { id_2285 };
                                                            Vec<1, Pointer> id_2287 {  dsum1_snd_475  };
                                                            ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2288;
                                                            {
                                                              Vec<1, Pointer> p_ref_487 { id_2287 };
                                                              bool while_flag_2289 { true };
                                                              do {
                                                                uint8_t id_2290 { 0 };
                                                                Pointer id_2291 { p_ref_487[id_2290] };
                                                                ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2292 { id_2291.readU8() };
                                                                bool let_res_2293;
                                                                {
                                                                  ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_488 { id_2292 };
                                                                  bool letpair_res_2294;
                                                                  {
                                                                    auto leb128_fst_489 { std::get<0>(leb128_488) };
                                                                    auto leb128_snd_490 { std::get<1>(leb128_488) };
                                                                    uint8_t id_2295 { 0 };
                                                                    Void id_2296 { ((void)(p_ref_487[id_2295] = leb128_snd_490), VOID) };
                                                                    (void)id_2296;
                                                                    uint8_t id_2297 { 0 };
                                                                    uint8_t id_2298 { 127 };
                                                                    uint8_t id_2299 { uint8_t(leb128_fst_489 & id_2298) };
                                                                    uint32_t id_2300 { uint32_t(id_2299) };
                                                                    uint8_t id_2301 { 0 };
                                                                    uint8_t id_2302 { shft_ref_486[id_2301] };
                                                                    uint32_t id_2303 { uint32_t(id_2300 << id_2302) };
                                                                    uint8_t id_2304 { 0 };
                                                                    uint32_t id_2305 { leb_ref_485[id_2304] };
                                                                    uint32_t id_2306 { uint32_t(id_2303 | id_2305) };
                                                                    Void id_2307 { ((void)(leb_ref_485[id_2297] = id_2306), VOID) };
                                                                    (void)id_2307;
                                                                    uint8_t id_2308 { 0 };
                                                                    uint8_t id_2309 { 0 };
                                                                    uint8_t id_2310 { shft_ref_486[id_2309] };
                                                                    uint8_t id_2311 { 7 };
                                                                    uint8_t id_2312 { uint8_t(id_2310 + id_2311) };
                                                                    Void id_2313 { ((void)(shft_ref_486[id_2308] = id_2312), VOID) };
                                                                    (void)id_2313;
                                                                    uint8_t id_2314 { 128 };
                                                                    bool id_2315 { bool(leb128_fst_489 >= id_2314) };
                                                                    letpair_res_2294 = id_2315;
                                                                  }
                                                                  let_res_2293 = letpair_res_2294;
                                                                }
                                                                while_flag_2289 = let_res_2293;
                                                                if (while_flag_2289) {
                                                                  (void)VOID;
                                                                }
                                                              } while (while_flag_2289);
                                                              (void)VOID;
                                                              uint8_t id_2316 { 0 };
                                                              uint32_t id_2317 { leb_ref_485[id_2316] };
                                                              Size id_2318 { Size(id_2317) };
                                                              uint8_t id_2319 { 0 };
                                                              Pointer id_2320 { p_ref_487[id_2319] };
                                                              ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2321 { id_2318, id_2320 };
                                                              let_res_2288 = id_2321;
                                                            }
                                                            let_res_2286 = let_res_2288;
                                                          }
                                                          let_res_2283 = let_res_2286;
                                                        }
                                                        ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e let_res_2322;
                                                        {
                                                          ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_491 { let_res_2283 };
                                                          ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2323;
                                                          {
                                                            auto dstring1_fst_492 { std::get<0>(dstring1_491) };
                                                            auto dstring1_snd_493 { std::get<1>(dstring1_491) };
                                                            ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2324 { dstring1_snd_493.readBytes(dstring1_fst_492) };
                                                            ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2325;
                                                            {
                                                              auto dstring2_fst_495 { std::get<0>(id_2324) };
                                                              auto dstring2_snd_496 { std::get<1>(id_2324) };
                                                              std::string id_2326 { dstring2_fst_495.toString() };
                                                              ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e id_2327 { id_2326, dstring2_snd_496 };
                                                              letpair_res_2325 = id_2327;
                                                            }
                                                            letpair_res_2323 = letpair_res_2325;
                                                          }
                                                          let_res_2322 = letpair_res_2323;
                                                        }
                                                        ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 let_res_2328;
                                                        {
                                                          ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e dtup_497 { let_res_2322 };
                                                          ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 letpair_res_2329;
                                                          {
                                                            auto dtup_fst_498 { std::get<0>(dtup_497) };
                                                            auto dtup_snd_499 { std::get<1>(dtup_497) };
                                                            ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2330 { dtup_snd_499.readU16Le() };
                                                            ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2331;
                                                            {
                                                              auto du16_fst_501 { std::get<0>(id_2330) };
                                                              auto du16_snd_502 { std::get<1>(id_2330) };
                                                              ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2332 { du16_fst_501, du16_snd_502 };
                                                              letpair_res_2331 = id_2332;
                                                            }
                                                            ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 let_res_2333;
                                                            {
                                                              ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_506 { letpair_res_2331 };
                                                              ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 letpair_res_2334;
                                                              {
                                                                auto dsum1_fst_507 { std::get<0>(dsum1_506) };
                                                                auto dsum1_snd_508 { std::get<1>(dsum1_506) };
                                                                uint16_t id_2335 { 0 };
                                                                bool id_2336 { bool(id_2335 == dsum1_fst_507) };
                                                                ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 choose_res_2337;
                                                                if (id_2336) {
                                                                  (void)VOID;
                                                                  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2338 { std::in_place_index<0>, VOID };
                                                                  ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 id_2339 { id_2338, dsum1_snd_508 };
                                                                  choose_res_2337 = id_2339;
                                                                } else {
                                                                  uint16_t id_2340 { 1 };
                                                                  bool id_2341 { bool(id_2340 == dsum1_fst_507) };
                                                                  ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 choose_res_2342;
                                                                  if (id_2341) {
                                                                    (void)VOID;
                                                                    ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2343 { std::in_place_index<1>, VOID };
                                                                    ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 id_2344 { id_2343, dsum1_snd_508 };
                                                                    choose_res_2342 = id_2344;
                                                                  } else {
                                                                    uint16_t id_2345 { 2 };
                                                                    bool id_2346 { bool(id_2345 == dsum1_fst_507) };
                                                                    ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 choose_res_2347;
                                                                    if (id_2346) {
                                                                      (void)VOID;
                                                                      ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2348 { std::in_place_index<2>, VOID };
                                                                      ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 id_2349 { id_2348, dsum1_snd_508 };
                                                                      choose_res_2347 = id_2349;
                                                                    } else {
                                                                      uint16_t id_2350 { 3 };
                                                                      bool id_2351 { bool(id_2350 == dsum1_fst_507) };
                                                                      ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 choose_res_2352;
                                                                      if (id_2351) {
                                                                        (void)VOID;
                                                                        ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2353 { std::in_place_index<3>, VOID };
                                                                        ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 id_2354 { id_2353, dsum1_snd_508 };
                                                                        choose_res_2352 = id_2354;
                                                                      } else {
                                                                        uint16_t id_2355 { 4 };
                                                                        bool id_2356 { bool(id_2355 == dsum1_fst_507) };
                                                                        ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 choose_res_2357;
                                                                        if (id_2356) {
                                                                          (void)VOID;
                                                                          ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2358 { std::in_place_index<4>, VOID };
                                                                          ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 id_2359 { id_2358, dsum1_snd_508 };
                                                                          choose_res_2357 = id_2359;
                                                                        } else {
                                                                          uint16_t id_2360 { 5 };
                                                                          bool id_2361 { bool(id_2360 == dsum1_fst_507) };
                                                                          ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 choose_res_2362;
                                                                          if (id_2361) {
                                                                            (void)VOID;
                                                                            ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2363 { std::in_place_index<5>, VOID };
                                                                            ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 id_2364 { id_2363, dsum1_snd_508 };
                                                                            choose_res_2362 = id_2364;
                                                                          } else {
                                                                            uint16_t id_2365 { 6 };
                                                                            bool id_2366 { bool(id_2365 == dsum1_fst_507) };
                                                                            ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 choose_res_2367;
                                                                            if (id_2366) {
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2368 { std::in_place_index<6>, VOID };
                                                                              ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 id_2369 { id_2368, dsum1_snd_508 };
                                                                              choose_res_2367 = id_2369;
                                                                            } else {
                                                                              uint16_t id_2370 { 7 };
                                                                              bool id_2371 { bool(dsum1_fst_507 == id_2370) };
                                                                              Void id_2372 { ((void)(assert(id_2371)), VOID) };
                                                                              (void)id_2372;
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2373 { std::in_place_index<7>, VOID };
                                                                              ::dessser::gen::sync_key::t37be669ae311fab16260f09e977da9b5 id_2374 { id_2373, dsum1_snd_508 };
                                                                              choose_res_2367 = id_2374;
                                                                            }
                                                                            choose_res_2362 = choose_res_2367;
                                                                          }
                                                                          choose_res_2357 = choose_res_2362;
                                                                        }
                                                                        choose_res_2352 = choose_res_2357;
                                                                      }
                                                                      choose_res_2347 = choose_res_2352;
                                                                    }
                                                                    choose_res_2342 = choose_res_2347;
                                                                  }
                                                                  choose_res_2337 = choose_res_2342;
                                                                }
                                                                letpair_res_2334 = choose_res_2337;
                                                              }
                                                              let_res_2333 = letpair_res_2334;
                                                            }
                                                            ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 letpair_res_2375;
                                                            {
                                                              auto dtup_fst_534 { std::get<0>(let_res_2333) };
                                                              auto dtup_snd_535 { std::get<1>(let_res_2333) };
                                                              ::dessser::gen::sync_key::t1ad3e248018f4f9e0c3083920c2150a2 id_2376 { dtup_fst_498, dtup_fst_534 };
                                                              ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_2377 { std::in_place_index<6>, id_2376 };
                                                              ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 id_2378 { id_2377, dtup_snd_535 };
                                                              letpair_res_2375 = id_2378;
                                                            }
                                                            letpair_res_2329 = letpair_res_2375;
                                                          }
                                                          let_res_2328 = letpair_res_2329;
                                                        }
                                                        choose_res_2280 = let_res_2328;
                                                      } else {
                                                        uint16_t id_2379 { 7 };
                                                        bool id_2380 { bool(id_2379 == dsum1_fst_474) };
                                                        ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 choose_res_2381;
                                                        if (id_2380) {
                                                          ::dessser::gen::sync_key::t405eb186408556fed8f2c41523c07d13 id_2382 { dsum1_snd_475.readU32Le() };
                                                          ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 letpair_res_2383;
                                                          {
                                                            auto du32_fst_480 { std::get<0>(id_2382) };
                                                            auto du32_snd_481 { std::get<1>(id_2382) };
                                                            ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_2384 { std::in_place_index<7>, du32_fst_480 };
                                                            ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 id_2385 { id_2384, du32_snd_481 };
                                                            letpair_res_2383 = id_2385;
                                                          }
                                                          choose_res_2381 = letpair_res_2383;
                                                        } else {
                                                          uint16_t id_2386 { 8 };
                                                          bool id_2387 { bool(dsum1_fst_474 == id_2386) };
                                                          Void id_2388 { ((void)(assert(id_2387)), VOID) };
                                                          (void)id_2388;
                                                          (void)VOID;
                                                          ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350 id_2389 { std::in_place_index<8>, VOID };
                                                          ::dessser::gen::sync_key::t41af8d053a5950cc10ed03d1b4f40e29 id_2390 { id_2389, dsum1_snd_475 };
                                                          choose_res_2381 = id_2390;
                                                        }
                                                        choose_res_2280 = choose_res_2381;
                                                      }
                                                      choose_res_2275 = choose_res_2280;
                                                    }
                                                    choose_res_2270 = choose_res_2275;
                                                  }
                                                  choose_res_2265 = choose_res_2270;
                                                }
                                                choose_res_2260 = choose_res_2265;
                                              }
                                              choose_res_2255 = choose_res_2260;
                                            }
                                            choose_res_2250 = choose_res_2255;
                                          }
                                          letpair_res_2247 = choose_res_2250;
                                        }
                                        let_res_2246 = letpair_res_2247;
                                      }
                                      ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e letpair_res_2391;
                                      {
                                        auto dtup_fst_558 { std::get<0>(let_res_2246) };
                                        auto dtup_snd_559 { std::get<1>(let_res_2246) };
                                        ::dessser::gen::sync_key::t4ead4b84ceaa6e65cf560142db29b99b id_2392 { dtup_fst_465, dtup_fst_558 };
                                        ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_2393 { std::in_place_index<2>, id_2392 };
                                        ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e id_2394 { id_2393, dtup_snd_559 };
                                        letpair_res_2391 = id_2394;
                                      }
                                      letpair_res_2242 = letpair_res_2391;
                                    }
                                    let_res_2241 = letpair_res_2242;
                                  }
                                  choose_res_2238 = let_res_2241;
                                } else {
                                  uint16_t id_2395 { 3 };
                                  bool id_2396 { bool(dsum1_fst_429 == id_2395) };
                                  Void id_2397 { ((void)(assert(id_2396)), VOID) };
                                  (void)id_2397;
                                  uint32_t id_2398 { 0U };
                                  Vec<1, uint32_t> id_2399 {  id_2398  };
                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2400;
                                  {
                                    Vec<1, uint32_t> leb_ref_431 { id_2399 };
                                    uint8_t id_2401 { 0 };
                                    Vec<1, uint8_t> id_2402 {  id_2401  };
                                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2403;
                                    {
                                      Vec<1, uint8_t> shft_ref_432 { id_2402 };
                                      Vec<1, Pointer> id_2404 {  dsum1_snd_430  };
                                      ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2405;
                                      {
                                        Vec<1, Pointer> p_ref_433 { id_2404 };
                                        bool while_flag_2406 { true };
                                        do {
                                          uint8_t id_2407 { 0 };
                                          Pointer id_2408 { p_ref_433[id_2407] };
                                          ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2409 { id_2408.readU8() };
                                          bool let_res_2410;
                                          {
                                            ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_434 { id_2409 };
                                            bool letpair_res_2411;
                                            {
                                              auto leb128_fst_435 { std::get<0>(leb128_434) };
                                              auto leb128_snd_436 { std::get<1>(leb128_434) };
                                              uint8_t id_2412 { 0 };
                                              Void id_2413 { ((void)(p_ref_433[id_2412] = leb128_snd_436), VOID) };
                                              (void)id_2413;
                                              uint8_t id_2414 { 0 };
                                              uint8_t id_2415 { 127 };
                                              uint8_t id_2416 { uint8_t(leb128_fst_435 & id_2415) };
                                              uint32_t id_2417 { uint32_t(id_2416) };
                                              uint8_t id_2418 { 0 };
                                              uint8_t id_2419 { shft_ref_432[id_2418] };
                                              uint32_t id_2420 { uint32_t(id_2417 << id_2419) };
                                              uint8_t id_2421 { 0 };
                                              uint32_t id_2422 { leb_ref_431[id_2421] };
                                              uint32_t id_2423 { uint32_t(id_2420 | id_2422) };
                                              Void id_2424 { ((void)(leb_ref_431[id_2414] = id_2423), VOID) };
                                              (void)id_2424;
                                              uint8_t id_2425 { 0 };
                                              uint8_t id_2426 { 0 };
                                              uint8_t id_2427 { shft_ref_432[id_2426] };
                                              uint8_t id_2428 { 7 };
                                              uint8_t id_2429 { uint8_t(id_2427 + id_2428) };
                                              Void id_2430 { ((void)(shft_ref_432[id_2425] = id_2429), VOID) };
                                              (void)id_2430;
                                              uint8_t id_2431 { 128 };
                                              bool id_2432 { bool(leb128_fst_435 >= id_2431) };
                                              letpair_res_2411 = id_2432;
                                            }
                                            let_res_2410 = letpair_res_2411;
                                          }
                                          while_flag_2406 = let_res_2410;
                                          if (while_flag_2406) {
                                            (void)VOID;
                                          }
                                        } while (while_flag_2406);
                                        (void)VOID;
                                        uint8_t id_2433 { 0 };
                                        uint32_t id_2434 { leb_ref_431[id_2433] };
                                        Size id_2435 { Size(id_2434) };
                                        uint8_t id_2436 { 0 };
                                        Pointer id_2437 { p_ref_433[id_2436] };
                                        ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2438 { id_2435, id_2437 };
                                        let_res_2405 = id_2438;
                                      }
                                      let_res_2403 = let_res_2405;
                                    }
                                    let_res_2400 = let_res_2403;
                                  }
                                  ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e let_res_2439;
                                  {
                                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_437 { let_res_2400 };
                                    ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2440;
                                    {
                                      auto dstring1_fst_438 { std::get<0>(dstring1_437) };
                                      auto dstring1_snd_439 { std::get<1>(dstring1_437) };
                                      ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2441 { dstring1_snd_439.readBytes(dstring1_fst_438) };
                                      ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2442;
                                      {
                                        auto dstring2_fst_441 { std::get<0>(id_2441) };
                                        auto dstring2_snd_442 { std::get<1>(id_2441) };
                                        std::string id_2443 { dstring2_fst_441.toString() };
                                        ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e id_2444 { id_2443, dstring2_snd_442 };
                                        letpair_res_2442 = id_2444;
                                      }
                                      letpair_res_2440 = letpair_res_2442;
                                    }
                                    let_res_2439 = letpair_res_2440;
                                  }
                                  ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e let_res_2445;
                                  {
                                    ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e dtup_443 { let_res_2439 };
                                    ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e letpair_res_2446;
                                    {
                                      auto dtup_fst_444 { std::get<0>(dtup_443) };
                                      auto dtup_snd_445 { std::get<1>(dtup_443) };
                                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2447 { dtup_snd_445.readU16Le() };
                                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2448;
                                      {
                                        auto du16_fst_447 { std::get<0>(id_2447) };
                                        auto du16_snd_448 { std::get<1>(id_2447) };
                                        ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2449 { du16_fst_447, du16_snd_448 };
                                        letpair_res_2448 = id_2449;
                                      }
                                      ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e let_res_2450;
                                      {
                                        ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_452 { letpair_res_2448 };
                                        ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e letpair_res_2451;
                                        {
                                          auto dsum1_fst_453 { std::get<0>(dsum1_452) };
                                          auto dsum1_snd_454 { std::get<1>(dsum1_452) };
                                          uint16_t id_2452 { 0 };
                                          bool id_2453 { bool(dsum1_fst_453 == id_2452) };
                                          Void id_2454 { ((void)(assert(id_2453)), VOID) };
                                          (void)id_2454;
                                          (void)VOID;
                                          ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_2455 { std::in_place_index<0>, VOID };
                                          ::dessser::gen::sync_key::tb761ebb9c7c72cccd366042890abdac8 id_2456 { dtup_fst_444, id_2455 };
                                          ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9 id_2457 { std::in_place_index<3>, id_2456 };
                                          ::dessser::gen::sync_key::tf093c02358b6fb2e811baa5e54812a8e id_2458 { id_2457, dsum1_snd_454 };
                                          letpair_res_2451 = id_2458;
                                        }
                                        let_res_2450 = letpair_res_2451;
                                      }
                                      letpair_res_2446 = let_res_2450;
                                    }
                                    let_res_2445 = letpair_res_2446;
                                  }
                                  choose_res_2238 = let_res_2445;
                                }
                                choose_res_2167 = choose_res_2238;
                              }
                              choose_res_2162 = choose_res_2167;
                            }
                            letpair_res_2159 = choose_res_2162;
                          }
                          let_res_2158 = letpair_res_2159;
                        }
                        ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2459;
                        {
                          auto dtup_fst_603 { std::get<0>(let_res_2158) };
                          auto dtup_snd_604 { std::get<1>(let_res_2158) };
                          ::dessser::gen::sync_key::td1b9e7ba6416a29dd2501cb424913fb2 id_2460 { dtup_fst_420, dtup_fst_603 };
                          ::dessser::gen::sync_key::t* id_2461 { new ::dessser::gen::sync_key::t(std::in_place_index<5>, id_2460) };
                          ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2462 { id_2461, dtup_snd_604 };
                          letpair_res_2459 = id_2462;
                        }
                        letpair_res_2154 = letpair_res_2459;
                      }
                      let_res_2153 = letpair_res_2154;
                    }
                    choose_res_2150 = let_res_2153;
                  } else {
                    uint16_t id_2463 { 6 };
                    bool id_2464 { bool(id_2463 == dsum1_fst_81) };
                    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2465;
                    if (id_2464) {
                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2466 { dsum1_snd_82.readU16Le() };
                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2467;
                      {
                        auto du16_fst_387 { std::get<0>(id_2466) };
                        auto du16_snd_388 { std::get<1>(id_2466) };
                        ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2468 { du16_fst_387, du16_snd_388 };
                        letpair_res_2467 = id_2468;
                      }
                      ::dessser::gen::sync_key::te62cbea9c501cbe12525ca38267c2513 let_res_2469;
                      {
                        ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_392 { letpair_res_2467 };
                        ::dessser::gen::sync_key::te62cbea9c501cbe12525ca38267c2513 letpair_res_2470;
                        {
                          auto dsum1_fst_393 { std::get<0>(dsum1_392) };
                          auto dsum1_snd_394 { std::get<1>(dsum1_392) };
                          uint16_t id_2471 { 0 };
                          bool id_2472 { bool(id_2471 == dsum1_fst_393) };
                          ::dessser::gen::sync_key::te62cbea9c501cbe12525ca38267c2513 choose_res_2473;
                          if (id_2472) {
                            (void)VOID;
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2474 { std::in_place_index<0>, VOID };
                            ::dessser::gen::sync_key::te62cbea9c501cbe12525ca38267c2513 id_2475 { id_2474, dsum1_snd_394 };
                            choose_res_2473 = id_2475;
                          } else {
                            uint16_t id_2476 { 1 };
                            bool id_2477 { bool(id_2476 == dsum1_fst_393) };
                            ::dessser::gen::sync_key::te62cbea9c501cbe12525ca38267c2513 choose_res_2478;
                            if (id_2477) {
                              (void)VOID;
                              ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2479 { std::in_place_index<1>, VOID };
                              ::dessser::gen::sync_key::te62cbea9c501cbe12525ca38267c2513 id_2480 { id_2479, dsum1_snd_394 };
                              choose_res_2478 = id_2480;
                            } else {
                              uint16_t id_2481 { 2 };
                              bool id_2482 { bool(dsum1_fst_393 == id_2481) };
                              Void id_2483 { ((void)(assert(id_2482)), VOID) };
                              (void)id_2483;
                              uint32_t id_2484 { 0U };
                              Vec<1, uint32_t> id_2485 {  id_2484  };
                              ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2486;
                              {
                                Vec<1, uint32_t> leb_ref_395 { id_2485 };
                                uint8_t id_2487 { 0 };
                                Vec<1, uint8_t> id_2488 {  id_2487  };
                                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2489;
                                {
                                  Vec<1, uint8_t> shft_ref_396 { id_2488 };
                                  Vec<1, Pointer> id_2490 {  dsum1_snd_394  };
                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2491;
                                  {
                                    Vec<1, Pointer> p_ref_397 { id_2490 };
                                    bool while_flag_2492 { true };
                                    do {
                                      uint8_t id_2493 { 0 };
                                      Pointer id_2494 { p_ref_397[id_2493] };
                                      ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2495 { id_2494.readU8() };
                                      bool let_res_2496;
                                      {
                                        ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_398 { id_2495 };
                                        bool letpair_res_2497;
                                        {
                                          auto leb128_fst_399 { std::get<0>(leb128_398) };
                                          auto leb128_snd_400 { std::get<1>(leb128_398) };
                                          uint8_t id_2498 { 0 };
                                          Void id_2499 { ((void)(p_ref_397[id_2498] = leb128_snd_400), VOID) };
                                          (void)id_2499;
                                          uint8_t id_2500 { 0 };
                                          uint8_t id_2501 { 127 };
                                          uint8_t id_2502 { uint8_t(leb128_fst_399 & id_2501) };
                                          uint32_t id_2503 { uint32_t(id_2502) };
                                          uint8_t id_2504 { 0 };
                                          uint8_t id_2505 { shft_ref_396[id_2504] };
                                          uint32_t id_2506 { uint32_t(id_2503 << id_2505) };
                                          uint8_t id_2507 { 0 };
                                          uint32_t id_2508 { leb_ref_395[id_2507] };
                                          uint32_t id_2509 { uint32_t(id_2506 | id_2508) };
                                          Void id_2510 { ((void)(leb_ref_395[id_2500] = id_2509), VOID) };
                                          (void)id_2510;
                                          uint8_t id_2511 { 0 };
                                          uint8_t id_2512 { 0 };
                                          uint8_t id_2513 { shft_ref_396[id_2512] };
                                          uint8_t id_2514 { 7 };
                                          uint8_t id_2515 { uint8_t(id_2513 + id_2514) };
                                          Void id_2516 { ((void)(shft_ref_396[id_2511] = id_2515), VOID) };
                                          (void)id_2516;
                                          uint8_t id_2517 { 128 };
                                          bool id_2518 { bool(leb128_fst_399 >= id_2517) };
                                          letpair_res_2497 = id_2518;
                                        }
                                        let_res_2496 = letpair_res_2497;
                                      }
                                      while_flag_2492 = let_res_2496;
                                      if (while_flag_2492) {
                                        (void)VOID;
                                      }
                                    } while (while_flag_2492);
                                    (void)VOID;
                                    uint8_t id_2519 { 0 };
                                    uint32_t id_2520 { leb_ref_395[id_2519] };
                                    Size id_2521 { Size(id_2520) };
                                    uint8_t id_2522 { 0 };
                                    Pointer id_2523 { p_ref_397[id_2522] };
                                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2524 { id_2521, id_2523 };
                                    let_res_2491 = id_2524;
                                  }
                                  let_res_2489 = let_res_2491;
                                }
                                let_res_2486 = let_res_2489;
                              }
                              ::dessser::gen::sync_key::te62cbea9c501cbe12525ca38267c2513 let_res_2525;
                              {
                                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_401 { let_res_2486 };
                                ::dessser::gen::sync_key::te62cbea9c501cbe12525ca38267c2513 letpair_res_2526;
                                {
                                  auto dstring1_fst_402 { std::get<0>(dstring1_401) };
                                  auto dstring1_snd_403 { std::get<1>(dstring1_401) };
                                  ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2527 { dstring1_snd_403.readBytes(dstring1_fst_402) };
                                  ::dessser::gen::sync_key::te62cbea9c501cbe12525ca38267c2513 letpair_res_2528;
                                  {
                                    auto dstring2_fst_405 { std::get<0>(id_2527) };
                                    auto dstring2_snd_406 { std::get<1>(id_2527) };
                                    std::string id_2529 { dstring2_fst_405.toString() };
                                    ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2530 { std::in_place_index<2>, id_2529 };
                                    ::dessser::gen::sync_key::te62cbea9c501cbe12525ca38267c2513 id_2531 { id_2530, dstring2_snd_406 };
                                    letpair_res_2528 = id_2531;
                                  }
                                  letpair_res_2526 = letpair_res_2528;
                                }
                                let_res_2525 = letpair_res_2526;
                              }
                              choose_res_2478 = let_res_2525;
                            }
                            choose_res_2473 = choose_res_2478;
                          }
                          letpair_res_2470 = choose_res_2473;
                        }
                        let_res_2469 = letpair_res_2470;
                      }
                      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2532;
                      {
                        auto dsum2_fst_417 { std::get<0>(let_res_2469) };
                        auto dsum2_snd_418 { std::get<1>(let_res_2469) };
                        ::dessser::gen::sync_key::t* id_2533 { new ::dessser::gen::sync_key::t(std::in_place_index<6>, dsum2_fst_417) };
                        ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2534 { id_2533, dsum2_snd_418 };
                        letpair_res_2532 = id_2534;
                      }
                      choose_res_2465 = letpair_res_2532;
                    } else {
                      uint16_t id_2535 { 7 };
                      bool id_2536 { bool(id_2535 == dsum1_fst_81) };
                      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2537;
                      if (id_2536) {
                        auto fun2538 { dessser::gen::site_name::of_row_binary };
                        ::dessser::gen::sync_key::tb31a43e42345099d489759a9c141b1b9 id_2539 { fun2538(dsum1_snd_82) };
                        ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2540;
                        {
                          ::dessser::gen::sync_key::tb31a43e42345099d489759a9c141b1b9 dtup_329 { id_2539 };
                          ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2541;
                          {
                            auto dtup_fst_330 { std::get<0>(dtup_329) };
                            auto dtup_snd_331 { std::get<1>(dtup_329) };
                            auto fun2542 { dessser::gen::fq_name::of_row_binary };
                            ::dessser::gen::sync_key::td8eaddfacf232bd15ab91a5778e12a3b id_2543 { fun2542(dtup_snd_331) };
                            ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2544;
                            {
                              ::dessser::gen::sync_key::td8eaddfacf232bd15ab91a5778e12a3b dtup_332 { id_2543 };
                              ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2545;
                              {
                                auto dtup_fst_333 { std::get<0>(dtup_332) };
                                auto dtup_snd_334 { std::get<1>(dtup_332) };
                                uint32_t id_2546 { 0U };
                                Vec<1, uint32_t> id_2547 {  id_2546  };
                                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2548;
                                {
                                  Vec<1, uint32_t> leb_ref_335 { id_2547 };
                                  uint8_t id_2549 { 0 };
                                  Vec<1, uint8_t> id_2550 {  id_2549  };
                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2551;
                                  {
                                    Vec<1, uint8_t> shft_ref_336 { id_2550 };
                                    Vec<1, Pointer> id_2552 {  dtup_snd_334  };
                                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2553;
                                    {
                                      Vec<1, Pointer> p_ref_337 { id_2552 };
                                      bool while_flag_2554 { true };
                                      do {
                                        uint8_t id_2555 { 0 };
                                        Pointer id_2556 { p_ref_337[id_2555] };
                                        ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2557 { id_2556.readU8() };
                                        bool let_res_2558;
                                        {
                                          ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_338 { id_2557 };
                                          bool letpair_res_2559;
                                          {
                                            auto leb128_fst_339 { std::get<0>(leb128_338) };
                                            auto leb128_snd_340 { std::get<1>(leb128_338) };
                                            uint8_t id_2560 { 0 };
                                            Void id_2561 { ((void)(p_ref_337[id_2560] = leb128_snd_340), VOID) };
                                            (void)id_2561;
                                            uint8_t id_2562 { 0 };
                                            uint8_t id_2563 { 127 };
                                            uint8_t id_2564 { uint8_t(leb128_fst_339 & id_2563) };
                                            uint32_t id_2565 { uint32_t(id_2564) };
                                            uint8_t id_2566 { 0 };
                                            uint8_t id_2567 { shft_ref_336[id_2566] };
                                            uint32_t id_2568 { uint32_t(id_2565 << id_2567) };
                                            uint8_t id_2569 { 0 };
                                            uint32_t id_2570 { leb_ref_335[id_2569] };
                                            uint32_t id_2571 { uint32_t(id_2568 | id_2570) };
                                            Void id_2572 { ((void)(leb_ref_335[id_2562] = id_2571), VOID) };
                                            (void)id_2572;
                                            uint8_t id_2573 { 0 };
                                            uint8_t id_2574 { 0 };
                                            uint8_t id_2575 { shft_ref_336[id_2574] };
                                            uint8_t id_2576 { 7 };
                                            uint8_t id_2577 { uint8_t(id_2575 + id_2576) };
                                            Void id_2578 { ((void)(shft_ref_336[id_2573] = id_2577), VOID) };
                                            (void)id_2578;
                                            uint8_t id_2579 { 128 };
                                            bool id_2580 { bool(leb128_fst_339 >= id_2579) };
                                            letpair_res_2559 = id_2580;
                                          }
                                          let_res_2558 = letpair_res_2559;
                                        }
                                        while_flag_2554 = let_res_2558;
                                        if (while_flag_2554) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_2554);
                                      (void)VOID;
                                      uint8_t id_2581 { 0 };
                                      uint32_t id_2582 { leb_ref_335[id_2581] };
                                      Size id_2583 { Size(id_2582) };
                                      uint8_t id_2584 { 0 };
                                      Pointer id_2585 { p_ref_337[id_2584] };
                                      ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2586 { id_2583, id_2585 };
                                      let_res_2553 = id_2586;
                                    }
                                    let_res_2551 = let_res_2553;
                                  }
                                  let_res_2548 = let_res_2551;
                                }
                                ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e let_res_2587;
                                {
                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_341 { let_res_2548 };
                                  ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2588;
                                  {
                                    auto dstring1_fst_342 { std::get<0>(dstring1_341) };
                                    auto dstring1_snd_343 { std::get<1>(dstring1_341) };
                                    ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2589 { dstring1_snd_343.readBytes(dstring1_fst_342) };
                                    ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2590;
                                    {
                                      auto dstring2_fst_345 { std::get<0>(id_2589) };
                                      auto dstring2_snd_346 { std::get<1>(id_2589) };
                                      std::string id_2591 { dstring2_fst_345.toString() };
                                      ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e id_2592 { id_2591, dstring2_snd_346 };
                                      letpair_res_2590 = id_2592;
                                    }
                                    letpair_res_2588 = letpair_res_2590;
                                  }
                                  let_res_2587 = letpair_res_2588;
                                }
                                ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2593;
                                {
                                  ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e dtup_347 { let_res_2587 };
                                  ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2594;
                                  {
                                    auto dtup_fst_348 { std::get<0>(dtup_347) };
                                    auto dtup_snd_349 { std::get<1>(dtup_347) };
                                    ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2595 { dtup_snd_349.readU16Le() };
                                    ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2596;
                                    {
                                      auto du16_fst_351 { std::get<0>(id_2595) };
                                      auto du16_snd_352 { std::get<1>(id_2595) };
                                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2597 { du16_fst_351, du16_snd_352 };
                                      letpair_res_2596 = id_2597;
                                    }
                                    ::dessser::gen::sync_key::t25f8accbaed2398ac12a9768d2538e0b let_res_2598;
                                    {
                                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_356 { letpair_res_2596 };
                                      ::dessser::gen::sync_key::t25f8accbaed2398ac12a9768d2538e0b letpair_res_2599;
                                      {
                                        auto dsum1_fst_357 { std::get<0>(dsum1_356) };
                                        auto dsum1_snd_358 { std::get<1>(dsum1_356) };
                                        uint16_t id_2600 { 0 };
                                        bool id_2601 { bool(id_2600 == dsum1_fst_357) };
                                        ::dessser::gen::sync_key::t25f8accbaed2398ac12a9768d2538e0b choose_res_2602;
                                        if (id_2601) {
                                          uint32_t id_2603 { 0U };
                                          Vec<1, uint32_t> id_2604 {  id_2603  };
                                          ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2605;
                                          {
                                            Vec<1, uint32_t> leb_ref_365 { id_2604 };
                                            uint8_t id_2606 { 0 };
                                            Vec<1, uint8_t> id_2607 {  id_2606  };
                                            ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2608;
                                            {
                                              Vec<1, uint8_t> shft_ref_366 { id_2607 };
                                              Vec<1, Pointer> id_2609 {  dsum1_snd_358  };
                                              ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2610;
                                              {
                                                Vec<1, Pointer> p_ref_367 { id_2609 };
                                                bool while_flag_2611 { true };
                                                do {
                                                  uint8_t id_2612 { 0 };
                                                  Pointer id_2613 { p_ref_367[id_2612] };
                                                  ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2614 { id_2613.readU8() };
                                                  bool let_res_2615;
                                                  {
                                                    ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_368 { id_2614 };
                                                    bool letpair_res_2616;
                                                    {
                                                      auto leb128_fst_369 { std::get<0>(leb128_368) };
                                                      auto leb128_snd_370 { std::get<1>(leb128_368) };
                                                      uint8_t id_2617 { 0 };
                                                      Void id_2618 { ((void)(p_ref_367[id_2617] = leb128_snd_370), VOID) };
                                                      (void)id_2618;
                                                      uint8_t id_2619 { 0 };
                                                      uint8_t id_2620 { 127 };
                                                      uint8_t id_2621 { uint8_t(leb128_fst_369 & id_2620) };
                                                      uint32_t id_2622 { uint32_t(id_2621) };
                                                      uint8_t id_2623 { 0 };
                                                      uint8_t id_2624 { shft_ref_366[id_2623] };
                                                      uint32_t id_2625 { uint32_t(id_2622 << id_2624) };
                                                      uint8_t id_2626 { 0 };
                                                      uint32_t id_2627 { leb_ref_365[id_2626] };
                                                      uint32_t id_2628 { uint32_t(id_2625 | id_2627) };
                                                      Void id_2629 { ((void)(leb_ref_365[id_2619] = id_2628), VOID) };
                                                      (void)id_2629;
                                                      uint8_t id_2630 { 0 };
                                                      uint8_t id_2631 { 0 };
                                                      uint8_t id_2632 { shft_ref_366[id_2631] };
                                                      uint8_t id_2633 { 7 };
                                                      uint8_t id_2634 { uint8_t(id_2632 + id_2633) };
                                                      Void id_2635 { ((void)(shft_ref_366[id_2630] = id_2634), VOID) };
                                                      (void)id_2635;
                                                      uint8_t id_2636 { 128 };
                                                      bool id_2637 { bool(leb128_fst_369 >= id_2636) };
                                                      letpair_res_2616 = id_2637;
                                                    }
                                                    let_res_2615 = letpair_res_2616;
                                                  }
                                                  while_flag_2611 = let_res_2615;
                                                  if (while_flag_2611) {
                                                    (void)VOID;
                                                  }
                                                } while (while_flag_2611);
                                                (void)VOID;
                                                uint8_t id_2638 { 0 };
                                                uint32_t id_2639 { leb_ref_365[id_2638] };
                                                Size id_2640 { Size(id_2639) };
                                                uint8_t id_2641 { 0 };
                                                Pointer id_2642 { p_ref_367[id_2641] };
                                                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2643 { id_2640, id_2642 };
                                                let_res_2610 = id_2643;
                                              }
                                              let_res_2608 = let_res_2610;
                                            }
                                            let_res_2605 = let_res_2608;
                                          }
                                          ::dessser::gen::sync_key::t25f8accbaed2398ac12a9768d2538e0b let_res_2644;
                                          {
                                            ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_371 { let_res_2605 };
                                            ::dessser::gen::sync_key::t25f8accbaed2398ac12a9768d2538e0b letpair_res_2645;
                                            {
                                              auto dstring1_fst_372 { std::get<0>(dstring1_371) };
                                              auto dstring1_snd_373 { std::get<1>(dstring1_371) };
                                              ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2646 { dstring1_snd_373.readBytes(dstring1_fst_372) };
                                              ::dessser::gen::sync_key::t25f8accbaed2398ac12a9768d2538e0b letpair_res_2647;
                                              {
                                                auto dstring2_fst_375 { std::get<0>(id_2646) };
                                                auto dstring2_snd_376 { std::get<1>(id_2646) };
                                                std::string id_2648 { dstring2_fst_375.toString() };
                                                ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_2649 { std::in_place_index<0>, id_2648 };
                                                ::dessser::gen::sync_key::t25f8accbaed2398ac12a9768d2538e0b id_2650 { id_2649, dstring2_snd_376 };
                                                letpair_res_2647 = id_2650;
                                              }
                                              letpair_res_2645 = letpair_res_2647;
                                            }
                                            let_res_2644 = letpair_res_2645;
                                          }
                                          choose_res_2602 = let_res_2644;
                                        } else {
                                          uint16_t id_2651 { 1 };
                                          bool id_2652 { bool(dsum1_fst_357 == id_2651) };
                                          Void id_2653 { ((void)(assert(id_2652)), VOID) };
                                          (void)id_2653;
                                          ::dessser::gen::sync_key::t405eb186408556fed8f2c41523c07d13 id_2654 { dsum1_snd_358.readU32Le() };
                                          ::dessser::gen::sync_key::t25f8accbaed2398ac12a9768d2538e0b letpair_res_2655;
                                          {
                                            auto du32_fst_360 { std::get<0>(id_2654) };
                                            auto du32_snd_361 { std::get<1>(id_2654) };
                                            ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8 id_2656 { std::in_place_index<1>, du32_fst_360 };
                                            ::dessser::gen::sync_key::t25f8accbaed2398ac12a9768d2538e0b id_2657 { id_2656, du32_snd_361 };
                                            letpair_res_2655 = id_2657;
                                          }
                                          choose_res_2602 = letpair_res_2655;
                                        }
                                        letpair_res_2599 = choose_res_2602;
                                      }
                                      let_res_2598 = letpair_res_2599;
                                    }
                                    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2658;
                                    {
                                      auto dtup_fst_381 { std::get<0>(let_res_2598) };
                                      auto dtup_snd_382 { std::get<1>(let_res_2598) };
                                      ::dessser::gen::sync_key::t9d781e6e3c7478a3c57f805b8c82ba57 id_2659 { dtup_fst_330, dtup_fst_333, dtup_fst_348, dtup_fst_381 };
                                      ::dessser::gen::sync_key::t* id_2660 { new ::dessser::gen::sync_key::t(std::in_place_index<7>, id_2659) };
                                      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2661 { id_2660, dtup_snd_382 };
                                      letpair_res_2658 = id_2661;
                                    }
                                    letpair_res_2594 = letpair_res_2658;
                                  }
                                  let_res_2593 = letpair_res_2594;
                                }
                                letpair_res_2545 = let_res_2593;
                              }
                              let_res_2544 = letpair_res_2545;
                            }
                            letpair_res_2541 = let_res_2544;
                          }
                          let_res_2540 = letpair_res_2541;
                        }
                        choose_res_2537 = let_res_2540;
                      } else {
                        uint16_t id_2662 { 8 };
                        bool id_2663 { bool(id_2662 == dsum1_fst_81) };
                        ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2664;
                        if (id_2663) {
                          ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2665 { dsum1_snd_82.readU16Le() };
                          ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2666;
                          {
                            auto du16_fst_324 { std::get<0>(id_2665) };
                            auto du16_snd_325 { std::get<1>(id_2665) };
                            ::dessser::gen::sync_key::t* id_2667 { new ::dessser::gen::sync_key::t(std::in_place_index<8>, du16_fst_324) };
                            ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2668 { id_2667, du16_snd_325 };
                            letpair_res_2666 = id_2668;
                          }
                          choose_res_2664 = letpair_res_2666;
                        } else {
                          uint16_t id_2669 { 9 };
                          bool id_2670 { bool(id_2669 == dsum1_fst_81) };
                          ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2671;
                          if (id_2670) {
                            Size id_2672 { 0UL };
                            uint8_t id_2673 { dsum1_snd_82.peekU8(id_2672) };
                            uint8_t id_2674 { 1 };
                            bool id_2675 { bool(id_2673 == id_2674) };
                            ::dessser::gen::sync_key::tc830800ab3d022d92257593f4e7f18f4 choose_res_2676;
                            if (id_2675) {
                              std::optional<dessser::gen::sync_socket::t_ext> id_2677 { std::nullopt };
                              Size id_2678 { 1UL };
                              Pointer id_2679 { dsum1_snd_82.skip(id_2678) };
                              ::dessser::gen::sync_key::tc830800ab3d022d92257593f4e7f18f4 id_2680 { id_2677, id_2679 };
                              choose_res_2676 = id_2680;
                            } else {
                              auto fun2681 { dessser::gen::sync_socket::of_row_binary };
                              Size id_2682 { 1UL };
                              Pointer id_2683 { dsum1_snd_82.skip(id_2682) };
                              ::dessser::gen::sync_key::t60a438e45a4b170b9ebd75067d553051 id_2684 { fun2681(id_2683) };
                              ::dessser::gen::sync_key::tc830800ab3d022d92257593f4e7f18f4 letpair_res_2685;
                              {
                                auto make1_1_fst_318 { std::get<0>(id_2684) };
                                auto make1_1_snd_319 { std::get<1>(id_2684) };
                                std::optional<dessser::gen::sync_socket::t_ext> id_2686 { make1_1_fst_318 };
                                ::dessser::gen::sync_key::tc830800ab3d022d92257593f4e7f18f4 id_2687 { id_2686, make1_1_snd_319 };
                                letpair_res_2685 = id_2687;
                              }
                              choose_res_2676 = letpair_res_2685;
                            }
                            ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2688;
                            {
                              auto dsum2_fst_321 { std::get<0>(choose_res_2676) };
                              auto dsum2_snd_322 { std::get<1>(choose_res_2676) };
                              ::dessser::gen::sync_key::t* id_2689 { new ::dessser::gen::sync_key::t(std::in_place_index<9>, dsum2_fst_321) };
                              ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2690 { id_2689, dsum2_snd_322 };
                              letpair_res_2688 = id_2690;
                            }
                            choose_res_2671 = letpair_res_2688;
                          } else {
                            uint16_t id_2691 { 10 };
                            bool id_2692 { bool(id_2691 == dsum1_fst_81) };
                            ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2693;
                            if (id_2692) {
                              (void)VOID;
                              ::dessser::gen::sync_key::t* id_2694 { new ::dessser::gen::sync_key::t(std::in_place_index<10>, VOID) };
                              ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2695 { id_2694, dsum1_snd_82 };
                              choose_res_2693 = id_2695;
                            } else {
                              uint16_t id_2696 { 11 };
                              bool id_2697 { bool(id_2696 == dsum1_fst_81) };
                              ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2698;
                              if (id_2697) {
                                auto fun2699 { dessser::gen::sync_socket::of_row_binary };
                                ::dessser::gen::sync_key::t60a438e45a4b170b9ebd75067d553051 id_2700 { fun2699(dsum1_snd_82) };
                                ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2701;
                                {
                                  ::dessser::gen::sync_key::t60a438e45a4b170b9ebd75067d553051 dtup_278 { id_2700 };
                                  ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2702;
                                  {
                                    auto dtup_fst_279 { std::get<0>(dtup_278) };
                                    auto dtup_snd_280 { std::get<1>(dtup_278) };
                                    ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2703 { dtup_snd_280.readU16Le() };
                                    ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2704;
                                    {
                                      auto du16_fst_282 { std::get<0>(id_2703) };
                                      auto du16_snd_283 { std::get<1>(id_2703) };
                                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2705 { du16_fst_282, du16_snd_283 };
                                      letpair_res_2704 = id_2705;
                                    }
                                    ::dessser::gen::sync_key::t12bd4a5520fba716109e506b78c12b14 let_res_2706;
                                    {
                                      ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_287 { letpair_res_2704 };
                                      ::dessser::gen::sync_key::t12bd4a5520fba716109e506b78c12b14 letpair_res_2707;
                                      {
                                        auto dsum1_fst_288 { std::get<0>(dsum1_287) };
                                        auto dsum1_snd_289 { std::get<1>(dsum1_287) };
                                        uint16_t id_2708 { 0 };
                                        bool id_2709 { bool(id_2708 == dsum1_fst_288) };
                                        ::dessser::gen::sync_key::t12bd4a5520fba716109e506b78c12b14 choose_res_2710;
                                        if (id_2709) {
                                          uint32_t id_2711 { 0U };
                                          Vec<1, uint32_t> id_2712 {  id_2711  };
                                          ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2713;
                                          {
                                            Vec<1, uint32_t> leb_ref_293 { id_2712 };
                                            uint8_t id_2714 { 0 };
                                            Vec<1, uint8_t> id_2715 {  id_2714  };
                                            ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2716;
                                            {
                                              Vec<1, uint8_t> shft_ref_294 { id_2715 };
                                              Vec<1, Pointer> id_2717 {  dsum1_snd_289  };
                                              ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2718;
                                              {
                                                Vec<1, Pointer> p_ref_295 { id_2717 };
                                                bool while_flag_2719 { true };
                                                do {
                                                  uint8_t id_2720 { 0 };
                                                  Pointer id_2721 { p_ref_295[id_2720] };
                                                  ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2722 { id_2721.readU8() };
                                                  bool let_res_2723;
                                                  {
                                                    ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_296 { id_2722 };
                                                    bool letpair_res_2724;
                                                    {
                                                      auto leb128_fst_297 { std::get<0>(leb128_296) };
                                                      auto leb128_snd_298 { std::get<1>(leb128_296) };
                                                      uint8_t id_2725 { 0 };
                                                      Void id_2726 { ((void)(p_ref_295[id_2725] = leb128_snd_298), VOID) };
                                                      (void)id_2726;
                                                      uint8_t id_2727 { 0 };
                                                      uint8_t id_2728 { 127 };
                                                      uint8_t id_2729 { uint8_t(leb128_fst_297 & id_2728) };
                                                      uint32_t id_2730 { uint32_t(id_2729) };
                                                      uint8_t id_2731 { 0 };
                                                      uint8_t id_2732 { shft_ref_294[id_2731] };
                                                      uint32_t id_2733 { uint32_t(id_2730 << id_2732) };
                                                      uint8_t id_2734 { 0 };
                                                      uint32_t id_2735 { leb_ref_293[id_2734] };
                                                      uint32_t id_2736 { uint32_t(id_2733 | id_2735) };
                                                      Void id_2737 { ((void)(leb_ref_293[id_2727] = id_2736), VOID) };
                                                      (void)id_2737;
                                                      uint8_t id_2738 { 0 };
                                                      uint8_t id_2739 { 0 };
                                                      uint8_t id_2740 { shft_ref_294[id_2739] };
                                                      uint8_t id_2741 { 7 };
                                                      uint8_t id_2742 { uint8_t(id_2740 + id_2741) };
                                                      Void id_2743 { ((void)(shft_ref_294[id_2738] = id_2742), VOID) };
                                                      (void)id_2743;
                                                      uint8_t id_2744 { 128 };
                                                      bool id_2745 { bool(leb128_fst_297 >= id_2744) };
                                                      letpair_res_2724 = id_2745;
                                                    }
                                                    let_res_2723 = letpair_res_2724;
                                                  }
                                                  while_flag_2719 = let_res_2723;
                                                  if (while_flag_2719) {
                                                    (void)VOID;
                                                  }
                                                } while (while_flag_2719);
                                                (void)VOID;
                                                uint8_t id_2746 { 0 };
                                                uint32_t id_2747 { leb_ref_293[id_2746] };
                                                Size id_2748 { Size(id_2747) };
                                                uint8_t id_2749 { 0 };
                                                Pointer id_2750 { p_ref_295[id_2749] };
                                                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2751 { id_2748, id_2750 };
                                                let_res_2718 = id_2751;
                                              }
                                              let_res_2716 = let_res_2718;
                                            }
                                            let_res_2713 = let_res_2716;
                                          }
                                          ::dessser::gen::sync_key::t12bd4a5520fba716109e506b78c12b14 let_res_2752;
                                          {
                                            ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_299 { let_res_2713 };
                                            ::dessser::gen::sync_key::t12bd4a5520fba716109e506b78c12b14 letpair_res_2753;
                                            {
                                              auto dstring1_fst_300 { std::get<0>(dstring1_299) };
                                              auto dstring1_snd_301 { std::get<1>(dstring1_299) };
                                              ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2754 { dstring1_snd_301.readBytes(dstring1_fst_300) };
                                              ::dessser::gen::sync_key::t12bd4a5520fba716109e506b78c12b14 letpair_res_2755;
                                              {
                                                auto dstring2_fst_303 { std::get<0>(id_2754) };
                                                auto dstring2_snd_304 { std::get<1>(id_2754) };
                                                std::string id_2756 { dstring2_fst_303.toString() };
                                                ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_2757 { std::in_place_index<0>, id_2756 };
                                                ::dessser::gen::sync_key::t12bd4a5520fba716109e506b78c12b14 id_2758 { id_2757, dstring2_snd_304 };
                                                letpair_res_2755 = id_2758;
                                              }
                                              letpair_res_2753 = letpair_res_2755;
                                            }
                                            let_res_2752 = letpair_res_2753;
                                          }
                                          choose_res_2710 = let_res_2752;
                                        } else {
                                          uint16_t id_2759 { 1 };
                                          bool id_2760 { bool(dsum1_fst_288 == id_2759) };
                                          Void id_2761 { ((void)(assert(id_2760)), VOID) };
                                          (void)id_2761;
                                          ::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9 id_2762 { per_dash_key_of_row_binary(dsum1_snd_289) };
                                          ::dessser::gen::sync_key::t12bd4a5520fba716109e506b78c12b14 letpair_res_2763;
                                          {
                                            auto dsum2_fst_291 { std::get<0>(id_2762) };
                                            auto dsum2_snd_292 { std::get<1>(id_2762) };
                                            ::dessser::gen::sync_key::t34440d69278f78fc117a9719151dac05 id_2764 { std::in_place_index<1>, dsum2_fst_291 };
                                            ::dessser::gen::sync_key::t12bd4a5520fba716109e506b78c12b14 id_2765 { id_2764, dsum2_snd_292 };
                                            letpair_res_2763 = id_2765;
                                          }
                                          choose_res_2710 = letpair_res_2763;
                                        }
                                        letpair_res_2707 = choose_res_2710;
                                      }
                                      let_res_2706 = letpair_res_2707;
                                    }
                                    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2766;
                                    {
                                      auto dtup_fst_309 { std::get<0>(let_res_2706) };
                                      auto dtup_snd_310 { std::get<1>(let_res_2706) };
                                      ::dessser::gen::sync_key::te92b7cdb8c8cb9bcb9417c7d44e820f0 id_2767 { dtup_fst_279, dtup_fst_309 };
                                      ::dessser::gen::sync_key::t* id_2768 { new ::dessser::gen::sync_key::t(std::in_place_index<11>, id_2767) };
                                      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2769 { id_2768, dtup_snd_310 };
                                      letpair_res_2766 = id_2769;
                                    }
                                    letpair_res_2702 = letpair_res_2766;
                                  }
                                  let_res_2701 = letpair_res_2702;
                                }
                                choose_res_2698 = let_res_2701;
                              } else {
                                uint16_t id_2770 { 12 };
                                bool id_2771 { bool(id_2770 == dsum1_fst_81) };
                                ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2772;
                                if (id_2771) {
                                  uint32_t id_2773 { 0U };
                                  Vec<1, uint32_t> id_2774 {  id_2773  };
                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2775;
                                  {
                                    Vec<1, uint32_t> leb_ref_257 { id_2774 };
                                    uint8_t id_2776 { 0 };
                                    Vec<1, uint8_t> id_2777 {  id_2776  };
                                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2778;
                                    {
                                      Vec<1, uint8_t> shft_ref_258 { id_2777 };
                                      Vec<1, Pointer> id_2779 {  dsum1_snd_82  };
                                      ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2780;
                                      {
                                        Vec<1, Pointer> p_ref_259 { id_2779 };
                                        bool while_flag_2781 { true };
                                        do {
                                          uint8_t id_2782 { 0 };
                                          Pointer id_2783 { p_ref_259[id_2782] };
                                          ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2784 { id_2783.readU8() };
                                          bool let_res_2785;
                                          {
                                            ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_260 { id_2784 };
                                            bool letpair_res_2786;
                                            {
                                              auto leb128_fst_261 { std::get<0>(leb128_260) };
                                              auto leb128_snd_262 { std::get<1>(leb128_260) };
                                              uint8_t id_2787 { 0 };
                                              Void id_2788 { ((void)(p_ref_259[id_2787] = leb128_snd_262), VOID) };
                                              (void)id_2788;
                                              uint8_t id_2789 { 0 };
                                              uint8_t id_2790 { 127 };
                                              uint8_t id_2791 { uint8_t(leb128_fst_261 & id_2790) };
                                              uint32_t id_2792 { uint32_t(id_2791) };
                                              uint8_t id_2793 { 0 };
                                              uint8_t id_2794 { shft_ref_258[id_2793] };
                                              uint32_t id_2795 { uint32_t(id_2792 << id_2794) };
                                              uint8_t id_2796 { 0 };
                                              uint32_t id_2797 { leb_ref_257[id_2796] };
                                              uint32_t id_2798 { uint32_t(id_2795 | id_2797) };
                                              Void id_2799 { ((void)(leb_ref_257[id_2789] = id_2798), VOID) };
                                              (void)id_2799;
                                              uint8_t id_2800 { 0 };
                                              uint8_t id_2801 { 0 };
                                              uint8_t id_2802 { shft_ref_258[id_2801] };
                                              uint8_t id_2803 { 7 };
                                              uint8_t id_2804 { uint8_t(id_2802 + id_2803) };
                                              Void id_2805 { ((void)(shft_ref_258[id_2800] = id_2804), VOID) };
                                              (void)id_2805;
                                              uint8_t id_2806 { 128 };
                                              bool id_2807 { bool(leb128_fst_261 >= id_2806) };
                                              letpair_res_2786 = id_2807;
                                            }
                                            let_res_2785 = letpair_res_2786;
                                          }
                                          while_flag_2781 = let_res_2785;
                                          if (while_flag_2781) {
                                            (void)VOID;
                                          }
                                        } while (while_flag_2781);
                                        (void)VOID;
                                        uint8_t id_2808 { 0 };
                                        uint32_t id_2809 { leb_ref_257[id_2808] };
                                        Size id_2810 { Size(id_2809) };
                                        uint8_t id_2811 { 0 };
                                        Pointer id_2812 { p_ref_259[id_2811] };
                                        ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2813 { id_2810, id_2812 };
                                        let_res_2780 = id_2813;
                                      }
                                      let_res_2778 = let_res_2780;
                                    }
                                    let_res_2775 = let_res_2778;
                                  }
                                  ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e let_res_2814;
                                  {
                                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_263 { let_res_2775 };
                                    ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2815;
                                    {
                                      auto dstring1_fst_264 { std::get<0>(dstring1_263) };
                                      auto dstring1_snd_265 { std::get<1>(dstring1_263) };
                                      ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2816 { dstring1_snd_265.readBytes(dstring1_fst_264) };
                                      ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2817;
                                      {
                                        auto dstring2_fst_267 { std::get<0>(id_2816) };
                                        auto dstring2_snd_268 { std::get<1>(id_2816) };
                                        std::string id_2818 { dstring2_fst_267.toString() };
                                        ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e id_2819 { id_2818, dstring2_snd_268 };
                                        letpair_res_2817 = id_2819;
                                      }
                                      letpair_res_2815 = letpair_res_2817;
                                    }
                                    let_res_2814 = letpair_res_2815;
                                  }
                                  ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2820;
                                  {
                                    ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e dtup_269 { let_res_2814 };
                                    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2821;
                                    {
                                      auto dtup_fst_270 { std::get<0>(dtup_269) };
                                      auto dtup_snd_271 { std::get<1>(dtup_269) };
                                      ::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9 id_2822 { per_dash_key_of_row_binary(dtup_snd_271) };
                                      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2823;
                                      {
                                        auto dtup_fst_273 { std::get<0>(id_2822) };
                                        auto dtup_snd_274 { std::get<1>(id_2822) };
                                        ::dessser::gen::sync_key::taedf2e3441a6137271066ee57c3c4d25 id_2824 { dtup_fst_270, dtup_fst_273 };
                                        ::dessser::gen::sync_key::t* id_2825 { new ::dessser::gen::sync_key::t(std::in_place_index<12>, id_2824) };
                                        ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2826 { id_2825, dtup_snd_274 };
                                        letpair_res_2823 = id_2826;
                                      }
                                      letpair_res_2821 = letpair_res_2823;
                                    }
                                    let_res_2820 = letpair_res_2821;
                                  }
                                  choose_res_2772 = let_res_2820;
                                } else {
                                  uint16_t id_2827 { 13 };
                                  bool id_2828 { bool(id_2827 == dsum1_fst_81) };
                                  ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2829;
                                  if (id_2828) {
                                    (void)VOID;
                                    ::dessser::gen::sync_key::t* id_2830 { new ::dessser::gen::sync_key::t(std::in_place_index<13>, VOID) };
                                    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2831 { id_2830, dsum1_snd_82 };
                                    choose_res_2829 = id_2831;
                                  } else {
                                    uint16_t id_2832 { 14 };
                                    bool id_2833 { bool(id_2832 == dsum1_fst_81) };
                                    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d choose_res_2834;
                                    if (id_2833) {
                                      uint32_t id_2835 { 0U };
                                      Vec<1, uint32_t> id_2836 {  id_2835  };
                                      ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2837;
                                      {
                                        Vec<1, uint32_t> leb_ref_194 { id_2836 };
                                        uint8_t id_2838 { 0 };
                                        Vec<1, uint8_t> id_2839 {  id_2838  };
                                        ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2840;
                                        {
                                          Vec<1, uint8_t> shft_ref_195 { id_2839 };
                                          Vec<1, Pointer> id_2841 {  dsum1_snd_82  };
                                          ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2842;
                                          {
                                            Vec<1, Pointer> p_ref_196 { id_2841 };
                                            bool while_flag_2843 { true };
                                            do {
                                              uint8_t id_2844 { 0 };
                                              Pointer id_2845 { p_ref_196[id_2844] };
                                              ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2846 { id_2845.readU8() };
                                              bool let_res_2847;
                                              {
                                                ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_197 { id_2846 };
                                                bool letpair_res_2848;
                                                {
                                                  auto leb128_fst_198 { std::get<0>(leb128_197) };
                                                  auto leb128_snd_199 { std::get<1>(leb128_197) };
                                                  uint8_t id_2849 { 0 };
                                                  Void id_2850 { ((void)(p_ref_196[id_2849] = leb128_snd_199), VOID) };
                                                  (void)id_2850;
                                                  uint8_t id_2851 { 0 };
                                                  uint8_t id_2852 { 127 };
                                                  uint8_t id_2853 { uint8_t(leb128_fst_198 & id_2852) };
                                                  uint32_t id_2854 { uint32_t(id_2853) };
                                                  uint8_t id_2855 { 0 };
                                                  uint8_t id_2856 { shft_ref_195[id_2855] };
                                                  uint32_t id_2857 { uint32_t(id_2854 << id_2856) };
                                                  uint8_t id_2858 { 0 };
                                                  uint32_t id_2859 { leb_ref_194[id_2858] };
                                                  uint32_t id_2860 { uint32_t(id_2857 | id_2859) };
                                                  Void id_2861 { ((void)(leb_ref_194[id_2851] = id_2860), VOID) };
                                                  (void)id_2861;
                                                  uint8_t id_2862 { 0 };
                                                  uint8_t id_2863 { 0 };
                                                  uint8_t id_2864 { shft_ref_195[id_2863] };
                                                  uint8_t id_2865 { 7 };
                                                  uint8_t id_2866 { uint8_t(id_2864 + id_2865) };
                                                  Void id_2867 { ((void)(shft_ref_195[id_2862] = id_2866), VOID) };
                                                  (void)id_2867;
                                                  uint8_t id_2868 { 128 };
                                                  bool id_2869 { bool(leb128_fst_198 >= id_2868) };
                                                  letpair_res_2848 = id_2869;
                                                }
                                                let_res_2847 = letpair_res_2848;
                                              }
                                              while_flag_2843 = let_res_2847;
                                              if (while_flag_2843) {
                                                (void)VOID;
                                              }
                                            } while (while_flag_2843);
                                            (void)VOID;
                                            uint8_t id_2870 { 0 };
                                            uint32_t id_2871 { leb_ref_194[id_2870] };
                                            Size id_2872 { Size(id_2871) };
                                            uint8_t id_2873 { 0 };
                                            Pointer id_2874 { p_ref_196[id_2873] };
                                            ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2875 { id_2872, id_2874 };
                                            let_res_2842 = id_2875;
                                          }
                                          let_res_2840 = let_res_2842;
                                        }
                                        let_res_2837 = let_res_2840;
                                      }
                                      ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e let_res_2876;
                                      {
                                        ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_200 { let_res_2837 };
                                        ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2877;
                                        {
                                          auto dstring1_fst_201 { std::get<0>(dstring1_200) };
                                          auto dstring1_snd_202 { std::get<1>(dstring1_200) };
                                          ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2878 { dstring1_snd_202.readBytes(dstring1_fst_201) };
                                          ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_2879;
                                          {
                                            auto dstring2_fst_204 { std::get<0>(id_2878) };
                                            auto dstring2_snd_205 { std::get<1>(id_2878) };
                                            std::string id_2880 { dstring2_fst_204.toString() };
                                            ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e id_2881 { id_2880, dstring2_snd_205 };
                                            letpair_res_2879 = id_2881;
                                          }
                                          letpair_res_2877 = letpair_res_2879;
                                        }
                                        let_res_2876 = letpair_res_2877;
                                      }
                                      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_2882;
                                      {
                                        ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e dtup_206 { let_res_2876 };
                                        ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2883;
                                        {
                                          auto dtup_fst_207 { std::get<0>(dtup_206) };
                                          auto dtup_snd_208 { std::get<1>(dtup_206) };
                                          ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2884 { dtup_snd_208.readU16Le() };
                                          ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_2885;
                                          {
                                            auto du16_fst_210 { std::get<0>(id_2884) };
                                            auto du16_snd_211 { std::get<1>(id_2884) };
                                            ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_2886 { du16_fst_210, du16_snd_211 };
                                            letpair_res_2885 = id_2886;
                                          }
                                          ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 let_res_2887;
                                          {
                                            ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_215 { letpair_res_2885 };
                                            ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 letpair_res_2888;
                                            {
                                              auto dsum1_fst_216 { std::get<0>(dsum1_215) };
                                              auto dsum1_snd_217 { std::get<1>(dsum1_215) };
                                              uint16_t id_2889 { 0 };
                                              bool id_2890 { bool(id_2889 == dsum1_fst_216) };
                                              ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 choose_res_2891;
                                              if (id_2890) {
                                                uint32_t id_2892 { 0U };
                                                Vec<1, uint32_t> id_2893 {  id_2892  };
                                                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2894;
                                                {
                                                  Vec<1, uint32_t> leb_ref_233 { id_2893 };
                                                  uint8_t id_2895 { 0 };
                                                  Vec<1, uint8_t> id_2896 {  id_2895  };
                                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2897;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_234 { id_2896 };
                                                    Vec<1, Pointer> id_2898 {  dsum1_snd_217  };
                                                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2899;
                                                    {
                                                      Vec<1, Pointer> p_ref_235 { id_2898 };
                                                      bool while_flag_2900 { true };
                                                      do {
                                                        uint8_t id_2901 { 0 };
                                                        Pointer id_2902 { p_ref_235[id_2901] };
                                                        ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2903 { id_2902.readU8() };
                                                        bool let_res_2904;
                                                        {
                                                          ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_236 { id_2903 };
                                                          bool letpair_res_2905;
                                                          {
                                                            auto leb128_fst_237 { std::get<0>(leb128_236) };
                                                            auto leb128_snd_238 { std::get<1>(leb128_236) };
                                                            uint8_t id_2906 { 0 };
                                                            Void id_2907 { ((void)(p_ref_235[id_2906] = leb128_snd_238), VOID) };
                                                            (void)id_2907;
                                                            uint8_t id_2908 { 0 };
                                                            uint8_t id_2909 { 127 };
                                                            uint8_t id_2910 { uint8_t(leb128_fst_237 & id_2909) };
                                                            uint32_t id_2911 { uint32_t(id_2910) };
                                                            uint8_t id_2912 { 0 };
                                                            uint8_t id_2913 { shft_ref_234[id_2912] };
                                                            uint32_t id_2914 { uint32_t(id_2911 << id_2913) };
                                                            uint8_t id_2915 { 0 };
                                                            uint32_t id_2916 { leb_ref_233[id_2915] };
                                                            uint32_t id_2917 { uint32_t(id_2914 | id_2916) };
                                                            Void id_2918 { ((void)(leb_ref_233[id_2908] = id_2917), VOID) };
                                                            (void)id_2918;
                                                            uint8_t id_2919 { 0 };
                                                            uint8_t id_2920 { 0 };
                                                            uint8_t id_2921 { shft_ref_234[id_2920] };
                                                            uint8_t id_2922 { 7 };
                                                            uint8_t id_2923 { uint8_t(id_2921 + id_2922) };
                                                            Void id_2924 { ((void)(shft_ref_234[id_2919] = id_2923), VOID) };
                                                            (void)id_2924;
                                                            uint8_t id_2925 { 128 };
                                                            bool id_2926 { bool(leb128_fst_237 >= id_2925) };
                                                            letpair_res_2905 = id_2926;
                                                          }
                                                          let_res_2904 = letpair_res_2905;
                                                        }
                                                        while_flag_2900 = let_res_2904;
                                                        if (while_flag_2900) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_2900);
                                                      (void)VOID;
                                                      uint8_t id_2927 { 0 };
                                                      uint32_t id_2928 { leb_ref_233[id_2927] };
                                                      Size id_2929 { Size(id_2928) };
                                                      uint8_t id_2930 { 0 };
                                                      Pointer id_2931 { p_ref_235[id_2930] };
                                                      ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2932 { id_2929, id_2931 };
                                                      let_res_2899 = id_2932;
                                                    }
                                                    let_res_2897 = let_res_2899;
                                                  }
                                                  let_res_2894 = let_res_2897;
                                                }
                                                ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 let_res_2933;
                                                {
                                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_239 { let_res_2894 };
                                                  ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 letpair_res_2934;
                                                  {
                                                    auto dstring1_fst_240 { std::get<0>(dstring1_239) };
                                                    auto dstring1_snd_241 { std::get<1>(dstring1_239) };
                                                    ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2935 { dstring1_snd_241.readBytes(dstring1_fst_240) };
                                                    ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 letpair_res_2936;
                                                    {
                                                      auto dstring2_fst_243 { std::get<0>(id_2935) };
                                                      auto dstring2_snd_244 { std::get<1>(id_2935) };
                                                      std::string id_2937 { dstring2_fst_243.toString() };
                                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_2938 { std::in_place_index<0>, id_2937 };
                                                      ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 id_2939 { id_2938, dstring2_snd_244 };
                                                      letpair_res_2936 = id_2939;
                                                    }
                                                    letpair_res_2934 = letpair_res_2936;
                                                  }
                                                  let_res_2933 = letpair_res_2934;
                                                }
                                                choose_res_2891 = let_res_2933;
                                              } else {
                                                uint16_t id_2940 { 1 };
                                                bool id_2941 { bool(dsum1_fst_216 == id_2940) };
                                                Void id_2942 { ((void)(assert(id_2941)), VOID) };
                                                (void)id_2942;
                                                uint32_t id_2943 { 0U };
                                                Vec<1, uint32_t> id_2944 {  id_2943  };
                                                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2945;
                                                {
                                                  Vec<1, uint32_t> leb_ref_218 { id_2944 };
                                                  uint8_t id_2946 { 0 };
                                                  Vec<1, uint8_t> id_2947 {  id_2946  };
                                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2948;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_219 { id_2947 };
                                                    Vec<1, Pointer> id_2949 {  dsum1_snd_217  };
                                                    ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_2950;
                                                    {
                                                      Vec<1, Pointer> p_ref_220 { id_2949 };
                                                      bool while_flag_2951 { true };
                                                      do {
                                                        uint8_t id_2952 { 0 };
                                                        Pointer id_2953 { p_ref_220[id_2952] };
                                                        ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_2954 { id_2953.readU8() };
                                                        bool let_res_2955;
                                                        {
                                                          ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_221 { id_2954 };
                                                          bool letpair_res_2956;
                                                          {
                                                            auto leb128_fst_222 { std::get<0>(leb128_221) };
                                                            auto leb128_snd_223 { std::get<1>(leb128_221) };
                                                            uint8_t id_2957 { 0 };
                                                            Void id_2958 { ((void)(p_ref_220[id_2957] = leb128_snd_223), VOID) };
                                                            (void)id_2958;
                                                            uint8_t id_2959 { 0 };
                                                            uint8_t id_2960 { 127 };
                                                            uint8_t id_2961 { uint8_t(leb128_fst_222 & id_2960) };
                                                            uint32_t id_2962 { uint32_t(id_2961) };
                                                            uint8_t id_2963 { 0 };
                                                            uint8_t id_2964 { shft_ref_219[id_2963] };
                                                            uint32_t id_2965 { uint32_t(id_2962 << id_2964) };
                                                            uint8_t id_2966 { 0 };
                                                            uint32_t id_2967 { leb_ref_218[id_2966] };
                                                            uint32_t id_2968 { uint32_t(id_2965 | id_2967) };
                                                            Void id_2969 { ((void)(leb_ref_218[id_2959] = id_2968), VOID) };
                                                            (void)id_2969;
                                                            uint8_t id_2970 { 0 };
                                                            uint8_t id_2971 { 0 };
                                                            uint8_t id_2972 { shft_ref_219[id_2971] };
                                                            uint8_t id_2973 { 7 };
                                                            uint8_t id_2974 { uint8_t(id_2972 + id_2973) };
                                                            Void id_2975 { ((void)(shft_ref_219[id_2970] = id_2974), VOID) };
                                                            (void)id_2975;
                                                            uint8_t id_2976 { 128 };
                                                            bool id_2977 { bool(leb128_fst_222 >= id_2976) };
                                                            letpair_res_2956 = id_2977;
                                                          }
                                                          let_res_2955 = letpair_res_2956;
                                                        }
                                                        while_flag_2951 = let_res_2955;
                                                        if (while_flag_2951) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_2951);
                                                      (void)VOID;
                                                      uint8_t id_2978 { 0 };
                                                      uint32_t id_2979 { leb_ref_218[id_2978] };
                                                      Size id_2980 { Size(id_2979) };
                                                      uint8_t id_2981 { 0 };
                                                      Pointer id_2982 { p_ref_220[id_2981] };
                                                      ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_2983 { id_2980, id_2982 };
                                                      let_res_2950 = id_2983;
                                                    }
                                                    let_res_2948 = let_res_2950;
                                                  }
                                                  let_res_2945 = let_res_2948;
                                                }
                                                ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 let_res_2984;
                                                {
                                                  ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_224 { let_res_2945 };
                                                  ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 letpair_res_2985;
                                                  {
                                                    auto dstring1_fst_225 { std::get<0>(dstring1_224) };
                                                    auto dstring1_snd_226 { std::get<1>(dstring1_224) };
                                                    ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_2986 { dstring1_snd_226.readBytes(dstring1_fst_225) };
                                                    ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 letpair_res_2987;
                                                    {
                                                      auto dstring2_fst_228 { std::get<0>(id_2986) };
                                                      auto dstring2_snd_229 { std::get<1>(id_2986) };
                                                      std::string id_2988 { dstring2_fst_228.toString() };
                                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_2989 { std::in_place_index<1>, id_2988 };
                                                      ::dessser::gen::sync_key::t652d47eaa6c827db9e62e1b0b0edf231 id_2990 { id_2989, dstring2_snd_229 };
                                                      letpair_res_2987 = id_2990;
                                                    }
                                                    letpair_res_2985 = letpair_res_2987;
                                                  }
                                                  let_res_2984 = letpair_res_2985;
                                                }
                                                choose_res_2891 = let_res_2984;
                                              }
                                              letpair_res_2888 = choose_res_2891;
                                            }
                                            let_res_2887 = letpair_res_2888;
                                          }
                                          ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_2991;
                                          {
                                            auto dtup_fst_249 { std::get<0>(let_res_2887) };
                                            auto dtup_snd_250 { std::get<1>(let_res_2887) };
                                            ::dessser::gen::sync_key::tf683ff0a6f84b622c9bd63a1e4d4c2e8 id_2992 { dtup_fst_207, dtup_fst_249 };
                                            ::dessser::gen::sync_key::t* id_2993 { new ::dessser::gen::sync_key::t(std::in_place_index<14>, id_2992) };
                                            ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_2994 { id_2993, dtup_snd_250 };
                                            letpair_res_2991 = id_2994;
                                          }
                                          letpair_res_2883 = letpair_res_2991;
                                        }
                                        let_res_2882 = letpair_res_2883;
                                      }
                                      choose_res_2834 = let_res_2882;
                                    } else {
                                      uint16_t id_2995 { 15 };
                                      bool id_2996 { bool(dsum1_fst_81 == id_2995) };
                                      Void id_2997 { ((void)(assert(id_2996)), VOID) };
                                      (void)id_2997;
                                      uint32_t id_2998 { 0U };
                                      Vec<1, uint32_t> id_2999 {  id_2998  };
                                      ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_3000;
                                      {
                                        Vec<1, uint32_t> leb_ref_83 { id_2999 };
                                        uint8_t id_3001 { 0 };
                                        Vec<1, uint8_t> id_3002 {  id_3001  };
                                        ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_3003;
                                        {
                                          Vec<1, uint8_t> shft_ref_84 { id_3002 };
                                          Vec<1, Pointer> id_3004 {  dsum1_snd_82  };
                                          ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_3005;
                                          {
                                            Vec<1, Pointer> p_ref_85 { id_3004 };
                                            bool while_flag_3006 { true };
                                            do {
                                              uint8_t id_3007 { 0 };
                                              Pointer id_3008 { p_ref_85[id_3007] };
                                              ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_3009 { id_3008.readU8() };
                                              bool let_res_3010;
                                              {
                                                ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_86 { id_3009 };
                                                bool letpair_res_3011;
                                                {
                                                  auto leb128_fst_87 { std::get<0>(leb128_86) };
                                                  auto leb128_snd_88 { std::get<1>(leb128_86) };
                                                  uint8_t id_3012 { 0 };
                                                  Void id_3013 { ((void)(p_ref_85[id_3012] = leb128_snd_88), VOID) };
                                                  (void)id_3013;
                                                  uint8_t id_3014 { 0 };
                                                  uint8_t id_3015 { 127 };
                                                  uint8_t id_3016 { uint8_t(leb128_fst_87 & id_3015) };
                                                  uint32_t id_3017 { uint32_t(id_3016) };
                                                  uint8_t id_3018 { 0 };
                                                  uint8_t id_3019 { shft_ref_84[id_3018] };
                                                  uint32_t id_3020 { uint32_t(id_3017 << id_3019) };
                                                  uint8_t id_3021 { 0 };
                                                  uint32_t id_3022 { leb_ref_83[id_3021] };
                                                  uint32_t id_3023 { uint32_t(id_3020 | id_3022) };
                                                  Void id_3024 { ((void)(leb_ref_83[id_3014] = id_3023), VOID) };
                                                  (void)id_3024;
                                                  uint8_t id_3025 { 0 };
                                                  uint8_t id_3026 { 0 };
                                                  uint8_t id_3027 { shft_ref_84[id_3026] };
                                                  uint8_t id_3028 { 7 };
                                                  uint8_t id_3029 { uint8_t(id_3027 + id_3028) };
                                                  Void id_3030 { ((void)(shft_ref_84[id_3025] = id_3029), VOID) };
                                                  (void)id_3030;
                                                  uint8_t id_3031 { 128 };
                                                  bool id_3032 { bool(leb128_fst_87 >= id_3031) };
                                                  letpair_res_3011 = id_3032;
                                                }
                                                let_res_3010 = letpair_res_3011;
                                              }
                                              while_flag_3006 = let_res_3010;
                                              if (while_flag_3006) {
                                                (void)VOID;
                                              }
                                            } while (while_flag_3006);
                                            (void)VOID;
                                            uint8_t id_3033 { 0 };
                                            uint32_t id_3034 { leb_ref_83[id_3033] };
                                            Size id_3035 { Size(id_3034) };
                                            uint8_t id_3036 { 0 };
                                            Pointer id_3037 { p_ref_85[id_3036] };
                                            ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_3038 { id_3035, id_3037 };
                                            let_res_3005 = id_3038;
                                          }
                                          let_res_3003 = let_res_3005;
                                        }
                                        let_res_3000 = let_res_3003;
                                      }
                                      ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e let_res_3039;
                                      {
                                        ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_89 { let_res_3000 };
                                        ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_3040;
                                        {
                                          auto dstring1_fst_90 { std::get<0>(dstring1_89) };
                                          auto dstring1_snd_91 { std::get<1>(dstring1_89) };
                                          ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_3041 { dstring1_snd_91.readBytes(dstring1_fst_90) };
                                          ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_3042;
                                          {
                                            auto dstring2_fst_93 { std::get<0>(id_3041) };
                                            auto dstring2_snd_94 { std::get<1>(id_3041) };
                                            std::string id_3043 { dstring2_fst_93.toString() };
                                            ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e id_3044 { id_3043, dstring2_snd_94 };
                                            letpair_res_3042 = id_3044;
                                          }
                                          letpair_res_3040 = letpair_res_3042;
                                        }
                                        let_res_3039 = letpair_res_3040;
                                      }
                                      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d let_res_3045;
                                      {
                                        ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e dtup_95 { let_res_3039 };
                                        ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_3046;
                                        {
                                          auto dtup_fst_96 { std::get<0>(dtup_95) };
                                          auto dtup_snd_97 { std::get<1>(dtup_95) };
                                          ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_3047 { dtup_snd_97.readU16Le() };
                                          ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_3048;
                                          {
                                            auto du16_fst_99 { std::get<0>(id_3047) };
                                            auto du16_snd_100 { std::get<1>(id_3047) };
                                            ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_3049 { du16_fst_99, du16_snd_100 };
                                            letpair_res_3048 = id_3049;
                                          }
                                          ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 let_res_3050;
                                          {
                                            ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_104 { letpair_res_3048 };
                                            ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 letpair_res_3051;
                                            {
                                              auto dsum1_fst_105 { std::get<0>(dsum1_104) };
                                              auto dsum1_snd_106 { std::get<1>(dsum1_104) };
                                              uint16_t id_3052 { 0 };
                                              bool id_3053 { bool(id_3052 == dsum1_fst_105) };
                                              ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 choose_res_3054;
                                              if (id_3053) {
                                                (void)VOID;
                                                ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_3055 { std::in_place_index<0>, VOID };
                                                ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 id_3056 { id_3055, dsum1_snd_106 };
                                                choose_res_3054 = id_3056;
                                              } else {
                                                uint16_t id_3057 { 1 };
                                                bool id_3058 { bool(id_3057 == dsum1_fst_105) };
                                                ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 choose_res_3059;
                                                if (id_3058) {
                                                  (void)VOID;
                                                  ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_3060 { std::in_place_index<1>, VOID };
                                                  ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 id_3061 { id_3060, dsum1_snd_106 };
                                                  choose_res_3059 = id_3061;
                                                } else {
                                                  uint16_t id_3062 { 2 };
                                                  bool id_3063 { bool(id_3062 == dsum1_fst_105) };
                                                  ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 choose_res_3064;
                                                  if (id_3063) {
                                                    (void)VOID;
                                                    ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_3065 { std::in_place_index<2>, VOID };
                                                    ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 id_3066 { id_3065, dsum1_snd_106 };
                                                    choose_res_3064 = id_3066;
                                                  } else {
                                                    uint16_t id_3067 { 3 };
                                                    bool id_3068 { bool(id_3067 == dsum1_fst_105) };
                                                    ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 choose_res_3069;
                                                    if (id_3068) {
                                                      (void)VOID;
                                                      ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_3070 { std::in_place_index<3>, VOID };
                                                      ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 id_3071 { id_3070, dsum1_snd_106 };
                                                      choose_res_3069 = id_3071;
                                                    } else {
                                                      uint16_t id_3072 { 4 };
                                                      bool id_3073 { bool(id_3072 == dsum1_fst_105) };
                                                      ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 choose_res_3074;
                                                      if (id_3073) {
                                                        (void)VOID;
                                                        ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_3075 { std::in_place_index<4>, VOID };
                                                        ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 id_3076 { id_3075, dsum1_snd_106 };
                                                        choose_res_3074 = id_3076;
                                                      } else {
                                                        uint16_t id_3077 { 5 };
                                                        bool id_3078 { bool(id_3077 == dsum1_fst_105) };
                                                        ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 choose_res_3079;
                                                        if (id_3078) {
                                                          uint32_t id_3080 { 0U };
                                                          Vec<1, uint32_t> id_3081 {  id_3080  };
                                                          ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_3082;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_122 { id_3081 };
                                                            uint8_t id_3083 { 0 };
                                                            Vec<1, uint8_t> id_3084 {  id_3083  };
                                                            ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_3085;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_123 { id_3084 };
                                                              Vec<1, Pointer> id_3086 {  dsum1_snd_106  };
                                                              ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c let_res_3087;
                                                              {
                                                                Vec<1, Pointer> p_ref_124 { id_3086 };
                                                                bool while_flag_3088 { true };
                                                                do {
                                                                  uint8_t id_3089 { 0 };
                                                                  Pointer id_3090 { p_ref_124[id_3089] };
                                                                  ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 id_3091 { id_3090.readU8() };
                                                                  bool let_res_3092;
                                                                  {
                                                                    ::dessser::gen::sync_key::tb3f98ea670610d40658a618de3ec7b90 leb128_125 { id_3091 };
                                                                    bool letpair_res_3093;
                                                                    {
                                                                      auto leb128_fst_126 { std::get<0>(leb128_125) };
                                                                      auto leb128_snd_127 { std::get<1>(leb128_125) };
                                                                      uint8_t id_3094 { 0 };
                                                                      Void id_3095 { ((void)(p_ref_124[id_3094] = leb128_snd_127), VOID) };
                                                                      (void)id_3095;
                                                                      uint8_t id_3096 { 0 };
                                                                      uint8_t id_3097 { 127 };
                                                                      uint8_t id_3098 { uint8_t(leb128_fst_126 & id_3097) };
                                                                      uint32_t id_3099 { uint32_t(id_3098) };
                                                                      uint8_t id_3100 { 0 };
                                                                      uint8_t id_3101 { shft_ref_123[id_3100] };
                                                                      uint32_t id_3102 { uint32_t(id_3099 << id_3101) };
                                                                      uint8_t id_3103 { 0 };
                                                                      uint32_t id_3104 { leb_ref_122[id_3103] };
                                                                      uint32_t id_3105 { uint32_t(id_3102 | id_3104) };
                                                                      Void id_3106 { ((void)(leb_ref_122[id_3096] = id_3105), VOID) };
                                                                      (void)id_3106;
                                                                      uint8_t id_3107 { 0 };
                                                                      uint8_t id_3108 { 0 };
                                                                      uint8_t id_3109 { shft_ref_123[id_3108] };
                                                                      uint8_t id_3110 { 7 };
                                                                      uint8_t id_3111 { uint8_t(id_3109 + id_3110) };
                                                                      Void id_3112 { ((void)(shft_ref_123[id_3107] = id_3111), VOID) };
                                                                      (void)id_3112;
                                                                      uint8_t id_3113 { 128 };
                                                                      bool id_3114 { bool(leb128_fst_126 >= id_3113) };
                                                                      letpair_res_3093 = id_3114;
                                                                    }
                                                                    let_res_3092 = letpair_res_3093;
                                                                  }
                                                                  while_flag_3088 = let_res_3092;
                                                                  if (while_flag_3088) {
                                                                    (void)VOID;
                                                                  }
                                                                } while (while_flag_3088);
                                                                (void)VOID;
                                                                uint8_t id_3115 { 0 };
                                                                uint32_t id_3116 { leb_ref_122[id_3115] };
                                                                Size id_3117 { Size(id_3116) };
                                                                uint8_t id_3118 { 0 };
                                                                Pointer id_3119 { p_ref_124[id_3118] };
                                                                ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c id_3120 { id_3117, id_3119 };
                                                                let_res_3087 = id_3120;
                                                              }
                                                              let_res_3085 = let_res_3087;
                                                            }
                                                            let_res_3082 = let_res_3085;
                                                          }
                                                          ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e let_res_3121;
                                                          {
                                                            ::dessser::gen::sync_key::t8beb80162423aee37bd383e9b6834c9c dstring1_128 { let_res_3082 };
                                                            ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_3122;
                                                            {
                                                              auto dstring1_fst_129 { std::get<0>(dstring1_128) };
                                                              auto dstring1_snd_130 { std::get<1>(dstring1_128) };
                                                              ::dessser::gen::sync_key::t188345aa49abd0cb47ff73fedc219f08 id_3123 { dstring1_snd_130.readBytes(dstring1_fst_129) };
                                                              ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e letpair_res_3124;
                                                              {
                                                                auto dstring2_fst_132 { std::get<0>(id_3123) };
                                                                auto dstring2_snd_133 { std::get<1>(id_3123) };
                                                                std::string id_3125 { dstring2_fst_132.toString() };
                                                                ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e id_3126 { id_3125, dstring2_snd_133 };
                                                                letpair_res_3124 = id_3126;
                                                              }
                                                              letpair_res_3122 = letpair_res_3124;
                                                            }
                                                            let_res_3121 = letpair_res_3122;
                                                          }
                                                          ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 let_res_3127;
                                                          {
                                                            ::dessser::gen::sync_key::tef94b55d8809251f13165d9a05bd9d0e dtup_134 { let_res_3121 };
                                                            ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 letpair_res_3128;
                                                            {
                                                              auto dtup_fst_135 { std::get<0>(dtup_134) };
                                                              auto dtup_snd_136 { std::get<1>(dtup_134) };
                                                              ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_3129 { dtup_snd_136.readU16Le() };
                                                              ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 letpair_res_3130;
                                                              {
                                                                auto du16_fst_138 { std::get<0>(id_3129) };
                                                                auto du16_snd_139 { std::get<1>(id_3129) };
                                                                ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 id_3131 { du16_fst_138, du16_snd_139 };
                                                                letpair_res_3130 = id_3131;
                                                              }
                                                              ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 let_res_3132;
                                                              {
                                                                ::dessser::gen::sync_key::t22a32080ad88ab548b80077a17b7dd46 dsum1_143 { letpair_res_3130 };
                                                                ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 letpair_res_3133;
                                                                {
                                                                  auto dsum1_fst_144 { std::get<0>(dsum1_143) };
                                                                  auto dsum1_snd_145 { std::get<1>(dsum1_143) };
                                                                  uint16_t id_3134 { 0 };
                                                                  bool id_3135 { bool(id_3134 == dsum1_fst_144) };
                                                                  ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 choose_res_3136;
                                                                  if (id_3135) {
                                                                    (void)VOID;
                                                                    ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3137 { std::in_place_index<0>, VOID };
                                                                    ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 id_3138 { id_3137, dsum1_snd_145 };
                                                                    choose_res_3136 = id_3138;
                                                                  } else {
                                                                    uint16_t id_3139 { 1 };
                                                                    bool id_3140 { bool(id_3139 == dsum1_fst_144) };
                                                                    ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 choose_res_3141;
                                                                    if (id_3140) {
                                                                      (void)VOID;
                                                                      ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3142 { std::in_place_index<1>, VOID };
                                                                      ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 id_3143 { id_3142, dsum1_snd_145 };
                                                                      choose_res_3141 = id_3143;
                                                                    } else {
                                                                      uint16_t id_3144 { 2 };
                                                                      bool id_3145 { bool(id_3144 == dsum1_fst_144) };
                                                                      ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 choose_res_3146;
                                                                      if (id_3145) {
                                                                        (void)VOID;
                                                                        ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3147 { std::in_place_index<2>, VOID };
                                                                        ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 id_3148 { id_3147, dsum1_snd_145 };
                                                                        choose_res_3146 = id_3148;
                                                                      } else {
                                                                        uint16_t id_3149 { 3 };
                                                                        bool id_3150 { bool(id_3149 == dsum1_fst_144) };
                                                                        ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 choose_res_3151;
                                                                        if (id_3150) {
                                                                          (void)VOID;
                                                                          ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3152 { std::in_place_index<3>, VOID };
                                                                          ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 id_3153 { id_3152, dsum1_snd_145 };
                                                                          choose_res_3151 = id_3153;
                                                                        } else {
                                                                          uint16_t id_3154 { 4 };
                                                                          bool id_3155 { bool(id_3154 == dsum1_fst_144) };
                                                                          ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 choose_res_3156;
                                                                          if (id_3155) {
                                                                            (void)VOID;
                                                                            ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3157 { std::in_place_index<4>, VOID };
                                                                            ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 id_3158 { id_3157, dsum1_snd_145 };
                                                                            choose_res_3156 = id_3158;
                                                                          } else {
                                                                            uint16_t id_3159 { 5 };
                                                                            bool id_3160 { bool(id_3159 == dsum1_fst_144) };
                                                                            ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 choose_res_3161;
                                                                            if (id_3160) {
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3162 { std::in_place_index<5>, VOID };
                                                                              ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 id_3163 { id_3162, dsum1_snd_145 };
                                                                              choose_res_3161 = id_3163;
                                                                            } else {
                                                                              uint16_t id_3164 { 6 };
                                                                              bool id_3165 { bool(dsum1_fst_144 == id_3164) };
                                                                              Void id_3166 { ((void)(assert(id_3165)), VOID) };
                                                                              (void)id_3166;
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3167 { std::in_place_index<6>, VOID };
                                                                              ::dessser::gen::sync_key::te6642ee05317b332274a933388d6d540 id_3168 { id_3167, dsum1_snd_145 };
                                                                              choose_res_3161 = id_3168;
                                                                            }
                                                                            choose_res_3156 = choose_res_3161;
                                                                          }
                                                                          choose_res_3151 = choose_res_3156;
                                                                        }
                                                                        choose_res_3146 = choose_res_3151;
                                                                      }
                                                                      choose_res_3141 = choose_res_3146;
                                                                    }
                                                                    choose_res_3136 = choose_res_3141;
                                                                  }
                                                                  letpair_res_3133 = choose_res_3136;
                                                                }
                                                                let_res_3132 = letpair_res_3133;
                                                              }
                                                              ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 letpair_res_3169;
                                                              {
                                                                auto dtup_fst_168 { std::get<0>(let_res_3132) };
                                                                auto dtup_snd_169 { std::get<1>(let_res_3132) };
                                                                ::dessser::gen::sync_key::t51130975cc895752ed58d8b9dd6b2622 id_3170 { dtup_fst_135, dtup_fst_168 };
                                                                ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_3171 { std::in_place_index<5>, id_3170 };
                                                                ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 id_3172 { id_3171, dtup_snd_169 };
                                                                letpair_res_3169 = id_3172;
                                                              }
                                                              letpair_res_3128 = letpair_res_3169;
                                                            }
                                                            let_res_3127 = letpair_res_3128;
                                                          }
                                                          choose_res_3079 = let_res_3127;
                                                        } else {
                                                          uint16_t id_3173 { 6 };
                                                          bool id_3174 { bool(dsum1_fst_105 == id_3173) };
                                                          Void id_3175 { ((void)(assert(id_3174)), VOID) };
                                                          (void)id_3175;
                                                          ::dessser::gen::sync_key::t7a47220550fc5126a7b79f1e0c10c645 id_3176 { dsum1_snd_106.readU64Le() };
                                                          ::dessser::gen::sync_key::taebed00ad7fdb3f7ced11d3cfd58aade letpair_res_3177;
                                                          {
                                                            auto dfloat_fst_108 { std::get<0>(id_3176) };
                                                            auto dfloat_snd_109 { std::get<1>(id_3176) };
                                                            double id_3178 { float_of_qword(dfloat_fst_108) };
                                                            ::dessser::gen::sync_key::taebed00ad7fdb3f7ced11d3cfd58aade id_3179 { id_3178, dfloat_snd_109 };
                                                            letpair_res_3177 = id_3179;
                                                          }
                                                          ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 let_res_3180;
                                                          {
                                                            ::dessser::gen::sync_key::taebed00ad7fdb3f7ced11d3cfd58aade dtup_110 { letpair_res_3177 };
                                                            ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 letpair_res_3181;
                                                            {
                                                              auto dtup_fst_111 { std::get<0>(dtup_110) };
                                                              auto dtup_snd_112 { std::get<1>(dtup_110) };
                                                              ::dessser::gen::sync_key::t405eb186408556fed8f2c41523c07d13 id_3182 { dtup_snd_112.readU32Le() };
                                                              ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 letpair_res_3183;
                                                              {
                                                                auto du32_fst_114 { std::get<0>(id_3182) };
                                                                auto du32_snd_115 { std::get<1>(id_3182) };
                                                                ::dessser::gen::sync_key::t66e64aa59a640b5ac04dd276fa3e8463 id_3184 { dtup_fst_111, du32_fst_114 };
                                                                ::dessser::gen::sync_key::t14a5e3eba11a1198d8e17aba65f08825 id_3185 { std::in_place_index<6>, id_3184 };
                                                                ::dessser::gen::sync_key::tf53c8dceba8a84883083484790fbf024 id_3186 { id_3185, du32_snd_115 };
                                                                letpair_res_3183 = id_3186;
                                                              }
                                                              letpair_res_3181 = letpair_res_3183;
                                                            }
                                                            let_res_3180 = letpair_res_3181;
                                                          }
                                                          choose_res_3079 = let_res_3180;
                                                        }
                                                        choose_res_3074 = choose_res_3079;
                                                      }
                                                      choose_res_3069 = choose_res_3074;
                                                    }
                                                    choose_res_3064 = choose_res_3069;
                                                  }
                                                  choose_res_3059 = choose_res_3064;
                                                }
                                                choose_res_3054 = choose_res_3059;
                                              }
                                              letpair_res_3051 = choose_res_3054;
                                            }
                                            let_res_3050 = letpair_res_3051;
                                          }
                                          ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_3187;
                                          {
                                            auto dtup_fst_189 { std::get<0>(let_res_3050) };
                                            auto dtup_snd_190 { std::get<1>(let_res_3050) };
                                            ::dessser::gen::sync_key::t0d1b1fab40d65ee9bac191ed6e0b37a6 id_3188 { dtup_fst_96, dtup_fst_189 };
                                            ::dessser::gen::sync_key::t* id_3189 { new ::dessser::gen::sync_key::t(std::in_place_index<15>, id_3188) };
                                            ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_3190 { id_3189, dtup_snd_190 };
                                            letpair_res_3187 = id_3190;
                                          }
                                          letpair_res_3046 = letpair_res_3187;
                                        }
                                        let_res_3045 = letpair_res_3046;
                                      }
                                      choose_res_2834 = let_res_3045;
                                    }
                                    choose_res_2829 = choose_res_2834;
                                  }
                                  choose_res_2772 = choose_res_2829;
                                }
                                choose_res_2698 = choose_res_2772;
                              }
                              choose_res_2693 = choose_res_2698;
                            }
                            choose_res_2671 = choose_res_2693;
                          }
                          choose_res_2664 = choose_res_2671;
                        }
                        choose_res_2537 = choose_res_2664;
                      }
                      choose_res_2465 = choose_res_2537;
                    }
                    choose_res_2150 = choose_res_2465;
                  }
                  choose_res_2145 = choose_res_2150;
                }
                choose_res_2089 = choose_res_2145;
              }
              choose_res_2038 = choose_res_2089;
            }
            choose_res_2033 = choose_res_2038;
          }
          choose_res_2028 = choose_res_2033;
        }
        letpair_res_2025 = choose_res_2028;
      }
      let_res_2024 = letpair_res_2025;
    }
    ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d letpair_res_3191;
    {
      auto make_fst_654 { std::get<0>(let_res_2024) };
      auto make_snd_655 { std::get<1>(let_res_2024) };
      ::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d id_3192 { make_fst_654, make_snd_655 };
      letpair_res_3191 = id_3192;
    }
    return letpair_res_3191;
  }
   };
  return fun2020;
}
std::function<::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
