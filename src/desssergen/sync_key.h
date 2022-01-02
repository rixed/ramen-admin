#ifndef DESSSER_GEN_sync_key
#define DESSSER_GEN_sync_key
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
struct dialog_key : public std::variant<
  Void, // NumDeliveryAttempts
  Void, // FirstDeliveryAttempt
  Void, // LastDeliveryAttempt
  Void, // NextScheduled
  Void, // NextSend
  Void, // DeliveryStatus
  Void // Ack
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 7 };
};

inline bool operator==(dialog_key const &a, dialog_key const &b) {
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
inline bool operator!=(dialog_key const &a, dialog_key const &b) {
  return !operator==(a, b);
}
enum Constr_dialog_key {
  NumDeliveryAttempts,
  FirstDeliveryAttempt,
  LastDeliveryAttempt,
  NextScheduled,
  NextSend,
  DeliveryStatus,
  Ack,
};

inline std::ostream &operator<<(std::ostream &os, dialog_key const &v) {
  switch (v.index()) {
    case 0: os << "NumDeliveryAttempts" << std::get<0>(v); break;
    case 1: os << "FirstDeliveryAttempt" << std::get<1>(v); break;
    case 2: os << "LastDeliveryAttempt" << std::get<2>(v); break;
    case 3: os << "NextScheduled" << std::get<3>(v); break;
    case 4: os << "NextSend" << std::get<4>(v); break;
    case 5: os << "DeliveryStatus" << std::get<5>(v); break;
    case 6: os << "Ack" << std::get<6>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<dialog_key> const v) { os << *v; return os; }

struct t3740d66cd009e943de2733cb4d9a7b53 : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::sync_key::dialog_key> 
> {
  using tuple::tuple;
};
inline bool operator==(t3740d66cd009e943de2733cb4d9a7b53 const &a, t3740d66cd009e943de2733cb4d9a7b53 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t3740d66cd009e943de2733cb4d9a7b53 const &a, t3740d66cd009e943de2733cb4d9a7b53 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t3740d66cd009e943de2733cb4d9a7b53 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t3740d66cd009e943de2733cb4d9a7b53> const t) { os << *t; return os; }

struct t9782147647347738b31cd77850bfc224 : public std::tuple<
  double,
  uint32_t
> {
  using tuple::tuple;
};
inline bool operator==(t9782147647347738b31cd77850bfc224 const &a, t9782147647347738b31cd77850bfc224 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9782147647347738b31cd77850bfc224 const &a, t9782147647347738b31cd77850bfc224 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t9782147647347738b31cd77850bfc224 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t9782147647347738b31cd77850bfc224> const t) { os << *t; return os; }

struct incident_key : public std::variant<
  Void, // FirstStartNotif
  Void, // LastStartNotif
  Void, // LastStopNotif
  Void, // LastStateChangeNotif
  Void, // Team
  ::dessser::gen::sync_key::t3740d66cd009e943de2733cb4d9a7b53, // Dialogs
  ::dessser::gen::sync_key::t9782147647347738b31cd77850bfc224 // Journal
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 7 };
};

