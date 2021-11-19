#ifndef DESSSER_GEN_sync_key
#define DESSSER_GEN_sync_key
#include <arpa/inet.h>
#include <functional>
#include <memory>
#include <optional>
#include <tuple>
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

/* ------------ */
/* Declarations */
/* ------------ */
struct per_dash_key : public std::variant<
  uint32_t // Widgets
> { using variant::variant; };

enum Constr_per_dash_key {
  Widgets,
};

inline std::ostream &operator<<(std::ostream &os, per_dash_key const &v) {
  switch (v.index()) {
    case 0: os << "Widgets " << std::get<0>(v); break;
  }
  return os;
}

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
  std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  // Scratchpad
> { using variant::variant; };

enum Constr_per_client {
  Response,
  Scratchpad,
};

inline std::ostream &operator<<(std::ostream &os, per_client const &v) {
  switch (v.index()) {
    case 0: os << "Response " << std::get<0>(v); break;
    case 1: os << "Scratchpad " << std::get<1>(v); break;
  }
  return os;
}

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

enum Constr_per_tail {
  Subscriber,
  LastTuple,
};

inline std::ostream &operator<<(std::ostream &os, per_tail const &v) {
  switch (v.index()) {
    case 0: os << "Subscriber " << std::get<0>(v); break;
    case 1: os << "LastTuple " << std::get<1>(v); break;
  }
  return os;
}

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
inline std::ostream &operator<<(std::ostream &os, t3f2a416abcbd7d33d681d9d47445767b const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t32def300158106bfcc2bfd2015d1a3a9 : public std::variant<
  Void, // Host
  Void // Port
> { using variant::variant; };

enum Constr_t32def300158106bfcc2bfd2015d1a3a9 {
  Host,
  Port,
};

inline std::ostream &operator<<(std::ostream &os, t32def300158106bfcc2bfd2015d1a3a9 const &v) {
  switch (v.index()) {
    case 0: os << "Host " << std::get<0>(v); break;
    case 1: os << "Port " << std::get<1>(v); break;
  }
  return os;
}

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
inline std::ostream &operator<<(std::ostream &os, t917a1ec3837bac9e10c931466c2b1db6 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
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

enum Constr_t082c1c733e68c2b9334f218f8c5aeccb {
  StateFile,
  InputRingFile,
  Pid,
  LastKilled,
  LastExit,
  LastExitStatus,
  SuccessiveFailures,
  QuarantineUntil,
};

inline std::ostream &operator<<(std::ostream &os, t082c1c733e68c2b9334f218f8c5aeccb const &v) {
  switch (v.index()) {
    case 0: os << "StateFile " << std::get<0>(v); break;
    case 1: os << "InputRingFile " << std::get<1>(v); break;
    case 2: os << "Pid " << std::get<2>(v); break;
    case 3: os << "LastKilled " << std::get<3>(v); break;
    case 4: os << "LastExit " << std::get<4>(v); break;
    case 5: os << "LastExitStatus " << std::get<5>(v); break;
    case 6: os << "SuccessiveFailures " << std::get<6>(v); break;
    case 7: os << "QuarantineUntil " << std::get<7>(v); break;
  }
  return os;
}

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
inline std::ostream &operator<<(std::ostream &os, t87de6a51e16e395e537230ef32d18a96 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
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

enum Constr_t4f653cc5cecafb6924f3d52da0caa392 {
  RuntimeStats,
  ArchivedTimes,
  NumArcFiles,
  NumArcBytes,
  AllocedArcBytes,
  Worker,
  PerInstance,
  PerReplayer,
  OutputSpecs,
};

inline std::ostream &operator<<(std::ostream &os, t4f653cc5cecafb6924f3d52da0caa392 const &v) {
  switch (v.index()) {
    case 0: os << "RuntimeStats " << std::get<0>(v); break;
    case 1: os << "ArchivedTimes " << std::get<1>(v); break;
    case 2: os << "NumArcFiles " << std::get<2>(v); break;
    case 3: os << "NumArcBytes " << std::get<3>(v); break;
    case 4: os << "AllocedArcBytes " << std::get<4>(v); break;
    case 5: os << "Worker " << std::get<5>(v); break;
    case 6: os << "PerInstance " << std::get<6>(v); break;
    case 7: os << "PerReplayer " << std::get<7>(v); break;
    case 8: os << "OutputSpecs " << std::get<8>(v); break;
  }
  return os;
}

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
inline std::ostream &operator<<(std::ostream &os, tb2139bc0252a099cc9e179b592108d12 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t73ec97d1f82a1880f5d2693e3a0558b1 : public std::variant<
  Void // Executable
> { using variant::variant; };

enum Constr_t73ec97d1f82a1880f5d2693e3a0558b1 {
  Executable,
};

inline std::ostream &operator<<(std::ostream &os, t73ec97d1f82a1880f5d2693e3a0558b1 const &v) {
  switch (v.index()) {
    case 0: os << "Executable " << std::get<0>(v); break;
  }
  return os;
}

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
inline std::ostream &operator<<(std::ostream &os, t1a2ea3d90b4ec20b73da76f490de4625 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t9030dc10bd527c50c2f835375dc4eb9d : public std::variant<
  Void, // IsMaster
  ::dessser::gen::sync_key::t917a1ec3837bac9e10c931466c2b1db6, // PerService
  ::dessser::gen::sync_key::tb2139bc0252a099cc9e179b592108d12, // PerWorker
  ::dessser::gen::sync_key::t1a2ea3d90b4ec20b73da76f490de4625 // PerProgram
> { using variant::variant; };

enum Constr_t9030dc10bd527c50c2f835375dc4eb9d {
  IsMaster,
  PerService,
  PerWorker,
  PerProgram,
};

inline std::ostream &operator<<(std::ostream &os, t9030dc10bd527c50c2f835375dc4eb9d const &v) {
  switch (v.index()) {
    case 0: os << "IsMaster " << std::get<0>(v); break;
    case 1: os << "PerService " << std::get<1>(v); break;
    case 2: os << "PerWorker " << std::get<2>(v); break;
    case 3: os << "PerProgram " << std::get<3>(v); break;
  }
  return os;
}

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
inline std::ostream &operator<<(std::ostream &os, t64d8d40f333c531e9d48c05b8ceb4cfa const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t1fb80ba5a0eef0b970838ab3e8e6bce4 : public std::variant<
  Void, // TotalSize
  Void, // RecallCost
  std::string // RetentionsOverride
> { using variant::variant; };

enum Constr_t1fb80ba5a0eef0b970838ab3e8e6bce4 {
  TotalSize,
  RecallCost,
  RetentionsOverride,
};

inline std::ostream &operator<<(std::ostream &os, t1fb80ba5a0eef0b970838ab3e8e6bce4 const &v) {
  switch (v.index()) {
    case 0: os << "TotalSize " << std::get<0>(v); break;
    case 1: os << "RecallCost " << std::get<1>(v); break;
    case 2: os << "RetentionsOverride " << std::get<2>(v); break;
  }
  return os;
}

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
struct te552b116666bdac4ad5a96694c71efca : public std::tuple<
  dessser::gen::site_name::t_ext,
  dessser::gen::fq_name::t_ext,
  std::string,
  std::shared_ptr<::dessser::gen::sync_key::per_tail> 
> {
  using tuple::tuple;
};
inline bool operator==(te552b116666bdac4ad5a96694c71efca const &a, te552b116666bdac4ad5a96694c71efca const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && ::dessser::gen::fq_name::Deref(std::get<1>(a)) == ::dessser::gen::fq_name::Deref(std::get<1>(b)) && std::get<2>(a) == std::get<2>(b) && std::get<3>(a) == std::get<3>(b);
}
inline bool operator!=(te552b116666bdac4ad5a96694c71efca const &a, te552b116666bdac4ad5a96694c71efca const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te552b116666bdac4ad5a96694c71efca const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct t4ce2d4679665698c8b564907b52837ef : public std::tuple<
  dessser::gen::sync_socket::t_ext,
  std::shared_ptr<::dessser::gen::sync_key::per_client> 
> {
  using tuple::tuple;
  t4ce2d4679665698c8b564907b52837ef(std::tuple<dessser::gen::sync_socket::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_client> > p)
    : std::tuple<dessser::gen::sync_socket::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_client> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4ce2d4679665698c8b564907b52837ef const &a, t4ce2d4679665698c8b564907b52837ef const &b) {
  return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4ce2d4679665698c8b564907b52837ef const &a, t4ce2d4679665698c8b564907b52837ef const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4ce2d4679665698c8b564907b52837ef const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct t86de2f73c647a4a64e778895c97184da : public std::tuple<
  std::string,
  std::shared_ptr<per_dash_key> 
> {
  using tuple::tuple;
  t86de2f73c647a4a64e778895c97184da(std::tuple<std::string, std::shared_ptr<per_dash_key> > p)
    : std::tuple<std::string, std::shared_ptr<per_dash_key> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t86de2f73c647a4a64e778895c97184da const &a, t86de2f73c647a4a64e778895c97184da const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t86de2f73c647a4a64e778895c97184da const &a, t86de2f73c647a4a64e778895c97184da const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t86de2f73c647a4a64e778895c97184da const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << *std::get<1>(t)
     << '>';
  return os;
}

struct t8bc7bba8a815a55f85ed48e95de5ac1f : public std::variant<
  std::string, // Contacts
  std::string // Inhibition
> { using variant::variant; };

enum Constr_t8bc7bba8a815a55f85ed48e95de5ac1f {
  Contacts,
  Inhibition,
};

inline std::ostream &operator<<(std::ostream &os, t8bc7bba8a815a55f85ed48e95de5ac1f const &v) {
  switch (v.index()) {
    case 0: os << "Contacts " << std::get<0>(v); break;
    case 1: os << "Inhibition " << std::get<1>(v); break;
  }
  return os;
}

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
struct t2ca7e384e93254d786048eef2705adff : public std::tuple<
  dessser::gen::team_name::t_ext,
  ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f
> {
  using tuple::tuple;
  t2ca7e384e93254d786048eef2705adff(std::tuple<dessser::gen::team_name::t_ext, ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f> p)
    : std::tuple<dessser::gen::team_name::t_ext, ::dessser::gen::sync_key::t8bc7bba8a815a55f85ed48e95de5ac1f>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t2ca7e384e93254d786048eef2705adff const &a, t2ca7e384e93254d786048eef2705adff const &b) {
  return ::dessser::gen::team_name::Deref(std::get<0>(a)) == ::dessser::gen::team_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t2ca7e384e93254d786048eef2705adff const &a, t2ca7e384e93254d786048eef2705adff const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t2ca7e384e93254d786048eef2705adff const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
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

enum Constr_t7cca840d7e40b13b976d995ba9f9fd5b {
  NumDeliveryAttempts,
  FirstDeliveryAttempt,
  LastDeliveryAttempt,
  NextScheduled,
  NextSend,
  DeliveryStatus,
  Ack,
};

inline std::ostream &operator<<(std::ostream &os, t7cca840d7e40b13b976d995ba9f9fd5b const &v) {
  switch (v.index()) {
    case 0: os << "NumDeliveryAttempts " << std::get<0>(v); break;
    case 1: os << "FirstDeliveryAttempt " << std::get<1>(v); break;
    case 2: os << "LastDeliveryAttempt " << std::get<2>(v); break;
    case 3: os << "NextScheduled " << std::get<3>(v); break;
    case 4: os << "NextSend " << std::get<4>(v); break;
    case 5: os << "DeliveryStatus " << std::get<5>(v); break;
    case 6: os << "Ack " << std::get<6>(v); break;
  }
  return os;
}

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
inline std::ostream &operator<<(std::ostream &os, t5f10ae89970b1e8c27fc9f8df94fd836 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
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
inline std::ostream &operator<<(std::ostream &os, t5f29f78957e3b1e9ec4688f50d1b6080 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
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

enum Constr_t0c4a58933d47075f04ed70f827130a86 {
  FirstStartNotif,
  LastStartNotif,
  LastStopNotif,
  LastStateChangeNotif,
  Team,
  Dialogs,
  Journal,
};

inline std::ostream &operator<<(std::ostream &os, t0c4a58933d47075f04ed70f827130a86 const &v) {
  switch (v.index()) {
    case 0: os << "FirstStartNotif " << std::get<0>(v); break;
    case 1: os << "LastStartNotif " << std::get<1>(v); break;
    case 2: os << "LastStopNotif " << std::get<2>(v); break;
    case 3: os << "LastStateChangeNotif " << std::get<3>(v); break;
    case 4: os << "Team " << std::get<4>(v); break;
    case 5: os << "Dialogs " << std::get<5>(v); break;
    case 6: os << "Journal " << std::get<6>(v); break;
  }
  return os;
}

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
inline std::ostream &operator<<(std::ostream &os, t9ec4790c9e9e464ee01331cfcf67af68 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

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
  ::dessser::gen::sync_key::t86de2f73c647a4a64e778895c97184da, // Dashboards
  Void, // Notifications
  ::dessser::gen::sync_key::t2ca7e384e93254d786048eef2705adff, // Teams
  ::dessser::gen::sync_key::t9ec4790c9e9e464ee01331cfcf67af68 // Incidents
> { using variant::variant; };

enum Constr_t {
  DevNull,
  Time,
  Versions,
  Sources,
  TargetConfig,
  PerSite,
  Storage,
  Tails,
  Replays,
  Error,
  ReplayRequests,
  PerClient,
  Dashboards,
  Notifications,
  Teams,
  Incidents,
};

inline std::ostream &operator<<(std::ostream &os, t const &v) {
  switch (v.index()) {
    case 0: os << "DevNull " << std::get<0>(v); break;
    case 1: os << "Time " << std::get<1>(v); break;
    case 2: os << "Versions " << std::get<2>(v); break;
    case 3: os << "Sources " << std::get<3>(v); break;
    case 4: os << "TargetConfig " << std::get<4>(v); break;
    case 5: os << "PerSite " << std::get<5>(v); break;
    case 6: os << "Storage " << std::get<6>(v); break;
    case 7: os << "Tails " << std::get<7>(v); break;
    case 8: os << "Replays " << std::get<8>(v); break;
    case 9: if (std::get<9>(v)) os << "Error " << ::dessser::gen::sync_socket::Deref(std::get<9>(v).value()); break;
    case 10: os << "ReplayRequests " << std::get<10>(v); break;
    case 11: os << "PerClient " << std::get<11>(v); break;
    case 12: os << "Dashboards " << std::get<12>(v); break;
    case 13: os << "Notifications " << std::get<13>(v); break;
    case 14: os << "Teams " << std::get<14>(v); break;
    case 15: os << "Incidents " << std::get<15>(v); break;
  }
  return os;
}

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
struct t35aec9ecfaa6df3f20c35d464145bd4c : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,
  Pointer
> {
  using tuple::tuple;
  t35aec9ecfaa6df3f20c35d464145bd4c(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_dash_key> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_dash_key> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t35aec9ecfaa6df3f20c35d464145bd4c const &a, t35aec9ecfaa6df3f20c35d464145bd4c const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t35aec9ecfaa6df3f20c35d464145bd4c const &a, t35aec9ecfaa6df3f20c35d464145bd4c const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t35aec9ecfaa6df3f20c35d464145bd4c const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t046563c971c0fcc6bcd022e88904aea9 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_client> ,
  Pointer
> {
  using tuple::tuple;
  t046563c971c0fcc6bcd022e88904aea9(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_client> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_client> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t046563c971c0fcc6bcd022e88904aea9 const &a, t046563c971c0fcc6bcd022e88904aea9 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t046563c971c0fcc6bcd022e88904aea9 const &a, t046563c971c0fcc6bcd022e88904aea9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t046563c971c0fcc6bcd022e88904aea9 const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct t4521c7ac16d3ba391c05353ff307ec6d : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_tail> ,
  Pointer
> {
  using tuple::tuple;
  t4521c7ac16d3ba391c05353ff307ec6d(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_tail> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_tail> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4521c7ac16d3ba391c05353ff307ec6d const &a, t4521c7ac16d3ba391c05353ff307ec6d const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4521c7ac16d3ba391c05353ff307ec6d const &a, t4521c7ac16d3ba391c05353ff307ec6d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4521c7ac16d3ba391c05353ff307ec6d const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
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
inline bool operator==(t88648ce03c3e83f4daca25557f77454f const &a, t88648ce03c3e83f4daca25557f77454f const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t88648ce03c3e83f4daca25557f77454f const &a, t88648ce03c3e83f4daca25557f77454f const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t88648ce03c3e83f4daca25557f77454f const &t) {
  os << '<'
     << *std::get<0>(t) << ", "
     << std::get<1>(t)
     << '>';
  return os;
}

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> per_dash_key_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> per_client_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> per_tail_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> per_dash_key_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> per_client_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> per_tail_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_key::t35aec9ecfaa6df3f20c35d464145bd4c(Pointer)> per_dash_key_of_row_binary;
extern std::function<::dessser::gen::sync_key::t046563c971c0fcc6bcd022e88904aea9(Pointer)> per_client_of_row_binary;
extern std::function<::dessser::gen::sync_key::t4521c7ac16d3ba391c05353ff307ec6d(Pointer)> per_tail_of_row_binary;
extern std::function<::dessser::gen::sync_key::t88648ce03c3e83f4daca25557f77454f(Pointer)> of_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t>  r) { os << *r; return os; }

}
#endif
