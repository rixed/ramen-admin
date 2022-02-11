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

struct t0e35f6d3419a3939b7cd57375b12fe4d : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::dialog_key
> {
  using tuple::tuple;
};
inline bool operator==(t0e35f6d3419a3939b7cd57375b12fe4d const &a, t0e35f6d3419a3939b7cd57375b12fe4d const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0e35f6d3419a3939b7cd57375b12fe4d const &a, t0e35f6d3419a3939b7cd57375b12fe4d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t0e35f6d3419a3939b7cd57375b12fe4d const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0e35f6d3419a3939b7cd57375b12fe4d> const t) { os << *t; return os; }

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
  ::dessser::gen::sync_key::t0e35f6d3419a3939b7cd57375b12fe4d, // Dialogs
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

struct team_key_info : public std::variant<
  std::string, // Contacts
  std::string // Inhibition
> {
  using variant::variant;
  using variant::operator=;
  static constexpr size_t size { 2 };
};

inline bool operator==(team_key_info const &a, team_key_info const &b) {
  if (a.index() != b.index()) return false;
  switch (a.index()) {
    case 0: return std::get<0>(a) == std::get<0>(b); // Contacts
    case 1: return std::get<1>(a) == std::get<1>(b); // Inhibition
  };
  return false;
}
inline bool operator!=(team_key_info const &a, team_key_info const &b) {
  return !operator==(a, b);
}
enum Constr_team_key_info {
  Contacts,
  Inhibition,
};

inline std::ostream &operator<<(std::ostream &os, team_key_info const &v) {
  switch (v.index()) {
    case 0: os << "Contacts " << std::get<0>(v); break;
    case 1: os << "Inhibition " << std::get<1>(v); break;
  }
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<team_key_info> const v) { os << *v; return os; }

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
  ::dessser::gen::sync_key::per_worker_data
> {
  using tuple::tuple;
};
inline bool operator==(per_worker const &a, per_worker const &b) {
  return ::dessser::gen::fq_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
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
  ::dessser::gen::sync_key::per_worker, // PerWorker
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
    case 2: return std::get<2>(a) == std::get<2>(b); // PerWorker
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
  ::dessser::gen::sync_key::per_site_data
> {
  using tuple::tuple;
};
inline bool operator==(per_site const &a, per_site const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
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

struct t97f8631e87fc5cd910c2a601533983ee : public std::tuple<
  dessser::gen::site_name::t_ext,
  dessser::gen::fq_name::t_ext,
  std::string,
  ::dessser::gen::sync_key::per_tail
> {
  using tuple::tuple;
};
inline bool operator==(t97f8631e87fc5cd910c2a601533983ee const &a, t97f8631e87fc5cd910c2a601533983ee const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && ::dessser::gen::fq_name::Deref(std::get<1>(a)) == ::dessser::gen::fq_name::Deref(std::get<1>(b)) && std::get<2>(a) == std::get<2>(b) && std::get<3>(a) == std::get<3>(b);
}
inline bool operator!=(t97f8631e87fc5cd910c2a601533983ee const &a, t97f8631e87fc5cd910c2a601533983ee const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t97f8631e87fc5cd910c2a601533983ee const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t) << ", ";
  os << std::get<2>(t) << ", ";
  os << std::get<3>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t97f8631e87fc5cd910c2a601533983ee> const t) { os << *t; return os; }

struct t32db4748152e7073f1f93bdcc3c5bff5 : public std::tuple<
  dessser::gen::sync_socket::t_ext,
  ::dessser::gen::sync_key::per_client
> {
  using tuple::tuple;
};
inline bool operator==(t32db4748152e7073f1f93bdcc3c5bff5 const &a, t32db4748152e7073f1f93bdcc3c5bff5 const &b) {
  return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t32db4748152e7073f1f93bdcc3c5bff5 const &a, t32db4748152e7073f1f93bdcc3c5bff5 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t32db4748152e7073f1f93bdcc3c5bff5 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t32db4748152e7073f1f93bdcc3c5bff5> const t) { os << *t; return os; }

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

struct t387175c465c261e0af17af4010188b4e {
  dessser::gen::team_name::t_ext name;
  ::dessser::gen::sync_key::team_key_info info;
  t387175c465c261e0af17af4010188b4e(dessser::gen::team_name::t_ext name_, ::dessser::gen::sync_key::team_key_info info_) : name(name_), info(info_) {}
  t387175c465c261e0af17af4010188b4e() = default;
};
inline bool operator==(t387175c465c261e0af17af4010188b4e const &a, t387175c465c261e0af17af4010188b4e const &b) {
  return ::dessser::gen::team_name::Deref(a.name) == ::dessser::gen::team_name::Deref(b.name) && a.info == b.info;
}

inline bool operator!=(t387175c465c261e0af17af4010188b4e const &a, t387175c465c261e0af17af4010188b4e const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t387175c465c261e0af17af4010188b4e const &r) {
  os << '{';
  os << "name:" << r.name << ',';
  os << "info:" << r.info;
  os << '}';
  return os;
}
inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t387175c465c261e0af17af4010188b4e> const r) { os << *r; return os; }