inline bool operator==(incident_key const &a, incident_key const &b) {
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
inline bool operator!=(incident_key const &a, incident_key const &b) {
  return !operator==(a, b);
}
enum Constr_incident_key {
  FirstStartNotif,
  LastStartNotif,
  LastStopNotif,
  LastStateChangeNotif,
  Team,
  Dialogs,
  Journal,
};

inline std::ostream &operator<<(std::ostream &os, incident_key const &v) {
  switch (v.index()) {
    case 0: os << "FirstStartNotif" << std::get<0>(v); break;
    case 1: os << "LastStartNotif" << std::get<1>(v); break;
    case 2: os << "LastStopNotif" << std::get<2>(v); break;
    case 3: os << "LastStateChangeNotif" << std::get<3>(v); break;
    case 4: os << "Team" << std::get<4>(v); break;
    case 5: os << "Dialogs " << std::get<5>(v); break;
    case 6: os << "Journal " << std::get<6>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<incident_key> const v) { os << *v; return os; }

struct per_dash_key : public std::variant<
  uint32_t // Widgets
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 1 };
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
enum Constr_per_dash_key {
  Widgets,
};

inline std::ostream &operator<<(std::ostream &os, per_dash_key const &v) {
  switch (v.index()) {
    case 0: os << "Widgets " << std::get<0>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<per_dash_key> const v) { os << *v; return os; }

struct per_client : public std::variant<
  std::string, // Response
  std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  // Scratchpad
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(per_client const &a, per_client const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Response
    case 1: return (*std::get<1>(a)) == (*std::get<1>(b)); // Scratchpad
  };
  return false;
}
inline bool operator!=(per_client const &a, per_client const &b) {
  return !operator==(a, b);
}
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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<per_client> const v) { os << *v; return os; }

struct per_tail : public std::variant<
  std::string, // Subscriber
  uint32_t // LastTuple
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

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

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<per_tail> const v) { os << *v; return os; }

struct t62147b4d97ca22ce48402f8d7a47b9c0 : public std::variant<
  Void, // StateFile
  Void, // InputRingFile
  Void, // Pid
  Void, // LastKilled
  Void, // LastExit
  Void, // LastExitStatus
  Void, // SuccessiveFailures
  Void // QuarantineUntil
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 8 };
};

inline bool operator==(t62147b4d97ca22ce48402f8d7a47b9c0 const &a, t62147b4d97ca22ce48402f8d7a47b9c0 const &b) {
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
inline bool operator!=(t62147b4d97ca22ce48402f8d7a47b9c0 const &a, t62147b4d97ca22ce48402f8d7a47b9c0 const &b) {
  return !operator==(a, b);
}
enum Constr_t62147b4d97ca22ce48402f8d7a47b9c0 {
  StateFile,
  InputRingFile,
  Pid,
  LastKilled,
  LastExit,
  LastExitStatus,
  SuccessiveFailures,
  QuarantineUntil,
};

inline std::ostream &operator<<(std::ostream &os, t62147b4d97ca22ce48402f8d7a47b9c0 const &v) {
  switch (v.index()) {
    case 0: os << "StateFile" << std::get<0>(v); break;
    case 1: os << "InputRingFile" << std::get<1>(v); break;
    case 2: os << "Pid" << std::get<2>(v); break;
    case 3: os << "LastKilled" << std::get<3>(v); break;
    case 4: os << "LastExit" << std::get<4>(v); break;
    case 5: os << "LastExitStatus" << std::get<5>(v); break;
    case 6: os << "SuccessiveFailures" << std::get<6>(v); break;
    case 7: os << "QuarantineUntil" << std::get<7>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t62147b4d97ca22ce48402f8d7a47b9c0> const v) { os << *v; return os; }

struct ta7e4a6f84fc41fdc68e99605bbb0a0c8 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0
> {
  using tuple::tuple;
};
inline bool operator==(ta7e4a6f84fc41fdc68e99605bbb0a0c8 const &a, ta7e4a6f84fc41fdc68e99605bbb0a0c8 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta7e4a6f84fc41fdc68e99605bbb0a0c8 const &a, ta7e4a6f84fc41fdc68e99605bbb0a0c8 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ta7e4a6f84fc41fdc68e99605bbb0a0c8 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta7e4a6f84fc41fdc68e99605bbb0a0c8> const t) { os << *t; return os; }

struct per_worker_data : public std::variant<
  Void, // RuntimeStats
  Void, // ArchivedTimes
  Void, // NumArcFiles
  Void, // NumArcBytes
  Void, // AllocedArcBytes
  Void, // Worker
  ::dessser::gen::sync_key::ta7e4a6f84fc41fdc68e99605bbb0a0c8, // PerInstance
  uint32_t, // PerReplayer
  Void // OutputSpecs
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 9 };
};

