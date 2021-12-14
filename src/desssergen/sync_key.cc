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
struct t64c0474e57c610aaa3e07cb04692cefe : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::sync_key::dialog_key> 
> {
  using tuple::tuple;
  t64c0474e57c610aaa3e07cb04692cefe(std::tuple<std::string, std::shared_ptr<::dessser::gen::sync_key::dialog_key> > p)
    : std::tuple<std::string, std::shared_ptr<::dessser::gen::sync_key::dialog_key> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t64c0474e57c610aaa3e07cb04692cefe const &a, t64c0474e57c610aaa3e07cb04692cefe const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t64c0474e57c610aaa3e07cb04692cefe const &a, t64c0474e57c610aaa3e07cb04692cefe const &b) {
  return !operator==(a, b);
}
struct taf1e37f579ece7fa9db5670cfd23039b : public std::tuple<
  double,
  uint32_t
> {
  using tuple::tuple;
  taf1e37f579ece7fa9db5670cfd23039b(std::tuple<double, uint32_t> p)
    : std::tuple<double, uint32_t>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(taf1e37f579ece7fa9db5670cfd23039b const &a, taf1e37f579ece7fa9db5670cfd23039b const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(taf1e37f579ece7fa9db5670cfd23039b const &a, taf1e37f579ece7fa9db5670cfd23039b const &b) {
  return !operator==(a, b);
}
struct incident_key : public std::variant<
  Void, // FirstStartNotif
  Void, // LastStartNotif
  Void, // LastStopNotif
  Void, // LastStateChangeNotif
  Void, // Team
  ::dessser::gen::sync_key::t64c0474e57c610aaa3e07cb04692cefe, // Dialogs
  ::dessser::gen::sync_key::taf1e37f579ece7fa9db5670cfd23039b // Journal
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
struct t35f466ab2ffe47e08d3d46d20f2eb1a6 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0
> {
  using tuple::tuple;
  t35f466ab2ffe47e08d3d46d20f2eb1a6(std::tuple<std::string, ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t35f466ab2ffe47e08d3d46d20f2eb1a6 const &a, t35f466ab2ffe47e08d3d46d20f2eb1a6 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t35f466ab2ffe47e08d3d46d20f2eb1a6 const &a, t35f466ab2ffe47e08d3d46d20f2eb1a6 const &b) {
  return !operator==(a, b);
}
struct per_worker_data : public std::variant<
  Void, // RuntimeStats
  Void, // ArchivedTimes
  Void, // NumArcFiles
  Void, // NumArcBytes
  Void, // AllocedArcBytes
  Void, // Worker
  ::dessser::gen::sync_key::t35f466ab2ffe47e08d3d46d20f2eb1a6, // PerInstance
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
  std::shared_ptr<::dessser::gen::sync_key::per_worker_data> 
> {
  using tuple::tuple;
  per_worker(std::tuple<dessser::gen::fq_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_worker_data> > p)
    : std::tuple<dessser::gen::fq_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_worker_data> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(per_worker const &a, per_worker const &b) {
  return ::dessser::gen::fq_name::Deref(std::get<0>(a)) == ::dessser::gen::fq_name::Deref(std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
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
struct t3ac6072d22a4c4a598bde9a5fc94f773 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9
> {
  using tuple::tuple;
  t3ac6072d22a4c4a598bde9a5fc94f773(std::tuple<std::string, ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3ac6072d22a4c4a598bde9a5fc94f773 const &a, t3ac6072d22a4c4a598bde9a5fc94f773 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3ac6072d22a4c4a598bde9a5fc94f773 const &a, t3ac6072d22a4c4a598bde9a5fc94f773 const &b) {
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
struct t861fec96932eb3dcd604deb55a8fed37 : public std::tuple<
  std::string,
  ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51
> {
  using tuple::tuple;
  t861fec96932eb3dcd604deb55a8fed37(std::tuple<std::string, ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51> p)
    : std::tuple<std::string, ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t861fec96932eb3dcd604deb55a8fed37 const &a, t861fec96932eb3dcd604deb55a8fed37 const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t861fec96932eb3dcd604deb55a8fed37 const &a, t861fec96932eb3dcd604deb55a8fed37 const &b) {
  return !operator==(a, b);
}
struct per_site_data : public std::variant<
  Void, // IsMaster
  ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773, // PerService
  std::shared_ptr<::dessser::gen::sync_key::per_worker> , // PerWorker
  ::dessser::gen::sync_key::t861fec96932eb3dcd604deb55a8fed37 // PerProgram
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
struct per_site : public std::tuple<
  dessser::gen::site_name::t_ext,
  std::shared_ptr<::dessser::gen::sync_key::per_site_data> 
> {
  using tuple::tuple;
  per_site(std::tuple<dessser::gen::site_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_site_data> > p)
    : std::tuple<dessser::gen::site_name::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_site_data> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(per_site const &a, per_site const &b) {
  return ::dessser::gen::site_name::Deref(std::get<0>(a)) == ::dessser::gen::site_name::Deref(std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(per_site const &a, per_site const &b) {
  return !operator==(a, b);
}
struct t5dbfadfb7b29c686ebe36a9b92f12903 : public std::tuple<
  dessser::gen::src_path::t_ext,
  std::string
> {
  using tuple::tuple;
  t5dbfadfb7b29c686ebe36a9b92f12903(std::tuple<dessser::gen::src_path::t_ext, std::string> p)
    : std::tuple<dessser::gen::src_path::t_ext, std::string>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5dbfadfb7b29c686ebe36a9b92f12903 const &a, t5dbfadfb7b29c686ebe36a9b92f12903 const &b) {
  return ::dessser::gen::src_path::Deref(std::get<0>(a)) == ::dessser::gen::src_path::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t5dbfadfb7b29c686ebe36a9b92f12903 const &a, t5dbfadfb7b29c686ebe36a9b92f12903 const &b) {
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
struct t5ea3af2f8623cdaebfc7634cbf90ee9c : public std::tuple<
  dessser::gen::sync_socket::t_ext,
  std::shared_ptr<::dessser::gen::sync_key::per_client> 
> {
  using tuple::tuple;
  t5ea3af2f8623cdaebfc7634cbf90ee9c(std::tuple<dessser::gen::sync_socket::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_client> > p)
    : std::tuple<dessser::gen::sync_socket::t_ext, std::shared_ptr<::dessser::gen::sync_key::per_client> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5ea3af2f8623cdaebfc7634cbf90ee9c const &a, t5ea3af2f8623cdaebfc7634cbf90ee9c const &b) {
  return ::dessser::gen::sync_socket::Deref(std::get<0>(a)) == ::dessser::gen::sync_socket::Deref(std::get<0>(b)) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t5ea3af2f8623cdaebfc7634cbf90ee9c const &a, t5ea3af2f8623cdaebfc7634cbf90ee9c const &b) {
  return !operator==(a, b);
}
struct per_dash_key;
inline std::ostream &operator<<(std::ostream &, struct per_dash_key const &);
inline std::ostream &operator<<(std::ostream &, std::shared_ptr<struct per_dash_key> const);
inline bool operator==(struct per_dash_key const &, struct per_dash_key const &);
inline bool operator!=(struct per_dash_key const &, struct per_dash_key const &);
struct t5f85ea99fc65adca3880884cd8e9f15d : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::sync_key::per_dash_key> 
> {
  using tuple::tuple;
  t5f85ea99fc65adca3880884cd8e9f15d(std::tuple<std::string, std::shared_ptr<::dessser::gen::sync_key::per_dash_key> > p)
    : std::tuple<std::string, std::shared_ptr<::dessser::gen::sync_key::per_dash_key> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t5f85ea99fc65adca3880884cd8e9f15d const &a, t5f85ea99fc65adca3880884cd8e9f15d const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(t5f85ea99fc65adca3880884cd8e9f15d const &a, t5f85ea99fc65adca3880884cd8e9f15d const &b) {
  return !operator==(a, b);
}
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
struct t3fa506fd8c7ad175afbb77516ca40d23 : public std::tuple<
  dessser::gen::team_name::t_ext,
  ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb
> {
  using tuple::tuple;
  t3fa506fd8c7ad175afbb77516ca40d23(std::tuple<dessser::gen::team_name::t_ext, ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb> p)
    : std::tuple<dessser::gen::team_name::t_ext, ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t3fa506fd8c7ad175afbb77516ca40d23 const &a, t3fa506fd8c7ad175afbb77516ca40d23 const &b) {
  return ::dessser::gen::team_name::Deref(std::get<0>(a)) == ::dessser::gen::team_name::Deref(std::get<0>(b)) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t3fa506fd8c7ad175afbb77516ca40d23 const &a, t3fa506fd8c7ad175afbb77516ca40d23 const &b) {
  return !operator==(a, b);
}
struct tdce75d0a7767ecd39280979e2e5897b1 : public std::tuple<
  std::string,
  std::shared_ptr<::dessser::gen::sync_key::incident_key> 
> {
  using tuple::tuple;
  tdce75d0a7767ecd39280979e2e5897b1(std::tuple<std::string, std::shared_ptr<::dessser::gen::sync_key::incident_key> > p)
    : std::tuple<std::string, std::shared_ptr<::dessser::gen::sync_key::incident_key> >(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(tdce75d0a7767ecd39280979e2e5897b1 const &a, tdce75d0a7767ecd39280979e2e5897b1 const &b) {
  return std::get<0>(a) == std::get<0>(b) && (*std::get<1>(a)) == (*std::get<1>(b));
}
inline bool operator!=(tdce75d0a7767ecd39280979e2e5897b1 const &a, tdce75d0a7767ecd39280979e2e5897b1 const &b) {
  return !operator==(a, b);
}
struct t : public std::variant<
  Void, // DevNull
  Void, // Time
  std::string, // Versions
  ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903, // Sources
  Void, // TargetConfig
  std::shared_ptr<::dessser::gen::sync_key::per_site> , // PerSite
  ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c, // Storage
  ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc, // Tails
  uint16_t, // Replays
  std::optional<dessser::gen::sync_socket::t_ext>, // Error
  Void, // ReplayRequests
  ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c, // PerClient
  ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d, // Dashboards
  Void, // Notifications
  ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23, // Teams
  ::dessser::gen::sync_key::tdce75d0a7767ecd39280979e2e5897b1 // Incidents
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
struct t685051b3783a797b8142eff00f35a04f : public std::tuple<
  ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb,
  Pointer
> {
  using tuple::tuple;
  t685051b3783a797b8142eff00f35a04f(std::tuple<::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb, Pointer> p)
    : std::tuple<::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb, Pointer>(std::get<0>(p), std::get<1>(p)) {}
};
inline bool operator==(t685051b3783a797b8142eff00f35a04f const &a, t685051b3783a797b8142eff00f35a04f const &b) {
  return std::get<0>(a) == std::get<0>(b) && std::get<1>(a) == std::get<1>(b);
}
inline bool operator!=(t685051b3783a797b8142eff00f35a04f const &a, t685051b3783a797b8142eff00f35a04f const &b) {
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
      (let "ssum_dst_756" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_756")
          (if (eq (u16 1) (label-of (param 0))) (identifier "ssum_dst_756")
            (if (eq (u16 2) (label-of (param 0))) (identifier "ssum_dst_756")
              (if (eq (u16 3) (label-of (param 0))) (identifier "ssum_dst_756")
                (if (eq (u16 4) (label-of (param 0))) (identifier "ssum_dst_756") (if (eq (u16 5) (label-of (param 0))) (identifier "ssum_dst_756") (seq (assert (eq (label-of (param 0)) (u16 6))) (identifier "ssum_dst_756"))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::dialog_key> ,Pointer)> dialog_key_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::dialog_key> ,Pointer)> fun0 { [&fun0](std::shared_ptr<::dessser::gen::sync_key::dialog_key>  p_0, Pointer p_1) {
    uint16_t id_1 { uint16_t((*p_0).index()) };
    Pointer id_2 { p_1.writeU16Le(id_1) };
    Pointer let_res_3;
    {
      Pointer ssum_dst_756 { id_2 };
      uint16_t id_4 { 0 };
      uint16_t id_5 { uint16_t((*p_0).index()) };
      bool id_6 { bool(id_4 == id_5) };
      Pointer choose_res_7;
      if (id_6) {
        choose_res_7 = ssum_dst_756;
      } else {
        uint16_t id_8 { 1 };
        uint16_t id_9 { uint16_t((*p_0).index()) };
        bool id_10 { bool(id_8 == id_9) };
        Pointer choose_res_11;
        if (id_10) {
          choose_res_11 = ssum_dst_756;
        } else {
          uint16_t id_12 { 2 };
          uint16_t id_13 { uint16_t((*p_0).index()) };
          bool id_14 { bool(id_12 == id_13) };
          Pointer choose_res_15;
          if (id_14) {
            choose_res_15 = ssum_dst_756;
          } else {
            uint16_t id_16 { 3 };
            uint16_t id_17 { uint16_t((*p_0).index()) };
            bool id_18 { bool(id_16 == id_17) };
            Pointer choose_res_19;
            if (id_18) {
              choose_res_19 = ssum_dst_756;
            } else {
              uint16_t id_20 { 4 };
              uint16_t id_21 { uint16_t((*p_0).index()) };
              bool id_22 { bool(id_20 == id_21) };
              Pointer choose_res_23;
              if (id_22) {
                choose_res_23 = ssum_dst_756;
              } else {
                uint16_t id_24 { 5 };
                uint16_t id_25 { uint16_t((*p_0).index()) };
                bool id_26 { bool(id_24 == id_25) };
                Pointer choose_res_27;
                if (id_26) {
                  choose_res_27 = ssum_dst_756;
                } else {
                  uint16_t id_28 { uint16_t((*p_0).index()) };
                  uint16_t id_29 { 6 };
                  bool id_30 { bool(id_28 == id_29) };
                  Void id_31 { ((void)(assert(id_30)), ::dessser::VOID) };
                  (void)id_31;
                  choose_res_27 = ssum_dst_756;
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
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::dialog_key> ,Pointer)> dialog_key_to_row_binary(dialog_key_to_row_binary_init());

/* 
    (fun ("[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" "Ptr")
      (let "ssum_dst_758" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_758")
          (if (eq (u16 1) (label-of (param 0))) (identifier "ssum_dst_758")
            (if (eq (u16 2) (label-of (param 0))) (identifier "ssum_dst_758")
              (if (eq (u16 3) (label-of (param 0))) (identifier "ssum_dst_758")
                (if (eq (u16 4) (label-of (param 0))) (identifier "ssum_dst_758")
                  (if (eq (u16 5) (label-of (param 0)))
                    (let "stup_dst_762"
                      (write-bytes
                        (let "leb128_sz_760" (make-vec (string-length (get-item 0 (get-alt "Dialogs" (param 0)))))
                          (let "leb128_ptr_761" (make-vec (identifier "ssum_dst_758"))
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
                        (bytes-of-string (get-item 0 (get-alt "Dialogs" (param 0))))) 
                      (apply (identifier "dialog_key-to-row-binary") (get-item 1 (get-alt "Dialogs" (param 0))) (identifier "stup_dst_762")))
                    (seq (assert (eq (label-of (param 0)) (u16 6)))
                      (let "stup_dst_759" (write-u64 little-endian (identifier "ssum_dst_758") (u64-of-float (get-item 0 (get-alt "Journal" (param 0)))))
                        (write-u32 little-endian (identifier "stup_dst_759") (get-item 1 (get-alt "Journal" (param 0))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::incident_key> ,Pointer)> incident_key_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::incident_key> ,Pointer)> fun32 { [&fun32](std::shared_ptr<::dessser::gen::sync_key::incident_key>  p_0, Pointer p_1) {
    uint16_t id_33 { uint16_t((*p_0).index()) };
    Pointer id_34 { p_1.writeU16Le(id_33) };
    Pointer let_res_35;
    {
      Pointer ssum_dst_758 { id_34 };
      uint16_t id_36 { 0 };
      uint16_t id_37 { uint16_t((*p_0).index()) };
      bool id_38 { bool(id_36 == id_37) };
      Pointer choose_res_39;
      if (id_38) {
        choose_res_39 = ssum_dst_758;
      } else {
        uint16_t id_40 { 1 };
        uint16_t id_41 { uint16_t((*p_0).index()) };
        bool id_42 { bool(id_40 == id_41) };
        Pointer choose_res_43;
        if (id_42) {
          choose_res_43 = ssum_dst_758;
        } else {
          uint16_t id_44 { 2 };
          uint16_t id_45 { uint16_t((*p_0).index()) };
          bool id_46 { bool(id_44 == id_45) };
          Pointer choose_res_47;
          if (id_46) {
            choose_res_47 = ssum_dst_758;
          } else {
            uint16_t id_48 { 3 };
            uint16_t id_49 { uint16_t((*p_0).index()) };
            bool id_50 { bool(id_48 == id_49) };
            Pointer choose_res_51;
            if (id_50) {
              choose_res_51 = ssum_dst_758;
            } else {
              uint16_t id_52 { 4 };
              uint16_t id_53 { uint16_t((*p_0).index()) };
              bool id_54 { bool(id_52 == id_53) };
              Pointer choose_res_55;
              if (id_54) {
                choose_res_55 = ssum_dst_758;
              } else {
                uint16_t id_56 { 5 };
                uint16_t id_57 { uint16_t((*p_0).index()) };
                bool id_58 { bool(id_56 == id_57) };
                Pointer choose_res_59;
                if (id_58) {
                  ::dessser::gen::sync_key::t64c0474e57c610aaa3e07cb04692cefe id_60 { std::get<5 /* Dialogs */>((*p_0)) };
                  std::string id_61 { std::get<0>(id_60) };
                  uint32_t id_62 { (uint32_t)id_61.size() };
                  Vec<1, uint32_t> id_63 {  id_62  };
                  Pointer let_res_64;
                  {
                    Vec<1, uint32_t> leb128_sz_760 { id_63 };
                    Vec<1, Pointer> id_65 {  ssum_dst_758  };
                    Pointer let_res_66;
                    {
                      Vec<1, Pointer> leb128_ptr_761 { id_65 };
                      bool while_flag_67 { true };
                      do {
                        uint8_t id_68 { 0 };
                        uint8_t id_69 { 0 };
                        Pointer id_70 { leb128_ptr_761[id_69] };
                        uint32_t id_71 { 128U };
                        uint8_t id_72 { 0 };
                        uint32_t id_73 { leb128_sz_760[id_72] };
                        bool id_74 { bool(id_71 > id_73) };
                        uint8_t choose_res_75;
                        if (id_74) {
                          uint8_t id_76 { 0 };
                          uint32_t id_77 { leb128_sz_760[id_76] };
                          uint8_t id_78 { uint8_t(id_77) };
                          choose_res_75 = id_78;
                        } else {
                          uint8_t id_79 { 0 };
                          uint32_t id_80 { leb128_sz_760[id_79] };
                          uint8_t id_81 { uint8_t(id_80) };
                          uint8_t id_82 { 128 };
                          uint8_t id_83 { uint8_t(id_81 | id_82) };
                          choose_res_75 = id_83;
                        }
                        Pointer id_84 { id_70.writeU8(choose_res_75) };
                        Void id_85 { ((void)(leb128_ptr_761[id_68] = id_84), ::dessser::VOID) };
                        (void)id_85;
                        uint8_t id_86 { 0 };
                        uint8_t id_87 { 0 };
                        uint32_t id_88 { leb128_sz_760[id_87] };
                        uint8_t id_89 { 7 };
                        uint32_t id_90 { uint32_t(id_88 >> id_89) };
                        Void id_91 { ((void)(leb128_sz_760[id_86] = id_90), ::dessser::VOID) };
                        (void)id_91;
                        uint8_t id_92 { 0 };
                        uint32_t id_93 { leb128_sz_760[id_92] };
                        uint32_t id_94 { 0U };
                        bool id_95 { bool(id_93 > id_94) };
                        while_flag_67 = id_95;
                        if (while_flag_67) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_67);
                      (void)::dessser::VOID;
                      uint8_t id_96 { 0 };
                      Pointer id_97 { leb128_ptr_761[id_96] };
                      let_res_66 = id_97;
                    }
                    let_res_64 = let_res_66;
                  }
                  ::dessser::gen::sync_key::t64c0474e57c610aaa3e07cb04692cefe id_98 { std::get<5 /* Dialogs */>((*p_0)) };
                  std::string id_99 { std::get<0>(id_98) };
                  Bytes id_100 { id_99 };
                  Pointer id_101 { let_res_64.writeBytes(id_100) };
                  Pointer let_res_102;
                  {
                    Pointer stup_dst_762 { id_101 };
                    ::dessser::gen::sync_key::t64c0474e57c610aaa3e07cb04692cefe id_103 { std::get<5 /* Dialogs */>((*p_0)) };
                    std::shared_ptr<::dessser::gen::sync_key::dialog_key>  id_104 { std::get<1>(id_103) };
                    Pointer id_105 { dialog_key_to_row_binary(id_104, stup_dst_762) };
                    let_res_102 = id_105;
                  }
                  choose_res_59 = let_res_102;
                } else {
                  uint16_t id_106 { uint16_t((*p_0).index()) };
                  uint16_t id_107 { 6 };
                  bool id_108 { bool(id_106 == id_107) };
                  Void id_109 { ((void)(assert(id_108)), ::dessser::VOID) };
                  (void)id_109;
                  ::dessser::gen::sync_key::taf1e37f579ece7fa9db5670cfd23039b id_110 { std::get<6 /* Journal */>((*p_0)) };
                  double id_111 { std::get<0>(id_110) };
                  uint64_t id_112 { qword_of_float(id_111) };
                  Pointer id_113 { ssum_dst_758.writeU64Le(id_112) };
                  Pointer let_res_114;
                  {
                    Pointer stup_dst_759 { id_113 };
                    ::dessser::gen::sync_key::taf1e37f579ece7fa9db5670cfd23039b id_115 { std::get<6 /* Journal */>((*p_0)) };
                    uint32_t id_116 { std::get<1>(id_115) };
                    Pointer id_117 { stup_dst_759.writeU32Le(id_116) };
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
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::incident_key> ,Pointer)> incident_key_to_row_binary(incident_key_to_row_binary_init());

/* 
    (fun ("[Widgets U32]" "Ptr")
      (let "ssum_dst_750" (write-u16 little-endian (param 1) (label-of (param 0))) (seq (assert (eq (label-of (param 0)) (u16 0))) (write-u32 little-endian (identifier "ssum_dst_750") (get-alt "Widgets" (param 0))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> per_dash_key_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> fun118 { [&fun118](std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  p_0, Pointer p_1) {
    uint16_t id_119 { uint16_t((*p_0).index()) };
    Pointer id_120 { p_1.writeU16Le(id_119) };
    Pointer let_res_121;
    {
      Pointer ssum_dst_750 { id_120 };
      uint16_t id_122 { uint16_t((*p_0).index()) };
      uint16_t id_123 { 0 };
      bool id_124 { bool(id_122 == id_123) };
      Void id_125 { ((void)(assert(id_124)), ::dessser::VOID) };
      (void)id_125;
      uint32_t id_126 { std::get<0 /* Widgets */>((*p_0)) };
      Pointer id_127 { ssum_dst_750.writeU32Le(id_126) };
      let_res_121 = id_127;
    }
    return let_res_121;
  }
   };
  return fun118;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> ,Pointer)> per_dash_key_to_row_binary(per_dash_key_to_row_binary_init());

/* 
    (fun ("[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" "Ptr")
      (let "ssum_dst_752" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_753" (make-vec (string-length (get-alt "Response" (param 0))))
              (let "leb128_ptr_754" (make-vec (identifier "ssum_dst_752"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_754")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_754"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_753"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_753"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_753"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_753") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_753")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_753")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_754"))))) 
            (bytes-of-string (get-alt "Response" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (apply (identifier "per_dash_key-to-row-binary") (get-alt "Scratchpad" (param 0)) (identifier "ssum_dst_752"))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> per_client_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> fun128 { [&fun128](std::shared_ptr<::dessser::gen::sync_key::per_client>  p_0, Pointer p_1) {
    uint16_t id_129 { uint16_t((*p_0).index()) };
    Pointer id_130 { p_1.writeU16Le(id_129) };
    Pointer let_res_131;
    {
      Pointer ssum_dst_752 { id_130 };
      uint16_t id_132 { 0 };
      uint16_t id_133 { uint16_t((*p_0).index()) };
      bool id_134 { bool(id_132 == id_133) };
      Pointer choose_res_135;
      if (id_134) {
        std::string id_136 { std::get<0 /* Response */>((*p_0)) };
        uint32_t id_137 { (uint32_t)id_136.size() };
        Vec<1, uint32_t> id_138 {  id_137  };
        Pointer let_res_139;
        {
          Vec<1, uint32_t> leb128_sz_753 { id_138 };
          Vec<1, Pointer> id_140 {  ssum_dst_752  };
          Pointer let_res_141;
          {
            Vec<1, Pointer> leb128_ptr_754 { id_140 };
            bool while_flag_142 { true };
            do {
              uint8_t id_143 { 0 };
              uint8_t id_144 { 0 };
              Pointer id_145 { leb128_ptr_754[id_144] };
              uint32_t id_146 { 128U };
              uint8_t id_147 { 0 };
              uint32_t id_148 { leb128_sz_753[id_147] };
              bool id_149 { bool(id_146 > id_148) };
              uint8_t choose_res_150;
              if (id_149) {
                uint8_t id_151 { 0 };
                uint32_t id_152 { leb128_sz_753[id_151] };
                uint8_t id_153 { uint8_t(id_152) };
                choose_res_150 = id_153;
              } else {
                uint8_t id_154 { 0 };
                uint32_t id_155 { leb128_sz_753[id_154] };
                uint8_t id_156 { uint8_t(id_155) };
                uint8_t id_157 { 128 };
                uint8_t id_158 { uint8_t(id_156 | id_157) };
                choose_res_150 = id_158;
              }
              Pointer id_159 { id_145.writeU8(choose_res_150) };
              Void id_160 { ((void)(leb128_ptr_754[id_143] = id_159), ::dessser::VOID) };
              (void)id_160;
              uint8_t id_161 { 0 };
              uint8_t id_162 { 0 };
              uint32_t id_163 { leb128_sz_753[id_162] };
              uint8_t id_164 { 7 };
              uint32_t id_165 { uint32_t(id_163 >> id_164) };
              Void id_166 { ((void)(leb128_sz_753[id_161] = id_165), ::dessser::VOID) };
              (void)id_166;
              uint8_t id_167 { 0 };
              uint32_t id_168 { leb128_sz_753[id_167] };
              uint32_t id_169 { 0U };
              bool id_170 { bool(id_168 > id_169) };
              while_flag_142 = id_170;
              if (while_flag_142) {
                (void)::dessser::VOID;
              }
            } while (while_flag_142);
            (void)::dessser::VOID;
            uint8_t id_171 { 0 };
            Pointer id_172 { leb128_ptr_754[id_171] };
            let_res_141 = id_172;
          }
          let_res_139 = let_res_141;
        }
        std::string id_173 { std::get<0 /* Response */>((*p_0)) };
        Bytes id_174 { id_173 };
        Pointer id_175 { let_res_139.writeBytes(id_174) };
        choose_res_135 = id_175;
      } else {
        uint16_t id_176 { uint16_t((*p_0).index()) };
        uint16_t id_177 { 1 };
        bool id_178 { bool(id_176 == id_177) };
        Void id_179 { ((void)(assert(id_178)), ::dessser::VOID) };
        (void)id_179;
        std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_180 { std::get<1 /* Scratchpad */>((*p_0)) };
        Pointer id_181 { per_dash_key_to_row_binary(id_180, ssum_dst_752) };
        choose_res_135 = id_181;
      }
      let_res_131 = choose_res_135;
    }
    return let_res_131;
  }
   };
  return fun128;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_client> ,Pointer)> per_client_to_row_binary(per_client_to_row_binary_init());

/* 
    (fun ("[Subscriber STRING | LastTuple U32]" "Ptr")
      (let "ssum_dst_746" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0)))
          (write-bytes
            (let "leb128_sz_747" (make-vec (string-length (get-alt "Subscriber" (param 0))))
              (let "leb128_ptr_748" (make-vec (identifier "ssum_dst_746"))
                (seq
                  (while
                    (seq
                      (set-vec (u8 0) (identifier "leb128_ptr_748")
                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_748"))
                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_747"))) (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_747"))) (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_747"))) (u8 128)))))
                      (set-vec (u8 0) (identifier "leb128_sz_747") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_747")) (u8 7))) 
                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_747")) (u32 0))) 
                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_748"))))) 
            (bytes-of-string (get-alt "Subscriber" (param 0)))) (seq (assert (eq (label-of (param 0)) (u16 1))) (write-u32 little-endian (identifier "ssum_dst_746") (get-alt "LastTuple" (param 0)))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> per_tail_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> fun182 { [&fun182](std::shared_ptr<::dessser::gen::sync_key::per_tail>  p_0, Pointer p_1) {
    uint16_t id_183 { uint16_t((*p_0).index()) };
    Pointer id_184 { p_1.writeU16Le(id_183) };
    Pointer let_res_185;
    {
      Pointer ssum_dst_746 { id_184 };
      uint16_t id_186 { 0 };
      uint16_t id_187 { uint16_t((*p_0).index()) };
      bool id_188 { bool(id_186 == id_187) };
      Pointer choose_res_189;
      if (id_188) {
        std::string id_190 { std::get<0 /* Subscriber */>((*p_0)) };
        uint32_t id_191 { (uint32_t)id_190.size() };
        Vec<1, uint32_t> id_192 {  id_191  };
        Pointer let_res_193;
        {
          Vec<1, uint32_t> leb128_sz_747 { id_192 };
          Vec<1, Pointer> id_194 {  ssum_dst_746  };
          Pointer let_res_195;
          {
            Vec<1, Pointer> leb128_ptr_748 { id_194 };
            bool while_flag_196 { true };
            do {
              uint8_t id_197 { 0 };
              uint8_t id_198 { 0 };
              Pointer id_199 { leb128_ptr_748[id_198] };
              uint32_t id_200 { 128U };
              uint8_t id_201 { 0 };
              uint32_t id_202 { leb128_sz_747[id_201] };
              bool id_203 { bool(id_200 > id_202) };
              uint8_t choose_res_204;
              if (id_203) {
                uint8_t id_205 { 0 };
                uint32_t id_206 { leb128_sz_747[id_205] };
                uint8_t id_207 { uint8_t(id_206) };
                choose_res_204 = id_207;
              } else {
                uint8_t id_208 { 0 };
                uint32_t id_209 { leb128_sz_747[id_208] };
                uint8_t id_210 { uint8_t(id_209) };
                uint8_t id_211 { 128 };
                uint8_t id_212 { uint8_t(id_210 | id_211) };
                choose_res_204 = id_212;
              }
              Pointer id_213 { id_199.writeU8(choose_res_204) };
              Void id_214 { ((void)(leb128_ptr_748[id_197] = id_213), ::dessser::VOID) };
              (void)id_214;
              uint8_t id_215 { 0 };
              uint8_t id_216 { 0 };
              uint32_t id_217 { leb128_sz_747[id_216] };
              uint8_t id_218 { 7 };
              uint32_t id_219 { uint32_t(id_217 >> id_218) };
              Void id_220 { ((void)(leb128_sz_747[id_215] = id_219), ::dessser::VOID) };
              (void)id_220;
              uint8_t id_221 { 0 };
              uint32_t id_222 { leb128_sz_747[id_221] };
              uint32_t id_223 { 0U };
              bool id_224 { bool(id_222 > id_223) };
              while_flag_196 = id_224;
              if (while_flag_196) {
                (void)::dessser::VOID;
              }
            } while (while_flag_196);
            (void)::dessser::VOID;
            uint8_t id_225 { 0 };
            Pointer id_226 { leb128_ptr_748[id_225] };
            let_res_195 = id_226;
          }
          let_res_193 = let_res_195;
        }
        std::string id_227 { std::get<0 /* Subscriber */>((*p_0)) };
        Bytes id_228 { id_227 };
        Pointer id_229 { let_res_193.writeBytes(id_228) };
        choose_res_189 = id_229;
      } else {
        uint16_t id_230 { uint16_t((*p_0).index()) };
        uint16_t id_231 { 1 };
        bool id_232 { bool(id_230 == id_231) };
        Void id_233 { ((void)(assert(id_232)), ::dessser::VOID) };
        (void)id_233;
        uint32_t id_234 { std::get<1 /* LastTuple */>((*p_0)) };
        Pointer id_235 { ssum_dst_746.writeU32Le(id_234) };
        choose_res_189 = id_235;
      }
      let_res_185 = choose_res_189;
    }
    return let_res_185;
  }
   };
  return fun182;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_tail> ,Pointer)> per_tail_to_row_binary(per_tail_to_row_binary_init());

/* 
    (fun ("[RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]" "Ptr")
      (let "label1_724" (label-of (param 0))
        (let "ssum_dst_725" (write-u16 little-endian (param 1) (identifier "label1_724"))
          (if (eq (u16 0) (identifier "label1_724")) (identifier "ssum_dst_725")
            (if (eq (u16 1) (identifier "label1_724")) (identifier "ssum_dst_725")
              (if (eq (u16 2) (identifier "label1_724")) (identifier "ssum_dst_725")
                (if (eq (u16 3) (identifier "label1_724")) (identifier "ssum_dst_725")
                  (if (eq (u16 4) (identifier "label1_724")) (identifier "ssum_dst_725")
                    (if (eq (u16 5) (identifier "label1_724")) (identifier "ssum_dst_725")
                      (if (eq (u16 6) (identifier "label1_724"))
                        (let "stup_dst_728"
                          (write-bytes
                            (let "leb128_sz_726" (make-vec (string-length (get-item 0 (get-alt "PerInstance" (param 0)))))
                              (let "leb128_ptr_727" (make-vec (identifier "ssum_dst_725"))
                                (seq
                                  (while
                                    (seq
                                      (set-vec (u8 0) (identifier "leb128_ptr_727")
                                        (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_727"))
                                          (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_726"))) 
                                            (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_726"))) 
                                            (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_726"))) (u8 128)))))
                                      (set-vec (u8 0) (identifier "leb128_sz_726") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_726")) (u8 7))) 
                                      (gt (unsafe-nth (u8 0) (identifier "leb128_sz_726")) (u32 0))) 
                                    (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_727"))))) 
                            (bytes-of-string (get-item 0 (get-alt "PerInstance" (param 0)))))
                          (let "label1_729" (label-of (get-item 1 (get-alt "PerInstance" (param 0))))
                            (let "ssum_dst_730" (write-u16 little-endian (identifier "stup_dst_728") (identifier "label1_729"))
                              (if (eq (u16 0) (identifier "label1_729")) 
                                (identifier "ssum_dst_730")
                                (if (eq (u16 1) (identifier "label1_729")) 
                                  (identifier "ssum_dst_730")
                                  (if (eq (u16 2) (identifier "label1_729")) 
                                    (identifier "ssum_dst_730")
                                    (if (eq (u16 3) (identifier "label1_729")) 
                                      (identifier "ssum_dst_730")
                                      (if (eq (u16 4) (identifier "label1_729")) 
                                        (identifier "ssum_dst_730")
                                        (if (eq (u16 5) (identifier "label1_729")) 
                                          (identifier "ssum_dst_730") 
                                          (if (eq (u16 6) (identifier "label1_729")) (identifier "ssum_dst_730") (seq (assert (eq (identifier "label1_729") (u16 7))) (identifier "ssum_dst_730"))))))))))))
                        (if (eq (u16 7) (identifier "label1_724")) (write-u32 little-endian (identifier "ssum_dst_725") (get-alt "PerReplayer" (param 0)))
                          (seq (assert (eq (identifier "label1_724") (u16 8))) (identifier "ssum_dst_725")))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,Pointer)> per_worker_data_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,Pointer)> fun236 { [&fun236](std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  p_0, Pointer p_1) {
    uint16_t id_237 { uint16_t((*p_0).index()) };
    Pointer let_res_238;
    {
      uint16_t label1_724 { id_237 };
      Pointer id_239 { p_1.writeU16Le(label1_724) };
      Pointer let_res_240;
      {
        Pointer ssum_dst_725 { id_239 };
        uint16_t id_241 { 0 };
        bool id_242 { bool(id_241 == label1_724) };
        Pointer choose_res_243;
        if (id_242) {
          choose_res_243 = ssum_dst_725;
        } else {
          uint16_t id_244 { 1 };
          bool id_245 { bool(id_244 == label1_724) };
          Pointer choose_res_246;
          if (id_245) {
            choose_res_246 = ssum_dst_725;
          } else {
            uint16_t id_247 { 2 };
            bool id_248 { bool(id_247 == label1_724) };
            Pointer choose_res_249;
            if (id_248) {
              choose_res_249 = ssum_dst_725;
            } else {
              uint16_t id_250 { 3 };
              bool id_251 { bool(id_250 == label1_724) };
              Pointer choose_res_252;
              if (id_251) {
                choose_res_252 = ssum_dst_725;
              } else {
                uint16_t id_253 { 4 };
                bool id_254 { bool(id_253 == label1_724) };
                Pointer choose_res_255;
                if (id_254) {
                  choose_res_255 = ssum_dst_725;
                } else {
                  uint16_t id_256 { 5 };
                  bool id_257 { bool(id_256 == label1_724) };
                  Pointer choose_res_258;
                  if (id_257) {
                    choose_res_258 = ssum_dst_725;
                  } else {
                    uint16_t id_259 { 6 };
                    bool id_260 { bool(id_259 == label1_724) };
                    Pointer choose_res_261;
                    if (id_260) {
                      ::dessser::gen::sync_key::t35f466ab2ffe47e08d3d46d20f2eb1a6 id_262 { std::get<6 /* PerInstance */>((*p_0)) };
                      std::string id_263 { std::get<0>(id_262) };
                      uint32_t id_264 { (uint32_t)id_263.size() };
                      Vec<1, uint32_t> id_265 {  id_264  };
                      Pointer let_res_266;
                      {
                        Vec<1, uint32_t> leb128_sz_726 { id_265 };
                        Vec<1, Pointer> id_267 {  ssum_dst_725  };
                        Pointer let_res_268;
                        {
                          Vec<1, Pointer> leb128_ptr_727 { id_267 };
                          bool while_flag_269 { true };
                          do {
                            uint8_t id_270 { 0 };
                            uint8_t id_271 { 0 };
                            Pointer id_272 { leb128_ptr_727[id_271] };
                            uint32_t id_273 { 128U };
                            uint8_t id_274 { 0 };
                            uint32_t id_275 { leb128_sz_726[id_274] };
                            bool id_276 { bool(id_273 > id_275) };
                            uint8_t choose_res_277;
                            if (id_276) {
                              uint8_t id_278 { 0 };
                              uint32_t id_279 { leb128_sz_726[id_278] };
                              uint8_t id_280 { uint8_t(id_279) };
                              choose_res_277 = id_280;
                            } else {
                              uint8_t id_281 { 0 };
                              uint32_t id_282 { leb128_sz_726[id_281] };
                              uint8_t id_283 { uint8_t(id_282) };
                              uint8_t id_284 { 128 };
                              uint8_t id_285 { uint8_t(id_283 | id_284) };
                              choose_res_277 = id_285;
                            }
                            Pointer id_286 { id_272.writeU8(choose_res_277) };
                            Void id_287 { ((void)(leb128_ptr_727[id_270] = id_286), ::dessser::VOID) };
                            (void)id_287;
                            uint8_t id_288 { 0 };
                            uint8_t id_289 { 0 };
                            uint32_t id_290 { leb128_sz_726[id_289] };
                            uint8_t id_291 { 7 };
                            uint32_t id_292 { uint32_t(id_290 >> id_291) };
                            Void id_293 { ((void)(leb128_sz_726[id_288] = id_292), ::dessser::VOID) };
                            (void)id_293;
                            uint8_t id_294 { 0 };
                            uint32_t id_295 { leb128_sz_726[id_294] };
                            uint32_t id_296 { 0U };
                            bool id_297 { bool(id_295 > id_296) };
                            while_flag_269 = id_297;
                            if (while_flag_269) {
                              (void)::dessser::VOID;
                            }
                          } while (while_flag_269);
                          (void)::dessser::VOID;
                          uint8_t id_298 { 0 };
                          Pointer id_299 { leb128_ptr_727[id_298] };
                          let_res_268 = id_299;
                        }
                        let_res_266 = let_res_268;
                      }
                      ::dessser::gen::sync_key::t35f466ab2ffe47e08d3d46d20f2eb1a6 id_300 { std::get<6 /* PerInstance */>((*p_0)) };
                      std::string id_301 { std::get<0>(id_300) };
                      Bytes id_302 { id_301 };
                      Pointer id_303 { let_res_266.writeBytes(id_302) };
                      Pointer let_res_304;
                      {
                        Pointer stup_dst_728 { id_303 };
                        ::dessser::gen::sync_key::t35f466ab2ffe47e08d3d46d20f2eb1a6 id_305 { std::get<6 /* PerInstance */>((*p_0)) };
                        ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_306 { std::get<1>(id_305) };
                        uint16_t id_307 { uint16_t(id_306.index()) };
                        Pointer let_res_308;
                        {
                          uint16_t label1_729 { id_307 };
                          Pointer id_309 { stup_dst_728.writeU16Le(label1_729) };
                          Pointer let_res_310;
                          {
                            Pointer ssum_dst_730 { id_309 };
                            uint16_t id_311 { 0 };
                            bool id_312 { bool(id_311 == label1_729) };
                            Pointer choose_res_313;
                            if (id_312) {
                              choose_res_313 = ssum_dst_730;
                            } else {
                              uint16_t id_314 { 1 };
                              bool id_315 { bool(id_314 == label1_729) };
                              Pointer choose_res_316;
                              if (id_315) {
                                choose_res_316 = ssum_dst_730;
                              } else {
                                uint16_t id_317 { 2 };
                                bool id_318 { bool(id_317 == label1_729) };
                                Pointer choose_res_319;
                                if (id_318) {
                                  choose_res_319 = ssum_dst_730;
                                } else {
                                  uint16_t id_320 { 3 };
                                  bool id_321 { bool(id_320 == label1_729) };
                                  Pointer choose_res_322;
                                  if (id_321) {
                                    choose_res_322 = ssum_dst_730;
                                  } else {
                                    uint16_t id_323 { 4 };
                                    bool id_324 { bool(id_323 == label1_729) };
                                    Pointer choose_res_325;
                                    if (id_324) {
                                      choose_res_325 = ssum_dst_730;
                                    } else {
                                      uint16_t id_326 { 5 };
                                      bool id_327 { bool(id_326 == label1_729) };
                                      Pointer choose_res_328;
                                      if (id_327) {
                                        choose_res_328 = ssum_dst_730;
                                      } else {
                                        uint16_t id_329 { 6 };
                                        bool id_330 { bool(id_329 == label1_729) };
                                        Pointer choose_res_331;
                                        if (id_330) {
                                          choose_res_331 = ssum_dst_730;
                                        } else {
                                          uint16_t id_332 { 7 };
                                          bool id_333 { bool(label1_729 == id_332) };
                                          Void id_334 { ((void)(assert(id_333)), ::dessser::VOID) };
                                          (void)id_334;
                                          choose_res_331 = ssum_dst_730;
                                        }
                                        choose_res_328 = choose_res_331;
                                      }
                                      choose_res_325 = choose_res_328;
                                    }
                                    choose_res_322 = choose_res_325;
                                  }
                                  choose_res_319 = choose_res_322;
                                }
                                choose_res_316 = choose_res_319;
                              }
                              choose_res_313 = choose_res_316;
                            }
                            let_res_310 = choose_res_313;
                          }
                          let_res_308 = let_res_310;
                        }
                        let_res_304 = let_res_308;
                      }
                      choose_res_261 = let_res_304;
                    } else {
                      uint16_t id_335 { 7 };
                      bool id_336 { bool(id_335 == label1_724) };
                      Pointer choose_res_337;
                      if (id_336) {
                        uint32_t id_338 { std::get<7 /* PerReplayer */>((*p_0)) };
                        Pointer id_339 { ssum_dst_725.writeU32Le(id_338) };
                        choose_res_337 = id_339;
                      } else {
                        uint16_t id_340 { 8 };
                        bool id_341 { bool(label1_724 == id_340) };
                        Void id_342 { ((void)(assert(id_341)), ::dessser::VOID) };
                        (void)id_342;
                        choose_res_337 = ssum_dst_725;
                      }
                      choose_res_261 = choose_res_337;
                    }
                    choose_res_258 = choose_res_261;
                  }
                  choose_res_255 = choose_res_258;
                }
                choose_res_252 = choose_res_255;
              }
              choose_res_249 = choose_res_252;
            }
            choose_res_246 = choose_res_249;
          }
          choose_res_243 = choose_res_246;
        }
        let_res_240 = choose_res_243;
      }
      let_res_238 = let_res_240;
    }
    return let_res_238;
  }
   };
  return fun236;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> ,Pointer)> per_worker_data_to_row_binary(per_worker_data_to_row_binary_init());

/* 
    (fun ("($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))" "Ptr")
      (let "stup_dst_731" (apply (ext-identifier fq_name to-row-binary) (get-item 0 (param 0)) (param 1)) (apply (identifier "per_worker_data-to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_731"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker> ,Pointer)> per_worker_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker> ,Pointer)> fun343 { [&fun343](std::shared_ptr<::dessser::gen::sync_key::per_worker>  p_0, Pointer p_1) {
    auto fun344 { dessser::gen::fq_name::to_row_binary };
    dessser::gen::fq_name::t_ext id_345 { std::get<0>((*p_0)) };
    Pointer id_346 { fun344(id_345, p_1) };
    Pointer let_res_347;
    {
      Pointer stup_dst_731 { id_346 };
      std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_348 { std::get<1>((*p_0)) };
      Pointer id_349 { per_worker_data_to_row_binary(id_348, stup_dst_731) };
      let_res_347 = id_349;
    }
    return let_res_347;
  }
   };
  return fun343;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_worker> ,Pointer)> per_worker_to_row_binary(per_worker_to_row_binary_init());

/* 
    (fun ("[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" "Ptr")
      (let "ssum_dst_733" (write-u16 little-endian (param 1) (label-of (param 0)))
        (if (eq (u16 0) (label-of (param 0))) (identifier "ssum_dst_733")
          (if (eq (u16 1) (label-of (param 0)))
            (let "stup_dst_741"
              (write-bytes
                (let "leb128_sz_739" (make-vec (string-length (get-item 0 (get-alt "PerService" (param 0)))))
                  (let "leb128_ptr_740" (make-vec (identifier "ssum_dst_733"))
                    (seq
                      (while
                        (seq
                          (set-vec (u8 0) (identifier "leb128_ptr_740")
                            (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_740"))
                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_739"))) 
                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_739"))) 
                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_739"))) (u8 128))))) 
                          (set-vec (u8 0) (identifier "leb128_sz_739") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_739")) (u8 7))) 
                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_739")) (u32 0))) 
                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_740"))))) 
                (bytes-of-string (get-item 0 (get-alt "PerService" (param 0)))))
              (let "ssum_dst_743" (write-u16 little-endian (identifier "stup_dst_741") (label-of (get-item 1 (get-alt "PerService" (param 0)))))
                (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (param 0))))) 
                  (identifier "ssum_dst_743") (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (param 0)))) (u16 1))) (identifier "ssum_dst_743")))))
            (if (eq (u16 2) (label-of (param 0))) (apply (identifier "per_worker-to-row-binary") (get-alt "PerWorker" (param 0)) (identifier "ssum_dst_733"))
              (seq (assert (eq (label-of (param 0)) (u16 3)))
                (let "stup_dst_736"
                  (write-bytes
                    (let "leb128_sz_734" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (param 0)))))
                      (let "leb128_ptr_735" (make-vec (identifier "ssum_dst_733"))
                        (seq
                          (while
                            (seq
                              (set-vec (u8 0) (identifier "leb128_ptr_735")
                                (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_735"))
                                  (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_734"))) 
                                    (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_734"))) 
                                    (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_734"))) (u8 128))))) 
                              (set-vec (u8 0) (identifier "leb128_sz_734") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_734")) (u8 7))) 
                              (gt (unsafe-nth (u8 0) (identifier "leb128_sz_734")) (u32 0))) 
                            (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_735"))))) 
                    (bytes-of-string (get-item 0 (get-alt "PerProgram" (param 0)))))
                  (let "ssum_dst_738" (write-u16 little-endian (identifier "stup_dst_736") (label-of (get-item 1 (get-alt "PerProgram" (param 0)))))
                    (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (param 0)))) (u16 0))) (identifier "ssum_dst_738"))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,Pointer)> per_site_data_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,Pointer)> fun350 { [&fun350](std::shared_ptr<::dessser::gen::sync_key::per_site_data>  p_0, Pointer p_1) {
    uint16_t id_351 { uint16_t((*p_0).index()) };
    Pointer id_352 { p_1.writeU16Le(id_351) };
    Pointer let_res_353;
    {
      Pointer ssum_dst_733 { id_352 };
      uint16_t id_354 { 0 };
      uint16_t id_355 { uint16_t((*p_0).index()) };
      bool id_356 { bool(id_354 == id_355) };
      Pointer choose_res_357;
      if (id_356) {
        choose_res_357 = ssum_dst_733;
      } else {
        uint16_t id_358 { 1 };
        uint16_t id_359 { uint16_t((*p_0).index()) };
        bool id_360 { bool(id_358 == id_359) };
        Pointer choose_res_361;
        if (id_360) {
          ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773 id_362 { std::get<1 /* PerService */>((*p_0)) };
          std::string id_363 { std::get<0>(id_362) };
          uint32_t id_364 { (uint32_t)id_363.size() };
          Vec<1, uint32_t> id_365 {  id_364  };
          Pointer let_res_366;
          {
            Vec<1, uint32_t> leb128_sz_739 { id_365 };
            Vec<1, Pointer> id_367 {  ssum_dst_733  };
            Pointer let_res_368;
            {
              Vec<1, Pointer> leb128_ptr_740 { id_367 };
              bool while_flag_369 { true };
              do {
                uint8_t id_370 { 0 };
                uint8_t id_371 { 0 };
                Pointer id_372 { leb128_ptr_740[id_371] };
                uint32_t id_373 { 128U };
                uint8_t id_374 { 0 };
                uint32_t id_375 { leb128_sz_739[id_374] };
                bool id_376 { bool(id_373 > id_375) };
                uint8_t choose_res_377;
                if (id_376) {
                  uint8_t id_378 { 0 };
                  uint32_t id_379 { leb128_sz_739[id_378] };
                  uint8_t id_380 { uint8_t(id_379) };
                  choose_res_377 = id_380;
                } else {
                  uint8_t id_381 { 0 };
                  uint32_t id_382 { leb128_sz_739[id_381] };
                  uint8_t id_383 { uint8_t(id_382) };
                  uint8_t id_384 { 128 };
                  uint8_t id_385 { uint8_t(id_383 | id_384) };
                  choose_res_377 = id_385;
                }
                Pointer id_386 { id_372.writeU8(choose_res_377) };
                Void id_387 { ((void)(leb128_ptr_740[id_370] = id_386), ::dessser::VOID) };
                (void)id_387;
                uint8_t id_388 { 0 };
                uint8_t id_389 { 0 };
                uint32_t id_390 { leb128_sz_739[id_389] };
                uint8_t id_391 { 7 };
                uint32_t id_392 { uint32_t(id_390 >> id_391) };
                Void id_393 { ((void)(leb128_sz_739[id_388] = id_392), ::dessser::VOID) };
                (void)id_393;
                uint8_t id_394 { 0 };
                uint32_t id_395 { leb128_sz_739[id_394] };
                uint32_t id_396 { 0U };
                bool id_397 { bool(id_395 > id_396) };
                while_flag_369 = id_397;
                if (while_flag_369) {
                  (void)::dessser::VOID;
                }
              } while (while_flag_369);
              (void)::dessser::VOID;
              uint8_t id_398 { 0 };
              Pointer id_399 { leb128_ptr_740[id_398] };
              let_res_368 = id_399;
            }
            let_res_366 = let_res_368;
          }
          ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773 id_400 { std::get<1 /* PerService */>((*p_0)) };
          std::string id_401 { std::get<0>(id_400) };
          Bytes id_402 { id_401 };
          Pointer id_403 { let_res_366.writeBytes(id_402) };
          Pointer let_res_404;
          {
            Pointer stup_dst_741 { id_403 };
            ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773 id_405 { std::get<1 /* PerService */>((*p_0)) };
            ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_406 { std::get<1>(id_405) };
            uint16_t id_407 { uint16_t(id_406.index()) };
            Pointer id_408 { stup_dst_741.writeU16Le(id_407) };
            Pointer let_res_409;
            {
              Pointer ssum_dst_743 { id_408 };
              uint16_t id_410 { 0 };
              ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773 id_411 { std::get<1 /* PerService */>((*p_0)) };
              ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_412 { std::get<1>(id_411) };
              uint16_t id_413 { uint16_t(id_412.index()) };
              bool id_414 { bool(id_410 == id_413) };
              Pointer choose_res_415;
              if (id_414) {
                choose_res_415 = ssum_dst_743;
              } else {
                ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773 id_416 { std::get<1 /* PerService */>((*p_0)) };
                ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_417 { std::get<1>(id_416) };
                uint16_t id_418 { uint16_t(id_417.index()) };
                uint16_t id_419 { 1 };
                bool id_420 { bool(id_418 == id_419) };
                Void id_421 { ((void)(assert(id_420)), ::dessser::VOID) };
                (void)id_421;
                choose_res_415 = ssum_dst_743;
              }
              let_res_409 = choose_res_415;
            }
            let_res_404 = let_res_409;
          }
          choose_res_361 = let_res_404;
        } else {
          uint16_t id_422 { 2 };
          uint16_t id_423 { uint16_t((*p_0).index()) };
          bool id_424 { bool(id_422 == id_423) };
          Pointer choose_res_425;
          if (id_424) {
            std::shared_ptr<::dessser::gen::sync_key::per_worker>  id_426 { std::get<2 /* PerWorker */>((*p_0)) };
            Pointer id_427 { per_worker_to_row_binary(id_426, ssum_dst_733) };
            choose_res_425 = id_427;
          } else {
            uint16_t id_428 { uint16_t((*p_0).index()) };
            uint16_t id_429 { 3 };
            bool id_430 { bool(id_428 == id_429) };
            Void id_431 { ((void)(assert(id_430)), ::dessser::VOID) };
            (void)id_431;
            ::dessser::gen::sync_key::t861fec96932eb3dcd604deb55a8fed37 id_432 { std::get<3 /* PerProgram */>((*p_0)) };
            std::string id_433 { std::get<0>(id_432) };
            uint32_t id_434 { (uint32_t)id_433.size() };
            Vec<1, uint32_t> id_435 {  id_434  };
            Pointer let_res_436;
            {
              Vec<1, uint32_t> leb128_sz_734 { id_435 };
              Vec<1, Pointer> id_437 {  ssum_dst_733  };
              Pointer let_res_438;
              {
                Vec<1, Pointer> leb128_ptr_735 { id_437 };
                bool while_flag_439 { true };
                do {
                  uint8_t id_440 { 0 };
                  uint8_t id_441 { 0 };
                  Pointer id_442 { leb128_ptr_735[id_441] };
                  uint32_t id_443 { 128U };
                  uint8_t id_444 { 0 };
                  uint32_t id_445 { leb128_sz_734[id_444] };
                  bool id_446 { bool(id_443 > id_445) };
                  uint8_t choose_res_447;
                  if (id_446) {
                    uint8_t id_448 { 0 };
                    uint32_t id_449 { leb128_sz_734[id_448] };
                    uint8_t id_450 { uint8_t(id_449) };
                    choose_res_447 = id_450;
                  } else {
                    uint8_t id_451 { 0 };
                    uint32_t id_452 { leb128_sz_734[id_451] };
                    uint8_t id_453 { uint8_t(id_452) };
                    uint8_t id_454 { 128 };
                    uint8_t id_455 { uint8_t(id_453 | id_454) };
                    choose_res_447 = id_455;
                  }
                  Pointer id_456 { id_442.writeU8(choose_res_447) };
                  Void id_457 { ((void)(leb128_ptr_735[id_440] = id_456), ::dessser::VOID) };
                  (void)id_457;
                  uint8_t id_458 { 0 };
                  uint8_t id_459 { 0 };
                  uint32_t id_460 { leb128_sz_734[id_459] };
                  uint8_t id_461 { 7 };
                  uint32_t id_462 { uint32_t(id_460 >> id_461) };
                  Void id_463 { ((void)(leb128_sz_734[id_458] = id_462), ::dessser::VOID) };
                  (void)id_463;
                  uint8_t id_464 { 0 };
                  uint32_t id_465 { leb128_sz_734[id_464] };
                  uint32_t id_466 { 0U };
                  bool id_467 { bool(id_465 > id_466) };
                  while_flag_439 = id_467;
                  if (while_flag_439) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_439);
                (void)::dessser::VOID;
                uint8_t id_468 { 0 };
                Pointer id_469 { leb128_ptr_735[id_468] };
                let_res_438 = id_469;
              }
              let_res_436 = let_res_438;
            }
            ::dessser::gen::sync_key::t861fec96932eb3dcd604deb55a8fed37 id_470 { std::get<3 /* PerProgram */>((*p_0)) };
            std::string id_471 { std::get<0>(id_470) };
            Bytes id_472 { id_471 };
            Pointer id_473 { let_res_436.writeBytes(id_472) };
            Pointer let_res_474;
            {
              Pointer stup_dst_736 { id_473 };
              ::dessser::gen::sync_key::t861fec96932eb3dcd604deb55a8fed37 id_475 { std::get<3 /* PerProgram */>((*p_0)) };
              ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51 id_476 { std::get<1>(id_475) };
              uint16_t id_477 { uint16_t(id_476.index()) };
              Pointer id_478 { stup_dst_736.writeU16Le(id_477) };
              Pointer let_res_479;
              {
                Pointer ssum_dst_738 { id_478 };
                ::dessser::gen::sync_key::t861fec96932eb3dcd604deb55a8fed37 id_480 { std::get<3 /* PerProgram */>((*p_0)) };
                ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51 id_481 { std::get<1>(id_480) };
                uint16_t id_482 { uint16_t(id_481.index()) };
                uint16_t id_483 { 0 };
                bool id_484 { bool(id_482 == id_483) };
                Void id_485 { ((void)(assert(id_484)), ::dessser::VOID) };
                (void)id_485;
                let_res_479 = ssum_dst_738;
              }
              let_res_474 = let_res_479;
            }
            choose_res_425 = let_res_474;
          }
          choose_res_361 = choose_res_425;
        }
        choose_res_357 = choose_res_361;
      }
      let_res_353 = choose_res_357;
    }
    return let_res_353;
  }
   };
  return fun350;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site_data> ,Pointer)> per_site_data_to_row_binary(per_site_data_to_row_binary_init());

/* 
    (fun ("($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))" "Ptr")
      (let "stup_dst_744" (apply (ext-identifier site_name to-row-binary) (get-item 0 (param 0)) (param 1)) (apply (identifier "per_site_data-to-row-binary") (get-item 1 (param 0)) (identifier "stup_dst_744"))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site> ,Pointer)> per_site_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site> ,Pointer)> fun486 { [&fun486](std::shared_ptr<::dessser::gen::sync_key::per_site>  p_0, Pointer p_1) {
    auto fun487 { dessser::gen::site_name::to_row_binary };
    dessser::gen::site_name::t_ext id_488 { std::get<0>((*p_0)) };
    Pointer id_489 { fun487(id_488, p_1) };
    Pointer let_res_490;
    {
      Pointer stup_dst_744 { id_489 };
      std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_491 { std::get<1>((*p_0)) };
      Pointer id_492 { per_site_data_to_row_binary(id_491, stup_dst_744) };
      let_res_490 = id_492;
    }
    return let_res_490;
  }
   };
  return fun486;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::per_site> ,Pointer)> per_site_to_row_binary(per_site_to_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" "Ptr")
      (let "label1_763" (label-of (param 0))
        (let "ssum_dst_764" (write-u16 little-endian (param 1) (identifier "label1_763"))
          (if (eq (u16 0) (identifier "label1_763")) (identifier "ssum_dst_764")
            (if (eq (u16 1) (identifier "label1_763")) (identifier "ssum_dst_764")
              (if (eq (u16 2) (identifier "label1_763"))
                (write-bytes
                  (let "leb128_sz_791" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "leb128_ptr_792" (make-vec (identifier "ssum_dst_764"))
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
                  (bytes-of-string (get-alt "Versions" (param 0))))
                (if (eq (u16 3) (identifier "label1_763"))
                  (let "stup_dst_788" (apply (ext-identifier src_path to-row-binary) (get-item 0 (get-alt "Sources" (param 0))) (identifier "ssum_dst_764"))
                    (write-bytes
                      (let "leb128_sz_789" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "leb128_ptr_790" (make-vec (identifier "stup_dst_788"))
                          (seq
                            (while
                              (seq
                                (set-vec (u8 0) (identifier "leb128_ptr_790")
                                  (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_790"))
                                    (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_789"))) 
                                      (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_789"))) 
                                      (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_789"))) (u8 128)))))
                                (set-vec (u8 0) (identifier "leb128_sz_789") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_789")) (u8 7))) 
                                (gt (unsafe-nth (u8 0) (identifier "leb128_sz_789")) (u32 0))) 
                              (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_790"))))) 
                      (bytes-of-string (get-item 1 (get-alt "Sources" (param 0))))))
                  (if (eq (u16 4) (identifier "label1_763")) (identifier "ssum_dst_764")
                    (if (eq (u16 5) (identifier "label1_763")) (apply (identifier "per_site-to-row-binary") (get-alt "PerSite" (param 0)) (identifier "ssum_dst_764"))
                      (if (eq (u16 6) (identifier "label1_763"))
                        (let "ssum_dst_785" (write-u16 little-endian (identifier "ssum_dst_764") (label-of (get-alt "Storage" (param 0))))
                          (if (eq (u16 0) (label-of (get-alt "Storage" (param 0)))) 
                            (identifier "ssum_dst_785")
                            (if (eq (u16 1) (label-of (get-alt "Storage" (param 0)))) 
                              (identifier "ssum_dst_785")
                              (seq (assert (eq (label-of (get-alt "Storage" (param 0))) (u16 2)))
                                (write-bytes
                                  (let "leb128_sz_786" (make-vec (string-length (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))
                                    (let "leb128_ptr_787" (make-vec (identifier "ssum_dst_785"))
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
                                  (bytes-of-string (get-alt "RetentionsOverride" (get-alt "Storage" (param 0)))))))))
                        (if (eq (u16 7) (identifier "label1_763"))
                          (let "stup_dst_783"
                            (let "stup_dst_780"
                              (let "stup_dst_779" (apply (ext-identifier site_name to-row-binary) (get-item 0 (get-alt "Tails" (param 0))) (identifier "ssum_dst_764"))
                                (apply (ext-identifier fq_name to-row-binary) (get-item 1 (get-alt "Tails" (param 0))) (identifier "stup_dst_779")))
                              (write-bytes
                                (let "leb128_sz_781" (make-vec (string-length (get-item 2 (get-alt "Tails" (param 0)))))
                                  (let "leb128_ptr_782" (make-vec (identifier "stup_dst_780"))
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
                                (bytes-of-string (get-item 2 (get-alt "Tails" (param 0)))))) 
                            (apply (identifier "per_tail-to-row-binary") (get-item 3 (get-alt "Tails" (param 0))) (identifier "stup_dst_783")))
                          (if (eq (u16 8) (identifier "label1_763")) 
                            (write-u16 little-endian (identifier "ssum_dst_764") (get-alt "Replays" (param 0)))
                            (if (eq (u16 9) (identifier "label1_763"))
                              (if (is-null (get-alt "Error" (param 0))) 
                                (write-u8 (identifier "ssum_dst_764") (u8 1)) 
                                (apply (ext-identifier sync_socket to-row-binary) (force (get-alt "Error" (param 0))) (write-u8 (identifier "ssum_dst_764") (u8 0))))
                              (if (eq (u16 10) (identifier "label1_763")) 
                                (identifier "ssum_dst_764")
                                (if (eq (u16 11) (identifier "label1_763"))
                                  (let "stup_dst_778" (apply (ext-identifier sync_socket to-row-binary) (get-item 0 (get-alt "PerClient" (param 0))) (identifier "ssum_dst_764"))
                                    (apply (identifier "per_client-to-row-binary") (get-item 1 (get-alt "PerClient" (param 0))) (identifier "stup_dst_778")))
                                  (if (eq (u16 12) (identifier "label1_763"))
                                    (let "stup_dst_777"
                                      (write-bytes
                                        (let "leb128_sz_775" (make-vec (string-length (get-item 0 (get-alt "Dashboards" (param 0)))))
                                          (let "leb128_ptr_776" (make-vec (identifier "ssum_dst_764"))
                                            (seq
                                              (while
                                                (seq
                                                  (set-vec (u8 0) (identifier "leb128_ptr_776")
                                                    (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_776"))
                                                      (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_775"))) 
                                                        (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_775"))) 
                                                        (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_775"))) (u8 128)))))
                                                  (set-vec (u8 0) (identifier "leb128_sz_775") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_775")) (u8 7))) 
                                                  (gt (unsafe-nth (u8 0) (identifier "leb128_sz_775")) (u32 0))) 
                                                (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_776"))))) 
                                        (bytes-of-string (get-item 0 (get-alt "Dashboards" (param 0))))) 
                                      (apply (identifier "per_dash_key-to-row-binary") (get-item 1 (get-alt "Dashboards" (param 0))) (identifier "stup_dst_777")))
                                    (if (eq (u16 13) (identifier "label1_763")) 
                                      (identifier "ssum_dst_764")
                                      (if (eq (u16 14) (identifier "label1_763"))
                                        (let "stup_dst_768" (apply (ext-identifier team_name to-row-binary) (get-item 0 (get-alt "Teams" (param 0))) (identifier "ssum_dst_764"))
                                          (let "ssum_dst_770" (write-u16 little-endian (identifier "stup_dst_768") (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                            (if (eq (u16 0) (label-of (get-item 1 (get-alt "Teams" (param 0)))))
                                              (write-bytes
                                                (let "leb128_sz_773" 
                                                  (make-vec (string-length (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                                  (let "leb128_ptr_774" 
                                                    (make-vec (identifier "ssum_dst_770"))
                                                    (seq
                                                      (while
                                                        (seq
                                                          (set-vec (u8 0) 
                                                            (identifier "leb128_ptr_774")
                                                            (write-u8 
                                                              (unsafe-nth (u8 0) (identifier "leb128_ptr_774"))
                                                              (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_773"))) 
                                                                (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_773"))) 
                                                                (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_773"))) (u8 128)))))
                                                          (set-vec (u8 0) (identifier "leb128_sz_773") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_773")) (u8 7)))
                                                          (gt (unsafe-nth (u8 0) (identifier "leb128_sz_773")) (u32 0))) 
                                                        (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_774"))))) 
                                                (bytes-of-string (get-alt "Contacts" (get-item 1 (get-alt "Teams" (param 0))))))
                                              (seq (assert (eq (label-of (get-item 1 (get-alt "Teams" (param 0)))) (u16 1)))
                                                (write-bytes
                                                  (let "leb128_sz_771" 
                                                    (make-vec (string-length (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))
                                                    (let "leb128_ptr_772" 
                                                      (make-vec (identifier "ssum_dst_770"))
                                                      (seq
                                                        (while
                                                          (seq
                                                            (set-vec 
                                                              (u8 0) 
                                                              (identifier "leb128_ptr_772")
                                                              (write-u8 
                                                                (unsafe-nth (u8 0) (identifier "leb128_ptr_772"))
                                                                (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_771"))) 
                                                                  (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_771"))) 
                                                                  (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_771"))) (u8 128)))))
                                                            (set-vec (u8 0) (identifier "leb128_sz_771") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_771")) (u8 7)))
                                                            (gt (unsafe-nth (u8 0) (identifier "leb128_sz_771")) (u32 0))) 
                                                          (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_772"))))) 
                                                  (bytes-of-string (get-alt "Inhibition" (get-item 1 (get-alt "Teams" (param 0))))))))))
                                        (seq (assert (eq (identifier "label1_763") (u16 15)))
                                          (let "stup_dst_767"
                                            (write-bytes
                                              (let "leb128_sz_765" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "leb128_ptr_766" 
                                                  (make-vec (identifier "ssum_dst_764"))
                                                  (seq
                                                    (while
                                                      (seq
                                                        (set-vec (u8 0) 
                                                          (identifier "leb128_ptr_766")
                                                          (write-u8 (unsafe-nth (u8 0) (identifier "leb128_ptr_766"))
                                                            (if (gt (u32 128) (unsafe-nth (u8 0) (identifier "leb128_sz_765"))) 
                                                              (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_765"))) 
                                                              (bit-or (to-u8 (unsafe-nth (u8 0) (identifier "leb128_sz_765"))) (u8 128)))))
                                                        (set-vec (u8 0) (identifier "leb128_sz_765") (right-shift (unsafe-nth (u8 0) (identifier "leb128_sz_765")) (u8 7)))
                                                        (gt (unsafe-nth (u8 0) (identifier "leb128_sz_765")) (u32 0))) 
                                                      (nop)) (unsafe-nth (u8 0) (identifier "leb128_ptr_766"))))) 
                                              (bytes-of-string (get-item 0 (get-alt "Incidents" (param 0)))))
                                            (apply (identifier "incident_key-to-row-binary") (get-item 1 (get-alt "Incidents" (param 0))) (identifier "stup_dst_767"))))))))))))))))))))))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> fun493 { [&fun493](std::shared_ptr<::dessser::gen::sync_key::t>  p_0, Pointer p_1) {
    uint16_t id_494 { uint16_t((*p_0).index()) };
    Pointer let_res_495;
    {
      uint16_t label1_763 { id_494 };
      Pointer id_496 { p_1.writeU16Le(label1_763) };
      Pointer let_res_497;
      {
        Pointer ssum_dst_764 { id_496 };
        uint16_t id_498 { 0 };
        bool id_499 { bool(id_498 == label1_763) };
        Pointer choose_res_500;
        if (id_499) {
          choose_res_500 = ssum_dst_764;
        } else {
          uint16_t id_501 { 1 };
          bool id_502 { bool(id_501 == label1_763) };
          Pointer choose_res_503;
          if (id_502) {
            choose_res_503 = ssum_dst_764;
          } else {
            uint16_t id_504 { 2 };
            bool id_505 { bool(id_504 == label1_763) };
            Pointer choose_res_506;
            if (id_505) {
              std::string id_507 { std::get<2 /* Versions */>((*p_0)) };
              uint32_t id_508 { (uint32_t)id_507.size() };
              Vec<1, uint32_t> id_509 {  id_508  };
              Pointer let_res_510;
              {
                Vec<1, uint32_t> leb128_sz_791 { id_509 };
                Vec<1, Pointer> id_511 {  ssum_dst_764  };
                Pointer let_res_512;
                {
                  Vec<1, Pointer> leb128_ptr_792 { id_511 };
                  bool while_flag_513 { true };
                  do {
                    uint8_t id_514 { 0 };
                    uint8_t id_515 { 0 };
                    Pointer id_516 { leb128_ptr_792[id_515] };
                    uint32_t id_517 { 128U };
                    uint8_t id_518 { 0 };
                    uint32_t id_519 { leb128_sz_791[id_518] };
                    bool id_520 { bool(id_517 > id_519) };
                    uint8_t choose_res_521;
                    if (id_520) {
                      uint8_t id_522 { 0 };
                      uint32_t id_523 { leb128_sz_791[id_522] };
                      uint8_t id_524 { uint8_t(id_523) };
                      choose_res_521 = id_524;
                    } else {
                      uint8_t id_525 { 0 };
                      uint32_t id_526 { leb128_sz_791[id_525] };
                      uint8_t id_527 { uint8_t(id_526) };
                      uint8_t id_528 { 128 };
                      uint8_t id_529 { uint8_t(id_527 | id_528) };
                      choose_res_521 = id_529;
                    }
                    Pointer id_530 { id_516.writeU8(choose_res_521) };
                    Void id_531 { ((void)(leb128_ptr_792[id_514] = id_530), ::dessser::VOID) };
                    (void)id_531;
                    uint8_t id_532 { 0 };
                    uint8_t id_533 { 0 };
                    uint32_t id_534 { leb128_sz_791[id_533] };
                    uint8_t id_535 { 7 };
                    uint32_t id_536 { uint32_t(id_534 >> id_535) };
                    Void id_537 { ((void)(leb128_sz_791[id_532] = id_536), ::dessser::VOID) };
                    (void)id_537;
                    uint8_t id_538 { 0 };
                    uint32_t id_539 { leb128_sz_791[id_538] };
                    uint32_t id_540 { 0U };
                    bool id_541 { bool(id_539 > id_540) };
                    while_flag_513 = id_541;
                    if (while_flag_513) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_513);
                  (void)::dessser::VOID;
                  uint8_t id_542 { 0 };
                  Pointer id_543 { leb128_ptr_792[id_542] };
                  let_res_512 = id_543;
                }
                let_res_510 = let_res_512;
              }
              std::string id_544 { std::get<2 /* Versions */>((*p_0)) };
              Bytes id_545 { id_544 };
              Pointer id_546 { let_res_510.writeBytes(id_545) };
              choose_res_506 = id_546;
            } else {
              uint16_t id_547 { 3 };
              bool id_548 { bool(id_547 == label1_763) };
              Pointer choose_res_549;
              if (id_548) {
                auto fun550 { dessser::gen::src_path::to_row_binary };
                ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_551 { std::get<3 /* Sources */>((*p_0)) };
                dessser::gen::src_path::t_ext id_552 { std::get<0>(id_551) };
                Pointer id_553 { fun550(id_552, ssum_dst_764) };
                Pointer let_res_554;
                {
                  Pointer stup_dst_788 { id_553 };
                  ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_555 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_556 { std::get<1>(id_555) };
                  uint32_t id_557 { (uint32_t)id_556.size() };
                  Vec<1, uint32_t> id_558 {  id_557  };
                  Pointer let_res_559;
                  {
                    Vec<1, uint32_t> leb128_sz_789 { id_558 };
                    Vec<1, Pointer> id_560 {  stup_dst_788  };
                    Pointer let_res_561;
                    {
                      Vec<1, Pointer> leb128_ptr_790 { id_560 };
                      bool while_flag_562 { true };
                      do {
                        uint8_t id_563 { 0 };
                        uint8_t id_564 { 0 };
                        Pointer id_565 { leb128_ptr_790[id_564] };
                        uint32_t id_566 { 128U };
                        uint8_t id_567 { 0 };
                        uint32_t id_568 { leb128_sz_789[id_567] };
                        bool id_569 { bool(id_566 > id_568) };
                        uint8_t choose_res_570;
                        if (id_569) {
                          uint8_t id_571 { 0 };
                          uint32_t id_572 { leb128_sz_789[id_571] };
                          uint8_t id_573 { uint8_t(id_572) };
                          choose_res_570 = id_573;
                        } else {
                          uint8_t id_574 { 0 };
                          uint32_t id_575 { leb128_sz_789[id_574] };
                          uint8_t id_576 { uint8_t(id_575) };
                          uint8_t id_577 { 128 };
                          uint8_t id_578 { uint8_t(id_576 | id_577) };
                          choose_res_570 = id_578;
                        }
                        Pointer id_579 { id_565.writeU8(choose_res_570) };
                        Void id_580 { ((void)(leb128_ptr_790[id_563] = id_579), ::dessser::VOID) };
                        (void)id_580;
                        uint8_t id_581 { 0 };
                        uint8_t id_582 { 0 };
                        uint32_t id_583 { leb128_sz_789[id_582] };
                        uint8_t id_584 { 7 };
                        uint32_t id_585 { uint32_t(id_583 >> id_584) };
                        Void id_586 { ((void)(leb128_sz_789[id_581] = id_585), ::dessser::VOID) };
                        (void)id_586;
                        uint8_t id_587 { 0 };
                        uint32_t id_588 { leb128_sz_789[id_587] };
                        uint32_t id_589 { 0U };
                        bool id_590 { bool(id_588 > id_589) };
                        while_flag_562 = id_590;
                        if (while_flag_562) {
                          (void)::dessser::VOID;
                        }
                      } while (while_flag_562);
                      (void)::dessser::VOID;
                      uint8_t id_591 { 0 };
                      Pointer id_592 { leb128_ptr_790[id_591] };
                      let_res_561 = id_592;
                    }
                    let_res_559 = let_res_561;
                  }
                  ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_593 { std::get<3 /* Sources */>((*p_0)) };
                  std::string id_594 { std::get<1>(id_593) };
                  Bytes id_595 { id_594 };
                  Pointer id_596 { let_res_559.writeBytes(id_595) };
                  let_res_554 = id_596;
                }
                choose_res_549 = let_res_554;
              } else {
                uint16_t id_597 { 4 };
                bool id_598 { bool(id_597 == label1_763) };
                Pointer choose_res_599;
                if (id_598) {
                  choose_res_599 = ssum_dst_764;
                } else {
                  uint16_t id_600 { 5 };
                  bool id_601 { bool(id_600 == label1_763) };
                  Pointer choose_res_602;
                  if (id_601) {
                    std::shared_ptr<::dessser::gen::sync_key::per_site>  id_603 { std::get<5 /* PerSite */>((*p_0)) };
                    Pointer id_604 { per_site_to_row_binary(id_603, ssum_dst_764) };
                    choose_res_602 = id_604;
                  } else {
                    uint16_t id_605 { 6 };
                    bool id_606 { bool(id_605 == label1_763) };
                    Pointer choose_res_607;
                    if (id_606) {
                      ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_608 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_609 { uint16_t(id_608.index()) };
                      Pointer id_610 { ssum_dst_764.writeU16Le(id_609) };
                      Pointer let_res_611;
                      {
                        Pointer ssum_dst_785 { id_610 };
                        uint16_t id_612 { 0 };
                        ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_613 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_614 { uint16_t(id_613.index()) };
                        bool id_615 { bool(id_612 == id_614) };
                        Pointer choose_res_616;
                        if (id_615) {
                          choose_res_616 = ssum_dst_785;
                        } else {
                          uint16_t id_617 { 1 };
                          ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_618 { std::get<6 /* Storage */>((*p_0)) };
                          uint16_t id_619 { uint16_t(id_618.index()) };
                          bool id_620 { bool(id_617 == id_619) };
                          Pointer choose_res_621;
                          if (id_620) {
                            choose_res_621 = ssum_dst_785;
                          } else {
                            ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_622 { std::get<6 /* Storage */>((*p_0)) };
                            uint16_t id_623 { uint16_t(id_622.index()) };
                            uint16_t id_624 { 2 };
                            bool id_625 { bool(id_623 == id_624) };
                            Void id_626 { ((void)(assert(id_625)), ::dessser::VOID) };
                            (void)id_626;
                            ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_627 { std::get<6 /* Storage */>((*p_0)) };
                            std::string id_628 { std::get<2 /* RetentionsOverride */>(id_627) };
                            uint32_t id_629 { (uint32_t)id_628.size() };
                            Vec<1, uint32_t> id_630 {  id_629  };
                            Pointer let_res_631;
                            {
                              Vec<1, uint32_t> leb128_sz_786 { id_630 };
                              Vec<1, Pointer> id_632 {  ssum_dst_785  };
                              Pointer let_res_633;
                              {
                                Vec<1, Pointer> leb128_ptr_787 { id_632 };
                                bool while_flag_634 { true };
                                do {
                                  uint8_t id_635 { 0 };
                                  uint8_t id_636 { 0 };
                                  Pointer id_637 { leb128_ptr_787[id_636] };
                                  uint32_t id_638 { 128U };
                                  uint8_t id_639 { 0 };
                                  uint32_t id_640 { leb128_sz_786[id_639] };
                                  bool id_641 { bool(id_638 > id_640) };
                                  uint8_t choose_res_642;
                                  if (id_641) {
                                    uint8_t id_643 { 0 };
                                    uint32_t id_644 { leb128_sz_786[id_643] };
                                    uint8_t id_645 { uint8_t(id_644) };
                                    choose_res_642 = id_645;
                                  } else {
                                    uint8_t id_646 { 0 };
                                    uint32_t id_647 { leb128_sz_786[id_646] };
                                    uint8_t id_648 { uint8_t(id_647) };
                                    uint8_t id_649 { 128 };
                                    uint8_t id_650 { uint8_t(id_648 | id_649) };
                                    choose_res_642 = id_650;
                                  }
                                  Pointer id_651 { id_637.writeU8(choose_res_642) };
                                  Void id_652 { ((void)(leb128_ptr_787[id_635] = id_651), ::dessser::VOID) };
                                  (void)id_652;
                                  uint8_t id_653 { 0 };
                                  uint8_t id_654 { 0 };
                                  uint32_t id_655 { leb128_sz_786[id_654] };
                                  uint8_t id_656 { 7 };
                                  uint32_t id_657 { uint32_t(id_655 >> id_656) };
                                  Void id_658 { ((void)(leb128_sz_786[id_653] = id_657), ::dessser::VOID) };
                                  (void)id_658;
                                  uint8_t id_659 { 0 };
                                  uint32_t id_660 { leb128_sz_786[id_659] };
                                  uint32_t id_661 { 0U };
                                  bool id_662 { bool(id_660 > id_661) };
                                  while_flag_634 = id_662;
                                  if (while_flag_634) {
                                    (void)::dessser::VOID;
                                  }
                                } while (while_flag_634);
                                (void)::dessser::VOID;
                                uint8_t id_663 { 0 };
                                Pointer id_664 { leb128_ptr_787[id_663] };
                                let_res_633 = id_664;
                              }
                              let_res_631 = let_res_633;
                            }
                            ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_665 { std::get<6 /* Storage */>((*p_0)) };
                            std::string id_666 { std::get<2 /* RetentionsOverride */>(id_665) };
                            Bytes id_667 { id_666 };
                            Pointer id_668 { let_res_631.writeBytes(id_667) };
                            choose_res_621 = id_668;
                          }
                          choose_res_616 = choose_res_621;
                        }
                        let_res_611 = choose_res_616;
                      }
                      choose_res_607 = let_res_611;
                    } else {
                      uint16_t id_669 { 7 };
                      bool id_670 { bool(id_669 == label1_763) };
                      Pointer choose_res_671;
                      if (id_670) {
                        auto fun672 { dessser::gen::site_name::to_row_binary };
                        ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_673 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::site_name::t_ext id_674 { std::get<0>(id_673) };
                        Pointer id_675 { fun672(id_674, ssum_dst_764) };
                        Pointer let_res_676;
                        {
                          Pointer stup_dst_779 { id_675 };
                          auto fun677 { dessser::gen::fq_name::to_row_binary };
                          ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_678 { std::get<7 /* Tails */>((*p_0)) };
                          dessser::gen::fq_name::t_ext id_679 { std::get<1>(id_678) };
                          Pointer id_680 { fun677(id_679, stup_dst_779) };
                          let_res_676 = id_680;
                        }
                        Pointer let_res_681;
                        {
                          Pointer stup_dst_780 { let_res_676 };
                          ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_682 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_683 { std::get<2>(id_682) };
                          uint32_t id_684 { (uint32_t)id_683.size() };
                          Vec<1, uint32_t> id_685 {  id_684  };
                          Pointer let_res_686;
                          {
                            Vec<1, uint32_t> leb128_sz_781 { id_685 };
                            Vec<1, Pointer> id_687 {  stup_dst_780  };
                            Pointer let_res_688;
                            {
                              Vec<1, Pointer> leb128_ptr_782 { id_687 };
                              bool while_flag_689 { true };
                              do {
                                uint8_t id_690 { 0 };
                                uint8_t id_691 { 0 };
                                Pointer id_692 { leb128_ptr_782[id_691] };
                                uint32_t id_693 { 128U };
                                uint8_t id_694 { 0 };
                                uint32_t id_695 { leb128_sz_781[id_694] };
                                bool id_696 { bool(id_693 > id_695) };
                                uint8_t choose_res_697;
                                if (id_696) {
                                  uint8_t id_698 { 0 };
                                  uint32_t id_699 { leb128_sz_781[id_698] };
                                  uint8_t id_700 { uint8_t(id_699) };
                                  choose_res_697 = id_700;
                                } else {
                                  uint8_t id_701 { 0 };
                                  uint32_t id_702 { leb128_sz_781[id_701] };
                                  uint8_t id_703 { uint8_t(id_702) };
                                  uint8_t id_704 { 128 };
                                  uint8_t id_705 { uint8_t(id_703 | id_704) };
                                  choose_res_697 = id_705;
                                }
                                Pointer id_706 { id_692.writeU8(choose_res_697) };
                                Void id_707 { ((void)(leb128_ptr_782[id_690] = id_706), ::dessser::VOID) };
                                (void)id_707;
                                uint8_t id_708 { 0 };
                                uint8_t id_709 { 0 };
                                uint32_t id_710 { leb128_sz_781[id_709] };
                                uint8_t id_711 { 7 };
                                uint32_t id_712 { uint32_t(id_710 >> id_711) };
                                Void id_713 { ((void)(leb128_sz_781[id_708] = id_712), ::dessser::VOID) };
                                (void)id_713;
                                uint8_t id_714 { 0 };
                                uint32_t id_715 { leb128_sz_781[id_714] };
                                uint32_t id_716 { 0U };
                                bool id_717 { bool(id_715 > id_716) };
                                while_flag_689 = id_717;
                                if (while_flag_689) {
                                  (void)::dessser::VOID;
                                }
                              } while (while_flag_689);
                              (void)::dessser::VOID;
                              uint8_t id_718 { 0 };
                              Pointer id_719 { leb128_ptr_782[id_718] };
                              let_res_688 = id_719;
                            }
                            let_res_686 = let_res_688;
                          }
                          ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_720 { std::get<7 /* Tails */>((*p_0)) };
                          std::string id_721 { std::get<2>(id_720) };
                          Bytes id_722 { id_721 };
                          Pointer id_723 { let_res_686.writeBytes(id_722) };
                          let_res_681 = id_723;
                        }
                        Pointer let_res_724;
                        {
                          Pointer stup_dst_783 { let_res_681 };
                          ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_725 { std::get<7 /* Tails */>((*p_0)) };
                          std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_726 { std::get<3>(id_725) };
                          Pointer id_727 { per_tail_to_row_binary(id_726, stup_dst_783) };
                          let_res_724 = id_727;
                        }
                        choose_res_671 = let_res_724;
                      } else {
                        uint16_t id_728 { 8 };
                        bool id_729 { bool(id_728 == label1_763) };
                        Pointer choose_res_730;
                        if (id_729) {
                          uint16_t id_731 { std::get<8 /* Replays */>((*p_0)) };
                          Pointer id_732 { ssum_dst_764.writeU16Le(id_731) };
                          choose_res_730 = id_732;
                        } else {
                          uint16_t id_733 { 9 };
                          bool id_734 { bool(id_733 == label1_763) };
                          Pointer choose_res_735;
                          if (id_734) {
                            std::optional<dessser::gen::sync_socket::t_ext> id_736 { std::get<9 /* Error */>((*p_0)) };
                            bool id_737 { !(id_736.has_value ()) };
                            Pointer choose_res_738;
                            if (id_737) {
                              uint8_t id_739 { 1 };
                              Pointer id_740 { ssum_dst_764.writeU8(id_739) };
                              choose_res_738 = id_740;
                            } else {
                              auto fun741 { dessser::gen::sync_socket::to_row_binary };
                              std::optional<dessser::gen::sync_socket::t_ext> id_742 { std::get<9 /* Error */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_743 { id_742.value() };
                              uint8_t id_744 { 0 };
                              Pointer id_745 { ssum_dst_764.writeU8(id_744) };
                              Pointer id_746 { fun741(id_743, id_745) };
                              choose_res_738 = id_746;
                            }
                            choose_res_735 = choose_res_738;
                          } else {
                            uint16_t id_747 { 10 };
                            bool id_748 { bool(id_747 == label1_763) };
                            Pointer choose_res_749;
                            if (id_748) {
                              choose_res_749 = ssum_dst_764;
                            } else {
                              uint16_t id_750 { 11 };
                              bool id_751 { bool(id_750 == label1_763) };
                              Pointer choose_res_752;
                              if (id_751) {
                                auto fun753 { dessser::gen::sync_socket::to_row_binary };
                                ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c id_754 { std::get<11 /* PerClient */>((*p_0)) };
                                dessser::gen::sync_socket::t_ext id_755 { std::get<0>(id_754) };
                                Pointer id_756 { fun753(id_755, ssum_dst_764) };
                                Pointer let_res_757;
                                {
                                  Pointer stup_dst_778 { id_756 };
                                  ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c id_758 { std::get<11 /* PerClient */>((*p_0)) };
                                  std::shared_ptr<::dessser::gen::sync_key::per_client>  id_759 { std::get<1>(id_758) };
                                  Pointer id_760 { per_client_to_row_binary(id_759, stup_dst_778) };
                                  let_res_757 = id_760;
                                }
                                choose_res_752 = let_res_757;
                              } else {
                                uint16_t id_761 { 12 };
                                bool id_762 { bool(id_761 == label1_763) };
                                Pointer choose_res_763;
                                if (id_762) {
                                  ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_764 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_765 { std::get<0>(id_764) };
                                  uint32_t id_766 { (uint32_t)id_765.size() };
                                  Vec<1, uint32_t> id_767 {  id_766  };
                                  Pointer let_res_768;
                                  {
                                    Vec<1, uint32_t> leb128_sz_775 { id_767 };
                                    Vec<1, Pointer> id_769 {  ssum_dst_764  };
                                    Pointer let_res_770;
                                    {
                                      Vec<1, Pointer> leb128_ptr_776 { id_769 };
                                      bool while_flag_771 { true };
                                      do {
                                        uint8_t id_772 { 0 };
                                        uint8_t id_773 { 0 };
                                        Pointer id_774 { leb128_ptr_776[id_773] };
                                        uint32_t id_775 { 128U };
                                        uint8_t id_776 { 0 };
                                        uint32_t id_777 { leb128_sz_775[id_776] };
                                        bool id_778 { bool(id_775 > id_777) };
                                        uint8_t choose_res_779;
                                        if (id_778) {
                                          uint8_t id_780 { 0 };
                                          uint32_t id_781 { leb128_sz_775[id_780] };
                                          uint8_t id_782 { uint8_t(id_781) };
                                          choose_res_779 = id_782;
                                        } else {
                                          uint8_t id_783 { 0 };
                                          uint32_t id_784 { leb128_sz_775[id_783] };
                                          uint8_t id_785 { uint8_t(id_784) };
                                          uint8_t id_786 { 128 };
                                          uint8_t id_787 { uint8_t(id_785 | id_786) };
                                          choose_res_779 = id_787;
                                        }
                                        Pointer id_788 { id_774.writeU8(choose_res_779) };
                                        Void id_789 { ((void)(leb128_ptr_776[id_772] = id_788), ::dessser::VOID) };
                                        (void)id_789;
                                        uint8_t id_790 { 0 };
                                        uint8_t id_791 { 0 };
                                        uint32_t id_792 { leb128_sz_775[id_791] };
                                        uint8_t id_793 { 7 };
                                        uint32_t id_794 { uint32_t(id_792 >> id_793) };
                                        Void id_795 { ((void)(leb128_sz_775[id_790] = id_794), ::dessser::VOID) };
                                        (void)id_795;
                                        uint8_t id_796 { 0 };
                                        uint32_t id_797 { leb128_sz_775[id_796] };
                                        uint32_t id_798 { 0U };
                                        bool id_799 { bool(id_797 > id_798) };
                                        while_flag_771 = id_799;
                                        if (while_flag_771) {
                                          (void)::dessser::VOID;
                                        }
                                      } while (while_flag_771);
                                      (void)::dessser::VOID;
                                      uint8_t id_800 { 0 };
                                      Pointer id_801 { leb128_ptr_776[id_800] };
                                      let_res_770 = id_801;
                                    }
                                    let_res_768 = let_res_770;
                                  }
                                  ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_802 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::string id_803 { std::get<0>(id_802) };
                                  Bytes id_804 { id_803 };
                                  Pointer id_805 { let_res_768.writeBytes(id_804) };
                                  Pointer let_res_806;
                                  {
                                    Pointer stup_dst_777 { id_805 };
                                    ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_807 { std::get<12 /* Dashboards */>((*p_0)) };
                                    std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_808 { std::get<1>(id_807) };
                                    Pointer id_809 { per_dash_key_to_row_binary(id_808, stup_dst_777) };
                                    let_res_806 = id_809;
                                  }
                                  choose_res_763 = let_res_806;
                                } else {
                                  uint16_t id_810 { 13 };
                                  bool id_811 { bool(id_810 == label1_763) };
                                  Pointer choose_res_812;
                                  if (id_811) {
                                    choose_res_812 = ssum_dst_764;
                                  } else {
                                    uint16_t id_813 { 14 };
                                    bool id_814 { bool(id_813 == label1_763) };
                                    Pointer choose_res_815;
                                    if (id_814) {
                                      auto fun816 { dessser::gen::team_name::to_row_binary };
                                      ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_817 { std::get<14 /* Teams */>((*p_0)) };
                                      dessser::gen::team_name::t_ext id_818 { std::get<0>(id_817) };
                                      Pointer id_819 { fun816(id_818, ssum_dst_764) };
                                      Pointer let_res_820;
                                      {
                                        Pointer stup_dst_768 { id_819 };
                                        ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_821 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_822 { std::get<1>(id_821) };
                                        uint16_t id_823 { uint16_t(id_822.index()) };
                                        Pointer id_824 { stup_dst_768.writeU16Le(id_823) };
                                        Pointer let_res_825;
                                        {
                                          Pointer ssum_dst_770 { id_824 };
                                          uint16_t id_826 { 0 };
                                          ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_827 { std::get<14 /* Teams */>((*p_0)) };
                                          ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_828 { std::get<1>(id_827) };
                                          uint16_t id_829 { uint16_t(id_828.index()) };
                                          bool id_830 { bool(id_826 == id_829) };
                                          Pointer choose_res_831;
                                          if (id_830) {
                                            ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_832 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_833 { std::get<1>(id_832) };
                                            std::string id_834 { std::get<0 /* Contacts */>(id_833) };
                                            uint32_t id_835 { (uint32_t)id_834.size() };
                                            Vec<1, uint32_t> id_836 {  id_835  };
                                            Pointer let_res_837;
                                            {
                                              Vec<1, uint32_t> leb128_sz_773 { id_836 };
                                              Vec<1, Pointer> id_838 {  ssum_dst_770  };
                                              Pointer let_res_839;
                                              {
                                                Vec<1, Pointer> leb128_ptr_774 { id_838 };
                                                bool while_flag_840 { true };
                                                do {
                                                  uint8_t id_841 { 0 };
                                                  uint8_t id_842 { 0 };
                                                  Pointer id_843 { leb128_ptr_774[id_842] };
                                                  uint32_t id_844 { 128U };
                                                  uint8_t id_845 { 0 };
                                                  uint32_t id_846 { leb128_sz_773[id_845] };
                                                  bool id_847 { bool(id_844 > id_846) };
                                                  uint8_t choose_res_848;
                                                  if (id_847) {
                                                    uint8_t id_849 { 0 };
                                                    uint32_t id_850 { leb128_sz_773[id_849] };
                                                    uint8_t id_851 { uint8_t(id_850) };
                                                    choose_res_848 = id_851;
                                                  } else {
                                                    uint8_t id_852 { 0 };
                                                    uint32_t id_853 { leb128_sz_773[id_852] };
                                                    uint8_t id_854 { uint8_t(id_853) };
                                                    uint8_t id_855 { 128 };
                                                    uint8_t id_856 { uint8_t(id_854 | id_855) };
                                                    choose_res_848 = id_856;
                                                  }
                                                  Pointer id_857 { id_843.writeU8(choose_res_848) };
                                                  Void id_858 { ((void)(leb128_ptr_774[id_841] = id_857), ::dessser::VOID) };
                                                  (void)id_858;
                                                  uint8_t id_859 { 0 };
                                                  uint8_t id_860 { 0 };
                                                  uint32_t id_861 { leb128_sz_773[id_860] };
                                                  uint8_t id_862 { 7 };
                                                  uint32_t id_863 { uint32_t(id_861 >> id_862) };
                                                  Void id_864 { ((void)(leb128_sz_773[id_859] = id_863), ::dessser::VOID) };
                                                  (void)id_864;
                                                  uint8_t id_865 { 0 };
                                                  uint32_t id_866 { leb128_sz_773[id_865] };
                                                  uint32_t id_867 { 0U };
                                                  bool id_868 { bool(id_866 > id_867) };
                                                  while_flag_840 = id_868;
                                                  if (while_flag_840) {
                                                    (void)::dessser::VOID;
                                                  }
                                                } while (while_flag_840);
                                                (void)::dessser::VOID;
                                                uint8_t id_869 { 0 };
                                                Pointer id_870 { leb128_ptr_774[id_869] };
                                                let_res_839 = id_870;
                                              }
                                              let_res_837 = let_res_839;
                                            }
                                            ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_871 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_872 { std::get<1>(id_871) };
                                            std::string id_873 { std::get<0 /* Contacts */>(id_872) };
                                            Bytes id_874 { id_873 };
                                            Pointer id_875 { let_res_837.writeBytes(id_874) };
                                            choose_res_831 = id_875;
                                          } else {
                                            ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_876 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_877 { std::get<1>(id_876) };
                                            uint16_t id_878 { uint16_t(id_877.index()) };
                                            uint16_t id_879 { 1 };
                                            bool id_880 { bool(id_878 == id_879) };
                                            Void id_881 { ((void)(assert(id_880)), ::dessser::VOID) };
                                            (void)id_881;
                                            ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_882 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_883 { std::get<1>(id_882) };
                                            std::string id_884 { std::get<1 /* Inhibition */>(id_883) };
                                            uint32_t id_885 { (uint32_t)id_884.size() };
                                            Vec<1, uint32_t> id_886 {  id_885  };
                                            Pointer let_res_887;
                                            {
                                              Vec<1, uint32_t> leb128_sz_771 { id_886 };
                                              Vec<1, Pointer> id_888 {  ssum_dst_770  };
                                              Pointer let_res_889;
                                              {
                                                Vec<1, Pointer> leb128_ptr_772 { id_888 };
                                                bool while_flag_890 { true };
                                                do {
                                                  uint8_t id_891 { 0 };
                                                  uint8_t id_892 { 0 };
                                                  Pointer id_893 { leb128_ptr_772[id_892] };
                                                  uint32_t id_894 { 128U };
                                                  uint8_t id_895 { 0 };
                                                  uint32_t id_896 { leb128_sz_771[id_895] };
                                                  bool id_897 { bool(id_894 > id_896) };
                                                  uint8_t choose_res_898;
                                                  if (id_897) {
                                                    uint8_t id_899 { 0 };
                                                    uint32_t id_900 { leb128_sz_771[id_899] };
                                                    uint8_t id_901 { uint8_t(id_900) };
                                                    choose_res_898 = id_901;
                                                  } else {
                                                    uint8_t id_902 { 0 };
                                                    uint32_t id_903 { leb128_sz_771[id_902] };
                                                    uint8_t id_904 { uint8_t(id_903) };
                                                    uint8_t id_905 { 128 };
                                                    uint8_t id_906 { uint8_t(id_904 | id_905) };
                                                    choose_res_898 = id_906;
                                                  }
                                                  Pointer id_907 { id_893.writeU8(choose_res_898) };
                                                  Void id_908 { ((void)(leb128_ptr_772[id_891] = id_907), ::dessser::VOID) };
                                                  (void)id_908;
                                                  uint8_t id_909 { 0 };
                                                  uint8_t id_910 { 0 };
                                                  uint32_t id_911 { leb128_sz_771[id_910] };
                                                  uint8_t id_912 { 7 };
                                                  uint32_t id_913 { uint32_t(id_911 >> id_912) };
                                                  Void id_914 { ((void)(leb128_sz_771[id_909] = id_913), ::dessser::VOID) };
                                                  (void)id_914;
                                                  uint8_t id_915 { 0 };
                                                  uint32_t id_916 { leb128_sz_771[id_915] };
                                                  uint32_t id_917 { 0U };
                                                  bool id_918 { bool(id_916 > id_917) };
                                                  while_flag_890 = id_918;
                                                  if (while_flag_890) {
                                                    (void)::dessser::VOID;
                                                  }
                                                } while (while_flag_890);
                                                (void)::dessser::VOID;
                                                uint8_t id_919 { 0 };
                                                Pointer id_920 { leb128_ptr_772[id_919] };
                                                let_res_889 = id_920;
                                              }
                                              let_res_887 = let_res_889;
                                            }
                                            ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_921 { std::get<14 /* Teams */>((*p_0)) };
                                            ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_922 { std::get<1>(id_921) };
                                            std::string id_923 { std::get<1 /* Inhibition */>(id_922) };
                                            Bytes id_924 { id_923 };
                                            Pointer id_925 { let_res_887.writeBytes(id_924) };
                                            choose_res_831 = id_925;
                                          }
                                          let_res_825 = choose_res_831;
                                        }
                                        let_res_820 = let_res_825;
                                      }
                                      choose_res_815 = let_res_820;
                                    } else {
                                      uint16_t id_926 { 15 };
                                      bool id_927 { bool(label1_763 == id_926) };
                                      Void id_928 { ((void)(assert(id_927)), ::dessser::VOID) };
                                      (void)id_928;
                                      ::dessser::gen::sync_key::tdce75d0a7767ecd39280979e2e5897b1 id_929 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_930 { std::get<0>(id_929) };
                                      uint32_t id_931 { (uint32_t)id_930.size() };
                                      Vec<1, uint32_t> id_932 {  id_931  };
                                      Pointer let_res_933;
                                      {
                                        Vec<1, uint32_t> leb128_sz_765 { id_932 };
                                        Vec<1, Pointer> id_934 {  ssum_dst_764  };
                                        Pointer let_res_935;
                                        {
                                          Vec<1, Pointer> leb128_ptr_766 { id_934 };
                                          bool while_flag_936 { true };
                                          do {
                                            uint8_t id_937 { 0 };
                                            uint8_t id_938 { 0 };
                                            Pointer id_939 { leb128_ptr_766[id_938] };
                                            uint32_t id_940 { 128U };
                                            uint8_t id_941 { 0 };
                                            uint32_t id_942 { leb128_sz_765[id_941] };
                                            bool id_943 { bool(id_940 > id_942) };
                                            uint8_t choose_res_944;
                                            if (id_943) {
                                              uint8_t id_945 { 0 };
                                              uint32_t id_946 { leb128_sz_765[id_945] };
                                              uint8_t id_947 { uint8_t(id_946) };
                                              choose_res_944 = id_947;
                                            } else {
                                              uint8_t id_948 { 0 };
                                              uint32_t id_949 { leb128_sz_765[id_948] };
                                              uint8_t id_950 { uint8_t(id_949) };
                                              uint8_t id_951 { 128 };
                                              uint8_t id_952 { uint8_t(id_950 | id_951) };
                                              choose_res_944 = id_952;
                                            }
                                            Pointer id_953 { id_939.writeU8(choose_res_944) };
                                            Void id_954 { ((void)(leb128_ptr_766[id_937] = id_953), ::dessser::VOID) };
                                            (void)id_954;
                                            uint8_t id_955 { 0 };
                                            uint8_t id_956 { 0 };
                                            uint32_t id_957 { leb128_sz_765[id_956] };
                                            uint8_t id_958 { 7 };
                                            uint32_t id_959 { uint32_t(id_957 >> id_958) };
                                            Void id_960 { ((void)(leb128_sz_765[id_955] = id_959), ::dessser::VOID) };
                                            (void)id_960;
                                            uint8_t id_961 { 0 };
                                            uint32_t id_962 { leb128_sz_765[id_961] };
                                            uint32_t id_963 { 0U };
                                            bool id_964 { bool(id_962 > id_963) };
                                            while_flag_936 = id_964;
                                            if (while_flag_936) {
                                              (void)::dessser::VOID;
                                            }
                                          } while (while_flag_936);
                                          (void)::dessser::VOID;
                                          uint8_t id_965 { 0 };
                                          Pointer id_966 { leb128_ptr_766[id_965] };
                                          let_res_935 = id_966;
                                        }
                                        let_res_933 = let_res_935;
                                      }
                                      ::dessser::gen::sync_key::tdce75d0a7767ecd39280979e2e5897b1 id_967 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::string id_968 { std::get<0>(id_967) };
                                      Bytes id_969 { id_968 };
                                      Pointer id_970 { let_res_933.writeBytes(id_969) };
                                      Pointer let_res_971;
                                      {
                                        Pointer stup_dst_767 { id_970 };
                                        ::dessser::gen::sync_key::tdce75d0a7767ecd39280979e2e5897b1 id_972 { std::get<15 /* Incidents */>((*p_0)) };
                                        std::shared_ptr<::dessser::gen::sync_key::incident_key>  id_973 { std::get<1>(id_972) };
                                        Pointer id_974 { incident_key_to_row_binary(id_973, stup_dst_767) };
                                        let_res_971 = id_974;
                                      }
                                      choose_res_815 = let_res_971;
                                    }
                                    choose_res_812 = choose_res_815;
                                  }
                                  choose_res_763 = choose_res_812;
                                }
                                choose_res_752 = choose_res_763;
                              }
                              choose_res_749 = choose_res_752;
                            }
                            choose_res_735 = choose_res_749;
                          }
                          choose_res_730 = choose_res_735;
                        }
                        choose_res_671 = choose_res_730;
                      }
                      choose_res_607 = choose_res_671;
                    }
                    choose_res_602 = choose_res_607;
                  }
                  choose_res_599 = choose_res_602;
                }
                choose_res_549 = choose_res_599;
              }
              choose_res_506 = choose_res_549;
            }
            choose_res_503 = choose_res_506;
          }
          choose_res_500 = choose_res_503;
        }
        let_res_497 = choose_res_500;
      }
      let_res_495 = let_res_497;
    }
    return let_res_495;
  }
   };
  return fun493;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> to_row_binary(to_row_binary_init());

/* 
    (fun ("[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0))) (size 2)
          (if (eq (u16 2) (label-of (param 0))) (size 2)
            (if (eq (u16 3) (label-of (param 0))) (size 2) (if (eq (u16 4) (label-of (param 0))) (size 2) (if (eq (u16 5) (label-of (param 0))) (size 2) (seq (assert (eq (label-of (param 0)) (u16 6))) (size 2)))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::dialog_key> )> dialog_key_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::dialog_key> )> fun975 { [&fun975](std::shared_ptr<::dessser::gen::sync_key::dialog_key>  p_0) {
    uint16_t id_976 { 0 };
    uint16_t id_977 { uint16_t((*p_0).index()) };
    bool id_978 { bool(id_976 == id_977) };
    Size choose_res_979;
    if (id_978) {
      Size id_980 { 2UL };
      choose_res_979 = id_980;
    } else {
      uint16_t id_981 { 1 };
      uint16_t id_982 { uint16_t((*p_0).index()) };
      bool id_983 { bool(id_981 == id_982) };
      Size choose_res_984;
      if (id_983) {
        Size id_985 { 2UL };
        choose_res_984 = id_985;
      } else {
        uint16_t id_986 { 2 };
        uint16_t id_987 { uint16_t((*p_0).index()) };
        bool id_988 { bool(id_986 == id_987) };
        Size choose_res_989;
        if (id_988) {
          Size id_990 { 2UL };
          choose_res_989 = id_990;
        } else {
          uint16_t id_991 { 3 };
          uint16_t id_992 { uint16_t((*p_0).index()) };
          bool id_993 { bool(id_991 == id_992) };
          Size choose_res_994;
          if (id_993) {
            Size id_995 { 2UL };
            choose_res_994 = id_995;
          } else {
            uint16_t id_996 { 4 };
            uint16_t id_997 { uint16_t((*p_0).index()) };
            bool id_998 { bool(id_996 == id_997) };
            Size choose_res_999;
            if (id_998) {
              Size id_1000 { 2UL };
              choose_res_999 = id_1000;
            } else {
              uint16_t id_1001 { 5 };
              uint16_t id_1002 { uint16_t((*p_0).index()) };
              bool id_1003 { bool(id_1001 == id_1002) };
              Size choose_res_1004;
              if (id_1003) {
                Size id_1005 { 2UL };
                choose_res_1004 = id_1005;
              } else {
                uint16_t id_1006 { uint16_t((*p_0).index()) };
                uint16_t id_1007 { 6 };
                bool id_1008 { bool(id_1006 == id_1007) };
                Void id_1009 { ((void)(assert(id_1008)), ::dessser::VOID) };
                (void)id_1009;
                Size id_1010 { 2UL };
                choose_res_1004 = id_1010;
              }
              choose_res_999 = choose_res_1004;
            }
            choose_res_994 = choose_res_999;
          }
          choose_res_989 = choose_res_994;
        }
        choose_res_984 = choose_res_989;
      }
      choose_res_979 = choose_res_984;
    }
    return choose_res_979;
  }
   };
  return fun975;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::dialog_key> )> dialog_key_sersize_of_row_binary(dialog_key_sersize_of_row_binary_init());

/* 
    (fun ("[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0))) (size 2)
          (if (eq (u16 2) (label-of (param 0))) (size 2)
            (if (eq (u16 3) (label-of (param 0))) (size 2)
              (if (eq (u16 4) (label-of (param 0))) (size 2)
                (if (eq (u16 5) (label-of (param 0)))
                  (let "sz_682"
                    (add (size 2)
                      (add
                        (let "n_ref_680" (make-vec (string-length (get-item 0 (get-alt "Dialogs" (param 0)))))
                          (let "lebsz_ref_681" (make-vec (u32 1))
                            (seq
                              (while (ge (unsafe-nth (u8 0) (identifier "n_ref_680")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_681")) (u8 7)))
                                (set-vec (u8 0) (identifier "lebsz_ref_681") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_681")) (u32 1)))) 
                              (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_681")))))) 
                        (size-of-u32 (string-length (get-item 0 (get-alt "Dialogs" (param 0))))))) 
                    (add (identifier "sz_682") (apply (identifier "dialog_key-sersize-of-row-binary") (get-item 1 (get-alt "Dialogs" (param 0)))))) 
                  (seq (assert (eq (label-of (param 0)) (u16 6))) (size 14)))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::incident_key> )> incident_key_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::incident_key> )> fun1011 { [&fun1011](std::shared_ptr<::dessser::gen::sync_key::incident_key>  p_0) {
    uint16_t id_1012 { 0 };
    uint16_t id_1013 { uint16_t((*p_0).index()) };
    bool id_1014 { bool(id_1012 == id_1013) };
    Size choose_res_1015;
    if (id_1014) {
      Size id_1016 { 2UL };
      choose_res_1015 = id_1016;
    } else {
      uint16_t id_1017 { 1 };
      uint16_t id_1018 { uint16_t((*p_0).index()) };
      bool id_1019 { bool(id_1017 == id_1018) };
      Size choose_res_1020;
      if (id_1019) {
        Size id_1021 { 2UL };
        choose_res_1020 = id_1021;
      } else {
        uint16_t id_1022 { 2 };
        uint16_t id_1023 { uint16_t((*p_0).index()) };
        bool id_1024 { bool(id_1022 == id_1023) };
        Size choose_res_1025;
        if (id_1024) {
          Size id_1026 { 2UL };
          choose_res_1025 = id_1026;
        } else {
          uint16_t id_1027 { 3 };
          uint16_t id_1028 { uint16_t((*p_0).index()) };
          bool id_1029 { bool(id_1027 == id_1028) };
          Size choose_res_1030;
          if (id_1029) {
            Size id_1031 { 2UL };
            choose_res_1030 = id_1031;
          } else {
            uint16_t id_1032 { 4 };
            uint16_t id_1033 { uint16_t((*p_0).index()) };
            bool id_1034 { bool(id_1032 == id_1033) };
            Size choose_res_1035;
            if (id_1034) {
              Size id_1036 { 2UL };
              choose_res_1035 = id_1036;
            } else {
              uint16_t id_1037 { 5 };
              uint16_t id_1038 { uint16_t((*p_0).index()) };
              bool id_1039 { bool(id_1037 == id_1038) };
              Size choose_res_1040;
              if (id_1039) {
                Size id_1041 { 2UL };
                ::dessser::gen::sync_key::t64c0474e57c610aaa3e07cb04692cefe id_1042 { std::get<5 /* Dialogs */>((*p_0)) };
                std::string id_1043 { std::get<0>(id_1042) };
                uint32_t id_1044 { (uint32_t)id_1043.size() };
                Vec<1, uint32_t> id_1045 {  id_1044  };
                Size let_res_1046;
                {
                  Vec<1, uint32_t> n_ref_680 { id_1045 };
                  uint32_t id_1047 { 1U };
                  Vec<1, uint32_t> id_1048 {  id_1047  };
                  Size let_res_1049;
                  {
                    Vec<1, uint32_t> lebsz_ref_681 { id_1048 };
                    bool while_flag_1050 { true };
                    do {
                      uint8_t id_1051 { 0 };
                      uint32_t id_1052 { n_ref_680[id_1051] };
                      uint8_t id_1053 { 0 };
                      uint32_t id_1054 { lebsz_ref_681[id_1053] };
                      uint8_t id_1055 { 7 };
                      uint32_t id_1056 { uint32_t(id_1054 << id_1055) };
                      bool id_1057 { bool(id_1052 >= id_1056) };
                      while_flag_1050 = id_1057;
                      if (while_flag_1050) {
                        uint8_t id_1058 { 0 };
                        uint8_t id_1059 { 0 };
                        uint32_t id_1060 { lebsz_ref_681[id_1059] };
                        uint32_t id_1061 { 1U };
                        uint32_t id_1062 { uint32_t(id_1060 + id_1061) };
                        Void id_1063 { ((void)(lebsz_ref_681[id_1058] = id_1062), ::dessser::VOID) };
                        (void)id_1063;
                      }
                    } while (while_flag_1050);
                    (void)::dessser::VOID;
                    uint8_t id_1064 { 0 };
                    uint32_t id_1065 { lebsz_ref_681[id_1064] };
                    Size id_1066 { Size(id_1065) };
                    let_res_1049 = id_1066;
                  }
                  let_res_1046 = let_res_1049;
                }
                ::dessser::gen::sync_key::t64c0474e57c610aaa3e07cb04692cefe id_1067 { std::get<5 /* Dialogs */>((*p_0)) };
                std::string id_1068 { std::get<0>(id_1067) };
                uint32_t id_1069 { (uint32_t)id_1068.size() };
                Size id_1070 { Size(id_1069) };
                Size id_1071 { Size(let_res_1046 + id_1070) };
                Size id_1072 { Size(id_1041 + id_1071) };
                Size let_res_1073;
                {
                  Size sz_682 { id_1072 };
                  ::dessser::gen::sync_key::t64c0474e57c610aaa3e07cb04692cefe id_1074 { std::get<5 /* Dialogs */>((*p_0)) };
                  std::shared_ptr<::dessser::gen::sync_key::dialog_key>  id_1075 { std::get<1>(id_1074) };
                  Size id_1076 { dialog_key_sersize_of_row_binary(id_1075) };
                  Size id_1077 { Size(sz_682 + id_1076) };
                  let_res_1073 = id_1077;
                }
                choose_res_1040 = let_res_1073;
              } else {
                uint16_t id_1078 { uint16_t((*p_0).index()) };
                uint16_t id_1079 { 6 };
                bool id_1080 { bool(id_1078 == id_1079) };
                Void id_1081 { ((void)(assert(id_1080)), ::dessser::VOID) };
                (void)id_1081;
                Size id_1082 { 14UL };
                choose_res_1040 = id_1082;
              }
              choose_res_1035 = choose_res_1040;
            }
            choose_res_1030 = choose_res_1035;
          }
          choose_res_1025 = choose_res_1030;
        }
        choose_res_1020 = choose_res_1025;
      }
      choose_res_1015 = choose_res_1020;
    }
    return choose_res_1015;
  }
   };
  return fun1011;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::incident_key> )> incident_key_sersize_of_row_binary(incident_key_sersize_of_row_binary_init());

/* 
    (fun ("[Widgets U32]") (seq (assert (eq (label-of (param 0)) (u16 0))) (size 6)))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> per_dash_key_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> fun1083 { [&fun1083](std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  p_0) {
    uint16_t id_1084 { uint16_t((*p_0).index()) };
    uint16_t id_1085 { 0 };
    bool id_1086 { bool(id_1084 == id_1085) };
    Void id_1087 { ((void)(assert(id_1086)), ::dessser::VOID) };
    (void)id_1087;
    Size id_1088 { 6UL };
    return id_1088;
  }
   };
  return fun1083;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_dash_key> )> per_dash_key_sersize_of_row_binary(per_dash_key_sersize_of_row_binary_init());

/* 
    (fun ("[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_672" (make-vec (string-length (get-alt "Response" (param 0))))
              (let "lebsz_ref_673" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_672")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_673")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_673") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_673")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_673")))))) 
            (size-of-u32 (string-length (get-alt "Response" (param 0))))))
        (seq (assert (eq (label-of (param 0)) (u16 1))) (add (size 2) (apply (identifier "per_dash_key-sersize-of-row-binary") (get-alt "Scratchpad" (param 0)))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> per_client_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> fun1089 { [&fun1089](std::shared_ptr<::dessser::gen::sync_key::per_client>  p_0) {
    uint16_t id_1090 { 0 };
    uint16_t id_1091 { uint16_t((*p_0).index()) };
    bool id_1092 { bool(id_1090 == id_1091) };
    Size choose_res_1093;
    if (id_1092) {
      Size id_1094 { 2UL };
      std::string id_1095 { std::get<0 /* Response */>((*p_0)) };
      uint32_t id_1096 { (uint32_t)id_1095.size() };
      Vec<1, uint32_t> id_1097 {  id_1096  };
      Size let_res_1098;
      {
        Vec<1, uint32_t> n_ref_672 { id_1097 };
        uint32_t id_1099 { 1U };
        Vec<1, uint32_t> id_1100 {  id_1099  };
        Size let_res_1101;
        {
          Vec<1, uint32_t> lebsz_ref_673 { id_1100 };
          bool while_flag_1102 { true };
          do {
            uint8_t id_1103 { 0 };
            uint32_t id_1104 { n_ref_672[id_1103] };
            uint8_t id_1105 { 0 };
            uint32_t id_1106 { lebsz_ref_673[id_1105] };
            uint8_t id_1107 { 7 };
            uint32_t id_1108 { uint32_t(id_1106 << id_1107) };
            bool id_1109 { bool(id_1104 >= id_1108) };
            while_flag_1102 = id_1109;
            if (while_flag_1102) {
              uint8_t id_1110 { 0 };
              uint8_t id_1111 { 0 };
              uint32_t id_1112 { lebsz_ref_673[id_1111] };
              uint32_t id_1113 { 1U };
              uint32_t id_1114 { uint32_t(id_1112 + id_1113) };
              Void id_1115 { ((void)(lebsz_ref_673[id_1110] = id_1114), ::dessser::VOID) };
              (void)id_1115;
            }
          } while (while_flag_1102);
          (void)::dessser::VOID;
          uint8_t id_1116 { 0 };
          uint32_t id_1117 { lebsz_ref_673[id_1116] };
          Size id_1118 { Size(id_1117) };
          let_res_1101 = id_1118;
        }
        let_res_1098 = let_res_1101;
      }
      std::string id_1119 { std::get<0 /* Response */>((*p_0)) };
      uint32_t id_1120 { (uint32_t)id_1119.size() };
      Size id_1121 { Size(id_1120) };
      Size id_1122 { Size(let_res_1098 + id_1121) };
      Size id_1123 { Size(id_1094 + id_1122) };
      choose_res_1093 = id_1123;
    } else {
      uint16_t id_1124 { uint16_t((*p_0).index()) };
      uint16_t id_1125 { 1 };
      bool id_1126 { bool(id_1124 == id_1125) };
      Void id_1127 { ((void)(assert(id_1126)), ::dessser::VOID) };
      (void)id_1127;
      Size id_1128 { 2UL };
      std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1129 { std::get<1 /* Scratchpad */>((*p_0)) };
      Size id_1130 { per_dash_key_sersize_of_row_binary(id_1129) };
      Size id_1131 { Size(id_1128 + id_1130) };
      choose_res_1093 = id_1131;
    }
    return choose_res_1093;
  }
   };
  return fun1089;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_client> )> per_client_sersize_of_row_binary(per_client_sersize_of_row_binary_init());

/* 
    (fun ("[Subscriber STRING | LastTuple U32]")
      (if (eq (u16 0) (label-of (param 0)))
        (add (size 2)
          (add
            (let "n_ref_667" (make-vec (string-length (get-alt "Subscriber" (param 0))))
              (let "lebsz_ref_668" (make-vec (u32 1))
                (seq
                  (while (ge (unsafe-nth (u8 0) (identifier "n_ref_667")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_668")) (u8 7)))
                    (set-vec (u8 0) (identifier "lebsz_ref_668") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_668")) (u32 1)))) 
                  (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_668")))))) 
            (size-of-u32 (string-length (get-alt "Subscriber" (param 0)))))) 
        (seq (assert (eq (label-of (param 0)) (u16 1))) (size 6))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> per_tail_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_tail> )> fun1132 { [&fun1132](std::shared_ptr<::dessser::gen::sync_key::per_tail>  p_0) {
    uint16_t id_1133 { 0 };
    uint16_t id_1134 { uint16_t((*p_0).index()) };
    bool id_1135 { bool(id_1133 == id_1134) };
    Size choose_res_1136;
    if (id_1135) {
      Size id_1137 { 2UL };
      std::string id_1138 { std::get<0 /* Subscriber */>((*p_0)) };
      uint32_t id_1139 { (uint32_t)id_1138.size() };
      Vec<1, uint32_t> id_1140 {  id_1139  };
      Size let_res_1141;
      {
        Vec<1, uint32_t> n_ref_667 { id_1140 };
        uint32_t id_1142 { 1U };
        Vec<1, uint32_t> id_1143 {  id_1142  };
        Size let_res_1144;
        {
          Vec<1, uint32_t> lebsz_ref_668 { id_1143 };
          bool while_flag_1145 { true };
          do {
            uint8_t id_1146 { 0 };
            uint32_t id_1147 { n_ref_667[id_1146] };
            uint8_t id_1148 { 0 };
            uint32_t id_1149 { lebsz_ref_668[id_1148] };
            uint8_t id_1150 { 7 };
            uint32_t id_1151 { uint32_t(id_1149 << id_1150) };
            bool id_1152 { bool(id_1147 >= id_1151) };
            while_flag_1145 = id_1152;
            if (while_flag_1145) {
              uint8_t id_1153 { 0 };
              uint8_t id_1154 { 0 };
              uint32_t id_1155 { lebsz_ref_668[id_1154] };
              uint32_t id_1156 { 1U };
              uint32_t id_1157 { uint32_t(id_1155 + id_1156) };
              Void id_1158 { ((void)(lebsz_ref_668[id_1153] = id_1157), ::dessser::VOID) };
              (void)id_1158;
            }
          } while (while_flag_1145);
          (void)::dessser::VOID;
          uint8_t id_1159 { 0 };
          uint32_t id_1160 { lebsz_ref_668[id_1159] };
          Size id_1161 { Size(id_1160) };
          let_res_1144 = id_1161;
        }
        let_res_1141 = let_res_1144;
      }
      std::string id_1162 { std::get<0 /* Subscriber */>((*p_0)) };
      uint32_t id_1163 { (uint32_t)id_1162.size() };
      Size id_1164 { Size(id_1163) };
      Size id_1165 { Size(let_res_1141 + id_1164) };
      Size id_1166 { Size(id_1137 + id_1165) };
      choose_res_1136 = id_1166;
    } else {
      uint16_t id_1167 { uint16_t((*p_0).index()) };
      uint16_t id_1168 { 1 };
      bool id_1169 { bool(id_1167 == id_1168) };
      Void id_1170 { ((void)(assert(id_1169)), ::dessser::VOID) };
      (void)id_1170;
      Size id_1171 { 6UL };
      choose_res_1136 = id_1171;
    }
    return choose_res_1136;
  }
   };
  return fun1132;
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
                    (let "sz_646"
                      (add (size 2)
                        (add
                          (let "n_ref_644" (make-vec (string-length (get-item 0 (get-alt "PerInstance" (param 0)))))
                            (let "lebsz_ref_645" (make-vec (u32 1))
                              (seq
                                (while (ge (unsafe-nth (u8 0) (identifier "n_ref_644")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_645")) (u8 7)))
                                  (set-vec (u8 0) (identifier "lebsz_ref_645") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_645")) (u32 1)))) 
                                (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_645")))))) 
                          (size-of-u32 (string-length (get-item 0 (get-alt "PerInstance" (param 0)))))))
                      (let "label2_647" (label-of (get-item 1 (get-alt "PerInstance" (param 0))))
                        (if (eq (u16 0) (identifier "label2_647")) (add (identifier "sz_646") (size 2))
                          (if (eq (u16 1) (identifier "label2_647")) 
                            (add (identifier "sz_646") (size 2))
                            (if (eq (u16 2) (identifier "label2_647")) 
                              (add (identifier "sz_646") (size 2))
                              (if (eq (u16 3) (identifier "label2_647")) 
                                (add (identifier "sz_646") (size 2))
                                (if (eq (u16 4) (identifier "label2_647")) 
                                  (add (identifier "sz_646") (size 2))
                                  (if (eq (u16 5) (identifier "label2_647")) 
                                    (add (identifier "sz_646") (size 2))
                                    (if (eq (u16 6) (identifier "label2_647")) (add (identifier "sz_646") (size 2)) (seq (assert (eq (identifier "label2_647") (u16 7))) (add (identifier "sz_646") (size 2))))))))))))
                    (if (eq (u16 7) (label-of (param 0))) (size 6) (seq (assert (eq (label-of (param 0)) (u16 8))) (size 2)))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> )> per_worker_data_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> )> fun1172 { [&fun1172](std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  p_0) {
    uint16_t id_1173 { 0 };
    uint16_t id_1174 { uint16_t((*p_0).index()) };
    bool id_1175 { bool(id_1173 == id_1174) };
    Size choose_res_1176;
    if (id_1175) {
      Size id_1177 { 2UL };
      choose_res_1176 = id_1177;
    } else {
      uint16_t id_1178 { 1 };
      uint16_t id_1179 { uint16_t((*p_0).index()) };
      bool id_1180 { bool(id_1178 == id_1179) };
      Size choose_res_1181;
      if (id_1180) {
        Size id_1182 { 2UL };
        choose_res_1181 = id_1182;
      } else {
        uint16_t id_1183 { 2 };
        uint16_t id_1184 { uint16_t((*p_0).index()) };
        bool id_1185 { bool(id_1183 == id_1184) };
        Size choose_res_1186;
        if (id_1185) {
          Size id_1187 { 2UL };
          choose_res_1186 = id_1187;
        } else {
          uint16_t id_1188 { 3 };
          uint16_t id_1189 { uint16_t((*p_0).index()) };
          bool id_1190 { bool(id_1188 == id_1189) };
          Size choose_res_1191;
          if (id_1190) {
            Size id_1192 { 2UL };
            choose_res_1191 = id_1192;
          } else {
            uint16_t id_1193 { 4 };
            uint16_t id_1194 { uint16_t((*p_0).index()) };
            bool id_1195 { bool(id_1193 == id_1194) };
            Size choose_res_1196;
            if (id_1195) {
              Size id_1197 { 2UL };
              choose_res_1196 = id_1197;
            } else {
              uint16_t id_1198 { 5 };
              uint16_t id_1199 { uint16_t((*p_0).index()) };
              bool id_1200 { bool(id_1198 == id_1199) };
              Size choose_res_1201;
              if (id_1200) {
                Size id_1202 { 2UL };
                choose_res_1201 = id_1202;
              } else {
                uint16_t id_1203 { 6 };
                uint16_t id_1204 { uint16_t((*p_0).index()) };
                bool id_1205 { bool(id_1203 == id_1204) };
                Size choose_res_1206;
                if (id_1205) {
                  Size id_1207 { 2UL };
                  ::dessser::gen::sync_key::t35f466ab2ffe47e08d3d46d20f2eb1a6 id_1208 { std::get<6 /* PerInstance */>((*p_0)) };
                  std::string id_1209 { std::get<0>(id_1208) };
                  uint32_t id_1210 { (uint32_t)id_1209.size() };
                  Vec<1, uint32_t> id_1211 {  id_1210  };
                  Size let_res_1212;
                  {
                    Vec<1, uint32_t> n_ref_644 { id_1211 };
                    uint32_t id_1213 { 1U };
                    Vec<1, uint32_t> id_1214 {  id_1213  };
                    Size let_res_1215;
                    {
                      Vec<1, uint32_t> lebsz_ref_645 { id_1214 };
                      bool while_flag_1216 { true };
                      do {
                        uint8_t id_1217 { 0 };
                        uint32_t id_1218 { n_ref_644[id_1217] };
                        uint8_t id_1219 { 0 };
                        uint32_t id_1220 { lebsz_ref_645[id_1219] };
                        uint8_t id_1221 { 7 };
                        uint32_t id_1222 { uint32_t(id_1220 << id_1221) };
                        bool id_1223 { bool(id_1218 >= id_1222) };
                        while_flag_1216 = id_1223;
                        if (while_flag_1216) {
                          uint8_t id_1224 { 0 };
                          uint8_t id_1225 { 0 };
                          uint32_t id_1226 { lebsz_ref_645[id_1225] };
                          uint32_t id_1227 { 1U };
                          uint32_t id_1228 { uint32_t(id_1226 + id_1227) };
                          Void id_1229 { ((void)(lebsz_ref_645[id_1224] = id_1228), ::dessser::VOID) };
                          (void)id_1229;
                        }
                      } while (while_flag_1216);
                      (void)::dessser::VOID;
                      uint8_t id_1230 { 0 };
                      uint32_t id_1231 { lebsz_ref_645[id_1230] };
                      Size id_1232 { Size(id_1231) };
                      let_res_1215 = id_1232;
                    }
                    let_res_1212 = let_res_1215;
                  }
                  ::dessser::gen::sync_key::t35f466ab2ffe47e08d3d46d20f2eb1a6 id_1233 { std::get<6 /* PerInstance */>((*p_0)) };
                  std::string id_1234 { std::get<0>(id_1233) };
                  uint32_t id_1235 { (uint32_t)id_1234.size() };
                  Size id_1236 { Size(id_1235) };
                  Size id_1237 { Size(let_res_1212 + id_1236) };
                  Size id_1238 { Size(id_1207 + id_1237) };
                  Size let_res_1239;
                  {
                    Size sz_646 { id_1238 };
                    ::dessser::gen::sync_key::t35f466ab2ffe47e08d3d46d20f2eb1a6 id_1240 { std::get<6 /* PerInstance */>((*p_0)) };
                    ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_1241 { std::get<1>(id_1240) };
                    uint16_t id_1242 { uint16_t(id_1241.index()) };
                    Size let_res_1243;
                    {
                      uint16_t label2_647 { id_1242 };
                      uint16_t id_1244 { 0 };
                      bool id_1245 { bool(id_1244 == label2_647) };
                      Size choose_res_1246;
                      if (id_1245) {
                        Size id_1247 { 2UL };
                        Size id_1248 { Size(sz_646 + id_1247) };
                        choose_res_1246 = id_1248;
                      } else {
                        uint16_t id_1249 { 1 };
                        bool id_1250 { bool(id_1249 == label2_647) };
                        Size choose_res_1251;
                        if (id_1250) {
                          Size id_1252 { 2UL };
                          Size id_1253 { Size(sz_646 + id_1252) };
                          choose_res_1251 = id_1253;
                        } else {
                          uint16_t id_1254 { 2 };
                          bool id_1255 { bool(id_1254 == label2_647) };
                          Size choose_res_1256;
                          if (id_1255) {
                            Size id_1257 { 2UL };
                            Size id_1258 { Size(sz_646 + id_1257) };
                            choose_res_1256 = id_1258;
                          } else {
                            uint16_t id_1259 { 3 };
                            bool id_1260 { bool(id_1259 == label2_647) };
                            Size choose_res_1261;
                            if (id_1260) {
                              Size id_1262 { 2UL };
                              Size id_1263 { Size(sz_646 + id_1262) };
                              choose_res_1261 = id_1263;
                            } else {
                              uint16_t id_1264 { 4 };
                              bool id_1265 { bool(id_1264 == label2_647) };
                              Size choose_res_1266;
                              if (id_1265) {
                                Size id_1267 { 2UL };
                                Size id_1268 { Size(sz_646 + id_1267) };
                                choose_res_1266 = id_1268;
                              } else {
                                uint16_t id_1269 { 5 };
                                bool id_1270 { bool(id_1269 == label2_647) };
                                Size choose_res_1271;
                                if (id_1270) {
                                  Size id_1272 { 2UL };
                                  Size id_1273 { Size(sz_646 + id_1272) };
                                  choose_res_1271 = id_1273;
                                } else {
                                  uint16_t id_1274 { 6 };
                                  bool id_1275 { bool(id_1274 == label2_647) };
                                  Size choose_res_1276;
                                  if (id_1275) {
                                    Size id_1277 { 2UL };
                                    Size id_1278 { Size(sz_646 + id_1277) };
                                    choose_res_1276 = id_1278;
                                  } else {
                                    uint16_t id_1279 { 7 };
                                    bool id_1280 { bool(label2_647 == id_1279) };
                                    Void id_1281 { ((void)(assert(id_1280)), ::dessser::VOID) };
                                    (void)id_1281;
                                    Size id_1282 { 2UL };
                                    Size id_1283 { Size(sz_646 + id_1282) };
                                    choose_res_1276 = id_1283;
                                  }
                                  choose_res_1271 = choose_res_1276;
                                }
                                choose_res_1266 = choose_res_1271;
                              }
                              choose_res_1261 = choose_res_1266;
                            }
                            choose_res_1256 = choose_res_1261;
                          }
                          choose_res_1251 = choose_res_1256;
                        }
                        choose_res_1246 = choose_res_1251;
                      }
                      let_res_1243 = choose_res_1246;
                    }
                    let_res_1239 = let_res_1243;
                  }
                  choose_res_1206 = let_res_1239;
                } else {
                  uint16_t id_1284 { 7 };
                  uint16_t id_1285 { uint16_t((*p_0).index()) };
                  bool id_1286 { bool(id_1284 == id_1285) };
                  Size choose_res_1287;
                  if (id_1286) {
                    Size id_1288 { 6UL };
                    choose_res_1287 = id_1288;
                  } else {
                    uint16_t id_1289 { uint16_t((*p_0).index()) };
                    uint16_t id_1290 { 8 };
                    bool id_1291 { bool(id_1289 == id_1290) };
                    Void id_1292 { ((void)(assert(id_1291)), ::dessser::VOID) };
                    (void)id_1292;
                    Size id_1293 { 2UL };
                    choose_res_1287 = id_1293;
                  }
                  choose_res_1206 = choose_res_1287;
                }
                choose_res_1201 = choose_res_1206;
              }
              choose_res_1196 = choose_res_1201;
            }
            choose_res_1191 = choose_res_1196;
          }
          choose_res_1186 = choose_res_1191;
        }
        choose_res_1181 = choose_res_1186;
      }
      choose_res_1176 = choose_res_1181;
    }
    return choose_res_1176;
  }
   };
  return fun1172;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker_data> )> per_worker_data_sersize_of_row_binary(per_worker_data_sersize_of_row_binary_init());

/* 
    (fun ("($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))")
      (let "sz_649" (apply (ext-identifier fq_name sersize-of-row-binary) (get-item 0 (param 0))) (add (identifier "sz_649") (apply (identifier "per_worker_data-sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker> )> per_worker_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker> )> fun1294 { [&fun1294](std::shared_ptr<::dessser::gen::sync_key::per_worker>  p_0) {
    auto fun1295 { dessser::gen::fq_name::sersize_of_row_binary };
    dessser::gen::fq_name::t_ext id_1296 { std::get<0>((*p_0)) };
    Size id_1297 { fun1295(id_1296) };
    Size let_res_1298;
    {
      Size sz_649 { id_1297 };
      std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_1299 { std::get<1>((*p_0)) };
      Size id_1300 { per_worker_data_sersize_of_row_binary(id_1299) };
      Size id_1301 { Size(sz_649 + id_1300) };
      let_res_1298 = id_1301;
    }
    return let_res_1298;
  }
   };
  return fun1294;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_worker> )> per_worker_sersize_of_row_binary(per_worker_sersize_of_row_binary_init());

/* 
    (fun ("[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]")
      (if (eq (u16 0) (label-of (param 0))) (size 2)
        (if (eq (u16 1) (label-of (param 0)))
          (let "sz_661"
            (add (size 2)
              (add
                (let "n_ref_659" (make-vec (string-length (get-item 0 (get-alt "PerService" (param 0)))))
                  (let "lebsz_ref_660" (make-vec (u32 1))
                    (seq
                      (while (ge (unsafe-nth (u8 0) (identifier "n_ref_659")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_660")) (u8 7)))
                        (set-vec (u8 0) (identifier "lebsz_ref_660") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_660")) (u32 1)))) 
                      (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_660")))))) 
                (size-of-u32 (string-length (get-item 0 (get-alt "PerService" (param 0)))))))
            (if (eq (u16 0) (label-of (get-item 1 (get-alt "PerService" (param 0))))) 
              (add (identifier "sz_661") (size 2)) (seq (assert (eq (label-of (get-item 1 (get-alt "PerService" (param 0)))) (u16 1))) (add (identifier "sz_661") (size 2)))))
          (if (eq (u16 2) (label-of (param 0))) (add (size 2) (apply (identifier "per_worker-sersize-of-row-binary") (get-alt "PerWorker" (param 0))))
            (seq (assert (eq (label-of (param 0)) (u16 3)))
              (let "sz_655"
                (add (size 2)
                  (add
                    (let "n_ref_653" (make-vec (string-length (get-item 0 (get-alt "PerProgram" (param 0)))))
                      (let "lebsz_ref_654" (make-vec (u32 1))
                        (seq
                          (while (ge (unsafe-nth (u8 0) (identifier "n_ref_653")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_654")) (u8 7)))
                            (set-vec (u8 0) (identifier "lebsz_ref_654") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_654")) (u32 1)))) 
                          (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_654")))))) 
                    (size-of-u32 (string-length (get-item 0 (get-alt "PerProgram" (param 0))))))) 
                (seq (assert (eq (label-of (get-item 1 (get-alt "PerProgram" (param 0)))) (u16 0))) (add (identifier "sz_655") (size 2)))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site_data> )> per_site_data_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site_data> )> fun1302 { [&fun1302](std::shared_ptr<::dessser::gen::sync_key::per_site_data>  p_0) {
    uint16_t id_1303 { 0 };
    uint16_t id_1304 { uint16_t((*p_0).index()) };
    bool id_1305 { bool(id_1303 == id_1304) };
    Size choose_res_1306;
    if (id_1305) {
      Size id_1307 { 2UL };
      choose_res_1306 = id_1307;
    } else {
      uint16_t id_1308 { 1 };
      uint16_t id_1309 { uint16_t((*p_0).index()) };
      bool id_1310 { bool(id_1308 == id_1309) };
      Size choose_res_1311;
      if (id_1310) {
        Size id_1312 { 2UL };
        ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773 id_1313 { std::get<1 /* PerService */>((*p_0)) };
        std::string id_1314 { std::get<0>(id_1313) };
        uint32_t id_1315 { (uint32_t)id_1314.size() };
        Vec<1, uint32_t> id_1316 {  id_1315  };
        Size let_res_1317;
        {
          Vec<1, uint32_t> n_ref_659 { id_1316 };
          uint32_t id_1318 { 1U };
          Vec<1, uint32_t> id_1319 {  id_1318  };
          Size let_res_1320;
          {
            Vec<1, uint32_t> lebsz_ref_660 { id_1319 };
            bool while_flag_1321 { true };
            do {
              uint8_t id_1322 { 0 };
              uint32_t id_1323 { n_ref_659[id_1322] };
              uint8_t id_1324 { 0 };
              uint32_t id_1325 { lebsz_ref_660[id_1324] };
              uint8_t id_1326 { 7 };
              uint32_t id_1327 { uint32_t(id_1325 << id_1326) };
              bool id_1328 { bool(id_1323 >= id_1327) };
              while_flag_1321 = id_1328;
              if (while_flag_1321) {
                uint8_t id_1329 { 0 };
                uint8_t id_1330 { 0 };
                uint32_t id_1331 { lebsz_ref_660[id_1330] };
                uint32_t id_1332 { 1U };
                uint32_t id_1333 { uint32_t(id_1331 + id_1332) };
                Void id_1334 { ((void)(lebsz_ref_660[id_1329] = id_1333), ::dessser::VOID) };
                (void)id_1334;
              }
            } while (while_flag_1321);
            (void)::dessser::VOID;
            uint8_t id_1335 { 0 };
            uint32_t id_1336 { lebsz_ref_660[id_1335] };
            Size id_1337 { Size(id_1336) };
            let_res_1320 = id_1337;
          }
          let_res_1317 = let_res_1320;
        }
        ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773 id_1338 { std::get<1 /* PerService */>((*p_0)) };
        std::string id_1339 { std::get<0>(id_1338) };
        uint32_t id_1340 { (uint32_t)id_1339.size() };
        Size id_1341 { Size(id_1340) };
        Size id_1342 { Size(let_res_1317 + id_1341) };
        Size id_1343 { Size(id_1312 + id_1342) };
        Size let_res_1344;
        {
          Size sz_661 { id_1343 };
          uint16_t id_1345 { 0 };
          ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773 id_1346 { std::get<1 /* PerService */>((*p_0)) };
          ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_1347 { std::get<1>(id_1346) };
          uint16_t id_1348 { uint16_t(id_1347.index()) };
          bool id_1349 { bool(id_1345 == id_1348) };
          Size choose_res_1350;
          if (id_1349) {
            Size id_1351 { 2UL };
            Size id_1352 { Size(sz_661 + id_1351) };
            choose_res_1350 = id_1352;
          } else {
            ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773 id_1353 { std::get<1 /* PerService */>((*p_0)) };
            ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_1354 { std::get<1>(id_1353) };
            uint16_t id_1355 { uint16_t(id_1354.index()) };
            uint16_t id_1356 { 1 };
            bool id_1357 { bool(id_1355 == id_1356) };
            Void id_1358 { ((void)(assert(id_1357)), ::dessser::VOID) };
            (void)id_1358;
            Size id_1359 { 2UL };
            Size id_1360 { Size(sz_661 + id_1359) };
            choose_res_1350 = id_1360;
          }
          let_res_1344 = choose_res_1350;
        }
        choose_res_1311 = let_res_1344;
      } else {
        uint16_t id_1361 { 2 };
        uint16_t id_1362 { uint16_t((*p_0).index()) };
        bool id_1363 { bool(id_1361 == id_1362) };
        Size choose_res_1364;
        if (id_1363) {
          Size id_1365 { 2UL };
          std::shared_ptr<::dessser::gen::sync_key::per_worker>  id_1366 { std::get<2 /* PerWorker */>((*p_0)) };
          Size id_1367 { per_worker_sersize_of_row_binary(id_1366) };
          Size id_1368 { Size(id_1365 + id_1367) };
          choose_res_1364 = id_1368;
        } else {
          uint16_t id_1369 { uint16_t((*p_0).index()) };
          uint16_t id_1370 { 3 };
          bool id_1371 { bool(id_1369 == id_1370) };
          Void id_1372 { ((void)(assert(id_1371)), ::dessser::VOID) };
          (void)id_1372;
          Size id_1373 { 2UL };
          ::dessser::gen::sync_key::t861fec96932eb3dcd604deb55a8fed37 id_1374 { std::get<3 /* PerProgram */>((*p_0)) };
          std::string id_1375 { std::get<0>(id_1374) };
          uint32_t id_1376 { (uint32_t)id_1375.size() };
          Vec<1, uint32_t> id_1377 {  id_1376  };
          Size let_res_1378;
          {
            Vec<1, uint32_t> n_ref_653 { id_1377 };
            uint32_t id_1379 { 1U };
            Vec<1, uint32_t> id_1380 {  id_1379  };
            Size let_res_1381;
            {
              Vec<1, uint32_t> lebsz_ref_654 { id_1380 };
              bool while_flag_1382 { true };
              do {
                uint8_t id_1383 { 0 };
                uint32_t id_1384 { n_ref_653[id_1383] };
                uint8_t id_1385 { 0 };
                uint32_t id_1386 { lebsz_ref_654[id_1385] };
                uint8_t id_1387 { 7 };
                uint32_t id_1388 { uint32_t(id_1386 << id_1387) };
                bool id_1389 { bool(id_1384 >= id_1388) };
                while_flag_1382 = id_1389;
                if (while_flag_1382) {
                  uint8_t id_1390 { 0 };
                  uint8_t id_1391 { 0 };
                  uint32_t id_1392 { lebsz_ref_654[id_1391] };
                  uint32_t id_1393 { 1U };
                  uint32_t id_1394 { uint32_t(id_1392 + id_1393) };
                  Void id_1395 { ((void)(lebsz_ref_654[id_1390] = id_1394), ::dessser::VOID) };
                  (void)id_1395;
                }
              } while (while_flag_1382);
              (void)::dessser::VOID;
              uint8_t id_1396 { 0 };
              uint32_t id_1397 { lebsz_ref_654[id_1396] };
              Size id_1398 { Size(id_1397) };
              let_res_1381 = id_1398;
            }
            let_res_1378 = let_res_1381;
          }
          ::dessser::gen::sync_key::t861fec96932eb3dcd604deb55a8fed37 id_1399 { std::get<3 /* PerProgram */>((*p_0)) };
          std::string id_1400 { std::get<0>(id_1399) };
          uint32_t id_1401 { (uint32_t)id_1400.size() };
          Size id_1402 { Size(id_1401) };
          Size id_1403 { Size(let_res_1378 + id_1402) };
          Size id_1404 { Size(id_1373 + id_1403) };
          Size let_res_1405;
          {
            Size sz_655 { id_1404 };
            ::dessser::gen::sync_key::t861fec96932eb3dcd604deb55a8fed37 id_1406 { std::get<3 /* PerProgram */>((*p_0)) };
            ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51 id_1407 { std::get<1>(id_1406) };
            uint16_t id_1408 { uint16_t(id_1407.index()) };
            uint16_t id_1409 { 0 };
            bool id_1410 { bool(id_1408 == id_1409) };
            Void id_1411 { ((void)(assert(id_1410)), ::dessser::VOID) };
            (void)id_1411;
            Size id_1412 { 2UL };
            Size id_1413 { Size(sz_655 + id_1412) };
            let_res_1405 = id_1413;
          }
          choose_res_1364 = let_res_1405;
        }
        choose_res_1311 = choose_res_1364;
      }
      choose_res_1306 = choose_res_1311;
    }
    return choose_res_1306;
  }
   };
  return fun1302;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site_data> )> per_site_data_sersize_of_row_binary(per_site_data_sersize_of_row_binary_init());

/* 
    (fun ("($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))")
      (let "sz_664" (apply (ext-identifier site_name sersize-of-row-binary) (get-item 0 (param 0))) (add (identifier "sz_664") (apply (identifier "per_site_data-sersize-of-row-binary") (get-item 1 (param 0))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site> )> per_site_sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site> )> fun1414 { [&fun1414](std::shared_ptr<::dessser::gen::sync_key::per_site>  p_0) {
    auto fun1415 { dessser::gen::site_name::sersize_of_row_binary };
    dessser::gen::site_name::t_ext id_1416 { std::get<0>((*p_0)) };
    Size id_1417 { fun1415(id_1416) };
    Size let_res_1418;
    {
      Size sz_664 { id_1417 };
      std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_1419 { std::get<1>((*p_0)) };
      Size id_1420 { per_site_data_sersize_of_row_binary(id_1419) };
      Size id_1421 { Size(sz_664 + id_1420) };
      let_res_1418 = id_1421;
    }
    return let_res_1418;
  }
   };
  return fun1414;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::per_site> )> per_site_sersize_of_row_binary(per_site_sersize_of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]")
      (let "label2_683" (label-of (param 0))
        (if (eq (u16 0) (identifier "label2_683")) (size 2)
          (if (eq (u16 1) (identifier "label2_683")) (size 2)
            (if (eq (u16 2) (identifier "label2_683"))
              (add (size 2)
                (add
                  (let "n_ref_722" (make-vec (string-length (get-alt "Versions" (param 0))))
                    (let "lebsz_ref_723" (make-vec (u32 1))
                      (seq
                        (while (ge (unsafe-nth (u8 0) (identifier "n_ref_722")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_723")) (u8 7)))
                          (set-vec (u8 0) (identifier "lebsz_ref_723") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_723")) (u32 1)))) 
                        (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_723")))))) 
                  (size-of-u32 (string-length (get-alt "Versions" (param 0))))))
              (if (eq (u16 3) (identifier "label2_683"))
                (let "sz_717" (add (size 2) (apply (ext-identifier src_path sersize-of-row-binary) (get-item 0 (get-alt "Sources" (param 0)))))
                  (add (identifier "sz_717")
                    (add
                      (let "n_ref_719" (make-vec (string-length (get-item 1 (get-alt "Sources" (param 0)))))
                        (let "lebsz_ref_720" (make-vec (u32 1))
                          (seq
                            (while (ge (unsafe-nth (u8 0) (identifier "n_ref_719")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_720")) (u8 7)))
                              (set-vec (u8 0) (identifier "lebsz_ref_720") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_720")) (u32 1)))) 
                            (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_720")))))) 
                      (size-of-u32 (string-length (get-item 1 (get-alt "Sources" (param 0))))))))
                (if (eq (u16 4) (identifier "label2_683")) (size 2)
                  (if (eq (u16 5) (identifier "label2_683")) (add (size 2) (apply (identifier "per_site-sersize-of-row-binary") (get-alt "PerSite" (param 0))))
                    (if (eq (u16 6) (identifier "label2_683"))
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
                      (if (eq (u16 7) (identifier "label2_683"))
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
                        (if (eq (u16 8) (identifier "label2_683")) (size 4)
                          (if (eq (u16 9) (identifier "label2_683"))
                            (if (is-null (get-alt "Error" (param 0))) (size 3) (add (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (force (get-alt "Error" (param 0))))) (size 1)))
                            (if (eq (u16 10) (identifier "label2_683")) 
                              (size 2)
                              (if (eq (u16 11) (identifier "label2_683"))
                                (let "sz_704" (add (size 2) (apply (ext-identifier sync_socket sersize-of-row-binary) (get-item 0 (get-alt "PerClient" (param 0)))))
                                  (add (identifier "sz_704") (apply (identifier "per_client-sersize-of-row-binary") (get-item 1 (get-alt "PerClient" (param 0))))))
                                (if (eq (u16 12) (identifier "label2_683"))
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
                                  (if (eq (u16 13) (identifier "label2_683")) 
                                    (size 2)
                                    (if (eq (u16 14) (identifier "label2_683"))
                                      (let "sz_690" (add (size 2) (apply (ext-identifier team_name sersize-of-row-binary) (get-item 0 (get-alt "Teams" (param 0)))))
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
                                      (seq (assert (eq (identifier "label2_683") (u16 15)))
                                        (let "sz_688"
                                          (add (size 2)
                                            (add
                                              (let "n_ref_686" (make-vec (string-length (get-item 0 (get-alt "Incidents" (param 0)))))
                                                (let "lebsz_ref_687" 
                                                  (make-vec (u32 1))
                                                  (seq
                                                    (while (ge (unsafe-nth (u8 0) (identifier "n_ref_686")) (left-shift (unsafe-nth (u8 0) (identifier "lebsz_ref_687")) (u8 7)))
                                                      (set-vec (u8 0) (identifier "lebsz_ref_687") (add (unsafe-nth (u8 0) (identifier "lebsz_ref_687")) (u32 1)))) 
                                                    (size-of-u32 (unsafe-nth (u8 0) (identifier "lebsz_ref_687")))))) 
                                              (size-of-u32 (string-length (get-item 0 (get-alt "Incidents" (param 0)))))))
                                          (add (identifier "sz_688") (apply (identifier "incident_key-sersize-of-row-binary") (get-item 1 (get-alt "Incidents" (param 0))))))))))))))))))))))))
 */
static std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> sersize_of_row_binary_init()
{
  std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> fun1422 { [&fun1422](std::shared_ptr<::dessser::gen::sync_key::t>  p_0) {
    uint16_t id_1423 { uint16_t((*p_0).index()) };
    Size let_res_1424;
    {
      uint16_t label2_683 { id_1423 };
      uint16_t id_1425 { 0 };
      bool id_1426 { bool(id_1425 == label2_683) };
      Size choose_res_1427;
      if (id_1426) {
        Size id_1428 { 2UL };
        choose_res_1427 = id_1428;
      } else {
        uint16_t id_1429 { 1 };
        bool id_1430 { bool(id_1429 == label2_683) };
        Size choose_res_1431;
        if (id_1430) {
          Size id_1432 { 2UL };
          choose_res_1431 = id_1432;
        } else {
          uint16_t id_1433 { 2 };
          bool id_1434 { bool(id_1433 == label2_683) };
          Size choose_res_1435;
          if (id_1434) {
            Size id_1436 { 2UL };
            std::string id_1437 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1438 { (uint32_t)id_1437.size() };
            Vec<1, uint32_t> id_1439 {  id_1438  };
            Size let_res_1440;
            {
              Vec<1, uint32_t> n_ref_722 { id_1439 };
              uint32_t id_1441 { 1U };
              Vec<1, uint32_t> id_1442 {  id_1441  };
              Size let_res_1443;
              {
                Vec<1, uint32_t> lebsz_ref_723 { id_1442 };
                bool while_flag_1444 { true };
                do {
                  uint8_t id_1445 { 0 };
                  uint32_t id_1446 { n_ref_722[id_1445] };
                  uint8_t id_1447 { 0 };
                  uint32_t id_1448 { lebsz_ref_723[id_1447] };
                  uint8_t id_1449 { 7 };
                  uint32_t id_1450 { uint32_t(id_1448 << id_1449) };
                  bool id_1451 { bool(id_1446 >= id_1450) };
                  while_flag_1444 = id_1451;
                  if (while_flag_1444) {
                    uint8_t id_1452 { 0 };
                    uint8_t id_1453 { 0 };
                    uint32_t id_1454 { lebsz_ref_723[id_1453] };
                    uint32_t id_1455 { 1U };
                    uint32_t id_1456 { uint32_t(id_1454 + id_1455) };
                    Void id_1457 { ((void)(lebsz_ref_723[id_1452] = id_1456), ::dessser::VOID) };
                    (void)id_1457;
                  }
                } while (while_flag_1444);
                (void)::dessser::VOID;
                uint8_t id_1458 { 0 };
                uint32_t id_1459 { lebsz_ref_723[id_1458] };
                Size id_1460 { Size(id_1459) };
                let_res_1443 = id_1460;
              }
              let_res_1440 = let_res_1443;
            }
            std::string id_1461 { std::get<2 /* Versions */>((*p_0)) };
            uint32_t id_1462 { (uint32_t)id_1461.size() };
            Size id_1463 { Size(id_1462) };
            Size id_1464 { Size(let_res_1440 + id_1463) };
            Size id_1465 { Size(id_1436 + id_1464) };
            choose_res_1435 = id_1465;
          } else {
            uint16_t id_1466 { 3 };
            bool id_1467 { bool(id_1466 == label2_683) };
            Size choose_res_1468;
            if (id_1467) {
              Size id_1469 { 2UL };
              auto fun1470 { dessser::gen::src_path::sersize_of_row_binary };
              ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_1471 { std::get<3 /* Sources */>((*p_0)) };
              dessser::gen::src_path::t_ext id_1472 { std::get<0>(id_1471) };
              Size id_1473 { fun1470(id_1472) };
              Size id_1474 { Size(id_1469 + id_1473) };
              Size let_res_1475;
              {
                Size sz_717 { id_1474 };
                ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_1476 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1477 { std::get<1>(id_1476) };
                uint32_t id_1478 { (uint32_t)id_1477.size() };
                Vec<1, uint32_t> id_1479 {  id_1478  };
                Size let_res_1480;
                {
                  Vec<1, uint32_t> n_ref_719 { id_1479 };
                  uint32_t id_1481 { 1U };
                  Vec<1, uint32_t> id_1482 {  id_1481  };
                  Size let_res_1483;
                  {
                    Vec<1, uint32_t> lebsz_ref_720 { id_1482 };
                    bool while_flag_1484 { true };
                    do {
                      uint8_t id_1485 { 0 };
                      uint32_t id_1486 { n_ref_719[id_1485] };
                      uint8_t id_1487 { 0 };
                      uint32_t id_1488 { lebsz_ref_720[id_1487] };
                      uint8_t id_1489 { 7 };
                      uint32_t id_1490 { uint32_t(id_1488 << id_1489) };
                      bool id_1491 { bool(id_1486 >= id_1490) };
                      while_flag_1484 = id_1491;
                      if (while_flag_1484) {
                        uint8_t id_1492 { 0 };
                        uint8_t id_1493 { 0 };
                        uint32_t id_1494 { lebsz_ref_720[id_1493] };
                        uint32_t id_1495 { 1U };
                        uint32_t id_1496 { uint32_t(id_1494 + id_1495) };
                        Void id_1497 { ((void)(lebsz_ref_720[id_1492] = id_1496), ::dessser::VOID) };
                        (void)id_1497;
                      }
                    } while (while_flag_1484);
                    (void)::dessser::VOID;
                    uint8_t id_1498 { 0 };
                    uint32_t id_1499 { lebsz_ref_720[id_1498] };
                    Size id_1500 { Size(id_1499) };
                    let_res_1483 = id_1500;
                  }
                  let_res_1480 = let_res_1483;
                }
                ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_1501 { std::get<3 /* Sources */>((*p_0)) };
                std::string id_1502 { std::get<1>(id_1501) };
                uint32_t id_1503 { (uint32_t)id_1502.size() };
                Size id_1504 { Size(id_1503) };
                Size id_1505 { Size(let_res_1480 + id_1504) };
                Size id_1506 { Size(sz_717 + id_1505) };
                let_res_1475 = id_1506;
              }
              choose_res_1468 = let_res_1475;
            } else {
              uint16_t id_1507 { 4 };
              bool id_1508 { bool(id_1507 == label2_683) };
              Size choose_res_1509;
              if (id_1508) {
                Size id_1510 { 2UL };
                choose_res_1509 = id_1510;
              } else {
                uint16_t id_1511 { 5 };
                bool id_1512 { bool(id_1511 == label2_683) };
                Size choose_res_1513;
                if (id_1512) {
                  Size id_1514 { 2UL };
                  std::shared_ptr<::dessser::gen::sync_key::per_site>  id_1515 { std::get<5 /* PerSite */>((*p_0)) };
                  Size id_1516 { per_site_sersize_of_row_binary(id_1515) };
                  Size id_1517 { Size(id_1514 + id_1516) };
                  choose_res_1513 = id_1517;
                } else {
                  uint16_t id_1518 { 6 };
                  bool id_1519 { bool(id_1518 == label2_683) };
                  Size choose_res_1520;
                  if (id_1519) {
                    uint16_t id_1521 { 0 };
                    ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_1522 { std::get<6 /* Storage */>((*p_0)) };
                    uint16_t id_1523 { uint16_t(id_1522.index()) };
                    bool id_1524 { bool(id_1521 == id_1523) };
                    Size choose_res_1525;
                    if (id_1524) {
                      Size id_1526 { 4UL };
                      choose_res_1525 = id_1526;
                    } else {
                      uint16_t id_1527 { 1 };
                      ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_1528 { std::get<6 /* Storage */>((*p_0)) };
                      uint16_t id_1529 { uint16_t(id_1528.index()) };
                      bool id_1530 { bool(id_1527 == id_1529) };
                      Size choose_res_1531;
                      if (id_1530) {
                        Size id_1532 { 4UL };
                        choose_res_1531 = id_1532;
                      } else {
                        ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_1533 { std::get<6 /* Storage */>((*p_0)) };
                        uint16_t id_1534 { uint16_t(id_1533.index()) };
                        uint16_t id_1535 { 2 };
                        bool id_1536 { bool(id_1534 == id_1535) };
                        Void id_1537 { ((void)(assert(id_1536)), ::dessser::VOID) };
                        (void)id_1537;
                        Size id_1538 { 4UL };
                        ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_1539 { std::get<6 /* Storage */>((*p_0)) };
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
                                Void id_1560 { ((void)(lebsz_ref_715[id_1555] = id_1559), ::dessser::VOID) };
                                (void)id_1560;
                              }
                            } while (while_flag_1547);
                            (void)::dessser::VOID;
                            uint8_t id_1561 { 0 };
                            uint32_t id_1562 { lebsz_ref_715[id_1561] };
                            Size id_1563 { Size(id_1562) };
                            let_res_1546 = id_1563;
                          }
                          let_res_1543 = let_res_1546;
                        }
                        ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_1564 { std::get<6 /* Storage */>((*p_0)) };
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
                    bool id_1571 { bool(id_1570 == label2_683) };
                    Size choose_res_1572;
                    if (id_1571) {
                      Size id_1573 { 2UL };
                      auto fun1574 { dessser::gen::site_name::sersize_of_row_binary };
                      ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_1575 { std::get<7 /* Tails */>((*p_0)) };
                      dessser::gen::site_name::t_ext id_1576 { std::get<0>(id_1575) };
                      Size id_1577 { fun1574(id_1576) };
                      Size id_1578 { Size(id_1573 + id_1577) };
                      Size let_res_1579;
                      {
                        Size sz_706 { id_1578 };
                        auto fun1580 { dessser::gen::fq_name::sersize_of_row_binary };
                        ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_1581 { std::get<7 /* Tails */>((*p_0)) };
                        dessser::gen::fq_name::t_ext id_1582 { std::get<1>(id_1581) };
                        Size id_1583 { fun1580(id_1582) };
                        Size id_1584 { Size(sz_706 + id_1583) };
                        let_res_1579 = id_1584;
                      }
                      Size let_res_1585;
                      {
                        Size sz_707 { let_res_1579 };
                        ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_1586 { std::get<7 /* Tails */>((*p_0)) };
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
                                Void id_1607 { ((void)(lebsz_ref_710[id_1602] = id_1606), ::dessser::VOID) };
                                (void)id_1607;
                              }
                            } while (while_flag_1594);
                            (void)::dessser::VOID;
                            uint8_t id_1608 { 0 };
                            uint32_t id_1609 { lebsz_ref_710[id_1608] };
                            Size id_1610 { Size(id_1609) };
                            let_res_1593 = id_1610;
                          }
                          let_res_1590 = let_res_1593;
                        }
                        ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_1611 { std::get<7 /* Tails */>((*p_0)) };
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
                        ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_1618 { std::get<7 /* Tails */>((*p_0)) };
                        std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_1619 { std::get<3>(id_1618) };
                        Size id_1620 { per_tail_sersize_of_row_binary(id_1619) };
                        Size id_1621 { Size(sz_711 + id_1620) };
                        let_res_1617 = id_1621;
                      }
                      choose_res_1572 = let_res_1617;
                    } else {
                      uint16_t id_1622 { 8 };
                      bool id_1623 { bool(id_1622 == label2_683) };
                      Size choose_res_1624;
                      if (id_1623) {
                        Size id_1625 { 4UL };
                        choose_res_1624 = id_1625;
                      } else {
                        uint16_t id_1626 { 9 };
                        bool id_1627 { bool(id_1626 == label2_683) };
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
                          bool id_1642 { bool(id_1641 == label2_683) };
                          Size choose_res_1643;
                          if (id_1642) {
                            Size id_1644 { 2UL };
                            choose_res_1643 = id_1644;
                          } else {
                            uint16_t id_1645 { 11 };
                            bool id_1646 { bool(id_1645 == label2_683) };
                            Size choose_res_1647;
                            if (id_1646) {
                              Size id_1648 { 2UL };
                              auto fun1649 { dessser::gen::sync_socket::sersize_of_row_binary };
                              ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c id_1650 { std::get<11 /* PerClient */>((*p_0)) };
                              dessser::gen::sync_socket::t_ext id_1651 { std::get<0>(id_1650) };
                              Size id_1652 { fun1649(id_1651) };
                              Size id_1653 { Size(id_1648 + id_1652) };
                              Size let_res_1654;
                              {
                                Size sz_704 { id_1653 };
                                ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c id_1655 { std::get<11 /* PerClient */>((*p_0)) };
                                std::shared_ptr<::dessser::gen::sync_key::per_client>  id_1656 { std::get<1>(id_1655) };
                                Size id_1657 { per_client_sersize_of_row_binary(id_1656) };
                                Size id_1658 { Size(sz_704 + id_1657) };
                                let_res_1654 = id_1658;
                              }
                              choose_res_1647 = let_res_1654;
                            } else {
                              uint16_t id_1659 { 12 };
                              bool id_1660 { bool(id_1659 == label2_683) };
                              Size choose_res_1661;
                              if (id_1660) {
                                Size id_1662 { 2UL };
                                ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_1663 { std::get<12 /* Dashboards */>((*p_0)) };
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
                                        Void id_1684 { ((void)(lebsz_ref_701[id_1679] = id_1683), ::dessser::VOID) };
                                        (void)id_1684;
                                      }
                                    } while (while_flag_1671);
                                    (void)::dessser::VOID;
                                    uint8_t id_1685 { 0 };
                                    uint32_t id_1686 { lebsz_ref_701[id_1685] };
                                    Size id_1687 { Size(id_1686) };
                                    let_res_1670 = id_1687;
                                  }
                                  let_res_1667 = let_res_1670;
                                }
                                ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_1688 { std::get<12 /* Dashboards */>((*p_0)) };
                                std::string id_1689 { std::get<0>(id_1688) };
                                uint32_t id_1690 { (uint32_t)id_1689.size() };
                                Size id_1691 { Size(id_1690) };
                                Size id_1692 { Size(let_res_1667 + id_1691) };
                                Size id_1693 { Size(id_1662 + id_1692) };
                                Size let_res_1694;
                                {
                                  Size sz_702 { id_1693 };
                                  ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_1695 { std::get<12 /* Dashboards */>((*p_0)) };
                                  std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1696 { std::get<1>(id_1695) };
                                  Size id_1697 { per_dash_key_sersize_of_row_binary(id_1696) };
                                  Size id_1698 { Size(sz_702 + id_1697) };
                                  let_res_1694 = id_1698;
                                }
                                choose_res_1661 = let_res_1694;
                              } else {
                                uint16_t id_1699 { 13 };
                                bool id_1700 { bool(id_1699 == label2_683) };
                                Size choose_res_1701;
                                if (id_1700) {
                                  Size id_1702 { 2UL };
                                  choose_res_1701 = id_1702;
                                } else {
                                  uint16_t id_1703 { 14 };
                                  bool id_1704 { bool(id_1703 == label2_683) };
                                  Size choose_res_1705;
                                  if (id_1704) {
                                    Size id_1706 { 2UL };
                                    auto fun1707 { dessser::gen::team_name::sersize_of_row_binary };
                                    ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_1708 { std::get<14 /* Teams */>((*p_0)) };
                                    dessser::gen::team_name::t_ext id_1709 { std::get<0>(id_1708) };
                                    Size id_1710 { fun1707(id_1709) };
                                    Size id_1711 { Size(id_1706 + id_1710) };
                                    Size let_res_1712;
                                    {
                                      Size sz_690 { id_1711 };
                                      uint16_t id_1713 { 0 };
                                      ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_1714 { std::get<14 /* Teams */>((*p_0)) };
                                      ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_1715 { std::get<1>(id_1714) };
                                      uint16_t id_1716 { uint16_t(id_1715.index()) };
                                      bool id_1717 { bool(id_1713 == id_1716) };
                                      Size choose_res_1718;
                                      if (id_1717) {
                                        Size id_1719 { 2UL };
                                        Size id_1720 { Size(sz_690 + id_1719) };
                                        ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_1721 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_1722 { std::get<1>(id_1721) };
                                        std::string id_1723 { std::get<0 /* Contacts */>(id_1722) };
                                        uint32_t id_1724 { (uint32_t)id_1723.size() };
                                        Vec<1, uint32_t> id_1725 {  id_1724  };
                                        Size let_res_1726;
                                        {
                                          Vec<1, uint32_t> n_ref_696 { id_1725 };
                                          uint32_t id_1727 { 1U };
                                          Vec<1, uint32_t> id_1728 {  id_1727  };
                                          Size let_res_1729;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_697 { id_1728 };
                                            bool while_flag_1730 { true };
                                            do {
                                              uint8_t id_1731 { 0 };
                                              uint32_t id_1732 { n_ref_696[id_1731] };
                                              uint8_t id_1733 { 0 };
                                              uint32_t id_1734 { lebsz_ref_697[id_1733] };
                                              uint8_t id_1735 { 7 };
                                              uint32_t id_1736 { uint32_t(id_1734 << id_1735) };
                                              bool id_1737 { bool(id_1732 >= id_1736) };
                                              while_flag_1730 = id_1737;
                                              if (while_flag_1730) {
                                                uint8_t id_1738 { 0 };
                                                uint8_t id_1739 { 0 };
                                                uint32_t id_1740 { lebsz_ref_697[id_1739] };
                                                uint32_t id_1741 { 1U };
                                                uint32_t id_1742 { uint32_t(id_1740 + id_1741) };
                                                Void id_1743 { ((void)(lebsz_ref_697[id_1738] = id_1742), ::dessser::VOID) };
                                                (void)id_1743;
                                              }
                                            } while (while_flag_1730);
                                            (void)::dessser::VOID;
                                            uint8_t id_1744 { 0 };
                                            uint32_t id_1745 { lebsz_ref_697[id_1744] };
                                            Size id_1746 { Size(id_1745) };
                                            let_res_1729 = id_1746;
                                          }
                                          let_res_1726 = let_res_1729;
                                        }
                                        ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_1747 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_1748 { std::get<1>(id_1747) };
                                        std::string id_1749 { std::get<0 /* Contacts */>(id_1748) };
                                        uint32_t id_1750 { (uint32_t)id_1749.size() };
                                        Size id_1751 { Size(id_1750) };
                                        Size id_1752 { Size(let_res_1726 + id_1751) };
                                        Size id_1753 { Size(id_1720 + id_1752) };
                                        choose_res_1718 = id_1753;
                                      } else {
                                        ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_1754 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_1755 { std::get<1>(id_1754) };
                                        uint16_t id_1756 { uint16_t(id_1755.index()) };
                                        uint16_t id_1757 { 1 };
                                        bool id_1758 { bool(id_1756 == id_1757) };
                                        Void id_1759 { ((void)(assert(id_1758)), ::dessser::VOID) };
                                        (void)id_1759;
                                        Size id_1760 { 2UL };
                                        Size id_1761 { Size(sz_690 + id_1760) };
                                        ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_1762 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_1763 { std::get<1>(id_1762) };
                                        std::string id_1764 { std::get<1 /* Inhibition */>(id_1763) };
                                        uint32_t id_1765 { (uint32_t)id_1764.size() };
                                        Vec<1, uint32_t> id_1766 {  id_1765  };
                                        Size let_res_1767;
                                        {
                                          Vec<1, uint32_t> n_ref_693 { id_1766 };
                                          uint32_t id_1768 { 1U };
                                          Vec<1, uint32_t> id_1769 {  id_1768  };
                                          Size let_res_1770;
                                          {
                                            Vec<1, uint32_t> lebsz_ref_694 { id_1769 };
                                            bool while_flag_1771 { true };
                                            do {
                                              uint8_t id_1772 { 0 };
                                              uint32_t id_1773 { n_ref_693[id_1772] };
                                              uint8_t id_1774 { 0 };
                                              uint32_t id_1775 { lebsz_ref_694[id_1774] };
                                              uint8_t id_1776 { 7 };
                                              uint32_t id_1777 { uint32_t(id_1775 << id_1776) };
                                              bool id_1778 { bool(id_1773 >= id_1777) };
                                              while_flag_1771 = id_1778;
                                              if (while_flag_1771) {
                                                uint8_t id_1779 { 0 };
                                                uint8_t id_1780 { 0 };
                                                uint32_t id_1781 { lebsz_ref_694[id_1780] };
                                                uint32_t id_1782 { 1U };
                                                uint32_t id_1783 { uint32_t(id_1781 + id_1782) };
                                                Void id_1784 { ((void)(lebsz_ref_694[id_1779] = id_1783), ::dessser::VOID) };
                                                (void)id_1784;
                                              }
                                            } while (while_flag_1771);
                                            (void)::dessser::VOID;
                                            uint8_t id_1785 { 0 };
                                            uint32_t id_1786 { lebsz_ref_694[id_1785] };
                                            Size id_1787 { Size(id_1786) };
                                            let_res_1770 = id_1787;
                                          }
                                          let_res_1767 = let_res_1770;
                                        }
                                        ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_1788 { std::get<14 /* Teams */>((*p_0)) };
                                        ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_1789 { std::get<1>(id_1788) };
                                        std::string id_1790 { std::get<1 /* Inhibition */>(id_1789) };
                                        uint32_t id_1791 { (uint32_t)id_1790.size() };
                                        Size id_1792 { Size(id_1791) };
                                        Size id_1793 { Size(let_res_1767 + id_1792) };
                                        Size id_1794 { Size(id_1761 + id_1793) };
                                        choose_res_1718 = id_1794;
                                      }
                                      let_res_1712 = choose_res_1718;
                                    }
                                    choose_res_1705 = let_res_1712;
                                  } else {
                                    uint16_t id_1795 { 15 };
                                    bool id_1796 { bool(label2_683 == id_1795) };
                                    Void id_1797 { ((void)(assert(id_1796)), ::dessser::VOID) };
                                    (void)id_1797;
                                    Size id_1798 { 2UL };
                                    ::dessser::gen::sync_key::tdce75d0a7767ecd39280979e2e5897b1 id_1799 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1800 { std::get<0>(id_1799) };
                                    uint32_t id_1801 { (uint32_t)id_1800.size() };
                                    Vec<1, uint32_t> id_1802 {  id_1801  };
                                    Size let_res_1803;
                                    {
                                      Vec<1, uint32_t> n_ref_686 { id_1802 };
                                      uint32_t id_1804 { 1U };
                                      Vec<1, uint32_t> id_1805 {  id_1804  };
                                      Size let_res_1806;
                                      {
                                        Vec<1, uint32_t> lebsz_ref_687 { id_1805 };
                                        bool while_flag_1807 { true };
                                        do {
                                          uint8_t id_1808 { 0 };
                                          uint32_t id_1809 { n_ref_686[id_1808] };
                                          uint8_t id_1810 { 0 };
                                          uint32_t id_1811 { lebsz_ref_687[id_1810] };
                                          uint8_t id_1812 { 7 };
                                          uint32_t id_1813 { uint32_t(id_1811 << id_1812) };
                                          bool id_1814 { bool(id_1809 >= id_1813) };
                                          while_flag_1807 = id_1814;
                                          if (while_flag_1807) {
                                            uint8_t id_1815 { 0 };
                                            uint8_t id_1816 { 0 };
                                            uint32_t id_1817 { lebsz_ref_687[id_1816] };
                                            uint32_t id_1818 { 1U };
                                            uint32_t id_1819 { uint32_t(id_1817 + id_1818) };
                                            Void id_1820 { ((void)(lebsz_ref_687[id_1815] = id_1819), ::dessser::VOID) };
                                            (void)id_1820;
                                          }
                                        } while (while_flag_1807);
                                        (void)::dessser::VOID;
                                        uint8_t id_1821 { 0 };
                                        uint32_t id_1822 { lebsz_ref_687[id_1821] };
                                        Size id_1823 { Size(id_1822) };
                                        let_res_1806 = id_1823;
                                      }
                                      let_res_1803 = let_res_1806;
                                    }
                                    ::dessser::gen::sync_key::tdce75d0a7767ecd39280979e2e5897b1 id_1824 { std::get<15 /* Incidents */>((*p_0)) };
                                    std::string id_1825 { std::get<0>(id_1824) };
                                    uint32_t id_1826 { (uint32_t)id_1825.size() };
                                    Size id_1827 { Size(id_1826) };
                                    Size id_1828 { Size(let_res_1803 + id_1827) };
                                    Size id_1829 { Size(id_1798 + id_1828) };
                                    Size let_res_1830;
                                    {
                                      Size sz_688 { id_1829 };
                                      ::dessser::gen::sync_key::tdce75d0a7767ecd39280979e2e5897b1 id_1831 { std::get<15 /* Incidents */>((*p_0)) };
                                      std::shared_ptr<::dessser::gen::sync_key::incident_key>  id_1832 { std::get<1>(id_1831) };
                                      Size id_1833 { incident_key_sersize_of_row_binary(id_1832) };
                                      Size id_1834 { Size(sz_688 + id_1833) };
                                      let_res_1830 = id_1834;
                                    }
                                    choose_res_1705 = let_res_1830;
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
                  choose_res_1513 = choose_res_1520;
                }
                choose_res_1509 = choose_res_1513;
              }
              choose_res_1468 = choose_res_1509;
            }
            choose_res_1435 = choose_res_1468;
          }
          choose_res_1431 = choose_res_1435;
        }
        choose_res_1427 = choose_res_1431;
      }
      let_res_1424 = choose_res_1427;
    }
    return let_res_1424;
  }
   };
  return fun1422;
}
std::function<Size(std::shared_ptr<::dessser::gen::sync_key::t> )> sersize_of_row_binary(sersize_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_320" (let-pair "du16_fst_315" "du16_snd_316" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_315") (identifier "du16_snd_316")))
        (let-pair "dsum1_fst_321" "dsum1_snd_322" (identifier "dsum1_320")
          (if (eq (u16 0) (identifier "dsum1_fst_321"))
            (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 0 (nop)) (identifier "dsum1_snd_322"))
            (if (eq (u16 1) (identifier "dsum1_fst_321"))
              (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 1 (nop)) (identifier "dsum1_snd_322"))
              (if (eq (u16 2) (identifier "dsum1_fst_321"))
                (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 2 (nop)) (identifier "dsum1_snd_322"))
                (if (eq (u16 3) (identifier "dsum1_fst_321"))
                  (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 3 (nop))
                    (identifier "dsum1_snd_322"))
                  (if (eq (u16 4) (identifier "dsum1_fst_321"))
                    (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 4 (nop))
                      (identifier "dsum1_snd_322"))
                    (if (eq (u16 5) (identifier "dsum1_fst_321"))
                      (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 5 (nop))
                        (identifier "dsum1_snd_322"))
                      (seq (assert (eq (identifier "dsum1_fst_321") (u16 6)))
                        (make-tup (construct "[NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void]" 6 (nop))
                          (identifier "dsum1_snd_322"))))))))))))
 */
static std::function<::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1(Pointer)> dialog_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1(Pointer)> fun1835 { [&fun1835](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1836 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1837;
    {
      auto du16_fst_315 { std::get<0>(id_1836) };
      auto du16_snd_316 { std::get<1>(id_1836) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1838 { du16_fst_315, du16_snd_316 };
      letpair_res_1837 = id_1838;
    }
    ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 let_res_1839;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_320 { letpair_res_1837 };
      ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 letpair_res_1840;
      {
        auto dsum1_fst_321 { std::get<0>(dsum1_320) };
        auto dsum1_snd_322 { std::get<1>(dsum1_320) };
        uint16_t id_1841 { 0 };
        bool id_1842 { bool(id_1841 == dsum1_fst_321) };
        ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 choose_res_1843;
        if (id_1842) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::dialog_key>  id_1844 { std::make_shared<::dessser::gen::sync_key::dialog_key>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 id_1845 { id_1844, dsum1_snd_322 };
          choose_res_1843 = id_1845;
        } else {
          uint16_t id_1846 { 1 };
          bool id_1847 { bool(id_1846 == dsum1_fst_321) };
          ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 choose_res_1848;
          if (id_1847) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::sync_key::dialog_key>  id_1849 { std::make_shared<::dessser::gen::sync_key::dialog_key>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 id_1850 { id_1849, dsum1_snd_322 };
            choose_res_1848 = id_1850;
          } else {
            uint16_t id_1851 { 2 };
            bool id_1852 { bool(id_1851 == dsum1_fst_321) };
            ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 choose_res_1853;
            if (id_1852) {
              (void)::dessser::VOID;
              std::shared_ptr<::dessser::gen::sync_key::dialog_key>  id_1854 { std::make_shared<::dessser::gen::sync_key::dialog_key>(std::in_place_index<2>, ::dessser::VOID) };
              ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 id_1855 { id_1854, dsum1_snd_322 };
              choose_res_1853 = id_1855;
            } else {
              uint16_t id_1856 { 3 };
              bool id_1857 { bool(id_1856 == dsum1_fst_321) };
              ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 choose_res_1858;
              if (id_1857) {
                (void)::dessser::VOID;
                std::shared_ptr<::dessser::gen::sync_key::dialog_key>  id_1859 { std::make_shared<::dessser::gen::sync_key::dialog_key>(std::in_place_index<3>, ::dessser::VOID) };
                ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 id_1860 { id_1859, dsum1_snd_322 };
                choose_res_1858 = id_1860;
              } else {
                uint16_t id_1861 { 4 };
                bool id_1862 { bool(id_1861 == dsum1_fst_321) };
                ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 choose_res_1863;
                if (id_1862) {
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::sync_key::dialog_key>  id_1864 { std::make_shared<::dessser::gen::sync_key::dialog_key>(std::in_place_index<4>, ::dessser::VOID) };
                  ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 id_1865 { id_1864, dsum1_snd_322 };
                  choose_res_1863 = id_1865;
                } else {
                  uint16_t id_1866 { 5 };
                  bool id_1867 { bool(id_1866 == dsum1_fst_321) };
                  ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 choose_res_1868;
                  if (id_1867) {
                    (void)::dessser::VOID;
                    std::shared_ptr<::dessser::gen::sync_key::dialog_key>  id_1869 { std::make_shared<::dessser::gen::sync_key::dialog_key>(std::in_place_index<5>, ::dessser::VOID) };
                    ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 id_1870 { id_1869, dsum1_snd_322 };
                    choose_res_1868 = id_1870;
                  } else {
                    uint16_t id_1871 { 6 };
                    bool id_1872 { bool(dsum1_fst_321 == id_1871) };
                    Void id_1873 { ((void)(assert(id_1872)), ::dessser::VOID) };
                    (void)id_1873;
                    (void)::dessser::VOID;
                    std::shared_ptr<::dessser::gen::sync_key::dialog_key>  id_1874 { std::make_shared<::dessser::gen::sync_key::dialog_key>(std::in_place_index<6>, ::dessser::VOID) };
                    ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 id_1875 { id_1874, dsum1_snd_322 };
                    choose_res_1868 = id_1875;
                  }
                  choose_res_1863 = choose_res_1868;
                }
                choose_res_1858 = choose_res_1863;
              }
              choose_res_1853 = choose_res_1858;
            }
            choose_res_1848 = choose_res_1853;
          }
          choose_res_1843 = choose_res_1848;
        }
        letpair_res_1840 = choose_res_1843;
      }
      let_res_1839 = letpair_res_1840;
    }
    return let_res_1839;
  }
   };
  return fun1835;
}
std::function<::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1(Pointer)> dialog_key_of_row_binary(dialog_key_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_350" (let-pair "du16_fst_345" "du16_snd_346" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_345") (identifier "du16_snd_346")))
        (let-pair "dsum1_fst_351" "dsum1_snd_352" (identifier "dsum1_350")
          (if (eq (u16 0) (identifier "dsum1_fst_351"))
            (make-tup
              (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 0
                (nop)) (identifier "dsum1_snd_352"))
            (if (eq (u16 1) (identifier "dsum1_fst_351"))
              (make-tup
                (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 1
                  (nop)) (identifier "dsum1_snd_352"))
              (if (eq (u16 2) (identifier "dsum1_fst_351"))
                (make-tup
                  (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 2
                    (nop)) (identifier "dsum1_snd_352"))
                (if (eq (u16 3) (identifier "dsum1_fst_351"))
                  (make-tup
                    (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 3
                      (nop)) (identifier "dsum1_snd_352"))
                  (if (eq (u16 4) (identifier "dsum1_fst_351"))
                    (make-tup
                      (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 4
                        (nop)) (identifier "dsum1_snd_352"))
                    (if (eq (u16 5) (identifier "dsum1_fst_351"))
                      (let "dtup_380"
                        (let "dstring1_374"
                          (let "leb_ref_368" (make-vec (u32 0))
                            (let "shft_ref_369" (make-vec (u8 0))
                              (let "p_ref_370" (make-vec (identifier "dsum1_snd_352"))
                                (seq
                                  (while
                                    (let "leb128_371" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_370")))
                                      (let-pair "leb128_fst_372" "leb128_snd_373" 
                                        (identifier "leb128_371")
                                        (seq (set-vec (u8 0) (identifier "p_ref_370") (identifier "leb128_snd_373"))
                                          (set-vec (u8 0) (identifier "leb_ref_368")
                                            (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_372") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_369"))) (unsafe-nth (u8 0) (identifier "leb_ref_368"))))
                                          (set-vec (u8 0) (identifier "shft_ref_369") (add (unsafe-nth (u8 0) (identifier "shft_ref_369")) (u8 7))) 
                                          (ge (identifier "leb128_fst_372") (u8 128))))) 
                                    (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_368"))) (unsafe-nth (u8 0) (identifier "p_ref_370")))))))
                          (let-pair "dstring1_fst_375" "dstring1_snd_376" 
                            (identifier "dstring1_374")
                            (let-pair "dstring2_fst_378" "dstring2_snd_379" 
                              (read-bytes (identifier "dstring1_snd_376") (identifier "dstring1_fst_375")) 
                              (make-tup (string-of-bytes (identifier "dstring2_fst_378")) (identifier "dstring2_snd_379")))))
                        (let-pair "dtup_fst_381" "dtup_snd_382" (identifier "dtup_380")
                          (let-pair "dtup_fst_384" "dtup_snd_385" (apply (identifier "dialog_key-of-row-binary") (identifier "dtup_snd_382"))
                            (make-tup
                              (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 5
                                (make-tup (identifier "dtup_fst_381") (identifier "dtup_fst_384"))) 
                              (identifier "dtup_snd_385")))))
                      (seq (assert (eq (identifier "dsum1_fst_351") (u16 6)))
                        (let "dtup_356" (let-pair "dfloat_fst_354" "dfloat_snd_355" (read-u64 little-endian (identifier "dsum1_snd_352")) (make-tup (float-of-u64 (identifier "dfloat_fst_354")) (identifier "dfloat_snd_355")))
                          (let-pair "dtup_fst_357" "dtup_snd_358" (identifier "dtup_356")
                            (let-pair "du32_fst_360" "du32_snd_361" (read-u32 little-endian (identifier "dtup_snd_358"))
                              (make-tup
                                (construct "[FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]" 6
                                  (make-tup (identifier "dtup_fst_357") (identifier "du32_fst_360"))) 
                                (identifier "du32_snd_361")))))))))))))))
 */
static std::function<::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d(Pointer)> incident_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d(Pointer)> fun1876 { [&fun1876](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1877 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1878;
    {
      auto du16_fst_345 { std::get<0>(id_1877) };
      auto du16_snd_346 { std::get<1>(id_1877) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1879 { du16_fst_345, du16_snd_346 };
      letpair_res_1878 = id_1879;
    }
    ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d let_res_1880;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_350 { letpair_res_1878 };
      ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d letpair_res_1881;
      {
        auto dsum1_fst_351 { std::get<0>(dsum1_350) };
        auto dsum1_snd_352 { std::get<1>(dsum1_350) };
        uint16_t id_1882 { 0 };
        bool id_1883 { bool(id_1882 == dsum1_fst_351) };
        ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d choose_res_1884;
        if (id_1883) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::incident_key>  id_1885 { std::make_shared<::dessser::gen::sync_key::incident_key>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d id_1886 { id_1885, dsum1_snd_352 };
          choose_res_1884 = id_1886;
        } else {
          uint16_t id_1887 { 1 };
          bool id_1888 { bool(id_1887 == dsum1_fst_351) };
          ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d choose_res_1889;
          if (id_1888) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::sync_key::incident_key>  id_1890 { std::make_shared<::dessser::gen::sync_key::incident_key>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d id_1891 { id_1890, dsum1_snd_352 };
            choose_res_1889 = id_1891;
          } else {
            uint16_t id_1892 { 2 };
            bool id_1893 { bool(id_1892 == dsum1_fst_351) };
            ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d choose_res_1894;
            if (id_1893) {
              (void)::dessser::VOID;
              std::shared_ptr<::dessser::gen::sync_key::incident_key>  id_1895 { std::make_shared<::dessser::gen::sync_key::incident_key>(std::in_place_index<2>, ::dessser::VOID) };
              ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d id_1896 { id_1895, dsum1_snd_352 };
              choose_res_1894 = id_1896;
            } else {
              uint16_t id_1897 { 3 };
              bool id_1898 { bool(id_1897 == dsum1_fst_351) };
              ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d choose_res_1899;
              if (id_1898) {
                (void)::dessser::VOID;
                std::shared_ptr<::dessser::gen::sync_key::incident_key>  id_1900 { std::make_shared<::dessser::gen::sync_key::incident_key>(std::in_place_index<3>, ::dessser::VOID) };
                ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d id_1901 { id_1900, dsum1_snd_352 };
                choose_res_1899 = id_1901;
              } else {
                uint16_t id_1902 { 4 };
                bool id_1903 { bool(id_1902 == dsum1_fst_351) };
                ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d choose_res_1904;
                if (id_1903) {
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::sync_key::incident_key>  id_1905 { std::make_shared<::dessser::gen::sync_key::incident_key>(std::in_place_index<4>, ::dessser::VOID) };
                  ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d id_1906 { id_1905, dsum1_snd_352 };
                  choose_res_1904 = id_1906;
                } else {
                  uint16_t id_1907 { 5 };
                  bool id_1908 { bool(id_1907 == dsum1_fst_351) };
                  ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d choose_res_1909;
                  if (id_1908) {
                    uint32_t id_1910 { 0U };
                    Vec<1, uint32_t> id_1911 {  id_1910  };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1912;
                    {
                      Vec<1, uint32_t> leb_ref_368 { id_1911 };
                      uint8_t id_1913 { 0 };
                      Vec<1, uint8_t> id_1914 {  id_1913  };
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1915;
                      {
                        Vec<1, uint8_t> shft_ref_369 { id_1914 };
                        Vec<1, Pointer> id_1916 {  dsum1_snd_352  };
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_1917;
                        {
                          Vec<1, Pointer> p_ref_370 { id_1916 };
                          bool while_flag_1918 { true };
                          do {
                            uint8_t id_1919 { 0 };
                            Pointer id_1920 { p_ref_370[id_1919] };
                            ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_1921 { id_1920.readU8() };
                            bool let_res_1922;
                            {
                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_371 { id_1921 };
                              bool letpair_res_1923;
                              {
                                auto leb128_fst_372 { std::get<0>(leb128_371) };
                                auto leb128_snd_373 { std::get<1>(leb128_371) };
                                uint8_t id_1924 { 0 };
                                Void id_1925 { ((void)(p_ref_370[id_1924] = leb128_snd_373), ::dessser::VOID) };
                                (void)id_1925;
                                uint8_t id_1926 { 0 };
                                uint8_t id_1927 { 127 };
                                uint8_t id_1928 { uint8_t(leb128_fst_372 & id_1927) };
                                uint32_t id_1929 { uint32_t(id_1928) };
                                uint8_t id_1930 { 0 };
                                uint8_t id_1931 { shft_ref_369[id_1930] };
                                uint32_t id_1932 { uint32_t(id_1929 << id_1931) };
                                uint8_t id_1933 { 0 };
                                uint32_t id_1934 { leb_ref_368[id_1933] };
                                uint32_t id_1935 { uint32_t(id_1932 | id_1934) };
                                Void id_1936 { ((void)(leb_ref_368[id_1926] = id_1935), ::dessser::VOID) };
                                (void)id_1936;
                                uint8_t id_1937 { 0 };
                                uint8_t id_1938 { 0 };
                                uint8_t id_1939 { shft_ref_369[id_1938] };
                                uint8_t id_1940 { 7 };
                                uint8_t id_1941 { uint8_t(id_1939 + id_1940) };
                                Void id_1942 { ((void)(shft_ref_369[id_1937] = id_1941), ::dessser::VOID) };
                                (void)id_1942;
                                uint8_t id_1943 { 128 };
                                bool id_1944 { bool(leb128_fst_372 >= id_1943) };
                                letpair_res_1923 = id_1944;
                              }
                              let_res_1922 = letpair_res_1923;
                            }
                            while_flag_1918 = let_res_1922;
                            if (while_flag_1918) {
                              (void)::dessser::VOID;
                            }
                          } while (while_flag_1918);
                          (void)::dessser::VOID;
                          uint8_t id_1945 { 0 };
                          uint32_t id_1946 { leb_ref_368[id_1945] };
                          Size id_1947 { Size(id_1946) };
                          uint8_t id_1948 { 0 };
                          Pointer id_1949 { p_ref_370[id_1948] };
                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_1950 { id_1947, id_1949 };
                          let_res_1917 = id_1950;
                        }
                        let_res_1915 = let_res_1917;
                      }
                      let_res_1912 = let_res_1915;
                    }
                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_1951;
                    {
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_374 { let_res_1912 };
                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_1952;
                      {
                        auto dstring1_fst_375 { std::get<0>(dstring1_374) };
                        auto dstring1_snd_376 { std::get<1>(dstring1_374) };
                        ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_1953 { dstring1_snd_376.readBytes(dstring1_fst_375) };
                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_1954;
                        {
                          auto dstring2_fst_378 { std::get<0>(id_1953) };
                          auto dstring2_snd_379 { std::get<1>(id_1953) };
                          std::string id_1955 { dstring2_fst_378.toString() };
                          ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_1956 { id_1955, dstring2_snd_379 };
                          letpair_res_1954 = id_1956;
                        }
                        letpair_res_1952 = letpair_res_1954;
                      }
                      let_res_1951 = letpair_res_1952;
                    }
                    ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d let_res_1957;
                    {
                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_380 { let_res_1951 };
                      ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d letpair_res_1958;
                      {
                        auto dtup_fst_381 { std::get<0>(dtup_380) };
                        auto dtup_snd_382 { std::get<1>(dtup_380) };
                        ::dessser::gen::sync_key::t4585ac1860331d8d8108dff115815fc1 id_1959 { dialog_key_of_row_binary(dtup_snd_382) };
                        ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d letpair_res_1960;
                        {
                          auto dtup_fst_384 { std::get<0>(id_1959) };
                          auto dtup_snd_385 { std::get<1>(id_1959) };
                          ::dessser::gen::sync_key::t64c0474e57c610aaa3e07cb04692cefe id_1961 { dtup_fst_381, dtup_fst_384 };
                          std::shared_ptr<::dessser::gen::sync_key::incident_key>  id_1962 { std::make_shared<::dessser::gen::sync_key::incident_key>(std::in_place_index<5>, id_1961) };
                          ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d id_1963 { id_1962, dtup_snd_385 };
                          letpair_res_1960 = id_1963;
                        }
                        letpair_res_1958 = letpair_res_1960;
                      }
                      let_res_1957 = letpair_res_1958;
                    }
                    choose_res_1909 = let_res_1957;
                  } else {
                    uint16_t id_1964 { 6 };
                    bool id_1965 { bool(dsum1_fst_351 == id_1964) };
                    Void id_1966 { ((void)(assert(id_1965)), ::dessser::VOID) };
                    (void)id_1966;
                    ::dessser::gen::sync_key::td2cd337bb3c8bc04d5603393d084985b id_1967 { dsum1_snd_352.readU64Le() };
                    ::dessser::gen::sync_key::t9a758baeff17224a77e1a522010b4168 letpair_res_1968;
                    {
                      auto dfloat_fst_354 { std::get<0>(id_1967) };
                      auto dfloat_snd_355 { std::get<1>(id_1967) };
                      double id_1969 { float_of_qword(dfloat_fst_354) };
                      ::dessser::gen::sync_key::t9a758baeff17224a77e1a522010b4168 id_1970 { id_1969, dfloat_snd_355 };
                      letpair_res_1968 = id_1970;
                    }
                    ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d let_res_1971;
                    {
                      ::dessser::gen::sync_key::t9a758baeff17224a77e1a522010b4168 dtup_356 { letpair_res_1968 };
                      ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d letpair_res_1972;
                      {
                        auto dtup_fst_357 { std::get<0>(dtup_356) };
                        auto dtup_snd_358 { std::get<1>(dtup_356) };
                        ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_1973 { dtup_snd_358.readU32Le() };
                        ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d letpair_res_1974;
                        {
                          auto du32_fst_360 { std::get<0>(id_1973) };
                          auto du32_snd_361 { std::get<1>(id_1973) };
                          ::dessser::gen::sync_key::taf1e37f579ece7fa9db5670cfd23039b id_1975 { dtup_fst_357, du32_fst_360 };
                          std::shared_ptr<::dessser::gen::sync_key::incident_key>  id_1976 { std::make_shared<::dessser::gen::sync_key::incident_key>(std::in_place_index<6>, id_1975) };
                          ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d id_1977 { id_1976, du32_snd_361 };
                          letpair_res_1974 = id_1977;
                        }
                        letpair_res_1972 = letpair_res_1974;
                      }
                      let_res_1971 = letpair_res_1972;
                    }
                    choose_res_1909 = let_res_1971;
                  }
                  choose_res_1904 = choose_res_1909;
                }
                choose_res_1899 = choose_res_1904;
              }
              choose_res_1894 = choose_res_1899;
            }
            choose_res_1889 = choose_res_1894;
          }
          choose_res_1884 = choose_res_1889;
        }
        letpair_res_1881 = choose_res_1884;
      }
      let_res_1880 = letpair_res_1881;
    }
    return let_res_1880;
  }
   };
  return fun1876;
}
std::function<::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d(Pointer)> incident_key_of_row_binary(incident_key_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_278" (let-pair "du16_fst_273" "du16_snd_274" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_273") (identifier "du16_snd_274")))
        (let-pair "dsum1_fst_279" "dsum1_snd_280" (identifier "dsum1_278")
          (seq (assert (eq (identifier "dsum1_fst_279") (u16 0)))
            (let-pair "du32_fst_282" "du32_snd_283" (read-u32 little-endian (identifier "dsum1_snd_280")) (make-tup (construct "[Widgets U32]" 0 (identifier "du32_fst_282")) (identifier "du32_snd_283")))))))
 */
static std::function<::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713(Pointer)> per_dash_key_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713(Pointer)> fun1978 { [&fun1978](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1979 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1980;
    {
      auto du16_fst_273 { std::get<0>(id_1979) };
      auto du16_snd_274 { std::get<1>(id_1979) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1981 { du16_fst_273, du16_snd_274 };
      letpair_res_1980 = id_1981;
    }
    ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 let_res_1982;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_278 { letpair_res_1980 };
      ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 letpair_res_1983;
      {
        auto dsum1_fst_279 { std::get<0>(dsum1_278) };
        auto dsum1_snd_280 { std::get<1>(dsum1_278) };
        uint16_t id_1984 { 0 };
        bool id_1985 { bool(dsum1_fst_279 == id_1984) };
        Void id_1986 { ((void)(assert(id_1985)), ::dessser::VOID) };
        (void)id_1986;
        ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_1987 { dsum1_snd_280.readU32Le() };
        ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 letpair_res_1988;
        {
          auto du32_fst_282 { std::get<0>(id_1987) };
          auto du32_snd_283 { std::get<1>(id_1987) };
          std::shared_ptr<::dessser::gen::sync_key::per_dash_key>  id_1989 { std::make_shared<::dessser::gen::sync_key::per_dash_key>(std::in_place_index<0>, du32_fst_282) };
          ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 id_1990 { id_1989, du32_snd_283 };
          letpair_res_1988 = id_1990;
        }
        letpair_res_1983 = letpair_res_1988;
      }
      let_res_1982 = letpair_res_1983;
    }
    return let_res_1982;
  }
   };
  return fun1978;
}
std::function<::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713(Pointer)> per_dash_key_of_row_binary(per_dash_key_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_293" (let-pair "du16_fst_288" "du16_snd_289" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_288") (identifier "du16_snd_289")))
        (let-pair "dsum1_fst_294" "dsum1_snd_295" (identifier "dsum1_293")
          (if (eq (u16 0) (identifier "dsum1_fst_294"))
            (let "dstring1_305"
              (let "leb_ref_299" (make-vec (u32 0))
                (let "shft_ref_300" (make-vec (u8 0))
                  (let "p_ref_301" (make-vec (identifier "dsum1_snd_295"))
                    (seq
                      (while
                        (let "leb128_302" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_301")))
                          (let-pair "leb128_fst_303" "leb128_snd_304" 
                            (identifier "leb128_302")
                            (seq (set-vec (u8 0) (identifier "p_ref_301") (identifier "leb128_snd_304"))
                              (set-vec (u8 0) (identifier "leb_ref_299")
                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_303") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_300"))) (unsafe-nth (u8 0) (identifier "leb_ref_299"))))
                              (set-vec (u8 0) (identifier "shft_ref_300") (add (unsafe-nth (u8 0) (identifier "shft_ref_300")) (u8 7))) 
                              (ge (identifier "leb128_fst_303") (u8 128))))) 
                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_299"))) (unsafe-nth (u8 0) (identifier "p_ref_301")))))))
              (let-pair "dstring1_fst_306" "dstring1_snd_307" (identifier "dstring1_305")
                (let-pair "dstring2_fst_309" "dstring2_snd_310" (read-bytes (identifier "dstring1_snd_307") (identifier "dstring1_fst_306"))
                  (make-tup (construct "[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" 0 (string-of-bytes (identifier "dstring2_fst_309"))) (identifier "dstring2_snd_310")))))
            (seq (assert (eq (identifier "dsum1_fst_294") (u16 1)))
              (let-pair "dsum2_fst_297" "dsum2_snd_298" (apply (identifier "per_dash_key-of-row-binary") (identifier "dsum1_snd_295"))
                (make-tup (construct "[Response STRING | Scratchpad (per_dash_key AS [Widgets U32])]" 1 (identifier "dsum2_fst_297")) (identifier "dsum2_snd_298"))))))))
 */
static std::function<::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796(Pointer)> per_client_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796(Pointer)> fun1991 { [&fun1991](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1992 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_1993;
    {
      auto du16_fst_288 { std::get<0>(id_1992) };
      auto du16_snd_289 { std::get<1>(id_1992) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_1994 { du16_fst_288, du16_snd_289 };
      letpair_res_1993 = id_1994;
    }
    ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 let_res_1995;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_293 { letpair_res_1993 };
      ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 letpair_res_1996;
      {
        auto dsum1_fst_294 { std::get<0>(dsum1_293) };
        auto dsum1_snd_295 { std::get<1>(dsum1_293) };
        uint16_t id_1997 { 0 };
        bool id_1998 { bool(id_1997 == dsum1_fst_294) };
        ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 choose_res_1999;
        if (id_1998) {
          uint32_t id_2000 { 0U };
          Vec<1, uint32_t> id_2001 {  id_2000  };
          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2002;
          {
            Vec<1, uint32_t> leb_ref_299 { id_2001 };
            uint8_t id_2003 { 0 };
            Vec<1, uint8_t> id_2004 {  id_2003  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2005;
            {
              Vec<1, uint8_t> shft_ref_300 { id_2004 };
              Vec<1, Pointer> id_2006 {  dsum1_snd_295  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2007;
              {
                Vec<1, Pointer> p_ref_301 { id_2006 };
                bool while_flag_2008 { true };
                do {
                  uint8_t id_2009 { 0 };
                  Pointer id_2010 { p_ref_301[id_2009] };
                  ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2011 { id_2010.readU8() };
                  bool let_res_2012;
                  {
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_302 { id_2011 };
                    bool letpair_res_2013;
                    {
                      auto leb128_fst_303 { std::get<0>(leb128_302) };
                      auto leb128_snd_304 { std::get<1>(leb128_302) };
                      uint8_t id_2014 { 0 };
                      Void id_2015 { ((void)(p_ref_301[id_2014] = leb128_snd_304), ::dessser::VOID) };
                      (void)id_2015;
                      uint8_t id_2016 { 0 };
                      uint8_t id_2017 { 127 };
                      uint8_t id_2018 { uint8_t(leb128_fst_303 & id_2017) };
                      uint32_t id_2019 { uint32_t(id_2018) };
                      uint8_t id_2020 { 0 };
                      uint8_t id_2021 { shft_ref_300[id_2020] };
                      uint32_t id_2022 { uint32_t(id_2019 << id_2021) };
                      uint8_t id_2023 { 0 };
                      uint32_t id_2024 { leb_ref_299[id_2023] };
                      uint32_t id_2025 { uint32_t(id_2022 | id_2024) };
                      Void id_2026 { ((void)(leb_ref_299[id_2016] = id_2025), ::dessser::VOID) };
                      (void)id_2026;
                      uint8_t id_2027 { 0 };
                      uint8_t id_2028 { 0 };
                      uint8_t id_2029 { shft_ref_300[id_2028] };
                      uint8_t id_2030 { 7 };
                      uint8_t id_2031 { uint8_t(id_2029 + id_2030) };
                      Void id_2032 { ((void)(shft_ref_300[id_2027] = id_2031), ::dessser::VOID) };
                      (void)id_2032;
                      uint8_t id_2033 { 128 };
                      bool id_2034 { bool(leb128_fst_303 >= id_2033) };
                      letpair_res_2013 = id_2034;
                    }
                    let_res_2012 = letpair_res_2013;
                  }
                  while_flag_2008 = let_res_2012;
                  if (while_flag_2008) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_2008);
                (void)::dessser::VOID;
                uint8_t id_2035 { 0 };
                uint32_t id_2036 { leb_ref_299[id_2035] };
                Size id_2037 { Size(id_2036) };
                uint8_t id_2038 { 0 };
                Pointer id_2039 { p_ref_301[id_2038] };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2040 { id_2037, id_2039 };
                let_res_2007 = id_2040;
              }
              let_res_2005 = let_res_2007;
            }
            let_res_2002 = let_res_2005;
          }
          ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 let_res_2041;
          {
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_305 { let_res_2002 };
            ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 letpair_res_2042;
            {
              auto dstring1_fst_306 { std::get<0>(dstring1_305) };
              auto dstring1_snd_307 { std::get<1>(dstring1_305) };
              ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2043 { dstring1_snd_307.readBytes(dstring1_fst_306) };
              ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 letpair_res_2044;
              {
                auto dstring2_fst_309 { std::get<0>(id_2043) };
                auto dstring2_snd_310 { std::get<1>(id_2043) };
                std::string id_2045 { dstring2_fst_309.toString() };
                std::shared_ptr<::dessser::gen::sync_key::per_client>  id_2046 { std::make_shared<::dessser::gen::sync_key::per_client>(std::in_place_index<0>, id_2045) };
                ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 id_2047 { id_2046, dstring2_snd_310 };
                letpair_res_2044 = id_2047;
              }
              letpair_res_2042 = letpair_res_2044;
            }
            let_res_2041 = letpair_res_2042;
          }
          choose_res_1999 = let_res_2041;
        } else {
          uint16_t id_2048 { 1 };
          bool id_2049 { bool(dsum1_fst_294 == id_2048) };
          Void id_2050 { ((void)(assert(id_2049)), ::dessser::VOID) };
          (void)id_2050;
          ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 id_2051 { per_dash_key_of_row_binary(dsum1_snd_295) };
          ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 letpair_res_2052;
          {
            auto dsum2_fst_297 { std::get<0>(id_2051) };
            auto dsum2_snd_298 { std::get<1>(id_2051) };
            std::shared_ptr<::dessser::gen::sync_key::per_client>  id_2053 { std::make_shared<::dessser::gen::sync_key::per_client>(std::in_place_index<1>, dsum2_fst_297) };
            ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 id_2054 { id_2053, dsum2_snd_298 };
            letpair_res_2052 = id_2054;
          }
          choose_res_1999 = letpair_res_2052;
        }
        letpair_res_1996 = choose_res_1999;
      }
      let_res_1995 = letpair_res_1996;
    }
    return let_res_1995;
  }
   };
  return fun1991;
}
std::function<::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796(Pointer)> per_client_of_row_binary(per_client_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_248" (let-pair "du16_fst_243" "du16_snd_244" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_243") (identifier "du16_snd_244")))
        (let-pair "dsum1_fst_249" "dsum1_snd_250" (identifier "dsum1_248")
          (if (eq (u16 0) (identifier "dsum1_fst_249"))
            (let "dstring1_263"
              (let "leb_ref_257" (make-vec (u32 0))
                (let "shft_ref_258" (make-vec (u8 0))
                  (let "p_ref_259" (make-vec (identifier "dsum1_snd_250"))
                    (seq
                      (while
                        (let "leb128_260" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_259")))
                          (let-pair "leb128_fst_261" "leb128_snd_262" 
                            (identifier "leb128_260")
                            (seq (set-vec (u8 0) (identifier "p_ref_259") (identifier "leb128_snd_262"))
                              (set-vec (u8 0) (identifier "leb_ref_257")
                                (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_261") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_258"))) (unsafe-nth (u8 0) (identifier "leb_ref_257"))))
                              (set-vec (u8 0) (identifier "shft_ref_258") (add (unsafe-nth (u8 0) (identifier "shft_ref_258")) (u8 7))) 
                              (ge (identifier "leb128_fst_261") (u8 128))))) 
                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_257"))) (unsafe-nth (u8 0) (identifier "p_ref_259")))))))
              (let-pair "dstring1_fst_264" "dstring1_snd_265" (identifier "dstring1_263")
                (let-pair "dstring2_fst_267" "dstring2_snd_268" (read-bytes (identifier "dstring1_snd_265") (identifier "dstring1_fst_264"))
                  (make-tup (construct "[Subscriber STRING | LastTuple U32]" 0 (string-of-bytes (identifier "dstring2_fst_267"))) (identifier "dstring2_snd_268")))))
            (seq (assert (eq (identifier "dsum1_fst_249") (u16 1)))
              (let-pair "du32_fst_252" "du32_snd_253" (read-u32 little-endian (identifier "dsum1_snd_250")) (make-tup (construct "[Subscriber STRING | LastTuple U32]" 1 (identifier "du32_fst_252")) (identifier "du32_snd_253"))))))))
 */
static std::function<::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e(Pointer)> per_tail_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e(Pointer)> fun2055 { [&fun2055](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2056 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2057;
    {
      auto du16_fst_243 { std::get<0>(id_2056) };
      auto du16_snd_244 { std::get<1>(id_2056) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2058 { du16_fst_243, du16_snd_244 };
      letpair_res_2057 = id_2058;
    }
    ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e let_res_2059;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_248 { letpair_res_2057 };
      ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e letpair_res_2060;
      {
        auto dsum1_fst_249 { std::get<0>(dsum1_248) };
        auto dsum1_snd_250 { std::get<1>(dsum1_248) };
        uint16_t id_2061 { 0 };
        bool id_2062 { bool(id_2061 == dsum1_fst_249) };
        ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e choose_res_2063;
        if (id_2062) {
          uint32_t id_2064 { 0U };
          Vec<1, uint32_t> id_2065 {  id_2064  };
          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2066;
          {
            Vec<1, uint32_t> leb_ref_257 { id_2065 };
            uint8_t id_2067 { 0 };
            Vec<1, uint8_t> id_2068 {  id_2067  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2069;
            {
              Vec<1, uint8_t> shft_ref_258 { id_2068 };
              Vec<1, Pointer> id_2070 {  dsum1_snd_250  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2071;
              {
                Vec<1, Pointer> p_ref_259 { id_2070 };
                bool while_flag_2072 { true };
                do {
                  uint8_t id_2073 { 0 };
                  Pointer id_2074 { p_ref_259[id_2073] };
                  ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2075 { id_2074.readU8() };
                  bool let_res_2076;
                  {
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_260 { id_2075 };
                    bool letpair_res_2077;
                    {
                      auto leb128_fst_261 { std::get<0>(leb128_260) };
                      auto leb128_snd_262 { std::get<1>(leb128_260) };
                      uint8_t id_2078 { 0 };
                      Void id_2079 { ((void)(p_ref_259[id_2078] = leb128_snd_262), ::dessser::VOID) };
                      (void)id_2079;
                      uint8_t id_2080 { 0 };
                      uint8_t id_2081 { 127 };
                      uint8_t id_2082 { uint8_t(leb128_fst_261 & id_2081) };
                      uint32_t id_2083 { uint32_t(id_2082) };
                      uint8_t id_2084 { 0 };
                      uint8_t id_2085 { shft_ref_258[id_2084] };
                      uint32_t id_2086 { uint32_t(id_2083 << id_2085) };
                      uint8_t id_2087 { 0 };
                      uint32_t id_2088 { leb_ref_257[id_2087] };
                      uint32_t id_2089 { uint32_t(id_2086 | id_2088) };
                      Void id_2090 { ((void)(leb_ref_257[id_2080] = id_2089), ::dessser::VOID) };
                      (void)id_2090;
                      uint8_t id_2091 { 0 };
                      uint8_t id_2092 { 0 };
                      uint8_t id_2093 { shft_ref_258[id_2092] };
                      uint8_t id_2094 { 7 };
                      uint8_t id_2095 { uint8_t(id_2093 + id_2094) };
                      Void id_2096 { ((void)(shft_ref_258[id_2091] = id_2095), ::dessser::VOID) };
                      (void)id_2096;
                      uint8_t id_2097 { 128 };
                      bool id_2098 { bool(leb128_fst_261 >= id_2097) };
                      letpair_res_2077 = id_2098;
                    }
                    let_res_2076 = letpair_res_2077;
                  }
                  while_flag_2072 = let_res_2076;
                  if (while_flag_2072) {
                    (void)::dessser::VOID;
                  }
                } while (while_flag_2072);
                (void)::dessser::VOID;
                uint8_t id_2099 { 0 };
                uint32_t id_2100 { leb_ref_257[id_2099] };
                Size id_2101 { Size(id_2100) };
                uint8_t id_2102 { 0 };
                Pointer id_2103 { p_ref_259[id_2102] };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2104 { id_2101, id_2103 };
                let_res_2071 = id_2104;
              }
              let_res_2069 = let_res_2071;
            }
            let_res_2066 = let_res_2069;
          }
          ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e let_res_2105;
          {
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_263 { let_res_2066 };
            ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e letpair_res_2106;
            {
              auto dstring1_fst_264 { std::get<0>(dstring1_263) };
              auto dstring1_snd_265 { std::get<1>(dstring1_263) };
              ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2107 { dstring1_snd_265.readBytes(dstring1_fst_264) };
              ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e letpair_res_2108;
              {
                auto dstring2_fst_267 { std::get<0>(id_2107) };
                auto dstring2_snd_268 { std::get<1>(id_2107) };
                std::string id_2109 { dstring2_fst_267.toString() };
                std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_2110 { std::make_shared<::dessser::gen::sync_key::per_tail>(std::in_place_index<0>, id_2109) };
                ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e id_2111 { id_2110, dstring2_snd_268 };
                letpair_res_2108 = id_2111;
              }
              letpair_res_2106 = letpair_res_2108;
            }
            let_res_2105 = letpair_res_2106;
          }
          choose_res_2063 = let_res_2105;
        } else {
          uint16_t id_2112 { 1 };
          bool id_2113 { bool(dsum1_fst_249 == id_2112) };
          Void id_2114 { ((void)(assert(id_2113)), ::dessser::VOID) };
          (void)id_2114;
          ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_2115 { dsum1_snd_250.readU32Le() };
          ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e letpair_res_2116;
          {
            auto du32_fst_252 { std::get<0>(id_2115) };
            auto du32_snd_253 { std::get<1>(id_2115) };
            std::shared_ptr<::dessser::gen::sync_key::per_tail>  id_2117 { std::make_shared<::dessser::gen::sync_key::per_tail>(std::in_place_index<1>, du32_fst_252) };
            ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e id_2118 { id_2117, du32_snd_253 };
            letpair_res_2116 = id_2118;
          }
          choose_res_2063 = letpair_res_2116;
        }
        letpair_res_2060 = choose_res_2063;
      }
      let_res_2059 = letpair_res_2060;
    }
    return let_res_2059;
  }
   };
  return fun2055;
}
std::function<::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e(Pointer)> per_tail_of_row_binary(per_tail_of_row_binary_init());

/* 
    (fun ("Ptr")
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
                                            (make-tup (construct "[StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]" 4 (nop))
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
                                (nop)) (identifier "dsum1_snd_64"))))))))))))))
 */
static std::function<::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049(Pointer)> per_worker_data_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049(Pointer)> fun2119 { [&fun2119](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2120 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2121;
    {
      auto du16_fst_57 { std::get<0>(id_2120) };
      auto du16_snd_58 { std::get<1>(id_2120) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2122 { du16_fst_57, du16_snd_58 };
      letpair_res_2121 = id_2122;
    }
    ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 let_res_2123;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_62 { letpair_res_2121 };
      ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 letpair_res_2124;
      {
        auto dsum1_fst_63 { std::get<0>(dsum1_62) };
        auto dsum1_snd_64 { std::get<1>(dsum1_62) };
        uint16_t id_2125 { 0 };
        bool id_2126 { bool(id_2125 == dsum1_fst_63) };
        ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2127;
        if (id_2126) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2128 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2129 { id_2128, dsum1_snd_64 };
          choose_res_2127 = id_2129;
        } else {
          uint16_t id_2130 { 1 };
          bool id_2131 { bool(id_2130 == dsum1_fst_63) };
          ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2132;
          if (id_2131) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2133 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2134 { id_2133, dsum1_snd_64 };
            choose_res_2132 = id_2134;
          } else {
            uint16_t id_2135 { 2 };
            bool id_2136 { bool(id_2135 == dsum1_fst_63) };
            ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2137;
            if (id_2136) {
              (void)::dessser::VOID;
              std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2138 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<2>, ::dessser::VOID) };
              ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2139 { id_2138, dsum1_snd_64 };
              choose_res_2137 = id_2139;
            } else {
              uint16_t id_2140 { 3 };
              bool id_2141 { bool(id_2140 == dsum1_fst_63) };
              ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2142;
              if (id_2141) {
                (void)::dessser::VOID;
                std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2143 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<3>, ::dessser::VOID) };
                ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2144 { id_2143, dsum1_snd_64 };
                choose_res_2142 = id_2144;
              } else {
                uint16_t id_2145 { 4 };
                bool id_2146 { bool(id_2145 == dsum1_fst_63) };
                ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2147;
                if (id_2146) {
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2148 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<4>, ::dessser::VOID) };
                  ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2149 { id_2148, dsum1_snd_64 };
                  choose_res_2147 = id_2149;
                } else {
                  uint16_t id_2150 { 5 };
                  bool id_2151 { bool(id_2150 == dsum1_fst_63) };
                  ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2152;
                  if (id_2151) {
                    (void)::dessser::VOID;
                    std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2153 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<5>, ::dessser::VOID) };
                    ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2154 { id_2153, dsum1_snd_64 };
                    choose_res_2152 = id_2154;
                  } else {
                    uint16_t id_2155 { 6 };
                    bool id_2156 { bool(id_2155 == dsum1_fst_63) };
                    ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2157;
                    if (id_2156) {
                      uint32_t id_2158 { 0U };
                      Vec<1, uint32_t> id_2159 {  id_2158  };
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2160;
                      {
                        Vec<1, uint32_t> leb_ref_74 { id_2159 };
                        uint8_t id_2161 { 0 };
                        Vec<1, uint8_t> id_2162 {  id_2161  };
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2163;
                        {
                          Vec<1, uint8_t> shft_ref_75 { id_2162 };
                          Vec<1, Pointer> id_2164 {  dsum1_snd_64  };
                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2165;
                          {
                            Vec<1, Pointer> p_ref_76 { id_2164 };
                            bool while_flag_2166 { true };
                            do {
                              uint8_t id_2167 { 0 };
                              Pointer id_2168 { p_ref_76[id_2167] };
                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2169 { id_2168.readU8() };
                              bool let_res_2170;
                              {
                                ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_77 { id_2169 };
                                bool letpair_res_2171;
                                {
                                  auto leb128_fst_78 { std::get<0>(leb128_77) };
                                  auto leb128_snd_79 { std::get<1>(leb128_77) };
                                  uint8_t id_2172 { 0 };
                                  Void id_2173 { ((void)(p_ref_76[id_2172] = leb128_snd_79), ::dessser::VOID) };
                                  (void)id_2173;
                                  uint8_t id_2174 { 0 };
                                  uint8_t id_2175 { 127 };
                                  uint8_t id_2176 { uint8_t(leb128_fst_78 & id_2175) };
                                  uint32_t id_2177 { uint32_t(id_2176) };
                                  uint8_t id_2178 { 0 };
                                  uint8_t id_2179 { shft_ref_75[id_2178] };
                                  uint32_t id_2180 { uint32_t(id_2177 << id_2179) };
                                  uint8_t id_2181 { 0 };
                                  uint32_t id_2182 { leb_ref_74[id_2181] };
                                  uint32_t id_2183 { uint32_t(id_2180 | id_2182) };
                                  Void id_2184 { ((void)(leb_ref_74[id_2174] = id_2183), ::dessser::VOID) };
                                  (void)id_2184;
                                  uint8_t id_2185 { 0 };
                                  uint8_t id_2186 { 0 };
                                  uint8_t id_2187 { shft_ref_75[id_2186] };
                                  uint8_t id_2188 { 7 };
                                  uint8_t id_2189 { uint8_t(id_2187 + id_2188) };
                                  Void id_2190 { ((void)(shft_ref_75[id_2185] = id_2189), ::dessser::VOID) };
                                  (void)id_2190;
                                  uint8_t id_2191 { 128 };
                                  bool id_2192 { bool(leb128_fst_78 >= id_2191) };
                                  letpair_res_2171 = id_2192;
                                }
                                let_res_2170 = letpair_res_2171;
                              }
                              while_flag_2166 = let_res_2170;
                              if (while_flag_2166) {
                                (void)::dessser::VOID;
                              }
                            } while (while_flag_2166);
                            (void)::dessser::VOID;
                            uint8_t id_2193 { 0 };
                            uint32_t id_2194 { leb_ref_74[id_2193] };
                            Size id_2195 { Size(id_2194) };
                            uint8_t id_2196 { 0 };
                            Pointer id_2197 { p_ref_76[id_2196] };
                            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2198 { id_2195, id_2197 };
                            let_res_2165 = id_2198;
                          }
                          let_res_2163 = let_res_2165;
                        }
                        let_res_2160 = let_res_2163;
                      }
                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2199;
                      {
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_80 { let_res_2160 };
                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2200;
                        {
                          auto dstring1_fst_81 { std::get<0>(dstring1_80) };
                          auto dstring1_snd_82 { std::get<1>(dstring1_80) };
                          ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2201 { dstring1_snd_82.readBytes(dstring1_fst_81) };
                          ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2202;
                          {
                            auto dstring2_fst_84 { std::get<0>(id_2201) };
                            auto dstring2_snd_85 { std::get<1>(id_2201) };
                            std::string id_2203 { dstring2_fst_84.toString() };
                            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2204 { id_2203, dstring2_snd_85 };
                            letpair_res_2202 = id_2204;
                          }
                          letpair_res_2200 = letpair_res_2202;
                        }
                        let_res_2199 = letpair_res_2200;
                      }
                      ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 let_res_2205;
                      {
                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_86 { let_res_2199 };
                        ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 letpair_res_2206;
                        {
                          auto dtup_fst_87 { std::get<0>(dtup_86) };
                          auto dtup_snd_88 { std::get<1>(dtup_86) };
                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2207 { dtup_snd_88.readU16Le() };
                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2208;
                          {
                            auto du16_fst_90 { std::get<0>(id_2207) };
                            auto du16_snd_91 { std::get<1>(id_2207) };
                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2209 { du16_fst_90, du16_snd_91 };
                            letpair_res_2208 = id_2209;
                          }
                          ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae let_res_2210;
                          {
                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_95 { letpair_res_2208 };
                            ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae letpair_res_2211;
                            {
                              auto dsum1_fst_96 { std::get<0>(dsum1_95) };
                              auto dsum1_snd_97 { std::get<1>(dsum1_95) };
                              uint16_t id_2212 { 0 };
                              bool id_2213 { bool(id_2212 == dsum1_fst_96) };
                              ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2214;
                              if (id_2213) {
                                (void)::dessser::VOID;
                                ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2215 { std::in_place_index<0>, ::dessser::VOID };
                                ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2216 { id_2215, dsum1_snd_97 };
                                choose_res_2214 = id_2216;
                              } else {
                                uint16_t id_2217 { 1 };
                                bool id_2218 { bool(id_2217 == dsum1_fst_96) };
                                ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2219;
                                if (id_2218) {
                                  (void)::dessser::VOID;
                                  ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2220 { std::in_place_index<1>, ::dessser::VOID };
                                  ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2221 { id_2220, dsum1_snd_97 };
                                  choose_res_2219 = id_2221;
                                } else {
                                  uint16_t id_2222 { 2 };
                                  bool id_2223 { bool(id_2222 == dsum1_fst_96) };
                                  ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2224;
                                  if (id_2223) {
                                    (void)::dessser::VOID;
                                    ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2225 { std::in_place_index<2>, ::dessser::VOID };
                                    ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2226 { id_2225, dsum1_snd_97 };
                                    choose_res_2224 = id_2226;
                                  } else {
                                    uint16_t id_2227 { 3 };
                                    bool id_2228 { bool(id_2227 == dsum1_fst_96) };
                                    ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2229;
                                    if (id_2228) {
                                      (void)::dessser::VOID;
                                      ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2230 { std::in_place_index<3>, ::dessser::VOID };
                                      ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2231 { id_2230, dsum1_snd_97 };
                                      choose_res_2229 = id_2231;
                                    } else {
                                      uint16_t id_2232 { 4 };
                                      bool id_2233 { bool(id_2232 == dsum1_fst_96) };
                                      ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2234;
                                      if (id_2233) {
                                        (void)::dessser::VOID;
                                        ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2235 { std::in_place_index<4>, ::dessser::VOID };
                                        ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2236 { id_2235, dsum1_snd_97 };
                                        choose_res_2234 = id_2236;
                                      } else {
                                        uint16_t id_2237 { 5 };
                                        bool id_2238 { bool(id_2237 == dsum1_fst_96) };
                                        ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2239;
                                        if (id_2238) {
                                          (void)::dessser::VOID;
                                          ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2240 { std::in_place_index<5>, ::dessser::VOID };
                                          ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2241 { id_2240, dsum1_snd_97 };
                                          choose_res_2239 = id_2241;
                                        } else {
                                          uint16_t id_2242 { 6 };
                                          bool id_2243 { bool(id_2242 == dsum1_fst_96) };
                                          ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae choose_res_2244;
                                          if (id_2243) {
                                            (void)::dessser::VOID;
                                            ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2245 { std::in_place_index<6>, ::dessser::VOID };
                                            ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2246 { id_2245, dsum1_snd_97 };
                                            choose_res_2244 = id_2246;
                                          } else {
                                            uint16_t id_2247 { 7 };
                                            bool id_2248 { bool(dsum1_fst_96 == id_2247) };
                                            Void id_2249 { ((void)(assert(id_2248)), ::dessser::VOID) };
                                            (void)id_2249;
                                            (void)::dessser::VOID;
                                            ::dessser::gen::sync_key::t62147b4d97ca22ce48402f8d7a47b9c0 id_2250 { std::in_place_index<7>, ::dessser::VOID };
                                            ::dessser::gen::sync_key::t4cdccf3979a446cc6c30bc2b6ecc87ae id_2251 { id_2250, dsum1_snd_97 };
                                            choose_res_2244 = id_2251;
                                          }
                                          choose_res_2239 = choose_res_2244;
                                        }
                                        choose_res_2234 = choose_res_2239;
                                      }
                                      choose_res_2229 = choose_res_2234;
                                    }
                                    choose_res_2224 = choose_res_2229;
                                  }
                                  choose_res_2219 = choose_res_2224;
                                }
                                choose_res_2214 = choose_res_2219;
                              }
                              letpair_res_2211 = choose_res_2214;
                            }
                            let_res_2210 = letpair_res_2211;
                          }
                          ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 letpair_res_2252;
                          {
                            auto dtup_fst_123 { std::get<0>(let_res_2210) };
                            auto dtup_snd_124 { std::get<1>(let_res_2210) };
                            ::dessser::gen::sync_key::t35f466ab2ffe47e08d3d46d20f2eb1a6 id_2253 { dtup_fst_87, dtup_fst_123 };
                            std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2254 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<6>, id_2253) };
                            ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2255 { id_2254, dtup_snd_124 };
                            letpair_res_2252 = id_2255;
                          }
                          letpair_res_2206 = letpair_res_2252;
                        }
                        let_res_2205 = letpair_res_2206;
                      }
                      choose_res_2157 = let_res_2205;
                    } else {
                      uint16_t id_2256 { 7 };
                      bool id_2257 { bool(id_2256 == dsum1_fst_63) };
                      ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 choose_res_2258;
                      if (id_2257) {
                        ::dessser::gen::sync_key::t491c44439106a32f896827242e8e76a1 id_2259 { dsum1_snd_64.readU32Le() };
                        ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 letpair_res_2260;
                        {
                          auto du32_fst_69 { std::get<0>(id_2259) };
                          auto du32_snd_70 { std::get<1>(id_2259) };
                          std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2261 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<7>, du32_fst_69) };
                          ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2262 { id_2261, du32_snd_70 };
                          letpair_res_2260 = id_2262;
                        }
                        choose_res_2258 = letpair_res_2260;
                      } else {
                        uint16_t id_2263 { 8 };
                        bool id_2264 { bool(dsum1_fst_63 == id_2263) };
                        Void id_2265 { ((void)(assert(id_2264)), ::dessser::VOID) };
                        (void)id_2265;
                        (void)::dessser::VOID;
                        std::shared_ptr<::dessser::gen::sync_key::per_worker_data>  id_2266 { std::make_shared<::dessser::gen::sync_key::per_worker_data>(std::in_place_index<8>, ::dessser::VOID) };
                        ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2267 { id_2266, dsum1_snd_64 };
                        choose_res_2258 = id_2267;
                      }
                      choose_res_2157 = choose_res_2258;
                    }
                    choose_res_2152 = choose_res_2157;
                  }
                  choose_res_2147 = choose_res_2152;
                }
                choose_res_2142 = choose_res_2147;
              }
              choose_res_2137 = choose_res_2142;
            }
            choose_res_2132 = choose_res_2137;
          }
          choose_res_2127 = choose_res_2132;
        }
        letpair_res_2124 = choose_res_2127;
      }
      let_res_2123 = letpair_res_2124;
    }
    return let_res_2123;
  }
   };
  return fun2119;
}
std::function<::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049(Pointer)> per_worker_data_of_row_binary(per_worker_data_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_146" (apply (ext-identifier fq_name of-row-binary) (param 0))
        (let-pair "dtup_fst_147" "dtup_snd_148" (identifier "dtup_146")
          (let-pair "dtup_fst_150" "dtup_snd_151" (apply (identifier "per_worker_data-of-row-binary") (identifier "dtup_snd_148"))
            (make-tup (make-tup (identifier "dtup_fst_147") (identifier "dtup_fst_150")) (identifier "dtup_snd_151"))))))
 */
static std::function<::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5(Pointer)> per_worker_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5(Pointer)> fun2268 { [&fun2268](Pointer p_0) {
    auto fun2269 { dessser::gen::fq_name::of_row_binary };
    ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 id_2270 { fun2269(p_0) };
    ::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5 let_res_2271;
    {
      ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 dtup_146 { id_2270 };
      ::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5 letpair_res_2272;
      {
        auto dtup_fst_147 { std::get<0>(dtup_146) };
        auto dtup_snd_148 { std::get<1>(dtup_146) };
        ::dessser::gen::sync_key::t86357804013591d564a14dcb7d208049 id_2273 { per_worker_data_of_row_binary(dtup_snd_148) };
        ::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5 letpair_res_2274;
        {
          auto dtup_fst_150 { std::get<0>(id_2273) };
          auto dtup_snd_151 { std::get<1>(id_2273) };
          std::shared_ptr<::dessser::gen::sync_key::per_worker>  id_2275 { std::make_shared<::dessser::gen::sync_key::per_worker>(dtup_fst_147, dtup_fst_150) };
          ::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5 id_2276 { id_2275, dtup_snd_151 };
          letpair_res_2274 = id_2276;
        }
        letpair_res_2272 = letpair_res_2274;
      }
      let_res_2271 = letpair_res_2272;
    }
    return let_res_2271;
  }
   };
  return fun2268;
}
std::function<::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5(Pointer)> per_worker_of_row_binary(per_worker_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_158" (let-pair "du16_fst_153" "du16_snd_154" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_153") (identifier "du16_snd_154")))
        (let-pair "dsum1_fst_159" "dsum1_snd_160" (identifier "dsum1_158")
          (if (eq (u16 0) (identifier "dsum1_fst_159"))
            (make-tup
              (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 0
                (nop)) (identifier "dsum1_snd_160"))
            (if (eq (u16 1) (identifier "dsum1_fst_159"))
              (let "dtup_209"
                (let "dstring1_203"
                  (let "leb_ref_197" (make-vec (u32 0))
                    (let "shft_ref_198" (make-vec (u8 0))
                      (let "p_ref_199" (make-vec (identifier "dsum1_snd_160"))
                        (seq
                          (while
                            (let "leb128_200" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_199")))
                              (let-pair "leb128_fst_201" "leb128_snd_202" 
                                (identifier "leb128_200")
                                (seq (set-vec (u8 0) (identifier "p_ref_199") (identifier "leb128_snd_202"))
                                  (set-vec (u8 0) (identifier "leb_ref_197")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_201") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_198"))) (unsafe-nth (u8 0) (identifier "leb_ref_197"))))
                                  (set-vec (u8 0) (identifier "shft_ref_198") (add (unsafe-nth (u8 0) (identifier "shft_ref_198")) (u8 7))) 
                                  (ge (identifier "leb128_fst_201") (u8 128))))) 
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_197"))) (unsafe-nth (u8 0) (identifier "p_ref_199")))))))
                  (let-pair "dstring1_fst_204" "dstring1_snd_205" (identifier "dstring1_203")
                    (let-pair "dstring2_fst_207" "dstring2_snd_208" (read-bytes (identifier "dstring1_snd_205") (identifier "dstring1_fst_204"))
                      (make-tup (string-of-bytes (identifier "dstring2_fst_207")) (identifier "dstring2_snd_208")))))
                (let-pair "dtup_fst_210" "dtup_snd_211" (identifier "dtup_209")
                  (let-pair "dtup_fst_228" "dtup_snd_229"
                    (let "dsum1_218" (let-pair "du16_fst_213" "du16_snd_214" (read-u16 little-endian (identifier "dtup_snd_211")) (make-tup (identifier "du16_fst_213") (identifier "du16_snd_214")))
                      (let-pair "dsum1_fst_219" "dsum1_snd_220" (identifier "dsum1_218")
                        (if (eq (u16 0) (identifier "dsum1_fst_219")) 
                          (make-tup (construct "[Host Void | Port Void]" 0 (nop)) (identifier "dsum1_snd_220"))
                          (seq (assert (eq (identifier "dsum1_fst_219") (u16 1))) (make-tup (construct "[Host Void | Port Void]" 1 (nop)) (identifier "dsum1_snd_220"))))))
                    (make-tup
                      (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 1
                        (make-tup (identifier "dtup_fst_210") (identifier "dtup_fst_228"))) 
                      (identifier "dtup_snd_229")))))
              (if (eq (u16 2) (identifier "dsum1_fst_159"))
                (let-pair "dsum2_fst_195" "dsum2_snd_196" (apply (identifier "per_worker-of-row-binary") (identifier "dsum1_snd_160"))
                  (make-tup
                    (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 2
                      (identifier "dsum2_fst_195")) (identifier "dsum2_snd_196")))
                (seq (assert (eq (identifier "dsum1_fst_159") (u16 3)))
                  (let "dtup_173"
                    (let "dstring1_167"
                      (let "leb_ref_161" (make-vec (u32 0))
                        (let "shft_ref_162" (make-vec (u8 0))
                          (let "p_ref_163" (make-vec (identifier "dsum1_snd_160"))
                            (seq
                              (while
                                (let "leb128_164" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_163")))
                                  (let-pair "leb128_fst_165" "leb128_snd_166" 
                                    (identifier "leb128_164")
                                    (seq (set-vec (u8 0) (identifier "p_ref_163") (identifier "leb128_snd_166"))
                                      (set-vec (u8 0) (identifier "leb_ref_161")
                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_165") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_162"))) (unsafe-nth (u8 0) (identifier "leb_ref_161"))))
                                      (set-vec (u8 0) (identifier "shft_ref_162") (add (unsafe-nth (u8 0) (identifier "shft_ref_162")) (u8 7))) 
                                      (ge (identifier "leb128_fst_165") (u8 128))))) 
                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_161"))) (unsafe-nth (u8 0) (identifier "p_ref_163")))))))
                      (let-pair "dstring1_fst_168" "dstring1_snd_169" 
                        (identifier "dstring1_167")
                        (let-pair "dstring2_fst_171" "dstring2_snd_172" 
                          (read-bytes (identifier "dstring1_snd_169") (identifier "dstring1_fst_168")) 
                          (make-tup (string-of-bytes (identifier "dstring2_fst_171")) (identifier "dstring2_snd_172")))))
                    (let-pair "dtup_fst_174" "dtup_snd_175" (identifier "dtup_173")
                      (let "dsum1_182" (let-pair "du16_fst_177" "du16_snd_178" (read-u16 little-endian (identifier "dtup_snd_175")) (make-tup (identifier "du16_fst_177") (identifier "du16_snd_178")))
                        (let-pair "dsum1_fst_183" "dsum1_snd_184" (identifier "dsum1_182")
                          (seq (assert (eq (identifier "dsum1_fst_183") (u16 0)))
                            (make-tup
                              (construct "[IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]" 3
                                (make-tup (identifier "dtup_fst_174") (construct "[Executable Void]" 0 (nop)))) 
                              (identifier "dsum1_snd_184"))))))))))))))
 */
static std::function<::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab(Pointer)> per_site_data_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab(Pointer)> fun2277 { [&fun2277](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2278 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2279;
    {
      auto du16_fst_153 { std::get<0>(id_2278) };
      auto du16_snd_154 { std::get<1>(id_2278) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2280 { du16_fst_153, du16_snd_154 };
      letpair_res_2279 = id_2280;
    }
    ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab let_res_2281;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_158 { letpair_res_2279 };
      ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2282;
      {
        auto dsum1_fst_159 { std::get<0>(dsum1_158) };
        auto dsum1_snd_160 { std::get<1>(dsum1_158) };
        uint16_t id_2283 { 0 };
        bool id_2284 { bool(id_2283 == dsum1_fst_159) };
        ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab choose_res_2285;
        if (id_2284) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2286 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab id_2287 { id_2286, dsum1_snd_160 };
          choose_res_2285 = id_2287;
        } else {
          uint16_t id_2288 { 1 };
          bool id_2289 { bool(id_2288 == dsum1_fst_159) };
          ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab choose_res_2290;
          if (id_2289) {
            uint32_t id_2291 { 0U };
            Vec<1, uint32_t> id_2292 {  id_2291  };
            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2293;
            {
              Vec<1, uint32_t> leb_ref_197 { id_2292 };
              uint8_t id_2294 { 0 };
              Vec<1, uint8_t> id_2295 {  id_2294  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2296;
              {
                Vec<1, uint8_t> shft_ref_198 { id_2295 };
                Vec<1, Pointer> id_2297 {  dsum1_snd_160  };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2298;
                {
                  Vec<1, Pointer> p_ref_199 { id_2297 };
                  bool while_flag_2299 { true };
                  do {
                    uint8_t id_2300 { 0 };
                    Pointer id_2301 { p_ref_199[id_2300] };
                    ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2302 { id_2301.readU8() };
                    bool let_res_2303;
                    {
                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_200 { id_2302 };
                      bool letpair_res_2304;
                      {
                        auto leb128_fst_201 { std::get<0>(leb128_200) };
                        auto leb128_snd_202 { std::get<1>(leb128_200) };
                        uint8_t id_2305 { 0 };
                        Void id_2306 { ((void)(p_ref_199[id_2305] = leb128_snd_202), ::dessser::VOID) };
                        (void)id_2306;
                        uint8_t id_2307 { 0 };
                        uint8_t id_2308 { 127 };
                        uint8_t id_2309 { uint8_t(leb128_fst_201 & id_2308) };
                        uint32_t id_2310 { uint32_t(id_2309) };
                        uint8_t id_2311 { 0 };
                        uint8_t id_2312 { shft_ref_198[id_2311] };
                        uint32_t id_2313 { uint32_t(id_2310 << id_2312) };
                        uint8_t id_2314 { 0 };
                        uint32_t id_2315 { leb_ref_197[id_2314] };
                        uint32_t id_2316 { uint32_t(id_2313 | id_2315) };
                        Void id_2317 { ((void)(leb_ref_197[id_2307] = id_2316), ::dessser::VOID) };
                        (void)id_2317;
                        uint8_t id_2318 { 0 };
                        uint8_t id_2319 { 0 };
                        uint8_t id_2320 { shft_ref_198[id_2319] };
                        uint8_t id_2321 { 7 };
                        uint8_t id_2322 { uint8_t(id_2320 + id_2321) };
                        Void id_2323 { ((void)(shft_ref_198[id_2318] = id_2322), ::dessser::VOID) };
                        (void)id_2323;
                        uint8_t id_2324 { 128 };
                        bool id_2325 { bool(leb128_fst_201 >= id_2324) };
                        letpair_res_2304 = id_2325;
                      }
                      let_res_2303 = letpair_res_2304;
                    }
                    while_flag_2299 = let_res_2303;
                    if (while_flag_2299) {
                      (void)::dessser::VOID;
                    }
                  } while (while_flag_2299);
                  (void)::dessser::VOID;
                  uint8_t id_2326 { 0 };
                  uint32_t id_2327 { leb_ref_197[id_2326] };
                  Size id_2328 { Size(id_2327) };
                  uint8_t id_2329 { 0 };
                  Pointer id_2330 { p_ref_199[id_2329] };
                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2331 { id_2328, id_2330 };
                  let_res_2298 = id_2331;
                }
                let_res_2296 = let_res_2298;
              }
              let_res_2293 = let_res_2296;
            }
            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2332;
            {
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_203 { let_res_2293 };
              ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2333;
              {
                auto dstring1_fst_204 { std::get<0>(dstring1_203) };
                auto dstring1_snd_205 { std::get<1>(dstring1_203) };
                ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2334 { dstring1_snd_205.readBytes(dstring1_fst_204) };
                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2335;
                {
                  auto dstring2_fst_207 { std::get<0>(id_2334) };
                  auto dstring2_snd_208 { std::get<1>(id_2334) };
                  std::string id_2336 { dstring2_fst_207.toString() };
                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2337 { id_2336, dstring2_snd_208 };
                  letpair_res_2335 = id_2337;
                }
                letpair_res_2333 = letpair_res_2335;
              }
              let_res_2332 = letpair_res_2333;
            }
            ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab let_res_2338;
            {
              ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_209 { let_res_2332 };
              ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2339;
              {
                auto dtup_fst_210 { std::get<0>(dtup_209) };
                auto dtup_snd_211 { std::get<1>(dtup_209) };
                ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2340 { dtup_snd_211.readU16Le() };
                ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2341;
                {
                  auto du16_fst_213 { std::get<0>(id_2340) };
                  auto du16_snd_214 { std::get<1>(id_2340) };
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2342 { du16_fst_213, du16_snd_214 };
                  letpair_res_2341 = id_2342;
                }
                ::dessser::gen::sync_key::t8f0858866d1e27d5fa38c6941e6365f2 let_res_2343;
                {
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_218 { letpair_res_2341 };
                  ::dessser::gen::sync_key::t8f0858866d1e27d5fa38c6941e6365f2 letpair_res_2344;
                  {
                    auto dsum1_fst_219 { std::get<0>(dsum1_218) };
                    auto dsum1_snd_220 { std::get<1>(dsum1_218) };
                    uint16_t id_2345 { 0 };
                    bool id_2346 { bool(id_2345 == dsum1_fst_219) };
                    ::dessser::gen::sync_key::t8f0858866d1e27d5fa38c6941e6365f2 choose_res_2347;
                    if (id_2346) {
                      (void)::dessser::VOID;
                      ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_2348 { std::in_place_index<0>, ::dessser::VOID };
                      ::dessser::gen::sync_key::t8f0858866d1e27d5fa38c6941e6365f2 id_2349 { id_2348, dsum1_snd_220 };
                      choose_res_2347 = id_2349;
                    } else {
                      uint16_t id_2350 { 1 };
                      bool id_2351 { bool(dsum1_fst_219 == id_2350) };
                      Void id_2352 { ((void)(assert(id_2351)), ::dessser::VOID) };
                      (void)id_2352;
                      (void)::dessser::VOID;
                      ::dessser::gen::sync_key::tcc9598dfd3f6ae835fa2904058bd9af9 id_2353 { std::in_place_index<1>, ::dessser::VOID };
                      ::dessser::gen::sync_key::t8f0858866d1e27d5fa38c6941e6365f2 id_2354 { id_2353, dsum1_snd_220 };
                      choose_res_2347 = id_2354;
                    }
                    letpair_res_2344 = choose_res_2347;
                  }
                  let_res_2343 = letpair_res_2344;
                }
                ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2355;
                {
                  auto dtup_fst_228 { std::get<0>(let_res_2343) };
                  auto dtup_snd_229 { std::get<1>(let_res_2343) };
                  ::dessser::gen::sync_key::t3ac6072d22a4c4a598bde9a5fc94f773 id_2356 { dtup_fst_210, dtup_fst_228 };
                  std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2357 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<1>, id_2356) };
                  ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab id_2358 { id_2357, dtup_snd_229 };
                  letpair_res_2355 = id_2358;
                }
                letpair_res_2339 = letpair_res_2355;
              }
              let_res_2338 = letpair_res_2339;
            }
            choose_res_2290 = let_res_2338;
          } else {
            uint16_t id_2359 { 2 };
            bool id_2360 { bool(id_2359 == dsum1_fst_159) };
            ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab choose_res_2361;
            if (id_2360) {
              ::dessser::gen::sync_key::t230dd37e292f8ada6da847a9bd177ec5 id_2362 { per_worker_of_row_binary(dsum1_snd_160) };
              ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2363;
              {
                auto dsum2_fst_195 { std::get<0>(id_2362) };
                auto dsum2_snd_196 { std::get<1>(id_2362) };
                std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2364 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<2>, dsum2_fst_195) };
                ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab id_2365 { id_2364, dsum2_snd_196 };
                letpair_res_2363 = id_2365;
              }
              choose_res_2361 = letpair_res_2363;
            } else {
              uint16_t id_2366 { 3 };
              bool id_2367 { bool(dsum1_fst_159 == id_2366) };
              Void id_2368 { ((void)(assert(id_2367)), ::dessser::VOID) };
              (void)id_2368;
              uint32_t id_2369 { 0U };
              Vec<1, uint32_t> id_2370 {  id_2369  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2371;
              {
                Vec<1, uint32_t> leb_ref_161 { id_2370 };
                uint8_t id_2372 { 0 };
                Vec<1, uint8_t> id_2373 {  id_2372  };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2374;
                {
                  Vec<1, uint8_t> shft_ref_162 { id_2373 };
                  Vec<1, Pointer> id_2375 {  dsum1_snd_160  };
                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2376;
                  {
                    Vec<1, Pointer> p_ref_163 { id_2375 };
                    bool while_flag_2377 { true };
                    do {
                      uint8_t id_2378 { 0 };
                      Pointer id_2379 { p_ref_163[id_2378] };
                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2380 { id_2379.readU8() };
                      bool let_res_2381;
                      {
                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_164 { id_2380 };
                        bool letpair_res_2382;
                        {
                          auto leb128_fst_165 { std::get<0>(leb128_164) };
                          auto leb128_snd_166 { std::get<1>(leb128_164) };
                          uint8_t id_2383 { 0 };
                          Void id_2384 { ((void)(p_ref_163[id_2383] = leb128_snd_166), ::dessser::VOID) };
                          (void)id_2384;
                          uint8_t id_2385 { 0 };
                          uint8_t id_2386 { 127 };
                          uint8_t id_2387 { uint8_t(leb128_fst_165 & id_2386) };
                          uint32_t id_2388 { uint32_t(id_2387) };
                          uint8_t id_2389 { 0 };
                          uint8_t id_2390 { shft_ref_162[id_2389] };
                          uint32_t id_2391 { uint32_t(id_2388 << id_2390) };
                          uint8_t id_2392 { 0 };
                          uint32_t id_2393 { leb_ref_161[id_2392] };
                          uint32_t id_2394 { uint32_t(id_2391 | id_2393) };
                          Void id_2395 { ((void)(leb_ref_161[id_2385] = id_2394), ::dessser::VOID) };
                          (void)id_2395;
                          uint8_t id_2396 { 0 };
                          uint8_t id_2397 { 0 };
                          uint8_t id_2398 { shft_ref_162[id_2397] };
                          uint8_t id_2399 { 7 };
                          uint8_t id_2400 { uint8_t(id_2398 + id_2399) };
                          Void id_2401 { ((void)(shft_ref_162[id_2396] = id_2400), ::dessser::VOID) };
                          (void)id_2401;
                          uint8_t id_2402 { 128 };
                          bool id_2403 { bool(leb128_fst_165 >= id_2402) };
                          letpair_res_2382 = id_2403;
                        }
                        let_res_2381 = letpair_res_2382;
                      }
                      while_flag_2377 = let_res_2381;
                      if (while_flag_2377) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_2377);
                    (void)::dessser::VOID;
                    uint8_t id_2404 { 0 };
                    uint32_t id_2405 { leb_ref_161[id_2404] };
                    Size id_2406 { Size(id_2405) };
                    uint8_t id_2407 { 0 };
                    Pointer id_2408 { p_ref_163[id_2407] };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2409 { id_2406, id_2408 };
                    let_res_2376 = id_2409;
                  }
                  let_res_2374 = let_res_2376;
                }
                let_res_2371 = let_res_2374;
              }
              ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2410;
              {
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_167 { let_res_2371 };
                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2411;
                {
                  auto dstring1_fst_168 { std::get<0>(dstring1_167) };
                  auto dstring1_snd_169 { std::get<1>(dstring1_167) };
                  ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2412 { dstring1_snd_169.readBytes(dstring1_fst_168) };
                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2413;
                  {
                    auto dstring2_fst_171 { std::get<0>(id_2412) };
                    auto dstring2_snd_172 { std::get<1>(id_2412) };
                    std::string id_2414 { dstring2_fst_171.toString() };
                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2415 { id_2414, dstring2_snd_172 };
                    letpair_res_2413 = id_2415;
                  }
                  letpair_res_2411 = letpair_res_2413;
                }
                let_res_2410 = letpair_res_2411;
              }
              ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab let_res_2416;
              {
                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_173 { let_res_2410 };
                ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2417;
                {
                  auto dtup_fst_174 { std::get<0>(dtup_173) };
                  auto dtup_snd_175 { std::get<1>(dtup_173) };
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2418 { dtup_snd_175.readU16Le() };
                  ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2419;
                  {
                    auto du16_fst_177 { std::get<0>(id_2418) };
                    auto du16_snd_178 { std::get<1>(id_2418) };
                    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2420 { du16_fst_177, du16_snd_178 };
                    letpair_res_2419 = id_2420;
                  }
                  ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab let_res_2421;
                  {
                    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_182 { letpair_res_2419 };
                    ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab letpair_res_2422;
                    {
                      auto dsum1_fst_183 { std::get<0>(dsum1_182) };
                      auto dsum1_snd_184 { std::get<1>(dsum1_182) };
                      uint16_t id_2423 { 0 };
                      bool id_2424 { bool(dsum1_fst_183 == id_2423) };
                      Void id_2425 { ((void)(assert(id_2424)), ::dessser::VOID) };
                      (void)id_2425;
                      (void)::dessser::VOID;
                      ::dessser::gen::sync_key::t64d562ea504a9ce27a59b90c4e554a51 id_2426 { std::in_place_index<0>, ::dessser::VOID };
                      ::dessser::gen::sync_key::t861fec96932eb3dcd604deb55a8fed37 id_2427 { dtup_fst_174, id_2426 };
                      std::shared_ptr<::dessser::gen::sync_key::per_site_data>  id_2428 { std::make_shared<::dessser::gen::sync_key::per_site_data>(std::in_place_index<3>, id_2427) };
                      ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab id_2429 { id_2428, dsum1_snd_184 };
                      letpair_res_2422 = id_2429;
                    }
                    let_res_2421 = letpair_res_2422;
                  }
                  letpair_res_2417 = let_res_2421;
                }
                let_res_2416 = letpair_res_2417;
              }
              choose_res_2361 = let_res_2416;
            }
            choose_res_2290 = choose_res_2361;
          }
          choose_res_2285 = choose_res_2290;
        }
        letpair_res_2282 = choose_res_2285;
      }
      let_res_2281 = letpair_res_2282;
    }
    return let_res_2281;
  }
   };
  return fun2277;
}
std::function<::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab(Pointer)> per_site_data_of_row_binary(per_site_data_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dtup_236" (apply (ext-identifier site_name of-row-binary) (param 0))
        (let-pair "dtup_fst_237" "dtup_snd_238" (identifier "dtup_236")
          (let-pair "dtup_fst_240" "dtup_snd_241" (apply (identifier "per_site_data-of-row-binary") (identifier "dtup_snd_238"))
            (make-tup (make-tup (identifier "dtup_fst_237") (identifier "dtup_fst_240")) (identifier "dtup_snd_241"))))))
 */
static std::function<::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581(Pointer)> per_site_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581(Pointer)> fun2430 { [&fun2430](Pointer p_0) {
    auto fun2431 { dessser::gen::site_name::of_row_binary };
    ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 id_2432 { fun2431(p_0) };
    ::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581 let_res_2433;
    {
      ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 dtup_236 { id_2432 };
      ::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581 letpair_res_2434;
      {
        auto dtup_fst_237 { std::get<0>(dtup_236) };
        auto dtup_snd_238 { std::get<1>(dtup_236) };
        ::dessser::gen::sync_key::tc0947ce7e9d20fe4fd59f16145aef5ab id_2435 { per_site_data_of_row_binary(dtup_snd_238) };
        ::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581 letpair_res_2436;
        {
          auto dtup_fst_240 { std::get<0>(id_2435) };
          auto dtup_snd_241 { std::get<1>(id_2435) };
          std::shared_ptr<::dessser::gen::sync_key::per_site>  id_2437 { std::make_shared<::dessser::gen::sync_key::per_site>(dtup_fst_237, dtup_fst_240) };
          ::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581 id_2438 { id_2437, dtup_snd_241 };
          letpair_res_2436 = id_2438;
        }
        letpair_res_2434 = letpair_res_2436;
      }
      let_res_2433 = letpair_res_2434;
    }
    return let_res_2433;
  }
   };
  return fun2430;
}
std::function<::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581(Pointer)> per_site_of_row_binary(per_site_of_row_binary_init());

/* 
    (fun ("Ptr")
      (let "dsum1_410" (let-pair "du16_fst_405" "du16_snd_406" (read-u16 little-endian (param 0)) (make-tup (identifier "du16_fst_405") (identifier "du16_snd_406")))
        (let-pair "dsum1_fst_411" "dsum1_snd_412" (identifier "dsum1_410")
          (if (eq (u16 0) (identifier "dsum1_fst_411"))
            (make-tup
              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 0
                (nop)) (identifier "dsum1_snd_412"))
            (if (eq (u16 1) (identifier "dsum1_fst_411"))
              (make-tup
                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 1
                  (nop)) (identifier "dsum1_snd_412"))
              (if (eq (u16 2) (identifier "dsum1_fst_411"))
                (let "dstring1_623"
                  (let "leb_ref_617" (make-vec (u32 0))
                    (let "shft_ref_618" (make-vec (u8 0))
                      (let "p_ref_619" (make-vec (identifier "dsum1_snd_412"))
                        (seq
                          (while
                            (let "leb128_620" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_619")))
                              (let-pair "leb128_fst_621" "leb128_snd_622" 
                                (identifier "leb128_620")
                                (seq (set-vec (u8 0) (identifier "p_ref_619") (identifier "leb128_snd_622"))
                                  (set-vec (u8 0) (identifier "leb_ref_617")
                                    (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_621") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_618"))) (unsafe-nth (u8 0) (identifier "leb_ref_617"))))
                                  (set-vec (u8 0) (identifier "shft_ref_618") (add (unsafe-nth (u8 0) (identifier "shft_ref_618")) (u8 7))) 
                                  (ge (identifier "leb128_fst_621") (u8 128))))) 
                            (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_617"))) (unsafe-nth (u8 0) (identifier "p_ref_619")))))))
                  (let-pair "dstring1_fst_624" "dstring1_snd_625" (identifier "dstring1_623")
                    (let-pair "dstring2_fst_627" "dstring2_snd_628" (read-bytes (identifier "dstring1_snd_625") (identifier "dstring1_fst_624"))
                      (make-tup
                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 2
                          (string-of-bytes (identifier "dstring2_fst_627"))) 
                        (identifier "dstring2_snd_628")))))
                (if (eq (u16 3) (identifier "dsum1_fst_411"))
                  (let "dtup_596" (apply (ext-identifier src_path of-row-binary) (identifier "dsum1_snd_412"))
                    (let-pair "dtup_fst_597" "dtup_snd_598" (identifier "dtup_596")
                      (let "dstring1_605"
                        (let "leb_ref_599" (make-vec (u32 0))
                          (let "shft_ref_600" (make-vec (u8 0))
                            (let "p_ref_601" (make-vec (identifier "dtup_snd_598"))
                              (seq
                                (while
                                  (let "leb128_602" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_601")))
                                    (let-pair "leb128_fst_603" "leb128_snd_604" 
                                      (identifier "leb128_602")
                                      (seq (set-vec (u8 0) (identifier "p_ref_601") (identifier "leb128_snd_604"))
                                        (set-vec (u8 0) (identifier "leb_ref_599")
                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_603") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_600"))) (unsafe-nth (u8 0) (identifier "leb_ref_599"))))
                                        (set-vec (u8 0) (identifier "shft_ref_600") (add (unsafe-nth (u8 0) (identifier "shft_ref_600")) (u8 7))) 
                                        (ge (identifier "leb128_fst_603") (u8 128))))) 
                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_599"))) (unsafe-nth (u8 0) (identifier "p_ref_601")))))))
                        (let-pair "dstring1_fst_606" "dstring1_snd_607" 
                          (identifier "dstring1_605")
                          (let-pair "dstring2_fst_609" "dstring2_snd_610" 
                            (read-bytes (identifier "dstring1_snd_607") (identifier "dstring1_fst_606"))
                            (make-tup
                              (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 3
                                (make-tup (identifier "dtup_fst_597") (string-of-bytes (identifier "dstring2_fst_609")))) 
                              (identifier "dstring2_snd_610")))))))
                  (if (eq (u16 4) (identifier "dsum1_fst_411"))
                    (make-tup
                      (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 4
                        (nop)) (identifier "dsum1_snd_412"))
                    (if (eq (u16 5) (identifier "dsum1_fst_411"))
                      (let-pair "dsum2_fst_591" "dsum2_snd_592" (apply (identifier "per_site-of-row-binary") (identifier "dsum1_snd_412"))
                        (make-tup
                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 5
                            (identifier "dsum2_fst_591")) (identifier "dsum2_snd_592")))
                      (if (eq (u16 6) (identifier "dsum1_fst_411"))
                        (let-pair "dsum2_fst_588" "dsum2_snd_589"
                          (let "dsum1_563" (let-pair "du16_fst_558" "du16_snd_559" (read-u16 little-endian (identifier "dsum1_snd_412")) (make-tup (identifier "du16_fst_558") (identifier "du16_snd_559")))
                            (let-pair "dsum1_fst_564" "dsum1_snd_565" 
                              (identifier "dsum1_563")
                              (if (eq (u16 0) (identifier "dsum1_fst_564")) 
                                (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 0 (nop)) (identifier "dsum1_snd_565"))
                                (if (eq (u16 1) (identifier "dsum1_fst_564")) 
                                  (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 1 (nop)) (identifier "dsum1_snd_565"))
                                  (seq (assert (eq (identifier "dsum1_fst_564") (u16 2)))
                                    (let "dstring1_572"
                                      (let "leb_ref_566" (make-vec (u32 0))
                                        (let "shft_ref_567" (make-vec (u8 0))
                                          (let "p_ref_568" (make-vec (identifier "dsum1_snd_565"))
                                            (seq
                                              (while
                                                (let "leb128_569" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_568")))
                                                  (let-pair "leb128_fst_570" "leb128_snd_571" 
                                                    (identifier "leb128_569")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_568") (identifier "leb128_snd_571"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_566")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_570") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_567")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_566")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_567") (add (unsafe-nth (u8 0) (identifier "shft_ref_567")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_570") (u8 128))))) 
                                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_566"))) (unsafe-nth (u8 0) (identifier "p_ref_568")))))))
                                      (let-pair "dstring1_fst_573" "dstring1_snd_574" 
                                        (identifier "dstring1_572")
                                        (let-pair "dstring2_fst_576" "dstring2_snd_577" 
                                          (read-bytes (identifier "dstring1_snd_574") (identifier "dstring1_fst_573"))
                                          (make-tup (construct "[TotalSize Void | RecallCost Void | RetentionsOverride STRING]" 2 (string-of-bytes (identifier "dstring2_fst_576"))) (identifier "dstring2_snd_577"))))))))))
                          (make-tup
                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 6
                              (identifier "dsum2_fst_588")) (identifier "dsum2_snd_589")))
                        (if (eq (u16 7) (identifier "dsum1_fst_411"))
                          (let "dtup_530" (apply (ext-identifier site_name of-row-binary) (identifier "dsum1_snd_412"))
                            (let-pair "dtup_fst_531" "dtup_snd_532" (identifier "dtup_530")
                              (let "dtup_533" (apply (ext-identifier fq_name of-row-binary) (identifier "dtup_snd_532"))
                                (let-pair "dtup_fst_534" "dtup_snd_535" 
                                  (identifier "dtup_533")
                                  (let "dtup_548"
                                    (let "dstring1_542"
                                      (let "leb_ref_536" (make-vec (u32 0))
                                        (let "shft_ref_537" (make-vec (u8 0))
                                          (let "p_ref_538" (make-vec (identifier "dtup_snd_535"))
                                            (seq
                                              (while
                                                (let "leb128_539" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_538")))
                                                  (let-pair "leb128_fst_540" "leb128_snd_541" 
                                                    (identifier "leb128_539")
                                                    (seq (set-vec (u8 0) (identifier "p_ref_538") (identifier "leb128_snd_541"))
                                                      (set-vec (u8 0) 
                                                        (identifier "leb_ref_536")
                                                        (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_540") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_537")))
                                                          (unsafe-nth (u8 0) (identifier "leb_ref_536")))) 
                                                      (set-vec (u8 0) (identifier "shft_ref_537") (add (unsafe-nth (u8 0) (identifier "shft_ref_537")) (u8 7))) 
                                                      (ge (identifier "leb128_fst_540") (u8 128))))) 
                                                (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_536"))) (unsafe-nth (u8 0) (identifier "p_ref_538")))))))
                                      (let-pair "dstring1_fst_543" "dstring1_snd_544" 
                                        (identifier "dstring1_542")
                                        (let-pair "dstring2_fst_546" "dstring2_snd_547" 
                                          (read-bytes (identifier "dstring1_snd_544") (identifier "dstring1_fst_543")) 
                                          (make-tup (string-of-bytes (identifier "dstring2_fst_546")) (identifier "dstring2_snd_547")))))
                                    (let-pair "dtup_fst_549" "dtup_snd_550" 
                                      (identifier "dtup_548")
                                      (let-pair "dtup_fst_552" "dtup_snd_553" 
                                        (apply (identifier "per_tail-of-row-binary") (identifier "dtup_snd_550"))
                                        (make-tup
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 7
                                            (make-tup (identifier "dtup_fst_531") (identifier "dtup_fst_534") (identifier "dtup_fst_549") (identifier "dtup_fst_552"))) 
                                          (identifier "dtup_snd_553")))))))))
                          (if (eq (u16 8) (identifier "dsum1_fst_411"))
                            (let-pair "du16_fst_525" "du16_snd_526" (read-u16 little-endian (identifier "dsum1_snd_412"))
                              (make-tup
                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 8
                                  (identifier "du16_fst_525")) (identifier "du16_snd_526")))
                            (if (eq (u16 9) (identifier "dsum1_fst_411"))
                              (let-pair "dsum2_fst_522" "dsum2_snd_523"
                                (if (eq (peek-u8 (identifier "dsum1_snd_412") (size 0)) (u8 1)) 
                                  (make-tup (null "$sync_socket") (ptr-add (identifier "dsum1_snd_412") (size 1)))
                                  (let-pair "make1_1_fst_519" "make1_1_snd_520" 
                                    (apply (ext-identifier sync_socket of-row-binary) (ptr-add (identifier "dsum1_snd_412") (size 1))) 
                                    (make-tup (not-null (identifier "make1_1_fst_519")) (identifier "make1_1_snd_520"))))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 9
                                    (identifier "dsum2_fst_522")) (identifier "dsum2_snd_523")))
                              (if (eq (u16 10) (identifier "dsum1_fst_411"))
                                (make-tup
                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 10
                                    (nop)) (identifier "dsum1_snd_412"))
                                (if (eq (u16 11) (identifier "dsum1_fst_411"))
                                  (let "dtup_506" (apply (ext-identifier sync_socket of-row-binary) (identifier "dsum1_snd_412"))
                                    (let-pair "dtup_fst_507" "dtup_snd_508" 
                                      (identifier "dtup_506")
                                      (let-pair "dtup_fst_510" "dtup_snd_511" 
                                        (apply (identifier "per_client-of-row-binary") (identifier "dtup_snd_508"))
                                        (make-tup
                                          (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 11
                                            (make-tup (identifier "dtup_fst_507") (identifier "dtup_fst_510"))) 
                                          (identifier "dtup_snd_511")))))
                                  (if (eq (u16 12) (identifier "dsum1_fst_411"))
                                    (let "dtup_497"
                                      (let "dstring1_491"
                                        (let "leb_ref_485" (make-vec (u32 0))
                                          (let "shft_ref_486" (make-vec (u8 0))
                                            (let "p_ref_487" (make-vec (identifier "dsum1_snd_412"))
                                              (seq
                                                (while
                                                  (let "leb128_488" (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_487")))
                                                    (let-pair "leb128_fst_489" "leb128_snd_490" 
                                                      (identifier "leb128_488")
                                                      (seq (set-vec (u8 0) (identifier "p_ref_487") (identifier "leb128_snd_490"))
                                                        (set-vec (u8 0) 
                                                          (identifier "leb_ref_485")
                                                          (bit-or (left-shift (to-u32 (bit-and (identifier "leb128_fst_489") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_486")))
                                                            (unsafe-nth (u8 0) (identifier "leb_ref_485")))) 
                                                        (set-vec (u8 0) (identifier "shft_ref_486") (add (unsafe-nth (u8 0) (identifier "shft_ref_486")) (u8 7))) 
                                                        (ge (identifier "leb128_fst_489") (u8 128))))) 
                                                  (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_485"))) (unsafe-nth (u8 0) (identifier "p_ref_487")))))))
                                        (let-pair "dstring1_fst_492" "dstring1_snd_493" 
                                          (identifier "dstring1_491")
                                          (let-pair "dstring2_fst_495" "dstring2_snd_496" 
                                            (read-bytes (identifier "dstring1_snd_493") (identifier "dstring1_fst_492")) 
                                            (make-tup (string-of-bytes (identifier "dstring2_fst_495")) (identifier "dstring2_snd_496")))))
                                      (let-pair "dtup_fst_498" "dtup_snd_499" 
                                        (identifier "dtup_497")
                                        (let-pair "dtup_fst_501" "dtup_snd_502" 
                                          (apply (identifier "per_dash_key-of-row-binary") (identifier "dtup_snd_499"))
                                          (make-tup
                                            (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 12
                                              (make-tup (identifier "dtup_fst_498") (identifier "dtup_fst_501"))) 
                                            (identifier "dtup_snd_502")))))
                                    (if (eq (u16 13) (identifier "dsum1_fst_411"))
                                      (make-tup
                                        (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 13
                                          (nop)) (identifier "dsum1_snd_412"))
                                      (if (eq (u16 14) (identifier "dsum1_fst_411"))
                                        (let "dtup_434" (apply (ext-identifier team_name of-row-binary) (identifier "dsum1_snd_412"))
                                          (let-pair "dtup_fst_435" "dtup_snd_436" 
                                            (identifier "dtup_434")
                                            (let-pair "dtup_fst_477" "dtup_snd_478"
                                              (let "dsum1_443" (let-pair "du16_fst_438" "du16_snd_439" (read-u16 little-endian (identifier "dtup_snd_436")) (make-tup (identifier "du16_fst_438") (identifier "du16_snd_439")))
                                                (let-pair "dsum1_fst_444" "dsum1_snd_445" 
                                                  (identifier "dsum1_443")
                                                  (if (eq (u16 0) (identifier "dsum1_fst_444"))
                                                    (let "dstring1_467"
                                                      (let "leb_ref_461" 
                                                        (make-vec (u32 0))
                                                        (let "shft_ref_462" 
                                                          (make-vec (u8 0))
                                                          (let "p_ref_463" 
                                                            (make-vec (identifier "dsum1_snd_445"))
                                                            (seq
                                                              (while
                                                                (let "leb128_464" 
                                                                  (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_463")))
                                                                  (let-pair "leb128_fst_465" "leb128_snd_466" 
                                                                    (identifier "leb128_464")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_463") (identifier "leb128_snd_466"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_461")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_465") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_462")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_461")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_462") (add (unsafe-nth (u8 0) (identifier "shft_ref_462")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_465") (u8 128))))) 
                                                                (nop)) 
                                                              (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_461"))) (unsafe-nth (u8 0) (identifier "p_ref_463")))))))
                                                      (let-pair "dstring1_fst_468" "dstring1_snd_469" 
                                                        (identifier "dstring1_467")
                                                        (let-pair "dstring2_fst_471" "dstring2_snd_472" 
                                                          (read-bytes (identifier "dstring1_snd_469") (identifier "dstring1_fst_468"))
                                                          (make-tup (construct "[Contacts STRING | Inhibition STRING]" 0 (string-of-bytes (identifier "dstring2_fst_471"))) (identifier "dstring2_snd_472")))))
                                                    (seq (assert (eq (identifier "dsum1_fst_444") (u16 1)))
                                                      (let "dstring1_452"
                                                        (let "leb_ref_446" 
                                                          (make-vec (u32 0))
                                                          (let "shft_ref_447" 
                                                            (make-vec (u8 0))
                                                            (let "p_ref_448" 
                                                              (make-vec (identifier "dsum1_snd_445"))
                                                              (seq
                                                                (while
                                                                  (let "leb128_449" 
                                                                    (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_448")))
                                                                    (let-pair "leb128_fst_450" "leb128_snd_451" 
                                                                    (identifier "leb128_449")
                                                                    (seq 
                                                                    (set-vec (u8 0) (identifier "p_ref_448") (identifier "leb128_snd_451"))
                                                                    (set-vec 
                                                                    (u8 0) 
                                                                    (identifier "leb_ref_446")
                                                                    (bit-or 
                                                                    (left-shift (to-u32 (bit-and (identifier "leb128_fst_450") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_447")))
                                                                    (unsafe-nth (u8 0) (identifier "leb_ref_446")))) 
                                                                    (set-vec (u8 0) (identifier "shft_ref_447") (add (unsafe-nth (u8 0) (identifier "shft_ref_447")) (u8 7))) 
                                                                    (ge (identifier "leb128_fst_450") (u8 128))))) 
                                                                  (nop)) 
                                                                (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_446"))) (unsafe-nth (u8 0) (identifier "p_ref_448")))))))
                                                        (let-pair "dstring1_fst_453" "dstring1_snd_454" 
                                                          (identifier "dstring1_452")
                                                          (let-pair "dstring2_fst_456" "dstring2_snd_457" 
                                                            (read-bytes (identifier "dstring1_snd_454") (identifier "dstring1_fst_453"))
                                                            (make-tup (construct "[Contacts STRING | Inhibition STRING]" 1 (string-of-bytes (identifier "dstring2_fst_456"))) (identifier "dstring2_snd_457")))))))))
                                              (make-tup
                                                (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 14
                                                  (make-tup (identifier "dtup_fst_435") (identifier "dtup_fst_477"))) 
                                                (identifier "dtup_snd_478")))))
                                        (seq (assert (eq (identifier "dsum1_fst_411") (u16 15)))
                                          (let "dtup_425"
                                            (let "dstring1_419"
                                              (let "leb_ref_413" (make-vec (u32 0))
                                                (let "shft_ref_414" (make-vec (u8 0))
                                                  (let "p_ref_415" (make-vec (identifier "dsum1_snd_412"))
                                                    (seq
                                                      (while
                                                        (let "leb128_416" 
                                                          (read-u8 (unsafe-nth (u8 0) (identifier "p_ref_415")))
                                                          (let-pair "leb128_fst_417" "leb128_snd_418" 
                                                            (identifier "leb128_416")
                                                            (seq (set-vec (u8 0) (identifier "p_ref_415") (identifier "leb128_snd_418"))
                                                              (set-vec 
                                                                (u8 0) 
                                                                (identifier "leb_ref_413")
                                                                (bit-or 
                                                                  (left-shift (to-u32 (bit-and (identifier "leb128_fst_417") (u8 127))) (unsafe-nth (u8 0) (identifier "shft_ref_414")))
                                                                  (unsafe-nth (u8 0) (identifier "leb_ref_413")))) 
                                                              (set-vec (u8 0) (identifier "shft_ref_414") (add (unsafe-nth (u8 0) (identifier "shft_ref_414")) (u8 7))) 
                                                              (ge (identifier "leb128_fst_417") (u8 128))))) 
                                                        (nop)) (make-tup (size-of-u32 (unsafe-nth (u8 0) (identifier "leb_ref_413"))) (unsafe-nth (u8 0) (identifier "p_ref_415")))))))
                                              (let-pair "dstring1_fst_420" "dstring1_snd_421" 
                                                (identifier "dstring1_419")
                                                (let-pair "dstring2_fst_423" "dstring2_snd_424" 
                                                  (read-bytes (identifier "dstring1_snd_421") (identifier "dstring1_fst_420")) 
                                                  (make-tup (string-of-bytes (identifier "dstring2_fst_423")) (identifier "dstring2_snd_424")))))
                                            (let-pair "dtup_fst_426" "dtup_snd_427" 
                                              (identifier "dtup_425")
                                              (let-pair "dtup_fst_429" "dtup_snd_430" 
                                                (apply (identifier "incident_key-of-row-binary") (identifier "dtup_snd_427"))
                                                (make-tup
                                                  (construct "[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" 15
                                                    (make-tup (identifier "dtup_fst_426") (identifier "dtup_fst_429"))) 
                                                  (identifier "dtup_snd_430"))))))))))))))))))))))))
 */
static std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> fun2439 { [&fun2439](Pointer p_0) {
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2440 { p_0.readU16Le() };
    ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2441;
    {
      auto du16_fst_405 { std::get<0>(id_2440) };
      auto du16_snd_406 { std::get<1>(id_2440) };
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2442 { du16_fst_405, du16_snd_406 };
      letpair_res_2441 = id_2442;
    }
    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2443;
    {
      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_410 { letpair_res_2441 };
      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2444;
      {
        auto dsum1_fst_411 { std::get<0>(dsum1_410) };
        auto dsum1_snd_412 { std::get<1>(dsum1_410) };
        uint16_t id_2445 { 0 };
        bool id_2446 { bool(id_2445 == dsum1_fst_411) };
        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2447;
        if (id_2446) {
          (void)::dessser::VOID;
          std::shared_ptr<::dessser::gen::sync_key::t>  id_2448 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<0>, ::dessser::VOID) };
          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2449 { id_2448, dsum1_snd_412 };
          choose_res_2447 = id_2449;
        } else {
          uint16_t id_2450 { 1 };
          bool id_2451 { bool(id_2450 == dsum1_fst_411) };
          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2452;
          if (id_2451) {
            (void)::dessser::VOID;
            std::shared_ptr<::dessser::gen::sync_key::t>  id_2453 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<1>, ::dessser::VOID) };
            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2454 { id_2453, dsum1_snd_412 };
            choose_res_2452 = id_2454;
          } else {
            uint16_t id_2455 { 2 };
            bool id_2456 { bool(id_2455 == dsum1_fst_411) };
            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2457;
            if (id_2456) {
              uint32_t id_2458 { 0U };
              Vec<1, uint32_t> id_2459 {  id_2458  };
              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2460;
              {
                Vec<1, uint32_t> leb_ref_617 { id_2459 };
                uint8_t id_2461 { 0 };
                Vec<1, uint8_t> id_2462 {  id_2461  };
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2463;
                {
                  Vec<1, uint8_t> shft_ref_618 { id_2462 };
                  Vec<1, Pointer> id_2464 {  dsum1_snd_412  };
                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2465;
                  {
                    Vec<1, Pointer> p_ref_619 { id_2464 };
                    bool while_flag_2466 { true };
                    do {
                      uint8_t id_2467 { 0 };
                      Pointer id_2468 { p_ref_619[id_2467] };
                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2469 { id_2468.readU8() };
                      bool let_res_2470;
                      {
                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_620 { id_2469 };
                        bool letpair_res_2471;
                        {
                          auto leb128_fst_621 { std::get<0>(leb128_620) };
                          auto leb128_snd_622 { std::get<1>(leb128_620) };
                          uint8_t id_2472 { 0 };
                          Void id_2473 { ((void)(p_ref_619[id_2472] = leb128_snd_622), ::dessser::VOID) };
                          (void)id_2473;
                          uint8_t id_2474 { 0 };
                          uint8_t id_2475 { 127 };
                          uint8_t id_2476 { uint8_t(leb128_fst_621 & id_2475) };
                          uint32_t id_2477 { uint32_t(id_2476) };
                          uint8_t id_2478 { 0 };
                          uint8_t id_2479 { shft_ref_618[id_2478] };
                          uint32_t id_2480 { uint32_t(id_2477 << id_2479) };
                          uint8_t id_2481 { 0 };
                          uint32_t id_2482 { leb_ref_617[id_2481] };
                          uint32_t id_2483 { uint32_t(id_2480 | id_2482) };
                          Void id_2484 { ((void)(leb_ref_617[id_2474] = id_2483), ::dessser::VOID) };
                          (void)id_2484;
                          uint8_t id_2485 { 0 };
                          uint8_t id_2486 { 0 };
                          uint8_t id_2487 { shft_ref_618[id_2486] };
                          uint8_t id_2488 { 7 };
                          uint8_t id_2489 { uint8_t(id_2487 + id_2488) };
                          Void id_2490 { ((void)(shft_ref_618[id_2485] = id_2489), ::dessser::VOID) };
                          (void)id_2490;
                          uint8_t id_2491 { 128 };
                          bool id_2492 { bool(leb128_fst_621 >= id_2491) };
                          letpair_res_2471 = id_2492;
                        }
                        let_res_2470 = letpair_res_2471;
                      }
                      while_flag_2466 = let_res_2470;
                      if (while_flag_2466) {
                        (void)::dessser::VOID;
                      }
                    } while (while_flag_2466);
                    (void)::dessser::VOID;
                    uint8_t id_2493 { 0 };
                    uint32_t id_2494 { leb_ref_617[id_2493] };
                    Size id_2495 { Size(id_2494) };
                    uint8_t id_2496 { 0 };
                    Pointer id_2497 { p_ref_619[id_2496] };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2498 { id_2495, id_2497 };
                    let_res_2465 = id_2498;
                  }
                  let_res_2463 = let_res_2465;
                }
                let_res_2460 = let_res_2463;
              }
              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2499;
              {
                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_623 { let_res_2460 };
                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2500;
                {
                  auto dstring1_fst_624 { std::get<0>(dstring1_623) };
                  auto dstring1_snd_625 { std::get<1>(dstring1_623) };
                  ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2501 { dstring1_snd_625.readBytes(dstring1_fst_624) };
                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2502;
                  {
                    auto dstring2_fst_627 { std::get<0>(id_2501) };
                    auto dstring2_snd_628 { std::get<1>(id_2501) };
                    std::string id_2503 { dstring2_fst_627.toString() };
                    std::shared_ptr<::dessser::gen::sync_key::t>  id_2504 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<2>, id_2503) };
                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2505 { id_2504, dstring2_snd_628 };
                    letpair_res_2502 = id_2505;
                  }
                  letpair_res_2500 = letpair_res_2502;
                }
                let_res_2499 = letpair_res_2500;
              }
              choose_res_2457 = let_res_2499;
            } else {
              uint16_t id_2506 { 3 };
              bool id_2507 { bool(id_2506 == dsum1_fst_411) };
              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2508;
              if (id_2507) {
                auto fun2509 { dessser::gen::src_path::of_row_binary };
                ::dessser::gen::sync_key::t6915129216bc7fcac0c82f38ea6cfec8 id_2510 { fun2509(dsum1_snd_412) };
                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2511;
                {
                  ::dessser::gen::sync_key::t6915129216bc7fcac0c82f38ea6cfec8 dtup_596 { id_2510 };
                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2512;
                  {
                    auto dtup_fst_597 { std::get<0>(dtup_596) };
                    auto dtup_snd_598 { std::get<1>(dtup_596) };
                    uint32_t id_2513 { 0U };
                    Vec<1, uint32_t> id_2514 {  id_2513  };
                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2515;
                    {
                      Vec<1, uint32_t> leb_ref_599 { id_2514 };
                      uint8_t id_2516 { 0 };
                      Vec<1, uint8_t> id_2517 {  id_2516  };
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2518;
                      {
                        Vec<1, uint8_t> shft_ref_600 { id_2517 };
                        Vec<1, Pointer> id_2519 {  dtup_snd_598  };
                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2520;
                        {
                          Vec<1, Pointer> p_ref_601 { id_2519 };
                          bool while_flag_2521 { true };
                          do {
                            uint8_t id_2522 { 0 };
                            Pointer id_2523 { p_ref_601[id_2522] };
                            ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2524 { id_2523.readU8() };
                            bool let_res_2525;
                            {
                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_602 { id_2524 };
                              bool letpair_res_2526;
                              {
                                auto leb128_fst_603 { std::get<0>(leb128_602) };
                                auto leb128_snd_604 { std::get<1>(leb128_602) };
                                uint8_t id_2527 { 0 };
                                Void id_2528 { ((void)(p_ref_601[id_2527] = leb128_snd_604), ::dessser::VOID) };
                                (void)id_2528;
                                uint8_t id_2529 { 0 };
                                uint8_t id_2530 { 127 };
                                uint8_t id_2531 { uint8_t(leb128_fst_603 & id_2530) };
                                uint32_t id_2532 { uint32_t(id_2531) };
                                uint8_t id_2533 { 0 };
                                uint8_t id_2534 { shft_ref_600[id_2533] };
                                uint32_t id_2535 { uint32_t(id_2532 << id_2534) };
                                uint8_t id_2536 { 0 };
                                uint32_t id_2537 { leb_ref_599[id_2536] };
                                uint32_t id_2538 { uint32_t(id_2535 | id_2537) };
                                Void id_2539 { ((void)(leb_ref_599[id_2529] = id_2538), ::dessser::VOID) };
                                (void)id_2539;
                                uint8_t id_2540 { 0 };
                                uint8_t id_2541 { 0 };
                                uint8_t id_2542 { shft_ref_600[id_2541] };
                                uint8_t id_2543 { 7 };
                                uint8_t id_2544 { uint8_t(id_2542 + id_2543) };
                                Void id_2545 { ((void)(shft_ref_600[id_2540] = id_2544), ::dessser::VOID) };
                                (void)id_2545;
                                uint8_t id_2546 { 128 };
                                bool id_2547 { bool(leb128_fst_603 >= id_2546) };
                                letpair_res_2526 = id_2547;
                              }
                              let_res_2525 = letpair_res_2526;
                            }
                            while_flag_2521 = let_res_2525;
                            if (while_flag_2521) {
                              (void)::dessser::VOID;
                            }
                          } while (while_flag_2521);
                          (void)::dessser::VOID;
                          uint8_t id_2548 { 0 };
                          uint32_t id_2549 { leb_ref_599[id_2548] };
                          Size id_2550 { Size(id_2549) };
                          uint8_t id_2551 { 0 };
                          Pointer id_2552 { p_ref_601[id_2551] };
                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2553 { id_2550, id_2552 };
                          let_res_2520 = id_2553;
                        }
                        let_res_2518 = let_res_2520;
                      }
                      let_res_2515 = let_res_2518;
                    }
                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2554;
                    {
                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_605 { let_res_2515 };
                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2555;
                      {
                        auto dstring1_fst_606 { std::get<0>(dstring1_605) };
                        auto dstring1_snd_607 { std::get<1>(dstring1_605) };
                        ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2556 { dstring1_snd_607.readBytes(dstring1_fst_606) };
                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2557;
                        {
                          auto dstring2_fst_609 { std::get<0>(id_2556) };
                          auto dstring2_snd_610 { std::get<1>(id_2556) };
                          std::string id_2558 { dstring2_fst_609.toString() };
                          ::dessser::gen::sync_key::t5dbfadfb7b29c686ebe36a9b92f12903 id_2559 { dtup_fst_597, id_2558 };
                          std::shared_ptr<::dessser::gen::sync_key::t>  id_2560 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<3>, id_2559) };
                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2561 { id_2560, dstring2_snd_610 };
                          letpair_res_2557 = id_2561;
                        }
                        letpair_res_2555 = letpair_res_2557;
                      }
                      let_res_2554 = letpair_res_2555;
                    }
                    letpair_res_2512 = let_res_2554;
                  }
                  let_res_2511 = letpair_res_2512;
                }
                choose_res_2508 = let_res_2511;
              } else {
                uint16_t id_2562 { 4 };
                bool id_2563 { bool(id_2562 == dsum1_fst_411) };
                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2564;
                if (id_2563) {
                  (void)::dessser::VOID;
                  std::shared_ptr<::dessser::gen::sync_key::t>  id_2565 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<4>, ::dessser::VOID) };
                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2566 { id_2565, dsum1_snd_412 };
                  choose_res_2564 = id_2566;
                } else {
                  uint16_t id_2567 { 5 };
                  bool id_2568 { bool(id_2567 == dsum1_fst_411) };
                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2569;
                  if (id_2568) {
                    ::dessser::gen::sync_key::tf1d5e8699e2fb10ae586f67c483db581 id_2570 { per_site_of_row_binary(dsum1_snd_412) };
                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2571;
                    {
                      auto dsum2_fst_591 { std::get<0>(id_2570) };
                      auto dsum2_snd_592 { std::get<1>(id_2570) };
                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2572 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<5>, dsum2_fst_591) };
                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2573 { id_2572, dsum2_snd_592 };
                      letpair_res_2571 = id_2573;
                    }
                    choose_res_2569 = letpair_res_2571;
                  } else {
                    uint16_t id_2574 { 6 };
                    bool id_2575 { bool(id_2574 == dsum1_fst_411) };
                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2576;
                    if (id_2575) {
                      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2577 { dsum1_snd_412.readU16Le() };
                      ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2578;
                      {
                        auto du16_fst_558 { std::get<0>(id_2577) };
                        auto du16_snd_559 { std::get<1>(id_2577) };
                        ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2579 { du16_fst_558, du16_snd_559 };
                        letpair_res_2578 = id_2579;
                      }
                      ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 let_res_2580;
                      {
                        ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_563 { letpair_res_2578 };
                        ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 letpair_res_2581;
                        {
                          auto dsum1_fst_564 { std::get<0>(dsum1_563) };
                          auto dsum1_snd_565 { std::get<1>(dsum1_563) };
                          uint16_t id_2582 { 0 };
                          bool id_2583 { bool(id_2582 == dsum1_fst_564) };
                          ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 choose_res_2584;
                          if (id_2583) {
                            (void)::dessser::VOID;
                            ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_2585 { std::in_place_index<0>, ::dessser::VOID };
                            ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 id_2586 { id_2585, dsum1_snd_565 };
                            choose_res_2584 = id_2586;
                          } else {
                            uint16_t id_2587 { 1 };
                            bool id_2588 { bool(id_2587 == dsum1_fst_564) };
                            ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 choose_res_2589;
                            if (id_2588) {
                              (void)::dessser::VOID;
                              ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_2590 { std::in_place_index<1>, ::dessser::VOID };
                              ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 id_2591 { id_2590, dsum1_snd_565 };
                              choose_res_2589 = id_2591;
                            } else {
                              uint16_t id_2592 { 2 };
                              bool id_2593 { bool(dsum1_fst_564 == id_2592) };
                              Void id_2594 { ((void)(assert(id_2593)), ::dessser::VOID) };
                              (void)id_2594;
                              uint32_t id_2595 { 0U };
                              Vec<1, uint32_t> id_2596 {  id_2595  };
                              ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2597;
                              {
                                Vec<1, uint32_t> leb_ref_566 { id_2596 };
                                uint8_t id_2598 { 0 };
                                Vec<1, uint8_t> id_2599 {  id_2598  };
                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2600;
                                {
                                  Vec<1, uint8_t> shft_ref_567 { id_2599 };
                                  Vec<1, Pointer> id_2601 {  dsum1_snd_565  };
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2602;
                                  {
                                    Vec<1, Pointer> p_ref_568 { id_2601 };
                                    bool while_flag_2603 { true };
                                    do {
                                      uint8_t id_2604 { 0 };
                                      Pointer id_2605 { p_ref_568[id_2604] };
                                      ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2606 { id_2605.readU8() };
                                      bool let_res_2607;
                                      {
                                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_569 { id_2606 };
                                        bool letpair_res_2608;
                                        {
                                          auto leb128_fst_570 { std::get<0>(leb128_569) };
                                          auto leb128_snd_571 { std::get<1>(leb128_569) };
                                          uint8_t id_2609 { 0 };
                                          Void id_2610 { ((void)(p_ref_568[id_2609] = leb128_snd_571), ::dessser::VOID) };
                                          (void)id_2610;
                                          uint8_t id_2611 { 0 };
                                          uint8_t id_2612 { 127 };
                                          uint8_t id_2613 { uint8_t(leb128_fst_570 & id_2612) };
                                          uint32_t id_2614 { uint32_t(id_2613) };
                                          uint8_t id_2615 { 0 };
                                          uint8_t id_2616 { shft_ref_567[id_2615] };
                                          uint32_t id_2617 { uint32_t(id_2614 << id_2616) };
                                          uint8_t id_2618 { 0 };
                                          uint32_t id_2619 { leb_ref_566[id_2618] };
                                          uint32_t id_2620 { uint32_t(id_2617 | id_2619) };
                                          Void id_2621 { ((void)(leb_ref_566[id_2611] = id_2620), ::dessser::VOID) };
                                          (void)id_2621;
                                          uint8_t id_2622 { 0 };
                                          uint8_t id_2623 { 0 };
                                          uint8_t id_2624 { shft_ref_567[id_2623] };
                                          uint8_t id_2625 { 7 };
                                          uint8_t id_2626 { uint8_t(id_2624 + id_2625) };
                                          Void id_2627 { ((void)(shft_ref_567[id_2622] = id_2626), ::dessser::VOID) };
                                          (void)id_2627;
                                          uint8_t id_2628 { 128 };
                                          bool id_2629 { bool(leb128_fst_570 >= id_2628) };
                                          letpair_res_2608 = id_2629;
                                        }
                                        let_res_2607 = letpair_res_2608;
                                      }
                                      while_flag_2603 = let_res_2607;
                                      if (while_flag_2603) {
                                        (void)::dessser::VOID;
                                      }
                                    } while (while_flag_2603);
                                    (void)::dessser::VOID;
                                    uint8_t id_2630 { 0 };
                                    uint32_t id_2631 { leb_ref_566[id_2630] };
                                    Size id_2632 { Size(id_2631) };
                                    uint8_t id_2633 { 0 };
                                    Pointer id_2634 { p_ref_568[id_2633] };
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2635 { id_2632, id_2634 };
                                    let_res_2602 = id_2635;
                                  }
                                  let_res_2600 = let_res_2602;
                                }
                                let_res_2597 = let_res_2600;
                              }
                              ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 let_res_2636;
                              {
                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_572 { let_res_2597 };
                                ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 letpair_res_2637;
                                {
                                  auto dstring1_fst_573 { std::get<0>(dstring1_572) };
                                  auto dstring1_snd_574 { std::get<1>(dstring1_572) };
                                  ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2638 { dstring1_snd_574.readBytes(dstring1_fst_573) };
                                  ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 letpair_res_2639;
                                  {
                                    auto dstring2_fst_576 { std::get<0>(id_2638) };
                                    auto dstring2_snd_577 { std::get<1>(id_2638) };
                                    std::string id_2640 { dstring2_fst_576.toString() };
                                    ::dessser::gen::sync_key::te22159e1728beb1685bbd47c6325049c id_2641 { std::in_place_index<2>, id_2640 };
                                    ::dessser::gen::sync_key::td062563cc812c1fd981608a011af2302 id_2642 { id_2641, dstring2_snd_577 };
                                    letpair_res_2639 = id_2642;
                                  }
                                  letpair_res_2637 = letpair_res_2639;
                                }
                                let_res_2636 = letpair_res_2637;
                              }
                              choose_res_2589 = let_res_2636;
                            }
                            choose_res_2584 = choose_res_2589;
                          }
                          letpair_res_2581 = choose_res_2584;
                        }
                        let_res_2580 = letpair_res_2581;
                      }
                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2643;
                      {
                        auto dsum2_fst_588 { std::get<0>(let_res_2580) };
                        auto dsum2_snd_589 { std::get<1>(let_res_2580) };
                        std::shared_ptr<::dessser::gen::sync_key::t>  id_2644 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<6>, dsum2_fst_588) };
                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2645 { id_2644, dsum2_snd_589 };
                        letpair_res_2643 = id_2645;
                      }
                      choose_res_2576 = letpair_res_2643;
                    } else {
                      uint16_t id_2646 { 7 };
                      bool id_2647 { bool(id_2646 == dsum1_fst_411) };
                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2648;
                      if (id_2647) {
                        auto fun2649 { dessser::gen::site_name::of_row_binary };
                        ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 id_2650 { fun2649(dsum1_snd_412) };
                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2651;
                        {
                          ::dessser::gen::sync_key::t5fda3fa18a9129079240e343cc4c7827 dtup_530 { id_2650 };
                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2652;
                          {
                            auto dtup_fst_531 { std::get<0>(dtup_530) };
                            auto dtup_snd_532 { std::get<1>(dtup_530) };
                            auto fun2653 { dessser::gen::fq_name::of_row_binary };
                            ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 id_2654 { fun2653(dtup_snd_532) };
                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2655;
                            {
                              ::dessser::gen::sync_key::t1067cf8ed87e4e016349f71797fb0661 dtup_533 { id_2654 };
                              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2656;
                              {
                                auto dtup_fst_534 { std::get<0>(dtup_533) };
                                auto dtup_snd_535 { std::get<1>(dtup_533) };
                                uint32_t id_2657 { 0U };
                                Vec<1, uint32_t> id_2658 {  id_2657  };
                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2659;
                                {
                                  Vec<1, uint32_t> leb_ref_536 { id_2658 };
                                  uint8_t id_2660 { 0 };
                                  Vec<1, uint8_t> id_2661 {  id_2660  };
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2662;
                                  {
                                    Vec<1, uint8_t> shft_ref_537 { id_2661 };
                                    Vec<1, Pointer> id_2663 {  dtup_snd_535  };
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2664;
                                    {
                                      Vec<1, Pointer> p_ref_538 { id_2663 };
                                      bool while_flag_2665 { true };
                                      do {
                                        uint8_t id_2666 { 0 };
                                        Pointer id_2667 { p_ref_538[id_2666] };
                                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2668 { id_2667.readU8() };
                                        bool let_res_2669;
                                        {
                                          ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_539 { id_2668 };
                                          bool letpair_res_2670;
                                          {
                                            auto leb128_fst_540 { std::get<0>(leb128_539) };
                                            auto leb128_snd_541 { std::get<1>(leb128_539) };
                                            uint8_t id_2671 { 0 };
                                            Void id_2672 { ((void)(p_ref_538[id_2671] = leb128_snd_541), ::dessser::VOID) };
                                            (void)id_2672;
                                            uint8_t id_2673 { 0 };
                                            uint8_t id_2674 { 127 };
                                            uint8_t id_2675 { uint8_t(leb128_fst_540 & id_2674) };
                                            uint32_t id_2676 { uint32_t(id_2675) };
                                            uint8_t id_2677 { 0 };
                                            uint8_t id_2678 { shft_ref_537[id_2677] };
                                            uint32_t id_2679 { uint32_t(id_2676 << id_2678) };
                                            uint8_t id_2680 { 0 };
                                            uint32_t id_2681 { leb_ref_536[id_2680] };
                                            uint32_t id_2682 { uint32_t(id_2679 | id_2681) };
                                            Void id_2683 { ((void)(leb_ref_536[id_2673] = id_2682), ::dessser::VOID) };
                                            (void)id_2683;
                                            uint8_t id_2684 { 0 };
                                            uint8_t id_2685 { 0 };
                                            uint8_t id_2686 { shft_ref_537[id_2685] };
                                            uint8_t id_2687 { 7 };
                                            uint8_t id_2688 { uint8_t(id_2686 + id_2687) };
                                            Void id_2689 { ((void)(shft_ref_537[id_2684] = id_2688), ::dessser::VOID) };
                                            (void)id_2689;
                                            uint8_t id_2690 { 128 };
                                            bool id_2691 { bool(leb128_fst_540 >= id_2690) };
                                            letpair_res_2670 = id_2691;
                                          }
                                          let_res_2669 = letpair_res_2670;
                                        }
                                        while_flag_2665 = let_res_2669;
                                        if (while_flag_2665) {
                                          (void)::dessser::VOID;
                                        }
                                      } while (while_flag_2665);
                                      (void)::dessser::VOID;
                                      uint8_t id_2692 { 0 };
                                      uint32_t id_2693 { leb_ref_536[id_2692] };
                                      Size id_2694 { Size(id_2693) };
                                      uint8_t id_2695 { 0 };
                                      Pointer id_2696 { p_ref_538[id_2695] };
                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2697 { id_2694, id_2696 };
                                      let_res_2664 = id_2697;
                                    }
                                    let_res_2662 = let_res_2664;
                                  }
                                  let_res_2659 = let_res_2662;
                                }
                                ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2698;
                                {
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_542 { let_res_2659 };
                                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2699;
                                  {
                                    auto dstring1_fst_543 { std::get<0>(dstring1_542) };
                                    auto dstring1_snd_544 { std::get<1>(dstring1_542) };
                                    ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2700 { dstring1_snd_544.readBytes(dstring1_fst_543) };
                                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2701;
                                    {
                                      auto dstring2_fst_546 { std::get<0>(id_2700) };
                                      auto dstring2_snd_547 { std::get<1>(id_2700) };
                                      std::string id_2702 { dstring2_fst_546.toString() };
                                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2703 { id_2702, dstring2_snd_547 };
                                      letpair_res_2701 = id_2703;
                                    }
                                    letpair_res_2699 = letpair_res_2701;
                                  }
                                  let_res_2698 = letpair_res_2699;
                                }
                                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2704;
                                {
                                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_548 { let_res_2698 };
                                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2705;
                                  {
                                    auto dtup_fst_549 { std::get<0>(dtup_548) };
                                    auto dtup_snd_550 { std::get<1>(dtup_548) };
                                    ::dessser::gen::sync_key::t4033af6a94e2f1d0f849f8e9c28f066e id_2706 { per_tail_of_row_binary(dtup_snd_550) };
                                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2707;
                                    {
                                      auto dtup_fst_552 { std::get<0>(id_2706) };
                                      auto dtup_snd_553 { std::get<1>(id_2706) };
                                      ::dessser::gen::sync_key::t2ffe933a548dbd220caa19cc4eccbdbc id_2708 { dtup_fst_531, dtup_fst_534, dtup_fst_549, dtup_fst_552 };
                                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2709 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<7>, id_2708) };
                                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2710 { id_2709, dtup_snd_553 };
                                      letpair_res_2707 = id_2710;
                                    }
                                    letpair_res_2705 = letpair_res_2707;
                                  }
                                  let_res_2704 = letpair_res_2705;
                                }
                                letpair_res_2656 = let_res_2704;
                              }
                              let_res_2655 = letpair_res_2656;
                            }
                            letpair_res_2652 = let_res_2655;
                          }
                          let_res_2651 = letpair_res_2652;
                        }
                        choose_res_2648 = let_res_2651;
                      } else {
                        uint16_t id_2711 { 8 };
                        bool id_2712 { bool(id_2711 == dsum1_fst_411) };
                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2713;
                        if (id_2712) {
                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2714 { dsum1_snd_412.readU16Le() };
                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2715;
                          {
                            auto du16_fst_525 { std::get<0>(id_2714) };
                            auto du16_snd_526 { std::get<1>(id_2714) };
                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2716 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<8>, du16_fst_525) };
                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2717 { id_2716, du16_snd_526 };
                            letpair_res_2715 = id_2717;
                          }
                          choose_res_2713 = letpair_res_2715;
                        } else {
                          uint16_t id_2718 { 9 };
                          bool id_2719 { bool(id_2718 == dsum1_fst_411) };
                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2720;
                          if (id_2719) {
                            Size id_2721 { 0UL };
                            uint8_t id_2722 { dsum1_snd_412.peekU8(id_2721) };
                            uint8_t id_2723 { 1 };
                            bool id_2724 { bool(id_2722 == id_2723) };
                            ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 choose_res_2725;
                            if (id_2724) {
                              std::optional<dessser::gen::sync_socket::t_ext> id_2726 { std::nullopt };
                              Size id_2727 { 1UL };
                              Pointer id_2728 { dsum1_snd_412.skip(id_2727) };
                              ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 id_2729 { id_2726, id_2728 };
                              choose_res_2725 = id_2729;
                            } else {
                              auto fun2730 { dessser::gen::sync_socket::of_row_binary };
                              Size id_2731 { 1UL };
                              Pointer id_2732 { dsum1_snd_412.skip(id_2731) };
                              ::dessser::gen::sync_key::tc3c0b466d06f5b0f1ffeebd3dab58a35 id_2733 { fun2730(id_2732) };
                              ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 letpair_res_2734;
                              {
                                auto make1_1_fst_519 { std::get<0>(id_2733) };
                                auto make1_1_snd_520 { std::get<1>(id_2733) };
                                std::optional<dessser::gen::sync_socket::t_ext> id_2735 { make1_1_fst_519 };
                                ::dessser::gen::sync_key::t012a36c0a466eec06183a69009335fa0 id_2736 { id_2735, make1_1_snd_520 };
                                letpair_res_2734 = id_2736;
                              }
                              choose_res_2725 = letpair_res_2734;
                            }
                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2737;
                            {
                              auto dsum2_fst_522 { std::get<0>(choose_res_2725) };
                              auto dsum2_snd_523 { std::get<1>(choose_res_2725) };
                              std::shared_ptr<::dessser::gen::sync_key::t>  id_2738 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<9>, dsum2_fst_522) };
                              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2739 { id_2738, dsum2_snd_523 };
                              letpair_res_2737 = id_2739;
                            }
                            choose_res_2720 = letpair_res_2737;
                          } else {
                            uint16_t id_2740 { 10 };
                            bool id_2741 { bool(id_2740 == dsum1_fst_411) };
                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2742;
                            if (id_2741) {
                              (void)::dessser::VOID;
                              std::shared_ptr<::dessser::gen::sync_key::t>  id_2743 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<10>, ::dessser::VOID) };
                              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2744 { id_2743, dsum1_snd_412 };
                              choose_res_2742 = id_2744;
                            } else {
                              uint16_t id_2745 { 11 };
                              bool id_2746 { bool(id_2745 == dsum1_fst_411) };
                              ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2747;
                              if (id_2746) {
                                auto fun2748 { dessser::gen::sync_socket::of_row_binary };
                                ::dessser::gen::sync_key::tc3c0b466d06f5b0f1ffeebd3dab58a35 id_2749 { fun2748(dsum1_snd_412) };
                                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2750;
                                {
                                  ::dessser::gen::sync_key::tc3c0b466d06f5b0f1ffeebd3dab58a35 dtup_506 { id_2749 };
                                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2751;
                                  {
                                    auto dtup_fst_507 { std::get<0>(dtup_506) };
                                    auto dtup_snd_508 { std::get<1>(dtup_506) };
                                    ::dessser::gen::sync_key::t56898a81c1f17af3902c13e6570a4796 id_2752 { per_client_of_row_binary(dtup_snd_508) };
                                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2753;
                                    {
                                      auto dtup_fst_510 { std::get<0>(id_2752) };
                                      auto dtup_snd_511 { std::get<1>(id_2752) };
                                      ::dessser::gen::sync_key::t5ea3af2f8623cdaebfc7634cbf90ee9c id_2754 { dtup_fst_507, dtup_fst_510 };
                                      std::shared_ptr<::dessser::gen::sync_key::t>  id_2755 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<11>, id_2754) };
                                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2756 { id_2755, dtup_snd_511 };
                                      letpair_res_2753 = id_2756;
                                    }
                                    letpair_res_2751 = letpair_res_2753;
                                  }
                                  let_res_2750 = letpair_res_2751;
                                }
                                choose_res_2747 = let_res_2750;
                              } else {
                                uint16_t id_2757 { 12 };
                                bool id_2758 { bool(id_2757 == dsum1_fst_411) };
                                ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2759;
                                if (id_2758) {
                                  uint32_t id_2760 { 0U };
                                  Vec<1, uint32_t> id_2761 {  id_2760  };
                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2762;
                                  {
                                    Vec<1, uint32_t> leb_ref_485 { id_2761 };
                                    uint8_t id_2763 { 0 };
                                    Vec<1, uint8_t> id_2764 {  id_2763  };
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2765;
                                    {
                                      Vec<1, uint8_t> shft_ref_486 { id_2764 };
                                      Vec<1, Pointer> id_2766 {  dsum1_snd_412  };
                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2767;
                                      {
                                        Vec<1, Pointer> p_ref_487 { id_2766 };
                                        bool while_flag_2768 { true };
                                        do {
                                          uint8_t id_2769 { 0 };
                                          Pointer id_2770 { p_ref_487[id_2769] };
                                          ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2771 { id_2770.readU8() };
                                          bool let_res_2772;
                                          {
                                            ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_488 { id_2771 };
                                            bool letpair_res_2773;
                                            {
                                              auto leb128_fst_489 { std::get<0>(leb128_488) };
                                              auto leb128_snd_490 { std::get<1>(leb128_488) };
                                              uint8_t id_2774 { 0 };
                                              Void id_2775 { ((void)(p_ref_487[id_2774] = leb128_snd_490), ::dessser::VOID) };
                                              (void)id_2775;
                                              uint8_t id_2776 { 0 };
                                              uint8_t id_2777 { 127 };
                                              uint8_t id_2778 { uint8_t(leb128_fst_489 & id_2777) };
                                              uint32_t id_2779 { uint32_t(id_2778) };
                                              uint8_t id_2780 { 0 };
                                              uint8_t id_2781 { shft_ref_486[id_2780] };
                                              uint32_t id_2782 { uint32_t(id_2779 << id_2781) };
                                              uint8_t id_2783 { 0 };
                                              uint32_t id_2784 { leb_ref_485[id_2783] };
                                              uint32_t id_2785 { uint32_t(id_2782 | id_2784) };
                                              Void id_2786 { ((void)(leb_ref_485[id_2776] = id_2785), ::dessser::VOID) };
                                              (void)id_2786;
                                              uint8_t id_2787 { 0 };
                                              uint8_t id_2788 { 0 };
                                              uint8_t id_2789 { shft_ref_486[id_2788] };
                                              uint8_t id_2790 { 7 };
                                              uint8_t id_2791 { uint8_t(id_2789 + id_2790) };
                                              Void id_2792 { ((void)(shft_ref_486[id_2787] = id_2791), ::dessser::VOID) };
                                              (void)id_2792;
                                              uint8_t id_2793 { 128 };
                                              bool id_2794 { bool(leb128_fst_489 >= id_2793) };
                                              letpair_res_2773 = id_2794;
                                            }
                                            let_res_2772 = letpair_res_2773;
                                          }
                                          while_flag_2768 = let_res_2772;
                                          if (while_flag_2768) {
                                            (void)::dessser::VOID;
                                          }
                                        } while (while_flag_2768);
                                        (void)::dessser::VOID;
                                        uint8_t id_2795 { 0 };
                                        uint32_t id_2796 { leb_ref_485[id_2795] };
                                        Size id_2797 { Size(id_2796) };
                                        uint8_t id_2798 { 0 };
                                        Pointer id_2799 { p_ref_487[id_2798] };
                                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2800 { id_2797, id_2799 };
                                        let_res_2767 = id_2800;
                                      }
                                      let_res_2765 = let_res_2767;
                                    }
                                    let_res_2762 = let_res_2765;
                                  }
                                  ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2801;
                                  {
                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_491 { let_res_2762 };
                                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2802;
                                    {
                                      auto dstring1_fst_492 { std::get<0>(dstring1_491) };
                                      auto dstring1_snd_493 { std::get<1>(dstring1_491) };
                                      ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2803 { dstring1_snd_493.readBytes(dstring1_fst_492) };
                                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2804;
                                      {
                                        auto dstring2_fst_495 { std::get<0>(id_2803) };
                                        auto dstring2_snd_496 { std::get<1>(id_2803) };
                                        std::string id_2805 { dstring2_fst_495.toString() };
                                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2806 { id_2805, dstring2_snd_496 };
                                        letpair_res_2804 = id_2806;
                                      }
                                      letpair_res_2802 = letpair_res_2804;
                                    }
                                    let_res_2801 = letpair_res_2802;
                                  }
                                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2807;
                                  {
                                    ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_497 { let_res_2801 };
                                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2808;
                                    {
                                      auto dtup_fst_498 { std::get<0>(dtup_497) };
                                      auto dtup_snd_499 { std::get<1>(dtup_497) };
                                      ::dessser::gen::sync_key::tddfcfedf3e7ada7bc193bdea642cf713 id_2809 { per_dash_key_of_row_binary(dtup_snd_499) };
                                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2810;
                                      {
                                        auto dtup_fst_501 { std::get<0>(id_2809) };
                                        auto dtup_snd_502 { std::get<1>(id_2809) };
                                        ::dessser::gen::sync_key::t5f85ea99fc65adca3880884cd8e9f15d id_2811 { dtup_fst_498, dtup_fst_501 };
                                        std::shared_ptr<::dessser::gen::sync_key::t>  id_2812 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<12>, id_2811) };
                                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2813 { id_2812, dtup_snd_502 };
                                        letpair_res_2810 = id_2813;
                                      }
                                      letpair_res_2808 = letpair_res_2810;
                                    }
                                    let_res_2807 = letpair_res_2808;
                                  }
                                  choose_res_2759 = let_res_2807;
                                } else {
                                  uint16_t id_2814 { 13 };
                                  bool id_2815 { bool(id_2814 == dsum1_fst_411) };
                                  ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2816;
                                  if (id_2815) {
                                    (void)::dessser::VOID;
                                    std::shared_ptr<::dessser::gen::sync_key::t>  id_2817 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<13>, ::dessser::VOID) };
                                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2818 { id_2817, dsum1_snd_412 };
                                    choose_res_2816 = id_2818;
                                  } else {
                                    uint16_t id_2819 { 14 };
                                    bool id_2820 { bool(id_2819 == dsum1_fst_411) };
                                    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf choose_res_2821;
                                    if (id_2820) {
                                      auto fun2822 { dessser::gen::team_name::of_row_binary };
                                      ::dessser::gen::sync_key::td204a4115a9974841e2d802fceb65890 id_2823 { fun2822(dsum1_snd_412) };
                                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2824;
                                      {
                                        ::dessser::gen::sync_key::td204a4115a9974841e2d802fceb65890 dtup_434 { id_2823 };
                                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2825;
                                        {
                                          auto dtup_fst_435 { std::get<0>(dtup_434) };
                                          auto dtup_snd_436 { std::get<1>(dtup_434) };
                                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2826 { dtup_snd_436.readU16Le() };
                                          ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 letpair_res_2827;
                                          {
                                            auto du16_fst_438 { std::get<0>(id_2826) };
                                            auto du16_snd_439 { std::get<1>(id_2826) };
                                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 id_2828 { du16_fst_438, du16_snd_439 };
                                            letpair_res_2827 = id_2828;
                                          }
                                          ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f let_res_2829;
                                          {
                                            ::dessser::gen::sync_key::ta97bb48ed75bbda6173555873826c8c6 dsum1_443 { letpair_res_2827 };
                                            ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f letpair_res_2830;
                                            {
                                              auto dsum1_fst_444 { std::get<0>(dsum1_443) };
                                              auto dsum1_snd_445 { std::get<1>(dsum1_443) };
                                              uint16_t id_2831 { 0 };
                                              bool id_2832 { bool(id_2831 == dsum1_fst_444) };
                                              ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f choose_res_2833;
                                              if (id_2832) {
                                                uint32_t id_2834 { 0U };
                                                Vec<1, uint32_t> id_2835 {  id_2834  };
                                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2836;
                                                {
                                                  Vec<1, uint32_t> leb_ref_461 { id_2835 };
                                                  uint8_t id_2837 { 0 };
                                                  Vec<1, uint8_t> id_2838 {  id_2837  };
                                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2839;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_462 { id_2838 };
                                                    Vec<1, Pointer> id_2840 {  dsum1_snd_445  };
                                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2841;
                                                    {
                                                      Vec<1, Pointer> p_ref_463 { id_2840 };
                                                      bool while_flag_2842 { true };
                                                      do {
                                                        uint8_t id_2843 { 0 };
                                                        Pointer id_2844 { p_ref_463[id_2843] };
                                                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2845 { id_2844.readU8() };
                                                        bool let_res_2846;
                                                        {
                                                          ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_464 { id_2845 };
                                                          bool letpair_res_2847;
                                                          {
                                                            auto leb128_fst_465 { std::get<0>(leb128_464) };
                                                            auto leb128_snd_466 { std::get<1>(leb128_464) };
                                                            uint8_t id_2848 { 0 };
                                                            Void id_2849 { ((void)(p_ref_463[id_2848] = leb128_snd_466), ::dessser::VOID) };
                                                            (void)id_2849;
                                                            uint8_t id_2850 { 0 };
                                                            uint8_t id_2851 { 127 };
                                                            uint8_t id_2852 { uint8_t(leb128_fst_465 & id_2851) };
                                                            uint32_t id_2853 { uint32_t(id_2852) };
                                                            uint8_t id_2854 { 0 };
                                                            uint8_t id_2855 { shft_ref_462[id_2854] };
                                                            uint32_t id_2856 { uint32_t(id_2853 << id_2855) };
                                                            uint8_t id_2857 { 0 };
                                                            uint32_t id_2858 { leb_ref_461[id_2857] };
                                                            uint32_t id_2859 { uint32_t(id_2856 | id_2858) };
                                                            Void id_2860 { ((void)(leb_ref_461[id_2850] = id_2859), ::dessser::VOID) };
                                                            (void)id_2860;
                                                            uint8_t id_2861 { 0 };
                                                            uint8_t id_2862 { 0 };
                                                            uint8_t id_2863 { shft_ref_462[id_2862] };
                                                            uint8_t id_2864 { 7 };
                                                            uint8_t id_2865 { uint8_t(id_2863 + id_2864) };
                                                            Void id_2866 { ((void)(shft_ref_462[id_2861] = id_2865), ::dessser::VOID) };
                                                            (void)id_2866;
                                                            uint8_t id_2867 { 128 };
                                                            bool id_2868 { bool(leb128_fst_465 >= id_2867) };
                                                            letpair_res_2847 = id_2868;
                                                          }
                                                          let_res_2846 = letpair_res_2847;
                                                        }
                                                        while_flag_2842 = let_res_2846;
                                                        if (while_flag_2842) {
                                                          (void)::dessser::VOID;
                                                        }
                                                      } while (while_flag_2842);
                                                      (void)::dessser::VOID;
                                                      uint8_t id_2869 { 0 };
                                                      uint32_t id_2870 { leb_ref_461[id_2869] };
                                                      Size id_2871 { Size(id_2870) };
                                                      uint8_t id_2872 { 0 };
                                                      Pointer id_2873 { p_ref_463[id_2872] };
                                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2874 { id_2871, id_2873 };
                                                      let_res_2841 = id_2874;
                                                    }
                                                    let_res_2839 = let_res_2841;
                                                  }
                                                  let_res_2836 = let_res_2839;
                                                }
                                                ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f let_res_2875;
                                                {
                                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_467 { let_res_2836 };
                                                  ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f letpair_res_2876;
                                                  {
                                                    auto dstring1_fst_468 { std::get<0>(dstring1_467) };
                                                    auto dstring1_snd_469 { std::get<1>(dstring1_467) };
                                                    ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2877 { dstring1_snd_469.readBytes(dstring1_fst_468) };
                                                    ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f letpair_res_2878;
                                                    {
                                                      auto dstring2_fst_471 { std::get<0>(id_2877) };
                                                      auto dstring2_snd_472 { std::get<1>(id_2877) };
                                                      std::string id_2879 { dstring2_fst_471.toString() };
                                                      ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_2880 { std::in_place_index<0>, id_2879 };
                                                      ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f id_2881 { id_2880, dstring2_snd_472 };
                                                      letpair_res_2878 = id_2881;
                                                    }
                                                    letpair_res_2876 = letpair_res_2878;
                                                  }
                                                  let_res_2875 = letpair_res_2876;
                                                }
                                                choose_res_2833 = let_res_2875;
                                              } else {
                                                uint16_t id_2882 { 1 };
                                                bool id_2883 { bool(dsum1_fst_444 == id_2882) };
                                                Void id_2884 { ((void)(assert(id_2883)), ::dessser::VOID) };
                                                (void)id_2884;
                                                uint32_t id_2885 { 0U };
                                                Vec<1, uint32_t> id_2886 {  id_2885  };
                                                ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2887;
                                                {
                                                  Vec<1, uint32_t> leb_ref_446 { id_2886 };
                                                  uint8_t id_2888 { 0 };
                                                  Vec<1, uint8_t> id_2889 {  id_2888  };
                                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2890;
                                                  {
                                                    Vec<1, uint8_t> shft_ref_447 { id_2889 };
                                                    Vec<1, Pointer> id_2891 {  dsum1_snd_445  };
                                                    ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2892;
                                                    {
                                                      Vec<1, Pointer> p_ref_448 { id_2891 };
                                                      bool while_flag_2893 { true };
                                                      do {
                                                        uint8_t id_2894 { 0 };
                                                        Pointer id_2895 { p_ref_448[id_2894] };
                                                        ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2896 { id_2895.readU8() };
                                                        bool let_res_2897;
                                                        {
                                                          ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_449 { id_2896 };
                                                          bool letpair_res_2898;
                                                          {
                                                            auto leb128_fst_450 { std::get<0>(leb128_449) };
                                                            auto leb128_snd_451 { std::get<1>(leb128_449) };
                                                            uint8_t id_2899 { 0 };
                                                            Void id_2900 { ((void)(p_ref_448[id_2899] = leb128_snd_451), ::dessser::VOID) };
                                                            (void)id_2900;
                                                            uint8_t id_2901 { 0 };
                                                            uint8_t id_2902 { 127 };
                                                            uint8_t id_2903 { uint8_t(leb128_fst_450 & id_2902) };
                                                            uint32_t id_2904 { uint32_t(id_2903) };
                                                            uint8_t id_2905 { 0 };
                                                            uint8_t id_2906 { shft_ref_447[id_2905] };
                                                            uint32_t id_2907 { uint32_t(id_2904 << id_2906) };
                                                            uint8_t id_2908 { 0 };
                                                            uint32_t id_2909 { leb_ref_446[id_2908] };
                                                            uint32_t id_2910 { uint32_t(id_2907 | id_2909) };
                                                            Void id_2911 { ((void)(leb_ref_446[id_2901] = id_2910), ::dessser::VOID) };
                                                            (void)id_2911;
                                                            uint8_t id_2912 { 0 };
                                                            uint8_t id_2913 { 0 };
                                                            uint8_t id_2914 { shft_ref_447[id_2913] };
                                                            uint8_t id_2915 { 7 };
                                                            uint8_t id_2916 { uint8_t(id_2914 + id_2915) };
                                                            Void id_2917 { ((void)(shft_ref_447[id_2912] = id_2916), ::dessser::VOID) };
                                                            (void)id_2917;
                                                            uint8_t id_2918 { 128 };
                                                            bool id_2919 { bool(leb128_fst_450 >= id_2918) };
                                                            letpair_res_2898 = id_2919;
                                                          }
                                                          let_res_2897 = letpair_res_2898;
                                                        }
                                                        while_flag_2893 = let_res_2897;
                                                        if (while_flag_2893) {
                                                          (void)::dessser::VOID;
                                                        }
                                                      } while (while_flag_2893);
                                                      (void)::dessser::VOID;
                                                      uint8_t id_2920 { 0 };
                                                      uint32_t id_2921 { leb_ref_446[id_2920] };
                                                      Size id_2922 { Size(id_2921) };
                                                      uint8_t id_2923 { 0 };
                                                      Pointer id_2924 { p_ref_448[id_2923] };
                                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2925 { id_2922, id_2924 };
                                                      let_res_2892 = id_2925;
                                                    }
                                                    let_res_2890 = let_res_2892;
                                                  }
                                                  let_res_2887 = let_res_2890;
                                                }
                                                ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f let_res_2926;
                                                {
                                                  ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_452 { let_res_2887 };
                                                  ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f letpair_res_2927;
                                                  {
                                                    auto dstring1_fst_453 { std::get<0>(dstring1_452) };
                                                    auto dstring1_snd_454 { std::get<1>(dstring1_452) };
                                                    ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2928 { dstring1_snd_454.readBytes(dstring1_fst_453) };
                                                    ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f letpair_res_2929;
                                                    {
                                                      auto dstring2_fst_456 { std::get<0>(id_2928) };
                                                      auto dstring2_snd_457 { std::get<1>(id_2928) };
                                                      std::string id_2930 { dstring2_fst_456.toString() };
                                                      ::dessser::gen::sync_key::t7c3b4d666d784c1e1d7f41f4fe6019cb id_2931 { std::in_place_index<1>, id_2930 };
                                                      ::dessser::gen::sync_key::t685051b3783a797b8142eff00f35a04f id_2932 { id_2931, dstring2_snd_457 };
                                                      letpair_res_2929 = id_2932;
                                                    }
                                                    letpair_res_2927 = letpair_res_2929;
                                                  }
                                                  let_res_2926 = letpair_res_2927;
                                                }
                                                choose_res_2833 = let_res_2926;
                                              }
                                              letpair_res_2830 = choose_res_2833;
                                            }
                                            let_res_2829 = letpair_res_2830;
                                          }
                                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2933;
                                          {
                                            auto dtup_fst_477 { std::get<0>(let_res_2829) };
                                            auto dtup_snd_478 { std::get<1>(let_res_2829) };
                                            ::dessser::gen::sync_key::t3fa506fd8c7ad175afbb77516ca40d23 id_2934 { dtup_fst_435, dtup_fst_477 };
                                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2935 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<14>, id_2934) };
                                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2936 { id_2935, dtup_snd_478 };
                                            letpair_res_2933 = id_2936;
                                          }
                                          letpair_res_2825 = letpair_res_2933;
                                        }
                                        let_res_2824 = letpair_res_2825;
                                      }
                                      choose_res_2821 = let_res_2824;
                                    } else {
                                      uint16_t id_2937 { 15 };
                                      bool id_2938 { bool(dsum1_fst_411 == id_2937) };
                                      Void id_2939 { ((void)(assert(id_2938)), ::dessser::VOID) };
                                      (void)id_2939;
                                      uint32_t id_2940 { 0U };
                                      Vec<1, uint32_t> id_2941 {  id_2940  };
                                      ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2942;
                                      {
                                        Vec<1, uint32_t> leb_ref_413 { id_2941 };
                                        uint8_t id_2943 { 0 };
                                        Vec<1, uint8_t> id_2944 {  id_2943  };
                                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2945;
                                        {
                                          Vec<1, uint8_t> shft_ref_414 { id_2944 };
                                          Vec<1, Pointer> id_2946 {  dsum1_snd_412  };
                                          ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa let_res_2947;
                                          {
                                            Vec<1, Pointer> p_ref_415 { id_2946 };
                                            bool while_flag_2948 { true };
                                            do {
                                              uint8_t id_2949 { 0 };
                                              Pointer id_2950 { p_ref_415[id_2949] };
                                              ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 id_2951 { id_2950.readU8() };
                                              bool let_res_2952;
                                              {
                                                ::dessser::gen::sync_key::t1a5d74abf838df33f185a72a8912f5c9 leb128_416 { id_2951 };
                                                bool letpair_res_2953;
                                                {
                                                  auto leb128_fst_417 { std::get<0>(leb128_416) };
                                                  auto leb128_snd_418 { std::get<1>(leb128_416) };
                                                  uint8_t id_2954 { 0 };
                                                  Void id_2955 { ((void)(p_ref_415[id_2954] = leb128_snd_418), ::dessser::VOID) };
                                                  (void)id_2955;
                                                  uint8_t id_2956 { 0 };
                                                  uint8_t id_2957 { 127 };
                                                  uint8_t id_2958 { uint8_t(leb128_fst_417 & id_2957) };
                                                  uint32_t id_2959 { uint32_t(id_2958) };
                                                  uint8_t id_2960 { 0 };
                                                  uint8_t id_2961 { shft_ref_414[id_2960] };
                                                  uint32_t id_2962 { uint32_t(id_2959 << id_2961) };
                                                  uint8_t id_2963 { 0 };
                                                  uint32_t id_2964 { leb_ref_413[id_2963] };
                                                  uint32_t id_2965 { uint32_t(id_2962 | id_2964) };
                                                  Void id_2966 { ((void)(leb_ref_413[id_2956] = id_2965), ::dessser::VOID) };
                                                  (void)id_2966;
                                                  uint8_t id_2967 { 0 };
                                                  uint8_t id_2968 { 0 };
                                                  uint8_t id_2969 { shft_ref_414[id_2968] };
                                                  uint8_t id_2970 { 7 };
                                                  uint8_t id_2971 { uint8_t(id_2969 + id_2970) };
                                                  Void id_2972 { ((void)(shft_ref_414[id_2967] = id_2971), ::dessser::VOID) };
                                                  (void)id_2972;
                                                  uint8_t id_2973 { 128 };
                                                  bool id_2974 { bool(leb128_fst_417 >= id_2973) };
                                                  letpair_res_2953 = id_2974;
                                                }
                                                let_res_2952 = letpair_res_2953;
                                              }
                                              while_flag_2948 = let_res_2952;
                                              if (while_flag_2948) {
                                                (void)::dessser::VOID;
                                              }
                                            } while (while_flag_2948);
                                            (void)::dessser::VOID;
                                            uint8_t id_2975 { 0 };
                                            uint32_t id_2976 { leb_ref_413[id_2975] };
                                            Size id_2977 { Size(id_2976) };
                                            uint8_t id_2978 { 0 };
                                            Pointer id_2979 { p_ref_415[id_2978] };
                                            ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa id_2980 { id_2977, id_2979 };
                                            let_res_2947 = id_2980;
                                          }
                                          let_res_2945 = let_res_2947;
                                        }
                                        let_res_2942 = let_res_2945;
                                      }
                                      ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 let_res_2981;
                                      {
                                        ::dessser::gen::sync_key::t12fb9c475959b52bf7b17b155a955ffa dstring1_419 { let_res_2942 };
                                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2982;
                                        {
                                          auto dstring1_fst_420 { std::get<0>(dstring1_419) };
                                          auto dstring1_snd_421 { std::get<1>(dstring1_419) };
                                          ::dessser::gen::sync_key::t9ef6882174ae71a34a3c5ef6b29242fb id_2983 { dstring1_snd_421.readBytes(dstring1_fst_420) };
                                          ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 letpair_res_2984;
                                          {
                                            auto dstring2_fst_423 { std::get<0>(id_2983) };
                                            auto dstring2_snd_424 { std::get<1>(id_2983) };
                                            std::string id_2985 { dstring2_fst_423.toString() };
                                            ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 id_2986 { id_2985, dstring2_snd_424 };
                                            letpair_res_2984 = id_2986;
                                          }
                                          letpair_res_2982 = letpair_res_2984;
                                        }
                                        let_res_2981 = letpair_res_2982;
                                      }
                                      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf let_res_2987;
                                      {
                                        ::dessser::gen::sync_key::t13a07ee37ab40962540da8534858dc07 dtup_425 { let_res_2981 };
                                        ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2988;
                                        {
                                          auto dtup_fst_426 { std::get<0>(dtup_425) };
                                          auto dtup_snd_427 { std::get<1>(dtup_425) };
                                          ::dessser::gen::sync_key::t81a0c931c4f6d47a526068c7b84a436d id_2989 { incident_key_of_row_binary(dtup_snd_427) };
                                          ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2990;
                                          {
                                            auto dtup_fst_429 { std::get<0>(id_2989) };
                                            auto dtup_snd_430 { std::get<1>(id_2989) };
                                            ::dessser::gen::sync_key::tdce75d0a7767ecd39280979e2e5897b1 id_2991 { dtup_fst_426, dtup_fst_429 };
                                            std::shared_ptr<::dessser::gen::sync_key::t>  id_2992 { std::make_shared<::dessser::gen::sync_key::t>(std::in_place_index<15>, id_2991) };
                                            ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2993 { id_2992, dtup_snd_430 };
                                            letpair_res_2990 = id_2993;
                                          }
                                          letpair_res_2988 = letpair_res_2990;
                                        }
                                        let_res_2987 = letpair_res_2988;
                                      }
                                      choose_res_2821 = let_res_2987;
                                    }
                                    choose_res_2816 = choose_res_2821;
                                  }
                                  choose_res_2759 = choose_res_2816;
                                }
                                choose_res_2747 = choose_res_2759;
                              }
                              choose_res_2742 = choose_res_2747;
                            }
                            choose_res_2720 = choose_res_2742;
                          }
                          choose_res_2713 = choose_res_2720;
                        }
                        choose_res_2648 = choose_res_2713;
                      }
                      choose_res_2576 = choose_res_2648;
                    }
                    choose_res_2569 = choose_res_2576;
                  }
                  choose_res_2564 = choose_res_2569;
                }
                choose_res_2508 = choose_res_2564;
              }
              choose_res_2457 = choose_res_2508;
            }
            choose_res_2452 = choose_res_2457;
          }
          choose_res_2447 = choose_res_2452;
        }
        letpair_res_2444 = choose_res_2447;
      }
      let_res_2443 = letpair_res_2444;
    }
    return let_res_2443;
  }
   };
  return fun2439;
}
std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> of_row_binary(of_row_binary_init());

/* 
    (fun ("Ptr") (let-pair "make_fst_639" "make_snd_640" (apply (identifier "of-row-binary") (param 0)) (make-tup (identifier "make_fst_639") (identifier "make_snd_640"))))
 */
static std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> wrap_of_row_binary_init()
{
  std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> fun2994 { [&fun2994](Pointer p_0) {
    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2995 { of_row_binary(p_0) };
    ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf letpair_res_2996;
    {
      auto make_fst_639 { std::get<0>(id_2995) };
      auto make_snd_640 { std::get<1>(id_2995) };
      ::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf id_2997 { make_fst_639, make_snd_640 };
      letpair_res_2996 = id_2997;
    }
    return letpair_res_2996;
  }
   };
  return fun2994;
}
std::function<::dessser::gen::sync_key::tcf9b51a7545aa8b67d24c1f5f504ceaf(Pointer)> wrap_of_row_binary(wrap_of_row_binary_init());

/* 
    (fun ("[DevNull Void | Time Void | Versions STRING | Sources ($src_path; STRING) | TargetConfig Void | PerSite (per_site AS ($site_name; (per_site_data AS [IsMaster Void | PerService (STRING; [Host Void | Port Void]) | PerWorker (per_worker AS ($fq_name; (per_worker_data AS [RuntimeStats Void | ArchivedTimes Void | NumArcFiles Void | NumArcBytes Void | AllocedArcBytes Void | Worker Void | PerInstance (STRING; [StateFile Void | InputRingFile Void | Pid Void | LastKilled Void | LastExit Void | LastExitStatus Void | SuccessiveFailures Void | QuarantineUntil Void]) | PerReplayer U32 | OutputSpecs Void]))) | PerProgram (STRING; [Executable Void])]))) | Storage [TotalSize Void | RecallCost Void | RetentionsOverride STRING] | Tails ($site_name; $fq_name; STRING; (per_tail AS [Subscriber STRING | LastTuple U32])) | Replays U16 | Error $sync_socket? | ReplayRequests Void | PerClient ($sync_socket; (per_client AS [Response STRING | Scratchpad (per_dash_key AS [Widgets U32])])) | Dashboards (STRING; per_dash_key) | Notifications Void | Teams ($team_name; [Contacts STRING | Inhibition STRING]) | Incidents (STRING; (incident_key AS [FirstStartNotif Void | LastStartNotif Void | LastStopNotif Void | LastStateChangeNotif Void | Team Void | Dialogs (STRING; (dialog_key AS [NumDeliveryAttempts Void | FirstDeliveryAttempt Void | LastDeliveryAttempt Void | NextScheduled Void | NextSend Void | DeliveryStatus Void | Ack Void])) | Journal (FLOAT; U32)]))]" "Ptr")
      (apply (identifier "to-row-binary") (param 0) (param 1)))
 */
static std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> wrap_to_row_binary_init()
{
  std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> fun2998 { [&fun2998](std::shared_ptr<::dessser::gen::sync_key::t>  p_0, Pointer p_1) {
    Pointer id_2999 { to_row_binary(p_0, p_1) };
    return id_2999;
  }
   };
  return fun2998;
}
std::function<Pointer(std::shared_ptr<::dessser::gen::sync_key::t> ,Pointer)> wrap_to_row_binary(wrap_to_row_binary_init());


}
