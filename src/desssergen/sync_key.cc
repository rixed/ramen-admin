#include <algorithm>
#include <charconv>  // for from_chars
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
struct ta97bb48ed75bbda6173555873826c8c6 : public std::tuple<
  uint16_t,
  Pointer
> {
  using tuple::tuple;
  ta97bb48ed75bbda6173555873826c8c6(std::tuple<uint16_t, Pointer> p)
    : std::tuple<uint16_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(ta97bb48ed75bbda6173555873826c8c6 const &a, ta97bb48ed75bbda6173555873826c8c6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(ta97bb48ed75bbda6173555873826c8c6 const &a, ta97bb48ed75bbda6173555873826c8c6 const &b) {
  return !operator==(a, b);
}
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
struct t12fb9c475959b52bf7b17b155a955ffa : public std::tuple<
  Size,
  Pointer
> {
  using tuple::tuple;
  t12fb9c475959b52bf7b17b155a955ffa(std::tuple<Size, Pointer> p)
    : std::tuple<Size, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t12fb9c475959b52bf7b17b155a955ffa const &a, t12fb9c475959b52bf7b17b155a955ffa const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t12fb9c475959b52bf7b17b155a955ffa const &a, t12fb9c475959b52bf7b17b155a955ffa const &b) {
  return !operator==(a, b);
}
struct t1a5d74abf838df33f185a72a8912f5c9 : public std::tuple<
  uint8_t,
  Pointer
> {
  using tuple::tuple;
  t1a5d74abf838df33f185a72a8912f5c9(std::tuple<uint8_t, Pointer> p)
    : std::tuple<uint8_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1a5d74abf838df33f185a72a8912f5c9 const &a, t1a5d74abf838df33f185a72a8912f5c9 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1a5d74abf838df33f185a72a8912f5c9 const &a, t1a5d74abf838df33f185a72a8912f5c9 const &b) {
  return !operator==(a, b);
}
struct t13a07ee37ab40962540da8534858dc07 : public std::tuple<
  std::string,
  Pointer
> {
  using tuple::tuple;
  t13a07ee37ab40962540da8534858dc07(std::tuple<std::string, Pointer> p)
    : std::tuple<std::string, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t13a07ee37ab40962540da8534858dc07 const &a, t13a07ee37ab40962540da8534858dc07 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t13a07ee37ab40962540da8534858dc07 const &a, t13a07ee37ab40962540da8534858dc07 const &b) {
  return !operator==(a, b);
}
struct t9ef6882174ae71a34a3c5ef6b29242fb : public std::tuple<
  Bytes,
  Pointer
> {
  using tuple::tuple;
  t9ef6882174ae71a34a3c5ef6b29242fb(std::tuple<Bytes, Pointer> p)
    : std::tuple<Bytes, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9ef6882174ae71a34a3c5ef6b29242fb const &a, t9ef6882174ae71a34a3c5ef6b29242fb const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9ef6882174ae71a34a3c5ef6b29242fb const &a, t9ef6882174ae71a34a3c5ef6b29242fb const &b) {
  return !operator==(a, b);
}
struct td2cd337bb3c8bc04d5603393d084985b : public std::tuple<
  uint64_t,
  Pointer
> {
  using tuple::tuple;
  td2cd337bb3c8bc04d5603393d084985b(std::tuple<uint64_t, Pointer> p)
    : std::tuple<uint64_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td2cd337bb3c8bc04d5603393d084985b const &a, td2cd337bb3c8bc04d5603393d084985b const &b) {
  return !operator==(a, b);
}
struct t9a758baeff17224a77e1a522010b4168 : public std::tuple<
  double,
  Pointer
> {
  using tuple::tuple;
  t9a758baeff17224a77e1a522010b4168(std::tuple<double, Pointer> p)
    : std::tuple<double, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t9a758baeff17224a77e1a522010b4168 const &a, t9a758baeff17224a77e1a522010b4168 const &b) {
  return !operator==(a, b);
}
struct t491c44439106a32f896827242e8e76a1 : public std::tuple<
  uint32_t,
  Pointer
> {
  using tuple::tuple;
  t491c44439106a32f896827242e8e76a1(std::tuple<uint32_t, Pointer> p)
    : std::tuple<uint32_t, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t491c44439106a32f896827242e8e76a1 const &a, t491c44439106a32f896827242e8e76a1 const &b) {
  return !operator==(a, b);
}
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
struct t4cdccf3979a446cc6c30bc2b6ecc87ae : public std::tuple<
  ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0,
  Pointer
> {
  using tuple::tuple;
  t4cdccf3979a446cc6c30bc2b6ecc87ae(std::tuple<::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t4cdccf3979a446cc6c30bc2b6ecc87ae const &a, t4cdccf3979a446cc6c30bc2b6ecc87ae const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t4cdccf3979a446cc6c30bc2b6ecc87ae const &a, t4cdccf3979a446cc6c30bc2b6ecc87ae const &b) {
  return !operator==(a, b);
}
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
struct t1067cf8ed87e4e016349f71797fb0661 : public std::tuple<
  dessser::gen::fq_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t1067cf8ed87e4e016349f71797fb0661(std::tuple<dessser::gen::fq_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::fq_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t1067cf8ed87e4e016349f71797fb0661 const &a, t1067cf8ed87e4e016349f71797fb0661 const &b) {
  return ::dessser::gen::fq_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t1067cf8ed87e4e016349f71797fb0661 const &a, t1067cf8ed87e4e016349f71797fb0661 const &b) {
  return !operator==(a, b);
}
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
struct t8f0858866d1e27d5fa38c6941e6365f2 : public std::tuple<
  ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9,
  Pointer
> {
  using tuple::tuple;
  t8f0858866d1e27d5fa38c6941e6365f2(std::tuple<::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t8f0858866d1e27d5fa38c6941e6365f2 const &a, t8f0858866d1e27d5fa38c6941e6365f2 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t8f0858866d1e27d5fa38c6941e6365f2 const &a, t8f0858866d1e27d5fa38c6941e6365f2 const &b) {
  return !operator==(a, b);
}
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
struct t5fda3fa18a9129079240e343cc4c7827 : public std::tuple<
  dessser::gen::site_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  t5fda3fa18a9129079240e343cc4c7827(std::tuple<dessser::gen::site_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::site_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5fda3fa18a9129079240e343cc4c7827 const &a, t5fda3fa18a9129079240e343cc4c7827 const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5fda3fa18a9129079240e343cc4c7827 const &a, t5fda3fa18a9129079240e343cc4c7827 const &b) {
  return !operator==(a, b);
}
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
struct t6915129216bc7fcac0c82f38ea6cfec8 : public std::tuple<
  dessser::gen::src_path::t_ext,
  Pointer
> {
  using tuple::tuple;
  t6915129216bc7fcac0c82f38ea6cfec8(std::tuple<dessser::gen::src_path::t_ext, Pointer> p)
    : std::tuple<dessser::gen::src_path::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t6915129216bc7fcac0c82f38ea6cfec8 const &a, t6915129216bc7fcac0c82f38ea6cfec8 const &b) {
  return ::dessser::gen::src_path::Deref(std::get<0>(a)) == ::dessser::gen::src_path::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t6915129216bc7fcac0c82f38ea6cfec8 const &a, t6915129216bc7fcac0c82f38ea6cfec8 const &b) {
  return !operator==(a, b);
}
struct td062563cc812c1fd981608a011af2302 : public std::tuple<
  ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c,
  Pointer
> {
  using tuple::tuple;
  td062563cc812c1fd981608a011af2302(std::tuple<::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td062563cc812c1fd981608a011af2302 const &a, td062563cc812c1fd981608a011af2302 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td062563cc812c1fd981608a011af2302 const &a, td062563cc812c1fd981608a011af2302 const &b) {
  return !operator==(a, b);
}
struct t012a36c0a466eec06183a69009335fa0 : public std::tuple<
  std::optional<dessser::gen::sync_socket::t_ext>,
  Pointer
> {
  using tuple::tuple;
  t012a36c0a466eec06183a69009335fa0(std::tuple<std::optional<dessser::gen::sync_socket::t_ext>, Pointer> p)
    : std::tuple<std::optional<dessser::gen::sync_socket::t_ext>, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t012a36c0a466eec06183a69009335fa0 const &a, t012a36c0a466eec06183a69009335fa0 const &b) {
  return ((std::get<0>(a) && std::get<0>(b) && ::dessser::gen::sync_socket::Deref(std::get<0>(a).value()) == ::dessser::gen::sync_socket::Deref(std::get<0>(b).value())) || (!std::get<0>(a) && !std::get<0>(b))) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t012a36c0a466eec06183a69009335fa0 const &a, t012a36c0a466eec06183a69009335fa0 const &b) {
  return !operator==(a, b);
}
struct tc3c0b466d06f5b0f1ffeebd3dab58a35 : public std::tuple<
  dessser::gen::sync_socket::t_ext,
  Pointer
> {
  using tuple::tuple;
  tc3c0b466d06f5b0f1ffeebd3dab58a35(std::tuple<dessser::gen::sync_socket::t_ext, Pointer> p)
    : std::tuple<dessser::gen::sync_socket::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tc3c0b466d06f5b0f1ffeebd3dab58a35 const &a, tc3c0b466d06f5b0f1ffeebd3dab58a35 const &b) {
  return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(tc3c0b466d06f5b0f1ffeebd3dab58a35 const &a, tc3c0b466d06f5b0f1ffeebd3dab58a35 const &b) {
  return !operator==(a, b);
}
struct td204a4115a9974841e2d802fceb65890 : public std::tuple<
  dessser::gen::team_name::t_ext,
  Pointer
> {
  using tuple::tuple;
  td204a4115a9974841e2d802fceb65890(std::tuple<dessser::gen::team_name::t_ext, Pointer> p)
    : std::tuple<dessser::gen::team_name::t_ext, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(td204a4115a9974841e2d802fceb65890 const &a, td204a4115a9974841e2d802fceb65890 const &b) {
  return ::dessser::gen::team_name::Deref(std::get<0>(a)) == ::dessser::gen::team_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(td204a4115a9974841e2d802fceb65890 const &a, td204a4115a9974841e2d802fceb65890 const &b) {
  return !operator==(a, b);
}
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
/* 
    (fun ("[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" "Ptr")
      (let "ssum_dst_763" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_763")
          (if (eq (u16 1) (label-of (param 0))) (identifier "ssum_dst_763")
            (if (eq (u16 2) (label-of (param 0))) (identifier "ssum_dst_763")
              (if (eq (u16 3) (label-of (param 0))) (identifier "ssum_dst_763")
                (if (eq (u16 4) (label-of (param 0))) (identifier "ssum_dst_763") (if (eq (u16 5) (label-of (param 0))) (identifier "ssum_dst_763") (seq (assert (eq (label-of (param 0)) (u16 6))) (identifier "ssum_dst_763"))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::dialog_key const &,Pointer &)> dialog_key_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::dialog_key const &,Pointer &)> fun0 { [&](::dessser::gen::sync_key::dialog_key p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t(p_0.index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_763 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t(p_0.index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        choose_res_7 = ssum_dst_763;
      } else {
        uint16_t id_8 { 1 };
        uint16_t id_9 { uint16_t(p_0.index()) };
        bool id_10 { bool(id_8 == id_9) };
        Pointer choose_res_11;
        if (id_10) {
          choose_res_11 = ssum_dst_763;
        } else {
          uint16_t id_12 { 2 };
          uint16_t id_13 { uint16_t(p_0.index()) };
          bool id_14 { bool(id_12 == id_13) };
          Pointer choose_res_15;
          if (id_14) {
            choose_res_15 = ssum_dst_763;
          } else {
            uint16_t id_16 { 3 };
            uint16_t id_17 { uint16_t(p_0.index()) };
            bool id_18 { bool(id_16 == id_17) };
            Pointer choose_res_19;
            if (id_18) {
              choose_res_19 = ssum_dst_763;
            } else {
              uint16_t id_20 { 4 };
              uint16_t id_21 { uint16_t(p_0.index()) };
              bool id_22 { bool(id_20 == id_21) };
              Pointer choose_res_23;
              if (id_22) {
                choose_res_23 = ssum_dst_763;
              } else {
                uint16_t id_24 { 5 };
                uint16_t id_25 { uint16_t(p_0.index()) };
                bool id_26 { bool(id_24 == id_25) };
                Pointer choose_res_27;
                if (id_26) {
                  choose_res_27 = ssum_dst_763;
                } else {
                  uint16_t id_28 { uint16_t(p_0.index()) };
                  uint16_t id_29 { 6 };
                  bool id_30 { bool(id_28 == id_29) };
                  Void id_31 { ((void)(assert(id_30)), ::dessser::Void()) };
                  (void)id_31;
                  choose_res_27 = ssum_dst_763;
                }
                choose_res_23 = choose_res_27;
              }
              choose_res_19 = choose_res_23;
            }
            choose_res_15 = choose_res_19;
          }
          choose_res_11 = choose_res_15;
        }
        choose_res_7 = choose_res_11;
      }
      let_res_3 = choose_res_7;
    }
    return let_res_3;
  }
   };
  return fun0;
}
std::function<Pointer(::dessser::gen::sync_key::dialog_key const &,Pointer &)> dialog_key_to_row_binary(dialog_key_to_row_binary_init());

/* 
    (fun ("[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" "Ptr")
      (let "ssum_dst_765" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_765")
          (if (eq (u16 1) (label-of (param 0))) (identifier "ssum_dst_765")
            (if (eq (u16 2) (label-of (param 0))) (identifier "ssum_dst_765")
              (if (eq (u16 3) (label-of (param 0))) (identifier "ssum_dst_765")
                (if (eq (u16 4) (label-of (param 0))) (identifier "ssum_dst_765")
                  (if (eq (u16 5) (label-of (param 0)))
                    (let "stup_dst_769"
                      (write-bytes
                        (let "leb128_sz_767" (make-vec (string-length (get-item 0 (get-alt "Dialogs" (param 0)))))
                          (let "leb128_ptr_768" (make-vec (identifier "ssum_dst_765"))
                            (seq
                              (while
                                (seq
                                  (set-vec (u8 0) (identifier "leb128_ptr_768")
                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_768"))
                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_767"))) 
                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_767"))) 
                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_767"))) (u8 128)))))
                                  (set-vec (u8 0) (identifier "leb128_sz_767") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_767")) (u8 7))) 
                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_767")) (u32 0))) 
                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_768"))))) 
                        (bytes-of-string (get-item 0 (get-alt "Dialogs" (param 0))))) 
                      (apply (identifier "dialog_key-to-row-binary") (get-item 1 (get-alt "Dialogs" (param 0))) (identifier "stup_dst_769")))
                    (seq (assert (eq (label-of (param 0)) (u16 6)))
                      (let "stup_dst_766" (write-u64 little-endian (identifier "ssum_dst_765") (u64-of-float (get-item 0 (get-alt "Journal" (param 0)))))
                        (write-u32 little-endian (identifier "stup_dst_766") (get-item 1 (get-alt "Journal" (param 0))))))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::incident_key const &,Pointer &)> incident_key_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::incident_key const &,Pointer &)> fun32 { [&](::dessser::gen::sync_key::incident_key p_0, Pointer p_1) {
    uint16_t id_33 { uint16_t(p_0.index()) };
    Pointer id_34 { p_1.writeU16Le(id_33) };
    Pointer let_res_35;
    {
      Pointer ssum_dst_765 { id_34 };
      uint16_t id_36 { 0 };
      uint16_t id_37 { uint16_t(p_0.index()) };
      bool id_38 { bool(id_36 == id_37) };
      Pointer choose_res_39;
      if (id_38) {
        choose_res_39 = ssum_dst_765;
      } else {
        uint16_t id_40 { 1 };
        uint16_t id_41 { uint16_t(p_0.index()) };
        bool id_42 { bool(id_40 == id_41) };
        Pointer choose_res_43;
        if (id_42) {
          choose_res_43 = ssum_dst_765;
        } else {
          uint16_t id_44 { 2 };
          uint16_t id_45 { uint16_t(p_0.index()) };
          bool id_46 { bool(id_44 == id_45) };
          Pointer choose_res_47;
          if (id_46) {
            choose_res_47 = ssum_dst_765;
          } else {
            uint16_t id_48 { 3 };
            uint16_t id_49 { uint16_t(p_0.index()) };
            bool id_50 { bool(id_48 == id_49) };
            Pointer choose_res_51;
            if (id_50) {
              choose_res_51 = ssum_dst_765;
            } else {
              uint16_t id_52 { 4 };
              uint16_t id_53 { uint16_t(p_0.index()) };
              bool id_54 { bool(id_52 == id_53) };
              Pointer choose_res_55;
              if (id_54) {
                choose_res_55 = ssum_dst_765;
              } else {
                uint16_t id_56 { 5 };
                uint16_t id_57 { uint16_t(p_0.index()) };
                bool id_58 { bool(id_56 == id_57) };
                Pointer choose_res_59;
                if (id_58) {
                  ::dessser::gen::sync_key::t0e35f6d3419a3939b7cd57375b12fe4d id_60 { std::get<5 /* Dialogs */>(p_0) };
                  std::string id_61 { std::get<0>(id_60) };
                  uint32_t id_62 { (uint32_t)id_61.size() };
                  Vec<1, uint32_t> id_63 {  id_62  };
                  Pointer let_res_64;
                  {
                    Vec<1, uint32_t> leb128_sz_767 { id_63 };
                    Vec<1, Pointer> id_65 {  ssum_dst_765  };
                    Pointer let_res_66;
                    {
                      Vec<1, Pointer> leb128_ptr_768 { id_65 };
                      bool while_flag_67 { true };
                      do {
                        uint8_t id_68 { 0 };
                        uint8_t id_69 { 0 };
                        Pointer id_70 { leb128_ptr_768[id_69] };
                        uint32_t id_71 { 128U };
                        uint8_t id_72 { 0 };
                        uint32_t id_73 { leb128_sz_767[id_72] };
                        bool id_74 { bool(id_71 > id_73) };
                        uint8_t choose_res_75;
                        if (id_74) {
                          uint8_t id_76 { 0 };
                          uint32_t id_77 { leb128_sz_767[id_76] };
                          uint8_t id_78 { uint8_t(id_77) };
                          choose_res_75 = id_78;
                        } else {
                          uint8_t id_79 { 0 };
                          uint32_t id_80 { leb128_sz_767[id_79] };
                          uint8_t id_81 { uint8_t(id_80) };
                          uint8_t id_82 { 128 };
                          uint8_t id_83 { uint8_t(id_81 | id_82) };
                          choose_res_75 = id_83;
                        }
                        Pointer id_84 { id_70.writeU8(choose_res_75) };
                        Void id_85 { ((void)(leb128_ptr_768[id_68] = id_84), ::dessser::Void()) };
                        (void)id_85;
                        uint8_t id_86 { 0 };
                        uint8_t id_87 { 0 };
                        uint32_t id_88 { leb128_sz_767[id_87] };
                        uint8_t id_89 { 7 };
                        uint32_t id_90 { uint32_t(id_88 >> id_89) };
                        Void id_91 { ((void)(leb128_sz_767[id_86] = id_90), ::dessser::Void()) };
                        (void)id_91;
                        uint8_t id_92 { 0 };
                        uint32_t id_93 { leb128_sz_767[id_92] };
                        uint32_t id_94 { 0U };
                        bool id_95 { bool(id_93 > id_94) };
                        while_flag_67 = id_95;
                        if (while_flag_67) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_67);
                      (void)::dessser::Void();
                      uint8_t id_96 { 0 };
                      Pointer id_97 { leb128_ptr_768[id_96] };
                      let_res_66 = id_97;
                    }
                    let_res_64 = let_res_66;
                  }
                  ::dessser::gen::sync_key::t0e35f6d3419a3939b7cd57375b12fe4d id_98 { std::get<5 /* Dialogs */>(p_0) };
                  std::string id_99 { std::get<0>(id_98) };
                  Bytes id_100 { id_99 };
                  Pointer id_101 { let_res_64.writeBytes(id_100) };
                  Pointer let_res_102;
                  {
                    Pointer stup_dst_769 { id_101 };
                    ::dessser::gen::sync_key::t0e35f6d3419a3939b7cd57375b12fe4d id_103 { std::get<5 /* Dialogs */>(p_0) };
                    ::dessser::gen::sync_key::dialog_key id_104 { std::get<1>(id_103) };
                    Pointer id_105 { dialog_key_to_row_binary(id_104, stup_dst_769) };
                    let_res_102 = id_105;
                  }
                  choose_res_59 = let_res_102;
                } else {
                  uint16_t id_106 { uint16_t(p_0.index()) };
                  uint16_t id_107 { 6 };
                  bool id_108 { bool(id_106 == id_107) };
                  Void id_109 { ((void)(assert(id_108)), ::dessser::Void()) };
                  (void)id_109;
                  ::dessser::gen::sync_key::t9782147647347738b31cd77850bfc224 id_110 { std::get<6 /* Journal */>(p_0) };
                  double id_111 { std::get<0>(id_110) };
                  uint64_t id_112 { qword_of_float(id_111) };
                  Pointer id_113 { ssum_dst_765.writeU64Le(id_112) };
                  Pointer let_res_114;
                  {
                    Pointer stup_dst_766 { id_113 };
                    ::dessser::gen::sync_key::t9782147647347738b31cd77850bfc224 id_115 { std::get<6 /* Journal */>(p_0) };
                    uint32_t id_116 { std::get<1>(id_115) };
                    Pointer id_117 { stup_dst_766.writeU32Le(id_116) };
                    let_res_114 = id_117;
                  }
                  choose_res_59 = let_res_114;
                }
                choose_res_55 = choose_res_59;
              }
              choose_res_51 = choose_res_55;
            }
            choose_res_47 = choose_res_51;
          }
          choose_res_43 = choose_res_47;
        }
        choose_res_39 = choose_res_43;
      }
      let_res_35 = choose_res_39;
    }
    return let_res_35;
  }
   };
  return fun32;
}
std::function<Pointer(::dessser::gen::sync_key::incident_key const &,Pointer &)> incident_key_to_row_binary(incident_key_to_row_binary_init());

/* 
    (fun ("[Contacts STRING | Inhibition STRING]" "Ptr")
      (let "ssum_dst_757" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_760" (make-vec (string-length (get-alt "Contacts" (param 0))))
              (let "leb128_ptr_761" (make-vec (identifier "ssum_dst_757"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_761")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_761"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_760"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_760"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_760"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_760") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_760")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_760")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_761"))))) 
            (bytes-of-string (get-alt "Contacts" (param 0))))
          (seq (assert (eq (label-of (param 0)) (u16 1)))
            (write-bytes
              (let "leb128_sz_758" (make-vec (string-length (get-alt "Inhibition" (param 0))))
                (let "leb128_ptr_759" (make-vec (identifier "ssum_dst_757"))
                  (seq
                    (while
                      (seq
                        (set-vec (u8 0) (identifier "leb128_ptr_759")
                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_759"))
                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_758"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_758"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_758"))) (u8 128)))))
                        (set-vec (u8 0) (identifier "leb128_sz_758") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_758")) (u8 7))) 
                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_758")) (u32 0))) 
                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_759"))))) 
              (bytes-of-string (get-alt "Inhibition" (param 0))))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::team_key_info const &,Pointer &)> team_key_info_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::team_key_info const &,Pointer &)> fun118 { [&](::dessser::gen::sync_key::team_key_info p_0, Pointer p_1) {
    uint16_t id_119 { uint16_t(p_0.index()) };
    Pointer id_120 { p_1.writeU16Le(id_119) };
    Pointer let_res_121;
    {
      Pointer ssum_dst_757 { id_120 };
      uint16_t id_122 { 0 };
      uint16_t id_123 { uint16_t(p_0.index()) };
      bool id_124 { bool(id_122 == id_123) };
      Pointer choose_res_125;
      if (id_124) {
        std::string id_126 { std::get<0 /* Contacts */>(p_0) };
        uint32_t id_127 { (uint32_t)id_126.size() };
        Vec<1, uint32_t> id_128 {  id_127  };
        Pointer let_res_129;
        {
          Vec<1, uint32_t> leb128_sz_760 { id_128 };
          Vec<1, Pointer> id_130 {  ssum_dst_757  };
          Pointer let_res_131;
          {
            Vec<1, Pointer> leb128_ptr_761 { id_130 };
            bool while_flag_132 { true };
            do {
              uint8_t id_133 { 0 };
              uint8_t id_134 { 0 };
              Pointer id_135 { leb128_ptr_761[id_134] };
              uint32_t id_136 { 128U };
              uint8_t id_137 { 0 };
              uint32_t id_138 { leb128_sz_760[id_137] };
              bool id_139 { bool(id_136 > id_138) };
              uint8_t choose_res_140;
              if (id_139) {
                uint8_t id_141 { 0 };
                uint32_t id_142 { leb128_sz_760[id_141] };
                uint8_t id_143 { uint8_t(id_142) };
                choose_res_140 = id_143;
              } else {
                uint8_t id_144 { 0 };
                uint32_t id_145 { leb128_sz_760[id_144] };
                uint8_t id_146 { uint8_t(id_145) };
                uint8_t id_147 { 128 };
                uint8_t id_148 { uint8_t(id_146 | id_147) };
                choose_res_140 = id_148;
              }
              Pointer id_149 { id_135.writeU8(choose_res_140) };
              Void id_150 { ((void)(leb128_ptr_761[id_133] = id_149), ::dessser::Void()) };
              (void)id_150;
              uint8_t id_151 { 0 };
              uint8_t id_152 { 0 };
              uint32_t id_153 { leb128_sz_760[id_152] };
              uint8_t id_154 { 7 };
              uint32_t id_155 { uint32_t(id_153 >> id_154) };
              Void id_156 { ((void)(leb128_sz_760[id_151] = id_155), ::dessser::Void()) };
              (void)id_156;
              uint8_t id_157 { 0 };
              uint32_t id_158 { leb128_sz_760[id_157] };
              uint32_t id_159 { 0U };
              bool id_160 { bool(id_158 > id_159) };
              while_flag_132 = id_160;
              if (while_flag_132) {
                (void)::dessser::Void();
              }
            } while (while_flag_132);
            (void)::dessser::Void();
            uint8_t id_161 { 0 };
            Pointer id_162 { leb128_ptr_761[id_161] };
            let_res_131 = id_162;
          }
          let_res_129 = let_res_131;
        }
        std::string id_163 { std::get<0 /* Contacts */>(p_0) };
        Bytes id_164 { id_163 };
        Pointer id_165 { let_res_129.writeBytes(id_164) };
        choose_res_125 = id_165;
      } else {
        uint16_t id_166 { uint16_t(p_0.index()) };
        uint16_t id_167 { 1 };
        bool id_168 { bool(id_166 == id_167) };
        Void id_169 { ((void)(assert(id_168)), ::dessser::Void()) };
        (void)id_169;
        std::string id_170 { std::get<1 /* Inhibition */>(p_0) };
        uint32_t id_171 { (uint32_t)id_170.size() };
        Vec<1, uint32_t> id_172 {  id_171  };
        Pointer let_res_173;
        {
          Vec<1, uint32_t> leb128_sz_758 { id_172 };
          Vec<1, Pointer> id_174 {  ssum_dst_757  };
          Pointer let_res_175;
          {
            Vec<1, Pointer> leb128_ptr_759 { id_174 };
            bool while_flag_176 { true };
            do {
              uint8_t id_177 { 0 };
              uint8_t id_178 { 0 };
              Pointer id_179 { leb128_ptr_759[id_178] };
              uint32_t id_180 { 128U };
              uint8_t id_181 { 0 };
              uint32_t id_182 { leb128_sz_758[id_181] };
              bool id_183 { bool(id_180 > id_182) };
              uint8_t choose_res_184;
              if (id_183) {
                uint8_t id_185 { 0 };
                uint32_t id_186 { leb128_sz_758[id_185] };
                uint8_t id_187 { uint8_t(id_186) };
                choose_res_184 = id_187;
              } else {
                uint8_t id_188 { 0 };
                uint32_t id_189 { leb128_sz_758[id_188] };
                uint8_t id_190 { uint8_t(id_189) };
                uint8_t id_191 { 128 };
                uint8_t id_192 { uint8_t(id_190 | id_191) };
                choose_res_184 = id_192;
              }
              Pointer id_193 { id_179.writeU8(choose_res_184) };
              Void id_194 { ((void)(leb128_ptr_759[id_177] = id_193), ::dessser::Void()) };
              (void)id_194;
              uint8_t id_195 { 0 };
              uint8_t id_196 { 0 };
              uint32_t id_197 { leb128_sz_758[id_196] };
              uint8_t id_198 { 7 };
              uint32_t id_199 { uint32_t(id_197 >> id_198) };
              Void id_200 { ((void)(leb128_sz_758[id_195] = id_199), ::dessser::Void()) };
              (void)id_200;
              uint8_t id_201 { 0 };
              uint32_t id_202 { leb128_sz_758[id_201] };
              uint32_t id_203 { 0U };
              bool id_204 { bool(id_202 > id_203) };
              while_flag_176 = id_204;
              if (while_flag_176) {
                (void)::dessser::Void();
              }
            } while (while_flag_176);
            (void)::dessser::Void();
            uint8_t id_205 { 0 };
            Pointer id_206 { leb128_ptr_759[id_205] };
            let_res_175 = id_206;
          }
          let_res_173 = let_res_175;
        }
        std::string id_207 { std::get<1 /* Inhibition */>(p_0) };
        Bytes id_208 { id_207 };
        Pointer id_209 { let_res_173.writeBytes(id_208) };
        choose_res_125 = id_209;
      }
      let_res_121 = choose_res_125;
    }
    return let_res_121;
  }
   };
  return fun118;
}
std::function<Pointer(::dessser::gen::sync_key::team_key_info const &,Pointer &)> team_key_info_to_row_binary(team_key_info_to_row_binary_init());

/* 
    (fun ("[Widgets U32]" "Ptr")
      (let "ssum_dst_751" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (write-u32 little-endian (identifier "ssum_dst_751") (get-alt "Widgets" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  const &,Pointer &)> per_dash_key_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  const &,Pointer &)> fun210 { [&](std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  p_0, Pointer p_1) {
    uint16_t id_211 { uint16_t((*p_0).index()) };
    Pointer id_212 { p_1.writeU16Le(id_211) };
    Pointer let_res_213;
    {
      Pointer ssum_dst_751 { id_212 };
      uint16_t id_214 { uint16_t((*p_0).index()) };
      uint16_t id_215 { 0 };
      bool id_216 { bool(id_214 == id_215) };
      Void id_217 { ((void)(assert(id_216)), ::dessser::Void()) };
      (void)id_217;
      uint32_t id_218 { std::get<0 /* Widgets */>((*p_0)) };
      Pointer id_219 { ssum_dst_751.writeU32Le(id_218) };
      let_res_213 = id_219;
    }
    return let_res_213;
  }
   };
  return fun210;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  const &,Pointer &)> per_dash_key_to_row_binary(per_dash_key_to_row_binary_init());

/* 
    (fun ("[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" "Ptr")
      (let "ssum_dst_753" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_754" (make-vec (string-length (get-alt "Response" (param 0))))
              (let "leb128_ptr_755" (make-vec (identifier "ssum_dst_753"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_755")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_755"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_754"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_754"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_754"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_754") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_754")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_754")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_755"))))) 
            (bytes-of-string (get-alt "Response" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "per_dash_key-to-row-binary") (get-alt "Scratchpad" (param 0)) (identifier "ssum_dst_753"))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::per_client const &,Pointer &)> per_client_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::per_client const &,Pointer &)> fun220 { [&](::dessser::gen::sync_key::per_client p_0, Pointer p_1) {
    uint16_t id_221 { uint16_t(p_0.index()) };
    Pointer id_222 { p_1.writeU16Le(id_221) };
    Pointer let_res_223;
    {
      Pointer ssum_dst_753 { id_222 };
      uint16_t id_224 { 0 };
      uint16_t id_225 { uint16_t(p_0.index()) };
      bool id_226 { bool(id_224 == id_225) };
      Pointer choose_res_227;
      if (id_226) {
        std::string id_228 { std::get<0 /* Response */>(p_0) };
        uint32_t id_229 { (uint32_t)id_228.size() };
        Vec<1, uint32_t> id_230 {  id_229  };
        Pointer let_res_231;
        {
          Vec<1, uint32_t> leb128_sz_754 { id_230 };
          Vec<1, Pointer> id_232 {  ssum_dst_753  };
          Pointer let_res_233;
          {
            Vec<1, Pointer> leb128_ptr_755 { id_232 };
            bool while_flag_234 { true };
            do {
              uint8_t id_235 { 0 };
              uint8_t id_236 { 0 };
              Pointer id_237 { leb128_ptr_755[id_236] };
              uint32_t id_238 { 128U };
              uint8_t id_239 { 0 };
              uint32_t id_240 { leb128_sz_754[id_239] };
              bool id_241 { bool(id_238 > id_240) };
              uint8_t choose_res_242;
              if (id_241) {
                uint8_t id_243 { 0 };
                uint32_t id_244 { leb128_sz_754[id_243] };
                uint8_t id_245 { uint8_t(id_244) };
                choose_res_242 = id_245;
              } else {
                uint8_t id_246 { 0 };
                uint32_t id_247 { leb128_sz_754[id_246] };
                uint8_t id_248 { uint8_t(id_247) };
                uint8_t id_249 { 128 };
                uint8_t id_250 { uint8_t(id_248 | id_249) };
                choose_res_242 = id_250;
              }
              Pointer id_251 { id_237.writeU8(choose_res_242) };
              Void id_252 { ((void)(leb128_ptr_755[id_235] = id_251), ::dessser::Void()) };
              (void)id_252;
              uint8_t id_253 { 0 };
              uint8_t id_254 { 0 };
              uint32_t id_255 { leb128_sz_754[id_254] };
              uint8_t id_256 { 7 };
              uint32_t id_257 { uint32_t(id_255 >> id_256) };
              Void id_258 { ((void)(leb128_sz_754[id_253] = id_257), ::dessser::Void()) };
              (void)id_258;
              uint8_t id_259 { 0 };
              uint32_t id_260 { leb128_sz_754[id_259] };
              uint32_t id_261 { 0U };
              bool id_262 { bool(id_260 > id_261) };
              while_flag_234 = id_262;
              if (while_flag_234) {
                (void)::dessser::Void();
              }
            } while (while_flag_234);
            (void)::dessser::Void();
            uint8_t id_263 { 0 };
            Pointer id_264 { leb128_ptr_755[id_263] };
            let_res_233 = id_264;
          }
          let_res_231 = let_res_233;
        }
        std::string id_265 { std::get<0 /* Response */>(p_0) };
        Bytes id_266 { id_265 };
        Pointer id_267 { let_res_231.writeBytes(id_266) };
        choose_res_227 = id_267;
      } else {
        uint16_t id_268 { uint16_t(p_0.index()) };
        uint16_t id_269 { 1 };
        bool id_270 { bool(id_268 == id_269) };
        Void id_271 { ((void)(assert(id_270)), ::dessser::Void()) };
        (void)id_271;
        std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_272 { std::get<1 /* Scratchpad */>(p_0) };
        Pointer id_273 { per_dash_key_to_row_binary(id_272, ssum_dst_753) };
        choose_res_227 = id_273;
      }
      let_res_223 = choose_res_227;
    }
    return let_res_223;
  }
   };
  return fun220;
}
std::function<Pointer(::dessser::gen::sync_key::per_client const &,Pointer &)> per_client_to_row_binary(per_client_to_row_binary_init());

/* 
    (fun ("[Subscriber STRING | LastTuple U32]" "Ptr")
      (let "ssum_dst_747" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_748" (make-vec (string-length (get-alt "Subscriber" (param 0))))
              (let "leb128_ptr_749" (make-vec (identifier "ssum_dst_747"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_749")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_749"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_748"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_748"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_748"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_748") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_748")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_748")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_749"))))) 
            (bytes-of-string (get-alt "Subscriber" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (write-u32 little-endian (identifier "ssum_dst_747") (get-alt "LastTuple" (param 0)))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::per_tail const &,Pointer &)> per_tail_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::per_tail const &,Pointer &)> fun274 { [&](::dessser::gen::sync_key::per_tail p_0, Pointer p_1) {
    uint16_t id_275 { uint16_t(p_0.index()) };
    Pointer id_276 { p_1.writeU16Le(id_275) };
    Pointer let_res_277;
    {
      Pointer ssum_dst_747 { id_276 };
      uint16_t id_278 { 0 };
      uint16_t id_279 { uint16_t(p_0.index()) };
      bool id_280 { bool(id_278 == id_279) };
      Pointer choose_res_281;
      if (id_280) {
        std::string id_282 { std::get<0 /* Subscriber */>(p_0) };
        uint32_t id_283 { (uint32_t)id_282.size() };
        Vec<1, uint32_t> id_284 {  id_283  };
        Pointer let_res_285;
        {
          Vec<1, uint32_t> leb128_sz_748 { id_284 };
          Vec<1, Pointer> id_286 {  ssum_dst_747  };
          Pointer let_res_287;
          {
            Vec<1, Pointer> leb128_ptr_749 { id_286 };
            bool while_flag_288 { true };
            do {
              uint8_t id_289 { 0 };
              uint8_t id_290 { 0 };
              Pointer id_291 { leb128_ptr_749[id_290] };
              uint32_t id_292 { 128U };
              uint8_t id_293 { 0 };
              uint32_t id_294 { leb128_sz_748[id_293] };
              bool id_295 { bool(id_292 > id_294) };
              uint8_t choose_res_296;
              if (id_295) {
                uint8_t id_297 { 0 };
                uint32_t id_298 { leb128_sz_748[id_297] };
                uint8_t id_299 { uint8_t(id_298) };
                choose_res_296 = id_299;
              } else {
                uint8_t id_300 { 0 };
                uint32_t id_301 { leb128_sz_748[id_300] };
                uint8_t id_302 { uint8_t(id_301) };
                uint8_t id_303 { 128 };
                uint8_t id_304 { uint8_t(id_302 | id_303) };
                choose_res_296 = id_304;
              }
              Pointer id_305 { id_291.writeU8(choose_res_296) };
              Void id_306 { ((void)(leb128_ptr_749[id_289] = id_305), ::dessser::Void()) };
              (void)id_306;
              uint8_t id_307 { 0 };
              uint8_t id_308 { 0 };
              uint32_t id_309 { leb128_sz_748[id_308] };
              uint8_t id_310 { 7 };
              uint32_t id_311 { uint32_t(id_309 >> id_310) };
              Void id_312 { ((void)(leb128_sz_748[id_307] = id_311), ::dessser::Void()) };
              (void)id_312;
              uint8_t id_313 { 0 };
              uint32_t id_314 { leb128_sz_748[id_313] };
              uint32_t id_315 { 0U };
              bool id_316 { bool(id_314 > id_315) };
              while_flag_288 = id_316;
              if (while_flag_288) {
                (void)::dessser::Void();
              }
            } while (while_flag_288);
            (void)::dessser::Void();
            uint8_t id_317 { 0 };
            Pointer id_318 { leb128_ptr_749[id_317] };
            let_res_287 = id_318;
          }
          let_res_285 = let_res_287;
        }
        std::string id_319 { std::get<0 /* Subscriber */>(p_0) };
        Bytes id_320 { id_319 };
        Pointer id_321 { let_res_285.writeBytes(id_320) };
        choose_res_281 = id_321;
      } else {
        uint16_t id_322 { uint16_t(p_0.index()) };
        uint16_t id_323 { 1 };
        bool id_324 { bool(id_322 == id_323) };
        Void id_325 { ((void)(assert(id_324)), ::dessser::Void()) };
        (void)id_325;
        uint32_t id_326 { std::get<1 /* LastTuple */>(p_0) };
        Pointer id_327 { ssum_dst_747.writeU32Le(id_326) };
        choose_res_281 = id_327;
      }
      let_res_277 = choose_res_281;
    }
    return let_res_277;
  }
   };
  return fun274;
}
std::function<Pointer(::dessser::gen::sync_key::per_tail const &,Pointer &)> per_tail_to_row_binary(per_tail_to_row_binary_init());

/* 
    (fun ("[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" "Ptr")
      (let "label1_725" (label-of (param 0))
        (let "ssum_dst_726" (write-u16 little-endian (param 1) (identifier "label1_725"))
          (if (eq (u16 0) (identifier "label1_725")) (identifier "ssum_dst_726")
            (if (eq (u16 1) (identifier "label1_725")) (identifier "ssum_dst_726")
              (if (eq (u16 2) (identifier "label1_725")) (identifier "ssum_dst_726")
                (if (eq (u16 3) (identifier "label1_725")) (identifier "ssum_dst_726")
                  (if (eq (u16 4) (identifier "label1_725")) (identifier "ssum_dst_726")
                    (if (eq (u16 5) (identifier "label1_725")) (identifier "ssum_dst_726")
                      (if (eq (u16 6) (identifier "label1_725"))
                        (let "stup_dst_729"
                          (write-bytes
                            (let "leb128_sz_727" (make-vec (string-length (get-item 0 (get-alt "PerInstance" (param 0)))))
                              (let "leb128_ptr_728" (make-vec (identifier "ssum_dst_726"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_728")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_728"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_727"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_727"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_727"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_727") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_727")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_727")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_728"))))) 
                            (bytes-of-string (get-item 0 (get-alt "PerInstance" (param 0)))))
                          (let "label1_730" (label-of (get-item 1 (get-alt "PerInstance" (param 0))))
                            (let "ssum_dst_731" (write-u16 little-endian (identifier "stup_dst_729") (identifier "label1_730"))
                              (if (eq (u16 0) (identifier "label1_730")) 
                                (identifier "ssum_dst_731")
                                (if (eq (u16 1) (identifier "label1_730")) 
                                  (identifier "ssum_dst_731")
                                  (if (eq (u16 2) (identifier "label1_730")) 
                                    (identifier "ssum_dst_731")
                                    (if (eq (u16 3) (identifier "label1_730")) 
                                      (identifier "ssum_dst_731")
                                      (if (eq (u16 4) (identifier "label1_730")) 
                                        (identifier "ssum_dst_731")
                                        (if (eq (u16 5) (identifier "label1_730")) 
                                          (identifier "ssum_dst_731") 
                                          (if (eq (u16 6) (identifier "label1_730")) (identifier "ssum_dst_731") (seq (assert (eq (identifier "label1_730") (u16 7))) (identifier "ssum_dst_731"))))))))))))
                        (if (eq (u16 7) (identifier "label1_725")) (write-u32 little-endian (identifier "ssum_dst_726") (get-alt "PerReplayer" (param 0)))
                          (seq (assert (eq (identifier "label1_725") (u16 8))) (identifier "ssum_dst_726")))))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::per_worker_data const &,Pointer &)> per_worker_data_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::per_worker_data const &,Pointer &)> fun328 { [&](::dessser::gen::sync_key::per_worker_data p_0, Pointer p_1) {
    uint16_t id_329 { uint16_t(p_0.index()) };
    Pointer let_res_330;
    {
      uint16_t label1_725 { id_329 };
      Pointer id_331 { p_1.writeU16Le(label1_725) };
      Pointer let_res_332;
      {
        Pointer ssum_dst_726 { id_331 };
        uint16_t id_333 { 0 };
        bool id_334 { bool(id_333 == label1_725) };
        Pointer choose_res_335;
        if (id_334) {
          choose_res_335 = ssum_dst_726;
        } else {
          uint16_t id_336 { 1 };
          bool id_337 { bool(id_336 == label1_725) };
          Pointer choose_res_338;
          if (id_337) {
            choose_res_338 = ssum_dst_726;
          } else {
            uint16_t id_339 { 2 };
            bool id_340 { bool(id_339 == label1_725) };
            Pointer choose_res_341;
            if (id_340) {
              choose_res_341 = ssum_dst_726;
            } else {
              uint16_t id_342 { 3 };
              bool id_343 { bool(id_342 == label1_725) };
              Pointer choose_res_344;
              if (id_343) {
                choose_res_344 = ssum_dst_726;
              } else {
                uint16_t id_345 { 4 };
                bool id_346 { bool(id_345 == label1_725) };
                Pointer choose_res_347;
                if (id_346) {
                  choose_res_347 = ssum_dst_726;
                } else {
                  uint16_t id_348 { 5 };
                  bool id_349 { bool(id_348 == label1_725) };
                  Pointer choose_res_350;
                  if (id_349) {
                    choose_res_350 = ssum_dst_726;
                  } else {
                    uint16_t id_351 { 6 };
                    bool id_352 { bool(id_351 == label1_725) };
                    Pointer choose_res_353;
                    if (id_352) {
                      ::dessser::gen::sync_key::ta7e4a6f84fc41fdc68e99605bbb0a0c8 id_354 { std::get<6 /* PerInstance */>(p_0) };
                      std::string id_355 { std::get<0>(id_354) };
                      uint32_t id_356 { (uint32_t)id_355.size() };
                      Vec<1, uint32_t> id_357 {  id_356  };
                      Pointer let_res_358;
                      {
                        Vec<1, uint32_t> leb128_sz_727 { id_357 };
                        Vec<1, Pointer> id_359 {  ssum_dst_726  };
                        Pointer let_res_360;
                        {
                          Vec<1, Pointer> leb128_ptr_728 { id_359 };
                          bool while_flag_361 { true };
                          do {
                            uint8_t id_362 { 0 };
                            uint8_t id_363 { 0 };
                            Pointer id_364 { leb128_ptr_728[id_363] };
                            uint32_t id_365 { 128U };
                            uint8_t id_366 { 0 };
                            uint32_t id_367 { leb128_sz_727[id_366] };
                            bool id_368 { bool(id_365 > id_367) };
                            uint8_t choose_res_369;
                            if (id_368) {
                              uint8_t id_370 { 0 };
                              uint32_t id_371 { leb128_sz_727[id_370] };
                              uint8_t id_372 { uint8_t(id_371) };
                              choose_res_369 = id_372;
                            } else {
                              uint8_t id_373 { 0 };
                              uint32_t id_374 { leb128_sz_727[id_373] };
                              uint8_t id_375 { uint8_t(id_374) };
                              uint8_t id_376 { 128 };
                              uint8_t id_377 { uint8_t(id_375 | id_376) };
                              choose_res_369 = id_377;
                            }
                            Pointer id_378 { id_364.writeU8(choose_res_369) };
                            Void id_379 { ((void)(leb128_ptr_728[id_362] = id_378), ::dessser::Void()) };
                            (void)id_379;
                            uint8_t id_380 { 0 };
                            uint8_t id_381 { 0 };
                            uint32_t id_382 { leb128_sz_727[id_381] };
                            uint8_t id_383 { 7 };
                            uint32_t id_384 { uint32_t(id_382 >> id_383) };
                            Void id_385 { ((void)(leb128_sz_727[id_380] = id_384), ::dessser::Void()) };
                            (void)id_385;
                            uint8_t id_386 { 0 };
                            uint32_t id_387 { leb128_sz_727[id_386] };
                            uint32_t id_388 { 0U };
                            bool id_389 { bool(id_387 > id_388) };
                            while_flag_361 = id_389;
                            if (while_flag_361) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_361);
                          (void)::dessser::Void();
                          uint8_t id_390 { 0 };
                          Pointer id_391 { leb128_ptr_728[id_390] };
                          let_res_360 = id_391;
                        }
                        let_res_358 = let_res_360;
                      }
                      ::dessser::gen::sync_key::ta7e4a6f84fc41fdc68e99605bbb0a0c8 id_392 { std::get<6 /* PerInstance */>(p_0) };
                      std::string id_393 { std::get<0>(id_392) };
                      Bytes id_394 { id_393 };
                      Pointer id_395 { let_res_358.writeBytes(id_394) };
                      Pointer let_res_396;
                      {
                        Pointer stup_dst_729 { id_395 };
                        ::dessser::gen::sync_key::ta7e4a6f84fc41fdc68e99605bbb0a0c8 id_397 { std::get<6 /* PerInstance */>(p_0) };
                        ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_398 { std::get<1>(id_397) };
                        uint16_t id_399 { uint16_t(id_398.index()) };
                        Pointer let_res_400;
                        {
                          uint16_t label1_730 { id_399 };
                          Pointer id_401 { stup_dst_729.writeU16Le(label1_730) };
                          Pointer let_res_402;
                          {
                            Pointer ssum_dst_731 { id_401 };
                            uint16_t id_403 { 0 };
                            bool id_404 { bool(id_403 == label1_730) };
                            Pointer choose_res_405;
                            if (id_404) {
                              choose_res_405 = ssum_dst_731;
                            } else {
                              uint16_t id_406 { 1 };
                              bool id_407 { bool(id_406 == label1_730) };
                              Pointer choose_res_408;
                              if (id_407) {
                                choose_res_408 = ssum_dst_731;
                              } else {
                                uint16_t id_409 { 2 };
                                bool id_410 { bool(id_409 == label1_730) };
                                Pointer choose_res_411;
                                if (id_410) {
                                  choose_res_411 = ssum_dst_731;
                                } else {
                                  uint16_t id_412 { 3 };
                                  bool id_413 { bool(id_412 == label1_730) };
                                  Pointer choose_res_414;
                                  if (id_413) {
                                    choose_res_414 = ssum_dst_731;
                                  } else {
                                    uint16_t id_415 { 4 };
                                    bool id_416 { bool(id_415 == label1_730) };
                                    Pointer choose_res_417;
                                    if (id_416) {
                                      choose_res_417 = ssum_dst_731;
                                    } else {
                                      uint16_t id_418 { 5 };
                                      bool id_419 { bool(id_418 == label1_730) };
                                      Pointer choose_res_420;
                                      if (id_419) {
                                        choose_res_420 = ssum_dst_731;
                                      } else {
                                        uint16_t id_421 { 6 };
                                        bool id_422 { bool(id_421 == label1_730) };
                                        Pointer choose_res_423;
                                        if (id_422) {
                                          choose_res_423 = ssum_dst_731;
                                        } else {
                                          uint16_t id_424 { 7 };
                                          bool id_425 { bool(label1_730 == id_424) };
                                          Void id_426 { ((void)(assert(id_425)), ::dessser::Void()) };
                                          (void)id_426;
                                          choose_res_423 = ssum_dst_731;
                                        }
                                        choose_res_420 = choose_res_423;
                                      }
                                      choose_res_417 = choose_res_420;
                                    }
                                    choose_res_414 = choose_res_417;
                                  }
                                  choose_res_411 = choose_res_414;
                                }
                                choose_res_408 = choose_res_411;
                              }
                              choose_res_405 = choose_res_408;
                            }
                            let_res_402 = choose_res_405;
                          }
                          let_res_400 = let_res_402;
                        }
                        let_res_396 = let_res_400;
                      }
                      choose_res_353 = let_res_396;
                    } else {
                      uint16_t id_427 { 7 };
                      bool id_428 { bool(id_427 == label1_725) };
                      Pointer choose_res_429;
                      if (id_428) {
                        uint32_t id_430 { std::get<7 /* PerReplayer */>(p_0) };
                        Pointer id_431 { ssum_dst_726.writeU32Le(id_430) };
                        choose_res_429 = id_431;
                      } else {
                        uint16_t id_432 { 8 };
                        bool id_433 { bool(label1_725 == id_432) };
                        Void id_434 { ((void)(assert(id_433)), ::dessser::Void()) };
                        (void)id_434;
                        choose_res_429 = ssum_dst_726;
                      }
                      choose_res_353 = choose_res_429;
                    }
                    choose_res_350 = choose_res_353;
                  }
                  choose_res_347 = choose_res_350;
                }
                choose_res_344 = choose_res_347;
              }
              choose_res_341 = choose_res_344;
            }
            choose_res_338 = choose_res_341;
          }
          choose_res_335 = choose_res_338;
        }
        let_res_332 = choose_res_335;
      }
      let_res_330 = let_res_332;
    }
    return let_res_330;
  }
   };
  return fun328;
}
std::function<Pointer(::dessser::gen::sync_key::per_worker_data const &,Pointer &)> per_worker_data_to_row_binary(per_worker_data_to_row_binary_init());

/* 
    (fun ("($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))" "Ptr")
      (let "stup_dst_732" (apply (ext-identifier fq_name to-row-binary) (get-item 0 (param 0)) (param 1)) (apply (identifier "per_worker_data-to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_732"))))
 */
static std::function<Pointer(::dessser::gen::sync_key::per_worker &,Pointer &)> per_worker_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::per_worker &,Pointer &)> fun435 { [&](::dessser::gen::sync_key::per_worker p_0, Pointer p_1) {
    auto fun436 { dessser::gen::fq_name::to_row_binary };
    dessser::gen::fq_name::t_ext id_437 { std::get<0>(p_0) };
    Pointer id_438 { fun436(id_437, p_1) };
    Pointer let_res_439;
    {
      Pointer stup_dst_732 { id_438 };
      ::dessser::gen::sync_key::per_worker_data id_440 { std::get<1>(p_0) };
      Pointer id_441 { per_worker_data_to_row_binary(id_440, stup_dst_732) };
      let_res_439 = id_441;
    }
    return let_res_439;
  }
   };
  return fun435;
}
std::function<Pointer(::dessser::gen::sync_key::per_worker &,Pointer &)> per_worker_to_row_binary(per_worker_to_row_binary_init());

/* 
    (fun ("[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" "Ptr")
      (let "ssum_dst_734" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_734")
          (if (eq (u16 1) (label-of (param 0)))
            (let "stup_dst_742"
              (write-bytes
                (let "leb128_sz_740" (make-vec (string-length (get-item 0 (get-alt "PerService" (param 0)))))
                  (let "leb128_ptr_741" (make-vec (identifier "ssum_dst_734"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_741")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_741"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_740"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_740"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_740"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_740") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_740")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_740")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_741"))))) 
                (bytes-of-string (get-item 0 (get-alt "PerService" (param 0)))))
              (let "ssum_dst_744" (write-u16 little-endian (identifier "stup_dst_742") (label-of (get-item 1 (get-alt "PerService" (param 0)))))
                (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (param 0))))) 
                  (identifier "ssum_dst_744") (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (param 0)))) (u16 1))) (identifier "ssum_dst_744")))))
            (if (eq (u16 2) (label-of (param 0))) (apply (identifier "per_worker-to-row-binary") (get-alt "PerWorker" (param 0)) (identifier "ssum_dst_734"))
              (seq (assert (eq (label-of (param 0)) (u16 3)))
                (let "stup_dst_737"
                  (write-bytes
                    (let "leb128_sz_735" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (param 0)))))
                      (let "leb128_ptr_736" (make-vec (identifier "ssum_dst_734"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_736")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_736"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_735"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_735"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_735"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_735") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_735")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_735")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_736"))))) 
                    (bytes-of-string (get-item 0 (get-alt "PerProgram" (param 0)))))
                  (let "ssum_dst_739" (write-u16 little-endian (identifier "stup_dst_737") (label-of (get-item 1 (get-alt "PerProgram" (param 0)))))
                    (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (param 0)))) (u16 0))) (identifier "ssum_dst_739"))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::per_site_data &,Pointer &)> per_site_data_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::per_site_data &,Pointer &)> fun442 { [&](::dessser::gen::sync_key::per_site_data p_0, Pointer p_1) {
    uint16_t id_443 { uint16_t(p_0.index()) };
    Pointer id_444 { p_1.writeU16Le(id_443) };
    Pointer let_res_445;
    {
      Pointer ssum_dst_734 { id_444 };
      uint16_t id_446 { 0 };
      uint16_t id_447 { uint16_t(p_0.index()) };
      bool id_448 { bool(id_446 == id_447) };
      Pointer choose_res_449;
      if (id_448) {
        choose_res_449 = ssum_dst_734;
      } else {
        uint16_t id_450 { 1 };
        uint16_t id_451 { uint16_t(p_0.index()) };
        bool id_452 { bool(id_450 == id_451) };
        Pointer choose_res_453;
        if (id_452) {
          ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98 id_454 { std::get<1 /* PerService */>(p_0) };
          std::string id_455 { std::get<0>(id_454) };
          uint32_t id_456 { (uint32_t)id_455.size() };
          Vec<1, uint32_t> id_457 {  id_456  };
          Pointer let_res_458;
          {
            Vec<1, uint32_t> leb128_sz_740 { id_457 };
            Vec<1, Pointer> id_459 {  ssum_dst_734  };
            Pointer let_res_460;
            {
              Vec<1, Pointer> leb128_ptr_741 { id_459 };
              bool while_flag_461 { true };
              do {
                uint8_t id_462 { 0 };
                uint8_t id_463 { 0 };
                Pointer id_464 { leb128_ptr_741[id_463] };
                uint32_t id_465 { 128U };
                uint8_t id_466 { 0 };
                uint32_t id_467 { leb128_sz_740[id_466] };
                bool id_468 { bool(id_465 > id_467) };
                uint8_t choose_res_469;
                if (id_468) {
                  uint8_t id_470 { 0 };
                  uint32_t id_471 { leb128_sz_740[id_470] };
                  uint8_t id_472 { uint8_t(id_471) };
                  choose_res_469 = id_472;
                } else {
                  uint8_t id_473 { 0 };
                  uint32_t id_474 { leb128_sz_740[id_473] };
                  uint8_t id_475 { uint8_t(id_474) };
                  uint8_t id_476 { 128 };
                  uint8_t id_477 { uint8_t(id_475 | id_476) };
                  choose_res_469 = id_477;
                }
                Pointer id_478 { id_464.writeU8(choose_res_469) };
                Void id_479 { ((void)(leb128_ptr_741[id_462] = id_478), ::dessser::Void()) };
                (void)id_479;
                uint8_t id_480 { 0 };
                uint8_t id_481 { 0 };
                uint32_t id_482 { leb128_sz_740[id_481] };
                uint8_t id_483 { 7 };
                uint32_t id_484 { uint32_t(id_482 >> id_483) };
                Void id_485 { ((void)(leb128_sz_740[id_480] = id_484), ::dessser::Void()) };
                (void)id_485;
                uint8_t id_486 { 0 };
                uint32_t id_487 { leb128_sz_740[id_486] };
                uint32_t id_488 { 0U };
                bool id_489 { bool(id_487 > id_488) };
                while_flag_461 = id_489;
                if (while_flag_461) {
                  (void)::dessser::Void();
                }
              } while (while_flag_461);
              (void)::dessser::Void();
              uint8_t id_490 { 0 };
              Pointer id_491 { leb128_ptr_741[id_490] };
              let_res_460 = id_491;
            }
            let_res_458 = let_res_460;
          }
          ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98 id_492 { std::get<1 /* PerService */>(p_0) };
          std::string id_493 { std::get<0>(id_492) };
          Bytes id_494 { id_493 };
          Pointer id_495 { let_res_458.writeBytes(id_494) };
          Pointer let_res_496;
          {
            Pointer stup_dst_742 { id_495 };
            ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98 id_497 { std::get<1 /* PerService */>(p_0) };
            ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_498 { std::get<1>(id_497) };
            uint16_t id_499 { uint16_t(id_498.index()) };
            Pointer id_500 { stup_dst_742.writeU16Le(id_499) };
            Pointer let_res_501;
            {
              Pointer ssum_dst_744 { id_500 };
              uint16_t id_502 { 0 };
              ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98 id_503 { std::get<1 /* PerService */>(p_0) };
              ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_504 { std::get<1>(id_503) };
              uint16_t id_505 { uint16_t(id_504.index()) };
              bool id_506 { bool(id_502 == id_505) };
              Pointer choose_res_507;
              if (id_506) {
                choose_res_507 = ssum_dst_744;
              } else {
                ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98 id_508 { std::get<1 /* PerService */>(p_0) };
                ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_509 { std::get<1>(id_508) };
                uint16_t id_510 { uint16_t(id_509.index()) };
                uint16_t id_511 { 1 };
                bool id_512 { bool(id_510 == id_511) };
                Void id_513 { ((void)(assert(id_512)), ::dessser::Void()) };
                (void)id_513;
                choose_res_507 = ssum_dst_744;
              }
              let_res_501 = choose_res_507;
            }
            let_res_496 = let_res_501;
          }
          choose_res_453 = let_res_496;
        } else {
          uint16_t id_514 { 2 };
          uint16_t id_515 { uint16_t(p_0.index()) };
          bool id_516 { bool(id_514 == id_515) };
          Pointer choose_res_517;
          if (id_516) {
            ::dessser::gen::sync_key::per_worker id_518 { std::get<2 /* PerWorker */>(p_0) };
            Pointer id_519 { per_worker_to_row_binary(id_518, ssum_dst_734) };
            choose_res_517 = id_519;
          } else {
            uint16_t id_520 { uint16_t(p_0.index()) };
            uint16_t id_521 { 3 };
            bool id_522 { bool(id_520 == id_521) };
            Void id_523 { ((void)(assert(id_522)), ::dessser::Void()) };
            (void)id_523;
            ::dessser::gen::sync_key::t85827d1984b82a47867ad2208bc45f28 id_524 { std::get<3 /* PerProgram */>(p_0) };
            std::string id_525 { std::get<0>(id_524) };
            uint32_t id_526 { (uint32_t)id_525.size() };
            Vec<1, uint32_t> id_527 {  id_526  };
            Pointer let_res_528;
            {
              Vec<1, uint32_t> leb128_sz_735 { id_527 };
              Vec<1, Pointer> id_529 {  ssum_dst_734  };
              Pointer let_res_530;
              {
                Vec<1, Pointer> leb128_ptr_736 { id_529 };
                bool while_flag_531 { true };
                do {
                  uint8_t id_532 { 0 };
                  uint8_t id_533 { 0 };
                  Pointer id_534 { leb128_ptr_736[id_533] };
                  uint32_t id_535 { 128U };
                  uint8_t id_536 { 0 };
                  uint32_t id_537 { leb128_sz_735[id_536] };
                  bool id_538 { bool(id_535 > id_537) };
                  uint8_t choose_res_539;
                  if (id_538) {
                    uint8_t id_540 { 0 };
                    uint32_t id_541 { leb128_sz_735[id_540] };
                    uint8_t id_542 { uint8_t(id_541) };
                    choose_res_539 = id_542;
                  } else {
                    uint8_t id_543 { 0 };
                    uint32_t id_544 { leb128_sz_735[id_543] };
                    uint8_t id_545 { uint8_t(id_544) };
                    uint8_t id_546 { 128 };
                    uint8_t id_547 { uint8_t(id_545 | id_546) };
                    choose_res_539 = id_547;
                  }
                  Pointer id_548 { id_534.writeU8(choose_res_539) };
                  Void id_549 { ((void)(leb128_ptr_736[id_532] = id_548), ::dessser::Void()) };
                  (void)id_549;
                  uint8_t id_550 { 0 };
                  uint8_t id_551 { 0 };
                  uint32_t id_552 { leb128_sz_735[id_551] };
                  uint8_t id_553 { 7 };
                  uint32_t id_554 { uint32_t(id_552 >> id_553) };
                  Void id_555 { ((void)(leb128_sz_735[id_550] = id_554), ::dessser::Void()) };
                  (void)id_555;
                  uint8_t id_556 { 0 };
                  uint32_t id_557 { leb128_sz_735[id_556] };
                  uint32_t id_558 { 0U };
                  bool id_559 { bool(id_557 > id_558) };
                  while_flag_531 = id_559;
                  if (while_flag_531) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_531);
                (void)::dessser::Void();
                uint8_t id_560 { 0 };
                Pointer id_561 { leb128_ptr_736[id_560] };
                let_res_530 = id_561;
              }
              let_res_528 = let_res_530;
            }
            ::dessser::gen::sync_key::t85827d1984b82a47867ad2208bc45f28 id_562 { std::get<3 /* PerProgram */>(p_0) };
            std::string id_563 { std::get<0>(id_562) };
            Bytes id_564 { id_563 };
            Pointer id_565 { let_res_528.writeBytes(id_564) };
            Pointer let_res_566;
            {
              Pointer stup_dst_737 { id_565 };
              ::dessser::gen::sync_key::t85827d1984b82a47867ad2208bc45f28 id_567 { std::get<3 /* PerProgram */>(p_0) };
              ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51 id_568 { std::get<1>(id_567) };
              uint16_t id_569 { uint16_t(id_568.index()) };
              Pointer id_570 { stup_dst_737.writeU16Le(id_569) };
              Pointer let_res_571;
              {
                Pointer ssum_dst_739 { id_570 };
                ::dessser::gen::sync_key::t85827d1984b82a47867ad2208bc45f28 id_572 { std::get<3 /* PerProgram */>(p_0) };
                ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51 id_573 { std::get<1>(id_572) };
                uint16_t id_574 { uint16_t(id_573.index()) };
                uint16_t id_575 { 0 };
                bool id_576 { bool(id_574 == id_575) };
                Void id_577 { ((void)(assert(id_576)), ::dessser::Void()) };
                (void)id_577;
                let_res_571 = ssum_dst_739;
              }
              let_res_566 = let_res_571;
            }
            choose_res_517 = let_res_566;
          }
          choose_res_453 = choose_res_517;
        }
        choose_res_449 = choose_res_453;
      }
      let_res_445 = choose_res_449;
    }
    return let_res_445;
  }
   };
  return fun442;
}
std::function<Pointer(::dessser::gen::sync_key::per_site_data &,Pointer &)> per_site_data_to_row_binary(per_site_data_to_row_binary_init());

/* 
    (fun ("($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))" "Ptr")
      (let "stup_dst_745" (apply (ext-identifier site_name to-row-binary) (get-item 0 (param 0)) (param 1)) (apply (identifier "per_site_data-to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_745"))))
 */
static std::function<Pointer(::dessser::gen::sync_key::per_site &,Pointer &)> per_site_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::per_site &,Pointer &)> fun578 { [&](::dessser::gen::sync_key::per_site p_0, Pointer p_1) {
    auto fun579 { dessser::gen::site_name::to_row_binary };
    dessser::gen::site_name::t_ext id_580 { std::get<0>(p_0) };
    Pointer id_581 { fun579(id_580, p_1) };
    Pointer let_res_582;
    {
      Pointer stup_dst_745 { id_581 };
      ::dessser::gen::sync_key::per_site_data id_583 { std::get<1>(p_0) };
      Pointer id_584 { per_site_data_to_row_binary(id_583, stup_dst_745) };
      let_res_582 = id_584;
    }
    return let_res_582;
  }
   };
  return fun578;
}
std::function<Pointer(::dessser::gen::sync_key::per_site &,Pointer &)> per_site_to_row_binary(per_site_to_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" "Ptr")
      (let "label1_770" (label-of (param 0))
        (let "ssum_dst_771" (write-u16 little-endian (param 1) (identifier "label1_770"))
          (if (eq (u16 0) (identifier "label1_770")) (identifier "ssum_dst_771")
            (if (eq (u16 1) (identifier "label1_770")) (identifier "ssum_dst_771")
              (if (eq (u16 2) (identifier "label1_770"))
                (write-bytes
                  (let "leb128_sz_792" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "leb128_ptr_793" (make-vec (identifier "ssum_dst_771"))
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
                  (bytes-of-string (get-alt "Versions" (param 0))))
                (if (eq (u16 3) (identifier "label1_770"))
                  (let "stup_dst_789" (apply (ext-identifier src_path to-row-binary) (get-item 0 (get-alt "Sources" (param 0))) (identifier "ssum_dst_771"))
                    (write-bytes
                      (let "leb128_sz_790" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "leb128_ptr_791" (make-vec (identifier "stup_dst_789"))
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
                      (bytes-of-string (get-item 1 (get-alt "Sources" (param 0))))))
                  (if (eq (u16 4) (identifier "label1_770")) (identifier "ssum_dst_771")
                    (if (eq (u16 5) (identifier "label1_770")) (apply (identifier "per_site-to-row-binary") (get-alt "PerSite" (param 0)) (identifier "ssum_dst_771"))
                      (if (eq (u16 6) (identifier "label1_770"))
                        (let "ssum_dst_786" (write-u16 little-endian (identifier "ssum_dst_771") (label-of (get-alt "Storage" (param 0))))
                          (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                            (identifier "ssum_dst_786")
                            (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                              (identifier "ssum_dst_786")
                              (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                                (write-bytes
                                  (let "leb128_sz_787" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                    (let "leb128_ptr_788" (make-vec (identifier "ssum_dst_786"))
                                      (seq
                                        (while
                                          (seq
                                            (set-vec (u8 0) (identifier "leb128_ptr_788")
                                              (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_788"))
                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_787"))) 
                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_787"))) 
                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_787"))) (u8 128)))))
                                            (set-vec (u8 0) (identifier "leb128_sz_787") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_787")) (u8 7))) 
                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_787")) (u32 0))) 
                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_788"))))) 
                                  (bytes-of-string (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))))))
                        (if (eq (u16 7) (identifier "label1_770"))
                          (let "stup_dst_784"
                            (let "stup_dst_781"
                              (let "stup_dst_780" (apply (ext-identifier site_name to-row-binary) (get-item 0 (get-alt "Tails" (param 0))) (identifier "ssum_dst_771"))
                                (apply (ext-identifier fq_name to-row-binary) (get-item 1 (get-alt "Tails" (param 0))) (identifier "stup_dst_780")))
                              (write-bytes
                                (let "leb128_sz_782" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "leb128_ptr_783" (make-vec (identifier "stup_dst_781"))
                                    (seq
                                      (while
                                        (seq
                                          (set-vec (u8 0) (identifier "leb128_ptr_783")
                                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_783"))
                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_782"))) 
                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_782"))) 
                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_782"))) (u8 128)))))
                                          (set-vec (u8 0) (identifier "leb128_sz_782") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_782")) (u8 7))) 
                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_782")) (u32 0))) 
                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_783"))))) 
                                (bytes-of-string (get-item 2 (get-alt "Tails" (param 0)))))) 
                            (apply (identifier "per_tail-to-row-binary") (get-item 3 (get-alt "Tails" (param 0))) (identifier "stup_dst_784")))
                          (if (eq (u16 8) (identifier "label1_770")) 
                            (write-u16 little-endian (identifier "ssum_dst_771") (get-alt "Replays" (param 0)))
                            (if (eq (u16 9) (identifier "label1_770"))
                              (if (is-null (get-alt "Error" (param 0))) 
                                (write-u8 (identifier "ssum_dst_771") (u8 1)) 
                                (apply (ext-identifier sync_socket to-row-binary) (force (get-alt "Error" (param 0))) (write-u8 (identifier "ssum_dst_771") (u8 0))))
                              (if (eq (u16 10) (identifier "label1_770")) 
                                (identifier "ssum_dst_771")
                                (if (eq (u16 11) (identifier "label1_770"))
                                  (let "stup_dst_779" (apply (ext-identifier sync_socket to-row-binary) (get-item 0 (get-alt "PerClient" (param 0))) (identifier "ssum_dst_771"))
                                    (apply (identifier "per_client-to-row-binary") (get-item 1 (get-alt "PerClient" (param 0))) (identifier "stup_dst_779")))
                                  (if (eq (u16 12) (identifier "label1_770"))
                                    (let "stup_dst_778"
                                      (write-bytes
                                        (let "leb128_sz_776" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "leb128_ptr_777" (make-vec (identifier "ssum_dst_771"))
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
                                        (bytes-of-string (get-item 0 (get-alt "Dashboards" (param 0))))) 
                                      (apply (identifier "per_dash_key-to-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))) (identifier "stup_dst_778")))
                                    (if (eq (u16 13) (identifier "label1_770")) 
                                      (identifier "ssum_dst_771")
                                      (if (eq (u16 14) (identifier "label1_770"))
                                        (let "srec_dst_775" (apply (ext-identifier team_name to-row-binary) (get-field "name" (get-alt "Teams" (param 0))) (identifier "ssum_dst_771"))
                                          (apply (identifier "team_key_info-to-row-binary") (get-field "info" (get-alt "Teams" (param 0))) (identifier "srec_dst_775")))
                                        (seq (assert (eq (identifier "label1_770") (u16 15)))
                                          (let "stup_dst_774"
                                            (write-bytes
                                              (let "leb128_sz_772" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "leb128_ptr_773" 
                                                  (make-vec (identifier "ssum_dst_771"))
                                                  (seq
                                                    (while
                                                      (seq
                                                        (set-vec (u8 0) 
                                                          (identifier "leb128_ptr_773")
                                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_773"))
                                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_772"))) 
                                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_772"))) 
                                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_772"))) (u8 128)))))
                                                        (set-vec (u8 0) (identifier "leb128_sz_772") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_772")) (u8 7)))
                                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_772")) (u32 0))) 
                                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_773"))))) 
                                              (bytes-of-string (get-item 0 (get-alt "Incidents" (param 0)))))
                                            (apply (identifier "incident_key-to-row-binary") (get-item 1 (get-alt "Incidents" (param 0))) (identifier "stup_dst_774"))))))))))))))))))))))
 */
static std::function<Pointer(::dessser::gen::sync_key::t &,Pointer &)> to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::t &,Pointer &)> fun585 { [&](::dessser::gen::sync_key::t p_0, Pointer p_1) {
    uint16_t id_586 { uint16_t(p_0.index()) };
    Pointer let_res_587;
    {
      uint16_t label1_770 { id_586 };
      Pointer id_588 { p_1.writeU16Le(label1_770) };
      Pointer let_res_589;
      {
        Pointer ssum_dst_771 { id_588 };
        uint16_t id_590 { 0 };
        bool id_591 { bool(id_590 == label1_770) };
        Pointer choose_res_592;
        if (id_591) {
          choose_res_592 = ssum_dst_771;
        } else {
          uint16_t id_593 { 1 };
          bool id_594 { bool(id_593 == label1_770) };
          Pointer choose_res_595;
          if (id_594) {
            choose_res_595 = ssum_dst_771;
          } else {
            uint16_t id_596 { 2 };
            bool id_597 { bool(id_596 == label1_770) };
            Pointer choose_res_598;
            if (id_597) {
              std::string id_599 { std::get<2 /* Versions */>(p_0) };
              uint32_t id_600 { (uint32_t)id_599.size() };
              Vec<1, uint32_t> id_601 {  id_600  };
              Pointer let_res_602;
              {
                Vec<1, uint32_t> leb128_sz_792 { id_601 };
                Vec<1, Pointer> id_603 {  ssum_dst_771  };
                Pointer let_res_604;
                {
                  Vec<1, Pointer> leb128_ptr_793 { id_603 };
                  bool while_flag_605 { true };
                  do {
                    uint8_t id_606 { 0 };
                    uint8_t id_607 { 0 };
                    Pointer id_608 { leb128_ptr_793[id_607] };
                    uint32_t id_609 { 128U };
                    uint8_t id_610 { 0 };
                    uint32_t id_611 { leb128_sz_792[id_610] };
                    bool id_612 { bool(id_609 > id_611) };
                    uint8_t choose_res_613;
                    if (id_612) {
                      uint8_t id_614 { 0 };
                      uint32_t id_615 { leb128_sz_792[id_614] };
                      uint8_t id_616 { uint8_t(id_615) };
                      choose_res_613 = id_616;
                    } else {
                      uint8_t id_617 { 0 };
                      uint32_t id_618 { leb128_sz_792[id_617] };
                      uint8_t id_619 { uint8_t(id_618) };
                      uint8_t id_620 { 128 };
                      uint8_t id_621 { uint8_t(id_619 | id_620) };
                      choose_res_613 = id_621;
                    }
                    Pointer id_622 { id_608.writeU8(choose_res_613) };
                    Void id_623 { ((void)(leb128_ptr_793[id_606] = id_622), ::dessser::Void()) };
                    (void)id_623;
                    uint8_t id_624 { 0 };
                    uint8_t id_625 { 0 };
                    uint32_t id_626 { leb128_sz_792[id_625] };
                    uint8_t id_627 { 7 };
                    uint32_t id_628 { uint32_t(id_626 >> id_627) };
                    Void id_629 { ((void)(leb128_sz_792[id_624] = id_628), ::dessser::Void()) };
                    (void)id_629;
                    uint8_t id_630 { 0 };
                    uint32_t id_631 { leb128_sz_792[id_630] };
                    uint32_t id_632 { 0U };
                    bool id_633 { bool(id_631 > id_632) };
                    while_flag_605 = id_633;
                    if (while_flag_605) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_605);
                  (void)::dessser::Void();
                  uint8_t id_634 { 0 };
                  Pointer id_635 { leb128_ptr_793[id_634] };
                  let_res_604 = id_635;
                }
                let_res_602 = let_res_604;
              }
              std::string id_636 { std::get<2 /* Versions */>(p_0) };
              Bytes id_637 { id_636 };
              Pointer id_638 { let_res_602.writeBytes(id_637) };
              choose_res_598 = id_638;
            } else {
              uint16_t id_639 { 3 };
              bool id_640 { bool(id_639 == label1_770) };
              Pointer choose_res_641;
              if (id_640) {
                auto fun642 { dessser::gen::src_path::to_row_binary };
                ::dessser::gen::sync_key::t86252e3890668e56d73574e8b879a5b1 id_643 { std::get<3 /* Sources */>(p_0) };
                dessser::gen::src_path::t_ext id_644 { std::get<0>(id_643) };
                Pointer id_645 { fun642(id_644, ssum_dst_771) };
                Pointer let_res_646;
                {
                  Pointer stup_dst_789 { id_645 };
                  ::dessser::gen::sync_key::t86252e3890668e56d73574e8b879a5b1 id_647 { std::get<3 /* Sources */>(p_0) };
                  std::string id_648 { std::get<1>(id_647) };
                  uint32_t id_649 { (uint32_t)id_648.size() };
                  Vec<1, uint32_t> id_650 {  id_649  };
                  Pointer let_res_651;
                  {
                    Vec<1, uint32_t> leb128_sz_790 { id_650 };
                    Vec<1, Pointer> id_652 {  stup_dst_789  };
                    Pointer let_res_653;
                    {
                      Vec<1, Pointer> leb128_ptr_791 { id_652 };
                      bool while_flag_654 { true };
                      do {
                        uint8_t id_655 { 0 };
                        uint8_t id_656 { 0 };
                        Pointer id_657 { leb128_ptr_791[id_656] };
                        uint32_t id_658 { 128U };
                        uint8_t id_659 { 0 };
                        uint32_t id_660 { leb128_sz_790[id_659] };
                        bool id_661 { bool(id_658 > id_660) };
                        uint8_t choose_res_662;
                        if (id_661) {
                          uint8_t id_663 { 0 };
                          uint32_t id_664 { leb128_sz_790[id_663] };
                          uint8_t id_665 { uint8_t(id_664) };
                          choose_res_662 = id_665;
                        } else {
                          uint8_t id_666 { 0 };
                          uint32_t id_667 { leb128_sz_790[id_666] };
                          uint8_t id_668 { uint8_t(id_667) };
                          uint8_t id_669 { 128 };
                          uint8_t id_670 { uint8_t(id_668 | id_669) };
                          choose_res_662 = id_670;
                        }
                        Pointer id_671 { id_657.writeU8(choose_res_662) };
                        Void id_672 { ((void)(leb128_ptr_791[id_655] = id_671), ::dessser::Void()) };
                        (void)id_672;
                        uint8_t id_673 { 0 };
                        uint8_t id_674 { 0 };
                        uint32_t id_675 { leb128_sz_790[id_674] };
                        uint8_t id_676 { 7 };
                        uint32_t id_677 { uint32_t(id_675 >> id_676) };
                        Void id_678 { ((void)(leb128_sz_790[id_673] = id_677), ::dessser::Void()) };
                        (void)id_678;
                        uint8_t id_679 { 0 };
                        uint32_t id_680 { leb128_sz_790[id_679] };
                        uint32_t id_681 { 0U };
                        bool id_682 { bool(id_680 > id_681) };
                        while_flag_654 = id_682;
                        if (while_flag_654) {
                          (void)::dessser::Void();
                        }
                      } while (while_flag_654);
                      (void)::dessser::Void();
                      uint8_t id_683 { 0 };
                      Pointer id_684 { leb128_ptr_791[id_683] };
                      let_res_653 = id_684;
                    }
                    let_res_651 = let_res_653;
                  }
                  ::dessser::gen::sync_key::t86252e3890668e56d73574e8b879a5b1 id_685 { std::get<3 /* Sources */>(p_0) };
                  std::string id_686 { std::get<1>(id_685) };
                  Bytes id_687 { id_686 };
                  Pointer id_688 { let_res_651.writeBytes(id_687) };
                  let_res_646 = id_688;
                }
                choose_res_641 = let_res_646;
              } else {
                uint16_t id_689 { 4 };
                bool id_690 { bool(id_689 == label1_770) };
                Pointer choose_res_691;
                if (id_690) {
                  choose_res_691 = ssum_dst_771;
                } else {
                  uint16_t id_692 { 5 };
                  bool id_693 { bool(id_692 == label1_770) };
                  Pointer choose_res_694;
                  if (id_693) {
                    ::dessser::gen::sync_key::per_site id_695 { std::get<5 /* PerSite */>(p_0) };
                    Pointer id_696 { per_site_to_row_binary(id_695, ssum_dst_771) };
                    choose_res_694 = id_696;
                  } else {
                    uint16_t id_697 { 6 };
                    bool id_698 { bool(id_697 == label1_770) };
                    Pointer choose_res_699;
                    if (id_698) {
                      ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_700 { std::get<6 /* Storage */>(p_0) };
                      uint16_t id_701 { uint16_t(id_700.index()) };
                      Pointer id_702 { ssum_dst_771.writeU16Le(id_701) };
                      Pointer let_res_703;
                      {
                        Pointer ssum_dst_786 { id_702 };
                        uint16_t id_704 { 0 };
                        ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_705 { std::get<6 /* Storage */>(p_0) };
                        uint16_t id_706 { uint16_t(id_705.index()) };
                        bool id_707 { bool(id_704 == id_706) };
                        Pointer choose_res_708;
                        if (id_707) {
                          choose_res_708 = ssum_dst_786;
                        } else {
                          uint16_t id_709 { 1 };
                          ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_710 { std::get<6 /* Storage */>(p_0) };
                          uint16_t id_711 { uint16_t(id_710.index()) };
                          bool id_712 { bool(id_709 == id_711) };
                          Pointer choose_res_713;
                          if (id_712) {
                            choose_res_713 = ssum_dst_786;
                          } else {
                            ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_714 { std::get<6 /* Storage */>(p_0) };
                            uint16_t id_715 { uint16_t(id_714.index()) };
                            uint16_t id_716 { 2 };
                            bool id_717 { bool(id_715 == id_716) };
                            Void id_718 { ((void)(assert(id_717)), ::dessser::Void()) };
                            (void)id_718;
                            ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_719 { std::get<6 /* Storage */>(p_0) };
                            std::string id_720 { std::get<2 /* RetentionsOverride */>(id_719) };
                            uint32_t id_721 { (uint32_t)id_720.size() };
                            Vec<1, uint32_t> id_722 {  id_721  };
                            Pointer let_res_723;
                            {
                              Vec<1, uint32_t> leb128_sz_787 { id_722 };
                              Vec<1, Pointer> id_724 {  ssum_dst_786  };
                              Pointer let_res_725;
                              {
                                Vec<1, Pointer> leb128_ptr_788 { id_724 };
                                bool while_flag_726 { true };
                                do {
                                  uint8_t id_727 { 0 };
                                  uint8_t id_728 { 0 };
                                  Pointer id_729 { leb128_ptr_788[id_728] };
                                  uint32_t id_730 { 128U };
                                  uint8_t id_731 { 0 };
                                  uint32_t id_732 { leb128_sz_787[id_731] };
                                  bool id_733 { bool(id_730 > id_732) };
                                  uint8_t choose_res_734;
                                  if (id_733) {
                                    uint8_t id_735 { 0 };
                                    uint32_t id_736 { leb128_sz_787[id_735] };
                                    uint8_t id_737 { uint8_t(id_736) };
                                    choose_res_734 = id_737;
                                  } else {
                                    uint8_t id_738 { 0 };
                                    uint32_t id_739 { leb128_sz_787[id_738] };
                                    uint8_t id_740 { uint8_t(id_739) };
                                    uint8_t id_741 { 128 };
                                    uint8_t id_742 { uint8_t(id_740 | id_741) };
                                    choose_res_734 = id_742;
                                  }
                                  Pointer id_743 { id_729.writeU8(choose_res_734) };
                                  Void id_744 { ((void)(leb128_ptr_788[id_727] = id_743), ::dessser::Void()) };
                                  (void)id_744;
                                  uint8_t id_745 { 0 };
                                  uint8_t id_746 { 0 };
                                  uint32_t id_747 { leb128_sz_787[id_746] };
                                  uint8_t id_748 { 7 };
                                  uint32_t id_749 { uint32_t(id_747 >> id_748) };
                                  Void id_750 { ((void)(leb128_sz_787[id_745] = id_749), ::dessser::Void()) };
                                  (void)id_750;
                                  uint8_t id_751 { 0 };
                                  uint32_t id_752 { leb128_sz_787[id_751] };
                                  uint32_t id_753 { 0U };
                                  bool id_754 { bool(id_752 > id_753) };
                                  while_flag_726 = id_754;
                                  if (while_flag_726) {
                                    (void)::dessser::Void();
                                  }
                                } while (while_flag_726);
                                (void)::dessser::Void();
                                uint8_t id_755 { 0 };
                                Pointer id_756 { leb128_ptr_788[id_755] };
                                let_res_725 = id_756;
                              }
                              let_res_723 = let_res_725;
                            }
                            ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_757 { std::get<6 /* Storage */>(p_0) };
                            std::string id_758 { std::get<2 /* RetentionsOverride */>(id_757) };
                            Bytes id_759 { id_758 };
                            Pointer id_760 { let_res_723.writeBytes(id_759) };
                            choose_res_713 = id_760;
                          }
                          choose_res_708 = choose_res_713;
                        }
                        let_res_703 = choose_res_708;
                      }
                      choose_res_699 = let_res_703;
                    } else {
                      uint16_t id_761 { 7 };
                      bool id_762 { bool(id_761 == label1_770) };
                      Pointer choose_res_763;
                      if (id_762) {
                        auto fun764 { dessser::gen::site_name::to_row_binary };
                        ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_765 { std::get<7 /* Tails */>(p_0) };
                        dessser::gen::site_name::t_ext id_766 { std::get<0>(id_765) };
                        Pointer id_767 { fun764(id_766, ssum_dst_771) };
                        Pointer let_res_768;
                        {
                          Pointer stup_dst_780 { id_767 };
                          auto fun769 { dessser::gen::fq_name::to_row_binary };
                          ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_770 { std::get<7 /* Tails */>(p_0) };
                          dessser::gen::fq_name::t_ext id_771 { std::get<1>(id_770) };
                          Pointer id_772 { fun769(id_771, stup_dst_780) };
                          let_res_768 = id_772;
                        }
                        Pointer let_res_773;
                        {
                          Pointer stup_dst_781 { let_res_768 };
                          ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_774 { std::get<7 /* Tails */>(p_0) };
                          std::string id_775 { std::get<2>(id_774) };
                          uint32_t id_776 { (uint32_t)id_775.size() };
                          Vec<1, uint32_t> id_777 {  id_776  };
                          Pointer let_res_778;
                          {
                            Vec<1, uint32_t> leb128_sz_782 { id_777 };
                            Vec<1, Pointer> id_779 {  stup_dst_781  };
                            Pointer let_res_780;
                            {
                              Vec<1, Pointer> leb128_ptr_783 { id_779 };
                              bool while_flag_781 { true };
                              do {
                                uint8_t id_782 { 0 };
                                uint8_t id_783 { 0 };
                                Pointer id_784 { leb128_ptr_783[id_783] };
                                uint32_t id_785 { 128U };
                                uint8_t id_786 { 0 };
                                uint32_t id_787 { leb128_sz_782[id_786] };
                                bool id_788 { bool(id_785 > id_787) };
                                uint8_t choose_res_789;
                                if (id_788) {
                                  uint8_t id_790 { 0 };
                                  uint32_t id_791 { leb128_sz_782[id_790] };
                                  uint8_t id_792 { uint8_t(id_791) };
                                  choose_res_789 = id_792;
                                } else {
                                  uint8_t id_793 { 0 };
                                  uint32_t id_794 { leb128_sz_782[id_793] };
                                  uint8_t id_795 { uint8_t(id_794) };
                                  uint8_t id_796 { 128 };
                                  uint8_t id_797 { uint8_t(id_795 | id_796) };
                                  choose_res_789 = id_797;
                                }
                                Pointer id_798 { id_784.writeU8(choose_res_789) };
                                Void id_799 { ((void)(leb128_ptr_783[id_782] = id_798), ::dessser::Void()) };
                                (void)id_799;
                                uint8_t id_800 { 0 };
                                uint8_t id_801 { 0 };
                                uint32_t id_802 { leb128_sz_782[id_801] };
                                uint8_t id_803 { 7 };
                                uint32_t id_804 { uint32_t(id_802 >> id_803) };
                                Void id_805 { ((void)(leb128_sz_782[id_800] = id_804), ::dessser::Void()) };
                                (void)id_805;
                                uint8_t id_806 { 0 };
                                uint32_t id_807 { leb128_sz_782[id_806] };
                                uint32_t id_808 { 0U };
                                bool id_809 { bool(id_807 > id_808) };
                                while_flag_781 = id_809;
                                if (while_flag_781) {
                                  (void)::dessser::Void();
                                }
                              } while (while_flag_781);
                              (void)::dessser::Void();
                              uint8_t id_810 { 0 };
                              Pointer id_811 { leb128_ptr_783[id_810] };
                              let_res_780 = id_811;
                            }
                            let_res_778 = let_res_780;
                          }
                          ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_812 { std::get<7 /* Tails */>(p_0) };
                          std::string id_813 { std::get<2>(id_812) };
                          Bytes id_814 { id_813 };
                          Pointer id_815 { let_res_778.writeBytes(id_814) };
                          let_res_773 = id_815;
                        }
                        Pointer let_res_816;
                        {
                          Pointer stup_dst_784 { let_res_773 };
                          ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_817 { std::get<7 /* Tails */>(p_0) };
                          ::dessser::gen::sync_key::per_tail id_818 { std::get<3>(id_817) };
                          Pointer id_819 { per_tail_to_row_binary(id_818, stup_dst_784) };
                          let_res_816 = id_819;
                        }
                        choose_res_763 = let_res_816;
                      } else {
                        uint16_t id_820 { 8 };
                        bool id_821 { bool(id_820 == label1_770) };
                        Pointer choose_res_822;
                        if (id_821) {
                          uint16_t id_823 { std::get<8 /* Replays */>(p_0) };
                          Pointer id_824 { ssum_dst_771.writeU16Le(id_823) };
                          choose_res_822 = id_824;
                        } else {
                          uint16_t id_825 { 9 };
                          bool id_826 { bool(id_825 == label1_770) };
                          Pointer choose_res_827;
                          if (id_826) {
                            std::optional<dessser::gen::sync_socket::t_ext> id_828 { std::get<9 /* Error */>(p_0) };
                            bool id_829 { !(id_828.has_value ()) };
                            Pointer choose_res_830;
                            if (id_829) {
                              uint8_t id_831 { 1 };
                              Pointer id_832 { ssum_dst_771.writeU8(id_831) };
                              choose_res_830 = id_832;
                            } else {
                              auto fun833 { dessser::gen::sync_socket::to_row_binary };
                              std::optional<dessser::gen::sync_socket::t_ext> id_834 { std::get<9 /* Error */>(p_0) };
                              dessser::gen::sync_socket::t_ext id_835 { id_834.value() };
                              uint8_t id_836 { 0 };
                              Pointer id_837 { ssum_dst_771.writeU8(id_836) };
                              Pointer id_838 { fun833(id_835, id_837) };
                              choose_res_830 = id_838;
                            }
                            choose_res_827 = choose_res_830;
                          } else {
                            uint16_t id_839 { 10 };
                            bool id_840 { bool(id_839 == label1_770) };
                            Pointer choose_res_841;
                            if (id_840) {
                              choose_res_841 = ssum_dst_771;
                            } else {
                              uint16_t id_842 { 11 };
                              bool id_843 { bool(id_842 == label1_770) };
                              Pointer choose_res_844;
                              if (id_843) {
                                auto fun845 { dessser::gen::sync_socket::to_row_binary };
                                ::dessser::gen::sync_key::t32db4748152e7073f1f93bdcc3c5bff5 id_846 { std::get<11 /* PerClient */>(p_0) };
                                dessser::gen::sync_socket::t_ext id_847 { std::get<0>(id_846) };
                                Pointer id_848 { fun845(id_847, ssum_dst_771) };
                                Pointer let_res_849;
                                {
                                  Pointer stup_dst_779 { id_848 };
                                  ::dessser::gen::sync_key::t32db4748152e7073f1f93bdcc3c5bff5 id_850 { std::get<11 /* PerClient */>(p_0) };
                                  ::dessser::gen::sync_key::per_client id_851 { std::get<1>(id_850) };
                                  Pointer id_852 { per_client_to_row_binary(id_851, stup_dst_779) };
                                  let_res_849 = id_852;
                                }
                                choose_res_844 = let_res_849;
                              } else {
                                uint16_t id_853 { 12 };
                                bool id_854 { bool(id_853 == label1_770) };
                                Pointer choose_res_855;
                                if (id_854) {
                                  ::dessser::gen::sync_key::ta05201a250c67cd2df71e6345b0a4f16 id_856 { std::get<12 /* Dashboards */>(p_0) };
                                  std::string id_857 { std::get<0>(id_856) };
                                  uint32_t id_858 { (uint32_t)id_857.size() };
                                  Vec<1, uint32_t> id_859 {  id_858  };
                                  Pointer let_res_860;
                                  {
                                    Vec<1, uint32_t> leb128_sz_776 { id_859 };
                                    Vec<1, Pointer> id_861 {  ssum_dst_771  };
                                    Pointer let_res_862;
                                    {
                                      Vec<1, Pointer> leb128_ptr_777 { id_861 };
                                      bool while_flag_863 { true };
                                      do {
                                        uint8_t id_864 { 0 };
                                        uint8_t id_865 { 0 };
                                        Pointer id_866 { leb128_ptr_777[id_865] };
                                        uint32_t id_867 { 128U };
                                        uint8_t id_868 { 0 };
                                        uint32_t id_869 { leb128_sz_776[id_868] };
                                        bool id_870 { bool(id_867 > id_869) };
                                        uint8_t choose_res_871;
                                        if (id_870) {
                                          uint8_t id_872 { 0 };
                                          uint32_t id_873 { leb128_sz_776[id_872] };
                                          uint8_t id_874 { uint8_t(id_873) };
                                          choose_res_871 = id_874;
                                        } else {
                                          uint8_t id_875 { 0 };
                                          uint32_t id_876 { leb128_sz_776[id_875] };
                                          uint8_t id_877 { uint8_t(id_876) };
                                          uint8_t id_878 { 128 };
                                          uint8_t id_879 { uint8_t(id_877 | id_878) };
                                          choose_res_871 = id_879;
                                        }
                                        Pointer id_880 { id_866.writeU8(choose_res_871) };
                                        Void id_881 { ((void)(leb128_ptr_777[id_864] = id_880), ::dessser::Void()) };
                                        (void)id_881;
                                        uint8_t id_882 { 0 };
                                        uint8_t id_883 { 0 };
                                        uint32_t id_884 { leb128_sz_776[id_883] };
                                        uint8_t id_885 { 7 };
                                        uint32_t id_886 { uint32_t(id_884 >> id_885) };
                                        Void id_887 { ((void)(leb128_sz_776[id_882] = id_886), ::dessser::Void()) };
                                        (void)id_887;
                                        uint8_t id_888 { 0 };
                                        uint32_t id_889 { leb128_sz_776[id_888] };
                                        uint32_t id_890 { 0U };
                                        bool id_891 { bool(id_889 > id_890) };
                                        while_flag_863 = id_891;
                                        if (while_flag_863) {
                                          (void)::dessser::Void();
                                        }
                                      } while (while_flag_863);
                                      (void)::dessser::Void();
                                      uint8_t id_892 { 0 };
                                      Pointer id_893 { leb128_ptr_777[id_892] };
                                      let_res_862 = id_893;
                                    }
                                    let_res_860 = let_res_862;
                                  }
                                  ::dessser::gen::sync_key::ta05201a250c67cd2df71e6345b0a4f16 id_894 { std::get<12 /* Dashboards */>(p_0) };
                                  std::string id_895 { std::get<0>(id_894) };
                                  Bytes id_896 { id_895 };
                                  Pointer id_897 { let_res_860.writeBytes(id_896) };
                                  Pointer let_res_898;
                                  {
                                    Pointer stup_dst_778 { id_897 };
                                    ::dessser::gen::sync_key::ta05201a250c67cd2df71e6345b0a4f16 id_899 { std::get<12 /* Dashboards */>(p_0) };
                                    std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_900 { std::get<1>(id_899) };
                                    Pointer id_901 { per_dash_key_to_row_binary(id_900, stup_dst_778) };
                                    let_res_898 = id_901;
                                  }
                                  choose_res_855 = let_res_898;
                                } else {
                                  uint16_t id_902 { 13 };
                                  bool id_903 { bool(id_902 == label1_770) };
                                  Pointer choose_res_904;
                                  if (id_903) {
                                    choose_res_904 = ssum_dst_771;
                                  } else {
                                    uint16_t id_905 { 14 };
                                    bool id_906 { bool(id_905 == label1_770) };
                                    Pointer choose_res_907;
                                    if (id_906) {
                                      auto fun908 { dessser::gen::team_name::to_row_binary };
                                      ::dessser::gen::sync_key::t387175c465c261e0af17af4010188b4e id_909 { std::get<14 /* Teams */>(p_0) };
                                      dessser::gen::team_name::t_ext id_910 { id_909.name };
                                      Pointer id_911 { fun908(id_910, ssum_dst_771) };
                                      Pointer let_res_912;
                                      {
                                        Pointer srec_dst_775 { id_911 };
                                        ::dessser::gen::sync_key::t387175c465c261e0af17af4010188b4e id_913 { std::get<14 /* Teams */>(p_0) };
                                        ::dessser::gen::sync_key::team_key_info id_914 { id_913.info };
                                        Pointer id_915 { team_key_info_to_row_binary(id_914, srec_dst_775) };
                                        let_res_912 = id_915;
                                      }
                                      choose_res_907 = let_res_912;
                                    } else {
                                      uint16_t id_916 { 15 };
                                      bool id_917 { bool(label1_770 == id_916) };
                                      Void id_918 { ((void)(assert(id_917)), ::dessser::Void()) };
                                      (void)id_918;
                                      ::dessser::gen::sync_key::t891de542b31fe57e6f8226ed37c952be id_919 { std::get<15 /* Incidents */>(p_0) };
                                      std::string id_920 { std::get<0>(id_919) };
                                      uint32_t id_921 { (uint32_t)id_920.size() };
                                      Vec<1, uint32_t> id_922 {  id_921  };
                                      Pointer let_res_923;
                                      {
                                        Vec<1, uint32_t> leb128_sz_772 { id_922 };
                                        Vec<1, Pointer> id_924 {  ssum_dst_771  };
                                        Pointer let_res_925;
                                        {
                                          Vec<1, Pointer> leb128_ptr_773 { id_924 };
                                          bool while_flag_926 { true };
                                          do {
                                            uint8_t id_927 { 0 };
                                            uint8_t id_928 { 0 };
                                            Pointer id_929 { leb128_ptr_773[id_928] };
                                            uint32_t id_930 { 128U };
                                            uint8_t id_931 { 0 };
                                            uint32_t id_932 { leb128_sz_772[id_931] };
                                            bool id_933 { bool(id_930 > id_932) };
                                            uint8_t choose_res_934;
                                            if (id_933) {
                                              uint8_t id_935 { 0 };
                                              uint32_t id_936 { leb128_sz_772[id_935] };
                                              uint8_t id_937 { uint8_t(id_936) };
                                              choose_res_934 = id_937;
                                            } else {
                                              uint8_t id_938 { 0 };
                                              uint32_t id_939 { leb128_sz_772[id_938] };
                                              uint8_t id_940 { uint8_t(id_939) };
                                              uint8_t id_941 { 128 };
                                              uint8_t id_942 { uint8_t(id_940 | id_941) };
                                              choose_res_934 = id_942;
                                            }
                                            Pointer id_943 { id_929.writeU8(choose_res_934) };
                                            Void id_944 { ((void)(leb128_ptr_773[id_927] = id_943), ::dessser::Void()) };
                                            (void)id_944;
                                            uint8_t id_945 { 0 };
                                            uint8_t id_946 { 0 };
                                            uint32_t id_947 { leb128_sz_772[id_946] };
                                            uint8_t id_948 { 7 };
                                            uint32_t id_949 { uint32_t(id_947 >> id_948) };
                                            Void id_950 { ((void)(leb128_sz_772[id_945] = id_949), ::dessser::Void()) };
                                            (void)id_950;
                                            uint8_t id_951 { 0 };
                                            uint32_t id_952 { leb128_sz_772[id_951] };
                                            uint32_t id_953 { 0U };
                                            bool id_954 { bool(id_952 > id_953) };
                                            while_flag_926 = id_954;
                                            if (while_flag_926) {
                                              (void)::dessser::Void();
                                            }
                                          } while (while_flag_926);
                                          (void)::dessser::Void();
                                          uint8_t id_955 { 0 };
                                          Pointer id_956 { leb128_ptr_773[id_955] };
                                          let_res_925 = id_956;
                                        }
                                        let_res_923 = let_res_925;
                                      }
                                      ::dessser::gen::sync_key::t891de542b31fe57e6f8226ed37c952be id_957 { std::get<15 /* Incidents */>(p_0) };
                                      std::string id_958 { std::get<0>(id_957) };
                                      Bytes id_959 { id_958 };
                                      Pointer id_960 { let_res_923.writeBytes(id_959) };
                                      Pointer let_res_961;
                                      {
                                        Pointer stup_dst_774 { id_960 };
                                        ::dessser::gen::sync_key::t891de542b31fe57e6f8226ed37c952be id_962 { std::get<15 /* Incidents */>(p_0) };
                                        ::dessser::gen::sync_key::incident_key id_963 { std::get<1>(id_962) };
                                        Pointer id_964 { incident_key_to_row_binary(id_963, stup_dst_774) };
                                        let_res_961 = id_964;
                                      }
                                      choose_res_907 = let_res_961;
                                    }
                                    choose_res_904 = choose_res_907;
                                  }
                                  choose_res_855 = choose_res_904;
                                }
                                choose_res_844 = choose_res_855;
                              }
                              choose_res_841 = choose_res_844;
                            }
                            choose_res_827 = choose_res_841;
                          }
                          choose_res_822 = choose_res_827;
                        }
                        choose_res_763 = choose_res_822;
                      }
                      choose_res_699 = choose_res_763;
                    }
                    choose_res_694 = choose_res_699;
                  }
                  choose_res_691 = choose_res_694;
                }
                choose_res_641 = choose_res_691;
              }
              choose_res_598 = choose_res_641;
            }
            choose_res_595 = choose_res_598;
          }
          choose_res_592 = choose_res_595;
        }
        let_res_589 = choose_res_592;
      }
      let_res_587 = let_res_589;
    }
    return let_res_587;
  }
   };
  return fun585;
}
std::function<Pointer(::dessser::gen::sync_key::t &,Pointer &)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0))) (size 2)
          (if (eq (u16 2) (label-of (param 0))) (size 2)
            (if (eq (u16 3) (label-of (param 0))) (size 2) (if (eq (u16 4) (label-of (param 0))) (size 2) (if (eq (u16 5) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 6))) (size 2)))))))))
 */
static std::function<Size(::dessser::gen::sync_key::dialog_key const &)> dialog_key_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::dialog_key const &)> fun965 { [&](::dessser::gen::sync_key::dialog_key p_0) {
    uint16_t id_966 { 0 };
    uint16_t id_967 { uint16_t(p_0.index()) };
    bool id_968 { bool(id_966 == id_967) };
    Size choose_res_969;
    if (id_968) {
      Size id_970 { 2UL };
      choose_res_969 = id_970;
    } else {
      uint16_t id_971 { 1 };
      uint16_t id_972 { uint16_t(p_0.index()) };
      bool id_973 { bool(id_971 == id_972) };
      Size choose_res_974;
      if (id_973) {
        Size id_975 { 2UL };
        choose_res_974 = id_975;
      } else {
        uint16_t id_976 { 2 };
        uint16_t id_977 { uint16_t(p_0.index()) };
        bool id_978 { bool(id_976 == id_977) };
        Size choose_res_979;
        if (id_978) {
          Size id_980 { 2UL };
          choose_res_979 = id_980;
        } else {
          uint16_t id_981 { 3 };
          uint16_t id_982 { uint16_t(p_0.index()) };
          bool id_983 { bool(id_981 == id_982) };
          Size choose_res_984;
          if (id_983) {
            Size id_985 { 2UL };
            choose_res_984 = id_985;
          } else {
            uint16_t id_986 { 4 };
            uint16_t id_987 { uint16_t(p_0.index()) };
            bool id_988 { bool(id_986 == id_987) };
            Size choose_res_989;
            if (id_988) {
              Size id_990 { 2UL };
              choose_res_989 = id_990;
            } else {
              uint16_t id_991 { 5 };
              uint16_t id_992 { uint16_t(p_0.index()) };
              bool id_993 { bool(id_991 == id_992) };
              Size choose_res_994;
              if (id_993) {
                Size id_995 { 2UL };
                choose_res_994 = id_995;
              } else {
                uint16_t id_996 { uint16_t(p_0.index()) };
                uint16_t id_997 { 6 };
                bool id_998 { bool(id_996 == id_997) };
                Void id_999 { ((void)(assert(id_998)), ::dessser::Void()) };
                (void)id_999;
                Size id_1000 { 2UL };
                choose_res_994 = id_1000;
              }
              choose_res_989 = choose_res_994;
            }
            choose_res_984 = choose_res_989;
          }
          choose_res_979 = choose_res_984;
        }
        choose_res_974 = choose_res_979;
      }
      choose_res_969 = choose_res_974;
    }
    return choose_res_969;
  }
   };
  return fun965;
}
std::function<Size(::dessser::gen::sync_key::dialog_key const &)> dialog_key_sersize_of_row_binary(dialog_key_sersize_of_row_binary_init());

/* 
    (fun ("[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0))) (size 2)
          (if (eq (u16 2) (label-of (param 0))) (size 2)
            (if (eq (u16 3) (label-of (param 0))) (size 2)
              (if (eq (u16 4) (label-of (param 0))) (size 2)
                (if (eq (u16 5) (label-of (param 0)))
                  (let "sz_690"
                    (add (size 2)
                      (add
                        (let "n_ref_688" (make-vec (string-length (get-item 0 (get-alt "Dialogs" (param 0)))))
                          (let "lebsz_ref_689" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_688")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_689")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_689") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_689")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_689")))))) 
                        (size-of-u32 (string-length (get-item 0 (get-alt "Dialogs" (param 0))))))) 
                    (add (identifier "sz_690") (apply (identifier "dialog_key-sersize-of-row-binary") (get-item 1 (get-alt "Dialogs" (param 0)))))) 
                  (seq (assert (eq (label-of (param 0)) (u16 6))) (size 14)))))))))
 */
static std::function<Size(::dessser::gen::sync_key::incident_key const &)> incident_key_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::incident_key const &)> fun1001 { [&](::dessser::gen::sync_key::incident_key p_0) {
    uint16_t id_1002 { 0 };
    uint16_t id_1003 { uint16_t(p_0.index()) };
    bool id_1004 { bool(id_1002 == id_1003) };
    Size choose_res_1005;
    if (id_1004) {
      Size id_1006 { 2UL };
      choose_res_1005 = id_1006;
    } else {
      uint16_t id_1007 { 1 };
      uint16_t id_1008 { uint16_t(p_0.index()) };
      bool id_1009 { bool(id_1007 == id_1008) };
      Size choose_res_1010;
      if (id_1009) {
        Size id_1011 { 2UL };
        choose_res_1010 = id_1011;
      } else {
        uint16_t id_1012 { 2 };
        uint16_t id_1013 { uint16_t(p_0.index()) };
        bool id_1014 { bool(id_1012 == id_1013) };
        Size choose_res_1015;
        if (id_1014) {
          Size id_1016 { 2UL };
          choose_res_1015 = id_1016;
        } else {
          uint16_t id_1017 { 3 };
          uint16_t id_1018 { uint16_t(p_0.index()) };
          bool id_1019 { bool(id_1017 == id_1018) };
          Size choose_res_1020;
          if (id_1019) {
            Size id_1021 { 2UL };
            choose_res_1020 = id_1021;
          } else {
            uint16_t id_1022 { 4 };
            uint16_t id_1023 { uint16_t(p_0.index()) };
            bool id_1024 { bool(id_1022 == id_1023) };
            Size choose_res_1025;
            if (id_1024) {
              Size id_1026 { 2UL };
              choose_res_1025 = id_1026;
            } else {
              uint16_t id_1027 { 5 };
              uint16_t id_1028 { uint16_t(p_0.index()) };
              bool id_1029 { bool(id_1027 == id_1028) };
              Size choose_res_1030;
              if (id_1029) {
                Size id_1031 { 2UL };
                ::dessser::gen::sync_key::t0e35f6d3419a3939b7cd57375b12fe4d id_1032 { std::get<5 /* Dialogs */>(p_0) };
                std::string id_1033 { std::get<0>(id_1032) };
                uint32_t id_1034 { (uint32_t)id_1033.size() };
                Vec<1, uint32_t> id_1035 {  id_1034  };
                Size let_res_1036;
                {
                  Vec<1, uint32_t> n_ref_688 { id_1035 };
                  uint32_t id_1037 { 1U };
                  Vec<1, uint32_t> id_1038 {  id_1037  };
                  Size let_res_1039;
                  {
                    Vec<1, uint32_t> lebsz_ref_689 { id_1038 };
                    bool while_flag_1040 { true };
                    do {
                      uint8_t id_1041 { 0 };
                      uint32_t id_1042 { n_ref_688[id_1041] };
                      uint8_t id_1043 { 0 };
                      uint32_t id_1044 { lebsz_ref_689[id_1043] };
                      uint8_t id_1045 { 7 };
                      uint32_t id_1046 { uint32_t(id_1044 << id_1045) };
                      bool id_1047 { bool(id_1042 >= id_1046) };
                      while_flag_1040 = id_1047;
                      if (while_flag_1040) {
                        uint8_t id_1048 { 0 };
                        uint8_t id_1049 { 0 };
                        uint32_t id_1050 { lebsz_ref_689[id_1049] };
                        uint32_t id_1051 { 1U };
                        uint32_t id_1052 { uint32_t(id_1050 + id_1051) };
                        Void id_1053 { ((void)(lebsz_ref_689[id_1048] = id_1052), ::dessser::Void()) };
                        (void)id_1053;
                      }
                    } while (while_flag_1040);
                    (void)::dessser::Void();
                    uint8_t id_1054 { 0 };
                    uint32_t id_1055 { lebsz_ref_689[id_1054] };
                    Size id_1056 { Size(id_1055) };
                    let_res_1039 = id_1056;
                  }
                  let_res_1036 = let_res_1039;
                }
                ::dessser::gen::sync_key::t0e35f6d3419a3939b7cd57375b12fe4d id_1057 { std::get<5 /* Dialogs */>(p_0) };
                std::string id_1058 { std::get<0>(id_1057) };
                uint32_t id_1059 { (uint32_t)id_1058.size() };
                Size id_1060 { Size(id_1059) };
                Size id_1061 { Size(let_res_1036 + id_1060) };
                Size id_1062 { Size(id_1031 + id_1061) };
                Size let_res_1063;
                {
                  Size sz_690 { id_1062 };
                  ::dessser::gen::sync_key::t0e35f6d3419a3939b7cd57375b12fe4d id_1064 { std::get<5 /* Dialogs */>(p_0) };
                  ::dessser::gen::sync_key::dialog_key id_1065 { std::get<1>(id_1064) };
                  Size id_1066 { dialog_key_sersize_of_row_binary(id_1065) };
                  Size id_1067 { Size(sz_690 + id_1066) };
                  let_res_1063 = id_1067;
                }
                choose_res_1030 = let_res_1063;
              } else {
                uint16_t id_1068 { uint16_t(p_0.index()) };
                uint16_t id_1069 { 6 };
                bool id_1070 { bool(id_1068 == id_1069) };
                Void id_1071 { ((void)(assert(id_1070)), ::dessser::Void()) };
                (void)id_1071;
                Size id_1072 { 14UL };
                choose_res_1030 = id_1072;
              }
              choose_res_1025 = choose_res_1030;
            }
            choose_res_1020 = choose_res_1025;
          }
          choose_res_1015 = choose_res_1020;
        }
        choose_res_1010 = choose_res_1015;
      }
      choose_res_1005 = choose_res_1010;
    }
    return choose_res_1005;
  }
   };
  return fun1001;
}
std::function<Size(::dessser::gen::sync_key::incident_key const &)> incident_key_sersize_of_row_binary(incident_key_sersize_of_row_binary_init());

/* 
    (fun ("[Contacts STRING | Inhibition STRING]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_680" (make-vec (string-length (get-alt "Contacts" (param 0))))
              (let "lebsz_ref_681" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_680")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_681")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_681") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_681")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_681")))))) 
            (size-of-u32 (string-length (get-alt "Contacts" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1)))
          (add (size 2)
            (add
              (let "n_ref_677" (make-vec (string-length (get-alt "Inhibition" (param 0))))
                (let "lebsz_ref_678" (make-vec (u32 1))
                  (seq
                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_677")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_678")) (u8 7)))
                      (set-vec (u8 0) (identifier "lebsz_ref_678") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_678")) (u32 1)))) 
                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_678")))))) 
              (size-of-u32 (string-length (get-alt "Inhibition" (param 0)))))))))
 */
static std::function<Size(::dessser::gen::sync_key::team_key_info const &)> team_key_info_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::team_key_info const &)> fun1073 { [&](::dessser::gen::sync_key::team_key_info p_0) {
    uint16_t id_1074 { 0 };
    uint16_t id_1075 { uint16_t(p_0.index()) };
    bool id_1076 { bool(id_1074 == id_1075) };
    Size choose_res_1077;
    if (id_1076) {
      Size id_1078 { 2UL };
      std::string id_1079 { std::get<0 /* Contacts */>(p_0) };
      uint32_t id_1080 { (uint32_t)id_1079.size() };
      Vec<1, uint32_t> id_1081 {  id_1080  };
      Size let_res_1082;
      {
        Vec<1, uint32_t> n_ref_680 { id_1081 };
        uint32_t id_1083 { 1U };
        Vec<1, uint32_t> id_1084 {  id_1083  };
        Size let_res_1085;
        {
          Vec<1, uint32_t> lebsz_ref_681 { id_1084 };
          bool while_flag_1086 { true };
          do {
            uint8_t id_1087 { 0 };
            uint32_t id_1088 { n_ref_680[id_1087] };
            uint8_t id_1089 { 0 };
            uint32_t id_1090 { lebsz_ref_681[id_1089] };
            uint8_t id_1091 { 7 };
            uint32_t id_1092 { uint32_t(id_1090 << id_1091) };
            bool id_1093 { bool(id_1088 >= id_1092) };
            while_flag_1086 = id_1093;
            if (while_flag_1086) {
              uint8_t id_1094 { 0 };
              uint8_t id_1095 { 0 };
              uint32_t id_1096 { lebsz_ref_681[id_1095] };
              uint32_t id_1097 { 1U };
              uint32_t id_1098 { uint32_t(id_1096 + id_1097) };
              Void id_1099 { ((void)(lebsz_ref_681[id_1094] = id_1098), ::dessser::Void()) };
              (void)id_1099;
            }
          } while (while_flag_1086);
          (void)::dessser::Void();
          uint8_t id_1100 { 0 };
          uint32_t id_1101 { lebsz_ref_681[id_1100] };
          Size id_1102 { Size(id_1101) };
          let_res_1085 = id_1102;
        }
        let_res_1082 = let_res_1085;
      }
      std::string id_1103 { std::get<0 /* Contacts */>(p_0) };
      uint32_t id_1104 { (uint32_t)id_1103.size() };
      Size id_1105 { Size(id_1104) };
      Size id_1106 { Size(let_res_1082 + id_1105) };
      Size id_1107 { Size(id_1078 + id_1106) };
      choose_res_1077 = id_1107;
    } else {
      uint16_t id_1108 { uint16_t(p_0.index()) };
      uint16_t id_1109 { 1 };
      bool id_1110 { bool(id_1108 == id_1109) };
      Void id_1111 { ((void)(assert(id_1110)), ::dessser::Void()) };
      (void)id_1111;
      Size id_1112 { 2UL };
      std::string id_1113 { std::get<1 /* Inhibition */>(p_0) };
      uint32_t id_1114 { (uint32_t)id_1113.size() };
      Vec<1, uint32_t> id_1115 {  id_1114  };
      Size let_res_1116;
      {
        Vec<1, uint32_t> n_ref_677 { id_1115 };
        uint32_t id_1117 { 1U };
        Vec<1, uint32_t> id_1118 {  id_1117  };
        Size let_res_1119;
        {
          Vec<1, uint32_t> lebsz_ref_678 { id_1118 };
          bool while_flag_1120 { true };
          do {
            uint8_t id_1121 { 0 };
            uint32_t id_1122 { n_ref_677[id_1121] };
            uint8_t id_1123 { 0 };
            uint32_t id_1124 { lebsz_ref_678[id_1123] };
            uint8_t id_1125 { 7 };
            uint32_t id_1126 { uint32_t(id_1124 << id_1125) };
            bool id_1127 { bool(id_1122 >= id_1126) };
            while_flag_1120 = id_1127;
            if (while_flag_1120) {
              uint8_t id_1128 { 0 };
              uint8_t id_1129 { 0 };
              uint32_t id_1130 { lebsz_ref_678[id_1129] };
              uint32_t id_1131 { 1U };
              uint32_t id_1132 { uint32_t(id_1130 + id_1131) };
              Void id_1133 { ((void)(lebsz_ref_678[id_1128] = id_1132), ::dessser::Void()) };
              (void)id_1133;
            }
          } while (while_flag_1120);
          (void)::dessser::Void();
          uint8_t id_1134 { 0 };
          uint32_t id_1135 { lebsz_ref_678[id_1134] };
          Size id_1136 { Size(id_1135) };
          let_res_1119 = id_1136;
        }
        let_res_1116 = let_res_1119;
      }
      std::string id_1137 { std::get<1 /* Inhibition */>(p_0) };
      uint32_t id_1138 { (uint32_t)id_1137.size() };
      Size id_1139 { Size(id_1138) };
      Size id_1140 { Size(let_res_1116 + id_1139) };
      Size id_1141 { Size(id_1112 + id_1140) };
      choose_res_1077 = id_1141;
    }
    return choose_res_1077;
  }
   };
  return fun1073;
}
std::function<Size(::dessser::gen::sync_key::team_key_info const &)> team_key_info_sersize_of_row_binary(team_key_info_sersize_of_row_binary_init());

/* 
    (fun ("[Widgets U32]") (seq (assert (eq (label-of (param 0)) (u16 0))) (size 6)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  const &)> per_dash_key_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  const &)> fun1142 { [&](std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  p_0) {
    uint16_t id_1143 { uint16_t((*p_0).index()) };
    uint16_t id_1144 { 0 };
    bool id_1145 { bool(id_1143 == id_1144) };
    Void id_1146 { ((void)(assert(id_1145)), ::dessser::Void()) };
    (void)id_1146;
    Size id_1147 { 6UL };
    return id_1147;
  }
   };
  return fun1142;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  const &)> per_dash_key_sersize_of_row_binary(per_dash_key_sersize_of_row_binary_init());

/* 
    (fun ("[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_673" (make-vec (string-length (get-alt "Response" (param 0))))
              (let "lebsz_ref_674" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_673")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_674")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_674") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_674")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_674")))))) 
            (size-of-u32 (string-length (get-alt "Response" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "per_dash_key-sersize-of-row-binary") (get-alt "Scratchpad" (param 0)))))))
 */
static std::function<Size(::dessser::gen::sync_key::per_client const &)> per_client_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::per_client const &)> fun1148 { [&](::dessser::gen::sync_key::per_client p_0) {
    uint16_t id_1149 { 0 };
    uint16_t id_1150 { uint16_t(p_0.index()) };
    bool id_1151 { bool(id_1149 == id_1150) };
    Size choose_res_1152;
    if (id_1151) {
      Size id_1153 { 2UL };
      std::string id_1154 { std::get<0 /* Response */>(p_0) };
      uint32_t id_1155 { (uint32_t)id_1154.size() };
      Vec<1, uint32_t> id_1156 {  id_1155  };
      Size let_res_1157;
      {
        Vec<1, uint32_t> n_ref_673 { id_1156 };
        uint32_t id_1158 { 1U };
        Vec<1, uint32_t> id_1159 {  id_1158  };
        Size let_res_1160;
        {
          Vec<1, uint32_t> lebsz_ref_674 { id_1159 };
          bool while_flag_1161 { true };
          do {
            uint8_t id_1162 { 0 };
            uint32_t id_1163 { n_ref_673[id_1162] };
            uint8_t id_1164 { 0 };
            uint32_t id_1165 { lebsz_ref_674[id_1164] };
            uint8_t id_1166 { 7 };
            uint32_t id_1167 { uint32_t(id_1165 << id_1166) };
            bool id_1168 { bool(id_1163 >= id_1167) };
            while_flag_1161 = id_1168;
            if (while_flag_1161) {
              uint8_t id_1169 { 0 };
              uint8_t id_1170 { 0 };
              uint32_t id_1171 { lebsz_ref_674[id_1170] };
              uint32_t id_1172 { 1U };
              uint32_t id_1173 { uint32_t(id_1171 + id_1172) };
              Void id_1174 { ((void)(lebsz_ref_674[id_1169] = id_1173), ::dessser::Void()) };
              (void)id_1174;
            }
          } while (while_flag_1161);
          (void)::dessser::Void();
          uint8_t id_1175 { 0 };
          uint32_t id_1176 { lebsz_ref_674[id_1175] };
          Size id_1177 { Size(id_1176) };
          let_res_1160 = id_1177;
        }
        let_res_1157 = let_res_1160;
      }
      std::string id_1178 { std::get<0 /* Response */>(p_0) };
      uint32_t id_1179 { (uint32_t)id_1178.size() };
      Size id_1180 { Size(id_1179) };
      Size id_1181 { Size(let_res_1157 + id_1180) };
      Size id_1182 { Size(id_1153 + id_1181) };
      choose_res_1152 = id_1182;
    } else {
      uint16_t id_1183 { uint16_t(p_0.index()) };
      uint16_t id_1184 { 1 };
      bool id_1185 { bool(id_1183 == id_1184) };
      Void id_1186 { ((void)(assert(id_1185)), ::dessser::Void()) };
      (void)id_1186;
      Size id_1187 { 2UL };
      std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1188 { std::get<1 /* Scratchpad */>(p_0) };
      Size id_1189 { per_dash_key_sersize_of_row_binary(id_1188) };
      Size id_1190 { Size(id_1187 + id_1189) };
      choose_res_1152 = id_1190;
    }
    return choose_res_1152;
  }
   };
  return fun1148;
}
std::function<Size(::dessser::gen::sync_key::per_client const &)> per_client_sersize_of_row_binary(per_client_sersize_of_row_binary_init());

/* 
    (fun ("[Subscriber STRING | LastTuple U32]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_668" (make-vec (string-length (get-alt "Subscriber" (param 0))))
              (let "lebsz_ref_669" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_668")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_669")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_669") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_669")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_669")))))) 
            (size-of-u32 (string-length (get-alt "Subscriber" (param 0)))))) 
        (seq (assert (eq (label-of (param 0)) (u16 1))) (size 6))))
 */
static std::function<Size(::dessser::gen::sync_key::per_tail const &)> per_tail_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::per_tail const &)> fun1191 { [&](::dessser::gen::sync_key::per_tail p_0) {
    uint16_t id_1192 { 0 };
    uint16_t id_1193 { uint16_t(p_0.index()) };
    bool id_1194 { bool(id_1192 == id_1193) };
    Size choose_res_1195;
    if (id_1194) {
      Size id_1196 { 2UL };
      std::string id_1197 { std::get<0 /* Subscriber */>(p_0) };
      uint32_t id_1198 { (uint32_t)id_1197.size() };
      Vec<1, uint32_t> id_1199 {  id_1198  };
      Size let_res_1200;
      {
        Vec<1, uint32_t> n_ref_668 { id_1199 };
        uint32_t id_1201 { 1U };
        Vec<1, uint32_t> id_1202 {  id_1201  };
        Size let_res_1203;
        {
          Vec<1, uint32_t> lebsz_ref_669 { id_1202 };
          bool while_flag_1204 { true };
          do {
            uint8_t id_1205 { 0 };
            uint32_t id_1206 { n_ref_668[id_1205] };
            uint8_t id_1207 { 0 };
            uint32_t id_1208 { lebsz_ref_669[id_1207] };
            uint8_t id_1209 { 7 };
            uint32_t id_1210 { uint32_t(id_1208 << id_1209) };
            bool id_1211 { bool(id_1206 >= id_1210) };
            while_flag_1204 = id_1211;
            if (while_flag_1204) {
              uint8_t id_1212 { 0 };
              uint8_t id_1213 { 0 };
              uint32_t id_1214 { lebsz_ref_669[id_1213] };
              uint32_t id_1215 { 1U };
              uint32_t id_1216 { uint32_t(id_1214 + id_1215) };
              Void id_1217 { ((void)(lebsz_ref_669[id_1212] = id_1216), ::dessser::Void()) };
              (void)id_1217;
            }
          } while (while_flag_1204);
          (void)::dessser::Void();
          uint8_t id_1218 { 0 };
          uint32_t id_1219 { lebsz_ref_669[id_1218] };
          Size id_1220 { Size(id_1219) };
          let_res_1203 = id_1220;
        }
        let_res_1200 = let_res_1203;
      }
      std::string id_1221 { std::get<0 /* Subscriber */>(p_0) };
      uint32_t id_1222 { (uint32_t)id_1221.size() };
      Size id_1223 { Size(id_1222) };
      Size id_1224 { Size(let_res_1200 + id_1223) };
      Size id_1225 { Size(id_1196 + id_1224) };
      choose_res_1195 = id_1225;
    } else {
      uint16_t id_1226 { uint16_t(p_0.index()) };
      uint16_t id_1227 { 1 };
      bool id_1228 { bool(id_1226 == id_1227) };
      Void id_1229 { ((void)(assert(id_1228)), ::dessser::Void()) };
      (void)id_1229;
      Size id_1230 { 6UL };
      choose_res_1195 = id_1230;
    }
    return choose_res_1195;
  }
   };
  return fun1191;
}
std::function<Size(::dessser::gen::sync_key::per_tail const &)> per_tail_sersize_of_row_binary(per_tail_sersize_of_row_binary_init());

/* 
    (fun ("[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0))) (size 2)
          (if (eq (u16 2) (label-of (param 0))) (size 2)
            (if (eq (u16 3) (label-of (param 0))) (size 2)
              (if (eq (u16 4) (label-of (param 0))) (size 2)
                (if (eq (u16 5) (label-of (param 0))) (size 2)
                  (if (eq (u16 6) (label-of (param 0)))
                    (let "sz_647"
                      (add (size 2)
                        (add
                          (let "n_ref_645" (make-vec (string-length (get-item 0 (get-alt "PerInstance" (param 0)))))
                            (let "lebsz_ref_646" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_645")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_646")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_646") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_646")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_646")))))) 
                          (size-of-u32 (string-length (get-item 0 (get-alt "PerInstance" (param 0)))))))
                      (let "label2_648" (label-of (get-item 1 (get-alt "PerInstance" (param 0))))
                        (if (eq (u16 0) (identifier "label2_648")) (add (identifier "sz_647") (size 2))
                          (if (eq (u16 1) (identifier "label2_648")) 
                            (add (identifier "sz_647") (size 2))
                            (if (eq (u16 2) (identifier "label2_648")) 
                              (add (identifier "sz_647") (size 2))
                              (if (eq (u16 3) (identifier "label2_648")) 
                                (add (identifier "sz_647") (size 2))
                                (if (eq (u16 4) (identifier "label2_648")) 
                                  (add (identifier "sz_647") (size 2))
                                  (if (eq (u16 5) (identifier "label2_648")) 
                                    (add (identifier "sz_647") (size 2))
                                    (if (eq (u16 6) (identifier "label2_648")) (add (identifier "sz_647") (size 2)) (seq (assert (eq (identifier "label2_648") (u16 7))) (add (identifier "sz_647") (size 2))))))))))))
                    (if (eq (u16 7) (label-of (param 0))) (size 6) (seq (assert (eq (label-of (param 0)) (u16 8))) (size 2)))))))))))
 */
static std::function<Size(::dessser::gen::sync_key::per_worker_data const &)> per_worker_data_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::per_worker_data const &)> fun1231 { [&](::dessser::gen::sync_key::per_worker_data p_0) {
    uint16_t id_1232 { 0 };
    uint16_t id_1233 { uint16_t(p_0.index()) };
    bool id_1234 { bool(id_1232 == id_1233) };
    Size choose_res_1235;
    if (id_1234) {
      Size id_1236 { 2UL };
      choose_res_1235 = id_1236;
    } else {
      uint16_t id_1237 { 1 };
      uint16_t id_1238 { uint16_t(p_0.index()) };
      bool id_1239 { bool(id_1237 == id_1238) };
      Size choose_res_1240;
      if (id_1239) {
        Size id_1241 { 2UL };
        choose_res_1240 = id_1241;
      } else {
        uint16_t id_1242 { 2 };
        uint16_t id_1243 { uint16_t(p_0.index()) };
        bool id_1244 { bool(id_1242 == id_1243) };
        Size choose_res_1245;
        if (id_1244) {
          Size id_1246 { 2UL };
          choose_res_1245 = id_1246;
        } else {
          uint16_t id_1247 { 3 };
          uint16_t id_1248 { uint16_t(p_0.index()) };
          bool id_1249 { bool(id_1247 == id_1248) };
          Size choose_res_1250;
          if (id_1249) {
            Size id_1251 { 2UL };
            choose_res_1250 = id_1251;
          } else {
            uint16_t id_1252 { 4 };
            uint16_t id_1253 { uint16_t(p_0.index()) };
            bool id_1254 { bool(id_1252 == id_1253) };
            Size choose_res_1255;
            if (id_1254) {
              Size id_1256 { 2UL };
              choose_res_1255 = id_1256;
            } else {
              uint16_t id_1257 { 5 };
              uint16_t id_1258 { uint16_t(p_0.index()) };
              bool id_1259 { bool(id_1257 == id_1258) };
              Size choose_res_1260;
              if (id_1259) {
                Size id_1261 { 2UL };
                choose_res_1260 = id_1261;
              } else {
                uint16_t id_1262 { 6 };
                uint16_t id_1263 { uint16_t(p_0.index()) };
                bool id_1264 { bool(id_1262 == id_1263) };
                Size choose_res_1265;
                if (id_1264) {
                  Size id_1266 { 2UL };
                  ::dessser::gen::sync_key::ta7e4a6f84fc41fdc68e99605bbb0a0c8 id_1267 { std::get<6 /* PerInstance */>(p_0) };
                  std::string id_1268 { std::get<0>(id_1267) };
                  uint32_t id_1269 { (uint32_t)id_1268.size() };
                  Vec<1, uint32_t> id_1270 {  id_1269  };
                  Size let_res_1271;
                  {
                    Vec<1, uint32_t> n_ref_645 { id_1270 };
                    uint32_t id_1272 { 1U };
                    Vec<1, uint32_t> id_1273 {  id_1272  };
                    Size let_res_1274;
                    {
                      Vec<1, uint32_t> lebsz_ref_646 { id_1273 };
                      bool while_flag_1275 { true };
                      do {
                        uint8_t id_1276 { 0 };
                        uint32_t id_1277 { n_ref_645[id_1276] };
                        uint8_t id_1278 { 0 };
                        uint32_t id_1279 { lebsz_ref_646[id_1278] };
                        uint8_t id_1280 { 7 };
                        uint32_t id_1281 { uint32_t(id_1279 << id_1280) };
                        bool id_1282 { bool(id_1277 >= id_1281) };
                        while_flag_1275 = id_1282;
                        if (while_flag_1275) {
                          uint8_t id_1283 { 0 };
                          uint8_t id_1284 { 0 };
                          uint32_t id_1285 { lebsz_ref_646[id_1284] };
                          uint32_t id_1286 { 1U };
                          uint32_t id_1287 { uint32_t(id_1285 + id_1286) };
                          Void id_1288 { ((void)(lebsz_ref_646[id_1283] = id_1287), ::dessser::Void()) };
                          (void)id_1288;
                        }
                      } while (while_flag_1275);
                      (void)::dessser::Void();
                      uint8_t id_1289 { 0 };
                      uint32_t id_1290 { lebsz_ref_646[id_1289] };
                      Size id_1291 { Size(id_1290) };
                      let_res_1274 = id_1291;
                    }
                    let_res_1271 = let_res_1274;
                  }
                  ::dessser::gen::sync_key::ta7e4a6f84fc41fdc68e99605bbb0a0c8 id_1292 { std::get<6 /* PerInstance */>(p_0) };
                  std::string id_1293 { std::get<0>(id_1292) };
                  uint32_t id_1294 { (uint32_t)id_1293.size() };
                  Size id_1295 { Size(id_1294) };
                  Size id_1296 { Size(let_res_1271 + id_1295) };
                  Size id_1297 { Size(id_1266 + id_1296) };
                  Size let_res_1298;
                  {
                    Size sz_647 { id_1297 };
                    ::dessser::gen::sync_key::ta7e4a6f84fc41fdc68e99605bbb0a0c8 id_1299 { std::get<6 /* PerInstance */>(p_0) };
                    ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_1300 { std::get<1>(id_1299) };
                    uint16_t id_1301 { uint16_t(id_1300.index()) };
                    Size let_res_1302;
                    {
                      uint16_t label2_648 { id_1301 };
                      uint16_t id_1303 { 0 };
                      bool id_1304 { bool(id_1303 == label2_648) };
                      Size choose_res_1305;
                      if (id_1304) {
                        Size id_1306 { 2UL };
                        Size id_1307 { Size(sz_647 + id_1306) };
                        choose_res_1305 = id_1307;
                      } else {
                        uint16_t id_1308 { 1 };
                        bool id_1309 { bool(id_1308 == label2_648) };
                        Size choose_res_1310;
                        if (id_1309) {
                          Size id_1311 { 2UL };
                          Size id_1312 { Size(sz_647 + id_1311) };
                          choose_res_1310 = id_1312;
                        } else {
                          uint16_t id_1313 { 2 };
                          bool id_1314 { bool(id_1313 == label2_648) };
                          Size choose_res_1315;
                          if (id_1314) {
                            Size id_1316 { 2UL };
                            Size id_1317 { Size(sz_647 + id_1316) };
                            choose_res_1315 = id_1317;
                          } else {
                            uint16_t id_1318 { 3 };
                            bool id_1319 { bool(id_1318 == label2_648) };
                            Size choose_res_1320;
                            if (id_1319) {
                              Size id_1321 { 2UL };
                              Size id_1322 { Size(sz_647 + id_1321) };
                              choose_res_1320 = id_1322;
                            } else {
                              uint16_t id_1323 { 4 };
                              bool id_1324 { bool(id_1323 == label2_648) };
                              Size choose_res_1325;
                              if (id_1324) {
                                Size id_1326 { 2UL };
                                Size id_1327 { Size(sz_647 + id_1326) };
                                choose_res_1325 = id_1327;
                              } else {
                                uint16_t id_1328 { 5 };
                                bool id_1329 { bool(id_1328 == label2_648) };
                                Size choose_res_1330;
                                if (id_1329) {
                                  Size id_1331 { 2UL };
                                  Size id_1332 { Size(sz_647 + id_1331) };
                                  choose_res_1330 = id_1332;
                                } else {
                                  uint16_t id_1333 { 6 };
                                  bool id_1334 { bool(id_1333 == label2_648) };
                                  Size choose_res_1335;
                                  if (id_1334) {
                                    Size id_1336 { 2UL };
                                    Size id_1337 { Size(sz_647 + id_1336) };
                                    choose_res_1335 = id_1337;
                                  } else {
                                    uint16_t id_1338 { 7 };
                                    bool id_1339 { bool(label2_648 == id_1338) };
                                    Void id_1340 { ((void)(assert(id_1339)), ::dessser::Void()) };
                                    (void)id_1340;
                                    Size id_1341 { 2UL };
                                    Size id_1342 { Size(sz_647 + id_1341) };
                                    choose_res_1335 = id_1342;
                                  }
                                  choose_res_1330 = choose_res_1335;
                                }
                                choose_res_1325 = choose_res_1330;
                              }
                              choose_res_1320 = choose_res_1325;
                            }
                            choose_res_1315 = choose_res_1320;
                          }
                          choose_res_1310 = choose_res_1315;
                        }
                        choose_res_1305 = choose_res_1310;
                      }
                      let_res_1302 = choose_res_1305;
                    }
                    let_res_1298 = let_res_1302;
                  }
                  choose_res_1265 = let_res_1298;
                } else {
                  uint16_t id_1343 { 7 };
                  uint16_t id_1344 { uint16_t(p_0.index()) };
                  bool id_1345 { bool(id_1343 == id_1344) };
                  Size choose_res_1346;
                  if (id_1345) {
                    Size id_1347 { 6UL };
                    choose_res_1346 = id_1347;
                  } else {
                    uint16_t id_1348 { uint16_t(p_0.index()) };
                    uint16_t id_1349 { 8 };
                    bool id_1350 { bool(id_1348 == id_1349) };
                    Void id_1351 { ((void)(assert(id_1350)), ::dessser::Void()) };
                    (void)id_1351;
                    Size id_1352 { 2UL };
                    choose_res_1346 = id_1352;
                  }
                  choose_res_1265 = choose_res_1346;
                }
                choose_res_1260 = choose_res_1265;
              }
              choose_res_1255 = choose_res_1260;
            }
            choose_res_1250 = choose_res_1255;
          }
          choose_res_1245 = choose_res_1250;
        }
        choose_res_1240 = choose_res_1245;
      }
      choose_res_1235 = choose_res_1240;
    }
    return choose_res_1235;
  }
   };
  return fun1231;
}
std::function<Size(::dessser::gen::sync_key::per_worker_data const &)> per_worker_data_sersize_of_row_binary(per_worker_data_sersize_of_row_binary_init());

/* 
    (fun ("($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))")
      (let "sz_650" (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 0 (param 0))) (add (identifier "sz_650") (apply (identifier "per_worker_data-sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(::dessser::gen::sync_key::per_worker &)> per_worker_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::per_worker &)> fun1353 { [&](::dessser::gen::sync_key::per_worker p_0) {
    auto fun1354 { dessser::gen::fq_name::sersize_of_row_binary };
    dessser::gen::fq_name::t_ext id_1355 { std::get<0>(p_0) };
    Size id_1356 { fun1354(id_1355) };
    Size let_res_1357;
    {
      Size sz_650 { id_1356 };
      ::dessser::gen::sync_key::per_worker_data id_1358 { std::get<1>(p_0) };
      Size id_1359 { per_worker_data_sersize_of_row_binary(id_1358) };
      Size id_1360 { Size(sz_650 + id_1359) };
      let_res_1357 = id_1360;
    }
    return let_res_1357;
  }
   };
  return fun1353;
}
std::function<Size(::dessser::gen::sync_key::per_worker &)> per_worker_sersize_of_row_binary(per_worker_sersize_of_row_binary_init());

/* 
    (fun ("[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0)))
          (let "sz_662"
            (add (size 2)
              (add
                (let "n_ref_660" (make-vec (string-length (get-item 0 (get-alt "PerService" (param 0)))))
                  (let "lebsz_ref_661" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_660")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_661")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_661") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_661")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_661")))))) 
                (size-of-u32 (string-length (get-item 0 (get-alt "PerService" (param 0)))))))
            (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (param 0))))) 
              (add (identifier "sz_662") (size 2)) (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (param 0)))) (u16 1))) (add (identifier "sz_662") (size 2)))))
          (if (eq (u16 2) (label-of (param 0))) (add (size 2) (apply (identifier "per_worker-sersize-of-row-binary") (get-alt "PerWorker" (param 0))))
            (seq (assert (eq (label-of (param 0)) (u16 3)))
              (let "sz_656"
                (add (size 2)
                  (add
                    (let "n_ref_654" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (param 0)))))
                      (let "lebsz_ref_655" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_654")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_655")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_655") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_655")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_655")))))) 
                    (size-of-u32 (string-length (get-item 0 (get-alt "PerProgram" (param 0))))))) 
                (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (param 0)))) (u16 0))) (add (identifier "sz_656") (size 2)))))))))
 */
static std::function<Size(::dessser::gen::sync_key::per_site_data &)> per_site_data_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::per_site_data &)> fun1361 { [&](::dessser::gen::sync_key::per_site_data p_0) {
    uint16_t id_1362 { 0 };
    uint16_t id_1363 { uint16_t(p_0.index()) };
    bool id_1364 { bool(id_1362 == id_1363) };
    Size choose_res_1365;
    if (id_1364) {
      Size id_1366 { 2UL };
      choose_res_1365 = id_1366;
    } else {
      uint16_t id_1367 { 1 };
      uint16_t id_1368 { uint16_t(p_0.index()) };
      bool id_1369 { bool(id_1367 == id_1368) };
      Size choose_res_1370;
      if (id_1369) {
        Size id_1371 { 2UL };
        ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98 id_1372 { std::get<1 /* PerService */>(p_0) };
        std::string id_1373 { std::get<0>(id_1372) };
        uint32_t id_1374 { (uint32_t)id_1373.size() };
        Vec<1, uint32_t> id_1375 {  id_1374  };
        Size let_res_1376;
        {
          Vec<1, uint32_t> n_ref_660 { id_1375 };
          uint32_t id_1377 { 1U };
          Vec<1, uint32_t> id_1378 {  id_1377  };
          Size let_res_1379;
          {
            Vec<1, uint32_t> lebsz_ref_661 { id_1378 };
            bool while_flag_1380 { true };
            do {
              uint8_t id_1381 { 0 };
              uint32_t id_1382 { n_ref_660[id_1381] };
              uint8_t id_1383 { 0 };
              uint32_t id_1384 { lebsz_ref_661[id_1383] };
              uint8_t id_1385 { 7 };
              uint32_t id_1386 { uint32_t(id_1384 << id_1385) };
              bool id_1387 { bool(id_1382 >= id_1386) };
              while_flag_1380 = id_1387;
              if (while_flag_1380) {
                uint8_t id_1388 { 0 };
                uint8_t id_1389 { 0 };
                uint32_t id_1390 { lebsz_ref_661[id_1389] };
                uint32_t id_1391 { 1U };
                uint32_t id_1392 { uint32_t(id_1390 + id_1391) };
                Void id_1393 { ((void)(lebsz_ref_661[id_1388] = id_1392), ::dessser::Void()) };
                (void)id_1393;
              }
            } while (while_flag_1380);
            (void)::dessser::Void();
            uint8_t id_1394 { 0 };
            uint32_t id_1395 { lebsz_ref_661[id_1394] };
            Size id_1396 { Size(id_1395) };
            let_res_1379 = id_1396;
          }
          let_res_1376 = let_res_1379;
        }
        ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98 id_1397 { std::get<1 /* PerService */>(p_0) };
        std::string id_1398 { std::get<0>(id_1397) };
        uint32_t id_1399 { (uint32_t)id_1398.size() };
        Size id_1400 { Size(id_1399) };
        Size id_1401 { Size(let_res_1376 + id_1400) };
        Size id_1402 { Size(id_1371 + id_1401) };
        Size let_res_1403;
        {
          Size sz_662 { id_1402 };
          uint16_t id_1404 { 0 };
          ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98 id_1405 { std::get<1 /* PerService */>(p_0) };
          ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_1406 { std::get<1>(id_1405) };
          uint16_t id_1407 { uint16_t(id_1406.index()) };
          bool id_1408 { bool(id_1404 == id_1407) };
          Size choose_res_1409;
          if (id_1408) {
            Size id_1410 { 2UL };
            Size id_1411 { Size(sz_662 + id_1410) };
            choose_res_1409 = id_1411;
          } else {
            ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98 id_1412 { std::get<1 /* PerService */>(p_0) };
            ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_1413 { std::get<1>(id_1412) };
            uint16_t id_1414 { uint16_t(id_1413.index()) };
            uint16_t id_1415 { 1 };
            bool id_1416 { bool(id_1414 == id_1415) };
            Void id_1417 { ((void)(assert(id_1416)), ::dessser::Void()) };
            (void)id_1417;
            Size id_1418 { 2UL };
            Size id_1419 { Size(sz_662 + id_1418) };
            choose_res_1409 = id_1419;
          }
          let_res_1403 = choose_res_1409;
        }
        choose_res_1370 = let_res_1403;
      } else {
        uint16_t id_1420 { 2 };
        uint16_t id_1421 { uint16_t(p_0.index()) };
        bool id_1422 { bool(id_1420 == id_1421) };
        Size choose_res_1423;
        if (id_1422) {
          Size id_1424 { 2UL };
          ::dessser::gen::sync_key::per_worker id_1425 { std::get<2 /* PerWorker */>(p_0) };
          Size id_1426 { per_worker_sersize_of_row_binary(id_1425) };
          Size id_1427 { Size(id_1424 + id_1426) };
          choose_res_1423 = id_1427;
        } else {
          uint16_t id_1428 { uint16_t(p_0.index()) };
          uint16_t id_1429 { 3 };
          bool id_1430 { bool(id_1428 == id_1429) };
          Void id_1431 { ((void)(assert(id_1430)), ::dessser::Void()) };
          (void)id_1431;
          Size id_1432 { 2UL };
          ::dessser::gen::sync_key::t85827d1984b82a47867ad2208bc45f28 id_1433 { std::get<3 /* PerProgram */>(p_0) };
          std::string id_1434 { std::get<0>(id_1433) };
          uint32_t id_1435 { (uint32_t)id_1434.size() };
          Vec<1, uint32_t> id_1436 {  id_1435  };
          Size let_res_1437;
          {
            Vec<1, uint32_t> n_ref_654 { id_1436 };
            uint32_t id_1438 { 1U };
            Vec<1, uint32_t> id_1439 {  id_1438  };
            Size let_res_1440;
            {
              Vec<1, uint32_t> lebsz_ref_655 { id_1439 };
              bool while_flag_1441 { true };
              do {
                uint8_t id_1442 { 0 };
                uint32_t id_1443 { n_ref_654[id_1442] };
                uint8_t id_1444 { 0 };
                uint32_t id_1445 { lebsz_ref_655[id_1444] };
                uint8_t id_1446 { 7 };
                uint32_t id_1447 { uint32_t(id_1445 << id_1446) };
                bool id_1448 { bool(id_1443 >= id_1447) };
                while_flag_1441 = id_1448;
                if (while_flag_1441) {
                  uint8_t id_1449 { 0 };
                  uint8_t id_1450 { 0 };
                  uint32_t id_1451 { lebsz_ref_655[id_1450] };
                  uint32_t id_1452 { 1U };
                  uint32_t id_1453 { uint32_t(id_1451 + id_1452) };
                  Void id_1454 { ((void)(lebsz_ref_655[id_1449] = id_1453), ::dessser::Void()) };
                  (void)id_1454;
                }
              } while (while_flag_1441);
              (void)::dessser::Void();
              uint8_t id_1455 { 0 };
              uint32_t id_1456 { lebsz_ref_655[id_1455] };
              Size id_1457 { Size(id_1456) };
              let_res_1440 = id_1457;
            }
            let_res_1437 = let_res_1440;
          }
          ::dessser::gen::sync_key::t85827d1984b82a47867ad2208bc45f28 id_1458 { std::get<3 /* PerProgram */>(p_0) };
          std::string id_1459 { std::get<0>(id_1458) };
          uint32_t id_1460 { (uint32_t)id_1459.size() };
          Size id_1461 { Size(id_1460) };
          Size id_1462 { Size(let_res_1437 + id_1461) };
          Size id_1463 { Size(id_1432 + id_1462) };
          Size let_res_1464;
          {
            Size sz_656 { id_1463 };
            ::dessser::gen::sync_key::t85827d1984b82a47867ad2208bc45f28 id_1465 { std::get<3 /* PerProgram */>(p_0) };
            ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51 id_1466 { std::get<1>(id_1465) };
            uint16_t id_1467 { uint16_t(id_1466.index()) };
            uint16_t id_1468 { 0 };
            bool id_1469 { bool(id_1467 == id_1468) };
            Void id_1470 { ((void)(assert(id_1469)), ::dessser::Void()) };
            (void)id_1470;
            Size id_1471 { 2UL };
            Size id_1472 { Size(sz_656 + id_1471) };
            let_res_1464 = id_1472;
          }
          choose_res_1423 = let_res_1464;
        }
        choose_res_1370 = choose_res_1423;
      }
      choose_res_1365 = choose_res_1370;
    }
    return choose_res_1365;
  }
   };
  return fun1361;
}
std::function<Size(::dessser::gen::sync_key::per_site_data &)> per_site_data_sersize_of_row_binary(per_site_data_sersize_of_row_binary_init());

/* 
    (fun ("($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))")
      (let "sz_665" (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (param 0))) (add (identifier "sz_665") (apply (identifier "per_site_data-sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(::dessser::gen::sync_key::per_site &)> per_site_sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::per_site &)> fun1473 { [&](::dessser::gen::sync_key::per_site p_0) {
    auto fun1474 { dessser::gen::site_name::sersize_of_row_binary };
    dessser::gen::site_name::t_ext id_1475 { std::get<0>(p_0) };
    Size id_1476 { fun1474(id_1475) };
    Size let_res_1477;
    {
      Size sz_665 { id_1476 };
      ::dessser::gen::sync_key::per_site_data id_1478 { std::get<1>(p_0) };
      Size id_1479 { per_site_data_sersize_of_row_binary(id_1478) };
      Size id_1480 { Size(sz_665 + id_1479) };
      let_res_1477 = id_1480;
    }
    return let_res_1477;
  }
   };
  return fun1473;
}
std::function<Size(::dessser::gen::sync_key::per_site &)> per_site_sersize_of_row_binary(per_site_sersize_of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]")
      (let "label2_691" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_691")) (size 2)
          (if (eq (u16 1) (identifier "label2_691")) (size 2)
            (if (eq (u16 2) (identifier "label2_691"))
              (add (size 2)
                (add
                  (let "n_ref_723" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "lebsz_ref_724" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_723")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_724")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_724") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_724")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_724")))))) 
                  (size-of-u32 (string-length (get-alt "Versions" (param 0))))))
              (if (eq (u16 3) (identifier "label2_691"))
                (let "sz_718" (add (size 2) (apply (ext-identifier src_path sersize-of-row-binary) (get-item 0 (get-alt "Sources" (param 0)))))
                  (add (identifier "sz_718")
                    (add
                      (let "n_ref_720" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "lebsz_ref_721" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_720")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_721")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_721") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_721")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_721")))))) 
                      (size-of-u32 (string-length (get-item 1 (get-alt "Sources" (param 0))))))))
                (if (eq (u16 4) (identifier "label2_691")) (size 2)
                  (if (eq (u16 5) (identifier "label2_691")) (add (size 2) (apply (identifier "per_site-sersize-of-row-binary") (get-alt "PerSite" (param 0))))
                    (if (eq (u16 6) (identifier "label2_691"))
                      (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                        (size 4)
                        (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                          (size 4)
                          (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                            (add (size 4)
                              (add
                                (let "n_ref_715" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                  (let "lebsz_ref_716" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_715")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_716")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_716") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_716")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_716")))))) 
                                (size-of-u32 (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0))))))))))
                      (if (eq (u16 7) (identifier "label2_691"))
                        (let "sz_712"
                          (let "sz_708"
                            (let "sz_707" (add (size 2) (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (get-alt "Tails" (param 0)))))
                              (add (identifier "sz_707") (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 1 (get-alt "Tails" (param 0))))))
                            (add (identifier "sz_708")
                              (add
                                (let "n_ref_710" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "lebsz_ref_711" (make-vec (u32 1))
                                    (seq
                                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_710")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_711")) (u8 7)))
                                        (set-vec (u8 0) (identifier "lebsz_ref_711") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_711")) (u32 1)))) 
                                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_711")))))) 
                                (size-of-u32 (string-length (get-item 2 (get-alt "Tails" (param 0)))))))) 
                          (add (identifier "sz_712") (apply (identifier "per_tail-sersize-of-row-binary") (get-item 3 (get-alt "Tails" (param 0))))))
                        (if (eq (u16 8) (identifier "label2_691")) (size 4)
                          (if (eq (u16 9) (identifier "label2_691"))
                            (if (is-null (get-alt "Error" (param 0))) (size 3) (add (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (force (get-alt "Error" (param 0))))) (size 1)))
                            (if (eq (u16 10) (identifier "label2_691")) 
                              (size 2)
                              (if (eq (u16 11) (identifier "label2_691"))
                                (let "sz_705" (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (get-item 0 (get-alt "PerClient" (param 0)))))
                                  (add (identifier "sz_705") (apply (identifier "per_client-sersize-of-row-binary") (get-item 1 (get-alt "PerClient" (param 0))))))
                                (if (eq (u16 12) (identifier "label2_691"))
                                  (let "sz_703"
                                    (add (size 2)
                                      (add
                                        (let "n_ref_701" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "lebsz_ref_702" (make-vec (u32 1))
                                            (seq
                                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_701")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_702")) (u8 7)))
                                                (set-vec (u8 0) (identifier "lebsz_ref_702") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_702")) (u32 1)))) 
                                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_702")))))) 
                                        (size-of-u32 (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))))
                                    (add (identifier "sz_703") (apply (identifier "per_dash_key-sersize-of-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))))))
                                  (if (eq (u16 13) (identifier "label2_691")) 
                                    (size 2)
                                    (if (eq (u16 14) (identifier "label2_691"))
                                      (let "sz_698" (add (size 2) (apply (ext-identifier team_name sersize-of-row-binary) (get-field "name" (get-alt "Teams" (param 0)))))
                                        (add (identifier "sz_698") (apply (identifier "team_key_info-sersize-of-row-binary") (get-field "info" (get-alt "Teams" (param 0))))))
                                      (seq (assert (eq (identifier "label2_691") (u16 15)))
                                        (let "sz_696"
                                          (add (size 2)
                                            (add
                                              (let "n_ref_694" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "lebsz_ref_695" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_694")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_695")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_695") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_695")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_695")))))) 
                                              (size-of-u32 (string-length (get-item 0 (get-alt "Incidents" (param 0)))))))
                                          (add (identifier "sz_696") (apply (identifier "incident_key-sersize-of-row-binary") (get-item 1 (get-alt "Incidents" (param 0))))))))))))))))))))))))
 */
static std::function<Size(::dessser::gen::sync_key::t &)> sersize_of_row_binary_init()
{
  std::function<Size(::dessser::gen::sync_key::t &)> fun1481 { [&](::dessser::gen::sync_key::t p_0) {
    uint16_t id_1482 { uint16_t(p_0.index()) };
    Size let_res_1483;
    {
      uint16_t label2_691 { id_1482 };
      uint16_t id_1484 { 0 };
      bool id_1485 { bool(id_1484 == label2_691) };
      Size choose_res_1486;
      if (id_1485) {
        Size id_1487 { 2UL };
        choose_res_1486 = id_1487;
      } else {
        uint16_t id_1488 { 1 };
        bool id_1489 { bool(id_1488 == label2_691) };
        Size choose_res_1490;
        if (id_1489) {
          Size id_1491 { 2UL };
          choose_res_1490 = id_1491;
        } else {
          uint16_t id_1492 { 2 };
          bool id_1493 { bool(id_1492 == label2_691) };
          Size choose_res_1494;
          if (id_1493) {
            Size id_1495 { 2UL };
            std::string id_1496 { std::get<2 /* Versions */>(p_0) };
            uint32_t id_1497 { (uint32_t)id_1496.size() };
            Vec<1, uint32_t> id_1498 {  id_1497  };
            Size let_res_1499;
            {
              Vec<1, uint32_t> n_ref_723 { id_1498 };
              uint32_t id_1500 { 1U };
              Vec<1, uint32_t> id_1501 {  id_1500  };
              Size let_res_1502;
              {
                Vec<1, uint32_t> lebsz_ref_724 { id_1501 };
                bool while_flag_1503 { true };
                do {
                  uint8_t id_1504 { 0 };
                  uint32_t id_1505 { n_ref_723[id_1504] };
                  uint8_t id_1506 { 0 };
                  uint32_t id_1507 { lebsz_ref_724[id_1506] };
                  uint8_t id_1508 { 7 };
                  uint32_t id_1509 { uint32_t(id_1507 << id_1508) };
                  bool id_1510 { bool(id_1505 >= id_1509) };
                  while_flag_1503 = id_1510;
                  if (while_flag_1503) {
                    uint8_t id_1511 { 0 };
                    uint8_t id_1512 { 0 };
                    uint32_t id_1513 { lebsz_ref_724[id_1512] };
                    uint32_t id_1514 { 1U };
                    uint32_t id_1515 { uint32_t(id_1513 + id_1514) };
                    Void id_1516 { ((void)(lebsz_ref_724[id_1511] = id_1515), ::dessser::Void()) };
                    (void)id_1516;
                  }
                } while (while_flag_1503);
                (void)::dessser::Void();
                uint8_t id_1517 { 0 };
                uint32_t id_1518 { lebsz_ref_724[id_1517] };
                Size id_1519 { Size(id_1518) };
                let_res_1502 = id_1519;
              }
              let_res_1499 = let_res_1502;
            }
            std::string id_1520 { std::get<2 /* Versions */>(p_0) };
            uint32_t id_1521 { (uint32_t)id_1520.size() };
            Size id_1522 { Size(id_1521) };
            Size id_1523 { Size(let_res_1499 + id_1522) };
            Size id_1524 { Size(id_1495 + id_1523) };
            choose_res_1494 = id_1524;
          } else {
            uint16_t id_1525 { 3 };
            bool id_1526 { bool(id_1525 == label2_691) };
            Size choose_res_1527;
            if (id_1526) {
              Size id_1528 { 2UL };
              auto fun1529 { dessser::gen::src_path::sersize_of_row_binary };
              ::dessser::gen::sync_key::t86252e3890668e56d73574e8b879a5b1 id_1530 { std::get<3 /* Sources */>(p_0) };
              dessser::gen::src_path::t_ext id_1531 { std::get<0>(id_1530) };
              Size id_1532 { fun1529(id_1531) };
              Size id_1533 { Size(id_1528 + id_1532) };
              Size let_res_1534;
              {
                Size sz_718 { id_1533 };
                ::dessser::gen::sync_key::t86252e3890668e56d73574e8b879a5b1 id_1535 { std::get<3 /* Sources */>(p_0) };
                std::string id_1536 { std::get<1>(id_1535) };
                uint32_t id_1537 { (uint32_t)id_1536.size() };
                Vec<1, uint32_t> id_1538 {  id_1537  };
                Size let_res_1539;
                {
                  Vec<1, uint32_t> n_ref_720 { id_1538 };
                  uint32_t id_1540 { 1U };
                  Vec<1, uint32_t> id_1541 {  id_1540  };
                  Size let_res_1542;
                  {
                    Vec<1, uint32_t> lebsz_ref_721 { id_1541 };
                    bool while_flag_1543 { true };
                    do {
                      uint8_t id_1544 { 0 };
                      uint32_t id_1545 { n_ref_720[id_1544] };
                      uint8_t id_1546 { 0 };
                      uint32_t id_1547 { lebsz_ref_721[id_1546] };
                      uint8_t id_1548 { 7 };
                      uint32_t id_1549 { uint32_t(id_1547 << id_1548) };
                      bool id_1550 { bool(id_1545 >= id_1549) };
                      while_flag_1543 = id_1550;
                      if (while_flag_1543) {
                        uint8_t id_1551 { 0 };
                        uint8_t id_1552 { 0 };
                        uint32_t id_1553 { lebsz_ref_721[id_1552] };
                        uint32_t id_1554 { 1U };
                        uint32_t id_1555 { uint32_t(id_1553 + id_1554) };
                        Void id_1556 { ((void)(lebsz_ref_721[id_1551] = id_1555), ::dessser::Void()) };
                        (void)id_1556;
                      }
                    } while (while_flag_1543);
                    (void)::dessser::Void();
                    uint8_t id_1557 { 0 };
                    uint32_t id_1558 { lebsz_ref_721[id_1557] };
                    Size id_1559 { Size(id_1558) };
                    let_res_1542 = id_1559;
                  }
                  let_res_1539 = let_res_1542;
                }
                ::dessser::gen::sync_key::t86252e3890668e56d73574e8b879a5b1 id_1560 { std::get<3 /* Sources */>(p_0) };
                std::string id_1561 { std::get<1>(id_1560) };
                uint32_t id_1562 { (uint32_t)id_1561.size() };
                Size id_1563 { Size(id_1562) };
                Size id_1564 { Size(let_res_1539 + id_1563) };
                Size id_1565 { Size(sz_718 + id_1564) };
                let_res_1534 = id_1565;
              }
              choose_res_1527 = let_res_1534;
            } else {
              uint16_t id_1566 { 4 };
              bool id_1567 { bool(id_1566 == label2_691) };
              Size choose_res_1568;
              if (id_1567) {
                Size id_1569 { 2UL };
                choose_res_1568 = id_1569;
              } else {
                uint16_t id_1570 { 5 };
                bool id_1571 { bool(id_1570 == label2_691) };
                Size choose_res_1572;
                if (id_1571) {
                  Size id_1573 { 2UL };
                  ::dessser::gen::sync_key::per_site id_1574 { std::get<5 /* PerSite */>(p_0) };
                  Size id_1575 { per_site_sersize_of_row_binary(id_1574) };
                  Size id_1576 { Size(id_1573 + id_1575) };
                  choose_res_1572 = id_1576;
                } else {
                  uint16_t id_1577 { 6 };
                  bool id_1578 { bool(id_1577 == label2_691) };
                  Size choose_res_1579;
                  if (id_1578) {
                    uint16_t id_1580 { 0 };
                    ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_1581 { std::get<6 /* Storage */>(p_0) };
                    uint16_t id_1582 { uint16_t(id_1581.index()) };
                    bool id_1583 { bool(id_1580 == id_1582) };
                    Size choose_res_1584;
                    if (id_1583) {
                      Size id_1585 { 4UL };
                      choose_res_1584 = id_1585;
                    } else {
                      uint16_t id_1586 { 1 };
                      ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_1587 { std::get<6 /* Storage */>(p_0) };
                      uint16_t id_1588 { uint16_t(id_1587.index()) };
                      bool id_1589 { bool(id_1586 == id_1588) };
                      Size choose_res_1590;
                      if (id_1589) {
                        Size id_1591 { 4UL };
                        choose_res_1590 = id_1591;
                      } else {
                        ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_1592 { std::get<6 /* Storage */>(p_0) };
                        uint16_t id_1593 { uint16_t(id_1592.index()) };
                        uint16_t id_1594 { 2 };
                        bool id_1595 { bool(id_1593 == id_1594) };
                        Void id_1596 { ((void)(assert(id_1595)), ::dessser::Void()) };
                        (void)id_1596;
                        Size id_1597 { 4UL };
                        ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_1598 { std::get<6 /* Storage */>(p_0) };
                        std::string id_1599 { std::get<2 /* RetentionsOverride */>(id_1598) };
                        uint32_t id_1600 { (uint32_t)id_1599.size() };
                        Vec<1, uint32_t> id_1601 {  id_1600  };
                        Size let_res_1602;
                        {
                          Vec<1, uint32_t> n_ref_715 { id_1601 };
                          uint32_t id_1603 { 1U };
                          Vec<1, uint32_t> id_1604 {  id_1603  };
                          Size let_res_1605;
                          {
                            Vec<1, uint32_t> lebsz_ref_716 { id_1604 };
                            bool while_flag_1606 { true };
                            do {
                              uint8_t id_1607 { 0 };
                              uint32_t id_1608 { n_ref_715[id_1607] };
                              uint8_t id_1609 { 0 };
                              uint32_t id_1610 { lebsz_ref_716[id_1609] };
                              uint8_t id_1611 { 7 };
                              uint32_t id_1612 { uint32_t(id_1610 << id_1611) };
                              bool id_1613 { bool(id_1608 >= id_1612) };
                              while_flag_1606 = id_1613;
                              if (while_flag_1606) {
                                uint8_t id_1614 { 0 };
                                uint8_t id_1615 { 0 };
                                uint32_t id_1616 { lebsz_ref_716[id_1615] };
                                uint32_t id_1617 { 1U };
                                uint32_t id_1618 { uint32_t(id_1616 + id_1617) };
                                Void id_1619 { ((void)(lebsz_ref_716[id_1614] = id_1618), ::dessser::Void()) };
                                (void)id_1619;
                              }
                            } while (while_flag_1606);
                            (void)::dessser::Void();
                            uint8_t id_1620 { 0 };
                            uint32_t id_1621 { lebsz_ref_716[id_1620] };
                            Size id_1622 { Size(id_1621) };
                            let_res_1605 = id_1622;
                          }
                          let_res_1602 = let_res_1605;
                        }
                        ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_1623 { std::get<6 /* Storage */>(p_0) };
                        std::string id_1624 { std::get<2 /* RetentionsOverride */>(id_1623) };
                        uint32_t id_1625 { (uint32_t)id_1624.size() };
                        Size id_1626 { Size(id_1625) };
                        Size id_1627 { Size(let_res_1602 + id_1626) };
                        Size id_1628 { Size(id_1597 + id_1627) };
                        choose_res_1590 = id_1628;
                      }
                      choose_res_1584 = choose_res_1590;
                    }
                    choose_res_1579 = choose_res_1584;
                  } else {
                    uint16_t id_1629 { 7 };
                    bool id_1630 { bool(id_1629 == label2_691) };
                    Size choose_res_1631;
                    if (id_1630) {
                      Size id_1632 { 2UL };
                      auto fun1633 { dessser::gen::site_name::sersize_of_row_binary };
                      ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_1634 { std::get<7 /* Tails */>(p_0) };
                      dessser::gen::site_name::t_ext id_1635 { std::get<0>(id_1634) };
                      Size id_1636 { fun1633(id_1635) };
                      Size id_1637 { Size(id_1632 + id_1636) };
                      Size let_res_1638;
                      {
                        Size sz_707 { id_1637 };
                        auto fun1639 { dessser::gen::fq_name::sersize_of_row_binary };
                        ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_1640 { std::get<7 /* Tails */>(p_0) };
                        dessser::gen::fq_name::t_ext id_1641 { std::get<1>(id_1640) };
                        Size id_1642 { fun1639(id_1641) };
                        Size id_1643 { Size(sz_707 + id_1642) };
                        let_res_1638 = id_1643;
                      }
                      Size let_res_1644;
                      {
                        Size sz_708 { let_res_1638 };
                        ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_1645 { std::get<7 /* Tails */>(p_0) };
                        std::string id_1646 { std::get<2>(id_1645) };
                        uint32_t id_1647 { (uint32_t)id_1646.size() };
                        Vec<1, uint32_t> id_1648 {  id_1647  };
                        Size let_res_1649;
                        {
                          Vec<1, uint32_t> n_ref_710 { id_1648 };
                          uint32_t id_1650 { 1U };
                          Vec<1, uint32_t> id_1651 {  id_1650  };
                          Size let_res_1652;
                          {
                            Vec<1, uint32_t> lebsz_ref_711 { id_1651 };
                            bool while_flag_1653 { true };
                            do {
                              uint8_t id_1654 { 0 };
                              uint32_t id_1655 { n_ref_710[id_1654] };
                              uint8_t id_1656 { 0 };
                              uint32_t id_1657 { lebsz_ref_711[id_1656] };
                              uint8_t id_1658 { 7 };
                              uint32_t id_1659 { uint32_t(id_1657 << id_1658) };
                              bool id_1660 { bool(id_1655 >= id_1659) };
                              while_flag_1653 = id_1660;
                              if (while_flag_1653) {
                                uint8_t id_1661 { 0 };
                                uint8_t id_1662 { 0 };
                                uint32_t id_1663 { lebsz_ref_711[id_1662] };
                                uint32_t id_1664 { 1U };
                                uint32_t id_1665 { uint32_t(id_1663 + id_1664) };
                                Void id_1666 { ((void)(lebsz_ref_711[id_1661] = id_1665), ::dessser::Void()) };
                                (void)id_1666;
                              }
                            } while (while_flag_1653);
                            (void)::dessser::Void();
                            uint8_t id_1667 { 0 };
                            uint32_t id_1668 { lebsz_ref_711[id_1667] };
                            Size id_1669 { Size(id_1668) };
                            let_res_1652 = id_1669;
                          }
                          let_res_1649 = let_res_1652;
                        }
                        ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_1670 { std::get<7 /* Tails */>(p_0) };
                        std::string id_1671 { std::get<2>(id_1670) };
                        uint32_t id_1672 { (uint32_t)id_1671.size() };
                        Size id_1673 { Size(id_1672) };
                        Size id_1674 { Size(let_res_1649 + id_1673) };
                        Size id_1675 { Size(sz_708 + id_1674) };
                        let_res_1644 = id_1675;
                      }
                      Size let_res_1676;
                      {
                        Size sz_712 { let_res_1644 };
                        ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_1677 { std::get<7 /* Tails */>(p_0) };
                        ::dessser::gen::sync_key::per_tail id_1678 { std::get<3>(id_1677) };
                        Size id_1679 { per_tail_sersize_of_row_binary(id_1678) };
                        Size id_1680 { Size(sz_712 + id_1679) };
                        let_res_1676 = id_1680;
                      }
                      choose_res_1631 = let_res_1676;
                    } else {
                      uint16_t id_1681 { 8 };
                      bool id_1682 { bool(id_1681 == label2_691) };
                      Size choose_res_1683;
                      if (id_1682) {
                        Size id_1684 { 4UL };
                        choose_res_1683 = id_1684;
                      } else {
                        uint16_t id_1685 { 9 };
                        bool id_1686 { bool(id_1685 == label2_691) };
                        Size choose_res_1687;
                        if (id_1686) {
                          std::optional<dessser::gen::sync_socket::t_ext> id_1688 { std::get<9 /* Error */>(p_0) };
                          bool id_1689 { !(id_1688.has_value ()) };
                          Size choose_res_1690;
                          if (id_1689) {
                            Size id_1691 { 3UL };
                            choose_res_1690 = id_1691;
                          } else {
                            Size id_1692 { 2UL };
                            auto fun1693 { dessser::gen::sync_socket::sersize_of_row_binary };
                            std::optional<dessser::gen::sync_socket::t_ext> id_1694 { std::get<9 /* Error */>(p_0) };
                            dessser::gen::sync_socket::t_ext id_1695 { id_1694.value() };
                            Size id_1696 { fun1693(id_1695) };
                            Size id_1697 { Size(id_1692 + id_1696) };
                            Size id_1698 { 1UL };
                            Size id_1699 { Size(id_1697 + id_1698) };
                            choose_res_1690 = id_1699;
                          }
                          choose_res_1687 = choose_res_1690;
                        } else {
                          uint16_t id_1700 { 10 };
                          bool id_1701 { bool(id_1700 == label2_691) };
                          Size choose_res_1702;
                          if (id_1701) {
                            Size id_1703 { 2UL };
                            choose_res_1702 = id_1703;
                          } else {
                            uint16_t id_1704 { 11 };
                            bool id_1705 { bool(id_1704 == label2_691) };
                            Size choose_res_1706;
                            if (id_1705) {
                              Size id_1707 { 2UL };
                              auto fun1708 { dessser::gen::sync_socket::sersize_of_row_binary };
                              ::dessser::gen::sync_key::t32db4748152e7073f1f93bdcc3c5bff5 id_1709 { std::get<11 /* PerClient */>(p_0) };
                              dessser::gen::sync_socket::t_ext id_1710 { std::get<0>(id_1709) };
                              Size id_1711 { fun1708(id_1710) };
                              Size id_1712 { Size(id_1707 + id_1711) };
                              Size let_res_1713;
                              {
                                Size sz_705 { id_1712 };
                                ::dessser::gen::sync_key::t32db4748152e7073f1f93bdcc3c5bff5 id_1714 { std::get<11 /* PerClient */>(p_0) };
                                ::dessser::gen::sync_key::per_client id_1715 { std::get<1>(id_1714) };
                                Size id_1716 { per_client_sersize_of_row_binary(id_1715) };
                                Size id_1717 { Size(sz_705 + id_1716) };
                                let_res_1713 = id_1717;
                              }
                              choose_res_1706 = let_res_1713;
                            } else {
                              uint16_t id_1718 { 12 };
                              bool id_1719 { bool(id_1718 == label2_691) };
                              Size choose_res_1720;
                              if (id_1719) {
                                Size id_1721 { 2UL };
                                ::dessser::gen::sync_key::ta05201a250c67cd2df71e6345b0a4f16 id_1722 { std::get<12 /* Dashboards */>(p_0) };
                                std::string id_1723 { std::get<0>(id_1722) };
                                uint32_t id_1724 { (uint32_t)id_1723.size() };
                                Vec<1, uint32_t> id_1725 {  id_1724  };
                                Size let_res_1726;
                                {
                                  Vec<1, uint32_t> n_ref_701 { id_1725 };
                                  uint32_t id_1727 { 1U };
                                  Vec<1, uint32_t> id_1728 {  id_1727  };
                                  Size let_res_1729;
                                  {
                                    Vec<1, uint32_t> lebsz_ref_702 { id_1728 };
                                    bool while_flag_1730 { true };
                                    do {
                                      uint8_t id_1731 { 0 };
                                      uint32_t id_1732 { n_ref_701[id_1731] };
                                      uint8_t id_1733 { 0 };
                                      uint32_t id_1734 { lebsz_ref_702[id_1733] };
                                      uint8_t id_1735 { 7 };
                                      uint32_t id_1736 { uint32_t(id_1734 << id_1735) };
                                      bool id_1737 { bool(id_1732 >= id_1736) };
                                      while_flag_1730 = id_1737;
                                      if (while_flag_1730) {
                                        uint8_t id_1738 { 0 };
                                        uint8_t id_1739 { 0 };
                                        uint32_t id_1740 { lebsz_ref_702[id_1739] };
                                        uint32_t id_1741 { 1U };
                                        uint32_t id_1742 { uint32_t(id_1740 + id_1741) };
                                        Void id_1743 { ((void)(lebsz_ref_702[id_1738] = id_1742), ::dessser::Void()) };
                                        (void)id_1743;
                                      }
                                    } while (while_flag_1730);
                                    (void)::dessser::Void();
                                    uint8_t id_1744 { 0 };
                                    uint32_t id_1745 { lebsz_ref_702[id_1744] };
                                    Size id_1746 { Size(id_1745) };
                                    let_res_1729 = id_1746;
                                  }
                                  let_res_1726 = let_res_1729;
                                }
                                ::dessser::gen::sync_key::ta05201a250c67cd2df71e6345b0a4f16 id_1747 { std::get<12 /* Dashboards */>(p_0) };
                                std::string id_1748 { std::get<0>(id_1747) };
                                uint32_t id_1749 { (uint32_t)id_1748.size() };
                                Size id_1750 { Size(id_1749) };
                                Size id_1751 { Size(let_res_1726 + id_1750) };
                                Size id_1752 { Size(id_1721 + id_1751) };
                                Size let_res_1753;
                                {
                                  Size sz_703 { id_1752 };
                                  ::dessser::gen::sync_key::ta05201a250c67cd2df71e6345b0a4f16 id_1754 { std::get<12 /* Dashboards */>(p_0) };
                                  std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1755 { std::get<1>(id_1754) };
                                  Size id_1756 { per_dash_key_sersize_of_row_binary(id_1755) };
                                  Size id_1757 { Size(sz_703 + id_1756) };
                                  let_res_1753 = id_1757;
                                }
                                choose_res_1720 = let_res_1753;
                              } else {
                                uint16_t id_1758 { 13 };
                                bool id_1759 { bool(id_1758 == label2_691) };
                                Size choose_res_1760;
                                if (id_1759) {
                                  Size id_1761 { 2UL };
                                  choose_res_1760 = id_1761;
                                } else {
                                  uint16_t id_1762 { 14 };
                                  bool id_1763 { bool(id_1762 == label2_691) };
                                  Size choose_res_1764;
                                  if (id_1763) {
                                    Size id_1765 { 2UL };
                                    auto fun1766 { dessser::gen::team_name::sersize_of_row_binary };
                                    ::dessser::gen::sync_key::t387175c465c261e0af17af4010188b4e id_1767 { std::get<14 /* Teams */>(p_0) };
                                    dessser::gen::team_name::t_ext id_1768 { id_1767.name };
                                    Size id_1769 { fun1766(id_1768) };
                                    Size id_1770 { Size(id_1765 + id_1769) };
                                    Size let_res_1771;
                                    {
                                      Size sz_698 { id_1770 };
                                      ::dessser::gen::sync_key::t387175c465c261e0af17af4010188b4e id_1772 { std::get<14 /* Teams */>(p_0) };
                                      ::dessser::gen::sync_key::team_key_info id_1773 { id_1772.info };
                                      Size id_1774 { team_key_info_sersize_of_row_binary(id_1773) };
                                      Size id_1775 { Size(sz_698 + id_1774) };
                                      let_res_1771 = id_1775;
                                    }
                                    choose_res_1764 = let_res_1771;
                                  } else {
                                    uint16_t id_1776 { 15 };
                                    bool id_1777 { bool(label2_691 == id_1776) };
                                    Void id_1778 { ((void)(assert(id_1777)), ::dessser::Void()) };
                                    (void)id_1778;
                                    Size id_1779 { 2UL };
                                    ::dessser::gen::sync_key::t891de542b31fe57e6f8226ed37c952be id_1780 { std::get<15 /* Incidents */>(p_0) };
                                    std::string id_1781 { std::get<0>(id_1780) };
                                    uint32_t id_1782 { (uint32_t)id_1781.size() };
                                    Vec<1, uint32_t> id_1783 {  id_1782  };
                                    Size let_res_1784;
                                    {
                                      Vec<1, uint32_t> n_ref_694 { id_1783 };
                                      uint32_t id_1785 { 1U };
                                      Vec<1, uint32_t> id_1786 {  id_1785  };
                                      Size let_res_1787;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_695 { id_1786 };
                                        bool while_flag_1788 { true };
                                        do {
                                          uint8_t id_1789 { 0 };
                                          uint32_t id_1790 { n_ref_694[id_1789] };
                                          uint8_t id_1791 { 0 };
                                          uint32_t id_1792 { lebsz_ref_695[id_1791] };
                                          uint8_t id_1793 { 7 };
                                          uint32_t id_1794 { uint32_t(id_1792 << id_1793) };
                                          bool id_1795 { bool(id_1790 >= id_1794) };
                                          while_flag_1788 = id_1795;
                                          if (while_flag_1788) {
                                            uint8_t id_1796 { 0 };
                                            uint8_t id_1797 { 0 };
                                            uint32_t id_1798 { lebsz_ref_695[id_1797] };
                                            uint32_t id_1799 { 1U };
                                            uint32_t id_1800 { uint32_t(id_1798 + id_1799) };
                                            Void id_1801 { ((void)(lebsz_ref_695[id_1796] = id_1800), ::dessser::Void()) };
                                            (void)id_1801;
                                          }
                                        } while (while_flag_1788);
                                        (void)::dessser::Void();
                                        uint8_t id_1802 { 0 };
                                        uint32_t id_1803 { lebsz_ref_695[id_1802] };
                                        Size id_1804 { Size(id_1803) };
                                        let_res_1787 = id_1804;
                                      }
                                      let_res_1784 = let_res_1787;
                                    }
                                    ::dessser::gen::sync_key::t891de542b31fe57e6f8226ed37c952be id_1805 { std::get<15 /* Incidents */>(p_0) };
                                    std::string id_1806 { std::get<0>(id_1805) };
                                    uint32_t id_1807 { (uint32_t)id_1806.size() };
                                    Size id_1808 { Size(id_1807) };
                                    Size id_1809 { Size(let_res_1784 + id_1808) };
                                    Size id_1810 { Size(id_1779 + id_1809) };
                                    Size let_res_1811;
                                    {
                                      Size sz_696 { id_1810 };
                                      ::dessser::gen::sync_key::t891de542b31fe57e6f8226ed37c952be id_1812 { std::get<15 /* Incidents */>(p_0) };
                                      ::dessser::gen::sync_key::incident_key id_1813 { std::get<1>(id_1812) };
                                      Size id_1814 { incident_key_sersize_of_row_binary(id_1813) };
                                      Size id_1815 { Size(sz_696 + id_1814) };
                                      let_res_1811 = id_1815;
                                    }
                                    choose_res_1764 = let_res_1811;
                                  }
                                  choose_res_1760 = choose_res_1764;
                                }
                                choose_res_1720 = choose_res_1760;
                              }
                              choose_res_1706 = choose_res_1720;
                            }
                            choose_res_1702 = choose_res_1706;
                          }
                          choose_res_1687 = choose_res_1702;
                        }
                        choose_res_1683 = choose_res_1687;
                      }
                      choose_res_1631 = choose_res_1683;
                    }
                    choose_res_1579 = choose_res_1631;
                  }
                  choose_res_1572 = choose_res_1579;
                }
                choose_res_1568 = choose_res_1572;
              }
              choose_res_1527 = choose_res_1568;
            }
            choose_res_1494 = choose_res_1527;
          }
          choose_res_1490 = choose_res_1494;
        }
        choose_res_1486 = choose_res_1490;
      }
      let_res_1483 = choose_res_1486;
    }
    return let_res_1483;
  }
   };
  return fun1481;
}
std::function<Size(::dessser::gen::sync_key::t &)> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_360" (let-pair "du16_fst_355" "du16_snd_356" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_355") (identifier "du16_snd_356")))
        (let-pair "dsum1_fst_361" "dsum1_snd_362" (identifier "dsum1_360")
          (if (eq (u16 0) (identifier "dsum1_fst_361"))
            (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 0 (nop)) (identifier "dsum1_snd_362"))
            (if (eq (u16 1) (identifier "dsum1_fst_361"))
              (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 1 (nop)) (identifier "dsum1_snd_362"))
              (if (eq (u16 2) (identifier "dsum1_fst_361"))
                (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 2 (nop)) (identifier "dsum1_snd_362"))
                (if (eq (u16 3) (identifier "dsum1_fst_361"))
                  (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 3 (nop))
                    (identifier "dsum1_snd_362"))
                  (if (eq (u16 4) (identifier "dsum1_fst_361"))
                    (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 4 (nop))
                      (identifier "dsum1_snd_362"))
                    (if (eq (u16 5) (identifier "dsum1_fst_361"))
                      (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 5 (nop))
                        (identifier "dsum1_snd_362"))
                      (seq (assert (eq (identifier "dsum1_fst_361") (u16 6)))
                        (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 6 (nop))
                          (identifier "dsum1_snd_362"))))))))))))
 */
static std::function<::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25(Pointer &)> dialog_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25(Pointer &)> fun1816 { [&](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1817 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1818;
    {
      auto du16_fst_355 { std::get<0>(id_1817) };
      auto du16_snd_356 { std::get<1>(id_1817) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1819 { du16_fst_355, du16_snd_356 };
      letpair_res_1818 = id_1819;
    }
    ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 let_res_1820;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_360 { letpair_res_1818 };
      ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 letpair_res_1821;
      {
        auto dsum1_fst_361 { std::get<0>(dsum1_360) };
        auto dsum1_snd_362 { std::get<1>(dsum1_360) };
        uint16_t id_1822 { 0 };
        bool id_1823 { bool(id_1822 == dsum1_fst_361) };
        ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 choose_res_1824;
        if (id_1823) {
          (void)::dessser::Void();
          ::dessser::gen::sync_key::dialog_key id_1825 { std::in_place_index<0>, ::dessser::Void() };
          ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 id_1826 { id_1825, dsum1_snd_362 };
          choose_res_1824 = id_1826;
        } else {
          uint16_t id_1827 { 1 };
          bool id_1828 { bool(id_1827 == dsum1_fst_361) };
          ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 choose_res_1829;
          if (id_1828) {
            (void)::dessser::Void();
            ::dessser::gen::sync_key::dialog_key id_1830 { std::in_place_index<1>, ::dessser::Void() };
            ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 id_1831 { id_1830, dsum1_snd_362 };
            choose_res_1829 = id_1831;
          } else {
            uint16_t id_1832 { 2 };
            bool id_1833 { bool(id_1832 == dsum1_fst_361) };
            ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 choose_res_1834;
            if (id_1833) {
              (void)::dessser::Void();
              ::dessser::gen::sync_key::dialog_key id_1835 { std::in_place_index<2>, ::dessser::Void() };
              ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 id_1836 { id_1835, dsum1_snd_362 };
              choose_res_1834 = id_1836;
            } else {
              uint16_t id_1837 { 3 };
              bool id_1838 { bool(id_1837 == dsum1_fst_361) };
              ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 choose_res_1839;
              if (id_1838) {
                (void)::dessser::Void();
                ::dessser::gen::sync_key::dialog_key id_1840 { std::in_place_index<3>, ::dessser::Void() };
                ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 id_1841 { id_1840, dsum1_snd_362 };
                choose_res_1839 = id_1841;
              } else {
                uint16_t id_1842 { 4 };
                bool id_1843 { bool(id_1842 == dsum1_fst_361) };
                ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 choose_res_1844;
                if (id_1843) {
                  (void)::dessser::Void();
                  ::dessser::gen::sync_key::dialog_key id_1845 { std::in_place_index<4>, ::dessser::Void() };
                  ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 id_1846 { id_1845, dsum1_snd_362 };
                  choose_res_1844 = id_1846;
                } else {
                  uint16_t id_1847 { 5 };
                  bool id_1848 { bool(id_1847 == dsum1_fst_361) };
                  ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 choose_res_1849;
                  if (id_1848) {
                    (void)::dessser::Void();
                    ::dessser::gen::sync_key::dialog_key id_1850 { std::in_place_index<5>, ::dessser::Void() };
                    ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 id_1851 { id_1850, dsum1_snd_362 };
                    choose_res_1849 = id_1851;
                  } else {
                    uint16_t id_1852 { 6 };
                    bool id_1853 { bool(dsum1_fst_361 == id_1852) };
                    Void id_1854 { ((void)(assert(id_1853)), ::dessser::Void()) };
                    (void)id_1854;
                    (void)::dessser::Void();
                    ::dessser::gen::sync_key::dialog_key id_1855 { std::in_place_index<6>, ::dessser::Void() };
                    ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 id_1856 { id_1855, dsum1_snd_362 };
                    choose_res_1849 = id_1856;
                  }
                  choose_res_1844 = choose_res_1849;
                }
                choose_res_1839 = choose_res_1844;
              }
              choose_res_1834 = choose_res_1839;
            }
            choose_res_1829 = choose_res_1834;
          }
          choose_res_1824 = choose_res_1829;
        }
        letpair_res_1821 = choose_res_1824;
      }
      let_res_1820 = letpair_res_1821;
    }
    return let_res_1820;
  }
   };
  return fun1816;
}
std::function<::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25(Pointer &)> dialog_key_of_row_binary(dialog_key_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_390" (let-pair "du16_fst_385" "du16_snd_386" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_385") (identifier "du16_snd_386")))
        (let-pair "dsum1_fst_391" "dsum1_snd_392" (identifier "dsum1_390")
          (if (eq (u16 0) (identifier "dsum1_fst_391"))
            (make-tup
              (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 0
                (nop)) (identifier "dsum1_snd_392"))
            (if (eq (u16 1) (identifier "dsum1_fst_391"))
              (make-tup
                (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 1
                  (nop)) (identifier "dsum1_snd_392"))
              (if (eq (u16 2) (identifier "dsum1_fst_391"))
                (make-tup
                  (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 2
                    (nop)) (identifier "dsum1_snd_392"))
                (if (eq (u16 3) (identifier "dsum1_fst_391"))
                  (make-tup
                    (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 3
                      (nop)) (identifier "dsum1_snd_392"))
                  (if (eq (u16 4) (identifier "dsum1_fst_391"))
                    (make-tup
                      (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 4
                        (nop)) (identifier "dsum1_snd_392"))
                    (if (eq (u16 5) (identifier "dsum1_fst_391"))
                      (let "dtup_420"
                        (let "dstring1_414"
                          (let "leb_ref_408" (make-vec (u32 0))
                            (let "shft_ref_409" (make-vec (u8 0))
                              (let "p_ref_410" (make-vec (identifier "dsum1_snd_392"))
                                (seq
                                  (while
                                    (let "leb128_411" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_410")))
                                      (let-pair "leb128_fst_412" "leb128_snd_413" 
                                        (identifier "leb128_411")
                                        (seq (set-vec (u8 0) (identifier "p_ref_410") (identifier "leb128_snd_413"))
                                          (set-vec (u8 0) (identifier "leb_ref_408")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_412") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_409"))) (unsafe-nth (u8 0) (identifier "leb_ref_408"))))
                                          (set-vec (u8 0) (identifier "shft_ref_409") (add (unsafe-nth (u8 0) (identifier "shft_ref_409")) (u8 7))) 
                                          (ge (identifier "leb128_fst_412") (u8 128))))) 
                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_408"))) (unsafe-nth (u8 0) (identifier "p_ref_410")))))))
                          (let-pair "dstring1_fst_415" "dstring1_snd_416" 
                            (identifier "dstring1_414")
                            (let-pair "dstring2_fst_418" "dstring2_snd_419" 
                              (read-bytes (identifier "dstring1_snd_416") (identifier "dstring1_fst_415")) 
                              (make-tup (string-of-bytes (identifier "dstring2_fst_418")) (identifier "dstring2_snd_419")))))
                        (let-pair "dtup_fst_421" "dtup_snd_422" (identifier "dtup_420")
                          (let-pair "dtup_fst_424" "dtup_snd_425" (apply (identifier "dialog_key-of-row-binary") (identifier "dtup_snd_422"))
                            (make-tup
                              (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 5
                                (make-tup (identifier "dtup_fst_421") (identifier "dtup_fst_424"))) 
                              (identifier "dtup_snd_425")))))
                      (seq (assert (eq (identifier "dsum1_fst_391") (u16 6)))
                        (let "dtup_396" (let-pair "dfloat_fst_394" "dfloat_snd_395" (read-u64 little-endian (identifier "dsum1_snd_392")) (make-tup (float-of-u64 (identifier "dfloat_fst_394")) (identifier "dfloat_snd_395")))
                          (let-pair "dtup_fst_397" "dtup_snd_398" (identifier "dtup_396")
                            (let-pair "du32_fst_400" "du32_snd_401" (read-u32 little-endian (identifier "dtup_snd_398"))
                              (make-tup
                                (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 6
                                  (make-tup (identifier "dtup_fst_397") (identifier "du32_fst_400"))) 
                                (identifier "du32_snd_401")))))))))))))))
 */
static std::function<::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4(Pointer &)> incident_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4(Pointer &)> fun1857 { [&](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1858 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1859;
    {
      auto du16_fst_385 { std::get<0>(id_1858) };
      auto du16_snd_386 { std::get<1>(id_1858) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1860 { du16_fst_385, du16_snd_386 };
      letpair_res_1859 = id_1860;
    }
    ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 let_res_1861;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_390 { letpair_res_1859 };
      ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 letpair_res_1862;
      {
        auto dsum1_fst_391 { std::get<0>(dsum1_390) };
        auto dsum1_snd_392 { std::get<1>(dsum1_390) };
        uint16_t id_1863 { 0 };
        bool id_1864 { bool(id_1863 == dsum1_fst_391) };
        ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 choose_res_1865;
        if (id_1864) {
          (void)::dessser::Void();
          ::dessser::gen::sync_key::incident_key id_1866 { std::in_place_index<0>, ::dessser::Void() };
          ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 id_1867 { id_1866, dsum1_snd_392 };
          choose_res_1865 = id_1867;
        } else {
          uint16_t id_1868 { 1 };
          bool id_1869 { bool(id_1868 == dsum1_fst_391) };
          ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 choose_res_1870;
          if (id_1869) {
            (void)::dessser::Void();
            ::dessser::gen::sync_key::incident_key id_1871 { std::in_place_index<1>, ::dessser::Void() };
            ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 id_1872 { id_1871, dsum1_snd_392 };
            choose_res_1870 = id_1872;
          } else {
            uint16_t id_1873 { 2 };
            bool id_1874 { bool(id_1873 == dsum1_fst_391) };
            ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 choose_res_1875;
            if (id_1874) {
              (void)::dessser::Void();
              ::dessser::gen::sync_key::incident_key id_1876 { std::in_place_index<2>, ::dessser::Void() };
              ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 id_1877 { id_1876, dsum1_snd_392 };
              choose_res_1875 = id_1877;
            } else {
              uint16_t id_1878 { 3 };
              bool id_1879 { bool(id_1878 == dsum1_fst_391) };
              ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 choose_res_1880;
              if (id_1879) {
                (void)::dessser::Void();
                ::dessser::gen::sync_key::incident_key id_1881 { std::in_place_index<3>, ::dessser::Void() };
                ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 id_1882 { id_1881, dsum1_snd_392 };
                choose_res_1880 = id_1882;
              } else {
                uint16_t id_1883 { 4 };
                bool id_1884 { bool(id_1883 == dsum1_fst_391) };
                ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 choose_res_1885;
                if (id_1884) {
                  (void)::dessser::Void();
                  ::dessser::gen::sync_key::incident_key id_1886 { std::in_place_index<4>, ::dessser::Void() };
                  ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 id_1887 { id_1886, dsum1_snd_392 };
                  choose_res_1885 = id_1887;
                } else {
                  uint16_t id_1888 { 5 };
                  bool id_1889 { bool(id_1888 == dsum1_fst_391) };
                  ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 choose_res_1890;
                  if (id_1889) {
                    uint32_t id_1891 { 0U };
                    Vec<1, uint32_t> id_1892 {  id_1891  };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1893;
                    {
                      Vec<1, uint32_t> leb_ref_408 { id_1892 };
                      uint8_t id_1894 { 0 };
                      Vec<1, uint8_t> id_1895 {  id_1894  };
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1896;
                      {
                        Vec<1, uint8_t> shft_ref_409 { id_1895 };
                        Vec<1, Pointer> id_1897 {  dsum1_snd_392  };
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1898;
                        {
                          Vec<1, Pointer> p_ref_410 { id_1897 };
                          bool while_flag_1899 { true };
                          do {
                            uint8_t id_1900 { 0 };
                            Pointer id_1901 { p_ref_410[id_1900] };
                            ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_1902 { id_1901.readU8() };
                            bool let_res_1903;
                            {
                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_411 { id_1902 };
                              bool letpair_res_1904;
                              {
                                auto leb128_fst_412 { std::get<0>(leb128_411) };
                                auto leb128_snd_413 { std::get<1>(leb128_411) };
                                uint8_t id_1905 { 0 };
                                Void id_1906 { ((void)(p_ref_410[id_1905] = leb128_snd_413), ::dessser::Void()) };
                                (void)id_1906;
                                uint8_t id_1907 { 0 };
                                uint8_t id_1908 { 127 };
                                uint8_t id_1909 { uint8_t(leb128_fst_412 & id_1908) };
                                uint32_t id_1910 { uint32_t(id_1909) };
                                uint8_t id_1911 { 0 };
                                uint8_t id_1912 { shft_ref_409[id_1911] };
                                uint32_t id_1913 { uint32_t(id_1910 << id_1912) };
                                uint8_t id_1914 { 0 };
                                uint32_t id_1915 { leb_ref_408[id_1914] };
                                uint32_t id_1916 { uint32_t(id_1913 | id_1915) };
                                Void id_1917 { ((void)(leb_ref_408[id_1907] = id_1916), ::dessser::Void()) };
                                (void)id_1917;
                                uint8_t id_1918 { 0 };
                                uint8_t id_1919 { 0 };
                                uint8_t id_1920 { shft_ref_409[id_1919] };
                                uint8_t id_1921 { 7 };
                                uint8_t id_1922 { uint8_t(id_1920 + id_1921) };
                                Void id_1923 { ((void)(shft_ref_409[id_1918] = id_1922), ::dessser::Void()) };
                                (void)id_1923;
                                uint8_t id_1924 { 128 };
                                bool id_1925 { bool(leb128_fst_412 >= id_1924) };
                                letpair_res_1904 = id_1925;
                              }
                              let_res_1903 = letpair_res_1904;
                            }
                            while_flag_1899 = let_res_1903;
                            if (while_flag_1899) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_1899);
                          (void)::dessser::Void();
                          uint8_t id_1926 { 0 };
                          uint32_t id_1927 { leb_ref_408[id_1926] };
                          Size id_1928 { Size(id_1927) };
                          uint8_t id_1929 { 0 };
                          Pointer id_1930 { p_ref_410[id_1929] };
                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_1931 { id_1928, id_1930 };
                          let_res_1898 = id_1931;
                        }
                        let_res_1896 = let_res_1898;
                      }
                      let_res_1893 = let_res_1896;
                    }
                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_1932;
                    {
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_414 { let_res_1893 };
                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_1933;
                      {
                        auto dstring1_fst_415 { std::get<0>(dstring1_414) };
                        auto dstring1_snd_416 { std::get<1>(dstring1_414) };
                        ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_1934 { dstring1_snd_416.readBytes(dstring1_fst_415) };
                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_1935;
                        {
                          auto dstring2_fst_418 { std::get<0>(id_1934) };
                          auto dstring2_snd_419 { std::get<1>(id_1934) };
                          std::string id_1936 { dstring2_fst_418.toString() };
                          ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_1937 { id_1936, dstring2_snd_419 };
                          letpair_res_1935 = id_1937;
                        }
                        letpair_res_1933 = letpair_res_1935;
                      }
                      let_res_1932 = letpair_res_1933;
                    }
                    ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 let_res_1938;
                    {
                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_420 { let_res_1932 };
                      ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 letpair_res_1939;
                      {
                        auto dtup_fst_421 { std::get<0>(dtup_420) };
                        auto dtup_snd_422 { std::get<1>(dtup_420) };
                        ::dessser::gen::sync_key::t0f2a9fd478dd335e4b2f4a474357fd25 id_1940 { dialog_key_of_row_binary(dtup_snd_422) };
                        ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 letpair_res_1941;
                        {
                          auto dtup_fst_424 { std::get<0>(id_1940) };
                          auto dtup_snd_425 { std::get<1>(id_1940) };
                          ::dessser::gen::sync_key::t0e35f6d3419a3939b7cd57375b12fe4d id_1942 { dtup_fst_421, dtup_fst_424 };
                          ::dessser::gen::sync_key::incident_key id_1943 { std::in_place_index<5>, id_1942 };
                          ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 id_1944 { id_1943, dtup_snd_425 };
                          letpair_res_1941 = id_1944;
                        }
                        letpair_res_1939 = letpair_res_1941;
                      }
                      let_res_1938 = letpair_res_1939;
                    }
                    choose_res_1890 = let_res_1938;
                  } else {
                    uint16_t id_1945 { 6 };
                    bool id_1946 { bool(dsum1_fst_391 == id_1945) };
                    Void id_1947 { ((void)(assert(id_1946)), ::dessser::Void()) };
                    (void)id_1947;
                    ::dessser::gen::sync_key::td2cd337bb3c8bc04d5603393d084985b id_1948 { dsum1_snd_392.readU64Le() };
                    ::dessser::gen::sync_key::t9a758baeff17224a77e1a522010b4168 letpair_res_1949;
                    {
                      auto dfloat_fst_394 { std::get<0>(id_1948) };
                      auto dfloat_snd_395 { std::get<1>(id_1948) };
                      double id_1950 { float_of_qword(dfloat_fst_394) };
                      ::dessser::gen::sync_key::t9a758baeff17224a77e1a522010b4168 id_1951 { id_1950, dfloat_snd_395 };
                      letpair_res_1949 = id_1951;
                    }
                    ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 let_res_1952;
                    {
                      ::dessser::gen::sync_key::t9a758baeff17224a77e1a522010b4168 dtup_396 { letpair_res_1949 };
                      ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 letpair_res_1953;
                      {
                        auto dtup_fst_397 { std::get<0>(dtup_396) };
                        auto dtup_snd_398 { std::get<1>(dtup_396) };
                        ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_1954 { dtup_snd_398.readU32Le() };
                        ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 letpair_res_1955;
                        {
                          auto du32_fst_400 { std::get<0>(id_1954) };
                          auto du32_snd_401 { std::get<1>(id_1954) };
                          ::dessser::gen::sync_key::t9782147647347738b31cd77850bfc224 id_1956 { dtup_fst_397, du32_fst_400 };
                          ::dessser::gen::sync_key::incident_key id_1957 { std::in_place_index<6>, id_1956 };
                          ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 id_1958 { id_1957, du32_snd_401 };
                          letpair_res_1955 = id_1958;
                        }
                        letpair_res_1953 = letpair_res_1955;
                      }
                      let_res_1952 = letpair_res_1953;
                    }
                    choose_res_1890 = let_res_1952;
                  }
                  choose_res_1885 = choose_res_1890;
                }
                choose_res_1880 = choose_res_1885;
              }
              choose_res_1875 = choose_res_1880;
            }
            choose_res_1870 = choose_res_1875;
          }
          choose_res_1865 = choose_res_1870;
        }
        letpair_res_1862 = choose_res_1865;
      }
      let_res_1861 = letpair_res_1862;
    }
    return let_res_1861;
  }
   };
  return fun1857;
}
std::function<::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4(Pointer &)> incident_key_of_row_binary(incident_key_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_321" (let-pair "du16_fst_316" "du16_snd_317" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_316") (identifier "du16_snd_317")))
        (let-pair "dsum1_fst_322" "dsum1_snd_323" (identifier "dsum1_321")
          (if (eq (u16 0) (identifier "dsum1_fst_322"))
            (let "dstring1_345"
              (let "leb_ref_339" (make-vec (u32 0))
                (let "shft_ref_340" (make-vec (u8 0))
                  (let "p_ref_341" (make-vec (identifier "dsum1_snd_323"))
                    (seq
                      (while
                        (let "leb128_342" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_341")))
                          (let-pair "leb128_fst_343" "leb128_snd_344" 
                            (identifier "leb128_342")
                            (seq (set-vec (u8 0) (identifier "p_ref_341") (identifier "leb128_snd_344"))
                              (set-vec (u8 0) (identifier "leb_ref_339")
                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_343") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_340"))) (unsafe-nth (u8 0) (identifier "leb_ref_339"))))
                              (set-vec (u8 0) (identifier "shft_ref_340") (add (unsafe-nth (u8 0) (identifier "shft_ref_340")) (u8 7))) 
                              (ge (identifier "leb128_fst_343") (u8 128))))) 
                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_339"))) (unsafe-nth (u8 0) (identifier "p_ref_341")))))))
              (let-pair "dstring1_fst_346" "dstring1_snd_347" (identifier "dstring1_345")
                (let-pair "dstring2_fst_349" "dstring2_snd_350" (read-bytes (identifier "dstring1_snd_347") (identifier "dstring1_fst_346"))
                  (make-tup (construct "[Contacts STRING | Inhibition STRING]" 0 (string-of-bytes (identifier "dstring2_fst_349"))) (identifier "dstring2_snd_350")))))
            (seq (assert (eq (identifier "dsum1_fst_322") (u16 1)))
              (let "dstring1_330"
                (let "leb_ref_324" (make-vec (u32 0))
                  (let "shft_ref_325" (make-vec (u8 0))
                    (let "p_ref_326" (make-vec (identifier "dsum1_snd_323"))
                      (seq
                        (while
                          (let "leb128_327" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_326")))
                            (let-pair "leb128_fst_328" "leb128_snd_329" 
                              (identifier "leb128_327")
                              (seq (set-vec (u8 0) (identifier "p_ref_326") (identifier "leb128_snd_329"))
                                (set-vec (u8 0) (identifier "leb_ref_324")
                                  (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_328") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_325"))) (unsafe-nth (u8 0) (identifier "leb_ref_324"))))
                                (set-vec (u8 0) (identifier "shft_ref_325") (add (unsafe-nth (u8 0) (identifier "shft_ref_325")) (u8 7))) 
                                (ge (identifier "leb128_fst_328") (u8 128))))) 
                          (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_324"))) (unsafe-nth (u8 0) (identifier "p_ref_326")))))))
                (let-pair "dstring1_fst_331" "dstring1_snd_332" (identifier "dstring1_330")
                  (let-pair "dstring2_fst_334" "dstring2_snd_335" (read-bytes (identifier "dstring1_snd_332") (identifier "dstring1_fst_331"))
                    (make-tup (construct "[Contacts STRING | Inhibition STRING]" 1 (string-of-bytes (identifier "dstring2_fst_334"))) (identifier "dstring2_snd_335"))))))))))
 */
static std::function<::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce(Pointer &)> team_key_info_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce(Pointer &)> fun1959 { [&](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1960 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1961;
    {
      auto du16_fst_316 { std::get<0>(id_1960) };
      auto du16_snd_317 { std::get<1>(id_1960) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1962 { du16_fst_316, du16_snd_317 };
      letpair_res_1961 = id_1962;
    }
    ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce let_res_1963;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_321 { letpair_res_1961 };
      ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce letpair_res_1964;
      {
        auto dsum1_fst_322 { std::get<0>(dsum1_321) };
        auto dsum1_snd_323 { std::get<1>(dsum1_321) };
        uint16_t id_1965 { 0 };
        bool id_1966 { bool(id_1965 == dsum1_fst_322) };
        ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce choose_res_1967;
        if (id_1966) {
          uint32_t id_1968 { 0U };
          Vec<1, uint32_t> id_1969 {  id_1968  };
          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1970;
          {
            Vec<1, uint32_t> leb_ref_339 { id_1969 };
            uint8_t id_1971 { 0 };
            Vec<1, uint8_t> id_1972 {  id_1971  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1973;
            {
              Vec<1, uint8_t> shft_ref_340 { id_1972 };
              Vec<1, Pointer> id_1974 {  dsum1_snd_323  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1975;
              {
                Vec<1, Pointer> p_ref_341 { id_1974 };
                bool while_flag_1976 { true };
                do {
                  uint8_t id_1977 { 0 };
                  Pointer id_1978 { p_ref_341[id_1977] };
                  ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_1979 { id_1978.readU8() };
                  bool let_res_1980;
                  {
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_342 { id_1979 };
                    bool letpair_res_1981;
                    {
                      auto leb128_fst_343 { std::get<0>(leb128_342) };
                      auto leb128_snd_344 { std::get<1>(leb128_342) };
                      uint8_t id_1982 { 0 };
                      Void id_1983 { ((void)(p_ref_341[id_1982] = leb128_snd_344), ::dessser::Void()) };
                      (void)id_1983;
                      uint8_t id_1984 { 0 };
                      uint8_t id_1985 { 127 };
                      uint8_t id_1986 { uint8_t(leb128_fst_343 & id_1985) };
                      uint32_t id_1987 { uint32_t(id_1986) };
                      uint8_t id_1988 { 0 };
                      uint8_t id_1989 { shft_ref_340[id_1988] };
                      uint32_t id_1990 { uint32_t(id_1987 << id_1989) };
                      uint8_t id_1991 { 0 };
                      uint32_t id_1992 { leb_ref_339[id_1991] };
                      uint32_t id_1993 { uint32_t(id_1990 | id_1992) };
                      Void id_1994 { ((void)(leb_ref_339[id_1984] = id_1993), ::dessser::Void()) };
                      (void)id_1994;
                      uint8_t id_1995 { 0 };
                      uint8_t id_1996 { 0 };
                      uint8_t id_1997 { shft_ref_340[id_1996] };
                      uint8_t id_1998 { 7 };
                      uint8_t id_1999 { uint8_t(id_1997 + id_1998) };
                      Void id_2000 { ((void)(shft_ref_340[id_1995] = id_1999), ::dessser::Void()) };
                      (void)id_2000;
                      uint8_t id_2001 { 128 };
                      bool id_2002 { bool(leb128_fst_343 >= id_2001) };
                      letpair_res_1981 = id_2002;
                    }
                    let_res_1980 = letpair_res_1981;
                  }
                  while_flag_1976 = let_res_1980;
                  if (while_flag_1976) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_1976);
                (void)::dessser::Void();
                uint8_t id_2003 { 0 };
                uint32_t id_2004 { leb_ref_339[id_2003] };
                Size id_2005 { Size(id_2004) };
                uint8_t id_2006 { 0 };
                Pointer id_2007 { p_ref_341[id_2006] };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2008 { id_2005, id_2007 };
                let_res_1975 = id_2008;
              }
              let_res_1973 = let_res_1975;
            }
            let_res_1970 = let_res_1973;
          }
          ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce let_res_2009;
          {
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_345 { let_res_1970 };
            ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce letpair_res_2010;
            {
              auto dstring1_fst_346 { std::get<0>(dstring1_345) };
              auto dstring1_snd_347 { std::get<1>(dstring1_345) };
              ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2011 { dstring1_snd_347.readBytes(dstring1_fst_346) };
              ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce letpair_res_2012;
              {
                auto dstring2_fst_349 { std::get<0>(id_2011) };
                auto dstring2_snd_350 { std::get<1>(id_2011) };
                std::string id_2013 { dstring2_fst_349.toString() };
                ::dessser::gen::sync_key::team_key_info id_2014 { std::in_place_index<0>, id_2013 };
                ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce id_2015 { id_2014, dstring2_snd_350 };
                letpair_res_2012 = id_2015;
              }
              letpair_res_2010 = letpair_res_2012;
            }
            let_res_2009 = letpair_res_2010;
          }
          choose_res_1967 = let_res_2009;
        } else {
          uint16_t id_2016 { 1 };
          bool id_2017 { bool(dsum1_fst_322 == id_2016) };
          Void id_2018 { ((void)(assert(id_2017)), ::dessser::Void()) };
          (void)id_2018;
          uint32_t id_2019 { 0U };
          Vec<1, uint32_t> id_2020 {  id_2019  };
          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2021;
          {
            Vec<1, uint32_t> leb_ref_324 { id_2020 };
            uint8_t id_2022 { 0 };
            Vec<1, uint8_t> id_2023 {  id_2022  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2024;
            {
              Vec<1, uint8_t> shft_ref_325 { id_2023 };
              Vec<1, Pointer> id_2025 {  dsum1_snd_323  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2026;
              {
                Vec<1, Pointer> p_ref_326 { id_2025 };
                bool while_flag_2027 { true };
                do {
                  uint8_t id_2028 { 0 };
                  Pointer id_2029 { p_ref_326[id_2028] };
                  ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2030 { id_2029.readU8() };
                  bool let_res_2031;
                  {
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_327 { id_2030 };
                    bool letpair_res_2032;
                    {
                      auto leb128_fst_328 { std::get<0>(leb128_327) };
                      auto leb128_snd_329 { std::get<1>(leb128_327) };
                      uint8_t id_2033 { 0 };
                      Void id_2034 { ((void)(p_ref_326[id_2033] = leb128_snd_329), ::dessser::Void()) };
                      (void)id_2034;
                      uint8_t id_2035 { 0 };
                      uint8_t id_2036 { 127 };
                      uint8_t id_2037 { uint8_t(leb128_fst_328 & id_2036) };
                      uint32_t id_2038 { uint32_t(id_2037) };
                      uint8_t id_2039 { 0 };
                      uint8_t id_2040 { shft_ref_325[id_2039] };
                      uint32_t id_2041 { uint32_t(id_2038 << id_2040) };
                      uint8_t id_2042 { 0 };
                      uint32_t id_2043 { leb_ref_324[id_2042] };
                      uint32_t id_2044 { uint32_t(id_2041 | id_2043) };
                      Void id_2045 { ((void)(leb_ref_324[id_2035] = id_2044), ::dessser::Void()) };
                      (void)id_2045;
                      uint8_t id_2046 { 0 };
                      uint8_t id_2047 { 0 };
                      uint8_t id_2048 { shft_ref_325[id_2047] };
                      uint8_t id_2049 { 7 };
                      uint8_t id_2050 { uint8_t(id_2048 + id_2049) };
                      Void id_2051 { ((void)(shft_ref_325[id_2046] = id_2050), ::dessser::Void()) };
                      (void)id_2051;
                      uint8_t id_2052 { 128 };
                      bool id_2053 { bool(leb128_fst_328 >= id_2052) };
                      letpair_res_2032 = id_2053;
                    }
                    let_res_2031 = letpair_res_2032;
                  }
                  while_flag_2027 = let_res_2031;
                  if (while_flag_2027) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_2027);
                (void)::dessser::Void();
                uint8_t id_2054 { 0 };
                uint32_t id_2055 { leb_ref_324[id_2054] };
                Size id_2056 { Size(id_2055) };
                uint8_t id_2057 { 0 };
                Pointer id_2058 { p_ref_326[id_2057] };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2059 { id_2056, id_2058 };
                let_res_2026 = id_2059;
              }
              let_res_2024 = let_res_2026;
            }
            let_res_2021 = let_res_2024;
          }
          ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce let_res_2060;
          {
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_330 { let_res_2021 };
            ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce letpair_res_2061;
            {
              auto dstring1_fst_331 { std::get<0>(dstring1_330) };
              auto dstring1_snd_332 { std::get<1>(dstring1_330) };
              ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2062 { dstring1_snd_332.readBytes(dstring1_fst_331) };
              ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce letpair_res_2063;
              {
                auto dstring2_fst_334 { std::get<0>(id_2062) };
                auto dstring2_snd_335 { std::get<1>(id_2062) };
                std::string id_2064 { dstring2_fst_334.toString() };
                ::dessser::gen::sync_key::team_key_info id_2065 { std::in_place_index<1>, id_2064 };
                ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce id_2066 { id_2065, dstring2_snd_335 };
                letpair_res_2063 = id_2066;
              }
              letpair_res_2061 = letpair_res_2063;
            }
            let_res_2060 = letpair_res_2061;
          }
          choose_res_1967 = let_res_2060;
        }
        letpair_res_1964 = choose_res_1967;
      }
      let_res_1963 = letpair_res_1964;
    }
    return let_res_1963;
  }
   };
  return fun1959;
}
std::function<::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce(Pointer &)> team_key_info_of_row_binary(team_key_info_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_279" (let-pair "du16_fst_274" "du16_snd_275" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_274") (identifier "du16_snd_275")))
        (let-pair "dsum1_fst_280" "dsum1_snd_281" (identifier "dsum1_279")
          (seq (assert (eq (identifier "dsum1_fst_280") (u16 0)))
            (let-pair "du32_fst_283" "du32_snd_284" (read-u32 little-endian (identifier "dsum1_snd_281")) (make-tup (construct "[Widgets U32]" 0 (identifier "du32_fst_283")) (identifier "du32_snd_284")))))))
 */
static std::function<::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713(Pointer &)> per_dash_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713(Pointer &)> fun2067 { [&](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2068 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2069;
    {
      auto du16_fst_274 { std::get<0>(id_2068) };
      auto du16_snd_275 { std::get<1>(id_2068) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2070 { du16_fst_274, du16_snd_275 };
      letpair_res_2069 = id_2070;
    }
    ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 let_res_2071;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_279 { letpair_res_2069 };
      ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 letpair_res_2072;
      {
        auto dsum1_fst_280 { std::get<0>(dsum1_279) };
        auto dsum1_snd_281 { std::get<1>(dsum1_279) };
        uint16_t id_2073 { 0 };
        bool id_2074 { bool(dsum1_fst_280 == id_2073) };
        Void id_2075 { ((void)(assert(id_2074)), ::dessser::Void()) };
        (void)id_2075;
        ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_2076 { dsum1_snd_281.readU32Le() };
        ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 letpair_res_2077;
        {
          auto du32_fst_283 { std::get<0>(id_2076) };
          auto du32_snd_284 { std::get<1>(id_2076) };
          std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_2078 { std::make_shared<::dessser::gen::sync_key::per_dash_key>(std::in_place_index<0>, du32_fst_283) };
          ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 id_2079 { id_2078, du32_snd_284 };
          letpair_res_2077 = id_2079;
        }
        letpair_res_2072 = letpair_res_2077;
      }
      let_res_2071 = letpair_res_2072;
    }
    return let_res_2071;
  }
   };
  return fun2067;
}
std::function<::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713(Pointer &)> per_dash_key_of_row_binary(per_dash_key_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_294" (let-pair "du16_fst_289" "du16_snd_290" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_289") (identifier "du16_snd_290")))
        (let-pair "dsum1_fst_295" "dsum1_snd_296" (identifier "dsum1_294")
          (if (eq (u16 0) (identifier "dsum1_fst_295"))
            (let "dstring1_306"
              (let "leb_ref_300" (make-vec (u32 0))
                (let "shft_ref_301" (make-vec (u8 0))
                  (let "p_ref_302" (make-vec (identifier "dsum1_snd_296"))
                    (seq
                      (while
                        (let "leb128_303" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_302")))
                          (let-pair "leb128_fst_304" "leb128_snd_305" 
                            (identifier "leb128_303")
                            (seq (set-vec (u8 0) (identifier "p_ref_302") (identifier "leb128_snd_305"))
                              (set-vec (u8 0) (identifier "leb_ref_300")
                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_304") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_301"))) (unsafe-nth (u8 0) (identifier "leb_ref_300"))))
                              (set-vec (u8 0) (identifier "shft_ref_301") (add (unsafe-nth (u8 0) (identifier "shft_ref_301")) (u8 7))) 
                              (ge (identifier "leb128_fst_304") (u8 128))))) 
                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_300"))) (unsafe-nth (u8 0) (identifier "p_ref_302")))))))
              (let-pair "dstring1_fst_307" "dstring1_snd_308" (identifier "dstring1_306")
                (let-pair "dstring2_fst_310" "dstring2_snd_311" (read-bytes (identifier "dstring1_snd_308") (identifier "dstring1_fst_307"))
                  (make-tup (construct "[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" 0 (string-of-bytes (identifier "dstring2_fst_310"))) (identifier "dstring2_snd_311")))))
            (seq (assert (eq (identifier "dsum1_fst_295") (u16 1)))
              (let-pair "dsum2_fst_298" "dsum2_snd_299" (apply (identifier "per_dash_key-of-row-binary") (identifier "dsum1_snd_296"))
                (make-tup (construct "[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" 1 (identifier "dsum2_fst_298")) (identifier "dsum2_snd_299"))))))))
 */
static std::function<::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783(Pointer &)> per_client_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783(Pointer &)> fun2080 { [&](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2081 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2082;
    {
      auto du16_fst_289 { std::get<0>(id_2081) };
      auto du16_snd_290 { std::get<1>(id_2081) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2083 { du16_fst_289, du16_snd_290 };
      letpair_res_2082 = id_2083;
    }
    ::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783 let_res_2084;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_294 { letpair_res_2082 };
      ::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783 letpair_res_2085;
      {
        auto dsum1_fst_295 { std::get<0>(dsum1_294) };
        auto dsum1_snd_296 { std::get<1>(dsum1_294) };
        uint16_t id_2086 { 0 };
        bool id_2087 { bool(id_2086 == dsum1_fst_295) };
        ::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783 choose_res_2088;
        if (id_2087) {
          uint32_t id_2089 { 0U };
          Vec<1, uint32_t> id_2090 {  id_2089  };
          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2091;
          {
            Vec<1, uint32_t> leb_ref_300 { id_2090 };
            uint8_t id_2092 { 0 };
            Vec<1, uint8_t> id_2093 {  id_2092  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2094;
            {
              Vec<1, uint8_t> shft_ref_301 { id_2093 };
              Vec<1, Pointer> id_2095 {  dsum1_snd_296  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2096;
              {
                Vec<1, Pointer> p_ref_302 { id_2095 };
                bool while_flag_2097 { true };
                do {
                  uint8_t id_2098 { 0 };
                  Pointer id_2099 { p_ref_302[id_2098] };
                  ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2100 { id_2099.readU8() };
                  bool let_res_2101;
                  {
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_303 { id_2100 };
                    bool letpair_res_2102;
                    {
                      auto leb128_fst_304 { std::get<0>(leb128_303) };
                      auto leb128_snd_305 { std::get<1>(leb128_303) };
                      uint8_t id_2103 { 0 };
                      Void id_2104 { ((void)(p_ref_302[id_2103] = leb128_snd_305), ::dessser::Void()) };
                      (void)id_2104;
                      uint8_t id_2105 { 0 };
                      uint8_t id_2106 { 127 };
                      uint8_t id_2107 { uint8_t(leb128_fst_304 & id_2106) };
                      uint32_t id_2108 { uint32_t(id_2107) };
                      uint8_t id_2109 { 0 };
                      uint8_t id_2110 { shft_ref_301[id_2109] };
                      uint32_t id_2111 { uint32_t(id_2108 << id_2110) };
                      uint8_t id_2112 { 0 };
                      uint32_t id_2113 { leb_ref_300[id_2112] };
                      uint32_t id_2114 { uint32_t(id_2111 | id_2113) };
                      Void id_2115 { ((void)(leb_ref_300[id_2105] = id_2114), ::dessser::Void()) };
                      (void)id_2115;
                      uint8_t id_2116 { 0 };
                      uint8_t id_2117 { 0 };
                      uint8_t id_2118 { shft_ref_301[id_2117] };
                      uint8_t id_2119 { 7 };
                      uint8_t id_2120 { uint8_t(id_2118 + id_2119) };
                      Void id_2121 { ((void)(shft_ref_301[id_2116] = id_2120), ::dessser::Void()) };
                      (void)id_2121;
                      uint8_t id_2122 { 128 };
                      bool id_2123 { bool(leb128_fst_304 >= id_2122) };
                      letpair_res_2102 = id_2123;
                    }
                    let_res_2101 = letpair_res_2102;
                  }
                  while_flag_2097 = let_res_2101;
                  if (while_flag_2097) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_2097);
                (void)::dessser::Void();
                uint8_t id_2124 { 0 };
                uint32_t id_2125 { leb_ref_300[id_2124] };
                Size id_2126 { Size(id_2125) };
                uint8_t id_2127 { 0 };
                Pointer id_2128 { p_ref_302[id_2127] };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2129 { id_2126, id_2128 };
                let_res_2096 = id_2129;
              }
              let_res_2094 = let_res_2096;
            }
            let_res_2091 = let_res_2094;
          }
          ::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783 let_res_2130;
          {
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_306 { let_res_2091 };
            ::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783 letpair_res_2131;
            {
              auto dstring1_fst_307 { std::get<0>(dstring1_306) };
              auto dstring1_snd_308 { std::get<1>(dstring1_306) };
              ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2132 { dstring1_snd_308.readBytes(dstring1_fst_307) };
              ::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783 letpair_res_2133;
              {
                auto dstring2_fst_310 { std::get<0>(id_2132) };
                auto dstring2_snd_311 { std::get<1>(id_2132) };
                std::string id_2134 { dstring2_fst_310.toString() };
                ::dessser::gen::sync_key::per_client id_2135 { std::in_place_index<0>, id_2134 };
                ::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783 id_2136 { id_2135, dstring2_snd_311 };
                letpair_res_2133 = id_2136;
              }
              letpair_res_2131 = letpair_res_2133;
            }
            let_res_2130 = letpair_res_2131;
          }
          choose_res_2088 = let_res_2130;
        } else {
          uint16_t id_2137 { 1 };
          bool id_2138 { bool(dsum1_fst_295 == id_2137) };
          Void id_2139 { ((void)(assert(id_2138)), ::dessser::Void()) };
          (void)id_2139;
          ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 id_2140 { per_dash_key_of_row_binary(dsum1_snd_296) };
          ::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783 letpair_res_2141;
          {
            auto dsum2_fst_298 { std::get<0>(id_2140) };
            auto dsum2_snd_299 { std::get<1>(id_2140) };
            ::dessser::gen::sync_key::per_client id_2142 { std::in_place_index<1>, dsum2_fst_298 };
            ::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783 id_2143 { id_2142, dsum2_snd_299 };
            letpair_res_2141 = id_2143;
          }
          choose_res_2088 = letpair_res_2141;
        }
        letpair_res_2085 = choose_res_2088;
      }
      let_res_2084 = letpair_res_2085;
    }
    return let_res_2084;
  }
   };
  return fun2080;
}
std::function<::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783(Pointer &)> per_client_of_row_binary(per_client_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_249" (let-pair "du16_fst_244" "du16_snd_245" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_244") (identifier "du16_snd_245")))
        (let-pair "dsum1_fst_250" "dsum1_snd_251" (identifier "dsum1_249")
          (if (eq (u16 0) (identifier "dsum1_fst_250"))
            (let "dstring1_264"
              (let "leb_ref_258" (make-vec (u32 0))
                (let "shft_ref_259" (make-vec (u8 0))
                  (let "p_ref_260" (make-vec (identifier "dsum1_snd_251"))
                    (seq
                      (while
                        (let "leb128_261" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_260")))
                          (let-pair "leb128_fst_262" "leb128_snd_263" 
                            (identifier "leb128_261")
                            (seq (set-vec (u8 0) (identifier "p_ref_260") (identifier "leb128_snd_263"))
                              (set-vec (u8 0) (identifier "leb_ref_258")
                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_262") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_259"))) (unsafe-nth (u8 0) (identifier "leb_ref_258"))))
                              (set-vec (u8 0) (identifier "shft_ref_259") (add (unsafe-nth (u8 0) (identifier "shft_ref_259")) (u8 7))) 
                              (ge (identifier "leb128_fst_262") (u8 128))))) 
                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_258"))) (unsafe-nth (u8 0) (identifier "p_ref_260")))))))
              (let-pair "dstring1_fst_265" "dstring1_snd_266" (identifier "dstring1_264")
                (let-pair "dstring2_fst_268" "dstring2_snd_269" (read-bytes (identifier "dstring1_snd_266") (identifier "dstring1_fst_265"))
                  (make-tup (construct "[Subscriber STRING | LastTuple U32]" 0 (string-of-bytes (identifier "dstring2_fst_268"))) (identifier "dstring2_snd_269")))))
            (seq (assert (eq (identifier "dsum1_fst_250") (u16 1)))
              (let-pair "du32_fst_253" "du32_snd_254" (read-u32 little-endian (identifier "dsum1_snd_251")) (make-tup (construct "[Subscriber STRING | LastTuple U32]" 1 (identifier "du32_fst_253")) (identifier "du32_snd_254"))))))))
 */
static std::function<::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9(Pointer &)> per_tail_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9(Pointer &)> fun2144 { [&](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2145 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2146;
    {
      auto du16_fst_244 { std::get<0>(id_2145) };
      auto du16_snd_245 { std::get<1>(id_2145) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2147 { du16_fst_244, du16_snd_245 };
      letpair_res_2146 = id_2147;
    }
    ::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9 let_res_2148;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_249 { letpair_res_2146 };
      ::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9 letpair_res_2149;
      {
        auto dsum1_fst_250 { std::get<0>(dsum1_249) };
        auto dsum1_snd_251 { std::get<1>(dsum1_249) };
        uint16_t id_2150 { 0 };
        bool id_2151 { bool(id_2150 == dsum1_fst_250) };
        ::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9 choose_res_2152;
        if (id_2151) {
          uint32_t id_2153 { 0U };
          Vec<1, uint32_t> id_2154 {  id_2153  };
          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2155;
          {
            Vec<1, uint32_t> leb_ref_258 { id_2154 };
            uint8_t id_2156 { 0 };
            Vec<1, uint8_t> id_2157 {  id_2156  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2158;
            {
              Vec<1, uint8_t> shft_ref_259 { id_2157 };
              Vec<1, Pointer> id_2159 {  dsum1_snd_251  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2160;
              {
                Vec<1, Pointer> p_ref_260 { id_2159 };
                bool while_flag_2161 { true };
                do {
                  uint8_t id_2162 { 0 };
                  Pointer id_2163 { p_ref_260[id_2162] };
                  ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2164 { id_2163.readU8() };
                  bool let_res_2165;
                  {
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_261 { id_2164 };
                    bool letpair_res_2166;
                    {
                      auto leb128_fst_262 { std::get<0>(leb128_261) };
                      auto leb128_snd_263 { std::get<1>(leb128_261) };
                      uint8_t id_2167 { 0 };
                      Void id_2168 { ((void)(p_ref_260[id_2167] = leb128_snd_263), ::dessser::Void()) };
                      (void)id_2168;
                      uint8_t id_2169 { 0 };
                      uint8_t id_2170 { 127 };
                      uint8_t id_2171 { uint8_t(leb128_fst_262 & id_2170) };
                      uint32_t id_2172 { uint32_t(id_2171) };
                      uint8_t id_2173 { 0 };
                      uint8_t id_2174 { shft_ref_259[id_2173] };
                      uint32_t id_2175 { uint32_t(id_2172 << id_2174) };
                      uint8_t id_2176 { 0 };
                      uint32_t id_2177 { leb_ref_258[id_2176] };
                      uint32_t id_2178 { uint32_t(id_2175 | id_2177) };
                      Void id_2179 { ((void)(leb_ref_258[id_2169] = id_2178), ::dessser::Void()) };
                      (void)id_2179;
                      uint8_t id_2180 { 0 };
                      uint8_t id_2181 { 0 };
                      uint8_t id_2182 { shft_ref_259[id_2181] };
                      uint8_t id_2183 { 7 };
                      uint8_t id_2184 { uint8_t(id_2182 + id_2183) };
                      Void id_2185 { ((void)(shft_ref_259[id_2180] = id_2184), ::dessser::Void()) };
                      (void)id_2185;
                      uint8_t id_2186 { 128 };
                      bool id_2187 { bool(leb128_fst_262 >= id_2186) };
                      letpair_res_2166 = id_2187;
                    }
                    let_res_2165 = letpair_res_2166;
                  }
                  while_flag_2161 = let_res_2165;
                  if (while_flag_2161) {
                    (void)::dessser::Void();
                  }
                } while (while_flag_2161);
                (void)::dessser::Void();
                uint8_t id_2188 { 0 };
                uint32_t id_2189 { leb_ref_258[id_2188] };
                Size id_2190 { Size(id_2189) };
                uint8_t id_2191 { 0 };
                Pointer id_2192 { p_ref_260[id_2191] };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2193 { id_2190, id_2192 };
                let_res_2160 = id_2193;
              }
              let_res_2158 = let_res_2160;
            }
            let_res_2155 = let_res_2158;
          }
          ::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9 let_res_2194;
          {
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_264 { let_res_2155 };
            ::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9 letpair_res_2195;
            {
              auto dstring1_fst_265 { std::get<0>(dstring1_264) };
              auto dstring1_snd_266 { std::get<1>(dstring1_264) };
              ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2196 { dstring1_snd_266.readBytes(dstring1_fst_265) };
              ::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9 letpair_res_2197;
              {
                auto dstring2_fst_268 { std::get<0>(id_2196) };
                auto dstring2_snd_269 { std::get<1>(id_2196) };
                std::string id_2198 { dstring2_fst_268.toString() };
                ::dessser::gen::sync_key::per_tail id_2199 { std::in_place_index<0>, id_2198 };
                ::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9 id_2200 { id_2199, dstring2_snd_269 };
                letpair_res_2197 = id_2200;
              }
              letpair_res_2195 = letpair_res_2197;
            }
            let_res_2194 = letpair_res_2195;
          }
          choose_res_2152 = let_res_2194;
        } else {
          uint16_t id_2201 { 1 };
          bool id_2202 { bool(dsum1_fst_250 == id_2201) };
          Void id_2203 { ((void)(assert(id_2202)), ::dessser::Void()) };
          (void)id_2203;
          ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_2204 { dsum1_snd_251.readU32Le() };
          ::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9 letpair_res_2205;
          {
            auto du32_fst_253 { std::get<0>(id_2204) };
            auto du32_snd_254 { std::get<1>(id_2204) };
            ::dessser::gen::sync_key::per_tail id_2206 { std::in_place_index<1>, du32_fst_253 };
            ::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9 id_2207 { id_2206, du32_snd_254 };
            letpair_res_2205 = id_2207;
          }
          choose_res_2152 = letpair_res_2205;
        }
        letpair_res_2149 = choose_res_2152;
      }
      let_res_2148 = letpair_res_2149;
    }
    return let_res_2148;
  }
   };
  return fun2144;
}
std::function<::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9(Pointer &)> per_tail_of_row_binary(per_tail_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_63" (let-pair "du16_fst_58" "du16_snd_59" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_58") (identifier "du16_snd_59")))
        (let-pair "dsum1_fst_64" "dsum1_snd_65" (identifier "dsum1_63")
          (if (eq (u16 0) (identifier "dsum1_fst_64"))
            (make-tup
              (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 0
                (nop)) (identifier "dsum1_snd_65"))
            (if (eq (u16 1) (identifier "dsum1_fst_64"))
              (make-tup
                (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 1
                  (nop)) (identifier "dsum1_snd_65"))
              (if (eq (u16 2) (identifier "dsum1_fst_64"))
                (make-tup
                  (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 2
                    (nop)) (identifier "dsum1_snd_65"))
                (if (eq (u16 3) (identifier "dsum1_fst_64"))
                  (make-tup
                    (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 3
                      (nop)) (identifier "dsum1_snd_65"))
                  (if (eq (u16 4) (identifier "dsum1_fst_64"))
                    (make-tup
                      (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 4
                        (nop)) (identifier "dsum1_snd_65"))
                    (if (eq (u16 5) (identifier "dsum1_fst_64"))
                      (make-tup
                        (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 5
                          (nop)) (identifier "dsum1_snd_65"))
                      (if (eq (u16 6) (identifier "dsum1_fst_64"))
                        (let "dtup_87"
                          (let "dstring1_81"
                            (let "leb_ref_75" (make-vec (u32 0))
                              (let "shft_ref_76" (make-vec (u8 0))
                                (let "p_ref_77" (make-vec (identifier "dsum1_snd_65"))
                                  (seq
                                    (while
                                      (let "leb128_78" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_77")))
                                        (let-pair "leb128_fst_79" "leb128_snd_80" 
                                          (identifier "leb128_78")
                                          (seq (set-vec (u8 0) (identifier "p_ref_77") (identifier "leb128_snd_80"))
                                            (set-vec (u8 0) (identifier "leb_ref_75")
                                              (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_79") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_76"))) (unsafe-nth (u8 0) (identifier "leb_ref_75"))))
                                            (set-vec (u8 0) (identifier "shft_ref_76") (add (unsafe-nth (u8 0) (identifier "shft_ref_76")) (u8 7))) 
                                            (ge (identifier "leb128_fst_79") (u8 128))))) 
                                      (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_75"))) (unsafe-nth (u8 0) (identifier "p_ref_77")))))))
                            (let-pair "dstring1_fst_82" "dstring1_snd_83" 
                              (identifier "dstring1_81")
                              (let-pair "dstring2_fst_85" "dstring2_snd_86" 
                                (read-bytes (identifier "dstring1_snd_83") (identifier "dstring1_fst_82")) 
                                (make-tup (string-of-bytes (identifier "dstring2_fst_85")) (identifier "dstring2_snd_86")))))
                          (let-pair "dtup_fst_88" "dtup_snd_89" (identifier "dtup_87")
                            (let-pair "dtup_fst_124" "dtup_snd_125"
                              (let "dsum1_96" (let-pair "du16_fst_91" "du16_snd_92" (read-u16 little-endian (identifier "dtup_snd_89")) (make-tup (identifier "du16_fst_91") (identifier "du16_snd_92")))
                                (let-pair "dsum1_fst_97" "dsum1_snd_98" 
                                  (identifier "dsum1_96")
                                  (if (eq (u16 0) (identifier "dsum1_fst_97"))
                                    (make-tup (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 0 (nop))
                                      (identifier "dsum1_snd_98"))
                                    (if (eq (u16 1) (identifier "dsum1_fst_97"))
                                      (make-tup (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 1 (nop))
                                        (identifier "dsum1_snd_98"))
                                      (if (eq (u16 2) (identifier "dsum1_fst_97"))
                                        (make-tup (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 2 (nop))
                                          (identifier "dsum1_snd_98"))
                                        (if (eq (u16 3) (identifier "dsum1_fst_97"))
                                          (make-tup (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 3 (nop))
                                            (identifier "dsum1_snd_98"))
                                          (if (eq (u16 4) (identifier "dsum1_fst_97"))
                                            (make-tup (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 4 (nop))
                                              (identifier "dsum1_snd_98"))
                                            (if (eq (u16 5) (identifier "dsum1_fst_97"))
                                              (make-tup
                                                (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 5 (nop))
                                                (identifier "dsum1_snd_98"))
                                              (if (eq (u16 6) (identifier "dsum1_fst_97"))
                                                (make-tup
                                                  (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 6 (nop))
                                                  (identifier "dsum1_snd_98"))
                                                (seq (assert (eq (identifier "dsum1_fst_97") (u16 7)))
                                                  (make-tup
                                                    (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 7 (nop))
                                                    (identifier "dsum1_snd_98"))))))))))))
                              (make-tup
                                (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 6
                                  (make-tup (identifier "dtup_fst_88") (identifier "dtup_fst_124"))) 
                                (identifier "dtup_snd_125")))))
                        (if (eq (u16 7) (identifier "dsum1_fst_64"))
                          (let-pair "du32_fst_70" "du32_snd_71" (read-u32 little-endian (identifier "dsum1_snd_65"))
                            (make-tup
                              (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 7
                                (identifier "du32_fst_70")) (identifier "du32_snd_71")))
                          (seq (assert (eq (identifier "dsum1_fst_64") (u16 8)))
                            (make-tup
                              (construct "[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" 8
                                (nop)) (identifier "dsum1_snd_65"))))))))))))))
 */
static std::function<::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc(Pointer &)> per_worker_data_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc(Pointer &)> fun2208 { [&](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2209 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2210;
    {
      auto du16_fst_58 { std::get<0>(id_2209) };
      auto du16_snd_59 { std::get<1>(id_2209) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2211 { du16_fst_58, du16_snd_59 };
      letpair_res_2210 = id_2211;
    }
    ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc let_res_2212;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_63 { letpair_res_2210 };
      ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc letpair_res_2213;
      {
        auto dsum1_fst_64 { std::get<0>(dsum1_63) };
        auto dsum1_snd_65 { std::get<1>(dsum1_63) };
        uint16_t id_2214 { 0 };
        bool id_2215 { bool(id_2214 == dsum1_fst_64) };
        ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc choose_res_2216;
        if (id_2215) {
          (void)::dessser::Void();
          ::dessser::gen::sync_key::per_worker_data id_2217 { std::in_place_index<0>, ::dessser::Void() };
          ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc id_2218 { id_2217, dsum1_snd_65 };
          choose_res_2216 = id_2218;
        } else {
          uint16_t id_2219 { 1 };
          bool id_2220 { bool(id_2219 == dsum1_fst_64) };
          ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc choose_res_2221;
          if (id_2220) {
            (void)::dessser::Void();
            ::dessser::gen::sync_key::per_worker_data id_2222 { std::in_place_index<1>, ::dessser::Void() };
            ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc id_2223 { id_2222, dsum1_snd_65 };
            choose_res_2221 = id_2223;
          } else {
            uint16_t id_2224 { 2 };
            bool id_2225 { bool(id_2224 == dsum1_fst_64) };
            ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc choose_res_2226;
            if (id_2225) {
              (void)::dessser::Void();
              ::dessser::gen::sync_key::per_worker_data id_2227 { std::in_place_index<2>, ::dessser::Void() };
              ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc id_2228 { id_2227, dsum1_snd_65 };
              choose_res_2226 = id_2228;
            } else {
              uint16_t id_2229 { 3 };
              bool id_2230 { bool(id_2229 == dsum1_fst_64) };
              ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc choose_res_2231;
              if (id_2230) {
                (void)::dessser::Void();
                ::dessser::gen::sync_key::per_worker_data id_2232 { std::in_place_index<3>, ::dessser::Void() };
                ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc id_2233 { id_2232, dsum1_snd_65 };
                choose_res_2231 = id_2233;
              } else {
                uint16_t id_2234 { 4 };
                bool id_2235 { bool(id_2234 == dsum1_fst_64) };
                ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc choose_res_2236;
                if (id_2235) {
                  (void)::dessser::Void();
                  ::dessser::gen::sync_key::per_worker_data id_2237 { std::in_place_index<4>, ::dessser::Void() };
                  ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc id_2238 { id_2237, dsum1_snd_65 };
                  choose_res_2236 = id_2238;
                } else {
                  uint16_t id_2239 { 5 };
                  bool id_2240 { bool(id_2239 == dsum1_fst_64) };
                  ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc choose_res_2241;
                  if (id_2240) {
                    (void)::dessser::Void();
                    ::dessser::gen::sync_key::per_worker_data id_2242 { std::in_place_index<5>, ::dessser::Void() };
                    ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc id_2243 { id_2242, dsum1_snd_65 };
                    choose_res_2241 = id_2243;
                  } else {
                    uint16_t id_2244 { 6 };
                    bool id_2245 { bool(id_2244 == dsum1_fst_64) };
                    ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc choose_res_2246;
                    if (id_2245) {
                      uint32_t id_2247 { 0U };
                      Vec<1, uint32_t> id_2248 {  id_2247  };
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2249;
                      {
                        Vec<1, uint32_t> leb_ref_75 { id_2248 };
                        uint8_t id_2250 { 0 };
                        Vec<1, uint8_t> id_2251 {  id_2250  };
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2252;
                        {
                          Vec<1, uint8_t> shft_ref_76 { id_2251 };
                          Vec<1, Pointer> id_2253 {  dsum1_snd_65  };
                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2254;
                          {
                            Vec<1, Pointer> p_ref_77 { id_2253 };
                            bool while_flag_2255 { true };
                            do {
                              uint8_t id_2256 { 0 };
                              Pointer id_2257 { p_ref_77[id_2256] };
                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2258 { id_2257.readU8() };
                              bool let_res_2259;
                              {
                                ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_78 { id_2258 };
                                bool letpair_res_2260;
                                {
                                  auto leb128_fst_79 { std::get<0>(leb128_78) };
                                  auto leb128_snd_80 { std::get<1>(leb128_78) };
                                  uint8_t id_2261 { 0 };
                                  Void id_2262 { ((void)(p_ref_77[id_2261] = leb128_snd_80), ::dessser::Void()) };
                                  (void)id_2262;
                                  uint8_t id_2263 { 0 };
                                  uint8_t id_2264 { 127 };
                                  uint8_t id_2265 { uint8_t(leb128_fst_79 & id_2264) };
                                  uint32_t id_2266 { uint32_t(id_2265) };
                                  uint8_t id_2267 { 0 };
                                  uint8_t id_2268 { shft_ref_76[id_2267] };
                                  uint32_t id_2269 { uint32_t(id_2266 << id_2268) };
                                  uint8_t id_2270 { 0 };
                                  uint32_t id_2271 { leb_ref_75[id_2270] };
                                  uint32_t id_2272 { uint32_t(id_2269 | id_2271) };
                                  Void id_2273 { ((void)(leb_ref_75[id_2263] = id_2272), ::dessser::Void()) };
                                  (void)id_2273;
                                  uint8_t id_2274 { 0 };
                                  uint8_t id_2275 { 0 };
                                  uint8_t id_2276 { shft_ref_76[id_2275] };
                                  uint8_t id_2277 { 7 };
                                  uint8_t id_2278 { uint8_t(id_2276 + id_2277) };
                                  Void id_2279 { ((void)(shft_ref_76[id_2274] = id_2278), ::dessser::Void()) };
                                  (void)id_2279;
                                  uint8_t id_2280 { 128 };
                                  bool id_2281 { bool(leb128_fst_79 >= id_2280) };
                                  letpair_res_2260 = id_2281;
                                }
                                let_res_2259 = letpair_res_2260;
                              }
                              while_flag_2255 = let_res_2259;
                              if (while_flag_2255) {
                                (void)::dessser::Void();
                              }
                            } while (while_flag_2255);
                            (void)::dessser::Void();
                            uint8_t id_2282 { 0 };
                            uint32_t id_2283 { leb_ref_75[id_2282] };
                            Size id_2284 { Size(id_2283) };
                            uint8_t id_2285 { 0 };
                            Pointer id_2286 { p_ref_77[id_2285] };
                            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2287 { id_2284, id_2286 };
                            let_res_2254 = id_2287;
                          }
                          let_res_2252 = let_res_2254;
                        }
                        let_res_2249 = let_res_2252;
                      }
                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2288;
                      {
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_81 { let_res_2249 };
                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2289;
                        {
                          auto dstring1_fst_82 { std::get<0>(dstring1_81) };
                          auto dstring1_snd_83 { std::get<1>(dstring1_81) };
                          ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2290 { dstring1_snd_83.readBytes(dstring1_fst_82) };
                          ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2291;
                          {
                            auto dstring2_fst_85 { std::get<0>(id_2290) };
                            auto dstring2_snd_86 { std::get<1>(id_2290) };
                            std::string id_2292 { dstring2_fst_85.toString() };
                            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2293 { id_2292, dstring2_snd_86 };
                            letpair_res_2291 = id_2293;
                          }
                          letpair_res_2289 = letpair_res_2291;
                        }
                        let_res_2288 = letpair_res_2289;
                      }
                      ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc let_res_2294;
                      {
                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_87 { let_res_2288 };
                        ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc letpair_res_2295;
                        {
                          auto dtup_fst_88 { std::get<0>(dtup_87) };
                          auto dtup_snd_89 { std::get<1>(dtup_87) };
                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2296 { dtup_snd_89.readU16Le() };
                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2297;
                          {
                            auto du16_fst_91 { std::get<0>(id_2296) };
                            auto du16_snd_92 { std::get<1>(id_2296) };
                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2298 { du16_fst_91, du16_snd_92 };
                            letpair_res_2297 = id_2298;
                          }
                          ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae let_res_2299;
                          {
                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_96 { letpair_res_2297 };
                            ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae letpair_res_2300;
                            {
                              auto dsum1_fst_97 { std::get<0>(dsum1_96) };
                              auto dsum1_snd_98 { std::get<1>(dsum1_96) };
                              uint16_t id_2301 { 0 };
                              bool id_2302 { bool(id_2301 == dsum1_fst_97) };
                              ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2303;
                              if (id_2302) {
                                (void)::dessser::Void();
                                ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2304 { std::in_place_index<0>, ::dessser::Void() };
                                ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2305 { id_2304, dsum1_snd_98 };
                                choose_res_2303 = id_2305;
                              } else {
                                uint16_t id_2306 { 1 };
                                bool id_2307 { bool(id_2306 == dsum1_fst_97) };
                                ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2308;
                                if (id_2307) {
                                  (void)::dessser::Void();
                                  ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2309 { std::in_place_index<1>, ::dessser::Void() };
                                  ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2310 { id_2309, dsum1_snd_98 };
                                  choose_res_2308 = id_2310;
                                } else {
                                  uint16_t id_2311 { 2 };
                                  bool id_2312 { bool(id_2311 == dsum1_fst_97) };
                                  ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2313;
                                  if (id_2312) {
                                    (void)::dessser::Void();
                                    ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2314 { std::in_place_index<2>, ::dessser::Void() };
                                    ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2315 { id_2314, dsum1_snd_98 };
                                    choose_res_2313 = id_2315;
                                  } else {
                                    uint16_t id_2316 { 3 };
                                    bool id_2317 { bool(id_2316 == dsum1_fst_97) };
                                    ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2318;
                                    if (id_2317) {
                                      (void)::dessser::Void();
                                      ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2319 { std::in_place_index<3>, ::dessser::Void() };
                                      ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2320 { id_2319, dsum1_snd_98 };
                                      choose_res_2318 = id_2320;
                                    } else {
                                      uint16_t id_2321 { 4 };
                                      bool id_2322 { bool(id_2321 == dsum1_fst_97) };
                                      ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2323;
                                      if (id_2322) {
                                        (void)::dessser::Void();
                                        ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2324 { std::in_place_index<4>, ::dessser::Void() };
                                        ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2325 { id_2324, dsum1_snd_98 };
                                        choose_res_2323 = id_2325;
                                      } else {
                                        uint16_t id_2326 { 5 };
                                        bool id_2327 { bool(id_2326 == dsum1_fst_97) };
                                        ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2328;
                                        if (id_2327) {
                                          (void)::dessser::Void();
                                          ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2329 { std::in_place_index<5>, ::dessser::Void() };
                                          ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2330 { id_2329, dsum1_snd_98 };
                                          choose_res_2328 = id_2330;
                                        } else {
                                          uint16_t id_2331 { 6 };
                                          bool id_2332 { bool(id_2331 == dsum1_fst_97) };
                                          ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2333;
                                          if (id_2332) {
                                            (void)::dessser::Void();
                                            ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2334 { std::in_place_index<6>, ::dessser::Void() };
                                            ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2335 { id_2334, dsum1_snd_98 };
                                            choose_res_2333 = id_2335;
                                          } else {
                                            uint16_t id_2336 { 7 };
                                            bool id_2337 { bool(dsum1_fst_97 == id_2336) };
                                            Void id_2338 { ((void)(assert(id_2337)), ::dessser::Void()) };
                                            (void)id_2338;
                                            (void)::dessser::Void();
                                            ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2339 { std::in_place_index<7>, ::dessser::Void() };
                                            ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2340 { id_2339, dsum1_snd_98 };
                                            choose_res_2333 = id_2340;
                                          }
                                          choose_res_2328 = choose_res_2333;
                                        }
                                        choose_res_2323 = choose_res_2328;
                                      }
                                      choose_res_2318 = choose_res_2323;
                                    }
                                    choose_res_2313 = choose_res_2318;
                                  }
                                  choose_res_2308 = choose_res_2313;
                                }
                                choose_res_2303 = choose_res_2308;
                              }
                              letpair_res_2300 = choose_res_2303;
                            }
                            let_res_2299 = letpair_res_2300;
                          }
                          ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc letpair_res_2341;
                          {
                            auto dtup_fst_124 { std::get<0>(let_res_2299) };
                            auto dtup_snd_125 { std::get<1>(let_res_2299) };
                            ::dessser::gen::sync_key::ta7e4a6f84fc41fdc68e99605bbb0a0c8 id_2342 { dtup_fst_88, dtup_fst_124 };
                            ::dessser::gen::sync_key::per_worker_data id_2343 { std::in_place_index<6>, id_2342 };
                            ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc id_2344 { id_2343, dtup_snd_125 };
                            letpair_res_2341 = id_2344;
                          }
                          letpair_res_2295 = letpair_res_2341;
                        }
                        let_res_2294 = letpair_res_2295;
                      }
                      choose_res_2246 = let_res_2294;
                    } else {
                      uint16_t id_2345 { 7 };
                      bool id_2346 { bool(id_2345 == dsum1_fst_64) };
                      ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc choose_res_2347;
                      if (id_2346) {
                        ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_2348 { dsum1_snd_65.readU32Le() };
                        ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc letpair_res_2349;
                        {
                          auto du32_fst_70 { std::get<0>(id_2348) };
                          auto du32_snd_71 { std::get<1>(id_2348) };
                          ::dessser::gen::sync_key::per_worker_data id_2350 { std::in_place_index<7>, du32_fst_70 };
                          ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc id_2351 { id_2350, du32_snd_71 };
                          letpair_res_2349 = id_2351;
                        }
                        choose_res_2347 = letpair_res_2349;
                      } else {
                        uint16_t id_2352 { 8 };
                        bool id_2353 { bool(dsum1_fst_64 == id_2352) };
                        Void id_2354 { ((void)(assert(id_2353)), ::dessser::Void()) };
                        (void)id_2354;
                        (void)::dessser::Void();
                        ::dessser::gen::sync_key::per_worker_data id_2355 { std::in_place_index<8>, ::dessser::Void() };
                        ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc id_2356 { id_2355, dsum1_snd_65 };
                        choose_res_2347 = id_2356;
                      }
                      choose_res_2246 = choose_res_2347;
                    }
                    choose_res_2241 = choose_res_2246;
                  }
                  choose_res_2236 = choose_res_2241;
                }
                choose_res_2231 = choose_res_2236;
              }
              choose_res_2226 = choose_res_2231;
            }
            choose_res_2221 = choose_res_2226;
          }
          choose_res_2216 = choose_res_2221;
        }
        letpair_res_2213 = choose_res_2216;
      }
      let_res_2212 = letpair_res_2213;
    }
    return let_res_2212;
  }
   };
  return fun2208;
}
std::function<::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc(Pointer &)> per_worker_data_of_row_binary(per_worker_data_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_147" (apply (ext-identifier fq_name of-row-binary) (param 0))
        (let-pair "dtup_fst_148" "dtup_snd_149" (identifier "dtup_147")
          (let-pair "dtup_fst_151" "dtup_snd_152" (apply (identifier "per_worker_data-of-row-binary") (identifier "dtup_snd_149"))
            (make-tup (make-tup (identifier "dtup_fst_148") (identifier "dtup_fst_151")) (identifier "dtup_snd_152"))))))
 */
static std::function<::dessser::gen::sync_key::t1f40308c4d529d3aab5f7f6d77e7f092(Pointer &)> per_worker_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t1f40308c4d529d3aab5f7f6d77e7f092(Pointer &)> fun2357 { [&](Pointer p_0) {
    auto fun2358 { dessser::gen::fq_name::of_row_binary };
    ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 id_2359 { fun2358(p_0) };
    ::dessser::gen::sync_key::t1f40308c4d529d3aab5f7f6d77e7f092 let_res_2360;
    {
      ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 dtup_147 { id_2359 };
      ::dessser::gen::sync_key::t1f40308c4d529d3aab5f7f6d77e7f092 letpair_res_2361;
      {
        auto dtup_fst_148 { std::get<0>(dtup_147) };
        auto dtup_snd_149 { std::get<1>(dtup_147) };
        ::dessser::gen::sync_key::t5c90cea3f3a08b18ff7f2236b4f968fc id_2362 { per_worker_data_of_row_binary(dtup_snd_149) };
        ::dessser::gen::sync_key::t1f40308c4d529d3aab5f7f6d77e7f092 letpair_res_2363;
        {
          auto dtup_fst_151 { std::get<0>(id_2362) };
          auto dtup_snd_152 { std::get<1>(id_2362) };
          ::dessser::gen::sync_key::per_worker id_2364 { dtup_fst_148, dtup_fst_151 };
          ::dessser::gen::sync_key::t1f40308c4d529d3aab5f7f6d77e7f092 id_2365 { id_2364, dtup_snd_152 };
          letpair_res_2363 = id_2365;
        }
        letpair_res_2361 = letpair_res_2363;
      }
      let_res_2360 = letpair_res_2361;
    }
    return let_res_2360;
  }
   };
  return fun2357;
}
std::function<::dessser::gen::sync_key::t1f40308c4d529d3aab5f7f6d77e7f092(Pointer &)> per_worker_of_row_binary(per_worker_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_159" (let-pair "du16_fst_154" "du16_snd_155" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_154") (identifier "du16_snd_155")))
        (let-pair "dsum1_fst_160" "dsum1_snd_161" (identifier "dsum1_159")
          (if (eq (u16 0) (identifier "dsum1_fst_160"))
            (make-tup
              (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 0
                (nop)) (identifier "dsum1_snd_161"))
            (if (eq (u16 1) (identifier "dsum1_fst_160"))
              (let "dtup_210"
                (let "dstring1_204"
                  (let "leb_ref_198" (make-vec (u32 0))
                    (let "shft_ref_199" (make-vec (u8 0))
                      (let "p_ref_200" (make-vec (identifier "dsum1_snd_161"))
                        (seq
                          (while
                            (let "leb128_201" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_200")))
                              (let-pair "leb128_fst_202" "leb128_snd_203" 
                                (identifier "leb128_201")
                                (seq (set-vec (u8 0) (identifier "p_ref_200") (identifier "leb128_snd_203"))
                                  (set-vec (u8 0) (identifier "leb_ref_198")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_202") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_199"))) (unsafe-nth (u8 0) (identifier "leb_ref_198"))))
                                  (set-vec (u8 0) (identifier "shft_ref_199") (add (unsafe-nth (u8 0) (identifier "shft_ref_199")) (u8 7))) 
                                  (ge (identifier "leb128_fst_202") (u8 128))))) 
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_198"))) (unsafe-nth (u8 0) (identifier "p_ref_200")))))))
                  (let-pair "dstring1_fst_205" "dstring1_snd_206" (identifier "dstring1_204")
                    (let-pair "dstring2_fst_208" "dstring2_snd_209" (read-bytes (identifier "dstring1_snd_206") (identifier "dstring1_fst_205"))
                      (make-tup (string-of-bytes (identifier "dstring2_fst_208")) (identifier "dstring2_snd_209")))))
                (let-pair "dtup_fst_211" "dtup_snd_212" (identifier "dtup_210")
                  (let-pair "dtup_fst_229" "dtup_snd_230"
                    (let "dsum1_219" (let-pair "du16_fst_214" "du16_snd_215" (read-u16 little-endian (identifier "dtup_snd_212")) (make-tup (identifier "du16_fst_214") (identifier "du16_snd_215")))
                      (let-pair "dsum1_fst_220" "dsum1_snd_221" (identifier "dsum1_219")
                        (if (eq (u16 0) (identifier "dsum1_fst_220")) 
                          (make-tup (construct "[Host Void | Port Void]" 0 (nop)) (identifier "dsum1_snd_221"))
                          (seq (assert (eq (identifier "dsum1_fst_220") (u16 1))) (make-tup (construct "[Host Void | Port Void]" 1 (nop)) (identifier "dsum1_snd_221"))))))
                    (make-tup
                      (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 1
                        (make-tup (identifier "dtup_fst_211") (identifier "dtup_fst_229"))) 
                      (identifier "dtup_snd_230")))))
              (if (eq (u16 2) (identifier "dsum1_fst_160"))
                (let-pair "dsum2_fst_196" "dsum2_snd_197" (apply (identifier "per_worker-of-row-binary") (identifier "dsum1_snd_161"))
                  (make-tup
                    (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 2
                      (identifier "dsum2_fst_196")) (identifier "dsum2_snd_197")))
                (seq (assert (eq (identifier "dsum1_fst_160") (u16 3)))
                  (let "dtup_174"
                    (let "dstring1_168"
                      (let "leb_ref_162" (make-vec (u32 0))
                        (let "shft_ref_163" (make-vec (u8 0))
                          (let "p_ref_164" (make-vec (identifier "dsum1_snd_161"))
                            (seq
                              (while
                                (let "leb128_165" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_164")))
                                  (let-pair "leb128_fst_166" "leb128_snd_167" 
                                    (identifier "leb128_165")
                                    (seq (set-vec (u8 0) (identifier "p_ref_164") (identifier "leb128_snd_167"))
                                      (set-vec (u8 0) (identifier "leb_ref_162")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_166") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_163"))) (unsafe-nth (u8 0) (identifier "leb_ref_162"))))
                                      (set-vec (u8 0) (identifier "shft_ref_163") (add (unsafe-nth (u8 0) (identifier "shft_ref_163")) (u8 7))) 
                                      (ge (identifier "leb128_fst_166") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_162"))) (unsafe-nth (u8 0) (identifier "p_ref_164")))))))
                      (let-pair "dstring1_fst_169" "dstring1_snd_170" 
                        (identifier "dstring1_168")
                        (let-pair "dstring2_fst_172" "dstring2_snd_173" 
                          (read-bytes (identifier "dstring1_snd_170") (identifier "dstring1_fst_169")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_172")) (identifier "dstring2_snd_173")))))
                    (let-pair "dtup_fst_175" "dtup_snd_176" (identifier "dtup_174")
                      (let "dsum1_183" (let-pair "du16_fst_178" "du16_snd_179" (read-u16 little-endian (identifier "dtup_snd_176")) (make-tup (identifier "du16_fst_178") (identifier "du16_snd_179")))
                        (let-pair "dsum1_fst_184" "dsum1_snd_185" (identifier "dsum1_183")
                          (seq (assert (eq (identifier "dsum1_fst_184") (u16 0)))
                            (make-tup
                              (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 3
                                (make-tup (identifier "dtup_fst_175") (construct "[Executable Void]" 0 (nop)))) 
                              (identifier "dsum1_snd_185"))))))))))))))
 */
static std::function<::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530(Pointer &)> per_site_data_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530(Pointer &)> fun2366 { [&](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2367 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2368;
    {
      auto du16_fst_154 { std::get<0>(id_2367) };
      auto du16_snd_155 { std::get<1>(id_2367) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2369 { du16_fst_154, du16_snd_155 };
      letpair_res_2368 = id_2369;
    }
    ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 let_res_2370;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_159 { letpair_res_2368 };
      ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 letpair_res_2371;
      {
        auto dsum1_fst_160 { std::get<0>(dsum1_159) };
        auto dsum1_snd_161 { std::get<1>(dsum1_159) };
        uint16_t id_2372 { 0 };
        bool id_2373 { bool(id_2372 == dsum1_fst_160) };
        ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 choose_res_2374;
        if (id_2373) {
          (void)::dessser::Void();
          ::dessser::gen::sync_key::per_site_data id_2375 { std::in_place_index<0>, ::dessser::Void() };
          ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 id_2376 { id_2375, dsum1_snd_161 };
          choose_res_2374 = id_2376;
        } else {
          uint16_t id_2377 { 1 };
          bool id_2378 { bool(id_2377 == dsum1_fst_160) };
          ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 choose_res_2379;
          if (id_2378) {
            uint32_t id_2380 { 0U };
            Vec<1, uint32_t> id_2381 {  id_2380  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2382;
            {
              Vec<1, uint32_t> leb_ref_198 { id_2381 };
              uint8_t id_2383 { 0 };
              Vec<1, uint8_t> id_2384 {  id_2383  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2385;
              {
                Vec<1, uint8_t> shft_ref_199 { id_2384 };
                Vec<1, Pointer> id_2386 {  dsum1_snd_161  };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2387;
                {
                  Vec<1, Pointer> p_ref_200 { id_2386 };
                  bool while_flag_2388 { true };
                  do {
                    uint8_t id_2389 { 0 };
                    Pointer id_2390 { p_ref_200[id_2389] };
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2391 { id_2390.readU8() };
                    bool let_res_2392;
                    {
                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_201 { id_2391 };
                      bool letpair_res_2393;
                      {
                        auto leb128_fst_202 { std::get<0>(leb128_201) };
                        auto leb128_snd_203 { std::get<1>(leb128_201) };
                        uint8_t id_2394 { 0 };
                        Void id_2395 { ((void)(p_ref_200[id_2394] = leb128_snd_203), ::dessser::Void()) };
                        (void)id_2395;
                        uint8_t id_2396 { 0 };
                        uint8_t id_2397 { 127 };
                        uint8_t id_2398 { uint8_t(leb128_fst_202 & id_2397) };
                        uint32_t id_2399 { uint32_t(id_2398) };
                        uint8_t id_2400 { 0 };
                        uint8_t id_2401 { shft_ref_199[id_2400] };
                        uint32_t id_2402 { uint32_t(id_2399 << id_2401) };
                        uint8_t id_2403 { 0 };
                        uint32_t id_2404 { leb_ref_198[id_2403] };
                        uint32_t id_2405 { uint32_t(id_2402 | id_2404) };
                        Void id_2406 { ((void)(leb_ref_198[id_2396] = id_2405), ::dessser::Void()) };
                        (void)id_2406;
                        uint8_t id_2407 { 0 };
                        uint8_t id_2408 { 0 };
                        uint8_t id_2409 { shft_ref_199[id_2408] };
                        uint8_t id_2410 { 7 };
                        uint8_t id_2411 { uint8_t(id_2409 + id_2410) };
                        Void id_2412 { ((void)(shft_ref_199[id_2407] = id_2411), ::dessser::Void()) };
                        (void)id_2412;
                        uint8_t id_2413 { 128 };
                        bool id_2414 { bool(leb128_fst_202 >= id_2413) };
                        letpair_res_2393 = id_2414;
                      }
                      let_res_2392 = letpair_res_2393;
                    }
                    while_flag_2388 = let_res_2392;
                    if (while_flag_2388) {
                      (void)::dessser::Void();
                    }
                  } while (while_flag_2388);
                  (void)::dessser::Void();
                  uint8_t id_2415 { 0 };
                  uint32_t id_2416 { leb_ref_198[id_2415] };
                  Size id_2417 { Size(id_2416) };
                  uint8_t id_2418 { 0 };
                  Pointer id_2419 { p_ref_200[id_2418] };
                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2420 { id_2417, id_2419 };
                  let_res_2387 = id_2420;
                }
                let_res_2385 = let_res_2387;
              }
              let_res_2382 = let_res_2385;
            }
            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2421;
            {
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_204 { let_res_2382 };
              ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2422;
              {
                auto dstring1_fst_205 { std::get<0>(dstring1_204) };
                auto dstring1_snd_206 { std::get<1>(dstring1_204) };
                ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2423 { dstring1_snd_206.readBytes(dstring1_fst_205) };
                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2424;
                {
                  auto dstring2_fst_208 { std::get<0>(id_2423) };
                  auto dstring2_snd_209 { std::get<1>(id_2423) };
                  std::string id_2425 { dstring2_fst_208.toString() };
                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2426 { id_2425, dstring2_snd_209 };
                  letpair_res_2424 = id_2426;
                }
                letpair_res_2422 = letpair_res_2424;
              }
              let_res_2421 = letpair_res_2422;
            }
            ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 let_res_2427;
            {
              ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_210 { let_res_2421 };
              ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 letpair_res_2428;
              {
                auto dtup_fst_211 { std::get<0>(dtup_210) };
                auto dtup_snd_212 { std::get<1>(dtup_210) };
                ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2429 { dtup_snd_212.readU16Le() };
                ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2430;
                {
                  auto du16_fst_214 { std::get<0>(id_2429) };
                  auto du16_snd_215 { std::get<1>(id_2429) };
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2431 { du16_fst_214, du16_snd_215 };
                  letpair_res_2430 = id_2431;
                }
                ::dessser::gen::sync_key::t8f0858866d1e27d5fa38c6941e6365f2 let_res_2432;
                {
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_219 { letpair_res_2430 };
                  ::dessser::gen::sync_key::t8f0858866d1e27d5fa38c6941e6365f2 letpair_res_2433;
                  {
                    auto dsum1_fst_220 { std::get<0>(dsum1_219) };
                    auto dsum1_snd_221 { std::get<1>(dsum1_219) };
                    uint16_t id_2434 { 0 };
                    bool id_2435 { bool(id_2434 == dsum1_fst_220) };
                    ::dessser::gen::sync_key::t8f0858866d1e27d5fa38c6941e6365f2 choose_res_2436;
                    if (id_2435) {
                      (void)::dessser::Void();
                      ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_2437 { std::in_place_index<0>, ::dessser::Void() };
                      ::dessser::gen::sync_key::t8f0858866d1e27d5fa38c6941e6365f2 id_2438 { id_2437, dsum1_snd_221 };
                      choose_res_2436 = id_2438;
                    } else {
                      uint16_t id_2439 { 1 };
                      bool id_2440 { bool(dsum1_fst_220 == id_2439) };
                      Void id_2441 { ((void)(assert(id_2440)), ::dessser::Void()) };
                      (void)id_2441;
                      (void)::dessser::Void();
                      ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_2442 { std::in_place_index<1>, ::dessser::Void() };
                      ::dessser::gen::sync_key::t8f0858866d1e27d5fa38c6941e6365f2 id_2443 { id_2442, dsum1_snd_221 };
                      choose_res_2436 = id_2443;
                    }
                    letpair_res_2433 = choose_res_2436;
                  }
                  let_res_2432 = letpair_res_2433;
                }
                ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 letpair_res_2444;
                {
                  auto dtup_fst_229 { std::get<0>(let_res_2432) };
                  auto dtup_snd_230 { std::get<1>(let_res_2432) };
                  ::dessser::gen::sync_key::t8b473b477d9037c968f39934f3815b98 id_2445 { dtup_fst_211, dtup_fst_229 };
                  ::dessser::gen::sync_key::per_site_data id_2446 { std::in_place_index<1>, id_2445 };
                  ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 id_2447 { id_2446, dtup_snd_230 };
                  letpair_res_2444 = id_2447;
                }
                letpair_res_2428 = letpair_res_2444;
              }
              let_res_2427 = letpair_res_2428;
            }
            choose_res_2379 = let_res_2427;
          } else {
            uint16_t id_2448 { 2 };
            bool id_2449 { bool(id_2448 == dsum1_fst_160) };
            ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 choose_res_2450;
            if (id_2449) {
              ::dessser::gen::sync_key::t1f40308c4d529d3aab5f7f6d77e7f092 id_2451 { per_worker_of_row_binary(dsum1_snd_161) };
              ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 letpair_res_2452;
              {
                auto dsum2_fst_196 { std::get<0>(id_2451) };
                auto dsum2_snd_197 { std::get<1>(id_2451) };
                ::dessser::gen::sync_key::per_site_data id_2453 { std::in_place_index<2>, dsum2_fst_196 };
                ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 id_2454 { id_2453, dsum2_snd_197 };
                letpair_res_2452 = id_2454;
              }
              choose_res_2450 = letpair_res_2452;
            } else {
              uint16_t id_2455 { 3 };
              bool id_2456 { bool(dsum1_fst_160 == id_2455) };
              Void id_2457 { ((void)(assert(id_2456)), ::dessser::Void()) };
              (void)id_2457;
              uint32_t id_2458 { 0U };
              Vec<1, uint32_t> id_2459 {  id_2458  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2460;
              {
                Vec<1, uint32_t> leb_ref_162 { id_2459 };
                uint8_t id_2461 { 0 };
                Vec<1, uint8_t> id_2462 {  id_2461  };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2463;
                {
                  Vec<1, uint8_t> shft_ref_163 { id_2462 };
                  Vec<1, Pointer> id_2464 {  dsum1_snd_161  };
                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2465;
                  {
                    Vec<1, Pointer> p_ref_164 { id_2464 };
                    bool while_flag_2466 { true };
                    do {
                      uint8_t id_2467 { 0 };
                      Pointer id_2468 { p_ref_164[id_2467] };
                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2469 { id_2468.readU8() };
                      bool let_res_2470;
                      {
                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_165 { id_2469 };
                        bool letpair_res_2471;
                        {
                          auto leb128_fst_166 { std::get<0>(leb128_165) };
                          auto leb128_snd_167 { std::get<1>(leb128_165) };
                          uint8_t id_2472 { 0 };
                          Void id_2473 { ((void)(p_ref_164[id_2472] = leb128_snd_167), ::dessser::Void()) };
                          (void)id_2473;
                          uint8_t id_2474 { 0 };
                          uint8_t id_2475 { 127 };
                          uint8_t id_2476 { uint8_t(leb128_fst_166 & id_2475) };
                          uint32_t id_2477 { uint32_t(id_2476) };
                          uint8_t id_2478 { 0 };
                          uint8_t id_2479 { shft_ref_163[id_2478] };
                          uint32_t id_2480 { uint32_t(id_2477 << id_2479) };
                          uint8_t id_2481 { 0 };
                          uint32_t id_2482 { leb_ref_162[id_2481] };
                          uint32_t id_2483 { uint32_t(id_2480 | id_2482) };
                          Void id_2484 { ((void)(leb_ref_162[id_2474] = id_2483), ::dessser::Void()) };
                          (void)id_2484;
                          uint8_t id_2485 { 0 };
                          uint8_t id_2486 { 0 };
                          uint8_t id_2487 { shft_ref_163[id_2486] };
                          uint8_t id_2488 { 7 };
                          uint8_t id_2489 { uint8_t(id_2487 + id_2488) };
                          Void id_2490 { ((void)(shft_ref_163[id_2485] = id_2489), ::dessser::Void()) };
                          (void)id_2490;
                          uint8_t id_2491 { 128 };
                          bool id_2492 { bool(leb128_fst_166 >= id_2491) };
                          letpair_res_2471 = id_2492;
                        }
                        let_res_2470 = letpair_res_2471;
                      }
                      while_flag_2466 = let_res_2470;
                      if (while_flag_2466) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_2466);
                    (void)::dessser::Void();
                    uint8_t id_2493 { 0 };
                    uint32_t id_2494 { leb_ref_162[id_2493] };
                    Size id_2495 { Size(id_2494) };
                    uint8_t id_2496 { 0 };
                    Pointer id_2497 { p_ref_164[id_2496] };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2498 { id_2495, id_2497 };
                    let_res_2465 = id_2498;
                  }
                  let_res_2463 = let_res_2465;
                }
                let_res_2460 = let_res_2463;
              }
              ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2499;
              {
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_168 { let_res_2460 };
                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2500;
                {
                  auto dstring1_fst_169 { std::get<0>(dstring1_168) };
                  auto dstring1_snd_170 { std::get<1>(dstring1_168) };
                  ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2501 { dstring1_snd_170.readBytes(dstring1_fst_169) };
                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2502;
                  {
                    auto dstring2_fst_172 { std::get<0>(id_2501) };
                    auto dstring2_snd_173 { std::get<1>(id_2501) };
                    std::string id_2503 { dstring2_fst_172.toString() };
                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2504 { id_2503, dstring2_snd_173 };
                    letpair_res_2502 = id_2504;
                  }
                  letpair_res_2500 = letpair_res_2502;
                }
                let_res_2499 = letpair_res_2500;
              }
              ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 let_res_2505;
              {
                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_174 { let_res_2499 };
                ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 letpair_res_2506;
                {
                  auto dtup_fst_175 { std::get<0>(dtup_174) };
                  auto dtup_snd_176 { std::get<1>(dtup_174) };
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2507 { dtup_snd_176.readU16Le() };
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2508;
                  {
                    auto du16_fst_178 { std::get<0>(id_2507) };
                    auto du16_snd_179 { std::get<1>(id_2507) };
                    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2509 { du16_fst_178, du16_snd_179 };
                    letpair_res_2508 = id_2509;
                  }
                  ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 let_res_2510;
                  {
                    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_183 { letpair_res_2508 };
                    ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 letpair_res_2511;
                    {
                      auto dsum1_fst_184 { std::get<0>(dsum1_183) };
                      auto dsum1_snd_185 { std::get<1>(dsum1_183) };
                      uint16_t id_2512 { 0 };
                      bool id_2513 { bool(dsum1_fst_184 == id_2512) };
                      Void id_2514 { ((void)(assert(id_2513)), ::dessser::Void()) };
                      (void)id_2514;
                      (void)::dessser::Void();
                      ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51 id_2515 { std::in_place_index<0>, ::dessser::Void() };
                      ::dessser::gen::sync_key::t85827d1984b82a47867ad2208bc45f28 id_2516 { dtup_fst_175, id_2515 };
                      ::dessser::gen::sync_key::per_site_data id_2517 { std::in_place_index<3>, id_2516 };
                      ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 id_2518 { id_2517, dsum1_snd_185 };
                      letpair_res_2511 = id_2518;
                    }
                    let_res_2510 = letpair_res_2511;
                  }
                  letpair_res_2506 = let_res_2510;
                }
                let_res_2505 = letpair_res_2506;
              }
              choose_res_2450 = let_res_2505;
            }
            choose_res_2379 = choose_res_2450;
          }
          choose_res_2374 = choose_res_2379;
        }
        letpair_res_2371 = choose_res_2374;
      }
      let_res_2370 = letpair_res_2371;
    }
    return let_res_2370;
  }
   };
  return fun2366;
}
std::function<::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530(Pointer &)> per_site_data_of_row_binary(per_site_data_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_237" (apply (ext-identifier site_name of-row-binary) (param 0))
        (let-pair "dtup_fst_238" "dtup_snd_239" (identifier "dtup_237")
          (let-pair "dtup_fst_241" "dtup_snd_242" (apply (identifier "per_site_data-of-row-binary") (identifier "dtup_snd_239"))
            (make-tup (make-tup (identifier "dtup_fst_238") (identifier "dtup_fst_241")) (identifier "dtup_snd_242"))))))
 */
static std::function<::dessser::gen::sync_key::t46884d5a883114c46d32db813b52f29d(Pointer &)> per_site_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t46884d5a883114c46d32db813b52f29d(Pointer &)> fun2519 { [&](Pointer p_0) {
    auto fun2520 { dessser::gen::site_name::of_row_binary };
    ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 id_2521 { fun2520(p_0) };
    ::dessser::gen::sync_key::t46884d5a883114c46d32db813b52f29d let_res_2522;
    {
      ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 dtup_237 { id_2521 };
      ::dessser::gen::sync_key::t46884d5a883114c46d32db813b52f29d letpair_res_2523;
      {
        auto dtup_fst_238 { std::get<0>(dtup_237) };
        auto dtup_snd_239 { std::get<1>(dtup_237) };
        ::dessser::gen::sync_key::te4133d682331ecfabfc7bd76e1489530 id_2524 { per_site_data_of_row_binary(dtup_snd_239) };
        ::dessser::gen::sync_key::t46884d5a883114c46d32db813b52f29d letpair_res_2525;
        {
          auto dtup_fst_241 { std::get<0>(id_2524) };
          auto dtup_snd_242 { std::get<1>(id_2524) };
          ::dessser::gen::sync_key::per_site id_2526 { dtup_fst_238, dtup_fst_241 };
          ::dessser::gen::sync_key::t46884d5a883114c46d32db813b52f29d id_2527 { id_2526, dtup_snd_242 };
          letpair_res_2525 = id_2527;
        }
        letpair_res_2523 = letpair_res_2525;
      }
      let_res_2522 = letpair_res_2523;
    }
    return let_res_2522;
  }
   };
  return fun2519;
}
std::function<::dessser::gen::sync_key::t46884d5a883114c46d32db813b52f29d(Pointer &)> per_site_of_row_binary(per_site_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_450" (let-pair "du16_fst_445" "du16_snd_446" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_445") (identifier "du16_snd_446")))
        (let-pair "dsum1_fst_451" "dsum1_snd_452" (identifier "dsum1_450")
          (if (eq (u16 0) (identifier "dsum1_fst_451"))
            (make-tup
              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 0
                (nop)) (identifier "dsum1_snd_452"))
            (if (eq (u16 1) (identifier "dsum1_fst_451"))
              (make-tup
                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 1
                  (nop)) (identifier "dsum1_snd_452"))
              (if (eq (u16 2) (identifier "dsum1_fst_451"))
                (let "dstring1_624"
                  (let "leb_ref_618" (make-vec (u32 0))
                    (let "shft_ref_619" (make-vec (u8 0))
                      (let "p_ref_620" (make-vec (identifier "dsum1_snd_452"))
                        (seq
                          (while
                            (let "leb128_621" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_620")))
                              (let-pair "leb128_fst_622" "leb128_snd_623" 
                                (identifier "leb128_621")
                                (seq (set-vec (u8 0) (identifier "p_ref_620") (identifier "leb128_snd_623"))
                                  (set-vec (u8 0) (identifier "leb_ref_618")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_622") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_619"))) (unsafe-nth (u8 0) (identifier "leb_ref_618"))))
                                  (set-vec (u8 0) (identifier "shft_ref_619") (add (unsafe-nth (u8 0) (identifier "shft_ref_619")) (u8 7))) 
                                  (ge (identifier "leb128_fst_622") (u8 128))))) 
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_618"))) (unsafe-nth (u8 0) (identifier "p_ref_620")))))))
                  (let-pair "dstring1_fst_625" "dstring1_snd_626" (identifier "dstring1_624")
                    (let-pair "dstring2_fst_628" "dstring2_snd_629" (read-bytes (identifier "dstring1_snd_626") (identifier "dstring1_fst_625"))
                      (make-tup
                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 2
                          (string-of-bytes (identifier "dstring2_fst_628"))) 
                        (identifier "dstring2_snd_629")))))
                (if (eq (u16 3) (identifier "dsum1_fst_451"))
                  (let "dtup_597" (apply (ext-identifier src_path of-row-binary) (identifier "dsum1_snd_452"))
                    (let-pair "dtup_fst_598" "dtup_snd_599" (identifier "dtup_597")
                      (let "dstring1_606"
                        (let "leb_ref_600" (make-vec (u32 0))
                          (let "shft_ref_601" (make-vec (u8 0))
                            (let "p_ref_602" (make-vec (identifier "dtup_snd_599"))
                              (seq
                                (while
                                  (let "leb128_603" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_602")))
                                    (let-pair "leb128_fst_604" "leb128_snd_605" 
                                      (identifier "leb128_603")
                                      (seq (set-vec (u8 0) (identifier "p_ref_602") (identifier "leb128_snd_605"))
                                        (set-vec (u8 0) (identifier "leb_ref_600")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_604") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_601"))) (unsafe-nth (u8 0) (identifier "leb_ref_600"))))
                                        (set-vec (u8 0) (identifier "shft_ref_601") (add (unsafe-nth (u8 0) (identifier "shft_ref_601")) (u8 7))) 
                                        (ge (identifier "leb128_fst_604") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_600"))) (unsafe-nth (u8 0) (identifier "p_ref_602")))))))
                        (let-pair "dstring1_fst_607" "dstring1_snd_608" 
                          (identifier "dstring1_606")
                          (let-pair "dstring2_fst_610" "dstring2_snd_611" 
                            (read-bytes (identifier "dstring1_snd_608") (identifier "dstring1_fst_607"))
                            (make-tup
                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 3
                                (make-tup (identifier "dtup_fst_598") (string-of-bytes (identifier "dstring2_fst_610")))) 
                              (identifier "dstring2_snd_611")))))))
                  (if (eq (u16 4) (identifier "dsum1_fst_451"))
                    (make-tup
                      (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 4
                        (nop)) (identifier "dsum1_snd_452"))
                    (if (eq (u16 5) (identifier "dsum1_fst_451"))
                      (let-pair "dsum2_fst_592" "dsum2_snd_593" (apply (identifier "per_site-of-row-binary") (identifier "dsum1_snd_452"))
                        (make-tup
                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 5
                            (identifier "dsum2_fst_592")) (identifier "dsum2_snd_593")))
                      (if (eq (u16 6) (identifier "dsum1_fst_451"))
                        (let-pair "dsum2_fst_589" "dsum2_snd_590"
                          (let "dsum1_564" (let-pair "du16_fst_559" "du16_snd_560" (read-u16 little-endian (identifier "dsum1_snd_452")) (make-tup (identifier "du16_fst_559") (identifier "du16_snd_560")))
                            (let-pair "dsum1_fst_565" "dsum1_snd_566" 
                              (identifier "dsum1_564")
                              (if (eq (u16 0) (identifier "dsum1_fst_565")) 
                                (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 0 (nop)) (identifier "dsum1_snd_566"))
                                (if (eq (u16 1) (identifier "dsum1_fst_565")) 
                                  (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 1 (nop)) (identifier "dsum1_snd_566"))
                                  (seq (assert (eq (identifier "dsum1_fst_565") (u16 2)))
                                    (let "dstring1_573"
                                      (let "leb_ref_567" (make-vec (u32 0))
                                        (let "shft_ref_568" (make-vec (u8 0))
                                          (let "p_ref_569" (make-vec (identifier "dsum1_snd_566"))
                                            (seq
                                              (while
                                                (let "leb128_570" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_569")))
                                                  (let-pair "leb128_fst_571" "leb128_snd_572" 
                                                    (identifier "leb128_570")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_569") (identifier "leb128_snd_572"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_567")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_571") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_568")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_567")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_568") (add (unsafe-nth (u8 0) (identifier "shft_ref_568")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_571") (u8 128))))) 
                                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_567"))) (unsafe-nth (u8 0) (identifier "p_ref_569")))))))
                                      (let-pair "dstring1_fst_574" "dstring1_snd_575" 
                                        (identifier "dstring1_573")
                                        (let-pair "dstring2_fst_577" "dstring2_snd_578" 
                                          (read-bytes (identifier "dstring1_snd_575") (identifier "dstring1_fst_574"))
                                          (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 2 (string-of-bytes (identifier "dstring2_fst_577"))) (identifier "dstring2_snd_578"))))))))))
                          (make-tup
                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 6
                              (identifier "dsum2_fst_589")) (identifier "dsum2_snd_590")))
                        (if (eq (u16 7) (identifier "dsum1_fst_451"))
                          (let "dtup_531" (apply (ext-identifier site_name of-row-binary) (identifier "dsum1_snd_452"))
                            (let-pair "dtup_fst_532" "dtup_snd_533" (identifier "dtup_531")
                              (let "dtup_534" (apply (ext-identifier fq_name of-row-binary) (identifier "dtup_snd_533"))
                                (let-pair "dtup_fst_535" "dtup_snd_536" 
                                  (identifier "dtup_534")
                                  (let "dtup_549"
                                    (let "dstring1_543"
                                      (let "leb_ref_537" (make-vec (u32 0))
                                        (let "shft_ref_538" (make-vec (u8 0))
                                          (let "p_ref_539" (make-vec (identifier "dtup_snd_536"))
                                            (seq
                                              (while
                                                (let "leb128_540" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_539")))
                                                  (let-pair "leb128_fst_541" "leb128_snd_542" 
                                                    (identifier "leb128_540")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_539") (identifier "leb128_snd_542"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_537")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_541") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_538")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_537")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_538") (add (unsafe-nth (u8 0) (identifier "shft_ref_538")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_541") (u8 128))))) 
                                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_537"))) (unsafe-nth (u8 0) (identifier "p_ref_539")))))))
                                      (let-pair "dstring1_fst_544" "dstring1_snd_545" 
                                        (identifier "dstring1_543")
                                        (let-pair "dstring2_fst_547" "dstring2_snd_548" 
                                          (read-bytes (identifier "dstring1_snd_545") (identifier "dstring1_fst_544")) 
                                          (make-tup (string-of-bytes (identifier "dstring2_fst_547")) (identifier "dstring2_snd_548")))))
                                    (let-pair "dtup_fst_550" "dtup_snd_551" 
                                      (identifier "dtup_549")
                                      (let-pair "dtup_fst_553" "dtup_snd_554" 
                                        (apply (identifier "per_tail-of-row-binary") (identifier "dtup_snd_551"))
                                        (make-tup
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 7
                                            (make-tup (identifier "dtup_fst_532") (identifier "dtup_fst_535") (identifier "dtup_fst_550") (identifier "dtup_fst_553"))) 
                                          (identifier "dtup_snd_554")))))))))
                          (if (eq (u16 8) (identifier "dsum1_fst_451"))
                            (let-pair "du16_fst_526" "du16_snd_527" (read-u16 little-endian (identifier "dsum1_snd_452"))
                              (make-tup
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 8
                                  (identifier "du16_fst_526")) (identifier "du16_snd_527")))
                            (if (eq (u16 9) (identifier "dsum1_fst_451"))
                              (let-pair "dsum2_fst_523" "dsum2_snd_524"
                                (if (eq (peek-u8 (identifier "dsum1_snd_452") (size 0)) (u8 1)) 
                                  (make-tup (null "$sync_socket") (ptr-add (identifier "dsum1_snd_452") (size 1)))
                                  (let-pair "make1_1_fst_520" "make1_1_snd_521" 
                                    (apply (ext-identifier sync_socket of-row-binary) (ptr-add (identifier "dsum1_snd_452") (size 1))) 
                                    (make-tup (not-null (identifier "make1_1_fst_520")) (identifier "make1_1_snd_521"))))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 9
                                    (identifier "dsum2_fst_523")) (identifier "dsum2_snd_524")))
                              (if (eq (u16 10) (identifier "dsum1_fst_451"))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 10
                                    (nop)) (identifier "dsum1_snd_452"))
                                (if (eq (u16 11) (identifier "dsum1_fst_451"))
                                  (let "dtup_507" (apply (ext-identifier sync_socket of-row-binary) (identifier "dsum1_snd_452"))
                                    (let-pair "dtup_fst_508" "dtup_snd_509" 
                                      (identifier "dtup_507")
                                      (let-pair "dtup_fst_511" "dtup_snd_512" 
                                        (apply (identifier "per_client-of-row-binary") (identifier "dtup_snd_509"))
                                        (make-tup
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 11
                                            (make-tup (identifier "dtup_fst_508") (identifier "dtup_fst_511"))) 
                                          (identifier "dtup_snd_512")))))
                                  (if (eq (u16 12) (identifier "dsum1_fst_451"))
                                    (let "dtup_498"
                                      (let "dstring1_492"
                                        (let "leb_ref_486" (make-vec (u32 0))
                                          (let "shft_ref_487" (make-vec (u8 0))
                                            (let "p_ref_488" (make-vec (identifier "dsum1_snd_452"))
                                              (seq
                                                (while
                                                  (let "leb128_489" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_488")))
                                                    (let-pair "leb128_fst_490" "leb128_snd_491" 
                                                      (identifier "leb128_489")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_488") (identifier "leb128_snd_491"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_486")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_490") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_487")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_486")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_487") (add (unsafe-nth (u8 0) (identifier "shft_ref_487")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_490") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_486"))) (unsafe-nth (u8 0) (identifier "p_ref_488")))))))
                                        (let-pair "dstring1_fst_493" "dstring1_snd_494" 
                                          (identifier "dstring1_492")
                                          (let-pair "dstring2_fst_496" "dstring2_snd_497" 
                                            (read-bytes (identifier "dstring1_snd_494") (identifier "dstring1_fst_493")) 
                                            (make-tup (string-of-bytes (identifier "dstring2_fst_496")) (identifier "dstring2_snd_497")))))
                                      (let-pair "dtup_fst_499" "dtup_snd_500" 
                                        (identifier "dtup_498")
                                        (let-pair "dtup_fst_502" "dtup_snd_503" 
                                          (apply (identifier "per_dash_key-of-row-binary") (identifier "dtup_snd_500"))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 12
                                              (make-tup (identifier "dtup_fst_499") (identifier "dtup_fst_502"))) 
                                            (identifier "dtup_snd_503")))))
                                    (if (eq (u16 13) (identifier "dsum1_fst_451"))
                                      (make-tup
                                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 13
                                          (nop)) (identifier "dsum1_snd_452"))
                                      (if (eq (u16 14) (identifier "dsum1_fst_451"))
                                        (let "drec_474" (apply (ext-identifier team_name of-row-binary) (identifier "dsum1_snd_452"))
                                          (let-pair "drec_fst_475" "drec_snd_476" 
                                            (identifier "drec_474")
                                            (let-pair "drec_fst_478" "drec_snd_479" 
                                              (apply (identifier "team_key_info-of-row-binary") (identifier "drec_snd_476"))
                                              (make-tup
                                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 14
                                                  (make-rec (string "info") (identifier "drec_fst_478") (string "name") (identifier "drec_fst_475"))) 
                                                (identifier "drec_snd_479")))))
                                        (seq (assert (eq (identifier "dsum1_fst_451") (u16 15)))
                                          (let "dtup_465"
                                            (let "dstring1_459"
                                              (let "leb_ref_453" (make-vec (u32 0))
                                                (let "shft_ref_454" (make-vec (u8 0))
                                                  (let "p_ref_455" (make-vec (identifier "dsum1_snd_452"))
                                                    (seq
                                                      (while
                                                        (let "leb128_456" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_455")))
                                                          (let-pair "leb128_fst_457" "leb128_snd_458" 
                                                            (identifier "leb128_456")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_455") (identifier "leb128_snd_458"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_453")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_457") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_454")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_453")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_454") (add (unsafe-nth (u8 0) (identifier "shft_ref_454")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_457") (u8 128))))) 
                                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_453"))) (unsafe-nth (u8 0) (identifier "p_ref_455")))))))
                                              (let-pair "dstring1_fst_460" "dstring1_snd_461" 
                                                (identifier "dstring1_459")
                                                (let-pair "dstring2_fst_463" "dstring2_snd_464" 
                                                  (read-bytes (identifier "dstring1_snd_461") (identifier "dstring1_fst_460")) 
                                                  (make-tup (string-of-bytes (identifier "dstring2_fst_463")) (identifier "dstring2_snd_464")))))
                                            (let-pair "dtup_fst_466" "dtup_snd_467" 
                                              (identifier "dtup_465")
                                              (let-pair "dtup_fst_469" "dtup_snd_470" 
                                                (apply (identifier "incident_key-of-row-binary") (identifier "dtup_snd_467"))
                                                (make-tup
                                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 15
                                                    (make-tup (identifier "dtup_fst_466") (identifier "dtup_fst_469"))) 
                                                  (identifier "dtup_snd_470"))))))))))))))))))))))))
 */
static std::function<::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a(Pointer &)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a(Pointer &)> fun2528 { [&](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2529 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2530;
    {
      auto du16_fst_445 { std::get<0>(id_2529) };
      auto du16_snd_446 { std::get<1>(id_2529) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2531 { du16_fst_445, du16_snd_446 };
      letpair_res_2530 = id_2531;
    }
    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2532;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_450 { letpair_res_2530 };
      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2533;
      {
        auto dsum1_fst_451 { std::get<0>(dsum1_450) };
        auto dsum1_snd_452 { std::get<1>(dsum1_450) };
        uint16_t id_2534 { 0 };
        bool id_2535 { bool(id_2534 == dsum1_fst_451) };
        ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2536;
        if (id_2535) {
          (void)::dessser::Void();
          ::dessser::gen::sync_key::t id_2537 { std::in_place_index<0>, ::dessser::Void() };
          ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2538 { id_2537, dsum1_snd_452 };
          choose_res_2536 = id_2538;
        } else {
          uint16_t id_2539 { 1 };
          bool id_2540 { bool(id_2539 == dsum1_fst_451) };
          ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2541;
          if (id_2540) {
            (void)::dessser::Void();
            ::dessser::gen::sync_key::t id_2542 { std::in_place_index<1>, ::dessser::Void() };
            ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2543 { id_2542, dsum1_snd_452 };
            choose_res_2541 = id_2543;
          } else {
            uint16_t id_2544 { 2 };
            bool id_2545 { bool(id_2544 == dsum1_fst_451) };
            ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2546;
            if (id_2545) {
              uint32_t id_2547 { 0U };
              Vec<1, uint32_t> id_2548 {  id_2547  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2549;
              {
                Vec<1, uint32_t> leb_ref_618 { id_2548 };
                uint8_t id_2550 { 0 };
                Vec<1, uint8_t> id_2551 {  id_2550  };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2552;
                {
                  Vec<1, uint8_t> shft_ref_619 { id_2551 };
                  Vec<1, Pointer> id_2553 {  dsum1_snd_452  };
                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2554;
                  {
                    Vec<1, Pointer> p_ref_620 { id_2553 };
                    bool while_flag_2555 { true };
                    do {
                      uint8_t id_2556 { 0 };
                      Pointer id_2557 { p_ref_620[id_2556] };
                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2558 { id_2557.readU8() };
                      bool let_res_2559;
                      {
                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_621 { id_2558 };
                        bool letpair_res_2560;
                        {
                          auto leb128_fst_622 { std::get<0>(leb128_621) };
                          auto leb128_snd_623 { std::get<1>(leb128_621) };
                          uint8_t id_2561 { 0 };
                          Void id_2562 { ((void)(p_ref_620[id_2561] = leb128_snd_623), ::dessser::Void()) };
                          (void)id_2562;
                          uint8_t id_2563 { 0 };
                          uint8_t id_2564 { 127 };
                          uint8_t id_2565 { uint8_t(leb128_fst_622 & id_2564) };
                          uint32_t id_2566 { uint32_t(id_2565) };
                          uint8_t id_2567 { 0 };
                          uint8_t id_2568 { shft_ref_619[id_2567] };
                          uint32_t id_2569 { uint32_t(id_2566 << id_2568) };
                          uint8_t id_2570 { 0 };
                          uint32_t id_2571 { leb_ref_618[id_2570] };
                          uint32_t id_2572 { uint32_t(id_2569 | id_2571) };
                          Void id_2573 { ((void)(leb_ref_618[id_2563] = id_2572), ::dessser::Void()) };
                          (void)id_2573;
                          uint8_t id_2574 { 0 };
                          uint8_t id_2575 { 0 };
                          uint8_t id_2576 { shft_ref_619[id_2575] };
                          uint8_t id_2577 { 7 };
                          uint8_t id_2578 { uint8_t(id_2576 + id_2577) };
                          Void id_2579 { ((void)(shft_ref_619[id_2574] = id_2578), ::dessser::Void()) };
                          (void)id_2579;
                          uint8_t id_2580 { 128 };
                          bool id_2581 { bool(leb128_fst_622 >= id_2580) };
                          letpair_res_2560 = id_2581;
                        }
                        let_res_2559 = letpair_res_2560;
                      }
                      while_flag_2555 = let_res_2559;
                      if (while_flag_2555) {
                        (void)::dessser::Void();
                      }
                    } while (while_flag_2555);
                    (void)::dessser::Void();
                    uint8_t id_2582 { 0 };
                    uint32_t id_2583 { leb_ref_618[id_2582] };
                    Size id_2584 { Size(id_2583) };
                    uint8_t id_2585 { 0 };
                    Pointer id_2586 { p_ref_620[id_2585] };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2587 { id_2584, id_2586 };
                    let_res_2554 = id_2587;
                  }
                  let_res_2552 = let_res_2554;
                }
                let_res_2549 = let_res_2552;
              }
              ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2588;
              {
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_624 { let_res_2549 };
                ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2589;
                {
                  auto dstring1_fst_625 { std::get<0>(dstring1_624) };
                  auto dstring1_snd_626 { std::get<1>(dstring1_624) };
                  ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2590 { dstring1_snd_626.readBytes(dstring1_fst_625) };
                  ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2591;
                  {
                    auto dstring2_fst_628 { std::get<0>(id_2590) };
                    auto dstring2_snd_629 { std::get<1>(id_2590) };
                    std::string id_2592 { dstring2_fst_628.toString() };
                    ::dessser::gen::sync_key::t id_2593 { std::in_place_index<2>, id_2592 };
                    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2594 { id_2593, dstring2_snd_629 };
                    letpair_res_2591 = id_2594;
                  }
                  letpair_res_2589 = letpair_res_2591;
                }
                let_res_2588 = letpair_res_2589;
              }
              choose_res_2546 = let_res_2588;
            } else {
              uint16_t id_2595 { 3 };
              bool id_2596 { bool(id_2595 == dsum1_fst_451) };
              ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2597;
              if (id_2596) {
                auto fun2598 { dessser::gen::src_path::of_row_binary };
                ::dessser::gen::sync_key::t6915129216bc7fcac0c82f38ea6cfec8 id_2599 { fun2598(dsum1_snd_452) };
                ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2600;
                {
                  ::dessser::gen::sync_key::t6915129216bc7fcac0c82f38ea6cfec8 dtup_597 { id_2599 };
                  ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2601;
                  {
                    auto dtup_fst_598 { std::get<0>(dtup_597) };
                    auto dtup_snd_599 { std::get<1>(dtup_597) };
                    uint32_t id_2602 { 0U };
                    Vec<1, uint32_t> id_2603 {  id_2602  };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2604;
                    {
                      Vec<1, uint32_t> leb_ref_600 { id_2603 };
                      uint8_t id_2605 { 0 };
                      Vec<1, uint8_t> id_2606 {  id_2605  };
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2607;
                      {
                        Vec<1, uint8_t> shft_ref_601 { id_2606 };
                        Vec<1, Pointer> id_2608 {  dtup_snd_599  };
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2609;
                        {
                          Vec<1, Pointer> p_ref_602 { id_2608 };
                          bool while_flag_2610 { true };
                          do {
                            uint8_t id_2611 { 0 };
                            Pointer id_2612 { p_ref_602[id_2611] };
                            ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2613 { id_2612.readU8() };
                            bool let_res_2614;
                            {
                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_603 { id_2613 };
                              bool letpair_res_2615;
                              {
                                auto leb128_fst_604 { std::get<0>(leb128_603) };
                                auto leb128_snd_605 { std::get<1>(leb128_603) };
                                uint8_t id_2616 { 0 };
                                Void id_2617 { ((void)(p_ref_602[id_2616] = leb128_snd_605), ::dessser::Void()) };
                                (void)id_2617;
                                uint8_t id_2618 { 0 };
                                uint8_t id_2619 { 127 };
                                uint8_t id_2620 { uint8_t(leb128_fst_604 & id_2619) };
                                uint32_t id_2621 { uint32_t(id_2620) };
                                uint8_t id_2622 { 0 };
                                uint8_t id_2623 { shft_ref_601[id_2622] };
                                uint32_t id_2624 { uint32_t(id_2621 << id_2623) };
                                uint8_t id_2625 { 0 };
                                uint32_t id_2626 { leb_ref_600[id_2625] };
                                uint32_t id_2627 { uint32_t(id_2624 | id_2626) };
                                Void id_2628 { ((void)(leb_ref_600[id_2618] = id_2627), ::dessser::Void()) };
                                (void)id_2628;
                                uint8_t id_2629 { 0 };
                                uint8_t id_2630 { 0 };
                                uint8_t id_2631 { shft_ref_601[id_2630] };
                                uint8_t id_2632 { 7 };
                                uint8_t id_2633 { uint8_t(id_2631 + id_2632) };
                                Void id_2634 { ((void)(shft_ref_601[id_2629] = id_2633), ::dessser::Void()) };
                                (void)id_2634;
                                uint8_t id_2635 { 128 };
                                bool id_2636 { bool(leb128_fst_604 >= id_2635) };
                                letpair_res_2615 = id_2636;
                              }
                              let_res_2614 = letpair_res_2615;
                            }
                            while_flag_2610 = let_res_2614;
                            if (while_flag_2610) {
                              (void)::dessser::Void();
                            }
                          } while (while_flag_2610);
                          (void)::dessser::Void();
                          uint8_t id_2637 { 0 };
                          uint32_t id_2638 { leb_ref_600[id_2637] };
                          Size id_2639 { Size(id_2638) };
                          uint8_t id_2640 { 0 };
                          Pointer id_2641 { p_ref_602[id_2640] };
                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2642 { id_2639, id_2641 };
                          let_res_2609 = id_2642;
                        }
                        let_res_2607 = let_res_2609;
                      }
                      let_res_2604 = let_res_2607;
                    }
                    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2643;
                    {
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_606 { let_res_2604 };
                      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2644;
                      {
                        auto dstring1_fst_607 { std::get<0>(dstring1_606) };
                        auto dstring1_snd_608 { std::get<1>(dstring1_606) };
                        ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2645 { dstring1_snd_608.readBytes(dstring1_fst_607) };
                        ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2646;
                        {
                          auto dstring2_fst_610 { std::get<0>(id_2645) };
                          auto dstring2_snd_611 { std::get<1>(id_2645) };
                          std::string id_2647 { dstring2_fst_610.toString() };
                          ::dessser::gen::sync_key::t86252e3890668e56d73574e8b879a5b1 id_2648 { dtup_fst_598, id_2647 };
                          ::dessser::gen::sync_key::t id_2649 { std::in_place_index<3>, id_2648 };
                          ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2650 { id_2649, dstring2_snd_611 };
                          letpair_res_2646 = id_2650;
                        }
                        letpair_res_2644 = letpair_res_2646;
                      }
                      let_res_2643 = letpair_res_2644;
                    }
                    letpair_res_2601 = let_res_2643;
                  }
                  let_res_2600 = letpair_res_2601;
                }
                choose_res_2597 = let_res_2600;
              } else {
                uint16_t id_2651 { 4 };
                bool id_2652 { bool(id_2651 == dsum1_fst_451) };
                ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2653;
                if (id_2652) {
                  (void)::dessser::Void();
                  ::dessser::gen::sync_key::t id_2654 { std::in_place_index<4>, ::dessser::Void() };
                  ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2655 { id_2654, dsum1_snd_452 };
                  choose_res_2653 = id_2655;
                } else {
                  uint16_t id_2656 { 5 };
                  bool id_2657 { bool(id_2656 == dsum1_fst_451) };
                  ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2658;
                  if (id_2657) {
                    ::dessser::gen::sync_key::t46884d5a883114c46d32db813b52f29d id_2659 { per_site_of_row_binary(dsum1_snd_452) };
                    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2660;
                    {
                      auto dsum2_fst_592 { std::get<0>(id_2659) };
                      auto dsum2_snd_593 { std::get<1>(id_2659) };
                      ::dessser::gen::sync_key::t id_2661 { std::in_place_index<5>, dsum2_fst_592 };
                      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2662 { id_2661, dsum2_snd_593 };
                      letpair_res_2660 = id_2662;
                    }
                    choose_res_2658 = letpair_res_2660;
                  } else {
                    uint16_t id_2663 { 6 };
                    bool id_2664 { bool(id_2663 == dsum1_fst_451) };
                    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2665;
                    if (id_2664) {
                      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2666 { dsum1_snd_452.readU16Le() };
                      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2667;
                      {
                        auto du16_fst_559 { std::get<0>(id_2666) };
                        auto du16_snd_560 { std::get<1>(id_2666) };
                        ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2668 { du16_fst_559, du16_snd_560 };
                        letpair_res_2667 = id_2668;
                      }
                      ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 let_res_2669;
                      {
                        ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_564 { letpair_res_2667 };
                        ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 letpair_res_2670;
                        {
                          auto dsum1_fst_565 { std::get<0>(dsum1_564) };
                          auto dsum1_snd_566 { std::get<1>(dsum1_564) };
                          uint16_t id_2671 { 0 };
                          bool id_2672 { bool(id_2671 == dsum1_fst_565) };
                          ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 choose_res_2673;
                          if (id_2672) {
                            (void)::dessser::Void();
                            ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_2674 { std::in_place_index<0>, ::dessser::Void() };
                            ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 id_2675 { id_2674, dsum1_snd_566 };
                            choose_res_2673 = id_2675;
                          } else {
                            uint16_t id_2676 { 1 };
                            bool id_2677 { bool(id_2676 == dsum1_fst_565) };
                            ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 choose_res_2678;
                            if (id_2677) {
                              (void)::dessser::Void();
                              ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_2679 { std::in_place_index<1>, ::dessser::Void() };
                              ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 id_2680 { id_2679, dsum1_snd_566 };
                              choose_res_2678 = id_2680;
                            } else {
                              uint16_t id_2681 { 2 };
                              bool id_2682 { bool(dsum1_fst_565 == id_2681) };
                              Void id_2683 { ((void)(assert(id_2682)), ::dessser::Void()) };
                              (void)id_2683;
                              uint32_t id_2684 { 0U };
                              Vec<1, uint32_t> id_2685 {  id_2684  };
                              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2686;
                              {
                                Vec<1, uint32_t> leb_ref_567 { id_2685 };
                                uint8_t id_2687 { 0 };
                                Vec<1, uint8_t> id_2688 {  id_2687  };
                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2689;
                                {
                                  Vec<1, uint8_t> shft_ref_568 { id_2688 };
                                  Vec<1, Pointer> id_2690 {  dsum1_snd_566  };
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2691;
                                  {
                                    Vec<1, Pointer> p_ref_569 { id_2690 };
                                    bool while_flag_2692 { true };
                                    do {
                                      uint8_t id_2693 { 0 };
                                      Pointer id_2694 { p_ref_569[id_2693] };
                                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2695 { id_2694.readU8() };
                                      bool let_res_2696;
                                      {
                                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_570 { id_2695 };
                                        bool letpair_res_2697;
                                        {
                                          auto leb128_fst_571 { std::get<0>(leb128_570) };
                                          auto leb128_snd_572 { std::get<1>(leb128_570) };
                                          uint8_t id_2698 { 0 };
                                          Void id_2699 { ((void)(p_ref_569[id_2698] = leb128_snd_572), ::dessser::Void()) };
                                          (void)id_2699;
                                          uint8_t id_2700 { 0 };
                                          uint8_t id_2701 { 127 };
                                          uint8_t id_2702 { uint8_t(leb128_fst_571 & id_2701) };
                                          uint32_t id_2703 { uint32_t(id_2702) };
                                          uint8_t id_2704 { 0 };
                                          uint8_t id_2705 { shft_ref_568[id_2704] };
                                          uint32_t id_2706 { uint32_t(id_2703 << id_2705) };
                                          uint8_t id_2707 { 0 };
                                          uint32_t id_2708 { leb_ref_567[id_2707] };
                                          uint32_t id_2709 { uint32_t(id_2706 | id_2708) };
                                          Void id_2710 { ((void)(leb_ref_567[id_2700] = id_2709), ::dessser::Void()) };
                                          (void)id_2710;
                                          uint8_t id_2711 { 0 };
                                          uint8_t id_2712 { 0 };
                                          uint8_t id_2713 { shft_ref_568[id_2712] };
                                          uint8_t id_2714 { 7 };
                                          uint8_t id_2715 { uint8_t(id_2713 + id_2714) };
                                          Void id_2716 { ((void)(shft_ref_568[id_2711] = id_2715), ::dessser::Void()) };
                                          (void)id_2716;
                                          uint8_t id_2717 { 128 };
                                          bool id_2718 { bool(leb128_fst_571 >= id_2717) };
                                          letpair_res_2697 = id_2718;
                                        }
                                        let_res_2696 = letpair_res_2697;
                                      }
                                      while_flag_2692 = let_res_2696;
                                      if (while_flag_2692) {
                                        (void)::dessser::Void();
                                      }
                                    } while (while_flag_2692);
                                    (void)::dessser::Void();
                                    uint8_t id_2719 { 0 };
                                    uint32_t id_2720 { leb_ref_567[id_2719] };
                                    Size id_2721 { Size(id_2720) };
                                    uint8_t id_2722 { 0 };
                                    Pointer id_2723 { p_ref_569[id_2722] };
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2724 { id_2721, id_2723 };
                                    let_res_2691 = id_2724;
                                  }
                                  let_res_2689 = let_res_2691;
                                }
                                let_res_2686 = let_res_2689;
                              }
                              ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 let_res_2725;
                              {
                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_573 { let_res_2686 };
                                ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 letpair_res_2726;
                                {
                                  auto dstring1_fst_574 { std::get<0>(dstring1_573) };
                                  auto dstring1_snd_575 { std::get<1>(dstring1_573) };
                                  ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2727 { dstring1_snd_575.readBytes(dstring1_fst_574) };
                                  ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 letpair_res_2728;
                                  {
                                    auto dstring2_fst_577 { std::get<0>(id_2727) };
                                    auto dstring2_snd_578 { std::get<1>(id_2727) };
                                    std::string id_2729 { dstring2_fst_577.toString() };
                                    ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_2730 { std::in_place_index<2>, id_2729 };
                                    ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 id_2731 { id_2730, dstring2_snd_578 };
                                    letpair_res_2728 = id_2731;
                                  }
                                  letpair_res_2726 = letpair_res_2728;
                                }
                                let_res_2725 = letpair_res_2726;
                              }
                              choose_res_2678 = let_res_2725;
                            }
                            choose_res_2673 = choose_res_2678;
                          }
                          letpair_res_2670 = choose_res_2673;
                        }
                        let_res_2669 = letpair_res_2670;
                      }
                      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2732;
                      {
                        auto dsum2_fst_589 { std::get<0>(let_res_2669) };
                        auto dsum2_snd_590 { std::get<1>(let_res_2669) };
                        ::dessser::gen::sync_key::t id_2733 { std::in_place_index<6>, dsum2_fst_589 };
                        ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2734 { id_2733, dsum2_snd_590 };
                        letpair_res_2732 = id_2734;
                      }
                      choose_res_2665 = letpair_res_2732;
                    } else {
                      uint16_t id_2735 { 7 };
                      bool id_2736 { bool(id_2735 == dsum1_fst_451) };
                      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2737;
                      if (id_2736) {
                        auto fun2738 { dessser::gen::site_name::of_row_binary };
                        ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 id_2739 { fun2738(dsum1_snd_452) };
                        ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2740;
                        {
                          ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 dtup_531 { id_2739 };
                          ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2741;
                          {
                            auto dtup_fst_532 { std::get<0>(dtup_531) };
                            auto dtup_snd_533 { std::get<1>(dtup_531) };
                            auto fun2742 { dessser::gen::fq_name::of_row_binary };
                            ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 id_2743 { fun2742(dtup_snd_533) };
                            ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2744;
                            {
                              ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 dtup_534 { id_2743 };
                              ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2745;
                              {
                                auto dtup_fst_535 { std::get<0>(dtup_534) };
                                auto dtup_snd_536 { std::get<1>(dtup_534) };
                                uint32_t id_2746 { 0U };
                                Vec<1, uint32_t> id_2747 {  id_2746  };
                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2748;
                                {
                                  Vec<1, uint32_t> leb_ref_537 { id_2747 };
                                  uint8_t id_2749 { 0 };
                                  Vec<1, uint8_t> id_2750 {  id_2749  };
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2751;
                                  {
                                    Vec<1, uint8_t> shft_ref_538 { id_2750 };
                                    Vec<1, Pointer> id_2752 {  dtup_snd_536  };
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2753;
                                    {
                                      Vec<1, Pointer> p_ref_539 { id_2752 };
                                      bool while_flag_2754 { true };
                                      do {
                                        uint8_t id_2755 { 0 };
                                        Pointer id_2756 { p_ref_539[id_2755] };
                                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2757 { id_2756.readU8() };
                                        bool let_res_2758;
                                        {
                                          ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_540 { id_2757 };
                                          bool letpair_res_2759;
                                          {
                                            auto leb128_fst_541 { std::get<0>(leb128_540) };
                                            auto leb128_snd_542 { std::get<1>(leb128_540) };
                                            uint8_t id_2760 { 0 };
                                            Void id_2761 { ((void)(p_ref_539[id_2760] = leb128_snd_542), ::dessser::Void()) };
                                            (void)id_2761;
                                            uint8_t id_2762 { 0 };
                                            uint8_t id_2763 { 127 };
                                            uint8_t id_2764 { uint8_t(leb128_fst_541 & id_2763) };
                                            uint32_t id_2765 { uint32_t(id_2764) };
                                            uint8_t id_2766 { 0 };
                                            uint8_t id_2767 { shft_ref_538[id_2766] };
                                            uint32_t id_2768 { uint32_t(id_2765 << id_2767) };
                                            uint8_t id_2769 { 0 };
                                            uint32_t id_2770 { leb_ref_537[id_2769] };
                                            uint32_t id_2771 { uint32_t(id_2768 | id_2770) };
                                            Void id_2772 { ((void)(leb_ref_537[id_2762] = id_2771), ::dessser::Void()) };
                                            (void)id_2772;
                                            uint8_t id_2773 { 0 };
                                            uint8_t id_2774 { 0 };
                                            uint8_t id_2775 { shft_ref_538[id_2774] };
                                            uint8_t id_2776 { 7 };
                                            uint8_t id_2777 { uint8_t(id_2775 + id_2776) };
                                            Void id_2778 { ((void)(shft_ref_538[id_2773] = id_2777), ::dessser::Void()) };
                                            (void)id_2778;
                                            uint8_t id_2779 { 128 };
                                            bool id_2780 { bool(leb128_fst_541 >= id_2779) };
                                            letpair_res_2759 = id_2780;
                                          }
                                          let_res_2758 = letpair_res_2759;
                                        }
                                        while_flag_2754 = let_res_2758;
                                        if (while_flag_2754) {
                                          (void)::dessser::Void();
                                        }
                                      } while (while_flag_2754);
                                      (void)::dessser::Void();
                                      uint8_t id_2781 { 0 };
                                      uint32_t id_2782 { leb_ref_537[id_2781] };
                                      Size id_2783 { Size(id_2782) };
                                      uint8_t id_2784 { 0 };
                                      Pointer id_2785 { p_ref_539[id_2784] };
                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2786 { id_2783, id_2785 };
                                      let_res_2753 = id_2786;
                                    }
                                    let_res_2751 = let_res_2753;
                                  }
                                  let_res_2748 = let_res_2751;
                                }
                                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2787;
                                {
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_543 { let_res_2748 };
                                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2788;
                                  {
                                    auto dstring1_fst_544 { std::get<0>(dstring1_543) };
                                    auto dstring1_snd_545 { std::get<1>(dstring1_543) };
                                    ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2789 { dstring1_snd_545.readBytes(dstring1_fst_544) };
                                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2790;
                                    {
                                      auto dstring2_fst_547 { std::get<0>(id_2789) };
                                      auto dstring2_snd_548 { std::get<1>(id_2789) };
                                      std::string id_2791 { dstring2_fst_547.toString() };
                                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2792 { id_2791, dstring2_snd_548 };
                                      letpair_res_2790 = id_2792;
                                    }
                                    letpair_res_2788 = letpair_res_2790;
                                  }
                                  let_res_2787 = letpair_res_2788;
                                }
                                ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2793;
                                {
                                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_549 { let_res_2787 };
                                  ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2794;
                                  {
                                    auto dtup_fst_550 { std::get<0>(dtup_549) };
                                    auto dtup_snd_551 { std::get<1>(dtup_549) };
                                    ::dessser::gen::sync_key::t1427b384ffff2d22da761632559548f9 id_2795 { per_tail_of_row_binary(dtup_snd_551) };
                                    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2796;
                                    {
                                      auto dtup_fst_553 { std::get<0>(id_2795) };
                                      auto dtup_snd_554 { std::get<1>(id_2795) };
                                      ::dessser::gen::sync_key::t97f8631e87fc5cd910c2a601533983ee id_2797 { dtup_fst_532, dtup_fst_535, dtup_fst_550, dtup_fst_553 };
                                      ::dessser::gen::sync_key::t id_2798 { std::in_place_index<7>, id_2797 };
                                      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2799 { id_2798, dtup_snd_554 };
                                      letpair_res_2796 = id_2799;
                                    }
                                    letpair_res_2794 = letpair_res_2796;
                                  }
                                  let_res_2793 = letpair_res_2794;
                                }
                                letpair_res_2745 = let_res_2793;
                              }
                              let_res_2744 = letpair_res_2745;
                            }
                            letpair_res_2741 = let_res_2744;
                          }
                          let_res_2740 = letpair_res_2741;
                        }
                        choose_res_2737 = let_res_2740;
                      } else {
                        uint16_t id_2800 { 8 };
                        bool id_2801 { bool(id_2800 == dsum1_fst_451) };
                        ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2802;
                        if (id_2801) {
                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2803 { dsum1_snd_452.readU16Le() };
                          ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2804;
                          {
                            auto du16_fst_526 { std::get<0>(id_2803) };
                            auto du16_snd_527 { std::get<1>(id_2803) };
                            ::dessser::gen::sync_key::t id_2805 { std::in_place_index<8>, du16_fst_526 };
                            ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2806 { id_2805, du16_snd_527 };
                            letpair_res_2804 = id_2806;
                          }
                          choose_res_2802 = letpair_res_2804;
                        } else {
                          uint16_t id_2807 { 9 };
                          bool id_2808 { bool(id_2807 == dsum1_fst_451) };
                          ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2809;
                          if (id_2808) {
                            Size id_2810 { 0UL };
                            uint8_t id_2811 { dsum1_snd_452.peekU8(id_2810) };
                            uint8_t id_2812 { 1 };
                            bool id_2813 { bool(id_2811 == id_2812) };
                            ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 choose_res_2814;
                            if (id_2813) {
                              std::optional<dessser::gen::sync_socket::t_ext> id_2815 { std::nullopt };
                              Size id_2816 { 1UL };
                              Pointer id_2817 { dsum1_snd_452.skip(id_2816) };
                              ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 id_2818 { id_2815, id_2817 };
                              choose_res_2814 = id_2818;
                            } else {
                              auto fun2819 { dessser::gen::sync_socket::of_row_binary };
                              Size id_2820 { 1UL };
                              Pointer id_2821 { dsum1_snd_452.skip(id_2820) };
                              ::dessser::gen::sync_key::tc3c0b466d06f5b0f1ffeebd3dab58a35 id_2822 { fun2819(id_2821) };
                              ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 letpair_res_2823;
                              {
                                auto make1_1_fst_520 { std::get<0>(id_2822) };
                                auto make1_1_snd_521 { std::get<1>(id_2822) };
                                std::optional<dessser::gen::sync_socket::t_ext> id_2824 { make1_1_fst_520 };
                                ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 id_2825 { id_2824, make1_1_snd_521 };
                                letpair_res_2823 = id_2825;
                              }
                              choose_res_2814 = letpair_res_2823;
                            }
                            ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2826;
                            {
                              auto dsum2_fst_523 { std::get<0>(choose_res_2814) };
                              auto dsum2_snd_524 { std::get<1>(choose_res_2814) };
                              ::dessser::gen::sync_key::t id_2827 { std::in_place_index<9>, dsum2_fst_523 };
                              ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2828 { id_2827, dsum2_snd_524 };
                              letpair_res_2826 = id_2828;
                            }
                            choose_res_2809 = letpair_res_2826;
                          } else {
                            uint16_t id_2829 { 10 };
                            bool id_2830 { bool(id_2829 == dsum1_fst_451) };
                            ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2831;
                            if (id_2830) {
                              (void)::dessser::Void();
                              ::dessser::gen::sync_key::t id_2832 { std::in_place_index<10>, ::dessser::Void() };
                              ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2833 { id_2832, dsum1_snd_452 };
                              choose_res_2831 = id_2833;
                            } else {
                              uint16_t id_2834 { 11 };
                              bool id_2835 { bool(id_2834 == dsum1_fst_451) };
                              ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2836;
                              if (id_2835) {
                                auto fun2837 { dessser::gen::sync_socket::of_row_binary };
                                ::dessser::gen::sync_key::tc3c0b466d06f5b0f1ffeebd3dab58a35 id_2838 { fun2837(dsum1_snd_452) };
                                ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2839;
                                {
                                  ::dessser::gen::sync_key::tc3c0b466d06f5b0f1ffeebd3dab58a35 dtup_507 { id_2838 };
                                  ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2840;
                                  {
                                    auto dtup_fst_508 { std::get<0>(dtup_507) };
                                    auto dtup_snd_509 { std::get<1>(dtup_507) };
                                    ::dessser::gen::sync_key::t33cdb4c52644761a7d0096ff5546d783 id_2841 { per_client_of_row_binary(dtup_snd_509) };
                                    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2842;
                                    {
                                      auto dtup_fst_511 { std::get<0>(id_2841) };
                                      auto dtup_snd_512 { std::get<1>(id_2841) };
                                      ::dessser::gen::sync_key::t32db4748152e7073f1f93bdcc3c5bff5 id_2843 { dtup_fst_508, dtup_fst_511 };
                                      ::dessser::gen::sync_key::t id_2844 { std::in_place_index<11>, id_2843 };
                                      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2845 { id_2844, dtup_snd_512 };
                                      letpair_res_2842 = id_2845;
                                    }
                                    letpair_res_2840 = letpair_res_2842;
                                  }
                                  let_res_2839 = letpair_res_2840;
                                }
                                choose_res_2836 = let_res_2839;
                              } else {
                                uint16_t id_2846 { 12 };
                                bool id_2847 { bool(id_2846 == dsum1_fst_451) };
                                ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2848;
                                if (id_2847) {
                                  uint32_t id_2849 { 0U };
                                  Vec<1, uint32_t> id_2850 {  id_2849  };
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2851;
                                  {
                                    Vec<1, uint32_t> leb_ref_486 { id_2850 };
                                    uint8_t id_2852 { 0 };
                                    Vec<1, uint8_t> id_2853 {  id_2852  };
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2854;
                                    {
                                      Vec<1, uint8_t> shft_ref_487 { id_2853 };
                                      Vec<1, Pointer> id_2855 {  dsum1_snd_452  };
                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2856;
                                      {
                                        Vec<1, Pointer> p_ref_488 { id_2855 };
                                        bool while_flag_2857 { true };
                                        do {
                                          uint8_t id_2858 { 0 };
                                          Pointer id_2859 { p_ref_488[id_2858] };
                                          ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2860 { id_2859.readU8() };
                                          bool let_res_2861;
                                          {
                                            ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_489 { id_2860 };
                                            bool letpair_res_2862;
                                            {
                                              auto leb128_fst_490 { std::get<0>(leb128_489) };
                                              auto leb128_snd_491 { std::get<1>(leb128_489) };
                                              uint8_t id_2863 { 0 };
                                              Void id_2864 { ((void)(p_ref_488[id_2863] = leb128_snd_491), ::dessser::Void()) };
                                              (void)id_2864;
                                              uint8_t id_2865 { 0 };
                                              uint8_t id_2866 { 127 };
                                              uint8_t id_2867 { uint8_t(leb128_fst_490 & id_2866) };
                                              uint32_t id_2868 { uint32_t(id_2867) };
                                              uint8_t id_2869 { 0 };
                                              uint8_t id_2870 { shft_ref_487[id_2869] };
                                              uint32_t id_2871 { uint32_t(id_2868 << id_2870) };
                                              uint8_t id_2872 { 0 };
                                              uint32_t id_2873 { leb_ref_486[id_2872] };
                                              uint32_t id_2874 { uint32_t(id_2871 | id_2873) };
                                              Void id_2875 { ((void)(leb_ref_486[id_2865] = id_2874), ::dessser::Void()) };
                                              (void)id_2875;
                                              uint8_t id_2876 { 0 };
                                              uint8_t id_2877 { 0 };
                                              uint8_t id_2878 { shft_ref_487[id_2877] };
                                              uint8_t id_2879 { 7 };
                                              uint8_t id_2880 { uint8_t(id_2878 + id_2879) };
                                              Void id_2881 { ((void)(shft_ref_487[id_2876] = id_2880), ::dessser::Void()) };
                                              (void)id_2881;
                                              uint8_t id_2882 { 128 };
                                              bool id_2883 { bool(leb128_fst_490 >= id_2882) };
                                              letpair_res_2862 = id_2883;
                                            }
                                            let_res_2861 = letpair_res_2862;
                                          }
                                          while_flag_2857 = let_res_2861;
                                          if (while_flag_2857) {
                                            (void)::dessser::Void();
                                          }
                                        } while (while_flag_2857);
                                        (void)::dessser::Void();
                                        uint8_t id_2884 { 0 };
                                        uint32_t id_2885 { leb_ref_486[id_2884] };
                                        Size id_2886 { Size(id_2885) };
                                        uint8_t id_2887 { 0 };
                                        Pointer id_2888 { p_ref_488[id_2887] };
                                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2889 { id_2886, id_2888 };
                                        let_res_2856 = id_2889;
                                      }
                                      let_res_2854 = let_res_2856;
                                    }
                                    let_res_2851 = let_res_2854;
                                  }
                                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2890;
                                  {
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_492 { let_res_2851 };
                                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2891;
                                    {
                                      auto dstring1_fst_493 { std::get<0>(dstring1_492) };
                                      auto dstring1_snd_494 { std::get<1>(dstring1_492) };
                                      ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2892 { dstring1_snd_494.readBytes(dstring1_fst_493) };
                                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2893;
                                      {
                                        auto dstring2_fst_496 { std::get<0>(id_2892) };
                                        auto dstring2_snd_497 { std::get<1>(id_2892) };
                                        std::string id_2894 { dstring2_fst_496.toString() };
                                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2895 { id_2894, dstring2_snd_497 };
                                        letpair_res_2893 = id_2895;
                                      }
                                      letpair_res_2891 = letpair_res_2893;
                                    }
                                    let_res_2890 = letpair_res_2891;
                                  }
                                  ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2896;
                                  {
                                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_498 { let_res_2890 };
                                    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2897;
                                    {
                                      auto dtup_fst_499 { std::get<0>(dtup_498) };
                                      auto dtup_snd_500 { std::get<1>(dtup_498) };
                                      ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 id_2898 { per_dash_key_of_row_binary(dtup_snd_500) };
                                      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2899;
                                      {
                                        auto dtup_fst_502 { std::get<0>(id_2898) };
                                        auto dtup_snd_503 { std::get<1>(id_2898) };
                                        ::dessser::gen::sync_key::ta05201a250c67cd2df71e6345b0a4f16 id_2900 { dtup_fst_499, dtup_fst_502 };
                                        ::dessser::gen::sync_key::t id_2901 { std::in_place_index<12>, id_2900 };
                                        ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2902 { id_2901, dtup_snd_503 };
                                        letpair_res_2899 = id_2902;
                                      }
                                      letpair_res_2897 = letpair_res_2899;
                                    }
                                    let_res_2896 = letpair_res_2897;
                                  }
                                  choose_res_2848 = let_res_2896;
                                } else {
                                  uint16_t id_2903 { 13 };
                                  bool id_2904 { bool(id_2903 == dsum1_fst_451) };
                                  ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2905;
                                  if (id_2904) {
                                    (void)::dessser::Void();
                                    ::dessser::gen::sync_key::t id_2906 { std::in_place_index<13>, ::dessser::Void() };
                                    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2907 { id_2906, dsum1_snd_452 };
                                    choose_res_2905 = id_2907;
                                  } else {
                                    uint16_t id_2908 { 14 };
                                    bool id_2909 { bool(id_2908 == dsum1_fst_451) };
                                    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a choose_res_2910;
                                    if (id_2909) {
                                      auto fun2911 { dessser::gen::team_name::of_row_binary };
                                      ::dessser::gen::sync_key::td204a4115a9974841e2d802fceb65890 id_2912 { fun2911(dsum1_snd_452) };
                                      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2913;
                                      {
                                        ::dessser::gen::sync_key::td204a4115a9974841e2d802fceb65890 drec_474 { id_2912 };
                                        ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2914;
                                        {
                                          auto drec_fst_475 { std::get<0>(drec_474) };
                                          auto drec_snd_476 { std::get<1>(drec_474) };
                                          ::dessser::gen::sync_key::tea08d4d857ea1e66be959e9b3d6681ce id_2915 { team_key_info_of_row_binary(drec_snd_476) };
                                          ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2916;
                                          {
                                            auto drec_fst_478 { std::get<0>(id_2915) };
                                            auto drec_snd_479 { std::get<1>(id_2915) };
                                            ::dessser::gen::sync_key::t387175c465c261e0af17af4010188b4e id_2917 { drec_fst_475, drec_fst_478 };
                                            ::dessser::gen::sync_key::t id_2918 { std::in_place_index<14>, id_2917 };
                                            ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2919 { id_2918, drec_snd_479 };
                                            letpair_res_2916 = id_2919;
                                          }
                                          letpair_res_2914 = letpair_res_2916;
                                        }
                                        let_res_2913 = letpair_res_2914;
                                      }
                                      choose_res_2910 = let_res_2913;
                                    } else {
                                      uint16_t id_2920 { 15 };
                                      bool id_2921 { bool(dsum1_fst_451 == id_2920) };
                                      Void id_2922 { ((void)(assert(id_2921)), ::dessser::Void()) };
                                      (void)id_2922;
                                      uint32_t id_2923 { 0U };
                                      Vec<1, uint32_t> id_2924 {  id_2923  };
                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2925;
                                      {
                                        Vec<1, uint32_t> leb_ref_453 { id_2924 };
                                        uint8_t id_2926 { 0 };
                                        Vec<1, uint8_t> id_2927 {  id_2926  };
                                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2928;
                                        {
                                          Vec<1, uint8_t> shft_ref_454 { id_2927 };
                                          Vec<1, Pointer> id_2929 {  dsum1_snd_452  };
                                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2930;
                                          {
                                            Vec<1, Pointer> p_ref_455 { id_2929 };
                                            bool while_flag_2931 { true };
                                            do {
                                              uint8_t id_2932 { 0 };
                                              Pointer id_2933 { p_ref_455[id_2932] };
                                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2934 { id_2933.readU8() };
                                              bool let_res_2935;
                                              {
                                                ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_456 { id_2934 };
                                                bool letpair_res_2936;
                                                {
                                                  auto leb128_fst_457 { std::get<0>(leb128_456) };
                                                  auto leb128_snd_458 { std::get<1>(leb128_456) };
                                                  uint8_t id_2937 { 0 };
                                                  Void id_2938 { ((void)(p_ref_455[id_2937] = leb128_snd_458), ::dessser::Void()) };
                                                  (void)id_2938;
                                                  uint8_t id_2939 { 0 };
                                                  uint8_t id_2940 { 127 };
                                                  uint8_t id_2941 { uint8_t(leb128_fst_457 & id_2940) };
                                                  uint32_t id_2942 { uint32_t(id_2941) };
                                                  uint8_t id_2943 { 0 };
                                                  uint8_t id_2944 { shft_ref_454[id_2943] };
                                                  uint32_t id_2945 { uint32_t(id_2942 << id_2944) };
                                                  uint8_t id_2946 { 0 };
                                                  uint32_t id_2947 { leb_ref_453[id_2946] };
                                                  uint32_t id_2948 { uint32_t(id_2945 | id_2947) };
                                                  Void id_2949 { ((void)(leb_ref_453[id_2939] = id_2948), ::dessser::Void()) };
                                                  (void)id_2949;
                                                  uint8_t id_2950 { 0 };
                                                  uint8_t id_2951 { 0 };
                                                  uint8_t id_2952 { shft_ref_454[id_2951] };
                                                  uint8_t id_2953 { 7 };
                                                  uint8_t id_2954 { uint8_t(id_2952 + id_2953) };
                                                  Void id_2955 { ((void)(shft_ref_454[id_2950] = id_2954), ::dessser::Void()) };
                                                  (void)id_2955;
                                                  uint8_t id_2956 { 128 };
                                                  bool id_2957 { bool(leb128_fst_457 >= id_2956) };
                                                  letpair_res_2936 = id_2957;
                                                }
                                                let_res_2935 = letpair_res_2936;
                                              }
                                              while_flag_2931 = let_res_2935;
                                              if (while_flag_2931) {
                                                (void)::dessser::Void();
                                              }
                                            } while (while_flag_2931);
                                            (void)::dessser::Void();
                                            uint8_t id_2958 { 0 };
                                            uint32_t id_2959 { leb_ref_453[id_2958] };
                                            Size id_2960 { Size(id_2959) };
                                            uint8_t id_2961 { 0 };
                                            Pointer id_2962 { p_ref_455[id_2961] };
                                            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2963 { id_2960, id_2962 };
                                            let_res_2930 = id_2963;
                                          }
                                          let_res_2928 = let_res_2930;
                                        }
                                        let_res_2925 = let_res_2928;
                                      }
                                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2964;
                                      {
                                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_459 { let_res_2925 };
                                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2965;
                                        {
                                          auto dstring1_fst_460 { std::get<0>(dstring1_459) };
                                          auto dstring1_snd_461 { std::get<1>(dstring1_459) };
                                          ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2966 { dstring1_snd_461.readBytes(dstring1_fst_460) };
                                          ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2967;
                                          {
                                            auto dstring2_fst_463 { std::get<0>(id_2966) };
                                            auto dstring2_snd_464 { std::get<1>(id_2966) };
                                            std::string id_2968 { dstring2_fst_463.toString() };
                                            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2969 { id_2968, dstring2_snd_464 };
                                            letpair_res_2967 = id_2969;
                                          }
                                          letpair_res_2965 = letpair_res_2967;
                                        }
                                        let_res_2964 = letpair_res_2965;
                                      }
                                      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a let_res_2970;
                                      {
                                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_465 { let_res_2964 };
                                        ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2971;
                                        {
                                          auto dtup_fst_466 { std::get<0>(dtup_465) };
                                          auto dtup_snd_467 { std::get<1>(dtup_465) };
                                          ::dessser::gen::sync_key::t1042a3f128208d457ce5fad4bbb3c2d4 id_2972 { incident_key_of_row_binary(dtup_snd_467) };
                                          ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2973;
                                          {
                                            auto dtup_fst_469 { std::get<0>(id_2972) };
                                            auto dtup_snd_470 { std::get<1>(id_2972) };
                                            ::dessser::gen::sync_key::t891de542b31fe57e6f8226ed37c952be id_2974 { dtup_fst_466, dtup_fst_469 };
                                            ::dessser::gen::sync_key::t id_2975 { std::in_place_index<15>, id_2974 };
                                            ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2976 { id_2975, dtup_snd_470 };
                                            letpair_res_2973 = id_2976;
                                          }
                                          letpair_res_2971 = letpair_res_2973;
                                        }
                                        let_res_2970 = letpair_res_2971;
                                      }
                                      choose_res_2910 = let_res_2970;
                                    }
                                    choose_res_2905 = choose_res_2910;
                                  }
                                  choose_res_2848 = choose_res_2905;
                                }
                                choose_res_2836 = choose_res_2848;
                              }
                              choose_res_2831 = choose_res_2836;
                            }
                            choose_res_2809 = choose_res_2831;
                          }
                          choose_res_2802 = choose_res_2809;
                        }
                        choose_res_2737 = choose_res_2802;
                      }
                      choose_res_2665 = choose_res_2737;
                    }
                    choose_res_2658 = choose_res_2665;
                  }
                  choose_res_2653 = choose_res_2658;
                }
                choose_res_2597 = choose_res_2653;
              }
              choose_res_2546 = choose_res_2597;
            }
            choose_res_2541 = choose_res_2546;
          }
          choose_res_2536 = choose_res_2541;
        }
        letpair_res_2533 = choose_res_2536;
      }
      let_res_2532 = letpair_res_2533;
    }
    return let_res_2532;
  }
   };
  return fun2528;
}
std::function<::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a(Pointer &)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_640" "make_snd_641" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_640") (identifier "make_snd_641"))))
 */
static std::function<::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a(Pointer &)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a(Pointer &)> fun2977 { [&](Pointer p_0) {
    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2978 { of_row_binary(p_0) };
    ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a letpair_res_2979;
    {
      auto make_fst_640 { std::get<0>(id_2978) };
      auto make_snd_641 { std::get<1>(id_2978) };
      ::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a id_2980 { make_fst_640, make_snd_641 };
      letpair_res_2979 = id_2980;
    }
    return letpair_res_2979;
  }
   };
  return fun2977;
}
std::function<::dessser::gen::sync_key::t34ebba618a0ff1a9bcb6711a6bde703a(Pointer &)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams {name: $team_name; info: (team_key_info AS [Contacts STRING | Inhibition STRING])} | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(::dessser::gen::sync_key::t &,Pointer &)> wrap_to_row_binary_init()
{
  std::function<Pointer(::dessser::gen::sync_key::t &,Pointer &)> fun2981 { [&](::dessser::gen::sync_key::t p_0, Pointer p_1) {
    Pointer id_2982 { to_row_binary(p_0, p_1) };
    return id_2982;
  }
   };
  return fun2981;
}
std::function<Pointer(::dessser::gen::sync_key::t &,Pointer &)> wrap_to_row_binary(wrap_to_row_binary_init());


}