inline bool operator==(per_worker_data const &a, per_worker_data const &b) {
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
inline bool operator!=(per_worker_data const &a, per_worker_data const &b) {
  return !operator==(a, b);
}
enum Constr_per_worker_data {
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

inline std::ostream &operator<<(std::ostream &os, per_worker_data const &v) {
  switch (v.index()) {
    case 0: os << "RuntimeStats" << std::get<0>(v); break;
    case 1: os << "ArchivedTimes" << std::get<1>(v); break;
    case 2: os << "NumArcFiles" << std::get<2>(v); break;
    case 3: os << "NumArcBytes" << std::get<3>(v); break;
    case 4: os << "AllocedArcBytes" << std::get<4>(v); break;
    case 5: os << "Worker" << std::get<5>(v); break;
    case 6: os << "PerInstance " << std::get<6>(v); break;
    case 7: os << "PerReplayer " << std::get<7>(v); break;
    case 8: os << "OutputSpecs" << std::get<8>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<per_worker_data> const v) { os << *v; return os; }

struct per_worker : public std::tuple<
  dessser::gen::fq_name::t_ext,
  std::shared_ptr<::dessser::gen::sync_key::per_worker_data> 
> {
  using tuple::tuple;
};
inline bool operator==(per_worker const &a, per_worker const &b) {
  return ::dessser::gen::fq_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_name::Deref(std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(per_worker const &a, per_worker const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, per_worker const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<per_worker> const t) { os << *t; return os; }

struct tcc9598dfd3f6ae835fa2904058bd9af9 : public std::variant<
  Void, // Host
  Void // Port
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(tcc9598dfd3f6ae835fa2904058bd9af9 const &a, tcc9598dfd3f6ae835fa2904058bd9af9 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Host
    case 1: return std::get<1>(a) == std::get<1>(b); // Port
  };
  return false;
}
inline bool operator!=(tcc9598dfd3f6ae835fa2904058bd9af9 const &a, tcc9598dfd3f6ae835fa2904058bd9af9 const &b) {
  return !operator==(a, b);
}
enum Constr_tcc9598dfd3f6ae835fa2904058bd9af9 {
  Host,
  Port,
};

inline std::ostream &operator<<(std::ostream &os, tcc9598dfd3f6ae835fa2904058bd9af9 const &v) {
  switch (v.index()) {
    case 0: os << "Host" << std::get<0>(v); break;
    case 1: os << "Port" << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tcc9598dfd3f6ae835fa2904058bd9af9> const v) { os << *v; return os; }

struct t8b473b477d9037c968f39934f3815b98 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9
> {
  using tuple::tuple;
};
inline bool operator==(t8b473b477d9037c968f39934f3815b98 const &a, t8b473b477d9037c968f39934f3815b98 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8b473b477d9037c968f39934f3815b98 const &a, t8b473b477d9037c968f39934f3815b98 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t8b473b477d9037c968f39934f3815b98 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t8b473b477d9037c968f39934f3815b98> const t) { os << *t; return os; }

struct t64d562ea504a9ce27a59b90c4e554a51 : public std::variant<
  Void // Executable
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 1 };
};

inline bool operator==(t64d562ea504a9ce27a59b90c4e554a51 const &a, t64d562ea504a9ce27a59b90c4e554a51 const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Executable
  };
  return false;
}
inline bool operator!=(t64d562ea504a9ce27a59b90c4e554a51 const &a, t64d562ea504a9ce27a59b90c4e554a51 const &b) {
  return !operator==(a, b);
}
enum Constr_t64d562ea504a9ce27a59b90c4e554a51 {
  Executable,
};

inline std::ostream &operator<<(std::ostream &os, t64d562ea504a9ce27a59b90c4e554a51 const &v) {
  switch (v.index()) {
    case 0: os << "Executable" << std::get<0>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t64d562ea504a9ce27a59b90c4e554a51> const v) { os << *v; return os; }

struct t85827d1984b82a47867ad2208bc45f28 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51
> {
  using tuple::tuple;
};
inline bool operator==(t85827d1984b82a47867ad2208bc45f28 const &a, t85827d1984b82a47867ad2208bc45f28 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t85827d1984b82a47867ad2208bc45f28 const &a, t85827d1984b82a47867ad2208bc45f28 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t85827d1984b82a47867ad2208bc45f28 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t85827d1984b82a47867ad2208bc45f28> const t) { os << *t; return os; }

struct per_site_data : public std::variant<
  Void, // IsMaster
  ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98, // PerService
  std::shared_ptr<::dessser::gen::sync_key::per_worker> , // PerWorker
  ::dessser::gen::sync_key::t85827d1984b82a47867ad2208bc45f28 // PerProgram
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 4 };
};

inline bool operator==(per_site_data const &a, per_site_data const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // IsMaster
    case 1: return std::get<1>(a) == std::get<1>(b); // PerService
    case 2: return (*std::get<2>(a)) == (*std::get<2>(b)); // PerWorker
    case 3: return std::get<3>(a) == std::get<3>(b); // PerProgram
  };
  return false;
}
inline bool operator!=(per_site_data const &a, per_site_data const &b) {
  return !operator==(a, b);
}
enum Constr_per_site_data {
  IsMaster,
  PerService,
  PerWorker,
  PerProgram,
};