struct t891de542b31fe57e6f8226ed37c952be : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::incident_key
> {
  using tuple::tuple;
};
inline bool operator==(t891de542b31fe57e6f8226ed37c952be const &a, t891de542b31fe57e6f8226ed37c952be const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t891de542b31fe57e6f8226ed37c952be const &a, t891de542b31fe57e6f8226ed37c952be const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t891de542b31fe57e6f8226ed37c952be const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t891de542b31fe57e6f8226ed37c952be> const t) { os << *t; return os; }

struct t : public std::variant<
  Void, // DevNull
  Void, // Time
  std::string, // Versions
  ::dessser::gen::sync_key::t86252e3890668e56d73574e8b879a5b1, // Sources
  Void, // TargetConfig
  ::dessser::gen::sync_key::per_site, // PerSite
  ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c, // Storage
  ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee, // Tails
  uint16_t, // Replays
  std::optional<dessser::gen::sync_socket::t_ext>, // Error
  Void, // ReplayRequests
  ::dessser::gen::sync_key::t32db4748152e7073f1f93bdcc3c5bff5, // PerClient
  ::dessser::gen::sync_key::ta05201a250c67cd2df71e6345b0a4f16, // Dashboards
  Void, // Notifications
  ::dessser::gen::sync_key::t387175c465c261e0af17af4010188b4e, // Teams
  ::dessser::gen::sync_key::t891de542b31fe57e6f8226ed37c952be // Incidents
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
struct t0f2a9fd478dd335e4b2f4a474357fd25 : public std::tuple<
  ::dessser::gen::sync_key::dialog_key,
  Pointer
