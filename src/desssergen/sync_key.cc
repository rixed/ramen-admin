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

inline bool operator==(per_dash_key const &a, per_dash_key const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Widgets
  };
  return false;
}
inline bool operator!=(per_dash_key const &a, per_dash_key const &b) {
  return !operator==(a, b);
}
struct per_client : public std::variant<
  std::string, // Response
  ::dessser::gen::sync_key::per_dash_key* // Scratchpad
> { using variant::variant; };

inline bool operator==(per_client const &a, per_client const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Response
    case 1: return std::get<1>(a) == std::get<1>(b); // Scratchpad
  };
  return false;
}
inline bool operator!=(per_client const &a, per_client const &b) {
  return !operator==(a, b);
}
struct per_tail : public std::variant<
  std::string, // Subscriber
  uint32_t // LastTuple
> { using variant::variant; };

inline bool operator==(per_tail const &a, per_tail const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Subscriber
    case 1: return std::get<1>(a) == std::get<1>(b); // LastTuple
  };
  return false;
}
inline bool operator!=(per_tail const &a, per_tail const &b) {
  return !operator==(a, b);
}
struct t3f2a416abcbd7d33d681d9d47445767b : public std::tuple<
  dessser::gen::src_path::t_ext,
  std::string
> {
  using tuple::tuple;
  t3f2a416abcbd7d33d681d9d47445767b(std::tuple<dessser::gen::src_path::t_ext, std::string> p)
    : std::tuple<dessser::gen::src_path::t_ext, std::string>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3f2a416abcbd7d33d681d9d47445767b const &a, t3f2a416abcbd7d33d681d9d47445767b const &b) {
  return ::dessser::gen::src_path::Deref(std::get<0>(a)) == ::dessser::gen::src_path::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3f2a416abcbd7d33d681d9d47445767b const &a, t3f2a416abcbd7d33d681d9d47445767b const &b) {
  return !operator==(a, b);
}
struct t32def300158106bfcc2bfd2015d1a3a9 : public std::variant<
  Void, // Host
  Void // Port
> { using variant::variant; };

inline bool operator==(t32def300158106bfcc2bfd2015d1a3a9 const &a, t32def300158106bfcc2bfd2015d1a3a9 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Host
    case 1: return std::get<1>(a) == std::get<1>(b); // Port
  };
  return false;
}
inline bool operator!=(t32def300158106bfcc2bfd2015d1a3a9 const &a, t32def300158106bfcc2bfd2015d1a3a9 const &b) {
  return !operator==(a, b);
}
struct t917a1ec3837bac9e10c931466c2b1db6 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9
> {
  using tuple::tuple;
  t917a1ec3837bac9e10c931466c2b1db6(std::tuple<std::string, ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t917a1ec3837bac9e10c931466c2b1db6 const &a, t917a1ec3837bac9e10c931466c2b1db6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t917a1ec3837bac9e10c931466c2b1db6 const &a, t917a1ec3837bac9e10c931466c2b1db6 const &b) {
  return !operator==(a, b);
}
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

inline bool operator==(t082c1c733e68c2b9334f218f8c5aeccb const &a, t082c1c733e68c2b9334f218f8c5aeccb const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // StateFile
    case 1: return std::get<1>(a) == std::get<1>(b); // InputRingFile
    case 2: return std::get<2>(a) == std::get<2>(b); // Pid
    case 3: return std::get<3>(a) == std::get<3>(b); // LastKilled
    case 4: return std::get<4>(a) == std::get<4>(b); // LastExit
    case 5: return std::get<5>(a) == std::get<5>(b); // LastExitStatus
    case 6: return std::get<6>(a) == std::get<6>(b); // SuccessiveFailures
    case 7: return std::get<7>(a) == std::get<7>(b); // QuarantineUntil
  };
  return false;
}
inline bool operator!=(t082c1c733e68c2b9334f218f8c5aeccb const &a, t082c1c733e68c2b9334f218f8c5aeccb const &b) {
  return !operator==(a, b);
}
struct t87de6a51e16e395e537230ef32d18a96 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb
> {
  using tuple::tuple;
  t87de6a51e16e395e537230ef32d18a96(std::tuple<std::string, ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t87de6a51e16e395e537230ef32d18a96 const &a, t87de6a51e16e395e537230ef32d18a96 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t87de6a51e16e395e537230ef32d18a96 const &a, t87de6a51e16e395e537230ef32d18a96 const &b) {
  return !operator==(a, b);
}
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

inline bool operator==(t4f653cc5cecafb6924f3d52da0caa392 const &a, t4f653cc5cecafb6924f3d52da0caa392 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // RuntimeStats
    case 1: return std::get<1>(a) == std::get<1>(b); // ArchivedTimes
    case 2: return std::get<2>(a) == std::get<2>(b); // NumArcFiles
    case 3: return std::get<3>(a) == std::get<3>(b); // NumArcBytes
    case 4: return std::get<4>(a) == std::get<4>(b); // AllocedArcBytes
    case 5: return std::get<5>(a) == std::get<5>(b); // Worker
    case 6: return std::get<6>(a) == std::get<6>(b); // PerInstance
    case 7: return std::get<7>(a) == std::get<7>(b); // PerReplayer
    case 8: return std::get<8>(a) == std::get<8>(b); // OutputSpecs
  };
  return false;
}
inline bool operator!=(t4f653cc5cecafb6924f3d52da0caa392 const &a, t4f653cc5cecafb6924f3d52da0caa392 const &b) {
  return !operator==(a, b);
}
struct tb2139bc0252a099cc9e179b592108d12 : public std::tuple<
  dessser::gen::fq_name::t_ext,
  ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392
> {
  using tuple::tuple;
  tb2139bc0252a099cc9e179b592108d12(std::tuple<dessser::gen::fq_name::t_ext, ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392> p)
    : std::tuple<dessser::gen::fq_name::t_ext, ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tb2139bc0252a099cc9e179b592108d12 const &a, tb2139bc0252a099cc9e179b592108d12 const &b) {
  return ::dessser::gen::fq_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tb2139bc0252a099cc9e179b592108d12 const &a, tb2139bc0252a099cc9e179b592108d12 const &b) {
  return !operator==(a, b);
}
struct t73ec97d1f82a1880f5d2693e3a0558b1 : public std::variant<
  Void // Executable
> { using variant::variant; };

inline bool operator==(t73ec97d1f82a1880f5d2693e3a0558b1 const &a, t73ec97d1f82a1880f5d2693e3a0558b1 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Executable
  };
  return false;
}
inline bool operator!=(t73ec97d1f82a1880f5d2693e3a0558b1 const &a, t73ec97d1f82a1880f5d2693e3a0558b1 const &b) {
  return !operator==(a, b);
}
struct t1a2ea3d90b4ec20b73da76f490de4625 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1
> {
  using tuple::tuple;
  t1a2ea3d90b4ec20b73da76f490de4625(std::tuple<std::string, ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1a2ea3d90b4ec20b73da76f490de4625 const &a, t1a2ea3d90b4ec20b73da76f490de4625 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1a2ea3d90b4ec20b73da76f490de4625 const &a, t1a2ea3d90b4ec20b73da76f490de4625 const &b) {
  return !operator==(a, b);
}
struct t9030dc10bd527c50c2f835375dc4eb9d : public std::variant<
  Void, // IsMaster
  ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6, // PerService
  ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12, // PerWorker
  ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 // PerProgram
> { using variant::variant; };

inline bool operator==(t9030dc10bd527c50c2f835375dc4eb9d const &a, t9030dc10bd527c50c2f835375dc4eb9d const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // IsMaster
    case 1: return std::get<1>(a) == std::get<1>(b); // PerService
    case 2: return std::get<2>(a) == std::get<2>(b); // PerWorker
    case 3: return std::get<3>(a) == std::get<3>(b); // PerProgram
  };
  return false;
}
inline bool operator!=(t9030dc10bd527c50c2f835375dc4eb9d const &a, t9030dc10bd527c50c2f835375dc4eb9d const &b) {
  return !operator==(a, b);
}
struct t64d8d40f333c531e9d48c05b8ceb4cfa : public std::tuple<
  dessser::gen::site_name::t_ext,
  ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d
> {
  using tuple::tuple;
  t64d8d40f333c531e9d48c05b8ceb4cfa(std::tuple<dessser::gen::site_name::t_ext, ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d> p)
    : std::tuple<dessser::gen::site_name::t_ext, ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t64d8d40f333c531e9d48c05b8ceb4cfa const &a, t64d8d40f333c531e9d48c05b8ceb4cfa const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t64d8d40f333c531e9d48c05b8ceb4cfa const &a, t64d8d40f333c531e9d48c05b8ceb4cfa const &b) {
  return !operator==(a, b);
}
struct t1fb80ba5a0eef0b970838ab3e8e6bce4 : public std::variant<
  Void, // TotalSize
  Void, // RecallCost
  std::string // RetentionsOverride
> { using variant::variant; };

inline bool operator==(t1fb80ba5a0eef0b970838ab3e8e6bce4 const &a, t1fb80ba5a0eef0b970838ab3e8e6bce4 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // TotalSize
    case 1: return std::get<1>(a) == std::get<1>(b); // RecallCost
    case 2: return std::get<2>(a) == std::get<2>(b); // RetentionsOverride
  };
  return false;
}
inline bool operator!=(t1fb80ba5a0eef0b970838ab3e8e6bce4 const &a, t1fb80ba5a0eef0b970838ab3e8e6bce4 const &b) {
  return !operator==(a, b);
}
struct t1fe1711acd7cd3c8e5ef24184b852848 : public std::tuple<
  dessser::gen::site_name::t_ext,
  dessser::gen::fq_name::t_ext,
  std::string,
  ::dessser::gen::sync_key::per_tail*
> {
  using tuple::tuple;
};
inline bool operator==(t1fe1711acd7cd3c8e5ef24184b852848 const &a, t1fe1711acd7cd3c8e5ef24184b852848 const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && ::dessser::gen::fq_name::Deref(std::get<1>(a)) == ::dessser::gen::fq_name::Deref(std::get<1>(b)) && std::get<2>(a) == std::get<2>(b) && std::get<3>(a) == std::get<3>(b);
}
inline bool operator!=(t1fe1711acd7cd3c8e5ef24184b852848 const &a, t1fe1711acd7cd3c8e5ef24184b852848 const &b) {
  return !operator==(a, b);
}
struct t3f175f4a6fba6fdb7dfcec615c7c9650 : public std::tuple<
  dessser::gen::sync_socket::t_ext,
  ::dessser::gen::sync_key::per_client*
> {
  using tuple::tuple;
  t3f175f4a6fba6fdb7dfcec615c7c9650(std::tuple<dessser::gen::sync_socket::t_ext, ::dessser::gen::sync_key::per_client*> p)
    : std::tuple<dessser::gen::sync_socket::t_ext, ::dessser::gen::sync_key::per_client*>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3f175f4a6fba6fdb7dfcec615c7c9650 const &a, t3f175f4a6fba6fdb7dfcec615c7c9650 const &b) {
  return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3f175f4a6fba6fdb7dfcec615c7c9650 const &a, t3f175f4a6fba6fdb7dfcec615c7c9650 const &b) {
  return !operator==(a, b);
}
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
struct ta2544ee31f0dcf915e9425cc06777d2f : public std::tuple<
  std::string,
  per_dash_key*
> {
  using tuple::tuple;
  ta2544ee31f0dcf915e9425cc06777d2f(std::tuple<std::string, per_dash_key*> p)
    : std::tuple<std::string, per_dash_key*>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta2544ee31f0dcf915e9425cc06777d2f const &a, ta2544ee31f0dcf915e9425cc06777d2f const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(ta2544ee31f0dcf915e9425cc06777d2f const &a, ta2544ee31f0dcf915e9425cc06777d2f const &b) {
  return !operator==(a, b);
}
struct t8bc7bba8a815a55f85ed48e95de5ac1f : public std::variant<
  std::string, // Contacts
  std::string // Inhibition
> { using variant::variant; };

inline bool operator==(t8bc7bba8a815a55f85ed48e95de5ac1f const &a, t8bc7bba8a815a55f85ed48e95de5ac1f const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Contacts
    case 1: return std::get<1>(a) == std::get<1>(b); // Inhibition
  };
  return false;
}
inline bool operator!=(t8bc7bba8a815a55f85ed48e95de5ac1f const &a, t8bc7bba8a815a55f85ed48e95de5ac1f const &b) {
  return !operator==(a, b);
}
struct tdf2a6472960228e59d64c7f9dc00dcfa : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f
> {
  using tuple::tuple;
  tdf2a6472960228e59d64c7f9dc00dcfa(std::tuple<std::string, ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tdf2a6472960228e59d64c7f9dc00dcfa const &a, tdf2a6472960228e59d64c7f9dc00dcfa const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tdf2a6472960228e59d64c7f9dc00dcfa const &a, tdf2a6472960228e59d64c7f9dc00dcfa const &b) {
  return !operator==(a, b);
}
struct t7cca840d7e40b13b976d995ba9f9fd5b : public std::variant<
  Void, // NumDeliveryAttempts
  Void, // FirstDeliveryAttempt
  Void, // LastDeliveryAttempt
  Void, // NextScheduled
  Void, // NextSend
  Void, // DeliveryStatus
  Void // Ack
> { using variant::variant; };

inline bool operator==(t7cca840d7e40b13b976d995ba9f9fd5b const &a, t7cca840d7e40b13b976d995ba9f9fd5b const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // NumDeliveryAttempts
    case 1: return std::get<1>(a) == std::get<1>(b); // FirstDeliveryAttempt
    case 2: return std::get<2>(a) == std::get<2>(b); // LastDeliveryAttempt
    case 3: return std::get<3>(a) == std::get<3>(b); // NextScheduled
    case 4: return std::get<4>(a) == std::get<4>(b); // NextSend
    case 5: return std::get<5>(a) == std::get<5>(b); // DeliveryStatus
    case 6: return std::get<6>(a) == std::get<6>(b); // Ack
  };
  return false;
}
inline bool operator!=(t7cca840d7e40b13b976d995ba9f9fd5b const &a, t7cca840d7e40b13b976d995ba9f9fd5b const &b) {
  return !operator==(a, b);
}
struct t5f10ae89970b1e8c27fc9f8df94fd836 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b
> {
  using tuple::tuple;
  t5f10ae89970b1e8c27fc9f8df94fd836(std::tuple<std::string, ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5f10ae89970b1e8c27fc9f8df94fd836 const &a, t5f10ae89970b1e8c27fc9f8df94fd836 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5f10ae89970b1e8c27fc9f8df94fd836 const &a, t5f10ae89970b1e8c27fc9f8df94fd836 const &b) {
  return !operator==(a, b);
}
struct t5f29f78957e3b1e9ec4688f50d1b6080 : public std::tuple<
  double,
  uint32_t
> {
  using tuple::tuple;
  t5f29f78957e3b1e9ec4688f50d1b6080(std::tuple<double, uint32_t> p)
    : std::tuple<double, uint32_t>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5f29f78957e3b1e9ec4688f50d1b6080 const &a, t5f29f78957e3b1e9ec4688f50d1b6080 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5f29f78957e3b1e9ec4688f50d1b6080 const &a, t5f29f78957e3b1e9ec4688f50d1b6080 const &b) {
  return !operator==(a, b);
}
struct t0c4a58933d47075f04ed70f827130a86 : public std::variant<
  Void, // FirstStartNotif
  Void, // LastStartNotif
  Void, // LastStopNotif
  Void, // LastStateChangeNotif
  Void, // Team
  ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836, // Dialogs
  ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 // Journal
> { using variant::variant; };

inline bool operator==(t0c4a58933d47075f04ed70f827130a86 const &a, t0c4a58933d47075f04ed70f827130a86 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // FirstStartNotif
    case 1: return std::get<1>(a) == std::get<1>(b); // LastStartNotif
    case 2: return std::get<2>(a) == std::get<2>(b); // LastStopNotif
    case 3: return std::get<3>(a) == std::get<3>(b); // LastStateChangeNotif
    case 4: return std::get<4>(a) == std::get<4>(b); // Team
    case 5: return std::get<5>(a) == std::get<5>(b); // Dialogs
    case 6: return std::get<6>(a) == std::get<6>(b); // Journal
  };
  return false;
}
inline bool operator!=(t0c4a58933d47075f04ed70f827130a86 const &a, t0c4a58933d47075f04ed70f827130a86 const &b) {
  return !operator==(a, b);
}
struct t9ec4790c9e9e464ee01331cfcf67af68 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86
> {
  using tuple::tuple;
  t9ec4790c9e9e464ee01331cfcf67af68(std::tuple<std::string, ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9ec4790c9e9e464ee01331cfcf67af68 const &a, t9ec4790c9e9e464ee01331cfcf67af68 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9ec4790c9e9e464ee01331cfcf67af68 const &a, t9ec4790c9e9e464ee01331cfcf67af68 const &b) {
  return !operator==(a, b);
}
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct t : public std::variant<
  Void, // DevNull
  Void, // Time
  std::string, // Versions
  ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b, // Sources
  Void, // TargetConfig
  ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa, // PerSite
  ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4, // Storage
  ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848, // Tails
  uint16_t, // Replays
  std::optional<dessser::gen::sync_socket::t_ext>, // Error
  Void, // ReplayRequests
  ::dessser::gen::sync_key::t3f175f4a6fba6fdb7dfcec615c7c9650, // PerClient
  ::dessser::gen::sync_key::ta2544ee31f0dcf915e9425cc06777d2f, // Dashboards
  Void, // Notifications
  ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa, // Teams
  ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 // Incidents
> { using variant::variant; };

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // DevNull
    case 1: return std::get<1>(a) == std::get<1>(b); // Time
    case 2: return std::get<2>(a) == std::get<2>(b); // Versions
    case 3: return std::get<3>(a) == std::get<3>(b); // Sources
    case 4: return std::get<4>(a) == std::get<4>(b); // TargetConfig
    case 5: return std::get<5>(a) == std::get<5>(b); // PerSite
    case 6: return std::get<6>(a) == std::get<6>(b); // Storage
    case 7: return std::get<7>(a) == std::get<7>(b); // Tails
    case 8: return std::get<8>(a) == std::get<8>(b); // Replays
    case 9: return (std::get<9>(a) && std::get<9>(b) && ::dessser::gen::sync_socket::Deref(std::get<9>(a).value()) == ::dessser::gen::sync_socket::Deref(std::get<9>(b).value())) || (!std::get<9>(a) && !std::get<9>(b)); // Error
    case 10: return std::get<10>(a) == std::get<10>(b); // ReplayRequests
    case 11: return std::get<11>(a) == std::get<11>(b); // PerClient
    case 12: return std::get<12>(a) == std::get<12>(b); // Dashboards
    case 13: return std::get<13>(a) == std::get<13>(b); // Notifications
    case 14: return std::get<14>(a) == std::get<14>(b); // Teams
    case 15: return std::get<15>(a) == std::get<15>(b); // Incidents
  };
  return false;
}
inline bool operator!=(t const &a, t const &b) {
  return !operator==(a, b);
}
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
struct tcce73bde988985bdd0bca77372a40274 : public std::tuple<
  ::dessser::gen::sync_key::per_dash_key*,
  Pointer
> {
  using tuple::tuple;
  tcce73bde988985bdd0bca77372a40274(std::tuple<::dessser::gen::sync_key::per_dash_key*, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::per_dash_key*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcce73bde988985bdd0bca77372a40274 const &a, tcce73bde988985bdd0bca77372a40274 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcce73bde988985bdd0bca77372a40274 const &a, tcce73bde988985bdd0bca77372a40274 const &b) {
  return !operator==(a, b);
}
struct t7609d344c1ba69d0f80fec236d4c216b : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  t7609d344c1ba69d0f80fec236d4c216b(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t7609d344c1ba69d0f80fec236d4c216b const &a, t7609d344c1ba69d0f80fec236d4c216b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t7609d344c1ba69d0f80fec236d4c216b const &a, t7609d344c1ba69d0f80fec236d4c216b const &b) {
  return !operator==(a, b);
}
struct t883c6ffea47c0d7b950fe35881e3d737 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t883c6ffea47c0d7b950fe35881e3d737(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t883c6ffea47c0d7b950fe35881e3d737 const &a, t883c6ffea47c0d7b950fe35881e3d737 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t883c6ffea47c0d7b950fe35881e3d737 const &a, t883c6ffea47c0d7b950fe35881e3d737 const &b) {
  return !operator==(a, b);
}
struct ta604b376a0844fde5b1ddf9a5c29cb43 : public std::tuple<
  ::dessser::gen::sync_key::per_client*,
  Pointer
> {
  using tuple::tuple;
  ta604b376a0844fde5b1ddf9a5c29cb43(std::tuple<::dessser::gen::sync_key::per_client*, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::per_client*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta604b376a0844fde5b1ddf9a5c29cb43 const &a, ta604b376a0844fde5b1ddf9a5c29cb43 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta604b376a0844fde5b1ddf9a5c29cb43 const &a, ta604b376a0844fde5b1ddf9a5c29cb43 const &b) {
  return !operator==(a, b);
}
struct t044960e524fd6ec1bfc06410ce526709 : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t044960e524fd6ec1bfc06410ce526709(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t044960e524fd6ec1bfc06410ce526709 const &a, t044960e524fd6ec1bfc06410ce526709 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t044960e524fd6ec1bfc06410ce526709 const &a, t044960e524fd6ec1bfc06410ce526709 const &b) {
  return !operator==(a, b);
}
struct t1566bd611d8a2b90669c241f5e8d6ff1 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1566bd611d8a2b90669c241f5e8d6ff1(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1566bd611d8a2b90669c241f5e8d6ff1 const &a, t1566bd611d8a2b90669c241f5e8d6ff1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1566bd611d8a2b90669c241f5e8d6ff1 const &a, t1566bd611d8a2b90669c241f5e8d6ff1 const &b) {
  return !operator==(a, b);
}
struct t5887709cc43c8c8e24d28211e8c970a2 : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t5887709cc43c8c8e24d28211e8c970a2(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5887709cc43c8c8e24d28211e8c970a2 const &a, t5887709cc43c8c8e24d28211e8c970a2 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5887709cc43c8c8e24d28211e8c970a2 const &a, t5887709cc43c8c8e24d28211e8c970a2 const &b) {
  return !operator==(a, b);
}
struct t5f750ede44b214b8c8c8313f068ccc23 : public std::tuple<
  ::dessser::gen::sync_key::per_tail*,
  Pointer
> {
  using tuple::tuple;
  t5f750ede44b214b8c8c8313f068ccc23(std::tuple<::dessser::gen::sync_key::per_tail*, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::per_tail*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5f750ede44b214b8c8c8313f068ccc23 const &a, t5f750ede44b214b8c8c8313f068ccc23 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5f750ede44b214b8c8c8313f068ccc23 const &a, t5f750ede44b214b8c8c8313f068ccc23 const &b) {
  return !operator==(a, b);
}
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
struct t2448b9260b09dfe70925659af56825d4 : public std::tuple<
  ::dessser::gen::sync_key::t*,
  Pointer
> {
  using tuple::tuple;
  t2448b9260b09dfe70925659af56825d4(std::tuple<::dessser::gen::sync_key::t*, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t*, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2448b9260b09dfe70925659af56825d4 const &a, t2448b9260b09dfe70925659af56825d4 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2448b9260b09dfe70925659af56825d4 const &a, t2448b9260b09dfe70925659af56825d4 const &b) {
  return !operator==(a, b);
}
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
struct t6886b6ff042edb771f45016f12178bb0 : public std::tuple<
  dessser::gen::src_path::t_ext,
  Pointer
> {
  using tuple::tuple;
  t6886b6ff042edb771f45016f12178bb0(std::tuple<dessser::gen::src_path::t_ext, Pointer> p)
    : std::tuple<dessser::gen::src_path::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6886b6ff042edb771f45016f12178bb0 const &a, t6886b6ff042edb771f45016f12178bb0 const &b) {
  return ::dessser::gen::src_path::Deref(std::get<0>(a)) == ::dessser::gen::src_path::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6886b6ff042edb771f45016f12178bb0 const &a, t6886b6ff042edb771f45016f12178bb0 const &b) {
  return !operator==(a, b);
}
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
struct tff906bde0664efb2415be180e5a241ea : public std::tuple<
  dessser::gen::site_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tff906bde0664efb2415be180e5a241ea(std::tuple<dessser::gen::site_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::site_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tff906bde0664efb2415be180e5a241ea const &a, tff906bde0664efb2415be180e5a241ea const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tff906bde0664efb2415be180e5a241ea const &a, tff906bde0664efb2415be180e5a241ea const &b) {
  return !operator==(a, b);
}
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
struct t712586ec75786967434a0be4152a1e08 : public std::tuple<
  ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d,
  Pointer
> {
  using tuple::tuple;
  t712586ec75786967434a0be4152a1e08(std::tuple<::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t712586ec75786967434a0be4152a1e08 const &a, t712586ec75786967434a0be4152a1e08 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t712586ec75786967434a0be4152a1e08 const &a, t712586ec75786967434a0be4152a1e08 const &b) {
  return !operator==(a, b);
}
struct t3fd8221434e489b54b5c4356ebff5005 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t3fd8221434e489b54b5c4356ebff5005(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3fd8221434e489b54b5c4356ebff5005 const &a, t3fd8221434e489b54b5c4356ebff5005 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3fd8221434e489b54b5c4356ebff5005 const &a, t3fd8221434e489b54b5c4356ebff5005 const &b) {
  return !operator==(a, b);
}
struct t693b3c0b01440f82d6bb9ea682c4062e : public std::tuple<
  ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9,
  Pointer
> {
  using tuple::tuple;
  t693b3c0b01440f82d6bb9ea682c4062e(std::tuple<::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t693b3c0b01440f82d6bb9ea682c4062e const &a, t693b3c0b01440f82d6bb9ea682c4062e const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t693b3c0b01440f82d6bb9ea682c4062e const &a, t693b3c0b01440f82d6bb9ea682c4062e const &b) {
  return !operator==(a, b);
}
struct tcd6e38ac5ca8a381102d1fa6500e9b6e : public std::tuple<
  dessser::gen::fq_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  tcd6e38ac5ca8a381102d1fa6500e9b6e(std::tuple<dessser::gen::fq_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcd6e38ac5ca8a381102d1fa6500e9b6e const &a, tcd6e38ac5ca8a381102d1fa6500e9b6e const &b) {
  return ::dessser::gen::fq_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcd6e38ac5ca8a381102d1fa6500e9b6e const &a, tcd6e38ac5ca8a381102d1fa6500e9b6e const &b) {
  return !operator==(a, b);
}
struct tfad316798fa8ee621795cab2ef1d09e1 : public std::tuple<
  ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392,
  Pointer
> {
  using tuple::tuple;
  tfad316798fa8ee621795cab2ef1d09e1(std::tuple<::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tfad316798fa8ee621795cab2ef1d09e1 const &a, tfad316798fa8ee621795cab2ef1d09e1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tfad316798fa8ee621795cab2ef1d09e1 const &a, tfad316798fa8ee621795cab2ef1d09e1 const &b) {
  return !operator==(a, b);
}
struct t0d6c591ce3b3ba893d6d35f4657ef1da : public std::tuple<
  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb,
  Pointer
> {
  using tuple::tuple;
  t0d6c591ce3b3ba893d6d35f4657ef1da(std::tuple<::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0d6c591ce3b3ba893d6d35f4657ef1da const &a, t0d6c591ce3b3ba893d6d35f4657ef1da const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0d6c591ce3b3ba893d6d35f4657ef1da const &a, t0d6c591ce3b3ba893d6d35f4657ef1da const &b) {
  return !operator==(a, b);
}
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
struct t0e79e03631acd607acafe442d826717b : public std::tuple<
  ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4,
  Pointer
> {
  using tuple::tuple;
  t0e79e03631acd607acafe442d826717b(std::tuple<::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0e79e03631acd607acafe442d826717b const &a, t0e79e03631acd607acafe442d826717b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0e79e03631acd607acafe442d826717b const &a, t0e79e03631acd607acafe442d826717b const &b) {
  return !operator==(a, b);
}
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
struct tdcc52da48df168277d8c161116b319a7 : public std::tuple<
  std::optional<dessser::gen::sync_socket::t_ext>,
  Pointer
> {
  using tuple::tuple;
  tdcc52da48df168277d8c161116b319a7(std::tuple<std::optional<dessser::gen::sync_socket::t_ext>, Pointer> p)
    : std::tuple<std::optional<dessser::gen::sync_socket::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tdcc52da48df168277d8c161116b319a7 const &a, tdcc52da48df168277d8c161116b319a7 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && ::dessser::gen::sync_socket::Deref(std::get<0>(a).value()) == ::dessser::gen::sync_socket::Deref(std::get<0>(b).value())) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tdcc52da48df168277d8c161116b319a7 const &a, tdcc52da48df168277d8c161116b319a7 const &b) {
  return !operator==(a, b);
}
struct t8a365991c4a4591932e21c9e1eeeab20 : public std::tuple<
  dessser::gen::sync_socket::t_ext,
  Pointer
> {
  using tuple::tuple;
  t8a365991c4a4591932e21c9e1eeeab20(std::tuple<dessser::gen::sync_socket::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_socket::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8a365991c4a4591932e21c9e1eeeab20 const &a, t8a365991c4a4591932e21c9e1eeeab20 const &b) {
  return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8a365991c4a4591932e21c9e1eeeab20 const &a, t8a365991c4a4591932e21c9e1eeeab20 const &b) {
  return !operator==(a, b);
}
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
struct t078f1eb283aa345c511748969bd72218 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::per_dash_key*
> {
  using tuple::tuple;
  t078f1eb283aa345c511748969bd72218(std::tuple<std::string, ::dessser::gen::sync_key::per_dash_key*> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::per_dash_key*>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t078f1eb283aa345c511748969bd72218 const &a, t078f1eb283aa345c511748969bd72218 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t078f1eb283aa345c511748969bd72218 const &a, t078f1eb283aa345c511748969bd72218 const &b) {
  return !operator==(a, b);
}
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
struct t3a8843ea98675a135ad450a23aa2b2c8 : public std::tuple<
  ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f,
  Pointer
> {
  using tuple::tuple;
  t3a8843ea98675a135ad450a23aa2b2c8(std::tuple<::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3a8843ea98675a135ad450a23aa2b2c8 const &a, t3a8843ea98675a135ad450a23aa2b2c8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3a8843ea98675a135ad450a23aa2b2c8 const &a, t3a8843ea98675a135ad450a23aa2b2c8 const &b) {
  return !operator==(a, b);
}
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
struct t873cf1aed4c62babb18fe01068a9e2b0 : public std::tuple<
  ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86,
  Pointer
> {
  using tuple::tuple;
  t873cf1aed4c62babb18fe01068a9e2b0(std::tuple<::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t873cf1aed4c62babb18fe01068a9e2b0 const &a, t873cf1aed4c62babb18fe01068a9e2b0 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t873cf1aed4c62babb18fe01068a9e2b0 const &a, t873cf1aed4c62babb18fe01068a9e2b0 const &b) {
  return !operator==(a, b);
}
struct teb1e6c681b5c443ec217619fc46b4be9 : public std::tuple<
  ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b,
  Pointer
> {
  using tuple::tuple;
  teb1e6c681b5c443ec217619fc46b4be9(std::tuple<::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(teb1e6c681b5c443ec217619fc46b4be9 const &a, teb1e6c681b5c443ec217619fc46b4be9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(teb1e6c681b5c443ec217619fc46b4be9 const &a, teb1e6c681b5c443ec217619fc46b4be9 const &b) {
  return !operator==(a, b);
}
struct tf568409f41c9c0a265f7302110fc9084 : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  tf568409f41c9c0a265f7302110fc9084(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf568409f41c9c0a265f7302110fc9084 const &a, tf568409f41c9c0a265f7302110fc9084 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf568409f41c9c0a265f7302110fc9084 const &a, tf568409f41c9c0a265f7302110fc9084 const &b) {
  return !operator==(a, b);
}
struct t5375de390f9cb5ae2ee5880ea1674828 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t5375de390f9cb5ae2ee5880ea1674828(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5375de390f9cb5ae2ee5880ea1674828 const &a, t5375de390f9cb5ae2ee5880ea1674828 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5375de390f9cb5ae2ee5880ea1674828 const &a, t5375de390f9cb5ae2ee5880ea1674828 const &b) {
  return !operator==(a, b);
}
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
/* ----------- */
/* Definitions */
/* ----------- */
/* 
    (fun ("[Widgets U32]" "Ptr")
      (let "ssum_dst_753" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (write-u32 little-endian (identifier "ssum_dst_753") (get-alt "Widgets" (param 0))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::per_dash_key*,Pointer)> per_dash_key_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::per_dash_key*,Pointer)> fun0 { [&fun0](::dessser::gen::sync_key::per_dash_key* p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_753 { id_2 };
      uint16_t id_4 { uint16_t((*p_0).index()) };
      uint16_t id_5 { 0 };
      bool id_6 { bool(id_4 == id_5) };
      Void id_7 { ((void)(assert(id_6)), VOID) };
      (void)id_7;
      uint32_t id_8 { std::get<0 /* Widgets */>((*p_0)) };
      Pointer id_9 { ssum_dst_753.writeU32Le(id_8) };
      let_res_3 = id_9;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::sync_key::per_dash_key*,Pointer)> per_dash_key_to_row_binary(per_dash_key_to_row_binary_init());

/* 
    (fun ("[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" "Ptr")
      (let "ssum_dst_755" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_756" (make-vec (string-length (get-alt "Response" (param 0))))
              (let "leb128_ptr_757" (make-vec (identifier "ssum_dst_755"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_757")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_757"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_756"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_756"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_756"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_756") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_756")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_756")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_757"))))) 
            (bytes-of-string (get-alt "Response" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "per_dash_key-to-row-binary") (get-alt "Scratchpad" (param 0)) (identifier "ssum_dst_755"))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::per_client*,Pointer)> per_client_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::per_client*,Pointer)> fun10 { [&fun10](::dessser::gen::sync_key::per_client* p_0, Pointer p_1) {
    uint16_t id_11 { uint16_t((*p_0).index()) };
    Pointer id_12 { p_1.writeU16Le(id_11) };
    Pointer let_res_13;
    {
      Pointer ssum_dst_755 { id_12 };
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
          Vec<1, uint32_t> leb128_sz_756 { id_20 };
          Vec<1, Pointer> id_22 {  ssum_dst_755  };
          Pointer let_res_23;
          {
            Vec<1, Pointer> leb128_ptr_757 { id_22 };
            bool while_flag_24 { true };
            do {
              uint8_t id_25 { 0 };
              uint8_t id_26 { 0 };
              Pointer id_27 { leb128_ptr_757[id_26] };
              uint32_t id_28 { 128U };
              uint8_t id_29 { 0 };
              uint32_t id_30 { leb128_sz_756[id_29] };
              bool id_31 { bool(id_28 > id_30) };
              uint8_t choose_res_32;
              if (id_31) {
                uint8_t id_33 { 0 };
                uint32_t id_34 { leb128_sz_756[id_33] };
                uint8_t id_35 { uint8_t(id_34) };
                choose_res_32 = id_35;
              } else {
                uint8_t id_36 { 0 };
                uint32_t id_37 { leb128_sz_756[id_36] };
                uint8_t id_38 { uint8_t(id_37) };
                uint8_t id_39 { 128 };
                uint8_t id_40 { uint8_t(id_38 | id_39) };
                choose_res_32 = id_40;
              }
              Pointer id_41 { id_27.writeU8(choose_res_32) };
              Void id_42 { ((void)(leb128_ptr_757[id_25] = id_41), VOID) };
              (void)id_42;
              uint8_t id_43 { 0 };
              uint8_t id_44 { 0 };
              uint32_t id_45 { leb128_sz_756[id_44] };
              uint8_t id_46 { 7 };
              uint32_t id_47 { uint32_t(id_45 >> id_46) };
              Void id_48 { ((void)(leb128_sz_756[id_43] = id_47), VOID) };
              (void)id_48;
              uint8_t id_49 { 0 };
              uint32_t id_50 { leb128_sz_756[id_49] };
              uint32_t id_51 { 0U };
              bool id_52 { bool(id_50 > id_51) };
              while_flag_24 = id_52;
              if (while_flag_24) {
                (void)VOID;
              }
            } while (while_flag_24);
            (void)VOID;
            uint8_t id_53 { 0 };
            Pointer id_54 { leb128_ptr_757[id_53] };
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
        ::dessser::gen::sync_key::per_dash_key* id_62 { std::get<1 /* Scratchpad */>((*p_0)) };
        Pointer id_63 { per_dash_key_to_row_binary(id_62, ssum_dst_755) };
        choose_res_17 = id_63;
      }
      let_res_13 = choose_res_17;
    }
    return let_res_13;
  }
   };
  return fun10;
}
std::function<Pointer(::dessser::gen::sync_key::per_client*,Pointer)> per_client_to_row_binary(per_client_to_row_binary_init());

/* 
    (fun ("[Subscriber STRING | LastTuple U32]" "Ptr")
      (let "ssum_dst_749" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_750" (make-vec (string-length (get-alt "Subscriber" (param 0))))
              (let "leb128_ptr_751" (make-vec (identifier "ssum_dst_749"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_751")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_751"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_750"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_750"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_750"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_750") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_750")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_750")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_751"))))) 
            (bytes-of-string (get-alt "Subscriber" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (write-u32 little-endian (identifier "ssum_dst_749") (get-alt "LastTuple" (param 0)))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::per_tail*,Pointer)> per_tail_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::per_tail*,Pointer)> fun64 { [&fun64](::dessser::gen::sync_key::per_tail* p_0, Pointer p_1) {
    uint16_t id_65 { uint16_t((*p_0).index()) };
    Pointer id_66 { p_1.writeU16Le(id_65) };
    Pointer let_res_67;
    {
      Pointer ssum_dst_749 { id_66 };
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
          Vec<1, uint32_t> leb128_sz_750 { id_74 };
          Vec<1, Pointer> id_76 {  ssum_dst_749  };
          Pointer let_res_77;
          {
            Vec<1, Pointer> leb128_ptr_751 { id_76 };
            bool while_flag_78 { true };
            do {
              uint8_t id_79 { 0 };
              uint8_t id_80 { 0 };
              Pointer id_81 { leb128_ptr_751[id_80] };
              uint32_t id_82 { 128U };
              uint8_t id_83 { 0 };
              uint32_t id_84 { leb128_sz_750[id_83] };
              bool id_85 { bool(id_82 > id_84) };
              uint8_t choose_res_86;
              if (id_85) {
                uint8_t id_87 { 0 };
                uint32_t id_88 { leb128_sz_750[id_87] };
                uint8_t id_89 { uint8_t(id_88) };
                choose_res_86 = id_89;
              } else {
                uint8_t id_90 { 0 };
                uint32_t id_91 { leb128_sz_750[id_90] };
                uint8_t id_92 { uint8_t(id_91) };
                uint8_t id_93 { 128 };
                uint8_t id_94 { uint8_t(id_92 | id_93) };
                choose_res_86 = id_94;
              }
              Pointer id_95 { id_81.writeU8(choose_res_86) };
              Void id_96 { ((void)(leb128_ptr_751[id_79] = id_95), VOID) };
              (void)id_96;
              uint8_t id_97 { 0 };
              uint8_t id_98 { 0 };
              uint32_t id_99 { leb128_sz_750[id_98] };
              uint8_t id_100 { 7 };
              uint32_t id_101 { uint32_t(id_99 >> id_100) };
              Void id_102 { ((void)(leb128_sz_750[id_97] = id_101), VOID) };
              (void)id_102;
              uint8_t id_103 { 0 };
              uint32_t id_104 { leb128_sz_750[id_103] };
              uint32_t id_105 { 0U };
              bool id_106 { bool(id_104 > id_105) };
              while_flag_78 = id_106;
              if (while_flag_78) {
                (void)VOID;
              }
            } while (while_flag_78);
            (void)VOID;
            uint8_t id_107 { 0 };
            Pointer id_108 { leb128_ptr_751[id_107] };
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
        Pointer id_117 { ssum_dst_749.writeU32Le(id_116) };
        choose_res_71 = id_117;
      }
      let_res_67 = choose_res_71;
    }
    return let_res_67;
  }
   };
  return fun64;
}
std::function<Pointer(::dessser::gen::sync_key::per_tail*,Pointer)> per_tail_to_row_binary(per_tail_to_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" "Ptr")
      (let "label1_758" (label-of (param 0))
        (let "ssum_dst_759" (write-u16 little-endian (param 1) (identifier "label1_758"))
          (if (eq (u16 0) (identifier "label1_758")) (identifier "ssum_dst_759")
            (if (eq (u16 1) (identifier "label1_758")) (identifier "ssum_dst_759")
              (if (eq (u16 2) (identifier "label1_758"))
                (write-bytes
                  (let "leb128_sz_817" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "leb128_ptr_818" (make-vec (identifier "ssum_dst_759"))
                      (seq
                        (while
                          (seq
                            (set-vec (u8 0) (identifier "leb128_ptr_818")
                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_818"))
                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_817"))) 
                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_817"))) 
                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_817"))) (u8 128))))) 
                            (set-vec (u8 0) (identifier "leb128_sz_817") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_817")) (u8 7))) 
                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_817")) (u32 0))) 
                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_818"))))) 
                  (bytes-of-string (get-alt "Versions" (param 0))))
                (if (eq (u16 3) (identifier "label1_758"))
                  (let "stup_dst_814" (apply (ext-identifier src_path to-row-binary) (get-item 0 (get-alt "Sources" (param 0))) (identifier "ssum_dst_759"))
                    (write-bytes
                      (let "leb128_sz_815" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "leb128_ptr_816" (make-vec (identifier "stup_dst_814"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_816")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_816"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_815"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_815"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_815"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_815") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_815")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_815")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_816"))))) 
                      (bytes-of-string (get-item 1 (get-alt "Sources" (param 0))))))
                  (if (eq (u16 4) (identifier "label1_758")) (identifier "ssum_dst_759")
                    (if (eq (u16 5) (identifier "label1_758"))
                      (let "stup_dst_793" (apply (ext-identifier site_name to-row-binary) (get-item 0 (get-alt "PerSite" (param 0))) (identifier "ssum_dst_759"))
                        (let "ssum_dst_795" (write-u16 little-endian (identifier "stup_dst_793") (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                          (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerSite" (param 0))))) 
                            (identifier "ssum_dst_795")
                            (if (eq (u16 1) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                              (let "stup_dst_811"
                                (write-bytes
                                  (let "leb128_sz_809" (make-vec (string-length (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                    (let "leb128_ptr_810" (make-vec (identifier "ssum_dst_795"))
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
                                  (bytes-of-string (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                (let "ssum_dst_813" (write-u16 little-endian (identifier "stup_dst_811") (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                  (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0))))))) 
                                    (identifier "ssum_dst_813") (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 1))) (identifier "ssum_dst_813")))))
                              (if (eq (u16 2) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                                (let "stup_dst_801" (apply (ext-identifier fq_name to-row-binary) (get-item 0 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))) (identifier "ssum_dst_795"))
                                  (let "label1_802" (label-of (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))
                                    (let "ssum_dst_803" (write-u16 little-endian (identifier "stup_dst_801") (identifier "label1_802"))
                                      (if (eq (u16 0) (identifier "label1_802")) 
                                        (identifier "ssum_dst_803")
                                        (if (eq (u16 1) (identifier "label1_802")) 
                                          (identifier "ssum_dst_803")
                                          (if (eq (u16 2) (identifier "label1_802")) 
                                            (identifier "ssum_dst_803")
                                            (if (eq (u16 3) (identifier "label1_802")) 
                                              (identifier "ssum_dst_803")
                                              (if (eq (u16 4) (identifier "label1_802")) 
                                                (identifier "ssum_dst_803")
                                                (if (eq (u16 5) (identifier "label1_802")) 
                                                  (identifier "ssum_dst_803")
                                                  (if (eq (u16 6) (identifier "label1_802"))
                                                    (let "stup_dst_806"
                                                      (write-bytes
                                                        (let "leb128_sz_804" 
                                                          (make-vec (string-length (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                                          (let "leb128_ptr_805" 
                                                            (make-vec (identifier "ssum_dst_803"))
                                                            (seq
                                                              (while
                                                                (seq
                                                                  (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_805")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_805"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_804"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_804"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_804"))) (u8 128)))))
                                                                  (set-vec (u8 0) (identifier "leb128_sz_804") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_804")) (u8 7)))
                                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_804")) (u32 0))) 
                                                                (nop)) 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_805")))))
                                                        (bytes-of-string (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                                      (let "label1_807" 
                                                        (label-of (get-item 1 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))))
                                                        (let "ssum_dst_808" 
                                                          (write-u16 little-endian (identifier "stup_dst_806") (identifier "label1_807"))
                                                          (if (eq (u16 0) (identifier "label1_807")) 
                                                            (identifier "ssum_dst_808")
                                                            (if (eq (u16 1) (identifier "label1_807")) 
                                                              (identifier "ssum_dst_808")
                                                              (if (eq (u16 2) (identifier "label1_807")) 
                                                                (identifier "ssum_dst_808")
                                                                (if (eq (u16 3) (identifier "label1_807")) 
                                                                  (identifier "ssum_dst_808")
                                                                  (if 
                                                                    (eq (u16 4) (identifier "label1_807")) 
                                                                    (identifier "ssum_dst_808")
                                                                    (if 
                                                                    (eq (u16 5) (identifier "label1_807")) 
                                                                    (identifier "ssum_dst_808")
                                                                    (if (eq (u16 6) (identifier "label1_807")) (identifier "ssum_dst_808") (seq (assert (eq (identifier "label1_807") (u16 7))) (identifier "ssum_dst_808"))))))))))))
                                                    (if (eq (u16 7) (identifier "label1_802"))
                                                      (write-u32 little-endian (identifier "ssum_dst_803") (get-alt "PerReplayer" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                                      (seq (assert (eq (identifier "label1_802") (u16 8))) (identifier "ssum_dst_803")))))))))))))
                                (seq (assert (eq (label-of (get-item 1 (get-alt "PerSite" (param 0)))) (u16 3)))
                                  (let "stup_dst_798"
                                    (write-bytes
                                      (let "leb128_sz_796" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                        (let "leb128_ptr_797" (make-vec (identifier "ssum_dst_795"))
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
                                      (bytes-of-string (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                    (let "ssum_dst_800" (write-u16 little-endian (identifier "stup_dst_798") (label-of (get-item 1 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                      (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 0))) (identifier "ssum_dst_800"))))))))))
                      (if (eq (u16 6) (identifier "label1_758"))
                        (let "ssum_dst_790" (write-u16 little-endian (identifier "ssum_dst_759") (label-of (get-alt "Storage" (param 0))))
                          (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                            (identifier "ssum_dst_790")
                            (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                              (identifier "ssum_dst_790")
                              (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                                (write-bytes
                                  (let "leb128_sz_791" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                    (let "leb128_ptr_792" (make-vec (identifier "ssum_dst_790"))
                                      (seq
                                        (while
                                          (seq
                                            (set-vec (u8 0) (identifier "leb128_ptr_792")
                                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_792"))
                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_791"))) 
                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_791"))) 
                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_791"))) (u8 128)))))
                                            (set-vec (u8 0) (identifier "leb128_sz_791") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_791")) (u8 7))) 
                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_791")) (u32 0))) 
                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_792"))))) 
                                  (bytes-of-string (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))))))
                        (if (eq (u16 7) (identifier "label1_758"))
                          (let "stup_dst_788"
                            (let "stup_dst_785"
                              (let "stup_dst_784" (apply (ext-identifier site_name to-row-binary) (get-item 0 (get-alt "Tails" (param 0))) (identifier "ssum_dst_759"))
                                (apply (ext-identifier fq_name to-row-binary) (get-item 1 (get-alt "Tails" (param 0))) (identifier "stup_dst_784")))
                              (write-bytes
                                (let "leb128_sz_786" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "leb128_ptr_787" (make-vec (identifier "stup_dst_785"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_787")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_787"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_786"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_786"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_786"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_786") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_786")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_786")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_787"))))) 
                                (bytes-of-string (get-item 2 (get-alt "Tails" (param 0)))))) 
                            (apply (identifier "per_tail-to-row-binary") (get-item 3 (get-alt "Tails" (param 0))) (identifier "stup_dst_788")))
                          (if (eq (u16 8) (identifier "label1_758")) 
                            (write-u16 little-endian (identifier "ssum_dst_759") (get-alt "Replays" (param 0)))
                            (if (eq (u16 9) (identifier "label1_758"))
                              (if (is-null (get-alt "Error" (param 0))) 
                                (write-u8 (identifier "ssum_dst_759") (u8 1)) 
                                (apply (ext-identifier sync_socket to-row-binary) (force (get-alt "Error" (param 0))) (write-u8 (identifier "ssum_dst_759") (u8 0))))
                              (if (eq (u16 10) (identifier "label1_758")) 
                                (identifier "ssum_dst_759")
                                (if (eq (u16 11) (identifier "label1_758"))
                                  (let "stup_dst_783" (apply (ext-identifier sync_socket to-row-binary) (get-item 0 (get-alt "PerClient" (param 0))) (identifier "ssum_dst_759"))
                                    (apply (identifier "per_client-to-row-binary") (get-item 1 (get-alt "PerClient" (param 0))) (identifier "stup_dst_783")))
                                  (if (eq (u16 12) (identifier "label1_758"))
                                    (let "stup_dst_782"
                                      (write-bytes
                                        (let "leb128_sz_780" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "leb128_ptr_781" (make-vec (identifier "ssum_dst_759"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_781")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_781"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_780"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_780"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_780"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_780") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_780")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_780")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_781"))))) 
                                        (bytes-of-string (get-item 0 (get-alt "Dashboards" (param 0))))) 
                                      (apply (identifier "per_dash_key-to-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))) (identifier "stup_dst_782")))
                                    (if (eq (u16 13) (identifier "label1_758")) 
                                      (identifier "ssum_dst_759")
                                      (if (eq (u16 14) (identifier "label1_758"))
                                        (let "stup_dst_773"
                                          (write-bytes
                                            (let "leb128_sz_771" (make-vec (string-length (get-item 0 (get-alt "Teams" (param 0)))))
                                              (let "leb128_ptr_772" (make-vec (identifier "ssum_dst_759"))
                                                (seq
                                                  (while
                                                    (seq
                                                      (set-vec (u8 0) 
                                                        (identifier "leb128_ptr_772")
                                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_772"))
                                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_771"))) 
                                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_771"))) 
                                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_771"))) (u8 128)))))
                                                      (set-vec (u8 0) (identifier "leb128_sz_771") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_771")) (u8 7)))
                                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_771")) (u32 0))) 
                                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_772"))))) 
                                            (bytes-of-string (get-item 0 (get-alt "Teams" (param 0)))))
                                          (let "ssum_dst_775" (write-u16 little-endian (identifier "stup_dst_773") (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                            (if (eq (u16 0) (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                              (write-bytes
                                                (let "leb128_sz_778" 
                                                  (make-vec (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                                  (let "leb128_ptr_779" 
                                                    (make-vec (identifier "ssum_dst_775"))
                                                    (seq
                                                      (while
                                                        (seq
                                                          (set-vec (u8 0) 
                                                            (identifier "leb128_ptr_779")
                                                            (write-u8 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_779"))
                                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_778"))) 
                                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_778"))) 
                                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_778"))) (u8 128)))))
                                                          (set-vec (u8 0) (identifier "leb128_sz_778") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_778")) (u8 7)))
                                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_778")) (u32 0))) 
                                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_779"))))) 
                                                (bytes-of-string (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                              (seq (assert (eq (label-of (get-item 1 (get-alt "Teams" (param 0)))) (u16 1)))
                                                (write-bytes
                                                  (let "leb128_sz_776" 
                                                    (make-vec (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))
                                                    (let "leb128_ptr_777" 
                                                      (make-vec (identifier "ssum_dst_775"))
                                                      (seq
                                                        (while
                                                          (seq
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb128_ptr_777")
                                                              (write-u8 
                                                                (unsafe-nth (u8 0) (identifier "leb128_ptr_777"))
                                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_776"))) 
                                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_776"))) 
                                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_776"))) (u8 128)))))
                                                            (set-vec (u8 0) (identifier "leb128_sz_776") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_776")) (u8 7)))
                                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_776")) (u32 0))) 
                                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_777"))))) 
                                                  (bytes-of-string (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))))))
                                        (seq (assert (eq (identifier "label1_758") (u16 15)))
                                          (let "stup_dst_762"
                                            (write-bytes
                                              (let "leb128_sz_760" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "leb128_ptr_761" 
                                                  (make-vec (identifier "ssum_dst_759"))
                                                  (seq
                                                    (while
                                                      (seq
                                                        (set-vec (u8 0) 
                                                          (identifier "leb128_ptr_761")
                                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_761"))
                                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_760"))) 
                                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_760"))) 
                                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_760"))) (u8 128)))))
                                                        (set-vec (u8 0) (identifier "leb128_sz_760") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_760")) (u8 7)))
                                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_760")) (u32 0))) 
                                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_761"))))) 
                                              (bytes-of-string (get-item 0 (get-alt "Incidents" (param 0)))))
                                            (let "label1_763" (label-of (get-item 1 (get-alt "Incidents" (param 0))))
                                              (let "ssum_dst_764" (write-u16 little-endian (identifier "stup_dst_762") (identifier "label1_763"))
                                                (if (eq (u16 0) (identifier "label1_763")) 
                                                  (identifier "ssum_dst_764")
                                                  (if (eq (u16 1) (identifier "label1_763")) 
                                                    (identifier "ssum_dst_764")
                                                    (if (eq (u16 2) (identifier "label1_763")) 
                                                      (identifier "ssum_dst_764")
                                                      (if (eq (u16 3) (identifier "label1_763")) 
                                                        (identifier "ssum_dst_764")
                                                        (if (eq (u16 4) (identifier "label1_763")) 
                                                          (identifier "ssum_dst_764")
                                                          (if (eq (u16 5) (identifier "label1_763"))
                                                            (let "stup_dst_768"
                                                              (write-bytes
                                                                (let "leb128_sz_766" 
                                                                  (make-vec (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                  (let "leb128_ptr_767" 
                                                                    (make-vec (identifier "ssum_dst_764"))
                                                                    (seq
                                                                    (while
                                                                    (seq
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb128_ptr_767")
                                                                    (write-u8 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_767"))
                                                                    (if 
                                                                    (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_766"))) 
                                                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_766"))) 
                                                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_766"))) (u8 128)))))
                                                                    (set-vec (u8 0) (identifier "leb128_sz_766") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_766")) (u8 7)))
                                                                    (gt (unsafe-nth (u8 0) (identifier "leb128_sz_766")) (u32 0))) 
                                                                    (nop)) 
                                                                    (unsafe-nth (u8 0) (identifier "leb128_ptr_767"))))) 
                                                                (bytes-of-string (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                              (let "label1_769" 
                                                                (label-of (get-item 1 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0))))))
                                                                (let "ssum_dst_770" 
                                                                  (write-u16 little-endian (identifier "stup_dst_768") (identifier "label1_769"))
                                                                  (if 
                                                                    (eq (u16 0) (identifier "label1_769")) 
                                                                    (identifier "ssum_dst_770")
                                                                    (if 
                                                                    (eq (u16 1) (identifier "label1_769")) 
                                                                    (identifier "ssum_dst_770")
                                                                    (if 
                                                                    (eq (u16 2) (identifier "label1_769")) 
                                                                    (identifier "ssum_dst_770")
                                                                    (if 
                                                                    (eq (u16 3) (identifier "label1_769")) 
                                                                    (identifier "ssum_dst_770")
                                                                    (if 
                                                                    (eq (u16 4) (identifier "label1_769")) 
                                                                    (identifier "ssum_dst_770")
                                                                    (if (eq (u16 5) (identifier "label1_769")) (identifier "ssum_dst_770") (seq (assert (eq (identifier "label1_769") (u16 6))) (identifier "ssum_dst_770")))))))))))
                                                            (seq (assert (eq (identifier "label1_763") (u16 6)))
                                                              (let "stup_dst_765" 
                                                                (write-u64 little-endian (identifier "ssum_dst_764") (u64-of-float (get-item 0 (get-alt "Journal" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                (write-u32 little-endian (identifier "stup_dst_765") (get-item 1 (get-alt "Journal" (get-item 1 (get-alt "Incidents" (param 0))))))))))))))))))))))))))))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::t*,Pointer)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::t*,Pointer)> fun118 { [&fun118](::dessser::gen::sync_key::t* p_0, Pointer p_1) {
    uint16_t id_119 { uint16_t((*p_0).index()) };
    Pointer let_res_120;
    {
      uint16_t label1_758 { id_119 };
      Pointer id_121 { p_1.writeU16Le(label1_758) };
      Pointer let_res_122;
      {
        Pointer ssum_dst_759 { id_121 };
        uint16_t id_123 { 0 };
        bool id_124 { bool(id_123 == label1_758) };
        Pointer choose_res_125;
        if (id_124) {
          choose_res_125 = ssum_dst_759;
        } else {
          uint16_t id_126 { 1 };
          bool id_127 { bool(id_126 == label1_758) };
          Pointer choose_res_128;
          if (id_127) {
            choose_res_128 = ssum_dst_759;
          } else {
            uint16_t id_129 { 2 };
            bool id_130 { bool(id_129 == label1_758) };
            Pointer choose_res_131;
            if (id_130) {
              std::string id_132 { std::get<2 /* Versions */>((*p_0)) };
              uint32_t id_133 { (uint32_t)id_132.size() };
              Vec<1, uint32_t> id_134 {  id_133  };
              Pointer let_res_135;
              {
                Vec<1, uint32_t> leb128_sz_817 { id_134 };
                Vec<1, Pointer> id_136 {  ssum_dst_759  };
                Pointer let_res_137;
                {
                  Vec<1, Pointer> leb128_ptr_818 { id_136 };
                  bool while_flag_138 { true };
                  do {
                    uint8_t id_139 { 0 };
                    uint8_t id_140 { 0 };
                    Pointer id_141 { leb128_ptr_818[id_140] };
                    uint32_t id_142 { 128U };
                    uint8_t id_143 { 0 };
                    uint32_t id_144 { leb128_sz_817[id_143] };
                    bool id_145 { bool(id_142 > id_144) };
                    uint8_t choose_res_146;
                    if (id_145) {
                      uint8_t id_147 { 0 };
                      uint32_t id_148 { leb128_sz_817[id_147] };
                      uint8_t id_149 { uint8_t(id_148) };
                      choose_res_146 = id_149;
                    } else {
                      uint8_t id_150 { 0 };
                      uint32_t id_151 { leb128_sz_817[id_150] };
                      uint8_t id_152 { uint8_t(id_151) };
                      uint8_t id_153 { 128 };
                      uint8_t id_154 { uint8_t(id_152 | id_153) };
                      choose_res_146 = id_154;
                    }
                    Pointer id_155 { id_141.writeU8(choose_res_146) };
                    Void id_156 { ((void)(leb128_ptr_818[id_139] = id_155), VOID) };
                    (void)id_156;
                    uint8_t id_157 { 0 };
                    uint8_t id_158 { 0 };
                    uint32_t id_159 { leb128_sz_817[id_158] };
                    uint8_t id_160 { 7 };
                    uint32_t id_161 { uint32_t(id_159 >> id_160) };
                    Void id_162 { ((void)(leb128_sz_817[id_157] = id_161), VOID) };
                    (void)id_162;
                    uint8_t id_163 { 0 };
                    uint32_t id_164 { leb128_sz_817[id_163] };
                    uint32_t id_165 { 0U };
                    bool id_166 { bool(id_164 > id_165) };
                    while_flag_138 = id_166;
                    if (while_flag_138) {
                      (void)VOID;
                    }
                  } while (while_flag_138);
                  (void)VOID;
                  uint8_t id_167 { 0 };
                  Pointer id_168 { leb128_ptr_818[id_167] };
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
              bool id_173 { bool(id_172 == label1_758) };
              Pointer choose_res_174;
              if (id_173) {
                auto fun175 { dessser::gen::src_path::to_row_binary };
                ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_176 { std::get<3 /* Sources */>((*p_0)) };
                dessser::gen::src_path::t_ext id_177 { std::get<0>(id_176) };
                Pointer id_178 { fun175(id_177, ssum_dst_759) };
                Pointer let_res_179;
                {
                  Pointer stup_dst_814 { id_178 };
                  ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_180 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_181 { std::get<1>(id_180) };
                  uint32_t id_182 { (uint32_t)id_181.size() };
                  Vec<1, uint32_t> id_183 {  id_182  };
                  Pointer let_res_184;
                  {
                    Vec<1, uint32_t> leb128_sz_815 { id_183 };
                    Vec<1, Pointer> id_185 {  stup_dst_814  };
                    Pointer let_res_186;
                    {
                      Vec<1, Pointer> leb128_ptr_816 { id_185 };
                      bool while_flag_187 { true };
                      do {
                        uint8_t id_188 { 0 };
                        uint8_t id_189 { 0 };
                        Pointer id_190 { leb128_ptr_816[id_189] };
                        uint32_t id_191 { 128U };
                        uint8_t id_192 { 0 };
                        uint32_t id_193 { leb128_sz_815[id_192] };
                        bool id_194 { bool(id_191 > id_193) };
                        uint8_t choose_res_195;
                        if (id_194) {
                          uint8_t id_196 { 0 };
                          uint32_t id_197 { leb128_sz_815[id_196] };
                          uint8_t id_198 { uint8_t(id_197) };
                          choose_res_195 = id_198;
                        } else {
                          uint8_t id_199 { 0 };
                          uint32_t id_200 { leb128_sz_815[id_199] };
                          uint8_t id_201 { uint8_t(id_200) };
                          uint8_t id_202 { 128 };
                          uint8_t id_203 { uint8_t(id_201 | id_202) };
                          choose_res_195 = id_203;
                        }
                        Pointer id_204 { id_190.writeU8(choose_res_195) };
                        Void id_205 { ((void)(leb128_ptr_816[id_188] = id_204), VOID) };
                        (void)id_205;
                        uint8_t id_206 { 0 };
                        uint8_t id_207 { 0 };
                        uint32_t id_208 { leb128_sz_815[id_207] };
                        uint8_t id_209 { 7 };
                        uint32_t id_210 { uint32_t(id_208 >> id_209) };
                        Void id_211 { ((void)(leb128_sz_815[id_206] = id_210), VOID) };
                        (void)id_211;
                        uint8_t id_212 { 0 };
                        uint32_t id_213 { leb128_sz_815[id_212] };
                        uint32_t id_214 { 0U };
                        bool id_215 { bool(id_213 > id_214) };
                        while_flag_187 = id_215;
                        if (while_flag_187) {
                          (void)VOID;
                        }
                      } while (while_flag_187);
                      (void)VOID;
                      uint8_t id_216 { 0 };
                      Pointer id_217 { leb128_ptr_816[id_216] };
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
                bool id_223 { bool(id_222 == label1_758) };
                Pointer choose_res_224;
                if (id_223) {
                  choose_res_224 = ssum_dst_759;
                } else {
                  uint16_t id_225 { 5 };
                  bool id_226 { bool(id_225 == label1_758) };
                  Pointer choose_res_227;
                  if (id_226) {
                    auto fun228 { dessser::gen::site_name::to_row_binary };
                    ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_229 { std::get<5 /* PerSite */>((*p_0)) };
                    dessser::gen::site_name::t_ext id_230 { std::get<0>(id_229) };
                    Pointer id_231 { fun228(id_230, ssum_dst_759) };
                    Pointer let_res_232;
                    {
                      Pointer stup_dst_793 { id_231 };
                      ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_233 { std::get<5 /* PerSite */>((*p_0)) };
                      ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_234 { std::get<1>(id_233) };
                      uint16_t id_235 { uint16_t(id_234.index()) };
                      Pointer id_236 { stup_dst_793.writeU16Le(id_235) };
                      Pointer let_res_237;
                      {
                        Pointer ssum_dst_795 { id_236 };
                        uint16_t id_238 { 0 };
                        ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_239 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_240 { std::get<1>(id_239) };
                        uint16_t id_241 { uint16_t(id_240.index()) };
                        bool id_242 { bool(id_238 == id_241) };
                        Pointer choose_res_243;
                        if (id_242) {
                          choose_res_243 = ssum_dst_795;
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
                              Vec<1, uint32_t> leb128_sz_809 { id_255 };
                              Vec<1, Pointer> id_257 {  ssum_dst_795  };
                              Pointer let_res_258;
                              {
                                Vec<1, Pointer> leb128_ptr_810 { id_257 };
                                bool while_flag_259 { true };
                                do {
                                  uint8_t id_260 { 0 };
                                  uint8_t id_261 { 0 };
                                  Pointer id_262 { leb128_ptr_810[id_261] };
                                  uint32_t id_263 { 128U };
                                  uint8_t id_264 { 0 };
                                  uint32_t id_265 { leb128_sz_809[id_264] };
                                  bool id_266 { bool(id_263 > id_265) };
                                  uint8_t choose_res_267;
                                  if (id_266) {
                                    uint8_t id_268 { 0 };
                                    uint32_t id_269 { leb128_sz_809[id_268] };
                                    uint8_t id_270 { uint8_t(id_269) };
                                    choose_res_267 = id_270;
                                  } else {
                                    uint8_t id_271 { 0 };
                                    uint32_t id_272 { leb128_sz_809[id_271] };
                                    uint8_t id_273 { uint8_t(id_272) };
                                    uint8_t id_274 { 128 };
                                    uint8_t id_275 { uint8_t(id_273 | id_274) };
                                    choose_res_267 = id_275;
                                  }
                                  Pointer id_276 { id_262.writeU8(choose_res_267) };
                                  Void id_277 { ((void)(leb128_ptr_810[id_260] = id_276), VOID) };
                                  (void)id_277;
                                  uint8_t id_278 { 0 };
                                  uint8_t id_279 { 0 };
                                  uint32_t id_280 { leb128_sz_809[id_279] };
                                  uint8_t id_281 { 7 };
                                  uint32_t id_282 { uint32_t(id_280 >> id_281) };
                                  Void id_283 { ((void)(leb128_sz_809[id_278] = id_282), VOID) };
                                  (void)id_283;
                                  uint8_t id_284 { 0 };
                                  uint32_t id_285 { leb128_sz_809[id_284] };
                                  uint32_t id_286 { 0U };
                                  bool id_287 { bool(id_285 > id_286) };
                                  while_flag_259 = id_287;
                                  if (while_flag_259) {
                                    (void)VOID;
                                  }
                                } while (while_flag_259);
                                (void)VOID;
                                uint8_t id_288 { 0 };
                                Pointer id_289 { leb128_ptr_810[id_288] };
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
                              Pointer stup_dst_811 { id_295 };
                              ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_297 { std::get<5 /* PerSite */>((*p_0)) };
                              ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_298 { std::get<1>(id_297) };
                              ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_299 { std::get<1 /* PerService */>(id_298) };
                              ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_300 { std::get<1>(id_299) };
                              uint16_t id_301 { uint16_t(id_300.index()) };
                              Pointer id_302 { stup_dst_811.writeU16Le(id_301) };
                              Pointer let_res_303;
                              {
                                Pointer ssum_dst_813 { id_302 };
                                uint16_t id_304 { 0 };
                                ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_305 { std::get<5 /* PerSite */>((*p_0)) };
                                ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_306 { std::get<1>(id_305) };
                                ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_307 { std::get<1 /* PerService */>(id_306) };
                                ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_308 { std::get<1>(id_307) };
                                uint16_t id_309 { uint16_t(id_308.index()) };
                                bool id_310 { bool(id_304 == id_309) };
                                Pointer choose_res_311;
                                if (id_310) {
                                  choose_res_311 = ssum_dst_813;
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
                                  choose_res_311 = ssum_dst_813;
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
                              Pointer id_331 { fun326(id_330, ssum_dst_795) };
                              Pointer let_res_332;
                              {
                                Pointer stup_dst_801 { id_331 };
                                ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_333 { std::get<5 /* PerSite */>((*p_0)) };
                                ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_334 { std::get<1>(id_333) };
                                ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_335 { std::get<2 /* PerWorker */>(id_334) };
                                ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_336 { std::get<1>(id_335) };
                                uint16_t id_337 { uint16_t(id_336.index()) };
                                Pointer let_res_338;
                                {
                                  uint16_t label1_802 { id_337 };
                                  Pointer id_339 { stup_dst_801.writeU16Le(label1_802) };
                                  Pointer let_res_340;
                                  {
                                    Pointer ssum_dst_803 { id_339 };
                                    uint16_t id_341 { 0 };
                                    bool id_342 { bool(id_341 == label1_802) };
                                    Pointer choose_res_343;
                                    if (id_342) {
                                      choose_res_343 = ssum_dst_803;
                                    } else {
                                      uint16_t id_344 { 1 };
                                      bool id_345 { bool(id_344 == label1_802) };
                                      Pointer choose_res_346;
                                      if (id_345) {
                                        choose_res_346 = ssum_dst_803;
                                      } else {
                                        uint16_t id_347 { 2 };
                                        bool id_348 { bool(id_347 == label1_802) };
                                        Pointer choose_res_349;
                                        if (id_348) {
                                          choose_res_349 = ssum_dst_803;
                                        } else {
                                          uint16_t id_350 { 3 };
                                          bool id_351 { bool(id_350 == label1_802) };
                                          Pointer choose_res_352;
                                          if (id_351) {
                                            choose_res_352 = ssum_dst_803;
                                          } else {
                                            uint16_t id_353 { 4 };
                                            bool id_354 { bool(id_353 == label1_802) };
                                            Pointer choose_res_355;
                                            if (id_354) {
                                              choose_res_355 = ssum_dst_803;
                                            } else {
                                              uint16_t id_356 { 5 };
                                              bool id_357 { bool(id_356 == label1_802) };
                                              Pointer choose_res_358;
                                              if (id_357) {
                                                choose_res_358 = ssum_dst_803;
                                              } else {
                                                uint16_t id_359 { 6 };
                                                bool id_360 { bool(id_359 == label1_802) };
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
                                                    Vec<1, uint32_t> leb128_sz_804 { id_369 };
                                                    Vec<1, Pointer> id_371 {  ssum_dst_803  };
                                                    Pointer let_res_372;
                                                    {
                                                      Vec<1, Pointer> leb128_ptr_805 { id_371 };
                                                      bool while_flag_373 { true };
                                                      do {
                                                        uint8_t id_374 { 0 };
                                                        uint8_t id_375 { 0 };
                                                        Pointer id_376 { leb128_ptr_805[id_375] };
                                                        uint32_t id_377 { 128U };
                                                        uint8_t id_378 { 0 };
                                                        uint32_t id_379 { leb128_sz_804[id_378] };
                                                        bool id_380 { bool(id_377 > id_379) };
                                                        uint8_t choose_res_381;
                                                        if (id_380) {
                                                          uint8_t id_382 { 0 };
                                                          uint32_t id_383 { leb128_sz_804[id_382] };
                                                          uint8_t id_384 { uint8_t(id_383) };
                                                          choose_res_381 = id_384;
                                                        } else {
                                                          uint8_t id_385 { 0 };
                                                          uint32_t id_386 { leb128_sz_804[id_385] };
                                                          uint8_t id_387 { uint8_t(id_386) };
                                                          uint8_t id_388 { 128 };
                                                          uint8_t id_389 { uint8_t(id_387 | id_388) };
                                                          choose_res_381 = id_389;
                                                        }
                                                        Pointer id_390 { id_376.writeU8(choose_res_381) };
                                                        Void id_391 { ((void)(leb128_ptr_805[id_374] = id_390), VOID) };
                                                        (void)id_391;
                                                        uint8_t id_392 { 0 };
                                                        uint8_t id_393 { 0 };
                                                        uint32_t id_394 { leb128_sz_804[id_393] };
                                                        uint8_t id_395 { 7 };
                                                        uint32_t id_396 { uint32_t(id_394 >> id_395) };
                                                        Void id_397 { ((void)(leb128_sz_804[id_392] = id_396), VOID) };
                                                        (void)id_397;
                                                        uint8_t id_398 { 0 };
                                                        uint32_t id_399 { leb128_sz_804[id_398] };
                                                        uint32_t id_400 { 0U };
                                                        bool id_401 { bool(id_399 > id_400) };
                                                        while_flag_373 = id_401;
                                                        if (while_flag_373) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_373);
                                                      (void)VOID;
                                                      uint8_t id_402 { 0 };
                                                      Pointer id_403 { leb128_ptr_805[id_402] };
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
                                                    Pointer stup_dst_806 { id_411 };
                                                    ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_413 { std::get<5 /* PerSite */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_414 { std::get<1>(id_413) };
                                                    ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_415 { std::get<2 /* PerWorker */>(id_414) };
                                                    ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_416 { std::get<1>(id_415) };
                                                    ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_417 { std::get<6 /* PerInstance */>(id_416) };
                                                    ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_418 { std::get<1>(id_417) };
                                                    uint16_t id_419 { uint16_t(id_418.index()) };
                                                    Pointer let_res_420;
                                                    {
                                                      uint16_t label1_807 { id_419 };
                                                      Pointer id_421 { stup_dst_806.writeU16Le(label1_807) };
                                                      Pointer let_res_422;
                                                      {
                                                        Pointer ssum_dst_808 { id_421 };
                                                        uint16_t id_423 { 0 };
                                                        bool id_424 { bool(id_423 == label1_807) };
                                                        Pointer choose_res_425;
                                                        if (id_424) {
                                                          choose_res_425 = ssum_dst_808;
                                                        } else {
                                                          uint16_t id_426 { 1 };
                                                          bool id_427 { bool(id_426 == label1_807) };
                                                          Pointer choose_res_428;
                                                          if (id_427) {
                                                            choose_res_428 = ssum_dst_808;
                                                          } else {
                                                            uint16_t id_429 { 2 };
                                                            bool id_430 { bool(id_429 == label1_807) };
                                                            Pointer choose_res_431;
                                                            if (id_430) {
                                                              choose_res_431 = ssum_dst_808;
                                                            } else {
                                                              uint16_t id_432 { 3 };
                                                              bool id_433 { bool(id_432 == label1_807) };
                                                              Pointer choose_res_434;
                                                              if (id_433) {
                                                                choose_res_434 = ssum_dst_808;
                                                              } else {
                                                                uint16_t id_435 { 4 };
                                                                bool id_436 { bool(id_435 == label1_807) };
                                                                Pointer choose_res_437;
                                                                if (id_436) {
                                                                  choose_res_437 = ssum_dst_808;
                                                                } else {
                                                                  uint16_t id_438 { 5 };
                                                                  bool id_439 { bool(id_438 == label1_807) };
                                                                  Pointer choose_res_440;
                                                                  if (id_439) {
                                                                    choose_res_440 = ssum_dst_808;
                                                                  } else {
                                                                    uint16_t id_441 { 6 };
                                                                    bool id_442 { bool(id_441 == label1_807) };
                                                                    Pointer choose_res_443;
                                                                    if (id_442) {
                                                                      choose_res_443 = ssum_dst_808;
                                                                    } else {
                                                                      uint16_t id_444 { 7 };
                                                                      bool id_445 { bool(label1_807 == id_444) };
                                                                      Void id_446 { ((void)(assert(id_445)), VOID) };
                                                                      (void)id_446;
                                                                      choose_res_443 = ssum_dst_808;
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
                                                  bool id_448 { bool(id_447 == label1_802) };
                                                  Pointer choose_res_449;
                                                  if (id_448) {
                                                    ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_450 { std::get<5 /* PerSite */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_451 { std::get<1>(id_450) };
                                                    ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_452 { std::get<2 /* PerWorker */>(id_451) };
                                                    ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_453 { std::get<1>(id_452) };
                                                    uint32_t id_454 { std::get<7 /* PerReplayer */>(id_453) };
                                                    Pointer id_455 { ssum_dst_803.writeU32Le(id_454) };
                                                    choose_res_449 = id_455;
                                                  } else {
                                                    uint16_t id_456 { 8 };
                                                    bool id_457 { bool(label1_802 == id_456) };
                                                    Void id_458 { ((void)(assert(id_457)), VOID) };
                                                    (void)id_458;
                                                    choose_res_449 = ssum_dst_803;
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
                                Vec<1, uint32_t> leb128_sz_796 { id_470 };
                                Vec<1, Pointer> id_472 {  ssum_dst_795  };
                                Pointer let_res_473;
                                {
                                  Vec<1, Pointer> leb128_ptr_797 { id_472 };
                                  bool while_flag_474 { true };
                                  do {
                                    uint8_t id_475 { 0 };
                                    uint8_t id_476 { 0 };
                                    Pointer id_477 { leb128_ptr_797[id_476] };
                                    uint32_t id_478 { 128U };
                                    uint8_t id_479 { 0 };
                                    uint32_t id_480 { leb128_sz_796[id_479] };
                                    bool id_481 { bool(id_478 > id_480) };
                                    uint8_t choose_res_482;
                                    if (id_481) {
                                      uint8_t id_483 { 0 };
                                      uint32_t id_484 { leb128_sz_796[id_483] };
                                      uint8_t id_485 { uint8_t(id_484) };
                                      choose_res_482 = id_485;
                                    } else {
                                      uint8_t id_486 { 0 };
                                      uint32_t id_487 { leb128_sz_796[id_486] };
                                      uint8_t id_488 { uint8_t(id_487) };
                                      uint8_t id_489 { 128 };
                                      uint8_t id_490 { uint8_t(id_488 | id_489) };
                                      choose_res_482 = id_490;
                                    }
                                    Pointer id_491 { id_477.writeU8(choose_res_482) };
                                    Void id_492 { ((void)(leb128_ptr_797[id_475] = id_491), VOID) };
                                    (void)id_492;
                                    uint8_t id_493 { 0 };
                                    uint8_t id_494 { 0 };
                                    uint32_t id_495 { leb128_sz_796[id_494] };
                                    uint8_t id_496 { 7 };
                                    uint32_t id_497 { uint32_t(id_495 >> id_496) };
                                    Void id_498 { ((void)(leb128_sz_796[id_493] = id_497), VOID) };
                                    (void)id_498;
                                    uint8_t id_499 { 0 };
                                    uint32_t id_500 { leb128_sz_796[id_499] };
                                    uint32_t id_501 { 0U };
                                    bool id_502 { bool(id_500 > id_501) };
                                    while_flag_474 = id_502;
                                    if (while_flag_474) {
                                      (void)VOID;
                                    }
                                  } while (while_flag_474);
                                  (void)VOID;
                                  uint8_t id_503 { 0 };
                                  Pointer id_504 { leb128_ptr_797[id_503] };
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
                                Pointer stup_dst_798 { id_510 };
                                ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_512 { std::get<5 /* PerSite */>((*p_0)) };
                                ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_513 { std::get<1>(id_512) };
                                ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_514 { std::get<3 /* PerProgram */>(id_513) };
                                ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_515 { std::get<1>(id_514) };
                                uint16_t id_516 { uint16_t(id_515.index()) };
                                Pointer id_517 { stup_dst_798.writeU16Le(id_516) };
                                Pointer let_res_518;
                                {
                                  Pointer ssum_dst_800 { id_517 };
                                  ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_519 { std::get<5 /* PerSite */>((*p_0)) };
                                  ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_520 { std::get<1>(id_519) };
                                  ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_521 { std::get<3 /* PerProgram */>(id_520) };
                                  ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_522 { std::get<1>(id_521) };
                                  uint16_t id_523 { uint16_t(id_522.index()) };
                                  uint16_t id_524 { 0 };
                                  bool id_525 { bool(id_523 == id_524) };
                                  Void id_526 { ((void)(assert(id_525)), VOID) };
                                  (void)id_526;
                                  let_res_518 = ssum_dst_800;
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
                    bool id_528 { bool(id_527 == label1_758) };
                    Pointer choose_res_529;
                    if (id_528) {
                      ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_530 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_531 { uint16_t(id_530.index()) };
                      Pointer id_532 { ssum_dst_759.writeU16Le(id_531) };
                      Pointer let_res_533;
                      {
                        Pointer ssum_dst_790 { id_532 };
                        uint16_t id_534 { 0 };
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_535 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_536 { uint16_t(id_535.index()) };
                        bool id_537 { bool(id_534 == id_536) };
                        Pointer choose_res_538;
                        if (id_537) {
                          choose_res_538 = ssum_dst_790;
                        } else {
                          uint16_t id_539 { 1 };
                          ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_540 { std::get<6 /* Storage */>((*p_0)) };
                          uint16_t id_541 { uint16_t(id_540.index()) };
                          bool id_542 { bool(id_539 == id_541) };
                          Pointer choose_res_543;
                          if (id_542) {
                            choose_res_543 = ssum_dst_790;
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
                              Vec<1, uint32_t> leb128_sz_791 { id_552 };
                              Vec<1, Pointer> id_554 {  ssum_dst_790  };
                              Pointer let_res_555;
                              {
                                Vec<1, Pointer> leb128_ptr_792 { id_554 };
                                bool while_flag_556 { true };
                                do {
                                  uint8_t id_557 { 0 };
                                  uint8_t id_558 { 0 };
                                  Pointer id_559 { leb128_ptr_792[id_558] };
                                  uint32_t id_560 { 128U };
                                  uint8_t id_561 { 0 };
                                  uint32_t id_562 { leb128_sz_791[id_561] };
                                  bool id_563 { bool(id_560 > id_562) };
                                  uint8_t choose_res_564;
                                  if (id_563) {
                                    uint8_t id_565 { 0 };
                                    uint32_t id_566 { leb128_sz_791[id_565] };
                                    uint8_t id_567 { uint8_t(id_566) };
                                    choose_res_564 = id_567;
                                  } else {
                                    uint8_t id_568 { 0 };
                                    uint32_t id_569 { leb128_sz_791[id_568] };
                                    uint8_t id_570 { uint8_t(id_569) };
                                    uint8_t id_571 { 128 };
                                    uint8_t id_572 { uint8_t(id_570 | id_571) };
                                    choose_res_564 = id_572;
                                  }
                                  Pointer id_573 { id_559.writeU8(choose_res_564) };
                                  Void id_574 { ((void)(leb128_ptr_792[id_557] = id_573), VOID) };
                                  (void)id_574;
                                  uint8_t id_575 { 0 };
                                  uint8_t id_576 { 0 };
                                  uint32_t id_577 { leb128_sz_791[id_576] };
                                  uint8_t id_578 { 7 };
                                  uint32_t id_579 { uint32_t(id_577 >> id_578) };
                                  Void id_580 { ((void)(leb128_sz_791[id_575] = id_579), VOID) };
                                  (void)id_580;
                                  uint8_t id_581 { 0 };
                                  uint32_t id_582 { leb128_sz_791[id_581] };
                                  uint32_t id_583 { 0U };
                                  bool id_584 { bool(id_582 > id_583) };
                                  while_flag_556 = id_584;
                                  if (while_flag_556) {
                                    (void)VOID;
                                  }
                                } while (while_flag_556);
                                (void)VOID;
                                uint8_t id_585 { 0 };
                                Pointer id_586 { leb128_ptr_792[id_585] };
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
                      bool id_592 { bool(id_591 == label1_758) };
                      Pointer choose_res_593;
                      if (id_592) {
                        auto fun594 { dessser::gen::site_name::to_row_binary };
                        ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_595 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::site_name::t_ext id_596 { std::get<0>(id_595) };
                        Pointer id_597 { fun594(id_596, ssum_dst_759) };
                        Pointer let_res_598;
                        {
                          Pointer stup_dst_784 { id_597 };
                          auto fun599 { dessser::gen::fq_name::to_row_binary };
                          ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_600 { std::get<7 /* Tails */>((*p_0)) };
                          dessser::gen::fq_name::t_ext id_601 { std::get<1>(id_600) };
                          Pointer id_602 { fun599(id_601, stup_dst_784) };
                          let_res_598 = id_602;
                        }
                        Pointer let_res_603;
                        {
                          Pointer stup_dst_785 { let_res_598 };
                          ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_604 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_605 { std::get<2>(id_604) };
                          uint32_t id_606 { (uint32_t)id_605.size() };
                          Vec<1, uint32_t> id_607 {  id_606  };
                          Pointer let_res_608;
                          {
                            Vec<1, uint32_t> leb128_sz_786 { id_607 };
                            Vec<1, Pointer> id_609 {  stup_dst_785  };
                            Pointer let_res_610;
                            {
                              Vec<1, Pointer> leb128_ptr_787 { id_609 };
                              bool while_flag_611 { true };
                              do {
                                uint8_t id_612 { 0 };
                                uint8_t id_613 { 0 };
                                Pointer id_614 { leb128_ptr_787[id_613] };
                                uint32_t id_615 { 128U };
                                uint8_t id_616 { 0 };
                                uint32_t id_617 { leb128_sz_786[id_616] };
                                bool id_618 { bool(id_615 > id_617) };
                                uint8_t choose_res_619;
                                if (id_618) {
                                  uint8_t id_620 { 0 };
                                  uint32_t id_621 { leb128_sz_786[id_620] };
                                  uint8_t id_622 { uint8_t(id_621) };
                                  choose_res_619 = id_622;
                                } else {
                                  uint8_t id_623 { 0 };
                                  uint32_t id_624 { leb128_sz_786[id_623] };
                                  uint8_t id_625 { uint8_t(id_624) };
                                  uint8_t id_626 { 128 };
                                  uint8_t id_627 { uint8_t(id_625 | id_626) };
                                  choose_res_619 = id_627;
                                }
                                Pointer id_628 { id_614.writeU8(choose_res_619) };
                                Void id_629 { ((void)(leb128_ptr_787[id_612] = id_628), VOID) };
                                (void)id_629;
                                uint8_t id_630 { 0 };
                                uint8_t id_631 { 0 };
                                uint32_t id_632 { leb128_sz_786[id_631] };
                                uint8_t id_633 { 7 };
                                uint32_t id_634 { uint32_t(id_632 >> id_633) };
                                Void id_635 { ((void)(leb128_sz_786[id_630] = id_634), VOID) };
                                (void)id_635;
                                uint8_t id_636 { 0 };
                                uint32_t id_637 { leb128_sz_786[id_636] };
                                uint32_t id_638 { 0U };
                                bool id_639 { bool(id_637 > id_638) };
                                while_flag_611 = id_639;
                                if (while_flag_611) {
                                  (void)VOID;
                                }
                              } while (while_flag_611);
                              (void)VOID;
                              uint8_t id_640 { 0 };
                              Pointer id_641 { leb128_ptr_787[id_640] };
                              let_res_610 = id_641;
                            }
                            let_res_608 = let_res_610;
                          }
                          ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_642 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_643 { std::get<2>(id_642) };
                          Bytes id_644 { id_643 };
                          Pointer id_645 { let_res_608.writeBytes(id_644) };
                          let_res_603 = id_645;
                        }
                        Pointer let_res_646;
                        {
                          Pointer stup_dst_788 { let_res_603 };
                          ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_647 { std::get<7 /* Tails */>((*p_0)) };
                          ::dessser::gen::sync_key::per_tail* id_648 { std::get<3>(id_647) };
                          Pointer id_649 { per_tail_to_row_binary(id_648, stup_dst_788) };
                          let_res_646 = id_649;
                        }
                        choose_res_593 = let_res_646;
                      } else {
                        uint16_t id_650 { 8 };
                        bool id_651 { bool(id_650 == label1_758) };
                        Pointer choose_res_652;
                        if (id_651) {
                          uint16_t id_653 { std::get<8 /* Replays */>((*p_0)) };
                          Pointer id_654 { ssum_dst_759.writeU16Le(id_653) };
                          choose_res_652 = id_654;
                        } else {
                          uint16_t id_655 { 9 };
                          bool id_656 { bool(id_655 == label1_758) };
                          Pointer choose_res_657;
                          if (id_656) {
                            std::optional<dessser::gen::sync_socket::t_ext> id_658 { std::get<9 /* Error */>((*p_0)) };
                            bool id_659 { !(id_658.has_value ()) };
                            Pointer choose_res_660;
                            if (id_659) {
                              uint8_t id_661 { 1 };
                              Pointer id_662 { ssum_dst_759.writeU8(id_661) };
                              choose_res_660 = id_662;
                            } else {
                              auto fun663 { dessser::gen::sync_socket::to_row_binary };
                              std::optional<dessser::gen::sync_socket::t_ext> id_664 { std::get<9 /* Error */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_665 { id_664.value() };
                              uint8_t id_666 { 0 };
                              Pointer id_667 { ssum_dst_759.writeU8(id_666) };
                              Pointer id_668 { fun663(id_665, id_667) };
                              choose_res_660 = id_668;
                            }
                            choose_res_657 = choose_res_660;
                          } else {
                            uint16_t id_669 { 10 };
                            bool id_670 { bool(id_669 == label1_758) };
                            Pointer choose_res_671;
                            if (id_670) {
                              choose_res_671 = ssum_dst_759;
                            } else {
                              uint16_t id_672 { 11 };
                              bool id_673 { bool(id_672 == label1_758) };
                              Pointer choose_res_674;
                              if (id_673) {
                                auto fun675 { dessser::gen::sync_socket::to_row_binary };
                                ::dessser::gen::sync_key::t3f175f4a6fba6fdb7dfcec615c7c9650 id_676 { std::get<11 /* PerClient */>((*p_0)) };
                                dessser::gen::sync_socket::t_ext id_677 { std::get<0>(id_676) };
                                Pointer id_678 { fun675(id_677, ssum_dst_759) };
                                Pointer let_res_679;
                                {
                                  Pointer stup_dst_783 { id_678 };
                                  ::dessser::gen::sync_key::t3f175f4a6fba6fdb7dfcec615c7c9650 id_680 { std::get<11 /* PerClient */>((*p_0)) };
                                  ::dessser::gen::sync_key::per_client* id_681 { std::get<1>(id_680) };
                                  Pointer id_682 { per_client_to_row_binary(id_681, stup_dst_783) };
                                  let_res_679 = id_682;
                                }
                                choose_res_674 = let_res_679;
                              } else {
                                uint16_t id_683 { 12 };
                                bool id_684 { bool(id_683 == label1_758) };
                                Pointer choose_res_685;
                                if (id_684) {
                                  ::dessser::gen::sync_key::ta2544ee31f0dcf915e9425cc06777d2f id_686 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_687 { std::get<0>(id_686) };
                                  uint32_t id_688 { (uint32_t)id_687.size() };
                                  Vec<1, uint32_t> id_689 {  id_688  };
                                  Pointer let_res_690;
                                  {
                                    Vec<1, uint32_t> leb128_sz_780 { id_689 };
                                    Vec<1, Pointer> id_691 {  ssum_dst_759  };
                                    Pointer let_res_692;
                                    {
                                      Vec<1, Pointer> leb128_ptr_781 { id_691 };
                                      bool while_flag_693 { true };
                                      do {
                                        uint8_t id_694 { 0 };
                                        uint8_t id_695 { 0 };
                                        Pointer id_696 { leb128_ptr_781[id_695] };
                                        uint32_t id_697 { 128U };
                                        uint8_t id_698 { 0 };
                                        uint32_t id_699 { leb128_sz_780[id_698] };
                                        bool id_700 { bool(id_697 > id_699) };
                                        uint8_t choose_res_701;
                                        if (id_700) {
                                          uint8_t id_702 { 0 };
                                          uint32_t id_703 { leb128_sz_780[id_702] };
                                          uint8_t id_704 { uint8_t(id_703) };
                                          choose_res_701 = id_704;
                                        } else {
                                          uint8_t id_705 { 0 };
                                          uint32_t id_706 { leb128_sz_780[id_705] };
                                          uint8_t id_707 { uint8_t(id_706) };
                                          uint8_t id_708 { 128 };
                                          uint8_t id_709 { uint8_t(id_707 | id_708) };
                                          choose_res_701 = id_709;
                                        }
                                        Pointer id_710 { id_696.writeU8(choose_res_701) };
                                        Void id_711 { ((void)(leb128_ptr_781[id_694] = id_710), VOID) };
                                        (void)id_711;
                                        uint8_t id_712 { 0 };
                                        uint8_t id_713 { 0 };
                                        uint32_t id_714 { leb128_sz_780[id_713] };
                                        uint8_t id_715 { 7 };
                                        uint32_t id_716 { uint32_t(id_714 >> id_715) };
                                        Void id_717 { ((void)(leb128_sz_780[id_712] = id_716), VOID) };
                                        (void)id_717;
                                        uint8_t id_718 { 0 };
                                        uint32_t id_719 { leb128_sz_780[id_718] };
                                        uint32_t id_720 { 0U };
                                        bool id_721 { bool(id_719 > id_720) };
                                        while_flag_693 = id_721;
                                        if (while_flag_693) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_693);
                                      (void)VOID;
                                      uint8_t id_722 { 0 };
                                      Pointer id_723 { leb128_ptr_781[id_722] };
                                      let_res_692 = id_723;
                                    }
                                    let_res_690 = let_res_692;
                                  }
                                  ::dessser::gen::sync_key::ta2544ee31f0dcf915e9425cc06777d2f id_724 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_725 { std::get<0>(id_724) };
                                  Bytes id_726 { id_725 };
                                  Pointer id_727 { let_res_690.writeBytes(id_726) };
                                  Pointer let_res_728;
                                  {
                                    Pointer stup_dst_782 { id_727 };
                                    ::dessser::gen::sync_key::ta2544ee31f0dcf915e9425cc06777d2f id_729 { std::get<12 /* Dashboards */>((*p_0)) };
                                    per_dash_key* id_730 { std::get<1>(id_729) };
                                    Pointer id_731 { per_dash_key_to_row_binary(id_730, stup_dst_782) };
                                    let_res_728 = id_731;
                                  }
                                  choose_res_685 = let_res_728;
                                } else {
                                  uint16_t id_732 { 13 };
                                  bool id_733 { bool(id_732 == label1_758) };
                                  Pointer choose_res_734;
                                  if (id_733) {
                                    choose_res_734 = ssum_dst_759;
                                  } else {
                                    uint16_t id_735 { 14 };
                                    bool id_736 { bool(id_735 == label1_758) };
                                    Pointer choose_res_737;
                                    if (id_736) {
                                      ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_738 { std::get<14 /* Teams */>((*p_0)) };
                                      std::string id_739 { std::get<0>(id_738) };
                                      uint32_t id_740 { (uint32_t)id_739.size() };
                                      Vec<1, uint32_t> id_741 {  id_740  };
                                      Pointer let_res_742;
                                      {
                                        Vec<1, uint32_t> leb128_sz_771 { id_741 };
                                        Vec<1, Pointer> id_743 {  ssum_dst_759  };
                                        Pointer let_res_744;
                                        {
                                          Vec<1, Pointer> leb128_ptr_772 { id_743 };
                                          bool while_flag_745 { true };
                                          do {
                                            uint8_t id_746 { 0 };
                                            uint8_t id_747 { 0 };
                                            Pointer id_748 { leb128_ptr_772[id_747] };
                                            uint32_t id_749 { 128U };
                                            uint8_t id_750 { 0 };
                                            uint32_t id_751 { leb128_sz_771[id_750] };
                                            bool id_752 { bool(id_749 > id_751) };
                                            uint8_t choose_res_753;
                                            if (id_752) {
                                              uint8_t id_754 { 0 };
                                              uint32_t id_755 { leb128_sz_771[id_754] };
                                              uint8_t id_756 { uint8_t(id_755) };
                                              choose_res_753 = id_756;
                                            } else {
                                              uint8_t id_757 { 0 };
                                              uint32_t id_758 { leb128_sz_771[id_757] };
                                              uint8_t id_759 { uint8_t(id_758) };
                                              uint8_t id_760 { 128 };
                                              uint8_t id_761 { uint8_t(id_759 | id_760) };
                                              choose_res_753 = id_761;
                                            }
                                            Pointer id_762 { id_748.writeU8(choose_res_753) };
                                            Void id_763 { ((void)(leb128_ptr_772[id_746] = id_762), VOID) };
                                            (void)id_763;
                                            uint8_t id_764 { 0 };
                                            uint8_t id_765 { 0 };
                                            uint32_t id_766 { leb128_sz_771[id_765] };
                                            uint8_t id_767 { 7 };
                                            uint32_t id_768 { uint32_t(id_766 >> id_767) };
                                            Void id_769 { ((void)(leb128_sz_771[id_764] = id_768), VOID) };
                                            (void)id_769;
                                            uint8_t id_770 { 0 };
                                            uint32_t id_771 { leb128_sz_771[id_770] };
                                            uint32_t id_772 { 0U };
                                            bool id_773 { bool(id_771 > id_772) };
                                            while_flag_745 = id_773;
                                            if (while_flag_745) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_745);
                                          (void)VOID;
                                          uint8_t id_774 { 0 };
                                          Pointer id_775 { leb128_ptr_772[id_774] };
                                          let_res_744 = id_775;
                                        }
                                        let_res_742 = let_res_744;
                                      }
                                      ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_776 { std::get<14 /* Teams */>((*p_0)) };
                                      std::string id_777 { std::get<0>(id_776) };
                                      Bytes id_778 { id_777 };
                                      Pointer id_779 { let_res_742.writeBytes(id_778) };
                                      Pointer let_res_780;
                                      {
                                        Pointer stup_dst_773 { id_779 };
                                        ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_781 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_782 { std::get<1>(id_781) };
                                        uint16_t id_783 { uint16_t(id_782.index()) };
                                        Pointer id_784 { stup_dst_773.writeU16Le(id_783) };
                                        Pointer let_res_785;
                                        {
                                          Pointer ssum_dst_775 { id_784 };
                                          uint16_t id_786 { 0 };
                                          ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_787 { std::get<14 /* Teams */>((*p_0)) };
                                          ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_788 { std::get<1>(id_787) };
                                          uint16_t id_789 { uint16_t(id_788.index()) };
                                          bool id_790 { bool(id_786 == id_789) };
                                          Pointer choose_res_791;
                                          if (id_790) {
                                            ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_792 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_793 { std::get<1>(id_792) };
                                            std::string id_794 { std::get<0 /* Contacts */>(id_793) };
                                            uint32_t id_795 { (uint32_t)id_794.size() };
                                            Vec<1, uint32_t> id_796 {  id_795  };
                                            Pointer let_res_797;
                                            {
                                              Vec<1, uint32_t> leb128_sz_778 { id_796 };
                                              Vec<1, Pointer> id_798 {  ssum_dst_775  };
                                              Pointer let_res_799;
                                              {
                                                Vec<1, Pointer> leb128_ptr_779 { id_798 };
                                                bool while_flag_800 { true };
                                                do {
                                                  uint8_t id_801 { 0 };
                                                  uint8_t id_802 { 0 };
                                                  Pointer id_803 { leb128_ptr_779[id_802] };
                                                  uint32_t id_804 { 128U };
                                                  uint8_t id_805 { 0 };
                                                  uint32_t id_806 { leb128_sz_778[id_805] };
                                                  bool id_807 { bool(id_804 > id_806) };
                                                  uint8_t choose_res_808;
                                                  if (id_807) {
                                                    uint8_t id_809 { 0 };
                                                    uint32_t id_810 { leb128_sz_778[id_809] };
                                                    uint8_t id_811 { uint8_t(id_810) };
                                                    choose_res_808 = id_811;
                                                  } else {
                                                    uint8_t id_812 { 0 };
                                                    uint32_t id_813 { leb128_sz_778[id_812] };
                                                    uint8_t id_814 { uint8_t(id_813) };
                                                    uint8_t id_815 { 128 };
                                                    uint8_t id_816 { uint8_t(id_814 | id_815) };
                                                    choose_res_808 = id_816;
                                                  }
                                                  Pointer id_817 { id_803.writeU8(choose_res_808) };
                                                  Void id_818 { ((void)(leb128_ptr_779[id_801] = id_817), VOID) };
                                                  (void)id_818;
                                                  uint8_t id_819 { 0 };
                                                  uint8_t id_820 { 0 };
                                                  uint32_t id_821 { leb128_sz_778[id_820] };
                                                  uint8_t id_822 { 7 };
                                                  uint32_t id_823 { uint32_t(id_821 >> id_822) };
                                                  Void id_824 { ((void)(leb128_sz_778[id_819] = id_823), VOID) };
                                                  (void)id_824;
                                                  uint8_t id_825 { 0 };
                                                  uint32_t id_826 { leb128_sz_778[id_825] };
                                                  uint32_t id_827 { 0U };
                                                  bool id_828 { bool(id_826 > id_827) };
                                                  while_flag_800 = id_828;
                                                  if (while_flag_800) {
                                                    (void)VOID;
                                                  }
                                                } while (while_flag_800);
                                                (void)VOID;
                                                uint8_t id_829 { 0 };
                                                Pointer id_830 { leb128_ptr_779[id_829] };
                                                let_res_799 = id_830;
                                              }
                                              let_res_797 = let_res_799;
                                            }
                                            ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_831 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_832 { std::get<1>(id_831) };
                                            std::string id_833 { std::get<0 /* Contacts */>(id_832) };
                                            Bytes id_834 { id_833 };
                                            Pointer id_835 { let_res_797.writeBytes(id_834) };
                                            choose_res_791 = id_835;
                                          } else {
                                            ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_836 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_837 { std::get<1>(id_836) };
                                            uint16_t id_838 { uint16_t(id_837.index()) };
                                            uint16_t id_839 { 1 };
                                            bool id_840 { bool(id_838 == id_839) };
                                            Void id_841 { ((void)(assert(id_840)), VOID) };
                                            (void)id_841;
                                            ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_842 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_843 { std::get<1>(id_842) };
                                            std::string id_844 { std::get<1 /* Inhibition */>(id_843) };
                                            uint32_t id_845 { (uint32_t)id_844.size() };
                                            Vec<1, uint32_t> id_846 {  id_845  };
                                            Pointer let_res_847;
                                            {
                                              Vec<1, uint32_t> leb128_sz_776 { id_846 };
                                              Vec<1, Pointer> id_848 {  ssum_dst_775  };
                                              Pointer let_res_849;
                                              {
                                                Vec<1, Pointer> leb128_ptr_777 { id_848 };
                                                bool while_flag_850 { true };
                                                do {
                                                  uint8_t id_851 { 0 };
                                                  uint8_t id_852 { 0 };
                                                  Pointer id_853 { leb128_ptr_777[id_852] };
                                                  uint32_t id_854 { 128U };
                                                  uint8_t id_855 { 0 };
                                                  uint32_t id_856 { leb128_sz_776[id_855] };
                                                  bool id_857 { bool(id_854 > id_856) };
                                                  uint8_t choose_res_858;
                                                  if (id_857) {
                                                    uint8_t id_859 { 0 };
                                                    uint32_t id_860 { leb128_sz_776[id_859] };
                                                    uint8_t id_861 { uint8_t(id_860) };
                                                    choose_res_858 = id_861;
                                                  } else {
                                                    uint8_t id_862 { 0 };
                                                    uint32_t id_863 { leb128_sz_776[id_862] };
                                                    uint8_t id_864 { uint8_t(id_863) };
                                                    uint8_t id_865 { 128 };
                                                    uint8_t id_866 { uint8_t(id_864 | id_865) };
                                                    choose_res_858 = id_866;
                                                  }
                                                  Pointer id_867 { id_853.writeU8(choose_res_858) };
                                                  Void id_868 { ((void)(leb128_ptr_777[id_851] = id_867), VOID) };
                                                  (void)id_868;
                                                  uint8_t id_869 { 0 };
                                                  uint8_t id_870 { 0 };
                                                  uint32_t id_871 { leb128_sz_776[id_870] };
                                                  uint8_t id_872 { 7 };
                                                  uint32_t id_873 { uint32_t(id_871 >> id_872) };
                                                  Void id_874 { ((void)(leb128_sz_776[id_869] = id_873), VOID) };
                                                  (void)id_874;
                                                  uint8_t id_875 { 0 };
                                                  uint32_t id_876 { leb128_sz_776[id_875] };
                                                  uint32_t id_877 { 0U };
                                                  bool id_878 { bool(id_876 > id_877) };
                                                  while_flag_850 = id_878;
                                                  if (while_flag_850) {
                                                    (void)VOID;
                                                  }
                                                } while (while_flag_850);
                                                (void)VOID;
                                                uint8_t id_879 { 0 };
                                                Pointer id_880 { leb128_ptr_777[id_879] };
                                                let_res_849 = id_880;
                                              }
                                              let_res_847 = let_res_849;
                                            }
                                            ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_881 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_882 { std::get<1>(id_881) };
                                            std::string id_883 { std::get<1 /* Inhibition */>(id_882) };
                                            Bytes id_884 { id_883 };
                                            Pointer id_885 { let_res_847.writeBytes(id_884) };
                                            choose_res_791 = id_885;
                                          }
                                          let_res_785 = choose_res_791;
                                        }
                                        let_res_780 = let_res_785;
                                      }
                                      choose_res_737 = let_res_780;
                                    } else {
                                      uint16_t id_886 { 15 };
                                      bool id_887 { bool(label1_758 == id_886) };
                                      Void id_888 { ((void)(assert(id_887)), VOID) };
                                      (void)id_888;
                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_889 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_890 { std::get<0>(id_889) };
                                      uint32_t id_891 { (uint32_t)id_890.size() };
                                      Vec<1, uint32_t> id_892 {  id_891  };
                                      Pointer let_res_893;
                                      {
                                        Vec<1, uint32_t> leb128_sz_760 { id_892 };
                                        Vec<1, Pointer> id_894 {  ssum_dst_759  };
                                        Pointer let_res_895;
                                        {
                                          Vec<1, Pointer> leb128_ptr_761 { id_894 };
                                          bool while_flag_896 { true };
                                          do {
                                            uint8_t id_897 { 0 };
                                            uint8_t id_898 { 0 };
                                            Pointer id_899 { leb128_ptr_761[id_898] };
                                            uint32_t id_900 { 128U };
                                            uint8_t id_901 { 0 };
                                            uint32_t id_902 { leb128_sz_760[id_901] };
                                            bool id_903 { bool(id_900 > id_902) };
                                            uint8_t choose_res_904;
                                            if (id_903) {
                                              uint8_t id_905 { 0 };
                                              uint32_t id_906 { leb128_sz_760[id_905] };
                                              uint8_t id_907 { uint8_t(id_906) };
                                              choose_res_904 = id_907;
                                            } else {
                                              uint8_t id_908 { 0 };
                                              uint32_t id_909 { leb128_sz_760[id_908] };
                                              uint8_t id_910 { uint8_t(id_909) };
                                              uint8_t id_911 { 128 };
                                              uint8_t id_912 { uint8_t(id_910 | id_911) };
                                              choose_res_904 = id_912;
                                            }
                                            Pointer id_913 { id_899.writeU8(choose_res_904) };
                                            Void id_914 { ((void)(leb128_ptr_761[id_897] = id_913), VOID) };
                                            (void)id_914;
                                            uint8_t id_915 { 0 };
                                            uint8_t id_916 { 0 };
                                            uint32_t id_917 { leb128_sz_760[id_916] };
                                            uint8_t id_918 { 7 };
                                            uint32_t id_919 { uint32_t(id_917 >> id_918) };
                                            Void id_920 { ((void)(leb128_sz_760[id_915] = id_919), VOID) };
                                            (void)id_920;
                                            uint8_t id_921 { 0 };
                                            uint32_t id_922 { leb128_sz_760[id_921] };
                                            uint32_t id_923 { 0U };
                                            bool id_924 { bool(id_922 > id_923) };
                                            while_flag_896 = id_924;
                                            if (while_flag_896) {
                                              (void)VOID;
                                            }
                                          } while (while_flag_896);
                                          (void)VOID;
                                          uint8_t id_925 { 0 };
                                          Pointer id_926 { leb128_ptr_761[id_925] };
                                          let_res_895 = id_926;
                                        }
                                        let_res_893 = let_res_895;
                                      }
                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_927 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_928 { std::get<0>(id_927) };
                                      Bytes id_929 { id_928 };
                                      Pointer id_930 { let_res_893.writeBytes(id_929) };
                                      Pointer let_res_931;
                                      {
                                        Pointer stup_dst_762 { id_930 };
                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_932 { std::get<15 /* Incidents */>((*p_0)) };
                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_933 { std::get<1>(id_932) };
                                        uint16_t id_934 { uint16_t(id_933.index()) };
                                        Pointer let_res_935;
                                        {
                                          uint16_t label1_763 { id_934 };
                                          Pointer id_936 { stup_dst_762.writeU16Le(label1_763) };
                                          Pointer let_res_937;
                                          {
                                            Pointer ssum_dst_764 { id_936 };
                                            uint16_t id_938 { 0 };
                                            bool id_939 { bool(id_938 == label1_763) };
                                            Pointer choose_res_940;
                                            if (id_939) {
                                              choose_res_940 = ssum_dst_764;
                                            } else {
                                              uint16_t id_941 { 1 };
                                              bool id_942 { bool(id_941 == label1_763) };
                                              Pointer choose_res_943;
                                              if (id_942) {
                                                choose_res_943 = ssum_dst_764;
                                              } else {
                                                uint16_t id_944 { 2 };
                                                bool id_945 { bool(id_944 == label1_763) };
                                                Pointer choose_res_946;
                                                if (id_945) {
                                                  choose_res_946 = ssum_dst_764;
                                                } else {
                                                  uint16_t id_947 { 3 };
                                                  bool id_948 { bool(id_947 == label1_763) };
                                                  Pointer choose_res_949;
                                                  if (id_948) {
                                                    choose_res_949 = ssum_dst_764;
                                                  } else {
                                                    uint16_t id_950 { 4 };
                                                    bool id_951 { bool(id_950 == label1_763) };
                                                    Pointer choose_res_952;
                                                    if (id_951) {
                                                      choose_res_952 = ssum_dst_764;
                                                    } else {
                                                      uint16_t id_953 { 5 };
                                                      bool id_954 { bool(id_953 == label1_763) };
                                                      Pointer choose_res_955;
                                                      if (id_954) {
                                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_956 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_957 { std::get<1>(id_956) };
                                                        ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_958 { std::get<5 /* Dialogs */>(id_957) };
                                                        std::string id_959 { std::get<0>(id_958) };
                                                        uint32_t id_960 { (uint32_t)id_959.size() };
                                                        Vec<1, uint32_t> id_961 {  id_960  };
                                                        Pointer let_res_962;
                                                        {
                                                          Vec<1, uint32_t> leb128_sz_766 { id_961 };
                                                          Vec<1, Pointer> id_963 {  ssum_dst_764  };
                                                          Pointer let_res_964;
                                                          {
                                                            Vec<1, Pointer> leb128_ptr_767 { id_963 };
                                                            bool while_flag_965 { true };
                                                            do {
                                                              uint8_t id_966 { 0 };
                                                              uint8_t id_967 { 0 };
                                                              Pointer id_968 { leb128_ptr_767[id_967] };
                                                              uint32_t id_969 { 128U };
                                                              uint8_t id_970 { 0 };
                                                              uint32_t id_971 { leb128_sz_766[id_970] };
                                                              bool id_972 { bool(id_969 > id_971) };
                                                              uint8_t choose_res_973;
                                                              if (id_972) {
                                                                uint8_t id_974 { 0 };
                                                                uint32_t id_975 { leb128_sz_766[id_974] };
                                                                uint8_t id_976 { uint8_t(id_975) };
                                                                choose_res_973 = id_976;
                                                              } else {
                                                                uint8_t id_977 { 0 };
                                                                uint32_t id_978 { leb128_sz_766[id_977] };
                                                                uint8_t id_979 { uint8_t(id_978) };
                                                                uint8_t id_980 { 128 };
                                                                uint8_t id_981 { uint8_t(id_979 | id_980) };
                                                                choose_res_973 = id_981;
                                                              }
                                                              Pointer id_982 { id_968.writeU8(choose_res_973) };
                                                              Void id_983 { ((void)(leb128_ptr_767[id_966] = id_982), VOID) };
                                                              (void)id_983;
                                                              uint8_t id_984 { 0 };
                                                              uint8_t id_985 { 0 };
                                                              uint32_t id_986 { leb128_sz_766[id_985] };
                                                              uint8_t id_987 { 7 };
                                                              uint32_t id_988 { uint32_t(id_986 >> id_987) };
                                                              Void id_989 { ((void)(leb128_sz_766[id_984] = id_988), VOID) };
                                                              (void)id_989;
                                                              uint8_t id_990 { 0 };
                                                              uint32_t id_991 { leb128_sz_766[id_990] };
                                                              uint32_t id_992 { 0U };
                                                              bool id_993 { bool(id_991 > id_992) };
                                                              while_flag_965 = id_993;
                                                              if (while_flag_965) {
                                                                (void)VOID;
                                                              }
                                                            } while (while_flag_965);
                                                            (void)VOID;
                                                            uint8_t id_994 { 0 };
                                                            Pointer id_995 { leb128_ptr_767[id_994] };
                                                            let_res_964 = id_995;
                                                          }
                                                          let_res_962 = let_res_964;
                                                        }
                                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_996 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_997 { std::get<1>(id_996) };
                                                        ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_998 { std::get<5 /* Dialogs */>(id_997) };
                                                        std::string id_999 { std::get<0>(id_998) };
                                                        Bytes id_1000 { id_999 };
                                                        Pointer id_1001 { let_res_962.writeBytes(id_1000) };
                                                        Pointer let_res_1002;
                                                        {
                                                          Pointer stup_dst_768 { id_1001 };
                                                          ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1003 { std::get<15 /* Incidents */>((*p_0)) };
                                                          ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1004 { std::get<1>(id_1003) };
                                                          ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_1005 { std::get<5 /* Dialogs */>(id_1004) };
                                                          ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_1006 { std::get<1>(id_1005) };
                                                          uint16_t id_1007 { uint16_t(id_1006.index()) };
                                                          Pointer let_res_1008;
                                                          {
                                                            uint16_t label1_769 { id_1007 };
                                                            Pointer id_1009 { stup_dst_768.writeU16Le(label1_769) };
                                                            Pointer let_res_1010;
                                                            {
                                                              Pointer ssum_dst_770 { id_1009 };
                                                              uint16_t id_1011 { 0 };
                                                              bool id_1012 { bool(id_1011 == label1_769) };
                                                              Pointer choose_res_1013;
                                                              if (id_1012) {
                                                                choose_res_1013 = ssum_dst_770;
                                                              } else {
                                                                uint16_t id_1014 { 1 };
                                                                bool id_1015 { bool(id_1014 == label1_769) };
                                                                Pointer choose_res_1016;
                                                                if (id_1015) {
                                                                  choose_res_1016 = ssum_dst_770;
                                                                } else {
                                                                  uint16_t id_1017 { 2 };
                                                                  bool id_1018 { bool(id_1017 == label1_769) };
                                                                  Pointer choose_res_1019;
                                                                  if (id_1018) {
                                                                    choose_res_1019 = ssum_dst_770;
                                                                  } else {
                                                                    uint16_t id_1020 { 3 };
                                                                    bool id_1021 { bool(id_1020 == label1_769) };
                                                                    Pointer choose_res_1022;
                                                                    if (id_1021) {
                                                                      choose_res_1022 = ssum_dst_770;
                                                                    } else {
                                                                      uint16_t id_1023 { 4 };
                                                                      bool id_1024 { bool(id_1023 == label1_769) };
                                                                      Pointer choose_res_1025;
                                                                      if (id_1024) {
                                                                        choose_res_1025 = ssum_dst_770;
                                                                      } else {
                                                                        uint16_t id_1026 { 5 };
                                                                        bool id_1027 { bool(id_1026 == label1_769) };
                                                                        Pointer choose_res_1028;
                                                                        if (id_1027) {
                                                                          choose_res_1028 = ssum_dst_770;
                                                                        } else {
                                                                          uint16_t id_1029 { 6 };
                                                                          bool id_1030 { bool(label1_769 == id_1029) };
                                                                          Void id_1031 { ((void)(assert(id_1030)), VOID) };
                                                                          (void)id_1031;
                                                                          choose_res_1028 = ssum_dst_770;
                                                                        }
                                                                        choose_res_1025 = choose_res_1028;
                                                                      }
                                                                      choose_res_1022 = choose_res_1025;
                                                                    }
                                                                    choose_res_1019 = choose_res_1022;
                                                                  }
                                                                  choose_res_1016 = choose_res_1019;
                                                                }
                                                                choose_res_1013 = choose_res_1016;
                                                              }
                                                              let_res_1010 = choose_res_1013;
                                                            }
                                                            let_res_1008 = let_res_1010;
                                                          }
                                                          let_res_1002 = let_res_1008;
                                                        }
                                                        choose_res_955 = let_res_1002;
                                                      } else {
                                                        uint16_t id_1032 { 6 };
                                                        bool id_1033 { bool(label1_763 == id_1032) };
                                                        Void id_1034 { ((void)(assert(id_1033)), VOID) };
                                                        (void)id_1034;
                                                        ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1035 { std::get<15 /* Incidents */>((*p_0)) };
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1036 { std::get<1>(id_1035) };
                                                        ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 id_1037 { std::get<6 /* Journal */>(id_1036) };
                                                        double id_1038 { std::get<0>(id_1037) };
                                                        uint64_t id_1039 { qword_of_float(id_1038) };
                                                        Pointer id_1040 { ssum_dst_764.writeU64Le(id_1039) };
                                                        Pointer let_res_1041;
                                                        {
                                                          Pointer stup_dst_765 { id_1040 };
                                                          ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1042 { std::get<15 /* Incidents */>((*p_0)) };
                                                          ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1043 { std::get<1>(id_1042) };
                                                          ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 id_1044 { std::get<6 /* Journal */>(id_1043) };
                                                          uint32_t id_1045 { std::get<1>(id_1044) };
                                                          Pointer id_1046 { stup_dst_765.writeU32Le(id_1045) };
                                                          let_res_1041 = id_1046;
                                                        }
                                                        choose_res_955 = let_res_1041;
                                                      }
                                                      choose_res_952 = choose_res_955;
                                                    }
                                                    choose_res_949 = choose_res_952;
                                                  }
                                                  choose_res_946 = choose_res_949;
                                                }
                                                choose_res_943 = choose_res_946;
                                              }
                                              choose_res_940 = choose_res_943;
                                            }
                                            let_res_937 = choose_res_940;
                                          }
                                          let_res_935 = let_res_937;
                                        }
                                        let_res_931 = let_res_935;
                                      }
                                      choose_res_737 = let_res_931;
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
std::function<Pointer(::dessser::gen::sync_key::t*,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[Widgets U32]") (seq (assert (eq (label-of (param 0)) (u16 0))) (size 6)))
 */
static std::function<Size(::dessser::gen::sync_key::per_dash_key*)> per_dash_key_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::per_dash_key*)> fun1047 { [&fun1047](::dessser::gen::sync_key::per_dash_key* p_0) {
    uint16_t id_1048 { uint16_t((*p_0).index()) };
    uint16_t id_1049 { 0 };
    bool id_1050 { bool(id_1048 == id_1049) };
    Void id_1051 { ((void)(assert(id_1050)), VOID) };
    (void)id_1051;
    Size id_1052 { 6UL };
    return id_1052;
  }
   };
  return fun1047;
}
std::function<Size(::dessser::gen::sync_key::per_dash_key*)> per_dash_key_sersize_of_row_binary(per_dash_key_sersize_of_row_binary_init());

/* 
    (fun ("[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_669" (make-vec (string-length (get-alt "Response" (param 0))))
              (let "lebsz_ref_670" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_669")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_670")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_670") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_670")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_670")))))) 
            (size-of-u32 (string-length (get-alt "Response" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "per_dash_key-sersize-of-row-binary") (get-alt "Scratchpad" (param 0)))))))
 */
static std::function<Size(::dessser::gen::sync_key::per_client*)> per_client_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::per_client*)> fun1053 { [&fun1053](::dessser::gen::sync_key::per_client* p_0) {
    uint16_t id_1054 { 0 };
    uint16_t id_1055 { uint16_t((*p_0).index()) };
    bool id_1056 { bool(id_1054 == id_1055) };
    Size choose_res_1057;
    if (id_1056) {
      Size id_1058 { 2UL };
      std::string id_1059 { std::get<0 /* Response */>((*p_0)) };
      uint32_t id_1060 { (uint32_t)id_1059.size() };
      Vec<1, uint32_t> id_1061 {  id_1060  };
      Size let_res_1062;
      {
        Vec<1, uint32_t> n_ref_669 { id_1061 };
        uint32_t id_1063 { 1U };
        Vec<1, uint32_t> id_1064 {  id_1063  };
        Size let_res_1065;
        {
          Vec<1, uint32_t> lebsz_ref_670 { id_1064 };
          bool while_flag_1066 { true };
          do {
            uint8_t id_1067 { 0 };
            uint32_t id_1068 { n_ref_669[id_1067] };
            uint8_t id_1069 { 0 };
            uint32_t id_1070 { lebsz_ref_670[id_1069] };
            uint8_t id_1071 { 7 };
            uint32_t id_1072 { uint32_t(id_1070 << id_1071) };
            bool id_1073 { bool(id_1068 >= id_1072) };
            while_flag_1066 = id_1073;
            if (while_flag_1066) {
              uint8_t id_1074 { 0 };
              uint8_t id_1075 { 0 };
              uint32_t id_1076 { lebsz_ref_670[id_1075] };
              uint32_t id_1077 { 1U };
              uint32_t id_1078 { uint32_t(id_1076 + id_1077) };
              Void id_1079 { ((void)(lebsz_ref_670[id_1074] = id_1078), VOID) };
              (void)id_1079;
            }
          } while (while_flag_1066);
          (void)VOID;
          uint8_t id_1080 { 0 };
          uint32_t id_1081 { lebsz_ref_670[id_1080] };
          Size id_1082 { Size(id_1081) };
          let_res_1065 = id_1082;
        }
        let_res_1062 = let_res_1065;
      }
      std::string id_1083 { std::get<0 /* Response */>((*p_0)) };
      uint32_t id_1084 { (uint32_t)id_1083.size() };
      Size id_1085 { Size(id_1084) };
      Size id_1086 { Size(let_res_1062 + id_1085) };
      Size id_1087 { Size(id_1058 + id_1086) };
      choose_res_1057 = id_1087;
    } else {
      uint16_t id_1088 { uint16_t((*p_0).index()) };
      uint16_t id_1089 { 1 };
      bool id_1090 { bool(id_1088 == id_1089) };
      Void id_1091 { ((void)(assert(id_1090)), VOID) };
      (void)id_1091;
      Size id_1092 { 2UL };
      ::dessser::gen::sync_key::per_dash_key* id_1093 { std::get<1 /* Scratchpad */>((*p_0)) };
      Size id_1094 { per_dash_key_sersize_of_row_binary(id_1093) };
      Size id_1095 { Size(id_1092 + id_1094) };
      choose_res_1057 = id_1095;
    }
    return choose_res_1057;
  }
   };
  return fun1053;
}
std::function<Size(::dessser::gen::sync_key::per_client*)> per_client_sersize_of_row_binary(per_client_sersize_of_row_binary_init());

/* 
    (fun ("[Subscriber STRING | LastTuple U32]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_664" (make-vec (string-length (get-alt "Subscriber" (param 0))))
              (let "lebsz_ref_665" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_664")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_665")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_665") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_665")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_665")))))) 
            (size-of-u32 (string-length (get-alt "Subscriber" (param 0)))))) 
        (seq (assert (eq (label-of (param 0)) (u16 1))) (size 6))))
 */
static std::function<Size(::dessser::gen::sync_key::per_tail*)> per_tail_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::per_tail*)> fun1096 { [&fun1096](::dessser::gen::sync_key::per_tail* p_0) {
    uint16_t id_1097 { 0 };
    uint16_t id_1098 { uint16_t((*p_0).index()) };
    bool id_1099 { bool(id_1097 == id_1098) };
    Size choose_res_1100;
    if (id_1099) {
      Size id_1101 { 2UL };
      std::string id_1102 { std::get<0 /* Subscriber */>((*p_0)) };
      uint32_t id_1103 { (uint32_t)id_1102.size() };
      Vec<1, uint32_t> id_1104 {  id_1103  };
      Size let_res_1105;
      {
        Vec<1, uint32_t> n_ref_664 { id_1104 };
        uint32_t id_1106 { 1U };
        Vec<1, uint32_t> id_1107 {  id_1106  };
        Size let_res_1108;
        {
          Vec<1, uint32_t> lebsz_ref_665 { id_1107 };
          bool while_flag_1109 { true };
          do {
            uint8_t id_1110 { 0 };
            uint32_t id_1111 { n_ref_664[id_1110] };
            uint8_t id_1112 { 0 };
            uint32_t id_1113 { lebsz_ref_665[id_1112] };
            uint8_t id_1114 { 7 };
            uint32_t id_1115 { uint32_t(id_1113 << id_1114) };
            bool id_1116 { bool(id_1111 >= id_1115) };
            while_flag_1109 = id_1116;
            if (while_flag_1109) {
              uint8_t id_1117 { 0 };
              uint8_t id_1118 { 0 };
              uint32_t id_1119 { lebsz_ref_665[id_1118] };
              uint32_t id_1120 { 1U };
              uint32_t id_1121 { uint32_t(id_1119 + id_1120) };
              Void id_1122 { ((void)(lebsz_ref_665[id_1117] = id_1121), VOID) };
              (void)id_1122;
            }
          } while (while_flag_1109);
          (void)VOID;
          uint8_t id_1123 { 0 };
          uint32_t id_1124 { lebsz_ref_665[id_1123] };
          Size id_1125 { Size(id_1124) };
          let_res_1108 = id_1125;
        }
        let_res_1105 = let_res_1108;
      }
      std::string id_1126 { std::get<0 /* Subscriber */>((*p_0)) };
      uint32_t id_1127 { (uint32_t)id_1126.size() };
      Size id_1128 { Size(id_1127) };
      Size id_1129 { Size(let_res_1105 + id_1128) };
      Size id_1130 { Size(id_1101 + id_1129) };
      choose_res_1100 = id_1130;
    } else {
      uint16_t id_1131 { uint16_t((*p_0).index()) };
      uint16_t id_1132 { 1 };
      bool id_1133 { bool(id_1131 == id_1132) };
      Void id_1134 { ((void)(assert(id_1133)), VOID) };
      (void)id_1134;
      Size id_1135 { 6UL };
      choose_res_1100 = id_1135;
    }
    return choose_res_1100;
  }
   };
  return fun1096;
}
std::function<Size(::dessser::gen::sync_key::per_tail*)> per_tail_sersize_of_row_binary(per_tail_sersize_of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]")
      (let "label2_671" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_671")) (size 2)
          (if (eq (u16 1) (identifier "label2_671")) (size 2)
            (if (eq (u16 2) (identifier "label2_671"))
              (add (size 2)
                (add
                  (let "n_ref_746" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "lebsz_ref_747" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_746")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_747")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_747") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_747")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_747")))))) 
                  (size-of-u32 (string-length (get-alt "Versions" (param 0))))))
              (if (eq (u16 3) (identifier "label2_671"))
                (let "sz_741" (add (size 2) (apply (ext-identifier src_path sersize-of-row-binary) (get-item 0 (get-alt "Sources" (param 0)))))
                  (add (identifier "sz_741")
                    (add
                      (let "n_ref_743" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "lebsz_ref_744" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_743")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_744")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_744") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_744")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_744")))))) 
                      (size-of-u32 (string-length (get-item 1 (get-alt "Sources" (param 0))))))))
                (if (eq (u16 4) (identifier "label2_671")) (size 2)
                  (if (eq (u16 5) (identifier "label2_671"))
                    (let "sz_717" (add (size 2) (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (get-alt "PerSite" (param 0)))))
                      (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerSite" (param 0))))) 
                        (add (identifier "sz_717") (size 2))
                        (if (eq (u16 1) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                          (let "sz_738"
                            (add (add (identifier "sz_717") (size 2))
                              (add
                                (let "n_ref_736" (make-vec (string-length (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                  (let "lebsz_ref_737" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_736")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_737")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_737") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_737")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_737")))))) 
                                (size-of-u32 (string-length (get-item 0 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                            (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0))))))) 
                              (add (identifier "sz_738") (size 2)) (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 1))) (add (identifier "sz_738") (size 2)))))
                          (if (eq (u16 2) (label-of (get-item 1 (get-alt "PerSite" (param 0)))))
                            (let "sz_726" (add (add (identifier "sz_717") (size 2)) (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 0 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))
                              (let "label2_727" (label-of (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))
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
                                              (let "sz_732"
                                                (add (add (identifier "sz_726") (size 2))
                                                  (add
                                                    (let "n_ref_730" 
                                                      (make-vec (string-length (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                                      (let "lebsz_ref_731" 
                                                        (make-vec (u32 1))
                                                        (seq
                                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_730")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_731")) (u8 7)))
                                                            (set-vec (u8 0) (identifier "lebsz_ref_731") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_731")) (u32 1))))
                                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_731"))))))
                                                    (size-of-u32 (string-length (get-item 0 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0)))))))))))
                                                (let "label2_733" (label-of (get-item 1 (get-alt "PerInstance" (get-item 1 (get-alt "PerWorker" (get-item 1 (get-alt "PerSite" (param 0))))))))
                                                  (if (eq (u16 0) (identifier "label2_733")) 
                                                    (add (identifier "sz_732") (size 2))
                                                    (if (eq (u16 1) (identifier "label2_733")) 
                                                      (add (identifier "sz_732") (size 2))
                                                      (if (eq (u16 2) (identifier "label2_733")) 
                                                        (add (identifier "sz_732") (size 2))
                                                        (if (eq (u16 3) (identifier "label2_733")) 
                                                          (add (identifier "sz_732") (size 2))
                                                          (if (eq (u16 4) (identifier "label2_733")) 
                                                            (add (identifier "sz_732") (size 2))
                                                            (if (eq (u16 5) (identifier "label2_733")) 
                                                              (add (identifier "sz_732") (size 2))
                                                              (if (eq (u16 6) (identifier "label2_733")) 
                                                                (add (identifier "sz_732") (size 2)) 
                                                                (seq (assert (eq (identifier "label2_733") (u16 7))) (add (identifier "sz_732") (size 2))))))))))))
                                              (if (eq (u16 7) (identifier "label2_727")) 
                                                (add (add (identifier "sz_726") (size 2)) (size 4)) 
                                                (seq (assert (eq (identifier "label2_727") (u16 8))) (add (identifier "sz_726") (size 2)))))))))))))
                            (seq (assert (eq (label-of (get-item 1 (get-alt "PerSite" (param 0)))) (u16 3)))
                              (let "sz_723"
                                (add (add (identifier "sz_717") (size 2))
                                  (add
                                    (let "n_ref_721" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))
                                      (let "lebsz_ref_722" (make-vec (u32 1))
                                        (seq
                                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_721")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_722")) (u8 7)))
                                            (set-vec (u8 0) (identifier "lebsz_ref_722") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_722")) (u32 1)))) 
                                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_722")))))) 
                                    (size-of-u32 (string-length (get-item 0 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))))))
                                (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (get-item 1 (get-alt "PerSite" (param 0)))))) (u16 0))) (add (identifier "sz_723") (size 2)))))))))
                    (if (eq (u16 6) (identifier "label2_671"))
                      (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                        (size 4)
                        (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                          (size 4)
                          (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                            (add (size 4)
                              (add
                                (let "n_ref_714" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                  (let "lebsz_ref_715" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_714")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_715")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_715") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_715")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_715")))))) 
                                (size-of-u32 (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0))))))))))
                      (if (eq (u16 7) (identifier "label2_671"))
                        (let "sz_711"
                          (let "sz_707"
                            (let "sz_706" (add (size 2) (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (get-alt "Tails" (param 0)))))
                              (add (identifier "sz_706") (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 1 (get-alt "Tails" (param 0))))))
                            (add (identifier "sz_707")
                              (add
                                (let "n_ref_709" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "lebsz_ref_710" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_709")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_710")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_710") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_710")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_710")))))) 
                                (size-of-u32 (string-length (get-item 2 (get-alt "Tails" (param 0)))))))) 
                          (add (identifier "sz_711") (apply (identifier "per_tail-sersize-of-row-binary") (get-item 3 (get-alt "Tails" (param 0))))))
                        (if (eq (u16 8) (identifier "label2_671")) (size 4)
                          (if (eq (u16 9) (identifier "label2_671"))
                            (if (is-null (get-alt "Error" (param 0))) (size 3) (add (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (force (get-alt "Error" (param 0))))) (size 1)))
                            (if (eq (u16 10) (identifier "label2_671")) 
                              (size 2)
                              (if (eq (u16 11) (identifier "label2_671"))
                                (let "sz_704" (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (get-item 0 (get-alt "PerClient" (param 0)))))
                                  (add (identifier "sz_704") (apply (identifier "per_client-sersize-of-row-binary") (get-item 1 (get-alt "PerClient" (param 0))))))
                                (if (eq (u16 12) (identifier "label2_671"))
                                  (let "sz_702"
                                    (add (size 2)
                                      (add
                                        (let "n_ref_700" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "lebsz_ref_701" (make-vec (u32 1))
                                            (seq
                                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_700")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_701")) (u8 7)))
                                                (set-vec (u8 0) (identifier "lebsz_ref_701") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_701")) (u32 1)))) 
                                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_701")))))) 
                                        (size-of-u32 (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))))
                                    (add (identifier "sz_702") (apply (identifier "per_dash_key-sersize-of-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))))))
                                  (if (eq (u16 13) (identifier "label2_671")) 
                                    (size 2)
                                    (if (eq (u16 14) (identifier "label2_671"))
                                      (let "sz_690"
                                        (add (size 2)
                                          (add
                                            (let "n_ref_688" (make-vec (string-length (get-item 0 (get-alt "Teams" (param 0)))))
                                              (let "lebsz_ref_689" (make-vec (u32 1))
                                                (seq
                                                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_688")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_689")) (u8 7)))
                                                    (set-vec (u8 0) (identifier "lebsz_ref_689") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_689")) (u32 1)))) 
                                                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_689")))))) 
                                            (size-of-u32 (string-length (get-item 0 (get-alt "Teams" (param 0)))))))
                                        (if (eq (u16 0) (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                          (add (add (identifier "sz_690") (size 2))
                                            (add
                                              (let "n_ref_696" (make-vec (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                                (let "lebsz_ref_697" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_696")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_697")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_697") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_697")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_697")))))) 
                                              (size-of-u32 (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))))
                                          (seq (assert (eq (label-of (get-item 1 (get-alt "Teams" (param 0)))) (u16 1)))
                                            (add (add (identifier "sz_690") (size 2))
                                              (add
                                                (let "n_ref_693" (make-vec (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))
                                                  (let "lebsz_ref_694" 
                                                    (make-vec (u32 1))
                                                    (seq
                                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_693")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_694")) (u8 7)))
                                                        (set-vec (u8 0) (identifier "lebsz_ref_694") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_694")) (u32 1)))) 
                                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_694")))))) 
                                                (size-of-u32 (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0)))))))))))
                                      (seq (assert (eq (identifier "label2_671") (u16 15)))
                                        (let "sz_676"
                                          (add (size 2)
                                            (add
                                              (let "n_ref_674" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "lebsz_ref_675" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_674")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_675")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_675") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_675")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_675")))))) 
                                              (size-of-u32 (string-length (get-item 0 (get-alt "Incidents" (param 0)))))))
                                          (let "label2_677" (label-of (get-item 1 (get-alt "Incidents" (param 0))))
                                            (if (eq (u16 0) (identifier "label2_677")) 
                                              (add (identifier "sz_676") (size 2))
                                              (if (eq (u16 1) (identifier "label2_677")) 
                                                (add (identifier "sz_676") (size 2))
                                                (if (eq (u16 2) (identifier "label2_677")) 
                                                  (add (identifier "sz_676") (size 2))
                                                  (if (eq (u16 3) (identifier "label2_677")) 
                                                    (add (identifier "sz_676") (size 2))
                                                    (if (eq (u16 4) (identifier "label2_677")) 
                                                      (add (identifier "sz_676") (size 2))
                                                      (if (eq (u16 5) (identifier "label2_677"))
                                                        (let "sz_684"
                                                          (add (add (identifier "sz_676") (size 2))
                                                            (add
                                                              (let "n_ref_682" 
                                                                (make-vec (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))
                                                                (let "lebsz_ref_683" 
                                                                  (make-vec (u32 1))
                                                                  (seq
                                                                    (while 
                                                                    (ge (unsafe-nth (u8 0) (identifier "n_ref_682")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_683")) (u8 7)))
                                                                    (set-vec (u8 0) (identifier "lebsz_ref_683") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_683")) (u32 1))))
                                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_683"))))))
                                                              (size-of-u32 (string-length (get-item 0 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0)))))))))
                                                          (let "label2_685" 
                                                            (label-of (get-item 1 (get-alt "Dialogs" (get-item 1 (get-alt "Incidents" (param 0))))))
                                                            (if (eq (u16 0) (identifier "label2_685")) 
                                                              (add (identifier "sz_684") (size 2))
                                                              (if (eq (u16 1) (identifier "label2_685")) 
                                                                (add (identifier "sz_684") (size 2))
                                                                (if (eq (u16 2) (identifier "label2_685")) 
                                                                  (add (identifier "sz_684") (size 2))
                                                                  (if 
                                                                    (eq (u16 3) (identifier "label2_685")) 
                                                                    (add (identifier "sz_684") (size 2))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "label2_685")) 
                                                                    (add (identifier "sz_684") (size 2))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "label2_685")) 
                                                                    (add (identifier "sz_684") (size 2)) 
                                                                    (seq (assert (eq (identifier "label2_685") (u16 6))) (add (identifier "sz_684") (size 2)))))))))))
                                                        (seq (assert (eq (identifier "label2_677") (u16 6))) (add (add (add (identifier "sz_676") (size 2)) (size 8)) (size 4)))))))))))))))))))))))))))))
 */
static std::function<Size(::dessser::gen::sync_key::t*)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::t*)> fun1136 { [&fun1136](::dessser::gen::sync_key::t* p_0) {
    uint16_t id_1137 { uint16_t((*p_0).index()) };
    Size let_res_1138;
    {
      uint16_t label2_671 { id_1137 };
      uint16_t id_1139 { 0 };
      bool id_1140 { bool(id_1139 == label2_671) };
      Size choose_res_1141;
      if (id_1140) {
        Size id_1142 { 2UL };
        choose_res_1141 = id_1142;
      } else {
        uint16_t id_1143 { 1 };
        bool id_1144 { bool(id_1143 == label2_671) };
        Size choose_res_1145;
        if (id_1144) {
          Size id_1146 { 2UL };
          choose_res_1145 = id_1146;
        } else {
          uint16_t id_1147 { 2 };
          bool id_1148 { bool(id_1147 == label2_671) };
          Size choose_res_1149;
          if (id_1148) {
            Size id_1150 { 2UL };
            std::string id_1151 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1152 { (uint32_t)id_1151.size() };
            Vec<1, uint32_t> id_1153 {  id_1152  };
            Size let_res_1154;
            {
              Vec<1, uint32_t> n_ref_746 { id_1153 };
              uint32_t id_1155 { 1U };
              Vec<1, uint32_t> id_1156 {  id_1155  };
              Size let_res_1157;
              {
                Vec<1, uint32_t> lebsz_ref_747 { id_1156 };
                bool while_flag_1158 { true };
                do {
                  uint8_t id_1159 { 0 };
                  uint32_t id_1160 { n_ref_746[id_1159] };
                  uint8_t id_1161 { 0 };
                  uint32_t id_1162 { lebsz_ref_747[id_1161] };
                  uint8_t id_1163 { 7 };
                  uint32_t id_1164 { uint32_t(id_1162 << id_1163) };
                  bool id_1165 { bool(id_1160 >= id_1164) };
                  while_flag_1158 = id_1165;
                  if (while_flag_1158) {
                    uint8_t id_1166 { 0 };
                    uint8_t id_1167 { 0 };
                    uint32_t id_1168 { lebsz_ref_747[id_1167] };
                    uint32_t id_1169 { 1U };
                    uint32_t id_1170 { uint32_t(id_1168 + id_1169) };
                    Void id_1171 { ((void)(lebsz_ref_747[id_1166] = id_1170), VOID) };
                    (void)id_1171;
                  }
                } while (while_flag_1158);
                (void)VOID;
                uint8_t id_1172 { 0 };
                uint32_t id_1173 { lebsz_ref_747[id_1172] };
                Size id_1174 { Size(id_1173) };
                let_res_1157 = id_1174;
              }
              let_res_1154 = let_res_1157;
            }
            std::string id_1175 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1176 { (uint32_t)id_1175.size() };
            Size id_1177 { Size(id_1176) };
            Size id_1178 { Size(let_res_1154 + id_1177) };
            Size id_1179 { Size(id_1150 + id_1178) };
            choose_res_1149 = id_1179;
          } else {
            uint16_t id_1180 { 3 };
            bool id_1181 { bool(id_1180 == label2_671) };
            Size choose_res_1182;
            if (id_1181) {
              Size id_1183 { 2UL };
              auto fun1184 { dessser::gen::src_path::sersize_of_row_binary };
              ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_1185 { std::get<3 /* Sources */>((*p_0)) };
              dessser::gen::src_path::t_ext id_1186 { std::get<0>(id_1185) };
              Size id_1187 { fun1184(id_1186) };
              Size id_1188 { Size(id_1183 + id_1187) };
              Size let_res_1189;
              {
                Size sz_741 { id_1188 };
                ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_1190 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1191 { std::get<1>(id_1190) };
                uint32_t id_1192 { (uint32_t)id_1191.size() };
                Vec<1, uint32_t> id_1193 {  id_1192  };
                Size let_res_1194;
                {
                  Vec<1, uint32_t> n_ref_743 { id_1193 };
                  uint32_t id_1195 { 1U };
                  Vec<1, uint32_t> id_1196 {  id_1195  };
                  Size let_res_1197;
                  {
                    Vec<1, uint32_t> lebsz_ref_744 { id_1196 };
                    bool while_flag_1198 { true };
                    do {
                      uint8_t id_1199 { 0 };
                      uint32_t id_1200 { n_ref_743[id_1199] };
                      uint8_t id_1201 { 0 };
                      uint32_t id_1202 { lebsz_ref_744[id_1201] };
                      uint8_t id_1203 { 7 };
                      uint32_t id_1204 { uint32_t(id_1202 << id_1203) };
                      bool id_1205 { bool(id_1200 >= id_1204) };
                      while_flag_1198 = id_1205;
                      if (while_flag_1198) {
                        uint8_t id_1206 { 0 };
                        uint8_t id_1207 { 0 };
                        uint32_t id_1208 { lebsz_ref_744[id_1207] };
                        uint32_t id_1209 { 1U };
                        uint32_t id_1210 { uint32_t(id_1208 + id_1209) };
                        Void id_1211 { ((void)(lebsz_ref_744[id_1206] = id_1210), VOID) };
                        (void)id_1211;
                      }
                    } while (while_flag_1198);
                    (void)VOID;
                    uint8_t id_1212 { 0 };
                    uint32_t id_1213 { lebsz_ref_744[id_1212] };
                    Size id_1214 { Size(id_1213) };
                    let_res_1197 = id_1214;
                  }
                  let_res_1194 = let_res_1197;
                }
                ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_1215 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1216 { std::get<1>(id_1215) };
                uint32_t id_1217 { (uint32_t)id_1216.size() };
                Size id_1218 { Size(id_1217) };
                Size id_1219 { Size(let_res_1194 + id_1218) };
                Size id_1220 { Size(sz_741 + id_1219) };
                let_res_1189 = id_1220;
              }
              choose_res_1182 = let_res_1189;
            } else {
              uint16_t id_1221 { 4 };
              bool id_1222 { bool(id_1221 == label2_671) };
              Size choose_res_1223;
              if (id_1222) {
                Size id_1224 { 2UL };
                choose_res_1223 = id_1224;
              } else {
                uint16_t id_1225 { 5 };
                bool id_1226 { bool(id_1225 == label2_671) };
                Size choose_res_1227;
                if (id_1226) {
                  Size id_1228 { 2UL };
                  auto fun1229 { dessser::gen::site_name::sersize_of_row_binary };
                  ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1230 { std::get<5 /* PerSite */>((*p_0)) };
                  dessser::gen::site_name::t_ext id_1231 { std::get<0>(id_1230) };
                  Size id_1232 { fun1229(id_1231) };
                  Size id_1233 { Size(id_1228 + id_1232) };
                  Size let_res_1234;
                  {
                    Size sz_717 { id_1233 };
                    uint16_t id_1235 { 0 };
                    ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1236 { std::get<5 /* PerSite */>((*p_0)) };
                    ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1237 { std::get<1>(id_1236) };
                    uint16_t id_1238 { uint16_t(id_1237.index()) };
                    bool id_1239 { bool(id_1235 == id_1238) };
                    Size choose_res_1240;
                    if (id_1239) {
                      Size id_1241 { 2UL };
                      Size id_1242 { Size(sz_717 + id_1241) };
                      choose_res_1240 = id_1242;
                    } else {
                      uint16_t id_1243 { 1 };
                      ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1244 { std::get<5 /* PerSite */>((*p_0)) };
                      ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1245 { std::get<1>(id_1244) };
                      uint16_t id_1246 { uint16_t(id_1245.index()) };
                      bool id_1247 { bool(id_1243 == id_1246) };
                      Size choose_res_1248;
                      if (id_1247) {
                        Size id_1249 { 2UL };
                        Size id_1250 { Size(sz_717 + id_1249) };
                        ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1251 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1252 { std::get<1>(id_1251) };
                        ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1253 { std::get<1 /* PerService */>(id_1252) };
                        std::string id_1254 { std::get<0>(id_1253) };
                        uint32_t id_1255 { (uint32_t)id_1254.size() };
                        Vec<1, uint32_t> id_1256 {  id_1255  };
                        Size let_res_1257;
                        {
                          Vec<1, uint32_t> n_ref_736 { id_1256 };
                          uint32_t id_1258 { 1U };
                          Vec<1, uint32_t> id_1259 {  id_1258  };
                          Size let_res_1260;
                          {
                            Vec<1, uint32_t> lebsz_ref_737 { id_1259 };
                            bool while_flag_1261 { true };
                            do {
                              uint8_t id_1262 { 0 };
                              uint32_t id_1263 { n_ref_736[id_1262] };
                              uint8_t id_1264 { 0 };
                              uint32_t id_1265 { lebsz_ref_737[id_1264] };
                              uint8_t id_1266 { 7 };
                              uint32_t id_1267 { uint32_t(id_1265 << id_1266) };
                              bool id_1268 { bool(id_1263 >= id_1267) };
                              while_flag_1261 = id_1268;
                              if (while_flag_1261) {
                                uint8_t id_1269 { 0 };
                                uint8_t id_1270 { 0 };
                                uint32_t id_1271 { lebsz_ref_737[id_1270] };
                                uint32_t id_1272 { 1U };
                                uint32_t id_1273 { uint32_t(id_1271 + id_1272) };
                                Void id_1274 { ((void)(lebsz_ref_737[id_1269] = id_1273), VOID) };
                                (void)id_1274;
                              }
                            } while (while_flag_1261);
                            (void)VOID;
                            uint8_t id_1275 { 0 };
                            uint32_t id_1276 { lebsz_ref_737[id_1275] };
                            Size id_1277 { Size(id_1276) };
                            let_res_1260 = id_1277;
                          }
                          let_res_1257 = let_res_1260;
                        }
                        ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1278 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1279 { std::get<1>(id_1278) };
                        ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1280 { std::get<1 /* PerService */>(id_1279) };
                        std::string id_1281 { std::get<0>(id_1280) };
                        uint32_t id_1282 { (uint32_t)id_1281.size() };
                        Size id_1283 { Size(id_1282) };
                        Size id_1284 { Size(let_res_1257 + id_1283) };
                        Size id_1285 { Size(id_1250 + id_1284) };
                        Size let_res_1286;
                        {
                          Size sz_738 { id_1285 };
                          uint16_t id_1287 { 0 };
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1288 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1289 { std::get<1>(id_1288) };
                          ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1290 { std::get<1 /* PerService */>(id_1289) };
                          ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_1291 { std::get<1>(id_1290) };
                          uint16_t id_1292 { uint16_t(id_1291.index()) };
                          bool id_1293 { bool(id_1287 == id_1292) };
                          Size choose_res_1294;
                          if (id_1293) {
                            Size id_1295 { 2UL };
                            Size id_1296 { Size(sz_738 + id_1295) };
                            choose_res_1294 = id_1296;
                          } else {
                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1297 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1298 { std::get<1>(id_1297) };
                            ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_1299 { std::get<1 /* PerService */>(id_1298) };
                            ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_1300 { std::get<1>(id_1299) };
                            uint16_t id_1301 { uint16_t(id_1300.index()) };
                            uint16_t id_1302 { 1 };
                            bool id_1303 { bool(id_1301 == id_1302) };
                            Void id_1304 { ((void)(assert(id_1303)), VOID) };
                            (void)id_1304;
                            Size id_1305 { 2UL };
                            Size id_1306 { Size(sz_738 + id_1305) };
                            choose_res_1294 = id_1306;
                          }
                          let_res_1286 = choose_res_1294;
                        }
                        choose_res_1248 = let_res_1286;
                      } else {
                        uint16_t id_1307 { 2 };
                        ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1308 { std::get<5 /* PerSite */>((*p_0)) };
                        ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1309 { std::get<1>(id_1308) };
                        uint16_t id_1310 { uint16_t(id_1309.index()) };
                        bool id_1311 { bool(id_1307 == id_1310) };
                        Size choose_res_1312;
                        if (id_1311) {
                          Size id_1313 { 2UL };
                          Size id_1314 { Size(sz_717 + id_1313) };
                          auto fun1315 { dessser::gen::fq_name::sersize_of_row_binary };
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1316 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1317 { std::get<1>(id_1316) };
                          ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_1318 { std::get<2 /* PerWorker */>(id_1317) };
                          dessser::gen::fq_name::t_ext id_1319 { std::get<0>(id_1318) };
                          Size id_1320 { fun1315(id_1319) };
                          Size id_1321 { Size(id_1314 + id_1320) };
                          Size let_res_1322;
                          {
                            Size sz_726 { id_1321 };
                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1323 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1324 { std::get<1>(id_1323) };
                            ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_1325 { std::get<2 /* PerWorker */>(id_1324) };
                            ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_1326 { std::get<1>(id_1325) };
                            uint16_t id_1327 { uint16_t(id_1326.index()) };
                            Size let_res_1328;
                            {
                              uint16_t label2_727 { id_1327 };
                              uint16_t id_1329 { 0 };
                              bool id_1330 { bool(id_1329 == label2_727) };
                              Size choose_res_1331;
                              if (id_1330) {
                                Size id_1332 { 2UL };
                                Size id_1333 { Size(sz_726 + id_1332) };
                                choose_res_1331 = id_1333;
                              } else {
                                uint16_t id_1334 { 1 };
                                bool id_1335 { bool(id_1334 == label2_727) };
                                Size choose_res_1336;
                                if (id_1335) {
                                  Size id_1337 { 2UL };
                                  Size id_1338 { Size(sz_726 + id_1337) };
                                  choose_res_1336 = id_1338;
                                } else {
                                  uint16_t id_1339 { 2 };
                                  bool id_1340 { bool(id_1339 == label2_727) };
                                  Size choose_res_1341;
                                  if (id_1340) {
                                    Size id_1342 { 2UL };
                                    Size id_1343 { Size(sz_726 + id_1342) };
                                    choose_res_1341 = id_1343;
                                  } else {
                                    uint16_t id_1344 { 3 };
                                    bool id_1345 { bool(id_1344 == label2_727) };
                                    Size choose_res_1346;
                                    if (id_1345) {
                                      Size id_1347 { 2UL };
                                      Size id_1348 { Size(sz_726 + id_1347) };
                                      choose_res_1346 = id_1348;
                                    } else {
                                      uint16_t id_1349 { 4 };
                                      bool id_1350 { bool(id_1349 == label2_727) };
                                      Size choose_res_1351;
                                      if (id_1350) {
                                        Size id_1352 { 2UL };
                                        Size id_1353 { Size(sz_726 + id_1352) };
                                        choose_res_1351 = id_1353;
                                      } else {
                                        uint16_t id_1354 { 5 };
                                        bool id_1355 { bool(id_1354 == label2_727) };
                                        Size choose_res_1356;
                                        if (id_1355) {
                                          Size id_1357 { 2UL };
                                          Size id_1358 { Size(sz_726 + id_1357) };
                                          choose_res_1356 = id_1358;
                                        } else {
                                          uint16_t id_1359 { 6 };
                                          bool id_1360 { bool(id_1359 == label2_727) };
                                          Size choose_res_1361;
                                          if (id_1360) {
                                            Size id_1362 { 2UL };
                                            Size id_1363 { Size(sz_726 + id_1362) };
                                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1364 { std::get<5 /* PerSite */>((*p_0)) };
                                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1365 { std::get<1>(id_1364) };
                                            ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_1366 { std::get<2 /* PerWorker */>(id_1365) };
                                            ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_1367 { std::get<1>(id_1366) };
                                            ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_1368 { std::get<6 /* PerInstance */>(id_1367) };
                                            std::string id_1369 { std::get<0>(id_1368) };
                                            uint32_t id_1370 { (uint32_t)id_1369.size() };
                                            Vec<1, uint32_t> id_1371 {  id_1370  };
                                            Size let_res_1372;
                                            {
                                              Vec<1, uint32_t> n_ref_730 { id_1371 };
                                              uint32_t id_1373 { 1U };
                                              Vec<1, uint32_t> id_1374 {  id_1373  };
                                              Size let_res_1375;
                                              {
                                                Vec<1, uint32_t> lebsz_ref_731 { id_1374 };
                                                bool while_flag_1376 { true };
                                                do {
                                                  uint8_t id_1377 { 0 };
                                                  uint32_t id_1378 { n_ref_730[id_1377] };
                                                  uint8_t id_1379 { 0 };
                                                  uint32_t id_1380 { lebsz_ref_731[id_1379] };
                                                  uint8_t id_1381 { 7 };
                                                  uint32_t id_1382 { uint32_t(id_1380 << id_1381) };
                                                  bool id_1383 { bool(id_1378 >= id_1382) };
                                                  while_flag_1376 = id_1383;
                                                  if (while_flag_1376) {
                                                    uint8_t id_1384 { 0 };
                                                    uint8_t id_1385 { 0 };
                                                    uint32_t id_1386 { lebsz_ref_731[id_1385] };
                                                    uint32_t id_1387 { 1U };
                                                    uint32_t id_1388 { uint32_t(id_1386 + id_1387) };
                                                    Void id_1389 { ((void)(lebsz_ref_731[id_1384] = id_1388), VOID) };
                                                    (void)id_1389;
                                                  }
                                                } while (while_flag_1376);
                                                (void)VOID;
                                                uint8_t id_1390 { 0 };
                                                uint32_t id_1391 { lebsz_ref_731[id_1390] };
                                                Size id_1392 { Size(id_1391) };
                                                let_res_1375 = id_1392;
                                              }
                                              let_res_1372 = let_res_1375;
                                            }
                                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1393 { std::get<5 /* PerSite */>((*p_0)) };
                                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1394 { std::get<1>(id_1393) };
                                            ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_1395 { std::get<2 /* PerWorker */>(id_1394) };
                                            ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_1396 { std::get<1>(id_1395) };
                                            ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_1397 { std::get<6 /* PerInstance */>(id_1396) };
                                            std::string id_1398 { std::get<0>(id_1397) };
                                            uint32_t id_1399 { (uint32_t)id_1398.size() };
                                            Size id_1400 { Size(id_1399) };
                                            Size id_1401 { Size(let_res_1372 + id_1400) };
                                            Size id_1402 { Size(id_1363 + id_1401) };
                                            Size let_res_1403;
                                            {
                                              Size sz_732 { id_1402 };
                                              ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1404 { std::get<5 /* PerSite */>((*p_0)) };
                                              ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1405 { std::get<1>(id_1404) };
                                              ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_1406 { std::get<2 /* PerWorker */>(id_1405) };
                                              ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_1407 { std::get<1>(id_1406) };
                                              ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_1408 { std::get<6 /* PerInstance */>(id_1407) };
                                              ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_1409 { std::get<1>(id_1408) };
                                              uint16_t id_1410 { uint16_t(id_1409.index()) };
                                              Size let_res_1411;
                                              {
                                                uint16_t label2_733 { id_1410 };
                                                uint16_t id_1412 { 0 };
                                                bool id_1413 { bool(id_1412 == label2_733) };
                                                Size choose_res_1414;
                                                if (id_1413) {
                                                  Size id_1415 { 2UL };
                                                  Size id_1416 { Size(sz_732 + id_1415) };
                                                  choose_res_1414 = id_1416;
                                                } else {
                                                  uint16_t id_1417 { 1 };
                                                  bool id_1418 { bool(id_1417 == label2_733) };
                                                  Size choose_res_1419;
                                                  if (id_1418) {
                                                    Size id_1420 { 2UL };
                                                    Size id_1421 { Size(sz_732 + id_1420) };
                                                    choose_res_1419 = id_1421;
                                                  } else {
                                                    uint16_t id_1422 { 2 };
                                                    bool id_1423 { bool(id_1422 == label2_733) };
                                                    Size choose_res_1424;
                                                    if (id_1423) {
                                                      Size id_1425 { 2UL };
                                                      Size id_1426 { Size(sz_732 + id_1425) };
                                                      choose_res_1424 = id_1426;
                                                    } else {
                                                      uint16_t id_1427 { 3 };
                                                      bool id_1428 { bool(id_1427 == label2_733) };
                                                      Size choose_res_1429;
                                                      if (id_1428) {
                                                        Size id_1430 { 2UL };
                                                        Size id_1431 { Size(sz_732 + id_1430) };
                                                        choose_res_1429 = id_1431;
                                                      } else {
                                                        uint16_t id_1432 { 4 };
                                                        bool id_1433 { bool(id_1432 == label2_733) };
                                                        Size choose_res_1434;
                                                        if (id_1433) {
                                                          Size id_1435 { 2UL };
                                                          Size id_1436 { Size(sz_732 + id_1435) };
                                                          choose_res_1434 = id_1436;
                                                        } else {
                                                          uint16_t id_1437 { 5 };
                                                          bool id_1438 { bool(id_1437 == label2_733) };
                                                          Size choose_res_1439;
                                                          if (id_1438) {
                                                            Size id_1440 { 2UL };
                                                            Size id_1441 { Size(sz_732 + id_1440) };
                                                            choose_res_1439 = id_1441;
                                                          } else {
                                                            uint16_t id_1442 { 6 };
                                                            bool id_1443 { bool(id_1442 == label2_733) };
                                                            Size choose_res_1444;
                                                            if (id_1443) {
                                                              Size id_1445 { 2UL };
                                                              Size id_1446 { Size(sz_732 + id_1445) };
                                                              choose_res_1444 = id_1446;
                                                            } else {
                                                              uint16_t id_1447 { 7 };
                                                              bool id_1448 { bool(label2_733 == id_1447) };
                                                              Void id_1449 { ((void)(assert(id_1448)), VOID) };
                                                              (void)id_1449;
                                                              Size id_1450 { 2UL };
                                                              Size id_1451 { Size(sz_732 + id_1450) };
                                                              choose_res_1444 = id_1451;
                                                            }
                                                            choose_res_1439 = choose_res_1444;
                                                          }
                                                          choose_res_1434 = choose_res_1439;
                                                        }
                                                        choose_res_1429 = choose_res_1434;
                                                      }
                                                      choose_res_1424 = choose_res_1429;
                                                    }
                                                    choose_res_1419 = choose_res_1424;
                                                  }
                                                  choose_res_1414 = choose_res_1419;
                                                }
                                                let_res_1411 = choose_res_1414;
                                              }
                                              let_res_1403 = let_res_1411;
                                            }
                                            choose_res_1361 = let_res_1403;
                                          } else {
                                            uint16_t id_1452 { 7 };
                                            bool id_1453 { bool(id_1452 == label2_727) };
                                            Size choose_res_1454;
                                            if (id_1453) {
                                              Size id_1455 { 2UL };
                                              Size id_1456 { Size(sz_726 + id_1455) };
                                              Size id_1457 { 4UL };
                                              Size id_1458 { Size(id_1456 + id_1457) };
                                              choose_res_1454 = id_1458;
                                            } else {
                                              uint16_t id_1459 { 8 };
                                              bool id_1460 { bool(label2_727 == id_1459) };
                                              Void id_1461 { ((void)(assert(id_1460)), VOID) };
                                              (void)id_1461;
                                              Size id_1462 { 2UL };
                                              Size id_1463 { Size(sz_726 + id_1462) };
                                              choose_res_1454 = id_1463;
                                            }
                                            choose_res_1361 = choose_res_1454;
                                          }
                                          choose_res_1356 = choose_res_1361;
                                        }
                                        choose_res_1351 = choose_res_1356;
                                      }
                                      choose_res_1346 = choose_res_1351;
                                    }
                                    choose_res_1341 = choose_res_1346;
                                  }
                                  choose_res_1336 = choose_res_1341;
                                }
                                choose_res_1331 = choose_res_1336;
                              }
                              let_res_1328 = choose_res_1331;
                            }
                            let_res_1322 = let_res_1328;
                          }
                          choose_res_1312 = let_res_1322;
                        } else {
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1464 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1465 { std::get<1>(id_1464) };
                          uint16_t id_1466 { uint16_t(id_1465.index()) };
                          uint16_t id_1467 { 3 };
                          bool id_1468 { bool(id_1466 == id_1467) };
                          Void id_1469 { ((void)(assert(id_1468)), VOID) };
                          (void)id_1469;
                          Size id_1470 { 2UL };
                          Size id_1471 { Size(sz_717 + id_1470) };
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1472 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1473 { std::get<1>(id_1472) };
                          ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_1474 { std::get<3 /* PerProgram */>(id_1473) };
                          std::string id_1475 { std::get<0>(id_1474) };
                          uint32_t id_1476 { (uint32_t)id_1475.size() };
                          Vec<1, uint32_t> id_1477 {  id_1476  };
                          Size let_res_1478;
                          {
                            Vec<1, uint32_t> n_ref_721 { id_1477 };
                            uint32_t id_1479 { 1U };
                            Vec<1, uint32_t> id_1480 {  id_1479  };
                            Size let_res_1481;
                            {
                              Vec<1, uint32_t> lebsz_ref_722 { id_1480 };
                              bool while_flag_1482 { true };
                              do {
                                uint8_t id_1483 { 0 };
                                uint32_t id_1484 { n_ref_721[id_1483] };
                                uint8_t id_1485 { 0 };
                                uint32_t id_1486 { lebsz_ref_722[id_1485] };
                                uint8_t id_1487 { 7 };
                                uint32_t id_1488 { uint32_t(id_1486 << id_1487) };
                                bool id_1489 { bool(id_1484 >= id_1488) };
                                while_flag_1482 = id_1489;
                                if (while_flag_1482) {
                                  uint8_t id_1490 { 0 };
                                  uint8_t id_1491 { 0 };
                                  uint32_t id_1492 { lebsz_ref_722[id_1491] };
                                  uint32_t id_1493 { 1U };
                                  uint32_t id_1494 { uint32_t(id_1492 + id_1493) };
                                  Void id_1495 { ((void)(lebsz_ref_722[id_1490] = id_1494), VOID) };
                                  (void)id_1495;
                                }
                              } while (while_flag_1482);
                              (void)VOID;
                              uint8_t id_1496 { 0 };
                              uint32_t id_1497 { lebsz_ref_722[id_1496] };
                              Size id_1498 { Size(id_1497) };
                              let_res_1481 = id_1498;
                            }
                            let_res_1478 = let_res_1481;
                          }
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1499 { std::get<5 /* PerSite */>((*p_0)) };
                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1500 { std::get<1>(id_1499) };
                          ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_1501 { std::get<3 /* PerProgram */>(id_1500) };
                          std::string id_1502 { std::get<0>(id_1501) };
                          uint32_t id_1503 { (uint32_t)id_1502.size() };
                          Size id_1504 { Size(id_1503) };
                          Size id_1505 { Size(let_res_1478 + id_1504) };
                          Size id_1506 { Size(id_1471 + id_1505) };
                          Size let_res_1507;
                          {
                            Size sz_723 { id_1506 };
                            ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_1508 { std::get<5 /* PerSite */>((*p_0)) };
                            ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_1509 { std::get<1>(id_1508) };
                            ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_1510 { std::get<3 /* PerProgram */>(id_1509) };
                            ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_1511 { std::get<1>(id_1510) };
                            uint16_t id_1512 { uint16_t(id_1511.index()) };
                            uint16_t id_1513 { 0 };
                            bool id_1514 { bool(id_1512 == id_1513) };
                            Void id_1515 { ((void)(assert(id_1514)), VOID) };
                            (void)id_1515;
                            Size id_1516 { 2UL };
                            Size id_1517 { Size(sz_723 + id_1516) };
                            let_res_1507 = id_1517;
                          }
                          choose_res_1312 = let_res_1507;
                        }
                        choose_res_1248 = choose_res_1312;
                      }
                      choose_res_1240 = choose_res_1248;
                    }
                    let_res_1234 = choose_res_1240;
                  }
                  choose_res_1227 = let_res_1234;
                } else {
                  uint16_t id_1518 { 6 };
                  bool id_1519 { bool(id_1518 == label2_671) };
                  Size choose_res_1520;
                  if (id_1519) {
                    uint16_t id_1521 { 0 };
                    ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1522 { std::get<6 /* Storage */>((*p_0)) };
                    uint16_t id_1523 { uint16_t(id_1522.index()) };
                    bool id_1524 { bool(id_1521 == id_1523) };
                    Size choose_res_1525;
                    if (id_1524) {
                      Size id_1526 { 4UL };
                      choose_res_1525 = id_1526;
                    } else {
                      uint16_t id_1527 { 1 };
                      ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1528 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_1529 { uint16_t(id_1528.index()) };
                      bool id_1530 { bool(id_1527 == id_1529) };
                      Size choose_res_1531;
                      if (id_1530) {
                        Size id_1532 { 4UL };
                        choose_res_1531 = id_1532;
                      } else {
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1533 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_1534 { uint16_t(id_1533.index()) };
                        uint16_t id_1535 { 2 };
                        bool id_1536 { bool(id_1534 == id_1535) };
                        Void id_1537 { ((void)(assert(id_1536)), VOID) };
                        (void)id_1537;
                        Size id_1538 { 4UL };
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1539 { std::get<6 /* Storage */>((*p_0)) };
                        std::string id_1540 { std::get<2 /* RetentionsOverride */>(id_1539) };
                        uint32_t id_1541 { (uint32_t)id_1540.size() };
                        Vec<1, uint32_t> id_1542 {  id_1541  };
                        Size let_res_1543;
                        {
                          Vec<1, uint32_t> n_ref_714 { id_1542 };
                          uint32_t id_1544 { 1U };
                          Vec<1, uint32_t> id_1545 {  id_1544  };
                          Size let_res_1546;
                          {
                            Vec<1, uint32_t> lebsz_ref_715 { id_1545 };
                            bool while_flag_1547 { true };
                            do {
                              uint8_t id_1548 { 0 };
                              uint32_t id_1549 { n_ref_714[id_1548] };
                              uint8_t id_1550 { 0 };
                              uint32_t id_1551 { lebsz_ref_715[id_1550] };
                              uint8_t id_1552 { 7 };
                              uint32_t id_1553 { uint32_t(id_1551 << id_1552) };
                              bool id_1554 { bool(id_1549 >= id_1553) };
                              while_flag_1547 = id_1554;
                              if (while_flag_1547) {
                                uint8_t id_1555 { 0 };
                                uint8_t id_1556 { 0 };
                                uint32_t id_1557 { lebsz_ref_715[id_1556] };
                                uint32_t id_1558 { 1U };
                                uint32_t id_1559 { uint32_t(id_1557 + id_1558) };
                                Void id_1560 { ((void)(lebsz_ref_715[id_1555] = id_1559), VOID) };
                                (void)id_1560;
                              }
                            } while (while_flag_1547);
                            (void)VOID;
                            uint8_t id_1561 { 0 };
                            uint32_t id_1562 { lebsz_ref_715[id_1561] };
                            Size id_1563 { Size(id_1562) };
                            let_res_1546 = id_1563;
                          }
                          let_res_1543 = let_res_1546;
                        }
                        ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_1564 { std::get<6 /* Storage */>((*p_0)) };
                        std::string id_1565 { std::get<2 /* RetentionsOverride */>(id_1564) };
                        uint32_t id_1566 { (uint32_t)id_1565.size() };
                        Size id_1567 { Size(id_1566) };
                        Size id_1568 { Size(let_res_1543 + id_1567) };
                        Size id_1569 { Size(id_1538 + id_1568) };
                        choose_res_1531 = id_1569;
                      }
                      choose_res_1525 = choose_res_1531;
                    }
                    choose_res_1520 = choose_res_1525;
                  } else {
                    uint16_t id_1570 { 7 };
                    bool id_1571 { bool(id_1570 == label2_671) };
                    Size choose_res_1572;
                    if (id_1571) {
                      Size id_1573 { 2UL };
                      auto fun1574 { dessser::gen::site_name::sersize_of_row_binary };
                      ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_1575 { std::get<7 /* Tails */>((*p_0)) };
                      dessser::gen::site_name::t_ext id_1576 { std::get<0>(id_1575) };
                      Size id_1577 { fun1574(id_1576) };
                      Size id_1578 { Size(id_1573 + id_1577) };
                      Size let_res_1579;
                      {
                        Size sz_706 { id_1578 };
                        auto fun1580 { dessser::gen::fq_name::sersize_of_row_binary };
                        ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_1581 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::fq_name::t_ext id_1582 { std::get<1>(id_1581) };
                        Size id_1583 { fun1580(id_1582) };
                        Size id_1584 { Size(sz_706 + id_1583) };
                        let_res_1579 = id_1584;
                      }
                      Size let_res_1585;
                      {
                        Size sz_707 { let_res_1579 };
                        ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_1586 { std::get<7 /* Tails */>((*p_0)) };
                        std::string id_1587 { std::get<2>(id_1586) };
                        uint32_t id_1588 { (uint32_t)id_1587.size() };
                        Vec<1, uint32_t> id_1589 {  id_1588  };
                        Size let_res_1590;
                        {
                          Vec<1, uint32_t> n_ref_709 { id_1589 };
                          uint32_t id_1591 { 1U };
                          Vec<1, uint32_t> id_1592 {  id_1591  };
                          Size let_res_1593;
                          {
                            Vec<1, uint32_t> lebsz_ref_710 { id_1592 };
                            bool while_flag_1594 { true };
                            do {
                              uint8_t id_1595 { 0 };
                              uint32_t id_1596 { n_ref_709[id_1595] };
                              uint8_t id_1597 { 0 };
                              uint32_t id_1598 { lebsz_ref_710[id_1597] };
                              uint8_t id_1599 { 7 };
                              uint32_t id_1600 { uint32_t(id_1598 << id_1599) };
                              bool id_1601 { bool(id_1596 >= id_1600) };
                              while_flag_1594 = id_1601;
                              if (while_flag_1594) {
                                uint8_t id_1602 { 0 };
                                uint8_t id_1603 { 0 };
                                uint32_t id_1604 { lebsz_ref_710[id_1603] };
                                uint32_t id_1605 { 1U };
                                uint32_t id_1606 { uint32_t(id_1604 + id_1605) };
                                Void id_1607 { ((void)(lebsz_ref_710[id_1602] = id_1606), VOID) };
                                (void)id_1607;
                              }
                            } while (while_flag_1594);
                            (void)VOID;
                            uint8_t id_1608 { 0 };
                            uint32_t id_1609 { lebsz_ref_710[id_1608] };
                            Size id_1610 { Size(id_1609) };
                            let_res_1593 = id_1610;
                          }
                          let_res_1590 = let_res_1593;
                        }
                        ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_1611 { std::get<7 /* Tails */>((*p_0)) };
                        std::string id_1612 { std::get<2>(id_1611) };
                        uint32_t id_1613 { (uint32_t)id_1612.size() };
                        Size id_1614 { Size(id_1613) };
                        Size id_1615 { Size(let_res_1590 + id_1614) };
                        Size id_1616 { Size(sz_707 + id_1615) };
                        let_res_1585 = id_1616;
                      }
                      Size let_res_1617;
                      {
                        Size sz_711 { let_res_1585 };
                        ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_1618 { std::get<7 /* Tails */>((*p_0)) };
                        ::dessser::gen::sync_key::per_tail* id_1619 { std::get<3>(id_1618) };
                        Size id_1620 { per_tail_sersize_of_row_binary(id_1619) };
                        Size id_1621 { Size(sz_711 + id_1620) };
                        let_res_1617 = id_1621;
                      }
                      choose_res_1572 = let_res_1617;
                    } else {
                      uint16_t id_1622 { 8 };
                      bool id_1623 { bool(id_1622 == label2_671) };
                      Size choose_res_1624;
                      if (id_1623) {
                        Size id_1625 { 4UL };
                        choose_res_1624 = id_1625;
                      } else {
                        uint16_t id_1626 { 9 };
                        bool id_1627 { bool(id_1626 == label2_671) };
                        Size choose_res_1628;
                        if (id_1627) {
                          std::optional<dessser::gen::sync_socket::t_ext> id_1629 { std::get<9 /* Error */>((*p_0)) };
                          bool id_1630 { !(id_1629.has_value ()) };
                          Size choose_res_1631;
                          if (id_1630) {
                            Size id_1632 { 3UL };
                            choose_res_1631 = id_1632;
                          } else {
                            Size id_1633 { 2UL };
                            auto fun1634 { dessser::gen::sync_socket::sersize_of_row_binary };
                            std::optional<dessser::gen::sync_socket::t_ext> id_1635 { std::get<9 /* Error */>((*p_0)) };
                            dessser::gen::sync_socket::t_ext id_1636 { id_1635.value() };
                            Size id_1637 { fun1634(id_1636) };
                            Size id_1638 { Size(id_1633 + id_1637) };
                            Size id_1639 { 1UL };
                            Size id_1640 { Size(id_1638 + id_1639) };
                            choose_res_1631 = id_1640;
                          }
                          choose_res_1628 = choose_res_1631;
                        } else {
                          uint16_t id_1641 { 10 };
                          bool id_1642 { bool(id_1641 == label2_671) };
                          Size choose_res_1643;
                          if (id_1642) {
                            Size id_1644 { 2UL };
                            choose_res_1643 = id_1644;
                          } else {
                            uint16_t id_1645 { 11 };
                            bool id_1646 { bool(id_1645 == label2_671) };
                            Size choose_res_1647;
                            if (id_1646) {
                              Size id_1648 { 2UL };
                              auto fun1649 { dessser::gen::sync_socket::sersize_of_row_binary };
                              ::dessser::gen::sync_key::t3f175f4a6fba6fdb7dfcec615c7c9650 id_1650 { std::get<11 /* PerClient */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_1651 { std::get<0>(id_1650) };
                              Size id_1652 { fun1649(id_1651) };
                              Size id_1653 { Size(id_1648 + id_1652) };
                              Size let_res_1654;
                              {
                                Size sz_704 { id_1653 };
                                ::dessser::gen::sync_key::t3f175f4a6fba6fdb7dfcec615c7c9650 id_1655 { std::get<11 /* PerClient */>((*p_0)) };
                                ::dessser::gen::sync_key::per_client* id_1656 { std::get<1>(id_1655) };
                                Size id_1657 { per_client_sersize_of_row_binary(id_1656) };
                                Size id_1658 { Size(sz_704 + id_1657) };
                                let_res_1654 = id_1658;
                              }
                              choose_res_1647 = let_res_1654;
                            } else {
                              uint16_t id_1659 { 12 };
                              bool id_1660 { bool(id_1659 == label2_671) };
                              Size choose_res_1661;
                              if (id_1660) {
                                Size id_1662 { 2UL };
                                ::dessser::gen::sync_key::ta2544ee31f0dcf915e9425cc06777d2f id_1663 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1664 { std::get<0>(id_1663) };
                                uint32_t id_1665 { (uint32_t)id_1664.size() };
                                Vec<1, uint32_t> id_1666 {  id_1665  };
                                Size let_res_1667;
                                {
                                  Vec<1, uint32_t> n_ref_700 { id_1666 };
                                  uint32_t id_1668 { 1U };
                                  Vec<1, uint32_t> id_1669 {  id_1668  };
                                  Size let_res_1670;
                                  {
                                    Vec<1, uint32_t> lebsz_ref_701 { id_1669 };
                                    bool while_flag_1671 { true };
                                    do {
                                      uint8_t id_1672 { 0 };
                                      uint32_t id_1673 { n_ref_700[id_1672] };
                                      uint8_t id_1674 { 0 };
                                      uint32_t id_1675 { lebsz_ref_701[id_1674] };
                                      uint8_t id_1676 { 7 };
                                      uint32_t id_1677 { uint32_t(id_1675 << id_1676) };
                                      bool id_1678 { bool(id_1673 >= id_1677) };
                                      while_flag_1671 = id_1678;
                                      if (while_flag_1671) {
                                        uint8_t id_1679 { 0 };
                                        uint8_t id_1680 { 0 };
                                        uint32_t id_1681 { lebsz_ref_701[id_1680] };
                                        uint32_t id_1682 { 1U };
                                        uint32_t id_1683 { uint32_t(id_1681 + id_1682) };
                                        Void id_1684 { ((void)(lebsz_ref_701[id_1679] = id_1683), VOID) };
                                        (void)id_1684;
                                      }
                                    } while (while_flag_1671);
                                    (void)VOID;
                                    uint8_t id_1685 { 0 };
                                    uint32_t id_1686 { lebsz_ref_701[id_1685] };
                                    Size id_1687 { Size(id_1686) };
                                    let_res_1670 = id_1687;
                                  }
                                  let_res_1667 = let_res_1670;
                                }
                                ::dessser::gen::sync_key::ta2544ee31f0dcf915e9425cc06777d2f id_1688 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1689 { std::get<0>(id_1688) };
                                uint32_t id_1690 { (uint32_t)id_1689.size() };
                                Size id_1691 { Size(id_1690) };
                                Size id_1692 { Size(let_res_1667 + id_1691) };
                                Size id_1693 { Size(id_1662 + id_1692) };
                                Size let_res_1694;
                                {
                                  Size sz_702 { id_1693 };
                                  ::dessser::gen::sync_key::ta2544ee31f0dcf915e9425cc06777d2f id_1695 { std::get<12 /* Dashboards */>((*p_0)) };
                                  per_dash_key* id_1696 { std::get<1>(id_1695) };
                                  Size id_1697 { per_dash_key_sersize_of_row_binary(id_1696) };
                                  Size id_1698 { Size(sz_702 + id_1697) };
                                  let_res_1694 = id_1698;
                                }
                                choose_res_1661 = let_res_1694;
                              } else {
                                uint16_t id_1699 { 13 };
                                bool id_1700 { bool(id_1699 == label2_671) };
                                Size choose_res_1701;
                                if (id_1700) {
                                  Size id_1702 { 2UL };
                                  choose_res_1701 = id_1702;
                                } else {
                                  uint16_t id_1703 { 14 };
                                  bool id_1704 { bool(id_1703 == label2_671) };
                                  Size choose_res_1705;
                                  if (id_1704) {
                                    Size id_1706 { 2UL };
                                    ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_1707 { std::get<14 /* Teams */>((*p_0)) };
                                    std::string id_1708 { std::get<0>(id_1707) };
                                    uint32_t id_1709 { (uint32_t)id_1708.size() };
                                    Vec<1, uint32_t> id_1710 {  id_1709  };
                                    Size let_res_1711;
                                    {
                                      Vec<1, uint32_t> n_ref_688 { id_1710 };
                                      uint32_t id_1712 { 1U };
                                      Vec<1, uint32_t> id_1713 {  id_1712  };
                                      Size let_res_1714;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_689 { id_1713 };
                                        bool while_flag_1715 { true };
                                        do {
                                          uint8_t id_1716 { 0 };
                                          uint32_t id_1717 { n_ref_688[id_1716] };
                                          uint8_t id_1718 { 0 };
                                          uint32_t id_1719 { lebsz_ref_689[id_1718] };
                                          uint8_t id_1720 { 7 };
                                          uint32_t id_1721 { uint32_t(id_1719 << id_1720) };
                                          bool id_1722 { bool(id_1717 >= id_1721) };
                                          while_flag_1715 = id_1722;
                                          if (while_flag_1715) {
                                            uint8_t id_1723 { 0 };
                                            uint8_t id_1724 { 0 };
                                            uint32_t id_1725 { lebsz_ref_689[id_1724] };
                                            uint32_t id_1726 { 1U };
                                            uint32_t id_1727 { uint32_t(id_1725 + id_1726) };
                                            Void id_1728 { ((void)(lebsz_ref_689[id_1723] = id_1727), VOID) };
                                            (void)id_1728;
                                          }
                                        } while (while_flag_1715);
                                        (void)VOID;
                                        uint8_t id_1729 { 0 };
                                        uint32_t id_1730 { lebsz_ref_689[id_1729] };
                                        Size id_1731 { Size(id_1730) };
                                        let_res_1714 = id_1731;
                                      }
                                      let_res_1711 = let_res_1714;
                                    }
                                    ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_1732 { std::get<14 /* Teams */>((*p_0)) };
                                    std::string id_1733 { std::get<0>(id_1732) };
                                    uint32_t id_1734 { (uint32_t)id_1733.size() };
                                    Size id_1735 { Size(id_1734) };
                                    Size id_1736 { Size(let_res_1711 + id_1735) };
                                    Size id_1737 { Size(id_1706 + id_1736) };
                                    Size let_res_1738;
                                    {
                                      Size sz_690 { id_1737 };
                                      uint16_t id_1739 { 0 };
                                      ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_1740 { std::get<14 /* Teams */>((*p_0)) };
                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1741 { std::get<1>(id_1740) };
                                      uint16_t id_1742 { uint16_t(id_1741.index()) };
                                      bool id_1743 { bool(id_1739 == id_1742) };
                                      Size choose_res_1744;
                                      if (id_1743) {
                                        Size id_1745 { 2UL };
                                        Size id_1746 { Size(sz_690 + id_1745) };
                                        ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_1747 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1748 { std::get<1>(id_1747) };
                                        std::string id_1749 { std::get<0 /* Contacts */>(id_1748) };
                                        uint32_t id_1750 { (uint32_t)id_1749.size() };
                                        Vec<1, uint32_t> id_1751 {  id_1750  };
                                        Size let_res_1752;
                                        {
                                          Vec<1, uint32_t> n_ref_696 { id_1751 };
                                          uint32_t id_1753 { 1U };
                                          Vec<1, uint32_t> id_1754 {  id_1753  };
                                          Size let_res_1755;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_697 { id_1754 };
                                            bool while_flag_1756 { true };
                                            do {
                                              uint8_t id_1757 { 0 };
                                              uint32_t id_1758 { n_ref_696[id_1757] };
                                              uint8_t id_1759 { 0 };
                                              uint32_t id_1760 { lebsz_ref_697[id_1759] };
                                              uint8_t id_1761 { 7 };
                                              uint32_t id_1762 { uint32_t(id_1760 << id_1761) };
                                              bool id_1763 { bool(id_1758 >= id_1762) };
                                              while_flag_1756 = id_1763;
                                              if (while_flag_1756) {
                                                uint8_t id_1764 { 0 };
                                                uint8_t id_1765 { 0 };
                                                uint32_t id_1766 { lebsz_ref_697[id_1765] };
                                                uint32_t id_1767 { 1U };
                                                uint32_t id_1768 { uint32_t(id_1766 + id_1767) };
                                                Void id_1769 { ((void)(lebsz_ref_697[id_1764] = id_1768), VOID) };
                                                (void)id_1769;
                                              }
                                            } while (while_flag_1756);
                                            (void)VOID;
                                            uint8_t id_1770 { 0 };
                                            uint32_t id_1771 { lebsz_ref_697[id_1770] };
                                            Size id_1772 { Size(id_1771) };
                                            let_res_1755 = id_1772;
                                          }
                                          let_res_1752 = let_res_1755;
                                        }
                                        ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_1773 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1774 { std::get<1>(id_1773) };
                                        std::string id_1775 { std::get<0 /* Contacts */>(id_1774) };
                                        uint32_t id_1776 { (uint32_t)id_1775.size() };
                                        Size id_1777 { Size(id_1776) };
                                        Size id_1778 { Size(let_res_1752 + id_1777) };
                                        Size id_1779 { Size(id_1746 + id_1778) };
                                        choose_res_1744 = id_1779;
                                      } else {
                                        ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_1780 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1781 { std::get<1>(id_1780) };
                                        uint16_t id_1782 { uint16_t(id_1781.index()) };
                                        uint16_t id_1783 { 1 };
                                        bool id_1784 { bool(id_1782 == id_1783) };
                                        Void id_1785 { ((void)(assert(id_1784)), VOID) };
                                        (void)id_1785;
                                        Size id_1786 { 2UL };
                                        Size id_1787 { Size(sz_690 + id_1786) };
                                        ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_1788 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1789 { std::get<1>(id_1788) };
                                        std::string id_1790 { std::get<1 /* Inhibition */>(id_1789) };
                                        uint32_t id_1791 { (uint32_t)id_1790.size() };
                                        Vec<1, uint32_t> id_1792 {  id_1791  };
                                        Size let_res_1793;
                                        {
                                          Vec<1, uint32_t> n_ref_693 { id_1792 };
                                          uint32_t id_1794 { 1U };
                                          Vec<1, uint32_t> id_1795 {  id_1794  };
                                          Size let_res_1796;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_694 { id_1795 };
                                            bool while_flag_1797 { true };
                                            do {
                                              uint8_t id_1798 { 0 };
                                              uint32_t id_1799 { n_ref_693[id_1798] };
                                              uint8_t id_1800 { 0 };
                                              uint32_t id_1801 { lebsz_ref_694[id_1800] };
                                              uint8_t id_1802 { 7 };
                                              uint32_t id_1803 { uint32_t(id_1801 << id_1802) };
                                              bool id_1804 { bool(id_1799 >= id_1803) };
                                              while_flag_1797 = id_1804;
                                              if (while_flag_1797) {
                                                uint8_t id_1805 { 0 };
                                                uint8_t id_1806 { 0 };
                                                uint32_t id_1807 { lebsz_ref_694[id_1806] };
                                                uint32_t id_1808 { 1U };
                                                uint32_t id_1809 { uint32_t(id_1807 + id_1808) };
                                                Void id_1810 { ((void)(lebsz_ref_694[id_1805] = id_1809), VOID) };
                                                (void)id_1810;
                                              }
                                            } while (while_flag_1797);
                                            (void)VOID;
                                            uint8_t id_1811 { 0 };
                                            uint32_t id_1812 { lebsz_ref_694[id_1811] };
                                            Size id_1813 { Size(id_1812) };
                                            let_res_1796 = id_1813;
                                          }
                                          let_res_1793 = let_res_1796;
                                        }
                                        ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_1814 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_1815 { std::get<1>(id_1814) };
                                        std::string id_1816 { std::get<1 /* Inhibition */>(id_1815) };
                                        uint32_t id_1817 { (uint32_t)id_1816.size() };
                                        Size id_1818 { Size(id_1817) };
                                        Size id_1819 { Size(let_res_1793 + id_1818) };
                                        Size id_1820 { Size(id_1787 + id_1819) };
                                        choose_res_1744 = id_1820;
                                      }
                                      let_res_1738 = choose_res_1744;
                                    }
                                    choose_res_1705 = let_res_1738;
                                  } else {
                                    uint16_t id_1821 { 15 };
                                    bool id_1822 { bool(label2_671 == id_1821) };
                                    Void id_1823 { ((void)(assert(id_1822)), VOID) };
                                    (void)id_1823;
                                    Size id_1824 { 2UL };
                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1825 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1826 { std::get<0>(id_1825) };
                                    uint32_t id_1827 { (uint32_t)id_1826.size() };
                                    Vec<1, uint32_t> id_1828 {  id_1827  };
                                    Size let_res_1829;
                                    {
                                      Vec<1, uint32_t> n_ref_674 { id_1828 };
                                      uint32_t id_1830 { 1U };
                                      Vec<1, uint32_t> id_1831 {  id_1830  };
                                      Size let_res_1832;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_675 { id_1831 };
                                        bool while_flag_1833 { true };
                                        do {
                                          uint8_t id_1834 { 0 };
                                          uint32_t id_1835 { n_ref_674[id_1834] };
                                          uint8_t id_1836 { 0 };
                                          uint32_t id_1837 { lebsz_ref_675[id_1836] };
                                          uint8_t id_1838 { 7 };
                                          uint32_t id_1839 { uint32_t(id_1837 << id_1838) };
                                          bool id_1840 { bool(id_1835 >= id_1839) };
                                          while_flag_1833 = id_1840;
                                          if (while_flag_1833) {
                                            uint8_t id_1841 { 0 };
                                            uint8_t id_1842 { 0 };
                                            uint32_t id_1843 { lebsz_ref_675[id_1842] };
                                            uint32_t id_1844 { 1U };
                                            uint32_t id_1845 { uint32_t(id_1843 + id_1844) };
                                            Void id_1846 { ((void)(lebsz_ref_675[id_1841] = id_1845), VOID) };
                                            (void)id_1846;
                                          }
                                        } while (while_flag_1833);
                                        (void)VOID;
                                        uint8_t id_1847 { 0 };
                                        uint32_t id_1848 { lebsz_ref_675[id_1847] };
                                        Size id_1849 { Size(id_1848) };
                                        let_res_1832 = id_1849;
                                      }
                                      let_res_1829 = let_res_1832;
                                    }
                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1850 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1851 { std::get<0>(id_1850) };
                                    uint32_t id_1852 { (uint32_t)id_1851.size() };
                                    Size id_1853 { Size(id_1852) };
                                    Size id_1854 { Size(let_res_1829 + id_1853) };
                                    Size id_1855 { Size(id_1824 + id_1854) };
                                    Size let_res_1856;
                                    {
                                      Size sz_676 { id_1855 };
                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1857 { std::get<15 /* Incidents */>((*p_0)) };
                                      ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1858 { std::get<1>(id_1857) };
                                      uint16_t id_1859 { uint16_t(id_1858.index()) };
                                      Size let_res_1860;
                                      {
                                        uint16_t label2_677 { id_1859 };
                                        uint16_t id_1861 { 0 };
                                        bool id_1862 { bool(id_1861 == label2_677) };
                                        Size choose_res_1863;
                                        if (id_1862) {
                                          Size id_1864 { 2UL };
                                          Size id_1865 { Size(sz_676 + id_1864) };
                                          choose_res_1863 = id_1865;
                                        } else {
                                          uint16_t id_1866 { 1 };
                                          bool id_1867 { bool(id_1866 == label2_677) };
                                          Size choose_res_1868;
                                          if (id_1867) {
                                            Size id_1869 { 2UL };
                                            Size id_1870 { Size(sz_676 + id_1869) };
                                            choose_res_1868 = id_1870;
                                          } else {
                                            uint16_t id_1871 { 2 };
                                            bool id_1872 { bool(id_1871 == label2_677) };
                                            Size choose_res_1873;
                                            if (id_1872) {
                                              Size id_1874 { 2UL };
                                              Size id_1875 { Size(sz_676 + id_1874) };
                                              choose_res_1873 = id_1875;
                                            } else {
                                              uint16_t id_1876 { 3 };
                                              bool id_1877 { bool(id_1876 == label2_677) };
                                              Size choose_res_1878;
                                              if (id_1877) {
                                                Size id_1879 { 2UL };
                                                Size id_1880 { Size(sz_676 + id_1879) };
                                                choose_res_1878 = id_1880;
                                              } else {
                                                uint16_t id_1881 { 4 };
                                                bool id_1882 { bool(id_1881 == label2_677) };
                                                Size choose_res_1883;
                                                if (id_1882) {
                                                  Size id_1884 { 2UL };
                                                  Size id_1885 { Size(sz_676 + id_1884) };
                                                  choose_res_1883 = id_1885;
                                                } else {
                                                  uint16_t id_1886 { 5 };
                                                  bool id_1887 { bool(id_1886 == label2_677) };
                                                  Size choose_res_1888;
                                                  if (id_1887) {
                                                    Size id_1889 { 2UL };
                                                    Size id_1890 { Size(sz_676 + id_1889) };
                                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1891 { std::get<15 /* Incidents */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1892 { std::get<1>(id_1891) };
                                                    ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_1893 { std::get<5 /* Dialogs */>(id_1892) };
                                                    std::string id_1894 { std::get<0>(id_1893) };
                                                    uint32_t id_1895 { (uint32_t)id_1894.size() };
                                                    Vec<1, uint32_t> id_1896 {  id_1895  };
                                                    Size let_res_1897;
                                                    {
                                                      Vec<1, uint32_t> n_ref_682 { id_1896 };
                                                      uint32_t id_1898 { 1U };
                                                      Vec<1, uint32_t> id_1899 {  id_1898  };
                                                      Size let_res_1900;
                                                      {
                                                        Vec<1, uint32_t> lebsz_ref_683 { id_1899 };
                                                        bool while_flag_1901 { true };
                                                        do {
                                                          uint8_t id_1902 { 0 };
                                                          uint32_t id_1903 { n_ref_682[id_1902] };
                                                          uint8_t id_1904 { 0 };
                                                          uint32_t id_1905 { lebsz_ref_683[id_1904] };
                                                          uint8_t id_1906 { 7 };
                                                          uint32_t id_1907 { uint32_t(id_1905 << id_1906) };
                                                          bool id_1908 { bool(id_1903 >= id_1907) };
                                                          while_flag_1901 = id_1908;
                                                          if (while_flag_1901) {
                                                            uint8_t id_1909 { 0 };
                                                            uint8_t id_1910 { 0 };
                                                            uint32_t id_1911 { lebsz_ref_683[id_1910] };
                                                            uint32_t id_1912 { 1U };
                                                            uint32_t id_1913 { uint32_t(id_1911 + id_1912) };
                                                            Void id_1914 { ((void)(lebsz_ref_683[id_1909] = id_1913), VOID) };
                                                            (void)id_1914;
                                                          }
                                                        } while (while_flag_1901);
                                                        (void)VOID;
                                                        uint8_t id_1915 { 0 };
                                                        uint32_t id_1916 { lebsz_ref_683[id_1915] };
                                                        Size id_1917 { Size(id_1916) };
                                                        let_res_1900 = id_1917;
                                                      }
                                                      let_res_1897 = let_res_1900;
                                                    }
                                                    ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1918 { std::get<15 /* Incidents */>((*p_0)) };
                                                    ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1919 { std::get<1>(id_1918) };
                                                    ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_1920 { std::get<5 /* Dialogs */>(id_1919) };
                                                    std::string id_1921 { std::get<0>(id_1920) };
                                                    uint32_t id_1922 { (uint32_t)id_1921.size() };
                                                    Size id_1923 { Size(id_1922) };
                                                    Size id_1924 { Size(let_res_1897 + id_1923) };
                                                    Size id_1925 { Size(id_1890 + id_1924) };
                                                    Size let_res_1926;
                                                    {
                                                      Size sz_684 { id_1925 };
                                                      ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_1927 { std::get<15 /* Incidents */>((*p_0)) };
                                                      ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_1928 { std::get<1>(id_1927) };
                                                      ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_1929 { std::get<5 /* Dialogs */>(id_1928) };
                                                      ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_1930 { std::get<1>(id_1929) };
                                                      uint16_t id_1931 { uint16_t(id_1930.index()) };
                                                      Size let_res_1932;
                                                      {
                                                        uint16_t label2_685 { id_1931 };
                                                        uint16_t id_1933 { 0 };
                                                        bool id_1934 { bool(id_1933 == label2_685) };
                                                        Size choose_res_1935;
                                                        if (id_1934) {
                                                          Size id_1936 { 2UL };
                                                          Size id_1937 { Size(sz_684 + id_1936) };
                                                          choose_res_1935 = id_1937;
                                                        } else {
                                                          uint16_t id_1938 { 1 };
                                                          bool id_1939 { bool(id_1938 == label2_685) };
                                                          Size choose_res_1940;
                                                          if (id_1939) {
                                                            Size id_1941 { 2UL };
                                                            Size id_1942 { Size(sz_684 + id_1941) };
                                                            choose_res_1940 = id_1942;
                                                          } else {
                                                            uint16_t id_1943 { 2 };
                                                            bool id_1944 { bool(id_1943 == label2_685) };
                                                            Size choose_res_1945;
                                                            if (id_1944) {
                                                              Size id_1946 { 2UL };
                                                              Size id_1947 { Size(sz_684 + id_1946) };
                                                              choose_res_1945 = id_1947;
                                                            } else {
                                                              uint16_t id_1948 { 3 };
                                                              bool id_1949 { bool(id_1948 == label2_685) };
                                                              Size choose_res_1950;
                                                              if (id_1949) {
                                                                Size id_1951 { 2UL };
                                                                Size id_1952 { Size(sz_684 + id_1951) };
                                                                choose_res_1950 = id_1952;
                                                              } else {
                                                                uint16_t id_1953 { 4 };
                                                                bool id_1954 { bool(id_1953 == label2_685) };
                                                                Size choose_res_1955;
                                                                if (id_1954) {
                                                                  Size id_1956 { 2UL };
                                                                  Size id_1957 { Size(sz_684 + id_1956) };
                                                                  choose_res_1955 = id_1957;
                                                                } else {
                                                                  uint16_t id_1958 { 5 };
                                                                  bool id_1959 { bool(id_1958 == label2_685) };
                                                                  Size choose_res_1960;
                                                                  if (id_1959) {
                                                                    Size id_1961 { 2UL };
                                                                    Size id_1962 { Size(sz_684 + id_1961) };
                                                                    choose_res_1960 = id_1962;
                                                                  } else {
                                                                    uint16_t id_1963 { 6 };
                                                                    bool id_1964 { bool(label2_685 == id_1963) };
                                                                    Void id_1965 { ((void)(assert(id_1964)), VOID) };
                                                                    (void)id_1965;
                                                                    Size id_1966 { 2UL };
                                                                    Size id_1967 { Size(sz_684 + id_1966) };
                                                                    choose_res_1960 = id_1967;
                                                                  }
                                                                  choose_res_1955 = choose_res_1960;
                                                                }
                                                                choose_res_1950 = choose_res_1955;
                                                              }
                                                              choose_res_1945 = choose_res_1950;
                                                            }
                                                            choose_res_1940 = choose_res_1945;
                                                          }
                                                          choose_res_1935 = choose_res_1940;
                                                        }
                                                        let_res_1932 = choose_res_1935;
                                                      }
                                                      let_res_1926 = let_res_1932;
                                                    }
                                                    choose_res_1888 = let_res_1926;
                                                  } else {
                                                    uint16_t id_1968 { 6 };
                                                    bool id_1969 { bool(label2_677 == id_1968) };
                                                    Void id_1970 { ((void)(assert(id_1969)), VOID) };
                                                    (void)id_1970;
                                                    Size id_1971 { 2UL };
                                                    Size id_1972 { Size(sz_676 + id_1971) };
                                                    Size id_1973 { 8UL };
                                                    Size id_1974 { Size(id_1972 + id_1973) };
                                                    Size id_1975 { 4UL };
                                                    Size id_1976 { Size(id_1974 + id_1975) };
                                                    choose_res_1888 = id_1976;
                                                  }
                                                  choose_res_1883 = choose_res_1888;
                                                }
                                                choose_res_1878 = choose_res_1883;
                                              }
                                              choose_res_1873 = choose_res_1878;
                                            }
                                            choose_res_1868 = choose_res_1873;
                                          }
                                          choose_res_1863 = choose_res_1868;
                                        }
                                        let_res_1860 = choose_res_1863;
                                      }
                                      let_res_1856 = let_res_1860;
                                    }
                                    choose_res_1705 = let_res_1856;
                                  }
                                  choose_res_1701 = choose_res_1705;
                                }
                                choose_res_1661 = choose_res_1701;
                              }
                              choose_res_1647 = choose_res_1661;
                            }
                            choose_res_1643 = choose_res_1647;
                          }
                          choose_res_1628 = choose_res_1643;
                        }
                        choose_res_1624 = choose_res_1628;
                      }
                      choose_res_1572 = choose_res_1624;
                    }
                    choose_res_1520 = choose_res_1572;
                  }
                  choose_res_1227 = choose_res_1520;
                }
                choose_res_1223 = choose_res_1227;
              }
              choose_res_1182 = choose_res_1223;
            }
            choose_res_1149 = choose_res_1182;
          }
          choose_res_1145 = choose_res_1149;
        }
        choose_res_1141 = choose_res_1145;
      }
      let_res_1138 = choose_res_1141;
    }
    return let_res_1138;
  }
   };
  return fun1136;
}
std::function<Size(::dessser::gen::sync_key::t*)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_95" (let-pair "du16_fst_90" "du16_snd_91" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_90") (identifier "du16_snd_91")))
        (let-pair "dsum1_fst_96" "dsum1_snd_97" (identifier "dsum1_95")
          (seq (assert (eq (identifier "dsum1_fst_96") (u16 0)))
            (let-pair "du32_fst_99" "du32_snd_100" (read-u32 little-endian (identifier "dsum1_snd_97")) (make-tup (construct "[Widgets U32]" 0 (identifier "du32_fst_99")) (identifier "du32_snd_100")))))))
 */
static std::function<::dessser::gen::sync_key::tcce73bde988985bdd0bca77372a40274(Pointer)> per_dash_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tcce73bde988985bdd0bca77372a40274(Pointer)> fun1977 { [&fun1977](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1978 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1979;
    {
      auto du16_fst_90 { std::get<0>(id_1978) };
      auto du16_snd_91 { std::get<1>(id_1978) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1980 { du16_fst_90, du16_snd_91 };
      letpair_res_1979 = id_1980;
    }
    ::dessser::gen::sync_key::tcce73bde988985bdd0bca77372a40274 let_res_1981;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_95 { letpair_res_1979 };
      ::dessser::gen::sync_key::tcce73bde988985bdd0bca77372a40274 letpair_res_1982;
      {
        auto dsum1_fst_96 { std::get<0>(dsum1_95) };
        auto dsum1_snd_97 { std::get<1>(dsum1_95) };
        uint16_t id_1983 { 0 };
        bool id_1984 { bool(dsum1_fst_96 == id_1983) };
        Void id_1985 { ((void)(assert(id_1984)), VOID) };
        (void)id_1985;
        ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_1986 { dsum1_snd_97.readU32Le() };
        ::dessser::gen::sync_key::tcce73bde988985bdd0bca77372a40274 letpair_res_1987;
        {
          auto du32_fst_99 { std::get<0>(id_1986) };
          auto du32_snd_100 { std::get<1>(id_1986) };
          ::dessser::gen::sync_key::per_dash_key* id_1988 { new ::dessser::gen::sync_key::per_dash_key(std::in_place_index<0>, du32_fst_99) };
          ::dessser::gen::sync_key::tcce73bde988985bdd0bca77372a40274 id_1989 { id_1988, du32_snd_100 };
          letpair_res_1987 = id_1989;
        }
        letpair_res_1982 = letpair_res_1987;
      }
      let_res_1981 = letpair_res_1982;
    }
    return let_res_1981;
  }
   };
  return fun1977;
}
std::function<::dessser::gen::sync_key::tcce73bde988985bdd0bca77372a40274(Pointer)> per_dash_key_of_row_binary(per_dash_key_of_row_binary_init());

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
static std::function<::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43(Pointer)> per_client_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43(Pointer)> fun1990 { [&fun1990](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1991 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_1992;
    {
      auto du16_fst_108 { std::get<0>(id_1991) };
      auto du16_snd_109 { std::get<1>(id_1991) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_1993 { du16_fst_108, du16_snd_109 };
      letpair_res_1992 = id_1993;
    }
    ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 let_res_1994;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_113 { letpair_res_1992 };
      ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 letpair_res_1995;
      {
        auto dsum1_fst_114 { std::get<0>(dsum1_113) };
        auto dsum1_snd_115 { std::get<1>(dsum1_113) };
        uint16_t id_1996 { 0 };
        bool id_1997 { bool(id_1996 == dsum1_fst_114) };
        ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 choose_res_1998;
        if (id_1997) {
          uint32_t id_1999 { 0U };
          Vec<1, uint32_t> id_2000 {  id_1999  };
          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2001;
          {
            Vec<1, uint32_t> leb_ref_119 { id_2000 };
            uint8_t id_2002 { 0 };
            Vec<1, uint8_t> id_2003 {  id_2002  };
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2004;
            {
              Vec<1, uint8_t> shft_ref_120 { id_2003 };
              Vec<1, Pointer> id_2005 {  dsum1_snd_115  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2006;
              {
                Vec<1, Pointer> p_ref_121 { id_2005 };
                bool while_flag_2007 { true };
                do {
                  uint8_t id_2008 { 0 };
                  Pointer id_2009 { p_ref_121[id_2008] };
                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2010 { id_2009.readU8() };
                  bool let_res_2011;
                  {
                    ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_122 { id_2010 };
                    bool letpair_res_2012;
                    {
                      auto leb128_fst_123 { std::get<0>(leb128_122) };
                      auto leb128_snd_124 { std::get<1>(leb128_122) };
                      uint8_t id_2013 { 0 };
                      Void id_2014 { ((void)(p_ref_121[id_2013] = leb128_snd_124), VOID) };
                      (void)id_2014;
                      uint8_t id_2015 { 0 };
                      uint8_t id_2016 { 127 };
                      uint8_t id_2017 { uint8_t(leb128_fst_123 & id_2016) };
                      uint32_t id_2018 { uint32_t(id_2017) };
                      uint8_t id_2019 { 0 };
                      uint8_t id_2020 { shft_ref_120[id_2019] };
                      uint32_t id_2021 { uint32_t(id_2018 << id_2020) };
                      uint8_t id_2022 { 0 };
                      uint32_t id_2023 { leb_ref_119[id_2022] };
                      uint32_t id_2024 { uint32_t(id_2021 | id_2023) };
                      Void id_2025 { ((void)(leb_ref_119[id_2015] = id_2024), VOID) };
                      (void)id_2025;
                      uint8_t id_2026 { 0 };
                      uint8_t id_2027 { 0 };
                      uint8_t id_2028 { shft_ref_120[id_2027] };
                      uint8_t id_2029 { 7 };
                      uint8_t id_2030 { uint8_t(id_2028 + id_2029) };
                      Void id_2031 { ((void)(shft_ref_120[id_2026] = id_2030), VOID) };
                      (void)id_2031;
                      uint8_t id_2032 { 128 };
                      bool id_2033 { bool(leb128_fst_123 >= id_2032) };
                      letpair_res_2012 = id_2033;
                    }
                    let_res_2011 = letpair_res_2012;
                  }
                  while_flag_2007 = let_res_2011;
                  if (while_flag_2007) {
                    (void)VOID;
                  }
                } while (while_flag_2007);
                (void)VOID;
                uint8_t id_2034 { 0 };
                uint32_t id_2035 { leb_ref_119[id_2034] };
                Size id_2036 { Size(id_2035) };
                uint8_t id_2037 { 0 };
                Pointer id_2038 { p_ref_121[id_2037] };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2039 { id_2036, id_2038 };
                let_res_2006 = id_2039;
              }
              let_res_2004 = let_res_2006;
            }
            let_res_2001 = let_res_2004;
          }
          ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 let_res_2040;
          {
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_125 { let_res_2001 };
            ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 letpair_res_2041;
            {
              auto dstring1_fst_126 { std::get<0>(dstring1_125) };
              auto dstring1_snd_127 { std::get<1>(dstring1_125) };
              ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2042 { dstring1_snd_127.readBytes(dstring1_fst_126) };
              ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 letpair_res_2043;
              {
                auto dstring2_fst_129 { std::get<0>(id_2042) };
                auto dstring2_snd_130 { std::get<1>(id_2042) };
                std::string id_2044 { dstring2_fst_129.toString() };
                ::dessser::gen::sync_key::per_client* id_2045 { new ::dessser::gen::sync_key::per_client(std::in_place_index<0>, id_2044) };
                ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 id_2046 { id_2045, dstring2_snd_130 };
                letpair_res_2043 = id_2046;
              }
              letpair_res_2041 = letpair_res_2043;
            }
            let_res_2040 = letpair_res_2041;
          }
          choose_res_1998 = let_res_2040;
        } else {
          uint16_t id_2047 { 1 };
          bool id_2048 { bool(dsum1_fst_114 == id_2047) };
          Void id_2049 { ((void)(assert(id_2048)), VOID) };
          (void)id_2049;
          ::dessser::gen::sync_key::tcce73bde988985bdd0bca77372a40274 id_2050 { per_dash_key_of_row_binary(dsum1_snd_115) };
          ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 letpair_res_2051;
          {
            auto dsum2_fst_117 { std::get<0>(id_2050) };
            auto dsum2_snd_118 { std::get<1>(id_2050) };
            ::dessser::gen::sync_key::per_client* id_2052 { new ::dessser::gen::sync_key::per_client(std::in_place_index<1>, dsum2_fst_117) };
            ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 id_2053 { id_2052, dsum2_snd_118 };
            letpair_res_2051 = id_2053;
          }
          choose_res_1998 = letpair_res_2051;
        }
        letpair_res_1995 = choose_res_1998;
      }
      let_res_1994 = letpair_res_1995;
    }
    ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 letpair_res_2054;
    {
      auto make_fst_135 { std::get<0>(let_res_1994) };
      auto make_snd_136 { std::get<1>(let_res_1994) };
      ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 id_2055 { make_fst_135, make_snd_136 };
      letpair_res_2054 = id_2055;
    }
    return letpair_res_2054;
  }
   };
  return fun1990;
}
std::function<::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43(Pointer)> per_client_of_row_binary(per_client_of_row_binary_init());

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
static std::function<::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23(Pointer)> per_tail_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23(Pointer)> fun2056 { [&fun2056](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2057 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2058;
    {
      auto du16_fst_57 { std::get<0>(id_2057) };
      auto du16_snd_58 { std::get<1>(id_2057) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2059 { du16_fst_57, du16_snd_58 };
      letpair_res_2058 = id_2059;
    }
    ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 let_res_2060;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_62 { letpair_res_2058 };
      ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 letpair_res_2061;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_2062 { 0 };
        bool id_2063 { bool(id_2062 == dsum1_fst_63) };
        ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 choose_res_2064;
        if (id_2063) {
          uint32_t id_2065 { 0U };
          Vec<1, uint32_t> id_2066 {  id_2065  };
          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2067;
          {
            Vec<1, uint32_t> leb_ref_71 { id_2066 };
            uint8_t id_2068 { 0 };
            Vec<1, uint8_t> id_2069 {  id_2068  };
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2070;
            {
              Vec<1, uint8_t> shft_ref_72 { id_2069 };
              Vec<1, Pointer> id_2071 {  dsum1_snd_64  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2072;
              {
                Vec<1, Pointer> p_ref_73 { id_2071 };
                bool while_flag_2073 { true };
                do {
                  uint8_t id_2074 { 0 };
                  Pointer id_2075 { p_ref_73[id_2074] };
                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2076 { id_2075.readU8() };
                  bool let_res_2077;
                  {
                    ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_74 { id_2076 };
                    bool letpair_res_2078;
                    {
                      auto leb128_fst_75 { std::get<0>(leb128_74) };
                      auto leb128_snd_76 { std::get<1>(leb128_74) };
                      uint8_t id_2079 { 0 };
                      Void id_2080 { ((void)(p_ref_73[id_2079] = leb128_snd_76), VOID) };
                      (void)id_2080;
                      uint8_t id_2081 { 0 };
                      uint8_t id_2082 { 127 };
                      uint8_t id_2083 { uint8_t(leb128_fst_75 & id_2082) };
                      uint32_t id_2084 { uint32_t(id_2083) };
                      uint8_t id_2085 { 0 };
                      uint8_t id_2086 { shft_ref_72[id_2085] };
                      uint32_t id_2087 { uint32_t(id_2084 << id_2086) };
                      uint8_t id_2088 { 0 };
                      uint32_t id_2089 { leb_ref_71[id_2088] };
                      uint32_t id_2090 { uint32_t(id_2087 | id_2089) };
                      Void id_2091 { ((void)(leb_ref_71[id_2081] = id_2090), VOID) };
                      (void)id_2091;
                      uint8_t id_2092 { 0 };
                      uint8_t id_2093 { 0 };
                      uint8_t id_2094 { shft_ref_72[id_2093] };
                      uint8_t id_2095 { 7 };
                      uint8_t id_2096 { uint8_t(id_2094 + id_2095) };
                      Void id_2097 { ((void)(shft_ref_72[id_2092] = id_2096), VOID) };
                      (void)id_2097;
                      uint8_t id_2098 { 128 };
                      bool id_2099 { bool(leb128_fst_75 >= id_2098) };
                      letpair_res_2078 = id_2099;
                    }
                    let_res_2077 = letpair_res_2078;
                  }
                  while_flag_2073 = let_res_2077;
                  if (while_flag_2073) {
                    (void)VOID;
                  }
                } while (while_flag_2073);
                (void)VOID;
                uint8_t id_2100 { 0 };
                uint32_t id_2101 { leb_ref_71[id_2100] };
                Size id_2102 { Size(id_2101) };
                uint8_t id_2103 { 0 };
                Pointer id_2104 { p_ref_73[id_2103] };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2105 { id_2102, id_2104 };
                let_res_2072 = id_2105;
              }
              let_res_2070 = let_res_2072;
            }
            let_res_2067 = let_res_2070;
          }
          ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 let_res_2106;
          {
            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_77 { let_res_2067 };
            ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 letpair_res_2107;
            {
              auto dstring1_fst_78 { std::get<0>(dstring1_77) };
              auto dstring1_snd_79 { std::get<1>(dstring1_77) };
              ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2108 { dstring1_snd_79.readBytes(dstring1_fst_78) };
              ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 letpair_res_2109;
              {
                auto dstring2_fst_81 { std::get<0>(id_2108) };
                auto dstring2_snd_82 { std::get<1>(id_2108) };
                std::string id_2110 { dstring2_fst_81.toString() };
                ::dessser::gen::sync_key::per_tail* id_2111 { new ::dessser::gen::sync_key::per_tail(std::in_place_index<0>, id_2110) };
                ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 id_2112 { id_2111, dstring2_snd_82 };
                letpair_res_2109 = id_2112;
              }
              letpair_res_2107 = letpair_res_2109;
            }
            let_res_2106 = letpair_res_2107;
          }
          choose_res_2064 = let_res_2106;
        } else {
          uint16_t id_2113 { 1 };
          bool id_2114 { bool(dsum1_fst_63 == id_2113) };
          Void id_2115 { ((void)(assert(id_2114)), VOID) };
          (void)id_2115;
          ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_2116 { dsum1_snd_64.readU32Le() };
          ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 letpair_res_2117;
          {
            auto du32_fst_66 { std::get<0>(id_2116) };
            auto du32_snd_67 { std::get<1>(id_2116) };
            ::dessser::gen::sync_key::per_tail* id_2118 { new ::dessser::gen::sync_key::per_tail(std::in_place_index<1>, du32_fst_66) };
            ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 id_2119 { id_2118, du32_snd_67 };
            letpair_res_2117 = id_2119;
          }
          choose_res_2064 = letpair_res_2117;
        }
        letpair_res_2061 = choose_res_2064;
      }
      let_res_2060 = letpair_res_2061;
    }
    ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 letpair_res_2120;
    {
      auto make_fst_87 { std::get<0>(let_res_2060) };
      auto make_snd_88 { std::get<1>(let_res_2060) };
      ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 id_2121 { make_fst_87, make_snd_88 };
      letpair_res_2120 = id_2121;
    }
    return letpair_res_2120;
  }
   };
  return fun2056;
}
std::function<::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23(Pointer)> per_tail_of_row_binary(per_tail_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let-pair "make_fst_660" "make_snd_661"
        (let "dsum1_143" (let-pair "du16_fst_138" "du16_snd_139" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_138") (identifier "du16_snd_139")))
          (let-pair "dsum1_fst_144" "dsum1_snd_145" (identifier "dsum1_143")
            (if (eq (u16 0) (identifier "dsum1_fst_144"))
              (make-tup
                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 0
                  (nop)) (identifier "dsum1_snd_145"))
              (if (eq (u16 1) (identifier "dsum1_fst_144"))
                (make-tup
                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 1
                    (nop)) (identifier "dsum1_snd_145"))
                (if (eq (u16 2) (identifier "dsum1_fst_144"))
                  (let "dstring1_644"
                    (let "leb_ref_638" (make-vec (u32 0))
                      (let "shft_ref_639" (make-vec (u8 0))
                        (let "p_ref_640" (make-vec (identifier "dsum1_snd_145"))
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
                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 2
                            (string-of-bytes (identifier "dstring2_fst_648"))) 
                          (identifier "dstring2_snd_649")))))
                  (if (eq (u16 3) (identifier "dsum1_fst_144"))
                    (let "dtup_617" (apply (ext-identifier src_path of-row-binary) (identifier "dsum1_snd_145"))
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
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 3
                                  (make-tup (identifier "dtup_fst_618") (string-of-bytes (identifier "dstring2_fst_630")))) 
                                (identifier "dstring2_snd_631")))))))
                    (if (eq (u16 4) (identifier "dsum1_fst_144"))
                      (make-tup
                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 4
                          (nop)) (identifier "dsum1_snd_145"))
                      (if (eq (u16 5) (identifier "dsum1_fst_144"))
                        (let "dtup_425" (apply (ext-identifier site_name of-row-binary) (identifier "dsum1_snd_145"))
                          (let-pair "dtup_fst_426" "dtup_snd_427" (identifier "dtup_425")
                            (let-pair "dtup_fst_609" "dtup_snd_610"
                              (let "dsum1_434" (let-pair "du16_fst_429" "du16_snd_430" (read-u16 little-endian (identifier "dtup_snd_427")) (make-tup (identifier "du16_fst_429") (identifier "du16_snd_430")))
                                (let-pair "dsum1_fst_435" "dsum1_snd_436" 
                                  (identifier "dsum1_434")
                                  (if (eq (u16 0) (identifier "dsum1_fst_435"))
                                    (make-tup
                                      (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 0
                                        (nop)) (identifier "dsum1_snd_436"))
                                    (if (eq (u16 1) (identifier "dsum1_fst_435"))
                                      (let "dtup_581"
                                        (let "dstring1_575"
                                          (let "leb_ref_569" (make-vec (u32 0))
                                            (let "shft_ref_570" (make-vec (u8 0))
                                              (let "p_ref_571" (make-vec (identifier "dsum1_snd_436"))
                                                (seq
                                                  (while
                                                    (let "leb128_572" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_571")))
                                                      (let-pair "leb128_fst_573" "leb128_snd_574" 
                                                        (identifier "leb128_572")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_571") (identifier "leb128_snd_574"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_569")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_573") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_570")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_569")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_570") (add (unsafe-nth (u8 0) (identifier "shft_ref_570")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_573") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_569"))) (unsafe-nth (u8 0) (identifier "p_ref_571")))))))
                                          (let-pair "dstring1_fst_576" "dstring1_snd_577" 
                                            (identifier "dstring1_575")
                                            (let-pair "dstring2_fst_579" "dstring2_snd_580" 
                                              (read-bytes (identifier "dstring1_snd_577") (identifier "dstring1_fst_576")) 
                                              (make-tup (string-of-bytes (identifier "dstring2_fst_579")) (identifier "dstring2_snd_580")))))
                                        (let-pair "dtup_fst_582" "dtup_snd_583" 
                                          (identifier "dtup_581")
                                          (let-pair "dtup_fst_600" "dtup_snd_601"
                                            (let "dsum1_590" (let-pair "du16_fst_585" "du16_snd_586" (read-u16 little-endian (identifier "dtup_snd_583")) (make-tup (identifier "du16_fst_585") (identifier "du16_snd_586")))
                                              (let-pair "dsum1_fst_591" "dsum1_snd_592" 
                                                (identifier "dsum1_590")
                                                (if (eq (u16 0) (identifier "dsum1_fst_591")) 
                                                  (make-tup (construct "[Host Void | Port Void]" 0 (nop)) (identifier "dsum1_snd_592"))
                                                  (seq (assert (eq (identifier "dsum1_fst_591") (u16 1))) (make-tup (construct "[Host Void | Port Void]" 1 (nop)) (identifier "dsum1_snd_592"))))))
                                            (make-tup
                                              (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 1
                                                (make-tup (identifier "dtup_fst_582") (identifier "dtup_fst_600"))) 
                                              (identifier "dtup_snd_601")))))
                                      (if (eq (u16 2) (identifier "dsum1_fst_435"))
                                        (let "dtup_470" (apply (ext-identifier fq_name of-row-binary) (identifier "dsum1_snd_436"))
                                          (let-pair "dtup_fst_471" "dtup_snd_472" 
                                            (identifier "dtup_470")
                                            (let-pair "dtup_fst_564" "dtup_snd_565"
                                              (let "dsum1_479" (let-pair "du16_fst_474" "du16_snd_475" (read-u16 little-endian (identifier "dtup_snd_472")) (make-tup (identifier "du16_fst_474") (identifier "du16_snd_475")))
                                                (let-pair "dsum1_fst_480" "dsum1_snd_481" 
                                                  (identifier "dsum1_479")
                                                  (if (eq (u16 0) (identifier "dsum1_fst_480"))
                                                    (make-tup
                                                      (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 0
                                                        (nop)) (identifier "dsum1_snd_481"))
                                                    (if (eq (u16 1) (identifier "dsum1_fst_480"))
                                                      (make-tup
                                                        (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 1
                                                          (nop)) (identifier "dsum1_snd_481"))
                                                      (if (eq (u16 2) (identifier "dsum1_fst_480"))
                                                        (make-tup
                                                          (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 2
                                                            (nop)) (identifier "dsum1_snd_481"))
                                                        (if (eq (u16 3) (identifier "dsum1_fst_480"))
                                                          (make-tup
                                                            (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 3
                                                              (nop)) 
                                                            (identifier "dsum1_snd_481"))
                                                          (if (eq (u16 4) (identifier "dsum1_fst_480"))
                                                            (make-tup
                                                              (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 4
                                                                (nop)) 
                                                              (identifier "dsum1_snd_481"))
                                                            (if (eq (u16 5) (identifier "dsum1_fst_480"))
                                                              (make-tup
                                                                (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 5
                                                                  (nop)) 
                                                                (identifier "dsum1_snd_481"))
                                                              (if (eq (u16 6) (identifier "dsum1_fst_480"))
                                                                (let "dtup_503"
                                                                  (let "dstring1_497"
                                                                    (let "leb_ref_491" 
                                                                    (make-vec (u32 0))
                                                                    (let "shft_ref_492" 
                                                                    (make-vec (u8 0))
                                                                    (let "p_ref_493" 
                                                                    (make-vec (identifier "dsum1_snd_481"))
                                                                    (seq
                                                                    (while
                                                                    (let "leb128_494" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_493")))
                                                                    (let-pair "leb128_fst_495" "leb128_snd_496" 
                                                                    (identifier "leb128_494")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_493") (identifier "leb128_snd_496"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_491")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_495") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_492")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_491")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_492") (add (unsafe-nth (u8 0) (identifier "shft_ref_492")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_495") (u8 128))))) 
                                                                    (nop)) 
                                                                    (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_491"))) (unsafe-nth (u8 0) (identifier "p_ref_493")))))))
                                                                    (let-pair "dstring1_fst_498" "dstring1_snd_499" 
                                                                    (identifier "dstring1_497")
                                                                    (let-pair "dstring2_fst_501" "dstring2_snd_502" 
                                                                    (read-bytes (identifier "dstring1_snd_499") (identifier "dstring1_fst_498"))
                                                                    (make-tup (string-of-bytes (identifier "dstring2_fst_501")) (identifier "dstring2_snd_502")))))
                                                                  (let-pair "dtup_fst_504" "dtup_snd_505" 
                                                                    (identifier "dtup_503")
                                                                    (let-pair "dtup_fst_540" "dtup_snd_541"
                                                                    (let "dsum1_512"
                                                                    (let-pair "du16_fst_507" "du16_snd_508" (read-u16 little-endian (identifier "dtup_snd_505")) (make-tup (identifier "du16_fst_507") (identifier "du16_snd_508")))
                                                                    (let-pair "dsum1_fst_513" "dsum1_snd_514" 
                                                                    (identifier "dsum1_512")
                                                                    (if 
                                                                    (eq (u16 0) (identifier "dsum1_fst_513"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 0
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_514"))
                                                                    (if 
                                                                    (eq (u16 1) (identifier "dsum1_fst_513"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 1
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_514"))
                                                                    (if 
                                                                    (eq (u16 2) (identifier "dsum1_fst_513"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 2
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_514"))
                                                                    (if 
                                                                    (eq (u16 3) (identifier "dsum1_fst_513"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 3
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_514"))
                                                                    (if 
                                                                    (eq (u16 4) (identifier "dsum1_fst_513"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 4
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_514"))
                                                                    (if 
                                                                    (eq (u16 5) (identifier "dsum1_fst_513"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 5
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_514"))
                                                                    (if 
                                                                    (eq (u16 6) (identifier "dsum1_fst_513"))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 6
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_514"))
                                                                    (seq 
                                                                    (assert (eq (identifier "dsum1_fst_513") (u16 7)))
                                                                    (make-tup
                                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 7
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_514"))))))))))))
                                                                    (make-tup
                                                                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 6
                                                                    (make-tup (identifier "dtup_fst_504") (identifier "dtup_fst_540"))) 
                                                                    (identifier "dtup_snd_541")))))
                                                                (if (eq (u16 7) (identifier "dsum1_fst_480"))
                                                                  (let-pair "du32_fst_486" "du32_snd_487" 
                                                                    (read-u32 little-endian (identifier "dsum1_snd_481"))
                                                                    (make-tup
                                                                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 7
                                                                    (identifier "du32_fst_486")) 
                                                                    (identifier "du32_snd_487")))
                                                                  (seq 
                                                                    (assert (eq (identifier "dsum1_fst_480") (u16 8)))
                                                                    (make-tup
                                                                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 8
                                                                    (nop)) 
                                                                    (identifier "dsum1_snd_481")))))))))))))
                                              (make-tup
                                                (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 2
                                                  (make-tup (identifier "dtup_fst_471") (identifier "dtup_fst_564"))) 
                                                (identifier "dtup_snd_565")))))
                                        (seq (assert (eq (identifier "dsum1_fst_435") (u16 3)))
                                          (let "dtup_449"
                                            (let "dstring1_443"
                                              (let "leb_ref_437" (make-vec (u32 0))
                                                (let "shft_ref_438" (make-vec (u8 0))
                                                  (let "p_ref_439" (make-vec (identifier "dsum1_snd_436"))
                                                    (seq
                                                      (while
                                                        (let "leb128_440" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_439")))
                                                          (let-pair "leb128_fst_441" "leb128_snd_442" 
                                                            (identifier "leb128_440")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_439") (identifier "leb128_snd_442"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_437")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_441") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_438")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_437")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_438") (add (unsafe-nth (u8 0) (identifier "shft_ref_438")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_441") (u8 128))))) 
                                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_437"))) (unsafe-nth (u8 0) (identifier "p_ref_439")))))))
                                              (let-pair "dstring1_fst_444" "dstring1_snd_445" 
                                                (identifier "dstring1_443")
                                                (let-pair "dstring2_fst_447" "dstring2_snd_448" 
                                                  (read-bytes (identifier "dstring1_snd_445") (identifier "dstring1_fst_444")) 
                                                  (make-tup (string-of-bytes (identifier "dstring2_fst_447")) (identifier "dstring2_snd_448")))))
                                            (let-pair "dtup_fst_450" "dtup_snd_451" 
                                              (identifier "dtup_449")
                                              (let "dsum1_458" (let-pair "du16_fst_453" "du16_snd_454" (read-u16 little-endian (identifier "dtup_snd_451")) (make-tup (identifier "du16_fst_453") (identifier "du16_snd_454")))
                                                (let-pair "dsum1_fst_459" "dsum1_snd_460" 
                                                  (identifier "dsum1_458")
                                                  (seq (assert (eq (identifier "dsum1_fst_459") (u16 0)))
                                                    (make-tup
                                                      (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]" 3
                                                        (make-tup (identifier "dtup_fst_450") (construct "[Executable Void]" 0 (nop)))) 
                                                      (identifier "dsum1_snd_460")))))))))))))
                              (make-tup
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 5
                                  (make-tup (identifier "dtup_fst_426") (identifier "dtup_fst_609"))) 
                                (identifier "dtup_snd_610")))))
                        (if (eq (u16 6) (identifier "dsum1_fst_144"))
                          (let-pair "dsum2_fst_423" "dsum2_snd_424"
                            (let "dsum1_398" (let-pair "du16_fst_393" "du16_snd_394" (read-u16 little-endian (identifier "dsum1_snd_145")) (make-tup (identifier "du16_fst_393") (identifier "du16_snd_394")))
                              (let-pair "dsum1_fst_399" "dsum1_snd_400" 
                                (identifier "dsum1_398")
                                (if (eq (u16 0) (identifier "dsum1_fst_399")) 
                                  (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 0 (nop)) (identifier "dsum1_snd_400"))
                                  (if (eq (u16 1) (identifier "dsum1_fst_399")) 
                                    (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 1 (nop)) (identifier "dsum1_snd_400"))
                                    (seq (assert (eq (identifier "dsum1_fst_399") (u16 2)))
                                      (let "dstring1_407"
                                        (let "leb_ref_401" (make-vec (u32 0))
                                          (let "shft_ref_402" (make-vec (u8 0))
                                            (let "p_ref_403" (make-vec (identifier "dsum1_snd_400"))
                                              (seq
                                                (while
                                                  (let "leb128_404" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_403")))
                                                    (let-pair "leb128_fst_405" "leb128_snd_406" 
                                                      (identifier "leb128_404")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_403") (identifier "leb128_snd_406"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_401")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_405") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_402")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_401")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_402") (add (unsafe-nth (u8 0) (identifier "shft_ref_402")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_405") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_401"))) (unsafe-nth (u8 0) (identifier "p_ref_403")))))))
                                        (let-pair "dstring1_fst_408" "dstring1_snd_409" 
                                          (identifier "dstring1_407")
                                          (let-pair "dstring2_fst_411" "dstring2_snd_412" 
                                            (read-bytes (identifier "dstring1_snd_409") (identifier "dstring1_fst_408"))
                                            (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 2 (string-of-bytes (identifier "dstring2_fst_411"))) (identifier "dstring2_snd_412"))))))))))
                            (make-tup
                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 6
                                (identifier "dsum2_fst_423")) (identifier "dsum2_snd_424")))
                          (if (eq (u16 7) (identifier "dsum1_fst_144"))
                            (let "dtup_365" (apply (ext-identifier site_name of-row-binary) (identifier "dsum1_snd_145"))
                              (let-pair "dtup_fst_366" "dtup_snd_367" 
                                (identifier "dtup_365")
                                (let "dtup_368" (apply (ext-identifier fq_name of-row-binary) (identifier "dtup_snd_367"))
                                  (let-pair "dtup_fst_369" "dtup_snd_370" 
                                    (identifier "dtup_368")
                                    (let "dtup_383"
                                      (let "dstring1_377"
                                        (let "leb_ref_371" (make-vec (u32 0))
                                          (let "shft_ref_372" (make-vec (u8 0))
                                            (let "p_ref_373" (make-vec (identifier "dtup_snd_370"))
                                              (seq
                                                (while
                                                  (let "leb128_374" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_373")))
                                                    (let-pair "leb128_fst_375" "leb128_snd_376" 
                                                      (identifier "leb128_374")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_373") (identifier "leb128_snd_376"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_371")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_375") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_372")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_371")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_372") (add (unsafe-nth (u8 0) (identifier "shft_ref_372")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_375") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_371"))) (unsafe-nth (u8 0) (identifier "p_ref_373")))))))
                                        (let-pair "dstring1_fst_378" "dstring1_snd_379" 
                                          (identifier "dstring1_377")
                                          (let-pair "dstring2_fst_381" "dstring2_snd_382" 
                                            (read-bytes (identifier "dstring1_snd_379") (identifier "dstring1_fst_378")) 
                                            (make-tup (string-of-bytes (identifier "dstring2_fst_381")) (identifier "dstring2_snd_382")))))
                                      (let-pair "dtup_fst_384" "dtup_snd_385" 
                                        (identifier "dtup_383")
                                        (let-pair "dtup_fst_387" "dtup_snd_388" 
                                          (apply (identifier "per_tail-of-row-binary") (identifier "dtup_snd_385"))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 7
                                              (make-tup (identifier "dtup_fst_366") (identifier "dtup_fst_369") (identifier "dtup_fst_384") (identifier "dtup_fst_387"))) 
                                            (identifier "dtup_snd_388")))))))))
                            (if (eq (u16 8) (identifier "dsum1_fst_144"))
                              (let-pair "du16_fst_360" "du16_snd_361" 
                                (read-u16 little-endian (identifier "dsum1_snd_145"))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 8
                                    (identifier "du16_fst_360")) (identifier "du16_snd_361")))
                              (if (eq (u16 9) (identifier "dsum1_fst_144"))
                                (let-pair "dsum2_fst_357" "dsum2_snd_358"
                                  (if (eq (peek-u8 (identifier "dsum1_snd_145") (size 0)) (u8 1)) 
                                    (make-tup (null "$sync_socket") (ptr-add (identifier "dsum1_snd_145") (size 1)))
                                    (let-pair "make1_1_fst_354" "make1_1_snd_355" 
                                      (apply (ext-identifier sync_socket of-row-binary) (ptr-add (identifier "dsum1_snd_145") (size 1))) 
                                      (make-tup (not-null (identifier "make1_1_fst_354")) (identifier "make1_1_snd_355"))))
                                  (make-tup
                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 9
                                      (identifier "dsum2_fst_357")) (identifier "dsum2_snd_358")))
                                (if (eq (u16 10) (identifier "dsum1_fst_144"))
                                  (make-tup
                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 10
                                      (nop)) (identifier "dsum1_snd_145"))
                                  (if (eq (u16 11) (identifier "dsum1_fst_144"))
                                    (let "dtup_341" (apply (ext-identifier sync_socket of-row-binary) (identifier "dsum1_snd_145"))
                                      (let-pair "dtup_fst_342" "dtup_snd_343" 
                                        (identifier "dtup_341")
                                        (let-pair "dtup_fst_345" "dtup_snd_346" 
                                          (apply (identifier "per_client-of-row-binary") (identifier "dtup_snd_343"))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 11
                                              (make-tup (identifier "dtup_fst_342") (identifier "dtup_fst_345"))) 
                                            (identifier "dtup_snd_346")))))
                                    (if (eq (u16 12) (identifier "dsum1_fst_144"))
                                      (let "dtup_332"
                                        (let "dstring1_326"
                                          (let "leb_ref_320" (make-vec (u32 0))
                                            (let "shft_ref_321" (make-vec (u8 0))
                                              (let "p_ref_322" (make-vec (identifier "dsum1_snd_145"))
                                                (seq
                                                  (while
                                                    (let "leb128_323" 
                                                      (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_322")))
                                                      (let-pair "leb128_fst_324" "leb128_snd_325" 
                                                        (identifier "leb128_323")
                                                        (seq (set-vec (u8 0) (identifier "p_ref_322") (identifier "leb128_snd_325"))
                                                          (set-vec (u8 0) 
                                                            (identifier "leb_ref_320")
                                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_324") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_321")))
                                                              (unsafe-nth (u8 0) (identifier "leb_ref_320")))) 
                                                          (set-vec (u8 0) (identifier "shft_ref_321") (add (unsafe-nth (u8 0) (identifier "shft_ref_321")) (u8 7))) 
                                                          (ge (identifier "leb128_fst_324") (u8 128))))) 
                                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_320"))) (unsafe-nth (u8 0) (identifier "p_ref_322")))))))
                                          (let-pair "dstring1_fst_327" "dstring1_snd_328" 
                                            (identifier "dstring1_326")
                                            (let-pair "dstring2_fst_330" "dstring2_snd_331" 
                                              (read-bytes (identifier "dstring1_snd_328") (identifier "dstring1_fst_327")) 
                                              (make-tup (string-of-bytes (identifier "dstring2_fst_330")) (identifier "dstring2_snd_331")))))
                                        (let-pair "dtup_fst_333" "dtup_snd_334" 
                                          (identifier "dtup_332")
                                          (let-pair "dtup_fst_336" "dtup_snd_337" 
                                            (apply (identifier "per_dash_key-of-row-binary") (identifier "dtup_snd_334"))
                                            (make-tup
                                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 12
                                                (make-tup (identifier "dtup_fst_333") (identifier "dtup_fst_336"))) 
                                              (identifier "dtup_snd_337")))))
                                      (if (eq (u16 13) (identifier "dsum1_fst_144"))
                                        (make-tup
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 13
                                            (nop)) (identifier "dsum1_snd_145"))
                                        (if (eq (u16 14) (identifier "dsum1_fst_144"))
                                          (let "dtup_269"
                                            (let "dstring1_263"
                                              (let "leb_ref_257" (make-vec (u32 0))
                                                (let "shft_ref_258" (make-vec (u8 0))
                                                  (let "p_ref_259" (make-vec (identifier "dsum1_snd_145"))
                                                    (seq
                                                      (while
                                                        (let "leb128_260" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_259")))
                                                          (let-pair "leb128_fst_261" "leb128_snd_262" 
                                                            (identifier "leb128_260")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_259") (identifier "leb128_snd_262"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_257")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_261") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_258")))
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
                                              (let-pair "dtup_fst_312" "dtup_snd_313"
                                                (let "dsum1_278" (let-pair "du16_fst_273" "du16_snd_274" (read-u16 little-endian (identifier "dtup_snd_271")) (make-tup (identifier "du16_fst_273") (identifier "du16_snd_274")))
                                                  (let-pair "dsum1_fst_279" "dsum1_snd_280" 
                                                    (identifier "dsum1_278")
                                                    (if (eq (u16 0) (identifier "dsum1_fst_279"))
                                                      (let "dstring1_302"
                                                        (let "leb_ref_296" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_297" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_298" 
                                                              (make-vec (identifier "dsum1_snd_280"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_299" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_298")))
                                                                    (let-pair "leb128_fst_300" "leb128_snd_301" 
                                                                    (identifier "leb128_299")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_298") (identifier "leb128_snd_301"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_296")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_300") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_297")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_296")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_297") (add (unsafe-nth (u8 0) (identifier "shft_ref_297")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_300") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_296"))) (unsafe-nth (u8 0) (identifier "p_ref_298")))))))
                                                        (let-pair "dstring1_fst_303" "dstring1_snd_304" 
                                                          (identifier "dstring1_302")
                                                          (let-pair "dstring2_fst_306" "dstring2_snd_307" 
                                                            (read-bytes (identifier "dstring1_snd_304") (identifier "dstring1_fst_303"))
                                                            (make-tup (construct "[Contacts STRING | Inhibition STRING]" 0 (string-of-bytes (identifier "dstring2_fst_306"))) (identifier "dstring2_snd_307")))))
                                                      (seq (assert (eq (identifier "dsum1_fst_279") (u16 1)))
                                                        (let "dstring1_287"
                                                          (let "leb_ref_281" 
                                                            (make-vec (u32 0))
                                                            (let "shft_ref_282" 
                                                              (make-vec (u8 0))
                                                              (let "p_ref_283" 
                                                                (make-vec (identifier "dsum1_snd_280"))
                                                                (seq
                                                                  (while
                                                                    (let "leb128_284" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_283")))
                                                                    (let-pair "leb128_fst_285" "leb128_snd_286" 
                                                                    (identifier "leb128_284")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_283") (identifier "leb128_snd_286"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_281")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_285") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_282")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_281")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_282") (add (unsafe-nth (u8 0) (identifier "shft_ref_282")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_285") (u8 128))))) 
                                                                    (nop)) 
                                                                  (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_281"))) (unsafe-nth (u8 0) (identifier "p_ref_283")))))))
                                                          (let-pair "dstring1_fst_288" "dstring1_snd_289" 
                                                            (identifier "dstring1_287")
                                                            (let-pair "dstring2_fst_291" "dstring2_snd_292" 
                                                              (read-bytes (identifier "dstring1_snd_289") (identifier "dstring1_fst_288"))
                                                              (make-tup (construct "[Contacts STRING | Inhibition STRING]" 1 (string-of-bytes (identifier "dstring2_fst_291"))) (identifier "dstring2_snd_292")))))))))
                                                (make-tup
                                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 14
                                                    (make-tup (identifier "dtup_fst_270") (identifier "dtup_fst_312"))) 
                                                  (identifier "dtup_snd_313")))))
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
                                                    (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite ($site_name; [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker ($fq_name; [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]) | PerProgram (STRING; [Executable Void])]) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams (STRING; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]) | Journal (FLOAT; U32)])]" 15
                                                      (make-tup (identifier "dtup_fst_159") (identifier "dtup_fst_252"))) 
                                                    (identifier "dtup_snd_253"))))))))))))))))))))))) 
        (make-tup (identifier "make_fst_660") (identifier "make_snd_661"))))
 */
static std::function<::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4(Pointer)> fun2122 { [&fun2122](Pointer p_0) {
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2123 { p_0.readU16Le() };
    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2124;
    {
      auto du16_fst_138 { std::get<0>(id_2123) };
      auto du16_snd_139 { std::get<1>(id_2123) };
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2125 { du16_fst_138, du16_snd_139 };
      letpair_res_2124 = id_2125;
    }
    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2126;
    {
      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_143 { letpair_res_2124 };
      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2127;
      {
        auto dsum1_fst_144 { std::get<0>(dsum1_143) };
        auto dsum1_snd_145 { std::get<1>(dsum1_143) };
        uint16_t id_2128 { 0 };
        bool id_2129 { bool(id_2128 == dsum1_fst_144) };
        ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2130;
        if (id_2129) {
          (void)VOID;
          ::dessser::gen::sync_key::t* id_2131 { new ::dessser::gen::sync_key::t(std::in_place_index<0>, VOID) };
          ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2132 { id_2131, dsum1_snd_145 };
          choose_res_2130 = id_2132;
        } else {
          uint16_t id_2133 { 1 };
          bool id_2134 { bool(id_2133 == dsum1_fst_144) };
          ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2135;
          if (id_2134) {
            (void)VOID;
            ::dessser::gen::sync_key::t* id_2136 { new ::dessser::gen::sync_key::t(std::in_place_index<1>, VOID) };
            ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2137 { id_2136, dsum1_snd_145 };
            choose_res_2135 = id_2137;
          } else {
            uint16_t id_2138 { 2 };
            bool id_2139 { bool(id_2138 == dsum1_fst_144) };
            ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2140;
            if (id_2139) {
              uint32_t id_2141 { 0U };
              Vec<1, uint32_t> id_2142 {  id_2141  };
              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2143;
              {
                Vec<1, uint32_t> leb_ref_638 { id_2142 };
                uint8_t id_2144 { 0 };
                Vec<1, uint8_t> id_2145 {  id_2144  };
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2146;
                {
                  Vec<1, uint8_t> shft_ref_639 { id_2145 };
                  Vec<1, Pointer> id_2147 {  dsum1_snd_145  };
                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2148;
                  {
                    Vec<1, Pointer> p_ref_640 { id_2147 };
                    bool while_flag_2149 { true };
                    do {
                      uint8_t id_2150 { 0 };
                      Pointer id_2151 { p_ref_640[id_2150] };
                      ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2152 { id_2151.readU8() };
                      bool let_res_2153;
                      {
                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_641 { id_2152 };
                        bool letpair_res_2154;
                        {
                          auto leb128_fst_642 { std::get<0>(leb128_641) };
                          auto leb128_snd_643 { std::get<1>(leb128_641) };
                          uint8_t id_2155 { 0 };
                          Void id_2156 { ((void)(p_ref_640[id_2155] = leb128_snd_643), VOID) };
                          (void)id_2156;
                          uint8_t id_2157 { 0 };
                          uint8_t id_2158 { 127 };
                          uint8_t id_2159 { uint8_t(leb128_fst_642 & id_2158) };
                          uint32_t id_2160 { uint32_t(id_2159) };
                          uint8_t id_2161 { 0 };
                          uint8_t id_2162 { shft_ref_639[id_2161] };
                          uint32_t id_2163 { uint32_t(id_2160 << id_2162) };
                          uint8_t id_2164 { 0 };
                          uint32_t id_2165 { leb_ref_638[id_2164] };
                          uint32_t id_2166 { uint32_t(id_2163 | id_2165) };
                          Void id_2167 { ((void)(leb_ref_638[id_2157] = id_2166), VOID) };
                          (void)id_2167;
                          uint8_t id_2168 { 0 };
                          uint8_t id_2169 { 0 };
                          uint8_t id_2170 { shft_ref_639[id_2169] };
                          uint8_t id_2171 { 7 };
                          uint8_t id_2172 { uint8_t(id_2170 + id_2171) };
                          Void id_2173 { ((void)(shft_ref_639[id_2168] = id_2172), VOID) };
                          (void)id_2173;
                          uint8_t id_2174 { 128 };
                          bool id_2175 { bool(leb128_fst_642 >= id_2174) };
                          letpair_res_2154 = id_2175;
                        }
                        let_res_2153 = letpair_res_2154;
                      }
                      while_flag_2149 = let_res_2153;
                      if (while_flag_2149) {
                        (void)VOID;
                      }
                    } while (while_flag_2149);
                    (void)VOID;
                    uint8_t id_2176 { 0 };
                    uint32_t id_2177 { leb_ref_638[id_2176] };
                    Size id_2178 { Size(id_2177) };
                    uint8_t id_2179 { 0 };
                    Pointer id_2180 { p_ref_640[id_2179] };
                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2181 { id_2178, id_2180 };
                    let_res_2148 = id_2181;
                  }
                  let_res_2146 = let_res_2148;
                }
                let_res_2143 = let_res_2146;
              }
              ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2182;
              {
                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_644 { let_res_2143 };
                ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2183;
                {
                  auto dstring1_fst_645 { std::get<0>(dstring1_644) };
                  auto dstring1_snd_646 { std::get<1>(dstring1_644) };
                  ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2184 { dstring1_snd_646.readBytes(dstring1_fst_645) };
                  ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2185;
                  {
                    auto dstring2_fst_648 { std::get<0>(id_2184) };
                    auto dstring2_snd_649 { std::get<1>(id_2184) };
                    std::string id_2186 { dstring2_fst_648.toString() };
                    ::dessser::gen::sync_key::t* id_2187 { new ::dessser::gen::sync_key::t(std::in_place_index<2>, id_2186) };
                    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2188 { id_2187, dstring2_snd_649 };
                    letpair_res_2185 = id_2188;
                  }
                  letpair_res_2183 = letpair_res_2185;
                }
                let_res_2182 = letpair_res_2183;
              }
              choose_res_2140 = let_res_2182;
            } else {
              uint16_t id_2189 { 3 };
              bool id_2190 { bool(id_2189 == dsum1_fst_144) };
              ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2191;
              if (id_2190) {
                auto fun2192 { dessser::gen::src_path::of_row_binary };
                ::dessser::gen::sync_key::t6886b6ff042edb771f45016f12178bb0 id_2193 { fun2192(dsum1_snd_145) };
                ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2194;
                {
                  ::dessser::gen::sync_key::t6886b6ff042edb771f45016f12178bb0 dtup_617 { id_2193 };
                  ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2195;
                  {
                    auto dtup_fst_618 { std::get<0>(dtup_617) };
                    auto dtup_snd_619 { std::get<1>(dtup_617) };
                    uint32_t id_2196 { 0U };
                    Vec<1, uint32_t> id_2197 {  id_2196  };
                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2198;
                    {
                      Vec<1, uint32_t> leb_ref_620 { id_2197 };
                      uint8_t id_2199 { 0 };
                      Vec<1, uint8_t> id_2200 {  id_2199  };
                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2201;
                      {
                        Vec<1, uint8_t> shft_ref_621 { id_2200 };
                        Vec<1, Pointer> id_2202 {  dtup_snd_619  };
                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2203;
                        {
                          Vec<1, Pointer> p_ref_622 { id_2202 };
                          bool while_flag_2204 { true };
                          do {
                            uint8_t id_2205 { 0 };
                            Pointer id_2206 { p_ref_622[id_2205] };
                            ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2207 { id_2206.readU8() };
                            bool let_res_2208;
                            {
                              ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_623 { id_2207 };
                              bool letpair_res_2209;
                              {
                                auto leb128_fst_624 { std::get<0>(leb128_623) };
                                auto leb128_snd_625 { std::get<1>(leb128_623) };
                                uint8_t id_2210 { 0 };
                                Void id_2211 { ((void)(p_ref_622[id_2210] = leb128_snd_625), VOID) };
                                (void)id_2211;
                                uint8_t id_2212 { 0 };
                                uint8_t id_2213 { 127 };
                                uint8_t id_2214 { uint8_t(leb128_fst_624 & id_2213) };
                                uint32_t id_2215 { uint32_t(id_2214) };
                                uint8_t id_2216 { 0 };
                                uint8_t id_2217 { shft_ref_621[id_2216] };
                                uint32_t id_2218 { uint32_t(id_2215 << id_2217) };
                                uint8_t id_2219 { 0 };
                                uint32_t id_2220 { leb_ref_620[id_2219] };
                                uint32_t id_2221 { uint32_t(id_2218 | id_2220) };
                                Void id_2222 { ((void)(leb_ref_620[id_2212] = id_2221), VOID) };
                                (void)id_2222;
                                uint8_t id_2223 { 0 };
                                uint8_t id_2224 { 0 };
                                uint8_t id_2225 { shft_ref_621[id_2224] };
                                uint8_t id_2226 { 7 };
                                uint8_t id_2227 { uint8_t(id_2225 + id_2226) };
                                Void id_2228 { ((void)(shft_ref_621[id_2223] = id_2227), VOID) };
                                (void)id_2228;
                                uint8_t id_2229 { 128 };
                                bool id_2230 { bool(leb128_fst_624 >= id_2229) };
                                letpair_res_2209 = id_2230;
                              }
                              let_res_2208 = letpair_res_2209;
                            }
                            while_flag_2204 = let_res_2208;
                            if (while_flag_2204) {
                              (void)VOID;
                            }
                          } while (while_flag_2204);
                          (void)VOID;
                          uint8_t id_2231 { 0 };
                          uint32_t id_2232 { leb_ref_620[id_2231] };
                          Size id_2233 { Size(id_2232) };
                          uint8_t id_2234 { 0 };
                          Pointer id_2235 { p_ref_622[id_2234] };
                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2236 { id_2233, id_2235 };
                          let_res_2203 = id_2236;
                        }
                        let_res_2201 = let_res_2203;
                      }
                      let_res_2198 = let_res_2201;
                    }
                    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2237;
                    {
                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_626 { let_res_2198 };
                      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2238;
                      {
                        auto dstring1_fst_627 { std::get<0>(dstring1_626) };
                        auto dstring1_snd_628 { std::get<1>(dstring1_626) };
                        ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2239 { dstring1_snd_628.readBytes(dstring1_fst_627) };
                        ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2240;
                        {
                          auto dstring2_fst_630 { std::get<0>(id_2239) };
                          auto dstring2_snd_631 { std::get<1>(id_2239) };
                          std::string id_2241 { dstring2_fst_630.toString() };
                          ::dessser::gen::sync_key::t3f2a416abcbd7d33d681d9d47445767b id_2242 { dtup_fst_618, id_2241 };
                          ::dessser::gen::sync_key::t* id_2243 { new ::dessser::gen::sync_key::t(std::in_place_index<3>, id_2242) };
                          ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2244 { id_2243, dstring2_snd_631 };
                          letpair_res_2240 = id_2244;
                        }
                        letpair_res_2238 = letpair_res_2240;
                      }
                      let_res_2237 = letpair_res_2238;
                    }
                    letpair_res_2195 = let_res_2237;
                  }
                  let_res_2194 = letpair_res_2195;
                }
                choose_res_2191 = let_res_2194;
              } else {
                uint16_t id_2245 { 4 };
                bool id_2246 { bool(id_2245 == dsum1_fst_144) };
                ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2247;
                if (id_2246) {
                  (void)VOID;
                  ::dessser::gen::sync_key::t* id_2248 { new ::dessser::gen::sync_key::t(std::in_place_index<4>, VOID) };
                  ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2249 { id_2248, dsum1_snd_145 };
                  choose_res_2247 = id_2249;
                } else {
                  uint16_t id_2250 { 5 };
                  bool id_2251 { bool(id_2250 == dsum1_fst_144) };
                  ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2252;
                  if (id_2251) {
                    auto fun2253 { dessser::gen::site_name::of_row_binary };
                    ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea id_2254 { fun2253(dsum1_snd_145) };
                    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2255;
                    {
                      ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea dtup_425 { id_2254 };
                      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2256;
                      {
                        auto dtup_fst_426 { std::get<0>(dtup_425) };
                        auto dtup_snd_427 { std::get<1>(dtup_425) };
                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2257 { dtup_snd_427.readU16Le() };
                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2258;
                        {
                          auto du16_fst_429 { std::get<0>(id_2257) };
                          auto du16_snd_430 { std::get<1>(id_2257) };
                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2259 { du16_fst_429, du16_snd_430 };
                          letpair_res_2258 = id_2259;
                        }
                        ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 let_res_2260;
                        {
                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_434 { letpair_res_2258 };
                          ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2261;
                          {
                            auto dsum1_fst_435 { std::get<0>(dsum1_434) };
                            auto dsum1_snd_436 { std::get<1>(dsum1_434) };
                            uint16_t id_2262 { 0 };
                            bool id_2263 { bool(id_2262 == dsum1_fst_435) };
                            ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 choose_res_2264;
                            if (id_2263) {
                              (void)VOID;
                              ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_2265 { std::in_place_index<0>, VOID };
                              ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 id_2266 { id_2265, dsum1_snd_436 };
                              choose_res_2264 = id_2266;
                            } else {
                              uint16_t id_2267 { 1 };
                              bool id_2268 { bool(id_2267 == dsum1_fst_435) };
                              ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 choose_res_2269;
                              if (id_2268) {
                                uint32_t id_2270 { 0U };
                                Vec<1, uint32_t> id_2271 {  id_2270  };
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2272;
                                {
                                  Vec<1, uint32_t> leb_ref_569 { id_2271 };
                                  uint8_t id_2273 { 0 };
                                  Vec<1, uint8_t> id_2274 {  id_2273  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2275;
                                  {
                                    Vec<1, uint8_t> shft_ref_570 { id_2274 };
                                    Vec<1, Pointer> id_2276 {  dsum1_snd_436  };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2277;
                                    {
                                      Vec<1, Pointer> p_ref_571 { id_2276 };
                                      bool while_flag_2278 { true };
                                      do {
                                        uint8_t id_2279 { 0 };
                                        Pointer id_2280 { p_ref_571[id_2279] };
                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2281 { id_2280.readU8() };
                                        bool let_res_2282;
                                        {
                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_572 { id_2281 };
                                          bool letpair_res_2283;
                                          {
                                            auto leb128_fst_573 { std::get<0>(leb128_572) };
                                            auto leb128_snd_574 { std::get<1>(leb128_572) };
                                            uint8_t id_2284 { 0 };
                                            Void id_2285 { ((void)(p_ref_571[id_2284] = leb128_snd_574), VOID) };
                                            (void)id_2285;
                                            uint8_t id_2286 { 0 };
                                            uint8_t id_2287 { 127 };
                                            uint8_t id_2288 { uint8_t(leb128_fst_573 & id_2287) };
                                            uint32_t id_2289 { uint32_t(id_2288) };
                                            uint8_t id_2290 { 0 };
                                            uint8_t id_2291 { shft_ref_570[id_2290] };
                                            uint32_t id_2292 { uint32_t(id_2289 << id_2291) };
                                            uint8_t id_2293 { 0 };
                                            uint32_t id_2294 { leb_ref_569[id_2293] };
                                            uint32_t id_2295 { uint32_t(id_2292 | id_2294) };
                                            Void id_2296 { ((void)(leb_ref_569[id_2286] = id_2295), VOID) };
                                            (void)id_2296;
                                            uint8_t id_2297 { 0 };
                                            uint8_t id_2298 { 0 };
                                            uint8_t id_2299 { shft_ref_570[id_2298] };
                                            uint8_t id_2300 { 7 };
                                            uint8_t id_2301 { uint8_t(id_2299 + id_2300) };
                                            Void id_2302 { ((void)(shft_ref_570[id_2297] = id_2301), VOID) };
                                            (void)id_2302;
                                            uint8_t id_2303 { 128 };
                                            bool id_2304 { bool(leb128_fst_573 >= id_2303) };
                                            letpair_res_2283 = id_2304;
                                          }
                                          let_res_2282 = letpair_res_2283;
                                        }
                                        while_flag_2278 = let_res_2282;
                                        if (while_flag_2278) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_2278);
                                      (void)VOID;
                                      uint8_t id_2305 { 0 };
                                      uint32_t id_2306 { leb_ref_569[id_2305] };
                                      Size id_2307 { Size(id_2306) };
                                      uint8_t id_2308 { 0 };
                                      Pointer id_2309 { p_ref_571[id_2308] };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2310 { id_2307, id_2309 };
                                      let_res_2277 = id_2310;
                                    }
                                    let_res_2275 = let_res_2277;
                                  }
                                  let_res_2272 = let_res_2275;
                                }
                                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2311;
                                {
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_575 { let_res_2272 };
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2312;
                                  {
                                    auto dstring1_fst_576 { std::get<0>(dstring1_575) };
                                    auto dstring1_snd_577 { std::get<1>(dstring1_575) };
                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2313 { dstring1_snd_577.readBytes(dstring1_fst_576) };
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2314;
                                    {
                                      auto dstring2_fst_579 { std::get<0>(id_2313) };
                                      auto dstring2_snd_580 { std::get<1>(id_2313) };
                                      std::string id_2315 { dstring2_fst_579.toString() };
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2316 { id_2315, dstring2_snd_580 };
                                      letpair_res_2314 = id_2316;
                                    }
                                    letpair_res_2312 = letpair_res_2314;
                                  }
                                  let_res_2311 = letpair_res_2312;
                                }
                                ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 let_res_2317;
                                {
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_581 { let_res_2311 };
                                  ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2318;
                                  {
                                    auto dtup_fst_582 { std::get<0>(dtup_581) };
                                    auto dtup_snd_583 { std::get<1>(dtup_581) };
                                    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2319 { dtup_snd_583.readU16Le() };
                                    ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2320;
                                    {
                                      auto du16_fst_585 { std::get<0>(id_2319) };
                                      auto du16_snd_586 { std::get<1>(id_2319) };
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2321 { du16_fst_585, du16_snd_586 };
                                      letpair_res_2320 = id_2321;
                                    }
                                    ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e let_res_2322;
                                    {
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_590 { letpair_res_2320 };
                                      ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e letpair_res_2323;
                                      {
                                        auto dsum1_fst_591 { std::get<0>(dsum1_590) };
                                        auto dsum1_snd_592 { std::get<1>(dsum1_590) };
                                        uint16_t id_2324 { 0 };
                                        bool id_2325 { bool(id_2324 == dsum1_fst_591) };
                                        ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e choose_res_2326;
                                        if (id_2325) {
                                          (void)VOID;
                                          ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_2327 { std::in_place_index<0>, VOID };
                                          ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e id_2328 { id_2327, dsum1_snd_592 };
                                          choose_res_2326 = id_2328;
                                        } else {
                                          uint16_t id_2329 { 1 };
                                          bool id_2330 { bool(dsum1_fst_591 == id_2329) };
                                          Void id_2331 { ((void)(assert(id_2330)), VOID) };
                                          (void)id_2331;
                                          (void)VOID;
                                          ::dessser::gen::sync_key::t32def300158106bfcc2bfd2015d1a3a9 id_2332 { std::in_place_index<1>, VOID };
                                          ::dessser::gen::sync_key::t693b3c0b01440f82d6bb9ea682c4062e id_2333 { id_2332, dsum1_snd_592 };
                                          choose_res_2326 = id_2333;
                                        }
                                        letpair_res_2323 = choose_res_2326;
                                      }
                                      let_res_2322 = letpair_res_2323;
                                    }
                                    ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2334;
                                    {
                                      auto dtup_fst_600 { std::get<0>(let_res_2322) };
                                      auto dtup_snd_601 { std::get<1>(let_res_2322) };
                                      ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6 id_2335 { dtup_fst_582, dtup_fst_600 };
                                      ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_2336 { std::in_place_index<1>, id_2335 };
                                      ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 id_2337 { id_2336, dtup_snd_601 };
                                      letpair_res_2334 = id_2337;
                                    }
                                    letpair_res_2318 = letpair_res_2334;
                                  }
                                  let_res_2317 = letpair_res_2318;
                                }
                                choose_res_2269 = let_res_2317;
                              } else {
                                uint16_t id_2338 { 2 };
                                bool id_2339 { bool(id_2338 == dsum1_fst_435) };
                                ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 choose_res_2340;
                                if (id_2339) {
                                  auto fun2341 { dessser::gen::fq_name::of_row_binary };
                                  ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e id_2342 { fun2341(dsum1_snd_436) };
                                  ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 let_res_2343;
                                  {
                                    ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e dtup_470 { id_2342 };
                                    ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2344;
                                    {
                                      auto dtup_fst_471 { std::get<0>(dtup_470) };
                                      auto dtup_snd_472 { std::get<1>(dtup_470) };
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2345 { dtup_snd_472.readU16Le() };
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2346;
                                      {
                                        auto du16_fst_474 { std::get<0>(id_2345) };
                                        auto du16_snd_475 { std::get<1>(id_2345) };
                                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2347 { du16_fst_474, du16_snd_475 };
                                        letpair_res_2346 = id_2347;
                                      }
                                      ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 let_res_2348;
                                      {
                                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_479 { letpair_res_2346 };
                                        ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 letpair_res_2349;
                                        {
                                          auto dsum1_fst_480 { std::get<0>(dsum1_479) };
                                          auto dsum1_snd_481 { std::get<1>(dsum1_479) };
                                          uint16_t id_2350 { 0 };
                                          bool id_2351 { bool(id_2350 == dsum1_fst_480) };
                                          ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2352;
                                          if (id_2351) {
                                            (void)VOID;
                                            ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2353 { std::in_place_index<0>, VOID };
                                            ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2354 { id_2353, dsum1_snd_481 };
                                            choose_res_2352 = id_2354;
                                          } else {
                                            uint16_t id_2355 { 1 };
                                            bool id_2356 { bool(id_2355 == dsum1_fst_480) };
                                            ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2357;
                                            if (id_2356) {
                                              (void)VOID;
                                              ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2358 { std::in_place_index<1>, VOID };
                                              ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2359 { id_2358, dsum1_snd_481 };
                                              choose_res_2357 = id_2359;
                                            } else {
                                              uint16_t id_2360 { 2 };
                                              bool id_2361 { bool(id_2360 == dsum1_fst_480) };
                                              ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2362;
                                              if (id_2361) {
                                                (void)VOID;
                                                ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2363 { std::in_place_index<2>, VOID };
                                                ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2364 { id_2363, dsum1_snd_481 };
                                                choose_res_2362 = id_2364;
                                              } else {
                                                uint16_t id_2365 { 3 };
                                                bool id_2366 { bool(id_2365 == dsum1_fst_480) };
                                                ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2367;
                                                if (id_2366) {
                                                  (void)VOID;
                                                  ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2368 { std::in_place_index<3>, VOID };
                                                  ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2369 { id_2368, dsum1_snd_481 };
                                                  choose_res_2367 = id_2369;
                                                } else {
                                                  uint16_t id_2370 { 4 };
                                                  bool id_2371 { bool(id_2370 == dsum1_fst_480) };
                                                  ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2372;
                                                  if (id_2371) {
                                                    (void)VOID;
                                                    ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2373 { std::in_place_index<4>, VOID };
                                                    ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2374 { id_2373, dsum1_snd_481 };
                                                    choose_res_2372 = id_2374;
                                                  } else {
                                                    uint16_t id_2375 { 5 };
                                                    bool id_2376 { bool(id_2375 == dsum1_fst_480) };
                                                    ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2377;
                                                    if (id_2376) {
                                                      (void)VOID;
                                                      ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2378 { std::in_place_index<5>, VOID };
                                                      ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2379 { id_2378, dsum1_snd_481 };
                                                      choose_res_2377 = id_2379;
                                                    } else {
                                                      uint16_t id_2380 { 6 };
                                                      bool id_2381 { bool(id_2380 == dsum1_fst_480) };
                                                      ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2382;
                                                      if (id_2381) {
                                                        uint32_t id_2383 { 0U };
                                                        Vec<1, uint32_t> id_2384 {  id_2383  };
                                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2385;
                                                        {
                                                          Vec<1, uint32_t> leb_ref_491 { id_2384 };
                                                          uint8_t id_2386 { 0 };
                                                          Vec<1, uint8_t> id_2387 {  id_2386  };
                                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2388;
                                                          {
                                                            Vec<1, uint8_t> shft_ref_492 { id_2387 };
                                                            Vec<1, Pointer> id_2389 {  dsum1_snd_481  };
                                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2390;
                                                            {
                                                              Vec<1, Pointer> p_ref_493 { id_2389 };
                                                              bool while_flag_2391 { true };
                                                              do {
                                                                uint8_t id_2392 { 0 };
                                                                Pointer id_2393 { p_ref_493[id_2392] };
                                                                ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2394 { id_2393.readU8() };
                                                                bool let_res_2395;
                                                                {
                                                                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_494 { id_2394 };
                                                                  bool letpair_res_2396;
                                                                  {
                                                                    auto leb128_fst_495 { std::get<0>(leb128_494) };
                                                                    auto leb128_snd_496 { std::get<1>(leb128_494) };
                                                                    uint8_t id_2397 { 0 };
                                                                    Void id_2398 { ((void)(p_ref_493[id_2397] = leb128_snd_496), VOID) };
                                                                    (void)id_2398;
                                                                    uint8_t id_2399 { 0 };
                                                                    uint8_t id_2400 { 127 };
                                                                    uint8_t id_2401 { uint8_t(leb128_fst_495 & id_2400) };
                                                                    uint32_t id_2402 { uint32_t(id_2401) };
                                                                    uint8_t id_2403 { 0 };
                                                                    uint8_t id_2404 { shft_ref_492[id_2403] };
                                                                    uint32_t id_2405 { uint32_t(id_2402 << id_2404) };
                                                                    uint8_t id_2406 { 0 };
                                                                    uint32_t id_2407 { leb_ref_491[id_2406] };
                                                                    uint32_t id_2408 { uint32_t(id_2405 | id_2407) };
                                                                    Void id_2409 { ((void)(leb_ref_491[id_2399] = id_2408), VOID) };
                                                                    (void)id_2409;
                                                                    uint8_t id_2410 { 0 };
                                                                    uint8_t id_2411 { 0 };
                                                                    uint8_t id_2412 { shft_ref_492[id_2411] };
                                                                    uint8_t id_2413 { 7 };
                                                                    uint8_t id_2414 { uint8_t(id_2412 + id_2413) };
                                                                    Void id_2415 { ((void)(shft_ref_492[id_2410] = id_2414), VOID) };
                                                                    (void)id_2415;
                                                                    uint8_t id_2416 { 128 };
                                                                    bool id_2417 { bool(leb128_fst_495 >= id_2416) };
                                                                    letpair_res_2396 = id_2417;
                                                                  }
                                                                  let_res_2395 = letpair_res_2396;
                                                                }
                                                                while_flag_2391 = let_res_2395;
                                                                if (while_flag_2391) {
                                                                  (void)VOID;
                                                                }
                                                              } while (while_flag_2391);
                                                              (void)VOID;
                                                              uint8_t id_2418 { 0 };
                                                              uint32_t id_2419 { leb_ref_491[id_2418] };
                                                              Size id_2420 { Size(id_2419) };
                                                              uint8_t id_2421 { 0 };
                                                              Pointer id_2422 { p_ref_493[id_2421] };
                                                              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2423 { id_2420, id_2422 };
                                                              let_res_2390 = id_2423;
                                                            }
                                                            let_res_2388 = let_res_2390;
                                                          }
                                                          let_res_2385 = let_res_2388;
                                                        }
                                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2424;
                                                        {
                                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_497 { let_res_2385 };
                                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2425;
                                                          {
                                                            auto dstring1_fst_498 { std::get<0>(dstring1_497) };
                                                            auto dstring1_snd_499 { std::get<1>(dstring1_497) };
                                                            ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2426 { dstring1_snd_499.readBytes(dstring1_fst_498) };
                                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2427;
                                                            {
                                                              auto dstring2_fst_501 { std::get<0>(id_2426) };
                                                              auto dstring2_snd_502 { std::get<1>(id_2426) };
                                                              std::string id_2428 { dstring2_fst_501.toString() };
                                                              ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2429 { id_2428, dstring2_snd_502 };
                                                              letpair_res_2427 = id_2429;
                                                            }
                                                            letpair_res_2425 = letpair_res_2427;
                                                          }
                                                          let_res_2424 = letpair_res_2425;
                                                        }
                                                        ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 let_res_2430;
                                                        {
                                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_503 { let_res_2424 };
                                                          ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 letpair_res_2431;
                                                          {
                                                            auto dtup_fst_504 { std::get<0>(dtup_503) };
                                                            auto dtup_snd_505 { std::get<1>(dtup_503) };
                                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2432 { dtup_snd_505.readU16Le() };
                                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2433;
                                                            {
                                                              auto du16_fst_507 { std::get<0>(id_2432) };
                                                              auto du16_snd_508 { std::get<1>(id_2432) };
                                                              ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2434 { du16_fst_507, du16_snd_508 };
                                                              letpair_res_2433 = id_2434;
                                                            }
                                                            ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da let_res_2435;
                                                            {
                                                              ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_512 { letpair_res_2433 };
                                                              ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da letpair_res_2436;
                                                              {
                                                                auto dsum1_fst_513 { std::get<0>(dsum1_512) };
                                                                auto dsum1_snd_514 { std::get<1>(dsum1_512) };
                                                                uint16_t id_2437 { 0 };
                                                                bool id_2438 { bool(id_2437 == dsum1_fst_513) };
                                                                ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2439;
                                                                if (id_2438) {
                                                                  (void)VOID;
                                                                  ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2440 { std::in_place_index<0>, VOID };
                                                                  ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2441 { id_2440, dsum1_snd_514 };
                                                                  choose_res_2439 = id_2441;
                                                                } else {
                                                                  uint16_t id_2442 { 1 };
                                                                  bool id_2443 { bool(id_2442 == dsum1_fst_513) };
                                                                  ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2444;
                                                                  if (id_2443) {
                                                                    (void)VOID;
                                                                    ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2445 { std::in_place_index<1>, VOID };
                                                                    ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2446 { id_2445, dsum1_snd_514 };
                                                                    choose_res_2444 = id_2446;
                                                                  } else {
                                                                    uint16_t id_2447 { 2 };
                                                                    bool id_2448 { bool(id_2447 == dsum1_fst_513) };
                                                                    ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2449;
                                                                    if (id_2448) {
                                                                      (void)VOID;
                                                                      ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2450 { std::in_place_index<2>, VOID };
                                                                      ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2451 { id_2450, dsum1_snd_514 };
                                                                      choose_res_2449 = id_2451;
                                                                    } else {
                                                                      uint16_t id_2452 { 3 };
                                                                      bool id_2453 { bool(id_2452 == dsum1_fst_513) };
                                                                      ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2454;
                                                                      if (id_2453) {
                                                                        (void)VOID;
                                                                        ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2455 { std::in_place_index<3>, VOID };
                                                                        ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2456 { id_2455, dsum1_snd_514 };
                                                                        choose_res_2454 = id_2456;
                                                                      } else {
                                                                        uint16_t id_2457 { 4 };
                                                                        bool id_2458 { bool(id_2457 == dsum1_fst_513) };
                                                                        ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2459;
                                                                        if (id_2458) {
                                                                          (void)VOID;
                                                                          ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2460 { std::in_place_index<4>, VOID };
                                                                          ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2461 { id_2460, dsum1_snd_514 };
                                                                          choose_res_2459 = id_2461;
                                                                        } else {
                                                                          uint16_t id_2462 { 5 };
                                                                          bool id_2463 { bool(id_2462 == dsum1_fst_513) };
                                                                          ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2464;
                                                                          if (id_2463) {
                                                                            (void)VOID;
                                                                            ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2465 { std::in_place_index<5>, VOID };
                                                                            ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2466 { id_2465, dsum1_snd_514 };
                                                                            choose_res_2464 = id_2466;
                                                                          } else {
                                                                            uint16_t id_2467 { 6 };
                                                                            bool id_2468 { bool(id_2467 == dsum1_fst_513) };
                                                                            ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da choose_res_2469;
                                                                            if (id_2468) {
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2470 { std::in_place_index<6>, VOID };
                                                                              ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2471 { id_2470, dsum1_snd_514 };
                                                                              choose_res_2469 = id_2471;
                                                                            } else {
                                                                              uint16_t id_2472 { 7 };
                                                                              bool id_2473 { bool(dsum1_fst_513 == id_2472) };
                                                                              Void id_2474 { ((void)(assert(id_2473)), VOID) };
                                                                              (void)id_2474;
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t082c1c733e68c2b9334f218f8c5aeccb id_2475 { std::in_place_index<7>, VOID };
                                                                              ::dessser::gen::sync_key::t0d6c591ce3b3ba893d6d35f4657ef1da id_2476 { id_2475, dsum1_snd_514 };
                                                                              choose_res_2469 = id_2476;
                                                                            }
                                                                            choose_res_2464 = choose_res_2469;
                                                                          }
                                                                          choose_res_2459 = choose_res_2464;
                                                                        }
                                                                        choose_res_2454 = choose_res_2459;
                                                                      }
                                                                      choose_res_2449 = choose_res_2454;
                                                                    }
                                                                    choose_res_2444 = choose_res_2449;
                                                                  }
                                                                  choose_res_2439 = choose_res_2444;
                                                                }
                                                                letpair_res_2436 = choose_res_2439;
                                                              }
                                                              let_res_2435 = letpair_res_2436;
                                                            }
                                                            ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 letpair_res_2477;
                                                            {
                                                              auto dtup_fst_540 { std::get<0>(let_res_2435) };
                                                              auto dtup_snd_541 { std::get<1>(let_res_2435) };
                                                              ::dessser::gen::sync_key::t87de6a51e16e395e537230ef32d18a96 id_2478 { dtup_fst_504, dtup_fst_540 };
                                                              ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2479 { std::in_place_index<6>, id_2478 };
                                                              ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2480 { id_2479, dtup_snd_541 };
                                                              letpair_res_2477 = id_2480;
                                                            }
                                                            letpair_res_2431 = letpair_res_2477;
                                                          }
                                                          let_res_2430 = letpair_res_2431;
                                                        }
                                                        choose_res_2382 = let_res_2430;
                                                      } else {
                                                        uint16_t id_2481 { 7 };
                                                        bool id_2482 { bool(id_2481 == dsum1_fst_480) };
                                                        ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 choose_res_2483;
                                                        if (id_2482) {
                                                          ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_2484 { dsum1_snd_481.readU32Le() };
                                                          ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 letpair_res_2485;
                                                          {
                                                            auto du32_fst_486 { std::get<0>(id_2484) };
                                                            auto du32_snd_487 { std::get<1>(id_2484) };
                                                            ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2486 { std::in_place_index<7>, du32_fst_486 };
                                                            ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2487 { id_2486, du32_snd_487 };
                                                            letpair_res_2485 = id_2487;
                                                          }
                                                          choose_res_2483 = letpair_res_2485;
                                                        } else {
                                                          uint16_t id_2488 { 8 };
                                                          bool id_2489 { bool(dsum1_fst_480 == id_2488) };
                                                          Void id_2490 { ((void)(assert(id_2489)), VOID) };
                                                          (void)id_2490;
                                                          (void)VOID;
                                                          ::dessser::gen::sync_key::t4f653cc5cecafb6924f3d52da0caa392 id_2491 { std::in_place_index<8>, VOID };
                                                          ::dessser::gen::sync_key::tfad316798fa8ee621795cab2ef1d09e1 id_2492 { id_2491, dsum1_snd_481 };
                                                          choose_res_2483 = id_2492;
                                                        }
                                                        choose_res_2382 = choose_res_2483;
                                                      }
                                                      choose_res_2377 = choose_res_2382;
                                                    }
                                                    choose_res_2372 = choose_res_2377;
                                                  }
                                                  choose_res_2367 = choose_res_2372;
                                                }
                                                choose_res_2362 = choose_res_2367;
                                              }
                                              choose_res_2357 = choose_res_2362;
                                            }
                                            choose_res_2352 = choose_res_2357;
                                          }
                                          letpair_res_2349 = choose_res_2352;
                                        }
                                        let_res_2348 = letpair_res_2349;
                                      }
                                      ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2493;
                                      {
                                        auto dtup_fst_564 { std::get<0>(let_res_2348) };
                                        auto dtup_snd_565 { std::get<1>(let_res_2348) };
                                        ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12 id_2494 { dtup_fst_471, dtup_fst_564 };
                                        ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_2495 { std::in_place_index<2>, id_2494 };
                                        ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 id_2496 { id_2495, dtup_snd_565 };
                                        letpair_res_2493 = id_2496;
                                      }
                                      letpair_res_2344 = letpair_res_2493;
                                    }
                                    let_res_2343 = letpair_res_2344;
                                  }
                                  choose_res_2340 = let_res_2343;
                                } else {
                                  uint16_t id_2497 { 3 };
                                  bool id_2498 { bool(dsum1_fst_435 == id_2497) };
                                  Void id_2499 { ((void)(assert(id_2498)), VOID) };
                                  (void)id_2499;
                                  uint32_t id_2500 { 0U };
                                  Vec<1, uint32_t> id_2501 {  id_2500  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2502;
                                  {
                                    Vec<1, uint32_t> leb_ref_437 { id_2501 };
                                    uint8_t id_2503 { 0 };
                                    Vec<1, uint8_t> id_2504 {  id_2503  };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2505;
                                    {
                                      Vec<1, uint8_t> shft_ref_438 { id_2504 };
                                      Vec<1, Pointer> id_2506 {  dsum1_snd_436  };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2507;
                                      {
                                        Vec<1, Pointer> p_ref_439 { id_2506 };
                                        bool while_flag_2508 { true };
                                        do {
                                          uint8_t id_2509 { 0 };
                                          Pointer id_2510 { p_ref_439[id_2509] };
                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2511 { id_2510.readU8() };
                                          bool let_res_2512;
                                          {
                                            ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_440 { id_2511 };
                                            bool letpair_res_2513;
                                            {
                                              auto leb128_fst_441 { std::get<0>(leb128_440) };
                                              auto leb128_snd_442 { std::get<1>(leb128_440) };
                                              uint8_t id_2514 { 0 };
                                              Void id_2515 { ((void)(p_ref_439[id_2514] = leb128_snd_442), VOID) };
                                              (void)id_2515;
                                              uint8_t id_2516 { 0 };
                                              uint8_t id_2517 { 127 };
                                              uint8_t id_2518 { uint8_t(leb128_fst_441 & id_2517) };
                                              uint32_t id_2519 { uint32_t(id_2518) };
                                              uint8_t id_2520 { 0 };
                                              uint8_t id_2521 { shft_ref_438[id_2520] };
                                              uint32_t id_2522 { uint32_t(id_2519 << id_2521) };
                                              uint8_t id_2523 { 0 };
                                              uint32_t id_2524 { leb_ref_437[id_2523] };
                                              uint32_t id_2525 { uint32_t(id_2522 | id_2524) };
                                              Void id_2526 { ((void)(leb_ref_437[id_2516] = id_2525), VOID) };
                                              (void)id_2526;
                                              uint8_t id_2527 { 0 };
                                              uint8_t id_2528 { 0 };
                                              uint8_t id_2529 { shft_ref_438[id_2528] };
                                              uint8_t id_2530 { 7 };
                                              uint8_t id_2531 { uint8_t(id_2529 + id_2530) };
                                              Void id_2532 { ((void)(shft_ref_438[id_2527] = id_2531), VOID) };
                                              (void)id_2532;
                                              uint8_t id_2533 { 128 };
                                              bool id_2534 { bool(leb128_fst_441 >= id_2533) };
                                              letpair_res_2513 = id_2534;
                                            }
                                            let_res_2512 = letpair_res_2513;
                                          }
                                          while_flag_2508 = let_res_2512;
                                          if (while_flag_2508) {
                                            (void)VOID;
                                          }
                                        } while (while_flag_2508);
                                        (void)VOID;
                                        uint8_t id_2535 { 0 };
                                        uint32_t id_2536 { leb_ref_437[id_2535] };
                                        Size id_2537 { Size(id_2536) };
                                        uint8_t id_2538 { 0 };
                                        Pointer id_2539 { p_ref_439[id_2538] };
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2540 { id_2537, id_2539 };
                                        let_res_2507 = id_2540;
                                      }
                                      let_res_2505 = let_res_2507;
                                    }
                                    let_res_2502 = let_res_2505;
                                  }
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2541;
                                  {
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_443 { let_res_2502 };
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2542;
                                    {
                                      auto dstring1_fst_444 { std::get<0>(dstring1_443) };
                                      auto dstring1_snd_445 { std::get<1>(dstring1_443) };
                                      ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2543 { dstring1_snd_445.readBytes(dstring1_fst_444) };
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2544;
                                      {
                                        auto dstring2_fst_447 { std::get<0>(id_2543) };
                                        auto dstring2_snd_448 { std::get<1>(id_2543) };
                                        std::string id_2545 { dstring2_fst_447.toString() };
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2546 { id_2545, dstring2_snd_448 };
                                        letpair_res_2544 = id_2546;
                                      }
                                      letpair_res_2542 = letpair_res_2544;
                                    }
                                    let_res_2541 = letpair_res_2542;
                                  }
                                  ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 let_res_2547;
                                  {
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_449 { let_res_2541 };
                                    ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2548;
                                    {
                                      auto dtup_fst_450 { std::get<0>(dtup_449) };
                                      auto dtup_snd_451 { std::get<1>(dtup_449) };
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2549 { dtup_snd_451.readU16Le() };
                                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2550;
                                      {
                                        auto du16_fst_453 { std::get<0>(id_2549) };
                                        auto du16_snd_454 { std::get<1>(id_2549) };
                                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2551 { du16_fst_453, du16_snd_454 };
                                        letpair_res_2550 = id_2551;
                                      }
                                      ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 let_res_2552;
                                      {
                                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_458 { letpair_res_2550 };
                                        ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 letpair_res_2553;
                                        {
                                          auto dsum1_fst_459 { std::get<0>(dsum1_458) };
                                          auto dsum1_snd_460 { std::get<1>(dsum1_458) };
                                          uint16_t id_2554 { 0 };
                                          bool id_2555 { bool(dsum1_fst_459 == id_2554) };
                                          Void id_2556 { ((void)(assert(id_2555)), VOID) };
                                          (void)id_2556;
                                          (void)VOID;
                                          ::dessser::gen::sync_key::t73ec97d1f82a1880f5d2693e3a0558b1 id_2557 { std::in_place_index<0>, VOID };
                                          ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 id_2558 { dtup_fst_450, id_2557 };
                                          ::dessser::gen::sync_key::t9030dc10bd527c50c2f835375dc4eb9d id_2559 { std::in_place_index<3>, id_2558 };
                                          ::dessser::gen::sync_key::t712586ec75786967434a0be4152a1e08 id_2560 { id_2559, dsum1_snd_460 };
                                          letpair_res_2553 = id_2560;
                                        }
                                        let_res_2552 = letpair_res_2553;
                                      }
                                      letpair_res_2548 = let_res_2552;
                                    }
                                    let_res_2547 = letpair_res_2548;
                                  }
                                  choose_res_2340 = let_res_2547;
                                }
                                choose_res_2269 = choose_res_2340;
                              }
                              choose_res_2264 = choose_res_2269;
                            }
                            letpair_res_2261 = choose_res_2264;
                          }
                          let_res_2260 = letpair_res_2261;
                        }
                        ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2561;
                        {
                          auto dtup_fst_609 { std::get<0>(let_res_2260) };
                          auto dtup_snd_610 { std::get<1>(let_res_2260) };
                          ::dessser::gen::sync_key::t64d8d40f333c531e9d48c05b8ceb4cfa id_2562 { dtup_fst_426, dtup_fst_609 };
                          ::dessser::gen::sync_key::t* id_2563 { new ::dessser::gen::sync_key::t(std::in_place_index<5>, id_2562) };
                          ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2564 { id_2563, dtup_snd_610 };
                          letpair_res_2561 = id_2564;
                        }
                        letpair_res_2256 = letpair_res_2561;
                      }
                      let_res_2255 = letpair_res_2256;
                    }
                    choose_res_2252 = let_res_2255;
                  } else {
                    uint16_t id_2565 { 6 };
                    bool id_2566 { bool(id_2565 == dsum1_fst_144) };
                    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2567;
                    if (id_2566) {
                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2568 { dsum1_snd_145.readU16Le() };
                      ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2569;
                      {
                        auto du16_fst_393 { std::get<0>(id_2568) };
                        auto du16_snd_394 { std::get<1>(id_2568) };
                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2570 { du16_fst_393, du16_snd_394 };
                        letpair_res_2569 = id_2570;
                      }
                      ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b let_res_2571;
                      {
                        ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_398 { letpair_res_2569 };
                        ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b letpair_res_2572;
                        {
                          auto dsum1_fst_399 { std::get<0>(dsum1_398) };
                          auto dsum1_snd_400 { std::get<1>(dsum1_398) };
                          uint16_t id_2573 { 0 };
                          bool id_2574 { bool(id_2573 == dsum1_fst_399) };
                          ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b choose_res_2575;
                          if (id_2574) {
                            (void)VOID;
                            ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2576 { std::in_place_index<0>, VOID };
                            ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b id_2577 { id_2576, dsum1_snd_400 };
                            choose_res_2575 = id_2577;
                          } else {
                            uint16_t id_2578 { 1 };
                            bool id_2579 { bool(id_2578 == dsum1_fst_399) };
                            ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b choose_res_2580;
                            if (id_2579) {
                              (void)VOID;
                              ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2581 { std::in_place_index<1>, VOID };
                              ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b id_2582 { id_2581, dsum1_snd_400 };
                              choose_res_2580 = id_2582;
                            } else {
                              uint16_t id_2583 { 2 };
                              bool id_2584 { bool(dsum1_fst_399 == id_2583) };
                              Void id_2585 { ((void)(assert(id_2584)), VOID) };
                              (void)id_2585;
                              uint32_t id_2586 { 0U };
                              Vec<1, uint32_t> id_2587 {  id_2586  };
                              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2588;
                              {
                                Vec<1, uint32_t> leb_ref_401 { id_2587 };
                                uint8_t id_2589 { 0 };
                                Vec<1, uint8_t> id_2590 {  id_2589  };
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2591;
                                {
                                  Vec<1, uint8_t> shft_ref_402 { id_2590 };
                                  Vec<1, Pointer> id_2592 {  dsum1_snd_400  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2593;
                                  {
                                    Vec<1, Pointer> p_ref_403 { id_2592 };
                                    bool while_flag_2594 { true };
                                    do {
                                      uint8_t id_2595 { 0 };
                                      Pointer id_2596 { p_ref_403[id_2595] };
                                      ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2597 { id_2596.readU8() };
                                      bool let_res_2598;
                                      {
                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_404 { id_2597 };
                                        bool letpair_res_2599;
                                        {
                                          auto leb128_fst_405 { std::get<0>(leb128_404) };
                                          auto leb128_snd_406 { std::get<1>(leb128_404) };
                                          uint8_t id_2600 { 0 };
                                          Void id_2601 { ((void)(p_ref_403[id_2600] = leb128_snd_406), VOID) };
                                          (void)id_2601;
                                          uint8_t id_2602 { 0 };
                                          uint8_t id_2603 { 127 };
                                          uint8_t id_2604 { uint8_t(leb128_fst_405 & id_2603) };
                                          uint32_t id_2605 { uint32_t(id_2604) };
                                          uint8_t id_2606 { 0 };
                                          uint8_t id_2607 { shft_ref_402[id_2606] };
                                          uint32_t id_2608 { uint32_t(id_2605 << id_2607) };
                                          uint8_t id_2609 { 0 };
                                          uint32_t id_2610 { leb_ref_401[id_2609] };
                                          uint32_t id_2611 { uint32_t(id_2608 | id_2610) };
                                          Void id_2612 { ((void)(leb_ref_401[id_2602] = id_2611), VOID) };
                                          (void)id_2612;
                                          uint8_t id_2613 { 0 };
                                          uint8_t id_2614 { 0 };
                                          uint8_t id_2615 { shft_ref_402[id_2614] };
                                          uint8_t id_2616 { 7 };
                                          uint8_t id_2617 { uint8_t(id_2615 + id_2616) };
                                          Void id_2618 { ((void)(shft_ref_402[id_2613] = id_2617), VOID) };
                                          (void)id_2618;
                                          uint8_t id_2619 { 128 };
                                          bool id_2620 { bool(leb128_fst_405 >= id_2619) };
                                          letpair_res_2599 = id_2620;
                                        }
                                        let_res_2598 = letpair_res_2599;
                                      }
                                      while_flag_2594 = let_res_2598;
                                      if (while_flag_2594) {
                                        (void)VOID;
                                      }
                                    } while (while_flag_2594);
                                    (void)VOID;
                                    uint8_t id_2621 { 0 };
                                    uint32_t id_2622 { leb_ref_401[id_2621] };
                                    Size id_2623 { Size(id_2622) };
                                    uint8_t id_2624 { 0 };
                                    Pointer id_2625 { p_ref_403[id_2624] };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2626 { id_2623, id_2625 };
                                    let_res_2593 = id_2626;
                                  }
                                  let_res_2591 = let_res_2593;
                                }
                                let_res_2588 = let_res_2591;
                              }
                              ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b let_res_2627;
                              {
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_407 { let_res_2588 };
                                ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b letpair_res_2628;
                                {
                                  auto dstring1_fst_408 { std::get<0>(dstring1_407) };
                                  auto dstring1_snd_409 { std::get<1>(dstring1_407) };
                                  ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2629 { dstring1_snd_409.readBytes(dstring1_fst_408) };
                                  ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b letpair_res_2630;
                                  {
                                    auto dstring2_fst_411 { std::get<0>(id_2629) };
                                    auto dstring2_snd_412 { std::get<1>(id_2629) };
                                    std::string id_2631 { dstring2_fst_411.toString() };
                                    ::dessser::gen::sync_key::t1fb80ba5a0eef0b970838ab3e8e6bce4 id_2632 { std::in_place_index<2>, id_2631 };
                                    ::dessser::gen::sync_key::t0e79e03631acd607acafe442d826717b id_2633 { id_2632, dstring2_snd_412 };
                                    letpair_res_2630 = id_2633;
                                  }
                                  letpair_res_2628 = letpair_res_2630;
                                }
                                let_res_2627 = letpair_res_2628;
                              }
                              choose_res_2580 = let_res_2627;
                            }
                            choose_res_2575 = choose_res_2580;
                          }
                          letpair_res_2572 = choose_res_2575;
                        }
                        let_res_2571 = letpair_res_2572;
                      }
                      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2634;
                      {
                        auto dsum2_fst_423 { std::get<0>(let_res_2571) };
                        auto dsum2_snd_424 { std::get<1>(let_res_2571) };
                        ::dessser::gen::sync_key::t* id_2635 { new ::dessser::gen::sync_key::t(std::in_place_index<6>, dsum2_fst_423) };
                        ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2636 { id_2635, dsum2_snd_424 };
                        letpair_res_2634 = id_2636;
                      }
                      choose_res_2567 = letpair_res_2634;
                    } else {
                      uint16_t id_2637 { 7 };
                      bool id_2638 { bool(id_2637 == dsum1_fst_144) };
                      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2639;
                      if (id_2638) {
                        auto fun2640 { dessser::gen::site_name::of_row_binary };
                        ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea id_2641 { fun2640(dsum1_snd_145) };
                        ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2642;
                        {
                          ::dessser::gen::sync_key::tff906bde0664efb2415be180e5a241ea dtup_365 { id_2641 };
                          ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2643;
                          {
                            auto dtup_fst_366 { std::get<0>(dtup_365) };
                            auto dtup_snd_367 { std::get<1>(dtup_365) };
                            auto fun2644 { dessser::gen::fq_name::of_row_binary };
                            ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e id_2645 { fun2644(dtup_snd_367) };
                            ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2646;
                            {
                              ::dessser::gen::sync_key::tcd6e38ac5ca8a381102d1fa6500e9b6e dtup_368 { id_2645 };
                              ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2647;
                              {
                                auto dtup_fst_369 { std::get<0>(dtup_368) };
                                auto dtup_snd_370 { std::get<1>(dtup_368) };
                                uint32_t id_2648 { 0U };
                                Vec<1, uint32_t> id_2649 {  id_2648  };
                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2650;
                                {
                                  Vec<1, uint32_t> leb_ref_371 { id_2649 };
                                  uint8_t id_2651 { 0 };
                                  Vec<1, uint8_t> id_2652 {  id_2651  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2653;
                                  {
                                    Vec<1, uint8_t> shft_ref_372 { id_2652 };
                                    Vec<1, Pointer> id_2654 {  dtup_snd_370  };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2655;
                                    {
                                      Vec<1, Pointer> p_ref_373 { id_2654 };
                                      bool while_flag_2656 { true };
                                      do {
                                        uint8_t id_2657 { 0 };
                                        Pointer id_2658 { p_ref_373[id_2657] };
                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2659 { id_2658.readU8() };
                                        bool let_res_2660;
                                        {
                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_374 { id_2659 };
                                          bool letpair_res_2661;
                                          {
                                            auto leb128_fst_375 { std::get<0>(leb128_374) };
                                            auto leb128_snd_376 { std::get<1>(leb128_374) };
                                            uint8_t id_2662 { 0 };
                                            Void id_2663 { ((void)(p_ref_373[id_2662] = leb128_snd_376), VOID) };
                                            (void)id_2663;
                                            uint8_t id_2664 { 0 };
                                            uint8_t id_2665 { 127 };
                                            uint8_t id_2666 { uint8_t(leb128_fst_375 & id_2665) };
                                            uint32_t id_2667 { uint32_t(id_2666) };
                                            uint8_t id_2668 { 0 };
                                            uint8_t id_2669 { shft_ref_372[id_2668] };
                                            uint32_t id_2670 { uint32_t(id_2667 << id_2669) };
                                            uint8_t id_2671 { 0 };
                                            uint32_t id_2672 { leb_ref_371[id_2671] };
                                            uint32_t id_2673 { uint32_t(id_2670 | id_2672) };
                                            Void id_2674 { ((void)(leb_ref_371[id_2664] = id_2673), VOID) };
                                            (void)id_2674;
                                            uint8_t id_2675 { 0 };
                                            uint8_t id_2676 { 0 };
                                            uint8_t id_2677 { shft_ref_372[id_2676] };
                                            uint8_t id_2678 { 7 };
                                            uint8_t id_2679 { uint8_t(id_2677 + id_2678) };
                                            Void id_2680 { ((void)(shft_ref_372[id_2675] = id_2679), VOID) };
                                            (void)id_2680;
                                            uint8_t id_2681 { 128 };
                                            bool id_2682 { bool(leb128_fst_375 >= id_2681) };
                                            letpair_res_2661 = id_2682;
                                          }
                                          let_res_2660 = letpair_res_2661;
                                        }
                                        while_flag_2656 = let_res_2660;
                                        if (while_flag_2656) {
                                          (void)VOID;
                                        }
                                      } while (while_flag_2656);
                                      (void)VOID;
                                      uint8_t id_2683 { 0 };
                                      uint32_t id_2684 { leb_ref_371[id_2683] };
                                      Size id_2685 { Size(id_2684) };
                                      uint8_t id_2686 { 0 };
                                      Pointer id_2687 { p_ref_373[id_2686] };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2688 { id_2685, id_2687 };
                                      let_res_2655 = id_2688;
                                    }
                                    let_res_2653 = let_res_2655;
                                  }
                                  let_res_2650 = let_res_2653;
                                }
                                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2689;
                                {
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_377 { let_res_2650 };
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2690;
                                  {
                                    auto dstring1_fst_378 { std::get<0>(dstring1_377) };
                                    auto dstring1_snd_379 { std::get<1>(dstring1_377) };
                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2691 { dstring1_snd_379.readBytes(dstring1_fst_378) };
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2692;
                                    {
                                      auto dstring2_fst_381 { std::get<0>(id_2691) };
                                      auto dstring2_snd_382 { std::get<1>(id_2691) };
                                      std::string id_2693 { dstring2_fst_381.toString() };
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2694 { id_2693, dstring2_snd_382 };
                                      letpair_res_2692 = id_2694;
                                    }
                                    letpair_res_2690 = letpair_res_2692;
                                  }
                                  let_res_2689 = letpair_res_2690;
                                }
                                ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2695;
                                {
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_383 { let_res_2689 };
                                  ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2696;
                                  {
                                    auto dtup_fst_384 { std::get<0>(dtup_383) };
                                    auto dtup_snd_385 { std::get<1>(dtup_383) };
                                    ::dessser::gen::sync_key::t5f750ede44b214b8c8c8313f068ccc23 id_2697 { per_tail_of_row_binary(dtup_snd_385) };
                                    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2698;
                                    {
                                      auto dtup_fst_387 { std::get<0>(id_2697) };
                                      auto dtup_snd_388 { std::get<1>(id_2697) };
                                      ::dessser::gen::sync_key::t1fe1711acd7cd3c8e5ef24184b852848 id_2699 { dtup_fst_366, dtup_fst_369, dtup_fst_384, dtup_fst_387 };
                                      ::dessser::gen::sync_key::t* id_2700 { new ::dessser::gen::sync_key::t(std::in_place_index<7>, id_2699) };
                                      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2701 { id_2700, dtup_snd_388 };
                                      letpair_res_2698 = id_2701;
                                    }
                                    letpair_res_2696 = letpair_res_2698;
                                  }
                                  let_res_2695 = letpair_res_2696;
                                }
                                letpair_res_2647 = let_res_2695;
                              }
                              let_res_2646 = letpair_res_2647;
                            }
                            letpair_res_2643 = let_res_2646;
                          }
                          let_res_2642 = letpair_res_2643;
                        }
                        choose_res_2639 = let_res_2642;
                      } else {
                        uint16_t id_2702 { 8 };
                        bool id_2703 { bool(id_2702 == dsum1_fst_144) };
                        ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2704;
                        if (id_2703) {
                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2705 { dsum1_snd_145.readU16Le() };
                          ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2706;
                          {
                            auto du16_fst_360 { std::get<0>(id_2705) };
                            auto du16_snd_361 { std::get<1>(id_2705) };
                            ::dessser::gen::sync_key::t* id_2707 { new ::dessser::gen::sync_key::t(std::in_place_index<8>, du16_fst_360) };
                            ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2708 { id_2707, du16_snd_361 };
                            letpair_res_2706 = id_2708;
                          }
                          choose_res_2704 = letpair_res_2706;
                        } else {
                          uint16_t id_2709 { 9 };
                          bool id_2710 { bool(id_2709 == dsum1_fst_144) };
                          ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2711;
                          if (id_2710) {
                            Size id_2712 { 0UL };
                            uint8_t id_2713 { dsum1_snd_145.peekU8(id_2712) };
                            uint8_t id_2714 { 1 };
                            bool id_2715 { bool(id_2713 == id_2714) };
                            ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 choose_res_2716;
                            if (id_2715) {
                              std::optional<dessser::gen::sync_socket::t_ext> id_2717 { std::nullopt };
                              Size id_2718 { 1UL };
                              Pointer id_2719 { dsum1_snd_145.skip(id_2718) };
                              ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 id_2720 { id_2717, id_2719 };
                              choose_res_2716 = id_2720;
                            } else {
                              auto fun2721 { dessser::gen::sync_socket::of_row_binary };
                              Size id_2722 { 1UL };
                              Pointer id_2723 { dsum1_snd_145.skip(id_2722) };
                              ::dessser::gen::sync_key::t8a365991c4a4591932e21c9e1eeeab20 id_2724 { fun2721(id_2723) };
                              ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 letpair_res_2725;
                              {
                                auto make1_1_fst_354 { std::get<0>(id_2724) };
                                auto make1_1_snd_355 { std::get<1>(id_2724) };
                                std::optional<dessser::gen::sync_socket::t_ext> id_2726 { make1_1_fst_354 };
                                ::dessser::gen::sync_key::tdcc52da48df168277d8c161116b319a7 id_2727 { id_2726, make1_1_snd_355 };
                                letpair_res_2725 = id_2727;
                              }
                              choose_res_2716 = letpair_res_2725;
                            }
                            ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2728;
                            {
                              auto dsum2_fst_357 { std::get<0>(choose_res_2716) };
                              auto dsum2_snd_358 { std::get<1>(choose_res_2716) };
                              ::dessser::gen::sync_key::t* id_2729 { new ::dessser::gen::sync_key::t(std::in_place_index<9>, dsum2_fst_357) };
                              ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2730 { id_2729, dsum2_snd_358 };
                              letpair_res_2728 = id_2730;
                            }
                            choose_res_2711 = letpair_res_2728;
                          } else {
                            uint16_t id_2731 { 10 };
                            bool id_2732 { bool(id_2731 == dsum1_fst_144) };
                            ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2733;
                            if (id_2732) {
                              (void)VOID;
                              ::dessser::gen::sync_key::t* id_2734 { new ::dessser::gen::sync_key::t(std::in_place_index<10>, VOID) };
                              ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2735 { id_2734, dsum1_snd_145 };
                              choose_res_2733 = id_2735;
                            } else {
                              uint16_t id_2736 { 11 };
                              bool id_2737 { bool(id_2736 == dsum1_fst_144) };
                              ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2738;
                              if (id_2737) {
                                auto fun2739 { dessser::gen::sync_socket::of_row_binary };
                                ::dessser::gen::sync_key::t8a365991c4a4591932e21c9e1eeeab20 id_2740 { fun2739(dsum1_snd_145) };
                                ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2741;
                                {
                                  ::dessser::gen::sync_key::t8a365991c4a4591932e21c9e1eeeab20 dtup_341 { id_2740 };
                                  ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2742;
                                  {
                                    auto dtup_fst_342 { std::get<0>(dtup_341) };
                                    auto dtup_snd_343 { std::get<1>(dtup_341) };
                                    ::dessser::gen::sync_key::ta604b376a0844fde5b1ddf9a5c29cb43 id_2743 { per_client_of_row_binary(dtup_snd_343) };
                                    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2744;
                                    {
                                      auto dtup_fst_345 { std::get<0>(id_2743) };
                                      auto dtup_snd_346 { std::get<1>(id_2743) };
                                      ::dessser::gen::sync_key::t3f175f4a6fba6fdb7dfcec615c7c9650 id_2745 { dtup_fst_342, dtup_fst_345 };
                                      ::dessser::gen::sync_key::t* id_2746 { new ::dessser::gen::sync_key::t(std::in_place_index<11>, id_2745) };
                                      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2747 { id_2746, dtup_snd_346 };
                                      letpair_res_2744 = id_2747;
                                    }
                                    letpair_res_2742 = letpair_res_2744;
                                  }
                                  let_res_2741 = letpair_res_2742;
                                }
                                choose_res_2738 = let_res_2741;
                              } else {
                                uint16_t id_2748 { 12 };
                                bool id_2749 { bool(id_2748 == dsum1_fst_144) };
                                ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2750;
                                if (id_2749) {
                                  uint32_t id_2751 { 0U };
                                  Vec<1, uint32_t> id_2752 {  id_2751  };
                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2753;
                                  {
                                    Vec<1, uint32_t> leb_ref_320 { id_2752 };
                                    uint8_t id_2754 { 0 };
                                    Vec<1, uint8_t> id_2755 {  id_2754  };
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2756;
                                    {
                                      Vec<1, uint8_t> shft_ref_321 { id_2755 };
                                      Vec<1, Pointer> id_2757 {  dsum1_snd_145  };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2758;
                                      {
                                        Vec<1, Pointer> p_ref_322 { id_2757 };
                                        bool while_flag_2759 { true };
                                        do {
                                          uint8_t id_2760 { 0 };
                                          Pointer id_2761 { p_ref_322[id_2760] };
                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2762 { id_2761.readU8() };
                                          bool let_res_2763;
                                          {
                                            ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_323 { id_2762 };
                                            bool letpair_res_2764;
                                            {
                                              auto leb128_fst_324 { std::get<0>(leb128_323) };
                                              auto leb128_snd_325 { std::get<1>(leb128_323) };
                                              uint8_t id_2765 { 0 };
                                              Void id_2766 { ((void)(p_ref_322[id_2765] = leb128_snd_325), VOID) };
                                              (void)id_2766;
                                              uint8_t id_2767 { 0 };
                                              uint8_t id_2768 { 127 };
                                              uint8_t id_2769 { uint8_t(leb128_fst_324 & id_2768) };
                                              uint32_t id_2770 { uint32_t(id_2769) };
                                              uint8_t id_2771 { 0 };
                                              uint8_t id_2772 { shft_ref_321[id_2771] };
                                              uint32_t id_2773 { uint32_t(id_2770 << id_2772) };
                                              uint8_t id_2774 { 0 };
                                              uint32_t id_2775 { leb_ref_320[id_2774] };
                                              uint32_t id_2776 { uint32_t(id_2773 | id_2775) };
                                              Void id_2777 { ((void)(leb_ref_320[id_2767] = id_2776), VOID) };
                                              (void)id_2777;
                                              uint8_t id_2778 { 0 };
                                              uint8_t id_2779 { 0 };
                                              uint8_t id_2780 { shft_ref_321[id_2779] };
                                              uint8_t id_2781 { 7 };
                                              uint8_t id_2782 { uint8_t(id_2780 + id_2781) };
                                              Void id_2783 { ((void)(shft_ref_321[id_2778] = id_2782), VOID) };
                                              (void)id_2783;
                                              uint8_t id_2784 { 128 };
                                              bool id_2785 { bool(leb128_fst_324 >= id_2784) };
                                              letpair_res_2764 = id_2785;
                                            }
                                            let_res_2763 = letpair_res_2764;
                                          }
                                          while_flag_2759 = let_res_2763;
                                          if (while_flag_2759) {
                                            (void)VOID;
                                          }
                                        } while (while_flag_2759);
                                        (void)VOID;
                                        uint8_t id_2786 { 0 };
                                        uint32_t id_2787 { leb_ref_320[id_2786] };
                                        Size id_2788 { Size(id_2787) };
                                        uint8_t id_2789 { 0 };
                                        Pointer id_2790 { p_ref_322[id_2789] };
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2791 { id_2788, id_2790 };
                                        let_res_2758 = id_2791;
                                      }
                                      let_res_2756 = let_res_2758;
                                    }
                                    let_res_2753 = let_res_2756;
                                  }
                                  ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2792;
                                  {
                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_326 { let_res_2753 };
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2793;
                                    {
                                      auto dstring1_fst_327 { std::get<0>(dstring1_326) };
                                      auto dstring1_snd_328 { std::get<1>(dstring1_326) };
                                      ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2794 { dstring1_snd_328.readBytes(dstring1_fst_327) };
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2795;
                                      {
                                        auto dstring2_fst_330 { std::get<0>(id_2794) };
                                        auto dstring2_snd_331 { std::get<1>(id_2794) };
                                        std::string id_2796 { dstring2_fst_330.toString() };
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2797 { id_2796, dstring2_snd_331 };
                                        letpair_res_2795 = id_2797;
                                      }
                                      letpair_res_2793 = letpair_res_2795;
                                    }
                                    let_res_2792 = letpair_res_2793;
                                  }
                                  ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2798;
                                  {
                                    ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_332 { let_res_2792 };
                                    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2799;
                                    {
                                      auto dtup_fst_333 { std::get<0>(dtup_332) };
                                      auto dtup_snd_334 { std::get<1>(dtup_332) };
                                      ::dessser::gen::sync_key::tcce73bde988985bdd0bca77372a40274 id_2800 { per_dash_key_of_row_binary(dtup_snd_334) };
                                      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2801;
                                      {
                                        auto dtup_fst_336 { std::get<0>(id_2800) };
                                        auto dtup_snd_337 { std::get<1>(id_2800) };
                                        ::dessser::gen::sync_key::t078f1eb283aa345c511748969bd72218 id_2802 { dtup_fst_333, dtup_fst_336 };
                                        ::dessser::gen::sync_key::t* id_2803 { new ::dessser::gen::sync_key::t(std::in_place_index<12>, id_2802) };
                                        ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2804 { id_2803, dtup_snd_337 };
                                        letpair_res_2801 = id_2804;
                                      }
                                      letpair_res_2799 = letpair_res_2801;
                                    }
                                    let_res_2798 = letpair_res_2799;
                                  }
                                  choose_res_2750 = let_res_2798;
                                } else {
                                  uint16_t id_2805 { 13 };
                                  bool id_2806 { bool(id_2805 == dsum1_fst_144) };
                                  ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2807;
                                  if (id_2806) {
                                    (void)VOID;
                                    ::dessser::gen::sync_key::t* id_2808 { new ::dessser::gen::sync_key::t(std::in_place_index<13>, VOID) };
                                    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2809 { id_2808, dsum1_snd_145 };
                                    choose_res_2807 = id_2809;
                                  } else {
                                    uint16_t id_2810 { 14 };
                                    bool id_2811 { bool(id_2810 == dsum1_fst_144) };
                                    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 choose_res_2812;
                                    if (id_2811) {
                                      uint32_t id_2813 { 0U };
                                      Vec<1, uint32_t> id_2814 {  id_2813  };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2815;
                                      {
                                        Vec<1, uint32_t> leb_ref_257 { id_2814 };
                                        uint8_t id_2816 { 0 };
                                        Vec<1, uint8_t> id_2817 {  id_2816  };
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2818;
                                        {
                                          Vec<1, uint8_t> shft_ref_258 { id_2817 };
                                          Vec<1, Pointer> id_2819 {  dsum1_snd_145  };
                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2820;
                                          {
                                            Vec<1, Pointer> p_ref_259 { id_2819 };
                                            bool while_flag_2821 { true };
                                            do {
                                              uint8_t id_2822 { 0 };
                                              Pointer id_2823 { p_ref_259[id_2822] };
                                              ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2824 { id_2823.readU8() };
                                              bool let_res_2825;
                                              {
                                                ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_260 { id_2824 };
                                                bool letpair_res_2826;
                                                {
                                                  auto leb128_fst_261 { std::get<0>(leb128_260) };
                                                  auto leb128_snd_262 { std::get<1>(leb128_260) };
                                                  uint8_t id_2827 { 0 };
                                                  Void id_2828 { ((void)(p_ref_259[id_2827] = leb128_snd_262), VOID) };
                                                  (void)id_2828;
                                                  uint8_t id_2829 { 0 };
                                                  uint8_t id_2830 { 127 };
                                                  uint8_t id_2831 { uint8_t(leb128_fst_261 & id_2830) };
                                                  uint32_t id_2832 { uint32_t(id_2831) };
                                                  uint8_t id_2833 { 0 };
                                                  uint8_t id_2834 { shft_ref_258[id_2833] };
                                                  uint32_t id_2835 { uint32_t(id_2832 << id_2834) };
                                                  uint8_t id_2836 { 0 };
                                                  uint32_t id_2837 { leb_ref_257[id_2836] };
                                                  uint32_t id_2838 { uint32_t(id_2835 | id_2837) };
                                                  Void id_2839 { ((void)(leb_ref_257[id_2829] = id_2838), VOID) };
                                                  (void)id_2839;
                                                  uint8_t id_2840 { 0 };
                                                  uint8_t id_2841 { 0 };
                                                  uint8_t id_2842 { shft_ref_258[id_2841] };
                                                  uint8_t id_2843 { 7 };
                                                  uint8_t id_2844 { uint8_t(id_2842 + id_2843) };
                                                  Void id_2845 { ((void)(shft_ref_258[id_2840] = id_2844), VOID) };
                                                  (void)id_2845;
                                                  uint8_t id_2846 { 128 };
                                                  bool id_2847 { bool(leb128_fst_261 >= id_2846) };
                                                  letpair_res_2826 = id_2847;
                                                }
                                                let_res_2825 = letpair_res_2826;
                                              }
                                              while_flag_2821 = let_res_2825;
                                              if (while_flag_2821) {
                                                (void)VOID;
                                              }
                                            } while (while_flag_2821);
                                            (void)VOID;
                                            uint8_t id_2848 { 0 };
                                            uint32_t id_2849 { leb_ref_257[id_2848] };
                                            Size id_2850 { Size(id_2849) };
                                            uint8_t id_2851 { 0 };
                                            Pointer id_2852 { p_ref_259[id_2851] };
                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2853 { id_2850, id_2852 };
                                            let_res_2820 = id_2853;
                                          }
                                          let_res_2818 = let_res_2820;
                                        }
                                        let_res_2815 = let_res_2818;
                                      }
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_2854;
                                      {
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_263 { let_res_2815 };
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2855;
                                        {
                                          auto dstring1_fst_264 { std::get<0>(dstring1_263) };
                                          auto dstring1_snd_265 { std::get<1>(dstring1_263) };
                                          ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2856 { dstring1_snd_265.readBytes(dstring1_fst_264) };
                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_2857;
                                          {
                                            auto dstring2_fst_267 { std::get<0>(id_2856) };
                                            auto dstring2_snd_268 { std::get<1>(id_2856) };
                                            std::string id_2858 { dstring2_fst_267.toString() };
                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_2859 { id_2858, dstring2_snd_268 };
                                            letpair_res_2857 = id_2859;
                                          }
                                          letpair_res_2855 = letpair_res_2857;
                                        }
                                        let_res_2854 = letpair_res_2855;
                                      }
                                      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_2860;
                                      {
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_269 { let_res_2854 };
                                        ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2861;
                                        {
                                          auto dtup_fst_270 { std::get<0>(dtup_269) };
                                          auto dtup_snd_271 { std::get<1>(dtup_269) };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2862 { dtup_snd_271.readU16Le() };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_2863;
                                          {
                                            auto du16_fst_273 { std::get<0>(id_2862) };
                                            auto du16_snd_274 { std::get<1>(id_2862) };
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_2864 { du16_fst_273, du16_snd_274 };
                                            letpair_res_2863 = id_2864;
                                          }
                                          ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 let_res_2865;
                                          {
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_278 { letpair_res_2863 };
                                            ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2866;
                                            {
                                              auto dsum1_fst_279 { std::get<0>(dsum1_278) };
                                              auto dsum1_snd_280 { std::get<1>(dsum1_278) };
                                              uint16_t id_2867 { 0 };
                                              bool id_2868 { bool(id_2867 == dsum1_fst_279) };
                                              ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 choose_res_2869;
                                              if (id_2868) {
                                                uint32_t id_2870 { 0U };
                                                Vec<1, uint32_t> id_2871 {  id_2870  };
                                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2872;
                                                {
                                                  Vec<1, uint32_t> leb_ref_296 { id_2871 };
                                                  uint8_t id_2873 { 0 };
                                                  Vec<1, uint8_t> id_2874 {  id_2873  };
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2875;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_297 { id_2874 };
                                                    Vec<1, Pointer> id_2876 {  dsum1_snd_280  };
                                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2877;
                                                    {
                                                      Vec<1, Pointer> p_ref_298 { id_2876 };
                                                      bool while_flag_2878 { true };
                                                      do {
                                                        uint8_t id_2879 { 0 };
                                                        Pointer id_2880 { p_ref_298[id_2879] };
                                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2881 { id_2880.readU8() };
                                                        bool let_res_2882;
                                                        {
                                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_299 { id_2881 };
                                                          bool letpair_res_2883;
                                                          {
                                                            auto leb128_fst_300 { std::get<0>(leb128_299) };
                                                            auto leb128_snd_301 { std::get<1>(leb128_299) };
                                                            uint8_t id_2884 { 0 };
                                                            Void id_2885 { ((void)(p_ref_298[id_2884] = leb128_snd_301), VOID) };
                                                            (void)id_2885;
                                                            uint8_t id_2886 { 0 };
                                                            uint8_t id_2887 { 127 };
                                                            uint8_t id_2888 { uint8_t(leb128_fst_300 & id_2887) };
                                                            uint32_t id_2889 { uint32_t(id_2888) };
                                                            uint8_t id_2890 { 0 };
                                                            uint8_t id_2891 { shft_ref_297[id_2890] };
                                                            uint32_t id_2892 { uint32_t(id_2889 << id_2891) };
                                                            uint8_t id_2893 { 0 };
                                                            uint32_t id_2894 { leb_ref_296[id_2893] };
                                                            uint32_t id_2895 { uint32_t(id_2892 | id_2894) };
                                                            Void id_2896 { ((void)(leb_ref_296[id_2886] = id_2895), VOID) };
                                                            (void)id_2896;
                                                            uint8_t id_2897 { 0 };
                                                            uint8_t id_2898 { 0 };
                                                            uint8_t id_2899 { shft_ref_297[id_2898] };
                                                            uint8_t id_2900 { 7 };
                                                            uint8_t id_2901 { uint8_t(id_2899 + id_2900) };
                                                            Void id_2902 { ((void)(shft_ref_297[id_2897] = id_2901), VOID) };
                                                            (void)id_2902;
                                                            uint8_t id_2903 { 128 };
                                                            bool id_2904 { bool(leb128_fst_300 >= id_2903) };
                                                            letpair_res_2883 = id_2904;
                                                          }
                                                          let_res_2882 = letpair_res_2883;
                                                        }
                                                        while_flag_2878 = let_res_2882;
                                                        if (while_flag_2878) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_2878);
                                                      (void)VOID;
                                                      uint8_t id_2905 { 0 };
                                                      uint32_t id_2906 { leb_ref_296[id_2905] };
                                                      Size id_2907 { Size(id_2906) };
                                                      uint8_t id_2908 { 0 };
                                                      Pointer id_2909 { p_ref_298[id_2908] };
                                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2910 { id_2907, id_2909 };
                                                      let_res_2877 = id_2910;
                                                    }
                                                    let_res_2875 = let_res_2877;
                                                  }
                                                  let_res_2872 = let_res_2875;
                                                }
                                                ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 let_res_2911;
                                                {
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_302 { let_res_2872 };
                                                  ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2912;
                                                  {
                                                    auto dstring1_fst_303 { std::get<0>(dstring1_302) };
                                                    auto dstring1_snd_304 { std::get<1>(dstring1_302) };
                                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2913 { dstring1_snd_304.readBytes(dstring1_fst_303) };
                                                    ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2914;
                                                    {
                                                      auto dstring2_fst_306 { std::get<0>(id_2913) };
                                                      auto dstring2_snd_307 { std::get<1>(id_2913) };
                                                      std::string id_2915 { dstring2_fst_306.toString() };
                                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_2916 { std::in_place_index<0>, id_2915 };
                                                      ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 id_2917 { id_2916, dstring2_snd_307 };
                                                      letpair_res_2914 = id_2917;
                                                    }
                                                    letpair_res_2912 = letpair_res_2914;
                                                  }
                                                  let_res_2911 = letpair_res_2912;
                                                }
                                                choose_res_2869 = let_res_2911;
                                              } else {
                                                uint16_t id_2918 { 1 };
                                                bool id_2919 { bool(dsum1_fst_279 == id_2918) };
                                                Void id_2920 { ((void)(assert(id_2919)), VOID) };
                                                (void)id_2920;
                                                uint32_t id_2921 { 0U };
                                                Vec<1, uint32_t> id_2922 {  id_2921  };
                                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2923;
                                                {
                                                  Vec<1, uint32_t> leb_ref_281 { id_2922 };
                                                  uint8_t id_2924 { 0 };
                                                  Vec<1, uint8_t> id_2925 {  id_2924  };
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2926;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_282 { id_2925 };
                                                    Vec<1, Pointer> id_2927 {  dsum1_snd_280  };
                                                    ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2928;
                                                    {
                                                      Vec<1, Pointer> p_ref_283 { id_2927 };
                                                      bool while_flag_2929 { true };
                                                      do {
                                                        uint8_t id_2930 { 0 };
                                                        Pointer id_2931 { p_ref_283[id_2930] };
                                                        ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2932 { id_2931.readU8() };
                                                        bool let_res_2933;
                                                        {
                                                          ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_284 { id_2932 };
                                                          bool letpair_res_2934;
                                                          {
                                                            auto leb128_fst_285 { std::get<0>(leb128_284) };
                                                            auto leb128_snd_286 { std::get<1>(leb128_284) };
                                                            uint8_t id_2935 { 0 };
                                                            Void id_2936 { ((void)(p_ref_283[id_2935] = leb128_snd_286), VOID) };
                                                            (void)id_2936;
                                                            uint8_t id_2937 { 0 };
                                                            uint8_t id_2938 { 127 };
                                                            uint8_t id_2939 { uint8_t(leb128_fst_285 & id_2938) };
                                                            uint32_t id_2940 { uint32_t(id_2939) };
                                                            uint8_t id_2941 { 0 };
                                                            uint8_t id_2942 { shft_ref_282[id_2941] };
                                                            uint32_t id_2943 { uint32_t(id_2940 << id_2942) };
                                                            uint8_t id_2944 { 0 };
                                                            uint32_t id_2945 { leb_ref_281[id_2944] };
                                                            uint32_t id_2946 { uint32_t(id_2943 | id_2945) };
                                                            Void id_2947 { ((void)(leb_ref_281[id_2937] = id_2946), VOID) };
                                                            (void)id_2947;
                                                            uint8_t id_2948 { 0 };
                                                            uint8_t id_2949 { 0 };
                                                            uint8_t id_2950 { shft_ref_282[id_2949] };
                                                            uint8_t id_2951 { 7 };
                                                            uint8_t id_2952 { uint8_t(id_2950 + id_2951) };
                                                            Void id_2953 { ((void)(shft_ref_282[id_2948] = id_2952), VOID) };
                                                            (void)id_2953;
                                                            uint8_t id_2954 { 128 };
                                                            bool id_2955 { bool(leb128_fst_285 >= id_2954) };
                                                            letpair_res_2934 = id_2955;
                                                          }
                                                          let_res_2933 = letpair_res_2934;
                                                        }
                                                        while_flag_2929 = let_res_2933;
                                                        if (while_flag_2929) {
                                                          (void)VOID;
                                                        }
                                                      } while (while_flag_2929);
                                                      (void)VOID;
                                                      uint8_t id_2956 { 0 };
                                                      uint32_t id_2957 { leb_ref_281[id_2956] };
                                                      Size id_2958 { Size(id_2957) };
                                                      uint8_t id_2959 { 0 };
                                                      Pointer id_2960 { p_ref_283[id_2959] };
                                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_2961 { id_2958, id_2960 };
                                                      let_res_2928 = id_2961;
                                                    }
                                                    let_res_2926 = let_res_2928;
                                                  }
                                                  let_res_2923 = let_res_2926;
                                                }
                                                ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 let_res_2962;
                                                {
                                                  ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_287 { let_res_2923 };
                                                  ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2963;
                                                  {
                                                    auto dstring1_fst_288 { std::get<0>(dstring1_287) };
                                                    auto dstring1_snd_289 { std::get<1>(dstring1_287) };
                                                    ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_2964 { dstring1_snd_289.readBytes(dstring1_fst_288) };
                                                    ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 letpair_res_2965;
                                                    {
                                                      auto dstring2_fst_291 { std::get<0>(id_2964) };
                                                      auto dstring2_snd_292 { std::get<1>(id_2964) };
                                                      std::string id_2966 { dstring2_fst_291.toString() };
                                                      ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f id_2967 { std::in_place_index<1>, id_2966 };
                                                      ::dessser::gen::sync_key::t3a8843ea98675a135ad450a23aa2b2c8 id_2968 { id_2967, dstring2_snd_292 };
                                                      letpair_res_2965 = id_2968;
                                                    }
                                                    letpair_res_2963 = letpair_res_2965;
                                                  }
                                                  let_res_2962 = letpair_res_2963;
                                                }
                                                choose_res_2869 = let_res_2962;
                                              }
                                              letpair_res_2866 = choose_res_2869;
                                            }
                                            let_res_2865 = letpair_res_2866;
                                          }
                                          ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_2969;
                                          {
                                            auto dtup_fst_312 { std::get<0>(let_res_2865) };
                                            auto dtup_snd_313 { std::get<1>(let_res_2865) };
                                            ::dessser::gen::sync_key::tdf2a6472960228e59d64c7f9dc00dcfa id_2970 { dtup_fst_270, dtup_fst_312 };
                                            ::dessser::gen::sync_key::t* id_2971 { new ::dessser::gen::sync_key::t(std::in_place_index<14>, id_2970) };
                                            ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_2972 { id_2971, dtup_snd_313 };
                                            letpair_res_2969 = id_2972;
                                          }
                                          letpair_res_2861 = letpair_res_2969;
                                        }
                                        let_res_2860 = letpair_res_2861;
                                      }
                                      choose_res_2812 = let_res_2860;
                                    } else {
                                      uint16_t id_2973 { 15 };
                                      bool id_2974 { bool(dsum1_fst_144 == id_2973) };
                                      Void id_2975 { ((void)(assert(id_2974)), VOID) };
                                      (void)id_2975;
                                      uint32_t id_2976 { 0U };
                                      Vec<1, uint32_t> id_2977 {  id_2976  };
                                      ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2978;
                                      {
                                        Vec<1, uint32_t> leb_ref_146 { id_2977 };
                                        uint8_t id_2979 { 0 };
                                        Vec<1, uint8_t> id_2980 {  id_2979  };
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2981;
                                        {
                                          Vec<1, uint8_t> shft_ref_147 { id_2980 };
                                          Vec<1, Pointer> id_2982 {  dsum1_snd_145  };
                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_2983;
                                          {
                                            Vec<1, Pointer> p_ref_148 { id_2982 };
                                            bool while_flag_2984 { true };
                                            do {
                                              uint8_t id_2985 { 0 };
                                              Pointer id_2986 { p_ref_148[id_2985] };
                                              ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_2987 { id_2986.readU8() };
                                              bool let_res_2988;
                                              {
                                                ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_149 { id_2987 };
                                                bool letpair_res_2989;
                                                {
                                                  auto leb128_fst_150 { std::get<0>(leb128_149) };
                                                  auto leb128_snd_151 { std::get<1>(leb128_149) };
                                                  uint8_t id_2990 { 0 };
                                                  Void id_2991 { ((void)(p_ref_148[id_2990] = leb128_snd_151), VOID) };
                                                  (void)id_2991;
                                                  uint8_t id_2992 { 0 };
                                                  uint8_t id_2993 { 127 };
                                                  uint8_t id_2994 { uint8_t(leb128_fst_150 & id_2993) };
                                                  uint32_t id_2995 { uint32_t(id_2994) };
                                                  uint8_t id_2996 { 0 };
                                                  uint8_t id_2997 { shft_ref_147[id_2996] };
                                                  uint32_t id_2998 { uint32_t(id_2995 << id_2997) };
                                                  uint8_t id_2999 { 0 };
                                                  uint32_t id_3000 { leb_ref_146[id_2999] };
                                                  uint32_t id_3001 { uint32_t(id_2998 | id_3000) };
                                                  Void id_3002 { ((void)(leb_ref_146[id_2992] = id_3001), VOID) };
                                                  (void)id_3002;
                                                  uint8_t id_3003 { 0 };
                                                  uint8_t id_3004 { 0 };
                                                  uint8_t id_3005 { shft_ref_147[id_3004] };
                                                  uint8_t id_3006 { 7 };
                                                  uint8_t id_3007 { uint8_t(id_3005 + id_3006) };
                                                  Void id_3008 { ((void)(shft_ref_147[id_3003] = id_3007), VOID) };
                                                  (void)id_3008;
                                                  uint8_t id_3009 { 128 };
                                                  bool id_3010 { bool(leb128_fst_150 >= id_3009) };
                                                  letpair_res_2989 = id_3010;
                                                }
                                                let_res_2988 = letpair_res_2989;
                                              }
                                              while_flag_2984 = let_res_2988;
                                              if (while_flag_2984) {
                                                (void)VOID;
                                              }
                                            } while (while_flag_2984);
                                            (void)VOID;
                                            uint8_t id_3011 { 0 };
                                            uint32_t id_3012 { leb_ref_146[id_3011] };
                                            Size id_3013 { Size(id_3012) };
                                            uint8_t id_3014 { 0 };
                                            Pointer id_3015 { p_ref_148[id_3014] };
                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_3016 { id_3013, id_3015 };
                                            let_res_2983 = id_3016;
                                          }
                                          let_res_2981 = let_res_2983;
                                        }
                                        let_res_2978 = let_res_2981;
                                      }
                                      ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_3017;
                                      {
                                        ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_152 { let_res_2978 };
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_3018;
                                        {
                                          auto dstring1_fst_153 { std::get<0>(dstring1_152) };
                                          auto dstring1_snd_154 { std::get<1>(dstring1_152) };
                                          ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_3019 { dstring1_snd_154.readBytes(dstring1_fst_153) };
                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_3020;
                                          {
                                            auto dstring2_fst_156 { std::get<0>(id_3019) };
                                            auto dstring2_snd_157 { std::get<1>(id_3019) };
                                            std::string id_3021 { dstring2_fst_156.toString() };
                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_3022 { id_3021, dstring2_snd_157 };
                                            letpair_res_3020 = id_3022;
                                          }
                                          letpair_res_3018 = letpair_res_3020;
                                        }
                                        let_res_3017 = letpair_res_3018;
                                      }
                                      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 let_res_3023;
                                      {
                                        ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_158 { let_res_3017 };
                                        ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_3024;
                                        {
                                          auto dtup_fst_159 { std::get<0>(dtup_158) };
                                          auto dtup_snd_160 { std::get<1>(dtup_158) };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_3025 { dtup_snd_160.readU16Le() };
                                          ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_3026;
                                          {
                                            auto du16_fst_162 { std::get<0>(id_3025) };
                                            auto du16_snd_163 { std::get<1>(id_3025) };
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_3027 { du16_fst_162, du16_snd_163 };
                                            letpair_res_3026 = id_3027;
                                          }
                                          ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 let_res_3028;
                                          {
                                            ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_167 { letpair_res_3026 };
                                            ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_3029;
                                            {
                                              auto dsum1_fst_168 { std::get<0>(dsum1_167) };
                                              auto dsum1_snd_169 { std::get<1>(dsum1_167) };
                                              uint16_t id_3030 { 0 };
                                              bool id_3031 { bool(id_3030 == dsum1_fst_168) };
                                              ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_3032;
                                              if (id_3031) {
                                                (void)VOID;
                                                ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_3033 { std::in_place_index<0>, VOID };
                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_3034 { id_3033, dsum1_snd_169 };
                                                choose_res_3032 = id_3034;
                                              } else {
                                                uint16_t id_3035 { 1 };
                                                bool id_3036 { bool(id_3035 == dsum1_fst_168) };
                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_3037;
                                                if (id_3036) {
                                                  (void)VOID;
                                                  ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_3038 { std::in_place_index<1>, VOID };
                                                  ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_3039 { id_3038, dsum1_snd_169 };
                                                  choose_res_3037 = id_3039;
                                                } else {
                                                  uint16_t id_3040 { 2 };
                                                  bool id_3041 { bool(id_3040 == dsum1_fst_168) };
                                                  ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_3042;
                                                  if (id_3041) {
                                                    (void)VOID;
                                                    ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_3043 { std::in_place_index<2>, VOID };
                                                    ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_3044 { id_3043, dsum1_snd_169 };
                                                    choose_res_3042 = id_3044;
                                                  } else {
                                                    uint16_t id_3045 { 3 };
                                                    bool id_3046 { bool(id_3045 == dsum1_fst_168) };
                                                    ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_3047;
                                                    if (id_3046) {
                                                      (void)VOID;
                                                      ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_3048 { std::in_place_index<3>, VOID };
                                                      ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_3049 { id_3048, dsum1_snd_169 };
                                                      choose_res_3047 = id_3049;
                                                    } else {
                                                      uint16_t id_3050 { 4 };
                                                      bool id_3051 { bool(id_3050 == dsum1_fst_168) };
                                                      ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_3052;
                                                      if (id_3051) {
                                                        (void)VOID;
                                                        ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_3053 { std::in_place_index<4>, VOID };
                                                        ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_3054 { id_3053, dsum1_snd_169 };
                                                        choose_res_3052 = id_3054;
                                                      } else {
                                                        uint16_t id_3055 { 5 };
                                                        bool id_3056 { bool(id_3055 == dsum1_fst_168) };
                                                        ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 choose_res_3057;
                                                        if (id_3056) {
                                                          uint32_t id_3058 { 0U };
                                                          Vec<1, uint32_t> id_3059 {  id_3058  };
                                                          ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_3060;
                                                          {
                                                            Vec<1, uint32_t> leb_ref_185 { id_3059 };
                                                            uint8_t id_3061 { 0 };
                                                            Vec<1, uint8_t> id_3062 {  id_3061  };
                                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_3063;
                                                            {
                                                              Vec<1, uint8_t> shft_ref_186 { id_3062 };
                                                              Vec<1, Pointer> id_3064 {  dsum1_snd_169  };
                                                              ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 let_res_3065;
                                                              {
                                                                Vec<1, Pointer> p_ref_187 { id_3064 };
                                                                bool while_flag_3066 { true };
                                                                do {
                                                                  uint8_t id_3067 { 0 };
                                                                  Pointer id_3068 { p_ref_187[id_3067] };
                                                                  ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 id_3069 { id_3068.readU8() };
                                                                  bool let_res_3070;
                                                                  {
                                                                    ::dessser::gen::sync_key::t1566bd611d8a2b90669c241f5e8d6ff1 leb128_188 { id_3069 };
                                                                    bool letpair_res_3071;
                                                                    {
                                                                      auto leb128_fst_189 { std::get<0>(leb128_188) };
                                                                      auto leb128_snd_190 { std::get<1>(leb128_188) };
                                                                      uint8_t id_3072 { 0 };
                                                                      Void id_3073 { ((void)(p_ref_187[id_3072] = leb128_snd_190), VOID) };
                                                                      (void)id_3073;
                                                                      uint8_t id_3074 { 0 };
                                                                      uint8_t id_3075 { 127 };
                                                                      uint8_t id_3076 { uint8_t(leb128_fst_189 & id_3075) };
                                                                      uint32_t id_3077 { uint32_t(id_3076) };
                                                                      uint8_t id_3078 { 0 };
                                                                      uint8_t id_3079 { shft_ref_186[id_3078] };
                                                                      uint32_t id_3080 { uint32_t(id_3077 << id_3079) };
                                                                      uint8_t id_3081 { 0 };
                                                                      uint32_t id_3082 { leb_ref_185[id_3081] };
                                                                      uint32_t id_3083 { uint32_t(id_3080 | id_3082) };
                                                                      Void id_3084 { ((void)(leb_ref_185[id_3074] = id_3083), VOID) };
                                                                      (void)id_3084;
                                                                      uint8_t id_3085 { 0 };
                                                                      uint8_t id_3086 { 0 };
                                                                      uint8_t id_3087 { shft_ref_186[id_3086] };
                                                                      uint8_t id_3088 { 7 };
                                                                      uint8_t id_3089 { uint8_t(id_3087 + id_3088) };
                                                                      Void id_3090 { ((void)(shft_ref_186[id_3085] = id_3089), VOID) };
                                                                      (void)id_3090;
                                                                      uint8_t id_3091 { 128 };
                                                                      bool id_3092 { bool(leb128_fst_189 >= id_3091) };
                                                                      letpair_res_3071 = id_3092;
                                                                    }
                                                                    let_res_3070 = letpair_res_3071;
                                                                  }
                                                                  while_flag_3066 = let_res_3070;
                                                                  if (while_flag_3066) {
                                                                    (void)VOID;
                                                                  }
                                                                } while (while_flag_3066);
                                                                (void)VOID;
                                                                uint8_t id_3093 { 0 };
                                                                uint32_t id_3094 { leb_ref_185[id_3093] };
                                                                Size id_3095 { Size(id_3094) };
                                                                uint8_t id_3096 { 0 };
                                                                Pointer id_3097 { p_ref_187[id_3096] };
                                                                ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 id_3098 { id_3095, id_3097 };
                                                                let_res_3065 = id_3098;
                                                              }
                                                              let_res_3063 = let_res_3065;
                                                            }
                                                            let_res_3060 = let_res_3063;
                                                          }
                                                          ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 let_res_3099;
                                                          {
                                                            ::dessser::gen::sync_key::t044960e524fd6ec1bfc06410ce526709 dstring1_191 { let_res_3060 };
                                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_3100;
                                                            {
                                                              auto dstring1_fst_192 { std::get<0>(dstring1_191) };
                                                              auto dstring1_snd_193 { std::get<1>(dstring1_191) };
                                                              ::dessser::gen::sync_key::t5887709cc43c8c8e24d28211e8c970a2 id_3101 { dstring1_snd_193.readBytes(dstring1_fst_192) };
                                                              ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 letpair_res_3102;
                                                              {
                                                                auto dstring2_fst_195 { std::get<0>(id_3101) };
                                                                auto dstring2_snd_196 { std::get<1>(id_3101) };
                                                                std::string id_3103 { dstring2_fst_195.toString() };
                                                                ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 id_3104 { id_3103, dstring2_snd_196 };
                                                                letpair_res_3102 = id_3104;
                                                              }
                                                              letpair_res_3100 = letpair_res_3102;
                                                            }
                                                            let_res_3099 = letpair_res_3100;
                                                          }
                                                          ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 let_res_3105;
                                                          {
                                                            ::dessser::gen::sync_key::t3fd8221434e489b54b5c4356ebff5005 dtup_197 { let_res_3099 };
                                                            ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_3106;
                                                            {
                                                              auto dtup_fst_198 { std::get<0>(dtup_197) };
                                                              auto dtup_snd_199 { std::get<1>(dtup_197) };
                                                              ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_3107 { dtup_snd_199.readU16Le() };
                                                              ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b letpair_res_3108;
                                                              {
                                                                auto du16_fst_201 { std::get<0>(id_3107) };
                                                                auto du16_snd_202 { std::get<1>(id_3107) };
                                                                ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b id_3109 { du16_fst_201, du16_snd_202 };
                                                                letpair_res_3108 = id_3109;
                                                              }
                                                              ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 let_res_3110;
                                                              {
                                                                ::dessser::gen::sync_key::t7609d344c1ba69d0f80fec236d4c216b dsum1_206 { letpair_res_3108 };
                                                                ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 letpair_res_3111;
                                                                {
                                                                  auto dsum1_fst_207 { std::get<0>(dsum1_206) };
                                                                  auto dsum1_snd_208 { std::get<1>(dsum1_206) };
                                                                  uint16_t id_3112 { 0 };
                                                                  bool id_3113 { bool(id_3112 == dsum1_fst_207) };
                                                                  ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3114;
                                                                  if (id_3113) {
                                                                    (void)VOID;
                                                                    ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3115 { std::in_place_index<0>, VOID };
                                                                    ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3116 { id_3115, dsum1_snd_208 };
                                                                    choose_res_3114 = id_3116;
                                                                  } else {
                                                                    uint16_t id_3117 { 1 };
                                                                    bool id_3118 { bool(id_3117 == dsum1_fst_207) };
                                                                    ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3119;
                                                                    if (id_3118) {
                                                                      (void)VOID;
                                                                      ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3120 { std::in_place_index<1>, VOID };
                                                                      ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3121 { id_3120, dsum1_snd_208 };
                                                                      choose_res_3119 = id_3121;
                                                                    } else {
                                                                      uint16_t id_3122 { 2 };
                                                                      bool id_3123 { bool(id_3122 == dsum1_fst_207) };
                                                                      ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3124;
                                                                      if (id_3123) {
                                                                        (void)VOID;
                                                                        ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3125 { std::in_place_index<2>, VOID };
                                                                        ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3126 { id_3125, dsum1_snd_208 };
                                                                        choose_res_3124 = id_3126;
                                                                      } else {
                                                                        uint16_t id_3127 { 3 };
                                                                        bool id_3128 { bool(id_3127 == dsum1_fst_207) };
                                                                        ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3129;
                                                                        if (id_3128) {
                                                                          (void)VOID;
                                                                          ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3130 { std::in_place_index<3>, VOID };
                                                                          ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3131 { id_3130, dsum1_snd_208 };
                                                                          choose_res_3129 = id_3131;
                                                                        } else {
                                                                          uint16_t id_3132 { 4 };
                                                                          bool id_3133 { bool(id_3132 == dsum1_fst_207) };
                                                                          ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3134;
                                                                          if (id_3133) {
                                                                            (void)VOID;
                                                                            ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3135 { std::in_place_index<4>, VOID };
                                                                            ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3136 { id_3135, dsum1_snd_208 };
                                                                            choose_res_3134 = id_3136;
                                                                          } else {
                                                                            uint16_t id_3137 { 5 };
                                                                            bool id_3138 { bool(id_3137 == dsum1_fst_207) };
                                                                            ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 choose_res_3139;
                                                                            if (id_3138) {
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3140 { std::in_place_index<5>, VOID };
                                                                              ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3141 { id_3140, dsum1_snd_208 };
                                                                              choose_res_3139 = id_3141;
                                                                            } else {
                                                                              uint16_t id_3142 { 6 };
                                                                              bool id_3143 { bool(dsum1_fst_207 == id_3142) };
                                                                              Void id_3144 { ((void)(assert(id_3143)), VOID) };
                                                                              (void)id_3144;
                                                                              (void)VOID;
                                                                              ::dessser::gen::sync_key::t7cca840d7e40b13b976d995ba9f9fd5b id_3145 { std::in_place_index<6>, VOID };
                                                                              ::dessser::gen::sync_key::teb1e6c681b5c443ec217619fc46b4be9 id_3146 { id_3145, dsum1_snd_208 };
                                                                              choose_res_3139 = id_3146;
                                                                            }
                                                                            choose_res_3134 = choose_res_3139;
                                                                          }
                                                                          choose_res_3129 = choose_res_3134;
                                                                        }
                                                                        choose_res_3124 = choose_res_3129;
                                                                      }
                                                                      choose_res_3119 = choose_res_3124;
                                                                    }
                                                                    choose_res_3114 = choose_res_3119;
                                                                  }
                                                                  letpair_res_3111 = choose_res_3114;
                                                                }
                                                                let_res_3110 = letpair_res_3111;
                                                              }
                                                              ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_3147;
                                                              {
                                                                auto dtup_fst_231 { std::get<0>(let_res_3110) };
                                                                auto dtup_snd_232 { std::get<1>(let_res_3110) };
                                                                ::dessser::gen::sync_key::t5f10ae89970b1e8c27fc9f8df94fd836 id_3148 { dtup_fst_198, dtup_fst_231 };
                                                                ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_3149 { std::in_place_index<5>, id_3148 };
                                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_3150 { id_3149, dtup_snd_232 };
                                                                letpair_res_3147 = id_3150;
                                                              }
                                                              letpair_res_3106 = letpair_res_3147;
                                                            }
                                                            let_res_3105 = letpair_res_3106;
                                                          }
                                                          choose_res_3057 = let_res_3105;
                                                        } else {
                                                          uint16_t id_3151 { 6 };
                                                          bool id_3152 { bool(dsum1_fst_168 == id_3151) };
                                                          Void id_3153 { ((void)(assert(id_3152)), VOID) };
                                                          (void)id_3153;
                                                          ::dessser::gen::sync_key::tf568409f41c9c0a265f7302110fc9084 id_3154 { dsum1_snd_169.readU64Le() };
                                                          ::dessser::gen::sync_key::t5375de390f9cb5ae2ee5880ea1674828 letpair_res_3155;
                                                          {
                                                            auto dfloat_fst_171 { std::get<0>(id_3154) };
                                                            auto dfloat_snd_172 { std::get<1>(id_3154) };
                                                            double id_3156 { float_of_qword(dfloat_fst_171) };
                                                            ::dessser::gen::sync_key::t5375de390f9cb5ae2ee5880ea1674828 id_3157 { id_3156, dfloat_snd_172 };
                                                            letpair_res_3155 = id_3157;
                                                          }
                                                          ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 let_res_3158;
                                                          {
                                                            ::dessser::gen::sync_key::t5375de390f9cb5ae2ee5880ea1674828 dtup_173 { letpair_res_3155 };
                                                            ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_3159;
                                                            {
                                                              auto dtup_fst_174 { std::get<0>(dtup_173) };
                                                              auto dtup_snd_175 { std::get<1>(dtup_173) };
                                                              ::dessser::gen::sync_key::t883c6ffea47c0d7b950fe35881e3d737 id_3160 { dtup_snd_175.readU32Le() };
                                                              ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 letpair_res_3161;
                                                              {
                                                                auto du32_fst_177 { std::get<0>(id_3160) };
                                                                auto du32_snd_178 { std::get<1>(id_3160) };
                                                                ::dessser::gen::sync_key::t5f29f78957e3b1e9ec4688f50d1b6080 id_3162 { dtup_fst_174, du32_fst_177 };
                                                                ::dessser::gen::sync_key::t0c4a58933d47075f04ed70f827130a86 id_3163 { std::in_place_index<6>, id_3162 };
                                                                ::dessser::gen::sync_key::t873cf1aed4c62babb18fe01068a9e2b0 id_3164 { id_3163, du32_snd_178 };
                                                                letpair_res_3161 = id_3164;
                                                              }
                                                              letpair_res_3159 = letpair_res_3161;
                                                            }
                                                            let_res_3158 = letpair_res_3159;
                                                          }
                                                          choose_res_3057 = let_res_3158;
                                                        }
                                                        choose_res_3052 = choose_res_3057;
                                                      }
                                                      choose_res_3047 = choose_res_3052;
                                                    }
                                                    choose_res_3042 = choose_res_3047;
                                                  }
                                                  choose_res_3037 = choose_res_3042;
                                                }
                                                choose_res_3032 = choose_res_3037;
                                              }
                                              letpair_res_3029 = choose_res_3032;
                                            }
                                            let_res_3028 = letpair_res_3029;
                                          }
                                          ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_3165;
                                          {
                                            auto dtup_fst_252 { std::get<0>(let_res_3028) };
                                            auto dtup_snd_253 { std::get<1>(let_res_3028) };
                                            ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 id_3166 { dtup_fst_159, dtup_fst_252 };
                                            ::dessser::gen::sync_key::t* id_3167 { new ::dessser::gen::sync_key::t(std::in_place_index<15>, id_3166) };
                                            ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_3168 { id_3167, dtup_snd_253 };
                                            letpair_res_3165 = id_3168;
                                          }
                                          letpair_res_3024 = letpair_res_3165;
                                        }
                                        let_res_3023 = letpair_res_3024;
                                      }
                                      choose_res_2812 = let_res_3023;
                                    }
                                    choose_res_2807 = choose_res_2812;
                                  }
                                  choose_res_2750 = choose_res_2807;
                                }
                                choose_res_2738 = choose_res_2750;
                              }
                              choose_res_2733 = choose_res_2738;
                            }
                            choose_res_2711 = choose_res_2733;
                          }
                          choose_res_2704 = choose_res_2711;
                        }
                        choose_res_2639 = choose_res_2704;
                      }
                      choose_res_2567 = choose_res_2639;
                    }
                    choose_res_2252 = choose_res_2567;
                  }
                  choose_res_2247 = choose_res_2252;
                }
                choose_res_2191 = choose_res_2247;
              }
              choose_res_2140 = choose_res_2191;
            }
            choose_res_2135 = choose_res_2140;
          }
          choose_res_2130 = choose_res_2135;
        }
        letpair_res_2127 = choose_res_2130;
      }
      let_res_2126 = letpair_res_2127;
    }
    ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 letpair_res_3169;
    {
      auto make_fst_660 { std::get<0>(let_res_2126) };
      auto make_snd_661 { std::get<1>(let_res_2126) };
      ::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4 id_3170 { make_fst_660, make_snd_661 };
      letpair_res_3169 = id_3170;
    }
    return letpair_res_3169;
  }
   };
  return fun2122;
}
std::function<::dessser::gen::sync_key::t2448b9260b09dfe70925659af56825d4(Pointer)> of_row_binary(of_row_binary_init());

typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