inline std::ostream &operator<<(std::ostream &os, per_site_data const &v) {
  switch (v.index()) {
    case 0: os << "IsMaster" << std::get<0>(v); break;
    case 1: os << "PerService " << std::get<1>(v); break;
    case 2: os << "PerWorker " << std::get<2>(v); break;
    case 3: os << "PerProgram " << std::get<3>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<per_site_data> const v) { os << *v; return os; }

struct per_site : public std::tuple<
  dessser::gen::site_name::t_ext,
  std::shared_ptr<::dessser::gen::sync_key::per_site_data> 
> {
  using tuple::tuple;
};
inline bool operator==(per_site const &a, per_site const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(per_site const &a, per_site const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, per_site const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<per_site> const t) { os << *t; return os; }

struct t86252e3890668e56d73574e8b879a5b1 : public std::tuple<
  dessser::gen::src_path::t_ext,
  std::string
> {
  using tuple::tuple;
};
inline bool operator==(t86252e3890668e56d73574e8b879a5b1 const &a, t86252e3890668e56d73574e8b879a5b1 const &b) {
  return ::dessser::gen::src_path::Deref(std::get<0>(a)) == ::dessser::gen::src_path::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t86252e3890668e56d73574e8b879a5b1 const &a, t86252e3890668e56d73574e8b879a5b1 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t86252e3890668e56d73574e8b879a5b1 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t86252e3890668e56d73574e8b879a5b1> const t) { os << *t; return os; }

struct te22159e1728beb1685bbd47c6325049c : public std::variant<
  Void, // TotalSize
  Void, // RecallCost
  std::string // RetentionsOverride
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 3 };
};

inline bool operator==(te22159e1728beb1685bbd47c6325049c const &a, te22159e1728beb1685bbd47c6325049c const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // TotalSize
    case 1: return std::get<1>(a) == std::get<1>(b); // RecallCost
    case 2: return std::get<2>(a) == std::get<2>(b); // RetentionsOverride
  };
  return false;
}
inline bool operator!=(te22159e1728beb1685bbd47c6325049c const &a, te22159e1728beb1685bbd47c6325049c const &b) {
  return !operator==(a, b);
}
enum Constr_te22159e1728beb1685bbd47c6325049c {
  TotalSize,
  RecallCost,
  RetentionsOverride,
};

