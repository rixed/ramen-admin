#ifndef DESSSER_GEN_sync_key
#define DESSSER_GEN_sync_key
#include <arpa/inet.h>
#include <functional>
#include <optional>
#include <tuple>
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

/* ------------ */
/* Declarations */
/* ------------ */
struct per_dash_key : public std::variant<
  uint32_t // Widgets
> { using variant::variant; };

enum Constr_per_dash_key {
  Widgets,
};

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
inline std::ostream &operator<<(std::ostream &os, per_dash_key const &v) {
  switch (v.index()) {
    case 0: os << "Widgets " << std::get<0>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::src_path::t_ext,
  std::string
> t274013922fc0b2cd45c289bf2ba4463d;

struct t32def300158106bfcc2bfd2015d1a3a9 : public std::variant<
  Void, // Host
  Void // Port
> { using variant::variant; };

enum Constr_t32def300158106bfcc2bfd2015d1a3a9 {
  Host,
  Port,
};

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
inline std::ostream &operator<<(std::ostream &os, t32def300158106bfcc2bfd2015d1a3a9 const &v) {
  switch (v.index()) {
    case 0: os << "Host " << std::get<0>(v); break;
    case 1: os << "Port " << std::get<1>(v); break;
  }
  return os;
}

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

enum Constr_t794aebb012043f26d004aebd5966b350 {
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

inline bool operator==(t794aebb012043f26d004aebd5966b350 const &a, t794aebb012043f26d004aebd5966b350 const &b) {
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
inline bool operator!=(t794aebb012043f26d004aebd5966b350 const &a, t794aebb012043f26d004aebd5966b350 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t794aebb012043f26d004aebd5966b350 const &v) {
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

typedef std::tuple<
  dessser::gen::fq_name::t_ext,
  ::dessser::gen::sync_key::t794aebb012043f26d004aebd5966b350
> t4ead4b84ceaa6e65cf560142db29b99b;

struct t73ec97d1f82a1880f5d2693e3a0558b1 : public std::variant<
  Void // Executable
> { using variant::variant; };

enum Constr_t73ec97d1f82a1880f5d2693e3a0558b1 {
  Executable,
};

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
inline std::ostream &operator<<(std::ostream &os, t73ec97d1f82a1880f5d2693e3a0558b1 const &v) {
  switch (v.index()) {
    case 0: os << "Executable " << std::get<0>(v); break;
  }
  return os;
}

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

enum Constr_td886436745a4631e1e780c597e2e1fe9 {
  IsMaster,
  PerService,
  PerWorker,
  PerProgram,
};

inline bool operator==(td886436745a4631e1e780c597e2e1fe9 const &a, td886436745a4631e1e780c597e2e1fe9 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // IsMaster
    case 1: return std::get<1>(a) == std::get<1>(b); // PerService
    case 2: return std::get<2>(a) == std::get<2>(b); // PerWorker
    case 3: return std::get<3>(a) == std::get<3>(b); // PerProgram
  };
  return false;
}
inline bool operator!=(td886436745a4631e1e780c597e2e1fe9 const &a, td886436745a4631e1e780c597e2e1fe9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, td886436745a4631e1e780c597e2e1fe9 const &v) {
  switch (v.index()) {
    case 0: os << "IsMaster " << std::get<0>(v); break;
    case 1: os << "PerService " << std::get<1>(v); break;
    case 2: os << "PerWorker " << std::get<2>(v); break;
    case 3: os << "PerProgram " << std::get<3>(v); break;
  }
  return os;
}

typedef std::tuple<
  dessser::gen::site_name::t_ext,
  ::dessser::gen::sync_key::td886436745a4631e1e780c597e2e1fe9
> td1b9e7ba6416a29dd2501cb424913fb2;

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
inline std::ostream &operator<<(std::ostream &os, t1fb80ba5a0eef0b970838ab3e8e6bce4 const &v) {
  switch (v.index()) {
    case 0: os << "TotalSize " << std::get<0>(v); break;
    case 1: os << "RecallCost " << std::get<1>(v); break;
    case 2: os << "RetentionsOverride " << std::get<2>(v); break;
  }
  return os;
}

struct tc93e19385f89f334cffc47ceb4a894b8 : public std::variant<
  std::string, // Subscriber
  uint32_t // LastTuple
> { using variant::variant; };

enum Constr_tc93e19385f89f334cffc47ceb4a894b8 {
  Subscriber,
  LastTuple,
};

inline bool operator==(tc93e19385f89f334cffc47ceb4a894b8 const &a, tc93e19385f89f334cffc47ceb4a894b8 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Subscriber
    case 1: return std::get<1>(a) == std::get<1>(b); // LastTuple
  };
  return false;
}
inline bool operator!=(tc93e19385f89f334cffc47ceb4a894b8 const &a, tc93e19385f89f334cffc47ceb4a894b8 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc93e19385f89f334cffc47ceb4a894b8 const &v) {
  switch (v.index()) {
    case 0: os << "Subscriber " << std::get<0>(v); break;
    case 1: os << "LastTuple " << std::get<1>(v); break;
  }
  return os;
}

struct t9d781e6e3c7478a3c57f805b8c82ba57 : public std::tuple<
  dessser::gen::site_name::t_ext,
  dessser::gen::fq_name::t_ext,
  std::string,
  ::dessser::gen::sync_key::tc93e19385f89f334cffc47ceb4a894b8
> { using tuple::tuple; };
inline bool operator==(t9d781e6e3c7478a3c57f805b8c82ba57 const &a, t9d781e6e3c7478a3c57f805b8c82ba57 const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && ::dessser::gen::fq_name::Deref(std::get<1>(a)) == ::dessser::gen::fq_name::Deref(std::get<1>(b)) && std::get<2>(a) == std::get<2>(b) && std::get<3>(a) == std::get<3>(b);
}
inline bool operator!=(t9d781e6e3c7478a3c57f805b8c82ba57 const &a, t9d781e6e3c7478a3c57f805b8c82ba57 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t9d781e6e3c7478a3c57f805b8c82ba57 const &t) {
  os << '<'
     << std::get<0>(t) << ", "
     << std::get<1>(t) << ", "
     << std::get<2>(t) << ", "
     << std::get<3>(t)
     << '>';
  return os;
}

struct t34440d69278f78fc117a9719151dac05 : public std::variant<
  std::string, // Response
  ::dessser::gen::sync_key::per_dash_key* // Scratchpad
> { using variant::variant; };

enum Constr_t34440d69278f78fc117a9719151dac05 {
  Response,
  Scratchpad,
};

inline bool operator==(t34440d69278f78fc117a9719151dac05 const &a, t34440d69278f78fc117a9719151dac05 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Response
    case 1: return std::get<1>(a) == std::get<1>(b); // Scratchpad
  };
  return false;
}
inline bool operator!=(t34440d69278f78fc117a9719151dac05 const &a, t34440d69278f78fc117a9719151dac05 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t34440d69278f78fc117a9719151dac05 const &v) {
  switch (v.index()) {
    case 0: os << "Response " << std::get<0>(v); break;
    case 1: os << "Scratchpad " << std::get<1>(v); break;
  }
  return os;
}

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

enum Constr_t8bc7bba8a815a55f85ed48e95de5ac1f {
  Contacts,
  Inhibition,
};

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
inline std::ostream &operator<<(std::ostream &os, t8bc7bba8a815a55f85ed48e95de5ac1f const &v) {
  switch (v.index()) {
    case 0: os << "Contacts " << std::get<0>(v); break;
    case 1: os << "Inhibition " << std::get<1>(v); break;
  }
  return os;
}

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

enum Constr_t7cca840d7e40b13b976d995ba9f9fd5b {
  NumDeliveryAttempts,
  FirstDeliveryAttempt,
  LastDeliveryAttempt,
  NextScheduled,
  NextSend,
  DeliveryStatus,
  Ack,
};

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

enum Constr_t14a5e3eba11a1198d8e17aba65f08825 {
  FirstStartNotif,
  LastStartNotif,
  LastStopNotif,
  LastStateChangeNotif,
  Team,
  Dialogs,
  Journal,
};

inline bool operator==(t14a5e3eba11a1198d8e17aba65f08825 const &a, t14a5e3eba11a1198d8e17aba65f08825 const &b) {
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
inline bool operator!=(t14a5e3eba11a1198d8e17aba65f08825 const &a, t14a5e3eba11a1198d8e17aba65f08825 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t14a5e3eba11a1198d8e17aba65f08825 const &v) {
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

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
typedef std::tuple<
  ::dessser::gen::sync_key::per_dash_key*,
  Pointer
> t74d8a287d0a13dbe7e14118a085f0fb9;

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

/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(::dessser::gen::sync_key::per_dash_key*,Pointer)> per_dash_key_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::t*,Pointer)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_key::per_dash_key*)> per_dash_key_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::t*)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_key::t74d8a287d0a13dbe7e14118a085f0fb9(Pointer)> per_dash_key_of_row_binary;
extern std::function<::dessser::gen::sync_key::t3161399693367e6234a99fd179dbbb5d(Pointer)> of_row_binary;
typedef t *t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