> {
  using tuple::tuple;
  t0f2a9fd478dd335e4b2f4a474357fd25(std::tuple<::dessser::gen::sync_key::dialog_key, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::dialog_key, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t0f2a9fd478dd335e4b2f4a474357fd25 const &a, t0f2a9fd478dd335e4b2f4a474357fd25 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t0f2a9fd478dd335e4b2f4a474357fd25 const &a, t0f2a9fd478dd335e4b2f4a474357fd25 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t0f2a9fd478dd335e4b2f4a474357fd25 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t0f2a9fd478dd335e4b2f4a474357fd25> const t) { os << *t; return os; }

struct t1042a3f128208d457ce5fad4bbb3c2d4 : public std::tuple<
  ::dessser::gen::sync_key::incident_key,
  Pointer
> {
  using tuple::tuple;
  t1042a3f128208d457ce5fad4bbb3c2d4(std::tuple<::dessser::gen::sync_key::incident_key, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::incident_key, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1042a3f128208d457ce5fad4bbb3c2d4 const &a, t1042a3f128208d457ce5fad4bbb3c2d4 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1042a3f128208d457ce5fad4bbb3c2d4 const &a, t1042a3f128208d457ce5fad4bbb3c2d4 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t1042a3f128208d457ce5fad4bbb3c2d4 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t1042a3f128208d457ce5fad4bbb3c2d4> const t) { os << *t; return os; }

struct tea08d4d857ea1e66be959e9b3d6681ce : public std::tuple<
  ::dessser::gen::sync_key::team_key_info,
  Pointer
> {
  using tuple::tuple;
  tea08d4d857ea1e66be959e9b3d6681ce(std::tuple<::dessser::gen::sync_key::team_key_info, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::team_key_info, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tea08d4d857ea1e66be959e9b3d6681ce const &a, tea08d4d857ea1e66be959e9b3d6681ce const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tea08d4d857ea1e66be959e9b3d6681ce const &a, tea08d4d857ea1e66be959e9b3d6681ce const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, tea08d4d857ea1e66be959e9b3d6681ce const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<tea08d4d857ea1e66be959e9b3d6681ce> const t) { os << *t; return os; }

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

struct t33cdb4c52644761a7d0096ff5546d783 : public std::tuple<
  ::dessser::gen::sync_key::per_client,
  Pointer
> {
  using tuple::tuple;
  t33cdb4c52644761a7d0096ff5546d783(std::tuple<::dessser::gen::sync_key::per_client, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::per_client, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t33cdb4c52644761a7d0096ff5546d783 const &a, t33cdb4c52644761a7d0096ff5546d783 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t33cdb4c52644761a7d0096ff5546d783 const &a, t33cdb4c52644761a7d0096ff5546d783 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t33cdb4c52644761a7d0096ff5546d783 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t33cdb4c52644761a7d0096ff5546d783> const t) { os << *t; return os; }

struct t1427b384ffff2d22da761632559548f9 : public std::tuple<
  ::dessser::gen::sync_key::per_tail,
  Pointer
> {
  using tuple::tuple;
  t1427b384ffff2d22da761632559548f9(std::tuple<::dessser::gen::sync_key::per_tail, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::per_tail, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1427b384ffff2d22da761632559548f9 const &a, t1427b384ffff2d22da761632559548f9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1427b384ffff2d22da761632559548f9 const &a, t1427b384ffff2d22da761632559548f9 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t1427b384ffff2d22da761632559548f9 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t1427b384ffff2d22da761632559548f9> const t) { os << *t; return os; }

struct t5c90cea3f3a08b18ff7f2236b4f968fc : public std::tuple<
  ::dessser::gen::sync_key::per_worker_data,
  Pointer
> {
  using tuple::tuple;
  t5c90cea3f3a08b18ff7f2236b4f968fc(std::tuple<::dessser::gen::sync_key::per_worker_data, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::per_worker_data, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5c90cea3f3a08b18ff7f2236b4f968fc const &a, t5c90cea3f3a08b18ff7f2236b4f968fc const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5c90cea3f3a08b18ff7f2236b4f968fc const &a, t5c90cea3f3a08b18ff7f2236b4f968fc const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t5c90cea3f3a08b18ff7f2236b4f968fc const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t5c90cea3f3a08b18ff7f2236b4f968fc> const t) { os << *t; return os; }

struct t1f40308c4d529d3aab5f7f6d77e7f092 : public std::tuple<
  ::dessser::gen::sync_key::per_worker,
  Pointer
> {
  using tuple::tuple;
  t1f40308c4d529d3aab5f7f6d77e7f092(std::tuple<::dessser::gen::sync_key::per_worker, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::per_worker, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1f40308c4d529d3aab5f7f6d77e7f092 const &a, t1f40308c4d529d3aab5f7f6d77e7f092 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1f40308c4d529d3aab5f7f6d77e7f092 const &a, t1f40308c4d529d3aab5f7f6d77e7f092 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t1f40308c4d529d3aab5f7f6d77e7f092 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t1f40308c4d529d3aab5f7f6d77e7f092> const t) { os << *t; return os; }

struct te4133d682331ecfabfc7bd76e1489530 : public std::tuple<
  ::dessser::gen::sync_key::per_site_data,
  Pointer
> {
  using tuple::tuple;
  te4133d682331ecfabfc7bd76e1489530(std::tuple<::dessser::gen::sync_key::per_site_data, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::per_site_data, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(te4133d682331ecfabfc7bd76e1489530 const &a, te4133d682331ecfabfc7bd76e1489530 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(te4133d682331ecfabfc7bd76e1489530 const &a, te4133d682331ecfabfc7bd76e1489530 const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, te4133d682331ecfabfc7bd76e1489530 const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<te4133d682331ecfabfc7bd76e1489530> const t) { os << *t; return os; }

struct t46884d5a883114c46d32db813b52f29d : public std::tuple<
  ::dessser::gen::sync_key::per_site,
  Pointer
> {
  using tuple::tuple;
  t46884d5a883114c46d32db813b52f29d(std::tuple<::dessser::gen::sync_key::per_site, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::per_site, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t46884d5a883114c46d32db813b52f29d const &a, t46884d5a883114c46d32db813b52f29d const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t46884d5a883114c46d32db813b52f29d const &a, t46884d5a883114c46d32db813b52f29d const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t46884d5a883114c46d32db813b52f29d const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t46884d5a883114c46d32db813b52f29d> const t) { os << *t; return os; }

struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct per_dash_key> const);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct t34ebba618a0ff1a9bcb6711a6bde703a : public std::tuple<
  ::dessser::gen::sync_key::t,
  Pointer
> {
  using tuple::tuple;
  t34ebba618a0ff1a9bcb6711a6bde703a(std::tuple<::dessser::gen::sync_key::t, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t34ebba618a0ff1a9bcb6711a6bde703a const &a, t34ebba618a0ff1a9bcb6711a6bde703a const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t34ebba618a0ff1a9bcb6711a6bde703a const &a, t34ebba618a0ff1a9bcb6711a6bde703a const &b) {
  return !operator==(a, b);
}
inline std::ostream &operator<<(std::ostream &os, t34ebba618a0ff1a9bcb6711a6bde703a const &t) {
  os << '<';
  os << std::get<0>(t) << ", ";
  os << std::get<1>(t);
  os << '>';
  return os;
}

inline std::ostream &operator<<(std::ostream &os, std::shared_ptr<t34ebba618a0ff1a9bcb6711a6bde703a> const t) { os << *t; return os; }

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
extern std::function<Pointer(::dessser::gen::sync_key::dialog_key const &,Pointer &)> dialog_key_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::incident_key const &,Pointer &)> incident_key_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::team_key_info const &,Pointer &)> team_key_info_to_row_binary;
extern std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  const &,Pointer &)> per_dash_key_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::per_client const &,Pointer &)> per_client_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::per_tail const &,Pointer &)> per_tail_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::per_worker_data const &,Pointer &)> per_worker_data_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::per_worker &,Pointer &)> per_worker_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::per_site_data &,Pointer &)> per_site_data_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::per_site &,Pointer &)> per_site_to_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::t &,Pointer &)> to_row_binary;
extern std::function<Size(::dessser::gen::sync_key::dialog_key const &)> dialog_key_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::incident_key const &)> incident_key_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::team_key_info const &)> team_key_info_sersize_of_row_binary;
extern std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  const &)> per_dash_key_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::per_client const &)> per_client_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::per_tail const &)> per_tail_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::per_worker_data const &)> per_worker_data_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::per_worker &)> per_worker_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::per_site_data &)> per_site_data_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::per_site &)> per_site_sersize_of_row_binary;
extern std::function<Size(::dessser::gen::sync_key::t &)> sersize_of_row_binary;
extern std::function<::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25(Pointer &)> dialog_key_of_row_binary;
extern std::function<::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4(Pointer &)> incident_key_of_row_binary;
extern std::function<::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce(Pointer &)> team_key_info_of_row_binary;
extern std::function<::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713(Pointer &)> per_dash_key_of_row_binary;
extern std::function<::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783(Pointer &)> per_client_of_row_binary;
extern std::function<::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9(Pointer &)> per_tail_of_row_binary;
extern std::function<::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc(Pointer &)> per_worker_data_of_row_binary;
extern std::function<::dessser::gen::sync_key::t1f40308c4d529d3aab5f7f6d77e7f092(Pointer &)> per_worker_of_row_binary;
extern std::function<::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530(Pointer &)> per_site_data_of_row_binary;
extern std::function<::dessser::gen::sync_key::t46884d5a883114c46d32db813b52f29d(Pointer &)> per_site_of_row_binary;
extern std::function<::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a(Pointer &)> of_row_binary;
extern std::function<::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a(Pointer &)> wrap_of_row_binary;
extern std::function<Pointer(::dessser::gen::sync_key::t &,Pointer &)> wrap_to_row_binary;
typedef t t_ext;
inline t Deref(t_ext x) { return x; }

}
#endif