inline std::ostream &operator<<(std::ostream &os, te22159e1728beb1685bbd47c6325049c const &v) {
  switch (v.index()) {
    case 0: os << "TotalSize" << std::get<0>(v); break;
    case 1: os << "RecallCost" << std::get<1>(v); break;
    case 2: os << "RetentionsOverride " << std::get<2>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te22159e1728beb1685bbd47c6325049c> const v) { os << *v; return os; }

struct t2ffe933a548dbd220caa19cc4eccbdbc : public std::tuple<
  dessser::gen::site_name::t_ext,
  dessser::gen::fq_name::t_ext,
  std::string,
  std::shared_ptr<::dessser::gen::sync_key::per_tail> 
> {
  using tuple::tuple;
};
inline bool operator==(t2ffe933a548dbd220caa19cc4eccbdbc const &a, t2ffe933a548dbd220caa19cc4eccbdbc const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && ::dessser::gen::fq_name::Deref(std::get<1>(a)) == ::dessser::gen::fq_name::Deref(std::get<1>(b)) && std::get<2>(a) == std::get<2>(b) && (*std::get<3>(a)) == (*std::get<3>(b));
}
inline bool operator!=(t2ffe933a548dbd220caa19cc4eccbdbc const &a, t2ffe933a548dbd220caa19cc4eccbdbc const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t2ffe933a548dbd220caa19cc4eccbdbc const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t2ffe933a548dbd220caa19cc4eccbdbc> const t) { os << *t; return os; }

struct tad3d72cbcbac129b71b1e72a57567c05 : public std::tuple<
  dessser::gen::sync_socket::t_ext,
  std::shared_ptr<::dessser::gen::sync_key::per_client> 
> {
  using tuple::tuple;
};
inline bool operator==(tad3d72cbcbac129b71b1e72a57567c05 const &a, tad3d72cbcbac129b71b1e72a57567c05 const &b) {
  return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(tad3d72cbcbac129b71b1e72a57567c05 const &a, tad3d72cbcbac129b71b1e72a57567c05 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tad3d72cbcbac129b71b1e72a57567c05 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tad3d72cbcbac129b71b1e72a57567c05> const t) { os << *t; return os; }

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct per_dash_key> const);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct ta05201a250c67cd2df71e6345b0a4f16 : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::sync_key::per_dash_key> 
> {
  using tuple::tuple;
};
inline bool operator==(ta05201a250c67cd2df71e6345b0a4f16 const &a, ta05201a250c67cd2df71e6345b0a4f16 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(ta05201a250c67cd2df71e6345b0a4f16 const &a, ta05201a250c67cd2df71e6345b0a4f16 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, ta05201a250c67cd2df71e6345b0a4f16 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<ta05201a250c67cd2df71e6345b0a4f16> const t) { os << *t; return os; }

struct t7c3b4d666d784c1e1d7f41f4fe6019cb : public std::variant<
  std::string, // Contacts
  std::string // Inhibition
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(t7c3b4d666d784c1e1d7f41f4fe6019cb const &a, t7c3b4d666d784c1e1d7f41f4fe6019cb const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Contacts
    case 1: return std::get<1>(a) == std::get<1>(b); // Inhibition
  };
  return false;
}
inline bool operator!=(t7c3b4d666d784c1e1d7f41f4fe6019cb const &a, t7c3b4d666d784c1e1d7f41f4fe6019cb const &b) {
  return !operator==(a, b);
}
enum Constr_t7c3b4d666d784c1e1d7f41f4fe6019cb {
  Contacts,
  Inhibition,
};

inline std::ostream &operator<<(std::ostream &os, t7c3b4d666d784c1e1d7f41f4fe6019cb const &v) {
  switch (v.index()) {
    case 0: os << "Contacts " << std::get<0>(v); break;
    case 1: os << "Inhibition " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t7c3b4d666d784c1e1d7f41f4fe6019cb> const v) { os << *v; return os; }

struct t1fe305ebed4021f1552512f2753ee099 : public std::tuple<
  dessser::gen::team_name::t_ext,
  ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb
> {
  using tuple::tuple;
};
inline bool operator==(t1fe305ebed4021f1552512f2753ee099 const &a, t1fe305ebed4021f1552512f2753ee099 const &b) {
  return ::dessser::gen::team_name::Deref(std::get<0>(a)) == ::dessser::gen::team_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1fe305ebed4021f1552512f2753ee099 const &a, t1fe305ebed4021f1552512f2753ee099 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t1fe305ebed4021f1552512f2753ee099 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t1fe305ebed4021f1552512f2753ee099> const t) { os << *t; return os; }

struct t401820a4624980e1b48c1031a82f4554 : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::sync_key::incident_key> 
> {
  using tuple::tuple;
};
inline bool operator==(t401820a4624980e1b48c1031a82f4554 const &a, t401820a4624980e1b48c1031a82f4554 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t401820a4624980e1b48c1031a82f4554 const &a, t401820a4624980e1b48c1031a82f4554 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t401820a4624980e1b48c1031a82f4554 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t401820a4624980e1b48c1031a82f4554> const t) { os << *t; return os; }

struct t : public std::variant<
  Void, // DevNull
  Void, // Time
  std::string, // Versions
  ::dessser::gen::sync_key::t86252e3890668e56d73574e8b879a5b1, // Sources
  Void, // TargetConfig
  std::shared_ptr<::dessser::gen::sync_key::per_site> , // PerSite
  ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c, // Storage
  ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc, // Tails
  uint16_t, // Replays
  std::optional<dessser::gen::sync_socket::t_ext>, // Error
  Void, // ReplayRequests
  ::dessser::gen::sync_key::tad3d72cbcbac129b71b1e72a57567c05, // PerClient
  ::dessser::gen::sync_key::ta05201a250c67cd2df71e6345b0a4f16, // Dashboards
  Void, // Notifications
  ::dessser::gen::sync_key::t1fe305ebed4021f1552512f2753ee099, // Teams
  ::dessser::gen::sync_key::t401820a4624980e1b48c1031a82f4554 // Incidents
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 16 };
};

inline bool operator==(t const &a, t const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // DevNull
    case 1: return std::get<1>(a) == std::get<1>(b); // Time
    case 2: return std::get<2>(a) == std::get<2>(b); // Versions
    case 3: return std::get<3>(a) == std::get<3>(b); // Sources
    case 4: return std::get<4>(a) == std::get<4>(b); // TargetConfig
    case 5: return (*std::get<5>(a)) == (*std::get<5>(b)); // PerSite
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
    case 0: os << "DevNull" << std::get<0>(v); break;
    case 1: os << "Time" << std::get<1>(v); break;
    case 2: os << "Versions " << std::get<2>(v); break;
    case 3: os << "Sources " << std::get<3>(v); break;
    case 4: os << "TargetConfig" << std::get<4>(v); break;
    case 5: os << "PerSite " << std::get<5>(v); break;
    case 6: os << "Storage " << std::get<6>(v); break;
    case 7: os << "Tails " << std::get<7>(v); break;
    case 8: os << "Replays " << std::get<8>(v); break;
    case 9: if (std::get<9>(v)) os << "Error " << std::get<9>(v).value(); break;
    case 10: os << "ReplayRequests" << std::get<10>(v); break;
    case 11: os << "PerClient " << std::get<11>(v); break;
    case 12: os << "Dashboards " << std::get<12>(v); break;
    case 13: os << "Notifications" << std::get<13>(v); break;
    case 14: os << "Teams " << std::get<14>(v); break;
    case 15: os << "Incidents " << std::get<15>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t> const v) { os << *v; return os; }

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct per_dash_key> const);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct t4585ac1860331d8d8108dff115815fc1 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::dialog_key> ,
  Pointer
> {
  using tuple::tuple;
  t4585ac1860331d8d8108dff115815fc1(std::tuple<std::shared_ptr<::dessser::gen::sync_key::dialog_key> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::dialog_key> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4585ac1860331d8d8108dff115815fc1 const &a, t4585ac1860331d8d8108dff115815fc1 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4585ac1860331d8d8108dff115815fc1 const &a, t4585ac1860331d8d8108dff115815fc1 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4585ac1860331d8d8108dff115815fc1 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t4585ac1860331d8d8108dff115815fc1> const t) { os << *t; return os; }

struct t81a0c931c4f6d47a526068c7b84a436d : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::incident_key> ,
  Pointer
> {
  using tuple::tuple;
  t81a0c931c4f6d47a526068c7b84a436d(std::tuple<std::shared_ptr<::dessser::gen::sync_key::incident_key> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::incident_key> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t81a0c931c4f6d47a526068c7b84a436d const &a, t81a0c931c4f6d47a526068c7b84a436d const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t81a0c931c4f6d47a526068c7b84a436d const &a, t81a0c931c4f6d47a526068c7b84a436d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t81a0c931c4f6d47a526068c7b84a436d const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t81a0c931c4f6d47a526068c7b84a436d> const t) { os << *t; return os; }

struct tddfcfedf3e7ada7bc193bdea642cf713 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,
  Pointer
> {
  using tuple::tuple;
  tddfcfedf3e7ada7bc193bdea642cf713(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_dash_key> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_dash_key> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tddfcfedf3e7ada7bc193bdea642cf713 const &a, tddfcfedf3e7ada7bc193bdea642cf713 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tddfcfedf3e7ada7bc193bdea642cf713 const &a, tddfcfedf3e7ada7bc193bdea642cf713 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tddfcfedf3e7ada7bc193bdea642cf713 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tddfcfedf3e7ada7bc193bdea642cf713> const t) { os << *t; return os; }

struct t56898a81c1f17af3902c13e6570a4796 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_client> ,
  Pointer
> {
  using tuple::tuple;
  t56898a81c1f17af3902c13e6570a4796(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_client> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_client> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t56898a81c1f17af3902c13e6570a4796 const &a, t56898a81c1f17af3902c13e6570a4796 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t56898a81c1f17af3902c13e6570a4796 const &a, t56898a81c1f17af3902c13e6570a4796 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t56898a81c1f17af3902c13e6570a4796 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t56898a81c1f17af3902c13e6570a4796> const t) { os << *t; return os; }

struct t4033af6a94e2f1d0f849f8e9c28f066e : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_tail> ,
  Pointer
> {
  using tuple::tuple;
  t4033af6a94e2f1d0f849f8e9c28f066e(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_tail> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_tail> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4033af6a94e2f1d0f849f8e9c28f066e const &a, t4033af6a94e2f1d0f849f8e9c28f066e const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4033af6a94e2f1d0f849f8e9c28f066e const &a, t4033af6a94e2f1d0f849f8e9c28f066e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t4033af6a94e2f1d0f849f8e9c28f066e const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t4033af6a94e2f1d0f849f8e9c28f066e> const t) { os << *t; return os; }

struct t86357804013591d564a14dcb7d208049 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,
  Pointer
> {
  using tuple::tuple;
  t86357804013591d564a14dcb7d208049(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_worker_data> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_worker_data> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t86357804013591d564a14dcb7d208049 const &a, t86357804013591d564a14dcb7d208049 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t86357804013591d564a14dcb7d208049 const &a, t86357804013591d564a14dcb7d208049 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t86357804013591d564a14dcb7d208049 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t86357804013591d564a14dcb7d208049> const t) { os << *t; return os; }

struct t230dd37e292f8ada6da847a9bd177ec5 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_worker> ,
  Pointer
> {
  using tuple::tuple;
  t230dd37e292f8ada6da847a9bd177ec5(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_worker> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_worker> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t230dd37e292f8ada6da847a9bd177ec5 const &a, t230dd37e292f8ada6da847a9bd177ec5 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t230dd37e292f8ada6da847a9bd177ec5 const &a, t230dd37e292f8ada6da847a9bd177ec5 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t230dd37e292f8ada6da847a9bd177ec5 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t230dd37e292f8ada6da847a9bd177ec5> const t) { os << *t; return os; }

struct tc0947ce7e9d20fe4fd59f16145aef5ab : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,
  Pointer
> {
  using tuple::tuple;
  tc0947ce7e9d20fe4fd59f16145aef5ab(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_site_data> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_site_data> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc0947ce7e9d20fe4fd59f16145aef5ab const &a, tc0947ce7e9d20fe4fd59f16145aef5ab const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc0947ce7e9d20fe4fd59f16145aef5ab const &a, tc0947ce7e9d20fe4fd59f16145aef5ab const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tc0947ce7e9d20fe4fd59f16145aef5ab const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tc0947ce7e9d20fe4fd59f16145aef5ab> const t) { os << *t; return os; }

struct tf1d5e8699e2fb10ae586f67c483db581 : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::per_site> ,
  Pointer
> {
  using tuple::tuple;
  tf1d5e8699e2fb10ae586f67c483db581(std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_site> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::per_site> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tf1d5e8699e2fb10ae586f67c483db581 const &a, tf1d5e8699e2fb10ae586f67c483db581 const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tf1d5e8699e2fb10ae586f67c483db581 const &a, tf1d5e8699e2fb10ae586f67c483db581 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tf1d5e8699e2fb10ae586f67c483db581 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tf1d5e8699e2fb10ae586f67c483db581> const t) { os << *t; return os; }

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct per_dash_key> const);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct tcf9b51a7545aa8b67d24c1f5f504ceaf : public std::tuple<
  std::shared_ptr<::dessser::gen::sync_key::t> ,
  Pointer
> {
  using tuple::tuple;
  tcf9b51a7545aa8b67d24c1f5f504ceaf(std::tuple<std::shared_ptr<::dessser::gen::sync_key::t> , Pointer> p)
    : std::tuple<std::shared_ptr<::dessser::gen::sync_key::t> , Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tcf9b51a7545aa8b67d24c1f5f504ceaf const &a, tcf9b51a7545aa8b67d24c1f5f504ceaf const &b) {
  return (*std::get<0>(a)) == (*std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tcf9b51a7545aa8b67d24c1f5f504ceaf const &a, tcf9b51a7545aa8b67d24c1f5f504ceaf const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tcf9b51a7545aa8b67d24c1f5f504ceaf const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tcf9b51a7545aa8b67d24c1f5f504ceaf> const t) { os << *t; return os; }

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct per_dash_key> const);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct per_dash_key> const);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
/* ----------- */
/* Definitions */
/* ----------- */
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::dialog_key> ,Pointer)> dialog_key_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::incident_key> ,Pointer)> incident_key_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> per_dash_key_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> per_client_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> per_tail_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,Pointer)> per_worker_data_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker> ,Pointer)> per_worker_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,Pointer)> per_site_data_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site> ,Pointer)> per_site_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> to_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::dialog_key> )> dialog_key_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::incident_key> )> incident_key_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> per_dash_key_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> per_client_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> per_tail_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> )> per_worker_data_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker> )> per_worker_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site_data> )> per_site_data_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site> )> per_site_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1(Pointer)> dialog_key_of_row_binary;
extern std::function<::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d(Pointer)> incident_key_of_row_binary;
extern std::function<::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713(Pointer)> per_dash_key_of_row_binary;
extern std::function<::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796(Pointer)> per_client_of_row_binary;
extern std::function<::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e(Pointer)> per_tail_of_row_binary;
extern std::function<::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049(Pointer)> per_worker_data_of_row_binary;
extern std::function<::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5(Pointer)> per_worker_of_row_binary;
extern std::function<::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab(Pointer)> per_site_data_of_row_binary;
extern std::function<::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581(Pointer)> per_site_of_row_binary;
extern std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> of_row_binary;
extern std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> wrap_of_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> wrap_to_row_binary;
typedef std::shared_ptr<t> t_ext;
inline t Deref(t_ext x) { return *x; }

}
#endif
